package com.leveluplabs.tools.animator;

import com.leveluplabs.tools.animator.EntitySkin;
import flash.display.BitmapData;
import flash.geom.Matrix;
import flash.geom.Rectangle;
import flash.text.Font;
import flixel.addons.ui.FlxClickArea;
import flixel.addons.ui.FlxInputText;
import flixel.addons.ui.FlxUI.NamedFloat;
import flixel.addons.ui.FlxUI9SliceSprite;
import flixel.addons.ui.FlxUIButton;
import flixel.addons.ui.FlxUICheckBox;
import flixel.addons.ui.FlxUIColorSwatch;
import flixel.addons.ui.FlxUIColorSwatchSelecter;
import flixel.addons.ui.FlxUIGroup;
import flixel.addons.ui.FlxUINumericStepper;
import flixel.addons.ui.FlxUIPopup;
import flixel.addons.ui.FlxUITabMenu;
import flixel.addons.ui.FlxUIText;
import flixel.addons.ui.FlxUITypedButton.FlxUITypedButton;
import flixel.addons.ui.interfaces.IFlxUIWidget;
import flixel.addons.ui.StrIdLabel;
import flixel.addons.ui.SwatchData;
import flixel.addons.ui.U;
import flixel.animation.FlxAnimation;
import flixel.FlxG;
import flixel.addons.ui.FlxUIState;
import flixel.addons.ui.FlxUIRadioGroup;
import flixel.addons.ui.FlxUIInputText;
import flixel.addons.ui.FlxUIDropDownMenu;
import flixel.FlxSprite;
import flixel.group.FlxGroup;
import flixel.group.FlxSpriteGroup;
import flixel.text.FlxText;
import flixel.util.FlxColor;
import flixel.util.FlxRect;
import flixel.util.FlxTimer;
import flixel.util.FlxVector;
import haxe.xml.Printer;
#if sys
	import systools.Dialogs;
	import sys.FileSystem;
	import sys.io.File;
	import sys.io.FileInput;
	import sys.io.FileOutput;
#end

import firetongue.FireTongue;
import haxe.xml.Fast;
import openfl.Assets;

/**
 * @author Lars Doucet
 */
class State_Animator extends FlxUIState
{
	private var color_index:ColorIndex;
	private var entity_graphics:EntityGraphics;
	private var entity_sprite:EntitySprite;
	private var bounds:FlxRect;
	private var entity_click:FlxClickArea;
	private var frame_sprite:EntitySprite;
	
	private var frame_rect:FlxRect;
	private var anim_rect:FlxRect;
	
	private var check_loop:FlxUICheckBox;
	private var curr_anim_name:String = "";
	
	private var input_name:FlxUIInputText;
	private var input_new:FlxUIInputText;
	private var input_color_feature:FlxUIInputText;
	private var stepper_fps:FlxUINumericStepper;
	
	private var dd_anims:FlxUIDropDownMenu;
	private var dd_skins:FlxUIDropDownMenu;
	private var dd_sprites:FlxUIDropDownMenu;
	
	private var spritesheet:AnimationPreviewSprite;
	private var anim_preview:AnimationPreviewSprite;
	
	private var frames:FlxSprite;
	
	private var underGroup:FlxGroup;
	
	private var selected_anim_frame:Int = -1;
	private var selected_sheet_frame:Int = -1;
	
	private var btn_insert:FlxUIButton;
	private var btn_remove:FlxUIButton;
	
	private var btn_anim_new:FlxUIButton;
	private var btn_anim_delete:FlxUIButton;
	private var btn_anim_rename:FlxUIButton;
	
	private var btn_index:FlxUIButton;
	private var btn_save:FlxUIButton;
	private var btn_stress_test:FlxUIButton;
	
	private var radio_insert:FlxUIRadioGroup;
	
	private var insert_mode:Int = -1;
	
	private var path_index:String = "";
	private static inline var path_defenders:String = "\\xml\\entities\\defenders";
	private static inline var path_enemies:String = "\\xml\\entities\\enemies";
	private static inline var path_colors:String = "\\xml\\entities";
	
	private var list_files:Array<String> = null;
	
	private var map_xml_dirty:Map<String,Bool> = null;
	private var map_xml_data:Map<String,Fast> = null;
	
	private var swatch_selecter:FlxSprite;
	private var group_color_stuff:FlxUIGroup;
	private var radio_color_modes:FlxUIRadioGroup;
	private var group_sweet:FlxUIGroup;
	private var tab_menu:FlxUITabMenu;
	
	private var check_sweet:FlxUICheckBox;
	private var check_sweet_test:FlxUICheckBox;
	private var stepper_sweet_x:FlxUINumericStepper;
	private var stepper_sweet_y:FlxUINumericStepper;
	private var input_sweet_name:FlxUIInputText;
	private var label_curr_frame:FlxUIText;
	
	private var sprite_sweet_spot:FlxSprite;
	
	private var sweetSpotTestOn:Bool = false;
	
	private var group_sweet_test:FlxSpriteGroup;
	private var vector:FlxVector = FlxVector.get();
	
	private var colorFeatureToEdit:String = "";
	
	override public function create():Void
	{
		underGroup = new FlxGroup();
		add(underGroup);
		
		FlxG.cameras.bgColor = 0xffaaaaaa;
		FlxG.log.redirectTraces = false; 
		
		if (Main.tongue == null) {
			Main.tongue = new FireTongueEx();
			Main.tongue.init("en-US");
			FlxUIState.static_tongue = Main.tongue;
		}
		
		_xml_id = "state_animator";
		
		super.create();
		
		check_loop = cast _ui.getAsset("check_loop");
		check_sweet_test = cast _ui.getAsset("check_sweet_test");
		input_name = cast _ui.getAsset("input_name");
		input_new = cast _ui.getAsset("input_new");
		stepper_fps = cast _ui.getAsset("stepper_fps");
		radio_insert = cast _ui.getAsset("radio_insert");
	
		var isReady:Bool = true;
		
		#if sys
			isReady = initData();
		#end
		
		if(isReady){
			entryPoint();
		}
	}
	
	public override function onResize(Width:Int, Height:Int):Void {
		//donothing
	}
	
	#if sys
		private function initData():Bool{
			path_index = readIndex();
			if (path_index == "") {
				openSubState(new Popup_Input());
				return false;
			}else {
				changeIndexPath(path_index);
			}
			if (color_index == null) 
			{
				color_index = new ColorIndex();
				var xml:Fast = U.readFast(path_index + path_colors + "\\" + "colors.xml");
				if (xml != null) {
					color_index.fromXML(xml);
				}
			}
			return true;
		}
		
