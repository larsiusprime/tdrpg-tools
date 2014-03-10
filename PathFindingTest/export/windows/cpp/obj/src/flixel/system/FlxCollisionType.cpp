#include <hxcpp.h>

#ifndef INCLUDED_flixel_system_FlxCollisionType
#include <flixel/system/FlxCollisionType.h>
#endif
namespace flixel{
namespace system{

::flixel::system::FlxCollisionType FlxCollisionType_obj::GROUP;

::flixel::system::FlxCollisionType FlxCollisionType_obj::NONE;

::flixel::system::FlxCollisionType FlxCollisionType_obj::OBJECT;

::flixel::system::FlxCollisionType FlxCollisionType_obj::SPRITEGROUP;

::flixel::system::FlxCollisionType FlxCollisionType_obj::TILEMAP;

HX_DEFINE_CREATE_ENUM(FlxCollisionType_obj)

int FlxCollisionType_obj::__FindIndex(::String inName)
{
	if (inName==HX_CSTRING("GROUP")) return 2;
	if (inName==HX_CSTRING("NONE")) return 0;
	if (inName==HX_CSTRING("OBJECT")) return 1;
	if (inName==HX_CSTRING("SPRITEGROUP")) return 4;
	if (inName==HX_CSTRING("TILEMAP")) return 3;
	return super::__FindIndex(inName);
}

int FlxCollisionType_obj::__FindArgCount(::String inName)
{
	if (inName==HX_CSTRING("GROUP")) return 0;
	if (inName==HX_CSTRING("NONE")) return 0;
	if (inName==HX_CSTRING("OBJECT")) return 0;
	if (inName==HX_CSTRING("SPRITEGROUP")) return 0;
	if (inName==HX_CSTRING("TILEMAP")) return 0;
	return super::__FindArgCount(inName);
}

Dynamic FlxCollisionType_obj::__Field(const ::String &inName,bool inCallProp)
{
	if (inName==HX_CSTRING("GROUP")) return GROUP;
	if (inName==HX_CSTRING("NONE")) return NONE;
	if (inName==HX_CSTRING("OBJECT")) return OBJECT;
	if (inName==HX_CSTRING("SPRITEGROUP")) return SPRITEGROUP;
	if (inName==HX_CSTRING("TILEMAP")) return TILEMAP;
	return super::__Field(inName,inCallProp);
}

static ::String sStaticFields[] = {
	HX_CSTRING("NONE"),
	HX_CSTRING("OBJECT"),
	HX_CSTRING("GROUP"),
	HX_CSTRING("TILEMAP"),
	HX_CSTRING("SPRITEGROUP"),
	::String(null()) };

static void sMarkStatics(HX_MARK_PARAMS) {
	HX_MARK_MEMBER_NAME(FlxCollisionType_obj::GROUP,"GROUP");
	HX_MARK_MEMBER_NAME(FlxCollisionType_obj::NONE,"NONE");
	HX_MARK_MEMBER_NAME(FlxCollisionType_obj::OBJECT,"OBJECT");
	HX_MARK_MEMBER_NAME(FlxCollisionType_obj::SPRITEGROUP,"SPRITEGROUP");
	HX_MARK_MEMBER_NAME(FlxCollisionType_obj::TILEMAP,"TILEMAP");
};

#ifdef HXCPP_VISIT_ALLOCS
static void sVisitStatic(HX_VISIT_PARAMS) {
	HX_VISIT_MEMBER_NAME(FlxCollisionType_obj::__mClass,"__mClass");
	HX_VISIT_MEMBER_NAME(FlxCollisionType_obj::GROUP,"GROUP");
	HX_VISIT_MEMBER_NAME(FlxCollisionType_obj::NONE,"NONE");
	HX_VISIT_MEMBER_NAME(FlxCollisionType_obj::OBJECT,"OBJECT");
	HX_VISIT_MEMBER_NAME(FlxCollisionType_obj::SPRITEGROUP,"SPRITEGROUP");
	HX_VISIT_MEMBER_NAME(FlxCollisionType_obj::TILEMAP,"TILEMAP");
};
#endif

static ::String sMemberFields[] = { ::String(null()) };
Class FlxCollisionType_obj::__mClass;

Dynamic __Create_FlxCollisionType_obj() { return new FlxCollisionType_obj; }

void FlxCollisionType_obj::__register()
{

hx::Static(__mClass) = hx::RegisterClass(HX_CSTRING("flixel.system.FlxCollisionType"), hx::TCanCast< FlxCollisionType_obj >,sStaticFields,sMemberFields,
	&__Create_FlxCollisionType_obj, &__Create,
	&super::__SGetClass(), &CreateFlxCollisionType_obj, sMarkStatics
#ifdef HXCPP_VISIT_ALLOCS
    , sVisitStatic
#endif
#ifdef HXCPP_SCRIPTABLE
    , 0
#endif
);
}

void FlxCollisionType_obj::__boot()
{
hx::Static(GROUP) = hx::CreateEnum< FlxCollisionType_obj >(HX_CSTRING("GROUP"),2);
hx::Static(NONE) = hx::CreateEnum< FlxCollisionType_obj >(HX_CSTRING("NONE"),0);
hx::Static(OBJECT) = hx::CreateEnum< FlxCollisionType_obj >(HX_CSTRING("OBJECT"),1);
hx::Static(SPRITEGROUP) = hx::CreateEnum< FlxCollisionType_obj >(HX_CSTRING("SPRITEGROUP"),4);
hx::Static(TILEMAP) = hx::CreateEnum< FlxCollisionType_obj >(HX_CSTRING("TILEMAP"),3);
}


} // end namespace flixel
} // end namespace system
