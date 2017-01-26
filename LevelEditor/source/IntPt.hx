package;

/**
 * ...
 * @author 
 */
class IntPt
{
	public var x:Int;
	public var y:Int;
	
	public function new(X:Int,Y:Int) 
	{
		x = X;
		y = Y;
	}

	public function toString():String{
		return "(" + x + "," + y + ")";
	}
}