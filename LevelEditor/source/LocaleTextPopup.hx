package;
import flixel.addons.ui.FlxUIGroup;
import flixel.addons.ui.FlxUISprite;
import flixel.util.FlxColor;
import openfl.events.TextEvent;

/**
 * ...
 * @author 
 */
class LocaleTextPopup extends BigTextPopup
{

	private var texts:Map<String,String>;
	private var currLocale:String = "";
	private var btns:Array<FlxUIGroup>;
	private var locCallback:Map<String,String>->Void;
	
	public function new(Texts:Map<String,String>, Label:String, Callback:Map<String,String>->Void, locale:String="en-US") 
	{
		locCallback = Callback;
		texts = Texts;
		
		currLocale = locale;
		
		var Value = Texts.get(locale);
		
		super(Value, Label, function(str:String){onClick(str); }, locale);
		
		input.input.text = Value;
		
		makeFlagBtns();
		for (key in texts.keys()){
			var entry = texts.get(key);
			if(entry == null || entry == ""){
				texts.set(key, "");
			}
		}
		
		
		input.input.addEventListener(TextEvent.TEXT_INPUT, stashLocale, false, 0, true);
		onLocale(locale);
	}
	
	override public function destroy():Void 
	{
		texts = null;
		input.input.removeEventListener(TextEvent.TEXT_INPUT, stashLocale);
		super.destroy();
	}
	
	private function makeFlagBtns(){
		
		var locales = [];
		for (locale in texts.keys()){
			locales.push(locale);
		}
		
		var X:Int = Std.int(back.x + 8);
		var Y:Int = Std.int(back.y + 4);
		var DX:Int = 34;
		
		btns = [];
		
		for (locale in locales){
			var btn = makeFlagBtn(locale);
			btn.x = X;
			btn.y = Y;
			btns.push(btn);
			X += DX;
			add(btn);
		}
	}
	
	override function onClick(str:String) 
	{
		stashLocale(null);
		if (locCallback != null){
			locCallback(texts);
		}
		locCallback = null;
		callback = null;
		close();
	}
	
	private function stashLocale(e:TextEvent):Void{
		texts.set(currLocale, input.input.text);
	}
	
	private function onLocale(locale:String):Void
	{
		stashLocale(null);
		currLocale = locale;
		for (btn in btns){
			if (btn.name == locale){
				btn.alpha = 1.0;
			}else{
				btn.alpha = 0.25;
			}
		}
		
		var font = switch(currLocale){
			case "ja-JP": "mplus2c.ttf";
			case "ko-KR": "nanumgothic.ttf";
			case "zh-HANS": "notosanscjksc.otf";
			case "zh-HANT": "notosanscjktc.otf";
			default: "verdana.ttf";
		}
		
		var dtf = input.input.defaultTextFormat.clone();
		dtf.font = "assets/fonts/" + font;
		input.input.setTextFormat(dtf);
		input.input.defaultTextFormat.font = dtf.font;
		
		input.input.text = texts.get(locale);
	}
	
	private function makeFlagBtn(locale:String):FlxUIGroup
	{
		var newlocale = locale.toLowerCase();
		newlocale = StringTools.replace(locale, "-", "_");
		var str = "assets/gfx/locales/" + newlocale+".png";
		var g = new FlxUIGroup();
		var img = new FlxUISprite();
		img.loadGraphic(str);
		img.scale.set(0.5, 0.5);
		img.updateHitbox();
		img.antialiasing = true;
		var btn = Util.makeBtn(0, 0, "", function(){
			onLocale(locale);
		},img.width,img.height);
		
		var spr = new FlxUISprite();
		spr.makeGraphic(1, 1, FlxColor.BLACK);
		spr.scale.set(img.width, img.height);
		spr.updateHitbox();
		
		g.add(btn);
		g.add(spr);
		g.add(img);
		g.name = locale;
		btn.alpha = 0;
		return g;
	}
}