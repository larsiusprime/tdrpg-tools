package ;
import flixel.addons.ui.U;
import haxe.xml.Fast;
import haxe.xml.Printer;

/**
 * ...
 * @author larsiusprime
 */
class ModFix
{

	public static inline var EFFECT_SCALE:Float = 3.0;
	
	public function new() 
	{
		
	}
	
	/**
	 * Remaps TDRPG-as3 "data_effects.xml" --> TDRPG-haxe "effects/effects.xml"
	 * @param	input
	 * @return
	 */
	
	public static function data_effects_effects(input:Fast):String
	{
		var output:String = "";
		
		var outXml:Xml = Xml.parse("");
		
		var first = true;
		
		if (input.hasNode.data_effects)
		{
			if (input.node.data_effects.hasNode.effect)
			{
				for (effNode in input.node.data_effects.nodes.effect)
				{
					var name:String = U.xml_str(effNode.x, "name");
					var graphic:String = name;
					
					if (effNode.hasNode.graphic)
					{
						graphic = U.xml_str(effNode.node.graphic.x, "id");
					}
					
					var colors:String = "";
					
					if (effNode.hasNode.color)
					{
						for (colNode in effNode.nodes.color)
						{
							var col:String = U.xml_str(colNode.x, "value");
							colors += col + ",";
						}
						if (colors.length > 0)
						{
							colors = colors.substr(0, colors.length - 1);
						}
					}
					
					var tag:String = '\t<effect name="' + name+'" graphic="' + graphic + '"';
					if (colors != "")
					{
						tag += ' colors="' + colors + '"';
					}
					tag += " />";
					
					if (first)
					{
						output += tag;
						first = false;
					}
					else
					{
						output += "\n" + tag;
					}
				}
			}
		}
		
		/*
		output = Printer.print(outXml);// outXml.toString();
		
		var fix_in = 
		[
			"\n<effect"
		];
		
		var fix_out = 
		[
			"\n\t<effect"
		];
		
		for (i in 0...fix_in.length)
		{
			while (output.indexOf(fix_in[i]) != -1)
			{
				output = StringTools.replace(output, fix_in[i], fix_out[i]);
			}
		}
		*/
		
		return xmlWrap(output);
	}
	
	/**
	 * Remaps TDRPG-as3 "data_effects.xml" --> TDRPG-haxe "effects/graphics.xml"
	 * @param	input
	 * @return
	 */
	
