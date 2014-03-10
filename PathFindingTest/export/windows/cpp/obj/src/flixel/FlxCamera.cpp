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
#ifndef INCLUDED_flash_display_Graphics
#include <flash/display/Graphics.h>
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
#ifndef INCLUDED_flash_geom_ColorTransform
#include <flash/geom/ColorTransform.h>
#endif
#ifndef INCLUDED_flash_geom_Point
#include <flash/geom/Point.h>
#endif
#ifndef INCLUDED_flash_geom_Rectangle
#include <flash/geom/Rectangle.h>
#endif
#ifndef INCLUDED_flash_geom_Transform
#include <flash/geom/Transform.h>
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
#ifndef INCLUDED_flixel_FlxSprite
#include <flixel/FlxSprite.h>
#endif
#ifndef INCLUDED_flixel_interfaces_IFlxDestroyable
#include <flixel/interfaces/IFlxDestroyable.h>
#endif
#ifndef INCLUDED_flixel_system_frontEnds_CameraFrontEnd
#include <flixel/system/frontEnds/CameraFrontEnd.h>
#endif
#ifndef INCLUDED_flixel_system_layer_DrawStackItem
#include <flixel/system/layer/DrawStackItem.h>
#endif
#ifndef INCLUDED_flixel_system_layer_TileSheetData
#include <flixel/system/layer/TileSheetData.h>
#endif
#ifndef INCLUDED_flixel_system_layer_TileSheetExt
#include <flixel/system/layer/TileSheetExt.h>
#endif
#ifndef INCLUDED_flixel_util_FlxPoint
#include <flixel/util/FlxPoint.h>
#endif
#ifndef INCLUDED_flixel_util_FlxRandom
#include <flixel/util/FlxRandom.h>
#endif
#ifndef INCLUDED_flixel_util_FlxRect
#include <flixel/util/FlxRect.h>
#endif
#ifndef INCLUDED_flixel_util_loaders_CachedGraphics
#include <flixel/util/loaders/CachedGraphics.h>
#endif
#ifndef INCLUDED_hxMath
#include <hxMath.h>
#endif
#ifndef INCLUDED_openfl_display_Tilesheet
#include <openfl/display/Tilesheet.h>
#endif
namespace flixel{

Void FlxCamera_obj::__construct(hx::Null< int >  __o_X,hx::Null< int >  __o_Y,hx::Null< int >  __o_Width,hx::Null< int >  __o_Height,hx::Null< Float >  __o_Zoom)
{
HX_STACK_FRAME("flixel.FlxCamera","new",0x0e8a9f77,"flixel.FlxCamera.new","flixel/FlxCamera.hx",24,0xe7aeb95a)

HX_STACK_ARG(__o_X,"X")

HX_STACK_ARG(__o_Y,"Y")

HX_STACK_ARG(__o_Width,"Width")

HX_STACK_ARG(__o_Height,"Height")

HX_STACK_ARG(__o_Zoom,"Zoom")
int X = __o_X.Default(0);
int Y = __o_Y.Default(0);
int Width = __o_Width.Default(0);
int Height = __o_Height.Default(0);
Float Zoom = __o_Zoom.Default(0);
{
	HX_STACK_LINE(276)
	this->canvas = null();
	HX_STACK_LINE(255)
	this->_fxShakeDirection = (int)0;
	HX_STACK_LINE(247)
	this->_fxShakeComplete = null();
	HX_STACK_LINE(243)
	this->_fxShakeDuration = (int)0;
	HX_STACK_LINE(239)
	this->_fxShakeIntensity = (int)0;
	HX_STACK_LINE(235)
	this->_fxFadeAlpha = (int)0;
	HX_STACK_LINE(231)
	this->_fxFadeComplete = null();
	HX_STACK_LINE(227)
	this->_fxFadeIn = false;
	HX_STACK_LINE(223)
	this->_fxFadeDuration = (int)0;
	HX_STACK_LINE(211)
	this->_fxFadeColor = (int)0;
	HX_STACK_LINE(207)
	this->_fxFlashAlpha = (int)0;
	HX_STACK_LINE(203)
	this->_fxFlashComplete = null();
	HX_STACK_LINE(199)
	this->_fxFlashDuration = (int)0;
	HX_STACK_LINE(195)
	this->_fxFlashColor = (int)0;
	HX_STACK_LINE(173)
	this->antialiasing = false;
	HX_STACK_LINE(168)
	this->color = (int)-1;
	HX_STACK_LINE(163)
	this->angle = (int)0;
	HX_STACK_LINE(158)
	this->alpha = (int)1;
	HX_STACK_LINE(134)
	this->useBgAlphaBlending = true;
	HX_STACK_LINE(99)
	this->bounds = null();
	HX_STACK_LINE(94)
	this->deadzone = null();
	HX_STACK_LINE(85)
	this->target = null();
	HX_STACK_LINE(437)
	super::__construct();
	HX_STACK_LINE(439)
	this->_scrollTarget = ::flixel::util::FlxPoint_obj::__new(null(),null());
	HX_STACK_LINE(441)
	this->x = X;
	HX_STACK_LINE(442)
	this->y = Y;
	HX_STACK_LINE(444)
	this->set_width((  (((Width <= (int)0))) ? int(::flixel::FlxG_obj::width) : int(Width) ));
	HX_STACK_LINE(445)
	this->set_height((  (((Height <= (int)0))) ? int(::flixel::FlxG_obj::height) : int(Height) ));
	HX_STACK_LINE(447)
	this->scroll = ::flixel::util::FlxPoint_obj::__new(null(),null());
	HX_STACK_LINE(448)
	this->followLead = ::flixel::util::FlxPoint_obj::__new(null(),null());
	HX_STACK_LINE(449)
	this->_point = ::flixel::util::FlxPoint_obj::__new(null(),null());
	HX_STACK_LINE(450)
	this->_flashOffset = ::flixel::util::FlxPoint_obj::__new(null(),null());
	HX_STACK_LINE(464)
	this->canvas = ::flash::display::Sprite_obj::__new();
	HX_STACK_LINE(465)
	this->canvas->set_x((-(this->width) * 0.5));
	HX_STACK_LINE(466)
	this->canvas->set_y((-(this->height) * 0.5));
	HX_STACK_LINE(473)
	this->flashSprite = ::flash::display::Sprite_obj::__new();
	HX_STACK_LINE(474)
	this->set_zoom(Zoom);
	HX_STACK_LINE(476)
	this->_flashOffset->set(((this->width * 0.5) * this->zoom),((this->height * 0.5) * this->zoom));
	HX_STACK_LINE(478)
	this->flashSprite->set_x((this->x + this->_flashOffset->x));
	HX_STACK_LINE(479)
	this->flashSprite->set_y((this->y + this->_flashOffset->y));
	HX_STACK_LINE(484)
	this->flashSprite->addChild(this->canvas);
	HX_STACK_LINE(486)
	this->_flashRect = ::flash::geom::Rectangle_obj::__new((int)0,(int)0,this->width,this->height);
	HX_STACK_LINE(487)
	this->_flashPoint = ::flash::geom::Point_obj::__new(null(),null());
	HX_STACK_LINE(489)
	this->_fxShakeOffset = ::flixel::util::FlxPoint_obj::__new(null(),null());
	HX_STACK_LINE(496)
	this->canvas->set_scrollRect(::flash::geom::Rectangle_obj::__new((int)0,(int)0,this->width,this->height));
	HX_STACK_LINE(502)
	this->debugLayer = ::flash::display::Sprite_obj::__new();
	HX_STACK_LINE(503)
	this->debugLayer->set_x((-(this->width) * 0.5));
	HX_STACK_LINE(504)
	this->debugLayer->set_y((-(this->height) * 0.5));
	HX_STACK_LINE(505)
	this->debugLayer->set_scaleX((int)1);
	HX_STACK_LINE(506)
	this->flashSprite->addChild(this->debugLayer);
	HX_STACK_LINE(509)
	this->_currentStackItem = ::flixel::system::layer::DrawStackItem_obj::__new();
	HX_STACK_LINE(510)
	this->_headOfDrawStack = this->_currentStackItem;
	HX_STACK_LINE(513)
	this->bgColor = ::flixel::FlxG_obj::cameras->get_bgColor();
}
;
	return null();
}

//FlxCamera_obj::~FlxCamera_obj() { }

Dynamic FlxCamera_obj::__CreateEmpty() { return  new FlxCamera_obj; }
hx::ObjectPtr< FlxCamera_obj > FlxCamera_obj::__new(hx::Null< int >  __o_X,hx::Null< int >  __o_Y,hx::Null< int >  __o_Width,hx::Null< int >  __o_Height,hx::Null< Float >  __o_Zoom)
{  hx::ObjectPtr< FlxCamera_obj > result = new FlxCamera_obj();
	result->__construct(__o_X,__o_Y,__o_Width,__o_Height,__o_Zoom);
	return result;}

Dynamic FlxCamera_obj::__Create(hx::DynamicArray inArgs)
{  hx::ObjectPtr< FlxCamera_obj > result = new FlxCamera_obj();
	result->__construct(inArgs[0],inArgs[1],inArgs[2],inArgs[3],inArgs[4]);
	return result;}

::flixel::system::layer::DrawStackItem FlxCamera_obj::getDrawStackItem( ::flixel::util::loaders::CachedGraphics ObjGraphics,bool ObjColored,int ObjBlending,hx::Null< bool >  __o_ObjAntialiasing){
bool ObjAntialiasing = __o_ObjAntialiasing.Default(false);
	HX_STACK_FRAME("flixel.FlxCamera","getDrawStackItem",0x060ba7ea,"flixel.FlxCamera.getDrawStackItem","flixel/FlxCamera.hx",303,0xe7aeb95a)
	HX_STACK_THIS(this)
	HX_STACK_ARG(ObjGraphics,"ObjGraphics")
	HX_STACK_ARG(ObjColored,"ObjColored")
	HX_STACK_ARG(ObjBlending,"ObjBlending")
	HX_STACK_ARG(ObjAntialiasing,"ObjAntialiasing")
{
		HX_STACK_LINE(304)
		::flixel::system::layer::DrawStackItem itemToReturn = null();		HX_STACK_VAR(itemToReturn,"itemToReturn");
		HX_STACK_LINE(305)
		if (((this->_currentStackItem->initialized == false))){
			HX_STACK_LINE(307)
			this->_headOfDrawStack = this->_currentStackItem;
			HX_STACK_LINE(308)
			this->_currentStackItem->graphics = ObjGraphics;
			HX_STACK_LINE(309)
			this->_currentStackItem->antialiasing = ObjAntialiasing;
			HX_STACK_LINE(311)
			this->_currentStackItem->colored = ObjColored;
			HX_STACK_LINE(312)
			this->_currentStackItem->blending = ObjBlending;
			HX_STACK_LINE(316)
			itemToReturn = this->_currentStackItem;
		}
		else{
			HX_STACK_LINE(319)
			if (((bool((bool((bool((this->_currentStackItem->graphics == ObjGraphics)) && bool((this->_currentStackItem->colored == ObjColored)))) && bool((this->_currentStackItem->blending == ObjBlending)))) && bool((this->_currentStackItem->antialiasing == ObjAntialiasing))))){
				HX_STACK_LINE(328)
				itemToReturn = this->_currentStackItem;
			}
		}
		HX_STACK_LINE(331)
		if (((itemToReturn == null()))){
			HX_STACK_LINE(333)
			::flixel::system::layer::DrawStackItem newItem = null();		HX_STACK_VAR(newItem,"newItem");
			HX_STACK_LINE(334)
			if (((::flixel::FlxCamera_obj::_storageHead != null()))){
				HX_STACK_LINE(336)
				newItem = ::flixel::FlxCamera_obj::_storageHead;
				HX_STACK_LINE(337)
				::flixel::system::layer::DrawStackItem newHead = ::flixel::FlxCamera_obj::_storageHead->next;		HX_STACK_VAR(newHead,"newHead");
				HX_STACK_LINE(338)
				newItem->next = null();
				HX_STACK_LINE(339)
				::flixel::FlxCamera_obj::_storageHead = newHead;
			}
			else{
				HX_STACK_LINE(343)
				newItem = ::flixel::system::layer::DrawStackItem_obj::__new();
			}
			HX_STACK_LINE(346)
			newItem->graphics = ObjGraphics;
			HX_STACK_LINE(347)
			newItem->antialiasing = ObjAntialiasing;
			HX_STACK_LINE(349)
			newItem->colored = ObjColored;
			HX_STACK_LINE(350)
			newItem->blending = ObjBlending;
			HX_STACK_LINE(354)
			this->_currentStackItem->next = newItem;
			HX_STACK_LINE(355)
			this->_currentStackItem = newItem;
			HX_STACK_LINE(356)
			itemToReturn = this->_currentStackItem;
		}
		HX_STACK_LINE(359)
		itemToReturn->initialized = true;
		HX_STACK_LINE(360)
		return itemToReturn;
	}
}


HX_DEFINE_DYNAMIC_FUNC4(FlxCamera_obj,getDrawStackItem,return )

Void FlxCamera_obj::clearDrawStack( ){
{
		HX_STACK_FRAME("flixel.FlxCamera","clearDrawStack",0x8d7c5ba0,"flixel.FlxCamera.clearDrawStack","flixel/FlxCamera.hx",365,0xe7aeb95a)
		HX_STACK_THIS(this)
		HX_STACK_LINE(366)
		::flixel::system::layer::DrawStackItem currItem = this->_headOfDrawStack->next;		HX_STACK_VAR(currItem,"currItem");
		HX_STACK_LINE(367)
		while(((currItem != null()))){
			HX_STACK_LINE(369)
			{
				HX_STACK_LINE(369)
				currItem->graphics = null();
				HX_STACK_LINE(369)
				currItem->initialized = false;
				HX_STACK_LINE(369)
				currItem->antialiasing = false;
				HX_STACK_LINE(369)
				currItem->position = (int)0;
			}
			HX_STACK_LINE(370)
			::flixel::system::layer::DrawStackItem newStorageHead = currItem;		HX_STACK_VAR(newStorageHead,"newStorageHead");
			HX_STACK_LINE(371)
			currItem = currItem->next;
			HX_STACK_LINE(372)
			if (((::flixel::FlxCamera_obj::_storageHead == null()))){
				HX_STACK_LINE(374)
				::flixel::FlxCamera_obj::_storageHead = newStorageHead;
				HX_STACK_LINE(375)
				newStorageHead->next = null();
			}
			else{
				HX_STACK_LINE(379)
				newStorageHead->next = ::flixel::FlxCamera_obj::_storageHead;
				HX_STACK_LINE(380)
				::flixel::FlxCamera_obj::_storageHead = newStorageHead;
			}
		}
		HX_STACK_LINE(384)
		{
			HX_STACK_LINE(384)
			::flixel::system::layer::DrawStackItem _this = this->_headOfDrawStack;		HX_STACK_VAR(_this,"_this");
			HX_STACK_LINE(384)
			_this->graphics = null();
			HX_STACK_LINE(384)
			_this->initialized = false;
			HX_STACK_LINE(384)
			_this->antialiasing = false;
			HX_STACK_LINE(384)
			_this->position = (int)0;
		}
		HX_STACK_LINE(385)
		this->_headOfDrawStack->next = null();
		HX_STACK_LINE(386)
		this->_currentStackItem = this->_headOfDrawStack;
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC0(FlxCamera_obj,clearDrawStack,(void))

Void FlxCamera_obj::render( ){
{
		HX_STACK_FRAME("flixel.FlxCamera","render",0x1f11e49f,"flixel.FlxCamera.render","flixel/FlxCamera.hx",391,0xe7aeb95a)
		HX_STACK_THIS(this)
		HX_STACK_LINE(392)
		::flixel::system::layer::DrawStackItem currItem = this->_headOfDrawStack;		HX_STACK_VAR(currItem,"currItem");
		HX_STACK_LINE(393)
		while(((currItem != null()))){
			HX_STACK_LINE(395)
			Array< Float > data = currItem->drawData;		HX_STACK_VAR(data,"data");
			HX_STACK_LINE(396)
			int dataLen = data->length;		HX_STACK_VAR(dataLen,"dataLen");
			HX_STACK_LINE(397)
			int position = currItem->position;		HX_STACK_VAR(position,"position");
			HX_STACK_LINE(398)
			if (((position > (int)0))){
				HX_STACK_LINE(400)
				if (((dataLen != position))){
					HX_STACK_LINE(402)
					data->length = position;
				}
				HX_STACK_LINE(404)
				int tempFlags = (int)16;		HX_STACK_VAR(tempFlags,"tempFlags");
				HX_STACK_LINE(406)
				hx::OrEq(tempFlags,(int)8);
				HX_STACK_LINE(407)
				if ((currItem->colored)){
					HX_STACK_LINE(409)
					hx::OrEq(tempFlags,(int)4);
				}
				HX_STACK_LINE(411)
				hx::OrEq(tempFlags,currItem->blending);
				HX_STACK_LINE(418)
				currItem->graphics->get_tilesheet()->tileSheet->drawTiles(this->canvas->get_graphics(),data,(bool(this->antialiasing) || bool(currItem->antialiasing)),tempFlags,null());
				HX_STACK_LINE(419)
				(::flixel::system::layer::TileSheetExt_obj::_DRAWCALLS)++;
			}
			HX_STACK_LINE(421)
			currItem = currItem->next;
		}
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC0(FlxCamera_obj,render,(void))

Void FlxCamera_obj::destroy( ){
{
		HX_STACK_FRAME("flixel.FlxCamera","destroy",0xb607d391,"flixel.FlxCamera.destroy","flixel/FlxCamera.hx",520,0xe7aeb95a)
		HX_STACK_THIS(this)
		HX_STACK_LINE(524)
		this->target = null();
		HX_STACK_LINE(525)
		this->scroll = null();
		HX_STACK_LINE(526)
		this->deadzone = null();
		HX_STACK_LINE(527)
		this->bounds = null();
		HX_STACK_LINE(532)
		this->_flashRect = null();
		HX_STACK_LINE(533)
		this->_flashPoint = null();
		HX_STACK_LINE(534)
		this->_fxFlashComplete = null();
		HX_STACK_LINE(535)
		this->_fxFadeComplete = null();
		HX_STACK_LINE(536)
		this->_fxShakeComplete = null();
		HX_STACK_LINE(537)
		this->_fxShakeOffset = null();
		HX_STACK_LINE(547)
		this->flashSprite->removeChild(this->debugLayer);
		HX_STACK_LINE(548)
		this->debugLayer = null();
		HX_STACK_LINE(550)
		this->flashSprite->removeChild(this->canvas);
		HX_STACK_LINE(551)
		int canvasNumChildren = this->canvas->get_numChildren();		HX_STACK_VAR(canvasNumChildren,"canvasNumChildren");
		HX_STACK_LINE(552)
		{
			HX_STACK_LINE(552)
			int _g1 = (int)0;		HX_STACK_VAR(_g1,"_g1");
			HX_STACK_LINE(552)
			int _g = canvasNumChildren;		HX_STACK_VAR(_g,"_g");
			HX_STACK_LINE(552)
			while(((_g1 < _g))){
				HX_STACK_LINE(552)
				int i = (_g1)++;		HX_STACK_VAR(i,"i");
				HX_STACK_LINE(554)
				this->canvas->removeChildAt((int)0);
			}
		}
		HX_STACK_LINE(556)
		this->canvas = null();
		HX_STACK_LINE(558)
		this->clearDrawStack();
		HX_STACK_LINE(560)
		this->_headOfDrawStack->dispose();
		HX_STACK_LINE(561)
		this->_headOfDrawStack = null();
		HX_STACK_LINE(562)
		this->_currentStackItem = null();
		HX_STACK_LINE(564)
		this->flashSprite = null();
		HX_STACK_LINE(566)
		this->super::destroy();
	}
return null();
}


Void FlxCamera_obj::update( ){
{
		HX_STACK_FRAME("flixel.FlxCamera","update",0xa0edff52,"flixel.FlxCamera.update","flixel/FlxCamera.hx",573,0xe7aeb95a)
		HX_STACK_THIS(this)
		HX_STACK_LINE(575)
		if (((this->target != null()))){
			HX_STACK_LINE(577)
			this->updateFollow();
		}
		HX_STACK_LINE(581)
		if (((this->bounds != null()))){
			struct _Function_2_1{
				inline static Float Block( ::flixel::FlxCamera_obj *__this){
					HX_STACK_FRAME("*","closure",0x5bdab937,"*.closure","flixel/FlxCamera.hx",583,0xe7aeb95a)
					{
						HX_STACK_LINE(583)
						Float Value = __this->scroll->x;		HX_STACK_VAR(Value,"Value");
						HX_STACK_LINE(583)
						Float Min = __this->bounds->get_left();		HX_STACK_VAR(Min,"Min");
						HX_STACK_LINE(583)
						Float Max = (__this->bounds->get_right() - __this->width);		HX_STACK_VAR(Max,"Max");
						HX_STACK_LINE(583)
						Float lowerBound;		HX_STACK_VAR(lowerBound,"lowerBound");
						HX_STACK_LINE(583)
						if (((Value < Min))){
							HX_STACK_LINE(583)
							lowerBound = Min;
						}
						else{
							HX_STACK_LINE(583)
							lowerBound = Value;
						}
						HX_STACK_LINE(583)
						return (  (((lowerBound > Max))) ? Float(Max) : Float(lowerBound) );
					}
					return null();
				}
			};
			HX_STACK_LINE(583)
			this->scroll->set_x(_Function_2_1::Block(this));
			struct _Function_2_2{
				inline static Float Block( ::flixel::FlxCamera_obj *__this){
					HX_STACK_FRAME("*","closure",0x5bdab937,"*.closure","flixel/FlxCamera.hx",584,0xe7aeb95a)
					{
						HX_STACK_LINE(584)
						Float Value = __this->scroll->y;		HX_STACK_VAR(Value,"Value");
						HX_STACK_LINE(584)
						Float Min = __this->bounds->get_top();		HX_STACK_VAR(Min,"Min");
						HX_STACK_LINE(584)
						Float Max = (__this->bounds->get_bottom() - __this->height);		HX_STACK_VAR(Max,"Max");
						HX_STACK_LINE(584)
						Float lowerBound;		HX_STACK_VAR(lowerBound,"lowerBound");
						HX_STACK_LINE(584)
						if (((Value < Min))){
							HX_STACK_LINE(584)
							lowerBound = Min;
						}
						else{
							HX_STACK_LINE(584)
							lowerBound = Value;
						}
						HX_STACK_LINE(584)
						return (  (((lowerBound > Max))) ? Float(Max) : Float(lowerBound) );
					}
					return null();
				}
			};
			HX_STACK_LINE(584)
			this->scroll->set_y(_Function_2_2::Block(this));
		}
		HX_STACK_LINE(587)
		this->updateFlash();
		HX_STACK_LINE(588)
		this->updateFade();
		HX_STACK_LINE(589)
		this->updateShake();
	}
return null();
}


Void FlxCamera_obj::updateFollow( ){
{
		HX_STACK_FRAME("flixel.FlxCamera","updateFollow",0xf2024e63,"flixel.FlxCamera.updateFollow","flixel/FlxCamera.hx",596,0xe7aeb95a)
		HX_STACK_THIS(this)
		HX_STACK_LINE(596)
		if (((this->deadzone == null()))){
			HX_STACK_LINE(598)
			::flixel::util::FlxPoint point = this->target->getMidpoint(this->_point);		HX_STACK_VAR(point,"point");
			HX_STACK_LINE(598)
			this->scroll->set((point->x - (this->width * 0.5)),(point->y - (this->height * 0.5)));
		}
		else{
			HX_STACK_LINE(602)
			Float edge;		HX_STACK_VAR(edge,"edge");
			HX_STACK_LINE(603)
			Float targetX = this->target->x;		HX_STACK_VAR(targetX,"targetX");
			HX_STACK_LINE(604)
			Float targetY = this->target->y;		HX_STACK_VAR(targetY,"targetY");
			HX_STACK_LINE(606)
			if (((this->style == (int)4))){
				HX_STACK_LINE(608)
				if (((targetX > (this->scroll->x + this->width)))){
					HX_STACK_LINE(610)
					::flixel::util::FlxPoint _g = this->_scrollTarget;		HX_STACK_VAR(_g,"_g");
					HX_STACK_LINE(610)
					_g->set_x((_g->x + this->width));
				}
				else{
					HX_STACK_LINE(612)
					if (((targetX < this->scroll->x))){
						HX_STACK_LINE(614)
						::flixel::util::FlxPoint _g = this->_scrollTarget;		HX_STACK_VAR(_g,"_g");
						HX_STACK_LINE(614)
						_g->set_x((_g->x - this->width));
					}
				}
				HX_STACK_LINE(617)
				if (((targetY > (this->scroll->y + this->height)))){
					HX_STACK_LINE(619)
					::flixel::util::FlxPoint _g = this->_scrollTarget;		HX_STACK_VAR(_g,"_g");
					HX_STACK_LINE(619)
					_g->set_y((_g->y + this->height));
				}
				else{
					HX_STACK_LINE(621)
					if (((targetY < this->scroll->y))){
						HX_STACK_LINE(623)
						::flixel::util::FlxPoint _g = this->_scrollTarget;		HX_STACK_VAR(_g,"_g");
						HX_STACK_LINE(623)
						_g->set_y((_g->y - this->height));
					}
				}
			}
			else{
				HX_STACK_LINE(628)
				edge = (targetX - this->deadzone->x);
				HX_STACK_LINE(629)
				if (((this->_scrollTarget->x > edge))){
					HX_STACK_LINE(631)
					this->_scrollTarget->set_x(edge);
				}
				HX_STACK_LINE(633)
				edge = (((targetX + this->target->get_width()) - this->deadzone->x) - this->deadzone->width);
				HX_STACK_LINE(634)
				if (((this->_scrollTarget->x < edge))){
					HX_STACK_LINE(636)
					this->_scrollTarget->set_x(edge);
				}
				HX_STACK_LINE(639)
				edge = (targetY - this->deadzone->y);
				HX_STACK_LINE(640)
				if (((this->_scrollTarget->y > edge))){
					HX_STACK_LINE(642)
					this->_scrollTarget->set_y(edge);
				}
				HX_STACK_LINE(644)
				edge = (((targetY + this->target->get_height()) - this->deadzone->y) - this->deadzone->height);
				HX_STACK_LINE(645)
				if (((this->_scrollTarget->y < edge))){
					HX_STACK_LINE(647)
					this->_scrollTarget->set_y(edge);
				}
			}
			HX_STACK_LINE(651)
			if ((::Std_obj::is(this->target,hx::ClassOf< ::flixel::FlxSprite >()))){
				HX_STACK_LINE(653)
				if (((this->_lastTargetPosition == null()))){
					HX_STACK_LINE(655)
					this->_lastTargetPosition = ::flixel::util::FlxPoint_obj::__new(this->target->x,this->target->y);
				}
				HX_STACK_LINE(657)
				{
					HX_STACK_LINE(657)
					::flixel::util::FlxPoint _g = this->_scrollTarget;		HX_STACK_VAR(_g,"_g");
					HX_STACK_LINE(657)
					_g->set_x((_g->x + (((this->target->x - this->_lastTargetPosition->x)) * this->followLead->x)));
				}
				HX_STACK_LINE(658)
				{
					HX_STACK_LINE(658)
					::flixel::util::FlxPoint _g = this->_scrollTarget;		HX_STACK_VAR(_g,"_g");
					HX_STACK_LINE(658)
					_g->set_y((_g->y + (((this->target->y - this->_lastTargetPosition->y)) * this->followLead->y)));
				}
				HX_STACK_LINE(660)
				this->_lastTargetPosition->set_x(this->target->x);
				HX_STACK_LINE(661)
				this->_lastTargetPosition->set_y(this->target->y);
			}
			HX_STACK_LINE(664)
			if (((this->followLerp == (int)0))){
				HX_STACK_LINE(666)
				this->scroll->set_x(this->_scrollTarget->x);
				HX_STACK_LINE(667)
				this->scroll->set_y(this->_scrollTarget->y);
			}
			else{
				HX_STACK_LINE(671)
				{
					HX_STACK_LINE(671)
					::flixel::util::FlxPoint _g = this->scroll;		HX_STACK_VAR(_g,"_g");
					HX_STACK_LINE(671)
					_g->set_x((_g->x + (Float((((this->_scrollTarget->x - this->scroll->x)) * ::flixel::FlxG_obj::elapsed)) / Float(((::flixel::FlxG_obj::elapsed + (this->followLerp * ::flixel::FlxG_obj::elapsed)))))));
				}
				HX_STACK_LINE(672)
				{
					HX_STACK_LINE(672)
					::flixel::util::FlxPoint _g = this->scroll;		HX_STACK_VAR(_g,"_g");
					HX_STACK_LINE(672)
					_g->set_y((_g->y + (Float((((this->_scrollTarget->y - this->scroll->y)) * ::flixel::FlxG_obj::elapsed)) / Float(((::flixel::FlxG_obj::elapsed + (this->followLerp * ::flixel::FlxG_obj::elapsed)))))));
				}
			}
		}
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC0(FlxCamera_obj,updateFollow,(void))

Void FlxCamera_obj::updateFlash( ){
{
		HX_STACK_FRAME("flixel.FlxCamera","updateFlash",0x43f2dcfe,"flixel.FlxCamera.updateFlash","flixel/FlxCamera.hx",680,0xe7aeb95a)
		HX_STACK_THIS(this)
		HX_STACK_LINE(680)
		if (((this->_fxFlashAlpha > 0.0))){
			HX_STACK_LINE(682)
			hx::SubEq(this->_fxFlashAlpha,(Float(::flixel::FlxG_obj::elapsed) / Float(this->_fxFlashDuration)));
			HX_STACK_LINE(683)
			if (((bool((this->_fxFlashAlpha <= (int)0)) && bool((this->_fxFlashComplete_dyn() != null()))))){
				HX_STACK_LINE(685)
				this->_fxFlashComplete();
			}
		}
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC0(FlxCamera_obj,updateFlash,(void))

Void FlxCamera_obj::updateFade( ){
{
		HX_STACK_FRAME("flixel.FlxCamera","updateFade",0xaec3f1ee,"flixel.FlxCamera.updateFade","flixel/FlxCamera.hx",692,0xe7aeb95a)
		HX_STACK_THIS(this)
		HX_STACK_LINE(692)
		if (((bool((this->_fxFadeAlpha > 0.0)) && bool((this->_fxFadeAlpha < 1.0))))){
			HX_STACK_LINE(694)
			if ((this->_fxFadeIn)){
				HX_STACK_LINE(696)
				hx::SubEq(this->_fxFadeAlpha,(Float(::flixel::FlxG_obj::elapsed) / Float(this->_fxFadeDuration)));
				HX_STACK_LINE(697)
				if (((this->_fxFadeAlpha <= 0.0))){
					HX_STACK_LINE(699)
					this->_fxFadeAlpha = 0.0;
					HX_STACK_LINE(700)
					if (((this->_fxFadeComplete_dyn() != null()))){
						HX_STACK_LINE(702)
						this->_fxFadeComplete();
					}
				}
			}
			else{
				HX_STACK_LINE(708)
				hx::AddEq(this->_fxFadeAlpha,(Float(::flixel::FlxG_obj::elapsed) / Float(this->_fxFadeDuration)));
				HX_STACK_LINE(709)
				if (((this->_fxFadeAlpha >= 1.0))){
					HX_STACK_LINE(711)
					this->_fxFadeAlpha = 1.0;
					HX_STACK_LINE(712)
					if (((this->_fxFadeComplete_dyn() != null()))){
						HX_STACK_LINE(714)
						this->_fxFadeComplete();
					}
				}
			}
		}
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC0(FlxCamera_obj,updateFade,(void))

Void FlxCamera_obj::updateShake( ){
{
		HX_STACK_FRAME("flixel.FlxCamera","updateShake",0xbd838614,"flixel.FlxCamera.updateShake","flixel/FlxCamera.hx",723,0xe7aeb95a)
		HX_STACK_THIS(this)
		HX_STACK_LINE(723)
		if (((this->_fxShakeDuration > (int)0))){
			HX_STACK_LINE(725)
			hx::SubEq(this->_fxShakeDuration,::flixel::FlxG_obj::elapsed);
			HX_STACK_LINE(726)
			if (((this->_fxShakeDuration <= (int)0))){
				HX_STACK_LINE(728)
				this->_fxShakeOffset->set(null(),null());
				HX_STACK_LINE(729)
				if (((this->_fxShakeComplete_dyn() != null()))){
					HX_STACK_LINE(732)
					this->_fxShakeComplete();
				}
			}
			else{
				HX_STACK_LINE(737)
				if (((bool((this->_fxShakeDirection == (int)0)) || bool((this->_fxShakeDirection == (int)1))))){
					HX_STACK_LINE(739)
					this->_fxShakeOffset->set_x((((((((Float((::flixel::util::FlxRandom_obj::_internalSeed = (int(hx::Mod((::flixel::util::FlxRandom_obj::_internalSeed * (int)48271),(int)2147483647)) & int((int)2147483647)))) / Float((int)2147483647)) * this->_fxShakeIntensity) * this->width) * (int)2) - (this->_fxShakeIntensity * this->width))) * this->zoom));
				}
				HX_STACK_LINE(741)
				if (((bool((this->_fxShakeDirection == (int)0)) || bool((this->_fxShakeDirection == (int)2))))){
					HX_STACK_LINE(743)
					this->_fxShakeOffset->set_y((((((((Float((::flixel::util::FlxRandom_obj::_internalSeed = (int(hx::Mod((::flixel::util::FlxRandom_obj::_internalSeed * (int)48271),(int)2147483647)) & int((int)2147483647)))) / Float((int)2147483647)) * this->_fxShakeIntensity) * this->height) * (int)2) - (this->_fxShakeIntensity * this->height))) * this->zoom));
				}
			}
			HX_STACK_LINE(748)
			if (((this->target != null()))){
				HX_STACK_LINE(750)
				this->flashSprite->set_x((this->x + this->_flashOffset->x));
				HX_STACK_LINE(751)
				this->flashSprite->set_y((this->y + this->_flashOffset->y));
			}
		}
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC0(FlxCamera_obj,updateShake,(void))

Void FlxCamera_obj::follow( ::flixel::FlxObject Target,hx::Null< int >  __o_Style,::flixel::util::FlxPoint Offset,hx::Null< Float >  __o_Lerp){
int Style = __o_Style.Default(0);
Float Lerp = __o_Lerp.Default(0);
	HX_STACK_FRAME("flixel.FlxCamera","follow",0x137f0aba,"flixel.FlxCamera.follow","flixel/FlxCamera.hx",765,0xe7aeb95a)
	HX_STACK_THIS(this)
	HX_STACK_ARG(Target,"Target")
	HX_STACK_ARG(Style,"Style")
	HX_STACK_ARG(Offset,"Offset")
	HX_STACK_ARG(Lerp,"Lerp")
{
		HX_STACK_LINE(766)
		this->style = Style;
		HX_STACK_LINE(767)
		this->target = Target;
		HX_STACK_LINE(768)
		this->followLerp = Lerp;
		HX_STACK_LINE(769)
		Float helper;		HX_STACK_VAR(helper,"helper");
		HX_STACK_LINE(770)
		Float w = (int)0;		HX_STACK_VAR(w,"w");
		HX_STACK_LINE(771)
		Float h = (int)0;		HX_STACK_VAR(h,"h");
		HX_STACK_LINE(772)
		this->_lastTargetPosition = null();
		HX_STACK_LINE(774)
		switch( (int)(Style)){
			case (int)1: {
				HX_STACK_LINE(777)
				Float w1;		HX_STACK_VAR(w1,"w1");
				HX_STACK_LINE(777)
				w1 = ((Float(this->width) / Float((int)8)) + ((  (((Offset != null()))) ? Float(Offset->x) : Float((int)0) )));
				HX_STACK_LINE(778)
				Float h1;		HX_STACK_VAR(h1,"h1");
				HX_STACK_LINE(778)
				h1 = ((Float(this->height) / Float((int)3)) + ((  (((Offset != null()))) ? Float(Offset->y) : Float((int)0) )));
				HX_STACK_LINE(779)
				this->deadzone = ::flixel::util::FlxRect_obj::__new((Float(((this->width - w1))) / Float((int)2)),((Float(((this->height - h1))) / Float((int)2)) - (h1 * 0.25)),w1,h1);
			}
			;break;
			case (int)2: {
				HX_STACK_LINE(782)
				helper = (Float(::Math_obj::max(this->width,this->height)) / Float((int)4));
				HX_STACK_LINE(783)
				this->deadzone = ::flixel::util::FlxRect_obj::__new((Float(((this->width - helper))) / Float((int)2)),(Float(((this->height - helper))) / Float((int)2)),helper,helper);
			}
			;break;
			case (int)3: {
				HX_STACK_LINE(786)
				helper = (Float(::Math_obj::max(this->width,this->height)) / Float((int)8));
				HX_STACK_LINE(787)
				this->deadzone = ::flixel::util::FlxRect_obj::__new((Float(((this->width - helper))) / Float((int)2)),(Float(((this->height - helper))) / Float((int)2)),helper,helper);
			}
			;break;
			case (int)0: {
				HX_STACK_LINE(790)
				if (((this->target != null()))){
					HX_STACK_LINE(792)
					Float _g = this->target->get_width();		HX_STACK_VAR(_g,"_g");
					HX_STACK_LINE(792)
					w = (_g + ((  (((Offset != null()))) ? Float(Offset->x) : Float((int)0) )));
					HX_STACK_LINE(793)
					Float _g1 = this->target->get_height();		HX_STACK_VAR(_g1,"_g1");
					HX_STACK_LINE(793)
					h = (_g1 + ((  (((Offset != null()))) ? Float(Offset->y) : Float((int)0) )));
				}
				HX_STACK_LINE(795)
				this->deadzone = ::flixel::util::FlxRect_obj::__new((Float(((this->width - w))) / Float((int)2)),((Float(((this->height - h))) / Float((int)2)) - (h * 0.25)),w,h);
			}
			;break;
			case (int)4: {
				HX_STACK_LINE(798)
				this->deadzone = ::flixel::util::FlxRect_obj::__new((int)0,(int)0,this->width,this->height);
			}
			;break;
			default: {
				HX_STACK_LINE(801)
				this->deadzone = null();
			}
		}
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC4(FlxCamera_obj,follow,(void))

Void FlxCamera_obj::focusOn( ::flixel::util::FlxPoint point){
{
		HX_STACK_FRAME("flixel.FlxCamera","focusOn",0xd304f1ae,"flixel.FlxCamera.focusOn","flixel/FlxCamera.hx",813,0xe7aeb95a)
		HX_STACK_THIS(this)
		HX_STACK_ARG(point,"point")
		HX_STACK_LINE(813)
		this->scroll->set((point->x - (this->width * 0.5)),(point->y - (this->height * 0.5)));
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC1(FlxCamera_obj,focusOn,(void))

Void FlxCamera_obj::flash( hx::Null< int >  __o_Color,hx::Null< Float >  __o_Duration,Dynamic OnComplete,hx::Null< bool >  __o_Force){
int Color = __o_Color.Default(-1);
Float Duration = __o_Duration.Default(1);
bool Force = __o_Force.Default(false);
	HX_STACK_FRAME("flixel.FlxCamera","flash",0x27663887,"flixel.FlxCamera.flash","flixel/FlxCamera.hx",825,0xe7aeb95a)
	HX_STACK_THIS(this)
	HX_STACK_ARG(Color,"Color")
	HX_STACK_ARG(Duration,"Duration")
	HX_STACK_ARG(OnComplete,"OnComplete")
	HX_STACK_ARG(Force,"Force")
{
		HX_STACK_LINE(826)
		if (((bool(!(Force)) && bool((this->_fxFlashAlpha > 0.0))))){
			HX_STACK_LINE(828)
			return null();
		}
		HX_STACK_LINE(830)
		this->_fxFlashColor = Color;
		HX_STACK_LINE(831)
		if (((Duration <= (int)0))){
			HX_STACK_LINE(833)
			Duration = 5e-324;
		}
		HX_STACK_LINE(835)
		this->_fxFlashDuration = Duration;
		HX_STACK_LINE(836)
		this->_fxFlashComplete = OnComplete;
		HX_STACK_LINE(837)
		this->_fxFlashAlpha = 1.0;
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC4(FlxCamera_obj,flash,(void))

Void FlxCamera_obj::fade( hx::Null< int >  __o_Color,hx::Null< Float >  __o_Duration,hx::Null< bool >  __o_FadeIn,Dynamic OnComplete,hx::Null< bool >  __o_Force){
int Color = __o_Color.Default(-16777216);
Float Duration = __o_Duration.Default(1);
bool FadeIn = __o_FadeIn.Default(false);
bool Force = __o_Force.Default(false);
	HX_STACK_FRAME("flixel.FlxCamera","fade",0xa5741a85,"flixel.FlxCamera.fade","flixel/FlxCamera.hx",850,0xe7aeb95a)
	HX_STACK_THIS(this)
	HX_STACK_ARG(Color,"Color")
	HX_STACK_ARG(Duration,"Duration")
	HX_STACK_ARG(FadeIn,"FadeIn")
	HX_STACK_ARG(OnComplete,"OnComplete")
	HX_STACK_ARG(Force,"Force")
{
		HX_STACK_LINE(851)
		if (((bool(!(Force)) && bool((this->_fxFadeAlpha > 0.0))))){
			HX_STACK_LINE(853)
			return null();
		}
		HX_STACK_LINE(855)
		this->_fxFadeColor = Color;
		HX_STACK_LINE(856)
		if (((Duration <= (int)0))){
			HX_STACK_LINE(858)
			Duration = 5e-324;
		}
		HX_STACK_LINE(861)
		this->_fxFadeIn = FadeIn;
		HX_STACK_LINE(862)
		this->_fxFadeDuration = Duration;
		HX_STACK_LINE(863)
		this->_fxFadeComplete = OnComplete;
		HX_STACK_LINE(865)
		if ((this->_fxFadeIn)){
			HX_STACK_LINE(867)
			this->_fxFadeAlpha = 0.999999;
		}
		else{
			HX_STACK_LINE(871)
			this->_fxFadeAlpha = 5e-324;
		}
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC5(FlxCamera_obj,fade,(void))

Void FlxCamera_obj::shake( hx::Null< Float >  __o_Intensity,hx::Null< Float >  __o_Duration,Dynamic OnComplete,hx::Null< bool >  __o_Force,hx::Null< int >  __o_Direction){
Float Intensity = __o_Intensity.Default(0.05);
Float Duration = __o_Duration.Default(0.5);
bool Force = __o_Force.Default(true);
int Direction = __o_Direction.Default(0);
	HX_STACK_FRAME("flixel.FlxCamera","shake",0xa0f6e19d,"flixel.FlxCamera.shake","flixel/FlxCamera.hx",885,0xe7aeb95a)
	HX_STACK_THIS(this)
	HX_STACK_ARG(Intensity,"Intensity")
	HX_STACK_ARG(Duration,"Duration")
	HX_STACK_ARG(OnComplete,"OnComplete")
	HX_STACK_ARG(Force,"Force")
	HX_STACK_ARG(Direction,"Direction")
{
		HX_STACK_LINE(886)
		if (((bool(!(Force)) && bool(((bool((this->_fxShakeOffset->x != (int)0)) || bool((this->_fxShakeOffset->y != (int)0)))))))){
			HX_STACK_LINE(888)
			return null();
		}
		HX_STACK_LINE(890)
		this->_fxShakeIntensity = Intensity;
		HX_STACK_LINE(891)
		this->_fxShakeDuration = Duration;
		HX_STACK_LINE(892)
		this->_fxShakeComplete = OnComplete;
		HX_STACK_LINE(893)
		this->_fxShakeDirection = Direction;
		HX_STACK_LINE(894)
		this->_fxShakeOffset->set(null(),null());
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC5(FlxCamera_obj,shake,(void))

Void FlxCamera_obj::stopFX( ){
{
		HX_STACK_FRAME("flixel.FlxCamera","stopFX",0x29222b1d,"flixel.FlxCamera.stopFX","flixel/FlxCamera.hx",901,0xe7aeb95a)
		HX_STACK_THIS(this)
		HX_STACK_LINE(902)
		this->_fxFlashAlpha = 0.0;
		HX_STACK_LINE(903)
		this->_fxFadeAlpha = 0.0;
		HX_STACK_LINE(904)
		this->_fxShakeDuration = (int)0;
		HX_STACK_LINE(905)
		this->flashSprite->set_x((this->x + this->_flashOffset->x));
		HX_STACK_LINE(906)
		this->flashSprite->set_y((this->y + this->_flashOffset->y));
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC0(FlxCamera_obj,stopFX,(void))

::flixel::FlxCamera FlxCamera_obj::copyFrom( ::flixel::FlxCamera Camera){
	HX_STACK_FRAME("flixel.FlxCamera","copyFrom",0x88512948,"flixel.FlxCamera.copyFrom","flixel/FlxCamera.hx",916,0xe7aeb95a)
	HX_STACK_THIS(this)
	HX_STACK_ARG(Camera,"Camera")
	HX_STACK_LINE(917)
	if (((Camera->bounds == null()))){
		HX_STACK_LINE(919)
		this->bounds = null();
	}
	else{
		HX_STACK_LINE(923)
		if (((this->bounds == null()))){
			HX_STACK_LINE(925)
			this->bounds = ::flixel::util::FlxRect_obj::__new(null(),null(),null(),null());
		}
		HX_STACK_LINE(927)
		{
			HX_STACK_LINE(927)
			::flixel::util::FlxRect _this = this->bounds;		HX_STACK_VAR(_this,"_this");
			HX_STACK_LINE(927)
			::flixel::util::FlxRect Rect = Camera->bounds;		HX_STACK_VAR(Rect,"Rect");
			HX_STACK_LINE(927)
			_this->x = Rect->x;
			HX_STACK_LINE(927)
			_this->y = Rect->y;
			HX_STACK_LINE(927)
			_this->width = Rect->width;
			HX_STACK_LINE(927)
			_this->height = Rect->height;
			HX_STACK_LINE(927)
			_this;
		}
	}
	HX_STACK_LINE(929)
	this->target = Camera->target;
	HX_STACK_LINE(931)
	if (((this->target != null()))){
		HX_STACK_LINE(933)
		if (((Camera->deadzone == null()))){
			HX_STACK_LINE(935)
			this->deadzone = null();
		}
		else{
			HX_STACK_LINE(939)
			if (((this->deadzone == null()))){
				HX_STACK_LINE(941)
				this->deadzone = ::flixel::util::FlxRect_obj::__new(null(),null(),null(),null());
			}
			HX_STACK_LINE(943)
			{
				HX_STACK_LINE(943)
				::flixel::util::FlxRect _this = this->deadzone;		HX_STACK_VAR(_this,"_this");
				HX_STACK_LINE(943)
				::flixel::util::FlxRect Rect = Camera->deadzone;		HX_STACK_VAR(Rect,"Rect");
				HX_STACK_LINE(943)
				_this->x = Rect->x;
				HX_STACK_LINE(943)
				_this->y = Rect->y;
				HX_STACK_LINE(943)
				_this->width = Rect->width;
				HX_STACK_LINE(943)
				_this->height = Rect->height;
				HX_STACK_LINE(943)
				_this;
			}
		}
	}
	HX_STACK_LINE(946)
	return hx::ObjectPtr<OBJ_>(this);
}


HX_DEFINE_DYNAMIC_FUNC1(FlxCamera_obj,copyFrom,return )

Void FlxCamera_obj::fill( int Color,hx::Null< bool >  __o_BlendAlpha,hx::Null< Float >  __o_FxAlpha,::flash::display::Graphics graphics){
bool BlendAlpha = __o_BlendAlpha.Default(true);
Float FxAlpha = __o_FxAlpha.Default(1.0);
	HX_STACK_FRAME("flixel.FlxCamera","fill",0xa57a338c,"flixel.FlxCamera.fill","flixel/FlxCamera.hx",956,0xe7aeb95a)
	HX_STACK_THIS(this)
	HX_STACK_ARG(Color,"Color")
	HX_STACK_ARG(BlendAlpha,"BlendAlpha")
	HX_STACK_ARG(FxAlpha,"FxAlpha")
	HX_STACK_ARG(graphics,"graphics")
{
		HX_STACK_LINE(969)
		if (((FxAlpha == (int)0))){
			HX_STACK_LINE(971)
			return null();
		}
		HX_STACK_LINE(974)
		::flash::display::Graphics targetGraphics;		HX_STACK_VAR(targetGraphics,"targetGraphics");
		HX_STACK_LINE(974)
		if (((graphics == null()))){
			HX_STACK_LINE(974)
			targetGraphics = this->canvas->get_graphics();
		}
		else{
			HX_STACK_LINE(974)
			targetGraphics = graphics;
		}
		HX_STACK_LINE(975)
		Color = (int(Color) & int((int)16777215));
		HX_STACK_LINE(978)
		targetGraphics->beginFill(Color,FxAlpha);
		HX_STACK_LINE(979)
		targetGraphics->drawRect((int)0,(int)0,this->width,this->height);
		HX_STACK_LINE(980)
		targetGraphics->endFill();
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC4(FlxCamera_obj,fill,(void))

Void FlxCamera_obj::drawFX( ){
{
		HX_STACK_FRAME("flixel.FlxCamera","drawFX",0xf9beeb9f,"flixel.FlxCamera.drawFX","flixel/FlxCamera.hx",988,0xe7aeb95a)
		HX_STACK_THIS(this)
		HX_STACK_LINE(989)
		Float alphaComponent;		HX_STACK_VAR(alphaComponent,"alphaComponent");
		HX_STACK_LINE(992)
		if (((this->_fxFlashAlpha > 0.0))){
			HX_STACK_LINE(994)
			alphaComponent = (int((int(this->_fxFlashColor) >> int((int)24))) & int((int)255));
			HX_STACK_LINE(999)
			Float _g;		HX_STACK_VAR(_g,"_g");
			HX_STACK_LINE(999)
			if (((alphaComponent <= (int)0))){
				HX_STACK_LINE(999)
				_g = (int)255;
			}
			else{
				HX_STACK_LINE(999)
				_g = alphaComponent;
			}
			HX_STACK_LINE(999)
			this->fill((int(this->_fxFlashColor) & int((int)16777215)),true,(Float((_g * this->_fxFlashAlpha)) / Float((int)255)),this->canvas->get_graphics());
		}
		HX_STACK_LINE(1004)
		if (((this->_fxFadeAlpha > 0.0))){
			HX_STACK_LINE(1006)
			alphaComponent = (int((int(this->_fxFadeColor) >> int((int)24))) & int((int)255));
			HX_STACK_LINE(1011)
			Float _g1;		HX_STACK_VAR(_g1,"_g1");
			HX_STACK_LINE(1011)
			if (((alphaComponent <= (int)0))){
				HX_STACK_LINE(1011)
				_g1 = (int)255;
			}
			else{
				HX_STACK_LINE(1011)
				_g1 = alphaComponent;
			}
			HX_STACK_LINE(1011)
			this->fill((int(this->_fxFadeColor) & int((int)16777215)),true,(Float((_g1 * this->_fxFadeAlpha)) / Float((int)255)),this->canvas->get_graphics());
		}
		HX_STACK_LINE(1015)
		if (((bool((this->_fxShakeOffset->x != (int)0)) || bool((this->_fxShakeOffset->y != (int)0))))){
			HX_STACK_LINE(1017)
			{
				HX_STACK_LINE(1017)
				::flash::display::Sprite _g = this->flashSprite;		HX_STACK_VAR(_g,"_g");
				HX_STACK_LINE(1017)
				_g->set_x((_g->get_x() + this->_fxShakeOffset->x));
			}
			HX_STACK_LINE(1018)
			{
				HX_STACK_LINE(1018)
				::flash::display::Sprite _g = this->flashSprite;		HX_STACK_VAR(_g,"_g");
				HX_STACK_LINE(1018)
				_g->set_y((_g->get_y() + this->_fxShakeOffset->y));
			}
		}
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC0(FlxCamera_obj,drawFX,(void))

Void FlxCamera_obj::setSize( int Width,int Height){
{
		HX_STACK_FRAME("flixel.FlxCamera","setSize",0xa359881a,"flixel.FlxCamera.setSize","flixel/FlxCamera.hx",1052,0xe7aeb95a)
		HX_STACK_THIS(this)
		HX_STACK_ARG(Width,"Width")
		HX_STACK_ARG(Height,"Height")
		HX_STACK_LINE(1053)
		this->set_width(Width);
		HX_STACK_LINE(1054)
		this->set_height(Height);
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC2(FlxCamera_obj,setSize,(void))

Void FlxCamera_obj::setPosition( hx::Null< Float >  __o_X,hx::Null< Float >  __o_Y){
Float X = __o_X.Default(0);
Float Y = __o_Y.Default(0);
	HX_STACK_FRAME("flixel.FlxCamera","setPosition",0x5729a882,"flixel.FlxCamera.setPosition","flixel/FlxCamera.hx",1065,0xe7aeb95a)
	HX_STACK_THIS(this)
	HX_STACK_ARG(X,"X")
	HX_STACK_ARG(Y,"Y")
{
		HX_STACK_LINE(1066)
		this->x = X;
		HX_STACK_LINE(1067)
		this->y = Y;
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC2(FlxCamera_obj,setPosition,(void))

Void FlxCamera_obj::setBounds( hx::Null< Float >  __o_X,hx::Null< Float >  __o_Y,hx::Null< Float >  __o_Width,hx::Null< Float >  __o_Height,hx::Null< bool >  __o_UpdateWorld){
Float X = __o_X.Default(0);
Float Y = __o_Y.Default(0);
Float Width = __o_Width.Default(0);
Float Height = __o_Height.Default(0);
bool UpdateWorld = __o_UpdateWorld.Default(false);
	HX_STACK_FRAME("flixel.FlxCamera","setBounds",0xf7eeb60e,"flixel.FlxCamera.setBounds","flixel/FlxCamera.hx",1080,0xe7aeb95a)
	HX_STACK_THIS(this)
	HX_STACK_ARG(X,"X")
	HX_STACK_ARG(Y,"Y")
	HX_STACK_ARG(Width,"Width")
	HX_STACK_ARG(Height,"Height")
	HX_STACK_ARG(UpdateWorld,"UpdateWorld")
{
		HX_STACK_LINE(1081)
		if (((this->bounds == null()))){
			HX_STACK_LINE(1083)
			this->bounds = ::flixel::util::FlxRect_obj::__new(null(),null(),null(),null());
		}
		HX_STACK_LINE(1085)
		{
			HX_STACK_LINE(1085)
			::flixel::util::FlxRect _this = this->bounds;		HX_STACK_VAR(_this,"_this");
			HX_STACK_LINE(1085)
			_this->x = X;
			HX_STACK_LINE(1085)
			_this->y = Y;
			HX_STACK_LINE(1085)
			_this->width = Width;
			HX_STACK_LINE(1085)
			_this->height = Height;
			HX_STACK_LINE(1085)
			_this;
		}
		HX_STACK_LINE(1086)
		if ((UpdateWorld)){
			HX_STACK_LINE(1088)
			::flixel::util::FlxRect _this = ::flixel::FlxG_obj::worldBounds;		HX_STACK_VAR(_this,"_this");
			HX_STACK_LINE(1088)
			::flixel::util::FlxRect Rect = this->bounds;		HX_STACK_VAR(Rect,"Rect");
			HX_STACK_LINE(1088)
			_this->x = Rect->x;
			HX_STACK_LINE(1088)
			_this->y = Rect->y;
			HX_STACK_LINE(1088)
			_this->width = Rect->width;
			HX_STACK_LINE(1088)
			_this->height = Rect->height;
			HX_STACK_LINE(1088)
			_this;
		}
		HX_STACK_LINE(1090)
		this->update();
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC5(FlxCamera_obj,setBounds,(void))

Void FlxCamera_obj::setScale( Float X,Float Y){
{
		HX_STACK_FRAME("flixel.FlxCamera","setScale",0x46f35511,"flixel.FlxCamera.setScale","flixel/FlxCamera.hx",1094,0xe7aeb95a)
		HX_STACK_THIS(this)
		HX_STACK_ARG(X,"X")
		HX_STACK_ARG(Y,"Y")
		HX_STACK_LINE(1095)
		this->flashSprite->set_scaleX(X);
		HX_STACK_LINE(1096)
		this->flashSprite->set_scaleY(Y);
		HX_STACK_LINE(1099)
		this->_flashOffset->set_x(((this->width * 0.5) * X));
		HX_STACK_LINE(1100)
		this->_flashOffset->set_y(((this->height * 0.5) * Y));
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC2(FlxCamera_obj,setScale,(void))

::flixel::util::FlxPoint FlxCamera_obj::getScale( ){
	HX_STACK_FRAME("flixel.FlxCamera","getScale",0x9895fb9d,"flixel.FlxCamera.getScale","flixel/FlxCamera.hx",1108,0xe7aeb95a)
	HX_STACK_THIS(this)
	HX_STACK_LINE(1109)
	Float _g = this->flashSprite->get_scaleX();		HX_STACK_VAR(_g,"_g");
	HX_STACK_LINE(1109)
	return this->_point->set(_g,this->flashSprite->get_scaleY());
}


HX_DEFINE_DYNAMIC_FUNC0(FlxCamera_obj,getScale,return )

int FlxCamera_obj::set_width( int Value){
	HX_STACK_FRAME("flixel.FlxCamera","set_width",0x2386b8c0,"flixel.FlxCamera.set_width","flixel/FlxCamera.hx",1113,0xe7aeb95a)
	HX_STACK_THIS(this)
	HX_STACK_ARG(Value,"Value")
	HX_STACK_LINE(1114)
	if (((Value > (int)0))){
		HX_STACK_LINE(1116)
		this->width = Value;
		HX_STACK_LINE(1125)
		if (((this->canvas != null()))){
			HX_STACK_LINE(1127)
			::flash::geom::Rectangle rect = this->canvas->get_scrollRect();		HX_STACK_VAR(rect,"rect");
			HX_STACK_LINE(1129)
			rect->width = Value;
			HX_STACK_LINE(1133)
			this->canvas->set_scrollRect(rect);
			HX_STACK_LINE(1135)
			this->_flashOffset->set_x(((this->width * 0.5) * this->zoom));
			HX_STACK_LINE(1136)
			this->canvas->set_x((-(this->width) * 0.5));
			HX_STACK_LINE(1138)
			this->debugLayer->set_x(this->canvas->get_x());
		}
	}
	HX_STACK_LINE(1143)
	return Value;
}


HX_DEFINE_DYNAMIC_FUNC1(FlxCamera_obj,set_width,return )

int FlxCamera_obj::set_height( int Value){
	HX_STACK_FRAME("flixel.FlxCamera","set_height",0xa8aa67ed,"flixel.FlxCamera.set_height","flixel/FlxCamera.hx",1147,0xe7aeb95a)
	HX_STACK_THIS(this)
	HX_STACK_ARG(Value,"Value")
	HX_STACK_LINE(1148)
	if (((Value > (int)0))){
		HX_STACK_LINE(1150)
		this->height = Value;
		HX_STACK_LINE(1159)
		if (((this->canvas != null()))){
			HX_STACK_LINE(1161)
			::flash::geom::Rectangle rect = this->canvas->get_scrollRect();		HX_STACK_VAR(rect,"rect");
			HX_STACK_LINE(1163)
			rect->height = Value;
			HX_STACK_LINE(1167)
			this->canvas->set_scrollRect(rect);
			HX_STACK_LINE(1169)
			this->_flashOffset->set_y(((this->height * 0.5) * this->zoom));
			HX_STACK_LINE(1170)
			this->canvas->set_y((-(this->height) * 0.5));
			HX_STACK_LINE(1172)
			this->debugLayer->set_y(this->canvas->get_y());
		}
	}
	HX_STACK_LINE(1177)
	return Value;
}


HX_DEFINE_DYNAMIC_FUNC1(FlxCamera_obj,set_height,return )

Float FlxCamera_obj::set_zoom( Float Zoom){
	HX_STACK_FRAME("flixel.FlxCamera","set_zoom",0x3f00d599,"flixel.FlxCamera.set_zoom","flixel/FlxCamera.hx",1181,0xe7aeb95a)
	HX_STACK_THIS(this)
	HX_STACK_ARG(Zoom,"Zoom")
	HX_STACK_LINE(1182)
	if (((Zoom == (int)0))){
		HX_STACK_LINE(1184)
		this->zoom = ::flixel::FlxCamera_obj::defaultZoom;
	}
	else{
		HX_STACK_LINE(1188)
		this->zoom = Zoom;
	}
	HX_STACK_LINE(1190)
	this->setScale(this->zoom,this->zoom);
	HX_STACK_LINE(1191)
	return this->zoom;
}


HX_DEFINE_DYNAMIC_FUNC1(FlxCamera_obj,set_zoom,return )

Float FlxCamera_obj::set_alpha( Float Alpha){
	HX_STACK_FRAME("flixel.FlxCamera","set_alpha",0x7abaaa18,"flixel.FlxCamera.set_alpha","flixel/FlxCamera.hx",1195,0xe7aeb95a)
	HX_STACK_THIS(this)
	HX_STACK_ARG(Alpha,"Alpha")
	HX_STACK_LINE(1196)
	{
		HX_STACK_LINE(1196)
		Float lowerBound;		HX_STACK_VAR(lowerBound,"lowerBound");
		HX_STACK_LINE(1196)
		if (((Alpha < (int)0))){
			HX_STACK_LINE(1196)
			lowerBound = (int)0;
		}
		else{
			HX_STACK_LINE(1196)
			lowerBound = Alpha;
		}
		HX_STACK_LINE(1196)
		if (((lowerBound > (int)1))){
			HX_STACK_LINE(1196)
			this->alpha = (int)1;
		}
		else{
			HX_STACK_LINE(1196)
			this->alpha = lowerBound;
		}
	}
	HX_STACK_LINE(1200)
	this->canvas->set_alpha(Alpha);
	HX_STACK_LINE(1202)
	return Alpha;
}


HX_DEFINE_DYNAMIC_FUNC1(FlxCamera_obj,set_alpha,return )

Float FlxCamera_obj::set_angle( Float Angle){
	HX_STACK_FRAME("flixel.FlxCamera","set_angle",0x7c06468d,"flixel.FlxCamera.set_angle","flixel/FlxCamera.hx",1206,0xe7aeb95a)
	HX_STACK_THIS(this)
	HX_STACK_ARG(Angle,"Angle")
	HX_STACK_LINE(1207)
	this->angle = Angle;
	HX_STACK_LINE(1208)
	this->flashSprite->set_rotation(Angle);
	HX_STACK_LINE(1209)
	return Angle;
}


HX_DEFINE_DYNAMIC_FUNC1(FlxCamera_obj,set_angle,return )

int FlxCamera_obj::set_color( int Color){
	HX_STACK_FRAME("flixel.FlxCamera","set_color",0xa380741d,"flixel.FlxCamera.set_color","flixel/FlxCamera.hx",1213,0xe7aeb95a)
	HX_STACK_THIS(this)
	HX_STACK_ARG(Color,"Color")
	HX_STACK_LINE(1214)
	this->color = (int(Color) & int((int)16777215));
	HX_STACK_LINE(1225)
	::flash::geom::ColorTransform colorTransform = this->canvas->get_transform()->get_colorTransform();		HX_STACK_VAR(colorTransform,"colorTransform");
	HX_STACK_LINE(1226)
	colorTransform->redMultiplier = (Float(((int(this->color) >> int((int)16)))) / Float((int)255));
	HX_STACK_LINE(1227)
	colorTransform->greenMultiplier = (Float(((int((int(this->color) >> int((int)8))) & int((int)255)))) / Float((int)255));
	HX_STACK_LINE(1228)
	colorTransform->blueMultiplier = (Float(((int(this->color) & int((int)255)))) / Float((int)255));
	HX_STACK_LINE(1229)
	this->canvas->get_transform()->set_colorTransform(colorTransform);
	HX_STACK_LINE(1232)
	return Color;
}


HX_DEFINE_DYNAMIC_FUNC1(FlxCamera_obj,set_color,return )

bool FlxCamera_obj::set_antialiasing( bool Antialiasing){
	HX_STACK_FRAME("flixel.FlxCamera","set_antialiasing",0x0f9a3f7a,"flixel.FlxCamera.set_antialiasing","flixel/FlxCamera.hx",1236,0xe7aeb95a)
	HX_STACK_THIS(this)
	HX_STACK_ARG(Antialiasing,"Antialiasing")
	HX_STACK_LINE(1237)
	this->antialiasing = Antialiasing;
	HX_STACK_LINE(1241)
	return Antialiasing;
}


HX_DEFINE_DYNAMIC_FUNC1(FlxCamera_obj,set_antialiasing,return )

int FlxCamera_obj::STYLE_LOCKON;

int FlxCamera_obj::STYLE_PLATFORMER;

int FlxCamera_obj::STYLE_TOPDOWN;

int FlxCamera_obj::STYLE_TOPDOWN_TIGHT;

int FlxCamera_obj::STYLE_SCREEN_BY_SCREEN;

int FlxCamera_obj::STYLE_NO_DEAD_ZONE;

int FlxCamera_obj::SHAKE_BOTH_AXES;

int FlxCamera_obj::SHAKE_HORIZONTAL_ONLY;

int FlxCamera_obj::SHAKE_VERTICAL_ONLY;

Float FlxCamera_obj::defaultZoom;

::flixel::system::layer::DrawStackItem FlxCamera_obj::_storageHead;


FlxCamera_obj::FlxCamera_obj()
{
}

void FlxCamera_obj::__Mark(HX_MARK_PARAMS)
{
	HX_MARK_BEGIN_CLASS(FlxCamera);
	HX_MARK_MEMBER_NAME(x,"x");
	HX_MARK_MEMBER_NAME(y,"y");
	HX_MARK_MEMBER_NAME(style,"style");
	HX_MARK_MEMBER_NAME(target,"target");
	HX_MARK_MEMBER_NAME(followLerp,"followLerp");
	HX_MARK_MEMBER_NAME(deadzone,"deadzone");
	HX_MARK_MEMBER_NAME(bounds,"bounds");
	HX_MARK_MEMBER_NAME(scroll,"scroll");
	HX_MARK_MEMBER_NAME(bgColor,"bgColor");
	HX_MARK_MEMBER_NAME(useBgAlphaBlending,"useBgAlphaBlending");
	HX_MARK_MEMBER_NAME(flashSprite,"flashSprite");
	HX_MARK_MEMBER_NAME(width,"width");
	HX_MARK_MEMBER_NAME(height,"height");
	HX_MARK_MEMBER_NAME(zoom,"zoom");
	HX_MARK_MEMBER_NAME(alpha,"alpha");
	HX_MARK_MEMBER_NAME(angle,"angle");
	HX_MARK_MEMBER_NAME(color,"color");
	HX_MARK_MEMBER_NAME(antialiasing,"antialiasing");
	HX_MARK_MEMBER_NAME(followLead,"followLead");
	HX_MARK_MEMBER_NAME(_flashRect,"_flashRect");
	HX_MARK_MEMBER_NAME(_flashPoint,"_flashPoint");
	HX_MARK_MEMBER_NAME(_flashOffset,"_flashOffset");
	HX_MARK_MEMBER_NAME(_fxFlashColor,"_fxFlashColor");
	HX_MARK_MEMBER_NAME(_fxFlashDuration,"_fxFlashDuration");
	HX_MARK_MEMBER_NAME(_fxFlashComplete,"_fxFlashComplete");
	HX_MARK_MEMBER_NAME(_fxFlashAlpha,"_fxFlashAlpha");
	HX_MARK_MEMBER_NAME(_fxFadeColor,"_fxFadeColor");
	HX_MARK_MEMBER_NAME(_lastTargetPosition,"_lastTargetPosition");
	HX_MARK_MEMBER_NAME(_scrollTarget,"_scrollTarget");
	HX_MARK_MEMBER_NAME(_fxFadeDuration,"_fxFadeDuration");
	HX_MARK_MEMBER_NAME(_fxFadeIn,"_fxFadeIn");
	HX_MARK_MEMBER_NAME(_fxFadeComplete,"_fxFadeComplete");
	HX_MARK_MEMBER_NAME(_fxFadeAlpha,"_fxFadeAlpha");
	HX_MARK_MEMBER_NAME(_fxShakeIntensity,"_fxShakeIntensity");
	HX_MARK_MEMBER_NAME(_fxShakeDuration,"_fxShakeDuration");
	HX_MARK_MEMBER_NAME(_fxShakeComplete,"_fxShakeComplete");
	HX_MARK_MEMBER_NAME(_fxShakeOffset,"_fxShakeOffset");
	HX_MARK_MEMBER_NAME(_fxShakeDirection,"_fxShakeDirection");
	HX_MARK_MEMBER_NAME(_point,"_point");
	HX_MARK_MEMBER_NAME(canvas,"canvas");
	HX_MARK_MEMBER_NAME(debugLayer,"debugLayer");
	HX_MARK_MEMBER_NAME(_currentStackItem,"_currentStackItem");
	HX_MARK_MEMBER_NAME(_headOfDrawStack,"_headOfDrawStack");
	::flixel::FlxBasic_obj::__Mark(HX_MARK_ARG);
	HX_MARK_END_CLASS();
}

void FlxCamera_obj::__Visit(HX_VISIT_PARAMS)
{
	HX_VISIT_MEMBER_NAME(x,"x");
	HX_VISIT_MEMBER_NAME(y,"y");
	HX_VISIT_MEMBER_NAME(style,"style");
	HX_VISIT_MEMBER_NAME(target,"target");
	HX_VISIT_MEMBER_NAME(followLerp,"followLerp");
	HX_VISIT_MEMBER_NAME(deadzone,"deadzone");
	HX_VISIT_MEMBER_NAME(bounds,"bounds");
	HX_VISIT_MEMBER_NAME(scroll,"scroll");
	HX_VISIT_MEMBER_NAME(bgColor,"bgColor");
	HX_VISIT_MEMBER_NAME(useBgAlphaBlending,"useBgAlphaBlending");
	HX_VISIT_MEMBER_NAME(flashSprite,"flashSprite");
	HX_VISIT_MEMBER_NAME(width,"width");
	HX_VISIT_MEMBER_NAME(height,"height");
	HX_VISIT_MEMBER_NAME(zoom,"zoom");
	HX_VISIT_MEMBER_NAME(alpha,"alpha");
	HX_VISIT_MEMBER_NAME(angle,"angle");
	HX_VISIT_MEMBER_NAME(color,"color");
	HX_VISIT_MEMBER_NAME(antialiasing,"antialiasing");
	HX_VISIT_MEMBER_NAME(followLead,"followLead");
	HX_VISIT_MEMBER_NAME(_flashRect,"_flashRect");
	HX_VISIT_MEMBER_NAME(_flashPoint,"_flashPoint");
	HX_VISIT_MEMBER_NAME(_flashOffset,"_flashOffset");
	HX_VISIT_MEMBER_NAME(_fxFlashColor,"_fxFlashColor");
	HX_VISIT_MEMBER_NAME(_fxFlashDuration,"_fxFlashDuration");
	HX_VISIT_MEMBER_NAME(_fxFlashComplete,"_fxFlashComplete");
	HX_VISIT_MEMBER_NAME(_fxFlashAlpha,"_fxFlashAlpha");
	HX_VISIT_MEMBER_NAME(_fxFadeColor,"_fxFadeColor");
	HX_VISIT_MEMBER_NAME(_lastTargetPosition,"_lastTargetPosition");
	HX_VISIT_MEMBER_NAME(_scrollTarget,"_scrollTarget");
	HX_VISIT_MEMBER_NAME(_fxFadeDuration,"_fxFadeDuration");
	HX_VISIT_MEMBER_NAME(_fxFadeIn,"_fxFadeIn");
	HX_VISIT_MEMBER_NAME(_fxFadeComplete,"_fxFadeComplete");
	HX_VISIT_MEMBER_NAME(_fxFadeAlpha,"_fxFadeAlpha");
	HX_VISIT_MEMBER_NAME(_fxShakeIntensity,"_fxShakeIntensity");
	HX_VISIT_MEMBER_NAME(_fxShakeDuration,"_fxShakeDuration");
	HX_VISIT_MEMBER_NAME(_fxShakeComplete,"_fxShakeComplete");
	HX_VISIT_MEMBER_NAME(_fxShakeOffset,"_fxShakeOffset");
	HX_VISIT_MEMBER_NAME(_fxShakeDirection,"_fxShakeDirection");
	HX_VISIT_MEMBER_NAME(_point,"_point");
	HX_VISIT_MEMBER_NAME(canvas,"canvas");
	HX_VISIT_MEMBER_NAME(debugLayer,"debugLayer");
	HX_VISIT_MEMBER_NAME(_currentStackItem,"_currentStackItem");
	HX_VISIT_MEMBER_NAME(_headOfDrawStack,"_headOfDrawStack");
	::flixel::FlxBasic_obj::__Visit(HX_VISIT_ARG);
}

Dynamic FlxCamera_obj::__Field(const ::String &inName,bool inCallProp)
{
	switch(inName.length) {
	case 1:
		if (HX_FIELD_EQ(inName,"x") ) { return x; }
		if (HX_FIELD_EQ(inName,"y") ) { return y; }
		break;
	case 4:
		if (HX_FIELD_EQ(inName,"zoom") ) { return zoom; }
		if (HX_FIELD_EQ(inName,"fade") ) { return fade_dyn(); }
		if (HX_FIELD_EQ(inName,"fill") ) { return fill_dyn(); }
		break;
	case 5:
		if (HX_FIELD_EQ(inName,"style") ) { return style; }
		if (HX_FIELD_EQ(inName,"width") ) { return width; }
		if (HX_FIELD_EQ(inName,"alpha") ) { return alpha; }
		if (HX_FIELD_EQ(inName,"angle") ) { return angle; }
		if (HX_FIELD_EQ(inName,"color") ) { return color; }
		if (HX_FIELD_EQ(inName,"flash") ) { return flash_dyn(); }
		if (HX_FIELD_EQ(inName,"shake") ) { return shake_dyn(); }
		break;
	case 6:
		if (HX_FIELD_EQ(inName,"target") ) { return target; }
		if (HX_FIELD_EQ(inName,"bounds") ) { return bounds; }
		if (HX_FIELD_EQ(inName,"scroll") ) { return scroll; }
		if (HX_FIELD_EQ(inName,"height") ) { return height; }
		if (HX_FIELD_EQ(inName,"_point") ) { return _point; }
		if (HX_FIELD_EQ(inName,"canvas") ) { return canvas; }
		if (HX_FIELD_EQ(inName,"render") ) { return render_dyn(); }
		if (HX_FIELD_EQ(inName,"update") ) { return update_dyn(); }
		if (HX_FIELD_EQ(inName,"follow") ) { return follow_dyn(); }
		if (HX_FIELD_EQ(inName,"stopFX") ) { return stopFX_dyn(); }
		if (HX_FIELD_EQ(inName,"drawFX") ) { return drawFX_dyn(); }
		break;
	case 7:
		if (HX_FIELD_EQ(inName,"bgColor") ) { return bgColor; }
		if (HX_FIELD_EQ(inName,"destroy") ) { return destroy_dyn(); }
		if (HX_FIELD_EQ(inName,"focusOn") ) { return focusOn_dyn(); }
		if (HX_FIELD_EQ(inName,"setSize") ) { return setSize_dyn(); }
		break;
	case 8:
		if (HX_FIELD_EQ(inName,"deadzone") ) { return deadzone; }
		if (HX_FIELD_EQ(inName,"copyFrom") ) { return copyFrom_dyn(); }
		if (HX_FIELD_EQ(inName,"setScale") ) { return setScale_dyn(); }
		if (HX_FIELD_EQ(inName,"getScale") ) { return getScale_dyn(); }
		if (HX_FIELD_EQ(inName,"set_zoom") ) { return set_zoom_dyn(); }
		break;
	case 9:
		if (HX_FIELD_EQ(inName,"_fxFadeIn") ) { return _fxFadeIn; }
		if (HX_FIELD_EQ(inName,"setBounds") ) { return setBounds_dyn(); }
		if (HX_FIELD_EQ(inName,"set_width") ) { return set_width_dyn(); }
		if (HX_FIELD_EQ(inName,"set_alpha") ) { return set_alpha_dyn(); }
		if (HX_FIELD_EQ(inName,"set_angle") ) { return set_angle_dyn(); }
		if (HX_FIELD_EQ(inName,"set_color") ) { return set_color_dyn(); }
		break;
	case 10:
		if (HX_FIELD_EQ(inName,"followLerp") ) { return followLerp; }
		if (HX_FIELD_EQ(inName,"followLead") ) { return followLead; }
		if (HX_FIELD_EQ(inName,"_flashRect") ) { return _flashRect; }
		if (HX_FIELD_EQ(inName,"debugLayer") ) { return debugLayer; }
		if (HX_FIELD_EQ(inName,"updateFade") ) { return updateFade_dyn(); }
		if (HX_FIELD_EQ(inName,"set_height") ) { return set_height_dyn(); }
		break;
	case 11:
		if (HX_FIELD_EQ(inName,"defaultZoom") ) { return defaultZoom; }
		if (HX_FIELD_EQ(inName,"flashSprite") ) { return flashSprite; }
		if (HX_FIELD_EQ(inName,"_flashPoint") ) { return _flashPoint; }
		if (HX_FIELD_EQ(inName,"updateFlash") ) { return updateFlash_dyn(); }
		if (HX_FIELD_EQ(inName,"updateShake") ) { return updateShake_dyn(); }
		if (HX_FIELD_EQ(inName,"setPosition") ) { return setPosition_dyn(); }
		break;
	case 12:
		if (HX_FIELD_EQ(inName,"_storageHead") ) { return _storageHead; }
		if (HX_FIELD_EQ(inName,"antialiasing") ) { return antialiasing; }
		if (HX_FIELD_EQ(inName,"_flashOffset") ) { return _flashOffset; }
		if (HX_FIELD_EQ(inName,"_fxFadeColor") ) { return _fxFadeColor; }
		if (HX_FIELD_EQ(inName,"_fxFadeAlpha") ) { return _fxFadeAlpha; }
		if (HX_FIELD_EQ(inName,"updateFollow") ) { return updateFollow_dyn(); }
		break;
	case 13:
		if (HX_FIELD_EQ(inName,"_fxFlashColor") ) { return _fxFlashColor; }
		if (HX_FIELD_EQ(inName,"_fxFlashAlpha") ) { return _fxFlashAlpha; }
		if (HX_FIELD_EQ(inName,"_scrollTarget") ) { return _scrollTarget; }
		break;
	case 14:
		if (HX_FIELD_EQ(inName,"_fxShakeOffset") ) { return _fxShakeOffset; }
		if (HX_FIELD_EQ(inName,"clearDrawStack") ) { return clearDrawStack_dyn(); }
		break;
	case 15:
		if (HX_FIELD_EQ(inName,"_fxFadeDuration") ) { return _fxFadeDuration; }
		if (HX_FIELD_EQ(inName,"_fxFadeComplete") ) { return _fxFadeComplete; }
		break;
	case 16:
		if (HX_FIELD_EQ(inName,"_fxFlashDuration") ) { return _fxFlashDuration; }
		if (HX_FIELD_EQ(inName,"_fxFlashComplete") ) { return _fxFlashComplete; }
		if (HX_FIELD_EQ(inName,"_fxShakeDuration") ) { return _fxShakeDuration; }
		if (HX_FIELD_EQ(inName,"_fxShakeComplete") ) { return _fxShakeComplete; }
		if (HX_FIELD_EQ(inName,"_headOfDrawStack") ) { return _headOfDrawStack; }
		if (HX_FIELD_EQ(inName,"getDrawStackItem") ) { return getDrawStackItem_dyn(); }
		if (HX_FIELD_EQ(inName,"set_antialiasing") ) { return set_antialiasing_dyn(); }
		break;
	case 17:
		if (HX_FIELD_EQ(inName,"_fxShakeIntensity") ) { return _fxShakeIntensity; }
		if (HX_FIELD_EQ(inName,"_fxShakeDirection") ) { return _fxShakeDirection; }
		if (HX_FIELD_EQ(inName,"_currentStackItem") ) { return _currentStackItem; }
		break;
	case 18:
		if (HX_FIELD_EQ(inName,"useBgAlphaBlending") ) { return useBgAlphaBlending; }
		break;
	case 19:
		if (HX_FIELD_EQ(inName,"_lastTargetPosition") ) { return _lastTargetPosition; }
	}
	return super::__Field(inName,inCallProp);
}

Dynamic FlxCamera_obj::__SetField(const ::String &inName,const Dynamic &inValue,bool inCallProp)
{
	switch(inName.length) {
	case 1:
		if (HX_FIELD_EQ(inName,"x") ) { x=inValue.Cast< Float >(); return inValue; }
		if (HX_FIELD_EQ(inName,"y") ) { y=inValue.Cast< Float >(); return inValue; }
		break;
	case 4:
		if (HX_FIELD_EQ(inName,"zoom") ) { if (inCallProp) return set_zoom(inValue);zoom=inValue.Cast< Float >(); return inValue; }
		break;
	case 5:
		if (HX_FIELD_EQ(inName,"style") ) { style=inValue.Cast< int >(); return inValue; }
		if (HX_FIELD_EQ(inName,"width") ) { if (inCallProp) return set_width(inValue);width=inValue.Cast< int >(); return inValue; }
		if (HX_FIELD_EQ(inName,"alpha") ) { if (inCallProp) return set_alpha(inValue);alpha=inValue.Cast< Float >(); return inValue; }
		if (HX_FIELD_EQ(inName,"angle") ) { if (inCallProp) return set_angle(inValue);angle=inValue.Cast< Float >(); return inValue; }
		if (HX_FIELD_EQ(inName,"color") ) { if (inCallProp) return set_color(inValue);color=inValue.Cast< int >(); return inValue; }
		break;
	case 6:
		if (HX_FIELD_EQ(inName,"target") ) { target=inValue.Cast< ::flixel::FlxObject >(); return inValue; }
		if (HX_FIELD_EQ(inName,"bounds") ) { bounds=inValue.Cast< ::flixel::util::FlxRect >(); return inValue; }
		if (HX_FIELD_EQ(inName,"scroll") ) { scroll=inValue.Cast< ::flixel::util::FlxPoint >(); return inValue; }
		if (HX_FIELD_EQ(inName,"height") ) { if (inCallProp) return set_height(inValue);height=inValue.Cast< int >(); return inValue; }
		if (HX_FIELD_EQ(inName,"_point") ) { _point=inValue.Cast< ::flixel::util::FlxPoint >(); return inValue; }
		if (HX_FIELD_EQ(inName,"canvas") ) { canvas=inValue.Cast< ::flash::display::Sprite >(); return inValue; }
		break;
	case 7:
		if (HX_FIELD_EQ(inName,"bgColor") ) { bgColor=inValue.Cast< int >(); return inValue; }
		break;
	case 8:
		if (HX_FIELD_EQ(inName,"deadzone") ) { deadzone=inValue.Cast< ::flixel::util::FlxRect >(); return inValue; }
		break;
	case 9:
		if (HX_FIELD_EQ(inName,"_fxFadeIn") ) { _fxFadeIn=inValue.Cast< bool >(); return inValue; }
		break;
	case 10:
		if (HX_FIELD_EQ(inName,"followLerp") ) { followLerp=inValue.Cast< Float >(); return inValue; }
		if (HX_FIELD_EQ(inName,"followLead") ) { followLead=inValue.Cast< ::flixel::util::FlxPoint >(); return inValue; }
		if (HX_FIELD_EQ(inName,"_flashRect") ) { _flashRect=inValue.Cast< ::flash::geom::Rectangle >(); return inValue; }
		if (HX_FIELD_EQ(inName,"debugLayer") ) { debugLayer=inValue.Cast< ::flash::display::Sprite >(); return inValue; }
		break;
	case 11:
		if (HX_FIELD_EQ(inName,"defaultZoom") ) { defaultZoom=inValue.Cast< Float >(); return inValue; }
		if (HX_FIELD_EQ(inName,"flashSprite") ) { flashSprite=inValue.Cast< ::flash::display::Sprite >(); return inValue; }
		if (HX_FIELD_EQ(inName,"_flashPoint") ) { _flashPoint=inValue.Cast< ::flash::geom::Point >(); return inValue; }
		break;
	case 12:
		if (HX_FIELD_EQ(inName,"_storageHead") ) { _storageHead=inValue.Cast< ::flixel::system::layer::DrawStackItem >(); return inValue; }
		if (HX_FIELD_EQ(inName,"antialiasing") ) { if (inCallProp) return set_antialiasing(inValue);antialiasing=inValue.Cast< bool >(); return inValue; }
		if (HX_FIELD_EQ(inName,"_flashOffset") ) { _flashOffset=inValue.Cast< ::flixel::util::FlxPoint >(); return inValue; }
		if (HX_FIELD_EQ(inName,"_fxFadeColor") ) { _fxFadeColor=inValue.Cast< int >(); return inValue; }
		if (HX_FIELD_EQ(inName,"_fxFadeAlpha") ) { _fxFadeAlpha=inValue.Cast< Float >(); return inValue; }
		break;
	case 13:
		if (HX_FIELD_EQ(inName,"_fxFlashColor") ) { _fxFlashColor=inValue.Cast< int >(); return inValue; }
		if (HX_FIELD_EQ(inName,"_fxFlashAlpha") ) { _fxFlashAlpha=inValue.Cast< Float >(); return inValue; }
		if (HX_FIELD_EQ(inName,"_scrollTarget") ) { _scrollTarget=inValue.Cast< ::flixel::util::FlxPoint >(); return inValue; }
		break;
	case 14:
		if (HX_FIELD_EQ(inName,"_fxShakeOffset") ) { _fxShakeOffset=inValue.Cast< ::flixel::util::FlxPoint >(); return inValue; }
		break;
	case 15:
		if (HX_FIELD_EQ(inName,"_fxFadeDuration") ) { _fxFadeDuration=inValue.Cast< Float >(); return inValue; }
		if (HX_FIELD_EQ(inName,"_fxFadeComplete") ) { _fxFadeComplete=inValue.Cast< Dynamic >(); return inValue; }
		break;
	case 16:
		if (HX_FIELD_EQ(inName,"_fxFlashDuration") ) { _fxFlashDuration=inValue.Cast< Float >(); return inValue; }
		if (HX_FIELD_EQ(inName,"_fxFlashComplete") ) { _fxFlashComplete=inValue.Cast< Dynamic >(); return inValue; }
		if (HX_FIELD_EQ(inName,"_fxShakeDuration") ) { _fxShakeDuration=inValue.Cast< Float >(); return inValue; }
		if (HX_FIELD_EQ(inName,"_fxShakeComplete") ) { _fxShakeComplete=inValue.Cast< Dynamic >(); return inValue; }
		if (HX_FIELD_EQ(inName,"_headOfDrawStack") ) { _headOfDrawStack=inValue.Cast< ::flixel::system::layer::DrawStackItem >(); return inValue; }
		break;
	case 17:
		if (HX_FIELD_EQ(inName,"_fxShakeIntensity") ) { _fxShakeIntensity=inValue.Cast< Float >(); return inValue; }
		if (HX_FIELD_EQ(inName,"_fxShakeDirection") ) { _fxShakeDirection=inValue.Cast< int >(); return inValue; }
		if (HX_FIELD_EQ(inName,"_currentStackItem") ) { _currentStackItem=inValue.Cast< ::flixel::system::layer::DrawStackItem >(); return inValue; }
		break;
	case 18:
		if (HX_FIELD_EQ(inName,"useBgAlphaBlending") ) { useBgAlphaBlending=inValue.Cast< bool >(); return inValue; }
		break;
	case 19:
		if (HX_FIELD_EQ(inName,"_lastTargetPosition") ) { _lastTargetPosition=inValue.Cast< ::flixel::util::FlxPoint >(); return inValue; }
	}
	return super::__SetField(inName,inValue,inCallProp);
}

void FlxCamera_obj::__GetFields(Array< ::String> &outFields)
{
	outFields->push(HX_CSTRING("x"));
	outFields->push(HX_CSTRING("y"));
	outFields->push(HX_CSTRING("style"));
	outFields->push(HX_CSTRING("target"));
	outFields->push(HX_CSTRING("followLerp"));
	outFields->push(HX_CSTRING("deadzone"));
	outFields->push(HX_CSTRING("bounds"));
	outFields->push(HX_CSTRING("scroll"));
	outFields->push(HX_CSTRING("bgColor"));
	outFields->push(HX_CSTRING("useBgAlphaBlending"));
	outFields->push(HX_CSTRING("flashSprite"));
	outFields->push(HX_CSTRING("width"));
	outFields->push(HX_CSTRING("height"));
	outFields->push(HX_CSTRING("zoom"));
	outFields->push(HX_CSTRING("alpha"));
	outFields->push(HX_CSTRING("angle"));
	outFields->push(HX_CSTRING("color"));
	outFields->push(HX_CSTRING("antialiasing"));
	outFields->push(HX_CSTRING("followLead"));
	outFields->push(HX_CSTRING("_flashRect"));
	outFields->push(HX_CSTRING("_flashPoint"));
	outFields->push(HX_CSTRING("_flashOffset"));
	outFields->push(HX_CSTRING("_fxFlashColor"));
	outFields->push(HX_CSTRING("_fxFlashDuration"));
	outFields->push(HX_CSTRING("_fxFlashAlpha"));
	outFields->push(HX_CSTRING("_fxFadeColor"));
	outFields->push(HX_CSTRING("_lastTargetPosition"));
	outFields->push(HX_CSTRING("_scrollTarget"));
	outFields->push(HX_CSTRING("_fxFadeDuration"));
	outFields->push(HX_CSTRING("_fxFadeIn"));
	outFields->push(HX_CSTRING("_fxFadeAlpha"));
	outFields->push(HX_CSTRING("_fxShakeIntensity"));
	outFields->push(HX_CSTRING("_fxShakeDuration"));
	outFields->push(HX_CSTRING("_fxShakeOffset"));
	outFields->push(HX_CSTRING("_fxShakeDirection"));
	outFields->push(HX_CSTRING("_point"));
	outFields->push(HX_CSTRING("canvas"));
	outFields->push(HX_CSTRING("debugLayer"));
	outFields->push(HX_CSTRING("_currentStackItem"));
	outFields->push(HX_CSTRING("_headOfDrawStack"));
	super::__GetFields(outFields);
};

static ::String sStaticFields[] = {
	HX_CSTRING("STYLE_LOCKON"),
	HX_CSTRING("STYLE_PLATFORMER"),
	HX_CSTRING("STYLE_TOPDOWN"),
	HX_CSTRING("STYLE_TOPDOWN_TIGHT"),
	HX_CSTRING("STYLE_SCREEN_BY_SCREEN"),
	HX_CSTRING("STYLE_NO_DEAD_ZONE"),
	HX_CSTRING("SHAKE_BOTH_AXES"),
	HX_CSTRING("SHAKE_HORIZONTAL_ONLY"),
	HX_CSTRING("SHAKE_VERTICAL_ONLY"),
	HX_CSTRING("defaultZoom"),
	HX_CSTRING("_storageHead"),
	String(null()) };

#if HXCPP_SCRIPTABLE
static hx::StorageInfo sMemberStorageInfo[] = {
	{hx::fsFloat,(int)offsetof(FlxCamera_obj,x),HX_CSTRING("x")},
	{hx::fsFloat,(int)offsetof(FlxCamera_obj,y),HX_CSTRING("y")},
	{hx::fsInt,(int)offsetof(FlxCamera_obj,style),HX_CSTRING("style")},
	{hx::fsObject /*::flixel::FlxObject*/ ,(int)offsetof(FlxCamera_obj,target),HX_CSTRING("target")},
	{hx::fsFloat,(int)offsetof(FlxCamera_obj,followLerp),HX_CSTRING("followLerp")},
	{hx::fsObject /*::flixel::util::FlxRect*/ ,(int)offsetof(FlxCamera_obj,deadzone),HX_CSTRING("deadzone")},
	{hx::fsObject /*::flixel::util::FlxRect*/ ,(int)offsetof(FlxCamera_obj,bounds),HX_CSTRING("bounds")},
	{hx::fsObject /*::flixel::util::FlxPoint*/ ,(int)offsetof(FlxCamera_obj,scroll),HX_CSTRING("scroll")},
	{hx::fsInt,(int)offsetof(FlxCamera_obj,bgColor),HX_CSTRING("bgColor")},
	{hx::fsBool,(int)offsetof(FlxCamera_obj,useBgAlphaBlending),HX_CSTRING("useBgAlphaBlending")},
	{hx::fsObject /*::flash::display::Sprite*/ ,(int)offsetof(FlxCamera_obj,flashSprite),HX_CSTRING("flashSprite")},
	{hx::fsInt,(int)offsetof(FlxCamera_obj,width),HX_CSTRING("width")},
	{hx::fsInt,(int)offsetof(FlxCamera_obj,height),HX_CSTRING("height")},
	{hx::fsFloat,(int)offsetof(FlxCamera_obj,zoom),HX_CSTRING("zoom")},
	{hx::fsFloat,(int)offsetof(FlxCamera_obj,alpha),HX_CSTRING("alpha")},
	{hx::fsFloat,(int)offsetof(FlxCamera_obj,angle),HX_CSTRING("angle")},
	{hx::fsInt,(int)offsetof(FlxCamera_obj,color),HX_CSTRING("color")},
	{hx::fsBool,(int)offsetof(FlxCamera_obj,antialiasing),HX_CSTRING("antialiasing")},
	{hx::fsObject /*::flixel::util::FlxPoint*/ ,(int)offsetof(FlxCamera_obj,followLead),HX_CSTRING("followLead")},
	{hx::fsObject /*::flash::geom::Rectangle*/ ,(int)offsetof(FlxCamera_obj,_flashRect),HX_CSTRING("_flashRect")},
	{hx::fsObject /*::flash::geom::Point*/ ,(int)offsetof(FlxCamera_obj,_flashPoint),HX_CSTRING("_flashPoint")},
	{hx::fsObject /*::flixel::util::FlxPoint*/ ,(int)offsetof(FlxCamera_obj,_flashOffset),HX_CSTRING("_flashOffset")},
	{hx::fsInt,(int)offsetof(FlxCamera_obj,_fxFlashColor),HX_CSTRING("_fxFlashColor")},
	{hx::fsFloat,(int)offsetof(FlxCamera_obj,_fxFlashDuration),HX_CSTRING("_fxFlashDuration")},
	{hx::fsObject /*Dynamic*/ ,(int)offsetof(FlxCamera_obj,_fxFlashComplete),HX_CSTRING("_fxFlashComplete")},
	{hx::fsFloat,(int)offsetof(FlxCamera_obj,_fxFlashAlpha),HX_CSTRING("_fxFlashAlpha")},
	{hx::fsInt,(int)offsetof(FlxCamera_obj,_fxFadeColor),HX_CSTRING("_fxFadeColor")},
	{hx::fsObject /*::flixel::util::FlxPoint*/ ,(int)offsetof(FlxCamera_obj,_lastTargetPosition),HX_CSTRING("_lastTargetPosition")},
	{hx::fsObject /*::flixel::util::FlxPoint*/ ,(int)offsetof(FlxCamera_obj,_scrollTarget),HX_CSTRING("_scrollTarget")},
	{hx::fsFloat,(int)offsetof(FlxCamera_obj,_fxFadeDuration),HX_CSTRING("_fxFadeDuration")},
	{hx::fsBool,(int)offsetof(FlxCamera_obj,_fxFadeIn),HX_CSTRING("_fxFadeIn")},
	{hx::fsObject /*Dynamic*/ ,(int)offsetof(FlxCamera_obj,_fxFadeComplete),HX_CSTRING("_fxFadeComplete")},
	{hx::fsFloat,(int)offsetof(FlxCamera_obj,_fxFadeAlpha),HX_CSTRING("_fxFadeAlpha")},
	{hx::fsFloat,(int)offsetof(FlxCamera_obj,_fxShakeIntensity),HX_CSTRING("_fxShakeIntensity")},
	{hx::fsFloat,(int)offsetof(FlxCamera_obj,_fxShakeDuration),HX_CSTRING("_fxShakeDuration")},
	{hx::fsObject /*Dynamic*/ ,(int)offsetof(FlxCamera_obj,_fxShakeComplete),HX_CSTRING("_fxShakeComplete")},
	{hx::fsObject /*::flixel::util::FlxPoint*/ ,(int)offsetof(FlxCamera_obj,_fxShakeOffset),HX_CSTRING("_fxShakeOffset")},
	{hx::fsInt,(int)offsetof(FlxCamera_obj,_fxShakeDirection),HX_CSTRING("_fxShakeDirection")},
	{hx::fsObject /*::flixel::util::FlxPoint*/ ,(int)offsetof(FlxCamera_obj,_point),HX_CSTRING("_point")},
	{hx::fsObject /*::flash::display::Sprite*/ ,(int)offsetof(FlxCamera_obj,canvas),HX_CSTRING("canvas")},
	{hx::fsObject /*::flash::display::Sprite*/ ,(int)offsetof(FlxCamera_obj,debugLayer),HX_CSTRING("debugLayer")},
	{hx::fsObject /*::flixel::system::layer::DrawStackItem*/ ,(int)offsetof(FlxCamera_obj,_currentStackItem),HX_CSTRING("_currentStackItem")},
	{hx::fsObject /*::flixel::system::layer::DrawStackItem*/ ,(int)offsetof(FlxCamera_obj,_headOfDrawStack),HX_CSTRING("_headOfDrawStack")},
	{ hx::fsUnknown, 0, null()}
};
#endif

static ::String sMemberFields[] = {
	HX_CSTRING("x"),
	HX_CSTRING("y"),
	HX_CSTRING("style"),
	HX_CSTRING("target"),
	HX_CSTRING("followLerp"),
	HX_CSTRING("deadzone"),
	HX_CSTRING("bounds"),
	HX_CSTRING("scroll"),
	HX_CSTRING("bgColor"),
	HX_CSTRING("useBgAlphaBlending"),
	HX_CSTRING("flashSprite"),
	HX_CSTRING("width"),
	HX_CSTRING("height"),
	HX_CSTRING("zoom"),
	HX_CSTRING("alpha"),
	HX_CSTRING("angle"),
	HX_CSTRING("color"),
	HX_CSTRING("antialiasing"),
	HX_CSTRING("followLead"),
	HX_CSTRING("_flashRect"),
	HX_CSTRING("_flashPoint"),
	HX_CSTRING("_flashOffset"),
	HX_CSTRING("_fxFlashColor"),
	HX_CSTRING("_fxFlashDuration"),
	HX_CSTRING("_fxFlashComplete"),
	HX_CSTRING("_fxFlashAlpha"),
	HX_CSTRING("_fxFadeColor"),
	HX_CSTRING("_lastTargetPosition"),
	HX_CSTRING("_scrollTarget"),
	HX_CSTRING("_fxFadeDuration"),
	HX_CSTRING("_fxFadeIn"),
	HX_CSTRING("_fxFadeComplete"),
	HX_CSTRING("_fxFadeAlpha"),
	HX_CSTRING("_fxShakeIntensity"),
	HX_CSTRING("_fxShakeDuration"),
	HX_CSTRING("_fxShakeComplete"),
	HX_CSTRING("_fxShakeOffset"),
	HX_CSTRING("_fxShakeDirection"),
	HX_CSTRING("_point"),
	HX_CSTRING("canvas"),
	HX_CSTRING("debugLayer"),
	HX_CSTRING("_currentStackItem"),
	HX_CSTRING("_headOfDrawStack"),
	HX_CSTRING("getDrawStackItem"),
	HX_CSTRING("clearDrawStack"),
	HX_CSTRING("render"),
	HX_CSTRING("destroy"),
	HX_CSTRING("update"),
	HX_CSTRING("updateFollow"),
	HX_CSTRING("updateFlash"),
	HX_CSTRING("updateFade"),
	HX_CSTRING("updateShake"),
	HX_CSTRING("follow"),
	HX_CSTRING("focusOn"),
	HX_CSTRING("flash"),
	HX_CSTRING("fade"),
	HX_CSTRING("shake"),
	HX_CSTRING("stopFX"),
	HX_CSTRING("copyFrom"),
	HX_CSTRING("fill"),
	HX_CSTRING("drawFX"),
	HX_CSTRING("setSize"),
	HX_CSTRING("setPosition"),
	HX_CSTRING("setBounds"),
	HX_CSTRING("setScale"),
	HX_CSTRING("getScale"),
	HX_CSTRING("set_width"),
	HX_CSTRING("set_height"),
	HX_CSTRING("set_zoom"),
	HX_CSTRING("set_alpha"),
	HX_CSTRING("set_angle"),
	HX_CSTRING("set_color"),
	HX_CSTRING("set_antialiasing"),
	String(null()) };

static void sMarkStatics(HX_MARK_PARAMS) {
	HX_MARK_MEMBER_NAME(FlxCamera_obj::__mClass,"__mClass");
	HX_MARK_MEMBER_NAME(FlxCamera_obj::STYLE_LOCKON,"STYLE_LOCKON");
	HX_MARK_MEMBER_NAME(FlxCamera_obj::STYLE_PLATFORMER,"STYLE_PLATFORMER");
	HX_MARK_MEMBER_NAME(FlxCamera_obj::STYLE_TOPDOWN,"STYLE_TOPDOWN");
	HX_MARK_MEMBER_NAME(FlxCamera_obj::STYLE_TOPDOWN_TIGHT,"STYLE_TOPDOWN_TIGHT");
	HX_MARK_MEMBER_NAME(FlxCamera_obj::STYLE_SCREEN_BY_SCREEN,"STYLE_SCREEN_BY_SCREEN");
	HX_MARK_MEMBER_NAME(FlxCamera_obj::STYLE_NO_DEAD_ZONE,"STYLE_NO_DEAD_ZONE");
	HX_MARK_MEMBER_NAME(FlxCamera_obj::SHAKE_BOTH_AXES,"SHAKE_BOTH_AXES");
	HX_MARK_MEMBER_NAME(FlxCamera_obj::SHAKE_HORIZONTAL_ONLY,"SHAKE_HORIZONTAL_ONLY");
	HX_MARK_MEMBER_NAME(FlxCamera_obj::SHAKE_VERTICAL_ONLY,"SHAKE_VERTICAL_ONLY");
	HX_MARK_MEMBER_NAME(FlxCamera_obj::defaultZoom,"defaultZoom");
	HX_MARK_MEMBER_NAME(FlxCamera_obj::_storageHead,"_storageHead");
};

#ifdef HXCPP_VISIT_ALLOCS
static void sVisitStatics(HX_VISIT_PARAMS) {
	HX_VISIT_MEMBER_NAME(FlxCamera_obj::__mClass,"__mClass");
	HX_VISIT_MEMBER_NAME(FlxCamera_obj::STYLE_LOCKON,"STYLE_LOCKON");
	HX_VISIT_MEMBER_NAME(FlxCamera_obj::STYLE_PLATFORMER,"STYLE_PLATFORMER");
	HX_VISIT_MEMBER_NAME(FlxCamera_obj::STYLE_TOPDOWN,"STYLE_TOPDOWN");
	HX_VISIT_MEMBER_NAME(FlxCamera_obj::STYLE_TOPDOWN_TIGHT,"STYLE_TOPDOWN_TIGHT");
	HX_VISIT_MEMBER_NAME(FlxCamera_obj::STYLE_SCREEN_BY_SCREEN,"STYLE_SCREEN_BY_SCREEN");
	HX_VISIT_MEMBER_NAME(FlxCamera_obj::STYLE_NO_DEAD_ZONE,"STYLE_NO_DEAD_ZONE");
	HX_VISIT_MEMBER_NAME(FlxCamera_obj::SHAKE_BOTH_AXES,"SHAKE_BOTH_AXES");
	HX_VISIT_MEMBER_NAME(FlxCamera_obj::SHAKE_HORIZONTAL_ONLY,"SHAKE_HORIZONTAL_ONLY");
	HX_VISIT_MEMBER_NAME(FlxCamera_obj::SHAKE_VERTICAL_ONLY,"SHAKE_VERTICAL_ONLY");
	HX_VISIT_MEMBER_NAME(FlxCamera_obj::defaultZoom,"defaultZoom");
	HX_VISIT_MEMBER_NAME(FlxCamera_obj::_storageHead,"_storageHead");
};

#endif

Class FlxCamera_obj::__mClass;

void FlxCamera_obj::__register()
{
	hx::Static(__mClass) = hx::RegisterClass(HX_CSTRING("flixel.FlxCamera"), hx::TCanCast< FlxCamera_obj> ,sStaticFields,sMemberFields,
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

void FlxCamera_obj::__boot()
{
	STYLE_LOCKON= (int)0;
	STYLE_PLATFORMER= (int)1;
	STYLE_TOPDOWN= (int)2;
	STYLE_TOPDOWN_TIGHT= (int)3;
	STYLE_SCREEN_BY_SCREEN= (int)4;
	STYLE_NO_DEAD_ZONE= (int)5;
	SHAKE_BOTH_AXES= (int)0;
	SHAKE_HORIZONTAL_ONLY= (int)1;
	SHAKE_VERTICAL_ONLY= (int)2;
}

} // end namespace flixel
