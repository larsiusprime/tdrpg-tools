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
#ifndef INCLUDED_flixel_FlxG
#include <flixel/FlxG.h>
#endif
#ifndef INCLUDED_flixel_input_gamepad_FlxGamepad
#include <flixel/input/gamepad/FlxGamepad.h>
#endif
#ifndef INCLUDED_flixel_input_gamepad_FlxGamepadButton
#include <flixel/input/gamepad/FlxGamepadButton.h>
#endif
#ifndef INCLUDED_flixel_input_gamepad_FlxGamepadManager
#include <flixel/input/gamepad/FlxGamepadManager.h>
#endif
#ifndef INCLUDED_flixel_interfaces_IFlxDestroyable
#include <flixel/interfaces/IFlxDestroyable.h>
#endif
#ifndef INCLUDED_flixel_interfaces_IFlxInput
#include <flixel/interfaces/IFlxInput.h>
#endif
#ifndef INCLUDED_flixel_util_FlxPoint
#include <flixel/util/FlxPoint.h>
#endif
#ifndef INCLUDED_haxe_ds_IntMap
#include <haxe/ds/IntMap.h>
#endif
#ifndef INCLUDED_hxMath
#include <hxMath.h>
#endif
#ifndef INCLUDED_openfl_events_JoystickEvent
#include <openfl/events/JoystickEvent.h>
#endif
namespace flixel{
namespace input{
namespace gamepad{

Void FlxGamepadManager_obj::__construct()
{
HX_STACK_FRAME("flixel.input.gamepad.FlxGamepadManager","new",0x05218fad,"flixel.input.gamepad.FlxGamepadManager.new","flixel/input/gamepad/FlxGamepadManager.hx",301,0xccfee0a6)
{
	HX_STACK_LINE(302)
	this->firstActive = null();
	HX_STACK_LINE(303)
	this->lastActive = null();
	HX_STACK_LINE(304)
	this->_gamepads = ::haxe::ds::IntMap_obj::__new();
	HX_STACK_LINE(307)
	::flash::Lib_obj::get_current()->get_stage()->addEventListener(HX_CSTRING("axisMove"),this->handleAxisMove_dyn(),null(),null(),null());
	HX_STACK_LINE(308)
	::flash::Lib_obj::get_current()->get_stage()->addEventListener(HX_CSTRING("ballMove"),this->handleBallMove_dyn(),null(),null(),null());
	HX_STACK_LINE(309)
	::flash::Lib_obj::get_current()->get_stage()->addEventListener(HX_CSTRING("buttonDown"),this->handleButtonDown_dyn(),null(),null(),null());
	HX_STACK_LINE(310)
	::flash::Lib_obj::get_current()->get_stage()->addEventListener(HX_CSTRING("buttonUp"),this->handleButtonUp_dyn(),null(),null(),null());
	HX_STACK_LINE(311)
	::flash::Lib_obj::get_current()->get_stage()->addEventListener(HX_CSTRING("hatMove"),this->handleHatMove_dyn(),null(),null(),null());
}
;
	return null();
}

//FlxGamepadManager_obj::~FlxGamepadManager_obj() { }

Dynamic FlxGamepadManager_obj::__CreateEmpty() { return  new FlxGamepadManager_obj; }
hx::ObjectPtr< FlxGamepadManager_obj > FlxGamepadManager_obj::__new()
{  hx::ObjectPtr< FlxGamepadManager_obj > result = new FlxGamepadManager_obj();
	result->__construct();
	return result;}

Dynamic FlxGamepadManager_obj::__Create(hx::DynamicArray inArgs)
{  hx::ObjectPtr< FlxGamepadManager_obj > result = new FlxGamepadManager_obj();
	result->__construct();
	return result;}

hx::Object *FlxGamepadManager_obj::__ToInterface(const hx::type_info &inType) {
	if (inType==typeid( ::flixel::interfaces::IFlxInput_obj)) return operator ::flixel::interfaces::IFlxInput_obj *();
	return super::__ToInterface(inType);
}

::flixel::input::gamepad::FlxGamepad FlxGamepadManager_obj::getByID( int GamepadID){
	HX_STACK_FRAME("flixel.input.gamepad.FlxGamepadManager","getByID",0xe19992f5,"flixel.input.gamepad.FlxGamepadManager.getByID","flixel/input/gamepad/FlxGamepadManager.hx",44,0xccfee0a6)
	HX_STACK_THIS(this)
	HX_STACK_ARG(GamepadID,"GamepadID")
	HX_STACK_LINE(45)
	::flixel::input::gamepad::FlxGamepad gamepad = this->_gamepads->get(GamepadID);		HX_STACK_VAR(gamepad,"gamepad");
	HX_STACK_LINE(47)
	if (((gamepad == null()))){
		HX_STACK_LINE(49)
		gamepad = ::flixel::input::gamepad::FlxGamepad_obj::__new(GamepadID,this->globalDeadZone);
		HX_STACK_LINE(50)
		this->_gamepads->set(GamepadID,gamepad);
		HX_STACK_LINE(52)
		this->lastActive = gamepad;
		HX_STACK_LINE(53)
		if (((this->firstActive == null()))){
			HX_STACK_LINE(54)
			this->firstActive = gamepad;
		}
	}
	HX_STACK_LINE(57)
	return gamepad;
}


HX_DEFINE_DYNAMIC_FUNC1(FlxGamepadManager_obj,getByID,return )

Array< int > FlxGamepadManager_obj::getActiveGamepadIDs( Array< int > IDsArray){
	HX_STACK_FRAME("flixel.input.gamepad.FlxGamepadManager","getActiveGamepadIDs",0x2dbae5a0,"flixel.input.gamepad.FlxGamepadManager.getActiveGamepadIDs","flixel/input/gamepad/FlxGamepadManager.hx",66,0xccfee0a6)
	HX_STACK_THIS(this)
	HX_STACK_ARG(IDsArray,"IDsArray")
	HX_STACK_LINE(67)
	if (((IDsArray == null()))){
		HX_STACK_LINE(69)
		IDsArray = Array_obj< int >::__new();
	}
	HX_STACK_LINE(72)
	Dynamic it = this->_gamepads->iterator();		HX_STACK_VAR(it,"it");
	HX_STACK_LINE(73)
	::flixel::input::gamepad::FlxGamepad gamepad = it->__Field(HX_CSTRING("next"),true)();		HX_STACK_VAR(gamepad,"gamepad");
	HX_STACK_LINE(75)
	while(((gamepad != null()))){
		HX_STACK_LINE(77)
		if ((gamepad->anyInput())){
			HX_STACK_LINE(79)
			IDsArray->push(gamepad->id);
		}
		HX_STACK_LINE(82)
		gamepad = it->__Field(HX_CSTRING("next"),true)();
	}
	HX_STACK_LINE(85)
	return IDsArray;
}


HX_DEFINE_DYNAMIC_FUNC1(FlxGamepadManager_obj,getActiveGamepadIDs,return )

Array< ::Dynamic > FlxGamepadManager_obj::getActiveGamepads( Array< ::Dynamic > GamepadArray){
	HX_STACK_FRAME("flixel.input.gamepad.FlxGamepadManager","getActiveGamepads",0xd3d79bdb,"flixel.input.gamepad.FlxGamepadManager.getActiveGamepads","flixel/input/gamepad/FlxGamepadManager.hx",94,0xccfee0a6)
	HX_STACK_THIS(this)
	HX_STACK_ARG(GamepadArray,"GamepadArray")
	HX_STACK_LINE(95)
	if (((GamepadArray == null()))){
		HX_STACK_LINE(97)
		GamepadArray = Array_obj< ::Dynamic >::__new();
	}
	HX_STACK_LINE(100)
	Dynamic it = this->_gamepads->iterator();		HX_STACK_VAR(it,"it");
	HX_STACK_LINE(101)
	::flixel::input::gamepad::FlxGamepad gamepad = it->__Field(HX_CSTRING("next"),true)();		HX_STACK_VAR(gamepad,"gamepad");
	HX_STACK_LINE(103)
	while(((gamepad != null()))){
		HX_STACK_LINE(105)
		if ((gamepad->anyInput())){
			HX_STACK_LINE(107)
			GamepadArray->push(gamepad);
		}
		HX_STACK_LINE(110)
		gamepad = it->__Field(HX_CSTRING("next"),true)();
	}
	HX_STACK_LINE(113)
	return GamepadArray;
}


HX_DEFINE_DYNAMIC_FUNC1(FlxGamepadManager_obj,getActiveGamepads,return )

int FlxGamepadManager_obj::getFirstActiveGamepadID( ){
	HX_STACK_FRAME("flixel.input.gamepad.FlxGamepadManager","getFirstActiveGamepadID",0x40a7d549,"flixel.input.gamepad.FlxGamepadManager.getFirstActiveGamepadID","flixel/input/gamepad/FlxGamepadManager.hx",121,0xccfee0a6)
	HX_STACK_THIS(this)
	HX_STACK_LINE(122)
	Dynamic it = this->_gamepads->iterator();		HX_STACK_VAR(it,"it");
	HX_STACK_LINE(123)
	::flixel::input::gamepad::FlxGamepad gamepad = it->__Field(HX_CSTRING("next"),true)();		HX_STACK_VAR(gamepad,"gamepad");
	HX_STACK_LINE(125)
	while(((gamepad != null()))){
		HX_STACK_LINE(127)
		if ((gamepad->anyInput())){
			HX_STACK_LINE(129)
			return gamepad->id;
		}
		HX_STACK_LINE(132)
		gamepad = it->__Field(HX_CSTRING("next"),true)();
	}
	HX_STACK_LINE(135)
	return (int)-1;
}


HX_DEFINE_DYNAMIC_FUNC0(FlxGamepadManager_obj,getFirstActiveGamepadID,return )

::flixel::input::gamepad::FlxGamepad FlxGamepadManager_obj::getFirstActiveGamepad( ){
	HX_STACK_FRAME("flixel.input.gamepad.FlxGamepadManager","getFirstActiveGamepad",0x4c49bdee,"flixel.input.gamepad.FlxGamepadManager.getFirstActiveGamepad","flixel/input/gamepad/FlxGamepadManager.hx",143,0xccfee0a6)
	HX_STACK_THIS(this)
	HX_STACK_LINE(144)
	Dynamic it = this->_gamepads->iterator();		HX_STACK_VAR(it,"it");
	HX_STACK_LINE(145)
	::flixel::input::gamepad::FlxGamepad gamepad = it->__Field(HX_CSTRING("next"),true)();		HX_STACK_VAR(gamepad,"gamepad");
	HX_STACK_LINE(147)
	while(((gamepad != null()))){
		HX_STACK_LINE(149)
		if ((gamepad->anyInput())){
			HX_STACK_LINE(151)
			return gamepad;
		}
		HX_STACK_LINE(154)
		gamepad = it->__Field(HX_CSTRING("next"),true)();
	}
	HX_STACK_LINE(157)
	return null();
}


HX_DEFINE_DYNAMIC_FUNC0(FlxGamepadManager_obj,getFirstActiveGamepad,return )

bool FlxGamepadManager_obj::anyButton( ){
	HX_STACK_FRAME("flixel.input.gamepad.FlxGamepadManager","anyButton",0x595b810b,"flixel.input.gamepad.FlxGamepadManager.anyButton","flixel/input/gamepad/FlxGamepadManager.hx",164,0xccfee0a6)
	HX_STACK_THIS(this)
	HX_STACK_LINE(165)
	Dynamic it = this->_gamepads->iterator();		HX_STACK_VAR(it,"it");
	HX_STACK_LINE(166)
	::flixel::input::gamepad::FlxGamepad gamepad = it->__Field(HX_CSTRING("next"),true)();		HX_STACK_VAR(gamepad,"gamepad");
	HX_STACK_LINE(168)
	while(((gamepad != null()))){
		HX_STACK_LINE(170)
		if ((gamepad->anyButton())){
			HX_STACK_LINE(172)
			return true;
		}
		HX_STACK_LINE(175)
		gamepad = it->__Field(HX_CSTRING("next"),true)();
	}
	HX_STACK_LINE(178)
	return false;
}


HX_DEFINE_DYNAMIC_FUNC0(FlxGamepadManager_obj,anyButton,return )

bool FlxGamepadManager_obj::anyInput( ){
	HX_STACK_FRAME("flixel.input.gamepad.FlxGamepadManager","anyInput",0xa448cb11,"flixel.input.gamepad.FlxGamepadManager.anyInput","flixel/input/gamepad/FlxGamepadManager.hx",185,0xccfee0a6)
	HX_STACK_THIS(this)
	HX_STACK_LINE(186)
	Dynamic it = this->_gamepads->iterator();		HX_STACK_VAR(it,"it");
	HX_STACK_LINE(187)
	::flixel::input::gamepad::FlxGamepad gamepad = it->__Field(HX_CSTRING("next"),true)();		HX_STACK_VAR(gamepad,"gamepad");
	HX_STACK_LINE(189)
	while(((gamepad != null()))){
		HX_STACK_LINE(191)
		if ((gamepad->anyInput())){
			HX_STACK_LINE(193)
			return true;
		}
		HX_STACK_LINE(196)
		gamepad = it->__Field(HX_CSTRING("next"),true)();
	}
	HX_STACK_LINE(199)
	return false;
}


HX_DEFINE_DYNAMIC_FUNC0(FlxGamepadManager_obj,anyInput,return )

bool FlxGamepadManager_obj::anyPressed( int ButtonID){
	HX_STACK_FRAME("flixel.input.gamepad.FlxGamepadManager","anyPressed",0x4626e969,"flixel.input.gamepad.FlxGamepadManager.anyPressed","flixel/input/gamepad/FlxGamepadManager.hx",209,0xccfee0a6)
	HX_STACK_THIS(this)
	HX_STACK_ARG(ButtonID,"ButtonID")
	HX_STACK_LINE(210)
	Dynamic it = this->_gamepads->iterator();		HX_STACK_VAR(it,"it");
	HX_STACK_LINE(211)
	::flixel::input::gamepad::FlxGamepad gamepad = it->__Field(HX_CSTRING("next"),true)();		HX_STACK_VAR(gamepad,"gamepad");
	HX_STACK_LINE(213)
	while(((gamepad != null()))){
		HX_STACK_LINE(215)
		if ((gamepad->pressed(ButtonID))){
			HX_STACK_LINE(217)
			return true;
		}
		HX_STACK_LINE(220)
		gamepad = it->__Field(HX_CSTRING("next"),true)();
	}
	HX_STACK_LINE(223)
	return false;
}


HX_DEFINE_DYNAMIC_FUNC1(FlxGamepadManager_obj,anyPressed,return )

bool FlxGamepadManager_obj::anyJustPressed( int ButtonID){
	HX_STACK_FRAME("flixel.input.gamepad.FlxGamepadManager","anyJustPressed",0x8467941d,"flixel.input.gamepad.FlxGamepadManager.anyJustPressed","flixel/input/gamepad/FlxGamepadManager.hx",233,0xccfee0a6)
	HX_STACK_THIS(this)
	HX_STACK_ARG(ButtonID,"ButtonID")
	HX_STACK_LINE(234)
	Dynamic it = this->_gamepads->iterator();		HX_STACK_VAR(it,"it");
	HX_STACK_LINE(235)
	::flixel::input::gamepad::FlxGamepad gamepad = it->__Field(HX_CSTRING("next"),true)();		HX_STACK_VAR(gamepad,"gamepad");
	HX_STACK_LINE(237)
	while(((gamepad != null()))){
		HX_STACK_LINE(239)
		if ((gamepad->justPressed(ButtonID))){
			HX_STACK_LINE(241)
			return true;
		}
		HX_STACK_LINE(244)
		gamepad = it->__Field(HX_CSTRING("next"),true)();
	}
	HX_STACK_LINE(246)
	return false;
}


HX_DEFINE_DYNAMIC_FUNC1(FlxGamepadManager_obj,anyJustPressed,return )

bool FlxGamepadManager_obj::anyJustReleased( int ButtonID){
	HX_STACK_FRAME("flixel.input.gamepad.FlxGamepadManager","anyJustReleased",0x5d1012e2,"flixel.input.gamepad.FlxGamepadManager.anyJustReleased","flixel/input/gamepad/FlxGamepadManager.hx",256,0xccfee0a6)
	HX_STACK_THIS(this)
	HX_STACK_ARG(ButtonID,"ButtonID")
	HX_STACK_LINE(257)
	Dynamic it = this->_gamepads->iterator();		HX_STACK_VAR(it,"it");
	HX_STACK_LINE(258)
	::flixel::input::gamepad::FlxGamepad gamepad = it->__Field(HX_CSTRING("next"),true)();		HX_STACK_VAR(gamepad,"gamepad");
	HX_STACK_LINE(260)
	while(((gamepad != null()))){
		HX_STACK_LINE(262)
		if ((gamepad->justReleased(ButtonID))){
			HX_STACK_LINE(264)
			return true;
		}
		HX_STACK_LINE(267)
		gamepad = it->__Field(HX_CSTRING("next"),true)();
	}
	HX_STACK_LINE(269)
	return false;
}


HX_DEFINE_DYNAMIC_FUNC1(FlxGamepadManager_obj,anyJustReleased,return )

Void FlxGamepadManager_obj::destroy( ){
{
		HX_STACK_FRAME("flixel.input.gamepad.FlxGamepadManager","destroy",0xf27a16c7,"flixel.input.gamepad.FlxGamepadManager.destroy","flixel/input/gamepad/FlxGamepadManager.hx",276,0xccfee0a6)
		HX_STACK_THIS(this)
		HX_STACK_LINE(277)
		for(::cpp::FastIterator_obj< ::flixel::input::gamepad::FlxGamepad > *__it = ::cpp::CreateFastIterator< ::flixel::input::gamepad::FlxGamepad >(this->_gamepads->iterator());  __it->hasNext(); ){
			::flixel::input::gamepad::FlxGamepad gamepad = __it->next();
			gamepad->destroy();
		}
		HX_STACK_LINE(282)
		this->firstActive = ::flixel::FlxG_obj::safeDestroy(this->firstActive);
		HX_STACK_LINE(283)
		this->lastActive = ::flixel::FlxG_obj::safeDestroy(this->lastActive);
		HX_STACK_LINE(284)
		this->_gamepads = ::haxe::ds::IntMap_obj::__new();
		HX_STACK_LINE(285)
		this->numActiveGamepads = (int)0;
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC0(FlxGamepadManager_obj,destroy,(void))

Void FlxGamepadManager_obj::reset( ){
{
		HX_STACK_FRAME("flixel.input.gamepad.FlxGamepadManager","reset",0x09fe365c,"flixel.input.gamepad.FlxGamepadManager.reset","flixel/input/gamepad/FlxGamepadManager.hx",293,0xccfee0a6)
		HX_STACK_THIS(this)
		HX_STACK_LINE(293)
		for(::cpp::FastIterator_obj< ::flixel::input::gamepad::FlxGamepad > *__it = ::cpp::CreateFastIterator< ::flixel::input::gamepad::FlxGamepad >(this->_gamepads->iterator());  __it->hasNext(); ){
			::flixel::input::gamepad::FlxGamepad gamepad = __it->next();
			gamepad->reset();
		}
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC0(FlxGamepadManager_obj,reset,(void))

Void FlxGamepadManager_obj::handleButtonDown( ::openfl::events::JoystickEvent FlashEvent){
{
		HX_STACK_FRAME("flixel.input.gamepad.FlxGamepadManager","handleButtonDown",0x9a9405cf,"flixel.input.gamepad.FlxGamepadManager.handleButtonDown","flixel/input/gamepad/FlxGamepadManager.hx",317,0xccfee0a6)
		HX_STACK_THIS(this)
		HX_STACK_ARG(FlashEvent,"FlashEvent")
		HX_STACK_LINE(318)
		::flixel::input::gamepad::FlxGamepad gamepad = this->getByID(FlashEvent->device);		HX_STACK_VAR(gamepad,"gamepad");
		HX_STACK_LINE(319)
		::flixel::input::gamepad::FlxGamepadButton o = gamepad->getButton(FlashEvent->id);		HX_STACK_VAR(o,"o");
		HX_STACK_LINE(321)
		if (((o == null()))){
			HX_STACK_LINE(323)
			return null();
		}
		HX_STACK_LINE(326)
		if (((o->current > (int)0))){
			HX_STACK_LINE(328)
			o->current = (int)1;
		}
		else{
			HX_STACK_LINE(332)
			o->current = (int)2;
		}
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC1(FlxGamepadManager_obj,handleButtonDown,(void))

Void FlxGamepadManager_obj::handleButtonUp( ::openfl::events::JoystickEvent FlashEvent){
{
		HX_STACK_FRAME("flixel.input.gamepad.FlxGamepadManager","handleButtonUp",0x87ba4e88,"flixel.input.gamepad.FlxGamepadManager.handleButtonUp","flixel/input/gamepad/FlxGamepadManager.hx",337,0xccfee0a6)
		HX_STACK_THIS(this)
		HX_STACK_ARG(FlashEvent,"FlashEvent")
		HX_STACK_LINE(338)
		::flixel::input::gamepad::FlxGamepad gamepad = this->getByID(FlashEvent->device);		HX_STACK_VAR(gamepad,"gamepad");
		HX_STACK_LINE(339)
		::flixel::input::gamepad::FlxGamepadButton object = gamepad->getButton(FlashEvent->id);		HX_STACK_VAR(object,"object");
		HX_STACK_LINE(341)
		if (((object == null()))){
			HX_STACK_LINE(343)
			return null();
		}
		HX_STACK_LINE(346)
		if (((object->current > (int)0))){
			HX_STACK_LINE(348)
			object->current = (int)-1;
		}
		else{
			HX_STACK_LINE(352)
			object->current = (int)0;
		}
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC1(FlxGamepadManager_obj,handleButtonUp,(void))

Void FlxGamepadManager_obj::handleAxisMove( ::openfl::events::JoystickEvent FlashEvent){
{
		HX_STACK_FRAME("flixel.input.gamepad.FlxGamepadManager","handleAxisMove",0xbb7c51ed,"flixel.input.gamepad.FlxGamepadManager.handleAxisMove","flixel/input/gamepad/FlxGamepadManager.hx",357,0xccfee0a6)
		HX_STACK_THIS(this)
		HX_STACK_ARG(FlashEvent,"FlashEvent")
		HX_STACK_LINE(358)
		::flixel::input::gamepad::FlxGamepad gamepad = this->getByID(FlashEvent->device);		HX_STACK_VAR(gamepad,"gamepad");
		HX_STACK_LINE(359)
		gamepad->axis = FlashEvent->axis;
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC1(FlxGamepadManager_obj,handleAxisMove,(void))

Void FlxGamepadManager_obj::handleBallMove( ::openfl::events::JoystickEvent FlashEvent){
{
		HX_STACK_FRAME("flixel.input.gamepad.FlxGamepadManager","handleBallMove",0x63851e4b,"flixel.input.gamepad.FlxGamepadManager.handleBallMove","flixel/input/gamepad/FlxGamepadManager.hx",363,0xccfee0a6)
		HX_STACK_THIS(this)
		HX_STACK_ARG(FlashEvent,"FlashEvent")
		HX_STACK_LINE(364)
		::flixel::input::gamepad::FlxGamepad gamepad = this->getByID(FlashEvent->device);		HX_STACK_VAR(gamepad,"gamepad");
		HX_STACK_LINE(365)
		gamepad->ball->set_x((  (((::Math_obj::abs(FlashEvent->x) < gamepad->deadZone))) ? Float((int)0) : Float(FlashEvent->x) ));
		HX_STACK_LINE(366)
		gamepad->ball->set_y((  (((::Math_obj::abs(FlashEvent->y) < gamepad->deadZone))) ? Float((int)0) : Float(FlashEvent->y) ));
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC1(FlxGamepadManager_obj,handleBallMove,(void))

Void FlxGamepadManager_obj::handleHatMove( ::openfl::events::JoystickEvent FlashEvent){
{
		HX_STACK_FRAME("flixel.input.gamepad.FlxGamepadManager","handleHatMove",0x5f7942d1,"flixel.input.gamepad.FlxGamepadManager.handleHatMove","flixel/input/gamepad/FlxGamepadManager.hx",370,0xccfee0a6)
		HX_STACK_THIS(this)
		HX_STACK_ARG(FlashEvent,"FlashEvent")
		HX_STACK_LINE(371)
		::flixel::input::gamepad::FlxGamepad gamepad = this->getByID(FlashEvent->device);		HX_STACK_VAR(gamepad,"gamepad");
		HX_STACK_LINE(372)
		gamepad->hat->set_x((  (((::Math_obj::abs(FlashEvent->x) < gamepad->deadZone))) ? Float((int)0) : Float(FlashEvent->x) ));
		HX_STACK_LINE(373)
		gamepad->hat->set_y((  (((::Math_obj::abs(FlashEvent->y) < gamepad->deadZone))) ? Float((int)0) : Float(FlashEvent->y) ));
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC1(FlxGamepadManager_obj,handleHatMove,(void))

Void FlxGamepadManager_obj::update( ){
{
		HX_STACK_FRAME("flixel.input.gamepad.FlxGamepadManager","update",0x32fe94dc,"flixel.input.gamepad.FlxGamepadManager.update","flixel/input/gamepad/FlxGamepadManager.hx",382,0xccfee0a6)
		HX_STACK_THIS(this)
		HX_STACK_LINE(382)
		for(::cpp::FastIterator_obj< ::flixel::input::gamepad::FlxGamepad > *__it = ::cpp::CreateFastIterator< ::flixel::input::gamepad::FlxGamepad >(this->_gamepads->iterator());  __it->hasNext(); ){
			::flixel::input::gamepad::FlxGamepad gamepad = __it->next();
			gamepad->update();
		}
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC0(FlxGamepadManager_obj,update,(void))

Void FlxGamepadManager_obj::onFocus( ){
{
		HX_STACK_FRAME("flixel.input.gamepad.FlxGamepadManager","onFocus",0x68bae806,"flixel.input.gamepad.FlxGamepadManager.onFocus","flixel/input/gamepad/FlxGamepadManager.hx",388,0xccfee0a6)
		HX_STACK_THIS(this)
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC0(FlxGamepadManager_obj,onFocus,(void))

Void FlxGamepadManager_obj::onFocusLost( ){
{
		HX_STACK_FRAME("flixel.input.gamepad.FlxGamepadManager","onFocusLost",0xeb47390a,"flixel.input.gamepad.FlxGamepadManager.onFocusLost","flixel/input/gamepad/FlxGamepadManager.hx",392,0xccfee0a6)
		HX_STACK_THIS(this)
		HX_STACK_LINE(392)
		this->reset();
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC0(FlxGamepadManager_obj,onFocusLost,(void))

int FlxGamepadManager_obj::get_numActiveGamepads( ){
	HX_STACK_FRAME("flixel.input.gamepad.FlxGamepadManager","get_numActiveGamepads",0x4cfd1ae2,"flixel.input.gamepad.FlxGamepadManager.get_numActiveGamepads","flixel/input/gamepad/FlxGamepadManager.hx",396,0xccfee0a6)
	HX_STACK_THIS(this)
	HX_STACK_LINE(397)
	int count = (int)0;		HX_STACK_VAR(count,"count");
	HX_STACK_LINE(399)
	for(::cpp::FastIterator_obj< ::flixel::input::gamepad::FlxGamepad > *__it = ::cpp::CreateFastIterator< ::flixel::input::gamepad::FlxGamepad >(this->_gamepads->iterator());  __it->hasNext(); ){
		::flixel::input::gamepad::FlxGamepad gamepad = __it->next();
		(count)++;
	}
	HX_STACK_LINE(404)
	return count;
}


HX_DEFINE_DYNAMIC_FUNC0(FlxGamepadManager_obj,get_numActiveGamepads,return )

Float FlxGamepadManager_obj::set_globalDeadZone( Float DeadZone){
	HX_STACK_FRAME("flixel.input.gamepad.FlxGamepadManager","set_globalDeadZone",0x5e4d5a03,"flixel.input.gamepad.FlxGamepadManager.set_globalDeadZone","flixel/input/gamepad/FlxGamepadManager.hx",414,0xccfee0a6)
	HX_STACK_THIS(this)
	HX_STACK_ARG(DeadZone,"DeadZone")
	HX_STACK_LINE(415)
	this->globalDeadZone = DeadZone;
	HX_STACK_LINE(417)
	for(::cpp::FastIterator_obj< ::flixel::input::gamepad::FlxGamepad > *__it = ::cpp::CreateFastIterator< ::flixel::input::gamepad::FlxGamepad >(this->_gamepads->iterator());  __it->hasNext(); ){
		::flixel::input::gamepad::FlxGamepad gamepad = __it->next();
		gamepad->deadZone = DeadZone;
	}
	HX_STACK_LINE(422)
	return this->globalDeadZone;
}


HX_DEFINE_DYNAMIC_FUNC1(FlxGamepadManager_obj,set_globalDeadZone,return )


FlxGamepadManager_obj::FlxGamepadManager_obj()
{
}

void FlxGamepadManager_obj::__Mark(HX_MARK_PARAMS)
{
	HX_MARK_BEGIN_CLASS(FlxGamepadManager);
	HX_MARK_MEMBER_NAME(firstActive,"firstActive");
	HX_MARK_MEMBER_NAME(lastActive,"lastActive");
	HX_MARK_MEMBER_NAME(numActiveGamepads,"numActiveGamepads");
	HX_MARK_MEMBER_NAME(globalDeadZone,"globalDeadZone");
	HX_MARK_MEMBER_NAME(_gamepads,"_gamepads");
	HX_MARK_END_CLASS();
}

void FlxGamepadManager_obj::__Visit(HX_VISIT_PARAMS)
{
	HX_VISIT_MEMBER_NAME(firstActive,"firstActive");
	HX_VISIT_MEMBER_NAME(lastActive,"lastActive");
	HX_VISIT_MEMBER_NAME(numActiveGamepads,"numActiveGamepads");
	HX_VISIT_MEMBER_NAME(globalDeadZone,"globalDeadZone");
	HX_VISIT_MEMBER_NAME(_gamepads,"_gamepads");
}

Dynamic FlxGamepadManager_obj::__Field(const ::String &inName,bool inCallProp)
{
	switch(inName.length) {
	case 5:
		if (HX_FIELD_EQ(inName,"reset") ) { return reset_dyn(); }
		break;
	case 6:
		if (HX_FIELD_EQ(inName,"update") ) { return update_dyn(); }
		break;
	case 7:
		if (HX_FIELD_EQ(inName,"getByID") ) { return getByID_dyn(); }
		if (HX_FIELD_EQ(inName,"destroy") ) { return destroy_dyn(); }
		if (HX_FIELD_EQ(inName,"onFocus") ) { return onFocus_dyn(); }
		break;
	case 8:
		if (HX_FIELD_EQ(inName,"anyInput") ) { return anyInput_dyn(); }
		break;
	case 9:
		if (HX_FIELD_EQ(inName,"_gamepads") ) { return _gamepads; }
		if (HX_FIELD_EQ(inName,"anyButton") ) { return anyButton_dyn(); }
		break;
	case 10:
		if (HX_FIELD_EQ(inName,"lastActive") ) { return lastActive; }
		if (HX_FIELD_EQ(inName,"anyPressed") ) { return anyPressed_dyn(); }
		break;
	case 11:
		if (HX_FIELD_EQ(inName,"firstActive") ) { return firstActive; }
		if (HX_FIELD_EQ(inName,"onFocusLost") ) { return onFocusLost_dyn(); }
		break;
	case 13:
		if (HX_FIELD_EQ(inName,"handleHatMove") ) { return handleHatMove_dyn(); }
		break;
	case 14:
		if (HX_FIELD_EQ(inName,"globalDeadZone") ) { return globalDeadZone; }
		if (HX_FIELD_EQ(inName,"anyJustPressed") ) { return anyJustPressed_dyn(); }
		if (HX_FIELD_EQ(inName,"handleButtonUp") ) { return handleButtonUp_dyn(); }
		if (HX_FIELD_EQ(inName,"handleAxisMove") ) { return handleAxisMove_dyn(); }
		if (HX_FIELD_EQ(inName,"handleBallMove") ) { return handleBallMove_dyn(); }
		break;
	case 15:
		if (HX_FIELD_EQ(inName,"anyJustReleased") ) { return anyJustReleased_dyn(); }
		break;
	case 16:
		if (HX_FIELD_EQ(inName,"handleButtonDown") ) { return handleButtonDown_dyn(); }
		break;
	case 17:
		if (HX_FIELD_EQ(inName,"numActiveGamepads") ) { return inCallProp ? get_numActiveGamepads() : numActiveGamepads; }
		if (HX_FIELD_EQ(inName,"getActiveGamepads") ) { return getActiveGamepads_dyn(); }
		break;
	case 18:
		if (HX_FIELD_EQ(inName,"set_globalDeadZone") ) { return set_globalDeadZone_dyn(); }
		break;
	case 19:
		if (HX_FIELD_EQ(inName,"getActiveGamepadIDs") ) { return getActiveGamepadIDs_dyn(); }
		break;
	case 21:
		if (HX_FIELD_EQ(inName,"getFirstActiveGamepad") ) { return getFirstActiveGamepad_dyn(); }
		if (HX_FIELD_EQ(inName,"get_numActiveGamepads") ) { return get_numActiveGamepads_dyn(); }
		break;
	case 23:
		if (HX_FIELD_EQ(inName,"getFirstActiveGamepadID") ) { return getFirstActiveGamepadID_dyn(); }
	}
	return super::__Field(inName,inCallProp);
}

Dynamic FlxGamepadManager_obj::__SetField(const ::String &inName,const Dynamic &inValue,bool inCallProp)
{
	switch(inName.length) {
	case 9:
		if (HX_FIELD_EQ(inName,"_gamepads") ) { _gamepads=inValue.Cast< ::haxe::ds::IntMap >(); return inValue; }
		break;
	case 10:
		if (HX_FIELD_EQ(inName,"lastActive") ) { lastActive=inValue.Cast< ::flixel::input::gamepad::FlxGamepad >(); return inValue; }
		break;
	case 11:
		if (HX_FIELD_EQ(inName,"firstActive") ) { firstActive=inValue.Cast< ::flixel::input::gamepad::FlxGamepad >(); return inValue; }
		break;
	case 14:
		if (HX_FIELD_EQ(inName,"globalDeadZone") ) { if (inCallProp) return set_globalDeadZone(inValue);globalDeadZone=inValue.Cast< Float >(); return inValue; }
		break;
	case 17:
		if (HX_FIELD_EQ(inName,"numActiveGamepads") ) { numActiveGamepads=inValue.Cast< int >(); return inValue; }
	}
	return super::__SetField(inName,inValue,inCallProp);
}

void FlxGamepadManager_obj::__GetFields(Array< ::String> &outFields)
{
	outFields->push(HX_CSTRING("firstActive"));
	outFields->push(HX_CSTRING("lastActive"));
	outFields->push(HX_CSTRING("numActiveGamepads"));
	outFields->push(HX_CSTRING("globalDeadZone"));
	outFields->push(HX_CSTRING("_gamepads"));
	super::__GetFields(outFields);
};

static ::String sStaticFields[] = {
	String(null()) };

#if HXCPP_SCRIPTABLE
static hx::StorageInfo sMemberStorageInfo[] = {
	{hx::fsObject /*::flixel::input::gamepad::FlxGamepad*/ ,(int)offsetof(FlxGamepadManager_obj,firstActive),HX_CSTRING("firstActive")},
	{hx::fsObject /*::flixel::input::gamepad::FlxGamepad*/ ,(int)offsetof(FlxGamepadManager_obj,lastActive),HX_CSTRING("lastActive")},
	{hx::fsInt,(int)offsetof(FlxGamepadManager_obj,numActiveGamepads),HX_CSTRING("numActiveGamepads")},
	{hx::fsFloat,(int)offsetof(FlxGamepadManager_obj,globalDeadZone),HX_CSTRING("globalDeadZone")},
	{hx::fsObject /*::haxe::ds::IntMap*/ ,(int)offsetof(FlxGamepadManager_obj,_gamepads),HX_CSTRING("_gamepads")},
	{ hx::fsUnknown, 0, null()}
};
#endif

static ::String sMemberFields[] = {
	HX_CSTRING("firstActive"),
	HX_CSTRING("lastActive"),
	HX_CSTRING("numActiveGamepads"),
	HX_CSTRING("globalDeadZone"),
	HX_CSTRING("_gamepads"),
	HX_CSTRING("getByID"),
	HX_CSTRING("getActiveGamepadIDs"),
	HX_CSTRING("getActiveGamepads"),
	HX_CSTRING("getFirstActiveGamepadID"),
	HX_CSTRING("getFirstActiveGamepad"),
	HX_CSTRING("anyButton"),
	HX_CSTRING("anyInput"),
	HX_CSTRING("anyPressed"),
	HX_CSTRING("anyJustPressed"),
	HX_CSTRING("anyJustReleased"),
	HX_CSTRING("destroy"),
	HX_CSTRING("reset"),
	HX_CSTRING("handleButtonDown"),
	HX_CSTRING("handleButtonUp"),
	HX_CSTRING("handleAxisMove"),
	HX_CSTRING("handleBallMove"),
	HX_CSTRING("handleHatMove"),
	HX_CSTRING("update"),
	HX_CSTRING("onFocus"),
	HX_CSTRING("onFocusLost"),
	HX_CSTRING("get_numActiveGamepads"),
	HX_CSTRING("set_globalDeadZone"),
	String(null()) };

static void sMarkStatics(HX_MARK_PARAMS) {
	HX_MARK_MEMBER_NAME(FlxGamepadManager_obj::__mClass,"__mClass");
};

#ifdef HXCPP_VISIT_ALLOCS
static void sVisitStatics(HX_VISIT_PARAMS) {
	HX_VISIT_MEMBER_NAME(FlxGamepadManager_obj::__mClass,"__mClass");
};

#endif

Class FlxGamepadManager_obj::__mClass;

void FlxGamepadManager_obj::__register()
{
	hx::Static(__mClass) = hx::RegisterClass(HX_CSTRING("flixel.input.gamepad.FlxGamepadManager"), hx::TCanCast< FlxGamepadManager_obj> ,sStaticFields,sMemberFields,
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

void FlxGamepadManager_obj::__boot()
{
}

} // end namespace flixel
} // end namespace input
} // end namespace gamepad
