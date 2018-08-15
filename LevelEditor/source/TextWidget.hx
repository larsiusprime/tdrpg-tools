package;
import flixel.addons.ui.FlxUIButton;
import flixel.addons.ui.FlxUIGroup;
import flixel.addons.ui.FlxUIInputText;
import flixel.addons.ui.FlxUINumericStepper;
import flixel.addons.ui.FlxUIText;
import flixel.addons.ui.interfaces.IFlxUIButton;
import flixel.util.FlxColor;
import flixel.text.FlxText.FlxTextAlign;
import flixel.text.FlxText.FlxTextBorderStyle;

/**
 * ...
 * @author 
 */
class TextWidget extends FlxUIGroup
{
	public var input:FlxUIInputText;
	public var label:FlxUIText;
	
	public function new(X:Float = 0, Y:Float = 0, W:Int, Label:String, DefaultValue:String="", Height:Float=0)
	{
		super(X, Y);
		
		input = new FlxUIInputText(X, Y, W, DefaultValue);
		input.font = "assets/fonts/verdanab.ttf";
		input.textField.textColor = FlxColor.BLACK;
		input.alignment = FlxTextAlign.CENTER;
		input.size = 16;
		add(input);
		
		label = new FlxUIText(0, 0, input.width, Label, 12);
		label.font = "assets/fonts/verdana.ttf";
		label.color = FlxColor.BLACK;
		label.alignment = FlxTextAlign.CENTER;
		label.y = input.y;
		add(label);
		
		input.hasFocus = true;
	}
}