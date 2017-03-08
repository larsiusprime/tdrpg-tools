package;
import com.leveluplabs.tdrpg.FileUtils;
import com.leveluplabs.tdrpg.Popup_MyMods.ModInfo;
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
import haxe.io.Bytes;
import haxe.xml.Fast;
import haxe.xml.Printer;
import lime.system.System;
import lime.ui.FileDialogType;
import openfl.Assets;
import openfl.Lib;
import org.zamedev.lib.Utf8Ext;
import steamwrap.api.Steam;
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
	private var currProjectText:FlxUIText;
	
	private var newProject:FlxUIButton;
	private var loadProject:FlxUIButton;
	
	private var projectID:ButtonWidget;
	private var projectTitle:ButtonWidget;
	private var projectDescription:ButtonWidget;
	
	private var newBattle:FlxUIButton;
	private var loadBattle:FlxUIButton;
	private var newItem:FlxUIButton;
	private var loadItem:FlxUIButton;
	
	private var versionText:FlxUIText;
	private var projectIcon:IconWidget;
	
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
		
		newProject = Util.makeBtn(0, 0, "New Project", onNewProject, 150);
		loadProject = Util.makeBtn(0, 0, "Load Project", onLoadProject, 150);
		projectID = new ButtonWidget(0, 0, 150, 64, "Project ID", "...", onChangeProjectID);
			
		screen = new FlxObject(0, 0, FlxG.width, FlxG.height);
		
		Util.center(screen, newProject, true, true);
		Util.center(screen, loadProject, true, true);
		Util.center(screen, projectID, true, true);
		
		newProject.y = 100;
		loadProject.y = newProject.y + newProject.height + 10;
		
		projectID.x = 256;
		projectID.y = 256;
		
		add(newProject);
		add(loadProject);
		add(projectID);
		
		initInstallPath(init);
		
		FlxG.autoPause = false;
		FlxG.mouse.useSystemCursor = true;
	}
	
	private function makeText(){
		installText = Util.makeTxt(0, 0, FlxG.width, "...");
		projectText = Util.makeTxt(0, 20, FlxG.width, "...");
		currProjectText = Util.makeTxt(0, 40, FlxG.width, "...");
		currProjectText.size += 8;
		
		installText.alignment = flixel.text.FlxTextAlign.CENTER;
		projectText.alignment = flixel.text.FlxTextAlign.CENTER;
		currProjectText.alignment = flixel.text.FlxTextAlign.CENTER;
		
		add(installText);
		add(projectText);
		add(currProjectText);
		
		versionText = Util.makeTxt(0, 0, FlxG.width, "0.0.0");
		versionText.alignment = flixel.text.FlxTextAlign.CENTER;
		versionText.y = FlxG.height - versionText.height;
		var versionString:String = Lib.application.config.version;
		versionText.text = "version " + versionString;
		add(versionText);
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
		currProjectText.text = "Current Project: " + Util.getModID() + "";
		
		projectID.value = Util.getModID();
		
		var info = Util.getModInfo(true);
		
		if (projectTitle != null)
		{
			if (info != null)
			{
				FlxG.bitmapLog.add(info.icon, "info.icon");
				
				projectTitle.value = info.title != null ? info.title : "untitled";
				projectDescription.value = info.description != null ? info.description : "Description goes here";
				projectIcon.value = info.icon != null ? info.icon : Util.randomIcon();
			}
			else
			{
				projectTitle.value = "untitled";
				projectDescription.value = "Description goes here";
			}
		}
		
		initBattleButtons();
		
		var pl = getProjectList();
		
		if (loadProject != null){
			activate(loadProject, getProjectList() != null);
		}
		
		if (loadBattle != null){
			activate(loadBattle, getBattleList() != null);
		}
		
		if (loadItem != null){
			activate(loadItem, getItemList() != null);
		}
		
		var modID = Util.getModID();
		activate(projectID,          (modID != null && modID != ""));
		activate(projectTitle,       (modID != null && modID != ""));
		activate(projectDescription, (modID != null && modID != ""));
	}
	
	private function activate(w:IFlxUIWidget, b:Bool)
	{
		w.active = b;
		w.alpha = b ? 1.0 : 0.5;
	}
	
	private function initBattleButtons(){
		if (loadBattle == null && (loadProject != null) && (saveData.modPath != "" && saveData.modPath != null)){
			newBattle = Util.makeBtn(0, 0, "New battle", onNewBattle, 150);
			loadBattle = Util.makeBtn(0, 0, "Load battle", onLoadBattle, 150);
			newItem = Util.makeBtn(0, 0, "New Item", onNewItem, 150);
			loadItem = Util.makeBtn(0, 0, "Load Item", onLoadItem, 150);
			
			var projectBmp:BitmapData = null;
			var iconPath = Util.safePath(saveData.modPath, "icon.png");
			if (FileSystem.exists(iconPath) && !FileSystem.isDirectory(iconPath)){
				projectBmp = BitmapData.fromFile(iconPath);
			}
			if (projectBmp == null){
				projectBmp = new BitmapData(192, 192, true, FlxColor.WHITE);
			}
			
			projectIcon        = new IconWidget  (32, 256, 192, 192, "Change Icon...", projectBmp, onChangeIcon);
			
			projectTitle       = new ButtonWidget(projectID.x, projectID.y+64 , 150, 64, "Title", "...", onChangeTitle);
			projectDescription = new ButtonWidget(projectID.x, projectID.y+128, 150, 64, "Description", "...", onChangeDescription);
			
			add(projectIcon);
			add(projectTitle);
			add(projectDescription);
			
			newBattle.x = projectID.x + newBattle.width + 5;
			loadBattle.x = newBattle.x;
			newItem.x = newBattle.x;
			loadItem.x = newBattle.x;
			
			newBattle.y = projectID.y;
			loadBattle.y = newBattle.y + newBattle.height + 32;
			newItem.y = loadBattle.y + loadBattle.height + 32;
			loadItem.y = newItem.y + newItem.height + 32;
			
			add(loadBattle);
			add(newBattle);
			add(newItem);
			add(loadItem);
			add(projectIcon);
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
		}else{
			var defaultModPath = getDefaultModPath();
			if (FileSystem.exists(defaultModPath) && FileSystem.isDirectory(defaultModPath)){
				
				saveData.modPath = defaultModPath;
				
				var projects = getProjectList();
				if (projects != null && projects.length > 0)
				{
					saveData.modPath = Util.safePath(saveData.modPath, projects[0]);
				}
				else
				{
					saveData.modPath = "";
				}
				
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
		
		if (FileSystem.exists(testPath) && FileSystem.isDirectory(testPath)){
			
			var files = FileSystem.readDirectory(testPath);
			for (file in files){
				if (file.indexOf("DefendersQuest") != -1){
					var fullFilePath = Util.safePath(testPath, file);
					if (FileSystem.exists(fullFilePath) && FileSystem.isDirectory(fullFilePath) == false)
					{
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
		
		if (Util.dataFetcher == null){
			Util.dataFetcher = new DataFetcher(saveData);
		}
		Util.dataFetcher.load(saveData);
		
		saveStuff();
		
	}
	
	private function detectInstallPath(path:String="", message:String="", finished:Void->Void)
	{
		var isInstallPath = testInstallPath(path);
		
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
	
	private function onChangeDescription(){
		var description = projectDescription.value;
		
		var popup = new BigTextPopup(description, "Project Description", function(str:String){
			
			projectDescription.value = str;
			saveProject();
		});
		openSubState(popup);
	}
	
	private function onChangeIcon(){
		
		saveProject();
	}
	
	private function onChangeTitle(){
		var title = projectTitle.value;
		
		var popup = new BigTextPopup(title, "Project Title", function(str:String){
			if (str == null || str == ""){
				Util.alert(this, "Error!", "Title can't be blank!");
			}else{
				projectTitle.value = str;
				saveProject();
			}
		});
		openSubState(popup);
	}
	
	private function onChangeProjectID(){
		
		var modID = Util.getModID();
		var modPath = saveData.modPath;
		
		var popup = new TextPopup(modID, "Project ID", function(str:String){
			if (str == null || str == ""){
				Util.alert(this, "Error!", "Project ID can't be blank!");
			}else if (str == modID){
				//do nothing, no change
			}
			else if(Util.checkProjectIDIsUnique(str) == false){
				
				var popup = new YesPopup("ID is not unique!", "Another mod on Steam already has the project ID \"" + str + "\", please pick another one.", function(){
					onChangeProjectID();
				});
				openSubState(popup);
				
			}
			else{
				
				var newPath = Util.safePath(modPath, str);
				
				var settingsPath = UU.fixDoubleSlash(newPath + UU.getSlash() + "settings.xml");
				
				if (FileSystem.exists(settingsPath))
				{
					var popup = new YesNoPopup("Confirm overwrite", "An existing project was found at path\n" + newPath + "\nOverwrite it?", function(b:Bool){
						doDeleteProject(str);
						doRenameProject(str);
					});
					
					openSubState(popup);
				}
				else
				{
					doRenameProject(str);
				}
				
			}
			
		},true, true);
		openSubState(popup);
	}
	
	private function doDeleteProject(name:String){
		
		var newPath = Util.safePath(saveData.modPath, name);
		var settingsPath = Util.safePath(newPath, "settings.xml");
		if (FileSystem.exists(settingsPath)){
			UU.clearDirectory(newPath);
		}
	}
	
	private function doRenameProject(newName:String){
		
		var oldName = Util.getModID();
		var basePath = Util.getParentDir(saveData.modPath);
		var oldPath = Util.safePath(basePath, oldName);
		var newPath = Util.safePath(basePath, newName);
		
		var settingsPath = Util.safePath(newPath, "settings.xml");
		
		var content = 0;
		if (FileSystem.exists(newPath))
		{
			var contents = FileSystem.readDirectory(newPath);
			content = contents == null ? 0 : contents.length;
		}
		else
		{
			UU.createDirectoryRecursive(newPath, UU.getOS());
		}
		
		if (content == 0)
		{
			var result = UU.copyDirectory(oldPath, newPath);
			if (result > 0){
				var oldSettings = Util.safePath(oldPath, "settings.xml");
				if (FileSystem.exists(oldSettings)){
					UU.clearDirectory(oldPath);
				}
				fixProjectIDs(newPath, oldName, newName);
			}
			
			saveData.modPath = newPath;
			saveStuff();
		}
		else{
			openSubState(new YesPopup("Error!", "Couldn't rename the project because the destination directory \"" + newPath +"\" was not emptied"));
		}
	}
	
	private function fixProjectIDs(newPath:String, oldID:String, newID:String){
		
		//Fix settings file
		var settingsPath:String = Util.safePath(newPath, "settings.xml");
		var settings:Fast = UU.getModSettings(settingsPath);
		if (settings != null){
			var modInfo:ModInfo = ModInfo.fromXML(settings);
			modInfo.id = newID;
			UU.saveModSettings(modInfo, newPath);
		}
		
		var oldPrefix = Util.uCat(oldID,"~");
		var newPrefix = Util.uCat(newID,"~");
		
		//Fix item image names
		var itemsPath:String = Util.safePath(newPath, "gfx/_hd/items/custom");
		renameFiles(oldPrefix, newPrefix, itemsPath);
		
		//Fix map file names
		var mapsPath:String = Util.safePath(newPath, "maps");
		renameFiles(oldPrefix, newPrefix, mapsPath);
		
		//Fix item xml contents
		var itemXMLPath:String = Util.safePath(newPath, "_append/xml/items.xml");
		renameTextFileContents(oldPrefix, newPrefix, itemXMLPath);
		
		//Fix bonux xml contents
		var bonusXMLPath:String = Util.safePath(newPath, "_append/xml/bonus.xml");
		renameTextFileContents(oldPrefix, newPrefix, bonusXMLPath);
		
		//Fix locale contents
		var localePath:String = Util.safePath(newPath, "_append/locales");
		if(FileSystem.exists(localePath)){
			var locStuff = FileUtils.getAllFilesFromDir(localePath, true, false);
			for (thing in locStuff){
				if (thing.indexOf(".tsv") != -1){
					renameTextFileContents(oldPrefix, newPrefix, thing);
				}
			}
		}
	}
	
	private function renameTextFileContents(oldPrefix:String, newPrefix:String, path:String):Bool{
		
		if (FileSystem.exists(path)){
			
			var str:String = File.getContent(path);
			
			var oldLower = Utf8Ext.toLowerCase(oldPrefix);
			var newLower = Utf8Ext.toLowerCase(newPrefix);
			var oldUpper = Utf8Ext.toUpperCase(oldPrefix);
			var newUpper = Utf8Ext.toUpperCase(newPrefix);
			
			str = UU.uSplitReplace(str, oldPrefix, newPrefix);
			str = UU.uSplitReplace(str, oldLower, newLower);
			str = UU.uSplitReplace(str, oldUpper, newUpper);
			
			File.saveContent(path, str);
			
			return true;
		}
		
		return false;
	}
	
	private function renameFiles(oldPrefix:String, newPrefix:String, dir:String):Bool{
		
		if (FileSystem.exists(dir)){
			var stuff = FileUtils.getAllFilesFromDir(dir, false);
			for (thing in stuff){
				var newName = fixFilePrefix(oldPrefix, newPrefix, thing);
				var newFilename = Util.safePath(dir, newName);
				var oldFilename = Util.safePath(dir, thing);
				var success = renameFile(oldFilename, newFilename);
				if (!success){
					return false;
				}
			}
			return true;
		}
		return false;
	}
	
	private function renameFile(oldName:String, newName:String):Bool{
		
		if (!FileSystem.exists(oldName)) return false;
		
		var bytes = File.getBytes(oldName);
		
		try
		{
			File.saveBytes(newName, bytes);
		}
		catch (msg:Dynamic){
			return false;
		}
		
		if (FileSystem.exists(newName))
		{
			var test = File.getBytes(newName);
			
			if (bytes.compare(test) == 0)
			{
				FileSystem.deleteFile(oldName);
				if (!FileSystem.exists(oldName))
				{
					return true;
				}
			}
			else
			{
				FileSystem.deleteFile(newName);
				return false;
			}
		}
		return false;
	}
	
	private function deleteFile(path:String):Bool{
		if (FileSystem.exists(path) && !FileSystem.isDirectory(path)){
			FileSystem.deleteFile(path);
			return true;
		}
		return false;
	}
	
	private function fixFilePrefix(oldID:String, newID:String, name:String):String{
		if (Unifill.uIndexOf(name, oldID) != -1){
			name = UU.uSplitReplace(name, oldID, newID);
		}
		return name;
	}
	
	private function getDefaultModPath():String{
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
		return modPath;
	}
	
	private function onNewProject(){
		
		var modPath = getDefaultModPath();
		
		var name = "";
		var title = "";
		
		var popup = new TextPopup("untitled", "Project ID", function(str:String){
			
			if (str == null || str == ""){
				Util.alert(this, "Error!", "Project ID can't be blank!");
			}
			else if(Util.checkProjectIDIsUnique(str) == false){
				
				var popup = new YesPopup("ID is not unique!", "Another mod on Steam already has the project ID \"" + str + "\", please pick another one.", function(){
					onNewProject();
				});
				openSubState(popup);
				
			}
			else{
				
				name = str;
				modPath = Util.safePath(modPath, str);
				
				var popup = new TextPopup(str, "Project Title", function(str:String){
					
					title = str;
					var success = ModUtil.exportMod(name, title, modPath, Util.dq1.dqString, Util.dq1.dqVersion, false);
					
					if (!success){
						var popup = new YesNoPopup("Confirm overwrite", "An existing project was found at path\n" + modPath + "\nOverwrite basic settings?", function(b:Bool){
							
							if (b){
								
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
			var last = Util.getLastFolder(modPath);
			if (last != "mods")
			{
				basePath = Util.getParentDir(modPath);
			}
			else
			{
				basePath = modPath;
			}
		}
		else
		{
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
	
	private function saveProject(){
		var title = projectTitle.value;
		var desc = projectDescription.value;
		var icon = projectIcon.value;
		
		var modPath = saveData.modPath;
		
		//Fix settings file
		var settingsPath:String = Util.safePath(modPath, "settings.xml");
		var settings:Fast = UU.getModSettings(settingsPath);
		if (settings != null)
		{
			var modInfo:ModInfo = ModInfo.fromXML(settings);
			modInfo.title = title;
			modInfo.description = desc;
			modInfo.icon = icon;
			UU.saveModSettings(modInfo, modPath);
		}
		
		saveStuff();
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