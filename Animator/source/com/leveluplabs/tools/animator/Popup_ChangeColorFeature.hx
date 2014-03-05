package com.leveluplabs.tools.animator;

import flixel.addons.ui.FlxUI;
import flixel.addons.ui.FlxUI9SliceSprite;
import flixel.addons.ui.FlxUIButton;
import flixel.addons.ui.FlxUIColorSwatchSelecter;
import flixel.addons.ui.FlxUIDropDownMenu;
import flixel.addons.ui.FlxUIGroup;
import flixel.addons.ui.FlxUIInputText;
import flixel.addons.ui.FlxUIPopup;
import flixel.addons.ui.FlxUIText;
import flixel.addons.ui.StrIdLabel;
import flixel.FlxSprite;
import flixel.util.FlxColor;
import flixel.util.FlxColorUtil;
import flixel.util.FlxStringUtil;
import haxe.macro.Compiler;
import sys.FileSystem;
import systools.Dialogs;

/**
 * ...
 * @author 
 */
class Popup_ChangeColorFeature extends FlxUIPopup
{
	private var color_index:ColorIndex;
	private var swatchSelecter:FlxUIColorSwatchSelecter;
	private var dropDown:FlxUIDropDownMenu;
	private var createMode:Bool = false;
	private var entity:EntityGraphics = null;
	private var paletteName:String = "";
	
	private var group_colorFeatures:FlxUIGroup;
	private var btn_add:FlxUIButton;
	
	private var swatchData:Array<StrIdLabel>;
	private var spriteData:Array<StrIdLabel>;
	
	private var input:FlxUIInputText;
	private var inputName:String = "";
	private var anchorY:Float = 0;
	
	public function new(PaletteName:String,Color_index:ColorIndex,?Create:Bool=false,?Entity:EntityGraphics=null,?InputName:String=""):Void {
		color_index = Color_index;
		paletteName = PaletteName;
		createMode = Create;
		inputName = InputName;
		entity = Entity;
		super();
	}
	
	public override function destroy():Void {
		entity = null;
		dropDown = null;
		color_index = null;
		swatchSelecter = null;
		super.destroy();
	}
	
	public override function create():Void {
		_xml_id = "popup_change_color_feature";
		
		super.create();
		
		var title:FlxUIText = cast _ui.getAsset("title");
		var body:FlxUIText = cast _ui.getAsset("body");
		
		title.text = "Change Color Feature";
		body.text = "Select a color palette:";
		if (createMode) {
			title.text = "Create NEW Color Feature";
		}
		
		var back:FlxSprite = cast _ui.getAsset("back");
		input = new FlxUIInputText(0, 0, 100, inputName);
		add(input);
		input.x = back.x+(back.width-input.width)/2;
		input.y = title.y + title.height + 2;
		input.text = inputName;
		
		var data_list = color_index.getPaletteList();
			
		if (paletteName == "") {
			paletteName = data_list[0].id;
		}
		var colorPalette:ColorPalette = color_index.getPalette(paletteName );
		
		if (colorPalette == null || colorPalette.list_colors == null) {
			trace("error loading color palette for feature : " + paletteName );
			close();
		}else {
			refreshSwatchSelecter(colorPalette);
			
			dropDown = new FlxUIDropDownMenu(0, 0, data_list);
			
			var back:FlxSprite = cast _ui.getAsset("back");
			dropDown.x = back.x + (back.width - dropDown.width) / 2;
			dropDown.y = swatchSelecter.y - 30;
			add(dropDown);
			
			dropDown.header.text.text = paletteName;
		}
		
		setupIndexStuff();
	}
	
