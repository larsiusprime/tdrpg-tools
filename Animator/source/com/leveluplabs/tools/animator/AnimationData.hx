package com.leveluplabs.tools.animator;
import flixel.FlxSprite;
import flixel.interfaces.IFlxDestroyable;

/**
 * ...
 * @author 
 */
class AnimationData implements IFlxDestroyable
{
	public var name:String = "";
	
	public var frames:Array<Int> = null;				//raw frame data
	public var sweets:Map<Int,AnimSweetSpot> = null;	//sweet spots in the animation, keyed by index
	
	public var frameRate:Int = 30;
	public var looped:Bool = false;
	
	public function new() 
	{
		frames = [];
	}
	
	public function destroy():Void {
		frames = null;
		if (sweets != null) 
		{
			for (key in sweets.keys()) 
			{
				sweets.remove(key);
			}
		}
		sweets = null;
	}
	
	public function setSweetSpot(i:Int, Sweet:AnimSweetSpot):Void {
		if (sweets == null) {
			sweets = new Map<Int, AnimSweetSpot>();
		}
		sweets.set(i, Sweet);
	}
	
	public function editSweetSpot(i:Int,Name:String,X:Float,Y:Float):Void {
		if (sweets == null) {
			sweets = new Map<Int,AnimSweetSpot>();
		}
		var s:AnimSweetSpot = sweets.get(i);
		if (s == null) {
			s = new AnimSweetSpot(Name, X, Y);
			sweets.set(i, s);
		}else {
			s.name = Name;
			s.x = X;
			s.y = Y;
		}
	}
	
	public function removeSweetSpot(i:Int):Void {
		if (sweets == null) {
			return;
		}else {
			if (sweets.exists(i)) {
				sweets.remove(i);
			}
		}
	}
	
	public function hasSweetSpot(i:Int):Bool {
		if (sweets != null && sweets.exists(i)) {
			return true;
		}
		return false;
	}
	
	public function getSweetSpot(i:Int):AnimSweetSpot{
		if (sweets == null) {
			return null;
		}
		return sweets.get(i);
	}
	
}