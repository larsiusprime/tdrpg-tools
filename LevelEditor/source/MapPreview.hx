package;
#if tdrpg_haxe
import com.leveluplabs.tdrpg.BattleFieldPreview;
#end
import flash.display.BitmapData;
import flixel.FlxG;
import flixel.FlxSprite;
import flixel.addons.ui.FlxUISprite;
import flixel.addons.ui.FlxUIText;
import flixel.group.FlxGroup;
import flixel.text.FlxText;
import flixel.util.FlxColor;
import haxe.xml.Fast;

#if !tdrpg_haxe

typedef BattleFieldPreviewParams = {
	var X:Int; 
	var Y:Int;
	var name:String;
	var diff:String; 
	var tileHeight:Int;
	var widthInSquares:Int;
	var heightInSquares:Int;
	var tilesetStyle:String;
	var tilesPerSquare:Int;
	var png:BitmapData;
	var xml:Fast;
	var levelEdit:Bool;
	var doodads:Bool;
}

#end

/**
 * ...
 * @author 
 */
class MapPreview extends FlxGroup
{
	#if tdrpg_haxe
	private var preview:BattleFieldPreview;
	#end
	private var errorTxt:FlxUIText;
	
	private var params:BattleFieldPreviewParams;
	
	public function new(Params:BattleFieldPreviewParams):Void
	{
		super();
		params = Params;
		makeFakePreview(params);
	}
	
	public function updatePreview(b:Bool, png:BitmapData=null, xml:Fast=null, diff:String="easy"){
		#if tdrpg_haxe
		
		if (!b){
			if (preview != null){
				preview.visible = false;
			}
			errorTxt.text = "Can't show preview without path to game and/or mod data";
			return;
		}else{
			errorTxt.text = "";
		}
		
		if (png == null || xml == null){
			return;
		}
		
		if(preview != null){
			preview.destroy();
			remove(preview, true);
		}
		if (params.png != null){
			params.png.dispose();
			params.png = null;
			params.xml = null;
		}
		
		params.png = png;
		params.xml = xml;
		params.diff = diff;
		preview = new BattleFieldPreview(params);
		add(preview);
		#end
	}
	
	private function makeFakePreview(params:BattleFieldPreviewParams)
	{
		var X = params.X;
		var Y = params.Y;
		var name = params.name;
		var diff = params.diff;
		var tileHeight = params.tileHeight;
		var widthInSquares = params.widthInSquares;
		var heightInSquares = params.heightInSquares;
		var tilesetStyle = params.tilesetStyle;
		var tilesPerSquare = params.tilesPerSquare;
		var wit = widthInSquares * tilesPerSquare;
		var hit = heightInSquares * tilesPerSquare;
		
		var back = new FlxSprite(X, Y).makeGraphic(Std.int(wit * tileHeight), Std.int(hit * tileHeight), FlxColor.BLACK);
		back.scrollFactor.set(0, 0);
		add(back);
		
		errorTxt = Util.makeTxt(X, Y, back.width, "...");
		errorTxt.y = (Y + Std.int((back.height - errorTxt.height) / 2));
		errorTxt.alignment = FlxTextAlign.CENTER;
		errorTxt.color = FlxColor.WHITE;
		errorTxt.font = "assets/fonts/verdanab.ttf";
		add(errorTxt);
		
		#if !tdrpg_haxe
		errorTxt.text = "Preview requires the 'tdrpg-haxe' library";
		#end
	}
}