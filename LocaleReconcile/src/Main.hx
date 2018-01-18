package;
import firetongue.CSV;
import firetongue.TSV;
import haxe.Utf8;
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
		if (args == null || args.length < 4)
		{
			usage();
			return;
		}
		
		var command = args[0];
		
		if (command == "reconcile")
		{
			commandReconcile(args);
		}
		else if (command == "findholes")
		{
			commandFindHoles(args);
		}
		else if (command == "construct")
		{
			commandConstruct(args);
		}
	}
	
	/*****************/
	
	public function commandConstruct(args:Array<String>)
	{
		var oldDir    = args[1];
		var diffDir   = args[2];
		var outputDir = args[3];
		
		var locales = [];
		
		var oldFiles = getFileNames(oldDir);
		var diffFiles = getFileNames(diffDir);
		
		var constructedFiles = constructFiles(oldFiles, diffFiles);
		
		writeFiles(outputDir, constructedFiles);
	}
	
	public function constructFiles(old:Array<String>, diff:Array<String>):Array<{filename:String,data:String}>
	{
		var files = [];
		
		var oldFiles = getFileContents(old);
		var diffFiles = getFileContents(diff);
		
		for (i in 0...old.length)
		{
			var oldFile:TSV = new TSV(oldFiles[i]);
			var diffFile:TSV = null;
			
			for (j in 0...diff.length)
			{
				if (strip(old[i]) == strip(diff[j]))
				{
					diffFile = new TSV(diffFiles[j]);
					break;
				}
			}
			
			if (diffFile != null)
			{
				files.push(
					{
						filename:strip(old[i])+".tsv",
						data:applyDiff(oldFile, diffFile)
					}
				);
			}
		}
		
		return files;
	}
	
	public function applyDiff(old:TSV, diff:TSV):String
	{
		var comparison:Comparison = comparisonFromDiff(diff);
		
		var output:String = "";
		for (i in 0...comparison.fields.length)
		{
			output += comparison.fields[i];
			if (i != comparison.fields.length - 1)
			{
				output += "\t";
			}
		}
		
		for (i in 0...old.grid.length)
		{
			var row = old.grid[i];
			
			var flag = (row != null && row.length > 0) ? row[0] : "";
			
			if (flag != "" && flag != null)
			{
				//DELETED:
				var deleted = false;
				for (row in comparison.deleted)
				{
					if (row != null && row.length > 0 && row[0] == flag)
					{
						deleted = true;
					}
				}
				
				if (deleted) continue;
				
				output += "\n" + flag + "\t";
				
				//CHANGED:
				if (comparison.changed.exists(flag))
				{
					var change = comparison.changed.get(flag);
					for (j in 0...change.length)
					{
						output += change[j].b;
						if (j != row.length - 1)
						{
							output += "\t";
						}
					}
				}
				else
				{
					for (j in 1...row.length)
					{
						output += row[j];
						if (j != row.length - 1)
						{
							output += "\t";
						}
					}
				}
			}
		}
		
		//INSERTED:
		for (i in 0...comparison.inserted.length)
		{
			var row = comparison.inserted[i];
			output += "\n" + row.join("\t");
		}
		
		return output;
	}
	
	public function comparisonFromDiff(diff:TSV):Comparison
	{
		var comparison:Comparison = {
			name:"",
			fields:diff.fields.copy(),
			deleted:[],
			inserted:[],
			changed:new Map<String,Array<StringPair>>(),
			changedContext:null,
			totalWords:0,
		}
		
		var state = "";
		var changeFlag:String = "";
		var changeRows:Array<Array<String>> = null;
		
		for (i in 0...diff.grid.length)
		{
			var row = diff.grid[i];
			
			var flag = (row != null && row.length > 0) ? row[0] : "";
			
			if (flag != "" && flag != null)
			{
					 if (flag.indexOf("DELETED:")  == 0)	{ state = "deleted"; continue; }
				else if (flag.indexOf("INSERTED:") == 0)	{ state = "inserted"; continue; }
				else if (flag.indexOf("CHANGED:") == 0)		{ state = "changed"; continue; }
				else if (flag.indexOf("METRICS:") == 0)		{ state = "metrics"; continue; }
				
				switch(state)
				{
					case "metrics": //do nothing
					case "deleted": comparison.deleted.push(row.copy());
					case "inserted": comparison.inserted.push(row.copy());
					case "changed":
						if (flag.indexOf("  old") != -1 || flag.indexOf("  new") != -1)
						{
							if (changeRows == null)
							{
								changeRows = [];
							}
							//get all the "old,new,old(loc),new(loc)" rows & store them
							changeRows.push(row);
						}
						else
						{
							if (changeRows != null && changeFlag != "")
							{
								//we've stored up change rows & hit a new flag
								
								var finalPairs = [];
								
								var origAs = [];
								var origBs = [];
								var locAs = [];
								var locBs = [];
								
								for (cr in changeRows)
								{
									var crflag = cr[0];
									
									//Get the original english diffs
									if (crflag.indexOf("old") != -1 && crflag.indexOf("old(") == -1)
									{
										for (j in 1...cr.length)
										{
											origAs.push(cr[j]);
										}
									}
									else if (crflag.indexOf("new") != -1 && crflag.indexOf("new(") == -1)
									{
										for (j in 1...cr.length)
										{
											origBs.push(cr[j]);
										}
									}
									
									//Get the localized diffs
									if (crflag.indexOf("old(") != -1)
									{
										for (j in 1...cr.length)
										{
											locAs.push(cr[j]);
										}
									}
									else if (crflag.indexOf("new(") != -1)
									{
										for (j in 1...cr.length)
										{
											locBs.push(cr[j]);
										}
									}
								}
								
								var len = Std.int(Math.max(Math.max(Math.max(origAs.length, origBs.length), locAs.length), locBs.length));
								
								for (i in 0...len)
								{
									var origA = origAs.length > i ? origAs[i] : null;
									var origB = origBs.length > i ? origBs[i] : null;
									var locA =   locAs.length > i ? locAs[i]  : null;
									var locB =   locBs.length > i ? locBs[i]  : null;
									
									var final = {a:"", b:""};
									
									if (origA != null && origB != null)
									{
										if (locA != null && locB != null)
										{
											final.a = locA;
											final.b = locB;
											if (locB == "~~~")
											{
												final.b = locA;
											}
											if (origB == "~~~" || origB == origA)
											{
												final.b = locA;
											}
										}
										else
										{
											if (origB == "~~~" || origB == origA)
											{
												final.b = origA;
											}
											else
											{
												final.b = origB;
											}
										}
									}
									
									finalPairs.push(final);
								}
								
								comparison.changed.set(changeFlag, finalPairs);
							}
							
							//update to the new flag & reset the change rows
							changeFlag = flag;
							changeRows = null;
						}
				}
			}
		}
		
		return comparison;
	}
	
	public function writeFiles(dir:String, files:Array<{filename:String,data:String}>)
	{
		for (file in files)
		{
			var fileDir = dir + "/" + file.filename;
			writeStr(file.data, fileDir);
		}
	}
	
	/*****************/
	
	public function commandFindHoles(args:Array<String>)
	{
		var inputDir1 = args[1];
		var inputDir2 = args[2];
		var outputDir = args[3];
		
		var files1:Array<String> = getFileNames(inputDir1);
		var files2:Array<String> = getFileNames(inputDir2);
		
		var holes = findHoles(files1, files2);
		
		writeComparisons(outputDir, holes, false);
	}
	
	public function commandReconcile(args:Array<String>)
	{
		var inputDir1 = args[1];
		var inputDir2 = args[2];
		var outputDir = args[3];
		
		var locales = [];
		var localeFiles = [];
		
		if (args.length > 4)
		{
			for (i in 4...args.length)
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
	
	public function writeComparisons(dir:String, arr:Array<Comparison>, changes:Bool=true, insertions:Bool=true, deletions:Bool=true)
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
			
			if (deletions)
			{
				file += "\nDELETED:\n";
				
				for (del in d.deleted)
				{
					file += del.join("\t") + "\n";
					metrics.wordsDeleted += countWords(del);
				}
			}
			
			if (insertions)
			{
				file += "\nINSERTED:\n\n";
				
				for (ins in d.inserted)
				{
					file += ins.join("\t") + "\n";
					metrics.wordsInserted += countWords(ins);
				}
			}
			
			if (changes)
			{
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
			}
			
			file += "\nMETRICS:\n";
			file += "\nOLD WORDS           : " + diff.totalWords;
			if (insertions)
			{
				file += "\nLINE INSERTED WORDS : " + metrics.wordsInserted;
			}
			if (deletions)
			{
				file += "\nLINE DELETED WORDS  : " + metrics.wordsDeleted;
			}
			if (changes)
			{
				file += "\nLINE CHANGED WORDS  : " + metrics.wordsChanged;
			}
			file += "\n---------------------\n";
			file += "\nTOTAL WORDS         : " + (diff.totalWords + metrics.wordsInserted - metrics.wordsDeleted);
			file += "\nTOTAL *NEW* WORDS   : " + (metrics.wordsInserted + metrics.wordsChanged);
			
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
	
	public function findHoles(files1:Array<String>, files2:Array<String>):Array<Comparison>
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
				}
			}
		}
		return comparisons;
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
							if (localeFile == null || localeFile.grid == null) continue;
							for (locArr in localeFile.grid)
							{
								if (locArr == null) continue;
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
			changedContext:new Map<String,Array<Array<String>>>(),
			totalWords:0
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
			
			diff.totalWords += countWords(arr);
			
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
	
	public function utf8IndexOf(str:String, char:String):Int
	{
		var charCode:Int = Utf8.charCodeAt(char, 0);
		var returnVal = -1;
		var i:Int = 0;
		Utf8.iter(str, function(c:Int):Void{
			if (c == charCode)
			{
				returnVal = i;
			}
			i++;
		});
		return returnVal;
	}
	
	public function utf8LastIndexOf(str:String, char:String):Int
	{
		var charCode = Utf8.charCodeAt(char, 0);
		var last:Int = -1;
		var i:Int = 0;
		Utf8.iter(str, function(c:Int):Void{
			if (c == charCode)
			{
				last = i;
			}
			i++;
		});
		return last;
	}
	
	public function utf8has(str:String, char:String):Bool
	{
		return utf8IndexOf(str, char) != -1;
	}
	
	private inline function strip(str:String):String
	{
		if (utf8has(str,"."))
		{
			str = Utf8.sub(str, 0, utf8IndexOf(str, "."));
		}
		if (utf8has(str,"/"))
		{
			str = Utf8.sub(str, utf8LastIndexOf(str, "/") + 1, Utf8.length(str));
		}
		if (utf8has(str,"\\"))
		{
			str = Utf8.sub(str, utf8LastIndexOf(str, "\\") + 1, Utf8.length(str));
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
			File.saveContent(name, str);
		}
		catch (msg:String)
		{
			error = true;
			Sys.print("ERROR! (" + msg + ")\n");
		}
	}
	
	public function usage():Void
	{
		var usage1:String = "usage 1: locale reconcile newdir olddir outputdir <?locale1> <?locale2> ... <?localen> ex: localereconcile new old output de fr";
		var usage2:String = "usage 2: locale construct olddir diffdir outputdir ex: locale construct de de_trans output";
		var usage3:String = "usage 3: locale findholes dir1 dir2 outputdir ex: locale findholes en de output";
		Sys.println(usage1 + "\n" + usage2 + "\n" + usage3);
	}

}

typedef Comparison = {
	var name:String;
	var fields:Array<String>;
	var deleted:Array<Array<String>>;
	var inserted:Array<Array<String>>;
	var changed:Map<String,Array<StringPair>>;
	var changedContext:Map<String,Array<Array<String>>>;
	var totalWords:Int;
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