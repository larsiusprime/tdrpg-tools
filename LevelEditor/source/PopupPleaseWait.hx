package;
import flixel.FlxG;
import flixel.addons.ui.FlxUI9SliceSprite;
import flixel.addons.ui.FlxUIButton;
import flixel.addons.ui.FlxUIPopup;
import flixel.addons.ui.FlxUISubState;
import flixel.addons.ui.FlxUIText;
import flixel.addons.ui.U;
import flixel.text.FlxText.FlxTextAlign;
import flixel.text.FlxText.FlxTextBorderStyle;
import flixel.util.FlxColor;

/**
 * ...
 * @author 
 */
class PopupPleaseWait extends FlxUISubState
{

	private var message:String;
	
	public function new(Message:String) 
	{
		super(0xB0000000);
		message = Message;
	}
	
	override public function create():Void 
	{
		super.create();
		
		var txt = Util.makeTxt(0, 0, FlxG.width, message);
		txt.alignment = flixel.text.FlxTextAlign.CENTER;
		txt.y = Std.int((FlxG.height - txt.height) / 2);
		add(txt);
		
		txt.color = FlxColor.WHITE;
		txt.size = 25;
	}
	
}