package;

import haxe.xml.Fast;
import openfl.display.BitmapDataChannel;
import openfl.display.DisplayObject;
import openfl.display.PNGEncoderOptions;
import openfl.display.Sprite;
import openfl.Lib;
import openfl.display.BitmapData;
import openfl.display.Bitmap;
import openfl.filters.BitmapFilterQuality;
import openfl.filters.GlowFilter;
import openfl.geom.Point;
import openfl.geom.Rectangle;
import openfl.utils.ByteArray;
import sys.FileSystem;
import sys.io.File;
import sys.io.FileOutput;

/**
 * ...
 * @author 
 */
class Main extends Sprite 
{

	public function new() 
	{
		super();
		
		var args = Sys.args();
		var infolder = args[0];
		var outfolder = args[1];
		var cols = args[2] != null ? Std.parseInt(args[2]) : 0;
		var rows = args[3] != null ? Std.parseInt(args[3]) : 0;
		var thick = args[4] != null ? Std.parseInt(args[4]) : 5;
		var color = args[5] != null ? Std.parseInt(args[5]) : 0;
		
		if (args.length < 5){
			Sys.println("Usage: dqspritespacer <infolder> <outprefixfolder> <columns> <rows> <thick> <color>\nex: dqspritespacer C:\\path\\to\\stuff out 10 4 5 0xFFFFFF");
		}
		
		if (cols == 0 || rows == 0) {
			Sys.println("cols = " + cols + " rows = " + rows + ", both must be non-zero");
			Sys.exit(0);
		}
		
		var pngs = getAllPngsInFolder(infolder);
		if(FileSystem.exists(infolder+"/"+outfolder) == false){
			FileSystem.createDirectory(infolder + "/" + outfolder);
		}
		for (png in pngs){
			var infile = infolder + "/" + png;
			var outfile = infolder + "/" + outfolder + "/" + png;
			processAFile(infile, outfile, cols, rows, thick, color, false);
			
			if(png == "mask.png"){
				outfile = infolder + "/" + outfolder + "/outline.png";
				processAFile(infile, outfile, cols, rows, thick, color, true);
			}
		}
		
		Sys.exit(0);
	}
	
	private function processAFile(infile:String, outfile:String, cols:Int, rows:Int, thick:Int, color:Int, doOutline:Bool=false){
		var outBmp = process(infile, cols, rows, thick);
		if(doOutline){
			outBmp = makeOutline(outBmp, color, thick);
		}
		writeBmp(outBmp, outfile);
	}
	
	private function getAllPngsInFolder(folder:String):Array<String>
	{
		var files = FileSystem.readDirectory(folder);
		var pngs = [];
		for (file in files){
			if (FileSystem.isDirectory(file) == false){
				if (file.indexOf(".png") != -1){
					pngs.push(file);
				}
			}
		}
		return pngs;
	}
	
	private function process(infile:String, cols:Int, rows:Int, thick:Int):BitmapData
	{
		var file = infile;
		if (FileSystem.exists(file)){
			var bmp:BitmapData = BitmapData.fromFile(file);
			
			if(cols > 0 && rows > 0){
				bmp = sliceUp(bmp, cols, rows, thick);
			}else if (cols == -1 && rows == -1){
				var atlas = StringTools.replace(infile, ".png", ".xml");
				if (FileSystem.exists(atlas)){
					var atlas = File.getContent(atlas);
					var info = sliceAtlas(bmp, atlas, thick);
				}
			}
			
			return bmp;
		}
		return null;
	}
	
