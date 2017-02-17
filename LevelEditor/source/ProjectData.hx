package;
import haxe.xml.Fast;
import sys.FileSystem;
import sys.io.File;

import BattleData.BonusStruct;

/**
 * ...
 * @author 
 */
class ProjectData
{
	public var bonusData:Array<BonusStruct>;
	
	private var path:String;
	
	public function new(Path:String)
	{
		path = Path;
		loadBonus();
	}
	
	public function loadBonus()
	{
		bonusData = [];
		var bonusPath = Util.safePath(path, "_append/xml/bonus.xml");
		if (FileSystem.exists(bonusPath))
		{
			var xmlString:String = File.getContent(bonusPath);
			var bonusXML:Fast = new Fast(Util.xmlify(xmlString));
			
			bonusData = BonusStruct.arrayFromXML(bonusXML);
		}
		
	}
	
}