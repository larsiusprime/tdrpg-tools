package;
import firetongue.TSV;
import haxe.xml.Fast;
import sys.FileSystem;
import sys.io.File;
import sys.io.FileOutput;

/**
 * ...
 * @author 
 */
class U
{

	private static var replaceFlags   = ["$MCG", "$BER", "$RAN",  "$HEA",  "$MAG",   "$KNI",   "$DRA", "$N$N$N", "$N$N", "$N", "<N>", "<LQ>", "<RQ>", "<Q>", "<C>"];
	private static var replaceStrings = ["Azra", "Slak", "Ketta", "Bakal", "Wrenna", "Markos", "Niru", "\n",     "\n",   "\n", "\n",  "“",    "”",    '"',    "," ];
	
	public function new() 
	{
		
	}
	
	public static function getLine(flag:String, tsv:TSV):String
	{
		var line = tsvGet(flag, tsv);
		return doReplace(line);
	}
	
	public static function doReplace(line:String):String
	{
		for (i in 0...replaceFlags.length)
		{
			var flag = replaceFlags[i];
			while (line.indexOf(flag) != -1)
			{
				line = StringTools.replace(line, flag, replaceStrings[i]);
			}
			if (line.indexOf("*") == 0)
			{
				line = line.substr(1, line.length - 1);
			}
		}
		return line;
	}
	
	public static function tsvGetLineNum(flag:String, tsv:TSV):Int
	{
		var i = 0;
		for (row in tsv.grid)
		{
			if (row[0] == flag)
			{
				return i;
			}
			i++;
		}
		return -1;
	}
	
	public static function tsvGet(flag:String, tsv:TSV):String
	{
		for (row in tsv.grid)
		{
			if (row[0] == flag)
			{
				return row[1];
			}
		}
		return "";
	}
	
	public static function xmlStr(xml:Fast, att:String, lower:Bool = false, def:String = ""):String
	{
		if (xml.x.exists(att))
		{
			var str = xml.x.get(att);
			if (lower){
				str = str.toLowerCase();
			}
			return str;
		}
		return def;
	}
	
	public static function getFile(name:String):String
	{
		if (FileSystem.exists(name) && FileSystem.isDirectory(name) == false)
		{
			return (File.getContent(name));
		}
		return "";
	}
	
	public static function writeStr(str:String, name:String):Void
	{
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
	
}