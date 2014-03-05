package com.leveluplabs.tools.animator;

/**
 * ...
 * @author 
 */
class AnimSweetSpot
{
	public var x:Float;	//frame location associated with the sweet spot, if any
	public var y:Float;
	
	public var name:String;	//name associated with the sweet spot, if any
	
	public function new(name_:String="",x_:Float=-2,y_:Float=-1) 
	{
		name = name_;
		x = x_;
		y = y_;
	}
	
}