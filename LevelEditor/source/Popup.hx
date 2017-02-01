package;
import flixel.FlxG;
import flixel.addons.ui.FlxUI9SliceSprite;
import flixel.addons.ui.FlxUIButton;
import flixel.addons.ui.FlxUIPopup;
import flixel.addons.ui.FlxUIText;
import flixel.addons.ui.U;
import flixel.text.FlxText.FlxTextAlign;
import flixel.text.FlxText.FlxTextBorderStyle;
import flixel.util.FlxColor;

/**
 * ...
 * @author 
 */
class Popup extends FlxUIPopup
{

	private var title:String;
	private var message:String;
	private var closeParam:String = "";
	
	public function new(Title:String,Message:String,CloseParam:String="") 
	{
		super(0xB0000000);
		title = Title;
		message = Message;
		quickSetup(title, message, ["OK"]);
	}
	
	override public function create():Void 
	{
		super.create();
		
		var text_title:FlxUIText = cast _ui.getAsset("title");
		text_title.setFormat("assets/fonts/verdanab.ttf", 14 , FlxColor.WHITE, FlxTextAlign.CENTER, FlxTextBorderStyle.OUTLINE, FlxColor.BLACK);
		
		var text_body:FlxUIText = cast _ui.getAsset("body");
		text_body.setFormat("assets/fonts/verdanab.ttf", 12, FlxColor.BLACK, FlxTextAlign.LEFT);// , FlxTextBorderStyle.OUTLINE, FlxColor.BLACK);
		
		var back:FlxUI9SliceSprite = cast _ui.getAsset("back");
		back.resize(Std.int(FlxG.width * 0.5), Std.int(FlxG.height * 0.35));
		
		back.x = Std.int((FlxG.width - back.width) / 2);
		back.y = Std.int((FlxG.height - back.height) / 2);
		
		text_title.y = back.y + 2;
		text_body.y = text_title.y + text_title.height + 10;
		
		text_title.x = back.x;
		text_body.x = back.x+10;
		text_title.width = text_title.textField.width = back.width;
		text_body.width = text_body.textField.width = back.width - 20;
		
		text_title.text = "";
		text_body.text = "";
		
		text_title.text = title;
		text_body.text = message;
		
		var btn:FlxUIButton = cast _ui.getAsset("btn0");
		btn.params = ["affirm"];
		
		if (closeParam != null && closeParam != ""){
			btn.params.push(closeParam);
		}
		
		btn.y = Std.int(back.y + back.height - btn.height - 5);
	}
	
}