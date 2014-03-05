package com.leveluplabs.tools.animator;

import flash.geom.Rectangle;
import flixel.addons.ui.FlxSlider;
import flixel.addons.ui.FlxUI;
import flixel.addons.ui.FlxUIButton;
import flixel.addons.ui.FlxUIColorSwatch;
import flixel.addons.ui.FlxUIColorSwatchSelecter;
import flixel.addons.ui.FlxUIDropDownMenu;
import flixel.addons.ui.FlxUIGroup;
import flixel.addons.ui.FlxUIPopup;
import flixel.addons.ui.FlxUIText;
import flixel.addons.ui.FlxUITypedButton.FlxUITypedButton;
import flixel.addons.ui.SwatchData;
import flixel.addons.ui.U;
import flixel.FlxSprite;
import flixel.util.FlxColor;
import flixel.util.FlxColorUtil;
import flixel.util.FlxColorUtil.ARGB;
import flixel.util.FlxColorUtil.HSV;
import sys.FileSystem;
import systools.Dialogs;

/**
 * ...
 * @author 
 */
class Popup_EditColorIndex extends FlxUIPopup
{
	private var colorIndex:ColorIndex;
	private var currSwatch:FlxUIColorSwatch;
	
	private var slider_r:FlxSlider;
	private var slider_g:FlxSlider;
	private var slider_b:FlxSlider;
	
	private var slider_h:FlxSlider;
	private var slider_s:FlxSlider;
	private var slider_br:FlxSlider;
	
	private var list_data:Array<SwatchData>;
	
	private var dd_swatch_component:FlxUIDropDownMenu;
	
	private var colorBlank:FlxSprite;
	
	private var btn_save:FlxUIButton;
	
	public var rgb:ARGB;
	public var hsb:HSBA;
	
	private var swatch_selecter:FlxUIColorSwatchSelecter;
	
	public function new(ci:ColorIndex):Void {
		colorIndex = ci;
		super();
	}
	
	public override function destroy():Void {
		colorIndex = null;
		currSwatch = null;
		slider_r = null;
		slider_g = null;
		slider_b = null;
		slider_h = null;
		slider_s = null;
		slider_br = null;
		U.clearArray(list_data);
		list_data = null;
		dd_swatch_component = null;
		colorBlank = null;
		btn_save = null;
		rgb = null;
		hsb = null;
		swatch_selecter = null;
		super.destroy();
	}
	
	public override function create():Void {
		_xml_id = "popup_color_index";
		super.create();
		setup();
	}
	
	private function setup():Void {
		
		id = "confirm_color_index_change";
		
		var back = _ui.getAsset("back");
		
		var maxColumns:Int = Std.int( ((back.width / 2) - 8) / (16 + 2) );
		
		list_data = colorIndex.getSwatchList();
		
		swatch_selecter = new FlxUIColorSwatchSelecter(back.x + 4, back.y + 20, list_data,2,2,maxColumns);
		add(swatch_selecter);
		
		var lcs:FlxUIText = cast _ui.getAsset("label_current_swatch");
		currSwatch = new FlxUIColorSwatch(lcs.x, lcs.y + lcs.height + 2, list_data[0],null,64,64);
		add(currSwatch);
		
		btn_save = new FlxUIButton(currSwatch.x + currSwatch.width + 5, currSwatch.y,"Update");
		btn_save.resize(100, currSwatch.height);
		add(btn_save);
		
		dd_swatch_component = cast _ui.getAsset("dd_swatch_component");
		
		var sx:Float = dd_swatch_component.header.x + 50;
		var sy:Float = dd_swatch_component.header.y + dd_swatch_component.header.height + 14;
		
		rgb = { alpha:1.0, red:0, green:0, blue:0 };
		hsb = { alpha:1.0, hue:0, saturation:0, brightness:0};
		
		colorBlank = new FlxSprite(0,0);
		colorBlank.makeGraphic(32, 32, FlxColor.BLACK, false, "colorBlank");
		colorBlank.pixels.fillRect(new Rectangle(1, 1, 30, 30), FlxColor.WHITE);
		
		var cbx:Float = dd_swatch_component.x + dd_swatch_component.width + 5;
		var cby:Float = dd_swatch_component.y + (dd_swatch_component.header.height - colorBlank.height) / 2;
		
		colorBlank.x = cbx;
		colorBlank.y = cby;
		
		slider_r = new FlxSlider(rgb, "red"  , sx, sy     , 0, 255, 100, 15, 3, 0xFFFF0000, 0xFFFFFFFF);
		slider_g = new FlxSlider(rgb, "green", sx, sy + 50, 0, 255, 100, 15, 3, 0xFF00FF00, 0xFFFFFFFF);
		slider_b = new FlxSlider(rgb, "blue" , sx, sy +100, 0, 255, 100, 15, 3, 0xFF0000FF, 0xFFFFFFFF);
		
		sx += 130;
		
		slider_h = new FlxSlider(hsb,  "hue"       , sx,  sy     , 0.0, 359, 100, 15, 3, 0xFFFFFF00, 0xFFFFFFFF);
		slider_s = new FlxSlider(hsb,  "saturation", sx,  sy + 50, 0.0, 1.0, 100, 15, 3, 0xFFC0C0C0, 0xFFFFFFFF);
		slider_br = new FlxSlider(hsb, "brightness", sx,  sy +100, 0.0, 1.0, 100, 15, 3, 0xFF000000, 0xFFFFFFFF);
		
		slider_r.callback = onSliderR;
		slider_g.callback = onSliderG;
		slider_b.callback = onSliderB;
		
		slider_h.callback = onSliderH;
		slider_s.callback = onSliderS;
		slider_br.callback = onSliderBR;
		
		var ug:FlxUIGroup = _ui.getGroup("under");
		
		ug.add(colorBlank);
		
		ug.add(slider_r);
		ug.add(slider_g);
		ug.add(slider_b);
		
		ug.add(slider_h);
		ug.add(slider_s);
		ug.add(slider_br);
		
		onDropDown(0);
	}
	