		private function changeIndexPath(path:String):Void {
			path_index = path;
			writeIndex(path_index);
			showIndex(path_index);
			var dirpath:String = path_index + path_defenders;
			if(FileSystem.exists(dirpath) && FileSystem.isDirectory(dirpath)){
				list_files = FileSystem.readDirectory(dirpath);
			}else {
				FlxG.log.error("Could not find directory: " + dirpath + "!");
			}
		}
		
		private function changeIndex():Void {
			path_index = Dialogs.folder("TITLE!", "MESSAGE!");
			changeIndexPath(path_index);
		}
		
		private function showIndex(path:String):Void {
			var text_index:FlxUIText = cast _ui.getAsset("text_index");
			text_index.text = path_index;
			var safe:Int = 0;
			while(text_index.textField.numLines > 1 && safe < 100) {
				text_index.width += 10;
				text_index.text = path_index;
				if (text_index.width > FlxG.width) {
					break;
				}
				safe++;
			}
			btn_index = cast _ui.getAsset("btn_index");
			btn_index.x = text_index.x + text_index.width + 5;
		}
		
		private function readIndex():String {
			if(FileSystem.exists("config.xml") == false){
				writeIndex("");
				return "";
			}else {
				var index:Fast = new Fast(Xml.parse(File.getContent("config.xml")).firstElement());
				if (index.hasNode.index) {
					var result:String = U.xml_str(index.node.index.x, "path");
					if (result == null || result.toLowerCase() == "null") {
						result = "";
					}
					return result;
				}
			}
			return "";
		}
		
		private function writeIndex(path:String):Void {
			var xml:Xml = Xml.parse('<index path="'+path+'"/>');
			U.writeXml(xml, "config.xml");
		}
		
		private function saveFile():Void {
			if (map_xml_dirty == null || map_xml_data == null) {
				return;
			}
			
			btn_save.label.color = btn_save.over_color = btn_save.down_color = btn_save.up_color = 0x000000;
			btn_save.label.text = "Save";
			dd_sprites.header.text.color = 0x000000;
			
			for (key in map_xml_dirty.keys()) {
				map_xml_dirty.remove(key);
			}
			
			for (key in map_xml_data.keys()) {
				var data:Fast = map_xml_data.get(key);
				var filename:String = key;
				U.writeXml(data.x, filename);
			}
		}
	#end
	
	private function entryPoint(t:FlxTimer=null):Void {
		setupDropdowns();
		setupSprite();
	}
	
	private function setupDropdowns():Void{
		if (list_files == null || list_files.length <= 0) 
		{
			FlxG.log.error("list of files is empty!");
			return;
		}
		
		var reg_animations_dd:IFlxUIWidget = cast _ui.getAsset("reg_animations_dd");
		dd_anims = new FlxUIDropDownMenu(reg_animations_dd.x, reg_animations_dd.y, [new StrIdLabel("null","null")],new FlxUIDropDownHeader(Std.int(reg_animations_dd.width)));
		_ui.addAsset(dd_anims, "dd_anims");
		_ui.removeAsset("reg_animations_dd");
		
		var reg_sprite_dd:IFlxUIWidget = cast _ui.getAsset("reg_sprites_dd");
		dd_sprites = new FlxUIDropDownMenu(reg_sprite_dd.x, reg_sprite_dd.y, [new StrIdLabel("null", "null")]);
		_ui.addAsset(dd_sprites, "dd_sprites");
		_ui.removeAsset("reg_sprites_dd");
		
		var reg_skins_dd:IFlxUIWidget = cast _ui.getAsset("reg_skins_dd");
		dd_skins = new FlxUIDropDownMenu(reg_skins_dd.x, reg_skins_dd.y, [new StrIdLabel("null","null")]);
		_ui.addAsset(dd_skins, "dd_skins");
		_ui.removeAsset("reg_skins_dd");
		
		btn_save = cast _ui.getAsset("btn_save");
		btn_stress_test = cast _ui.getAsset("btn_stress_test");
		
		btn_anim_delete = cast _ui.getAsset("btn_anim_delete");
		btn_anim_new = cast _ui.getAsset("btn_anim_new");
		btn_anim_rename = cast _ui.getAsset("btn_anim_rename");
	}
		
	private function setupSprite():Void{
		var files:Array<StrIdLabel> = getStrIdList(list_files);
		dd_sprites.setData(files);
		loadSprite(files[0].id);
	}
	
	private function loadSkin(skinName:String):Void {
		loadSprite(entity_graphics.name+".xml", skinName);
	}
	
	private function loadSprite(fname:String, skinName:String = ""):Void {
		
		if (map_xml_dirty == null) {
			map_xml_dirty = new Map<String,Bool>();
		}
		
		if (map_xml_dirty.exists(fname) && map_xml_dirty.get(fname) == true) {
			dd_sprites.header.text.color = 0xff0000;
		}else {
			dd_sprites.header.text.color = 0x000000;
		}
		
		if (entity_graphics != null) {
			entity_graphics.destroy();
		}
		entity_graphics = new EntityGraphics();
		
		var loadpath:String = path_index + path_defenders + "\\" + fname;
		
		var xml = null;
		
		if (map_xml_data != null && map_xml_data.exists(loadpath)) {
			//If we have temporary data for this sprite, load it locally instead of from the file
			xml = map_xml_data.get(loadpath);
		}else {
			xml = U.readFast(loadpath);
		}
		
		if(xml != null){
			entity_graphics.fromXML(xml);
			
			if (skinName != "") {
				entity_graphics.skinName = skinName;
			}else {
				entity_graphics.skinName = entity_graphics.getDefaultSkin().name;
			}
			
			var anims:Array<StrIdLabel> = entity_graphics.getAnimationList();
			dd_anims.setData(anims);
			
			var skins:Array<StrIdLabel> = entity_graphics.getSkinList();
			dd_skins.setData(skins);
			
			dd_skins.header.text.text = entity_graphics.skinName;
			
			if (entity_sprite != null) {
				remove(entity_sprite, true);
				entity_sprite.destroy();
				entity_sprite = null;
			}
			if (anim_preview != null) {
				remove(anim_preview, true);
				anim_preview.destroy();
				anim_preview = null;
			}
			if (spritesheet != null) {
				remove(spritesheet, true);
				spritesheet.destroy();
				spritesheet = null;
			}
			if (frame_sprite != null) {
				remove(frame_sprite, true);
				frame_sprite.destroy();
				frame_sprite = null;
			}
			
			selectAnim(anims[0].id);
			
			clickAnimPreview(0,false);
			
			clickSpriteSheet(0,false);
			
			showSpriteColorization();
			
			radio_insert.selectedId = "before";
		}else {
			FlxG.log.error("State_Animator.loadSprite("+fname+"): couldn't read : \"" + loadpath + "\" !");
		}
	}
	
