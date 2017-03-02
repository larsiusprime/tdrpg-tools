package;
import com.leveluplabs.tdrpg.ItemSpecial;
import com.leveluplabs.tdrpg.MapMarker;
import com.leveluplabs.tdrpg.Popup_Options_SubMenu;
import com.leveluplabs.tdrpg.enums.ItemClasses;
import com.leveluplabs.tdrpg.enums.Stat;
import firetongue.TSV;
import flixel.FlxG;
import flixel.FlxSprite;
import flixel.addons.ui.FlxUIButton;
import flixel.addons.ui.FlxUINumericStepper;
import flixel.addons.ui.FlxUIState;
import flixel.addons.ui.U;
import flixel.addons.util.PNGEncoder;
import flixel.util.FlxArrayUtil;
import flixel.util.FlxColor;
import haxe.Json;
import haxe.xml.Fast;
import haxe.xml.Printer;
import lime.ui.FileDialogType;
import openfl.display.BitmapData;
import org.zamedev.lib.Utf8Ext;
import sys.FileSystem;
import sys.io.File;
import unifill.Unifill;

/**
 * ...
 * @author 
 */
class State_ItemEdit extends FlxUIState
{

	private var bigIcon:FlxSprite;
	private var smallIcon:FlxSprite;
	private var menu:FlxUIButton;
	private var save:FlxUIButton;
	private var saveAs:FlxUIButton;
	private var delete:FlxUIButton;
	
	private var classBtn:ButtonWidget;
	private var typeBtn:ButtonWidget;
	private var costStepper:NumberWidget;
	private var nameBtn:ButtonWidget;
	private var blurbBtn:ButtonWidget;
	private var levelBtn:ButtonWidget;
	private var statWidget:NumberWidget;
	
	private var locStrs:Map<String,Map<String,String>>;
	private var titleMap:Map<String,String>;
	private var blurbMap:Map<String,String>;
	
	private var itemClass:String;
	private var itemType:String;
	private var itemLevel:String;
	private var itemID:String = "";
	private var itemLoadID:String = "";
	private var itemBonus:Float = 0;
	private var itemCost:Float = 0;
	
	private var itemSpecial:ItemSpecial;
	
	private var special1:ItemSpecialWidget;
	private var special2:ItemSpecialWidget;
	
	private var hasArt:Bool = false;
	private var hasArtBig:Bool = false;
	
	private var dirty(default, set):Bool = false;
	
	public function new(theID:String) 
	{
		itemID = Util.fixID(theID);
		itemLoadID = Util.fixID(theID);
		
		super();
	}
	
	private function set_dirty(b:Bool){
		dirty = b;
		if (save != null){
			if (b == true){
				save.label.text = "Save*";
				saveAs.label.text = "Save As*";
			}else{
				save.label.text = "Save";
				saveAs.label.text = "Save As";
			}
		}
		return dirty;
	}
	
	
	override public function getEvent(id:String, sender:Dynamic, data:Dynamic, ?params:Array<Dynamic>):Void 
	{
		super.getEvent(id, sender, data, params);
		if (id == "dirty"){
			dirty = true;
		}
		else if (id == FlxUINumericStepper.CHANGE_EVENT){
			dirty = true;
		}
	}
	
	private function loadItem(){
		
		var modPath = Util.dataFetcher.modPath;
		
		var itemNode:Fast = Util.loadItemNode(itemID);
		
		var isNew = false;
		
		var specialStr:String = "";
		if (itemNode != null){
			itemClass = itemNode.name.toLowerCase();
			itemType = U.xml_str(itemNode.x, "type", true);
			itemLevel = U.xml_str(itemNode.x, "level", true);
			itemBonus = U.xml_f(itemNode.x, "bonus");
			itemCost = U.xml_f(itemNode.x, "cost");
			specialStr = U.xml_str(itemNode.x, "special", true, "");
		}
		else{
			itemClass = "weapon";
			itemType = "sword";
			itemLevel = "untitled";
			itemBonus = 0;
			itemCost = 0;
			specialStr = "";
			isNew = true;
		}
		
		if (specialStr == "" || specialStr == null){
			itemSpecial = new ItemSpecial();
			itemSpecial.abilities = [];
		}else{
			var json = Json.parse(specialStr);
			itemSpecial = ItemSpecial.fromJSON(json);
		}
		
		var locPath = Util.safePath(modPath, "_append/locales");
		Util.ensurePath(locPath);
		
		var tongue = Util.dataFetcher.tongue;
		for (t in tongue.locales){
			var tPath = Util.safePath(locPath, t);
			Util.ensurePath(tPath);
			var iPath = Util.safePath(tPath, "items.tsv");
			if (FileSystem.exists(iPath) == false){
				File.saveContent(iPath, "flag	name	description");
			}
			
			var titles = Util.dataFetcher.getStrMap("$ITM_CUSTOM_" + itemID.toUpperCase(), "items.tsv", 1);
			var blurbs = Util.dataFetcher.getStrMap("$ITM_CUSTOM_" + itemID.toUpperCase(), "items.tsv", 2);
			
			locStrs = new Map<String,Map<String,String>>();
			
			locStrs.set("title", titles);
			locStrs.set("blurb", blurbs);
			
			if (isNew){
				titles.set("en-US", "???");
				blurbs.set("en-US", "???");
			}
		}
	}
	
