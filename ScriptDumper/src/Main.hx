package;
import firetongue.TSV;
import flash.display.PixelSnapping;
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
	public function new() 
	{
		super();
		doStuff(Sys.args());
		Sys.exit(0);
	}
	
	public function doStuff(args:Array<String>):Void
	{
		if (args == null || args.length < 4)
		{
			usage();
			return;
		}
		
		var command = args[0];
		
		var rawXml = U.getFile(args[1]);
		var rawTsv = U.getFile(args[2]);
		var xml:Fast = new Fast(Xml.parse(rawXml));
		var tsv:TSV = new TSV(rawTsv);
		
		switch(command)
		{
			case "cutscenes":
				Cutscene.process(xml, tsv, args[3]);
			case "maps":
				Maps.process(xml, tsv, args[3]);
			case "journal":
				Journal.process(xml, tsv, args[3]);
		}
	}
	
	public function usage():Void
	{
		Sys.println(
		"usage:\n"+
		"  scriptdump cutscenes <xml> <tsv> <outfile.txt>; ex: scriptdump cutscenes scripts.xml scripts.tsv scripts.txt\n" +
		"  scriptdump maps <xml> <tsv> <outfile.txt>; ex: scriptdump maps index.xml maps.tsv maps.txt\n" +
		"  scriptdump journal <xml> <tsv> <outfile.txt>; ex: scriptdump journal journal.xml journal.tsv journal.txt"
		);
	}

}