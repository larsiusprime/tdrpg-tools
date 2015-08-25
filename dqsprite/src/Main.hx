package;

import flixel.util.FlxColor;
import haxe.xml.Fast;
import haxe.xml.Printer;
import openfl.geom.Matrix;
import lime.app.Application;
import lime.graphics.Image;
import lime.graphics.ImageBuffer;
import lime.graphics.opengl.GL;
import lime.graphics.RenderContext;
import openfl.geom.Rectangle;
import lime.ui.Window;
import lime.utils.ByteArray;
import openfl.display.BitmapData;
import openfl.display.BitmapDataChannel;
import openfl.display.PNGEncoderOptions;
import openfl.geom.Point;
import BitmapPacker.BmpEntry;
import sys.FileSystem;
import sys.io.File;
import sys.io.FileOutput;
import sys.io.Process;

/**
 * ...
 * @author larsiusprime
 */

class Main extends Application 
{

	public function new() 
	{
		super();
		doStuff(Sys.args());
		Sys.exit(0);
	}
	
	public function doStuff(args:Array<String>):Void
	{
		if (args == null || args.length == 0) return;
		if (args.length < 4) 
		{
			usage();
			return;
		}
		var input:String = args[0];
		var output:String = args[1];
		var new_w:Int = Std.parseInt(args[2]);
		var new_h:Int = Std.parseInt(args[3]);
		
		var orig_w:Int = 0;
		var orig_h:Int = 0;
		
		if (args.length >= 6)
		{
			orig_w = Std.parseInt(args[4]);
			orig_h = Std.parseInt(args[5]);
		}
		
		var ww = orig_w;
		var hh = orig_h;
		
		var scale = new_h / orig_h;
		
		if (FileSystem.exists(input))
		{
			var bmp = BitmapData.fromFile(input);
			
			var cellsWide:Int = Std.int(bmp.width / ww);
			var cellsTall:Int = Std.int(bmp.height / hh);
			
			var list:Array<BmpEntry> = [];
			
			var rect:Rectangle = new Rectangle();
			var pt:Point = new Point();
			
			rect.width = ww;
			rect.height = hh;
			
			var str:String = "";
			
			var i:Int = 0;
			
			for (yy in 0...cellsTall)
			{
				for (xx in 0...cellsWide)
				{
					rect.x = xx * ww;
					rect.y = yy * hh;
					
					var cell = new BitmapData(ww, hh, true, FlxColor.TRANSPARENT);
					cell.copyPixels(bmp, rect, pt);
					
					var notAlphaBounds:Rectangle = cell.getColorBoundsRect(0xFFFFFFFF, 0x00000000, false);
					var trimmed:BitmapData = new BitmapData(Std.int(notAlphaBounds.width), Std.int(notAlphaBounds.height), true, 0x00000000);
					trimmed.copyPixels(cell, notAlphaBounds, pt);
					
					list.push( {index:i, bmp:trimmed, rect:new Rectangle(-notAlphaBounds.x, -notAlphaBounds.y, ww, hh), flipX:false, dupe:false} );
					
					i++;
				}
			}
			
			list.sort(sortWidestThenTallest);
			
			list = removeDupesAndFlips(list);
			
			var scaledList   = scaleList(list, scale);
			
			var scaledPacked = BitmapPacker.pack(Std.int(bmp.width*scale), Std.int(bmp.height*scale), scaledList);
			
			output = StringTools.replace(output, ".png", "_scaled.png");
			
			writeBmp(scaledPacked.bmp, output);
			writeStr(FancyPrinter.print(scaledPacked.metadata.x, true), output + ".xml");
			
		}
		else
		{
			trace("could not find: " + input);
		}
	}
	