	private function makeOutline(bmp:BitmapData, col:Int, thick:Int):BitmapData
	{
		
		var g:GlowFilter = new GlowFilter(col, 1, thick/2, thick/2, 64, BitmapFilterQuality.HIGH, false, false);
		var b:Bitmap = new Bitmap(bmp);
		b.filters = [g];
		var newBmp = new BitmapData(bmp.width, bmp.height, true, 0x00000000);
		newBmp.draw(b);
		
		var matte = new BitmapData(bmp.width, bmp.height, false);
		matte.copyChannel(bmp, bmp.rect, new Point(), BitmapDataChannel.ALPHA, BitmapDataChannel.RED);
		
		for (ix in 0...matte.width){
			for (iy in 0...matte.height){
				matte.setPixel(ix, iy, 0xFFFFFF - matte.getPixel(ix, iy));
			}
		}
		
		var matte2 = new BitmapData(bmp.width, bmp.height, false);
		matte2.copyChannel(newBmp, newBmp.rect, new Point(), BitmapDataChannel.ALPHA, BitmapDataChannel.RED);
		
		for (ix in 0...matte.width){
			for (iy in 0...matte.height){
				var pix1 = matte.getPixel(ix, iy);
				var pix2 = matte2.getPixel(ix, iy);
				var pix3 = pix1 < pix2 ? pix1 : pix2;
				matte.setPixel(ix, iy, pix3);
			}
		}
		
		newBmp.copyChannel(matte, matte.rect, new Point(), BitmapDataChannel.RED, BitmapDataChannel.ALPHA);
		return newBmp;
	}
	
	private function sliceAtlas(bmp:BitmapData, atlas:String, thick:Int):{bmp:BitmapData,atlas:String}{
		Sys.println("sliceAtlas()");
		var xml = new Fast(Xml.parse(atlas));
		
		//Sys.println("xml = " + xml.x);
		
		if (xml.hasNode.TextureAtlas){
			for (SubTexture in xml.node.TextureAtlas.nodes.SubTexture){
				var flipX:Bool = SubTexture.att.flipX == "true";
				var flipY:Bool = SubTexture.att.flipY == "true";
				var frameHeight:Int = Std.parseInt(SubTexture.att.frameHeight);
				var frameWidth:Int = Std.parseInt(SubTexture.att.frameWidth);
				var frameX:Int = Std.parseInt(SubTexture.att.frameX);
				var frameY:Int = Std.parseInt(SubTexture.att.frameY);
				var width:Int = Std.parseInt(SubTexture.att.width);
				var height:Int = Std.parseInt(SubTexture.att.height);
				var name:String = SubTexture.att.name;
				var x:Int = Std.parseInt(SubTexture.att.x);
				var y:Int = Std.parseInt(SubTexture.att.y);
				
			}
		}
		
		return null;
		/*
		<TextureAtlas imagePath="pack.png">
			<SubTexture flipX="false" flipY="false" frameHeight="125" frameWidth="125" frameX="-31" frameY="-38" height="51" name="0" width="49" x="0" y="0"/>
			<SubTexture flipX="false" flipY="false" frameHeight="125" frameWidth="125" frameX="-45" frameY="-36" height="53" name="1" width="35" x="0" y="51"/>
			<SubTexture flipX="false" flipY="false" frameHeight="125" frameWidth="125" frameX="-7" frameY="-37" height="62" name="10" width="115" x="267" y="0"/>
		*/
	}
	
	private function sliceUp(bmp:BitmapData, cols:Int, rows:Int, thick:Int):BitmapData{
		
		var cellW = Std.int(bmp.width / cols);
		var cellH = Std.int(bmp.height / rows);
		
		var guttersX = cols*2;
		var guttersY = rows*2;
		
		var extraX = thick * guttersX;
		var extraY = thick * guttersY;
		
		var newBmp = new BitmapData(bmp.width + extraX, bmp.height + extraY, true, 0x00000000);
		
		var rect = new Rectangle(0, 0, cellW, cellH);
		var dest = new Point();
		
		for (c in 0...cols){
			for (r in 0...rows){
				rect.x = cellW * c;
				rect.y = cellH * r;
				dest.x = thick + (cellW + thick*2) * c;
				dest.y = thick + (cellH + thick*2) * r;
				newBmp.copyPixels(bmp, rect, dest, null, null, true);
			}
		}
		
		return newBmp;
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
}
