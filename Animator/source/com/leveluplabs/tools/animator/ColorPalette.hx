package com.leveluplabs.tools.animator;
import flixel.addons.ui.SwatchData;
import flixel.addons.ui.U;
import flixel.interfaces.IFlxDestroyable;

/**
 * ...
 * @author Lars A. Doucet
 */

 class ColorPalette implements IFlxDestroyable {

	public var name: String;
	public var list_colors : Array<SwatchData>;
	public function new(Name: String, list: Array<SwatchData>) 
	{
		name = Name;
		list_colors = list;
	}

	public function destroy() : Void 
	{
		U.clearArray(list_colors);
		list_colors = null;
	}

	public function copy() : ColorPalette 
	{
		var list : Array<SwatchData> = new Array<SwatchData>();
		for (cs in list_colors)
		{
			list.push(cs.copy());
		}

		return new ColorPalette(name, list);
	}

	public function toString() : String {
		return "Pallete(" + name + ")" + list_colors;
	}

}

