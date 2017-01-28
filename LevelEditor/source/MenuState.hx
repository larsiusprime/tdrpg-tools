package;

import flash.display.BitmapData;
import flash.geom.Point;
import flash.geom.Rectangle;
import flash.net.FileFilter;
import flash.net.FileReference;
import flixel.FlxG;
import flixel.FlxSprite;
import flixel.FlxState;
import flixel.addons.ui.FlxUIButton;
import flixel.addons.ui.FlxUIList;
import flixel.addons.ui.FlxUINumericStepper;
import flixel.addons.ui.FlxUIState;
import flixel.addons.ui.FlxUITypedButton;
import flixel.addons.ui.interfaces.IFlxUIWidget;
import flixel.text.FlxText;
import flixel.ui.FlxButton;
import flixel.math.FlxMath;
import flixel.util.FlxColor;
import haxe.xml.Fast;
import haxe.xml.Printer;
import lime.ui.FileDialog;
import lime.ui.FileDialogType;
import openfl.display.PNGEncoderOptions;
import openfl.events.Event;
import openfl.utils.ByteArray;
import sys.FileSystem;
import sys.io.File;
import unifill.Unifill;
import WaveWidget.WaveInfo;

class MenuState extends FlxUIState
{
	public static var dq1:Settings;
	public static var dq2:Settings;
	
	private static inline var LAYER_X:Int = 5;
	private static inline var LAYER_Y:Int = 5;
	
	private static inline var WAVE_X:Int = 550;
	private static inline var WAVE_Y:Int = 250;
	
	public var sigil:Int = 0;
	public var tool:Tool = Tool.Pencil;
	public var toolFlows:Bool = true;
	
	public static inline var START_I:Int = 1;
	public static inline var END_I:Int = 6;
	
	override public function create():Void
	{
		super.create();
		FlxG.sound.muted = false;
		makeBkg();
		makeSettings();
		load(dq1);
	}
	
	override public function update(elapsed:Float):Void 
	{
		if (FlxG.keys.pressed.SPACE){
			tool = Bucket;
		}
		else{
			tool = Pencil;
		}
		
		if (FlxG.keys.justPressed.Z && FlxG.keys.pressed.CONTROL){
			undo();
		}
		else if (FlxG.keys.justPressed.Y && FlxG.keys.pressed.CONTROL){
			redo();
		}
		
		if (FlxG.keys.justPressed.ONE)   doSigil(1);
		if (FlxG.keys.justPressed.TWO)   doSigil(2);
		if (FlxG.keys.justPressed.THREE) doSigil(3);
		if (FlxG.keys.justPressed.FOUR)  doSigil(4);
		if (FlxG.keys.justPressed.FIVE)  doSigil(5);
		if (FlxG.keys.justPressed.A)     doSigil(6);
		if (FlxG.keys.justPressed.B)     doSigil(7);
		if (FlxG.keys.justPressed.C)     doSigil(8);
		if (FlxG.keys.justPressed.D)     doSigil(9);
		if (FlxG.keys.justPressed.E)     doSigil(10);
		
		super.update(elapsed);
		updateInput(elapsed);
	}
	
	override public function getEvent(id:String, sender:Dynamic, data:Dynamic, ?params:Array<Dynamic>):Void 
	{
		super.getEvent(id, sender, data, params);
		switch(id){
			case "delete_wave":
				var i:Int = cast data;
				waves.splice(i, 1);
				refreshWaves();
			case "add_wave":
				waves.push(getWave());
				refreshWaves();
			case FlxUINumericStepper.CHANGE_EVENT,"sigil_change":
				if (params != null && params.indexOf("wave_widget") != -1){
					var widget = cast(sender, IFlxUIWidget);
					resolveWidgetChange(widget, params);
				}
		}
	}
	
	//PRIVATE
	
	private var waves:Array<WaveInfo>;
	private var waveWidgets:Array<WaveWidget>;
	private var hintText:FlxText;
	private var sigilSprite:FlxSprite;
	private var sigilHint:String;
	private var layers:Array<MapLayer>;
	private var data:Settings;
	private var maxUndo:Int = 100;
	private var undoPointer:Int = -1;
	private var undoBuffer:Array<EditState>;
	private var tempState:EditState;
	private var waveList:FlxUIList;
	
