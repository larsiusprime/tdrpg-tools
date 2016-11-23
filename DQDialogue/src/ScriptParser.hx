import firetongue.TSV;
import haxe.xml.Fast;
import org.zamedev.lib.Utf8Ext;
import sys.FileSystem;
import sys.io.File;
import unifill.Unicode;
/**
 * ...
 * @author 
 */

using unifill.Unifill;

typedef MetaStruct = {
	plotLine:String,
	plotType:String,
	entries:Array<MetaEntry>
}

typedef MetaEntry = {
	name:String,
	modifier:String
}

class ScriptParser
{
	private var outDir:String;
	private var locale:String;
	
	public static var logDir(default,null):String;
	
	private var tsvContent:String = "";
	
	private var plotContent:Array<MetaStruct>;
	
	public function new(){}
	
	public function parse(inDir:String, OutDir:String, Locale:String="en-US")
	{
		outDir = OutDir;
		locale = Locale;
		
		logDir = outDir + "logs/";
		
		var str = "";
		var inFile = inDir + "script.txt";
		if (FileSystem.exists(inFile))
		{
			str = File.getContent(inFile);
		}
		else
		{
			ScriptParser.error(0, 0, "could not find input file \"" + inFile+"\"!");
			return;
		}
		
		var document = new Document(str);
		tsvContent = "flag\tcontent\n";
		plotContent = [];
		processDocument(document, outDir, locale);
		
		var localeDir = outDir+"/locales/" + Locale+"/";
		if (!FileSystem.exists(localeDir)) FileSystem.createDirectory(localeDir);
		File.saveContent(localeDir + "scenes.tsv", tsvContent);
		
		var tempDir = outDir + "/_temp/";
		if (!FileSystem.exists(tempDir)) FileSystem.createDirectory(tempDir);
		var tempFile = tempDir + "meta.txt";
		var metaContent = processMeta();
		
		File.saveContent(tempFile, metaContent);
	}
	
	public static function matchAndStrip(string:String, match:String):String
	{
		var lowerString = Utf8Ext.toLowerCase(string);
		var lowerMatch = Utf8Ext.toLowerCase(match);
		var index = lowerString.uIndexOf(lowerMatch);
		if (index == 0)
		{
			var len = match.uLength();
			return Unifill.uSubstr(string, len, string.uLength() - len);
		}
		return null;
	}
	
	private function processMeta()
	{
		var metaContent = "";
		
		for (i in 0...plotContent.length)
		{
			var plot = plotContent[i];
			if (i != 0) metaContent += "\n";
			
			if (plot.plotLine != "")
			{
				metaContent += plot.plotLine+":" + plot.plotType+":";
				if (plot.entries == null || plot.entries.length == 0)
				{
					metaContent += ";\n";
				}
				else
				{
					metaContent += "\n\t";
					for (j in 0...plot.entries.length)
					{
						var entry = plot.entries[j];
						if (entry.modifier == "root" || entry.modifier == ""){
							metaContent += entry.name;
						}
						else
						{
							metaContent += entry.name+"*" + entry.modifier;
						}
						if (j != plot.entries.length - 1)
						{
							metaContent += ",";
						}
						else
						{
							metaContent += ";\n";
						}
					}
				}
			}
		}
		
		return metaContent;
	}
	
	public function processDocument(document:Document, outDir:String, locale:String)
	{
		for (scene in document.scenes)
		{
			processScene(scene, outDir, locale);
		}
		
		for (i in 0...document.scenes.length)
		{
			var scene = document.scenes[i];
			var prev = null;
			var next = null;
			if (i != document.scenes.length - 1)
			{
				next = document.scenes[i + 1];
				scene.next = next.name;
			}
			else
			{
				scene.next = "dummy";
			}
			if (i != 0)
			{
				prev = document.scenes[i - 1];
				scene.previous = prev.name;
			}
			else
			{
				scene.previous = "";
			}
			
			processPlot(scene, prev, next);
		}
	}
	
	private function getMetaEntry(metaStruct:MetaStruct, name:String)
	{
		for (entry in metaStruct.entries)
		{
			if (entry.name == name)
			{
				return entry;
			}
		}
		return null;
	}
	
	private function getMetaStruct(plotLine:String)
	{
		for (plot in plotContent)
		{
			if (Utf8Ext.toLowerCase(plot.plotLine) == Utf8Ext.toLowerCase(plotLine))
			{
				return plot;
			}
		}
		return null;
	}
	
