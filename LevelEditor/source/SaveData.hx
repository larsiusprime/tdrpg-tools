package;
import flixel.FlxG;
import flixel.util.FlxSave;

/**
 * ...
 * @author 
 */
class SaveData
{
	public var devPath:String = "";
	public var devPath2:String = "";
	public var modPath:String = "";
	public var installPath:String = "";
	public var mapID:String = "";
	public var saveName:String = "";
	
	public function new(saveName:String)
	{
		if (saveName != "DefendersQuest")
		{
			this.saveName = saveName;
		}
		load();
	}
	
	public function clear(){
		devPath = "";
		devPath2 = "";
		modPath = "";
		installPath = "";
		mapID + "";
		save();
	}
	
	public function save(){
		var name = FlxG.save.name;
		if (FlxG.save.bind("level_editor_data"+saveName )){
			setStr("devPath", Util.fixDoubleSlash(devPath));
			setStr("modPath", Util.fixDoubleSlash(modPath));
			setStr("installPath", Util.fixDoubleSlash(installPath));
			setStr("devPath2", Util.fixDoubleSlash(devPath2));
			setStr("mapID", mapID);
			FlxG.save.flush();
		}
		FlxG.save.bind(name);
	}
	
	public function load(){
		var name = FlxG.save.name;
		if (FlxG.save.bind("level_editor_data"+saveName)){
			devPath = Util.fixDoubleSlash(getStr("devPath"));
			devPath2 = Util.fixDoubleSlash(getStr("devPath2"));
			modPath = Util.fixDoubleSlash(getStr("modPath"));
			installPath = Util.fixDoubleSlash(getStr("installPath"));
			mapID = getStr("mapID");
			FlxG.save.flush();
		}
		FlxG.save.bind(name);
	}
	
	private function getStr(field:String):String{
		if (Reflect.hasField(FlxG.save.data, field)){
			return Std.string(Reflect.field(FlxG.save.data, field));
		}
		return "";
	}
	
	private function setStr(field:String, value:String){
		Reflect.setField(FlxG.save.data, field, value);
	}
}