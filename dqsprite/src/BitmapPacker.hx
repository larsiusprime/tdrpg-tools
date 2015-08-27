package;
import flixel.FlxG;
import flixel.math.FlxRandom;
import flixel.util.FlxColor;
import haxe.xml.Fast;
import haxe.xml.Printer;
import openfl.geom.Matrix;
import openfl.display.BitmapData;
import openfl.display.PNGEncoderOptions;
import openfl.geom.Point;
import openfl.geom.Rectangle;
import openfl.utils.ByteArray;
import sys.io.FileOutput;

/**
 * ...
 * @author larsiusprime
 */
class BitmapPacker
{
	static public function pack(maxW:Int, maxH:Int, list:Array<BmpEntry>):{ bmp:BitmapData, metadata:Fast }
	{
		var blocks:Array<Block> = [];
		
		for (entry in list)
		{
			if (entry.bmp != null && entry.dupe == false)
			{
				blocks.push( { w:entry.bmp.width, h:entry.bmp.height, bmp:entry.bmp } );
			}
			else
			{
				blocks.push(null);
			}
		}
		
		var maxpixels = maxW * maxH;
		
		var fail = true;
		var powerOf2X:Int = 2;
		var powerOf2Y:Int = 2;
		
		var packer:MaxRectsBinPack;
		
		var rightMost:Int = 0;
		var bottomMost:Int = 0;
		
		var meta:Fast = new Fast(Xml.parse('<TextureAtlas imagePath="pack.png"></TextureAtlas>'));
		
		var subs = [];
		
		while (fail)
		{
			trace("attempting " + powerOf2X + " x " + powerOf2Y + "...");
			
			packer = new MaxRectsBinPack(powerOf2X, powerOf2Y);
			
			var list2 = [];
			
			var j:Int = 0;
			
			fail = false;
			
			var j:Int = 0;
			
			for(i in 0...list.length)
			{
				if (list[i].dupe) 
				{
					var n = Std.string(list[i].index);
					
					var dentry:BmpEntry = list[list[i].dupeOf];
					var dblock:Block    = blocks[list[i].dupeOf];
					
					var dfx = Std.int(dblock.fit.x);
					var dfy = Std.int(dblock.fit.y);
					
					var drx = Std.int(list[i].rect.x);
					var dry = Std.int(list[i].rect.y);
					var drw = Std.int(list[i].rect.width);
					var drh = Std.int(list[i].rect.height);
					
					var dupeSub = subTexNode(n, dfx, dfy, dentry.bmp.width, dentry.bmp.height, drx, dry, drw, drh, list[i].flipX);
					subs.push(dupeSub);
					continue;
				}
				
				var sub:Xml = null;
				
				var block = blocks[i];
				var rect = list[i].rect;
				
				block.fit = packer.quickInsert(block.w, block.h);
				
				if (block.fit.x + block.w > rightMost ) rightMost  = Std.int(block.fit.x + block.w);
				if (block.fit.y + block.h > bottomMost) bottomMost = Std.int(block.fit.y + block.h);
				
				var flipX = (list[i].dupe && list[i].flipX);
				
				var n = Std.string(list[i].index);
				
				var bfx = Std.int(block.fit.x);
				var bfy = Std.int(block.fit.y);
				
				var rx = Std.int(rect.x);
				var ry = Std.int(rect.y);
				var rw = Std.int(rect.width);
				var rh = Std.int(rect.height);
				
				sub = subTexNode(n, bfx, bfy, list[i].bmp.width, list[i].bmp.height, rx, ry, rw, rh, flipX);
				
				subs.push(sub);
				
				if (i != 0 && block.fit.x == 0 && block.fit.y == 0)
				{
					fail = true;
					if (powerOf2Y < powerOf2X)
					{
						powerOf2Y *= 2;
					}
					else
					{
						powerOf2X *= 2;
					}
					meta = new Fast(Xml.parse('<TextureAtlas imagePath="pack.png"></TextureAtlas>'));
					subs = [];
					break;
				}
			}
		}
		
		trace("...success!");
		
		subs.sort(sortSubsAscending);
		
		for (sub in subs)
		{
			meta.node.TextureAtlas.x.addChild(sub);
		}
		
		trace("drawing output...");
		
		var rightMost2:Int = 2;
		var bottomMost2:Int = 2;
		
		while (rightMost2 < rightMost)
		{
			rightMost2 *= 2;
		}
		while (bottomMost2 < bottomMost)
		{
			bottomMost2 *= 2;
		}
		
		var canvas:BitmapData = new BitmapData(rightMost2, bottomMost2, true, 0x00000000);
		var pt = new Point();
		
		var i:Int = 0;
		for (block in blocks)
		{
			
			if (block != null && block.fit != null)
			{
				pt.setTo(block.fit.x, block.fit.y);
				canvas.copyPixels(block.bmp, block.bmp.rect, pt);
			}
			
			i++;
		}
		
		return {bmp:canvas, metadata:meta};
	}
	
	public static function sortSubsAscending(a:Xml, b:Xml):Int
	{
		var an:String = a.get("name");
		var bn:String = b.get("name");
		
		if (an < bn) return -1;
		if (an > bn) return  1;
		return 0;
	}
	
	private static function trimBmp(bmp:BitmapData):BitmapData {
		var notAlphaBounds:Rectangle = bmp.getColorBoundsRect(0xFFFFFFFF, 0x00000000, false);
		var trimmed:BitmapData = new BitmapData(Std.int(notAlphaBounds.width), Std.int(notAlphaBounds.height), true, 0x00000000);
		trimmed.copyPixels(bmp, notAlphaBounds, new Point());
		return trimmed;
	}
	
	static private function writeBmp(b:BitmapData,name:String):Void
	{
		trace("writing out to : " + name);
		var bytes:ByteArray = b.encode(b.rect, new PNGEncoderOptions());
		if (bytes != null)
		{
			var error:Bool = false;
			try
			{
				var f:FileOutput= sys.io.File.write(name);
				f.write(bytes);
				f.close();
			}
			catch (msg:String)
			{
				error = true;
				Sys.print("ERROR! (" + msg + ")\n");
			}
		}
	}
	
	static public function dupeSub(name:String, orig:Xml):Xml
	{
		var sub = Xml.createElement("SubTexture");
		
		for (att in orig.attributes())
		{
			sub.set(att, orig.get(att));
		}
		
		sub.set("name", name);
		
		return sub;
	}
	
	static public function subTexNode(name:String,x:Int,y:Int,width:Int,height:Int,frameX:Int,frameY:Int,frameWidth:Int,frameHeight:Int,flipX:Bool=false,flipY:Bool=false):Xml
	{
		var sub = Xml.createElement("SubTexture");
		
		sub.set("name", name);
		sub.set("x", Std.string(x));
		sub.set("y", Std.string(y));
		sub.set("width", Std.string(width));
		sub.set("height", Std.string(height));
		sub.set("frameX", Std.string(frameX));
		sub.set("frameY", Std.string(frameY));
		sub.set("frameWidth", Std.string(frameWidth));
		sub.set("frameHeight", Std.string(frameHeight));
		sub.set("flipX", Std.string(flipX));
		sub.set("flipY", Std.string(flipY));
		
		return sub;
	}
}

typedef Block = {
	w:Int,
	h:Int,
	?bmp:BitmapData,
	?fit:Rectangle
}

typedef BmpEntry = {
	index:Int,
	bmp:BitmapData,
	rect:Rectangle,
	flipX:Bool,
	dupe:Bool,
	?origBmp:BitmapData,
	?dupeOf:Int,
	?layer:String
}