	override public function create():Void 
	{
		super.create();
		
		loadItem();
		
		var bkg = new FlxSprite().makeGraphic(1, 1);
		bkg.scale.set(FlxG.width, FlxG.height);
		bkg.updateHitbox();
		add(bkg);
		
		var box = Util.makeBox(130, 130, FlxColor.WHITE);
		box.x = 10;
		box.y = 10;
		add(box);
		
		var boxBtn = new ButtonWidget(box.x-2, box.y+box.height+2, box.width+4, 60, "Big icon", "Change...", onChangeBigIcon);
		add(boxBtn);
		
		var box2 = Util.makeBox(66, 66, FlxColor.WHITE);
		box2.x = box.x + box.width + 10;
		box2.y = box.x + box.height - box2.height;
		add(box2);
		
		var box2Btn = new ButtonWidget(box2.x-2, box2.y+box2.height+2, box2.width+4, 60, "Small icon", "Change...", onChangeSmallIcon);
		add(box2Btn);
		
		bigIcon = new FlxSprite(box.x + 2, box.y + 2, "*assets/gfx/_hd/editor/" + itemClass + "_" + itemType + "_big.png");
		smallIcon = new FlxSprite(box2.x + 2, box2.y + 2, "*assets/gfx/_hd/editor/" + itemClass + "_" + itemType+".png");
		bigIcon.scale.set(2, 2);
		smallIcon.scale.set(2, 2);
		bigIcon.updateHitbox();
		smallIcon.updateHitbox();
		
		add(bigIcon);
		add(smallIcon);
		
		menu = Util.makeBtn(0, 5, "Main Menu", onMainMenu);
		menu.x = FlxG.width - (menu.width+5);
		add(menu);
		
		save = Util.makeBtn(0, Std.int(menu.y + menu.height + 5), "Save", onSave);
		save.x = menu.x;
		add(save);
		
		saveAs = Util.makeBtn(0, Std.int(save.y + save.height + 5), "Save As", onSaveAs);
		saveAs.x = menu.x;
		add(saveAs);
		
		delete = Util.makeBtn(0, Std.int(saveAs.y + saveAs.height + 5), "Delete", onDelete);
		delete.x = menu.x;
		add(delete);
		
		classBtn = new ButtonWidget(box2Btn.x + box2Btn.width + 5, box2Btn.y, 100, 60, "Item Class", itemClass, onItemClass);
		add(classBtn);
		
		typeBtn = new ButtonWidget(classBtn.x + classBtn.width + 5, classBtn.y, 100, 60, "Item Type", itemType, onItemType);
		add(typeBtn);
		
		statWidget = getStatWidget();
		
		titleMap = locStrs.get("title");
		blurbMap = locStrs.get("blurb");
		
		costStepper = new NumberWidget(statWidget.x + statWidget.width + 5, statWidget.y, 100, "Cost", 100, itemCost, 0, 9999999999);
		add(costStepper);
		
		var itemIDStripped = Util.stripID(itemID);
		levelBtn = new ButtonWidget(costStepper.x + costStepper.width + 5, costStepper.y, 100, 60, "Identifier", itemIDStripped, onID);
		add(levelBtn);
		
		nameBtn = new ButtonWidget(levelBtn.x + levelBtn.width + 5, costStepper.y, 100, 60, "Name", "...", onName);
		add(nameBtn);
		
		blurbBtn = new ButtonWidget(nameBtn.x + nameBtn.width + 5, costStepper.y, 100, 60, "Description", "...", onBlurb);
		add(blurbBtn);
		
		fixItemType();
		
		var itemPath = Util.safePath(Util.dataFetcher.modPath, "gfx/_hd/items/custom");
		
		if (FileSystem.exists(itemPath)){
			var bigPath = Util.safePath(itemPath, itemID + "_big.png");
			var smallPath = Util.safePath(itemPath, itemID + ".png");
			if (FileSystem.exists(bigPath)){
				var bigItem = BitmapData.fromFile(bigPath);
				bigIcon.loadGraphic(bigItem);
				hasArtBig = true;
			}
			if (FileSystem.exists(smallPath)){
				var smallItem = BitmapData.fromFile(smallPath);
				smallIcon.loadGraphic(smallItem);
				hasArt = true;
			}
		}
		
		special1 = new ItemSpecialWidget(bigIcon.x, bigIcon.y + bigIcon.height + 120, null);
		special2 = new ItemSpecialWidget(bigIcon.x, special1.y + special1.height + 10, null);
		
		var spec1 = itemSpecial.abilities != null && itemSpecial.abilities.length > 0 ? itemSpecial.abilities[0] : null;
		var spec2 = itemSpecial.abilities != null && itemSpecial.abilities.length > 1 ? itemSpecial.abilities[1] : null;
		
		special1.sync(spec1);
		special2.sync(spec2);
		
		add(special1);
		add(special2);
	}
	
