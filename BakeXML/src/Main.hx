package;
import com.leveluplabs.tdrpg.UU;
import flixel.addons.ui.FlxUI;
import flixel.addons.ui.U;
import haxe.ds.ArraySort;
import haxe.xml.Fast;
import lime.app.Application;
import sys.FileSystem;
import sys.io.File;
import sys.io.FileOutput;

using StringTools;

/**
 * ...
 * @author larsiusprime
 */

class Main extends Application
{

	public var pathsToCheck = ["assets/full/xml/ui", "assets/demo/xml/ui", "../tdrpg-haxe/code/assets/xml/ui"];
	public var filesToProcess = ["state_battle_layout_16x9", "battle_character_menu", "battle_defender_menu", "battle_character_preview", "battle_defender_preview", "battle_enemy_menu"];
	
	public function new() 
	{
		super();
		doStuff(Sys.args());
		Sys.exit(0);
	}
	
	public function doStuff(args:Array<String>):Void
	{
		for (f in filesToProcess)
		{
			for (p in pathsToCheck)
			{
				var file = getFile(p + "/" + f + ".xml");
				if (file != "")
				{
					processFile(file);
				}
			}
		}
	}
	
	public function processFile(file:String)
	{
		var xml:Xml = UU.xmlify(file);
		processXML(xml);
	}
	
	public function processXML(xml:Xml)
	{
		for (element in xml.elements)
		{
			processXML(element);
		}
		
		var flxUI:FlxUI = new FlxUI();
		flxUI.load(xml);
		
		var use_def = U.xml_str(xml, "use_def");
		if (use_def != "")
		{
			xml = FlxUI.consolidateData(xml
		}
	}
	
	public function getFile(name:String):String
	{
		if (FileSystem.exists(name) && FileSystem.isDirectory(name) == false)
		{
			return (File.getContent(name));
		}
		return "";
	}
	
	public function writeStr(str:String, name:String):Void
	{
		Sys.println("writing " + str.length + " characters to file(" + name+")...");
		var error:Bool = false;
		try
		{
			var f:FileOutput = File.write(name);
			f.writeString(str);
			f.close();
		}
		catch (msg:String)
		{
			error = true;
			Sys.print("ERROR! (" + msg + ")\n");
		}
	}
	
	public function usage():Void
	{
		Sys.println("usage: ");
	}

}