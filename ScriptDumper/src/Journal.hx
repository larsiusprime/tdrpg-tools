package;
import firetongue.TSV;
import haxe.xml.Fast;

/**
 * ...
 * @author 
 */
class Journal
{

	public function new() 
	{
		
	}
	
	public static function process(xml:Fast, tsv:TSV, outfile:String)
	{
		var str:String = "";
		
		for (entryNode in xml.node.data.nodes.entry)
		{
			var title = U.xmlStr(entryNode, "level");
			var titleStr = U.getLine(title, tsv);
			
			if (str != "") { str += "\n\n"; }
			str += "-------------------\n"+titleStr;
			
			var lastSide = "";
			var lastPage = "";
			var side = "";
			var page = "";
			
			var pageCount:Int = 0;
			
			for (pageNode in entryNode.nodes.page)
			{
				lastSide = side;
				lastPage = page;
				
				side = U.xmlStr(entryNode, "side");
				page = U.xmlStr(entryNode, "sub_page");
				
				if (page != lastPage)
				{
					str += "\n\n" + page.toUpperCase() + " SIDE:";
				}
				
				if (side != lastSide)
				{
					str += "\n\n(TURN PAGE)";
				}
				
				for (textNode in pageNode.nodes.text)
				{
					if (textNode != null)
					{
						var x = textNode.x;
						if (x != null)
						{
							var fc = x.firstChild();
							if (fc != null)
							{
								var pageText = fc.nodeValue;
								pageText = U.getLine(pageText, tsv);
								str += "\n\n" + jReplace(pageText);
							}
						}
					}
				}
			}
		}
		
		U.writeStr(str, outfile);
	}
	
	private static function jReplace(pageText):String
	{
		var line = U.doReplace(pageText);
		for (i in 0...replaceFlags.length)
		{
			var flag = replaceFlags[i];
			while (line.indexOf(flag) != -1)
			{
				line = StringTools.replace(line, flag, replaceStrings[i]);
			}
			if (line.indexOf("*") == 0)
			{
				line = line.substr(1, line.length - 1);
			}
		}
		return line;
		
	}
	
	private static var replaceFlags   = ["@",
		"[mcguffin_hero]",
		"[mcguffin_hero_fu]",
		"[mcguffin_hero_up]",
		"[mcguffin_hero_pos]",
		"[mcguffin_hero_pos_up]",
		"[berserker_hero]",
		"[berserker_hero_fu]",
		"[berserker_hero_up]",
		"[berserker_hero_pos]",
		"[berserker_hero_pos_up]",
		"[ranger_hero]",
		"[ranger_hero_fu]",
		"[ranger_hero_up]",
		"[ranger_hero_pos]",
		"[ranger_hero_pos_up]",
		"[healer_hero]",
		"[healer_hero_fu]",
		"[healer_hero_up]",
		"[healer_hero_pos]",
		"[healer_hero_pos_up]",
		"[mage_hero]",
		"[mage_hero_fu]",
		"[mage_hero_up]",
		"[mage_hero_pos]",
		"[mage_hero_pos_up]",
		"[knight_hero]",
		"[knight_hero_fu]",
		"[knight_hero_up]",
		"[knight_hero_pos]",
		"[knight_hero_pos_up]",
		"[dragon_hero]",
		"[dragon_hero_fu]",
		"[dragon_hero_up]",
		"[dragon_hero_pos]",
		"[dragon_hero_pos_up]"
	];
	private static var replaceStrings = ["",
		"Azra", 
		"Azra", 
		"AZRA", 
		"Azra's", 
		"AZRA'S",
		"Slak", 
		"Slak", 
		"SLAK", 
		"Slak's", 
		"SLAK'S", 
		"Ketta", 
		"Ketta", 
		"KETTA", 
		"Ketta's", 
		"KETTA'S", 
		"Bakal", 
		"Bakal", 
		"BAKAL", 
		"Bakal's", 
		"BAKAL'S", 
		"Wrenna",
		"Wrenna",
		"WRENNA",
		"Wrenna's", 
		"WRENNA'S",
		"Markos", 
		"Markos", 
		"MARKOS", 
		"Markos's", 
		"MARKOS'S",
		"Niru", 
		"Niru", 
		"NIRU", 
		"Niru's",
		"NIRU'S"
	];
	
}