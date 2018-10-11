package;
import com.leveluplabs.tdrpg.CreatureAttackFlavor;
import com.leveluplabs.tdrpg.FlavorInteraction;
import com.leveluplabs.tdrpg.ItemSpecial;
import com.leveluplabs.tdrpg.ItemSpecial.SpecialAbility;
import com.leveluplabs.tdrpg.enums.Interaction;
import com.leveluplabs.tdrpg.enums.Operator;
import com.leveluplabs.tdrpg.enums.SpecialAbilityType;
import flixel.FlxG;
import flixel.addons.ui.FlxUI;
import flixel.addons.ui.FlxUIButton;
import flixel.addons.ui.FlxUIGroup;
import flixel.addons.ui.FlxUILine;
import flixel.addons.ui.FlxUIRegion;
import flixel.addons.ui.FlxUISprite;
import flixel.addons.ui.FlxUIState;
import flixel.addons.ui.interfaces.IFlxUIWidget;
import flixel.text.FlxText;
import flixel.util.FlxColor;
import flixel.util.FlxDestroyUtil;

/**
 * ...
 * @author 
 */
class ItemSpecialWidget extends FlxUIGroup
{
	public static inline var W:Int = 1250;
	public static inline var H:Int = 140;
	
	public var box:FlxUIGroup;
	public var chrome:FlxUISprite;
	public var special:SpecialAbility;
	
	private var data:SpecialAbility;
	
	public function new(X:Float=0,Y:Float=0,Data:SpecialAbility) 
	{
		super(X, Y);
		init();
		data = Data;
		sync("");
	}
	
	public function sync(?ability:SpecialAbility,?AbilityType:String){
		clearStuff();
		init();
		
		var type = ability != null ? Std.string(ability.type) : "nothing";
		if (type == "nothing" && AbilityType != null){
			type = AbilityType;
		}
		type = type.toLowerCase();
		
		var last:IFlxUIWidget = new FlxUISprite(10, 20);
		last.visible = false;
		add(cast last);
		last = makeButton(last, "special", "Special", "...", 120);
		
		getBtn("special").button.label.text = type;
		
		if(type != "nothing"){
			last = makeNumber(last, "psi_tax", "PSI Tax", 0.01, 0.00, 0.00, 1.00, 2, true);
			last = makeButton(last, "difficulty", "If difficulty is", "any");
		}else{
			return;
		}
		
		if (ability != null){
			getNum("psi_tax").stepper.value = ability.psiTax;
			getBtn("difficulty").button.label.text = ability.difficulty;
		}
		
		var stype:SpecialAbilityType = type;
		
		switch(stype){
			case STRONG:
				makeStrong(last, abilStrong(ability));
			case THORNS:
				makeThorns(last, abilThorns(ability));
			case STAT:
				makeStat(last, abilStat(ability));
			case AUGMENT_FLAVOR:
				makeAugmentFlavor(last, abilAugment(ability));
			case ADD_FLAVOR:
				makeAddFlavor(last, abilFlavor(ability));
			default:
				//whatever
			/*
			case AUGMENT_SPELL:
			case REPLACE_SPELL:
			case TRIGGER_HIT:
			case ALL_FLAVOR:
			case RANDOM_FLAVOR:
			case RULE:
			case PLACE_INTERACTIVE:
			*/
		}
	}
	
	private static inline function abilStrong (a:SpecialAbility):SpecialStrong       { if (Std.is(a, SpecialStrong       )) return cast a; return null; }
	private static inline function abilThorns (a:SpecialAbility):SpecialThorns       { if (Std.is(a, SpecialThorns       )) return cast a; return null; }
	private static inline function abilStat   (a:SpecialAbility):SpecialStat         { if (Std.is(a, SpecialStat         )) return cast a; return null; }
	private static inline function abilAugment(a:SpecialAbility):SpecialAugmentFlavor{ if (Std.is(a, SpecialAugmentFlavor)) return cast a; return null; }
	private static inline function abilFlavor (a:SpecialAbility):SpecialAddFlavor    { if (Std.is(a, SpecialAddFlavor    )) return cast a; return null; }
	
