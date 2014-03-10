#include <hxcpp.h>

#ifndef INCLUDED_flixel_util_FlxArrayUtil
#include <flixel/util/FlxArrayUtil.h>
#endif
#ifndef INCLUDED_flixel_util_FlxPool_flixel_util_FlxTimer
#include <flixel/util/FlxPool_flixel_util_FlxTimer.h>
#endif
#ifndef INCLUDED_flixel_util_FlxTimer
#include <flixel/util/FlxTimer.h>
#endif
namespace flixel{
namespace util{

Void FlxPool_flixel_util_FlxTimer_obj::__construct()
{
HX_STACK_FRAME("flixel.util.FlxPool_flixel_util_FlxTimer","new",0xa9be4fea,"flixel.util.FlxPool_flixel_util_FlxTimer.new","flixel/util/FlxPool.hx",14,0xdd4de86a)
{
	HX_STACK_LINE(14)
	this->_pool = Array_obj< ::Dynamic >::__new();
}
;
	return null();
}

//FlxPool_flixel_util_FlxTimer_obj::~FlxPool_flixel_util_FlxTimer_obj() { }

Dynamic FlxPool_flixel_util_FlxTimer_obj::__CreateEmpty() { return  new FlxPool_flixel_util_FlxTimer_obj; }
hx::ObjectPtr< FlxPool_flixel_util_FlxTimer_obj > FlxPool_flixel_util_FlxTimer_obj::__new()
{  hx::ObjectPtr< FlxPool_flixel_util_FlxTimer_obj > result = new FlxPool_flixel_util_FlxTimer_obj();
	result->__construct();
	return result;}

Dynamic FlxPool_flixel_util_FlxTimer_obj::__Create(hx::DynamicArray inArgs)
{  hx::ObjectPtr< FlxPool_flixel_util_FlxTimer_obj > result = new FlxPool_flixel_util_FlxTimer_obj();
	result->__construct();
	return result;}

::flixel::util::FlxTimer FlxPool_flixel_util_FlxTimer_obj::get( ){
	HX_STACK_FRAME("flixel.util.FlxPool_flixel_util_FlxTimer","get",0xa9b90020,"flixel.util.FlxPool_flixel_util_FlxTimer.get","flixel/util/FlxPool.hx",18,0xdd4de86a)
	HX_STACK_THIS(this)
	HX_STACK_LINE(19)
	::flixel::util::FlxTimer obj = this->_pool->pop().StaticCast< ::flixel::util::FlxTimer >();		HX_STACK_VAR(obj,"obj");
	HX_STACK_LINE(20)
	if (((obj == null()))){
		HX_STACK_LINE(20)
		obj = ::flixel::util::FlxTimer_obj::__new();
	}
	HX_STACK_LINE(21)
	return obj;
}


HX_DEFINE_DYNAMIC_FUNC0(FlxPool_flixel_util_FlxTimer_obj,get,return )

Void FlxPool_flixel_util_FlxTimer_obj::put( ::flixel::util::FlxTimer obj){
{
		HX_STACK_FRAME("flixel.util.FlxPool_flixel_util_FlxTimer","put",0xa9bfe259,"flixel.util.FlxPool_flixel_util_FlxTimer.put","flixel/util/FlxPool.hx",27,0xdd4de86a)
		HX_STACK_THIS(this)
		HX_STACK_ARG(obj,"obj")
		HX_STACK_LINE(27)
		if (((  (((obj != null()))) ? bool((::flixel::util::FlxArrayUtil_obj::indexOf_flixel_util_FlxPool_T(this->_pool,obj,null()) < (int)0)) : bool(false) ))){
			HX_STACK_LINE(29)
			obj->destroy();
			HX_STACK_LINE(30)
			this->_pool->push(obj);
		}
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC1(FlxPool_flixel_util_FlxTimer_obj,put,(void))

Void FlxPool_flixel_util_FlxTimer_obj::putUnsafe( ::flixel::util::FlxTimer obj){
{
		HX_STACK_FRAME("flixel.util.FlxPool_flixel_util_FlxTimer","putUnsafe",0x0982a35f,"flixel.util.FlxPool_flixel_util_FlxTimer.putUnsafe","flixel/util/FlxPool.hx",36,0xdd4de86a)
		HX_STACK_THIS(this)
		HX_STACK_ARG(obj,"obj")
		HX_STACK_LINE(36)
		if (((obj != null()))){
			HX_STACK_LINE(38)
			obj->destroy();
			HX_STACK_LINE(39)
			this->_pool->push(obj);
		}
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC1(FlxPool_flixel_util_FlxTimer_obj,putUnsafe,(void))

Array< ::Dynamic > FlxPool_flixel_util_FlxTimer_obj::clear( ){
	HX_STACK_FRAME("flixel.util.FlxPool_flixel_util_FlxTimer","clear",0x010c6797,"flixel.util.FlxPool_flixel_util_FlxTimer.clear","flixel/util/FlxPool.hx",44,0xdd4de86a)
	HX_STACK_THIS(this)
	HX_STACK_LINE(45)
	Array< ::Dynamic > oldPool = this->_pool;		HX_STACK_VAR(oldPool,"oldPool");
	HX_STACK_LINE(46)
	this->_pool = Array_obj< ::Dynamic >::__new();
	HX_STACK_LINE(47)
	return oldPool;
}


HX_DEFINE_DYNAMIC_FUNC0(FlxPool_flixel_util_FlxTimer_obj,clear,return )

int FlxPool_flixel_util_FlxTimer_obj::get_length( ){
	HX_STACK_FRAME("flixel.util.FlxPool_flixel_util_FlxTimer","get_length",0x2333ea65,"flixel.util.FlxPool_flixel_util_FlxTimer.get_length","flixel/util/FlxPool.hx",52,0xdd4de86a)
	HX_STACK_THIS(this)
	HX_STACK_LINE(52)
	return this->_pool->length;
}


HX_DEFINE_DYNAMIC_FUNC0(FlxPool_flixel_util_FlxTimer_obj,get_length,return )


FlxPool_flixel_util_FlxTimer_obj::FlxPool_flixel_util_FlxTimer_obj()
{
}

void FlxPool_flixel_util_FlxTimer_obj::__Mark(HX_MARK_PARAMS)
{
	HX_MARK_BEGIN_CLASS(FlxPool_flixel_util_FlxTimer);
	HX_MARK_MEMBER_NAME(_pool,"_pool");
	HX_MARK_END_CLASS();
}

void FlxPool_flixel_util_FlxTimer_obj::__Visit(HX_VISIT_PARAMS)
{
	HX_VISIT_MEMBER_NAME(_pool,"_pool");
}

Dynamic FlxPool_flixel_util_FlxTimer_obj::__Field(const ::String &inName,bool inCallProp)
{
	switch(inName.length) {
	case 3:
		if (HX_FIELD_EQ(inName,"get") ) { return get_dyn(); }
		if (HX_FIELD_EQ(inName,"put") ) { return put_dyn(); }
		break;
	case 5:
		if (HX_FIELD_EQ(inName,"_pool") ) { return _pool; }
		if (HX_FIELD_EQ(inName,"clear") ) { return clear_dyn(); }
		break;
	case 6:
		if (HX_FIELD_EQ(inName,"length") ) { return get_length(); }
		break;
	case 9:
		if (HX_FIELD_EQ(inName,"putUnsafe") ) { return putUnsafe_dyn(); }
		break;
	case 10:
		if (HX_FIELD_EQ(inName,"get_length") ) { return get_length_dyn(); }
	}
	return super::__Field(inName,inCallProp);
}

Dynamic FlxPool_flixel_util_FlxTimer_obj::__SetField(const ::String &inName,const Dynamic &inValue,bool inCallProp)
{
	switch(inName.length) {
	case 5:
		if (HX_FIELD_EQ(inName,"_pool") ) { _pool=inValue.Cast< Array< ::Dynamic > >(); return inValue; }
	}
	return super::__SetField(inName,inValue,inCallProp);
}

void FlxPool_flixel_util_FlxTimer_obj::__GetFields(Array< ::String> &outFields)
{
	outFields->push(HX_CSTRING("_pool"));
	outFields->push(HX_CSTRING("length"));
	super::__GetFields(outFields);
};

static ::String sStaticFields[] = {
	String(null()) };

#if HXCPP_SCRIPTABLE
static hx::StorageInfo sMemberStorageInfo[] = {
	{hx::fsObject /*Array< ::Dynamic >*/ ,(int)offsetof(FlxPool_flixel_util_FlxTimer_obj,_pool),HX_CSTRING("_pool")},
	{ hx::fsUnknown, 0, null()}
};
#endif

static ::String sMemberFields[] = {
	HX_CSTRING("_pool"),
	HX_CSTRING("get"),
	HX_CSTRING("put"),
	HX_CSTRING("putUnsafe"),
	HX_CSTRING("clear"),
	HX_CSTRING("get_length"),
	String(null()) };

static void sMarkStatics(HX_MARK_PARAMS) {
	HX_MARK_MEMBER_NAME(FlxPool_flixel_util_FlxTimer_obj::__mClass,"__mClass");
};

#ifdef HXCPP_VISIT_ALLOCS
static void sVisitStatics(HX_VISIT_PARAMS) {
	HX_VISIT_MEMBER_NAME(FlxPool_flixel_util_FlxTimer_obj::__mClass,"__mClass");
};

#endif

Class FlxPool_flixel_util_FlxTimer_obj::__mClass;

void FlxPool_flixel_util_FlxTimer_obj::__register()
{
	hx::Static(__mClass) = hx::RegisterClass(HX_CSTRING("flixel.util.FlxPool_flixel_util_FlxTimer"), hx::TCanCast< FlxPool_flixel_util_FlxTimer_obj> ,sStaticFields,sMemberFields,
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

void FlxPool_flixel_util_FlxTimer_obj::__boot()
{
}

} // end namespace flixel
} // end namespace util
