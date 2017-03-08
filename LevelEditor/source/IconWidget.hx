package;
import flash.display.BitmapData;
import flash.geom.Matrix;
import flash.geom.Point;
import flixel.FlxG;
import flixel.addons.ui.FlxUI;
import flixel.addons.ui.FlxUIButton;
import flixel.addons.ui.FlxUIGroup;
import flixel.addons.ui.FlxUISprite;
import flixel.addons.ui.FlxUIText;
import flixel.addons.ui.U;
import flixel.text.FlxText.FlxTextAlign;
import flixel.util.FlxColor;
import lime.ui.FileDialogType;
import openfl.geom.Rectangle;
import sys.FileSystem;

/**
 * ...
 * @author 
 */
class IconWidget extends FlxUIGroup
{
	public var value(default, set):BitmapData;
	
	public var back:FlxUISprite;
	public var icon:FlxUISprite;
	public var button:FlxUIButton;
	
	private var theHeight:Int = 0;
	private var theWidth:Int = 0;
	
	private var callback:Void->Void;
	
	public function new(X:Float, Y:Float, W:Float, H:Float, buttonLabel:String, image:BitmapData, Callback:Void->Void) 
	{
		super(X, Y);
		
		callback = Callback;
		
		H = Std.int(H);
		
		theHeight = Std.int(H);
		theWidth = Std.int(W);
		
		back = new FlxUISprite();
		back.makeGraphic(theWidth+4, theHeight+4, FlxColor.BLACK, false, "bahbahblacksheep");
		
		add(back);
		
		image = prepImage(image);
		
		icon = new FlxUISprite(2,2);
		add(icon);
		
		value = image;
		
		button = new FlxUIButton(2, H+6, buttonLabel, onClick);
		button.resize(W, Std.int(H/4));
		button.label.font = "assets/fonts/verdana.ttf";
		button.label.size = 12;
		button.label.color = FlxColor.BLACK;
		button.autoCenterLabel();
		
		add(button);
	}
	
	public function onClick()
	{
		var state = Util.openPopup(new PopupPleaseWait("please wait..."));
		
		Util.promptPath(function(str:String):Void{
			
			if (str != null && FileSystem.exists(str) && str.indexOf(".png") != -1){
				var png = BitmapData.fromFile(str);
				
				if (png != null)
				{
					value = png;
					if (callback != null)
					{
						callback();
					}
				}
			}
			
			Util.closePopup(state);
			
		}, FileDialogType.OPEN);
	}
	
	override public function destroy():Void 
	{
		super.destroy();
		back = null;
		button = null;
		icon = null;
		callback = null;
	}
	
	private function set_value(bmp:BitmapData):BitmapData
	{
		bmp = prepImage(bmp);
		
		var scaled = new BitmapData(theWidth, theHeight);
		var matrix = new Matrix();
		var scaleH:Float = theHeight / bmp.height;
		matrix.scale(scaleH, scaleH);
		scaled.draw(bmp, matrix, null, null, null, true);
		value = bmp;
		icon.loadGraphic(scaled);
		
		return value;
	}
	
	private function prepImage(image:BitmapData):BitmapData
	{
		if (image.width != image.height)
		{
			var cropX:Int = 0;
			var offX:Int = 0;
			
			if (image.height > image.width)
			{
				offX = Std.int((image.height - image.width)/2);
			}
			else
			{
				cropX = Std.int((image.width - image.height)/2);
			}
			
			var crop = new BitmapData(image.height, image.height, true, FlxColor.BLACK);
			var sourceRect = new Rectangle(cropX, 0, image.height, image.height);
			var destPoint = new Point(offX, 0);
			crop.copyPixels(image, sourceRect, destPoint);
			image = crop;
		}
		return image;
	}
	
	
}