package;

import haxe.Utf8;
import java.Lib;
import sys.FileSystem;
import sys.io.File;
import unifill.Unifill;

/**
 * ...
 * @author 
 */
class Main 
{
	
	static function main() 
	{
		var args = Sys.args();
		if (args == null || args.length < 2){
			usage();
			return;
		}
		var input = args[0];
		var output = args[1];
		var reverse = args.indexOf("-reverse") != -1;
		
		var file = "";
		if (FileSystem.exists(input))
		{
			try{
				file = File.getContent(input);
			}
			catch (msg:Dynamic)
			{
				error(msg);
				return;
			}
		}
		else
		{
			error("input file (" + input + ") does not exist");
		}
		
		if (!reverse)
		{
			var grid = processCSV(file, output);
			var tsv = printTSV(grid);
			
			File.saveContent(output, tsv);
		}
		else
		{
			var grid = processTSV(file, output);
			var csv = printCSV(grid);
			
			File.saveContent(output, csv);
		}
	}
	
	static function printCSV(grid:Array<Array<String>>):String
	{
		var buf = new StringBuf();
		
		var comma = 0x2C;
		var quote = 0x22;
		
		for (iy in 0...grid.length){
			var row = grid[iy];
			for (ix in 0...row.length){
				var cell = row[ix];
				var quoteStatus = needsQuotes(cell);
				
				//If we need quotes, deal with that
				if (quoteStatus > 0)
				{
					//If we have quotes IN the cell, first double them up
					if (quoteStatus == 2){
						cell = doubleQuotes(cell);
					}
					
					//Then wrap the cell in a starting & ending quotation mark
					cell = quoteCell(cell);
				}
				
				//Add all the regular characters
				Utf8.iter(cell, function(char:Int){
					buf.addChar(char);
				});
				
				//Add a comma
				if (ix != row.length - 1){
					buf.addChar(comma);
				}
			}
			if(iy != grid.length -1){
				buf.add(Std.string("\n"));
			}
		}
		
		return buf.toString();
	}
	
	static function quoteCell(str:String):String
	{
		var buf = new StringBuf();
		var quote = 0x22;
		
		buf.addChar(quote);
		Utf8.iter(str, function(char:Int){
			buf.addChar(char);
		});
		buf.addChar(quote);
		
		return buf.toString();
	}
	
	static function doubleQuotes(str:String):String
	{
		var buf = new StringBuf();
		var quote = 0x22;
		
		Utf8.iter(str, function(char:Int){
			if (char == quote){
				buf.addChar(quote);
				buf.addChar(quote);
			}
			else {
				buf.addChar(char);
			}
		});
		
		return buf.toString();
	}
	
	static function needsQuotes(str:String):Int
	{
		var comma = 0x2C;
		var quote = 0x22;
		
		var hasComma = false;
		var hasQuote = false;
		Utf8.iter(str, function(char:Int){
			if (char == comma) {
				hasComma = true;
			}
			if (char == quote) {
				hasQuote = true;
			}
		});
		
		if (hasQuote) return 2;
		
		if (hasComma) return 1;
		
		return 0;
	}
	
	static function printTSV(grid:Array<Array<String>>):String
	{
		var buf = new StringBuf();
		
		var tab = 0x09;
		
		for (iy in 0...grid.length){
			var row = grid[iy];
			for (ix in 0...row.length){
				var cell = row[ix];
				Utf8.iter(cell, function(char:Int){
					buf.addChar(char);
				});
				if (ix != row.length - 1){
					buf.addChar(tab);
				}
			}
			if(iy != grid.length -1){
				buf.add(Std.string("\n"));
			}
		}
		
		return buf.toString();
	}
	
	static function processTSV(file:String, output:String):Array<Array<String>>
	{
		var row:Int = 0;
		var col:Int = 0;
		var cellStarted:Bool = false;
		var row_i:Int = 0;
		
		var lastChar = 0;
		
		var tab:Int   = 0x09;
		var lf:Int    = 0x0A;
		var cr:Int    = 0x0D;
		
		var grid:Array<Array<String>> = [];
		var chars:Array<Int> = [];
		
		var endCell = function(){
			col++;
			cellStarted = false;
		};
		
		var addChar = function(?char:Int)
		{
			if (char != null)
			{
				chars.push(char);
			}
		};
		
		var storeCell = function(Row:Int, Col:Int)
		{
			if (grid.length <= Row){
				grid.push([]);
			}
			while (grid[Row].length <= Col){
				grid[Row].push("");
			}
			var buf = new StringBuf();
			for (char in chars){
				buf.addChar(char);
			}
			grid[Row][Col] = buf.toString();
			endCell();
		};
		
		Utf8.iter(file, function(char:Int){
			switch(char){
				case 0x0D://CARRIAGE RETURN
					//ignore all carriage returns
				case 0x0A://LINE FEED
					addChar(null);
					
					if (cellStarted) {					//encountered a line feed inside of a cell
						storeCell(row, col);				//end the cell
					}
					col = 0;							//reset column and advance row
					row++;
				case 0x09://TAB
					if (!cellStarted) {					//encountered a tab outside of a cell
						chars = [];
						storeCell(row, col);				//start & finish a new cell immediately
					}
					else {								//encountered a tab inside of a cell
						addChar(null);
						storeCell(row, col);		//end the cell
					}
				default:
					if (!cellStarted) {					//encountered a random character outside of a cell
						cellStarted = true;					//start a new cell
						chars = [];
						addChar(char);
					}
					else {								//encountered a random character inside of a cell
						addChar(char);						//add the character
					}
			}
		});
		
		if (cellStarted) {
			addChar(null);
			storeCell(row, col);
		}
		
		return grid;
	}
	
