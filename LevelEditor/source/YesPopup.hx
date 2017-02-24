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
import flixel.text.FlxText;
import flixel.text.FlxText.FlxTextAlign;
import flixel.util.FlxColor;
import flixel.text.FlxText.FlxTextBorderStyle;
import org.zamedev.lib.Utf8Ext;
import unifill.Unifill;

/**
 * ...
 * @author 
 */
class YesPopup extends FlxUISubState
{

	private var callback:Void->Void;
	
	public function new(Title:String, Message:String, ?Callback:Void->Void) 
	{
		super(0xB0000000);
		
		callback = Callback;
		
		var back = Util.makeBox(500, 250, FlxColor.WHITE);
		
		back.x = Std.int((FlxG.width - back.width) / 2);
		back.y = Std.int((FlxG.height - back.height) / 2);
		add(back);
		
		var title = Util.makeTxt(0, 0, back.width, Title);
		title.alignment = FlxTextAlign.CENTER;
		var message = Util.makeTxt(0, 0, Std.int(back.width * 0.9), Message);
		message.alignment = FlxTextAlign.CENTER;
		
		title.x = back.x;
		title.y = Std.int(back.y + 5);
		
		message.x = back.x + Std.int((back.width - message.width) / 2);
		message.y = back.y + Std.int((back.height-message.height) / 2);
		
		add(title);
		add(message);
		
		var yes = Util.makeBtn(0, 0, "Okay", function(){
			onClick();
		});
		yes.x = Std.int((FlxG.width - yes.width) / 2);
		yes.y = back.y + back.height - (yes.height + 5);
		
		add(yes);
	}
	
	private function onClick(){
		if(callback != null){
			callback();
		}
		callback = null;
		close();
	}
}