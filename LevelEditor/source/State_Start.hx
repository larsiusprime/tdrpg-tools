package;
import com.leveluplabs.tdrpg.UU;
import flash.display.BitmapData;
import flixel.FlxG;
import flixel.FlxObject;
import flixel.FlxSprite;
import flixel.addons.ui.FlxUIButton;
import flixel.addons.ui.FlxUIState;
import flixel.addons.ui.FlxUIText;
import flixel.addons.ui.U;
import flixel.addons.ui.interfaces.IFlxUIWidget;
import flixel.addons.util.PNGEncoder;
import flixel.util.FlxColor;
import flixel.text.FlxText.FlxTextAlign;
import haxe.xml.Fast;
import haxe.xml.Printer;
import lime.system.System;
import lime.ui.FileDialogType;
import openfl.Assets;
import org.zamedev.lib.Utf8Ext;
import sys.FileSystem;
import sys.io.File;
import unifill.Unifill;

/**
 * ...
 * @author 
 */
class State_Start extends FlxUIState
{
	private var saveData:SaveData;
	private var screen:FlxObject;
	
	private var installText:FlxUIText;
	private var projectText:FlxUIText;
	
	private var newProject:FlxUIButton;
	private var loadProject:FlxUIButton;
	private var newBattle:FlxUIButton;
	private var loadBattle:FlxUIButton;
	private var newItem:FlxUIButton;
	private var loadItem:FlxUIButton;
	
	public function new() 
	{
		super();
	}
	
	override public function create():Void 
	{
		super.create();
		makeBkg();
		makeText();
		
		Util.initSettings();
		
		saveData = new SaveData();
		
		newProject = Util.makeBtn(0, 0, "New Project", onNewProject);
		loadProject = Util.makeBtn(0, 0, "Load Project", onLoadProject);
		
		screen = new FlxObject(0, 0, FlxG.width, FlxG.height);
		
		Util.center(screen, newProject, true, true);
		Util.center(screen, loadProject, true, true);
		
		loadProject.y += newProject.height + 10;
		
		add(newProject);
		add(loadProject);
		
		initInstallPath(init);
		
		FlxG.autoPause = false;
		FlxG.mouse.useSystemCursor = true;
	}
	
	private function makeText(){
		installText = Util.makeTxt(0, 0, FlxG.width, "...");
		projectText = Util.makeTxt(0, 20, FlxG.width, "...");
		
		installText.alignment = flixel.text.FlxTextAlign.CENTER;
		projectText.alignment = flixel.text.FlxTextAlign.CENTER;
		
		add(installText);
		add(projectText);
	}
	
	private function init(){
		
		Util.dataFetcher = new DataFetcher(saveData);
		
		refreshText();
		
		FlxG.mouse.useSystemCursor = true;
		FlxG.autoPause = false;
	}
	
	private function refreshText(){
		installText.text = "Game directory: (" +saveData.installPath+")";
		projectText.text = "Project directory: (" + saveData.modPath + ")";
		
		initBattleButtons();
		
		var pl = getProjectList();
		
		if (loadProject != null){
			if (getProjectList() == null){
				loadProject.visible = false;
			}else{
				loadProject.visible = true;
			}
		}
		
		if(loadBattle != null){
			if (getBattleList() == null){
				loadBattle.visible = false;
			}else{
				loadBattle.visible = true;
			}
		}
		
		if (loadItem != null){
			if (getItemList() == null){
				loadItem.visible = false;
			}else{
				loadItem.visible = true;
			}
		}
	}
	