	private function resolveWidgetChange(widget:IFlxUIWidget, params:Array<Dynamic>){
		
		var i:Int = 0;
		for (waveWidget in waveWidgets){
			if (waveWidget.owns(widget)){
				trace("write wave info (" + i + ")!");
				waveWidget.write(waves[i]);
			}
			i++;
		}
		
	}
	
	private function updateInput(elapsed:Float){
		
		for (i in 0...layers.length){
			var layer = layers[i];
			layer.update();
			if (toolFlows && (tool != Bucket && tool != Turpentine)){
				if (layer.button.pressed){
					doInput(layer);
				}
				else if (layer.rightButton.pressed){
					doInput(layer, true);
				}
			}
			else{
				if (layer.button.justPressed){
					doInput(layer, false, true);
				}
				else if (layer.rightButton.justPressed){
					doInput(layer, true, true);
				}
			}
		}
		
	}
	
	private function doSigil(i:Int){
		sigil = i - 1;
		sigilSprite.animation.frameIndex = sigil;
		var changeHint:Bool = (hintText.text == sigilHint);
		sigilHint = switch(i){
			case 1, 2, 3, 4, 5:
				"Enemy start loc " + (i);
			case 6:
				"Mcguffin end loc";
			case 7, 8, 9, 10:
				"Ally " + (i-END_I) + " end loc";
			default:
				"";
		}
		if (changeHint){
			hintText.text = sigilHint;
		}
	}
	
	private function doInput(layer:MapLayer, rightClick:Bool = false, justPressed:Bool=false){
		var change = false;
		tempState.sync(layers);
		
		var skipTool = false;
		if (!layer.editable)
		{
			if (layer.hasSigils){
				if (!rightClick)
				{
					change = layer.onSigilPlace(sigil);
				}
				else{
					change = layer.onSigilErase(sigil);
				}
				skipTool = true;
			}
		}
		
		if(!skipTool){
			switch(tool){
				case Pencil:
					if(!rightClick){
						change = layer.onPencil();
					}
					else{
						change = layer.onEraser();
					}
				case Eraser:
					change = layer.onEraser();
				case Bucket:
					if (justPressed)
					{
						if(!rightClick){
							change = layer.onBucket();
						}
						else{
							change = layer.onTurpentine();
						}
					}
				case Turpentine:
					if (justPressed)
					{
						change = layer.onTurpentine();
					}
			}
		}
		composite();
		
		if(change){
			pushUndo(tempState);
			tempState = new EditState(layers);
		}
	}
	
	private function redo(){
		if (undoBuffer == null || undoBuffer.length == 0) {
			return;
		}
		
		if (undoPointer == -1){
			return;
		}
		
		if (undoPointer < undoBuffer.length-1){
			undoPointer++;
		}
		else {
			return;
		}
		
		restore();
	}
	
	private function undo(){
		
		if (undoBuffer == null || undoBuffer.length == 0) {
			return;
		}
		
		if (undoPointer == -1){
			undoPointer = undoBuffer.length - 1;
			undoBuffer.push(tempState);
		}
		else {
			undoPointer--;
			if (undoPointer <= 0)
			{ 
				undoPointer = 0;
			}
		}
		
		restore();
	}
	
	private function restore(){
		
		if (undoPointer == -1) return;
		
		var state = undoBuffer[undoPointer];
		
		if (state == null) return;
		if (state.layers == null) return;
		if (state.sigils == null) return;
		
		var zpt = new Point();
		for (i in 0...layers.length){
			layers[i].sprite.graphic.bitmap.copyPixels(state.layers[i], state.layers[i].rect, zpt);
		}
		for (i in 0...layers[0].sigils.length){
			layers[0].forceSigil(i, state.sigils[i].x, state.sigils[i].y);
		}
	}
	
	private function killRedos(){
		if (undoPointer != -1){
			while (undoBuffer.length - 1 > undoPointer){
				var state = undoBuffer.pop();
				state.destroy();
			}
		}
	}
	
