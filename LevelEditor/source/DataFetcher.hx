package;
#if tdrpg_haxe
import com.leveluplabs.tdrpg.IndexData;
import com.leveluplabs.tdrpg.GraphicStyleData;
#end
import flash.display.BitmapData;
import flixel.FlxG;
import flixel.addons.ui.U;
import haxe.io.Bytes;
import haxe.xml.Fast;
import lime.graphics.Image;
import lime.graphics.ImageBuffer;
import openfl.Assets;
import openfl.display.PNGEncoderOptions;
import org.zamedev.lib.Utf8Ext;
import sys.FileSystem;
import sys.io.File;
import unifill.Unifill;

/**
 * ...
 * @author 
 */
class DataFetcher
{
	public var fetchCode(default, null):DataFetchCode;
	public var error(default, null):String;
	
	public var devPath(default, null):String = "";
	public var devPath2(default, null):String = "";
	public var modPath(default, null):String = "";
	public var installPath(default, null):String = "";
	
	#if tdrpg_haxe
	public var index:IndexData = null;
	public var graphics:GraphicStyleData = null;
	#end
	
	public function new(saveData:SaveData) 
	{
		devPath = saveData.devPath;
		devPath2 = saveData.devPath2;
		modPath = saveData.modPath;
		installPath = saveData.installPath;
		refresh();
	}
	
	public function clearPaths(){
		devPath = "";
		devPath2 = "";
		modPath = "";
		installPath = "";
	}
	
	public function setPath(str:String):Void
	{
		interpretPath(str);
	}
	
	public function sync(save:SaveData){
		save.devPath = devPath;
		save.devPath2 = devPath2;
		save.modPath = modPath;
		save.installPath = installPath;
	}
	
	public function getPathText():String{
		var str:String = "";
		if (modPath != null && modPath != ""){
			str = Util.uCat("MOD: ",modPath);
		}
		if (devPath != null && devPath != ""){
			if (str != null){
				str = Util.uCat(str, "\n");
			}
			str = Util.uCat(str, "DQ: ");
			str = Util.uCat(str, devPath);
		}
		if (devPath2 != null && devPath2 != ""){
			if (str != null){
				str = Util.uCat(str, "\n");
			}
			str = Util.uCat(str, "TDRPG: ");
			str = Util.uCat(str, devPath2);
		}
		if (installPath != null && installPath != ""){
			if (str != null){
				str = Util.uCat(str, "\n");
			}
			str = Util.uCat(str, "INSTALL: ");
			str = Util.uCat(str, installPath);
		}
		return str;
	}
	
	public function getEnemyTypes(){
		if (_enemyTypes == null) return null;
		return _enemyTypes.copy();
	}
	
	/**********/
	
	private var _path:String;
	private var _enemyTypes:Array<String>;
	
	private function get_path():String{
		return _path;
	}
	
	private function interpretPath(path:String){
		
		var parentDir = Util.goUpOneDirectory(path);
		var parentName = Util.getLastFolder(parentDir);
		
		var lastFolder = Util.getLastFolder(path);
		if (lastFolder.toLowerCase() != "assets")
		{
			fetchCode = DataFetchCode.NEEDS_ASSETS;
			error = "File path must end in 'assets'!";
		}
		
		var isMod = false;
		var isDev = false;
		var isDev2 = false;
		if (Utf8Ext.toLowerCase(parentName) == "mods")
		{
			modPath = path;
			isMod = true;
		}
		else
		{
			var Hxprj = Util.safePath(parentDir, "Tdrpg-haxe.hxproj");
			if (FileSystem.exists(Hxprj) || FileSystem.exists(Utf8Ext.toLowerCase(Hxprj)))
			{
				devPath2 = path;
				isDev2 = true;
			}
			else{
				var projectPath = Util.safePath(parentDir, "project.xml");
				if (FileSystem.exists(projectPath))
				{
					devPath = path;
					isDev = true;
				}
			}
			
		}
		
		if(!isDev && !isMod && !isDev2)
		{
			var stuff = FileSystem.readDirectory(parentDir);
			var foundEXE:Bool = false;
			var foundLime:Bool = false;
			for (thing in stuff){
				if (Unifill.uIndexOf(thing, ".exe") != -1){
					foundEXE = true;
				}
				if (Unifill.uIndexOf(thing, "lime.ndll") != -1){
					foundLime = true;
				}
			}
			if (foundEXE && foundLime){
				installPath = path;
			}
		}
		
		refresh();
	}
	
