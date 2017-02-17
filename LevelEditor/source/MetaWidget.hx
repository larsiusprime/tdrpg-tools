package;
import com.leveluplabs.tdrpg.UI_Recruit.ColorSwatchStruct;
import flixel.FlxState;
import flixel.FlxSubState;
import flixel.addons.ui.FlxUI;
import flixel.addons.ui.FlxUIButton;
import flixel.addons.ui.FlxUICheckBox;
import flixel.addons.ui.FlxUIGroup;
import flixel.addons.ui.FlxUILine;
import flixel.addons.ui.FlxUIRadioGroup;
import flixel.addons.ui.FlxUISprite;
import flixel.addons.ui.FlxUIState;
import flixel.addons.ui.U;
import flixel.addons.ui.interfaces.IFlxUIWidget;
import flixel.util.FlxColor;
import RewardsPicker.RewardStruct;
import flixel.util.FlxTimer;
import BattleData.BonusStruct;

/**
 * ...
 * @author 
 */
class MetaWidget extends FlxUIGroup
{
	public static inline var W:Int = 700;
	public static inline var H:Int = 72;
	public static inline var H2:Int = 92;
	
	public var box:FlxUIGroup;
	public var meta:MetaEntry;
	public var project:ProjectData;
	
	public var difficulty:FlxUIRadioGroup;
	public var firstWait:NumberWidget;
	public var endless:FlxUICheckBox;
	public var endlessLevelup:NumberWidget;
	public var isBonus:FlxUICheckBox;
	
	private var rewardsButton1:ButtonWidget;
	private var rewardsButton2:ButtonWidget;
	private var bonusSettings:ButtonWidget;
	
	public var bonusStruct:BonusStruct;
	public var rewards1:RewardStruct;
	public var rewards2:RewardStruct;
	
	public static inline var LOCK_ISBONUS:Bool = true;
	
	public function new(X:Float=0,Y:Float=0) 
	{
		super(X, Y);
		init();
	}
	
	public function syncRewards(r1:RewardStruct, r2:RewardStruct){
		Util.matchRewards(rewards1, r1);
		Util.matchRewards(rewards2, r2);
		rewardsButton1.button.label.text = getRewardText(1);
		rewardsButton2.button.label.text = getRewardText(2);
		rewardsButton1.button.autoCenterLabel();
		rewardsButton2.button.autoCenterLabel();
	}
	
	public function syncBonus(bd:BonusStruct){
		
		bonusStruct.stars = bd.stars;
		bonusStruct.starsColor = bd.starsColor;
		bonusStruct.starsPlus = bd.starsPlus;
		bonusStruct.starsPlusColor = bd.starsPlusColor;
		bonusStruct.matchRewards(bd.rewards);
		
		syncRewards(bd.rewards[0], bd.rewards[1]);
		
		refreshBonusSettingsButton();
	}
	
	public function setBonus(b:Bool){
		meta.infos[0].isBonus = b;
		isBonus.checked = b;
		refreshRadios();
		isBonus.active = !LOCK_ISBONUS;
		isBonus.alpha = LOCK_ISBONUS ? 0.5 : 1.0;
	}
	
	public function sync(Meta:MetaEntry, refresh:Bool=true){
		meta = Meta;
		
		var i = Util.diffI(meta.difficulty);
		var info = meta.infos[i];
		
		difficulty.selectedId  = meta.difficulty;
		endlessLevelup.stepper.value = info.endlessLevelup;
		endless.checked = info.isEndless;
		endless.callback = function(){
			endlessLevelup.visible = endless.checked;
		};
		endlessLevelup.visible = endless.checked;
		isBonus.checked = info.isBonus;
		firstWait.stepper.value = info.firstWait;
		
		if(refresh){
			refreshRadios();
		}
	}
	
	override public function destroy():Void 
	{
		box = null;
		super.destroy();
	}
	
