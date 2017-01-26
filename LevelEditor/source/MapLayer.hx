package;
import flash.display.BitmapData;
import flixel.FlxG;
import flixel.FlxSprite;
import flixel.addons.ui.FlxClickArea;
import flixel.group.FlxGroup;
import flixel.group.FlxSpriteGroup;
import flixel.input.mouse.FlxMouseButton;
import flixel.ui.FlxButton;
import flixel.util.FlxColor;

/**
 * ...
 * @author 
 */
class MapLayer
{
	public var width(default,null):Int;
	public var height(default,null):Int;
	
	public var color(default,null):FlxColor;
	
	public var back:FlxSprite;
	public var sprite:FlxSprite;
	public var button:FlxButton;
	public var rightButton:FlxButton;
	
	public var layer:Int;
	public var value:String;
	
	public var x(default, set):Int;
	public var y(default, set):Int;
	
	public var editable:Bool;
	public var hasSigils:Bool = false;
	
	public var sigils:Array<IntPt>;
	
	public static inline var THE_SCALE:Int = 12;
	
	public function new(W:Int,H:Int,Color:FlxColor,Layer:Int,Value:String,Editable:Bool)
	{
		var theScale:Int = THE_SCALE;
		var halfScale:Int = Std.int(theScale/2);
		
		width = W;
		height = H;
		color = Color;
		layer = Layer;
		value = Value;
		editable = Editable;
		
		sigils = [];
		sigilGroup = new FlxSpriteGroup();
		
		back = new FlxSprite();
		if (FlxG.bitmap.checkCache("backgrid") == false){
			var bmp = makeBackGraphic(W,H);
			FlxG.bitmap.add(bmp, true, "backgrid");
		}
		back.loadGraphic("backgrid");
		back.scale.set(halfScale, halfScale);
		back.updateHitbox();
		
		var bitmap = new BitmapData(W, H, true, FlxColor.TRANSPARENT);
		sprite = new FlxSprite();
		FlxG.bitmap.add(bitmap, true, "layer_" + layer);
		sprite.loadGraphic("layer_" + layer);
		sprite.scale.set(theScale, theScale);
		sprite.updateHitbox();
		
		button = new FlxButton();
		button.loadGraphic(FlxG.bitmap.create(W, H * 3, FlxColor.TRANSPARENT, true), true, W, H);
		button.scale.set(theScale, theScale);
		button.updateHitbox();
		
		rightButton = new FlxButton();
		rightButton.loadGraphic(FlxG.bitmap.create(W, H * 3, FlxColor.TRANSPARENT, true), true, W, H);
		rightButton.scale.set(theScale, theScale);
		rightButton.updateHitbox();
		rightButton.mouseButtons[0] = FlxMouseButtonID.RIGHT;
		
		border = new FlxSprite();
		border.makeGraphic(Std.int(sprite.width + 2), Std.int(sprite.height + 2), FlxColor.BLACK);
	}
	
	public function addTo(group:FlxGroup){
		group.add(border);
		group.add(back);
		group.add(button);
		group.add(rightButton);
		group.add(sprite);
		group.add(sigilGroup);
	}
	
	public function onPencil():Bool{
		var m = getMouseDXY();
		if (sprite.graphic.bitmap.getPixel32(m.x,m.y) != color){
			sprite.graphic.bitmap.setPixel32(m.x, m.y, color);
			return true;
		}
		return false;
	}
	
	public function onEraser():Bool{
		var m = getMouseDXY();
		if (sprite.graphic.bitmap.getPixel32(m.x, m.y) != FlxColor.TRANSPARENT)
		{
			sprite.graphic.bitmap.setPixel32(m.x, m.y, FlxColor.TRANSPARENT);
			return true;
		}
		return false;
	}
	
	public function onBucket():Bool{
		var m = getMouseDXY();
		sprite.graphic.bitmap.floodFill(m.x, m.y, color);
		return true;
	}
	
	public function onTurpentine():Bool{
		var m = getMouseDXY();
		sprite.graphic.bitmap.floodFill(m.x, m.y, FlxColor.TRANSPARENT);
		return true;
	}
	
	public function onSigilPlace(i:Int):Bool{
		var m = getMouseDXY();
		
		while (i >= 0 && sigils.length-1 < i){
			sigils.push(new IntPt( -1, -1));
		}
		
		if (sigils[i].x == m.x && sigils[i].y == m.y) return false;
		
		sigils[i].x = m.x;
		sigils[i].y = m.y;
		
		updateSigils();
		
		return true;
	}
	
	public function onSigilErase(i:Int):Bool{
		var m = getMouseDXY();
		
		while (i >= 0 && sigils.length-1 < i){
			sigils.push(new IntPt( -1, -1));
		}
		
		var change = false;
		
		for (sigil in sigils){
			if (m.x == sigil.x && m.y == sigil.y){
				sigil.x = -1;
				sigil.y = -1;
				change = true;
			}
		}
		
		updateSigils();
		
		return change;
	}
	
	
	//private
	
	private var border:FlxSprite;
	private var sigilGroup:FlxSpriteGroup;
	
	private function getMouseDXY():IntPt{
		var dx:Float = FlxG.mouse.getScreenPosition().x - x;
		var dy:Float = FlxG.mouse.getScreenPosition().y - y;
		dx = Std.int(dx / sprite.scale.x);
		dy = Std.int(dy / sprite.scale.y);
		return new IntPt(Std.int(dx), Std.int(dy));
	}
	
	private function set_x(X:Int):Int{
		x = X;
		sprite.x = x;
		button.x = x;
		rightButton.x = x;
		back.x = x;
		border.x = x - 1;
		sigilGroup.x = x;
		return x;
	}
	
	private function set_y(Y:Int):Int{
		y = Y;
		sprite.y = y;
		button.y = y;
		rightButton.y = y;
		back.y = y;
		border.y = y - 1;
		sigilGroup.y = y;
		return y;
	}
	
	private function updateSigils(){
		for (i in 0...sigilGroup.members.length)
		{
			sigilGroup.members[i].visible = false;
		}
		
		for (i in 0...sigils.length)
		{
			var sigil = sigils[i];
			if (sigil.x != -1 && sigil.y != -1){
				while (i >= 0 && sigilGroup.members.length-1 < i)
				{
					sigilGroup.add(new FlxSprite());
				}
				var sprite = sigilGroup.members[i];
				sprite.loadGraphic("assets/gfx/_hd/tiles/sigils.png",true,64,64);
				sprite.animation.frameIndex = i;
				var S = THE_SCALE / (sprite.graphic.height/2);
				sprite.scale.set(S, S);
				sprite.updateHitbox();
				sprite.antialiasing = true;
				sprite.x = sigilGroup.x + sigils[i].x * sprite.width;
				sprite.y = sigilGroup.y + sigils[i].y * sprite.height;
				sprite.visible = true;
			}
		}
	}
	
	private function makeBackGraphic(W:Int, H:Int):BitmapData
	{
		W *= 2;
		H *= 2;
		var bmp = new BitmapData(W, H, false, 0xFFFFFF);
		var a = 0xFF202020;
		var b = 0xFF000000;
		for (y in 0...H){
			for (x in 0...W){
				if ((x + y) % 2 == 0){
					bmp.setPixel(x, y, a);
				}
				else{
					bmp.setPixel(x, y, b);
				}
			}
		}
		return bmp;
	}
	
}