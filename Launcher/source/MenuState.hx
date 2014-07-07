package;

import flixel.addons.ui.FlxUIButton;
import flixel.addons.ui.FlxUIState;
import flixel.addons.ui.FlxUIText;
import flixel.addons.ui.FlxUITypedButton;
import flixel.FlxG;
import flixel.FlxSprite;
import flixel.FlxState;
import flixel.text.FlxText;
import flixel.ui.FlxButton;
import flixel.util.FlxSpriteUtil;
import openfl.Lib;

/**
 * A FlxState which can be used for the game's menu.
 */
class MenuState extends FlxUIState
{
	/**
	 * Function that is called up when to state is created to set it up. 
	 */
	override public function create():Void
	{
		_xml_id = "ui/state_menu";
		super.create();
		
		FlxG.mouse.useSystemCursor = true;
		
		var simple_desc:FlxUIText = cast _ui.getAsset("simple_desc");
		while (simple_desc.text.indexOf("$N") != -1) {
			simple_desc.text = StringTools.replace(simple_desc.text, "$N", "\n");
		}
		
		var fancy_desc:FlxUIText = cast _ui.getAsset("fancy_desc");
		while (fancy_desc.text.indexOf("$N") != -1) {
			fancy_desc.text = StringTools.replace(fancy_desc.text, "$N", "\n");
		}
	}
	
	override public function getEvent(id:String, sender:Dynamic, data:Dynamic, ?params:Array<Dynamic>):Void
	{
		switch(id) {
			case FlxUITypedButton.CLICK_EVENT:
				var str:String = cast params[0];
				switch(str)
				{
					case "cancel":
						Sys.exit(0);
					case "simple":
						Sys.command("simple.sh");
						Sys.exit(0);
					case "fancy":
						Sys.command("fancy.sh");
						Sys.exit(0);
				}
		}
	}
	
	/**
	 * Function that is called when this state is destroyed - you might want to 
	 * consider setting all objects this state uses to null to help garbage collection.
	 */
	override public function destroy():Void
	{
		super.destroy();
	}

	/**
	 * Function that is called once every frame.
	 */
	override public function update():Void
	{
		super.update();
		if (FlxG.keys.justPressed.ENTER) {
			FlxG.switchState(new MenuState());
		}
	}
}