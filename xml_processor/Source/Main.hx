package;


import flash.display.Bitmap;
import flash.display.BitmapData;
import flash.display.Sprite;
import flixel.addons.ui.U;
import haxe.xml.Fast;
import openfl.Assets;
#if sys
	import sys.io.File;
	import sys.FileSystem;
#end

/**
 * This is a cheap project that processes xml data from the original Defender's Quest to reformat it for Defender's Quest (haxe version)
 */


class Main extends Sprite {
	
	
	public function new () {
		
		super ();
		
		var data_effects = U.xml("data_effects", "xml", true, "assets/");
		
		var effects_gfx = ModFix.data_effects_gfx(data_effects);
		write(effects_gfx, "graphics.xml", "effects");
		
		var effects = ModFix.data_effects_effects(data_effects);
		write(effects, "effects.xml", "effects");
	}
	
	public function write(data:String, filename:String, dir:String=""):Void
	{
		#if sys
			if (dir != "")
			{
				dir += "/";
			}
			if (dir != "" && FileSystem.exists(dir) == false)
			{
				FileSystem.createDirectory(dir);
			}
			var fo = File.write(dir+filename);
			fo.writeString(data);
			fo.close();
		#end
	}
}