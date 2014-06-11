#TileProcess

TileProcess lets an artist create a "sparse" tileset, then does all the boring scut-work of generating tile connection permutations for final use in the game.

It also creates a "Quick Brown Fox" tiling test that uses every tile connection so the artist can see how they're doing.

![](https://raw.githubusercontent.com/larsiusprime/tdrpg-tools/master/TileProcess/LOOKATME.png)

##Scripting

TileProcess supports a very simple scripting format that lets you specify the output format. For instance, this line generates the "donut" tile (an empty tile bordered 8 full tiles) by compositing 4 interior corners and properly masking them:

````
 1,10		S+W,S+E,N+E,N+W		NE,NW,SW,SE
````

###Scripting Notes
These comments are taken from the "default.txt" script file:

````
//Two slashes indicate a comment; blank and/or malformed lines are also ignored
//You separate blocks with two tabs, and finish a line with a single endline
//Leading spaces and tabs at the beginning of a line are trimmed
//A comment can only be preceded by whitespace, you can't insert one on the same line as a command

//Line Format:
	//tile destination + 2 tabs + list of tiles + 2 tabs + list of masks + endline
	//example:
	// 0,6		NW,NE,SW		SE,SW,NE
	
	//Script MUST begin with a line specifying the four basic settings (widthInTiles, heightInTiles, tileSize, scale)
		//widthInTiles	:	INT, how wide the final tileset will be, in tiles
		//heightInTiles : 	INT, how tall the final tileset will be, in tiles
		//tileSize		:	INT, the length of one side of a tile from the input set (unscaled), in pixels (assumes square tiles)
		//scale			:	FLOAT, the scale factor to apply to the final tileset
	//First line should be like this:
		//setting1=value + 2 tabs + setting2=value + 2 tabs + setting3=value + 2 tabs + setting4=value
		//example:
		//widthInTiles=3		heightInTiles=18		tileSize=64		scale=1.0
		
		//NOTE: case and order doesn't matter, but spelling does. All 4 values must be specified
		//Do NOT put whitespace between the setting name, the equals sign, and the value
	
//list of legal tile primitives:
	//Center:			CENT			(center, "filled" tile)
	//Cardinals:		N,W,S,E			("flat" borders to the N,W,S,E of center)
	//Intermediates:	NW,NE,SE,SW		(external corners to the NW,NE,SE,SW of center)
	//Composites:		N+W,N+E,S+E,S+W	(internal corners that are visual composites of N+W, S+E, etc)
	
//list of legal masks:
	//Cardinals:		N,W,S,E
	//Intermediaes:		NW,NE,SE,SW
	
//TIPS:
	//turn on "show all characters", "show whitespace", and/or "show endlines" in your text editor
	//do not use whitespace (tabs or spaces) INSIDE a command block
	//scripts are case-insensitive
	//when using masks, most of the time you want the OPPOSITE of the corresponding tile
	//If you paint tile N, you mask out the rest with mask S, tile SW is masked properly by mask NE, etc.
	//both unix and windows style endlines are (theoretically) supported
````
