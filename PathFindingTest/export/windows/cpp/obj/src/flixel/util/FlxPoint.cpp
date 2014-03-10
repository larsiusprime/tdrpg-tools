#include <hxcpp.h>

#ifndef INCLUDED_flash_geom_Point
#include <flash/geom/Point.h>
#endif
#ifndef INCLUDED_flixel_interfaces_IFlxDestroyable
#include <flixel/interfaces/IFlxDestroyable.h>
#endif
#ifndef INCLUDED_flixel_util_FlxMath
#include <flixel/util/FlxMath.h>
#endif
#ifndef INCLUDED_flixel_util_FlxPoint
#include <flixel/util/FlxPoint.h>
#endif
#ifndef INCLUDED_flixel_util_FlxRect
#include <flixel/util/FlxRect.h>
#endif
#ifndef INCLUDED_flixel_util_FlxStringUtil
#include <flixel/util/FlxStringUtil.h>
#endif
#ifndef INCLUDED_hxMath
#include <hxMath.h>
#endif
namespace flixel{
namespace util{

Void FlxPoint_obj::__construct(hx::Null< Float >  __o_X,hx::Null< Float >  __o_Y)
{
HX_STACK_FRAME("flixel.util.FlxPoint","new",0xdda8d7ea,"flixel.util.FlxPoint.new","flixel/util/FlxPoint.hx",10,0xb59f5266)

HX_STACK_ARG(__o_X,"X")

HX_STACK_ARG(__o_Y,"Y")
Float X = __o_X.Default(0);
Float Y = __o_Y.Default(0);
{
	HX_STACK_LINE(25)
	this->y = (int)0;
	HX_STACK_LINE(15)
	this->x = (int)0;
	HX_STACK_LINE(39)
	this->set_x(X);
	HX_STACK_LINE(40)
	this->set_y(Y);
}
;
	return null();
}

//FlxPoint_obj::~FlxPoint_obj() { }

Dynamic FlxPoint_obj::__CreateEmpty() { return  new FlxPoint_obj; }
hx::ObjectPtr< FlxPoint_obj > FlxPoint_obj::__new(hx::Null< Float >  __o_X,hx::Null< Float >  __o_Y)
{  hx::ObjectPtr< FlxPoint_obj > result = new FlxPoint_obj();
	result->__construct(__o_X,__o_Y);
	return result;}

Dynamic FlxPoint_obj::__Create(hx::DynamicArray inArgs)
{  hx::ObjectPtr< FlxPoint_obj > result = new FlxPoint_obj();
	result->__construct(inArgs[0],inArgs[1]);
	return result;}

hx::Object *FlxPoint_obj::__ToInterface(const hx::type_info &inType) {
	if (inType==typeid( ::flixel::interfaces::IFlxDestroyable_obj)) return operator ::flixel::interfaces::IFlxDestroyable_obj *();
	return super::__ToInterface(inType);
}

Float FlxPoint_obj::set_x( Float Value){
	HX_STACK_FRAME("flixel.util.FlxPoint","set_x",0x1c7d1965,"flixel.util.FlxPoint.set_x","flixel/util/FlxPoint.hx",19,0xb59f5266)
	HX_STACK_THIS(this)
	HX_STACK_ARG(Value,"Value")
	HX_STACK_LINE(19)
	return this->x = Value;
}


HX_DEFINE_DYNAMIC_FUNC1(FlxPoint_obj,set_x,return )

Float FlxPoint_obj::set_y( Float Value){
	HX_STACK_FRAME("flixel.util.FlxPoint","set_y",0x1c7d1966,"flixel.util.FlxPoint.set_y","flixel/util/FlxPoint.hx",29,0xb59f5266)
	HX_STACK_THIS(this)
	HX_STACK_ARG(Value,"Value")
	HX_STACK_LINE(29)
	return this->y = Value;
}


HX_DEFINE_DYNAMIC_FUNC1(FlxPoint_obj,set_y,return )

::flixel::util::FlxPoint FlxPoint_obj::set( hx::Null< Float >  __o_X,hx::Null< Float >  __o_Y){
Float X = __o_X.Default(0);
Float Y = __o_Y.Default(0);
	HX_STACK_FRAME("flixel.util.FlxPoint","set",0xddaca32c,"flixel.util.FlxPoint.set","flixel/util/FlxPoint.hx",49,0xb59f5266)
	HX_STACK_THIS(this)
	HX_STACK_ARG(X,"X")
	HX_STACK_ARG(Y,"Y")
{
		HX_STACK_LINE(50)
		this->set_x(X);
		HX_STACK_LINE(51)
		this->set_y(Y);
		HX_STACK_LINE(52)
		return hx::ObjectPtr<OBJ_>(this);
	}
}


HX_DEFINE_DYNAMIC_FUNC2(FlxPoint_obj,set,return )

::flixel::util::FlxPoint FlxPoint_obj::copyFrom( ::flixel::util::FlxPoint point){
	HX_STACK_FRAME("flixel.util.FlxPoint","copyFrom",0x23b26ff5,"flixel.util.FlxPoint.copyFrom","flixel/util/FlxPoint.hx",61,0xb59f5266)
	HX_STACK_THIS(this)
	HX_STACK_ARG(point,"point")
	HX_STACK_LINE(62)
	this->set_x(point->x);
	HX_STACK_LINE(63)
	this->set_y(point->y);
	HX_STACK_LINE(64)
	return hx::ObjectPtr<OBJ_>(this);
}


HX_DEFINE_DYNAMIC_FUNC1(FlxPoint_obj,copyFrom,return )

::flixel::util::FlxPoint FlxPoint_obj::copyTo( ::flixel::util::FlxPoint point){
	HX_STACK_FRAME("flixel.util.FlxPoint","copyTo",0x2ab3e746,"flixel.util.FlxPoint.copyTo","flixel/util/FlxPoint.hx",73,0xb59f5266)
	HX_STACK_THIS(this)
	HX_STACK_ARG(point,"point")
	HX_STACK_LINE(74)
	if (((point == null()))){
		HX_STACK_LINE(76)
		point = ::flixel::util::FlxPoint_obj::__new(null(),null());
	}
	HX_STACK_LINE(78)
	point->set_x(this->x);
	HX_STACK_LINE(79)
	point->set_y(this->y);
	HX_STACK_LINE(80)
	return point;
}


HX_DEFINE_DYNAMIC_FUNC1(FlxPoint_obj,copyTo,return )

::flixel::util::FlxPoint FlxPoint_obj::copyFromFlash( ::flash::geom::Point FlashPoint){
	HX_STACK_FRAME("flixel.util.FlxPoint","copyFromFlash",0x5f443d7b,"flixel.util.FlxPoint.copyFromFlash","flixel/util/FlxPoint.hx",89,0xb59f5266)
	HX_STACK_THIS(this)
	HX_STACK_ARG(FlashPoint,"FlashPoint")
	HX_STACK_LINE(90)
	this->set_x(FlashPoint->x);
	HX_STACK_LINE(91)
	this->set_y(FlashPoint->y);
	HX_STACK_LINE(92)
	return hx::ObjectPtr<OBJ_>(this);
}


HX_DEFINE_DYNAMIC_FUNC1(FlxPoint_obj,copyFromFlash,return )

::flash::geom::Point FlxPoint_obj::copyToFlash( ::flash::geom::Point FlashPoint){
	HX_STACK_FRAME("flixel.util.FlxPoint","copyToFlash",0x2f7ba08a,"flixel.util.FlxPoint.copyToFlash","flixel/util/FlxPoint.hx",101,0xb59f5266)
	HX_STACK_THIS(this)
	HX_STACK_ARG(FlashPoint,"FlashPoint")
	HX_STACK_LINE(102)
	FlashPoint->x = this->x;
	HX_STACK_LINE(103)
	FlashPoint->y = this->y;
	HX_STACK_LINE(104)
	return FlashPoint;
}


HX_DEFINE_DYNAMIC_FUNC1(FlxPoint_obj,copyToFlash,return )

bool FlxPoint_obj::inCoords( Float RectX,Float RectY,Float RectWidth,Float RectHeight){
	HX_STACK_FRAME("flixel.util.FlxPoint","inCoords",0xac545219,"flixel.util.FlxPoint.inCoords","flixel/util/FlxPoint.hx",118,0xb59f5266)
	HX_STACK_THIS(this)
	HX_STACK_ARG(RectX,"RectX")
	HX_STACK_ARG(RectY,"RectY")
	HX_STACK_ARG(RectWidth,"RectWidth")
	HX_STACK_ARG(RectHeight,"RectHeight")
	HX_STACK_LINE(118)
	return ::flixel::util::FlxMath_obj::pointInCoordinates(this->x,this->y,RectX,RectY,RectWidth,RectHeight);
}


HX_DEFINE_DYNAMIC_FUNC4(FlxPoint_obj,inCoords,return )

bool FlxPoint_obj::inFlxRect( ::flixel::util::FlxRect Rect){
	HX_STACK_FRAME("flixel.util.FlxPoint","inFlxRect",0x8096ec5b,"flixel.util.FlxPoint.inFlxRect","flixel/util/FlxPoint.hx",129,0xb59f5266)
	HX_STACK_THIS(this)
	HX_STACK_ARG(Rect,"Rect")
	HX_STACK_LINE(129)
	return ::flixel::util::FlxMath_obj::pointInFlxRect(this->x,this->y,Rect);
}


HX_DEFINE_DYNAMIC_FUNC1(FlxPoint_obj,inFlxRect,return )

Float FlxPoint_obj::distanceTo( ::flixel::util::FlxPoint AnotherPoint){
	HX_STACK_FRAME("flixel.util.FlxPoint","distanceTo",0x698831c6,"flixel.util.FlxPoint.distanceTo","flixel/util/FlxPoint.hx",140,0xb59f5266)
	HX_STACK_THIS(this)
	HX_STACK_ARG(AnotherPoint,"AnotherPoint")
	HX_STACK_LINE(140)
	Float dx = (this->x - AnotherPoint->x);		HX_STACK_VAR(dx,"dx");
	HX_STACK_LINE(140)
	Float dy = (this->y - AnotherPoint->y);		HX_STACK_VAR(dy,"dy");
	HX_STACK_LINE(140)
	return ::Math_obj::sqrt(((dx * dx) + (dy * dy)));
}


HX_DEFINE_DYNAMIC_FUNC1(FlxPoint_obj,distanceTo,return )

Void FlxPoint_obj::destroy( ){
{
		HX_STACK_FRAME("flixel.util.FlxPoint","destroy",0x13b6c184,"flixel.util.FlxPoint.destroy","flixel/util/FlxPoint.hx",143,0xb59f5266)
		HX_STACK_THIS(this)
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC0(FlxPoint_obj,destroy,(void))

::String FlxPoint_obj::toString( ){
	HX_STACK_FRAME("flixel.util.FlxPoint","toString",0x93c034e2,"flixel.util.FlxPoint.toString","flixel/util/FlxPoint.hx",149,0xb59f5266)
	HX_STACK_THIS(this)
	struct _Function_1_1{
		inline static Dynamic Block( ::flixel::util::FlxPoint_obj *__this){
			HX_STACK_FRAME("*","closure",0x5bdab937,"*.closure","flixel/util/FlxPoint.hx",150,0xb59f5266)
			{
				hx::Anon __result = hx::Anon_obj::Create();
				__result->Add(HX_CSTRING("label") , HX_CSTRING("x"),false);
				__result->Add(HX_CSTRING("value") , __this->x,false);
				return __result;
			}
			return null();
		}
	};
	HX_STACK_LINE(150)
	Dynamic _g = _Function_1_1::Block(this);		HX_STACK_VAR(_g,"_g");
	struct _Function_1_2{
		inline static Dynamic Block( ::flixel::util::FlxPoint_obj *__this){
			HX_STACK_FRAME("*","closure",0x5bdab937,"*.closure","flixel/util/FlxPoint.hx",151,0xb59f5266)
			{
				hx::Anon __result = hx::Anon_obj::Create();
				__result->Add(HX_CSTRING("label") , HX_CSTRING("y"),false);
				__result->Add(HX_CSTRING("value") , __this->y,false);
				return __result;
			}
			return null();
		}
	};
	HX_STACK_LINE(150)
	return ::flixel::util::FlxStringUtil_obj::getDebugString(Dynamic( Array_obj<Dynamic>::__new().Add(_g).Add(_Function_1_2::Block(this))));
}


HX_DEFINE_DYNAMIC_FUNC0(FlxPoint_obj,toString,return )


FlxPoint_obj::FlxPoint_obj()
{
}

Dynamic FlxPoint_obj::__Field(const ::String &inName,bool inCallProp)
{
	switch(inName.length) {
	case 1:
		if (HX_FIELD_EQ(inName,"x") ) { return x; }
		if (HX_FIELD_EQ(inName,"y") ) { return y; }
		break;
	case 3:
		if (HX_FIELD_EQ(inName,"set") ) { return set_dyn(); }
		break;
	case 5:
		if (HX_FIELD_EQ(inName,"set_x") ) { return set_x_dyn(); }
		if (HX_FIELD_EQ(inName,"set_y") ) { return set_y_dyn(); }
		break;
	case 6:
		if (HX_FIELD_EQ(inName,"copyTo") ) { return copyTo_dyn(); }
		break;
	case 7:
		if (HX_FIELD_EQ(inName,"destroy") ) { return destroy_dyn(); }
		break;
	case 8:
		if (HX_FIELD_EQ(inName,"copyFrom") ) { return copyFrom_dyn(); }
		if (HX_FIELD_EQ(inName,"inCoords") ) { return inCoords_dyn(); }
		if (HX_FIELD_EQ(inName,"toString") ) { return toString_dyn(); }
		break;
	case 9:
		if (HX_FIELD_EQ(inName,"inFlxRect") ) { return inFlxRect_dyn(); }
		break;
	case 10:
		if (HX_FIELD_EQ(inName,"distanceTo") ) { return distanceTo_dyn(); }
		break;
	case 11:
		if (HX_FIELD_EQ(inName,"copyToFlash") ) { return copyToFlash_dyn(); }
		break;
	case 13:
		if (HX_FIELD_EQ(inName,"copyFromFlash") ) { return copyFromFlash_dyn(); }
	}
	return super::__Field(inName,inCallProp);
}

Dynamic FlxPoint_obj::__SetField(const ::String &inName,const Dynamic &inValue,bool inCallProp)
{
	switch(inName.length) {
	case 1:
		if (HX_FIELD_EQ(inName,"x") ) { if (inCallProp) return set_x(inValue);x=inValue.Cast< Float >(); return inValue; }
		if (HX_FIELD_EQ(inName,"y") ) { if (inCallProp) return set_y(inValue);y=inValue.Cast< Float >(); return inValue; }
	}
	return super::__SetField(inName,inValue,inCallProp);
}

void FlxPoint_obj::__GetFields(Array< ::String> &outFields)
{
	outFields->push(HX_CSTRING("x"));
	outFields->push(HX_CSTRING("y"));
	super::__GetFields(outFields);
};

static ::String sStaticFields[] = {
	String(null()) };

#if HXCPP_SCRIPTABLE
static hx::StorageInfo sMemberStorageInfo[] = {
	{hx::fsFloat,(int)offsetof(FlxPoint_obj,x),HX_CSTRING("x")},
	{hx::fsFloat,(int)offsetof(FlxPoint_obj,y),HX_CSTRING("y")},
	{ hx::fsUnknown, 0, null()}
};
#endif

static ::String sMemberFields[] = {
	HX_CSTRING("x"),
	HX_CSTRING("set_x"),
	HX_CSTRING("y"),
	HX_CSTRING("set_y"),
	HX_CSTRING("set"),
	HX_CSTRING("copyFrom"),
	HX_CSTRING("copyTo"),
	HX_CSTRING("copyFromFlash"),
	HX_CSTRING("copyToFlash"),
	HX_CSTRING("inCoords"),
	HX_CSTRING("inFlxRect"),
	HX_CSTRING("distanceTo"),
	HX_CSTRING("destroy"),
	HX_CSTRING("toString"),
	String(null()) };

static void sMarkStatics(HX_MARK_PARAMS) {
	HX_MARK_MEMBER_NAME(FlxPoint_obj::__mClass,"__mClass");
};

#ifdef HXCPP_VISIT_ALLOCS
static void sVisitStatics(HX_VISIT_PARAMS) {
	HX_VISIT_MEMBER_NAME(FlxPoint_obj::__mClass,"__mClass");
};

#endif

Class FlxPoint_obj::__mClass;

void FlxPoint_obj::__register()
{
	hx::Static(__mClass) = hx::RegisterClass(HX_CSTRING("flixel.util.FlxPoint"), hx::TCanCast< FlxPoint_obj> ,sStaticFields,sMemberFields,
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

void FlxPoint_obj::__boot()
{
}

} // end namespace flixel
} // end namespace util
