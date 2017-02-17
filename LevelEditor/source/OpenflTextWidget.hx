package;
import flash.text.TextFormat;
import flixel.FlxG;
import flixel.addons.ui.FlxUIButton;
import flixel.addons.ui.FlxUIGroup;
import flixel.addons.ui.FlxUIInputText;
import flixel.addons.ui.FlxUINumericStepper;
import flixel.addons.ui.FlxUIText;
import flixel.addons.ui.interfaces.IFlxUIButton;
import flixel.util.FlxColor;
import flixel.text.FlxText.FlxTextAlign;
import flixel.text.FlxText.FlxTextBorderStyle;
import openfl.text.TextField;
import openfl.text.TextFieldType;
import openfl.text.TextFormatAlign;

/**
 * ...
 * @author 
 */
class OpenflTextWidget extends FlxUIGroup
{
	public var input:TextField;
	public var label:FlxUIText;
	
	public function new(X:Float = 0, Y:Float = 0, W:Int, Label:String, DefaultValue:String="", H:Float=0, font:String="verdana.ttf", Multiline:Bool=true, WordWrap:Bool=true, Align:TextFormatAlign=TextFormatAlign.LEFT, Size:Int=12, AlphaNumeric:Bool=false, LowerCase:Bool=false)
	{
		super(X, Y);
		
		input = new TextField();
		input.setTextFormat(new TextFormat("assets/fonts/" + font, Size, FlxColor.BLACK, null, null, null, null, null, Align));
		input.type = TextFieldType.INPUT;
		input.background = true;
		input.border = true;
		input.wordWrap = WordWrap;
		input.multiline = Multiline;
		input.width = Std.int(W*0.9);
		input.height = H;
		input.text = DefaultValue;
		if (AlphaNumeric){
			if(LowerCase){
				input.restrict = "abcdefghijklmnopqrstuvwxyz1234567890";
			}else{
				input.restrict = "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ1234567890";
			}
		}
		
		FlxG.stage.addChild(input);
		
		label = new FlxUIText(0, 0, input.width, Label, 12);
		label.font = "assets/fonts/verdana.ttf";
		label.color = FlxColor.BLACK;
		label.alignment = FlxTextAlign.CENTER;
		add(label);
	}
	
	override function set_x(Value:Float):Float 
	{
		var val = super.set_x(Value);
		if(input != null){
			input.x = label.x;
		}
		return val;
	}
	
	override function set_y(Value:Float):Float 
	{
		var val = super.set_y(Value);
		if (input != null){
			label.y = y;
			input.y = label.y + label.height + 2;
		}
		return val;
	}
	
	override public function destroy():Void 
	{
		FlxG.stage.removeChild(input);
		input = null;
		super.destroy();
	}
}