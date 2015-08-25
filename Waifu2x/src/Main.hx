package;

import lime.app.Application;
import lime.graphics.Image;
import lime.graphics.ImageBuffer;
import lime.graphics.opengl.GL;
import lime.graphics.RenderContext;
import lime.ui.Window;
import lime.utils.ByteArray;
import openfl.display.BitmapData;
import openfl.display.BitmapDataChannel;
import openfl.display.PNGEncoderOptions;
import openfl.geom.Point;
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
		doScale(Sys.args());
		Sys.exit(0);
	}
	
	public function doScale(args:Array<String>):Void
	{
		if (args == null || args.length == 0) return;
		if (args.length < 2) 
		{
			usage();
			return;
		}
		var input:String = args[0];
		var output:String = args[1];
		var scale:Int = 2;
		if (FileSystem.exists(input))
		{
			var bmp = BitmapData.fromFile(input);
			
			var maskColor:Int = 0xFFFFFFFF;
			var color:Int = 0xFFFFFFFF;
			
			var orig = bmp.rect.clone();
			var rect = bmp.getColorBoundsRect(0xFF000000, 0x00000000, false);
			
			var bmp2 = new BitmapData(Std.int(rect.width), Std.int(rect.height), true, 0x00FFFFFF);
			bmp2.copyPixels(bmp, rect, new Point(0, 0));
			
			bmp = bmp2;
			
			bmp = addBorder(bmp, 1);
			
			var alpha = new BitmapData(bmp.width, bmp.height, false, 0xFFFFFF);
			alpha.copyChannel(bmp, bmp.rect, new Point(0, 0), BitmapDataChannel.ALPHA, BitmapDataChannel.RED);
			alpha.copyChannel(bmp, bmp.rect, new Point(0, 0), BitmapDataChannel.ALPHA, BitmapDataChannel.GREEN);
			alpha.copyChannel(bmp, bmp.rect, new Point(0, 0), BitmapDataChannel.ALPHA, BitmapDataChannel.BLUE);
			
			var alphaFile = "___temp_alpha.png";
			var matteFile = "___temp_matte.png";
			
			writeBmp(alpha, alphaFile);
			
			var matte = new BitmapData(bmp.width, bmp.height, true, 0xFF000000);
			matte.copyPixels(bmp, bmp.rect, new Point(0, 0), null, null, true);
			
			writeBmp(matte, matteFile);
			
			Sys.command("waifu2xscript", ["-i", alphaFile, "-o", "___out" + alphaFile]);
			Sys.command("waifu2xscript", ["-i", matteFile, "-o", "___out" + matteFile]);
			
			var alphaBig = BitmapData.fromFile("___out" + alphaFile);
			var matteBig = BitmapData.fromFile("___out" + matteFile);
			
			matteBig.copyChannel(alphaBig, alphaBig.rect, new Point(0, 0), BitmapDataChannel.RED, BitmapDataChannel.ALPHA);
			
			bmp = removeBorder(matteBig, scale);
			
			bmp2 = new BitmapData(Std.int(orig.width*scale), Std.int(orig.height*scale), true, 0x00FFFFFF);
			bmp2.copyPixels(bmp, bmp.rect, new Point(rect.x*scale, rect.y*scale));
			
			bmp = bmp2;
			
			writeBmp(bmp, output);
			
			deleteFile(alphaFile);
			deleteFile(matteFile);
			deleteFile("___out"+alphaFile);
			deleteFile("___out"+matteFile);
		}
		else
		{
			trace("could not find: " + input);
		}
	}
	
	public function deleteFile(str:String):Void
	{
		if (FileSystem.exists(str))
		{
			FileSystem.deleteFile(str);
		}
	}

	public function writeBmp(b:BitmapData,name:String):Void
	{
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
		trace("usage: waifu2x <input_file> <output_file>, ex: waifu2x in.png out.png");
	}
	
	public override function addWindow (window:Window):Void
	{
		//donothing
	}
	
}