	private function updateStatAmount(stat:String){
		
		var num = getNum("amount");
		
		var stepSize:Float = 0;
		var decimals:Int = 1;
		var min:Float = 0;
		var max:Float = 1;
		var value:Float = 0;
		var isPercent:Bool = false;
		
		switch(stat){
			case "attack","defense_abs":
				stepSize = 1;
				decimals = 0;
				min = 0;
				max = 999999;
				value = 0;
				isPercent = false;
			case "range":
				stepSize = 0.01;
				decimals = 2;
				min = 0;
				max = 25;
				value = 1.0;
				isPercent = false;
			case "regen_abs":
				stepSize = 1;
				decimals = 0;
				min = 0;
				max = 999999;
				value = 0;
				isPercent = false;
			case "dodge":
				stepSize = 0.01;
				decimals = 2;
				min = 0;
				max = 1.0;
				value = 0;
				isPercent = true;
			case "attack_speed":
				stepSize = 0.01;
				decimals = 2;
				min = 0;
				max = 1.0;
				value = 1.0;
				isPercent = true;
		}
		
		num.stepper.stepSize = stepSize;
		num.stepper.decimals = decimals;
		num.stepper.min = min;
		num.stepper.max = max;
		num.stepper.isPercent = isPercent;
		num.stepper.value = value;
	}
	
	public function getAbility():SpecialAbility{
		
		var special = getStr("special");
		var psi_tax = getFloat("psi_tax");
		var diff = getStr("difficulty");
		
		var stype:SpecialAbilityType = special;
		
		var data:SpecialAbility = null;
		
		switch(stype){
			case STRONG:
				var strong = new SpecialStrong();
				data = strong;
				strong.interaction = new FlavorInteraction(getStr("strong_flavor"), Interaction.fromString(getStr("strong_interaction")), getFloat("strong_amount"));
			case THORNS:
				var thorns = new SpecialThorns();
				data = thorns;
				thorns.amount = getFloat("thorns_amount");
				thorns.rate = getFloat("thorns_rate");
				thorns.flavor = getFlavor("thornsflavor");
			case STAT:
				var stat = new SpecialStat();
				data = stat;
				stat.stat = getStr("stat");
				stat.operator = getStr("stat_operator");
				stat.amount = getFloat("stat_amount");
			case AUGMENT_FLAVOR:
				var augment = new SpecialAugmentFlavor();
				data = augment;
				augment.flavor = getStr("augment_flavor");
				augment.vs_type = getStr("augment_vstype");
				var opval = getOperatorValueMap("augment");
				augment.valueMap = opval.values;
				augment.operatorMap = opval.operators;
			case ADD_FLAVOR:
				var add = new SpecialAddFlavor();
				data = add;
				add.flavor = getFlavor("add");
			default:
				//whatever
			/*
			case AUGMENT_SPELL:
			case REPLACE_SPELL:
			case TRIGGER_HIT:
			case ALL_FLAVOR:
			case RANDOM_FLAVOR:
			case RULE:
			case PLACE_INTERACTIVE:
			*/
		}
		
		if (data != null){
			data.difficulty = diff;
			data.type = special;
			data.psiTax = psi_tax;
			data.noDescription = false;
		}
		
		return data;
		
	}
	
	private function makeStat(last:IFlxUIWidget, ?abil:SpecialStat, withBox:Bool=true):IFlxUIWidget{
		
		var firstX = nextX(last);
		
		last = makeButton(last, "stat", "Stat", "attack");
		
		last.x += 5;
		
		last = makeButton(last, "stat_operator", "Operator", "x");
		last = makeNumber(last, "stat_amount", "Amount", 1, 1.1, 0, 999999, 1);
		
		if (abil != null){
			getBtn("stat").button.label.text = Std.string(abil.stat).toLowerCase();
			getBtn("stat_operator").button.label.text = Operator.toSymbol(abil.operator);
			getNum("stat_amount").stepper.value = abil.amount;
		}
		
		var lastX = nextX(last) + 2;
		
		if(withBox){
			var box = Util.makeBox(lastX - firstX, H);
			box.x = firstX;
			box.alpha = 0.25;
			add(box);
		}
		return last;
	}
	
