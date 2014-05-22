package ;

import flash.display.Bitmap;
import flash.display.BitmapData;
import flash.display.Sprite;
import flash.events.Event;
import flash.events.KeyboardEvent;
import flash.geom.Point;
import flash.geom.Rectangle;
import flash.Lib;
import flash.text.TextField;
import flash.utils.ByteArray;
import openfl.Assets;
#if sys
	import sys.io.File;
	import sys.io.FileOutput;
#end
import sys.FileSystem;
import sys.io.FileInput;
import systools.Dialogs;

/**
 * ...
 * @author larsiusprime
 */

class Main extends Sprite 
{
	var inited:Bool;
	var process:ProcessImage;
	var fileName:String = "";
	var stageBmp:Bitmap;
	var stageTest:Bitmap;
	var testMapInts:Array<Int>;
	var testMapSize:Point;
	var theText:TextField;
	
	var state:String = "";
	/* ENTRY POINT */
	
	var stageWidth:Int = 1024;
	var stageHeight:Int = 768;
	
	var tileSize:Int = 64;
	
	function resize(e) 
	{
		if (!inited) init();
		// else (resize or orientation change)
	}
	
	function init() 
	{
		if (inited) return;
		inited = true;

		theText = new TextField();
		theText.textColor = 0xffffff;
		theText.width = stageWidth;
		addChild(theText);
		
		theText.text = "Click this window (for focus),then press ENTER to load an image";
		
		process = new ProcessImage();
		stage.addEventListener(KeyboardEvent.KEY_DOWN, onKeyDown);
		
		var input = Assets.getBitmapData("img/tile_sparse.png");
		doProcess(input, false);
		
		var testMap:BitmapData = Assets.getBitmapData("img/testmap.png");
		testMapInts = ProcessTileMap.getAutoTiles(testMap);
		testMapSize = new Point(testMap.width, testMap.height);
	}
	
	function onKeyDown(e:KeyboardEvent):Void {
		if (e.keyCode == 13) {
			doEnterSomething();
		}
		if (e.keyCode == 32) {
			doSpaceSomething();
		}
		if (e.keyCode == 84) {
			doTSomething();
		}
	}
	
	function doEnterSomething():Void {
		if (state == "" || state == "any") {
			var fileStr:Array<String> = Dialogs.openFile("Select a PNG File", "Select a PNG File", { count:1, descriptions:["PNG File"], extensions:["*.png"] } );
			if (fileStr != null) {
				if (FileSystem.exists(fileStr[0]))
				{
					if (stageBmp != null) {
						var temp = stageBmp.bitmapData;
						stageBmp.bitmapData = null;
						temp.dispose();
						removeChild(stageBmp);
						stageBmp = null;
						
						if (stageTest != null) {
							var temp2 = stageTest.bitmapData;
							stageTest.bitmapData = null;
							temp2.dispose();
							removeChild(stageTest);
							stageTest = null;
						}
					}
					
					fileName = fileStr[0];
					var input = BitmapData.load(fileStr[0]);
					doProcess(input);
					
					state = "any";
					theText.text = "ENTER: load new, SPACE: save processed tile-SET (@ full scale), T: save tile-TEST.";
				}
			}
		}
	}
	
	function doSpaceSomething():Void {
		if (state == "any") {
			var location = Dialogs.saveFile("Select Output File", "blah","");
			
			if (location != "" && location != null) {
				var output:BitmapData = stageBmp.bitmapData;
				var fout:FileOutput = File.write(location,true);
				var bytes:ByteArray = output.encode("png");
				fout.writeString(bytes.toString());
				fout.close();
				theText.text = "File written to : " + location + ". ENTER: load new, SPACE: save tile-SET, T: save tile-TEST";
				state = "any";
			}
		}
	}
	
	function doTSomething():Void {
		if (state == "any") {
			var location = Dialogs.saveFile("Select Output File", "blah","");
			
			if (location != "" && location != null) {
				var output:BitmapData = stageTest.bitmapData;
				var fout:FileOutput = File.write(location,true);
				var bytes:ByteArray = output.encode("png");
				fout.writeString(bytes.toString());
				fout.close();
				theText.text = "File written to : " + location + ". ENTER: load new, SPACE: save tile-SET, T: save tile-TEST";
			}
		}
	}
	
	function doProcess(input:BitmapData,write:Bool=true):Void {
		var output:BitmapData = process.addAutoTiles(input, tileSize, 1.0);
		
		if(write){
			if (stageBmp == null) {
				stageBmp = new Bitmap(null, null, true);
				addChild(stageBmp);
			}
			stageBmp.bitmapData = output;
			
			if (stageTest == null) {
				stageTest = new Bitmap(null, null, true);
				addChild(stageTest);
			}
			stageTest.bitmapData = drawStageTest();
			
			var hScale:Float = 1;
			if (stageBmp.height > stageHeight) {
				hScale = stageHeight / stageBmp.height;
			}
			var wScale:Float = 1;
			if (stageBmp.width > stageWidth) {
				wScale = stageWidth / stageBmp.width;
			}
			var theScale:Float = hScale < wScale ? hScale : wScale;
			
			trace("theScale = " + theScale + " hScale = " + hScale);
			
			stageBmp.scaleX = theScale;
			stageBmp.scaleY = theScale;
			
			hScale = 1;
			wScale = 1;
			if (stageTest.height > (stageHeight-32)) {
				hScale = stageHeight / (stageTest.height-32);
			}
			if (stageTest.width > (stageWidth - stageBmp.width)) {
				wScale = (stageWidth-stageBmp.width) / stageTest.width;
			}
			theScale = hScale < wScale ? hScale : wScale;
			
			stageTest.scaleX = theScale;
			stageTest.scaleY = theScale;
			
			stageTest.x = stageBmp.width;
			stageTest.y = 32;
			stageBmp.y = 32;
		}
	}
	
	function drawStageTest():BitmapData {
		var pt:Point = new Point();
		var rect:Rectangle = new Rectangle();
		rect.width = tileSize;
		rect.height = tileSize;
		var bmp:BitmapData = new BitmapData(cast testMapSize.x * tileSize,cast testMapSize.y * tileSize, true, 0x00000000);
		
		var xi:Int = 0;
		var yi:Int = 0;
		
		for (i in testMapInts) {
			pt = ProcessTileMap.tileIndexToPoint(i, 3, 16, tileSize, pt);
			if(pt.x != -1 && pt.y != -1){
				rect.x = pt.x;
				rect.y = pt.y;
				bmp.copyPixels(stageBmp.bitmapData, rect, new Point(xi*tileSize,yi*tileSize));
			}
			xi++;
			if (xi == testMapSize.x) {
				xi -= cast testMapSize.x;
				yi++;
			}
		}
		return bmp;
	}

	/* SETUP */

	public function new() 
	{
		super();	
		addEventListener(Event.ADDED_TO_STAGE, added);
	}

	function added(e) 
	{
		removeEventListener(Event.ADDED_TO_STAGE, added);
		stage.addEventListener(Event.RESIZE, resize);
		#if ios
		haxe.Timer.delay(init, 100); // iOS 6
		#else
		init();
		#end
	}
	
	public static function main() 
	{
		// static entry point
		Lib.current.stage.align = flash.display.StageAlign.TOP_LEFT;
		Lib.current.stage.scaleMode = flash.display.StageScaleMode.NO_SCALE;
		Lib.current.addChild(new Main());
	}
}
