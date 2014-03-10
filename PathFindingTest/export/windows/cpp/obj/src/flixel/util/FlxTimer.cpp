#include <hxcpp.h>

#ifndef INCLUDED_flixel_FlxBasic
#include <flixel/FlxBasic.h>
#endif
#ifndef INCLUDED_flixel_FlxG
#include <flixel/FlxG.h>
#endif
#ifndef INCLUDED_flixel_interfaces_IFlxDestroyable
#include <flixel/interfaces/IFlxDestroyable.h>
#endif
#ifndef INCLUDED_flixel_plugin_FlxPlugin
#include <flixel/plugin/FlxPlugin.h>
#endif
#ifndef INCLUDED_flixel_plugin_TimerManager
#include <flixel/plugin/TimerManager.h>
#endif
#ifndef INCLUDED_flixel_util_FlxPool_flixel_util_FlxTimer
#include <flixel/util/FlxPool_flixel_util_FlxTimer.h>
#endif
#ifndef INCLUDED_flixel_util_FlxTimer
#include <flixel/util/FlxTimer.h>
#endif
#ifndef INCLUDED_hxMath
#include <hxMath.h>
#endif
namespace flixel{
namespace util{

Void FlxTimer_obj::__construct()
{
HX_STACK_FRAME("flixel.util.FlxTimer","new",0xb89241df,"flixel.util.FlxTimer.new","flixel/util/FlxTimer.hx",12,0x0a681e11)
{
	HX_STACK_LINE(53)
	this->_loopsCounter = (int)0;
	HX_STACK_LINE(49)
	this->_timeCounter = (int)0;
	HX_STACK_LINE(45)
	this->complete = null();
	HX_STACK_LINE(40)
	this->usePooling = true;
	HX_STACK_LINE(36)
	this->userData = null();
	HX_STACK_LINE(31)
	this->finished = false;
	HX_STACK_LINE(27)
	this->paused = false;
	HX_STACK_LINE(23)
	this->loops = (int)0;
	HX_STACK_LINE(19)
	this->time = (int)0;
}
;
	return null();
}

//FlxTimer_obj::~FlxTimer_obj() { }

Dynamic FlxTimer_obj::__CreateEmpty() { return  new FlxTimer_obj; }
hx::ObjectPtr< FlxTimer_obj > FlxTimer_obj::__new()
{  hx::ObjectPtr< FlxTimer_obj > result = new FlxTimer_obj();
	result->__construct();
	return result;}

Dynamic FlxTimer_obj::__Create(hx::DynamicArray inArgs)
{  hx::ObjectPtr< FlxTimer_obj > result = new FlxTimer_obj();
	result->__construct();
	return result;}

Void FlxTimer_obj::destroy( ){
{
		HX_STACK_FRAME("flixel.util.FlxTimer","destroy",0x3b34c9f9,"flixel.util.FlxTimer.destroy","flixel/util/FlxTimer.hx",65,0x0a681e11)
		HX_STACK_THIS(this)
		HX_STACK_LINE(66)
		this->complete = null();
		HX_STACK_LINE(67)
		this->userData = null();
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC0(FlxTimer_obj,destroy,(void))

Void FlxTimer_obj::run( hx::Null< Float >  __o_Time,Dynamic Callback,hx::Null< int >  __o_Loops){
Float Time = __o_Time.Default(1);
int Loops = __o_Loops.Default(1);
	HX_STACK_FRAME("flixel.util.FlxTimer","run",0xb89558ca,"flixel.util.FlxTimer.run","flixel/util/FlxTimer.hx",101,0x0a681e11)
	HX_STACK_THIS(this)
	HX_STACK_ARG(Time,"Time")
	HX_STACK_ARG(Callback,"Callback")
	HX_STACK_ARG(Loops,"Loops")
{
		HX_STACK_LINE(102)
		if (((::flixel::util::FlxTimer_obj::manager != null()))){
			HX_STACK_LINE(104)
			::flixel::util::FlxTimer_obj::manager->add(hx::ObjectPtr<OBJ_>(this));
		}
		HX_STACK_LINE(107)
		this->paused = false;
		HX_STACK_LINE(108)
		this->finished = false;
		HX_STACK_LINE(109)
		this->time = ::Math_obj::abs(Time);
		HX_STACK_LINE(111)
		if (((Loops < (int)0))){
			HX_STACK_LINE(113)
			hx::MultEq(Loops,(int)-1);
		}
		HX_STACK_LINE(116)
		this->loops = Loops;
		HX_STACK_LINE(117)
		this->complete = Callback;
		HX_STACK_LINE(118)
		this->_timeCounter = (int)0;
		HX_STACK_LINE(119)
		this->_loopsCounter = (int)0;
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC3(FlxTimer_obj,run,(void))

::flixel::util::FlxTimer FlxTimer_obj::reset( hx::Null< Float >  __o_NewTime){
Float NewTime = __o_NewTime.Default(-1);
	HX_STACK_FRAME("flixel.util.FlxTimer","reset",0x00a5590e,"flixel.util.FlxTimer.reset","flixel/util/FlxTimer.hx",127,0x0a681e11)
	HX_STACK_THIS(this)
	HX_STACK_ARG(NewTime,"NewTime")
{
		HX_STACK_LINE(128)
		if (((NewTime < (int)0))){
			HX_STACK_LINE(130)
			NewTime = this->time;
		}
		HX_STACK_LINE(132)
		this->run(NewTime,this->complete_dyn(),this->loops);
		HX_STACK_LINE(133)
		return hx::ObjectPtr<OBJ_>(this);
	}
}


HX_DEFINE_DYNAMIC_FUNC1(FlxTimer_obj,reset,return )

Void FlxTimer_obj::abort( ){
{
		HX_STACK_FRAME("flixel.util.FlxTimer","abort",0x34d6daef,"flixel.util.FlxTimer.abort","flixel/util/FlxTimer.hx",140,0x0a681e11)
		HX_STACK_THIS(this)
		HX_STACK_LINE(141)
		this->finished = true;
		HX_STACK_LINE(142)
		if (((::flixel::util::FlxTimer_obj::manager != null()))){
			HX_STACK_LINE(144)
			::flixel::util::FlxTimer_obj::manager->remove(hx::ObjectPtr<OBJ_>(this),this->usePooling);
		}
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC0(FlxTimer_obj,abort,(void))

Void FlxTimer_obj::update( ){
{
		HX_STACK_FRAME("flixel.util.FlxTimer","update",0x0e95cdea,"flixel.util.FlxTimer.update","flixel/util/FlxTimer.hx",155,0x0a681e11)
		HX_STACK_THIS(this)
		HX_STACK_LINE(156)
		hx::AddEq(this->_timeCounter,::flixel::FlxG_obj::elapsed);
		HX_STACK_LINE(158)
		while(((bool((bool((this->_timeCounter >= this->time)) && bool(!(this->paused)))) && bool(!(this->finished))))){
			HX_STACK_LINE(160)
			hx::SubEq(this->_timeCounter,this->time);
			HX_STACK_LINE(161)
			(this->_loopsCounter)++;
			HX_STACK_LINE(163)
			if (((this->complete_dyn() != null()))){
				HX_STACK_LINE(165)
				this->complete(hx::ObjectPtr<OBJ_>(this));
			}
			HX_STACK_LINE(168)
			if (((bool((this->loops > (int)0)) && bool((this->_loopsCounter >= this->loops))))){
				HX_STACK_LINE(170)
				this->abort();
			}
		}
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC0(FlxTimer_obj,update,(void))

Float FlxTimer_obj::get_timeLeft( ){
	HX_STACK_FRAME("flixel.util.FlxTimer","get_timeLeft",0x3108255e,"flixel.util.FlxTimer.get_timeLeft","flixel/util/FlxTimer.hx",182,0x0a681e11)
	HX_STACK_THIS(this)
	HX_STACK_LINE(182)
	return (this->time - this->_timeCounter);
}


HX_DEFINE_DYNAMIC_FUNC0(FlxTimer_obj,get_timeLeft,return )

Float FlxTimer_obj::get_elapsedTime( ){
	HX_STACK_FRAME("flixel.util.FlxTimer","get_elapsedTime",0x36d149ff,"flixel.util.FlxTimer.get_elapsedTime","flixel/util/FlxTimer.hx",192,0x0a681e11)
	HX_STACK_THIS(this)
	HX_STACK_LINE(192)
	return this->_timeCounter;
}


HX_DEFINE_DYNAMIC_FUNC0(FlxTimer_obj,get_elapsedTime,return )

int FlxTimer_obj::get_loopsLeft( ){
	HX_STACK_FRAME("flixel.util.FlxTimer","get_loopsLeft",0x92ed534c,"flixel.util.FlxTimer.get_loopsLeft","flixel/util/FlxTimer.hx",202,0x0a681e11)
	HX_STACK_THIS(this)
	HX_STACK_LINE(202)
	return (this->loops - this->_loopsCounter);
}


HX_DEFINE_DYNAMIC_FUNC0(FlxTimer_obj,get_loopsLeft,return )

int FlxTimer_obj::get_elapsedLoops( ){
	HX_STACK_FRAME("flixel.util.FlxTimer","get_elapsedLoops",0x2913a75d,"flixel.util.FlxTimer.get_elapsedLoops","flixel/util/FlxTimer.hx",212,0x0a681e11)
	HX_STACK_THIS(this)
	HX_STACK_LINE(212)
	return this->_loopsCounter;
}


HX_DEFINE_DYNAMIC_FUNC0(FlxTimer_obj,get_elapsedLoops,return )

Float FlxTimer_obj::get_progress( ){
	HX_STACK_FRAME("flixel.util.FlxTimer","get_progress",0xcf219257,"flixel.util.FlxTimer.get_progress","flixel/util/FlxTimer.hx",222,0x0a681e11)
	HX_STACK_THIS(this)
	HX_STACK_LINE(222)
	if (((this->time > (int)0))){
		HX_STACK_LINE(224)
		return (Float(this->_timeCounter) / Float(this->time));
	}
	else{
		HX_STACK_LINE(228)
		return (int)0;
	}
	HX_STACK_LINE(222)
	return 0.;
}


HX_DEFINE_DYNAMIC_FUNC0(FlxTimer_obj,get_progress,return )

::flixel::util::FlxPool_flixel_util_FlxTimer FlxTimer_obj::pool;

::flixel::util::FlxTimer FlxTimer_obj::recycle( ){
	HX_STACK_FRAME("flixel.util.FlxTimer","recycle",0x4e3aad12,"flixel.util.FlxTimer.recycle","flixel/util/FlxTimer.hx",75,0x0a681e11)
	HX_STACK_LINE(75)
	::flixel::util::FlxTimer obj = ::flixel::util::FlxTimer_obj::pool->_pool->pop().StaticCast< ::flixel::util::FlxTimer >();		HX_STACK_VAR(obj,"obj");
	HX_STACK_LINE(75)
	if (((obj == null()))){
		HX_STACK_LINE(75)
		obj = ::flixel::util::FlxTimer_obj::__new();
	}
	HX_STACK_LINE(75)
	return obj;
}


STATIC_HX_DEFINE_DYNAMIC_FUNC0(FlxTimer_obj,recycle,return )

::flixel::util::FlxTimer FlxTimer_obj::start( hx::Null< Float >  __o_Time,Dynamic Callback,hx::Null< int >  __o_Loops){
Float Time = __o_Time.Default(1);
int Loops = __o_Loops.Default(1);
	HX_STACK_FRAME("flixel.util.FlxTimer","start",0x9de883a1,"flixel.util.FlxTimer.start","flixel/util/FlxTimer.hx",86,0x0a681e11)
	HX_STACK_ARG(Time,"Time")
	HX_STACK_ARG(Callback,"Callback")
	HX_STACK_ARG(Loops,"Loops")
{
		HX_STACK_LINE(87)
		::flixel::util::FlxTimer timer = ::flixel::util::FlxTimer_obj::recycle();		HX_STACK_VAR(timer,"timer");
		HX_STACK_LINE(88)
		timer->run(Time,Callback,Loops);
		HX_STACK_LINE(89)
		return timer;
	}
}


STATIC_HX_DEFINE_DYNAMIC_FUNC3(FlxTimer_obj,start,return )

Void FlxTimer_obj::put( ::flixel::util::FlxTimer timer){
{
		HX_STACK_FRAME("flixel.util.FlxTimer","put",0xb893d44e,"flixel.util.FlxTimer.put","flixel/util/FlxTimer.hx",234,0x0a681e11)
		HX_STACK_ARG(timer,"timer")
		HX_STACK_LINE(234)
		::flixel::util::FlxTimer_obj::pool->put(timer);
	}
return null();
}


STATIC_HX_DEFINE_DYNAMIC_FUNC1(FlxTimer_obj,put,(void))

::flixel::plugin::TimerManager FlxTimer_obj::manager;


FlxTimer_obj::FlxTimer_obj()
{
}

void FlxTimer_obj::__Mark(HX_MARK_PARAMS)
{
	HX_MARK_BEGIN_CLASS(FlxTimer);
	HX_MARK_MEMBER_NAME(time,"time");
	HX_MARK_MEMBER_NAME(loops,"loops");
	HX_MARK_MEMBER_NAME(paused,"paused");
	HX_MARK_MEMBER_NAME(finished,"finished");
	HX_MARK_MEMBER_NAME(userData,"userData");
	HX_MARK_MEMBER_NAME(usePooling,"usePooling");
	HX_MARK_MEMBER_NAME(complete,"complete");
	HX_MARK_MEMBER_NAME(_timeCounter,"_timeCounter");
	HX_MARK_MEMBER_NAME(_loopsCounter,"_loopsCounter");
	HX_MARK_END_CLASS();
}

void FlxTimer_obj::__Visit(HX_VISIT_PARAMS)
{
	HX_VISIT_MEMBER_NAME(time,"time");
	HX_VISIT_MEMBER_NAME(loops,"loops");
	HX_VISIT_MEMBER_NAME(paused,"paused");
	HX_VISIT_MEMBER_NAME(finished,"finished");
	HX_VISIT_MEMBER_NAME(userData,"userData");
	HX_VISIT_MEMBER_NAME(usePooling,"usePooling");
	HX_VISIT_MEMBER_NAME(complete,"complete");
	HX_VISIT_MEMBER_NAME(_timeCounter,"_timeCounter");
	HX_VISIT_MEMBER_NAME(_loopsCounter,"_loopsCounter");
}

Dynamic FlxTimer_obj::__Field(const ::String &inName,bool inCallProp)
{
	switch(inName.length) {
	case 3:
		if (HX_FIELD_EQ(inName,"put") ) { return put_dyn(); }
		if (HX_FIELD_EQ(inName,"run") ) { return run_dyn(); }
		break;
	case 4:
		if (HX_FIELD_EQ(inName,"pool") ) { return pool; }
		if (HX_FIELD_EQ(inName,"time") ) { return time; }
		break;
	case 5:
		if (HX_FIELD_EQ(inName,"start") ) { return start_dyn(); }
		if (HX_FIELD_EQ(inName,"loops") ) { return loops; }
		if (HX_FIELD_EQ(inName,"reset") ) { return reset_dyn(); }
		if (HX_FIELD_EQ(inName,"abort") ) { return abort_dyn(); }
		break;
	case 6:
		if (HX_FIELD_EQ(inName,"paused") ) { return paused; }
		if (HX_FIELD_EQ(inName,"update") ) { return update_dyn(); }
		break;
	case 7:
		if (HX_FIELD_EQ(inName,"recycle") ) { return recycle_dyn(); }
		if (HX_FIELD_EQ(inName,"manager") ) { return manager; }
		if (HX_FIELD_EQ(inName,"destroy") ) { return destroy_dyn(); }
		break;
	case 8:
		if (HX_FIELD_EQ(inName,"finished") ) { return finished; }
		if (HX_FIELD_EQ(inName,"userData") ) { return userData; }
		if (HX_FIELD_EQ(inName,"complete") ) { return complete; }
		if (HX_FIELD_EQ(inName,"timeLeft") ) { return get_timeLeft(); }
		if (HX_FIELD_EQ(inName,"progress") ) { return get_progress(); }
		break;
	case 9:
		if (HX_FIELD_EQ(inName,"loopsLeft") ) { return get_loopsLeft(); }
		break;
	case 10:
		if (HX_FIELD_EQ(inName,"usePooling") ) { return usePooling; }
		break;
	case 11:
		if (HX_FIELD_EQ(inName,"elapsedTime") ) { return get_elapsedTime(); }
		break;
	case 12:
		if (HX_FIELD_EQ(inName,"_timeCounter") ) { return _timeCounter; }
		if (HX_FIELD_EQ(inName,"get_timeLeft") ) { return get_timeLeft_dyn(); }
		if (HX_FIELD_EQ(inName,"elapsedLoops") ) { return get_elapsedLoops(); }
		if (HX_FIELD_EQ(inName,"get_progress") ) { return get_progress_dyn(); }
		break;
	case 13:
		if (HX_FIELD_EQ(inName,"_loopsCounter") ) { return _loopsCounter; }
		if (HX_FIELD_EQ(inName,"get_loopsLeft") ) { return get_loopsLeft_dyn(); }
		break;
	case 15:
		if (HX_FIELD_EQ(inName,"get_elapsedTime") ) { return get_elapsedTime_dyn(); }
		break;
	case 16:
		if (HX_FIELD_EQ(inName,"get_elapsedLoops") ) { return get_elapsedLoops_dyn(); }
	}
	return super::__Field(inName,inCallProp);
}

Dynamic FlxTimer_obj::__SetField(const ::String &inName,const Dynamic &inValue,bool inCallProp)
{
	switch(inName.length) {
	case 4:
		if (HX_FIELD_EQ(inName,"pool") ) { pool=inValue.Cast< ::flixel::util::FlxPool_flixel_util_FlxTimer >(); return inValue; }
		if (HX_FIELD_EQ(inName,"time") ) { time=inValue.Cast< Float >(); return inValue; }
		break;
	case 5:
		if (HX_FIELD_EQ(inName,"loops") ) { loops=inValue.Cast< int >(); return inValue; }
		break;
	case 6:
		if (HX_FIELD_EQ(inName,"paused") ) { paused=inValue.Cast< bool >(); return inValue; }
		break;
	case 7:
		if (HX_FIELD_EQ(inName,"manager") ) { manager=inValue.Cast< ::flixel::plugin::TimerManager >(); return inValue; }
		break;
	case 8:
		if (HX_FIELD_EQ(inName,"finished") ) { finished=inValue.Cast< bool >(); return inValue; }
		if (HX_FIELD_EQ(inName,"userData") ) { userData=inValue.Cast< Dynamic >(); return inValue; }
		if (HX_FIELD_EQ(inName,"complete") ) { complete=inValue.Cast< Dynamic >(); return inValue; }
		break;
	case 10:
		if (HX_FIELD_EQ(inName,"usePooling") ) { usePooling=inValue.Cast< bool >(); return inValue; }
		break;
	case 12:
		if (HX_FIELD_EQ(inName,"_timeCounter") ) { _timeCounter=inValue.Cast< Float >(); return inValue; }
		break;
	case 13:
		if (HX_FIELD_EQ(inName,"_loopsCounter") ) { _loopsCounter=inValue.Cast< int >(); return inValue; }
	}
	return super::__SetField(inName,inValue,inCallProp);
}

void FlxTimer_obj::__GetFields(Array< ::String> &outFields)
{
	outFields->push(HX_CSTRING("time"));
	outFields->push(HX_CSTRING("loops"));
	outFields->push(HX_CSTRING("paused"));
	outFields->push(HX_CSTRING("finished"));
	outFields->push(HX_CSTRING("userData"));
	outFields->push(HX_CSTRING("usePooling"));
	outFields->push(HX_CSTRING("_timeCounter"));
	outFields->push(HX_CSTRING("_loopsCounter"));
	outFields->push(HX_CSTRING("timeLeft"));
	outFields->push(HX_CSTRING("elapsedTime"));
	outFields->push(HX_CSTRING("loopsLeft"));
	outFields->push(HX_CSTRING("elapsedLoops"));
	outFields->push(HX_CSTRING("progress"));
	super::__GetFields(outFields);
};

static ::String sStaticFields[] = {
	HX_CSTRING("pool"),
	HX_CSTRING("recycle"),
	HX_CSTRING("start"),
	HX_CSTRING("put"),
	HX_CSTRING("manager"),
	String(null()) };

#if HXCPP_SCRIPTABLE
static hx::StorageInfo sMemberStorageInfo[] = {
	{hx::fsFloat,(int)offsetof(FlxTimer_obj,time),HX_CSTRING("time")},
	{hx::fsInt,(int)offsetof(FlxTimer_obj,loops),HX_CSTRING("loops")},
	{hx::fsBool,(int)offsetof(FlxTimer_obj,paused),HX_CSTRING("paused")},
	{hx::fsBool,(int)offsetof(FlxTimer_obj,finished),HX_CSTRING("finished")},
	{hx::fsObject /*Dynamic*/ ,(int)offsetof(FlxTimer_obj,userData),HX_CSTRING("userData")},
	{hx::fsBool,(int)offsetof(FlxTimer_obj,usePooling),HX_CSTRING("usePooling")},
	{hx::fsObject /*Dynamic*/ ,(int)offsetof(FlxTimer_obj,complete),HX_CSTRING("complete")},
	{hx::fsFloat,(int)offsetof(FlxTimer_obj,_timeCounter),HX_CSTRING("_timeCounter")},
	{hx::fsInt,(int)offsetof(FlxTimer_obj,_loopsCounter),HX_CSTRING("_loopsCounter")},
	{ hx::fsUnknown, 0, null()}
};
#endif

static ::String sMemberFields[] = {
	HX_CSTRING("time"),
	HX_CSTRING("loops"),
	HX_CSTRING("paused"),
	HX_CSTRING("finished"),
	HX_CSTRING("userData"),
	HX_CSTRING("usePooling"),
	HX_CSTRING("complete"),
	HX_CSTRING("_timeCounter"),
	HX_CSTRING("_loopsCounter"),
	HX_CSTRING("destroy"),
	HX_CSTRING("run"),
	HX_CSTRING("reset"),
	HX_CSTRING("abort"),
	HX_CSTRING("update"),
	HX_CSTRING("get_timeLeft"),
	HX_CSTRING("get_elapsedTime"),
	HX_CSTRING("get_loopsLeft"),
	HX_CSTRING("get_elapsedLoops"),
	HX_CSTRING("get_progress"),
	String(null()) };

static void sMarkStatics(HX_MARK_PARAMS) {
	HX_MARK_MEMBER_NAME(FlxTimer_obj::__mClass,"__mClass");
	HX_MARK_MEMBER_NAME(FlxTimer_obj::pool,"pool");
	HX_MARK_MEMBER_NAME(FlxTimer_obj::manager,"manager");
};

#ifdef HXCPP_VISIT_ALLOCS
static void sVisitStatics(HX_VISIT_PARAMS) {
	HX_VISIT_MEMBER_NAME(FlxTimer_obj::__mClass,"__mClass");
	HX_VISIT_MEMBER_NAME(FlxTimer_obj::pool,"pool");
	HX_VISIT_MEMBER_NAME(FlxTimer_obj::manager,"manager");
};

#endif

Class FlxTimer_obj::__mClass;

void FlxTimer_obj::__register()
{
	hx::Static(__mClass) = hx::RegisterClass(HX_CSTRING("flixel.util.FlxTimer"), hx::TCanCast< FlxTimer_obj> ,sStaticFields,sMemberFields,
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

void FlxTimer_obj::__boot()
{
	pool= ::flixel::util::FlxPool_flixel_util_FlxTimer_obj::__new();
}

} // end namespace flixel
} // end namespace util
