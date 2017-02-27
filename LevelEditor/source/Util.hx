package;
import com.leveluplabs.tdrpg.UU;
import firetongue.TSV;
import flash.display.BitmapData;
import flixel.FlxG;
import flixel.FlxObject;
import flixel.FlxState;
import flixel.FlxSubState;
import flixel.addons.ui.FlxUI;
import flixel.addons.ui.FlxUIButton;
import flixel.addons.ui.FlxUICheckBox;
import flixel.addons.ui.FlxUIGroup;
import flixel.addons.ui.FlxUILine;
import flixel.addons.ui.FlxUIRadioGroup;
import flixel.addons.ui.FlxUISprite;
import flixel.addons.ui.FlxUIState;
import flixel.addons.ui.FlxUISubState;
import flixel.addons.ui.FlxUIText;
import flixel.addons.ui.U;
import flixel.addons.ui.interfaces.IFlxUIState;
import flixel.input.actions.FlxAction.FlxActionAnalog;
import flixel.input.actions.FlxAction.FlxActionDigital;
import flixel.input.actions.FlxActionInput;
import flixel.input.actions.FlxActionManager;
import flixel.util.FlxColor;
import haxe.Utf8;
import haxe.xml.Fast;
import haxe.xml.Printer;
import lime.ui.FileDialog;
import lime.ui.FileDialogType;
import lime.ui.Mouse;
import lime.ui.Window;
import openfl.Assets;
import openfl.Lib;
import openfl.events.Event;
import openfl.geom.Point;
import openfl.geom.Rectangle;
import steamwrap.api.Steam;
import sys.FileSystem;
import sys.io.File;
import unifill.CodePoint;
import unifill.Unifill;
import flixel.text.FlxText.FlxTextAlign;
import flixel.input.actions.FlxActionInput.FlxInputDevice;
import flixel.input.actions.FlxActionInput.FlxInputDeviceID;
import flixel.addons.ui.FlxUILine.LineAxis;
import RewardsPicker.RewardStruct;

/**
 * ...
 * @author 
 */
class Util
{
	public static var dq1:Settings;
	public static var dq2:Settings;
	public static var dataFetcher:DataFetcher;
	
	public static function initSettings(){
		makeSettings();
	}
	
	private static function makeSettings(){
		dq1 = new Settings();
		dq2 = new Settings();
		
		dq1.tilesetStyle = "dq1";
		dq1.tilesPerSquare = 2;
		dq1.squaresWide = 15;
		dq1.squaresTall = 14;
		dq1.dqFolder = "DefendersQuest";
		dq1.APP_ID = 218410;
		
		dq2.tilesetStyle = "dq2";
		dq2.tilesPerSquare = 1;
		dq2.squaresWide = 23;
		dq2.squaresTall = 15;
		dq2.dqFolder = "DefendersQuestII";
		dq2.APP_ID = 0;
		
		try{
			if (!Steam.active){
				initSteam();
			}
		}catch (msg:Dynamic){
			
		}
	}
	
	private static function initSteam(){
		
		Steam.init(Util.dq1.APP_ID);
		cacheSteamProjectIDs();
		FlxG.stage.addEventListener(Event.ENTER_FRAME, onEnterFrame, false, 0, true);
		
		FlxG.gamepads.globalDeadZone = 0.15;
		
		//Main.OMNI.actionManager = new FlxActionManager();
		var actionManager = new FlxActionManager();
		FlxG.inputs.add(actionManager);
		
		/*
		actionManager.deviceConnected.add(Main.onDeviceConnected);
		actionManager.deviceDisconnected.add(Main.onDeviceDisconnected);
		actionManager.inputsChanged.add(Main.onInputsChanged);
		*/
		
		var vdfText:String = Assets.getText("assets/xml/actions.vdf");
		actionManager.initSteam(steamwrap.data.ControllerConfig.fromVDF(vdfText), onActionDigital, onActionAnalog);
		var setIndex = actionManager.getSetIndex("EditorControls");
		trace("setIndex = " + setIndex);
		actionManager.activateSet(setIndex, FlxInputDevice.ALL, FlxInputDeviceID.ALL);
		
		//steamwrap.api.Steam.whenGamepadTextInputDismissed = Main.onSteamSoftKeyboardClose;
		
		return true;
	}
	
