package;
import flixel.addons.ui.FlxUIButton;
import flixel.addons.ui.FlxUICheckBox;
import flixel.addons.ui.FlxUIGroup;
import flixel.addons.ui.FlxUILine;
import flixel.addons.ui.FlxUIRadioGroup;
import flixel.addons.ui.FlxUIText;
import flixel.util.FlxColor;
import haxe.xml.Fast;
import unifill.Unifill;
import flixel.text.FlxText.FlxTextAlign;
import flixel.addons.ui.FlxUILine.LineAxis;

/**
 * ...
 * @author 
 */
class Util
{

	public static function xmlify(str:String){
		return Xml.parse(str).firstElement();
	}
	
	public static function getLastFolder(path:String):String
	{
		var arr = splitPath(path);
		
		while(arr[arr.length - 1] == ""){
			arr.pop();
		}
		
		var last = arr[arr.length - 1];
		
		
		return last;
	}
	
	public static function getFast(str:String):Fast{
		var xml:Xml = Xml.parse(str).firstElement();
		return new Fast(xml);
	}
	
	public static function makeTxt(X:Int, Y:Int, W:Float, label:String):FlxUIText{
		var txt = new FlxUIText(X, Y, W, label, 12);
		txt.font = "assets/fonts/verdana.ttf";
		txt.color = FlxColor.BLACK;
		txt.alignment = FlxTextAlign.LEFT;
		return txt;
	}
	
	public static function makeBtn(X:Int,Y:Int,label:String,callback:Void->Void,W:Float=100,H:Float=32){
		var btn = new FlxUIButton(X, Y, label, callback);
		btn.label.font = "assets/fonts/verdana.ttf";
		btn.label.size = 14;
		btn.label.color = FlxColor.BLACK;
		btn.resize(W, H);
		return btn;
	}
	
	public static function makeCheckbox(X:Float,Y:Float,label:String,callback:Void->Void){
		var cb = new FlxUICheckBox(X, Y, null, null, label, null, null, callback);
		var text:FlxUIText = cast cb.getLabel();
		cb.button.setLabelFormat("assets/fonts/verdana.ttf", 12, FlxColor.BLACK);
		text.setFormat("assets/fonts/verdana.ttf", 12, FlxColor.BLACK);
		var offsets = cb.button.getCenterLabelOffset();
		cb.button.autoCenterLabel();
		var noffsets = cb.button.getCenterLabelOffset();
		cb.button.setCenterLabelOffset(offsets.x, noffsets.y);
		cb.button.up_color = cb.button.over_color = cb.button.down_color = cb.button.down_toggle_color = cb.button.over_toggle_color = cb.button.over_toggle_color = FlxColor.BLACK;
		return cb;
	}
	
	public static function activateRadios(g:FlxUIRadioGroup,ids:Array<String>,b:Bool)
	{
		var rs:Array<FlxUICheckBox> = g.getRadios();
		for (i in 0...g.numRadios){
			var cb:FlxUICheckBox = rs[i];
			if (ids.indexOf(g.getId(i)) != -1){
				cb.alpha = b ? 1.0 : 0.5;
				cb.active = b;
			}
		}
	}
	
	public static function diffI(diff:String):Int{
		return diffToI(diff);
	}
	
	public static function diffToI(str:String){
		return switch(str){
			case "easy": 0;
			case "normal": 1;
			case "hard": 2;
			default: 0;
		}
		return 0;
	}
	
	public static function makeRadios(X:Float,Y:Float,ids:Array<String>,labels:Array<String>,callback:String->Void):FlxUIRadioGroup{
		var radios = new FlxUIRadioGroup(X, Y, ids, labels, callback);
		var rs = radios.getRadios();
		for (i in 0...radios.numRadios){
			var cb:FlxUICheckBox = rs[i];
			var text:FlxUIText = cast cb.getLabel();
			cb.button.setLabelFormat("assets/fonts/verdana.ttf", 12, FlxColor.BLACK);
			text.setFormat("assets/fonts/verdana.ttf", 12, FlxColor.BLACK);
			var offsets = cb.button.getCenterLabelOffset();
			cb.button.autoCenterLabel();
			var noffsets = cb.button.getCenterLabelOffset();
			cb.button.setCenterLabelOffset(offsets.x, noffsets.y);
			cb.button.up_color = cb.button.over_color = cb.button.down_color = cb.button.down_toggle_color = cb.button.over_toggle_color = cb.button.over_toggle_color = FlxColor.BLACK;
		}
		return radios;
	}
	
	public static function makeBox(W:Int, H:Int):FlxUIGroup{
		var top    = new FlxUILine(0, 0,     LineAxis.HORIZONTAL, W, 2, FlxColor.BLACK);
		var left   = new FlxUILine(0, 0,     LineAxis.VERTICAL  , H, 2, FlxColor.BLACK);
		var bottom = new FlxUILine(0, H - 2, LineAxis.HORIZONTAL, W, 2, FlxColor.BLACK);
		var right  = new FlxUILine(W - 2, 0, LineAxis.VERTICAL  , H, 2, FlxColor.BLACK);
		var g = new FlxUIGroup();
		g.add(top);
		g.add(left);
		g.add(right);
		g.add(bottom);
		return g;
	}
	
	public static function safePath(path:String, add:String):String{
		var fLast = Unifill.uLastIndexOf(path, "/");
		var bLast = Unifill.uLastIndexOf(path, "\\");
		var last = Unifill.uLength(path) - 1;
		var needsSlash = (fLast != last && bLast != last);
		var sb = new StringBuf();
		sb.add(path);
		if (needsSlash){
			sb.add("/");
		}
		sb.add(add);
		return sb.toString();
	}
	
	public static function uCat(a:String, b:String):String{
		var sb = new StringBuf();
		sb.add(a);
		sb.add(b);
		return sb.toString();
	}
	
	public static function joinPath(arr:Array<String>,trailingSlash:Bool=false):String{
		var sb:StringBuf = new StringBuf();
		for (i in 0...arr.length){
			var str = arr[i];
			sb.add(str);
			if (trailingSlash || i != arr.length - 1){
				sb.add("/");
			}
		}
		return sb.toString();
	}
	
	public static function splitPath(path:String):Array<String>
	{
		var arr:Array<String> = Unifill.uSplit(path, "/");
		
		var newArr:Array<String> = [];
		for (str in arr){
			if (Unifill.uIndexOf(str,"\\") != -1){
				var bArr = Unifill.uSplit(str, "\\");
				for (bStr in bArr){
					newArr.push(bStr);
				}
			}
			else{
				newArr.push(str);
			}
		}
		
		return newArr;
	}
	
	public static function goUpOneDirectory(path:String):String
	{
		var arr = splitPath(path);
		arr.pop();
		
		var sb:StringBuf = new StringBuf();
		for (i in 0...arr.length){
			sb.add(arr[i]);
			sb.add("/");
		}
		
		return sb.toString();
	}
	
	public static function stripExtension(path:String):String
	{
		if (Unifill.uIndexOf(path, ".") == -1) return path;
		
		var arr = Unifill.uSplit(path, ".");
		var sb:StringBuf = new StringBuf();
		for (i in 0...arr.length){
			if (i == arr.length - 1) continue;
			sb.add(arr[i]);
			if (i != arr.length - 2){
				sb.add(".");
			}
		}
		return sb.toString();
	}
}