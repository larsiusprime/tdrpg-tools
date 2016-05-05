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
	
	public static var command:String;
	public static var input:String;
	public static var output:String;
	
	public static var params:Array<String>;
	
	static function main() 
	{
		var args:Array<String> = Sys.args();
		params = [];
		doStuff(args);
	}
	
	static function doStuff(args:Array<String>):Void {
		Sys.println("args = " + args);
		if (args != null && args.length == 3)
		{
			var inFile:String = args[0];
			var outFile:String = args[1];
			var isDemo:Bool = args[2].toLowerCase() == "demo";
			var isFull:Bool = args[2].toLowerCase() == "full" || isDemo == false;
			
			if (!isDemo && !isFull) {
				usage();
			}
			else {
				var raw = File.getContent(inFile);
				raw = fixXML(raw, isDemo, isFull);
				File.saveContent(outFile, raw);
				Sys.println("saved cropped file as " + outFile);
			}
		}
		else
		{
			usage();
		}
	}
	
	static function fixXML(rawString:String, isDemo:Bool, isFull:Bool):String
	{
		var mark:String = isDemo ? "FULL" : (isFull ? "DEMO" : "");
		var self:String = isDemo ? "DEMO" : (isFull ? "FULL" : "");
		
		var startMark:String = "<!--IF:" + mark + "-->";
		var endMark:String = "<!--ENDIF:" + mark + "-->";
		
		var selfStartMark:String = "<!--IF:" + self + "-->";
		var selfEndMark:String = "<!--ENDIF:" + self + "-->";
		
		while (rawString.indexOf(startMark) != -1) {
			var starti:Int = rawString.indexOf(startMark);
			var endi:Int = rawString.indexOf(endMark);
			
			var before:String = rawString.substring(0, starti);
			var end:String = rawString.substring(endi+endMark.length+1, rawString.length);
			
			rawString = before + end;
			
			Sys.println("removed " + (endi-starti) + " characters...");
		}
		
		while (rawString.indexOf(selfStartMark) != -1) {
			rawString = StringTools.replace(rawString, selfStartMark, "");
		}
		
		while (rawString.indexOf(selfEndMark) != -1) {
			rawString = StringTools.replace(rawString, selfEndMark, "");
		}
		
		return rawString;
	}
	
	public static function usage():Void
	{
		Sys.println("usage: xml_fix in.xml out.xml demo");
	}
	
}