	private static function onActionDigital(d:FlxActionDigital){
		trace("digital " + d.name);
	}
	
	private static function onActionAnalog(a:FlxActionAnalog){
		trace("analog " + a.name);
	}
	
	private static function onEnterFrame(e:Event){
		if (Steam.active){
			Steam.onEnterFrame();
		}
	}
	
	
	public static function checkProjectIDIsUnique(str:String):Bool
	{
		trace(str + " VS " + projectIDsOnSteam);
		if (projectIDsOnSteam.indexOf(str) != -1){
			return false;
		}
		return true;
	}
	
	
	private static var projectIDsOnSteam:Array<String> = null;
	private static function cacheSteamProjectIDs():Void
	{
		trace("cachesteamprojectIds");
		projectIDsOnSteam = [];
		
		if (!Steam.active) return;
		
		Steam.whenQueryUGCRequestSent = onSteamQuery;
		
		var appID = Util.dq1.APP_ID;
		var queryType = EUGCQuery.RankedByVote;
		var matchingType = EUGCMatchingUGCType.All;
		var queryHandle:String = Steam.ugc.createQueryAllUGCRequest(queryType, matchingType, appID, appID, 1);
		
		Steam.ugc.setReturnKeyValueTags(queryHandle, true);
		
		Steam.ugc.sendQueryUGCRequest(queryHandle);
		
	}
	
	private static function onSteamQuery(result:SteamUGCQueryCompleted):Void
	{
		var handle = result.handle;
		var num = result.numResultsReturned;
		var tot = result.totalMatchingResults;
		
		for (i in 0...num){
			
			var numTags = Steam.ugc.getQueryUGCNumKeyValueTags(handle, i);
			var details = Steam.ugc.getQueryUGCResult(handle, i);
			
			for(tagi in 0...numTags){
				var keyValue = Steam.ugc.getQueryUGCKeyValueTag(handle, i, tagi);
				if(keyValue != null && keyValue.length == 2){
					var key = keyValue[0];
					var value = keyValue[1];
					if (key == "project_id"){
						projectIDsOnSteam.push(value);
					}
				}
			}
		}
		
		trace("projectIDsOnSteam = " + projectIDsOnSteam);
		
		Steam.ugc.releaseQueryUGCRequest(handle);
	}
	
	public static function getFixedModPath():String
	{
		var modPath = UU.getDefaultPath("mods");
		
		var subPath  = Util.getLastFolder(Util.getParentDir(modPath));
		var sub2Path = Util.getLastFolder(Util.getParentDir(Util.getParentDir(modPath)));
		var sub3Path = Util.getLastFolder(Util.getParentDir(Util.getParentDir(Util.getParentDir(modPath))));
		
		var newPath = modPath;
		
		//If default Documents\LevelEditor directory detected, make it point to the DefendersQuest mod directory instead
		if (subPath == "LevelEditor" && sub2Path == "LevelUpLabs" && sub3Path == "Documents"){
			
			var ppPath = Util.getParentDir(Util.getParentDir(modPath));
			
			newPath = Util.safePath(ppPath, Util.dq1.dqFolder);
			newPath = Util.safePath(newPath, Util.getLastFolder(modPath));
			
		}
		
		modPath = newPath;
		
		return modPath;
	}
	
	public static function abc2num(str:String):Int{
		return switch(str){
			case "a": 0;
			case "b": 1;
			case "c": 2;
			case "d": 3;
			case "e": 4;
			default: 0;
		}
	}
	
	public static function num2abc(i:Int):String{
		return switch(i){
			case 0: "a";
			case 1: "b";
			case 2: "c";
			case 3: "d";
			case 4: "e";
			default: "a";
		}
	}
	
	
	
