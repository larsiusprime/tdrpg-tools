package com.leveluplabs.tools.animator;
import com.leveluplabs.tools.animator.EntityGraphics.EntityColorLayer;
import com.leveluplabs.tools.animator.EntitySkin;
import flash.display.BitmapData;
import flash.geom.ColorTransform;
import flixel.addons.ui.StrIdLabel;
import flixel.addons.ui.U;
import flixel.util.FlxArrayUtil;
import flixel.util.FlxColor;
import flixel.util.FlxColorUtil;
import haxe.xml.Fast;
import openfl.Assets;

/**
 * All the data you need to make an EntitySprite
 * @author 
 */
class EntityGraphics
{
	public var name:String;								//string identifier
	
	/**
	 * The path to the file you want
	 */
	
	public var asset_src(get, null):String = "";
	public function get_asset_src():String {
		if (skin != null) {
			return skin.path + "/" + skin.asset_src;
		}
		return null;
	}
	
	/**
	 * The name of the currently selected EntitySkin. Set this to change it.
	 */
	
	public var skinName:String = "";			//currently selected skin
	
	/**
	 * The currently selected EntitySkin
	 */
	
	public var skin(get, null):EntitySkin;
	public function get_skin():EntitySkin {
		if (map_skins != null && map_skins.exists(skinName)) {
			return map_skins.get(skinName);
		}
		return null;
	}
	
	public var map_skins:Map<String,EntitySkin>;			//maps string identifiers ("hero") to skin data
	
	public var animations:Map<String,AnimationData>;		//animations
	
	public static inline var COLOR_CHANGE_NONE:Int = 0;
	public static inline var COLOR_CHANGE_LAYERS:Int = 1;
	public static inline var COLOR_CHANGE_PIXEL_PALETTE:Int = 2;
	
	/**
	 * Returns a unique identifier for the current skin (combination of asset file(s) + custom color rules)
	 */
	public var colorKey(get, null):String;
	public function get_colorKey():String
	{
		var key:String = U.gfx(asset_src);
		var i:Int = 0;
		var color:Int = 0;
		
		if (skin.color_change_mode == COLOR_CHANGE_LAYERS && skin.list_color_layers != null && skin.list_colors != null) 
		{
			for (layer in skin.list_color_layers) 
			{
				if(i < skin.list_colors.length){
					color = skin.list_colors[i];
					key += "+" + layer.asset_src + "#" + StringTools.hex(color, 6);
					//Returns e.g. "assets/gfx/defenders/dude+pants#FF0000+hat#0000FF+shirt#00FF00"
				}
				i++;
			}
		}
		else if (skin.color_change_mode == COLOR_CHANGE_PIXEL_PALETTE && skin.list_original_pixel_colors != null && skin.list_colors != null) 
		{
			for (color in skin.list_colors) 
			{
				key += "+" + "#" + StringTools.hex(color, 6);
				//Returns e.g. "assets/gfx/defenders/dude+#FF0000+#0000FF+#00FF00"
			}
		}
		return key;
	}
	
	public function new() 
	{
	
	}
	
	public function destroy():Void {
		//TODO
	}
	
	public function countSkins():Int 
	{
		var i:Int = 0;
		for(key in map_skins.keys()) {
			i++;
		}
		return i;
	}
	
	public function getDefaultSkin():EntitySkin 
	{
		for (key in map_skins.keys()) {
			var skin:EntitySkin = map_skins.get(key);
			if (skin.isDefault) {
				return skin;
			}
		}
		return null;								//this should never happen if everything works correctly
	}
	
	public function getAnimationList():Array<StrIdLabel> {
		var strIds:Array<StrIdLabel> = [];
		for (key in animations.keys()) {
			var strId:StrIdLabel = new StrIdLabel(key, key);
			strIds.push(strId);
		}
		strIds.sort(StrIdLabel.sortByLabel);
		return strIds;
	}
	
	public function getSkins():Array<EntitySkin>
	{
		var arr = [];
		for (key in map_skins.keys()) {
			arr.push(map_skins.get(key));
		}
		return arr;
	}
	
	public function getSkinNames():Array<String>
	{
		var arr = [];
		for (key in map_skins.keys()) {
			arr.push(map_skins.get(key).name);
		}
		return arr;
	}
	
	public function getSkinList():Array<StrIdLabel> {
		var strIds:Array<StrIdLabel> = [];
		for (key in map_skins.keys()) {
			var strId:StrIdLabel = new StrIdLabel(key, key);
			strIds.push(strId);
		}
		strIds.sort(StrIdLabel.sortByLabel);
		return strIds;
	}
	
