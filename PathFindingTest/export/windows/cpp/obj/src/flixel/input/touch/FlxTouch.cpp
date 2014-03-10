#include <hxcpp.h>

#ifndef INCLUDED_Std
#include <Std.h>
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
#ifndef INCLUDED_flash_geom_Point
#include <flash/geom/Point.h>
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
#ifndef INCLUDED_flixel_FlxObject
#include <flixel/FlxObject.h>
#endif
#ifndef INCLUDED_flixel_group_FlxTypedGroup
#include <flixel/group/FlxTypedGroup.h>
#endif
#ifndef INCLUDED_flixel_input_FlxSwipe
#include <flixel/input/FlxSwipe.h>
#endif
#ifndef INCLUDED_flixel_input_touch_FlxTouch
#include <flixel/input/touch/FlxTouch.h>
#endif
#ifndef INCLUDED_flixel_interfaces_IFlxDestroyable
#include <flixel/interfaces/IFlxDestroyable.h>
#endif
#ifndef INCLUDED_flixel_util_FlxPoint
#include <flixel/util/FlxPoint.h>
#endif
#ifndef INCLUDED_hxMath
#include <hxMath.h>
#endif
namespace flixel{
namespace input{
namespace touch{

Void FlxTouch_obj::__construct(hx::Null< Float >  __o_X,hx::Null< Float >  __o_Y,hx::Null< int >  __o_PointID)
{
HX_STACK_FRAME("flixel.input.touch.FlxTouch","new",0xa47319c4,"flixel.input.touch.FlxTouch.new","flixel/input/touch/FlxTouch.hx",18,0x7bf286c9)

HX_STACK_ARG(__o_X,"X")

HX_STACK_ARG(__o_Y,"Y")

HX_STACK_ARG(__o_PointID,"PointID")
Float X = __o_X.Default(0);
Float Y = __o_Y.Default(0);
int PointID = __o_PointID.Default(0);
{
	HX_STACK_LINE(36)
	this->_last = (int)0;
	HX_STACK_LINE(35)
	this->_current = (int)0;
	HX_STACK_LINE(22)
	this->screenY = (int)0;
	HX_STACK_LINE(21)
	this->screenX = (int)0;
	HX_STACK_LINE(158)
	super::__construct(null(),null());
	HX_STACK_LINE(159)
	this->_point = ::flixel::util::FlxPoint_obj::__new(null(),null());
	HX_STACK_LINE(160)
	this->_globalScreenPosition = ::flixel::util::FlxPoint_obj::__new(null(),null());
	HX_STACK_LINE(161)
	this->_justPressedPosition = ::flixel::util::FlxPoint_obj::__new(null(),null());
	HX_STACK_LINE(163)
	this->_flashPoint = ::flash::geom::Point_obj::__new(null(),null());
	HX_STACK_LINE(164)
	this->updatePosition(X,Y);
	HX_STACK_LINE(165)
	this->touchPointID = PointID;
}
;
	return null();
}

//FlxTouch_obj::~FlxTouch_obj() { }

Dynamic FlxTouch_obj::__CreateEmpty() { return  new FlxTouch_obj; }
hx::ObjectPtr< FlxTouch_obj > FlxTouch_obj::__new(hx::Null< Float >  __o_X,hx::Null< Float >  __o_Y,hx::Null< int >  __o_PointID)
{  hx::ObjectPtr< FlxTouch_obj > result = new FlxTouch_obj();
	result->__construct(__o_X,__o_Y,__o_PointID);
	return result;}

Dynamic FlxTouch_obj::__Create(hx::DynamicArray inArgs)
{  hx::ObjectPtr< FlxTouch_obj > result = new FlxTouch_obj();
	result->__construct(inArgs[0],inArgs[1],inArgs[2]);
	return result;}

hx::Object *FlxTouch_obj::__ToInterface(const hx::type_info &inType) {
	if (inType==typeid( ::flixel::interfaces::IFlxDestroyable_obj)) return operator ::flixel::interfaces::IFlxDestroyable_obj *();
	return super::__ToInterface(inType);
}

Void FlxTouch_obj::destroy( ){
{
		HX_STACK_FRAME("flixel.input.touch.FlxTouch","destroy",0x988ff85e,"flixel.input.touch.FlxTouch.destroy","flixel/input/touch/FlxTouch.hx",48,0x7bf286c9)
		HX_STACK_THIS(this)
		HX_STACK_LINE(49)
		this->_point = null();
		HX_STACK_LINE(50)
		this->_globalScreenPosition = null();
		HX_STACK_LINE(51)
		this->_flashPoint = null();
		HX_STACK_LINE(52)
		this->_justPressedPosition = null();
	}
return null();
}


::flixel::util::FlxPoint FlxTouch_obj::getWorldPosition( ::flixel::FlxCamera Camera,::flixel::util::FlxPoint point){
	HX_STACK_FRAME("flixel.input.touch.FlxTouch","getWorldPosition",0x5306e6c1,"flixel.input.touch.FlxTouch.getWorldPosition","flixel/input/touch/FlxTouch.hx",64,0x7bf286c9)
	HX_STACK_THIS(this)
	HX_STACK_ARG(Camera,"Camera")
	HX_STACK_ARG(point,"point")
	HX_STACK_LINE(65)
	if (((Camera == null()))){
		HX_STACK_LINE(67)
		Camera = ::flixel::FlxG_obj::camera;
	}
	HX_STACK_LINE(69)
	if (((point == null()))){
		HX_STACK_LINE(71)
		point = ::flixel::util::FlxPoint_obj::__new(null(),null());
	}
	HX_STACK_LINE(73)
	this->getScreenPosition(Camera,this->_point);
	HX_STACK_LINE(74)
	point->set_x((this->_point->x + Camera->scroll->x));
	HX_STACK_LINE(75)
	point->set_y((this->_point->y + Camera->scroll->y));
	HX_STACK_LINE(76)
	return point;
}


HX_DEFINE_DYNAMIC_FUNC2(FlxTouch_obj,getWorldPosition,return )

::flixel::util::FlxPoint FlxTouch_obj::getScreenPosition( ::flixel::FlxCamera Camera,::flixel::util::FlxPoint point){
	HX_STACK_FRAME("flixel.input.touch.FlxTouch","getScreenPosition",0x13c003cf,"flixel.input.touch.FlxTouch.getScreenPosition","flixel/input/touch/FlxTouch.hx",88,0x7bf286c9)
	HX_STACK_THIS(this)
	HX_STACK_ARG(Camera,"Camera")
	HX_STACK_ARG(point,"point")
	HX_STACK_LINE(89)
	if (((Camera == null()))){
		HX_STACK_LINE(91)
		Camera = ::flixel::FlxG_obj::camera;
	}
	HX_STACK_LINE(93)
	if (((point == null()))){
		HX_STACK_LINE(95)
		point = ::flixel::util::FlxPoint_obj::__new(null(),null());
	}
	HX_STACK_LINE(97)
	point->set_x((Float(((this->_globalScreenPosition->x - Camera->x))) / Float(Camera->zoom)));
	HX_STACK_LINE(98)
	point->set_y((Float(((this->_globalScreenPosition->y - Camera->y))) / Float(Camera->zoom)));
	HX_STACK_LINE(99)
	return point;
}


HX_DEFINE_DYNAMIC_FUNC2(FlxTouch_obj,getScreenPosition,return )

bool FlxTouch_obj::overlaps( ::flixel::FlxBasic ObjectOrGroup,::flixel::FlxCamera Camera){
	HX_STACK_FRAME("flixel.input.touch.FlxTouch","overlaps",0x59b2ff28,"flixel.input.touch.FlxTouch.overlaps","flixel/input/touch/FlxTouch.hx",112,0x7bf286c9)
	HX_STACK_THIS(this)
	HX_STACK_ARG(ObjectOrGroup,"ObjectOrGroup")
	HX_STACK_ARG(Camera,"Camera")
	HX_STACK_LINE(113)
	if ((::Std_obj::is(ObjectOrGroup,hx::ClassOf< ::flixel::group::FlxTypedGroup >()))){
		HX_STACK_LINE(115)
		int i = (int)0;		HX_STACK_VAR(i,"i");
		HX_STACK_LINE(116)
		bool results = false;		HX_STACK_VAR(results,"results");
		HX_STACK_LINE(117)
		::flixel::FlxBasic basic;		HX_STACK_VAR(basic,"basic");
		HX_STACK_LINE(118)
		::flixel::group::FlxTypedGroup grp = ObjectOrGroup;		HX_STACK_VAR(grp,"grp");
		HX_STACK_LINE(119)
		Array< ::Dynamic > members = grp->get_members();		HX_STACK_VAR(members,"members");
		HX_STACK_LINE(120)
		while(((i < grp->length))){
			HX_STACK_LINE(122)
			basic = members->__get((i)++).StaticCast< ::flixel::FlxBasic >();
			HX_STACK_LINE(123)
			if (((  (((bool((basic != null())) && bool(basic->exists)))) ? bool(this->overlaps(basic,Camera)) : bool(false) ))){
				HX_STACK_LINE(125)
				results = true;
				HX_STACK_LINE(126)
				break;
			}
		}
		HX_STACK_LINE(129)
		return results;
	}
	HX_STACK_LINE(131)
	return (hx::TCast< flixel::FlxObject >::cast(ObjectOrGroup))->overlapsPoint(hx::ObjectPtr<OBJ_>(this),true,Camera);
}


HX_DEFINE_DYNAMIC_FUNC2(FlxTouch_obj,overlaps,return )

Void FlxTouch_obj::reset( Float X,Float Y,int PointID){
{
		HX_STACK_FRAME("flixel.input.touch.FlxTouch","reset",0x4857b433,"flixel.input.touch.FlxTouch.reset","flixel/input/touch/FlxTouch.hx",138,0x7bf286c9)
		HX_STACK_THIS(this)
		HX_STACK_ARG(X,"X")
		HX_STACK_ARG(Y,"Y")
		HX_STACK_ARG(PointID,"PointID")
		HX_STACK_LINE(139)
		this->updatePosition(X,Y);
		HX_STACK_LINE(140)
		this->touchPointID = PointID;
		HX_STACK_LINE(141)
		this->_current = (int)0;
		HX_STACK_LINE(142)
		this->_last = (int)0;
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC3(FlxTouch_obj,reset,(void))

Void FlxTouch_obj::deactivate( ){
{
		HX_STACK_FRAME("flixel.input.touch.FlxTouch","deactivate",0xa401c750,"flixel.input.touch.FlxTouch.deactivate","flixel/input/touch/FlxTouch.hx",146,0x7bf286c9)
		HX_STACK_THIS(this)
		HX_STACK_LINE(147)
		this->_current = (int)0;
		HX_STACK_LINE(148)
		this->_last = (int)0;
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC0(FlxTouch_obj,deactivate,(void))

Void FlxTouch_obj::update( ){
{
		HX_STACK_FRAME("flixel.input.touch.FlxTouch","update",0x82f33325,"flixel.input.touch.FlxTouch.update","flixel/input/touch/FlxTouch.hx",172,0x7bf286c9)
		HX_STACK_THIS(this)
		HX_STACK_LINE(173)
		if (((bool((this->_last == (int)-1)) && bool((this->_current == (int)-1))))){
			HX_STACK_LINE(175)
			this->_current = (int)0;
		}
		else{
			HX_STACK_LINE(177)
			if (((bool((this->_last == (int)2)) && bool((this->_current == (int)2))))){
				HX_STACK_LINE(179)
				this->_current = (int)1;
			}
		}
		HX_STACK_LINE(181)
		this->_last = this->_current;
		HX_STACK_LINE(183)
		if (((this->_current == (int)2))){
			HX_STACK_LINE(185)
			this->_justPressedPosition->set(this->screenX,this->screenY);
			HX_STACK_LINE(186)
			this->_justPressedTimeInTicks = ::flixel::FlxG_obj::game->ticks;
		}
		else{
			HX_STACK_LINE(188)
			if (((this->_current == (int)-1))){
				HX_STACK_LINE(190)
				::flixel::FlxG_obj::swipes->push(::flixel::input::FlxSwipe_obj::__new(this->touchPointID,this->_justPressedPosition,this->getScreenPosition(null(),null()),this->_justPressedTimeInTicks));
			}
		}
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC0(FlxTouch_obj,update,(void))

Void FlxTouch_obj::updateCursor( ){
{
		HX_STACK_FRAME("flixel.input.touch.FlxTouch","updateCursor",0xf7f29fdb,"flixel.input.touch.FlxTouch.updateCursor","flixel/input/touch/FlxTouch.hx",198,0x7bf286c9)
		HX_STACK_THIS(this)
		HX_STACK_LINE(201)
		::flixel::FlxCamera camera = ::flixel::FlxG_obj::camera;		HX_STACK_VAR(camera,"camera");
		HX_STACK_LINE(202)
		this->screenX = ::Math_obj::floor((Float(((this->_globalScreenPosition->x - camera->x))) / Float(camera->zoom)));
		HX_STACK_LINE(203)
		this->screenY = ::Math_obj::floor((Float(((this->_globalScreenPosition->y - camera->y))) / Float(camera->zoom)));
		HX_STACK_LINE(204)
		this->set_x((this->screenX + camera->scroll->x));
		HX_STACK_LINE(205)
		this->set_y((this->screenY + camera->scroll->y));
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC0(FlxTouch_obj,updateCursor,(void))

Void FlxTouch_obj::updatePosition( Float X,Float Y){
{
		HX_STACK_FRAME("flixel.input.touch.FlxTouch","updatePosition",0x676ebcee,"flixel.input.touch.FlxTouch.updatePosition","flixel/input/touch/FlxTouch.hx",215,0x7bf286c9)
		HX_STACK_THIS(this)
		HX_STACK_ARG(X,"X")
		HX_STACK_ARG(Y,"Y")
		HX_STACK_LINE(216)
		this->_flashPoint->x = X;
		HX_STACK_LINE(217)
		this->_flashPoint->y = Y;
		HX_STACK_LINE(218)
		this->_flashPoint = ::flixel::FlxG_obj::game->globalToLocal(this->_flashPoint);
		HX_STACK_LINE(220)
		this->_globalScreenPosition->set_x(this->_flashPoint->x);
		HX_STACK_LINE(221)
		this->_globalScreenPosition->set_y(this->_flashPoint->y);
		HX_STACK_LINE(222)
		this->updateCursor();
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC2(FlxTouch_obj,updatePosition,(void))

bool FlxTouch_obj::get_pressed( ){
	HX_STACK_FRAME("flixel.input.touch.FlxTouch","get_pressed",0x583e801d,"flixel.input.touch.FlxTouch.get_pressed","flixel/input/touch/FlxTouch.hx",225,0x7bf286c9)
	HX_STACK_THIS(this)
	HX_STACK_LINE(225)
	return (this->_current > (int)0);
}


HX_DEFINE_DYNAMIC_FUNC0(FlxTouch_obj,get_pressed,return )

bool FlxTouch_obj::get_justPressed( ){
	HX_STACK_FRAME("flixel.input.touch.FlxTouch","get_justPressed",0xad2294d1,"flixel.input.touch.FlxTouch.get_justPressed","flixel/input/touch/FlxTouch.hx",226,0x7bf286c9)
	HX_STACK_THIS(this)
	HX_STACK_LINE(226)
	return (this->_current == (int)2);
}


HX_DEFINE_DYNAMIC_FUNC0(FlxTouch_obj,get_justPressed,return )

bool FlxTouch_obj::get_justReleased( ){
	HX_STACK_FRAME("flixel.input.touch.FlxTouch","get_justReleased",0xd7f5afae,"flixel.input.touch.FlxTouch.get_justReleased","flixel/input/touch/FlxTouch.hx",227,0x7bf286c9)
	HX_STACK_THIS(this)
	HX_STACK_LINE(227)
	return (this->_current == (int)-1);
}


HX_DEFINE_DYNAMIC_FUNC0(FlxTouch_obj,get_justReleased,return )

bool FlxTouch_obj::get_isActive( ){
	HX_STACK_FRAME("flixel.input.touch.FlxTouch","get_isActive",0xdd0ffb75,"flixel.input.touch.FlxTouch.get_isActive","flixel/input/touch/FlxTouch.hx",228,0x7bf286c9)
	HX_STACK_THIS(this)
	HX_STACK_LINE(228)
	return (this->_current != (int)0);
}


HX_DEFINE_DYNAMIC_FUNC0(FlxTouch_obj,get_isActive,return )


FlxTouch_obj::FlxTouch_obj()
{
}

void FlxTouch_obj::__Mark(HX_MARK_PARAMS)
{
	HX_MARK_BEGIN_CLASS(FlxTouch);
	HX_MARK_MEMBER_NAME(screenX,"screenX");
	HX_MARK_MEMBER_NAME(screenY,"screenY");
	HX_MARK_MEMBER_NAME(touchPointID,"touchPointID");
	HX_MARK_MEMBER_NAME(_current,"_current");
	HX_MARK_MEMBER_NAME(_last,"_last");
	HX_MARK_MEMBER_NAME(_point,"_point");
	HX_MARK_MEMBER_NAME(_globalScreenPosition,"_globalScreenPosition");
	HX_MARK_MEMBER_NAME(_flashPoint,"_flashPoint");
	HX_MARK_MEMBER_NAME(_justPressedPosition,"_justPressedPosition");
	HX_MARK_MEMBER_NAME(_justPressedTimeInTicks,"_justPressedTimeInTicks");
	HX_MARK_END_CLASS();
}

void FlxTouch_obj::__Visit(HX_VISIT_PARAMS)
{
	HX_VISIT_MEMBER_NAME(screenX,"screenX");
	HX_VISIT_MEMBER_NAME(screenY,"screenY");
	HX_VISIT_MEMBER_NAME(touchPointID,"touchPointID");
	HX_VISIT_MEMBER_NAME(_current,"_current");
	HX_VISIT_MEMBER_NAME(_last,"_last");
	HX_VISIT_MEMBER_NAME(_point,"_point");
	HX_VISIT_MEMBER_NAME(_globalScreenPosition,"_globalScreenPosition");
	HX_VISIT_MEMBER_NAME(_flashPoint,"_flashPoint");
	HX_VISIT_MEMBER_NAME(_justPressedPosition,"_justPressedPosition");
	HX_VISIT_MEMBER_NAME(_justPressedTimeInTicks,"_justPressedTimeInTicks");
}

Dynamic FlxTouch_obj::__Field(const ::String &inName,bool inCallProp)
{
	switch(inName.length) {
	case 5:
		if (HX_FIELD_EQ(inName,"_last") ) { return _last; }
		if (HX_FIELD_EQ(inName,"reset") ) { return reset_dyn(); }
		break;
	case 6:
		if (HX_FIELD_EQ(inName,"_point") ) { return _point; }
		if (HX_FIELD_EQ(inName,"update") ) { return update_dyn(); }
		break;
	case 7:
		if (HX_FIELD_EQ(inName,"screenX") ) { return screenX; }
		if (HX_FIELD_EQ(inName,"screenY") ) { return screenY; }
		if (HX_FIELD_EQ(inName,"pressed") ) { return get_pressed(); }
		if (HX_FIELD_EQ(inName,"destroy") ) { return destroy_dyn(); }
		break;
	case 8:
		if (HX_FIELD_EQ(inName,"isActive") ) { return get_isActive(); }
		if (HX_FIELD_EQ(inName,"_current") ) { return _current; }
		if (HX_FIELD_EQ(inName,"overlaps") ) { return overlaps_dyn(); }
		break;
	case 10:
		if (HX_FIELD_EQ(inName,"deactivate") ) { return deactivate_dyn(); }
		break;
	case 11:
		if (HX_FIELD_EQ(inName,"justPressed") ) { return get_justPressed(); }
		if (HX_FIELD_EQ(inName,"_flashPoint") ) { return _flashPoint; }
		if (HX_FIELD_EQ(inName,"get_pressed") ) { return get_pressed_dyn(); }
		break;
	case 12:
		if (HX_FIELD_EQ(inName,"touchPointID") ) { return touchPointID; }
		if (HX_FIELD_EQ(inName,"justReleased") ) { return get_justReleased(); }
		if (HX_FIELD_EQ(inName,"updateCursor") ) { return updateCursor_dyn(); }
		if (HX_FIELD_EQ(inName,"get_isActive") ) { return get_isActive_dyn(); }
		break;
	case 14:
		if (HX_FIELD_EQ(inName,"updatePosition") ) { return updatePosition_dyn(); }
		break;
	case 15:
		if (HX_FIELD_EQ(inName,"get_justPressed") ) { return get_justPressed_dyn(); }
		break;
	case 16:
		if (HX_FIELD_EQ(inName,"getWorldPosition") ) { return getWorldPosition_dyn(); }
		if (HX_FIELD_EQ(inName,"get_justReleased") ) { return get_justReleased_dyn(); }
		break;
	case 17:
		if (HX_FIELD_EQ(inName,"getScreenPosition") ) { return getScreenPosition_dyn(); }
		break;
	case 20:
		if (HX_FIELD_EQ(inName,"_justPressedPosition") ) { return _justPressedPosition; }
		break;
	case 21:
		if (HX_FIELD_EQ(inName,"_globalScreenPosition") ) { return _globalScreenPosition; }
		break;
	case 23:
		if (HX_FIELD_EQ(inName,"_justPressedTimeInTicks") ) { return _justPressedTimeInTicks; }
	}
	return super::__Field(inName,inCallProp);
}

Dynamic FlxTouch_obj::__SetField(const ::String &inName,const Dynamic &inValue,bool inCallProp)
{
	switch(inName.length) {
	case 5:
		if (HX_FIELD_EQ(inName,"_last") ) { _last=inValue.Cast< int >(); return inValue; }
		break;
	case 6:
		if (HX_FIELD_EQ(inName,"_point") ) { _point=inValue.Cast< ::flixel::util::FlxPoint >(); return inValue; }
		break;
	case 7:
		if (HX_FIELD_EQ(inName,"screenX") ) { screenX=inValue.Cast< int >(); return inValue; }
		if (HX_FIELD_EQ(inName,"screenY") ) { screenY=inValue.Cast< int >(); return inValue; }
		break;
	case 8:
		if (HX_FIELD_EQ(inName,"_current") ) { _current=inValue.Cast< int >(); return inValue; }
		break;
	case 11:
		if (HX_FIELD_EQ(inName,"_flashPoint") ) { _flashPoint=inValue.Cast< ::flash::geom::Point >(); return inValue; }
		break;
	case 12:
		if (HX_FIELD_EQ(inName,"touchPointID") ) { touchPointID=inValue.Cast< int >(); return inValue; }
		break;
	case 20:
		if (HX_FIELD_EQ(inName,"_justPressedPosition") ) { _justPressedPosition=inValue.Cast< ::flixel::util::FlxPoint >(); return inValue; }
		break;
	case 21:
		if (HX_FIELD_EQ(inName,"_globalScreenPosition") ) { _globalScreenPosition=inValue.Cast< ::flixel::util::FlxPoint >(); return inValue; }
		break;
	case 23:
		if (HX_FIELD_EQ(inName,"_justPressedTimeInTicks") ) { _justPressedTimeInTicks=inValue.Cast< Float >(); return inValue; }
	}
	return super::__SetField(inName,inValue,inCallProp);
}

void FlxTouch_obj::__GetFields(Array< ::String> &outFields)
{
	outFields->push(HX_CSTRING("screenX"));
	outFields->push(HX_CSTRING("screenY"));
	outFields->push(HX_CSTRING("touchPointID"));
	outFields->push(HX_CSTRING("pressed"));
	outFields->push(HX_CSTRING("justPressed"));
	outFields->push(HX_CSTRING("justReleased"));
	outFields->push(HX_CSTRING("isActive"));
	outFields->push(HX_CSTRING("_current"));
	outFields->push(HX_CSTRING("_last"));
	outFields->push(HX_CSTRING("_point"));
	outFields->push(HX_CSTRING("_globalScreenPosition"));
	outFields->push(HX_CSTRING("_flashPoint"));
	outFields->push(HX_CSTRING("_justPressedPosition"));
	outFields->push(HX_CSTRING("_justPressedTimeInTicks"));
	super::__GetFields(outFields);
};

static ::String sStaticFields[] = {
	String(null()) };

#if HXCPP_SCRIPTABLE
static hx::StorageInfo sMemberStorageInfo[] = {
	{hx::fsInt,(int)offsetof(FlxTouch_obj,screenX),HX_CSTRING("screenX")},
	{hx::fsInt,(int)offsetof(FlxTouch_obj,screenY),HX_CSTRING("screenY")},
	{hx::fsInt,(int)offsetof(FlxTouch_obj,touchPointID),HX_CSTRING("touchPointID")},
	{hx::fsInt,(int)offsetof(FlxTouch_obj,_current),HX_CSTRING("_current")},
	{hx::fsInt,(int)offsetof(FlxTouch_obj,_last),HX_CSTRING("_last")},
	{hx::fsObject /*::flixel::util::FlxPoint*/ ,(int)offsetof(FlxTouch_obj,_point),HX_CSTRING("_point")},
	{hx::fsObject /*::flixel::util::FlxPoint*/ ,(int)offsetof(FlxTouch_obj,_globalScreenPosition),HX_CSTRING("_globalScreenPosition")},
	{hx::fsObject /*::flash::geom::Point*/ ,(int)offsetof(FlxTouch_obj,_flashPoint),HX_CSTRING("_flashPoint")},
	{hx::fsObject /*::flixel::util::FlxPoint*/ ,(int)offsetof(FlxTouch_obj,_justPressedPosition),HX_CSTRING("_justPressedPosition")},
	{hx::fsFloat,(int)offsetof(FlxTouch_obj,_justPressedTimeInTicks),HX_CSTRING("_justPressedTimeInTicks")},
	{ hx::fsUnknown, 0, null()}
};
#endif

static ::String sMemberFields[] = {
	HX_CSTRING("screenX"),
	HX_CSTRING("screenY"),
	HX_CSTRING("touchPointID"),
	HX_CSTRING("_current"),
	HX_CSTRING("_last"),
	HX_CSTRING("_point"),
	HX_CSTRING("_globalScreenPosition"),
	HX_CSTRING("_flashPoint"),
	HX_CSTRING("_justPressedPosition"),
	HX_CSTRING("_justPressedTimeInTicks"),
	HX_CSTRING("destroy"),
	HX_CSTRING("getWorldPosition"),
	HX_CSTRING("getScreenPosition"),
	HX_CSTRING("overlaps"),
	HX_CSTRING("reset"),
	HX_CSTRING("deactivate"),
	HX_CSTRING("update"),
	HX_CSTRING("updateCursor"),
	HX_CSTRING("updatePosition"),
	HX_CSTRING("get_pressed"),
	HX_CSTRING("get_justPressed"),
	HX_CSTRING("get_justReleased"),
	HX_CSTRING("get_isActive"),
	String(null()) };

static void sMarkStatics(HX_MARK_PARAMS) {
	HX_MARK_MEMBER_NAME(FlxTouch_obj::__mClass,"__mClass");
};

#ifdef HXCPP_VISIT_ALLOCS
static void sVisitStatics(HX_VISIT_PARAMS) {
	HX_VISIT_MEMBER_NAME(FlxTouch_obj::__mClass,"__mClass");
};

#endif

Class FlxTouch_obj::__mClass;

void FlxTouch_obj::__register()
{
	hx::Static(__mClass) = hx::RegisterClass(HX_CSTRING("flixel.input.touch.FlxTouch"), hx::TCanCast< FlxTouch_obj> ,sStaticFields,sMemberFields,
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

void FlxTouch_obj::__boot()
{
}

} // end namespace flixel
} // end namespace input
} // end namespace touch
