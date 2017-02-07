package;

#if tdrpg_haxe
import com.leveluplabs.tdrpg.BattleFieldUtility;
import com.leveluplabs.tdrpg.IndexData;
import com.leveluplabs.tdrpg.enums.TerrainType;
#end
import com.leveluplabs.tdrpg.BonusData;
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
import org.zamedev.lib.Utf8Ext;
import sys.FileSystem;
import sys.io.File;
import unifill.Unifill;
import WaveWidget.WaveInfo;
import BattleData.WaveData;
import DataFetcher.DataFetchCode;
import MetaWidget.MetaInfo;
import MetaWidget.MetaEntry;
import RewardsPicker.RewardStruct;
import BattleData.BonusStruct;

class LevelEditState extends FlxUIState
{
	public static var dq1:Settings;
	public static var dq2:Settings;
	
	private static inline var LAYER_X:Int = 60;
	private static inline var LAYER_Y:Int = 30;
	private static inline var LAYER_W:Int = 930;
	
	private static inline var WAVE_X:Int = 550;
	private static inline var WAVE_Y:Int = 225;
	
	public var tool:Tool = Tool.Pencil;
	
	public var dirty(default, set):Bool = false;
	
	public static inline var START_I:Int = 1;
	public static inline var END_I:Int = 6;
	
	public function new(saveData_:SaveData)
	{
		saveData = saveData_;
		super();
	}
	
	override public function create():Void
	{
		super.create();
		dataFetcher = Util.dataFetcher;
		
		var mapsDir = Util.safePath(saveData.modPath, "maps");
		if (FileSystem.exists(mapsDir) == false){
			FileSystem.createDirectory(mapsDir);
		}
		lastSavePath = Util.safePath(mapsDir, saveData.mapID + ".xml");
		
		FlxG.sound.muted = false;
		makeBkg();
		
		dq1 = Util.dq1;
		dq2 = Util.dq2;
		
		load(dq1);
		
		dirty = false;
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
		
		super.update(elapsed);
		updateInput(elapsed);
	}
	
	override public function getRequest(id:String, sender:Dynamic, data:Dynamic, ?params:Array<Dynamic>):Dynamic 
	{
		//super.getRequest(id, sender, data, params);
		switch(id){
			case "items":
				var code:String = cast data;
				var items = dataFetcher.getItems(code);
				//var items = {names:["a", "b", "c"], labels:["A", "B", "C"]};
				if (items == null){
					return {names:[""], labels:["nothing"]};
				}
				return items;
			default: //donothing
		}
		return null;
	}
	