	private function makeTabMenu():Void {
		var reg_colors = _ui.getAsset("reg_colors");
		
		var tabs = [{id:"colors", label:"Colors"},{id:"sweets", label:"SweetSpots"}];
		tab_menu = new FlxUITabMenu(null, tabs, true);
		tab_menu.x = reg_colors.x;
		tab_menu.y = reg_colors.y;
		tab_menu.resize(reg_colors.width, reg_colors.height);
		
		_ui.addAsset(tab_menu, "tab_menu","under");
		_ui.removeAsset("reg_colors");
		
		if (group_color_stuff == null)
		{
			group_color_stuff = new FlxUIGroup();
			group_color_stuff.id = "colors";
			tab_menu.addGroup(group_color_stuff);
		}
		
		if(radio_color_modes == null){
			radio_color_modes = new FlxUIRadioGroup(0, 0,
					[Std.string(EntityGraphics.COLOR_CHANGE_NONE), Std.string(EntityGraphics.COLOR_CHANGE_LAYERS), Std.string(EntityGraphics.COLOR_CHANGE_PIXEL_PALETTE)],
					["None", "Layers", "Pixels"], onColorModeRadio, 15);
			
			radio_color_modes.x = 4;
			radio_color_modes.y = 4;
			
			var btn:FlxUIButton = new FlxUIButton(0, 0, "Edit Master\nColor Index", onClickColorIndex);
			btn.resize(75, 40);
			
			btn.x = 100;
			btn.y = 10;
			
			btn.id = "btn_color_index";
			
			group_color_stuff.add(btn);
			group_color_stuff.add(radio_color_modes);
		}
		
		group_sweet = new FlxUIGroup();
		group_sweet.id = "sweets";
		
		label_curr_frame = new FlxUIText(5, 5, 200, "Select an animation frame!");
		label_curr_frame.setBorderStyle(FlxText.BORDER_OUTLINE_FAST, 0);
		group_sweet.add(label_curr_frame);
		
		check_sweet = new FlxUICheckBox(5, label_curr_frame.y+20,null,null,"Has Sweet Spot");
		
		
		stepper_sweet_x = new FlxUINumericStepper(check_sweet.x+20, check_sweet.y + 30, 1, 0, 0);
		stepper_sweet_y = new FlxUINumericStepper(stepper_sweet_x.x+100, check_sweet.y + 30, 1, 0, 0);
		
		input_sweet_name = new FlxUIInputText(check_sweet.x+40, check_sweet.y + 60,100);
		input_sweet_name.text = "";
		
		group_sweet.add(check_sweet);
		group_sweet.add(stepper_sweet_x);
		group_sweet.add(stepper_sweet_y);
		group_sweet.add(input_sweet_name);
		
		
		var label = new FlxUIText(stepper_sweet_x.x - 20, stepper_sweet_x.y, 20, "X:");
		label.setBorderStyle(FlxText.BORDER_OUTLINE_FAST, 0);
		group_sweet.add(label);
		label = new FlxUIText(stepper_sweet_y.x - 20, stepper_sweet_y.y, 20, "Y:");
		label.setBorderStyle(FlxText.BORDER_OUTLINE_FAST, 0);
		group_sweet.add(label);
		label = new FlxUIText(input_sweet_name.x - 40, input_sweet_name.y, 40, "Name:");
		label.setBorderStyle(FlxText.BORDER_OUTLINE_FAST, 0);
		group_sweet.add(label);
		
		tab_menu.addGroup(group_sweet);
		enableSweetMenu(false);
	}
	
	private function onClickColorIndex():Void {
		openSubState(new Popup_EditColorIndex(color_index));
		//confirm("...", "Testing", "Color Index Goes Here", ["OK"]);
	}
	
	private function onColorModeRadio(mode:String):Void {
		var modeInt:Int = Std.parseInt(mode);
		var oldMode:Int = entity_graphics.skin.color_change_mode;
		
		//If we're going from something to nothing, warn the user first
		if (modeInt == EntityGraphics.COLOR_CHANGE_NONE && oldMode != EntityGraphics.COLOR_CHANGE_NONE) {
			confirm("confirm_color_mode_none", "Are you sure?", "This will destroy your color structure.", ["YES", "CANCEL"]);
		}else {
			doColorModeRadio(mode);
		}
	}
	
	private function doColorModeRadio(mode:String):Void {
		switch(Std.parseInt(mode)) {
			case EntityGraphics.COLOR_CHANGE_NONE:
				entity_graphics.skin.color_change_mode = EntityGraphics.COLOR_CHANGE_NONE;
			case EntityGraphics.COLOR_CHANGE_LAYERS:
				entity_graphics.skin.color_change_mode = EntityGraphics.COLOR_CHANGE_LAYERS;
			case EntityGraphics.COLOR_CHANGE_PIXEL_PALETTE:
				entity_graphics.skin.color_change_mode = EntityGraphics.COLOR_CHANGE_PIXEL_PALETTE;
		}
		
		stashAndDirtyData();
		refreshSprite();
		showSpriteColorization();
	}
	
	private function getCurrentAnimation():AnimationData{
		var name:String = curr_anim_name;
		if (name != "" && name != null) {
			return entity_graphics.animations.get(name);
		}
		return null;
	}
	
