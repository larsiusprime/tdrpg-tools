package com.leveluplabs.tools.animator;
import flash.display.BitmapData;
import flash.geom.Rectangle;
import flixel.addons.ui.FlxUI;
import flixel.addons.ui.FlxUI9SliceSprite;
import flixel.addons.ui.FlxUIAssets;
import flixel.addons.ui.FlxUIButton;
import flixel.addons.ui.FlxUIDropDownMenu;
import flixel.addons.ui.FlxUIGroup;
import flixel.addons.ui.FlxUIInputText;
import flixel.addons.ui.FlxUINumericStepper;
import flixel.addons.ui.FlxUIText;
import flixel.addons.ui.StrIdLabel;
import flixel.addons.ui.U;
import flixel.FlxSprite;
import flixel.text.FlxText;
import flixel.util.FlxColorUtil;

/**
 * Simple group wrapper around 3 widgets
 * @author 
 */
class ColorFeatureThingy extends FlxUIGroup
{
	public var dd_sprite:FlxUIDropDownMenu;
	public var dd_swatch:FlxUIDropDownMenu;
	public var button:FlxUIButton;
	public var headersExist(default, null):Bool;
	
	public function new(X:Float,Y:Float,spriteData:Array<StrIdLabel>,swatchData:Array<StrIdLabel>,?hasHeaders:Bool=false) 
	{
		headersExist = hasHeaders;
		super(X, Y);
		var dd_sprite_bkg:FlxSprite = new FlxUI9SliceSprite(0, 0, FlxUIAssets.IMG_BOX, new Rectangle(0, 0, 120, 20), [1, 1, 14, 14]);
		var pixels:BitmapData = dd_sprite_bkg.pixels.clone();
		
		var dd_sprite_bkg2 = new FlxSprite(0, 0, pixels);
		dd_sprite_bkg.destroy();
		pixels = null;
		
		var dd_sprite_header:FlxUIDropDownHeader = new FlxUIDropDownHeader(120, dd_sprite_bkg2);
		dd_sprite = new FlxUIDropDownMenu(0, 0, spriteData, onSprite, dd_sprite_header);
		dd_sprite.broadcastToFlxUI = false;
		add(dd_sprite);
		
		var colorString:String;
		var colorInt:Int;
		var colorIcon:FlxSprite;
		var btn:FlxUIButton;
		for (btn in dd_sprite.list) {
			colorString = btn.label.text;
			colorInt = U.parseHex(colorString, false, true, 0xFFFFFF);
			colorIcon = new FlxSprite();
			colorIcon.makeGraphic(Std.int(btn.label.height - 2), Std.int(btn.label.height - 2), 0xFF000000, true, "pixColor_"+colorString);
			colorIcon.pixels.fillRect(new Rectangle(1, 1, colorIcon.width - 2, colorIcon.height - 2), colorInt);
			btn.autoCenterLabel();
			btn.addIcon(colorIcon, 1, 1, false);
			for (fxpoint in btn.labelOffsets) {
				fxpoint.x = colorIcon.width + 2;
			}
		}
		
		colorString = dd_sprite.header.text.text;
		colorInt = U.parseHex(colorString, false, true, 0xFFFFFF);
		colorIcon = new FlxSprite();
		colorIcon.loadGraphic("pixColor_" + colorString);
		dd_sprite.header.background.stamp(colorIcon, 2, 4);
		dd_sprite.header.text.x = colorIcon.width + 2;
		
		dd_swatch = new FlxUIDropDownMenu(0, 0, swatchData);
		dd_swatch.x = dd_sprite.x + dd_sprite.width + 2;
		dd_swatch.broadcastToFlxUI = false;
		add(dd_swatch);
		
		button = new FlxUIButton(0, 0, "Delete", onClick);
		button.x = dd_swatch.x + dd_swatch.width + 2;
		button.resize(button.width, dd_swatch.header.height);
		button.broadcastToFlxUI = false;
		add(button);
		
		if (hasHeaders) {
			var label:FlxUIText = new FlxUIText(0, 0, Std.int(dd_sprite.width), "Palette Color");
			label.setBorderStyle(FlxText.BORDER_OUTLINE_FAST, 0);
			add(label);
			
			label.x = dd_sprite.x;
			label.y = dd_sprite.y;
			
			dd_sprite.y += label.height + 2;
			
			label = new FlxUIText(0,0,Std.int(dd_swatch.width),"Swatch Index");
			label.setBorderStyle(FlxText.BORDER_OUTLINE_FAST, 0);
			add(label);
			
			label.x = dd_swatch.x;
			label.y = dd_swatch.y;
			dd_swatch.y += label.height + 2;
			
			button.y += label.height + 2;
		}
	}
	
	public function selectSprite(id:String):Void {
		dd_sprite.selectedId = id;
		onSprite(id);
	}
	
	public function selectSwatch(id:String):Void {
		dd_swatch.selectedId = id;
	}
	
	private function onSprite(id:String):Void {
		var colorString:String = dd_sprite.header.text.text;
		var colorInt = U.parseHex(colorString, false, true, 0xFFFFFF);
		var colorIcon = new FlxSprite();
		colorIcon.loadGraphic("pixColor_" + colorString);
		dd_sprite.header.background.stamp(colorIcon, 2, 4);
	}
	
	private function onClick():Void {
		FlxUI.event("color_feature_click_delete", this, id);
	}
	
}