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
import lime.system.Clipboard;
import org.zamedev.lib.Utf8Ext;
import unifill.Unifill;

/**
 * ...
 * @author 
 */
class BigTextPopup extends FlxUISubState
{

	private var existing:String;
	private var callback:String->Void;
	private var input:OpenflTextWidget;
	private var back:FlxUIGroup;
	
	public function new(Value:String, Label:String, Callback:String->Void, locale:String="en-us") 
	{
		super(0xB0000000);
		
		locale = locale.toLowerCase();
		var font = switch(locale){
			case "ja-jp": "mplus2c.ttf";
			case "zh-hans": "notostanscjksc.otf";
			case "zh-hant": "notostanscjktc.otf";
			case "ko-kr": "nanumgothic.ttf";
			default: "notosans.ttf";
		}
		
		callback = Callback;
		
		back = Util.makeBox(500, 250, FlxColor.WHITE);
		
		back.x = Std.int((FlxG.width - back.width) / 2);
		back.y = Std.int((FlxG.height - back.height) / 2);
		add(back);
		
		input = new OpenflTextWidget(0, 5, 500, Label, Value, 100, font);
		add(input);
		
		input.x = Std.int((FlxG.width - input.width) / 2);
		
		input.y = back.y + 20;
		
		var button = Util.makeBtn(Std.int(input.x), Std.int(input.y + input.height + 5), "Accept", function(){
			onClick(input.input.text);
		});
		button.x = Std.int((FlxG.width - button.width) / 2);
		button.y = back.y + back.height - (button.height + 5);
		add(button);
		
		var clipboard  = Util.makeBtn(0, 0, "Paste from clipboard", onClipboard, 100, 50);
		clipboard.x = button.x;
		clipboard.y = button.y - clipboard.height - 5;
		add(clipboard);
	}
	
	private function onClipboard(){
		if(Clipboard.text != null && Clipboard.text != ""){
			input.input.text = Clipboard.text;
		}
	}
	
	private function onClick(str:String){
		callback(str);
		callback = null;
		close();
	}
}