package ;
import flash.display.Bitmap;
import flash.display.BitmapData;
import flash.display.BitmapDataChannel;
import flash.display.BlendMode;
import flash.geom.Matrix;
import flash.geom.Point;
import flash.geom.Rectangle;
import flash.Lib;
import openfl.Assets;

/**
 * ...
 * @author larsiusprime
 */
class ProcessImage
{
	private var wit:Int=3;
	private var hit:Int=18;
	private var tileSize:Int = 1;
	private var rect:Rectangle = new Rectangle();
	
	public function new() 
	{
		
	}
	
	private static inline function NW():Point 	{ return new Point(0, 0); };
	private static inline function NORTH():Point{ return new Point(1, 0); };
	private static inline function NE():Point	{ return new Point(2, 0); };
	private static inline function WEST():Point	{ return new Point(0, 1); };
	private static inline function CENT():Point	{ return new Point(1, 1); };
	private static inline function EAST():Point	{ return new Point(2, 1); };
	private static inline function SW():Point	{ return new Point(0, 2); };
	private static inline function SOUTH():Point{ return new Point(1, 2); };
	private static inline function SE():Point	{ return new Point(2, 2); };
	
	private static inline function NplusW():Point	{ return new Point(0, 3); };
	private static inline function NplusE():Point	{ return new Point(2, 3); };
	private static inline function SplusW():Point	{ return new Point(0, 5); };
	private static inline function SplusE():Point	{ return new Point(2, 5); };
	
	private var mt:Matrix = new Matrix();
	private var zero:Point = new Point();
	
