#include <hxcpp.h>

#ifndef INCLUDED_Reflect
#include <Reflect.h>
#endif
#ifndef INCLUDED_Std
#include <Std.h>
#endif
#ifndef INCLUDED_flash_display_CapsStyle
#include <flash/display/CapsStyle.h>
#endif
#ifndef INCLUDED_flash_display_DisplayObject
#include <flash/display/DisplayObject.h>
#endif
#ifndef INCLUDED_flash_display_DisplayObjectContainer
#include <flash/display/DisplayObjectContainer.h>
#endif
#ifndef INCLUDED_flash_display_Graphics
#include <flash/display/Graphics.h>
#endif
#ifndef INCLUDED_flash_display_IBitmapDrawable
#include <flash/display/IBitmapDrawable.h>
#endif
#ifndef INCLUDED_flash_display_InteractiveObject
#include <flash/display/InteractiveObject.h>
#endif
#ifndef INCLUDED_flash_display_JointStyle
#include <flash/display/JointStyle.h>
#endif
#ifndef INCLUDED_flash_display_LineScaleMode
#include <flash/display/LineScaleMode.h>
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
#ifndef INCLUDED_flixel_FlxObject
#include <flixel/FlxObject.h>
#endif
#ifndef INCLUDED_flixel_group_FlxTypedGroup
#include <flixel/group/FlxTypedGroup.h>
#endif
#ifndef INCLUDED_flixel_interfaces_IFlxDestroyable
#include <flixel/interfaces/IFlxDestroyable.h>
#endif
#ifndef INCLUDED_flixel_system_FlxCollisionType
#include <flixel/system/FlxCollisionType.h>
#endif
#ifndef INCLUDED_flixel_system_debug_LogStyle
#include <flixel/system/debug/LogStyle.h>
#endif
#ifndef INCLUDED_flixel_system_frontEnds_CameraFrontEnd
#include <flixel/system/frontEnds/CameraFrontEnd.h>
#endif
#ifndef INCLUDED_flixel_system_frontEnds_LogFrontEnd
#include <flixel/system/frontEnds/LogFrontEnd.h>
#endif
#ifndef INCLUDED_flixel_system_layer_Region
#include <flixel/system/layer/Region.h>
#endif
#ifndef INCLUDED_flixel_system_layer_frames_FlxSpriteFrames
#include <flixel/system/layer/frames/FlxSpriteFrames.h>
#endif
#ifndef INCLUDED_flixel_tile_FlxTilemap
#include <flixel/tile/FlxTilemap.h>
#endif
#ifndef INCLUDED_flixel_util_FlxPoint
#include <flixel/util/FlxPoint.h>
#endif
#ifndef INCLUDED_flixel_util_FlxRect
#include <flixel/util/FlxRect.h>
#endif
#ifndef INCLUDED_flixel_util_FlxStringUtil
#include <flixel/util/FlxStringUtil.h>
#endif
#ifndef INCLUDED_flixel_util_FlxVelocity
#include <flixel/util/FlxVelocity.h>
#endif
#ifndef INCLUDED_flixel_util_loaders_CachedGraphics
#include <flixel/util/loaders/CachedGraphics.h>
#endif
#ifndef INCLUDED_hxMath
#include <hxMath.h>
#endif
namespace flixel{

Void FlxObject_obj::__construct(hx::Null< Float >  __o_X,hx::Null< Float >  __o_Y,hx::Null< Float >  __o_Width,hx::Null< Float >  __o_Height)
{
HX_STACK_FRAME("flixel.FlxObject","new",0x2aa4ec91,"flixel.FlxObject.new","flixel/FlxObject.hx",24,0xf0fe0d80)

HX_STACK_ARG(__o_X,"X")

HX_STACK_ARG(__o_Y,"Y")

HX_STACK_ARG(__o_Width,"Width")

HX_STACK_ARG(__o_Height,"Height")
Float X = __o_X.Default(0);
Float Y = __o_Y.Default(0);
Float Width = __o_Width.Default(0);
Float Height = __o_Height.Default(0);
{
	HX_STACK_LINE(1063)
	this->_boundingBoxColorOverritten = false;
	HX_STACK_LINE(185)
	this->collisonXDrag = true;
	HX_STACK_LINE(175)
	this->allowCollisions = (int)4369;
	HX_STACK_LINE(170)
	this->wasTouching = (int)0;
	HX_STACK_LINE(165)
	this->touching = (int)0;
	HX_STACK_LINE(160)
	this->health = (int)1;
	HX_STACK_LINE(156)
	this->maxAngular = (int)10000;
	HX_STACK_LINE(152)
	this->angularDrag = (int)0;
	HX_STACK_LINE(148)
	this->angularAcceleration = (int)0;
	HX_STACK_LINE(144)
	this->angularVelocity = (int)0;
	HX_STACK_LINE(140)
	this->elasticity = (int)0;
	HX_STACK_LINE(136)
	this->mass = (int)1;
	HX_STACK_LINE(107)
	this->forceComplexRender = false;
	HX_STACK_LINE(96)
	this->immovable = false;
	HX_STACK_LINE(92)
	this->moves = true;
	HX_STACK_LINE(87)
	this->angle = (int)0;
	HX_STACK_LINE(74)
	this->y = (int)0;
	HX_STACK_LINE(70)
	this->x = (int)0;
	HX_STACK_LINE(208)
	super::__construct();
	HX_STACK_LINE(210)
	this->set_x(X);
	HX_STACK_LINE(211)
	this->set_y(Y);
	HX_STACK_LINE(212)
	this->set_width(Width);
	HX_STACK_LINE(213)
	this->set_height(Height);
	HX_STACK_LINE(215)
	this->initVars();
}
;
	return null();
}

//FlxObject_obj::~FlxObject_obj() { }

Dynamic FlxObject_obj::__CreateEmpty() { return  new FlxObject_obj; }
hx::ObjectPtr< FlxObject_obj > FlxObject_obj::__new(hx::Null< Float >  __o_X,hx::Null< Float >  __o_Y,hx::Null< Float >  __o_Width,hx::Null< Float >  __o_Height)
{  hx::ObjectPtr< FlxObject_obj > result = new FlxObject_obj();
	result->__construct(__o_X,__o_Y,__o_Width,__o_Height);
	return result;}

Dynamic FlxObject_obj::__Create(hx::DynamicArray inArgs)
{  hx::ObjectPtr< FlxObject_obj > result = new FlxObject_obj();
	result->__construct(inArgs[0],inArgs[1],inArgs[2],inArgs[3]);
	return result;}

Void FlxObject_obj::initVars( ){
{
		HX_STACK_FRAME("flixel.FlxObject","initVars",0xb8a66d0b,"flixel.FlxObject.initVars","flixel/FlxObject.hx",222,0xf0fe0d80)
		HX_STACK_THIS(this)
		HX_STACK_LINE(223)
		this->collisionType = ::flixel::system::FlxCollisionType_obj::OBJECT;
		HX_STACK_LINE(224)
		this->last = ::flixel::util::FlxPoint_obj::__new(this->x,this->y);
		HX_STACK_LINE(225)
		this->scrollFactor = ::flixel::util::FlxPoint_obj::__new((int)1,(int)1);
		HX_STACK_LINE(226)
		this->_point = ::flixel::util::FlxPoint_obj::__new(null(),null());
		HX_STACK_LINE(228)
		{
			HX_STACK_LINE(228)
			this->velocity = ::flixel::util::FlxPoint_obj::__new(null(),null());
			HX_STACK_LINE(228)
			this->acceleration = ::flixel::util::FlxPoint_obj::__new(null(),null());
			HX_STACK_LINE(228)
			this->drag = ::flixel::util::FlxPoint_obj::__new(null(),null());
			HX_STACK_LINE(228)
			this->maxVelocity = ::flixel::util::FlxPoint_obj::__new((int)10000,(int)10000);
		}
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC0(FlxObject_obj,initVars,(void))

Void FlxObject_obj::initMotionVars( ){
{
		HX_STACK_FRAME("flixel.FlxObject","initMotionVars",0xb01943a1,"flixel.FlxObject.initMotionVars","flixel/FlxObject.hx",235,0xf0fe0d80)
		HX_STACK_THIS(this)
		HX_STACK_LINE(236)
		this->velocity = ::flixel::util::FlxPoint_obj::__new(null(),null());
		HX_STACK_LINE(237)
		this->acceleration = ::flixel::util::FlxPoint_obj::__new(null(),null());
		HX_STACK_LINE(238)
		this->drag = ::flixel::util::FlxPoint_obj::__new(null(),null());
		HX_STACK_LINE(239)
		this->maxVelocity = ::flixel::util::FlxPoint_obj::__new((int)10000,(int)10000);
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC0(FlxObject_obj,initMotionVars,(void))

Void FlxObject_obj::destroy( ){
{
		HX_STACK_FRAME("flixel.FlxObject","destroy",0xba37b5ab,"flixel.FlxObject.destroy","flixel/FlxObject.hx",247,0xf0fe0d80)
		HX_STACK_THIS(this)
		HX_STACK_LINE(248)
		this->super::destroy();
		HX_STACK_LINE(250)
		this->velocity = null();
		HX_STACK_LINE(251)
		this->acceleration = null();
		HX_STACK_LINE(252)
		this->drag = null();
		HX_STACK_LINE(253)
		this->maxVelocity = null();
		HX_STACK_LINE(254)
		this->scrollFactor = null();
		HX_STACK_LINE(255)
		this->last = null();
		HX_STACK_LINE(256)
		this->cameras = null();
		HX_STACK_LINE(257)
		this->_point = null();
		HX_STACK_LINE(258)
		this->scrollFactor = null();
		HX_STACK_LINE(260)
		this->framesData = null();
		HX_STACK_LINE(261)
		this->set_cachedGraphics(null());
		HX_STACK_LINE(262)
		this->region = null();
	}
return null();
}


Void FlxObject_obj::update( ){
{
		HX_STACK_FRAME("flixel.FlxObject","update",0x87b15e78,"flixel.FlxObject.update","flixel/FlxObject.hx",270,0xf0fe0d80)
		HX_STACK_THIS(this)
		HX_STACK_LINE(272)
		(::flixel::FlxBasic_obj::_ACTIVECOUNT)++;
		HX_STACK_LINE(275)
		this->last->set_x(this->x);
		HX_STACK_LINE(276)
		this->last->set_y(this->y);
		HX_STACK_LINE(278)
		if ((this->moves)){
			HX_STACK_LINE(280)
			Float delta;		HX_STACK_VAR(delta,"delta");
			HX_STACK_LINE(280)
			Float velocityDelta;		HX_STACK_VAR(velocityDelta,"velocityDelta");
			HX_STACK_LINE(280)
			Float dt = ::flixel::FlxG_obj::elapsed;		HX_STACK_VAR(dt,"dt");
			HX_STACK_LINE(280)
			velocityDelta = (0.5 * ((::flixel::util::FlxVelocity_obj::computeVelocity(this->angularVelocity,this->angularAcceleration,this->angularDrag,this->maxAngular) - this->angularVelocity)));
			HX_STACK_LINE(280)
			hx::AddEq(this->angularVelocity,velocityDelta);
			HX_STACK_LINE(280)
			{
				HX_STACK_LINE(280)
				::flixel::FlxObject _g = hx::ObjectPtr<OBJ_>(this);		HX_STACK_VAR(_g,"_g");
				HX_STACK_LINE(280)
				_g->set_angle((_g->angle + (this->angularVelocity * dt)));
			}
			HX_STACK_LINE(280)
			hx::AddEq(this->angularVelocity,velocityDelta);
			HX_STACK_LINE(280)
			velocityDelta = (0.5 * ((::flixel::util::FlxVelocity_obj::computeVelocity(this->velocity->x,this->acceleration->x,this->drag->x,this->maxVelocity->x) - this->velocity->x)));
			HX_STACK_LINE(280)
			{
				HX_STACK_LINE(280)
				::flixel::util::FlxPoint _g = this->velocity;		HX_STACK_VAR(_g,"_g");
				HX_STACK_LINE(280)
				_g->set_x((_g->x + velocityDelta));
			}
			HX_STACK_LINE(280)
			delta = (this->velocity->x * dt);
			HX_STACK_LINE(280)
			{
				HX_STACK_LINE(280)
				::flixel::util::FlxPoint _g = this->velocity;		HX_STACK_VAR(_g,"_g");
				HX_STACK_LINE(280)
				_g->set_x((_g->x + velocityDelta));
			}
			HX_STACK_LINE(280)
			{
				HX_STACK_LINE(280)
				::flixel::FlxObject _g = hx::ObjectPtr<OBJ_>(this);		HX_STACK_VAR(_g,"_g");
				HX_STACK_LINE(280)
				_g->set_x((_g->x + delta));
			}
			HX_STACK_LINE(280)
			velocityDelta = (0.5 * ((::flixel::util::FlxVelocity_obj::computeVelocity(this->velocity->y,this->acceleration->y,this->drag->y,this->maxVelocity->y) - this->velocity->y)));
			HX_STACK_LINE(280)
			{
				HX_STACK_LINE(280)
				::flixel::util::FlxPoint _g = this->velocity;		HX_STACK_VAR(_g,"_g");
				HX_STACK_LINE(280)
				_g->set_y((_g->y + velocityDelta));
			}
			HX_STACK_LINE(280)
			delta = (this->velocity->y * dt);
			HX_STACK_LINE(280)
			{
				HX_STACK_LINE(280)
				::flixel::util::FlxPoint _g = this->velocity;		HX_STACK_VAR(_g,"_g");
				HX_STACK_LINE(280)
				_g->set_y((_g->y + velocityDelta));
			}
			HX_STACK_LINE(280)
			{
				HX_STACK_LINE(280)
				::flixel::FlxObject _g = hx::ObjectPtr<OBJ_>(this);		HX_STACK_VAR(_g,"_g");
				HX_STACK_LINE(280)
				_g->set_y((_g->y + delta));
			}
		}
		HX_STACK_LINE(283)
		this->wasTouching = this->touching;
		HX_STACK_LINE(284)
		this->touching = (int)0;
	}
return null();
}


Void FlxObject_obj::updateMotion( ){
{
		HX_STACK_FRAME("flixel.FlxObject","updateMotion",0x420d82ce,"flixel.FlxObject.updateMotion","flixel/FlxObject.hx",292,0xf0fe0d80)
		HX_STACK_THIS(this)
		HX_STACK_LINE(293)
		Float delta;		HX_STACK_VAR(delta,"delta");
		HX_STACK_LINE(294)
		Float velocityDelta;		HX_STACK_VAR(velocityDelta,"velocityDelta");
		HX_STACK_LINE(296)
		Float dt = ::flixel::FlxG_obj::elapsed;		HX_STACK_VAR(dt,"dt");
		HX_STACK_LINE(298)
		velocityDelta = (0.5 * ((::flixel::util::FlxVelocity_obj::computeVelocity(this->angularVelocity,this->angularAcceleration,this->angularDrag,this->maxAngular) - this->angularVelocity)));
		HX_STACK_LINE(299)
		hx::AddEq(this->angularVelocity,velocityDelta);
		HX_STACK_LINE(300)
		{
			HX_STACK_LINE(300)
			::flixel::FlxObject _g = hx::ObjectPtr<OBJ_>(this);		HX_STACK_VAR(_g,"_g");
			HX_STACK_LINE(300)
			_g->set_angle((_g->angle + (this->angularVelocity * dt)));
		}
		HX_STACK_LINE(301)
		hx::AddEq(this->angularVelocity,velocityDelta);
		HX_STACK_LINE(303)
		velocityDelta = (0.5 * ((::flixel::util::FlxVelocity_obj::computeVelocity(this->velocity->x,this->acceleration->x,this->drag->x,this->maxVelocity->x) - this->velocity->x)));
		HX_STACK_LINE(304)
		{
			HX_STACK_LINE(304)
			::flixel::util::FlxPoint _g = this->velocity;		HX_STACK_VAR(_g,"_g");
			HX_STACK_LINE(304)
			_g->set_x((_g->x + velocityDelta));
		}
		HX_STACK_LINE(305)
		delta = (this->velocity->x * dt);
		HX_STACK_LINE(306)
		{
			HX_STACK_LINE(306)
			::flixel::util::FlxPoint _g = this->velocity;		HX_STACK_VAR(_g,"_g");
			HX_STACK_LINE(306)
			_g->set_x((_g->x + velocityDelta));
		}
		HX_STACK_LINE(307)
		{
			HX_STACK_LINE(307)
			::flixel::FlxObject _g = hx::ObjectPtr<OBJ_>(this);		HX_STACK_VAR(_g,"_g");
			HX_STACK_LINE(307)
			_g->set_x((_g->x + delta));
		}
		HX_STACK_LINE(309)
		velocityDelta = (0.5 * ((::flixel::util::FlxVelocity_obj::computeVelocity(this->velocity->y,this->acceleration->y,this->drag->y,this->maxVelocity->y) - this->velocity->y)));
		HX_STACK_LINE(310)
		{
			HX_STACK_LINE(310)
			::flixel::util::FlxPoint _g = this->velocity;		HX_STACK_VAR(_g,"_g");
			HX_STACK_LINE(310)
			_g->set_y((_g->y + velocityDelta));
		}
		HX_STACK_LINE(311)
		delta = (this->velocity->y * dt);
		HX_STACK_LINE(312)
		{
			HX_STACK_LINE(312)
			::flixel::util::FlxPoint _g = this->velocity;		HX_STACK_VAR(_g,"_g");
			HX_STACK_LINE(312)
			_g->set_y((_g->y + velocityDelta));
		}
		HX_STACK_LINE(313)
		{
			HX_STACK_LINE(313)
			::flixel::FlxObject _g = hx::ObjectPtr<OBJ_>(this);		HX_STACK_VAR(_g,"_g");
			HX_STACK_LINE(313)
			_g->set_y((_g->y + delta));
		}
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC0(FlxObject_obj,updateMotion,(void))

Void FlxObject_obj::draw( ){
{
		HX_STACK_FRAME("flixel.FlxObject","draw",0x1f17bab3,"flixel.FlxObject.draw","flixel/FlxObject.hx",320,0xf0fe0d80)
		HX_STACK_THIS(this)
		HX_STACK_LINE(321)
		if (((this->cameras == null()))){
			HX_STACK_LINE(323)
			this->cameras = ::flixel::FlxG_obj::cameras->list;
		}
		HX_STACK_LINE(325)
		::flixel::FlxCamera camera;		HX_STACK_VAR(camera,"camera");
		HX_STACK_LINE(326)
		int i = (int)0;		HX_STACK_VAR(i,"i");
		HX_STACK_LINE(327)
		int l = this->cameras->length;		HX_STACK_VAR(l,"l");
		HX_STACK_LINE(328)
		while(((i < l))){
			HX_STACK_LINE(330)
			camera = this->cameras->__get((i)++).StaticCast< ::flixel::FlxCamera >();
			HX_STACK_LINE(331)
			if (((  ((!(((bool(!(camera->visible)) || bool(!(camera->exists))))))) ? bool(!(this->isOnScreen(camera))) : bool(true) ))){
				HX_STACK_LINE(333)
				continue;
			}
			HX_STACK_LINE(337)
			(::flixel::FlxBasic_obj::_VISIBLECOUNT)++;
		}
	}
return null();
}


Void FlxObject_obj::drawDebugOnCamera( ::flixel::FlxCamera Camera){
{
		HX_STACK_FRAME("flixel.FlxObject","drawDebugOnCamera",0x0b2ef7e4,"flixel.FlxObject.drawDebugOnCamera","flixel/FlxObject.hx",350,0xf0fe0d80)
		HX_STACK_THIS(this)
		HX_STACK_ARG(Camera,"Camera")
		HX_STACK_LINE(351)
		if (((Camera == null()))){
			HX_STACK_LINE(353)
			Camera = ::flixel::FlxG_obj::camera;
		}
		HX_STACK_LINE(356)
		if (((  ((!(((bool(!(Camera->visible)) || bool(!(Camera->exists))))))) ? bool(!(this->isOnScreen(Camera))) : bool(true) ))){
			HX_STACK_LINE(358)
			return null();
		}
		HX_STACK_LINE(362)
		Float boundingBoxX = (this->x - (Camera->scroll->x * this->scrollFactor->x));		HX_STACK_VAR(boundingBoxX,"boundingBoxX");
		HX_STACK_LINE(363)
		Float boundingBoxY = (this->y - (Camera->scroll->y * this->scrollFactor->y));		HX_STACK_VAR(boundingBoxY,"boundingBoxY");
		HX_STACK_LINE(369)
		if (((bool((this->allowCollisions != (int)0)) && bool(!(this->_boundingBoxColorOverritten))))){
			HX_STACK_LINE(371)
			if (((this->allowCollisions != (int)4369))){
				HX_STACK_LINE(373)
				this->set_debugBoundingBoxColor((int)-16181);
			}
			HX_STACK_LINE(375)
			if ((this->immovable)){
				HX_STACK_LINE(377)
				this->set_debugBoundingBoxColor((int)-16744448);
			}
			else{
				HX_STACK_LINE(381)
				this->set_debugBoundingBoxColor((int)-65536);
			}
		}
		else{
			HX_STACK_LINE(384)
			if ((!(this->_boundingBoxColorOverritten))){
				HX_STACK_LINE(386)
				this->set_debugBoundingBoxColor((int)-16776961);
			}
		}
		HX_STACK_LINE(402)
		::flash::display::Graphics gfx = Camera->debugLayer->get_graphics();		HX_STACK_VAR(gfx,"gfx");
		HX_STACK_LINE(403)
		gfx->lineStyle((int)1,this->debugBoundingBoxColor,0.5,null(),null(),null(),null(),null());
		HX_STACK_LINE(404)
		Float _g = this->get_width();		HX_STACK_VAR(_g,"_g");
		HX_STACK_LINE(404)
		gfx->drawRect(boundingBoxX,boundingBoxY,_g,this->get_height());
	}
return null();
}


bool FlxObject_obj::overlaps( ::flixel::FlxBasic ObjectOrGroup,hx::Null< bool >  __o_InScreenSpace,::flixel::FlxCamera Camera){
bool InScreenSpace = __o_InScreenSpace.Default(false);
	HX_STACK_FRAME("flixel.FlxObject","overlaps",0xaad0e53b,"flixel.FlxObject.overlaps","flixel/FlxObject.hx",418,0xf0fe0d80)
	HX_STACK_THIS(this)
	HX_STACK_ARG(ObjectOrGroup,"ObjectOrGroup")
	HX_STACK_ARG(InScreenSpace,"InScreenSpace")
	HX_STACK_ARG(Camera,"Camera")
{
		HX_STACK_LINE(419)
		if (((ObjectOrGroup->collisionType == ::flixel::system::FlxCollisionType_obj::SPRITEGROUP))){
			HX_STACK_LINE(421)
			ObjectOrGroup = ::Reflect_obj::field(ObjectOrGroup,HX_CSTRING("group"));
		}
		HX_STACK_LINE(424)
		if (((ObjectOrGroup->collisionType == ::flixel::system::FlxCollisionType_obj::GROUP))){
			HX_STACK_LINE(426)
			bool results = false;		HX_STACK_VAR(results,"results");
			HX_STACK_LINE(427)
			int i = (int)0;		HX_STACK_VAR(i,"i");
			HX_STACK_LINE(428)
			::flixel::FlxBasic basic;		HX_STACK_VAR(basic,"basic");
			HX_STACK_LINE(429)
			::flixel::group::FlxTypedGroup grp = ObjectOrGroup;		HX_STACK_VAR(grp,"grp");
			HX_STACK_LINE(430)
			Array< ::Dynamic > members = grp->get_members();		HX_STACK_VAR(members,"members");
			HX_STACK_LINE(431)
			while(((i < grp->length))){
				HX_STACK_LINE(433)
				basic = members->__get((i)++).StaticCast< ::flixel::FlxBasic >();
				HX_STACK_LINE(434)
				if (((  (((bool((basic != null())) && bool(basic->exists)))) ? bool(this->overlaps(basic,InScreenSpace,Camera)) : bool(false) ))){
					HX_STACK_LINE(436)
					results = true;
					HX_STACK_LINE(437)
					break;
				}
			}
			HX_STACK_LINE(440)
			return results;
		}
		HX_STACK_LINE(443)
		if (((ObjectOrGroup->collisionType == ::flixel::system::FlxCollisionType_obj::TILEMAP))){
			HX_STACK_LINE(447)
			return (hx::TCast< flixel::tile::FlxTilemap >::cast(ObjectOrGroup))->overlaps(hx::ObjectPtr<OBJ_>(this),InScreenSpace,Camera);
		}
		HX_STACK_LINE(450)
		::flixel::FlxObject object;		HX_STACK_VAR(object,"object");
		HX_STACK_LINE(450)
		object = hx::TCast< flixel::FlxObject >::cast(ObjectOrGroup);
		HX_STACK_LINE(451)
		if ((!(InScreenSpace))){
			HX_STACK_LINE(453)
			if (((  (((  ((((object->x + object->get_width()) > this->x))) ? bool((object->x < (this->x + this->get_width()))) : bool(false) ))) ? bool(((object->y + object->get_height()) > this->y)) : bool(false) ))){
				HX_STACK_LINE(454)
				return (object->y < (this->y + this->get_height()));
			}
			else{
				HX_STACK_LINE(453)
				return false;
			}
		}
		HX_STACK_LINE(457)
		if (((Camera == null()))){
			HX_STACK_LINE(459)
			Camera = ::flixel::FlxG_obj::camera;
		}
		HX_STACK_LINE(461)
		::flixel::util::FlxPoint objectScreenPos = object->getScreenXY(null(),Camera);		HX_STACK_VAR(objectScreenPos,"objectScreenPos");
		HX_STACK_LINE(462)
		this->getScreenXY(this->_point,Camera);
		HX_STACK_LINE(463)
		if (((  (((  ((((objectScreenPos->x + object->get_width()) > this->_point->x))) ? bool((objectScreenPos->x < (this->_point->x + this->get_width()))) : bool(false) ))) ? bool(((objectScreenPos->y + object->get_height()) > this->_point->y)) : bool(false) ))){
			HX_STACK_LINE(464)
			return (objectScreenPos->y < (this->_point->y + this->get_height()));
		}
		else{
			HX_STACK_LINE(463)
			return false;
		}
		HX_STACK_LINE(463)
		return false;
	}
}


HX_DEFINE_DYNAMIC_FUNC3(FlxObject_obj,overlaps,return )

bool FlxObject_obj::overlapsAt( Float X,Float Y,::flixel::FlxBasic ObjectOrGroup,hx::Null< bool >  __o_InScreenSpace,::flixel::FlxCamera Camera){
bool InScreenSpace = __o_InScreenSpace.Default(false);
	HX_STACK_FRAME("flixel.FlxObject","overlapsAt",0xacc1230e,"flixel.FlxObject.overlapsAt","flixel/FlxObject.hx",478,0xf0fe0d80)
	HX_STACK_THIS(this)
	HX_STACK_ARG(X,"X")
	HX_STACK_ARG(Y,"Y")
	HX_STACK_ARG(ObjectOrGroup,"ObjectOrGroup")
	HX_STACK_ARG(InScreenSpace,"InScreenSpace")
	HX_STACK_ARG(Camera,"Camera")
{
		HX_STACK_LINE(479)
		if (((ObjectOrGroup->collisionType == ::flixel::system::FlxCollisionType_obj::SPRITEGROUP))){
			HX_STACK_LINE(481)
			ObjectOrGroup = ::Reflect_obj::field(ObjectOrGroup,HX_CSTRING("group"));
		}
		HX_STACK_LINE(484)
		if (((ObjectOrGroup->collisionType == ::flixel::system::FlxCollisionType_obj::GROUP))){
			HX_STACK_LINE(486)
			bool results = false;		HX_STACK_VAR(results,"results");
			HX_STACK_LINE(487)
			::flixel::FlxBasic basic;		HX_STACK_VAR(basic,"basic");
			HX_STACK_LINE(488)
			int i = (int)0;		HX_STACK_VAR(i,"i");
			HX_STACK_LINE(489)
			::flixel::group::FlxTypedGroup grp = ObjectOrGroup;		HX_STACK_VAR(grp,"grp");
			HX_STACK_LINE(490)
			Array< ::Dynamic > members = grp->get_members();		HX_STACK_VAR(members,"members");
			HX_STACK_LINE(491)
			while(((i < ::Std_obj::_int(grp->length)))){
				HX_STACK_LINE(493)
				basic = members->__get((i)++).StaticCast< ::flixel::FlxBasic >();
				HX_STACK_LINE(494)
				if (((  (((bool((basic != null())) && bool(basic->exists)))) ? bool(this->overlapsAt(X,Y,basic,InScreenSpace,Camera)) : bool(false) ))){
					HX_STACK_LINE(496)
					results = true;
					HX_STACK_LINE(497)
					break;
				}
			}
			HX_STACK_LINE(500)
			return results;
		}
		HX_STACK_LINE(503)
		if (((ObjectOrGroup->collisionType == ::flixel::system::FlxCollisionType_obj::TILEMAP))){
			HX_STACK_LINE(509)
			::flixel::tile::FlxTilemap tilemap;		HX_STACK_VAR(tilemap,"tilemap");
			HX_STACK_LINE(509)
			tilemap = hx::TCast< flixel::tile::FlxTilemap >::cast(ObjectOrGroup);
			HX_STACK_LINE(510)
			return tilemap->overlapsAt((tilemap->x - ((X - this->x))),(tilemap->y - ((Y - this->y))),hx::ObjectPtr<OBJ_>(this),InScreenSpace,Camera);
		}
		HX_STACK_LINE(513)
		::flixel::FlxObject object;		HX_STACK_VAR(object,"object");
		HX_STACK_LINE(513)
		object = hx::TCast< flixel::FlxObject >::cast(ObjectOrGroup);
		HX_STACK_LINE(514)
		if ((!(InScreenSpace))){
			HX_STACK_LINE(516)
			if (((  (((  ((((object->x + object->get_width()) > X))) ? bool((object->x < (X + this->get_width()))) : bool(false) ))) ? bool(((object->y + object->get_height()) > Y)) : bool(false) ))){
				HX_STACK_LINE(517)
				return (object->y < (Y + this->get_height()));
			}
			else{
				HX_STACK_LINE(516)
				return false;
			}
		}
		HX_STACK_LINE(520)
		if (((Camera == null()))){
			HX_STACK_LINE(522)
			Camera = ::flixel::FlxG_obj::camera;
		}
		HX_STACK_LINE(524)
		::flixel::util::FlxPoint objectScreenPos = object->getScreenXY(null(),Camera);		HX_STACK_VAR(objectScreenPos,"objectScreenPos");
		HX_STACK_LINE(525)
		this->getScreenXY(this->_point,Camera);
		HX_STACK_LINE(526)
		if (((  (((  ((((objectScreenPos->x + object->get_width()) > this->_point->x))) ? bool((objectScreenPos->x < (this->_point->x + this->get_width()))) : bool(false) ))) ? bool(((objectScreenPos->y + object->get_height()) > this->_point->y)) : bool(false) ))){
			HX_STACK_LINE(527)
			return (objectScreenPos->y < (this->_point->y + this->get_height()));
		}
		else{
			HX_STACK_LINE(526)
			return false;
		}
		HX_STACK_LINE(526)
		return false;
	}
}


HX_DEFINE_DYNAMIC_FUNC5(FlxObject_obj,overlapsAt,return )

bool FlxObject_obj::overlapsPoint( ::flixel::util::FlxPoint point,hx::Null< bool >  __o_InScreenSpace,::flixel::FlxCamera Camera){
bool InScreenSpace = __o_InScreenSpace.Default(false);
	HX_STACK_FRAME("flixel.FlxObject","overlapsPoint",0xcd9c6915,"flixel.FlxObject.overlapsPoint","flixel/FlxObject.hx",538,0xf0fe0d80)
	HX_STACK_THIS(this)
	HX_STACK_ARG(point,"point")
	HX_STACK_ARG(InScreenSpace,"InScreenSpace")
	HX_STACK_ARG(Camera,"Camera")
{
		HX_STACK_LINE(539)
		if ((!(InScreenSpace))){
			HX_STACK_LINE(541)
			if (((  (((  (((point->x > this->x))) ? bool((point->x < (this->x + this->get_width()))) : bool(false) ))) ? bool((point->y > this->y)) : bool(false) ))){
				HX_STACK_LINE(541)
				return (point->y < (this->y + this->get_height()));
			}
			else{
				HX_STACK_LINE(541)
				return false;
			}
		}
		HX_STACK_LINE(544)
		if (((Camera == null()))){
			HX_STACK_LINE(546)
			Camera = ::flixel::FlxG_obj::camera;
		}
		HX_STACK_LINE(548)
		Float X = (point->x - Camera->scroll->x);		HX_STACK_VAR(X,"X");
		HX_STACK_LINE(549)
		Float Y = (point->y - Camera->scroll->y);		HX_STACK_VAR(Y,"Y");
		HX_STACK_LINE(550)
		this->getScreenXY(this->_point,Camera);
		HX_STACK_LINE(551)
		if (((  (((  (((X > this->_point->x))) ? bool((X < (this->_point->x + this->get_width()))) : bool(false) ))) ? bool((Y > this->_point->y)) : bool(false) ))){
			HX_STACK_LINE(551)
			return (Y < (this->_point->y + this->get_height()));
		}
		else{
			HX_STACK_LINE(551)
			return false;
		}
		HX_STACK_LINE(551)
		return false;
	}
}


HX_DEFINE_DYNAMIC_FUNC3(FlxObject_obj,overlapsPoint,return )

bool FlxObject_obj::inWorldBounds( ){
	HX_STACK_FRAME("flixel.FlxObject","inWorldBounds",0x89d0e9f3,"flixel.FlxObject.inWorldBounds","flixel/FlxObject.hx",560,0xf0fe0d80)
	HX_STACK_THIS(this)
	HX_STACK_LINE(560)
	if (((  (((  ((((this->x + this->get_width()) > ::flixel::FlxG_obj::worldBounds->x))) ? bool((this->x < ::flixel::FlxG_obj::worldBounds->get_right())) : bool(false) ))) ? bool(((this->y + this->get_height()) > ::flixel::FlxG_obj::worldBounds->y)) : bool(false) ))){
		HX_STACK_LINE(560)
		return (this->y < ::flixel::FlxG_obj::worldBounds->get_bottom());
	}
	else{
		HX_STACK_LINE(560)
		return false;
	}
	HX_STACK_LINE(560)
	return false;
}


HX_DEFINE_DYNAMIC_FUNC0(FlxObject_obj,inWorldBounds,return )

::flixel::util::FlxPoint FlxObject_obj::getScreenXY( ::flixel::util::FlxPoint point,::flixel::FlxCamera Camera){
	HX_STACK_FRAME("flixel.FlxObject","getScreenXY",0x16aa3354,"flixel.FlxObject.getScreenXY","flixel/FlxObject.hx",570,0xf0fe0d80)
	HX_STACK_THIS(this)
	HX_STACK_ARG(point,"point")
	HX_STACK_ARG(Camera,"Camera")
	HX_STACK_LINE(571)
	if (((point == null()))){
		HX_STACK_LINE(573)
		point = ::flixel::util::FlxPoint_obj::__new(null(),null());
	}
	HX_STACK_LINE(575)
	if (((Camera == null()))){
		HX_STACK_LINE(577)
		Camera = ::flixel::FlxG_obj::camera;
	}
	HX_STACK_LINE(579)
	return point->set((this->x - (Camera->scroll->x * this->scrollFactor->x)),(this->y - (Camera->scroll->y * this->scrollFactor->y)));
}


HX_DEFINE_DYNAMIC_FUNC2(FlxObject_obj,getScreenXY,return )

::flixel::util::FlxPoint FlxObject_obj::getMidpoint( ::flixel::util::FlxPoint point){
	HX_STACK_FRAME("flixel.FlxObject","getMidpoint",0x7bfe0daf,"flixel.FlxObject.getMidpoint","flixel/FlxObject.hx",588,0xf0fe0d80)
	HX_STACK_THIS(this)
	HX_STACK_ARG(point,"point")
	HX_STACK_LINE(589)
	if (((point == null()))){
		HX_STACK_LINE(591)
		point = ::flixel::util::FlxPoint_obj::__new(null(),null());
	}
	HX_STACK_LINE(593)
	Float _g = (this->x + (this->get_width() * 0.5));		HX_STACK_VAR(_g,"_g");
	HX_STACK_LINE(593)
	return point->set(_g,(this->y + (this->get_height() * 0.5)));
}


HX_DEFINE_DYNAMIC_FUNC1(FlxObject_obj,getMidpoint,return )

Void FlxObject_obj::reset( Float X,Float Y){
{
		HX_STACK_FRAME("flixel.FlxObject","reset",0x1cbd9440,"flixel.FlxObject.reset","flixel/FlxObject.hx",603,0xf0fe0d80)
		HX_STACK_THIS(this)
		HX_STACK_ARG(X,"X")
		HX_STACK_ARG(Y,"Y")
		HX_STACK_LINE(604)
		this->revive();
		HX_STACK_LINE(605)
		this->touching = (int)0;
		HX_STACK_LINE(606)
		this->wasTouching = (int)0;
		HX_STACK_LINE(607)
		this->setPosition(X,Y);
		HX_STACK_LINE(608)
		this->last->set(this->x,this->y);
		HX_STACK_LINE(609)
		this->velocity->set(null(),null());
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC2(FlxObject_obj,reset,(void))

bool FlxObject_obj::isOnScreen( ::flixel::FlxCamera Camera){
	HX_STACK_FRAME("flixel.FlxObject","isOnScreen",0x4aab7fe4,"flixel.FlxObject.isOnScreen","flixel/FlxObject.hx",619,0xf0fe0d80)
	HX_STACK_THIS(this)
	HX_STACK_ARG(Camera,"Camera")
	HX_STACK_LINE(620)
	if (((Camera == null()))){
		HX_STACK_LINE(622)
		Camera = ::flixel::FlxG_obj::camera;
	}
	HX_STACK_LINE(624)
	this->getScreenXY(this->_point,Camera);
	HX_STACK_LINE(625)
	if (((  (((  ((((this->_point->x + this->get_width()) > (int)0))) ? bool((this->_point->x < Camera->width)) : bool(false) ))) ? bool(((this->_point->y + this->get_height()) > (int)0)) : bool(false) ))){
		HX_STACK_LINE(625)
		return (this->_point->y < Camera->height);
	}
	else{
		HX_STACK_LINE(625)
		return false;
	}
	HX_STACK_LINE(625)
	return false;
}


HX_DEFINE_DYNAMIC_FUNC1(FlxObject_obj,isOnScreen,return )

bool FlxObject_obj::isTouching( int Direction){
	HX_STACK_FRAME("flixel.FlxObject","isTouching",0x23c6647c,"flixel.FlxObject.isTouching","flixel/FlxObject.hx",635,0xf0fe0d80)
	HX_STACK_THIS(this)
	HX_STACK_ARG(Direction,"Direction")
	HX_STACK_LINE(635)
	return (((int(this->touching) & int(Direction))) > (int)0);
}


HX_DEFINE_DYNAMIC_FUNC1(FlxObject_obj,isTouching,return )

bool FlxObject_obj::justTouched( int Direction){
	HX_STACK_FRAME("flixel.FlxObject","justTouched",0xbcba8e43,"flixel.FlxObject.justTouched","flixel/FlxObject.hx",645,0xf0fe0d80)
	HX_STACK_THIS(this)
	HX_STACK_ARG(Direction,"Direction")
	HX_STACK_LINE(645)
	return (bool((((int(this->touching) & int(Direction))) > (int)0)) && bool((((int(this->wasTouching) & int(Direction))) <= (int)0)));
}


HX_DEFINE_DYNAMIC_FUNC1(FlxObject_obj,justTouched,return )

Void FlxObject_obj::hurt( Float Damage){
{
		HX_STACK_FRAME("flixel.FlxObject","hurt",0x21beeabe,"flixel.FlxObject.hurt","flixel/FlxObject.hx",654,0xf0fe0d80)
		HX_STACK_THIS(this)
		HX_STACK_ARG(Damage,"Damage")
		HX_STACK_LINE(655)
		this->health = (this->health - Damage);
		HX_STACK_LINE(656)
		if (((this->health <= (int)0))){
			HX_STACK_LINE(658)
			this->kill();
		}
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC1(FlxObject_obj,hurt,(void))

Void FlxObject_obj::setPosition( hx::Null< Float >  __o_X,hx::Null< Float >  __o_Y){
Float X = __o_X.Default(0);
Float Y = __o_Y.Default(0);
	HX_STACK_FRAME("flixel.FlxObject","setPosition",0x265d9f9c,"flixel.FlxObject.setPosition","flixel/FlxObject.hx",916,0xf0fe0d80)
	HX_STACK_THIS(this)
	HX_STACK_ARG(X,"X")
	HX_STACK_ARG(Y,"Y")
{
		HX_STACK_LINE(917)
		this->set_x(X);
		HX_STACK_LINE(918)
		this->set_y(Y);
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC2(FlxObject_obj,setPosition,(void))

Void FlxObject_obj::setSize( Float Width,Float Height){
{
		HX_STACK_FRAME("flixel.FlxObject","setSize",0xa7896a34,"flixel.FlxObject.setSize","flixel/FlxObject.hx",927,0xf0fe0d80)
		HX_STACK_THIS(this)
		HX_STACK_ARG(Width,"Width")
		HX_STACK_ARG(Height,"Height")
		HX_STACK_LINE(928)
		this->set_width(Width);
		HX_STACK_LINE(929)
		this->set_height(Height);
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC2(FlxObject_obj,setSize,(void))

::flixel::util::loaders::CachedGraphics FlxObject_obj::set_cachedGraphics( ::flixel::util::loaders::CachedGraphics Value){
	HX_STACK_FRAME("flixel.FlxObject","set_cachedGraphics",0xa3f11cf9,"flixel.FlxObject.set_cachedGraphics","flixel/FlxObject.hx",938,0xf0fe0d80)
	HX_STACK_THIS(this)
	HX_STACK_ARG(Value,"Value")
	HX_STACK_LINE(939)
	::flixel::util::loaders::CachedGraphics oldCached = this->cachedGraphics;		HX_STACK_VAR(oldCached,"oldCached");
	HX_STACK_LINE(941)
	if (((bool((this->cachedGraphics != Value)) && bool((Value != null()))))){
		HX_STACK_LINE(943)
		::flixel::util::loaders::CachedGraphics _g = Value;		HX_STACK_VAR(_g,"_g");
		HX_STACK_LINE(943)
		int _g1 = _g->useCount;		HX_STACK_VAR(_g1,"_g1");
		HX_STACK_LINE(943)
		_g->set_useCount((_g1 + (int)1));
		HX_STACK_LINE(943)
		_g1;
	}
	HX_STACK_LINE(946)
	if (((bool((oldCached != null())) && bool((oldCached != Value))))){
		HX_STACK_LINE(948)
		::flixel::util::loaders::CachedGraphics _g = oldCached;		HX_STACK_VAR(_g,"_g");
		HX_STACK_LINE(948)
		int _g1 = _g->useCount;		HX_STACK_VAR(_g1,"_g1");
		HX_STACK_LINE(948)
		_g->set_useCount((_g1 - (int)1));
		HX_STACK_LINE(948)
		_g1;
	}
	HX_STACK_LINE(951)
	return this->cachedGraphics = Value;
}


HX_DEFINE_DYNAMIC_FUNC1(FlxObject_obj,set_cachedGraphics,return )

Float FlxObject_obj::set_x( Float NewX){
	HX_STACK_FRAME("flixel.FlxObject","set_x",0xb024e5cc,"flixel.FlxObject.set_x","flixel/FlxObject.hx",959,0xf0fe0d80)
	HX_STACK_THIS(this)
	HX_STACK_ARG(NewX,"NewX")
	HX_STACK_LINE(959)
	return this->x = NewX;
}


HX_DEFINE_DYNAMIC_FUNC1(FlxObject_obj,set_x,return )

Float FlxObject_obj::set_y( Float NewY){
	HX_STACK_FRAME("flixel.FlxObject","set_y",0xb024e5cd,"flixel.FlxObject.set_y","flixel/FlxObject.hx",964,0xf0fe0d80)
	HX_STACK_THIS(this)
	HX_STACK_ARG(NewY,"NewY")
	HX_STACK_LINE(964)
	return this->y = NewY;
}


HX_DEFINE_DYNAMIC_FUNC1(FlxObject_obj,set_y,return )

Float FlxObject_obj::set_width( Float Width){
	HX_STACK_FRAME("flixel.FlxObject","set_width",0x7d06d55a,"flixel.FlxObject.set_width","flixel/FlxObject.hx",968,0xf0fe0d80)
	HX_STACK_THIS(this)
	HX_STACK_ARG(Width,"Width")
	HX_STACK_LINE(970)
	if (((Width < (int)0))){
		HX_STACK_LINE(972)
		::flixel::FlxG_obj::log->advanced(HX_CSTRING("An object's width cannot be smaller than 0. Use offset for sprites to control the hitbox position!"),::flixel::system::debug::LogStyle_obj::WARNING,true);
	}
	else{
		HX_STACK_LINE(977)
		this->width = Width;
	}
	HX_STACK_LINE(982)
	return Width;
}


HX_DEFINE_DYNAMIC_FUNC1(FlxObject_obj,set_width,return )

Float FlxObject_obj::set_height( Float Height){
	HX_STACK_FRAME("flixel.FlxObject","set_height",0x9f435213,"flixel.FlxObject.set_height","flixel/FlxObject.hx",986,0xf0fe0d80)
	HX_STACK_THIS(this)
	HX_STACK_ARG(Height,"Height")
	HX_STACK_LINE(988)
	if (((Height < (int)0))){
		HX_STACK_LINE(990)
		::flixel::FlxG_obj::log->advanced(HX_CSTRING("An object's height cannot be smaller than 0. Use offset for sprites to control the hitbox position!"),::flixel::system::debug::LogStyle_obj::WARNING,true);
	}
	else{
		HX_STACK_LINE(995)
		this->height = Height;
	}
	HX_STACK_LINE(1000)
	return Height;
}


HX_DEFINE_DYNAMIC_FUNC1(FlxObject_obj,set_height,return )

Float FlxObject_obj::get_width( ){
	HX_STACK_FRAME("flixel.FlxObject","get_width",0x99b5e94e,"flixel.FlxObject.get_width","flixel/FlxObject.hx",1005,0xf0fe0d80)
	HX_STACK_THIS(this)
	HX_STACK_LINE(1005)
	return this->width;
}


HX_DEFINE_DYNAMIC_FUNC0(FlxObject_obj,get_width,return )

Float FlxObject_obj::get_height( ){
	HX_STACK_FRAME("flixel.FlxObject","get_height",0x9bc5b39f,"flixel.FlxObject.get_height","flixel/FlxObject.hx",1010,0xf0fe0d80)
	HX_STACK_THIS(this)
	HX_STACK_LINE(1010)
	return this->height;
}


HX_DEFINE_DYNAMIC_FUNC0(FlxObject_obj,get_height,return )

bool FlxObject_obj::get_solid( ){
	HX_STACK_FRAME("flixel.FlxObject","get_solid",0x5018e773,"flixel.FlxObject.get_solid","flixel/FlxObject.hx",1015,0xf0fe0d80)
	HX_STACK_THIS(this)
	HX_STACK_LINE(1015)
	return (((int(this->allowCollisions) & int((int)4369))) > (int)0);
}


HX_DEFINE_DYNAMIC_FUNC0(FlxObject_obj,get_solid,return )

bool FlxObject_obj::set_solid( bool Solid){
	HX_STACK_FRAME("flixel.FlxObject","set_solid",0x3369d37f,"flixel.FlxObject.set_solid","flixel/FlxObject.hx",1019,0xf0fe0d80)
	HX_STACK_THIS(this)
	HX_STACK_ARG(Solid,"Solid")
	HX_STACK_LINE(1020)
	if ((Solid)){
		HX_STACK_LINE(1022)
		this->allowCollisions = (int)4369;
	}
	else{
		HX_STACK_LINE(1026)
		this->allowCollisions = (int)0;
	}
	HX_STACK_LINE(1028)
	return Solid;
}


HX_DEFINE_DYNAMIC_FUNC1(FlxObject_obj,set_solid,return )

Float FlxObject_obj::set_angle( Float Value){
	HX_STACK_FRAME("flixel.FlxObject","set_angle",0xd5866327,"flixel.FlxObject.set_angle","flixel/FlxObject.hx",1033,0xf0fe0d80)
	HX_STACK_THIS(this)
	HX_STACK_ARG(Value,"Value")
	HX_STACK_LINE(1033)
	return this->angle = Value;
}


HX_DEFINE_DYNAMIC_FUNC1(FlxObject_obj,set_angle,return )

bool FlxObject_obj::set_moves( bool Value){
	HX_STACK_FRAME("flixel.FlxObject","set_moves",0xbf09eb96,"flixel.FlxObject.set_moves","flixel/FlxObject.hx",1038,0xf0fe0d80)
	HX_STACK_THIS(this)
	HX_STACK_ARG(Value,"Value")
	HX_STACK_LINE(1038)
	return this->moves = Value;
}


HX_DEFINE_DYNAMIC_FUNC1(FlxObject_obj,set_moves,return )

bool FlxObject_obj::set_immovable( bool Value){
	HX_STACK_FRAME("flixel.FlxObject","set_immovable",0xc5b8805e,"flixel.FlxObject.set_immovable","flixel/FlxObject.hx",1043,0xf0fe0d80)
	HX_STACK_THIS(this)
	HX_STACK_ARG(Value,"Value")
	HX_STACK_LINE(1043)
	return this->immovable = Value;
}


HX_DEFINE_DYNAMIC_FUNC1(FlxObject_obj,set_immovable,return )

bool FlxObject_obj::set_forceComplexRender( bool Value){
	HX_STACK_FRAME("flixel.FlxObject","set_forceComplexRender",0x98b66ce7,"flixel.FlxObject.set_forceComplexRender","flixel/FlxObject.hx",1048,0xf0fe0d80)
	HX_STACK_THIS(this)
	HX_STACK_ARG(Value,"Value")
	HX_STACK_LINE(1048)
	return this->forceComplexRender = Value;
}


HX_DEFINE_DYNAMIC_FUNC1(FlxObject_obj,set_forceComplexRender,return )

int FlxObject_obj::set_debugBoundingBoxColor( int Value){
	HX_STACK_FRAME("flixel.FlxObject","set_debugBoundingBoxColor",0x1a43fea3,"flixel.FlxObject.set_debugBoundingBoxColor","flixel/FlxObject.hx",1058,0xf0fe0d80)
	HX_STACK_THIS(this)
	HX_STACK_ARG(Value,"Value")
	HX_STACK_LINE(1059)
	this->_boundingBoxColorOverritten = true;
	HX_STACK_LINE(1060)
	return this->debugBoundingBoxColor = Value;
}


HX_DEFINE_DYNAMIC_FUNC1(FlxObject_obj,set_debugBoundingBoxColor,return )

::String FlxObject_obj::toString( ){
	HX_STACK_FRAME("flixel.FlxObject","toString",0x9e14e2db,"flixel.FlxObject.toString","flixel/FlxObject.hx",1070,0xf0fe0d80)
	HX_STACK_THIS(this)
	struct _Function_1_1{
		inline static Dynamic Block( ::flixel::FlxObject_obj *__this){
			HX_STACK_FRAME("*","closure",0x5bdab937,"*.closure","flixel/FlxObject.hx",1071,0xf0fe0d80)
			{
				hx::Anon __result = hx::Anon_obj::Create();
				__result->Add(HX_CSTRING("label") , HX_CSTRING("x"),false);
				__result->Add(HX_CSTRING("value") , __this->x,false);
				return __result;
			}
			return null();
		}
	};
	HX_STACK_LINE(1071)
	Dynamic _g = _Function_1_1::Block(this);		HX_STACK_VAR(_g,"_g");
	struct _Function_1_2{
		inline static Dynamic Block( ::flixel::FlxObject_obj *__this){
			HX_STACK_FRAME("*","closure",0x5bdab937,"*.closure","flixel/FlxObject.hx",1072,0xf0fe0d80)
			{
				hx::Anon __result = hx::Anon_obj::Create();
				__result->Add(HX_CSTRING("label") , HX_CSTRING("y"),false);
				__result->Add(HX_CSTRING("value") , __this->y,false);
				return __result;
			}
			return null();
		}
	};
	HX_STACK_LINE(1072)
	Dynamic _g1 = _Function_1_2::Block(this);		HX_STACK_VAR(_g1,"_g1");
	struct _Function_1_3{
		inline static Dynamic Block( ::flixel::FlxObject_obj *__this){
			HX_STACK_FRAME("*","closure",0x5bdab937,"*.closure","flixel/FlxObject.hx",1073,0xf0fe0d80)
			{
				hx::Anon __result = hx::Anon_obj::Create();
				__result->Add(HX_CSTRING("label") , HX_CSTRING("w"),false);
				__result->Add(HX_CSTRING("value") , __this->get_width(),false);
				return __result;
			}
			return null();
		}
	};
	HX_STACK_LINE(1073)
	Dynamic _g2 = _Function_1_3::Block(this);		HX_STACK_VAR(_g2,"_g2");
	struct _Function_1_4{
		inline static Dynamic Block( ::flixel::FlxObject_obj *__this){
			HX_STACK_FRAME("*","closure",0x5bdab937,"*.closure","flixel/FlxObject.hx",1074,0xf0fe0d80)
			{
				hx::Anon __result = hx::Anon_obj::Create();
				__result->Add(HX_CSTRING("label") , HX_CSTRING("h"),false);
				__result->Add(HX_CSTRING("value") , __this->get_height(),false);
				return __result;
			}
			return null();
		}
	};
	HX_STACK_LINE(1074)
	Dynamic _g3 = _Function_1_4::Block(this);		HX_STACK_VAR(_g3,"_g3");
	struct _Function_1_5{
		inline static Dynamic Block( ::flixel::FlxObject_obj *__this){
			HX_STACK_FRAME("*","closure",0x5bdab937,"*.closure","flixel/FlxObject.hx",1075,0xf0fe0d80)
			{
				hx::Anon __result = hx::Anon_obj::Create();
				__result->Add(HX_CSTRING("label") , HX_CSTRING("visible"),false);
				__result->Add(HX_CSTRING("value") , __this->visible,false);
				return __result;
			}
			return null();
		}
	};
	HX_STACK_LINE(1075)
	Dynamic _g4 = _Function_1_5::Block(this);		HX_STACK_VAR(_g4,"_g4");
	struct _Function_1_6{
		inline static Dynamic Block( ::flixel::FlxObject_obj *__this){
			HX_STACK_FRAME("*","closure",0x5bdab937,"*.closure","flixel/FlxObject.hx",1076,0xf0fe0d80)
			{
				hx::Anon __result = hx::Anon_obj::Create();
				__result->Add(HX_CSTRING("label") , HX_CSTRING("velocity"),false);
				__result->Add(HX_CSTRING("value") , __this->velocity,false);
				return __result;
			}
			return null();
		}
	};
	HX_STACK_LINE(1071)
	return ::flixel::util::FlxStringUtil_obj::getDebugString(Dynamic( Array_obj<Dynamic>::__new().Add(_g).Add(_g1).Add(_g2).Add(_g3).Add(_g4).Add(_Function_1_6::Block(this))));
}


Float FlxObject_obj::SEPARATE_BIAS;

int FlxObject_obj::LEFT;

int FlxObject_obj::RIGHT;

int FlxObject_obj::UP;

int FlxObject_obj::DOWN;

int FlxObject_obj::NONE;

int FlxObject_obj::CEILING;

int FlxObject_obj::FLOOR;

int FlxObject_obj::WALL;

int FlxObject_obj::ANY;

::flixel::util::FlxPoint FlxObject_obj::_pZero;

::flixel::util::FlxRect FlxObject_obj::_firstSeparateFlxRect;

::flixel::util::FlxRect FlxObject_obj::_secondSeparateFlxRect;

bool FlxObject_obj::separate( ::flixel::FlxObject Object1,::flixel::FlxObject Object2){
	HX_STACK_FRAME("flixel.FlxObject","separate",0x6cc23192,"flixel.FlxObject.separate","flixel/FlxObject.hx",669,0xf0fe0d80)
	HX_STACK_ARG(Object1,"Object1")
	HX_STACK_ARG(Object2,"Object2")
	HX_STACK_LINE(670)
	bool separatedX = ::flixel::FlxObject_obj::separateX(Object1,Object2);		HX_STACK_VAR(separatedX,"separatedX");
	HX_STACK_LINE(671)
	bool separatedY = ::flixel::FlxObject_obj::separateY(Object1,Object2);		HX_STACK_VAR(separatedY,"separatedY");
	HX_STACK_LINE(672)
	return (bool(separatedX) || bool(separatedY));
}


STATIC_HX_DEFINE_DYNAMIC_FUNC2(FlxObject_obj,separate,return )

bool FlxObject_obj::separateX( ::flixel::FlxObject Object1,::flixel::FlxObject Object2){
	HX_STACK_FRAME("flixel.FlxObject","separateX",0xbd292e86,"flixel.FlxObject.separateX","flixel/FlxObject.hx",682,0xf0fe0d80)
	HX_STACK_ARG(Object1,"Object1")
	HX_STACK_ARG(Object2,"Object2")
	HX_STACK_LINE(684)
	bool obj1immovable = Object1->immovable;		HX_STACK_VAR(obj1immovable,"obj1immovable");
	HX_STACK_LINE(685)
	bool obj2immovable = Object2->immovable;		HX_STACK_VAR(obj2immovable,"obj2immovable");
	HX_STACK_LINE(686)
	if (((bool(obj1immovable) && bool(obj2immovable)))){
		HX_STACK_LINE(688)
		return false;
	}
	HX_STACK_LINE(692)
	if (((Object1->collisionType == ::flixel::system::FlxCollisionType_obj::TILEMAP))){
		HX_STACK_LINE(694)
		return (hx::TCast< flixel::tile::FlxTilemap >::cast(Object1))->overlapsWithCallback(Object2,::flixel::FlxObject_obj::separateX_dyn(),null(),null());
	}
	HX_STACK_LINE(696)
	if (((Object2->collisionType == ::flixel::system::FlxCollisionType_obj::TILEMAP))){
		HX_STACK_LINE(698)
		return (hx::TCast< flixel::tile::FlxTilemap >::cast(Object2))->overlapsWithCallback(Object1,::flixel::FlxObject_obj::separateX_dyn(),true,null());
	}
	HX_STACK_LINE(702)
	Float overlap = (int)0;		HX_STACK_VAR(overlap,"overlap");
	HX_STACK_LINE(703)
	Float obj1delta = (Object1->x - Object1->last->x);		HX_STACK_VAR(obj1delta,"obj1delta");
	HX_STACK_LINE(704)
	Float obj2delta = (Object2->x - Object2->last->x);		HX_STACK_VAR(obj2delta,"obj2delta");
	HX_STACK_LINE(706)
	if (((obj1delta != obj2delta))){
		HX_STACK_LINE(709)
		Float obj1deltaAbs;		HX_STACK_VAR(obj1deltaAbs,"obj1deltaAbs");
		HX_STACK_LINE(709)
		if (((obj1delta > (int)0))){
			HX_STACK_LINE(709)
			obj1deltaAbs = obj1delta;
		}
		else{
			HX_STACK_LINE(709)
			obj1deltaAbs = -(obj1delta);
		}
		HX_STACK_LINE(710)
		Float obj2deltaAbs;		HX_STACK_VAR(obj2deltaAbs,"obj2deltaAbs");
		HX_STACK_LINE(710)
		if (((obj2delta > (int)0))){
			HX_STACK_LINE(710)
			obj2deltaAbs = obj2delta;
		}
		else{
			HX_STACK_LINE(710)
			obj2deltaAbs = -(obj2delta);
		}
		HX_STACK_LINE(712)
		::flixel::util::FlxRect obj1rect;		HX_STACK_VAR(obj1rect,"obj1rect");
		HX_STACK_LINE(712)
		{
			HX_STACK_LINE(712)
			::flixel::util::FlxRect _this = ::flixel::FlxObject_obj::_firstSeparateFlxRect;		HX_STACK_VAR(_this,"_this");
			HX_STACK_LINE(712)
			Float _g = Object1->get_width();		HX_STACK_VAR(_g,"_g");
			HX_STACK_LINE(712)
			Float Width;		HX_STACK_VAR(Width,"Width");
			HX_STACK_LINE(712)
			Width = (_g + ((  (((obj1delta > (int)0))) ? Float(obj1delta) : Float(-(obj1delta)) )));
			HX_STACK_LINE(712)
			Float Height = Object1->get_height();		HX_STACK_VAR(Height,"Height");
			HX_STACK_LINE(712)
			_this->x = (Object1->x - ((  (((obj1delta > (int)0))) ? Float(obj1delta) : Float((int)0) )));
			HX_STACK_LINE(712)
			_this->y = Object1->last->y;
			HX_STACK_LINE(712)
			_this->width = Width;
			HX_STACK_LINE(712)
			_this->height = Height;
			HX_STACK_LINE(712)
			obj1rect = _this;
		}
		HX_STACK_LINE(713)
		::flixel::util::FlxRect obj2rect;		HX_STACK_VAR(obj2rect,"obj2rect");
		HX_STACK_LINE(713)
		{
			HX_STACK_LINE(713)
			::flixel::util::FlxRect _this = ::flixel::FlxObject_obj::_secondSeparateFlxRect;		HX_STACK_VAR(_this,"_this");
			HX_STACK_LINE(713)
			Float _g1 = Object2->get_width();		HX_STACK_VAR(_g1,"_g1");
			HX_STACK_LINE(713)
			Float Width;		HX_STACK_VAR(Width,"Width");
			HX_STACK_LINE(713)
			Width = (_g1 + ((  (((obj2delta > (int)0))) ? Float(obj2delta) : Float(-(obj2delta)) )));
			HX_STACK_LINE(713)
			Float Height = Object2->get_height();		HX_STACK_VAR(Height,"Height");
			HX_STACK_LINE(713)
			_this->x = (Object2->x - ((  (((obj2delta > (int)0))) ? Float(obj2delta) : Float((int)0) )));
			HX_STACK_LINE(713)
			_this->y = Object2->last->y;
			HX_STACK_LINE(713)
			_this->width = Width;
			HX_STACK_LINE(713)
			_this->height = Height;
			HX_STACK_LINE(713)
			obj2rect = _this;
		}
		HX_STACK_LINE(715)
		if (((bool((bool((bool(((obj1rect->x + obj1rect->width) > obj2rect->x)) && bool((obj1rect->x < (obj2rect->x + obj2rect->width))))) && bool(((obj1rect->y + obj1rect->height) > obj2rect->y)))) && bool((obj1rect->y < (obj2rect->y + obj2rect->height)))))){
			HX_STACK_LINE(717)
			Float maxOverlap = ((obj1deltaAbs + obj2deltaAbs) + ::flixel::FlxObject_obj::SEPARATE_BIAS);		HX_STACK_VAR(maxOverlap,"maxOverlap");
			HX_STACK_LINE(720)
			if (((obj1delta > obj2delta))){
				HX_STACK_LINE(722)
				overlap = ((Object1->x + Object1->get_width()) - Object2->x);
				HX_STACK_LINE(723)
				if (((bool((bool((overlap > maxOverlap)) || bool((((int(Object1->allowCollisions) & int((int)16))) == (int)0)))) || bool((((int(Object2->allowCollisions) & int((int)1))) == (int)0))))){
					HX_STACK_LINE(725)
					overlap = (int)0;
				}
				else{
					HX_STACK_LINE(729)
					hx::OrEq(Object1->touching,(int)16);
					HX_STACK_LINE(730)
					hx::OrEq(Object2->touching,(int)1);
				}
			}
			else{
				HX_STACK_LINE(733)
				if (((obj1delta < obj2delta))){
					HX_STACK_LINE(735)
					overlap = ((Object1->x - Object2->get_width()) - Object2->x);
					HX_STACK_LINE(736)
					if (((bool((bool((-(overlap) > maxOverlap)) || bool((((int(Object1->allowCollisions) & int((int)1))) == (int)0)))) || bool((((int(Object2->allowCollisions) & int((int)16))) == (int)0))))){
						HX_STACK_LINE(738)
						overlap = (int)0;
					}
					else{
						HX_STACK_LINE(742)
						hx::OrEq(Object1->touching,(int)1);
						HX_STACK_LINE(743)
						hx::OrEq(Object2->touching,(int)16);
					}
				}
			}
		}
	}
	HX_STACK_LINE(750)
	if (((overlap != (int)0))){
		HX_STACK_LINE(752)
		Float obj1v = Object1->velocity->x;		HX_STACK_VAR(obj1v,"obj1v");
		HX_STACK_LINE(753)
		Float obj2v = Object2->velocity->x;		HX_STACK_VAR(obj2v,"obj2v");
		HX_STACK_LINE(755)
		if (((bool(!(obj1immovable)) && bool(!(obj2immovable))))){
			HX_STACK_LINE(757)
			hx::MultEq(overlap,0.5);
			HX_STACK_LINE(758)
			Object1->set_x((Object1->x - overlap));
			HX_STACK_LINE(759)
			{
				HX_STACK_LINE(759)
				::flixel::FlxObject _g = Object2;		HX_STACK_VAR(_g,"_g");
				HX_STACK_LINE(759)
				_g->set_x((_g->x + overlap));
			}
			HX_STACK_LINE(761)
			Float _g2 = ::Math_obj::sqrt((Float(((obj2v * obj2v) * Object2->mass)) / Float(Object1->mass)));		HX_STACK_VAR(_g2,"_g2");
			HX_STACK_LINE(761)
			Float obj1velocity;		HX_STACK_VAR(obj1velocity,"obj1velocity");
			HX_STACK_LINE(761)
			obj1velocity = (_g2 * ((  (((obj2v > (int)0))) ? int((int)1) : int((int)-1) )));
			HX_STACK_LINE(762)
			Float _g3 = ::Math_obj::sqrt((Float(((obj1v * obj1v) * Object1->mass)) / Float(Object2->mass)));		HX_STACK_VAR(_g3,"_g3");
			HX_STACK_LINE(762)
			Float obj2velocity;		HX_STACK_VAR(obj2velocity,"obj2velocity");
			HX_STACK_LINE(762)
			obj2velocity = (_g3 * ((  (((obj1v > (int)0))) ? int((int)1) : int((int)-1) )));
			HX_STACK_LINE(763)
			Float average = (((obj1velocity + obj2velocity)) * 0.5);		HX_STACK_VAR(average,"average");
			HX_STACK_LINE(764)
			hx::SubEq(obj1velocity,average);
			HX_STACK_LINE(765)
			hx::SubEq(obj2velocity,average);
			HX_STACK_LINE(766)
			Object1->velocity->set_x((average + (obj1velocity * Object1->elasticity)));
			HX_STACK_LINE(767)
			Object2->velocity->set_x((average + (obj2velocity * Object2->elasticity)));
		}
		else{
			HX_STACK_LINE(769)
			if ((!(obj1immovable))){
				HX_STACK_LINE(771)
				Object1->set_x((Object1->x - overlap));
				HX_STACK_LINE(772)
				Object1->velocity->set_x((obj2v - (obj1v * Object1->elasticity)));
			}
			else{
				HX_STACK_LINE(774)
				if ((!(obj2immovable))){
					HX_STACK_LINE(776)
					{
						HX_STACK_LINE(776)
						::flixel::FlxObject _g = Object2;		HX_STACK_VAR(_g,"_g");
						HX_STACK_LINE(776)
						_g->set_x((_g->x + overlap));
					}
					HX_STACK_LINE(777)
					Object2->velocity->set_x((obj1v - (obj2v * Object2->elasticity)));
				}
			}
		}
		HX_STACK_LINE(779)
		return true;
	}
	else{
		HX_STACK_LINE(783)
		return false;
	}
	HX_STACK_LINE(750)
	return false;
}


STATIC_HX_DEFINE_DYNAMIC_FUNC2(FlxObject_obj,separateX,return )

bool FlxObject_obj::separateY( ::flixel::FlxObject Object1,::flixel::FlxObject Object2){
	HX_STACK_FRAME("flixel.FlxObject","separateY",0xbd292e87,"flixel.FlxObject.separateY","flixel/FlxObject.hx",794,0xf0fe0d80)
	HX_STACK_ARG(Object1,"Object1")
	HX_STACK_ARG(Object2,"Object2")
	HX_STACK_LINE(796)
	bool obj1immovable = Object1->immovable;		HX_STACK_VAR(obj1immovable,"obj1immovable");
	HX_STACK_LINE(797)
	bool obj2immovable = Object2->immovable;		HX_STACK_VAR(obj2immovable,"obj2immovable");
	HX_STACK_LINE(798)
	if (((bool(obj1immovable) && bool(obj2immovable)))){
		HX_STACK_LINE(800)
		return false;
	}
	HX_STACK_LINE(804)
	if (((Object1->collisionType == ::flixel::system::FlxCollisionType_obj::TILEMAP))){
		HX_STACK_LINE(806)
		return (hx::TCast< flixel::tile::FlxTilemap >::cast(Object1))->overlapsWithCallback(Object2,::flixel::FlxObject_obj::separateY_dyn(),null(),null());
	}
	HX_STACK_LINE(808)
	if (((Object2->collisionType == ::flixel::system::FlxCollisionType_obj::TILEMAP))){
		HX_STACK_LINE(810)
		return (hx::TCast< flixel::tile::FlxTilemap >::cast(Object2))->overlapsWithCallback(Object1,::flixel::FlxObject_obj::separateY_dyn(),true,null());
	}
	HX_STACK_LINE(814)
	Float overlap = (int)0;		HX_STACK_VAR(overlap,"overlap");
	HX_STACK_LINE(815)
	Float obj1delta = (Object1->y - Object1->last->y);		HX_STACK_VAR(obj1delta,"obj1delta");
	HX_STACK_LINE(816)
	Float obj2delta = (Object2->y - Object2->last->y);		HX_STACK_VAR(obj2delta,"obj2delta");
	HX_STACK_LINE(818)
	if (((obj1delta != obj2delta))){
		HX_STACK_LINE(821)
		Float obj1deltaAbs;		HX_STACK_VAR(obj1deltaAbs,"obj1deltaAbs");
		HX_STACK_LINE(821)
		if (((obj1delta > (int)0))){
			HX_STACK_LINE(821)
			obj1deltaAbs = obj1delta;
		}
		else{
			HX_STACK_LINE(821)
			obj1deltaAbs = -(obj1delta);
		}
		HX_STACK_LINE(822)
		Float obj2deltaAbs;		HX_STACK_VAR(obj2deltaAbs,"obj2deltaAbs");
		HX_STACK_LINE(822)
		if (((obj2delta > (int)0))){
			HX_STACK_LINE(822)
			obj2deltaAbs = obj2delta;
		}
		else{
			HX_STACK_LINE(822)
			obj2deltaAbs = -(obj2delta);
		}
		HX_STACK_LINE(824)
		::flixel::util::FlxRect obj1rect;		HX_STACK_VAR(obj1rect,"obj1rect");
		HX_STACK_LINE(824)
		{
			HX_STACK_LINE(824)
			::flixel::util::FlxRect _this = ::flixel::FlxObject_obj::_firstSeparateFlxRect;		HX_STACK_VAR(_this,"_this");
			HX_STACK_LINE(824)
			Float Width = Object1->get_width();		HX_STACK_VAR(Width,"Width");
			HX_STACK_LINE(824)
			Float Height = (Object1->get_height() + obj1deltaAbs);		HX_STACK_VAR(Height,"Height");
			HX_STACK_LINE(824)
			_this->x = Object1->x;
			HX_STACK_LINE(824)
			_this->y = (Object1->y - ((  (((obj1delta > (int)0))) ? Float(obj1delta) : Float((int)0) )));
			HX_STACK_LINE(824)
			_this->width = Width;
			HX_STACK_LINE(824)
			_this->height = Height;
			HX_STACK_LINE(824)
			obj1rect = _this;
		}
		HX_STACK_LINE(825)
		::flixel::util::FlxRect obj2rect;		HX_STACK_VAR(obj2rect,"obj2rect");
		HX_STACK_LINE(825)
		{
			HX_STACK_LINE(825)
			::flixel::util::FlxRect _this = ::flixel::FlxObject_obj::_secondSeparateFlxRect;		HX_STACK_VAR(_this,"_this");
			HX_STACK_LINE(825)
			Float Width = Object2->get_width();		HX_STACK_VAR(Width,"Width");
			HX_STACK_LINE(825)
			Float Height = (Object2->get_height() + obj2deltaAbs);		HX_STACK_VAR(Height,"Height");
			HX_STACK_LINE(825)
			_this->x = Object2->x;
			HX_STACK_LINE(825)
			_this->y = (Object2->y - ((  (((obj2delta > (int)0))) ? Float(obj2delta) : Float((int)0) )));
			HX_STACK_LINE(825)
			_this->width = Width;
			HX_STACK_LINE(825)
			_this->height = Height;
			HX_STACK_LINE(825)
			obj2rect = _this;
		}
		HX_STACK_LINE(827)
		if (((bool((bool((bool(((obj1rect->x + obj1rect->width) > obj2rect->x)) && bool((obj1rect->x < (obj2rect->x + obj2rect->width))))) && bool(((obj1rect->y + obj1rect->height) > obj2rect->y)))) && bool((obj1rect->y < (obj2rect->y + obj2rect->height)))))){
			HX_STACK_LINE(829)
			Float maxOverlap = ((obj1deltaAbs + obj2deltaAbs) + ::flixel::FlxObject_obj::SEPARATE_BIAS);		HX_STACK_VAR(maxOverlap,"maxOverlap");
			HX_STACK_LINE(832)
			if (((obj1delta > obj2delta))){
				HX_STACK_LINE(834)
				overlap = ((Object1->y + Object1->get_height()) - Object2->y);
				HX_STACK_LINE(835)
				if (((bool((bool((overlap > maxOverlap)) || bool((((int(Object1->allowCollisions) & int((int)4096))) == (int)0)))) || bool((((int(Object2->allowCollisions) & int((int)256))) == (int)0))))){
					HX_STACK_LINE(837)
					overlap = (int)0;
				}
				else{
					HX_STACK_LINE(841)
					hx::OrEq(Object1->touching,(int)4096);
					HX_STACK_LINE(842)
					hx::OrEq(Object2->touching,(int)256);
				}
			}
			else{
				HX_STACK_LINE(845)
				if (((obj1delta < obj2delta))){
					HX_STACK_LINE(847)
					overlap = ((Object1->y - Object2->get_height()) - Object2->y);
					HX_STACK_LINE(848)
					if (((bool((bool((-(overlap) > maxOverlap)) || bool((((int(Object1->allowCollisions) & int((int)256))) == (int)0)))) || bool((((int(Object2->allowCollisions) & int((int)4096))) == (int)0))))){
						HX_STACK_LINE(850)
						overlap = (int)0;
					}
					else{
						HX_STACK_LINE(854)
						hx::OrEq(Object1->touching,(int)256);
						HX_STACK_LINE(855)
						hx::OrEq(Object2->touching,(int)4096);
					}
				}
			}
		}
	}
	HX_STACK_LINE(862)
	if (((overlap != (int)0))){
		HX_STACK_LINE(864)
		Float obj1v = Object1->velocity->y;		HX_STACK_VAR(obj1v,"obj1v");
		HX_STACK_LINE(865)
		Float obj2v = Object2->velocity->y;		HX_STACK_VAR(obj2v,"obj2v");
		HX_STACK_LINE(867)
		if (((bool(!(obj1immovable)) && bool(!(obj2immovable))))){
			HX_STACK_LINE(869)
			hx::MultEq(overlap,0.5);
			HX_STACK_LINE(870)
			Object1->set_y((Object1->y - overlap));
			HX_STACK_LINE(871)
			{
				HX_STACK_LINE(871)
				::flixel::FlxObject _g = Object2;		HX_STACK_VAR(_g,"_g");
				HX_STACK_LINE(871)
				_g->set_y((_g->y + overlap));
			}
			HX_STACK_LINE(873)
			Float _g = ::Math_obj::sqrt((Float(((obj2v * obj2v) * Object2->mass)) / Float(Object1->mass)));		HX_STACK_VAR(_g,"_g");
			HX_STACK_LINE(873)
			Float obj1velocity;		HX_STACK_VAR(obj1velocity,"obj1velocity");
			HX_STACK_LINE(873)
			obj1velocity = (_g * ((  (((obj2v > (int)0))) ? int((int)1) : int((int)-1) )));
			HX_STACK_LINE(874)
			Float _g1 = ::Math_obj::sqrt((Float(((obj1v * obj1v) * Object1->mass)) / Float(Object2->mass)));		HX_STACK_VAR(_g1,"_g1");
			HX_STACK_LINE(874)
			Float obj2velocity;		HX_STACK_VAR(obj2velocity,"obj2velocity");
			HX_STACK_LINE(874)
			obj2velocity = (_g1 * ((  (((obj1v > (int)0))) ? int((int)1) : int((int)-1) )));
			HX_STACK_LINE(875)
			Float average = (((obj1velocity + obj2velocity)) * 0.5);		HX_STACK_VAR(average,"average");
			HX_STACK_LINE(876)
			hx::SubEq(obj1velocity,average);
			HX_STACK_LINE(877)
			hx::SubEq(obj2velocity,average);
			HX_STACK_LINE(878)
			Object1->velocity->set_y((average + (obj1velocity * Object1->elasticity)));
			HX_STACK_LINE(879)
			Object2->velocity->set_y((average + (obj2velocity * Object2->elasticity)));
		}
		else{
			HX_STACK_LINE(881)
			if ((!(obj1immovable))){
				HX_STACK_LINE(883)
				Object1->set_y((Object1->y - overlap));
				HX_STACK_LINE(884)
				Object1->velocity->set_y((obj2v - (obj1v * Object1->elasticity)));
				HX_STACK_LINE(886)
				if (((bool((bool((bool(Object1->collisonXDrag) && bool(Object2->active))) && bool(Object2->moves))) && bool((obj1delta > obj2delta))))){
					HX_STACK_LINE(888)
					::flixel::FlxObject _g = Object1;		HX_STACK_VAR(_g,"_g");
					HX_STACK_LINE(888)
					_g->set_x((_g->x + ((Object2->x - Object2->last->x))));
				}
			}
			else{
				HX_STACK_LINE(891)
				if ((!(obj2immovable))){
					HX_STACK_LINE(893)
					{
						HX_STACK_LINE(893)
						::flixel::FlxObject _g = Object2;		HX_STACK_VAR(_g,"_g");
						HX_STACK_LINE(893)
						_g->set_y((_g->y + overlap));
					}
					HX_STACK_LINE(894)
					Object2->velocity->set_y((obj1v - (obj2v * Object2->elasticity)));
					HX_STACK_LINE(896)
					if (((bool((bool((bool(Object2->collisonXDrag) && bool(Object1->active))) && bool(Object1->moves))) && bool((obj1delta < obj2delta))))){
						HX_STACK_LINE(898)
						::flixel::FlxObject _g = Object2;		HX_STACK_VAR(_g,"_g");
						HX_STACK_LINE(898)
						_g->set_x((_g->x + ((Object1->x - Object1->last->x))));
					}
				}
			}
		}
		HX_STACK_LINE(901)
		return true;
	}
	else{
		HX_STACK_LINE(905)
		return false;
	}
	HX_STACK_LINE(862)
	return false;
}


STATIC_HX_DEFINE_DYNAMIC_FUNC2(FlxObject_obj,separateY,return )


FlxObject_obj::FlxObject_obj()
{
}

void FlxObject_obj::__Mark(HX_MARK_PARAMS)
{
	HX_MARK_BEGIN_CLASS(FlxObject);
	HX_MARK_MEMBER_NAME(x,"x");
	HX_MARK_MEMBER_NAME(y,"y");
	HX_MARK_MEMBER_NAME(width,"width");
	HX_MARK_MEMBER_NAME(height,"height");
	HX_MARK_MEMBER_NAME(angle,"angle");
	HX_MARK_MEMBER_NAME(moves,"moves");
	HX_MARK_MEMBER_NAME(immovable,"immovable");
	HX_MARK_MEMBER_NAME(forceComplexRender,"forceComplexRender");
	HX_MARK_MEMBER_NAME(scrollFactor,"scrollFactor");
	HX_MARK_MEMBER_NAME(velocity,"velocity");
	HX_MARK_MEMBER_NAME(acceleration,"acceleration");
	HX_MARK_MEMBER_NAME(drag,"drag");
	HX_MARK_MEMBER_NAME(maxVelocity,"maxVelocity");
	HX_MARK_MEMBER_NAME(mass,"mass");
	HX_MARK_MEMBER_NAME(elasticity,"elasticity");
	HX_MARK_MEMBER_NAME(angularVelocity,"angularVelocity");
	HX_MARK_MEMBER_NAME(angularAcceleration,"angularAcceleration");
	HX_MARK_MEMBER_NAME(angularDrag,"angularDrag");
	HX_MARK_MEMBER_NAME(maxAngular,"maxAngular");
	HX_MARK_MEMBER_NAME(health,"health");
	HX_MARK_MEMBER_NAME(touching,"touching");
	HX_MARK_MEMBER_NAME(wasTouching,"wasTouching");
	HX_MARK_MEMBER_NAME(allowCollisions,"allowCollisions");
	HX_MARK_MEMBER_NAME(last,"last");
	HX_MARK_MEMBER_NAME(collisonXDrag,"collisonXDrag");
	HX_MARK_MEMBER_NAME(region,"region");
	HX_MARK_MEMBER_NAME(framesData,"framesData");
	HX_MARK_MEMBER_NAME(cachedGraphics,"cachedGraphics");
	HX_MARK_MEMBER_NAME(_point,"_point");
	HX_MARK_MEMBER_NAME(debugBoundingBoxColor,"debugBoundingBoxColor");
	HX_MARK_MEMBER_NAME(_boundingBoxColorOverritten,"_boundingBoxColorOverritten");
	::flixel::FlxBasic_obj::__Mark(HX_MARK_ARG);
	HX_MARK_END_CLASS();
}

void FlxObject_obj::__Visit(HX_VISIT_PARAMS)
{
	HX_VISIT_MEMBER_NAME(x,"x");
	HX_VISIT_MEMBER_NAME(y,"y");
	HX_VISIT_MEMBER_NAME(width,"width");
	HX_VISIT_MEMBER_NAME(height,"height");
	HX_VISIT_MEMBER_NAME(angle,"angle");
	HX_VISIT_MEMBER_NAME(moves,"moves");
	HX_VISIT_MEMBER_NAME(immovable,"immovable");
	HX_VISIT_MEMBER_NAME(forceComplexRender,"forceComplexRender");
	HX_VISIT_MEMBER_NAME(scrollFactor,"scrollFactor");
	HX_VISIT_MEMBER_NAME(velocity,"velocity");
	HX_VISIT_MEMBER_NAME(acceleration,"acceleration");
	HX_VISIT_MEMBER_NAME(drag,"drag");
	HX_VISIT_MEMBER_NAME(maxVelocity,"maxVelocity");
	HX_VISIT_MEMBER_NAME(mass,"mass");
	HX_VISIT_MEMBER_NAME(elasticity,"elasticity");
	HX_VISIT_MEMBER_NAME(angularVelocity,"angularVelocity");
	HX_VISIT_MEMBER_NAME(angularAcceleration,"angularAcceleration");
	HX_VISIT_MEMBER_NAME(angularDrag,"angularDrag");
	HX_VISIT_MEMBER_NAME(maxAngular,"maxAngular");
	HX_VISIT_MEMBER_NAME(health,"health");
	HX_VISIT_MEMBER_NAME(touching,"touching");
	HX_VISIT_MEMBER_NAME(wasTouching,"wasTouching");
	HX_VISIT_MEMBER_NAME(allowCollisions,"allowCollisions");
	HX_VISIT_MEMBER_NAME(last,"last");
	HX_VISIT_MEMBER_NAME(collisonXDrag,"collisonXDrag");
	HX_VISIT_MEMBER_NAME(region,"region");
	HX_VISIT_MEMBER_NAME(framesData,"framesData");
	HX_VISIT_MEMBER_NAME(cachedGraphics,"cachedGraphics");
	HX_VISIT_MEMBER_NAME(_point,"_point");
	HX_VISIT_MEMBER_NAME(debugBoundingBoxColor,"debugBoundingBoxColor");
	HX_VISIT_MEMBER_NAME(_boundingBoxColorOverritten,"_boundingBoxColorOverritten");
	::flixel::FlxBasic_obj::__Visit(HX_VISIT_ARG);
}

Dynamic FlxObject_obj::__Field(const ::String &inName,bool inCallProp)
{
	switch(inName.length) {
	case 1:
		if (HX_FIELD_EQ(inName,"x") ) { return x; }
		if (HX_FIELD_EQ(inName,"y") ) { return y; }
		break;
	case 4:
		if (HX_FIELD_EQ(inName,"drag") ) { return drag; }
		if (HX_FIELD_EQ(inName,"mass") ) { return mass; }
		if (HX_FIELD_EQ(inName,"last") ) { return last; }
		if (HX_FIELD_EQ(inName,"draw") ) { return draw_dyn(); }
		if (HX_FIELD_EQ(inName,"hurt") ) { return hurt_dyn(); }
		break;
	case 5:
		if (HX_FIELD_EQ(inName,"width") ) { return inCallProp ? get_width() : width; }
		if (HX_FIELD_EQ(inName,"angle") ) { return angle; }
		if (HX_FIELD_EQ(inName,"moves") ) { return moves; }
		if (HX_FIELD_EQ(inName,"solid") ) { return get_solid(); }
		if (HX_FIELD_EQ(inName,"reset") ) { return reset_dyn(); }
		if (HX_FIELD_EQ(inName,"set_x") ) { return set_x_dyn(); }
		if (HX_FIELD_EQ(inName,"set_y") ) { return set_y_dyn(); }
		break;
	case 6:
		if (HX_FIELD_EQ(inName,"_pZero") ) { return _pZero; }
		if (HX_FIELD_EQ(inName,"height") ) { return inCallProp ? get_height() : height; }
		if (HX_FIELD_EQ(inName,"health") ) { return health; }
		if (HX_FIELD_EQ(inName,"region") ) { return region; }
		if (HX_FIELD_EQ(inName,"_point") ) { return _point; }
		if (HX_FIELD_EQ(inName,"update") ) { return update_dyn(); }
		break;
	case 7:
		if (HX_FIELD_EQ(inName,"destroy") ) { return destroy_dyn(); }
		if (HX_FIELD_EQ(inName,"setSize") ) { return setSize_dyn(); }
		break;
	case 8:
		if (HX_FIELD_EQ(inName,"separate") ) { return separate_dyn(); }
		if (HX_FIELD_EQ(inName,"velocity") ) { return velocity; }
		if (HX_FIELD_EQ(inName,"touching") ) { return touching; }
		if (HX_FIELD_EQ(inName,"initVars") ) { return initVars_dyn(); }
		if (HX_FIELD_EQ(inName,"overlaps") ) { return overlaps_dyn(); }
		if (HX_FIELD_EQ(inName,"toString") ) { return toString_dyn(); }
		break;
	case 9:
		if (HX_FIELD_EQ(inName,"separateX") ) { return separateX_dyn(); }
		if (HX_FIELD_EQ(inName,"separateY") ) { return separateY_dyn(); }
		if (HX_FIELD_EQ(inName,"immovable") ) { return immovable; }
		if (HX_FIELD_EQ(inName,"set_width") ) { return set_width_dyn(); }
		if (HX_FIELD_EQ(inName,"get_width") ) { return get_width_dyn(); }
		if (HX_FIELD_EQ(inName,"get_solid") ) { return get_solid_dyn(); }
		if (HX_FIELD_EQ(inName,"set_solid") ) { return set_solid_dyn(); }
		if (HX_FIELD_EQ(inName,"set_angle") ) { return set_angle_dyn(); }
		if (HX_FIELD_EQ(inName,"set_moves") ) { return set_moves_dyn(); }
		break;
	case 10:
		if (HX_FIELD_EQ(inName,"elasticity") ) { return elasticity; }
		if (HX_FIELD_EQ(inName,"maxAngular") ) { return maxAngular; }
		if (HX_FIELD_EQ(inName,"framesData") ) { return framesData; }
		if (HX_FIELD_EQ(inName,"overlapsAt") ) { return overlapsAt_dyn(); }
		if (HX_FIELD_EQ(inName,"isOnScreen") ) { return isOnScreen_dyn(); }
		if (HX_FIELD_EQ(inName,"isTouching") ) { return isTouching_dyn(); }
		if (HX_FIELD_EQ(inName,"set_height") ) { return set_height_dyn(); }
		if (HX_FIELD_EQ(inName,"get_height") ) { return get_height_dyn(); }
		break;
	case 11:
		if (HX_FIELD_EQ(inName,"maxVelocity") ) { return maxVelocity; }
		if (HX_FIELD_EQ(inName,"angularDrag") ) { return angularDrag; }
		if (HX_FIELD_EQ(inName,"wasTouching") ) { return wasTouching; }
		if (HX_FIELD_EQ(inName,"getScreenXY") ) { return getScreenXY_dyn(); }
		if (HX_FIELD_EQ(inName,"getMidpoint") ) { return getMidpoint_dyn(); }
		if (HX_FIELD_EQ(inName,"justTouched") ) { return justTouched_dyn(); }
		if (HX_FIELD_EQ(inName,"setPosition") ) { return setPosition_dyn(); }
		break;
	case 12:
		if (HX_FIELD_EQ(inName,"scrollFactor") ) { return scrollFactor; }
		if (HX_FIELD_EQ(inName,"acceleration") ) { return acceleration; }
		if (HX_FIELD_EQ(inName,"updateMotion") ) { return updateMotion_dyn(); }
		break;
	case 13:
		if (HX_FIELD_EQ(inName,"SEPARATE_BIAS") ) { return SEPARATE_BIAS; }
		if (HX_FIELD_EQ(inName,"collisonXDrag") ) { return collisonXDrag; }
		if (HX_FIELD_EQ(inName,"overlapsPoint") ) { return overlapsPoint_dyn(); }
		if (HX_FIELD_EQ(inName,"inWorldBounds") ) { return inWorldBounds_dyn(); }
		if (HX_FIELD_EQ(inName,"set_immovable") ) { return set_immovable_dyn(); }
		break;
	case 14:
		if (HX_FIELD_EQ(inName,"cachedGraphics") ) { return cachedGraphics; }
		if (HX_FIELD_EQ(inName,"initMotionVars") ) { return initMotionVars_dyn(); }
		break;
	case 15:
		if (HX_FIELD_EQ(inName,"angularVelocity") ) { return angularVelocity; }
		if (HX_FIELD_EQ(inName,"allowCollisions") ) { return allowCollisions; }
		break;
	case 17:
		if (HX_FIELD_EQ(inName,"drawDebugOnCamera") ) { return drawDebugOnCamera_dyn(); }
		break;
	case 18:
		if (HX_FIELD_EQ(inName,"forceComplexRender") ) { return forceComplexRender; }
		if (HX_FIELD_EQ(inName,"set_cachedGraphics") ) { return set_cachedGraphics_dyn(); }
		break;
	case 19:
		if (HX_FIELD_EQ(inName,"angularAcceleration") ) { return angularAcceleration; }
		break;
	case 21:
		if (HX_FIELD_EQ(inName,"_firstSeparateFlxRect") ) { return _firstSeparateFlxRect; }
		if (HX_FIELD_EQ(inName,"debugBoundingBoxColor") ) { return debugBoundingBoxColor; }
		break;
	case 22:
		if (HX_FIELD_EQ(inName,"_secondSeparateFlxRect") ) { return _secondSeparateFlxRect; }
		if (HX_FIELD_EQ(inName,"set_forceComplexRender") ) { return set_forceComplexRender_dyn(); }
		break;
	case 25:
		if (HX_FIELD_EQ(inName,"set_debugBoundingBoxColor") ) { return set_debugBoundingBoxColor_dyn(); }
		break;
	case 27:
		if (HX_FIELD_EQ(inName,"_boundingBoxColorOverritten") ) { return _boundingBoxColorOverritten; }
	}
	return super::__Field(inName,inCallProp);
}

Dynamic FlxObject_obj::__SetField(const ::String &inName,const Dynamic &inValue,bool inCallProp)
{
	switch(inName.length) {
	case 1:
		if (HX_FIELD_EQ(inName,"x") ) { if (inCallProp) return set_x(inValue);x=inValue.Cast< Float >(); return inValue; }
		if (HX_FIELD_EQ(inName,"y") ) { if (inCallProp) return set_y(inValue);y=inValue.Cast< Float >(); return inValue; }
		break;
	case 4:
		if (HX_FIELD_EQ(inName,"drag") ) { drag=inValue.Cast< ::flixel::util::FlxPoint >(); return inValue; }
		if (HX_FIELD_EQ(inName,"mass") ) { mass=inValue.Cast< Float >(); return inValue; }
		if (HX_FIELD_EQ(inName,"last") ) { last=inValue.Cast< ::flixel::util::FlxPoint >(); return inValue; }
		break;
	case 5:
		if (HX_FIELD_EQ(inName,"width") ) { if (inCallProp) return set_width(inValue);width=inValue.Cast< Float >(); return inValue; }
		if (HX_FIELD_EQ(inName,"angle") ) { if (inCallProp) return set_angle(inValue);angle=inValue.Cast< Float >(); return inValue; }
		if (HX_FIELD_EQ(inName,"moves") ) { if (inCallProp) return set_moves(inValue);moves=inValue.Cast< bool >(); return inValue; }
		if (HX_FIELD_EQ(inName,"solid") ) { return set_solid(inValue); }
		break;
	case 6:
		if (HX_FIELD_EQ(inName,"_pZero") ) { _pZero=inValue.Cast< ::flixel::util::FlxPoint >(); return inValue; }
		if (HX_FIELD_EQ(inName,"height") ) { if (inCallProp) return set_height(inValue);height=inValue.Cast< Float >(); return inValue; }
		if (HX_FIELD_EQ(inName,"health") ) { health=inValue.Cast< Float >(); return inValue; }
		if (HX_FIELD_EQ(inName,"region") ) { region=inValue.Cast< ::flixel::system::layer::Region >(); return inValue; }
		if (HX_FIELD_EQ(inName,"_point") ) { _point=inValue.Cast< ::flixel::util::FlxPoint >(); return inValue; }
		break;
	case 8:
		if (HX_FIELD_EQ(inName,"velocity") ) { velocity=inValue.Cast< ::flixel::util::FlxPoint >(); return inValue; }
		if (HX_FIELD_EQ(inName,"touching") ) { touching=inValue.Cast< int >(); return inValue; }
		break;
	case 9:
		if (HX_FIELD_EQ(inName,"immovable") ) { if (inCallProp) return set_immovable(inValue);immovable=inValue.Cast< bool >(); return inValue; }
		break;
	case 10:
		if (HX_FIELD_EQ(inName,"elasticity") ) { elasticity=inValue.Cast< Float >(); return inValue; }
		if (HX_FIELD_EQ(inName,"maxAngular") ) { maxAngular=inValue.Cast< Float >(); return inValue; }
		if (HX_FIELD_EQ(inName,"framesData") ) { framesData=inValue.Cast< ::flixel::system::layer::frames::FlxSpriteFrames >(); return inValue; }
		break;
	case 11:
		if (HX_FIELD_EQ(inName,"maxVelocity") ) { maxVelocity=inValue.Cast< ::flixel::util::FlxPoint >(); return inValue; }
		if (HX_FIELD_EQ(inName,"angularDrag") ) { angularDrag=inValue.Cast< Float >(); return inValue; }
		if (HX_FIELD_EQ(inName,"wasTouching") ) { wasTouching=inValue.Cast< int >(); return inValue; }
		break;
	case 12:
		if (HX_FIELD_EQ(inName,"scrollFactor") ) { scrollFactor=inValue.Cast< ::flixel::util::FlxPoint >(); return inValue; }
		if (HX_FIELD_EQ(inName,"acceleration") ) { acceleration=inValue.Cast< ::flixel::util::FlxPoint >(); return inValue; }
		break;
	case 13:
		if (HX_FIELD_EQ(inName,"SEPARATE_BIAS") ) { SEPARATE_BIAS=inValue.Cast< Float >(); return inValue; }
		if (HX_FIELD_EQ(inName,"collisonXDrag") ) { collisonXDrag=inValue.Cast< bool >(); return inValue; }
		break;
	case 14:
		if (HX_FIELD_EQ(inName,"cachedGraphics") ) { if (inCallProp) return set_cachedGraphics(inValue);cachedGraphics=inValue.Cast< ::flixel::util::loaders::CachedGraphics >(); return inValue; }
		break;
	case 15:
		if (HX_FIELD_EQ(inName,"angularVelocity") ) { angularVelocity=inValue.Cast< Float >(); return inValue; }
		if (HX_FIELD_EQ(inName,"allowCollisions") ) { allowCollisions=inValue.Cast< int >(); return inValue; }
		break;
	case 18:
		if (HX_FIELD_EQ(inName,"forceComplexRender") ) { if (inCallProp) return set_forceComplexRender(inValue);forceComplexRender=inValue.Cast< bool >(); return inValue; }
		break;
	case 19:
		if (HX_FIELD_EQ(inName,"angularAcceleration") ) { angularAcceleration=inValue.Cast< Float >(); return inValue; }
		break;
	case 21:
		if (HX_FIELD_EQ(inName,"_firstSeparateFlxRect") ) { _firstSeparateFlxRect=inValue.Cast< ::flixel::util::FlxRect >(); return inValue; }
		if (HX_FIELD_EQ(inName,"debugBoundingBoxColor") ) { if (inCallProp) return set_debugBoundingBoxColor(inValue);debugBoundingBoxColor=inValue.Cast< int >(); return inValue; }
		break;
	case 22:
		if (HX_FIELD_EQ(inName,"_secondSeparateFlxRect") ) { _secondSeparateFlxRect=inValue.Cast< ::flixel::util::FlxRect >(); return inValue; }
		break;
	case 27:
		if (HX_FIELD_EQ(inName,"_boundingBoxColorOverritten") ) { _boundingBoxColorOverritten=inValue.Cast< bool >(); return inValue; }
	}
	return super::__SetField(inName,inValue,inCallProp);
}

void FlxObject_obj::__GetFields(Array< ::String> &outFields)
{
	outFields->push(HX_CSTRING("x"));
	outFields->push(HX_CSTRING("y"));
	outFields->push(HX_CSTRING("width"));
	outFields->push(HX_CSTRING("height"));
	outFields->push(HX_CSTRING("angle"));
	outFields->push(HX_CSTRING("moves"));
	outFields->push(HX_CSTRING("immovable"));
	outFields->push(HX_CSTRING("solid"));
	outFields->push(HX_CSTRING("forceComplexRender"));
	outFields->push(HX_CSTRING("scrollFactor"));
	outFields->push(HX_CSTRING("velocity"));
	outFields->push(HX_CSTRING("acceleration"));
	outFields->push(HX_CSTRING("drag"));
	outFields->push(HX_CSTRING("maxVelocity"));
	outFields->push(HX_CSTRING("mass"));
	outFields->push(HX_CSTRING("elasticity"));
	outFields->push(HX_CSTRING("angularVelocity"));
	outFields->push(HX_CSTRING("angularAcceleration"));
	outFields->push(HX_CSTRING("angularDrag"));
	outFields->push(HX_CSTRING("maxAngular"));
	outFields->push(HX_CSTRING("health"));
	outFields->push(HX_CSTRING("touching"));
	outFields->push(HX_CSTRING("wasTouching"));
	outFields->push(HX_CSTRING("allowCollisions"));
	outFields->push(HX_CSTRING("last"));
	outFields->push(HX_CSTRING("collisonXDrag"));
	outFields->push(HX_CSTRING("region"));
	outFields->push(HX_CSTRING("framesData"));
	outFields->push(HX_CSTRING("cachedGraphics"));
	outFields->push(HX_CSTRING("_point"));
	outFields->push(HX_CSTRING("debugBoundingBoxColor"));
	outFields->push(HX_CSTRING("_boundingBoxColorOverritten"));
	super::__GetFields(outFields);
};

static ::String sStaticFields[] = {
	HX_CSTRING("SEPARATE_BIAS"),
	HX_CSTRING("LEFT"),
	HX_CSTRING("RIGHT"),
	HX_CSTRING("UP"),
	HX_CSTRING("DOWN"),
	HX_CSTRING("NONE"),
	HX_CSTRING("CEILING"),
	HX_CSTRING("FLOOR"),
	HX_CSTRING("WALL"),
	HX_CSTRING("ANY"),
	HX_CSTRING("_pZero"),
	HX_CSTRING("_firstSeparateFlxRect"),
	HX_CSTRING("_secondSeparateFlxRect"),
	HX_CSTRING("separate"),
	HX_CSTRING("separateX"),
	HX_CSTRING("separateY"),
	String(null()) };

#if HXCPP_SCRIPTABLE
static hx::StorageInfo sMemberStorageInfo[] = {
	{hx::fsFloat,(int)offsetof(FlxObject_obj,x),HX_CSTRING("x")},
	{hx::fsFloat,(int)offsetof(FlxObject_obj,y),HX_CSTRING("y")},
	{hx::fsFloat,(int)offsetof(FlxObject_obj,width),HX_CSTRING("width")},
	{hx::fsFloat,(int)offsetof(FlxObject_obj,height),HX_CSTRING("height")},
	{hx::fsFloat,(int)offsetof(FlxObject_obj,angle),HX_CSTRING("angle")},
	{hx::fsBool,(int)offsetof(FlxObject_obj,moves),HX_CSTRING("moves")},
	{hx::fsBool,(int)offsetof(FlxObject_obj,immovable),HX_CSTRING("immovable")},
	{hx::fsBool,(int)offsetof(FlxObject_obj,forceComplexRender),HX_CSTRING("forceComplexRender")},
	{hx::fsObject /*::flixel::util::FlxPoint*/ ,(int)offsetof(FlxObject_obj,scrollFactor),HX_CSTRING("scrollFactor")},
	{hx::fsObject /*::flixel::util::FlxPoint*/ ,(int)offsetof(FlxObject_obj,velocity),HX_CSTRING("velocity")},
	{hx::fsObject /*::flixel::util::FlxPoint*/ ,(int)offsetof(FlxObject_obj,acceleration),HX_CSTRING("acceleration")},
	{hx::fsObject /*::flixel::util::FlxPoint*/ ,(int)offsetof(FlxObject_obj,drag),HX_CSTRING("drag")},
	{hx::fsObject /*::flixel::util::FlxPoint*/ ,(int)offsetof(FlxObject_obj,maxVelocity),HX_CSTRING("maxVelocity")},
	{hx::fsFloat,(int)offsetof(FlxObject_obj,mass),HX_CSTRING("mass")},
	{hx::fsFloat,(int)offsetof(FlxObject_obj,elasticity),HX_CSTRING("elasticity")},
	{hx::fsFloat,(int)offsetof(FlxObject_obj,angularVelocity),HX_CSTRING("angularVelocity")},
	{hx::fsFloat,(int)offsetof(FlxObject_obj,angularAcceleration),HX_CSTRING("angularAcceleration")},
	{hx::fsFloat,(int)offsetof(FlxObject_obj,angularDrag),HX_CSTRING("angularDrag")},
	{hx::fsFloat,(int)offsetof(FlxObject_obj,maxAngular),HX_CSTRING("maxAngular")},
	{hx::fsFloat,(int)offsetof(FlxObject_obj,health),HX_CSTRING("health")},
	{hx::fsInt,(int)offsetof(FlxObject_obj,touching),HX_CSTRING("touching")},
	{hx::fsInt,(int)offsetof(FlxObject_obj,wasTouching),HX_CSTRING("wasTouching")},
	{hx::fsInt,(int)offsetof(FlxObject_obj,allowCollisions),HX_CSTRING("allowCollisions")},
	{hx::fsObject /*::flixel::util::FlxPoint*/ ,(int)offsetof(FlxObject_obj,last),HX_CSTRING("last")},
	{hx::fsBool,(int)offsetof(FlxObject_obj,collisonXDrag),HX_CSTRING("collisonXDrag")},
	{hx::fsObject /*::flixel::system::layer::Region*/ ,(int)offsetof(FlxObject_obj,region),HX_CSTRING("region")},
	{hx::fsObject /*::flixel::system::layer::frames::FlxSpriteFrames*/ ,(int)offsetof(FlxObject_obj,framesData),HX_CSTRING("framesData")},
	{hx::fsObject /*::flixel::util::loaders::CachedGraphics*/ ,(int)offsetof(FlxObject_obj,cachedGraphics),HX_CSTRING("cachedGraphics")},
	{hx::fsObject /*::flixel::util::FlxPoint*/ ,(int)offsetof(FlxObject_obj,_point),HX_CSTRING("_point")},
	{hx::fsInt,(int)offsetof(FlxObject_obj,debugBoundingBoxColor),HX_CSTRING("debugBoundingBoxColor")},
	{hx::fsBool,(int)offsetof(FlxObject_obj,_boundingBoxColorOverritten),HX_CSTRING("_boundingBoxColorOverritten")},
	{ hx::fsUnknown, 0, null()}
};
#endif

static ::String sMemberFields[] = {
	HX_CSTRING("x"),
	HX_CSTRING("y"),
	HX_CSTRING("width"),
	HX_CSTRING("height"),
	HX_CSTRING("angle"),
	HX_CSTRING("moves"),
	HX_CSTRING("immovable"),
	HX_CSTRING("forceComplexRender"),
	HX_CSTRING("scrollFactor"),
	HX_CSTRING("velocity"),
	HX_CSTRING("acceleration"),
	HX_CSTRING("drag"),
	HX_CSTRING("maxVelocity"),
	HX_CSTRING("mass"),
	HX_CSTRING("elasticity"),
	HX_CSTRING("angularVelocity"),
	HX_CSTRING("angularAcceleration"),
	HX_CSTRING("angularDrag"),
	HX_CSTRING("maxAngular"),
	HX_CSTRING("health"),
	HX_CSTRING("touching"),
	HX_CSTRING("wasTouching"),
	HX_CSTRING("allowCollisions"),
	HX_CSTRING("last"),
	HX_CSTRING("collisonXDrag"),
	HX_CSTRING("region"),
	HX_CSTRING("framesData"),
	HX_CSTRING("cachedGraphics"),
	HX_CSTRING("_point"),
	HX_CSTRING("initVars"),
	HX_CSTRING("initMotionVars"),
	HX_CSTRING("destroy"),
	HX_CSTRING("update"),
	HX_CSTRING("updateMotion"),
	HX_CSTRING("draw"),
	HX_CSTRING("drawDebugOnCamera"),
	HX_CSTRING("overlaps"),
	HX_CSTRING("overlapsAt"),
	HX_CSTRING("overlapsPoint"),
	HX_CSTRING("inWorldBounds"),
	HX_CSTRING("getScreenXY"),
	HX_CSTRING("getMidpoint"),
	HX_CSTRING("reset"),
	HX_CSTRING("isOnScreen"),
	HX_CSTRING("isTouching"),
	HX_CSTRING("justTouched"),
	HX_CSTRING("hurt"),
	HX_CSTRING("setPosition"),
	HX_CSTRING("setSize"),
	HX_CSTRING("set_cachedGraphics"),
	HX_CSTRING("set_x"),
	HX_CSTRING("set_y"),
	HX_CSTRING("set_width"),
	HX_CSTRING("set_height"),
	HX_CSTRING("get_width"),
	HX_CSTRING("get_height"),
	HX_CSTRING("get_solid"),
	HX_CSTRING("set_solid"),
	HX_CSTRING("set_angle"),
	HX_CSTRING("set_moves"),
	HX_CSTRING("set_immovable"),
	HX_CSTRING("set_forceComplexRender"),
	HX_CSTRING("debugBoundingBoxColor"),
	HX_CSTRING("set_debugBoundingBoxColor"),
	HX_CSTRING("_boundingBoxColorOverritten"),
	HX_CSTRING("toString"),
	String(null()) };

static void sMarkStatics(HX_MARK_PARAMS) {
	HX_MARK_MEMBER_NAME(FlxObject_obj::__mClass,"__mClass");
	HX_MARK_MEMBER_NAME(FlxObject_obj::SEPARATE_BIAS,"SEPARATE_BIAS");
	HX_MARK_MEMBER_NAME(FlxObject_obj::LEFT,"LEFT");
	HX_MARK_MEMBER_NAME(FlxObject_obj::RIGHT,"RIGHT");
	HX_MARK_MEMBER_NAME(FlxObject_obj::UP,"UP");
	HX_MARK_MEMBER_NAME(FlxObject_obj::DOWN,"DOWN");
	HX_MARK_MEMBER_NAME(FlxObject_obj::NONE,"NONE");
	HX_MARK_MEMBER_NAME(FlxObject_obj::CEILING,"CEILING");
	HX_MARK_MEMBER_NAME(FlxObject_obj::FLOOR,"FLOOR");
	HX_MARK_MEMBER_NAME(FlxObject_obj::WALL,"WALL");
	HX_MARK_MEMBER_NAME(FlxObject_obj::ANY,"ANY");
	HX_MARK_MEMBER_NAME(FlxObject_obj::_pZero,"_pZero");
	HX_MARK_MEMBER_NAME(FlxObject_obj::_firstSeparateFlxRect,"_firstSeparateFlxRect");
	HX_MARK_MEMBER_NAME(FlxObject_obj::_secondSeparateFlxRect,"_secondSeparateFlxRect");
};

#ifdef HXCPP_VISIT_ALLOCS
static void sVisitStatics(HX_VISIT_PARAMS) {
	HX_VISIT_MEMBER_NAME(FlxObject_obj::__mClass,"__mClass");
	HX_VISIT_MEMBER_NAME(FlxObject_obj::SEPARATE_BIAS,"SEPARATE_BIAS");
	HX_VISIT_MEMBER_NAME(FlxObject_obj::LEFT,"LEFT");
	HX_VISIT_MEMBER_NAME(FlxObject_obj::RIGHT,"RIGHT");
	HX_VISIT_MEMBER_NAME(FlxObject_obj::UP,"UP");
	HX_VISIT_MEMBER_NAME(FlxObject_obj::DOWN,"DOWN");
	HX_VISIT_MEMBER_NAME(FlxObject_obj::NONE,"NONE");
	HX_VISIT_MEMBER_NAME(FlxObject_obj::CEILING,"CEILING");
	HX_VISIT_MEMBER_NAME(FlxObject_obj::FLOOR,"FLOOR");
	HX_VISIT_MEMBER_NAME(FlxObject_obj::WALL,"WALL");
	HX_VISIT_MEMBER_NAME(FlxObject_obj::ANY,"ANY");
	HX_VISIT_MEMBER_NAME(FlxObject_obj::_pZero,"_pZero");
	HX_VISIT_MEMBER_NAME(FlxObject_obj::_firstSeparateFlxRect,"_firstSeparateFlxRect");
	HX_VISIT_MEMBER_NAME(FlxObject_obj::_secondSeparateFlxRect,"_secondSeparateFlxRect");
};

#endif

Class FlxObject_obj::__mClass;

void FlxObject_obj::__register()
{
	hx::Static(__mClass) = hx::RegisterClass(HX_CSTRING("flixel.FlxObject"), hx::TCanCast< FlxObject_obj> ,sStaticFields,sMemberFields,
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

void FlxObject_obj::__boot()
{
	SEPARATE_BIAS= (int)4;
	LEFT= (int)1;
	RIGHT= (int)16;
	UP= (int)256;
	DOWN= (int)4096;
	NONE= (int)0;
	CEILING= (int)256;
	FLOOR= (int)4096;
	WALL= (int)17;
	ANY= (int)4369;
	_pZero= ::flixel::util::FlxPoint_obj::__new(null(),null());
	_firstSeparateFlxRect= ::flixel::util::FlxRect_obj::__new(null(),null(),null(),null());
	_secondSeparateFlxRect= ::flixel::util::FlxRect_obj::__new(null(),null(),null(),null());
}

} // end namespace flixel
