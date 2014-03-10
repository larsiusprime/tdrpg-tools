#include <hxcpp.h>

#ifndef INCLUDED_GameClass
#include <GameClass.h>
#endif
#ifndef INCLUDED_PlayState
#include <PlayState.h>
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
#ifndef INCLUDED_flash_events_EventDispatcher
#include <flash/events/EventDispatcher.h>
#endif
#ifndef INCLUDED_flash_events_IEventDispatcher
#include <flash/events/IEventDispatcher.h>
#endif
#ifndef INCLUDED_flixel_FlxBasic
#include <flixel/FlxBasic.h>
#endif
#ifndef INCLUDED_flixel_FlxGame
#include <flixel/FlxGame.h>
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
#ifndef INCLUDED_hxMath
#include <hxMath.h>
#endif

Void GameClass_obj::__construct()
{
HX_STACK_FRAME("GameClass","new",0x66f3c2b8,"GameClass.new","GameClass.hx",7,0xf86cfbb8)
{
	HX_STACK_LINE(15)
	this->startFullscreen = false;
	HX_STACK_LINE(14)
	this->skipSplash = false;
	HX_STACK_LINE(13)
	this->framerate = (int)60;
	HX_STACK_LINE(12)
	this->zoom = (int)-1;
	HX_STACK_LINE(11)
	this->initialState = hx::ClassOf< ::PlayState >();
	HX_STACK_LINE(10)
	this->gameHeight = (int)480;
	HX_STACK_LINE(9)
	this->gameWidth = (int)640;
	HX_STACK_LINE(22)
	int stageWidth = ::flash::Lib_obj::get_current()->get_stage()->get_stageWidth();		HX_STACK_VAR(stageWidth,"stageWidth");
	HX_STACK_LINE(23)
	int stageHeight = ::flash::Lib_obj::get_current()->get_stage()->get_stageHeight();		HX_STACK_VAR(stageHeight,"stageHeight");
	HX_STACK_LINE(25)
	if (((this->zoom == (int)-1))){
		HX_STACK_LINE(27)
		Float ratioX = (Float(stageWidth) / Float(this->gameWidth));		HX_STACK_VAR(ratioX,"ratioX");
		HX_STACK_LINE(28)
		Float ratioY = (Float(stageHeight) / Float(this->gameHeight));		HX_STACK_VAR(ratioY,"ratioY");
		HX_STACK_LINE(29)
		this->zoom = ::Math_obj::min(ratioX,ratioY);
		HX_STACK_LINE(30)
		this->gameWidth = ::Math_obj::ceil((Float(stageWidth) / Float(this->zoom)));
		HX_STACK_LINE(31)
		this->gameHeight = ::Math_obj::ceil((Float(stageHeight) / Float(this->zoom)));
	}
	HX_STACK_LINE(34)
	super::__construct(this->gameWidth,this->gameHeight,this->initialState,this->zoom,this->framerate,this->framerate,this->skipSplash,this->startFullscreen);
}
;
	return null();
}

//GameClass_obj::~GameClass_obj() { }

Dynamic GameClass_obj::__CreateEmpty() { return  new GameClass_obj; }
hx::ObjectPtr< GameClass_obj > GameClass_obj::__new()
{  hx::ObjectPtr< GameClass_obj > result = new GameClass_obj();
	result->__construct();
	return result;}

Dynamic GameClass_obj::__Create(hx::DynamicArray inArgs)
{  hx::ObjectPtr< GameClass_obj > result = new GameClass_obj();
	result->__construct();
	return result;}


GameClass_obj::GameClass_obj()
{
}

void GameClass_obj::__Mark(HX_MARK_PARAMS)
{
	HX_MARK_BEGIN_CLASS(GameClass);
	HX_MARK_MEMBER_NAME(gameWidth,"gameWidth");
	HX_MARK_MEMBER_NAME(gameHeight,"gameHeight");
	HX_MARK_MEMBER_NAME(initialState,"initialState");
	HX_MARK_MEMBER_NAME(zoom,"zoom");
	HX_MARK_MEMBER_NAME(framerate,"framerate");
	HX_MARK_MEMBER_NAME(skipSplash,"skipSplash");
	HX_MARK_MEMBER_NAME(startFullscreen,"startFullscreen");
	::flixel::FlxGame_obj::__Mark(HX_MARK_ARG);
	HX_MARK_END_CLASS();
}

void GameClass_obj::__Visit(HX_VISIT_PARAMS)
{
	HX_VISIT_MEMBER_NAME(gameWidth,"gameWidth");
	HX_VISIT_MEMBER_NAME(gameHeight,"gameHeight");
	HX_VISIT_MEMBER_NAME(initialState,"initialState");
	HX_VISIT_MEMBER_NAME(zoom,"zoom");
	HX_VISIT_MEMBER_NAME(framerate,"framerate");
	HX_VISIT_MEMBER_NAME(skipSplash,"skipSplash");
	HX_VISIT_MEMBER_NAME(startFullscreen,"startFullscreen");
	::flixel::FlxGame_obj::__Visit(HX_VISIT_ARG);
}

