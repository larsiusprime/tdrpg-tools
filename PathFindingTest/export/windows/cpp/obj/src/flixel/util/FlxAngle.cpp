#include <hxcpp.h>

#ifndef INCLUDED_Std
#include <Std.h>
#endif
#ifndef INCLUDED_flixel_FlxBasic
#include <flixel/FlxBasic.h>
#endif
#ifndef INCLUDED_flixel_FlxCamera
#include <flixel/FlxCamera.h>
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
#ifndef INCLUDED_flixel_input_mouse_FlxMouse
#include <flixel/input/mouse/FlxMouse.h>
#endif
#ifndef INCLUDED_flixel_input_touch_FlxTouch
#include <flixel/input/touch/FlxTouch.h>
#endif
#ifndef INCLUDED_flixel_interfaces_IFlxDestroyable
#include <flixel/interfaces/IFlxDestroyable.h>
#endif
#ifndef INCLUDED_flixel_interfaces_IFlxInput
#include <flixel/interfaces/IFlxInput.h>
#endif
#ifndef INCLUDED_flixel_util_FlxAngle
#include <flixel/util/FlxAngle.h>
#endif
#ifndef INCLUDED_flixel_util_FlxPoint
#include <flixel/util/FlxPoint.h>
#endif
#ifndef INCLUDED_hxMath
#include <hxMath.h>
#endif
namespace flixel{
namespace util{

Void FlxAngle_obj::__construct()
{
	return null();
}

//FlxAngle_obj::~FlxAngle_obj() { }

Dynamic FlxAngle_obj::__CreateEmpty() { return  new FlxAngle_obj; }
hx::ObjectPtr< FlxAngle_obj > FlxAngle_obj::__new()
{  hx::ObjectPtr< FlxAngle_obj > result = new FlxAngle_obj();
	result->__construct();
	return result;}

Dynamic FlxAngle_obj::__Create(hx::DynamicArray inArgs)
{  hx::ObjectPtr< FlxAngle_obj > result = new FlxAngle_obj();
	result->__construct();
	return result;}

Array< Float > FlxAngle_obj::cosTable;

Array< Float > FlxAngle_obj::sinTable;

Float FlxAngle_obj::TO_DEG;

Float FlxAngle_obj::TO_RAD;

::flixel::util::FlxPoint FlxAngle_obj::rotatePoint( Float X,Float Y,Float PivotX,Float PivotY,Float Angle,::flixel::util::FlxPoint point){
	HX_STACK_FRAME("flixel.util.FlxAngle","rotatePoint",0x699cdd82,"flixel.util.FlxAngle.rotatePoint","flixel/util/FlxAngle.hx",43,0x34a716c3)
	HX_STACK_ARG(X,"X")
	HX_STACK_ARG(Y,"Y")
	HX_STACK_ARG(PivotX,"PivotX")
	HX_STACK_ARG(PivotY,"PivotY")
	HX_STACK_ARG(Angle,"Angle")
	HX_STACK_ARG(point,"point")
	HX_STACK_LINE(44)
	Float sin = (int)0;		HX_STACK_VAR(sin,"sin");
	HX_STACK_LINE(45)
	Float cos = (int)0;		HX_STACK_VAR(cos,"cos");
	HX_STACK_LINE(46)
	Float radians = (Angle * -(::flixel::util::FlxAngle_obj::TO_RAD));		HX_STACK_VAR(radians,"radians");
	HX_STACK_LINE(47)
	while(((radians < -(::Math_obj::PI)))){
		HX_STACK_LINE(49)
		hx::AddEq(radians,(::Math_obj::PI * (int)2));
	}
	HX_STACK_LINE(51)
	while(((radians > ::Math_obj::PI))){
		HX_STACK_LINE(53)
		radians = (radians - (::Math_obj::PI * (int)2));
	}
	HX_STACK_LINE(56)
	if (((radians < (int)0))){
		HX_STACK_LINE(58)
		sin = ((1.27323954 * radians) + ((.405284735 * radians) * radians));
		HX_STACK_LINE(59)
		if (((sin < (int)0))){
			HX_STACK_LINE(61)
			sin = ((.225 * (((sin * -(sin)) - sin))) + sin);
		}
		else{
			HX_STACK_LINE(65)
			sin = ((.225 * (((sin * sin) - sin))) + sin);
		}
	}
	else{
		HX_STACK_LINE(70)
		sin = ((1.27323954 * radians) - ((0.405284735 * radians) * radians));
		HX_STACK_LINE(71)
		if (((sin < (int)0))){
			HX_STACK_LINE(73)
			sin = ((.225 * (((sin * -(sin)) - sin))) + sin);
		}
		else{
			HX_STACK_LINE(77)
			sin = ((.225 * (((sin * sin) - sin))) + sin);
		}
	}
	HX_STACK_LINE(81)
	hx::AddEq(radians,(Float(::Math_obj::PI) / Float((int)2)));
	HX_STACK_LINE(82)
	if (((radians > ::Math_obj::PI))){
		HX_STACK_LINE(84)
		radians = (radians - (::Math_obj::PI * (int)2));
	}
	HX_STACK_LINE(86)
	if (((radians < (int)0))){
		HX_STACK_LINE(88)
		cos = ((1.27323954 * radians) + ((0.405284735 * radians) * radians));
		HX_STACK_LINE(89)
		if (((cos < (int)0))){
			HX_STACK_LINE(91)
			cos = ((.225 * (((cos * -(cos)) - cos))) + cos);
		}
		else{
			HX_STACK_LINE(95)
			cos = ((.225 * (((cos * cos) - cos))) + cos);
		}
	}
	else{
		HX_STACK_LINE(100)
		cos = ((1.27323954 * radians) - ((0.405284735 * radians) * radians));
		HX_STACK_LINE(101)
		if (((cos < (int)0))){
			HX_STACK_LINE(103)
			cos = ((.225 * (((cos * -(cos)) - cos))) + cos);
		}
		else{
			HX_STACK_LINE(107)
			cos = ((.225 * (((cos * cos) - cos))) + cos);
		}
	}
	HX_STACK_LINE(111)
	Float dx = (X - PivotX);		HX_STACK_VAR(dx,"dx");
	HX_STACK_LINE(114)
	Float dy = (Y - PivotY);		HX_STACK_VAR(dy,"dy");
	HX_STACK_LINE(115)
	if (((point == null()))){
		HX_STACK_LINE(117)
		point = ::flixel::util::FlxPoint_obj::__new(null(),null());
	}
	HX_STACK_LINE(119)
	point->set_x(((PivotX + (cos * dx)) - (sin * dy)));
	HX_STACK_LINE(120)
	point->set_y(((PivotY - (sin * dx)) - (cos * dy)));
	HX_STACK_LINE(121)
	return point;
}


STATIC_HX_DEFINE_DYNAMIC_FUNC6(FlxAngle_obj,rotatePoint,return )

Float FlxAngle_obj::getAngle( ::flixel::util::FlxPoint Point1,::flixel::util::FlxPoint Point2){
	HX_STACK_FRAME("flixel.util.FlxAngle","getAngle",0x66899fb0,"flixel.util.FlxAngle.getAngle","flixel/util/FlxAngle.hx",132,0x34a716c3)
	HX_STACK_ARG(Point1,"Point1")
	HX_STACK_ARG(Point2,"Point2")
	HX_STACK_LINE(133)
	Float x = (Point2->x - Point1->x);		HX_STACK_VAR(x,"x");
	HX_STACK_LINE(134)
	Float y = (Point2->y - Point1->y);		HX_STACK_VAR(y,"y");
	HX_STACK_LINE(135)
	Float angle = (int)0;		HX_STACK_VAR(angle,"angle");
	HX_STACK_LINE(137)
	if (((bool((x != (int)0)) || bool((y != (int)0))))){
		HX_STACK_LINE(139)
		Float c1 = (::Math_obj::PI * 0.25);		HX_STACK_VAR(c1,"c1");
		HX_STACK_LINE(140)
		Float c2 = ((int)3 * c1);		HX_STACK_VAR(c2,"c2");
		HX_STACK_LINE(141)
		Float ay;		HX_STACK_VAR(ay,"ay");
		HX_STACK_LINE(141)
		if (((y < (int)0))){
			HX_STACK_LINE(141)
			ay = -(y);
		}
		else{
			HX_STACK_LINE(141)
			ay = y;
		}
		HX_STACK_LINE(143)
		if (((x >= (int)0))){
			HX_STACK_LINE(145)
			angle = (c1 - (c1 * ((Float(((x - ay))) / Float(((x + ay)))))));
		}
		else{
			HX_STACK_LINE(149)
			angle = (c2 - (c1 * ((Float(((x + ay))) / Float(((ay - x)))))));
		}
		HX_STACK_LINE(151)
		angle = (((  (((y < (int)0))) ? Float(-(angle)) : Float(angle) )) * ::flixel::util::FlxAngle_obj::TO_DEG);
		HX_STACK_LINE(153)
		if (((angle > (int)90))){
			HX_STACK_LINE(155)
			angle = (angle - (int)270);
		}
		else{
			HX_STACK_LINE(159)
			hx::AddEq(angle,(int)90);
		}
	}
	HX_STACK_LINE(163)
	return angle;
}


STATIC_HX_DEFINE_DYNAMIC_FUNC2(FlxAngle_obj,getAngle,return )

Void FlxAngle_obj::sinCosGenerator( int length,hx::Null< Float >  __o_sinAmplitude,hx::Null< Float >  __o_cosAmplitude,hx::Null< Float >  __o_frequency){
Float sinAmplitude = __o_sinAmplitude.Default(1.0);
Float cosAmplitude = __o_cosAmplitude.Default(1.0);
Float frequency = __o_frequency.Default(1.0);
	HX_STACK_FRAME("flixel.util.FlxAngle","sinCosGenerator",0x2783fa51,"flixel.util.FlxAngle.sinCosGenerator","flixel/util/FlxAngle.hx",181,0x34a716c3)
	HX_STACK_ARG(length,"length")
	HX_STACK_ARG(sinAmplitude,"sinAmplitude")
	HX_STACK_ARG(cosAmplitude,"cosAmplitude")
	HX_STACK_ARG(frequency,"frequency")
{
		HX_STACK_LINE(182)
		Float sin = sinAmplitude;		HX_STACK_VAR(sin,"sin");
		HX_STACK_LINE(183)
		Float cos = cosAmplitude;		HX_STACK_VAR(cos,"cos");
		HX_STACK_LINE(184)
		Float frq = (Float((frequency * ::Math_obj::PI)) / Float(length));		HX_STACK_VAR(frq,"frq");
		HX_STACK_LINE(186)
		::flixel::util::FlxAngle_obj::cosTable = Array_obj< Float >::__new();
		HX_STACK_LINE(187)
		::flixel::util::FlxAngle_obj::sinTable = Array_obj< Float >::__new();
		HX_STACK_LINE(189)
		{
			HX_STACK_LINE(189)
			int _g = (int)0;		HX_STACK_VAR(_g,"_g");
			HX_STACK_LINE(189)
			while(((_g < length))){
				HX_STACK_LINE(189)
				int c = (_g)++;		HX_STACK_VAR(c,"c");
				HX_STACK_LINE(191)
				hx::SubEq(cos,(sin * frq));
				HX_STACK_LINE(192)
				hx::AddEq(sin,(cos * frq));
				HX_STACK_LINE(194)
				::flixel::util::FlxAngle_obj::cosTable[c] = cos;
				HX_STACK_LINE(195)
				::flixel::util::FlxAngle_obj::sinTable[c] = sin;
			}
		}
	}
return null();
}


STATIC_HX_DEFINE_DYNAMIC_FUNC4(FlxAngle_obj,sinCosGenerator,(void))

int FlxAngle_obj::wrapAngle( Float angle){
	HX_STACK_FRAME("flixel.util.FlxAngle","wrapAngle",0x38cb39f6,"flixel.util.FlxAngle.wrapAngle","flixel/util/FlxAngle.hx",208,0x34a716c3)
	HX_STACK_ARG(angle,"angle")
	HX_STACK_LINE(209)
	int result = ::Std_obj::_int(angle);		HX_STACK_VAR(result,"result");
	HX_STACK_LINE(211)
	if (((angle > (int)180))){
		HX_STACK_LINE(213)
		result = (int)-180;
	}
	else{
		HX_STACK_LINE(215)
		if (((angle < (int)-180))){
			HX_STACK_LINE(217)
			result = (int)180;
		}
	}
	HX_STACK_LINE(220)
	return result;
}


STATIC_HX_DEFINE_DYNAMIC_FUNC1(FlxAngle_obj,wrapAngle,return )

int FlxAngle_obj::angleLimit( int angle,int min,int max){
	HX_STACK_FRAME("flixel.util.FlxAngle","angleLimit",0x2a40d57b,"flixel.util.FlxAngle.angleLimit","flixel/util/FlxAngle.hx",233,0x34a716c3)
	HX_STACK_ARG(angle,"angle")
	HX_STACK_ARG(min,"min")
	HX_STACK_ARG(max,"max")
	HX_STACK_LINE(234)
	int result = angle;		HX_STACK_VAR(result,"result");
	HX_STACK_LINE(236)
	if (((angle > max))){
		HX_STACK_LINE(238)
		result = max;
	}
	else{
		HX_STACK_LINE(240)
		if (((angle < min))){
			HX_STACK_LINE(242)
			result = min;
		}
	}
	HX_STACK_LINE(245)
	return result;
}


STATIC_HX_DEFINE_DYNAMIC_FUNC3(FlxAngle_obj,angleLimit,return )

Float FlxAngle_obj::asDegrees( Float radians){
	HX_STACK_FRAME("flixel.util.FlxAngle","asDegrees",0x19409522,"flixel.util.FlxAngle.asDegrees","flixel/util/FlxAngle.hx",257,0x34a716c3)
	HX_STACK_ARG(radians,"radians")
	HX_STACK_LINE(257)
	return (radians * ::flixel::util::FlxAngle_obj::TO_DEG);
}


STATIC_HX_DEFINE_DYNAMIC_FUNC1(FlxAngle_obj,asDegrees,return )

Float FlxAngle_obj::asRadians( Float degrees){
	HX_STACK_FRAME("flixel.util.FlxAngle","asRadians",0x05d5f7ed,"flixel.util.FlxAngle.asRadians","flixel/util/FlxAngle.hx",269,0x34a716c3)
	HX_STACK_ARG(degrees,"degrees")
	HX_STACK_LINE(269)
	return (degrees * ::flixel::util::FlxAngle_obj::TO_RAD);
}


STATIC_HX_DEFINE_DYNAMIC_FUNC1(FlxAngle_obj,asRadians,return )

Float FlxAngle_obj::angleBetween( ::flixel::FlxSprite SpriteA,::flixel::FlxSprite SpriteB,hx::Null< bool >  __o_AsDegrees){
bool AsDegrees = __o_AsDegrees.Default(false);
	HX_STACK_FRAME("flixel.util.FlxAngle","angleBetween",0xb3fd5808,"flixel.util.FlxAngle.angleBetween","flixel/util/FlxAngle.hx",282,0x34a716c3)
	HX_STACK_ARG(SpriteA,"SpriteA")
	HX_STACK_ARG(SpriteB,"SpriteB")
	HX_STACK_ARG(AsDegrees,"AsDegrees")
{
		HX_STACK_LINE(283)
		Float dx = ((SpriteB->x + SpriteB->origin->x) - ((SpriteA->x + SpriteA->origin->x)));		HX_STACK_VAR(dx,"dx");
		HX_STACK_LINE(284)
		Float dy = ((SpriteB->y + SpriteB->origin->y) - ((SpriteA->y + SpriteA->origin->y)));		HX_STACK_VAR(dy,"dy");
		HX_STACK_LINE(286)
		if ((AsDegrees)){
			HX_STACK_LINE(287)
			Float radians = ::Math_obj::atan2(dy,dx);		HX_STACK_VAR(radians,"radians");
			HX_STACK_LINE(287)
			return (radians * ::flixel::util::FlxAngle_obj::TO_DEG);
		}
		else{
			HX_STACK_LINE(289)
			return ::Math_obj::atan2(dy,dx);
		}
		HX_STACK_LINE(286)
		return 0.;
	}
}


STATIC_HX_DEFINE_DYNAMIC_FUNC3(FlxAngle_obj,angleBetween,return )

Float FlxAngle_obj::angleBetweenPoint( ::flixel::FlxSprite Sprite,::flixel::util::FlxPoint Target,hx::Null< bool >  __o_AsDegrees){
bool AsDegrees = __o_AsDegrees.Default(false);
	HX_STACK_FRAME("flixel.util.FlxAngle","angleBetweenPoint",0xab3baf28,"flixel.util.FlxAngle.angleBetweenPoint","flixel/util/FlxAngle.hx",302,0x34a716c3)
	HX_STACK_ARG(Sprite,"Sprite")
	HX_STACK_ARG(Target,"Target")
	HX_STACK_ARG(AsDegrees,"AsDegrees")
{
		HX_STACK_LINE(303)
		Float dx = (Target->x - ((Sprite->x + Sprite->origin->x)));		HX_STACK_VAR(dx,"dx");
		HX_STACK_LINE(304)
		Float dy = (Target->y - ((Sprite->y + Sprite->origin->y)));		HX_STACK_VAR(dy,"dy");
		HX_STACK_LINE(306)
		if ((AsDegrees)){
			HX_STACK_LINE(307)
			Float radians = ::Math_obj::atan2(dy,dx);		HX_STACK_VAR(radians,"radians");
			HX_STACK_LINE(307)
			return (radians * ::flixel::util::FlxAngle_obj::TO_DEG);
		}
		else{
			HX_STACK_LINE(309)
			return ::Math_obj::atan2(dy,dx);
		}
		HX_STACK_LINE(306)
		return 0.;
	}
}


STATIC_HX_DEFINE_DYNAMIC_FUNC3(FlxAngle_obj,angleBetweenPoint,return )

Float FlxAngle_obj::angleBetweenMouse( ::flixel::FlxObject Object,hx::Null< bool >  __o_AsDegrees){
bool AsDegrees = __o_AsDegrees.Default(false);
	HX_STACK_FRAME("flixel.util.FlxAngle","angleBetweenMouse",0xf11110fd,"flixel.util.FlxAngle.angleBetweenMouse","flixel/util/FlxAngle.hx",322,0x34a716c3)
	HX_STACK_ARG(Object,"Object")
	HX_STACK_ARG(AsDegrees,"AsDegrees")
{
		HX_STACK_LINE(324)
		if (((Object == null()))){
			HX_STACK_LINE(325)
			return (int)0;
		}
		HX_STACK_LINE(327)
		::flixel::util::FlxPoint p = Object->getScreenXY(null(),null());		HX_STACK_VAR(p,"p");
		HX_STACK_LINE(329)
		Float dx = (::flixel::FlxG_obj::mouse->screenX - p->x);		HX_STACK_VAR(dx,"dx");
		HX_STACK_LINE(330)
		Float dy = (::flixel::FlxG_obj::mouse->screenY - p->y);		HX_STACK_VAR(dy,"dy");
		HX_STACK_LINE(332)
		if ((AsDegrees)){
			HX_STACK_LINE(333)
			Float radians = ::Math_obj::atan2(dy,dx);		HX_STACK_VAR(radians,"radians");
			HX_STACK_LINE(333)
			return (radians * ::flixel::util::FlxAngle_obj::TO_DEG);
		}
		else{
			HX_STACK_LINE(335)
			return ::Math_obj::atan2(dy,dx);
		}
		HX_STACK_LINE(332)
		return 0.;
	}
}


STATIC_HX_DEFINE_DYNAMIC_FUNC2(FlxAngle_obj,angleBetweenMouse,return )

Float FlxAngle_obj::angleBetweenTouch( ::flixel::FlxObject Object,::flixel::input::touch::FlxTouch Touch,hx::Null< bool >  __o_AsDegrees){
bool AsDegrees = __o_AsDegrees.Default(false);
	HX_STACK_FRAME("flixel.util.FlxAngle","angleBetweenTouch",0xf8df1297,"flixel.util.FlxAngle.angleBetweenTouch","flixel/util/FlxAngle.hx",350,0x34a716c3)
	HX_STACK_ARG(Object,"Object")
	HX_STACK_ARG(Touch,"Touch")
	HX_STACK_ARG(AsDegrees,"AsDegrees")
{
		HX_STACK_LINE(352)
		::flixel::util::FlxPoint p = Object->getScreenXY(null(),null());		HX_STACK_VAR(p,"p");
		HX_STACK_LINE(354)
		Float dx = (Touch->screenX - p->x);		HX_STACK_VAR(dx,"dx");
		HX_STACK_LINE(355)
		Float dy = (Touch->screenY - p->y);		HX_STACK_VAR(dy,"dy");
		HX_STACK_LINE(357)
		if ((AsDegrees)){
			HX_STACK_LINE(358)
			Float radians = ::Math_obj::atan2(dy,dx);		HX_STACK_VAR(radians,"radians");
			HX_STACK_LINE(358)
			return (radians * ::flixel::util::FlxAngle_obj::TO_DEG);
		}
		else{
			HX_STACK_LINE(360)
			return ::Math_obj::atan2(dy,dx);
		}
		HX_STACK_LINE(357)
		return 0.;
	}
}


STATIC_HX_DEFINE_DYNAMIC_FUNC3(FlxAngle_obj,angleBetweenTouch,return )

::flixel::util::FlxPoint FlxAngle_obj::getCartesianCoords( Float Radius,Float Angle,::flixel::util::FlxPoint point){
	HX_STACK_FRAME("flixel.util.FlxAngle","getCartesianCoords",0xcba23863,"flixel.util.FlxAngle.getCartesianCoords","flixel/util/FlxAngle.hx",373,0x34a716c3)
	HX_STACK_ARG(Radius,"Radius")
	HX_STACK_ARG(Angle,"Angle")
	HX_STACK_ARG(point,"point")
	HX_STACK_LINE(374)
	::flixel::util::FlxPoint p = point;		HX_STACK_VAR(p,"p");
	HX_STACK_LINE(375)
	if (((p == null()))){
		HX_STACK_LINE(377)
		p = ::flixel::util::FlxPoint_obj::__new(null(),null());
	}
	HX_STACK_LINE(380)
	p->set_x((Radius * ::Math_obj::cos((Angle * ::flixel::util::FlxAngle_obj::TO_RAD))));
	HX_STACK_LINE(381)
	p->set_y((Radius * ::Math_obj::sin((Angle * ::flixel::util::FlxAngle_obj::TO_RAD))));
	HX_STACK_LINE(382)
	return p;
}


STATIC_HX_DEFINE_DYNAMIC_FUNC3(FlxAngle_obj,getCartesianCoords,return )

::flixel::util::FlxPoint FlxAngle_obj::getPolarCoords( Float X,Float Y,::flixel::util::FlxPoint point){
	HX_STACK_FRAME("flixel.util.FlxAngle","getPolarCoords",0xef5b8a19,"flixel.util.FlxAngle.getPolarCoords","flixel/util/FlxAngle.hx",394,0x34a716c3)
	HX_STACK_ARG(X,"X")
	HX_STACK_ARG(Y,"Y")
	HX_STACK_ARG(point,"point")
	HX_STACK_LINE(395)
	::flixel::util::FlxPoint p = point;		HX_STACK_VAR(p,"p");
	HX_STACK_LINE(396)
	if (((p == null()))){
		HX_STACK_LINE(398)
		p = ::flixel::util::FlxPoint_obj::__new(null(),null());
	}
	HX_STACK_LINE(401)
	p->set_x(::Math_obj::sqrt(((X * X) + (Y * Y))));
	HX_STACK_LINE(402)
	p->set_y((::Math_obj::atan2(Y,X) * ::flixel::util::FlxAngle_obj::TO_DEG));
	HX_STACK_LINE(403)
	return p;
}


STATIC_HX_DEFINE_DYNAMIC_FUNC3(FlxAngle_obj,getPolarCoords,return )


FlxAngle_obj::FlxAngle_obj()
{
}

Dynamic FlxAngle_obj::__Field(const ::String &inName,bool inCallProp)
{
	switch(inName.length) {
	case 6:
		if (HX_FIELD_EQ(inName,"TO_DEG") ) { return TO_DEG; }
		if (HX_FIELD_EQ(inName,"TO_RAD") ) { return TO_RAD; }
		break;
	case 8:
		if (HX_FIELD_EQ(inName,"cosTable") ) { return cosTable; }
		if (HX_FIELD_EQ(inName,"sinTable") ) { return sinTable; }
		if (HX_FIELD_EQ(inName,"getAngle") ) { return getAngle_dyn(); }
		break;
	case 9:
		if (HX_FIELD_EQ(inName,"wrapAngle") ) { return wrapAngle_dyn(); }
		if (HX_FIELD_EQ(inName,"asDegrees") ) { return asDegrees_dyn(); }
		if (HX_FIELD_EQ(inName,"asRadians") ) { return asRadians_dyn(); }
		break;
	case 10:
		if (HX_FIELD_EQ(inName,"angleLimit") ) { return angleLimit_dyn(); }
		break;
	case 11:
		if (HX_FIELD_EQ(inName,"rotatePoint") ) { return rotatePoint_dyn(); }
		break;
	case 12:
		if (HX_FIELD_EQ(inName,"angleBetween") ) { return angleBetween_dyn(); }
		break;
	case 14:
		if (HX_FIELD_EQ(inName,"getPolarCoords") ) { return getPolarCoords_dyn(); }
		break;
	case 15:
		if (HX_FIELD_EQ(inName,"sinCosGenerator") ) { return sinCosGenerator_dyn(); }
		break;
	case 17:
		if (HX_FIELD_EQ(inName,"angleBetweenPoint") ) { return angleBetweenPoint_dyn(); }
		if (HX_FIELD_EQ(inName,"angleBetweenMouse") ) { return angleBetweenMouse_dyn(); }
		if (HX_FIELD_EQ(inName,"angleBetweenTouch") ) { return angleBetweenTouch_dyn(); }
		break;
	case 18:
		if (HX_FIELD_EQ(inName,"getCartesianCoords") ) { return getCartesianCoords_dyn(); }
	}
	return super::__Field(inName,inCallProp);
}

Dynamic FlxAngle_obj::__SetField(const ::String &inName,const Dynamic &inValue,bool inCallProp)
{
	switch(inName.length) {
	case 6:
		if (HX_FIELD_EQ(inName,"TO_DEG") ) { TO_DEG=inValue.Cast< Float >(); return inValue; }
		if (HX_FIELD_EQ(inName,"TO_RAD") ) { TO_RAD=inValue.Cast< Float >(); return inValue; }
		break;
	case 8:
		if (HX_FIELD_EQ(inName,"cosTable") ) { cosTable=inValue.Cast< Array< Float > >(); return inValue; }
		if (HX_FIELD_EQ(inName,"sinTable") ) { sinTable=inValue.Cast< Array< Float > >(); return inValue; }
	}
	return super::__SetField(inName,inValue,inCallProp);
}

void FlxAngle_obj::__GetFields(Array< ::String> &outFields)
{
	super::__GetFields(outFields);
};

static ::String sStaticFields[] = {
	HX_CSTRING("cosTable"),
	HX_CSTRING("sinTable"),
	HX_CSTRING("TO_DEG"),
	HX_CSTRING("TO_RAD"),
	HX_CSTRING("rotatePoint"),
	HX_CSTRING("getAngle"),
	HX_CSTRING("sinCosGenerator"),
	HX_CSTRING("wrapAngle"),
	HX_CSTRING("angleLimit"),
	HX_CSTRING("asDegrees"),
	HX_CSTRING("asRadians"),
	HX_CSTRING("angleBetween"),
	HX_CSTRING("angleBetweenPoint"),
	HX_CSTRING("angleBetweenMouse"),
	HX_CSTRING("angleBetweenTouch"),
	HX_CSTRING("getCartesianCoords"),
	HX_CSTRING("getPolarCoords"),
	String(null()) };

#if HXCPP_SCRIPTABLE
static hx::StorageInfo *sMemberStorageInfo = 0;
#endif

static ::String sMemberFields[] = {
	String(null()) };

static void sMarkStatics(HX_MARK_PARAMS) {
	HX_MARK_MEMBER_NAME(FlxAngle_obj::__mClass,"__mClass");
	HX_MARK_MEMBER_NAME(FlxAngle_obj::cosTable,"cosTable");
	HX_MARK_MEMBER_NAME(FlxAngle_obj::sinTable,"sinTable");
	HX_MARK_MEMBER_NAME(FlxAngle_obj::TO_DEG,"TO_DEG");
	HX_MARK_MEMBER_NAME(FlxAngle_obj::TO_RAD,"TO_RAD");
};

#ifdef HXCPP_VISIT_ALLOCS
static void sVisitStatics(HX_VISIT_PARAMS) {
	HX_VISIT_MEMBER_NAME(FlxAngle_obj::__mClass,"__mClass");
	HX_VISIT_MEMBER_NAME(FlxAngle_obj::cosTable,"cosTable");
	HX_VISIT_MEMBER_NAME(FlxAngle_obj::sinTable,"sinTable");
	HX_VISIT_MEMBER_NAME(FlxAngle_obj::TO_DEG,"TO_DEG");
	HX_VISIT_MEMBER_NAME(FlxAngle_obj::TO_RAD,"TO_RAD");
};

#endif

Class FlxAngle_obj::__mClass;

void FlxAngle_obj::__register()
{
	hx::Static(__mClass) = hx::RegisterClass(HX_CSTRING("flixel.util.FlxAngle"), hx::TCanCast< FlxAngle_obj> ,sStaticFields,sMemberFields,
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

void FlxAngle_obj::__boot()
{
	cosTable= Array_obj< Float >::__new();
	sinTable= Array_obj< Float >::__new();
	TO_DEG= (Float((int)180) / Float(::Math_obj::PI));
	TO_RAD= (Float(::Math_obj::PI) / Float((int)180));
}

} // end namespace flixel
} // end namespace util