	public static function splitMapBitmap(bmp:BitmapData, layers:Int):Array<BitmapData>
	{
		var sw = Util.dq1.squaresWide;
		var sh = Util.dq1.squaresTall;
		
		var arr = [];
		var rect = new Rectangle(sw, 0, sw, sh);
		for (i in 0...layers){
			var out:BitmapData = new BitmapData(sw, sh, false, 0x000000);
			out.copyPixels(bmp, rect, new Point());
			arr.push(out);
			rect.x += sw;
		}
		
		return arr;
	}
	
	public static function fixXMLDoubleData(str:String):String
	{
		while (Unifill.uIndexOf(str, "<data>\n<data>") != -1)
		{
			str = Util.uSplitReplace(str, "<data>\n<data>", "<data>\n");
		}
		return str;
	}

	public static function loadItemNode(itemID:String):Fast
	{
		var modPath = Util.dataFetcher.modPath;
		var itemPath = Util.safePath(modPath, "_append/xml/items.xml");
		
		if (FileSystem.exists(itemPath) == false) return null;
		
		var itemStr:String = File.getContent(itemPath);
		var itemXML:Fast = new Fast(Util.xmlify(itemStr));
		
		var itemNode:Fast = null;
		for (el in itemXML.elements){
			if (el.has.editor_id){
				var editorID:String = U.xml_str(el.x, "editor_id", true);
				if (editorID == itemID){
					itemNode = el;
					break;
				}
			}
		}
		
		return itemNode;
	}
	
	public static function getCustomItems(code:String):{names:Array<String>,labels:Array<String>}
	{
		var names:Array<String> = [];
		var labels:Array<String> = [];
		
		#if tdrpg_haxe
		
		var culled = [];
		
		var path = Util.safePath(dataFetcher.modPath, "_append/xml/items.xml");
		if (FileSystem.exists(path) && !FileSystem.isDirectory(path)){
			
			var file = File.getContent(path);
			var itemXML = new Fast(Util.xmlify(file));
			
			for (element in itemXML.elements){
				if (element.has.editor_id){
					var editorID:String = U.xml_str(element.x, "editor_id", true);
					var itemClass:String = element.x.nodeName;
					var itemType:String = U.xml_str(element.x, "type", true);
					var itemLevel:String = U.xml_str(element.x, "lvl", true);
					
					if (culled.indexOf(editorID) == -1){
						culled.push(editorID);
						names.push(itemClass + "_" + itemType+"_" + itemLevel);
						labels.push(Util.stripID(editorID));
					}
				}
			}
		}
		
		
		/*
		var classes:Array<ItemClass> = itemIndex.getClasses();
		for (ic in classes){
			var types = itemIndex.getTypes(ic);
			if (types == null) continue;
			var l = types.length;
			for (i in 0...l){
				var type = types[i];
				var items:Array<Item> = itemIndex.getItems(ic, type);
				if (items == null) continue;
				for (i in 0...items.length){
					var item = items[i];
					if (item == null) continue;
					var pass = true;
					if (code == "unique"){
						if (item.unique == false){
							pass = false;
						}
					}
					if (pass){
						names.push(item.itemClass + "_" + item.itemType+"_" + item.level);
						labels.push(item.name);
					}
				}
			}
		}*/
		
		#end
		
		return {names:names, labels:labels};
	}
	
	public static function getItemList():Array<String>{
		var culled = [];
		
		var path = Util.safePath(dataFetcher.modPath, "_append/xml/items.xml");
		if (FileSystem.exists(path) && !FileSystem.isDirectory(path)){
			
			var file = File.getContent(path);
			var itemXML = new Fast(Util.xmlify(file));
			
			for (element in itemXML.elements){
				if (element.has.editor_id){
					var editorID:String = U.xml_str(element.x, "editor_id", true);
					if (culled.indexOf(editorID) == -1){
						culled.push(Util.stripID(editorID));
					}
				}
			}
			
			if (culled.length == 0) return null;
			
			return culled;
		}
		return null;
	}
	
