package;

import firetongue.TSV;
import haxe.Utf8;
import haxe.xml.Fast;
import openfl.Assets;
import openfl.display.Sprite;
import openfl.Lib;
import openfl.geom.Point;
import sys.FileSystem;
import sys.io.File;
import unifill.CodePoint;
import unifill.Unifill;

/**
 * ...
 * @author 
 */
class Main extends Sprite 
{
	public function new() 
	{
		super();
		//countChars();
		countChars2();
	}
	
	private function getChars(bmpSrc:String):Array<Int>
	{
		while (bmpSrc.indexOf("chars=") != -1)
		{
			bmpSrc = StringTools.replace(bmpSrc, "chars=", "");
		}
		var lines = bmpSrc.split("\n");
		var chars:Array<Int> = [];
		for (line in lines)
		{
			var bits = line.split(",");
			for (bit in bits)
			{
				if (bit == "") continue;
				if (bit.indexOf("-") != -1)
				{
					var pair = bit.split("-");
					var a = Std.parseInt(pair[0]);
					var b = Std.parseInt(pair[1]);
					for (count in a...b + 1)
					{
						chars.push(count);
					}
				}
				else
				{
					var a = Std.parseInt(bit);
					chars.push(a);
				}
			}
		}
		return chars;
	}
	
	private function utf8(i:Int):String
	{
		var b = new Utf8();
		b.addChar(i);
		return b.toString();
	}
	
	private function countChars2()
	{
		var inText = Assets.getText("assets/in.bmfc");
		var outText = Assets.getText("assets/out.bmfc");
		
		var inArr = getChars(inText);
		var outArr = getChars(outText);
		
		var iMissing:Array<Int> = [];
		var cMissing:Array<String> = [];
		
		var iExtra:Array<Int> = [];
		var cExtra:Array<String> = [];
		
		for (inChar in inArr)
		{
			if (outArr.indexOf(inChar) == -1)
			{
				Sys.println("char (" + inChar + ") is missing!");
				iMissing.push(inChar);
				cMissing.push(utf8(inChar));
			}
		}
		
		for (outChar in outArr)
		{
			if (inArr.indexOf(outChar) == -1)
			{
				Sys.println("char (" + outChar + ") is extra!");
				iExtra.push(outChar);
				cExtra.push(utf8(outChar));
			}
		}
		
		var missing = "";
		for (i in 0...iMissing.length)
		{
			missing += iMissing[i] + ": " + cMissing[i] + "\n";
		}
		var extra = "";
		for (i in 0...iExtra.length){
			extra += iExtra[i] + ": " + cExtra[i] + "\n";
		}
		
		Sys.println("in chars = " + inArr.length);
		Sys.println("out chars = " + outArr.length);
		
		if (extra == "" && missing == "")
		{
			Sys.println("FILES ARE IDENTICAL!");
		}
		
		File.saveContent("missing.txt", missing);
		File.saveContent("extra.txt", extra);
	}
	
	private function countChars()
	{
		var font = Assets.getText("assets/font.xml");
		var text = Assets.getText("assets/chars.txt");
		
		var xml = new Fast(Xml.parse(font));
		var fontNode = xml.node.font;
		var charsNode = fontNode.node.chars;
		var fontChars:Array<String> = [];
		var charsNotInFont:Array<String> = [];
		var charsNotInText:Array<String> = [];
		for (charNode in charsNode.nodes.char)
		{
			var id:Int = Std.parseInt(charNode.x.get("id"));
			var utf8:Utf8 = new Utf8();
			utf8.addChar(id);
			var theChar = utf8.toString();
			fontChars.push(theChar);
			
			var i = Unifill.uIndexOf(text, theChar);
			
			if (i == -1)
			{
				charsNotInText.push(theChar);
			}
		}
		Utf8.iter(text, 
			function(c:Int):Void
			{
				var utf8:Utf8 = new Utf8();
				utf8.addChar(c);
				var theChar = utf8.toString();
				
				var i = fontChars.indexOf(theChar);
				
				if (i == -1)
				{
					charsNotInFont.push(theChar);
				}
			}
		);
		
		File.saveContent("out.txt", fontChars.join(""));
		File.saveContent("not_in_text.txt", charsNotInText.join(""));
		File.saveContent("not_in_font.txt", charsNotInFont.join(""));
	}
}
