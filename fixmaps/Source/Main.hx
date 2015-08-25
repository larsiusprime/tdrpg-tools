package;


import haxe.xml.Fast;
import openfl.display.Bitmap;
import openfl.display.BitmapData;
import openfl.display.PNGEncoderOptions;
import openfl.display.Sprite;
import openfl.Assets;
import openfl.geom.Point;
import sys.FileSystem;
import sys.io.File;


class Main extends Sprite {
	
	
	public function new () {
		
		super ();
		
		fixStuff("doodad");
	}
	
	private function fixStuff(fix:String):Void
	{
		var path = "T:\\Development\\Projects\\tdrpg-tools\\fixmaps\\Assets\\maps";
		var out = "T:\\Development\\Projects\\tdrpg-tools\\fixmaps\\Assets\\out";
		
		if (FileSystem.exists(out) == false)
		{
			FileSystem.createDirectory(out);
		}
		
		trace("read path = " + path);
		var files = FileSystem.readDirectory(path);
		for (file in files)
		{
			if (file.indexOf(".png") != -1)
			{
				var root:String = StringTools.replace(file, ".png", "");
				var png = path + "\\" + root + ".png";
				var xml = path + "\\" + root + ".xml";
				
				var fixFile = switch(fix)
				{
					case "start": fixStarts(png, xml);
					case "doodad": fixDoodads(png, xml);
					default: throw "didn't recognize fix command (" + fix + ") !";
				}
				
				var outxml = out + "\\" + root + ".xml";
				var outpng = out + "\\" + root + ".png";
				if (fixFile != null)
				{
					if(fixFile.bmp != null)
					{
						var bytes = fixFile.bmp.encode(fixFile.bmp.rect, new PNGEncoderOptions());
						File.saveBytes(outpng, bytes);
					}
					if (fixFile.str != null)
					{
						File.saveContent(outxml, fixFile.str);
					}
				}
			}
		}
	}
	
	//Fixes doodad xml
	private function fixDoodads(pngFile:String, xmlFile:String): { bmp:BitmapData, str:String }
	{
		if (!FileSystem.exists(xmlFile))
		{
			return null;
		}
		
		var xmlString = File.getContent(xmlFile);
		var xml:Xml = Xml.parse(xmlString);
		
		var fast:Fast = new Fast(xml.firstElement());
		if (fast.hasNode.tiles)
		{
			var tilesXML = fast.node.tiles.x;
			var tilesFast = fast.node.tiles;
			for (tileNode in tilesFast.nodes.tile)
			{
				var tileValue = tileNode.att.value;
				if (tilesFast.hasNode.doodad)
				{
					for (doodadNode in tilesFast.nodes.doodad)
					{
						var doodadValue = doodadNode.att.value;
						if (doodadValue == tileValue)
						{
							var doodadRGB = doodadNode.att.rgb;
							trace("tileNode.x BEFORE = " + tileNode.x);
							tileNode.x.set("doodad", doodadRGB);
							trace("tileNode.x AFTER = " + tileNode.x);
							
							trace("remove doodad = " + tilesXML.removeChild(doodadNode.x));
						}
					}
				}
			}
		}
		
		return { bmp:null, str:xml.toString() };
	}
	
	//Fixes start locations
	private function fixStarts(pngFile:String, xmlFile:String):{bmp:BitmapData,str:String}
	{
		if (!FileSystem.exists(pngFile) || !FileSystem.exists(xmlFile))
		{
			return null;
		}
		
		var bmp = BitmapData.fromFile(pngFile);
		var xmlString = File.getContent(xmlFile);
		var xml:Xml = Xml.parse(xmlString);
		
		var fast:Fast = new Fast(xml.firstElement());
		if (fast.hasNode.tiles)
		{
			for (startNode in fast.node.tiles.nodes.start)
			{
				var colStr = startNode.att.rgb;
				var colInt = Std.parseInt(colStr);
				var coords = getCoordsOfColor(bmp, colInt);
				if (coords != null)
				{
					startNode.x.set("x", Std.string(coords.x));
					startNode.x.set("y", Std.string(coords.y));
				}
			}
			for (endNode in fast.node.tiles.nodes.end)
			{
				var colStr = endNode.att.rgb;
				var colInt = Std.parseInt(colStr);
				var coords = getCoordsOfColor(bmp, colInt);
				if (coords != null)
				{
					endNode.x.set("x", Std.string(coords.x));
					endNode.x.set("y", Std.string(coords.y));
				}
			}
		}
		
		return { bmp:bmp, str:xml.toString() };
	}
	
	private function getCoordsOfColor(bmp:BitmapData, col:Int):Point
	{
		for (yy in 0...14)
		{
			for (xx in 0...15)
			{
				var pix = bmp.getPixel(xx, yy);
				if (pix == col)
				{
					bmp.setPixel(xx, yy, 0x000000);
					return new Point(xx, yy);
				}
			}
		}
		return null;
	}
}