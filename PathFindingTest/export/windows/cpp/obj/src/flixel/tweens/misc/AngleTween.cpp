#include <hxcpp.h>

#ifndef INCLUDED_flixel_FlxBasic
#include <flixel/FlxBasic.h>
#endif
#ifndef INCLUDED_flixel_FlxObject
#include <flixel/FlxObject.h>
#endif
#ifndef INCLUDED_flixel_FlxSprite
#include <flixel/FlxSprite.h>
#endif
#ifndef INCLUDED_flixel_interfaces_IFlxDestroyable
#include <flixel/interfaces/IFlxDestroyable.h>
#endif
#ifndef INCLUDED_flixel_tweens_FlxTween
#include <flixel/tweens/FlxTween.h>
#endif
#ifndef INCLUDED_flixel_tweens_misc_AngleTween
#include <flixel/tweens/misc/AngleTween.h>
#endif
#ifndef INCLUDED_flixel_util_FlxRandom
#include <flixel/util/FlxRandom.h>
#endif
#ifndef INCLUDED_hxMath
#include <hxMath.h>
#endif
namespace flixel{
namespace tweens{
namespace misc{

Void AngleTween_obj::__construct(Dynamic Complete,hx::Null< int >  __o_type)
{
HX_STACK_FRAME("flixel.tweens.misc.AngleTween","new",0x28853ef8,"flixel.tweens.misc.AngleTween.new","flixel/tweens/misc/AngleTween.hx",11,0x989494f7)

HX_STACK_ARG(Complete,"Complete")

HX_STACK_ARG(__o_type,"type")
int type = __o_type.Default(0);
{
	HX_STACK_LINE(13)
	this->angle = (int)0;
	HX_STACK_LINE(29)
	super::__construct((int)0,type,Complete,null());
}
;
	return null();
}

//AngleTween_obj::~AngleTween_obj() { }

Dynamic AngleTween_obj::__CreateEmpty() { return  new AngleTween_obj; }
hx::ObjectPtr< AngleTween_obj > AngleTween_obj::__new(Dynamic Complete,hx::Null< int >  __o_type)
{  hx::ObjectPtr< AngleTween_obj > result = new AngleTween_obj();
	result->__construct(Complete,__o_type);
	return result;}

Dynamic AngleTween_obj::__Create(hx::DynamicArray inArgs)
{  hx::ObjectPtr< AngleTween_obj > result = new AngleTween_obj();
	result->__construct(inArgs[0],inArgs[1]);
	return result;}

::flixel::tweens::misc::AngleTween AngleTween_obj::tween( Float FromAngle,Float ToAngle,Float Duration,Dynamic Ease,::flixel::FlxSprite Sprite){
	HX_STACK_FRAME("flixel.tweens.misc.AngleTween","tween",0xc3ccef03,"flixel.tweens.misc.AngleTween.tween","flixel/tweens/misc/AngleTween.hx",41,0x989494f7)
	HX_STACK_THIS(this)
	HX_STACK_ARG(FromAngle,"FromAngle")
	HX_STACK_ARG(ToAngle,"ToAngle")
	HX_STACK_ARG(Duration,"Duration")
	HX_STACK_ARG(Ease,"Ease")
	HX_STACK_ARG(Sprite,"Sprite")
	HX_STACK_LINE(42)
	this->_start = this->angle = FromAngle;
	HX_STACK_LINE(43)
	Float d = (ToAngle - this->angle);		HX_STACK_VAR(d,"d");
	HX_STACK_LINE(44)
	Float a = ::Math_obj::abs(d);		HX_STACK_VAR(a,"a");
	HX_STACK_LINE(45)
	if (((a > (int)181))){
		HX_STACK_LINE(47)
		this->_range = ((((int)360 - a)) * ((  (((d > (int)0))) ? int((int)-1) : int((int)1) )));
	}
	else{
		HX_STACK_LINE(49)
		if (((a < (int)179))){
			HX_STACK_LINE(51)
			this->_range = d;
		}
		else{
			HX_STACK_LINE(55)
			this->_range = ::flixel::util::FlxRandom_obj::floatRanged((int)180,(int)-180,null());
		}
	}
	HX_STACK_LINE(57)
	this->duration = Duration;
	HX_STACK_LINE(58)
	this->ease = Ease;
	HX_STACK_LINE(59)
	this->sprite = Sprite;
	HX_STACK_LINE(60)
	this->start();
	HX_STACK_LINE(61)
	return hx::ObjectPtr<OBJ_>(this);
}


HX_DEFINE_DYNAMIC_FUNC5(AngleTween_obj,tween,return )

Void AngleTween_obj::update( ){
{
		HX_STACK_FRAME("flixel.tweens.misc.AngleTween","update",0xed654671,"flixel.tweens.misc.AngleTween.update","flixel/tweens/misc/AngleTween.hx",65,0x989494f7)
		HX_STACK_THIS(this)
		HX_STACK_LINE(66)
		this->super::update();
		HX_STACK_LINE(68)
		this->angle = hx::Mod(((this->_start + (this->_range * this->scale))),(int)360);
		HX_STACK_LINE(70)
		if (((this->angle < (int)0))){
			HX_STACK_LINE(72)
			hx::AddEq(this->angle,(int)360);
		}
		HX_STACK_LINE(75)
		if (((this->sprite != null()))){
			HX_STACK_LINE(77)
			this->sprite->set_angle(this->angle);
		}
	}
return null();
}



AngleTween_obj::AngleTween_obj()
{
}

void AngleTween_obj::__Mark(HX_MARK_PARAMS)
{
	HX_MARK_BEGIN_CLASS(AngleTween);
	HX_MARK_MEMBER_NAME(angle,"angle");
	HX_MARK_MEMBER_NAME(sprite,"sprite");
	HX_MARK_MEMBER_NAME(_start,"_start");
	HX_MARK_MEMBER_NAME(_range,"_range");
	::flixel::tweens::FlxTween_obj::__Mark(HX_MARK_ARG);
	HX_MARK_END_CLASS();
}

void AngleTween_obj::__Visit(HX_VISIT_PARAMS)
{
	HX_VISIT_MEMBER_NAME(angle,"angle");
	HX_VISIT_MEMBER_NAME(sprite,"sprite");
	HX_VISIT_MEMBER_NAME(_start,"_start");
	HX_VISIT_MEMBER_NAME(_range,"_range");
	::flixel::tweens::FlxTween_obj::__Visit(HX_VISIT_ARG);
}

Dynamic AngleTween_obj::__Field(const ::String &inName,bool inCallProp)
{
	switch(inName.length) {
	case 5:
		if (HX_FIELD_EQ(inName,"angle") ) { return angle; }
		if (HX_FIELD_EQ(inName,"tween") ) { return tween_dyn(); }
		break;
	case 6:
		if (HX_FIELD_EQ(inName,"sprite") ) { return sprite; }
		if (HX_FIELD_EQ(inName,"_start") ) { return _start; }
		if (HX_FIELD_EQ(inName,"_range") ) { return _range; }
		if (HX_FIELD_EQ(inName,"update") ) { return update_dyn(); }
	}
	return super::__Field(inName,inCallProp);
}

Dynamic AngleTween_obj::__SetField(const ::String &inName,const Dynamic &inValue,bool inCallProp)
{
	switch(inName.length) {
	case 5:
		if (HX_FIELD_EQ(inName,"angle") ) { angle=inValue.Cast< Float >(); return inValue; }
		break;
	case 6:
		if (HX_FIELD_EQ(inName,"sprite") ) { sprite=inValue.Cast< ::flixel::FlxSprite >(); return inValue; }
		if (HX_FIELD_EQ(inName,"_start") ) { _start=inValue.Cast< Float >(); return inValue; }
		if (HX_FIELD_EQ(inName,"_range") ) { _range=inValue.Cast< Float >(); return inValue; }
	}
	return super::__SetField(inName,inValue,inCallProp);
}

void AngleTween_obj::__GetFields(Array< ::String> &outFields)
{
	outFields->push(HX_CSTRING("angle"));
	outFields->push(HX_CSTRING("sprite"));
	outFields->push(HX_CSTRING("_start"));
	outFields->push(HX_CSTRING("_range"));
	super::__GetFields(outFields);
};

static ::String sStaticFields[] = {
	String(null()) };

#if HXCPP_SCRIPTABLE
static hx::StorageInfo sMemberStorageInfo[] = {
	{hx::fsFloat,(int)offsetof(AngleTween_obj,angle),HX_CSTRING("angle")},
	{hx::fsObject /*::flixel::FlxSprite*/ ,(int)offsetof(AngleTween_obj,sprite),HX_CSTRING("sprite")},
	{hx::fsFloat,(int)offsetof(AngleTween_obj,_start),HX_CSTRING("_start")},
	{hx::fsFloat,(int)offsetof(AngleTween_obj,_range),HX_CSTRING("_range")},
	{ hx::fsUnknown, 0, null()}
};
#endif

static ::String sMemberFields[] = {
	HX_CSTRING("angle"),
	HX_CSTRING("sprite"),
	HX_CSTRING("_start"),
	HX_CSTRING("_range"),
	HX_CSTRING("tween"),
	HX_CSTRING("update"),
	String(null()) };

static void sMarkStatics(HX_MARK_PARAMS) {
	HX_MARK_MEMBER_NAME(AngleTween_obj::__mClass,"__mClass");
};

#ifdef HXCPP_VISIT_ALLOCS
static void sVisitStatics(HX_VISIT_PARAMS) {
	HX_VISIT_MEMBER_NAME(AngleTween_obj::__mClass,"__mClass");
};

#endif

Class AngleTween_obj::__mClass;

void AngleTween_obj::__register()
{
	hx::Static(__mClass) = hx::RegisterClass(HX_CSTRING("flixel.tweens.misc.AngleTween"), hx::TCanCast< AngleTween_obj> ,sStaticFields,sMemberFields,
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

void AngleTween_obj::__boot()
{
}

} // end namespace flixel
} // end namespace tweens
} // end namespace misc
