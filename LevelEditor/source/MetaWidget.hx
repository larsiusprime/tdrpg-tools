package;
import flixel.addons.ui.FlxUI;
import flixel.addons.ui.FlxUIButton;
import flixel.addons.ui.FlxUICheckBox;
import flixel.addons.ui.FlxUIGroup;
import flixel.addons.ui.FlxUILine;
import flixel.addons.ui.FlxUIRadioGroup;
import flixel.addons.ui.FlxUISprite;
import flixel.addons.ui.interfaces.IFlxUIWidget;
import flixel.util.FlxColor;

/**
 * ...
 * @author 
 */
class MetaWidget extends FlxUIGroup
{
	public static inline var W:Int = 700;
	public static inline var H:Int = 72;
	
	public var box:FlxUIGroup;
	public var meta:MetaEntry;
	
	public var difficulty:FlxUIRadioGroup;
	public var firstWait:NumberWidget;
	public var endless:FlxUICheckBox;
	public var endlessLevelup:NumberWidget;
	public var isBonus:FlxUICheckBox;
	
	public function new(X:Float=0,Y:Float=0) 
	{
		super(X, Y);
		init();
	}
	
	public function sync(Meta:MetaEntry,refresh:Bool=true){
		meta = Meta;
		
		var i = Util.diffI(meta.difficulty);
		var info = meta.infos[i];
		
		difficulty.selectedId = meta.difficulty;
		endlessLevelup.stepper.value = info.endlessLevelup;
		endless.checked = info.isEndless;
		isBonus.checked = info.isBonus;
		firstWait.stepper.value = info.firstWait;
		
		if(refresh){
			refreshRadios();
		}
		
	}
	
	override public function destroy():Void 
	{
		box = null;
		super.destroy();
	}
	
	public function write(meta:MetaEntry){
		if (meta == null) return;
		meta.difficulty = difficulty.selectedId;
		
		var i = switch(meta.difficulty){
			case "easy": 0;
			case "normal": 1;
			case "hard": 2;
			default: 0;
		}
		
		meta.infos[i].endlessLevelup = Std.int(endlessLevelup.stepper.value);
		meta.infos[i].isEndless = endless.checked;
		meta.infos[i].firstWait = firstWait.stepper.value;
		meta.infos[i].isBonus = isBonus.checked;
	}
	
	public function owns(widget:IFlxUIWidget){
		var fast = members.indexOf(cast widget) != -1;
		if (fast) return true;
		for (member in members){
			if (Std.is(member, FlxUIGroup)){
				var g:FlxUIGroup = cast member;
				if (g.members.indexOf(cast widget) != -1){
					return true;
				}
			}
		}
		return false;
	}
	
	private function init()
	{
		var chrome = new FlxUISprite();
		chrome.makeGraphic(1, 1, FlxColor.WHITE);
		chrome.scale.set(W, H);
		chrome.updateHitbox();
		add(chrome);
		box = Util.makeBox(W, H);
		add(box);
		
		var Y = 20;
		
		difficulty = Util.makeRadios(5, 5, ["easy", "normal", "hard"], ["Normal", "Advanced", "Extreme"], 
			function(str:String){
				onDiffChange();
			}
		);
		difficulty.selectedId = "easy";
		add(difficulty);
		
		var ww = Std.int(H * 0.8);
		var dx = ww + 38;
		
		firstWait = new NumberWidget(100, Y, ww, "First wait", 0.1, 1.0, 0.0, 60.0, 1);
		add(firstWait);
		
		var X = 100 + dx;
		
		endless = Util.makeCheckbox(X, Y, "Endless", onChange);
		add(endless);
		
		X += dx;
		
		endlessLevelup = new NumberWidget(X, Y, ww, "Endless levelup", 1, 0, 0, 99, 0);
		add(endlessLevelup);
		
		X += dx;
		
		isBonus = Util.makeCheckbox(X, Y, "Is bonus level", onChange);
		add(isBonus);
	}
	
	private function onWaveChange(){
		FlxUI.event("wave_change", null, null);
	}
	
	private function onDiffChange(){
		var diff = difficulty.selectedId;
		meta.difficulty = diff;
		var i = Util.diffI(diff);
		sync(meta);
		refreshRadios();
		onWaveChange();
	}
	
	private function onChange(){
		if (meta == null) return;
		trace("WRITE");
		write(meta);
		refreshRadios();
	}
	
	private function refreshRadios()
	{
		var i = Util.diffI(meta.difficulty);
		if (meta.infos[i].isBonus){
			Util.activateRadios(difficulty, ["normal", "hard"], false);
			difficulty.selectedId = "easy";
			meta.difficulty = "easy";
			sync(meta, false);
			meta.infos[0].isBonus = true;
			isBonus.checked = true;
			onWaveChange();
			if(i != 0){
				meta.infos[i].isBonus = false;
			}
		}else{
			Util.activateRadios(difficulty, ["easy", "normal", "hard"], true);
		}
	}
	
	override function set_visible(Value:Bool):Bool 
	{
		var vis = super.set_visible(Value);
		return vis;
	}
}

typedef MetaEntry =
{
	var difficulty:String;
	var infos:Array<MetaInfo>;
}

typedef MetaInfo = 
{
	var difficulty:String;
	var firstWait:Float;
	var endlessLevelup:Int;
	var isEndless:Bool;
	var isBonus:Bool;
}