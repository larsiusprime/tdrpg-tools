#include <hxcpp.h>

#ifndef INCLUDED_flixel_FlxBasic
#include <flixel/FlxBasic.h>
#endif
#ifndef INCLUDED_flixel_FlxCamera
#include <flixel/FlxCamera.h>
#endif
#ifndef INCLUDED_flixel_FlxG
#include <flixel/FlxG.h>
#endif
#ifndef INCLUDED_flixel_interfaces_IFlxDestroyable
#include <flixel/interfaces/IFlxDestroyable.h>
#endif
#ifndef INCLUDED_flixel_plugin_FlxPlugin
#include <flixel/plugin/FlxPlugin.h>
#endif
#ifndef INCLUDED_flixel_plugin_PathManager
#include <flixel/plugin/PathManager.h>
#endif
#ifndef INCLUDED_flixel_system_frontEnds_CameraFrontEnd
#include <flixel/system/frontEnds/CameraFrontEnd.h>
#endif
#ifndef INCLUDED_flixel_system_frontEnds_DebuggerFrontEnd
#include <flixel/system/frontEnds/DebuggerFrontEnd.h>
#endif
#ifndef INCLUDED_flixel_util_FlxArrayUtil
#include <flixel/util/FlxArrayUtil.h>
#endif
#ifndef INCLUDED_flixel_util_FlxPath
#include <flixel/util/FlxPath.h>
#endif
namespace flixel{
namespace plugin{

Void PathManager_obj::__construct()
{
HX_STACK_FRAME("flixel.plugin.PathManager","new",0xc86d5031,"flixel.plugin.PathManager.new","flixel/plugin/PathManager.hx",16,0xf3716a7f)
{
	HX_STACK_LINE(17)
	super::__construct();
	HX_STACK_LINE(18)
	this->_paths = Array_obj< ::Dynamic >::__new();
	HX_STACK_LINE(19)
	this->set_visible(false);
}
;
	return null();
}

//PathManager_obj::~PathManager_obj() { }

Dynamic PathManager_obj::__CreateEmpty() { return  new PathManager_obj; }
hx::ObjectPtr< PathManager_obj > PathManager_obj::__new()
{  hx::ObjectPtr< PathManager_obj > result = new PathManager_obj();
	result->__construct();
	return result;}

Dynamic PathManager_obj::__Create(hx::DynamicArray inArgs)
{  hx::ObjectPtr< PathManager_obj > result = new PathManager_obj();
	result->__construct();
	return result;}

Void PathManager_obj::destroy( ){
{
		HX_STACK_FRAME("flixel.plugin.PathManager","destroy",0xa78a694b,"flixel.plugin.PathManager.destroy","flixel/plugin/PathManager.hx",26,0xf3716a7f)
		HX_STACK_THIS(this)
		HX_STACK_LINE(27)
		this->clear();
		HX_STACK_LINE(28)
		this->_paths = null();
		HX_STACK_LINE(30)
		this->super::destroy();
	}
return null();
}


Void PathManager_obj::update( ){
{
		HX_STACK_FRAME("flixel.plugin.PathManager","update",0x90cafed8,"flixel.plugin.PathManager.update","flixel/plugin/PathManager.hx",35,0xf3716a7f)
		HX_STACK_THIS(this)
		HX_STACK_LINE(35)
		int _g = (int)0;		HX_STACK_VAR(_g,"_g");
		HX_STACK_LINE(35)
		Array< ::Dynamic > _g1 = this->_paths;		HX_STACK_VAR(_g1,"_g1");
		HX_STACK_LINE(35)
		while(((_g < _g1->length))){
			HX_STACK_LINE(35)
			::flixel::util::FlxPath path = _g1->__get(_g).StaticCast< ::flixel::util::FlxPath >();		HX_STACK_VAR(path,"path");
			HX_STACK_LINE(35)
			++(_g);
			HX_STACK_LINE(37)
			if ((!(path->paused))){
				HX_STACK_LINE(39)
				path->update();
			}
		}
	}
return null();
}


Void PathManager_obj::drawDebug( ){
{
		HX_STACK_FRAME("flixel.plugin.PathManager","drawDebug",0x18f33a40,"flixel.plugin.PathManager.drawDebug","flixel/plugin/PathManager.hx",50,0xf3716a7f)
		HX_STACK_THIS(this)
		HX_STACK_LINE(51)
		if (((bool(!(::flixel::FlxG_obj::debugger->drawDebug)) || bool(this->ignoreDrawDebug)))){
			HX_STACK_LINE(53)
			return null();
		}
		HX_STACK_LINE(56)
		if (((this->cameras == null()))){
			HX_STACK_LINE(58)
			this->cameras = ::flixel::FlxG_obj::cameras->list;
		}
		HX_STACK_LINE(61)
		int i = (int)0;		HX_STACK_VAR(i,"i");
		HX_STACK_LINE(62)
		int l = this->cameras->length;		HX_STACK_VAR(l,"l");
		HX_STACK_LINE(64)
		while(((i < l))){
			HX_STACK_LINE(66)
			this->drawDebugOnCamera(this->cameras->__get((i)++).StaticCast< ::flixel::FlxCamera >());
		}
	}
return null();
}


Void PathManager_obj::drawDebugOnCamera( ::flixel::FlxCamera Camera){
{
		HX_STACK_FRAME("flixel.plugin.PathManager","drawDebugOnCamera",0xa3027384,"flixel.plugin.PathManager.drawDebugOnCamera","flixel/plugin/PathManager.hx",78,0xf3716a7f)
		HX_STACK_THIS(this)
		HX_STACK_ARG(Camera,"Camera")
		HX_STACK_LINE(79)
		if (((Camera == null()))){
			HX_STACK_LINE(81)
			Camera = ::flixel::FlxG_obj::camera;
		}
		HX_STACK_LINE(84)
		int i = (this->_paths->length - (int)1);		HX_STACK_VAR(i,"i");
		HX_STACK_LINE(85)
		::flixel::util::FlxPath path;		HX_STACK_VAR(path,"path");
		HX_STACK_LINE(87)
		while(((i >= (int)0))){
			HX_STACK_LINE(89)
			path = this->_paths->__get((i)--).StaticCast< ::flixel::util::FlxPath >();
			HX_STACK_LINE(91)
			if (((bool((path != null())) && bool(!(path->ignoreDrawDebug))))){
				HX_STACK_LINE(93)
				path->drawDebug(Camera);
			}
		}
	}
return null();
}


Void PathManager_obj::add( ::flixel::util::FlxPath Path){
{
		HX_STACK_FRAME("flixel.plugin.PathManager","add",0xc86371f2,"flixel.plugin.PathManager.add","flixel/plugin/PathManager.hx",107,0xf3716a7f)
		HX_STACK_THIS(this)
		HX_STACK_ARG(Path,"Path")
		HX_STACK_LINE(107)
		if (((::flixel::util::FlxArrayUtil_obj::indexOf_flixel_util_FlxPath(this->_paths,Path,null()) < (int)0))){
			HX_STACK_LINE(109)
			this->_paths->push(Path);
		}
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC1(PathManager_obj,add,(void))

Void PathManager_obj::remove( ::flixel::util::FlxPath Path,hx::Null< bool >  __o_ReturnInPool){
bool ReturnInPool = __o_ReturnInPool.Default(true);
	HX_STACK_FRAME("flixel.plugin.PathManager","remove",0x0e4e1513,"flixel.plugin.PathManager.remove","flixel/plugin/PathManager.hx",120,0xf3716a7f)
	HX_STACK_THIS(this)
	HX_STACK_ARG(Path,"Path")
	HX_STACK_ARG(ReturnInPool,"ReturnInPool")
{
		HX_STACK_LINE(121)
		::flixel::util::FlxArrayUtil_obj::fastSplice_flixel_util_FlxPath(this->_paths,Path);
		HX_STACK_LINE(123)
		if ((ReturnInPool)){
			HX_STACK_LINE(125)
			::flixel::util::FlxPath_obj::put(Path);
		}
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC2(PathManager_obj,remove,(void))

Void PathManager_obj::clear( ){
{
		HX_STACK_FRAME("flixel.plugin.PathManager","clear",0x69b1479e,"flixel.plugin.PathManager.clear","flixel/plugin/PathManager.hx",134,0xf3716a7f)
		HX_STACK_THIS(this)
		HX_STACK_LINE(134)
		while(((this->_paths->length > (int)0))){
			HX_STACK_LINE(136)
			::flixel::util::FlxPath path = this->_paths->pop().StaticCast< ::flixel::util::FlxPath >();		HX_STACK_VAR(path,"path");
			HX_STACK_LINE(137)
			::flixel::util::FlxPath_obj::put(path);
		}
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC0(PathManager_obj,clear,(void))

Void PathManager_obj::onStateSwitch( ){
{
		HX_STACK_FRAME("flixel.plugin.PathManager","onStateSwitch",0x71108317,"flixel.plugin.PathManager.onStateSwitch","flixel/plugin/PathManager.hx",143,0xf3716a7f)
		HX_STACK_THIS(this)
		HX_STACK_LINE(143)
		this->clear();
	}
return null();
}



PathManager_obj::PathManager_obj()
{
}

void PathManager_obj::__Mark(HX_MARK_PARAMS)
{
	HX_MARK_BEGIN_CLASS(PathManager);
	HX_MARK_MEMBER_NAME(_paths,"_paths");
	::flixel::FlxBasic_obj::__Mark(HX_MARK_ARG);
	HX_MARK_END_CLASS();
}

void PathManager_obj::__Visit(HX_VISIT_PARAMS)
{
	HX_VISIT_MEMBER_NAME(_paths,"_paths");
	::flixel::FlxBasic_obj::__Visit(HX_VISIT_ARG);
}

Dynamic PathManager_obj::__Field(const ::String &inName,bool inCallProp)
{
	switch(inName.length) {
	case 3:
		if (HX_FIELD_EQ(inName,"add") ) { return add_dyn(); }
		break;
	case 5:
		if (HX_FIELD_EQ(inName,"clear") ) { return clear_dyn(); }
		break;
	case 6:
		if (HX_FIELD_EQ(inName,"_paths") ) { return _paths; }
		if (HX_FIELD_EQ(inName,"update") ) { return update_dyn(); }
		if (HX_FIELD_EQ(inName,"remove") ) { return remove_dyn(); }
		break;
	case 7:
		if (HX_FIELD_EQ(inName,"destroy") ) { return destroy_dyn(); }
		break;
	case 9:
		if (HX_FIELD_EQ(inName,"drawDebug") ) { return drawDebug_dyn(); }
		break;
	case 13:
		if (HX_FIELD_EQ(inName,"onStateSwitch") ) { return onStateSwitch_dyn(); }
		break;
	case 17:
		if (HX_FIELD_EQ(inName,"drawDebugOnCamera") ) { return drawDebugOnCamera_dyn(); }
	}
	return super::__Field(inName,inCallProp);
}

Dynamic PathManager_obj::__SetField(const ::String &inName,const Dynamic &inValue,bool inCallProp)
{
	switch(inName.length) {
	case 6:
		if (HX_FIELD_EQ(inName,"_paths") ) { _paths=inValue.Cast< Array< ::Dynamic > >(); return inValue; }
	}
	return super::__SetField(inName,inValue,inCallProp);
}

void PathManager_obj::__GetFields(Array< ::String> &outFields)
{
	outFields->push(HX_CSTRING("_paths"));
	super::__GetFields(outFields);
};

static ::String sStaticFields[] = {
	String(null()) };

#if HXCPP_SCRIPTABLE
static hx::StorageInfo sMemberStorageInfo[] = {
	{hx::fsObject /*Array< ::Dynamic >*/ ,(int)offsetof(PathManager_obj,_paths),HX_CSTRING("_paths")},
	{ hx::fsUnknown, 0, null()}
};
#endif

static ::String sMemberFields[] = {
	HX_CSTRING("_paths"),
	HX_CSTRING("destroy"),
	HX_CSTRING("update"),
	HX_CSTRING("drawDebug"),
	HX_CSTRING("drawDebugOnCamera"),
	HX_CSTRING("add"),
	HX_CSTRING("remove"),
	HX_CSTRING("clear"),
	HX_CSTRING("onStateSwitch"),
	String(null()) };

static void sMarkStatics(HX_MARK_PARAMS) {
	HX_MARK_MEMBER_NAME(PathManager_obj::__mClass,"__mClass");
};

#ifdef HXCPP_VISIT_ALLOCS
static void sVisitStatics(HX_VISIT_PARAMS) {
	HX_VISIT_MEMBER_NAME(PathManager_obj::__mClass,"__mClass");
};

#endif

Class PathManager_obj::__mClass;

void PathManager_obj::__register()
{
	hx::Static(__mClass) = hx::RegisterClass(HX_CSTRING("flixel.plugin.PathManager"), hx::TCanCast< PathManager_obj> ,sStaticFields,sMemberFields,
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

void PathManager_obj::__boot()
{
}

} // end namespace flixel
} // end namespace plugin