	public function toXML():Fast {
		
		var root:Xml = Xml.createDocument();
		var xml:Fast = new Fast(root);
		
		var gfxXml:Xml = Xml.createElement("graphic");
		gfxXml.set("name", name);
		
		root.addChild(gfxXml);
		
		for (key in animations.keys()) {
			var anim:AnimationData = animations.get(key);
			var animXml:Xml = Xml.createElement("anim");
			animXml.set("name", anim.name);
			animXml.set("framerate", Std.string(anim.frameRate));
			animXml.set("looped", Std.string(anim.looped));
			for (i in 0...anim.frames.length) {
				var frameXml:Xml = Xml.createElement("frame");
				frameXml.set("value", Std.string(anim.frames[i]));
				if (anim.hasSweetSpot(i)) {
					var sweet:AnimSweetSpot = anim.getSweetSpot(i);
					frameXml.set("sweet", "true");
					if(sweet.x != 0){
						frameXml.set("x", Std.string(sweet.x));
					}
					if(sweet.y != 0){
						frameXml.set("y", Std.string(sweet.y));
					}
					if (sweet.name != "" && sweet.name != null) {
						frameXml.set("name", sweet.name);
					}
				}
				animXml.addChild(frameXml);
			}
			gfxXml.addChild(animXml);
		}
		
		for (key in map_skins.keys()) {
			var s:EntitySkin = map_skins.get(key);
			var skinXml:Fast = s.toXML();
			gfxXml.addChild(skinXml.x);
		}
		
		return xml;
	}
	
	public function fromXML(xml:Fast):Void {
		xml = xml.node.graphic;
		
		name = U.xml_str(xml.x, "name", true);
		
		_skinsFromXML(xml);
		_colorsFromXML(xml);
		_animsFromXML(xml);
	}
	
	/**
	 * Load all the color information for each skin from the xml
	 * @param	xml
	 */
	
	private function _colorsFromXML(xml:Fast):Void 
	{
		if (xml.hasNode.skin) 
		{
			for (skinNode in xml.nodes.skin)
			{
				var sName:String = U.xml_str(skinNode.x, "name");
				var s:EntitySkin = map_skins.get(sName);
				
				if (skinNode.hasNode.colors) 
				{
					
					//Determine the color change mode of this skin
					var mode:String = U.xml_str(skinNode.node.colors.x, "mode", true);
					
					if (mode == "layers") {
						s.color_change_mode = COLOR_CHANGE_LAYERS;
					}else if (mode == "pixels") {
						s.color_change_mode = COLOR_CHANGE_PIXEL_PALETTE;
					}else {
						s.color_change_mode = COLOR_CHANGE_NONE;
					}
					
					if (s.color_change_mode == COLOR_CHANGE_LAYERS)
					{
						var use_default:Bool = U.xml_bool(skinNode.node.colors.x, "use_default");
						
						if (use_default) {
							s.using_default_structure = true;
							//if it wants to use default layer structure, 
							//grab & copy that from the default skin
							var defaultSkin:EntitySkin = getDefaultSkin();
							
							s.list_color_layers = [];
							
							for (ecl in defaultSkin.list_color_layers) {
								s.list_color_layers.push(copyEntityColorLayer(ecl));
							}
						}
					}
					else if (s.color_change_mode == COLOR_CHANGE_PIXEL_PALETTE)
					{
						//Temporarily load the image
						//Scan the first vertical column in the first frame for palette information
						
						skinName = s.name;
						
						s.list_original_pixel_colors = [];
						
						var b:BitmapData = Assets.getBitmapData(U.gfx(asset_src),false);	//don't cache it, just peek at it
						if (b != null) {
							for (py in 0...b.height) {
								var pix_color:Int = b.getPixel32(0, py);
								if (FlxColorUtil.getAlpha(pix_color) == 0) {				//break on first 100% transparent pixel
									break;
								}
								s.list_original_pixel_colors.push(pix_color);
							}
						}
						
						//destroy bitmap data information (it's safe b/c we didn't cache it!)
						b.dispose();
						b = null;
					}
					
					//If color data is supplied in the skin
					if (skinNode.node.colors.hasNode.color) 
					{
						s.list_colors = [];
						
						//Loop through the color nodes
						for (colorNode in skinNode.node.colors.nodes.color) 
						{
							//Get color value
							var lValue = U.parseHex(U.xml_str(colorNode.x, "value", true, "0xffffffff"), true, true, 0x00000000);
							var index = U.xml_i(colorNode.x, "index", -1);
							
							var insert:Int = -1;
							
							if (index != -1) {
								insert = index;
							}
							
							if (s.color_change_mode == COLOR_CHANGE_LAYERS) 
							{
								//Get name value too
								var lName = U.xml_str(colorNode.x, "name", true, "");
								
								var i:Int = 0;
								
								//If a name is specified, try to match it to a color layer
								if (lName != "") 
								{
									if (s.list_color_layers != null) 
									{
										for (colorLayer in s.list_color_layers) 
										{
											if (colorLayer.name == lName) 
											{
												insert = i;
												break;
											}
											i++;
										}
									}
								}
								
								//Still can't find an insertion point? Default to the index value if it exists
								if (insert == -1 && index != -1) {
									insert = index;
								}
							}
							
							if (insert == -1) 						//no layer name was specified; just add the color in the order you found it
							{
								s.list_colors.push(lValue);
							}
							else									//a layer name was found and matched; add the color at this exact index
							{
								s.list_colors[insert] = lValue;
							}
						}
					}
					
					#if neko
						if (s.list_colors != null) {
							for (i in 0...s.list_colors.length) {
								if (s.list_colors[i] == null) {
									s.list_colors[i] = 0;
								}
							}
						}
					#end
					
					if (skinNode.node.colors.hasNode.feature)
					{
						//Create color feature structure if it exists
						s.list_color_features = [];
						
						for (featureNode in skinNode.node.colors.nodes.feature) 
						{
							var featName:String = U.xml_str(featureNode.x, "name", true);
							var featPalette:String = U.xml_str(featureNode.x, "palette", true);
							var colorList:Array<Int> = [];
							for (i in 0...16) {
								var str:String = U.xml_str(featureNode.x, "c" + i);
								if (str != "") {
									var cStr:Int = Std.parseInt(str);
									colorList.push(cStr);
								}
							}
							var feature:ColorFeature = new ColorFeature(featName, colorList, featPalette);
							s.list_color_features.push(feature);
						}
					}else {
						//Otherwise, check to see if it's using the default setup
						var use_default:Bool = U.xml_bool(skinNode.node.colors.x, "use_default");
						
						if (use_default) {
							s.list_color_features = [];
							//if it wants to use default feature structure, 
							//grab & copy that from the default skin
							var defaultSkin:EntitySkin = getDefaultSkin();
							if (defaultSkin.list_color_features != null) 
							{
								var colorFeature:ColorFeature;
								for (colorFeature in defaultSkin.list_color_features) 
								{
									if (colorFeature != null) {
										var colorFeatureCopy:ColorFeature = colorFeature.copy();
										s.list_color_features.push(colorFeatureCopy);
									}
								}
							}
						}
					}
				}
			}
		}
	}
	
