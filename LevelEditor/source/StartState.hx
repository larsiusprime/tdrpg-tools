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
class StartState extends FlxUIState
{
	private var saveData:SaveData;
	private var screen:FlxObject;
	
	private var installText:FlxUIText;
	private var projectText:FlxUIText;
	
	private var newProject:FlxUIButton;
	private var loadProject:FlxUIButton;
	private var newBattle:FlxUIButton;
	private var loadBattle:FlxUIButton;
	
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
	}
	
	private function initBattleButtons(){
		if (loadBattle == null && (loadProject != null) && (saveData.modPath != "" && saveData.modPath != null)){
			newBattle = Util.makeBtn(0, 0, "New battle", onNewBattle);
			loadBattle = Util.makeBtn(0, 0, "Load battle", onLoadBattle);
			
			newBattle.x = loadProject.x;
			loadBattle.x = loadProject.x;
			
			newBattle.y = loadProject.y + loadProject.height + 10;
			loadBattle.y = newBattle.y + newBattle.height + 10;
			
			add(newBattle);
			add(loadBattle);
		}
	}
	
	private function initInstallPath(callback:Void->Void){
		
		if (saveData.installPath == "" || saveData.installPath == null){
			saveData.installPath = Util.fixDoubleSlash(Util.joinPath([System.applicationDirectory, "assets"]));
			
			if (testInstallPath(saveData.installPath)){
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
		
		var isInstallPath = false;
		if(FileSystem.exists(testPath) && FileSystem.isDirectory(testPath)){
			var files = FileSystem.readDirectory(testPath);
			for (file in files){
				if (file.indexOf("DefendersQuest") != -1 && file.indexOf(".exe") != -1){
					return true;
				}
			}
		}
		return false;
	}
	
	private function saveInstallPath(path:String){
		
		if (Util.pathEndsInAssets(path) == false){
			path = Util.joinPath([path, "assets"]);
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
	
	private function onNewProject(){
		
		var modPath = UU.getDefaultPath("mods");
		
		var name = "";
		var title = "";
		
		var popup = new TextPopup("untitled", "Project name", function(str:String){
			if (str == null || str == ""){
				Util.alert(this, "Error!", "Project name can't be blank!");
			}else{
				name = str;
				modPath = Util.safePath(modPath, str);
				var popup = new TextPopup(str, "Project title", function(str:String){
					
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
			
		});
		openSubState(popup);
	}
	
	private function loadMap(mapID:String){
		
		saveData.mapID = mapID;
		saveData.save();
		
		saveStuff();
		
		FlxG.switchState(new LevelEditState(saveData));
		
	}
	
	private function onNewBattle(){
		
		var popup = new TextPopup("untitled", "Battle ID", function(str:String){
			
			var dqString = Utf8Ext.toLowerCase(Util.dq1.dqString);
			
			var basePng:BitmapData = Assets.getBitmapData("*assets/levels/" + dqString + ".png");
			var baseXml:String = Assets.getText("*assets/levels/" + dqString + ".xml");
			
			var mapID = Utf8Ext.toLowerCase(str);
			
			var baseBonus:String = Assets.getText("*assets/levels/bonus.xml");
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
					
					baseBonusStr = Util.uCat('<?xml version="1.0" encoding="utf-8" ?>\n<data>\n', baseBonusStr);
					File.saveContent(outBonus, baseBonusStr);
				}
				
				File.saveBytes(outPng, PNGEncoder.encode(basePng));
				File.saveContent(outXml, baseXml);
			}
			
			loadMap(mapID);
			
		});
		
		openSubState(popup);
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
							culled.push(map);
						}
					}
				}
			}
			
			if (culled.length == 0) return null;
			
			return culled;
		}
		return null;
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