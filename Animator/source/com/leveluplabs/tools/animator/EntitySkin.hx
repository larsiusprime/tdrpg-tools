package com.leveluplabs.tools.animator;
import com.leveluplabs.tools.animator.EntityGraphics.EntityColorLayer;
import flixel.addons.ui.SwatchData;
import flixel.addons.ui.U;
import flixel.interfaces.IFlxDestroyable;
import flixel.util.FlxColorUtil;
import haxe.xml.Fast;

/**
 * ...
 * @author 
 */
class EntitySkin implements IFlxDestroyable
{

	public var name:String;						//identifier
	public var path:String;						//path to asset within assets/gfx/ folder
	public var width:Int;						//width of frame
	public var height:Int;						//height of frame
	public var off_x:Int;						//x offset
	public var off_y:Int;						//y offset
	public var asset_src:String;				//filename sans extension
	public var isDefault:Bool;					//is this the default skin
	public var color_change_mode:Int;			//color change method: COLOR_CHANGE_NONE, COLOR_CHANGE_LAYERS, COLOR_CHANGE_PIXELS
	public var list_colors:Array<Int>;			//color change rules, in correct sorting order (optional: works with PIXELS and LAYERS )
	public var list_original_pixel_colors:Array<Int>;						//original pixels for color change (optional: COLOR_CHANGE_PIXELS mode only)
	public var list_color_layers:Array<EntityGraphics.EntityColorLayer>;	//layer structure for color change (optional: COLOR_CHANGE_LAYERS mode only)
	public var list_color_features:Array<ColorFeature>;						//palette structue for color change
	public var using_default_structure:Bool=false;							//whether we loaded our color structure from the default layout
	
	public function new() 
	{
	}
	
	public function destroy():Void {
		//todo
	}
	
	public function removeColorFeature(name:String):Void {
		if (list_color_features != null)
		{
			var match:ColorFeature = null;
			var i:Int = 0;
			for (cf in list_color_features)
			{
				if (cf.name == name)
				{
					match = cf;
					break;
				}
				i++;
			}
			
			if (match != null) {
				trace("could not find (" + name + ") in list " + list_color_features);
				list_color_features.splice(i, 1);
				match.destroy();
			}else {
				trace("removed(" + name + ") list = " + list_color_features);
			}
		}
	}
	
	public function getSwatchFromColorFeature(name:String):SwatchData {
		trace("getSwatchFromColorFeature(" + name + ")");
		if (list_color_features != null)
		{
			var match:ColorFeature = null;
			for (cf in list_color_features)
			{
				trace("cf.name = " + cf.name + " VS " + name);
				if (cf.name == name)
				{
					match = cf;
					break;
				}
			}
			
			if (match != null) 
			{
				var swatch:SwatchData = new SwatchData("");
				trace("swatch.colors = " + swatch.colors);
				if(swatch.colors != null){
					for (i in 0...swatch.colors.length) {
						var indexInListColors:Int = -1;
						if (i < match.colors.length) {
							indexInListColors = match.colors[i];
						}
						if(indexInListColors >= 0 && indexInListColors < list_colors.length){
							swatch.colors[i] = list_colors[match.colors[i]];
						}
					}
				}
				return swatch;
			}
		}
		return null;
	}
	
	public function addColorFeature(cf:ColorFeature):Void {
		if (list_color_features == null)
		{
			list_color_features = [];
		}	
		list_color_features.push(cf);
	}
	
	public function changeColorFeaturePalette(name:String, cp:ColorPalette, ?newName:String=""):Void {
		if (list_color_features != null)
		{
			var match:ColorFeature = null;
			for (cf in list_color_features)
			{
				if (cf.name == name)
				{
					match = cf;
					break;
				}
			}
			
			if (match != null)
			{
				if (match.palette != null) {
					match.palette.destroy();
					match.palette = null;
				}
				match.palette = cp;
				match.palette_name = cp.name;
				if (newName != "") {
					match.name = newName;
				}
			}
		}
	}
	
	public function replaceColorFeature(name:String, cf:ColorFeature):Void {
		if (list_color_features != null)
		{
			var match:ColorFeature = null;
			var i:Int = 0;
			for (cf in list_color_features)
			{
				if (cf.name == name)
				{
					match = cf;
					break;
				}
				i++;
			}
			
			if (match != null) 
			{
				match.destroy();
				list_color_features[i] = cf.copy();
			}
		}
	}
	