	private function onSliderR(f:Float):Void { onSliderRGB(); };
	private function onSliderG(f:Float):Void { onSliderRGB(); };
	private function onSliderB(f:Float):Void { onSliderRGB(); };
	private function onSliderH(f:Float):Void { onSliderHSB(); };
	private function onSliderS(f:Float):Void { onSliderHSB(); };
	private function onSliderBR(f:Float):Void { onSliderHSB(); };
	
	private function onSliderRGB():Void {
		var red:Int = Std.int(rgb.red);
		var green:Int = Std.int(rgb.green);
		var blue:Int = Std.int(rgb.blue);
		var the_color:Int = FlxColorUtil.getColor32(255, red, green, blue);
		var the_hsb = FlxColorUtil.getHSBA(the_color);
		
		hsb.hue = the_hsb.hue;
		hsb.saturation = the_hsb.saturation;
		hsb.brightness = the_hsb.brightness;
		onSlider();
	}
	
	private function onSliderHSB():Void {
		var the_color:Int = FlxColorUtil.makeFromHSBA(hsb.hue, hsb.saturation, hsb.brightness, 1.0);
		var the_rgb = FlxColorUtil.getARGB(the_color);
		rgb.red = the_rgb.red;
		rgb.green = the_rgb.green;
		rgb.blue = the_rgb.blue;
		onSlider();
	}
	
	private function onSlider():Void {
		var str:String = dd_swatch_component.selectedId;
		var curr_swatchIndex:Int = Std.parseInt(str);
		
		var rgbcol:Int = FlxColorUtil.getColor32(255,Std.int(rgb.red), Std.int(rgb.green), Std.int(rgb.blue));
		
		colorBlank.color = rgbcol;
		currSwatch.set_colorAtIndex(rgbcol, curr_swatchIndex);
		
		btn_save.label.text = "Update*";
		btn_save.label.color = 0xFF0000;
	}
	
	private function updateSwatch():Void {
		btn_save.label.text = "Update";
		btn_save.label.color = 0x000000;
		var s:FlxUIColorSwatch = swatch_selecter.selectedSwatch;
		if (s != null) {
			s.colors = currSwatch.colors;
		}
	}
	
	private function onDropDown(id:Int):Void {
		var the_color:Int = currSwatch.colors.get_color(id);
		
		var the_rgb = FlxColorUtil.getARGB(the_color);
		rgb.red = the_rgb.red;
		rgb.green = the_rgb.green;
		rgb.blue = the_rgb.blue;
		
		var the_hsb = FlxColorUtil.getHSBA(the_color);
		hsb.hue = the_hsb.hue;
		hsb.saturation = the_hsb.saturation;
		hsb.brightness = the_hsb.brightness;
		
		colorBlank.color = the_color;
	}
	
	private function onSwatchClick(sd:SwatchData):Void {
		refreshSwatch(sd);
		btn_save.label.text = "Update";
		btn_save.label.color = 0x000000;
		onDropDown(1);
		dd_swatch_component.selectedId = "1";
	}
	
	private function refreshSwatch(sd:SwatchData):Void {
		currSwatch.colors = sd;
		var input_swatch_name:FlxUIText = cast _ui.getAsset("input_swatch_name");
		
		input_swatch_name.text = sd.name;
		dd_swatch_component.selectedId = "1";	//midtone
	}
	
	public override function getEvent(id:String, sender:Dynamic, data:Array<Dynamic>, ?params:Array<Dynamic>):Void {
		switch(id) {
			case FlxUIDropDownMenu.CLICK_EVENT:
				var id:Int = Std.parseInt(cast data);
				onDropDown(id);
			case FlxUIColorSwatchSelecter.CLICK_EVENT:
				var swatchData:SwatchData = cast data;
				onSwatchClick(swatchData);
			case FlxUITypedButton.CLICK_EVENT:
				if (sender == btn_save) {
					updateSwatch();
				}else if(params != null){
					var param0:String = Std.string(params[0]);
					if (param0 == "cancel") {
						close();
					}else if (param0 == "accept") {
						updateColorIndex();
						castParent().getEvent("popup_color_index_change", this, null);
						close();
					}
				}
		}
	}
	
	private function updateColorIndex():Void {
		var list_swatch_data:Array<SwatchData> = [];
		for (sprite in swatch_selecter.members) {
			if (Std.is(sprite, FlxUIColorSwatch)) {
				var fuics:FlxUIColorSwatch = cast sprite;
				list_swatch_data.push(fuics.colors);
			}
		}
		colorIndex.updateFromSwatches(list_swatch_data, true);
		U.clearArraySoft(list_swatch_data);
		list_swatch_data = null;
	}
}
