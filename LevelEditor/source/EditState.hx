package;
import flash.geom.Point;
import flixel.util.FlxArrayUtil;
import openfl.display.BitmapData;

/**
 * ...
 * @author 
 */
class EditState
{
	public var layers:Array<BitmapData>;
	public var sigils:Array<IntPt>;
	
	public function new(other:Array<MapLayer>)
	{
		sync(other);
	}
	
	public function destroy(){
		if (layers == null) return;
		for (layer in layers){
			if(layer != null){
				layer.dispose();
			}
		}
		FlxArrayUtil.clearArray(layers);
		FlxArrayUtil.clearArray(sigils);
		layers = null;
		sigils = null;
	}
	
	public function sync(other:Array<MapLayer>)
	{
		if (layers != null && other.length != layers.length){
			while (layers.length > 0){
				var bmp = layers.pop();
				bmp.dispose();
			}
			FlxArrayUtil.clearArray(layers);
			FlxArrayUtil.clearArray(sigils);
			layers = null;
			sigils = null;
		}
		
		if (layers == null){
			layers = [];
			for (i in 0...other.length){
				layers.push(other[i].sprite.graphic.bitmap.clone());
			}
			sigils = [];
			for (i in 0...other[0].sigils.length){
				sigils.push(other[0].sigils[i].copy());
			}
			return;
		}
		var zpt = new Point();
		for (i in 0...other.length){
			layers[i].copyPixels(other[i].sprite.graphic.bitmap, other[i].sprite.graphic.bitmap.rect, zpt);
		}
		for (i in 0...other[0].sigils.length){
			sigils[i].x = other[0].sigils[i].x;
			sigils[i].y = other[0].sigils[i].y;
		}
	}
}