package;
import haxe.ds.ArraySort;
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

	public function new() 
	{
		super();
		doStuff(Sys.args());
		Sys.exit(0);
	}
	
	public function doStuff(args:Array<String>):Void
	{
		if (args == null || args.length < 2)
		{
			usage();
			return;
		}
		
		var delimeter = ",";
		if (args.length > 2)
		{
			delimeter = args[2];
		}
		
		var input = args[0];
		var output = args[1];
		
		var inputFile = getFile(input);
		
		var oldRowEnd = '"' + delimeter + "\r\n$";
		var fakeRowEnd = "####$$$$";
		var newRowEnd = "\r\n$";
		
		var oldSeparator = '"' + delimeter + '"';
		
		inputFile = inputFile.replace(oldRowEnd, fakeRowEnd);
		inputFile = inputFile.replace("\r\n", "<N>");
		inputFile = inputFile.replace("\n", "<N>");
		inputFile = inputFile.replace("\t", "<T>");
		inputFile = inputFile.replace(fakeRowEnd, newRowEnd);
		inputFile = inputFile.replace(oldSeparator, "\t");
		if (inputFile.indexOf('"') == 0)
		{
			inputFile = inputFile.substr(1, inputFile.length);
		}
		
		if (input.indexOf(".csv") == -1){ usage(); return; }
		if (output.indexOf(".tsv") == -1){ usage(); return; }
		
		writeStr(inputFile, output);
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
		Sys.println("usage: csvtotsv <infile>.csv <outfile>.tsv <?delimeter>, ex: csvtotsv a.csv a.tsv");
	}

}