package com.leveluplabs.tools.animator;

import com.leveluplabs.tools.animator.EntityGraphics.EntityColorLayer;
import com.leveluplabs.tools.animator.EntitySkin;
import flash.display.Bitmap;
import flash.display.BitmapData;
import flash.display.BlendMode;
import flash.geom.ColorTransform;
import flash.Lib;
import flixel.addons.ui.FlxUIButton;
import flixel.addons.ui.FlxUINumericStepper;
import flixel.addons.ui.FlxUIState;
import flixel.addons.ui.FlxUITypedButton.FlxUITypedButton;
import flixel.addons.ui.interfaces.IFlxUIWidget;
import flixel.addons.ui.U;
import flixel.FlxG;
import flixel.FlxSprite;
import flixel.group.FlxGroup;
import flixel.text.FlxText;
import flixel.util.FlxColor;
import flixel.util.FlxRandom;
import openfl.Assets;

/**
 * ...
 * @author 
 */
class State_StressTest extends FlxUIState
{
	private var step_change:FlxUINumericStepper;
	private var step_colors:FlxUINumericStepper;
	private var btn_add:FlxUIButton;
	private var btn_remove:FlxUIButton;
	
	private var gfx:EntityGraphics;
	
	public static var offscreen:Bool = false;
	
	private var spriteGroup:FlxGroup;
	
	private var label_fps:FlxText;
	private var label_bunnies:FlxText;
	
	private var _times:Array<Float>;
	
	private var _list_colors:Array<Array<Int>>;
	
	private var _list_keys:Array<String>;
	
	private var _anim:String = "";
	
	override public function create():Void
	{
		FlxG.cameras.bgColor = 0xffaaaaaa;
		FlxG.log.redirectTraces = false; 
		
		if (Main.tongue == null) {
			Main.tongue = new FireTongueEx();
			Main.tongue.init("en-US");
			FlxUIState.static_tongue = Main.tongue;
		}
		
		spriteGroup = new FlxGroup();
		add(spriteGroup);
		
		_xml_id = "state_stress_test";
		
		super.create();
		
		step_change = cast _ui.getAsset("step_change");
		step_colors = cast _ui.getAsset("step_colors");
		btn_add = cast _ui.getAsset("btn_add");
		btn_remove = cast _ui.getAsset("btn_remove");
		
		if(Main.data.curr_gfx == null){
			gfx = new EntityGraphics();
			gfx.fromXML(U.xml("entities/defenders/glitch"));
		}else {
			gfx = Main.data.curr_gfx;
		}
		
		if (Main.data.curr_anim != "") {
			_anim = Main.data.curr_anim;
		}else {
			_anim = "default";
		}
		
		label_bunnies = new FlxText(0, 20, FlxG.width, "Sprites: " + step_change.value);
		label_bunnies.setFormat(null, 22, FlxColor.WHITE, "center", FlxText.BORDER_OUTLINE_FAST);
		label_bunnies.borderSize = 2;
		add(label_bunnies);
		
		label_fps = new FlxText(0, label_bunnies.y+label_bunnies.height+10, FlxG.width, "FPS: " + 30);
		label_fps.setFormat(null, 22, FlxColor.WHITE, "center",FlxText.BORDER_OUTLINE_FAST);
		label_fps.borderSize = 2;
		add(label_fps);
		
		addSprites(cast step_change.value);
		
		_times = [];
		
		_list_keys = [];
		
		changeColors();
	}
	
	public override function update():Void {
		super.update();
		
		var t = Lib.getTimer();
		
		var now:Float = t / 1000;
		_times.push(now);
		
		while (_times[0] < now - 1) {
			_times.shift();
		}
		
		label_fps.text = "FPS: " + _times.length + "/" + Lib.current.stage.frameRate;
	}
	
	public override function getEvent(event:String, sender:IFlxUIWidget, data:Dynamic, ?params:Dynamic):Void {
		switch(event) {
			case FlxUINumericStepper.CHANGE_EVENT:
				if (sender == step_colors) {
					changeColors();
				}
			case FlxUITypedButton.CLICK_EVENT:
				var str:String = "";
				if (params != null && params.length >= 1) {
					str = cast params[0];
					if (str == "animator") {
						FlxG.switchState(new State_Animator());
					}
				}
				
				if (sender == btn_add) {
					addSprites(cast step_change.value);
				}else if (sender == btn_remove) {
					removeSprites(cast step_change.value);
				}
		}
	}
	
