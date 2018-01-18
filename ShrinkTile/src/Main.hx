package;

import flash.geom.Matrix;
import flash.geom.Point;
import openfl.display.PNGEncoderOptions;
import openfl.display.Sprite;
import openfl.display.BitmapData;
import openfl.Lib;
import openfl.Assets;
import openfl.geom.Rectangle;
import sys.io.File;

/**
 * ...
 * @author 
 */
class Main extends Sprite 
{

	public function new() 
	{
		super();
		
		var tilesWide:Int = 6;
		var tilesTall:Int = 6;
		var tileWidth:Int = 83;
		var tileHeight:Int = 83;
		var gutter:Int = 1;
		
		var targetWidth:Int = 32;
		var targetHeight:Int = 32;
		
		var finalTilesTall:Int = 4;
		var finalTilesWide:Int = 4;
		var finalGutter:Int = 0;
		
		var scaleW:Float=targetWidth/tileWidth;
		var scaleH:Float=targetHeight/tileHeight;
		
		var tiles:BitmapData = Assets.getBitmapData("img/tiles.png");
		
		var finalWidth  = Std.int((targetWidth  * (finalTilesTall + (finalGutter * 2))) + (finalGutter * 2));
		var finalHeight = Std.int((targetHeight * (finalTilesWide + (finalGutter * 2))) + (finalGutter * 2));
		var finalTiles:BitmapData = new BitmapData(finalWidth, finalHeight, true, 0x00000000);
		
		var finalCutFromStart:Int = 4;
		var finalCutFromEnd:Int = 0;
		var finalSkipEvery:Float = 2;
		
		var px = gutter;
		var py = gutter;
		var fx = gutter;
		var fy = gutter;
		var sourceRect = new Rectangle(0, 0, tileWidth, tileHeight);
		var zeroPt = new Point(0, 0);
		var destPt = new Point(0, 0);
		var matrix = new Matrix();
		
		var finalI:Int = 0;
		var finalSkip:Int = 0;
		
		var finalTilesArray:Array<BitmapData> = [];
		
		for (ty in 0...tilesTall)
		{
			px = gutter;
			
			for (tx in 0...tilesWide)
			{
				sourceRect.x = px;
				sourceRect.y = py;
				var tile:BitmapData = new BitmapData(tileWidth, tileHeight, true, 0x00000000);
				tile.copyPixels(tiles, sourceRect, zeroPt);
				
				matrix.identity();
				matrix.scale(scaleW, scaleH);
				
				var scaledTile:BitmapData = new BitmapData(targetWidth, targetHeight, true, 0x00000000);
				scaledTile.draw(tile, matrix, null, null, null, true);
				
				if(finalI >= finalCutFromStart && finalI < (tilesWide*tilesTall-(finalCutFromEnd+1)))
				{
					finalTilesArray.push(scaledTile);
				}
				
				px += tileWidth + (gutter * 2);
				
				finalI++;
			}
			py += tileHeight + (gutter*2);
		}
		
		var fx = finalGutter;
		var fy = finalGutter;
		var fi = 0;
		var i = 0;
		for (tile in finalTilesArray)
		{
			i++;
			if (i % finalSkipEvery == 0)
			{
				continue;
			}
			
			if (fi >= finalTilesWide)
			{
				fx = finalGutter;
				fy += tile.height + (finalGutter * 2);
				fi = 0;
			}
			
			destPt.setTo(fx, fy);
			finalTiles.copyPixels(tile, tile.rect, destPt);
			
			Sys.println(destPt);
			
			fi++;
			fx += tile.width + (finalGutter * 2);
		}
		
		var bytes = finalTiles.encode(finalTiles.rect, new PNGEncoderOptions());
		File.saveBytes("shrunk.png", bytes);
	}

}