	private var xLibrary:AssetLibraryX;
	
	private function refresh()
	{
		var hasMod = modPath != "" && modPath != null;
		var hasDev = devPath != "" && devPath != null;
		var hasDev2 = devPath2 != "" && devPath2 != null;
		
		var hasInstall = installPath != "" && installPath != null;
		#if tdrpg_haxe
		if (xLibrary == null){
			var defaultLibrary:DefaultAssetLibrary = cast lime.Assets.libraries.get("default");
			xLibrary = new AssetLibraryX(modPath, defaultLibrary);
		}
		xLibrary.xExists = getExists;
		xLibrary.xGetBytes = getBytes;
		xLibrary.xGetImage = getImage;
		xLibrary.xGetPath = getPath;
		Assets.registerLibrary("default", xLibrary);
		
		trace("hasmod = " + hasMod + " hasdev " + hasDev + " hasdev2 " + hasDev2 + " hasinstall " + hasInstall);
		
		#end
		
		if (fetchCode == DataFetchCode.NEEDS_ASSETS){
			if (hasMod){
				error = "";
				fetchCode = DataFetchCode.OK;
			}
		}
		else
		{
			error = "";
			fetchCode = DataFetchCode.OK;
		}
		
		if (!hasMod && !hasDev && !hasInstall && !hasDev2){
			error = "Path must be the 'assets' folder of one of these three:\n- a mod,\n- the game's install directory\n- the game's source code directory";
			fetchCode = DataFetchCode.HAS_NOTHING;
		}
		else{
			if (hasMod){
				if (!hasDev && !hasInstall){
					error = "A mod is specified, but one of these paths is still required:\n- the game's install directory\n- the game's source code directory";
					fetchCode = DataFetchCode.HAS_MOD_NEED_BASE;
				}
			}
			if (hasDev && !hasDev2 || hasDev2 && !hasDev){
				error = "A source path is specified, but one is still missing. Both of these are required:\n- the game's content directory (DQ1/DQ2/etc)\n- the game's engine directory (tdrpg)";
				fetchCode = DataFetchCode.HAS_DEV_NEED_MORE;
			}
		}
		
		if (fetchCode == OK){
			loadData();
		}
	}
	
	private function loadData(){
		loadEnemies();
		loadIndex();
		loadGraphics();
	}
	
	private function loadGraphics(){
		#if tdrpg_haxe
		if (graphics != null)
		{
			graphics.destroy();
			graphics = null;
		}
		
		var xmlStr = getXMLFile("graphics");
		var fast:Fast = new Fast(Util.xmlify(xmlStr));
		
		graphics = new GraphicStyleData(fast);
		
		#end
	}
	
	private function loadIndex(){
		
		#if tdrpg_haxe
		if (index != null)
		{
			index.destroy();
			index = null;
		}
		
		var xmlStr = getXMLFile("index", "maps");
		var the_xml:Xml = Xml.parse(xmlStr);
		var fast:Fast = new Fast(the_xml.firstElement());
		
		index = new IndexData(fast);
		#end
	}
	
	private function loadEnemies(){
		_enemyTypes = [];
		
		var file = getXMLFile("enemy");
		
		if (file != ""){
			var enemies = Util.getFast(file);
			if (enemies.hasNode.enemy_data && enemies.node.enemy_data.hasNode.enemy){
				for (enemy in enemies.node.enemy_data.nodes.enemy){
					_enemyTypes.push(U.xml_name(enemy.x));
				}
			}
		}
	}
	