	private function pushUndo(state:EditState){
		
		killRedos();
		
		if (undoBuffer.length >= maxUndo){
			var state = undoBuffer.shift();
			state.destroy();
		}
		
		undoBuffer.push(state);
		undoPointer = -1;
	}
	
	private function composite(){
		var canvas = layers[0];
		var bmp = canvas.sprite.graphic.bitmap;
		
		bmp.fillRect(bmp.rect, FlxColor.BLACK);
		
		var zpt = new Point();
		
		for (i in 1...layers.length){
			var layer = layers[i];
			var lbmp = layer.sprite.graphic.bitmap;
			bmp.copyPixels(lbmp, lbmp.rect, zpt, null, null, true);
			switch(layer.value){
				case "legal","illegal":
					for (sigil in layers[0].sigils){
						if (sigil.x != -1 && sigil.y != -1){
							bmp.setPixel32(sigil.x, sigil.y, FlxColor.BLACK);
						}
					}
			}
		}
	}
	
	private function load(settings:Settings){
		
		data = settings;
		undoBuffer = [];
		
		layers = [];
		makeLayer(0xFF000000,  0, "composite", false);
		makeLayer(0xFFFFFFFF,  1, "legal");
		makeLayer(0xFFFF0000,  2, "illegal");
		makeLayer(0xFF0000FF,  3, "water");
		
		layers[0].hasSigils = true;
		
		sigilSprite = new FlxSprite();
		sigilSprite.loadGraphic("assets/images/sigils.png", true, 48, 48);
		add(sigilSprite);
		
		hintText = new FlxText(0, 0, layers[0].sprite.width, "Testing");
		hintText.alignment = FlxTextAlign.CENTER;
		hintText.text = "Testing";
		hintText.font = "assets/fonts/verdana.ttf";
		hintText.size = 14;
		hintText.color = FlxColor.BLACK;
		hintText.x = FlxG.width - (hintText.width + 5);
		hintText.y = FlxG.height - hintText.height * 2;
		add(hintText);
		
		sigilSprite.x = Std.int(hintText.x + (hintText.width - sigilSprite.width) / 2);
		sigilSprite.y = hintText.y - sigilSprite.height - 5;
		
		doSigil(1);
		
		sigilSprite.visible = false;
		hintText.visible = false;
		
		tempState = new EditState(layers);
		
		layers[0].onSigilPlace(START_I-1, 0, Std.int(layers[0].height / 2));
		layers[0].onSigilPlace(END_I - 1, layers[0].width - 1, Std.int(layers[0].height / 2));
		
		for (i in 0...layers.length){
			layers[i].button.onOver.callback = function(){
				showLayer(i, true);
			}
			layers[i].button.onOut.callback = function(){
				showLayer(i, false);
			}
		}
		
		composite();
		
		var button = new FlxUIButton(0, 0, "Export", onExport);
		button.label.font = "assets/fonts/verdana.ttf";
		button.label.size = 14;
		button.label.color = FlxColor.BLACK;
		button.resize(100, 32);
		button.x = FlxG.width - button.width - 5;
		button.y = 5;
		add(button);
		
		waves = [];
		waveWidgets = [];
		waves.push(getWave());
		refreshWaves();
	}
	
	private function getWave():WaveInfo{
		return
		{
			type:"normal",
			count:1,
			wait:1.0,
			level:1,
			rate:1.0,
			starts:[true,false,false,false,false],
			ends:[true,false,false,false,false]
		};
	}
	
	private function refreshWaves()
	{
		if (waveList == null){
			waveList = new FlxUIList(WAVE_X, WAVE_Y, null, WaveWidget.W, WaveWidget.H * 6);
			add(waveList);
		}
		
		while (waveWidgets.length < waves.length){
			var widget = new WaveWidget();
			waveWidgets.push(widget);
			waveList.add(widget);
		}
		while (waveWidgets.length > waves.length){
			var widget = waveWidgets.pop();
			waveList.remove(widget, true);
			widget.destroy();
		}
		
		var l = waveList.members.length;
		for (i in 0...l){
			if (Std.is(waveList.members[0], WaveWidget)){
				waveList.remove(waveList.members[0], true);
			}
		}
		
		var X = 0;
		var Y = 0;
		for (i in 0...waves.length){
			waveWidgets[i].ID = i;
			waveWidgets[i].empty = false;
			waveWidgets[i].sync(waves[i]);
			waveList.add(waveWidgets[i]);
		}
		
		var lastWave = new WaveWidget();
		lastWave.ID = waveWidgets.length - 1;
		lastWave.empty = true;
		waveList.add(lastWave);
	}
	