	/**
	 * Load all the skin information from the xml
	 * @param	xml
	 */
	
	private function _skinsFromXML(xml:Fast):Void {
		if (xml.hasNode.skin) 
		{
			var firstSkin:String = "";
			
			if (map_skins == null) 
			{
				map_skins = new Map<String,EntitySkin>();
			}
			
			var count_default:Int = 0;
			
			for (skinNode in xml.nodes.skin)
			{
				//Get all the basic properties
				
				var sName = U.xml_str(skinNode.x, "name", true);
				if (firstSkin == "") { 
					firstSkin = sName;
				}
				
				var sAsset_src = U.xml_str(skinNode.x, "asset_src");
				var sPath= U.xml_str(skinNode.x, "path");
				var sWidth = U.xml_i(skinNode.x, "width");
				var sHeight= U.xml_i(skinNode.x, "height");
				var sOff_x = U.xml_i(skinNode.x, "off_x");
				var sOff_y = U.xml_i(skinNode.x, "off_y");
				var sIsDefault = U.xml_bool(skinNode.x, "default", false);
				
				//Check if this is the default skin
				if (sIsDefault) 
				{
					if (count_default == 0)
					{
						count_default++;
					}
					else 
					{
						sIsDefault = false;		//can't be more than one default! Ignore all "default" skins after 1st one set to default
					}
				}
				
				//Make the skin object
				var s:EntitySkin = new EntitySkin();
				s.name = sName;
				s.path = sPath;
				s.width = sWidth;
				s.height = sHeight;
				s.off_x = sOff_x;
				s.off_y = sOff_y;
				s.color_change_mode = COLOR_CHANGE_NONE;
				s.isDefault = sIsDefault;
				s.asset_src = sAsset_src;
				
				//Add the layer color structure if it exists
				if (skinNode.hasNode.colors && skinNode.node.colors.hasNode.layer) 
				{
					s.list_color_layers = [];
					s.list_colors = [];
					
					//Loop through the layer nodes
					for (layerNode in skinNode.node.colors.nodes.layer) 
					{
						var lName = U.xml_str(layerNode.x, "name", true, "");
						var lValue = U.parseHex(U.xml_str(layerNode.x, "value", true, "0xffffffff"), true, true, 0x00000000);
						var lAssetSrc = U.xml_str(layerNode.x, "asset_src");
						var lAlpha = U.xml_f(layerNode.x, "alpha", 1);
						var lSort = U.xml_i(layerNode.x, "sort", 0);
						
						//Create each color layer object
						var ecl:EntityColorLayer = {
							name:lName,
							asset_src:lAssetSrc,
							alpha:lAlpha,
							sort:lSort
						}
						
						//Add the color layer to the skin
						s.list_color_layers.push(ecl);
					}
					
					//Sort them correctly
					s.list_color_layers.sort(sortEntityColorLayers);
				}
				
				//Store the skin
				map_skins.set(sName, s);
			}
			
			//if no defaults are set, the first one is default
			if (count_default == 0)
			{
				for (key in map_skins.keys()) 
				{
					var skin:EntitySkin = map_skins.get(key);
					skin.isDefault = true;
					skinName = skin.name;
					break;
				}
			}
			
			//failsafe
			if (skinName == "")
			{
				skinName = firstSkin;
			}
		}
	}
	