	private function initBattleButtons(){
		if (loadBattle == null && (loadProject != null) && (saveData.modPath != "" && saveData.modPath != null)){
			newBattle = Util.makeBtn(0, 0, "New battle", onNewBattle);
			loadBattle = Util.makeBtn(0, 0, "Load battle", onLoadBattle);
			newItem = Util.makeBtn(0, 0, "New Item", onNewItem);
			loadItem = Util.makeBtn(0, 0, "Load Item", onLoadItem);
			
			newBattle.x = loadProject.x;
			loadBattle.x = loadProject.x;
			newItem.x = newBattle.x;
			loadItem.x = newBattle.x;
			
			newBattle.y = loadProject.y + loadProject.height + 10;
			loadBattle.y = newBattle.y + newBattle.height + 10;
			newItem.y = loadBattle.y + loadBattle.height + 10;
			loadItem.y = newItem.y + newItem.height + 10;
			
			add(loadBattle);
			add(newBattle);
			add(newItem);
			add(loadItem);
		}
	}
	
	private function onNewItem(){
		
		saveData.save();
		saveStuff();
		
		Util.dataFetcher.loadModPath(saveData);
		
		var popup = new TextPopup("item0", "Item ID", function(str:String){
			
			var basePath = Util.safePath(saveData.modPath, "_append/xml");
			Util.ensurePath(basePath);
			
			var itemNode = Util.loadItemNode(str);
			
			if (Util.stripID(str).toLowerCase() == Util.getModID().toLowerCase()){
				
				var popup = new YesPopup("Error!", "An item may not have the same ID as your project (\"" + str + "\")", function(){
					
					onNewItem();
					
				});
				
				openSubState(popup);
				
			}
			else if (itemNode != null){
				
				var popup = new YesNoPopup("Confirm overwrite", "An existing item was found with ID \""+str+"\"\nOverwrite it?", function(b:Bool){
					
					if (b){
						makeNewItem(str);
					}
					
				});
				
				openSubState(popup);
				
			}else{
				
				makeNewItem(str);
				
			}
			
		}, true, true);
		
		openSubState(popup);
	}
	
	private function makeNewItem(str:String){
		var basePath = Util.safePath(saveData.modPath, "_append/xml");
		Util.ensurePath(basePath);
		var itemPath = Util.safePath(basePath, "items.xml");
		
		if (FileSystem.exists(itemPath) == false){
			var baseItem = '<?xml version="1.0" encoding="utf-8" ?>\n<data>\n</data>';
			File.saveContent(itemPath, baseItem);
		}
		
		var itemXML = new Fast(Util.xmlify(File.getContent(itemPath)));
		
		var theID = str;
		
		var fixID = Util.fixID(theID);
		
		var nameFlag = "$ITM_CUSTOM_" + fixID.toUpperCase() + "_NAME";
		var descFlag = "$ITM_CUSTOM_" + fixID.toUpperCase() + "_DESCRIPTION";
		
		for (el in itemXML.elements){
			if (el.has.editor_id){
				var editorID = U.xml_str(el.x, "editor_id", true);
				if (editorID == theID){
					
					itemXML.x.removeChild(el.x);
					
				}
			}
		}
		
		var itemRaw = Printer.print(itemXML.x, true);
		
		var itemEntry = Util.xmlify('<weapon type="sword" lvl="$fixID" bonus="1" name="$nameFlag" cost="1" description="$descFlag" editor_id="$fixID"/>');
		var itemOut = Util.appendToXML(itemRaw, itemEntry);
		
		var bigIcon = Assets.getBitmapData("*assets/gfx/_hd/editor/weapon_sword_big.png");
		var smallIcon = Assets.getBitmapData("*assets/gfx/_hd/editor/weapon_sword.png");
		
		var baseImgPath = Util.safePath(saveData.modPath, "gfx/_hd/items/custom");
		
		Util.ensurePath(baseImgPath);
		
		var bigPath = Util.safePath(baseImgPath, fixID+"_big.png");
		var smallPath = Util.safePath(baseImgPath, fixID+".png");
		
		//save custom graphics
		var bytes = PNGEncoder.encode(bigIcon);
		File.saveBytes(bigPath, bytes);
		
		bytes = PNGEncoder.encode(smallIcon);
		File.saveBytes(smallPath, bytes);
		
		//save data
		File.saveContent(itemPath, itemOut);
		
		Util.dataFetcher.loadModPath(saveData);
		
		FlxG.switchState(new State_ItemEdit(theID));
	}
	
