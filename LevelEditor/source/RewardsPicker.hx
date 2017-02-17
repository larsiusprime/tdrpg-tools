package;
import flixel.FlxG;
import flixel.addons.ui.FlxUI;
import flixel.addons.ui.FlxUI9SliceSprite;
import flixel.addons.ui.FlxUIButton;
import flixel.addons.ui.FlxUIGroup;
import flixel.addons.ui.FlxUISubState;
import flixel.addons.ui.interfaces.IFlxUIState;
import flixel.util.FlxColor;

/**
 * ...
 * @author 
 */
class RewardsPicker extends FlxUISubState
{

	private var isBonus:Bool = false;
	private var isEndless:Bool = false;
	private var callback:RewardStruct->Void;
	private var rewardNum:Int = 0;
	
	private var goalBtn:ButtonWidget;
	private var typeBtn:ButtonWidget;
	private var valueBtn:ButtonWidget;
	private var typeBtnPlus:ButtonWidget;
	private var valueBtnPlus:ButtonWidget;
	
	private var reward:RewardStruct;
	
	public function new(IsBonus:Bool,IsEndless:Bool,i:Int,theReward:RewardStruct, Callback:RewardStruct->Void)
	{
		super(0xB0000000);
		
		isEndless = IsEndless;
		isBonus = IsBonus;
		callback = Callback;
		rewardNum = i;
		
		reward = theReward;
	}
	
	override public function create():Void 
	{
		super.create();
		if (isBonus){
			makeBonus();
		}
		else{
			close();
		}
	}
	
	override public function destroy():Void 
	{
		super.destroy();
		callback = null;
	}
	
	private function makeBonus(){
		
		var W:Int = Std.int(FlxG.width * 0.75);
		var H:Int = Std.int(FlxG.height * 0.25);
		
		var back = Util.makeBox(W, H, FlxColor.WHITE);
		var X:Int = Std.int((FlxG.width - back.width) / 2);
		var Y:Int = Std.int((FlxG.height - back.height) / 2);
		back.x = X;
		back.y = Y;
		add(back);
		
		var criterionLabel:String = "";
		var criterion:String = "";
		
		var freezeCriterion = false;
		
		if (isEndless){
			criterionLabel = "Reach wave #";
			
			criterion = reward.goal;
			
			var parsedInt:Null<Int> = Std.parseInt(reward.goal);
			if (parsedInt == null){
				parsedInt = 10;
			}
			criterion = Std.string(parsedInt);
			
		}else{
			freezeCriterion = true;
			criterionLabel = "Victory status";
			if (rewardNum == 1){
				criterion = "pass";
			}else{
				criterion = "perfect";
			}
		}
		
		var WW = Std.int((W / 5) - 10);
		var HH = Std.int(H  * 0.5);
		
		var YY = Y + Std.int(H / 3);
		goalBtn = new ButtonWidget(X + 5, YY, WW, HH, criterionLabel, criterion, onCriterion);
		add(goalBtn);
		
		if (freezeCriterion){
			goalBtn.active = false;
			goalBtn.alpha = 0.5;
		}
		
		typeBtn = new ButtonWidget(goalBtn.x + goalBtn.width + 5, YY, WW, HH, "Reward type", reward.type, onReward.bind("type"));
		valueBtn = new ButtonWidget(typeBtn.x + typeBtn.width + 5, YY, WW, HH, "Reward value", reward.value, onReward.bind("value"));
		typeBtnPlus = new ButtonWidget(valueBtn.x + valueBtn.width + 5, YY, WW, HH, "NG+ Reward type", reward.typePlus, onReward.bind("typePlus"));
		valueBtnPlus = new ButtonWidget(typeBtnPlus.x + typeBtnPlus.width + 5, YY, WW, HH, "NG+ Reward value", reward.valuePlus, onReward.bind("valuePlus"));
		
		add(typeBtn);
		add(valueBtn);
		add(typeBtnPlus);
		add(valueBtnPlus);
		
		var accept = Util.makeBtn(0, 0, "Accept", onAccept);
		accept.x = back.x + Std.int((back.width - accept.width) / 2);
		accept.y = back.y + back.height - accept.height - 5;
		add(accept);
		
		var cancel = Util.makeBtn(0, 0, "Cancel", onCancel);
		cancel.x = accept.x;
		cancel.y = accept.y;
		add(cancel);
		
		accept.x -= accept.width;
		cancel.x += cancel.width;
	}
	
