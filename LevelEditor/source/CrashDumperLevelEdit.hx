package com.leveluplabs.tdrpg;
import crashdumper.CrashDumper;
import flash.display.BitmapData;
import flash.errors.Error;
import flixel.addons.plugin.screengrab.FlxScreenGrab;
import flixel.FlxG;
import openfl.display.Bitmap;
import openfl.display.JPEGEncoderOptions;
import openfl.Lib;
#if sys
import sys.io.File;
import sys.io.FileOutput;
#end


/**
 * ...
 * @author larsiusprime
 */
class CrashDumperLevelEdit extends CrashDumper
{
	public var firstCrash:Bool = true;
	
	public override function new(sessionId_:String,?path_:String,closeOnCrash_:Bool=true,?customDataMethod_:CrashDumper->Void,?postCrashMethod_:CrashDumper->Void) 
	{
		var theUrl:String = "";
		
		super(sessionId_, path_, theUrl, closeOnCrash_, customDataMethod_, postCrashMethod_);
	}
	
	
	private var __doSuperErrorStuff:Bool = false;
	
	/***Only log a crash dump if the user has the right setting***/
	private override function doErrorStuff(e:Dynamic,writeToFile:Bool=true,sendToServer:Bool=false,traceToLog:Bool=true):Void
	{
		var waitToDoErrorStuff = false;
		
		if(!waitToDoErrorStuff) {
			super.doErrorStuff(e, writeToFile, sendToServer, false); 
			
			if (!closeOnCrash)
			{
				return;
			}
		}
		
		if (closeOnCrash)
		{
			CrashDumper.active = false;
			var msg:String = UU.fixSlashes(UU.uCombine(["Crashdump saved to : ",path,pathLogErrors]));
			throw new Error(msg);
			#if sys
			Sys.exit(0);
			#end
		}
	}
	
}