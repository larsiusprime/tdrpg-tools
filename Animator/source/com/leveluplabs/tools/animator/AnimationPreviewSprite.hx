package com.leveluplabs.tools.animator;
import flash.display.BitmapData;
import flash.geom.Matrix;
import flash.geom.Point;
import flash.geom.Rectangle;
import flixel.addons.ui.FlxClickArea;
import flixel.addons.ui.U;
import flixel.FlxG;
import flixel.FlxSprite;
import flixel.group.FlxGroup;
import flixel.group.FlxSpriteGroup;
import flixel.ui.FlxButton;
import flixel.util.FlxColor;
import flixel.util.FlxPoint;
import flixel.util.loaders.CachedGraphics;

/**
 * This is just a big sprite-sheet that shows the exact frames of an animation, including duplicated frames, all in one big sheet
 * @author 
 */
class AnimationPreviewSprite extends FlxSpriteGroup
{
	/**
	 * 
	 * @param	entity	The Entity you want to grab frames from
	 * @param	anim	The Animation you want to display
	 */
	
	private var _maxWidth:Float = 100;
	private var _maxHeight:Float = 100;
	
	public var cellOutlineColor:Int = 0x00000000;
	public var hilightColor(default,set):Int     = 0xff00ff00;
	public var hilightColor2(default,set):Int    = 0xffffffff;
	public var cellCheckColor1:Int  = 0xff808080;
	public var cellCheckColor2:Int  = 0xff404040;
	
	private var _canvas:FlxSprite;
	private var _backing:FlxSprite;
	private var _rect:Rectangle;
	private var _btn:FlxButton;
	private var _hilight:FlxSprite;
	private var _hilight2:FlxSprite;
	
	private var _callback:Int->Void;
	
	private var _cellWidth:Float;
	private var _cellHeight:Float;
	private var _heightInCells:Int;
	private var _widthInCells:Int;
	private var _totalCells:Int;
	private var _scale:Float = 1;
	
	private var _sweet:FlxSprite;
	
	public override function destroy():Void {
		super.destroy();
		_callback = null;
		_canvas = null;
		_backing = null;
		_rect = null;
		_btn = null;
		_hilight = null;
		_hilight2 = null;
		_sweet = null;
	}
	
	public function new(entity:FlxSprite,anim:AnimationData,maxW:Float,maxH:Float,?Callback:Int->Void)
	{
		_rect = new Rectangle();
		_sweet = new FlxSprite(0, 0, U.gfx("ui/sweet"));
		_callback = Callback;
		
		_canvas = new FlxSprite();
		_backing = new FlxSprite();
		_hilight = new FlxSprite();
		_hilight2 = new FlxSprite();
		_btn = new FlxButton(0, 0, onClick);
		var fs:FlxSprite = new FlxSprite();
		fs.makeGraphic(10, 10, FlxColor.TRANSPARENT);
		_btn.loadGraphicFromSprite(fs);
		
		super(0, 0);
		
		add(_btn);
		add(_backing);
		add(_canvas);
		add(_hilight);
		add(_hilight2);
		
		_maxWidth = maxW;
		_maxHeight = maxH;
		
		showEntityAnimation(entity, anim);
	}
	
	public function set_hilightColor2(i:Int):Int {
		hilightColor2 = i;
		if (_hilight2 != null) {
			_hilight2.color = hilightColor2;
		}
		return hilightColor2;
	}
	
	
	public function set_hilightColor(i:Int):Int {
		hilightColor = i;
		if (_hilight != null) {
			_hilight.color = hilightColor;
		}
		return hilightColor;
	}
	
