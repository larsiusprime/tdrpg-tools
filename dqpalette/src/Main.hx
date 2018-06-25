package;
import flixel.FlxG;
import flixel.FlxSprite;
import flixel.util.FlxColor;
import lime.app.Application;
import openfl.display.BitmapData;
import openfl.display.PNGEncoderOptions;
import openfl.utils.ByteArray;
import sys.FileSystem;
import sys.io.FileOutput;
import flixel.math.FlxPoint;

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
		if (args == null || args.length < 3)
		{
			usage();
			Sys.exit(0);
		}
		var command = args[0];
		switch(command.toLowerCase())
		{
			case "index": indexify(args[1], args[2]);
			case "combine": combine(args[1], args[2], args[3]);
		}
		
	}
	
	private function combine(input1:String, input2:String, output:String)
	{
		var inputs:Array<FlxColor> = [FlxColor.TRANSPARENT];
		var collisions:Map<String, Array<FlxPoint>> = new Map<String, Array<FlxPoint>>();
		
		if (!FileSystem.exists(input1) || !FileSystem.exists(input2))
		{
			Sys.println("An input file (" + input1 + "," + input2 + ") does not exist");
			Sys.exit(0);
		}
		
		var bmp1:BitmapData = BitmapData.fromFile(input1);
		var bmp2:BitmapData = BitmapData.fromFile(input2);
		
		if (bmp1.width != bmp2.width || bmp1.height != bmp2.height)
		{
			Sys.println("input images are not the same size");
			Sys.exit(0);
		}
		
		var bmp3:BitmapData = new BitmapData(bmp1.width, bmp1.height, true, FlxColor.TRANSPARENT);
		
		for (y in 0...bmp1.height){
			for (x in 0...bmp1.width){
				var col1:FlxColor = bmp1.getPixel32(x, y);
				var col2:FlxColor = bmp2.getPixel32(x, y);
				if (col1 == FlxColor.TRANSPARENT && col2 == FlxColor.TRANSPARENT) 
				{
					continue;
				}
				if (col1 != col2) {
					var str:String = col1.toHexString() + "_" + col2.toHexString();
					if (!collisions.exists(str)){
						collisions.set(str, []);
					}
					var arr = collisions.get(str);
					arr.push(new FlxPoint(x, y));
				}
				else {
					if (inputs.indexOf(col1) == -1) {
						inputs.push(col1);
					}
					var index = inputs.indexOf(col1);
					var col = FlxColor.fromRGB(index, index, index, 255);
					bmp3.setPixel32(x, y, col);
				}
			}
		}
		
		var inputs1:Array<FlxColor> = inputs.copy();
		var inputs2:Array<FlxColor> = inputs.copy();
		
		for (key in collisions.keys())
		{
			var cols:Array<String> = key.split("_");
			var col1:FlxColor = FlxColor.fromString(cols[0]);
			var col2:FlxColor = FlxColor.fromString(cols[1]);
			inputs1.push(col1);
			inputs2.push(col2);
			var ptArray = collisions.get(key);
			for (pt in ptArray)
			{
				var x = Std.int(pt.x);
				var y = Std.int(pt.y);
				var index = inputs1.length - 1;
				var col = FlxColor.fromRGB(index, index, index, 255);
				bmp3.setPixel32(x, y, col);
			}
		}
		
		var outputStub = output;
		if (outputStub.indexOf(".png") != -1){
			outputStub = StringTools.replace(outputStub, ".png", "");
		}
		
		var palette1 = new BitmapData(256, 1, true, FlxColor.TRANSPARENT);
		var palette2 = new BitmapData(256, 1, true, FlxColor.TRANSPARENT);
		
		for (i in 0...inputs1.length)
		{
			palette1.setPixel32(i, 0, inputs1[i]);
			palette2.setPixel32(i, 0, inputs2[i]);
		}
		
		writeBmp(palette1, outputStub + "_palette_1.png");
		writeBmp(palette2, outputStub + "_palette_2.png");
		writeBmp(bmp3, outputStub + ".png");
		
		var out1 = new BitmapData(bmp3.width, bmp3.height, true, FlxColor.TRANSPARENT);
		var out2 = new BitmapData(bmp3.width, bmp3.height, true, FlxColor.TRANSPARENT);
		
		for (y in 0...bmp3.height){
			for (x in 0...bmp3.width){
				var col:FlxColor = bmp3.getPixel32(x, y);
				if (col != FlxColor.TRANSPARENT)
				{
					var index:Int = col.red;
					var col1 = inputs1[index];
					var col2 = inputs2[index];
					out1.setPixel32(x, y, col1);
					out2.setPixel32(x, y, col2);
				}
			}
		}
		
		writeBmp(out1, outputStub + "_test_1.png");
		writeBmp(out2, outputStub + "_test_2.png");
	}
	
	private function indexify(input:String, output:String)
	{
		if (!FileSystem.exists(input)) 
		{
			Sys.println("Input file (" + input + ") does not exist");
			Sys.exit(0);
		}
		
		var bmp:BitmapData = BitmapData.fromFile(input);
		var inputs:Array<FlxColor> = [FlxColor.TRANSPARENT];
		
		for (i in 0...bmp.height){
			var col:FlxColor = bmp.getPixel32(0, i);
			if (col.alpha == 0){
				break;
			}else{
				inputs.push(col);
				bmp.setPixel32(0, i, FlxColor.TRANSPARENT);
			}
		}
		
		for (y in 0...bmp.height){
			for (x in 0...bmp.width) {
				var col:FlxColor = bmp.getPixel32(x, y);
				if (col.alpha == 0) continue;
				var index = inputs.indexOf(col);
				if (index == -1)
				{
					inputs.push(col);
					index = inputs.length - 1;
				}
				var col2 = FlxColor.fromRGB(index, index, index);
				bmp.setPixel32(x, y, col2);
			}
		}
		
		var palette = new BitmapData(256, 1, true, FlxColor.TRANSPARENT);
		for (i in 0...inputs.length)
		{
			palette.setPixel32(i, 0, inputs[i]);
		}
		
		var outputStub = output;
		if (outputStub.indexOf(".png") != -1){
			outputStub = StringTools.replace(outputStub, ".png", "");
		}
		
		writeBmp(palette, outputStub + "_palette.png");
		writeBmp(bmp, outputStub + ".png");
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
	
	public function usage():Void
	{
		Sys.println
		(
		"usage: \n" +
			  "1) dqpalette index <in> <out>, ex: dqpalette index in.png out.png" + "\n" +
			  "2) dqpalette combine <image1> <image2> <out>, ex: dqpalette combine image1.png image2.png out.png"
		);
	}
}