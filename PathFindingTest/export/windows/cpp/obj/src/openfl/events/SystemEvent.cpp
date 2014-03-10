#include <hxcpp.h>

#ifndef INCLUDED_Std
#include <Std.h>
#endif
#ifndef INCLUDED_flash_events_Event
#include <flash/events/Event.h>
#endif
#ifndef INCLUDED_openfl_events_SystemEvent
#include <openfl/events/SystemEvent.h>
#endif
namespace openfl{
namespace events{

Void SystemEvent_obj::__construct(::String type,hx::Null< bool >  __o_bubbles,hx::Null< bool >  __o_cancelable,hx::Null< int >  __o_data)
{
HX_STACK_FRAME("openfl.events.SystemEvent","new",0x11944ec6,"openfl.events.SystemEvent.new","openfl/events/SystemEvent.hx",15,0x6320158a)

HX_STACK_ARG(type,"type")

HX_STACK_ARG(__o_bubbles,"bubbles")

HX_STACK_ARG(__o_cancelable,"cancelable")

HX_STACK_ARG(__o_data,"data")
bool bubbles = __o_bubbles.Default(false);
bool cancelable = __o_cancelable.Default(false);
int data = __o_data.Default(0);
{
	HX_STACK_LINE(17)
	super::__construct(type,bubbles,cancelable);
	HX_STACK_LINE(18)
	this->data = data;
}
;
	return null();
}

//SystemEvent_obj::~SystemEvent_obj() { }

Dynamic SystemEvent_obj::__CreateEmpty() { return  new SystemEvent_obj; }
hx::ObjectPtr< SystemEvent_obj > SystemEvent_obj::__new(::String type,hx::Null< bool >  __o_bubbles,hx::Null< bool >  __o_cancelable,hx::Null< int >  __o_data)
{  hx::ObjectPtr< SystemEvent_obj > result = new SystemEvent_obj();
	result->__construct(type,__o_bubbles,__o_cancelable,__o_data);
	return result;}

Dynamic SystemEvent_obj::__Create(hx::DynamicArray inArgs)
{  hx::ObjectPtr< SystemEvent_obj > result = new SystemEvent_obj();
	result->__construct(inArgs[0],inArgs[1],inArgs[2],inArgs[3]);
	return result;}

::flash::events::Event SystemEvent_obj::clone( ){
	HX_STACK_FRAME("openfl.events.SystemEvent","clone",0x898c7743,"openfl.events.SystemEvent.clone","openfl/events/SystemEvent.hx",23,0x6320158a)
	HX_STACK_THIS(this)
	HX_STACK_LINE(25)
	::String _g = this->get_type();		HX_STACK_VAR(_g,"_g");
	HX_STACK_LINE(25)
	bool _g1 = this->get_bubbles();		HX_STACK_VAR(_g1,"_g1");
	HX_STACK_LINE(25)
	return ::openfl::events::SystemEvent_obj::__new(_g,_g1,this->get_cancelable(),this->data);
}


::String SystemEvent_obj::toString( ){
	HX_STACK_FRAME("openfl.events.SystemEvent","toString",0x5f0c6086,"openfl.events.SystemEvent.toString","openfl/events/SystemEvent.hx",30,0x6320158a)
	HX_STACK_THIS(this)
	HX_STACK_LINE(32)
	::String _g = ((HX_CSTRING("[SystemEvent type=") + this->get_type()) + HX_CSTRING(" bubbles="));		HX_STACK_VAR(_g,"_g");
	HX_STACK_LINE(32)
	::String _g1 = ((_g + ::Std_obj::string(this->get_bubbles())) + HX_CSTRING(" cancelable="));		HX_STACK_VAR(_g1,"_g1");
	HX_STACK_LINE(32)
	return ((((_g1 + ::Std_obj::string(this->get_cancelable())) + HX_CSTRING(" data=")) + this->data) + HX_CSTRING("]"));
}


::String SystemEvent_obj::SYSTEM;


SystemEvent_obj::SystemEvent_obj()
{
}

Dynamic SystemEvent_obj::__Field(const ::String &inName,bool inCallProp)
{
	switch(inName.length) {
	case 4:
		if (HX_FIELD_EQ(inName,"data") ) { return data; }
		break;
	case 5:
		if (HX_FIELD_EQ(inName,"clone") ) { return clone_dyn(); }
		break;
	case 6:
		if (HX_FIELD_EQ(inName,"SYSTEM") ) { return SYSTEM; }
		break;
	case 8:
		if (HX_FIELD_EQ(inName,"toString") ) { return toString_dyn(); }
	}
	return super::__Field(inName,inCallProp);
}

Dynamic SystemEvent_obj::__SetField(const ::String &inName,const Dynamic &inValue,bool inCallProp)
{
	switch(inName.length) {
	case 4:
		if (HX_FIELD_EQ(inName,"data") ) { data=inValue.Cast< int >(); return inValue; }
		break;
	case 6:
		if (HX_FIELD_EQ(inName,"SYSTEM") ) { SYSTEM=inValue.Cast< ::String >(); return inValue; }
	}
	return super::__SetField(inName,inValue,inCallProp);
}

void SystemEvent_obj::__GetFields(Array< ::String> &outFields)
{
	outFields->push(HX_CSTRING("data"));
	super::__GetFields(outFields);
};

static ::String sStaticFields[] = {
	HX_CSTRING("SYSTEM"),
	String(null()) };

#if HXCPP_SCRIPTABLE
static hx::StorageInfo sMemberStorageInfo[] = {
	{hx::fsInt,(int)offsetof(SystemEvent_obj,data),HX_CSTRING("data")},
	{ hx::fsUnknown, 0, null()}
};
#endif

static ::String sMemberFields[] = {
	HX_CSTRING("data"),
	HX_CSTRING("clone"),
	HX_CSTRING("toString"),
	String(null()) };

static void sMarkStatics(HX_MARK_PARAMS) {
	HX_MARK_MEMBER_NAME(SystemEvent_obj::__mClass,"__mClass");
	HX_MARK_MEMBER_NAME(SystemEvent_obj::SYSTEM,"SYSTEM");
};

#ifdef HXCPP_VISIT_ALLOCS
static void sVisitStatics(HX_VISIT_PARAMS) {
	HX_VISIT_MEMBER_NAME(SystemEvent_obj::__mClass,"__mClass");
	HX_VISIT_MEMBER_NAME(SystemEvent_obj::SYSTEM,"SYSTEM");
};

#endif

Class SystemEvent_obj::__mClass;

void SystemEvent_obj::__register()
{
	hx::Static(__mClass) = hx::RegisterClass(HX_CSTRING("openfl.events.SystemEvent"), hx::TCanCast< SystemEvent_obj> ,sStaticFields,sMemberFields,
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

void SystemEvent_obj::__boot()
{
	SYSTEM= HX_CSTRING("system");
}

} // end namespace openfl
} // end namespace events
