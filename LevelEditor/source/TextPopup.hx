package;
import flixel.FlxG;
import flixel.FlxSprite;
import flixel.addons.ui.FlxUI;
import flixel.addons.ui.FlxUI9SliceSprite;
import flixel.addons.ui.FlxUIButton;
import flixel.addons.ui.FlxUIGroup;
import flixel.addons.ui.FlxUIList;
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
class TextPopup extends FlxUISubState
{

	private var existing:String;
	private var callback:String->Void;
	
	public function new(Value:String, Label:String, Callback:String->Void) 
	{
		super(0xB0000000);
		
		callback = Callback;
		
		var back = Util.makeBox(500, 250, FlxColor.WHITE);
		
		back.x = Std.int((FlxG.width - back.width) / 2);
		back.y = Std.int((FlxG.height - back.height) / 2);
		add(back);
		
		var value = new TextWidget(0, 0, 300, Label, Value);
		add(value);
		
		value.x = Std.int((FlxG.width - value.width) / 2);
		value.y = Std.int((FlxG.height - value.height) / 2);
		
		value.label.y += 20;
		
		var button = Util.makeBtn(Std.int(value.x), Std.int(value.y + value.height + 5), "Accept", function(){
			onClick(value.input.text);
		});
		button.x = Std.int((FlxG.width - button.width) / 2);
		button.y = back.y + back.height - (button.height + 5);
		add(button);
	}
	
	private function onClick(str:String){
		callback(str);
		callback = null;
		close();
	}
}