	public function addAutoTiles(input:BitmapData,TileSize:Int,Scale:Float,script:String="default.txt"):BitmapData {
		tileSize = Std.int(TileSize * Scale);
		
		var temp:BitmapData = new BitmapData(Std.int(input.width * Scale), Std.int(input.height * Scale), true, 0x00000000);
		mt.identity();
		mt.scale(Scale, Scale);
		temp.draw(input, mt, true);
		
		input = temp;
		
		var zero:Point = new Point(0, 0);
		var output:BitmapData = new BitmapData(tileSize * wit, tileSize * hit, true, 0x00000000);
		output.copyPixels(input, input.rect, zero);
		
		var scriptText:String = Assets.getText("assets/scripts/" + script);
		
		if (scriptText != null && scriptText != "")
		{
			doScript(scriptText, TileSize, Scale, input, output);
		}
		else
		{
			var mNW:BitmapData = getScaledBitmap("img/NW.png", TileSize * Scale);
			var mNE:BitmapData = getScaledBitmap("img/NE.png", TileSize * Scale);
			var mSE:BitmapData = getScaledBitmap("img/SE.png", TileSize * Scale);
			var mSW:BitmapData = getScaledBitmap("img/SW.png", TileSize * Scale);
			var mN:BitmapData = getScaledBitmap("img/NORTH.png", TileSize * Scale);
			var mW:BitmapData = getScaledBitmap("img/WEST.png", TileSize * Scale);
			var mS:BitmapData = getScaledBitmap("img/SOUTH.png", TileSize * Scale);
			var mE:BitmapData = getScaledBitmap("img/EAST.png", TileSize * Scale);
		
			//Triple corner
			copyTiles(input, output, new Point(0, 6), [NW(), NE(), SW()]  , [mSE, mSW, mNE]);
			copyTiles(input, output, new Point(2,6), [NW(), NE(), SE()] , [mSE,mSW,mNW]);
			copyTiles(input, output, new Point(0,8), [NW(), SW(), SE()] , [mSE,mNE,mNW]);
			copyTiles(input, output, new Point(2,8), [NE(), SE(), SW()] , [mSW,mNW,mNE]);
			
			//Double corner
			copyTiles(input, output, new Point(1, 6), [NW(), NE()] , [mSE,mSW]);
			copyTiles(input, output, new Point(0, 7), [NW(), SW()] , [mSE,mNE]);
			copyTiles(input, output, new Point(1, 8), [SW(), SE()] , [mNE,mNW]);
			copyTiles(input, output, new Point(2, 7), [NE(), SE()] , [mSW,mNW]);
		
			//Quadruple corner
			copyTiles(input, output, new Point(1, 7), [NW(), NE(), SW(), SE()] ,[mSE,mSW,mNE,mNW]);
			
			//Faces donut, spinner
			copyTiles(input, output, new Point(0, 9), [SOUTH(), NW()],[mN,mSE]);
			copyTiles(input, output, new Point(1, 9), [SE(), SW(), NORTH()],[mNW,mNE,mS]);
			copyTiles(input, output, new Point(2, 9), [NE(), WEST()],[mSW,mE]);
			copyTiles(input, output, new Point(0, 10), [SE(), NE(), WEST()],[mNW,mSW,mE]);
			
			copyTiles(input, output, new Point(1, 10), [SplusW(),SplusE(),NplusE(),NplusW()],[mNE,mNW,mSW,mSE]);
			
			copyTiles(input, output, new Point(2, 10), [EAST(), SW(), NW()],[mW,mNE,mSE]);
			copyTiles(input, output, new Point(0, 11), [EAST(), SW()],[mW,mNE]);
			copyTiles(input, output, new Point(1, 11), [SOUTH(), NE(), NW()],[mN,mSW,mSE]);
			copyTiles(input, output, new Point(2, 11), [SE(), NORTH()],[mNW,mS]);
			
			//Long thing vert
			copyTiles(input, output, new Point(0, 12), [SplusW(),SplusE()],[mE,mW]);
			copyTiles(input, output, new Point(0, 13), [WEST(), EAST()],[mE,mW]);
			copyTiles(input, output, new Point(0, 14), [NplusW(),NplusE()],[mE,mW]);
			
			//Small spinner
			copyTiles(input, output, new Point(1, 12), [EAST(), NW()], [mW,mSE]);
			copyTiles(input, output, new Point(2, 12), [SOUTH(), NE()], [mN, mSW]);
			copyTiles(input, output, new Point(1, 13), [NORTH(), SW()], [mS, mNE]);
			copyTiles(input, output, new Point(2, 13), [WEST(), SE()], [mE, mNW]);
			
			//Double corner
			copyTiles(input, output, new Point(1, 14), [NE(), SW()], [mSW,mNE]);
			copyTiles(input, output, new Point(2, 14), [NW(), SE()], [mSE,mNW]);
			
			//Long thing horz
			copyTiles(input, output, new Point(0, 15), [NplusE(), SplusE()],[mS,mN]);
			copyTiles(input, output, new Point(1, 15), [NORTH(),   SOUTH()],[mS,mN]);
			copyTiles(input, output, new Point(2, 15), [SplusW(), NplusW()],[mN,mS]);
			
			//Corner sockets
			copyTiles(input, output, new Point(0, 16), [NplusW(), SE()]);
			copyTiles(input, output, new Point(1, 16), [NplusE(), SW()]);
			copyTiles(input, output, new Point(0, 17), [SplusW(), NE()]);
			copyTiles(input, output, new Point(1, 17), [SplusE(), NW()]);
		}
		
		return output;
	}
	
	private function doScript(script:String, TileSize:Int, Scale:Float, input:BitmapData, output:BitmapData)
	{
		var mNW:BitmapData = getScaledBitmap("img/NW.png", TileSize * Scale);
		var mNE:BitmapData = getScaledBitmap("img/NE.png", TileSize * Scale);
		var mSE:BitmapData = getScaledBitmap("img/SE.png", TileSize * Scale);
		var mSW:BitmapData = getScaledBitmap("img/SW.png", TileSize * Scale);
		var mN:BitmapData = getScaledBitmap("img/NORTH.png", TileSize * Scale);
		var mW:BitmapData = getScaledBitmap("img/WEST.png", TileSize * Scale);
		var mS:BitmapData = getScaledBitmap("img/SOUTH.png", TileSize * Scale);
		var mE:BitmapData = getScaledBitmap("img/EAST.png", TileSize * Scale);
		
		var masks:Array<BitmapData> = [mN, mW, mS, mE, mNW, mNE, mSE, mSW];
		var scriptLines:Array<String> = getScriptLines(script);
		
		var trimFirst:Array<String> = ["\t", " "];
		
		for (line in scriptLines)
		{
			var done:Bool = false;
			while (!done) {
				done = true;
				for (trim in trimFirst) {
					while (line.indexOf(trim) == 0)
					{
						line = StringTools.replace(line, trim, "");
						done = false;
					}
				}
			}
			
			if (line.indexOf("//") == 0)
			{
				//donothing
			}
			else
			{
				var groups:Array<String> = line.split("\t\t");
				trace("-->groups = " + groups);
				if (groups != null && groups.length >= 2)
				{
					var point:Point = scriptPoint(groups[0]);
					var regions:Array<Point> = scriptRegions(groups[1]);
					var maskBmps:Array<BitmapData> = null;
					if (groups.length >= 3)
					{
						maskBmps = scriptMasks(groups[2], masks);
					}
					copyTiles(input, output, point, regions, maskBmps);
				}
			}
		}
	}
	
