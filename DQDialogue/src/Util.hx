package;
import unifill.CodePoint;
using unifill.Unifill;
/**
 * ...
 * @author 
 */
class Util
{

	public function new() 
	{
		
	}
	
	public static function stripStuff(s:String):String
	{
		var arr = ["!", "@", "#", "$", "%", "^", "&", "*", "(", ")", "-", "+", "=", "[", "]", "{", "}", "\\", "|", "/", ";", ":", "\"", "'", ",", ".", "<", ">", "?", "\r", "\n"];
		return uStrip(s, arr);
	}
	
	public static function uStrip(s:String, arr:Array<String>):String
	{
		for (str in arr)
		{
			while (s.uIndexOf(str) != -1)
			{
				s = uReplace(s, str, "");
			}
		}
		return s;
	}
	
	public static function uJoin(arr:Array<String>, char:String):String
	{
		var sb = new StringBuf();
		for (i in 0...arr.length)
		{
			var str = arr[i];
			sb.add(str);
			if (i != arr.length - 1)
			{
				sb.add(char);
			}
		}
		return sb.toString();
	}
	
	public static function uCat(a:String, b:String):String
	{
		var sb = new StringBuf();
		sb.add(Std.string(a));
		sb.add(Std.string(b));
		return sb.toString();
	}
	
	public static function uCombine(arr:Array<String>):String
	{
		var sb = new StringBuf();
		for (str in arr)
		{
			sb.add(Std.string(str));
		}
		return sb.toString();
	}
	
	public static inline function padLeft(str:String, d:Int, padChar:String = "0"):String{
		
		while (str.length < d)
		{
			str = padChar + str;
		}
		
		return str;
	}
	
	public static inline function padDigits(i:Int, d:Int, padChar:String="0"):String {
		var f:Float = i;
		var str:String = "";
		var num_digits:Int = 0;
		while (f >= 1) {
			f /= 10;
			num_digits++;
		}
		
		if (i == 0) {
			num_digits = 1; //special case
		}
		
		if(num_digits < d){		
			for (temp in 0...(d-num_digits)) {
				str += padChar;
			}
		}
		
		return str + Std.string(i);
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
}