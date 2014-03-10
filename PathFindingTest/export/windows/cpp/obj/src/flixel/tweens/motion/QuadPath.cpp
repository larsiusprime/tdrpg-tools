#include <hxcpp.h>

#ifndef INCLUDED_Std
#include <Std.h>
#endif
#ifndef INCLUDED_flixel_interfaces_IFlxDestroyable
#include <flixel/interfaces/IFlxDestroyable.h>
#endif
#ifndef INCLUDED_flixel_tweens_FlxTween
#include <flixel/tweens/FlxTween.h>
#endif
#ifndef INCLUDED_flixel_tweens_motion_Motion
#include <flixel/tweens/motion/Motion.h>
#endif
#ifndef INCLUDED_flixel_tweens_motion_QuadPath
#include <flixel/tweens/motion/QuadPath.h>
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

Void QuadPath_obj::__construct(Dynamic complete,hx::Null< int >  __o_type)
{
HX_STACK_FRAME("flixel.tweens.motion.QuadPath","new",0x9e663362,"flixel.tweens.motion.QuadPath.new","flixel/tweens/motion/QuadPath.hx",39,0x562bb60d)

HX_STACK_ARG(complete,"complete")

HX_STACK_ARG(__o_type,"type")
int type = __o_type.Default(0);
{
	HX_STACK_LINE(40)
	super::__construct((int)0,complete,type,null());
	HX_STACK_LINE(41)
	this->_points = Array_obj< ::Dynamic >::__new();
	HX_STACK_LINE(42)
	this->_curveD = Array_obj< Float >::__new();
	HX_STACK_LINE(43)
	this->_curveT = Array_obj< Float >::__new();
	HX_STACK_LINE(44)
	this->_distance = this->_speed = this->_index = this->_numSegs = (int)0;
	HX_STACK_LINE(45)
	this->_updateCurve = true;
}
;
	return null();
}

//QuadPath_obj::~QuadPath_obj() { }

Dynamic QuadPath_obj::__CreateEmpty() { return  new QuadPath_obj; }
hx::ObjectPtr< QuadPath_obj > QuadPath_obj::__new(Dynamic complete,hx::Null< int >  __o_type)
{  hx::ObjectPtr< QuadPath_obj > result = new QuadPath_obj();
	result->__construct(complete,__o_type);
	return result;}

Dynamic QuadPath_obj::__Create(hx::DynamicArray inArgs)
{  hx::ObjectPtr< QuadPath_obj > result = new QuadPath_obj();
	result->__construct(inArgs[0],inArgs[1]);
	return result;}

Void QuadPath_obj::destroy( ){
{
		HX_STACK_FRAME("flixel.tweens.motion.QuadPath","destroy",0x05d338fc,"flixel.tweens.motion.QuadPath.destroy","flixel/tweens/motion/QuadPath.hx",49,0x562bb60d)
		HX_STACK_THIS(this)
		HX_STACK_LINE(50)
		this->super::destroy();
		HX_STACK_LINE(51)
		this->_points = null();
		HX_STACK_LINE(52)
		this->_curveD = null();
		HX_STACK_LINE(53)
		this->_curveT = null();
		HX_STACK_LINE(54)
		this->_a = null();
		HX_STACK_LINE(55)
		this->_b = null();
		HX_STACK_LINE(56)
		this->_c = null();
	}
return null();
}


::flixel::tweens::motion::QuadPath QuadPath_obj::setMotion( Float DurationOrSpeed,hx::Null< bool >  __o_UseDuration,Dynamic Ease){
bool UseDuration = __o_UseDuration.Default(true);
	HX_STACK_FRAME("flixel.tweens.motion.QuadPath","setMotion",0xc2ae8bfa,"flixel.tweens.motion.QuadPath.setMotion","flixel/tweens/motion/QuadPath.hx",67,0x562bb60d)
	HX_STACK_THIS(this)
	HX_STACK_ARG(DurationOrSpeed,"DurationOrSpeed")
	HX_STACK_ARG(UseDuration,"UseDuration")
	HX_STACK_ARG(Ease,"Ease")
{
		HX_STACK_LINE(68)
		this->updatePath();
		HX_STACK_LINE(70)
		if ((UseDuration)){
			HX_STACK_LINE(72)
			this->duration = DurationOrSpeed;
			HX_STACK_LINE(73)
			this->_speed = (Float(this->_distance) / Float(DurationOrSpeed));
		}
		else{
			HX_STACK_LINE(77)
			this->duration = (Float(this->_distance) / Float(DurationOrSpeed));
			HX_STACK_LINE(78)
			this->_speed = DurationOrSpeed;
		}
		HX_STACK_LINE(81)
		this->ease = Ease;
		HX_STACK_LINE(82)
		hx::TCast< ::flixel::tweens::motion::QuadPath >::cast(this->start());
		HX_STACK_LINE(83)
		return hx::ObjectPtr<OBJ_>(this);
	}
}


