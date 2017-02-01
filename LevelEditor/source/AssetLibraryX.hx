package;

import lime.graphics.Image;
import lime.utils.Bytes;
import openfl.Assets.AssetLibrary;
import openfl.display.BitmapData;
import unifill.Unifill;

#if tdrpg_haxe
import com.leveluplabs.tdrpg.ModAssetLibrary;
#end

/**
 * ...
 * @author 
 */
class AssetLibraryX extends #if tdrpg_haxe ModAssetLibrary #else AssetLibrary #end
{

	public var xGetBytes:String->Bytes;
	public var xExists:String->String->Bool;
	public var xGetImage:String->Image;
	public var xGetPath:String->String;
	
	public function new(Dir:String, Fallback:DefaultAssetLibrary=null, Dirs:Array<String>=null)
	{
		#if tdrpg_haxe
		super(Dir, Fallback, Dirs);
		#else
		super();
		#end
	}
	
	public override function exists (id:String, type:String):Bool {
		
		var s = testStar(id);
		if (s != "") return super.exists(s, type);
		
		if (xExists != null) return xExists(id, type);
		return super.exists(id, type);
		
	}
	
	
	public override function getBytes (id:String):Bytes {
		var s = testStar(id);
		if (s != "") return super.getBytes(s);
		
		if (xGetBytes != null) return xGetBytes(id);
		return super.getBytes(id);
		
	}
	
	
	public override function getImage (id:String):Image{
		var s = testStar(id);
		if (s != "") return super.getImage(s);
		
		if (xGetImage != null) return xGetImage(id);
		return super.getImage(id);
		
	}
	
	
	public override function getPath (id:String):String {
		
		var s = testStar(id);
		if (s != "") return super.getPath(s);
		
		if (xGetPath != null) return xGetPath(id);
		return super.getPath(id);
		
	}
	
	private function testStar(id:String){
		if (Unifill.uIndexOf(id, "*") == 0){
			var str = Unifill.uSubstr(id, 1, Unifill.uLength(id) - 1);
			return str;
		}
		
		if (Unifill.uIndexOf(id, "flixel") == 0){
			return id;
		}
		
		return "";
	}
	
	
}