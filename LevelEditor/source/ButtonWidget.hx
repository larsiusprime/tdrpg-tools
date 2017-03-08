package;
import flixel.addons.ui.FlxUIButton;
import flixel.addons.ui.FlxUIGroup;
import flixel.addons.ui.FlxUIText;
import flixel.text.FlxText.FlxTextAlign;
import flixel.util.FlxColor;
import unifill.Unifill;

/**
 * ...
 * @author 
 */
class ButtonWidget extends FlxUIGroup
{
	public var value(default, set):String;
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
	
	private function set_value(str:String)
	{
		value = str;
		button.label.text = str;
		button.update(0);
		var temp = str;
		var failsafe = 0;
		while ((button.label.textField.textWidth > button.width * 0.9 || button.label.textField.textHeight > button.height * 0.9) && failsafe < 999){
			temp = Unifill.uSubstr(temp, 0, Unifill.uLength(temp) - 1);
			button.label.text = Util.uCat(temp,"...");
			button.update(0);
			failsafe++;
		}
		return value;
	}
	
	public function labelOnTop(){
		label.y = button.y;
		button.y = label.y + label.height;
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