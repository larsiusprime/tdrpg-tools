package;
import flixel.FlxSprite;
import flixel.addons.ui.FlxClickArea;
import flixel.addons.ui.FlxUI;
import flixel.addons.ui.FlxUIButton;
import flixel.addons.ui.FlxUIGroup;
import flixel.addons.ui.FlxUISprite;
import flixel.addons.ui.interfaces.IFlxUIWidget;
import WaveWidget.WaveInfo;


/**
 * ...
 * @author 
 */
class SigilWidget extends FlxUIGroup
{

	public var starts:Array<Bool> = [true,false,false,false,false];
	public var ends:Array<Bool> = [true,false,false,false,false];
	
	public function new(xx:Int,yy:Int,H:Float) 
	{
		super(xx, yy);
		var X = 0;
		var Y = 0;
		for (i in 0...5){
			var sigil = makeSigil(i, H);
			sigil.ID = i;
			sigil.x = X;
			var click = new FlxUIButton(X, Y, "", toggleStart.bind(i));
			click.resize(sigil.width, sigil.height);
			click.ID = -1;
			add(click);
			add(sigil);
			click.alpha = 0;
			X += Std.int(sigil.width + 1);
		}
		X = 0;
		for (i in 0...5){
			var sigil = makeSigil(i + 5, H);
			sigil.ID = i + 5;
			if (i == 0){
				Y += Std.int(sigil.height + 1);
			}
			sigil.x = X;
			sigil.y = Y;
			var click = new FlxUIButton(X, Y, "", toggleEnd.bind(i));
			click.resize(sigil.width, sigil.height);
			click.ID = -1;
			add(click);
			add(sigil);
			click.alpha = 0;
			X += Std.int(sigil.width + 1);
		}
	}
	
	public function sync(info:WaveInfo){
		for (i in 0...info.starts.length){
			toggleStart(i, info.starts[i]);
		}
		for (i in 0...info.ends.length){
			toggleEnd(i, info.ends[i]);
		}
	}
	
	private function toggleStart(i:Int, ?b:Bool){
		trace("toggleStart(" + i + "," + b + ")");
		for (j in 0...members.length){
			var member = members[j];
			if (member.ID == i){
				var spr:FlxUISprite = cast member;
				if(b == null){
					starts[i] = !starts[i];
					FlxUI.event("sigil_change", this, null, ["wave_widget"]);
				}else{
					starts[i] = b;
				}
				spr.alpha = starts[i] ? 1.0 : 0.25;
				return;
			}
		}
	}
	
	private function toggleEnd(i:Int,?b:Bool){
		for (j in 0...members.length){
			var member = members[j];
			if (member.ID == i+5){
				var spr:FlxUISprite = cast member;
				if(b == null){
					ends[i] = !ends[i];
					FlxUI.event("sigil_change", this, null, ["wave_widget"]);
				}else{
					ends[i] = b;
				}
				spr.alpha = ends[i] ? 1.0 : 0.25;
				return;
			}
		}
	}
	
	private function makeSigil(i:Int,H:Float):FlxUISprite
	{
		var spr = new FlxUISprite();
		spr.loadGraphic("*assets/images/sigils.png", true, 48, 48);
		spr.scale.set(H / spr.graphic.bitmap.height, H / spr.graphic.bitmap.height);
		spr.updateHitbox();
		spr.antialiasing = true;
		spr.animation.frameIndex = i;
		return spr;
	}
}