	private function setupIndexStuff():Void {
		var back:FlxUI9SliceSprite = cast _ui.getAsset("back");
		back.resize(back.width, back.height * 2);
		var btn_cancel = _ui.getAsset("btn_cancel");
		var btn_select = _ui.getAsset("btn_select");
		btn_cancel.y = back.y + back.height - btn_cancel.height - 4;
		btn_select.y = back.y + back.height - btn_select.height - 4;
		
		group_colorFeatures = new FlxUIGroup();
		add(group_colorFeatures);
		
		var YY:Float = swatchSelecter.y + 25;
		
		swatchData = 
		[
			new StrIdLabel("0", "0 Hilight"),
			new StrIdLabel("1", "1 Midtone"),
			new StrIdLabel("2", "2 ShadowMid"),
			new StrIdLabel("3", "3 ShadowDark"),
			new StrIdLabel("4", "4 Other"),
			new StrIdLabel("5", "5 Other"),
			new StrIdLabel("6", "6 Other"),
			new StrIdLabel("7", "7 Other"),
			new StrIdLabel("8", "8 Other"),
			new StrIdLabel("9", "9 Other")
		];
		
		spriteData = [];
		if (entity != null) {
			entity.skin.list_original_pixel_colors;
			for (i in 0...entity.skin.list_original_pixel_colors.length) {
				var pix:Int = entity.skin.list_original_pixel_colors[i];
				spriteData.push(new StrIdLabel(Std.string(i), "0x" + StringTools.hex(pix, 6)));
			}
		}else {
			for (i in 0...16) {
				spriteData.push(new StrIdLabel(Std.string(i), Std.string(i)));
			}
		}
		
		var thing:ColorFeatureThingy=null;
		if(createMode){
			thing = new ColorFeatureThingy(0, YY, spriteData, swatchData, true);
			thing.x = back.x + (back.width - thing.width) / 2;
			thing.id = "0";
			thing.ID = 0;
			
			thing.button.visible = thing.button.active = false;
			group_colorFeatures.add(thing);
		
		}else {
			var match:ColorFeature = null;
			for (i in 0...entity.skin.list_color_features.length) {
				var cf = entity.skin.list_color_features[i];
				if (cf.name == inputName) {
					match = cf;
					break;
				}
			}
			if (match != null) {
				var count:Int = 0;
				for (i in 0...match.colors.length)
				{
					//if we have an entry for this index AND it's not set to an index of -1 (none)
					if (match.colors.length > i && match.colors[i] != -1) 
					{
						thing = new ColorFeatureThingy(0, YY, spriteData, swatchData, count == 0);
						thing.x = back.x + (back.width - thing.width) / 2;
						
						thing.id = Std.string(count);
						thing.ID = count;
						
						thing.button.visible = thing.button.active = (count != 0);
						
						//Which pixel in the palette are we editing
						thing.selectSprite(Std.string(match.colors[i]));
						
						//Which part of the swatch are we looking at (hilight, midtone, shadow, etc)
						thing.selectSwatch(Std.string(i));
						
						group_colorFeatures.add(thing);
						count++;
					}
				}
			}
		}
		
		btn_add = new FlxUIButton(0, 0, "Add...", onClickAdd);
		btn_add.x = thing.x;
		btn_add.y = thing.y + 40;
		btn_add.resize(btn_add.width, btn_add.height);
		
		
		add(btn_add);
		
		remove(group_colorFeatures, true);
		add(group_colorFeatures);
		
		anchorY = thing.y;
		
		remove(swatchSelecter, true);
		add(swatchSelecter);
		
		remove(dropDown, true);
		add(dropDown);
		
		updateSpacing();
	}
	
	private function onClickAdd():Void {
		var thing:ColorFeatureThingy = new ColorFeatureThingy(0, 0, spriteData, swatchData);
		thing.ID = group_colorFeatures.members.length;
		var otherThing:ColorFeatureThingy = cast group_colorFeatures.members[group_colorFeatures.members.length - 1];
		group_colorFeatures.add(thing);
		group_colorFeatures.members.sort(sortOnY);
		updateSpacing();
	}
	
