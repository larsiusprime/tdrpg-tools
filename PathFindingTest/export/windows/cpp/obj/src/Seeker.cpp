#include <hxcpp.h>

#ifndef INCLUDED_Seeker
#include <Seeker.h>
#endif
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
#ifndef INCLUDED_flixel_util_FlxPoint
#include <flixel/util/FlxPoint.h>
#endif
#ifndef INCLUDED_flixel_util_FlxVector
#include <flixel/util/FlxVector.h>
#endif
#ifndef INCLUDED_haxe_Log
#include <haxe/Log.h>
#endif

Void Seeker_obj::__construct(Float X,Float Y,Dynamic SimpleGraphic)
{
HX_STACK_FRAME("Seeker","new",0xa8382777,"Seeker.new","Seeker.hx",10,0x9849b3d9)

HX_STACK_ARG(X,"X")

HX_STACK_ARG(Y,"Y")

HX_STACK_ARG(SimpleGraphic,"SimpleGraphic")
{
	HX_STACK_LINE(13)
	this->moving = false;
	HX_STACK_LINE(20)
	super::__construct(X,Y,SimpleGraphic);
	HX_STACK_LINE(21)
	this->dest = ::flixel::util::FlxPoint_obj::__new(null(),null());
	HX_STACK_LINE(22)
	this->vec = ::flixel::util::FlxVector_obj::__new(null(),null());
}
;
	return null();
}

//Seeker_obj::~Seeker_obj() { }

Dynamic Seeker_obj::__CreateEmpty() { return  new Seeker_obj; }
hx::ObjectPtr< Seeker_obj > Seeker_obj::__new(Float X,Float Y,Dynamic SimpleGraphic)
{  hx::ObjectPtr< Seeker_obj > result = new Seeker_obj();
	result->__construct(X,Y,SimpleGraphic);
	return result;}

Dynamic Seeker_obj::__Create(hx::DynamicArray inArgs)
{  hx::ObjectPtr< Seeker_obj > result = new Seeker_obj();
	result->__construct(inArgs[0],inArgs[1],inArgs[2]);
	return result;}