	private function getPlotType(trigger:SceneTrigger):String
	{
		return switch(trigger) {
			case INTRO, OUTRO, NEWGAME: "movies";
			case REWARDS: "reward_movies";
			case BATTLE: "battle_movies";
			case OVERWORLD: "overworld_movies";
			case PARTY: "party_movies";
			case TOWN: "town_movies";
			default: "unknown";
		}
	}
	
	public function processPlot(scene:Scene, prev:Scene, next:Scene)
	{
		var plot:MetaStruct = getMetaStruct(scene.plotLine);
		if (plot == null)
		{
			plot = {
				plotLine: scene.plotLine,
				plotType: getPlotType(scene.trigger),
				entries: []
			}
			plotContent.push(plot);
		}
		
		switch(plot.plotType)
		{
			case "movies": processPlotMovies(plot, scene);
			case "battle_movies", "reward_movies", "overworld_movies", "party_movies", "town_movies": processPlotTutMovies(plot, scene, plot.plotType);
			case "unknown":
		}
	}
	
	private function sceneName(scene:Scene):String
	{
		var theName = scene.pearlID;
		if (theName == null)
		{
			theName = scene.name;
		}
		else
		{
			theName = Util.padLeft(theName, 3);
		}
		return theName;
	}
	
	private function processPlotTutMovies(plot:MetaStruct, scene:Scene, plotType:String="")
	{
		var theName = sceneName(scene);
		
		if (plotType == "overworld_movies")
		{
			var i = theName.indexOf("_overworld");
			if (i != -1 && i != 0)
			{
				theName = StringTools.replace(theName, "_overworld", "");
			}
		}
		else if (plotType == "party_movies" || plotType == "reward_movies")
		{
			var pearl = scene.getParam("pearl");
			var section = scene.getParam("section");
			theName = Util.padLeft(pearl, 3);
			if (section != "" && section != null)
			{
				theName = theName + "*" + section;
			}
		}
		else if (plotType == "town_movies")
		{
			var town = scene.getParam("town");
			var pearl = scene.getParam("pearl");
			var section = scene.getParam("section");
			trace("town = " + town + " pearl = " + pearl + " section = " + section);
			theName = town;
			if (section != "" && section != null)
			{
				theName = town + "*" + section + "*" + pearl;
			}
		}
		
		var entry = getMetaEntry(plot, theName);
		if (entry == null)
		{
			entry = {name:theName, modifier:""};
			plot.entries.push(entry);
		}
	}
	
	private function processPlotMovies(plot:MetaStruct, scene:Scene)
	{
		var theName = sceneName(scene);
		var entry = getMetaEntry(plot, theName);
		if (entry == null)
		{
			entry = {name:theName, modifier:""};
			plot.entries.push(entry);
		}
		switch(scene.trigger)
		{
			case INTRO:
				if (entry.modifier == "") entry.modifier = "i";
				else if (entry.modifier == "o") entry.modifier = "";
			case OUTRO:
				if (entry.modifier == "") entry.modifier = "o";
				else if (entry.modifier == "i") entry.modifier = "";
			case NEWGAME:
				entry.modifier = "root";
				
				var entryIndex = plot.entries.indexOf(entry);
				//ensure root comes first!
				if (entryIndex != 0)
				{
					plot.entries.splice(entryIndex, 1);
					plot.entries.insert(0, entry);
				}
				
				//ensure there are no other roots:
				for (i in 1...plot.entries.length)
				{
					if (plot.entries[i].modifier == "root")
					{
						error( -1, -1, "only one NEWGAME block is allowed in the entire document!");
					}
				}
		}
	}
	
