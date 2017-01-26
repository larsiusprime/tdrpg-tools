package;

import flash.geom.Point;
import flixel.FlxG;
import flixel.FlxSprite;
import flixel.FlxState;
import flixel.text.FlxText;
import flixel.ui.FlxButton;
import flixel.math.FlxMath;
import flixel.util.FlxColor;

class MenuState extends FlxState
{
	public static var dq1:Settings;
	public static var dq2:Settings;
	
	private static var LAYER_X:Int = 5;
	private static var LAYER_Y:Int = 5;
	
	//public
	
	public var sigil:Int = 0;
	public var tool:Tool = Tool.Pencil;
	public var toolFlows:Bool = true;
	
	override public function create():Void
	{
		super.create();
		makeBkg();
		makeSettings();
		load(dq1);
	}
	
	override public function update(elapsed:Float):Void 
	{
		if (FlxG.keys.pressed.SPACE){
			tool = Bucket;
		}
		else{
			tool = Pencil;
		}
		
		if (FlxG.keys.justPressed.Z && FlxG.keys.pressed.CONTROL){
			undo();
		}
		
		if (FlxG.keys.justPressed.A)     doSigil(1);
		if (FlxG.keys.justPressed.B)     doSigil(2);
		if (FlxG.keys.justPressed.C)     doSigil(3);
		if (FlxG.keys.justPressed.D)     doSigil(4);
		if (FlxG.keys.justPressed.E)     doSigil(5);
		if (FlxG.keys.justPressed.ONE)   doSigil(6);
		if (FlxG.keys.justPressed.TWO)   doSigil(7);
		if (FlxG.keys.justPressed.THREE) doSigil(8);
		if (FlxG.keys.justPressed.FOUR)  doSigil(9);
		if (FlxG.keys.justPressed.FIVE)  doSigil(10);
		
		super.update(elapsed);
		updateInput(elapsed);
	}
	
	//private
	
	private var sigilSprite:FlxSprite;
	private var layers:Array<MapLayer>;
	private var data:Settings;
	private var maxUndo:Int = 100;
	private var undoBuffer:Array<EditState>;
	private var tempState:EditState;
	
	private function updateInput(elapsed:Float){
		
		for (i in 0...layers.length){
			var layer = layers[i];
			if (toolFlows && (tool != Bucket && tool != Turpentine)){
				if (layer.button.pressed){
					doInput(layer);
				}
				else if (layer.rightButton.pressed){
					doInput(layer, true);
				}
			}
			else{
				if (layer.button.justPressed){
					doInput(layer, false, true);
				}
				else if (layer.rightButton.justPressed){
					doInput(layer, true, true);
				}
			}
		}
	}
	
	private function doSigil(i:Int){
		sigil = i - 1;
		sigilSprite.animation.frameIndex = sigil;
	}
	
	private function doInput(layer:MapLayer, rightClick:Bool = false, justPressed:Bool=false){
		var change = false;
		tempState.sync(layers);
		
		if (!layer.editable)
		{
			if (layer.hasSigils){
				if (!rightClick)
				{
					change = layer.onSigilPlace(sigil);
				}
				else{
					change = layer.onSigilErase(sigil);
				}
			}
			return;
		}
		switch(tool){
			case Pencil:
				if(!rightClick){
					change = layer.onPencil();
				}
				else{
					change = layer.onEraser();
				}
			case Eraser:
				change = layer.onEraser();
			case Bucket:
				if (justPressed)
				{
					if(!rightClick){
						change = layer.onBucket();
					}
					else{
						change = layer.onTurpentine();
					}
				}
			case Turpentine:
				if (justPressed)
				{
					change = layer.onTurpentine();
				}
		}
		composite();
		
		if(change){
			pushUndo(tempState);
			tempState = new EditState(layers);
		}
	}
	
	private function undo(){
		if (undoBuffer == null || undoBuffer.length == 0) {
			return;
		}
		
		var state = undoBuffer.pop();
		var zpt = new Point();
		for (i in 0...layers.length){
			layers[i].sprite.graphic.bitmap.copyPixels(state.layers[i], state.layers[i].rect, zpt);
		}
	}
	
	private function pushUndo(state:EditState){
		if (undoBuffer.length >= maxUndo){
			undoBuffer.shift();
		}
		
		undoBuffer.push(state);
		
		for (i in 0...state.layers.length){
			FlxG.bitmapLog.add(state.layers[i], Std.string(i));
		}
	}
	
	private function composite(){
		var canvas = layers[0];
		var bmp = canvas.sprite.graphic.bitmap;
		
		bmp.fillRect(bmp.rect, FlxColor.BLACK);
		
		var zpt = new Point();
		
		for (i in 1...layers.length){
			var layer = layers[i];
			var lbmp = layer.sprite.graphic.bitmap;
			bmp.copyPixels(lbmp, lbmp.rect, zpt, null, null, true);
		}
	}
	
	private function load(settings:Settings){
		
		data = settings;
		undoBuffer = [];
		
		layers = [];
		makeLayer(0xFF000000,  0, "composite", false);
		makeLayer(0xFFFFFFFF,  1, "legal");
		makeLayer(0xFFFF0000,  2, "illegal");
		makeLayer(0xFF0000FF,  3, "water");
		
		layers[0].hasSigils = true;
		
		sigilSprite = new FlxSprite();
		sigilSprite.loadGraphic("assets/gfx/_hd/tiles/sigils.png", true, 64, 64);
		sigilSprite.x = FlxG.width - sigilSprite.width;
		sigilSprite.y = FlxG.height - sigilSprite.height;
		add(sigilSprite);
		
		tempState = new EditState(layers);
	}
	
	private function makeLayer(color:FlxColor, layer:Int, value:String, editable:Bool=true)
	{
		var l = new MapLayer(data.squaresWide, data.squaresTall, color, layer, value, editable);
		layers.push(l);
		
		l.x = Std.int(LAYER_X + (l.sprite.width + 5) * layer);
		l.y = LAYER_Y;
		
		l.addTo(this);
	}
	
	private function makeSettings(){
		dq1 = new Settings();
		dq2 = new Settings();
		
		dq1.tilesetStyle = "dq1";
		dq1.tilesPerSquare = 2;
		dq1.squaresWide = 15;
		dq1.squaresTall = 14;
		
		dq2.tilesetStyle = "dq2";
		dq2.tilesPerSquare = 1;
		dq2.squaresWide = 23;
		dq2.squaresTall = 15;
	}
	
	private function makeBkg(){
		var bkg = new FlxSprite().makeGraphic(1, 1, FlxColor.WHITE);
		bkg.scale.set(FlxG.width, FlxG.height);
		bkg.updateHitbox();
		add(bkg);
	}
}

@:enum abstract Tool(Int){
	
	public var Pencil = 0;
	public var Eraser = 1;
	public var Bucket = 2;
	public var Turpentine = 3;
}