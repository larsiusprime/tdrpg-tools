package;
import firetongue.CSV;
import firetongue.TSV;
import haxe.ds.ArraySort;
import lime.app.Application;
import sys.FileSystem;
import sys.io.File;
import sys.io.FileOutput;
import firetongue.FireTongue;

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
		if (args == null || args.length < 3)
		{
			usage();
			return;
		}
		
		var inputDir1 = args[0];
		var inputDir2 = args[1];
		var outputDir = args[2];
		
		var locales = [];
		var localeFiles = [];
		
		if (args.length > 3)
		{
			for (i in 3...args.length)
			{
				locales.push(args[i]);
				localeFiles.push(getFileNames(args[i]));
			}
		}
		
		var files1:Array<String> = getFileNames(inputDir1);
		var files2:Array<String> = getFileNames(inputDir2);
		
		var comparisons = reconcile(files1, files2, locales, localeFiles);
		
		writeComparisons(outputDir, comparisons);
	}
	
	public function writeComparisons(dir:String, arr:Array<Comparison>)
	{
		var total:Metrics = {
			wordsInserted:0,
			wordsDeleted:0,
			wordsChanged:0
		}
		
		for (diff in arr)
		{
			var metrics:Metrics = {
				wordsInserted:0,
				wordsDeleted:0,
				wordsChanged:0
			}
		
			var d:Comparison = diff;
			var file:String = "";
			
			file += d.fields.join("\t") + "\n";
			
			file += "\nDELETED:\n";
			
			for (del in d.deleted)
			{
				file += del.join("\t") + "\n";
				metrics.wordsDeleted += countWords(del);
			}
			
			file += "\nINSERTED:\n\n";
			
			for (ins in d.inserted)
			{
				file += ins.join("\t") + "\n";
				metrics.wordsInserted += countWords(ins);
			}
			
			file += "\nCHANGED:\n\n";
			
			for (change in d.changed.keys())
			{
				var list = d.changed.get(change);
				file += change + "\n";
				file += "  old    \t" + joinA(list, "\t") + "\n";
				file += "  new    \t" + joinB(list, "\t") + "\n";
				metrics.wordsChanged += countWordsChanged(list);
				
				for (locale in d.changedContext.keys())
				{
					var arr = d.changedContext.get(locale);
					for (i in 0...arr.length)
					{
						var line = arr[i];
						if (line != null && line.length > 0)
						{
							if (line[0] == change)
							{
								var line2 = [for (i in 1...line.length) line[i]];
								file += "  old(" + locale+")\t" + line2.join("\t") +"\n";
								file += "  new(" + locale+")\t\n";
								break;
							}
						}
					}
				}
			}
			
			file += "\nMETRICS:\n";
			file += "\nLINE INSERTION WORDS: " + metrics.wordsInserted;
			file += "\nLINE DELETED WORDS  : " + metrics.wordsDeleted;
			file += "\nLINE CHANGED WORDS  : " + metrics.wordsChanged;
			file += "\n---------------------\n";
			file += "\nTOTAL NEW WORD COUNT: " + (metrics.wordsInserted + metrics.wordsChanged);
			
			writeStr(file, dir + "/" + d.name+".tsv");
			
			total.wordsInserted += metrics.wordsInserted;
			total.wordsDeleted  += metrics.wordsDeleted;
			total.wordsChanged  += metrics.wordsChanged;
		}
		
		Sys.println("word metrics: INSERTED: " + total.wordsInserted + " DELETED: " + total.wordsDeleted + " CHANGED: " + total.wordsChanged);
	}
	
	public function countWordsChanged(arr:Array<StringPair>):Int
	{
		var i = 0;
		for (p in arr)
		{
			if (p.a.indexOf("$") == 0 || p.b.indexOf("$") == 0) continue;
			if (p.a == p.b) continue;
			if (p.a == "~~~" || p.b == "~~~") continue;
			if (p.a != p.b) i++;
		}
		return i;
	}
	
	public function countWords(arr:Array<String>):Int
	{
		//var print = true;// Math.random() < 1 / 100;
		var i = 0;
		for (str in arr)
		{
			if (str.indexOf("$") == 0) continue;
			if (str == " " || str == "") continue;
			var temp = str;
			temp = StringTools.replace(temp, "\n", " ");
			temp = StringTools.replace(temp, "<N>", " ");
			temp = StringTools.replace(temp, "\r\n", " ");
			temp = StringTools.replace(temp, "     ", " ");
			temp = StringTools.replace(temp, "    ", " ");
			temp = StringTools.replace(temp, "   ", " ");
			temp = StringTools.replace(temp, "  ", " ");
			var a = temp.split(" ");
			if (a != null && a.length != 0)
			{
				i += a.length;
			}
		}
		return i;
	}
	
	public function safeJoin(arr:Array<String>, sep:String):String
	{
		var str:String = "";
		for (i in 0...arr.length)
		{
			str += (arr[i] != null) ? arr[i] : "";
			if (i != arr.length - 1)
			{
				str += sep;
			}
		}
		return str;
	}
	
	public function joinA(arr:Array<StringPair>, sep:String):String
	{
		var str:String = "";
		for (i in 0...arr.length)
		{
			str += arr[i].a;
			if (i != arr.length - 1)
			{
				str += sep;
			}
		}
		return str;
	}
	
	public function joinB(arr:Array<StringPair>, sep:String):String
	{
		var str:String = "";
		for (i in 0...arr.length)
		{
			str += arr[i].b;
			if (i != arr.length - 1)
			{
				str += sep;
			}
		}
		return str;
	}
	
	public function reconcile(files1:Array<String>, files2:Array<String>, locales:Array<String>, localeFiles:Array<Array<String>>):Array<Comparison>
	{
		var comparisons = [];
		for (i in 0...files1.length)
		{
			var file = files1[i];
			var fileSansEx = strip(file).toLowerCase();
			for (j in 0...files2.length)
			{
				var other = files2[j];
				var otherSansEx = strip(other).toLowerCase();
				
				if (otherSansEx == fileSansEx)
				{
					var comparison:Comparison = getComparison(file, other, getFile(file), getFile(other));
					comparisons.push(comparison);
					
					for (k in 0...locales.length)
					{
						var locale = locales[k];
						
						var fileID = "";
						for (l in 0...localeFiles[k].length)
						{
							if (strip(localeFiles[k][l]) == strip(file))
							{
								fileID = localeFiles[k][l];
								break;
							}
						}
						
						var theFile = getFile(fileID);
						var localeFile = getSheet(fileID, theFile);
						
						var context = [];
						for (key in comparison.changed.keys())
						{
							for (locArr in localeFile.grid)
							{
								var locFirst = (locArr != null && locArr.length > 0) ? locArr[0] : "";
								if (locFirst == key)
								{
									context.push(locArr.copy());
									break;
								}
							}
						}
						comparison.changedContext.set(locale, context);
					}
				}
			}
		}
		return comparisons;
	}
	
	public function getComparison(file1:String, file2:String, data1:String, data2:String):Comparison
	{
		var diff:Comparison = {
			name:strip(file1).toLowerCase(),
			fields:[],
			deleted:[],
			inserted:[],
			changed:new Map<String,Array<StringPair>>(),
			changedContext:new Map<String,Array<Array<String>>>()
		};
		
		var sheet1 = getSheet(file1, data1);
		var sheet2 = getSheet(file2, data2);
		
		ArraySort.sort(sheet1.grid, sortSheet);
		ArraySort.sort(sheet2.grid, sortSheet);
		
		diff.fields = sheet1.fields.copy();
		
		//Check for insertions & changes
		for (arr in sheet1.grid)
		{
			if (arr == null || arr.length == 0) continue;
			
			var first1 = arr[0];
			var match = false;
			var changed = false;
			var changes = null;
			
			for (otherArr in sheet2.grid)
			{
				if (otherArr == null || otherArr.length == 0) continue;
				
				var first2 = otherArr[0];
				if (first2 == first1)
				{
					match = true;
					changes = [];
					var len1 = arr.length;
					var len2 = otherArr.length;
					var maxLen = Std.int(Math.max(len1, len2));
					for (i in 1...maxLen)
					{
						var val1 = i < len1 ? arr[i] : "";
						var val2 = i < len2 ? otherArr[i] : "";
						
						if (val1 == val2)
						{
							val1 = noChangeToken();
						}
						else
						{
							changed = true;
						}
						
						var strPair = {
							a: val2,
							b: val1
						};
						
						changes.push(strPair);
					}
					break;
				}
			}
			
			if (changed)
			{
				var allIdentical = true;
				for (pair in changes)
				{
					if (pair.a != pair.b)
					{
						allIdentical = false;
					}
				}
				if (allIdentical)
				{
					changed = false;
				}
			}
			
			if (!match)
			{
				diff.inserted.push(arr.copy());
			}
			else if(changed)
			{
				diff.changed.set(first1, changes);
			}
		}
		
		//Check for deletions
		for (otherArr in sheet2.grid)
		{
			if (otherArr == null || otherArr.length == 0) continue;
			
			var first2 = otherArr[0];
			var match = false;
			
			for (arr in sheet1.grid)
			{
				if (arr == null || arr.length == 0) continue;
				
				var first1 = arr[0];
				if (first1 == first2)
				{
					match = true;
					break;
				}
			}
			
			if (!match)
			{
				diff.deleted.push(otherArr.copy());
			}
		}
		
		return diff;
	}
	
	private function noChangeToken():String
	{
		return "~~~";
	}
	
	private function sortSheet(a:Array<String>, b:Array<String>):Int
	{
		if (a == null && b != null) return  1;
		if (a != null && b == null) return -1;
		if (a == null && b == null) return  0;
		if (a.length == 0 && b.length != 0) return  1;
		if (a.length != 0 && b.length == 0) return -1;
		if (a.length == 0 && b.length == 0) return  0;
		if (a[0] > b[0]) return  1;
		if (a[0] < b[0]) return -1;
		return 0;
	}
	
	private function getSheet(filename:String, data:String):CSV
	{
		if(filename.indexOf(".tsv") != -1)
		{
			return new TSV(data);
		}
		return new CSV(data);
	}
	
	private inline function strip(str:String):String
	{
		if (str.indexOf(".") != -1)
		{
			str = str.substr(0, str.indexOf("."));
		}
		if (str.indexOf("/") != -1)
		{
			str = str.substring(str.lastIndexOf("/") + 1, str.length);
		}
		if (str.indexOf("\\") != -1)
		{
			str = str.substring(str.lastIndexOf("//") + 1, str.length);
		}
		return str;
	};
	
	public function getFile(name:String):String
	{
		if (FileSystem.exists(name) && FileSystem.isDirectory(name) == false)
		{
			return (File.getContent(name));
		}
		return "";
	}
	
	public function getFileContents(names:Array<String>):Array<String>
	{
		var data = [];
		for (name in names)
		{
			if (FileSystem.exists(name) && FileSystem.isDirectory(name) == false)
			{
				data.push(File.getContent(name));
			}
		}
		return data;
	}
	
	public function getFileNames(dir:String):Array<String>
	{
		var arr = [];
		if (FileSystem.exists(dir) && FileSystem.isDirectory(dir))
		{
			arr = FileSystem.readDirectory(dir);
			for (i in 0...arr.length)
			{
				arr[i] = dir + "/" + arr[i].toLowerCase();
			}
		}
		return arr;
	}
	
	public function deleteFile(str:String):Void
	{
		if (FileSystem.exists(str))
		{
			FileSystem.deleteFile(str);
		}
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
		Sys.println("usage: localereconcile newdir olddir outputdir <?locale1> <?locale2> ... <?localen> ex: localereconcile new old output de fr");
	}

}

typedef Comparison = {
	var name:String;
	var fields:Array<String>;
	var deleted:Array<Array<String>>;
	var inserted:Array<Array<String>>;
	var changed:Map<String,Array<StringPair>>;
	var changedContext:Map<String,Array<Array<String>>>;
}

typedef Metrics = {
	var wordsInserted:Int;
	var wordsDeleted:Int;
	var wordsChanged:Int;
}

typedef StringPair = {
	var a:String;
	var b:String;
}