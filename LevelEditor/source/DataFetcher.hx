package;
#if tdrpg_haxe
import com.leveluplabs.tdrpg.IndexData;
import com.leveluplabs.tdrpg.GraphicStyleData;
import com.leveluplabs.tdrpg.EnemyStats;
import com.leveluplabs.tdrpg.enums.Difficulty;
import com.leveluplabs.tdrpg.FireTongueEx;
import com.leveluplabs.tdrpg.Item;
import com.leveluplabs.tdrpg.ItemIndex;
import com.leveluplabs.tdrpg.enums.ItemClass;
import com.leveluplabs.tdrpg.enums.TerrainType;
import com.leveluplabs.tdrpg.enums.Stat;
#end
import firetongue.FireTongue;
import firetongue.TSV;
import flash.display.BitmapData;
import flash.geom.Matrix;
import flash.geom.Point;
import flixel.FlxG;
import flixel.addons.ui.U;
import flixel.addons.ui.interfaces.IFireTongue;
import flixel.util.FlxArrayUtil;
import flixel.util.FlxColor;
import haxe.io.Bytes;
import haxe.xml.Fast;
import lime.graphics.Image;
import lime.graphics.ImageBuffer;
import openfl.Assets;
import openfl.display.PNGEncoderOptions;
import openfl.geom.Rectangle;
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
	public var mapID(default, null):String = "";
	public var installPath(default, null):String = "";
	
	public var projectData:ProjectData;
	
	#if tdrpg_haxe
	public var index:IndexData = null;
	public var itemIndex:ItemIndex = null;
	public var tongue:FireTongue = null;
	public var graphics:GraphicStyleData = null;
	#end
	
	public var allTerrain:Array<String>;
	public var illegalTerrain:Array<String>;
	public var legalTerrain:Array<String>;
	public var waterTerrain:Array<String>;
	public var singleTerrain:Array<String>;
	public var arts:Array<String>;
	public var interactives:Array<String>;
	
	public function new(saveData:SaveData) 
	{
		load(saveData);
	}
	
	public function loadModPath(saveData:SaveData){
		modPath = saveData.modPath;
	}
	
	public function loadMapID(saveData:SaveData){
		mapID = saveData.mapID;
	}
	
	public function load(saveData:SaveData){
		devPath = saveData.devPath;
		devPath2 = saveData.devPath2;
		modPath = saveData.modPath;
		mapID = saveData.mapID;
		installPath = saveData.installPath;
		refresh();
	}
	
	public function clearPaths(){
		devPath = "";
		devPath2 = "";
		modPath = "";
		installPath = "";
		setError(false, false, false, false);
	}
	
	public function setPath(str:String):Void
	{
		interpretPath(str);
	}
	
	public function getStrMaps():Map<String,Map<String,String>>
	{
		var titleMap = getStrMap("$" + mapID.toUpperCase() + "_TITLE", "maps.tsv",1);
		var blurbMap = getStrMap("$" + mapID.toUpperCase() + "_TEXT", "maps.tsv",1);
		var map = new Map<String,Map<String,String>>();
		map.set("title", titleMap);
		map.set("blurb", blurbMap);
		return map;
	}
	
	/*
	public function getItemStrMap(itemClass:String,itemType:String):Map<String,Map<String,String>>
	{
		var prefix:String = switch(itemClass){
			case "weapon": "W";
			case "armor": "A";
			case "accessory": "ACC";
			default: "U";
		}
		prefix += "_"+itemType.toUpperCase();
		var title = getStrMap("$" + prefix, "items.tsv", 0);
		var blurb = getStrMap("$" + prefix, "items.tsv", 1);
		var map = new Map<String,Map<String,String>>();
		map.set("title", title);
		map.set("blurb", blurb);
		return map;
	}*/
	
	public function getStrMap(flag:String, file:String, i:Int=0):Map<String,String>
	{
		var map = new Map<String,String>();
		var path = Util.safePath(modPath, "_append/locales");
		
		var locs = tongue.locales.copy();
		var notExist = false;
		if(FileSystem.exists(path)){
			var ls = readDirectory(path);
			
			for (loc in locs){
				var filePath = Util.safePath(path, loc + "/" + file);
				var found = false;
				if (FileSystem.exists(filePath)){
					var rawTSV = File.getContent(filePath);
					var tsv = new NoFieldTSV(rawTSV);
					for (row in 0...tsv.grid.length){
						for (col in 0...tsv.grid[row].length){
							
							if (tsv.grid[row][0] == flag){
								var val = tsv.grid[row][i];
								if (val != "" && val != null){
									map.set(loc, val);
									found = true;
								}
							}
						}
					}
				}
				if (!found){
					notExist = true;
					map.set(loc, "???");
				}
			}
		}else{
			for (loc in locs){
				notExist = true;
				map.set(loc, "???");
			}
		}
		
		if (notExist){
			writeLocaleStringMap(map, path, file, flag);
		}
		
		return map;
	}
	
	public function writeLocaleStringMap(map:Map<String,String>, path:String, file:String, flag:String){
		for (locale in map.keys()){
			var locPath = Util.safePath(path, locale);
			Util.ensurePath(locPath);
			locPath = Util.safePath(locPath, file);
			if (!FileSystem.exists(locPath)){
				File.saveContent(locPath, "");
			}
			var tsvData = File.getContent(locPath);
			tsvData = Util.appendToTSV(tsvData, flag, map.get(locale));
			File.saveContent(locPath, tsvData);
		}
	}
	
	public function getItems(code:String):{names:Array<String>,labels:Array<String>}
	{
		#if tdrpg_haxe
		var names:Array<String> = [];
		var labels:Array<String> = [];
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
		}
		
		return {names:names, labels:labels};
		#end
	}
	
	public function sync(save:SaveData){
		save.devPath = devPath;
		save.devPath2 = devPath2;
		save.modPath = modPath;
		save.installPath = installPath;
	}
	
	private function fixFeatureStr(str:String):String{
		if (Unifill.uIndexOf(str, ".png") != -1){
			var l = Unifill.uLength(str);
			str = Unifill.uSubstr(str, 0, l - 4);
		}
		if (Unifill.uIndexOf(str,"feature_") != -1){
			var l = Unifill.uLength(str);
			str = Unifill.uSubstr(str, 8, l - 8);
		}
		return str;
	}
	
	private function fixTerrainStr(str:String):String{
		if (Unifill.uIndexOf(str, ".png") != -1){
			var l = Unifill.uLength(str);
			str = Unifill.uSubstr(str, 0, l - 4);
		}
		if (Unifill.uIndexOf(str, "tile_") != -1){
			var l = Unifill.uLength(str);
			str = Unifill.uSubstr(str, 5, l - 5);
		}
		return str;
	}
	
	public function getNextTileset(tileset:String, used:Array<String>):String{
		
		if (legalTerrain != null && tileset == "legal"){
			for (t in legalTerrain){
				if (used.indexOf(t) == -1){
					tileset = t;
				}
			}
		}
		else if (illegalTerrain != null && tileset == "illegal"){
			for (t in illegalTerrain){
				if (used.indexOf(t) == -1){
					tileset = t;
				}
			}
		}
		else if (waterTerrain != null && tileset == "water"){
			for (t in waterTerrain){
				if (used.indexOf(t) == -1){
					tileset = t;
				}
			}
		}
		else if (singleTerrain != null && tileset == "single"){
			for (t in singleTerrain){
				if (used.indexOf(t) == -1){
					tileset = t;
				}
			}
		}
		
		return tileset;
	}

	public function getTileCategory(tileset:String):String{
		if (waterTerrain.indexOf(tileset) != -1) return "water";
		if (illegalTerrain.indexOf(tileset) != -1) return "illegal";
		return "";
	}
	
	public function getTileColor(tileset:String):FlxColor{
		
		tileset = switch(tileset){
			case "illegal": Util.tile("dark_cliff");
			case "legal": Util.tile("grass");
			default: Util.tile(tileset);
		}
		
		if (index != null){
			var bmp = getBitmapData("gfx/_hd/tiles/tile_" + tileset + ".png");
			if (bmp != null){
				var color:FlxColor = FlxColor.WHITE;
				if (Util.dqx.tilesetStyle == "dq1")
				{
					var lastTileRect = new Rectangle(bmp.width - bmp.height, 0, bmp.height, bmp.height);
					
					var lastTile:BitmapData = new BitmapData(Std.int(lastTileRect.width), Std.int(lastTileRect.height), false, 0xFFFFFFFF);
					lastTile.copyPixels(bmp, lastTileRect, new Point());
					
					var px:BitmapData = new BitmapData(1, 1);
					var m:Matrix = new Matrix();
					m.scale(1 / lastTile.width, 1 / lastTile.height);
					px.draw(lastTile, m, null, null, null, true);
					
					color = px.getPixel32(0, 0);
					
					if (color.brightness < 0.33){
						color.brightness = 0.33;
					}
					
					lastTile.dispose();
					px.dispose();
				}
				else if(Util.dqx.tilesetStyle == "dq2")
				{
					if (bmp.height > bmp.width)
					{
						color = bmp.getPixel32(96, 96);
					}
					
					if (color.brightness < 0.33) {
						color.brightness = 0.33;
					}
				}
				
				return color;
			}
		}
		
		if (tileset == Util.tile("water")) return FlxColor.BLUE;
		if (tileset == Util.tile("grass")) return FlxColor.GREEN;
		if (tileset == Util.tile("legal")) return FlxColor.WHITE;
		if (tileset == Util.tile("illegal")) return FlxColor.RED;
		if (tileset == Util.tile("dark_cliff")) return FlxColor.GRAY;
		return FlxColor.MAGENTA;
	}
	
	public function getPathText():String{
		var str:String = "";
		if (modPath != null && modPath != ""){
			str = Util.uCat("MOD: ",modPath);
		}
		if (devPath != null && devPath != ""){
			if (str != ""){
				str = Util.uCat(str, "\n");
			}
			str = Util.uCat(str, "DQ: ");
			str = Util.uCat(str, devPath);
		}
		if (devPath2 != null && devPath2 != ""){
			if (str != ""){
				str = Util.uCat(str, "\n");
			}
			str = Util.uCat(str, "TDRPG: ");
			str = Util.uCat(str, devPath2);
		}
		if (installPath != null && installPath != ""){
			if (str != ""){
				str = Util.uCat(str, "\n");
			}
			str = Util.uCat(str, "INSTALL: ");
			str = Util.uCat(str, installPath);
		}
		return str;
	}
	
	public function getEnemyStat(enemy:String, s:Stat, forLevel:Int):Float
	{
		var base = _enemyStats.get(enemy);
		var ups = _enemyStatsUp.get(enemy);
		if (base == null || ups == null) return 0;
		var baseStat = base.get(s);
		var upStat = ups.get(s);
		return EnemyStats.getLevelUpStat(s, forLevel, baseStat, upStat, Difficulty.EASY);
	}
	
	public function getEnemyNames(){
		if (_enemyNames == null) return null;
		return _enemyNames.copy();
	}
	
	public function getEnemyTypes(){
		if (_enemyTypes == null) return null;
		return _enemyTypes.copy();
	}
	
	/**********/
	
	private var _path:String;
	private var _enemyNames:Array<String>;
	private var _enemyTypes:Array<String>;
	private var _enemyStats:Map<String,EnemyStats>;
	private var _enemyStatsUp:Map<String,EnemyStats>;
	
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
	private static var dLibrary:DefaultAssetLibrary = null;
	
	private function refresh()
	{
		var hasMod = modPath != "" && modPath != null;
		var hasDev = devPath != "" && devPath != null;
		var hasDev2 = devPath2 != "" && devPath2 != null;
		
		var hasInstall = installPath != "" && installPath != null;
		
		#if tdrpg_haxe
		if(dLibrary == null){
			dLibrary = cast lime.Assets.libraries.get("default");
		}
		
		xLibrary = new AssetLibraryX(modPath, dLibrary);
		xLibrary.xExists = getExists;
		xLibrary.xGetBytes = getBytes;
		xLibrary.xGetImage = getImage;
		xLibrary.xGetPath = getPath;
		xLibrary.xGetText = getText;
		Assets.registerLibrary("default", xLibrary);
		
		#end
		
		setError(hasMod, hasDev, hasInstall, hasDev2);
		
		if (fetchCode == OK){
			loadData();
		}
	}
	
	private function setError(hasMod:Bool, hasDev:Bool, hasInstall:Bool, hasDev2:Bool){
		
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
		
		if (hasInstall){
			error = "";
			fetchCode = DataFetchCode.OK;
		}
	}
	
	private function loadData(){
		loadEnemies();
		loadIndex();
		loadGraphics();
		loadTiles();
		loadFireTongue();
	}
	
	private function fExists(str:String):Bool{
		str = killAssetPrefix(str);
		return assetExists(str, AssetType.TEXT);
	}
	
	private function fGetText(str:String):String{
		str = killAssetPrefix(str);
		str = getGenericFile(str, "");
		if (str != "" && str != null){
			return File.getContent(str);
		}
		return null;
	}
	
	private function fGetDir(str:String):Array<String>{
		str = killAssetPrefix(str);
		return readDirectory(str);
	}
	
	private function loadFireTongue(){
		tongue = new FireTongue(null, fExists, fGetText, fGetDir);
		tongue.init("en-US");
		#if tdrpg_haxe
		Item.staticTongue = tongue;
		#end
	}
	
	private function loadTiles(){
		#if tdrpg_haxe
		
		legalTerrain = [];
		illegalTerrain = [];
		waterTerrain = [];
		singleTerrain = [];
		allTerrain = [];
		arts = [];
		interactives = [];
		
		var path = getPath("assets/gfx/_hd/tiles");
		var results = readDirectory(path);
		
		if(results != null){
			for (r in results){
				if (Unifill.uIndexOf(r, ".png") != -1 && Unifill.uIndexOf(r, "tile_") == 0 && Unifill.uIndexOf(r,"tile_overworld_") != 0){
					
					var test = getBitmapData("assets/gfx/_hd/tiles/" + r);
					var isSingle = false;
					if (test != null && test.width == test.height)
					{
						test.dispose();
						isSingle = true;
					}
					
					r = fixTerrainStr(r);
					allTerrain.push(r);
					
					if (isSingle)
					{
						singleTerrain.push(r);
					}
					else if (index.isTileOfType(r, TerrainType.WATER))
					{
						waterTerrain.push(r);
					}
					else if (index.isTileLegal(r) == false){
						illegalTerrain.push(r);
					}
					else{
						legalTerrain.push(r);
					}
				}
				else if (Unifill.uIndexOf(r, ".png") != -1 && Unifill.uIndexOf(r, "feature_") == 0){
					
					r = fixFeatureStr(r);
					if (Unifill.uIndexOf(r, "stepping_stone") == -1)
					{
						if (index.interactives.exists(r) == false)
						{
							arts.push(r);
						}
						else
						{
							interactives.push(r);
						}
					}
				}
			}
		}
		
		#end
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
		
		if (itemIndex != null){
			itemIndex.destroy();
			itemIndex = null;
		}
		
		var xmlStr = getXMLFile("index", "maps");
		var the_xml:Xml = Xml.parse(xmlStr);
		var fast:Fast = new Fast(the_xml.firstElement());
		
		index = new IndexData(fast);
		
		xmlStr = getXMLFile("items");
		the_xml = Xml.parse(xmlStr);
		fast = new Fast(the_xml.firstElement());
		
		itemIndex = new ItemIndex(fast);
		
		#end
	}
	
	private function isIgnoreType(type:String){
		switch(type){
			case "hide_level", "nuke_on_kill", "no_end_damage", "max_end_hit": return true;
			default: //blah
		}
		return false;
	}
	
	private function loadEnemies(){
		_enemyNames = [];
		_enemyTypes = [];
		_enemyStats = new Map<String,EnemyStats>();
		_enemyStatsUp = new Map<String,EnemyStats>();
		
		var file = getXMLFile("enemy");
		
		if (file != ""){
			var enemies = Util.getFast(file);
			if (enemies.hasNode.enemy_data && enemies.node.enemy_data.hasNode.enemy){
				for (enemy in enemies.node.enemy_data.nodes.enemy){
					var hide:Bool = U.xml_bool(enemy.x, "hide", false);
					var stationary = false;
					if (enemy.hasNode.type){
						for (typeNode in enemy.nodes.type){
							var typeVal = U.xml_str(typeNode.x, "value", true);
							if (typeVal == "stationary"){
								stationary = true;
							}
							if (!isIgnoreType(typeVal) && _enemyTypes.indexOf(typeVal) == -1){
								_enemyTypes.push(typeVal);
							}
						}
					}
					var name = U.xml_name(enemy.x);
					if(!hide && !stationary){
						_enemyNames.push(name);
					}
					var stats = EnemyStats.fromXML(enemy);
					var statsUp = EnemyStats.fromXML(enemy, true);
					_enemyStats.set(name, stats);
					_enemyStatsUp.set(name, statsUp);
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
	
	public function readDirectory(str:String):Array<String>{
		var paths = ["mod", "dev", "dev2", "install"];
		var contents = [];
		
		for(pathType in paths){
			var str = killAssetPrefix(str);
			
			var path = fixPath(str, pathType);
			
			if (path != null && path != ""){
				if (FileSystem.exists(path) && FileSystem.isDirectory(path)){
					var raw = FileSystem.readDirectory(path);
					for (r in raw){
						if (contents.indexOf(r) == -1){
							contents.push(r);
						}
					}
				}
			}
		}
		
		if (contents.length == 0){
			return null;
		}
		
		return contents;
	}
	
	private function getPath(str:String):String{
		
		var str = killAssetPrefix(str);
		
		var path = getGenericFile(str, "");
		if (path != "" && path != null){
			return path;
		}
		return null;
	}
	
	private function getText(str:String):String{
		var path = getGenericFile(str, "");
		if (path != "" && path != null){
			return File.getContent(path);
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
	
	private function fixPath(str:String, type:String):String{
		
		var sub = "";
		
		sub = switch(type){
			case "mod": modPath;
			case "dev": devPath;
			case "dev2": devPath2;
			case "install": installPath;
			default: "";
		}
		
		var result = str;
		if (sub != ""){
			var strBits = Util.splitPath(str);
			var strBits2 = [];
			var assetIndex = -1;
			var i = 0;
			for (bit in strBits){
				if (assetIndex == -1 && Utf8Ext.toLowerCase(bit) == "assets"){
					assetIndex = i;
					break;
				}
				i++;
				if (i > assetIndex && assetIndex != -1){
					strBits2.push(bit);
				}
			}
			var str2 = Util.joinPath(strBits2);
			result = Util.joinPath([sub, str2]);
		}
		
		return result;
	}
	
	private function getGenericFile(str:String, dir:String):String{
		var foo = false;
		if (str.indexOf("paths.xml") != -1) foo = true;
		
		var path = "";
		var file = "";
		
		
		if (modPath != ""){
			var file = getGenericFilePath(modPath, dir, str);
			if (file != "" && file != null){
				return file;
			}
		}
		
		if (devPath != ""){
			var demoStr = (dir != null && dir != "") ? "demo/" + dir : "demo";
			var fullStr = (dir != null && dir != "") ? "full/" + dir : "full";
			
			var file = getGenericFilePath(devPath, demoStr, str);
			if (file != "" && file != null){
				file = getGenericFilePath(devPath, fullStr, str);
			}
			if (file != "" && file != null){
				return file;
			}
		}
		
		if (devPath != ""){
			var file = getGenericFilePath(devPath2, dir, str);
			if (file != "" && file != null){
				return file;
			}
		}
		
		if(installPath != ""){
			var file = getGenericFilePath(installPath, dir, str);
			if (file != "" && file != null){
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
		else{
			if (Util.pathEndsInAssets(path) && Util.pathStartsWithAssets(file)){
				path = Util.getParentDir(path);
				return getGenericFilePath(path, prefix, file);
			}
		}
		return "";
	}
	
	private function getXMLStr(path:String, prefix:String, file:String){
		var test = Util.safePath(path, prefix);
		test = Util.safePath(test, file);
		test = Util.uCat(test, ".xml");
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