	private function onExport(){
		
		promptPath();
	}
	
	private function exportData(path:String){
		if (FileSystem.isDirectory(path)){
			SFX.play("clang");
			return;
		}
		
		var W = Std.int(layers[0].sprite.graphic.bitmap.width);
		var H = Std.int(layers[0].sprite.graphic.bitmap.height);
		
		var img:BitmapData = new BitmapData(Std.int(W*layers.length+1), H, true, 0xFF000000);
		
		var pt = new Point();
		
		var bmp = layers[0].sprite.graphic.bitmap;
		img.copyPixels(bmp, bmp.rect, pt, null, null, true);
		
		//skip the composite image, leave one entire field blank for "path" layer
		pt.x += W * 2;
		
		path = stripExtension(path);
		
		for (i in 1...layers.length){
			var bmp = layers[i].sprite.graphic.bitmap;
			img.copyPixels(bmp, bmp.rect, pt, null, null, true);
			pt.x += bmp.width;
		}
		
		var bytes = img.encode(img.rect, new PNGEncoderOptions());
		
		File.saveBytes(path + ".png", bytes);
		File.saveContent(path + ".xml", getXMLString());
	}
	
	private function tab(i:Int):String
	{
		var tab = "    ";
		var str = "";
		for (j in 0...i){
			str += tab;
		}
		return tab;
	}
	
	private function getXMLString():String{
		
		var save_xml:Xml = Xml.parse("<data></data>");
		save_xml = save_xml.firstElement();
		
		var fast:Fast= new Fast(save_xml);
		
		var tileStr = tab(1)+'<tiles>';
		for (i in 0...layers.length){
			var color:FlxColor = layers[i].color;
			var value = switch(layers[i].value){
				case "legal": "grass";
				case "illegal": "dark_cliff";
				case "water": "water";
				default: layers[i].value;
			}
			if (i == 0){
				tileStr += '<tile rgb="0x000000" tile_sheet="single" value="grey_dirt" layer="0"/>';
			}
			else {
				tileStr += '<tile rgb="' + color.toHexString(false, true) + '" value="$value" layer="$i"/>';
			}
		}
		var ids = ["a", "b", "c", "d", "e"];
		for (i in 0...10){
			var sigil = layers[0].sigils[i];
			if (sigil.x != -1 && sigil.y != -1){
				var id = "";
				var nodeName = "";
				if (i < END_I - 1){
					id = ids[i];
					nodeName = "start";
				}
				else {
					id = ids[i - (END_I - 1)];
					nodeName = "end";
				}
				var X = sigil.x;
				var Y = sigil.y;
				tileStr += '<$nodeName id="$id" x="$X" y="$Y"/>';
			}
		}
		tileStr += '</tiles>';
		
		var waveStr = '<waves first_wait="1" diff="easy">';
		for (wave in waves){
			var locStr = "";
			var endStr = "";
			for (i in 0...wave.starts.length){
				if (wave.starts[i]){
					if (locStr != ""){
						locStr += ",";
					}
					locStr += ids[i];
				}
			}
			for (i in 0...wave.ends.length){
				if (wave.ends[i]){
					if (endStr != ""){
						endStr += ",";
					}
					endStr += ids[i];
				}
			}
			//TODO: add ally injection here
			var endValue = endStr != "" ? "" : "";
			var wc = wave.count;
			var ww = wave.wait;
			var wt = wave.type;
			var wl = wave.level;
			var wr = wave.rate;
			waveStr += '<wave count="$wc" wait="$ww" type="$wt" level="$wl" rate="$wr" loc="$locStr" $endValue/>';
		}
		waveStr += '</waves>';
		
		save_xml.addChild(xmlify('<title id="" value=""/>'));
		save_xml.addChild(xmlify('<music value="battle"/>'));
		save_xml.addChild(xmlify('<victory><condition value="kill_all"/></victory>'));
		save_xml.addChild(xmlify('<failure/>'));
		save_xml.addChild(xmlify(tileStr));
		save_xml.addChild(xmlify(waveStr));
		
		var outputstr = Printer.print(save_xml,true);
		
		var outputstr = '<?xml version="1.0" encoding="utf-8" ?>\n' + outputstr;
		return outputstr;
	}
	