	public function write(meta:MetaEntry){
		if (meta == null) return;
		meta.difficulty = difficulty.selectedId;
		
		var i = switch(meta.difficulty){
			case "easy": 0;
			case "normal": 1;
			case "hard": 2;
			default: 0;
		}
		
		meta.infos[i].endlessLevelup = Std.int(endlessLevelup.stepper.value);
		meta.infos[i].isEndless = endless.checked;
		meta.infos[i].firstWait = firstWait.stepper.value;
		meta.infos[i].isBonus = isBonus.checked;
	}
	
	public function owns(widget:IFlxUIWidget){
		var fast = members.indexOf(cast widget) != -1;
		if (fast) return true;
		for (member in members){
			if (Std.is(member, FlxUIGroup)){
				var g:FlxUIGroup = cast member;
				if (g.members.indexOf(cast widget) != -1){
					return true;
				}
			}
		}
		return false;
	}
	
	private function init()
	{
		var chrome = new FlxUISprite();
		chrome.makeGraphic(1, 1, FlxColor.WHITE);
		chrome.scale.set(W, H2);
		chrome.updateHitbox();
		add(chrome);
		box = Util.makeBox(W, H2);
		add(box);
		
		rewards1 = {
			feat:"pass",
			goal:"true",
			type:"xp",
			value:"100",
			typePlus:"xp",
			valuePlus:"100"
		};
		
		rewards2 = {
			feat:"pass",
			goal:"true",
			type:"xp",
			value:"100",
			typePlus:"xp",
			valuePlus:"100"
		};
		
		bonusStruct = new BonusStruct();
		bonusStruct.stars = 0;
		bonusStruct.starsColor = "blue";
		bonusStruct.starsPlus = 0;
		bonusStruct.starsPlusColor = "blue";
		bonusStruct.rewards = [rewards1, rewards2];
		
		var Y = 20;
		
		difficulty = Util.makeRadios(5, 5, ["easy", "normal", "hard"], ["Normal", "Advanced", "Extreme"], 
			function(str:String){
				onDiffChange();
			}
		);
		difficulty.selectedId = "easy";
		add(difficulty);
		
		var ww = Std.int(H * 0.8);
		var dx = ww + 38;
		
		firstWait = new NumberWidget(100, Y, ww, "First wait", 0.1, 1.0, 0.0, 60.0, 1);
		add(firstWait);
		
		var X = 100 + dx;
		
		isBonus = Util.makeCheckbox(X, Y-10, "Is bonus level", onChange);
		add(isBonus);
		
		bonusSettings = new ButtonWidget(X, Y + 5, 100, 90, "Unlocks at", "...", onChangeBonusSettings);
		bonusSettings.labelOnTop();
		add(bonusSettings);
		
		X += dx + 25;
		
		endless = Util.makeCheckbox(X, Y-10, "Endless", onChange);
		add(endless);
		
		endlessLevelup = new NumberWidget(X, Y+15, ww, "Endless levelup", 1, 0, 0, 99, 0);
		add(endlessLevelup);
		
		X += dx;
		
		rewardsButton1 = new ButtonWidget(X, Y-10, 140, 110, "reward 1", getRewardText(1) , onChangeRewards.bind(1));
		add(rewardsButton1);
		
		X += dx + 50;
		
		rewardsButton2 = new ButtonWidget(X, Y-10, 140, 110, "reward 2", getRewardText(2) , onChangeRewards.bind(2));
		add(rewardsButton2);
	}
	
	private function getRewardText(i:Int):String{
		var reward:RewardStruct = null;
		switch(i){
			case 1: reward = rewards1;
			case 2: reward = rewards2;
		}
		if (reward != null){
			var str = "";
			if (reward.type != "item" && reward.type != "nothing"){
				if (reward.type == "xp")
				{
					str += reward.value + "xp";
				}
				if (reward.type == "gold")
				{
					str += "$" + reward.value;
				}
			}else if (reward.type == "item"){
				str += reward.value;
			}
			str += "\n";
			if (reward.typePlus != "item" && reward.typePlus != "nothing"){
				if (reward.typePlus == "xp")
				{
					str += reward.valuePlus + "xp";
				}
				if (reward.typePlus == "gold")
				{
					str += "$" + reward.valuePlus;
				}
			}else if (reward.typePlus == "item"){
				str += reward.valuePlus;
			}
			/*if (str.length > 28){
				str = str.substr(0, 28) + "...";
			}*/
			return str;
		}
		return "...";
	}
	