Dynamic GameClass_obj::__Field(const ::String &inName,bool inCallProp)
{
	switch(inName.length) {
	case 4:
		if (HX_FIELD_EQ(inName,"zoom") ) { return zoom; }
		break;
	case 9:
		if (HX_FIELD_EQ(inName,"gameWidth") ) { return gameWidth; }
		if (HX_FIELD_EQ(inName,"framerate") ) { return framerate; }
		break;
	case 10:
		if (HX_FIELD_EQ(inName,"gameHeight") ) { return gameHeight; }
		if (HX_FIELD_EQ(inName,"skipSplash") ) { return skipSplash; }
		break;
	case 12:
		if (HX_FIELD_EQ(inName,"initialState") ) { return initialState; }
		break;
	case 15:
		if (HX_FIELD_EQ(inName,"startFullscreen") ) { return startFullscreen; }
	}
	return super::__Field(inName,inCallProp);
}

Dynamic GameClass_obj::__SetField(const ::String &inName,const Dynamic &inValue,bool inCallProp)
{
	switch(inName.length) {
	case 4:
		if (HX_FIELD_EQ(inName,"zoom") ) { zoom=inValue.Cast< Float >(); return inValue; }
		break;
	case 9:
		if (HX_FIELD_EQ(inName,"gameWidth") ) { gameWidth=inValue.Cast< int >(); return inValue; }
		if (HX_FIELD_EQ(inName,"framerate") ) { framerate=inValue.Cast< int >(); return inValue; }
		break;
	case 10:
		if (HX_FIELD_EQ(inName,"gameHeight") ) { gameHeight=inValue.Cast< int >(); return inValue; }
		if (HX_FIELD_EQ(inName,"skipSplash") ) { skipSplash=inValue.Cast< bool >(); return inValue; }
		break;
	case 12:
		if (HX_FIELD_EQ(inName,"initialState") ) { initialState=inValue.Cast< ::Class >(); return inValue; }
		break;
	case 15:
		if (HX_FIELD_EQ(inName,"startFullscreen") ) { startFullscreen=inValue.Cast< bool >(); return inValue; }
	}
	return super::__SetField(inName,inValue,inCallProp);
}

void GameClass_obj::__GetFields(Array< ::String> &outFields)
{
	outFields->push(HX_CSTRING("gameWidth"));
	outFields->push(HX_CSTRING("gameHeight"));
	outFields->push(HX_CSTRING("initialState"));
	outFields->push(HX_CSTRING("zoom"));
	outFields->push(HX_CSTRING("framerate"));
	outFields->push(HX_CSTRING("skipSplash"));
	outFields->push(HX_CSTRING("startFullscreen"));
	super::__GetFields(outFields);
};

static ::String sStaticFields[] = {
	String(null()) };

#if HXCPP_SCRIPTABLE
static hx::StorageInfo sMemberStorageInfo[] = {
	{hx::fsInt,(int)offsetof(GameClass_obj,gameWidth),HX_CSTRING("gameWidth")},
	{hx::fsInt,(int)offsetof(GameClass_obj,gameHeight),HX_CSTRING("gameHeight")},
	{hx::fsObject /*::Class*/ ,(int)offsetof(GameClass_obj,initialState),HX_CSTRING("initialState")},
	{hx::fsFloat,(int)offsetof(GameClass_obj,zoom),HX_CSTRING("zoom")},
	{hx::fsInt,(int)offsetof(GameClass_obj,framerate),HX_CSTRING("framerate")},
	{hx::fsBool,(int)offsetof(GameClass_obj,skipSplash),HX_CSTRING("skipSplash")},
	{hx::fsBool,(int)offsetof(GameClass_obj,startFullscreen),HX_CSTRING("startFullscreen")},
	{ hx::fsUnknown, 0, null()}
};
#endif

static ::String sMemberFields[] = {
	HX_CSTRING("gameWidth"),
	HX_CSTRING("gameHeight"),
	HX_CSTRING("initialState"),
	HX_CSTRING("zoom"),
	HX_CSTRING("framerate"),
	HX_CSTRING("skipSplash"),
	HX_CSTRING("startFullscreen"),
	String(null()) };

static void sMarkStatics(HX_MARK_PARAMS) {
	HX_MARK_MEMBER_NAME(GameClass_obj::__mClass,"__mClass");
};

#ifdef HXCPP_VISIT_ALLOCS
static void sVisitStatics(HX_VISIT_PARAMS) {
	HX_VISIT_MEMBER_NAME(GameClass_obj::__mClass,"__mClass");
};

#endif

Class GameClass_obj::__mClass;

void GameClass_obj::__register()
{
	hx::Static(__mClass) = hx::RegisterClass(HX_CSTRING("GameClass"), hx::TCanCast< GameClass_obj> ,sStaticFields,sMemberFields,
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

void GameClass_obj::__boot()
{
}

