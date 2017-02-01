package;
import flixel.addons.ui.FlxUI;
import flixel.addons.ui.FlxUIButton;
import flixel.addons.ui.FlxUIGroup;
import flixel.addons.ui.FlxUILine;
import flixel.addons.ui.FlxUISprite;
import flixel.addons.ui.interfaces.IFlxUIWidget;
import flixel.util.FlxColor;

/**
 * ...
 * @author 
 */
class WaveWidget extends FlxUIGroup
{
	public static inline var W:Int = 700;
	public static inline var H:Int = 72;
	
	public var sigils:SigilWidget;
	public var count:NumberWidget;
	public var wait:NumberWidget;
	public var level:NumberWidget;
	public var rate:NumberWidget;
	public var type:ButtonWidget;
	public var plusMinus:FlxUIButton;
	public var box:FlxUIGroup;
	public var info:WaveInfo;
	
	public var empty(default, set):Bool = false;
	
	public function new(X:Float=0,Y:Float=0) 
	{
		super(X, Y);
		init();
	}
	
	public function sync(Info:WaveInfo){
		info = Info;
		sigils.sync(info);
		count.stepper.value = info.count;
		wait.stepper.value = info.wait;
		level.stepper.value = info.level;
		rate.stepper.value = info.rate;
		type.button.label.text = info.type;
	}
	
	override public function destroy():Void 
	{
		info = null;
		sigils = null;
		count = null;
		wait = null;
		level = null;
		rate = null;
		type = null;
		plusMinus = null;
		box = null;
		super.destroy();
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
	
	public function write(info:WaveInfo){
		trace("write before info.starts = " + info.starts);
		info.count = Std.int(count.stepper.value);
		info.wait = wait.stepper.value;
		info.level = Std.int(level.stepper.value);
		info.rate = rate.stepper.value;
		info.type = type.button.label.text;
		info.starts = sigils.starts.copy();
		info.ends = sigils.ends.copy();
		trace("write after info.starts = " + info.starts);
	}
	
	public function setType(typeStr:String){
		trace("setType(" + typeStr + ")");
		type.button.label.text = typeStr;
		type.button.autoCenterLabel();
		if (info != null){
			info.type = typeStr;
		}
	}
	
	private function init()
	{
		var chrome = new FlxUISprite();
		chrome.makeGraphic(1, 1, FlxColor.WHITE);
		chrome.scale.set(W, H);
		chrome.updateHitbox();
		add(chrome);
		box = makeBox(W, H);
		add(box);
		
		sigils = new SigilWidget(4,Std.int(H/4),H/2);
		add(sigils);
		
		var X = 4 + sigils.width + 8;
		var Y = 20;
		var ww = Std.int(H*0.8);
		var dx = ww + 38;
		
		type = new ButtonWidget(X, Y - 8, H * 2, H, "type", "normal", onType);
		add(type);
		X += ww*2 + 38;
		
		count = new NumberWidget(X, Y, ww, "count", 1, 0, 0, 99);
		add(count);
		X += dx;
		
		wait = new NumberWidget(X, Y, ww, "wait", 0.1, 1, 0, 60, 1);
		add(wait);
		X += dx;
		
		level = new NumberWidget(X, Y, ww, "level", 1, 1, 1, 99);
		add(level);
		X += dx;
		
		rate = new NumberWidget(X, Y, ww, "rate", 0.1, 1, 0.1, 99, 1);
		add(rate);
		X += dx;
		
		plusMinus = new FlxUIButton(X, Std.int((H-ww)/2), "X", onPlusMinus);
		plusMinus.resize(ww, ww);
		plusMinus.label.font = "assets/fonts/verdanab.ttf";
		plusMinus.label.color = FlxColor.BLACK;
		plusMinus.label.size = 24;
		plusMinus.label.bold = true;
		plusMinus.autoCenterLabel();
		add(plusMinus);
	}
	
	override function set_visible(Value:Bool):Bool 
	{
		var vis = super.set_visible(Value);
		set_empty(empty);
		return vis;
	}
	
	private function set_empty(b:Bool){
		empty = b;
		if (empty){
			box.visible = false;
			type.visible = false;
			count.visible = false;
			wait.visible = false;
			level.visible = false;
			rate.visible = false;
			plusMinus.label.text = "+";
			sigils.visible = false;
		}
		else{
			box.visible = true;
			type.visible = true;
			count.visible = true;
			wait.visible = true;
			level.visible = true;
			rate.visible = true;
			plusMinus.label.text = "X";
			sigils.visible = true;
		}
		
		if (!empty && ID == 0){
			plusMinus.visible = plusMinus.active = false;
		}
		
		return empty;
	}
	
	private function onType(){
		trace("on type");
		FlxUI.event("select_type", this, null);
	}
	
	private function onPlusMinus(){
		if(empty){
			FlxUI.event("add_wave", this, ID);
		}else{
			FlxUI.event("delete_wave", this, ID);
		}
	}
	
	private function makeBox(W:Int, H:Int):FlxUIGroup{
		var top    = new FlxUILine(0, 0,     LineAxis.HORIZONTAL, W, 2, FlxColor.BLACK);
		var left   = new FlxUILine(0, 0,     LineAxis.VERTICAL  , H, 2, FlxColor.BLACK);
		var bottom = new FlxUILine(0, H - 2, LineAxis.HORIZONTAL, W, 2, FlxColor.BLACK);
		var right  = new FlxUILine(W - 2, 0, LineAxis.VERTICAL  , H, 2, FlxColor.BLACK);
		var g = new FlxUIGroup();
		g.add(top);
		g.add(left);
		g.add(right);
		g.add(bottom);
		return g;
	}
}

typedef WaveInfo = 
{
	var type:String;
	var count:Int;
	var wait:Float;
	var level:Int;
	var rate:Float;
	var starts:Array<Bool>;
	var ends:Array<Bool>;
}