	private function onChangeBonusSettings(){
		
		var popup = new BonusSettingsPopup(bonusStruct.stars, bonusStruct.starsColor, bonusStruct.starsPlus, bonusStruct.starsPlusColor, function(stars:Float, starsColor:String, starsPlus:Float, starsPlusColor:String){
			
			bonusStruct.stars = Std.int(stars);
			bonusStruct.starsColor = starsColor;
			bonusStruct.starsPlus = Std.int(starsPlus);
			bonusStruct.starsPlusColor = starsPlusColor;
			
			refreshBonusSettingsButton();
			
			new FlxTimer().start(0.01,function(f:FlxTimer){
				FlxUI.event("bonus_change", null, bonusStruct);
			});
		});
		
		openPopup(popup);
	}
	
	private function refreshBonusSettingsButton(){
		
		var str = bonusStruct.stars + " " + bonusStruct.starsColor + "\n" + bonusStruct.starsPlus + " " + bonusStruct.starsPlusColor;
		bonusSettings.button.label.text = str;
		bonusSettings.button.autoCenterLabel();
	}
	
	private function onChangeRewards(i:Int){
		
		var theReward:RewardStruct = (i == 1) ? rewards1 : rewards2;
		
		var popup = new RewardsPicker(isBonus.checked, endless.checked, i, theReward, function(reward:RewardStruct){
			if (i == 1){
				rewards1 = reward;
				rewardsButton1.button.label.text = getRewardText(1);
				rewardsButton1.button.autoCenterLabel();
			}else{
				rewards2 = reward;
				rewardsButton2.button.label.text = getRewardText(2);
				rewardsButton2.button.autoCenterLabel();
			}
			onRewardChange([rewards1, rewards2]);
		});
		
		openPopup(popup);
	}
	
	private function openPopup(popup:FlxSubState){
		var s = FlxUI.getLeafUIState();
		if (Std.is(s, FlxState)){
			cast(s, FlxState).openSubState(popup);
		}else if (Std.is(s, FlxSubState)){
			cast(s, FlxSubState).openSubState(popup);
		}
	}
	
	private function onRewardChange(arr:Array<RewardStruct>){
		new FlxTimer().start(0.01,function(f:FlxTimer){
			FlxUI.event("reward_change", null, arr);
		});
	}
	
	private function onWaveChange(){
		FlxUI.event("wave_change", null, null);
	}
	
	private function onDiffChange(){
		var diff = difficulty.selectedId;
		meta.difficulty = diff;
		var i = Util.diffI(diff);
		sync(meta);
		refreshRadios();
		onWaveChange();
	}
	
	private function onChange(){
		if (meta == null) return;
		trace("WRITE");
		write(meta);
		refreshRadios();
	}
	
	private function refreshRadios()
	{
		if (meta.infos[0].isBonus){
			Util.activateRadios(difficulty, ["normal", "hard"], false);
			difficulty.selectedId = "easy";
			meta.difficulty = "easy";
			sync(meta, false);
			meta.infos[0].isBonus = true;
			isBonus.checked = true;
			onWaveChange();
		}else{
			Util.activateRadios(difficulty, ["easy", "normal", "hard"], true);
		}
	}
	
	override function set_visible(Value:Bool):Bool 
	{
		var vis = super.set_visible(Value);
		return vis;
	}
}

typedef MetaEntry =
{
	var difficulty:String;
	var infos:Array<MetaInfo>;
}

typedef MetaInfo = 
{
	var difficulty:String;
	var firstWait:Float;
	var endlessLevelup:Int;
	var isEndless:Bool;
	var isBonus:Bool;
}