	public function removeDupesAndFlips(list:Array<BmpEntry>):Array<BmpEntry>
	{
		var newList = [];
		var lastEntry = null;
		
		for(entry in list) {
			
			var flipX = false;
			
			if (lastEntry != null) {
				
				var compare = entry.bmp.compare(lastEntry.bmp);
				
				if (compare != 0 && Std.is(compare,BitmapData))
				{
					//If they're not identical
					var delta = diffInComparison(cast compare);
					
					//If they're close
					if (delta > 1000)
					{
						//Flip it and check again
						var flip = new BitmapData(entry.bmp.width, entry.bmp.height, true, 0x00000000);
						var m = new Matrix();
						m.scale( -1, 1);
						m.translate(entry.bmp.width, 0);
						flip.draw(entry.bmp, m);
						
						var newCompare = lastEntry.bmp.compare(flip);
						if (newCompare == 0)
						{
							compare = newCompare;
							flipX = true;
						}
					}
				}
				
				if (compare == 0)
				{
					//if this block is identical (or a flipped mirror) of the previous one, then we just want to copy the previous metadata but with the duplicate frame name
					newList.push( { index:entry.index, bmp:null, rect:null, flipX:flipX, dupe:true } );
					continue;
				}
			}
			
			newList.push( { index:entry.index, bmp:entry.bmp, rect:entry.rect, flipX:false, dupe:false } );
			
			lastEntry = entry;
		}
		
		return newList;
	}
	
	public function scaleList(list:Array<BmpEntry>, scale:Float, smooth:Bool=true):Array<BmpEntry>
	{
		var newList = [];
		
		var m:Matrix = new Matrix();
		m.scale(scale, scale);
		
		var lastEntry = null;
		
		for (entry in list)
		{
			if (entry.dupe)
			{
				newList.push( {index:entry.index, bmp:null, rect:null, flipX:entry.flipX, dupe:entry.dupe } );
				continue;
			}
			
			var newBmp:BitmapData = new BitmapData(
												   Std.int(entry.bmp.width * scale),
												   Std.int(entry.bmp.height * scale),
												   true, 0x00000000);
			
			newBmp.draw(entry.bmp, m, null, null, null, smooth);
			
			var newRect:Rectangle = new Rectangle(
												  Std.int(entry.rect.x * scale),
												  Std.int(entry.rect.y * scale),
												  Std.int(entry.rect.width * scale),
												  Std.int(entry.rect.height * scale));
			
			newList.push( {index:entry.index, bmp:newBmp, rect:newRect, flipX:false, dupe:false} );
		}
		
		return newList;
	}
	
