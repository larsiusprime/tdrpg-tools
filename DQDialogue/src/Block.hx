package;
import org.zamedev.lib.Utf8Ext;

/**
 * ...
 * @author 
 */

using unifill.Unifill;
using Util;

class Block
{
	public var keyword:Keyword;
	public var parameters:Array<String>;
	public var lines:Array<String>;
	public var number:Int = 0;
	public var lineNumber:Int = 0;
	public var linesConsumed:Int = 0;
	public var error:DocumentError;
	
	public function new(str:String, names:Array<String>, Number:Int, LineNumber:Int)
	{
		number = Number;
		lineNumber = LineNumber;
		error = parse(str, names);
	}
	
	public function getParameter(name:String = "", default_:String = ""):String
	{
		name = name.toLowerCase();
		var value = switch(keyword)
		{
			case Keyword.ACTION: getParameter_ACTION(name);
			case Keyword.NARRATOR: getParameter_NARRATOR(name);
			case Keyword.BEGIN: getParameter_BEGIN(name);
			case Keyword.SPEECH: getParameter_SPEECH(name);
			case Keyword.TUTORIAL: getParameter_TUTORIAL(name);
			case Keyword.DUB: getParameter_DUB(name);
			case Keyword.JOIN: getParameter_JOIN(name);
			default: getParameter_GENERIC( -1, name);
		}
		if (value == "")
		{
			return default_;
		}
		return value;
	}
	
	private function getParameter_ACTION(name:String):String
	{
		var value = "";
		var i = 0;
		switch(name)
		{
			case "text": 
				for (line in lines)
				{
					if (Utf8Ext.toLowerCase(line).indexOf("text") == 0)
					{
						value = Util.cutStrCaseInsensitive(line, "text ");
						break;
					}
					i++;
				}
			default: value = "";
		}
		return value;
	}
	
	private function getParameter_NARRATOR(name:String):String
	{
		var value = "";
		switch(name)
		{
			case "background": value = getParameter_GENERIC(0, name);
			default: value = "";
		}
		return value;
	}
	
	private function getParameter_JOIN(name:String):String
	{
		var value = "";
		switch(name)
		{
			case "character": value = getParameter_GENERIC(0, name);
			case "name": value = getParameter_GENERIC(1, name);
			case "class": value = getParameter_GENERIC(2, name);
			default: value = "";
		}
		return value;
	}
	
	private function getParameter_DUB(name:String):String
	{
		var value = "";
		switch(name)
		{
			case "character": value = getParameter_GENERIC(0, name);
			case "class": value = getParameter_GENERIC(1, name);
			case "text": 
				for (line in lines){
					var lline = Utf8Ext.toLowerCase(line);
					if (lline.uIndexOf("character") == 0 || lline.uIndexOf("class") == 0)
					{
						continue;
					}
					value = line;
				}
			default: value = ""; 
		}
		return value;
	}
	
	private function getParameter_SPEECH(name:String):String
	{
		return switch(name)
		{
			case "speaker": getParameter_GENERIC(0, name);
			case "emote": getParameter_GENERIC(1, name);
			case "sound": getParameter_GENERIC(999, name);
			case "effect": getParameter_GENERIC(999, name);
			default: "";
		}
	}
	
	private function getParameter_TUTORIAL(name:String):String
	{
		return switch(name)
		{
			case "trigger":
			               getParameter_GENERIC(0, name);
			case "id":     getParameter_GENERIC(0, name);
			case "arrow", "click", "locked": 
			               getParameter_GENERIC(0, name);
			case "input":  getParameter_GENERIC(0, name);
			case "target": getParameter_GENERIC(0, name);
			case "facing": getParameter_GENERIC(0, name);
			case "offset": getParameter_GENERIC(0, name);
			case "style":  getParameter_GENERIC(0, name);
			case "mouse": getParameter_GENERIC(0, name);
			case "title":  getParameter_GENERIC(0, name);
			case "action": getParameter_GENERIC(0, name);
			case "tags", "subtags": getParameter_GENERIC(0, name);
			case "speaker": getParameter_GENERIC(0, name);
			case "background": getParameter_GENERIC(0, name);
			case "overlay": getParameter_GENERIC(0, name);
			case "emote": getParameter_GENERIC(0, name);
			case "sound": getParameter_GENERIC(999, name);
			case "effect": getParameter_GENERIC(999, name);
			default: "";
		}
	}
	
