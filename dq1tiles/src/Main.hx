package;

import lime.app.Application;
import openfl.utils.ByteArray;
import openfl.geom.Matrix;
import sys.io.FileOutput;
import openfl.display.BitmapData;
import openfl.display.PNGEncoderOptions;
import flixel.util.FlxColor;
import haxe.xml.Fast;
import openfl.geom.Rectangle;
import openfl.geom.Point;
import sys.FileSystem;

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
		var dqgame:Int = 1;
		if (args.length == 5)
		{
			dqgame = Std.parseInt(args[4]);
		}
		var reverse:Bool = false;
		if (args.indexOf("-r") != -1)
		{
			reverse = true;
		}
		var infile:String = args[0];
		var width  = Std.parseInt(args[1]);
		var height = Std.parseInt(args[2]);
		var outfile:String = args[3];
		
		var infiles = [infile];
		var outfiles = [outfile];
		
		if ((infile == "*.png" || infile == "*") && outfile.indexOf("*") != -1)
		{
			infiles = [];
			outfiles = [];
			var list = FileSystem.readDirectory("");
			for (f in list)
			{
				if (f.indexOf(".png") != -1)
				{
					infiles.push(f);
					outfiles.push(StringTools.replace(outfile, "*", f));
				}
			}
		}
		
		for (i in 0...infiles.length)
		{
			var inf = infiles[i];
			var outf = outfiles[i];
			
			if (!FileSystem.exists(inf))
			{
				trace("file does not exist : " + inf);
				continue;
			}
			
			if (!reverse)
			{
				makeTileFancy(inf, outf, width, height);
			}
			else
			{
				makeTileStrip(inf, outf, width, height);
			}
		}
	}
	
	private function makeTileFancy(infile:String, outfile:String, width:Int, height:Int):Void {
		var pattern = new Pattern();
		
		var bmp:BitmapData = new BitmapData(Std.int(width * pattern.width), Std.int(height * pattern.height), true, FlxColor.TRANSPARENT);
		var rect:Rectangle = new Rectangle();
		var pt:Point = new Point();
		
		var inBmp:BitmapData = BitmapData.fromFile(infile);
		
		var hw = Std.int(width / 2);
		var hh = Std.int(height / 2);
		
		while (!pattern.atEnd()) {
			var tile = pattern.getNext();
			pt.setTo(tile.out_x * width, tile.out_y * height);
			if (tile.crop_half == "")
			{
				rect.setTo(tile.in_x * width, tile.in_y * height, width, height);
			}
			else {
				switch(tile.crop_half.toLowerCase())
				{
					case "left"  : rect.setTo(tile.in_x * width + hw, tile.in_y * height, hw, height);
								   pt.x += hw;
					case "right" : rect.setTo(tile.in_x * width, tile.in_y * height, hw, height);
					case "top"   : rect.setTo(tile.in_x * width, tile.in_y * height + hh, width, hh);
								   pt.y += hh;
					case "bottom": rect.setTo(tile.in_x * width, tile.in_y * height, width, hh);
				}
			}
			bmp.copyPixels(inBmp, rect, pt);
		}
		
		writeBmp(bmp, outfile);
	}
	
	private function makeTileStrip(infile:String, outfile:String, width:Int, height:Int):Void {
		var pattern = new Pattern();
		
		var bmp:BitmapData = new BitmapData(Std.int(width * pattern.length), height, true, FlxColor.TRANSPARENT);
		var rect:Rectangle = new Rectangle();
		var pt:Point = new Point();
		
		var inBmp:BitmapData = BitmapData.fromFile(infile);
		
		var i:Int = 0;
		while (!pattern.atEnd()) {
			var tile = pattern.getNext();
			
			if (tile.crop_half != "") {
				continue;
			}
			
			rect.setTo(tile.out_x * width, tile.out_y * height, width, height);
			pt.setTo(width * tile.in_x, height * tile.in_y);
			
			bmp.copyPixels(inBmp, rect, pt);
			i++;
		}
		
		writeBmp(bmp, outfile);
	}
	
	public function usage():Void
	{
		trace("usage: dqtiles <infile> <width> <height> <outfile> <?dq_game_number>, ex: dqtiles in.png 20 20 out.png, ex2: dqtiles in.png 20 20 1\nUse '-r' flag to reverse the operation");
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