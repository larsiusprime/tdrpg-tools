package;
import firetongue.TSV;
import haxe.xml.Fast;

/**
 * ...
 * @author 
 */
class Cutscene
{

	public function new() 
	{
		
	}
	
	public static function process(xml:Fast, tsv:TSV, outfile:String)
	{
		var arr:Array<{act:String,scene:String,text:String}> = [];
		
		for (sceneNode in xml.node.scenes.nodes.scene)
		{
			var title = U.xmlStr(sceneNode, "title");
			var act = U.xmlStr(sceneNode, "act");
			var scene = U.xmlStr(sceneNode, "scene");
			
			var text = writeToScript(title, act, scene, tsv);
			arr.push({act:act, scene:scene, text:text});
		}
		
		U.writeStr(outputText(arr), outfile);
	}
	
	private static function outputText(arr:Array<{act:String,scene:String,text:String}>):String
	{
		arr.sort(
			function (a:{act:String, scene:String, text:String}, b:{act:String, scene:String, text:String}):Int
			{
				if (a.act < b.act) return -1;
				if (a.act > b.act) return  1;
				if (a.scene < b.scene) return -1;
				if (a.scene > b.scene) return  1;
				return 0;
			}
		);
		
		var text = "";
		
		for (i in 0...arr.length)
		{
			if (text != "")
			{
				text += "\n\n";
			}
			text += arr[i].text;
		}
		
		return text;
	}
	
	private static function writeToScript(title:String, act:String, scene:String, tsv:TSV):String
	{
		var titleStr = "------------------------------\nAct " + act;
		
		if (scene.indexOf("quest_") != -1)
		{
			var num = StringTools.replace(scene, "quest_", "");
			titleStr += ", Quest " + num;
		}
		else if (scene.indexOf("end_") != -1)
		{
			var num = StringTools.replace(scene, "end_", "");
			titleStr += ", End " + num.toUpperCase();
		}
		else
		{
			titleStr += ", Scene " + scene;
		}
		
		titleStr += ": " + U.getLine(title, tsv);
		
		var bodyStr = "";
		
		var i = U.tsvGetLineNum(title, tsv);
		
		var speaker = "";
		var lastSpeaker = "";
		
		var nextFlag = tsv.grid[i][0];
		var nextLine = tsv.grid[i][1];
		
		while (true)
		{
			if (nextFlag.indexOf("$NARR_") == 0)
			{
				lastSpeaker = speaker;
				speaker = "NARRATOR";
			}
			else if (nextFlag.indexOf("_CHAR") != -1)
			{
				lastSpeaker = speaker;
				speaker = U.doReplace(nextLine);
			}
			
			if (nextFlag.indexOf("_TEXT") != -1)
			{
				if (speaker != lastSpeaker)
				{
					bodyStr += "\n" + speaker.toUpperCase() + ":\n";
				}
				
				bodyStr += U.doReplace(nextLine) + "\n";
			}
			
			i++;
			
			if (i >= tsv.grid.length)
			{
				break;
			}
			
			nextFlag = tsv.grid[i][0];
			nextLine = tsv.grid[i][1];
		
			if (nextFlag.indexOf("$SCENE_") == 0)
			{
				break;
			}
		}
		
		return titleStr + "\n" + bodyStr;
	}
}