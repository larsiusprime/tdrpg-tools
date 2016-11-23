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
		doStuff(Sys.args());
		Sys.exit(0);
	}
	
	private static function usage()
	{
		Sys.println("usage: dqdialogue path/to/input/ path/to/output/");
	}
	
	public static function doStuff(args:Array<String>)
	{
		var fail = args.length < 2;
		
		if (fail)
		{
			usage();
			return;
		}
		
		var inDir = args[0];
		var outDir = args[1];
		if (FileSystem.exists(inDir))
		{
			var script = new ScriptParser();
			script.parse(inDir, outDir);
			
			var meta = new MetaParser();
			inDir = outDir + "/_temp/";
			meta.parse(inDir, outDir);
		}
		else
		{
			Sys.println("could not find directory: " + inDir);
		}
	}
}