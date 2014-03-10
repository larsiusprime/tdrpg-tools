#include <hxcpp.h>

#ifndef INCLUDED_StringTools
#include <StringTools.h>
#endif
#ifndef INCLUDED_Sys
#include <Sys.h>
#endif
#ifndef INCLUDED_Type
#include <Type.h>
#endif
#ifndef INCLUDED_flash_events_EventDispatcher
#include <flash/events/EventDispatcher.h>
#endif
#ifndef INCLUDED_flash_events_IEventDispatcher
#include <flash/events/IEventDispatcher.h>
#endif
#ifndef INCLUDED_flash_filesystem_File
#include <flash/filesystem/File.h>
#endif
#ifndef INCLUDED_flash_net_SharedObject
#include <flash/net/SharedObject.h>
#endif
#ifndef INCLUDED_flash_net_SharedObjectFlushStatus
#include <flash/net/SharedObjectFlushStatus.h>
#endif
#ifndef INCLUDED_haxe_Log
#include <haxe/Log.h>
#endif
#ifndef INCLUDED_haxe_Serializer
#include <haxe/Serializer.h>
#endif
#ifndef INCLUDED_haxe_Unserializer
#include <haxe/Unserializer.h>
#endif
#ifndef INCLUDED_haxe_io_Output
#include <haxe/io/Output.h>
#endif
#ifndef INCLUDED_haxe_io_Path
#include <haxe/io/Path.h>
#endif
#ifndef INCLUDED_sys_FileSystem
#include <sys/FileSystem.h>
#endif
#ifndef INCLUDED_sys_io_File
#include <sys/io/File.h>
#endif
#ifndef INCLUDED_sys_io_FileOutput
#include <sys/io/FileOutput.h>
#endif
namespace flash{
namespace net{

Void SharedObject_obj::__construct(::String name,::String localPath,Dynamic data)
{
HX_STACK_FRAME("flash.net.SharedObject","new",0x3ee7b505,"flash.net.SharedObject.new","flash/net/SharedObject.hx",25,0xc7b15fc9)

HX_STACK_ARG(name,"name")

HX_STACK_ARG(localPath,"localPath")

HX_STACK_ARG(data,"data")
{
	HX_STACK_LINE(27)
	super::__construct(null());
	HX_STACK_LINE(29)
	this->name = name;
	HX_STACK_LINE(30)
	this->localPath = localPath;
	HX_STACK_LINE(31)
	this->data = data;
}
;
	return null();
}

//SharedObject_obj::~SharedObject_obj() { }

Dynamic SharedObject_obj::__CreateEmpty() { return  new SharedObject_obj; }
hx::ObjectPtr< SharedObject_obj > SharedObject_obj::__new(::String name,::String localPath,Dynamic data)
{  hx::ObjectPtr< SharedObject_obj > result = new SharedObject_obj();
	result->__construct(name,localPath,data);
	return result;}

Dynamic SharedObject_obj::__Create(hx::DynamicArray inArgs)
{  hx::ObjectPtr< SharedObject_obj > result = new SharedObject_obj();
	result->__construct(inArgs[0],inArgs[1],inArgs[2]);
	return result;}

Void SharedObject_obj::clear( ){
{
		HX_STACK_FRAME("flash.net.SharedObject","clear",0x3f2d8972,"flash.net.SharedObject.clear","flash/net/SharedObject.hx",36,0xc7b15fc9)
		HX_STACK_THIS(this)
		HX_STACK_LINE(44)
		::String filePath = ::flash::net::SharedObject_obj::getFilePath(this->name,this->localPath);		HX_STACK_VAR(filePath,"filePath");
		HX_STACK_LINE(46)
		if ((::sys::FileSystem_obj::sys_exists(::haxe::io::Path_obj::removeTrailingSlashes(filePath)))){
			HX_STACK_LINE(48)
			::sys::FileSystem_obj::deleteFile(filePath);
		}
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC0(SharedObject_obj,clear,(void))

Void SharedObject_obj::close( ){
{
		HX_STACK_FRAME("flash.net.SharedObject","close",0x3f352f9d,"flash.net.SharedObject.close","flash/net/SharedObject.hx",57,0xc7b15fc9)
		HX_STACK_THIS(this)
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC0(SharedObject_obj,close,(void))

::flash::net::SharedObjectFlushStatus SharedObject_obj::flush( hx::Null< int >  __o_minDiskSpace){
int minDiskSpace = __o_minDiskSpace.Default(0);
	HX_STACK_FRAME("flash.net.SharedObject","flush",0xf96d7aa9,"flash.net.SharedObject.flush","flash/net/SharedObject.hx",121,0xc7b15fc9)
	HX_STACK_THIS(this)
	HX_STACK_ARG(minDiskSpace,"minDiskSpace")
{
		HX_STACK_LINE(123)
		::String encodedData = ::haxe::Serializer_obj::run(this->data);		HX_STACK_VAR(encodedData,"encodedData");
		HX_STACK_LINE(131)
		::String filePath = ::flash::net::SharedObject_obj::getFilePath(this->name,this->localPath);		HX_STACK_VAR(filePath,"filePath");
		HX_STACK_LINE(132)
		::String folderPath = ::haxe::io::Path_obj::directory(filePath);		HX_STACK_VAR(folderPath,"folderPath");
		HX_STACK_LINE(134)
		if ((!(::sys::FileSystem_obj::sys_exists(::haxe::io::Path_obj::removeTrailingSlashes(folderPath))))){
			HX_STACK_LINE(136)
			::flash::net::SharedObject_obj::mkdir(folderPath);
		}
		HX_STACK_LINE(140)
		::sys::io::FileOutput output = ::sys::io::File_obj::write(filePath,false);		HX_STACK_VAR(output,"output");
		HX_STACK_LINE(141)
		output->writeString(encodedData);
		HX_STACK_LINE(142)
		output->close();
		HX_STACK_LINE(146)
		return ::flash::net::SharedObjectFlushStatus_obj::FLUSHED;
	}
}


HX_DEFINE_DYNAMIC_FUNC1(SharedObject_obj,flush,return )

Void SharedObject_obj::setProperty( ::String propertyName,Dynamic value){
{
		HX_STACK_FRAME("flash.net.SharedObject","setProperty",0x5d49a3bc,"flash.net.SharedObject.setProperty","flash/net/SharedObject.hx",225,0xc7b15fc9)
		HX_STACK_THIS(this)
		HX_STACK_ARG(propertyName,"propertyName")
		HX_STACK_ARG(value,"value")
		HX_STACK_LINE(225)
		if (((this->data != null()))){
			HX_STACK_LINE(227)
			Dynamic o = this->data;		HX_STACK_VAR(o,"o");
			HX_STACK_LINE(227)
			if (((o != null()))){
				HX_STACK_LINE(227)
				o->__SetField(propertyName,value,false);
			}
		}
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC2(SharedObject_obj,setProperty,(void))

Void SharedObject_obj::mkdir( ::String directory){
{
		HX_STACK_FRAME("flash.net.SharedObject","mkdir",0x00856494,"flash.net.SharedObject.mkdir","flash/net/SharedObject.hx",66,0xc7b15fc9)
		HX_STACK_ARG(directory,"directory")
		HX_STACK_LINE(68)
		directory = ::StringTools_obj::replace(directory,HX_CSTRING("\\"),HX_CSTRING("/"));
		HX_STACK_LINE(69)
		::String total = HX_CSTRING("");		HX_STACK_VAR(total,"total");
		HX_STACK_LINE(71)
		if (((directory.substr((int)0,(int)1) == HX_CSTRING("/")))){
			HX_STACK_LINE(73)
			total = HX_CSTRING("/");
		}
		HX_STACK_LINE(77)
		Array< ::String > parts = directory.split(HX_CSTRING("/"));		HX_STACK_VAR(parts,"parts");
		HX_STACK_LINE(78)
		::String oldPath = HX_CSTRING("");		HX_STACK_VAR(oldPath,"oldPath");
		HX_STACK_LINE(80)
		if (((  (((parts->length > (int)0))) ? bool((parts->__get((int)0).indexOf(HX_CSTRING(":"),null()) > (int)-1)) : bool(false) ))){
			HX_STACK_LINE(82)
			oldPath = ::Sys_obj::getCwd();
			HX_STACK_LINE(83)
			::Sys_obj::setCwd((parts->__get((int)0) + HX_CSTRING("\\")));
			HX_STACK_LINE(84)
			parts->shift();
		}
		HX_STACK_LINE(88)
		{
			HX_STACK_LINE(88)
			int _g = (int)0;		HX_STACK_VAR(_g,"_g");
			HX_STACK_LINE(88)
			while(((_g < parts->length))){
				HX_STACK_LINE(88)
				::String part = parts->__get(_g);		HX_STACK_VAR(part,"part");
				HX_STACK_LINE(88)
				++(_g);
				HX_STACK_LINE(90)
				if (((bool((part != HX_CSTRING("."))) && bool((part != HX_CSTRING("")))))){
					HX_STACK_LINE(92)
					if (((total != HX_CSTRING("")))){
						HX_STACK_LINE(94)
						hx::AddEq(total,HX_CSTRING("/"));
					}
					HX_STACK_LINE(98)
					hx::AddEq(total,part);
					HX_STACK_LINE(100)
					if ((!(::sys::FileSystem_obj::sys_exists(::haxe::io::Path_obj::removeTrailingSlashes(total))))){
						HX_STACK_LINE(102)
						::sys::FileSystem_obj::createDirectory(total);
					}
				}
			}
		}
		HX_STACK_LINE(110)
		if (((oldPath != HX_CSTRING("")))){
			HX_STACK_LINE(112)
			::Sys_obj::setCwd(oldPath);
		}
	}
return null();
}


STATIC_HX_DEFINE_DYNAMIC_FUNC1(SharedObject_obj,mkdir,(void))

::String SharedObject_obj::getFilePath( ::String name,::String localPath){
	HX_STACK_FRAME("flash.net.SharedObject","getFilePath",0x0a3a229c,"flash.net.SharedObject.getFilePath","flash/net/SharedObject.hx",151,0xc7b15fc9)
	HX_STACK_ARG(name,"name")
	HX_STACK_ARG(localPath,"localPath")
	HX_STACK_LINE(153)
	::String path = ::flash::filesystem::File_obj::get_applicationStorageDirectory()->nativePath;		HX_STACK_VAR(path,"path");
	HX_STACK_LINE(154)
	hx::AddEq(path,((((HX_CSTRING("/") + localPath) + HX_CSTRING("/")) + name) + HX_CSTRING(".sol")));
	HX_STACK_LINE(155)
	return path;
}


STATIC_HX_DEFINE_DYNAMIC_FUNC2(SharedObject_obj,getFilePath,return )

::flash::net::SharedObject SharedObject_obj::getLocal( ::String name,::String localPath,hx::Null< bool >  __o_secure){
bool secure = __o_secure.Default(false);
	HX_STACK_FRAME("flash.net.SharedObject","getLocal",0x3c7bfe30,"flash.net.SharedObject.getLocal","flash/net/SharedObject.hx",160,0xc7b15fc9)
	HX_STACK_ARG(name,"name")
	HX_STACK_ARG(localPath,"localPath")
	HX_STACK_ARG(secure,"secure")
{
		HX_STACK_LINE(162)
		if (((localPath == null()))){
			HX_STACK_LINE(164)
			localPath = HX_CSTRING("");
		}
		HX_STACK_LINE(174)
		::String filePath = ::flash::net::SharedObject_obj::getFilePath(name,localPath);		HX_STACK_VAR(filePath,"filePath");
		HX_STACK_LINE(175)
		::String rawData = HX_CSTRING("");		HX_STACK_VAR(rawData,"rawData");
		HX_STACK_LINE(177)
		if ((::sys::FileSystem_obj::sys_exists(::haxe::io::Path_obj::removeTrailingSlashes(filePath)))){
			HX_STACK_LINE(179)
			rawData = ::sys::io::File_obj::getContent(filePath);
		}
		struct _Function_1_1{
			inline static Dynamic Block( ){
				HX_STACK_FRAME("*","closure",0x5bdab937,"*.closure","flash/net/SharedObject.hx",185,0xc7b15fc9)
				{
					hx::Anon __result = hx::Anon_obj::Create();
					return __result;
				}
				return null();
			}
		};
		HX_STACK_LINE(185)
		Dynamic loadedData = _Function_1_1::Block();		HX_STACK_VAR(loadedData,"loadedData");
		HX_STACK_LINE(187)
		if (((bool((rawData != HX_CSTRING(""))) && bool((rawData != null()))))){
			HX_STACK_LINE(189)
			try
			{
			HX_STACK_CATCHABLE(Dynamic, 0);
			{
				HX_STACK_LINE(191)
				::haxe::Unserializer unserializer = ::haxe::Unserializer_obj::__new(rawData);		HX_STACK_VAR(unserializer,"unserializer");
				struct _Function_3_1{
					inline static Dynamic Block( ){
						HX_STACK_FRAME("*","closure",0x5bdab937,"*.closure","flash/net/SharedObject.hx",192,0xc7b15fc9)
						{
							hx::Anon __result = hx::Anon_obj::Create();
							__result->Add(HX_CSTRING("resolveEnum") , ::Type_obj::resolveEnum_dyn(),false);
							__result->Add(HX_CSTRING("resolveClass") , ::flash::net::SharedObject_obj::resolveClass_dyn(),false);
							return __result;
						}
						return null();
					}
				};
				HX_STACK_LINE(192)
				unserializer->setResolver(_Function_3_1::Block());
				HX_STACK_LINE(193)
				loadedData = unserializer->unserialize();
			}
			}
			catch(Dynamic __e){
				{
					HX_STACK_BEGIN_CATCH
					Dynamic e = __e;{
						HX_STACK_LINE(197)
						::haxe::Log_obj::trace(HX_CSTRING("Could not unserialize SharedObject"),hx::SourceInfo(HX_CSTRING("SharedObject.hx"),197,HX_CSTRING("flash.net.SharedObject"),HX_CSTRING("getLocal")));
						struct _Function_3_1{
							inline static Dynamic Block( ){
								HX_STACK_FRAME("*","closure",0x5bdab937,"*.closure","flash/net/SharedObject.hx",198,0xc7b15fc9)
								{
									hx::Anon __result = hx::Anon_obj::Create();
									return __result;
								}
								return null();
							}
						};
						HX_STACK_LINE(198)
						loadedData = _Function_3_1::Block();
					}
				}
			}
		}
		HX_STACK_LINE(204)
		::flash::net::SharedObject so = ::flash::net::SharedObject_obj::__new(name,localPath,loadedData);		HX_STACK_VAR(so,"so");
		HX_STACK_LINE(205)
		return so;
	}
}


STATIC_HX_DEFINE_DYNAMIC_FUNC3(SharedObject_obj,getLocal,return )

::Class SharedObject_obj::resolveClass( ::String name){
	HX_STACK_FRAME("flash.net.SharedObject","resolveClass",0x9aac9c67,"flash.net.SharedObject.resolveClass","flash/net/SharedObject.hx",210,0xc7b15fc9)
	HX_STACK_ARG(name,"name")
	HX_STACK_LINE(212)
	if (((name != null()))){
		HX_STACK_LINE(214)
		return ::Type_obj::resolveClass(::StringTools_obj::replace(::StringTools_obj::replace(name,HX_CSTRING("neash."),HX_CSTRING("native.")),HX_CSTRING("native."),HX_CSTRING("flash.")));
	}
	HX_STACK_LINE(218)
	return null();
}


STATIC_HX_DEFINE_DYNAMIC_FUNC1(SharedObject_obj,resolveClass,return )


SharedObject_obj::SharedObject_obj()
{
}

void SharedObject_obj::__Mark(HX_MARK_PARAMS)
{
	HX_MARK_BEGIN_CLASS(SharedObject);
	HX_MARK_MEMBER_NAME(data,"data");
	HX_MARK_MEMBER_NAME(localPath,"localPath");
	HX_MARK_MEMBER_NAME(name,"name");
	::flash::events::EventDispatcher_obj::__Mark(HX_MARK_ARG);
	HX_MARK_END_CLASS();
}

void SharedObject_obj::__Visit(HX_VISIT_PARAMS)
{
	HX_VISIT_MEMBER_NAME(data,"data");
	HX_VISIT_MEMBER_NAME(localPath,"localPath");
	HX_VISIT_MEMBER_NAME(name,"name");
	::flash::events::EventDispatcher_obj::__Visit(HX_VISIT_ARG);
}

Dynamic SharedObject_obj::__Field(const ::String &inName,bool inCallProp)
{
	switch(inName.length) {
	case 4:
		if (HX_FIELD_EQ(inName,"data") ) { return data; }
		if (HX_FIELD_EQ(inName,"name") ) { return name; }
		break;
	case 5:
		if (HX_FIELD_EQ(inName,"mkdir") ) { return mkdir_dyn(); }
		if (HX_FIELD_EQ(inName,"clear") ) { return clear_dyn(); }
		if (HX_FIELD_EQ(inName,"close") ) { return close_dyn(); }
		if (HX_FIELD_EQ(inName,"flush") ) { return flush_dyn(); }
		break;
	case 8:
		if (HX_FIELD_EQ(inName,"getLocal") ) { return getLocal_dyn(); }
		break;
	case 9:
		if (HX_FIELD_EQ(inName,"localPath") ) { return localPath; }
		break;
	case 11:
		if (HX_FIELD_EQ(inName,"getFilePath") ) { return getFilePath_dyn(); }
		if (HX_FIELD_EQ(inName,"setProperty") ) { return setProperty_dyn(); }
		break;
	case 12:
		if (HX_FIELD_EQ(inName,"resolveClass") ) { return resolveClass_dyn(); }
	}
	return super::__Field(inName,inCallProp);
}

Dynamic SharedObject_obj::__SetField(const ::String &inName,const Dynamic &inValue,bool inCallProp)
{
	switch(inName.length) {
	case 4:
		if (HX_FIELD_EQ(inName,"data") ) { data=inValue.Cast< Dynamic >(); return inValue; }
		if (HX_FIELD_EQ(inName,"name") ) { name=inValue.Cast< ::String >(); return inValue; }
		break;
	case 9:
		if (HX_FIELD_EQ(inName,"localPath") ) { localPath=inValue.Cast< ::String >(); return inValue; }
	}
	return super::__SetField(inName,inValue,inCallProp);
}

void SharedObject_obj::__GetFields(Array< ::String> &outFields)
{
	outFields->push(HX_CSTRING("data"));
	outFields->push(HX_CSTRING("localPath"));
	outFields->push(HX_CSTRING("name"));
	super::__GetFields(outFields);
};

static ::String sStaticFields[] = {
	HX_CSTRING("mkdir"),
	HX_CSTRING("getFilePath"),
	HX_CSTRING("getLocal"),
	HX_CSTRING("resolveClass"),
	String(null()) };

#if HXCPP_SCRIPTABLE
static hx::StorageInfo sMemberStorageInfo[] = {
	{hx::fsObject /*Dynamic*/ ,(int)offsetof(SharedObject_obj,data),HX_CSTRING("data")},
	{hx::fsString,(int)offsetof(SharedObject_obj,localPath),HX_CSTRING("localPath")},
	{hx::fsString,(int)offsetof(SharedObject_obj,name),HX_CSTRING("name")},
	{ hx::fsUnknown, 0, null()}
};
#endif

static ::String sMemberFields[] = {
	HX_CSTRING("data"),
	HX_CSTRING("localPath"),
	HX_CSTRING("name"),
	HX_CSTRING("clear"),
	HX_CSTRING("close"),
	HX_CSTRING("flush"),
	HX_CSTRING("setProperty"),
	String(null()) };

static void sMarkStatics(HX_MARK_PARAMS) {
	HX_MARK_MEMBER_NAME(SharedObject_obj::__mClass,"__mClass");
};

#ifdef HXCPP_VISIT_ALLOCS
static void sVisitStatics(HX_VISIT_PARAMS) {
	HX_VISIT_MEMBER_NAME(SharedObject_obj::__mClass,"__mClass");
};

#endif

Class SharedObject_obj::__mClass;

void SharedObject_obj::__register()
{
	hx::Static(__mClass) = hx::RegisterClass(HX_CSTRING("flash.net.SharedObject"), hx::TCanCast< SharedObject_obj> ,sStaticFields,sMemberFields,
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

void SharedObject_obj::__boot()
{
}

} // end namespace flash
} // end namespace net
