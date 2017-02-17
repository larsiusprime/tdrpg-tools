package;
import flixel.addons.ui.FlxUIState;
import haxe.ui.HaxeUIApp;
import haxe.ui.Toolkit;
import haxe.ui.components.Button;
import haxe.ui.core.Component;
import haxe.ui.core.Screen;
import haxe.ui.macros.ComponentMacros;

/**
 * ...
 * @author 
 */
class HaxeUIFlixelState extends FlxUIState
{
	public var haxeuiID:String = "";
	private var app:HaxeUIApp;
	
	public function new(HaxeuiID:String) 
	{
		haxeuiID = HaxeuiID;
		super();
	}
	
	override public function create():Void 
	{
		super.create();
		
		 app = new HaxeUIApp();
		 app.ready(function() {
			var main:Component = ComponentMacros.buildComponent("assets/haxeui/"+haxeuiID+".xml");
			
			app.addComponent(main);
			
			var button:Button = main.findComponent("testButton2", null, true);
			button.onClick = function(e) {
				button.text = "Set from code!";
			}
			
			app.start();
		});
	}
	
	override public function destroy():Void 
	{
		super.destroy();
		//Screen.instance.removeComponent
	}
	
	
}