	public function processScene(scene:Scene, outDir:String, locale:String)
	{
		var scenesDir = outDir + "/scenes/" + locale+"/"; 
		var tutsDir = outDir + "/tuts/" + locale+"/";
		
		var titleFlag = Utf8Ext.toUpperCase("$S_" + scene.name+"_TITLE");
		
		var bkg = "";
		var music = "";
		var demoMusic = "";
		var actNum = "";
		var sceneNum = "";
		var foreLeft = "";
		var foreRight = "";
		
		var sceneNodes = "";
		var bs:BeginSettings = null;
		var lineData = {tsv:titleFlag+"\t"+scene.title+"\n", xml:""};
		
		for (block in scene.blocks)
		{
			switch(block.keyword)
			{
				case Keyword.BEGIN:
					bs = doBlock_Begin(block);
				case Keyword.PLAINTEXT:
					lineData = doBlock_PlainText(scene, block, lineData);
				case Keyword.SPEECH:
					lineData = doBlock_Speech(scene, block, lineData);
				case Keyword.NARRATOR:
					lineData = doBlock_Narrator(scene, block, lineData);
				case Keyword.PLACEHOLDER:
					lineData = doBlock_Placeholder(scene, block, lineData);
				case Keyword.TUTORIAL:
					lineData = doBlock_Tutorial(scene, block, lineData);
			}
		}
		
		//append TSV data
		tsvContent += lineData.tsv;
		
		//create unique scene entry
		if (!FileSystem.exists(scenesDir))
		{
			FileSystem.createDirectory(scenesDir);
		}
		if (!FileSystem.exists(tutsDir))
		{
			FileSystem.createDirectory(tutsDir); 
		}
		
		if (bs == null)
		{
			bs = {
				background:"",
				music:"",
				demoMusic:"",
				act:0,
				scene:0,
				foreLeft:"",
				foreRight:"",
				plotLine:""
			};
		}
		
		var plotType = getPlotType(scene.trigger);
		
		var sceneXML = "";
		switch(plotType)
		{
			case "movies": 
				sceneXML = getMoviesXML(scene, titleFlag, bs, lineData.xml);
			case "battle_movies","reward_movies","overworld_movies","party_movies","town_movies":
				sceneXML = getTutMoviesXML(scene, titleFlag, bs, lineData.xml);
			default:
				sceneXML = "";
		}
		
		if (sceneXML != "")
		{
			File.saveContent(scenesDir + scene.name + ".xml", sceneXML);
		}
	}
	
	private function getMoviesXML(scene:Scene, titleFlag:String, bs:BeginSettings, lineData:String):String
	{
		return 
'<scene ' + att("name", scene.name) + att("title", titleFlag) + att("background", bs.background) + att("music", bs.music) + att("demo_music", bs.demoMusic) + att("foreground_left", bs.foreLeft) + att("foreground_right", bs.foreRight) + att("act", Std.string(bs.act)) + att("scene", Std.string(bs.scene)) + '>' +
lineData +
'\n</scene>';
	}
	
	private function getTutMoviesXML(scene:Scene, titleFlag:String, bs:BeginSettings, lineData:String):String
	{
		return
'<scene ' + att("name", scene.name) + att("title", titleFlag) + att("act", Std.string(bs.act)) + att("scene", Std.string(bs.scene)) + '>' +
lineData +
'\n</scene>';
	}
	
	private function doBlock_Begin(block:Block):BeginSettings
	{
		var bkg:String="";
		var music:String="";
		var demoMusic:String="";
		var actNum:Null<Int>=0;
		var sceneNum:Null<Int>=0;
		var foreLeft:String="";
		var foreRight:String = "";
		var plotLine:String = "";
		
		for (i in 1...block.lines.length)
		{
			var line = block.lines[i];
			if (line != null && line != "")
			{
				var line = Utf8Ext.toLowerCase(line);
				var words = ["background", "music", "demo music", "act", "scene", "foreground left", "foreground right", "plotline"];
				for (word in words)
				{
					if (line.uIndexOf(word+" ") == 0)
					{
						line = Util.uReplace(line, word+" ", "");
						switch(word)
						{
							case "background": bkg = Utf8Ext.toLowerCase(line);
							case "music": music = Utf8Ext.toLowerCase(line);
							case "demo music": demoMusic = Utf8Ext.toLowerCase(line);
							case "act": 
								actNum = Std.parseInt(line);
								if (actNum == null)
								{
									error(block.number, block.lineNumber + i, "act property requires a numeric value, found \"" + line+"\"");
								}
							case "scene":
								sceneNum = Std.parseInt(line);
								if (sceneNum == null)
								{
									error(block.number, block.lineNumber + i, "scene property requires a numeric value, found \"" + line+"\"");
								}
							case "foreground left": foreLeft = Utf8Ext.toLowerCase(line);
							case "foreground right": foreRight = Utf8Ext.toLowerCase(line);
							case "plotline": plotLine = Utf8Ext.toLowerCase(line);
						}
					}
				}
			}
		}
		
		return {
			background:bkg,
			music:music,
			demoMusic:demoMusic,
			act:actNum,
			scene:sceneNum,
			foreLeft:foreLeft,
			foreRight:foreRight,
			plotLine:plotLine
		};
	}
	
	private function doBlock_PlainText(scene:Scene, block:Block, lineData:BlockLineData):BlockLineData
	{
		for (i in 0...block.lines.length)
		{
			var flag = Utf8Ext.toUpperCase("$S_" + scene.name+"_B" + block.number + "_L" + i);
			var content = block.lines[i];
			
			lineData.tsv += flag + "\t" + content + "\n";
			
			lineData.xml += "\n    <tut " + att("title", "PLAINTEXT") + att("text", flag) + "/>";
		}
		return lineData;
	}
	
