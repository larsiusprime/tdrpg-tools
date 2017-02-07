package;
import firetongue.TSV;
import flash.display.BitmapData;
import flixel.FlxObject;
import flixel.FlxState;
import flixel.addons.ui.FlxUIButton;
import flixel.addons.ui.FlxUICheckBox;
import flixel.addons.ui.FlxUIGroup;
import flixel.addons.ui.FlxUILine;
import flixel.addons.ui.FlxUIRadioGroup;
import flixel.addons.ui.FlxUISprite;
import flixel.addons.ui.FlxUIState;
import flixel.addons.ui.FlxUISubState;
import flixel.addons.ui.FlxUIText;
import flixel.addons.ui.U;
import flixel.addons.ui.interfaces.IFlxUIState;
import flixel.util.FlxColor;
import haxe.xml.Fast;
import lime.ui.FileDialog;
import lime.ui.FileDialogType;
import openfl.geom.Point;
import openfl.geom.Rectangle;
import sys.FileSystem;
import unifill.CodePoint;
import unifill.Unifill;
import flixel.text.FlxText.FlxTextAlign;
import flixel.addons.ui.FlxUILine.LineAxis;
import RewardsPicker.RewardStruct;

/**
 * ...
 * @author 
 */
class Util
{
	public static var dq1:Settings;
	public static var dq2:Settings;
	public static var dataFetcher:DataFetcher;
	
	public static function initSettings(){
		makeSettings();
	}
	
	private static function makeSettings(){
		dq1 = new Settings();
		dq2 = new Settings();
		
		dq1.tilesetStyle = "dq1";
		dq1.tilesPerSquare = 2;
		dq1.squaresWide = 15;
		dq1.squaresTall = 14;
		
		dq2.tilesetStyle = "dq2";
		dq2.tilesPerSquare = 1;
		dq2.squaresWide = 23;
		dq2.squaresTall = 15;
	}
	
	public static function abc2num(str:String):Int{
		return switch(str){
			case "a": 0;
			case "b": 1;
			case "c": 2;
			case "d": 3;
			case "e": 4;
			default: 0;
		}
	}
	
	public static function num2abc(i:Int):String{
		return switch(i){
			case 0: "a";
			case 1: "b";
			case 2: "c";
			case 3: "d";
			case 4: "e";
			default: "a";
		}
	}
	
	
	
	public static function splitMapBitmap(bmp:BitmapData, layers:Int):Array<BitmapData>
	{
		var sw = Util.dq1.squaresWide;
		var sh = Util.dq1.squaresTall;
		
		var arr = [];
		var rect = new Rectangle(sw, 0, sw, sh);
		for (i in 0...layers){
			var out:BitmapData = new BitmapData(sw, sh, false, 0x000000);
			out.copyPixels(bmp, rect, new Point());
			arr.push(out);
			rect.x += sw;
		}
		
		return arr;
	}
	
	public static function appendToTSV(tsvData:String, flag:String, value:String):String{
		
		var tsv = new TSV(tsvData);
		
		var found = false;
		for (row in tsv.grid){
			if (row[0] == flag){
				row[1] = value;
				found = true;
			}
		}
		
		if (!found){
			tsv.grid.push([flag, value]);
		}
		
		var str = "";
		for (i in 0...tsv.fields.length){
			var field = tsv.fields[i];
			str = Util.uCat(str, field);
			if (i != tsv.fields.length - 1){
				str = Util.uCat(str, "\t");
			}
		}
		
		var lastChar = Unifill.uCharCodeAt(str, Unifill.uLength(str) - 1);
		
		if(lastChar != 10 && lastChar != 13){
			str = Util.uCat(str, "\n");
		}
		
		for (row in 0...tsv.grid.length){
			if (tsv.grid[row].length == 0) continue;
			for (col in 0...tsv.grid[row].length){
				str = Util.uCat(str, tsv.grid[row][col]);
				if (col != tsv.grid[row].length - 1){
					str = Util.uCat(str, "\t");
				}
			}
			if (row != tsv.grid.length - 1){
				var lastChar = Unifill.uCharCodeAt(str, Unifill.uLength(str) - 1);
				if(lastChar != 10 && lastChar != 13){
					str = Util.uCat(str, "\n");
				}
			}
		}
		
		return str;
	}
	
	
	public static function isLineBlank(str:String){
		var i:Int;
		for (i in 0...str.length){
			switch(str.charAt(i)){
				case " ", "\t", "\r", "\n":
					//do nothing
				default:
					return false;
			}
		}
		return true;
	}
	
