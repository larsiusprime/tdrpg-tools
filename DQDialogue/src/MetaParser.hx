package;
import haxe.xml.Fast;
import haxe.xml.Printer;
import sys.FileSystem;
import sys.io.File;

/**
 * ...
 * @author 
 */
class MetaParser
{

	public function new(){}
	
	public function parse(inDir:String, outDir:String)
	{
		var file = inDir + "/meta.txt";
		if (FileSystem.exists(file))
		{
			var str = File.getContent(file);
			if (str != null && str != "")
			{
				var document = processMap(str);
				if (document != null)
				{
					if (FileSystem.exists(outDir) == false)
					{
						FileSystem.createDirectory(outDir);
					}
					File.saveContent(outDir+"xml/game_progression.xml", Printer.print(document, true));
				}
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
	
	private function processMap(data:String):Xml
	{
		data = StringTools.replace(data, "\r", "");
		data = StringTools.replace(data, "\n", "");
		data = StringTools.replace(data, " ", "");
		data = StringTools.replace(data, "\t", "");
		var lines:Array<String> = data.split(";");
		var document = Xml.parse('<plotlines></plotlines>').firstChild();
		for (line in lines)
		{
			if (line == null) continue;
			var entry = line.split(":");
			if (entry.length == 3)
			{
				var plotline:String = entry[0];
				var plottype:String = entry[1];
				
				var cells:Array<String> = entry[2].split(",");
				
				var xml = Xml.parse('<plotline name="$plotline"></plotline>').firstChild();
				
				xml = addCells(xml, cells, plottype);
				
				document.addChild(xml);
			}
		}
		return document;
	}
	
	private function splitCell(cell:String, thing:String):Array<String>
	{
		if (cell.indexOf(thing) == -1) return [cell, ""];
		var arr = cell.split(thing);
		if (arr == null || arr.length < 2) return [cell, ""];
		return [arr[0], arr[1]];
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
					el = addHero(el, i, cell);
					xml.addChild(el.x);
			}
			
			if (i == cells.length - 1)
			{
				var dummy = Xml.parse('<element next="none" name="dummy"><requirements type="complete_pearl" value="impossible"></requirements><actions/></element>').firstChild();
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
				var dummy = Xml.parse('<element next="none" name="dummy"><requirements type="complete_pearl" value="impossible"></requirements><actions/></element>').firstChild();
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
				var requirement = Xml.parse('<requirement type="start_pearl" value="$theCell"/>').firstChild();
				el.node.requirements.x.addChild(requirement);
			}
			else if(introOutro == 1)
			{
				var requirement = Xml.parse('<requirement type="complete_pearl" value="$theCell"/>').firstChild();
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
	
	private function addHero(el:Fast, i:Int, cell:String):Fast
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
				var requirement = Xml.parse('<requirement type="watch_cutscene" value="$scene"/>').firstChild();
				el.node.requirements.x.addChild(requirement);
			}
		}
		return el;
	}
	
	private function addPearl(el:Fast, i:Int, cell:String, prevCell:String, nextCell:String):Fast
	{
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