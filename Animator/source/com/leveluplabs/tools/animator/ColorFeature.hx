package com.leveluplabs.tools.animator;
import flixel.addons.ui.SwatchData;
import flixel.interfaces.IFlxDestroyable;
/**
 * ...
 * @author Lars A. Doucet
 */class ColorFeature implements IFlxDestroyable {

	public var name : String;				//name of the feature - "skin", "pants"
	
	//corresponding palette indeces in sprite
	public var hilight(get,set):Int;				//-1 means "ignore this index"
	public var midtone(get,set):Int;
	public var shadowMid(get,set):Int;
	public var shadowDark(get,set):Int;
	
	public function get_hilight():Int {
		if (colors.length >= 1) {
			return colors[0];
		}
		return -1;
	}
	public function set_hilight(Value:Int):Int {
		colors[0] = Value;
		return Value;
	}
	
	public function get_midtone():Int {
		if (colors.length >= 2) {
			return colors[1];
		}
		return -1;
	}
	public function set_midtone(Value:Int):Int {
		colors[1] = Value;
		return Value;
	}
	
	public function get_shadowMid():Int {
		if (colors.length >= 3) {
			return colors[2];
		}
		return -1;
	}
	public function set_shadowMid(Value:Int):Int {
		colors[2] = Value;
		return Value;
	}
	
	public function get_shadowDark():Int {
		if (colors.length >= 4) {
			return colors[3];
		}
		return -1;
	}
	public function set_shadowDark(Value:Int):Int {
		colors[3] = Value;
		return Value;
	}
	
	public var colors:Array<Int>;
	
	public var swatch : SwatchData;			//currently selected color swatch
	public var palette : ColorPalette;		//palette of possible swatches
	
	public var palette_name:String;			//palette name (for lookup purposes)
	
	public function new(Name:String, ?Colors:Array<Int>, ?Palette_name:String, ?Pallete:ColorPalette, ?Swatch:SwatchData) 
	{
		if (Colors == null) {
			colors = [];
		}else {
			colors = Colors;
		}
		name = Name;
		swatch = Swatch;
		palette_name = Palette_name;
		if (Pallete != null)
		{
			palette = Pallete;
		}
	}

	public function destroy() : Void {
		swatch = null;
		if (palette != null)
		{
			palette.destroy();
		}
		palette = null;
	}

	public function copy() : ColorFeature 
	{
		var cs : SwatchData = null;
		if (swatch != null)
		{
			cs = swatch.copy();
		}
		var pal : ColorPalette = null;
		if (palette != null)
		{
			pal = palette.copy();
		}
		return new ColorFeature(name, colors.copy(), palette_name, pal, cs);
	}

	public function toString() : String 
	{
		var str : String = "\nCF(" + name + ":" + hilight + "," + midtone + "," + shadowMid + "," + shadowDark +") ";
		str += "palette=\n..." + palette;
		return str;
	}

}

