#include <hxcpp.h>

#ifndef INCLUDED_Reflect
#include <Reflect.h>
#endif
#ifndef INCLUDED_flixel_FlxBasic
#include <flixel/FlxBasic.h>
#endif
#ifndef INCLUDED_flixel_FlxG
#include <flixel/FlxG.h>
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
#ifndef INCLUDED_flixel_plugin_FlxPlugin
#include <flixel/plugin/FlxPlugin.h>
#endif
#ifndef INCLUDED_flixel_plugin_TweenManager
#include <flixel/plugin/TweenManager.h>
#endif
#ifndef INCLUDED_flixel_tweens_FlxTween
#include <flixel/tweens/FlxTween.h>
#endif
#ifndef INCLUDED_flixel_tweens_misc_AngleTween
#include <flixel/tweens/misc/AngleTween.h>
#endif
#ifndef INCLUDED_flixel_tweens_misc_ColorTween
#include <flixel/tweens/misc/ColorTween.h>
#endif
#ifndef INCLUDED_flixel_tweens_misc_MultiVarTween
#include <flixel/tweens/misc/MultiVarTween.h>
#endif
#ifndef INCLUDED_flixel_tweens_misc_NumTween
#include <flixel/tweens/misc/NumTween.h>
#endif
#ifndef INCLUDED_flixel_tweens_misc_VarTween
#include <flixel/tweens/misc/VarTween.h>
#endif
#ifndef INCLUDED_flixel_tweens_motion_CircularMotion
#include <flixel/tweens/motion/CircularMotion.h>
#endif
#ifndef INCLUDED_flixel_tweens_motion_CubicMotion
#include <flixel/tweens/motion/CubicMotion.h>
#endif
#ifndef INCLUDED_flixel_tweens_motion_LinearMotion
#include <flixel/tweens/motion/LinearMotion.h>
#endif
#ifndef INCLUDED_flixel_tweens_motion_LinearPath
#include <flixel/tweens/motion/LinearPath.h>
#endif
#ifndef INCLUDED_flixel_tweens_motion_Motion
#include <flixel/tweens/motion/Motion.h>
#endif
#ifndef INCLUDED_flixel_tweens_motion_QuadMotion
#include <flixel/tweens/motion/QuadMotion.h>
#endif
#ifndef INCLUDED_flixel_tweens_motion_QuadPath
#include <flixel/tweens/motion/QuadPath.h>
#endif
#ifndef INCLUDED_flixel_tweens_sound_Fader
#include <flixel/tweens/sound/Fader.h>
#endif
#ifndef INCLUDED_flixel_util_FlxPoint
#include <flixel/util/FlxPoint.h>
#endif
#ifndef INCLUDED_hxMath
#include <hxMath.h>
#endif
namespace flixel{
namespace tweens{

Void FlxTween_obj::__construct(Float duration,hx::Null< int >  __o_type,Dynamic complete,Dynamic ease)
{
HX_STACK_FRAME("flixel.tweens.FlxTween","new",0xa442439f,"flixel.tweens.FlxTween.new","flixel/tweens/FlxTween.hx",27,0x5d58d691)

HX_STACK_ARG(duration,"duration")

HX_STACK_ARG(__o_type,"type")

HX_STACK_ARG(complete,"complete")

HX_STACK_ARG(ease,"ease")
int type = __o_type.Default(0);
{
	HX_STACK_LINE(527)
	this->_delayToUse = (int)0;
	HX_STACK_LINE(525)
	this->_secondsSinceStart = (int)0;
	HX_STACK_LINE(523)
	this->loopDelay = (int)0;
	HX_STACK_LINE(518)
	this->startDelay = (int)0;
	HX_STACK_LINE(513)
	this->executions = (int)0;
	HX_STACK_LINE(501)
	this->userData = null();
	HX_STACK_LINE(539)
	this->duration = duration;
	HX_STACK_LINE(540)
	this->set_type(type);
	HX_STACK_LINE(541)
	this->complete = complete;
	HX_STACK_LINE(542)
	this->ease = ease;
	struct _Function_1_1{
		inline static Dynamic Block( ){
			HX_STACK_FRAME("*","closure",0x5bdab937,"*.closure","flixel/tweens/FlxTween.hx",544,0x5d58d691)
			{
				hx::Anon __result = hx::Anon_obj::Create();
				return __result;
			}
			return null();
		}
	};
	HX_STACK_LINE(544)
	this->userData = _Function_1_1::Block();
}
;
	return null();
}

//FlxTween_obj::~FlxTween_obj() { }

Dynamic FlxTween_obj::__CreateEmpty() { return  new FlxTween_obj; }
hx::ObjectPtr< FlxTween_obj > FlxTween_obj::__new(Float duration,hx::Null< int >  __o_type,Dynamic complete,Dynamic ease)
{  hx::ObjectPtr< FlxTween_obj > result = new FlxTween_obj();
	result->__construct(duration,__o_type,complete,ease);
	return result;}

Dynamic FlxTween_obj::__Create(hx::DynamicArray inArgs)
{  hx::ObjectPtr< FlxTween_obj > result = new FlxTween_obj();
	result->__construct(inArgs[0],inArgs[1],inArgs[2],inArgs[3]);
	return result;}

hx::Object *FlxTween_obj::__ToInterface(const hx::type_info &inType) {
	if (inType==typeid( ::flixel::interfaces::IFlxDestroyable_obj)) return operator ::flixel::interfaces::IFlxDestroyable_obj *();
	return super::__ToInterface(inType);
}

Void FlxTween_obj::destroy( ){
{
		HX_STACK_FRAME("flixel.tweens.FlxTween","destroy",0xb268abb9,"flixel.tweens.FlxTween.destroy","flixel/tweens/FlxTween.hx",548,0x5d58d691)
		HX_STACK_THIS(this)
		HX_STACK_LINE(549)
		this->complete = null();
		HX_STACK_LINE(550)
		this->ease = null();
		HX_STACK_LINE(551)
		this->userData = null();
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC0(FlxTween_obj,destroy,(void))

Void FlxTween_obj::update( ){
{
		HX_STACK_FRAME("flixel.tweens.FlxTween","update",0xb905642a,"flixel.tweens.FlxTween.update","flixel/tweens/FlxTween.hx",555,0x5d58d691)
		HX_STACK_THIS(this)
		HX_STACK_LINE(556)
		hx::AddEq(this->_secondsSinceStart,::flixel::FlxG_obj::elapsed);
		HX_STACK_LINE(557)
		Float delay;		HX_STACK_VAR(delay,"delay");
		HX_STACK_LINE(557)
		if (((this->executions > (int)0))){
			HX_STACK_LINE(557)
			delay = this->loopDelay;
		}
		else{
			HX_STACK_LINE(557)
			delay = this->startDelay;
		}
		HX_STACK_LINE(558)
		this->scale = (Float(::Math_obj::max((this->_secondsSinceStart - delay),(int)0)) / Float(this->duration));
		HX_STACK_LINE(559)
		if (((this->ease_dyn() != null()))){
			HX_STACK_LINE(561)
			this->scale = this->ease(this->scale);
		}
		HX_STACK_LINE(563)
		if ((this->backward)){
			HX_STACK_LINE(565)
			this->scale = ((int)1 - this->scale);
		}
		HX_STACK_LINE(567)
		if (((this->_secondsSinceStart >= (this->duration + delay)))){
			HX_STACK_LINE(569)
			if ((this->backward)){
				HX_STACK_LINE(569)
				this->scale = (int)0;
			}
			else{
				HX_STACK_LINE(569)
				this->scale = (int)1;
			}
			HX_STACK_LINE(570)
			this->finished = true;
		}
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC0(FlxTween_obj,update,(void))

::flixel::tweens::FlxTween FlxTween_obj::start( ){
	HX_STACK_FRAME("flixel.tweens.FlxTween","start",0xd6ec7561,"flixel.tweens.FlxTween.start","flixel/tweens/FlxTween.hx",578,0x5d58d691)
	HX_STACK_THIS(this)
	HX_STACK_LINE(579)
	this->_secondsSinceStart = (int)0;
	HX_STACK_LINE(580)
	if (((this->executions > (int)0))){
		HX_STACK_LINE(580)
		this->_delayToUse = this->loopDelay;
	}
	else{
		HX_STACK_LINE(580)
		this->_delayToUse = this->startDelay;
	}
	HX_STACK_LINE(581)
	if (((this->duration == (int)0))){
		HX_STACK_LINE(583)
		this->active = false;
		HX_STACK_LINE(584)
		return hx::ObjectPtr<OBJ_>(this);
	}
	HX_STACK_LINE(586)
	this->active = true;
	HX_STACK_LINE(587)
	return hx::ObjectPtr<OBJ_>(this);
}


HX_DEFINE_DYNAMIC_FUNC0(FlxTween_obj,start,return )

Void FlxTween_obj::cancel( ){
{
		HX_STACK_FRAME("flixel.tweens.FlxTween","cancel",0xea33cb9b,"flixel.tweens.FlxTween.cancel","flixel/tweens/FlxTween.hx",594,0x5d58d691)
		HX_STACK_THIS(this)
		HX_STACK_LINE(595)
		this->active = false;
		HX_STACK_LINE(596)
		::flixel::tweens::FlxTween_obj::manager->remove(hx::ObjectPtr<OBJ_>(this),null());
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC0(FlxTween_obj,cancel,(void))

Void FlxTween_obj::finish( ){
{
		HX_STACK_FRAME("flixel.tweens.FlxTween","finish",0xb87f1e74,"flixel.tweens.FlxTween.finish","flixel/tweens/FlxTween.hx",600,0x5d58d691)
		HX_STACK_THIS(this)
		HX_STACK_LINE(601)
		(this->executions)++;
		HX_STACK_LINE(603)
		if (((this->complete_dyn() != null()))){
			HX_STACK_LINE(605)
			this->complete(hx::ObjectPtr<OBJ_>(this));
		}
		HX_STACK_LINE(608)
		{
			HX_STACK_LINE(608)
			int _g = (int(this->type) & int((int)-17));		HX_STACK_VAR(_g,"_g");
			HX_STACK_LINE(608)
			switch( (int)(_g)){
				case (int)1: {
					HX_STACK_LINE(611)
					this->_secondsSinceStart = (this->duration + this->startDelay);
					HX_STACK_LINE(612)
					this->active = false;
				}
				;break;
				case (int)2: {
					HX_STACK_LINE(615)
					this->_secondsSinceStart = (hx::Mod(((this->_secondsSinceStart - this->_delayToUse)),this->duration) + this->_delayToUse);
					HX_STACK_LINE(616)
					this->scale = (Float(::Math_obj::max((this->_secondsSinceStart - this->_delayToUse),(int)0)) / Float(this->duration));
					HX_STACK_LINE(617)
					if (((bool((bool((this->ease_dyn() != null())) && bool((this->scale > (int)0)))) && bool((this->scale < (int)1))))){
						HX_STACK_LINE(618)
						this->scale = this->ease(this->scale);
					}
					HX_STACK_LINE(620)
					this->start();
				}
				;break;
				case (int)4: {
					HX_STACK_LINE(623)
					this->_secondsSinceStart = (hx::Mod(((this->_secondsSinceStart - this->_delayToUse)),this->duration) + this->_delayToUse);
					HX_STACK_LINE(624)
					this->scale = (Float(::Math_obj::max((this->_secondsSinceStart - this->_delayToUse),(int)0)) / Float(this->duration));
					HX_STACK_LINE(625)
					if (((bool((bool((this->ease_dyn() != null())) && bool((this->scale > (int)0)))) && bool((this->scale < (int)1))))){
						HX_STACK_LINE(626)
						this->scale = this->ease(this->scale);
					}
					HX_STACK_LINE(628)
					this->backward = !(this->backward);
					HX_STACK_LINE(629)
					if ((this->backward)){
						HX_STACK_LINE(630)
						this->scale = ((int)1 - this->scale);
					}
					HX_STACK_LINE(632)
					this->start();
				}
				;break;
				case (int)8: {
					HX_STACK_LINE(635)
					this->_secondsSinceStart = (this->duration + this->startDelay);
					HX_STACK_LINE(636)
					this->active = false;
					HX_STACK_LINE(637)
					::flixel::tweens::FlxTween_obj::manager->remove(hx::ObjectPtr<OBJ_>(this),true);
				}
				;break;
			}
		}
		HX_STACK_LINE(640)
		this->finished = false;
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC0(FlxTween_obj,finish,(void))

Void FlxTween_obj::setDelays( Dynamic __o_startDelay,Dynamic __o_loopDelay){
Dynamic startDelay = __o_startDelay.Default(0);
Dynamic loopDelay = __o_loopDelay.Default(0);
	HX_STACK_FRAME("flixel.tweens.FlxTween","setDelays",0x750c1d51,"flixel.tweens.FlxTween.setDelays","flixel/tweens/FlxTween.hx",650,0x5d58d691)
	HX_STACK_THIS(this)
	HX_STACK_ARG(startDelay,"startDelay")
	HX_STACK_ARG(loopDelay,"loopDelay")
{
		HX_STACK_LINE(651)
		this->set_startDelay(startDelay);
		HX_STACK_LINE(652)
		this->set_loopDelay(loopDelay);
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC2(FlxTween_obj,setDelays,(void))

Dynamic FlxTween_obj::set_startDelay( Dynamic value){
	HX_STACK_FRAME("flixel.tweens.FlxTween","set_startDelay",0xdc7f879f,"flixel.tweens.FlxTween.set_startDelay","flixel/tweens/FlxTween.hx",656,0x5d58d691)
	HX_STACK_THIS(this)
	HX_STACK_ARG(value,"value")
	HX_STACK_LINE(657)
	Float dly;		HX_STACK_VAR(dly,"dly");
	HX_STACK_LINE(657)
	if (((value != null()))){
		HX_STACK_LINE(657)
		dly = ::Math_obj::abs(value);
	}
	else{
		HX_STACK_LINE(657)
		dly = (int)0;
	}
	HX_STACK_LINE(658)
	if (((this->executions == (int)0))){
		HX_STACK_LINE(660)
		Float _g = (this->duration * ((Float(::Math_obj::max((this->_secondsSinceStart - this->_delayToUse),(int)0)) / Float(this->duration))));		HX_STACK_VAR(_g,"_g");
		HX_STACK_LINE(660)
		this->_secondsSinceStart = (_g + ::Math_obj::max((dly - this->startDelay),(int)0));
		HX_STACK_LINE(661)
		this->_delayToUse = dly;
	}
	HX_STACK_LINE(663)
	return this->startDelay = dly;
}


HX_DEFINE_DYNAMIC_FUNC1(FlxTween_obj,set_startDelay,return )

Dynamic FlxTween_obj::set_loopDelay( Dynamic value){
	HX_STACK_FRAME("flixel.tweens.FlxTween","set_loopDelay",0xc5954461,"flixel.tweens.FlxTween.set_loopDelay","flixel/tweens/FlxTween.hx",667,0x5d58d691)
	HX_STACK_THIS(this)
	HX_STACK_ARG(value,"value")
	HX_STACK_LINE(668)
	Float dly;		HX_STACK_VAR(dly,"dly");
	HX_STACK_LINE(668)
	if (((value != null()))){
		HX_STACK_LINE(668)
		dly = ::Math_obj::abs(value);
	}
	else{
		HX_STACK_LINE(668)
		dly = (int)0;
	}
	HX_STACK_LINE(669)
	if (((this->executions > (int)0))){
		HX_STACK_LINE(671)
		Float _g = (this->duration * ((Float(::Math_obj::max((this->_secondsSinceStart - this->_delayToUse),(int)0)) / Float(this->duration))));		HX_STACK_VAR(_g,"_g");
		HX_STACK_LINE(671)
		this->_secondsSinceStart = (_g + ::Math_obj::max((dly - this->loopDelay),(int)0));
		HX_STACK_LINE(672)
		this->_delayToUse = dly;
	}
	HX_STACK_LINE(674)
	return this->loopDelay = dly;
}


HX_DEFINE_DYNAMIC_FUNC1(FlxTween_obj,set_loopDelay,return )

Float FlxTween_obj::get_percent( ){
	HX_STACK_FRAME("flixel.tweens.FlxTween","get_percent",0x9c57551b,"flixel.tweens.FlxTween.get_percent","flixel/tweens/FlxTween.hx",679,0x5d58d691)
	HX_STACK_THIS(this)
	HX_STACK_LINE(679)
	return (Float(::Math_obj::max((this->_secondsSinceStart - this->_delayToUse),(int)0)) / Float(this->duration));
}


HX_DEFINE_DYNAMIC_FUNC0(FlxTween_obj,get_percent,return )

Float FlxTween_obj::set_percent( Float value){
	HX_STACK_FRAME("flixel.tweens.FlxTween","set_percent",0xa6c45c27,"flixel.tweens.FlxTween.set_percent","flixel/tweens/FlxTween.hx",684,0x5d58d691)
	HX_STACK_THIS(this)
	HX_STACK_ARG(value,"value")
	HX_STACK_LINE(684)
	return this->_secondsSinceStart = ((this->duration * value) + this->_delayToUse);
}


HX_DEFINE_DYNAMIC_FUNC1(FlxTween_obj,set_percent,return )

int FlxTween_obj::set_type( int value){
	HX_STACK_FRAME("flixel.tweens.FlxTween","set_type",0x136d7018,"flixel.tweens.FlxTween.set_type","flixel/tweens/FlxTween.hx",688,0x5d58d691)
	HX_STACK_THIS(this)
	HX_STACK_ARG(value,"value")
	HX_STACK_LINE(689)
	if (((value == (int)0))){
		HX_STACK_LINE(691)
		value = (int)8;
	}
	else{
		HX_STACK_LINE(693)
		if (((value == (int)16))){
			HX_STACK_LINE(695)
			value = (int)17;
		}
	}
	HX_STACK_LINE(698)
	this->backward = (((int(value) & int((int)16))) > (int)0);
	HX_STACK_LINE(700)
	return this->type = value;
}


HX_DEFINE_DYNAMIC_FUNC1(FlxTween_obj,set_type,return )

int FlxTween_obj::PERSIST;

int FlxTween_obj::LOOPING;

int FlxTween_obj::PINGPONG;

int FlxTween_obj::ONESHOT;

int FlxTween_obj::BACKWARD;

::flixel::plugin::TweenManager FlxTween_obj::manager;

::flixel::tweens::FlxTween FlxTween_obj::tween( Dynamic Object,Dynamic Values,Float Duration,Dynamic Options){
	HX_STACK_FRAME("flixel.tweens.FlxTween","tween",0x6c51ab6a,"flixel.tweens.FlxTween.tween","flixel/tweens/FlxTween.hx",73,0x5d58d691)
	HX_STACK_ARG(Object,"Object")
	HX_STACK_ARG(Values,"Values")
	HX_STACK_ARG(Duration,"Duration")
	HX_STACK_ARG(Options,"Options")
	HX_STACK_LINE(74)
	if (((Options == null()))){
		struct _Function_2_1{
			inline static Dynamic Block( ){
				HX_STACK_FRAME("*","closure",0x5bdab937,"*.closure","flixel/tweens/FlxTween.hx",76,0x5d58d691)
				{
					hx::Anon __result = hx::Anon_obj::Create();
					__result->Add(HX_CSTRING("type") , (int)8,false);
					return __result;
				}
				return null();
			}
		};
		HX_STACK_LINE(76)
		Options = _Function_2_1::Block();
	}
	HX_STACK_LINE(79)
	Array< ::String > fields = ::Reflect_obj::fields(Values);		HX_STACK_VAR(fields,"fields");
	HX_STACK_LINE(80)
	if (((fields->length == (int)1))){
		HX_STACK_LINE(82)
		return ::flixel::tweens::FlxTween_obj::singleVar(Object,fields->__get((int)0),::Reflect_obj::field(Values,fields->__get((int)0)),Duration,Options);
	}
	else{
		HX_STACK_LINE(86)
		return ::flixel::tweens::FlxTween_obj::multiVar(Object,Values,Duration,Options);
	}
	HX_STACK_LINE(80)
	return null();
}


STATIC_HX_DEFINE_DYNAMIC_FUNC4(FlxTween_obj,tween,return )

::flixel::tweens::misc::VarTween FlxTween_obj::singleVar( Dynamic Object,::String Property,Float To,Float Duration,Dynamic Options){
	HX_STACK_FRAME("flixel.tweens.FlxTween","singleVar",0x61f7e1be,"flixel.tweens.FlxTween.singleVar","flixel/tweens/FlxTween.hx",107,0x5d58d691)
	HX_STACK_ARG(Object,"Object")
	HX_STACK_ARG(Property,"Property")
	HX_STACK_ARG(To,"To")
	HX_STACK_ARG(Duration,"Duration")
	HX_STACK_ARG(Options,"Options")
	HX_STACK_LINE(108)
	if (((Options == null()))){
		struct _Function_2_1{
			inline static Dynamic Block( ){
				HX_STACK_FRAME("*","closure",0x5bdab937,"*.closure","flixel/tweens/FlxTween.hx",110,0x5d58d691)
				{
					hx::Anon __result = hx::Anon_obj::Create();
					__result->Add(HX_CSTRING("type") , (int)8,false);
					return __result;
				}
				return null();
			}
		};
		HX_STACK_LINE(110)
		Options = _Function_2_1::Block();
	}
	HX_STACK_LINE(113)
	::flixel::tweens::misc::VarTween tween = ::flixel::tweens::misc::VarTween_obj::__new(Options->__Field(HX_CSTRING("complete"),true),Options->__Field(HX_CSTRING("type"),true));		HX_STACK_VAR(tween,"tween");
	HX_STACK_LINE(114)
	tween->setDelays(Options->__Field(HX_CSTRING("startDelay"),true),Options->__Field(HX_CSTRING("loopDelay"),true));
	HX_STACK_LINE(115)
	tween->tween(Object,Property,To,Duration,Options->__Field(HX_CSTRING("ease"),true));
	HX_STACK_LINE(116)
	::flixel::tweens::FlxTween_obj::manager->add(tween,null());
	HX_STACK_LINE(117)
	return tween;
}


STATIC_HX_DEFINE_DYNAMIC_FUNC5(FlxTween_obj,singleVar,return )

::flixel::tweens::FlxTween FlxTween_obj::multiVar( Dynamic Object,Dynamic Values,Float Duration,Dynamic Options){
	HX_STACK_FRAME("flixel.tweens.FlxTween","multiVar",0x32c5864f,"flixel.tweens.FlxTween.multiVar","flixel/tweens/FlxTween.hx",136,0x5d58d691)
	HX_STACK_ARG(Object,"Object")
	HX_STACK_ARG(Values,"Values")
	HX_STACK_ARG(Duration,"Duration")
	HX_STACK_ARG(Options,"Options")
	HX_STACK_LINE(137)
	if (((Options == null()))){
		struct _Function_2_1{
			inline static Dynamic Block( ){
				HX_STACK_FRAME("*","closure",0x5bdab937,"*.closure","flixel/tweens/FlxTween.hx",139,0x5d58d691)
				{
					hx::Anon __result = hx::Anon_obj::Create();
					__result->Add(HX_CSTRING("type") , (int)8,false);
					return __result;
				}
				return null();
			}
		};
		HX_STACK_LINE(139)
		Options = _Function_2_1::Block();
	}
	HX_STACK_LINE(142)
	::flixel::tweens::misc::MultiVarTween tween = ::flixel::tweens::misc::MultiVarTween_obj::__new(Options->__Field(HX_CSTRING("complete"),true),Options->__Field(HX_CSTRING("type"),true));		HX_STACK_VAR(tween,"tween");
	HX_STACK_LINE(143)
	tween->setDelays(Options->__Field(HX_CSTRING("startDelay"),true),Options->__Field(HX_CSTRING("loopDelay"),true));
	HX_STACK_LINE(144)
	tween->tween(Object,Values,Duration,Options->__Field(HX_CSTRING("ease"),true));
	HX_STACK_LINE(145)
	::flixel::tweens::FlxTween_obj::manager->add(tween,null());
	HX_STACK_LINE(146)
	return tween;
}


STATIC_HX_DEFINE_DYNAMIC_FUNC4(FlxTween_obj,multiVar,return )

::flixel::tweens::misc::NumTween FlxTween_obj::num( Float FromValue,Float ToValue,Float Duration,Dynamic Options){
	HX_STACK_FRAME("flixel.tweens.FlxTween","num",0xa4425185,"flixel.tweens.FlxTween.num","flixel/tweens/FlxTween.hx",165,0x5d58d691)
	HX_STACK_ARG(FromValue,"FromValue")
	HX_STACK_ARG(ToValue,"ToValue")
	HX_STACK_ARG(Duration,"Duration")
	HX_STACK_ARG(Options,"Options")
	HX_STACK_LINE(166)
	if (((Options == null()))){
		struct _Function_2_1{
			inline static Dynamic Block( ){
				HX_STACK_FRAME("*","closure",0x5bdab937,"*.closure","flixel/tweens/FlxTween.hx",168,0x5d58d691)
				{
					hx::Anon __result = hx::Anon_obj::Create();
					__result->Add(HX_CSTRING("type") , (int)8,false);
					return __result;
				}
				return null();
			}
		};
		HX_STACK_LINE(168)
		Options = _Function_2_1::Block();
	}
	HX_STACK_LINE(171)
	::flixel::tweens::misc::NumTween tween = ::flixel::tweens::misc::NumTween_obj::__new(Options->__Field(HX_CSTRING("complete"),true),Options->__Field(HX_CSTRING("type"),true));		HX_STACK_VAR(tween,"tween");
	HX_STACK_LINE(172)
	tween->setDelays(Options->__Field(HX_CSTRING("startDelay"),true),Options->__Field(HX_CSTRING("loopDelay"),true));
	HX_STACK_LINE(173)
	tween->tween(FromValue,ToValue,Duration,Options->__Field(HX_CSTRING("ease"),true));
	HX_STACK_LINE(174)
	::flixel::tweens::FlxTween_obj::manager->add(tween,null());
	HX_STACK_LINE(175)
	return tween;
}


STATIC_HX_DEFINE_DYNAMIC_FUNC4(FlxTween_obj,num,return )

::flixel::tweens::misc::AngleTween FlxTween_obj::angle( ::flixel::FlxSprite Sprite,Float FromAngle,Float ToAngle,Float Duration,Dynamic Options){
	HX_STACK_FRAME("flixel.tweens.FlxTween","angle",0x75c344d2,"flixel.tweens.FlxTween.angle","flixel/tweens/FlxTween.hx",195,0x5d58d691)
	HX_STACK_ARG(Sprite,"Sprite")
	HX_STACK_ARG(FromAngle,"FromAngle")
	HX_STACK_ARG(ToAngle,"ToAngle")
	HX_STACK_ARG(Duration,"Duration")
	HX_STACK_ARG(Options,"Options")
	HX_STACK_LINE(196)
	if (((Options == null()))){
		struct _Function_2_1{
			inline static Dynamic Block( ){
				HX_STACK_FRAME("*","closure",0x5bdab937,"*.closure","flixel/tweens/FlxTween.hx",198,0x5d58d691)
				{
					hx::Anon __result = hx::Anon_obj::Create();
					__result->Add(HX_CSTRING("type") , (int)8,false);
					return __result;
				}
				return null();
			}
		};
		HX_STACK_LINE(198)
		Options = _Function_2_1::Block();
	}
	HX_STACK_LINE(201)
	::flixel::tweens::misc::AngleTween tween = ::flixel::tweens::misc::AngleTween_obj::__new(Options->__Field(HX_CSTRING("complete"),true),Options->__Field(HX_CSTRING("type"),true));		HX_STACK_VAR(tween,"tween");
	HX_STACK_LINE(202)
	tween->setDelays(Options->__Field(HX_CSTRING("startDelay"),true),Options->__Field(HX_CSTRING("loopDelay"),true));
	HX_STACK_LINE(203)
	tween->tween(FromAngle,ToAngle,Duration,Options->__Field(HX_CSTRING("ease"),true),Sprite);
	HX_STACK_LINE(204)
	::flixel::tweens::FlxTween_obj::manager->add(tween,null());
	HX_STACK_LINE(205)
	return tween;
}


STATIC_HX_DEFINE_DYNAMIC_FUNC5(FlxTween_obj,angle,return )

::flixel::tweens::misc::ColorTween FlxTween_obj::color( ::flixel::FlxSprite Sprite,Float Duration,int FromColor,int ToColor,hx::Null< Float >  __o_FromAlpha,hx::Null< Float >  __o_ToAlpha,Dynamic Options){
Float FromAlpha = __o_FromAlpha.Default(1);
Float ToAlpha = __o_ToAlpha.Default(1);
	HX_STACK_FRAME("flixel.tweens.FlxTween","color",0x9d3d7262,"flixel.tweens.FlxTween.color","flixel/tweens/FlxTween.hx",227,0x5d58d691)
	HX_STACK_ARG(Sprite,"Sprite")
	HX_STACK_ARG(Duration,"Duration")
	HX_STACK_ARG(FromColor,"FromColor")
	HX_STACK_ARG(ToColor,"ToColor")
	HX_STACK_ARG(FromAlpha,"FromAlpha")
	HX_STACK_ARG(ToAlpha,"ToAlpha")
	HX_STACK_ARG(Options,"Options")
{
		HX_STACK_LINE(228)
		if (((Options == null()))){
			struct _Function_2_1{
				inline static Dynamic Block( ){
					HX_STACK_FRAME("*","closure",0x5bdab937,"*.closure","flixel/tweens/FlxTween.hx",230,0x5d58d691)
					{
						hx::Anon __result = hx::Anon_obj::Create();
						__result->Add(HX_CSTRING("type") , (int)8,false);
						return __result;
					}
					return null();
				}
			};
			HX_STACK_LINE(230)
			Options = _Function_2_1::Block();
		}
		HX_STACK_LINE(233)
		::flixel::tweens::misc::ColorTween tween = ::flixel::tweens::misc::ColorTween_obj::__new(Options->__Field(HX_CSTRING("complete"),true),Options->__Field(HX_CSTRING("type"),true));		HX_STACK_VAR(tween,"tween");
		HX_STACK_LINE(234)
		tween->setDelays(Options->__Field(HX_CSTRING("startDelay"),true),Options->__Field(HX_CSTRING("loopDelay"),true));
		HX_STACK_LINE(235)
		tween->tween(Duration,FromColor,ToColor,FromAlpha,ToAlpha,Options->__Field(HX_CSTRING("ease"),true),Sprite);
		HX_STACK_LINE(236)
		::flixel::tweens::FlxTween_obj::manager->add(tween,null());
		HX_STACK_LINE(237)
		return tween;
	}
}


STATIC_HX_DEFINE_DYNAMIC_FUNC7(FlxTween_obj,color,return )

::flixel::tweens::sound::Fader FlxTween_obj::fader( Float Volume,Float Duration,Dynamic Options){
	HX_STACK_FRAME("flixel.tweens.FlxTween","fader",0x4e2a1875,"flixel.tweens.FlxTween.fader","flixel/tweens/FlxTween.hx",256,0x5d58d691)
	HX_STACK_ARG(Volume,"Volume")
	HX_STACK_ARG(Duration,"Duration")
	HX_STACK_ARG(Options,"Options")
	HX_STACK_LINE(257)
	if (((Options == null()))){
		struct _Function_2_1{
			inline static Dynamic Block( ){
				HX_STACK_FRAME("*","closure",0x5bdab937,"*.closure","flixel/tweens/FlxTween.hx",259,0x5d58d691)
				{
					hx::Anon __result = hx::Anon_obj::Create();
					__result->Add(HX_CSTRING("type") , (int)8,false);
					return __result;
				}
				return null();
			}
		};
		HX_STACK_LINE(259)
		Options = _Function_2_1::Block();
	}
	HX_STACK_LINE(262)
	::flixel::tweens::sound::Fader tween = ::flixel::tweens::sound::Fader_obj::__new(Options->__Field(HX_CSTRING("complete"),true),Options->__Field(HX_CSTRING("type"),true));		HX_STACK_VAR(tween,"tween");
	HX_STACK_LINE(263)
	tween->setDelays(Options->__Field(HX_CSTRING("startDelay"),true),Options->__Field(HX_CSTRING("loopDelay"),true));
	HX_STACK_LINE(264)
	tween->fadeTo(Volume,Duration,Options->__Field(HX_CSTRING("ease"),true));
	HX_STACK_LINE(265)
	::flixel::tweens::FlxTween_obj::manager->add(tween,null());
	HX_STACK_LINE(266)
	return tween;
}


STATIC_HX_DEFINE_DYNAMIC_FUNC3(FlxTween_obj,fader,return )

::flixel::tweens::motion::LinearMotion FlxTween_obj::linearMotion( ::flixel::FlxObject Object,Float FromX,Float FromY,Float ToX,Float ToY,Float DurationOrSpeed,hx::Null< bool >  __o_UseDuration,Dynamic Options){
bool UseDuration = __o_UseDuration.Default(true);
	HX_STACK_FRAME("flixel.tweens.FlxTween","linearMotion",0xd656f2dc,"flixel.tweens.FlxTween.linearMotion","flixel/tweens/FlxTween.hx",290,0x5d58d691)
	HX_STACK_ARG(Object,"Object")
	HX_STACK_ARG(FromX,"FromX")
	HX_STACK_ARG(FromY,"FromY")
	HX_STACK_ARG(ToX,"ToX")
	HX_STACK_ARG(ToY,"ToY")
	HX_STACK_ARG(DurationOrSpeed,"DurationOrSpeed")
	HX_STACK_ARG(UseDuration,"UseDuration")
	HX_STACK_ARG(Options,"Options")
{
		HX_STACK_LINE(291)
		if (((Options == null()))){
			struct _Function_2_1{
				inline static Dynamic Block( ){
					HX_STACK_FRAME("*","closure",0x5bdab937,"*.closure","flixel/tweens/FlxTween.hx",293,0x5d58d691)
					{
						hx::Anon __result = hx::Anon_obj::Create();
						__result->Add(HX_CSTRING("type") , (int)8,false);
						return __result;
					}
					return null();
				}
			};
			HX_STACK_LINE(293)
			Options = _Function_2_1::Block();
		}
		HX_STACK_LINE(296)
		::flixel::tweens::motion::LinearMotion tween = ::flixel::tweens::motion::LinearMotion_obj::__new(Options->__Field(HX_CSTRING("complete"),true),Options->__Field(HX_CSTRING("type"),true));		HX_STACK_VAR(tween,"tween");
		HX_STACK_LINE(297)
		tween->setObject(Object);
		HX_STACK_LINE(298)
		tween->setDelays(Options->__Field(HX_CSTRING("startDelay"),true),Options->__Field(HX_CSTRING("loopDelay"),true));
		HX_STACK_LINE(299)
		tween->setMotion(FromX,FromY,ToX,ToY,DurationOrSpeed,UseDuration,Options->__Field(HX_CSTRING("ease"),true));
		HX_STACK_LINE(300)
		::flixel::tweens::FlxTween_obj::manager->add(tween,null());
		HX_STACK_LINE(301)
		return tween;
	}
}


STATIC_HX_DEFINE_DYNAMIC_FUNC8(FlxTween_obj,linearMotion,return )

::flixel::tweens::motion::QuadMotion FlxTween_obj::quadMotion( ::flixel::FlxObject Object,Float FromX,Float FromY,Float ControlX,Float ControlY,Float ToX,Float ToY,Float DurationOrSpeed,hx::Null< bool >  __o_UseDuration,Dynamic Options){
bool UseDuration = __o_UseDuration.Default(true);
	HX_STACK_FRAME("flixel.tweens.FlxTween","quadMotion",0xc62584fe,"flixel.tweens.FlxTween.quadMotion","flixel/tweens/FlxTween.hx",326,0x5d58d691)
	HX_STACK_ARG(Object,"Object")
	HX_STACK_ARG(FromX,"FromX")
	HX_STACK_ARG(FromY,"FromY")
	HX_STACK_ARG(ControlX,"ControlX")
	HX_STACK_ARG(ControlY,"ControlY")
	HX_STACK_ARG(ToX,"ToX")
	HX_STACK_ARG(ToY,"ToY")
	HX_STACK_ARG(DurationOrSpeed,"DurationOrSpeed")
	HX_STACK_ARG(UseDuration,"UseDuration")
	HX_STACK_ARG(Options,"Options")
{
		HX_STACK_LINE(327)
		if (((Options == null()))){
			struct _Function_2_1{
				inline static Dynamic Block( ){
					HX_STACK_FRAME("*","closure",0x5bdab937,"*.closure","flixel/tweens/FlxTween.hx",329,0x5d58d691)
					{
						hx::Anon __result = hx::Anon_obj::Create();
						__result->Add(HX_CSTRING("type") , (int)8,false);
						return __result;
					}
					return null();
				}
			};
			HX_STACK_LINE(329)
			Options = _Function_2_1::Block();
		}
		HX_STACK_LINE(332)
		::flixel::tweens::motion::QuadMotion tween = ::flixel::tweens::motion::QuadMotion_obj::__new(Options->__Field(HX_CSTRING("complete"),true),Options->__Field(HX_CSTRING("type"),true));		HX_STACK_VAR(tween,"tween");
		HX_STACK_LINE(333)
		tween->setObject(Object);
		HX_STACK_LINE(334)
		tween->setDelays(Options->__Field(HX_CSTRING("startDelay"),true),Options->__Field(HX_CSTRING("loopDelay"),true));
		HX_STACK_LINE(335)
		tween->setMotion(FromX,FromY,ControlX,ControlY,ToX,ToY,DurationOrSpeed,UseDuration,Options->__Field(HX_CSTRING("ease"),true));
		HX_STACK_LINE(336)
		::flixel::tweens::FlxTween_obj::manager->add(tween,null());
		HX_STACK_LINE(337)
		return tween;
	}
}


STATIC_HX_DEFINE_DYNAMIC_FUNC10(FlxTween_obj,quadMotion,return )

::flixel::tweens::motion::CubicMotion FlxTween_obj::cubicMotion( ::flixel::FlxObject Object,Float FromX,Float FromY,Float aX,Float aY,Float bX,Float bY,Float ToX,Float ToY,Float Duration,Dynamic Options){
	HX_STACK_FRAME("flixel.tweens.FlxTween","cubicMotion",0xa068755f,"flixel.tweens.FlxTween.cubicMotion","flixel/tweens/FlxTween.hx",363,0x5d58d691)
	HX_STACK_ARG(Object,"Object")
	HX_STACK_ARG(FromX,"FromX")
	HX_STACK_ARG(FromY,"FromY")
	HX_STACK_ARG(aX,"aX")
	HX_STACK_ARG(aY,"aY")
	HX_STACK_ARG(bX,"bX")
	HX_STACK_ARG(bY,"bY")
	HX_STACK_ARG(ToX,"ToX")
	HX_STACK_ARG(ToY,"ToY")
	HX_STACK_ARG(Duration,"Duration")
	HX_STACK_ARG(Options,"Options")
	HX_STACK_LINE(364)
	if (((Options == null()))){
		struct _Function_2_1{
			inline static Dynamic Block( ){
				HX_STACK_FRAME("*","closure",0x5bdab937,"*.closure","flixel/tweens/FlxTween.hx",366,0x5d58d691)
				{
					hx::Anon __result = hx::Anon_obj::Create();
					__result->Add(HX_CSTRING("type") , (int)8,false);
					return __result;
				}
				return null();
			}
		};
		HX_STACK_LINE(366)
		Options = _Function_2_1::Block();
	}
	HX_STACK_LINE(369)
	::flixel::tweens::motion::CubicMotion tween = ::flixel::tweens::motion::CubicMotion_obj::__new(Options->__Field(HX_CSTRING("complete"),true),Options->__Field(HX_CSTRING("type"),true));		HX_STACK_VAR(tween,"tween");
	HX_STACK_LINE(370)
	tween->setObject(Object);
	HX_STACK_LINE(371)
	tween->setDelays(Options->__Field(HX_CSTRING("startDelay"),true),Options->__Field(HX_CSTRING("loopDelay"),true));
	HX_STACK_LINE(372)
	tween->setMotion(FromX,FromY,aX,aY,bX,bY,ToX,ToY,Duration,Options->__Field(HX_CSTRING("ease"),true));
	HX_STACK_LINE(373)
	::flixel::tweens::FlxTween_obj::manager->add(tween,null());
	HX_STACK_LINE(374)
	return tween;
}


STATIC_HX_DEFINE_DYNAMIC_FUNC11(FlxTween_obj,cubicMotion,return )

::flixel::tweens::motion::CircularMotion FlxTween_obj::circularMotion( ::flixel::FlxObject Object,Float CenterX,Float CenterY,Float Radius,Float Angle,bool Clockwise,Float DurationOrSpeed,hx::Null< bool >  __o_UseDuration,Dynamic Options){
bool UseDuration = __o_UseDuration.Default(true);
	HX_STACK_FRAME("flixel.tweens.FlxTween","circularMotion",0x65e89916,"flixel.tweens.FlxTween.circularMotion","flixel/tweens/FlxTween.hx",399,0x5d58d691)
	HX_STACK_ARG(Object,"Object")
	HX_STACK_ARG(CenterX,"CenterX")
	HX_STACK_ARG(CenterY,"CenterY")
	HX_STACK_ARG(Radius,"Radius")
	HX_STACK_ARG(Angle,"Angle")
	HX_STACK_ARG(Clockwise,"Clockwise")
	HX_STACK_ARG(DurationOrSpeed,"DurationOrSpeed")
	HX_STACK_ARG(UseDuration,"UseDuration")
	HX_STACK_ARG(Options,"Options")
{
		HX_STACK_LINE(400)
		if (((Options == null()))){
			struct _Function_2_1{
				inline static Dynamic Block( ){
					HX_STACK_FRAME("*","closure",0x5bdab937,"*.closure","flixel/tweens/FlxTween.hx",402,0x5d58d691)
					{
						hx::Anon __result = hx::Anon_obj::Create();
						__result->Add(HX_CSTRING("type") , (int)8,false);
						return __result;
					}
					return null();
				}
			};
			HX_STACK_LINE(402)
			Options = _Function_2_1::Block();
		}
		HX_STACK_LINE(405)
		::flixel::tweens::motion::CircularMotion tween = ::flixel::tweens::motion::CircularMotion_obj::__new(Options->__Field(HX_CSTRING("complete"),true),Options->__Field(HX_CSTRING("type"),true));		HX_STACK_VAR(tween,"tween");
		HX_STACK_LINE(406)
		tween->setObject(Object);
		HX_STACK_LINE(407)
		tween->setDelays(Options->__Field(HX_CSTRING("startDelay"),true),Options->__Field(HX_CSTRING("loopDelay"),true));
		HX_STACK_LINE(408)
		tween->setMotion(CenterX,CenterY,Radius,Angle,Clockwise,DurationOrSpeed,UseDuration,Options->__Field(HX_CSTRING("ease"),true));
		HX_STACK_LINE(409)
		::flixel::tweens::FlxTween_obj::manager->add(tween,null());
		HX_STACK_LINE(410)
		return tween;
	}
}


STATIC_HX_DEFINE_DYNAMIC_FUNC9(FlxTween_obj,circularMotion,return )

::flixel::tweens::motion::LinearPath FlxTween_obj::linearPath( ::flixel::FlxObject Object,Array< ::Dynamic > Points,Float DurationOrSpeed,hx::Null< bool >  __o_UseDuration,Dynamic Options){
bool UseDuration = __o_UseDuration.Default(true);
	HX_STACK_FRAME("flixel.tweens.FlxTween","linearPath",0xd40abccb,"flixel.tweens.FlxTween.linearPath","flixel/tweens/FlxTween.hx",430,0x5d58d691)
	HX_STACK_ARG(Object,"Object")
	HX_STACK_ARG(Points,"Points")
	HX_STACK_ARG(DurationOrSpeed,"DurationOrSpeed")
	HX_STACK_ARG(UseDuration,"UseDuration")
	HX_STACK_ARG(Options,"Options")
{
		HX_STACK_LINE(431)
		if (((Options == null()))){
			struct _Function_2_1{
				inline static Dynamic Block( ){
					HX_STACK_FRAME("*","closure",0x5bdab937,"*.closure","flixel/tweens/FlxTween.hx",433,0x5d58d691)
					{
						hx::Anon __result = hx::Anon_obj::Create();
						__result->Add(HX_CSTRING("type") , (int)8,false);
						return __result;
					}
					return null();
				}
			};
			HX_STACK_LINE(433)
			Options = _Function_2_1::Block();
		}
		HX_STACK_LINE(436)
		::flixel::tweens::motion::LinearPath tween = ::flixel::tweens::motion::LinearPath_obj::__new(Options->__Field(HX_CSTRING("complete"),true),Options->__Field(HX_CSTRING("type"),true));		HX_STACK_VAR(tween,"tween");
		HX_STACK_LINE(438)
		if (((Points != null()))){
			HX_STACK_LINE(440)
			int _g = (int)0;		HX_STACK_VAR(_g,"_g");
			HX_STACK_LINE(440)
			while(((_g < Points->length))){
				HX_STACK_LINE(440)
				::flixel::util::FlxPoint point = Points->__get(_g).StaticCast< ::flixel::util::FlxPoint >();		HX_STACK_VAR(point,"point");
				HX_STACK_LINE(440)
				++(_g);
				HX_STACK_LINE(442)
				tween->addPoint(point->x,point->y);
			}
		}
		HX_STACK_LINE(446)
		tween->setObject(Object);
		HX_STACK_LINE(447)
		tween->setDelays(Options->__Field(HX_CSTRING("startDelay"),true),Options->__Field(HX_CSTRING("loopDelay"),true));
		HX_STACK_LINE(448)
		tween->setMotion(DurationOrSpeed,UseDuration,Options->__Field(HX_CSTRING("ease"),true));
		HX_STACK_LINE(449)
		::flixel::tweens::FlxTween_obj::manager->add(tween,null());
		HX_STACK_LINE(450)
		return tween;
	}
}


STATIC_HX_DEFINE_DYNAMIC_FUNC5(FlxTween_obj,linearPath,return )

::flixel::tweens::motion::QuadPath FlxTween_obj::quadPath( ::flixel::FlxObject Object,Array< ::Dynamic > Points,Float DurationOrSpeed,hx::Null< bool >  __o_UseDuration,Dynamic Options){
bool UseDuration = __o_UseDuration.Default(true);
	HX_STACK_FRAME("flixel.tweens.FlxTween","quadPath",0x6abb226d,"flixel.tweens.FlxTween.quadPath","flixel/tweens/FlxTween.hx",470,0x5d58d691)
	HX_STACK_ARG(Object,"Object")
	HX_STACK_ARG(Points,"Points")
	HX_STACK_ARG(DurationOrSpeed,"DurationOrSpeed")
	HX_STACK_ARG(UseDuration,"UseDuration")
	HX_STACK_ARG(Options,"Options")
{
		HX_STACK_LINE(471)
		if (((Options == null()))){
			struct _Function_2_1{
				inline static Dynamic Block( ){
					HX_STACK_FRAME("*","closure",0x5bdab937,"*.closure","flixel/tweens/FlxTween.hx",473,0x5d58d691)
					{
						hx::Anon __result = hx::Anon_obj::Create();
						__result->Add(HX_CSTRING("type") , (int)8,false);
						return __result;
					}
					return null();
				}
			};
			HX_STACK_LINE(473)
			Options = _Function_2_1::Block();
		}
		HX_STACK_LINE(476)
		::flixel::tweens::motion::QuadPath tween = ::flixel::tweens::motion::QuadPath_obj::__new(Options->__Field(HX_CSTRING("complete"),true),Options->__Field(HX_CSTRING("type"),true));		HX_STACK_VAR(tween,"tween");
		HX_STACK_LINE(478)
		if (((Points != null()))){
			HX_STACK_LINE(480)
			int _g = (int)0;		HX_STACK_VAR(_g,"_g");
			HX_STACK_LINE(480)
			while(((_g < Points->length))){
				HX_STACK_LINE(480)
				::flixel::util::FlxPoint point = Points->__get(_g).StaticCast< ::flixel::util::FlxPoint >();		HX_STACK_VAR(point,"point");
				HX_STACK_LINE(480)
				++(_g);
				HX_STACK_LINE(482)
				tween->addPoint(point->x,point->y);
			}
		}
		HX_STACK_LINE(486)
		tween->setObject(Object);
		HX_STACK_LINE(487)
		tween->setDelays(Options->__Field(HX_CSTRING("startDelay"),true),Options->__Field(HX_CSTRING("loopDelay"),true));
		HX_STACK_LINE(488)
		tween->setMotion(DurationOrSpeed,UseDuration,Options->__Field(HX_CSTRING("ease"),true));
		HX_STACK_LINE(489)
		::flixel::tweens::FlxTween_obj::manager->add(tween,null());
		HX_STACK_LINE(490)
		return tween;
	}
}


STATIC_HX_DEFINE_DYNAMIC_FUNC5(FlxTween_obj,quadPath,return )


FlxTween_obj::FlxTween_obj()
{
}

void FlxTween_obj::__Mark(HX_MARK_PARAMS)
{
	HX_MARK_BEGIN_CLASS(FlxTween);
	HX_MARK_MEMBER_NAME(active,"active");
	HX_MARK_MEMBER_NAME(complete,"complete");
	HX_MARK_MEMBER_NAME(duration,"duration");
	HX_MARK_MEMBER_NAME(ease,"ease");
	HX_MARK_MEMBER_NAME(userData,"userData");
	HX_MARK_MEMBER_NAME(type,"type");
	HX_MARK_MEMBER_NAME(finished,"finished");
	HX_MARK_MEMBER_NAME(scale,"scale");
	HX_MARK_MEMBER_NAME(backward,"backward");
	HX_MARK_MEMBER_NAME(executions,"executions");
	HX_MARK_MEMBER_NAME(startDelay,"startDelay");
	HX_MARK_MEMBER_NAME(loopDelay,"loopDelay");
	HX_MARK_MEMBER_NAME(_secondsSinceStart,"_secondsSinceStart");
	HX_MARK_MEMBER_NAME(_delayToUse,"_delayToUse");
	HX_MARK_END_CLASS();
}

void FlxTween_obj::__Visit(HX_VISIT_PARAMS)
{
	HX_VISIT_MEMBER_NAME(active,"active");
	HX_VISIT_MEMBER_NAME(complete,"complete");
	HX_VISIT_MEMBER_NAME(duration,"duration");
	HX_VISIT_MEMBER_NAME(ease,"ease");
	HX_VISIT_MEMBER_NAME(userData,"userData");
	HX_VISIT_MEMBER_NAME(type,"type");
	HX_VISIT_MEMBER_NAME(finished,"finished");
	HX_VISIT_MEMBER_NAME(scale,"scale");
	HX_VISIT_MEMBER_NAME(backward,"backward");
	HX_VISIT_MEMBER_NAME(executions,"executions");
	HX_VISIT_MEMBER_NAME(startDelay,"startDelay");
	HX_VISIT_MEMBER_NAME(loopDelay,"loopDelay");
	HX_VISIT_MEMBER_NAME(_secondsSinceStart,"_secondsSinceStart");
	HX_VISIT_MEMBER_NAME(_delayToUse,"_delayToUse");
}

Dynamic FlxTween_obj::__Field(const ::String &inName,bool inCallProp)
{
	switch(inName.length) {
	case 3:
		if (HX_FIELD_EQ(inName,"num") ) { return num_dyn(); }
		break;
	case 4:
		if (HX_FIELD_EQ(inName,"ease") ) { return ease; }
		if (HX_FIELD_EQ(inName,"type") ) { return type; }
		break;
	case 5:
		if (HX_FIELD_EQ(inName,"tween") ) { return tween_dyn(); }
		if (HX_FIELD_EQ(inName,"angle") ) { return angle_dyn(); }
		if (HX_FIELD_EQ(inName,"color") ) { return color_dyn(); }
		if (HX_FIELD_EQ(inName,"fader") ) { return fader_dyn(); }
		if (HX_FIELD_EQ(inName,"scale") ) { return scale; }
		if (HX_FIELD_EQ(inName,"start") ) { return start_dyn(); }
		break;
	case 6:
		if (HX_FIELD_EQ(inName,"active") ) { return active; }
		if (HX_FIELD_EQ(inName,"update") ) { return update_dyn(); }
		if (HX_FIELD_EQ(inName,"cancel") ) { return cancel_dyn(); }
		if (HX_FIELD_EQ(inName,"finish") ) { return finish_dyn(); }
		break;
	case 7:
		if (HX_FIELD_EQ(inName,"manager") ) { return manager; }
		if (HX_FIELD_EQ(inName,"percent") ) { return get_percent(); }
		if (HX_FIELD_EQ(inName,"destroy") ) { return destroy_dyn(); }
		break;
	case 8:
		if (HX_FIELD_EQ(inName,"multiVar") ) { return multiVar_dyn(); }
		if (HX_FIELD_EQ(inName,"quadPath") ) { return quadPath_dyn(); }
		if (HX_FIELD_EQ(inName,"complete") ) { return complete; }
		if (HX_FIELD_EQ(inName,"duration") ) { return duration; }
		if (HX_FIELD_EQ(inName,"userData") ) { return userData; }
		if (HX_FIELD_EQ(inName,"finished") ) { return finished; }
		if (HX_FIELD_EQ(inName,"backward") ) { return backward; }
		if (HX_FIELD_EQ(inName,"set_type") ) { return set_type_dyn(); }
		break;
	case 9:
		if (HX_FIELD_EQ(inName,"singleVar") ) { return singleVar_dyn(); }
		if (HX_FIELD_EQ(inName,"loopDelay") ) { return loopDelay; }
		if (HX_FIELD_EQ(inName,"setDelays") ) { return setDelays_dyn(); }
		break;
	case 10:
		if (HX_FIELD_EQ(inName,"quadMotion") ) { return quadMotion_dyn(); }
		if (HX_FIELD_EQ(inName,"linearPath") ) { return linearPath_dyn(); }
		if (HX_FIELD_EQ(inName,"executions") ) { return executions; }
		if (HX_FIELD_EQ(inName,"startDelay") ) { return startDelay; }
		break;
	case 11:
		if (HX_FIELD_EQ(inName,"cubicMotion") ) { return cubicMotion_dyn(); }
		if (HX_FIELD_EQ(inName,"_delayToUse") ) { return _delayToUse; }
		if (HX_FIELD_EQ(inName,"get_percent") ) { return get_percent_dyn(); }
		if (HX_FIELD_EQ(inName,"set_percent") ) { return set_percent_dyn(); }
		break;
	case 12:
		if (HX_FIELD_EQ(inName,"linearMotion") ) { return linearMotion_dyn(); }
		break;
	case 13:
		if (HX_FIELD_EQ(inName,"set_loopDelay") ) { return set_loopDelay_dyn(); }
		break;
	case 14:
		if (HX_FIELD_EQ(inName,"circularMotion") ) { return circularMotion_dyn(); }
		if (HX_FIELD_EQ(inName,"set_startDelay") ) { return set_startDelay_dyn(); }
		break;
	case 18:
		if (HX_FIELD_EQ(inName,"_secondsSinceStart") ) { return _secondsSinceStart; }
	}
	return super::__Field(inName,inCallProp);
}

Dynamic FlxTween_obj::__SetField(const ::String &inName,const Dynamic &inValue,bool inCallProp)
{
	switch(inName.length) {
	case 4:
		if (HX_FIELD_EQ(inName,"ease") ) { ease=inValue.Cast< Dynamic >(); return inValue; }
		if (HX_FIELD_EQ(inName,"type") ) { if (inCallProp) return set_type(inValue);type=inValue.Cast< int >(); return inValue; }
		break;
	case 5:
		if (HX_FIELD_EQ(inName,"scale") ) { scale=inValue.Cast< Float >(); return inValue; }
		break;
	case 6:
		if (HX_FIELD_EQ(inName,"active") ) { active=inValue.Cast< bool >(); return inValue; }
		break;
	case 7:
		if (HX_FIELD_EQ(inName,"manager") ) { manager=inValue.Cast< ::flixel::plugin::TweenManager >(); return inValue; }
		if (HX_FIELD_EQ(inName,"percent") ) { return set_percent(inValue); }
		break;
	case 8:
		if (HX_FIELD_EQ(inName,"complete") ) { complete=inValue.Cast< Dynamic >(); return inValue; }
		if (HX_FIELD_EQ(inName,"duration") ) { duration=inValue.Cast< Float >(); return inValue; }
		if (HX_FIELD_EQ(inName,"userData") ) { userData=inValue.Cast< Dynamic >(); return inValue; }
		if (HX_FIELD_EQ(inName,"finished") ) { finished=inValue.Cast< bool >(); return inValue; }
		if (HX_FIELD_EQ(inName,"backward") ) { backward=inValue.Cast< bool >(); return inValue; }
		break;
	case 9:
		if (HX_FIELD_EQ(inName,"loopDelay") ) { if (inCallProp) return set_loopDelay(inValue);loopDelay=inValue.Cast< Dynamic >(); return inValue; }
		break;
	case 10:
		if (HX_FIELD_EQ(inName,"executions") ) { executions=inValue.Cast< int >(); return inValue; }
		if (HX_FIELD_EQ(inName,"startDelay") ) { if (inCallProp) return set_startDelay(inValue);startDelay=inValue.Cast< Dynamic >(); return inValue; }
		break;
	case 11:
		if (HX_FIELD_EQ(inName,"_delayToUse") ) { _delayToUse=inValue.Cast< Float >(); return inValue; }
		break;
	case 18:
		if (HX_FIELD_EQ(inName,"_secondsSinceStart") ) { _secondsSinceStart=inValue.Cast< Float >(); return inValue; }
	}
	return super::__SetField(inName,inValue,inCallProp);
}

void FlxTween_obj::__GetFields(Array< ::String> &outFields)
{
	outFields->push(HX_CSTRING("active"));
	outFields->push(HX_CSTRING("duration"));
	outFields->push(HX_CSTRING("userData"));
	outFields->push(HX_CSTRING("type"));
	outFields->push(HX_CSTRING("percent"));
	outFields->push(HX_CSTRING("finished"));
	outFields->push(HX_CSTRING("scale"));
	outFields->push(HX_CSTRING("backward"));
	outFields->push(HX_CSTRING("executions"));
	outFields->push(HX_CSTRING("startDelay"));
	outFields->push(HX_CSTRING("loopDelay"));
	outFields->push(HX_CSTRING("_secondsSinceStart"));
	outFields->push(HX_CSTRING("_delayToUse"));
	super::__GetFields(outFields);
};

static ::String sStaticFields[] = {
	HX_CSTRING("PERSIST"),
	HX_CSTRING("LOOPING"),
	HX_CSTRING("PINGPONG"),
	HX_CSTRING("ONESHOT"),
	HX_CSTRING("BACKWARD"),
	HX_CSTRING("manager"),
	HX_CSTRING("tween"),
	HX_CSTRING("singleVar"),
	HX_CSTRING("multiVar"),
	HX_CSTRING("num"),
	HX_CSTRING("angle"),
	HX_CSTRING("color"),
	HX_CSTRING("fader"),
	HX_CSTRING("linearMotion"),
	HX_CSTRING("quadMotion"),
	HX_CSTRING("cubicMotion"),
	HX_CSTRING("circularMotion"),
	HX_CSTRING("linearPath"),
	HX_CSTRING("quadPath"),
	String(null()) };

#if HXCPP_SCRIPTABLE
static hx::StorageInfo sMemberStorageInfo[] = {
	{hx::fsBool,(int)offsetof(FlxTween_obj,active),HX_CSTRING("active")},
	{hx::fsObject /*Dynamic*/ ,(int)offsetof(FlxTween_obj,complete),HX_CSTRING("complete")},
	{hx::fsFloat,(int)offsetof(FlxTween_obj,duration),HX_CSTRING("duration")},
	{hx::fsObject /*Dynamic*/ ,(int)offsetof(FlxTween_obj,ease),HX_CSTRING("ease")},
	{hx::fsObject /*Dynamic*/ ,(int)offsetof(FlxTween_obj,userData),HX_CSTRING("userData")},
	{hx::fsInt,(int)offsetof(FlxTween_obj,type),HX_CSTRING("type")},
	{hx::fsBool,(int)offsetof(FlxTween_obj,finished),HX_CSTRING("finished")},
	{hx::fsFloat,(int)offsetof(FlxTween_obj,scale),HX_CSTRING("scale")},
	{hx::fsBool,(int)offsetof(FlxTween_obj,backward),HX_CSTRING("backward")},
	{hx::fsInt,(int)offsetof(FlxTween_obj,executions),HX_CSTRING("executions")},
	{hx::fsObject /*Dynamic*/ ,(int)offsetof(FlxTween_obj,startDelay),HX_CSTRING("startDelay")},
	{hx::fsObject /*Dynamic*/ ,(int)offsetof(FlxTween_obj,loopDelay),HX_CSTRING("loopDelay")},
	{hx::fsFloat,(int)offsetof(FlxTween_obj,_secondsSinceStart),HX_CSTRING("_secondsSinceStart")},
	{hx::fsFloat,(int)offsetof(FlxTween_obj,_delayToUse),HX_CSTRING("_delayToUse")},
	{ hx::fsUnknown, 0, null()}
};
#endif

static ::String sMemberFields[] = {
	HX_CSTRING("active"),
	HX_CSTRING("complete"),
	HX_CSTRING("duration"),
	HX_CSTRING("ease"),
	HX_CSTRING("userData"),
	HX_CSTRING("type"),
	HX_CSTRING("finished"),
	HX_CSTRING("scale"),
	HX_CSTRING("backward"),
	HX_CSTRING("executions"),
	HX_CSTRING("startDelay"),
	HX_CSTRING("loopDelay"),
	HX_CSTRING("_secondsSinceStart"),
	HX_CSTRING("_delayToUse"),
	HX_CSTRING("destroy"),
	HX_CSTRING("update"),
	HX_CSTRING("start"),
	HX_CSTRING("cancel"),
	HX_CSTRING("finish"),
	HX_CSTRING("setDelays"),
	HX_CSTRING("set_startDelay"),
	HX_CSTRING("set_loopDelay"),
	HX_CSTRING("get_percent"),
	HX_CSTRING("set_percent"),
	HX_CSTRING("set_type"),
	String(null()) };

static void sMarkStatics(HX_MARK_PARAMS) {
	HX_MARK_MEMBER_NAME(FlxTween_obj::__mClass,"__mClass");
	HX_MARK_MEMBER_NAME(FlxTween_obj::PERSIST,"PERSIST");
	HX_MARK_MEMBER_NAME(FlxTween_obj::LOOPING,"LOOPING");
	HX_MARK_MEMBER_NAME(FlxTween_obj::PINGPONG,"PINGPONG");
	HX_MARK_MEMBER_NAME(FlxTween_obj::ONESHOT,"ONESHOT");
	HX_MARK_MEMBER_NAME(FlxTween_obj::BACKWARD,"BACKWARD");
	HX_MARK_MEMBER_NAME(FlxTween_obj::manager,"manager");
};

#ifdef HXCPP_VISIT_ALLOCS
static void sVisitStatics(HX_VISIT_PARAMS) {
	HX_VISIT_MEMBER_NAME(FlxTween_obj::__mClass,"__mClass");
	HX_VISIT_MEMBER_NAME(FlxTween_obj::PERSIST,"PERSIST");
	HX_VISIT_MEMBER_NAME(FlxTween_obj::LOOPING,"LOOPING");
	HX_VISIT_MEMBER_NAME(FlxTween_obj::PINGPONG,"PINGPONG");
	HX_VISIT_MEMBER_NAME(FlxTween_obj::ONESHOT,"ONESHOT");
	HX_VISIT_MEMBER_NAME(FlxTween_obj::BACKWARD,"BACKWARD");
	HX_VISIT_MEMBER_NAME(FlxTween_obj::manager,"manager");
};

#endif

Class FlxTween_obj::__mClass;

void FlxTween_obj::__register()
{
	hx::Static(__mClass) = hx::RegisterClass(HX_CSTRING("flixel.tweens.FlxTween"), hx::TCanCast< FlxTween_obj> ,sStaticFields,sMemberFields,
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

void FlxTween_obj::__boot()
{
	PERSIST= (int)1;
	LOOPING= (int)2;
	PINGPONG= (int)4;
	ONESHOT= (int)8;
	BACKWARD= (int)16;
}

} // end namespace flixel
} // end namespace tweens