	/*public static function xmlSneakyQuotes(str:String):String{
		
		var inQuotes:Bool = false;
		var quoteString:Int = 0;
		var dblQuote:Int = 0x22;
		var sinQuote:Int = 0x27;
		//var lBracket:Int = 0x7B;
		//var rBracket:Int = 0x7D;
		var quotI:Int = 0;
		
		var quotArr:Array<Int> = [0x26, 0x71, 0x75, 0x6F, 0x74];
		
		var buffer:Array<Int> = [];
		
		var firstQuoteI:Int = -1;
		var lastQuoteI:Int = -1;
		
		Utf8.iter(str, function(char:Int){
			
			if (!inQuotes){
				if (char == dblQuote){
					inQuotes = true;
					quoteString = dblQuote;
				}else if (char == sinQuote){
					inQuotes = false;
					quoteString = sinQuote;
				}
			}else{
				if (char == quoteString){
					inQuotes = false;
				}else{
					
					if (char == quotArr[quotI])
					{
						quotI++;
					}
					
					if (quotI == 4)
					{
						
					}
				}
			}
			
			
		});
		
	}*/
	
	public static function escapeXML(str:String):String{
		
		if (Unifill.uIndexOf(str, "&") != -1){
			unescapeXML(str);	//if we have ANY ampersands, unescape everything first so we're starting from a clean place
		}
		
		str = uSplitReplace(str, "&", "&amp;");
		str = uSplitReplace(str, '"', "&quot;");
		str = uSplitReplace(str, "<", "&lt;");
		str = uSplitReplace(str, ">", "&gt;");
		str = uSplitReplace(str, "'", "&apos;");
		
		return str;
	}
	
	public static function unescapeXML(xmlData:String):String{
		
		var str = "";
		
		xmlData = uSplitReplace(xmlData, "&quot;", '"');
		xmlData = uSplitReplace(xmlData, "&lt;", '<');
		xmlData = uSplitReplace(xmlData, "&gt;", '>');
		xmlData = uSplitReplace(xmlData, "&apos;", "'");
		xmlData = uSplitReplace(xmlData, "&amp;", "&");
		
		return str;
	}
	
	public static function appendToXMLCheap(xmlData:String, xmlString:String):String
	{
		xmlData = killBlankLines(xmlData);
		
		var xmlArr = Unifill.uSplit(xmlData, "\n");
		
		if (xmlArr != null){
			if (xmlArr[xmlArr.length - 1].indexOf("</data>") != -1){
				xmlArr.insert(xmlArr.length-1, xmlString);
			}
		}
		
		if (xmlArr[0] != '<?xml version="1.0" encoding="utf-8" ?>'){
			xmlArr.insert(0, '<?xml version="1.0" encoding="utf-8" ?>');
		}
		
		var xmlOut = "";
		for (i in 0...xmlArr.length){
			var bit = xmlArr[i];
			xmlOut = uCat(xmlOut, bit);
			if (i != xmlArr.length - 1){
				xmlOut = uCat(xmlOut, "\n");
			}
		}
		
		return xmlOut;
	}
	
	public static function appendToXML(xmlData:String, xmlEntry:Xml):String
	{
		var theXML = xmlify(xmlData);
		
		theXML.addChild(xmlEntry);
		
		var xmlOut = Printer.print(theXML, true);
		xmlOut = killBlankLines(xmlOut);
		
		return xmlOut;
	}
	
	public static function appendToTSV(tsvData:String, flag:String, value:String, value2:String=null):String{
		
		if (tsvData == null || tsvData == ""){
			var str = Util.uCat(flag, "\t");
			str = Util.uCat(str, value);
			if (value2 != null){
				str = Util.uCat(str, "\t");
				str = Util.uCat(str, value2);
			}
			str = Util.uCat(str, "\n");
			return str;
		}
		
		var tsv = new NoFieldTSV(tsvData);
		
		if (tsv.grid == null){
			tsv.grid = [];
		}
		
		var found = false;
		for (row in tsv.grid){
			if (row[0] == flag){
				row[1] = value;
				found = true;
				if (value2 != null && row.length > 1){
					row[2] = value2;
				}
			}
		}
		
		if (!found){
			if(value2 == null){
				tsv.grid.push([flag, value]);
			}else{
				tsv.grid.push([flag, value, value2]);
			}
		}
		
		return printTSV(tsv);
	}
		
