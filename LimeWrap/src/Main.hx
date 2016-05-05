package ;
import haxe.xml.Fast;
import haxe.xml.Printer;
import sys.FileSystem;
import sys.io.File;
import sys.io.FileOutput;


/**
 * ...
 * @author larsiusprime
 */

class Main 
{
	
	static function main() 
	{
		var args:Array<String> = Sys.args();
		doStuff(args);
	}
	
	static function doStuff(args:Array<String>):Void {
		if (args != null && args.length >= 3)
		{
			var limeArgs = args.copy();
			limeArgs.splice(0, 1);
			Sys.command("lime", limeArgs);
			var afterArgs = args[0].split(",");
			Sys.command("neko", afterArgs);
		}
		else
		{
			usage();
		}
	}
	
	public static function usage():Void
	{
		Sys.println("usage: limewrap [wrap,arguments,go,here] arg1 arg2 arg3...");
	}
	
}