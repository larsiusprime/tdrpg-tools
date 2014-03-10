#include <hxcpp.h>

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
#ifndef INCLUDED_flixel_FlxG
#include <flixel/FlxG.h>
#endif
#ifndef INCLUDED_flixel_FlxGame
#include <flixel/FlxGame.h>
#endif
#ifndef INCLUDED_flixel_system_debug_FlxDebugger
#include <flixel/system/debug/FlxDebugger.h>
#endif
#ifndef INCLUDED_flixel_system_debug_Watch
#include <flixel/system/debug/Watch.h>
#endif
#ifndef INCLUDED_flixel_system_debug_Window
#include <flixel/system/debug/Window.h>
#endif
#ifndef INCLUDED_flixel_system_frontEnds_WatchFrontEnd
#include <flixel/system/frontEnds/WatchFrontEnd.h>
#endif
namespace flixel{
namespace system{
namespace frontEnds{

Void WatchFrontEnd_obj::__construct()
{
HX_STACK_FRAME("flixel.system.frontEnds.WatchFrontEnd","new",0xbd21d019,"flixel.system.frontEnds.WatchFrontEnd.new","flixel/system/frontEnds/WatchFrontEnd.hx",88,0xd7ade198)
{
}
;
	return null();
}

//WatchFrontEnd_obj::~WatchFrontEnd_obj() { }

Dynamic WatchFrontEnd_obj::__CreateEmpty() { return  new WatchFrontEnd_obj; }
hx::ObjectPtr< WatchFrontEnd_obj > WatchFrontEnd_obj::__new()
{  hx::ObjectPtr< WatchFrontEnd_obj > result = new WatchFrontEnd_obj();
	result->__construct();
	return result;}

Dynamic WatchFrontEnd_obj::__Create(hx::DynamicArray inArgs)
{  hx::ObjectPtr< WatchFrontEnd_obj > result = new WatchFrontEnd_obj();
	result->__construct();
	return result;}

Void WatchFrontEnd_obj::add( Dynamic AnyObject,::String VariableName,::String DisplayName){
{
		HX_STACK_FRAME("flixel.system.frontEnds.WatchFrontEnd","add",0xbd17f1da,"flixel.system.frontEnds.WatchFrontEnd.add","flixel/system/frontEnds/WatchFrontEnd.hx",18,0xd7ade198)
		HX_STACK_THIS(this)
		HX_STACK_ARG(AnyObject,"AnyObject")
		HX_STACK_ARG(VariableName,"VariableName")
		HX_STACK_ARG(DisplayName,"DisplayName")
		HX_STACK_LINE(18)
		::flixel::FlxG_obj::game->debugger->watch->add(AnyObject,VariableName,DisplayName);
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC3(WatchFrontEnd_obj,add,(void))

Void WatchFrontEnd_obj::remove( Dynamic AnyObject,::String VariableName){
{
		HX_STACK_FRAME("flixel.system.frontEnds.WatchFrontEnd","remove",0x8d8c762b,"flixel.system.frontEnds.WatchFrontEnd.remove","flixel/system/frontEnds/WatchFrontEnd.hx",32,0xd7ade198)
		HX_STACK_THIS(this)
		HX_STACK_ARG(AnyObject,"AnyObject")
		HX_STACK_ARG(VariableName,"VariableName")
		HX_STACK_LINE(32)
		::flixel::FlxG_obj::game->debugger->watch->remove(AnyObject,VariableName,null());
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC2(WatchFrontEnd_obj,remove,(void))

Void WatchFrontEnd_obj::addQuick( ::String Name,Dynamic NewValue){
{
		HX_STACK_FRAME("flixel.system.frontEnds.WatchFrontEnd","addQuick",0x8c660eb3,"flixel.system.frontEnds.WatchFrontEnd.addQuick","flixel/system/frontEnds/WatchFrontEnd.hx",47,0xd7ade198)
		HX_STACK_THIS(this)
		HX_STACK_ARG(Name,"Name")
		HX_STACK_ARG(NewValue,"NewValue")
		HX_STACK_LINE(47)
		::flixel::FlxG_obj::game->debugger->watch->updateQuickWatch(Name,NewValue);
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC2(WatchFrontEnd_obj,addQuick,(void))

Void WatchFrontEnd_obj::removeQuick( ::String Name){
{
		HX_STACK_FRAME("flixel.system.frontEnds.WatchFrontEnd","removeQuick",0x15fb44c2,"flixel.system.frontEnds.WatchFrontEnd.removeQuick","flixel/system/frontEnds/WatchFrontEnd.hx",59,0xd7ade198)
		HX_STACK_THIS(this)
		HX_STACK_ARG(Name,"Name")
		HX_STACK_LINE(59)
		::flixel::FlxG_obj::game->debugger->watch->remove(null(),null(),Name);
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC1(WatchFrontEnd_obj,removeQuick,(void))

Void WatchFrontEnd_obj::addMouse( ){
{
		HX_STACK_FRAME("flixel.system.frontEnds.WatchFrontEnd","addMouse",0x3add9deb,"flixel.system.frontEnds.WatchFrontEnd.addMouse","flixel/system/frontEnds/WatchFrontEnd.hx",70,0xd7ade198)
		HX_STACK_THIS(this)
		HX_STACK_LINE(70)
		::flixel::FlxG_obj::game->debugger->watch->add(hx::ClassOf< ::flixel::FlxG >(),HX_CSTRING("mouse"),HX_CSTRING("Mouse Position"));
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC0(WatchFrontEnd_obj,addMouse,(void))

Void WatchFrontEnd_obj::removeMouse( ){
{
		HX_STACK_FRAME("flixel.system.frontEnds.WatchFrontEnd","removeMouse",0xc472d3fa,"flixel.system.frontEnds.WatchFrontEnd.removeMouse","flixel/system/frontEnds/WatchFrontEnd.hx",80,0xd7ade198)
		HX_STACK_THIS(this)
		HX_STACK_LINE(80)
		::flixel::FlxG_obj::game->debugger->watch->remove(hx::ClassOf< ::flixel::FlxG >(),HX_CSTRING("mouse"),null());
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC0(WatchFrontEnd_obj,removeMouse,(void))


WatchFrontEnd_obj::WatchFrontEnd_obj()
{
}

Dynamic WatchFrontEnd_obj::__Field(const ::String &inName,bool inCallProp)
{
	switch(inName.length) {
	case 3:
		if (HX_FIELD_EQ(inName,"add") ) { return add_dyn(); }
		break;
	case 6:
		if (HX_FIELD_EQ(inName,"remove") ) { return remove_dyn(); }
		break;
	case 8:
		if (HX_FIELD_EQ(inName,"addQuick") ) { return addQuick_dyn(); }
		if (HX_FIELD_EQ(inName,"addMouse") ) { return addMouse_dyn(); }
		break;
	case 11:
		if (HX_FIELD_EQ(inName,"removeQuick") ) { return removeQuick_dyn(); }
		if (HX_FIELD_EQ(inName,"removeMouse") ) { return removeMouse_dyn(); }
	}
	return super::__Field(inName,inCallProp);
}

Dynamic WatchFrontEnd_obj::__SetField(const ::String &inName,const Dynamic &inValue,bool inCallProp)
{
	return super::__SetField(inName,inValue,inCallProp);
}

void WatchFrontEnd_obj::__GetFields(Array< ::String> &outFields)
{
	super::__GetFields(outFields);
};

static ::String sStaticFields[] = {
	String(null()) };

#if HXCPP_SCRIPTABLE
static hx::StorageInfo *sMemberStorageInfo = 0;
#endif

static ::String sMemberFields[] = {
	HX_CSTRING("add"),
	HX_CSTRING("remove"),
	HX_CSTRING("addQuick"),
	HX_CSTRING("removeQuick"),
	HX_CSTRING("addMouse"),
	HX_CSTRING("removeMouse"),
	String(null()) };

static void sMarkStatics(HX_MARK_PARAMS) {
	HX_MARK_MEMBER_NAME(WatchFrontEnd_obj::__mClass,"__mClass");
};

#ifdef HXCPP_VISIT_ALLOCS
static void sVisitStatics(HX_VISIT_PARAMS) {
	HX_VISIT_MEMBER_NAME(WatchFrontEnd_obj::__mClass,"__mClass");
};

#endif

Class WatchFrontEnd_obj::__mClass;

void WatchFrontEnd_obj::__register()
{
	hx::Static(__mClass) = hx::RegisterClass(HX_CSTRING("flixel.system.frontEnds.WatchFrontEnd"), hx::TCanCast< WatchFrontEnd_obj> ,sStaticFields,sMemberFields,
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

void WatchFrontEnd_obj::__boot()
{
}

} // end namespace flixel
} // end namespace system
} // end namespace frontEnds