	private function onSaveAs(){
		
		var popup = new TextPopup(Util.stripID(itemID), "Item ID", function(str:String){
			
			str = Utf8Ext.toLowerCase(str);
			
			var node = Util.loadItemNode(Util.fixID(str));
			
			if (node != null){
				
				var popup = new YesNoPopup("Confirm overwrite", "An existing item was found with ID \""+str+"\"\nOverwrite it?", function(b:Bool){
					
					if (b){
						
						itemID = Util.fixID(str);
						itemLoadID = Util.fixID(str);
						onSave();
						
					}
					
				});
				
				openSubState(popup);
				
			}else{
			
				itemID = Util.fixID(str);
				itemLoadID = Util.fixID(str);
				onSave();
			
			}
			
		}, true, true);
		
		openSubState(popup);
		
	}
	
	private function onDelete(){
		
		var popup = new YesNoPopup("Delete item '" + itemID + "'?", "Are you sure?", function(f:Bool){
			
			if (f){
				doDelete();
			}
			
		});
		openSubState(popup);
		
	}
	
	private function doDelete(){
		
		itemID = itemLoadID;
		
		var modPath = Util.dataFetcher.modPath;
		var imgPath:String = Util.safePath(modPath, "gfx/_hd/items/custom");
		Util.ensurePath(imgPath);
		
		var bigPath = Util.safePath(imgPath, itemID.toLowerCase() + "_big.png");
		var smallPath = Util.safePath(imgPath, itemID.toLowerCase() + ".png");
		
		if (FileSystem.exists(bigPath)){
			FileSystem.deleteFile(bigPath);
		}
		if (FileSystem.exists(smallPath)){
			FileSystem.deleteFile(smallPath);
		}
		
		var titles = locStrs.get("title");
		var blurbs = locStrs.get("blurb");
		
		var tongue = Util.dataFetcher.tongue;
		
		//save localization text information
		for (loc in tongue.locales){
			
			var locPath = Util.safePath(modPath, "_append/locales/"+loc+"/items.tsv");
			if (!FileSystem.exists(locPath)){
				File.saveContent(locPath, "flag	name	description");
			}
			var tsvStr:String = File.getContent(locPath);
			
			var flag = "$ITM_CUSTOM_" + itemID.toUpperCase();
			
			tsvStr = Util.removeFromTSV(tsvStr, flag);
			
			File.saveContent(locPath, tsvStr);
		}
		
		var itemPath = Util.safePath(modPath, "_append/xml/items.xml");
		var itemStr = FileSystem.exists(itemPath) ? File.getContent(itemPath) : "<data></data>";
		
		var itemXML = new Fast(Util.xmlify(itemStr));
		
		for (el in itemXML.elements){
			if (el.has.editor_id){
				var elID:String = U.xml_str(el.x, "editor_id", true);
				if (elID == itemLoadID){
					
					//remove clashing item entries if found
					itemXML.x.removeChild(el.x);
					
				}
			}
		}
		
		itemStr = Printer.print(itemXML.x, true);
		
		Util.ensurePath(itemPath);
		
		File.saveContent(itemPath, itemStr);
		
		onMainMenu();
	}
	
