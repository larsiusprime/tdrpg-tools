#include <hxcpp.h>

#ifndef INCLUDED_Reflect
#include <Reflect.h>
#endif
#ifndef INCLUDED_flixel_interfaces_IFlxDestroyable
#include <flixel/interfaces/IFlxDestroyable.h>
#endif
#ifndef INCLUDED_flixel_tweens_FlxTween
#include <flixel/tweens/FlxTween.h>
#endif
#ifndef INCLUDED_flixel_tweens_misc_VarTween
#include <flixel/tweens/misc/VarTween.h>
#endif
#ifndef INCLUDED_hxMath
#include <hxMath.h>
#endif
namespace flixel{
namespace tweens{
namespace misc{

Void VarTween_obj::__construct(Dynamic complete,hx::Null< int >  __o_type)
{
HX_STACK_FRAME("flixel.tweens.misc.VarTween","new",0x19cf09e4,"flixel.tweens.misc.VarTween.new","flixel/tweens/misc/VarTween.hx",22,0x836bddcb)

HX_STACK_ARG(complete,"complete")

HX_STACK_ARG(__o_type,"type")
int type = __o_type.Default(0);
{
	HX_STACK_LINE(22)
	super::__construct((int)0,type,complete,null());
}
;
	return null();
}

//VarTween_obj::~VarTween_obj() { }

Dynamic VarTween_obj::__CreateEmpty() { return  new VarTween_obj; }
hx::ObjectPtr< VarTween_obj > VarTween_obj::__new(Dynamic complete,hx::Null< int >  __o_type)
{  hx::ObjectPtr< VarTween_obj > result = new VarTween_obj();
	result->__construct(complete,__o_type);
	return result;}

Dynamic VarTween_obj::__Create(hx::DynamicArray inArgs)
{  hx::ObjectPtr< VarTween_obj > result = new VarTween_obj();
	result->__construct(inArgs[0],inArgs[1]);
	return result;}

Void VarTween_obj::destroy( ){
{
		HX_STACK_FRAME("flixel.tweens.misc.VarTween","destroy",0xef76787e,"flixel.tweens.misc.VarTween.destroy","flixel/tweens/misc/VarTween.hx",26,0x836bddcb)
		HX_STACK_THIS(this)
		HX_STACK_LINE(27)
		this->super::destroy();
		HX_STACK_LINE(28)
		this->_object = null();
	}
return null();
}


::flixel::tweens::misc::VarTween VarTween_obj::tween( Dynamic object,::String property,Float to,Float duration,Dynamic ease){
	HX_STACK_FRAME("flixel.tweens.misc.VarTween","tween",0xf3504cef,"flixel.tweens.misc.VarTween.tween","flixel/tweens/misc/VarTween.hx",41,0x836bddcb)
	HX_STACK_THIS(this)
	HX_STACK_ARG(object,"object")
	HX_STACK_ARG(property,"property")
	HX_STACK_ARG(to,"to")
	HX_STACK_ARG(duration,"duration")
	HX_STACK_ARG(ease,"ease")
	HX_STACK_LINE(42)
	this->_object = object;
	HX_STACK_LINE(43)
	this->ease = ease;
	HX_STACK_LINE(46)
	if ((!(::Reflect_obj::isObject(object)))){
		HX_STACK_LINE(48)
		HX_STACK_DO_THROW(HX_CSTRING("A valid object was not passed."));
	}
	HX_STACK_LINE(51)
	this->_property = property;
	struct _Function_1_1{
		inline static Dynamic Block( ::flixel::tweens::misc::VarTween_obj *__this,::String &property){
			HX_STACK_FRAME("*","closure",0x5bdab937,"*.closure","flixel/tweens/misc/VarTween.hx",54,0x836bddcb)
			{
				HX_STACK_LINE(54)
				Dynamic o = __this->_object;		HX_STACK_VAR(o,"o");
				HX_STACK_LINE(54)
				return (  (((o == null()))) ? Dynamic(null()) : Dynamic(o->__Field(property,true)) );
			}
			return null();
		}
	};
	HX_STACK_LINE(54)
	if (((_Function_1_1::Block(this,property) == null()))){
		HX_STACK_LINE(56)
		HX_STACK_DO_THROW(((HX_CSTRING("The Object does not have the property\"") + property) + HX_CSTRING("\", or it is not accessible.")));
	}
	HX_STACK_LINE(59)
	Float a;		HX_STACK_VAR(a,"a");
	HX_STACK_LINE(59)
	{
		HX_STACK_LINE(59)
		Dynamic o = this->_object;		HX_STACK_VAR(o,"o");
		HX_STACK_LINE(59)
		if (((o == null()))){
			HX_STACK_LINE(59)
			a = null();
		}
		else{
			HX_STACK_LINE(59)
			a = o->__Field(property,true);
		}
	}
	HX_STACK_LINE(61)
	if ((::Math_obj::isNaN(a))){
		HX_STACK_LINE(63)
		HX_STACK_DO_THROW(((HX_CSTRING("The property \"") + property) + HX_CSTRING("\" is not numeric.")));
	}
	HX_STACK_LINE(66)
	this->_start = a;
	HX_STACK_LINE(67)
	this->_range = (to - this->_start);
	HX_STACK_LINE(68)
	this->duration = duration;
	HX_STACK_LINE(69)
	this->start();
	HX_STACK_LINE(70)
	return hx::ObjectPtr<OBJ_>(this);
}


HX_DEFINE_DYNAMIC_FUNC5(VarTween_obj,tween,return )

Void VarTween_obj::update( ){
{
		HX_STACK_FRAME("flixel.tweens.misc.VarTween","update",0x50d41705,"flixel.tweens.misc.VarTween.update","flixel/tweens/misc/VarTween.hx",74,0x836bddcb)
		HX_STACK_THIS(this)
		HX_STACK_LINE(75)
		this->super::update();
		HX_STACK_LINE(76)
		{
			HX_STACK_LINE(76)
			Dynamic o = this->_object;		HX_STACK_VAR(o,"o");
			HX_STACK_LINE(76)
			if (((o != null()))){
				HX_STACK_LINE(76)
				o->__SetField(this->_property,(this->_start + (this->_range * this->scale)),true);
			}
		}
	}
return null();
}



VarTween_obj::VarTween_obj()
{
}

void VarTween_obj::__Mark(HX_MARK_PARAMS)
{
	HX_MARK_BEGIN_CLASS(VarTween);
	HX_MARK_MEMBER_NAME(_object,"_object");
	HX_MARK_MEMBER_NAME(_property,"_property");
	HX_MARK_MEMBER_NAME(_start,"_start");
	HX_MARK_MEMBER_NAME(_range,"_range");
	::flixel::tweens::FlxTween_obj::__Mark(HX_MARK_ARG);
	HX_MARK_END_CLASS();
}

void VarTween_obj::__Visit(HX_VISIT_PARAMS)
{
	HX_VISIT_MEMBER_NAME(_object,"_object");
	HX_VISIT_MEMBER_NAME(_property,"_property");
	HX_VISIT_MEMBER_NAME(_start,"_start");
	HX_VISIT_MEMBER_NAME(_range,"_range");
	::flixel::tweens::FlxTween_obj::__Visit(HX_VISIT_ARG);
}

Dynamic VarTween_obj::__Field(const ::String &inName,bool inCallProp)
{
	switch(inName.length) {
	case 5:
		if (HX_FIELD_EQ(inName,"tween") ) { return tween_dyn(); }
		break;
	case 6:
		if (HX_FIELD_EQ(inName,"_start") ) { return _start; }
		if (HX_FIELD_EQ(inName,"_range") ) { return _range; }
		if (HX_FIELD_EQ(inName,"update") ) { return update_dyn(); }
		break;
	case 7:
		if (HX_FIELD_EQ(inName,"_object") ) { return _object; }
		if (HX_FIELD_EQ(inName,"destroy") ) { return destroy_dyn(); }
		break;
	case 9:
		if (HX_FIELD_EQ(inName,"_property") ) { return _property; }
	}
	return super::__Field(inName,inCallProp);
}

Dynamic VarTween_obj::__SetField(const ::String &inName,const Dynamic &inValue,bool inCallProp)
{
	switch(inName.length) {
	case 6:
		if (HX_FIELD_EQ(inName,"_start") ) { _start=inValue.Cast< Float >(); return inValue; }
		if (HX_FIELD_EQ(inName,"_range") ) { _range=inValue.Cast< Float >(); return inValue; }
		break;
	case 7:
		if (HX_FIELD_EQ(inName,"_object") ) { _object=inValue.Cast< Dynamic >(); return inValue; }
		break;
	case 9:
		if (HX_FIELD_EQ(inName,"_property") ) { _property=inValue.Cast< ::String >(); return inValue; }
	}
	return super::__SetField(inName,inValue,inCallProp);
}

void VarTween_obj::__GetFields(Array< ::String> &outFields)
{
	outFields->push(HX_CSTRING("_object"));
	outFields->push(HX_CSTRING("_property"));
	outFields->push(HX_CSTRING("_start"));
	outFields->push(HX_CSTRING("_range"));
	super::__GetFields(outFields);
};

static ::String sStaticFields[] = {
	String(null()) };

#if HXCPP_SCRIPTABLE
static hx::StorageInfo sMemberStorageInfo[] = {
	{hx::fsObject /*Dynamic*/ ,(int)offsetof(VarTween_obj,_object),HX_CSTRING("_object")},
	{hx::fsString,(int)offsetof(VarTween_obj,_property),HX_CSTRING("_property")},
	{hx::fsFloat,(int)offsetof(VarTween_obj,_start),HX_CSTRING("_start")},
	{hx::fsFloat,(int)offsetof(VarTween_obj,_range),HX_CSTRING("_range")},
	{ hx::fsUnknown, 0, null()}
};
#endif

static ::String sMemberFields[] = {
	HX_CSTRING("_object"),
	HX_CSTRING("_property"),
	HX_CSTRING("_start"),
	HX_CSTRING("_range"),
	HX_CSTRING("destroy"),
	HX_CSTRING("tween"),
	HX_CSTRING("update"),
	String(null()) };

static void sMarkStatics(HX_MARK_PARAMS) {
	HX_MARK_MEMBER_NAME(VarTween_obj::__mClass,"__mClass");
};

#ifdef HXCPP_VISIT_ALLOCS
static void sVisitStatics(HX_VISIT_PARAMS) {
	HX_VISIT_MEMBER_NAME(VarTween_obj::__mClass,"__mClass");
};

#endif

Class VarTween_obj::__mClass;

void VarTween_obj::__register()
{
	hx::Static(__mClass) = hx::RegisterClass(HX_CSTRING("flixel.tweens.misc.VarTween"), hx::TCanCast< VarTween_obj> ,sStaticFields,sMemberFields,
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

void VarTween_obj::__boot()
{
}

} // end namespace flixel
} // end namespace tweens
} // end namespace misc