	private function makeAugmentFlavor(last:IFlxUIWidget, ?abil:SpecialAugmentFlavor){
		
		var firstX = nextX(last) - 2;
		
		last = makeButton(last, "augment_flavor", "Flavor", "poison");
		
		last.x += 5;
		
		last = makeMath(last, "augment_amount", "Amount", 0.01, 0.10, 0.00, 100.00, 2);
		last = makeMath(last, "augment_rate", "Chance", 0.01, 0.10, 0.00, 1.00, 2, true);
		last = makeMath(last, "augment_time", "Seconds", 0.1, 0.10, 0.00, 9999, 1, false);
		last = makeButton(last, "augment_vstype", "Vs. type:", "any");
		//last = makeMath(last, "augment_amount2", "Amount2", 0.01, 0.00, 0.00, 100.00, 2, false);
		
		if (abil != null){
			getBtn("augment_flavor").button.label.text = Std.string(abil.flavor).toLowerCase();
			getBtn("augment_vstype").button.label.text = Std.string(abil.vs_type).toLowerCase();
			
			for (key in abil.valueMap.keys()){
				if (abil.operatorMap.exists(key)){
					var op = Operator.toSymbol(abil.operatorMap.get(key));
					var val = abil.valueMap.get(key);
					
					var math:MathWidget = switch(key){
						case "amount": getMath("augment_amount");
						case "rate": getMath("augment_rate");
						case "time": getMath("augment_time");
						//case "amount2": getMath("augment_amount2");
						default: null;
					}
					
					if (math != null){
						math.operation.label.text = op;
						math.stepper.value = val;
					}
				}
			}
		}
		
		var lastX = nextX(last) + 2;
		
		var box = Util.makeBox(lastX - firstX, H);
		box.x = firstX;
		box.alpha = 0.25;
		add(box);
		
		return last;
	}
	
	private function parentEvent(id:String, sender:IFlxUIWidget, data:Dynamic, ?params:Array<Dynamic>)
	{
		var state = FlxG.state;
		if (Std.is(state, FlxUIState)){
			cast(state, FlxUIState).getEvent(id, sender, data, params);
		}
	}
	
	private function makeThorns(last:IFlxUIWidget, ?abil:SpecialThorns){
		
		var firstX = nextX(last) - 2;
		
		last = makeNumber(last, "thorns_amount", "Reflected DMG", 0.01, 0.10, 0.00, 10.00, 2, true);
		
		last.x += 5;
		
		last = makeNumber(last, "thorns_rate", "Chance", 0.01, 0.10, 0.00, 1.00, 2, true);
		
		var lastX = nextX(last) + 2;
		
		var box = Util.makeBox(lastX - firstX, H);
		box.x = firstX;
		box.alpha = 0.25;
		add(box);
		
		/***********/
		
		firstX = nextX(last) - 2;
		
		last = makeButton(last, "thornsflavor_flavor", "Flavor", "poison");
		
		last.x += 5;
		
		var flav = last;
		
		last = makeButton(last, "thornsflavor_vstype", "Vs. type:", "any");
		last.x = flav.x;
		last.y = flav.y + flav.height + 5;
		
		last = flav;
		
		last = makeNumber(last, "thornsflavor_amount", "Amount", 0.01, 0.10, 0.00, 100.00, 2);
		
		
		last = makeNumber(last, "thornsflavor_rate", "Chance", 0.01, 0.10, 0.00, 1.00, 2, true);
		last = makeNumber(last, "thornsflavor_time", "Seconds", 0.1, 1.00, 0.00, 9999, 1);
		//last = makeNumber(last, "thornsflavor_amount2", "Amount2", 0.01, 0.00, 0.00, 100.00, 2);
		
		if (abil != null){
			getNum("thorns_amount").stepper.value = abil.amount;
			getNum("thorns_rate").stepper.value = abil.rate;
			if (abil.flavor != null){
				getBtn("thornsflavor_flavor").button.label.text = Std.string(abil.flavor.flavor).toLowerCase();
				getBtn("thornsflavor_vstype").button.label.text = getVsType(Std.string(abil.flavor.vs_type).toLowerCase());
				getNum("thornsflavor_amount").stepper.value = abil.flavor.amount;
				getNum("thornsflavor_rate").stepper.value = abil.flavor.rate;
				getNum("thornsflavor_time").stepper.value = abil.flavor.time;
				//getNum("thornsflavor_amount2").stepper.value = abil.flavor.amount2;
			}
		}
		
		var lastX = nextX(last) + 5;
		
		var box2 = Util.makeBox(lastX - (firstX+4), H);
		box2.x = firstX;
		box2.alpha = 0.25;
		add(box2);
		
		return last;
	}
	
