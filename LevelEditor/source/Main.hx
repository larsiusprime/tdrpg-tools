package;

import crashdumper.CrashDumper;
import crashdumper.SessionData;
import flixel.FlxGame;
import openfl.display.Sprite;

class Main extends Sprite
{
	public function new()
	{
		var crashDumper = new CrashDumper(SessionData.generateID("LevelEditor", ""), "", "", true);
		
		super();
		addChild(new FlxGame(1600, 900, State_Start, 1, 60, 60, true));
	}
}