	private function initInstallPath(callback:Void->Void){
		
		if (saveData.installPath == "" || saveData.installPath == null){
			saveData.installPath = System.applicationDirectory;
			
			if (!testInstallPath(saveData.installPath)){
				saveData.installPath = "";
			}
		}
		
		if (saveData.modPath != "" || saveData.modPath == null){
			if (false == (FileSystem.exists(saveData.modPath) && FileSystem.isDirectory(saveData.modPath))){
				saveData.modPath = "";
				saveData.save();
			}
		}
		
		detectInstallPath(saveData.installPath, "", callback);
	}
	
	private function testInstallPath(testPath:String):Bool
	{
		if (Util.pathEndsInAssets(testPath)){
			testPath = Util.getParentDir(testPath);
		}
		
		UU.debugLog("testPath = " + testPath,true);
		
		if (FileSystem.exists(testPath) && FileSystem.isDirectory(testPath)){
			
			var files = FileSystem.readDirectory(testPath);
			UU.debugLog("files = " + files,true);
			for (file in files){
				if (file.indexOf("DefendersQuest") != -1){
					var fullFilePath = Util.safePath(testPath, file);
					UU.debugLog("fullFilePath = " + fullFilePath, true);
					if (FileSystem.exists(fullFilePath) && FileSystem.isDirectory(fullFilePath) == false)
					{
						UU.debugLog("FOUND DQ!!!", true);
						return true;
					}
				}
			}
		}
		return false;
	}
	
	private function saveInstallPath(path:String){
		
		if (Util.pathEndsInAssets(path) == false){
			path = Util.fixDoubleSlash(Util.joinPath([path, "assets"]));
		}
		
		saveData.installPath = path;
		
		UU.debugLog("installPath = " + path, true);
		
		if (Util.dataFetcher == null){
			Util.dataFetcher = new DataFetcher(saveData);
		}
		Util.dataFetcher.load(saveData);
		
		saveStuff();
		
	}
	
	private function detectInstallPath(path:String="", message:String="", finished:Void->Void)
	{
		var isInstallPath = testInstallPath(path);
		
		UU.debugLog("a   is install path = " + isInstallPath, true);
		
		if (isInstallPath){
			saveInstallPath(path);
			if (finished != null){
				finished();
			}
		}
		else{
			if (message == ""){
				message = "The editor needs to know where the game is installed.\nPress 'Yes' to select a path, or 'No' to quit.";
			}
			var popup = new YesNoPopup("Need game path", message, function(b:Bool){
				if (!b){
					Sys.exit(0);
				}else{
					Util.promptPath(function(str:String){
						
						detectInstallPath(str, "Sorry, that wasn't a valid game directory.\nPress 'Yes' to try again, or 'No' to quit.", null);
						
					}, FileDialogType.OPEN_DIRECTORY);
				}
			});
			openSubState(popup);
		}
	}
	
	private function onNewProject(){
		
		var modPath = UU.getDefaultPath("mods");
		
		var subPath = Util.getLastFolder(Util.getParentDir(modPath));
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
		
		var name = "";
		var title = "";
		
		var popup = new TextPopup("untitled", "Project ID", function(str:String){
			if (str == null || str == ""){
				Util.alert(this, "Error!", "Project ID can't be blank!");
			}else{
				name = str;
				modPath = Util.safePath(modPath, str);
				
				var popup = new TextPopup(str, "Project Title", function(str:String){
					
					title = str;
					var success = ModUtil.exportMod(name, title, modPath, Util.dq1.dqString, Util.dq1.dqVersion, false);
					if (!success){
						var popup = new YesNoPopup("Confirm overwrite", "An existing project was found at path\n" + modPath + "\nOverwrite basic settings?", function(b:Bool){
							
							if(b){
								ModUtil.exportMod(name, title, modPath, Util.dq1.dqString, Util.dq1.dqVersion, true);
								saveData.modPath = modPath;
								saveStuff();
								refreshText();
								
							}else{
								
							}
							
						});
						openSubState(popup);
					}
					else{
						saveData.modPath = modPath;
						saveStuff();
						refreshText();
						
					}
					
				});
				openSubState(popup);
			}
			
		},true, true);
		openSubState(popup);
	}
	
