package;

import lime.app.Application;
import lime.graphics.Image;
import lime.graphics.ImageBuffer;
import lime.graphics.opengl.GL;
import lime.graphics.RenderContext;
import lime.ui.Window;
import lime.utils.ByteArray;
import openfl.geom.Rectangle;
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
		doThing(Sys.args());
		Sys.exit(0);
	}
	
	public function doThing(args:Array<String>):Void
	{
		if (args == null || args.length == 0) return;
		if (args.length < 2)
		{
			usage();
			return;
		}
		var input:String = args[0];
		var output:String = args[1];
		
		if (FileSystem.exists(input))
		{
			var inBmp = BitmapData.fromFile(input);
			
			var alpha = new BitmapData(inBmp.width, inBmp.height, true, 0xFFFFFFFF);
			alpha.copyChannel(inBmp, inBmp.rect, new Point(0, 0), BitmapDataChannel.ALPHA, BitmapDataChannel.RED);
			alpha.copyChannel(inBmp, inBmp.rect, new Point(0, 0), BitmapDataChannel.ALPHA, BitmapDataChannel.GREEN);
			alpha.copyChannel(inBmp, inBmp.rect, new Point(0, 0), BitmapDataChannel.ALPHA, BitmapDataChannel.BLUE);
			
			var matte = new BitmapData(alpha.width, alpha.height, true, 0xFF000000);
			matte.threshold(alpha, alpha.rect, new Point(0, 0), "!=", 0xFF000000, 0xFF808080, 0xFFFFFFFF);
			
			matte.copyChannel(alpha, alpha.rect, new Point(0, 0), BitmapDataChannel.RED, BitmapDataChannel.ALPHA);
			
			writeBmp(matte, output);
			
			//writeBmp(alpha, "alpha_" + output);
			//writeBmp(matte, "matte_" + output);
			
			//Sys.command("convert", [input, "-fill", "#00000000", "-opaque", "none", output]);
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
	
	public function usage():Void
	{
		trace("usage: legacyfix <infile> <outfile>, ex: legacyfix in.png out.png");
	}
	
}
