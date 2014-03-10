#include <hxcpp.h>

#ifndef INCLUDED_flixel_interfaces_IFlxDestroyable
#include <flixel/interfaces/IFlxDestroyable.h>
#endif
#ifndef INCLUDED_flixel_tweens_FlxTween
#include <flixel/tweens/FlxTween.h>
#endif
#ifndef INCLUDED_flixel_tweens_motion_LinearPath
#include <flixel/tweens/motion/LinearPath.h>
#endif
#ifndef INCLUDED_flixel_tweens_motion_Motion
#include <flixel/tweens/motion/Motion.h>
#endif
#ifndef INCLUDED_flixel_util_FlxPoint
#include <flixel/util/FlxPoint.h>
#endif
#ifndef INCLUDED_hxMath
#include <hxMath.h>
#endif
namespace flixel{
namespace tweens{
namespace motion{

Void LinearPath_obj::__construct(Dynamic complete,hx::Null< int >  __o_type)
{
HX_STACK_FRAME("flixel.tweens.motion.LinearPath","new",0x6d0ffb80,"flixel.tweens.motion.LinearPath.new","flixel/tweens/motion/LinearPath.hx",35,0x519b896f)

HX_STACK_ARG(complete,"complete")

HX_STACK_ARG(__o_type,"type")
int type = __o_type.Default(0);
{
	HX_STACK_LINE(36)
	super::__construct((int)0,complete,type,null());
	HX_STACK_LINE(37)
	this->points = Array_obj< ::Dynamic >::__new();
	HX_STACK_LINE(38)
	this->_pointD = Array_obj< Float >::__new();
	HX_STACK_LINE(39)
	this->_pointT = Array_obj< Float >::__new();
	HX_STACK_LINE(41)
	this->distance = this->_speed = this->_index = (int)0;
	HX_STACK_LINE(43)
	this->_pointD[(int)0] = this->_pointT[(int)0] = (int)0;
}
;
	return null();
}

//LinearPath_obj::~LinearPath_obj() { }

Dynamic LinearPath_obj::__CreateEmpty() { return  new LinearPath_obj; }
hx::ObjectPtr< LinearPath_obj > LinearPath_obj::__new(Dynamic complete,hx::Null< int >  __o_type)
{  hx::ObjectPtr< LinearPath_obj > result = new LinearPath_obj();
	result->__construct(complete,__o_type);
	return result;}

Dynamic LinearPath_obj::__Create(hx::DynamicArray inArgs)
{  hx::ObjectPtr< LinearPath_obj > result = new LinearPath_obj();
	result->__construct(inArgs[0],inArgs[1]);
	return result;}

Void LinearPath_obj::destroy( ){
{
		HX_STACK_FRAME("flixel.tweens.motion.LinearPath","destroy",0x4706681a,"flixel.tweens.motion.LinearPath.destroy","flixel/tweens/motion/LinearPath.hx",47,0x519b896f)
		HX_STACK_THIS(this)
		HX_STACK_LINE(48)
		this->super::destroy();
		HX_STACK_LINE(49)
		this->points = null();
		HX_STACK_LINE(50)
		this->_pointD = null();
		HX_STACK_LINE(51)
		this->_pointT = null();
		HX_STACK_LINE(52)
		this->_last = null();
		HX_STACK_LINE(53)
		this->_prevPoint = null();
		HX_STACK_LINE(54)
		this->_nextPoint = null();
	}
return null();
}


::flixel::tweens::motion::LinearPath LinearPath_obj::setMotion( Float DurationOrSpeed,hx::Null< bool >  __o_UseDuration,Dynamic Ease){
bool UseDuration = __o_UseDuration.Default(true);
	HX_STACK_FRAME("flixel.tweens.motion.LinearPath","setMotion",0x1a623e98,"flixel.tweens.motion.LinearPath.setMotion","flixel/tweens/motion/LinearPath.hx",65,0x519b896f)
	HX_STACK_THIS(this)
	HX_STACK_ARG(DurationOrSpeed,"DurationOrSpeed")
	HX_STACK_ARG(UseDuration,"UseDuration")
	HX_STACK_ARG(Ease,"Ease")
{
		HX_STACK_LINE(66)
		this->updatePath();
		HX_STACK_LINE(68)
		if ((UseDuration)){
			HX_STACK_LINE(70)
			this->duration = DurationOrSpeed;
			HX_STACK_LINE(71)
			this->_speed = (Float(this->distance) / Float(DurationOrSpeed));
		}
		else{
			HX_STACK_LINE(75)
			this->duration = (Float(this->distance) / Float(DurationOrSpeed));
			HX_STACK_LINE(76)
			this->_speed = DurationOrSpeed;
		}
		HX_STACK_LINE(79)
		this->ease = Ease;
		HX_STACK_LINE(80)
		hx::TCast< ::flixel::tweens::motion::LinearPath >::cast(this->start());
		HX_STACK_LINE(81)
		return hx::ObjectPtr<OBJ_>(this);
	}
}


HX_DEFINE_DYNAMIC_FUNC3(LinearPath_obj,setMotion,return )

::flixel::tweens::motion::LinearPath LinearPath_obj::addPoint( hx::Null< Float >  __o_x,hx::Null< Float >  __o_y){
Float x = __o_x.Default(0);
Float y = __o_y.Default(0);
	HX_STACK_FRAME("flixel.tweens.motion.LinearPath","addPoint",0x4da05b4f,"flixel.tweens.motion.LinearPath.addPoint","flixel/tweens/motion/LinearPath.hx",85,0x519b896f)
	HX_STACK_THIS(this)
	HX_STACK_ARG(x,"x")
	HX_STACK_ARG(y,"y")
{
		HX_STACK_LINE(86)
		if (((this->_last != null()))){
			HX_STACK_LINE(88)
			hx::AddEq(this->distance,::Math_obj::sqrt(((((x - this->_last->x)) * ((x - this->_last->x))) + (((y - this->_last->y)) * ((y - this->_last->y))))));
			HX_STACK_LINE(89)
			this->_pointD[this->points->length] = this->distance;
		}
		HX_STACK_LINE(91)
		this->points[this->points->length] = this->_last = ::flixel::util::FlxPoint_obj::__new(x,y);
		HX_STACK_LINE(92)
		return hx::ObjectPtr<OBJ_>(this);
	}
}


HX_DEFINE_DYNAMIC_FUNC2(LinearPath_obj,addPoint,return )

::flixel::util::FlxPoint LinearPath_obj::getPoint( hx::Null< int >  __o_index){
int index = __o_index.Default(0);
	HX_STACK_FRAME("flixel.tweens.motion.LinearPath","getPoint",0x341a44ba,"flixel.tweens.motion.LinearPath.getPoint","flixel/tweens/motion/LinearPath.hx",96,0x519b896f)
	HX_STACK_THIS(this)
	HX_STACK_ARG(index,"index")
{
		HX_STACK_LINE(97)
		if (((this->points->length == (int)0))){
			HX_STACK_LINE(99)
			HX_STACK_DO_THROW(HX_CSTRING("No points have been added to the path yet."));
		}
		HX_STACK_LINE(101)
		return this->points->__get(hx::Mod(index,this->points->length)).StaticCast< ::flixel::util::FlxPoint >();
	}
}


HX_DEFINE_DYNAMIC_FUNC1(LinearPath_obj,getPoint,return )

::flixel::tweens::FlxTween LinearPath_obj::start( ){
	HX_STACK_FRAME("flixel.tweens.motion.LinearPath","start",0xb880a782,"flixel.tweens.motion.LinearPath.start","flixel/tweens/motion/LinearPath.hx",105,0x519b896f)
	HX_STACK_THIS(this)
	HX_STACK_LINE(106)
	if ((this->backward)){
		HX_STACK_LINE(106)
		this->_index = (this->points->length - (int)1);
	}
	else{
		HX_STACK_LINE(106)
		this->_index = (int)0;
	}
	HX_STACK_LINE(107)
	this->super::start();
	HX_STACK_LINE(108)
	return hx::ObjectPtr<OBJ_>(this);
}


Void LinearPath_obj::update( ){
{
		HX_STACK_FRAME("flixel.tweens.motion.LinearPath","update",0x391d0ee9,"flixel.tweens.motion.LinearPath.update","flixel/tweens/motion/LinearPath.hx",112,0x519b896f)
		HX_STACK_THIS(this)
		HX_STACK_LINE(113)
		this->super::update();
		HX_STACK_LINE(114)
		Float td;		HX_STACK_VAR(td,"td");
		HX_STACK_LINE(115)
		Float tt;		HX_STACK_VAR(tt,"tt");
		HX_STACK_LINE(117)
		if (((this->points == null()))){
			HX_STACK_LINE(118)
			return null();
		}
		HX_STACK_LINE(120)
		if ((!(this->backward))){
			HX_STACK_LINE(122)
			if (((this->_index < (this->points->length - (int)1)))){
				HX_STACK_LINE(124)
				while(((this->scale > this->_pointT->__get((this->_index + (int)1))))){
					HX_STACK_LINE(126)
					(this->_index)++;
					HX_STACK_LINE(127)
					if (((this->_index == (this->points->length - (int)1)))){
						HX_STACK_LINE(129)
						hx::SubEq(this->_index,(int)1);
						HX_STACK_LINE(130)
						break;
					}
				}
			}
			HX_STACK_LINE(135)
			td = this->_pointT->__get(this->_index);
			HX_STACK_LINE(136)
			tt = (this->_pointT->__get((this->_index + (int)1)) - td);
			HX_STACK_LINE(137)
			td = (Float(((this->scale - td))) / Float(tt));
			HX_STACK_LINE(138)
			this->_prevPoint = this->points->__get(this->_index).StaticCast< ::flixel::util::FlxPoint >();
			HX_STACK_LINE(139)
			this->_nextPoint = this->points->__get((this->_index + (int)1)).StaticCast< ::flixel::util::FlxPoint >();
			HX_STACK_LINE(140)
			this->x = (this->_prevPoint->x + (((this->_nextPoint->x - this->_prevPoint->x)) * td));
			HX_STACK_LINE(141)
			this->y = (this->_prevPoint->y + (((this->_nextPoint->y - this->_prevPoint->y)) * td));
		}
		else{
			HX_STACK_LINE(145)
			if (((this->_index > (int)0))){
				HX_STACK_LINE(147)
				while(((this->scale < this->_pointT->__get((this->_index - (int)1))))){
					HX_STACK_LINE(149)
					hx::SubEq(this->_index,(int)1);
					HX_STACK_LINE(150)
					if (((this->_index == (int)0))){
						HX_STACK_LINE(152)
						hx::AddEq(this->_index,(int)1);
						HX_STACK_LINE(153)
						break;
					}
				}
			}
			HX_STACK_LINE(158)
			td = this->_pointT->__get(this->_index);
			HX_STACK_LINE(159)
			tt = (this->_pointT->__get((this->_index - (int)1)) - td);
			HX_STACK_LINE(160)
			td = (Float(((this->scale - td))) / Float(tt));
			HX_STACK_LINE(161)
			this->_prevPoint = this->points->__get(this->_index).StaticCast< ::flixel::util::FlxPoint >();
			HX_STACK_LINE(162)
			this->_nextPoint = this->points->__get((this->_index - (int)1)).StaticCast< ::flixel::util::FlxPoint >();
			HX_STACK_LINE(163)
			this->x = (this->_prevPoint->x + (((this->_nextPoint->x - this->_prevPoint->x)) * td));
			HX_STACK_LINE(164)
			this->y = (this->_prevPoint->y + (((this->_nextPoint->y - this->_prevPoint->y)) * td));
		}
		HX_STACK_LINE(167)
		this->super::postUpdate();
	}
return null();
}


Void LinearPath_obj::updatePath( ){
{
		HX_STACK_FRAME("flixel.tweens.motion.LinearPath","updatePath",0x8544492e,"flixel.tweens.motion.LinearPath.updatePath","flixel/tweens/motion/LinearPath.hx",174,0x519b896f)
		HX_STACK_THIS(this)
		HX_STACK_LINE(175)
		if (((this->points->length < (int)2))){
			HX_STACK_LINE(175)
			HX_STACK_DO_THROW(HX_CSTRING("A LinearPath must have at least 2 points to operate."));
		}
		HX_STACK_LINE(176)
		if (((this->_pointD->length == this->_pointT->length))){
			HX_STACK_LINE(176)
			return null();
		}
		HX_STACK_LINE(178)
		int i = (int)0;		HX_STACK_VAR(i,"i");
		HX_STACK_LINE(179)
		while(((i < this->points->length))){
			HX_STACK_LINE(181)
			this->_pointT[i] = (Float(this->_pointD->__get((i)++)) / Float(this->distance));
		}
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC0(LinearPath_obj,updatePath,(void))


LinearPath_obj::LinearPath_obj()
{
}

void LinearPath_obj::__Mark(HX_MARK_PARAMS)
{
	HX_MARK_BEGIN_CLASS(LinearPath);
	HX_MARK_MEMBER_NAME(distance,"distance");
	HX_MARK_MEMBER_NAME(points,"points");
	HX_MARK_MEMBER_NAME(_pointD,"_pointD");
	HX_MARK_MEMBER_NAME(_pointT,"_pointT");
	HX_MARK_MEMBER_NAME(_speed,"_speed");
	HX_MARK_MEMBER_NAME(_index,"_index");
	HX_MARK_MEMBER_NAME(_last,"_last");
	HX_MARK_MEMBER_NAME(_prevPoint,"_prevPoint");
	HX_MARK_MEMBER_NAME(_nextPoint,"_nextPoint");
	::flixel::tweens::motion::Motion_obj::__Mark(HX_MARK_ARG);
	HX_MARK_END_CLASS();
}

void LinearPath_obj::__Visit(HX_VISIT_PARAMS)
{
	HX_VISIT_MEMBER_NAME(distance,"distance");
	HX_VISIT_MEMBER_NAME(points,"points");
	HX_VISIT_MEMBER_NAME(_pointD,"_pointD");
	HX_VISIT_MEMBER_NAME(_pointT,"_pointT");
	HX_VISIT_MEMBER_NAME(_speed,"_speed");
	HX_VISIT_MEMBER_NAME(_index,"_index");
	HX_VISIT_MEMBER_NAME(_last,"_last");
	HX_VISIT_MEMBER_NAME(_prevPoint,"_prevPoint");
	HX_VISIT_MEMBER_NAME(_nextPoint,"_nextPoint");
	::flixel::tweens::motion::Motion_obj::__Visit(HX_VISIT_ARG);
}

Dynamic LinearPath_obj::__Field(const ::String &inName,bool inCallProp)
{
	switch(inName.length) {
	case 5:
		if (HX_FIELD_EQ(inName,"_last") ) { return _last; }
		if (HX_FIELD_EQ(inName,"start") ) { return start_dyn(); }
		break;
	case 6:
		if (HX_FIELD_EQ(inName,"points") ) { return points; }
		if (HX_FIELD_EQ(inName,"_speed") ) { return _speed; }
		if (HX_FIELD_EQ(inName,"_index") ) { return _index; }
		if (HX_FIELD_EQ(inName,"update") ) { return update_dyn(); }
		break;
	case 7:
		if (HX_FIELD_EQ(inName,"_pointD") ) { return _pointD; }
		if (HX_FIELD_EQ(inName,"_pointT") ) { return _pointT; }
		if (HX_FIELD_EQ(inName,"destroy") ) { return destroy_dyn(); }
		break;
	case 8:
		if (HX_FIELD_EQ(inName,"distance") ) { return distance; }
		if (HX_FIELD_EQ(inName,"addPoint") ) { return addPoint_dyn(); }
		if (HX_FIELD_EQ(inName,"getPoint") ) { return getPoint_dyn(); }
		break;
	case 9:
		if (HX_FIELD_EQ(inName,"setMotion") ) { return setMotion_dyn(); }
		break;
	case 10:
		if (HX_FIELD_EQ(inName,"_prevPoint") ) { return _prevPoint; }
		if (HX_FIELD_EQ(inName,"_nextPoint") ) { return _nextPoint; }
		if (HX_FIELD_EQ(inName,"updatePath") ) { return updatePath_dyn(); }
	}
	return super::__Field(inName,inCallProp);
}

Dynamic LinearPath_obj::__SetField(const ::String &inName,const Dynamic &inValue,bool inCallProp)
{
	switch(inName.length) {
	case 5:
		if (HX_FIELD_EQ(inName,"_last") ) { _last=inValue.Cast< ::flixel::util::FlxPoint >(); return inValue; }
		break;
	case 6:
		if (HX_FIELD_EQ(inName,"points") ) { points=inValue.Cast< Array< ::Dynamic > >(); return inValue; }
		if (HX_FIELD_EQ(inName,"_speed") ) { _speed=inValue.Cast< Float >(); return inValue; }
		if (HX_FIELD_EQ(inName,"_index") ) { _index=inValue.Cast< int >(); return inValue; }
		break;
	case 7:
		if (HX_FIELD_EQ(inName,"_pointD") ) { _pointD=inValue.Cast< Array< Float > >(); return inValue; }
		if (HX_FIELD_EQ(inName,"_pointT") ) { _pointT=inValue.Cast< Array< Float > >(); return inValue; }
		break;
	case 8:
		if (HX_FIELD_EQ(inName,"distance") ) { distance=inValue.Cast< Float >(); return inValue; }
		break;
	case 10:
		if (HX_FIELD_EQ(inName,"_prevPoint") ) { _prevPoint=inValue.Cast< ::flixel::util::FlxPoint >(); return inValue; }
		if (HX_FIELD_EQ(inName,"_nextPoint") ) { _nextPoint=inValue.Cast< ::flixel::util::FlxPoint >(); return inValue; }
	}
	return super::__SetField(inName,inValue,inCallProp);
}

void LinearPath_obj::__GetFields(Array< ::String> &outFields)
{
	outFields->push(HX_CSTRING("distance"));
	outFields->push(HX_CSTRING("points"));
	outFields->push(HX_CSTRING("_pointD"));
	outFields->push(HX_CSTRING("_pointT"));
	outFields->push(HX_CSTRING("_speed"));
	outFields->push(HX_CSTRING("_index"));
	outFields->push(HX_CSTRING("_last"));
	outFields->push(HX_CSTRING("_prevPoint"));
	outFields->push(HX_CSTRING("_nextPoint"));
	super::__GetFields(outFields);
};

static ::String sStaticFields[] = {
	String(null()) };

#if HXCPP_SCRIPTABLE
static hx::StorageInfo sMemberStorageInfo[] = {
	{hx::fsFloat,(int)offsetof(LinearPath_obj,distance),HX_CSTRING("distance")},
	{hx::fsObject /*Array< ::Dynamic >*/ ,(int)offsetof(LinearPath_obj,points),HX_CSTRING("points")},
	{hx::fsObject /*Array< Float >*/ ,(int)offsetof(LinearPath_obj,_pointD),HX_CSTRING("_pointD")},
	{hx::fsObject /*Array< Float >*/ ,(int)offsetof(LinearPath_obj,_pointT),HX_CSTRING("_pointT")},
	{hx::fsFloat,(int)offsetof(LinearPath_obj,_speed),HX_CSTRING("_speed")},
	{hx::fsInt,(int)offsetof(LinearPath_obj,_index),HX_CSTRING("_index")},
	{hx::fsObject /*::flixel::util::FlxPoint*/ ,(int)offsetof(LinearPath_obj,_last),HX_CSTRING("_last")},
	{hx::fsObject /*::flixel::util::FlxPoint*/ ,(int)offsetof(LinearPath_obj,_prevPoint),HX_CSTRING("_prevPoint")},
	{hx::fsObject /*::flixel::util::FlxPoint*/ ,(int)offsetof(LinearPath_obj,_nextPoint),HX_CSTRING("_nextPoint")},
	{ hx::fsUnknown, 0, null()}
};
#endif

static ::String sMemberFields[] = {
	HX_CSTRING("distance"),
	HX_CSTRING("points"),
	HX_CSTRING("_pointD"),
	HX_CSTRING("_pointT"),
	HX_CSTRING("_speed"),
	HX_CSTRING("_index"),
	HX_CSTRING("_last"),
	HX_CSTRING("_prevPoint"),
	HX_CSTRING("_nextPoint"),
	HX_CSTRING("destroy"),
	HX_CSTRING("setMotion"),
	HX_CSTRING("addPoint"),
	HX_CSTRING("getPoint"),
	HX_CSTRING("start"),
	HX_CSTRING("update"),
	HX_CSTRING("updatePath"),
	String(null()) };

static void sMarkStatics(HX_MARK_PARAMS) {
	HX_MARK_MEMBER_NAME(LinearPath_obj::__mClass,"__mClass");
};

#ifdef HXCPP_VISIT_ALLOCS
static void sVisitStatics(HX_VISIT_PARAMS) {
	HX_VISIT_MEMBER_NAME(LinearPath_obj::__mClass,"__mClass");
};

#endif

Class LinearPath_obj::__mClass;

void LinearPath_obj::__register()
{
	hx::Static(__mClass) = hx::RegisterClass(HX_CSTRING("flixel.tweens.motion.LinearPath"), hx::TCanCast< LinearPath_obj> ,sStaticFields,sMemberFields,
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

void LinearPath_obj::__boot()
{
}

} // end namespace flixel
} // end namespace tweens
} // end namespace motion