HX_DEFINE_DYNAMIC_FUNC3(QuadPath_obj,setMotion,return )

::flixel::tweens::motion::QuadPath QuadPath_obj::addPoint( hx::Null< Float >  __o_x,hx::Null< Float >  __o_y){
Float x = __o_x.Default(0);
Float y = __o_y.Default(0);
	HX_STACK_FRAME("flixel.tweens.motion.QuadPath","addPoint",0x820a502d,"flixel.tweens.motion.QuadPath.addPoint","flixel/tweens/motion/QuadPath.hx",90,0x562bb60d)
	HX_STACK_THIS(this)
	HX_STACK_ARG(x,"x")
	HX_STACK_ARG(y,"y")
{
		HX_STACK_LINE(91)
		this->_updateCurve = true;
		HX_STACK_LINE(92)
		this->_points[this->_points->length] = ::flixel::util::FlxPoint_obj::__new(x,y);
		HX_STACK_LINE(93)
		return hx::ObjectPtr<OBJ_>(this);
	}
}


HX_DEFINE_DYNAMIC_FUNC2(QuadPath_obj,addPoint,return )

::flixel::util::FlxPoint QuadPath_obj::getPoint( hx::Null< int >  __o_index){
int index = __o_index.Default(0);
	HX_STACK_FRAME("flixel.tweens.motion.QuadPath","getPoint",0x68843998,"flixel.tweens.motion.QuadPath.getPoint","flixel/tweens/motion/QuadPath.hx",100,0x562bb60d)
	HX_STACK_THIS(this)
	HX_STACK_ARG(index,"index")
{
		HX_STACK_LINE(101)
		if (((this->_points->length == (int)0))){
			HX_STACK_LINE(103)
			HX_STACK_DO_THROW(HX_CSTRING("No points have been added to the path yet."));
		}
		HX_STACK_LINE(105)
		return this->_points->__get(hx::Mod(index,this->_points->length)).StaticCast< ::flixel::util::FlxPoint >();
	}
}


HX_DEFINE_DYNAMIC_FUNC1(QuadPath_obj,getPoint,return )

::flixel::tweens::FlxTween QuadPath_obj::start( ){
	HX_STACK_FRAME("flixel.tweens.motion.QuadPath","start",0x95be1be4,"flixel.tweens.motion.QuadPath.start","flixel/tweens/motion/QuadPath.hx",109,0x562bb60d)
	HX_STACK_THIS(this)
	HX_STACK_LINE(110)
	if ((this->backward)){
		HX_STACK_LINE(110)
		this->_index = (this->_numSegs - (int)1);
	}
	else{
		HX_STACK_LINE(110)
		this->_index = (int)0;
	}
	HX_STACK_LINE(111)
	this->super::start();
	HX_STACK_LINE(112)
	return hx::ObjectPtr<OBJ_>(this);
}


