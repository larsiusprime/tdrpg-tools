package;
import org.zamedev.lib.Utf8Ext;

using Util;
using unifill.Unifill;

/**
 * ...
 * @author 
 */
class Scene
{
	public var plotLine:String;
	public var next:String;
	public var previous:String;
	public var number:Int;
	public var name:String;
	public var title:String;
	public var trigger:SceneTrigger;
	public var triggerParams:Array<String>;
	public var pearlID:String;
	public var townID:String;
	public var blocks:Array<Block>;
	
	public function new(Blocks:Array<Block>, endBlock:Int=0, SceneNumber:Int=0)
	{
		number = SceneNumber;
		
		var startBlock = endBlock - Blocks.length;
		var blockNum = startBlock;
		var lineNum = Blocks[0].lineNumber;
		
		blocks = Blocks;
		
		triggerParams = [];
		
		if (blocks == null || blocks.length == 0)
		{
			error(blockNum, lineNum, "Block array is empty!");
			return;
		}
		
		for (block in blocks)
		{
			if (blockNum == startBlock)
			{
				if (block.keyword != Keyword.BEGIN)
				{
					error(blockNum, lineNum, "First block in scene is not BEGIN, but \"" + Utf8Ext.toUpperCase(block.keyword) + "\"! context:(" + block + ")");
					return;
				}
				else
				{
					title = block.lines[0];
				}
			}
			else if (blockNum == endBlock)
			{
				if (block.keyword != Keyword.END)
				{
					error(blockNum, lineNum, "Last block in scene is not END, but \"" + Utf8Ext.toUpperCase(block.keyword) + "\"! context:(" + block + ")");
					return;
				}
			}
			else
			{
				if (block.keyword == Keyword.BEGIN || block.keyword == Keyword.END)
				{
					error(blockNum, lineNum, "Found " + block.keyword + " in middle of block! context:(" + block + ")");
					return;
				}
				var sceneTrigger = SceneTrigger.fromString(block.keyword);
				if (sceneTrigger != SceneTrigger.UNKNOWN)
				{
					if (blockNum == startBlock + 1)
					{
						trigger = sceneTrigger;
						var mainID = block.parameters.length > 0 ? block.parameters[0] : "";
						switch(trigger)
						{
							case SceneTrigger.INTRO, SceneTrigger.BATTLE, SceneTrigger.OUTRO, SceneTrigger.REWARDS:
								if (mainID == "")
								{
									error(blockNum, lineNum, "Block type \"" + trigger + "\" requires a pearl ID! context:(" + block + ")");
								}
								else
								{
									pearlID = mainID;
								}
							case SceneTrigger.TOWN:
								if (mainID == "")
								{
									error(blockNum, lineNum, "Block type \"" + trigger + "\" requires a town ID! context:(" + block + ")");
								}
								else
								{
									townID = mainID;
								}
						}
						triggerParams = block.parameters.copy();
					}
					else
					{
						error(blockNum, lineNum, "Block type \"" + sceneTrigger + "\" must always occur immediately after a BEGIN block! context:(" + block + ")");
						return;
					}
				}
			}
			
			blockNum++;
			lineNum += block.linesConsumed;
		}
		
		var p = getParam("pearl");
		if (p != "" && p != null)
		{
			p = Util.padLeft(p, 3);
		}
		
		name = "";
		
		switch(trigger)
		{
			case SceneTrigger.NEWGAME: name = "_intro";
			case SceneTrigger.INTRO:   name = p + "_intro";
			case SceneTrigger.OUTRO:   name = p + "_outro";
			case SceneTrigger.BATTLE:  name = p + "_battle";
			case SceneTrigger.REWARDS: name = p + "_rewards";
			case SceneTrigger.TOWN:    
				var town = getParam("town");
				var section = getParam("section");
				name = "town_" + town + "_" + section + "_" + p;
			case SceneTrigger.PARTY:   
				var section = getParam("section");
				if (p != "") name = p + "_party";
				if (section != "") name = name + "_" + section;
				if (p == "" && section == "") name = name + "__" + Util.padDigits(number, 3);
			case SceneTrigger.OVERWORLD: 
				if (p != "") name = p + "_overworld";
				if (p == "") name = "_overworld__" + Util.padDigits(number, 3);
			default:
				name = title.uReplace(" ", "_");
				name = name.stripStuff();
				name = Utf8Ext.toLowerCase(name);
				name = Std.string(Util.padDigits(number, 3)).uCat("_").uCat(name);
		}
		
		var begin = getBlock(Keyword.BEGIN);
		if (begin != null)
		{
			plotLine = begin.getParameter("plotline");
			if (plotLine == "" || plotLine == null)
			{
				plotLine = switch(trigger)
				{
					case SceneTrigger.NEWGAME, SceneTrigger.INTRO, SceneTrigger.OUTRO:  "default_pearls";
					case SceneTrigger.OVERWORLD: "default_overworld";
					case SceneTrigger.BATTLE: "default_battles";
					case SceneTrigger.TOWN: "default_towns";
					case SceneTrigger.PARTY: "default_party";
					case SceneTrigger.REWARDS: "default_rewards";
					default: "default_unknown";
				}
			}
		}
	}
		
