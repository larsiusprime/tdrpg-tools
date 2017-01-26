package;

import cpp.Lib;
import sys.FileSystem;
import sys.io.File;

/**
 * ...
 * @author 
 */
class Main 
{
	
	static function main() 
	{
		var args = Sys.args();
		if (args == null || args.length < 2)
		{
			usage();
		}
		else
		{
			fixVersion(args[0], args[1]);
		}
	}
	
	static function fixVersion(path:String, version:String)
	{
		if (path == "")
		{
			path = Sys.getCwd() + path;
		}
		
		if (FileSystem.exists(path) && FileSystem.isDirectory(path))
		{
			var stuff = FileSystem.readDirectory(path);
			for (thing in stuff){
				if (FileSystem.exists(path+"/"+thing) && !FileSystem.isDirectory(path+"/"+thing))
				{
					if (thing.indexOf(".vdf") != -1 && thing.indexOf("app_build") != -1){
						Sys.println("fixing " + thing + "...");
						var contents = File.getContent(path + "/" + thing);
						var newContents = fixVersionFile(contents, version);
						if (newContents != null)
						{
							File.saveContent(path + "/" + thing, newContents);
						}
					}
				}
			}
		}
		else
		{
			Sys.println("couldn't find directory: " + path);
		}
	}
	
	static function fixVersionFile(content:String, version:String):String
	{
		var lines = content.split("\n");
		if (lines != null && lines.length > 0){
			var i = 0;
			for (line in lines){
				var nameValue = getNameValue(line);
				if (nameValue.name != ""){
					if (nameValue.name == "desc")
					{
						var newValue = fixVersionString(nameValue.value, version);
						var newLine = StringTools.replace(lines[i], nameValue.value, newValue);
						lines[i] = newLine;
					}
				}
				i++;
			}
		}
		return lines.join("\n");
	}
	
	static function fixVersionString(string:String, version:String):String
	{
		var words = string.split(" ");
		var lastWord = words[words.length - 1];
		if (lastWord.indexOf(".") != -1 && containsNumber(lastWord)){
			words[words.length - 1] = version;
		}
		return words.join(" ");
	}
	
	static function containsNumber(lastWord:String):Bool
	{
		for (i in 0...10){
			if (lastWord.indexOf(Std.string(i)) != -1)
			{
				return true;
			}
		}
		return false;
	}
	
	static function getNameValue(line:String):{name:String, value:String}
	{
		var name = "";
		var value = "";
		var quote = 0;
		var skip = false;
		for (i in 0...line.length){
			skip = false;
			if (line.charAt(i) == '"'){
				quote++;
				skip = true;
			}
			if (!skip)
			{
				switch(quote){
					case 1: name += line.charAt(i);
					case 2: //donothing
					case 3: value += line.charAt(i);
					case 4: break;
				}
			}
		}
		return {name:name, value:value};
	}
	
	static function usage()
	{
		Sys.println("usage: fix_version path/to/steamworks/scripts <version_number>\nex: fix_version C:\\steamworks\\sdk\\tools\\ContentBuilder\\scripts 1.0.0");
	}
	
}