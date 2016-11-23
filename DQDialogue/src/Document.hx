package;
import haxe.EnumTools;
import unifill.CodePoint;
import unifill.Unicode;

using unifill.Unifill;
using StringTools;
using org.zamedev.lib.Utf8Ext;
using Util;

/**
 * ...
 * @author 
 */
class Document
{
	public var scenes:Array<Scene>;
	
	public function new(str:String)
	{
		scenes = [];
		
		//remove all carriage returns
		str = str.uStrip(["\r"]);
		
		//split the string into blocks by double-line-breaks
		var rawBlocks = str.uSplit("\n\n");
		
		var blocks = [];
		
		var names = [];
		
		var sceneBlocks = null;
		
		var lineNum:Int = 0;
		var blockNum:Int = 1;
		var sceneNum:Int = 0;
		
		for (rawBlock in rawBlocks)
		{
			var ln = lineNum + 1;
			
			if (rawBlock != "" && rawBlock != null)
			{
				var block = new Block(rawBlock, names, blockNum, ln);
				
				if (block.error != null)
				{
					error(block.error.block, block.error.line, block.error.message);
					return;
				}
				
				if (blockNum == rawBlocks.length - 1)
				{
					if (sceneBlocks != null && block.keyword != Keyword.END)
					{
						error(blockNum, lineNum, "End of file reached with an unterminated block! context:\"" + rawBlock + "\"");
						return;
					}
				}
				
				switch(block.keyword)
				{
					case Keyword.BEGIN:
						if (sceneBlocks == null)
						{
							sceneBlocks = [block];
						}
						else
						{
							error(blockNum, lineNum, "Multiple BEGIN blocks found in the same scene! context:\"" + rawBlock + "\"");
							return;
						}
					case Keyword.END: 
						if (sceneBlocks != null)
						{
							var scene = null;
							try
							{
								scene = new Scene(sceneBlocks, blockNum, sceneNum);
								sceneNum++;
							}
							catch (msg:String)
							{
								error(blockNum, lineNum, msg);
								return;
							}
							
							if (scene != null)
							{
								scenes.push(scene);
							}
							sceneBlocks = null;
						}
						else
						{
							error(blockNum, lineNum, "END block found without a matching BEGIN! context:\"" + rawBlock + "\"");
							return;
						}
					case Keyword.ERROR:
						error(blockNum, lineNum, block.parameters.uJoin(","));
						return;
					case Keyword.NAMES:
						names = block.lines.copy();
				}
				
				if (block.keyword == Keyword.IGNORED)
				{
					lineNum += 2;
				}
				else
				{
					blockNum++;
					lineNum += block.linesConsumed;
				}
				
				if (block != null && block.error == null)
				{
					switch(block.keyword)
					{
						case Keyword.BEGIN, Keyword.END, Keyword.ERROR, Keyword.UNKNOWN, Keyword.IGNORED, Keyword.NAMES:
							//donothing
						default:
							if (sceneBlocks == null)
							{
								error(blockNum, lineNum, "\""+block.keyword + "\" block found before BEGIN block! context:\"" + rawBlock + "\"");
							}
							else
							{
								sceneBlocks.push(block);
							}
					}
				}
			}
			else
			{
				lineNum += 2;
			}
		}
	}
	
	public function error(block:Int,line:Int,msg:String)
	{
		ScriptParser.error(block, line, msg);
	}
}