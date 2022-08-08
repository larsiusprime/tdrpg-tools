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
using Util;

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
	private var loremContent:String = "";
	
	private var alreadyJoined:Array<String> = [];
	private var plotContent:Array<MetaStruct>;
	private var namesContent:String = "";
	
	public function new(){}
	
	public function parse(inDir:String, OutDir:String, Locale:String="en-US")
	{
		outDir = OutDir;
		locale = Locale;
		
		logDir = outDir + "logs/";
		
		var found = false;
		var str = "";
		var inFile = inDir + "script.txt";
		if (FileSystem.exists(inFile))
		{
			str = File.getContent(inFile);
			found = true;
		}
		else
		{
			var inFiles = FileSystem.readDirectory(inDir + "/script");
			inFiles.sort(function(a:String, b:String):Int{
				if (a < b) return -1;
				if (a > b) return  1;
				return 0;
			});
			for (file in inFiles){
				var theFile = inDir + "script/" + file;
				if (FileSystem.exists(theFile) && FileSystem.isDirectory(theFile) == false)
				{
					found = true;
					var fileStr = File.getContent(theFile);
					str += "COMMENT\n" + "*************************\nFrom file \"" + file+"\"\n*************************\n\n" + fileStr + "\n\n";
				}
			}
		}
		
		if(!found)
		{
			ScriptParser.error(0, 0, "could not find input file \"" + inFile+"\"!");
			return;
		}
		
		var document = new Document(str);
		tsvContent = "flag\tcontent\n";
		loremContent = "flag\tcontent\n";
		plotContent = [];
		processDocument(document, outDir, locale);
		
		var localeDir = outDir+"/locales/" + Locale+"/";
		if (!FileSystem.exists(localeDir)) FileSystem.createDirectory(localeDir);
		File.saveContent(localeDir + "scenes_text.tsv", tsvContent);
		File.saveContent(localeDir + "scenes_lorem.tsv", loremContent);
		
		var tempDir = outDir + "/_temp/";
		if (!FileSystem.exists(tempDir)) FileSystem.createDirectory(tempDir);
		var tempFile = tempDir + "meta.txt";
		var metaContent = processMeta();
		
		File.saveContent(tempDir + "script.txt", str);
		
		var nameDir = outDir + "/locales/"+Locale+"/";
		if (!FileSystem.exists(nameDir)) FileSystem.createDirectory(nameDir);
		File.saveContent(nameDir + "names.tsv", namesContent);
		
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
	
	private function sortMeta(a:MetaStruct, b:MetaStruct):Int
	{
		var aRank = metaRank(a);
		var bRank = metaRank(b);
		if (aRank < bRank) return -1;
		if (aRank > bRank) return  1;
		return 0;
	}
	
	private function metaRank(a:MetaStruct):Int
	{
		if (a.plotType == "heroes")  return -4;
		if (a.plotType == "actions") return -3;
		if (a.plotType == "movies")  return -2;
		if (a.plotType == "pearls")  return -1;
		return 0;
	}
	
	private function processMeta()
	{
		var metaContent = "";
		
		plotContent.sort(sortMeta);
		
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
		
		alreadyJoined = [];
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
		
		namesContent = "flag\tcontent\n";
		for (name in document.names)
		{
			var flag = ("$").uCat(Util.cleanString(name, ""));
			namesContent = namesContent.uCat(flag).uCat("\t").uCat(name).uCat("\n");
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
	
	private function getMetaStruct(plotLine:String, createIfNull:Bool=false)
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
			case WATCH: "actions";
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
			case "actions": processPlotActions(plot, scene);
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
		
		processPartyJoins(scene);
	}
	
	private function processPlotActions(plot:MetaStruct, scene:Scene)
	{
		var theName = sceneName(scene);
		var entry = getMetaEntry(plot, theName);
		if (entry == null)
		{
			entry = {name:theName, modifier:""};
			var actionBlob:String = "";
			for (block in scene.blocks)
			{
				if (block.keyword == Keyword.ACTION)
				{
					var text = block.getParameter("text");
					var flag = Utf8Ext.toUpperCase("$S_" + scene.name+"_B" + block.number + "_ACTION");
					actionBlob += getActionLine(block, flag);
				}
			}
			entry.modifier = actionBlob;
			plot.entries.push(entry);
		}
	}
	
	private function getActionLine(block:Block, flag:String)
	{
		var str = "<action ";
		for (line in block.lines)
		{
			var words = line.split(" ");
			if (words != null && words.length > 0)
			{
				var word = words[0].toLowerCase();
				words.splice(0, 1);
				var content = words.join("_").toLowerCase();
				if (word == "text")
				{
					content = flag;
				}
				str += (word + '="' + content + '" ');
			}
		}
		str += "/>";
		return str;
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
		
		processPartyJoins(scene);
	}
	
	private function processPartyJoins(scene:Scene)
	{
		for (block in scene.blocks)
		{
			if (block.keyword == Keyword.JOIN || block.keyword == Keyword.DUB)
			{
				switch(scene.trigger)
				{
					case SceneTrigger.NEWGAME, SceneTrigger.INTRO, SceneTrigger.OUTRO, SceneTrigger.BATTLE:
						var plot:MetaStruct = getMetaStruct("default_heroes");
						if (plot == null)
						{
							plot = {
								plotLine: "default_heroes",
								plotType: "heroes",
								entries: []
							}
							plotContent.push(plot);
						}
						var sceneName = scene.name;
						var mod = "";
						if (scene.trigger == SceneTrigger.NEWGAME)
						{
							sceneName = "-1";
						}
						else
						{
							mod = "p";
							sceneName = scene.pearlID;
						}
						
						var className = block.getParameter("class");
						className = Utf8Ext.toLowerCase(Util.cleanString(className));
						
						var hiddenOrNot:String = block.keyword == Keyword.JOIN ? "?" : "";
						
						if (className != "" && alreadyJoined.indexOf(className) == -1)
						{
							alreadyJoined.push(className);
							plot.entries.push({
								name:sceneName+"=" + hiddenOrNot +className,
								modifier:mod
							});
						}
					default: //donothing
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
		var lineData = {tsv:titleFlag+"\t"+scene.title+"\n", xml:"", xml2:"", id:"", loremIpsum:titleFlag+"\t"+scene.title+"\n"};
		
		var i = 0;
		for (block in scene.blocks)
		{
			i++;
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
				case Keyword.DUB:
					lineData = doBlock_Dub(scene, block, lineData);
				case Keyword.ACTION:
					lineData = doBlock_Action(scene, block, lineData);
			}
		}
		
		//append TSV data
		tsvContent += lineData.tsv;
		loremContent += lineData.loremIpsum;
		
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
				sceneXML = getTutMoviesXML(scene, titleFlag, bs, lineData.xml, lineData.xml2);
			default:
				sceneXML = "";
		}
		
		if (sceneXML != "")
		{
			trace("scene : " + scene.name+".xml ************");
			Util.saveXML(scenesDir + scene.name+".xml", null, sceneXML);
		}
	}
	
	private function getMoviesXML(scene:Scene, titleFlag:String, bs:BeginSettings, lineData:String):String
	{
		return 
'<scene ' + att("name", scene.name) + att("title", titleFlag) + att("background", bs.background) + att("music", bs.music) + att("demo_music", bs.demoMusic) + att("foreground_left", bs.foreLeft) + att("foreground_right", bs.foreRight) + att("act", Std.string(bs.act)) + att("scene", Std.string(bs.scene)) + att("sort", Std.string(scene.number)) + '>' +
lineData +
'</scene>';
	}
	
	private function getTutMoviesXML(scene:Scene, titleFlag:String, bs:BeginSettings, lineData:String, endData:String):String
	{
		return
'<scene ' + att("name", scene.name) + att("title", titleFlag) + att("act", Std.string(bs.act)) + att("scene", Std.string(bs.scene)) + att("sort", Std.string(scene.number)) + '>' +
lineData +
'</scene>' + 
endData;
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
			
			lineData.tsv += flag + "\t" + fixContent(content) + "\n";
			lineData.loremIpsum += flag + "\t" + fixContent(content) + "\n";
			
			
			lineData.xml += "<tut " + att("title", "PLAINTEXT") + att("text", flag) + "/>";
		}
		return lineData;
	}
	
	private function doBlock_Narrator(scene:Scene, block:Block, lineData:BlockLineData):BlockLineData
	{
		for (i in 0...block.lines.length)
		{
			var flag = Utf8Ext.toUpperCase("$S_" + scene.name+"_B" + block.number + "_L" + i);
			var content = block.lines[i];
			lineData.tsv += flag + "\t" + fixContent(content) + "\n";
			lineData.loremIpsum += flag + "\t" + loremIpsum(fixContent(content)) + "\n";
			
			lineData.xml += "<tut " + att("title", "$TALK_NARRATOR_NORMAL") + att("text", flag) +"/>";
		}
		return lineData;
	}
	
	private function doBlock_Placeholder(scene:Scene, block:Block, lineData:BlockLineData):BlockLineData
	{
		for (i in 0...block.lines.length)
		{
			var flag = Utf8Ext.toUpperCase("$S_" + scene.name+"_B" + block.number + "_L" + i);
			var content = block.lines[i];
			lineData.tsv += flag +"\t" + fixContent(content) + "\n";
			lineData.loremIpsum += flag +"\t" + fixContent(content) + "\n";
			
			lineData.xml += "<tut " + att("title", "PLACEHOLDER") + att("text", flag) + "/>";
		}
		return lineData;
	}
	
	private function doBlock_Speech(scene:Scene, block:Block, lineData:BlockLineData):BlockLineData
	{
		var flag = "";
		var speaker = block.getParameter("speaker");
		var emote = block.getParameter("emote");
		var id = block.getParameter("id");
		if (emote == "")
		{
			emote = "NORMAL";
		}
		speaker = Util.cleanString(speaker, "");
		
		for (i in 0...block.lines.length)
		{
			flag = Utf8Ext.toUpperCase("$S_" + scene.name+"_B" + block.number + "_L" + i);
			var content = block.lines[i];
			
			if (content == "Emote " + emote){
				continue;
			}
			
			lineData.tsv += flag + "\t" + fixContent(content) + "\n";
			lineData.loremIpsum += flag + "\t" + loremIpsum(fixContent(content)) + "\n";
			lineData.xml += "<tut " + att("title", "TALK_$" + speaker + "_" + emote) + att("text", flag) + "/>";
		}
		return lineData;
	}
	
	private function doBlock_Action(scene:Scene, block:Block, lineData:BlockLineData):BlockLineData
	{
		var flag = Utf8Ext.toUpperCase("$S_" + scene.name+"_B" + block.number + "_ACTION");
		
		var text = block.getParameter("text");
		if (text == "") flag = "";
		
		if(flag != "")
		{
			lineData.tsv += flag + "\t" + text + "\n";
			lineData.loremIpsum += flag + "\t" + text + "\n";
		}
		
		return lineData;
	}
	
	private function doBlock_Dub(scene:Scene, block:Block, lineData:BlockLineData):BlockLineData
	{
		var flag = Utf8Ext.toUpperCase("$S_" + scene.name+"_B" + block.number + "_DUB");
		
		var charClass = block.getParameter("class");
		
		if (charClass == "")
		{
			charClass = block.getParameter("character");
		}
		
		var text = block.getParameter("text");
		if (text == "") flag = "";
		
		if (flag != "")
		{
			lineData.tsv += flag + "\t" + text + "\n";
			lineData.loremIpsum += flag + "\t" + text + "\n";
		}
		
		lineData.xml += "<dub " + att("class", charClass) + att("text", flag) + "/>";
		return lineData;
	}
	
	private function getNextBlock(scene:Scene, block:Block):Block
	{
		var i = scene.blocks.indexOf(block);
		if (i == -1) return null;
		if (scene.blocks.length > i + 1)
		{
			return scene.blocks[i + 1];
		}
		return null;
	}
	
	private function getTutorialHeader(id:String, scene:Scene, block:Block, lineData:BlockLineData)
	{
		var nextId = id;
		var lastWasMe = false;
		var nextBlock = getNextBlock(scene, block);
		
		while(nextBlock != null && nextId == id)
		{
			nextId = nextBlock.getParameter("id");
			nextBlock = getNextBlock(scene, nextBlock);
		}
		if (nextId == id) nextId = "";
		
		var locked:Bool = (lineData.id != "");
		
		var lockOverride = block.getParameter("locked", "");
		if (lockOverride == "true"){
			locked = true;
		}else if (lockOverride == "false"){
			locked = false;
		}
		
		var trigger = getTriggerAndParams(block.getParameter("trigger"));
		var style = doBlock_Tutorial_Style(block);
		lineData.xml2 += '<tutorial id="' + id + '" trigger = "' + trigger.verb + '"' + style + '>';
		if(trigger.params != null)
		{
			for (i in 0...Std.int(trigger.params.length / 2))
			{
				var a = i * 2;
				var b = (i * 2) + 1;
				var type = trigger.params.length > a ? trigger.params[a] : "";
				var value = trigger.params.length > b ? trigger.params[b] : "";
				if (type != "" && value != "")
				{
					lineData.xml2 += '<param type="' + type + '" value="' + value + '"/>';
				}
			}
		}
		
		lineData.xml2 += '<locked value="' + locked + '"/>';
		if (nextId != "")
		{
			lineData.xml2 += '<unlock id="' + nextId + '"/>';
		}
		
		var tags = doBlock_Tutorial_Tags(block);
		if (tags != ""){
			lineData.xml2 += tags;
		}
		
		var action  = getActionAndParams(block.getParameter("action"));
		
		if (action != null && action.verb != "")
		{
			lineData.xml2 += '<action id="' + action.verb + '"';
			var i:Int = 1;
			for (param in action.params)
			{
				if (param == "") continue;
				var p = "p" + i;
				lineData.xml2 += ' ' + p + '="' + param + '"';
				i++;
			}
			lineData.xml2 += '/>';
		}
	}
	
	private function getVerbAndParams(str:String, testWords:Array<String>):{verb:String, params:Array<String>}
	{
		var words = str.toLowerCase().split(" ");
		var result = {verb:"", params:[]};
		if (words != null)
		{
			if (words.length > 0)
			{
				var wordStr = words.join("_");
				for (test in testWords)
				{
					var i:Int = wordStr.indexOf(test);
					if (i == 0)
					{
						result.verb = test;
						
						var wordBit = Util.firstReplace(wordStr, test, "");
						if (wordBit.length > 1 && wordBit.charAt(0) == "_")
						{
							wordBit = wordBit.substr(0, wordBit.length);
							if (wordBit.length > 1)
							{
								var params = wordBit.split("_");
								if (params.length > 1 && params[0] == ""){
									params.splice(0, 1);
								}
								result.params = params;
								if (result.params.length == 1)
								{
									var verbSplit = result.verb.split("_");
									if (verbSplit != null && verbSplit.length > 1)
									{
										result.params = [verbSplit[verbSplit.length - 1], params[0]];
									}
								}
							}
						}
						break;
					}
				}
			}
		}
		return result;
	}
	
	private function getTestWords()
	{
		var testWords = [
			"skip_proximity_defender",
			"summon_defender",
			"summon_defender_or_reach_wave",
			"boost",
			"boost_defender",
			"select_character",
			"hurt_defender",
			"start",
			"select_class",
			"place_defender",
			"defender_die",
			"select_defender",
			"reach_wave",
			"select_spell",
			"cast_spell",
			"cast_delayed_spell",
			"kill",
			"start_kill",
			"start_kill_type",
			"time",
			"instant",
			"victory",
			"enemy_reach_node",
			"apc_spawn",
			"enemy_start_swim",
			"exalted_barrier",
			"kill_exalted",
			"level_up",
			"click_level_up_gem",
			"click_bonus",
			"view_skill_have_points",
			"shop",
			"select_merch",
			"equipped",
			"buy",
			"sell",
			"downgrade",
			"upgrade",
			"jumpzone",
			"item_upgraded",
			"speaker",
			"long_shot",
			"parasite_1",
			"parasite_2",
			"medium_shot",
			"quarter_health",
			"half_health",
			"black_hat_ship"
		];
		return testWords;
	}
	
	private function getTriggerAndParams(str:String):{verb:String, params:Array<String>}
	{
		var testWords = getTestWords();
		return getVerbAndParams(str, testWords);
	}
	
	private function getActionAndParams(str:String):{verb:String, params:Array<String>}
	{
		var testWords = [
			"select_defender",
			"set_time",
			"hide_craters",
			"show_craters",
			"guarantee_psi",
			"spawn",
			"summon",
			"friend_spell",
			"set_defender_value",
			"gamepad_menu",
			"gamepad_menu_back",
			"suppress"
		];
		return getVerbAndParams(str, testWords);
	}
	
	private static var loremText = "Lorem ipsum dolor sit amet, consectetur adipiscing elit. Sed do eiusmod tempor incididunt ut labore et dolore magna aliqua. Eu scelerisque felis imperdiet proin. Lacus sed viverra tellus in hac habitasse platea dictumst. Platea dictumst vestibulum rhoncus est pellentesque elit ullamcorper. Sagittis id consectetur purus ut faucibus. Facilisis leo vel fringilla est. Rhoncus dolor purus non enim praesent elementum facilisis. Lacus vestibulum sed arcu non odio euismod. Sit amet risus nullam eget. Nisl pretium fusce id velit ut tortor pretium viverra suspendisse. Et ultrices neque ornare aenean.";
	private static var loremSentences = [];
	private static var loremSentence:Int = 0;
	
	private function loremIpsum(str:String):String
	{
		if (loremSentences.length == 0){
			loremSentences = loremText.split(". ");
		}
		var text = loremSentences[loremSentence] + ".";
		loremSentence++;
		if (loremSentence >= loremSentences.length){
			loremSentence = 0;
		}
		return text;
	}
	
	private function fixContent(str:String):String
	{
		var tokens = [
			["line", "break"]
		];
		
		var values = [
			"<N>"
		];
		
		var lStr:String = Utf8Ext.toLowerCase(str);
		for (i in 0...tokens.length)
		{
			var token = tokens[i];
			var value = values[i];
			var variants = getAllTokenVariants(token);
			for (variant in variants)
			{
				var i:Int = lStr.uIndexOf(variant);
				while(i != -1)
				{
					var bit = lStr.uSubstr(i, variant.length);
					var before = str.uSubstr(0, i);
					var after = str.uSubstr(i + variant.length, str.uLength());
					
					str = before + value + after;
					lStr = Utf8Ext.toLowerCase(str);
					i = lStr.uIndexOf(variant);
				}
			}
		}
		
		return str;
	}
	
	static function getAllTokenVariants(tokens:Array<String>):Array<String>
	{
		var baseWord:String = tokens.join("");
		var withSpace:String = tokens.join(" ");
		var arr = [baseWord, withSpace];
		
		arr = arr.concat(getToken_with(arr, "", "."));
		arr = arr.concat(getToken_with(arr, " ", " "));
		
		arr.sort(function(a:String,b:String):Int{
			if(a.length > b.length) return -1;
			if(a.length < b.length) return  1;
			return 0;
		});
		
		return arr;
	}
	
	static  function getToken_with(arr:Array<String>, prefix:String = "", suffix:String = ""):Array<String>
	{
		var all = [];
		for (str in arr)
		{
			if (prefix != "") all.push(prefix + str);
			if (suffix != "") all.push(str + suffix);
			if (prefix != "" && suffix != "") all.push(prefix + str + suffix);
		}
		return all;
	}
	
	private function trimBlock_Tutorial(block:Block)
	{
		var params = ["id", "trigger", "arrow", "target", "click", "facing", "mouse", "action", "offset", "style", "tags", "locked", "emote", "speaker"];
		var punctuation = [".", "?", "!", ":", ";", "-"];
		
		//Try to find parameters at the beginning of the block
		// - exit on the first line with a word that isn't also a parameter
		// - if a line starts with a parameter word, treat it as text if:
		//   - it contains more than four words after the first
		//   - it ends with a punctuation mark
		//Otherwise, they'll show up as regular text
		//Make sure that we've already read all the parameter information we need in the section above
		
		var testWords = getTestWords();
		
		var badlines = [];
		for (i in 0...block.lines.length)
		{
			var line = block.lines[i].toLowerCase();
			var words = line.split(" ");
			if (words == null || words.length == 0 || words.length >= 9)
			{
				break;
			}
			
			var word = words[0];
			if (params.indexOf(word) == -1)
			{
				break;
			}
			var fail = false;
			for (p in punctuation)
			{
				if (line.indexOf(p) == line.length-1)
				{
					fail = true;
					break;
				}
			}
			if (fail){
				break;
			}
			badlines.push(i);
		}
		
		for (i in 0...badlines.length)
		{
			var j = badlines.length - i - 1;
			var line = badlines[j];
			block.lines.splice(j, 1);
		}
	}
	
	private function doBlock_Tutorial(scene:Scene, block:Block, lineData:BlockLineData):BlockLineData
	{
		var extraString = "";
		extraString += doBlock_Tutorial_Arrow(block);
		extraString += doBlock_Tutorial_Click(block);
		extraString += doBlock_Tutorial_Offset(block);
		
		var id = block.getParameter("id");
		var newId = false;
		if (id != lineData.id)
		{
			newId = true;
		}
		
		var nextBlock = getNextBlock(scene, block);
		var nextId = (nextBlock != null) ? nextBlock.getParameter("id") : "";
		
		if (newId)
		{
			getTutorialHeader(id, scene, block, lineData);
		}
		lineData.id = id;
		
		var speaker = block.getParameter("speaker");
		var emote = block.getParameter("emote");
		
		trimBlock_Tutorial(block);
		
		for (i in 0...block.lines.length)
		{
			var flag = Utf8Ext.toUpperCase("$S_" + scene.name+"_B" + block.number + "_L" + i);
			var content = block.lines[i];
			
			var lContent = content.toLowerCase();
			
			lineData.tsv += flag + "\t" + fixContent(content) + "\n";
			
			var title = block.getParameter("title");
			if (title == "")
			{
				title = "TUTORIAL";
			}
			
			speaker = Util.cleanString(speaker, "");
			
			if (speaker != "" && speaker != null){
				if (emote == "" || emote == null){
					emote = "NORMAL";
				}
				title = "TALK_$" + speaker.toUpperCase() + "_" + emote;
				lineData.loremIpsum += flag + "\t" + loremIpsum(fixContent(content)) + "\n";
			}else{
				lineData.loremIpsum += flag + "\t" + fixContent(content) + "\n";
			}
			
			var linexml = "<tut " + att("title", title) + att("text", flag);
			
			if (extraString == "")
			{
				linexml += "/>";
			}
			else
			{
				linexml += ">" + extraString + "</tut>";
			}
			
			if (id == "")
			{
				lineData.xml += linexml;
			}
			else
			{
				lineData.xml2 += linexml;
			}
		}
		
		if (id != "" && nextId != id)
		{
			lineData.xml2 += "</tutorial>";
		}
		
		return lineData;
	}
	
	private function doBlock_Tutorial_Arrow(block:Block)
	{
		var arrow = block.getParameter("arrow");
		var target = block.getParameter("target");
		
		arrow = StringTools.replace(arrow, " ", "_");
		target = StringTools.replace(target, " ", "_");
		
		var extraString = "";
		if (arrow != "")
		{
			return '<arrow target_type="' + arrow + '" target_value="' + target + '"/>';
		}
		
		return "";
	}
	
	private function doBlock_Tutorial_Click(block:Block)
	{
		var arrow = block.getParameter("click");
		var target = block.getParameter("target");
		var facing = block.getParameter("facing", "right");
		
		arrow = StringTools.replace(arrow, " ", "_");
		target = StringTools.replace(target, " ", "_");
		
		var mouseOver = "";
		var mouse = block.getParameter("mouse");
		if (mouse == "over"){
			mouseOver = ' mouse_over="true" ';
		}
		
		var extraString = "";
		if (arrow != "")
		{
			return '<tut_arrow target_type="' + arrow + '" target_value="' + target + '" facing="'+facing+'"' + mouseOver + '/>';
		}
		
		return "";
	}
	
	private function doBlock_Tutorial_Offset(block:Block)
	{
		var offset = block.getParameter("offset");
		if (offset != "")
		{
			var xy = offset.split(",");
			if(xy != null && xy.length == 2){
				var x = Std.parseInt(xy[0]);
				var y = Std.parseInt(xy[1]);
				return '<offset x="' + x + '" y="' + y + '"/>';
			}
		}
		return "";
	}
	
	private function doBlock_Tutorial_Tags(block:Block)
	{
		var tags = block.getParameter("tags");
		if (tags != "")
		{
			var entries = tags.split(";");
			var returnValue = "";
			if (entries != null && entries.length > 0){
				for (entry in entries)
				{
					//dont_show,condition,have,value,defender_berserker:ls_eq:0;dont_show,condition,have,defender-boost_berserker:gr_eq:2
					
					var tagName:String = "unknown_tag";
					var varName:String = "";
					var varValue:String = "";
					var entryValue:String = "";
					
					var bits = entry.split(",");
					var temp = "";
					
					for (i in 0...bits.length){
						trace(i + " " + bits[i]);
						if (i == 0) {
							tagName = bits[i];
						}
						else {
							if (i % 2 != 0) varName = bits[i];
							else {
								varValue = bits[i];
								temp += ' ' + varName + '="' + varValue+'"';
							}
						}
					}
					entryValue += '<' + tagName+temp + '/>';
					
					returnValue += entryValue;
				}
			}
			return returnValue;
		}
		return "";
	}
	
	private function doBlock_Tutorial_Style(block:Block)
	{
		var style = block.getParameter("style");
		if (style != "")
		{
			return ' style = "' + style+'"';
		}
		return ' style = "default"';
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
		return name + '="' + value + '" ';
	}
}

typedef BlockLineData = {tsv:String, ?xml:String, ?mapXml:String, ?listPlots:Array<String>, ?xml2:String, ?id:String, loremIpsum:String};
typedef BeginSettings = {background:String, music:String, demoMusic:String, act:Int, scene:Int, foreLeft:String, foreRight:String, plotLine:String};