	public function showEntityAnimation(entity:FlxSprite, anim:AnimationData, clearHilights:Bool=true):Void {
		var frameW:Float = entity.width;
		var frameH:Float = entity.height;
		var frames:Int = anim.frames.length;
		
		var grid:FlxPoint = null;
		
		_scale = 1.0;
		
		grid = fitCellsToDimensions(_maxWidth, _maxHeight, frames, frameW, frameH);
		
		while (grid == null) {			//if we can't make it fit
			_scale -= 0.01;				//scale down by 1% & try again
			if (_scale <= 0) {
				grid = null;			//if we've reached the end, FAIL
				break;
			}else{
				grid = fitCellsToDimensions(_maxWidth, _maxHeight, frames, frameW * _scale, frameH * _scale);
			}
		}
		
		if (grid != null) {
			var w:Int = Std.int(grid.x * (frameW * _scale));
			var h:Int = Std.int(grid.y * (frameH * _scale));
			
			_widthInCells = cast grid.x;
			_heightInCells = cast grid.y;
			_totalCells = frames;
			_cellWidth = frameW * _scale;
			_cellHeight = frameH * _scale;

			var cg:CachedGraphics = FlxG.bitmap.get("anim_preview_" + anim.name);
			if (cg != null) {
				FlxG.bitmap.remove("anim_preview_" + anim.name);
			}
			
			_canvas.makeGraphic(w, h, FlxColor.TRANSPARENT, true, "anim_preview_"+anim.name);			//start with blank fresh canvas
			_backing.makeGraphic(cast w, cast h, FlxColor.TRANSPARENT, true);							//start with blank fresh backing
			
			_hilight.makeGraphic(Math.round(_cellWidth),Math.round(_cellHeight), 0xFFFFFFFF, true);
			_hilight2.makeGraphic(Math.round(_cellWidth),Math.round(_cellHeight), 0xFFFFFFFF, true);
			_rect.x = 1;
			_rect.y = 1;
			_rect.width = Math.round(_cellWidth - 2);
			_rect.height = Math.round(_cellHeight - 2);
			
			_hilight.pixels.fillRect(_rect, FlxColor.TRANSPARENT);
			_hilight2.pixels.fillRect(_rect, FlxColor.TRANSPARENT);
			
			hilightColor = hilightColor;
			hilightColor2 = hilightColor2;
			
			if (clearHilights) {
				_hilight.visible = false;
				_hilight2.visible = false;
			}
			
			_btn.width = w;
			_btn.height = h;
			
			_canvas.pixels.fillRect(_canvas.pixels.rect, FlxColor.TRANSPARENT);
			_backing.pixels.fillRect(_backing.pixels.rect, FlxColor.TRANSPARENT);
			redraw(entity, anim.frames, anim.sweets);
		}
	}
	
	private function redraw(entity:FlxSprite,frames:Array<Int>,sweets:Map<Int,AnimSweetSpot>):Void {
		var frame_index:Int = 0;
		var i:Int = 0;
		var grid_x:Int = 0;
		var grid_y:Int = 0;
		
		for (frame_index in frames) {
			var hasSweet:Bool = false;
			if (sweets != null && sweets.exists(i)) {
				hasSweet = true;
			}
			pasteFrame(entity, frame_index, grid_x, grid_y, _scale, i, hasSweet);	//paste each animation frame
			grid_x++;
			if (grid_x >= _widthInCells) {
				grid_x = 0;
				grid_y++;
			}
			i++;
		}
	}
	
	public function hilightCell(i:Int,which:Int=0):Int{
		var theHilight:FlxSprite = _hilight;
		if (which == 1) {
			theHilight = _hilight2;
		}
		
		if(i >= 0 && i < _totalCells){
			var loc = indexToGridLoc(i);
			theHilight.x = Math.ceil(x + loc.x * (_cellWidth));
			theHilight.y = Math.ceil(y + loc.y * (_cellHeight));
			theHilight.visible = true;
		}else {
			theHilight.visible = false;
			theHilight.x = x;
			theHilight.y = y;
			return -1;
		}
		return i;
	}
	
	private inline function indexToGridLoc(i:Int):FlxPoint {
		var pt:FlxPoint = new FlxPoint();
		pt.y = Math.floor(i / _widthInCells);
		pt.x = i % _widthInCells;
		return pt;
	}
	
	private inline function gridLocToIndex(X:Int, Y:Int):Int {
		return (Y * _widthInCells) + X;
	}
	
