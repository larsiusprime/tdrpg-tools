#include <hxcpp.h>

#ifndef INCLUDED_Std
#include <Std.h>
#endif
#ifndef INCLUDED_Type
#include <Type.h>
#endif
#ifndef INCLUDED_flash_display_BitmapData
#include <flash/display/BitmapData.h>
#endif
#ifndef INCLUDED_flash_display_BlendMode
#include <flash/display/BlendMode.h>
#endif
#ifndef INCLUDED_flash_display_IBitmapDrawable
#include <flash/display/IBitmapDrawable.h>
#endif
#ifndef INCLUDED_flash_geom_ColorTransform
#include <flash/geom/ColorTransform.h>
#endif
#ifndef INCLUDED_flash_geom_Matrix
#include <flash/geom/Matrix.h>
#endif
#ifndef INCLUDED_flash_geom_Point
#include <flash/geom/Point.h>
#endif
#ifndef INCLUDED_flash_geom_Rectangle
#include <flash/geom/Rectangle.h>
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
#ifndef INCLUDED_flixel__FlxSprite_GraphicDefault
#include <flixel/_FlxSprite/GraphicDefault.h>
#endif
#ifndef INCLUDED_flixel_animation_FlxAnimationController
#include <flixel/animation/FlxAnimationController.h>
#endif
#ifndef INCLUDED_flixel_interfaces_IFlxDestroyable
#include <flixel/interfaces/IFlxDestroyable.h>
#endif
#ifndef INCLUDED_flixel_system_debug_LogStyle
#include <flixel/system/debug/LogStyle.h>
#endif
#ifndef INCLUDED_flixel_system_frontEnds_BitmapFrontEnd
#include <flixel/system/frontEnds/BitmapFrontEnd.h>
#endif
#ifndef INCLUDED_flixel_system_frontEnds_CameraFrontEnd
#include <flixel/system/frontEnds/CameraFrontEnd.h>
#endif
#ifndef INCLUDED_flixel_system_frontEnds_LogFrontEnd
#include <flixel/system/frontEnds/LogFrontEnd.h>
#endif
#ifndef INCLUDED_flixel_system_layer_DrawStackItem
#include <flixel/system/layer/DrawStackItem.h>
#endif
#ifndef INCLUDED_flixel_system_layer_Region
#include <flixel/system/layer/Region.h>
#endif
#ifndef INCLUDED_flixel_system_layer_TileSheetData
#include <flixel/system/layer/TileSheetData.h>
#endif
#ifndef INCLUDED_flixel_system_layer_frames_FlxFrame
#include <flixel/system/layer/frames/FlxFrame.h>
#endif
#ifndef INCLUDED_flixel_system_layer_frames_FlxSpriteFrames
#include <flixel/system/layer/frames/FlxSpriteFrames.h>
#endif
#ifndef INCLUDED_flixel_util_FlxAngle
#include <flixel/util/FlxAngle.h>
#endif
#ifndef INCLUDED_flixel_util_FlxPoint
#include <flixel/util/FlxPoint.h>
#endif
#ifndef INCLUDED_flixel_util_loaders_CachedGraphics
#include <flixel/util/loaders/CachedGraphics.h>
#endif
#ifndef INCLUDED_flixel_util_loaders_TexturePackerData
#include <flixel/util/loaders/TexturePackerData.h>
#endif
#ifndef INCLUDED_flixel_util_loaders_TextureRegion
#include <flixel/util/loaders/TextureRegion.h>
#endif
#ifndef INCLUDED_hxMath
#include <hxMath.h>
#endif
namespace flixel{

Void FlxSprite_obj::__construct(hx::Null< Float >  __o_X,hx::Null< Float >  __o_Y,Dynamic SimpleGraphic)
{
HX_STACK_FRAME("flixel.FlxSprite","new",0x4dfa64d7,"flixel.FlxSprite.new","flixel/FlxSprite.hx",31,0x0384bffa)

HX_STACK_ARG(__o_X,"X")

HX_STACK_ARG(__o_Y,"Y")

HX_STACK_ARG(SimpleGraphic,"SimpleGraphic")
Float X = __o_X.Default(0);
Float Y = __o_Y.Default(0);
{
	HX_STACK_LINE(167)
	this->_angleChanged = false;
	HX_STACK_LINE(166)
	this->_cosAngle = (int)1;
	HX_STACK_LINE(165)
	this->_sinAngle = (int)0;
	HX_STACK_LINE(132)
	this->_blendInt = (int)0;
	HX_STACK_LINE(131)
	this->_facingMult = (int)1;
	HX_STACK_LINE(130)
	this->_blue = 1.0;
	HX_STACK_LINE(129)
	this->_green = 1.0;
	HX_STACK_LINE(128)
	this->_red = 1.0;
	HX_STACK_LINE(125)
	this->useColorTransform = false;
	HX_STACK_LINE(118)
	this->color = (int)16777215;
	HX_STACK_LINE(93)
	this->flipped = (int)0;
	HX_STACK_LINE(89)
	this->facing = (int)16;
	HX_STACK_LINE(84)
	this->alpha = 1.0;
	HX_STACK_LINE(80)
	this->bakedRotationAngle = (int)0;
	HX_STACK_LINE(75)
	this->frames = (int)0;
	HX_STACK_LINE(52)
	this->isColored = false;
	HX_STACK_LINE(49)
	this->dirty = true;
	HX_STACK_LINE(44)
	this->antialiasing = false;
	HX_STACK_LINE(179)
	super::__construct(X,Y,null(),null());
	HX_STACK_LINE(181)
	if (((SimpleGraphic != null()))){
		HX_STACK_LINE(183)
		this->loadGraphic(SimpleGraphic,null(),null(),null(),null(),null(),null());
	}
}
;
	return null();
}

//FlxSprite_obj::~FlxSprite_obj() { }

Dynamic FlxSprite_obj::__CreateEmpty() { return  new FlxSprite_obj; }
hx::ObjectPtr< FlxSprite_obj > FlxSprite_obj::__new(hx::Null< Float >  __o_X,hx::Null< Float >  __o_Y,Dynamic SimpleGraphic)
{  hx::ObjectPtr< FlxSprite_obj > result = new FlxSprite_obj();
	result->__construct(__o_X,__o_Y,SimpleGraphic);
	return result;}

Dynamic FlxSprite_obj::__Create(hx::DynamicArray inArgs)
{  hx::ObjectPtr< FlxSprite_obj > result = new FlxSprite_obj();
	result->__construct(inArgs[0],inArgs[1],inArgs[2]);
	return result;}

Void FlxSprite_obj::initVars( ){
{
		HX_STACK_FRAME("flixel.FlxSprite","initVars",0x31793705,"flixel.FlxSprite.initVars","flixel/FlxSprite.hx",188,0x0384bffa)
		HX_STACK_THIS(this)
		HX_STACK_LINE(189)
		this->super::initVars();
		HX_STACK_LINE(191)
		this->animation = ::flixel::animation::FlxAnimationController_obj::__new(hx::ObjectPtr<OBJ_>(this));
		HX_STACK_LINE(193)
		this->_flashPoint = ::flash::geom::Point_obj::__new(null(),null());
		HX_STACK_LINE(194)
		this->_flashRect = ::flash::geom::Rectangle_obj::__new(null(),null(),null(),null());
		HX_STACK_LINE(195)
		this->_flashRect2 = ::flash::geom::Rectangle_obj::__new(null(),null(),null(),null());
		HX_STACK_LINE(196)
		this->_flashPointZero = ::flash::geom::Point_obj::__new(null(),null());
		HX_STACK_LINE(197)
		this->offset = ::flixel::util::FlxPoint_obj::__new(null(),null());
		HX_STACK_LINE(198)
		this->origin = ::flixel::util::FlxPoint_obj::__new(null(),null());
		HX_STACK_LINE(199)
		this->scale = ::flixel::util::FlxPoint_obj::__new((int)1,(int)1);
		HX_STACK_LINE(200)
		this->_matrix = ::flash::geom::Matrix_obj::__new(null(),null(),null(),null(),null(),null());
	}
return null();
}


Void FlxSprite_obj::destroy( ){
{
		HX_STACK_FRAME("flixel.FlxSprite","destroy",0x0fb5c8f1,"flixel.FlxSprite.destroy","flixel/FlxSprite.hx",208,0x0384bffa)
		HX_STACK_THIS(this)
		HX_STACK_LINE(209)
		this->super::destroy();
		HX_STACK_LINE(211)
		this->animation = ::flixel::FlxG_obj::safeDestroy(this->animation);
		HX_STACK_LINE(213)
		this->_flashPoint = null();
		HX_STACK_LINE(214)
		this->_flashRect = null();
		HX_STACK_LINE(215)
		this->_flashRect2 = null();
		HX_STACK_LINE(216)
		this->_flashPointZero = null();
		HX_STACK_LINE(217)
		this->offset = null();
		HX_STACK_LINE(218)
		this->origin = null();
		HX_STACK_LINE(219)
		this->scale = null();
		HX_STACK_LINE(220)
		this->_matrix = null();
		HX_STACK_LINE(221)
		this->_colorTransform = null();
		HX_STACK_LINE(222)
		if (((this->framePixels != null()))){
			HX_STACK_LINE(224)
			this->framePixels->dispose();
		}
		HX_STACK_LINE(226)
		this->framePixels = null();
		HX_STACK_LINE(227)
		this->set_blend(null());
		HX_STACK_LINE(228)
		this->set_frame(null());
	}
return null();
}


::flixel::FlxSprite FlxSprite_obj::clone( ::flixel::FlxSprite NewSprite){
	HX_STACK_FRAME("flixel.FlxSprite","clone",0x3c30f394,"flixel.FlxSprite.clone","flixel/FlxSprite.hx",232,0x0384bffa)
	HX_STACK_THIS(this)
	HX_STACK_ARG(NewSprite,"NewSprite")
	HX_STACK_LINE(233)
	if (((NewSprite == null()))){
		HX_STACK_LINE(235)
		NewSprite = ::flixel::FlxSprite_obj::__new(null(),null(),null());
	}
	HX_STACK_LINE(238)
	return NewSprite->loadGraphicFromSprite(hx::ObjectPtr<OBJ_>(this));
}


HX_DEFINE_DYNAMIC_FUNC1(FlxSprite_obj,clone,return )

::flixel::FlxSprite FlxSprite_obj::loadGraphicFromSprite( ::flixel::FlxSprite Sprite){
	HX_STACK_FRAME("flixel.FlxSprite","loadGraphicFromSprite",0xd0637b08,"flixel.FlxSprite.loadGraphicFromSprite","flixel/FlxSprite.hx",249,0x0384bffa)
	HX_STACK_THIS(this)
	HX_STACK_ARG(Sprite,"Sprite")
	HX_STACK_LINE(250)
	if ((!(this->exists))){
		HX_STACK_LINE(252)
		Dynamic Data = ((HX_CSTRING("Warning, trying to clone ") + ::Type_obj::getClassName(::Type_obj::getClass(hx::ObjectPtr<OBJ_>(this)))) + HX_CSTRING(" object that doesn't exist."));		HX_STACK_VAR(Data,"Data");
		HX_STACK_LINE(252)
		::flixel::FlxG_obj::log->advanced(Data,::flixel::system::debug::LogStyle_obj::WARNING,true);
	}
	HX_STACK_LINE(255)
	this->region = Sprite->region->clone();
	HX_STACK_LINE(256)
	this->flipped = Sprite->flipped;
	HX_STACK_LINE(257)
	this->bakedRotationAngle = Sprite->bakedRotationAngle;
	HX_STACK_LINE(258)
	this->set_cachedGraphics(Sprite->cachedGraphics);
	HX_STACK_LINE(260)
	this->set_width(this->frameWidth = Sprite->frameWidth);
	HX_STACK_LINE(261)
	this->set_height(this->frameHeight = Sprite->frameHeight);
	HX_STACK_LINE(262)
	if (((this->bakedRotationAngle > (int)0))){
		HX_STACK_LINE(264)
		this->set_width(Sprite->get_width());
		HX_STACK_LINE(265)
		this->set_height(Sprite->get_height());
		HX_STACK_LINE(266)
		this->centerOffsets(null());
	}
	HX_STACK_LINE(269)
	this->updateFrameData();
	HX_STACK_LINE(270)
	this->resetHelpers();
	HX_STACK_LINE(271)
	this->antialiasing = Sprite->antialiasing;
	HX_STACK_LINE(272)
	this->animation->copyFrom(Sprite->animation);
	HX_STACK_LINE(273)
	return hx::ObjectPtr<OBJ_>(this);
}


HX_DEFINE_DYNAMIC_FUNC1(FlxSprite_obj,loadGraphicFromSprite,return )

::flixel::FlxSprite FlxSprite_obj::loadGraphic( Dynamic Graphic,hx::Null< bool >  __o_Animated,hx::Null< bool >  __o_Reverse,hx::Null< int >  __o_Width,hx::Null< int >  __o_Height,hx::Null< bool >  __o_Unique,::String Key){
bool Animated = __o_Animated.Default(false);
bool Reverse = __o_Reverse.Default(false);
int Width = __o_Width.Default(0);
int Height = __o_Height.Default(0);
bool Unique = __o_Unique.Default(false);
	HX_STACK_FRAME("flixel.FlxSprite","loadGraphic",0x47377c99,"flixel.FlxSprite.loadGraphic","flixel/FlxSprite.hx",289,0x0384bffa)
	HX_STACK_THIS(this)
	HX_STACK_ARG(Graphic,"Graphic")
	HX_STACK_ARG(Animated,"Animated")
	HX_STACK_ARG(Reverse,"Reverse")
	HX_STACK_ARG(Width,"Width")
	HX_STACK_ARG(Height,"Height")
	HX_STACK_ARG(Unique,"Unique")
	HX_STACK_ARG(Key,"Key")
{
		HX_STACK_LINE(290)
		this->bakedRotationAngle = (int)0;
		HX_STACK_LINE(291)
		this->set_cachedGraphics(::flixel::FlxG_obj::bitmap->add(Graphic,Unique,Key));
		HX_STACK_LINE(293)
		if (((Reverse == true))){
			HX_STACK_LINE(293)
			this->flipped = this->cachedGraphics->bitmap->get_width();
		}
		else{
			HX_STACK_LINE(293)
			this->flipped = (int)0;
		}
		HX_STACK_LINE(295)
		if (((Width == (int)0))){
			HX_STACK_LINE(297)
			if (((Animated == true))){
				HX_STACK_LINE(297)
				Width = this->cachedGraphics->bitmap->get_height();
			}
			else{
				HX_STACK_LINE(297)
				Width = this->cachedGraphics->bitmap->get_width();
			}
			HX_STACK_LINE(298)
			if (((Width > this->cachedGraphics->bitmap->get_width()))){
				HX_STACK_LINE(298)
				Width = this->cachedGraphics->bitmap->get_width();
			}
			else{
				HX_STACK_LINE(298)
				Width = Width;
			}
		}
		HX_STACK_LINE(301)
		if (((Height == (int)0))){
			HX_STACK_LINE(303)
			if (((Animated == true))){
				HX_STACK_LINE(303)
				Height = Width;
			}
			else{
				HX_STACK_LINE(303)
				Height = this->cachedGraphics->bitmap->get_height();
			}
			HX_STACK_LINE(304)
			if (((Height > this->cachedGraphics->bitmap->get_height()))){
				HX_STACK_LINE(304)
				Height = this->cachedGraphics->bitmap->get_height();
			}
			else{
				HX_STACK_LINE(304)
				Height = Height;
			}
		}
		HX_STACK_LINE(307)
		if ((!(::Std_obj::is(Graphic,hx::ClassOf< ::flixel::util::loaders::TextureRegion >())))){
			HX_STACK_LINE(309)
			this->region = ::flixel::system::layer::Region_obj::__new((int)0,(int)0,Width,Height,null(),null(),null(),null());
			HX_STACK_LINE(310)
			this->region->width = this->cachedGraphics->bitmap->get_width();
			HX_STACK_LINE(311)
			this->region->height = this->cachedGraphics->bitmap->get_height();
		}
		else{
			HX_STACK_LINE(315)
			this->region = (hx::TCast< flixel::util::loaders::TextureRegion >::cast(Graphic))->region->clone();
			HX_STACK_LINE(317)
			if (((this->region->tileWidth > (int)0))){
				HX_STACK_LINE(318)
				Width = this->region->tileWidth;
			}
			else{
				HX_STACK_LINE(320)
				this->region->tileWidth = this->region->width;
			}
			HX_STACK_LINE(322)
			if (((this->region->tileHeight > (int)0))){
				HX_STACK_LINE(323)
				Height = this->region->tileWidth;
			}
			else{
				HX_STACK_LINE(325)
				this->region->tileHeight = this->region->height;
			}
		}
		HX_STACK_LINE(328)
		this->set_width(this->frameWidth = Width);
		HX_STACK_LINE(329)
		this->set_height(this->frameHeight = Height);
		HX_STACK_LINE(331)
		this->animation->destroyAnimations();
		HX_STACK_LINE(333)
		this->updateFrameData();
		HX_STACK_LINE(334)
		this->resetHelpers();
		HX_STACK_LINE(336)
		return hx::ObjectPtr<OBJ_>(this);
	}
}


HX_DEFINE_DYNAMIC_FUNC7(FlxSprite_obj,loadGraphic,return )

::flixel::FlxSprite FlxSprite_obj::loadRotatedGraphic( Dynamic Graphic,hx::Null< int >  __o_Rotations,hx::Null< int >  __o_Frame,hx::Null< bool >  __o_AntiAliasing,hx::Null< bool >  __o_AutoBuffer,::String Key){
int Rotations = __o_Rotations.Default(16);
int Frame = __o_Frame.Default(-1);
bool AntiAliasing = __o_AntiAliasing.Default(false);
bool AutoBuffer = __o_AutoBuffer.Default(false);
	HX_STACK_FRAME("flixel.FlxSprite","loadRotatedGraphic",0xceb71e2e,"flixel.FlxSprite.loadRotatedGraphic","flixel/FlxSprite.hx",351,0x0384bffa)
	HX_STACK_THIS(this)
	HX_STACK_ARG(Graphic,"Graphic")
	HX_STACK_ARG(Rotations,"Rotations")
	HX_STACK_ARG(Frame,"Frame")
	HX_STACK_ARG(AntiAliasing,"AntiAliasing")
	HX_STACK_ARG(AutoBuffer,"AutoBuffer")
	HX_STACK_ARG(Key,"Key")
{
		HX_STACK_LINE(353)
		int rows = ::Std_obj::_int(::Math_obj::sqrt(Rotations));		HX_STACK_VAR(rows,"rows");
		HX_STACK_LINE(354)
		::flash::display::BitmapData brush = ::flixel::FlxG_obj::bitmap->add(Graphic,false,Key)->bitmap;		HX_STACK_VAR(brush,"brush");
		HX_STACK_LINE(355)
		bool isRegion = ::Std_obj::is(Graphic,hx::ClassOf< ::flixel::util::loaders::TextureRegion >());		HX_STACK_VAR(isRegion,"isRegion");
		HX_STACK_LINE(356)
		::flixel::util::loaders::TextureRegion spriteRegion;		HX_STACK_VAR(spriteRegion,"spriteRegion");
		HX_STACK_LINE(356)
		if (((isRegion == true))){
			HX_STACK_LINE(356)
			spriteRegion = Graphic;
		}
		else{
			HX_STACK_LINE(356)
			spriteRegion = null();
		}
		HX_STACK_LINE(357)
		::flixel::system::layer::Region tempRegion;		HX_STACK_VAR(tempRegion,"tempRegion");
		HX_STACK_LINE(357)
		if (((isRegion == true))){
			HX_STACK_LINE(357)
			tempRegion = spriteRegion->region;
		}
		else{
			HX_STACK_LINE(357)
			tempRegion = null();
		}
		HX_STACK_LINE(359)
		if (((bool((Frame >= (int)0)) || bool(isRegion)))){
			HX_STACK_LINE(362)
			::flash::display::BitmapData full = brush;		HX_STACK_VAR(full,"full");
			HX_STACK_LINE(364)
			if ((isRegion)){
				HX_STACK_LINE(366)
				brush = ::flash::display::BitmapData_obj::__new(tempRegion->width,tempRegion->height,null(),null(),null());
				HX_STACK_LINE(367)
				this->_flashRect->x = tempRegion->startX;
				HX_STACK_LINE(368)
				this->_flashRect->y = tempRegion->startY;
				HX_STACK_LINE(369)
				this->_flashRect->width = tempRegion->width;
				HX_STACK_LINE(370)
				this->_flashRect->height = tempRegion->height;
				HX_STACK_LINE(371)
				brush->copyPixels(full,this->_flashRect,this->_flashPointZero,null(),null(),null());
			}
			else{
				HX_STACK_LINE(375)
				int _g = full->get_height();		HX_STACK_VAR(_g,"_g");
				HX_STACK_LINE(375)
				brush = ::flash::display::BitmapData_obj::__new(_g,full->get_height(),null(),null(),null());
				HX_STACK_LINE(376)
				int rx = (Frame * brush->get_width());		HX_STACK_VAR(rx,"rx");
				HX_STACK_LINE(377)
				int ry = (int)0;		HX_STACK_VAR(ry,"ry");
				HX_STACK_LINE(378)
				int fw = full->get_width();		HX_STACK_VAR(fw,"fw");
				HX_STACK_LINE(379)
				if (((rx >= fw))){
					HX_STACK_LINE(381)
					int _g1 = ::Std_obj::_int((Float(rx) / Float(fw)));		HX_STACK_VAR(_g1,"_g1");
					HX_STACK_LINE(381)
					ry = (_g1 * brush->get_height());
					HX_STACK_LINE(382)
					hx::ModEq(rx,fw);
				}
				HX_STACK_LINE(384)
				this->_flashRect->x = rx;
				HX_STACK_LINE(385)
				this->_flashRect->y = ry;
				HX_STACK_LINE(386)
				this->_flashRect->width = brush->get_width();
				HX_STACK_LINE(387)
				this->_flashRect->height = brush->get_height();
				HX_STACK_LINE(388)
				brush->copyPixels(full,this->_flashRect,this->_flashPointZero,null(),null(),null());
			}
		}
		HX_STACK_LINE(392)
		int max = brush->get_width();		HX_STACK_VAR(max,"max");
		HX_STACK_LINE(393)
		if (((brush->get_height() > max))){
			HX_STACK_LINE(395)
			max = brush->get_height();
		}
		HX_STACK_LINE(398)
		if ((AutoBuffer)){
			HX_STACK_LINE(400)
			max = ::Std_obj::_int((max * 1.5));
		}
		HX_STACK_LINE(403)
		int columns = ::Math_obj::ceil((Float(Rotations) / Float(rows)));		HX_STACK_VAR(columns,"columns");
		HX_STACK_LINE(404)
		this->set_width((max * columns));
		HX_STACK_LINE(405)
		this->set_height((max * rows));
		HX_STACK_LINE(406)
		::String key = HX_CSTRING("");		HX_STACK_VAR(key,"key");
		HX_STACK_LINE(407)
		if ((::Std_obj::is(Graphic,hx::ClassOf< ::String >()))){
			HX_STACK_LINE(409)
			key = Graphic;
		}
		else{
			HX_STACK_LINE(411)
			if ((::Std_obj::is(Graphic,hx::ClassOf< ::Class >()))){
				HX_STACK_LINE(413)
				key = ::Type_obj::getClassName(Graphic);
			}
			else{
				HX_STACK_LINE(415)
				if (((  ((::Std_obj::is(Graphic,hx::ClassOf< ::flash::display::BitmapData >()))) ? bool((Key != null())) : bool(false) ))){
					HX_STACK_LINE(417)
					key = Key;
				}
				else{
					HX_STACK_LINE(419)
					if ((isRegion)){
						HX_STACK_LINE(421)
						key = spriteRegion->data->key;
						HX_STACK_LINE(422)
						hx::AddEq(key,(((((((((HX_CSTRING(":") + tempRegion->startX) + HX_CSTRING(":")) + tempRegion->startY) + HX_CSTRING(":")) + tempRegion->width) + HX_CSTRING(":")) + tempRegion->height) + HX_CSTRING(":")) + Rotations));
					}
					else{
						HX_STACK_LINE(426)
						return null();
					}
				}
			}
		}
		HX_STACK_LINE(429)
		if ((!(isRegion))){
			HX_STACK_LINE(431)
			::String _g2 = ((((HX_CSTRING(":") + Frame) + HX_CSTRING(":")) + this->get_width()) + HX_CSTRING("x"));		HX_STACK_VAR(_g2,"_g2");
			HX_STACK_LINE(431)
			hx::AddEq(key,(((_g2 + this->get_height()) + HX_CSTRING(":")) + Rotations));
		}
		HX_STACK_LINE(434)
		bool skipGen = ::flixel::FlxG_obj::bitmap->checkCache(key);		HX_STACK_VAR(skipGen,"skipGen");
		HX_STACK_LINE(435)
		int _g3 = ((::Std_obj::_int(this->get_width()) + columns) - (int)1);		HX_STACK_VAR(_g3,"_g3");
		HX_STACK_LINE(435)
		this->set_cachedGraphics(::flixel::FlxG_obj::bitmap->create(_g3,((::Std_obj::_int(this->get_height()) + rows) - (int)1),(int)0,true,key));
		HX_STACK_LINE(436)
		this->bakedRotationAngle = (Float((int)360) / Float(Rotations));
		HX_STACK_LINE(439)
		if ((!(skipGen))){
			HX_STACK_LINE(441)
			int row = (int)0;		HX_STACK_VAR(row,"row");
			HX_STACK_LINE(442)
			int column;		HX_STACK_VAR(column,"column");
			HX_STACK_LINE(443)
			Float bakedAngle = (int)0;		HX_STACK_VAR(bakedAngle,"bakedAngle");
			HX_STACK_LINE(444)
			int halfBrushWidth = ::Std_obj::_int((brush->get_width() * 0.5));		HX_STACK_VAR(halfBrushWidth,"halfBrushWidth");
			HX_STACK_LINE(445)
			int halfBrushHeight = ::Std_obj::_int((brush->get_height() * 0.5));		HX_STACK_VAR(halfBrushHeight,"halfBrushHeight");
			HX_STACK_LINE(446)
			int midpointX = ::Std_obj::_int((max * 0.5));		HX_STACK_VAR(midpointX,"midpointX");
			HX_STACK_LINE(447)
			int midpointY = ::Std_obj::_int((max * 0.5));		HX_STACK_VAR(midpointY,"midpointY");
			HX_STACK_LINE(448)
			while(((row < rows))){
				HX_STACK_LINE(450)
				column = (int)0;
				HX_STACK_LINE(451)
				while(((column < columns))){
					HX_STACK_LINE(453)
					this->_matrix->identity();
					HX_STACK_LINE(454)
					this->_matrix->translate(-(halfBrushWidth),-(halfBrushHeight));
					HX_STACK_LINE(455)
					this->_matrix->rotate((bakedAngle * ::flixel::util::FlxAngle_obj::TO_RAD));
					HX_STACK_LINE(456)
					this->_matrix->translate((((max * column) + midpointX) + column),(midpointY + row));
					HX_STACK_LINE(457)
					hx::AddEq(bakedAngle,this->bakedRotationAngle);
					HX_STACK_LINE(458)
					this->cachedGraphics->bitmap->draw(brush,this->_matrix,null(),null(),null(),AntiAliasing);
					HX_STACK_LINE(459)
					(column)++;
				}
				HX_STACK_LINE(461)
				hx::AddEq(midpointY,max);
				HX_STACK_LINE(462)
				(row)++;
			}
		}
		HX_STACK_LINE(465)
		this->frameWidth = this->frameHeight = max;
		HX_STACK_LINE(466)
		this->set_width(this->set_height(max));
		HX_STACK_LINE(468)
		this->region = ::flixel::system::layer::Region_obj::__new((int)0,(int)0,max,max,(int)1,(int)1,null(),null());
		HX_STACK_LINE(469)
		this->region->width = this->cachedGraphics->bitmap->get_width();
		HX_STACK_LINE(470)
		this->region->height = this->cachedGraphics->bitmap->get_height();
		HX_STACK_LINE(473)
		this->antialiasing = AntiAliasing;
		HX_STACK_LINE(476)
		this->updateFrameData();
		HX_STACK_LINE(477)
		this->resetHelpers();
		HX_STACK_LINE(479)
		if ((AutoBuffer)){
			HX_STACK_LINE(481)
			this->set_width(brush->get_width());
			HX_STACK_LINE(482)
			this->set_height(brush->get_height());
			HX_STACK_LINE(483)
			this->centerOffsets(null());
		}
		HX_STACK_LINE(486)
		this->animation->createPrerotated(null());
		HX_STACK_LINE(487)
		return hx::ObjectPtr<OBJ_>(this);
	}
}


HX_DEFINE_DYNAMIC_FUNC6(FlxSprite_obj,loadRotatedGraphic,return )

::flixel::FlxSprite FlxSprite_obj::loadGraphicFromTexture( Dynamic Data,hx::Null< bool >  __o_Reverse,hx::Null< bool >  __o_Unique,::String FrameName){
bool Reverse = __o_Reverse.Default(false);
bool Unique = __o_Unique.Default(false);
	HX_STACK_FRAME("flixel.FlxSprite","loadGraphicFromTexture",0xc5fe4c78,"flixel.FlxSprite.loadGraphicFromTexture","flixel/FlxSprite.hx",500,0x0384bffa)
	HX_STACK_THIS(this)
	HX_STACK_ARG(Data,"Data")
	HX_STACK_ARG(Reverse,"Reverse")
	HX_STACK_ARG(Unique,"Unique")
	HX_STACK_ARG(FrameName,"FrameName")
{
		HX_STACK_LINE(501)
		this->bakedRotationAngle = (int)0;
		HX_STACK_LINE(503)
		if ((::Std_obj::is(Data,hx::ClassOf< ::flixel::util::loaders::CachedGraphics >()))){
			HX_STACK_LINE(505)
			this->set_cachedGraphics(Data);
			HX_STACK_LINE(506)
			if (((this->cachedGraphics->data == null()))){
				HX_STACK_LINE(508)
				return null();
			}
		}
		else{
			HX_STACK_LINE(511)
			if ((::Std_obj::is(Data,hx::ClassOf< ::flixel::util::loaders::TexturePackerData >()))){
				HX_STACK_LINE(513)
				this->set_cachedGraphics(::flixel::FlxG_obj::bitmap->add(Data->__Field(HX_CSTRING("assetName"),true),Unique,null()));
				HX_STACK_LINE(514)
				this->cachedGraphics->data = Data;
			}
			else{
				HX_STACK_LINE(518)
				return null();
			}
		}
		HX_STACK_LINE(521)
		this->region = ::flixel::system::layer::Region_obj::__new(null(),null(),null(),null(),null(),null(),null(),null());
		HX_STACK_LINE(522)
		this->region->width = this->cachedGraphics->bitmap->get_width();
		HX_STACK_LINE(523)
		this->region->height = this->cachedGraphics->bitmap->get_height();
		HX_STACK_LINE(525)
		if (((Reverse == true))){
			HX_STACK_LINE(525)
			this->flipped = this->cachedGraphics->bitmap->get_width();
		}
		else{
			HX_STACK_LINE(525)
			this->flipped = (int)0;
		}
		HX_STACK_LINE(527)
		this->animation->destroyAnimations();
		HX_STACK_LINE(528)
		this->updateFrameData();
		HX_STACK_LINE(529)
		this->resetHelpers();
		HX_STACK_LINE(531)
		if (((FrameName != null()))){
			HX_STACK_LINE(533)
			this->animation->set_frameName(FrameName);
		}
		HX_STACK_LINE(536)
		{
			HX_STACK_LINE(536)
			this->set_width(this->frameWidth);
			HX_STACK_LINE(536)
			this->set_height(this->frameHeight);
		}
		HX_STACK_LINE(537)
		this->origin->set((this->frameWidth * 0.5),(this->frameHeight * 0.5));
		HX_STACK_LINE(538)
		return hx::ObjectPtr<OBJ_>(this);
	}
}


HX_DEFINE_DYNAMIC_FUNC4(FlxSprite_obj,loadGraphicFromTexture,return )

::flixel::FlxSprite FlxSprite_obj::loadRotatedGraphicFromTexture( Dynamic Data,::String Image,hx::Null< int >  __o_Rotations,hx::Null< bool >  __o_AntiAliasing,hx::Null< bool >  __o_AutoBuffer){
int Rotations = __o_Rotations.Default(16);
bool AntiAliasing = __o_AntiAliasing.Default(false);
bool AutoBuffer = __o_AutoBuffer.Default(false);
	HX_STACK_FRAME("flixel.FlxSprite","loadRotatedGraphicFromTexture",0xa93b1903,"flixel.FlxSprite.loadRotatedGraphicFromTexture","flixel/FlxSprite.hx",553,0x0384bffa)
	HX_STACK_THIS(this)
	HX_STACK_ARG(Data,"Data")
	HX_STACK_ARG(Image,"Image")
	HX_STACK_ARG(Rotations,"Rotations")
	HX_STACK_ARG(AntiAliasing,"AntiAliasing")
	HX_STACK_ARG(AutoBuffer,"AutoBuffer")
{
		HX_STACK_LINE(554)
		::flixel::FlxSprite temp = this->loadGraphicFromTexture(Data,null(),null(),null());		HX_STACK_VAR(temp,"temp");
		HX_STACK_LINE(556)
		if (((temp == null()))){
			HX_STACK_LINE(558)
			return null();
		}
		HX_STACK_LINE(561)
		this->animation->set_frameName(Image);
		HX_STACK_LINE(564)
		this->antialiasing = AntiAliasing;
		HX_STACK_LINE(570)
		return hx::ObjectPtr<OBJ_>(this);
	}
}


HX_DEFINE_DYNAMIC_FUNC5(FlxSprite_obj,loadRotatedGraphicFromTexture,return )

::flixel::FlxSprite FlxSprite_obj::makeGraphic( int Width,int Height,hx::Null< int >  __o_Color,hx::Null< bool >  __o_Unique,::String Key){
int Color = __o_Color.Default(-1);
bool Unique = __o_Unique.Default(false);
	HX_STACK_FRAME("flixel.FlxSprite","makeGraphic",0xbaa3e5d1,"flixel.FlxSprite.makeGraphic","flixel/FlxSprite.hx",583,0x0384bffa)
	HX_STACK_THIS(this)
	HX_STACK_ARG(Width,"Width")
	HX_STACK_ARG(Height,"Height")
	HX_STACK_ARG(Color,"Color")
	HX_STACK_ARG(Unique,"Unique")
	HX_STACK_ARG(Key,"Key")
{
		HX_STACK_LINE(584)
		this->bakedRotationAngle = (int)0;
		HX_STACK_LINE(585)
		this->set_cachedGraphics(::flixel::FlxG_obj::bitmap->create(Width,Height,Color,Unique,Key));
		HX_STACK_LINE(586)
		this->region = ::flixel::system::layer::Region_obj::__new(null(),null(),null(),null(),null(),null(),null(),null());
		HX_STACK_LINE(587)
		this->region->width = Width;
		HX_STACK_LINE(588)
		this->region->height = Height;
		HX_STACK_LINE(589)
		this->set_width(this->region->tileWidth = this->frameWidth = this->cachedGraphics->bitmap->get_width());
		HX_STACK_LINE(590)
		this->set_height(this->region->tileHeight = this->frameHeight = this->cachedGraphics->bitmap->get_height());
		HX_STACK_LINE(591)
		this->animation->destroyAnimations();
		HX_STACK_LINE(592)
		this->updateFrameData();
		HX_STACK_LINE(593)
		this->resetHelpers();
		HX_STACK_LINE(594)
		return hx::ObjectPtr<OBJ_>(this);
	}
}


HX_DEFINE_DYNAMIC_FUNC5(FlxSprite_obj,makeGraphic,return )

Void FlxSprite_obj::resetSize( ){
{
		HX_STACK_FRAME("flixel.FlxSprite","resetSize",0x5d8771e7,"flixel.FlxSprite.resetSize","flixel/FlxSprite.hx",601,0x0384bffa)
		HX_STACK_THIS(this)
		HX_STACK_LINE(602)
		this->_flashRect->x = (int)0;
		HX_STACK_LINE(603)
		this->_flashRect->y = (int)0;
		HX_STACK_LINE(604)
		this->_flashRect->width = this->frameWidth;
		HX_STACK_LINE(605)
		this->_flashRect->height = this->frameHeight;
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC0(FlxSprite_obj,resetSize,(void))

Void FlxSprite_obj::resetFrameSize( ){
{
		HX_STACK_FRAME("flixel.FlxSprite","resetFrameSize",0xb7baa4a8,"flixel.FlxSprite.resetFrameSize","flixel/FlxSprite.hx",612,0x0384bffa)
		HX_STACK_THIS(this)
		HX_STACK_LINE(613)
		this->frameWidth = ::Std_obj::_int(this->frame->sourceSize->x);
		HX_STACK_LINE(614)
		this->frameHeight = ::Std_obj::_int(this->frame->sourceSize->y);
		HX_STACK_LINE(615)
		{
			HX_STACK_LINE(615)
			this->_flashRect->x = (int)0;
			HX_STACK_LINE(615)
			this->_flashRect->y = (int)0;
			HX_STACK_LINE(615)
			this->_flashRect->width = this->frameWidth;
			HX_STACK_LINE(615)
			this->_flashRect->height = this->frameHeight;
		}
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC0(FlxSprite_obj,resetFrameSize,(void))

Void FlxSprite_obj::resetSizeFromFrame( ){
{
		HX_STACK_FRAME("flixel.FlxSprite","resetSizeFromFrame",0xf893db7c,"flixel.FlxSprite.resetSizeFromFrame","flixel/FlxSprite.hx",622,0x0384bffa)
		HX_STACK_THIS(this)
		HX_STACK_LINE(623)
		this->set_width(this->frameWidth);
		HX_STACK_LINE(624)
		this->set_height(this->frameHeight);
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC0(FlxSprite_obj,resetSizeFromFrame,(void))

Void FlxSprite_obj::setOriginToCenter( ){
{
		HX_STACK_FRAME("flixel.FlxSprite","setOriginToCenter",0xc64c57af,"flixel.FlxSprite.setOriginToCenter","flixel/FlxSprite.hx",633,0x0384bffa)
		HX_STACK_THIS(this)
		HX_STACK_LINE(633)
		this->origin->set((this->frameWidth * 0.5),(this->frameHeight * 0.5));
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC0(FlxSprite_obj,setOriginToCenter,(void))

Void FlxSprite_obj::setGraphicSize( hx::Null< int >  __o_Width,hx::Null< int >  __o_Height){
int Width = __o_Width.Default(0);
int Height = __o_Height.Default(0);
	HX_STACK_FRAME("flixel.FlxSprite","setGraphicSize",0x516eb7f0,"flixel.FlxSprite.setGraphicSize","flixel/FlxSprite.hx",644,0x0384bffa)
	HX_STACK_THIS(this)
	HX_STACK_ARG(Width,"Width")
	HX_STACK_ARG(Height,"Height")
{
		HX_STACK_LINE(645)
		if (((bool((Width <= (int)0)) && bool((Height <= (int)0))))){
			HX_STACK_LINE(646)
			return null();
		}
		HX_STACK_LINE(649)
		Float newScaleX = (Float(Width) / Float(this->frameWidth));		HX_STACK_VAR(newScaleX,"newScaleX");
		HX_STACK_LINE(650)
		Float newScaleY = (Float(Height) / Float(this->frameHeight));		HX_STACK_VAR(newScaleY,"newScaleY");
		HX_STACK_LINE(651)
		this->scale->set(newScaleX,newScaleY);
		HX_STACK_LINE(653)
		if (((Width <= (int)0))){
			HX_STACK_LINE(654)
			this->scale->set_x(newScaleY);
		}
		else{
			HX_STACK_LINE(656)
			if (((Height <= (int)0))){
				HX_STACK_LINE(657)
				this->scale->set_y(newScaleX);
			}
		}
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC2(FlxSprite_obj,setGraphicSize,(void))

Void FlxSprite_obj::updateHitbox( ){
{
		HX_STACK_FRAME("flixel.FlxSprite","updateHitbox",0x9470392a,"flixel.FlxSprite.updateHitbox","flixel/FlxSprite.hx",666,0x0384bffa)
		HX_STACK_THIS(this)
		HX_STACK_LINE(667)
		Float newWidth = (this->scale->x * this->frameWidth);		HX_STACK_VAR(newWidth,"newWidth");
		HX_STACK_LINE(668)
		Float newHeight = (this->scale->y * this->frameHeight);		HX_STACK_VAR(newHeight,"newHeight");
		HX_STACK_LINE(670)
		this->set_width(newWidth);
		HX_STACK_LINE(671)
		this->set_height(newHeight);
		HX_STACK_LINE(672)
		this->offset->set(-(((((newWidth - this->frameWidth)) * 0.5))),-(((((newHeight - this->frameHeight)) * 0.5))));
		HX_STACK_LINE(673)
		this->origin->set((this->frameWidth * 0.5),(this->frameHeight * 0.5));
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC0(FlxSprite_obj,updateHitbox,(void))

Void FlxSprite_obj::resetHelpers( ){
{
		HX_STACK_FRAME("flixel.FlxSprite","resetHelpers",0x6fc22ddf,"flixel.FlxSprite.resetHelpers","flixel/FlxSprite.hx",680,0x0384bffa)
		HX_STACK_THIS(this)
		HX_STACK_LINE(681)
		{
			HX_STACK_LINE(681)
			this->_flashRect->x = (int)0;
			HX_STACK_LINE(681)
			this->_flashRect->y = (int)0;
			HX_STACK_LINE(681)
			this->_flashRect->width = this->frameWidth;
			HX_STACK_LINE(681)
			this->_flashRect->height = this->frameHeight;
		}
		HX_STACK_LINE(682)
		this->_flashRect2->x = (int)0;
		HX_STACK_LINE(683)
		this->_flashRect2->y = (int)0;
		HX_STACK_LINE(684)
		this->_flashRect2->width = this->cachedGraphics->bitmap->get_width();
		HX_STACK_LINE(685)
		this->_flashRect2->height = this->cachedGraphics->bitmap->get_height();
		HX_STACK_LINE(686)
		this->origin->set((this->frameWidth * 0.5),(this->frameHeight * 0.5));
		HX_STACK_LINE(697)
		this->_halfWidth = (this->frameWidth * 0.5);
		HX_STACK_LINE(698)
		this->_halfHeight = (this->frameHeight * 0.5);
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC0(FlxSprite_obj,resetHelpers,(void))

Void FlxSprite_obj::update( ){
{
		HX_STACK_FRAME("flixel.FlxSprite","update",0xe75bd5f2,"flixel.FlxSprite.update","flixel/FlxSprite.hx",702,0x0384bffa)
		HX_STACK_THIS(this)
		HX_STACK_LINE(703)
		this->super::update();
		HX_STACK_LINE(704)
		this->animation->update();
	}
return null();
}


Void FlxSprite_obj::draw( ){
{
		HX_STACK_FRAME("flixel.FlxSprite","draw",0xe68b7fad,"flixel.FlxSprite.draw","flixel/FlxSprite.hx",711,0x0384bffa)
		HX_STACK_THIS(this)
		HX_STACK_LINE(712)
		if (((this->alpha == (int)0))){
			HX_STACK_LINE(713)
			return null();
		}
		HX_STACK_LINE(715)
		if ((this->dirty)){
			HX_STACK_LINE(717)
			this->calcFrame(null());
		}
		HX_STACK_LINE(720)
		if (((this->cameras == null()))){
			HX_STACK_LINE(722)
			this->cameras = ::flixel::FlxG_obj::cameras->list;
		}
		HX_STACK_LINE(726)
		::flixel::system::layer::DrawStackItem drawItem;		HX_STACK_VAR(drawItem,"drawItem");
		HX_STACK_LINE(727)
		Array< Float > currDrawData;		HX_STACK_VAR(currDrawData,"currDrawData");
		HX_STACK_LINE(728)
		int currIndex;		HX_STACK_VAR(currIndex,"currIndex");
		HX_STACK_LINE(730)
		Float cos;		HX_STACK_VAR(cos,"cos");
		HX_STACK_LINE(731)
		Float sin;		HX_STACK_VAR(sin,"sin");
		HX_STACK_LINE(734)
		bool simpleRender = this->isSimpleRender();		HX_STACK_VAR(simpleRender,"simpleRender");
		HX_STACK_LINE(736)
		{
			HX_STACK_LINE(736)
			int _g = (int)0;		HX_STACK_VAR(_g,"_g");
			HX_STACK_LINE(736)
			Array< ::Dynamic > _g1 = this->cameras;		HX_STACK_VAR(_g1,"_g1");
			HX_STACK_LINE(736)
			while(((_g < _g1->length))){
				HX_STACK_LINE(736)
				::flixel::FlxCamera camera = _g1->__get(_g).StaticCast< ::flixel::FlxCamera >();		HX_STACK_VAR(camera,"camera");
				HX_STACK_LINE(736)
				++(_g);
				HX_STACK_LINE(738)
				if (((  ((!(((bool(!(camera->visible)) || bool(!(camera->exists))))))) ? bool(!(this->isOnScreen(camera))) : bool(true) ))){
					HX_STACK_LINE(740)
					continue;
				}
				HX_STACK_LINE(745)
				drawItem = camera->getDrawStackItem(this->cachedGraphics,this->isColored,this->_blendInt,this->antialiasing);
				HX_STACK_LINE(750)
				currDrawData = drawItem->drawData;
				HX_STACK_LINE(751)
				currIndex = drawItem->position;
				HX_STACK_LINE(753)
				this->_point->set_x(((this->x - (camera->scroll->x * this->scrollFactor->x)) - this->offset->x));
				HX_STACK_LINE(754)
				this->_point->set_y(((this->y - (camera->scroll->y * this->scrollFactor->y)) - this->offset->y));
				HX_STACK_LINE(756)
				this->_point->set_x((this->_point->x + this->origin->x));
				HX_STACK_LINE(757)
				this->_point->set_y((this->_point->y + this->origin->y));
				HX_STACK_LINE(790)
				Float csx = this->_facingMult;		HX_STACK_VAR(csx,"csx");
				HX_STACK_LINE(791)
				Float ssy = (int)0;		HX_STACK_VAR(ssy,"ssy");
				HX_STACK_LINE(792)
				Float ssx = (int)0;		HX_STACK_VAR(ssx,"ssx");
				HX_STACK_LINE(793)
				Float csy = (int)1;		HX_STACK_VAR(csy,"csy");
				HX_STACK_LINE(795)
				Float x1 = (this->origin->x - this->frame->center->x);		HX_STACK_VAR(x1,"x1");
				HX_STACK_LINE(796)
				Float y1 = (this->origin->y - this->frame->center->y);		HX_STACK_VAR(y1,"y1");
				HX_STACK_LINE(798)
				Float x2 = x1;		HX_STACK_VAR(x2,"x2");
				HX_STACK_LINE(799)
				Float y2 = y1;		HX_STACK_VAR(y2,"y2");
				HX_STACK_LINE(802)
				Float a = csx;		HX_STACK_VAR(a,"a");
				HX_STACK_LINE(803)
				Float b = ssx;		HX_STACK_VAR(b,"b");
				HX_STACK_LINE(804)
				Float c = ssy;		HX_STACK_VAR(c,"c");
				HX_STACK_LINE(805)
				Float d = csy;		HX_STACK_VAR(d,"d");
				HX_STACK_LINE(807)
				if ((!(simpleRender))){
					HX_STACK_LINE(809)
					if (((bool(this->_angleChanged) && bool((this->bakedRotationAngle <= (int)0))))){
						HX_STACK_LINE(811)
						Float radians = (-(this->angle) * ::flixel::util::FlxAngle_obj::TO_RAD);		HX_STACK_VAR(radians,"radians");
						HX_STACK_LINE(812)
						this->_sinAngle = ::Math_obj::sin(radians);
						HX_STACK_LINE(813)
						this->_cosAngle = ::Math_obj::cos(radians);
						HX_STACK_LINE(814)
						this->_angleChanged = false;
					}
					HX_STACK_LINE(817)
					Float sx = (this->scale->x * this->_facingMult);		HX_STACK_VAR(sx,"sx");
					HX_STACK_LINE(819)
					if ((this->frame->rotated)){
						HX_STACK_LINE(821)
						cos = -(this->_sinAngle);
						HX_STACK_LINE(822)
						sin = this->_cosAngle;
						HX_STACK_LINE(824)
						csx = (cos * sx);
						HX_STACK_LINE(825)
						ssy = (sin * this->scale->y);
						HX_STACK_LINE(826)
						ssx = (sin * sx);
						HX_STACK_LINE(827)
						csy = (cos * this->scale->y);
						HX_STACK_LINE(829)
						x2 = ((x1 * ssx) - (y1 * csy));
						HX_STACK_LINE(830)
						y2 = ((x1 * csx) + (y1 * ssy));
						HX_STACK_LINE(832)
						a = csy;
						HX_STACK_LINE(833)
						b = ssy;
						HX_STACK_LINE(834)
						c = ssx;
						HX_STACK_LINE(835)
						d = csx;
					}
					else{
						HX_STACK_LINE(839)
						cos = this->_cosAngle;
						HX_STACK_LINE(840)
						sin = this->_sinAngle;
						HX_STACK_LINE(842)
						csx = (cos * sx);
						HX_STACK_LINE(843)
						ssy = (sin * this->scale->y);
						HX_STACK_LINE(844)
						ssx = (sin * sx);
						HX_STACK_LINE(845)
						csy = (cos * this->scale->y);
						HX_STACK_LINE(847)
						x2 = ((x1 * csx) + (y1 * ssy));
						HX_STACK_LINE(848)
						y2 = ((-(x1) * ssx) + (y1 * csy));
						HX_STACK_LINE(850)
						a = csx;
						HX_STACK_LINE(851)
						b = ssx;
						HX_STACK_LINE(852)
						c = ssy;
						HX_STACK_LINE(853)
						d = csy;
					}
				}
				else{
					HX_STACK_LINE(858)
					x2 = (x1 * csx);
				}
				HX_STACK_LINE(861)
				currDrawData[(currIndex)++] = (this->_point->x - x2);
				HX_STACK_LINE(862)
				currDrawData[(currIndex)++] = (this->_point->y - y2);
				HX_STACK_LINE(864)
				currDrawData[(currIndex)++] = this->frame->tileID;
				HX_STACK_LINE(866)
				currDrawData[(currIndex)++] = a;
				HX_STACK_LINE(867)
				currDrawData[(currIndex)++] = -(b);
				HX_STACK_LINE(868)
				currDrawData[(currIndex)++] = c;
				HX_STACK_LINE(869)
				currDrawData[(currIndex)++] = d;
				HX_STACK_LINE(872)
				if ((this->isColored)){
					HX_STACK_LINE(874)
					currDrawData[(currIndex)++] = this->_red;
					HX_STACK_LINE(875)
					currDrawData[(currIndex)++] = this->_green;
					HX_STACK_LINE(876)
					currDrawData[(currIndex)++] = this->_blue;
				}
				HX_STACK_LINE(878)
				currDrawData[(currIndex)++] = (this->alpha * camera->alpha);
				HX_STACK_LINE(885)
				drawItem->position = currIndex;
				HX_STACK_LINE(888)
				(::flixel::FlxBasic_obj::_VISIBLECOUNT)++;
			}
		}
	}
return null();
}


Void FlxSprite_obj::stamp( ::flixel::FlxSprite Brush,hx::Null< int >  __o_X,hx::Null< int >  __o_Y){
int X = __o_X.Default(0);
int Y = __o_Y.Default(0);
	HX_STACK_FRAME("flixel.FlxSprite","stamp",0x77d9503a,"flixel.FlxSprite.stamp","flixel/FlxSprite.hx",901,0x0384bffa)
	HX_STACK_THIS(this)
	HX_STACK_ARG(Brush,"Brush")
	HX_STACK_ARG(X,"X")
	HX_STACK_ARG(Y,"Y")
{
		HX_STACK_LINE(902)
		{
			HX_STACK_LINE(902)
			bool Force = false;		HX_STACK_VAR(Force,"Force");
			HX_STACK_LINE(902)
			Brush->calcFrame(true);
		}
		HX_STACK_LINE(903)
		::flash::display::BitmapData bitmapData = Brush->framePixels;		HX_STACK_VAR(bitmapData,"bitmapData");
		HX_STACK_LINE(906)
		if (((bool((bool((bool(((bool((Brush->angle == (int)0)) || bool((Brush->bakedRotationAngle > (int)0))))) && bool((Brush->scale->x == (int)1)))) && bool((Brush->scale->y == (int)1)))) && bool((Brush->blend == null()))))){
			HX_STACK_LINE(908)
			this->_flashPoint->x = (X + this->region->startX);
			HX_STACK_LINE(909)
			this->_flashPoint->y = (Y + this->region->startY);
			HX_STACK_LINE(910)
			this->_flashRect2->width = bitmapData->get_width();
			HX_STACK_LINE(911)
			this->_flashRect2->height = bitmapData->get_height();
			HX_STACK_LINE(912)
			this->cachedGraphics->bitmap->copyPixels(bitmapData,this->_flashRect2,this->_flashPoint,null(),null(),true);
			HX_STACK_LINE(913)
			this->_flashRect2->width = this->cachedGraphics->bitmap->get_width();
			HX_STACK_LINE(914)
			this->_flashRect2->height = this->cachedGraphics->bitmap->get_height();
			HX_STACK_LINE(916)
			this->cachedGraphics->get_tilesheet()->destroyFrameBitmapDatas();
			HX_STACK_LINE(921)
			return null();
		}
		HX_STACK_LINE(925)
		this->_matrix->identity();
		HX_STACK_LINE(926)
		this->_matrix->translate(-(Brush->origin->x),-(Brush->origin->y));
		HX_STACK_LINE(927)
		this->_matrix->scale(Brush->scale->x,Brush->scale->y);
		HX_STACK_LINE(928)
		if (((Brush->angle != (int)0))){
			HX_STACK_LINE(930)
			this->_matrix->rotate((Brush->angle * ::flixel::util::FlxAngle_obj::TO_RAD));
		}
		HX_STACK_LINE(932)
		this->_matrix->translate(((X + this->region->startX) + Brush->origin->x),((Y + this->region->startY) + Brush->origin->y));
		HX_STACK_LINE(933)
		::flash::display::BlendMode brushBlend = Brush->blend;		HX_STACK_VAR(brushBlend,"brushBlend");
		HX_STACK_LINE(934)
		this->cachedGraphics->bitmap->draw(bitmapData,this->_matrix,null(),brushBlend,null(),Brush->antialiasing);
		HX_STACK_LINE(935)
		this->cachedGraphics->get_tilesheet()->destroyFrameBitmapDatas();
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC3(FlxSprite_obj,stamp,(void))

Void FlxSprite_obj::drawFrame( hx::Null< bool >  __o_Force){
bool Force = __o_Force.Default(false);
	HX_STACK_FRAME("flixel.FlxSprite","drawFrame",0x99d67540,"flixel.FlxSprite.drawFrame","flixel/FlxSprite.hx",954,0x0384bffa)
	HX_STACK_THIS(this)
	HX_STACK_ARG(Force,"Force")
{
		HX_STACK_LINE(954)
		this->calcFrame(true);
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC1(FlxSprite_obj,drawFrame,(void))

Void FlxSprite_obj::centerOffsets( hx::Null< bool >  __o_AdjustPosition){
bool AdjustPosition = __o_AdjustPosition.Default(false);
	HX_STACK_FRAME("flixel.FlxSprite","centerOffsets",0x583e0f62,"flixel.FlxSprite.centerOffsets","flixel/FlxSprite.hx",963,0x0384bffa)
	HX_STACK_THIS(this)
	HX_STACK_ARG(AdjustPosition,"AdjustPosition")
{
		HX_STACK_LINE(964)
		this->offset->set_x((((this->frameWidth - this->get_width())) * 0.5));
		HX_STACK_LINE(965)
		this->offset->set_y((((this->frameHeight - this->get_height())) * 0.5));
		HX_STACK_LINE(966)
		if ((AdjustPosition)){
			HX_STACK_LINE(968)
			{
				HX_STACK_LINE(968)
				::flixel::FlxSprite _g = hx::ObjectPtr<OBJ_>(this);		HX_STACK_VAR(_g,"_g");
				HX_STACK_LINE(968)
				_g->set_x((_g->x + this->offset->x));
			}
			HX_STACK_LINE(969)
			{
				HX_STACK_LINE(969)
				::flixel::FlxSprite _g = hx::ObjectPtr<OBJ_>(this);		HX_STACK_VAR(_g,"_g");
				HX_STACK_LINE(969)
				_g->set_y((_g->y + this->offset->y));
			}
		}
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC1(FlxSprite_obj,centerOffsets,(void))

Array< ::Dynamic > FlxSprite_obj::replaceColor( int Color,int NewColor,hx::Null< bool >  __o_FetchPositions){
bool FetchPositions = __o_FetchPositions.Default(false);
	HX_STACK_FRAME("flixel.FlxSprite","replaceColor",0x7b700138,"flixel.FlxSprite.replaceColor","flixel/FlxSprite.hx",981,0x0384bffa)
	HX_STACK_THIS(this)
	HX_STACK_ARG(Color,"Color")
	HX_STACK_ARG(NewColor,"NewColor")
	HX_STACK_ARG(FetchPositions,"FetchPositions")
{
		HX_STACK_LINE(982)
		Array< ::Dynamic > positions = null();		HX_STACK_VAR(positions,"positions");
		HX_STACK_LINE(983)
		if ((FetchPositions)){
			HX_STACK_LINE(985)
			positions = Array_obj< ::Dynamic >::__new();
		}
		HX_STACK_LINE(988)
		int row = this->region->startY;		HX_STACK_VAR(row,"row");
		HX_STACK_LINE(989)
		int column;		HX_STACK_VAR(column,"column");
		HX_STACK_LINE(990)
		int rows = this->region->height;		HX_STACK_VAR(rows,"rows");
		HX_STACK_LINE(991)
		int columns = this->region->width;		HX_STACK_VAR(columns,"columns");
		HX_STACK_LINE(992)
		this->cachedGraphics->bitmap->lock();
		HX_STACK_LINE(993)
		while(((row < rows))){
			HX_STACK_LINE(995)
			column = this->region->startX;
			HX_STACK_LINE(996)
			while(((column < columns))){
				HX_STACK_LINE(998)
				if (((this->cachedGraphics->bitmap->getPixel32(column,row) == Color))){
					HX_STACK_LINE(1000)
					this->cachedGraphics->bitmap->setPixel32(column,row,NewColor);
					HX_STACK_LINE(1001)
					if ((FetchPositions)){
						HX_STACK_LINE(1003)
						positions->push(::flixel::util::FlxPoint_obj::__new(column,row));
					}
					HX_STACK_LINE(1005)
					this->dirty = true;
				}
				HX_STACK_LINE(1007)
				(column)++;
			}
			HX_STACK_LINE(1009)
			(row)++;
		}
		HX_STACK_LINE(1011)
		this->cachedGraphics->bitmap->unlock(null());
		HX_STACK_LINE(1012)
		this->cachedGraphics->get_tilesheet()->destroyFrameBitmapDatas();
		HX_STACK_LINE(1013)
		return positions;
	}
}


HX_DEFINE_DYNAMIC_FUNC3(FlxSprite_obj,replaceColor,return )

Void FlxSprite_obj::setColorTransform( hx::Null< Float >  __o_redMultiplier,hx::Null< Float >  __o_greenMultiplier,hx::Null< Float >  __o_blueMultiplier,hx::Null< Float >  __o_alphaMultiplier,hx::Null< Float >  __o_redOffset,hx::Null< Float >  __o_greenOffset,hx::Null< Float >  __o_blueOffset,hx::Null< Float >  __o_alphaOffset){
Float redMultiplier = __o_redMultiplier.Default(1.0);
Float greenMultiplier = __o_greenMultiplier.Default(1.0);
Float blueMultiplier = __o_blueMultiplier.Default(1.0);
Float alphaMultiplier = __o_alphaMultiplier.Default(1.0);
Float redOffset = __o_redOffset.Default(0);
Float greenOffset = __o_greenOffset.Default(0);
Float blueOffset = __o_blueOffset.Default(0);
Float alphaOffset = __o_alphaOffset.Default(0);
	HX_STACK_FRAME("flixel.FlxSprite","setColorTransform",0xa09a3582,"flixel.FlxSprite.setColorTransform","flixel/FlxSprite.hx",1028,0x0384bffa)
	HX_STACK_THIS(this)
	HX_STACK_ARG(redMultiplier,"redMultiplier")
	HX_STACK_ARG(greenMultiplier,"greenMultiplier")
	HX_STACK_ARG(blueMultiplier,"blueMultiplier")
	HX_STACK_ARG(alphaMultiplier,"alphaMultiplier")
	HX_STACK_ARG(redOffset,"redOffset")
	HX_STACK_ARG(greenOffset,"greenOffset")
	HX_STACK_ARG(blueOffset,"blueOffset")
	HX_STACK_ARG(alphaOffset,"alphaOffset")
{
		struct _Function_1_1{
			inline static int Block( Float &redMultiplier,Float &blueMultiplier,Float &greenMultiplier){
				HX_STACK_FRAME("*","closure",0x5bdab937,"*.closure","flixel/FlxSprite.hx",1029,0x0384bffa)
				{
					HX_STACK_LINE(1029)
					int Red = ::Std_obj::_int((redMultiplier * (int)255));		HX_STACK_VAR(Red,"Red");
					HX_STACK_LINE(1029)
					int Green = ::Std_obj::_int((greenMultiplier * (int)255));		HX_STACK_VAR(Green,"Green");
					HX_STACK_LINE(1029)
					int Blue = ::Std_obj::_int((blueMultiplier * (int)255));		HX_STACK_VAR(Blue,"Blue");
					HX_STACK_LINE(1029)
					return (int((int((int(Red) << int((int)16))) | int((int(Green) << int((int)8))))) | int(Blue));
				}
				return null();
			}
		};
		HX_STACK_LINE(1029)
		this->set_color(_Function_1_1::Block(redMultiplier,blueMultiplier,greenMultiplier));
		HX_STACK_LINE(1030)
		this->set_alpha(alphaMultiplier);
		HX_STACK_LINE(1032)
		if (((this->_colorTransform == null()))){
			HX_STACK_LINE(1034)
			this->_colorTransform = ::flash::geom::ColorTransform_obj::__new(null(),null(),null(),null(),null(),null(),null(),null());
		}
		else{
			HX_STACK_LINE(1038)
			this->_colorTransform->redMultiplier = redMultiplier;
			HX_STACK_LINE(1039)
			this->_colorTransform->greenMultiplier = greenMultiplier;
			HX_STACK_LINE(1040)
			this->_colorTransform->blueMultiplier = blueMultiplier;
			HX_STACK_LINE(1041)
			this->_colorTransform->alphaMultiplier = alphaMultiplier;
			HX_STACK_LINE(1042)
			this->_colorTransform->redOffset = redOffset;
			HX_STACK_LINE(1043)
			this->_colorTransform->greenOffset = greenOffset;
			HX_STACK_LINE(1044)
			this->_colorTransform->blueOffset = blueOffset;
			HX_STACK_LINE(1045)
			this->_colorTransform->alphaOffset = alphaOffset;
		}
		HX_STACK_LINE(1048)
		this->useColorTransform = (bool((bool((bool((bool((bool((this->alpha != (int)1)) || bool((this->color != (int)16777215)))) || bool((redOffset != (int)0)))) || bool((greenOffset != (int)0)))) || bool((blueOffset != (int)0)))) || bool((alphaOffset != (int)0)));
		HX_STACK_LINE(1049)
		this->dirty = true;
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC8(FlxSprite_obj,setColorTransform,(void))

Void FlxSprite_obj::updateColorTransform( ){
{
		HX_STACK_FRAME("flixel.FlxSprite","updateColorTransform",0x79f9051b,"flixel.FlxSprite.updateColorTransform","flixel/FlxSprite.hx",1053,0x0384bffa)
		HX_STACK_THIS(this)
		HX_STACK_LINE(1054)
		if (((bool((this->alpha != (int)1)) || bool((this->color != (int)16777215))))){
			HX_STACK_LINE(1056)
			if (((this->_colorTransform == null()))){
				HX_STACK_LINE(1058)
				this->_colorTransform = ::flash::geom::ColorTransform_obj::__new((Float(((int(this->color) >> int((int)16)))) / Float((int)255)),(Float(((int((int(this->color) >> int((int)8))) & int((int)255)))) / Float((int)255)),(Float(((int(this->color) & int((int)255)))) / Float((int)255)),this->alpha,null(),null(),null(),null());
			}
			else{
				HX_STACK_LINE(1062)
				this->_colorTransform->redMultiplier = (Float(((int(this->color) >> int((int)16)))) / Float((int)255));
				HX_STACK_LINE(1063)
				this->_colorTransform->greenMultiplier = (Float(((int((int(this->color) >> int((int)8))) & int((int)255)))) / Float((int)255));
				HX_STACK_LINE(1064)
				this->_colorTransform->blueMultiplier = (Float(((int(this->color) & int((int)255)))) / Float((int)255));
				HX_STACK_LINE(1065)
				this->_colorTransform->alphaMultiplier = this->alpha;
			}
			HX_STACK_LINE(1067)
			this->useColorTransform = true;
		}
		else{
			HX_STACK_LINE(1071)
			if (((this->_colorTransform != null()))){
				HX_STACK_LINE(1073)
				this->_colorTransform->redMultiplier = (int)1;
				HX_STACK_LINE(1074)
				this->_colorTransform->greenMultiplier = (int)1;
				HX_STACK_LINE(1075)
				this->_colorTransform->blueMultiplier = (int)1;
				HX_STACK_LINE(1076)
				this->_colorTransform->alphaMultiplier = (int)1;
			}
			HX_STACK_LINE(1079)
			this->useColorTransform = false;
		}
		HX_STACK_LINE(1081)
		this->dirty = true;
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC0(FlxSprite_obj,updateColorTransform,(void))

bool FlxSprite_obj::pixelsOverlapPoint( ::flixel::util::FlxPoint point,hx::Null< int >  __o_Mask,::flixel::FlxCamera Camera){
int Mask = __o_Mask.Default(255);
	HX_STACK_FRAME("flixel.FlxSprite","pixelsOverlapPoint",0x4c878b7f,"flixel.FlxSprite.pixelsOverlapPoint","flixel/FlxSprite.hx",1093,0x0384bffa)
	HX_STACK_THIS(this)
	HX_STACK_ARG(point,"point")
	HX_STACK_ARG(Mask,"Mask")
	HX_STACK_ARG(Camera,"Camera")
{
		HX_STACK_LINE(1094)
		if (((Camera == null()))){
			HX_STACK_LINE(1096)
			Camera = ::flixel::FlxG_obj::camera;
		}
		HX_STACK_LINE(1098)
		this->getScreenXY(this->_point,Camera);
		HX_STACK_LINE(1099)
		this->_point->set_x((this->_point->x - this->offset->x));
		HX_STACK_LINE(1100)
		this->_point->set_y((this->_point->y - this->offset->y));
		HX_STACK_LINE(1101)
		this->_flashPoint->x = ((point->x - Camera->scroll->x) - this->_point->x);
		HX_STACK_LINE(1102)
		this->_flashPoint->y = ((point->y - Camera->scroll->y) - this->_point->y);
		HX_STACK_LINE(1105)
		if (((bool((bool((bool((this->_flashPoint->x < (int)0)) || bool((this->_flashPoint->x > this->frameWidth)))) || bool((this->_flashPoint->y < (int)0)))) || bool((this->_flashPoint->y > this->frameHeight))))){
			HX_STACK_LINE(1107)
			return false;
		}
		else{
			HX_STACK_LINE(1111)
			::flash::display::BitmapData frameData;		HX_STACK_VAR(frameData,"frameData");
			HX_STACK_LINE(1111)
			{
				HX_STACK_LINE(1111)
				::flash::display::BitmapData frameBmd = null();		HX_STACK_VAR(frameBmd,"frameBmd");
				HX_STACK_LINE(1111)
				if (((this->frame != null()))){
					HX_STACK_LINE(1111)
					if (((bool((this->facing == (int)1)) && bool((this->flipped > (int)0))))){
						HX_STACK_LINE(1111)
						frameBmd = this->frame->getHReversedBitmap();
					}
					else{
						HX_STACK_LINE(1111)
						frameBmd = this->frame->getBitmap();
					}
				}
				HX_STACK_LINE(1111)
				frameData = frameBmd;
			}
			HX_STACK_LINE(1112)
			int _g = ::Std_obj::_int(this->_flashPoint->x);		HX_STACK_VAR(_g,"_g");
			HX_STACK_LINE(1112)
			int pixelColor = frameData->getPixel32(_g,::Std_obj::_int(this->_flashPoint->y));		HX_STACK_VAR(pixelColor,"pixelColor");
			HX_STACK_LINE(1113)
			int pixelAlpha = (int((int(pixelColor) >> int((int)24))) & int((int)255));		HX_STACK_VAR(pixelAlpha,"pixelAlpha");
			HX_STACK_LINE(1114)
			return ((pixelAlpha * this->alpha) >= Mask);
		}
		HX_STACK_LINE(1105)
		return false;
	}
}


HX_DEFINE_DYNAMIC_FUNC3(FlxSprite_obj,pixelsOverlapPoint,return )

Void FlxSprite_obj::calcFrame( hx::Null< bool >  __o_RunOnCpp){
bool RunOnCpp = __o_RunOnCpp.Default(false);
	HX_STACK_FRAME("flixel.FlxSprite","calcFrame",0xc4d45b0f,"flixel.FlxSprite.calcFrame","flixel/FlxSprite.hx",1124,0x0384bffa)
	HX_STACK_THIS(this)
	HX_STACK_ARG(RunOnCpp,"RunOnCpp")
{
		HX_STACK_LINE(1125)
		if (((this->cachedGraphics == null()))){
			HX_STACK_LINE(1127)
			this->loadGraphic(hx::ClassOf< ::flixel::_FlxSprite::GraphicDefault >(),null(),null(),null(),null(),null(),null());
		}
		HX_STACK_LINE(1131)
		if ((!(RunOnCpp))){
			HX_STACK_LINE(1133)
			return null();
		}
		HX_STACK_LINE(1137)
		if (((this->frame != null()))){
			HX_STACK_LINE(1139)
			if (((  ((!(((  ((!(((this->framePixels == null()))))) ? bool((this->framePixels->get_width() != this->frameWidth)) : bool(true) ))))) ? bool((this->framePixels->get_height() != this->frameHeight)) : bool(true) ))){
				HX_STACK_LINE(1141)
				if (((this->framePixels != null()))){
					HX_STACK_LINE(1142)
					this->framePixels->dispose();
				}
				HX_STACK_LINE(1144)
				int _g = ::Std_obj::_int(this->frame->sourceSize->x);		HX_STACK_VAR(_g,"_g");
				HX_STACK_LINE(1144)
				this->framePixels = ::flash::display::BitmapData_obj::__new(_g,::Std_obj::_int(this->frame->sourceSize->y),null(),null(),null());
			}
			struct _Function_2_1{
				inline static ::flash::display::BitmapData Block( ::flixel::FlxSprite_obj *__this){
					HX_STACK_FRAME("*","closure",0x5bdab937,"*.closure","flixel/FlxSprite.hx",1147,0x0384bffa)
					{
						HX_STACK_LINE(1147)
						::flash::display::BitmapData frameBmd = null();		HX_STACK_VAR(frameBmd,"frameBmd");
						HX_STACK_LINE(1147)
						if (((__this->frame != null()))){
							HX_STACK_LINE(1147)
							if (((bool((__this->facing == (int)1)) && bool((__this->flipped > (int)0))))){
								HX_STACK_LINE(1147)
								frameBmd = __this->frame->getHReversedBitmap();
							}
							else{
								HX_STACK_LINE(1147)
								frameBmd = __this->frame->getBitmap();
							}
						}
						HX_STACK_LINE(1147)
						return frameBmd;
					}
					return null();
				}
			};
			HX_STACK_LINE(1147)
			this->framePixels->copyPixels(_Function_2_1::Block(this),this->_flashRect,this->_flashPointZero,null(),null(),null());
		}
		HX_STACK_LINE(1150)
		if ((this->useColorTransform)){
			HX_STACK_LINE(1152)
			this->framePixels->colorTransform(this->_flashRect,this->_colorTransform);
		}
		HX_STACK_LINE(1155)
		this->dirty = false;
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC1(FlxSprite_obj,calcFrame,(void))

Void FlxSprite_obj::updateFrameData( ){
{
		HX_STACK_FRAME("flixel.FlxSprite","updateFrameData",0x631dd0a5,"flixel.FlxSprite.updateFrameData","flixel/FlxSprite.hx",1163,0x0384bffa)
		HX_STACK_THIS(this)
		HX_STACK_LINE(1164)
		if (((this->cachedGraphics == null()))){
			HX_STACK_LINE(1166)
			return null();
		}
		HX_STACK_LINE(1169)
		if (((bool((this->cachedGraphics->data != null())) && bool(((bool((this->region->tileWidth == (int)0)) && bool((this->region->tileHeight == (int)0)))))))){
			HX_STACK_LINE(1171)
			this->framesData = this->cachedGraphics->get_tilesheet()->getTexturePackerFrames(this->cachedGraphics->data,null(),null());
		}
		else{
			HX_STACK_LINE(1175)
			this->framesData = this->cachedGraphics->get_tilesheet()->getSpriteSheetFrames(this->region,null());
		}
		HX_STACK_LINE(1178)
		this->set_frame(this->framesData->frames->__get((int)0).StaticCast< ::flixel::system::layer::frames::FlxFrame >());
		HX_STACK_LINE(1179)
		this->frames = this->framesData->frames->length;
		HX_STACK_LINE(1180)
		{
			HX_STACK_LINE(1180)
			this->set_width(this->frameWidth);
			HX_STACK_LINE(1180)
			this->set_height(this->frameHeight);
		}
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC0(FlxSprite_obj,updateFrameData,(void))

::flash::display::BitmapData FlxSprite_obj::getFlxFrameBitmapData( ){
	HX_STACK_FRAME("flixel.FlxSprite","getFlxFrameBitmapData",0xc4eba061,"flixel.FlxSprite.getFlxFrameBitmapData","flixel/FlxSprite.hx",1187,0x0384bffa)
	HX_STACK_THIS(this)
	HX_STACK_LINE(1188)
	::flash::display::BitmapData frameBmd = null();		HX_STACK_VAR(frameBmd,"frameBmd");
	HX_STACK_LINE(1189)
	if (((this->frame != null()))){
		HX_STACK_LINE(1191)
		if (((bool((this->facing == (int)1)) && bool((this->flipped > (int)0))))){
			HX_STACK_LINE(1193)
			frameBmd = this->frame->getHReversedBitmap();
		}
		else{
			HX_STACK_LINE(1197)
			frameBmd = this->frame->getBitmap();
		}
	}
	HX_STACK_LINE(1201)
	return frameBmd;
}


HX_DEFINE_DYNAMIC_FUNC0(FlxSprite_obj,getFlxFrameBitmapData,return )

::flixel::util::FlxPoint FlxSprite_obj::getGraphicMidpoint( ::flixel::util::FlxPoint point){
	HX_STACK_FRAME("flixel.FlxSprite","getGraphicMidpoint",0xc420be03,"flixel.FlxSprite.getGraphicMidpoint","flixel/FlxSprite.hx",1211,0x0384bffa)
	HX_STACK_THIS(this)
	HX_STACK_ARG(point,"point")
	HX_STACK_LINE(1212)
	if (((point == null()))){
		HX_STACK_LINE(1214)
		point = ::flixel::util::FlxPoint_obj::__new(null(),null());
	}
	HX_STACK_LINE(1216)
	return point->set((this->x + (this->frameWidth * 0.5)),(this->y + (this->frameHeight * 0.5)));
}


HX_DEFINE_DYNAMIC_FUNC1(FlxSprite_obj,getGraphicMidpoint,return )

Void FlxSprite_obj::resetFrameBitmapDatas( ){
{
		HX_STACK_FRAME("flixel.FlxSprite","resetFrameBitmapDatas",0x2832a393,"flixel.FlxSprite.resetFrameBitmapDatas","flixel/FlxSprite.hx",1225,0x0384bffa)
		HX_STACK_THIS(this)
		HX_STACK_LINE(1225)
		this->cachedGraphics->get_tilesheet()->destroyFrameBitmapDatas();
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC0(FlxSprite_obj,resetFrameBitmapDatas,(void))

bool FlxSprite_obj::isOnScreen( ::flixel::FlxCamera Camera){
	HX_STACK_FRAME("flixel.FlxSprite","isOnScreen",0xb5403c5e,"flixel.FlxSprite.isOnScreen","flixel/FlxSprite.hx",1236,0x0384bffa)
	HX_STACK_THIS(this)
	HX_STACK_ARG(Camera,"Camera")
	HX_STACK_LINE(1237)
	if (((Camera == null()))){
		HX_STACK_LINE(1239)
		Camera = ::flixel::FlxG_obj::camera;
	}
	HX_STACK_LINE(1242)
	Float minX = ((this->x - this->offset->x) - (Camera->scroll->x * this->scrollFactor->x));		HX_STACK_VAR(minX,"minX");
	HX_STACK_LINE(1243)
	Float minY = ((this->y - this->offset->y) - (Camera->scroll->y * this->scrollFactor->y));		HX_STACK_VAR(minY,"minY");
	HX_STACK_LINE(1244)
	Float maxX = (int)0;		HX_STACK_VAR(maxX,"maxX");
	HX_STACK_LINE(1245)
	Float maxY = (int)0;		HX_STACK_VAR(maxY,"maxY");
	HX_STACK_LINE(1247)
	if (((bool((bool(((bool((this->angle == (int)0)) || bool((this->bakedRotationAngle > (int)0))))) && bool((this->scale->x == (int)1)))) && bool((this->scale->y == (int)1))))){
		HX_STACK_LINE(1249)
		maxX = (minX + this->frameWidth);
		HX_STACK_LINE(1250)
		maxY = (minY + this->frameHeight);
	}
	else{
		HX_STACK_LINE(1254)
		Float radiusX = this->_halfWidth;		HX_STACK_VAR(radiusX,"radiusX");
		HX_STACK_LINE(1255)
		Float radiusY = this->_halfHeight;		HX_STACK_VAR(radiusY,"radiusY");
		HX_STACK_LINE(1257)
		if (((this->origin->x == this->_halfWidth))){
			HX_STACK_LINE(1259)
			radiusX = ::Math_obj::abs((this->_halfWidth * this->scale->x));
		}
		else{
			HX_STACK_LINE(1263)
			Float sox = (this->scale->x * this->origin->x);		HX_STACK_VAR(sox,"sox");
			HX_STACK_LINE(1264)
			Float sfw = (this->scale->x * this->frameWidth);		HX_STACK_VAR(sfw,"sfw");
			HX_STACK_LINE(1265)
			Float x1 = ::Math_obj::abs(sox);		HX_STACK_VAR(x1,"x1");
			HX_STACK_LINE(1266)
			Float x2 = ::Math_obj::abs((sfw - sox));		HX_STACK_VAR(x2,"x2");
			HX_STACK_LINE(1267)
			radiusX = ::Math_obj::max(x2,x1);
		}
		HX_STACK_LINE(1270)
		if (((this->origin->y == this->_halfHeight))){
			HX_STACK_LINE(1272)
			radiusY = ::Math_obj::abs((this->_halfHeight * this->scale->y));
		}
		else{
			HX_STACK_LINE(1276)
			Float soy = (this->scale->y * this->origin->y);		HX_STACK_VAR(soy,"soy");
			HX_STACK_LINE(1277)
			Float sfh = (this->scale->y * this->frameHeight);		HX_STACK_VAR(sfh,"sfh");
			HX_STACK_LINE(1278)
			Float y1 = ::Math_obj::abs(soy);		HX_STACK_VAR(y1,"y1");
			HX_STACK_LINE(1279)
			Float y2 = ::Math_obj::abs((sfh - soy));		HX_STACK_VAR(y2,"y2");
			HX_STACK_LINE(1280)
			radiusY = ::Math_obj::max(y2,y1);
		}
		HX_STACK_LINE(1283)
		Float radius = ::Math_obj::max(radiusX,radiusY);		HX_STACK_VAR(radius,"radius");
		HX_STACK_LINE(1284)
		hx::MultEq(radius,1.415);
		HX_STACK_LINE(1286)
		hx::AddEq(minX,this->origin->x);
		HX_STACK_LINE(1287)
		maxX = (minX + radius);
		HX_STACK_LINE(1288)
		hx::SubEq(minX,radius);
		HX_STACK_LINE(1290)
		hx::AddEq(minY,this->origin->y);
		HX_STACK_LINE(1291)
		maxY = (minY + radius);
		HX_STACK_LINE(1292)
		hx::SubEq(minY,radius);
	}
	HX_STACK_LINE(1295)
	if (((bool((maxX < (int)0)) || bool((minX > Camera->width))))){
		HX_STACK_LINE(1296)
		return false;
	}
	HX_STACK_LINE(1298)
	if (((bool((maxY < (int)0)) || bool((minY > Camera->height))))){
		HX_STACK_LINE(1299)
		return false;
	}
	HX_STACK_LINE(1301)
	return true;
}


bool FlxSprite_obj::isSimpleRender( ){
	HX_STACK_FRAME("flixel.FlxSprite","isSimpleRender",0x6aa0d51b,"flixel.FlxSprite.isSimpleRender","flixel/FlxSprite.hx",1313,0x0384bffa)
	HX_STACK_THIS(this)
	HX_STACK_LINE(1313)
	return (bool((bool(((bool((bool((this->angle == (int)0)) && bool((this->frame->additionalAngle == (int)0)))) || bool((this->bakedRotationAngle > (int)0))))) && bool((this->scale->x == (int)1)))) && bool((this->scale->y == (int)1)));
}


HX_DEFINE_DYNAMIC_FUNC0(FlxSprite_obj,isSimpleRender,return )

::flash::display::BitmapData FlxSprite_obj::get_pixels( ){
	HX_STACK_FRAME("flixel.FlxSprite","get_pixels",0x90b8575f,"flixel.FlxSprite.get_pixels","flixel/FlxSprite.hx",1322,0x0384bffa)
	HX_STACK_THIS(this)
	HX_STACK_LINE(1322)
	return this->cachedGraphics->bitmap;
}


HX_DEFINE_DYNAMIC_FUNC0(FlxSprite_obj,get_pixels,return )

::flash::display::BitmapData FlxSprite_obj::set_pixels( ::flash::display::BitmapData Pixels){
	HX_STACK_FRAME("flixel.FlxSprite","set_pixels",0x9435f5d3,"flixel.FlxSprite.set_pixels","flixel/FlxSprite.hx",1326,0x0384bffa)
	HX_STACK_THIS(this)
	HX_STACK_ARG(Pixels,"Pixels")
	HX_STACK_LINE(1327)
	::String key = ::flixel::FlxG_obj::bitmap->getCacheKeyFor(Pixels);		HX_STACK_VAR(key,"key");
	HX_STACK_LINE(1329)
	if (((key == null()))){
		HX_STACK_LINE(1331)
		key = ::flixel::FlxG_obj::bitmap->getUniqueKey(null());
		HX_STACK_LINE(1332)
		this->set_cachedGraphics(::flixel::FlxG_obj::bitmap->add(Pixels,false,key));
		HX_STACK_LINE(1333)
		this->cachedGraphics->set_destroyOnNoUse(true);
	}
	else{
		HX_STACK_LINE(1337)
		this->set_cachedGraphics(::flixel::FlxG_obj::bitmap->get(key));
	}
	HX_STACK_LINE(1340)
	if (((this->region == null()))){
		HX_STACK_LINE(1342)
		this->region = ::flixel::system::layer::Region_obj::__new(null(),null(),null(),null(),null(),null(),null(),null());
	}
	HX_STACK_LINE(1345)
	this->region->startX = (int)0;
	HX_STACK_LINE(1346)
	this->region->startY = (int)0;
	HX_STACK_LINE(1347)
	this->region->tileWidth = this->region->width = this->cachedGraphics->bitmap->get_width();
	HX_STACK_LINE(1348)
	this->region->tileHeight = this->region->height = this->cachedGraphics->bitmap->get_height();
	HX_STACK_LINE(1349)
	this->region->spacingX = (int)0;
	HX_STACK_LINE(1350)
	this->region->spacingY = (int)0;
	HX_STACK_LINE(1352)
	this->set_width(this->frameWidth = this->cachedGraphics->bitmap->get_width());
	HX_STACK_LINE(1353)
	this->set_height(this->frameHeight = this->cachedGraphics->bitmap->get_height());
	HX_STACK_LINE(1354)
	this->animation->destroyAnimations();
	HX_STACK_LINE(1356)
	this->updateFrameData();
	HX_STACK_LINE(1357)
	this->resetHelpers();
	HX_STACK_LINE(1359)
	this->cachedGraphics->get_tilesheet()->destroyFrameBitmapDatas();
	HX_STACK_LINE(1361)
	return Pixels;
}


HX_DEFINE_DYNAMIC_FUNC1(FlxSprite_obj,set_pixels,return )

::flixel::system::layer::frames::FlxFrame FlxSprite_obj::set_frame( ::flixel::system::layer::frames::FlxFrame Value){
	HX_STACK_FRAME("flixel.FlxSprite","set_frame",0xf8c58847,"flixel.FlxSprite.set_frame","flixel/FlxSprite.hx",1365,0x0384bffa)
	HX_STACK_THIS(this)
	HX_STACK_ARG(Value,"Value")
	HX_STACK_LINE(1366)
	this->frame = Value;
	HX_STACK_LINE(1367)
	if (((this->frame != null()))){
		HX_STACK_LINE(1369)
		{
			HX_STACK_LINE(1369)
			this->frameWidth = ::Std_obj::_int(this->frame->sourceSize->x);
			HX_STACK_LINE(1369)
			this->frameHeight = ::Std_obj::_int(this->frame->sourceSize->y);
			HX_STACK_LINE(1369)
			{
				HX_STACK_LINE(1369)
				this->_flashRect->x = (int)0;
				HX_STACK_LINE(1369)
				this->_flashRect->y = (int)0;
				HX_STACK_LINE(1369)
				this->_flashRect->width = this->frameWidth;
				HX_STACK_LINE(1369)
				this->_flashRect->height = this->frameHeight;
			}
		}
		HX_STACK_LINE(1370)
		this->dirty = true;
	}
	else{
		HX_STACK_LINE(1372)
		if (((bool((bool((this->framesData != null())) && bool((this->framesData->frames != null())))) && bool((this->framesData->frames->length > (int)0))))){
			HX_STACK_LINE(1374)
			this->frame = this->framesData->frames->__get((int)0).StaticCast< ::flixel::system::layer::frames::FlxFrame >();
			HX_STACK_LINE(1375)
			this->dirty = true;
		}
	}
	HX_STACK_LINE(1377)
	return this->frame;
}


HX_DEFINE_DYNAMIC_FUNC1(FlxSprite_obj,set_frame,return )

int FlxSprite_obj::set_facing( int Direction){
	HX_STACK_FRAME("flixel.FlxSprite","set_facing",0xeb9145c0,"flixel.FlxSprite.set_facing","flixel/FlxSprite.hx",1381,0x0384bffa)
	HX_STACK_THIS(this)
	HX_STACK_ARG(Direction,"Direction")
	HX_STACK_LINE(1382)
	if (((this->facing != Direction))){
		HX_STACK_LINE(1384)
		this->dirty = true;
	}
	HX_STACK_LINE(1386)
	this->facing = Direction;
	HX_STACK_LINE(1388)
	if (((bool((this->flipped != (int)0)) && bool((this->facing == (int)1))))){
		HX_STACK_LINE(1388)
		this->_facingMult = (int)-1;
	}
	else{
		HX_STACK_LINE(1388)
		this->_facingMult = (int)1;
	}
	HX_STACK_LINE(1390)
	return Direction;
}


HX_DEFINE_DYNAMIC_FUNC1(FlxSprite_obj,set_facing,return )

Float FlxSprite_obj::set_alpha( Float Alpha){
	HX_STACK_FRAME("flixel.FlxSprite","set_alpha",0x13d8b778,"flixel.FlxSprite.set_alpha","flixel/FlxSprite.hx",1394,0x0384bffa)
	HX_STACK_THIS(this)
	HX_STACK_ARG(Alpha,"Alpha")
	HX_STACK_LINE(1395)
	if (((Alpha > (int)1))){
		HX_STACK_LINE(1397)
		Alpha = (int)1;
	}
	HX_STACK_LINE(1399)
	if (((Alpha < (int)0))){
		HX_STACK_LINE(1401)
		Alpha = (int)0;
	}
	HX_STACK_LINE(1403)
	if (((Alpha == this->alpha))){
		HX_STACK_LINE(1405)
		return this->alpha;
	}
	HX_STACK_LINE(1407)
	this->alpha = Alpha;
	HX_STACK_LINE(1408)
	this->updateColorTransform();
	HX_STACK_LINE(1409)
	return this->alpha;
}


HX_DEFINE_DYNAMIC_FUNC1(FlxSprite_obj,set_alpha,return )

int FlxSprite_obj::set_color( int Color){
	HX_STACK_FRAME("flixel.FlxSprite","set_color",0x3c9e817d,"flixel.FlxSprite.set_color","flixel/FlxSprite.hx",1413,0x0384bffa)
	HX_STACK_THIS(this)
	HX_STACK_ARG(Color,"Color")
	HX_STACK_LINE(1414)
	hx::AndEq(Color,(int)16777215);
	HX_STACK_LINE(1415)
	if (((this->color == Color))){
		HX_STACK_LINE(1417)
		return Color;
	}
	HX_STACK_LINE(1419)
	this->color = Color;
	HX_STACK_LINE(1420)
	this->updateColorTransform();
	HX_STACK_LINE(1423)
	this->_red = (Float(((int(this->color) >> int((int)16)))) / Float((int)255));
	HX_STACK_LINE(1424)
	this->_green = (Float(((int((int(this->color) >> int((int)8))) & int((int)255)))) / Float((int)255));
	HX_STACK_LINE(1425)
	this->_blue = (Float(((int(this->color) & int((int)255)))) / Float((int)255));
	HX_STACK_LINE(1426)
	this->isColored = (this->color < (int)16777215);
	HX_STACK_LINE(1429)
	return this->color;
}


HX_DEFINE_DYNAMIC_FUNC1(FlxSprite_obj,set_color,return )

::flash::geom::ColorTransform FlxSprite_obj::get_colorTransform( ){
	HX_STACK_FRAME("flixel.FlxSprite","get_colorTransform",0xb51cc1bb,"flixel.FlxSprite.get_colorTransform","flixel/FlxSprite.hx",1434,0x0384bffa)
	HX_STACK_THIS(this)
	HX_STACK_LINE(1434)
	return this->_colorTransform;
}


HX_DEFINE_DYNAMIC_FUNC0(FlxSprite_obj,get_colorTransform,return )

Float FlxSprite_obj::set_angle( Float Value){
	HX_STACK_FRAME("flixel.FlxSprite","set_angle",0x152453ed,"flixel.FlxSprite.set_angle","flixel/FlxSprite.hx",1438,0x0384bffa)
	HX_STACK_THIS(this)
	HX_STACK_ARG(Value,"Value")
	HX_STACK_LINE(1439)
	this->_angleChanged = (bool((this->angle != Value)) || bool(this->_angleChanged));
	HX_STACK_LINE(1440)
	return this->super::set_angle(Value);
}


::flash::display::BlendMode FlxSprite_obj::set_blend( ::flash::display::BlendMode Value){
	HX_STACK_FRAME("flixel.FlxSprite","set_blend",0xa736f86b,"flixel.FlxSprite.set_blend","flixel/FlxSprite.hx",1444,0x0384bffa)
	HX_STACK_THIS(this)
	HX_STACK_ARG(Value,"Value")
	HX_STACK_LINE(1446)
	if (((Value != null()))){
		HX_STACK_LINE(1448)
		switch( (int)(Value->__Index())){
			case (int)7: {
				HX_STACK_LINE(1451)
				this->_blendInt = (int)65536;
			}
			;break;
			case (int)2: {
				HX_STACK_LINE(1454)
				this->_blendInt = (int)131072;
			}
			;break;
			case (int)3: {
				HX_STACK_LINE(1456)
				this->_blendInt = (int)262144;
			}
			;break;
			default: {
				HX_STACK_LINE(1459)
				this->_blendInt = (int)0;
			}
		}
	}
	else{
		HX_STACK_LINE(1464)
		this->_blendInt = (int)0;
	}
	HX_STACK_LINE(1468)
	return this->blend = Value;
}


HX_DEFINE_DYNAMIC_FUNC1(FlxSprite_obj,set_blend,return )


FlxSprite_obj::FlxSprite_obj()
{
}

void FlxSprite_obj::__Mark(HX_MARK_PARAMS)
{
	HX_MARK_BEGIN_CLASS(FlxSprite);
	HX_MARK_MEMBER_NAME(animation,"animation");
	HX_MARK_MEMBER_NAME(framePixels,"framePixels");
	HX_MARK_MEMBER_NAME(antialiasing,"antialiasing");
	HX_MARK_MEMBER_NAME(dirty,"dirty");
	HX_MARK_MEMBER_NAME(isColored,"isColored");
	HX_MARK_MEMBER_NAME(frame,"frame");
	HX_MARK_MEMBER_NAME(frameWidth,"frameWidth");
	HX_MARK_MEMBER_NAME(frameHeight,"frameHeight");
	HX_MARK_MEMBER_NAME(frames,"frames");
	HX_MARK_MEMBER_NAME(bakedRotationAngle,"bakedRotationAngle");
	HX_MARK_MEMBER_NAME(alpha,"alpha");
	HX_MARK_MEMBER_NAME(facing,"facing");
	HX_MARK_MEMBER_NAME(flipped,"flipped");
	HX_MARK_MEMBER_NAME(origin,"origin");
	HX_MARK_MEMBER_NAME(offset,"offset");
	HX_MARK_MEMBER_NAME(scale,"scale");
	HX_MARK_MEMBER_NAME(blend,"blend");
	HX_MARK_MEMBER_NAME(color,"color");
	HX_MARK_MEMBER_NAME(useColorTransform,"useColorTransform");
	HX_MARK_MEMBER_NAME(_red,"_red");
	HX_MARK_MEMBER_NAME(_green,"_green");
	HX_MARK_MEMBER_NAME(_blue,"_blue");
	HX_MARK_MEMBER_NAME(_facingMult,"_facingMult");
	HX_MARK_MEMBER_NAME(_blendInt,"_blendInt");
	HX_MARK_MEMBER_NAME(_flashPoint,"_flashPoint");
	HX_MARK_MEMBER_NAME(_flashRect,"_flashRect");
	HX_MARK_MEMBER_NAME(_flashRect2,"_flashRect2");
	HX_MARK_MEMBER_NAME(_flashPointZero,"_flashPointZero");
	HX_MARK_MEMBER_NAME(_colorTransform,"_colorTransform");
	HX_MARK_MEMBER_NAME(_matrix,"_matrix");
	HX_MARK_MEMBER_NAME(_halfWidth,"_halfWidth");
	HX_MARK_MEMBER_NAME(_halfHeight,"_halfHeight");
	HX_MARK_MEMBER_NAME(_sinAngle,"_sinAngle");
	HX_MARK_MEMBER_NAME(_cosAngle,"_cosAngle");
	HX_MARK_MEMBER_NAME(_angleChanged,"_angleChanged");
	::flixel::FlxObject_obj::__Mark(HX_MARK_ARG);
	HX_MARK_END_CLASS();
}

void FlxSprite_obj::__Visit(HX_VISIT_PARAMS)
{
	HX_VISIT_MEMBER_NAME(animation,"animation");
	HX_VISIT_MEMBER_NAME(framePixels,"framePixels");
	HX_VISIT_MEMBER_NAME(antialiasing,"antialiasing");
	HX_VISIT_MEMBER_NAME(dirty,"dirty");
	HX_VISIT_MEMBER_NAME(isColored,"isColored");
	HX_VISIT_MEMBER_NAME(frame,"frame");
	HX_VISIT_MEMBER_NAME(frameWidth,"frameWidth");
	HX_VISIT_MEMBER_NAME(frameHeight,"frameHeight");
	HX_VISIT_MEMBER_NAME(frames,"frames");
	HX_VISIT_MEMBER_NAME(bakedRotationAngle,"bakedRotationAngle");
	HX_VISIT_MEMBER_NAME(alpha,"alpha");
	HX_VISIT_MEMBER_NAME(facing,"facing");
	HX_VISIT_MEMBER_NAME(flipped,"flipped");
	HX_VISIT_MEMBER_NAME(origin,"origin");
	HX_VISIT_MEMBER_NAME(offset,"offset");
	HX_VISIT_MEMBER_NAME(scale,"scale");
	HX_VISIT_MEMBER_NAME(blend,"blend");
	HX_VISIT_MEMBER_NAME(color,"color");
	HX_VISIT_MEMBER_NAME(useColorTransform,"useColorTransform");
	HX_VISIT_MEMBER_NAME(_red,"_red");
	HX_VISIT_MEMBER_NAME(_green,"_green");
	HX_VISIT_MEMBER_NAME(_blue,"_blue");
	HX_VISIT_MEMBER_NAME(_facingMult,"_facingMult");
	HX_VISIT_MEMBER_NAME(_blendInt,"_blendInt");
	HX_VISIT_MEMBER_NAME(_flashPoint,"_flashPoint");
	HX_VISIT_MEMBER_NAME(_flashRect,"_flashRect");
	HX_VISIT_MEMBER_NAME(_flashRect2,"_flashRect2");
	HX_VISIT_MEMBER_NAME(_flashPointZero,"_flashPointZero");
	HX_VISIT_MEMBER_NAME(_colorTransform,"_colorTransform");
	HX_VISIT_MEMBER_NAME(_matrix,"_matrix");
	HX_VISIT_MEMBER_NAME(_halfWidth,"_halfWidth");
	HX_VISIT_MEMBER_NAME(_halfHeight,"_halfHeight");
	HX_VISIT_MEMBER_NAME(_sinAngle,"_sinAngle");
	HX_VISIT_MEMBER_NAME(_cosAngle,"_cosAngle");
	HX_VISIT_MEMBER_NAME(_angleChanged,"_angleChanged");
	::flixel::FlxObject_obj::__Visit(HX_VISIT_ARG);
}

Dynamic FlxSprite_obj::__Field(const ::String &inName,bool inCallProp)
{
	switch(inName.length) {
	case 4:
		if (HX_FIELD_EQ(inName,"_red") ) { return _red; }
		if (HX_FIELD_EQ(inName,"draw") ) { return draw_dyn(); }
		break;
	case 5:
		if (HX_FIELD_EQ(inName,"dirty") ) { return dirty; }
		if (HX_FIELD_EQ(inName,"frame") ) { return frame; }
		if (HX_FIELD_EQ(inName,"alpha") ) { return alpha; }
		if (HX_FIELD_EQ(inName,"scale") ) { return scale; }
		if (HX_FIELD_EQ(inName,"blend") ) { return blend; }
		if (HX_FIELD_EQ(inName,"color") ) { return color; }
		if (HX_FIELD_EQ(inName,"_blue") ) { return _blue; }
		if (HX_FIELD_EQ(inName,"clone") ) { return clone_dyn(); }
		if (HX_FIELD_EQ(inName,"stamp") ) { return stamp_dyn(); }
		break;
	case 6:
		if (HX_FIELD_EQ(inName,"pixels") ) { return get_pixels(); }
		if (HX_FIELD_EQ(inName,"frames") ) { return frames; }
		if (HX_FIELD_EQ(inName,"facing") ) { return facing; }
		if (HX_FIELD_EQ(inName,"origin") ) { return origin; }
		if (HX_FIELD_EQ(inName,"offset") ) { return offset; }
		if (HX_FIELD_EQ(inName,"_green") ) { return _green; }
		if (HX_FIELD_EQ(inName,"update") ) { return update_dyn(); }
		break;
	case 7:
		if (HX_FIELD_EQ(inName,"flipped") ) { return flipped; }
		if (HX_FIELD_EQ(inName,"_matrix") ) { return _matrix; }
		if (HX_FIELD_EQ(inName,"destroy") ) { return destroy_dyn(); }
		break;
	case 8:
		if (HX_FIELD_EQ(inName,"initVars") ) { return initVars_dyn(); }
		break;
	case 9:
		if (HX_FIELD_EQ(inName,"animation") ) { return animation; }
		if (HX_FIELD_EQ(inName,"isColored") ) { return isColored; }
		if (HX_FIELD_EQ(inName,"_blendInt") ) { return _blendInt; }
		if (HX_FIELD_EQ(inName,"_sinAngle") ) { return _sinAngle; }
		if (HX_FIELD_EQ(inName,"_cosAngle") ) { return _cosAngle; }
		if (HX_FIELD_EQ(inName,"resetSize") ) { return resetSize_dyn(); }
		if (HX_FIELD_EQ(inName,"drawFrame") ) { return drawFrame_dyn(); }
		if (HX_FIELD_EQ(inName,"calcFrame") ) { return calcFrame_dyn(); }
		if (HX_FIELD_EQ(inName,"set_frame") ) { return set_frame_dyn(); }
		if (HX_FIELD_EQ(inName,"set_alpha") ) { return set_alpha_dyn(); }
		if (HX_FIELD_EQ(inName,"set_color") ) { return set_color_dyn(); }
		if (HX_FIELD_EQ(inName,"set_angle") ) { return set_angle_dyn(); }
		if (HX_FIELD_EQ(inName,"set_blend") ) { return set_blend_dyn(); }
		break;
	case 10:
		if (HX_FIELD_EQ(inName,"frameWidth") ) { return frameWidth; }
		if (HX_FIELD_EQ(inName,"_flashRect") ) { return _flashRect; }
		if (HX_FIELD_EQ(inName,"_halfWidth") ) { return _halfWidth; }
		if (HX_FIELD_EQ(inName,"isOnScreen") ) { return isOnScreen_dyn(); }
		if (HX_FIELD_EQ(inName,"get_pixels") ) { return get_pixels_dyn(); }
		if (HX_FIELD_EQ(inName,"set_pixels") ) { return set_pixels_dyn(); }
		if (HX_FIELD_EQ(inName,"set_facing") ) { return set_facing_dyn(); }
		break;
	case 11:
		if (HX_FIELD_EQ(inName,"framePixels") ) { return framePixels; }
		if (HX_FIELD_EQ(inName,"frameHeight") ) { return frameHeight; }
		if (HX_FIELD_EQ(inName,"_facingMult") ) { return _facingMult; }
		if (HX_FIELD_EQ(inName,"_flashPoint") ) { return _flashPoint; }
		if (HX_FIELD_EQ(inName,"_flashRect2") ) { return _flashRect2; }
		if (HX_FIELD_EQ(inName,"_halfHeight") ) { return _halfHeight; }
		if (HX_FIELD_EQ(inName,"loadGraphic") ) { return loadGraphic_dyn(); }
		if (HX_FIELD_EQ(inName,"makeGraphic") ) { return makeGraphic_dyn(); }
		break;
	case 12:
		if (HX_FIELD_EQ(inName,"antialiasing") ) { return antialiasing; }
		if (HX_FIELD_EQ(inName,"updateHitbox") ) { return updateHitbox_dyn(); }
		if (HX_FIELD_EQ(inName,"resetHelpers") ) { return resetHelpers_dyn(); }
		if (HX_FIELD_EQ(inName,"replaceColor") ) { return replaceColor_dyn(); }
		break;
	case 13:
		if (HX_FIELD_EQ(inName,"_angleChanged") ) { return _angleChanged; }
		if (HX_FIELD_EQ(inName,"centerOffsets") ) { return centerOffsets_dyn(); }
		break;
	case 14:
		if (HX_FIELD_EQ(inName,"colorTransform") ) { return get_colorTransform(); }
		if (HX_FIELD_EQ(inName,"resetFrameSize") ) { return resetFrameSize_dyn(); }
		if (HX_FIELD_EQ(inName,"setGraphicSize") ) { return setGraphicSize_dyn(); }
		if (HX_FIELD_EQ(inName,"isSimpleRender") ) { return isSimpleRender_dyn(); }
		break;
	case 15:
		if (HX_FIELD_EQ(inName,"_flashPointZero") ) { return _flashPointZero; }
		if (HX_FIELD_EQ(inName,"_colorTransform") ) { return _colorTransform; }
		if (HX_FIELD_EQ(inName,"updateFrameData") ) { return updateFrameData_dyn(); }
		break;
	case 17:
		if (HX_FIELD_EQ(inName,"useColorTransform") ) { return useColorTransform; }
		if (HX_FIELD_EQ(inName,"setOriginToCenter") ) { return setOriginToCenter_dyn(); }
		if (HX_FIELD_EQ(inName,"setColorTransform") ) { return setColorTransform_dyn(); }
		break;
	case 18:
		if (HX_FIELD_EQ(inName,"bakedRotationAngle") ) { return bakedRotationAngle; }
		if (HX_FIELD_EQ(inName,"loadRotatedGraphic") ) { return loadRotatedGraphic_dyn(); }
		if (HX_FIELD_EQ(inName,"resetSizeFromFrame") ) { return resetSizeFromFrame_dyn(); }
		if (HX_FIELD_EQ(inName,"pixelsOverlapPoint") ) { return pixelsOverlapPoint_dyn(); }
		if (HX_FIELD_EQ(inName,"getGraphicMidpoint") ) { return getGraphicMidpoint_dyn(); }
		if (HX_FIELD_EQ(inName,"get_colorTransform") ) { return get_colorTransform_dyn(); }
		break;
	case 20:
		if (HX_FIELD_EQ(inName,"updateColorTransform") ) { return updateColorTransform_dyn(); }
		break;
	case 21:
		if (HX_FIELD_EQ(inName,"loadGraphicFromSprite") ) { return loadGraphicFromSprite_dyn(); }
		if (HX_FIELD_EQ(inName,"getFlxFrameBitmapData") ) { return getFlxFrameBitmapData_dyn(); }
		if (HX_FIELD_EQ(inName,"resetFrameBitmapDatas") ) { return resetFrameBitmapDatas_dyn(); }
		break;
	case 22:
		if (HX_FIELD_EQ(inName,"loadGraphicFromTexture") ) { return loadGraphicFromTexture_dyn(); }
		break;
	case 29:
		if (HX_FIELD_EQ(inName,"loadRotatedGraphicFromTexture") ) { return loadRotatedGraphicFromTexture_dyn(); }
	}
	return super::__Field(inName,inCallProp);
}

Dynamic FlxSprite_obj::__SetField(const ::String &inName,const Dynamic &inValue,bool inCallProp)
{
	switch(inName.length) {
	case 4:
		if (HX_FIELD_EQ(inName,"_red") ) { _red=inValue.Cast< Float >(); return inValue; }
		break;
	case 5:
		if (HX_FIELD_EQ(inName,"dirty") ) { dirty=inValue.Cast< bool >(); return inValue; }
		if (HX_FIELD_EQ(inName,"frame") ) { if (inCallProp) return set_frame(inValue);frame=inValue.Cast< ::flixel::system::layer::frames::FlxFrame >(); return inValue; }
		if (HX_FIELD_EQ(inName,"alpha") ) { if (inCallProp) return set_alpha(inValue);alpha=inValue.Cast< Float >(); return inValue; }
		if (HX_FIELD_EQ(inName,"scale") ) { scale=inValue.Cast< ::flixel::util::FlxPoint >(); return inValue; }
		if (HX_FIELD_EQ(inName,"blend") ) { if (inCallProp) return set_blend(inValue);blend=inValue.Cast< ::flash::display::BlendMode >(); return inValue; }
		if (HX_FIELD_EQ(inName,"color") ) { if (inCallProp) return set_color(inValue);color=inValue.Cast< int >(); return inValue; }
		if (HX_FIELD_EQ(inName,"_blue") ) { _blue=inValue.Cast< Float >(); return inValue; }
		break;
	case 6:
		if (HX_FIELD_EQ(inName,"pixels") ) { return set_pixels(inValue); }
		if (HX_FIELD_EQ(inName,"frames") ) { frames=inValue.Cast< int >(); return inValue; }
		if (HX_FIELD_EQ(inName,"facing") ) { if (inCallProp) return set_facing(inValue);facing=inValue.Cast< int >(); return inValue; }
		if (HX_FIELD_EQ(inName,"origin") ) { origin=inValue.Cast< ::flixel::util::FlxPoint >(); return inValue; }
		if (HX_FIELD_EQ(inName,"offset") ) { offset=inValue.Cast< ::flixel::util::FlxPoint >(); return inValue; }
		if (HX_FIELD_EQ(inName,"_green") ) { _green=inValue.Cast< Float >(); return inValue; }
		break;
	case 7:
		if (HX_FIELD_EQ(inName,"flipped") ) { flipped=inValue.Cast< int >(); return inValue; }
		if (HX_FIELD_EQ(inName,"_matrix") ) { _matrix=inValue.Cast< ::flash::geom::Matrix >(); return inValue; }
		break;
	case 9:
		if (HX_FIELD_EQ(inName,"animation") ) { animation=inValue.Cast< ::flixel::animation::FlxAnimationController >(); return inValue; }
		if (HX_FIELD_EQ(inName,"isColored") ) { isColored=inValue.Cast< bool >(); return inValue; }
		if (HX_FIELD_EQ(inName,"_blendInt") ) { _blendInt=inValue.Cast< int >(); return inValue; }
		if (HX_FIELD_EQ(inName,"_sinAngle") ) { _sinAngle=inValue.Cast< Float >(); return inValue; }
		if (HX_FIELD_EQ(inName,"_cosAngle") ) { _cosAngle=inValue.Cast< Float >(); return inValue; }
		break;
	case 10:
		if (HX_FIELD_EQ(inName,"frameWidth") ) { frameWidth=inValue.Cast< int >(); return inValue; }
		if (HX_FIELD_EQ(inName,"_flashRect") ) { _flashRect=inValue.Cast< ::flash::geom::Rectangle >(); return inValue; }
		if (HX_FIELD_EQ(inName,"_halfWidth") ) { _halfWidth=inValue.Cast< Float >(); return inValue; }
		break;
	case 11:
		if (HX_FIELD_EQ(inName,"framePixels") ) { framePixels=inValue.Cast< ::flash::display::BitmapData >(); return inValue; }
		if (HX_FIELD_EQ(inName,"frameHeight") ) { frameHeight=inValue.Cast< int >(); return inValue; }
		if (HX_FIELD_EQ(inName,"_facingMult") ) { _facingMult=inValue.Cast< int >(); return inValue; }
		if (HX_FIELD_EQ(inName,"_flashPoint") ) { _flashPoint=inValue.Cast< ::flash::geom::Point >(); return inValue; }
		if (HX_FIELD_EQ(inName,"_flashRect2") ) { _flashRect2=inValue.Cast< ::flash::geom::Rectangle >(); return inValue; }
		if (HX_FIELD_EQ(inName,"_halfHeight") ) { _halfHeight=inValue.Cast< Float >(); return inValue; }
		break;
	case 12:
		if (HX_FIELD_EQ(inName,"antialiasing") ) { antialiasing=inValue.Cast< bool >(); return inValue; }
		break;
	case 13:
		if (HX_FIELD_EQ(inName,"_angleChanged") ) { _angleChanged=inValue.Cast< bool >(); return inValue; }
		break;
	case 15:
		if (HX_FIELD_EQ(inName,"_flashPointZero") ) { _flashPointZero=inValue.Cast< ::flash::geom::Point >(); return inValue; }
		if (HX_FIELD_EQ(inName,"_colorTransform") ) { _colorTransform=inValue.Cast< ::flash::geom::ColorTransform >(); return inValue; }
		break;
	case 17:
		if (HX_FIELD_EQ(inName,"useColorTransform") ) { useColorTransform=inValue.Cast< bool >(); return inValue; }
		break;
	case 18:
		if (HX_FIELD_EQ(inName,"bakedRotationAngle") ) { bakedRotationAngle=inValue.Cast< Float >(); return inValue; }
	}
	return super::__SetField(inName,inValue,inCallProp);
}

void FlxSprite_obj::__GetFields(Array< ::String> &outFields)
{
	outFields->push(HX_CSTRING("animation"));
	outFields->push(HX_CSTRING("framePixels"));
	outFields->push(HX_CSTRING("antialiasing"));
	outFields->push(HX_CSTRING("dirty"));
	outFields->push(HX_CSTRING("isColored"));
	outFields->push(HX_CSTRING("pixels"));
	outFields->push(HX_CSTRING("frame"));
	outFields->push(HX_CSTRING("frameWidth"));
	outFields->push(HX_CSTRING("frameHeight"));
	outFields->push(HX_CSTRING("frames"));
	outFields->push(HX_CSTRING("bakedRotationAngle"));
	outFields->push(HX_CSTRING("alpha"));
	outFields->push(HX_CSTRING("facing"));
	outFields->push(HX_CSTRING("flipped"));
	outFields->push(HX_CSTRING("origin"));
	outFields->push(HX_CSTRING("offset"));
	outFields->push(HX_CSTRING("scale"));
	outFields->push(HX_CSTRING("blend"));
	outFields->push(HX_CSTRING("color"));
	outFields->push(HX_CSTRING("colorTransform"));
	outFields->push(HX_CSTRING("useColorTransform"));
	outFields->push(HX_CSTRING("_red"));
	outFields->push(HX_CSTRING("_green"));
	outFields->push(HX_CSTRING("_blue"));
	outFields->push(HX_CSTRING("_facingMult"));
	outFields->push(HX_CSTRING("_blendInt"));
	outFields->push(HX_CSTRING("_flashPoint"));
	outFields->push(HX_CSTRING("_flashRect"));
	outFields->push(HX_CSTRING("_flashRect2"));
	outFields->push(HX_CSTRING("_flashPointZero"));
	outFields->push(HX_CSTRING("_colorTransform"));
	outFields->push(HX_CSTRING("_matrix"));
	outFields->push(HX_CSTRING("_halfWidth"));
	outFields->push(HX_CSTRING("_halfHeight"));
	outFields->push(HX_CSTRING("_sinAngle"));
	outFields->push(HX_CSTRING("_cosAngle"));
	outFields->push(HX_CSTRING("_angleChanged"));
	super::__GetFields(outFields);
};

static ::String sStaticFields[] = {
	String(null()) };

#if HXCPP_SCRIPTABLE
static hx::StorageInfo sMemberStorageInfo[] = {
	{hx::fsObject /*::flixel::animation::FlxAnimationController*/ ,(int)offsetof(FlxSprite_obj,animation),HX_CSTRING("animation")},
	{hx::fsObject /*::flash::display::BitmapData*/ ,(int)offsetof(FlxSprite_obj,framePixels),HX_CSTRING("framePixels")},
	{hx::fsBool,(int)offsetof(FlxSprite_obj,antialiasing),HX_CSTRING("antialiasing")},
	{hx::fsBool,(int)offsetof(FlxSprite_obj,dirty),HX_CSTRING("dirty")},
	{hx::fsBool,(int)offsetof(FlxSprite_obj,isColored),HX_CSTRING("isColored")},
	{hx::fsObject /*::flixel::system::layer::frames::FlxFrame*/ ,(int)offsetof(FlxSprite_obj,frame),HX_CSTRING("frame")},
	{hx::fsInt,(int)offsetof(FlxSprite_obj,frameWidth),HX_CSTRING("frameWidth")},
	{hx::fsInt,(int)offsetof(FlxSprite_obj,frameHeight),HX_CSTRING("frameHeight")},
	{hx::fsInt,(int)offsetof(FlxSprite_obj,frames),HX_CSTRING("frames")},
	{hx::fsFloat,(int)offsetof(FlxSprite_obj,bakedRotationAngle),HX_CSTRING("bakedRotationAngle")},
	{hx::fsFloat,(int)offsetof(FlxSprite_obj,alpha),HX_CSTRING("alpha")},
	{hx::fsInt,(int)offsetof(FlxSprite_obj,facing),HX_CSTRING("facing")},
	{hx::fsInt,(int)offsetof(FlxSprite_obj,flipped),HX_CSTRING("flipped")},
	{hx::fsObject /*::flixel::util::FlxPoint*/ ,(int)offsetof(FlxSprite_obj,origin),HX_CSTRING("origin")},
	{hx::fsObject /*::flixel::util::FlxPoint*/ ,(int)offsetof(FlxSprite_obj,offset),HX_CSTRING("offset")},
	{hx::fsObject /*::flixel::util::FlxPoint*/ ,(int)offsetof(FlxSprite_obj,scale),HX_CSTRING("scale")},
	{hx::fsObject /*::flash::display::BlendMode*/ ,(int)offsetof(FlxSprite_obj,blend),HX_CSTRING("blend")},
	{hx::fsInt,(int)offsetof(FlxSprite_obj,color),HX_CSTRING("color")},
	{hx::fsBool,(int)offsetof(FlxSprite_obj,useColorTransform),HX_CSTRING("useColorTransform")},
	{hx::fsFloat,(int)offsetof(FlxSprite_obj,_red),HX_CSTRING("_red")},
	{hx::fsFloat,(int)offsetof(FlxSprite_obj,_green),HX_CSTRING("_green")},
	{hx::fsFloat,(int)offsetof(FlxSprite_obj,_blue),HX_CSTRING("_blue")},
	{hx::fsInt,(int)offsetof(FlxSprite_obj,_facingMult),HX_CSTRING("_facingMult")},
	{hx::fsInt,(int)offsetof(FlxSprite_obj,_blendInt),HX_CSTRING("_blendInt")},
	{hx::fsObject /*::flash::geom::Point*/ ,(int)offsetof(FlxSprite_obj,_flashPoint),HX_CSTRING("_flashPoint")},
	{hx::fsObject /*::flash::geom::Rectangle*/ ,(int)offsetof(FlxSprite_obj,_flashRect),HX_CSTRING("_flashRect")},
	{hx::fsObject /*::flash::geom::Rectangle*/ ,(int)offsetof(FlxSprite_obj,_flashRect2),HX_CSTRING("_flashRect2")},
	{hx::fsObject /*::flash::geom::Point*/ ,(int)offsetof(FlxSprite_obj,_flashPointZero),HX_CSTRING("_flashPointZero")},
	{hx::fsObject /*::flash::geom::ColorTransform*/ ,(int)offsetof(FlxSprite_obj,_colorTransform),HX_CSTRING("_colorTransform")},
	{hx::fsObject /*::flash::geom::Matrix*/ ,(int)offsetof(FlxSprite_obj,_matrix),HX_CSTRING("_matrix")},
	{hx::fsFloat,(int)offsetof(FlxSprite_obj,_halfWidth),HX_CSTRING("_halfWidth")},
	{hx::fsFloat,(int)offsetof(FlxSprite_obj,_halfHeight),HX_CSTRING("_halfHeight")},
	{hx::fsFloat,(int)offsetof(FlxSprite_obj,_sinAngle),HX_CSTRING("_sinAngle")},
	{hx::fsFloat,(int)offsetof(FlxSprite_obj,_cosAngle),HX_CSTRING("_cosAngle")},
	{hx::fsBool,(int)offsetof(FlxSprite_obj,_angleChanged),HX_CSTRING("_angleChanged")},
	{ hx::fsUnknown, 0, null()}
};
#endif

static ::String sMemberFields[] = {
	HX_CSTRING("animation"),
	HX_CSTRING("framePixels"),
	HX_CSTRING("antialiasing"),
	HX_CSTRING("dirty"),
	HX_CSTRING("isColored"),
	HX_CSTRING("frame"),
	HX_CSTRING("frameWidth"),
	HX_CSTRING("frameHeight"),
	HX_CSTRING("frames"),
	HX_CSTRING("bakedRotationAngle"),
	HX_CSTRING("alpha"),
	HX_CSTRING("facing"),
	HX_CSTRING("flipped"),
	HX_CSTRING("origin"),
	HX_CSTRING("offset"),
	HX_CSTRING("scale"),
	HX_CSTRING("blend"),
	HX_CSTRING("color"),
	HX_CSTRING("useColorTransform"),
	HX_CSTRING("_red"),
	HX_CSTRING("_green"),
	HX_CSTRING("_blue"),
	HX_CSTRING("_facingMult"),
	HX_CSTRING("_blendInt"),
	HX_CSTRING("_flashPoint"),
	HX_CSTRING("_flashRect"),
	HX_CSTRING("_flashRect2"),
	HX_CSTRING("_flashPointZero"),
	HX_CSTRING("_colorTransform"),
	HX_CSTRING("_matrix"),
	HX_CSTRING("_halfWidth"),
	HX_CSTRING("_halfHeight"),
	HX_CSTRING("_sinAngle"),
	HX_CSTRING("_cosAngle"),
	HX_CSTRING("_angleChanged"),
	HX_CSTRING("initVars"),
	HX_CSTRING("destroy"),
	HX_CSTRING("clone"),
	HX_CSTRING("loadGraphicFromSprite"),
	HX_CSTRING("loadGraphic"),
	HX_CSTRING("loadRotatedGraphic"),
	HX_CSTRING("loadGraphicFromTexture"),
	HX_CSTRING("loadRotatedGraphicFromTexture"),
	HX_CSTRING("makeGraphic"),
	HX_CSTRING("resetSize"),
	HX_CSTRING("resetFrameSize"),
	HX_CSTRING("resetSizeFromFrame"),
	HX_CSTRING("setOriginToCenter"),
	HX_CSTRING("setGraphicSize"),
	HX_CSTRING("updateHitbox"),
	HX_CSTRING("resetHelpers"),
	HX_CSTRING("update"),
	HX_CSTRING("draw"),
	HX_CSTRING("stamp"),
	HX_CSTRING("drawFrame"),
	HX_CSTRING("centerOffsets"),
	HX_CSTRING("replaceColor"),
	HX_CSTRING("setColorTransform"),
	HX_CSTRING("updateColorTransform"),
	HX_CSTRING("pixelsOverlapPoint"),
	HX_CSTRING("calcFrame"),
	HX_CSTRING("updateFrameData"),
	HX_CSTRING("getFlxFrameBitmapData"),
	HX_CSTRING("getGraphicMidpoint"),
	HX_CSTRING("resetFrameBitmapDatas"),
	HX_CSTRING("isOnScreen"),
	HX_CSTRING("isSimpleRender"),
	HX_CSTRING("get_pixels"),
	HX_CSTRING("set_pixels"),
	HX_CSTRING("set_frame"),
	HX_CSTRING("set_facing"),
	HX_CSTRING("set_alpha"),
	HX_CSTRING("set_color"),
	HX_CSTRING("get_colorTransform"),
	HX_CSTRING("set_angle"),
	HX_CSTRING("set_blend"),
	String(null()) };

static void sMarkStatics(HX_MARK_PARAMS) {
	HX_MARK_MEMBER_NAME(FlxSprite_obj::__mClass,"__mClass");
};

#ifdef HXCPP_VISIT_ALLOCS
static void sVisitStatics(HX_VISIT_PARAMS) {
	HX_VISIT_MEMBER_NAME(FlxSprite_obj::__mClass,"__mClass");
};

#endif

Class FlxSprite_obj::__mClass;

void FlxSprite_obj::__register()
{
	hx::Static(__mClass) = hx::RegisterClass(HX_CSTRING("flixel.FlxSprite"), hx::TCanCast< FlxSprite_obj> ,sStaticFields,sMemberFields,
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

void FlxSprite_obj::__boot()
{
}

} // end namespace flixel
