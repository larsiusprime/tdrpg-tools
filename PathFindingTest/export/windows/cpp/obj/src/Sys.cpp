#include <hxcpp.h>

#ifndef INCLUDED_Sys
#include <Sys.h>
#endif
#ifndef INCLUDED_cpp_Lib
#include <cpp/Lib.h>
#endif
#ifndef INCLUDED_haxe_io_Output
#include <haxe/io/Output.h>
#endif
#ifndef INCLUDED_sys_io_FileOutput
#include <sys/io/FileOutput.h>
#endif

Void Sys_obj::__construct()
{
	return null();
}

//Sys_obj::~Sys_obj() { }

Dynamic Sys_obj::__CreateEmpty() { return  new Sys_obj; }
hx::ObjectPtr< Sys_obj > Sys_obj::__new()
{  hx::ObjectPtr< Sys_obj > result = new Sys_obj();
	result->__construct();
	return result;}

Dynamic Sys_obj::__Create(hx::DynamicArray inArgs)
{  hx::ObjectPtr< Sys_obj > result = new Sys_obj();
	result->__construct();
	return result;}

Void Sys_obj::print( Dynamic v){
{
		HX_STACK_FRAME("Sys","print",0x483745ec,"Sys.print","C:\\HaxeToolkit\\haxe\\std/cpp/_std/Sys.hx",25,0x57bbb657)
		HX_STACK_ARG(v,"v")
		HX_STACK_LINE(25)
		::__hxcpp_print(v);
	}
return null();
}


STATIC_HX_DEFINE_DYNAMIC_FUNC1(Sys_obj,print,(void))

Void Sys_obj::println( Dynamic v){
{
		HX_STACK_FRAME("Sys","println",0x3905f76e,"Sys.println","C:\\HaxeToolkit\\haxe\\std/cpp/_std/Sys.hx",28,0x57bbb657)
		HX_STACK_ARG(v,"v")
		HX_STACK_LINE(29)
		::Sys_obj::print(v);
		HX_STACK_LINE(30)
		::Sys_obj::print(HX_CSTRING("\n"));
	}
return null();
}


STATIC_HX_DEFINE_DYNAMIC_FUNC1(Sys_obj,println,(void))

::haxe::io::Output Sys_obj::_stderr( ){
	HX_STACK_FRAME("Sys","stderr",0x3eb04003,"Sys.stderr","C:\\HaxeToolkit\\haxe\\std/cpp/_std/Sys.hx",42,0x57bbb657)
	HX_STACK_LINE(42)
	return ::sys::io::FileOutput_obj::__new(::Sys_obj::file_stderr());
}


STATIC_HX_DEFINE_DYNAMIC_FUNC0(Sys_obj,_stderr,return )

Void Sys_obj::sleep( Float seconds){
{
		HX_STACK_FRAME("Sys","sleep",0xfe70aad6,"Sys.sleep","C:\\HaxeToolkit\\haxe\\std/cpp/_std/Sys.hx",65,0x57bbb657)
		HX_STACK_ARG(seconds,"seconds")
		HX_STACK_LINE(65)
		::Sys_obj::_sleep(seconds);
	}
return null();
}


STATIC_HX_DEFINE_DYNAMIC_FUNC1(Sys_obj,sleep,(void))

::String Sys_obj::getCwd( ){
	HX_STACK_FRAME("Sys","getCwd",0xd9ded99b,"Sys.getCwd","C:\\HaxeToolkit\\haxe\\std/cpp/_std/Sys.hx",73,0x57bbb657)
	HX_STACK_LINE(73)
	return ::String(::Sys_obj::get_cwd());
}


STATIC_HX_DEFINE_DYNAMIC_FUNC0(Sys_obj,getCwd,return )

Void Sys_obj::setCwd( ::String s){
{
		HX_STACK_FRAME("Sys","setCwd",0xa6272e0f,"Sys.setCwd","C:\\HaxeToolkit\\haxe\\std/cpp/_std/Sys.hx",77,0x57bbb657)
		HX_STACK_ARG(s,"s")
		HX_STACK_LINE(77)
		::Sys_obj::set_cwd(s);
	}
return null();
}


