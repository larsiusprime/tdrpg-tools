package;
import haxe.xml.Fast;
import haxe.xml.Printer;
import sys.FileSystem;
import sys.io.File;

/**
 * ...
 * @author larsiusprime
 */

class Main
{

	public function new() 
	{
		doStuff(Sys.args());
		Sys.exit(0);
	}
	
	public function doStuff(args:Array<String>)
	{
		if (args.length < 2){
			usage();
			return;
		}
		
		var inFile = args[0];
		var outFile = args[1];
		if (FileSystem.exists(inFile))
		{
			processMap(File.getContent(inFile), outFile);
		}
		else
		{
			Sys.println("could not find file: " + inFile);
		}
	}
	
	private function processMap(data:String, out:String)
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
		
		File.saveContent(out, Printer.print(document,true));
	}
	
	private function addPearls(xml:Xml, cells:Array<String>):Xml
	{
		for (i in 0...cells.length)
		{
			var cell = cells[i];
			var prevCell = i > 0 ? cells [i - 1] : "";
			var nextCell = i < cells.length - 1 ? cells[i + 1] : "dummy";
			
			var el = new Fast(Xml.parse('<element name="a" next="b"><requirements></requirements><actions></actions></element>').firstChild());
			
			el.x.set("name", cell);
			el.x.set("next", nextCell);
			
			var enable = Xml.parse('<action type="enable_pearl" value="$cell"/>').firstChild();
			el.node.actions.x.addChild(enable);
			
			if (i != 0)
			{
				var requirement = Xml.parse('<requirement type="complete_pearl" value="$prevCell"/>').firstChild();
				el.node.requirements.x.addChild(requirement);
				
				var connect = Xml.parse('<action type="connect_pearl" value="$prevCell,$cell"/>').firstChild();
				el.node.actions.x.addChild(connect);
			}
			
			xml.addChild(el.x);
			
			if (i == cells.length - 1)
			{
				var dummy = Xml.parse('<element name="dummy" next="none"><requirements type="complete_pearl" value="impossible"></requirements><actions/></element>').firstChild();
				xml.addChild(dummy);
			}
		}
		
		return xml;
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
					el = addMovie(el, i, cell, true, nextCell);
					if(el != null) xml.addChild(el.x);
					el = getEl(cell, nextCell);
					el = addMovie(el, i, cell, false, nextCell);
					if(el != null) xml.addChild(el.x);
				case "heroes": 
					el = addHero(el, i, cell);
					xml.addChild(el.x);
			}
			
			if (i == cells.length - 1)
			{
				var dummy = Xml.parse('<element name="dummy" next="none"><requirements type="complete_pearl" value="impossible"></requirements><actions/></element>').firstChild();
				xml.addChild(dummy);
			}
		}
		
		return xml;
	}
	
	private function getEl(cell:String,nextCell:String):Fast
	{
		return new Fast(Xml.parse('<element name="$cell" next="$nextCell"><requirements></requirements><actions></actions></element>').firstChild());
	}
	
	private function addMovie(el:Fast, i:Int, cell:String, isIntro:Bool, nextCell:String):Fast
	{
		var scene = cell + (i != 0 ? (isIntro ? "_intro" : "_outro") : "");
		
		var nextScene = isIntro ? (cell + "_outro") : (nextCell + "_intro");
		
		var enable = Xml.parse('<action type="show_cutscene" value="$scene"/>').firstChild();
		el.node.actions.x.addChild(enable);
		
		if (i == 0)
		{
			if (isIntro)
			{
				var requirement = Xml.parse('<requirement type="have_hero" value="mcguffin"/>').firstChild();
				el.node.requirements.x.addChild(requirement);
			}
			else
			{
				return null;
			}
		}
		else
		{
			el.x.set("name", scene);
			el.x.set("next", nextScene);
			
			if (isIntro)
			{
				var requirement = Xml.parse('<requirement type="start_pearl" value="$cell"/>').firstChild();
				el.node.requirements.x.addChild(requirement);
			}
			else
			{
				var requirement = Xml.parse('<requirement type="complete_pearl" value="$cell"/>').firstChild();
				el.node.requirements.x.addChild(requirement);
			}
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
			
			var connect = Xml.parse('<action type="connect_pearl" value="$prevCell,$cell"/>').firstChild();
			el.node.actions.x.addChild(connect);
		}
		
		return el;
	}
	
	private function usage()
	{
		Sys.println("usage: dqmap infile.txt outfile.txt");
	}

}