	private function scriptRegions(str:String):Array<Point> {
		var strs:Array<String> = str.split(",");
		var arr:Array<Point> = [];
		if (strs != null) {
			var pt:Point = null;
			for (ptstr in strs) {
				ptstr = ptstr.toUpperCase();
				switch(ptstr) {
					case "CENT": pt = CENT();
					case "N": pt = NORTH();
					case "E": pt = EAST();
					case "W": pt = WEST();
					case "S": pt = SOUTH();
					case "NW": pt = NW();
					case "NE": pt = NE();
					case "SW": pt = SW();
					case "SE": pt = SE();
					case "N+W": pt = NplusW();
					case "N+E": pt = NplusE();
					case "S+W": pt = SplusW();
					case "S+E": pt = SplusE();
				}
				arr.push(pt);
			}
		}
		return arr;
	}
	
	private function scriptMasks(str:String,masks:Array<BitmapData>):Array<BitmapData> {
		var mN:BitmapData = masks[0];
		var mW:BitmapData = masks[1];
		var mS:BitmapData = masks[2];
		var mE:BitmapData = masks[3];
		var mNW:BitmapData = masks[4];
		var mNE:BitmapData = masks[5];
		var mSE:BitmapData = masks[6];
		var mSW:BitmapData = masks[7];
		var strs:Array<String> = str.split(",");
		var arr:Array<BitmapData> = [];
		if (strs != null) {
			var bmp:BitmapData = null;
			var i:Int = 0;
			for (bmpstr in strs) {
				bmpstr = bmpstr.toUpperCase();
				//MURDER THE WHITESPACE!!!!!
				while (bmpstr.indexOf("\t") != -1) {bmpstr = StringTools.replace(bmpstr, "\t", "");}
				while (bmpstr.indexOf("\n") != -1) {bmpstr = StringTools.replace(bmpstr, "\n", "");}
				while (bmpstr.indexOf("\r") != -1) {bmpstr = StringTools.replace(bmpstr, "\r", "");}
				switch(bmpstr) {
					case "N": bmp = mN;
					case "W": bmp = mW;
					case "E": bmp = mE;
					case "S": bmp = mS;
					case "NW": bmp = mNW;
					case "NE": bmp = mNE;
					case "SW": bmp = mSW;
					case "SE": bmp = mSE;
				}
				arr.push(bmp);
			}
		}
		return arr;
	}
	
	private function scriptPoint(str:String):Point {
		var numStr:Array<String> = str.split(",");
		if (numStr != null && numStr.length == 2) {
			return new Point(Std.parseInt(numStr[0]), Std.parseInt(numStr[1]));
		}
		return null;
	}
	
	private function getScriptLines(script:String):Array<String> {
		var lines:Array<String> = script.split("\n");
		for (line in lines)
		{
			while (line.indexOf("\n") != -1) { line = StringTools.replace(line, "\n", ""); }
			while (line.indexOf("\r") != -1) { line = StringTools.replace(line, "\r", ""); }
			while (line.indexOf(" ") == 0)
			{
				line = line.substr(1, line.length - 1);
			}
		}
		return lines;
	}
	
	private function invert(bmp:BitmapData):BitmapData {
		var clone:BitmapData = new BitmapData(bmp.width, bmp.height, true);
		for (xx in 0...bmp.width) {
			for (yy in 0...bmp.height) {
				var argb = bmp.getPixel32(xx, yy);
				var a = (argb >> 24) & 0xFF;
				var r = (argb >> 16) & 0xFF;
				var g = (argb >> 08) & 0xFF;
				var b = (argb      ) & 0xFF;
				r = 255 - r;
				g = 255 - g;
				b = 255 - b;
				argb = (a << 24) | (r << 16) | (g << 8) | b;
				clone.setPixel32(xx, yy, argb);
			}
		}
		return clone;
	}
	