	private function doLoadItem(itemID:String){
		
		Util.dataFetcher.loadModPath(saveData);
		
		FlxG.switchState(new State_ItemEdit(itemID));
		
	}
	
	private function loadMap(mapID:String){
		
		mapID = Util.fixID(mapID);
		
		saveData.mapID = mapID;
		saveData.save();
		
		saveStuff();
		
		Util.dataFetcher.loadMapID(saveData);
		
		FlxG.switchState(new State_LevelEdit(saveData));
		
	}
	
	private function onNewBattle(){
		
		var popup = new TextPopup("battle0", "Battle ID", function(str:String){
		
			var mapID = Util.fixID(Utf8Ext.toLowerCase(str));
			var outXml = Util.safePath(saveData.modPath, "maps/"+mapID+ ".xml");
			
			trace("str = " + str + " mod = " + Util.getModID());
			
			if (Util.stripID(str).toLowerCase() == Util.getModID().toLowerCase()){
				
				var popup = new YesPopup("Error!", "A battle may not have the same ID as your project (\"" + str + "\")", function(){
					
					onNewBattle();
					
				});
				
				openSubState(popup);
				
			}
			else if (FileSystem.exists(outXml)){
				
				var popup = new YesNoPopup("Confirm overwrite", "An existing battle was found with ID \""+str+"\"\nOverwrite it?", function(b:Bool){
					
					if (b){
						makeNewBattle(mapID);
					}
					
				});
				
				openSubState(popup);
				
			}
			else{
			
				makeNewBattle(mapID);
				
			}
			
		},true, true);
		
		openSubState(popup);
	}

	private function makeNewBattle(str:String){
		
		str = Util.fixID(str);
		
		var dqString = Utf8Ext.toLowerCase(Util.dq1.dqString);
		
		var basePng:BitmapData = BakedAssets.getBMP(dqString+".png");
		var baseXml:String = BakedAssets.getTxt(dqString + ".xml");
		
		var mapID = Utf8Ext.toLowerCase(str);
		
		var baseBonus:String = BakedAssets.getTxt("bonus.xml");
		
		baseBonus = Util.uReplace(baseBonus, "$ID$", mapID, false);
		
		if (basePng != null && baseXml != null && baseBonus != null){
			var outPng = Util.safePath(saveData.modPath, "maps/"+mapID + ".png");
			var outXml = Util.safePath(saveData.modPath, "maps/"+mapID + ".xml");
			
			var maps = Util.safePath(saveData.modPath, "maps");
			
			Util.ensurePath(maps);
			
			var outBonus = Util.safePath(saveData.modPath, "_append/xml/bonus.xml");
			var outPath = Util.safePath(saveData.modPath, "_append/xml");
			
			Util.ensurePath(outPath);
			
			var bonusEntryExists = false;
			if (!FileSystem.exists(outBonus)){
				var newStr = '<?xml version="1.0" encoding="utf-8" ?>\n<data>\n</data>';
				File.saveContent(outBonus, newStr);
			}
			
			var xml = new Fast(Util.xmlify(File.getContent(outBonus)));
			
			if (!xml.hasNode.bonus && xml.hasNode.data){
				xml = xml.node.data;
			}
			
			if (xml.hasNode.bonus){
				for (bonusNode in xml.nodes.bonus){
					var bid = U.xml_name(bonusNode.x);
					if (bid == mapID){
						bonusEntryExists = true;
						break;
					}
				}
			}
			
			if (!bonusEntryExists){
				xml.x.addChild(Util.xmlify(baseBonus));
				var baseBonusStr = Printer.print(xml.x, true);
				
				baseBonusStr = Util.killBlankLines(baseBonusStr);
				
				baseBonusStr = Util.uCat('<?xml version="1.0" encoding="utf-8" ?>\n', baseBonusStr);
				
				File.saveContent(outBonus, baseBonusStr);
			}
			
			File.saveBytes(outPng, PNGEncoder.encode(basePng));
			File.saveContent(outXml, baseXml);
		}
		
		loadMap(mapID);
	}
	
