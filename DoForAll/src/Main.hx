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
		doForAll(Sys.args());
		Sys.exit(0);
	}
	
	public function doForAll(args:Array<String>):Void
	{
		if (args == null || args.length == 0) return;
		if (args.length < 3) 
		{
			usage();
			return;
		}
		var command:String = args[0];
		var input:String = args[1];
		var output:String = args[2];
		
		if (FileSystem.exists(input) && FileSystem.isDirectory(input))
		{
			for (file in FileSystem.readDirectory(input))
			{
				var inpath:String = input + "/" + file;
				var outpath:String = output + "/" + file;
				Sys.command(command, [inpath, outpath]);
			}
		}
	}
	
	public function usage():Void
	{
		trace("usage: doforall <command> <input_dir> <output_dir>, ex: doforall waifu2x path/to/in path/to/out");
	}
	
}