	private function doBlock_Narrator(scene:Scene, block:Block, lineData:BlockLineData):BlockLineData
	{
		for (i in 0...block.lines.length)
		{
			var flag = Utf8Ext.toUpperCase("$S_" + scene.name+"_B" + block.number + "_L" + i);
			var content = block.lines[i];
			lineData.tsv += flag + "\t" + content + "\n";
			
			lineData.xml += "\n    <tut " + att("title", "TALK_$NARRATOR_NORMAL") + att("text", flag) +"/>";
			
			//lineData.xml += "\n    <line " + att("character", "", true) + att("text", flag) +"/>";
		}
		return lineData;
	}
	
	private function doBlock_Placeholder(scene:Scene, block:Block, lineData:BlockLineData):BlockLineData
	{
		for (i in 0...block.lines.length)
		{
			var flag = Utf8Ext.toUpperCase("$S_" + scene.name+"_B" + block.number + "_L" + i);
			var content = block.lines[i];
			lineData.tsv += flag +"\t" + content + "\n";
			
			lineData.xml += "\n    <tut " + att("title", "PLACEHOLDER") + att("text", flag) + "/>";
			
			//lineData.xml += "\n    <line " + att("character", "", true) + att("text", flag) +"/>";
		}
		return lineData;
	}
	
	private function doBlock_Speech(scene:Scene, block:Block, lineData:BlockLineData):BlockLineData
	{
		var flag = Utf8Ext.toUpperCase("$S_" + scene.name+"_B" + block.number + "_SPEAKER");
		var speaker = block.getParameter("speaker");
		var emote = block.getParameter("emote");
		if (emote == "")
		{
			emote = "NORMAL";
		}
		speaker = Util.cleanString(speaker, "");
		lineData.tsv += flag + "\t" + speaker + "\n";
		for (i in 0...block.lines.length)
		{
			flag = Utf8Ext.toUpperCase("$S_" + scene.name+"_B" + block.number + "_L" + i);
			var content = block.lines[i];
			lineData.tsv += flag + "\t" + content + "\n";
			
			lineData.xml += "\n    <tut " + att("title", "TALK_$" + speaker + "_" + emote) + att("text", flag) + "/>";
			
			//lineData.xml += "\n    <line " + att("character", speaker) + att("text", flag) +"/>";
		}
		return lineData;
	}
	
	private function doBlock_Tutorial(scene:Scene, block:Block, lineData:BlockLineData):BlockLineData
	{
		for (i in 0...block.lines.length)
		{
			var flag = Utf8Ext.toUpperCase("$S_" + scene.name+"_B" + block.number + "_L" + i);
			var content = block.lines[i];
			lineData.tsv += flag + "\t" + content + "\n";
			var title = block.getParameter("title");
			if (title == "")
			{
				title = "TUTORIAL";
			}
			
			lineData.xml += "\n    <tut " + att("title", title) + att("text", flag) + "/>";
			
			//lineData.xml += "\n    <line " + att("character", "", true) + att("text", content) +"/>";
		}
		return lineData;
	}
	
	public static function error(block:Int,line:Int,msg:String,?context:String):Void
	{
		var str = Util.uCombine(["SCRIPT ERROR @ line ", Std.string(line), ", block ", Std.string(block), ": ", msg]);
		if (context != null)
		{
			str = Util.uCombine([str," context=",context]);
		}
		Sys.println(str);
	}
	
	public static function log(msgs:Array<String>)
	{
		var msg = Util.uCombine(msgs);
		if (FileSystem.exists(logDir) == false)
		{
			FileSystem.createDirectory(logDir);
		}
		var logFile = logDir + "log.txt";
		var file = "";
		if (FileSystem.exists(logFile))
		{
			file = File.getContent(logDir + "log.txt");
		}
		file = Util.uCombine([file, "\n*************\n", msg]);
		File.saveContent(logDir + "log.txt", file);
	}
	
	public static function arrVal(arr:Array<String>, i:Int):String
	{
		if (arr == null) return null;
		if (arr.length <= i) return null;
		return arr[i];
	}
	
	public static function att(name:String, value:String, forceEmpty:Bool=false):String
	{
		if (!forceEmpty && (value == null || value == "")) return "";
		return name + '="' + value + '" ';				//' fart="value"'
	}
}

typedef BlockLineData = {tsv:String, ?xml:String, ?mapXml:String, ?listPlots:Array<String>};
typedef BeginSettings = {background:String, music:String, demoMusic:String, act:Int, scene:Int, foreLeft:String, foreRight:String, plotLine:String};