	private function getVsType(str:String):String{
		if (str == null || str == "") return "any";
		return str;
	}
	
	private function makeAddFlavor(last:IFlxUIWidget, ?abil:SpecialAddFlavor){
		
		var firstX = nextX(last) - 2;
		
		last = makeButton(last, "add_flavor", "Flavor", "poison");
		
		last.x += 5;
		
		last = makeNumber(last, "add_amount", "Amount", 0.01, 0.10, 0.00, 100.00, 2);
		last = makeNumber(last, "add_rate", "Chance", 0.01, 0.10, 0.00, 1.00, 2, true);
		last = makeNumber(last, "add_time", "Seconds", 0.1, 1.00, 0.00, 9999, 1);
		//last = makeNumber(last, "add_amount2", "Amount2", 0.01, 0.00, 0.00, 100.00, 2);
		last = makeButton(last, "add_vstype", "Vs. type:", "any");
		
		if (abil != null && abil.flavor != null){
			getBtn("add_flavor").button.label.text = Std.string(abil.flavor.flavor).toLowerCase();
			getNum("add_amount").stepper.value = abil.flavor.amount;
			getNum("add_rate").stepper.value = abil.flavor.rate;
			getNum("add_time").stepper.value = abil.flavor.time;
			getBtn("add_vstype").button.label.text = getVsType(Std.string(abil.flavor.vs_type).toLowerCase());
			//getNum("add_amount2").stepper.value = abil.flavor.amount2;
		}
		
		var lastX = nextX(last) + 2;
		
		var box = Util.makeBox(lastX - firstX, H);
		box.x = firstX;
		box.alpha = 0.25;
		add(box);
		
		return last;
	}
	
	private function makeStrong(last:IFlxUIWidget, ?ability:SpecialStrong){
		
		var firstX = nextX(last) - 2;
		
		last = makeButton(last, "strong_flavor", "Vs. attack flavor", "physical");
		
		last.x += 5;
		
		last = makeButton(last, "strong_interaction", "Interaction", "damage_mult");
		var stepSize:Float = 0.01;
		var stepValue:Float = 0.50;
		var stepMin:Float =  0.00;
		var stepMax:Float =  10.00;
		var stepDec:Int = 2;
		
		last = makeNumber(last, "strong_amount", "Amount", stepSize, stepValue, stepMin, stepMax, stepDec);
		
		var lastX = nextX(last);
		
		var box = Util.makeBox(lastX - firstX, H);
		box.x = firstX;
		box.alpha = 0.25;
		add(box);
		
		if (ability != null){
			getBtn("strong_interaction").button.label.text = Std.string(ability.interaction.effect);
			getBtn("strong_flavor").button.label.text = ability.interaction.flavor;
			getNum("strong_amount").stepper.value = ability.interaction.amount;
		}
		
		return last;
	}
	
