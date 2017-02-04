package;
import flash.display.BitmapData;
import flash.geom.Point;
import flixel.addons.ui.U;
import flixel.util.FlxColor;
import haxe.xml.Fast;
import openfl.geom.Rectangle;
import unifill.Unifill;
import WaveWidget.WaveInfo;

/**
 * ...
 * @author 
 */
class BattleData
{
	public var starts:Map<String,IntPt>;
	public var ends:Map<String,IntPt>;
	public var layers:Array<LayerData>;
	public var waves:Array<WaveData>;
	
	public function new() 
	{
		
	}
	
	public static function fromXML(xml:Fast):BattleData{
		
		var bd = new BattleData();
		
		if (xml.hasNode.tiles){
			var tiles = xml.node.tiles;
			if (tiles.hasNode.start){
				bd.starts = new Map<String,IntPt>();
				for (start in tiles.nodes.start){
					var x:Int = U.xml_i(start.x, "x");
					var y:Int = U.xml_i(start.x, "y");
					var id:String = U.xml_str(start.x, "id");
					bd.starts.set(id, new IntPt(x, y));
				}
				bd.ends = new Map<String,IntPt>();
				for (end in tiles.nodes.end){
					var x:Int = U.xml_i(end.x, "x");
					var y:Int = U.xml_i(end.x, "y");
					var id:String = U.xml_str(end.x, "id");
					bd.ends.set(id, new IntPt(x, y));
				} 
			}
			
			if (tiles.hasNode.tile){
				bd.layers = [];
				
				for (tile in tiles.nodes.tile){
					bd.layers.push(LayerData.fromXML(tile));
				}
				bd.layers.sort(function(a:LayerData, b:LayerData):Int{
					if (a.layer < b.layer) return -1;
					if (a.layer > b.layer) return  1;
					return 0;
				});
			}
		}
		
		if (xml.hasNode.waves){
			bd.waves = [];
			for(wavesNode in xml.nodes.waves){
				bd.waves.push(WaveData.fromXML(wavesNode));
				bd.waves.sort(function(a:WaveData, b:WaveData):Int{
					if (Util.diffToI(a.difficulty) < Util.diffToI(b.difficulty)) return -1;
					if (Util.diffToI(a.difficulty) > Util.diffToI(b.difficulty)) return  1;
					return 0;
				});
			}
		}
		
		return bd;
	}
	
}

class WaveData
{
	public var firstWait:Float;
	public var difficulty:String;
	public var waves:Array<WaveInfo>;
	
	public function new(){}
	
	public static function fromXML(xml:Fast){
		var wd = new WaveData();
		wd.firstWait = U.xml_f(xml.x, "first_wait", 1);
		wd.difficulty = U.xml_str(xml.x, "diff", true);
		if (xml.hasNode.wave){
			wd.waves = [];
			for (wave in xml.nodes.wave){
				var starts = [false,false,false,false,false];
				var ends = [false,false,false,false,false];
				var startStr = U.xml_str(xml.x, "starts");
				var endStr = U.xml_str(xml.x, "ends");
				
				var startArr = startStr.split(",");
				var endArr = endStr.split(",");
				
				for (start in startArr){
					var i:Int = switch(start){
						case "a": 0;
						case "b": 1;
						case "c": 2;
						case "d": 3;
						case "e": 4;
						default: 0;
					}
					starts[i] = true;
				}
				for (end in endArr){
					var i:Int = switch(end){
						case "a": 0;
						case "b": 1;
						case "c": 2;
						case "d": 3;
						case "e": 4;
						default: 0;
					}
					ends[i] = true;
				}
				
				var info = {
					type:U.xml_str(xml.x,"type",true),
					count:U.xml_i(xml.x,"count",1),
					wait:U.xml_f(xml.x,"wait",1),
					level:U.xml_i(xml.x,"level",1),
					rate:U.xml_f(xml.x,"rate",1),
					starts:starts,
					ends:ends
				}
				wd.waves.push(info);
			}
		}
		return wd;
	}
	
	public static function copyWaveInfo(wi:WaveInfo):WaveInfo{
		return {
			type:wi.type,
			count:wi.count,
			wait:wi.wait,
			level:wi.level,
			rate:wi.rate,
			starts:wi.starts,
			ends:wi.ends
		};
	}
}

class LayerData
{
	public var layer:Int;
	public var value:String;
	public var doodad:FlxColor;
	public var rgb:FlxColor;
	
	public function new(){
		
	}
	
	public static function fromXML(xml:Fast){
		var ld = new LayerData();
		ld.layer = U.xml_i(xml.x, "layer");
		ld.value = U.xml_str(xml.x, "value");
		ld.rgb = U.xml_color(xml.x, "rgb", true, FlxColor.BLACK);
		ld.doodad = U.xml_color(xml.x, "doodad", true, FlxColor.BLACK);
		return ld;
	}
}