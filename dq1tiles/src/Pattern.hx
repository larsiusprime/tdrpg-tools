package;
import flixel.addons.ui.U;
import haxe.xml.Fast;
import haxe.zip.Entry;

/**
 * ...
 * @author larsiusprime
 */
class Pattern
{
	private var cur:Int = 0;
	private var tiles:Array<Entry> = [];
	
	public var width(default, null):Int;
	public var height(default, null):Int;
	public var length(default, null):Int;
	
	public function new() 
	{
		var xml:Fast = U.xml("pattern", "xml", true, "assets/");
		
		width = U.xml_i(xml.node.size.x, "width");
		height = U.xml_i(xml.node.size.x, "height");
		length = U.xml_i(xml.node.size.x, "length");
		
		for (tile in xml.nodes.tile) {
			var in_x = U.xml_i(tile.x, "in_x");
			var in_y = U.xml_i(tile.x, "in_y");
			var out_x = U.xml_i(tile.x, "out_x");
			var out_y = U.xml_i(tile.x, "out_y");
			var crop_half = U.xml_str(tile.x, "crop_half");
			tiles.push( { in_x:in_x, in_y:in_y, out_x:out_x, out_y:out_y, crop_half:crop_half } );
		}
	}
	
	public function atEnd():Bool {
		return cur >= tiles.length;
	}
	
	public function getNext():Entry {
		var thing = tiles[cur];
		cur++;
		return thing;
	}
	
}

typedef Entry = { in_x:Int, in_y:Int, out_x:Int, out_y:Int, crop_half:String };