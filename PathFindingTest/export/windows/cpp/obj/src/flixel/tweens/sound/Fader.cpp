#include <hxcpp.h>

#ifndef INCLUDED_flixel_FlxG
#include <flixel/FlxG.h>
#endif
#ifndef INCLUDED_flixel_interfaces_IFlxDestroyable
#include <flixel/interfaces/IFlxDestroyable.h>
#endif
#ifndef INCLUDED_flixel_system_frontEnds_SoundFrontEnd
#include <flixel/system/frontEnds/SoundFrontEnd.h>
#endif
#ifndef INCLUDED_flixel_tweens_FlxTween
#include <flixel/tweens/FlxTween.h>
#endif
#ifndef INCLUDED_flixel_tweens_sound_Fader
#include <flixel/tweens/sound/Fader.h>
#endif
namespace flixel{
namespace tweens{
namespace sound{

Void Fader_obj::__construct(Dynamic complete,hx::Null< int >  __o_type)
{
HX_STACK_FRAME("flixel.tweens.sound.Fader","new",0x1d219df5,"flixel.tweens.sound.Fader.new","flixel/tweens/sound/Fader.hx",22,0xc3526a3c)

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

//Fader_obj::~Fader_obj() { }

Dynamic Fader_obj::__CreateEmpty() { return  new Fader_obj; }
hx::ObjectPtr< Fader_obj > Fader_obj::__new(Dynamic complete,hx::Null< int >  __o_type)
{  hx::ObjectPtr< Fader_obj > result = new Fader_obj();
	result->__construct(complete,__o_type);
	return result;}

Dynamic Fader_obj::__Create(hx::DynamicArray inArgs)
{  hx::ObjectPtr< Fader_obj > result = new Fader_obj();
	result->__construct(inArgs[0],inArgs[1]);
	return result;}

Void Fader_obj::fadeTo( Float volume,Float duration,Dynamic ease){
{
		HX_STACK_FRAME("flixel.tweens.sound.Fader","fadeTo",0xe93873a2,"flixel.tweens.sound.Fader.fadeTo","flixel/tweens/sound/Fader.hx",33,0xc3526a3c)
		HX_STACK_THIS(this)
		HX_STACK_ARG(volume,"volume")
		HX_STACK_ARG(duration,"duration")
		HX_STACK_ARG(ease,"ease")
		HX_STACK_LINE(34)
		if (((volume < (int)0))){
			HX_STACK_LINE(34)
			volume = (int)0;
		}
		HX_STACK_LINE(35)
		this->_start = ::flixel::FlxG_obj::sound->volume;
		HX_STACK_LINE(36)
		this->_range = (volume - this->_start);
		HX_STACK_LINE(37)
		this->duration = duration;
		HX_STACK_LINE(38)
		this->ease = ease;
		HX_STACK_LINE(39)
		this->start();
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC3(Fader_obj,fadeTo,(void))

Void Fader_obj::update( ){
{
		HX_STACK_FRAME("flixel.tweens.sound.Fader","update",0x8b92a394,"flixel.tweens.sound.Fader.update","flixel/tweens/sound/Fader.hx",43,0xc3526a3c)
		HX_STACK_THIS(this)
		HX_STACK_LINE(44)
		this->super::update();
		HX_STACK_LINE(45)
		::flixel::FlxG_obj::sound->set_volume((this->_start + (this->_range * this->scale)));
	}
return null();
}



Fader_obj::Fader_obj()
{
}

Dynamic Fader_obj::__Field(const ::String &inName,bool inCallProp)
{
	switch(inName.length) {
	case 6:
		if (HX_FIELD_EQ(inName,"_start") ) { return _start; }
		if (HX_FIELD_EQ(inName,"_range") ) { return _range; }
		if (HX_FIELD_EQ(inName,"fadeTo") ) { return fadeTo_dyn(); }
		if (HX_FIELD_EQ(inName,"update") ) { return update_dyn(); }
	}
	return super::__Field(inName,inCallProp);
}

Dynamic Fader_obj::__SetField(const ::String &inName,const Dynamic &inValue,bool inCallProp)
{
	switch(inName.length) {
	case 6:
		if (HX_FIELD_EQ(inName,"_start") ) { _start=inValue.Cast< Float >(); return inValue; }
		if (HX_FIELD_EQ(inName,"_range") ) { _range=inValue.Cast< Float >(); return inValue; }
	}
	return super::__SetField(inName,inValue,inCallProp);
}

void Fader_obj::__GetFields(Array< ::String> &outFields)
{
	outFields->push(HX_CSTRING("_start"));
	outFields->push(HX_CSTRING("_range"));
	super::__GetFields(outFields);
};

static ::String sStaticFields[] = {
	String(null()) };

#if HXCPP_SCRIPTABLE
static hx::StorageInfo sMemberStorageInfo[] = {
	{hx::fsFloat,(int)offsetof(Fader_obj,_start),HX_CSTRING("_start")},
	{hx::fsFloat,(int)offsetof(Fader_obj,_range),HX_CSTRING("_range")},
	{ hx::fsUnknown, 0, null()}
};
#endif

static ::String sMemberFields[] = {
	HX_CSTRING("_start"),
	HX_CSTRING("_range"),
	HX_CSTRING("fadeTo"),
	HX_CSTRING("update"),
	String(null()) };

static void sMarkStatics(HX_MARK_PARAMS) {
	HX_MARK_MEMBER_NAME(Fader_obj::__mClass,"__mClass");
};

#ifdef HXCPP_VISIT_ALLOCS
static void sVisitStatics(HX_VISIT_PARAMS) {
	HX_VISIT_MEMBER_NAME(Fader_obj::__mClass,"__mClass");
};

#endif

Class Fader_obj::__mClass;

void Fader_obj::__register()
{
	hx::Static(__mClass) = hx::RegisterClass(HX_CSTRING("flixel.tweens.sound.Fader"), hx::TCanCast< Fader_obj> ,sStaticFields,sMemberFields,
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

void Fader_obj::__boot()
{
}

} // end namespace flixel
} // end namespace tweens
} // end namespace sound
