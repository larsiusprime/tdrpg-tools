#include <hxcpp.h>

#ifndef INCLUDED_IMap
#include <IMap.h>
#endif
#ifndef INCLUDED_flash_Lib
#include <flash/Lib.h>
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
#ifndef INCLUDED_flash_events_IEventDispatcher
#include <flash/events/IEventDispatcher.h>
#endif
#ifndef INCLUDED_flash_events_KeyboardEvent
#include <flash/events/KeyboardEvent.h>
#endif
#ifndef INCLUDED_flixel_FlxG
#include <flixel/FlxG.h>
#endif
#ifndef INCLUDED_flixel_FlxGame
#include <flixel/FlxGame.h>
#endif
#ifndef INCLUDED_flixel_input_keyboard_FlxKey
#include <flixel/input/keyboard/FlxKey.h>
#endif
#ifndef INCLUDED_flixel_input_keyboard_FlxKeyList
#include <flixel/input/keyboard/FlxKeyList.h>
#endif
#ifndef INCLUDED_flixel_input_keyboard_FlxKeyboard
#include <flixel/input/keyboard/FlxKeyboard.h>
#endif
#ifndef INCLUDED_flixel_interfaces_IFlxInput
#include <flixel/interfaces/IFlxInput.h>
#endif
#ifndef INCLUDED_flixel_system_debug_FlxDebugger
#include <flixel/system/debug/FlxDebugger.h>
#endif
#ifndef INCLUDED_flixel_system_debug_LogStyle
#include <flixel/system/debug/LogStyle.h>
#endif
#ifndef INCLUDED_flixel_system_frontEnds_DebuggerFrontEnd
#include <flixel/system/frontEnds/DebuggerFrontEnd.h>
#endif
#ifndef INCLUDED_flixel_system_frontEnds_LogFrontEnd
#include <flixel/system/frontEnds/LogFrontEnd.h>
#endif
#ifndef INCLUDED_flixel_system_frontEnds_SoundFrontEnd
#include <flixel/system/frontEnds/SoundFrontEnd.h>
#endif
#ifndef INCLUDED_flixel_system_replay_CodeValuePair
#include <flixel/system/replay/CodeValuePair.h>
#endif
#ifndef INCLUDED_flixel_system_ui_FlxSoundTray
#include <flixel/system/ui/FlxSoundTray.h>
#endif
#ifndef INCLUDED_flixel_util_FlxArrayUtil
#include <flixel/util/FlxArrayUtil.h>
#endif
#ifndef INCLUDED_haxe_ds_StringMap
#include <haxe/ds/StringMap.h>
#endif
namespace flixel{
namespace input{
namespace keyboard{

Void FlxKeyboard_obj::__construct()
{
HX_STACK_FRAME("flixel.input.keyboard.FlxKeyboard","new",0xa12d657a,"flixel.input.keyboard.FlxKeyboard.new","flixel/input/keyboard/FlxKeyboard.hx",17,0x41882875)
{
	HX_STACK_LINE(22)
	this->enabled = true;
	HX_STACK_LINE(180)
	this->_keyLookup = ::haxe::ds::StringMap_obj::__new();
	HX_STACK_LINE(182)
	this->_keyList = Array_obj< ::Dynamic >::__new();
	HX_STACK_LINE(183)
	::flixel::util::FlxArrayUtil_obj::setLength_flixel_input_keyboard_FlxKey(this->_keyList,(int)256);
	HX_STACK_LINE(185)
	int i;		HX_STACK_VAR(i,"i");
	HX_STACK_LINE(188)
	i = (int)65;
	HX_STACK_LINE(190)
	while(((i <= (int)90))){
		HX_STACK_LINE(192)
		this->addKey(::String::fromCharCode(i),i);
		HX_STACK_LINE(193)
		(i)++;
	}
	HX_STACK_LINE(197)
	i = (int)48;
	HX_STACK_LINE(198)
	this->addKey(HX_CSTRING("ZERO"),(i)++);
	HX_STACK_LINE(199)
	this->addKey(HX_CSTRING("ONE"),(i)++);
	HX_STACK_LINE(200)
	this->addKey(HX_CSTRING("TWO"),(i)++);
	HX_STACK_LINE(201)
	this->addKey(HX_CSTRING("THREE"),(i)++);
	HX_STACK_LINE(202)
	this->addKey(HX_CSTRING("FOUR"),(i)++);
	HX_STACK_LINE(203)
	this->addKey(HX_CSTRING("FIVE"),(i)++);
	HX_STACK_LINE(204)
	this->addKey(HX_CSTRING("SIX"),(i)++);
	HX_STACK_LINE(205)
	this->addKey(HX_CSTRING("SEVEN"),(i)++);
	HX_STACK_LINE(206)
	this->addKey(HX_CSTRING("EIGHT"),(i)++);
	HX_STACK_LINE(207)
	this->addKey(HX_CSTRING("NINE"),(i)++);
	HX_STACK_LINE(208)
	i = (int)96;
	HX_STACK_LINE(209)
	this->addKey(HX_CSTRING("NUMPADZERO"),(i)++);
	HX_STACK_LINE(210)
	this->addKey(HX_CSTRING("NUMPADONE"),(i)++);
	HX_STACK_LINE(211)
	this->addKey(HX_CSTRING("NUMPADTWO"),(i)++);
	HX_STACK_LINE(212)
	this->addKey(HX_CSTRING("NUMPADTHREE"),(i)++);
	HX_STACK_LINE(213)
	this->addKey(HX_CSTRING("NUMPADFOUR"),(i)++);
	HX_STACK_LINE(214)
	this->addKey(HX_CSTRING("NUMPADFIVE"),(i)++);
	HX_STACK_LINE(215)
	this->addKey(HX_CSTRING("NUMPADSIX"),(i)++);
	HX_STACK_LINE(216)
	this->addKey(HX_CSTRING("NUMPADSEVEN"),(i)++);
	HX_STACK_LINE(217)
	this->addKey(HX_CSTRING("NUMPADEIGHT"),(i)++);
	HX_STACK_LINE(218)
	this->addKey(HX_CSTRING("NUMPADNINE"),(i)++);
	HX_STACK_LINE(220)
	this->addKey(HX_CSTRING("PAGEUP"),(int)33);
	HX_STACK_LINE(221)
	this->addKey(HX_CSTRING("PAGEDOWN"),(int)34);
	HX_STACK_LINE(222)
	this->addKey(HX_CSTRING("HOME"),(int)36);
	HX_STACK_LINE(223)
	this->addKey(HX_CSTRING("END"),(int)35);
	HX_STACK_LINE(224)
	this->addKey(HX_CSTRING("INSERT"),(int)45);
	HX_STACK_LINE(236)
	this->addKey(HX_CSTRING("ESCAPE"),(int)27);
	HX_STACK_LINE(237)
	this->addKey(HX_CSTRING("MINUS"),(int)189);
	HX_STACK_LINE(238)
	this->addKey(HX_CSTRING("PLUS"),(int)187);
	HX_STACK_LINE(239)
	this->addKey(HX_CSTRING("DELETE"),(int)46);
	HX_STACK_LINE(240)
	this->addKey(HX_CSTRING("BACKSPACE"),(int)8);
	HX_STACK_LINE(241)
	this->addKey(HX_CSTRING("LBRACKET"),(int)219);
	HX_STACK_LINE(242)
	this->addKey(HX_CSTRING("RBRACKET"),(int)221);
	HX_STACK_LINE(243)
	this->addKey(HX_CSTRING("BACKSLASH"),(int)220);
	HX_STACK_LINE(244)
	this->addKey(HX_CSTRING("CAPSLOCK"),(int)20);
	HX_STACK_LINE(245)
	this->addKey(HX_CSTRING("SEMICOLON"),(int)186);
	HX_STACK_LINE(246)
	this->addKey(HX_CSTRING("QUOTE"),(int)222);
	HX_STACK_LINE(247)
	this->addKey(HX_CSTRING("ENTER"),(int)13);
	HX_STACK_LINE(248)
	this->addKey(HX_CSTRING("SHIFT"),(int)16);
	HX_STACK_LINE(249)
	this->addKey(HX_CSTRING("COMMA"),(int)188);
	HX_STACK_LINE(250)
	this->addKey(HX_CSTRING("PERIOD"),(int)190);
	HX_STACK_LINE(251)
	this->addKey(HX_CSTRING("SLASH"),(int)191);
	HX_STACK_LINE(252)
	this->addKey(HX_CSTRING("NUMPADSLASH"),(int)191);
	HX_STACK_LINE(253)
	this->addKey(HX_CSTRING("GRAVEACCENT"),(int)192);
	HX_STACK_LINE(254)
	this->addKey(HX_CSTRING("CONTROL"),(int)17);
	HX_STACK_LINE(255)
	this->addKey(HX_CSTRING("ALT"),(int)18);
	HX_STACK_LINE(256)
	this->addKey(HX_CSTRING("SPACE"),(int)32);
	HX_STACK_LINE(257)
	this->addKey(HX_CSTRING("UP"),(int)38);
	HX_STACK_LINE(258)
	this->addKey(HX_CSTRING("DOWN"),(int)40);
	HX_STACK_LINE(259)
	this->addKey(HX_CSTRING("LEFT"),(int)37);
	HX_STACK_LINE(260)
	this->addKey(HX_CSTRING("RIGHT"),(int)39);
	HX_STACK_LINE(261)
	this->addKey(HX_CSTRING("TAB"),(int)9);
	HX_STACK_LINE(269)
	::flash::Lib_obj::get_current()->get_stage()->addEventListener(::flash::events::KeyboardEvent_obj::KEY_DOWN,this->onKeyDown_dyn(),null(),null(),null());
	HX_STACK_LINE(270)
	::flash::Lib_obj::get_current()->get_stage()->addEventListener(::flash::events::KeyboardEvent_obj::KEY_UP,this->onKeyUp_dyn(),null(),null(),null());
	HX_STACK_LINE(272)
	this->pressed = ::flixel::input::keyboard::FlxKeyList_obj::__new((int)1);
	HX_STACK_LINE(273)
	this->justPressed = ::flixel::input::keyboard::FlxKeyList_obj::__new((int)2);
	HX_STACK_LINE(274)
	this->justReleased = ::flixel::input::keyboard::FlxKeyList_obj::__new((int)-1);
}
;
	return null();
}

//FlxKeyboard_obj::~FlxKeyboard_obj() { }

Dynamic FlxKeyboard_obj::__CreateEmpty() { return  new FlxKeyboard_obj; }
hx::ObjectPtr< FlxKeyboard_obj > FlxKeyboard_obj::__new()
{  hx::ObjectPtr< FlxKeyboard_obj > result = new FlxKeyboard_obj();
	result->__construct();
	return result;}

Dynamic FlxKeyboard_obj::__Create(hx::DynamicArray inArgs)
{  hx::ObjectPtr< FlxKeyboard_obj > result = new FlxKeyboard_obj();
	result->__construct();
	return result;}

hx::Object *FlxKeyboard_obj::__ToInterface(const hx::type_info &inType) {
	if (inType==typeid( ::flixel::interfaces::IFlxInput_obj)) return operator ::flixel::interfaces::IFlxInput_obj *();
	return super::__ToInterface(inType);
}

bool FlxKeyboard_obj::anyPressed( Array< ::String > KeyArray){
	HX_STACK_FRAME("flixel.input.keyboard.FlxKeyboard","anyPressed",0xd7d5173c,"flixel.input.keyboard.FlxKeyboard.anyPressed","flixel/input/keyboard/FlxKeyboard.hx",61,0x41882875)
	HX_STACK_THIS(this)
	HX_STACK_ARG(KeyArray,"KeyArray")
	HX_STACK_LINE(61)
	return this->checkKeyStatus(KeyArray,(int)1);
}


HX_DEFINE_DYNAMIC_FUNC1(FlxKeyboard_obj,anyPressed,return )

bool FlxKeyboard_obj::anyJustPressed( Array< ::String > KeyArray){
	HX_STACK_FRAME("flixel.input.keyboard.FlxKeyboard","anyJustPressed",0x0abca770,"flixel.input.keyboard.FlxKeyboard.anyJustPressed","flixel/input/keyboard/FlxKeyboard.hx",73,0x41882875)
	HX_STACK_THIS(this)
	HX_STACK_ARG(KeyArray,"KeyArray")
	HX_STACK_LINE(73)
	return this->checkKeyStatus(KeyArray,(int)2);
}


HX_DEFINE_DYNAMIC_FUNC1(FlxKeyboard_obj,anyJustPressed,return )

bool FlxKeyboard_obj::anyJustReleased( Array< ::String > KeyArray){
	HX_STACK_FRAME("flixel.input.keyboard.FlxKeyboard","anyJustReleased",0x612be82f,"flixel.input.keyboard.FlxKeyboard.anyJustReleased","flixel/input/keyboard/FlxKeyboard.hx",85,0x41882875)
	HX_STACK_THIS(this)
	HX_STACK_ARG(KeyArray,"KeyArray")
	HX_STACK_LINE(85)
	return this->checkKeyStatus(KeyArray,(int)-1);
}


HX_DEFINE_DYNAMIC_FUNC1(FlxKeyboard_obj,anyJustReleased,return )

bool FlxKeyboard_obj::checkStatus( int KeyCode,int Status){
	HX_STACK_FRAME("flixel.input.keyboard.FlxKeyboard","checkStatus",0x7888f934,"flixel.input.keyboard.FlxKeyboard.checkStatus","flixel/input/keyboard/FlxKeyboard.hx",96,0x41882875)
	HX_STACK_THIS(this)
	HX_STACK_ARG(KeyCode,"KeyCode")
	HX_STACK_ARG(Status,"Status")
	HX_STACK_LINE(97)
	::flixel::input::keyboard::FlxKey k = this->_keyList->__get(KeyCode).StaticCast< ::flixel::input::keyboard::FlxKey >();		HX_STACK_VAR(k,"k");
	HX_STACK_LINE(98)
	if (((k != null()))){
		HX_STACK_LINE(100)
		if (((k->current == Status))){
			HX_STACK_LINE(102)
			return true;
		}
		else{
			HX_STACK_LINE(104)
			if (((bool((Status == (int)1)) && bool((k->current == (int)2))))){
				HX_STACK_LINE(106)
				return true;
			}
			else{
				HX_STACK_LINE(108)
				if (((bool((Status == (int)0)) && bool((k->current == (int)-1))))){
					HX_STACK_LINE(110)
					return true;
				}
			}
		}
	}
	else{
		HX_STACK_LINE(116)
		::flixel::FlxG_obj::log->advanced(((HX_CSTRING("Invalid Key: `") + KeyCode) + HX_CSTRING("`. Note that function and numpad keys can only be used in flash and js.")),::flixel::system::debug::LogStyle_obj::ERROR,true);
	}
	HX_STACK_LINE(120)
	return false;
}


HX_DEFINE_DYNAMIC_FUNC2(FlxKeyboard_obj,checkStatus,return )

int FlxKeyboard_obj::getKeyCode( ::String KeyName){
	HX_STACK_FRAME("flixel.input.keyboard.FlxKeyboard","getKeyCode",0x32d24a9c,"flixel.input.keyboard.FlxKeyboard.getKeyCode","flixel/input/keyboard/FlxKeyboard.hx",131,0x41882875)
	HX_STACK_THIS(this)
	HX_STACK_ARG(KeyName,"KeyName")
	HX_STACK_LINE(131)
	return this->_keyLookup->get(KeyName);
}


HX_DEFINE_DYNAMIC_FUNC1(FlxKeyboard_obj,getKeyCode,return )

Array< ::Dynamic > FlxKeyboard_obj::getIsDown( ){
	HX_STACK_FRAME("flixel.input.keyboard.FlxKeyboard","getIsDown",0x5d10ab3c,"flixel.input.keyboard.FlxKeyboard.getIsDown","flixel/input/keyboard/FlxKeyboard.hx",140,0x41882875)
	HX_STACK_THIS(this)
	HX_STACK_LINE(141)
	Array< ::Dynamic > keysDown = Array_obj< ::Dynamic >::__new();		HX_STACK_VAR(keysDown,"keysDown");
	HX_STACK_LINE(143)
	{
		HX_STACK_LINE(143)
		int _g = (int)0;		HX_STACK_VAR(_g,"_g");
		HX_STACK_LINE(143)
		Array< ::Dynamic > _g1 = this->_keyList;		HX_STACK_VAR(_g1,"_g1");
		HX_STACK_LINE(143)
		while(((_g < _g1->length))){
			HX_STACK_LINE(143)
			::flixel::input::keyboard::FlxKey key = _g1->__get(_g).StaticCast< ::flixel::input::keyboard::FlxKey >();		HX_STACK_VAR(key,"key");
			HX_STACK_LINE(143)
			++(_g);
			HX_STACK_LINE(145)
			if (((bool((key != null())) && bool((key->current > (int)0))))){
				HX_STACK_LINE(147)
				keysDown->push(key);
			}
		}
	}
	HX_STACK_LINE(150)
	return keysDown;
}


HX_DEFINE_DYNAMIC_FUNC0(FlxKeyboard_obj,getIsDown,return )

Void FlxKeyboard_obj::destroy( ){
{
		HX_STACK_FRAME("flixel.input.keyboard.FlxKeyboard","destroy",0x52b95714,"flixel.input.keyboard.FlxKeyboard.destroy","flixel/input/keyboard/FlxKeyboard.hx",157,0x41882875)
		HX_STACK_THIS(this)
		HX_STACK_LINE(158)
		this->_keyList = null();
		HX_STACK_LINE(159)
		this->_keyLookup = null();
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC0(FlxKeyboard_obj,destroy,(void))

Void FlxKeyboard_obj::reset( ){
{
		HX_STACK_FRAME("flixel.input.keyboard.FlxKeyboard","reset",0xa104d969,"flixel.input.keyboard.FlxKeyboard.reset","flixel/input/keyboard/FlxKeyboard.hx",167,0x41882875)
		HX_STACK_THIS(this)
		HX_STACK_LINE(167)
		int _g = (int)0;		HX_STACK_VAR(_g,"_g");
		HX_STACK_LINE(167)
		Array< ::Dynamic > _g1 = this->_keyList;		HX_STACK_VAR(_g1,"_g1");
		HX_STACK_LINE(167)
		while(((_g < _g1->length))){
			HX_STACK_LINE(167)
			::flixel::input::keyboard::FlxKey key = _g1->__get(_g).StaticCast< ::flixel::input::keyboard::FlxKey >();		HX_STACK_VAR(key,"key");
			HX_STACK_LINE(167)
			++(_g);
			HX_STACK_LINE(169)
			if (((key != null()))){
				HX_STACK_LINE(171)
				key->current = (int)0;
				HX_STACK_LINE(172)
				key->last = (int)0;
			}
		}
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC0(FlxKeyboard_obj,reset,(void))

Void FlxKeyboard_obj::addKey( ::String KeyName,int KeyCode){
{
		HX_STACK_FRAME("flixel.input.keyboard.FlxKeyboard","addKey",0xd9c3b124,"flixel.input.keyboard.FlxKeyboard.addKey","flixel/input/keyboard/FlxKeyboard.hx",284,0x41882875)
		HX_STACK_THIS(this)
		HX_STACK_ARG(KeyName,"KeyName")
		HX_STACK_ARG(KeyCode,"KeyCode")
		HX_STACK_LINE(285)
		this->_keyLookup->set(KeyName,KeyCode);
		HX_STACK_LINE(286)
		this->_keyList[KeyCode] = ::flixel::input::keyboard::FlxKey_obj::__new(KeyName);
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC2(FlxKeyboard_obj,addKey,(void))

Void FlxKeyboard_obj::update( ){
{
		HX_STACK_FRAME("flixel.input.keyboard.FlxKeyboard","update",0xc1c69d2f,"flixel.input.keyboard.FlxKeyboard.update","flixel/input/keyboard/FlxKeyboard.hx",294,0x41882875)
		HX_STACK_THIS(this)
		HX_STACK_LINE(294)
		int _g = (int)0;		HX_STACK_VAR(_g,"_g");
		HX_STACK_LINE(294)
		Array< ::Dynamic > _g1 = this->_keyList;		HX_STACK_VAR(_g1,"_g1");
		HX_STACK_LINE(294)
		while(((_g < _g1->length))){
			HX_STACK_LINE(294)
			::flixel::input::keyboard::FlxKey key = _g1->__get(_g).StaticCast< ::flixel::input::keyboard::FlxKey >();		HX_STACK_VAR(key,"key");
			HX_STACK_LINE(294)
			++(_g);
			HX_STACK_LINE(296)
			if (((key == null()))){
				HX_STACK_LINE(298)
				continue;
			}
			HX_STACK_LINE(301)
			if (((bool((key->last == (int)-1)) && bool((key->current == (int)-1))))){
				HX_STACK_LINE(303)
				key->current = (int)0;
			}
			else{
				HX_STACK_LINE(305)
				if (((bool((key->last == (int)2)) && bool((key->current == (int)2))))){
					HX_STACK_LINE(307)
					key->current = (int)1;
				}
			}
			HX_STACK_LINE(310)
			key->last = key->current;
		}
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC0(FlxKeyboard_obj,update,(void))

bool FlxKeyboard_obj::checkKeyStatus( Array< ::String > KeyArray,int Status){
	HX_STACK_FRAME("flixel.input.keyboard.FlxKeyboard","checkKeyStatus",0x68c0016f,"flixel.input.keyboard.FlxKeyboard.checkKeyStatus","flixel/input/keyboard/FlxKeyboard.hx",322,0x41882875)
	HX_STACK_THIS(this)
	HX_STACK_ARG(KeyArray,"KeyArray")
	HX_STACK_ARG(Status,"Status")
	HX_STACK_LINE(323)
	if (((KeyArray == null()))){
		HX_STACK_LINE(325)
		return false;
	}
	HX_STACK_LINE(328)
	{
		HX_STACK_LINE(328)
		int _g = (int)0;		HX_STACK_VAR(_g,"_g");
		HX_STACK_LINE(328)
		while(((_g < KeyArray->length))){
			HX_STACK_LINE(328)
			::String code = KeyArray->__get(_g);		HX_STACK_VAR(code,"code");
			HX_STACK_LINE(328)
			++(_g);
			HX_STACK_LINE(330)
			::flixel::input::keyboard::FlxKey key;		HX_STACK_VAR(key,"key");
			HX_STACK_LINE(333)
			code = code.toUpperCase();
			HX_STACK_LINE(334)
			key = this->_keyList->__get(this->_keyLookup->get(code)).StaticCast< ::flixel::input::keyboard::FlxKey >();
			HX_STACK_LINE(336)
			if (((key != null()))){
				HX_STACK_LINE(338)
				if (((key->current == Status))){
					HX_STACK_LINE(340)
					return true;
				}
				else{
					HX_STACK_LINE(342)
					if (((bool((Status == (int)1)) && bool((key->current == (int)2))))){
						HX_STACK_LINE(344)
						return true;
					}
					else{
						HX_STACK_LINE(346)
						if (((bool((Status == (int)0)) && bool((key->current == (int)-1))))){
							HX_STACK_LINE(348)
							return true;
						}
					}
				}
			}
			else{
				HX_STACK_LINE(354)
				::flixel::FlxG_obj::log->advanced(((HX_CSTRING("Invalid Key: `") + code) + HX_CSTRING("`. Note that function and numpad keys can only be used in flash and js.")),::flixel::system::debug::LogStyle_obj::ERROR,true);
			}
		}
	}
	HX_STACK_LINE(359)
	return false;
}


HX_DEFINE_DYNAMIC_FUNC2(FlxKeyboard_obj,checkKeyStatus,return )

Void FlxKeyboard_obj::onKeyUp( ::flash::events::KeyboardEvent FlashEvent){
{
		HX_STACK_FRAME("flixel.input.keyboard.FlxKeyboard","onKeyUp",0xa36f8255,"flixel.input.keyboard.FlxKeyboard.onKeyUp","flixel/input/keyboard/FlxKeyboard.hx",368,0x41882875)
		HX_STACK_THIS(this)
		HX_STACK_ARG(FlashEvent,"FlashEvent")
		HX_STACK_LINE(369)
		int c = FlashEvent->keyCode;		HX_STACK_VAR(c,"c");
		HX_STACK_LINE(373)
		if (((  (((::flixel::FlxG_obj::game->debugger != null()))) ? bool(this->inKeyArray(::flixel::FlxG_obj::debugger->toggleKeys,c)) : bool(false) ))){
			HX_STACK_LINE(375)
			bool Visible = !(::flixel::FlxG_obj::debugger->visible);		HX_STACK_VAR(Visible,"Visible");
			HX_STACK_LINE(375)
			::flixel::FlxG_obj::game->debugger->set_visible(Visible);
			HX_STACK_LINE(375)
			::flixel::FlxG_obj::debugger->visible = Visible;
		}
		HX_STACK_LINE(380)
		if ((!(this->enabled))){
			HX_STACK_LINE(382)
			return null();
		}
		HX_STACK_LINE(388)
		if ((this->inKeyArray(::flixel::FlxG_obj::sound->muteKeys,c))){
			HX_STACK_LINE(390)
			::flixel::FlxG_obj::sound->muted = !(::flixel::FlxG_obj::sound->muted);
			HX_STACK_LINE(392)
			if (((::flixel::FlxG_obj::sound->volumeHandler != null()))){
				HX_STACK_LINE(394)
				::flixel::FlxG_obj::sound->volumeHandler((  ((::flixel::FlxG_obj::sound->muted)) ? Float((int)0) : Float(::flixel::FlxG_obj::sound->volume) ));
			}
			HX_STACK_LINE(398)
			if (((::flixel::FlxG_obj::game->soundTray != null()))){
				HX_STACK_LINE(400)
				::flixel::FlxG_obj::game->soundTray->show(null());
			}
		}
		else{
			HX_STACK_LINE(405)
			if ((this->inKeyArray(::flixel::FlxG_obj::sound->volumeDownKeys,c))){
				HX_STACK_LINE(407)
				::flixel::FlxG_obj::sound->muted = false;
				HX_STACK_LINE(408)
				{
					HX_STACK_LINE(408)
					::flixel::system::frontEnds::SoundFrontEnd _g = ::flixel::FlxG_obj::sound;		HX_STACK_VAR(_g,"_g");
					HX_STACK_LINE(408)
					_g->set_volume((_g->volume - 0.1));
				}
				HX_STACK_LINE(411)
				if (((::flixel::FlxG_obj::game->soundTray != null()))){
					HX_STACK_LINE(413)
					::flixel::FlxG_obj::game->soundTray->show(null());
				}
			}
			else{
				HX_STACK_LINE(418)
				if ((this->inKeyArray(::flixel::FlxG_obj::sound->volumeUpKeys,c))){
					HX_STACK_LINE(420)
					::flixel::FlxG_obj::sound->muted = false;
					HX_STACK_LINE(421)
					{
						HX_STACK_LINE(421)
						::flixel::system::frontEnds::SoundFrontEnd _g = ::flixel::FlxG_obj::sound;		HX_STACK_VAR(_g,"_g");
						HX_STACK_LINE(421)
						_g->set_volume((_g->volume + 0.1));
					}
					HX_STACK_LINE(424)
					if (((::flixel::FlxG_obj::game->soundTray != null()))){
						HX_STACK_LINE(426)
						::flixel::FlxG_obj::game->soundTray->show(null());
					}
				}
			}
		}
		HX_STACK_LINE(432)
		{
			HX_STACK_LINE(432)
			::flixel::input::keyboard::FlxKey obj = this->_keyList->__get(c).StaticCast< ::flixel::input::keyboard::FlxKey >();		HX_STACK_VAR(obj,"obj");
			HX_STACK_LINE(432)
			if (((obj != null()))){
				HX_STACK_LINE(432)
				if (((obj->current > (int)0))){
					HX_STACK_LINE(432)
					obj->current = (int)-1;
				}
				else{
					HX_STACK_LINE(432)
					obj->current = (int)0;
				}
			}
		}
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC1(FlxKeyboard_obj,onKeyUp,(void))

Void FlxKeyboard_obj::onKeyDown( ::flash::events::KeyboardEvent FlashEvent){
{
		HX_STACK_FRAME("flixel.input.keyboard.FlxKeyboard","onKeyDown",0xf4d786dc,"flixel.input.keyboard.FlxKeyboard.onKeyDown","flixel/input/keyboard/FlxKeyboard.hx",441,0x41882875)
		HX_STACK_THIS(this)
		HX_STACK_ARG(FlashEvent,"FlashEvent")
		HX_STACK_LINE(442)
		int c = FlashEvent->keyCode;		HX_STACK_VAR(c,"c");
		HX_STACK_LINE(460)
		if ((this->enabled)){
			HX_STACK_LINE(462)
			::flixel::input::keyboard::FlxKey obj = this->_keyList->__get(c).StaticCast< ::flixel::input::keyboard::FlxKey >();		HX_STACK_VAR(obj,"obj");
			HX_STACK_LINE(462)
			if (((obj != null()))){
				HX_STACK_LINE(462)
				if (((obj->current > (int)0))){
					HX_STACK_LINE(462)
					obj->current = (int)1;
				}
				else{
					HX_STACK_LINE(462)
					obj->current = (int)2;
				}
			}
		}
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC1(FlxKeyboard_obj,onKeyDown,(void))

bool FlxKeyboard_obj::inKeyArray( Array< ::String > KeyArray,int KeyCode){
	HX_STACK_FRAME("flixel.input.keyboard.FlxKeyboard","inKeyArray",0x0dc3baa5,"flixel.input.keyboard.FlxKeyboard.inKeyArray","flixel/input/keyboard/FlxKeyboard.hx",471,0x41882875)
	HX_STACK_THIS(this)
	HX_STACK_ARG(KeyArray,"KeyArray")
	HX_STACK_ARG(KeyCode,"KeyCode")
	HX_STACK_LINE(472)
	if (((KeyArray == null()))){
		HX_STACK_LINE(474)
		return false;
	}
	else{
		HX_STACK_LINE(478)
		int _g = (int)0;		HX_STACK_VAR(_g,"_g");
		HX_STACK_LINE(478)
		while(((_g < KeyArray->length))){
			HX_STACK_LINE(478)
			::String keyString = KeyArray->__get(_g);		HX_STACK_VAR(keyString,"keyString");
			HX_STACK_LINE(478)
			++(_g);
			HX_STACK_LINE(480)
			if (((  ((!(((keyString == HX_CSTRING("ANY")))))) ? bool((this->_keyLookup->get(keyString) == KeyCode)) : bool(true) ))){
				HX_STACK_LINE(482)
				return true;
			}
		}
	}
	HX_STACK_LINE(487)
	return false;
}


HX_DEFINE_DYNAMIC_FUNC2(FlxKeyboard_obj,inKeyArray,return )

Void FlxKeyboard_obj::updateKeyStates( int KeyCode,bool Down){
{
		HX_STACK_FRAME("flixel.input.keyboard.FlxKeyboard","updateKeyStates",0x0e7ffd12,"flixel.input.keyboard.FlxKeyboard.updateKeyStates","flixel/input/keyboard/FlxKeyboard.hx",494,0x41882875)
		HX_STACK_THIS(this)
		HX_STACK_ARG(KeyCode,"KeyCode")
		HX_STACK_ARG(Down,"Down")
		HX_STACK_LINE(495)
		::flixel::input::keyboard::FlxKey obj = this->_keyList->__get(KeyCode).StaticCast< ::flixel::input::keyboard::FlxKey >();		HX_STACK_VAR(obj,"obj");
		HX_STACK_LINE(497)
		if (((obj != null()))){
			HX_STACK_LINE(499)
			if (((obj->current > (int)0))){
				HX_STACK_LINE(501)
				if ((Down)){
					HX_STACK_LINE(503)
					obj->current = (int)1;
				}
				else{
					HX_STACK_LINE(507)
					obj->current = (int)-1;
				}
			}
			else{
				HX_STACK_LINE(512)
				if ((Down)){
					HX_STACK_LINE(514)
					obj->current = (int)2;
				}
				else{
					HX_STACK_LINE(518)
					obj->current = (int)0;
				}
			}
		}
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC2(FlxKeyboard_obj,updateKeyStates,(void))

Void FlxKeyboard_obj::onFocus( ){
{
		HX_STACK_FRAME("flixel.input.keyboard.FlxKeyboard","onFocus",0xc8fa2853,"flixel.input.keyboard.FlxKeyboard.onFocus","flixel/input/keyboard/FlxKeyboard.hx",524,0x41882875)
		HX_STACK_THIS(this)
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC0(FlxKeyboard_obj,onFocus,(void))

Void FlxKeyboard_obj::onFocusLost( ){
{
		HX_STACK_FRAME("flixel.input.keyboard.FlxKeyboard","onFocusLost",0xd20123d7,"flixel.input.keyboard.FlxKeyboard.onFocusLost","flixel/input/keyboard/FlxKeyboard.hx",528,0x41882875)
		HX_STACK_THIS(this)
		HX_STACK_LINE(528)
		this->reset();
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC0(FlxKeyboard_obj,onFocusLost,(void))

Array< ::Dynamic > FlxKeyboard_obj::record( ){
	HX_STACK_FRAME("flixel.input.keyboard.FlxKeyboard","record",0x38ad8db7,"flixel.input.keyboard.FlxKeyboard.record","flixel/input/keyboard/FlxKeyboard.hx",541,0x41882875)
	HX_STACK_THIS(this)
	HX_STACK_LINE(542)
	Array< ::Dynamic > data = null();		HX_STACK_VAR(data,"data");
	HX_STACK_LINE(543)
	int i = (int)0;		HX_STACK_VAR(i,"i");
	HX_STACK_LINE(545)
	while(((i < (int)256))){
		HX_STACK_LINE(547)
		::flixel::input::keyboard::FlxKey key = this->_keyList->__get((i)++).StaticCast< ::flixel::input::keyboard::FlxKey >();		HX_STACK_VAR(key,"key");
		HX_STACK_LINE(549)
		if (((bool((key == null())) || bool((key->current == (int)0))))){
			HX_STACK_LINE(551)
			continue;
		}
		HX_STACK_LINE(554)
		if (((data == null()))){
			HX_STACK_LINE(556)
			data = Array_obj< ::Dynamic >::__new();
		}
		HX_STACK_LINE(559)
		data->push(::flixel::system::replay::CodeValuePair_obj::__new((i - (int)1),key->current));
	}
	HX_STACK_LINE(561)
	return data;
}


HX_DEFINE_DYNAMIC_FUNC0(FlxKeyboard_obj,record,return )

Void FlxKeyboard_obj::playback( Array< ::Dynamic > Record){
{
		HX_STACK_FRAME("flixel.input.keyboard.FlxKeyboard","playback",0x84dcbec1,"flixel.input.keyboard.FlxKeyboard.playback","flixel/input/keyboard/FlxKeyboard.hx",571,0x41882875)
		HX_STACK_THIS(this)
		HX_STACK_ARG(Record,"Record")
		HX_STACK_LINE(572)
		int i = (int)0;		HX_STACK_VAR(i,"i");
		HX_STACK_LINE(573)
		int l = Record->length;		HX_STACK_VAR(l,"l");
		HX_STACK_LINE(574)
		::flixel::system::replay::CodeValuePair o;		HX_STACK_VAR(o,"o");
		HX_STACK_LINE(575)
		::flixel::input::keyboard::FlxKey o2;		HX_STACK_VAR(o2,"o2");
		HX_STACK_LINE(577)
		while(((i < l))){
			HX_STACK_LINE(579)
			o = Record->__get((i)++).StaticCast< ::flixel::system::replay::CodeValuePair >();
			HX_STACK_LINE(580)
			o2 = this->_keyList->__get(o->code).StaticCast< ::flixel::input::keyboard::FlxKey >();
			HX_STACK_LINE(581)
			o2->current = o->value;
		}
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC1(FlxKeyboard_obj,playback,(void))

int FlxKeyboard_obj::TOTAL;


FlxKeyboard_obj::FlxKeyboard_obj()
{
}

void FlxKeyboard_obj::__Mark(HX_MARK_PARAMS)
{
	HX_MARK_BEGIN_CLASS(FlxKeyboard);
	HX_MARK_MEMBER_NAME(enabled,"enabled");
	HX_MARK_MEMBER_NAME(pressed,"pressed");
	HX_MARK_MEMBER_NAME(justPressed,"justPressed");
	HX_MARK_MEMBER_NAME(justReleased,"justReleased");
	HX_MARK_MEMBER_NAME(_keyLookup,"_keyLookup");
	HX_MARK_MEMBER_NAME(_keyList,"_keyList");
	HX_MARK_END_CLASS();
}

void FlxKeyboard_obj::__Visit(HX_VISIT_PARAMS)
{
	HX_VISIT_MEMBER_NAME(enabled,"enabled");
	HX_VISIT_MEMBER_NAME(pressed,"pressed");
	HX_VISIT_MEMBER_NAME(justPressed,"justPressed");
	HX_VISIT_MEMBER_NAME(justReleased,"justReleased");
	HX_VISIT_MEMBER_NAME(_keyLookup,"_keyLookup");
	HX_VISIT_MEMBER_NAME(_keyList,"_keyList");
}

Dynamic FlxKeyboard_obj::__Field(const ::String &inName,bool inCallProp)
{
	switch(inName.length) {
	case 5:
		if (HX_FIELD_EQ(inName,"reset") ) { return reset_dyn(); }
		break;
	case 6:
		if (HX_FIELD_EQ(inName,"addKey") ) { return addKey_dyn(); }
		if (HX_FIELD_EQ(inName,"update") ) { return update_dyn(); }
		if (HX_FIELD_EQ(inName,"record") ) { return record_dyn(); }
		break;
	case 7:
		if (HX_FIELD_EQ(inName,"enabled") ) { return enabled; }
		if (HX_FIELD_EQ(inName,"pressed") ) { return pressed; }
		if (HX_FIELD_EQ(inName,"destroy") ) { return destroy_dyn(); }
		if (HX_FIELD_EQ(inName,"onKeyUp") ) { return onKeyUp_dyn(); }
		if (HX_FIELD_EQ(inName,"onFocus") ) { return onFocus_dyn(); }
		break;
	case 8:
		if (HX_FIELD_EQ(inName,"_keyList") ) { return _keyList; }
		if (HX_FIELD_EQ(inName,"playback") ) { return playback_dyn(); }
		break;
	case 9:
		if (HX_FIELD_EQ(inName,"getIsDown") ) { return getIsDown_dyn(); }
		if (HX_FIELD_EQ(inName,"onKeyDown") ) { return onKeyDown_dyn(); }
		break;
	case 10:
		if (HX_FIELD_EQ(inName,"_keyLookup") ) { return _keyLookup; }
		if (HX_FIELD_EQ(inName,"anyPressed") ) { return anyPressed_dyn(); }
		if (HX_FIELD_EQ(inName,"getKeyCode") ) { return getKeyCode_dyn(); }
		if (HX_FIELD_EQ(inName,"inKeyArray") ) { return inKeyArray_dyn(); }
		break;
	case 11:
		if (HX_FIELD_EQ(inName,"justPressed") ) { return justPressed; }
		if (HX_FIELD_EQ(inName,"checkStatus") ) { return checkStatus_dyn(); }
		if (HX_FIELD_EQ(inName,"onFocusLost") ) { return onFocusLost_dyn(); }
		break;
	case 12:
		if (HX_FIELD_EQ(inName,"justReleased") ) { return justReleased; }
		break;
	case 14:
		if (HX_FIELD_EQ(inName,"anyJustPressed") ) { return anyJustPressed_dyn(); }
		if (HX_FIELD_EQ(inName,"checkKeyStatus") ) { return checkKeyStatus_dyn(); }
		break;
	case 15:
		if (HX_FIELD_EQ(inName,"anyJustReleased") ) { return anyJustReleased_dyn(); }
		if (HX_FIELD_EQ(inName,"updateKeyStates") ) { return updateKeyStates_dyn(); }
	}
	return super::__Field(inName,inCallProp);
}

Dynamic FlxKeyboard_obj::__SetField(const ::String &inName,const Dynamic &inValue,bool inCallProp)
{
	switch(inName.length) {
	case 7:
		if (HX_FIELD_EQ(inName,"enabled") ) { enabled=inValue.Cast< bool >(); return inValue; }
		if (HX_FIELD_EQ(inName,"pressed") ) { pressed=inValue.Cast< ::flixel::input::keyboard::FlxKeyList >(); return inValue; }
		break;
	case 8:
		if (HX_FIELD_EQ(inName,"_keyList") ) { _keyList=inValue.Cast< Array< ::Dynamic > >(); return inValue; }
		break;
	case 10:
		if (HX_FIELD_EQ(inName,"_keyLookup") ) { _keyLookup=inValue.Cast< ::haxe::ds::StringMap >(); return inValue; }
		break;
	case 11:
		if (HX_FIELD_EQ(inName,"justPressed") ) { justPressed=inValue.Cast< ::flixel::input::keyboard::FlxKeyList >(); return inValue; }
		break;
	case 12:
		if (HX_FIELD_EQ(inName,"justReleased") ) { justReleased=inValue.Cast< ::flixel::input::keyboard::FlxKeyList >(); return inValue; }
	}
	return super::__SetField(inName,inValue,inCallProp);
}

void FlxKeyboard_obj::__GetFields(Array< ::String> &outFields)
{
	outFields->push(HX_CSTRING("enabled"));
	outFields->push(HX_CSTRING("pressed"));
	outFields->push(HX_CSTRING("justPressed"));
	outFields->push(HX_CSTRING("justReleased"));
	outFields->push(HX_CSTRING("_keyLookup"));
	outFields->push(HX_CSTRING("_keyList"));
	super::__GetFields(outFields);
};

static ::String sStaticFields[] = {
	HX_CSTRING("TOTAL"),
	String(null()) };

#if HXCPP_SCRIPTABLE
static hx::StorageInfo sMemberStorageInfo[] = {
	{hx::fsBool,(int)offsetof(FlxKeyboard_obj,enabled),HX_CSTRING("enabled")},
	{hx::fsObject /*::flixel::input::keyboard::FlxKeyList*/ ,(int)offsetof(FlxKeyboard_obj,pressed),HX_CSTRING("pressed")},
	{hx::fsObject /*::flixel::input::keyboard::FlxKeyList*/ ,(int)offsetof(FlxKeyboard_obj,justPressed),HX_CSTRING("justPressed")},
	{hx::fsObject /*::flixel::input::keyboard::FlxKeyList*/ ,(int)offsetof(FlxKeyboard_obj,justReleased),HX_CSTRING("justReleased")},
	{hx::fsObject /*::haxe::ds::StringMap*/ ,(int)offsetof(FlxKeyboard_obj,_keyLookup),HX_CSTRING("_keyLookup")},
	{hx::fsObject /*Array< ::Dynamic >*/ ,(int)offsetof(FlxKeyboard_obj,_keyList),HX_CSTRING("_keyList")},
	{ hx::fsUnknown, 0, null()}
};
#endif

static ::String sMemberFields[] = {
	HX_CSTRING("enabled"),
	HX_CSTRING("pressed"),
	HX_CSTRING("justPressed"),
	HX_CSTRING("justReleased"),
	HX_CSTRING("_keyLookup"),
	HX_CSTRING("_keyList"),
	HX_CSTRING("anyPressed"),
	HX_CSTRING("anyJustPressed"),
	HX_CSTRING("anyJustReleased"),
	HX_CSTRING("checkStatus"),
	HX_CSTRING("getKeyCode"),
	HX_CSTRING("getIsDown"),
	HX_CSTRING("destroy"),
	HX_CSTRING("reset"),
	HX_CSTRING("addKey"),
	HX_CSTRING("update"),
	HX_CSTRING("checkKeyStatus"),
	HX_CSTRING("onKeyUp"),
	HX_CSTRING("onKeyDown"),
	HX_CSTRING("inKeyArray"),
	HX_CSTRING("updateKeyStates"),
	HX_CSTRING("onFocus"),
	HX_CSTRING("onFocusLost"),
	HX_CSTRING("record"),
	HX_CSTRING("playback"),
	String(null()) };

static void sMarkStatics(HX_MARK_PARAMS) {
	HX_MARK_MEMBER_NAME(FlxKeyboard_obj::__mClass,"__mClass");
	HX_MARK_MEMBER_NAME(FlxKeyboard_obj::TOTAL,"TOTAL");
};

#ifdef HXCPP_VISIT_ALLOCS
static void sVisitStatics(HX_VISIT_PARAMS) {
	HX_VISIT_MEMBER_NAME(FlxKeyboard_obj::__mClass,"__mClass");
	HX_VISIT_MEMBER_NAME(FlxKeyboard_obj::TOTAL,"TOTAL");
};

#endif

Class FlxKeyboard_obj::__mClass;

void FlxKeyboard_obj::__register()
{
	hx::Static(__mClass) = hx::RegisterClass(HX_CSTRING("flixel.input.keyboard.FlxKeyboard"), hx::TCanCast< FlxKeyboard_obj> ,sStaticFields,sMemberFields,
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

void FlxKeyboard_obj::__boot()
{
	TOTAL= (int)256;
}

} // end namespace flixel
} // end namespace input
} // end namespace keyboard
