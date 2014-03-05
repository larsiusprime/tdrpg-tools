package com.leveluplabs.tools.animator;
import flixel.FlxG;
import flixel.util.FlxRandom;

/**
 * ...
 * @author 
 */
class StressSprite extends EntitySprite
{

	public function new(X:Float,Y:Float,G:EntityGraphics) 
	{
		super(X, Y, G);
	}
	
	public function init(Offscreen:Bool = false):StressSprite
	{
		var speedMultiplier:Int = 50;
		
		if (Offscreen)
		{
			speedMultiplier = 5000;
		}
		
		velocity.x = speedMultiplier * FlxRandom.floatRanged( -5, 5);
		velocity.y = speedMultiplier * FlxRandom.floatRanged( -7.5, 2.5);
		acceleration.y = 5;
		elasticity = 1;
		
		return this;
	}
	
	override public function update():Void
	{
		super.update();
		
		if (!State_StressTest.offscreen)
		{
			setBounds();
		}
	}

	private function setBounds():Void
	{
		if (x+width > FlxG.width)
		{
			velocity.x *= -1;
			x = FlxG.width-width;
		}
		else if (x < 0)
		{
			velocity.x *= -1;
			x = 0;
		}
		
		if (y+height > FlxG.height)
		{
			velocity.y *= -0.8;
			y = FlxG.height-height;
		
			if (FlxRandom.chanceRoll())
			{
				velocity.y -= FlxRandom.floatRanged(3, 7);
			}
		}
		else if (y < 0)
		{
			velocity.y *= -0.8;
			y = 0;
		}
	}




}