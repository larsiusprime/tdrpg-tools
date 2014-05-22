package ;
import flash.display.BitmapData;
import flash.geom.Point;

/**
 * ...
 * @author larsiusprime
 */
class ProcessTileMap
{

	public static inline function TILE_REMAP_ARRAY():Array<Int> { 
		var a:Array<Int> = [];
		for (i in 0...480) {
			a[i] = -1;
		}
		a[1] = 4;
		a[2] = 7;
		a[4] = 3;
		a[6] = 15;
		a[8] = 1;
		a[10] = 46;
		a[12] = 9;
		a[14] = 47;
		a[16] = 5;
		a[18] = 17;
		a[20] = 39;
		a[22] = 36;
		a[24] = 11;
		a[26] = 45;
		a[28] = 42;
		a[30] = 31;
		a[32] = 6;
		a[40] = 40;
		a[48] = 33;
		a[56] = 49;
		a[64] = 0;
		a[66] = 27;
		a[80] = 37;
		a[82] = 52;
		a[96] = 21;
		a[112] = 32;
		a[128] = 2;
		a[130] = 38;
		a[132] = 29;
		a[134] = 51;
		a[160] = 43;
		a[192] = 19;
		a[194] = 34;
		a[224] = 18;
		a[256] = 8;
		a[260] = 41;
		a[264] = 35;
		a[268] = 48;
		a[288] = 25;
		a[296] = 28;
		a[320] = 44;
		a[352] = 24;
		a[384] = 23;
		a[388] = 30;
		a[416] = 26;
		a[448] = 20;
		a[480] = 22;
		return a;
	}
	
	private static inline var CENTER:Int = 	 1;
	private static inline var NORTH:Int =	 2;
	private static inline var EAST:Int = 	 4;
	private static inline var SOUTH:Int =	 8;
	private static inline var WEST:Int = 	16;
	private static inline var NE:Int = 		32;
	private static inline var SE:Int =		64;
	private static inline var SW:Int = 		128;
	private static inline var NW:Int = 		256;
	
	public static function getAutoTiles(bd:BitmapData):Array<Int> {
		var intdata:Array<Int> = bmpToIntLayer(bd);
		intdata = autoMap(intdata, bd.width, bd.height);
		intdata = remapArray(intdata, TILE_REMAP_ARRAY());
		return intdata;
	}
	
	public static function tileIndexToPoint(tileIndex:Int, wit:Int, hit:Int, tileSize:Int, returnPoint:Point):Point{
		if (tileIndex == -1) {
			returnPoint.x = -1;
			returnPoint.y = -1;
			return returnPoint;
		}
		var row:Int = Std.int(tileIndex / wit);
		var col:Int = tileIndex % wit;
		returnPoint.x = col * tileSize;
		returnPoint.y = row * tileSize;
		return returnPoint;
	}
	
	private static function bmpToIntLayer(bd:BitmapData):Array<Int>{
		var intdata:Array<Int> = [];
		var pix:Int = 0;
		
		var color_index:Int = 0xFFFFFF;
		
		for(row in 0...bd.height){
			for (col in 0...bd.width) {
				pix = bd.getPixel(col, row);
				if (pix == color_index) {
					pix = 1;
				}else {
					pix = 0;
				}
				intdata.push(pix);
			}
		}
		return intdata;
	}
	
	/**
	 * Pass in an int array of 0's and 1's and its dimensions, and this
	 * will add 1-pixel borders around all the 1's and remap the indeces
	 * @param	intdata
	 * @param	wit
	 * @param	hit	 
	 * @return
	 */
	
	private static function autoMap(intdata:Array<Int>,wit:Int, hit:Int):Array<Int> {
		var newdata:Array<Int> = new Array<Int>();
		for (i in 0...intdata.length) {
			newdata[i] = 0;
		}
		
		for (ix in 0...wit) {			//loop through every cell, x&y
			for (iy in 0...hit) {
				var ii:Int = arrayXY(ix, iy, wit, hit);	//get the index
				
				var value:Int = intdata[ii];		//get original value
				
				var neighborWeight:Int = (value == 0) ? 0 : 1;
				
				var n:Int  = readIntArrayXY(intdata, ix    , iy - 1, wit, hit);
				var ne:Int = readIntArrayXY(intdata, ix + 1, iy - 1, wit, hit);
				var e:Int  = readIntArrayXY(intdata, ix + 1, iy    , wit, hit);
				var se:Int = readIntArrayXY(intdata, ix + 1, iy + 1, wit, hit);
				var s:Int  = readIntArrayXY(intdata, ix    , iy + 1, wit, hit);
				var sw:Int = readIntArrayXY(intdata, ix - 1, iy + 1, wit, hit);
				var w:Int  = readIntArrayXY(intdata, ix - 1, iy    , wit, hit);
				var nw:Int = readIntArrayXY(intdata, ix - 1, iy - 1, wit, hit);
				
				if (n == 1)  { neighborWeight += 2; }
				if (e == 1)  { neighborWeight += 4; }
				if (s == 1)  { neighborWeight += 8; }
				if (w == 1)  { neighborWeight += 16; }
				
				if (ne == 1) { neighborWeight += 32; }
				if (se == 1) { neighborWeight += 64; }
				if (sw == 1) { neighborWeight += 128; }
				if (nw == 1) { neighborWeight += 256; }
				
				newdata[ii] = reduceNumber(neighborWeight);
			}
		}
		
		return newdata;
	}
	
	private static function reduceNumber(input:Int):Int
	{
		//assume the number is between 0 <= 256, ie, 8 bits
		
		//if number contains CENTER tile, it's equivalent to a CENTER tile
		if (input & CENTER == CENTER) return CENTER;
		
		//if number contains NORTH tile, ignore NW & NE values
		if (input & NORTH == NORTH) {
			if (input & NW == NW) { input -= NW; }
			if (input & NE == NE) { input -= NE; }
		}
		
		//if number contains SOUTH tile, ignore SW & SE values
		if (input & SOUTH == SOUTH) {
			if (input & SW == SW) { input -= SW; }
			if (input & SE == SE) { input -= SE; }
		}
		
		//if number contains WEST tile, ignore NW & SW values
		if (input & WEST == WEST) {
			if (input & NW == NW) { input -= NW; }
			if (input & SW == SW) { input -= SW; }
		}
		
		//if number contains EAST tile, ignore NE & SE values
		if (input & EAST == EAST) {
			if (input & NE == NE) { input -= NE; }
			if (input & SE == SE) { input -= SE; }
		}
		
		return input;
	}
	
	private static inline function readIntArrayXY(arr:Array<Int>,ix:Int, iy:Int, iw:Int, ih:Int):Int {
		var i:Int = arrayXY(ix, iy, iw, ih);
		if (i < 0 || i >= arr.length) {
			return -1;
		}
		return arr[i];
	}
	
	private static inline function arrayXY(ix:Int, iy:Int, iw:Int, ih:Int):Int {
		var val:Int = -1;
		if(ix >= 0 && ix < iw && iy >= 0 && iy < ih){
			val = (iy * iw) + ix;
		}
		return val;
	}
	
	private static function remapArray(original:Array<Int>, remapping:Array<Int>):Array<Int> {
		var newArr:Array<Int> = [];
		for (i in 0...original.length) {
			for (j in 0...remapping.length) {
				var origVal:Int = original[i];
				if (origVal == j) {
					newArr[i] = remapping[j];
				}
			}
		}
		return newArr;
	}
}