package;
import flash.geom.Point;
import openfl.display.BitmapData;

/**
 * ...
 * @author 
 */
class EditState
{
	public var layers:Array<BitmapData>;
	
	public function new(other:Array<MapLayer>)
	{
		sync(other);
	}
	
	public function sync(other:Array<MapLayer>)
	{
		if (layers == null){
			layers = [];
			for (i in 0...other.length){
				layers.push(other[i].sprite.graphic.bitmap.clone());
			}
			return;
		}
		var zpt = new Point();
		for (i in 0...other.length){
			layers[i].copyPixels(other[i].sprite.graphic.bitmap, other[i].sprite.graphic.bitmap.rect, zpt);
		}
	}
}