	private function makeMath(last:IFlxUIWidget, id:String, Label:String, StepSize:Float, Value:Float, Min:Float, Max:Float, Decimals:Int, IsPercent:Bool=false, Operator:String="+"){
		var math = new MathWidget(nextX(last), nextY(last), 100, Label, StepSize, Value, Min, Max, Decimals, IsPercent, Operator);
		math.name = id;
		add(math);
		return math;
	}
	
	private function makeNumber(last:IFlxUIWidget, id:String, Label:String, StepSize:Float, Value:Float, Min:Float, Max:Float, Decimals:Int, IsPercent:Bool=false){
		var num = new NumberWidget(nextX(last), nextY(last), 100, Label, StepSize, Value, Min, Max, Decimals, IsPercent);
		num.name = id;
		num.stepper.y += 10;
		num.label.y += 10;
		add(num);
		return num;
	}
	
	private function makeButton(last:IFlxUIWidget, id:String, Label:String, Value:String, Width:Float=100){
		var btn = new ButtonWidget(nextX(last), nextY(last), Width, 60, Label, Value, onBtn.bind(id));
		btn.name = id;
		add(btn);
		return btn;
	}
	
	private function nextX(widget:IFlxUIWidget):Float{ 
		if (widget == null) return 0;
		return (widget.x + widget.width + 5)-x;
	}
	private function nextY(widget:IFlxUIWidget):Float{ 
		if (widget == null) return 0;
		return widget.y-y;
	}
	
	private function getAsset(id:String):IFlxUIWidget{
		for (member in members){
			if (Std.is(member, IFlxUIWidget)){
				var widget:IFlxUIWidget = cast member;
				if (widget.name == id) return widget;
			}
		}
		return null;
	}
	
	private function getStr(id:String):String{
		var val = getValue(id);
		if (val == null) return "";
		return Std.string(getValue(id));
	}
	
	private function getOperatorValueMap(id:String):{operators:Map<String,Operator>,values:Map<String,Float>}
	{
		var operators = new Map<String,Operator>();
		var values = new Map<String,Float>();
		for (asset in members){
			if (Std.is(asset, MathWidget)){
				var mw:MathWidget = cast asset;
				if(mw.name.indexOf(id) == 0){
					var arr:Array<String> = mw.name.split("_");
					if(arr != null && arr.length > 1){
						var thing = arr[1];
						operators.set(thing, mw.operation.label.text);
						values.set(thing, mw.stepper.value);
					}
				}
			}
		}
		return {operators:operators, values:values};
	}
	
	private function getFlavor(id:String):CreatureAttackFlavor{
		var flavor = new CreatureAttackFlavor(
			getStr(id + "_flavor"), 
			getFloat(id + "_amount"), 
			getFloat(id + "_time"),
			getFloat(id + "_rate"), 
			getStr(id + "_vstype"),
			getFloat(id + "_amount2"), 
			getStr(id + "_iftarget")
		);
		return flavor;
	}
	
	private function getOperator(id:String):String{
		var asset = getAsset(id);
		
		if (Std.is(asset, MathWidget)){
			var mw:MathWidget = cast asset;
			return mw.operation.label.text;
		}
		
		return "+";
	}
	
	private function getFloat(id:String):Float{
		var val = getValue(id);
		if (val == null || !Std.is(val, Float)) return 0;
		return cast val;
	}
	
	private function getInt(id:String):Int{
		var val = getValue(id);
		if (val == null || !Std.is(val, Int)) return 0;
		return cast val;
	}
	
	private function getValue(id:String):Dynamic{
		var asset = getAsset(id);
		
		if (Std.is(asset, ButtonWidget)){
			var bw:ButtonWidget = cast asset;
			return bw.button.label.text;
		}else if (Std.is(asset, NumberWidget)){
			var nw:NumberWidget = cast asset;
			return nw.stepper.value;
		}else if (Std.is(asset, MathWidget)){
			var mw:MathWidget = cast asset;
			return mw.stepper.value;
		}
		
		return null;
	}
	