	private function onClick():Void{
		var m = FlxG.mouse.getScreenPosition();
		var rx:Float = m.x - x;
		var ry:Float = m.y - y;
		
		var cellX:Int = Math.floor(rx / _cellWidth);
		var cellY:Int = Math.floor(ry / _cellHeight);
		
		if(_callback != null){
			_callback((cellY * _widthInCells) + cellX);
		}
	}
	
	private function pasteFrame(source:FlxSprite, frame:Int, cellX:Int, cellY:Int, scale:Float= 1, i:Int=0, hasSweet:Bool=false):Void {
		var bmp:BitmapData = source.framesData.frames[frame].getBitmap();
		
		if (_flashPoint == null) {
			_flashPoint = new Point();
		}
		if (_matrix == null) {
			_matrix = new Matrix();
		}
		_flashPoint.x = cellX * (bmp.width * scale);
		_flashPoint.y = cellY * (bmp.height * scale);
		
		if (scale == 1) {
			drawOutlinesAndFills(_flashPoint,bmp.width,bmp.height,cellX,cellY);
			
			_canvas.pixels.copyPixels(bmp, bmp.rect, _flashPoint, true);
			if(hasSweet){
				_canvas.pixels.copyPixels(_sweet.pixels, _sweet.pixels.rect, _flashPoint, true);
			}
		}else {
			_matrix.identity();
			_matrix.scale(scale, scale);
			_matrix.translate(_flashPoint.x, _flashPoint.y);
			drawOutlinesAndFills(_flashPoint,bmp.width*scale,bmp.height*scale,cellX,cellY);
			_canvas.pixels.draw(bmp, _matrix, true);
			if(hasSweet){
				_canvas.pixels.copyPixels(_sweet.pixels, _sweet.pixels.rect, _flashPoint, true);
			}
		}
	}
	
	private function drawOutlinesAndFills(pt:Point,w:Float,h:Float,cellX:Int,cellY:Int):Void {
		
		_rect.x = pt.x;
		_rect.y = pt.y;
		_rect.width = w;
		_rect.height = h;
		
		var fillColor:Int = cellCheckColor1;
		if (cellY % 2 == 0) {
			if (cellX % 2 == 0) {
				fillColor = cellCheckColor2;
			}
		}else {
			if (cellX % 2 == 1) {
				fillColor = cellCheckColor2;
			}
		}
		
		if (cellOutlineColor != FlxColor.TRANSPARENT) {
			_backing.pixels.fillRect(_rect, cellOutlineColor);
			_rect.x += 1;
			_rect.y += 1;
			_rect.width -= 2;
			_rect.height -= 2;
			_backing.pixels.fillRect(_rect, fillColor);		//fill with color, even if transparent
			
		}else {
			if (fillColor != FlxColor.TRANSPARENT) {		//check for transparent b/c we don't need to since there's no border to cut out
				_backing.pixels.fillRect(_rect, fillColor);
			}
		}
		_backing.dirty = true;
	}
	
	private function fitCellsToDimensions(maxW:Float, maxH:Float, cells:Int, cellW:Float, cellH:Float):FlxPoint {
		var gridW:Int = cells;				//start with a long strip of cells
		var gridH:Int = 1;
		
		var sheetW:Float = gridW * cellW;	//caluclate sheet width
		var sheetH:Float = gridH * cellH;
		
		var maxCells:Int = gridW * gridH;
		
		while (sheetW > maxW || sheetH > maxH) {	//while sheet does NOT fit inside the bounds
			gridW--;								//subtract one column
			maxCells = gridW * gridH;
			if (maxCells < cells) {
				gridH++;
				maxCells = gridW * gridH;
			}
			
			sheetW = gridW * cellW;					//recalculate sheet size
			sheetH = gridH * cellH;
			
			if (gridW <= 0) {						//if we've gone all the way to the end
				return null;						//FAIL
			}
		}											//if sheet size is now within bounds, exit loop
		
		return new FlxPoint(gridW, gridH);			//return number of cells that will fit within bounds
	}
	
}