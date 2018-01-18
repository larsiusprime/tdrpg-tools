package;

import firetongue.TSV;
import haxe.Utf8;
import openfl.Assets;
import openfl.display.Sprite;
import openfl.Lib;
import openfl.geom.Point;
import sys.FileSystem;
import sys.io.File;
import unifill.CodePoint;
import unifill.Unifill;

/**
 * ...
 * @author 
 */
class Main extends Sprite 
{
	public function new() 
	{
		super();
		countFiles();
	}
	
	private function countFiles()
	{
		var locs  = ["ko-KR"];//["cs-CZ", "de-DE", "en-US", "es-ES", "fr-FR", "it-IT", "ja-JP", "ko-KR", "ru-RU", "zh-HANS", "zh-HANT"];
		var files = ["achievements", "bonus", "core", "defender", "goodies", "mods", "status_effects", "items", "enemy", "enemy_plus", "maps", "scripts", "journal", "journal2", "journal3"];
		for (loc in locs)
		{
			var allMap = new Map<Int,CharacterEntry>();
			for (file in files)
			{
				var fileMap = new Map<Int, CharacterEntry>();
				if (file == "items")
				{
					File.saveContent("out/" + loc + "/_all_sans_items_enemy_maps_script_journal.txt", printMap(allMap));
					File.saveContent("out/" + loc + "/_all_sans_items_enemy_maps_script_journal_range.txt", printRange(allMap));
				}
				if (file == "enemy")
				{
					File.saveContent("out/" + loc + "/_all_sans_enemy_maps_script_journal.txt", printMap(allMap));
					File.saveContent("out/" + loc + "/_all_sans_enemy_maps_script_journal_range.txt", printRange(allMap));
				}
				if (file == "maps")
				{
					File.saveContent("out/" + loc + "/_all_sans_maps_script_journal.txt", printMap(allMap));
					File.saveContent("out/" + loc + "/_all_sans_maps_script_journal_range.txt", printRange(allMap));
				}
				if (file == "scripts")
				{
					File.saveContent("out/" + loc + "/_all_sans_script_journal.txt", printMap(allMap));
					File.saveContent("out/" + loc + "/_all_sans_script_journal_range.txt", printRange(allMap));
				}
				if (file == "journal")
				{
					File.saveContent("out/" + loc + "/_all_sans_journal.txt", printMap(allMap));
					File.saveContent("out/" + loc + "/_all_sans_journal_range.txt", printRange(allMap));
				}
				
				var asset = Assets.getText("assets/" + loc + "/" + file+".tsv");
				
				var tsv = new TSV(asset);
				
				var output = "";
				
				output = countChars(file, tsv, allMap, fileMap);
				
				FileSystem.createDirectory("out");
				FileSystem.createDirectory("out/"+loc);
				File.saveContent("out/" + loc + "/" + file+".txt", output);
				File.saveContent("out/" + loc + "/" + file+"_range.txt", printRange(fileMap));
			}
			File.saveContent("out/"+loc+"/_all.txt", printMap(allMap));
			File.saveContent("out/"+loc+"/_all_chars.txt", print100(allMap));
			File.saveContent("out/"+loc+"/_all_chars_range.txt", printRange(allMap));
		}
	}
	
	private function countChars(file:String, tsv:TSV, allMap:Map<Int,CharacterEntry>, map:Map<Int,CharacterEntry>):String
	{
		var output = "";
		for (row in tsv.grid)
		{
			var c = 0;
			var flag = "";
			for (col in row)
			{
				if (c == 0)
				{
					flag = col;
					c++;
					continue;
				}
				Utf8.iter(col, 
					function(char:Int):Void
					{
						var entry:CharacterEntry = null;
						if (map.exists(char))
						{
							entry = map.get(char);
						}
						else
						{
							entry = new CharacterEntry(char);
						}
						entry.count++;
						entry.add(flag, col, file);
						map.set(char, entry);
					}
				);
				c++;
			}
		}
		for (key in map.keys())
		{
			var entry:CharacterEntry = null;
			if (allMap.exists(key))
			{
				entry = allMap.get(key);
			}
			else
			{
				entry = new CharacterEntry(key);
			}
			entry.addEntry(map.get(key));
			allMap.set(key, entry);
		}
		return printMap(map);
	}
	
	private function printRange(map:Map<Int,CharacterEntry>):String
	{
		var output = "";
		var arr:Array<CharacterEntry> = [];
		var keys = 0;
		for (key in map.keys())
		{
			var entry = map.get(key);
			var newEntry = new CharacterEntry(entry.code);
			newEntry.addEntry(entry);
			arr.push(newEntry);
			keys++;
		}
		arr.sort(function (a:CharacterEntry, b:CharacterEntry)
			{
				if (a.code < b.code) return -1;
				if (a.code > b.code) return  1;
				return 0;
			}
		);
		
		var last = 0;
		var lastRange = "";
		var ranges = [];
		
		for (i in 0...arr.length)
		{
			var entry = arr[i];
			var c:CodePoint = cast entry.code;
			var ci = c.toInt();
			
			if (lastRange == "")
			{
				lastRange = Std.string(ci);
				if (ci == arr.length - 1)
				{
					ranges.push(lastRange);
				}
			}
			else if (ci != last + 1)
			{
				if (lastRange == Std.string(last))
				{
					ranges.push(lastRange);
				}
				else
				{
					ranges.push(lastRange + "-" + last);
				}
				lastRange = "";
			}
			else
			{
				if (ci == arr.length - 1)
				{
					ranges.push(lastRange + "-" + last);
				}
			}
			last = ci;
		}
		
		var blah = "chars=";
		for (i in 0...arr.length)
		{
			blah += arr[i].code;
			if (i != 0 && i % 10 == 0)
			{
				blah += "\nchars=";
			}
			else
			{
				blah += ",";
			}
		}
		
		/*
		var line = "chars=";
		for (i in 0...ranges.length)
		{
			var oldLine = line;
			
			line += ranges[i];
			if (i % 5 == 0)
			{
				line += "\nchars=";
			}
			else
			{
				line += ",";
			}
		}
		*/
		
		output = blah;
		
		return output;
	}
	
