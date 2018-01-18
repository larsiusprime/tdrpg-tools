package;

import flash.geom.Matrix;
import lime.app.Application;
import lime.graphics.Image;
import lime.graphics.ImageBuffer;
import lime.graphics.opengl.GL;
import lime.graphics.RenderContext;
import lime.ui.Window;
import openfl.utils.ByteArray;
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
		
		var dir = FileSystem.readDirectory("");
		
		for (file in dir)
		{
			if (file.indexOf(".stitch.txt") != -1)
			{
				doImg([file, "out"]);
			}
		}
		//doImg(Sys.args());
		
		
		Sys.exit(0);
	}
	
	private function getStitch(stitchStuff:Array<{file:String,point:Point}>):BitmapData
	{
		var bmp:BitmapData = null;
		for (stitch in stitchStuff)
		{
			if (FileSystem.exists(stitch.file))
			{
				if (stitch.file.indexOf("stitch.txt") != -1)
				{
					return getStitch(readStitchFile(stitch.file));
				}
				else
				{
					if (bmp == null)
					{
						bmp = BitmapData.fromFile(stitch.file);
					}
					else
					{
						var bmp2 = BitmapData.fromFile(stitch.file);
						bmp.copyPixels(bmp2, bmp2.rect, stitch.point);
					}
				}
			}
		}
		return bmp;
	}
	
	public function doImg(args:Array<String>):Void
	{
		Sys.println("doImg(" + args + ")");
		
		if (args == null || args.length == 0) return;
		if (args.length < 2)
		{
			return;
		}
		var input:String = args[0];
		var output:String = args[1];
		
		var scale:Float = 544 / 1200;
		var cropLeft:Int = 3;
		
		if (FileSystem.exists(input))
		{
			var stitchStuff = readStitchFile(input);
			
			var i = 0;
			
			if(stitchStuff.length == 2)
			{
				var bkg = stitchStuff[0];
				
				if (FileSystem.exists(bkg.file))
				{
					var bkgBmp:BitmapData = null;
					if (bkg.file.indexOf("stitch.txt") != -1)
					{
						bkgBmp = getStitch(stitchStuff);
					}
					else
					{
						bkgBmp = BitmapData.fromFile(bkg.file);
					}
					var bkgScale = new BitmapData(967, 544, true, 0x00000000);
					var m:Matrix = new Matrix();
					m.scale(scale, scale);
					bkgScale.draw(bkgBmp, m, null, null, null, true);
					var bkgScale2 = new BitmapData(960, 544, false);
					bkgScale2.copyPixels(bkgScale, bkgScale.rect, new Point( -cropLeft, 0));
					
					if (bkg.file.indexOf("stitch.txt") == -1)
					{
						writeBmp(bkgScale2, output + "/" + bkg.file);
					}
				}
				
				var stuff = stitchStuff[1];
				
				var file = stuff.file;
				var pt = stuff.point;
				
				if (FileSystem.exists(file))
				{
					var bmp = BitmapData.fromFile(file);
					var compose = new BitmapData(2133, 1200, true, 0x00000000);
					compose.copyPixels(bmp, bmp.rect, pt);
					
					var matrix:Matrix = new Matrix();
					matrix.scale(scale, scale);
					matrix.translate(-cropLeft, 0);
					var bmp2 = new BitmapData(960, 544, true, 0x00000000);
					bmp2.draw(compose, matrix, null, null, null, true);
					//writeBmp(bmp2, output + "/" + input + ".png");
					
					var ptScale:Point = new Point(pt.x, pt.y);
					ptScale.x = Std.int(scale * pt.x);
					ptScale.y = Std.int(scale * pt.y);
					ptScale.x -= cropLeft;
					
					var newWidth:Int = Std.int(bmp.width*scale);
					var newHeight:Int = Std.int(bmp.height * scale);
					
					if (pt.x != 0 || pt.y != 0)
					{
						//remove 1-pixel gap
						ptScale.x += 1;
						ptScale.y += 1;
						newWidth -= 1;
						newHeight -= 1;
					}
					
					var newFile = bkg.file+"\n" + file+":" + Std.int(ptScale.x) + "," + Std.int(ptScale.y);
					File.saveContent(output + "/" + input, newFile);
					
					var bmp3 = new BitmapData(newWidth, newHeight, true, 0x00000000);
					var rect = new Rectangle(ptScale.x, ptScale.y, newWidth, newHeight);
					
					bmp3.copyPixels(bmp2, rect, new Point(0, 0));
					
					writeBmp(bmp3, output + "/" + file);
				}
				
			}
		}
	}
	
	public function readStitchFile(path:String):Array<{file:String,point:Point}>
	{
		var file = File.getContent(path);
		var stuff = [];
		if (file != null && file != "")
		{
			var strings = file.split("\n");
			for (string in strings)
			{
				var arr = ["\n", "\r", " "];
				for (s in arr){
					while (string.indexOf(s) != -1){
						string = StringTools.replace(string, s, "");
					}
				}
				var line = string.split(":");
				if (line != null && line.length == 2)
				{
					var name = line[0];
					var pointArr = line[1].split(",");
					if (pointArr != null && pointArr.length == 2)
					{
						var point = new Point(Std.parseInt(pointArr[0]), Std.parseInt(pointArr[1]));
						stuff.push({file:name, point:point});
					}
					else
					{
						var point = new Point(0, 0);
						stuff.push({file:name, point:point});
					}
				}
				else
				{
					var point = new Point(0, 0);
					stuff.push({file:string, point:point});
				}
			}
		}
		return stuff;
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
		trace("usage: mouthfix <mouthfile> <outdir>, ex: mouthfix mouth.txt out");
	}
	
	public override function addWindow (window:Window):Void
	{
		//donothing
	}
	
}
