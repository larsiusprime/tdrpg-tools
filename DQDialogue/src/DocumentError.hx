package;

/**
 * ...
 * @author 
 */


class DocumentError
{
	public var line:Int;
	public var block:Int;
	public var message:String;
	public var context:String;
	
	public function new(line_:Int, block_:Int, msg_:String, context_:String)
	{
		line = line_;
		block = block_;
		message = msg_;
		context = context_;
	}
}