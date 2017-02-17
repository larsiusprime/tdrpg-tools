package;
import flixel.FlxState;
import flixel.FlxSubState;
import flixel.addons.ui.FlxUI;
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
class MathWidget extends FlxUIGroup
{
	public var operation:FlxUIButton;
	public var stepper:FlxUINumericStepper;
	public var label:FlxUIText;
	
	public function new(X:Float = 0, Y:Float = 0, W:Int, Label:String, StepSize:Float=1, DefaultValue:Float=0, Min:Float=-999, Max:Float=999, Decimals:Int=0, IsPercent:Bool=false, Operator:String="+")
	{
		super(X, Y);
		
		var field = new FlxUIInputText(0, 0, Std.int(W*0.75), "", 12);
		field.font = "assets/fonts/verdana.ttf";
		field.color = FlxColor.BLACK;
		
		var xx = 0;
		var yy = 0;
		
		stepper = new FlxUINumericStepper(0, 20, StepSize, DefaultValue, Min, Max, Decimals, FlxUINumericStepper.STACK_HORIZONTAL, field, null, null, false);
		stepper.isPercent = IsPercent;
		
		operation = Util.makeBtn(0, 0, Operator, onOperation, stepper.width, 20);
		add(operation);
		
		add(stepper);
		label = new FlxUIText(0, 0, stepper.width, Label, 12);
		label.font = "assets/fonts/verdana.ttf";
		label.color = FlxColor.BLACK;
		label.alignment = FlxTextAlign.CENTER;
		label.y = 36;
		add(label);
		
		operation.x = Std.int(label.x + (label.width - operation.width) / 2);
		
		stepper.params = ["wave_widget"];
	}
	
	private function onOperation(){
		
		var popup = new TypePopup(["+", "-", "x"], operation.label.text, function(str:String, category:String){
			
			operation.label.text = str;
			FlxUI.event("change_math_operator", this, operation.label.text);
			
		});
		
		Util.openPopup(popup);
	}
}