	private function changeColors():Void {
		
		if (gfx.skin.color_change_mode == EntityGraphics.COLOR_CHANGE_NONE) 
		{
			return;
		}
		
		//Get number of colors from stepper
		var target_colors:Int = cast step_colors.value;
		var custom_colors:Int = 0;
		
		if (gfx.skin.color_change_mode == EntityGraphics.COLOR_CHANGE_LAYERS) 
		{
			if (gfx.skin.list_color_layers == null) { return; }
			custom_colors = gfx.skin.list_color_layers.length;
		}
		else if (gfx.skin.color_change_mode == EntityGraphics.COLOR_CHANGE_PIXEL_PALETTE) 
		{
			if (gfx.skin.list_original_pixel_colors== null){ return; }
			custom_colors = gfx.skin.list_original_pixel_colors.length;
		}
		
		if (_list_colors == null) 
		{
			_list_colors = [];
		}
		
		//Clear our old custom color cache
		for (key in _list_keys) {
			FlxG.bitmap.remove(key);
		}
		
		_list_keys = [];
		
		//Clear the old array
		while(_list_colors.length > 0){
			var temp = _list_colors.pop();
			while (temp.length > 0) {
				temp.pop();
			}
			temp = null;
		}
		
		var i:Int = 0;
		var c:Int = 0;
		var s:EntitySkin;
		
		//If we have more colors than skins
		if (target_colors > gfx.countSkins()) 
		{
			var diff:Int = target_colors - gfx.countSkins();
			
			var count:Int = 0;
			//Add some more skins
			for (i in 0...diff) {
				var s:EntitySkin = gfx.getDefaultSkin();
				var sCopy:EntitySkin = s.copy();
				sCopy.list_colors = null;
				
				sCopy.name = "random";
				while(gfx.map_skins.exists(sCopy.name)) {
					sCopy.name = "random_" + count;
					count++;
				}
				
				gfx.map_skins.set(sCopy.name, sCopy);
			}
		}
		
		//We have now guaranteed that we have enough skins for our lists of colors
		for (key in gfx.map_skins.keys()) 
		{
			s = gfx.map_skins.get(key);
			if (s.list_colors == null) 								//If there's no colors
			{
				var arr:Array<Int> = [];
				for (i in 0...custom_colors)						//Create a new color array at random
				{
					var new_color = FlxRandom.color(0, 255, 0);
					arr.push(new_color);
				}
				s.list_colors = arr;
			}
		}
		
		var counter:Int = 0;
		var counterRounds:Int = 0;
		
		var list_skins = gfx.getSkinNames();
		
		//Re-colorize sprites throughout
		for (s in 0...spriteGroup.length) 
		{
			var skinName:String = list_skins[counter];				//get a skin
			gfx.skinName = skinName;
			if (counterRounds == 0) {
				_list_keys.push(gfx.colorKey);						//store unique key the first time through so we can clear them later
			}
			
			var sprite:EntitySprite = cast spriteGroup.members[s];
			if (sprite != null && sprite.exists && sprite.alive) 
			{
				sprite.loadEntityGraphics(gfx);						//reload graphics
				sprite.animation.play(_anim);						//restart animation
			}
			
			counter++;
			if (counter >= list_skins.length) 						//start over
			{
				counter = 0;
				counterRounds++;
			}
		}
	}
	
	private function addSprites(count:Int):Void {
		var counter:Int = 0;
		
		var list_skins = gfx.getSkinNames();
		
		for (i in 0...count) {
			
			if (list_skins != null) {
				gfx.skinName = list_skins[counter];
				counter++;
				if (counter >= list_skins.length) {
					counter = 0;
				}
			}
			var sprite = new StressSprite(0, 0, gfx);
			sprite.init(offscreen);
			sprite.animation.play(_anim);
			
			sprite.x = 25;
			sprite.y = 25;
			
			spriteGroup.add(sprite);
		}
		
		label_bunnies.text = "Sprites: " + spriteGroup.countLiving();
	}
	
	private function removeSprites(count:Int):Void {
		for (i in 0...count) {
			var sprite:FlxSprite = cast spriteGroup.getFirstAlive();
			if(sprite != null){
				spriteGroup.remove(sprite, true);
				sprite.kill();
				sprite.destroy();
				sprite = null;
			}
		}
		
		label_bunnies.text = "Sprites: " + spriteGroup.countLiving();
	}
}