package;
import flash.display.BitmapData;
import flash.geom.Point;
import flixel.addons.ui.U;
import flixel.util.FlxColor;
import haxe.xml.Fast;
import openfl.geom.Rectangle;
import unifill.Unifill;
import WaveWidget.WaveInfo;
import RewardsPicker.RewardStruct;

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
	public var isEndless:Bool = false;
	public var endlessLevelup:Int = 1;
	public var waves:Array<WaveInfo>;
	
	public function new(){}
	
	public static function fromXML(xml:Fast){
		var wd = new WaveData();
		wd.firstWait = U.xml_f(xml.x, "first_wait", 1);
		wd.difficulty = U.xml_str(xml.x, "diff", true);
		wd.isEndless = U.xml_bool(xml.x, "infinite", false);
		wd.endlessLevelup = U.xml_i(xml.x, "lvl_up", 1);
		if (xml.hasNode.wave){
			wd.waves = [];
			for (wave in xml.nodes.wave){
				var starts = [false,false,false,false,false];
				var ends = [false,false,false,false,false];
				var startStr = U.xml_str(wave.x, "loc");
				//var endStr = U.xml_str(xml.x, "ends");
				
				var startArr = startStr.split(",");
				//var endArr = endStr.split(",");
				
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
				/*
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
				}*/
				
				var info = {
					type:U.xml_str(wave.x,"type",true),
					count:U.xml_i(wave.x,"count",1),
					wait:U.xml_f(wave.x,"wait",1),
					level:U.xml_i(wave.x,"level",1),
					rate:U.xml_f(wave.x, "rate", 1),
					starts:starts,
					ends:ends
				}
				wd.waves.push(info);
			}
		}
		
		return wd;
	}
	
	public function toString():String{
		return "{difficulty:" + difficulty + ",firstWait:" + firstWait + ",waves:" + waves + "}";
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

class BonusStruct
{
	public var stars:Int;
	public var starsColor:String;
	
	public var starsPlus:Int;
	public var starsPlusColor:String;
	
	public var id:String;
	public var title:String;
	public var description:String;
	
	public var rewards:Array<RewardStruct>;
	
	public function new(){}
	
	public function match(other:BonusStruct, safe:Bool=true){
		stars = other.stars;
		starsColor = other.starsColor;
		starsPlus = other.starsPlus;
		starsPlusColor = other.starsPlusColor;
		if(safe){
			id = other.id != "" && other.id != null ? other.id : id;
			title = other.title != "" && other.title != null ? other.title : title;
			description = other.description != "" && other.description != null ? other.description : description;
		}else{
			id = other.id;
			title = other.title;
			description = other.description;
		}
		matchRewards(other.rewards);
	}
	
	public static function arrayFromXML(xml:Fast):Array<BonusStruct>
	{
		var bonuses:Array<BonusStruct> = [];
		if (xml.hasNode.bonus){
			for (bonusNode in xml.nodes.bonus){
				var bs = BonusStruct.fromXML(bonusNode);
				bonuses.push(bs);
			}
		}
		return bonuses;
	}
	
	private function getReward():RewardStruct{
		return {
			feat:"",
			goal:"",
			type:"",
			typePlus:"",
			value:"",
			valuePlus:""
		};
	}
	
	public function matchRewards(arr:Array<RewardStruct>){
		
		if (rewards == null){
			rewards = [];
			rewards.push(getReward());
			rewards.push(getReward());
		}
		
		for (i in 0...arr.length){
			var other = arr[i];
			for (j in 0...rewards.length){
				if (i == j){
					var mine = rewards[j];
					mine.feat = other.feat;
					mine.goal = other.goal;
					mine.type = other.type;
					mine.typePlus = other.typePlus;
					mine.value = other.value;
					mine.valuePlus = other.valuePlus;
				}
			}
		}
	}
	
	public static function fromXML(xml:Fast):BonusStruct{
		var bs = new BonusStruct();
		
		bs.stars = U.xml_i(xml.x, "stars");
		bs.starsColor = U.xml_str(xml.x, "color");
		bs.starsPlus = U.xml_i(xml.x, "stars_plus");
		bs.starsPlusColor = U.xml_str(xml.x, "color_plus");
		bs.id = U.xml_name(xml.x);
		bs.title = U.xml_str(xml.x, "title");
		bs.description = U.xml_str(xml.x, "description");
		
		bs.rewards = [];
		if (xml.hasNode.rewards && xml.node.rewards.hasNode.reward){
			for (rewardNode in xml.node.rewards.nodes.reward){
				
				bs.rewards.push({
					feat:U.xml_str(rewardNode.x,"feat"),
					goal:U.xml_str(rewardNode.x,"goal"),
					type:U.xml_str(rewardNode.x,"type",true),
					value:U.xml_str(rewardNode.x,"value"),
					typePlus:U.xml_str(rewardNode.x,"type_plus",true),
					valuePlus:U.xml_str(rewardNode.x,"value_plus")
				});
				
			}
		}
		
		return bs;
	}
}