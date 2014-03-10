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
#ifndef INCLUDED_flash_display_MovieClip
#include <flash/display/MovieClip.h>
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
#ifndef INCLUDED_flash_media_Sound
#include <flash/media/Sound.h>
#endif
#ifndef INCLUDED_flash_text_Font
#include <flash/text/Font.h>
#endif
#ifndef INCLUDED_flash_utils_ByteArray
#include <flash/utils/ByteArray.h>
#endif
#ifndef INCLUDED_flash_utils_IDataInput
#include <flash/utils/IDataInput.h>
#endif
#ifndef INCLUDED_flash_utils_IDataOutput
#include <flash/utils/IDataOutput.h>
#endif
#ifndef INCLUDED_haxe_io_Bytes
#include <haxe/io/Bytes.h>
#endif
#ifndef INCLUDED_openfl_AssetLibrary
#include <openfl/AssetLibrary.h>
#endif
#ifndef INCLUDED_openfl_AssetType
#include <openfl/AssetType.h>
#endif
#ifndef INCLUDED_openfl_utils_IMemoryRange
#include <openfl/utils/IMemoryRange.h>
#endif
namespace openfl{

Void AssetLibrary_obj::__construct()
{
HX_STACK_FRAME("openfl.AssetLibrary","new",0x1b1e281b,"openfl.AssetLibrary.new","openfl/Assets.hx",1067,0x989d477c)
{
}
;
	return null();
}

//AssetLibrary_obj::~AssetLibrary_obj() { }

Dynamic AssetLibrary_obj::__CreateEmpty() { return  new AssetLibrary_obj; }
hx::ObjectPtr< AssetLibrary_obj > AssetLibrary_obj::__new()
{  hx::ObjectPtr< AssetLibrary_obj > result = new AssetLibrary_obj();
	result->__construct();
	return result;}

Dynamic AssetLibrary_obj::__Create(hx::DynamicArray inArgs)
{  hx::ObjectPtr< AssetLibrary_obj > result = new AssetLibrary_obj();
	result->__construct();
	return result;}

bool AssetLibrary_obj::exists( ::String id,::openfl::AssetType type){
	HX_STACK_FRAME("openfl.AssetLibrary","exists",0xfc810d01,"openfl.AssetLibrary.exists","openfl/Assets.hx",1076,0x989d477c)
	HX_STACK_THIS(this)
	HX_STACK_ARG(id,"id")
	HX_STACK_ARG(type,"type")
	HX_STACK_LINE(1076)
	return false;
}


HX_DEFINE_DYNAMIC_FUNC2(AssetLibrary_obj,exists,return )

::flash::display::BitmapData AssetLibrary_obj::getBitmapData( ::String id){
	HX_STACK_FRAME("openfl.AssetLibrary","getBitmapData",0x8468816a,"openfl.AssetLibrary.getBitmapData","openfl/Assets.hx",1083,0x989d477c)
	HX_STACK_THIS(this)
	HX_STACK_ARG(id,"id")
	HX_STACK_LINE(1083)
	return null();
}


HX_DEFINE_DYNAMIC_FUNC1(AssetLibrary_obj,getBitmapData,return )

::flash::utils::ByteArray AssetLibrary_obj::getBytes( ::String id){
	HX_STACK_FRAME("openfl.AssetLibrary","getBytes",0x7785da5a,"openfl.AssetLibrary.getBytes","openfl/Assets.hx",1090,0x989d477c)
	HX_STACK_THIS(this)
	HX_STACK_ARG(id,"id")
	HX_STACK_LINE(1090)
	return null();
}


HX_DEFINE_DYNAMIC_FUNC1(AssetLibrary_obj,getBytes,return )

::flash::text::Font AssetLibrary_obj::getFont( ::String id){
	HX_STACK_FRAME("openfl.AssetLibrary","getFont",0xe6735ec0,"openfl.AssetLibrary.getFont","openfl/Assets.hx",1097,0x989d477c)
	HX_STACK_THIS(this)
	HX_STACK_ARG(id,"id")
	HX_STACK_LINE(1097)
	return null();
}


HX_DEFINE_DYNAMIC_FUNC1(AssetLibrary_obj,getFont,return )

::flash::display::MovieClip AssetLibrary_obj::getMovieClip( ::String id){
	HX_STACK_FRAME("openfl.AssetLibrary","getMovieClip",0x2889f80f,"openfl.AssetLibrary.getMovieClip","openfl/Assets.hx",1104,0x989d477c)
	HX_STACK_THIS(this)
	HX_STACK_ARG(id,"id")
	HX_STACK_LINE(1104)
	return null();
}


HX_DEFINE_DYNAMIC_FUNC1(AssetLibrary_obj,getMovieClip,return )

::flash::media::Sound AssetLibrary_obj::getMusic( ::String id){
	HX_STACK_FRAME("openfl.AssetLibrary","getMusic",0xca48a294,"openfl.AssetLibrary.getMusic","openfl/Assets.hx",1111,0x989d477c)
	HX_STACK_THIS(this)
	HX_STACK_ARG(id,"id")
	HX_STACK_LINE(1111)
	return this->getSound(id);
}


HX_DEFINE_DYNAMIC_FUNC1(AssetLibrary_obj,getMusic,return )

::String AssetLibrary_obj::getPath( ::String id){
	HX_STACK_FRAME("openfl.AssetLibrary","getPath",0xed04e696,"openfl.AssetLibrary.getPath","openfl/Assets.hx",1118,0x989d477c)
	HX_STACK_THIS(this)
	HX_STACK_ARG(id,"id")
	HX_STACK_LINE(1118)
	return null();
}


HX_DEFINE_DYNAMIC_FUNC1(AssetLibrary_obj,getPath,return )

::flash::media::Sound AssetLibrary_obj::getSound( ::String id){
	HX_STACK_FRAME("openfl.AssetLibrary","getSound",0x3aba5ebe,"openfl.AssetLibrary.getSound","openfl/Assets.hx",1125,0x989d477c)
	HX_STACK_THIS(this)
	HX_STACK_ARG(id,"id")
	HX_STACK_LINE(1125)
	return null();
}


HX_DEFINE_DYNAMIC_FUNC1(AssetLibrary_obj,getSound,return )

bool AssetLibrary_obj::isLocal( ::String id,::openfl::AssetType type){
	HX_STACK_FRAME("openfl.AssetLibrary","isLocal",0xe5a6be5c,"openfl.AssetLibrary.isLocal","openfl/Assets.hx",1132,0x989d477c)
	HX_STACK_THIS(this)
	HX_STACK_ARG(id,"id")
	HX_STACK_ARG(type,"type")
	HX_STACK_LINE(1132)
	return true;
}


HX_DEFINE_DYNAMIC_FUNC2(AssetLibrary_obj,isLocal,return )

Void AssetLibrary_obj::load( Dynamic handler){
{
		HX_STACK_FRAME("openfl.AssetLibrary","load",0x9dfa060b,"openfl.AssetLibrary.load","openfl/Assets.hx",1139,0x989d477c)
		HX_STACK_THIS(this)
		HX_STACK_ARG(handler,"handler")
		HX_STACK_LINE(1139)
		handler(hx::ObjectPtr<OBJ_>(this)).Cast< Void >();
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC1(AssetLibrary_obj,load,(void))

Void AssetLibrary_obj::loadBitmapData( ::String id,Dynamic handler){
{
		HX_STACK_FRAME("openfl.AssetLibrary","loadBitmapData",0x84fddba4,"openfl.AssetLibrary.loadBitmapData","openfl/Assets.hx",1146,0x989d477c)
		HX_STACK_THIS(this)
		HX_STACK_ARG(id,"id")
		HX_STACK_ARG(handler,"handler")
		HX_STACK_LINE(1146)
		handler(this->getBitmapData(id)).Cast< Void >();
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC2(AssetLibrary_obj,loadBitmapData,(void))

Void AssetLibrary_obj::loadBytes( ::String id,Dynamic handler){
{
		HX_STACK_FRAME("openfl.AssetLibrary","loadBytes",0x52a2aa60,"openfl.AssetLibrary.loadBytes","openfl/Assets.hx",1153,0x989d477c)
		HX_STACK_THIS(this)
		HX_STACK_ARG(id,"id")
		HX_STACK_ARG(handler,"handler")
		HX_STACK_LINE(1153)
		handler(this->getBytes(id)).Cast< Void >();
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC2(AssetLibrary_obj,loadBytes,(void))

Void AssetLibrary_obj::loadFont( ::String id,Dynamic handler){
{
		HX_STACK_FRAME("openfl.AssetLibrary","loadFont",0x0e76f17a,"openfl.AssetLibrary.loadFont","openfl/Assets.hx",1160,0x989d477c)
		HX_STACK_THIS(this)
		HX_STACK_ARG(id,"id")
		HX_STACK_ARG(handler,"handler")
		HX_STACK_LINE(1160)
		handler(this->getFont(id)).Cast< Void >();
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC2(AssetLibrary_obj,loadFont,(void))

Void AssetLibrary_obj::loadMovieClip( ::String id,Dynamic handler){
{
		HX_STACK_FRAME("openfl.AssetLibrary","loadMovieClip",0x8eb64315,"openfl.AssetLibrary.loadMovieClip","openfl/Assets.hx",1167,0x989d477c)
		HX_STACK_THIS(this)
		HX_STACK_ARG(id,"id")
		HX_STACK_ARG(handler,"handler")
		HX_STACK_LINE(1167)
		handler(this->getMovieClip(id)).Cast< Void >();
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC2(AssetLibrary_obj,loadMovieClip,(void))

Void AssetLibrary_obj::loadMusic( ::String id,Dynamic handler){
{
		HX_STACK_FRAME("openfl.AssetLibrary","loadMusic",0xa565729a,"openfl.AssetLibrary.loadMusic","openfl/Assets.hx",1174,0x989d477c)
		HX_STACK_THIS(this)
		HX_STACK_ARG(id,"id")
		HX_STACK_ARG(handler,"handler")
		HX_STACK_LINE(1174)
		handler(this->getMusic(id)).Cast< Void >();
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC2(AssetLibrary_obj,loadMusic,(void))

Void AssetLibrary_obj::loadSound( ::String id,Dynamic handler){
{
		HX_STACK_FRAME("openfl.AssetLibrary","loadSound",0x15d72ec4,"openfl.AssetLibrary.loadSound","openfl/Assets.hx",1181,0x989d477c)
		HX_STACK_THIS(this)
		HX_STACK_ARG(id,"id")
		HX_STACK_ARG(handler,"handler")
		HX_STACK_LINE(1181)
		handler(this->getSound(id)).Cast< Void >();
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC2(AssetLibrary_obj,loadSound,(void))


AssetLibrary_obj::AssetLibrary_obj()
{
}

Dynamic AssetLibrary_obj::__Field(const ::String &inName,bool inCallProp)
{
	switch(inName.length) {
	case 4:
		if (HX_FIELD_EQ(inName,"load") ) { return load_dyn(); }
		break;
	case 6:
		if (HX_FIELD_EQ(inName,"exists") ) { return exists_dyn(); }
		break;
	case 7:
		if (HX_FIELD_EQ(inName,"getFont") ) { return getFont_dyn(); }
		if (HX_FIELD_EQ(inName,"getPath") ) { return getPath_dyn(); }
		if (HX_FIELD_EQ(inName,"isLocal") ) { return isLocal_dyn(); }
		break;
	case 8:
		if (HX_FIELD_EQ(inName,"getBytes") ) { return getBytes_dyn(); }
		if (HX_FIELD_EQ(inName,"getMusic") ) { return getMusic_dyn(); }
		if (HX_FIELD_EQ(inName,"getSound") ) { return getSound_dyn(); }
		if (HX_FIELD_EQ(inName,"loadFont") ) { return loadFont_dyn(); }
		break;
	case 9:
		if (HX_FIELD_EQ(inName,"loadBytes") ) { return loadBytes_dyn(); }
		if (HX_FIELD_EQ(inName,"loadMusic") ) { return loadMusic_dyn(); }
		if (HX_FIELD_EQ(inName,"loadSound") ) { return loadSound_dyn(); }
		break;
	case 12:
		if (HX_FIELD_EQ(inName,"getMovieClip") ) { return getMovieClip_dyn(); }
		break;
	case 13:
		if (HX_FIELD_EQ(inName,"getBitmapData") ) { return getBitmapData_dyn(); }
		if (HX_FIELD_EQ(inName,"loadMovieClip") ) { return loadMovieClip_dyn(); }
		break;
	case 14:
		if (HX_FIELD_EQ(inName,"loadBitmapData") ) { return loadBitmapData_dyn(); }
	}
	return super::__Field(inName,inCallProp);
}

Dynamic AssetLibrary_obj::__SetField(const ::String &inName,const Dynamic &inValue,bool inCallProp)
{
	return super::__SetField(inName,inValue,inCallProp);
}

void AssetLibrary_obj::__GetFields(Array< ::String> &outFields)
{
	super::__GetFields(outFields);
};

static ::String sStaticFields[] = {
	String(null()) };

#if HXCPP_SCRIPTABLE
static hx::StorageInfo *sMemberStorageInfo = 0;
#endif

static ::String sMemberFields[] = {
	HX_CSTRING("exists"),
	HX_CSTRING("getBitmapData"),
	HX_CSTRING("getBytes"),
	HX_CSTRING("getFont"),
	HX_CSTRING("getMovieClip"),
	HX_CSTRING("getMusic"),
	HX_CSTRING("getPath"),
	HX_CSTRING("getSound"),
	HX_CSTRING("isLocal"),
	HX_CSTRING("load"),
	HX_CSTRING("loadBitmapData"),
	HX_CSTRING("loadBytes"),
	HX_CSTRING("loadFont"),
	HX_CSTRING("loadMovieClip"),
	HX_CSTRING("loadMusic"),
	HX_CSTRING("loadSound"),
	String(null()) };

static void sMarkStatics(HX_MARK_PARAMS) {
	HX_MARK_MEMBER_NAME(AssetLibrary_obj::__mClass,"__mClass");
};

#ifdef HXCPP_VISIT_ALLOCS
static void sVisitStatics(HX_VISIT_PARAMS) {
	HX_VISIT_MEMBER_NAME(AssetLibrary_obj::__mClass,"__mClass");
};

#endif

Class AssetLibrary_obj::__mClass;

void AssetLibrary_obj::__register()
{
	hx::Static(__mClass) = hx::RegisterClass(HX_CSTRING("openfl.AssetLibrary"), hx::TCanCast< AssetLibrary_obj> ,sStaticFields,sMemberFields,
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

void AssetLibrary_obj::__boot()
{
}

} // end namespace openfl
