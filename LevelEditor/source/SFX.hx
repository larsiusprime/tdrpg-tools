package;
import flixel.FlxG;
import flixel.system.FlxSound;
import openfl.Assets;

/**
 * ...
 * @author 
 */
class SFX
{

	public function new() 
	{
		
	}

	private static var sound:FlxSound;
	
	public static function play(str:String)
	{
		if (sound == null) sound = new FlxSound();
		if (sound.playing) return;
		
		var soundid = "assets/sounds/" + str + ".ogg";
		if (Assets.exists(soundid, AssetType.SOUND)){
			sound.loadEmbedded(soundid);
			sound.play(true);
		}
	}
}