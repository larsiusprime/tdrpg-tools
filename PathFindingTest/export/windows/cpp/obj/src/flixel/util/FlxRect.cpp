#include <hxcpp.h>

#ifndef INCLUDED_flash_geom_Rectangle
#include <flash/geom/Rectangle.h>
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

Void FlxRect_obj::__construct(hx::Null< Float >  __o_X,hx::Null< Float >  __o_Y,hx::Null< Float >  __o_Width,hx::Null< Float >  __o_Height)
{
HX_STACK_FRAME("flixel.util.FlxRect","new",0xa3a9426e,"flixel.util.FlxRect.new","flixel/util/FlxRect.hx",37,0x4d61f922)

HX_STACK_ARG(__o_X,"X")

HX_STACK_ARG(__o_Y,"Y")

HX_STACK_ARG(__o_Width,"Width")

HX_STACK_ARG(__o_Height,"Height")
Float X = __o_X.Default(0);
Float Y = __o_Y.Default(0);
Float Width = __o_Width.Default(0);
Float Height = __o_Height.Default(0);
{
	HX_STACK_LINE(38)
	this->x = X;
	HX_STACK_LINE(39)
	this->y = Y;
	HX_STACK_LINE(40)
	this->width = Width;
	HX_STACK_LINE(41)
	this->height = Height;
}
;
	return null();
}

//FlxRect_obj::~FlxRect_obj() { }

Dynamic FlxRect_obj::__CreateEmpty() { return  new FlxRect_obj; }
hx::ObjectPtr< FlxRect_obj > FlxRect_obj::__new(hx::Null< Float >  __o_X,hx::Null< Float >  __o_Y,hx::Null< Float >  __o_Width,hx::Null< Float >  __o_Height)
{  hx::ObjectPtr< FlxRect_obj > result = new FlxRect_obj();
	result->__construct(__o_X,__o_Y,__o_Width,__o_Height);
	return result;}

Dynamic FlxRect_obj::__Create(hx::DynamicArray inArgs)
{  hx::ObjectPtr< FlxRect_obj > result = new FlxRect_obj();
	result->__construct(inArgs[0],inArgs[1],inArgs[2],inArgs[3]);
	return result;}

