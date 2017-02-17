package;
import flixel.FlxG;
import flixel.FlxSprite;
import flixel.addons.ui.FlxUI;
import flixel.addons.ui.FlxUI9SliceSprite;
import flixel.addons.ui.FlxUIButton;
import flixel.addons.ui.FlxUIGroup;
import flixel.addons.ui.FlxUIList;
import flixel.addons.ui.FlxUIRadioGroup;
import flixel.addons.ui.FlxUISprite;
import flixel.addons.ui.FlxUISubState;
import flixel.addons.ui.interfaces.IFlxUIWidget;
import flixel.util.FlxColor;
import flixel.text.FlxText.FlxTextBorderStyle;
import org.zamedev.lib.Utf8Ext;
import unifill.Unifill;

/**
 * ...
 * @author 
 */
class BonusSettingsPopup extends FlxUISubState
{

	private var callback:Float->String->Float->String->Void;
	
	private var stars:NumberWidget;
	private var starsColor:FlxUIRadioGroup;
	private var starsPlus:NumberWidget;
	private var starsPlusColor:FlxUIRadioGroup;
	
	public function new(Stars:Int, StarsColor:String, StarsPlus:Int, StarsPlusColor:String, Callback:Float->String->Float->String->Void) 
	{
		super(0xB0000000);
		
		callback = Callback;
		
		var back = Util.makeBox(500, 250, FlxColor.WHITE);
		
		back.x = Std.int((FlxG.width - back.width) / 2);
		back.y = Std.int((FlxG.height - back.height) / 2);
		add(back);
		
		var S:Int = Std.int((back.width * 0.1) /6);
		var W:Int = Std.int((back.width-(S*6))/4);
		
		var X:Int = Std.int(back.x + S + W/2);
		
		stars = new NumberWidget(X, 0, W-S, "Stars", 1, Stars, 0, 999, 0);
		add(stars);
		
		X += W + S;
		
		starsColor = Util.makeRadios(X+S, 0, ["blue", "gold"], ["blue", "gold"], null);
		starsColor.selectedId = StarsColor;
		add(starsColor);
		
		X += W + S;
		
		starsPlus = new NumberWidget(X, 0, W-S, "NG+ Stars", 1, StarsPlus, 0, 999, 0);
		add(starsPlus);
		
		X += W + S;
		
		starsPlusColor = Util.makeRadios(X+S, 0, ["blue", "gold"], ["blue", "gold"], null);
		starsPlusColor.selectedId = StarsPlusColor;
		add(starsPlusColor);
		
		Util.center(back, stars, false, true);
		Util.center(back, starsColor, false, true);
		Util.center(back, starsPlus, false, true);
		Util.center(back, starsPlusColor, false, true);
		
		var button = Util.makeBtn(0, 0, "Accept", function(){
			onClick(
				stars.stepper.value, starsColor.selectedId, starsPlus.stepper.value, starsPlusColor.selectedId
			);
		});
		button.x = Std.int((FlxG.width - button.width) / 2);
		button.y = back.y + back.height - (button.height + 5);
		add(button);
		
		var cancel = Util.makeBtn(Std.int(button.x), Std.int(button.y), "Cancel", function(){
			callback = null;
			close();
		});
		add(cancel);
		
		button.x -= button.width;
		cancel.x += cancel.width;
	}
	
	private function onClick(s:Float,sc:String,sp:Float,spc:String){
		callback(s,sc,sp,spc);
		callback = null;
		close();
	}
}