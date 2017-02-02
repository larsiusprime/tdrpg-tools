package;

#if tdrpg_haxe
import com.leveluplabs.tdrpg.BattleFieldUtility;
import com.leveluplabs.tdrpg.IndexData;
import com.leveluplabs.tdrpg.enums.TerrainType;
#end
import flash.display.BitmapData;
import flash.geom.Point;
import flash.geom.Rectangle;
import flash.net.FileFilter;
import flash.net.FileReference;
import flixel.FlxG;
import flixel.FlxSprite;
import flixel.FlxState;
import flixel.addons.ui.FlxUI;
import flixel.addons.ui.FlxUIButton;
import flixel.addons.ui.FlxUIList;
import flixel.addons.ui.FlxUINumericStepper;
import flixel.addons.ui.FlxUIPopup;
import flixel.addons.ui.FlxUIState;
import flixel.addons.ui.FlxUIText;
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
import openfl.Assets.AssetType;
import openfl.utils.ByteArray;
import sys.FileSystem;
import sys.io.File;
import unifill.Unifill;
import WaveWidget.WaveInfo;
import DataFetcher.DataFetchCode;
import MetaWidget.MetaInfo;
import MetaWidget.MetaEntry;

class MenuState extends FlxUIState
{
	public static var dq1:Settings;
	public static var dq2:Settings;
	
	private static inline var LAYER_X:Int = 60;
	private static inline var LAYER_Y:Int = 50;
	private static inline var LAYER_W:Int = 930;
	
	private static inline var WAVE_X:Int = 550;
	private static inline var WAVE_Y:Int = 240;
	
	public var sigil:Int = 0;
	public var tool:Tool = Tool.Pencil;
	public var toolFlows:Bool = true;
	
	public static inline var START_I:Int = 1;
	public static inline var END_I:Int = 6;
	
