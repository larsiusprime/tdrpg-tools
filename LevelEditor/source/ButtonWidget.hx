package;
import flixel.addons.ui.FlxUIButton;
import flixel.addons.ui.FlxUIGroup;
import flixel.addons.ui.FlxUIText;
import flixel.text.FlxText.FlxTextAlign;
import flixel.util.FlxColor;

/**
 * ...
 * @author 
 */
class ButtonWidget extends FlxUIGroup
{
	public var button:FlxUIButton;
	public var label:FlxUIText;
	public var callback:Void->Void;
	
	override public function destroy():Void 
	{
		super.destroy();
		button = null;
		label = null;
		callback = null;
	}
	
	public function new(X:Float, Y:Float, W:Float, H:Float, textLabel:String, buttonLabel:String, Callback:Void->Void) 
	{
		super(X, Y);
		
		callback = Callback;
		
		button = new FlxUIButton(0, 0, buttonLabel, onClick);
		button.resize(W, H/2);
		button.label.font = "assets/fonts/verdana.ttf";
		button.label.size = 12;
		button.label.color = FlxColor.BLACK;
		button.autoCenterLabel();
		
		add(button);
		
		label = new FlxUIText(0, 0, W, textLabel);
		label.font = "assets/fonts/verdana.ttf";
		label.size = 12;
		label.alignment = FlxTextAlign.CENTER;
		label.color = FlxColor.BLACK;
		add(label);
		
		label.y = button.y + button.height;
	}
	
	public function onClick(){
		if (callback != null){
			callback();
		}
	}
}