#include <hxcpp.h>

#ifndef INCLUDED_IMap
#include <IMap.h>
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
#ifndef INCLUDED_flixel_FlxG
#include <flixel/FlxG.h>
#endif
#ifndef INCLUDED_flixel_FlxGame
#include <flixel/FlxGame.h>
#endif
#ifndef INCLUDED_flixel_system_debug_Console
#include <flixel/system/debug/Console.h>
#endif
#ifndef INCLUDED_flixel_system_debug_FlxDebugger
#include <flixel/system/debug/FlxDebugger.h>
#endif
#ifndef INCLUDED_flixel_system_debug_Window
#include <flixel/system/debug/Window.h>
#endif
#ifndef INCLUDED_flixel_system_frontEnds_ConsoleFrontEnd
#include <flixel/system/frontEnds/ConsoleFrontEnd.h>
#endif
#ifndef INCLUDED_haxe_ds_StringMap
#include <haxe/ds/StringMap.h>
#endif
namespace flixel{
namespace system{
namespace frontEnds{

Void ConsoleFrontEnd_obj::__construct()
{
HX_STACK_FRAME("flixel.system.frontEnds.ConsoleFrontEnd","new",0x926b3ea1,"flixel.system.frontEnds.ConsoleFrontEnd.new","flixel/system/frontEnds/ConsoleFrontEnd.hx",5,0x0ff3a650)
{
	HX_STACK_LINE(11)
	this->autoPause = true;
}
;
	return null();
}

//ConsoleFrontEnd_obj::~ConsoleFrontEnd_obj() { }

Dynamic ConsoleFrontEnd_obj::__CreateEmpty() { return  new ConsoleFrontEnd_obj; }
hx::ObjectPtr< ConsoleFrontEnd_obj > ConsoleFrontEnd_obj::__new()
{  hx::ObjectPtr< ConsoleFrontEnd_obj > result = new ConsoleFrontEnd_obj();
	result->__construct();
	return result;}

Dynamic ConsoleFrontEnd_obj::__Create(hx::DynamicArray inArgs)
{  hx::ObjectPtr< ConsoleFrontEnd_obj > result = new ConsoleFrontEnd_obj();
	result->__construct();
	return result;}

Void ConsoleFrontEnd_obj::registerFunction( ::String FunctionAlias,Dynamic Function){
{
		HX_STACK_FRAME("flixel.system.frontEnds.ConsoleFrontEnd","registerFunction",0xa673a5ba,"flixel.system.frontEnds.ConsoleFrontEnd.registerFunction","flixel/system/frontEnds/ConsoleFrontEnd.hx",22,0x0ff3a650)
		HX_STACK_THIS(this)
		HX_STACK_ARG(FunctionAlias,"FunctionAlias")
		HX_STACK_ARG(Function,"Function")
		HX_STACK_LINE(22)
		Dynamic value = Function;		HX_STACK_VAR(value,"value");
		HX_STACK_LINE(22)
		::flixel::FlxG_obj::game->debugger->console->registeredFunctions->set(FunctionAlias,value);
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC2(ConsoleFrontEnd_obj,registerFunction,(void))

Void ConsoleFrontEnd_obj::registerObject( ::String ObjectAlias,Dynamic AnyObject){
{
		HX_STACK_FRAME("flixel.system.frontEnds.ConsoleFrontEnd","registerObject",0x557f2ce1,"flixel.system.frontEnds.ConsoleFrontEnd.registerObject","flixel/system/frontEnds/ConsoleFrontEnd.hx",35,0x0ff3a650)
		HX_STACK_THIS(this)
		HX_STACK_ARG(ObjectAlias,"ObjectAlias")
		HX_STACK_ARG(AnyObject,"AnyObject")
		HX_STACK_LINE(35)
		Dynamic value = AnyObject;		HX_STACK_VAR(value,"value");
		HX_STACK_LINE(35)
		::flixel::FlxG_obj::game->debugger->console->registeredObjects->set(ObjectAlias,value);
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC2(ConsoleFrontEnd_obj,registerObject,(void))

Void ConsoleFrontEnd_obj::addCommand( Array< ::String > Aliases,Dynamic ProcessFunction,::String Help,::String ParamHelp,hx::Null< int >  __o_NumParams,hx::Null< int >  __o_ParamCutoff){
int NumParams = __o_NumParams.Default(0);
int ParamCutoff = __o_ParamCutoff.Default(-1);
	HX_STACK_FRAME("flixel.system.frontEnds.ConsoleFrontEnd","addCommand",0x0a98e909,"flixel.system.frontEnds.ConsoleFrontEnd.addCommand","flixel/system/frontEnds/ConsoleFrontEnd.hx",52,0x0ff3a650)
	HX_STACK_THIS(this)
	HX_STACK_ARG(Aliases,"Aliases")
	HX_STACK_ARG(ProcessFunction,"ProcessFunction")
	HX_STACK_ARG(Help,"Help")
	HX_STACK_ARG(ParamHelp,"ParamHelp")
	HX_STACK_ARG(NumParams,"NumParams")
	HX_STACK_ARG(ParamCutoff,"ParamCutoff")
{
		struct _Function_1_1{
			inline static Dynamic Block( ::String &ParamHelp,Array< ::String > &Aliases,int &NumParams,int &ParamCutoff,::String &Help,Dynamic &ProcessFunction){
				HX_STACK_FRAME("*","closure",0x5bdab937,"*.closure","flixel/system/frontEnds/ConsoleFrontEnd.hx",52,0x0ff3a650)
				{
					hx::Anon __result = hx::Anon_obj::Create();
					__result->Add(HX_CSTRING("aliases") , Aliases,false);
					__result->Add(HX_CSTRING("processFunction") , ProcessFunction,false);
					__result->Add(HX_CSTRING("help") , Help,false);
					__result->Add(HX_CSTRING("paramHelp") , ParamHelp,false);
					__result->Add(HX_CSTRING("numParams") , NumParams,false);
					__result->Add(HX_CSTRING("paramCutoff") , ParamCutoff,false);
					return __result;
				}
				return null();
			}
		};
		HX_STACK_LINE(52)
		::flixel::FlxG_obj::game->debugger->console->commands->__Field(HX_CSTRING("push"),true)(_Function_1_1::Block(ParamHelp,Aliases,NumParams,ParamCutoff,Help,ProcessFunction));
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC6(ConsoleFrontEnd_obj,addCommand,(void))


ConsoleFrontEnd_obj::ConsoleFrontEnd_obj()
{
}

Dynamic ConsoleFrontEnd_obj::__Field(const ::String &inName,bool inCallProp)
{
	switch(inName.length) {
	case 9:
		if (HX_FIELD_EQ(inName,"autoPause") ) { return autoPause; }
		break;
	case 10:
		if (HX_FIELD_EQ(inName,"addCommand") ) { return addCommand_dyn(); }
		break;
	case 14:
		if (HX_FIELD_EQ(inName,"registerObject") ) { return registerObject_dyn(); }
		break;
	case 16:
		if (HX_FIELD_EQ(inName,"registerFunction") ) { return registerFunction_dyn(); }
	}
	return super::__Field(inName,inCallProp);
}

Dynamic ConsoleFrontEnd_obj::__SetField(const ::String &inName,const Dynamic &inValue,bool inCallProp)
{
	switch(inName.length) {
	case 9:
		if (HX_FIELD_EQ(inName,"autoPause") ) { autoPause=inValue.Cast< bool >(); return inValue; }
	}
	return super::__SetField(inName,inValue,inCallProp);
}

void ConsoleFrontEnd_obj::__GetFields(Array< ::String> &outFields)
{
	outFields->push(HX_CSTRING("autoPause"));
	super::__GetFields(outFields);
};

static ::String sStaticFields[] = {
	String(null()) };

#if HXCPP_SCRIPTABLE
static hx::StorageInfo sMemberStorageInfo[] = {
	{hx::fsBool,(int)offsetof(ConsoleFrontEnd_obj,autoPause),HX_CSTRING("autoPause")},
	{ hx::fsUnknown, 0, null()}
};
#endif

static ::String sMemberFields[] = {
	HX_CSTRING("autoPause"),
	HX_CSTRING("registerFunction"),
	HX_CSTRING("registerObject"),
	HX_CSTRING("addCommand"),
	String(null()) };

static void sMarkStatics(HX_MARK_PARAMS) {
	HX_MARK_MEMBER_NAME(ConsoleFrontEnd_obj::__mClass,"__mClass");
};

#ifdef HXCPP_VISIT_ALLOCS
static void sVisitStatics(HX_VISIT_PARAMS) {
	HX_VISIT_MEMBER_NAME(ConsoleFrontEnd_obj::__mClass,"__mClass");
};

#endif

Class ConsoleFrontEnd_obj::__mClass;

void ConsoleFrontEnd_obj::__register()
{
	hx::Static(__mClass) = hx::RegisterClass(HX_CSTRING("flixel.system.frontEnds.ConsoleFrontEnd"), hx::TCanCast< ConsoleFrontEnd_obj> ,sStaticFields,sMemberFields,
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

void ConsoleFrontEnd_obj::__boot()
{
}

} // end namespace flixel
} // end namespace system
} // end namespace frontEnds