STATIC_HX_DEFINE_DYNAMIC_FUNC1(Sys_obj,setCwd,(void))

Void Sys_obj::exit( int code){
{
		HX_STACK_FRAME("Sys","exit",0xed97463f,"Sys.exit","C:\\HaxeToolkit\\haxe\\std/cpp/_std/Sys.hx",108,0x57bbb657)
		HX_STACK_ARG(code,"code")
		HX_STACK_LINE(108)
		::Sys_obj::sys_exit(code);
	}
return null();
}


STATIC_HX_DEFINE_DYNAMIC_FUNC1(Sys_obj,exit,(void))

::String Sys_obj::executablePath( ){
	HX_STACK_FRAME("Sys","executablePath",0xfc9406f0,"Sys.executablePath","C:\\HaxeToolkit\\haxe\\std/cpp/_std/Sys.hx",120,0x57bbb657)
	HX_STACK_LINE(120)
	return ::String(::Sys_obj::sys_exe_path());
}


STATIC_HX_DEFINE_DYNAMIC_FUNC0(Sys_obj,executablePath,return )

Dynamic Sys_obj::_sleep;

Dynamic Sys_obj::get_cwd;

Dynamic Sys_obj::set_cwd;

Dynamic Sys_obj::sys_exit;

Dynamic Sys_obj::sys_exe_path;

Dynamic Sys_obj::file_stderr;


Sys_obj::Sys_obj()
{
}

Dynamic Sys_obj::__Field(const ::String &inName,bool inCallProp)
{
	switch(inName.length) {
	case 4:
		if (HX_FIELD_EQ(inName,"exit") ) { return exit_dyn(); }
		break;
	case 5:
		if (HX_FIELD_EQ(inName,"print") ) { return print_dyn(); }
		if (HX_FIELD_EQ(inName,"sleep") ) { return sleep_dyn(); }
		break;
	case 6:
		if (HX_FIELD_EQ(inName,"stderr") ) { return _stderr_dyn(); }
		if (HX_FIELD_EQ(inName,"getCwd") ) { return getCwd_dyn(); }
		if (HX_FIELD_EQ(inName,"setCwd") ) { return setCwd_dyn(); }
		if (HX_FIELD_EQ(inName,"_sleep") ) { return _sleep; }
		break;
	case 7:
		if (HX_FIELD_EQ(inName,"println") ) { return println_dyn(); }
		if (HX_FIELD_EQ(inName,"get_cwd") ) { return get_cwd; }
		if (HX_FIELD_EQ(inName,"set_cwd") ) { return set_cwd; }
		break;
	case 8:
		if (HX_FIELD_EQ(inName,"sys_exit") ) { return sys_exit; }
		break;
	case 11:
		if (HX_FIELD_EQ(inName,"file_stderr") ) { return file_stderr; }
		break;
	case 12:
		if (HX_FIELD_EQ(inName,"sys_exe_path") ) { return sys_exe_path; }
		break;
	case 14:
		if (HX_FIELD_EQ(inName,"executablePath") ) { return executablePath_dyn(); }
	}
	return super::__Field(inName,inCallProp);
}

Dynamic Sys_obj::__SetField(const ::String &inName,const Dynamic &inValue,bool inCallProp)
{
	switch(inName.length) {
	case 6:
		if (HX_FIELD_EQ(inName,"_sleep") ) { _sleep=inValue.Cast< Dynamic >(); return inValue; }
		break;
	case 7:
		if (HX_FIELD_EQ(inName,"get_cwd") ) { get_cwd=inValue.Cast< Dynamic >(); return inValue; }
		if (HX_FIELD_EQ(inName,"set_cwd") ) { set_cwd=inValue.Cast< Dynamic >(); return inValue; }
		break;
	case 8:
		if (HX_FIELD_EQ(inName,"sys_exit") ) { sys_exit=inValue.Cast< Dynamic >(); return inValue; }
		break;
	case 11:
		if (HX_FIELD_EQ(inName,"file_stderr") ) { file_stderr=inValue.Cast< Dynamic >(); return inValue; }
		break;
	case 12:
		if (HX_FIELD_EQ(inName,"sys_exe_path") ) { sys_exe_path=inValue.Cast< Dynamic >(); return inValue; }
	}
	return super::__SetField(inName,inValue,inCallProp);
}

