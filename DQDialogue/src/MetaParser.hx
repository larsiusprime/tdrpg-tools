package;
import haxe.xml.Fast;
import haxe.xml.Printer;
import sys.FileSystem;
import sys.io.File;
import unifill.Unifill;

/**
 * ...
 * @author 
 */
class MetaParser
{

	public function new(){}
	
	private var cutscenes:Array<String>;
	
	public function parse(inDir:String, outDir:String)
	{
		if (FileSystem.exists(outDir) == false)
		{
			FileSystem.createDirectory(outDir);
		}
		
		var str = "";
		
		var meta = inDir + "meta.txt";
		if (FileSystem.exists(meta))
		{
			str = File.getContent(meta);
			if (str == null) str = "";
		}
		
		var file = outDir + "_temp/meta.txt";
		if (FileSystem.exists(file))
		{
			var str2 = File.getContent(file);
			
			if (str2 == null) str2 = "";
			
			str = str2 + "\n\n" + str;
			
			trace("str = " + str);
			
			if (str != null && str != "")
			{
				cutscenes = [];
				
				var document = processScenes(str);
				Util.saveXML(outDir + "xml/game_progression.xml", document);
				
				trace('cutscenes = ' + cutscenes);
				
				document = processIndex(str);
				Util.saveXML(outDir + "xml/scenes.xml", document);
				
			}
			else
			{
				error("input file \"" + file+"\" is empty!");
				return;
			}
		}
		else
		{
			error("can't find input file \"" + file+"\"");
			return;
		}
	}
	
	public static function error(msg:String)
	{
		Sys.println("META ERROR : " + msg);
	}
	
	private function stripData(data:String):String
	{
		data = StringTools.replace(data, "\r", "");
		data = StringTools.replace(data, "\n", "");
		data = StringTools.replace(data, " ", "");
		data = StringTools.replace(data, "\t", "");
		return data;
	}
	
	private function processScenes(data:String)
	{
		return processData(data, "<plotlines></plotlines>", ["heroes","movies","pearls"]);
	}
	
	private function processIndex(data:String)
	{
		var xml = processData(data, "<scenes></scenes>", ["battle_movies", "reward_movies", "overworld_movies", "party_movies", "town_movies"]);
		if (cutscenes != null)
		{
			for (cutscene in cutscenes)
			{
				var node = Xml.parse('<progress scene="$cutscene"/>');
				xml.addChild(node);
			}
		}
		return xml;
	}
	
	private function depadPearl(pearl:String):String
	{
		while (pearl.length > 1 && pearl.indexOf("0") == 0)
		{
			pearl = pearl.substr(1, pearl.length - 1);
		}
		return pearl;
	}
	