Void Seeker_obj::moveTo( Float X,Float Y,Float Time){
{
		HX_STACK_FRAME("Seeker","moveTo",0xbc0cc435,"Seeker.moveTo","Seeker.hx",25,0x9849b3d9)
		HX_STACK_THIS(this)
		HX_STACK_ARG(X,"X")
		HX_STACK_ARG(Y,"Y")
		HX_STACK_ARG(Time,"Time")
		HX_STACK_LINE(26)
		::haxe::Log_obj::trace(((((HX_CSTRING("moveTo(") + X) + HX_CSTRING(",")) + Y) + HX_CSTRING(")")),hx::SourceInfo(HX_CSTRING("Seeker.hx"),26,HX_CSTRING("Seeker"),HX_CSTRING("moveTo")));
		HX_STACK_LINE(27)
		this->moving = true;
		HX_STACK_LINE(28)
		this->dest->set_x(X);
		HX_STACK_LINE(29)
		this->dest->set_y(Y);
		HX_STACK_LINE(30)
		this->vec->set_x((this->dest->x - this->x));
		HX_STACK_LINE(31)
		this->vec->set_y((this->dest->y - this->y));
		HX_STACK_LINE(33)
		this->velocity->set_x((Float(this->vec->x) / Float(Time)));
		HX_STACK_LINE(34)
		this->velocity->set_y((Float(this->vec->y) / Float(Time)));
		HX_STACK_LINE(36)
		this->vec->normalize();
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC3(Seeker_obj,moveTo,(void))

Void Seeker_obj::finishMoveTo( ){
{
		HX_STACK_FRAME("Seeker","finishMoveTo",0x9b2f95a8,"Seeker.finishMoveTo","Seeker.hx",39,0x9849b3d9)
		HX_STACK_THIS(this)
		HX_STACK_LINE(40)
		this->set_x(this->dest->x);
		HX_STACK_LINE(41)
		this->set_y(this->dest->y);
		HX_STACK_LINE(42)
		this->velocity->set_x((int)0);
		HX_STACK_LINE(43)
		this->velocity->set_y((int)0);
		HX_STACK_LINE(44)
		this->moving = false;
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC0(Seeker_obj,finishMoveTo,(void))

Void Seeker_obj::update( ){
{
		HX_STACK_FRAME("Seeker","update",0x76657752,"Seeker.update","Seeker.hx",47,0x9849b3d9)
		HX_STACK_THIS(this)
		HX_STACK_LINE(48)
		Float oldx = this->vec->x;		HX_STACK_VAR(oldx,"oldx");
		HX_STACK_LINE(49)
		Float oldy = this->vec->y;		HX_STACK_VAR(oldy,"oldy");
		HX_STACK_LINE(50)
		this->super::update();
		HX_STACK_LINE(51)
		this->vec->set_x((this->x - this->dest->x));
		HX_STACK_LINE(52)
		this->vec->set_y((this->y - this->dest->y));
		HX_STACK_LINE(53)
		int _g = this->signOf(oldx);		HX_STACK_VAR(_g,"_g");
		struct _Function_1_1{
			inline static bool Block( ::Seeker_obj *__this,Float &oldy){
				HX_STACK_FRAME("*","closure",0x5bdab937,"*.closure","Seeker.hx",53,0x9849b3d9)
				{
					HX_STACK_LINE(53)
					int _g1 = __this->signOf(oldy);		HX_STACK_VAR(_g1,"_g1");
					HX_STACK_LINE(53)
					return (_g1 != __this->signOf(__this->vec->y));
				}
				return null();
			}
		};
		HX_STACK_LINE(53)
		if (((  ((!(((_g != this->signOf(this->vec->x)))))) ? bool(_Function_1_1::Block(this,oldy)) : bool(true) ))){
			HX_STACK_LINE(54)
			this->finishMoveTo();
		}
	}
return null();
}


int Seeker_obj::signOf( Float f){
	HX_STACK_FRAME("Seeker","signOf",0xa3e60ffd,"Seeker.signOf","Seeker.hx",58,0x9849b3d9)
	HX_STACK_THIS(this)
	HX_STACK_ARG(f,"f")
	HX_STACK_LINE(59)
	if (((f < (int)0))){
		HX_STACK_LINE(60)
		return (int)-1;
	}
	HX_STACK_LINE(62)
	return (int)1;
}


HX_DEFINE_DYNAMIC_FUNC1(Seeker_obj,signOf,return )


Seeker_obj::Seeker_obj()
{
}

void Seeker_obj::__Mark(HX_MARK_PARAMS)
{
	HX_MARK_BEGIN_CLASS(Seeker);
	HX_MARK_MEMBER_NAME(moving,"moving");
	HX_MARK_MEMBER_NAME(dest,"dest");
	HX_MARK_MEMBER_NAME(vec,"vec");
	::flixel::FlxSprite_obj::__Mark(HX_MARK_ARG);
	HX_MARK_END_CLASS();
}

void Seeker_obj::__Visit(HX_VISIT_PARAMS)
{
	HX_VISIT_MEMBER_NAME(moving,"moving");
	HX_VISIT_MEMBER_NAME(dest,"dest");
	HX_VISIT_MEMBER_NAME(vec,"vec");
	::flixel::FlxSprite_obj::__Visit(HX_VISIT_ARG);
}

Dynamic Seeker_obj::__Field(const ::String &inName,bool inCallProp)
{
	switch(inName.length) {
	case 3:
		if (HX_FIELD_EQ(inName,"vec") ) { return vec; }
		break;
	case 4:
		if (HX_FIELD_EQ(inName,"dest") ) { return dest; }
		break;
	case 6:
		if (HX_FIELD_EQ(inName,"moving") ) { return moving; }
		if (HX_FIELD_EQ(inName,"moveTo") ) { return moveTo_dyn(); }
		if (HX_FIELD_EQ(inName,"update") ) { return update_dyn(); }
		if (HX_FIELD_EQ(inName,"signOf") ) { return signOf_dyn(); }
		break;
	case 12:
		if (HX_FIELD_EQ(inName,"finishMoveTo") ) { return finishMoveTo_dyn(); }
	}
	return super::__Field(inName,inCallProp);
}

Dynamic Seeker_obj::__SetField(const ::String &inName,const Dynamic &inValue,bool inCallProp)
{
	switch(inName.length) {
	case 3:
		if (HX_FIELD_EQ(inName,"vec") ) { vec=inValue.Cast< ::flixel::util::FlxVector >(); return inValue; }
		break;
	case 4:
		if (HX_FIELD_EQ(inName,"dest") ) { dest=inValue.Cast< ::flixel::util::FlxPoint >(); return inValue; }
		break;
	case 6:
		if (HX_FIELD_EQ(inName,"moving") ) { moving=inValue.Cast< bool >(); return inValue; }
	}
	return super::__SetField(inName,inValue,inCallProp);
}

void Seeker_obj::__GetFields(Array< ::String> &outFields)
{
	outFields->push(HX_CSTRING("moving"));
	outFields->push(HX_CSTRING("dest"));
	outFields->push(HX_CSTRING("vec"));
	super::__GetFields(outFields);
};

static ::String sStaticFields[] = {
	String(null()) };

#if HXCPP_SCRIPTABLE
static hx::StorageInfo sMemberStorageInfo[] = {
	{hx::fsBool,(int)offsetof(Seeker_obj,moving),HX_CSTRING("moving")},
	{hx::fsObject /*::flixel::util::FlxPoint*/ ,(int)offsetof(Seeker_obj,dest),HX_CSTRING("dest")},
	{hx::fsObject /*::flixel::util::FlxVector*/ ,(int)offsetof(Seeker_obj,vec),HX_CSTRING("vec")},
	{ hx::fsUnknown, 0, null()}
};
#endif

static ::String sMemberFields[] = {
	HX_CSTRING("moving"),
	HX_CSTRING("dest"),
	HX_CSTRING("vec"),
	HX_CSTRING("moveTo"),
	HX_CSTRING("finishMoveTo"),
	HX_CSTRING("update"),
	HX_CSTRING("signOf"),
	String(null()) };

static void sMarkStatics(HX_MARK_PARAMS) {
	HX_MARK_MEMBER_NAME(Seeker_obj::__mClass,"__mClass");
};

#ifdef HXCPP_VISIT_ALLOCS
static void sVisitStatics(HX_VISIT_PARAMS) {
	HX_VISIT_MEMBER_NAME(Seeker_obj::__mClass,"__mClass");
};

#endif

Class Seeker_obj::__mClass;

void Seeker_obj::__register()
{
	hx::Static(__mClass) = hx::RegisterClass(HX_CSTRING("Seeker"), hx::TCanCast< Seeker_obj> ,sStaticFields,sMemberFields,
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

void Seeker_obj::__boot()
{
}