	private function getImage(str:String):Image{
		var path = getPath(str);
		if (path != null && path != ""){
			return Image.fromBitmapData(BitmapData.fromFile(path));
		}
		return null;
	}
	
	private function getPath(str:String):String{
		
		var str = killAssetPrefix(str);
		
		var path = getGenericFile(str, "");
		if (path != "" && path != null){
			return path;
		}
		return null;
	}
	
	private function getBytes(str:String):lime.utils.Bytes{
		var path = getGenericFile(str, "");
		if (path != "" && path != null){
			return lime.utils.Bytes.readFile(path);
		}
		return null;
	}
	
	public function getBitmapData(str:String):BitmapData{
		var image = getImage(str);
		if (image != null){
			return BitmapData.fromImage(image);
		}
		return null;
	}
	
	public function getExists(str:String, type:String):Bool{
		return assetExists(str, cast type);
	}
	
	public function assetExists(str:String, assetType:AssetType):Bool{
		var newPath = killAssetPrefix(str);
		newPath = getGenericFile(newPath, "");
		if (newPath != null && newPath != ""){
			return true;
		}
		return false;
	}
	
	private function killAssetPrefix(str:String):String{
		var pathBits = Util.splitPath(str);
		var firstBit = pathBits[0];
		if (firstBit == "assets"){
			pathBits.splice(0, 1);
		}
		var newPath = Util.joinPath(pathBits);
		return newPath;
	}
	
	private function getGenericFile(str:String, dir:String):String{
		var path = "";
		var file = "";
		
		if (modPath != ""){
			var file = getGenericFilePath(modPath, dir, str);
			if (file != ""){
				return file;
			}
		}
		
		if (devPath != ""){
			var demoStr = (dir != null && dir != "") ? "demo/" + dir : "demo";
			var fullStr = (dir != null && dir != "") ? "full/" + dir : "full";
			
			var file = getGenericFilePath(devPath, demoStr, str);
			if (file == ""){
				file = getGenericFilePath(devPath, fullStr, str);
			}
			if (file != ""){
				return file;
			}
		}
		
		if (devPath != ""){
			var file = getGenericFilePath(devPath2, dir, str);
			if (file != ""){
				return file;
			}
		}
		
		if(installPath != ""){
			var file = getGenericFilePath(installPath, dir, str);
			if (file != ""){
				return file;
			}
		}
		
		return "";
	}
	
	private function getXMLFile(str:String, dir:String = "xml"){
		
		var path = "";
		var file = "";
		
		if (modPath != ""){
			var file = getXMLStr(modPath, dir, str);
			if (file != ""){
				return file;
			}
		}
		
		if (devPath != ""){
			var file = getXMLStr(devPath, "demo/"+dir, str);
			if (file == ""){
				file = getXMLStr(devPath, "full/"+dir, str);
			}
			if (file != ""){
				return file;
			}
		}
		if (devPath != ""){
			var file = getXMLStr(devPath2, dir, str);
			if (file != ""){
				return file;
			}
		}
		
		if(installPath != ""){
			var file = getXMLStr(installPath, dir, str);
			if (file != ""){
				return file;
			}
		}
		
		return "";
	}
	
	private function getGenericFilePath(path:String, prefix:String, file:String):String{
		var test = Util.safePath(path, prefix);
		test = Util.safePath(test, file);
		
		if (FileSystem.exists(test)){
			return test;
		}
		return "";
	}
	
	private function getXMLStr(path:String, prefix:String, file:String){
		var test = Util.safePath(path, prefix);
		test = Util.safePath(test, file);
		test = Util.uCat(test, ".xml");
		trace("test = " + test);
		if(FileSystem.exists(test)){
			return File.getContent(test);
		}
		return "";
	}
}

@:enum abstract DataFetchCode(Int){
	public var OK = 0;
	public var HAS_MOD_NEED_BASE = 1;
	public var HAS_NOTHING = 2;
	public var NEEDS_ASSETS = 3;
	public var HAS_DEV_NEED_MORE = 4;
}