	private function getParameter_BEGIN(name:String):String
	{
		return switch(name)
		{
			case "plotline", "background", "overlay", "music", "demo music", "act", "scene", "foreground left", "foreground right": getParameter_GENERIC( -1, name);
			default: "";
		}
	}
	
	private function getParameter_GENERIC(i:Int = -1, name:String = ""):String
	{
		if (i == -1) return "";
		
		var isAction = false;
		if (name == "action"){
			isAction = true;
		}
		
		if (parameters != null && parameters.length > i)
		{
			return parameters[i];
		}
		else if(name != "" && lines != null)
		{
			name = Utf8Ext.toLowerCase(name).uCat(" ");
			for (line in lines)
			{
				var lowerline = Utf8Ext.toLowerCase(line);
				if (lowerline.uIndexOf(name) == 0)
				{
					var value = lowerline.uReplaceStart(name, "", false);
					if (value != null && value != "")
					{
						return value;
					}
				}
			}
		}
		
		return "";
	}
	
	public function parse(str:String, names:Array<String>):DocumentError
	{
		var arr = str.uSplit("\n");
		
		parameters = [];
		lines = [];
		keyword = Keyword.UNKNOWN;
		
		var deadLines:Int = 0;
		
		if (arr != null && arr.length > 0)
		{
			for(i in 0...arr.length)
			{
				var j = arr.length - 1 - i;
				var foundText = false;
				if (arr[j] == null || arr[j] == "" || arr[j] == "\n")
				{
					if (!foundText)
					{
						lineNumber++;
					}
					deadLines++;
					arr.splice(j, 1);
				}
				else
				{
					foundText = true;
				}
			}
			
			if (arr == null || arr.length == 0 || (arr.length == 1 && arr[0] == null))
			{
				arr = [Keyword.IGNORED];
			}
			
			var keyLine = arr[0];
			
			if (keyLine != null && keyLine.length > 0 && keyLine != "")
			{
				keyLine = Utf8Ext.toLowerCase(keyLine);
				
				//check for recognized names
				for (name in names)
				{
					var lowerName = Utf8Ext.toLowerCase(name);
					if (keyLine.uIndexOf(lowerName) == 0)
					{
						parameters.push(name);
						keyLine = keyLine.uReplace(lowerName, Keyword.SPEECH);
						break;
					}
					else if (keyLine.uIndexOf(lowerName) != -1)
					{
						keyLine = StringTools.replace(keyLine, lowerName, "");
						parameters.push(name);
						break;
					}
				}
				
				keyLine = keyLine.stripStuff();
				var keyCells = keyLine.uSplit(" ");
				
				if (keyCells != null && keyCells.length > 0 && keyLine != "")
				{
					keyword = Keyword.fromString(keyCells[0]);
					
					if (keyword == Keyword.UNKNOWN)
					{
						return err(number, lineNumber, "unknown keyword: \"" + keyCells[0] + "\"", str);
					}
					else
					{
						if (keyCells.length > 0)
						{
							for (i in 1...keyCells.length)
							{
								var param = keyCells[i];
								if (param != null && param != "")
								{
									param = Utf8Ext.toLowerCase(param);
									parameters.push(param);
								}
							}
						}
						lines = arr.splice(1, arr.length - 1);
					}
				}
				else
				{
					return err(number, lineNumber, "could not split key line: \"" + keyLine + "\" into cells", str);
				}
			}
			else
			{
				return err(number, lineNumber, "no keyline found in block string: \"" + str + "\"");
			}
		}
		else
		{
			return err(number, lineNumber, "could not parse block string: \"" + str + "\"");
		}
		
		switch(keyword)
		{
			case BEGIN:
				if (lines == null || lines.length < 1)
				{
					return err(number, lineNumber, "BEGIN block requires one line, found 0 : (" + lines + ")", str);
				}
		}
		
		linesConsumed = lines.length + deadLines + 2;
		
		return null;
	}
	
	public function toString():String
	{
		return Util.uCombine(["{keyword:", keyword, ",parameters:", Std.string(parameters), ",lines:", Std.string(lines), "}"]);
	}
	
	public static function err(block:Int, line:Int, msg:String, ?context:String):DocumentError
	{
		return new DocumentError(block, line, msg, context);
	}
}