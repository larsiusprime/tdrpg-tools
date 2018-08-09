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
		var input = args[0];
		var dir = args[1];
		
		if (!FileSystem.exists(dir))
		{
			return;
		}
		
		var map:Map<String,String> = new Map<String,String>();
		
		if (FileSystem.exists(input))
		{
			var file = File.getContent(input);
			file = StringTools.replace(file, "\r", "");
			var lines = file.split("\n");
			for (line in lines)
			{
				var cells = line.split("\t");
				map.set(cells[0], cells[1]);
			}
			fixGraphics(dir, map);
			fixDefenders(dir, map);
		}
	}
	
	static function fixGraphics(dir:String, map:Map<String,String>)
	{
		var gfxDir = dir + "/assets/demo/gfx/_hd/defenders/";
		var dirs = FileSystem.readDirectory(gfxDir);
		for (dir in dirs)
		{
			var oldPath = gfxDir + dir;
			for (key in map.keys())
			{
				if (dir.indexOf(key) != -1)
				{
					dir = map.get(key);
					break;
				}
			}
			var newPath = gfxDir + dir;
			if (newPath != oldPath)
			{
				Sys.println("renaming (" + oldPath + ") to (" + newPath + ")");
				FileSystem.rename(oldPath, newPath);
			}
		}
	}
	
	static function fixDefenders(dir:String, map:Map<String,String>)
	{
		var defDir = dir + "/assets/demo/xml/entities/defenders/";
		var dirs = FileSystem.readDirectory(defDir);
		for (dir in dirs)
		{
			var oldPath = defDir + dir;
			for (key in map.keys())
			{
				if (dir.indexOf(key) != -1)
				{
					dir = map.get(key);
					var content = File.getContent(oldPath);
					if (content != null && content != "")
					{
						Sys.println("replacing (" + key + ") with (" + map.get(key) + ") in " + oldPath);
						content = StringTools.replace(content, key, map.get(key));
						File.saveContent(oldPath, content);
					}
					break;
				}
			}
			var newPath = defDir + dir;
			if (newPath != oldPath)
			{
				Sys.println("renaming (" + oldPath + ") to (" + newPath + ".xml)");
				FileSystem.rename(oldPath, newPath+".xml");
			}
		}
		
		var files = ["defender.xml", "defender_skills.xml", "heroes.xml"];
		
		for (f in files)
		{
			var defFile = dir + "/assets/demo/xml/" + f;
			var content = FileSystem.exists(defFile) ? File.getContent(defFile) : "";
			for (key in map.keys())
			{
				var lowerKey = key.toLowerCase();
				var lowerValue = map.get(key).toLowerCase();
				var upperKey = key.toUpperCase();
				var upperValue = map.get(key).toUpperCase();
				var nameKey = nameify(key);
				var nameValue = nameify(map.get(key));
				if (content.indexOf(lowerKey) != -1 || content.indexOf(upperKey) != -1 || content.indexOf(nameKey) != -1)
				{
					content = StringTools.replace(content, lowerKey, lowerValue);
					content = StringTools.replace(content, upperKey, upperValue);
					content = StringTools.replace(content, nameKey, nameValue);
					Sys.println("replacing (" + key + ") with (" + map.get(key) + ") in " + defFile);
				}
				File.saveContent(defFile, content);
			}
		}
		
		var path = dir + "/assets/demo/tables";
		for (key in map.keys())
		{
			var value = map.get(key);
			var file = path + "/" + key + ".tsv";
			if (FileSystem.exists(file))
			{
				var newFile = path + "/" + value+".tsv";
				FileSystem.rename(file, newFile);
				Sys.println("renaming(" + file+") to (" + newFile+")");
			}
		}
	}
	
	private static function nameify(str:String):String
	{
		str = str.toLowerCase();
		str = StringTools.replace(str, "_", " ");
		var arr = str.split(" ");
		for (i in 0...arr.length)
		{
			var s = arr[i];
			s = s.substr(0, 1).toUpperCase() + s.substr(1, s.length);
			arr[i] = s;
		}
		return arr.join(" ");
	}
	
}