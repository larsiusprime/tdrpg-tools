package ;
import openfl.geom.Rectangle;
import openfl.display.BitmapDataChannel;
import openfl.display.BlendMode;
import openfl.geom.Matrix;
import openfl.geom.Point;
import openfl.utils.ByteArray;
import openfl.display.BitmapData;
import sys.FileSystem;
import sys.io.FileOutput;


/**
 * ...
 * @author larsiusprime
 */

class Main 
{
	
	public static var command:String;
	public static var input:String;
	public static var output:String;
	
	public static var params:Array<String>;
	
	static function main() 
	{
		var args:Array<String> = Sys.args();
		params = [];
		doStuff(args);
	}
	
	static function doStuff(args:Array<String>):Void{
		if (args != null)
		{
			command = "";
			input = "";
			output = "";
			
			if (args.length >= 1)
			{
				command = args[0];
			}
			
			if (args.length >= 2)
			{
				input = args[1];
			}
			
			if (args.length >= 3)
			{
				output = args[2];
			}
			
			if (args.length >= 4)
			{
				for (i in 3...args.length)
				{
					params.push(args[i]);
				}
			}
			
			if (output == "" || output == null)
			{
				output = input;
			}
			
			if (command != "" && input != "")
			{
				if (input == "*")
				{
					var list:Array<String> = FileSystem.readDirectory("");
					for (item in list)
					{
						if (output == "*")
						{
							Sys.command("prep_image " + command + " " + item + " " + item);
						}
						else
						{
							Sys.command("prep_image " + command + " " + item + " " + output);
						}
					}
					return;
				}
				
				if (input.indexOf(".png") == -1)
				{
					Sys.println("input must be a png file");
					return;
				}
				if (output.indexOf(".png") == -1)
				{
					Sys.println("output must be a png file");
					return;
				}
				
				var src:BitmapData = BitmapData.load(input);
				
				switch(command)
				{
					case "help", "-help", "-h", "h": 
								help();
					case "clean": 
								var hasColor:Bool = false;
								var cleanColor:Int = 0;
								if (params != null)
								{
									if (params[0].indexOf("0x") == 0)
									{
										hasColor = true;
										cleanColor = Std.parseInt(params[0]);
									}
								}
								if (hasColor)
								{
									writeBmp(cleanAlpha(src, cleanColor), output);
								}
								else
								{
									writeBmp(cleanAlpha(src), output);
								}
					case "3xbr":
								writeBmp(xbr_3x(src), output);
					case "xbr": 
								writeBmp(xbr(src), output);
					case "layers":
								var colors = getColorList(src);
								var layers = makeLayers(src, colors);
								writeBmpList(layers, output);
					case "xbr_layers": 
								doXBRLayers(src);
					case "dq_layers":
								doXBRLayers(src, 0xFFFFFF);
					case "sprite_sheet":
								if (params.length < 3)
								{
									Sys.println("must supply params: width height columns");
								}
								else
								{
									writeBmp(spriteSheet(src), output);
								}
				}
			}
			else
			{
				usage();
			}
		}else {
			usage();
		}
	}
	
	public static function removeLayers(layers:Array<BitmapData>, counts:Array<Int>, colors:Array<Int>):Array<BitmapData>
	{
		var j:Int = 0;
		for (i in 0...counts.length)
		{
			if (counts[i] == 0)
			{
				var bmp:BitmapData = layers[j];
				bmp.dispose(); bmp = null; layers[j] = null; layers.splice(j, 1);
				colors.splice(j, 1);
				j--;
			}
			j++;
		}
		return layers;
	}
	
	public static function uniqueRandomStr(prefix:String="",suffix:String=".png",count:Int = 10):String
	{
		if (prefix.indexOf(".png") != -1)
		{
			prefix = StringTools.replace(prefix, ".png", "");
		}
		var randStr:String = "";
		var failsafe:Int = 0;
		
		while ((randStr == "" || FileSystem.exists(randStr)) && failsafe < 999)
		{
			randStr = prefix+randomStr()+suffix;
			failsafe++;
		}
		
		if (failsafe > 999)
		{
			return "";
		}
		
		return randStr;
	}
	
	public static function randomStr(count:Int=10):String
	{
		var letters:String = "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789";
		var str:String = "";
		for (i in 0...count)
		{
			var letter:String = letters.charAt(Std.int(Math.random() * letters.length));
			str += letter;
		}
		return str;
	}
	
	public static function help():Void {
		Sys.println("commands: help, clean, xbr, layers, xbr_layers");
	}
	
	public static function getColorList(b:BitmapData):Array<Int>
	{
		var list_colors:Array<Int> = [];
		for (i in 0...Std.int(b.height / 2))
		{
			var argb:Int = b.getPixel32(0, i);
			b.setPixel32(0, i, 0x00000000);
			var alpha:Int = (argb >> 24) & 0xFF;
			if (alpha >= 0x10)
			{
				list_colors.push(argb);
			}
		}
		return list_colors;
	}
	