	private function onSave(){
		
		var modPath = Util.dataFetcher.modPath;
		var imgPath:String = Util.safePath(modPath, "gfx/_hd/items/custom");
		Util.ensurePath(imgPath);
		
		var oldBigPath = Util.safePath(imgPath, itemLoadID.toLowerCase() + "_big.png");
		var oldSmallPath = Util.safePath(imgPath, itemLoadID.toLowerCase() + ".png");
		
		var bigPath = Util.safePath(imgPath, itemID.toLowerCase() + "_big.png");
		var smallPath = Util.safePath(imgPath, itemID.toLowerCase() + ".png");
		
		if (oldBigPath != bigPath){
			if (FileSystem.exists(oldBigPath)){
				FileSystem.deleteFile(oldBigPath);
			}
		}
		
		if (oldSmallPath != smallPath){
			if (FileSystem.exists(oldSmallPath)){
				FileSystem.deleteFile(oldSmallPath);
			}
		}
		
		//save custom graphics
		var bytes = PNGEncoder.encode(bigIcon.graphic.bitmap);
		File.saveBytes(bigPath, bytes);
		
		bytes = PNGEncoder.encode(smallIcon.graphic.bitmap);
		File.saveBytes(smallPath, bytes);
		
		var titles = locStrs.get("title");
		var blurbs = locStrs.get("blurb");
		
		var tongue = Util.dataFetcher.tongue;
		
		//save localization text information
		for (loc in tongue.locales){
			
			var locPath = Util.safePath(modPath, "_append/locales/"+loc+"/items.tsv");
			if (!FileSystem.exists(locPath)){
				File.saveContent(locPath, "");
			}
			var tsvStr:String = File.getContent(locPath);
			
			var title = titles.get(loc);
			var blurb = blurbs.get(loc);
			
			var flag = "$ITM_CUSTOM_" + itemID.toUpperCase();
			var oldFlag = "$ITM_CUSTOM_" + itemLoadID.toUpperCase();
			
			if (flag != oldFlag){
				tsvStr = Util.removeFromTSV(tsvStr, oldFlag);
			}
			
			tsvStr = Util.appendToTSV(tsvStr, flag, title, blurb);
			
			File.saveContent(locPath, tsvStr);
		}
		
		var itemPath = Util.safePath(modPath, "_append/xml/items.xml");
		
		var itemStr = FileSystem.exists(itemPath) ? File.getContent(itemPath) : "<data></data>";
		
		var theSpecial = getSpecialStr();
		
		var itemName = "$ITM_CUSTOM_" + itemID.toUpperCase() + "_NAME";
		var itemDescription = "$ITM_CUSTOM_" + itemID.toUpperCase() + "_DESCRIPTION";
		
		var itemXML = new Fast(Util.xmlify(itemStr));
		
		for (el in itemXML.elements){
			if (el.has.editor_id){
				var elID:String = U.xml_str(el.x, "editor_id", true);
				
				if (elID == itemLoadID){
					
					//remove clashing item entries if found
					itemXML.x.removeChild(el.x);
				}
			}
		}
		
		itemStr = Printer.print(itemXML.x, true);
		
		itemBonus = statWidget.stepper.value;
		
		itemCost = costStepper.stepper.value;
		
		//write new item entry to bottom of document
		var itemEntryStr = '<$itemClass editor_id="$itemID" type="$itemType" lvl="$itemID" bonus="$itemBonus" cost="$itemCost" name="$itemName" description="$itemDescription" special=\''+theSpecial+'\'/>';
		
		itemStr = Util.appendToXML(itemStr, Util.xmlify(itemEntryStr));
		itemStr = Util.uCat(Util.xmlHead(), itemStr);
		
		Util.ensurePath(itemPath);
		
		File.saveContent(itemPath, itemStr);
		
		levelBtn.button.label.text = Util.stripID(itemID);
		
		itemLoadID = itemID;
		
		dirty = false;
	}
	
	private function refreshItemSpecials(){
		
		if (itemSpecial == null){
			itemSpecial = new ItemSpecial();
			itemSpecial.abilities = [];
		}
		if (itemSpecial.abilities == null){
			itemSpecial.abilities = [];
		}
		
		itemSpecial.unique = false;  //TODO
		
		FlxArrayUtil.clearArray(itemSpecial.abilities);
		
		var abil = special1.getAbility();
		
		if (abil != null){ itemSpecial.abilities.push(abil); }
		abil = special2.getAbility();
		if (abil != null){ itemSpecial.abilities.push(abil); }
	}
	
	private function noSpecial():Bool{
		if (itemSpecial.unique) return false;
		if (itemSpecial.abilities != null){
			if (itemSpecial.abilities.length > 0){
				for (i in 0...itemSpecial.abilities.length){
					if (itemSpecial.abilities[i] != null) return false;
				}
			}
		}
		return true;
	}
	