	public static function removeFromTSV(tsvData:String, flag:String):String{
		
		var tsv = new NoFieldTSV(tsvData);
		
		var found = false;
		for (i in 0...tsv.grid.length){
			var j = tsv.grid.length - i - 1;
			var row = tsv.grid[j];
			if(row != null && row.length > 0){
				if (row[0] == flag){
					tsv.grid.splice(j, 1);
				}
			}
		}
		
		return printTSV(tsv);
	}
	
	
	public static function printTSV(tsv:TSV):String{
		var str = "";
		for (i in 0...tsv.fields.length){
			var field = tsv.fields[i];
			str = Util.uCat(str, field);
			if (i != tsv.fields.length - 1){
				str = Util.uCat(str, "\t");
			}
		}
		
		var lastChar = Unifill.uCharCodeAt(str, Unifill.uLength(str) - 1);
		
		if(lastChar != 10 && lastChar != 13){
			str = Util.uCat(str, "\n");
		}
		
		for (row in 0...tsv.grid.length){
			if (tsv.grid[row].length == 0) continue;
			for (col in 0...tsv.grid[row].length){
				str = Util.uCat(str, tsv.grid[row][col]);
				if (col != tsv.grid[row].length - 1){
					str = Util.uCat(str, "\t");
				}
			}
			if (row != tsv.grid.length - 1){
				var lastChar = Unifill.uCharCodeAt(str, Unifill.uLength(str) - 1);
				if(lastChar != 10 && lastChar != 13){
					str = Util.uCat(str, "\n");
				}
			}
		}
		
		return str;
	}
	
	public static function isLineBlank(str:String){
		var i:Int;
		for (i in 0...str.length){
			switch(str.charAt(i)){
				case " ", "\t", "\r", "\n":
					//do nothing
				default:
					return false;
			}
		}
		return true;
	}
	
	public static function killBlankLines(str:String):String{
		var lines = Unifill.uSplit(str, "\n");
		var lastLine = "";
		var newLines = [];
		for (i in 0...lines.length){
			if (i != 0){
				if (!isLineBlank(lines[i])){
					newLines.push(lines[i]);
				}
			}else{
				newLines.push(lines[i]);
			}
		}
		var sb:StringBuf = new StringBuf();
		for (i in 0...newLines.length){
			sb.add(newLines[i]);
			if(i != newLines.length-1){
				sb.add("\n");
			}
		}
		return sb.toString();
	}
	
	public static function xmlify(str:String){
		return Xml.parse(str).firstElement();
	}
	
	public static function ensurePath(path:String)
	{
		if (FileSystem.exists(path) && FileSystem.isDirectory(path)) return;
		
		var parent = getParentDir(path);
		if (parent == null || parent == "" || FileSystem.exists(parent)){
			//donothing
		}
		else{
			ensurePath(parent);
		}
		
		var stripped = stripExtension(path);
		var isFile = (stripped != path);
		
		if(path != null && path != "" && !isFile){
			FileSystem.createDirectory(path);
		}
	}
	
	public static function fixID(str:String):String{
		str = stripID(str);
		str = Util.getModID() + "~" + str;
		return str;
	}
	
	public static function stripID(str:String){
		var modID = Util.getModID()+"~";
		if (str.indexOf(modID) == 0){
			var ulen = Unifill.uLength(str);
			var otherlen = Unifill.uLength(modID);
			var sub = Unifill.uSubstr(str, otherlen, ulen - otherlen);
			return sub;
		}
		return str;
	}
	
	
	public static function getModID():String{
		return getLastFolder(dataFetcher.modPath).toLowerCase();
	}
	
