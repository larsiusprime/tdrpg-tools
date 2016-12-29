package;

import firetongue.TSV;
import haxe.Utf8;
import java.Lib;
import sys.FileSystem;
import sys.io.File;
import unifill.Unifill;

/**
 * ...
 * @author 
 */
class Main 
{
	
	static function main() 
	{
		var args = Sys.args();
		if (args == null || args.length < 2){
			usage();
			return;
		}
		var a = args[0];
		var b= args[1];
		
		var fileA = getFile(a);
		var fileB = getFile(b);
		
		if (fileA == fileB)
		{
			Sys.println("1");
		}
		else
		{
			var tsvA = new TSV(fileA);
			var tsvB = new TSV(fileB);
			
			var equal = areTSVEqual(tsvA, tsvB);
			if (equal)
			{
				Sys.println("2");
			}
			else
			{
				Sys.println("0");
			}
		}
	}
	
	private static function areTSVEqual(a:TSV, b:TSV):Bool
	{
		if ((a.fields == null) != (b.fields == null)) return false;
		
		if (a.fields != null && b.fields != null)
		{
			if (a.fields.length != b.fields.length) return false;
			
			for (i in 0...a.fields.length)
			{
				if (a.fields[i] != b.fields[i]) return false;
			}
			
			if ((a.grid == null) != (b.grid == null)) return false;
			if (a.grid.length != b.grid.length) return false;
			
			for (yy in 0...a.grid.length)
			{
				if ((a.grid[yy] == null) != (b.grid[yy] == null)) return false;
				
				if ((a.grid[yy] != null) && (b.grid[yy] != null))
				{
					if ((a.grid[yy].length != b.grid[yy].length)) return false;
					
					for (xx in 0...a.grid[yy].length)
					{
						if ((a.grid[yy][xx] == null) != (b.grid[yy][xx] == null)) return false;
						
						if ((a.grid[yy][xx] != null && (b.grid[yy][xx] != null)))
						{
							if ((a.grid[yy][xx].length != b.grid[yy][xx].length)) return false;
							
							var aValue = a.grid[yy][xx];
							var bValue = b.grid[yy][xx];
							
							if (aValue != bValue) return false;
						}
					}
				}
			}
		}
		return true;
	}
	
	private static function getFile(path:String):String
	{
		if (FileSystem.exists(path))
		{
			try{
				return File.getContent(path);
			}
			catch (msg:Dynamic)
			{
				error(msg);
			}
		}
		else
		{
			error("file (" + path + ") does not exist");
		}
		return "";
	}
	
	private static function error(msg:Dynamic)
	{
		Sys.println("ERROR: " + msg);
	}
	
	private static function usage()
	{
		Sys.println("usage: tsvCompare <file_1> <file_2>\nex: tsvCompare a.tsv b.tsv\noutputs: 0 if unequal, 1 if equal, 2 if text is equal but not binary equal"); 
	}
	
}