	private function getNum(id:String):NumberWidget{
		return cast(getAsset(id), NumberWidget);
	}
	
	private function getMath(id:String):MathWidget{
		return cast(getAsset(id), MathWidget);
	}
	
	private function getBtn(id:String):ButtonWidget{
		return cast(getAsset(id), ButtonWidget);
	}
	
	private function onBtn(type:String){
		var txt:FlxText = getBtn(type).button.label;
		
		var labels = null;
		var array =  null;
		
		var thing = "";
		if(type.indexOf("_") != -1){
			var typeArr = type.split("_");
			type = typeArr[1];
			thing = typeArr[0];
		}
		
		switch(type){
			case "special":
				array = ["defense:", "strong", "thorns", "general:", "stat", "augment_flavor", "add_flavor", "(remove the special):","nothing"];
				//'utility (stuff we used for books):', "augment_spell", "replace_spell", "trigger_hit", "rule", "all_flavor", "random_flavor", "place_interactive"];
			case "difficulty": 
				array = ["easy", "medium", "hard", "any"];
			case "interaction":
				array = ["damage_mult", "dodge", "save"];
			case "flavor":
				if (thing == "strong"){
					array = [
						"attack type:",
							"physical", "melee", "ranged", "physical-ranged", "area", "magic",
						"from enemy type:",
					];
					
					var enemies = Util.dataFetcher.getEnemyTypes();
					for (enemy in enemies){
						array.push("type_" + enemy);
					}
				}
				else{
					array = [
						"apply negative status effect with attack:",
							"chill", "slow", "freeze", "burn", "poison", "bleed", "blinded", "stun", "light", 
						"apply positive status effect with attack:",
							"dark", "frenzy", "dark_frenzy", "inspire",
						"apply bonus effect with attack:",
							"armor_pierce", "armor_break", "armor_ignore", "critical", "inspired_hit", "knock_back",
							"devour", "strike_through", "max_damage", "undodgeable", "disarm",
						"apply penalty effect with attack:",
							"psi_burn",
						/*
						"status debuff (special):", 
							"ever_bleed", "ever_poison", "single_stun", "reduce_health", "disease", "toxic", "ever_toxic",
						"joke:",
							"anonymous", "fb_happy", "fb_sad", "fb_bored", "fb_existential", "fb_lol", "fb_omg"
						*/
						];
				}
			case "stat":
				array = [
					"offense:",
						"attack","range","attack_speed",
					"defense:",
						"defense_abs","dodge","regen_abs",
					"vitals:",
						"hp","psi"
				];
			case "operator":
				array = ["+", "-", "x"];
			case "vstype":
				array = Util.dataFetcher.getEnemyTypes();
				array.push("any");
			default:
		}
		
		var popup = new TypePopup(array, txt.text, function(str:String, category:String){
			txt.text = str;
			
			switch(type){
				case "special": sync(str);
				case "operator": fixOperator(thing);
				case "stat": fixOperator("stat");
				case "interaction": fixInteraction(thing);
				case "strong": fixInteraction("strong");
			}
			parentEvent("dirty", null, this);
			
		},labels);
		
		Util.openPopup(popup);
	}
	
	private function fixInteraction(thing:String){
		
		var btn = getBtn(thing);
		var amount = getNum(thing + "_amount");
		var interact = getBtn(thing + "_interaction");
		
		var stepSize = 1.0;
		var decimals = 0;
		var min = 0.0;
		var max = 999999.0;
		var value = 0.0;
		var isPercent = false;
		
		var effect = interact.button.label.text;
		
		switch(effect){
			case "damage_mult","dodge","save":
				stepSize = 0.01;
				decimals = 2;
				min = 0;
				max = 10.0;
				value = 1.0;
		}
		
		switch(effect){
			
			case "save":
				amount.label.text = "If HP>X%, live";
				isPercent = true;
			case "damage_mult":
				amount.label.text = "Multiplier";
			case "dodge":
				amount.label.text = "Chance";
				isPercent = true;
		}
		
		amount.stepper.stepSize = stepSize;
		amount.stepper.decimals = decimals;
		amount.stepper.min = min;
		amount.stepper.max = max;
		amount.stepper.value = value;
		amount.stepper.isPercent = isPercent;
	}
	