	private function enableSweetMenu(b:Bool,i:Int=0):Void {
		if (group_sweet == null) {
			return;
		}
		
		//Start by ensuring everything is disabled
		for (f in group_sweet.members) {
			if (f != label_curr_frame && f != check_sweet) {
				f.active = false;
				
				if(Std.is(f,FlxUIInputText) == false){
					f.color = 0xffa0a0a0;
				}else {
					var ft:FlxUIInputText = cast f;
					ft.backgroundColor = 0xffa0a0a0;
				}
				
				if (f == stepper_sweet_x) {
					stepper_sweet_x.value = 0;
				}
				if (f == stepper_sweet_y) {
					stepper_sweet_y.value = 0;
				}
				if (f == input_sweet_name) {
					input_sweet_name.text = "";
				}
			}
		}
		
		//DISABLE
		if (b == false) {
			label_curr_frame.text = "Select an animation frame!";
			
		}else { //ENABLE
			label_curr_frame.text = "Anim Index Frame: " + Std.string(i);
			
			//always activate the check
			check_sweet.color = 0xffffffff;
			check_sweet.active = true;
			
			var curr_anim:AnimationData = getCurrentAnimation();
			
			if (curr_anim != null) {
				check_sweet.checked = curr_anim.hasSweetSpot(i);
				if (curr_anim.hasSweetSpot(i)) {
					var ss:AnimSweetSpot = curr_anim.getSweetSpot(i);
					stepper_sweet_x.value = ss.x;
					stepper_sweet_y.value = ss.y;
					input_sweet_name.text = ss.name;
				}else {
					check_sweet.checked = false;
					stepper_sweet_x.value = 0;
					stepper_sweet_y.value = 0;
					input_sweet_name.text = "";
				}
			}
			
			//activate others based on check status
			if(check_sweet.checked){
				for (f in group_sweet.members) {
					f.active = true;
					if(Std.is(f,FlxUIInputText) == false){
						f.color = 0xffffffff;
					}else {
						var ft:FlxUIInputText = cast f;
						ft.backgroundColor = 0xffffffff;
					}
				}
			}
		}
		showSweetSpotLocation();
	}
	
	private function showSpriteColorization():Void 
	{
		trace("showSpriteColorization()");
		var skin:EntitySkin = entity_graphics.skin;
		
		if (tab_menu == null) {
			makeTabMenu();
		}
		for (thing in group_color_stuff.members) {
			if(thing != radio_color_modes){
				thing.visible = false;
				thing.active = false;
			}
		}
		
		radio_color_modes.selectedId = Std.string(skin.color_change_mode);
		
		if (skin == null)
		{
			return;
		}
		
		if (skin.color_change_mode != EntityGraphics.COLOR_CHANGE_NONE)
		{
			var feature:ColorFeature;
			var inputTextName:String = "new";
			var inputI:Int = 0;
			var i:Int = 0;
			var yy:Float = radio_color_modes.y + radio_color_modes.height;
			
			//fetch the color editing button and show it
			var color_index_btn:FlxUIButton = getColorStuffButton("btn_color_index");
			
			if (skin.list_color_features != null)
			{
				for (feature in skin.list_color_features)
				{
					if (feature.palette_name != "" && feature.palette_name != "null" && feature.palette_name != null)
					{
						if (feature.name == inputTextName) {
							inputI++;
							inputTextName = "new" + Std.string(inputI);
						}
						var label:FlxText = getColorStuffLabel();
						if (label == null)
						{
							label = new FlxText(0,0,50,feature.name);
							group_color_stuff.add(label);
						}
						label.x = group_color_stuff.x+4;
						label.y = yy;
						label.text = feature.name.toUpperCase();
						label.color = 0xFFFFFF;
						label.setBorderStyle(FlxText.BORDER_OUTLINE_FAST);
						label.alignment = "left";
						
						var btn:FlxUIButton = getColorStuffButton();
						if (btn == null) 
						{
							btn = new FlxUIButton(0,0,"...");
							group_color_stuff.add(btn);
							btn.resize(30, label.height);
						}
						btn.x = label.x + label.textField.textWidth + 4;
						btn.y = label.y;
						btn.resize(30, label.height);
						btn.label.text = "...";
						btn.id = "btn_change_color_feature";
						btn.params = [feature.palette_name,feature.name];
						
						var btn2:FlxUIButton = getColorStuffButton();
						if (btn2 == null) 
						{
							btn2 = new FlxUIButton(0, 0, "X");
							group_color_stuff.add(btn2);
							btn2.resize(20, label.height);
						}
						btn2.x = btn.x + btn.width + 2;
						btn2.y = btn.y;
						btn2.label.text = "X";
						btn2.resize(20, label.height);
						btn2.id = "btn_delete_color_feature";
						btn2.params = [feature.name,i];
						
						var palette:ColorPalette = color_index.getPalette(feature.palette_name);
						
						var swatch:SwatchData = null;
						var xx:Float = group_color_stuff.x+4;
						
						if (palette != null) 
						{
							if (palette.list_colors != null) 
							{
								var swatchSelecter:FlxUIColorSwatchSelecter = getColorStuffSwatchSelecter();
								if (swatchSelecter == null) 
								{
									swatchSelecter = new FlxUIColorSwatchSelecter(0,0, palette.list_colors);
									group_color_stuff.add(swatchSelecter);
								}else {
									swatchSelecter.changeColors(palette.list_colors);
								}
								
								swatchSelecter.x = xx;
								swatchSelecter.y = yy + label.height + 1;
								swatchSelecter.id = feature.name;
								
								var currSwatch:SwatchData = entity_graphics.skin.getSwatchFromColorFeature(feature.name);
								trace("currSwatch = " + currSwatch);
								if (currSwatch != null)
								{
									trace("selectByColors");
									swatchSelecter.selectByColors(currSwatch, true);
									trace("swatchSelecter.selectedSwatch.colorKey = " + swatchSelecter.selectedSwatch.colorKey());
								}else
								{
									trace("unselect");
									swatchSelecter.unselect();
								}
							}
						}
						
						yy += Std.int(label.height + 5) + 18;
					}
					i++;
				}
			}
			input_color_feature = getColorStuffInputText();
			if (input_color_feature == null) {
				input_color_feature = new FlxUIInputText(0, 0);
				input_color_feature.width = 100;
				group_color_stuff.add(input_color_feature);
			}
			input_color_feature.text = inputTextName;
			input_color_feature.x = group_color_stuff.x + 4;
			input_color_feature.y = yy;
			
			var btn3:FlxUIButton = getColorStuffButton();
			if (btn3 == null) 
			{
				btn3 = new FlxUIButton(4, 0, "New...");
				group_color_stuff.add(btn3);
			}
			
			btn3.label.text = "Add New";
			btn3.resize(75, 16);
			btn3.x = input_color_feature.x + input_color_feature.width + 4;
			btn3.y = yy;
			btn3.id = "btn_new_color_feature";
		}
	}
	
