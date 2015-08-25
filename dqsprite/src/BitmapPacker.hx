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
		var powerOf2:Int = 2;
		
		var packer:MaxRectsBinPack;
		
		var rightMost:Int = 0;
		var bottomMost:Int = 0;
		
		var meta:Fast = new Fast(Xml.parse('<TextureAtlas imagePath="pack.png"></TextureAtlas>'));
		
		var subs = [];
		
		while (fail)
		{
			packer = new MaxRectsBinPack(powerOf2, powerOf2);
			
			var list2 = [];
			
			var j:Int = 0;
			
			fail = false;
			
			var j:Int = 0;
			
			var lastSub:Xml = null;
			
			for(i in 0...list.length)
			{
				if (list[i].dupe) 
				{
					lastSub.set("name", Std.string(list[i].index));
					lastSub.set("flipX", Std.string(list[i].flipX));
					trace("pushing dupe --> " + lastSub.toString());
					subs.push(lastSub);
					lastSub = dupeSub(Std.string(list[i].index), lastSub);
					continue;
				}
				
				var sub:Xml = null;
				
				var block = blocks[i];
				var rect = list[i].rect;
				
				block.fit = packer.quickInsert(block.w, block.h);
				
				if (block.fit.x + block.w > rightMost ) rightMost  = Std.int(block.fit.x + block.w);
				if (block.fit.y + block.h > bottomMost) bottomMost = Std.int(block.fit.y + block.h);
				
				var flipX = (list[i].dupe && list[i].flipX);
				
				sub = subTexNode(list[i].index, Std.int(block.fit.x), Std.int(block.fit.y), block.w, block.h, Std.int(rect.x), Std.int(rect.y), Std.int(rect.width), Std.int(rect.height), flipX);
				
				subs.push(sub);
				
				if (i != 0 && block.fit.x == 0 && block.fit.y == 0)
				{
					fail = true;
					powerOf2 *= 2;
					meta = new Fast(Xml.parse('<TextureAtlas imagePath="pack.png"></TextureAtlas>'));
					lastSub = null;
					subs = [];
					break;
				}
				
				lastSub = dupeSub(Std.string(list[i].index), sub);
				//lastSub = subTexNode(list[i].index, Std.int(block.fit.x), Std.int(block.fit.y), block.w, block.h, Std.int(rect.x), Std.int(rect.y), Std.int(rect.width), Std.int(rect.height), flipX);
			}
		}
		
		subs.sort(sortSubsAscending);
		
		for (sub in subs)
		{
			meta.node.TextureAtlas.x.addChild(sub);
		}
		
		var canvas:BitmapData = new BitmapData(rightMost, bottomMost, true, 0x00000000);
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
		var ai:Int = Std.parseInt(a.get("name"));
		var bi:Int = Std.parseInt(b.get("name"));
		if (ai < bi) return -1;
		if (ai > bi) return  1;
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
	
	static public function subTexNode(i:Int,x:Int,y:Int,width:Int,height:Int,frameX:Int,frameY:Int,frameWidth:Int,frameHeight:Int,flipX:Bool=false,flipY:Bool=false):Xml
	{
		var sub = Xml.createElement("SubTexture");
		
		sub.set("name", Std.string(i));
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
	dupe:Bool
}