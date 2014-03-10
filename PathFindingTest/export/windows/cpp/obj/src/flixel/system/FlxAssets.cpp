#include <hxcpp.h>

#ifndef INCLUDED_flash_display_BitmapData
#include <flash/display/BitmapData.h>
#endif
#ifndef INCLUDED_flash_display_Graphics
#include <flash/display/Graphics.h>
#endif
#ifndef INCLUDED_flash_display_IBitmapDrawable
#include <flash/display/IBitmapDrawable.h>
#endif
#ifndef INCLUDED_flash_text_Font
#include <flash/text/Font.h>
#endif
#ifndef INCLUDED_flixel_system_FlxAssets
#include <flixel/system/FlxAssets.h>
#endif
#ifndef INCLUDED_flixel_system__FlxAssets_FontDebugger
#include <flixel/system/_FlxAssets/FontDebugger.h>
#endif
#ifndef INCLUDED_flixel_system__FlxAssets_FontDefault
#include <flixel/system/_FlxAssets/FontDefault.h>
#endif
#ifndef INCLUDED_openfl_Assets
#include <openfl/Assets.h>
#endif
namespace flixel{
namespace system{

Void FlxAssets_obj::__construct()
{
	return null();
}

//FlxAssets_obj::~FlxAssets_obj() { }

Dynamic FlxAssets_obj::__CreateEmpty() { return  new FlxAssets_obj; }
hx::ObjectPtr< FlxAssets_obj > FlxAssets_obj::__new()
{  hx::ObjectPtr< FlxAssets_obj > result = new FlxAssets_obj();
	result->__construct();
	return result;}

Dynamic FlxAssets_obj::__Create(hx::DynamicArray inArgs)
{  hx::ObjectPtr< FlxAssets_obj > result = new FlxAssets_obj();
	result->__construct();
	return result;}

::String FlxAssets_obj::FONT_DEFAULT;

::String FlxAssets_obj::FONT_DEBUGGER;

Void FlxAssets_obj::init( ){
{
		HX_STACK_FRAME("flixel.system.FlxAssets","init",0x4cb026b6,"flixel.system.FlxAssets.init","flixel/system/FlxAssets.hx",33,0xd3ac1356)
		HX_STACK_LINE(34)
		::flash::text::Font_obj::registerFont(hx::ClassOf< ::flixel::system::_FlxAssets::FontDefault >());
		HX_STACK_LINE(37)
		::flash::text::Font_obj::registerFont(hx::ClassOf< ::flixel::system::_FlxAssets::FontDebugger >());
	}
return null();
}


STATIC_HX_DEFINE_DYNAMIC_FUNC0(FlxAssets_obj,init,(void))

Void FlxAssets_obj::drawLogo( ::flash::display::Graphics graph){
{
		HX_STACK_FRAME("flixel.system.FlxAssets","drawLogo",0xabec0035,"flixel.system.FlxAssets.drawLogo","flixel/system/FlxAssets.hx",42,0xd3ac1356)
		HX_STACK_ARG(graph,"graph")
		HX_STACK_LINE(44)
		graph->beginFill((int)47394,null());
		HX_STACK_LINE(45)
		graph->moveTo((int)50,(int)13);
		HX_STACK_LINE(46)
		graph->lineTo((int)51,(int)13);
		HX_STACK_LINE(47)
		graph->lineTo((int)87,(int)50);
		HX_STACK_LINE(48)
		graph->lineTo((int)87,(int)51);
		HX_STACK_LINE(49)
		graph->lineTo((int)51,(int)87);
		HX_STACK_LINE(50)
		graph->lineTo((int)50,(int)87);
		HX_STACK_LINE(51)
		graph->lineTo((int)13,(int)51);
		HX_STACK_LINE(52)
		graph->lineTo((int)13,(int)50);
		HX_STACK_LINE(53)
		graph->lineTo((int)50,(int)13);
		HX_STACK_LINE(54)
		graph->endFill();
		HX_STACK_LINE(57)
		graph->beginFill((int)16761138,null());
		HX_STACK_LINE(58)
		graph->moveTo((int)0,(int)0);
		HX_STACK_LINE(59)
		graph->lineTo((int)25,(int)0);
		HX_STACK_LINE(60)
		graph->lineTo((int)50,(int)13);
		HX_STACK_LINE(61)
		graph->lineTo((int)13,(int)50);
		HX_STACK_LINE(62)
		graph->lineTo((int)0,(int)25);
		HX_STACK_LINE(63)
		graph->lineTo((int)0,(int)0);
		HX_STACK_LINE(64)
		graph->endFill();
		HX_STACK_LINE(67)
		graph->beginFill((int)16066382,null());
		HX_STACK_LINE(68)
		graph->moveTo((int)100,(int)0);
		HX_STACK_LINE(69)
		graph->lineTo((int)75,(int)0);
		HX_STACK_LINE(70)
		graph->lineTo((int)51,(int)13);
		HX_STACK_LINE(71)
		graph->lineTo((int)87,(int)50);
		HX_STACK_LINE(72)
		graph->lineTo((int)100,(int)25);
		HX_STACK_LINE(73)
		graph->lineTo((int)100,(int)0);
		HX_STACK_LINE(74)
		graph->endFill();
		HX_STACK_LINE(77)
		graph->beginFill((int)3555839,null());
		HX_STACK_LINE(78)
		graph->moveTo((int)0,(int)100);
		HX_STACK_LINE(79)
		graph->lineTo((int)25,(int)100);
		HX_STACK_LINE(80)
		graph->lineTo((int)50,(int)87);
		HX_STACK_LINE(81)
		graph->lineTo((int)13,(int)51);
		HX_STACK_LINE(82)
		graph->lineTo((int)0,(int)75);
		HX_STACK_LINE(83)
		graph->lineTo((int)0,(int)100);
		HX_STACK_LINE(84)
		graph->endFill();
		HX_STACK_LINE(87)
		graph->beginFill((int)314875,null());
		HX_STACK_LINE(88)
		graph->moveTo((int)100,(int)100);
		HX_STACK_LINE(89)
		graph->lineTo((int)75,(int)100);
		HX_STACK_LINE(90)
		graph->lineTo((int)51,(int)87);
		HX_STACK_LINE(91)
		graph->lineTo((int)87,(int)51);
		HX_STACK_LINE(92)
		graph->lineTo((int)100,(int)75);
		HX_STACK_LINE(93)
		graph->lineTo((int)100,(int)100);
		HX_STACK_LINE(94)
		graph->endFill();
	}
return null();
}


STATIC_HX_DEFINE_DYNAMIC_FUNC1(FlxAssets_obj,drawLogo,(void))

::flash::display::BitmapData FlxAssets_obj::getBitmapData( ::String id){
	HX_STACK_FRAME("flixel.system.FlxAssets","getBitmapData",0x17128189,"flixel.system.FlxAssets.getBitmapData","flixel/system/FlxAssets.hx",99,0xd3ac1356)
	HX_STACK_ARG(id,"id")
	HX_STACK_LINE(99)
	return ::openfl::Assets_obj::getBitmapData(id,false);
}


STATIC_HX_DEFINE_DYNAMIC_FUNC1(FlxAssets_obj,getBitmapData,return )

Void FlxAssets_obj::cacheSounds( ){
{
		HX_STACK_FRAME("flixel.system.FlxAssets","cacheSounds",0x35d449c0,"flixel.system.FlxAssets.cacheSounds","flixel/system/FlxAssets.hx",109,0xd3ac1356)
	}
return null();
}


STATIC_HX_DEFINE_DYNAMIC_FUNC0(FlxAssets_obj,cacheSounds,(void))


FlxAssets_obj::FlxAssets_obj()
{
}

Dynamic FlxAssets_obj::__Field(const ::String &inName,bool inCallProp)
{
	switch(inName.length) {
	case 4:
		if (HX_FIELD_EQ(inName,"init") ) { return init_dyn(); }
		break;
	case 8:
		if (HX_FIELD_EQ(inName,"drawLogo") ) { return drawLogo_dyn(); }
		break;
	case 11:
		if (HX_FIELD_EQ(inName,"cacheSounds") ) { return cacheSounds_dyn(); }
		break;
	case 12:
		if (HX_FIELD_EQ(inName,"FONT_DEFAULT") ) { return FONT_DEFAULT; }
		break;
	case 13:
		if (HX_FIELD_EQ(inName,"FONT_DEBUGGER") ) { return FONT_DEBUGGER; }
		if (HX_FIELD_EQ(inName,"getBitmapData") ) { return getBitmapData_dyn(); }
	}
	return super::__Field(inName,inCallProp);
}

Dynamic FlxAssets_obj::__SetField(const ::String &inName,const Dynamic &inValue,bool inCallProp)
{
	switch(inName.length) {
	case 12:
		if (HX_FIELD_EQ(inName,"FONT_DEFAULT") ) { FONT_DEFAULT=inValue.Cast< ::String >(); return inValue; }
		break;
	case 13:
		if (HX_FIELD_EQ(inName,"FONT_DEBUGGER") ) { FONT_DEBUGGER=inValue.Cast< ::String >(); return inValue; }
	}
	return super::__SetField(inName,inValue,inCallProp);
}

void FlxAssets_obj::__GetFields(Array< ::String> &outFields)
{
	super::__GetFields(outFields);
};

static ::String sStaticFields[] = {
	HX_CSTRING("FONT_DEFAULT"),
	HX_CSTRING("FONT_DEBUGGER"),
	HX_CSTRING("init"),
	HX_CSTRING("drawLogo"),
	HX_CSTRING("getBitmapData"),
	HX_CSTRING("cacheSounds"),
	String(null()) };

#if HXCPP_SCRIPTABLE
static hx::StorageInfo *sMemberStorageInfo = 0;
#endif

static ::String sMemberFields[] = {
	String(null()) };

static void sMarkStatics(HX_MARK_PARAMS) {
	HX_MARK_MEMBER_NAME(FlxAssets_obj::__mClass,"__mClass");
	HX_MARK_MEMBER_NAME(FlxAssets_obj::FONT_DEFAULT,"FONT_DEFAULT");
	HX_MARK_MEMBER_NAME(FlxAssets_obj::FONT_DEBUGGER,"FONT_DEBUGGER");
};

#ifdef HXCPP_VISIT_ALLOCS
static void sVisitStatics(HX_VISIT_PARAMS) {
	HX_VISIT_MEMBER_NAME(FlxAssets_obj::__mClass,"__mClass");
	HX_VISIT_MEMBER_NAME(FlxAssets_obj::FONT_DEFAULT,"FONT_DEFAULT");
	HX_VISIT_MEMBER_NAME(FlxAssets_obj::FONT_DEBUGGER,"FONT_DEBUGGER");
};

#endif

Class FlxAssets_obj::__mClass;

void FlxAssets_obj::__register()
{
	hx::Static(__mClass) = hx::RegisterClass(HX_CSTRING("flixel.system.FlxAssets"), hx::TCanCast< FlxAssets_obj> ,sStaticFields,sMemberFields,
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

void FlxAssets_obj::__boot()
{
	FONT_DEFAULT= HX_CSTRING("Nokia Cellphone FC Small");
	FONT_DEBUGGER= HX_CSTRING("Arial");
}

} // end namespace flixel
} // end namespace system
