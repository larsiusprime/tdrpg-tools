package;
import flixel.FlxG;
import flixel.FlxSprite;
import flixel.addons.ui.FlxUI;
import flixel.addons.ui.FlxUIButton;
import flixel.addons.ui.FlxUIGroup;
import flixel.addons.ui.FlxUIList;
import flixel.addons.ui.FlxUISprite;
import flixel.addons.ui.FlxUISubState;
import flixel.addons.ui.interfaces.IFlxUIWidget;
import flixel.util.FlxColor;
import flixel.text.FlxText.FlxTextBorderStyle;
import org.zamedev.lib.Utf8Ext;
import unifill.Unifill;

/**
 * ...
 * @author 
 */
class TypePopup extends FlxUISubState
{

	private var existing:String;
	private var callback:String->String->Void;
	
	public function new(array:Array<String>, Existing:String, Callback:String->String->Void) 
	{
		super(0xB0000000);
		
		existing = Existing;
		callback = Callback;
		
		var buttonWidth = 250;
		var buttonHeight = 32;
		
		var offY = 0;
		var totalHeight = (buttonHeight + 5) * array.length;
		if (totalHeight > FlxG.height){
			offY = 20;
		}
		else{
			offY = Std.int((FlxG.height - totalHeight) / 2);
		}
		
		var buttons:Array<IFlxUIWidget> = [];
		var group:FlxUIGroup = new FlxUIGroup();
		var i = 0;
		
		var category = "";
		for (str in array){
			if (str.indexOf(":") != -1){
				if (i > 0)
				{
					buttons.push(group);
					group = new FlxUIGroup();
				}
				var txt = Util.makeTxt(0, 0, buttonWidth, str);
				var g = new FlxUIGroup();
				txt.x = 0 + Std.int(((FlxG.width / 4) - txt.width) / 2);
				txt.color = FlxColor.WHITE;
				txt.font = "assets/fonts/verdanab.ttf";
				g.add(txt);
				buttons.push(g);
				category = Unifill.uSubstr(str,0,Unifill.uLength(str)-1);
				i = 0;
			}
			else{
				var btn = Util.makeBtn(0, 0, str, onClick.bind(str, category), buttonWidth, buttonHeight);
				group.add(btn);
				btn.x = 0 + Std.int(((FlxG.width / 4) - btn.width) / 2);
				if (str == existing){
					btn.label.color = FlxColor.WHITE;
					btn.setLabelFormat("assets/fonts/verdanab.ttf", btn.label.size, FlxColor.WHITE, null, FlxTextBorderStyle.OUTLINE, FlxColor.BLACK);
					btn.label.text = Utf8Ext.toUpperCase(btn.label.text);
				}
				switch(i){
					case 1:
						btn.x += (Std.int(FlxG.width * 1 / 4));
					case 2:
						btn.x += (Std.int(FlxG.width * 2 / 4));
					case 3:
						btn.x += (Std.int(FlxG.width * 3 / 4));
					default:
						//nothing
				}
				i++;
				if (i >= 4){
					buttons.push(group);
					group = new FlxUIGroup();
					i = 0;
				}else if (str == array[array.length - 1]){
					buttons.push(group);
					i = 0;
				}
			}
		}
		
		var list = new FlxUIList(0, offY, buttons, FlxG.width, (FlxG.height - (offY * 2)), "<X> more...", FlxUIList.STACK_VERTICAL, 5);
		add(list);
	}
	
	private function alpha(a:String, b:String):Int{
		if (a < b) return -1;
		if (a > b) return  1;
		return 0;
	}
	
	private function onClick(str:String,category:String){
		
		callback(str,category);
		callback = null;
		close();
	}
}