	public static function makeLayers(b:BitmapData,list_colors:Array<Int>):Array<BitmapData>
	{
		var list_layers:Array<BitmapData> = [];
		for (i in 0...list_colors.length)
		{
			list_layers.push(new BitmapData(b.width, b.height, true, 0x00000000));
		}
		for (yy in 0...b.height)
		{
			for (xx in 0...b.height)
			{
				var argb:Int = b.getPixel32(xx, yy);
				for (col in 0...list_colors.length)
				{
					if (argb == list_colors[col])
					{
						list_layers[col].setPixel32(xx, yy, argb);
					}
				}
			}
		}
		return list_layers;
	}
	
	public static function spriteSheet(src:BitmapData):BitmapData
	{
		var w:Int = 0;
		var h:Int = 0;
		var columns:Int = 0;
		
		if (params.length < 3)
		{
			w = Std.parseInt(params[0]);
			h = Std.parseInt(params[1]);
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
		return null;
	}
	
	public static function doXBRLayers(src:BitmapData, forceColor:Int=0xffffff):Void
	{
		var list_colors = getColorList(src);
		
		var src_xbr = xbr_3x(src);
		
		var layers = makeLayers(src_xbr, list_colors);
		
		var newLayers = layers;
		
		for (i in 0...newLayers.length)
		{
			var color:Int = list_colors[i];
			var alphaMult:Float = 1.0;
			if (color & 0xFFFFFF != 000000)
			{
				alphaMult = 4.0;
			}
			newLayers[i] = cleanColorLayer(newLayers[i], list_colors[i], alphaMult);
		}
		
		writeBmpList(layers, output+"_layer");
		writeBmp(compositeLayers(layers), output + "_composite");
	}
	
	public static function scaleLayers(layers:Array<BitmapData>,scale:Float):Array<BitmapData>
	{
		var matrix:Matrix = new Matrix();
		matrix.scale(scale, scale);
		var list:Array<BitmapData> = [];
		for (bmp in layers)
		{
			var newBmp:BitmapData = new BitmapData(Std.int(bmp.width * scale), Std.int(bmp.height * scale), true, 0x00000000);
			newBmp.draw(bmp, matrix, null, null, null, true);
			list.push(newBmp);
		}
		return list;
	}
	
	public static function cleanColorLayer(src:BitmapData, color:Int, alphaMult:Float=1.0):BitmapData
	{
		#if neko
			if (color == null)
			{
				color = 0x00000000;
			}
		#end
		
		Sys.println("cleanColorLayer color = 0x" + StringTools.hex(color, 8));
		var rgb:Int = color & 0xFFFFFF;
		var a:Int = (color >> 24) & 0xFF;
		
		for (yy in 0...src.height)
		{
			for (xx in 0...src.width)
			{
				var argb:Int = src.getPixel32(xx, yy);
				var alpha:Int = (argb >> 24) & 0xFF;
				alpha = Std.int(alpha*alphaMult);
				if (alpha > 255) { alpha = 255; }
				if (alpha < 0) { alpha = 0; }
				var new_argb = (alpha << 24) + rgb;
				src.setPixel32(xx, yy, new_argb);
			}
		}
		return src;
	}
	
	public static function xbrLayers(layers:Array<BitmapData>):Array<BitmapData>
	{
		for (i in 0...layers.length)
		{
			var oldBmp:BitmapData = layers[i];
			var newBmp:BitmapData = xbr(oldBmp);
			oldBmp.dispose(); oldBmp = null;
			layers[i] = newBmp;
		}
		
		return layers;
	}
	
	public static function compositeLayers(layers:Array<BitmapData>):BitmapData
	{
		var composite:BitmapData = new BitmapData(layers[0].width, layers[0].height, true, 0x00000000);
		for (i in 0...layers.length)
		{
			//if(i != 1 && i != 2){
				composite.copyPixels(layers[i], layers[i].rect, new Point(), null, null, true);
			//}
		}
		return composite;
	}
	
	public static function xbr_3x(b:BitmapData):BitmapData
	{
		var bStr:String = uniqueRandomStr();
		
		var b2:BitmapData = new BitmapData(b.width + 2, b.height + 2, true, 0x00000000);
		b2.copyPixels(b, b.rect, new Point(1, 1));
		
		writeBmp(b2, bStr);
		
		var xbrStr:String = uniqueRandomStr("_xbr");
		
		Sys.command("3xBRLV4 " + bStr + " " + xbrStr);
		
		var bXBR:BitmapData = BitmapData.load(xbrStr);
		
		Sys.command("del " + bStr);
		Sys.command("del " + xbrStr);
		
		var bXBRCrop:BitmapData = new BitmapData(bXBR.width - 6, bXBR.height - 6, true, 0x00000000);
		bXBRCrop.copyPixels(bXBR, bXBR.rect,new Point(-3,-3));
		
		b2.dispose(); b2 = null;
		
		return bXBRCrop;
	}
	
	public static function doCommand(str:String):Void {
		Sys.println(str);
		Sys.command(str);
	}
	
	public static function xbr(b:BitmapData,matteColor:Int=0x00000000):BitmapData
	{
		var bCopy:BitmapData = new BitmapData(b.width + 2, b.height + 2, true, 0x00000000);				//add 1-pixel border to source
		bCopy.copyPixels(b, b.rect, new Point(1, 1));
		
		var temp:BitmapData = new BitmapData(bCopy.width, bCopy.height, false);
		
		var b2:BitmapData = bCopy.clone();
		b2.copyChannel(temp, temp.rect, new Point(), BitmapDataChannel.RED, BitmapDataChannel.ALPHA);	//clear the alpha
		
		var b2Str:String = uniqueRandomStr(input+"_flat_");
		var xbrStr:String = uniqueRandomStr(input+"_flat_xbr_");
		
		writeBmp(b2, b2Str);
		
		Sys.command("xbr " + b2Str + " " + xbrStr + " 2x");		//xbr the input
		
		var bXBR:BitmapData = BitmapData.load(xbrStr);			//load the xbr'ed image
		bXBR.copyChannel(temp, temp.rect, new Point(), BitmapDataChannel.RED, BitmapDataChannel.ALPHA);	//clear the alpha
		
		temp.dispose(); temp = null;
		
		var alphaStr:String = uniqueRandomStr(input + "_alpha_");
		var alphaStr2:String = uniqueRandomStr(input + "_alpha_xbr_");
		
		var bAlpha:BitmapData = new BitmapData(bCopy.width, bCopy.height, false);
		bAlpha.copyChannel(bCopy, bCopy.rect, new Point(), BitmapDataChannel.ALPHA, BitmapDataChannel.RED);		//copy alpha of unscaled original image
		
		writeBmp(bAlpha, alphaStr);									//write out temporary alpha channel
		
		bAlpha.dispose(); bAlpha = null;
		
		Sys.command("xbr " + alphaStr + " " + alphaStr2 + " 2x");	//xbr the alpha channel
		bAlpha = BitmapData.load(alphaStr2);						//load new alpha channel
		
		bXBR.copyChannel(bAlpha, bAlpha.rect, new Point(), BitmapDataChannel.RED, BitmapDataChannel.ALPHA);		//apply the xbr'ed alpha to the xbr'ed image
		
		var bXBRCrop:BitmapData = new BitmapData(bXBR.width - 4, bXBR.height - 4, true, 0x00000000);			//remove 2-pixel border
		bXBRCrop.copyPixels(bXBR, bXBR.rect, new Point(-2, -2));
		
		//cleanup temp files
		
		Sys.command("del " + b2Str);		//delete flattened image
		Sys.command("del " + xbrStr);		//delete xbr'ed flattened image
		Sys.command("del " + alphaStr);		//delete temp alpha
		Sys.command("del " + alphaStr2);	//delete xbr'ed alpha
		
		return bXBRCrop;		//return the final composited image
	}
	
	public static function cleanAlpha(b:BitmapData,cleanColor:Int=0x00000000):BitmapData
	{
		var change:Bool = false;
		var count:Int = 0;
		if (b != null)
		{
			for (xx in 0...b.width)
			{
				for (yy in 0...b.height)
				{
					var argb:Int = b.getPixel32(xx, yy);
					var alpha:Int = (argb >> 24) & 0xFF;
					if (alpha == 0)
					{
						b.setPixel32(xx, yy, cleanColor);	//replace all transparent pixels with clean color (transparent BLACK by default)
						count++;
					}
				}
			}
		}
		if (count > 0)
		{
			Sys.println("...fixed " + count + " pixels!");
			return b;
		}
		return null;
	}
	
	public static function writeBmpList(arr:Array<BitmapData>, name:String):Void
	{
		if (name.indexOf(".png") == -1)
		{
			Sys.println("output must end in .png");
			return;
		}
		name = StringTools.replace(name, ".png", "");
		var i:Int = 0;
		for (b in arr)
		{
			writeBmp(b, name+"_"+i+".png");
			i++;
		}
	}
	
	public static function writeBmp(b:BitmapData,name:String):Void
	{
		if (name.indexOf(".png") == -1)
		{
			Sys.println("output must end in .png");
			return;
		}
		name = StringTools.replace(name, ".png", "");
		if (b == null)
		{
			return;
		}
		var bytes:ByteArray = b.encode("png");
		if (bytes != null)
		{
			Sys.print("writing data to \""+name+"\"...");
			var error:Bool = false;
			try
			{
				var f:FileOutput = sys.io.File.write(name+".png");
				f.write(bytes);
				f.close();
			}
			catch (msg:String)
			{
				error = true;
				Sys.print("ERROR! (" + msg + ")\n");
			}
			if (!error)
			{
				Sys.print("SUCCESS!\n");
			}
		}
	}
	
	public static function usage():Void
	{
		Sys.println("usage: prep_image.n <command> <input.png> <output.png> [options]");
	}
	
}