Void FlxRect_obj::setSize( Float Width,Float Height){
{
		HX_STACK_FRAME("flixel.util.FlxRect","setSize",0x416a7291,"flixel.util.FlxRect.setSize","flixel/util/FlxRect.hx",51,0x4d61f922)
		HX_STACK_THIS(this)
		HX_STACK_ARG(Width,"Width")
		HX_STACK_ARG(Height,"Height")
		HX_STACK_LINE(52)
		this->width = Width;
		HX_STACK_LINE(53)
		this->height = Height;
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC2(FlxRect_obj,setSize,(void))

Float FlxRect_obj::get_left( ){
	HX_STACK_FRAME("flixel.util.FlxRect","get_left",0x38171ec2,"flixel.util.FlxRect.get_left","flixel/util/FlxRect.hx",63,0x4d61f922)
	HX_STACK_THIS(this)
	HX_STACK_LINE(63)
	return this->x;
}


HX_DEFINE_DYNAMIC_FUNC0(FlxRect_obj,get_left,return )

Float FlxRect_obj::set_left( Float Value){
	HX_STACK_FRAME("flixel.util.FlxRect","set_left",0xe6747836,"flixel.util.FlxRect.set_left","flixel/util/FlxRect.hx",67,0x4d61f922)
	HX_STACK_THIS(this)
	HX_STACK_ARG(Value,"Value")
	HX_STACK_LINE(68)
	hx::SubEq(this->width,(Value - this->x));
	HX_STACK_LINE(69)
	return this->x = Value;
}


HX_DEFINE_DYNAMIC_FUNC1(FlxRect_obj,set_left,return )

Float FlxRect_obj::get_right( ){
	HX_STACK_FRAME("flixel.util.FlxRect","get_right",0x5330d8c1,"flixel.util.FlxRect.get_right","flixel/util/FlxRect.hx",79,0x4d61f922)
	HX_STACK_THIS(this)
	HX_STACK_LINE(79)
	return (this->x + this->width);
}


HX_DEFINE_DYNAMIC_FUNC0(FlxRect_obj,get_right,return )

Float FlxRect_obj::set_right( Float Value){
	HX_STACK_FRAME("flixel.util.FlxRect","set_right",0x3681c4cd,"flixel.util.FlxRect.set_right","flixel/util/FlxRect.hx",83,0x4d61f922)
	HX_STACK_THIS(this)
	HX_STACK_ARG(Value,"Value")
	HX_STACK_LINE(84)
	this->width = (Value - this->x);
	HX_STACK_LINE(85)
	return Value;
}


HX_DEFINE_DYNAMIC_FUNC1(FlxRect_obj,set_right,return )

Float FlxRect_obj::get_top( ){
	HX_STACK_FRAME("flixel.util.FlxRect","get_top",0x565fc03a,"flixel.util.FlxRect.get_top","flixel/util/FlxRect.hx",95,0x4d61f922)
	HX_STACK_THIS(this)
	HX_STACK_LINE(95)
	return this->y;
}


HX_DEFINE_DYNAMIC_FUNC0(FlxRect_obj,get_top,return )

Float FlxRect_obj::set_top( Float Value){
	HX_STACK_FRAME("flixel.util.FlxRect","set_top",0x49615146,"flixel.util.FlxRect.set_top","flixel/util/FlxRect.hx",99,0x4d61f922)
	HX_STACK_THIS(this)
	HX_STACK_ARG(Value,"Value")
	HX_STACK_LINE(100)
	hx::SubEq(this->height,(Value - this->y));
	HX_STACK_LINE(101)
	return this->y = Value;
}


HX_DEFINE_DYNAMIC_FUNC1(FlxRect_obj,set_top,return )

Float FlxRect_obj::get_bottom( ){
	HX_STACK_FRAME("flixel.util.FlxRect","get_bottom",0x8edf6266,"flixel.util.FlxRect.get_bottom","flixel/util/FlxRect.hx",111,0x4d61f922)
	HX_STACK_THIS(this)
	HX_STACK_LINE(111)
	return (this->y + this->height);
}


HX_DEFINE_DYNAMIC_FUNC0(FlxRect_obj,get_bottom,return )

Float FlxRect_obj::set_bottom( Float Value){
	HX_STACK_FRAME("flixel.util.FlxRect","set_bottom",0x925d00da,"flixel.util.FlxRect.set_bottom","flixel/util/FlxRect.hx",115,0x4d61f922)
	HX_STACK_THIS(this)
	HX_STACK_ARG(Value,"Value")
	HX_STACK_LINE(116)
	this->height = (Value - this->y);
	HX_STACK_LINE(117)
	return Value;
}


HX_DEFINE_DYNAMIC_FUNC1(FlxRect_obj,set_bottom,return )

::flixel::util::FlxRect FlxRect_obj::set( hx::Null< Float >  __o_X,hx::Null< Float >  __o_Y,hx::Null< Float >  __o_Width,hx::Null< Float >  __o_Height){
Float X = __o_X.Default(0);
Float Y = __o_Y.Default(0);
Float Width = __o_Width.Default(0);
Float Height = __o_Height.Default(0);
	HX_STACK_FRAME("flixel.util.FlxRect","set",0xa3ad0db0,"flixel.util.FlxRect.set","flixel/util/FlxRect.hx",130,0x4d61f922)
	HX_STACK_THIS(this)
	HX_STACK_ARG(X,"X")
	HX_STACK_ARG(Y,"Y")
	HX_STACK_ARG(Width,"Width")
	HX_STACK_ARG(Height,"Height")
{
		HX_STACK_LINE(131)
		this->x = X;
		HX_STACK_LINE(132)
		this->y = Y;
		HX_STACK_LINE(133)
		this->width = Width;
		HX_STACK_LINE(134)
		this->height = Height;
		HX_STACK_LINE(135)
		return hx::ObjectPtr<OBJ_>(this);
	}
}


HX_DEFINE_DYNAMIC_FUNC4(FlxRect_obj,set,return )

::flixel::util::FlxRect FlxRect_obj::copyFrom( ::flixel::util::FlxRect Rect){
	HX_STACK_FRAME("flixel.util.FlxRect","copyFrom",0x390d66f1,"flixel.util.FlxRect.copyFrom","flixel/util/FlxRect.hx",144,0x4d61f922)
	HX_STACK_THIS(this)
	HX_STACK_ARG(Rect,"Rect")
	HX_STACK_LINE(145)
	this->x = Rect->x;
	HX_STACK_LINE(146)
	this->y = Rect->y;
	HX_STACK_LINE(147)
	this->width = Rect->width;
	HX_STACK_LINE(148)
	this->height = Rect->height;
	HX_STACK_LINE(149)
	return hx::ObjectPtr<OBJ_>(this);
}


HX_DEFINE_DYNAMIC_FUNC1(FlxRect_obj,copyFrom,return )

::flixel::util::FlxRect FlxRect_obj::copyTo( ::flixel::util::FlxRect Rect){
	HX_STACK_FRAME("flixel.util.FlxRect","copyTo",0x8c91e742,"flixel.util.FlxRect.copyTo","flixel/util/FlxRect.hx",158,0x4d61f922)
	HX_STACK_THIS(this)
	HX_STACK_ARG(Rect,"Rect")
	HX_STACK_LINE(159)
	Rect->x = this->x;
	HX_STACK_LINE(160)
	Rect->y = this->y;
	HX_STACK_LINE(161)
	Rect->width = this->width;
	HX_STACK_LINE(162)
	Rect->height = this->height;
	HX_STACK_LINE(163)
	return Rect;
}


HX_DEFINE_DYNAMIC_FUNC1(FlxRect_obj,copyTo,return )

::flixel::util::FlxRect FlxRect_obj::copyFromFlash( ::flash::geom::Rectangle FlashRect){
	HX_STACK_FRAME("flixel.util.FlxRect","copyFromFlash",0x305c74ff,"flixel.util.FlxRect.copyFromFlash","flixel/util/FlxRect.hx",172,0x4d61f922)
	HX_STACK_THIS(this)
	HX_STACK_ARG(FlashRect,"FlashRect")
	HX_STACK_LINE(173)
	this->x = FlashRect->x;
	HX_STACK_LINE(174)
	this->y = FlashRect->y;
	HX_STACK_LINE(175)
	this->width = FlashRect->width;
	HX_STACK_LINE(176)
	this->height = FlashRect->height;
	HX_STACK_LINE(177)
	return hx::ObjectPtr<OBJ_>(this);
}


HX_DEFINE_DYNAMIC_FUNC1(FlxRect_obj,copyFromFlash,return )

::flash::geom::Rectangle FlxRect_obj::copyToFlash( ::flash::geom::Rectangle FlashRect){
	HX_STACK_FRAME("flixel.util.FlxRect","copyToFlash",0xaf702f0e,"flixel.util.FlxRect.copyToFlash","flixel/util/FlxRect.hx",186,0x4d61f922)
	HX_STACK_THIS(this)
	HX_STACK_ARG(FlashRect,"FlashRect")
	HX_STACK_LINE(187)
	FlashRect->x = this->x;
	HX_STACK_LINE(188)
	FlashRect->y = this->y;
	HX_STACK_LINE(189)
	FlashRect->width = this->width;
	HX_STACK_LINE(190)
	FlashRect->height = this->height;
	HX_STACK_LINE(191)
	return FlashRect;
}


HX_DEFINE_DYNAMIC_FUNC1(FlxRect_obj,copyToFlash,return )

bool FlxRect_obj::overlaps( ::flixel::util::FlxRect Rect){
	HX_STACK_FRAME("flixel.util.FlxRect","overlaps",0xb5d72e3e,"flixel.util.FlxRect.overlaps","flixel/util/FlxRect.hx",201,0x4d61f922)
	HX_STACK_THIS(this)
	HX_STACK_ARG(Rect,"Rect")
	HX_STACK_LINE(201)
	return (bool((bool((bool(((Rect->x + Rect->width) > this->x)) && bool((Rect->x < (this->x + this->width))))) && bool(((Rect->y + Rect->height) > this->y)))) && bool((Rect->y < (this->y + this->height))));
}


HX_DEFINE_DYNAMIC_FUNC1(FlxRect_obj,overlaps,return )

bool FlxRect_obj::containsFlxPoint( ::flixel::util::FlxPoint Point){
	HX_STACK_FRAME("flixel.util.FlxRect","containsFlxPoint",0x8d30acef,"flixel.util.FlxRect.containsFlxPoint","flixel/util/FlxRect.hx",212,0x4d61f922)
	HX_STACK_THIS(this)
	HX_STACK_ARG(Point,"Point")
	HX_STACK_LINE(212)
	return ::flixel::util::FlxMath_obj::pointInFlxRect(Point->x,Point->y,hx::ObjectPtr<OBJ_>(this));
}


HX_DEFINE_DYNAMIC_FUNC1(FlxRect_obj,containsFlxPoint,return )

::flixel::util::FlxRect FlxRect_obj::_union( ::flixel::util::FlxRect Rect){
	HX_STACK_FRAME("flixel.util.FlxRect","union",0xe007f69d,"flixel.util.FlxRect.union","flixel/util/FlxRect.hx",223,0x4d61f922)
	HX_STACK_THIS(this)
	HX_STACK_ARG(Rect,"Rect")
	HX_STACK_LINE(224)
	Float minX = ::Math_obj::min(this->x,Rect->x);		HX_STACK_VAR(minX,"minX");
	HX_STACK_LINE(225)
	Float minY = ::Math_obj::min(this->y,Rect->y);		HX_STACK_VAR(minY,"minY");
	HX_STACK_LINE(226)
	Float _g = this->get_right();		HX_STACK_VAR(_g,"_g");
	HX_STACK_LINE(226)
	Float maxX = ::Math_obj::max(_g,Rect->get_right());		HX_STACK_VAR(maxX,"maxX");
	HX_STACK_LINE(227)
	Float _g1 = this->get_bottom();		HX_STACK_VAR(_g1,"_g1");
	HX_STACK_LINE(227)
	Float maxY = ::Math_obj::max(_g1,Rect->get_bottom());		HX_STACK_VAR(maxY,"maxY");
	HX_STACK_LINE(229)
	this->x = minX;
	HX_STACK_LINE(229)
	this->y = minY;
	HX_STACK_LINE(229)
	this->width = (maxX - minX);
	HX_STACK_LINE(229)
	this->height = (maxY - minY);
	HX_STACK_LINE(229)
	return hx::ObjectPtr<OBJ_>(this);
}


HX_DEFINE_DYNAMIC_FUNC1(FlxRect_obj,_union,return )

::String FlxRect_obj::toString( ){
	HX_STACK_FRAME("flixel.util.FlxRect","toString",0xa91b2bde,"flixel.util.FlxRect.toString","flixel/util/FlxRect.hx",236,0x4d61f922)
	HX_STACK_THIS(this)
	struct _Function_1_1{
		inline static Dynamic Block( ::flixel::util::FlxRect_obj *__this){
			HX_STACK_FRAME("*","closure",0x5bdab937,"*.closure","flixel/util/FlxRect.hx",237,0x4d61f922)
			{
				hx::Anon __result = hx::Anon_obj::Create();
				__result->Add(HX_CSTRING("label") , HX_CSTRING("x"),false);
				__result->Add(HX_CSTRING("value") , __this->x,false);
				return __result;
			}
			return null();
		}
	};
	HX_STACK_LINE(237)
	Dynamic _g = _Function_1_1::Block(this);		HX_STACK_VAR(_g,"_g");
	struct _Function_1_2{
		inline static Dynamic Block( ::flixel::util::FlxRect_obj *__this){
			HX_STACK_FRAME("*","closure",0x5bdab937,"*.closure","flixel/util/FlxRect.hx",238,0x4d61f922)
			{
				hx::Anon __result = hx::Anon_obj::Create();
				__result->Add(HX_CSTRING("label") , HX_CSTRING("y"),false);
				__result->Add(HX_CSTRING("value") , __this->y,false);
				return __result;
			}
			return null();
		}
	};
	HX_STACK_LINE(238)
	Dynamic _g1 = _Function_1_2::Block(this);		HX_STACK_VAR(_g1,"_g1");
	struct _Function_1_3{
		inline static Dynamic Block( ::flixel::util::FlxRect_obj *__this){
			HX_STACK_FRAME("*","closure",0x5bdab937,"*.closure","flixel/util/FlxRect.hx",239,0x4d61f922)
			{
				hx::Anon __result = hx::Anon_obj::Create();
				__result->Add(HX_CSTRING("label") , HX_CSTRING("w"),false);
				__result->Add(HX_CSTRING("value") , __this->width,false);
				return __result;
			}
			return null();
		}
	};
	HX_STACK_LINE(239)
	Dynamic _g2 = _Function_1_3::Block(this);		HX_STACK_VAR(_g2,"_g2");
	struct _Function_1_4{
		inline static Dynamic Block( ::flixel::util::FlxRect_obj *__this){
			HX_STACK_FRAME("*","closure",0x5bdab937,"*.closure","flixel/util/FlxRect.hx",240,0x4d61f922)
			{
				hx::Anon __result = hx::Anon_obj::Create();
				__result->Add(HX_CSTRING("label") , HX_CSTRING("h"),false);
				__result->Add(HX_CSTRING("value") , __this->height,false);
				return __result;
			}
			return null();
		}
	};
	HX_STACK_LINE(237)
	return ::flixel::util::FlxStringUtil_obj::getDebugString(Dynamic( Array_obj<Dynamic>::__new().Add(_g).Add(_g1).Add(_g2).Add(_Function_1_4::Block(this))));
}


HX_DEFINE_DYNAMIC_FUNC0(FlxRect_obj,toString,return )


FlxRect_obj::FlxRect_obj()
{
}

Dynamic FlxRect_obj::__Field(const ::String &inName,bool inCallProp)
{
	switch(inName.length) {
	case 1:
		if (HX_FIELD_EQ(inName,"x") ) { return x; }
		if (HX_FIELD_EQ(inName,"y") ) { return y; }
		break;
	case 3:
		if (HX_FIELD_EQ(inName,"top") ) { return get_top(); }
		if (HX_FIELD_EQ(inName,"set") ) { return set_dyn(); }
		break;
	case 4:
		if (HX_FIELD_EQ(inName,"left") ) { return get_left(); }
		break;
	case 5:
		if (HX_FIELD_EQ(inName,"width") ) { return width; }
		if (HX_FIELD_EQ(inName,"right") ) { return get_right(); }
		if (HX_FIELD_EQ(inName,"union") ) { return _union_dyn(); }
		break;
	case 6:
		if (HX_FIELD_EQ(inName,"height") ) { return height; }
		if (HX_FIELD_EQ(inName,"bottom") ) { return get_bottom(); }
		if (HX_FIELD_EQ(inName,"copyTo") ) { return copyTo_dyn(); }
		break;
	case 7:
		if (HX_FIELD_EQ(inName,"setSize") ) { return setSize_dyn(); }
		if (HX_FIELD_EQ(inName,"get_top") ) { return get_top_dyn(); }
		if (HX_FIELD_EQ(inName,"set_top") ) { return set_top_dyn(); }
		break;
	case 8:
		if (HX_FIELD_EQ(inName,"get_left") ) { return get_left_dyn(); }
		if (HX_FIELD_EQ(inName,"set_left") ) { return set_left_dyn(); }
		if (HX_FIELD_EQ(inName,"copyFrom") ) { return copyFrom_dyn(); }
		if (HX_FIELD_EQ(inName,"overlaps") ) { return overlaps_dyn(); }
		if (HX_FIELD_EQ(inName,"toString") ) { return toString_dyn(); }
		break;
	case 9:
		if (HX_FIELD_EQ(inName,"get_right") ) { return get_right_dyn(); }
		if (HX_FIELD_EQ(inName,"set_right") ) { return set_right_dyn(); }
		break;
	case 10:
		if (HX_FIELD_EQ(inName,"get_bottom") ) { return get_bottom_dyn(); }
		if (HX_FIELD_EQ(inName,"set_bottom") ) { return set_bottom_dyn(); }
		break;
	case 11:
		if (HX_FIELD_EQ(inName,"copyToFlash") ) { return copyToFlash_dyn(); }
		break;
	case 13:
		if (HX_FIELD_EQ(inName,"copyFromFlash") ) { return copyFromFlash_dyn(); }
		break;
	case 16:
		if (HX_FIELD_EQ(inName,"containsFlxPoint") ) { return containsFlxPoint_dyn(); }
	}
	return super::__Field(inName,inCallProp);
}

Dynamic FlxRect_obj::__SetField(const ::String &inName,const Dynamic &inValue,bool inCallProp)
{
	switch(inName.length) {
	case 1:
		if (HX_FIELD_EQ(inName,"x") ) { x=inValue.Cast< Float >(); return inValue; }
		if (HX_FIELD_EQ(inName,"y") ) { y=inValue.Cast< Float >(); return inValue; }
		break;
	case 3:
		if (HX_FIELD_EQ(inName,"top") ) { return set_top(inValue); }
		break;
	case 4:
		if (HX_FIELD_EQ(inName,"left") ) { return set_left(inValue); }
		break;
	case 5:
		if (HX_FIELD_EQ(inName,"width") ) { width=inValue.Cast< Float >(); return inValue; }
		if (HX_FIELD_EQ(inName,"right") ) { return set_right(inValue); }
		break;
	case 6:
		if (HX_FIELD_EQ(inName,"height") ) { height=inValue.Cast< Float >(); return inValue; }
		if (HX_FIELD_EQ(inName,"bottom") ) { return set_bottom(inValue); }
	}
	return super::__SetField(inName,inValue,inCallProp);
}

void FlxRect_obj::__GetFields(Array< ::String> &outFields)
{
	outFields->push(HX_CSTRING("x"));
	outFields->push(HX_CSTRING("y"));
	outFields->push(HX_CSTRING("width"));
	outFields->push(HX_CSTRING("height"));
	outFields->push(HX_CSTRING("left"));
	outFields->push(HX_CSTRING("right"));
	outFields->push(HX_CSTRING("top"));
	outFields->push(HX_CSTRING("bottom"));
	super::__GetFields(outFields);
};

static ::String sStaticFields[] = {
	String(null()) };

#if HXCPP_SCRIPTABLE
static hx::StorageInfo sMemberStorageInfo[] = {
	{hx::fsFloat,(int)offsetof(FlxRect_obj,x),HX_CSTRING("x")},
	{hx::fsFloat,(int)offsetof(FlxRect_obj,y),HX_CSTRING("y")},
	{hx::fsFloat,(int)offsetof(FlxRect_obj,width),HX_CSTRING("width")},
	{hx::fsFloat,(int)offsetof(FlxRect_obj,height),HX_CSTRING("height")},
	{ hx::fsUnknown, 0, null()}
};
#endif

static ::String sMemberFields[] = {
	HX_CSTRING("x"),
	HX_CSTRING("y"),
	HX_CSTRING("width"),
	HX_CSTRING("height"),
	HX_CSTRING("setSize"),
	HX_CSTRING("get_left"),
	HX_CSTRING("set_left"),
	HX_CSTRING("get_right"),
	HX_CSTRING("set_right"),
	HX_CSTRING("get_top"),
	HX_CSTRING("set_top"),
	HX_CSTRING("get_bottom"),
	HX_CSTRING("set_bottom"),
	HX_CSTRING("set"),
	HX_CSTRING("copyFrom"),
	HX_CSTRING("copyTo"),
	HX_CSTRING("copyFromFlash"),
	HX_CSTRING("copyToFlash"),
	HX_CSTRING("overlaps"),
	HX_CSTRING("containsFlxPoint"),
	HX_CSTRING("union"),
	HX_CSTRING("toString"),
	String(null()) };

static void sMarkStatics(HX_MARK_PARAMS) {
	HX_MARK_MEMBER_NAME(FlxRect_obj::__mClass,"__mClass");
};

#ifdef HXCPP_VISIT_ALLOCS
static void sVisitStatics(HX_VISIT_PARAMS) {
	HX_VISIT_MEMBER_NAME(FlxRect_obj::__mClass,"__mClass");
};

#endif

Class FlxRect_obj::__mClass;

void FlxRect_obj::__register()
{
	hx::Static(__mClass) = hx::RegisterClass(HX_CSTRING("flixel.util.FlxRect"), hx::TCanCast< FlxRect_obj> ,sStaticFields,sMemberFields,
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

void FlxRect_obj::__boot()
{
}

} // end namespace flixel
} // end namespace util
