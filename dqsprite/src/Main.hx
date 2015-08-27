package;

import flixel.util.FlxColor;
import haxe.xml.Fast;
import haxe.xml.Printer;
import openfl.geom.ColorTransform;
import openfl.geom.Matrix;
import lime.app.Application;
import lime.graphics.Image;
import lime.graphics.ImageBuffer;
import lime.graphics.opengl.GL;
import lime.graphics.RenderContext;
import openfl.geom.Rectangle;
import lime.ui.Window;
import lime.utils.ByteArray;
import openfl.display.BitmapData;
import openfl.display.BitmapDataChannel;
import openfl.display.PNGEncoderOptions;
import openfl.geom.Point;
import BitmapPacker.BmpEntry;
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
		doStuff(Sys.args());
		Sys.exit(0);
	}
	
	public function doStuff(args:Array<String>):Void
	{
		if (args == null || args.length == 0) return;
		if (args.length < 4) 
		{
			usage();
			return;
		}
		var input:String = args[0];
		var output:String = args[1];
		
		var new_w:Int = Std.parseInt(args[2]);
		var new_h:Int = Std.parseInt(args[3]);
		
		var orig_w:Int = 0;
		var orig_h:Int = 0;
		
		if (args.length >= 6)
		{
			orig_w = Std.parseInt(args[4]);
			orig_h = Std.parseInt(args[5]);
		}
		
		var layers:String = "";
		
		if (args.length >= 7)
		{
			layers = args[6];
		}
		
		var ww = orig_w;
		var hh = orig_h;
		
		var scale = new_h / orig_h;
		
		if (FileSystem.exists(input))
		{
			var bmp = BitmapData.fromFile(input);
			
			var layers:Array<{name:String,?color:FlxColor}> = getLayerData(layers);
			
			if (layers == null)
			{
				layers = [ { name:"", color:null } ];
			}
			
			var cellsWide:Int = Std.int(bmp.width / ww);
			var cellsTall:Int = Std.int(bmp.height / hh);
			
			var lists:Array<Array<BmpEntry>> = [];
			
			for (layer in layers)
			{
				lists.push([]);
			}
			
			var rect:Rectangle = new Rectangle();
			var pt:Point = new Point();
			
			rect.width = ww;
			rect.height = hh;
			
			var str:String = "";
			
			var i:Int = 0;
			
			//go through and slice out all of the image files
			
			trace("slicing cells....");
			
			var total:Int = cellsTall * cellsWide;
			
			for (yy in 0...cellsTall)
			{
				for (xx in 0...cellsWide)
				{
					rect.x = xx * ww;
					rect.y = yy * hh;
					
					var cell = new BitmapData(ww, hh, true, FlxColor.TRANSPARENT);
					cell.copyPixels(bmp, rect, pt);
					
					var baseCopy:BitmapData = null;
					var baseName:String = "";
					var baseLi:Int = -1;
					
					var li:Int = 0;
					
					for (layer in layers)
					{
						var cellCopy:BitmapData = cell.clone();	//copy the original trimmed layer cell
						
						if (layer.color != null) {
							
							cellCopy = trimOutColorLayer(cellCopy, layer.color, pt);
							
							//We're left with ONLY colors that are a pure tint of this layer's color
							
							if (baseCopy != null)
							{
								var black:BitmapData = new BitmapData(cellCopy.width, cellCopy.height, true, 0xFF000000);
								black.copyChannel(cellCopy, cellCopy.rect, pt, BitmapDataChannel.ALPHA, BitmapDataChannel.ALPHA);
								baseCopy.copyPixels(black, black.rect, pt, null, null, true);
								black.dispose();
							}
							
							var layerBounds:Rectangle = cellCopy.getColorBoundsRect(0xFFFFFFFF, 0x00000000, false);
							var trimColor:BitmapData = new BitmapData(Std.int(layerBounds.width), Std.int(layerBounds.height), true, 0x00000000);
							trimColor.copyPixels(cellCopy, layerBounds, pt);
							
							var xxx = layerBounds.x;
							var yyy = layerBounds.y;
							
							lists[li].push( { index:i, bmp:trimColor, rect:new Rectangle( -xxx, -yyy, ww, hh), flipX:false, dupe:false, layer:layer.name, origBmp:cellCopy } );
						}
						else {
							
							baseCopy = cellCopy;
							baseName = layer.name;
							baseLi = li;
						}
						
						li++;
					}
					
					if (baseCopy != null)
					{
						var layerBounds:Rectangle = baseCopy.getColorBoundsRect(0xFFFFFFFF, 0x00000000, false);
						var baseTrim:BitmapData = new BitmapData(Std.int(layerBounds.width), Std.int(layerBounds.height), true, 0x00000000);
						baseTrim.copyPixels(baseCopy, layerBounds, pt);
						
						var xxx = layerBounds.x;
						var yyy = layerBounds.y;
						
						lists[baseLi].push( { index:i, bmp:baseTrim, rect:new Rectangle( -xxx, -yyy, ww, hh), flipX:false, dupe:false, layer:baseName, origBmp:baseCopy} );
					}
					
					i++;
					
					var percent = Math.floor((i / total) * 1000)/10;
					
					trace("..." + percent + "%");
					
					cell.dispose();
				}
			}
			
			var l = 0;
			for (list in lists)
			{
				trace("processing list: " + l);
				
				list.sort(sortWidestThenTallest);
				list = removeDupesAndFlips(list);
				
				var j:Int = 0;
				for (entry in list)
				{
					if (entry.origBmp != null)
					{
						entry.bmp = entry.origBmp;
						entry.origBmp = null;
					}
					j++;
				}
				
				list = scaleList(list, scale);
				list = trimList(list);
				
				var nw = Std.int(bmp.width * scale);
				var nh = Std.int(bmp.height * scale);
				
				var pack = BitmapPacker.pack(nw, nh, list);
				
				var name = list[0].layer;
				
				if (name == "" || name == null)
				{
					name = StringTools.replace(output, ".png", "");
				}
				
				var out = name + ".png";
				var outXml = name + ".xml";
				
				writeBmp(pack.bmp, out);
				writeStr(FancyPrinter.print(pack.metadata.x, true), outXml);
				l++;
			}
			
		}
		else
		{
			trace("could not find: " + input);
		}
	}
	
	private function trimOutColorLayer(trimCopy:BitmapData, c:FlxColor, pt:Point):BitmapData
	{
		if (c.red == c.green && c.green == c.blue)	//special case, greyscale -- must be strictly monochromatic (no shading)
		{
			//remove anything that isn't exactly the same color
			trimCopy.threshold(trimCopy, trimCopy.rect, pt, "!=", c, 0x00000000, 0x00FFFFFF);
			
			//make it 100% white
			trimCopy.copyChannel(trimCopy, trimCopy.rect, pt, BitmapDataChannel.ALPHA, BitmapDataChannel.RED);
			trimCopy.copyChannel(trimCopy, trimCopy.rect, pt, BitmapDataChannel.ALPHA, BitmapDataChannel.GREEN);
			trimCopy.copyChannel(trimCopy, trimCopy.rect, pt, BitmapDataChannel.ALPHA, BitmapDataChannel.BLUE);
		}
		else {
			
			var testColor:FlxColor = FlxColor.fromRGB(
				((c.red   > 0) ? 1 : 0),
				((c.green > 0) ? 1 : 0),
				((c.blue  > 0) ? 1 : 0)
			);
			
			var rMask:FlxColor = FlxColor.fromRGB((c.red > 0) ? 255 : 0, 0, 0);
			var gMask:FlxColor = FlxColor.fromRGB(0, (c.green > 0) ? 255 : 0, 0);
			var bMask:FlxColor = FlxColor.fromRGB(0, 0, (c.blue > 0) ? 255 : 0);
			
			var invMask:FlxColor = FlxColor.fromRGB(255 - rMask.red, 255 - gMask.green, 255 - bMask.blue);
			
			var invRMask:FlxColor = FlxColor.fromRGB((c.red > 0) ? 0 : 255, 0, 0, 0);
			var invGMask:FlxColor = FlxColor.fromRGB(0, (c.green > 0) ? 0 : 255, 0, 0);
			var invBMask:FlxColor = FlxColor.fromRGB(0, 0, (c.blue > 0) ? 0 : 255, 0);
			
			if(c.red > 0)
				trimCopy.threshold(trimCopy, trimCopy.rect, pt, "<", testColor, 0x00000000, rMask);  //remove anything that DOESN'T have a value >= 1 in     matching channels
				
			if(c.green > 0)
				trimCopy.threshold(trimCopy, trimCopy.rect, pt, "<", testColor, 0x00000000, gMask);  //remove anything that DOESN'T have a value >= 1 in     matching channels
			
			if(c.blue > 0)
				trimCopy.threshold(trimCopy, trimCopy.rect, pt, "<", testColor, 0x00000000, bMask);  //remove anything that DOESN'T have a value >= 1 in     matching channels
			
			if(c.red == 0)
				trimCopy.threshold(trimCopy, trimCopy.rect, pt, ">", 0x00000000, 0x00000000,  invRMask);  //remove anything that DOES    have a value >= 1 in non-matching channels
			
			if(c.green == 0)
				trimCopy.threshold(trimCopy, trimCopy.rect, pt, ">", 0x00000000, 0x00000000,  invGMask);  //remove anything that DOES    have a value >= 1 in non-matching channels
			
			if(c.blue == 0)
				trimCopy.threshold(trimCopy, trimCopy.rect, pt, ">", 0x00000000, 0x00000000,  invBMask);  //remove anything that DOES    have a value >= 1 in non-matching channels
			
			var copyChannel:Int = 0;
			if (c.red   > 0) copyChannel = BitmapDataChannel.RED;
			if (c.green > 0) copyChannel = BitmapDataChannel.GREEN;
			if (c.blue  > 0) copyChannel = BitmapDataChannel.BLUE;
			
			//Make the layer monochrome
			
			if (c.red   <= 0) trimCopy.copyChannel(trimCopy, trimCopy.rect, pt, copyChannel, BitmapDataChannel.RED);
			if (c.green <= 0) trimCopy.copyChannel(trimCopy, trimCopy.rect, pt, copyChannel, BitmapDataChannel.GREEN);
			if (c.blue  <= 0) trimCopy.copyChannel(trimCopy, trimCopy.rect, pt, copyChannel, BitmapDataChannel.BLUE);
		}
		return trimCopy;
	}
	
	private function getLayerData(filename:String):Array<{name:String,?color:FlxColor}>
	{
		if (filename != "")
		{
			var str = File.getContent(filename);
			var xml = new Fast(Xml.parse(str));
			if (xml.hasNode.layer)
			{
				var arr = [];
				for (l in xml.nodes.layer)
				{
					var color = l.has.color ? FlxColor.fromString(l.att.color) : null;
					arr.push( { name:l.att.name, color:color } );
				}
				return arr;
			}
		}
		return null;
	}
	
	public function removeDupesAndFlips(list:Array<BmpEntry>):Array<BmpEntry>
	{
		var newList:Array<BmpEntry> = [];
		
		trace("removeDupesAndFlips");
		
		var i:Int = 0;
		var dupes:Int = 0;
		var flips:Int = 0;
		
		for(entry in list) {
			
			var flipX = false;
			var isDupe = false;
			
			var j:Int = 0;
			//check every other bitmap we've stashed so far
			for (prevEntry in newList) {
				
				var dupeEntry:BmpEntry = null;
				
				if (prevEntry != null && entry != null && prevEntry.dupe == false && prevEntry.bmp != null && entry.bmp != null) {
					
					if (prevEntry.layer      == entry.layer && 
						prevEntry.bmp.width  == entry.bmp.width && 
						prevEntry.bmp.height == entry.bmp.height)
					{
						var compare:Dynamic = entry.bmp.compare(prevEntry.bmp);
						
						if (Std.is(compare, BitmapData))			//a valid comparison
						{
							var bmp:BitmapData = cast compare;
							
							var delta:Int = diffInComparison(bmp);
							var flipOffsetX = ((entry.rect.width - entry.bmp.width) + entry.rect.x) * -1;
							
							//If they're not identical & their coordinates seem like they might be mirror images
							if (delta > 1000 && (flipOffsetX == prevEntry.rect.x && entry.rect.y == prevEntry.rect.y))
							{
								trace("FLIPPY DIPPY");
								
								//Flip it and check again
								var flip = new BitmapData(entry.bmp.width, entry.bmp.height, true, 0x00000000);
								var m = new Matrix();
								m.scale( -1, 1);
								m.translate(entry.bmp.width, 0);
								flip.draw(entry.bmp, m);
								
								var newCompare:Dynamic = flip.compare(prevEntry.bmp);
								if (newCompare == 0)
								{
									compare = newCompare;
									flipX = true;
									flips++;
								}
								else if (Std.is(newCompare, BitmapData))
								{
									var nc:BitmapData = cast newCompare;
									nc.dispose();
								}
								
								flip.dispose();
							}
							
							//if (delta < 10000)
							//{
							//	writeBmp(bmp, "out/"+ prevEntry.layer+"_"+ prevEntry.index + "_vs_" + entry.layer+"_"+entry.index + ".png");
							//}
							
							bmp.dispose();
						}
						
						if (Std.is(compare,Int))			//either a perfect match (0) or an error code (anything else)
						{
							var compareVal:Int = cast compare;
							if (compareVal == 0)
							{
								//if this block is identical (or a flipped mirror) of the previous one, then we just want to copy the previous metadata but with the duplicate frame name
								
								//with one change: we want the x/y of OUR rectangle's offset, not the previous one, to prevent bugs
								//this is in case a duplicate is detected from a trimmed frame that matches on a pixel level, but not on an offset level
								
								var newRect = new Rectangle(entry.rect.x, entry.rect.y, prevEntry.rect.width, prevEntry.rect.height);
								
								if (flipX)
								{
									//we need to reverse the rectangle's x offset coordinate since it's a flip
									
									var rectFlipX = ((entry.rect.width - entry.bmp.width) + entry.rect.x) * -1;
									 newRect.x = rectFlipX;
								}
								
								//TODO: flipped duplicates are mega broken atm, so for now we're just culling regular duplicates
								if (!flipX)
								{
									newList.push( { index:entry.index, bmp:null, rect:newRect, flipX:flipX, dupe:true, dupeOf:j, layer:entry.layer, origBmp:entry.origBmp} );
									isDupe = true;
									dupes++;
									break;
								}
							}
						}
					}
				}
				
				j++;
			}
			
			if (isDupe)
			{
				i++;
				continue;
			}
			
			var newEntry:BmpEntry = { index:entry.index, bmp:entry.bmp, rect:entry.rect, flipX:false, dupe:false, layer:entry.layer, origBmp:entry.origBmp };
			newList.push(newEntry);
			
			i++;
		}
		
		trace("removed " + dupes + ", " + flips + " of them flips");
		
		return newList;
	}
	
	public function trimList(list:Array<BmpEntry>):Array<BmpEntry>
	{
		var pt = new Point();
		for (entry in list)
		{
			if (entry.bmp != null)
			{
				var bmp = entry.bmp;
				
				var layerBounds:Rectangle = bmp.getColorBoundsRect(0xFFFFFFFF, 0x00000000, false);
				var trimColor:BitmapData = new BitmapData(Std.int(layerBounds.width), Std.int(layerBounds.height), true, 0x00000000);
				trimColor.copyPixels(bmp, layerBounds, pt);
				
				entry.bmp = trimColor;
				entry.rect.x = - layerBounds.x;
				entry.rect.y = - layerBounds.y;
				
				bmp.dispose();
			}
		}
		return list;
	}
	
	public function scaleList(list:Array<BmpEntry>, scale:Float, smooth:Bool=true):Array<BmpEntry>
	{
		var newList = [];
		
		var m:Matrix = new Matrix();
		m.scale(scale, scale);
		
		var lastEntry = null;
		
		for (entry in list)
		{
			var nrx = Std.int(entry.rect.x * scale);
			var nry = Std.int(entry.rect.y * scale);
			var nrw = Std.int(entry.rect.width * scale);
			var nrh = Std.int(entry.rect.height * scale);
			if (nrw <= 0) nrw = 1;
			if (nrh <= 0) nrh = 1;
			var newRect:Rectangle = new Rectangle(nrx, nry, nrw, nrh);
			
			var nw = Std.int(entry.bmp.width * scale);
			var nh = Std.int(entry.bmp.height * scale);
			if (nw <= 0) nw = 1;
			if (nh <= 0) nh = 1;
			
			var newBmp:BitmapData = new BitmapData(nw, nh, true, 0x00000000);
			newBmp.draw(entry.bmp, m, null, null, null, smooth);
			
			if (entry.dupe)
			{
				newList.push( {index:entry.index, bmp:newBmp, rect:newRect, flipX:entry.flipX, dupe:true, layer:entry.layer, dupeOf:entry.dupeOf, origBmp:null } );
				continue;
			}
			
			newList.push( { index:entry.index, bmp:newBmp, rect:newRect, flipX:false, dupe:false, layer:entry.layer, dupeOf: -1, origBmp:null } );
		}
		
		return newList;
	}
	
	/*
	public function scaleAtlas(orig:BitmapData, atlas:Fast, scale:Float, smooth:Bool = true): { bmp:BitmapData, atlas:Fast }
	{
		if (Math.abs(scale - 1.0) > 0.001)
		{
			var scaled:BitmapData = new BitmapData(Std.int(scale*orig.width), Std.int(scale*orig.height), true, 0x00000000);
			
			var rect:Rectangle = new Rectangle();
			var pt:Point = new Point();
			var matrix:Matrix = new Matrix();
			matrix.scale(scale, scale);
			
			if (atlas.hasNode.TextureAtlas)
			{
				var scaledAtlas:Xml = Xml.createElement("<TextureAtlas></TextureAtlas/>");
				scaledAtlas.set("imagePath", atlas.node.TextureAtlas.att.imagePath);
				
				if (atlas.node.TextureAtlas.hasNode.SubTexture)
				{
					for (sub in atlas.node.TextureAtlas.nodes.SubTexture)
					{
						var name = sub.att.name;
						var x = Std.parseInt(sub.att.x);
						var y = Std.parseInt(sub.att.y);
						var height = Std.parseInt(sub.att.height);
						var width = Std.parseInt(sub.att.width);
						var frameX = Std.parseInt(sub.att.frameX);
						var frameY = Std.parseInt(sub.att.frameY);
						var frameWidth = Std.parseInt(sub.att.frameWidth);
						var frameHeight = Std.parseInt(sub.att.frameHeight);
						var flipX = sub.att.flipX == "true";
						var flipY = sub.att.flipY == "true";
						
						pt.setTo(0, 0);
						rect.setTo(x, y, width, height);
						
						var bmp:BitmapData = new BitmapData(width, height, true, 0x00000000);
						bmp.copyPixels(orig, rect, pt);
						
						var scaleX = Std.int(x * scale);
						var scaleY = Std.int(y * scale);
						var scaleW = Std.int(width * scale);
						var scaleH = Std.int(height * scale);
						var scaleFrameX = Std.int(frameX * scale);
						var scaleFrameY = Std.int(frameY * scale);
						var scaleFrameWidth = Std.int(frameWidth * scale);
						var scaleFrameHeight = Std.int(frameHeight * scale);
						
						var scaleBmp:BitmapData = new BitmapData(scaleW, scaleH, true, 0x00000000);
						scaleBmp.draw(bmp, matrix, null, null, null, smooth);
						
						pt.setTo(scaleX, scaleY);
						scaled.copyPixels(scaleBmp, scaleBmp.rect, pt);
						
						var i = Std.parseInt(name);
						
						var subXml = BitmapPacker.subTexNode(i, scaleX, scaleY, scaleW, scaleH, scaleFrameX, scaleFrameY, scaleFrameWidth, scaleFrameHeight, flipX, flipY);
						scaledAtlas.addChild(subXml);
						
						bmp.dispose();
						scaleBmp.dispose();
					}
				}
				
				return { bmp:scaled, atlas:new Fast(scaledAtlas) };
			}
		}
		
		var a2:Xml = Xml.createElement("<TextureAtlas></TextureAtlas/>");
		if (atlas.hasNode.TextureAtlas)
		{
			a2.set("imagePath", atlas.node.TextureAtlas.att.imagePath);
			if (atlas.node.TextureAtlas.hasNode.SubTexture) {
				for (sub in atlas.node.TextureAtlas.nodes.SubTexture) {
					var subXml = BitmapPacker.subTexNode(
						Std.parseInt(sub.att.name), 
						Std.parseInt(sub.att.x),
						Std.parseInt(sub.att.y),
						Std.parseInt(sub.att.width),
						Std.parseInt(sub.att.height),
						Std.parseInt(sub.att.frameX),
						Std.parseInt(sub.att.frameY),
						Std.parseInt(sub.att.frameWidth),
						Std.parseInt(sub.att.frameHeight)
					);
					a2.addChild(subXml);
				}
			}
		}
		return { bmp:orig.clone(), atlas:new Fast(a2) };
	}
	*/
	
	
	/**
	 * This scales an image that contains tiles, being super OCD about it, making sure each tile is
	 * properly scaled and put in the correct position
	 * @param	orig_id asset id
	 * @param	scale the scale factor
	 * @param	origW original width of the tile
	 * @param	origH original height of the tile
	 * @param	W final width of the tile
	 * @param	H final height of the tile
	 * @param	smooth
	 * @return
	 */
	public function scaleTileBmp(orig:BitmapData, scale:Float, origW:Int, origH:Int, W:Int = -1, H:Int = -1, smooth:Bool = true):BitmapData
	{
		var widthInTiles:Int = Std.int(orig.width / origW);
		var heightInTiles:Int = Std.int(orig.height / origH);
		
		//if W and H are not provided, infer the correct size
		if (W == -1)
		{
			W = Std.int(origW * scale);
		}
		if (H == -1)
		{
			H = Std.int(origH * scale);
			scale = H / origH;
		}
		
		if (Math.abs(scale - 1.0) > 0.001)
		{
			var scaled:BitmapData = new BitmapData(Std.int(W*widthInTiles), Std.int(H*heightInTiles), true, 0x00000000);
			var rect:Rectangle = new Rectangle();
			var pt:Point = new Point();
			var matrix:Matrix = new Matrix();
			matrix.scale(scale, scale);
			for (tiley in 0...heightInTiles)
			{
				for (tilex in 0...widthInTiles)
				{
					var tile:BitmapData = new BitmapData(origW, origH, true, 0x00000000);
					rect.setTo(tilex * origW, tiley * origH, origW, origH);
					pt.setTo(0, 0);
					tile.copyPixels(orig, rect, pt);
					
					var scaleTile:BitmapData = new BitmapData(W, H, true, 0x000000);
					scaleTile.draw(tile, matrix, null, null, null, smooth);
					pt.setTo(tilex * W, tiley * H);
					scaled.copyPixels(scaleTile, scaleTile.rect, pt);
				}
			}
			return scaled;
		}
		else
		{
			return orig.clone();
		}
	}
	
	private function packRectangles(list:Array<{bmp:BitmapData, rect:Rectangle}>)
	{
		var bmp:BitmapData;
		var space:Rectangle = new Rectangle();
		
		for (i in 0...list.length)
		{
			
		}
	}
	
	private function sortTallest(a: { bmp:BitmapData, rect:Rectangle }, b: { bmp:BitmapData, rect:Rectangle } ):Int
	{
		var asize = a.bmp.height;
		var bsize = b.bmp.height;
		if (asize > bsize) return -1;
		if (asize < bsize) return  1;
		return 0;
	}
	
	private function sortWidest(a: { bmp:BitmapData, rect:Rectangle }, b: { bmp:BitmapData, rect:Rectangle } ):Int
	{
		var asize = a.bmp.width;
		var bsize = b.bmp.width;
		if (asize > bsize) return -1;
		if (asize < bsize) return  1;
		return 0;
	}
	
	private function sortWidestThenTallest(a: { bmp:BitmapData, rect:Rectangle }, b: { bmp:BitmapData, rect:Rectangle } ):Int
	{
		if (a.rect.width > b.rect.width) return -1;
		if (a.rect.width < b.rect.width) return  1;
		if (a.rect.height > b.rect.height) return -1;
		if (a.rect.height < b.rect.height) return 1;
		return 0;
	}
	
	private function sortTallestThanWidest(a: { bmp:BitmapData, rect:Rectangle }, b: { bmp:BitmapData, rect:Rectangle } ):Int
	{
		if (a.bmp.height > b.bmp.height) return -1;
		if (a.bmp.height < b.bmp.height) return 1;
		if (a.bmp.width > b.bmp.width) return -1;
		if (a.bmp.width < b.bmp.width) return  1;
		return 0;
	}
	
	private function sortMostPixels(a: { bmp:BitmapData, rect:Rectangle }, b: { bmp:BitmapData, rect:Rectangle } ):Int
	{
		var asize = (a.bmp.width * a.bmp.height);
		var bsize = (b.bmp.width * b.bmp.height);
		if (asize > bsize) return -1;
		if (asize < bsize) return  1;
		return 0;
	}
	
	private function sortBiggest(a: { bmp:BitmapData, rect:Rectangle }, b: { bmp:BitmapData, rect:Rectangle } ):Int
	{
		var asize = Math.max(a.bmp.width, a.bmp.height);
		var bsize = Math.max(b.bmp.width, b.bmp.height);
		if (asize > bsize) return -1;
		if (asize < bsize) return  1;
		return 0;
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
		trace("usage: dqsprite <inputfile> <outputfile> <final_width> <final_height> ?<orig_width> ?<orig_height>, ex: dqsprite in.png out.png 128 128 192 192 ");
	}
	
	private function diffInComparison(bmp:BitmapData):Int {
		
		var total = 0;
		
		for (yy in 0...bmp.height) {
			for (xx in 0...bmp.width) {
				
				var pix = bmp.getPixel(xx, yy);
				
				var r = (pix >> 16) & 0xFF;
				var g = (pix >> 8 ) & 0xFF;
				var b = (pix      ) & 0xFF;
				
				total += r;
				total += g;
				total += b;
				
			}
		}
		
		return total;
	}

}