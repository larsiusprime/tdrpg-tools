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
	
	public function new()
	{
		load();
	}
	
	public function clear(){
		devPath = "";
		modPath = "";
		installPath = "";
		save();
	}
	
	public function save(){
		trace("save");
		var name = FlxG.save.name;
		if (FlxG.save.bind("level_editor_data")){
			setStr("devPath", devPath);
			setStr("modPath", modPath);
			setStr("installPath", installPath);
			setStr("devPath2", devPath2);
			trace("modPath = " + modPath);
			trace("FlxG.save.data = " + FlxG.save.data);
			FlxG.save.flush();
		}
		FlxG.save.bind(name);
	}
	
	public function load(){
		trace("load");
		var name = FlxG.save.name;
		if (FlxG.save.bind("level_editor_data")){
			trace("FlxG.save.data = " + FlxG.save.data);
			devPath = getStr("devPath");
			devPath2 = getStr("devPath2");
			modPath = getStr("modPath");
			installPath = getStr("installPath");
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
		trace("setStr field("+field+","+value+") now = " + Reflect.field(FlxG.save.data, field));
	}
}