	private function fixOperator(thing:String){
		
		var operator = getBtn(thing + "_operator");
		var amount = getNum(thing + "_amount");
		var btn = getBtn(thing);
		
		var op = operator.button.label.text;
		var thingVal = btn.button.label.text;
		
		var stepSize = 1.0;
		var decimals = 0;
		var min = 0.0;
		var max = 999999.0;
		var value = 0.0;
		var isPercent = false;
		
		switch(thing){
			
			case "stat":
				switch(thingVal){
					case "attack", "defense_abs", "regen_abs", "hp", "psi":
						switch(op){
							case "+","-":
								stepSize = 1;
								decimals = 0;
								min = 0;
								max = 999999;
								value = 1;
								isPercent = false;
							case "x":
								stepSize = 0.01;
								decimals = 2;
								min = 0;
								max = 100;
								value = 1.0;
						}
					case "dodge":
						switch(op){
							case "+", "-":
								stepSize = 0.01;
								decimals = 2;
								min = 0;
								max = 1.0;
								value = 1.0;
								isPercent = true;
							case "x":
								stepSize = 0.01;
								decimals = 2;
								min = 0;
								max = 100;
								value = 1.0;
						}
					case "attack_speed":
						switch(op){
							case "+", "-":
								stepSize = 0.01;
								decimals = 2;
								min = 0;
								max = 10.0;
								value = 1.0;
							case "x":
								stepSize = 0.01;
								decimals = 2;
								min = 0;
								max = 10;
								value = 1.0;
						}
					case "range":
						switch(op){
							case "+", "-":
								stepSize = 0.01;
								decimals = 2;
								min = 0;
								max = 25;
								value = 1.0;
							case "x":
								stepSize = 0.01;
								decimals = 2;
								min = 0;
								max = 10;
								value = 1.0;
						}
				}
		}
		
		amount.stepper.stepSize = stepSize;
		amount.stepper.isPercent = isPercent;
		amount.stepper.value = value;
		amount.stepper.min = min;
		amount.stepper.max = max;
		amount.stepper.decimals = decimals;
	}
	
	private function clearStuff(){
		
		if (members == null) return;
		
		FlxDestroyUtil.destroyArray(members);
		
		members = [];
	}
	
	override public function destroy():Void 
	{
		box = null;
		super.destroy();
	}
	
	
	private function init()
	{
		chrome = new FlxUISprite();
		chrome.makeGraphic(1, 1, FlxColor.WHITE);
		chrome.scale.set(W, H);
		chrome.updateHitbox();
		chrome.name = "chrome";
		add(chrome);
		box = makeBox(W, H);
		box.name = "box";
		add(box);
		
	}
	
	
	private function makeBox(W:Int, H:Int):FlxUIGroup{
		var top    = new FlxUILine(0, 0,     LineAxis.HORIZONTAL, W, 2, FlxColor.BLACK);
		var left   = new FlxUILine(0, 0,     LineAxis.VERTICAL  , H, 2, FlxColor.BLACK);
		var bottom = new FlxUILine(0, H - 2, LineAxis.HORIZONTAL, W, 2, FlxColor.BLACK);
		var right  = new FlxUILine(W - 2, 0, LineAxis.VERTICAL  , H, 2, FlxColor.BLACK);
		var g = new FlxUIGroup();
		g.add(top);
		g.add(left);
		g.add(right);
		g.add(bottom);
		return g;
	}
}