Void QuadPath_obj::update( ){
{
		HX_STACK_FRAME("flixel.tweens.motion.QuadPath","update",0xf1a57047,"flixel.tweens.motion.QuadPath.update","flixel/tweens/motion/QuadPath.hx",116,0x562bb60d)
		HX_STACK_THIS(this)
		HX_STACK_LINE(117)
		this->super::update();
		HX_STACK_LINE(118)
		Float td;		HX_STACK_VAR(td,"td");
		HX_STACK_LINE(119)
		Float tt;		HX_STACK_VAR(tt,"tt");
		HX_STACK_LINE(121)
		if (((bool(!(this->backward)) && bool((this->_points != null()))))){
			HX_STACK_LINE(123)
			if (((this->_index < (this->_numSegs - (int)1)))){
				HX_STACK_LINE(125)
				while(((this->scale > this->_curveT->__get((this->_index + (int)1))))){
					HX_STACK_LINE(127)
					(this->_index)++;
					HX_STACK_LINE(128)
					if (((this->_index == (this->_numSegs - (int)1)))){
						HX_STACK_LINE(130)
						break;
					}
				}
			}
			HX_STACK_LINE(134)
			td = this->_curveT->__get(this->_index);
			HX_STACK_LINE(135)
			tt = (this->_curveT->__get((this->_index + (int)1)) - td);
			HX_STACK_LINE(136)
			td = (Float(((this->scale - td))) / Float(tt));
			HX_STACK_LINE(137)
			this->_a = this->_points->__get((this->_index * (int)2)).StaticCast< ::flixel::util::FlxPoint >();
			HX_STACK_LINE(138)
			this->_b = this->_points->__get(((this->_index * (int)2) + (int)1)).StaticCast< ::flixel::util::FlxPoint >();
			HX_STACK_LINE(139)
			this->_c = this->_points->__get(((this->_index * (int)2) + (int)2)).StaticCast< ::flixel::util::FlxPoint >();
			HX_STACK_LINE(141)
			this->x = ((((this->_a->x * (((int)1 - td))) * (((int)1 - td))) + (((this->_b->x * (int)2) * (((int)1 - td))) * td)) + ((this->_c->x * td) * td));
			HX_STACK_LINE(142)
			this->y = ((((this->_a->y * (((int)1 - td))) * (((int)1 - td))) + (((this->_b->y * (int)2) * (((int)1 - td))) * td)) + ((this->_c->y * td) * td));
		}
		else{
			HX_STACK_LINE(144)
			if (((this->_points != null()))){
				HX_STACK_LINE(146)
				if (((this->_index > (int)0))){
					HX_STACK_LINE(148)
					while(((this->scale < this->_curveT->__get(this->_index)))){
						HX_STACK_LINE(150)
						(this->_index)--;
						HX_STACK_LINE(151)
						if (((this->_index == (int)0))){
							HX_STACK_LINE(153)
							break;
						}
					}
				}
				HX_STACK_LINE(158)
				td = this->_curveT->__get((this->_index + (int)1));
				HX_STACK_LINE(159)
				tt = (this->_curveT->__get(this->_index) - td);
				HX_STACK_LINE(160)
				td = (Float(((this->scale - td))) / Float(tt));
				HX_STACK_LINE(161)
				this->_a = this->_points->__get(((this->_index * (int)2) + (int)2)).StaticCast< ::flixel::util::FlxPoint >();
				HX_STACK_LINE(162)
				this->_b = this->_points->__get(((this->_index * (int)2) + (int)1)).StaticCast< ::flixel::util::FlxPoint >();
				HX_STACK_LINE(163)
				this->_c = this->_points->__get((this->_index * (int)2)).StaticCast< ::flixel::util::FlxPoint >();
				HX_STACK_LINE(165)
				this->x = ((((this->_a->x * (((int)1 - td))) * (((int)1 - td))) + (((this->_b->x * (int)2) * (((int)1 - td))) * td)) + ((this->_c->x * td) * td));
				HX_STACK_LINE(166)
				this->y = ((((this->_a->y * (((int)1 - td))) * (((int)1 - td))) + (((this->_b->y * (int)2) * (((int)1 - td))) * td)) + ((this->_c->y * td) * td));
			}
		}
		HX_STACK_LINE(168)
		this->super::postUpdate();
	}
return null();
}