	public function changeColorFeature(name:String, data:SwatchData):Void
	{
		trace("changeColorFeature(" + name + "," + data + ")");
		if (list_color_features != null)
		{
			var match:ColorFeature = null;
			for (cf in list_color_features)
			{
				if (cf.name == name)
				{
					match = cf;
					break;
				}
			}
			
			if (match != null) 
			{
				if (list_colors == null) {
					list_colors = [];
				}
				
				var i:Int = 0;
				for (cIndex in match.colors) {
					if (cIndex >= 0) {
						list_colors[cIndex] = data.colors[i];
					}
					i++;
				}
				
				#if neko
					for (i in 0...list_colors.length) {
						if (list_colors[i] == null) {
							list_colors[i] = 0;
						}
					}
				#end 
			}
		}
	}
	
	public function colorString():String {
		var str:String = "";
		var i:Int = 0;
		for (color in list_colors) {
			str += ("0x" + StringTools.hex(color, 6));
			if (i <= list_colors.length - 1) {
				str += ",";
			}
			i++;
		}
		return str;
	}
	
	public function copy():EntitySkin 
	{
		var copy = new EntitySkin();
		
		copy.name = name;
		copy.path = path;
		copy.width = width;
		copy.height = height;
		copy.off_x = off_x;
		copy.off_y = off_y;
		copy.asset_src = asset_src;
		copy.isDefault = isDefault;
		copy.color_change_mode = color_change_mode;
		copy.list_color_layers = null;
		copy.list_original_pixel_colors = U.copy_shallow_arr_i(list_original_pixel_colors);
		copy.list_colors = U.copy_shallow_arr_i(list_colors);
		copy.list_color_features = null;
		copy.using_default_structure = using_default_structure;
		
		if (list_color_features != null) {
			copy.list_color_features = [];
			for (cf in list_color_features) {
				copy.list_color_features.push(cf.copy());
			}
		}
		
		if (list_color_layers != null) {
			copy.list_color_layers = [];
			for (ecl in list_color_layers) {
				copy.list_color_layers.push(EntityGraphics.copyEntityColorLayer(ecl));
			}
		}
		
		return copy;
	}
	
	public function toXML():Fast{
		var xml:Xml = Xml.createElement("skin");
		xml.set("name", name);
		xml.set("default", Std.string(isDefault));
		xml.set("asset_src", asset_src);
		xml.set("path", path);
		xml.set("width", Std.string(width));
		xml.set("height", Std.string(height));
		xml.set("off_x", Std.string(off_x));
		xml.set("off_y", Std.string(off_y));
		if (color_change_mode != EntityGraphics.COLOR_CHANGE_NONE) {
			var colors:Xml = Xml.createElement("colors");
			if (color_change_mode == EntityGraphics.COLOR_CHANGE_LAYERS) {
				colors.set("mode", "layers");
			}else if(color_change_mode == EntityGraphics.COLOR_CHANGE_PIXEL_PALETTE) {
				colors.set("mode", "pixels");
			}
			
			if (using_default_structure) {
				colors.set("use_default", "true");
			}else {
				if (list_color_features != null) {
					var cf:ColorFeature;
					for (cf in list_color_features) {
						var featureXml:Xml = Xml.createElement("feature");
						featureXml.set("name", cf.name);
						if (cf.palette != null) {
							featureXml.set("palette", cf.palette.name);	//palette DOT name (if we have object, read name from object)
						}else {
							featureXml.set("palette", cf.palette_name); //"palette_name" variable
						}
						
						var ci:Int = 0;
						for (colorInt in cf.colors) {
							featureXml.set("c" + ci, Std.string(colorInt));
							ci++;
						}
						colors.addChild(featureXml);
					}
				}
				if (list_color_layers != null) {
					var ecl:EntityColorLayer;
					for (ecl in list_color_layers) {
						var layerXml:Xml = Xml.createElement("layer");
						layerXml.set("name", ecl.name);
						layerXml.set("asset_src", ecl.asset_src);
						if(ecl.alpha < 1){
							layerXml.set("alpha", Std.string(ecl.alpha));
						}
						layerXml.set("sort", Std.string(ecl.sort));
						colors.addChild(layerXml);
					}
				}
			}
			
			if (list_colors != null) {
				for (i in 0...list_colors.length) {
					var colorXml:Xml = Xml.createElement("color");
					var colorHex:String = hexColor(list_colors[i]);
					colorXml.set("value", colorHex);
					colorXml.set("index", Std.string(i));
					colors.addChild(colorXml);
				}
			}
			xml.addChild(colors);
		}
		return new Fast(xml);
	}
	
	private inline function hexColor(col:Int):String {
		return "0x" + StringTools.hex(col, 6);
	}
}