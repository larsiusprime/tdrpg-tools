#include <hxcpp.h>

#ifndef INCLUDED_flash_display_DisplayObject
#include <flash/display/DisplayObject.h>
#endif
#ifndef INCLUDED_flash_display_IBitmapDrawable
#include <flash/display/IBitmapDrawable.h>
#endif
#ifndef INCLUDED_flash_display_InteractiveObject
#include <flash/display/InteractiveObject.h>
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
#ifndef INCLUDED_flash_text_TextFormat
#include <flash/text/TextFormat.h>
#endif
#ifndef INCLUDED_flixel_system_FlxAssets
#include <flixel/system/FlxAssets.h>
#endif
#ifndef INCLUDED_flixel_system_debug_DebuggerUtil
#include <flixel/system/debug/DebuggerUtil.h>
#endif
namespace flixel{
namespace system{
namespace debug{

Void DebuggerUtil_obj::__construct()
{
	return null();
}

//DebuggerUtil_obj::~DebuggerUtil_obj() { }

Dynamic DebuggerUtil_obj::__CreateEmpty() { return  new DebuggerUtil_obj; }
hx::ObjectPtr< DebuggerUtil_obj > DebuggerUtil_obj::__new()
{  hx::ObjectPtr< DebuggerUtil_obj > result = new DebuggerUtil_obj();
	result->__construct();
	return result;}

Dynamic DebuggerUtil_obj::__Create(hx::DynamicArray inArgs)
{  hx::ObjectPtr< DebuggerUtil_obj > result = new DebuggerUtil_obj();
	result->__construct();
	return result;}

::flash::text::TextField DebuggerUtil_obj::createTextField( hx::Null< Float >  __o_X,hx::Null< Float >  __o_Y,hx::Null< int >  __o_Color,hx::Null< int >  __o_Size){
Float X = __o_X.Default(0);
Float Y = __o_Y.Default(0);
int Color = __o_Color.Default(-1);
int Size = __o_Size.Default(12);
	HX_STACK_FRAME("flixel.system.debug.DebuggerUtil","createTextField",0x34b9b52e,"flixel.system.debug.DebuggerUtil.createTextField","flixel/system/debug/DebuggerUtil.hx",27,0x13434d32)
	HX_STACK_ARG(X,"X")
	HX_STACK_ARG(Y,"Y")
	HX_STACK_ARG(Color,"Color")
	HX_STACK_ARG(Size,"Size")
{
		HX_STACK_LINE(28)
		::flash::text::TextField tf = ::flash::text::TextField_obj::__new();		HX_STACK_VAR(tf,"tf");
		HX_STACK_LINE(29)
		tf->set_x(X);
		HX_STACK_LINE(30)
		tf->set_y(Y);
		HX_STACK_LINE(31)
		tf->set_multiline(false);
		HX_STACK_LINE(32)
		tf->set_wordWrap(false);
		HX_STACK_LINE(33)
		tf->set_embedFonts(true);
		HX_STACK_LINE(34)
		tf->set_selectable(false);
		HX_STACK_LINE(39)
		tf->set_defaultTextFormat(::flash::text::TextFormat_obj::__new(::flixel::system::FlxAssets_obj::FONT_DEBUGGER,Size,(int((int((int(((int((int(Color) >> int((int)16))) & int((int)255)))) << int((int)16))) | int((int(((int((int(Color) >> int((int)8))) & int((int)255)))) << int((int)8))))) | int((int(Color) & int((int)255)))),null(),null(),null(),null(),null(),null(),null(),null(),null(),null()));
		struct _Function_1_1{
			inline static Float Block( int &Color){
				HX_STACK_FRAME("*","closure",0x5bdab937,"*.closure","flixel/system/debug/DebuggerUtil.hx",40,0x13434d32)
				{
					HX_STACK_LINE(40)
					int f = (int((int(Color) >> int((int)24))) & int((int)255));		HX_STACK_VAR(f,"f");
					HX_STACK_LINE(40)
					return (Float(f) / Float((int)255));
				}
				return null();
			}
		};
		HX_STACK_LINE(40)
		tf->set_alpha(_Function_1_1::Block(Color));
		HX_STACK_LINE(41)
		return tf;
	}
}


STATIC_HX_DEFINE_DYNAMIC_FUNC4(DebuggerUtil_obj,createTextField,return )


DebuggerUtil_obj::DebuggerUtil_obj()
{
}

Dynamic DebuggerUtil_obj::__Field(const ::String &inName,bool inCallProp)
{
	switch(inName.length) {
	case 15:
		if (HX_FIELD_EQ(inName,"createTextField") ) { return createTextField_dyn(); }
	}
	return super::__Field(inName,inCallProp);
}

Dynamic DebuggerUtil_obj::__SetField(const ::String &inName,const Dynamic &inValue,bool inCallProp)
{
	return super::__SetField(inName,inValue,inCallProp);
}

void DebuggerUtil_obj::__GetFields(Array< ::String> &outFields)
{
	super::__GetFields(outFields);
};

static ::String sStaticFields[] = {
	HX_CSTRING("createTextField"),
	String(null()) };

#if HXCPP_SCRIPTABLE
static hx::StorageInfo *sMemberStorageInfo = 0;
#endif

static ::String sMemberFields[] = {
	String(null()) };

static void sMarkStatics(HX_MARK_PARAMS) {
	HX_MARK_MEMBER_NAME(DebuggerUtil_obj::__mClass,"__mClass");
};

#ifdef HXCPP_VISIT_ALLOCS
static void sVisitStatics(HX_VISIT_PARAMS) {
	HX_VISIT_MEMBER_NAME(DebuggerUtil_obj::__mClass,"__mClass");
};

#endif

Class DebuggerUtil_obj::__mClass;

void DebuggerUtil_obj::__register()
{
	hx::Static(__mClass) = hx::RegisterClass(HX_CSTRING("flixel.system.debug.DebuggerUtil"), hx::TCanCast< DebuggerUtil_obj> ,sStaticFields,sMemberFields,
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

void DebuggerUtil_obj::__boot()
{
}

} // end namespace flixel
} // end namespace system
} // end namespace debug