	private function getColorStuffInputText():FlxUIInputText {
		for (thing in group_color_stuff.members) {
			if (Std.is(thing, FlxUIInputText)) {
				if (thing.visible == false && thing.active == false) {
					thing.visible = true;
					thing.active = true;
					return cast thing;
				}
			}
		}
		return null;
	}
	
	private function getColorStuffButton(id:String=""):FlxUIButton {
		for (thing in group_color_stuff.members) {
			if (Std.is(thing, FlxUIButton)) {
				var b:FlxUIButton = cast thing;
				if (b.visible == false && b.active == false) {
					if (id != "") {
						if (b.id == id) {
							b.visible = true;
							b.active = true;
							return b;
						}
					}else {
						b.visible = true;
						b.active = true;
						return b;
					}
				}
			}
		}
		return null;
	}
	
	private function getColorStuffLabel():FlxText {
		for (thing in group_color_stuff.members) {
			if (Std.is(thing, FlxText) && !Std.is(thing,FlxUIInputText)) {
				if (thing.visible == false && thing.active == false) {
					thing.visible = true;
					thing.active = true;
					return cast thing;
				}
			}
		}
		return null;
	}
	
	private function getColorStuffSwatchSelecter():FlxUIColorSwatchSelecter{
		for (thing in group_color_stuff.members) {
			if (Std.is(thing, FlxUIColorSwatchSelecter)) {
				if (thing.visible == false && thing.active == false) {
					thing.visible = true;
					thing.active = true;
					return cast thing;
				}
			}
		}
		return null;
	}
	
	private function getStrIdList(list:Array<String>):Array<StrIdLabel> {
		var silist:Array<StrIdLabel> = [];
		for (str in list) {
			silist.push(new StrIdLabel(str, str));
		}
		return silist;
	}
	
	private function createSpriteSheet():Void {
		var reg_spritesheet = _ui.getAsset("reg_spritesheet");
		
		var ad:AnimationData = new AnimationData();
		ad.name = "raw_frames";
		for (i in 0...entity_sprite.frames) {
			ad.frames.push(i);
		}
		
		spritesheet = new AnimationPreviewSprite(entity_sprite, ad, reg_spritesheet.width, reg_spritesheet.height, onClickSpriteSheet);
		spritesheet.y = reg_spritesheet.y;
		spritesheet.x = reg_spritesheet.x;
		spritesheet.hilightColor = 0x8800ff00;
		spritesheet.hilightColor2 = 0xffff00ff;
		
		underGroup.add(spritesheet);
		
		reg_spritesheet.visible = false;
		//_ui.removeAsset("reg_spritesheet");
	}
	
	public override function update():Void {
		super.update();
		checkBullets();
	}
	
	private function updateSheetButtons():Void {
		if (btn_insert == null) { btn_insert = cast _ui.getAsset("btn_insert");}
		if (btn_remove == null) { btn_remove = cast _ui.getAsset("btn_remove"); }
		
		if (selected_anim_frame != -1) {
			btn_remove.active = true;
			btn_remove.color = 0xFFFFFF;
			if (selected_sheet_frame != -1) {
				btn_insert.active = true;
				btn_insert.color = 0xFFFFFF;
			}else {
				btn_insert.active = false;
				btn_insert.color = 0x808080;
			}
		}else {
			btn_remove.active = false;
			btn_remove.color = 0x808080;
			btn_insert.active = false;
			btn_insert.color = 0x808080;
		}
	}
	
	private function onClickSpriteSheet(i:Int):Void {
		clickSpriteSheet(i);
	}
		
	private function clickSpriteSheet(i:Int,toggle:Bool=true):Void {
		if (toggle && i == selected_sheet_frame) {
			selected_sheet_frame = spritesheet.hilightCell( -1, 1);
		}else{
			selected_sheet_frame = spritesheet.hilightCell(i, 1);
			showSpriteSheetFrame(i);
		}
		updateSheetButtons();
	}
	
	private function onClickAnimPreview(i:Int):Void {
		clickAnimPreview(i);
	}
		
	private function clickAnimPreview(i:Int, toggle:Bool = true):Void {
		if (toggle && i == selected_anim_frame) {
			selected_anim_frame = anim_preview.hilightCell( -1);
			spritesheet.hilightCell( -1);
			enableSweetMenu(false);
		}else{
			selected_anim_frame = anim_preview.hilightCell(i);
			
			var anim:AnimationData = currAnim();
			var sheet_index:Int = anim.frames[i];
			
			spritesheet.hilightCell(sheet_index);
			
			if (label_curr_frame != null) {
				enableSweetMenu(true,i);
			}
		}
		updateSheetButtons();
	}
	
	private inline function currAnim():AnimationData {
		return entity_graphics.animations.get(curr_anim_name);
	}
	
	private function removeFrame():Void {
		if (selected_anim_frame == -1) { return; }
		var anim:AnimationData = currAnim();
		if(anim.frames.length > 1){
			anim.frames.splice(selected_anim_frame, 1);
			refreshAnim();
		}
		stashAndDirtyData();
	}
	
	private function insertFrame():Void {
		if (selected_anim_frame == -1) { return; }
		if (selected_sheet_frame == -1) { return; }
		var anim:AnimationData = currAnim();
		if(insert_mode == -1){			//before
			anim.frames.insert(selected_anim_frame, selected_sheet_frame);
		}else if (insert_mode == 1) {	//after
			anim.frames.insert(selected_anim_frame + 1, selected_sheet_frame);
			selected_anim_frame++;
		}
		refreshAnim();
		stashAndDirtyData();
	}
	
	private function refreshSprite():Void {
		var fname:String = dd_sprites.header.text.text;
		
		stashAndDirtyData();
		
		//Reload the sprite
		loadSprite(fname, entity_graphics.skinName);
	}
	
	private function stashAndDirtyData():Void {
		var fname:String = dd_sprites.header.text.text;
		var curr_path:String = path_index + path_defenders + "\\" + fname;		//get the full filename
		
		if (map_xml_data == null) {
			map_xml_data = new Map<String,Fast>();
		}
		
		//Stash the current XML representation of the object
		var gfxXML:Fast = entity_graphics.toXML();
		map_xml_data.set(curr_path, gfxXML);
		
		dirtyFileState(fname);
	}
	
