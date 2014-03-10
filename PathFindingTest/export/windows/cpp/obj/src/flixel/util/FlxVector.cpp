#include <hxcpp.h>

#ifndef INCLUDED_flixel_interfaces_IFlxDestroyable
#include <flixel/interfaces/IFlxDestroyable.h>
#endif
#ifndef INCLUDED_flixel_util_FlxAngle
#include <flixel/util/FlxAngle.h>
#endif
#ifndef INCLUDED_flixel_util_FlxPoint
#include <flixel/util/FlxPoint.h>
#endif
#ifndef INCLUDED_flixel_util_FlxVector
#include <flixel/util/FlxVector.h>
#endif
#ifndef INCLUDED_hxMath
#include <hxMath.h>
#endif
namespace flixel{
namespace util{

Void FlxVector_obj::__construct(hx::Null< Float >  __o_X,hx::Null< Float >  __o_Y)
{
HX_STACK_FRAME("flixel.util.FlxVector","new",0xf9e6a78d,"flixel.util.FlxVector.new","flixel/util/FlxVector.hx",22,0xa3e1b4e3)

HX_STACK_ARG(__o_X,"X")

HX_STACK_ARG(__o_Y,"Y")
Float X = __o_X.Default(0);
Float Y = __o_Y.Default(0);
{
	HX_STACK_LINE(22)
	super::__construct(X,Y);
}
;
	return null();
}

//FlxVector_obj::~FlxVector_obj() { }

Dynamic FlxVector_obj::__CreateEmpty() { return  new FlxVector_obj; }
hx::ObjectPtr< FlxVector_obj > FlxVector_obj::__new(hx::Null< Float >  __o_X,hx::Null< Float >  __o_Y)
{  hx::ObjectPtr< FlxVector_obj > result = new FlxVector_obj();
	result->__construct(__o_X,__o_Y);
	return result;}

Dynamic FlxVector_obj::__Create(hx::DynamicArray inArgs)
{  hx::ObjectPtr< FlxVector_obj > result = new FlxVector_obj();
	result->__construct(inArgs[0],inArgs[1]);
	return result;}

::flixel::util::FlxPoint FlxVector_obj::set( hx::Null< Float >  __o_X,hx::Null< Float >  __o_Y){
Float X = __o_X.Default(0);
Float Y = __o_Y.Default(0);
	HX_STACK_FRAME("flixel.util.FlxVector","set",0xf9ea72cf,"flixel.util.FlxVector.set","flixel/util/FlxVector.hx",31,0xa3e1b4e3)
	HX_STACK_THIS(this)
	HX_STACK_ARG(X,"X")
	HX_STACK_ARG(Y,"Y")
{
		HX_STACK_LINE(32)
		this->set_x(X);
		HX_STACK_LINE(33)
		this->set_y(Y);
		HX_STACK_LINE(34)
		return hx::ObjectPtr<OBJ_>(this);
	}
}


::flixel::util::FlxVector FlxVector_obj::scale( Float k){
	HX_STACK_FRAME("flixel.util.FlxVector","scale",0x1e278af7,"flixel.util.FlxVector.scale","flixel/util/FlxVector.hx",43,0xa3e1b4e3)
	HX_STACK_THIS(this)
	HX_STACK_ARG(k,"k")
	HX_STACK_LINE(44)
	{
		HX_STACK_LINE(44)
		::flixel::util::FlxVector _g = hx::ObjectPtr<OBJ_>(this);		HX_STACK_VAR(_g,"_g");
		HX_STACK_LINE(44)
		_g->set_x((_g->x * k));
	}
	HX_STACK_LINE(45)
	{
		HX_STACK_LINE(45)
		::flixel::util::FlxVector _g = hx::ObjectPtr<OBJ_>(this);		HX_STACK_VAR(_g,"_g");
		HX_STACK_LINE(45)
		_g->set_y((_g->y * k));
	}
	HX_STACK_LINE(46)
	return hx::ObjectPtr<OBJ_>(this);
}


HX_DEFINE_DYNAMIC_FUNC1(FlxVector_obj,scale,return )

::flixel::util::FlxVector FlxVector_obj::scaleNew( Float k){
	HX_STACK_FRAME("flixel.util.FlxVector","scaleNew",0xcf29f1a9,"flixel.util.FlxVector.scaleNew","flixel/util/FlxVector.hx",56,0xa3e1b4e3)
	HX_STACK_THIS(this)
	HX_STACK_ARG(k,"k")
	HX_STACK_LINE(56)
	::flixel::util::FlxVector _this;		HX_STACK_VAR(_this,"_this");
	HX_STACK_LINE(56)
	{
		HX_STACK_LINE(56)
		::flixel::util::FlxVector vec = null();		HX_STACK_VAR(vec,"vec");
		HX_STACK_LINE(56)
		if (((vec == null()))){
			HX_STACK_LINE(56)
			vec = ::flixel::util::FlxVector_obj::__new(null(),null());
		}
		HX_STACK_LINE(56)
		vec->set_x(this->x);
		HX_STACK_LINE(56)
		vec->set_y(this->y);
		HX_STACK_LINE(56)
		_this = vec;
	}
	HX_STACK_LINE(56)
	{
		HX_STACK_LINE(56)
		::flixel::util::FlxVector _g = _this;		HX_STACK_VAR(_g,"_g");
		HX_STACK_LINE(56)
		_g->set_x((_g->x * k));
	}
	HX_STACK_LINE(56)
	{
		HX_STACK_LINE(56)
		::flixel::util::FlxVector _g = _this;		HX_STACK_VAR(_g,"_g");
		HX_STACK_LINE(56)
		_g->set_y((_g->y * k));
	}
	HX_STACK_LINE(56)
	return _this;
}


HX_DEFINE_DYNAMIC_FUNC1(FlxVector_obj,scaleNew,return )

::flixel::util::FlxVector FlxVector_obj::add( ::flixel::util::FlxVector v){
	HX_STACK_FRAME("flixel.util.FlxVector","add",0xf9dcc94e,"flixel.util.FlxVector.add","flixel/util/FlxVector.hx",65,0xa3e1b4e3)
	HX_STACK_THIS(this)
	HX_STACK_ARG(v,"v")
	HX_STACK_LINE(66)
	{
		HX_STACK_LINE(66)
		::flixel::util::FlxVector _g = hx::ObjectPtr<OBJ_>(this);		HX_STACK_VAR(_g,"_g");
		HX_STACK_LINE(66)
		_g->set_x((_g->x + v->x));
	}
	HX_STACK_LINE(67)
	{
		HX_STACK_LINE(67)
		::flixel::util::FlxVector _g = hx::ObjectPtr<OBJ_>(this);		HX_STACK_VAR(_g,"_g");
		HX_STACK_LINE(67)
		_g->set_y((_g->y + v->y));
	}
	HX_STACK_LINE(68)
	return hx::ObjectPtr<OBJ_>(this);
}


HX_DEFINE_DYNAMIC_FUNC1(FlxVector_obj,add,return )

::flixel::util::FlxVector FlxVector_obj::addNew( ::flixel::util::FlxVector v){
	HX_STACK_FRAME("flixel.util.FlxVector","addNew",0xa75103b2,"flixel.util.FlxVector.addNew","flixel/util/FlxVector.hx",78,0xa3e1b4e3)
	HX_STACK_THIS(this)
	HX_STACK_ARG(v,"v")
	HX_STACK_LINE(78)
	::flixel::util::FlxVector _this;		HX_STACK_VAR(_this,"_this");
	HX_STACK_LINE(78)
	{
		HX_STACK_LINE(78)
		::flixel::util::FlxVector vec = null();		HX_STACK_VAR(vec,"vec");
		HX_STACK_LINE(78)
		if (((vec == null()))){
			HX_STACK_LINE(78)
			vec = ::flixel::util::FlxVector_obj::__new(null(),null());
		}
		HX_STACK_LINE(78)
		vec->set_x(this->x);
		HX_STACK_LINE(78)
		vec->set_y(this->y);
		HX_STACK_LINE(78)
		_this = vec;
	}
	HX_STACK_LINE(78)
	{
		HX_STACK_LINE(78)
		::flixel::util::FlxVector _g = _this;		HX_STACK_VAR(_g,"_g");
		HX_STACK_LINE(78)
		_g->set_x((_g->x + v->x));
	}
	HX_STACK_LINE(78)
	{
		HX_STACK_LINE(78)
		::flixel::util::FlxVector _g = _this;		HX_STACK_VAR(_g,"_g");
		HX_STACK_LINE(78)
		_g->set_y((_g->y + v->y));
	}
	HX_STACK_LINE(78)
	return _this;
}


HX_DEFINE_DYNAMIC_FUNC1(FlxVector_obj,addNew,return )

::flixel::util::FlxVector FlxVector_obj::substract( ::flixel::util::FlxVector v){
	HX_STACK_FRAME("flixel.util.FlxVector","substract",0x2bf5cdae,"flixel.util.FlxVector.substract","flixel/util/FlxVector.hx",87,0xa3e1b4e3)
	HX_STACK_THIS(this)
	HX_STACK_ARG(v,"v")
	HX_STACK_LINE(88)
	{
		HX_STACK_LINE(88)
		::flixel::util::FlxVector _g = hx::ObjectPtr<OBJ_>(this);		HX_STACK_VAR(_g,"_g");
		HX_STACK_LINE(88)
		_g->set_x((_g->x - v->x));
	}
	HX_STACK_LINE(89)
	{
		HX_STACK_LINE(89)
		::flixel::util::FlxVector _g = hx::ObjectPtr<OBJ_>(this);		HX_STACK_VAR(_g,"_g");
		HX_STACK_LINE(89)
		_g->set_y((_g->y - v->y));
	}
	HX_STACK_LINE(90)
	return hx::ObjectPtr<OBJ_>(this);
}


HX_DEFINE_DYNAMIC_FUNC1(FlxVector_obj,substract,return )

::flixel::util::FlxVector FlxVector_obj::substractNew( ::flixel::util::FlxVector v){
	HX_STACK_FRAME("flixel.util.FlxVector","substractNew",0xef26fb52,"flixel.util.FlxVector.substractNew","flixel/util/FlxVector.hx",100,0xa3e1b4e3)
	HX_STACK_THIS(this)
	HX_STACK_ARG(v,"v")
	HX_STACK_LINE(100)
	::flixel::util::FlxVector _this;		HX_STACK_VAR(_this,"_this");
	HX_STACK_LINE(100)
	{
		HX_STACK_LINE(100)
		::flixel::util::FlxVector vec = null();		HX_STACK_VAR(vec,"vec");
		HX_STACK_LINE(100)
		if (((vec == null()))){
			HX_STACK_LINE(100)
			vec = ::flixel::util::FlxVector_obj::__new(null(),null());
		}
		HX_STACK_LINE(100)
		vec->set_x(this->x);
		HX_STACK_LINE(100)
		vec->set_y(this->y);
		HX_STACK_LINE(100)
		_this = vec;
	}
	HX_STACK_LINE(100)
	{
		HX_STACK_LINE(100)
		::flixel::util::FlxVector _g = _this;		HX_STACK_VAR(_g,"_g");
		HX_STACK_LINE(100)
		_g->set_x((_g->x - v->x));
	}
	HX_STACK_LINE(100)
	{
		HX_STACK_LINE(100)
		::flixel::util::FlxVector _g = _this;		HX_STACK_VAR(_g,"_g");
		HX_STACK_LINE(100)
		_g->set_y((_g->y - v->y));
	}
	HX_STACK_LINE(100)
	return _this;
}


HX_DEFINE_DYNAMIC_FUNC1(FlxVector_obj,substractNew,return )

Float FlxVector_obj::dotProduct( ::flixel::util::FlxVector v){
	HX_STACK_FRAME("flixel.util.FlxVector","dotProduct",0xe6544019,"flixel.util.FlxVector.dotProduct","flixel/util/FlxVector.hx",110,0xa3e1b4e3)
	HX_STACK_THIS(this)
	HX_STACK_ARG(v,"v")
	HX_STACK_LINE(110)
	return ((this->x * v->x) + (this->y * v->y));
}


HX_DEFINE_DYNAMIC_FUNC1(FlxVector_obj,dotProduct,return )

Float FlxVector_obj::dotProdWithNormalizing( ::flixel::util::FlxVector v){
	HX_STACK_FRAME("flixel.util.FlxVector","dotProdWithNormalizing",0x78163bb7,"flixel.util.FlxVector.dotProdWithNormalizing","flixel/util/FlxVector.hx",119,0xa3e1b4e3)
	HX_STACK_THIS(this)
	HX_STACK_ARG(v,"v")
	struct _Function_1_1{
		inline static ::flixel::util::FlxVector Block( ::flixel::util::FlxVector &v){
			HX_STACK_FRAME("*","closure",0x5bdab937,"*.closure","flixel/util/FlxVector.hx",120,0xa3e1b4e3)
			{
				HX_STACK_LINE(120)
				::flixel::util::FlxVector vec = ::flixel::util::FlxVector_obj::_vector1;		HX_STACK_VAR(vec,"vec");
				HX_STACK_LINE(120)
				if (((vec == null()))){
					HX_STACK_LINE(120)
					vec = ::flixel::util::FlxVector_obj::__new(null(),null());
				}
				HX_STACK_LINE(120)
				vec->set_x(v->x);
				HX_STACK_LINE(120)
				vec->set_y(v->y);
				HX_STACK_LINE(120)
				return vec;
			}
			return null();
		}
	};
	HX_STACK_LINE(120)
	::flixel::util::FlxVector normalized = (_Function_1_1::Block(v))->normalize();		HX_STACK_VAR(normalized,"normalized");
	HX_STACK_LINE(121)
	return ((this->x * normalized->x) + (this->y * normalized->y));
}


HX_DEFINE_DYNAMIC_FUNC1(FlxVector_obj,dotProdWithNormalizing,return )

bool FlxVector_obj::isPerpendicular( ::flixel::util::FlxVector v){
	HX_STACK_FRAME("flixel.util.FlxVector","isPerpendicular",0x1d48770d,"flixel.util.FlxVector.isPerpendicular","flixel/util/FlxVector.hx",131,0xa3e1b4e3)
	HX_STACK_THIS(this)
	HX_STACK_ARG(v,"v")
	HX_STACK_LINE(131)
	return (::Math_obj::abs(((this->x * v->x) + (this->y * v->y))) < 9.9999999999999984e-015);
}


HX_DEFINE_DYNAMIC_FUNC1(FlxVector_obj,isPerpendicular,return )

Float FlxVector_obj::crossProductLength( ::flixel::util::FlxVector v){
	HX_STACK_FRAME("flixel.util.FlxVector","crossProductLength",0x7fc88948,"flixel.util.FlxVector.crossProductLength","flixel/util/FlxVector.hx",141,0xa3e1b4e3)
	HX_STACK_THIS(this)
	HX_STACK_ARG(v,"v")
	HX_STACK_LINE(141)
	return ((this->x * v->y) - (this->y * v->x));
}


HX_DEFINE_DYNAMIC_FUNC1(FlxVector_obj,crossProductLength,return )

bool FlxVector_obj::isParallel( ::flixel::util::FlxVector v){
	HX_STACK_FRAME("flixel.util.FlxVector","isParallel",0xa109d544,"flixel.util.FlxVector.isParallel","flixel/util/FlxVector.hx",151,0xa3e1b4e3)
	HX_STACK_THIS(this)
	HX_STACK_ARG(v,"v")
	HX_STACK_LINE(151)
	return (::Math_obj::abs(((this->x * v->y) - (this->y * v->x))) < 9.9999999999999984e-015);
}


HX_DEFINE_DYNAMIC_FUNC1(FlxVector_obj,isParallel,return )

bool FlxVector_obj::isZero( ){
	HX_STACK_FRAME("flixel.util.FlxVector","isZero",0x76a3f725,"flixel.util.FlxVector.isZero","flixel/util/FlxVector.hx",160,0xa3e1b4e3)
	HX_STACK_THIS(this)
	HX_STACK_LINE(160)
	if (((::Math_obj::abs(this->x) < 0.0000001))){
		HX_STACK_LINE(160)
		return (::Math_obj::abs(this->y) < 0.0000001);
	}
	else{
		HX_STACK_LINE(160)
		return false;
	}
	HX_STACK_LINE(160)
	return false;
}


HX_DEFINE_DYNAMIC_FUNC0(FlxVector_obj,isZero,return )

::flixel::util::FlxVector FlxVector_obj::zero( ){
	HX_STACK_FRAME("flixel.util.FlxVector","zero",0xb7da7f5b,"flixel.util.FlxVector.zero","flixel/util/FlxVector.hx",167,0xa3e1b4e3)
	HX_STACK_THIS(this)
	HX_STACK_LINE(168)
	this->set_x(this->set_y((int)0));
	HX_STACK_LINE(169)
	return hx::ObjectPtr<OBJ_>(this);
}


HX_DEFINE_DYNAMIC_FUNC0(FlxVector_obj,zero,return )

::flixel::util::FlxVector FlxVector_obj::normalize( ){
	HX_STACK_FRAME("flixel.util.FlxVector","normalize",0xf4b52e7a,"flixel.util.FlxVector.normalize","flixel/util/FlxVector.hx",176,0xa3e1b4e3)
	HX_STACK_THIS(this)
	HX_STACK_LINE(177)
	if (((  (((::Math_obj::abs(this->x) < 0.0000001))) ? bool((::Math_obj::abs(this->y) < 0.0000001)) : bool(false) ))){
		HX_STACK_LINE(179)
		this->set_x((int)1);
		HX_STACK_LINE(180)
		return hx::ObjectPtr<OBJ_>(this);
	}
	HX_STACK_LINE(182)
	Float k = (Float((int)1) / Float(::Math_obj::sqrt(((this->x * this->x) + (this->y * this->y)))));		HX_STACK_VAR(k,"k");
	HX_STACK_LINE(182)
	{
		HX_STACK_LINE(182)
		::flixel::util::FlxVector _g = hx::ObjectPtr<OBJ_>(this);		HX_STACK_VAR(_g,"_g");
		HX_STACK_LINE(182)
		_g->set_x((_g->x * k));
	}
	HX_STACK_LINE(182)
	{
		HX_STACK_LINE(182)
		::flixel::util::FlxVector _g = hx::ObjectPtr<OBJ_>(this);		HX_STACK_VAR(_g,"_g");
		HX_STACK_LINE(182)
		_g->set_y((_g->y * k));
	}
	HX_STACK_LINE(182)
	return hx::ObjectPtr<OBJ_>(this);
}


HX_DEFINE_DYNAMIC_FUNC0(FlxVector_obj,normalize,return )

Float FlxVector_obj::get_dx( ){
	HX_STACK_FRAME("flixel.util.FlxVector","get_dx",0xab7c11d0,"flixel.util.FlxVector.get_dx","flixel/util/FlxVector.hx",191,0xa3e1b4e3)
	HX_STACK_THIS(this)
	HX_STACK_LINE(192)
	if (((  (((::Math_obj::abs(this->x) < 0.0000001))) ? bool((::Math_obj::abs(this->y) < 0.0000001)) : bool(false) ))){
		HX_STACK_LINE(192)
		return (int)0;
	}
	HX_STACK_LINE(194)
	return (Float(this->x) / Float(::Math_obj::sqrt(((this->x * this->x) + (this->y * this->y)))));
}


HX_DEFINE_DYNAMIC_FUNC0(FlxVector_obj,get_dx,return )

Float FlxVector_obj::get_dy( ){
	HX_STACK_FRAME("flixel.util.FlxVector","get_dy",0xab7c11d1,"flixel.util.FlxVector.get_dy","flixel/util/FlxVector.hx",203,0xa3e1b4e3)
	HX_STACK_THIS(this)
	HX_STACK_LINE(204)
	if (((  (((::Math_obj::abs(this->x) < 0.0000001))) ? bool((::Math_obj::abs(this->y) < 0.0000001)) : bool(false) ))){
		HX_STACK_LINE(204)
		return (int)0;
	}
	HX_STACK_LINE(206)
	return (Float(this->y) / Float(::Math_obj::sqrt(((this->x * this->x) + (this->y * this->y)))));
}


HX_DEFINE_DYNAMIC_FUNC0(FlxVector_obj,get_dy,return )

bool FlxVector_obj::isNormalized( ){
	HX_STACK_FRAME("flixel.util.FlxVector","isNormalized",0xef7fe7f4,"flixel.util.FlxVector.isNormalized","flixel/util/FlxVector.hx",214,0xa3e1b4e3)
	HX_STACK_THIS(this)
	HX_STACK_LINE(214)
	return (::Math_obj::abs((((this->x * this->x) + (this->y * this->y)) - (int)1)) < 9.9999999999999984e-015);
}


HX_DEFINE_DYNAMIC_FUNC0(FlxVector_obj,isNormalized,return )

bool FlxVector_obj::equals( ::flixel::util::FlxVector v){
	HX_STACK_FRAME("flixel.util.FlxVector","equals",0xc83f1132,"flixel.util.FlxVector.equals","flixel/util/FlxVector.hx",223,0xa3e1b4e3)
	HX_STACK_THIS(this)
	HX_STACK_ARG(v,"v")
	HX_STACK_LINE(223)
	if (((::Math_obj::abs((this->x - v->x)) < 0.0000001))){
		HX_STACK_LINE(223)
		return (::Math_obj::abs((this->y - v->y)) < 0.0000001);
	}
	else{
		HX_STACK_LINE(223)
		return false;
	}
	HX_STACK_LINE(223)
	return false;
}


HX_DEFINE_DYNAMIC_FUNC1(FlxVector_obj,equals,return )

Float FlxVector_obj::get_length( ){
	HX_STACK_FRAME("flixel.util.FlxVector","get_length",0x37f31d22,"flixel.util.FlxVector.get_length","flixel/util/FlxVector.hx",233,0xa3e1b4e3)
	HX_STACK_THIS(this)
	HX_STACK_LINE(233)
	return ::Math_obj::sqrt(((this->x * this->x) + (this->y * this->y)));
}


HX_DEFINE_DYNAMIC_FUNC0(FlxVector_obj,get_length,return )

Float FlxVector_obj::set_length( Float l){
	HX_STACK_FRAME("flixel.util.FlxVector","set_length",0x3b70bb96,"flixel.util.FlxVector.set_length","flixel/util/FlxVector.hx",237,0xa3e1b4e3)
	HX_STACK_THIS(this)
	HX_STACK_ARG(l,"l")
	HX_STACK_LINE(238)
	Float a = this->get_radians();		HX_STACK_VAR(a,"a");
	HX_STACK_LINE(239)
	this->set_x((l * ::Math_obj::cos(a)));
	HX_STACK_LINE(240)
	this->set_y((l * ::Math_obj::sin(a)));
	HX_STACK_LINE(241)
	return l;
}


HX_DEFINE_DYNAMIC_FUNC1(FlxVector_obj,set_length,return )

Float FlxVector_obj::get_lengthSquared( ){
	HX_STACK_FRAME("flixel.util.FlxVector","get_lengthSquared",0x942d5c25,"flixel.util.FlxVector.get_lengthSquared","flixel/util/FlxVector.hx",251,0xa3e1b4e3)
	HX_STACK_THIS(this)
	HX_STACK_LINE(251)
	return ((this->x * this->x) + (this->y * this->y));
}


HX_DEFINE_DYNAMIC_FUNC0(FlxVector_obj,get_lengthSquared,return )

Float FlxVector_obj::get_degrees( ){
	HX_STACK_FRAME("flixel.util.FlxVector","get_degrees",0x6f868feb,"flixel.util.FlxVector.get_degrees","flixel/util/FlxVector.hx",261,0xa3e1b4e3)
	HX_STACK_THIS(this)
	HX_STACK_LINE(261)
	return (this->get_radians() * ::flixel::util::FlxAngle_obj::TO_DEG);
}


HX_DEFINE_DYNAMIC_FUNC0(FlxVector_obj,get_degrees,return )

Float FlxVector_obj::set_degrees( Float degs){
	HX_STACK_FRAME("flixel.util.FlxVector","set_degrees",0x79f396f7,"flixel.util.FlxVector.set_degrees","flixel/util/FlxVector.hx",265,0xa3e1b4e3)
	HX_STACK_THIS(this)
	HX_STACK_ARG(degs,"degs")
	HX_STACK_LINE(266)
	{
		HX_STACK_LINE(266)
		Float rads = (degs * ::flixel::util::FlxAngle_obj::TO_RAD);		HX_STACK_VAR(rads,"rads");
		HX_STACK_LINE(266)
		Float len = ::Math_obj::sqrt(((this->x * this->x) + (this->y * this->y)));		HX_STACK_VAR(len,"len");
		HX_STACK_LINE(266)
		this->set_x((len * ::Math_obj::cos(rads)));
		HX_STACK_LINE(266)
		this->set_y((len * ::Math_obj::sin(rads)));
		HX_STACK_LINE(266)
		rads;
	}
	HX_STACK_LINE(267)
	return degs;
}


HX_DEFINE_DYNAMIC_FUNC1(FlxVector_obj,set_degrees,return )

Float FlxVector_obj::get_radians( ){
	HX_STACK_FRAME("flixel.util.FlxVector","get_radians",0x5c1bf2b6,"flixel.util.FlxVector.get_radians","flixel/util/FlxVector.hx",276,0xa3e1b4e3)
	HX_STACK_THIS(this)
	HX_STACK_LINE(277)
	if (((  (((::Math_obj::abs(this->x) < 0.0000001))) ? bool((::Math_obj::abs(this->y) < 0.0000001)) : bool(false) ))){
		HX_STACK_LINE(277)
		return (int)0;
	}
	HX_STACK_LINE(279)
	return ::Math_obj::atan2(this->y,this->x);
}


HX_DEFINE_DYNAMIC_FUNC0(FlxVector_obj,get_radians,return )

Float FlxVector_obj::set_radians( Float rads){
	HX_STACK_FRAME("flixel.util.FlxVector","set_radians",0x6688f9c2,"flixel.util.FlxVector.set_radians","flixel/util/FlxVector.hx",283,0xa3e1b4e3)
	HX_STACK_THIS(this)
	HX_STACK_ARG(rads,"rads")
	HX_STACK_LINE(284)
	Float len = ::Math_obj::sqrt(((this->x * this->x) + (this->y * this->y)));		HX_STACK_VAR(len,"len");
	HX_STACK_LINE(286)
	this->set_x((len * ::Math_obj::cos(rads)));
	HX_STACK_LINE(287)
	this->set_y((len * ::Math_obj::sin(rads)));
	HX_STACK_LINE(288)
	return rads;
}


HX_DEFINE_DYNAMIC_FUNC1(FlxVector_obj,set_radians,return )

::flixel::util::FlxVector FlxVector_obj::rotateByRadians( Float rads){
	HX_STACK_FRAME("flixel.util.FlxVector","rotateByRadians",0xe0456e2d,"flixel.util.FlxVector.rotateByRadians","flixel/util/FlxVector.hx",297,0xa3e1b4e3)
	HX_STACK_THIS(this)
	HX_STACK_ARG(rads,"rads")
	HX_STACK_LINE(298)
	Float s = ::Math_obj::sin(rads);		HX_STACK_VAR(s,"s");
	HX_STACK_LINE(299)
	Float c = ::Math_obj::cos(rads);		HX_STACK_VAR(c,"c");
	HX_STACK_LINE(300)
	Float tempX = this->x;		HX_STACK_VAR(tempX,"tempX");
	HX_STACK_LINE(302)
	this->set_x(((tempX * c) - (this->y * s)));
	HX_STACK_LINE(303)
	this->set_y(((tempX * s) + (this->y * c)));
	HX_STACK_LINE(305)
	return hx::ObjectPtr<OBJ_>(this);
}


HX_DEFINE_DYNAMIC_FUNC1(FlxVector_obj,rotateByRadians,return )

::flixel::util::FlxVector FlxVector_obj::rotateByDegrees( Float degs){
	HX_STACK_FRAME("flixel.util.FlxVector","rotateByDegrees",0xf3b00b62,"flixel.util.FlxVector.rotateByDegrees","flixel/util/FlxVector.hx",315,0xa3e1b4e3)
	HX_STACK_THIS(this)
	HX_STACK_ARG(degs,"degs")
	HX_STACK_LINE(315)
	Float rads = (degs * ::flixel::util::FlxAngle_obj::TO_RAD);		HX_STACK_VAR(rads,"rads");
	HX_STACK_LINE(315)
	Float s = ::Math_obj::sin(rads);		HX_STACK_VAR(s,"s");
	HX_STACK_LINE(315)
	Float c = ::Math_obj::cos(rads);		HX_STACK_VAR(c,"c");
	HX_STACK_LINE(315)
	Float tempX = this->x;		HX_STACK_VAR(tempX,"tempX");
	HX_STACK_LINE(315)
	this->set_x(((tempX * c) - (this->y * s)));
	HX_STACK_LINE(315)
	this->set_y(((tempX * s) + (this->y * c)));
	HX_STACK_LINE(315)
	return hx::ObjectPtr<OBJ_>(this);
}


HX_DEFINE_DYNAMIC_FUNC1(FlxVector_obj,rotateByDegrees,return )

::flixel::util::FlxVector FlxVector_obj::rotateWithTrig( Float sin,Float cos){
	HX_STACK_FRAME("flixel.util.FlxVector","rotateWithTrig",0x626cdd70,"flixel.util.FlxVector.rotateWithTrig","flixel/util/FlxVector.hx",325,0xa3e1b4e3)
	HX_STACK_THIS(this)
	HX_STACK_ARG(sin,"sin")
	HX_STACK_ARG(cos,"cos")
	HX_STACK_LINE(326)
	Float tempX = this->x;		HX_STACK_VAR(tempX,"tempX");
	HX_STACK_LINE(327)
	this->set_x(((tempX * cos) - (this->y * sin)));
	HX_STACK_LINE(328)
	this->set_y(((tempX * sin) + (this->y * cos)));
	HX_STACK_LINE(329)
	return hx::ObjectPtr<OBJ_>(this);
}


HX_DEFINE_DYNAMIC_FUNC2(FlxVector_obj,rotateWithTrig,return )

::flixel::util::FlxVector FlxVector_obj::rightNormal( ::flixel::util::FlxVector vec){
	HX_STACK_FRAME("flixel.util.FlxVector","rightNormal",0x491f8b50,"flixel.util.FlxVector.rightNormal","flixel/util/FlxVector.hx",336,0xa3e1b4e3)
	HX_STACK_THIS(this)
	HX_STACK_ARG(vec,"vec")
	HX_STACK_LINE(337)
	if (((vec == null()))){
		HX_STACK_LINE(339)
		vec = ::flixel::util::FlxVector_obj::__new(null(),null());
	}
	HX_STACK_LINE(341)
	hx::TCast< ::flixel::util::FlxVector >::cast(vec->set(-(this->y),this->x));
	HX_STACK_LINE(342)
	return vec;
}


HX_DEFINE_DYNAMIC_FUNC1(FlxVector_obj,rightNormal,return )

Float FlxVector_obj::get_rx( ){
	HX_STACK_FRAME("flixel.util.FlxVector","get_rx",0xab7c1e02,"flixel.util.FlxVector.get_rx","flixel/util/FlxVector.hx",352,0xa3e1b4e3)
	HX_STACK_THIS(this)
	HX_STACK_LINE(352)
	return -(this->y);
}


HX_DEFINE_DYNAMIC_FUNC0(FlxVector_obj,get_rx,return )

Float FlxVector_obj::get_ry( ){
	HX_STACK_FRAME("flixel.util.FlxVector","get_ry",0xab7c1e03,"flixel.util.FlxVector.get_ry","flixel/util/FlxVector.hx",362,0xa3e1b4e3)
	HX_STACK_THIS(this)
	HX_STACK_LINE(362)
	return this->x;
}


HX_DEFINE_DYNAMIC_FUNC0(FlxVector_obj,get_ry,return )

::flixel::util::FlxVector FlxVector_obj::leftNormal( ::flixel::util::FlxVector vec){
	HX_STACK_FRAME("flixel.util.FlxVector","leftNormal",0x07de4601,"flixel.util.FlxVector.leftNormal","flixel/util/FlxVector.hx",369,0xa3e1b4e3)
	HX_STACK_THIS(this)
	HX_STACK_ARG(vec,"vec")
	HX_STACK_LINE(370)
	if (((vec == null()))){
		HX_STACK_LINE(372)
		vec = ::flixel::util::FlxVector_obj::__new(null(),null());
	}
	HX_STACK_LINE(374)
	hx::TCast< ::flixel::util::FlxVector >::cast(vec->set(this->y,-(this->x)));
	HX_STACK_LINE(375)
	return vec;
}


HX_DEFINE_DYNAMIC_FUNC1(FlxVector_obj,leftNormal,return )

Float FlxVector_obj::get_lx( ){
	HX_STACK_FRAME("flixel.util.FlxVector","get_lx",0xab7c18c8,"flixel.util.FlxVector.get_lx","flixel/util/FlxVector.hx",385,0xa3e1b4e3)
	HX_STACK_THIS(this)
	HX_STACK_LINE(385)
	return this->y;
}


HX_DEFINE_DYNAMIC_FUNC0(FlxVector_obj,get_lx,return )

Float FlxVector_obj::get_ly( ){
	HX_STACK_FRAME("flixel.util.FlxVector","get_ly",0xab7c18c9,"flixel.util.FlxVector.get_ly","flixel/util/FlxVector.hx",395,0xa3e1b4e3)
	HX_STACK_THIS(this)
	HX_STACK_LINE(395)
	return -(this->x);
}


HX_DEFINE_DYNAMIC_FUNC0(FlxVector_obj,get_ly,return )

::flixel::util::FlxVector FlxVector_obj::negate( ){
	HX_STACK_FRAME("flixel.util.FlxVector","negate",0x6f6564b5,"flixel.util.FlxVector.negate","flixel/util/FlxVector.hx",402,0xa3e1b4e3)
	HX_STACK_THIS(this)
	HX_STACK_LINE(403)
	{
		HX_STACK_LINE(403)
		::flixel::util::FlxVector _g = hx::ObjectPtr<OBJ_>(this);		HX_STACK_VAR(_g,"_g");
		HX_STACK_LINE(403)
		_g->set_x((_g->x * (int)-1));
	}
	HX_STACK_LINE(404)
	{
		HX_STACK_LINE(404)
		::flixel::util::FlxVector _g = hx::ObjectPtr<OBJ_>(this);		HX_STACK_VAR(_g,"_g");
		HX_STACK_LINE(404)
		_g->set_y((_g->y * (int)-1));
	}
	HX_STACK_LINE(405)
	return hx::ObjectPtr<OBJ_>(this);
}


HX_DEFINE_DYNAMIC_FUNC0(FlxVector_obj,negate,return )

::flixel::util::FlxVector FlxVector_obj::negateNew( ){
	HX_STACK_FRAME("flixel.util.FlxVector","negateNew",0x0ef042ab,"flixel.util.FlxVector.negateNew","flixel/util/FlxVector.hx",410,0xa3e1b4e3)
	HX_STACK_THIS(this)
	HX_STACK_LINE(410)
	::flixel::util::FlxVector _this;		HX_STACK_VAR(_this,"_this");
	HX_STACK_LINE(410)
	{
		HX_STACK_LINE(410)
		::flixel::util::FlxVector vec = null();		HX_STACK_VAR(vec,"vec");
		HX_STACK_LINE(410)
		if (((vec == null()))){
			HX_STACK_LINE(410)
			vec = ::flixel::util::FlxVector_obj::__new(null(),null());
		}
		HX_STACK_LINE(410)
		vec->set_x(this->x);
		HX_STACK_LINE(410)
		vec->set_y(this->y);
		HX_STACK_LINE(410)
		_this = vec;
	}
	HX_STACK_LINE(410)
	{
		HX_STACK_LINE(410)
		::flixel::util::FlxVector _g = _this;		HX_STACK_VAR(_g,"_g");
		HX_STACK_LINE(410)
		_g->set_x((_g->x * (int)-1));
	}
	HX_STACK_LINE(410)
	{
		HX_STACK_LINE(410)
		::flixel::util::FlxVector _g = _this;		HX_STACK_VAR(_g,"_g");
		HX_STACK_LINE(410)
		_g->set_y((_g->y * (int)-1));
	}
	HX_STACK_LINE(410)
	return _this;
}


HX_DEFINE_DYNAMIC_FUNC0(FlxVector_obj,negateNew,return )

::flixel::util::FlxVector FlxVector_obj::projectTo( ::flixel::util::FlxVector v,::flixel::util::FlxVector proj){
	HX_STACK_FRAME("flixel.util.FlxVector","projectTo",0xde0c7ba1,"flixel.util.FlxVector.projectTo","flixel/util/FlxVector.hx",421,0xa3e1b4e3)
	HX_STACK_THIS(this)
	HX_STACK_ARG(v,"v")
	HX_STACK_ARG(proj,"proj")
	HX_STACK_LINE(422)
	Float dp = ((this->x * v->x) + (this->y * v->y));		HX_STACK_VAR(dp,"dp");
	HX_STACK_LINE(423)
	Float lenSq = ((v->x * v->x) + (v->y * v->y));		HX_STACK_VAR(lenSq,"lenSq");
	HX_STACK_LINE(425)
	if (((proj == null()))){
		HX_STACK_LINE(427)
		proj = ::flixel::util::FlxVector_obj::__new(null(),null());
	}
	HX_STACK_LINE(430)
	return hx::TCast< ::flixel::util::FlxVector >::cast(proj->set((Float((dp * v->x)) / Float(lenSq)),(Float((dp * v->y)) / Float(lenSq))));
}


HX_DEFINE_DYNAMIC_FUNC2(FlxVector_obj,projectTo,return )

::flixel::util::FlxVector FlxVector_obj::projectToNormalized( ::flixel::util::FlxVector v,::flixel::util::FlxVector proj){
	HX_STACK_FRAME("flixel.util.FlxVector","projectToNormalized",0xc6961738,"flixel.util.FlxVector.projectToNormalized","flixel/util/FlxVector.hx",440,0xa3e1b4e3)
	HX_STACK_THIS(this)
	HX_STACK_ARG(v,"v")
	HX_STACK_ARG(proj,"proj")
	HX_STACK_LINE(441)
	Float dp = ((this->x * v->x) + (this->y * v->y));		HX_STACK_VAR(dp,"dp");
	HX_STACK_LINE(443)
	if (((proj == null()))){
		HX_STACK_LINE(445)
		proj = ::flixel::util::FlxVector_obj::__new(null(),null());
	}
	HX_STACK_LINE(448)
	return hx::TCast< ::flixel::util::FlxVector >::cast(proj->set((dp * v->x),(dp * v->y)));
}


HX_DEFINE_DYNAMIC_FUNC2(FlxVector_obj,projectToNormalized,return )

Float FlxVector_obj::perpProduct( ::flixel::util::FlxVector v){
	HX_STACK_FRAME("flixel.util.FlxVector","perpProduct",0xa2c54aa9,"flixel.util.FlxVector.perpProduct","flixel/util/FlxVector.hx",456,0xa3e1b4e3)
	HX_STACK_THIS(this)
	HX_STACK_ARG(v,"v")
	HX_STACK_LINE(456)
	return ((this->y * v->x) + (-(this->x) * v->y));
}


HX_DEFINE_DYNAMIC_FUNC1(FlxVector_obj,perpProduct,return )

Float FlxVector_obj::ratio( ::flixel::util::FlxVector a,::flixel::util::FlxVector b,::flixel::util::FlxVector v){
	HX_STACK_FRAME("flixel.util.FlxVector","ratio",0x897cf178,"flixel.util.FlxVector.ratio","flixel/util/FlxVector.hx",467,0xa3e1b4e3)
	HX_STACK_THIS(this)
	HX_STACK_ARG(a,"a")
	HX_STACK_ARG(b,"b")
	HX_STACK_ARG(v,"v")
	HX_STACK_LINE(468)
	if (((::Math_obj::abs(((this->x * v->y) - (this->y * v->x))) < 9.9999999999999984e-015))){
		HX_STACK_LINE(468)
		return ::Math_obj::NaN;
	}
	HX_STACK_LINE(469)
	if (((bool((((this->x * this->x) + (this->y * this->y)) < 9.9999999999999984e-015)) || bool((((v->x * v->x) + (v->y * v->y)) < 9.9999999999999984e-015))))){
		HX_STACK_LINE(469)
		return ::Math_obj::NaN;
	}
	HX_STACK_LINE(471)
	{
		HX_STACK_LINE(471)
		::flixel::util::FlxVector vec = ::flixel::util::FlxVector_obj::_vector1;		HX_STACK_VAR(vec,"vec");
		HX_STACK_LINE(471)
		if (((vec == null()))){
			HX_STACK_LINE(471)
			vec = ::flixel::util::FlxVector_obj::__new(null(),null());
		}
		HX_STACK_LINE(471)
		vec->set_x(b->x);
		HX_STACK_LINE(471)
		vec->set_y(b->y);
		HX_STACK_LINE(471)
		::flixel::util::FlxVector_obj::_vector1 = vec;
	}
	HX_STACK_LINE(472)
	{
		HX_STACK_LINE(472)
		::flixel::util::FlxVector _this = ::flixel::util::FlxVector_obj::_vector1;		HX_STACK_VAR(_this,"_this");
		HX_STACK_LINE(472)
		{
			HX_STACK_LINE(472)
			::flixel::util::FlxVector _g = _this;		HX_STACK_VAR(_g,"_g");
			HX_STACK_LINE(472)
			_g->set_x((_g->x - a->x));
		}
		HX_STACK_LINE(472)
		{
			HX_STACK_LINE(472)
			::flixel::util::FlxVector _g = _this;		HX_STACK_VAR(_g,"_g");
			HX_STACK_LINE(472)
			_g->set_y((_g->y - a->y));
		}
		HX_STACK_LINE(472)
		_this;
	}
	struct _Function_1_1{
		inline static Float Block( ::flixel::util::FlxVector &v){
			HX_STACK_FRAME("*","closure",0x5bdab937,"*.closure","flixel/util/FlxVector.hx",474,0xa3e1b4e3)
			{
				HX_STACK_LINE(474)
				::flixel::util::FlxVector _this = ::flixel::util::FlxVector_obj::_vector1;		HX_STACK_VAR(_this,"_this");
				HX_STACK_LINE(474)
				return ((_this->y * v->x) + (-(_this->x) * v->y));
			}
			return null();
		}
	};
	HX_STACK_LINE(474)
	return (Float(_Function_1_1::Block(v)) / Float((((this->y * v->x) + (-(this->x) * v->y)))));
}


HX_DEFINE_DYNAMIC_FUNC3(FlxVector_obj,ratio,return )

::flixel::util::FlxVector FlxVector_obj::findIntersection( ::flixel::util::FlxVector a,::flixel::util::FlxVector b,::flixel::util::FlxVector v,::flixel::util::FlxVector intersection){
	HX_STACK_FRAME("flixel.util.FlxVector","findIntersection",0x6b2e20d5,"flixel.util.FlxVector.findIntersection","flixel/util/FlxVector.hx",485,0xa3e1b4e3)
	HX_STACK_THIS(this)
	HX_STACK_ARG(a,"a")
	HX_STACK_ARG(b,"b")
	HX_STACK_ARG(v,"v")
	HX_STACK_ARG(intersection,"intersection")
	HX_STACK_LINE(486)
	Float t = this->ratio(a,b,v);		HX_STACK_VAR(t,"t");
	HX_STACK_LINE(488)
	if (((intersection == null()))){
		HX_STACK_LINE(490)
		intersection = ::flixel::util::FlxVector_obj::__new(null(),null());
	}
	HX_STACK_LINE(493)
	if ((::Math_obj::isNaN(t))){
		HX_STACK_LINE(495)
		return hx::TCast< ::flixel::util::FlxVector >::cast(intersection->set(::Math_obj::NaN,::Math_obj::NaN));
	}
	HX_STACK_LINE(498)
	return hx::TCast< ::flixel::util::FlxVector >::cast(intersection->set((a->x + (t * this->x)),(a->y + (t * this->y))));
}


HX_DEFINE_DYNAMIC_FUNC4(FlxVector_obj,findIntersection,return )

::flixel::util::FlxVector FlxVector_obj::findIntersectionInBounds( ::flixel::util::FlxVector a,::flixel::util::FlxVector b,::flixel::util::FlxVector v,::flixel::util::FlxVector intersection){
	HX_STACK_FRAME("flixel.util.FlxVector","findIntersectionInBounds",0xc1780a2f,"flixel.util.FlxVector.findIntersectionInBounds","flixel/util/FlxVector.hx",509,0xa3e1b4e3)
	HX_STACK_THIS(this)
	HX_STACK_ARG(a,"a")
	HX_STACK_ARG(b,"b")
	HX_STACK_ARG(v,"v")
	HX_STACK_ARG(intersection,"intersection")
	HX_STACK_LINE(510)
	if (((intersection == null()))){
		HX_STACK_LINE(512)
		intersection = ::flixel::util::FlxVector_obj::__new(null(),null());
	}
	HX_STACK_LINE(515)
	Float t1 = this->ratio(a,b,v);		HX_STACK_VAR(t1,"t1");
	HX_STACK_LINE(516)
	Float t2 = v->ratio(b,a,hx::ObjectPtr<OBJ_>(this));		HX_STACK_VAR(t2,"t2");
	HX_STACK_LINE(517)
	if (((  (((  (((  (((  (((  ((!(::Math_obj::isNaN(t1)))) ? bool(!(::Math_obj::isNaN(t2))) : bool(false) ))) ? bool((t1 > (int)0)) : bool(false) ))) ? bool((t1 <= (int)1)) : bool(false) ))) ? bool((t2 > (int)0)) : bool(false) ))) ? bool((t2 <= (int)1)) : bool(false) ))){
		HX_STACK_LINE(519)
		return hx::TCast< ::flixel::util::FlxVector >::cast(intersection->set((a->x + (t1 * this->x)),(a->y + (t1 * this->y))));
	}
	HX_STACK_LINE(522)
	return hx::TCast< ::flixel::util::FlxVector >::cast(intersection->set(::Math_obj::NaN,::Math_obj::NaN));
}


HX_DEFINE_DYNAMIC_FUNC4(FlxVector_obj,findIntersectionInBounds,return )

::flixel::util::FlxVector FlxVector_obj::truncate( Float max){
	HX_STACK_FRAME("flixel.util.FlxVector","truncate",0x9ccac419,"flixel.util.FlxVector.truncate","flixel/util/FlxVector.hx",530,0xa3e1b4e3)
	HX_STACK_THIS(this)
	HX_STACK_ARG(max,"max")
	HX_STACK_LINE(531)
	{
		HX_STACK_LINE(531)
		Float l = ::Math_obj::min(max,::Math_obj::sqrt(((this->x * this->x) + (this->y * this->y))));		HX_STACK_VAR(l,"l");
		HX_STACK_LINE(531)
		Float a = this->get_radians();		HX_STACK_VAR(a,"a");
		HX_STACK_LINE(531)
		this->set_x((l * ::Math_obj::cos(a)));
		HX_STACK_LINE(531)
		this->set_y((l * ::Math_obj::sin(a)));
		HX_STACK_LINE(531)
		l;
	}
	HX_STACK_LINE(532)
	return hx::ObjectPtr<OBJ_>(this);
}


HX_DEFINE_DYNAMIC_FUNC1(FlxVector_obj,truncate,return )

Float FlxVector_obj::radiansBetween( ::flixel::util::FlxVector v){
	HX_STACK_FRAME("flixel.util.FlxVector","radiansBetween",0x8e24d369,"flixel.util.FlxVector.radiansBetween","flixel/util/FlxVector.hx",541,0xa3e1b4e3)
	HX_STACK_THIS(this)
	HX_STACK_ARG(v,"v")
	HX_STACK_LINE(542)
	{
		HX_STACK_LINE(542)
		::flixel::util::FlxVector vec = ::flixel::util::FlxVector_obj::_vector1;		HX_STACK_VAR(vec,"vec");
		HX_STACK_LINE(542)
		if (((vec == null()))){
			HX_STACK_LINE(542)
			vec = ::flixel::util::FlxVector_obj::__new(null(),null());
		}
		HX_STACK_LINE(542)
		vec->set_x(this->x);
		HX_STACK_LINE(542)
		vec->set_y(this->y);
		HX_STACK_LINE(542)
		::flixel::util::FlxVector_obj::_vector1 = vec;
	}
	HX_STACK_LINE(543)
	{
		HX_STACK_LINE(543)
		::flixel::util::FlxVector vec = ::flixel::util::FlxVector_obj::_vector2;		HX_STACK_VAR(vec,"vec");
		HX_STACK_LINE(543)
		if (((vec == null()))){
			HX_STACK_LINE(543)
			vec = ::flixel::util::FlxVector_obj::__new(null(),null());
		}
		HX_STACK_LINE(543)
		vec->set_x(this->x);
		HX_STACK_LINE(543)
		vec->set_y(this->y);
		HX_STACK_LINE(543)
		::flixel::util::FlxVector_obj::_vector2 = vec;
	}
	HX_STACK_LINE(545)
	if ((!(((::Math_obj::abs((((this->x * this->x) + (this->y * this->y)) - (int)1)) < 9.9999999999999984e-015))))){
		HX_STACK_LINE(547)
		::flixel::util::FlxVector_obj::_vector1->normalize();
	}
	HX_STACK_LINE(549)
	if ((!(((::Math_obj::abs((((v->x * v->x) + (v->y * v->y)) - (int)1)) < 9.9999999999999984e-015))))){
		HX_STACK_LINE(551)
		::flixel::util::FlxVector_obj::_vector2->normalize();
	}
	struct _Function_1_1{
		inline static Float Block( ){
			HX_STACK_FRAME("*","closure",0x5bdab937,"*.closure","flixel/util/FlxVector.hx",553,0xa3e1b4e3)
			{
				HX_STACK_LINE(553)
				::flixel::util::FlxVector _this = ::flixel::util::FlxVector_obj::_vector1;		HX_STACK_VAR(_this,"_this");
				HX_STACK_LINE(553)
				::flixel::util::FlxVector v1 = ::flixel::util::FlxVector_obj::_vector2;		HX_STACK_VAR(v1,"v1");
				HX_STACK_LINE(553)
				return ((_this->x * v1->x) + (_this->y * v1->y));
			}
			return null();
		}
	};
	HX_STACK_LINE(553)
	return ::Math_obj::acos(_Function_1_1::Block());
}


HX_DEFINE_DYNAMIC_FUNC1(FlxVector_obj,radiansBetween,return )

Float FlxVector_obj::degreesBetween( ::flixel::util::FlxVector v){
	HX_STACK_FRAME("flixel.util.FlxVector","degreesBetween",0xe36976d4,"flixel.util.FlxVector.degreesBetween","flixel/util/FlxVector.hx",563,0xa3e1b4e3)
	HX_STACK_THIS(this)
	HX_STACK_ARG(v,"v")
	struct _Function_1_1{
		inline static Float Block( ::flixel::util::FlxVector_obj *__this,::flixel::util::FlxVector &v){
			HX_STACK_FRAME("*","closure",0x5bdab937,"*.closure","flixel/util/FlxVector.hx",563,0xa3e1b4e3)
			{
				HX_STACK_LINE(563)
				{
					HX_STACK_LINE(563)
					::flixel::util::FlxVector vec = ::flixel::util::FlxVector_obj::_vector1;		HX_STACK_VAR(vec,"vec");
					HX_STACK_LINE(563)
					if (((vec == null()))){
						HX_STACK_LINE(563)
						vec = ::flixel::util::FlxVector_obj::__new(null(),null());
					}
					HX_STACK_LINE(563)
					vec->set_x(__this->x);
					HX_STACK_LINE(563)
					vec->set_y(__this->y);
					HX_STACK_LINE(563)
					::flixel::util::FlxVector_obj::_vector1 = vec;
				}
				HX_STACK_LINE(563)
				{
					HX_STACK_LINE(563)
					::flixel::util::FlxVector vec = ::flixel::util::FlxVector_obj::_vector2;		HX_STACK_VAR(vec,"vec");
					HX_STACK_LINE(563)
					if (((vec == null()))){
						HX_STACK_LINE(563)
						vec = ::flixel::util::FlxVector_obj::__new(null(),null());
					}
					HX_STACK_LINE(563)
					vec->set_x(__this->x);
					HX_STACK_LINE(563)
					vec->set_y(__this->y);
					HX_STACK_LINE(563)
					::flixel::util::FlxVector_obj::_vector2 = vec;
				}
				HX_STACK_LINE(563)
				if ((!(((::Math_obj::abs((((__this->x * __this->x) + (__this->y * __this->y)) - (int)1)) < 9.9999999999999984e-015))))){
					HX_STACK_LINE(563)
					::flixel::util::FlxVector_obj::_vector1->normalize();
				}
				HX_STACK_LINE(563)
				if ((!(((::Math_obj::abs((((v->x * v->x) + (v->y * v->y)) - (int)1)) < 9.9999999999999984e-015))))){
					HX_STACK_LINE(563)
					::flixel::util::FlxVector_obj::_vector2->normalize();
				}
				struct _Function_2_1{
					inline static Float Block( ){
						HX_STACK_FRAME("*","closure",0x5bdab937,"*.closure","flixel/util/FlxVector.hx",563,0xa3e1b4e3)
						{
							HX_STACK_LINE(563)
							::flixel::util::FlxVector _this = ::flixel::util::FlxVector_obj::_vector1;		HX_STACK_VAR(_this,"_this");
							HX_STACK_LINE(563)
							::flixel::util::FlxVector v1 = ::flixel::util::FlxVector_obj::_vector2;		HX_STACK_VAR(v1,"v1");
							HX_STACK_LINE(563)
							return ((_this->x * v1->x) + (_this->y * v1->y));
						}
						return null();
					}
				};
				HX_STACK_LINE(563)
				return ::Math_obj::acos(_Function_2_1::Block());
			}
			return null();
		}
	};
	HX_STACK_LINE(563)
	return (_Function_1_1::Block(this,v) * ::flixel::util::FlxAngle_obj::TO_DEG);
}


HX_DEFINE_DYNAMIC_FUNC1(FlxVector_obj,degreesBetween,return )

int FlxVector_obj::sign( ::flixel::util::FlxVector a,::flixel::util::FlxVector b){
	HX_STACK_FRAME("flixel.util.FlxVector","sign",0xb33d0070,"flixel.util.FlxVector.sign","flixel/util/FlxVector.hx",572,0xa3e1b4e3)
	HX_STACK_THIS(this)
	HX_STACK_ARG(a,"a")
	HX_STACK_ARG(b,"b")
	HX_STACK_LINE(573)
	Float signFl = ((((a->x - this->x)) * ((b->y - this->y))) - (((a->y - this->y)) * ((b->x - this->x))));		HX_STACK_VAR(signFl,"signFl");
	HX_STACK_LINE(574)
	if (((signFl == (int)0))){
		HX_STACK_LINE(576)
		return (int)0;
	}
	HX_STACK_LINE(578)
	return ::Math_obj::round((Float(signFl) / Float(::Math_obj::abs(signFl))));
}


HX_DEFINE_DYNAMIC_FUNC2(FlxVector_obj,sign,return )

Float FlxVector_obj::dist( ::flixel::util::FlxVector v){
	HX_STACK_FRAME("flixel.util.FlxVector","dist",0xa952d799,"flixel.util.FlxVector.dist","flixel/util/FlxVector.hx",586,0xa3e1b4e3)
	HX_STACK_THIS(this)
	HX_STACK_ARG(v,"v")
	struct _Function_1_1{
		inline static Float Block( ::flixel::util::FlxVector_obj *__this,::flixel::util::FlxVector &v){
			HX_STACK_FRAME("*","closure",0x5bdab937,"*.closure","flixel/util/FlxVector.hx",586,0xa3e1b4e3)
			{
				HX_STACK_LINE(586)
				Float dx = (v->x - __this->x);		HX_STACK_VAR(dx,"dx");
				HX_STACK_LINE(586)
				Float dy = (v->y - __this->y);		HX_STACK_VAR(dy,"dy");
				HX_STACK_LINE(586)
				return ((dx * dx) + (dy * dy));
			}
			return null();
		}
	};
	HX_STACK_LINE(586)
	return ::Math_obj::sqrt(_Function_1_1::Block(this,v));
}


HX_DEFINE_DYNAMIC_FUNC1(FlxVector_obj,dist,return )

Float FlxVector_obj::distSquared( ::flixel::util::FlxVector v){
	HX_STACK_FRAME("flixel.util.FlxVector","distSquared",0xda0bee8e,"flixel.util.FlxVector.distSquared","flixel/util/FlxVector.hx",593,0xa3e1b4e3)
	HX_STACK_THIS(this)
	HX_STACK_ARG(v,"v")
	HX_STACK_LINE(594)
	Float dx = (v->x - this->x);		HX_STACK_VAR(dx,"dx");
	HX_STACK_LINE(595)
	Float dy = (v->y - this->y);		HX_STACK_VAR(dy,"dy");
	HX_STACK_LINE(596)
	return ((dx * dx) + (dy * dy));
}


HX_DEFINE_DYNAMIC_FUNC1(FlxVector_obj,distSquared,return )

::flixel::util::FlxVector FlxVector_obj::bounce( ::flixel::util::FlxVector normal,hx::Null< Float >  __o_bounceCoeff){
Float bounceCoeff = __o_bounceCoeff.Default(1);
	HX_STACK_FRAME("flixel.util.FlxVector","bounce",0x6e69a87b,"flixel.util.FlxVector.bounce","flixel/util/FlxVector.hx",606,0xa3e1b4e3)
	HX_STACK_THIS(this)
	HX_STACK_ARG(normal,"normal")
	HX_STACK_ARG(bounceCoeff,"bounceCoeff")
{
		HX_STACK_LINE(607)
		Float d = ((((int)1 + bounceCoeff)) * (((this->x * normal->x) + (this->y * normal->y))));		HX_STACK_VAR(d,"d");
		HX_STACK_LINE(608)
		{
			HX_STACK_LINE(608)
			::flixel::util::FlxVector _g = hx::ObjectPtr<OBJ_>(this);		HX_STACK_VAR(_g,"_g");
			HX_STACK_LINE(608)
			_g->set_x((_g->x - (d * normal->x)));
		}
		HX_STACK_LINE(609)
		{
			HX_STACK_LINE(609)
			::flixel::util::FlxVector _g = hx::ObjectPtr<OBJ_>(this);		HX_STACK_VAR(_g,"_g");
			HX_STACK_LINE(609)
			_g->set_y((_g->y - (d * normal->y)));
		}
		HX_STACK_LINE(610)
		return hx::ObjectPtr<OBJ_>(this);
	}
}


HX_DEFINE_DYNAMIC_FUNC2(FlxVector_obj,bounce,return )

::flixel::util::FlxVector FlxVector_obj::bounceWithFriction( ::flixel::util::FlxVector normal,hx::Null< Float >  __o_bounceCoeff,hx::Null< Float >  __o_friction){
Float bounceCoeff = __o_bounceCoeff.Default(1);
Float friction = __o_friction.Default(0);
	HX_STACK_FRAME("flixel.util.FlxVector","bounceWithFriction",0x3656623b,"flixel.util.FlxVector.bounceWithFriction","flixel/util/FlxVector.hx",621,0xa3e1b4e3)
	HX_STACK_THIS(this)
	HX_STACK_ARG(normal,"normal")
	HX_STACK_ARG(bounceCoeff,"bounceCoeff")
	HX_STACK_ARG(friction,"friction")
{
		HX_STACK_LINE(622)
		::flixel::util::FlxVector p1;		HX_STACK_VAR(p1,"p1");
		HX_STACK_LINE(622)
		{
			HX_STACK_LINE(622)
			::flixel::util::FlxVector v;		HX_STACK_VAR(v,"v");
			HX_STACK_LINE(622)
			{
				HX_STACK_LINE(622)
				::flixel::util::FlxVector vec = ::flixel::util::FlxVector_obj::_vector3;		HX_STACK_VAR(vec,"vec");
				HX_STACK_LINE(622)
				if (((vec == null()))){
					HX_STACK_LINE(622)
					vec = ::flixel::util::FlxVector_obj::__new(null(),null());
				}
				HX_STACK_LINE(622)
				hx::TCast< ::flixel::util::FlxVector >::cast(vec->set(-(normal->y),normal->x));
				HX_STACK_LINE(622)
				v = vec;
			}
			HX_STACK_LINE(622)
			::flixel::util::FlxVector proj = ::flixel::util::FlxVector_obj::_vector1;		HX_STACK_VAR(proj,"proj");
			HX_STACK_LINE(622)
			Float dp = ((this->x * v->x) + (this->y * v->y));		HX_STACK_VAR(dp,"dp");
			HX_STACK_LINE(622)
			if (((proj == null()))){
				HX_STACK_LINE(622)
				proj = ::flixel::util::FlxVector_obj::__new(null(),null());
			}
			HX_STACK_LINE(622)
			p1 = hx::TCast< ::flixel::util::FlxVector >::cast(proj->set((dp * v->x),(dp * v->y)));
		}
		HX_STACK_LINE(623)
		::flixel::util::FlxVector p2;		HX_STACK_VAR(p2,"p2");
		HX_STACK_LINE(623)
		{
			HX_STACK_LINE(623)
			::flixel::util::FlxVector proj = ::flixel::util::FlxVector_obj::_vector2;		HX_STACK_VAR(proj,"proj");
			HX_STACK_LINE(623)
			Float dp = ((this->x * normal->x) + (this->y * normal->y));		HX_STACK_VAR(dp,"dp");
			HX_STACK_LINE(623)
			if (((proj == null()))){
				HX_STACK_LINE(623)
				proj = ::flixel::util::FlxVector_obj::__new(null(),null());
			}
			HX_STACK_LINE(623)
			p2 = hx::TCast< ::flixel::util::FlxVector >::cast(proj->set((dp * normal->x),(dp * normal->y)));
		}
		HX_STACK_LINE(624)
		Float bounceX = -(p2->x);		HX_STACK_VAR(bounceX,"bounceX");
		HX_STACK_LINE(625)
		Float bounceY = -(p2->y);		HX_STACK_VAR(bounceY,"bounceY");
		HX_STACK_LINE(626)
		Float frictionX = p1->x;		HX_STACK_VAR(frictionX,"frictionX");
		HX_STACK_LINE(627)
		Float frictionY = p1->y;		HX_STACK_VAR(frictionY,"frictionY");
		HX_STACK_LINE(628)
		this->set_x(((bounceX * bounceCoeff) + (frictionX * friction)));
		HX_STACK_LINE(629)
		this->set_y(((bounceY * bounceCoeff) + (frictionY * friction)));
		HX_STACK_LINE(630)
		return hx::ObjectPtr<OBJ_>(this);
	}
}


HX_DEFINE_DYNAMIC_FUNC3(FlxVector_obj,bounceWithFriction,return )

bool FlxVector_obj::isValid( ){
	HX_STACK_FRAME("flixel.util.FlxVector","isValid",0x08908a5f,"flixel.util.FlxVector.isValid","flixel/util/FlxVector.hx",639,0xa3e1b4e3)
	HX_STACK_THIS(this)
	HX_STACK_LINE(639)
	if (((  (((  ((!(::Math_obj::isNaN(this->x)))) ? bool(!(::Math_obj::isNaN(this->y))) : bool(false) ))) ? bool(::Math_obj::isFinite(this->x)) : bool(false) ))){
		HX_STACK_LINE(639)
		return ::Math_obj::isFinite(this->y);
	}
	else{
		HX_STACK_LINE(639)
		return false;
	}
	HX_STACK_LINE(639)
	return false;
}


HX_DEFINE_DYNAMIC_FUNC0(FlxVector_obj,isValid,return )

::flixel::util::FlxVector FlxVector_obj::clone( ::flixel::util::FlxVector vec){
	HX_STACK_FRAME("flixel.util.FlxVector","clone",0xedbbcfca,"flixel.util.FlxVector.clone","flixel/util/FlxVector.hx",648,0xa3e1b4e3)
	HX_STACK_THIS(this)
	HX_STACK_ARG(vec,"vec")
	HX_STACK_LINE(649)
	if (((vec == null()))){
		HX_STACK_LINE(651)
		vec = ::flixel::util::FlxVector_obj::__new(null(),null());
	}
	HX_STACK_LINE(654)
	vec->set_x(this->x);
	HX_STACK_LINE(655)
	vec->set_y(this->y);
	HX_STACK_LINE(657)
	return vec;
}


HX_DEFINE_DYNAMIC_FUNC1(FlxVector_obj,clone,return )

Float FlxVector_obj::EPSILON;

Float FlxVector_obj::EPSILON_SQUARED;

::flixel::util::FlxVector FlxVector_obj::_vector1;

::flixel::util::FlxVector FlxVector_obj::_vector2;

::flixel::util::FlxVector FlxVector_obj::_vector3;


FlxVector_obj::FlxVector_obj()
{
}

Dynamic FlxVector_obj::__Field(const ::String &inName,bool inCallProp)
{
	switch(inName.length) {
	case 2:
		if (HX_FIELD_EQ(inName,"dx") ) { return get_dx(); }
		if (HX_FIELD_EQ(inName,"dy") ) { return get_dy(); }
		if (HX_FIELD_EQ(inName,"rx") ) { return get_rx(); }
		if (HX_FIELD_EQ(inName,"ry") ) { return get_ry(); }
		if (HX_FIELD_EQ(inName,"lx") ) { return get_lx(); }
		if (HX_FIELD_EQ(inName,"ly") ) { return get_ly(); }
		break;
	case 3:
		if (HX_FIELD_EQ(inName,"set") ) { return set_dyn(); }
		if (HX_FIELD_EQ(inName,"add") ) { return add_dyn(); }
		break;
	case 4:
		if (HX_FIELD_EQ(inName,"zero") ) { return zero_dyn(); }
		if (HX_FIELD_EQ(inName,"sign") ) { return sign_dyn(); }
		if (HX_FIELD_EQ(inName,"dist") ) { return dist_dyn(); }
		break;
	case 5:
		if (HX_FIELD_EQ(inName,"scale") ) { return scale_dyn(); }
		if (HX_FIELD_EQ(inName,"ratio") ) { return ratio_dyn(); }
		if (HX_FIELD_EQ(inName,"clone") ) { return clone_dyn(); }
		break;
	case 6:
		if (HX_FIELD_EQ(inName,"addNew") ) { return addNew_dyn(); }
		if (HX_FIELD_EQ(inName,"isZero") ) { return isZero_dyn(); }
		if (HX_FIELD_EQ(inName,"get_dx") ) { return get_dx_dyn(); }
		if (HX_FIELD_EQ(inName,"get_dy") ) { return get_dy_dyn(); }
		if (HX_FIELD_EQ(inName,"equals") ) { return equals_dyn(); }
		if (HX_FIELD_EQ(inName,"length") ) { return get_length(); }
		if (HX_FIELD_EQ(inName,"get_rx") ) { return get_rx_dyn(); }
		if (HX_FIELD_EQ(inName,"get_ry") ) { return get_ry_dyn(); }
		if (HX_FIELD_EQ(inName,"get_lx") ) { return get_lx_dyn(); }
		if (HX_FIELD_EQ(inName,"get_ly") ) { return get_ly_dyn(); }
		if (HX_FIELD_EQ(inName,"negate") ) { return negate_dyn(); }
		if (HX_FIELD_EQ(inName,"bounce") ) { return bounce_dyn(); }
		break;
	case 7:
		if (HX_FIELD_EQ(inName,"degrees") ) { return get_degrees(); }
		if (HX_FIELD_EQ(inName,"radians") ) { return get_radians(); }
		if (HX_FIELD_EQ(inName,"isValid") ) { return isValid_dyn(); }
		break;
	case 8:
		if (HX_FIELD_EQ(inName,"_vector1") ) { return _vector1; }
		if (HX_FIELD_EQ(inName,"_vector2") ) { return _vector2; }
		if (HX_FIELD_EQ(inName,"_vector3") ) { return _vector3; }
		if (HX_FIELD_EQ(inName,"scaleNew") ) { return scaleNew_dyn(); }
		if (HX_FIELD_EQ(inName,"truncate") ) { return truncate_dyn(); }
		break;
	case 9:
		if (HX_FIELD_EQ(inName,"substract") ) { return substract_dyn(); }
		if (HX_FIELD_EQ(inName,"normalize") ) { return normalize_dyn(); }
		if (HX_FIELD_EQ(inName,"negateNew") ) { return negateNew_dyn(); }
		if (HX_FIELD_EQ(inName,"projectTo") ) { return projectTo_dyn(); }
		break;
	case 10:
		if (HX_FIELD_EQ(inName,"dotProduct") ) { return dotProduct_dyn(); }
		if (HX_FIELD_EQ(inName,"isParallel") ) { return isParallel_dyn(); }
		if (HX_FIELD_EQ(inName,"get_length") ) { return get_length_dyn(); }
		if (HX_FIELD_EQ(inName,"set_length") ) { return set_length_dyn(); }
		if (HX_FIELD_EQ(inName,"leftNormal") ) { return leftNormal_dyn(); }
		break;
	case 11:
		if (HX_FIELD_EQ(inName,"get_degrees") ) { return get_degrees_dyn(); }
		if (HX_FIELD_EQ(inName,"set_degrees") ) { return set_degrees_dyn(); }
		if (HX_FIELD_EQ(inName,"get_radians") ) { return get_radians_dyn(); }
		if (HX_FIELD_EQ(inName,"set_radians") ) { return set_radians_dyn(); }
		if (HX_FIELD_EQ(inName,"rightNormal") ) { return rightNormal_dyn(); }
		if (HX_FIELD_EQ(inName,"perpProduct") ) { return perpProduct_dyn(); }
		if (HX_FIELD_EQ(inName,"distSquared") ) { return distSquared_dyn(); }
		break;
	case 12:
		if (HX_FIELD_EQ(inName,"substractNew") ) { return substractNew_dyn(); }
		if (HX_FIELD_EQ(inName,"isNormalized") ) { return isNormalized_dyn(); }
		break;
	case 13:
		if (HX_FIELD_EQ(inName,"lengthSquared") ) { return get_lengthSquared(); }
		break;
	case 14:
		if (HX_FIELD_EQ(inName,"rotateWithTrig") ) { return rotateWithTrig_dyn(); }
		if (HX_FIELD_EQ(inName,"radiansBetween") ) { return radiansBetween_dyn(); }
		if (HX_FIELD_EQ(inName,"degreesBetween") ) { return degreesBetween_dyn(); }
		break;
	case 15:
		if (HX_FIELD_EQ(inName,"isPerpendicular") ) { return isPerpendicular_dyn(); }
		if (HX_FIELD_EQ(inName,"rotateByRadians") ) { return rotateByRadians_dyn(); }
		if (HX_FIELD_EQ(inName,"rotateByDegrees") ) { return rotateByDegrees_dyn(); }
		break;
	case 16:
		if (HX_FIELD_EQ(inName,"findIntersection") ) { return findIntersection_dyn(); }
		break;
	case 17:
		if (HX_FIELD_EQ(inName,"get_lengthSquared") ) { return get_lengthSquared_dyn(); }
		break;
	case 18:
		if (HX_FIELD_EQ(inName,"crossProductLength") ) { return crossProductLength_dyn(); }
		if (HX_FIELD_EQ(inName,"bounceWithFriction") ) { return bounceWithFriction_dyn(); }
		break;
	case 19:
		if (HX_FIELD_EQ(inName,"projectToNormalized") ) { return projectToNormalized_dyn(); }
		break;
	case 22:
		if (HX_FIELD_EQ(inName,"dotProdWithNormalizing") ) { return dotProdWithNormalizing_dyn(); }
		break;
	case 24:
		if (HX_FIELD_EQ(inName,"findIntersectionInBounds") ) { return findIntersectionInBounds_dyn(); }
	}
	return super::__Field(inName,inCallProp);
}

Dynamic FlxVector_obj::__SetField(const ::String &inName,const Dynamic &inValue,bool inCallProp)
{
	switch(inName.length) {
	case 6:
		if (HX_FIELD_EQ(inName,"length") ) { return set_length(inValue); }
		break;
	case 7:
		if (HX_FIELD_EQ(inName,"degrees") ) { return set_degrees(inValue); }
		if (HX_FIELD_EQ(inName,"radians") ) { return set_radians(inValue); }
		break;
	case 8:
		if (HX_FIELD_EQ(inName,"_vector1") ) { _vector1=inValue.Cast< ::flixel::util::FlxVector >(); return inValue; }
		if (HX_FIELD_EQ(inName,"_vector2") ) { _vector2=inValue.Cast< ::flixel::util::FlxVector >(); return inValue; }
		if (HX_FIELD_EQ(inName,"_vector3") ) { _vector3=inValue.Cast< ::flixel::util::FlxVector >(); return inValue; }
	}
	return super::__SetField(inName,inValue,inCallProp);
}

void FlxVector_obj::__GetFields(Array< ::String> &outFields)
{
	outFields->push(HX_CSTRING("dx"));
	outFields->push(HX_CSTRING("dy"));
	outFields->push(HX_CSTRING("length"));
	outFields->push(HX_CSTRING("lengthSquared"));
	outFields->push(HX_CSTRING("degrees"));
	outFields->push(HX_CSTRING("radians"));
	outFields->push(HX_CSTRING("rx"));
	outFields->push(HX_CSTRING("ry"));
	outFields->push(HX_CSTRING("lx"));
	outFields->push(HX_CSTRING("ly"));
	super::__GetFields(outFields);
};

static ::String sStaticFields[] = {
	HX_CSTRING("EPSILON"),
	HX_CSTRING("EPSILON_SQUARED"),
	HX_CSTRING("_vector1"),
	HX_CSTRING("_vector2"),
	HX_CSTRING("_vector3"),
	String(null()) };

#if HXCPP_SCRIPTABLE
static hx::StorageInfo *sMemberStorageInfo = 0;
#endif

static ::String sMemberFields[] = {
	HX_CSTRING("set"),
	HX_CSTRING("scale"),
	HX_CSTRING("scaleNew"),
	HX_CSTRING("add"),
	HX_CSTRING("addNew"),
	HX_CSTRING("substract"),
	HX_CSTRING("substractNew"),
	HX_CSTRING("dotProduct"),
	HX_CSTRING("dotProdWithNormalizing"),
	HX_CSTRING("isPerpendicular"),
	HX_CSTRING("crossProductLength"),
	HX_CSTRING("isParallel"),
	HX_CSTRING("isZero"),
	HX_CSTRING("zero"),
	HX_CSTRING("normalize"),
	HX_CSTRING("get_dx"),
	HX_CSTRING("get_dy"),
	HX_CSTRING("isNormalized"),
	HX_CSTRING("equals"),
	HX_CSTRING("get_length"),
	HX_CSTRING("set_length"),
	HX_CSTRING("get_lengthSquared"),
	HX_CSTRING("get_degrees"),
	HX_CSTRING("set_degrees"),
	HX_CSTRING("get_radians"),
	HX_CSTRING("set_radians"),
	HX_CSTRING("rotateByRadians"),
	HX_CSTRING("rotateByDegrees"),
	HX_CSTRING("rotateWithTrig"),
	HX_CSTRING("rightNormal"),
	HX_CSTRING("get_rx"),
	HX_CSTRING("get_ry"),
	HX_CSTRING("leftNormal"),
	HX_CSTRING("get_lx"),
	HX_CSTRING("get_ly"),
	HX_CSTRING("negate"),
	HX_CSTRING("negateNew"),
	HX_CSTRING("projectTo"),
	HX_CSTRING("projectToNormalized"),
	HX_CSTRING("perpProduct"),
	HX_CSTRING("ratio"),
	HX_CSTRING("findIntersection"),
	HX_CSTRING("findIntersectionInBounds"),
	HX_CSTRING("truncate"),
	HX_CSTRING("radiansBetween"),
	HX_CSTRING("degreesBetween"),
	HX_CSTRING("sign"),
	HX_CSTRING("dist"),
	HX_CSTRING("distSquared"),
	HX_CSTRING("bounce"),
	HX_CSTRING("bounceWithFriction"),
	HX_CSTRING("isValid"),
	HX_CSTRING("clone"),
	String(null()) };

static void sMarkStatics(HX_MARK_PARAMS) {
	HX_MARK_MEMBER_NAME(FlxVector_obj::__mClass,"__mClass");
	HX_MARK_MEMBER_NAME(FlxVector_obj::EPSILON,"EPSILON");
	HX_MARK_MEMBER_NAME(FlxVector_obj::EPSILON_SQUARED,"EPSILON_SQUARED");
	HX_MARK_MEMBER_NAME(FlxVector_obj::_vector1,"_vector1");
	HX_MARK_MEMBER_NAME(FlxVector_obj::_vector2,"_vector2");
	HX_MARK_MEMBER_NAME(FlxVector_obj::_vector3,"_vector3");
};

#ifdef HXCPP_VISIT_ALLOCS
static void sVisitStatics(HX_VISIT_PARAMS) {
	HX_VISIT_MEMBER_NAME(FlxVector_obj::__mClass,"__mClass");
	HX_VISIT_MEMBER_NAME(FlxVector_obj::EPSILON,"EPSILON");
	HX_VISIT_MEMBER_NAME(FlxVector_obj::EPSILON_SQUARED,"EPSILON_SQUARED");
	HX_VISIT_MEMBER_NAME(FlxVector_obj::_vector1,"_vector1");
	HX_VISIT_MEMBER_NAME(FlxVector_obj::_vector2,"_vector2");
	HX_VISIT_MEMBER_NAME(FlxVector_obj::_vector3,"_vector3");
};

#endif

Class FlxVector_obj::__mClass;

void FlxVector_obj::__register()
{
	hx::Static(__mClass) = hx::RegisterClass(HX_CSTRING("flixel.util.FlxVector"), hx::TCanCast< FlxVector_obj> ,sStaticFields,sMemberFields,
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

void FlxVector_obj::__boot()
{
	EPSILON= 0.0000001;
	EPSILON_SQUARED= 9.9999999999999984e-015;
	_vector1= ::flixel::util::FlxVector_obj::__new(null(),null());
	_vector2= ::flixel::util::FlxVector_obj::__new(null(),null());
	_vector3= ::flixel::util::FlxVector_obj::__new(null(),null());
}

} // end namespace flixel
} // end namespace util