Void QuadPath_obj::updatePath( ){
{
		HX_STACK_FRAME("flixel.tweens.motion.QuadPath","updatePath",0x1fbbb18c,"flixel.tweens.motion.QuadPath.updatePath","flixel/tweens/motion/QuadPath.hx",173,0x562bb60d)
		HX_STACK_THIS(this)
		HX_STACK_LINE(174)
		if (((bool((hx::Mod(((this->_points->length - (int)1)),(int)2) != (int)0)) || bool((this->_points->length < (int)3))))){
			HX_STACK_LINE(176)
			HX_STACK_DO_THROW(HX_CSTRING("A QuadPath must have at least 3 points to operate and number of points must be a odd."));
		}
		HX_STACK_LINE(178)
		if ((!(this->_updateCurve))){
			HX_STACK_LINE(180)
			return null();
		}
		HX_STACK_LINE(182)
		this->_updateCurve = false;
		HX_STACK_LINE(185)
		int i = (int)0;		HX_STACK_VAR(i,"i");
		HX_STACK_LINE(186)
		int j = (int)0;		HX_STACK_VAR(j,"j");
		HX_STACK_LINE(187)
		this->_distance = (int)0;
		HX_STACK_LINE(188)
		this->_numSegs = ::Std_obj::_int((Float(((this->_points->length - (int)1))) / Float((int)2)));
		HX_STACK_LINE(189)
		while(((i < this->_numSegs))){
			HX_STACK_LINE(191)
			j = (i * (int)2);
			HX_STACK_LINE(192)
			this->_curveD[i] = this->getCurveLength(this->_points->__get(j).StaticCast< ::flixel::util::FlxPoint >(),this->_points->__get((j + (int)1)).StaticCast< ::flixel::util::FlxPoint >(),this->_points->__get((j + (int)2)).StaticCast< ::flixel::util::FlxPoint >());
			HX_STACK_LINE(193)
			hx::AddEq(this->_distance,this->_curveD->__get((i)++));
		}
		HX_STACK_LINE(197)
		i = (int)0;
		HX_STACK_LINE(198)
		Float d = (int)0;		HX_STACK_VAR(d,"d");
		HX_STACK_LINE(199)
		while(((i < this->_numSegs))){
			HX_STACK_LINE(201)
			hx::AddEq(d,this->_curveD->__get(i));
			HX_STACK_LINE(202)
			this->_curveT[(i)++] = (Float(d) / Float(this->_distance));
		}
		HX_STACK_LINE(204)
		this->_curveT[(this->_numSegs - (int)1)] = (int)1;
		HX_STACK_LINE(205)
		this->_curveT->unshift((int)0);
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC0(QuadPath_obj,updatePath,(void))

Float QuadPath_obj::getCurveLength( ::flixel::util::FlxPoint start,::flixel::util::FlxPoint control,::flixel::util::FlxPoint finish){
	HX_STACK_FRAME("flixel.tweens.motion.QuadPath","getCurveLength",0x2a112e3d,"flixel.tweens.motion.QuadPath.getCurveLength","flixel/tweens/motion/QuadPath.hx",209,0x562bb60d)
	HX_STACK_THIS(this)
	HX_STACK_ARG(start,"start")
	HX_STACK_ARG(control,"control")
	HX_STACK_ARG(finish,"finish")
	HX_STACK_LINE(210)
	::flixel::util::FlxPoint a = ::flixel::tweens::motion::QuadPath_obj::_Point;		HX_STACK_VAR(a,"a");
	HX_STACK_LINE(211)
	::flixel::util::FlxPoint b = ::flixel::tweens::motion::QuadPath_obj::_Point2;		HX_STACK_VAR(b,"b");
	HX_STACK_LINE(212)
	a->set_x(((start->x - ((int)2 * control->x)) + finish->x));
	HX_STACK_LINE(213)
	a->set_y(((start->y - ((int)2 * control->y)) + finish->y));
	HX_STACK_LINE(214)
	b->set_x((((int)2 * control->x) - ((int)2 * start->x)));
	HX_STACK_LINE(215)
	b->set_y((((int)2 * control->y) - ((int)2 * start->y)));
	HX_STACK_LINE(216)
	Float A = ((int)4 * (((a->x * a->x) + (a->y * a->y))));		HX_STACK_VAR(A,"A");
	HX_STACK_LINE(217)
	Float B = ((int)4 * (((a->x * b->x) + (a->y * b->y))));		HX_STACK_VAR(B,"B");
	HX_STACK_LINE(218)
	Float C = ((b->x * b->x) + (b->y * b->y));		HX_STACK_VAR(C,"C");
	HX_STACK_LINE(219)
	Float ABC = ((int)2 * ::Math_obj::sqrt(((A + B) + C)));		HX_STACK_VAR(ABC,"ABC");
	HX_STACK_LINE(220)
	Float A2 = ::Math_obj::sqrt(A);		HX_STACK_VAR(A2,"A2");
	HX_STACK_LINE(221)
	Float A32 = (((int)2 * A) * A2);		HX_STACK_VAR(A32,"A32");
	HX_STACK_LINE(222)
	Float C2 = ((int)2 * ::Math_obj::sqrt(C));		HX_STACK_VAR(C2,"C2");
	HX_STACK_LINE(223)
	Float BA = (Float(B) / Float(A2));		HX_STACK_VAR(BA,"BA");
	HX_STACK_LINE(224)
	return (Float(((((A32 * ABC) + ((A2 * B) * ((ABC - C2)))) + ((((((int)4 * C) * A) - (B * B))) * ::Math_obj::log((Float((((((int)2 * A2) + BA) + ABC))) / Float(((BA + C2))))))))) / Float((((int)4 * A32))));
}


HX_DEFINE_DYNAMIC_FUNC3(QuadPath_obj,getCurveLength,return )

::flixel::util::FlxPoint QuadPath_obj::_Point;

::flixel::util::FlxPoint QuadPath_obj::_Point2;


QuadPath_obj::QuadPath_obj()
{
}

void QuadPath_obj::__Mark(HX_MARK_PARAMS)
{
	HX_MARK_BEGIN_CLASS(QuadPath);
	HX_MARK_MEMBER_NAME(_points,"_points");
	HX_MARK_MEMBER_NAME(_distance,"_distance");
	HX_MARK_MEMBER_NAME(_speed,"_speed");
	HX_MARK_MEMBER_NAME(_index,"_index");
	HX_MARK_MEMBER_NAME(_numSegs,"_numSegs");
	HX_MARK_MEMBER_NAME(_updateCurve,"_updateCurve");
	HX_MARK_MEMBER_NAME(_curveT,"_curveT");
	HX_MARK_MEMBER_NAME(_curveD,"_curveD");
	HX_MARK_MEMBER_NAME(_a,"_a");
	HX_MARK_MEMBER_NAME(_b,"_b");
	HX_MARK_MEMBER_NAME(_c,"_c");
	::flixel::tweens::motion::Motion_obj::__Mark(HX_MARK_ARG);
	HX_MARK_END_CLASS();
}

void QuadPath_obj::__Visit(HX_VISIT_PARAMS)
{
	HX_VISIT_MEMBER_NAME(_points,"_points");
	HX_VISIT_MEMBER_NAME(_distance,"_distance");
	HX_VISIT_MEMBER_NAME(_speed,"_speed");
	HX_VISIT_MEMBER_NAME(_index,"_index");
	HX_VISIT_MEMBER_NAME(_numSegs,"_numSegs");
	HX_VISIT_MEMBER_NAME(_updateCurve,"_updateCurve");
	HX_VISIT_MEMBER_NAME(_curveT,"_curveT");
	HX_VISIT_MEMBER_NAME(_curveD,"_curveD");
	HX_VISIT_MEMBER_NAME(_a,"_a");
	HX_VISIT_MEMBER_NAME(_b,"_b");
	HX_VISIT_MEMBER_NAME(_c,"_c");
	::flixel::tweens::motion::Motion_obj::__Visit(HX_VISIT_ARG);
}

Dynamic QuadPath_obj::__Field(const ::String &inName,bool inCallProp)
{
	switch(inName.length) {
	case 2:
		if (HX_FIELD_EQ(inName,"_a") ) { return _a; }
		if (HX_FIELD_EQ(inName,"_b") ) { return _b; }
		if (HX_FIELD_EQ(inName,"_c") ) { return _c; }
		break;
	case 5:
		if (HX_FIELD_EQ(inName,"start") ) { return start_dyn(); }
		break;
	case 6:
		if (HX_FIELD_EQ(inName,"_Point") ) { return _Point; }
		if (HX_FIELD_EQ(inName,"_speed") ) { return _speed; }
		if (HX_FIELD_EQ(inName,"_index") ) { return _index; }
		if (HX_FIELD_EQ(inName,"update") ) { return update_dyn(); }
		break;
	case 7:
		if (HX_FIELD_EQ(inName,"_Point2") ) { return _Point2; }
		if (HX_FIELD_EQ(inName,"_points") ) { return _points; }
		if (HX_FIELD_EQ(inName,"_curveT") ) { return _curveT; }
		if (HX_FIELD_EQ(inName,"_curveD") ) { return _curveD; }
		if (HX_FIELD_EQ(inName,"destroy") ) { return destroy_dyn(); }
		break;
	case 8:
		if (HX_FIELD_EQ(inName,"_numSegs") ) { return _numSegs; }
		if (HX_FIELD_EQ(inName,"addPoint") ) { return addPoint_dyn(); }
		if (HX_FIELD_EQ(inName,"getPoint") ) { return getPoint_dyn(); }
		break;
	case 9:
		if (HX_FIELD_EQ(inName,"_distance") ) { return _distance; }
		if (HX_FIELD_EQ(inName,"setMotion") ) { return setMotion_dyn(); }
		break;
	case 10:
		if (HX_FIELD_EQ(inName,"updatePath") ) { return updatePath_dyn(); }
		break;
	case 12:
		if (HX_FIELD_EQ(inName,"_updateCurve") ) { return _updateCurve; }
		break;
	case 14:
		if (HX_FIELD_EQ(inName,"getCurveLength") ) { return getCurveLength_dyn(); }
	}
	return super::__Field(inName,inCallProp);
}

Dynamic QuadPath_obj::__SetField(const ::String &inName,const Dynamic &inValue,bool inCallProp)
{
	switch(inName.length) {
	case 2:
		if (HX_FIELD_EQ(inName,"_a") ) { _a=inValue.Cast< ::flixel::util::FlxPoint >(); return inValue; }
		if (HX_FIELD_EQ(inName,"_b") ) { _b=inValue.Cast< ::flixel::util::FlxPoint >(); return inValue; }
		if (HX_FIELD_EQ(inName,"_c") ) { _c=inValue.Cast< ::flixel::util::FlxPoint >(); return inValue; }
		break;
	case 6:
		if (HX_FIELD_EQ(inName,"_Point") ) { _Point=inValue.Cast< ::flixel::util::FlxPoint >(); return inValue; }
		if (HX_FIELD_EQ(inName,"_speed") ) { _speed=inValue.Cast< Float >(); return inValue; }
		if (HX_FIELD_EQ(inName,"_index") ) { _index=inValue.Cast< int >(); return inValue; }
		break;
	case 7:
		if (HX_FIELD_EQ(inName,"_Point2") ) { _Point2=inValue.Cast< ::flixel::util::FlxPoint >(); return inValue; }
		if (HX_FIELD_EQ(inName,"_points") ) { _points=inValue.Cast< Array< ::Dynamic > >(); return inValue; }
		if (HX_FIELD_EQ(inName,"_curveT") ) { _curveT=inValue.Cast< Array< Float > >(); return inValue; }
		if (HX_FIELD_EQ(inName,"_curveD") ) { _curveD=inValue.Cast< Array< Float > >(); return inValue; }
		break;
	case 8:
		if (HX_FIELD_EQ(inName,"_numSegs") ) { _numSegs=inValue.Cast< int >(); return inValue; }
		break;
	case 9:
		if (HX_FIELD_EQ(inName,"_distance") ) { _distance=inValue.Cast< Float >(); return inValue; }
		break;
	case 12:
		if (HX_FIELD_EQ(inName,"_updateCurve") ) { _updateCurve=inValue.Cast< bool >(); return inValue; }
	}
	return super::__SetField(inName,inValue,inCallProp);
}

void QuadPath_obj::__GetFields(Array< ::String> &outFields)
{
	outFields->push(HX_CSTRING("_points"));
	outFields->push(HX_CSTRING("_distance"));
	outFields->push(HX_CSTRING("_speed"));
	outFields->push(HX_CSTRING("_index"));
	outFields->push(HX_CSTRING("_numSegs"));
	outFields->push(HX_CSTRING("_updateCurve"));
	outFields->push(HX_CSTRING("_curveT"));
	outFields->push(HX_CSTRING("_curveD"));
	outFields->push(HX_CSTRING("_a"));
	outFields->push(HX_CSTRING("_b"));
	outFields->push(HX_CSTRING("_c"));
	super::__GetFields(outFields);
};

static ::String sStaticFields[] = {
	HX_CSTRING("_Point"),
	HX_CSTRING("_Point2"),
	String(null()) };

#if HXCPP_SCRIPTABLE
static hx::StorageInfo sMemberStorageInfo[] = {
	{hx::fsObject /*Array< ::Dynamic >*/ ,(int)offsetof(QuadPath_obj,_points),HX_CSTRING("_points")},
	{hx::fsFloat,(int)offsetof(QuadPath_obj,_distance),HX_CSTRING("_distance")},
	{hx::fsFloat,(int)offsetof(QuadPath_obj,_speed),HX_CSTRING("_speed")},
	{hx::fsInt,(int)offsetof(QuadPath_obj,_index),HX_CSTRING("_index")},
	{hx::fsInt,(int)offsetof(QuadPath_obj,_numSegs),HX_CSTRING("_numSegs")},
	{hx::fsBool,(int)offsetof(QuadPath_obj,_updateCurve),HX_CSTRING("_updateCurve")},
	{hx::fsObject /*Array< Float >*/ ,(int)offsetof(QuadPath_obj,_curveT),HX_CSTRING("_curveT")},
	{hx::fsObject /*Array< Float >*/ ,(int)offsetof(QuadPath_obj,_curveD),HX_CSTRING("_curveD")},
	{hx::fsObject /*::flixel::util::FlxPoint*/ ,(int)offsetof(QuadPath_obj,_a),HX_CSTRING("_a")},
	{hx::fsObject /*::flixel::util::FlxPoint*/ ,(int)offsetof(QuadPath_obj,_b),HX_CSTRING("_b")},
	{hx::fsObject /*::flixel::util::FlxPoint*/ ,(int)offsetof(QuadPath_obj,_c),HX_CSTRING("_c")},
	{ hx::fsUnknown, 0, null()}
};
#endif

static ::String sMemberFields[] = {
	HX_CSTRING("_points"),
	HX_CSTRING("_distance"),
	HX_CSTRING("_speed"),
	HX_CSTRING("_index"),
	HX_CSTRING("_numSegs"),
	HX_CSTRING("_updateCurve"),
	HX_CSTRING("_curveT"),
	HX_CSTRING("_curveD"),
	HX_CSTRING("_a"),
	HX_CSTRING("_b"),
	HX_CSTRING("_c"),
	HX_CSTRING("destroy"),
	HX_CSTRING("setMotion"),
	HX_CSTRING("addPoint"),
	HX_CSTRING("getPoint"),
	HX_CSTRING("start"),
	HX_CSTRING("update"),
	HX_CSTRING("updatePath"),
	HX_CSTRING("getCurveLength"),
	String(null()) };

static void sMarkStatics(HX_MARK_PARAMS) {
	HX_MARK_MEMBER_NAME(QuadPath_obj::__mClass,"__mClass");
	HX_MARK_MEMBER_NAME(QuadPath_obj::_Point,"_Point");
	HX_MARK_MEMBER_NAME(QuadPath_obj::_Point2,"_Point2");
};

#ifdef HXCPP_VISIT_ALLOCS
static void sVisitStatics(HX_VISIT_PARAMS) {
	HX_VISIT_MEMBER_NAME(QuadPath_obj::__mClass,"__mClass");
	HX_VISIT_MEMBER_NAME(QuadPath_obj::_Point,"_Point");
	HX_VISIT_MEMBER_NAME(QuadPath_obj::_Point2,"_Point2");
};

#endif

Class QuadPath_obj::__mClass;

void QuadPath_obj::__register()
{
	hx::Static(__mClass) = hx::RegisterClass(HX_CSTRING("flixel.tweens.motion.QuadPath"), hx::TCanCast< QuadPath_obj> ,sStaticFields,sMemberFields,
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

void QuadPath_obj::__boot()
{
	_Point= ::flixel::util::FlxPoint_obj::__new(null(),null());
	_Point2= ::flixel::util::FlxPoint_obj::__new(null(),null());
}

} // end namespace flixel
} // end namespace tweens
} // end namespace motion
