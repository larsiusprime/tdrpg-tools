package;
import firetongue.TSV;
import haxe.xml.Fast;

/**
 * ...
 * @author 
 */
class Maps
{

	public function new() 
	{
		
	}
	
	public static function process(xml:Fast, tsv:TSV, outfile:String)
	{
		var str:String = "";
		
		for (pearlNode in xml.node.data.node.pearl_data.nodes.pearl)
		{
			var title = U.xmlStr(pearlNode, "level");
			var desc  = U.xmlStr(pearlNode, "description");
			var id    = U.xmlStr(pearlNode, "level_id");
			var type  = U.xmlStr(pearlNode, "_type");
			
			var text = writeToScript(title, desc, id, type, tsv);
			if (str != "") { str += "\n\n"; }
			str += text;
		}
		
		U.writeStr(str, outfile);
	}
	
	private static function writeToScript(title:String, desc:String, id:String, type:String, tsv:TSV):String
	{
		var titleStr = U.doReplace(U.tsvGet(title, tsv));
		var descStr  = U.doReplace(U.tsvGet(desc, tsv));
		
		var str = "------------------------\n" + titleStr + "\n" + descStr + "\n";
		
		var firstFlag = "$" + id.toUpperCase() + "_00_TITLE";
		var i = U.tsvGetLineNum(firstFlag, tsv);
		
		if (i != -1)
		{
			var nextFlag = tsv.grid[i][0];
			var nextLine = tsv.grid[i][1];
			
			var speaker = "";
			var lastSpeaker = "";
			
			while (true)
			{
				if (nextFlag != null && nextFlag.indexOf("_TITLE") != -1)
				{
					if (nextLine != null && nextLine.indexOf("TALK_") != -1)
					{
						var flagArr = nextLine.split("_");
						if (flagArr != null && flagArr.length >= 2)
						{
							lastSpeaker = speaker;
							speaker = U.doReplace(flagArr[1]).toUpperCase();
							Sys.println("flagArr = " + flagArr);
						}
					}
					else if (nextLine == "" || nextLine == null)
					{
						lastSpeaker = speaker;
						speaker = "TUTORIAL";
					}
				}
				
				if (nextFlag.indexOf("_TEXT") != -1)
				{
					if (speaker != lastSpeaker)
					{
						str += "\n" + speaker + ":\n";
					}
					str += U.doReplace(nextLine) + "\n";
				}
				
				i++;
				
				if (i >= tsv.grid.length)
				{
					break;
				}
				
				nextFlag = tsv.grid[i][0];
				nextLine = tsv.grid[i][1];
				
				if (nextFlag.indexOf("_00_TITLE") != -1)
				{
					break;
				}
			}
		}
		
		return str;
	}
}