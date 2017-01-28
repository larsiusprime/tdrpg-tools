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
class NumberWidget extends FlxUIGroup
{
	public var stepper:FlxUINumericStepper;
	public var label:FlxUIText;
	
	public function new(X:Float = 0, Y:Float = 0, W:Int, Label:String, StepSize:Float=1, DefaultValue:Float=0, Min:Float=-999, Max:Float=999, Decimals:Int=0)
	{
		super(X, Y);
		
		var field = new FlxUIInputText(0, 0, Std.int(W*0.75), "", 12);
		field.font = "assets/fonts/verdana.ttf";
		field.color = FlxColor.BLACK;
		//field.alignment = FlxTextAlign.RIGHT;
		
		stepper = new FlxUINumericStepper(0, 0, StepSize, DefaultValue, Min, Max, Decimals, FlxUINumericStepper.STACK_HORIZONTAL, field, null, null, false);
		add(stepper);
		label = new FlxUIText(0, 0, stepper.width, Label, 12);
		label.font = "assets/fonts/verdana.ttf";
		label.color = FlxColor.BLACK;
		label.alignment = FlxTextAlign.CENTER;
		label.y = stepper.y;
		add(label);
	}
}