	private function updateSpacing():Void {
		group_colorFeatures.members.sort(sortOnId);
		var yy:Float = group_colorFeatures.members[0].y;
		var xx:Float = group_colorFeatures.members[0].x;
		for (i in 0...group_colorFeatures.members.length) {
			var thing:ColorFeatureThingy = cast group_colorFeatures.members[i];
			thing.x = xx;
			thing.y = yy;
			yy += 30;
			if (thing.headersExist) {
				yy += 18;
			}
		}
		btn_add.y = yy;
		group_colorFeatures.members.sort(sortOnY);
	}
	
	
	private function sortOnId(a:FlxSprite, b:FlxSprite):Int {
		if (a.ID < b.ID) return -1;
		if (a.ID > b.ID) return 1;
		return 0;
	}
	
	private function sortOnY(a:FlxSprite, b:FlxSprite):Int {
		if (a.y < b.y) return 1;
		if (a.y > b.y) return -1;
		return 0;
	}
	
	
	private function deleteColorFeature(id:String):Void {
		var thing:ColorFeatureThingy;
		for (sprite in group_colorFeatures.members) {
			thing = cast sprite;
			if (thing.id == id) {
				group_colorFeatures.remove(thing, true);
				thing.destroy();
				thing = null;
				break;
			}
		}
		group_colorFeatures.members.sort(sortOnY);
		updateSpacing();
	}
	
	private function refreshSwatchSelecter(colorPalette:ColorPalette):Void {
		if (swatchSelecter != null) {
			remove(swatchSelecter, true);
			swatchSelecter.destroy();
			swatchSelecter = null;
		}
		
		var back:FlxSprite = cast _ui.getAsset("back");
		swatchSelecter = new FlxUIColorSwatchSelecter(0, 0, colorPalette.list_colors);
		swatchSelecter.unselect();
		swatchSelecter.x = back.x + (back.width - swatchSelecter.width) / 2;
		var body:FlxUIText = cast _ui.getAsset("body");
		swatchSelecter.y = body.y + body.height + 35;
		
		swatchSelecter.active = false;
		add(swatchSelecter);
		
		if (dropDown != null) {
			remove(dropDown, true);
			add(dropDown);
		}
	}
	
	private function getColorFeatureList():Array<Int> {
		var color_list:Array<Int> = [];
		group_colorFeatures.members.sort(sortOnId);
		var thing:ColorFeatureThingy;
		for (sprite in group_colorFeatures.members) {
			thing = cast sprite;
			var pixelIndex:Int = Std.parseInt(thing.dd_sprite.selectedId);
			var swatchIndex:Int = Std.parseInt(thing.dd_swatch.selectedId);
			if(swatchIndex != -1){
				color_list[swatchIndex] = pixelIndex;
			}
			//color_list[0] = 12 --> means "hilight of this swatch replaces --> original_pixels[12]"
			//color_list[1] = 4  --> means "midtone of this swatch replaces --> original_pixels[4]"
			//etc
		}
		return color_list;
	}
	
	public override function getEvent(id:String, sender:Dynamic, data:Array<Dynamic>, ?params:Array<Dynamic>):Void {
		switch(id) {
			case "color_feature_click_delete":
				deleteColorFeature(cast data);
			case "click_button":
				if(params != null){
					var param0:String = Std.string(params[0]);
					if (param0 == "cancel") {
						close();
					}else if (param0 == "select") {
						if (createMode) {
							var colorFeature = new ColorFeature(input.text, getColorFeatureList(), paletteName);
							castParent().getEvent("popup_create_color_feature", this, colorFeature);
						}else {
							var colorFeature = new ColorFeature(input.text, getColorFeatureList(), paletteName);
							castParent().getEvent("popup_select_color_feature", this, colorFeature);
						}
						close();
					}
				}
			case FlxUIDropDownMenu.CLICK_EVENT:
				paletteName = cast data;
				var colorPalette:ColorPalette = color_index.getPalette(paletteName);
				refreshSwatchSelecter(colorPalette);
		}
	}
}