void Sys_obj::__GetFields(Array< ::String> &outFields)
{
	super::__GetFields(outFields);
};

static ::String sStaticFields[] = {
	HX_CSTRING("print"),
	HX_CSTRING("println"),
	HX_CSTRING("stderr"),
	HX_CSTRING("sleep"),
	HX_CSTRING("getCwd"),
	HX_CSTRING("setCwd"),
	HX_CSTRING("exit"),
	HX_CSTRING("executablePath"),
	HX_CSTRING("_sleep"),
	HX_CSTRING("get_cwd"),
	HX_CSTRING("set_cwd"),
	HX_CSTRING("sys_exit"),
	HX_CSTRING("sys_exe_path"),
	HX_CSTRING("file_stderr"),
	String(null()) };

#if HXCPP_SCRIPTABLE
static hx::StorageInfo *sMemberStorageInfo = 0;
#endif

static ::String sMemberFields[] = {
	String(null()) };

static void sMarkStatics(HX_MARK_PARAMS) {
	HX_MARK_MEMBER_NAME(Sys_obj::__mClass,"__mClass");
	HX_MARK_MEMBER_NAME(Sys_obj::_sleep,"_sleep");
	HX_MARK_MEMBER_NAME(Sys_obj::get_cwd,"get_cwd");
	HX_MARK_MEMBER_NAME(Sys_obj::set_cwd,"set_cwd");
	HX_MARK_MEMBER_NAME(Sys_obj::sys_exit,"sys_exit");
	HX_MARK_MEMBER_NAME(Sys_obj::sys_exe_path,"sys_exe_path");
	HX_MARK_MEMBER_NAME(Sys_obj::file_stderr,"file_stderr");
};

#ifdef HXCPP_VISIT_ALLOCS
static void sVisitStatics(HX_VISIT_PARAMS) {
	HX_VISIT_MEMBER_NAME(Sys_obj::__mClass,"__mClass");
	HX_VISIT_MEMBER_NAME(Sys_obj::_sleep,"_sleep");
	HX_VISIT_MEMBER_NAME(Sys_obj::get_cwd,"get_cwd");
	HX_VISIT_MEMBER_NAME(Sys_obj::set_cwd,"set_cwd");
	HX_VISIT_MEMBER_NAME(Sys_obj::sys_exit,"sys_exit");
	HX_VISIT_MEMBER_NAME(Sys_obj::sys_exe_path,"sys_exe_path");
	HX_VISIT_MEMBER_NAME(Sys_obj::file_stderr,"file_stderr");
};

#endif

Class Sys_obj::__mClass;

void Sys_obj::__register()
{
	hx::Static(__mClass) = hx::RegisterClass(HX_CSTRING("Sys"), hx::TCanCast< Sys_obj> ,sStaticFields,sMemberFields,
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

void Sys_obj::__boot()
{
	_sleep= ::cpp::Lib_obj::load(HX_CSTRING("std"),HX_CSTRING("sys_sleep"),(int)1);
	get_cwd= ::cpp::Lib_obj::load(HX_CSTRING("std"),HX_CSTRING("get_cwd"),(int)0);
	set_cwd= ::cpp::Lib_obj::load(HX_CSTRING("std"),HX_CSTRING("set_cwd"),(int)1);
	sys_exit= ::cpp::Lib_obj::load(HX_CSTRING("std"),HX_CSTRING("sys_exit"),(int)1);
	sys_exe_path= ::cpp::Lib_obj::load(HX_CSTRING("std"),HX_CSTRING("sys_exe_path"),(int)0);
	file_stderr= ::cpp::Lib_obj::load(HX_CSTRING("std"),HX_CSTRING("file_stderr"),(int)0);
}

