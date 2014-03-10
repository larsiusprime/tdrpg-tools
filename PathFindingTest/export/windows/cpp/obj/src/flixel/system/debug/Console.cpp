#include <hxcpp.h>

#ifndef INCLUDED_IMap
#include <IMap.h>
#endif
#ifndef INCLUDED_Reflect
#include <Reflect.h>
#endif
#ifndef INCLUDED_StringTools
#include <StringTools.h>
#endif
#ifndef INCLUDED_flash_Lib
#include <flash/Lib.h>
#endif
#ifndef INCLUDED_flash_display_BitmapData
#include <flash/display/BitmapData.h>
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
#ifndef INCLUDED_flash_display_MovieClip
#include <flash/display/MovieClip.h>
#endif
#ifndef INCLUDED_flash_display_Sprite
#include <flash/display/Sprite.h>
#endif
#ifndef INCLUDED_flash_display_Stage
#include <flash/display/Stage.h>
#endif
#ifndef INCLUDED_flash_events_Event
#include <flash/events/Event.h>
#endif
#ifndef INCLUDED_flash_events_EventDispatcher
#include <flash/events/EventDispatcher.h>
#endif
#ifndef INCLUDED_flash_events_FocusEvent
#include <flash/events/FocusEvent.h>
#endif
#ifndef INCLUDED_flash_events_IEventDispatcher
#include <flash/events/IEventDispatcher.h>
#endif
#ifndef INCLUDED_flash_events_KeyboardEvent
#include <flash/events/KeyboardEvent.h>
#endif
#ifndef INCLUDED_flash_geom_Rectangle
#include <flash/geom/Rectangle.h>
#endif
#ifndef INCLUDED_flash_text_TextField
#include <flash/text/TextField.h>
#endif
#ifndef INCLUDED_flash_text_TextFieldType
#include <flash/text/TextFieldType.h>
#endif
#ifndef INCLUDED_flash_text_TextFormat
#include <flash/text/TextFormat.h>
#endif
#ifndef INCLUDED_flash_ui_Keyboard
#include <flash/ui/Keyboard.h>
#endif
#ifndef INCLUDED_flixel_FlxBasic
#include <flixel/FlxBasic.h>
#endif
#ifndef INCLUDED_flixel_FlxG
#include <flixel/FlxG.h>
#endif
#ifndef INCLUDED_flixel_FlxObject
#include <flixel/FlxObject.h>
#endif
#ifndef INCLUDED_flixel_input_keyboard_FlxKeyboard
#include <flixel/input/keyboard/FlxKeyboard.h>
#endif
#ifndef INCLUDED_flixel_interfaces_IFlxDestroyable
#include <flixel/interfaces/IFlxDestroyable.h>
#endif
#ifndef INCLUDED_flixel_interfaces_IFlxInput
#include <flixel/interfaces/IFlxInput.h>
#endif
#ifndef INCLUDED_flixel_system_FlxAssets
#include <flixel/system/FlxAssets.h>
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
#ifndef INCLUDED_flixel_system_debug_GraphicConsole
#include <flixel/system/debug/GraphicConsole.h>
#endif
#ifndef INCLUDED_flixel_system_debug_LogStyle
#include <flixel/system/debug/LogStyle.h>
#endif
#ifndef INCLUDED_flixel_system_debug_Window
#include <flixel/system/debug/Window.h>
#endif
#ifndef INCLUDED_flixel_system_frontEnds_LogFrontEnd
#include <flixel/system/frontEnds/LogFrontEnd.h>
#endif
#ifndef INCLUDED_flixel_util_FlxSave
#include <flixel/util/FlxSave.h>
#endif
#ifndef INCLUDED_haxe_ds_StringMap
#include <haxe/ds/StringMap.h>
#endif
namespace flixel{
namespace system{
namespace debug{

Void Console_obj::__construct()
{
HX_STACK_FRAME("flixel.system.debug.Console","new",0x1c127021,"flixel.system.debug.Console.new","flixel/system/debug/Console.hx",24,0x3559cbd0)
{
	HX_STACK_LINE(63)
	this->_historyIndex = (int)0;
	HX_STACK_LINE(74)
	super::__construct(HX_CSTRING("console"),::flixel::system::debug::GraphicConsole_obj::__new((int)0,(int)0,null(),null()),(int)0,(int)0,false,null(),null());
	HX_STACK_LINE(76)
	this->commands = Dynamic( Array_obj<Dynamic>::__new() );
	HX_STACK_LINE(78)
	this->registeredObjects = ::haxe::ds::StringMap_obj::__new();
	HX_STACK_LINE(79)
	this->registeredFunctions = ::haxe::ds::StringMap_obj::__new();
	HX_STACK_LINE(81)
	this->objectStack = Array_obj< ::Dynamic >::__new();
	HX_STACK_LINE(83)
	this->cmdHistory = Array_obj< ::String >::__new();
	HX_STACK_LINE(86)
	if (((::flixel::FlxG_obj::save->data->__Field(HX_CSTRING("history"),true) != null()))){
		HX_STACK_LINE(87)
		this->cmdHistory = ::flixel::FlxG_obj::save->data->__Field(HX_CSTRING("history"),true);
		HX_STACK_LINE(88)
		this->_historyIndex = this->cmdHistory->length;
	}
	else{
		HX_STACK_LINE(91)
		this->cmdHistory = Array_obj< ::String >::__new();
		HX_STACK_LINE(92)
		::flixel::FlxG_obj::save->data->__FieldRef(HX_CSTRING("history")) = this->cmdHistory;
	}
	HX_STACK_LINE(96)
	this->_input = ::flash::text::TextField_obj::__new();
	HX_STACK_LINE(97)
	this->_input->set_type(::flash::text::TextFieldType_obj::INPUT);
	HX_STACK_LINE(98)
	this->_input->set_embedFonts(true);
	HX_STACK_LINE(99)
	this->_input->set_defaultTextFormat(::flash::text::TextFormat_obj::__new(::flixel::system::FlxAssets_obj::FONT_DEBUGGER,(int)13,(int)16777215,false,false,false,null(),null(),null(),null(),null(),null(),null()));
	HX_STACK_LINE(100)
	this->_input->set_text(HX_CSTRING("(Click here / press [Tab] to enter command. Type 'help' for help.)"));
	HX_STACK_LINE(101)
	this->_input->set_width((this->_width - (int)4));
	HX_STACK_LINE(102)
	this->_input->set_height((this->_height - (int)15));
	HX_STACK_LINE(103)
	this->_input->set_x((int)2);
	HX_STACK_LINE(104)
	this->_input->set_y((int)15);
	HX_STACK_LINE(105)
	this->addChild(this->_input);
	HX_STACK_LINE(107)
	this->_input->addEventListener(::flash::events::FocusEvent_obj::FOCUS_IN,this->onFocus_dyn(),null(),null(),null());
	HX_STACK_LINE(108)
	this->_input->addEventListener(::flash::events::FocusEvent_obj::FOCUS_OUT,this->onFocusLost_dyn(),null(),null(),null());
	HX_STACK_LINE(109)
	this->_input->addEventListener(::flash::events::KeyboardEvent_obj::KEY_DOWN,this->onKeyPress_dyn(),null(),null(),null());
	HX_STACK_LINE(113)
	::flixel::system::debug::ConsoleCommands_obj::__new(hx::ObjectPtr<OBJ_>(this));
}
;
	return null();
}

//Console_obj::~Console_obj() { }

Dynamic Console_obj::__CreateEmpty() { return  new Console_obj; }
hx::ObjectPtr< Console_obj > Console_obj::__new()
{  hx::ObjectPtr< Console_obj > result = new Console_obj();
	result->__construct();
	return result;}

Dynamic Console_obj::__Create(hx::DynamicArray inArgs)
{  hx::ObjectPtr< Console_obj > result = new Console_obj();
	result->__construct();
	return result;}

Void Console_obj::onFocus( ::flash::events::FocusEvent e){
{
		HX_STACK_FRAME("flixel.system.debug.Console","onFocus",0x4417127a,"flixel.system.debug.Console.onFocus","flixel/system/debug/Console.hx",118,0x3559cbd0)
		HX_STACK_THIS(this)
		HX_STACK_ARG(e,"e")
		HX_STACK_LINE(130)
		::flixel::FlxG_obj::keys->enabled = false;
		HX_STACK_LINE(133)
		if (((this->_input->get_text() == HX_CSTRING("(Click here / press [Tab] to enter command. Type 'help' for help.)")))){
			HX_STACK_LINE(135)
			this->_input->set_text(HX_CSTRING(""));
		}
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC1(Console_obj,onFocus,(void))

Void Console_obj::onFocusLost( ::flash::events::FocusEvent e){
{
		HX_STACK_FRAME("flixel.system.debug.Console","onFocusLost",0x437bad7e,"flixel.system.debug.Console.onFocusLost","flixel/system/debug/Console.hx",141,0x3559cbd0)
		HX_STACK_THIS(this)
		HX_STACK_ARG(e,"e")
		HX_STACK_LINE(152)
		::flixel::FlxG_obj::keys->enabled = true;
		HX_STACK_LINE(155)
		if (((this->_input->get_text() == HX_CSTRING("")))){
			HX_STACK_LINE(157)
			this->_input->set_text(HX_CSTRING("(Click here / press [Tab] to enter command. Type 'help' for help.)"));
		}
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC1(Console_obj,onFocusLost,(void))

Void Console_obj::onKeyPress( ::flash::events::KeyboardEvent e){
{
		HX_STACK_FRAME("flixel.system.debug.Console","onKeyPress",0x56941802,"flixel.system.debug.Console.onKeyPress","flixel/system/debug/Console.hx",163,0x3559cbd0)
		HX_STACK_THIS(this)
		HX_STACK_ARG(e,"e")
		HX_STACK_LINE(165)
		if (((  (((e->keyCode == ::flash::ui::Keyboard_obj::SPACE))) ? bool((this->_input->get_text() == HX_CSTRING(" "))) : bool(false) ))){
			HX_STACK_LINE(166)
			this->_input->set_text(HX_CSTRING(""));
		}
		HX_STACK_LINE(170)
		if (((  (((e->keyCode == ::flash::ui::Keyboard_obj::ENTER))) ? bool((this->_input->get_text() != HX_CSTRING(""))) : bool(false) ))){
			HX_STACK_LINE(171)
			this->processCommand();
		}
		else{
			HX_STACK_LINE(175)
			if (((e->keyCode == ::flash::ui::Keyboard_obj::ESCAPE))){
				HX_STACK_LINE(176)
				::flash::Lib_obj::get_current()->get_stage()->set_focus(null());
			}
			else{
				HX_STACK_LINE(180)
				if (((e->keyCode == ::flash::ui::Keyboard_obj::DELETE))){
					HX_STACK_LINE(181)
					this->_input->set_text(HX_CSTRING(""));
				}
				else{
					HX_STACK_LINE(185)
					if (((e->keyCode == ::flash::ui::Keyboard_obj::UP))){
						HX_STACK_LINE(187)
						if (((this->cmdHistory->length == (int)0))){
							HX_STACK_LINE(188)
							return null();
						}
						struct _Function_5_1{
							inline static ::String Block( ::flixel::system::debug::Console_obj *__this){
								HX_STACK_FRAME("*","closure",0x5bdab937,"*.closure","flixel/system/debug/Console.hx",191,0x3559cbd0)
								{
									HX_STACK_LINE(191)
									if (((__this->_historyIndex > (int)0))){
										HX_STACK_LINE(191)
										(__this->_historyIndex)--;
									}
									HX_STACK_LINE(191)
									return __this->cmdHistory->__get(__this->_historyIndex);
								}
								return null();
							}
						};
						HX_STACK_LINE(191)
						this->_input->set_text(_Function_5_1::Block(this));
						HX_STACK_LINE(194)
						this->addEventListener(::flash::events::Event_obj::RENDER,this->overrideDefaultSelection_dyn(),null(),null(),null());
						HX_STACK_LINE(195)
						::flash::Lib_obj::get_current()->get_stage()->invalidate();
					}
					else{
						HX_STACK_LINE(198)
						if (((e->keyCode == ::flash::ui::Keyboard_obj::DOWN))){
							HX_STACK_LINE(200)
							if (((this->cmdHistory->length == (int)0))){
								HX_STACK_LINE(201)
								return null();
							}
							struct _Function_6_1{
								inline static ::String Block( ::flixel::system::debug::Console_obj *__this){
									HX_STACK_FRAME("*","closure",0x5bdab937,"*.closure","flixel/system/debug/Console.hx",204,0x3559cbd0)
									{
										HX_STACK_LINE(204)
										if (((__this->_historyIndex < __this->cmdHistory->length))){
											HX_STACK_LINE(204)
											(__this->_historyIndex)++;
										}
										HX_STACK_LINE(204)
										return (  (((__this->cmdHistory->__get(__this->_historyIndex) != null()))) ? ::String(__this->cmdHistory->__get(__this->_historyIndex)) : ::String(HX_CSTRING("")) );
									}
									return null();
								}
							};
							HX_STACK_LINE(204)
							this->_input->set_text(_Function_6_1::Block(this));
						}
					}
				}
			}
		}
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC1(Console_obj,onKeyPress,(void))

Void Console_obj::processCommand( ){
{
		HX_STACK_FRAME("flixel.system.debug.Console","processCommand",0xcb35187b,"flixel.system.debug.Console.processCommand","flixel/system/debug/Console.hx",209,0x3559cbd0)
		HX_STACK_THIS(this)
		HX_STACK_LINE(210)
		Dynamic args = ::StringTools_obj::rtrim(this->_input->get_text()).split(HX_CSTRING(" "));		HX_STACK_VAR(args,"args");
		HX_STACK_LINE(211)
		::String alias = args->__Field(HX_CSTRING("shift"),true)();		HX_STACK_VAR(alias,"alias");
		HX_STACK_LINE(212)
		Dynamic command = ::flixel::system::debug::ConsoleUtil_obj::findCommand(alias,this->commands);		HX_STACK_VAR(command,"command");
		HX_STACK_LINE(215)
		if (((command != null()))){
			HX_STACK_LINE(217)
			Dynamic func = command->__Field(HX_CSTRING("processFunction"),true);		HX_STACK_VAR(func,"func");
			HX_STACK_LINE(231)
			::String _g;		HX_STACK_VAR(_g,"_g");
			HX_STACK_LINE(231)
			{
				HX_STACK_LINE(231)
				if (((this->_historyIndex > (int)0))){
					HX_STACK_LINE(231)
					(this->_historyIndex)--;
				}
				HX_STACK_LINE(231)
				_g = this->cmdHistory->__get(this->_historyIndex);
			}
			HX_STACK_LINE(231)
			if (((_g != this->_input->get_text()))){
				HX_STACK_LINE(234)
				this->cmdHistory->push(this->_input->get_text());
				HX_STACK_LINE(235)
				::flixel::FlxG_obj::save->flush(null(),null());
				HX_STACK_LINE(238)
				if (((this->cmdHistory->length > (int)25))){
					HX_STACK_LINE(239)
					this->cmdHistory->shift();
				}
			}
			HX_STACK_LINE(243)
			this->_historyIndex = this->cmdHistory->length;
			HX_STACK_LINE(245)
			if ((::Reflect_obj::isFunction(func))){
				HX_STACK_LINE(248)
				if (((command->__Field(HX_CSTRING("paramCutoff"),true) > (int)0))){
					HX_STACK_LINE(250)
					int start = (command->__Field(HX_CSTRING("paramCutoff"),true) - (int)1);		HX_STACK_VAR(start,"start");
					HX_STACK_LINE(251)
					hx::IndexRef((args).mPtr,start) = args->__Field(HX_CSTRING("slice"),true)(start,args->__Field(HX_CSTRING("length"),true));
					HX_STACK_LINE(252)
					args = args->__Field(HX_CSTRING("slice"),true)((int)0,command->__Field(HX_CSTRING("paramCutoff"),true));
				}
				HX_STACK_LINE(255)
				::flixel::system::debug::ConsoleUtil_obj::callFunction(func,args);
			}
			HX_STACK_LINE(266)
			this->_input->set_text(HX_CSTRING(""));
		}
		else{
			HX_STACK_LINE(271)
			::flixel::FlxG_obj::log->advanced(((HX_CSTRING("Console: Invalid command: '") + alias) + HX_CSTRING("'")),::flixel::system::debug::LogStyle_obj::ERROR,true);
		}
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC0(Console_obj,processCommand,(void))

Void Console_obj::overrideDefaultSelection( ::flash::events::Event e){
{
		HX_STACK_FRAME("flixel.system.debug.Console","overrideDefaultSelection",0x1d35c856,"flixel.system.debug.Console.overrideDefaultSelection","flixel/system/debug/Console.hx",276,0x3559cbd0)
		HX_STACK_THIS(this)
		HX_STACK_ARG(e,"e")
		HX_STACK_LINE(277)
		::String _g = this->_input->get_text();		HX_STACK_VAR(_g,"_g");
		HX_STACK_LINE(277)
		this->_input->setSelection(_g.length,this->_input->get_text().length);
		HX_STACK_LINE(278)
		this->removeEventListener(::flash::events::Event_obj::RENDER,this->overrideDefaultSelection_dyn(),null());
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC1(Console_obj,overrideDefaultSelection,(void))

::String Console_obj::getPreviousCommand( ){
	HX_STACK_FRAME("flixel.system.debug.Console","getPreviousCommand",0xe854c33d,"flixel.system.debug.Console.getPreviousCommand","flixel/system/debug/Console.hx",282,0x3559cbd0)
	HX_STACK_THIS(this)
	HX_STACK_LINE(283)
	if (((this->_historyIndex > (int)0))){
		HX_STACK_LINE(284)
		(this->_historyIndex)--;
	}
	HX_STACK_LINE(287)
	return this->cmdHistory->__get(this->_historyIndex);
}


HX_DEFINE_DYNAMIC_FUNC0(Console_obj,getPreviousCommand,return )

::String Console_obj::getNextCommand( ){
	HX_STACK_FRAME("flixel.system.debug.Console","getNextCommand",0x76bea181,"flixel.system.debug.Console.getNextCommand","flixel/system/debug/Console.hx",291,0x3559cbd0)
	HX_STACK_THIS(this)
	HX_STACK_LINE(292)
	if (((this->_historyIndex < this->cmdHistory->length))){
		HX_STACK_LINE(293)
		(this->_historyIndex)++;
	}
	HX_STACK_LINE(296)
	if (((this->cmdHistory->__get(this->_historyIndex) != null()))){
		HX_STACK_LINE(297)
		return this->cmdHistory->__get(this->_historyIndex);
	}
	else{
		HX_STACK_LINE(300)
		return HX_CSTRING("");
	}
	HX_STACK_LINE(296)
	return null();
}


HX_DEFINE_DYNAMIC_FUNC0(Console_obj,getNextCommand,return )

Void Console_obj::registerObject( ::String ObjectAlias,Dynamic AnyObject){
{
		HX_STACK_FRAME("flixel.system.debug.Console","registerObject",0x72ea6b61,"flixel.system.debug.Console.registerObject","flixel/system/debug/Console.hx",312,0x3559cbd0)
		HX_STACK_THIS(this)
		HX_STACK_ARG(ObjectAlias,"ObjectAlias")
		HX_STACK_ARG(AnyObject,"AnyObject")
		HX_STACK_LINE(312)
		Dynamic value = AnyObject;		HX_STACK_VAR(value,"value");
		HX_STACK_LINE(312)
		this->registeredObjects->set(ObjectAlias,value);
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC2(Console_obj,registerObject,(void))

Void Console_obj::registerFunction( ::String FunctionAlias,Dynamic Function){
{
		HX_STACK_FRAME("flixel.system.debug.Console","registerFunction",0x640b843a,"flixel.system.debug.Console.registerFunction","flixel/system/debug/Console.hx",323,0x3559cbd0)
		HX_STACK_THIS(this)
		HX_STACK_ARG(FunctionAlias,"FunctionAlias")
		HX_STACK_ARG(Function,"Function")
		HX_STACK_LINE(323)
		Dynamic value = Function;		HX_STACK_VAR(value,"value");
		HX_STACK_LINE(323)
		this->registeredFunctions->set(FunctionAlias,value);
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC2(Console_obj,registerFunction,(void))

Void Console_obj::addCommand( Array< ::String > Aliases,Dynamic ProcessFunction,::String Help,::String ParamHelp,hx::Null< int >  __o_NumParams,hx::Null< int >  __o_ParamCutoff){
int NumParams = __o_NumParams.Default(0);
int ParamCutoff = __o_ParamCutoff.Default(-1);
	HX_STACK_FRAME("flixel.system.debug.Console","addCommand",0x54e2e789,"flixel.system.debug.Console.addCommand","flixel/system/debug/Console.hx",338,0x3559cbd0)
	HX_STACK_THIS(this)
	HX_STACK_ARG(Aliases,"Aliases")
	HX_STACK_ARG(ProcessFunction,"ProcessFunction")
	HX_STACK_ARG(Help,"Help")
	HX_STACK_ARG(ParamHelp,"ParamHelp")
	HX_STACK_ARG(NumParams,"NumParams")
	HX_STACK_ARG(ParamCutoff,"ParamCutoff")
{
		struct _Function_1_1{
			inline static Dynamic Block( ::String &ParamHelp,Array< ::String > &Aliases,int &NumParams,int &ParamCutoff,::String &Help,Dynamic &ProcessFunction){
				HX_STACK_FRAME("*","closure",0x5bdab937,"*.closure","flixel/system/debug/Console.hx",338,0x3559cbd0)
				{
					hx::Anon __result = hx::Anon_obj::Create();
					__result->Add(HX_CSTRING("aliases") , Aliases,false);
					__result->Add(HX_CSTRING("processFunction") , ProcessFunction,false);
					__result->Add(HX_CSTRING("help") , Help,false);
					__result->Add(HX_CSTRING("paramHelp") , ParamHelp,false);
					__result->Add(HX_CSTRING("numParams") , NumParams,false);
					__result->Add(HX_CSTRING("paramCutoff") , ParamCutoff,false);
					return __result;
				}
				return null();
			}
		};
		HX_STACK_LINE(338)
		this->commands->__Field(HX_CSTRING("push"),true)(_Function_1_1::Block(ParamHelp,Aliases,NumParams,ParamCutoff,Help,ProcessFunction));
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC6(Console_obj,addCommand,(void))

Void Console_obj::destroy( ){
{
		HX_STACK_FRAME("flixel.system.debug.Console","destroy",0xcdd6413b,"flixel.system.debug.Console.destroy","flixel/system/debug/Console.hx",346,0x3559cbd0)
		HX_STACK_THIS(this)
		HX_STACK_LINE(347)
		this->super::destroy();
		HX_STACK_LINE(349)
		this->_input->removeEventListener(::flash::events::FocusEvent_obj::FOCUS_IN,this->onFocus_dyn(),null());
		HX_STACK_LINE(350)
		this->_input->removeEventListener(::flash::events::FocusEvent_obj::FOCUS_OUT,this->onFocusLost_dyn(),null());
		HX_STACK_LINE(351)
		this->_input->removeEventListener(::flash::events::KeyboardEvent_obj::KEY_DOWN,this->onKeyPress_dyn(),null());
		HX_STACK_LINE(353)
		if (((this->_input != null()))){
			HX_STACK_LINE(355)
			this->removeChild(this->_input);
			HX_STACK_LINE(356)
			this->_input = null();
		}
		HX_STACK_LINE(359)
		this->commands = null();
		HX_STACK_LINE(361)
		this->registeredObjects = null();
		HX_STACK_LINE(362)
		this->registeredFunctions = null();
		HX_STACK_LINE(364)
		this->objectStack = null();
	}
return null();
}


Void Console_obj::updateSize( ){
{
		HX_STACK_FRAME("flixel.system.debug.Console","updateSize",0x70f3d5c9,"flixel.system.debug.Console.updateSize","flixel/system/debug/Console.hx",371,0x3559cbd0)
		HX_STACK_THIS(this)
		HX_STACK_LINE(372)
		this->super::updateSize();
		HX_STACK_LINE(374)
		this->_input->set_width((this->_width - (int)4));
		HX_STACK_LINE(375)
		this->_input->set_height((this->_height - (int)15));
	}
return null();
}


::String Console_obj::_DEFAULT_TEXT;

int Console_obj::_HISTORY_MAX;


Console_obj::Console_obj()
{
}

void Console_obj::__Mark(HX_MARK_PARAMS)
{
	HX_MARK_BEGIN_CLASS(Console);
	HX_MARK_MEMBER_NAME(registeredObjects,"registeredObjects");
	HX_MARK_MEMBER_NAME(registeredFunctions,"registeredFunctions");
	HX_MARK_MEMBER_NAME(objectStack,"objectStack");
	HX_MARK_MEMBER_NAME(cmdHistory,"cmdHistory");
	HX_MARK_MEMBER_NAME(commands,"commands");
	HX_MARK_MEMBER_NAME(_historyIndex,"_historyIndex");
	HX_MARK_MEMBER_NAME(_input,"_input");
	::flixel::system::debug::Window_obj::__Mark(HX_MARK_ARG);
	HX_MARK_END_CLASS();
}

void Console_obj::__Visit(HX_VISIT_PARAMS)
{
	HX_VISIT_MEMBER_NAME(registeredObjects,"registeredObjects");
	HX_VISIT_MEMBER_NAME(registeredFunctions,"registeredFunctions");
	HX_VISIT_MEMBER_NAME(objectStack,"objectStack");
	HX_VISIT_MEMBER_NAME(cmdHistory,"cmdHistory");
	HX_VISIT_MEMBER_NAME(commands,"commands");
	HX_VISIT_MEMBER_NAME(_historyIndex,"_historyIndex");
	HX_VISIT_MEMBER_NAME(_input,"_input");
	::flixel::system::debug::Window_obj::__Visit(HX_VISIT_ARG);
}

Dynamic Console_obj::__Field(const ::String &inName,bool inCallProp)
{
	switch(inName.length) {
	case 6:
		if (HX_FIELD_EQ(inName,"_input") ) { return _input; }
		break;
	case 7:
		if (HX_FIELD_EQ(inName,"onFocus") ) { return onFocus_dyn(); }
		if (HX_FIELD_EQ(inName,"destroy") ) { return destroy_dyn(); }
		break;
	case 8:
		if (HX_FIELD_EQ(inName,"commands") ) { return commands; }
		break;
	case 10:
		if (HX_FIELD_EQ(inName,"cmdHistory") ) { return cmdHistory; }
		if (HX_FIELD_EQ(inName,"onKeyPress") ) { return onKeyPress_dyn(); }
		if (HX_FIELD_EQ(inName,"addCommand") ) { return addCommand_dyn(); }
		if (HX_FIELD_EQ(inName,"updateSize") ) { return updateSize_dyn(); }
		break;
	case 11:
		if (HX_FIELD_EQ(inName,"objectStack") ) { return objectStack; }
		if (HX_FIELD_EQ(inName,"onFocusLost") ) { return onFocusLost_dyn(); }
		break;
	case 13:
		if (HX_FIELD_EQ(inName,"_historyIndex") ) { return _historyIndex; }
		break;
	case 14:
		if (HX_FIELD_EQ(inName,"processCommand") ) { return processCommand_dyn(); }
		if (HX_FIELD_EQ(inName,"getNextCommand") ) { return getNextCommand_dyn(); }
		if (HX_FIELD_EQ(inName,"registerObject") ) { return registerObject_dyn(); }
		break;
	case 16:
		if (HX_FIELD_EQ(inName,"registerFunction") ) { return registerFunction_dyn(); }
		break;
	case 17:
		if (HX_FIELD_EQ(inName,"registeredObjects") ) { return registeredObjects; }
		break;
	case 18:
		if (HX_FIELD_EQ(inName,"getPreviousCommand") ) { return getPreviousCommand_dyn(); }
		break;
	case 19:
		if (HX_FIELD_EQ(inName,"registeredFunctions") ) { return registeredFunctions; }
		break;
	case 24:
		if (HX_FIELD_EQ(inName,"overrideDefaultSelection") ) { return overrideDefaultSelection_dyn(); }
	}
	return super::__Field(inName,inCallProp);
}

Dynamic Console_obj::__SetField(const ::String &inName,const Dynamic &inValue,bool inCallProp)
{
	switch(inName.length) {
	case 6:
		if (HX_FIELD_EQ(inName,"_input") ) { _input=inValue.Cast< ::flash::text::TextField >(); return inValue; }
		break;
	case 8:
		if (HX_FIELD_EQ(inName,"commands") ) { commands=inValue.Cast< Dynamic >(); return inValue; }
		break;
	case 10:
		if (HX_FIELD_EQ(inName,"cmdHistory") ) { cmdHistory=inValue.Cast< Array< ::String > >(); return inValue; }
		break;
	case 11:
		if (HX_FIELD_EQ(inName,"objectStack") ) { objectStack=inValue.Cast< Array< ::Dynamic > >(); return inValue; }
		break;
	case 13:
		if (HX_FIELD_EQ(inName,"_historyIndex") ) { _historyIndex=inValue.Cast< int >(); return inValue; }
		break;
	case 17:
		if (HX_FIELD_EQ(inName,"registeredObjects") ) { registeredObjects=inValue.Cast< ::haxe::ds::StringMap >(); return inValue; }
		break;
	case 19:
		if (HX_FIELD_EQ(inName,"registeredFunctions") ) { registeredFunctions=inValue.Cast< ::haxe::ds::StringMap >(); return inValue; }
	}
	return super::__SetField(inName,inValue,inCallProp);
}

void Console_obj::__GetFields(Array< ::String> &outFields)
{
	outFields->push(HX_CSTRING("registeredObjects"));
	outFields->push(HX_CSTRING("registeredFunctions"));
	outFields->push(HX_CSTRING("objectStack"));
	outFields->push(HX_CSTRING("cmdHistory"));
	outFields->push(HX_CSTRING("commands"));
	outFields->push(HX_CSTRING("_historyIndex"));
	outFields->push(HX_CSTRING("_input"));
	super::__GetFields(outFields);
};

static ::String sStaticFields[] = {
	HX_CSTRING("_DEFAULT_TEXT"),
	HX_CSTRING("_HISTORY_MAX"),
	String(null()) };

#if HXCPP_SCRIPTABLE
static hx::StorageInfo sMemberStorageInfo[] = {
	{hx::fsObject /*::haxe::ds::StringMap*/ ,(int)offsetof(Console_obj,registeredObjects),HX_CSTRING("registeredObjects")},
	{hx::fsObject /*::haxe::ds::StringMap*/ ,(int)offsetof(Console_obj,registeredFunctions),HX_CSTRING("registeredFunctions")},
	{hx::fsObject /*Array< ::Dynamic >*/ ,(int)offsetof(Console_obj,objectStack),HX_CSTRING("objectStack")},
	{hx::fsObject /*Array< ::String >*/ ,(int)offsetof(Console_obj,cmdHistory),HX_CSTRING("cmdHistory")},
	{hx::fsObject /*Dynamic*/ ,(int)offsetof(Console_obj,commands),HX_CSTRING("commands")},
	{hx::fsInt,(int)offsetof(Console_obj,_historyIndex),HX_CSTRING("_historyIndex")},
	{hx::fsObject /*::flash::text::TextField*/ ,(int)offsetof(Console_obj,_input),HX_CSTRING("_input")},
	{ hx::fsUnknown, 0, null()}
};
#endif

static ::String sMemberFields[] = {
	HX_CSTRING("registeredObjects"),
	HX_CSTRING("registeredFunctions"),
	HX_CSTRING("objectStack"),
	HX_CSTRING("cmdHistory"),
	HX_CSTRING("commands"),
	HX_CSTRING("_historyIndex"),
	HX_CSTRING("_input"),
	HX_CSTRING("onFocus"),
	HX_CSTRING("onFocusLost"),
	HX_CSTRING("onKeyPress"),
	HX_CSTRING("processCommand"),
	HX_CSTRING("overrideDefaultSelection"),
	HX_CSTRING("getPreviousCommand"),
	HX_CSTRING("getNextCommand"),
	HX_CSTRING("registerObject"),
	HX_CSTRING("registerFunction"),
	HX_CSTRING("addCommand"),
	HX_CSTRING("destroy"),
	HX_CSTRING("updateSize"),
	String(null()) };

static void sMarkStatics(HX_MARK_PARAMS) {
	HX_MARK_MEMBER_NAME(Console_obj::__mClass,"__mClass");
	HX_MARK_MEMBER_NAME(Console_obj::_DEFAULT_TEXT,"_DEFAULT_TEXT");
	HX_MARK_MEMBER_NAME(Console_obj::_HISTORY_MAX,"_HISTORY_MAX");
};

#ifdef HXCPP_VISIT_ALLOCS
static void sVisitStatics(HX_VISIT_PARAMS) {
	HX_VISIT_MEMBER_NAME(Console_obj::__mClass,"__mClass");
	HX_VISIT_MEMBER_NAME(Console_obj::_DEFAULT_TEXT,"_DEFAULT_TEXT");
	HX_VISIT_MEMBER_NAME(Console_obj::_HISTORY_MAX,"_HISTORY_MAX");
};

#endif

Class Console_obj::__mClass;

void Console_obj::__register()
{
	hx::Static(__mClass) = hx::RegisterClass(HX_CSTRING("flixel.system.debug.Console"), hx::TCanCast< Console_obj> ,sStaticFields,sMemberFields,
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

void Console_obj::__boot()
{
	_DEFAULT_TEXT= HX_CSTRING("(Click here / press [Tab] to enter command. Type 'help' for help.)");
	_HISTORY_MAX= (int)25;
}

} // end namespace flixel
} // end namespace system
} // end namespace debug
