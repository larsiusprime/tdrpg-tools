#include <hxcpp.h>

#ifndef INCLUDED_flash_events_EventDispatcher
#include <flash/events/EventDispatcher.h>
#endif
#ifndef INCLUDED_flash_events_IEventDispatcher
#include <flash/events/IEventDispatcher.h>
#endif
#ifndef INCLUDED_flash_media_Sound
#include <flash/media/Sound.h>
#endif
#ifndef INCLUDED_flash_media_SoundLoaderContext
#include <flash/media/SoundLoaderContext.h>
#endif
#ifndef INCLUDED_flash_net_URLRequest
#include <flash/net/URLRequest.h>
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
#ifndef INCLUDED_flixel_system_BeepSound
#include <flixel/system/BeepSound.h>
#endif
#ifndef INCLUDED_haxe_Resource
#include <haxe/Resource.h>
#endif
#ifndef INCLUDED_haxe_io_Bytes
#include <haxe/io/Bytes.h>
#endif
#ifndef INCLUDED_openfl_utils_IMemoryRange
#include <openfl/utils/IMemoryRange.h>
#endif
namespace flixel{
namespace system{

Void BeepSound_obj::__construct(::flash::net::URLRequest stream,::flash::media::SoundLoaderContext context,Dynamic __o_forcePlayAsMusic)
{
HX_STACK_FRAME("flixel.system.BeepSound","new",0x95b657e6,"flixel.system.BeepSound.new","openfl/Assets.hx",1474,0x989d477c)

HX_STACK_ARG(stream,"stream")

HX_STACK_ARG(context,"context")

HX_STACK_ARG(__o_forcePlayAsMusic,"forcePlayAsMusic")
Dynamic forcePlayAsMusic = __o_forcePlayAsMusic.Default(false);
{
	HX_STACK_LINE(1476)
	super::__construct(null(),null(),null());
	HX_STACK_LINE(1478)
	::flash::utils::ByteArray byteArray = ::flash::utils::ByteArray_obj::fromBytes(::haxe::Resource_obj::getBytes(::flixel::system::BeepSound_obj::resourceName));		HX_STACK_VAR(byteArray,"byteArray");
	HX_STACK_LINE(1479)
	this->loadCompressedDataFromByteArray(byteArray,byteArray->length,forcePlayAsMusic);
}
;
	return null();
}

//BeepSound_obj::~BeepSound_obj() { }

Dynamic BeepSound_obj::__CreateEmpty() { return  new BeepSound_obj; }
hx::ObjectPtr< BeepSound_obj > BeepSound_obj::__new(::flash::net::URLRequest stream,::flash::media::SoundLoaderContext context,Dynamic __o_forcePlayAsMusic)
{  hx::ObjectPtr< BeepSound_obj > result = new BeepSound_obj();
	result->__construct(stream,context,__o_forcePlayAsMusic);
	return result;}

Dynamic BeepSound_obj::__Create(hx::DynamicArray inArgs)
{  hx::ObjectPtr< BeepSound_obj > result = new BeepSound_obj();
	result->__construct(inArgs[0],inArgs[1],inArgs[2]);
	return result;}

::String BeepSound_obj::resourceName;


BeepSound_obj::BeepSound_obj()
{
}

Dynamic BeepSound_obj::__Field(const ::String &inName,bool inCallProp)
{
	switch(inName.length) {
	case 12:
		if (HX_FIELD_EQ(inName,"resourceName") ) { return resourceName; }
	}
	return super::__Field(inName,inCallProp);
}

Dynamic BeepSound_obj::__SetField(const ::String &inName,const Dynamic &inValue,bool inCallProp)
{
	switch(inName.length) {
	case 12:
		if (HX_FIELD_EQ(inName,"resourceName") ) { resourceName=inValue.Cast< ::String >(); return inValue; }
	}
	return super::__SetField(inName,inValue,inCallProp);
}

void BeepSound_obj::__GetFields(Array< ::String> &outFields)
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
	HX_MARK_MEMBER_NAME(BeepSound_obj::__mClass,"__mClass");
	HX_MARK_MEMBER_NAME(BeepSound_obj::resourceName,"resourceName");
};

#ifdef HXCPP_VISIT_ALLOCS
static void sVisitStatics(HX_VISIT_PARAMS) {
	HX_VISIT_MEMBER_NAME(BeepSound_obj::__mClass,"__mClass");
	HX_VISIT_MEMBER_NAME(BeepSound_obj::resourceName,"resourceName");
};

#endif

Class BeepSound_obj::__mClass;

void BeepSound_obj::__register()
{
	hx::Static(__mClass) = hx::RegisterClass(HX_CSTRING("flixel.system.BeepSound"), hx::TCanCast< BeepSound_obj> ,sStaticFields,sMemberFields,
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

void BeepSound_obj::__boot()
{
	resourceName= HX_CSTRING("__ASSET__:sound_flixel_system_BeepSound");
}

} // end namespace flixel
} // end namespace system
