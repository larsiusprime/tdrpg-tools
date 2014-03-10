#include <hxcpp.h>

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
#ifndef INCLUDED_flixel_interfaces_IFlxDestroyable
#include <flixel/interfaces/IFlxDestroyable.h>
#endif
#ifndef INCLUDED_flixel_plugin_FlxPlugin
#include <flixel/plugin/FlxPlugin.h>
#endif
#ifndef INCLUDED_flixel_plugin_PathManager
#include <flixel/plugin/PathManager.h>
#endif
#ifndef INCLUDED_flixel_util_FlxAngle
#include <flixel/util/FlxAngle.h>
#endif
#ifndef INCLUDED_flixel_util_FlxArrayUtil
#include <flixel/util/FlxArrayUtil.h>
#endif
#ifndef INCLUDED_flixel_util_FlxPath
#include <flixel/util/FlxPath.h>
#endif
#ifndef INCLUDED_flixel_util_FlxPoint
#include <flixel/util/FlxPoint.h>
#endif
#ifndef INCLUDED_flixel_util_FlxPool_flixel_util_FlxPath
#include <flixel/util/FlxPool_flixel_util_FlxPath.h>
#endif
#ifndef INCLUDED_hxMath
#include <hxMath.h>
#endif
namespace flixel{
namespace util{

Void FlxPath_obj::__construct()
{
HX_STACK_FRAME("flixel.util.FlxPath","new",0x6e30af6f,"flixel.util.FlxPath.new","flixel/util/FlxPath.hx",18,0x22aae741)
{
	HX_STACK_LINE(152)
	this->ignoreDrawDebug = false;
	HX_STACK_LINE(146)
	this->debugScrollY = 1.0;
	HX_STACK_LINE(145)
	this->debugScrollX = 1.0;
	HX_STACK_LINE(140)
	this->debugColor = (int)16777215;
	HX_STACK_LINE(132)
	this->finished = false;
	HX_STACK_LINE(130)
	this->paused = false;
	HX_STACK_LINE(125)
	this->_autoRotate = false;
	HX_STACK_LINE(121)
	this->_inc = (int)1;
	HX_STACK_LINE(113)
	this->_nodeIndex = (int)0;
	HX_STACK_LINE(109)
	this->autoCenter = true;
	HX_STACK_LINE(104)
	this->angle = (int)0;
	HX_STACK_LINE(100)
	this->speed = (int)0;
	HX_STACK_LINE(91)
	this->usePooling = true;
}
;
	return null();
}

//FlxPath_obj::~FlxPath_obj() { }

Dynamic FlxPath_obj::__CreateEmpty() { return  new FlxPath_obj; }
hx::ObjectPtr< FlxPath_obj > FlxPath_obj::__new()
{  hx::ObjectPtr< FlxPath_obj > result = new FlxPath_obj();
	result->__construct();
	return result;}

Dynamic FlxPath_obj::__Create(hx::DynamicArray inArgs)
{  hx::ObjectPtr< FlxPath_obj > result = new FlxPath_obj();
	result->__construct();
	return result;}

::flixel::util::FlxPath FlxPath_obj::reset( ){
	HX_STACK_FRAME("flixel.util.FlxPath","reset",0x2ce64a9e,"flixel.util.FlxPath.reset","flixel/util/FlxPath.hx",172,0x22aae741)
	HX_STACK_THIS(this)
	HX_STACK_LINE(174)
	this->debugScrollX = 1.0;
	HX_STACK_LINE(175)
	this->debugScrollY = 1.0;
	HX_STACK_LINE(176)
	this->debugColor = (int)16777215;
	HX_STACK_LINE(177)
	this->ignoreDrawDebug = false;
	HX_STACK_LINE(179)
	this->autoCenter = true;
	HX_STACK_LINE(180)
	return hx::ObjectPtr<OBJ_>(this);
}


HX_DEFINE_DYNAMIC_FUNC0(FlxPath_obj,reset,return )

::flixel::util::FlxPath FlxPath_obj::run( ::flixel::FlxObject Object,Array< ::Dynamic > Nodes,hx::Null< Float >  __o_Speed,hx::Null< int >  __o_Mode,hx::Null< bool >  __o_AutoRotate,hx::Null< bool >  __o_UsePooling){
Float Speed = __o_Speed.Default(100);
int Mode = __o_Mode.Default(0);
bool AutoRotate = __o_AutoRotate.Default(false);
bool UsePooling = __o_UsePooling.Default(true);
	HX_STACK_FRAME("flixel.util.FlxPath","run",0x6e33c65a,"flixel.util.FlxPath.run","flixel/util/FlxPath.hx",184,0x22aae741)
	HX_STACK_THIS(this)
	HX_STACK_ARG(Object,"Object")
	HX_STACK_ARG(Nodes,"Nodes")
	HX_STACK_ARG(Speed,"Speed")
	HX_STACK_ARG(Mode,"Mode")
	HX_STACK_ARG(AutoRotate,"AutoRotate")
	HX_STACK_ARG(UsePooling,"UsePooling")
{
		HX_STACK_LINE(185)
		this->usePooling = UsePooling;
		HX_STACK_LINE(186)
		this->object = Object;
		HX_STACK_LINE(187)
		this->nodes = Nodes;
		HX_STACK_LINE(188)
		this->speed = ::Math_obj::abs(Speed);
		HX_STACK_LINE(189)
		this->_mode = Mode;
		HX_STACK_LINE(190)
		this->_autoRotate = AutoRotate;
		HX_STACK_LINE(191)
		this->restart();
		HX_STACK_LINE(192)
		return hx::ObjectPtr<OBJ_>(this);
	}
}


HX_DEFINE_DYNAMIC_FUNC6(FlxPath_obj,run,return )

::flixel::util::FlxPath FlxPath_obj::restart( ){
	HX_STACK_FRAME("flixel.util.FlxPath","restart",0xf4e0da5e,"flixel.util.FlxPath.restart","flixel/util/FlxPath.hx",196,0x22aae741)
	HX_STACK_THIS(this)
	HX_STACK_LINE(197)
	if (((::flixel::util::FlxPath_obj::manager != null()))){
		HX_STACK_LINE(199)
		::flixel::util::FlxPath_obj::manager->add(hx::ObjectPtr<OBJ_>(this));
	}
	HX_STACK_LINE(202)
	this->finished = false;
	HX_STACK_LINE(203)
	this->paused = false;
	HX_STACK_LINE(204)
	if (((this->nodes->length <= (int)0))){
		HX_STACK_LINE(206)
		this->paused = true;
	}
	HX_STACK_LINE(210)
	if (((bool((this->_mode == (int)1)) || bool((this->_mode == (int)256))))){
		HX_STACK_LINE(212)
		this->_nodeIndex = (this->nodes->length - (int)1);
		HX_STACK_LINE(213)
		this->_inc = (int)-1;
	}
	else{
		HX_STACK_LINE(217)
		this->_nodeIndex = (int)0;
		HX_STACK_LINE(218)
		this->_inc = (int)1;
	}
	HX_STACK_LINE(221)
	this->object->set_immovable(true);
	HX_STACK_LINE(222)
	return hx::ObjectPtr<OBJ_>(this);
}


HX_DEFINE_DYNAMIC_FUNC0(FlxPath_obj,restart,return )

Void FlxPath_obj::setNode( int NodeIndex){
{
		HX_STACK_FRAME("flixel.util.FlxPath","setNode",0x98c95d53,"flixel.util.FlxPath.setNode","flixel/util/FlxPath.hx",230,0x22aae741)
		HX_STACK_THIS(this)
		HX_STACK_ARG(NodeIndex,"NodeIndex")
		HX_STACK_LINE(231)
		if (((NodeIndex < (int)0))){
			HX_STACK_LINE(232)
			NodeIndex = (int)0;
		}
		else{
			HX_STACK_LINE(233)
			if (((NodeIndex > (this->nodes->length - (int)1)))){
				HX_STACK_LINE(234)
				NodeIndex = (this->nodes->length - (int)1);
			}
		}
		HX_STACK_LINE(236)
		this->_nodeIndex = NodeIndex;
		HX_STACK_LINE(237)
		this->advancePath(null());
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC1(FlxPath_obj,setNode,(void))

Void FlxPath_obj::update( ){
{
		HX_STACK_FRAME("flixel.util.FlxPath","update",0x9b283a5a,"flixel.util.FlxPath.update","flixel/util/FlxPath.hx",247,0x22aae741)
		HX_STACK_THIS(this)
		HX_STACK_LINE(249)
		::flixel::util::FlxPath_obj::_point->set_x(this->object->x);
		HX_STACK_LINE(250)
		::flixel::util::FlxPath_obj::_point->set_y(this->object->y);
		HX_STACK_LINE(251)
		if ((this->autoCenter)){
			HX_STACK_LINE(253)
			{
				HX_STACK_LINE(253)
				::flixel::util::FlxPoint _g = ::flixel::util::FlxPath_obj::_point;		HX_STACK_VAR(_g,"_g");
				HX_STACK_LINE(253)
				_g->set_x((_g->x + (this->object->get_width() * 0.5)));
			}
			HX_STACK_LINE(254)
			{
				HX_STACK_LINE(254)
				::flixel::util::FlxPoint _g = ::flixel::util::FlxPath_obj::_point;		HX_STACK_VAR(_g,"_g");
				HX_STACK_LINE(254)
				_g->set_y((_g->y + (this->object->get_height() * 0.5)));
			}
		}
		HX_STACK_LINE(256)
		::flixel::util::FlxPoint node = this->nodes->__get(this->_nodeIndex).StaticCast< ::flixel::util::FlxPoint >();		HX_STACK_VAR(node,"node");
		HX_STACK_LINE(257)
		Float deltaX = (node->x - ::flixel::util::FlxPath_obj::_point->x);		HX_STACK_VAR(deltaX,"deltaX");
		HX_STACK_LINE(258)
		Float deltaY = (node->y - ::flixel::util::FlxPath_obj::_point->y);		HX_STACK_VAR(deltaY,"deltaY");
		HX_STACK_LINE(260)
		bool horizontalOnly = (((int(this->_mode) & int((int)65536))) > (int)0);		HX_STACK_VAR(horizontalOnly,"horizontalOnly");
		HX_STACK_LINE(261)
		bool verticalOnly = (((int(this->_mode) & int((int)1048576))) > (int)0);		HX_STACK_VAR(verticalOnly,"verticalOnly");
		HX_STACK_LINE(263)
		if ((horizontalOnly)){
			HX_STACK_LINE(265)
			if (((((  (((deltaX > (int)0))) ? Float(deltaX) : Float(-(deltaX)) )) < (this->speed * ::flixel::FlxG_obj::elapsed)))){
				HX_STACK_LINE(267)
				node = this->advancePath(null());
			}
		}
		else{
			HX_STACK_LINE(270)
			if ((verticalOnly)){
				HX_STACK_LINE(272)
				if (((((  (((deltaY > (int)0))) ? Float(deltaY) : Float(-(deltaY)) )) < (this->speed * ::flixel::FlxG_obj::elapsed)))){
					HX_STACK_LINE(274)
					node = this->advancePath(null());
				}
			}
			else{
				HX_STACK_LINE(279)
				if (((::Math_obj::sqrt(((deltaX * deltaX) + (deltaY * deltaY))) < (this->speed * ::flixel::FlxG_obj::elapsed)))){
					HX_STACK_LINE(281)
					node = this->advancePath(null());
				}
			}
		}
		HX_STACK_LINE(286)
		if (((this->speed != (int)0))){
			HX_STACK_LINE(289)
			::flixel::util::FlxPath_obj::_point->set_x(this->object->x);
			HX_STACK_LINE(290)
			::flixel::util::FlxPath_obj::_point->set_y(this->object->y);
			HX_STACK_LINE(292)
			if ((this->autoCenter)){
				HX_STACK_LINE(294)
				{
					HX_STACK_LINE(294)
					::flixel::util::FlxPoint _g = ::flixel::util::FlxPath_obj::_point;		HX_STACK_VAR(_g,"_g");
					HX_STACK_LINE(294)
					_g->set_x((_g->x + (this->object->get_width() * 0.5)));
				}
				HX_STACK_LINE(295)
				{
					HX_STACK_LINE(295)
					::flixel::util::FlxPoint _g = ::flixel::util::FlxPath_obj::_point;		HX_STACK_VAR(_g,"_g");
					HX_STACK_LINE(295)
					_g->set_y((_g->y + (this->object->get_height() * 0.5)));
				}
			}
			HX_STACK_LINE(298)
			if (((bool(horizontalOnly) || bool((::flixel::util::FlxPath_obj::_point->y == node->y))))){
				HX_STACK_LINE(300)
				this->object->velocity->set_x((  (((::flixel::util::FlxPath_obj::_point->x < node->x))) ? Float(this->speed) : Float(-(this->speed)) ));
				HX_STACK_LINE(301)
				if (((this->object->velocity->x < (int)0))){
					HX_STACK_LINE(303)
					this->angle = (int)-90;
				}
				else{
					HX_STACK_LINE(307)
					this->angle = (int)90;
				}
				HX_STACK_LINE(309)
				if ((!(horizontalOnly))){
					HX_STACK_LINE(311)
					this->object->velocity->set_y((int)0);
				}
			}
			else{
				HX_STACK_LINE(314)
				if (((bool(verticalOnly) || bool((::flixel::util::FlxPath_obj::_point->x == node->x))))){
					HX_STACK_LINE(316)
					this->object->velocity->set_y((  (((::flixel::util::FlxPath_obj::_point->y < node->y))) ? Float(this->speed) : Float(-(this->speed)) ));
					HX_STACK_LINE(317)
					if (((this->object->velocity->y < (int)0))){
						HX_STACK_LINE(319)
						this->angle = (int)0;
					}
					else{
						HX_STACK_LINE(323)
						this->angle = (int)180;
					}
					HX_STACK_LINE(325)
					if ((!(verticalOnly))){
						HX_STACK_LINE(327)
						this->object->velocity->set_x((int)0);
					}
				}
				else{
					HX_STACK_LINE(332)
					this->object->velocity->set_x((  (((::flixel::util::FlxPath_obj::_point->x < node->x))) ? Float(this->speed) : Float(-(this->speed)) ));
					HX_STACK_LINE(333)
					this->object->velocity->set_y((  (((::flixel::util::FlxPath_obj::_point->y < node->y))) ? Float(this->speed) : Float(-(this->speed)) ));
					HX_STACK_LINE(334)
					{
						HX_STACK_LINE(334)
						::flixel::util::FlxPoint Point1 = ::flixel::util::FlxPath_obj::_point;		HX_STACK_VAR(Point1,"Point1");
						HX_STACK_LINE(334)
						Float x = (node->x - Point1->x);		HX_STACK_VAR(x,"x");
						HX_STACK_LINE(334)
						Float y = (node->y - Point1->y);		HX_STACK_VAR(y,"y");
						HX_STACK_LINE(334)
						Float angle = (int)0;		HX_STACK_VAR(angle,"angle");
						HX_STACK_LINE(334)
						if (((bool((x != (int)0)) || bool((y != (int)0))))){
							HX_STACK_LINE(334)
							Float c1 = (::Math_obj::PI * 0.25);		HX_STACK_VAR(c1,"c1");
							HX_STACK_LINE(334)
							Float c2 = ((int)3 * c1);		HX_STACK_VAR(c2,"c2");
							HX_STACK_LINE(334)
							Float ay;		HX_STACK_VAR(ay,"ay");
							HX_STACK_LINE(334)
							if (((y < (int)0))){
								HX_STACK_LINE(334)
								ay = -(y);
							}
							else{
								HX_STACK_LINE(334)
								ay = y;
							}
							HX_STACK_LINE(334)
							if (((x >= (int)0))){
								HX_STACK_LINE(334)
								angle = (c1 - (c1 * ((Float(((x - ay))) / Float(((x + ay)))))));
							}
							else{
								HX_STACK_LINE(334)
								angle = (c2 - (c1 * ((Float(((x + ay))) / Float(((ay - x)))))));
							}
							HX_STACK_LINE(334)
							angle = (((  (((y < (int)0))) ? Float(-(angle)) : Float(angle) )) * ::flixel::util::FlxAngle_obj::TO_DEG);
							HX_STACK_LINE(334)
							if (((angle > (int)90))){
								HX_STACK_LINE(334)
								angle = (angle - (int)270);
							}
							else{
								HX_STACK_LINE(334)
								hx::AddEq(angle,(int)90);
							}
						}
						HX_STACK_LINE(334)
						this->angle = angle;
					}
					HX_STACK_LINE(335)
					{
						HX_STACK_LINE(335)
						::flixel::util::FlxPoint point = this->object->velocity;		HX_STACK_VAR(point,"point");
						HX_STACK_LINE(335)
						Float sin = (int)0;		HX_STACK_VAR(sin,"sin");
						HX_STACK_LINE(335)
						Float cos = (int)0;		HX_STACK_VAR(cos,"cos");
						HX_STACK_LINE(335)
						Float radians = (this->angle * -(::flixel::util::FlxAngle_obj::TO_RAD));		HX_STACK_VAR(radians,"radians");
						HX_STACK_LINE(335)
						while(((radians < -(::Math_obj::PI)))){
							HX_STACK_LINE(335)
							hx::AddEq(radians,(::Math_obj::PI * (int)2));
						}
						HX_STACK_LINE(335)
						while(((radians > ::Math_obj::PI))){
							HX_STACK_LINE(335)
							radians = (radians - (::Math_obj::PI * (int)2));
						}
						HX_STACK_LINE(335)
						if (((radians < (int)0))){
							HX_STACK_LINE(335)
							sin = ((1.27323954 * radians) + ((.405284735 * radians) * radians));
							HX_STACK_LINE(335)
							if (((sin < (int)0))){
								HX_STACK_LINE(335)
								sin = ((.225 * (((sin * -(sin)) - sin))) + sin);
							}
							else{
								HX_STACK_LINE(335)
								sin = ((.225 * (((sin * sin) - sin))) + sin);
							}
						}
						else{
							HX_STACK_LINE(335)
							sin = ((1.27323954 * radians) - ((0.405284735 * radians) * radians));
							HX_STACK_LINE(335)
							if (((sin < (int)0))){
								HX_STACK_LINE(335)
								sin = ((.225 * (((sin * -(sin)) - sin))) + sin);
							}
							else{
								HX_STACK_LINE(335)
								sin = ((.225 * (((sin * sin) - sin))) + sin);
							}
						}
						HX_STACK_LINE(335)
						hx::AddEq(radians,(Float(::Math_obj::PI) / Float((int)2)));
						HX_STACK_LINE(335)
						if (((radians > ::Math_obj::PI))){
							HX_STACK_LINE(335)
							radians = (radians - (::Math_obj::PI * (int)2));
						}
						HX_STACK_LINE(335)
						if (((radians < (int)0))){
							HX_STACK_LINE(335)
							cos = ((1.27323954 * radians) + ((0.405284735 * radians) * radians));
							HX_STACK_LINE(335)
							if (((cos < (int)0))){
								HX_STACK_LINE(335)
								cos = ((.225 * (((cos * -(cos)) - cos))) + cos);
							}
							else{
								HX_STACK_LINE(335)
								cos = ((.225 * (((cos * cos) - cos))) + cos);
							}
						}
						else{
							HX_STACK_LINE(335)
							cos = ((1.27323954 * radians) - ((0.405284735 * radians) * radians));
							HX_STACK_LINE(335)
							if (((cos < (int)0))){
								HX_STACK_LINE(335)
								cos = ((.225 * (((cos * -(cos)) - cos))) + cos);
							}
							else{
								HX_STACK_LINE(335)
								cos = ((.225 * (((cos * cos) - cos))) + cos);
							}
						}
						HX_STACK_LINE(335)
						Float dx = (int)0;		HX_STACK_VAR(dx,"dx");
						HX_STACK_LINE(335)
						Float dy = this->speed;		HX_STACK_VAR(dy,"dy");
						HX_STACK_LINE(335)
						if (((point == null()))){
							HX_STACK_LINE(335)
							point = ::flixel::util::FlxPoint_obj::__new(null(),null());
						}
						HX_STACK_LINE(335)
						point->set_x(((cos * dx) - (sin * dy)));
						HX_STACK_LINE(335)
						point->set_y((((int)0 - (sin * dx)) - (cos * dy)));
						HX_STACK_LINE(335)
						point;
					}
				}
			}
			HX_STACK_LINE(339)
			if ((this->_autoRotate)){
				HX_STACK_LINE(341)
				this->object->angularVelocity = (int)0;
				HX_STACK_LINE(342)
				this->object->angularAcceleration = (int)0;
				HX_STACK_LINE(343)
				this->object->set_angle(this->angle);
			}
			HX_STACK_LINE(346)
			if ((this->finished)){
				HX_STACK_LINE(348)
				this->abort();
			}
		}
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC0(FlxPath_obj,update,(void))

::flixel::util::FlxPoint FlxPath_obj::advancePath( hx::Null< bool >  __o_Snap){
bool Snap = __o_Snap.Default(true);
	HX_STACK_FRAME("flixel.util.FlxPath","advancePath",0xf96b8956,"flixel.util.FlxPath.advancePath","flixel/util/FlxPath.hx",358,0x22aae741)
	HX_STACK_THIS(this)
	HX_STACK_ARG(Snap,"Snap")
{
		HX_STACK_LINE(359)
		if ((Snap)){
			HX_STACK_LINE(361)
			::flixel::util::FlxPoint oldNode = this->nodes->__get(this->_nodeIndex).StaticCast< ::flixel::util::FlxPoint >();		HX_STACK_VAR(oldNode,"oldNode");
			HX_STACK_LINE(362)
			if (((oldNode != null()))){
				HX_STACK_LINE(364)
				if (((((int(this->_mode) & int((int)1048576))) == (int)0))){
					HX_STACK_LINE(366)
					this->object->set_x(oldNode->x);
					HX_STACK_LINE(367)
					if ((this->autoCenter)){
						HX_STACK_LINE(368)
						::flixel::FlxObject _g = this->object;		HX_STACK_VAR(_g,"_g");
						HX_STACK_LINE(368)
						_g->set_x((_g->x - (this->object->get_width() * 0.5)));
					}
				}
				HX_STACK_LINE(370)
				if (((((int(this->_mode) & int((int)65536))) == (int)0))){
					HX_STACK_LINE(372)
					this->object->set_y(oldNode->y);
					HX_STACK_LINE(373)
					if ((this->autoCenter)){
						HX_STACK_LINE(374)
						::flixel::FlxObject _g = this->object;		HX_STACK_VAR(_g,"_g");
						HX_STACK_LINE(374)
						_g->set_y((_g->y - (this->object->get_height() * 0.5)));
					}
				}
			}
		}
		HX_STACK_LINE(379)
		bool callComplete = false;		HX_STACK_VAR(callComplete,"callComplete");
		HX_STACK_LINE(380)
		hx::AddEq(this->_nodeIndex,this->_inc);
		HX_STACK_LINE(382)
		if (((((int(this->_mode) & int((int)1))) > (int)0))){
			HX_STACK_LINE(384)
			if (((this->_nodeIndex < (int)0))){
				HX_STACK_LINE(386)
				this->_nodeIndex = (int)0;
				HX_STACK_LINE(387)
				this->finished = callComplete = true;
			}
		}
		else{
			HX_STACK_LINE(390)
			if (((((int(this->_mode) & int((int)16))) > (int)0))){
				HX_STACK_LINE(392)
				if (((this->_nodeIndex >= this->nodes->length))){
					HX_STACK_LINE(394)
					callComplete = true;
					HX_STACK_LINE(395)
					this->_nodeIndex = (int)0;
				}
			}
			else{
				HX_STACK_LINE(398)
				if (((((int(this->_mode) & int((int)256))) > (int)0))){
					HX_STACK_LINE(400)
					if (((this->_nodeIndex < (int)0))){
						HX_STACK_LINE(402)
						this->_nodeIndex = (this->nodes->length - (int)1);
						HX_STACK_LINE(403)
						callComplete = true;
						HX_STACK_LINE(404)
						if (((this->_nodeIndex < (int)0))){
							HX_STACK_LINE(406)
							this->_nodeIndex = (int)0;
						}
					}
				}
				else{
					HX_STACK_LINE(410)
					if (((((int(this->_mode) & int((int)4096))) > (int)0))){
						HX_STACK_LINE(412)
						if (((this->_inc > (int)0))){
							HX_STACK_LINE(414)
							if (((this->_nodeIndex >= this->nodes->length))){
								HX_STACK_LINE(416)
								this->_nodeIndex = (this->nodes->length - (int)2);
								HX_STACK_LINE(417)
								callComplete = true;
								HX_STACK_LINE(418)
								if (((this->_nodeIndex < (int)0))){
									HX_STACK_LINE(420)
									this->_nodeIndex = (int)0;
								}
								HX_STACK_LINE(422)
								this->_inc = -(this->_inc);
							}
						}
						else{
							HX_STACK_LINE(425)
							if (((this->_nodeIndex < (int)0))){
								HX_STACK_LINE(427)
								this->_nodeIndex = (int)1;
								HX_STACK_LINE(428)
								callComplete = true;
								HX_STACK_LINE(429)
								if (((this->_nodeIndex >= this->nodes->length))){
									HX_STACK_LINE(431)
									this->_nodeIndex = (this->nodes->length - (int)1);
								}
								HX_STACK_LINE(433)
								if (((this->_nodeIndex < (int)0))){
									HX_STACK_LINE(435)
									this->_nodeIndex = (int)0;
								}
								HX_STACK_LINE(437)
								this->_inc = -(this->_inc);
							}
						}
					}
					else{
						HX_STACK_LINE(442)
						if (((this->_nodeIndex >= this->nodes->length))){
							HX_STACK_LINE(444)
							this->_nodeIndex = (this->nodes->length - (int)1);
							HX_STACK_LINE(445)
							this->finished = callComplete = true;
						}
					}
				}
			}
		}
		HX_STACK_LINE(449)
		if (((bool(callComplete) && bool((this->onComplete_dyn() != null()))))){
			HX_STACK_LINE(451)
			this->onComplete(hx::ObjectPtr<OBJ_>(this));
		}
		HX_STACK_LINE(454)
		return this->nodes->__get(this->_nodeIndex).StaticCast< ::flixel::util::FlxPoint >();
	}
}


HX_DEFINE_DYNAMIC_FUNC1(FlxPath_obj,advancePath,return )

Void FlxPath_obj::abort( ){
{
		HX_STACK_FRAME("flixel.util.FlxPath","abort",0x6117cc7f,"flixel.util.FlxPath.abort","flixel/util/FlxPath.hx",461,0x22aae741)
		HX_STACK_THIS(this)
		HX_STACK_LINE(462)
		this->finished = true;
		HX_STACK_LINE(464)
		if (((this->object != null()))){
			HX_STACK_LINE(466)
			this->object->velocity->set_x((int)0);
			HX_STACK_LINE(467)
			this->object->velocity->set_y((int)0);
		}
		HX_STACK_LINE(470)
		if (((::flixel::util::FlxPath_obj::manager != null()))){
			HX_STACK_LINE(472)
			::flixel::util::FlxPath_obj::manager->remove(hx::ObjectPtr<OBJ_>(this),this->usePooling);
		}
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC0(FlxPath_obj,abort,(void))

Void FlxPath_obj::destroy( ){
{
		HX_STACK_FRAME("flixel.util.FlxPath","destroy",0xaec13f89,"flixel.util.FlxPath.destroy","flixel/util/FlxPath.hx",480,0x22aae741)
		HX_STACK_THIS(this)
		HX_STACK_LINE(481)
		this->nodes = null();
		HX_STACK_LINE(482)
		this->object = null();
		HX_STACK_LINE(483)
		this->onComplete = null();
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC0(FlxPath_obj,destroy,(void))

::flixel::util::FlxPath FlxPath_obj::add( Float X,Float Y){
	HX_STACK_FRAME("flixel.util.FlxPath","add",0x6e26d130,"flixel.util.FlxPath.add","flixel/util/FlxPath.hx",492,0x22aae741)
	HX_STACK_THIS(this)
	HX_STACK_ARG(X,"X")
	HX_STACK_ARG(Y,"Y")
	HX_STACK_LINE(493)
	this->nodes->push(::flixel::util::FlxPoint_obj::__new(X,Y));
	HX_STACK_LINE(494)
	return hx::ObjectPtr<OBJ_>(this);
}


HX_DEFINE_DYNAMIC_FUNC2(FlxPath_obj,add,return )

::flixel::util::FlxPath FlxPath_obj::addAt( Float X,Float Y,int Index){
	HX_STACK_FRAME("flixel.util.FlxPath","addAt",0x6261b643,"flixel.util.FlxPath.addAt","flixel/util/FlxPath.hx",504,0x22aae741)
	HX_STACK_THIS(this)
	HX_STACK_ARG(X,"X")
	HX_STACK_ARG(Y,"Y")
	HX_STACK_ARG(Index,"Index")
	HX_STACK_LINE(505)
	if (((Index < (int)0))){
		HX_STACK_LINE(505)
		return hx::ObjectPtr<OBJ_>(this);
	}
	HX_STACK_LINE(506)
	if (((Index > this->nodes->length))){
		HX_STACK_LINE(508)
		Index = this->nodes->length;
	}
	HX_STACK_LINE(510)
	this->nodes->insert(Index,::flixel::util::FlxPoint_obj::__new(X,Y));
	HX_STACK_LINE(511)
	return hx::ObjectPtr<OBJ_>(this);
}


HX_DEFINE_DYNAMIC_FUNC3(FlxPath_obj,addAt,return )

::flixel::util::FlxPath FlxPath_obj::addPoint( ::flixel::util::FlxPoint Node,hx::Null< bool >  __o_AsReference){
bool AsReference = __o_AsReference.Default(false);
	HX_STACK_FRAME("flixel.util.FlxPath","addPoint",0xa9620500,"flixel.util.FlxPath.addPoint","flixel/util/FlxPath.hx",522,0x22aae741)
	HX_STACK_THIS(this)
	HX_STACK_ARG(Node,"Node")
	HX_STACK_ARG(AsReference,"AsReference")
{
		HX_STACK_LINE(523)
		if ((AsReference)){
			HX_STACK_LINE(525)
			this->nodes->push(Node);
		}
		else{
			HX_STACK_LINE(529)
			this->nodes->push(::flixel::util::FlxPoint_obj::__new(Node->x,Node->y));
		}
		HX_STACK_LINE(531)
		return hx::ObjectPtr<OBJ_>(this);
	}
}


HX_DEFINE_DYNAMIC_FUNC2(FlxPath_obj,addPoint,return )

::flixel::util::FlxPath FlxPath_obj::addPointAt( ::flixel::util::FlxPoint Node,int Index,hx::Null< bool >  __o_AsReference){
bool AsReference = __o_AsReference.Default(false);
	HX_STACK_FRAME("flixel.util.FlxPath","addPointAt",0x49ad7e13,"flixel.util.FlxPath.addPointAt","flixel/util/FlxPath.hx",543,0x22aae741)
	HX_STACK_THIS(this)
	HX_STACK_ARG(Node,"Node")
	HX_STACK_ARG(Index,"Index")
	HX_STACK_ARG(AsReference,"AsReference")
{
		HX_STACK_LINE(544)
		if (((Index < (int)0))){
			HX_STACK_LINE(544)
			return hx::ObjectPtr<OBJ_>(this);
		}
		HX_STACK_LINE(545)
		if (((Index > this->nodes->length))){
			HX_STACK_LINE(547)
			Index = this->nodes->length;
		}
		HX_STACK_LINE(549)
		if ((AsReference)){
			HX_STACK_LINE(551)
			this->nodes->insert(Index,Node);
		}
		else{
			HX_STACK_LINE(555)
			this->nodes->insert(Index,::flixel::util::FlxPoint_obj::__new(Node->x,Node->y));
		}
		HX_STACK_LINE(557)
		return hx::ObjectPtr<OBJ_>(this);
	}
}


HX_DEFINE_DYNAMIC_FUNC3(FlxPath_obj,addPointAt,return )

::flixel::util::FlxPoint FlxPath_obj::remove( ::flixel::util::FlxPoint Node){
	HX_STACK_FRAME("flixel.util.FlxPath","remove",0x18ab5095,"flixel.util.FlxPath.remove","flixel/util/FlxPath.hx",567,0x22aae741)
	HX_STACK_THIS(this)
	HX_STACK_ARG(Node,"Node")
	HX_STACK_LINE(568)
	int index = ::flixel::util::FlxArrayUtil_obj::indexOf_flixel_util_FlxPoint(this->nodes,Node,null());		HX_STACK_VAR(index,"index");
	HX_STACK_LINE(569)
	if (((index >= (int)0))){
		HX_STACK_LINE(571)
		return this->nodes->splice(index,(int)1)->__get((int)0).StaticCast< ::flixel::util::FlxPoint >();
	}
	else{
		HX_STACK_LINE(575)
		return null();
	}
	HX_STACK_LINE(569)
	return null();
}


HX_DEFINE_DYNAMIC_FUNC1(FlxPath_obj,remove,return )

::flixel::util::FlxPoint FlxPath_obj::removeAt( int Index){
	HX_STACK_FRAME("flixel.util.FlxPath","removeAt",0x169098e8,"flixel.util.FlxPath.removeAt","flixel/util/FlxPath.hx",585,0x22aae741)
	HX_STACK_THIS(this)
	HX_STACK_ARG(Index,"Index")
	HX_STACK_LINE(586)
	if (((this->nodes->length <= (int)0))){
		HX_STACK_LINE(588)
		return null();
	}
	HX_STACK_LINE(590)
	if (((Index >= this->nodes->length))){
		HX_STACK_LINE(592)
		Index = (this->nodes->length - (int)1);
	}
	HX_STACK_LINE(594)
	return this->nodes->splice(Index,(int)1)->__get((int)0).StaticCast< ::flixel::util::FlxPoint >();
}


HX_DEFINE_DYNAMIC_FUNC1(FlxPath_obj,removeAt,return )

::flixel::util::FlxPoint FlxPath_obj::head( ){
	HX_STACK_FRAME("flixel.util.FlxPath","head",0xf8717731,"flixel.util.FlxPath.head","flixel/util/FlxPath.hx",602,0x22aae741)
	HX_STACK_THIS(this)
	HX_STACK_LINE(603)
	if (((this->nodes->length > (int)0))){
		HX_STACK_LINE(605)
		return this->nodes->__get((int)0).StaticCast< ::flixel::util::FlxPoint >();
	}
	HX_STACK_LINE(607)
	return null();
}


HX_DEFINE_DYNAMIC_FUNC0(FlxPath_obj,head,return )

::flixel::util::FlxPoint FlxPath_obj::tail( ){
	HX_STACK_FRAME("flixel.util.FlxPath","tail",0x005d04a1,"flixel.util.FlxPath.tail","flixel/util/FlxPath.hx",615,0x22aae741)
	HX_STACK_THIS(this)
	HX_STACK_LINE(616)
	if (((this->nodes->length > (int)0))){
		HX_STACK_LINE(618)
		return this->nodes->__get((this->nodes->length - (int)1)).StaticCast< ::flixel::util::FlxPoint >();
	}
	HX_STACK_LINE(620)
	return null();
}


HX_DEFINE_DYNAMIC_FUNC0(FlxPath_obj,tail,return )

Void FlxPath_obj::drawDebug( ::flixel::FlxCamera Camera){
{
		HX_STACK_FRAME("flixel.util.FlxPath","drawDebug",0x7c3a9bfe,"flixel.util.FlxPath.drawDebug","flixel/util/FlxPath.hx",632,0x22aae741)
		HX_STACK_THIS(this)
		HX_STACK_ARG(Camera,"Camera")
		HX_STACK_LINE(633)
		if (((bool((this->nodes == null())) || bool((this->nodes->length <= (int)0))))){
			HX_STACK_LINE(635)
			return null();
		}
		HX_STACK_LINE(637)
		if (((Camera == null()))){
			HX_STACK_LINE(639)
			Camera = ::flixel::FlxG_obj::camera;
		}
		HX_STACK_LINE(647)
		::flash::display::Graphics gfx = Camera->debugLayer->get_graphics();		HX_STACK_VAR(gfx,"gfx");
		HX_STACK_LINE(651)
		::flixel::util::FlxPoint node;		HX_STACK_VAR(node,"node");
		HX_STACK_LINE(652)
		::flixel::util::FlxPoint nextNode;		HX_STACK_VAR(nextNode,"nextNode");
		HX_STACK_LINE(653)
		int i = (int)0;		HX_STACK_VAR(i,"i");
		HX_STACK_LINE(654)
		int l = this->nodes->length;		HX_STACK_VAR(l,"l");
		HX_STACK_LINE(655)
		while(((i < l))){
			HX_STACK_LINE(658)
			node = this->nodes->__get(i).StaticCast< ::flixel::util::FlxPoint >();
			HX_STACK_LINE(661)
			::flixel::util::FlxPath_obj::_point->set_x((node->x - (Camera->scroll->x * this->debugScrollX)));
			HX_STACK_LINE(662)
			::flixel::util::FlxPath_obj::_point->set_y((node->y - (Camera->scroll->y * this->debugScrollY)));
			HX_STACK_LINE(665)
			int nodeSize = (int)2;		HX_STACK_VAR(nodeSize,"nodeSize");
			HX_STACK_LINE(666)
			if (((bool((i == (int)0)) || bool((i == (l - (int)1)))))){
				HX_STACK_LINE(668)
				hx::MultEq(nodeSize,(int)2);
			}
			HX_STACK_LINE(670)
			int nodeColor = this->debugColor;		HX_STACK_VAR(nodeColor,"nodeColor");
			HX_STACK_LINE(671)
			if (((l > (int)1))){
				HX_STACK_LINE(673)
				if (((i == (int)0))){
					HX_STACK_LINE(675)
					nodeColor = (int)-16744448;
				}
				else{
					HX_STACK_LINE(677)
					if (((i == (l - (int)1)))){
						HX_STACK_LINE(679)
						nodeColor = (int)-65536;
					}
				}
			}
			HX_STACK_LINE(684)
			gfx->beginFill(nodeColor,0.5);
			HX_STACK_LINE(685)
			gfx->lineStyle(null(),null(),null(),null(),null(),null(),null(),null());
			HX_STACK_LINE(686)
			gfx->drawRect((::flixel::util::FlxPath_obj::_point->x - (nodeSize * 0.5)),(::flixel::util::FlxPath_obj::_point->y - (nodeSize * 0.5)),nodeSize,nodeSize);
			HX_STACK_LINE(687)
			gfx->endFill();
			HX_STACK_LINE(690)
			Float linealpha = 0.3;		HX_STACK_VAR(linealpha,"linealpha");
			HX_STACK_LINE(691)
			if (((i < (l - (int)1)))){
				HX_STACK_LINE(693)
				nextNode = this->nodes->__get((i + (int)1)).StaticCast< ::flixel::util::FlxPoint >();
			}
			else{
				HX_STACK_LINE(697)
				nextNode = this->nodes->__get((int)0).StaticCast< ::flixel::util::FlxPoint >();
				HX_STACK_LINE(698)
				linealpha = 0.15;
			}
			HX_STACK_LINE(702)
			gfx->moveTo(::flixel::util::FlxPath_obj::_point->x,::flixel::util::FlxPath_obj::_point->y);
			HX_STACK_LINE(703)
			gfx->lineStyle((int)1,this->debugColor,linealpha,null(),null(),null(),null(),null());
			HX_STACK_LINE(704)
			::flixel::util::FlxPath_obj::_point->set_x((nextNode->x - (Camera->scroll->x * this->debugScrollX)));
			HX_STACK_LINE(705)
			::flixel::util::FlxPath_obj::_point->set_y((nextNode->y - (Camera->scroll->y * this->debugScrollY)));
			HX_STACK_LINE(706)
			gfx->lineTo(::flixel::util::FlxPath_obj::_point->x,::flixel::util::FlxPath_obj::_point->y);
			HX_STACK_LINE(708)
			(i)++;
		}
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC1(FlxPath_obj,drawDebug,(void))

::flixel::util::FlxPool_flixel_util_FlxPath FlxPath_obj::pool;

::flixel::util::FlxPath FlxPath_obj::recycle( ){
	HX_STACK_FRAME("flixel.util.FlxPath","recycle",0xc1c722a2,"flixel.util.FlxPath.recycle","flixel/util/FlxPath.hx",27,0x22aae741)
	struct _Function_1_1{
		inline static ::flixel::util::FlxPath Block( ){
			HX_STACK_FRAME("*","closure",0x5bdab937,"*.closure","flixel/util/FlxPath.hx",27,0x22aae741)
			{
				HX_STACK_LINE(27)
				::flixel::util::FlxPath obj = ::flixel::util::FlxPath_obj::pool->_pool->pop().StaticCast< ::flixel::util::FlxPath >();		HX_STACK_VAR(obj,"obj");
				HX_STACK_LINE(27)
				if (((obj == null()))){
					HX_STACK_LINE(27)
					obj = ::flixel::util::FlxPath_obj::__new();
				}
				HX_STACK_LINE(27)
				return obj;
			}
			return null();
		}
	};
	HX_STACK_LINE(27)
	return (_Function_1_1::Block())->reset();
}


STATIC_HX_DEFINE_DYNAMIC_FUNC0(FlxPath_obj,recycle,return )

Void FlxPath_obj::put( ::flixel::util::FlxPath path){
{
		HX_STACK_FRAME("flixel.util.FlxPath","put",0x6e3241de,"flixel.util.FlxPath.put","flixel/util/FlxPath.hx",32,0x22aae741)
		HX_STACK_ARG(path,"path")
		HX_STACK_LINE(32)
		::flixel::util::FlxPath_obj::pool->put(path);
	}
return null();
}


STATIC_HX_DEFINE_DYNAMIC_FUNC1(FlxPath_obj,put,(void))

::flixel::util::FlxPath FlxPath_obj::start( ::flixel::FlxObject Object,Array< ::Dynamic > Nodes,hx::Null< Float >  __o_Speed,hx::Null< int >  __o_Mode,hx::Null< bool >  __o_AutoRotate,hx::Null< bool >  __o_UsePooling){
Float Speed = __o_Speed.Default(100);
int Mode = __o_Mode.Default(0);
bool AutoRotate = __o_AutoRotate.Default(false);
bool UsePooling = __o_UsePooling.Default(true);
	HX_STACK_FRAME("flixel.util.FlxPath","start",0xca297531,"flixel.util.FlxPath.start","flixel/util/FlxPath.hx",46,0x22aae741)
	HX_STACK_ARG(Object,"Object")
	HX_STACK_ARG(Nodes,"Nodes")
	HX_STACK_ARG(Speed,"Speed")
	HX_STACK_ARG(Mode,"Mode")
	HX_STACK_ARG(AutoRotate,"AutoRotate")
	HX_STACK_ARG(UsePooling,"UsePooling")
{
		HX_STACK_LINE(47)
		::flixel::util::FlxPath path = ::flixel::util::FlxPath_obj::recycle();		HX_STACK_VAR(path,"path");
		HX_STACK_LINE(48)
		path->run(Object,Nodes,Speed,Mode,AutoRotate,UsePooling);
		HX_STACK_LINE(49)
		return path;
	}
}


STATIC_HX_DEFINE_DYNAMIC_FUNC6(FlxPath_obj,start,return )

int FlxPath_obj::FORWARD;

int FlxPath_obj::BACKWARD;

int FlxPath_obj::LOOP_FORWARD;

int FlxPath_obj::LOOP_BACKWARD;

int FlxPath_obj::YOYO;

int FlxPath_obj::HORIZONTAL_ONLY;

int FlxPath_obj::VERTICAL_ONLY;

::flixel::util::FlxPoint FlxPath_obj::_point;

::flixel::plugin::PathManager FlxPath_obj::manager;


FlxPath_obj::FlxPath_obj()
{
}

void FlxPath_obj::__Mark(HX_MARK_PARAMS)
{
	HX_MARK_BEGIN_CLASS(FlxPath);
	HX_MARK_MEMBER_NAME(nodes,"nodes");
	HX_MARK_MEMBER_NAME(object,"object");
	HX_MARK_MEMBER_NAME(usePooling,"usePooling");
	HX_MARK_MEMBER_NAME(speed,"speed");
	HX_MARK_MEMBER_NAME(angle,"angle");
	HX_MARK_MEMBER_NAME(autoCenter,"autoCenter");
	HX_MARK_MEMBER_NAME(_nodeIndex,"_nodeIndex");
	HX_MARK_MEMBER_NAME(_mode,"_mode");
	HX_MARK_MEMBER_NAME(_inc,"_inc");
	HX_MARK_MEMBER_NAME(_autoRotate,"_autoRotate");
	HX_MARK_MEMBER_NAME(paused,"paused");
	HX_MARK_MEMBER_NAME(finished,"finished");
	HX_MARK_MEMBER_NAME(onComplete,"onComplete");
	HX_MARK_MEMBER_NAME(debugColor,"debugColor");
	HX_MARK_MEMBER_NAME(debugScrollX,"debugScrollX");
	HX_MARK_MEMBER_NAME(debugScrollY,"debugScrollY");
	HX_MARK_MEMBER_NAME(ignoreDrawDebug,"ignoreDrawDebug");
	HX_MARK_END_CLASS();
}

void FlxPath_obj::__Visit(HX_VISIT_PARAMS)
{
	HX_VISIT_MEMBER_NAME(nodes,"nodes");
	HX_VISIT_MEMBER_NAME(object,"object");
	HX_VISIT_MEMBER_NAME(usePooling,"usePooling");
	HX_VISIT_MEMBER_NAME(speed,"speed");
	HX_VISIT_MEMBER_NAME(angle,"angle");
	HX_VISIT_MEMBER_NAME(autoCenter,"autoCenter");
	HX_VISIT_MEMBER_NAME(_nodeIndex,"_nodeIndex");
	HX_VISIT_MEMBER_NAME(_mode,"_mode");
	HX_VISIT_MEMBER_NAME(_inc,"_inc");
	HX_VISIT_MEMBER_NAME(_autoRotate,"_autoRotate");
	HX_VISIT_MEMBER_NAME(paused,"paused");
	HX_VISIT_MEMBER_NAME(finished,"finished");
	HX_VISIT_MEMBER_NAME(onComplete,"onComplete");
	HX_VISIT_MEMBER_NAME(debugColor,"debugColor");
	HX_VISIT_MEMBER_NAME(debugScrollX,"debugScrollX");
	HX_VISIT_MEMBER_NAME(debugScrollY,"debugScrollY");
	HX_VISIT_MEMBER_NAME(ignoreDrawDebug,"ignoreDrawDebug");
}

Dynamic FlxPath_obj::__Field(const ::String &inName,bool inCallProp)
{
	switch(inName.length) {
	case 3:
		if (HX_FIELD_EQ(inName,"put") ) { return put_dyn(); }
		if (HX_FIELD_EQ(inName,"run") ) { return run_dyn(); }
		if (HX_FIELD_EQ(inName,"add") ) { return add_dyn(); }
		break;
	case 4:
		if (HX_FIELD_EQ(inName,"pool") ) { return pool; }
		if (HX_FIELD_EQ(inName,"_inc") ) { return _inc; }
		if (HX_FIELD_EQ(inName,"head") ) { return head_dyn(); }
		if (HX_FIELD_EQ(inName,"tail") ) { return tail_dyn(); }
		break;
	case 5:
		if (HX_FIELD_EQ(inName,"start") ) { return start_dyn(); }
		if (HX_FIELD_EQ(inName,"nodes") ) { return nodes; }
		if (HX_FIELD_EQ(inName,"speed") ) { return speed; }
		if (HX_FIELD_EQ(inName,"angle") ) { return angle; }
		if (HX_FIELD_EQ(inName,"_mode") ) { return _mode; }
		if (HX_FIELD_EQ(inName,"reset") ) { return reset_dyn(); }
		if (HX_FIELD_EQ(inName,"abort") ) { return abort_dyn(); }
		if (HX_FIELD_EQ(inName,"addAt") ) { return addAt_dyn(); }
		break;
	case 6:
		if (HX_FIELD_EQ(inName,"_point") ) { return _point; }
		if (HX_FIELD_EQ(inName,"object") ) { return object; }
		if (HX_FIELD_EQ(inName,"paused") ) { return paused; }
		if (HX_FIELD_EQ(inName,"update") ) { return update_dyn(); }
		if (HX_FIELD_EQ(inName,"remove") ) { return remove_dyn(); }
		break;
	case 7:
		if (HX_FIELD_EQ(inName,"recycle") ) { return recycle_dyn(); }
		if (HX_FIELD_EQ(inName,"manager") ) { return manager; }
		if (HX_FIELD_EQ(inName,"restart") ) { return restart_dyn(); }
		if (HX_FIELD_EQ(inName,"setNode") ) { return setNode_dyn(); }
		if (HX_FIELD_EQ(inName,"destroy") ) { return destroy_dyn(); }
		break;
	case 8:
		if (HX_FIELD_EQ(inName,"finished") ) { return finished; }
		if (HX_FIELD_EQ(inName,"addPoint") ) { return addPoint_dyn(); }
		if (HX_FIELD_EQ(inName,"removeAt") ) { return removeAt_dyn(); }
		break;
	case 9:
		if (HX_FIELD_EQ(inName,"drawDebug") ) { return drawDebug_dyn(); }
		break;
	case 10:
		if (HX_FIELD_EQ(inName,"usePooling") ) { return usePooling; }
		if (HX_FIELD_EQ(inName,"autoCenter") ) { return autoCenter; }
		if (HX_FIELD_EQ(inName,"_nodeIndex") ) { return _nodeIndex; }
		if (HX_FIELD_EQ(inName,"onComplete") ) { return onComplete; }
		if (HX_FIELD_EQ(inName,"debugColor") ) { return debugColor; }
		if (HX_FIELD_EQ(inName,"addPointAt") ) { return addPointAt_dyn(); }
		break;
	case 11:
		if (HX_FIELD_EQ(inName,"_autoRotate") ) { return _autoRotate; }
		if (HX_FIELD_EQ(inName,"advancePath") ) { return advancePath_dyn(); }
		break;
	case 12:
		if (HX_FIELD_EQ(inName,"debugScrollX") ) { return debugScrollX; }
		if (HX_FIELD_EQ(inName,"debugScrollY") ) { return debugScrollY; }
		break;
	case 15:
		if (HX_FIELD_EQ(inName,"ignoreDrawDebug") ) { return ignoreDrawDebug; }
	}
	return super::__Field(inName,inCallProp);
}

Dynamic FlxPath_obj::__SetField(const ::String &inName,const Dynamic &inValue,bool inCallProp)
{
	switch(inName.length) {
	case 4:
		if (HX_FIELD_EQ(inName,"pool") ) { pool=inValue.Cast< ::flixel::util::FlxPool_flixel_util_FlxPath >(); return inValue; }
		if (HX_FIELD_EQ(inName,"_inc") ) { _inc=inValue.Cast< int >(); return inValue; }
		break;
	case 5:
		if (HX_FIELD_EQ(inName,"nodes") ) { nodes=inValue.Cast< Array< ::Dynamic > >(); return inValue; }
		if (HX_FIELD_EQ(inName,"speed") ) { speed=inValue.Cast< Float >(); return inValue; }
		if (HX_FIELD_EQ(inName,"angle") ) { angle=inValue.Cast< Float >(); return inValue; }
		if (HX_FIELD_EQ(inName,"_mode") ) { _mode=inValue.Cast< int >(); return inValue; }
		break;
	case 6:
		if (HX_FIELD_EQ(inName,"_point") ) { _point=inValue.Cast< ::flixel::util::FlxPoint >(); return inValue; }
		if (HX_FIELD_EQ(inName,"object") ) { object=inValue.Cast< ::flixel::FlxObject >(); return inValue; }
		if (HX_FIELD_EQ(inName,"paused") ) { paused=inValue.Cast< bool >(); return inValue; }
		break;
	case 7:
		if (HX_FIELD_EQ(inName,"manager") ) { manager=inValue.Cast< ::flixel::plugin::PathManager >(); return inValue; }
		break;
	case 8:
		if (HX_FIELD_EQ(inName,"finished") ) { finished=inValue.Cast< bool >(); return inValue; }
		break;
	case 10:
		if (HX_FIELD_EQ(inName,"usePooling") ) { usePooling=inValue.Cast< bool >(); return inValue; }
		if (HX_FIELD_EQ(inName,"autoCenter") ) { autoCenter=inValue.Cast< bool >(); return inValue; }
		if (HX_FIELD_EQ(inName,"_nodeIndex") ) { _nodeIndex=inValue.Cast< int >(); return inValue; }
		if (HX_FIELD_EQ(inName,"onComplete") ) { onComplete=inValue.Cast< Dynamic >(); return inValue; }
		if (HX_FIELD_EQ(inName,"debugColor") ) { debugColor=inValue.Cast< int >(); return inValue; }
		break;
	case 11:
		if (HX_FIELD_EQ(inName,"_autoRotate") ) { _autoRotate=inValue.Cast< bool >(); return inValue; }
		break;
	case 12:
		if (HX_FIELD_EQ(inName,"debugScrollX") ) { debugScrollX=inValue.Cast< Float >(); return inValue; }
		if (HX_FIELD_EQ(inName,"debugScrollY") ) { debugScrollY=inValue.Cast< Float >(); return inValue; }
		break;
	case 15:
		if (HX_FIELD_EQ(inName,"ignoreDrawDebug") ) { ignoreDrawDebug=inValue.Cast< bool >(); return inValue; }
	}
	return super::__SetField(inName,inValue,inCallProp);
}

void FlxPath_obj::__GetFields(Array< ::String> &outFields)
{
	outFields->push(HX_CSTRING("nodes"));
	outFields->push(HX_CSTRING("object"));
	outFields->push(HX_CSTRING("usePooling"));
	outFields->push(HX_CSTRING("speed"));
	outFields->push(HX_CSTRING("angle"));
	outFields->push(HX_CSTRING("autoCenter"));
	outFields->push(HX_CSTRING("_nodeIndex"));
	outFields->push(HX_CSTRING("_mode"));
	outFields->push(HX_CSTRING("_inc"));
	outFields->push(HX_CSTRING("_autoRotate"));
	outFields->push(HX_CSTRING("paused"));
	outFields->push(HX_CSTRING("finished"));
	outFields->push(HX_CSTRING("debugColor"));
	outFields->push(HX_CSTRING("debugScrollX"));
	outFields->push(HX_CSTRING("debugScrollY"));
	outFields->push(HX_CSTRING("ignoreDrawDebug"));
	super::__GetFields(outFields);
};

static ::String sStaticFields[] = {
	HX_CSTRING("pool"),
	HX_CSTRING("recycle"),
	HX_CSTRING("put"),
	HX_CSTRING("start"),
	HX_CSTRING("FORWARD"),
	HX_CSTRING("BACKWARD"),
	HX_CSTRING("LOOP_FORWARD"),
	HX_CSTRING("LOOP_BACKWARD"),
	HX_CSTRING("YOYO"),
	HX_CSTRING("HORIZONTAL_ONLY"),
	HX_CSTRING("VERTICAL_ONLY"),
	HX_CSTRING("_point"),
	HX_CSTRING("manager"),
	String(null()) };

#if HXCPP_SCRIPTABLE
static hx::StorageInfo sMemberStorageInfo[] = {
	{hx::fsObject /*Array< ::Dynamic >*/ ,(int)offsetof(FlxPath_obj,nodes),HX_CSTRING("nodes")},
	{hx::fsObject /*::flixel::FlxObject*/ ,(int)offsetof(FlxPath_obj,object),HX_CSTRING("object")},
	{hx::fsBool,(int)offsetof(FlxPath_obj,usePooling),HX_CSTRING("usePooling")},
	{hx::fsFloat,(int)offsetof(FlxPath_obj,speed),HX_CSTRING("speed")},
	{hx::fsFloat,(int)offsetof(FlxPath_obj,angle),HX_CSTRING("angle")},
	{hx::fsBool,(int)offsetof(FlxPath_obj,autoCenter),HX_CSTRING("autoCenter")},
	{hx::fsInt,(int)offsetof(FlxPath_obj,_nodeIndex),HX_CSTRING("_nodeIndex")},
	{hx::fsInt,(int)offsetof(FlxPath_obj,_mode),HX_CSTRING("_mode")},
	{hx::fsInt,(int)offsetof(FlxPath_obj,_inc),HX_CSTRING("_inc")},
	{hx::fsBool,(int)offsetof(FlxPath_obj,_autoRotate),HX_CSTRING("_autoRotate")},
	{hx::fsBool,(int)offsetof(FlxPath_obj,paused),HX_CSTRING("paused")},
	{hx::fsBool,(int)offsetof(FlxPath_obj,finished),HX_CSTRING("finished")},
	{hx::fsObject /*Dynamic*/ ,(int)offsetof(FlxPath_obj,onComplete),HX_CSTRING("onComplete")},
	{hx::fsInt,(int)offsetof(FlxPath_obj,debugColor),HX_CSTRING("debugColor")},
	{hx::fsFloat,(int)offsetof(FlxPath_obj,debugScrollX),HX_CSTRING("debugScrollX")},
	{hx::fsFloat,(int)offsetof(FlxPath_obj,debugScrollY),HX_CSTRING("debugScrollY")},
	{hx::fsBool,(int)offsetof(FlxPath_obj,ignoreDrawDebug),HX_CSTRING("ignoreDrawDebug")},
	{ hx::fsUnknown, 0, null()}
};
#endif

static ::String sMemberFields[] = {
	HX_CSTRING("nodes"),
	HX_CSTRING("object"),
	HX_CSTRING("usePooling"),
	HX_CSTRING("speed"),
	HX_CSTRING("angle"),
	HX_CSTRING("autoCenter"),
	HX_CSTRING("_nodeIndex"),
	HX_CSTRING("_mode"),
	HX_CSTRING("_inc"),
	HX_CSTRING("_autoRotate"),
	HX_CSTRING("paused"),
	HX_CSTRING("finished"),
	HX_CSTRING("onComplete"),
	HX_CSTRING("debugColor"),
	HX_CSTRING("debugScrollX"),
	HX_CSTRING("debugScrollY"),
	HX_CSTRING("ignoreDrawDebug"),
	HX_CSTRING("reset"),
	HX_CSTRING("run"),
	HX_CSTRING("restart"),
	HX_CSTRING("setNode"),
	HX_CSTRING("update"),
	HX_CSTRING("advancePath"),
	HX_CSTRING("abort"),
	HX_CSTRING("destroy"),
	HX_CSTRING("add"),
	HX_CSTRING("addAt"),
	HX_CSTRING("addPoint"),
	HX_CSTRING("addPointAt"),
	HX_CSTRING("remove"),
	HX_CSTRING("removeAt"),
	HX_CSTRING("head"),
	HX_CSTRING("tail"),
	HX_CSTRING("drawDebug"),
	String(null()) };

static void sMarkStatics(HX_MARK_PARAMS) {
	HX_MARK_MEMBER_NAME(FlxPath_obj::__mClass,"__mClass");
	HX_MARK_MEMBER_NAME(FlxPath_obj::pool,"pool");
	HX_MARK_MEMBER_NAME(FlxPath_obj::FORWARD,"FORWARD");
	HX_MARK_MEMBER_NAME(FlxPath_obj::BACKWARD,"BACKWARD");
	HX_MARK_MEMBER_NAME(FlxPath_obj::LOOP_FORWARD,"LOOP_FORWARD");
	HX_MARK_MEMBER_NAME(FlxPath_obj::LOOP_BACKWARD,"LOOP_BACKWARD");
	HX_MARK_MEMBER_NAME(FlxPath_obj::YOYO,"YOYO");
	HX_MARK_MEMBER_NAME(FlxPath_obj::HORIZONTAL_ONLY,"HORIZONTAL_ONLY");
	HX_MARK_MEMBER_NAME(FlxPath_obj::VERTICAL_ONLY,"VERTICAL_ONLY");
	HX_MARK_MEMBER_NAME(FlxPath_obj::_point,"_point");
	HX_MARK_MEMBER_NAME(FlxPath_obj::manager,"manager");
};

#ifdef HXCPP_VISIT_ALLOCS
static void sVisitStatics(HX_VISIT_PARAMS) {
	HX_VISIT_MEMBER_NAME(FlxPath_obj::__mClass,"__mClass");
	HX_VISIT_MEMBER_NAME(FlxPath_obj::pool,"pool");
	HX_VISIT_MEMBER_NAME(FlxPath_obj::FORWARD,"FORWARD");
	HX_VISIT_MEMBER_NAME(FlxPath_obj::BACKWARD,"BACKWARD");
	HX_VISIT_MEMBER_NAME(FlxPath_obj::LOOP_FORWARD,"LOOP_FORWARD");
	HX_VISIT_MEMBER_NAME(FlxPath_obj::LOOP_BACKWARD,"LOOP_BACKWARD");
	HX_VISIT_MEMBER_NAME(FlxPath_obj::YOYO,"YOYO");
	HX_VISIT_MEMBER_NAME(FlxPath_obj::HORIZONTAL_ONLY,"HORIZONTAL_ONLY");
	HX_VISIT_MEMBER_NAME(FlxPath_obj::VERTICAL_ONLY,"VERTICAL_ONLY");
	HX_VISIT_MEMBER_NAME(FlxPath_obj::_point,"_point");
	HX_VISIT_MEMBER_NAME(FlxPath_obj::manager,"manager");
};

#endif

Class FlxPath_obj::__mClass;

void FlxPath_obj::__register()
{
	hx::Static(__mClass) = hx::RegisterClass(HX_CSTRING("flixel.util.FlxPath"), hx::TCanCast< FlxPath_obj> ,sStaticFields,sMemberFields,
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

void FlxPath_obj::__boot()
{
	pool= ::flixel::util::FlxPool_flixel_util_FlxPath_obj::__new();
	FORWARD= (int)0;
	BACKWARD= (int)1;
	LOOP_FORWARD= (int)16;
	LOOP_BACKWARD= (int)256;
	YOYO= (int)4096;
	HORIZONTAL_ONLY= (int)65536;
	VERTICAL_ONLY= (int)1048576;
	_point= ::flixel::util::FlxPoint_obj::__new(null(),null());
}

} // end namespace flixel
} // end namespace util
