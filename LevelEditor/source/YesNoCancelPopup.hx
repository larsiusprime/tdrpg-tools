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
class YesNoCancelPopup extends FlxUISubState
{

	private var callback:String->Void;
	
	public function new(Title:String, Message:String, Callback:String->Void) 
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
		
		message.x = Std.int((FlxG.width - back.width) / 2);
		message.y = back.y + Std.int((back.height-message.height) / 2);
		
		add(title);
		add(message);
		
		var yes = Util.makeBtn(0, 0, "Yes", function(){
			onClick("yes");
		});
		yes.x = Std.int((FlxG.width - yes.width) / 2);
		yes.y = back.y + back.height - (yes.height + 5);
		
		var no = Util.makeBtn(0, 0, "No", function(){
			onClick("no");
		});
		no.x = Std.int((FlxG.width - no.width) / 2);
		no.y = back.y + back.height - (no.height + 5);
		
		var cancel = Util.makeBtn(0, 0, "Cancel", function(){
			onClick("cancel");
		});
		cancel.x = Std.int((FlxG.width - cancel.width) / 2);
		cancel.y = back.y + back.height - (cancel.height + 5);
		
		
		yes.x -= (yes.width + 10);
		cancel.x += (cancel.width+10);
		
		add(yes);
		add(no);
		add(cancel);
	}
	
	private function onClick(str:String){
		callback(str);
		callback = null;
		close();
	}
}