	public static function matchRewards(a:RewardStruct, b:RewardStruct){
		a.feat = b.feat;
		a.goal = b.goal;
		a.type = b.type;
		a.typePlus = b.typePlus;
		a.value = b.value;
		a.valuePlus = b.valuePlus;
	}
	
	public static function getLastFolder(path:String):String
	{
		var arr = splitPath(path);
		
		while(arr[arr.length - 1] == ""){
			arr.pop();
		}
		
		var last = arr[arr.length - 1];
		
		
		return last;
	}
	
	public static function getFast(str:String):Fast{
		var xml:Xml = Xml.parse(str).firstElement();
		return new Fast(xml);
	}
	
	public static function makeTxt(X:Int, Y:Int, W:Float, label:String):FlxUIText{
		var txt = new FlxUIText(X, Y, W, label, 12);
		txt.font = "assets/fonts/verdana.ttf";
		txt.color = FlxColor.BLACK;
		txt.alignment = FlxTextAlign.LEFT;
		return txt;
	}
	
	public static function makeBtn(X:Int,Y:Int,label:String,callback:Void->Void,W:Float=100,H:Float=32){
		var btn = new FlxUIButton(X, Y, label, callback);
		btn.label.font = "assets/fonts/verdana.ttf";
		btn.label.size = 14;
		btn.label.color = FlxColor.BLACK;
		btn.resize(W, H);
		return btn;
	}
	
	public static function makeCheckbox(X:Float,Y:Float,label:String,callback:Void->Void){
		var cb = new FlxUICheckBox(X, Y, null, null, label, null, null, callback);
		var text:FlxUIText = cast cb.getLabel();
		cb.button.setLabelFormat("assets/fonts/verdana.ttf", 12, FlxColor.BLACK);
		text.setFormat("assets/fonts/verdana.ttf", 12, FlxColor.BLACK);
		var offsets = cb.button.getCenterLabelOffset();
		cb.button.autoCenterLabel();
		var noffsets = cb.button.getCenterLabelOffset();
		cb.button.setCenterLabelOffset(offsets.x, noffsets.y);
		cb.button.up_color = cb.button.over_color = cb.button.down_color = cb.button.down_toggle_color = cb.button.over_toggle_color = cb.button.over_toggle_color = FlxColor.BLACK;
		return cb;
	}
	
	public static function activateRadios(g:FlxUIRadioGroup,ids:Array<String>,b:Bool)
	{
		var rs:Array<FlxUICheckBox> = g.getRadios();
		for (i in 0...g.numRadios){
			var cb:FlxUICheckBox = rs[i];
			if (ids.indexOf(g.getId(i)) != -1){
				cb.alpha = b ? 1.0 : 0.5;
				cb.active = b;
			}
		}
	}
	
	public static function diffI(diff:String):Int{
		return diffToI(diff);
	}
	
	public static function diffToI(str:String){
		return switch(str){
			case "easy": 0;
			case "normal": 1;
			case "hard": 2;
			default: 0;
		}
		return 0;
	}
	
	public static function makeRadios(X:Float,Y:Float,ids:Array<String>,labels:Array<String>,callback:String->Void):FlxUIRadioGroup{
		var radios = new FlxUIRadioGroup(X, Y, ids, labels, callback);
		var rs = radios.getRadios();
		for (i in 0...radios.numRadios){
			var cb:FlxUICheckBox = rs[i];
			var text:FlxUIText = cast cb.getLabel();
			cb.button.setLabelFormat("assets/fonts/verdana.ttf", 12, FlxColor.BLACK);
			text.setFormat("assets/fonts/verdana.ttf", 12, FlxColor.BLACK);
			var offsets = cb.button.getCenterLabelOffset();
			cb.button.autoCenterLabel();
			var noffsets = cb.button.getCenterLabelOffset();
			cb.button.setCenterLabelOffset(offsets.x, noffsets.y);
			cb.button.up_color = cb.button.over_color = cb.button.down_color = cb.button.down_toggle_color = cb.button.over_toggle_color = cb.button.over_toggle_color = FlxColor.BLACK;
		}
		return radios;
	}
	
