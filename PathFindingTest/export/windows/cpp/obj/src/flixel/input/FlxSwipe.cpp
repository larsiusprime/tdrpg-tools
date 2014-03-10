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
#ifndef INCLUDED_flixel_input_FlxSwipe
#include <flixel/input/FlxSwipe.h>
#endif
#ifndef INCLUDED_flixel_interfaces_IFlxDestroyable
#include <flixel/interfaces/IFlxDestroyable.h>
#endif
#ifndef INCLUDED_flixel_util_FlxAngle
#include <flixel/util/FlxAngle.h>
#endif
#ifndef INCLUDED_flixel_util_FlxPoint
#include <flixel/util/FlxPoint.h>
#endif
#ifndef INCLUDED_flixel_util_FlxStringUtil
#include <flixel/util/FlxStringUtil.h>
#endif
#ifndef INCLUDED_hxMath
#include <hxMath.h>
#endif
namespace flixel{
namespace input{

Void FlxSwipe_obj::__construct(int ID,::flixel::util::FlxPoint StartPosition,::flixel::util::FlxPoint EndPosition,Float StartTimeInTicks)
{
HX_STACK_FRAME("flixel.input.FlxSwipe","new",0xecc12d70,"flixel.input.FlxSwipe.new","flixel/input/FlxSwipe.hx",33,0xe38cac7e)

HX_STACK_ARG(ID,"ID")

HX_STACK_ARG(StartPosition,"StartPosition")

HX_STACK_ARG(EndPosition,"EndPosition")

HX_STACK_ARG(StartTimeInTicks,"StartTimeInTicks")
{
	HX_STACK_LINE(34)
	this->ID = ID;
	HX_STACK_LINE(35)
	this->startPosition = StartPosition;
	HX_STACK_LINE(36)
	this->endPosition = EndPosition;
	HX_STACK_LINE(37)
	this->_startTimeInTicks = StartTimeInTicks;
}
;
	return null();
}

//FlxSwipe_obj::~FlxSwipe_obj() { }

Dynamic FlxSwipe_obj::__CreateEmpty() { return  new FlxSwipe_obj; }
hx::ObjectPtr< FlxSwipe_obj > FlxSwipe_obj::__new(int ID,::flixel::util::FlxPoint StartPosition,::flixel::util::FlxPoint EndPosition,Float StartTimeInTicks)
{  hx::ObjectPtr< FlxSwipe_obj > result = new FlxSwipe_obj();
	result->__construct(ID,StartPosition,EndPosition,StartTimeInTicks);
	return result;}

Dynamic FlxSwipe_obj::__Create(hx::DynamicArray inArgs)
{  hx::ObjectPtr< FlxSwipe_obj > result = new FlxSwipe_obj();
	result->__construct(inArgs[0],inArgs[1],inArgs[2],inArgs[3]);
	return result;}

::String FlxSwipe_obj::toString( ){
	HX_STACK_FRAME("flixel.input.FlxSwipe","toString",0xb726199c,"flixel.input.FlxSwipe.toString","flixel/input/FlxSwipe.hx",41,0xe38cac7e)
	HX_STACK_THIS(this)
	struct _Function_1_1{
		inline static Dynamic Block( ::flixel::input::FlxSwipe_obj *__this){
			HX_STACK_FRAME("*","closure",0x5bdab937,"*.closure","flixel/input/FlxSwipe.hx",42,0xe38cac7e)
			{
				hx::Anon __result = hx::Anon_obj::Create();
				__result->Add(HX_CSTRING("label") , HX_CSTRING("ID"),false);
				__result->Add(HX_CSTRING("value") , __this->ID,false);
				return __result;
			}
			return null();
		}
	};
	HX_STACK_LINE(42)
	Dynamic _g = _Function_1_1::Block(this);		HX_STACK_VAR(_g,"_g");
	struct _Function_1_2{
		inline static Dynamic Block( ::flixel::input::FlxSwipe_obj *__this){
			HX_STACK_FRAME("*","closure",0x5bdab937,"*.closure","flixel/input/FlxSwipe.hx",43,0xe38cac7e)
			{
				hx::Anon __result = hx::Anon_obj::Create();
				__result->Add(HX_CSTRING("label") , HX_CSTRING("start"),false);
				__result->Add(HX_CSTRING("value") , __this->startPosition,false);
				return __result;
			}
			return null();
		}
	};
	HX_STACK_LINE(43)
	Dynamic _g1 = _Function_1_2::Block(this);		HX_STACK_VAR(_g1,"_g1");
	struct _Function_1_3{
		inline static Dynamic Block( ::flixel::input::FlxSwipe_obj *__this){
			HX_STACK_FRAME("*","closure",0x5bdab937,"*.closure","flixel/input/FlxSwipe.hx",44,0xe38cac7e)
			{
				hx::Anon __result = hx::Anon_obj::Create();
				__result->Add(HX_CSTRING("label") , HX_CSTRING("end"),false);
				__result->Add(HX_CSTRING("value") , __this->endPosition,false);
				return __result;
			}
			return null();
		}
	};
	HX_STACK_LINE(44)
	Dynamic _g2 = _Function_1_3::Block(this);		HX_STACK_VAR(_g2,"_g2");
	struct _Function_1_4{
		inline static Dynamic Block( ::flixel::input::FlxSwipe_obj *__this){
			HX_STACK_FRAME("*","closure",0x5bdab937,"*.closure","flixel/input/FlxSwipe.hx",45,0xe38cac7e)
			{
				hx::Anon __result = hx::Anon_obj::Create();
				__result->Add(HX_CSTRING("label") , HX_CSTRING("distance"),false);
				struct _Function_2_1{
					inline static Float Block( ::flixel::input::FlxSwipe_obj *__this){
						HX_STACK_FRAME("*","closure",0x5bdab937,"*.closure","flixel/input/FlxSwipe.hx",45,0xe38cac7e)
						{
							HX_STACK_LINE(45)
							Float dx = (__this->startPosition->x - __this->endPosition->x);		HX_STACK_VAR(dx,"dx");
							HX_STACK_LINE(45)
							Float dy = (__this->startPosition->y - __this->endPosition->y);		HX_STACK_VAR(dy,"dy");
							HX_STACK_LINE(45)
							return ::Math_obj::sqrt(((dx * dx) + (dy * dy)));
						}
						return null();
					}
				};
				__result->Add(HX_CSTRING("value") , _Function_2_1::Block(__this),false);
				return __result;
			}
			return null();
		}
	};
	HX_STACK_LINE(45)
	Dynamic _g3 = _Function_1_4::Block(this);		HX_STACK_VAR(_g3,"_g3");
	struct _Function_1_5{
		inline static Dynamic Block( ::flixel::input::FlxSwipe_obj *__this){
			HX_STACK_FRAME("*","closure",0x5bdab937,"*.closure","flixel/input/FlxSwipe.hx",46,0xe38cac7e)
			{
				hx::Anon __result = hx::Anon_obj::Create();
				__result->Add(HX_CSTRING("label") , HX_CSTRING("angle"),false);
				struct _Function_2_1{
					inline static Float Block( ::flixel::input::FlxSwipe_obj *__this){
						HX_STACK_FRAME("*","closure",0x5bdab937,"*.closure","flixel/input/FlxSwipe.hx",46,0xe38cac7e)
						{
							HX_STACK_LINE(46)
							::flixel::util::FlxPoint Point1 = __this->startPosition;		HX_STACK_VAR(Point1,"Point1");
							HX_STACK_LINE(46)
							::flixel::util::FlxPoint Point2 = __this->endPosition;		HX_STACK_VAR(Point2,"Point2");
							HX_STACK_LINE(46)
							Float x = (Point2->x - Point1->x);		HX_STACK_VAR(x,"x");
							HX_STACK_LINE(46)
							Float y = (Point2->y - Point1->y);		HX_STACK_VAR(y,"y");
							HX_STACK_LINE(46)
							Float angle = (int)0;		HX_STACK_VAR(angle,"angle");
							HX_STACK_LINE(46)
							if (((bool((x != (int)0)) || bool((y != (int)0))))){
								HX_STACK_LINE(46)
								Float c1 = (::Math_obj::PI * 0.25);		HX_STACK_VAR(c1,"c1");
								HX_STACK_LINE(46)
								Float c2 = ((int)3 * c1);		HX_STACK_VAR(c2,"c2");
								HX_STACK_LINE(46)
								Float ay;		HX_STACK_VAR(ay,"ay");
								HX_STACK_LINE(46)
								if (((y < (int)0))){
									HX_STACK_LINE(46)
									ay = -(y);
								}
								else{
									HX_STACK_LINE(46)
									ay = y;
								}
								HX_STACK_LINE(46)
								if (((x >= (int)0))){
									HX_STACK_LINE(46)
									angle = (c1 - (c1 * ((Float(((x - ay))) / Float(((x + ay)))))));
								}
								else{
									HX_STACK_LINE(46)
									angle = (c2 - (c1 * ((Float(((x + ay))) / Float(((ay - x)))))));
								}
								HX_STACK_LINE(46)
								angle = (((  (((y < (int)0))) ? Float(-(angle)) : Float(angle) )) * ::flixel::util::FlxAngle_obj::TO_DEG);
								HX_STACK_LINE(46)
								if (((angle > (int)90))){
									HX_STACK_LINE(46)
									angle = (angle - (int)270);
								}
								else{
									HX_STACK_LINE(46)
									hx::AddEq(angle,(int)90);
								}
							}
							HX_STACK_LINE(46)
							return angle;
						}
						return null();
					}
				};
				__result->Add(HX_CSTRING("value") , _Function_2_1::Block(__this),false);
				return __result;
			}
			return null();
		}
	};
	HX_STACK_LINE(46)
	Dynamic _g4 = _Function_1_5::Block(this);		HX_STACK_VAR(_g4,"_g4");
	struct _Function_1_6{
		inline static Dynamic Block( ::flixel::input::FlxSwipe_obj *__this){
			HX_STACK_FRAME("*","closure",0x5bdab937,"*.closure","flixel/input/FlxSwipe.hx",47,0xe38cac7e)
			{
				hx::Anon __result = hx::Anon_obj::Create();
				__result->Add(HX_CSTRING("label") , HX_CSTRING("duration"),false);
				__result->Add(HX_CSTRING("value") , (Float(((::flixel::FlxG_obj::game->ticks - __this->_startTimeInTicks))) / Float((int)1000)),false);
				return __result;
			}
			return null();
		}
	};
	HX_STACK_LINE(42)
	return ::flixel::util::FlxStringUtil_obj::getDebugString(Dynamic( Array_obj<Dynamic>::__new().Add(_g).Add(_g1).Add(_g2).Add(_g3).Add(_g4).Add(_Function_1_6::Block(this))));
}


HX_DEFINE_DYNAMIC_FUNC0(FlxSwipe_obj,toString,return )

Float FlxSwipe_obj::get_distance( ){
	HX_STACK_FRAME("flixel.input.FlxSwipe","get_distance",0xd139c82e,"flixel.input.FlxSwipe.get_distance","flixel/input/FlxSwipe.hx",52,0xe38cac7e)
	HX_STACK_THIS(this)
	HX_STACK_LINE(52)
	Float dx = (this->startPosition->x - this->endPosition->x);		HX_STACK_VAR(dx,"dx");
	HX_STACK_LINE(52)
	Float dy = (this->startPosition->y - this->endPosition->y);		HX_STACK_VAR(dy,"dy");
	HX_STACK_LINE(52)
	return ::Math_obj::sqrt(((dx * dx) + (dy * dy)));
}


HX_DEFINE_DYNAMIC_FUNC0(FlxSwipe_obj,get_distance,return )

Float FlxSwipe_obj::get_angle( ){
	HX_STACK_FRAME("flixel.input.FlxSwipe","get_angle",0xc834293a,"flixel.input.FlxSwipe.get_angle","flixel/input/FlxSwipe.hx",57,0xe38cac7e)
	HX_STACK_THIS(this)
	HX_STACK_LINE(57)
	::flixel::util::FlxPoint Point1 = this->startPosition;		HX_STACK_VAR(Point1,"Point1");
	HX_STACK_LINE(57)
	::flixel::util::FlxPoint Point2 = this->endPosition;		HX_STACK_VAR(Point2,"Point2");
	HX_STACK_LINE(57)
	Float x = (Point2->x - Point1->x);		HX_STACK_VAR(x,"x");
	HX_STACK_LINE(57)
	Float y = (Point2->y - Point1->y);		HX_STACK_VAR(y,"y");
	HX_STACK_LINE(57)
	Float angle = (int)0;		HX_STACK_VAR(angle,"angle");
	HX_STACK_LINE(57)
	if (((bool((x != (int)0)) || bool((y != (int)0))))){
		HX_STACK_LINE(57)
		Float c1 = (::Math_obj::PI * 0.25);		HX_STACK_VAR(c1,"c1");
		HX_STACK_LINE(57)
		Float c2 = ((int)3 * c1);		HX_STACK_VAR(c2,"c2");
		HX_STACK_LINE(57)
		Float ay;		HX_STACK_VAR(ay,"ay");
		HX_STACK_LINE(57)
		if (((y < (int)0))){
			HX_STACK_LINE(57)
			ay = -(y);
		}
		else{
			HX_STACK_LINE(57)
			ay = y;
		}
		HX_STACK_LINE(57)
		if (((x >= (int)0))){
			HX_STACK_LINE(57)
			angle = (c1 - (c1 * ((Float(((x - ay))) / Float(((x + ay)))))));
		}
		else{
			HX_STACK_LINE(57)
			angle = (c2 - (c1 * ((Float(((x + ay))) / Float(((ay - x)))))));
		}
		HX_STACK_LINE(57)
		angle = (((  (((y < (int)0))) ? Float(-(angle)) : Float(angle) )) * ::flixel::util::FlxAngle_obj::TO_DEG);
		HX_STACK_LINE(57)
		if (((angle > (int)90))){
			HX_STACK_LINE(57)
			angle = (angle - (int)270);
		}
		else{
			HX_STACK_LINE(57)
			hx::AddEq(angle,(int)90);
		}
	}
	HX_STACK_LINE(57)
	return angle;
}


HX_DEFINE_DYNAMIC_FUNC0(FlxSwipe_obj,get_angle,return )

Float FlxSwipe_obj::get_duration( ){
	HX_STACK_FRAME("flixel.input.FlxSwipe","get_duration",0x79ce444d,"flixel.input.FlxSwipe.get_duration","flixel/input/FlxSwipe.hx",62,0xe38cac7e)
	HX_STACK_THIS(this)
	HX_STACK_LINE(62)
	return (::flixel::FlxG_obj::game->ticks - this->_startTimeInTicks);
}


HX_DEFINE_DYNAMIC_FUNC0(FlxSwipe_obj,get_duration,return )


FlxSwipe_obj::FlxSwipe_obj()
{
}

void FlxSwipe_obj::__Mark(HX_MARK_PARAMS)
{
	HX_MARK_BEGIN_CLASS(FlxSwipe);
	HX_MARK_MEMBER_NAME(ID,"ID");
	HX_MARK_MEMBER_NAME(startPosition,"startPosition");
	HX_MARK_MEMBER_NAME(endPosition,"endPosition");
	HX_MARK_MEMBER_NAME(_startTimeInTicks,"_startTimeInTicks");
	HX_MARK_END_CLASS();
}

void FlxSwipe_obj::__Visit(HX_VISIT_PARAMS)
{
	HX_VISIT_MEMBER_NAME(ID,"ID");
	HX_VISIT_MEMBER_NAME(startPosition,"startPosition");
	HX_VISIT_MEMBER_NAME(endPosition,"endPosition");
	HX_VISIT_MEMBER_NAME(_startTimeInTicks,"_startTimeInTicks");
}

Dynamic FlxSwipe_obj::__Field(const ::String &inName,bool inCallProp)
{
	switch(inName.length) {
	case 2:
		if (HX_FIELD_EQ(inName,"ID") ) { return ID; }
		break;
	case 5:
		if (HX_FIELD_EQ(inName,"angle") ) { return get_angle(); }
		break;
	case 8:
		if (HX_FIELD_EQ(inName,"distance") ) { return get_distance(); }
		if (HX_FIELD_EQ(inName,"duration") ) { return get_duration(); }
		if (HX_FIELD_EQ(inName,"toString") ) { return toString_dyn(); }
		break;
	case 9:
		if (HX_FIELD_EQ(inName,"get_angle") ) { return get_angle_dyn(); }
		break;
	case 11:
		if (HX_FIELD_EQ(inName,"endPosition") ) { return endPosition; }
		break;
	case 12:
		if (HX_FIELD_EQ(inName,"get_distance") ) { return get_distance_dyn(); }
		if (HX_FIELD_EQ(inName,"get_duration") ) { return get_duration_dyn(); }
		break;
	case 13:
		if (HX_FIELD_EQ(inName,"startPosition") ) { return startPosition; }
		break;
	case 17:
		if (HX_FIELD_EQ(inName,"_startTimeInTicks") ) { return _startTimeInTicks; }
	}
	return super::__Field(inName,inCallProp);
}

Dynamic FlxSwipe_obj::__SetField(const ::String &inName,const Dynamic &inValue,bool inCallProp)
{
	switch(inName.length) {
	case 2:
		if (HX_FIELD_EQ(inName,"ID") ) { ID=inValue.Cast< int >(); return inValue; }
		break;
	case 11:
		if (HX_FIELD_EQ(inName,"endPosition") ) { endPosition=inValue.Cast< ::flixel::util::FlxPoint >(); return inValue; }
		break;
	case 13:
		if (HX_FIELD_EQ(inName,"startPosition") ) { startPosition=inValue.Cast< ::flixel::util::FlxPoint >(); return inValue; }
		break;
	case 17:
		if (HX_FIELD_EQ(inName,"_startTimeInTicks") ) { _startTimeInTicks=inValue.Cast< Float >(); return inValue; }
	}
	return super::__SetField(inName,inValue,inCallProp);
}

void FlxSwipe_obj::__GetFields(Array< ::String> &outFields)
{
	outFields->push(HX_CSTRING("ID"));
	outFields->push(HX_CSTRING("startPosition"));
	outFields->push(HX_CSTRING("endPosition"));
	outFields->push(HX_CSTRING("distance"));
	outFields->push(HX_CSTRING("angle"));
	outFields->push(HX_CSTRING("duration"));
	outFields->push(HX_CSTRING("_startTimeInTicks"));
	super::__GetFields(outFields);
};

static ::String sStaticFields[] = {
	String(null()) };

#if HXCPP_SCRIPTABLE
static hx::StorageInfo sMemberStorageInfo[] = {
	{hx::fsInt,(int)offsetof(FlxSwipe_obj,ID),HX_CSTRING("ID")},
	{hx::fsObject /*::flixel::util::FlxPoint*/ ,(int)offsetof(FlxSwipe_obj,startPosition),HX_CSTRING("startPosition")},
	{hx::fsObject /*::flixel::util::FlxPoint*/ ,(int)offsetof(FlxSwipe_obj,endPosition),HX_CSTRING("endPosition")},
	{hx::fsFloat,(int)offsetof(FlxSwipe_obj,_startTimeInTicks),HX_CSTRING("_startTimeInTicks")},
	{ hx::fsUnknown, 0, null()}
};
#endif

static ::String sMemberFields[] = {
	HX_CSTRING("ID"),
	HX_CSTRING("startPosition"),
	HX_CSTRING("endPosition"),
	HX_CSTRING("_startTimeInTicks"),
	HX_CSTRING("toString"),
	HX_CSTRING("get_distance"),
	HX_CSTRING("get_angle"),
	HX_CSTRING("get_duration"),
	String(null()) };

static void sMarkStatics(HX_MARK_PARAMS) {
	HX_MARK_MEMBER_NAME(FlxSwipe_obj::__mClass,"__mClass");
};

#ifdef HXCPP_VISIT_ALLOCS
static void sVisitStatics(HX_VISIT_PARAMS) {
	HX_VISIT_MEMBER_NAME(FlxSwipe_obj::__mClass,"__mClass");
};

#endif

Class FlxSwipe_obj::__mClass;

void FlxSwipe_obj::__register()
{
	hx::Static(__mClass) = hx::RegisterClass(HX_CSTRING("flixel.input.FlxSwipe"), hx::TCanCast< FlxSwipe_obj> ,sStaticFields,sMemberFields,
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

void FlxSwipe_obj::__boot()
{
}

} // end namespace flixel
} // end namespace input