	public function getParam(string:String):String
	{
		string = Utf8Ext.toLowerCase(string);
		return switch(trigger)
		{
			case SceneTrigger.NEWGAME:   "";
			case SceneTrigger.INTRO:     getParam_INTRO(string);
			case SceneTrigger.OUTRO:     getParam_OUTRO(string);
			case SceneTrigger.TOWN:      getParam_TOWN(string);
			case SceneTrigger.BATTLE:    getParam_BATTLE(string);
			case SceneTrigger.REWARDS:   getParam_REWARDS(string);
			case SceneTrigger.PARTY:     getParam_PARTY(string);
			case SceneTrigger.OVERWORLD: getParam_OVERWORLD(string);
			default: "";
		}
	}
	
	private function getBlock(keyword:Keyword):Block
	{
		for (block in blocks)
		{
			if (block.keyword == keyword)
			{
				return block;
			}
		}
		return null;
	}
	
	private function getParam_GENERIC(i:Int, string:String=""):String
	{
		if (i == -1) return "";
		
		if (triggerParams != null && triggerParams.length > i)
		{
			return triggerParams[i];
		}
		else if(string != "")
		{
			var block = getBlock(string);
			if (block != null)
			{
				for (line in block.lines)
				{
					string = Utf8Ext.toLowerCase(string).uCat(" ");
					var lowerline = Utf8Ext.toLowerCase(line);
					if (lowerline.uIndexOf(string) == 0)
					{
						var value = lowerline.uReplace(string, "");
						if (value != null && value != "")
						{
							return value;
						}
					}
				}
			}
		}
		return "";
	}
	
	private function getParam_BATTLE(string:String):String
	{
		var i:Int = switch(string)
		{
			case "pearl": 0;
			default: -1;
		}
		return getParam_GENERIC(i, string);
	}
	
	private function getParam_OUTRO(string:String):String
	{
		var i:Int = switch(string)
		{
			case "pearl": 0;
			default: -1;
		}
		return getParam_GENERIC(i, string);
	}
	
	private function getParam_INTRO(string:String):String
	{
		var i:Int = switch(string)
		{
			case "pearl": 0;
			default: -1;
		}
		return getParam_GENERIC(i, string);
	}
	
	private function getParam_OVERWORLD(string:String):String
	{
		var i:Int = switch(string)
		{
			case "pearl": 0;
			default: -1;
		}
		return getParam_GENERIC(i, string);
	}
	
	private function getParam_REWARDS(string:String):String
	{
		var i:Int = switch(string)
		{
			case "pearl": 0;
			default: -1;
		}
		return getParam_GENERIC(i, string);
	}
	
	private function getParam_PARTY(string:String):String
	{
		var i:Int = switch(string)
		{
			case "pearl": 0;
			case "section": 1;
			default: -1;
		}
		return getParam_GENERIC(i, string);
	}
	
	private function getParam_TOWN(string:String):String
	{
		var i:Int = switch(string)
		{
			case "town": 0;
			case "section": 1;
			case "pearl": 2;
			default: -1;
		}
		return getParam_GENERIC(i, string);
	}
	
	public static function error(block:Int, line:Int, msg:String)
	{
		ScriptParser.error(block, line, msg);
	}
}