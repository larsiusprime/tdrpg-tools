package;

import com.leveluplabs.tdrpg.UU;
import flash.display.BitmapData;
import flixel.FlxG;
import flixel.addons.util.PNGEncoder;
import sys.FileSystem;
import sys.io.File;

/**
 * ...
 * @author 
 */

class ModUtil
{

	public static function exportMod(name:String, title:String, modPath:String, dqString:String="", dqVersion:String="", overwrite:Bool):Bool
	{
		var settingsPath = UU.fixDoubleSlash(modPath + UU.getSlash() + "settings.xml");
		
		if (FileSystem.exists(modPath) == false)
		{
			FileSystem.createDirectory(modPath);
		}
		
		if (!overwrite)
		{
			if (FileSystem.exists(settingsPath))
			{
				return false;
			}
		}
		
		//write out settings.xml
		File.saveContent(settingsPath, UU.getDefaultModSettings(name, title, dqString, dqVersion));
		
		//write out icon.png
		var iconPath = UU.fixDoubleSlash(modPath + UU.getSlash() + "icon.png");
		var icon = new BitmapData(512, 512, false, FlxG.random.color());
		var byteArray = PNGEncoder.encode(icon);
		File.saveBytes(iconPath, byteArray);
		
		return true;
	}
}