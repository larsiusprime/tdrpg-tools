#include <hxcpp.h>

#ifndef INCLUDED_IMap
#include <IMap.h>
#endif
#ifndef INCLUDED_Std
#include <Std.h>
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
#ifndef INCLUDED_flixel_effects_FlxFlicker
#include <flixel/effects/FlxFlicker.h>
#endif
#ifndef INCLUDED_flixel_interfaces_IFlxDestroyable
#include <flixel/interfaces/IFlxDestroyable.h>
#endif
#ifndef INCLUDED_flixel_util_FlxPool_flixel_effects_FlxFlicker
#include <flixel/util/FlxPool_flixel_effects_FlxFlicker.h>
#endif
#ifndef INCLUDED_flixel_util_FlxTimer
#include <flixel/util/FlxTimer.h>
#endif
#ifndef INCLUDED_haxe_ds_IntMap
#include <haxe/ds/IntMap.h>
#endif
#ifndef INCLUDED_haxe_ds_ObjectMap
#include <haxe/ds/ObjectMap.h>
#endif
namespace flixel{
namespace effects{

Void FlxFlicker_obj::__construct()
{
HX_STACK_FRAME("flixel.effects.FlxFlicker","new",0x4bc826b6,"flixel.effects.FlxFlicker.new","flixel/effects/FlxFlicker.hx",61,0x4fa53f38)
{
}
;
	return null();
}

//FlxFlicker_obj::~FlxFlicker_obj() { }

Dynamic FlxFlicker_obj::__CreateEmpty() { return  new FlxFlicker_obj; }
hx::ObjectPtr< FlxFlicker_obj > FlxFlicker_obj::__new()
{  hx::ObjectPtr< FlxFlicker_obj > result = new FlxFlicker_obj();
	result->__construct();
	return result;}

Dynamic FlxFlicker_obj::__Create(hx::DynamicArray inArgs)
{  hx::ObjectPtr< FlxFlicker_obj > result = new FlxFlicker_obj();
	result->__construct();
	return result;}

Void FlxFlicker_obj::reset( ::flixel::FlxObject Object,Float Duration,Float Interval,bool EndVisibility,Dynamic CompletionCallback,Dynamic ProgressCallback){
{
		HX_STACK_FRAME("flixel.effects.FlxFlicker","reset",0x38bf61a5,"flixel.effects.FlxFlicker.reset","flixel/effects/FlxFlicker.hx",99,0x4fa53f38)
		HX_STACK_THIS(this)
		HX_STACK_ARG(Object,"Object")
		HX_STACK_ARG(Duration,"Duration")
		HX_STACK_ARG(Interval,"Interval")
		HX_STACK_ARG(EndVisibility,"EndVisibility")
		HX_STACK_ARG(CompletionCallback,"CompletionCallback")
		HX_STACK_ARG(ProgressCallback,"ProgressCallback")
		HX_STACK_LINE(100)
		this->object = Object;
		HX_STACK_LINE(101)
		this->duration = Duration;
		HX_STACK_LINE(102)
		this->interval = Interval;
		HX_STACK_LINE(103)
		this->completionCallback = CompletionCallback;
		HX_STACK_LINE(104)
		this->progressCallback = ProgressCallback;
		HX_STACK_LINE(105)
		this->endVisibility = EndVisibility;
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC6(FlxFlicker_obj,reset,(void))

Void FlxFlicker_obj::start( ){
{
		HX_STACK_FRAME("flixel.effects.FlxFlicker","start",0xd6028c38,"flixel.effects.FlxFlicker.start","flixel/effects/FlxFlicker.hx",112,0x4fa53f38)
		HX_STACK_THIS(this)
		HX_STACK_LINE(113)
		this->timer = ::flixel::util::FlxTimer_obj::recycle();
		HX_STACK_LINE(114)
		this->timer->run(this->interval,this->flickerProgress_dyn(),::Std_obj::_int((Float(this->duration) / Float(this->interval))));
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC0(FlxFlicker_obj,start,(void))

Void FlxFlicker_obj::stop( ){
{
		HX_STACK_FRAME("flixel.effects.FlxFlicker","stop",0x06b324ec,"flixel.effects.FlxFlicker.stop","flixel/effects/FlxFlicker.hx",121,0x4fa53f38)
		HX_STACK_THIS(this)
		HX_STACK_LINE(122)
		this->timer->abort();
		HX_STACK_LINE(123)
		this->object->set_visible(true);
		HX_STACK_LINE(124)
		this->release();
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC0(FlxFlicker_obj,stop,(void))

Void FlxFlicker_obj::release( ){
{
		HX_STACK_FRAME("flixel.effects.FlxFlicker","release",0x68babf1d,"flixel.effects.FlxFlicker.release","flixel/effects/FlxFlicker.hx",131,0x4fa53f38)
		HX_STACK_THIS(this)
		HX_STACK_LINE(132)
		::flixel::effects::FlxFlicker_obj::_boundObjects->remove(this->object);
		HX_STACK_LINE(133)
		::flixel::effects::FlxFlicker_obj::put(hx::ObjectPtr<OBJ_>(this));
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC0(FlxFlicker_obj,release,(void))

Void FlxFlicker_obj::flickerProgress( ::flixel::util::FlxTimer Timer){
{
		HX_STACK_FRAME("flixel.effects.FlxFlicker","flickerProgress",0x5258c61b,"flixel.effects.FlxFlicker.flickerProgress","flixel/effects/FlxFlicker.hx",140,0x4fa53f38)
		HX_STACK_THIS(this)
		HX_STACK_ARG(Timer,"Timer")
		HX_STACK_LINE(141)
		this->object->set_visible(!(this->object->visible));
		HX_STACK_LINE(143)
		if (((this->progressCallback_dyn() != null()))){
			HX_STACK_LINE(145)
			this->progressCallback(hx::ObjectPtr<OBJ_>(this));
		}
		HX_STACK_LINE(148)
		if (((bool((Timer->loops > (int)0)) && bool(((Timer->loops - Timer->_loopsCounter) == (int)0))))){
			HX_STACK_LINE(150)
			this->object->set_visible(this->endVisibility);
			HX_STACK_LINE(151)
			if (((this->completionCallback_dyn() != null()))){
				HX_STACK_LINE(153)
				this->completionCallback(hx::ObjectPtr<OBJ_>(this));
			}
			HX_STACK_LINE(155)
			this->release();
		}
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC1(FlxFlicker_obj,flickerProgress,(void))

Void FlxFlicker_obj::destroy( ){
{
		HX_STACK_FRAME("flixel.effects.FlxFlicker","destroy",0x34536650,"flixel.effects.FlxFlicker.destroy","flixel/effects/FlxFlicker.hx",163,0x4fa53f38)
		HX_STACK_THIS(this)
		HX_STACK_LINE(164)
		this->object = null();
		HX_STACK_LINE(165)
		this->timer = null();
		HX_STACK_LINE(166)
		this->completionCallback = null();
		HX_STACK_LINE(167)
		this->progressCallback = null();
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC0(FlxFlicker_obj,destroy,(void))

::flixel::util::FlxPool_flixel_effects_FlxFlicker FlxFlicker_obj::_pool;

::haxe::ds::ObjectMap FlxFlicker_obj::_boundObjects;

::flixel::effects::FlxFlicker FlxFlicker_obj::recycle( ::flixel::FlxObject Object,Float Duration,Float Interval,bool EndVisibility,Dynamic CompletionCallback,Dynamic ProgressCallback){
	HX_STACK_FRAME("flixel.effects.FlxFlicker","recycle",0x47594969,"flixel.effects.FlxFlicker.recycle","flixel/effects/FlxFlicker.hx",74,0x4fa53f38)
	HX_STACK_ARG(Object,"Object")
	HX_STACK_ARG(Duration,"Duration")
	HX_STACK_ARG(Interval,"Interval")
	HX_STACK_ARG(EndVisibility,"EndVisibility")
	HX_STACK_ARG(CompletionCallback,"CompletionCallback")
	HX_STACK_ARG(ProgressCallback,"ProgressCallback")
	HX_STACK_LINE(75)
	::flixel::effects::FlxFlicker flicker;		HX_STACK_VAR(flicker,"flicker");
	HX_STACK_LINE(75)
	{
		HX_STACK_LINE(75)
		::flixel::effects::FlxFlicker obj = ::flixel::effects::FlxFlicker_obj::_pool->_pool->pop().StaticCast< ::flixel::effects::FlxFlicker >();		HX_STACK_VAR(obj,"obj");
		HX_STACK_LINE(75)
		if (((obj == null()))){
			HX_STACK_LINE(75)
			obj = ::flixel::effects::FlxFlicker_obj::__new();
		}
		HX_STACK_LINE(75)
		flicker = obj;
	}
	HX_STACK_LINE(76)
	flicker->reset(Object,Duration,Interval,EndVisibility,CompletionCallback,ProgressCallback);
	HX_STACK_LINE(77)
	return flicker;
}


STATIC_HX_DEFINE_DYNAMIC_FUNC6(FlxFlicker_obj,recycle,return )

Void FlxFlicker_obj::put( ::flixel::effects::FlxFlicker Flicker){
{
		HX_STACK_FRAME("flixel.effects.FlxFlicker","put",0x4bc9b925,"flixel.effects.FlxFlicker.put","flixel/effects/FlxFlicker.hx",86,0x4fa53f38)
		HX_STACK_ARG(Flicker,"Flicker")
		HX_STACK_LINE(86)
		::flixel::effects::FlxFlicker_obj::_pool->put(Flicker);
	}
return null();
}


STATIC_HX_DEFINE_DYNAMIC_FUNC1(FlxFlicker_obj,put,(void))

Void FlxFlicker_obj::flicker( ::flixel::FlxObject Object,hx::Null< Float >  __o_Duration,hx::Null< Float >  __o_Interval,hx::Null< bool >  __o_EndVisibility,hx::Null< bool >  __o_ForceRestart,Dynamic CompletionCallback,Dynamic ProgressCallback){
Float Duration = __o_Duration.Default(1);
Float Interval = __o_Interval.Default(0.04);
bool EndVisibility = __o_EndVisibility.Default(true);
bool ForceRestart = __o_ForceRestart.Default(true);
	HX_STACK_FRAME("flixel.effects.FlxFlicker","flicker",0x86ba144e,"flixel.effects.FlxFlicker.flicker","flixel/effects/FlxFlicker.hx",184,0x4fa53f38)
	HX_STACK_ARG(Object,"Object")
	HX_STACK_ARG(Duration,"Duration")
	HX_STACK_ARG(Interval,"Interval")
	HX_STACK_ARG(EndVisibility,"EndVisibility")
	HX_STACK_ARG(ForceRestart,"ForceRestart")
	HX_STACK_ARG(CompletionCallback,"CompletionCallback")
	HX_STACK_ARG(ProgressCallback,"ProgressCallback")
{
		HX_STACK_LINE(185)
		if ((::flixel::effects::FlxFlicker_obj::isFlickering(Object))){
			HX_STACK_LINE(187)
			if ((ForceRestart)){
				HX_STACK_LINE(189)
				::flixel::effects::FlxFlicker_obj::stopFlickering(Object);
			}
			else{
				HX_STACK_LINE(194)
				return null();
			}
		}
		HX_STACK_LINE(198)
		if (((Interval <= (int)0))){
			HX_STACK_LINE(200)
			Interval = ::flixel::FlxG_obj::elapsed;
		}
		HX_STACK_LINE(203)
		::flixel::effects::FlxFlicker fl = ::flixel::effects::FlxFlicker_obj::recycle(Object,Duration,Interval,EndVisibility,CompletionCallback,ProgressCallback);		HX_STACK_VAR(fl,"fl");
		HX_STACK_LINE(204)
		{
			HX_STACK_LINE(204)
			::flixel::effects::FlxFlicker_obj::_boundObjects->set(Object,fl);
			HX_STACK_LINE(204)
			fl;
		}
		HX_STACK_LINE(205)
		fl->start();
	}
return null();
}


STATIC_HX_DEFINE_DYNAMIC_FUNC7(FlxFlicker_obj,flicker,(void))

bool FlxFlicker_obj::isFlickering( ::flixel::FlxObject Object){
	HX_STACK_FRAME("flixel.effects.FlxFlicker","isFlickering",0x76c8b45e,"flixel.effects.FlxFlicker.isFlickering","flixel/effects/FlxFlicker.hx",214,0x4fa53f38)
	HX_STACK_ARG(Object,"Object")
	HX_STACK_LINE(214)
	return ::flixel::effects::FlxFlicker_obj::_boundObjects->__Internal->exists(::__hxcpp_obj_id(Object));
}


STATIC_HX_DEFINE_DYNAMIC_FUNC1(FlxFlicker_obj,isFlickering,return )

Void FlxFlicker_obj::stopFlickering( ::flixel::FlxObject Object){
{
		HX_STACK_FRAME("flixel.effects.FlxFlicker","stopFlickering",0xf09864f6,"flixel.effects.FlxFlicker.stopFlickering","flixel/effects/FlxFlicker.hx",222,0x4fa53f38)
		HX_STACK_ARG(Object,"Object")
		HX_STACK_LINE(223)
		::flixel::effects::FlxFlicker boundFlicker = ::flixel::effects::FlxFlicker_obj::_boundObjects->get(Object);		HX_STACK_VAR(boundFlicker,"boundFlicker");
		HX_STACK_LINE(224)
		if (((boundFlicker != null()))){
			HX_STACK_LINE(226)
			boundFlicker->stop();
		}
	}
return null();
}


STATIC_HX_DEFINE_DYNAMIC_FUNC1(FlxFlicker_obj,stopFlickering,(void))


FlxFlicker_obj::FlxFlicker_obj()
{
}

void FlxFlicker_obj::__Mark(HX_MARK_PARAMS)
{
	HX_MARK_BEGIN_CLASS(FlxFlicker);
	HX_MARK_MEMBER_NAME(object,"object");
	HX_MARK_MEMBER_NAME(endVisibility,"endVisibility");
	HX_MARK_MEMBER_NAME(timer,"timer");
	HX_MARK_MEMBER_NAME(completionCallback,"completionCallback");
	HX_MARK_MEMBER_NAME(progressCallback,"progressCallback");
	HX_MARK_MEMBER_NAME(duration,"duration");
	HX_MARK_MEMBER_NAME(interval,"interval");
	HX_MARK_END_CLASS();
}

void FlxFlicker_obj::__Visit(HX_VISIT_PARAMS)
{
	HX_VISIT_MEMBER_NAME(object,"object");
	HX_VISIT_MEMBER_NAME(endVisibility,"endVisibility");
	HX_VISIT_MEMBER_NAME(timer,"timer");
	HX_VISIT_MEMBER_NAME(completionCallback,"completionCallback");
	HX_VISIT_MEMBER_NAME(progressCallback,"progressCallback");
	HX_VISIT_MEMBER_NAME(duration,"duration");
	HX_VISIT_MEMBER_NAME(interval,"interval");
}

Dynamic FlxFlicker_obj::__Field(const ::String &inName,bool inCallProp)
{
	switch(inName.length) {
	case 3:
		if (HX_FIELD_EQ(inName,"put") ) { return put_dyn(); }
		break;
	case 4:
		if (HX_FIELD_EQ(inName,"stop") ) { return stop_dyn(); }
		break;
	case 5:
		if (HX_FIELD_EQ(inName,"_pool") ) { return _pool; }
		if (HX_FIELD_EQ(inName,"timer") ) { return timer; }
		if (HX_FIELD_EQ(inName,"reset") ) { return reset_dyn(); }
		if (HX_FIELD_EQ(inName,"start") ) { return start_dyn(); }
		break;
	case 6:
		if (HX_FIELD_EQ(inName,"object") ) { return object; }
		break;
	case 7:
		if (HX_FIELD_EQ(inName,"recycle") ) { return recycle_dyn(); }
		if (HX_FIELD_EQ(inName,"flicker") ) { return flicker_dyn(); }
		if (HX_FIELD_EQ(inName,"release") ) { return release_dyn(); }
		if (HX_FIELD_EQ(inName,"destroy") ) { return destroy_dyn(); }
		break;
	case 8:
		if (HX_FIELD_EQ(inName,"duration") ) { return duration; }
		if (HX_FIELD_EQ(inName,"interval") ) { return interval; }
		break;
	case 12:
		if (HX_FIELD_EQ(inName,"isFlickering") ) { return isFlickering_dyn(); }
		break;
	case 13:
		if (HX_FIELD_EQ(inName,"_boundObjects") ) { return _boundObjects; }
		if (HX_FIELD_EQ(inName,"endVisibility") ) { return endVisibility; }
		break;
	case 14:
		if (HX_FIELD_EQ(inName,"stopFlickering") ) { return stopFlickering_dyn(); }
		break;
	case 15:
		if (HX_FIELD_EQ(inName,"flickerProgress") ) { return flickerProgress_dyn(); }
		break;
	case 16:
		if (HX_FIELD_EQ(inName,"progressCallback") ) { return progressCallback; }
		break;
	case 18:
		if (HX_FIELD_EQ(inName,"completionCallback") ) { return completionCallback; }
	}
	return super::__Field(inName,inCallProp);
}

Dynamic FlxFlicker_obj::__SetField(const ::String &inName,const Dynamic &inValue,bool inCallProp)
{
	switch(inName.length) {
	case 5:
		if (HX_FIELD_EQ(inName,"_pool") ) { _pool=inValue.Cast< ::flixel::util::FlxPool_flixel_effects_FlxFlicker >(); return inValue; }
		if (HX_FIELD_EQ(inName,"timer") ) { timer=inValue.Cast< ::flixel::util::FlxTimer >(); return inValue; }
		break;
	case 6:
		if (HX_FIELD_EQ(inName,"object") ) { object=inValue.Cast< ::flixel::FlxObject >(); return inValue; }
		break;
	case 8:
		if (HX_FIELD_EQ(inName,"duration") ) { duration=inValue.Cast< Float >(); return inValue; }
		if (HX_FIELD_EQ(inName,"interval") ) { interval=inValue.Cast< Float >(); return inValue; }
		break;
	case 13:
		if (HX_FIELD_EQ(inName,"_boundObjects") ) { _boundObjects=inValue.Cast< ::haxe::ds::ObjectMap >(); return inValue; }
		if (HX_FIELD_EQ(inName,"endVisibility") ) { endVisibility=inValue.Cast< bool >(); return inValue; }
		break;
	case 16:
		if (HX_FIELD_EQ(inName,"progressCallback") ) { progressCallback=inValue.Cast< Dynamic >(); return inValue; }
		break;
	case 18:
		if (HX_FIELD_EQ(inName,"completionCallback") ) { completionCallback=inValue.Cast< Dynamic >(); return inValue; }
	}
	return super::__SetField(inName,inValue,inCallProp);
}

void FlxFlicker_obj::__GetFields(Array< ::String> &outFields)
{
	outFields->push(HX_CSTRING("object"));
	outFields->push(HX_CSTRING("endVisibility"));
	outFields->push(HX_CSTRING("timer"));
	outFields->push(HX_CSTRING("duration"));
	outFields->push(HX_CSTRING("interval"));
	super::__GetFields(outFields);
};

static ::String sStaticFields[] = {
	HX_CSTRING("_pool"),
	HX_CSTRING("_boundObjects"),
	HX_CSTRING("recycle"),
	HX_CSTRING("put"),
	HX_CSTRING("flicker"),
	HX_CSTRING("isFlickering"),
	HX_CSTRING("stopFlickering"),
	String(null()) };

#if HXCPP_SCRIPTABLE
static hx::StorageInfo sMemberStorageInfo[] = {
	{hx::fsObject /*::flixel::FlxObject*/ ,(int)offsetof(FlxFlicker_obj,object),HX_CSTRING("object")},
	{hx::fsBool,(int)offsetof(FlxFlicker_obj,endVisibility),HX_CSTRING("endVisibility")},
	{hx::fsObject /*::flixel::util::FlxTimer*/ ,(int)offsetof(FlxFlicker_obj,timer),HX_CSTRING("timer")},
	{hx::fsObject /*Dynamic*/ ,(int)offsetof(FlxFlicker_obj,completionCallback),HX_CSTRING("completionCallback")},
	{hx::fsObject /*Dynamic*/ ,(int)offsetof(FlxFlicker_obj,progressCallback),HX_CSTRING("progressCallback")},
	{hx::fsFloat,(int)offsetof(FlxFlicker_obj,duration),HX_CSTRING("duration")},
	{hx::fsFloat,(int)offsetof(FlxFlicker_obj,interval),HX_CSTRING("interval")},
	{ hx::fsUnknown, 0, null()}
};
#endif

static ::String sMemberFields[] = {
	HX_CSTRING("object"),
	HX_CSTRING("endVisibility"),
	HX_CSTRING("timer"),
	HX_CSTRING("completionCallback"),
	HX_CSTRING("progressCallback"),
	HX_CSTRING("duration"),
	HX_CSTRING("interval"),
	HX_CSTRING("reset"),
	HX_CSTRING("start"),
	HX_CSTRING("stop"),
	HX_CSTRING("release"),
	HX_CSTRING("flickerProgress"),
	HX_CSTRING("destroy"),
	String(null()) };

static void sMarkStatics(HX_MARK_PARAMS) {
	HX_MARK_MEMBER_NAME(FlxFlicker_obj::__mClass,"__mClass");
	HX_MARK_MEMBER_NAME(FlxFlicker_obj::_pool,"_pool");
	HX_MARK_MEMBER_NAME(FlxFlicker_obj::_boundObjects,"_boundObjects");
};

#ifdef HXCPP_VISIT_ALLOCS
static void sVisitStatics(HX_VISIT_PARAMS) {
	HX_VISIT_MEMBER_NAME(FlxFlicker_obj::__mClass,"__mClass");
	HX_VISIT_MEMBER_NAME(FlxFlicker_obj::_pool,"_pool");
	HX_VISIT_MEMBER_NAME(FlxFlicker_obj::_boundObjects,"_boundObjects");
};

#endif

Class FlxFlicker_obj::__mClass;

void FlxFlicker_obj::__register()
{
	hx::Static(__mClass) = hx::RegisterClass(HX_CSTRING("flixel.effects.FlxFlicker"), hx::TCanCast< FlxFlicker_obj> ,sStaticFields,sMemberFields,
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

void FlxFlicker_obj::__boot()
{
	_pool= ::flixel::util::FlxPool_flixel_effects_FlxFlicker_obj::__new();
	_boundObjects= ::haxe::ds::ObjectMap_obj::__new();
}

} // end namespace flixel
} // end namespace effects