	private function xmlify(str:String){
		return Xml.parse(str).firstElement();
	}
	
	private function stripExtension(path:String):String
	{
		if (Unifill.uIndexOf(path, ".") == -1) return path;
		
		var arr = Unifill.uSplit(path, ".");
		var sb:StringBuf = new StringBuf();
		for (i in 0...arr.length){
			if (i == arr.length - 1) continue;
			sb.add(arr[i]);
			if (i != arr.length - 2){
				sb.add(".");
			}
		}
		return sb.toString();
	}
	
	private function promptPath(){
		#if sys
			var openFileDialog = new FileDialog();
			/*openFileDialog.onCancel.add(function(){
				
			});*/
			openFileDialog.onSelect.add(onSelectPath);
			
			try
			{
				openFileDialog.browse(FileDialogType.SAVE,"");
			}
			catch (e:Dynamic)
			{
				trace("error : " + e);
			}
		#end
	}
	
	private function onSelectPath(value:String){
		var path = Std.string(value);
		
		exportData(path);
		
	}
	
	private function showLayer(i:Int, b:Bool)
	{
		if (i > 0)
		{
			if(b){
				hintText.text = layers[i].value;
				hintText.visible = true;
				sigilSprite.visible = false;
				hintText.x = Std.int(layers[i].sprite.x + (layers[i].sprite.width - hintText.width)/2);
				hintText.y = layers[i].sprite.y + layers[i].sprite.height + 5;
			}
			else{
				if(hintText.text == layers[i].value){
					hintText.visible = false;
				}
			}
		}
		else{
			if (b){
				sigilSprite.visible = true;
				hintText.visible = true;
				hintText.text = sigilHint;
				hintText.x = Std.int(layers[i].sprite.x + (layers[i].sprite.width - hintText.width)/2);
				hintText.y = layers[i].sprite.y + layers[i].sprite.height + 5;
			}
			else{
				if (hintText.text == sigilHint){
					sigilSprite.visible = false;
					hintText.visible = false;
				}
			}
		}
		
		sigilSprite.x = Std.int(hintText.x + (hintText.width - sigilSprite.width) / 2);
		sigilSprite.y = hintText.y + hintText.height;
	}
	
	private function makeLayer(color:FlxColor, layer:Int, value:String, editable:Bool=true)
	{
		var l = new MapLayer(data.squaresWide, data.squaresTall, color, layer, value, editable);
		layers.push(l);
		
		l.x = Std.int(LAYER_X + (l.sprite.width + 5) * layer);
		l.y = LAYER_Y;
		
		l.addTo(this);
	}
	
	private function makeSettings(){
		dq1 = new Settings();
		dq2 = new Settings();
		
		dq1.tilesetStyle = "dq1";
		dq1.tilesPerSquare = 2;
		dq1.squaresWide = 15;
		dq1.squaresTall = 14;
		
		dq2.tilesetStyle = "dq2";
		dq2.tilesPerSquare = 1;
		dq2.squaresWide = 23;
		dq2.squaresTall = 15;
	}
	
	private function makeBkg(){
		var bkg = new FlxSprite().makeGraphic(1, 1, FlxColor.WHITE);
		bkg.scale.set(FlxG.width, FlxG.height);
		bkg.updateHitbox();
		add(bkg);
	}
}

@:enum abstract Tool(Int){
	
	public var Pencil = 0;
	public var Eraser = 1;
	public var Bucket = 2;
	public var Turpentine = 3;
}