	public function scaleAtlas(orig:BitmapData, atlas:Fast, scale:Float, smooth:Bool = true): { bmp:BitmapData, atlas:Fast }
	{
		if (Math.abs(scale - 1.0) > 0.001)
		{
			var scaled:BitmapData = new BitmapData(Std.int(scale*orig.width), Std.int(scale*orig.height), true, 0x00000000);
			
			var rect:Rectangle = new Rectangle();
			var pt:Point = new Point();
			var matrix:Matrix = new Matrix();
			matrix.scale(scale, scale);
			
			if (atlas.hasNode.TextureAtlas)
			{
				var scaledAtlas:Xml = Xml.createElement("<TextureAtlas></TextureAtlas/>");
				scaledAtlas.set("imagePath", atlas.node.TextureAtlas.att.imagePath);
				
				if (atlas.node.TextureAtlas.hasNode.SubTexture)
				{
					for (sub in atlas.node.TextureAtlas.nodes.SubTexture)
					{
						var name = sub.att.name;
						var x = Std.parseInt(sub.att.x);
						var y = Std.parseInt(sub.att.y);
						var height = Std.parseInt(sub.att.height);
						var width = Std.parseInt(sub.att.width);
						var frameX = Std.parseInt(sub.att.frameX);
						var frameY = Std.parseInt(sub.att.frameY);
						var frameWidth = Std.parseInt(sub.att.frameWidth);
						var frameHeight = Std.parseInt(sub.att.frameHeight);
						var flipX = sub.att.flipX == "true";
						var flipY = sub.att.flipY == "true";
						
						pt.setTo(0, 0);
						rect.setTo(x, y, width, height);
						
						var bmp:BitmapData = new BitmapData(width, height, true, 0x00000000);
						bmp.copyPixels(orig, rect, pt);
						
						var scaleX = Std.int(x * scale);
						var scaleY = Std.int(y * scale);
						var scaleW = Std.int(width * scale);
						var scaleH = Std.int(height * scale);
						var scaleFrameX = Std.int(frameX * scale);
						var scaleFrameY = Std.int(frameY * scale);
						var scaleFrameWidth = Std.int(frameWidth * scale);
						var scaleFrameHeight = Std.int(frameHeight * scale);
						
						var scaleBmp:BitmapData = new BitmapData(scaleW, scaleH, true, 0x00000000);
						scaleBmp.draw(bmp, matrix, null, null, null, smooth);
						
						pt.setTo(scaleX, scaleY);
						scaled.copyPixels(scaleBmp, scaleBmp.rect, pt);
						
						var i = Std.parseInt(name);
						
						var subXml = BitmapPacker.subTexNode(i, scaleX, scaleY, scaleW, scaleH, scaleFrameX, scaleFrameY, scaleFrameWidth, scaleFrameHeight, flipX, flipY);
						scaledAtlas.addChild(subXml);
						
						bmp.dispose();
						scaleBmp.dispose();
					}
				}
				
				return { bmp:scaled, atlas:new Fast(scaledAtlas) };
			}
		}
		
		var a2:Xml = Xml.createElement("<TextureAtlas></TextureAtlas/>");
		if (atlas.hasNode.TextureAtlas)
		{
			a2.set("imagePath", atlas.node.TextureAtlas.att.imagePath);
			if (atlas.node.TextureAtlas.hasNode.SubTexture) {
				for (sub in atlas.node.TextureAtlas.nodes.SubTexture) {
					var subXml = BitmapPacker.subTexNode(
						Std.parseInt(sub.att.name), 
						Std.parseInt(sub.att.x),
						Std.parseInt(sub.att.y),
						Std.parseInt(sub.att.width),
						Std.parseInt(sub.att.height),
						Std.parseInt(sub.att.frameX),
						Std.parseInt(sub.att.frameY),
						Std.parseInt(sub.att.frameWidth),
						Std.parseInt(sub.att.frameHeight)
					);
					a2.addChild(subXml);
				}
			}
		}
		return { bmp:orig.clone(), atlas:new Fast(a2) };
	}
	
	
	/**
	 * This scales an image that contains tiles, being super OCD about it, making sure each tile is
	 * properly scaled and put in the correct position
	 * @param	orig_id asset id
	 * @param	scale the scale factor
	 * @param	origW original width of the tile
	 * @param	origH original height of the tile
	 * @param	W final width of the tile
	 * @param	H final height of the tile
	 * @param	smooth
	 * @return
	 */
	public function scaleTileBmp(orig:BitmapData, scale:Float, origW:Int, origH:Int, W:Int = -1, H:Int = -1, smooth:Bool = true):BitmapData
	{
		var widthInTiles:Int = Std.int(orig.width / origW);
		var heightInTiles:Int = Std.int(orig.height / origH);
		
		//if W and H are not provided, infer the correct size
		if (W == -1)
		{
			W = Std.int(origW * scale);
		}
		if (H == -1)
		{
			H = Std.int(origH * scale);
			scale = H / origH;
		}
		
		if (Math.abs(scale - 1.0) > 0.001)
		{
			var scaled:BitmapData = new BitmapData(Std.int(W*widthInTiles), Std.int(H*heightInTiles), true, 0x00000000);
			var rect:Rectangle = new Rectangle();
			var pt:Point = new Point();
			var matrix:Matrix = new Matrix();
			matrix.scale(scale, scale);
			for (tiley in 0...heightInTiles)
			{
				for (tilex in 0...widthInTiles)
				{
					var tile:BitmapData = new BitmapData(origW, origH, true, 0x00000000);
					rect.setTo(tilex * origW, tiley * origH, origW, origH);
					pt.setTo(0, 0);
					tile.copyPixels(orig, rect, pt);
					
					var scaleTile:BitmapData = new BitmapData(W, H, true, 0x000000);
					scaleTile.draw(tile, matrix, null, null, null, smooth);
					pt.setTo(tilex * W, tiley * H);
					scaled.copyPixels(scaleTile, scaleTile.rect, pt);
				}
			}
			return scaled;
		}
		else
		{
			return orig.clone();
		}
	}
	
	private function packRectangles(list:Array<{bmp:BitmapData, rect:Rectangle}>)
	{
		var bmp:BitmapData;
		var space:Rectangle = new Rectangle();
		
		for (i in 0...list.length)
		{
			
		}
	}
	
	private function sortTallest(a: { bmp:BitmapData, rect:Rectangle }, b: { bmp:BitmapData, rect:Rectangle } ):Int
	{
		var asize = a.bmp.height;
		var bsize = b.bmp.height;
		if (asize > bsize) return -1;
		if (asize < bsize) return  1;
		return 0;
	}
	
