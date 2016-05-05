package ;
import openfl.display.PNGEncoderOptions;
import openfl.geom.Rectangle;
import openfl.display.BitmapDataChannel;
import openfl.display.BlendMode;
import openfl.geom.Matrix;
import openfl.geom.Point;
import openfl.utils.ByteArray;
import openfl.display.BitmapData;
import sys.FileSystem;
import sys.io.File;
import sys.io.FileOutput;


/**
 * ...
 * @author larsiusprime
 */

class Main 
{
	public static var prefix:String;
	public static var output:String;
	public static var columns:Int;
	
	static function main() 
	{
		var args:Array<String> = Sys.args();
		params = [];
		doStuff(args);
	}
	
	static function doStuff(args:Array<String>):Void{
		if (args == null)
		{
			usage();
			return;
		}
		
		prefix = "";
		output = "";
		columns = 0;
		
		if (args.length >= 1)
		{
			prefix = args[0];
		}
		
		if (args.length >= 2)
		{
			output = args[1];
		}
		
		if (args.length >= 3)
		{
			columns = args[2] != "" ? Std.parseInt(args[2]);
		}
		
		if (prefix == "" || output == "" || columns <= 0)
		{
			usage();
			return;
		}
		
		var list:Array<String> = FileSystem.readDirectory("");
		var files:Array<String> = [];
		for (item in list)
		{
			if (FileSystem.isDirectory(item) == false && item.indexOf(prefix) != -1)
			{
				files.push(item);
			}
		}
		
		var bitmapData = spriteSheet(files, columns);
		File.saveBytes(output, bitmapData.encode(bitmapData.rect, new PNGEncoderOptions()));
	}
		
	public static function spriteSheet(files:Array<String>, columns:Int):BitmapData
	{
		var columns:Int = 0;
		
		var w:Int = 0;
		var h:Int = 0;
		
		var bmps:Array<BitmapData> = [];
		for (file in files)
		{
			bmps.push(new BitmapData.fromFile(file));
		}
		
		w = bmps[0].width;
		h = bmps[0].
		
		columns = Std.parseInt(params[2]);
		
		var r:Rectangle = new Rectangle(0, 0, w, h);
		var pt:Point = new Point();
		var orig_columns = Std.int(w / src.width);
		var orig_rows = Std.int(h / src.height);
		var frames:Array<BitmapData> = [];
		if (orig_columns > 0)
		{
			for (yy in 0...orig_columns)
			{
				for (xx in 0...orig_rows)
				{
					var frame = new BitmapData(w, h, true);
					r.x = w * xx;
					r.y = h * yy;
					frame.copyPixels(src, r, pt);
					frames.push(frame);
				}
			}
		}
		
		var new_rows = Math.ceil(frames.length / columns);
		
		var out = new BitmapData(columns * w, new_rows * h, true);
		r.x = 0;
		r.y = 0;
		
		pt.x = 0;
		pt.y = 0;
		
		for (i in 0...frames.length)
		{
			out.copyPixels(frames[i], frames[i].rect, pt);
			pt.x += w;
			if (pt.x >= out.width)
			{
				pt.x = 0;
				pt.y += h;
			}
		}
		
		return out;
	}
	
	public static function usage():Void
	{
		Sys.println("usage: spritesheet.n <imageprefix> <output.png> <columns>, ex: spritesheet.n image composite.png 14");
	}
	
}