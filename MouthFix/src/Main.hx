package;

import haxe.io.Bytes;
import lime.app.Application;
import lime.graphics.Image;
import lime.graphics.ImageBuffer;
import lime.graphics.opengl.GL;
import lime.graphics.RenderContext;
import lime.ui.Window;
import openfl.geom.Rectangle;
import openfl.display.BitmapData;
import openfl.display.BitmapDataChannel;
import openfl.display.PNGEncoderOptions;
import openfl.geom.Point;
import openfl.utils.ByteArray;
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
		doMouth(Sys.args());
		Sys.exit(0);
	}
	
	public function doMouth(args:Array<String>):Void
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
			var mouthStuff = readMouthFile(input);
			
			for (stuff in mouthStuff)
			{
				var  posePath = stuff.name+".png";
				var mouthPath = stuff.name+"_mouth.png";
				
				var outMouthPath = output + "/" + mouthPath;
				
				if (FileSystem.exists(posePath) && FileSystem.exists(mouthPath))
				{
					var  pose = BitmapData.fromFile(posePath);
					var mouth = BitmapData.fromFile(mouthPath);
					
					var newMouth = new BitmapData(mouth.width + 2, mouth.height + 2, true);
					
					var r = stuff.rect.clone();
					r.width = mouth.width;
					r.height = mouth.height;
					r.x -= 1;
					r.y -= 1;
					r.width += 2;
					r.height += 2;
					
					newMouth.copyPixels(pose, r, new Point(0,0));				//copy the old pose's closed mouth
					newMouth.copyPixels(mouth, mouth.rect, new Point(1, 1));	//paste the open mouth over it, offset by one pixel
					
					var bigMouth = doScale(newMouth);		//scale it up by 2x
					
					bigMouth = removeBorder(bigMouth, 2);	//remove the border, which is double size now
					
					stuff.rect.x *= 2;						//double up the rectangle
					stuff.rect.y *= 2;
					stuff.rect.width = bigMouth.width;
					stuff.rect.height = bigMouth.height;
					
					writeBmp(bigMouth, outMouthPath);		//write the big mouth out
					
					pose.dispose();
					mouth.dispose();
					newMouth.dispose();
					bigMouth.dispose();
				}
			}
			writeMouthFile(mouthStuff, output + "/mouth.txt");	//write the new and improved mouth file
		}
	}
	
	public function writeMouthFile(mouthStuff:Array<{name:String,rect:Rectangle}>, path:String)
	{
		var str:String = "";
		for (stuff in mouthStuff)
		{
			str += stuff.name+":" + stuff.rect.x + "," + stuff.rect.y + "," + stuff.rect.width + "," + stuff.rect.height + "\n";
		}
		File.saveContent(path, str);
	}
	
	public function readMouthFile(path:String):Array<{name:String,rect:Rectangle}>
	{
		var file = File.getContent(path);
		var stuff = [];
		if (file != null && file != "")
		{
			var strings = file.split("\n");
			for (string in strings)
			{
				var line = string.split(":");
				if (line != null && line.length == 2)
				{
					var name = line[0];
					var rectArr = line[1].split(",");
					if (rectArr != null && rectArr.length == 4)
					{
						var rect = new Rectangle(Std.parseInt(rectArr[0]), Std.parseInt(rectArr[1]), Std.parseInt(rectArr[2]), Std.parseInt(rectArr[3]));
						stuff.push( { name:name, rect:rect } );
					}
				}
			}
		}
		return stuff;
	}
	
	public function doScale(bmp:BitmapData):BitmapData
	{
		var scale:Int = 2;
		var bmp2:BitmapData;
		var orig:BitmapData = bmp;
		var rect = orig.rect;
		
			bmp = addBorder(bmp, 1);
			
			var alpha = new BitmapData(bmp.width, bmp.height, false, 0xFFFFFF);
			alpha.copyChannel(bmp, bmp.rect, new Point(0, 0), BitmapDataChannel.ALPHA, BitmapDataChannel.RED);
			alpha.copyChannel(bmp, bmp.rect, new Point(0, 0), BitmapDataChannel.ALPHA, BitmapDataChannel.GREEN);
			alpha.copyChannel(bmp, bmp.rect, new Point(0, 0), BitmapDataChannel.ALPHA, BitmapDataChannel.BLUE);
			
			var alphaFile = "___temp_alpha_.png";
			var matteFile = "___temp_matte_.png";
			
			writeBmp(alpha, alphaFile);
			
			var matte = new BitmapData(bmp.width, bmp.height, true, 0xFF000000);
			matte.copyPixels(bmp, bmp.rect, new Point(0, 0), null, null, true);
			
			writeBmp(matte, matteFile);
			
			Sys.command("xbr", [alphaFile, "___out_" + alphaFile]);
			Sys.command("xbr", [matteFile, "___out_" + matteFile]);
			
			var alphaBig = BitmapData.fromFile("___out_" + alphaFile);
			var matteBig = BitmapData.fromFile("___out_" + matteFile);
			
			matteBig.copyChannel(alphaBig, alphaBig.rect, new Point(0, 0), BitmapDataChannel.RED, BitmapDataChannel.ALPHA);
			
			bmp = removeBorder(matteBig, scale);
			
			bmp2 = new BitmapData(Std.int(orig.width*scale), Std.int(orig.height*scale), true, 0x00FFFFFF);
			bmp2.copyPixels(bmp, bmp.rect, new Point(rect.x*scale, rect.y*scale));
			
			bmp = bmp2;
			
			deleteFile(alphaFile);
			deleteFile(matteFile);
			deleteFile("___out_" + alphaFile);
			deleteFile("___out_" + matteFile);
			
			return bmp;
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
