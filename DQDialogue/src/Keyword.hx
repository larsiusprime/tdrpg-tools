package;
import org.zamedev.lib.Utf8Ext;

/**
 * @author 
 */
abstract Keyword(String) from String to String
{
	public static inline var BEGIN:String = "BEGIN";
	public static inline var END:String = "END";
	public static inline var NAMES:String = "NAMES";
	public static inline var DUB:String = "DUB";
	public static inline var JOIN:String = "JOIN";
	public static inline var PLAINTEXT:String = "PLAINTEXT";
	public static inline var NARRATOR:String = "NARRATOR";
	public static inline var COMMENT:String = "COMMENT";
	public static inline var PLACEHOLDER:String = "PLACEHOLDER";
	public static inline var TUTORIAL:String = "TUTORIAL";
	public static inline var NEWGAME:String = "NEWGAME";
	public static inline var INTRO:String = "INTRO";
	public static inline var WATCH:String = "WATCH";
	public static inline var BATTLE:String = "BATTLE";
	public static inline var OUTRO:String = "OUTRO";
	public static inline var OVERWORLD:String = "OVERWORLD";
	public static inline var PARTY:String = "PARTY";
	public static inline var TOWN:String = "TOWN";
	public static inline var REWARDS:String = "REWARDS";
	public static inline var SPEECH:String = "SPEECH";
	public static inline var ACTION:String = "ACTION";
	public static inline var ERROR:String = "ERROR";
	public static inline var UNKNOWN:String = "UNKNOWN";
	public static inline var IGNORED:String = "IGNORED";
	
	public function new(str:String)
	{
		this = fromString(str);
	}
	
	public static inline function fromString(str:String)
	{
		str = Utf8Ext.toUpperCase(str);
		return switch(str)
		{
			case "BEGIN": BEGIN;
			case "END": END;
			case "NAMES": NAMES;
			case "DUB": DUB;
			case "JOIN": JOIN;
			case "PLAINTEXT": PLAINTEXT;
			case "NARRATOR": NARRATOR;
			case "COMMENT": COMMENT;
			case "PLACEHOLDER": PLACEHOLDER;
			case "TUTORIAL": TUTORIAL;
			case "NEWGAME": NEWGAME;
			case "INTRO": INTRO;
			case "WATCH": WATCH;
			case "BATTLE": BATTLE;
			case "OUTRO": OUTRO;
			case "OVERWORLD": OVERWORLD;
			case "PARTY": PARTY;
			case "TOWN": TOWN;
			case "REWARDS": REWARDS;
			case "SPEECH": SPEECH;
			case "ACTION": ACTION;
			case "ERROR": ERROR;
			case "UNKNOWN": UNKNOWN;
			case "IGNORED": IGNORED;
			default: UNKNOWN;
		}
	}
}