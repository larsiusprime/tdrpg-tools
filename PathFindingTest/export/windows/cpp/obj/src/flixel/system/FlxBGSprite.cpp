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
#ifndef INCLUDED_flixel_FlxObject
#include <flixel/FlxObject.h>
#endif
#ifndef INCLUDED_flixel_FlxSprite
#include <flixel/FlxSprite.h>
#endif
#ifndef INCLUDED_flixel_interfaces_IFlxDestroyable
#include <flixel/interfaces/IFlxDestroyable.h>
#endif
#ifndef INCLUDED_flixel_system_FlxBGSprite
#include <flixel/system/FlxBGSprite.h>
#endif
#ifndef INCLUDED_flixel_system_frontEnds_BitmapFrontEnd
#include <flixel/system/frontEnds/BitmapFrontEnd.h>
#endif
#ifndef INCLUDED_flixel_system_frontEnds_CameraFrontEnd
#include <flixel/system/frontEnds/CameraFrontEnd.h>
#endif
#ifndef INCLUDED_flixel_system_layer_DrawStackItem
#include <flixel/system/layer/DrawStackItem.h>
#endif
#ifndef INCLUDED_flixel_system_layer_frames_FlxFrame
#include <flixel/system/layer/frames/FlxFrame.h>
#endif
#ifndef INCLUDED_flixel_util_FlxPoint
#include <flixel/util/FlxPoint.h>
#endif
#ifndef INCLUDED_flixel_util_loaders_CachedGraphics
#include <flixel/util/loaders/CachedGraphics.h>
#endif
namespace flixel{
namespace system{

Void FlxBGSprite_obj::__construct()
{
HX_STACK_FRAME("flixel.system.FlxBGSprite","new",0x62e2bd41,"flixel.system.FlxBGSprite.new","flixel/system/FlxBGSprite.hx",18,0xa9844f6f)
{
	HX_STACK_LINE(19)
	super::__construct(null(),null(),null());
	HX_STACK_LINE(20)
	this->makeGraphic((int)1,(int)1,(int)0,true,::flixel::FlxG_obj::bitmap->getUniqueKey(HX_CSTRING("bg_graphic_")));
	HX_STACK_LINE(21)
	this->scrollFactor->set(null(),null());
}
;
	return null();
}

//FlxBGSprite_obj::~FlxBGSprite_obj() { }

Dynamic FlxBGSprite_obj::__CreateEmpty() { return  new FlxBGSprite_obj; }
hx::ObjectPtr< FlxBGSprite_obj > FlxBGSprite_obj::__new()
{  hx::ObjectPtr< FlxBGSprite_obj > result = new FlxBGSprite_obj();
	result->__construct();
	return result;}

Dynamic FlxBGSprite_obj::__Create(hx::DynamicArray inArgs)
{  hx::ObjectPtr< FlxBGSprite_obj > result = new FlxBGSprite_obj();
	result->__construct();
	return result;}

Void FlxBGSprite_obj::draw( ){
{
		HX_STACK_FRAME("flixel.system.FlxBGSprite","draw",0x1cf08403,"flixel.system.FlxBGSprite.draw","flixel/system/FlxBGSprite.hx",28,0xa9844f6f)
		HX_STACK_THIS(this)
		HX_STACK_LINE(29)
		if (((this->cameras == null()))){
			HX_STACK_LINE(31)
			this->cameras = ::flixel::FlxG_obj::cameras->list;
		}
		HX_STACK_LINE(33)
		::flixel::FlxCamera camera;		HX_STACK_VAR(camera,"camera");
		HX_STACK_LINE(34)
		int i = (int)0;		HX_STACK_VAR(i,"i");
		HX_STACK_LINE(35)
		int l = this->cameras->length;		HX_STACK_VAR(l,"l");
		HX_STACK_LINE(37)
		::flixel::system::layer::DrawStackItem drawItem;		HX_STACK_VAR(drawItem,"drawItem");
		HX_STACK_LINE(38)
		Array< Float > currDrawData;		HX_STACK_VAR(currDrawData,"currDrawData");
		HX_STACK_LINE(39)
		int currIndex;		HX_STACK_VAR(currIndex,"currIndex");
		HX_STACK_LINE(44)
		while(((i < l))){
			HX_STACK_LINE(46)
			camera = this->cameras->__get((i)++).StaticCast< ::flixel::FlxCamera >();
			HX_STACK_LINE(48)
			if (((bool(!(camera->visible)) || bool(!(camera->exists))))){
				HX_STACK_LINE(50)
				continue;
			}
			HX_STACK_LINE(54)
			drawItem = camera->getDrawStackItem(this->cachedGraphics,this->isColored,this->_blendInt,null());
			HX_STACK_LINE(58)
			currDrawData = drawItem->drawData;
			HX_STACK_LINE(59)
			currIndex = drawItem->position;
			HX_STACK_LINE(61)
			this->_point->set_x((camera->width * 0.5));
			HX_STACK_LINE(62)
			this->_point->set_y((camera->height * 0.5));
			HX_STACK_LINE(64)
			Float csx = camera->width;		HX_STACK_VAR(csx,"csx");
			HX_STACK_LINE(65)
			Float ssy = (int)0;		HX_STACK_VAR(ssy,"ssy");
			HX_STACK_LINE(66)
			Float ssx = (int)0;		HX_STACK_VAR(ssx,"ssx");
			HX_STACK_LINE(67)
			Float csy = camera->height;		HX_STACK_VAR(csy,"csy");
			HX_STACK_LINE(69)
			currDrawData[(currIndex)++] = this->_point->x;
			HX_STACK_LINE(70)
			currDrawData[(currIndex)++] = this->_point->y;
			HX_STACK_LINE(72)
			currDrawData[(currIndex)++] = this->frame->tileID;
			HX_STACK_LINE(74)
			currDrawData[(currIndex)++] = csx;
			HX_STACK_LINE(75)
			currDrawData[(currIndex)++] = ssx;
			HX_STACK_LINE(76)
			currDrawData[(currIndex)++] = -(ssy);
			HX_STACK_LINE(77)
			currDrawData[(currIndex)++] = csy;
			HX_STACK_LINE(80)
			if ((this->isColored)){
				HX_STACK_LINE(82)
				currDrawData[(currIndex)++] = this->_red;
				HX_STACK_LINE(83)
				currDrawData[(currIndex)++] = this->_green;
				HX_STACK_LINE(84)
				currDrawData[(currIndex)++] = this->_blue;
			}
			HX_STACK_LINE(86)
			currDrawData[(currIndex)++] = this->alpha;
			HX_STACK_LINE(93)
			drawItem->position = currIndex;
			HX_STACK_LINE(96)
			(::flixel::FlxBasic_obj::_VISIBLECOUNT)++;
		}
	}
return null();
}



FlxBGSprite_obj::FlxBGSprite_obj()
{
}

Dynamic FlxBGSprite_obj::__Field(const ::String &inName,bool inCallProp)
{
	switch(inName.length) {
	case 4:
		if (HX_FIELD_EQ(inName,"draw") ) { return draw_dyn(); }
	}
	return super::__Field(inName,inCallProp);
}

Dynamic FlxBGSprite_obj::__SetField(const ::String &inName,const Dynamic &inValue,bool inCallProp)
{
	return super::__SetField(inName,inValue,inCallProp);
}

void FlxBGSprite_obj::__GetFields(Array< ::String> &outFields)
{
	super::__GetFields(outFields);
};

static ::String sStaticFields[] = {
	String(null()) };

#if HXCPP_SCRIPTABLE
static hx::StorageInfo *sMemberStorageInfo = 0;
#endif

static ::String sMemberFields[] = {
	HX_CSTRING("draw"),
	String(null()) };

static void sMarkStatics(HX_MARK_PARAMS) {
	HX_MARK_MEMBER_NAME(FlxBGSprite_obj::__mClass,"__mClass");
};

#ifdef HXCPP_VISIT_ALLOCS
static void sVisitStatics(HX_VISIT_PARAMS) {
	HX_VISIT_MEMBER_NAME(FlxBGSprite_obj::__mClass,"__mClass");
};

#endif

Class FlxBGSprite_obj::__mClass;

void FlxBGSprite_obj::__register()
{
	hx::Static(__mClass) = hx::RegisterClass(HX_CSTRING("flixel.system.FlxBGSprite"), hx::TCanCast< FlxBGSprite_obj> ,sStaticFields,sMemberFields,
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

void FlxBGSprite_obj::__boot()
{
}

} // end namespace flixel
} // end namespace system