	private function print100(map:Map<Int,CharacterEntry>):String
	{
		var output = "";
		var arr:Array<CharacterEntry> = [];
		for (key in map.keys())
		{
			var entry = map.get(key);
			var newEntry = new CharacterEntry(entry.code);
			newEntry.addEntry(entry);
			arr.push(newEntry);
		}
		arr.sort(function (a:CharacterEntry, b:CharacterEntry)
			{
				if (a.flags.length > b.flags.length) return -1;
				if (a.flags.length < b.flags.length) return 1;
				if (a.files.length > b.files.length ) return -1;
				if (a.files.length < b.files.length ) return 1;
				if (a.words.length > b.words.length) return -1;
				if (a.words.length < b.words.length) return  1;
				if (a.count > b.count) return -1;
				if (a.count < b.count) return  1;
				if (a.code < b.code) return -1;
				if (a.code > b.code) return  1;
				var achar = a.files.length == 0 ? a.files[0].charCodeAt(0) : -1;
				var bchar = b.files.length == 0 ? b.files[0].charCodeAt(0) : -1;
				if (achar > bchar) return -1;
				if (achar < bchar) return 1;
				var aFlagStr = a.flags[0];
				var bFlagStr = b.flags[0];
				if (aFlagStr < bFlagStr) return -1;
				if (aFlagStr > bFlagStr) return 1;
				return 0;
			}
		);
		for (entry in arr)
		{
			var c:CodePoint = cast entry.code;
			var char = c.toString();
			output += char;
		}
		return output;
	}
	
	private function printMap(map:Map<Int,CharacterEntry>):String
	{
		var output = "";
		var arr:Array<CharacterEntry> = [];
		for (key in map.keys())
		{
			var entry = map.get(key);
			var newEntry = new CharacterEntry(entry.code);
			newEntry.addEntry(entry);
			arr.push(newEntry);
		}
		
		arr.sort(function (a:CharacterEntry, b:CharacterEntry)
			{
				if (a.flags.length > b.flags.length) return -1;
				if (a.flags.length < b.flags.length) return 1;
				if (a.files.length > b.files.length ) return -1;
				if (a.files.length < b.files.length ) return 1;
				if (a.words.length > b.words.length) return -1;
				if (a.words.length < b.words.length) return  1;
				if (a.count > b.count) return -1;
				if (a.count < b.count) return  1;
				if (a.code < b.code) return -1;
				if (a.code > b.code) return  1;
				var achar = a.files.length == 0 ? a.files[0].charCodeAt(0) : -1;
				var bchar = b.files.length == 0 ? b.files[0].charCodeAt(0) : -1;
				if (achar > bchar) return -1;
				if (achar < bchar) return 1;
				return 0;
			}
		);
		
		var set50 = "";
		var set75 = "";
		var set90 = "";
		var set95 = "";
		var set99 = "";
		var set100= "";
		
		var total = 0;
		
		for (e in arr)
		{
			total += e.flags.length;
		}
		
		var running = 0;
		
		var percent = 0.0;
		for (e in arr)
		{
			running += e.flags.length;
			var c:CodePoint = cast e.code;
			var char = c.toString();
			output += char + " ("+c.toInt()+") f:" + Std.int(e.flags.length) + " w:" + Std.int(e.words.length) + " c:" + e.count + " files:" + e.files + " flags: " + e.flags;
			output += "\n";
			if (percent < 0.50) set50 += char;
			if (percent < 0.75) set75 += char;
			if (percent < 0.90) set90 += char;
			if (percent < 0.95) set95 += char;
			if (percent < 0.99) set99 += char;
			set100 += char;
			percent = running / total;
		}
		var prefix = 
		"50 % (" + Unifill.uLength(set50) + ") = " + set50 + "\n" +
		"75 % (" + Unifill.uLength(set75) + ") = " + set75 + "\n" +
		"90 % (" + Unifill.uLength(set90) + ") = " + set90 + "\n" +
		"95 % (" + Unifill.uLength(set95) + ") = " + set95 + "\n" +
		"99 % (" + Unifill.uLength(set99) + ") = " + set99 + "\n" +
		"100% (" + Unifill.uLength(set100)+ ") = " + set100+ "\n";
		output = prefix + output;
		return output;
	}

}

class CharacterEntry
{
	public var code:Int=0;
	public var count:Int=0;
	public var words:Array<String>=[];
	public var flags:Array<String>=[];
	public var files:Array<String>=[];
	
	public function new(Code:Int)
	{
		code = Code;
	}
	
	public function addEntry(entry:CharacterEntry)
	{
		if (entry == null) return;
		count += entry.count;
		for (flag in entry.flags){
			if (flags.indexOf(flag) == -1) flags.push(flag);
		}
		for (word in entry.words){
			if (words.indexOf(word) == -1) words.push(word);
		}
		for (file in entry.files){
			if (files.indexOf(file) == -1) files.push(file);
		}
	}
	
	public function add(flag:String, word:String, file:String)
	{
		if (flags.indexOf(flag) == -1) flags.push(flag);
		if (words.indexOf(word) == -1) words.push(word);
		if (files.indexOf(file) == -1) files.push(file);
	}
}