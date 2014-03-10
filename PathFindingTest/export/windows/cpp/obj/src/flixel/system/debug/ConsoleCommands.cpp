#include <hxcpp.h>

#ifndef INCLUDED_IMap
#include <IMap.h>
#endif
#ifndef INCLUDED_Reflect
#include <Reflect.h>
#endif
#ifndef INCLUDED_Std
#include <Std.h>
#endif
#ifndef INCLUDED_StringTools
#include <StringTools.h>
#endif
#ifndef INCLUDED_Type
#include <Type.h>
#endif
#ifndef INCLUDED_flash_display_DisplayObject
#include <flash/display/DisplayObject.h>
#endif
#ifndef INCLUDED_flash_display_DisplayObjectContainer
#include <flash/display/DisplayObjectContainer.h>
#endif
#ifndef INCLUDED_flash_display_IBitmapDrawable
#include <flash/display/IBitmapDrawable.h>
#endif
#ifndef INCLUDED_flash_display_InteractiveObject
#include <flash/display/InteractiveObject.h>
#endif
#ifndef INCLUDED_flash_display_Sprite
#include <flash/display/Sprite.h>
#endif
#ifndef INCLUDED_flash_events_EventDispatcher
#include <flash/events/EventDispatcher.h>
#endif
#ifndef INCLUDED_flash_events_IEventDispatcher
#include <flash/events/IEventDispatcher.h>
#endif
#ifndef INCLUDED_flixel_FlxBasic
#include <flixel/FlxBasic.h>
#endif
#ifndef INCLUDED_flixel_FlxG
#include <flixel/FlxG.h>
#endif
#ifndef INCLUDED_flixel_FlxGame
#include <flixel/FlxGame.h>
#endif
#ifndef INCLUDED_flixel_FlxObject
#include <flixel/FlxObject.h>
#endif
#ifndef INCLUDED_flixel_FlxState
#include <flixel/FlxState.h>
#endif
#ifndef INCLUDED_flixel_group_FlxGroup
#include <flixel/group/FlxGroup.h>
#endif
#ifndef INCLUDED_flixel_group_FlxTypedGroup
#include <flixel/group/FlxTypedGroup.h>
#endif
#ifndef INCLUDED_flixel_interfaces_IFlxDestroyable
#include <flixel/interfaces/IFlxDestroyable.h>
#endif
#ifndef INCLUDED_flixel_system_debug_Console
#include <flixel/system/debug/Console.h>
#endif
#ifndef INCLUDED_flixel_system_debug_ConsoleCommands
#include <flixel/system/debug/ConsoleCommands.h>
#endif
#ifndef INCLUDED_flixel_system_debug_ConsoleUtil
#include <flixel/system/debug/ConsoleUtil.h>
#endif
#ifndef INCLUDED_flixel_system_debug_FlxDebugger
#include <flixel/system/debug/FlxDebugger.h>
#endif
#ifndef INCLUDED_flixel_system_debug_LogStyle
#include <flixel/system/debug/LogStyle.h>
#endif
#ifndef INCLUDED_flixel_system_debug_Watch
#include <flixel/system/debug/Watch.h>
#endif
#ifndef INCLUDED_flixel_system_debug_Window
#include <flixel/system/debug/Window.h>
#endif
#ifndef INCLUDED_flixel_system_frontEnds_DebuggerFrontEnd
#include <flixel/system/frontEnds/DebuggerFrontEnd.h>
#endif
#ifndef INCLUDED_flixel_system_frontEnds_LogFrontEnd
#include <flixel/system/frontEnds/LogFrontEnd.h>
#endif
#ifndef INCLUDED_flixel_system_frontEnds_VCRFrontEnd
#include <flixel/system/frontEnds/VCRFrontEnd.h>
#endif
#ifndef INCLUDED_flixel_util_FlxSave
#include <flixel/util/FlxSave.h>
#endif
#ifndef INCLUDED_haxe_ds_StringMap
#include <haxe/ds/StringMap.h>
#endif
#ifndef INCLUDED_hxMath
#include <hxMath.h>
#endif
namespace flixel{
namespace system{
namespace debug{

Void ConsoleCommands_obj::__construct(::flixel::system::debug::Console console)
{
HX_STACK_FRAME("flixel.system.debug.ConsoleCommands","new",0xd36fb809,"flixel.system.debug.ConsoleCommands.new","flixel/system/debug/ConsoleCommands.hx",11,0x4441c1e8)

HX_STACK_ARG(console,"console")
{
	HX_STACK_LINE(20)
	this->_watchingMouse = false;
	HX_STACK_LINE(25)
	this->_console = console;
	HX_STACK_LINE(28)
	{
		HX_STACK_LINE(28)
		int ParamCutoff = (int)-1;		HX_STACK_VAR(ParamCutoff,"ParamCutoff");
		struct _Function_2_1{
			inline static Dynamic Block( ::flixel::system::debug::ConsoleCommands_obj *__this,int &ParamCutoff){
				HX_STACK_FRAME("*","closure",0x5bdab937,"*.closure","flixel/system/debug/ConsoleCommands.hx",28,0x4441c1e8)
				{
					hx::Anon __result = hx::Anon_obj::Create();
					__result->Add(HX_CSTRING("aliases") , Array_obj< ::String >::__new().Add(HX_CSTRING("help")).Add(HX_CSTRING("h")),false);
					__result->Add(HX_CSTRING("processFunction") , __this->help_dyn(),false);
					__result->Add(HX_CSTRING("help") , null(),false);
					__result->Add(HX_CSTRING("paramHelp") , HX_CSTRING("(Command)"),false);
					__result->Add(HX_CSTRING("numParams") , (int)1,false);
					__result->Add(HX_CSTRING("paramCutoff") , ParamCutoff,false);
					return __result;
				}
				return null();
			}
		};
		HX_STACK_LINE(28)
		console->commands->__Field(HX_CSTRING("push"),true)(_Function_2_1::Block(this,ParamCutoff));
	}
	HX_STACK_LINE(29)
	{
		HX_STACK_LINE(29)
		int NumParams = (int)0;		HX_STACK_VAR(NumParams,"NumParams");
		HX_STACK_LINE(29)
		int ParamCutoff = (int)-1;		HX_STACK_VAR(ParamCutoff,"ParamCutoff");
		struct _Function_2_1{
			inline static Dynamic Block( ::flixel::system::debug::ConsoleCommands_obj *__this,int &NumParams,int &ParamCutoff){
				HX_STACK_FRAME("*","closure",0x5bdab937,"*.closure","flixel/system/debug/ConsoleCommands.hx",29,0x4441c1e8)
				{
					hx::Anon __result = hx::Anon_obj::Create();
					__result->Add(HX_CSTRING("aliases") , Array_obj< ::String >::__new().Add(HX_CSTRING("close")).Add(HX_CSTRING("cl")),false);
					__result->Add(HX_CSTRING("processFunction") , __this->close_dyn(),false);
					__result->Add(HX_CSTRING("help") , HX_CSTRING("Closes the debugger overlay."),false);
					__result->Add(HX_CSTRING("paramHelp") , null(),false);
					__result->Add(HX_CSTRING("numParams") , NumParams,false);
					__result->Add(HX_CSTRING("paramCutoff") , ParamCutoff,false);
					return __result;
				}
				return null();
			}
		};
		HX_STACK_LINE(29)
		console->commands->__Field(HX_CSTRING("push"),true)(_Function_2_1::Block(this,NumParams,ParamCutoff));
	}
	HX_STACK_LINE(30)
	{
		HX_STACK_LINE(30)
		int NumParams = (int)0;		HX_STACK_VAR(NumParams,"NumParams");
		HX_STACK_LINE(30)
		int ParamCutoff = (int)-1;		HX_STACK_VAR(ParamCutoff,"ParamCutoff");
		struct _Function_2_1{
			inline static Dynamic Block( ::flixel::system::debug::ConsoleCommands_obj *__this,int &NumParams,int &ParamCutoff){
				HX_STACK_FRAME("*","closure",0x5bdab937,"*.closure","flixel/system/debug/ConsoleCommands.hx",30,0x4441c1e8)
				{
					hx::Anon __result = hx::Anon_obj::Create();
					__result->Add(HX_CSTRING("aliases") , Array_obj< ::String >::__new().Add(HX_CSTRING("clearHistory")).Add(HX_CSTRING("ch")),false);
					__result->Add(HX_CSTRING("processFunction") , __this->clearHistory_dyn(),false);
					__result->Add(HX_CSTRING("help") , HX_CSTRING("Clears the command history."),false);
					__result->Add(HX_CSTRING("paramHelp") , null(),false);
					__result->Add(HX_CSTRING("numParams") , NumParams,false);
					__result->Add(HX_CSTRING("paramCutoff") , ParamCutoff,false);
					return __result;
				}
				return null();
			}
		};
		HX_STACK_LINE(30)
		console->commands->__Field(HX_CSTRING("push"),true)(_Function_2_1::Block(this,NumParams,ParamCutoff));
	}
	HX_STACK_LINE(32)
	{
		HX_STACK_LINE(32)
		int NumParams = (int)0;		HX_STACK_VAR(NumParams,"NumParams");
		HX_STACK_LINE(32)
		int ParamCutoff = (int)-1;		HX_STACK_VAR(ParamCutoff,"ParamCutoff");
		struct _Function_2_1{
			inline static Dynamic Block( int &NumParams,int &ParamCutoff){
				HX_STACK_FRAME("*","closure",0x5bdab937,"*.closure","flixel/system/debug/ConsoleCommands.hx",32,0x4441c1e8)
				{
					hx::Anon __result = hx::Anon_obj::Create();
					__result->Add(HX_CSTRING("aliases") , Array_obj< ::String >::__new().Add(HX_CSTRING("clearLog")).Add(HX_CSTRING("clear")),false);
					__result->Add(HX_CSTRING("processFunction") , ::flixel::FlxG_obj::log->clear_dyn(),false);
					__result->Add(HX_CSTRING("help") , HX_CSTRING("Clears the log window."),false);
					__result->Add(HX_CSTRING("paramHelp") , null(),false);
					__result->Add(HX_CSTRING("numParams") , NumParams,false);
					__result->Add(HX_CSTRING("paramCutoff") , ParamCutoff,false);
					return __result;
				}
				return null();
			}
		};
		HX_STACK_LINE(32)
		console->commands->__Field(HX_CSTRING("push"),true)(_Function_2_1::Block(NumParams,ParamCutoff));
	}
	HX_STACK_LINE(34)
	{
		HX_STACK_LINE(34)
		int NumParams = (int)0;		HX_STACK_VAR(NumParams,"NumParams");
		HX_STACK_LINE(34)
		int ParamCutoff = (int)-1;		HX_STACK_VAR(ParamCutoff,"ParamCutoff");
		struct _Function_2_1{
			inline static Dynamic Block( ::flixel::system::debug::ConsoleCommands_obj *__this,int &NumParams,int &ParamCutoff){
				HX_STACK_FRAME("*","closure",0x5bdab937,"*.closure","flixel/system/debug/ConsoleCommands.hx",34,0x4441c1e8)
				{
					hx::Anon __result = hx::Anon_obj::Create();
					__result->Add(HX_CSTRING("aliases") , Array_obj< ::String >::__new().Add(HX_CSTRING("resetState")).Add(HX_CSTRING("rs")),false);
					__result->Add(HX_CSTRING("processFunction") , __this->resetState_dyn(),false);
					__result->Add(HX_CSTRING("help") , HX_CSTRING("Resets the current state."),false);
					__result->Add(HX_CSTRING("paramHelp") , null(),false);
					__result->Add(HX_CSTRING("numParams") , NumParams,false);
					__result->Add(HX_CSTRING("paramCutoff") , ParamCutoff,false);
					return __result;
				}
				return null();
			}
		};
		HX_STACK_LINE(34)
		console->commands->__Field(HX_CSTRING("push"),true)(_Function_2_1::Block(this,NumParams,ParamCutoff));
	}
	HX_STACK_LINE(35)
	{
		HX_STACK_LINE(35)
		int NumParams = (int)0;		HX_STACK_VAR(NumParams,"NumParams");
		HX_STACK_LINE(35)
		int ParamCutoff = (int)-1;		HX_STACK_VAR(ParamCutoff,"ParamCutoff");
		struct _Function_2_1{
			inline static Dynamic Block( ::flixel::system::debug::ConsoleCommands_obj *__this,int &NumParams,int &ParamCutoff){
				HX_STACK_FRAME("*","closure",0x5bdab937,"*.closure","flixel/system/debug/ConsoleCommands.hx",35,0x4441c1e8)
				{
					hx::Anon __result = hx::Anon_obj::Create();
					__result->Add(HX_CSTRING("aliases") , Array_obj< ::String >::__new().Add(HX_CSTRING("switchState")).Add(HX_CSTRING("ss")),false);
					__result->Add(HX_CSTRING("processFunction") , __this->switchState_dyn(),false);
					__result->Add(HX_CSTRING("help") , HX_CSTRING("Switches to a specified state."),false);
					__result->Add(HX_CSTRING("paramHelp") , HX_CSTRING("[FlxState]"),false);
					__result->Add(HX_CSTRING("numParams") , NumParams,false);
					__result->Add(HX_CSTRING("paramCutoff") , ParamCutoff,false);
					return __result;
				}
				return null();
			}
		};
		HX_STACK_LINE(35)
		console->commands->__Field(HX_CSTRING("push"),true)(_Function_2_1::Block(this,NumParams,ParamCutoff));
	}
	HX_STACK_LINE(36)
	{
		HX_STACK_LINE(36)
		int NumParams = (int)0;		HX_STACK_VAR(NumParams,"NumParams");
		HX_STACK_LINE(36)
		int ParamCutoff = (int)-1;		HX_STACK_VAR(ParamCutoff,"ParamCutoff");
		struct _Function_2_1{
			inline static Dynamic Block( ::flixel::system::debug::ConsoleCommands_obj *__this,int &NumParams,int &ParamCutoff){
				HX_STACK_FRAME("*","closure",0x5bdab937,"*.closure","flixel/system/debug/ConsoleCommands.hx",36,0x4441c1e8)
				{
					hx::Anon __result = hx::Anon_obj::Create();
					__result->Add(HX_CSTRING("aliases") , Array_obj< ::String >::__new().Add(HX_CSTRING("resetGame")).Add(HX_CSTRING("rg")),false);
					__result->Add(HX_CSTRING("processFunction") , __this->resetGame_dyn(),false);
					__result->Add(HX_CSTRING("help") , HX_CSTRING("Resets the game."),false);
					__result->Add(HX_CSTRING("paramHelp") , null(),false);
					__result->Add(HX_CSTRING("numParams") , NumParams,false);
					__result->Add(HX_CSTRING("paramCutoff") , ParamCutoff,false);
					return __result;
				}
				return null();
			}
		};
		HX_STACK_LINE(36)
		console->commands->__Field(HX_CSTRING("push"),true)(_Function_2_1::Block(this,NumParams,ParamCutoff));
	}
	struct _Function_1_1{
		inline static Dynamic Block( ::flixel::system::debug::ConsoleCommands_obj *__this){
			HX_STACK_FRAME("*","closure",0x5bdab937,"*.closure","flixel/system/debug/ConsoleCommands.hx",38,0x4441c1e8)
			{
				hx::Anon __result = hx::Anon_obj::Create();
				__result->Add(HX_CSTRING("aliases") , Array_obj< ::String >::__new().Add(HX_CSTRING("create")).Add(HX_CSTRING("cr")),false);
				__result->Add(HX_CSTRING("processFunction") , __this->create_dyn(),false);
				__result->Add(HX_CSTRING("help") , HX_CSTRING("Creates a new FlxObject and registers it - by default at the mouse position."),false);
				__result->Add(HX_CSTRING("paramHelp") , HX_CSTRING("[FlxObject] (MousePos = true)"),false);
				__result->Add(HX_CSTRING("numParams") , (int)3,false);
				__result->Add(HX_CSTRING("paramCutoff") , (int)3,false);
				return __result;
			}
			return null();
		}
	};
	HX_STACK_LINE(38)
	console->commands->__Field(HX_CSTRING("push"),true)(_Function_1_1::Block(this));
	HX_STACK_LINE(40)
	{
		HX_STACK_LINE(40)
		int ParamCutoff = (int)-1;		HX_STACK_VAR(ParamCutoff,"ParamCutoff");
		struct _Function_2_1{
			inline static Dynamic Block( ::flixel::system::debug::ConsoleCommands_obj *__this,int &ParamCutoff){
				HX_STACK_FRAME("*","closure",0x5bdab937,"*.closure","flixel/system/debug/ConsoleCommands.hx",40,0x4441c1e8)
				{
					hx::Anon __result = hx::Anon_obj::Create();
					__result->Add(HX_CSTRING("aliases") , Array_obj< ::String >::__new().Add(HX_CSTRING("set")).Add(HX_CSTRING("s")),false);
					__result->Add(HX_CSTRING("processFunction") , __this->set_dyn(),false);
					__result->Add(HX_CSTRING("help") , HX_CSTRING("Sets a variable within a registered object."),false);
					__result->Add(HX_CSTRING("paramHelp") , HX_CSTRING("[Path to function]"),false);
					__result->Add(HX_CSTRING("numParams") , (int)3,false);
					__result->Add(HX_CSTRING("paramCutoff") , ParamCutoff,false);
					return __result;
				}
				return null();
			}
		};
		HX_STACK_LINE(40)
		console->commands->__Field(HX_CSTRING("push"),true)(_Function_2_1::Block(this,ParamCutoff));
	}
	struct _Function_1_2{
		inline static Dynamic Block( ::flixel::system::debug::ConsoleCommands_obj *__this){
			HX_STACK_FRAME("*","closure",0x5bdab937,"*.closure","flixel/system/debug/ConsoleCommands.hx",41,0x4441c1e8)
			{
				hx::Anon __result = hx::Anon_obj::Create();
				__result->Add(HX_CSTRING("aliases") , Array_obj< ::String >::__new().Add(HX_CSTRING("call")).Add(HX_CSTRING("c")),false);
				__result->Add(HX_CSTRING("processFunction") , __this->call_dyn(),false);
				__result->Add(HX_CSTRING("help") , HX_CSTRING("Calls a registered function / function within a registered object."),false);
				__result->Add(HX_CSTRING("paramHelp") , null(),false);
				__result->Add(HX_CSTRING("numParams") , (int)3,false);
				__result->Add(HX_CSTRING("paramCutoff") , (int)2,false);
				return __result;
			}
			return null();
		}
	};
	HX_STACK_LINE(41)
	console->commands->__Field(HX_CSTRING("push"),true)(_Function_1_2::Block(this));
	HX_STACK_LINE(43)
	{
		HX_STACK_LINE(43)
		int NumParams = (int)0;		HX_STACK_VAR(NumParams,"NumParams");
		HX_STACK_LINE(43)
		int ParamCutoff = (int)-1;		HX_STACK_VAR(ParamCutoff,"ParamCutoff");
		struct _Function_2_1{
			inline static Dynamic Block( ::flixel::system::debug::ConsoleCommands_obj *__this,int &NumParams,int &ParamCutoff){
				HX_STACK_FRAME("*","closure",0x5bdab937,"*.closure","flixel/system/debug/ConsoleCommands.hx",43,0x4441c1e8)
				{
					hx::Anon __result = hx::Anon_obj::Create();
					__result->Add(HX_CSTRING("aliases") , Array_obj< ::String >::__new().Add(HX_CSTRING("listObjects")).Add(HX_CSTRING("lo")),false);
					__result->Add(HX_CSTRING("processFunction") , __this->listObjects_dyn(),false);
					__result->Add(HX_CSTRING("help") , HX_CSTRING("Lists all the aliases of the registered objects."),false);
					__result->Add(HX_CSTRING("paramHelp") , null(),false);
					__result->Add(HX_CSTRING("numParams") , NumParams,false);
					__result->Add(HX_CSTRING("paramCutoff") , ParamCutoff,false);
					return __result;
				}
				return null();
			}
		};
		HX_STACK_LINE(43)
		console->commands->__Field(HX_CSTRING("push"),true)(_Function_2_1::Block(this,NumParams,ParamCutoff));
	}
	HX_STACK_LINE(44)
	{
		HX_STACK_LINE(44)
		int NumParams = (int)0;		HX_STACK_VAR(NumParams,"NumParams");
		HX_STACK_LINE(44)
		int ParamCutoff = (int)-1;		HX_STACK_VAR(ParamCutoff,"ParamCutoff");
		struct _Function_2_1{
			inline static Dynamic Block( ::flixel::system::debug::ConsoleCommands_obj *__this,int &NumParams,int &ParamCutoff){
				HX_STACK_FRAME("*","closure",0x5bdab937,"*.closure","flixel/system/debug/ConsoleCommands.hx",44,0x4441c1e8)
				{
					hx::Anon __result = hx::Anon_obj::Create();
					__result->Add(HX_CSTRING("aliases") , Array_obj< ::String >::__new().Add(HX_CSTRING("listFunctions")).Add(HX_CSTRING("lf")),false);
					__result->Add(HX_CSTRING("processFunction") , __this->listFunctions_dyn(),false);
					__result->Add(HX_CSTRING("help") , HX_CSTRING("Lists all the aliases of the registered objects."),false);
					__result->Add(HX_CSTRING("paramHelp") , null(),false);
					__result->Add(HX_CSTRING("numParams") , NumParams,false);
					__result->Add(HX_CSTRING("paramCutoff") , ParamCutoff,false);
					return __result;
				}
				return null();
			}
		};
		HX_STACK_LINE(44)
		console->commands->__Field(HX_CSTRING("push"),true)(_Function_2_1::Block(this,NumParams,ParamCutoff));
	}
	HX_STACK_LINE(46)
	{
		HX_STACK_LINE(46)
		int NumParams = (int)0;		HX_STACK_VAR(NumParams,"NumParams");
		HX_STACK_LINE(46)
		int ParamCutoff = (int)-1;		HX_STACK_VAR(ParamCutoff,"ParamCutoff");
		struct _Function_2_1{
			inline static Dynamic Block( ::flixel::system::debug::ConsoleCommands_obj *__this,int &NumParams,int &ParamCutoff){
				HX_STACK_FRAME("*","closure",0x5bdab937,"*.closure","flixel/system/debug/ConsoleCommands.hx",46,0x4441c1e8)
				{
					hx::Anon __result = hx::Anon_obj::Create();
					__result->Add(HX_CSTRING("aliases") , Array_obj< ::String >::__new().Add(HX_CSTRING("watchMouse")).Add(HX_CSTRING("wm")),false);
					__result->Add(HX_CSTRING("processFunction") , __this->watchMouse_dyn(),false);
					__result->Add(HX_CSTRING("help") , HX_CSTRING("Adds the mouse coordinates to the watch window."),false);
					__result->Add(HX_CSTRING("paramHelp") , null(),false);
					__result->Add(HX_CSTRING("numParams") , NumParams,false);
					__result->Add(HX_CSTRING("paramCutoff") , ParamCutoff,false);
					return __result;
				}
				return null();
			}
		};
		HX_STACK_LINE(46)
		console->commands->__Field(HX_CSTRING("push"),true)(_Function_2_1::Block(this,NumParams,ParamCutoff));
	}
	HX_STACK_LINE(48)
	{
		HX_STACK_LINE(48)
		int NumParams = (int)0;		HX_STACK_VAR(NumParams,"NumParams");
		HX_STACK_LINE(48)
		int ParamCutoff = (int)-1;		HX_STACK_VAR(ParamCutoff,"ParamCutoff");
		struct _Function_2_1{
			inline static Dynamic Block( ::flixel::system::debug::ConsoleCommands_obj *__this,int &NumParams,int &ParamCutoff){
				HX_STACK_FRAME("*","closure",0x5bdab937,"*.closure","flixel/system/debug/ConsoleCommands.hx",48,0x4441c1e8)
				{
					hx::Anon __result = hx::Anon_obj::Create();
					__result->Add(HX_CSTRING("aliases") , Array_obj< ::String >::__new().Add(HX_CSTRING("pause")).Add(HX_CSTRING("p")),false);
					__result->Add(HX_CSTRING("processFunction") , __this->pause_dyn(),false);
					__result->Add(HX_CSTRING("help") , HX_CSTRING("Toggle between paused and unpaused"),false);
					__result->Add(HX_CSTRING("paramHelp") , null(),false);
					__result->Add(HX_CSTRING("numParams") , NumParams,false);
					__result->Add(HX_CSTRING("paramCutoff") , ParamCutoff,false);
					return __result;
				}
				return null();
			}
		};
		HX_STACK_LINE(48)
		console->commands->__Field(HX_CSTRING("push"),true)(_Function_2_1::Block(this,NumParams,ParamCutoff));
	}
	HX_STACK_LINE(51)
	{
		HX_STACK_LINE(51)
		Dynamic value = hx::ClassOf< ::flixel::FlxG >();		HX_STACK_VAR(value,"value");
		HX_STACK_LINE(51)
		console->registeredObjects->set(HX_CSTRING("FlxG"),value);
	}
}
;
	return null();
}

//ConsoleCommands_obj::~ConsoleCommands_obj() { }

Dynamic ConsoleCommands_obj::__CreateEmpty() { return  new ConsoleCommands_obj; }
hx::ObjectPtr< ConsoleCommands_obj > ConsoleCommands_obj::__new(::flixel::system::debug::Console console)
{  hx::ObjectPtr< ConsoleCommands_obj > result = new ConsoleCommands_obj();
	result->__construct(console);
	return result;}

Dynamic ConsoleCommands_obj::__Create(hx::DynamicArray inArgs)
{  hx::ObjectPtr< ConsoleCommands_obj > result = new ConsoleCommands_obj();
	result->__construct(inArgs[0]);
	return result;}

Void ConsoleCommands_obj::help( ::String Alias){
{
		HX_STACK_FRAME("flixel.system.debug.ConsoleCommands","help",0x2a59fef8,"flixel.system.debug.ConsoleCommands.help","flixel/system/debug/ConsoleCommands.hx",62,0x4441c1e8)
		HX_STACK_THIS(this)
		HX_STACK_ARG(Alias,"Alias")
		HX_STACK_LINE(62)
		if (((Alias == null()))){
			HX_STACK_LINE(64)
			::String output = HX_CSTRING("System commands: ");		HX_STACK_VAR(output,"output");
			HX_STACK_LINE(65)
			{
				HX_STACK_LINE(65)
				int _g = (int)0;		HX_STACK_VAR(_g,"_g");
				HX_STACK_LINE(65)
				Dynamic _g1 = this->_console->commands;		HX_STACK_VAR(_g1,"_g1");
				HX_STACK_LINE(65)
				while(((_g < _g1->__Field(HX_CSTRING("length"),true)))){
					HX_STACK_LINE(65)
					Dynamic command = _g1->__GetItem(_g);		HX_STACK_VAR(command,"command");
					HX_STACK_LINE(65)
					++(_g);
					HX_STACK_LINE(67)
					hx::AddEq(output,(command->__Field(HX_CSTRING("aliases"),true)->__GetItem((int)0) + HX_CSTRING(", ")));
				}
			}
			HX_STACK_LINE(69)
			::flixel::FlxG_obj::log->advanced(Dynamic( Array_obj<Dynamic>::__new().Add(output)),::flixel::system::debug::LogStyle_obj::CONSOLE,null());
			HX_STACK_LINE(70)
			::flixel::FlxG_obj::log->advanced(Dynamic( Array_obj<Dynamic>::__new().Add(HX_CSTRING("help (Command) for more information about a specific command"))),::flixel::system::debug::LogStyle_obj::CONSOLE,null());
		}
		else{
			HX_STACK_LINE(74)
			Dynamic command = ::flixel::system::debug::ConsoleUtil_obj::findCommand(Alias,this->_console->commands);		HX_STACK_VAR(command,"command");
			HX_STACK_LINE(76)
			if (((command != null()))){
				HX_STACK_LINE(78)
				::flixel::FlxG_obj::log->advanced(HX_CSTRING(""),::flixel::system::debug::LogStyle_obj::NORMAL,null());
				HX_STACK_LINE(79)
				::flixel::FlxG_obj::log->advanced(Dynamic( Array_obj<Dynamic>::__new().Add(command->__Field(HX_CSTRING("aliases"),true))),::flixel::system::debug::LogStyle_obj::CONSOLE,null());
				HX_STACK_LINE(81)
				if (((command->__Field(HX_CSTRING("help"),true) != null()))){
					HX_STACK_LINE(82)
					::flixel::FlxG_obj::log->advanced(Dynamic( Array_obj<Dynamic>::__new().Add(command->__Field(HX_CSTRING("help"),true))),::flixel::system::debug::LogStyle_obj::CONSOLE,null());
				}
				HX_STACK_LINE(85)
				::String cutoffHelp = HX_CSTRING("");		HX_STACK_VAR(cutoffHelp,"cutoffHelp");
				HX_STACK_LINE(86)
				if (((command->__Field(HX_CSTRING("paramCutoff"),true) > (int)0))){
					HX_STACK_LINE(87)
					cutoffHelp = HX_CSTRING(" [param0...paramX]");
				}
				HX_STACK_LINE(90)
				if (((bool((command->__Field(HX_CSTRING("paramHelp"),true) != null())) || bool((cutoffHelp != HX_CSTRING("")))))){
					HX_STACK_LINE(91)
					::flixel::FlxG_obj::log->advanced(Dynamic( Array_obj<Dynamic>::__new().Add(((HX_CSTRING("Params: ") + command->__Field(HX_CSTRING("paramHelp"),true)) + cutoffHelp))),::flixel::system::debug::LogStyle_obj::CONSOLE,null());
				}
			}
			else{
				HX_STACK_LINE(96)
				::flixel::FlxG_obj::log->advanced(((HX_CSTRING("A command named '") + Alias) + HX_CSTRING("' does not exist")),::flixel::system::debug::LogStyle_obj::ERROR,true);
			}
		}
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC1(ConsoleCommands_obj,help,(void))

Void ConsoleCommands_obj::close( ){
{
		HX_STACK_FRAME("flixel.system.debug.ConsoleCommands","close",0x0806fba1,"flixel.system.debug.ConsoleCommands.close","flixel/system/debug/ConsoleCommands.hx",103,0x4441c1e8)
		HX_STACK_THIS(this)
		HX_STACK_LINE(103)
		::flixel::FlxG_obj::game->debugger->set_visible(false);
		HX_STACK_LINE(103)
		::flixel::FlxG_obj::debugger->visible = false;
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC0(ConsoleCommands_obj,close,(void))

Void ConsoleCommands_obj::clearHistory( ){
{
		HX_STACK_FRAME("flixel.system.debug.ConsoleCommands","clearHistory",0xd49e427e,"flixel.system.debug.ConsoleCommands.clearHistory","flixel/system/debug/ConsoleCommands.hx",107,0x4441c1e8)
		HX_STACK_THIS(this)
		HX_STACK_LINE(108)
		this->_console->cmdHistory = Array_obj< ::String >::__new();
		HX_STACK_LINE(109)
		::flixel::FlxG_obj::save->flush(null(),null());
		HX_STACK_LINE(110)
		::flixel::FlxG_obj::log->advanced(Dynamic( Array_obj<Dynamic>::__new().Add(HX_CSTRING("clearHistory: Command history cleared"))),::flixel::system::debug::LogStyle_obj::CONSOLE,null());
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC0(ConsoleCommands_obj,clearHistory,(void))

Void ConsoleCommands_obj::resetState( ){
{
		HX_STACK_FRAME("flixel.system.debug.ConsoleCommands","resetState",0x4a33fd39,"flixel.system.debug.ConsoleCommands.resetState","flixel/system/debug/ConsoleCommands.hx",114,0x4441c1e8)
		HX_STACK_THIS(this)
		HX_STACK_LINE(115)
		{
			HX_STACK_LINE(115)
			::Class _g = ::Type_obj::getClass(::flixel::FlxG_obj::game->_state);		HX_STACK_VAR(_g,"_g");
			HX_STACK_LINE(115)
			::flixel::FlxState State = ::Type_obj::createInstance(_g,Dynamic( Array_obj<Dynamic>::__new()));		HX_STACK_VAR(State,"State");
			HX_STACK_LINE(115)
			::flixel::FlxG_obj::game->_requestedState = State;
		}
		HX_STACK_LINE(116)
		::flixel::FlxG_obj::log->advanced(Dynamic( Array_obj<Dynamic>::__new().Add(HX_CSTRING("resetState: State has been reset"))),::flixel::system::debug::LogStyle_obj::CONSOLE,null());
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC0(ConsoleCommands_obj,resetState,(void))

Void ConsoleCommands_obj::switchState( ::String ClassName){
{
		HX_STACK_FRAME("flixel.system.debug.ConsoleCommands","switchState",0x74c44026,"flixel.system.debug.ConsoleCommands.switchState","flixel/system/debug/ConsoleCommands.hx",120,0x4441c1e8)
		HX_STACK_THIS(this)
		HX_STACK_ARG(ClassName,"ClassName")
		HX_STACK_LINE(121)
		Dynamic instance = ::flixel::system::debug::ConsoleUtil_obj::attemptToCreateInstance_flixel_FlxState(ClassName,hx::ClassOf< ::flixel::FlxState >(),null());		HX_STACK_VAR(instance,"instance");
		HX_STACK_LINE(122)
		if (((instance == null()))){
			HX_STACK_LINE(123)
			return null();
		}
		HX_STACK_LINE(126)
		{
			HX_STACK_LINE(126)
			::flixel::FlxState State = instance;		HX_STACK_VAR(State,"State");
			HX_STACK_LINE(126)
			::flixel::FlxG_obj::game->_requestedState = State;
		}
		HX_STACK_LINE(127)
		::flixel::FlxG_obj::log->advanced(Dynamic( Array_obj<Dynamic>::__new().Add(((HX_CSTRING("switchState: New '") + ClassName) + HX_CSTRING("' created")))),::flixel::system::debug::LogStyle_obj::CONSOLE,null());
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC1(ConsoleCommands_obj,switchState,(void))

Void ConsoleCommands_obj::resetGame( ){
{
		HX_STACK_FRAME("flixel.system.debug.ConsoleCommands","resetGame",0x757989ca,"flixel.system.debug.ConsoleCommands.resetGame","flixel/system/debug/ConsoleCommands.hx",131,0x4441c1e8)
		HX_STACK_THIS(this)
		HX_STACK_LINE(132)
		::flixel::FlxG_obj::game->_resetGame = true;
		HX_STACK_LINE(133)
		::flixel::FlxG_obj::log->advanced(Dynamic( Array_obj<Dynamic>::__new().Add(HX_CSTRING("resetGame: Game has been reset"))),::flixel::system::debug::LogStyle_obj::CONSOLE,null());
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC0(ConsoleCommands_obj,resetGame,(void))

Void ConsoleCommands_obj::create( ::String ClassName,::String __o_MousePos,Array< ::String > Params){
::String MousePos = __o_MousePos.Default(HX_CSTRING("true"));
	HX_STACK_FRAME("flixel.system.debug.ConsoleCommands","create",0x6bd2eef3,"flixel.system.debug.ConsoleCommands.create","flixel/system/debug/ConsoleCommands.hx",137,0x4441c1e8)
	HX_STACK_THIS(this)
	HX_STACK_ARG(ClassName,"ClassName")
	HX_STACK_ARG(MousePos,"MousePos")
	HX_STACK_ARG(Params,"Params")
{
		HX_STACK_LINE(138)
		if (((Params == null()))){
			HX_STACK_LINE(139)
			Params = Array_obj< ::String >::__new();
		}
		HX_STACK_LINE(142)
		Dynamic instance = ::flixel::system::debug::ConsoleUtil_obj::attemptToCreateInstance_flixel_FlxObject(ClassName,hx::ClassOf< ::flixel::FlxObject >(),Params);		HX_STACK_VAR(instance,"instance");
		HX_STACK_LINE(143)
		if (((instance == null()))){
			HX_STACK_LINE(144)
			return null();
		}
		HX_STACK_LINE(147)
		::flixel::FlxObject obj = instance;		HX_STACK_VAR(obj,"obj");
		HX_STACK_LINE(149)
		if (((MousePos == HX_CSTRING("true")))){
			HX_STACK_LINE(150)
			obj->set_x(::flixel::FlxG_obj::game->get_mouseX());
			HX_STACK_LINE(151)
			obj->set_y(::flixel::FlxG_obj::game->get_mouseY());
		}
		HX_STACK_LINE(154)
		::flixel::FlxG_obj::game->_state->add(instance);
		HX_STACK_LINE(156)
		if (((Params->length == (int)0))){
			HX_STACK_LINE(157)
			::flixel::FlxG_obj::log->advanced(Dynamic( Array_obj<Dynamic>::__new().Add((((((HX_CSTRING("create: New ") + ClassName) + HX_CSTRING(" created at X = ")) + obj->x) + HX_CSTRING(" Y = ")) + obj->y))),::flixel::system::debug::LogStyle_obj::CONSOLE,null());
		}
		else{
			HX_STACK_LINE(160)
			Dynamic Text = (((((((HX_CSTRING("create: New ") + ClassName) + HX_CSTRING(" created at X = ")) + obj->x) + HX_CSTRING(" Y = ")) + obj->y) + HX_CSTRING(" with params ")) + ::Std_obj::string(Params));		HX_STACK_VAR(Text,"Text");
			HX_STACK_LINE(160)
			::flixel::FlxG_obj::log->advanced(Dynamic( Array_obj<Dynamic>::__new().Add(Text)),::flixel::system::debug::LogStyle_obj::CONSOLE,null());
		}
		HX_STACK_LINE(163)
		this->_console->objectStack->push(instance);
		HX_STACK_LINE(164)
		{
			HX_STACK_LINE(164)
			::String ObjectAlias = ::Std_obj::string(this->_console->objectStack->length);		HX_STACK_VAR(ObjectAlias,"ObjectAlias");
			HX_STACK_LINE(164)
			{
				HX_STACK_LINE(164)
				Dynamic value = instance;		HX_STACK_VAR(value,"value");
				HX_STACK_LINE(164)
				this->_console->registeredObjects->set(ObjectAlias,value);
			}
		}
		HX_STACK_LINE(166)
		::flixel::FlxG_obj::log->advanced(Dynamic( Array_obj<Dynamic>::__new().Add(((((HX_CSTRING("create: ") + ClassName) + HX_CSTRING(" registered as object '")) + this->_console->objectStack->length) + HX_CSTRING("'")))),::flixel::system::debug::LogStyle_obj::CONSOLE,null());
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC3(ConsoleCommands_obj,create,(void))

Void ConsoleCommands_obj::set( ::String ObjectAndVariable,Dynamic NewVariableValue,::String WatchName){
{
		HX_STACK_FRAME("flixel.system.debug.ConsoleCommands","set",0xd373834b,"flixel.system.debug.ConsoleCommands.set","flixel/system/debug/ConsoleCommands.hx",170,0x4441c1e8)
		HX_STACK_THIS(this)
		HX_STACK_ARG(ObjectAndVariable,"ObjectAndVariable")
		HX_STACK_ARG(NewVariableValue,"NewVariableValue")
		HX_STACK_ARG(WatchName,"WatchName")
		HX_STACK_LINE(171)
		Dynamic pathToVariable = ::flixel::system::debug::ConsoleUtil_obj::resolveObjectAndVariable(ObjectAndVariable,this->_console->registeredObjects);		HX_STACK_VAR(pathToVariable,"pathToVariable");
		HX_STACK_LINE(174)
		if (((pathToVariable == null()))){
			HX_STACK_LINE(175)
			return null();
		}
		HX_STACK_LINE(178)
		Dynamic object = pathToVariable->__Field(HX_CSTRING("object"),true);		HX_STACK_VAR(object,"object");
		HX_STACK_LINE(179)
		::String varName = pathToVariable->__Field(HX_CSTRING("variableName"),true);		HX_STACK_VAR(varName,"varName");
		HX_STACK_LINE(180)
		Dynamic variable = null();		HX_STACK_VAR(variable,"variable");
		HX_STACK_LINE(182)
		try
		{
		HX_STACK_CATCHABLE(Dynamic, 0);
		{
			HX_STACK_LINE(184)
			variable = (  (((object == null()))) ? Dynamic(null()) : Dynamic(object->__Field(varName,true)) );
		}
		}
		catch(Dynamic __e){
			{
				HX_STACK_BEGIN_CATCH
				Dynamic e = __e;{
					HX_STACK_LINE(188)
					return null();
				}
			}
		}
		HX_STACK_LINE(192)
		if ((::Std_obj::is(variable,hx::ClassOf< ::Bool >()))){
			HX_STACK_LINE(194)
			::String oldVal = NewVariableValue;		HX_STACK_VAR(oldVal,"oldVal");
			HX_STACK_LINE(195)
			NewVariableValue = ::flixel::system::debug::ConsoleUtil_obj::parseBool(NewVariableValue);
			HX_STACK_LINE(197)
			if (((NewVariableValue == null()))){
				HX_STACK_LINE(199)
				::flixel::FlxG_obj::log->advanced(((((HX_CSTRING("set: '") + oldVal) + HX_CSTRING("' is not a valid value for Bool '")) + varName) + HX_CSTRING("'")),::flixel::system::debug::LogStyle_obj::ERROR,true);
				HX_STACK_LINE(200)
				return null();
			}
		}
		HX_STACK_LINE(205)
		if (((  ((::Std_obj::is(variable,hx::ClassOf< ::Float >()))) ? bool(::Math_obj::isNaN(::Std_obj::parseFloat(NewVariableValue))) : bool(false) ))){
			HX_STACK_LINE(207)
			{
				HX_STACK_LINE(207)
				Dynamic Data = ((((HX_CSTRING("set: '") + ::Std_obj::string(NewVariableValue)) + HX_CSTRING("' is not a valid value for number '")) + varName) + HX_CSTRING("'"));		HX_STACK_VAR(Data,"Data");
				HX_STACK_LINE(207)
				::flixel::FlxG_obj::log->advanced(Data,::flixel::system::debug::LogStyle_obj::ERROR,true);
			}
			HX_STACK_LINE(208)
			return null();
		}
		else{
			HX_STACK_LINE(211)
			if (((  (((  ((!(::Std_obj::is(variable,hx::ClassOf< ::Float >())))) ? bool(!(::Std_obj::is(variable,hx::ClassOf< ::Bool >()))) : bool(false) ))) ? bool(!(::Std_obj::is(variable,hx::ClassOf< ::String >()))) : bool(false) ))){
				HX_STACK_LINE(213)
				{
					HX_STACK_LINE(213)
					Dynamic Data;		HX_STACK_VAR(Data,"Data");
					struct _Function_4_1{
						inline static ::String Block( Dynamic &variable){
							HX_STACK_FRAME("*","closure",0x5bdab937,"*.closure","flixel/system/debug/ConsoleCommands.hx",213,0x4441c1e8)
							{
								HX_STACK_LINE(213)
								::Class cl;		HX_STACK_VAR(cl,"cl");
								HX_STACK_LINE(213)
								if ((::Std_obj::is(variable,hx::ClassOf< ::Class >()))){
									HX_STACK_LINE(213)
									cl = variable;
								}
								else{
									HX_STACK_LINE(213)
									cl = ::Type_obj::getClass(variable);
								}
								HX_STACK_LINE(213)
								::String s = ::Type_obj::getClassName(cl);		HX_STACK_VAR(s,"s");
								HX_STACK_LINE(213)
								if (((s != null()))){
									HX_STACK_LINE(213)
									s = ::StringTools_obj::replace(s,HX_CSTRING("::"),HX_CSTRING("."));
									HX_STACK_LINE(213)
									s = s.substr((s.lastIndexOf(HX_CSTRING("."),null()) + (int)1),null());
								}
								HX_STACK_LINE(213)
								return s;
							}
							return null();
						}
					};
					HX_STACK_LINE(213)
					Data = ((((HX_CSTRING("set: '") + varName) + HX_CSTRING(":")) + _Function_4_1::Block(variable)) + HX_CSTRING("' is not of a simple type (number, bool or string)"));
					HX_STACK_LINE(213)
					::flixel::FlxG_obj::log->advanced(Data,::flixel::system::debug::LogStyle_obj::ERROR,true);
				}
				HX_STACK_LINE(214)
				return null();
			}
		}
		HX_STACK_LINE(217)
		if (((object != null()))){
			HX_STACK_LINE(217)
			object->__SetField(varName,NewVariableValue,true);
		}
		HX_STACK_LINE(218)
		{
			HX_STACK_LINE(218)
			::String _g;		HX_STACK_VAR(_g,"_g");
			struct _Function_2_1{
				inline static ::String Block( Dynamic &object){
					HX_STACK_FRAME("*","closure",0x5bdab937,"*.closure","flixel/system/debug/ConsoleCommands.hx",218,0x4441c1e8)
					{
						HX_STACK_LINE(218)
						::Class cl;		HX_STACK_VAR(cl,"cl");
						HX_STACK_LINE(218)
						if ((::Std_obj::is(object,hx::ClassOf< ::Class >()))){
							HX_STACK_LINE(218)
							cl = object;
						}
						else{
							HX_STACK_LINE(218)
							cl = ::Type_obj::getClass(object);
						}
						HX_STACK_LINE(218)
						::String s = ::Type_obj::getClassName(cl);		HX_STACK_VAR(s,"s");
						HX_STACK_LINE(218)
						if (((s != null()))){
							HX_STACK_LINE(218)
							s = ::StringTools_obj::replace(s,HX_CSTRING("::"),HX_CSTRING("."));
							HX_STACK_LINE(218)
							s = s.substr((s.lastIndexOf(HX_CSTRING("."),null()) + (int)1),null());
						}
						HX_STACK_LINE(218)
						return s;
					}
					return null();
				}
			};
			HX_STACK_LINE(218)
			_g = ((((HX_CSTRING("set: ") + _Function_2_1::Block(object)) + HX_CSTRING(".")) + varName) + HX_CSTRING(" is now "));
			HX_STACK_LINE(218)
			Dynamic Text = (_g + ::Std_obj::string(NewVariableValue));		HX_STACK_VAR(Text,"Text");
			HX_STACK_LINE(218)
			::flixel::FlxG_obj::log->advanced(Dynamic( Array_obj<Dynamic>::__new().Add(Text)),::flixel::system::debug::LogStyle_obj::CONSOLE,null());
		}
		HX_STACK_LINE(220)
		if (((WatchName != null()))){
			HX_STACK_LINE(221)
			::flixel::FlxG_obj::game->debugger->watch->add(object,varName,WatchName);
		}
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC3(ConsoleCommands_obj,set,(void))

Void ConsoleCommands_obj::call( ::String FunctionAlias,Array< ::String > Params){
{
		HX_STACK_FRAME("flixel.system.debug.ConsoleCommands","call",0x2708e4d5,"flixel.system.debug.ConsoleCommands.call","flixel/system/debug/ConsoleCommands.hx",226,0x4441c1e8)
		HX_STACK_THIS(this)
		HX_STACK_ARG(FunctionAlias,"FunctionAlias")
		HX_STACK_ARG(Params,"Params")
		HX_STACK_LINE(227)
		if (((Params == null()))){
			HX_STACK_LINE(228)
			Params = Array_obj< ::String >::__new();
		}
		HX_STACK_LINE(232)
		Dynamic func = this->_console->registeredFunctions->get(FunctionAlias);		HX_STACK_VAR(func,"func");
		HX_STACK_LINE(235)
		if ((!(::Reflect_obj::isFunction(func)))){
			HX_STACK_LINE(237)
			Array< ::String > searchArr = FunctionAlias.split(HX_CSTRING("."));		HX_STACK_VAR(searchArr,"searchArr");
			HX_STACK_LINE(238)
			::String objectName = searchArr->shift();		HX_STACK_VAR(objectName,"objectName");
			HX_STACK_LINE(239)
			Dynamic object = this->_console->registeredObjects->get(objectName);		HX_STACK_VAR(object,"object");
			HX_STACK_LINE(241)
			if ((!(::Reflect_obj::isObject(object)))){
				HX_STACK_LINE(243)
				{
					HX_STACK_LINE(243)
					Dynamic Data;		HX_STACK_VAR(Data,"Data");
					struct _Function_4_1{
						inline static ::String Block( Dynamic &object){
							HX_STACK_FRAME("*","closure",0x5bdab937,"*.closure","flixel/system/debug/ConsoleCommands.hx",243,0x4441c1e8)
							{
								HX_STACK_LINE(243)
								::Class cl;		HX_STACK_VAR(cl,"cl");
								HX_STACK_LINE(243)
								if ((::Std_obj::is(object,hx::ClassOf< ::Class >()))){
									HX_STACK_LINE(243)
									cl = object;
								}
								else{
									HX_STACK_LINE(243)
									cl = ::Type_obj::getClass(object);
								}
								HX_STACK_LINE(243)
								::String s = ::Type_obj::getClassName(cl);		HX_STACK_VAR(s,"s");
								HX_STACK_LINE(243)
								if (((s != null()))){
									HX_STACK_LINE(243)
									s = ::StringTools_obj::replace(s,HX_CSTRING("::"),HX_CSTRING("."));
									HX_STACK_LINE(243)
									s = s.substr((s.lastIndexOf(HX_CSTRING("."),null()) + (int)1),null());
								}
								HX_STACK_LINE(243)
								return s;
							}
							return null();
						}
					};
					HX_STACK_LINE(243)
					Data = ((HX_CSTRING("call: '") + _Function_4_1::Block(object)) + HX_CSTRING("' is not a valid Object to call"));
					HX_STACK_LINE(243)
					::flixel::FlxG_obj::log->advanced(Data,::flixel::system::debug::LogStyle_obj::ERROR,true);
				}
				HX_STACK_LINE(244)
				return null();
			}
			HX_STACK_LINE(247)
			Dynamic tempObj = object;		HX_STACK_VAR(tempObj,"tempObj");
			HX_STACK_LINE(248)
			::String tempVarName = HX_CSTRING("");		HX_STACK_VAR(tempVarName,"tempVarName");
			HX_STACK_LINE(249)
			::String funcName = HX_CSTRING("");		HX_STACK_VAR(funcName,"funcName");
			HX_STACK_LINE(250)
			int l = (searchArr->length - (int)1);		HX_STACK_VAR(l,"l");
			HX_STACK_LINE(251)
			{
				HX_STACK_LINE(251)
				int _g = (int)0;		HX_STACK_VAR(_g,"_g");
				HX_STACK_LINE(251)
				while(((_g < l))){
					HX_STACK_LINE(251)
					int i = (_g)++;		HX_STACK_VAR(i,"i");
					HX_STACK_LINE(253)
					tempVarName = searchArr->__get(i);
					HX_STACK_LINE(255)
					try
					{
					HX_STACK_CATCHABLE(Dynamic, 0);
					{
						HX_STACK_LINE(257)
						Dynamic prop;		HX_STACK_VAR(prop,"prop");
						HX_STACK_LINE(257)
						prop = (  (((tempObj == null()))) ? Dynamic(null()) : Dynamic(tempObj->__Field(tempVarName,true)) );
					}
					}
					catch(Dynamic __e){
						{
							HX_STACK_BEGIN_CATCH
							Dynamic e = __e;{
								HX_STACK_LINE(261)
								{
									HX_STACK_LINE(261)
									Dynamic Data;		HX_STACK_VAR(Data,"Data");
									struct _Function_6_1{
										inline static ::String Block( Dynamic &tempObj){
											HX_STACK_FRAME("*","closure",0x5bdab937,"*.closure","flixel/system/debug/ConsoleCommands.hx",261,0x4441c1e8)
											{
												HX_STACK_LINE(261)
												::Class cl;		HX_STACK_VAR(cl,"cl");
												HX_STACK_LINE(261)
												if ((::Std_obj::is(tempObj,hx::ClassOf< ::Class >()))){
													HX_STACK_LINE(261)
													cl = tempObj;
												}
												else{
													HX_STACK_LINE(261)
													cl = ::Type_obj::getClass(tempObj);
												}
												HX_STACK_LINE(261)
												::String s = ::Type_obj::getClassName(cl);		HX_STACK_VAR(s,"s");
												HX_STACK_LINE(261)
												if (((s != null()))){
													HX_STACK_LINE(261)
													s = ::StringTools_obj::replace(s,HX_CSTRING("::"),HX_CSTRING("."));
													HX_STACK_LINE(261)
													s = s.substr((s.lastIndexOf(HX_CSTRING("."),null()) + (int)1),null());
												}
												HX_STACK_LINE(261)
												return s;
											}
											return null();
										}
									};
									HX_STACK_LINE(261)
									Data = ((((HX_CSTRING("call: ") + _Function_6_1::Block(tempObj)) + HX_CSTRING(" does not have a field '")) + tempVarName) + HX_CSTRING("' to call"));
									HX_STACK_LINE(261)
									::flixel::FlxG_obj::log->advanced(Data,::flixel::system::debug::LogStyle_obj::ERROR,true);
								}
								HX_STACK_LINE(262)
								return null();
							}
						}
					}
					HX_STACK_LINE(265)
					tempObj = (  (((tempObj == null()))) ? Dynamic(null()) : Dynamic(tempObj->__Field(tempVarName,true)) );
				}
			}
			HX_STACK_LINE(268)
			func = ::Reflect_obj::field(tempObj,searchArr->__get(l));
			HX_STACK_LINE(270)
			if (((func == null()))){
				HX_STACK_LINE(272)
				{
					HX_STACK_LINE(272)
					Dynamic Data;		HX_STACK_VAR(Data,"Data");
					struct _Function_4_1{
						inline static ::String Block( Dynamic &tempObj){
							HX_STACK_FRAME("*","closure",0x5bdab937,"*.closure","flixel/system/debug/ConsoleCommands.hx",272,0x4441c1e8)
							{
								HX_STACK_LINE(272)
								::Class cl;		HX_STACK_VAR(cl,"cl");
								HX_STACK_LINE(272)
								if ((::Std_obj::is(tempObj,hx::ClassOf< ::Class >()))){
									HX_STACK_LINE(272)
									cl = tempObj;
								}
								else{
									HX_STACK_LINE(272)
									cl = ::Type_obj::getClass(tempObj);
								}
								HX_STACK_LINE(272)
								::String s = ::Type_obj::getClassName(cl);		HX_STACK_VAR(s,"s");
								HX_STACK_LINE(272)
								if (((s != null()))){
									HX_STACK_LINE(272)
									s = ::StringTools_obj::replace(s,HX_CSTRING("::"),HX_CSTRING("."));
									HX_STACK_LINE(272)
									s = s.substr((s.lastIndexOf(HX_CSTRING("."),null()) + (int)1),null());
								}
								HX_STACK_LINE(272)
								return s;
							}
							return null();
						}
					};
					HX_STACK_LINE(272)
					Data = ((((HX_CSTRING("call: ") + _Function_4_1::Block(tempObj)) + HX_CSTRING(" does not have a method '")) + searchArr->__get(l)) + HX_CSTRING("' to call"));
					HX_STACK_LINE(272)
					::flixel::FlxG_obj::log->advanced(Data,::flixel::system::debug::LogStyle_obj::ERROR,true);
				}
				HX_STACK_LINE(273)
				return null();
			}
		}
		HX_STACK_LINE(277)
		if ((::Reflect_obj::isFunction(func))){
			HX_STACK_LINE(279)
			bool success = ::flixel::system::debug::ConsoleUtil_obj::callFunction(func,Params);		HX_STACK_VAR(success,"success");
			HX_STACK_LINE(281)
			if (((bool((Params->length == (int)0)) && bool(success)))){
				HX_STACK_LINE(282)
				::flixel::FlxG_obj::log->advanced(Dynamic( Array_obj<Dynamic>::__new().Add(((HX_CSTRING("call: Called '") + FunctionAlias) + HX_CSTRING("()'")))),::flixel::system::debug::LogStyle_obj::CONSOLE,null());
			}
			else{
				HX_STACK_LINE(284)
				if ((success)){
					HX_STACK_LINE(285)
					Dynamic Text = (((HX_CSTRING("call: Called '") + FunctionAlias) + HX_CSTRING("()' with params ")) + ::Std_obj::string(Params));		HX_STACK_VAR(Text,"Text");
					HX_STACK_LINE(285)
					::flixel::FlxG_obj::log->advanced(Dynamic( Array_obj<Dynamic>::__new().Add(Text)),::flixel::system::debug::LogStyle_obj::CONSOLE,null());
				}
			}
		}
		else{
			HX_STACK_LINE(289)
			::flixel::FlxG_obj::log->advanced(((HX_CSTRING("call: '") + FunctionAlias) + HX_CSTRING("' is not a valid function")),::flixel::system::debug::LogStyle_obj::ERROR,true);
		}
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC2(ConsoleCommands_obj,call,(void))

Void ConsoleCommands_obj::listObjects( ){
{
		HX_STACK_FRAME("flixel.system.debug.ConsoleCommands","listObjects",0x368814bf,"flixel.system.debug.ConsoleCommands.listObjects","flixel/system/debug/ConsoleCommands.hx",295,0x4441c1e8)
		HX_STACK_THIS(this)
		HX_STACK_LINE(295)
		Dynamic Text;		HX_STACK_VAR(Text,"Text");
		struct _Function_1_1{
			inline static ::String Block( ::flixel::system::debug::ConsoleCommands_obj *__this){
				HX_STACK_FRAME("*","closure",0x5bdab937,"*.closure","flixel/system/debug/ConsoleCommands.hx",295,0x4441c1e8)
				{
					HX_STACK_LINE(295)
					::String string = HX_CSTRING("");		HX_STACK_VAR(string,"string");
					HX_STACK_LINE(295)
					for(::cpp::FastIterator_obj< ::String > *__it = ::cpp::CreateFastIterator< ::String >(__this->_console->registeredObjects->keys());  __it->hasNext(); ){
						::String key = __it->next();
						{
							HX_STACK_LINE(295)
							hx::AddEq(string,::Std_obj::string(key));
							HX_STACK_LINE(295)
							hx::AddEq(string,HX_CSTRING(", "));
						}
;
					}
					HX_STACK_LINE(295)
					return string.substring((int)0,(string.length - (int)2));
				}
				return null();
			}
		};
		HX_STACK_LINE(295)
		Text = (HX_CSTRING("Objects registered: \n") + _Function_1_1::Block(this));
		HX_STACK_LINE(295)
		::flixel::FlxG_obj::log->advanced(Dynamic( Array_obj<Dynamic>::__new().Add(Text)),::flixel::system::debug::LogStyle_obj::CONSOLE,null());
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC0(ConsoleCommands_obj,listObjects,(void))

Void ConsoleCommands_obj::listFunctions( ){
{
		HX_STACK_FRAME("flixel.system.debug.ConsoleCommands","listFunctions",0x68aec706,"flixel.system.debug.ConsoleCommands.listFunctions","flixel/system/debug/ConsoleCommands.hx",300,0x4441c1e8)
		HX_STACK_THIS(this)
		HX_STACK_LINE(300)
		Dynamic Text;		HX_STACK_VAR(Text,"Text");
		struct _Function_1_1{
			inline static ::String Block( ::flixel::system::debug::ConsoleCommands_obj *__this){
				HX_STACK_FRAME("*","closure",0x5bdab937,"*.closure","flixel/system/debug/ConsoleCommands.hx",300,0x4441c1e8)
				{
					HX_STACK_LINE(300)
					::String string = HX_CSTRING("");		HX_STACK_VAR(string,"string");
					HX_STACK_LINE(300)
					for(::cpp::FastIterator_obj< ::String > *__it = ::cpp::CreateFastIterator< ::String >(__this->_console->registeredFunctions->keys());  __it->hasNext(); ){
						::String key = __it->next();
						{
							HX_STACK_LINE(300)
							hx::AddEq(string,::Std_obj::string(key));
							HX_STACK_LINE(300)
							hx::AddEq(string,HX_CSTRING(", "));
						}
;
					}
					HX_STACK_LINE(300)
					return string.substring((int)0,(string.length - (int)2));
				}
				return null();
			}
		};
		HX_STACK_LINE(300)
		Text = (HX_CSTRING("Functions registered: \n") + _Function_1_1::Block(this));
		HX_STACK_LINE(300)
		::flixel::FlxG_obj::log->advanced(Dynamic( Array_obj<Dynamic>::__new().Add(Text)),::flixel::system::debug::LogStyle_obj::CONSOLE,null());
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC0(ConsoleCommands_obj,listFunctions,(void))

Void ConsoleCommands_obj::watchMouse( ){
{
		HX_STACK_FRAME("flixel.system.debug.ConsoleCommands","watchMouse",0x61fb80cd,"flixel.system.debug.ConsoleCommands.watchMouse","flixel/system/debug/ConsoleCommands.hx",304,0x4441c1e8)
		HX_STACK_THIS(this)
		HX_STACK_LINE(305)
		if ((!(this->_watchingMouse))){
			HX_STACK_LINE(307)
			::flixel::FlxG_obj::game->debugger->watch->add(hx::ClassOf< ::flixel::FlxG >(),HX_CSTRING("mouse"),HX_CSTRING("Mouse Position"));
			HX_STACK_LINE(308)
			::flixel::FlxG_obj::log->advanced(Dynamic( Array_obj<Dynamic>::__new().Add(HX_CSTRING("watchMouse: Mouse position added to watch window"))),::flixel::system::debug::LogStyle_obj::CONSOLE,null());
		}
		else{
			HX_STACK_LINE(312)
			::flixel::FlxG_obj::game->debugger->watch->remove(hx::ClassOf< ::flixel::FlxG >(),HX_CSTRING("mouse"),null());
			HX_STACK_LINE(313)
			::flixel::FlxG_obj::log->advanced(Dynamic( Array_obj<Dynamic>::__new().Add(HX_CSTRING("watchMouse: Mouse position removed from watch window"))),::flixel::system::debug::LogStyle_obj::CONSOLE,null());
		}
		HX_STACK_LINE(316)
		this->_watchingMouse = !(this->_watchingMouse);
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC0(ConsoleCommands_obj,watchMouse,(void))

Void ConsoleCommands_obj::pause( ){
{
		HX_STACK_FRAME("flixel.system.debug.ConsoleCommands","pause",0x7cfbbadf,"flixel.system.debug.ConsoleCommands.pause","flixel/system/debug/ConsoleCommands.hx",321,0x4441c1e8)
		HX_STACK_THIS(this)
		HX_STACK_LINE(321)
		if ((::flixel::FlxG_obj::vcr->paused)){
			HX_STACK_LINE(323)
			::flixel::FlxG_obj::vcr->resume();
			HX_STACK_LINE(324)
			::flixel::FlxG_obj::log->advanced(Dynamic( Array_obj<Dynamic>::__new().Add(HX_CSTRING("pause: Game unpaused"))),::flixel::system::debug::LogStyle_obj::CONSOLE,null());
		}
		else{
			HX_STACK_LINE(328)
			::flixel::FlxG_obj::vcr->pause();
			HX_STACK_LINE(329)
			::flixel::FlxG_obj::log->advanced(Dynamic( Array_obj<Dynamic>::__new().Add(HX_CSTRING("pause: Game paused"))),::flixel::system::debug::LogStyle_obj::CONSOLE,null());
		}
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC0(ConsoleCommands_obj,pause,(void))


ConsoleCommands_obj::ConsoleCommands_obj()
{
}

void ConsoleCommands_obj::__Mark(HX_MARK_PARAMS)
{
	HX_MARK_BEGIN_CLASS(ConsoleCommands);
	HX_MARK_MEMBER_NAME(_console,"_console");
	HX_MARK_MEMBER_NAME(_watchingMouse,"_watchingMouse");
	HX_MARK_END_CLASS();
}

void ConsoleCommands_obj::__Visit(HX_VISIT_PARAMS)
{
	HX_VISIT_MEMBER_NAME(_console,"_console");
	HX_VISIT_MEMBER_NAME(_watchingMouse,"_watchingMouse");
}

Dynamic ConsoleCommands_obj::__Field(const ::String &inName,bool inCallProp)
{
	switch(inName.length) {
	case 3:
		if (HX_FIELD_EQ(inName,"set") ) { return set_dyn(); }
		break;
	case 4:
		if (HX_FIELD_EQ(inName,"help") ) { return help_dyn(); }
		if (HX_FIELD_EQ(inName,"call") ) { return call_dyn(); }
		break;
	case 5:
		if (HX_FIELD_EQ(inName,"close") ) { return close_dyn(); }
		if (HX_FIELD_EQ(inName,"pause") ) { return pause_dyn(); }
		break;
	case 6:
		if (HX_FIELD_EQ(inName,"create") ) { return create_dyn(); }
		break;
	case 8:
		if (HX_FIELD_EQ(inName,"_console") ) { return _console; }
		break;
	case 9:
		if (HX_FIELD_EQ(inName,"resetGame") ) { return resetGame_dyn(); }
		break;
	case 10:
		if (HX_FIELD_EQ(inName,"resetState") ) { return resetState_dyn(); }
		if (HX_FIELD_EQ(inName,"watchMouse") ) { return watchMouse_dyn(); }
		break;
	case 11:
		if (HX_FIELD_EQ(inName,"switchState") ) { return switchState_dyn(); }
		if (HX_FIELD_EQ(inName,"listObjects") ) { return listObjects_dyn(); }
		break;
	case 12:
		if (HX_FIELD_EQ(inName,"clearHistory") ) { return clearHistory_dyn(); }
		break;
	case 13:
		if (HX_FIELD_EQ(inName,"listFunctions") ) { return listFunctions_dyn(); }
		break;
	case 14:
		if (HX_FIELD_EQ(inName,"_watchingMouse") ) { return _watchingMouse; }
	}
	return super::__Field(inName,inCallProp);
}

Dynamic ConsoleCommands_obj::__SetField(const ::String &inName,const Dynamic &inValue,bool inCallProp)
{
	switch(inName.length) {
	case 8:
		if (HX_FIELD_EQ(inName,"_console") ) { _console=inValue.Cast< ::flixel::system::debug::Console >(); return inValue; }
		break;
	case 14:
		if (HX_FIELD_EQ(inName,"_watchingMouse") ) { _watchingMouse=inValue.Cast< bool >(); return inValue; }
	}
	return super::__SetField(inName,inValue,inCallProp);
}

void ConsoleCommands_obj::__GetFields(Array< ::String> &outFields)
{
	outFields->push(HX_CSTRING("_console"));
	outFields->push(HX_CSTRING("_watchingMouse"));
	super::__GetFields(outFields);
};

static ::String sStaticFields[] = {
	String(null()) };

#if HXCPP_SCRIPTABLE
static hx::StorageInfo sMemberStorageInfo[] = {
	{hx::fsObject /*::flixel::system::debug::Console*/ ,(int)offsetof(ConsoleCommands_obj,_console),HX_CSTRING("_console")},
	{hx::fsBool,(int)offsetof(ConsoleCommands_obj,_watchingMouse),HX_CSTRING("_watchingMouse")},
	{ hx::fsUnknown, 0, null()}
};
#endif

static ::String sMemberFields[] = {
	HX_CSTRING("_console"),
	HX_CSTRING("_watchingMouse"),
	HX_CSTRING("help"),
	HX_CSTRING("close"),
	HX_CSTRING("clearHistory"),
	HX_CSTRING("resetState"),
	HX_CSTRING("switchState"),
	HX_CSTRING("resetGame"),
	HX_CSTRING("create"),
	HX_CSTRING("set"),
	HX_CSTRING("call"),
	HX_CSTRING("listObjects"),
	HX_CSTRING("listFunctions"),
	HX_CSTRING("watchMouse"),
	HX_CSTRING("pause"),
	String(null()) };

static void sMarkStatics(HX_MARK_PARAMS) {
	HX_MARK_MEMBER_NAME(ConsoleCommands_obj::__mClass,"__mClass");
};

#ifdef HXCPP_VISIT_ALLOCS
static void sVisitStatics(HX_VISIT_PARAMS) {
	HX_VISIT_MEMBER_NAME(ConsoleCommands_obj::__mClass,"__mClass");
};

#endif

Class ConsoleCommands_obj::__mClass;

void ConsoleCommands_obj::__register()
{
	hx::Static(__mClass) = hx::RegisterClass(HX_CSTRING("flixel.system.debug.ConsoleCommands"), hx::TCanCast< ConsoleCommands_obj> ,sStaticFields,sMemberFields,
	&__CreateEmpty, &__Create,
	&super::__SGetClass(), 0, sMarkStatics
#ifdef HXCPP_VISIT_ALLOCS
    , sVisitStatics
#endif
#ifdef HXCPP_SCRIPTABLE
    , sMemberStorageInfo
#endif
);
}

void ConsoleCommands_obj::__boot()
{
}

} // end namespace flixel
} // end namespace system
} // end namespace debug