	private function dirtyFileState(fileName:String):Void {
		map_xml_dirty.set(fileName, true);
		
		var butt:FlxUIButton = null;
		dd_sprites.header.text.color = 0x000000;
		
		if (dd_sprites.header.text.text == fileName) 
		{
			dd_sprites.header.text.color = 0xff0000;
		}
		
		for (butt in dd_sprites.list) 
		{
			butt.label.color = butt.over_color = butt.down_color = butt.up_color = 0x000000;
			if (butt.label.text == fileName) {
				butt.label.color = butt.over_color = butt.down_color = butt.up_color = 0xff0000;
			}
		}
		
		btn_save.label.text = "Save*";
		btn_save.label.color = btn_save.over_color = btn_save.down_color = btn_save.up_color = 0xff0000;
	}
	
	private function refreshAnim(?t:FlxTimer=null,?the_frame:Int=-1):Void {
		selectAnim(curr_anim_name);
		if (the_frame == -1) {
			the_frame = selected_anim_frame;
		}
		clickAnimPreview(the_frame, false);
		clickSpriteSheet(the_frame, false);
	}
	
	private function stressTest():Void {
		Main.data.curr_anim = curr_anim_name;
		Main.data.curr_gfx = entity_graphics;
		FlxG.switchState(new State_StressTest());
	}
	
	private function createAnimation():Void {
		if (input_new != null) {
			var animName:String = input_new.text;
			if(animName!= "" && animName != null){
				if (!entity_graphics.animations.exists(animName)) {
					var newAnim = new AnimationData();
					newAnim.name = animName;
					newAnim.frames = [0];
					newAnim.looped = false;
					newAnim.sweets = null;
					entity_graphics.animations.set(animName, newAnim);
					
					var anims:Array<StrIdLabel> = entity_graphics.getAnimationList();
					dd_anims.setData(anims);
					dd_anims.header.text.text = animName;
					selectAnim(animName);
				}
			}
		}
		stashAndDirtyData();
	}
	
	private function renameAnimation():Void {
		var anim:AnimationData = currAnim();
		if (anim != null) {
			entity_graphics.animations.remove(anim.name);
			anim.name = input_new.text;
			entity_graphics.animations.set(anim.name, anim);
			
			var anims:Array<StrIdLabel> = entity_graphics.getAnimationList();
			dd_anims.setData(anims);
			dd_anims.header.text.text = anim.name;
		}
		stashAndDirtyData();
	}
	
	private function deleteAnimation():Void {
		if (dd_anims.list.length <= 1) {
			confirm("alert", "Error", "Can't delete the last animation!", ["OK"]);
		}else {
			confirm("confirm_delete_animation", "Confirm", "Are you sure you want to delete this animation?", ["Yes", "No"]);
		}
		stashAndDirtyData();
	}
	
	private function confirm(confirmId:String, title:String, message:String, buttons:Array<String>, ?Params:Array<Dynamic>):Void {
		var p:FlxUIPopup = new FlxUIPopup();
		p.quickSetup(title, message, buttons);
		p.id = confirmId;
		p.params = Params;
		openSubState(p);
	}
	
	private function doDeleteAnimation():Void {
		var ad:AnimationData = currAnim();
		entity_graphics.animations.remove(ad.name);
		ad.destroy();
		ad = null;
		var anims:Array<StrIdLabel> = entity_graphics.getAnimationList();
		dd_anims.setData(anims);
		if(anims.length > 0){
			selectAnim(anims[0].id);
		}
	}
	
	private function deleteColorFeature(featureName:String):Void {
		var p:FlxUIPopup = new FlxUIPopup();
		
		p.params = [featureName];
		p.quickSetup("Confirm", "Are you sure you want to delete this color feature?", ["Yes", "No"]);
		p.id = "confirm_delete_color_feature";
		
		openSubState(p);
	}
	
	private function doDeleteColorFeature(featureName):Void {
		entity_graphics.skin.removeColorFeature(featureName);
		stashAndDirtyData();
		loadSkin(entity_graphics.skinName);	//reload the skin
	}
	
	private function changeColorFeature(featureName:String, paletteName:String):Void {
		colorFeatureToEdit = featureName;
		openSubState(new Popup_ChangeColorFeature(paletteName,color_index,false,entity_graphics,featureName));
	}
	
	private function doChangeColorFeature(colorFeature:ColorFeature):Void {
		var cp:ColorPalette = color_index.getPalette(colorFeature.palette_name);
		
		entity_graphics.skin.changeColorFeaturePalette(colorFeatureToEdit, cp, colorFeature.name);
		entity_graphics.skin.replaceColorFeature(colorFeature.name, colorFeature);
		
		/*colorFeature.destroy();
		colorFeature = null;*/
		
		stashAndDirtyData();
		loadSkin(entity_graphics.skinName);	//reload the skin
		colorFeatureToEdit = "";
	}
	
	private function newColorFeature():Void {
		openSubState(new Popup_ChangeColorFeature("",color_index,true,entity_graphics,input_color_feature.text));
	}
	
	private function doNewColorFeature(colorFeature:ColorFeature):Void {
		var cp:ColorPalette = color_index.getPalette(colorFeature.palette_name);
		colorFeature.palette = cp;
		entity_graphics.skin.addColorFeature(colorFeature);
		stashAndDirtyData();
		
		loadSkin(entity_graphics.skinName);	//reload the skin
	}
	