	private function processData(data:String, header:String, match:Array<String>):Xml
	{
		data = stripData(data);
		var lines:Array<String> = data.split(";");
		var document = Xml.parse(header).firstChild();
		for (line in lines)
		{
			if (line == null) continue;
			var entry = line.split(":");
			if (entry.length == 3)
			{
				var plotline:String = entry[0];
				var plottype:String = entry[1];
				
				trace(plotline + " " + plottype);
				
				var cells:Array<String> = entry[2].split(",");
				
				if (match.indexOf(plottype) != -1)
				{
					switch(plottype)
					{
						case "pearls", "movies", "heroes":
							var xml = Xml.parse('<plotline name="$plotline"></plotline>').firstChild();
							xml = addCells(xml, cells, plottype);
							document.addChild(xml);
						case "battle_movies":
							for (cell in cells)
							{
								if (cell == null || cell == "") continue;
								var pearl = depadPearl(cell);
								var xml = Xml.parse('<battle pearl="$pearl" scene="'+cell+'_battle"/>');
								document.addChild(xml);
							}
						case "reward_movies":
							for (cell in cells)
							{
								if (cell == null || cell == "") continue;
								var pearl = depadPearl(cell);
								var xml = Xml.parse('<rewards pearl="$pearl" scene="'+cell+'_rewards"/>');
								document.addChild(xml);
							}
						case "overworld_movies":
							for (cell in cells)
							{
								if (cell == null || cell == "") continue;
								var pearl = depadPearl(cell);
								if (cell.indexOf("_overworld") == -1)
								{
									cell = cell + "_overworld";
								}
								else
								{
									pearl = "";
								}
								var xml = Xml.parse('<overworld pearl="$pearl" scene="$cell"/>');
								document.addChild(xml);
							}
						case "party_movies":
							for (cell in cells)
							{
								if (cell == null || cell == "") continue;
								var arr = splitCell(cell, "*");
								cell = arr[0];
								var section = arr[1];
								var pearl = depadPearl(cell);
								
								cell = pearl + "_party_" + section;
								
								var xml = Xml.parse('<party pearl="$pearl" section="$section" scene="$cell"/>');
								document.addChild(xml);
							}
						case "town_movies":
							for (cell in cells)
							{
								if (cell == null || cell == "") continue;
								var arr = splitCell(cell, "*");
								var town = arr[0];
								var section = arr[1];
								var pearl = depadPearl(arr[2]);
								
								if (town == null) town = "";
								if (section == null) section = "";
								if (pearl == null) pearl = "";
								
								if (pearl != ""){
									pearl = Util.padLeft(pearl, 3);
								}
								
								cell = "town_" + town+ "_" + section + "_" + pearl;
								
								var xml = Xml.parse('<town town="$town" pearl="$pearl" section="$section" scene="$cell"/>');
								document.addChild(xml);
							}
						default:
					}
				}
			}
		}
		return document;
	}
	
	private function splitCell(cell:String, thing:String):Array<String>
	{
		if (cell.indexOf(thing) == -1) return [cell, ""];
		var arr = cell.split(thing);
		if (arr == null || arr.length < 2) return [cell, ""];
		return [arr[0], arr[1], arr[2]];
	}
	
