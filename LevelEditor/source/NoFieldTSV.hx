package;
import firetongue.TSV;

/**
 * ...
 * @author 
 */
class NoFieldTSV extends TSV
{

	public function new(input:String)
	{
		super(input);
	}
	
	private override function processCells(cells:Array<String>,row:Int=0):Void
	{
		var col:Int = 0;
		var newline:Bool = false;
		var row_array:Array<String>=null;
		
		if (grid == null)
		{
			grid = new Array<Array<String>>();
			fields = [];
		}
		
		row_array = [];
		
		for (i in 0...cells.length)
		{
			var cell:String = "";
			if (_quoted)
			{
				cell = cells[i].substr(1, cells[i].length - 2);
			}
			else
			{
				cell = cells[i];
			}
			
			{
				row_array.push(cell);	//get the row cells
			}
		}
		
		grid.push(row_array);
		clearArray(cells);
		cells = null;
	}
}