	public static function makeBox(Wf:Float, Hf:Float, Col:FlxColor = null, Line:FlxColor = FlxColor.BLACK):FlxUIGroup{
		var W = Std.int(Wf);
		var H = Std.int(Hf);
		
		var top    = new FlxUILine(0, 0,     LineAxis.HORIZONTAL, W, 2, Line);
		var left   = new FlxUILine(0, 0,     LineAxis.VERTICAL  , H, 2, Line);
		var bottom = new FlxUILine(0, H - 2, LineAxis.HORIZONTAL, W, 2, Line);
		var right  = new FlxUILine(W - 2, 0, LineAxis.VERTICAL  , H, 2, Line);
		var g = new FlxUIGroup();
		if (Col != null){
			var s = new FlxUISprite(0, 0);
			s.makeGraphic(1, 1, Col, true);
			s.scale.set(W, H);
			s.updateHitbox();
			g.add(s);
		}
		g.add(top);
		g.add(left);
		g.add(right);
		g.add(bottom);
		return g;
	}
	
	public static function promptPath(callback:String->Void, type:FileDialogType = null){
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
	
	public static inline function center(fb1:FlxObject,fb2:FlxObject,centerX:Bool=true,centerY:Bool=true):Void {
		U.center(fb1, fb2, centerX, centerY);
		fb2.x = Std.int(fb2.x);
		fb2.y = Std.int(fb2.y);
	}
	
	public static function alert(state:IFlxUIState, title:String, message:String, closeParam:String=""){
		var popup = new Popup(title, message, closeParam);
		if(Std.is(state,FlxUIState)){
			cast(state,FlxUIState).openSubState(popup);
		}
		else if (Std.is(state, FlxUISubState)){
			cast(state,FlxUISubState).openSubState(popup);
		}
	}
	
	public static function openPopup(sub:FlxSubState)
	{
		var state = FlxUI.getLeafUIState();
		if (Std.is(state, FlxState)){
			cast(state, FlxState).openSubState(sub);
		}else if (Std.is(state, FlxSubState)){
			cast(state, FlxSubState).openSubState(sub);
		}
	}
	
	public static function fixSlashes(str:String):String
	{
		var slash:String = getSlash();
		
		var otherslash:String = "";
		if (slash == "/") {
			otherslash = "\\";
		}else if(slash == "\\"){
			otherslash = "/";
		}
	
		//enforce operating system slash style
		str = uReplace(str, otherslash, slash);
		
		return str;
	}
	
	public static function fixDoubleSlash(str:String):String{
		var str = fixSlashes(str);
		return uReplace(str, getSlash() + getSlash(), getSlash());
	}
	
	public static function getSlash(os:String=""):String {
		var os = "";
		#if windows
			os = "win";
		#end
		var slash:String = "/";
		if (os == "win" || os == "windows") { slash = "\\";}
		return slash;
	}
	
	public static function uSplitReplace(s:String, substr:String, by:String):String{
		if (Unifill.uIndexOf(s, substr) == -1) return s;
		
		var arr = Unifill.uSplit(s, substr);
		
		if (arr == null || arr.length < 2) return s;
		
		var sb:StringBuf = new StringBuf();
		for (i in 0...arr.length){
			var bit = arr[i];
			sb.add(bit);
			if (i != arr.length - 1){
				sb.add(by);
			}
		}
		
		return sb.toString();
	}
	
	public static function uReplace(s:String, substr:String, by:String, recursive:Bool=true):String
	{
		if (Unifill.uIndexOf(s, substr) == -1) return s;
		
		var sb = new StringBuf();
		
		//turn the substr into an array of code points
		var substrArr:Array<CodePoint> = [];
		var iter = Unifill.uIterator(substr);
		while (iter.hasNext())
		{
			substrArr.push(iter.next());
		}
		
		//turn the by str into an array of code points
		var byArr:Array<CodePoint> = [];
		iter = Unifill.uIterator(by);
		while (iter.hasNext())
		{
			byArr.push(iter.next());
		}
		
		var matchI:Int = 0;
		var onMatch = false;
		iter = Unifill.uIterator(s);
		
		while (iter.hasNext())
		{
			//iterate through the main string code point by code point
			var cp:CodePoint = iter.next();
			
			if (matchI < substrArr.length && cp == substrArr[matchI])
			{
				//detected the substr -- advance but don't write to the buffer
				onMatch = true;
				matchI++;
			}
			else
			{
				if (onMatch)
				{
					onMatch = false;
					matchI = 0;
					//write the replacement str to the buffer
					for (i in 0...byArr.length)
					{
						Unifill.uAddChar(sb, byArr[i]);
					}
				}
				//write the character to the buffer
				Unifill.uAddChar(sb, cp);
			}
		}
		if (onMatch && matchI >= substrArr.length)
		{
			for (i in 0...byArr.length)
			{
				Unifill.uAddChar(sb, byArr[i]);
			}
		}
		
		if (recursive)
		{
			return uReplace(sb.toString(), substr, by, true);
		}
		
		//return the final string
		return sb.toString();
	}
	
	public static function safePath(path:String, add:String):String{
		var fLast = Unifill.uLastIndexOf(path, "/");
		var bLast = Unifill.uLastIndexOf(path, "\\");
		var last = Unifill.uLength(path) - 1;
		var needsSlash = (fLast != last && bLast != last);
		var sb = new StringBuf();
		sb.add(path);
		if (needsSlash){
			sb.add(getSlash());
		}
		if (Unifill.uIndexOf(add, "\\") != -1 || Unifill.uIndexOf(add, "/") != -1){
			add == Unifill.uSubstr(add, 1, Unifill.uLength(add) - 1);
		}
		sb.add(add);
		var str = sb.toString();
		str = fixDoubleSlash(str);
		return str;
	}
	
	public static function xmlHead():String{
		return '<?xml version="1.0" encoding="utf-8" ?>';
	}
	
	public static function uCat(a:String, b:String):String{
		var sb = new StringBuf();
		sb.add(a);
		sb.add(b);
		return sb.toString();
	}
	
	public static function joinPath(arr:Array<String>,trailingSlash:Bool=false):String{
		var sb:StringBuf = new StringBuf();
		for (i in 0...arr.length){
			var str = arr[i];
			sb.add(str);
			if (trailingSlash || i != arr.length - 1){
				sb.add(getSlash());
			}
		}
		return sb.toString();
	}
	
	public static function getParentDir(path:String):String{
		var bits = splitPath(path);
		if (bits != null && bits.length > 0){
			bits.pop();
			return joinPath(bits);
		}
		return "";
	}
	
	public static function pathStartsWithAssets(path:String):Bool{
		var bits = splitPath(path);
		if (bits != null && bits.length > 0 && bits[0] == "assets"){
			return true;
		}
		return false;
	}
	
	public static function pathEndsInAssets(path:String):Bool{
		var bits = splitPath(path);
		if (bits != null && bits.length > 0 && bits[bits.length - 1] == "assets"){
			return true;
		}
		return false;
	}
	
	public static function splitPath(path:String):Array<String>
	{
		var arr:Array<String> = Unifill.uSplit(path, "/");
		
		var newArr:Array<String> = [];
		for (str in arr){
			if (Unifill.uIndexOf(str,"\\") != -1){
				var bArr = Unifill.uSplit(str, "\\");
				for (bStr in bArr){
					newArr.push(bStr);
				}
			}
			else{
				newArr.push(str);
			}
		}
		
		return newArr;
	}
	
	public static function goUpOneDirectory(path:String):String
	{
		var arr = splitPath(path);
		arr.pop();
		
		var sb:StringBuf = new StringBuf();
		for (i in 0...arr.length){
			sb.add(arr[i]);
			sb.add(getSlash());
		}
		
		return sb.toString();
	}
	
	public static function stripExtension(path:String):String
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
}