	static function processCSV(file:String, output:String):Array<Array<String>>
	{
		var row:Int = 0;
		var col:Int = 0;
		var cellStarted:Bool = false;
		var cellQuoted:Bool = false;
		var row_i:Int = 0;
		
		var qs:Int = 0;
		
		var lastChar = 0;
		
		var comma:Int = 0x2c;
		var quote:Int = 0x22;
		var lf:Int    = 0x0A;
		var cr:Int    = 0x0D;
		
		var grid:Array<Array<String>> = [];
		var chars:Array<Int> = [];
		
		var endCell = function(){
			col++;
			cellStarted = false;
			cellQuoted = false;
			qs = 0;
		};
		
		var addChar = function(?char:Int)
		{
			qs = stashQuotes(chars, qs);
			if (char != null)
			{
				chars.push(char);
			}
		};
		
		var storeCell = function(Row:Int, Col:Int)
		{
			if (grid.length <= Row){
				grid.push([]);
			}
			while (grid[Row].length <= Col){
				grid[Row].push("");
			}
			var buf = new StringBuf();
			for (char in chars){
				buf.addChar(char);
			}
			grid[Row][Col] = buf.toString();
			endCell();
		};
		
		Utf8.iter(file, function(char:Int){
			switch(char){
				case 0x0D://CARRIAGE RETURN
					//ignore all carriage returns
				case 0x0A://LINE FEED
					addChar(null);
					
					if (cellStarted) {					//encountered a line feed inside of a cell
						storeCell(row, col);				//end the cell
					}
					col = 0;							//reset column and advance row
					row++;
					row_i = -1;
				case 0x2C://COMMA
					if (!cellStarted) {					//encountered a comma outside of a cell
						chars = [];
						storeCell(row, col);				//start & finish a new cell immediately
					}
					else {								//encountered a comma inside of a cell
						var cellFinished = false;
						
						if (cellQuoted) {					//cell is quoted...
							if (qs % 2 == 1) {					//odd-number of quotes followed by a comma means end
								cellFinished = true;
								addChar(null);
							}
							else {
								addChar(comma);					//comma is internal text
							}
						}
						else {								//cell is unquoted means end
							cellFinished = true;
							addChar(null);
						}
						
						if (cellFinished) {
							storeCell(row, col);		//end the cell
						}
					}
				case 0x22://QUOTE
					if (!cellStarted) {					//encountered a quote outside of a cell
						cellStarted = true;					//start a new cell
						cellQuoted = true;					//cell is quoted
						chars = [];
						qs = 0;
					}else {								//encountered a quote inside of a cell
						if (cellQuoted) {					//cell is quoted
							if (lastChar != quote){				//last char wasn't a quote
								qs = 1;								//start counting
							}
							else{								//last char was a quote
								qs++;								//keep counting
							}
						}
					}
				default:
					if (!cellStarted) {					//encountered a random character outside of a cell
						cellStarted = true;					//start a new cell
						cellQuoted = false;
						chars = [];
						addChar(char);
					}
					else {								//encountered a random character inside of a cell
						addChar(char);						//add the character
					}
			}
			lastChar = char;
			row_i++;
		});
		
		if (cellStarted) {
			addChar(null);
			storeCell(row, col);
		}
		
		return grid;
	}
	
	static function stashQuotes(chars:Array<Int>, count:Int):Int
	{
		var quote = 0x22;
		var quotes = Std.int(count / 2);
		for (i in 0...quotes){
			chars.push(quote);
		}
		return 0;
	}
	
	private static function error(msg:Dynamic)
	{
		Sys.println("ERROR: " + msg);
	}
	
	private static function usage()
	{
		Sys.println("usage: csv2tsv <input_file> <output_file>\nex: csv2tsv input.csv output.tsv"); 
	}
	
}