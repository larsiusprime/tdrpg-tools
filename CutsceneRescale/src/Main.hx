package;
import firetongue.CSV;
import firetongue.TSV;
import flash.geom.Matrix;
import flash.geom.Point;
import haxe.Utf8;
import haxe.ds.ArraySort;
import lime.app.Application;
import openfl.display.BitmapData;
import openfl.display.PNGEncoderOptions;
import openfl.geom.Rectangle;
import sys.FileSystem;
import sys.io.File;
import sys.io.FileOutput;
import firetongue.FireTongue;

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
			return;
		}
		
		var inDir = args[0];
		var outDir = args[1];
		var scale = Std.parseFloat(args[2]);
		
		rescale(inDir, outDir, scale);
	}
	
	/*****************/
	
	private function rescale(inDir:String, outDir:String, scale:Float):Void
	{
		var inFiles:Array<String> = getFileNames(inDir);
		var mouthMap:Map<String,Point> = null;
		
		for (file in inFiles)
		{
			if (file.indexOf("mouth.txt") != -1)
			{
				mouthMap = makeMouthMap(File.getContent(file));
			}
		}
		
		for (file in inFiles)
		{
			var fileName = file.substring(file.lastIndexOf("/")+1, file.indexOf(".png"));
			var outFile = outDir + "/" + fileName+".png";
			
			Sys.println("file: " + file + " out: " + outFile + " name: " + fileName);
			
			var base = null;
			var image = null;
			
			if (file.indexOf("_mouth.png") != -1)
			{
				var baseFileName = StringTools.replace(fileName, "_mouth", "");
				base = makeMouthStamp(file, mouthMap.get(baseFileName));
				outFile = StringTools.replace(outFile, "_mouth", "_talk");
			}
			else if(file.indexOf(".png") != -1)
			{
				base = BitmapData.fromBytes(File.getBytes(file));
			}
			
			if (base != null)
			{
				image = scaleImage(base, scale);
				
				base.dispose();
				base = null;
				
				writeImage(image, outFile);
			}
			else
			{
				Sys.println(" ERROR! null image");
			}
		}
	}
	
	private function makeMouthStamp(file:String, pt:Point):BitmapData
	{
		var baseFile = StringTools.replace(file, "_mouth", "");
		if (FileSystem.exists(baseFile))
		{
			var base  = BitmapData.fromBytes(File.getBytes(baseFile));
			var mouth = BitmapData.fromBytes(File.getBytes(file));
			base.copyPixels(mouth, mouth.rect, pt);
			mouth.dispose();
			mouth = null;
			return base;
		}
		return null;
	}
	
	private function writeImage(image:BitmapData, file:String):Void
	{
		var bytes = image.encode(image.rect, new PNGEncoderOptions());
		File.saveBytes(file, bytes);
	}
	
	private function scaleImage(image:BitmapData, scale:Float):BitmapData
	{
		var scaledBmp = new BitmapData(Std.int(image.width * scale), Std.int(image.height * scale), true, 0x00000000);
		var matrix = new Matrix();
		matrix.scale(scale, scale);
		scaledBmp.draw(image, matrix, null, null, null, true);
		return scaledBmp;
	}
	
	private function makeMouthMap(mouthFile:String):Map<String,Point>
	{
		var map = new Map<String,Point>();
		var lines = mouthFile.split("\n");
		for (line in lines)
		{
			var entry = line.split(":");
			if (entry != null && entry.length >= 2)
			{
				var r = entry[1].split(",");
				if (r != null && r.length >= 2)
				{
					var pt = new Point(Std.parseInt(r[0]), Std.parseInt(r[1]));
					map.set(entry[0], pt);
				}
			}
		}
		return map;
	}
	
	
	public function writeFiles(dir:String, files:Array<{filename:String,data:String}>)
	{
		for (file in files)
		{
			var fileDir = dir + "/" + file.filename;
			writeStr(file.data, fileDir);
		}
	}
	
	/*****************/

	
	public function getFile(name:String):String
	{
		if (FileSystem.exists(name) && FileSystem.isDirectory(name) == false)
		{
			return (File.getContent(name));
		}
		return "";
	}
	
	public function getFileContents(names:Array<String>):Array<String>
	{
		var data = [];
		for (name in names)
		{
			if (FileSystem.exists(name) && FileSystem.isDirectory(name) == false)
			{
				data.push(File.getContent(name));
			}
		}
		return data;
	}
	
	public function getFileNames(dir:String):Array<String>
	{
		var arr = [];
		if (FileSystem.exists(dir) && FileSystem.isDirectory(dir))
		{
			arr = FileSystem.readDirectory(dir);
			for (i in 0...arr.length)
			{
				arr[i] = dir + "/" + arr[i].toLowerCase();
			}
		}
		return arr;
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
		Sys.println("writing " + str.length + " characters to file(" + name+")...");
		var error:Bool = false;
		try
		{
			File.saveContent(name, str);
		}
		catch (msg:String)
		{
			error = true;
			Sys.print("ERROR! (" + msg + ")\n");
		}
	}
	
	public function usage():Void
	{
		Sys.println("rescale indir outdir <scale> , ex: rescale old new 0.5");
		//Sys.println(usage1 + "\n" + usage2);
	}

}