	private function getSpecialStr():String{
		refreshItemSpecials();
		if (noSpecial())
		{
			return "";
		}
		var json:Dynamic = itemSpecial.toJSON();
		var str = Json.stringify(json, null, "\t");
		str = Util.escapeXML(str);
		return str;
	}
	
	private function onID(){
		
		var popup = new TextPopup(Util.stripID(itemID), "Item ID", function(str:String){
			
			itemLevel = str;
			itemID = Util.fixID(str);
			levelBtn.button.label.text = str;
			dirty = true;
			
		}, true, true);
		openSubState(popup);
	}
	
	private function onName(){
		
		var popup = new LocaleTextPopup(titleMap, "Item Name", function(map:Map<String,String>){
			
			fixItemType();
			dirty = true;
			
		});
		openSubState(popup);
	}
	
	private function onBlurb(){
		
		var popup = new LocaleTextPopup(blurbMap, "Item Description", function(map:Map<String,String>){
			
			fixItemType();
			dirty = true;
			
		});
		openSubState(popup);
	}
	
	private function getStatWidget():NumberWidget{
		
		var statWidgetValue = itemBonus;
		if (statWidget != null){
			statWidgetValue = statWidget.stepper.value;
			remove(statWidget,true);
			statWidget.destroy();
		}
		
		var ic = ItemClasses.fromString(itemClass);
		var stat:Stat = Util.dataFetcher.itemIndex.getPrimaryStat(ic, itemType);
		
		statWidget = new NumberWidget(typeBtn.x + typeBtn.width + 5, typeBtn.y, 100, stat, 1, statWidgetValue, 0, 9999, 0);
		add(statWidget);
		
		return statWidget;
	}
	
	private function fixItemType(){
		var types = getItemTypes();
		if(types.indexOf(itemType) == -1){
			itemType = types[0];
		}
		typeBtn.button.label.text = types[0];
		if (!hasArtBig){
			bigIcon.loadGraphic("*assets/gfx/_hd/editor/" + itemClass + "_" + itemType+"_big.png");
		}
		if (!hasArt){
			smallIcon.loadGraphic("*assets/gfx/_hd/editor/" + itemClass + "_" + itemType+".png");
		}
		getStatWidget();
		
		nameBtn.button.label.text = titleMap.get("en-US");
		blurbBtn.button.label.text = Util.uCat(Unifill.uSubstr(blurbMap.get("en-US"), 0, 10),"...");
	}
	
	private function onItemClass(){
		var popup = new TypePopup(["weapon", "armor", "accessory"], itemClass, function(str:String, category:String){
			
			itemClass = str;
			classBtn.button.label.text = itemClass;
			
			fixItemType();
			dirty = true;
			
		});
		openSubState(popup);
	}
	
	private function onItemType(){
		var types = getItemTypes();
		if (types == null) return;
		var popup = new TypePopup(types, itemType, function(str:String, category:String){
			
			itemType = str;
			fixItemType();
			typeBtn.button.label.text = itemType;
			dirty = true;
			
		});
		openSubState(popup);
	}
	
	private function getItemTypes():Array<String>{
		
		switch(itemClass){
			case "armor":
				return ["light", "heavy"];
			case "weapon":
				return ["sword", "staff", "bow"];
			case "accessory":
				return ["book"];
		}
		
		return null;
	}
	
	private function onMainMenu(){
		FlxG.switchState(new State_Start());
	}
	
	private function onChangeBigIcon(){
		
		Util.promptPath(function(str:String):Void{
			
			var error = true;
			if (FileSystem.exists(str) && str.indexOf(".png") != -1){
				var png = BitmapData.fromFile(str);
				if (png.width == 64 && png.height == 64){
					
					var gfx = FlxG.bitmap.add(png, "item_big_icon");
					bigIcon.loadGraphic(gfx);
					error = false;
					hasArtBig = true;
					dirty = true;
					
				}
			}
			
			if (error){
				Util.alert(this, "Error!", "Big icon must be a 64x64 png file!");
			}
			
		}, FileDialogType.OPEN);
		
	}
	
	private function onChangeSmallIcon(){
		
		Util.promptPath(function(str:String):Void{
			
			var error = true;
			if (FileSystem.exists(str) && str.indexOf(".png") != -1){
				var png = BitmapData.fromFile(str);
				if (png.width == 32 && png.height == 32){
					
					var gfx = FlxG.bitmap.add(png, "item_small_icon");
					smallIcon.loadGraphic(gfx);
					error = false;
					hasArt = true;
					dirty = true;
					
				}
			}
			
			if (error){
				Util.alert(this, "Error!", "Small icon must be a 32x32 png file!");
			}
			
		}, FileDialogType.OPEN);
	}
}