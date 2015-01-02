package;

import flash.display.Bitmap;
import flash.display.BitmapData;
import flash.display.Sprite;
import openfl.utils.ByteArray;
import openfl.geom.Rectangle;
import openfl.geom.Point;
import openfl.Assets;
import openfl.display.BlendMode;
import openfl.display.Shape;
import openfl.Lib;
import sys.FileSystem;
import sys.io.File;
import sys.io.FileOutput;


class Main extends Sprite {
	
	private var path:String = "";
	private var pt:Point = null;
	private var rectStr:String = "";
	
	public function new () {
		
		super ();
		
		pt = new Point();
		
		path = Assets.getText("assets/path.txt");
		
		processPath();
	}
	
	private function processPath():Void
	{
		rectStr = "";
		var list:Array<String> = FileSystem.readDirectory(path);
		for (file in list)
		{
			if (FileSystem.isDirectory(file) == false)
			{
				if (file.indexOf("_talk.png") == -1)
				{
					var str:String = file;
					while (str.indexOf(".png") != -1)
					{
						str = StringTools.replace(str, ".png", "");
					}
					if (FileSystem.exists(path+str + "_talk.png"))
					{
						var rect = reduceTalkFrame(file);
						rectStr += str+":"+rect.x + "," + rect.y + "," + rect.width + "," + rect.height + "\n";
					}
				}
			}
		}
		var f = File.write(path+"mouth.txt");
		f.writeString(rectStr);
		f.close();
	}
	
	private function writeRect(r:Rectangle, name:String):Void
	{
		var f = File.write(name);
		var str:String = r.x + "," + r.y + "," + r.width + "," + r.height;
		f.writeString(str);
		f.close();
	}
	
	private function writeBmp(b:BitmapData,name:String):Void
	{
		var bytes:ByteArray = b.encode("png");
		if (bytes != null)
		{
			try{
				var f:FileOutput = sys.io.File.write(name);
				f.write(bytes);
				f.close();
			}
			catch (e:Dynamic)
			{
				trace("ERROR: " + e);
			}
		}
	}
	
	private function reduceTalkFrame(str:String):Rectangle
	{
		trace("reduceTalkFrame(" + str + ")");
		while(str.indexOf(".png") != -1)
		{
			str = StringTools.replace(str, ".png", "");
		}
		
		var orig = getImage(str + "_talk.png",false);
		var mask = getMask(str + ".png", str + "_talk.png");
		var rect = getMaskRect(mask);
		var mouth = new BitmapData(Std.int(rect.width), Std.int(rect.height), true, 0xFF000000);
		
		mouth.copyPixels(orig, rect, pt);
		writeBmp(mouth, path + str + "_mouth.png");
		
		return rect;
		//writeRect(rect, path + str + "_mouth.txt");
	}
	
	private function getMaskRect(bmp:BitmapData):Rectangle
	{
		var rect = new Rectangle(Math.POSITIVE_INFINITY, Math.POSITIVE_INFINITY, 0, 0);
		for (yy in 0...bmp.height)
		{
			for (xx in 0...bmp.width)
			{
				var pix = bmp.getPixel(xx, yy);
				var r = (pix >> 16) & 0xFF;
				var g = (pix >> 8) & 0xFF;
				var b = pix & 0xFF;
				
				var count:Int = 0;
				if (r > 0) count++;
				if (g > 0) count++;
				if (b > 0) count++;
				
				if (r + g + b > 32)
				{
					if (xx < rect.x)
					{
						rect.x = xx;
					}
					if (yy < rect.y)
					{
						rect.y = yy;
					}
					if (xx - rect.x > rect.width)
					{
						rect.width = xx - rect.x;
					}
					if (yy - rect.y > rect.height)
					{
						rect.height = yy - rect.y;
					}
				}
			}
		}
		
		if (rect.x >= 2)
		{
			rect.x -= 2;
			rect.width += 4;
		}
		else
		{
			var xx = rect.x;
			rect.x -= xx;
			rect.width += xx * 2;
		}
		
		if (rect.y >= 2)
		{
			rect.y -= 2;
			rect.height += 4;
		}
		else
		{
			var yy = rect.y;
			rect.y -= yy;
			rect.height += yy * 2;
		}
		
		if (rect.x + rect.width >= bmp.width) rect.width = (bmp.width - 1 - rect.x);
		if (rect.y + rect.height >= bmp.height) rect.height = (bmp.height - 1- rect.y);
		
		return rect;
	}
	
	private function getMask(str1:String, str2:String):BitmapData
	{
		return (diff(str1, str2));
	}
	
	private function whitenize(img:BitmapData,count:Int=0):BitmapData
	{
		var bitmap1 = new Bitmap(img);
		var bitmap2 = new Bitmap(img);
		
		addChild(bitmap1);
		addChild(bitmap2);
		
		bitmap2.blendMode = BlendMode.ADD;
		
		var result = new BitmapData(Std.int(width), Std.int(height), false, 0xFFFFFF);
		result.draw(this);
		
		removeChild(bitmap1);
		removeChild(bitmap2);
		
		if (count < 1)
		{
			return whitenize(result, count + 1);
		}
		else
		{
			return result;
		}
	}
	
	private function diff(str:String, str2:String):BitmapData
	{
		var bitmap1 = new Bitmap(getImage(str));
		var bitmap2 = new Bitmap(getImage(str2));
		
		addChild(bitmap1);
		addChild(bitmap2);
		
		bitmap2.blendMode = BlendMode.DIFFERENCE;
		
		var result = new BitmapData(Std.int(width), Std.int(height), false, 0xFFFFFFFF);
		result.draw(this);
		
		removeChild(bitmap1);
		removeChild(bitmap2);
		
		bitmap1.bitmapData.dispose();
		bitmap2.bitmapData.dispose();
		
		bitmap1.bitmapData = null;
		bitmap2.bitmapData = null;
		
		return result;
	}
	
	private function getImage(str:String, matte:Bool = true)
	{
		var img1str:String = path + str;
		var img1:BitmapData = BitmapData.load(img1str);
		if (matte)
		{
			var img1a = new BitmapData(img1.width, img1.height, true, 0xFFFFFFFF);
			img1a.copyPixels(img1, img1.rect, new Point(0, 0), null, null, true);
			img1.dispose();
			return img1a;
		}
		return img1;
	}
	
}