	public static var counter:Int = 0;
	
	private function copyTiles(input:BitmapData, output:BitmapData, dest:Point, regions:Array<Point>, ?masks:Array<BitmapData>):Void
	{
		var i:Int = 0;
		for (pt in regions)
		{
			rect.x = pt.x * tileSize;
			rect.y = pt.y * tileSize;
			rect.width = rect.height = tileSize;
			var destPoint = new Point(dest.x * tileSize, dest.y * tileSize);
			var mask:BitmapData = null;
			
			var tileBit:BitmapData = new BitmapData(tileSize, tileSize, true, 0x00000000);
			tileBit.copyPixels(input, rect, zero, true);
			
			if (masks != null && masks.length > i)
			{
				mask = masks[i];
				if (mask != null)
				{
					var tileBitCopy:BitmapData = new BitmapData(tileBit.width, tileBit.height, true, 0x00000000);
					for (xx in 0...tileBit.width) {
						for (yy in 0...tileBit.height) {
							var argb:Int = tileBit.getPixel32(xx, yy);
							
							var rgb:Int = 0xFFFFFF & argb;
							var alpha:Int = (argb >> 24) & 0xFF;
							
							var maskAlpha:Int = 0xFF & mask.getPixel(xx, yy);	//any channel will do, using blue for now
							
							alpha = cast ((alpha / 255) * (maskAlpha / 255)) * 255;
							
							argb = (alpha << 24) | rgb;
							tileBitCopy.setPixel32(xx, yy, argb);
						}
					}
					
					tileBit = tileBitCopy;
				}
				for (xx in 0...tileBit.width) {
					for (yy in 0...tileBit.height) {
						var finalValue:Int = 0x00ffffff;	//start with transparent black
						if (i != 0) {
							//if something exists, start with that instead
							finalValue = output.getPixel32(cast destPoint.x + xx, cast destPoint.y + yy);
						}
						var tileBitVal:Int = tileBit.getPixel32(xx, yy);
						
						//Split out the channels
						
						var a:Int = (finalValue >> 24) & 0xFF;
						var r:Int = (finalValue >> 16) & 0xFF;
						var g:Int = (finalValue >> 08) & 0xFF;
						var b:Int = (finalValue)       & 0xFF;
						
						var ta:Int = (tileBitVal >> 24) & 0xFF;
						var tr:Int = (tileBitVal >> 16) & 0xFF;
						var tg:Int = (tileBitVal >> 08) & 0xFF;
						var tb:Int = (tileBitVal)       & 0xFF;
						
						var af:Float = (a / 255);
						var taf:Float = (ta / 255);
						
						//Manually do additive blending:
						
						if(a < 1){
							r = Std.int( (r * af) + (tr * (1 - af)) );
							g = Std.int( (g * af) + (tg * (1 - af)) );
							b = Std.int( (b * af) + (tb * (1 - af)) );
						}
						
						a = a + ta;
						
						if (r > 255) r = 255;
						if (g > 255) g = 255;
						if (b > 255) b = 255;
						if (a > 255) a = 255;
						
						finalValue = (a << 24) | (r << 16) | (g << 8) | (b);
						
						output.setPixel32(cast destPoint.x + xx, cast destPoint.y + yy, finalValue);
					}
				}
			}
			else
			{
				output.copyPixels(tileBit, tileBit.rect, destPoint, true);
			}
			
			
			i++;
		}
	}
	
	private function getScaledBitmap(asset:String, targetSize:Float):BitmapData {
		var orig:BitmapData = Assets.getBitmapData(asset);
		if (orig != null) {
			var scaled:BitmapData = new BitmapData(Std.int(targetSize), Std.int(targetSize), true, 0x00000000);
			
			mt.identity();
			mt.scale(targetSize/orig.width, targetSize/orig.height);
			scaled.draw(orig, mt);
			return scaled;
		}
		return null;
	}
}