	private function addCells(xml:Xml, cells:Array<String>, plottype:String):Xml
	{
		for (i in 0...cells.length)
		{
			var cell = cells[i];
			var prevCell = i > 0 ? cells [i - 1] : "";
			var nextCell = i < cells.length - 1 ? cells[i + 1] : "dummy";
			
			var el:Fast = getEl(cell, nextCell);
			
			switch(plottype)
			{
				case "pearls": 
					el = addPearl(el, i, cell, prevCell, nextCell);
					xml.addChild(el.x);
				case "movies": 
					var code:String = "";
					var nextCode:String = "";
					var req:String = "";
					var nextReq:String = "";
					
					var cellSplit = splitCell(cell, "*");
					cell = cellSplit[0];
					code = cellSplit[1];
					
					var nextSplit = splitCell(nextCell, "*");
					nextCell = nextSplit[0];
					nextCode = nextSplit[1];
					
					cellSplit = splitCell(cell, "<-");
					cell = cellSplit[0];
					req = cellSplit[1];
					
					nextSplit = splitCell(nextCell, "<-");
					nextCell = nextSplit[0];
					nextReq = nextSplit[1];
					
					el = getEl(cell, nextCell);
					
					var next1:String = "";
					var next2:String = "";
					
					var has1:Bool = false;
					var has2:Bool = false;
					
					var hasX:Bool = false;
					
					if (code == "ix"){
						code = "i";
						hasX = true;
					}
					if (code == "ox"){
						code = "o";
						hasX = true;
					}
					
					var intro = !hasX ? "_intro" : "";
					var outro = !hasX ? "_outro" : "";
					
					var nextI = nextCell != "dummy" ? nextCell + "_intro" : "dummy";
					var nextO = nextCell != "dummy" ? nextCell + "_outro" : "dummy";
					var nextX = nextCell != "dummy" ? nextCell : "dummy";
					
					var isRoot = (i == 0 && !hasX);
					
					var introDelta:Int = !hasX ? -1 : 1;
					var outroDelta:Int =  1;
					
					switch(code)
					{
						case "":
							//an _intro and an _outro
							has1 = true;
							has2 = true;
							next1 = cell != "dummy" ? cell + "_outro" : "dummy";
							switch(nextCode)
							{
								case "", "i": next2 = nextI;
								case "o": next2 = nextO;
								case "ix","ox": next2 = nextX;
							}
							if (isRoot)
							{
								has2 = false;
								next1 = next2;
								intro = "";
							}
						case "i":
							//just an _intro
							has1 = true;
							has2 = false;
							switch(nextCode)
							{
								case "", "i": next1 = nextI;
								case "o": next1 = nextO;
								case "ix","ox": next1 = nextX;
							}
						case "o":
							//just an _outro
							has1 = false;
							has2 = true;
							switch(nextCode)
							{
								case "", "i": next2 = nextI;
								case "o": next2 = nextO;
								case "ix","ox": next2 = nextX;
							}
					}
					
					if (has1)
					{
						el = addMovie(el, i, cell, intro, introDelta, next1, isRoot, req);
						if (el != null) xml.addChild(el.x);
					}
					
					if (has2)
					{
						el = getEl(cell, nextCell);
						el = addMovie(el, i, cell, outro, outroDelta, next2, false, req);
						if (el != null) xml.addChild(el.x);
					}
					
				case "heroes": 
					
					var cellSplit = splitCell(cell, "*");
					cell = cellSplit[0];
					var code = cellSplit[1];
					
					el = addHero(el, i, cell, code);
					xml.addChild(el.x);
					
					var fixName = el.att.name;
					var fixNext = el.att.next;
					
					fixName = StringTools.replace(fixName, "*p", "");
					fixNext = StringTools.replace(fixNext, "*p", "");
					
					if (fixName.indexOf("?") != -1) fixName = splitCell(fixName, "?")[1];
					if (fixName.indexOf("=") != -1) fixName = splitCell(fixName, "=")[1];
					if (fixNext.indexOf("?") != -1) fixNext = splitCell(fixNext, "?")[1];
					if (fixNext.indexOf("=") != -1) fixNext = splitCell(fixNext, "=")[1];
					
					el.x.set("name", fixName);
					el.x.set("next", fixNext);
			}
			
			if (i == cells.length - 1)
			{
				var dummy = Xml.parse('<element next="none" name="dummy"><requirements><requirement type="complete_pearl" value="impossible"/></requirements><actions/></element>').firstChild();
				xml.addChild(dummy);
			}
		}
		
		return xml;
	}
	
	private function addPearls(xml:Xml, cells:Array<String>):Xml
	{
		for (i in 0...cells.length)
		{
			var cell = cells[i];
			var prevCell = i > 0 ? cells [i - 1] : "";
			var nextCell = i < cells.length - 1 ? cells[i + 1] : "dummy";
			
			var el = new Fast(Xml.parse('<element next="b" name="a"><requirements></requirements><actions></actions></element>').firstChild());
			
			el.x.set("name", cell);
			el.x.set("next", nextCell);
			
			var enable = Xml.parse('<action type="enable_pearl" value="$cell"/>').firstChild();
			el.node.actions.x.addChild(enable);
			
			if (i != 0)
			{
				var requirement = Xml.parse('<requirement type="complete_pearl" value="$prevCell"/>').firstChild();
				el.node.requirements.x.addChild(requirement);
				
				var connect = Xml.parse('<action type="connect_pearls" value="$prevCell,$cell"/>').firstChild();
				el.node.actions.x.addChild(connect);
			}
			
			xml.addChild(el.x);
			
			if (i == cells.length - 1)
			{
				var dummy = Xml.parse('<element next="none" name="dummy"><requirements><requirement type="complete_pearl" value="impossible"/></requirements><actions/></element>').firstChild();
				xml.addChild(dummy);
			}
		}
		
		return xml;
	}
	