	public static function data_effects_gfx(input:Fast):String
	{
		var output:String = "";
		
		var outXml:Xml = Xml.parse("");
		var outFast:Fast = new Fast(outXml);
		
		if (input.hasNode.data_effects)
		{
			if (input.node.data_effects.hasNode.effect)
			{
				for (effNode in input.node.data_effects.nodes.effect)
				{
					var name:String = U.xml_str(effNode.x, "name");
					var graphic:String = name;
					var width:Int = 1;
					var height:Int = 1;
					var off_x:Int = 0;
					var off_y:Int = 0;
					
					if (effNode.hasNode.graphic)
					{
						graphic = U.xml_str(effNode.node.graphic.x, "id");
						width = U.xml_i(effNode.node.graphic.x, "width");
						height = U.xml_i(effNode.node.graphic.x, "height");
						off_x = U.xml_i(effNode.node.graphic.x, "off_x");
						off_y = U.xml_i(effNode.node.graphic.x, "off_y");
					}
					
					var copyString = effNode.x.toString();
					
					//Replace the "graphic" node with an "original" node signifiying original-graphic (sprite) information
					copyString = StringTools.replace(copyString, '<graphic','<original');
					copyString = StringTools.replace(copyString, 'id="' + graphic + '"', '');
					
					//Rename the "effect" node itself to "graphic"
					copyString = StringTools.replace(copyString, "<effect", "<graphic");
					copyString = StringTools.replace(copyString, "effect>", "graphic>");
					
					//Remove off_x/off_y if they are 0
					if (off_x == 0 || off_y == 0)
					{
						copyString = StringTools.replace(copyString, 'off_x="0"', "");
						copyString = StringTools.replace(copyString, 'off_y="0"', "");
					}
					
					//Copy the node
					var copyNode:Xml = Xml.parse(copyString).firstElement();
					
					var copyFast:Fast = new Fast(copyNode);
					while(copyFast.hasNode.color)
					{
						copyFast.x.removeChild(copyFast.node.color.x);
					}
					
					if (copyFast.node.original.has.in_demo)
					{
						copyFast.node.original.x.remove("in_demo");
					}
					
					if (copyFast.hasNode.anim)
					{
						for (animNode in copyFast.nodes.anim)
						{
							var animId:String = U.xml_str(animNode.x, "id");
							if (animId == "")
							{
								animNode.x.set("name", name);
							}
							else
							{
								animNode.x.set("name", animId);
								animNode.x.remove("id");
							}
						}
					}
					
					//Add an "hd" node with scaled up dimensions based on original
					var el = Xml.createElement("hd");
					
					el.set("width", Std.string(width * EFFECT_SCALE));
					el.set("height", Std.string(height * EFFECT_SCALE));
					
					if(off_x != 0)
					{
						el.set("off_x", Std.string(off_x * EFFECT_SCALE));
					}
					if (off_y != 0)
					{
						el.set("off_y", Std.string(off_y * EFFECT_SCALE));
					}
					
					copyNode.set("name", graphic);
					copyNode.insertChild(el, 2);
					
					//Check my animations against every other node so far
					var exists:Bool = false;
					for (ofgNode in outFast.nodes.graphic)
					{
						var graphicName:String = U.xml_str(ofgNode.x, "name");
						
						//If there's already something else using the same graphic
						if (graphicName == graphic)
						{
							exists = true;
							
							//Then instead of adding this to the list just copy my animations in there
							for (myAnimNode in copyFast.nodes.anim)
							{
								if (areAnimsDifferent(ofgNode, myAnimNode))
								{
									ofgNode.x.addChild(myAnimNode.x);
								}
							}
						}
					}
					
					if (!exists)
					{
						outXml.addChild(copyNode);
					}
				}
			}
		}
		
		for (graphicNode in outFast.nodes.graphic)
		{
			var i:Int = 0;
			for (animNode in graphicNode.nodes.anim)
			{
				i++;
			}
			
			if (i == 1)
			{
				graphicNode.node.anim.x.remove("name");
			}
		}
		
		output = outXml.toString();
		
		var fix_in = 
		[
			"\t\t\t\r\n",
			"\t\t\t\t\t\t\r\n",
			"\t\t\t\t\t\t\t\t\t\t\t\t<anim",
			"\t\t\t\t\t\t<anim",
			"anim><anim",
			"anim></graphic",
			"\t\t\t</anim>\r\n\t\t<anim",
			"</graphic><graphic",
			"/>\t\t\t\t\t<frame",
			"\t\t\t\t\t<frame",
			"\t\t\t\t\t\t<original",
			"/><hd"
		];
		
		var fix_out = 
		[
			"",
			"",
			"\t\t\t<anim",
			"\t\t\t<anim",
			"anim>\r\n\t\t\t<anim",
			"anim>\r\n\t\t</graphic",
			"\t\t\t</anim>\r\n\t\t\t<anim",
			"</graphic>\r\n\t\t<graphic",
			"/>\r\n\t\t\t\t<frame",
			"\t\t\t\t<frame",
			"\t\t\t<original",
			"/>\r\n\t\t\t<hd"
		];
		
		for (i in 0...fix_in.length)
		{
			while (output.indexOf(fix_in[i]) != -1)
			{
				output = StringTools.replace(output, fix_in[i], fix_out[i]);
			}
		}
		
		return xmlWrap(output);
	}
	
	/****/
	
	private static function areAnimsDifferent(masterNode:Fast, animNode:Fast):Bool
	{
		for (masterAnimNode in masterNode.nodes.anim)
		{
			var framerate:Int = U.xml_i(masterAnimNode.x, "framerate");
			var animFramefrate:Int = U.xml_i(animNode.x, "framerate");
			
			var masterFrameStr:String = "";
			var animFrameStr:String = "";
			for (mfFrame in masterAnimNode.nodes.frame)
			{
				masterFrameStr += U.xml_str(mfFrame.x, "value")+",";
			}
			for (afFrame in animNode.nodes.frame)
			{
				animFrameStr += U.xml_str(afFrame.x, "value")+",";
			}
			
			if (masterFrameStr == animFrameStr && framerate == animFramefrate)
			{
				return false;
			}
		}
		return true;
	}
	
	private static function xmlWrap(data:String):String
	{
		return 	'<?xml version="1.0" encoding="utf-8" ?>' + "\n" +
				'<data>' + "\n" + 
				    data + "\n" +
				'</data>';
	}
}