	override public function create():Void
	{
		super.create();
		saveData = new SaveData();
		dataFetcher = new DataFetcher(saveData);
		
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
			case "move_map_layer":
				var i:Int = cast data;
				
				trace("move map layer " + i);
				var layer:MapLayer = cast sender;
				onMoveLayer(layer, i);
			case "change_map_layer":
				var i:Int = cast data;
				var layer = layers[i];
				onChangeLayer(layer);
			case "delete_map_layer":
				var i:Int = cast data;
				var layer = layers.splice(i, 1);
				trace("splice i = " + i);
				if(layer != null && layer.length > 0){
					layer[0].destroy();
				}
				refreshLayers();
				composite();
			case "delete_wave":
				var i:Int = cast data;
				waves[diffI()].splice(i,1);
				refreshWaves();
			case "add_wave":
				waves[diffI()].push(getWave());
				refreshWaves();
			case "wave_change":
				refreshWaves();
			case FlxUINumericStepper.CHANGE_EVENT, "sigil_change":
				if (params != null && params.indexOf("wave_widget") != -1){
					var widget = cast(sender, IFlxUIWidget);
					resolveWidgetChange(widget, params);
				}
			case FlxUIPopup.CLICK_EVENT:
				if (params != null && params.indexOf("setPath") != -1){
					onSetPath();
				}
			case "select_type":
				var waveWidget:WaveWidget = cast sender;
				var types = dataFetcher.getEnemyTypes();
				if (types == null){
					alert("No game data!", "The Level editor doesn't know what enemy types exist.\n\nYou must set a path to :\n\n  - a mod's root directory\n  - the 'asset' folder in the game's install directory\n  - the 'asset' folder in the game's source code directory\n\nTo do this, select the 'Set Path' button and select one of these.\n\nNOTE: If you select a mod path, you will afterwards need to supply one of the other two.");
				}
				else
				{
					var popup = new TypePopup(types, waveWidget.info.type,
							function(str:String,category:String){
								waveWidget.setType(str);
							}
						);
					openSubState(popup);
				}
			case "preview_available":
				var value:Bool = cast data;
				previewAvailable = value;
				updatePreview();
		}
	}
	
	//PRIVATE
	
	private var addLayerBtn:FlxUIButton;
	
	private var previewAvailable:Bool = false;
	private var preview:MapPreview;
	
	private var pathTxt:FlxUIText;
	private var setpath:FlxUIButton;
	private var clearpath:FlxUIButton;
	private var export:FlxUIButton;
	private var save:FlxUIButton;
	
	private var saveData:SaveData;
	private var dataFetcher:DataFetcher;
	private var lastSavePath:String = "";
	
	private var waves:Array<Array<WaveInfo>>;
	private var waveWidgets:Array<WaveWidget>;
	private var waveList:FlxUIList;
	
	private var layers:Array<MapLayer>;
	private var layerList:FlxUIList;
	
	private var meta:MetaEntry;
	private var metaWidget:MetaWidget;
	
	private var hintText:FlxText;
	private var sigilSprite:FlxSprite;
	private var sigilHint:String;
	private var data:Settings;
	private var maxUndo:Int = 100;
	private var undoPointer:Int = -1;
	private var undoBuffer:Array<EditState>;
	private var tempState:EditState;
	
	
	private function resolveWidgetChange(widget:IFlxUIWidget, params:Array<Dynamic>){
		
		var i:Int = 0;
		for (waveWidget in waveWidgets){
			if (waveWidget.owns(widget)){
				waveWidget.write(waves[diffI()][i]);
			}
			i++;
		}
		if (metaWidget.owns(widget)){
			metaWidget.write(meta);
		}
	}
	
	private function diffI():Int{
		return diffToI(meta.difficulty);
	}
	
	private function diffToI(str:String){
		return switch(str){
			case "easy": 0;
			case "normal": 1;
			case "hard": 2;
			default: 0;
		}
		return 0;
	}
	
	private function updateInput(elapsed:Float){
		
		for (i in 0...layers.length){
			var layer = layers[i];
			layer.update(elapsed);
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
	
	private function updatePreview()
	{
		if (previewAvailable)
		{
			#if tdrpg_haxe
			setBattleFieldUtilityCallbacks();
			#end
			
			preview.updatePreview(true, getMapBitmap(), getMapXML());
		}
		else{
			preview.updatePreview(false);
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
		
		if(change){
			composite();
		}
		
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
			if(layer.art == ""){
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
		
		if (preview != null)
		{
			updatePreview();
		}
	}
	
	private function load(settings:Settings){
		
		data = settings;
		undoBuffer = [];
		
		layers = [];
		makeLayer(0xFF000000,  0, "grey_dirt", false, "");
		makeMapLayerFromTileset("grass", 1, "");
		makeMapLayerFromTileset("dark_cliff", 2, "");
		makeMapLayerFromTileset("water", 3, "");
		
		layers[0].hasSigils = true;
		
		refreshLayers();
		
		sigilSprite = new FlxSprite();
		sigilSprite.loadGraphic("*assets/images/sigils.png", true, 48, 48);
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
		
		layers[0].onSigilPlace(START_I-1, 0, Std.int(layers[0].squareHeight / 2));
		layers[0].onSigilPlace(END_I - 1, Std.int(layers[0].squareWidth - 1), Std.int(layers[0].squareHeight / 2));
		
		composite();
		
		var previewParams = {
			X:Std.int(layers[0].x+10),
			Y:Std.int(WAVE_Y+45),
			name:"",
			diff:"easy",
			tileHeight:14,
			widthInSquares:settings.squaresWide,
			heightInSquares:settings.squaresTall,
			tilesetStyle:settings.tilesetStyle,
			tilesPerSquare:settings.tilesPerSquare,
			png:getMapBitmap(),
			xml:getMapXML(),
			levelEdit:true
		}
		
		preview = new MapPreview(previewParams);
		add(preview);
		
		export = addBtn(0, 5, "Save As", onExport);
		export.x = FlxG.width - export.width - 5;
		
		save      = addBtn(export.x, export.y + export.height + 5, "Save", onSave);
		setpath   = addBtn(export.x, save.y + save.height + 5, "Set Path", onSetPath);
		clearpath = addBtn(export.x, setpath.y + setpath.height + 5, "Clear Paths", onClearPaths);
		
		pathTxt = new FlxUIText(0, 0, FlxG.width - (setpath.width+5), dataFetcher.getPathText(), 12);
		pathTxt.font = "assets/fonts/verdana.ttf";
		pathTxt.color = FlxColor.BLACK;
		pathTxt.x = setpath.x - pathTxt.width;
		pathTxt.y = 0;
		pathTxt.alignment = FlxTextAlign.LEFT;
		add(pathTxt);
		
		tooltips.add(setpath, {title:"No path set",body:""});
		
		meta = {
			difficulty:"easy",
			infos:[getMeta("easy"), getMeta("normal"), getMeta("hard")]
		};
		metaWidget = new MetaWidget(WAVE_X, WAVE_Y);
		add(metaWidget);
		metaWidget.sync(meta);
		
		waves = [[],[],[]];
		waveWidgets = [];
		waves[0].push(getWave());
		waves[1].push(getWave());
		waves[2].push(getWave());
		refreshWaves();
		
		refreshSavePath();
		refreshPreview();
	}
	
	private function getMeta(diff:String):MetaInfo{
		return {
			difficulty:diff,
			firstWait:1.0,
			endlessLevelup:1,
			isEndless:false,
			isBonus:false
		}
	}
	
	private function addBtn(X:Float, Y:Float, label:String, callback:Void->Void):FlxUIButton{
		var btn = Util.makeBtn(Std.int(X), Std.int(Y), label, callback);
		add(btn);
		return btn;
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
	
	private function onMoveLayer(layer:MapLayer, i:Int){
		
		if (layer == null) return;
		
		var a = layer.layer;
		var b = layer.layer + i;
		
		if (b > 0 && b < layer.length){
			var layerB = layers[b];
			layers[b] = layer;
			layers[a] = layerB;
			refreshLayers();
			composite();
		}
	}
	
	private function onChangeLayer(layer:MapLayer){
		
		var arr = null;
		
		if (layer.layer == 0){
			arr = getTileTypes(false, false, false, true, false);
		}
		else{
			arr = getTileTypes(true, true, true, false, true);
		}
		
		var popup = new TypePopup(arr, "",
			function(str:String, category:String = ""){
				trace("str = " + str + " category = " + category);
				if (category == "art"){
					layer.art = str;
				}
				else{
					layer.art = "";
					layer.drawColor = dataFetcher.getTileColor(str);
					layer.value = str;
				}
				refreshLayers();
				composite();
			}
		);
		
		openSubState(popup);
	}
	
	private function getTileTypes(legal:Bool,illegal:Bool,water:Bool,single:Bool,art:Bool):Array<String>
	{
		var arr:Array<String> = [];
		if(legal){
			arr.push("legal:");
			for (str in dataFetcher.legalTerrain){
				arr.push(str);
			}
		}
		if(illegal){
			arr.push("illegal:");
			for (str in dataFetcher.illegalTerrain){
				arr.push(str);
			}
		}
		if(water){
			arr.push("water:");
			for (str in dataFetcher.waterTerrain){
				arr.push(str);
			}
		}
		if (single){
			arr.push("single:");
			for (str in dataFetcher.singleTerrain){
				arr.push(str);
			}
		}
		if (art){
			arr.push("art:");
			for (str in dataFetcher.arts){
				arr.push(str);
			}
		}
		return arr;
	}
	
	private function onAddLayer(){
		
		var arr = getTileTypes(true, true, true, false, true);
		
		var popup = new TypePopup(arr, "",
			function(str:String, category:String){
				makeMapLayerFromTileset(str, layers.length, category);
				refreshLayers();
			}
		);
		
		openSubState(popup);
		
		refreshLayers();
	}
	
	private function refreshLayers(){
		
		var scrollIndex = 0;
		if (layerList != null){
			scrollIndex = layerList.scrollIndex;
			var l = layerList.members.length;
			for (i in 0...l){
				var j = l - i - 1;
				layerList.remove(layerList.members[j],true);
			}
			remove(layerList, true);
			layerList.destroy();
		}
		
		if (addLayerBtn == null){
			addLayerBtn = Util.makeBtn(LAYER_X + LAYER_W + 5, LAYER_Y, "+", onAddLayer, 32, 32);
			add(addLayerBtn);
		}
		
		var widgets:Array<IFlxUIWidget> = [];
		var l = layers.length;
		for (i in 0...l){
			layers[i].layer = i;
			widgets.push(layers[i]);
			layers[i].isLast = (i == (l - 1));
		}
		
		layerList = new FlxUIList(LAYER_X, LAYER_Y, widgets, LAYER_W, layers[0].back.height, "<X> more...", FlxUIList.STACK_HORIZONTAL, 5);
		add(layerList);
		
		layerList.scrollIndex = scrollIndex;
		
		var lastLayer = layers[0];
		
		for (i in 0...layers.length){
			if (layers[i].visible){
				lastLayer = layers[i];
			}
		}
		
		if(lastLayer != null){
			addLayerBtn.x = Std.int(lastLayer.x + lastLayer.width + 5);
			addLayerBtn.y = Std.int(lastLayer.y + (lastLayer.height - addLayerBtn.height) / 2);
		}
	}
	
	private function refreshWaves()
	{
		if (waveList == null){
			waveList = new FlxUIList(WAVE_X, WAVE_Y+metaWidget.height+20, null, WaveWidget.W, WaveWidget.H * 5);
			add(waveList);
		}
		
		var ws = waves[diffI()];
		
		while (waveWidgets.length < ws.length){
			var widget = new WaveWidget();
			waveWidgets.push(widget);
			waveList.add(widget);
		}
		while (waveWidgets.length > ws.length){
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
		for (i in 0...ws.length){
			waveWidgets[i].ID = i;
			waveWidgets[i].empty = false;
			waveWidgets[i].sync(ws[i]);
			waveList.add(waveWidgets[i]);
		}
		
		var lastWave = new WaveWidget();
		lastWave.ID = waveWidgets.length - 1;
		lastWave.empty = true;
		waveList.add(lastWave);
	}
	
	private function onSave(){
		if (lastSavePath != ""){
			exportData(lastSavePath);
		}
	}
	
	private function onClearPaths(){
		dataFetcher.clearPaths();
		saveData.clear();
		pathTxt.text = dataFetcher.getPathText();
		refreshPreview();
	}
	
	private function onSetPath(){
		promptPath(setDataPath, FileDialogType.OPEN_DIRECTORY);
	}
	
	private function refreshSavePath(){
		save.update(0);
		if (lastSavePath != ""){
			save.active = true;
			save.alpha = 1.0;
		}
		else{
			save.active = false;
			save.alpha = 0.25;
		}
		refreshPreview();
	}
	
	private function refreshPreview(){
		if (dataFetcher.fetchCode == OK){
			previewAvailable = true;
		}else{
			previewAvailable = false;
		}
		updatePreview();
	}
	
	private function setDataPath(path:String){
		var title = "";
		var body = "";
		var tt = "No path set";
		
		dataFetcher.setPath(path);
		
		switch(dataFetcher.fetchCode){
			case DataFetchCode.OK:
				//FlxUI
			case DataFetchCode.HAS_DEV_NEED_MORE:
				title = "Base path required";
				body = dataFetcher.error;
				alert(title, body, "setPath");
			case DataFetchCode.HAS_MOD_NEED_BASE:
				title = "Base path required";
				body = dataFetcher.error;
				alert(title, body, "setPath");
			case DataFetchCode.HAS_NOTHING:
				title = "Error!";
				body = dataFetcher.error;
				tt = "No path set";
				alert(title, body);
				tooltips.add(setpath, {
					title:tt,
					body:"",
					style:{
						titleWidth:200,
						bodyWidth:200
					}
				});
			case DataFetchCode.NEEDS_ASSETS:
				title = "Error!";
				body = dataFetcher.error;
				tt = "No path set";
				alert(title, body);
				tooltips.add(setpath, {
					title:tt,
					body:"",
					style:{
						titleWidth:200,
						bodyWidth:200
					}
				});
		}
		
		pathTxt.text = dataFetcher.getPathText();
		
		dataFetcher.sync(saveData);
		saveData.save();
		
		refreshPreview();
		composite();
	}
	
	private function onExport()
	{
		promptPath(exportData);
	}
	
	private var _mapBmp:BitmapData = null;
	private function getMapBitmap():BitmapData{
		var W = Std.int(layers[0].sprite.graphic.bitmap.width);
		var H = Std.int(layers[0].sprite.graphic.bitmap.height);
		
		var pw = Std.int(W * (layers.length + 1));
		var ph = H;
		
		if (_mapBmp != null){
			if (pw != _mapBmp.width || ph != _mapBmp.height){
				_mapBmp.dispose();
				_mapBmp = null;
			}
		}
		
		if (_mapBmp == null){
			_mapBmp = new BitmapData(pw, ph, true, 0xFF000000);
		}
		else{
			_mapBmp.fillRect(_mapBmp.rect, 0xFF000000);
		}
		
		var img = _mapBmp;
		
		var pt = new Point();
		
		var bmp = layers[0].sprite.graphic.bitmap;
		img.copyPixels(bmp, bmp.rect, pt, null, null, true);
		
		//skip the composite image, leave one entire field blank for "path" layer
		pt.x += W * 2;
		
		for (i in 1...layers.length){
			if(layers[i].art == ""){
				var bmp = layers[i].sprite.graphic.bitmap;
				img.copyPixels(bmp, bmp.rect, pt, null, null, true);
				pt.x += bmp.width;
			}
		}
		
		return img;
	}
	
	private function exportData(path:String){
		lastSavePath = "";
		
		if (FileSystem.isDirectory(path)){
			SFX.play("clang");
			return;
		}
		
		lastSavePath = path;
		
		var img = getMapBitmap();
		var bytes = img.encode(img.rect, new PNGEncoderOptions());
		
		path = Util.stripExtension(path);
		
		File.saveBytes(path + ".png", bytes);
		File.saveContent(path + ".xml", getXMLString());
		
		refreshSavePath();
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
	
	private function getMapXML():Fast
	{
		return new Fast(Util.xmlify(getXMLString()));
	}
	
	private function getXMLString():String{
		
		var save_xml:Xml = Xml.parse("<data></data>");
		save_xml = save_xml.firstElement();
		
		var fast:Fast= new Fast(save_xml);
		
		var tileStr = '<tiles>';
		
		var layerIndex = 0;
		var artLayerIndex = 0;
		
		var hasArt = false;
		var artStr = '<artlayers>';
		
		for (i in 0...layers.length){
			
			if (layers[i].art == "")
			{
				var color:FlxColor = layers[i].drawColor;
				var value = switch(layers[i].value){
					case "legal": "grass";
					case "illegal": "dark_cliff";
					case "water": "water";
					default: layers[i].value;
				}
				if (i == 0){
					tileStr += '<tile rgb="0x000000" tile_sheet="single" value="$value" layer="0"/>';
				}
				else {
					tileStr += '<tile rgb="' + color.toHexString(false, true) + '" value="$value" layer="$layerIndex"/>';
				}
				layerIndex++;
			}
			else
			{
				var art = layers[i].art;
				var artx = layers[i].artX;
				var arty = layers[i].artY;
				artLayerIndex = layerIndex - 1;
				artStr += '<artlayer id="$art" x="$artx" y="$arty" layer="$artLayerIndex"/>';
				hasArt = true;
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
		artStr += '</artlayers>';
		
		var waveArr:Array<String> = [];
		var waveStr = "";
		
		var i = 0;
		
		if(waves != null){
			for (ws in waves){
				
				var wdiff = switch(i){
					case 0:"easy";
					case 1:"normal";
					case 2:"hard";
					default:"easy";
				}
				
				if (meta.infos[i].isBonus && wdiff != "easy"){
					continue;
				}
				
				var wfirstwait = meta.infos[i].firstWait;
				waveStr = '<waves first_wait="$wfirstwait" diff="$wdiff">';
				
				for (wave in ws){
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
				waveArr.push(waveStr);
				
				i++;
			}
		}
		
		save_xml.addChild(Util.xmlify('<title id="" value=""/>'));
		save_xml.addChild(Util.xmlify('<music value="battle"/>'));
		save_xml.addChild(Util.xmlify('<victory><condition value="kill_all"/></victory>'));
		save_xml.addChild(Util.xmlify('<failure/>'));
		save_xml.addChild(Util.xmlify(tileStr));
		if (hasArt){
			save_xml.addChild(Util.xmlify(artStr));
		}
		
		for(waveStr in waveArr){
			save_xml.addChild(Util.xmlify(waveStr));
		}
		
		var outputstr = Printer.print(save_xml,true);
		
		var outputstr = '<?xml version="1.0" encoding="utf-8" ?>\n' + outputstr;
		return outputstr;
	}
	
	private function alert(title:String, message:String, closeParam:String=""){
		var popup = new Popup(title,message,closeParam);
		openSubState(popup);
	}
	
	private function promptPath(callback:String->Void, type:FileDialogType = null){
		#if sys
			if (type == null){
				type = FileDialogType.SAVE;
			}
			var openFileDialog = new FileDialog();
			openFileDialog.onSelect.add(callback);
			
			try
			{
				openFileDialog.browse(type,"");
			}
			catch (e:Dynamic)
			{
				trace("error : " + e);
			}
		#end
	}
	
	private function showLayer(i:Int, b:Bool)
	{
		if (i > 0)
		{
			if(i < layers.length){
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
	
	private function makeMapLayerFromTileset(tileset:String, layer:Int, category:String)
	{
		if (tileset == "legal" || tileset == "illegal" || tileset == "water"){
			var tilesets = [];
			for (ml in layers){
				tilesets.push(ml.value);
			}
			tileset = dataFetcher.getNextTileset(tileset,tilesets);
		}
		
		if (category == "art"){
			var color = FlxColor.WHITE;
			makeLayer(color, layer, tileset, true, "art");
		}
		else{
			var color = dataFetcher.getTileColor(tileset);
			makeLayer(color, layer, tileset);
		}
	}
	
	private function makeLayer(color:FlxColor, layer:Int, value:String, editable:Bool=true, category:String="")
	{
		var tileset = value;
		if (category == "art"){
			tileset = "grass";
			color = dataFetcher.getTileColor("grass");
		}
		
		var l = new MapLayer(0, 0, data.squaresWide, data.squaresTall, color, layer, tileset, editable);
		if(category == "art"){
			l.art = value;
		}
		
		var heightInPixels = data.tilesPerSquare * data.tilePixelsTall * data.squaresTall;
		
		l.effectiveScale = l.back.height / heightInPixels;
		
		l.button.onOver.callback = function(){
			showLayer(l.layer, true);
		}
		l.button.onOut.callback = function(){
			showLayer(l.layer, false);
		}
		
		layers.push(l);
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
	
	/*********comaptibiliy callbacks************/
	
	#if tdrpg_haxe
	private function hasIndex():Bool{
		return dataFetcher != null && dataFetcher.index != null;
		return false;
	}
	
	private function hasGraphics():Bool{
		return dataFetcher != null && dataFetcher.graphics != null;
		return false;
	}
	
	private function isTileLegal(str:String):Bool
	{
		if (hasIndex()) return dataFetcher.index.isTileLegal(str);
		return false;
	}
	
	private function getTileType(tileId:String, defaultType:TerrainType = TerrainType.WALL):String
	{
		if (hasIndex()) return dataFetcher.index.getTileType(tileId, defaultType);
		return TerrainType.WALL;
	}
	
	private function getListClasses():Array<String>
	{
		return ["mcguffin"];
	}
	
	private function checkClassPlusDisabled(str:String):Bool
	{
		return false;
	}
	
	private function getCharacter(class_str:String, ?handle:String, ?index:Int)
	{
		#if tdrpg_haxe
		return null;
		#else
		return null;
		#end
	}
	
	private function isSpriteModeHD():Bool{
		return true;
	}
	
	private function getGraphicsHeight(str:String):Int{
		if (hasGraphics()) return dataFetcher.graphics.getHeight(str);
		if (str == "tile") return 20;
		if (str == "tile_hd") return 40;
		return 0;
	}
	
	private function getBitmapData(str:String):BitmapData{
		return dataFetcher.getBitmapData(str);
	}
	
	private function assetExists(str:String, type:AssetType):Bool{
		return dataFetcher.assetExists(str, type);
	}
	
	private function setBattleFieldUtilityCallbacks(){
		BattleFieldUtility.setCallbacks(
			isTileLegal,
			getTileType,
			getListClasses,
			checkClassPlusDisabled,
			getCharacter,
			isSpriteModeHD,
			getGraphicsHeight,
			getBitmapData,
			assetExists
		);
	}
	#end
}

@:enum abstract Tool(Int){
	
	public var Pencil = 0;
	public var Eraser = 1;
	public var Bucket = 2;
	public var Turpentine = 3;
}