	override public function getEvent(id:String, sender:Dynamic, data:Dynamic, ?params:Array<Dynamic>):Void 
	{
		super.getEvent(id, sender, data, params);
		switch(id){
			case "focus_layer":
				var mapLayer:MapLayer = cast sender;
				for (layer in layers){
					layer.hasFocus = false;
				}
				mapLayer.hasFocus = true;
			case "map_sigil_change":
				var sigilWidget:SigilWidget = cast sender;
				var i:Int = cast data;
				var value:Bool = false;
				if (params.indexOf("start") != -1){
					value = sigilWidget.starts[i];
				}
				else if (params.indexOf("end") != -1){
					value = sigilWidget.ends[i];
					i += 5;
				}
				getSigilHint(i + 1);
			case "move_map_layer":
				var i:Int = cast data;
				var layer:MapLayer = cast sender;
				onMoveLayer(layer, i);
			case "change_map_layer":
				var i:Int = cast data;
				var layer = layers[i];
				onChangeLayer(layer);
			case "delete_map_layer":
				var i:Int = cast data;
				onDeleteLayer(i);
			case "delete_wave":
				var i:Int = cast data;
				onDeleteWave(i);
			case "add_wave":
				onAddWave();
			case "wave_change":
				onWaveChange();
			case "reward_change":
				onRewardChange(cast data);
			case "bonus_change":
				onBonusChange(cast data);
			case FlxUINumericStepper.CHANGE_EVENT, "sigil_change":
				if (params != null && params.indexOf("wave_widget") != -1){
					var widget = cast(sender, IFlxUIWidget);
					resolveWidgetChange(widget, params);
				}
			case FlxUIPopup.CLICK_EVENT:
				
				//
				
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
								dirty = true;
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
	
	private var locStrs:Map<String,Map<String,String>>;
	
	private var addLayerBtn:FlxUIButton;
	
	private var previewAvailable:Bool = false;
	private var preview:MapPreview;
	
	private var pathTxt:FlxUIText;
	private var saveAs:FlxUIButton;
	private var save:FlxUIButton;
	private var titleBtn:FlxUIButton;
	private var blurbBtn:FlxUIButton;
	private var menu:FlxUIButton;
	
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
	private var sigilHint:String;
	private var data:Settings;
	private var maxUndo:Int = 100;
	private var undoPointer:Int = -1;
	private var undoBuffer:Array<EditState>;
	private var tempState:EditState;
	
	
	private function set_dirty(b:Bool){
		dirty = b;
		if (save != null){
			if (b == true){
				save.label.text = "Save*";
				saveAs.label.text = "Save As*";
			}else{
				save.label.text = "Save";
				saveAs.label.text = "Save As";
			}
		}
		return dirty;
	}
	
	private function onBonusChange(bonusData:BonusStruct){
		if (meta.infos[0].isBonus){
			for (bs in dataFetcher.projectData.bonusData){
				if (bs.id == saveData.mapID){
					bs.match(bonusData);
				}
			}
		}
		dirty = true;
	}
	
	private function onRewardChange(rewards:Array<RewardStruct>){
		if (meta.infos[0].isBonus){
			for (bs in dataFetcher.projectData.bonusData){
				if (bs.id == saveData.mapID){
					bs.matchRewards(rewards);
					
				}
			}
		}
		dirty = true;
	}
	
	private function onWaveChange(){
		refreshWaves();
		updatePreview();
		dirty = true;
	}
	
	private function onAddWave(){
		waves[diffI()].push(getWave());
		refreshWaves(true);
		dirty = true;
	}
	
	private function onDeleteWave(i:Int){
		waves[diffI()].splice(i, 1);
		refreshWaves();
		dirty = true;
	}
	
	private function onDeleteLayer(i:Int){
		var layer = layers.splice(i, 1);
		if(layer != null && layer.length > 0){
			layer[0].destroy();
		}
		dirty = true;
		refreshLayers();
		composite();
	}
	
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
			
			if (layer.hasFocus){
				
				if (layer.button.pressed){
					doInput(layer, false);
				}
				else if (layer.rightButton.pressed){
					doInput(layer, true);
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
		
			var xml = getMapXML();
			var bmp = getMapBitmap();
			
			
			var diff = meta.difficulty;
			if (diff == "normal" || diff == "med"){
				diff = "medium";
			}
			
			preview.updatePreview(true, bmp, xml, diff);
		}
		else{
			preview.updatePreview(false);
		}
	}
	
	private function getSigilHint(i:Int){
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
	
	private function doInput(layer:MapLayer, rightClick:Bool = false, justPressed:Bool = false){
		var change = false;
		tempState.sync(layers);
		
		var skipTool = false;
		if (!layer.editable)
		{
			if (layer.hasSigils){
				if (!rightClick)
				{
					change = layer.onSigilPlace();
				}
				else{
					change = layer.onSigilErase();
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
					if(!rightClick){
						change = layer.onBucket();
					}
					else{
						change = layer.onTurpentine();
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
		
		if(change){
			dirty = true;
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
		
		var mapPath = Util.safePath(saveData.modPath, "maps");
		var bmpPath = Util.safePath(mapPath, saveData.mapID + ".png");
		var xmlPath = Util.safePath(mapPath, saveData.mapID + ".xml");
		
		var mapPNG:BitmapData = (FileSystem.exists(bmpPath) ? BitmapData.fromFile(bmpPath) : getMapBitmap());
		var mapXMLString:String = (FileSystem.exists(xmlPath) ? File.getContent(xmlPath) : "");
		
		var mapXML:Fast = null;
		if (mapXMLString != null){
			mapXML = new Fast(Util.xmlify(mapXMLString));
		}else{
			mapXML = getMapXML();
		}
		
		var bData = BattleData.fromXML(mapXML);
		var bmps = Util.splitMapBitmap(mapPNG, bData.layers.length);
		
		layers = [];
		
		for (layer in bData.layers){
			if (layer.layer == 0){
				makeMapLayer(0xFF000000, 0, layer.value, false, "");
			}else{
				var category = dataFetcher.getTileCategory(layer.value);
				makeMapLayer(layer.rgb, layer.layer, layer.value, true, category);
			}
			var ml:MapLayer = layers[layer.layer];
			var copyBmp = bmps[layer.layer];
			ml.sprite.graphic.bitmap.copyPixels(copyBmp, copyBmp.rect, new Point());
			ml.clearBlack();
		}
		
		layers[0].hasSigils = true;
		
		refreshLayers();
		
		hintText = new FlxText(0, 0, layers[0].sprite.width, "Testing");
		hintText.alignment = FlxTextAlign.CENTER;
		hintText.text = "Testing";
		hintText.font = "assets/fonts/verdana.ttf";
		hintText.size = 14;
		hintText.color = FlxColor.BLACK;
		hintText.x = FlxG.width - (hintText.width + 5);
		hintText.y = FlxG.height - hintText.height * 2;
		add(hintText);
		
		hintText.visible = false;
		
		tempState = new EditState(layers);
		
		for (key in bData.starts.keys()){
			var i = Util.abc2num(key);
			var pt = bData.starts.get(key);
			layers[0].onSigilPlace(START_I - 1 + i, pt.x, pt.y);
		}
		for (key in bData.ends.keys()){
			var i = Util.abc2num(key);
			var pt = bData.ends.get(key);
			layers[0].onSigilPlace(END_I - 1 + i, pt.x, pt.y);
		}
		
		getSigilHint(layers[0].sigilWidget.getFirstI()+1);
		
		composite();
		
		var previewParams = {
			X:Std.int(layers[0].x),
			Y:Std.int(WAVE_Y+25),
			name:"",
			diff:"easy",
			tileHeight:14,
			widthInSquares:settings.squaresWide,
			heightInSquares:settings.squaresTall,
			tilesetStyle:settings.tilesetStyle,
			tilesPerSquare:settings.tilesPerSquare,
			png:mapPNG,
			xml:mapXML,
			levelEdit:true,
			doodads:true
		}
		
		preview = new MapPreview(previewParams);
		add(preview);
		
		menu = addBtn(0, 5, "Main Menu", onMainMenu);
		menu.x = FlxG.width - menu.width - 5;
		
		saveAs = addBtn(menu.x, menu.y + menu.height + 5, "Save As", onExport);
		save = addBtn(saveAs.x, saveAs.y + saveAs.height + 5, "Save", onSave);
		titleBtn = addBtn(save.x, save.y + save.height + 5, "Title...", onTitle);
		blurbBtn = addBtn(titleBtn.x, titleBtn.y + titleBtn.height + 5, "Blurb...", onBlurb);
		
		meta = {
			difficulty:"easy",
			infos:[getMeta("easy"), getMeta("normal"), getMeta("hard")]
		};
		
		var isBonus = false;
		var thisBD:BonusStruct = null;
		for (bd in dataFetcher.projectData.bonusData){
			if (bd.id == saveData.mapID){
				isBonus = true;
				thisBD = bd;
			}
		}
		
		for (i in 0...meta.infos.length){
			var metaInfo:MetaInfo = meta.infos[i];
			metaInfo.firstWait = bData.waves[i].firstWait;
			metaInfo.isEndless = bData.waves[i].isEndless;
			metaInfo.endlessLevelup = bData.waves[i].endlessLevelup;
		}
		
		metaWidget = new MetaWidget(WAVE_X, WAVE_Y);
		add(metaWidget);
		metaWidget.sync(meta);
		
		if(thisBD != null){
			metaWidget.syncBonus(thisBD);
		}
		
		//syncing rewards for non-bonus levels must come later
		//metaWidget.syncRewards(dataFetcher.projectData.);
		
		metaWidget.setBonus(isBonus);
		
		waves = [[],[],[]];
		waveWidgets = [];
		
		for (waveData in bData.waves){
			var diffI = Util.diffToI(waveData.difficulty);
			for (waveInfo in waveData.waves){
				waves[diffI].push(WaveData.copyWaveInfo(waveInfo));
			}
		}
		
		locStrs = dataFetcher.getStrMaps();
		trace("locStrs = " + locStrs);
		
		refreshWaves();
		
		refreshSavePath();
		refreshPreview();
	}
	
	private function getRewards():Array<RewardStruct>{
		for (bd in dataFetcher.projectData.bonusData){
			if (bd.id == saveData.mapID){
				return bd.rewards;
			}
		}
		return null;
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
			if (layerB.isLast && layerB.interactive != ""){
				return;
			}
			layers[b] = layer;
			layers[a] = layerB;
			refreshLayers();
			composite();
		}
		
		dirty = true;
	}
	
	private function onChangeLayer(layer:MapLayer){
		
		var arr = null;
		
		if (layer.layer == 0){
			arr = getTileTypes(false, false, false, true, false, false);
		}
		else{
			if(layer.isLast){
				arr = getTileTypes(true, true, true, false, true, true);
			}
			else{
				arr = getTileTypes(true, true, true, false, true, false);
			}
		}
		
		var popup = new TypePopup(arr, "",
			function(str:String, category:String = ""){
				if (category == "art"){
					layer.interactive = "";
					layer.art = str;
				}
				else if (category == "interactive"){
					layer.art = "";
					layer.interactive = str;
				}
				else{
					layer.art = "";
					layer.interactive = "";
					layer.drawColor = dataFetcher.getTileColor(str);
					layer.value = str;
					if (category == "water"){
						layer.isWater = true;
					}
					else{
						layer.isWater = false;
					}
				}
				refreshLayers();
				composite();
				
				dirty = true;
			}
		);
		
		openSubState(popup);
	}
	
	private function getTileTypes(legal:Bool,illegal:Bool,water:Bool,single:Bool,art:Bool,interactive:Bool):Array<String>
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
		if (interactive){
			arr.push("interactive:");
			for (str in dataFetcher.interactives){
				arr.push(str);
			}
		}
		return arr;
	}
	
	private function onAddLayer(){
		
		var interactiveI:Int = -1;
		for (layer in layers){
			if (layer.interactive != ""){
				interactiveI = layer.layer;
			}
		}
		
		var arr = getTileTypes(true, true, true, false, true, interactiveI == -1);
		
		var popup = new TypePopup(arr, "",
			function(str:String, category:String){
				makeMapLayerFromTileset(str, layers.length, category);
				
				refreshLayers();
				if (interactiveI != -1){
					//if there was an interactives layer already, keep it on top
					onMoveLayer(layers[layers.length - 1], -1);
				}
				refreshLayers(true);
				composite();
				
				dirty = true;
			}
		);
		
		openSubState(popup);
	}
	
	private function refreshLayers(autoScroll:Bool=false){
		
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
			if(i != 0){
				layers[i].isWater = dataFetcher.waterTerrain.indexOf(layers[i].value) != -1;
			}
		}
		
		layerList = new FlxUIList(LAYER_X, LAYER_Y, widgets, LAYER_W, layers[0].back.height, "<X> more...", FlxUIList.STACK_HORIZONTAL, 5);
		add(layerList);
		
		layerList.scrollIndex = scrollIndex;
		
		if (autoScroll && layerList.amountNext > 0){
			layerList.scrollIndex++;
		}
		
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
	
	private function refreshWaves(autoScroll:Bool=false)
	{
		if (waveList == null){
			waveList = new FlxUIList(WAVE_X, WAVE_Y+metaWidget.height+20, null, WaveWidget.W, WaveWidget.H * 5);
			add(waveList);
		}
		
		if (waves == null){
			return;
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
		
		for (layer in layers){
			layer.currDifficulty = meta.difficulty;
		}
		
		var lastWave = new WaveWidget();
		lastWave.ID = waveWidgets.length - 1;
		lastWave.empty = true;
		waveList.add(lastWave);
		
		if (autoScroll && waveList.amountNext > 0){
			waveList.scrollIndex++;
		}
		
		dirty = true;
	}
	
	private function onTitle(){
		
		var titleMap = locStrs.get("title");
		var popup = new LocaleTextPopup(titleMap, "Battle Title", function(texts:Map<String,String>){
			
			trace("titleMap = " + texts);
			dirty = true;
			
		});
		
		openSubState(popup);
	}
	
	private function onBlurb(){
		
		var blurbMap = locStrs.get("blurb");
		var popup = new LocaleTextPopup(blurbMap, "Battle Blurb", function(texts:Map<String,String>){
			
			trace("blurbMap = " + blurbMap);
			dirty = true;
			
		});
		
		openSubState(popup);
	}
	
	private function onSave(){
		if (lastSavePath != ""){
			exportData(lastSavePath);
			dirty = false;
		}
	}
	
	private function refreshSavePath(){
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
	
	private function onMainMenu()
	{
		
		if (dirty){
			
			var popup = new YesNoCancelPopup("Unsaved changes", "Save your changes before closing this level?", function(str:String){
				
				if (str != "cancel"){
					if (str == "yes"){
						onSave();
					}
					FlxG.switchState(new StartState());
				}
				
			});
			
			openSubState(popup);
			
		}else{
			FlxG.switchState(new StartState());
		}
		
	}
	
	private function onExport()
	{
		var popup = new TextPopup(saveData.mapID, "Battle ID", function(str:String){
			
			var path = Util.safePath(saveData.modPath, "maps");
			path = Util.safePath(path, str + ".xml");
			exportData(path);
			
		});
		
		openSubState(popup);
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
			if(layers[i].art == "" && layers[i].interactive == ""){
				var bmp = layers[i].getBasicBitmap();
		
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
		
		var basePath = Util.dataFetcher.modPath;
		
		if (meta.infos[0].isBonus){
			saveBonusData();
			
			var bonusPath = Util.uCat(basePath, "/_append/xml/bonus.xml");
			Util.ensurePath(bonusPath);
			File.saveContent(bonusPath, getBonusString());
		}
		
		var localePath = Util.safePath(basePath, "/_append/locales");
		Util.ensurePath(localePath);
		
		writeLocaleStrings("title", localePath, "$"+saveData.mapID.toUpperCase()+"_TITLE");
		writeLocaleStrings("blurb", localePath, "$"+saveData.mapID.toUpperCase()+"_TEXT");
		
		refreshSavePath();
	}
	
	private function writeLocaleStrings(id:String, path:String, flag:String){
		var map = locStrs.get(id);
		for (locale in map.keys()){
			var locPath = Util.safePath(path, locale);
			Util.ensurePath(locPath);
			locPath = Util.safePath(locPath, "maps.tsv");
			if (!FileSystem.exists(locPath)){
				File.saveContent(locPath, "flag\tcontent\tcomment\n");
			}
			var tsvData = File.getContent(locPath);
			tsvData = Util.appendToTSV(tsvData, flag, map.get(locale));
			File.saveContent(locPath, tsvData);
		}
	}
	
	private function saveBonusData(){
		var exists = false;
		for (bd in Util.dataFetcher.projectData.bonusData){
			if (bd.id == saveData.mapID){
				exists = true;
			}
		}
		if (!exists){
			var newBonus = new BonusStruct();
			
			newBonus.stars = 0;
			newBonus.starsColor = "blue";
			newBonus.starsPlus = 0;
			newBonus.starsPlusColor = "blue";
			newBonus.id = saveData.mapID;
			newBonus.title = saveData.mapID;
			newBonus.description = "";
			newBonus.matchRewards([metaWidget.rewards1, metaWidget.rewards2]);
			Util.dataFetcher.projectData.bonusData.push(newBonus);
		}
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
	
	private function getBonusString():String
	{
		var saveStr:String = '<data>';
		
		for (b in dataFetcher.projectData.bonusData){
			var bstars = b.stars;
			var bcolor = b.starsColor;
			var bstarsPlus = b.starsPlus;
			var bcolorPlus = b.starsPlusColor;
			var bid = b.id;
			var btitle = b.title;
			var bdescription = b.description;
			var bonusStr:String = '<bonus stars="$bstars" color="$bcolor" stars_plus="$bstarsPlus" color_plus="$bcolorPlus" id="$bid" title="$btitle" description="$bdescription">';
			bonusStr = Util.uCat(bonusStr, '<rewards>');
			for (r in b.rewards)
			{
				var rfeat = r.feat;
				var rgoal = r.goal;
				var rtype = r.type;
				var rvalue = Utf8Ext.toLowerCase(r.value);
				var rtypePlus = r.typePlus;
				var rvaluePlus = Utf8Ext.toLowerCase(r.valuePlus);
				
				if (rvalue == "xp") rvalue = "XP";
				if (rvaluePlus == "xp") rvaluePlus = "XP";
				
				var rewardStr:String = '<reward feat="$rfeat" goal="$rgoal" type="$rtype" value="$rvalue" type_plus="$rtypePlus" value_plus="$rvaluePlus"/>';
				bonusStr = Util.uCat(bonusStr, rewardStr);
			}
			bonusStr = Util.uCat(bonusStr, '</rewards>');
			bonusStr = Util.uCat(bonusStr, "</bonus>");
			saveStr = Util.uCat(saveStr, bonusStr);
		}
		
		var save_xml:Xml = Xml.parse(saveStr);
		
		var outputstr = Printer.print(save_xml,true);
		var outputstr = '<?xml version="1.0" encoding="utf-8" ?>\n' + outputstr;
		
		return outputstr;
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
		var tileMiddleStr = "";
		
		var layerIndex = 0;
		var artLayerIndex = 0;
		
		var hasArt = false;
		var hasInteractives = false;
		var artStr = '<artlayers>';
		var interactiveStr = '<features>';
		
		for (i in 0...layers.length){
			
			if (layers[i].art == "" && layers[i].interactive == "")
			{
				var color:FlxColor = layers[i].drawColor;
				var value = switch(layers[i].value){
					case "legal": "grass";
					case "illegal": "dark_cliff";
					case "water": "water";
					default: layers[i].value;
				}
				var hexcol = color.toHexString(false, true);
				if (i == 0){
					tileMiddleStr += '<tile rgb="0x000000" tile_sheet="single" value="$value" layer="0"/>';
				}
				else {
					var doodadBit = "";
					if (layers[i].hasDoodads()){
						var hexdoodad = layers[i].getDoodadColor().toHexString(false, true);
						doodadBit = ' doodad="$hexdoodad" ';
					}
					tileMiddleStr += '<tile rgb="$hexcol" $doodadBit value="$value" layer="$layerIndex"/>';
				}
				if (layers[i].isWater && layers[i].hasSteppingStones()){
					
					var hexstep = layers[i].getSteppingStoneColor().toHexString(false, true);
					tileStr += '<tweak_tile rgb="$hexstep" look="$hexcol" walk="0x000000" feature="stepping_stone_$value:6"/>';
				}
				layerIndex++;
			}
			else
			{
				if(layers[i].art != ""){
					var art = layers[i].art;
					var artx = layers[i].artX;
					var arty = layers[i].artY;
					artLayerIndex = layerIndex - 1;
					artStr += '<artlayer id="$art" x="$artx" y="$arty" layer="$artLayerIndex"/>';
					hasArt = true;
				}else if (layers[i].interactive != ""){
					
					var feats = layers[i].getInteractiveFeatures();
					for (feat in feats){
						var featName = feat.name;
						var featx = feat.x;
						var featy = feat.y;
						var feateasy = feat.easy;
						var featmedium = feat.medium;
						var feathard = feat.hard;
						interactiveStr += '<feature id="$featName" x="$featx" y="$featy" easy="$feateasy" medium="$featmedium" hard="$feathard"/>';
						hasInteractives = true;
					}
				}
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
		tileStr += tileMiddleStr + '</tiles>';
		artStr += '</artlayers>';
		interactiveStr += '</features>';
		
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
				
				var wlvl_up = meta.infos[i].endlessLevelup;
				var winfinite = meta.infos[i].isEndless ? ' infinite="true" lvl_up="$wlvl_up" ' : "";
				var wfirstwait = meta.infos[i].firstWait;
				waveStr = '<waves diff="$wdiff" first_wait="$wfirstwait" $winfinite>';
				
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
		if (hasInteractives){
			save_xml.addChild(Util.xmlify(interactiveStr));
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
	
	private function getTileCategory(value:String):String{
		var type:String = getTileType(value);
		return switch(type){
			case "path": "path";
			case "wall": "illegal";
			case "water": "water";
			default: "legal";
		}
	}
	
	private function showLayer(i:Int, b:Bool)
	{
		if (i > 0)
		{
			if(i < layers.length){
				if (b){
					if (layers[i].art != ""){
						hintText.text = layers[i].art;
					}
					else if (layers[i].interactive != ""){
						hintText.text = layers[i].interactive;
					}
					else {
						hintText.text = layers[i].value + " (" + getTileCategory(layers[i].value) + ")";
						
					}
					hintText.visible = true;
					hintText.x = Std.int(layers[i].sprite.x + (layers[i].sprite.width - hintText.width)/2);
					hintText.y = layers[i].sprite.y + layers[i].sprite.height + 20;
				}
				else{
					if(hintText.text == layers[i].value || hintText.text == layers[i].art){
						hintText.visible = false;
					}
				}
			}
		}
		else{
			if (b){
				hintText.visible = true;
				hintText.text = sigilHint;
				hintText.x = Std.int(layers[i].sprite.x + (layers[i].sprite.width - hintText.width)/2);
				hintText.y = layers[i].sprite.y + layers[i].sprite.height + 50;
			}
			else{
				if (hintText.text == sigilHint){
					hintText.visible = false;
				}
			}
		}
	}
	
	private function makeMapLayerFromTileset(tileset:String, layer:Int, category:String)
	{
		var category = "";
		if (tileset == "legal" || tileset == "illegal" || tileset == "water"){
			var tilesets = [];
			for (ml in layers){
				tilesets.push(ml.value);
			}
			tileset = dataFetcher.getNextTileset(tileset, tilesets);
			category = tileset;
		}
		
		if (category == "art" || category == "interactive"){
			var color = FlxColor.WHITE;
			makeMapLayer(color, layer, tileset, true, category);
		}
		else{
			var color = dataFetcher.getTileColor(tileset);
			makeMapLayer(color, layer, tileset);
		}
	}
	
	private function makeMapLayer(color:FlxColor, layer:Int, value:String, editable:Bool=true, category:String="")
	{
		var tileset = value;
		if (category == "art" || category == "interactive"){
			tileset = "grass";
			color = dataFetcher.getTileColor("grass");
		}
		
		var heightInPixels = data.tilesPerSquare * data.tilePixelsTall * data.squaresTall;
		
		var l = new MapLayer(0, 0, data.squaresWide, data.squaresTall, color, layer, tileset, editable);
		l.effectiveScale = l.back.height / heightInPixels;
		
		if(category == "art"){
			l.art = value;
			l.interactive = "";
		}
		
		if (category == "interactive"){
			l.art = "";
			l.interactive = value;
			l.currDifficulty = meta.difficulty;
		}
		
		if (category == "water"){
			l.isWater = true;
		}
		
		l.button.onOver.callback = function(){
			showLayer(l.layer, true);
		}
		l.button.onOut.callback = function(){
			showLayer(l.layer, false);
		}
		
		layers.push(l);
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