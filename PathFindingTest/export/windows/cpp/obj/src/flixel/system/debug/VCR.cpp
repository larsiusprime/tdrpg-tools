#include <hxcpp.h>

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
#ifndef INCLUDED_flash_display_Sprite
#include <flash/display/Sprite.h>
#endif
#ifndef INCLUDED_flash_events_EventDispatcher
#include <flash/events/EventDispatcher.h>
#endif
#ifndef INCLUDED_flash_events_IEventDispatcher
#include <flash/events/IEventDispatcher.h>
#endif
#ifndef INCLUDED_flash_text_TextField
#include <flash/text/TextField.h>
#endif
#ifndef INCLUDED_flixel_FlxG
#include <flixel/FlxG.h>
#endif
#ifndef INCLUDED_flixel_interfaces_IFlxDestroyable
#include <flixel/interfaces/IFlxDestroyable.h>
#endif
#ifndef INCLUDED_flixel_system_debug_ButtonAlignment
#include <flixel/system/debug/ButtonAlignment.h>
#endif
#ifndef INCLUDED_flixel_system_debug_FlxDebugger
#include <flixel/system/debug/FlxDebugger.h>
#endif
#ifndef INCLUDED_flixel_system_debug_VCR
#include <flixel/system/debug/VCR.h>
#endif
#ifndef INCLUDED_flixel_system_debug__VCR_GraphicPause
#include <flixel/system/debug/_VCR/GraphicPause.h>
#endif
#ifndef INCLUDED_flixel_system_debug__VCR_GraphicPlay
#include <flixel/system/debug/_VCR/GraphicPlay.h>
#endif
#ifndef INCLUDED_flixel_system_debug__VCR_GraphicRestart
#include <flixel/system/debug/_VCR/GraphicRestart.h>
#endif
#ifndef INCLUDED_flixel_system_debug__VCR_GraphicStep
#include <flixel/system/debug/_VCR/GraphicStep.h>
#endif
#ifndef INCLUDED_flixel_system_frontEnds_VCRFrontEnd
#include <flixel/system/frontEnds/VCRFrontEnd.h>
#endif
#ifndef INCLUDED_flixel_system_ui_FlxSystemButton
#include <flixel/system/ui/FlxSystemButton.h>
#endif
namespace flixel{
namespace system{
namespace debug{

Void VCR_obj::__construct(::flixel::system::debug::FlxDebugger Debugger)
{
HX_STACK_FRAME("flixel.system.debug.VCR","new",0x7584fc6f,"flixel.system.debug.VCR.new","flixel/system/debug/VCR.hx",26,0x4ecb3ec2)

HX_STACK_ARG(Debugger,"Debugger")
{
	HX_STACK_LINE(33)
	this->runtime = (int)0;
	HX_STACK_LINE(46)
	this->restartBtn = Debugger->addButton(::flixel::system::debug::ButtonAlignment_obj::MIDDLE,::flixel::system::debug::_VCR::GraphicRestart_obj::__new((int)0,(int)0,null(),null()),::flixel::FlxG_obj::resetState_dyn(),null(),null());
	HX_STACK_LINE(51)
	this->playbackToggleBtn = Debugger->addButton(::flixel::system::debug::ButtonAlignment_obj::MIDDLE,::flixel::system::debug::_VCR::GraphicPause_obj::__new((int)0,(int)0,null(),null()),::flixel::FlxG_obj::vcr->pause_dyn(),null(),null());
	HX_STACK_LINE(52)
	this->stepBtn = Debugger->addButton(::flixel::system::debug::ButtonAlignment_obj::MIDDLE,::flixel::system::debug::_VCR::GraphicStep_obj::__new((int)0,(int)0,null(),null()),this->onStep_dyn(),null(),null());
}
;
	return null();
}

//VCR_obj::~VCR_obj() { }

Dynamic VCR_obj::__CreateEmpty() { return  new VCR_obj; }
hx::ObjectPtr< VCR_obj > VCR_obj::__new(::flixel::system::debug::FlxDebugger Debugger)
{  hx::ObjectPtr< VCR_obj > result = new VCR_obj();
	result->__construct(Debugger);
	return result;}

Dynamic VCR_obj::__Create(hx::DynamicArray inArgs)
{  hx::ObjectPtr< VCR_obj > result = new VCR_obj();
	result->__construct(inArgs[0]);
	return result;}

Void VCR_obj::onPause( ){
{
		HX_STACK_FRAME("flixel.system.debug.VCR","onPause",0xf9cf54e6,"flixel.system.debug.VCR.onPause","flixel/system/debug/VCR.hx",132,0x4ecb3ec2)
		HX_STACK_THIS(this)
		HX_STACK_LINE(133)
		this->playbackToggleBtn->upHandler = ::flixel::FlxG_obj::vcr->resume_dyn();
		HX_STACK_LINE(134)
		this->playbackToggleBtn->changeIcon(::flixel::system::debug::_VCR::GraphicPlay_obj::__new((int)0,(int)0,null(),null()));
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC0(VCR_obj,onPause,(void))

Void VCR_obj::onResume( ){
{
		HX_STACK_FRAME("flixel.system.debug.VCR","onResume",0xb49b1dbd,"flixel.system.debug.VCR.onResume","flixel/system/debug/VCR.hx",142,0x4ecb3ec2)
		HX_STACK_THIS(this)
		HX_STACK_LINE(143)
		this->playbackToggleBtn->upHandler = ::flixel::FlxG_obj::vcr->pause_dyn();
		HX_STACK_LINE(144)
		this->playbackToggleBtn->changeIcon(::flixel::system::debug::_VCR::GraphicPause_obj::__new((int)0,(int)0,null(),null()));
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC0(VCR_obj,onResume,(void))

Void VCR_obj::onStep( ){
{
		HX_STACK_FRAME("flixel.system.debug.VCR","onStep",0x2da2775c,"flixel.system.debug.VCR.onStep","flixel/system/debug/VCR.hx",152,0x4ecb3ec2)
		HX_STACK_THIS(this)
		HX_STACK_LINE(153)
		if ((!(::flixel::FlxG_obj::vcr->paused))){
			HX_STACK_LINE(155)
			::flixel::FlxG_obj::vcr->pause();
		}
		HX_STACK_LINE(157)
		::flixel::FlxG_obj::vcr->stepRequested = true;
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC0(VCR_obj,onStep,(void))


VCR_obj::VCR_obj()
{
}

void VCR_obj::__Mark(HX_MARK_PARAMS)
{
	HX_MARK_BEGIN_CLASS(VCR);
	HX_MARK_MEMBER_NAME(runtimeDisplay,"runtimeDisplay");
	HX_MARK_MEMBER_NAME(runtime,"runtime");
	HX_MARK_MEMBER_NAME(playbackToggleBtn,"playbackToggleBtn");
	HX_MARK_MEMBER_NAME(stepBtn,"stepBtn");
	HX_MARK_MEMBER_NAME(restartBtn,"restartBtn");
	HX_MARK_MEMBER_NAME(recordBtn,"recordBtn");
	HX_MARK_MEMBER_NAME(openBtn,"openBtn");
	HX_MARK_END_CLASS();
}

void VCR_obj::__Visit(HX_VISIT_PARAMS)
{
	HX_VISIT_MEMBER_NAME(runtimeDisplay,"runtimeDisplay");
	HX_VISIT_MEMBER_NAME(runtime,"runtime");
	HX_VISIT_MEMBER_NAME(playbackToggleBtn,"playbackToggleBtn");
	HX_VISIT_MEMBER_NAME(stepBtn,"stepBtn");
	HX_VISIT_MEMBER_NAME(restartBtn,"restartBtn");
	HX_VISIT_MEMBER_NAME(recordBtn,"recordBtn");
	HX_VISIT_MEMBER_NAME(openBtn,"openBtn");
}

Dynamic VCR_obj::__Field(const ::String &inName,bool inCallProp)
{
	switch(inName.length) {
	case 6:
		if (HX_FIELD_EQ(inName,"onStep") ) { return onStep_dyn(); }
		break;
	case 7:
		if (HX_FIELD_EQ(inName,"runtime") ) { return runtime; }
		if (HX_FIELD_EQ(inName,"stepBtn") ) { return stepBtn; }
		if (HX_FIELD_EQ(inName,"openBtn") ) { return openBtn; }
		if (HX_FIELD_EQ(inName,"onPause") ) { return onPause_dyn(); }
		break;
	case 8:
		if (HX_FIELD_EQ(inName,"onResume") ) { return onResume_dyn(); }
		break;
	case 9:
		if (HX_FIELD_EQ(inName,"recordBtn") ) { return recordBtn; }
		break;
	case 10:
		if (HX_FIELD_EQ(inName,"restartBtn") ) { return restartBtn; }
		break;
	case 14:
		if (HX_FIELD_EQ(inName,"runtimeDisplay") ) { return runtimeDisplay; }
		break;
	case 17:
		if (HX_FIELD_EQ(inName,"playbackToggleBtn") ) { return playbackToggleBtn; }
	}
	return super::__Field(inName,inCallProp);
}

Dynamic VCR_obj::__SetField(const ::String &inName,const Dynamic &inValue,bool inCallProp)
{
	switch(inName.length) {
	case 7:
		if (HX_FIELD_EQ(inName,"runtime") ) { runtime=inValue.Cast< int >(); return inValue; }
		if (HX_FIELD_EQ(inName,"stepBtn") ) { stepBtn=inValue.Cast< ::flixel::system::ui::FlxSystemButton >(); return inValue; }
		if (HX_FIELD_EQ(inName,"openBtn") ) { openBtn=inValue.Cast< ::flixel::system::ui::FlxSystemButton >(); return inValue; }
		break;
	case 9:
		if (HX_FIELD_EQ(inName,"recordBtn") ) { recordBtn=inValue.Cast< ::flixel::system::ui::FlxSystemButton >(); return inValue; }
		break;
	case 10:
		if (HX_FIELD_EQ(inName,"restartBtn") ) { restartBtn=inValue.Cast< ::flixel::system::ui::FlxSystemButton >(); return inValue; }
		break;
	case 14:
		if (HX_FIELD_EQ(inName,"runtimeDisplay") ) { runtimeDisplay=inValue.Cast< ::flash::text::TextField >(); return inValue; }
		break;
	case 17:
		if (HX_FIELD_EQ(inName,"playbackToggleBtn") ) { playbackToggleBtn=inValue.Cast< ::flixel::system::ui::FlxSystemButton >(); return inValue; }
	}
	return super::__SetField(inName,inValue,inCallProp);
}

void VCR_obj::__GetFields(Array< ::String> &outFields)
{
	outFields->push(HX_CSTRING("runtimeDisplay"));
	outFields->push(HX_CSTRING("runtime"));
	outFields->push(HX_CSTRING("playbackToggleBtn"));
	outFields->push(HX_CSTRING("stepBtn"));
	outFields->push(HX_CSTRING("restartBtn"));
	outFields->push(HX_CSTRING("recordBtn"));
	outFields->push(HX_CSTRING("openBtn"));
	super::__GetFields(outFields);
};

static ::String sStaticFields[] = {
	String(null()) };

#if HXCPP_SCRIPTABLE
static hx::StorageInfo sMemberStorageInfo[] = {
	{hx::fsObject /*::flash::text::TextField*/ ,(int)offsetof(VCR_obj,runtimeDisplay),HX_CSTRING("runtimeDisplay")},
	{hx::fsInt,(int)offsetof(VCR_obj,runtime),HX_CSTRING("runtime")},
	{hx::fsObject /*::flixel::system::ui::FlxSystemButton*/ ,(int)offsetof(VCR_obj,playbackToggleBtn),HX_CSTRING("playbackToggleBtn")},
	{hx::fsObject /*::flixel::system::ui::FlxSystemButton*/ ,(int)offsetof(VCR_obj,stepBtn),HX_CSTRING("stepBtn")},
	{hx::fsObject /*::flixel::system::ui::FlxSystemButton*/ ,(int)offsetof(VCR_obj,restartBtn),HX_CSTRING("restartBtn")},
	{hx::fsObject /*::flixel::system::ui::FlxSystemButton*/ ,(int)offsetof(VCR_obj,recordBtn),HX_CSTRING("recordBtn")},
	{hx::fsObject /*::flixel::system::ui::FlxSystemButton*/ ,(int)offsetof(VCR_obj,openBtn),HX_CSTRING("openBtn")},
	{ hx::fsUnknown, 0, null()}
};
#endif

static ::String sMemberFields[] = {
	HX_CSTRING("runtimeDisplay"),
	HX_CSTRING("runtime"),
	HX_CSTRING("playbackToggleBtn"),
	HX_CSTRING("stepBtn"),
	HX_CSTRING("restartBtn"),
	HX_CSTRING("recordBtn"),
	HX_CSTRING("openBtn"),
	HX_CSTRING("onPause"),
	HX_CSTRING("onResume"),
	HX_CSTRING("onStep"),
	String(null()) };

static void sMarkStatics(HX_MARK_PARAMS) {
	HX_MARK_MEMBER_NAME(VCR_obj::__mClass,"__mClass");
};

#ifdef HXCPP_VISIT_ALLOCS
static void sVisitStatics(HX_VISIT_PARAMS) {
	HX_VISIT_MEMBER_NAME(VCR_obj::__mClass,"__mClass");
};

#endif

Class VCR_obj::__mClass;

void VCR_obj::__register()
{
	hx::Static(__mClass) = hx::RegisterClass(HX_CSTRING("flixel.system.debug.VCR"), hx::TCanCast< VCR_obj> ,sStaticFields,sMemberFields,
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

void VCR_obj::__boot()
{
}

} // end namespace flixel
} // end namespace system
} // end namespace debug
