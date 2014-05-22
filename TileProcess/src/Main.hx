package ;

import flash.display.Bitmap;
import flash.display.BitmapData;
import flash.display.Sprite;
import flash.events.Event;
import flash.events.KeyboardEvent;
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
	var theText:TextField;
	/* ENTRY POINT */
	
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
		theText.width = 800;
		addChild(theText);
		
		theText.text = "Click this window (for focus),then press ENTER to load an image";
		
		process = new ProcessImage();
		stage.addEventListener(KeyboardEvent.KEY_DOWN, onKeyDown);
		
		var input = Assets.getBitmapData("img/tile_riverbed.png");
		doProcess(input,false);
	}
	
	function onKeyDown(e:KeyboardEvent):Void {
		if (e.keyCode == 13) {
			var fileStr:Array<String> = Dialogs.openFile("Select a PNG File", "Select a PNG File", { count:1, descriptions:["PNG File"], extensions:["*.png"] } );
			if (fileStr != null) {
				if (FileSystem.exists(fileStr[0]))
				{
					fileName = fileStr[0];
					var input = BitmapData.load(fileStr[0]);
					doProcess(input);
				}
			}
		}
	}
	
	function doProcess(input:BitmapData,write:Bool=true):Void {
		var output:BitmapData = process.addAutoTiles(input, 64, 1.0);
		
		if(write){
			if (stageBmp == null) {
				stageBmp = new Bitmap(null, null, true);
				addChild(stageBmp);
			}
			stageBmp.bitmapData = output;
			
			var hScale:Float = 1;
			if (stageBmp.height > 600) {
				hScale = 600 / stageBmp.height;
			}
			var wScale:Float = 1;
			if (stageBmp.width > 800) {
				wScale = 800 / stageBmp.width;
			}
			var theScale:Float = hScale < wScale ? hScale : wScale;
			
			trace("theScale = " + theScale + " hScale = " + hScale);
			
			stageBmp.scaleX = theScale;
			stageBmp.scaleY = theScale;
			
			var location = Dialogs.saveFile("Select Output File", "blah","");
			
			if(location != "" && location != null){
				var fout:FileOutput = File.write(location,true);
				var bytes:ByteArray = output.encode("png");
				fout.writeString(bytes.toString());
				fout.close();
				theText.text = "Full-Scale file written to : " + location;
			}
		}
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