	public override function getEvent(id:String, sender:IFlxUIWidget, data:Dynamic, ?params:Array<Dynamic>):Void {
		var str:String = "";
		
		var arr:Array<Dynamic>;
		
		switch(id) {
			case "popup_select_color_feature":
				var colorFeature:ColorFeature = cast data;
				doChangeColorFeature(colorFeature);
			case "popup_create_color_feature":
				var colorFeature:ColorFeature = cast data;
				doNewColorFeature(colorFeature);
			case "popup_color_index_change":
				trace("color index changed!");
			case "choose_path":
				changeIndexPath(cast data);
				entryPoint();
			case FlxUIPopup.CLICK_EVENT:
				var p:FlxUIPopup = cast sender;
				var popBtn:Int = Std.int(data);
				if (p.id == "confirm_delete_animation") {
					if(popBtn == 0) {
						doDeleteAnimation();
					}
				}else if (p.id == "confirm_delete_color_feature") {
					if (popBtn == 0) {
						var featureName:String = cast params[1];
						doDeleteColorFeature(featureName);
					}
				}else if (p.id == "confirm_color_mode_none") {
					if (popBtn == 0){
						doColorModeRadio(Std.string(EntityGraphics.COLOR_CHANGE_NONE));
					}else {
						doColorModeRadio(Std.string(entity_graphics.skin.color_change_mode));
					}
				}
			case FlxUITypedButton.CLICK_EVENT:
				if (sender == btn_insert) {
					insertFrame();
				}else if (sender == btn_remove) {
					removeFrame();
				}else if (sender == btn_index) {
					changeIndex();
				}else if (sender == btn_save) {
					saveFile();
				}else if (sender == btn_stress_test) {
					stressTest();
				}else if (sender == btn_anim_new) {
					createAnimation();
				}else if (sender == btn_anim_delete) {
					deleteAnimation();
				}else if (sender == btn_anim_rename) {
					renameAnimation();
				}else if (sender.id == "btn_change_color_feature") {
					var paletteName:String = cast params[0];
					var featureName:String = cast params[1];
					changeColorFeature(featureName,paletteName);
				}else if (sender.id == "btn_delete_color_feature") {
					var featureName:String = cast params[0];
					deleteColorFeature(featureName);
				}else if (sender.id == "btn_new_color_feature") {
					newColorFeature();
				}
			case FlxUIColorSwatchSelecter.CLICK_EVENT:
				var swatch:SwatchData = cast data;
				trace("Clicked on swatch(" + swatch + ")");
				var swatchSelecter:FlxUIColorSwatchSelecter = cast sender;
				entity_graphics.skin.changeColorFeature(swatchSelecter.id, swatch);
				refreshSprite();
			case FlxUITabMenu.CLICK_EVENT:
				var tabId:String = cast data;
				if (tabId == "sweets") {
					if(selected_anim_frame != -1){
						entity_sprite.animation.paused = true;
						showSweetSpotLocation();
					}
				}else {
					entity_sprite.animation.paused = false;
					showSweetSpotLocation(false);
				}
			case FlxUIDropDownMenu.CLICK_EVENT:
				var str = cast data;
				if(sender == dd_anims){
					selectAnim(str);
				}else if (sender == dd_sprites) {
					loadSprite(str);
				}else if (sender == dd_skins) {
					loadSkin(str);
				}
			case FlxUICheckBox.CLICK_EVENT:
				var checked:Bool = cast data;
				if(sender == check_loop){
					var anim:AnimationData = currAnim();
					anim.looped = checked;
					loadAnimation(curr_anim_name);
				}else if (sender == check_sweet) {
					updateSweetSpot();
				}else if (sender == check_sweet_test) {
					setSweetSpotTest(checked);
				}
			case FlxUINumericStepper.CHANGE_EVENT:
				if(sender == stepper_fps){
					var int:Int = cast data;
					setCurrAnimFPS(int);
				}else if (sender == stepper_sweet_x || sender == stepper_sweet_y) {
					updateSweetSpot();
				}
			case FlxUIInputText.CHANGE_EVENT:
				if (sender == input_name) {
					str = cast data;
					setCurrAnimName(str);
				}else if (sender == input_sweet_name) {
					updateSweetSpot();
				}else if (sender == input_new) {
					onInputAnimNew();
				}
			case FlxUIRadioGroup.CLICK_EVENT:
				if (sender == radio_insert) {
					str = cast data;
					switch(str) {
						case "before": insert_mode = -1;
						case "after": insert_mode = 1;
					}
				}
		}
	}
	
	private function onInputAnimNew():Void {
		if (input_new.text == "" || input_new.text == null && entity_graphics.animations.exists(input_new.text) == false) {
			btn_anim_new.active = false;
			btn_anim_new.color = 0xa0a0a0;
		}else {
			btn_anim_new.active = true;
			btn_anim_new.color = 0xffffff;
		}
	}
	
	private function setSweetSpotTest(b:Bool = true):Void {
		sweetSpotTestOn = b;
		if (sweetSpotTestOn) {
			entity_sprite.onSweetSpotCallback = onEntitySpriteSweetSpot;
		}else {
			entity_sprite.onSweetSpotCallback = null;
		}
	}
	
	private function showSweetSpotLocation(b:Bool = true):Void {
		if (b == false) {
			if (sprite_sweet_spot != null) {
				sprite_sweet_spot.visible = false;
			}
			return;
		}
		if (group_sweet == null) {
			return;
		}
		
		var a = currAnim();
		
		var X:Float = stepper_sweet_x.value;
		var Y:Float = stepper_sweet_y.value;
		var Show:Bool = check_sweet.checked;
		
		if (a != null && entity_sprite != null && entity_sprite.animation != null && selected_anim_frame > 0 && selected_anim_frame < a.frames.length) {
			entity_sprite.animation.frameIndex = a.frames[selected_anim_frame];
		}
		if (sprite_sweet_spot == null) {
			if(Show){
				sprite_sweet_spot = new FlxSprite(0, 0, U.gfx("ui/sweet_loc"));
				add(sprite_sweet_spot);
			}
		}else {
			sprite_sweet_spot.visible = Show;
		}
		
		if(Show){
			sprite_sweet_spot.x = entity_sprite.x + X - Std.int(sprite_sweet_spot.width/2);
			sprite_sweet_spot.y = entity_sprite.y + Y - Std.int(sprite_sweet_spot.height/2);
		}
	}
	
	private function updateSweetSpot():Void {
		if (group_sweet == null) {
			return;
		}
		var exists:Bool = check_sweet.checked;
		if (selected_anim_frame != -1) {
			if(group_sweet != null){
				var anim:AnimationData = currAnim();
				if(exists){
					var sName:String = input_sweet_name.text;
					var sX:Float = stepper_sweet_x.value;
					var sY:Float = stepper_sweet_y.value;
					anim.editSweetSpot(selected_anim_frame, sName, sX, sY);
				}else {
					anim.removeSweetSpot(selected_anim_frame);
				}
				anim_preview.showEntityAnimation(entity_sprite, anim, false);
			}
		}
		showSweetSpotLocation();
		stashAndDirtyData();
		enableSweetMenu(exists,selected_anim_frame);
	}
	
	public function setCurrAnimFPS(fps:Int):Void {
		var anim = fetchAnim(curr_anim_name);
		if (anim != null) {
			anim.frameRate = fps;
			loadAnimation(curr_anim_name);
		}
	}
	
	public function setCurrAnimName(name:String):Void {
		var oldName:String = curr_anim_name;
		
		var anim = fetchAnim(oldName);
		
		var btn:FlxUIButton = dd_anims.getBtnById(oldName);
		btn.id = name;			//update both id and label
		btn.label.text = name;
		
		if (anim != null) {
			entity_graphics.animations.remove(oldName);
			entity_graphics.animations.set(name, anim);
		
			anim.name = name;
			curr_anim_name = name;
			loadAnimation(name);
			dd_anims.header.text.text = name;
		}
	}
	