	private function _animsFromXML(xml:Fast):Void {
		
		animations = new Map<String,AnimationData>();
		
		if (xml.hasNode.anim) {
			for (animNode in xml.nodes.anim) {
				var a:AnimationData = new AnimationData();
				a.name = U.xml_str(animNode.x, "name");
				a.looped = U.xml_bool(animNode.x, "looped");
				a.frameRate = U.xml_i(animNode.x, "framerate");
				if (animNode.hasNode.frame) {
					var i:Int = 0;
					for (frameNode in animNode.nodes.frame) {
						var frame:Int = U.xml_i(frameNode.x, "value", -1);
						if(frame != -1){
							a.frames.push(frame);
						}else{
							var frame_s:String = U.xml_str(frameNode.x, "range", true, "");
							if (frame_s != "" && frame_s.indexOf("-") != -1) {
								var arr:Array<String> = frame_s.split("-");
								var lo:Int = Std.parseInt(arr[0]);
								var hi:Int = Std.parseInt(arr[1]);
								for (fi in lo...hi+1) {
									a.frames.push(fi);
								}
							}
						}
						var sweet:String = U.xml_str(frameNode.x, "sweet", true);
						if (sweet != "") {
							var s_name:String = U.xml_str(frameNode.x, "name");
							var s_x:Float = U.xml_f(frameNode.x, "x", 0);
							var s_y:Float = U.xml_f(frameNode.x, "y", 0);
							var sweet:AnimSweetSpot = new AnimSweetSpot(s_name, s_x, s_y);
							a.setSweetSpot(i, sweet);
						}
						
						if(frame != -1){
							i++;
						}
					}
				}
				if (animNode.hasNode.sweet) {
					for (sweetNode in animNode.nodes.sweet) {
						var s_frame:Int = U.xml_i(sweetNode.x, "value");
						
					}
				}
				animations.set(a.name, a);
			}
		}
	}
	
	private function sortEntityColorLayers(a:EntityColorLayer, b:EntityColorLayer):Int {
		if (a.sort < b.sort) return -1;
		if (a.sort > b.sort) return 1;
		return 0;
	}
	
	public static function getColorTransform(?Trans:ColorTransform=null,Color:Int=0xffffff,Alpha:Float=1):ColorTransform {
		if (Trans == null) {
			Trans = new ColorTransform();
		}
		var red:Float = FlxColorUtil.getRed(Color);
		var green:Float = FlxColorUtil.getGreen(Color);
		var blue:Float = FlxColorUtil.getBlue(Color);
		Trans.redMultiplier = red / 255;
		Trans.greenMultiplier = green / 255;
		Trans.blueMultiplier = blue / 255;
		Trans.alphaMultiplier = Alpha;
		return Trans;
	}
	
	public static function copyEntityColorLayer(ecl:EntityColorLayer):EntityColorLayer 
	{
		var copy:EntityColorLayer = {
			name:ecl.name,
			asset_src:ecl.asset_src,
			alpha:ecl.alpha,
			sort:ecl.sort
		};
		return copy;
	}
}


typedef EntityColorLayer = {
	name:String,					//the user-facing name (or localization flag) of this color value, "Hair", "Pants"
	asset_src:String,				//mask asset filename sans extension
	alpha:Float,					//alpha value between 1 and 0
	sort:Int,						//sorting index
}