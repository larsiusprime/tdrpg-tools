package;
import flixel.addons.ui.FlxUIGroup;
import flixel.addons.ui.FlxUILine;
import flixel.addons.ui.FlxUISprite;
import flixel.util.FlxColor;

/**
 * ...
 * @author 
 */
class WaveWidget extends FlxUIGroup
{
	public static inline var W:Int = 660;
	public static inline var H:Int = 72;
	
	public var sigils:SigilWidget;
	public var count:NumberWidget;
	public var wait:NumberWidget;
	public var level:NumberWidget;
	public var rate:NumberWidget;
	public var type:ButtonWidget;
	
	public function new(X:Float=0,Y:Float=0) 
	{
		super(X, Y);
		init();
	}
	
	public function sync(info:WaveInfo){
		sigils.sync(info);
	}
	
	private function init()
	{
		var chrome = new FlxUISprite();
		chrome.makeGraphic(1, 1, FlxColor.WHITE);
		chrome.scale.set(W, H);
		chrome.updateHitbox();
		add(chrome);
		makeBox(W, H);
		
		sigils = new SigilWidget(4,Std.int(H/4),H/2);
		add(sigils);
		
		var X = 4 + sigils.width + 8;
		var Y = 20;
		var ww = Std.int(H*0.8);
		var dx = ww + 38;
		
		type = new ButtonWidget(X, Y-8, H * 2, H, "type", "normal");
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
	}
	
	private function makeBox(W:Int, H:Int):Void{
		var top    = new FlxUILine(0, 0,     LineAxis.HORIZONTAL, W, 2, FlxColor.BLACK);
		var left   = new FlxUILine(0, 0,     LineAxis.VERTICAL  , H, 2, FlxColor.BLACK);
		var bottom = new FlxUILine(0, H - 2, LineAxis.HORIZONTAL, W, 2, FlxColor.BLACK);
		var right  = new FlxUILine(W - 2, 0, LineAxis.VERTICAL  , H, 2, FlxColor.BLACK);
		add(top);
		add(left);
		add(right);
		add(bottom);
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