	public function selectAnim(str:String):Void {
		var isNew:Bool = curr_anim_name != str;
		curr_anim_name = str;
		var anim:AnimationData = fetchAnim(str);
		if (anim != null) {
			check_loop.checked = anim.looped;
			input_name.text = anim.name;
			stepper_fps.value = anim.frameRate;
		}
		loadAnimation(str);
		if(isNew){
			clickAnimPreview( -1);							//if new, deselect always
		}else {
			if (selected_anim_frame > anim.frames.length - 1) {	//if old, deselect if out of bounds
				clickAnimPreview( -1);
			}
		}
	}
	
	private function fetchAnim(str:String):AnimationData {
		if (entity_graphics.animations.exists(str)) {
			return entity_graphics.animations.get(str);
		}
		return null;
	}
	
	private function showSpriteSheetFrame(i:Int):Void {
		var box:FlxUI9SliceSprite = cast _ui.getAsset("frame_box");
		if (frame_rect == null) {
			frame_rect = FlxRect.get(box.x, box.y, box.width, box.height);
		}
		
		if (frame_sprite == null) {
			frame_sprite = new EntitySprite(frame_rect.x, frame_rect.y, entity_graphics);
			
			add(frame_sprite);
			frame_sprite.x += (frame_rect.width - entity_sprite.width) / 2;
			frame_sprite.y += (frame_rect.height - entity_sprite.height) / 2;
			
			var ad = getRawFrames();
			frame_sprite.addAnimation(ad);
			frame_sprite.animation.play(ad.name, true);
		}
		
		box.resize(frame_sprite.width, frame_sprite.height);
		box.x = frame_sprite.x;
		box.y = frame_sprite.y;
		
		frame_sprite.animation.frameIndex = i;
	}
	
	private function getRawFrames():AnimationData{
		var ad:AnimationData = new AnimationData();
		ad.name = "raw_frames";
		ad.frameRate = 0;
		for (i in 0...entity_sprite.frames) {
			ad.frames.push(i);
		}
		return ad;
	}
	
	private function makeEntityClick():Void {
		if (entity_click == null) {
			entity_click = new FlxClickArea(entity_sprite.x, entity_sprite.y, entity_sprite.width, entity_sprite.height, onEntitySpriteClick);
			add(entity_click);
		}
		entity_click.x = entity_sprite.x;
		entity_click.y = entity_sprite.y;
		entity_click.width = entity_sprite.width;
		entity_click.height = entity_sprite.height;
		if (bounds == null) {
			bounds = FlxRect.get();
		}
		bounds.x = entity_sprite.x-entity_sprite.width;
		bounds.y = entity_sprite.y-entity_sprite.height;
		bounds.width = entity_sprite.width * 3;
		bounds.height = entity_sprite.height * 3;
	}
	
	private function onEntitySpriteSweetSpot(AnimName:String, SweetName:String, X:Float, Y:Float):Void {
		if (group_sweet_test == null) {
			group_sweet_test = new FlxSpriteGroup();
			add(group_sweet_test);
		}
		var bullet:FlxSprite = group_sweet_test.getFirstDead();
		if (bullet == null) {
			bullet = new FlxSprite(0, 0, U.gfx("ui/bullet"));
			group_sweet_test.add(bullet);
		}
		bullet.reset(entity_sprite.x + X, entity_sprite.y + Y);
		
		var halfW:Float = entity_sprite.width / 2;
		var halfH:Float = entity_sprite.height / 2;
		
		var compX:Float = (X - halfW) / halfW;
		var compY:Float = (Y - halfH) / halfH;
		
		compX = Math.ceil(compX * 4) / 4;
		compY = Math.ceil(compY * 4) / 4;
		
		vector.set(compX, compY);
		vector.normalize();
		
		bullet.velocity.set(vector.x*50, vector.y*50);
	}
	
	private function checkBullets():Void {
		if(sweetSpotTestOn && group_sweet_test != null){
			for (bullet in group_sweet_test.members) {
				if (bullet.x < bounds.left || bullet.x > bounds.right || bullet.y < bounds.top || bullet.y > bounds.bottom) {
					bullet.kill();
				}
			}
		}
	}
	
	private function onEntitySpriteClick():Void {
		if (tab_menu != null && tab_menu.selected_tab_id == "sweets") {
			var dx:Float = FlxG.mouse.x - entity_click.x;
			var dy:Float = FlxG.mouse.y - entity_click.y;
			stepper_sweet_x.value = dx;
			stepper_sweet_y.value = dy;
			updateSweetSpot();
		}
	}
	
	private function loadAnimation(anim:String):Void {
		var box:FlxUI9SliceSprite = cast _ui.getAsset("preview_box");
		if (anim_rect == null) {
			anim_rect = FlxRect.get(box.x,box.y,box.width,box.height);
		}
		
		if (entity_sprite == null) {
			entity_sprite = new EntitySprite(anim_rect.x, anim_rect.y, entity_graphics);
			add(entity_sprite);
			entity_sprite.x += (anim_rect.width - entity_sprite.width) / 2;
			entity_sprite.y += (anim_rect.height - entity_sprite.height) / 2;
			makeEntityClick();
		}
		
		box.resize(entity_sprite.width, entity_sprite.height);
		box.x = entity_sprite.x;
		box.y = entity_sprite.y;
		
		entity_sprite.loadAnimations(entity_graphics.animations);
		
		if(entity_graphics.animations.exists(anim)){
			entity_sprite.animation.play(anim);
		}
		
		if (spritesheet == null) {
			createSpriteSheet();
		}
		
		if (anim_preview == null) {
			
			var reg_animation:IFlxUIWidget = _ui.getAsset("reg_animation");
			
			anim_preview = new AnimationPreviewSprite(entity_sprite, entity_graphics.animations.get(anim), reg_animation.width, reg_animation.height,onClickAnimPreview);
			
			anim_preview.x = reg_animation.x;
			anim_preview.y = reg_animation.y;
			
			reg_animation.visible = false;
			
			underGroup.add(anim_preview);
		}else {
			anim_preview.showEntityAnimation(entity_sprite, entity_graphics.animations.get(anim));
		}
	}
	
	private function reloadState():Void {
		FlxG.switchState(new State_Animator());
	}
}