package ;


import com.leveluplabs.tools.animator.FireTongueEx;
import com.leveluplabs.tools.animator.GlobalData;
import com.leveluplabs.tools.animator.State_Animator;
import com.leveluplabs.tools.animator.State_StressTest;
import flash.Lib;
import flixel.FlxG;
import flixel.FlxGame;
import firetongue.FireTongue;
	
class Main extends FlxGame
{	
	public static var tongue:FireTongueEx;
	public static var data:GlobalData;
	
	public function new()
	{
		
		data = new GlobalData();
		
		var stageWidth:Int = Lib.current.stage.stageWidth;
		var stageHeight:Int = Lib.current.stage.stageHeight;
		var ratioX:Float = 1;// stageWidth / Lib.stage.stageWidth;
		var ratioY:Float = 1;// stageHeight / Lib.stage.stageHeight;
		var ratio:Float = Math.min(ratioX, ratioY);
		super(Math.floor(stageWidth / ratio), Math.floor(stageHeight / ratio), State_Animator, ratio, 60, 60);
	}
}
