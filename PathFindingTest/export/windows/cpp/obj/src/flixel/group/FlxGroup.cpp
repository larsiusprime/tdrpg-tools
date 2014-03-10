#include <hxcpp.h>

#ifndef INCLUDED_flixel_FlxBasic
#include <flixel/FlxBasic.h>
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
namespace flixel{
namespace group{

Void FlxGroup_obj::__construct(hx::Null< int >  __o_MaxSize)
{
HX_STACK_FRAME("flixel.group.FlxGroup","new",0x4f47f260,"flixel.group.FlxGroup.new","flixel/group/FlxGroup.hx",19,0x1e89d58e)

HX_STACK_ARG(__o_MaxSize,"MaxSize")
int MaxSize = __o_MaxSize.Default(0);
{
	HX_STACK_LINE(19)
	super::__construct(MaxSize);
}
;
	return null();
}

//FlxGroup_obj::~FlxGroup_obj() { }

Dynamic FlxGroup_obj::__CreateEmpty() { return  new FlxGroup_obj; }
hx::ObjectPtr< FlxGroup_obj > FlxGroup_obj::__new(hx::Null< int >  __o_MaxSize)
{  hx::ObjectPtr< FlxGroup_obj > result = new FlxGroup_obj();
	result->__construct(__o_MaxSize);
	return result;}

Dynamic FlxGroup_obj::__Create(hx::DynamicArray inArgs)
{  hx::ObjectPtr< FlxGroup_obj > result = new FlxGroup_obj();
	result->__construct(inArgs[0]);
	return result;}


FlxGroup_obj::FlxGroup_obj()
{
}

Dynamic FlxGroup_obj::__Field(const ::String &inName,bool inCallProp)
{
	return super::__Field(inName,inCallProp);
}

Dynamic FlxGroup_obj::__SetField(const ::String &inName,const Dynamic &inValue,bool inCallProp)
{
	return super::__SetField(inName,inValue,inCallProp);
}

void FlxGroup_obj::__GetFields(Array< ::String> &outFields)
{
	super::__GetFields(outFields);
};

static ::String sStaticFields[] = {
	String(null()) };

#if HXCPP_SCRIPTABLE
static hx::StorageInfo *sMemberStorageInfo = 0;
#endif

static ::String sMemberFields[] = {
	String(null()) };

static void sMarkStatics(HX_MARK_PARAMS) {
	HX_MARK_MEMBER_NAME(FlxGroup_obj::__mClass,"__mClass");
};

#ifdef HXCPP_VISIT_ALLOCS
static void sVisitStatics(HX_VISIT_PARAMS) {
	HX_VISIT_MEMBER_NAME(FlxGroup_obj::__mClass,"__mClass");
};

#endif

Class FlxGroup_obj::__mClass;

void FlxGroup_obj::__register()
{
	hx::Static(__mClass) = hx::RegisterClass(HX_CSTRING("flixel.group.FlxGroup"), hx::TCanCast< FlxGroup_obj> ,sStaticFields,sMemberFields,
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

void FlxGroup_obj::__boot()
{
}

} // end namespace flixel
} // end namespace group
