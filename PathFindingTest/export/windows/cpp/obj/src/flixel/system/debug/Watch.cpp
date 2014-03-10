#include <hxcpp.h>

#ifndef INCLUDED_IMap
#include <IMap.h>
#endif
#ifndef INCLUDED_Std
#include <Std.h>
#endif
#ifndef INCLUDED_flash_display_BitmapData
#include <flash/display/BitmapData.h>
#endif
#ifndef INCLUDED_flash_display_DisplayObject
#include <flash/display/DisplayObject.h>
#endif
#ifndef INCLUDED_flash_display_DisplayObjectContainer
#include <flash/display/DisplayObjectContainer.h>
#endif
#ifndef INCLUDED_flash_display_IBitmapDrawable
#include <flash/display/IBitmapDrawable.h>
#endif
#ifndef INCLUDED_flash_display_InteractiveObject
#include <flash/display/InteractiveObject.h>
#endif
#ifndef INCLUDED_flash_display_Sprite
#include <flash/display/Sprite.h>
#endif
#ifndef INCLUDED_flash_events_EventDispatcher
#include <flash/events/EventDispatcher.h>
#endif
#ifndef INCLUDED_flash_events_IEventDispatcher
#include <flash/events/IEventDispatcher.h>
#endif
#ifndef INCLUDED_flash_geom_Rectangle
#include <flash/geom/Rectangle.h>
#endif
#ifndef INCLUDED_flash_text_TextField
#include <flash/text/TextField.h>
#endif
#ifndef INCLUDED_flixel_system_debug_GraphicWatch
#include <flixel/system/debug/GraphicWatch.h>
#endif
#ifndef INCLUDED_flixel_system_debug_Watch
#include <flixel/system/debug/Watch.h>
#endif
#ifndef INCLUDED_flixel_system_debug_WatchEntry
#include <flixel/system/debug/WatchEntry.h>
#endif
#ifndef INCLUDED_flixel_system_debug_Window
#include <flixel/system/debug/Window.h>
#endif
#ifndef INCLUDED_flixel_util_FlxArrayUtil
#include <flixel/util/FlxArrayUtil.h>
#endif
#ifndef INCLUDED_haxe_ds_StringMap
#include <haxe/ds/StringMap.h>
#endif
namespace flixel{
namespace system{
namespace debug{

Void Watch_obj::__construct()
{
HX_STACK_FRAME("flixel.system.debug.Watch","new",0x42e63119,"flixel.system.debug.Watch.new","flixel/system/debug/Watch.hx",36,0x3c078798)
{
	HX_STACK_LINE(37)
	super::__construct(HX_CSTRING("watch"),::flixel::system::debug::GraphicWatch_obj::__new((int)0,(int)0,null(),null()),null(),null(),null(),null(),null());
	HX_STACK_LINE(39)
	this->_names = ::flash::display::Sprite_obj::__new();
	HX_STACK_LINE(40)
	this->_names->set_x((int)2);
	HX_STACK_LINE(41)
	this->_names->set_y((int)15);
	HX_STACK_LINE(42)
	this->addChild(this->_names);
	HX_STACK_LINE(44)
	this->_values = ::flash::display::Sprite_obj::__new();
	HX_STACK_LINE(45)
	this->_values->set_x((int)2);
	HX_STACK_LINE(46)
	this->_values->set_y((int)15);
	HX_STACK_LINE(47)
	this->addChild(this->_values);
	HX_STACK_LINE(49)
	this->_watching = Array_obj< ::Dynamic >::__new();
	HX_STACK_LINE(50)
	this->_quickWatchList = ::haxe::ds::StringMap_obj::__new();
	HX_STACK_LINE(52)
	this->editing = false;
	HX_STACK_LINE(54)
	this->removeAll();
}
;
	return null();
}

//Watch_obj::~Watch_obj() { }

Dynamic Watch_obj::__CreateEmpty() { return  new Watch_obj; }
hx::ObjectPtr< Watch_obj > Watch_obj::__new()
{  hx::ObjectPtr< Watch_obj > result = new Watch_obj();
	result->__construct();
	return result;}

Dynamic Watch_obj::__Create(hx::DynamicArray inArgs)
{  hx::ObjectPtr< Watch_obj > result = new Watch_obj();
	result->__construct();
	return result;}

Void Watch_obj::destroy( ){
{
		HX_STACK_FRAME("flixel.system.debug.Watch","destroy",0x14e9de33,"flixel.system.debug.Watch.destroy","flixel/system/debug/Watch.hx",61,0x3c078798)
		HX_STACK_THIS(this)
		HX_STACK_LINE(62)
		if (((this->_names != null()))){
			HX_STACK_LINE(64)
			this->removeChild(this->_names);
		}
		HX_STACK_LINE(66)
		this->_names = null();
		HX_STACK_LINE(67)
		if (((this->_values != null()))){
			HX_STACK_LINE(69)
			this->removeChild(this->_values);
		}
		HX_STACK_LINE(71)
		this->_values = null();
		HX_STACK_LINE(72)
		if (((this->_watching != null()))){
			HX_STACK_LINE(74)
			{
				HX_STACK_LINE(74)
				int _g = (int)0;		HX_STACK_VAR(_g,"_g");
				HX_STACK_LINE(74)
				Array< ::Dynamic > _g1 = this->_watching;		HX_STACK_VAR(_g1,"_g1");
				HX_STACK_LINE(74)
				while(((_g < _g1->length))){
					HX_STACK_LINE(74)
					::flixel::system::debug::WatchEntry watchEntry = _g1->__get(_g).StaticCast< ::flixel::system::debug::WatchEntry >();		HX_STACK_VAR(watchEntry,"watchEntry");
					HX_STACK_LINE(74)
					++(_g);
					HX_STACK_LINE(76)
					watchEntry->destroy();
				}
			}
			HX_STACK_LINE(78)
			this->_watching = null();
		}
		HX_STACK_LINE(80)
		this->_quickWatchList = null();
		HX_STACK_LINE(82)
		this->super::destroy();
	}
return null();
}


Void Watch_obj::add( Dynamic AnyObject,::String VariableName,::String DisplayName){
{
		HX_STACK_FRAME("flixel.system.debug.Watch","add",0x42dc52da,"flixel.system.debug.Watch.add","flixel/system/debug/Watch.hx",94,0x3c078798)
		HX_STACK_THIS(this)
		HX_STACK_ARG(AnyObject,"AnyObject")
		HX_STACK_ARG(VariableName,"VariableName")
		HX_STACK_ARG(DisplayName,"DisplayName")
		HX_STACK_LINE(96)
		::flixel::system::debug::WatchEntry watchEntry;		HX_STACK_VAR(watchEntry,"watchEntry");
		HX_STACK_LINE(97)
		int i = (int)0;		HX_STACK_VAR(i,"i");
		HX_STACK_LINE(98)
		int l = this->_watching->length;		HX_STACK_VAR(l,"l");
		HX_STACK_LINE(99)
		while(((i < l))){
			HX_STACK_LINE(101)
			watchEntry = this->_watching->__get((i)++).StaticCast< ::flixel::system::debug::WatchEntry >();
			HX_STACK_LINE(102)
			if (((bool((watchEntry->object == AnyObject)) && bool((watchEntry->field == VariableName))))){
				HX_STACK_LINE(104)
				return null();
			}
		}
		HX_STACK_LINE(109)
		watchEntry = ::flixel::system::debug::WatchEntry_obj::__new((this->_watching->length * (int)15),(Float(this->_width) / Float((int)2)),((Float(this->_width) / Float((int)2)) - (int)10),AnyObject,VariableName,DisplayName);
		HX_STACK_LINE(111)
		if (((watchEntry->field == null()))){
			HX_STACK_LINE(113)
			watchEntry->destroy();
			HX_STACK_LINE(114)
			watchEntry = null();
			HX_STACK_LINE(115)
			return null();
		}
		HX_STACK_LINE(118)
		this->_names->addChild(watchEntry->nameDisplay);
		HX_STACK_LINE(119)
		this->_values->addChild(watchEntry->valueDisplay);
		HX_STACK_LINE(120)
		this->_watching->push(watchEntry);
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC3(Watch_obj,add,(void))

Void Watch_obj::updateQuickWatch( ::String Name,Dynamic NewValue){
{
		HX_STACK_FRAME("flixel.system.debug.Watch","updateQuickWatch",0xf6d27332,"flixel.system.debug.Watch.updateQuickWatch","flixel/system/debug/Watch.hx",132,0x3c078798)
		HX_STACK_THIS(this)
		HX_STACK_ARG(Name,"Name")
		HX_STACK_ARG(NewValue,"NewValue")
		HX_STACK_LINE(134)
		if (((this->_quickWatchList->get(Name) == null()))){
			HX_STACK_LINE(136)
			::flixel::system::debug::WatchEntry quickWatch = ::flixel::system::debug::WatchEntry_obj::__new((this->_watching->length * (int)15),(Float(this->_width) / Float((int)2)),((Float(this->_width) / Float((int)2)) - (int)10),null(),null(),Name);		HX_STACK_VAR(quickWatch,"quickWatch");
			HX_STACK_LINE(137)
			this->_names->addChild(quickWatch->nameDisplay);
			HX_STACK_LINE(138)
			this->_values->addChild(quickWatch->valueDisplay);
			HX_STACK_LINE(139)
			this->_watching->push(quickWatch);
			HX_STACK_LINE(140)
			this->_quickWatchList->set(Name,quickWatch);
		}
		HX_STACK_LINE(144)
		::flixel::system::debug::WatchEntry quickWatch = this->_quickWatchList->get(Name);		HX_STACK_VAR(quickWatch,"quickWatch");
		HX_STACK_LINE(146)
		if (((quickWatch != null()))){
			HX_STACK_LINE(148)
			quickWatch->valueDisplay->set_text(::Std_obj::string(NewValue));
		}
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC2(Watch_obj,updateQuickWatch,(void))

Void Watch_obj::remove( Dynamic AnyObject,::String VariableName,::String QuickWatchName){
{
		HX_STACK_FRAME("flixel.system.debug.Watch","remove",0x17fab52b,"flixel.system.debug.Watch.remove","flixel/system/debug/Watch.hx",160,0x3c078798)
		HX_STACK_THIS(this)
		HX_STACK_ARG(AnyObject,"AnyObject")
		HX_STACK_ARG(VariableName,"VariableName")
		HX_STACK_ARG(QuickWatchName,"QuickWatchName")
		HX_STACK_LINE(162)
		if (((bool((bool((AnyObject == null())) && bool((VariableName == null())))) && bool((QuickWatchName != null()))))){
			HX_STACK_LINE(164)
			::flixel::system::debug::WatchEntry quickWatch = this->_quickWatchList->get(QuickWatchName);		HX_STACK_VAR(quickWatch,"quickWatch");
			HX_STACK_LINE(166)
			if (((quickWatch != null()))){
				HX_STACK_LINE(167)
				this->removeEntry(quickWatch,::flixel::util::FlxArrayUtil_obj::indexOf_flixel_system_debug_WatchEntry(this->_watching,quickWatch,null()));
			}
			HX_STACK_LINE(168)
			this->_quickWatchList->remove(QuickWatchName);
			HX_STACK_LINE(171)
			return null();
		}
		HX_STACK_LINE(175)
		::flixel::system::debug::WatchEntry watchEntry;		HX_STACK_VAR(watchEntry,"watchEntry");
		HX_STACK_LINE(177)
		int i = (this->_watching->length - (int)1);		HX_STACK_VAR(i,"i");
		HX_STACK_LINE(178)
		while(((i >= (int)0))){
			HX_STACK_LINE(180)
			watchEntry = this->_watching->__get(i).StaticCast< ::flixel::system::debug::WatchEntry >();
			HX_STACK_LINE(182)
			if (((bool((watchEntry->object == AnyObject)) && bool(((bool((VariableName == null())) || bool((watchEntry->field == VariableName)))))))){
				HX_STACK_LINE(184)
				this->removeEntry(watchEntry,i);
			}
			HX_STACK_LINE(187)
			(i)--;
		}
		HX_STACK_LINE(189)
		watchEntry = null();
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC3(Watch_obj,remove,(void))

Void Watch_obj::removeEntry( ::flixel::system::debug::WatchEntry Entry,int Index){
{
		HX_STACK_FRAME("flixel.system.debug.Watch","removeEntry",0x8b219747,"flixel.system.debug.Watch.removeEntry","flixel/system/debug/Watch.hx",196,0x3c078798)
		HX_STACK_THIS(this)
		HX_STACK_ARG(Entry,"Entry")
		HX_STACK_ARG(Index,"Index")
		HX_STACK_LINE(197)
		::flixel::util::FlxArrayUtil_obj::fastSplice_flixel_system_debug_WatchEntry(this->_watching,Entry);
		HX_STACK_LINE(199)
		this->_names->removeChild(Entry->nameDisplay);
		HX_STACK_LINE(200)
		this->_values->removeChild(Entry->valueDisplay);
		HX_STACK_LINE(201)
		Entry->destroy();
		HX_STACK_LINE(204)
		int i = (int)0;		HX_STACK_VAR(i,"i");
		HX_STACK_LINE(205)
		int l = this->_watching->length;		HX_STACK_VAR(l,"l");
		HX_STACK_LINE(206)
		while(((i < l))){
			HX_STACK_LINE(208)
			this->_watching->__get(i).StaticCast< ::flixel::system::debug::WatchEntry >()->setY((i * (int)15));
			HX_STACK_LINE(209)
			(i)++;
		}
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC2(Watch_obj,removeEntry,(void))

Void Watch_obj::removeAll( ){
{
		HX_STACK_FRAME("flixel.system.debug.Watch","removeAll",0x608248b6,"flixel.system.debug.Watch.removeAll","flixel/system/debug/Watch.hx",217,0x3c078798)
		HX_STACK_THIS(this)
		HX_STACK_LINE(218)
		::flixel::system::debug::WatchEntry watchEntry;		HX_STACK_VAR(watchEntry,"watchEntry");
		HX_STACK_LINE(219)
		int i = (int)0;		HX_STACK_VAR(i,"i");
		HX_STACK_LINE(220)
		int l = this->_watching->length;		HX_STACK_VAR(l,"l");
		HX_STACK_LINE(221)
		while(((i < l))){
			HX_STACK_LINE(223)
			watchEntry = this->_watching->pop().StaticCast< ::flixel::system::debug::WatchEntry >();
			HX_STACK_LINE(224)
			this->_names->removeChild(watchEntry->nameDisplay);
			HX_STACK_LINE(225)
			this->_values->removeChild(watchEntry->valueDisplay);
			HX_STACK_LINE(226)
			watchEntry->destroy();
			HX_STACK_LINE(227)
			(i)++;
		}
		HX_STACK_LINE(229)
		this->_watching = Array_obj< ::Dynamic >::__new();
		HX_STACK_LINE(230)
		this->_quickWatchList = ::haxe::ds::StringMap_obj::__new();
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC0(Watch_obj,removeAll,(void))

Void Watch_obj::update( ){
{
		HX_STACK_FRAME("flixel.system.debug.Watch","update",0x9a779ef0,"flixel.system.debug.Watch.update","flixel/system/debug/Watch.hx",237,0x3c078798)
		HX_STACK_THIS(this)
		HX_STACK_LINE(239)
		this->editing = false;
		HX_STACK_LINE(240)
		int i = (int)0;		HX_STACK_VAR(i,"i");
		HX_STACK_LINE(241)
		int l = this->_watching->length;		HX_STACK_VAR(l,"l");
		HX_STACK_LINE(242)
		while(((i < l))){
			HX_STACK_LINE(244)
			if ((!(this->_watching->__get((i)++).StaticCast< ::flixel::system::debug::WatchEntry >()->updateValue()))){
				HX_STACK_LINE(246)
				this->editing = true;
			}
		}
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC0(Watch_obj,update,(void))

Void Watch_obj::submit( ){
{
		HX_STACK_FRAME("flixel.system.debug.Watch","submit",0xad7870ff,"flixel.system.debug.Watch.submit","flixel/system/debug/Watch.hx",256,0x3c078798)
		HX_STACK_THIS(this)
		HX_STACK_LINE(257)
		int i = (int)0;		HX_STACK_VAR(i,"i");
		HX_STACK_LINE(258)
		int l = this->_watching->length;		HX_STACK_VAR(l,"l");
		HX_STACK_LINE(259)
		::flixel::system::debug::WatchEntry watchEntry;		HX_STACK_VAR(watchEntry,"watchEntry");
		HX_STACK_LINE(260)
		while(((i < l))){
			HX_STACK_LINE(262)
			watchEntry = this->_watching->__get((i)++).StaticCast< ::flixel::system::debug::WatchEntry >();
			HX_STACK_LINE(263)
			if ((watchEntry->editing)){
				HX_STACK_LINE(265)
				watchEntry->submit();
			}
		}
		HX_STACK_LINE(268)
		this->editing = false;
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC0(Watch_obj,submit,(void))

Void Watch_obj::updateSize( ){
{
		HX_STACK_FRAME("flixel.system.debug.Watch","updateSize",0x58f6a3d1,"flixel.system.debug.Watch.updateSize","flixel/system/debug/Watch.hx",276,0x3c078798)
		HX_STACK_THIS(this)
		HX_STACK_LINE(277)
		if (((::Std_obj::_int(this->_height) < ((this->_watching->length * (int)15) + (int)17)))){
			HX_STACK_LINE(279)
			this->_height = ((this->_watching->length * (int)15) + (int)17);
		}
		HX_STACK_LINE(282)
		this->super::updateSize();
		HX_STACK_LINE(284)
		this->_values->set_x(((Float(this->_width) / Float((int)2)) + (int)2));
		HX_STACK_LINE(286)
		int i = (int)0;		HX_STACK_VAR(i,"i");
		HX_STACK_LINE(287)
		int l = this->_watching->length;		HX_STACK_VAR(l,"l");
		HX_STACK_LINE(288)
		while(((i < l))){
			HX_STACK_LINE(290)
			this->_watching->__get((i)++).StaticCast< ::flixel::system::debug::WatchEntry >()->updateWidth((Float(this->_width) / Float((int)2)),((Float(this->_width) / Float((int)2)) - (int)10));
		}
	}
return null();
}


int Watch_obj::MAX_LOG_LINES;

int Watch_obj::LINE_HEIGHT;


Watch_obj::Watch_obj()
{
}

void Watch_obj::__Mark(HX_MARK_PARAMS)
{
	HX_MARK_BEGIN_CLASS(Watch);
	HX_MARK_MEMBER_NAME(editing,"editing");
	HX_MARK_MEMBER_NAME(_names,"_names");
	HX_MARK_MEMBER_NAME(_values,"_values");
	HX_MARK_MEMBER_NAME(_watching,"_watching");
	HX_MARK_MEMBER_NAME(_quickWatchList,"_quickWatchList");
	::flixel::system::debug::Window_obj::__Mark(HX_MARK_ARG);
	HX_MARK_END_CLASS();
}

void Watch_obj::__Visit(HX_VISIT_PARAMS)
{
	HX_VISIT_MEMBER_NAME(editing,"editing");
	HX_VISIT_MEMBER_NAME(_names,"_names");
	HX_VISIT_MEMBER_NAME(_values,"_values");
	HX_VISIT_MEMBER_NAME(_watching,"_watching");
	HX_VISIT_MEMBER_NAME(_quickWatchList,"_quickWatchList");
	::flixel::system::debug::Window_obj::__Visit(HX_VISIT_ARG);
}

Dynamic Watch_obj::__Field(const ::String &inName,bool inCallProp)
{
	switch(inName.length) {
	case 3:
		if (HX_FIELD_EQ(inName,"add") ) { return add_dyn(); }
		break;
	case 6:
		if (HX_FIELD_EQ(inName,"_names") ) { return _names; }
		if (HX_FIELD_EQ(inName,"remove") ) { return remove_dyn(); }
		if (HX_FIELD_EQ(inName,"update") ) { return update_dyn(); }
		if (HX_FIELD_EQ(inName,"submit") ) { return submit_dyn(); }
		break;
	case 7:
		if (HX_FIELD_EQ(inName,"editing") ) { return editing; }
		if (HX_FIELD_EQ(inName,"_values") ) { return _values; }
		if (HX_FIELD_EQ(inName,"destroy") ) { return destroy_dyn(); }
		break;
	case 9:
		if (HX_FIELD_EQ(inName,"_watching") ) { return _watching; }
		if (HX_FIELD_EQ(inName,"removeAll") ) { return removeAll_dyn(); }
		break;
	case 10:
		if (HX_FIELD_EQ(inName,"updateSize") ) { return updateSize_dyn(); }
		break;
	case 11:
		if (HX_FIELD_EQ(inName,"removeEntry") ) { return removeEntry_dyn(); }
		break;
	case 15:
		if (HX_FIELD_EQ(inName,"_quickWatchList") ) { return _quickWatchList; }
		break;
	case 16:
		if (HX_FIELD_EQ(inName,"updateQuickWatch") ) { return updateQuickWatch_dyn(); }
	}
	return super::__Field(inName,inCallProp);
}

Dynamic Watch_obj::__SetField(const ::String &inName,const Dynamic &inValue,bool inCallProp)
{
	switch(inName.length) {
	case 6:
		if (HX_FIELD_EQ(inName,"_names") ) { _names=inValue.Cast< ::flash::display::Sprite >(); return inValue; }
		break;
	case 7:
		if (HX_FIELD_EQ(inName,"editing") ) { editing=inValue.Cast< bool >(); return inValue; }
		if (HX_FIELD_EQ(inName,"_values") ) { _values=inValue.Cast< ::flash::display::Sprite >(); return inValue; }
		break;
	case 9:
		if (HX_FIELD_EQ(inName,"_watching") ) { _watching=inValue.Cast< Array< ::Dynamic > >(); return inValue; }
		break;
	case 15:
		if (HX_FIELD_EQ(inName,"_quickWatchList") ) { _quickWatchList=inValue.Cast< ::haxe::ds::StringMap >(); return inValue; }
	}
	return super::__SetField(inName,inValue,inCallProp);
}

void Watch_obj::__GetFields(Array< ::String> &outFields)
{
	outFields->push(HX_CSTRING("editing"));
	outFields->push(HX_CSTRING("_names"));
	outFields->push(HX_CSTRING("_values"));
	outFields->push(HX_CSTRING("_watching"));
	outFields->push(HX_CSTRING("_quickWatchList"));
	super::__GetFields(outFields);
};

static ::String sStaticFields[] = {
	HX_CSTRING("MAX_LOG_LINES"),
	HX_CSTRING("LINE_HEIGHT"),
	String(null()) };

#if HXCPP_SCRIPTABLE
static hx::StorageInfo sMemberStorageInfo[] = {
	{hx::fsBool,(int)offsetof(Watch_obj,editing),HX_CSTRING("editing")},
	{hx::fsObject /*::flash::display::Sprite*/ ,(int)offsetof(Watch_obj,_names),HX_CSTRING("_names")},
	{hx::fsObject /*::flash::display::Sprite*/ ,(int)offsetof(Watch_obj,_values),HX_CSTRING("_values")},
	{hx::fsObject /*Array< ::Dynamic >*/ ,(int)offsetof(Watch_obj,_watching),HX_CSTRING("_watching")},
	{hx::fsObject /*::haxe::ds::StringMap*/ ,(int)offsetof(Watch_obj,_quickWatchList),HX_CSTRING("_quickWatchList")},
	{ hx::fsUnknown, 0, null()}
};
#endif

static ::String sMemberFields[] = {
	HX_CSTRING("editing"),
	HX_CSTRING("_names"),
	HX_CSTRING("_values"),
	HX_CSTRING("_watching"),
	HX_CSTRING("_quickWatchList"),
	HX_CSTRING("destroy"),
	HX_CSTRING("add"),
	HX_CSTRING("updateQuickWatch"),
	HX_CSTRING("remove"),
	HX_CSTRING("removeEntry"),
	HX_CSTRING("removeAll"),
	HX_CSTRING("update"),
	HX_CSTRING("submit"),
	HX_CSTRING("updateSize"),
	String(null()) };

static void sMarkStatics(HX_MARK_PARAMS) {
	HX_MARK_MEMBER_NAME(Watch_obj::__mClass,"__mClass");
	HX_MARK_MEMBER_NAME(Watch_obj::MAX_LOG_LINES,"MAX_LOG_LINES");
	HX_MARK_MEMBER_NAME(Watch_obj::LINE_HEIGHT,"LINE_HEIGHT");
};

#ifdef HXCPP_VISIT_ALLOCS
static void sVisitStatics(HX_VISIT_PARAMS) {
	HX_VISIT_MEMBER_NAME(Watch_obj::__mClass,"__mClass");
	HX_VISIT_MEMBER_NAME(Watch_obj::MAX_LOG_LINES,"MAX_LOG_LINES");
	HX_VISIT_MEMBER_NAME(Watch_obj::LINE_HEIGHT,"LINE_HEIGHT");
};

#endif

Class Watch_obj::__mClass;

void Watch_obj::__register()
{
	hx::Static(__mClass) = hx::RegisterClass(HX_CSTRING("flixel.system.debug.Watch"), hx::TCanCast< Watch_obj> ,sStaticFields,sMemberFields,
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

void Watch_obj::__boot()
{
	MAX_LOG_LINES= (int)1024;
	LINE_HEIGHT= (int)15;
}

} // end namespace flixel
} // end namespace system
} // end namespace debug
