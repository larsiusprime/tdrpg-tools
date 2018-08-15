package;
import com.leveluplabs.tdrpg.enums.Stat;
import flixel.addons.ui.FlxUI;
import flixel.addons.ui.FlxUIButton;
import flixel.addons.ui.FlxUIGroup;
import flixel.addons.ui.FlxUILine;
import flixel.addons.ui.FlxUIText;
import flixel.addons.ui.FlxUISprite;
import flixel.addons.ui.interfaces.IFlxUIWidget;
import flixel.util.FlxColor;

/**
 * ...
 * @author 
 */
class WaveWidget extends FlxUIGroup
{
	public static inline var W:Int = 800;
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
	
	public var txtPsiGold:FlxUIText;
	
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
		onChange();
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
		info.count = Std.int(count.stepper.value);
		info.wait = wait.stepper.value;
		info.level = Std.int(level.stepper.value);
		info.rate = rate.stepper.value;
		info.type = type.button.label.text;
		info.starts = sigils.starts.copy();
		info.ends = sigils.ends.copy();
		onChange();
	}
	
	public function setType(typeStr:String){
		type.button.label.text = typeStr;
		type.button.centerLabel();
		if (info != null){
			info.type = typeStr;
			onChange();
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
		
		sigils = new SigilWidget(4, Std.int(H / 4), H / 2);
		sigils.endsAsRadio = true;
		sigils.setValues([true, false, false, false, false], [true, false, false, false, false]);
		add(sigils);
		
		var X = Std.int(4 + sigils.width + 8);
		var Y = Std.int(20);
		var ww = Std.int(H*0.8);
		var dx = ww + 38;
		
		type = new ButtonWidget(X, Y - 8, H * 2, H, "type", "normal", onType);
		add(type);
		X += ww*2 + 38;
		
		count = new NumberWidget(X, Y, ww, "count", 1, 0, 0, 99, 0, false, onNumber);
		add(count);
		X += dx;
		
		wait = new NumberWidget(X, Y, ww, "wait", 0.1, 1, 0, 60, 1, false, onNumber);
		add(wait);
		X += dx;
		
		level = new NumberWidget(X, Y, ww, "level", 1, 1, 1, 99, 0, false, onNumber);
		add(level);
		X += dx;
		
		rate = new NumberWidget(X, Y, ww, "rate", 0.05, 1, 0.05, 99, 2, false, onNumber);
		add(rate);
		X += dx;
		
		txtPsiGold = Util.makeTxt(X, Y - 8, Std.int(ww*2), "Psi: XX\nGold: XX\nXP: XX");
		add(txtPsiGold);
		
		X += 100;
		
		plusMinus = new FlxUIButton(X, Std.int((H-ww)/2), "X", onPlusMinus);
		plusMinus.resize(ww, ww);
		plusMinus.label.font = "assets/fonts/verdanab.ttf";
		plusMinus.label.color = FlxColor.BLACK;
		plusMinus.label.size = 24;
		plusMinus.label.bold = true;
		plusMinus.centerLabel();
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
			txtPsiGold.visible = true;
			var totalPsi:Float = cast FlxUI.request("total_psi",null,null);
			var totalGold:Float = cast FlxUI.request("total_gold",null,null);
			var totalExp:Float = cast FlxUI.request("total_xp",null,null);
			txtPsiGold.text = "Psi: " + totalPsi + "\nGold: " + totalGold + "\nExp: " + totalExp;
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
			txtPsiGold.visible = true;
		}
		
		if (!empty && ID == 0){
			plusMinus.visible = plusMinus.active = false;
		}
		
		return empty;
	}
	
	private function onType(){
		FlxUI.event("select_type", this, null);
		onChange();
	}
	
	private function onNumber(w:NumberWidget){
		onChange();
	}
	
	public function updatePsiGold(){
		if (empty)
		{
			var totalPsi:Float = cast FlxUI.request("total_psi",null,null);
			var totalGold:Float = cast FlxUI.request("total_gold",null,null);
			var totalXp:Float = cast FlxUI.request("total_xp",null,null);
			txtPsiGold.text = "Psi: " + totalPsi + "\nGold: " + totalGold+"\nXP: " + totalXp;
		}
		else
		{
			var psi = Util.dataFetcher.getEnemyStat(info.type, Stat.PSI_REWARD, info.level) * info.count;
			var gold = Util.dataFetcher.getEnemyStat(info.type, Stat.GOLD_REWARD, info.level) * info.count;
			var xp = Util.dataFetcher.getEnemyStat(info.type, Stat.XP_REWARD, info.level) * info.count;
			txtPsiGold.text = "Psi:" + psi + "\nGold:" + gold + "\nXP:" + xp;
		}
	}
	
	public function onChange(){
		Sys.println("ON CHANGE");
		updatePsiGold();
		FlxUI.event("wave_change_info",this,null);
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