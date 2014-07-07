package ;

import haxe.io.Input;
import haxe.Json;
import haxe.xml.Fast;
import haxe.xml.Printer;
import neko.Lib;
import sys.FileSystem;
import sys.io.File;
import sys.io.FileOutput;
import sys.io.Process;

/**
 * ...
 * @author larsiusprime
 */

class Main 
{
	
	static function main() 
	{
		var args:Array<String> = Sys.args();
		if (args != null)
		{
			if (args.length == 2)
			{
				var projectRaw:String = "";
				
				var projectFile:String = args[0];
				var engineLibrary:String = args[1];
				
				var engineFile:String = "";
				
				var libPath:String = new Process("haxelib", ["path", engineLibrary]).stdout.readLine();
				
				engineFile = libPath + "haxelib.json";
				
				var projectExists:Bool = FileSystem.exists(projectFile);
				var engineExists:Bool = FileSystem.exists(engineFile);
				
				var projectXml:Fast = null;
				var engineJson = null;
				
				var engineName:String = "";
				var projectName:String = "";
				
				var projectVersion:String = "";
				var engineVersion:String = "";
				
				var newTitle:String = "";
				
				if (projectExists && engineExists) {
					projectRaw = File.getContent(projectFile);
					projectXml = new Fast(Xml.parse(projectRaw));
					engineJson = Json.parse(File.getContent(engineFile));
					
					if (Reflect.hasField(engineJson, "version") && Reflect.hasField(engineJson, "name")) {
						engineVersion = Reflect.getProperty(engineJson, "version");
						engineName = Reflect.getProperty(engineJson, "name");
					}
					
					if (projectXml.hasNode.project)
					{
						if (projectXml.node.project.hasNode.meta)
						{
							projectVersion = projectXml.node.project.node.meta.att.version;
							projectName = projectXml.node.project.node.meta.att.name;
							
							newTitle = projectName +" v." + projectVersion + " using " + engineName + " v." + engineVersion;
							
							Sys.println("Application Title is: (" + newTitle+")");
							
							var newFile:String = insertText(projectRaw, "title=\"", "\"", newTitle);
							
							var output:FileOutput = File.write(projectFile);
							output.writeString(newFile);
							output.close();
						}
					}
				}
			}
			else {
				Sys.println("usage: prep_project.n <projectfilexml> <enginefilexml>");
			}
		}else {
			Sys.println("usage: prep_project.n <projectfilexml> <enginefilexml>");
		}
	}
	
	private static function insertText(str:String, begin:String, end:String, insert:String):String {
		var begin_i:Int = str.indexOf(begin);
		var end_i:Int = -1;
		var done:Bool = false;
		var begin_str:String = str.substr(0, begin_i + begin.length);
		var end_str:String = str.substr(begin_str.length,str.length-begin_str.length);
		
		var char:String = " ";
		var i:Int = 0;
		while (!done && end_str.length > 0)
		{
			i++;
			var char:String = end_str.charAt(0);
			if (char != end)
			{
				end_str = end_str.substr(1, end_str.length - 1);
			}else {
				done = true;
			}
		}
		
		return begin_str + insert + end_str;
	}
	
}