	private function sortWidest(a: { bmp:BitmapData, rect:Rectangle }, b: { bmp:BitmapData, rect:Rectangle } ):Int
	{
		var asize = a.bmp.width;
		var bsize = b.bmp.width;
		if (asize > bsize) return -1;
		if (asize < bsize) return  1;
		return 0;
	}
	
	private function sortWidestThenTallest(a: { bmp:BitmapData, rect:Rectangle }, b: { bmp:BitmapData, rect:Rectangle } ):Int
	{
		if (a.bmp.width > b.bmp.width) return -1;
		if (a.bmp.width < b.bmp.width) return  1;
		if (a.bmp.height > b.bmp.height) return -1;
		if (a.bmp.height < b.bmp.height) return 1;
		return 0;
	}
	
	private function sortTallestThanWidest(a: { bmp:BitmapData, rect:Rectangle }, b: { bmp:BitmapData, rect:Rectangle } ):Int
	{
		if (a.bmp.height > b.bmp.height) return -1;
		if (a.bmp.height < b.bmp.height) return 1;
		if (a.bmp.width > b.bmp.width) return -1;
		if (a.bmp.width < b.bmp.width) return  1;
		return 0;
	}
	
	private function sortMostPixels(a: { bmp:BitmapData, rect:Rectangle }, b: { bmp:BitmapData, rect:Rectangle } ):Int
	{
		var asize = (a.bmp.width * a.bmp.height);
		var bsize = (b.bmp.width * b.bmp.height);
		if (asize > bsize) return -1;
		if (asize < bsize) return  1;
		return 0;
	}
	
	private function sortBiggest(a: { bmp:BitmapData, rect:Rectangle }, b: { bmp:BitmapData, rect:Rectangle } ):Int
	{
		var asize = Math.max(a.bmp.width, a.bmp.height);
		var bsize = Math.max(b.bmp.width, b.bmp.height);
		if (asize > bsize) return -1;
		if (asize < bsize) return  1;
		return 0;
	}
	
	public function deleteFile(str:String):Void
	{
		if (FileSystem.exists(str))
		{
			FileSystem.deleteFile(str);
		}
	}

	public function writeStr(str:String, name:String):Void
	{
		var error:Bool = false;
		try
		{
			var f:FileOutput = sys.io.File.write(name);
			f.writeString(str);
			f.close();
		}
		catch (msg:String)
		{
			error = true;
			Sys.print("ERROR! (" + msg + ")\n");
		}
	}
	
	public function writeBmp(b:BitmapData,name:String):Void
	{
		trace("writing out to : " + name);
		var bytes:ByteArray = b.encode(b.rect, new PNGEncoderOptions());
		if (bytes != null)
		{
			var error:Bool = false;
			try
			{
				var f:FileOutput = sys.io.File.write(name);
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

	public function removeBorder(bmp:BitmapData, size:Int):BitmapData
	{
		var bmp2 = new BitmapData(bmp.width - size * 2, bmp.height - size * 2, true, 0x00000000);
		bmp2.copyPixels(bmp, bmp.rect, new Point(-size, -size));
		return bmp2;
	}
	
	public function addBorder(bmp:BitmapData, size:Int):BitmapData
	{
		var bmp2 = new BitmapData(bmp.width + size * 2, bmp.height + size * 2, true, 0x00000000);
		bmp2.copyPixels(bmp, bmp.rect, new Point(size, size));
		return bmp2;
	}
	
	public function usage():Void
	{
		trace("usage: dqsprite <inputfile> <outputfile> <final_width> <final_height> ?<orig_width> ?<orig_height>, ex: dqsprite in.png out.png 128 128");
	}
	
	private function diffInComparison(bmp:BitmapData):Int {
		
		var total = 0;
		
		for (yy in 0...bmp.height) {
			for (xx in 0...bmp.width) {
				
				var pix = bmp.getPixel(xx, yy);
				
				var r = (pix >> 16) & 0xFF;
				var g = (pix >> 8 ) & 0xFF;
				var b = (pix      ) & 0xFF;
				
				total += r;
				total += g;
				total += b;
				
			}
		}
		
		return total;
	}

}