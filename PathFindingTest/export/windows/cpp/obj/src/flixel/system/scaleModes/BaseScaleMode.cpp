#include <hxcpp.h>

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
#ifndef INCLUDED_flixel_FlxBasic
#include <flixel/FlxBasic.h>
#endif
#ifndef INCLUDED_flixel_FlxCamera
#include <flixel/FlxCamera.h>
#endif
#ifndef INCLUDED_flixel_FlxG
#include <flixel/FlxG.h>
#endif
#ifndef INCLUDED_flixel_FlxGame
#include <flixel/FlxGame.h>
#endif
#ifndef INCLUDED_flixel_interfaces_IFlxDestroyable
#include <flixel/interfaces/IFlxDestroyable.h>
#endif
#ifndef INCLUDED_flixel_system_scaleModes_BaseScaleMode
#include <flixel/system/scaleModes/BaseScaleMode.h>
#endif
#ifndef INCLUDED_flixel_util_FlxPoint
#include <flixel/util/FlxPoint.h>
#endif
#ifndef INCLUDED_hxMath
#include <hxMath.h>
#endif
namespace flixel{
namespace system{
namespace scaleModes{

Void BaseScaleMode_obj::__construct()
{
HX_STACK_FRAME("flixel.system.scaleModes.BaseScaleMode","new",0xb84381b3,"flixel.system.scaleModes.BaseScaleMode.new","flixel/system/scaleModes/BaseScaleMode.hx",17,0x5a3188fe)
{
	HX_STACK_LINE(18)
	this->deviceSize = ::flixel::util::FlxPoint_obj::__new(null(),null());
	HX_STACK_LINE(19)
	this->gameSize = ::flixel::util::FlxPoint_obj::__new(null(),null());
	HX_STACK_LINE(20)
	this->scale = ::flixel::util::FlxPoint_obj::__new(null(),null());
	HX_STACK_LINE(21)
	this->offset = ::flixel::util::FlxPoint_obj::__new(null(),null());
}
;
	return null();
}

//BaseScaleMode_obj::~BaseScaleMode_obj() { }

Dynamic BaseScaleMode_obj::__CreateEmpty() { return  new BaseScaleMode_obj; }
hx::ObjectPtr< BaseScaleMode_obj > BaseScaleMode_obj::__new()
{  hx::ObjectPtr< BaseScaleMode_obj > result = new BaseScaleMode_obj();
	result->__construct();
	return result;}

Dynamic BaseScaleMode_obj::__Create(hx::DynamicArray inArgs)
{  hx::ObjectPtr< BaseScaleMode_obj > result = new BaseScaleMode_obj();
	result->__construct();
	return result;}

Void BaseScaleMode_obj::onMeasure( int Width,int Height){
{
		HX_STACK_FRAME("flixel.system.scaleModes.BaseScaleMode","onMeasure",0xbc54a592,"flixel.system.scaleModes.BaseScaleMode.onMeasure","flixel/system/scaleModes/BaseScaleMode.hx",25,0x5a3188fe)
		HX_STACK_THIS(this)
		HX_STACK_ARG(Width,"Width")
		HX_STACK_ARG(Height,"Height")
		HX_STACK_LINE(26)
		this->updateGameSize(Width,Height);
		HX_STACK_LINE(27)
		this->updateDeviceSize(Width,Height);
		HX_STACK_LINE(28)
		this->updateScaleOffset();
		HX_STACK_LINE(29)
		this->updateGameScale();
		HX_STACK_LINE(30)
		this->updateGamePosition();
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC2(BaseScaleMode_obj,onMeasure,(void))

Void BaseScaleMode_obj::updateGameSize( int Width,int Height){
{
		HX_STACK_FRAME("flixel.system.scaleModes.BaseScaleMode","updateGameSize",0x99f00e89,"flixel.system.scaleModes.BaseScaleMode.updateGameSize","flixel/system/scaleModes/BaseScaleMode.hx",35,0x5a3188fe)
		HX_STACK_THIS(this)
		HX_STACK_ARG(Width,"Width")
		HX_STACK_ARG(Height,"Height")
		HX_STACK_LINE(35)
		this->gameSize->set(Width,Height);
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC2(BaseScaleMode_obj,updateGameSize,(void))

Void BaseScaleMode_obj::updateDeviceSize( int Width,int Height){
{
		HX_STACK_FRAME("flixel.system.scaleModes.BaseScaleMode","updateDeviceSize",0xb35132ad,"flixel.system.scaleModes.BaseScaleMode.updateDeviceSize","flixel/system/scaleModes/BaseScaleMode.hx",40,0x5a3188fe)
		HX_STACK_THIS(this)
		HX_STACK_ARG(Width,"Width")
		HX_STACK_ARG(Height,"Height")
		HX_STACK_LINE(40)
		this->deviceSize->set(Width,Height);
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC2(BaseScaleMode_obj,updateDeviceSize,(void))

Void BaseScaleMode_obj::updateScaleOffset( ){
{
		HX_STACK_FRAME("flixel.system.scaleModes.BaseScaleMode","updateScaleOffset",0x13e546c7,"flixel.system.scaleModes.BaseScaleMode.updateScaleOffset","flixel/system/scaleModes/BaseScaleMode.hx",44,0x5a3188fe)
		HX_STACK_THIS(this)
		HX_STACK_LINE(45)
		this->scale->set_x((Float(this->gameSize->x) / Float(::flixel::FlxG_obj::width)));
		HX_STACK_LINE(46)
		this->scale->set_y((Float(this->gameSize->y) / Float(::flixel::FlxG_obj::height)));
		HX_STACK_LINE(48)
		::flixel::system::scaleModes::BaseScaleMode_obj::zoom->set(::flixel::FlxCamera_obj::defaultZoom,::flixel::FlxCamera_obj::defaultZoom);
		HX_STACK_LINE(50)
		if (((::flixel::FlxG_obj::camera != null()))){
			struct _Function_2_1{
				inline static ::flixel::util::FlxPoint Block( ){
					HX_STACK_FRAME("*","closure",0x5bdab937,"*.closure","flixel/system/scaleModes/BaseScaleMode.hx",52,0x5a3188fe)
					{
						HX_STACK_LINE(52)
						::flixel::FlxCamera _this = ::flixel::FlxG_obj::camera;		HX_STACK_VAR(_this,"_this");
						HX_STACK_LINE(52)
						Float _g = _this->flashSprite->get_scaleX();		HX_STACK_VAR(_g,"_g");
						HX_STACK_LINE(52)
						return _this->_point->set(_g,_this->flashSprite->get_scaleY());
					}
					return null();
				}
			};
			HX_STACK_LINE(52)
			::flixel::system::scaleModes::BaseScaleMode_obj::zoom->set_x((_Function_2_1::Block())->x);
			struct _Function_2_2{
				inline static ::flixel::util::FlxPoint Block( ){
					HX_STACK_FRAME("*","closure",0x5bdab937,"*.closure","flixel/system/scaleModes/BaseScaleMode.hx",53,0x5a3188fe)
					{
						HX_STACK_LINE(53)
						::flixel::FlxCamera _this = ::flixel::FlxG_obj::camera;		HX_STACK_VAR(_this,"_this");
						HX_STACK_LINE(53)
						Float _g1 = _this->flashSprite->get_scaleX();		HX_STACK_VAR(_g1,"_g1");
						HX_STACK_LINE(53)
						return _this->_point->set(_g1,_this->flashSprite->get_scaleY());
					}
					return null();
				}
			};
			HX_STACK_LINE(53)
			::flixel::system::scaleModes::BaseScaleMode_obj::zoom->set_y((_Function_2_2::Block())->y);
		}
		HX_STACK_LINE(56)
		{
			HX_STACK_LINE(56)
			::flixel::util::FlxPoint _g = this->scale;		HX_STACK_VAR(_g,"_g");
			HX_STACK_LINE(56)
			_g->set_x((Float(_g->x) / Float(::flixel::system::scaleModes::BaseScaleMode_obj::zoom->x)));
		}
		HX_STACK_LINE(57)
		{
			HX_STACK_LINE(57)
			::flixel::util::FlxPoint _g = this->scale;		HX_STACK_VAR(_g,"_g");
			HX_STACK_LINE(57)
			_g->set_y((Float(_g->y) / Float(::flixel::system::scaleModes::BaseScaleMode_obj::zoom->y)));
		}
		HX_STACK_LINE(59)
		this->offset->set_x(::Math_obj::ceil((((this->deviceSize->x - this->gameSize->x)) * 0.5)));
		HX_STACK_LINE(60)
		this->offset->set_y(::Math_obj::ceil((((this->deviceSize->y - this->gameSize->y)) * 0.5)));
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC0(BaseScaleMode_obj,updateScaleOffset,(void))

Void BaseScaleMode_obj::updateGameScale( ){
{
		HX_STACK_FRAME("flixel.system.scaleModes.BaseScaleMode","updateGameScale",0x14126fc2,"flixel.system.scaleModes.BaseScaleMode.updateGameScale","flixel/system/scaleModes/BaseScaleMode.hx",64,0x5a3188fe)
		HX_STACK_THIS(this)
		HX_STACK_LINE(65)
		::flixel::FlxG_obj::game->set_scaleX(this->scale->x);
		HX_STACK_LINE(66)
		::flixel::FlxG_obj::game->set_scaleY(this->scale->y);
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC0(BaseScaleMode_obj,updateGameScale,(void))

Void BaseScaleMode_obj::updateGamePosition( ){
{
		HX_STACK_FRAME("flixel.system.scaleModes.BaseScaleMode","updateGamePosition",0xebf59271,"flixel.system.scaleModes.BaseScaleMode.updateGamePosition","flixel/system/scaleModes/BaseScaleMode.hx",70,0x5a3188fe)
		HX_STACK_THIS(this)
		HX_STACK_LINE(71)
		::flixel::FlxG_obj::game->set_x(this->offset->x);
		HX_STACK_LINE(72)
		::flixel::FlxG_obj::game->set_y(this->offset->y);
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC0(BaseScaleMode_obj,updateGamePosition,(void))

::flixel::util::FlxPoint BaseScaleMode_obj::zoom;


BaseScaleMode_obj::BaseScaleMode_obj()
{
}

void BaseScaleMode_obj::__Mark(HX_MARK_PARAMS)
{
	HX_MARK_BEGIN_CLASS(BaseScaleMode);
	HX_MARK_MEMBER_NAME(deviceSize,"deviceSize");
	HX_MARK_MEMBER_NAME(gameSize,"gameSize");
	HX_MARK_MEMBER_NAME(scale,"scale");
	HX_MARK_MEMBER_NAME(offset,"offset");
	HX_MARK_END_CLASS();
}

void BaseScaleMode_obj::__Visit(HX_VISIT_PARAMS)
{
	HX_VISIT_MEMBER_NAME(deviceSize,"deviceSize");
	HX_VISIT_MEMBER_NAME(gameSize,"gameSize");
	HX_VISIT_MEMBER_NAME(scale,"scale");
	HX_VISIT_MEMBER_NAME(offset,"offset");
}

Dynamic BaseScaleMode_obj::__Field(const ::String &inName,bool inCallProp)
{
	switch(inName.length) {
	case 4:
		if (HX_FIELD_EQ(inName,"zoom") ) { return zoom; }
		break;
	case 5:
		if (HX_FIELD_EQ(inName,"scale") ) { return scale; }
		break;
	case 6:
		if (HX_FIELD_EQ(inName,"offset") ) { return offset; }
		break;
	case 8:
		if (HX_FIELD_EQ(inName,"gameSize") ) { return gameSize; }
		break;
	case 9:
		if (HX_FIELD_EQ(inName,"onMeasure") ) { return onMeasure_dyn(); }
		break;
	case 10:
		if (HX_FIELD_EQ(inName,"deviceSize") ) { return deviceSize; }
		break;
	case 14:
		if (HX_FIELD_EQ(inName,"updateGameSize") ) { return updateGameSize_dyn(); }
		break;
	case 15:
		if (HX_FIELD_EQ(inName,"updateGameScale") ) { return updateGameScale_dyn(); }
		break;
	case 16:
		if (HX_FIELD_EQ(inName,"updateDeviceSize") ) { return updateDeviceSize_dyn(); }
		break;
	case 17:
		if (HX_FIELD_EQ(inName,"updateScaleOffset") ) { return updateScaleOffset_dyn(); }
		break;
	case 18:
		if (HX_FIELD_EQ(inName,"updateGamePosition") ) { return updateGamePosition_dyn(); }
	}
	return super::__Field(inName,inCallProp);
}

Dynamic BaseScaleMode_obj::__SetField(const ::String &inName,const Dynamic &inValue,bool inCallProp)
{
	switch(inName.length) {
	case 4:
		if (HX_FIELD_EQ(inName,"zoom") ) { zoom=inValue.Cast< ::flixel::util::FlxPoint >(); return inValue; }
		break;
	case 5:
		if (HX_FIELD_EQ(inName,"scale") ) { scale=inValue.Cast< ::flixel::util::FlxPoint >(); return inValue; }
		break;
	case 6:
		if (HX_FIELD_EQ(inName,"offset") ) { offset=inValue.Cast< ::flixel::util::FlxPoint >(); return inValue; }
		break;
	case 8:
		if (HX_FIELD_EQ(inName,"gameSize") ) { gameSize=inValue.Cast< ::flixel::util::FlxPoint >(); return inValue; }
		break;
	case 10:
		if (HX_FIELD_EQ(inName,"deviceSize") ) { deviceSize=inValue.Cast< ::flixel::util::FlxPoint >(); return inValue; }
	}
	return super::__SetField(inName,inValue,inCallProp);
}

void BaseScaleMode_obj::__GetFields(Array< ::String> &outFields)
{
	outFields->push(HX_CSTRING("deviceSize"));
	outFields->push(HX_CSTRING("gameSize"));
	outFields->push(HX_CSTRING("scale"));
	outFields->push(HX_CSTRING("offset"));
	super::__GetFields(outFields);
};

static ::String sStaticFields[] = {
	HX_CSTRING("zoom"),
	String(null()) };

#if HXCPP_SCRIPTABLE
static hx::StorageInfo sMemberStorageInfo[] = {
	{hx::fsObject /*::flixel::util::FlxPoint*/ ,(int)offsetof(BaseScaleMode_obj,deviceSize),HX_CSTRING("deviceSize")},
	{hx::fsObject /*::flixel::util::FlxPoint*/ ,(int)offsetof(BaseScaleMode_obj,gameSize),HX_CSTRING("gameSize")},
	{hx::fsObject /*::flixel::util::FlxPoint*/ ,(int)offsetof(BaseScaleMode_obj,scale),HX_CSTRING("scale")},
	{hx::fsObject /*::flixel::util::FlxPoint*/ ,(int)offsetof(BaseScaleMode_obj,offset),HX_CSTRING("offset")},
	{ hx::fsUnknown, 0, null()}
};
#endif

static ::String sMemberFields[] = {
	HX_CSTRING("deviceSize"),
	HX_CSTRING("gameSize"),
	HX_CSTRING("scale"),
	HX_CSTRING("offset"),
	HX_CSTRING("onMeasure"),
	HX_CSTRING("updateGameSize"),
	HX_CSTRING("updateDeviceSize"),
	HX_CSTRING("updateScaleOffset"),
	HX_CSTRING("updateGameScale"),
	HX_CSTRING("updateGamePosition"),
	String(null()) };

static void sMarkStatics(HX_MARK_PARAMS) {
	HX_MARK_MEMBER_NAME(BaseScaleMode_obj::__mClass,"__mClass");
	HX_MARK_MEMBER_NAME(BaseScaleMode_obj::zoom,"zoom");
};

#ifdef HXCPP_VISIT_ALLOCS
static void sVisitStatics(HX_VISIT_PARAMS) {
	HX_VISIT_MEMBER_NAME(BaseScaleMode_obj::__mClass,"__mClass");
	HX_VISIT_MEMBER_NAME(BaseScaleMode_obj::zoom,"zoom");
};

#endif

Class BaseScaleMode_obj::__mClass;

void BaseScaleMode_obj::__register()
{
	hx::Static(__mClass) = hx::RegisterClass(HX_CSTRING("flixel.system.scaleModes.BaseScaleMode"), hx::TCanCast< BaseScaleMode_obj> ,sStaticFields,sMemberFields,
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

void BaseScaleMode_obj::__boot()
{
	zoom= ::flixel::util::FlxPoint_obj::__new(null(),null());
}

} // end namespace flixel
} // end namespace system
} // end namespace scaleModes
