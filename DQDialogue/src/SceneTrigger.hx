package;
import org.zamedev.lib.Utf8Ext;

/**
 * @author 
 */
abstract SceneTrigger(String) from String to String
{
	public static inline var NEWGAME:String = "NEWGAME";
	public static inline var INTRO:String = "INTRO";
	public static inline var WATCH:String = "WATCH";
	public static inline var OUTRO:String = "OUTRO";
	public static inline var BATTLE:String = "BATTLE";
	public static inline var OVERWORLD:String = "OVERWORLD";
	public static inline var PARTY:String = "PARTY";
	public static inline var TOWN:String = "TOWN";
	public static inline var REWARDS:String = "REWARDS";
	public static inline var ERROR:String = "ERROR";
	public static inline var UNKNOWN:String = "UNKNOWN";
	
	public function new(str:String)
	{
		this = fromString(str);
	}
	
	public static inline function fromString(str:String)
	{
		str = Utf8Ext.toUpperCase(str);
		return switch(str)
		{
			case "NEWGAME": NEWGAME;
			case "INTRO": INTRO;
			case "WATCH": WATCH;
			case "OUTRO": OUTRO;
			case "BATTLE": BATTLE;
			case "OVERWORLD": OVERWORLD;
			case "PARTY": PARTY;
			case "TOWN": TOWN;
			case "REWARDS": REWARDS;
			case "ERROR": ERROR;
			case "UNKNOWN": UNKNOWN;
			default: UNKNOWN;
		}
	}
}