	public static function killBlankLines(str:String):String{
		var lines = Unifill.uSplit(str, "\n");
		var lastLine = "";
		var newLines = [];
		for (i in 0...lines.length){
			if (i != 0){
				if (!isLineBlank(lines[i])){
					newLines.push(lines[i]);
				}
			}
		}
		var sb:StringBuf = new StringBuf();
		for (i in 0...newLines.length){
			sb.add(newLines[i]);
			if(i != newLines.length-1){
				sb.add("\n");
			}
		}
		return sb.toString();
	}
	
	public static function xmlify(str:String){
		return Xml.parse(str).firstElement();
	}
	
	public static function ensurePath(path:String)
	{
		if (FileSystem.exists(path) && FileSystem.isDirectory(path)) return;
		
		var parent = getParentDir(path);
		if (parent == null || parent == "" || FileSystem.exists(parent)){
			//donothing
		}
		else{
			ensurePath(parent);
		}
		
		var stripped = stripExtension(path);
		var isFile = (stripped != path);
		
		if(path != null && path != "" && !isFile){
			FileSystem.createDirectory(path);
		}
	}
	
	public static function matchRewards(a:RewardStruct, b:RewardStruct){
		a.feat = b.feat;
		a.goal = b.goal;
		a.type = b.type;
		a.typePlus = b.typePlus;
		a.value = b.value;
		a.valuePlus = b.valuePlus;
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
	
	public static function makeBox(W:Int, H:Int, Col:FlxColor = null):FlxUIGroup{
		var top    = new FlxUILine(0, 0,     LineAxis.HORIZONTAL, W, 2, FlxColor.BLACK);
		var left   = new FlxUILine(0, 0,     LineAxis.VERTICAL  , H, 2, FlxColor.BLACK);
		var bottom = new FlxUILine(0, H - 2, LineAxis.HORIZONTAL, W, 2, FlxColor.BLACK);
		var right  = new FlxUILine(W - 2, 0, LineAxis.VERTICAL  , H, 2, FlxColor.BLACK);
		var g = new FlxUIGroup();
		if (Col != null){
			var s = new FlxUISprite(0, 0);
			s.makeGraphic(1, 1, Col, true);
			s.scale.set(W, H);
			s.updateHitbox();
			g.add(s);
		}
		g.add(top);
		g.add(left);
		g.add(right);
		g.add(bottom);
		return g;
	}
	
	public static function promptPath(callback:String->Void, type:FileDialogType = null){
		#if sys
			if (type == null){
				type = FileDialogType.SAVE;
			}
			var openFileDialog = new FileDialog();
			openFileDialog.onSelect.add(callback);
			
			try
			{
				openFileDialog.browse(type,"");
			}
			catch (e:Dynamic)
			{
				trace("error : " + e);
			}
		#end
	}
	
	public static inline function center(fb1:FlxObject,fb2:FlxObject,centerX:Bool=true,centerY:Bool=true):Void {
		U.center(fb1, fb2, centerX, centerY);
		fb2.x = Std.int(fb2.x);
		fb2.y = Std.int(fb2.y);
	}
	
	public static function alert(state:IFlxUIState, title:String, message:String, closeParam:String=""){
		var popup = new Popup(title, message, closeParam);
		if(Std.is(state,FlxUIState)){
			cast(state,FlxUIState).openSubState(popup);
		}
		else if (Std.is(state, FlxUISubState)){
			cast(state,FlxUISubState).openSubState(popup);
		}
	}
	
	public static function fixSlashes(str:String):String
	{
		var slash:String = getSlash();
		
		var otherslash:String = "";
		if (slash == "/") {
			otherslash = "\\";
		}else if(slash == "\\"){
			otherslash = "/";
		}
	
		//enforce operating system slash style
		str = uReplace(str, otherslash, slash);
		
		return str;
	}
	
	public static function fixDoubleSlash(str:String):String{
		var str = fixSlashes(str);
		return uReplace(str, getSlash() + getSlash(), getSlash());
	}
	
	public static function getSlash(os:String=""):String {
		var os = "";
		#if windows
			os = "win";
		#end
		var slash:String = "/";
		if (os == "win" || os == "windows") { slash = "\\";}
		return slash;
	}
	
	public static function uReplace(s:String, substr:String, by:String, recursive:Bool=true):String
	{
		if (Unifill.uIndexOf(s, substr) == -1) return s;
		
		var sb = new StringBuf();
		
		//turn the substr into an array of code points
		var substrArr:Array<CodePoint> = [];
		var iter = Unifill.uIterator(substr);
		while (iter.hasNext())
		{
			substrArr.push(iter.next());
		}
		
		//turn the by str into an array of code points
		var byArr:Array<CodePoint> = [];
		iter = Unifill.uIterator(by);
		while (iter.hasNext())
		{
			byArr.push(iter.next());
		}
		
		var matchI:Int = 0;
		var onMatch = false;
		iter = Unifill.uIterator(s);
		
		while (iter.hasNext())
		{
			//iterate through the main string code point by code point
			var cp:CodePoint = iter.next();
			
			if (matchI < substrArr.length && cp == substrArr[matchI])
			{
				//detected the substr -- advance but don't write to the buffer
				onMatch = true;
				matchI++;
			}
			else
			{
				if (onMatch)
				{
					onMatch = false;
					matchI = 0;
					//write the replacement str to the buffer
					for (i in 0...byArr.length)
					{
						Unifill.uAddChar(sb, byArr[i]);
					}
				}
				//write the character to the buffer
				Unifill.uAddChar(sb, cp);
			}
		}
		if (onMatch && matchI >= substrArr.length)
		{
			for (i in 0...byArr.length)
			{
				Unifill.uAddChar(sb, byArr[i]);
			}
		}
		
		if (recursive)
		{
			return uReplace(sb.toString(), substr, by, true);
		}
		
		//return the final string
		return sb.toString();
	}
	
	public static function safePath(path:String, add:String):String{
		var fLast = Unifill.uLastIndexOf(path, "/");
		var bLast = Unifill.uLastIndexOf(path, "\\");
		var last = Unifill.uLength(path) - 1;
		var needsSlash = (fLast != last && bLast != last);
		var sb = new StringBuf();
		sb.add(path);
		if (needsSlash){
			sb.add(getSlash());
		}
		if (Unifill.uIndexOf(add, "\\") != -1 || Unifill.uIndexOf(add, "/") != -1){
			add == Unifill.uSubstr(add, 1, Unifill.uLength(add) - 1);
		}
		sb.add(add);
		var str = sb.toString();
		str = fixDoubleSlash(str);
		return str;
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
				sb.add(getSlash());
			}
		}
		return sb.toString();
	}
	
	public static function getParentDir(path:String):String{
		var bits = splitPath(path);
		if (bits != null && bits.length > 0){
			bits.pop();
			return joinPath(bits);
		}
		return "";
	}
	
	public static function pathStartsWithAssets(path:String):Bool{
		var bits = splitPath(path);
		if (bits != null && bits.length > 0 && bits[0] == "assets"){
			return true;
		}
		return false;
	}
	
	public static function pathEndsInAssets(path:String):Bool{
		var bits = splitPath(path);
		if (bits != null && bits.length > 0 && bits[bits.length - 1] == "assets"){
			return true;
		}
		return false;
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
			sb.add(getSlash());
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