	private function onCancel(){
		close();
	}
	
	private function onAccept(){
		var feat:String = "pass";
		var goal:String = "true";
		if (isBonus){
			if (isEndless){
				feat = "reach_wave";
				goal = goalBtn.button.label.text;
			}else{
				feat = goalBtn.button.label.text;
				goal = "true";
			}
		}
		else{
			feat = goalBtn.button.label.text;
			goal = "true";
		}
		
		callback({
			feat:feat,
			goal:goal,
			type:typeBtn.button.label.text,
			value:valueBtn.button.label.text,
			typePlus:typeBtnPlus.button.label.text,
			valuePlus:valueBtnPlus.button.label.text
		});
		close();
	}
	
	private function onReward(code:String){
		var theBtn:FlxUIButton = null;
		var otherBtn:FlxUIButton = null;
		var choices = [];
		var isValue = false;
		var isType = false;
		switch(code){
			case "type":
				theBtn = typeBtn.button;
				isType = true;
				otherBtn = valueBtn.button;
			case "typePlus":
				theBtn = typeBtnPlus.button;
				isType = true;
				otherBtn = valueBtnPlus.button;
			case "valuePlus":
				theBtn = valueBtnPlus.button;
				isValue = true;
				otherBtn = typeBtnPlus.button;
			case "value":
				theBtn = valueBtn.button;
				isValue = true;
				otherBtn = typeBtn.button;
		}
		if (isType){
			choices.push("xp");
			choices.push("gold");
			choices.push("item");
			choices.push("nothing");
			
			var currType = theBtn.label.text;
			var numVal = Std.parseFloat(otherBtn.label.text);
			var wasNumeric = false;
			if (Math.isNaN(numVal) == false){
				wasNumeric = true;
			}
			
			var popup = new TypePopup(choices, currType, function(str:String, category:String){
				theBtn.label.text = str;
				
				switch(str){
					case "xp", "gold":
						if (!wasNumeric){
							otherBtn.label.text = "100";
						}
					case "item":
						if (wasNumeric){
							otherBtn.label.text = "";
						}
					case "nothing":
						otherBtn.label.text = "";
				}
			});
			
			openSubState(popup);
		}
		else if (isValue){
			var type = otherBtn.label.text;
			switch(type){
				case "xp", "gold":
					var numValue = Std.parseFloat(theBtn.label.text);
					
					var popup = new NumberPopup(numValue, 0, 999999999999, 100, 0, type, function(f:Float){
						theBtn.label.text = Std.string(f);
					});
					
					openSubState(popup);
					
				case "item":
					var itemValue = theBtn.label.text;
					
					var parent:IFlxUIState = cast _parentState;
					var itemDetails:{names:Array<String>,labels:Array<String>} = parent.getRequest("items", null, "", null);
					var labels = [];
					
					for (i in 0...itemDetails.names.length){
						choices.push(itemDetails.names[i]);
						labels.push(itemDetails.labels[i]);
					}
					
					/*var labels = [];
					for (choice in choices){
						labels.push(choice.
					}*/
					
					if(choices.length > 0){
					
						var popup = new TypePopup(choices, itemValue, 
							function(str:String, category:String)
							{
								theBtn.label.text = str;
							}
						,labels);
						
						openSubState(popup);
						
					}else {
						
						Util.alert(this, "No items defined!", "You haven't defined any items! Create some in the item editor.");
						
					}
					
			}
		}
	}
	
	
	private function onCriterion(){
		
		var choices = [];
		
		if (isEndless){
			
			var currVal:Float = Std.parseFloat(goalBtn.button.label.text);
			if (Math.isNaN(currVal)){
				currVal = 100;
			}
			
			var popup = new NumberPopup(currVal, 0, 255, 1, 0, "Reach Wave #", function(f:Float){
				goalBtn.button.label.text = Std.string(f);
			});
			
			openSubState(popup);
			
		}else{
			choices.push("pass");
			choices.push("perfect");
			
			var popup = new TypePopup(choices, goalBtn.button.label.text, function(str:String, category:String){
				goalBtn.button.label.text = str;
			});
			
			openSubState(popup);
		}
	}
}

typedef RewardStruct = {
	feat:String,
	goal:String,
	type:String,
	value:String,
	typePlus:String,
	valuePlus:String
}