	private function getEl(cell:String,nextCell:String):Fast
	{
		return new Fast(Xml.parse('<element next="$nextCell" name="$cell"><requirements></requirements><actions></actions></element>').firstChild());
	}
	
	private function addMovie(el:Fast, i:Int, cell:String, suffix:String="", introOutro:Int, nextScene:String, isRoot:Bool=false, requiredScene:String=""):Fast
	{
		var scene = cell + suffix;
		if (i == 0)
		{
			scene = cell;
		}
		
		var enable = Xml.parse('<action type="show_cutscene" value="$scene"/>').firstChild();
		el.node.actions.x.addChild(enable);
		
		if(cutscenes.indexOf(scene) == -1){
			cutscenes.push(scene);
		}
		
		if (isRoot)
		{
			var requirement = Xml.parse('<requirement type="have_hero" value="mcguffin"/>').firstChild();
			el.node.requirements.x.addChild(requirement);
			el.x.set("next", nextScene);
		}
		else
		{
			el.x.set("name", scene);
			el.x.set("next", nextScene);
			
			var theCell = cell;
			
			var removes = ["_overworld"];
			
			for (remove in removes)
			{
				if (theCell.indexOf(remove) != -1)
				{
					theCell = StringTools.replace(theCell, remove, "");
				}
			}
			
			if (introOutro == -1 || introOutro == 0)
			{
				var pearl = depadPearl(theCell);
				var requirement = Xml.parse('<requirement type="start_pearl" value="$pearl"/>').firstChild();
				el.node.requirements.x.addChild(requirement);
			}
			else if(introOutro == 1)
			{
				var pearl = depadPearl(theCell);
				var requirement = Xml.parse('<requirement type="complete_pearl" value="$pearl"/>').firstChild();
				el.node.requirements.x.addChild(requirement);
			}
		}
		
		if (requiredScene != "")
		{
			var requirement = Xml.parse('<requirement type="watched_cutscene" value="$requiredScene"/>').firstChild();
			el.node.requirements.x.addChild(requirement);
		}
		
		return el;
	}
	
	private function addHero(el:Fast, i:Int, cell:String, code:String=""):Fast
	{
		var data = cell.split("=");
		if (data != null && data.length == 2)
		{
			var scene = data[0];
			var hero = data[1];
			var action = "name_hero";
			if (hero.indexOf("?") == 0)
			{
				hero = StringTools.replace(hero, "?", "");
				action = "get_silent_hero";
			}
			
			var nameHero = Xml.parse('<action type="$action" value="$hero"/>').firstChild();
			el.node.actions.x.addChild(nameHero);
			
			if (scene != "-1")
			{
				if (code == "")
				{
					var requirement = Xml.parse('<requirement type="watch_cutscene" value="$scene"/>').firstChild();
					el.node.requirements.x.addChild(requirement);
				}
				else if (code == "p")
				{
					var pearl = depadPearl(scene);
					var requirement = Xml.parse('<requirement type="start_pearl" value="$pearl"/>').firstChild();
					el.node.requirements.x.addChild(requirement);
				}
			}
			
		}
		return el;
	}
	
	private function addPearl(el:Fast, i:Int, cell:String, prevCell:String, nextCell:String):Fast
	{
		cell = depadPearl(cell);
		prevCell = depadPearl(prevCell);
		nextCell = depadPearl(nextCell);
		
		var enable = Xml.parse('<action type="enable_pearl" value="$cell"/>').firstChild();
		el.node.actions.x.addChild(enable);
		
		if (i != 0)
		{
			var requirement = Xml.parse('<requirement type="complete_pearl" value="$prevCell"/>').firstChild();
			el.node.requirements.x.addChild(requirement);
			
			var connect = Xml.parse('<action type="connect_pearls" value="$prevCell,$cell"/>').firstChild();
			el.node.actions.x.addChild(connect);
		}
		
		return el;
	}
}