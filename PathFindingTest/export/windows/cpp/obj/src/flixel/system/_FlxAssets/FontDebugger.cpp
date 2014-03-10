#include <hxcpp.h>

#ifndef INCLUDED_flash_text_Font
#include <flash/text/Font.h>
#endif
#ifndef INCLUDED_flash_text_FontStyle
#include <flash/text/FontStyle.h>
#endif
#ifndef INCLUDED_flash_text_FontType
#include <flash/text/FontType.h>
#endif
#ifndef INCLUDED_flixel_system__FlxAssets_FontDebugger
#include <flixel/system/_FlxAssets/FontDebugger.h>
#endif
namespace flixel{
namespace system{
namespace _FlxAssets{

Void FontDebugger_obj::__construct(::String __o_filename,::flash::text::FontStyle style,::flash::text::FontType type)
{
HX_STACK_FRAME("flixel.system._FlxAssets.FontDebugger","new",0xc644602d,"flixel.system._FlxAssets.FontDebugger.new","flixel/system/FlxAssets.hx",16,0xd3ac1356)

HX_STACK_ARG(__o_filename,"filename")

HX_STACK_ARG(style,"style")

HX_STACK_ARG(type,"type")
::String filename = __o_filename.Default(HX_CSTRING(""));
{
	HX_STACK_LINE(16)
	super::__construct(filename,style,type);
}
;
	return null();
}

//FontDebugger_obj::~FontDebugger_obj() { }

Dynamic FontDebugger_obj::__CreateEmpty() { return  new FontDebugger_obj; }
hx::ObjectPtr< FontDebugger_obj > FontDebugger_obj::__new(::String __o_filename,::flash::text::FontStyle style,::flash::text::FontType type)
{  hx::ObjectPtr< FontDebugger_obj > result = new FontDebugger_obj();
	result->__construct(__o_filename,style,type);
	return result;}

Dynamic FontDebugger_obj::__Create(hx::DynamicArray inArgs)
{  hx::ObjectPtr< FontDebugger_obj > result = new FontDebugger_obj();
	result->__construct(inArgs[0],inArgs[1],inArgs[2]);
	return result;}

::String FontDebugger_obj::resourceName;


FontDebugger_obj::FontDebugger_obj()
{
}

Dynamic FontDebugger_obj::__Field(const ::String &inName,bool inCallProp)
{
	switch(inName.length) {
	case 12:
		if (HX_FIELD_EQ(inName,"resourceName") ) { return resourceName; }
	}
	return super::__Field(inName,inCallProp);
}

Dynamic FontDebugger_obj::__SetField(const ::String &inName,const Dynamic &inValue,bool inCallProp)
{
	switch(inName.length) {
	case 12:
		if (HX_FIELD_EQ(inName,"resourceName") ) { resourceName=inValue.Cast< ::String >(); return inValue; }
	}
	return super::__SetField(inName,inValue,inCallProp);
}

void FontDebugger_obj::__GetFields(Array< ::String> &outFields)
{
	super::__GetFields(outFields);
};

static ::String sStaticFields[] = {
	HX_CSTRING("resourceName"),
	String(null()) };

#if HXCPP_SCRIPTABLE
static hx::StorageInfo *sMemberStorageInfo = 0;
#endif

static ::String sMemberFields[] = {
	String(null()) };

static void sMarkStatics(HX_MARK_PARAMS) {
	HX_MARK_MEMBER_NAME(FontDebugger_obj::__mClass,"__mClass");
	HX_MARK_MEMBER_NAME(FontDebugger_obj::resourceName,"resourceName");
};

#ifdef HXCPP_VISIT_ALLOCS
static void sVisitStatics(HX_VISIT_PARAMS) {
	HX_VISIT_MEMBER_NAME(FontDebugger_obj::__mClass,"__mClass");
	HX_VISIT_MEMBER_NAME(FontDebugger_obj::resourceName,"resourceName");
};

#endif

Class FontDebugger_obj::__mClass;

void FontDebugger_obj::__register()
{
	hx::Static(__mClass) = hx::RegisterClass(HX_CSTRING("flixel.system._FlxAssets.FontDebugger"), hx::TCanCast< FontDebugger_obj> ,sStaticFields,sMemberFields,
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

void FontDebugger_obj::__boot()
{
	resourceName= HX_CSTRING("NME_font_flixel_system__FlxAssets_FontDebugger");
}

} // end namespace flixel
} // end namespace system
} // end namespace _FlxAssets