	private function getItemList():Array<String>{
		return Util.getItemList();
	}
	
	private function getBattleList():Array<String>{
		var path = Util.safePath(saveData.modPath, "maps");
		if (FileSystem.exists(path) && FileSystem.isDirectory(path)){
			var stuff = FileSystem.readDirectory(path);
			var culled = [];
			if (stuff != null && stuff.length >= 2){
				for (thing in stuff){
					if (thing.indexOf(".xml") != -1){
						var map = Util.stripExtension(thing);
						if (stuff.indexOf(map + ".png") != -1){
							culled.push(Util.stripID(map));
						}
					}
				}
			}
			
			trace("culled = " + culled);
			
			if (culled.length == 0) return null;
			
			return culled;
		}
		return null;
	}
	
	private function onLoadItem()
	{
		var culled = getItemList();
		
		var popup = new TypePopup(culled, "", function(str:String, category:String){
			
			doLoadItem(str);
			
		});
		
		openSubState(popup);
	}
	
	private function onLoadBattle()
	{
		var culled = getBattleList();
		
		var popup = new TypePopup(culled, "", function(str:String, category:String){
			
			loadMap(str);
			
		});
		
		openSubState(popup);
		
	}
	
	private function getProjectList():Array<String>{
		var modPath = saveData.modPath;
		
		var basePath = "";
		
		if (FileSystem.exists(modPath) && FileSystem.isDirectory(modPath)){
			basePath = Util.getParentDir(modPath);
		}
		else{
			basePath = UU.getDefaultPath("mods");
		}
		
		if (FileSystem.exists(basePath) && FileSystem.isDirectory(basePath)){
			var stuff = FileSystem.readDirectory(basePath);
			
			var culled = [];
			for (thing in stuff){
				var test = Util.safePath(basePath, thing);
				test = Util.safePath(test, "settings.xml");
				if (FileSystem.exists(test)){
					culled.push(thing);
				}
			}
			
			if (culled.length == 0) return null;
			
			return culled;
		}
		
		return null;
	}
	
	private function onLoadProject(){
		
		var modPath = saveData.modPath;
		var basePath = "";
		
		if (FileSystem.exists(modPath) && FileSystem.isDirectory(modPath)){
			basePath = Util.getParentDir(modPath);
		}
		else{
			basePath = UU.getDefaultPath("mods");
		}
		
		var culled = getProjectList();
			
		if (culled != null){
			var lastBit = Util.getLastFolder(modPath);
			var popup = new TypePopup(culled, lastBit, function(str:String, category:String){
				
				modPath = Util.safePath(basePath, str);
				saveData.modPath = modPath;
				saveStuff();
				
			});
			openSubState(popup);
		}
		else{
			Util.alert(this, "Error!", "You don't have any projects yet!");
		}
		
	}
	
	private function saveStuff(){
		saveData.save();
		Util.dataFetcher.projectData = new ProjectData(saveData.modPath);
		Util.dataFetcher.loadModPath(saveData);
		refreshText();
	}
	
	private function needPaths():Bool{
		var hasMod = (saveData.modPath != "" && saveData.modPath != null);
		var hasDev = (saveData.devPath != "" && saveData.devPath != null);
		var hasDev2 = (saveData.devPath2 != "" && saveData.devPath2 != null);
		var hasInstall = (saveData.installPath != "" && saveData.installPath != null);
		
		var hasDevs = hasDev && hasDev2;
		
		if (!hasMod && !hasDevs){
			return true;
		}
		
		return false;
	}

	private function makeBkg(){
		var bkg = new FlxSprite().makeGraphic(1, 1, FlxColor.WHITE);
		bkg.scale.set(FlxG.width, FlxG.height);
		bkg.updateHitbox();
		add(bkg);
	}
}