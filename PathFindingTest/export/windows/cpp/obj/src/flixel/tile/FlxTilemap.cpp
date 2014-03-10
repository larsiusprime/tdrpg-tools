#include <hxcpp.h>

#ifndef INCLUDED_Reflect
#include <Reflect.h>
#endif
#ifndef INCLUDED_Std
#include <Std.h>
#endif
#ifndef INCLUDED_Type
#include <Type.h>
#endif
#ifndef INCLUDED_ValueType
#include <ValueType.h>
#endif
#ifndef INCLUDED_flash_display_BitmapData
#include <flash/display/BitmapData.h>
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
#ifndef INCLUDED_flixel_group_FlxTypedGroup
#include <flixel/group/FlxTypedGroup.h>
#endif
#ifndef INCLUDED_flixel_interfaces_IFlxDestroyable
#include <flixel/interfaces/IFlxDestroyable.h>
#endif
#ifndef INCLUDED_flixel_system_FlxCollisionType
#include <flixel/system/FlxCollisionType.h>
#endif
#ifndef INCLUDED_flixel_system_frontEnds_BitmapFrontEnd
#include <flixel/system/frontEnds/BitmapFrontEnd.h>
#endif
#ifndef INCLUDED_flixel_system_frontEnds_CameraFrontEnd
#include <flixel/system/frontEnds/CameraFrontEnd.h>
#endif
#ifndef INCLUDED_flixel_system_frontEnds_DebuggerFrontEnd
#include <flixel/system/frontEnds/DebuggerFrontEnd.h>
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
#ifndef INCLUDED_flixel_tile_FlxTile
#include <flixel/tile/FlxTile.h>
#endif
#ifndef INCLUDED_flixel_tile_FlxTilemap
#include <flixel/tile/FlxTilemap.h>
#endif
#ifndef INCLUDED_flixel_tile_FlxTilemapBuffer
#include <flixel/tile/FlxTilemapBuffer.h>
#endif
#ifndef INCLUDED_flixel_util_FlxArrayUtil
#include <flixel/util/FlxArrayUtil.h>
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
#ifndef INCLUDED_flixel_util_loaders_TextureRegion
#include <flixel/util/loaders/TextureRegion.h>
#endif
#ifndef INCLUDED_hxMath
#include <hxMath.h>
#endif
namespace flixel{
namespace tile{

Void FlxTilemap_obj::__construct()
{
HX_STACK_FRAME("flixel.tile.FlxTilemap","new",0xbe02531c,"flixel.tile.FlxTilemap.new","flixel/tile/FlxTilemap.hx",32,0x448feb74)
{
	HX_STACK_LINE(173)
	this->_startingIndex = (int)0;
	HX_STACK_LINE(138)
	this->_scaledTileHeight = (int)0;
	HX_STACK_LINE(137)
	this->_scaledTileWidth = (int)0;
	HX_STACK_LINE(135)
	this->_tileHeight = (int)0;
	HX_STACK_LINE(131)
	this->_tileWidth = (int)0;
	HX_STACK_LINE(82)
	this->scaleY = 1.0;
	HX_STACK_LINE(81)
	this->scaleX = 1.0;
	HX_STACK_LINE(66)
	this->tileScaleHack = 1.01;
	HX_STACK_LINE(62)
	this->totalTiles = (int)0;
	HX_STACK_LINE(58)
	this->heightInTiles = (int)0;
	HX_STACK_LINE(54)
	this->widthInTiles = (int)0;
	HX_STACK_LINE(50)
	this->_auto = (int)0;
	HX_STACK_LINE(190)
	super::__construct(null(),null(),null(),null());
	HX_STACK_LINE(192)
	this->collisionType = ::flixel::system::FlxCollisionType_obj::TILEMAP;
	HX_STACK_LINE(194)
	this->_buffers = Array_obj< ::Dynamic >::__new();
	HX_STACK_LINE(195)
	this->_flashPoint = ::flash::geom::Point_obj::__new(null(),null());
	HX_STACK_LINE(197)
	this->_tileWidth = (int)0;
	HX_STACK_LINE(198)
	this->_tileHeight = (int)0;
	HX_STACK_LINE(200)
	this->set_immovable(true);
	HX_STACK_LINE(201)
	this->set_moves(false);
	HX_STACK_LINE(204)
	this->_lastVisualDebug = ::flixel::FlxG_obj::debugger->drawDebug;
	HX_STACK_LINE(207)
	this->_startingIndex = (int)0;
	HX_STACK_LINE(210)
	this->_helperPoint = ::flash::geom::Point_obj::__new(null(),null());
}
;
	return null();
}

//FlxTilemap_obj::~FlxTilemap_obj() { }

Dynamic FlxTilemap_obj::__CreateEmpty() { return  new FlxTilemap_obj; }
hx::ObjectPtr< FlxTilemap_obj > FlxTilemap_obj::__new()
{  hx::ObjectPtr< FlxTilemap_obj > result = new FlxTilemap_obj();
	result->__construct();
	return result;}

Dynamic FlxTilemap_obj::__Create(hx::DynamicArray inArgs)
{  hx::ObjectPtr< FlxTilemap_obj > result = new FlxTilemap_obj();
	result->__construct();
	return result;}

Void FlxTilemap_obj::destroy( ){
{
		HX_STACK_FRAME("flixel.tile.FlxTilemap","destroy",0xa7f2bdb6,"flixel.tile.FlxTilemap.destroy","flixel/tile/FlxTilemap.hx",218,0x448feb74)
		HX_STACK_THIS(this)
		HX_STACK_LINE(219)
		this->_flashPoint = null();
		HX_STACK_LINE(220)
		this->_flashRect = null();
		HX_STACK_LINE(221)
		int i = (int)0;		HX_STACK_VAR(i,"i");
		HX_STACK_LINE(222)
		int l;		HX_STACK_VAR(l,"l");
		HX_STACK_LINE(224)
		if (((this->_tileObjects != null()))){
			HX_STACK_LINE(226)
			l = this->_tileObjects->length;
			HX_STACK_LINE(228)
			{
				HX_STACK_LINE(228)
				int _g = (int)0;		HX_STACK_VAR(_g,"_g");
				HX_STACK_LINE(228)
				while(((_g < l))){
					HX_STACK_LINE(228)
					int i1 = (_g)++;		HX_STACK_VAR(i1,"i1");
					HX_STACK_LINE(230)
					this->_tileObjects->__get(i1).StaticCast< ::flixel::tile::FlxTile >()->destroy();
				}
			}
			HX_STACK_LINE(233)
			this->_tileObjects = null();
		}
		HX_STACK_LINE(236)
		if (((this->_buffers != null()))){
			HX_STACK_LINE(238)
			i = (int)0;
			HX_STACK_LINE(239)
			l = this->_buffers->length;
			HX_STACK_LINE(241)
			{
				HX_STACK_LINE(241)
				int _g = (int)0;		HX_STACK_VAR(_g,"_g");
				HX_STACK_LINE(241)
				while(((_g < l))){
					HX_STACK_LINE(241)
					int i1 = (_g)++;		HX_STACK_VAR(i1,"i1");
					HX_STACK_LINE(243)
					this->_buffers->__get(i1).StaticCast< ::flixel::tile::FlxTilemapBuffer >()->destroy();
				}
			}
			HX_STACK_LINE(246)
			this->_buffers = null();
		}
		HX_STACK_LINE(249)
		this->_data = null();
		HX_STACK_LINE(260)
		this->_helperPoint = null();
		HX_STACK_LINE(261)
		this->_rectIDs = null();
		HX_STACK_LINE(264)
		this->super::destroy();
	}
return null();
}


::flixel::tile::FlxTilemap FlxTilemap_obj::loadMap( Dynamic MapData,Dynamic TileGraphic,hx::Null< int >  __o_TileWidth,hx::Null< int >  __o_TileHeight,hx::Null< int >  __o_AutoTile,hx::Null< int >  __o_StartingIndex,hx::Null< int >  __o_DrawIndex,hx::Null< int >  __o_CollideIndex){
int TileWidth = __o_TileWidth.Default(0);
int TileHeight = __o_TileHeight.Default(0);
int AutoTile = __o_AutoTile.Default(0);
int StartingIndex = __o_StartingIndex.Default(0);
int DrawIndex = __o_DrawIndex.Default(1);
int CollideIndex = __o_CollideIndex.Default(1);
	HX_STACK_FRAME("flixel.tile.FlxTilemap","loadMap",0x8c4a14d2,"flixel.tile.FlxTilemap.loadMap","flixel/tile/FlxTilemap.hx",281,0x448feb74)
	HX_STACK_THIS(this)
	HX_STACK_ARG(MapData,"MapData")
	HX_STACK_ARG(TileGraphic,"TileGraphic")
	HX_STACK_ARG(TileWidth,"TileWidth")
	HX_STACK_ARG(TileHeight,"TileHeight")
	HX_STACK_ARG(AutoTile,"AutoTile")
	HX_STACK_ARG(StartingIndex,"StartingIndex")
	HX_STACK_ARG(DrawIndex,"DrawIndex")
	HX_STACK_ARG(CollideIndex,"CollideIndex")
{
		HX_STACK_LINE(282)
		this->_auto = AutoTile;
		HX_STACK_LINE(283)
		if (((StartingIndex <= (int)0))){
			HX_STACK_LINE(283)
			this->_startingIndex = (int)0;
		}
		else{
			HX_STACK_LINE(283)
			this->_startingIndex = StartingIndex;
		}
		HX_STACK_LINE(286)
		if ((::Std_obj::is(MapData,hx::ClassOf< ::String >()))){
			HX_STACK_LINE(289)
			this->_data = Array_obj< int >::__new();
			HX_STACK_LINE(290)
			Array< ::String > columns;		HX_STACK_VAR(columns,"columns");
			HX_STACK_LINE(291)
			Array< ::String > rows = MapData->__Field(HX_CSTRING("split"),true)(HX_CSTRING("\n"));		HX_STACK_VAR(rows,"rows");
			HX_STACK_LINE(292)
			this->heightInTiles = rows->length;
			HX_STACK_LINE(293)
			this->widthInTiles = (int)0;
			HX_STACK_LINE(294)
			int row = (int)0;		HX_STACK_VAR(row,"row");
			HX_STACK_LINE(295)
			int column;		HX_STACK_VAR(column,"column");
			HX_STACK_LINE(297)
			while(((row < this->heightInTiles))){
				HX_STACK_LINE(299)
				columns = rows->__get((row)++).split(HX_CSTRING(","));
				HX_STACK_LINE(301)
				if (((columns->length <= (int)1))){
					HX_STACK_LINE(303)
					this->heightInTiles = (this->heightInTiles - (int)1);
					HX_STACK_LINE(304)
					continue;
				}
				HX_STACK_LINE(306)
				if (((this->widthInTiles == (int)0))){
					HX_STACK_LINE(308)
					this->widthInTiles = columns->length;
				}
				HX_STACK_LINE(310)
				column = (int)0;
				HX_STACK_LINE(312)
				while(((column < this->widthInTiles))){
					HX_STACK_LINE(314)
					this->_data->push(::Std_obj::parseInt(columns->__get((column)++)));
				}
			}
		}
		else{
			HX_STACK_LINE(320)
			if ((::Std_obj::is(MapData,hx::ClassOf< Array<int> >()))){
				HX_STACK_LINE(322)
				this->_data = MapData;
			}
			else{
				HX_STACK_LINE(326)
				HX_STACK_DO_THROW(((HX_CSTRING("Unexpected MapData format '") + ::Std_obj::string(::Type_obj::_typeof(MapData))) + HX_CSTRING("' passed into loadMap. Map data must be CSV string or Array<Int>.")));
			}
		}
		HX_STACK_LINE(330)
		int i;		HX_STACK_VAR(i,"i");
		HX_STACK_LINE(331)
		this->totalTiles = this->_data->length;
		HX_STACK_LINE(333)
		if (((this->_auto > (int)0))){
			HX_STACK_LINE(335)
			this->_startingIndex = (int)1;
			HX_STACK_LINE(336)
			DrawIndex = (int)1;
			HX_STACK_LINE(337)
			CollideIndex = (int)1;
			HX_STACK_LINE(338)
			i = (int)0;
			HX_STACK_LINE(340)
			while(((i < this->totalTiles))){
				HX_STACK_LINE(342)
				this->autoTile((i)++);
			}
		}
		HX_STACK_LINE(346)
		if (((this->customTileRemap != null()))){
			HX_STACK_LINE(348)
			i = (int)0;
			HX_STACK_LINE(349)
			while(((i < this->totalTiles))){
				HX_STACK_LINE(351)
				int old_index = this->_data->__get(i);		HX_STACK_VAR(old_index,"old_index");
				HX_STACK_LINE(352)
				int new_index = old_index;		HX_STACK_VAR(new_index,"new_index");
				HX_STACK_LINE(353)
				if (((old_index < this->customTileRemap->length))){
					HX_STACK_LINE(355)
					new_index = this->customTileRemap->__get(old_index);
				}
				HX_STACK_LINE(357)
				this->_data[i] = new_index;
				HX_STACK_LINE(358)
				(i)++;
			}
		}
		HX_STACK_LINE(362)
		if (((this->_randomIndices != null()))){
			HX_STACK_LINE(364)
			Dynamic randLambda;		HX_STACK_VAR(randLambda,"randLambda");
			HX_STACK_LINE(364)
			if (((this->_randomLambda_dyn() != null()))){
				HX_STACK_LINE(364)
				randLambda = this->_randomLambda_dyn();
			}
			else{
				HX_STACK_LINE(364)
				randLambda = ::flixel::util::FlxRandom_obj::_float_dyn();
			}
			HX_STACK_LINE(366)
			i = (int)0;
			HX_STACK_LINE(367)
			while(((i < this->totalTiles))){
				HX_STACK_LINE(369)
				int old_index = this->_data->__get(i);		HX_STACK_VAR(old_index,"old_index");
				HX_STACK_LINE(370)
				int j = (int)0;		HX_STACK_VAR(j,"j");
				HX_STACK_LINE(371)
				int new_index = old_index;		HX_STACK_VAR(new_index,"new_index");
				HX_STACK_LINE(372)
				{
					HX_STACK_LINE(372)
					int _g = (int)0;		HX_STACK_VAR(_g,"_g");
					HX_STACK_LINE(372)
					Array< int > _g1 = this->_randomIndices;		HX_STACK_VAR(_g1,"_g1");
					HX_STACK_LINE(372)
					while(((_g < _g1->length))){
						HX_STACK_LINE(372)
						int rand = _g1->__get(_g);		HX_STACK_VAR(rand,"rand");
						HX_STACK_LINE(372)
						++(_g);
						HX_STACK_LINE(374)
						if (((old_index == rand))){
							HX_STACK_LINE(376)
							int k = ::Std_obj::_int((randLambda().Cast< Float >() * this->_randomChoices->__get(j).StaticCast< Array< int > >()->length));		HX_STACK_VAR(k,"k");
							HX_STACK_LINE(377)
							new_index = this->_randomChoices->__get(j).StaticCast< Array< int > >()->__get(k);
						}
						HX_STACK_LINE(379)
						(j)++;
					}
				}
				HX_STACK_LINE(381)
				this->_data[i] = new_index;
				HX_STACK_LINE(382)
				(i)++;
			}
		}
		HX_STACK_LINE(387)
		this->set_cachedGraphics(::flixel::FlxG_obj::bitmap->add(TileGraphic,null(),null()));
		HX_STACK_LINE(388)
		this->_tileWidth = TileWidth;
		HX_STACK_LINE(390)
		if (((this->_tileWidth <= (int)0))){
			HX_STACK_LINE(392)
			this->_tileWidth = this->cachedGraphics->bitmap->get_height();
		}
		HX_STACK_LINE(395)
		this->_tileHeight = TileHeight;
		HX_STACK_LINE(397)
		if (((this->_tileHeight <= (int)0))){
			HX_STACK_LINE(399)
			this->_tileHeight = this->_tileWidth;
		}
		HX_STACK_LINE(402)
		if ((!(::Std_obj::is(TileGraphic,hx::ClassOf< ::flixel::util::loaders::TextureRegion >())))){
			HX_STACK_LINE(404)
			this->region = ::flixel::system::layer::Region_obj::__new((int)0,(int)0,this->_tileWidth,this->_tileHeight,null(),null(),null(),null());
			HX_STACK_LINE(405)
			this->region->width = (::Std_obj::_int((Float(this->cachedGraphics->bitmap->get_width()) / Float(this->_tileWidth))) * this->_tileWidth);
			HX_STACK_LINE(406)
			this->region->height = (::Std_obj::_int((Float(this->cachedGraphics->bitmap->get_height()) / Float(this->_tileHeight))) * this->_tileHeight);
		}
		else{
			HX_STACK_LINE(410)
			::flixel::util::loaders::TextureRegion spriteRegion = TileGraphic;		HX_STACK_VAR(spriteRegion,"spriteRegion");
			HX_STACK_LINE(411)
			this->region = spriteRegion->region->clone();
			HX_STACK_LINE(412)
			if (((this->region->tileWidth > (int)0))){
				HX_STACK_LINE(414)
				this->_tileWidth = this->region->tileWidth;
			}
			else{
				HX_STACK_LINE(418)
				this->region->tileWidth = this->_tileWidth;
			}
			HX_STACK_LINE(421)
			if (((this->region->tileHeight > (int)0))){
				HX_STACK_LINE(423)
				this->_tileHeight = this->region->tileWidth;
			}
			else{
				HX_STACK_LINE(427)
				this->region->tileHeight = this->_tileHeight;
			}
		}
		HX_STACK_LINE(432)
		this->_tileObjects = Array_obj< ::Dynamic >::__new();
		HX_STACK_LINE(434)
		int length = this->region->get_numTiles();		HX_STACK_VAR(length,"length");
		HX_STACK_LINE(435)
		hx::AddEq(length,this->_startingIndex);
		HX_STACK_LINE(437)
		{
			HX_STACK_LINE(437)
			int _g = (int)0;		HX_STACK_VAR(_g,"_g");
			HX_STACK_LINE(437)
			while(((_g < length))){
				HX_STACK_LINE(437)
				int i1 = (_g)++;		HX_STACK_VAR(i1,"i1");
				HX_STACK_LINE(439)
				this->_tileObjects[i1] = ::flixel::tile::FlxTile_obj::__new(hx::ObjectPtr<OBJ_>(this),i1,this->_tileWidth,this->_tileHeight,(i1 >= DrawIndex),(  (((i1 >= CollideIndex))) ? int(this->allowCollisions) : int((int)0) ));
			}
		}
		HX_STACK_LINE(449)
		this->_scaledTileWidth = (this->_tileWidth * this->scaleX);
		HX_STACK_LINE(450)
		this->_scaledTileHeight = (this->_tileHeight * this->scaleY);
		HX_STACK_LINE(453)
		this->set_width((this->widthInTiles * this->_scaledTileWidth));
		HX_STACK_LINE(454)
		this->set_height((this->heightInTiles * this->_scaledTileHeight));
		HX_STACK_LINE(470)
		this->updateFrameData();
		HX_STACK_LINE(473)
		return hx::ObjectPtr<OBJ_>(this);
	}
}


HX_DEFINE_DYNAMIC_FUNC8(FlxTilemap_obj,loadMap,return )

Void FlxTilemap_obj::setCustomTileMappings( Array< int > mappings,Array< int > randomIndices,Array< ::Dynamic > randomChoices,Dynamic randomLambda){
{
		HX_STACK_FRAME("flixel.tile.FlxTilemap","setCustomTileMappings",0x2422e242,"flixel.tile.FlxTilemap.setCustomTileMappings","flixel/tile/FlxTilemap.hx",486,0x448feb74)
		HX_STACK_THIS(this)
		HX_STACK_ARG(mappings,"mappings")
		HX_STACK_ARG(randomIndices,"randomIndices")
		HX_STACK_ARG(randomChoices,"randomChoices")
		HX_STACK_ARG(randomLambda,"randomLambda")
		HX_STACK_LINE(487)
		this->customTileRemap = mappings;
		HX_STACK_LINE(488)
		this->_randomIndices = randomIndices;
		HX_STACK_LINE(489)
		this->_randomChoices = randomChoices;
		HX_STACK_LINE(490)
		this->_randomLambda = randomLambda;
		HX_STACK_LINE(493)
		if (((bool((this->_randomIndices != null())) && bool(((bool((this->_randomChoices == null())) || bool((this->_randomChoices->length == (int)0)))))))){
			HX_STACK_LINE(495)
			HX_STACK_DO_THROW(HX_CSTRING("You must provide valid 'randomChoices' if you wish to randomize tilemap indicies, please read documentation of 'setCustomTileMappings' function."));
		}
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC4(FlxTilemap_obj,setCustomTileMappings,(void))

Void FlxTilemap_obj::update( ){
{
		HX_STACK_FRAME("flixel.tile.FlxTilemap","update",0x741860cd,"flixel.tile.FlxTilemap.update","flixel/tile/FlxTilemap.hx",505,0x448feb74)
		HX_STACK_THIS(this)
		HX_STACK_LINE(506)
		if (((this->_lastVisualDebug != ::flixel::FlxG_obj::debugger->drawDebug))){
			HX_STACK_LINE(508)
			this->_lastVisualDebug = ::flixel::FlxG_obj::debugger->drawDebug;
			HX_STACK_LINE(509)
			this->setDirty(null());
		}
		HX_STACK_LINE(512)
		this->super::update();
	}
return null();
}


Void FlxTilemap_obj::drawDebugOnCamera( ::flixel::FlxCamera Camera){
{
		HX_STACK_FRAME("flixel.tile.FlxTilemap","drawDebugOnCamera",0x0d929baf,"flixel.tile.FlxTilemap.drawDebugOnCamera","flixel/tile/FlxTilemap.hx",521,0x448feb74)
		HX_STACK_THIS(this)
		HX_STACK_ARG(Camera,"Camera")
		HX_STACK_LINE(522)
		::flixel::tile::FlxTilemapBuffer buffer = null();		HX_STACK_VAR(buffer,"buffer");
		HX_STACK_LINE(523)
		int l = ::flixel::FlxG_obj::cameras->list->length;		HX_STACK_VAR(l,"l");
		HX_STACK_LINE(525)
		{
			HX_STACK_LINE(525)
			int _g = (int)0;		HX_STACK_VAR(_g,"_g");
			HX_STACK_LINE(525)
			while(((_g < l))){
				HX_STACK_LINE(525)
				int i = (_g)++;		HX_STACK_VAR(i,"i");
				HX_STACK_LINE(527)
				if (((::flixel::FlxG_obj::cameras->list->__get(i).StaticCast< ::flixel::FlxCamera >() == Camera))){
					HX_STACK_LINE(529)
					buffer = this->_buffers->__get(i).StaticCast< ::flixel::tile::FlxTilemapBuffer >();
					HX_STACK_LINE(530)
					break;
				}
			}
		}
		HX_STACK_LINE(534)
		if (((buffer == null()))){
			HX_STACK_LINE(534)
			return null();
		}
		HX_STACK_LINE(538)
		this->_helperPoint->x = ((Float(::Math_obj::floor((((this->x - (::Math_obj::floor(Camera->scroll->x) * this->scrollFactor->x))) * (int)5))) / Float((int)5)) + 0.1);
		HX_STACK_LINE(539)
		this->_helperPoint->y = ((Float(::Math_obj::floor((((this->y - (::Math_obj::floor(Camera->scroll->y) * this->scrollFactor->y))) * (int)5))) / Float((int)5)) + 0.1);
		HX_STACK_LINE(546)
		int tileID;		HX_STACK_VAR(tileID,"tileID");
		HX_STACK_LINE(547)
		int debugColor;		HX_STACK_VAR(debugColor,"debugColor");
		HX_STACK_LINE(548)
		Float drawX;		HX_STACK_VAR(drawX,"drawX");
		HX_STACK_LINE(549)
		Float drawY;		HX_STACK_VAR(drawY,"drawY");
		HX_STACK_LINE(553)
		this->_point->set_x(((Camera->scroll->x * this->scrollFactor->x) - this->x));
		HX_STACK_LINE(554)
		this->_point->set_y(((Camera->scroll->y * this->scrollFactor->y) - this->y));
		HX_STACK_LINE(555)
		int screenXInTiles = ::Math_obj::floor((Float(this->_point->x) / Float(this->_scaledTileWidth)));		HX_STACK_VAR(screenXInTiles,"screenXInTiles");
		HX_STACK_LINE(556)
		int screenYInTiles = ::Math_obj::floor((Float(this->_point->y) / Float(this->_scaledTileHeight)));		HX_STACK_VAR(screenYInTiles,"screenYInTiles");
		HX_STACK_LINE(557)
		int screenRows = buffer->rows;		HX_STACK_VAR(screenRows,"screenRows");
		HX_STACK_LINE(558)
		int screenColumns = buffer->columns;		HX_STACK_VAR(screenColumns,"screenColumns");
		HX_STACK_LINE(561)
		if (((screenXInTiles < (int)0))){
			HX_STACK_LINE(563)
			screenXInTiles = (int)0;
		}
		HX_STACK_LINE(565)
		if (((screenXInTiles > (this->widthInTiles - screenColumns)))){
			HX_STACK_LINE(567)
			screenXInTiles = (this->widthInTiles - screenColumns);
		}
		HX_STACK_LINE(569)
		if (((screenYInTiles < (int)0))){
			HX_STACK_LINE(571)
			screenYInTiles = (int)0;
		}
		HX_STACK_LINE(573)
		if (((screenYInTiles > (this->heightInTiles - screenRows)))){
			HX_STACK_LINE(575)
			screenYInTiles = (this->heightInTiles - screenRows);
		}
		HX_STACK_LINE(578)
		int rowIndex = ((screenYInTiles * this->widthInTiles) + screenXInTiles);		HX_STACK_VAR(rowIndex,"rowIndex");
		HX_STACK_LINE(579)
		this->_flashPoint->y = (int)0;
		HX_STACK_LINE(580)
		int row = (int)0;		HX_STACK_VAR(row,"row");
		HX_STACK_LINE(581)
		int column;		HX_STACK_VAR(column,"column");
		HX_STACK_LINE(582)
		int columnIndex;		HX_STACK_VAR(columnIndex,"columnIndex");
		HX_STACK_LINE(583)
		::flixel::tile::FlxTile tile;		HX_STACK_VAR(tile,"tile");
		HX_STACK_LINE(584)
		::flash::display::BitmapData debugTile;		HX_STACK_VAR(debugTile,"debugTile");
		HX_STACK_LINE(586)
		while(((row < screenRows))){
			HX_STACK_LINE(588)
			columnIndex = rowIndex;
			HX_STACK_LINE(589)
			column = (int)0;
			HX_STACK_LINE(590)
			this->_flashPoint->x = (int)0;
			HX_STACK_LINE(592)
			while(((column < screenColumns))){
				HX_STACK_LINE(594)
				tileID = this->_rectIDs->__get(columnIndex);
				HX_STACK_LINE(596)
				if (((tileID != (int)-1))){
					HX_STACK_LINE(598)
					drawX = (this->_helperPoint->x + (hx::Mod(columnIndex,this->widthInTiles) * this->_scaledTileWidth));
					HX_STACK_LINE(599)
					drawY = (this->_helperPoint->y + (::Math_obj::floor((Float(columnIndex) / Float(this->widthInTiles))) * this->_scaledTileHeight));
					HX_STACK_LINE(601)
					tile = this->_tileObjects->__get(this->_data->__get(columnIndex)).StaticCast< ::flixel::tile::FlxTile >();
					HX_STACK_LINE(603)
					if (((tile != null()))){
						HX_STACK_LINE(605)
						if (((tile->allowCollisions <= (int)0))){
							HX_STACK_LINE(607)
							debugColor = (int)-16776961;
						}
						else{
							HX_STACK_LINE(609)
							if (((tile->allowCollisions != (int)4369))){
								HX_STACK_LINE(611)
								debugColor = (int)-16181;
							}
							else{
								HX_STACK_LINE(615)
								debugColor = (int)-16744448;
							}
						}
						HX_STACK_LINE(619)
						::flash::display::Graphics gfx = Camera->debugLayer->get_graphics();		HX_STACK_VAR(gfx,"gfx");
						HX_STACK_LINE(620)
						gfx->lineStyle((int)1,debugColor,0.5,null(),null(),null(),null(),null());
						HX_STACK_LINE(621)
						gfx->drawRect(drawX,drawY,this->_scaledTileWidth,this->_scaledTileHeight);
					}
				}
				HX_STACK_LINE(625)
				hx::AddEq(this->_flashPoint->x,this->_scaledTileWidth);
				HX_STACK_LINE(626)
				(column)++;
				HX_STACK_LINE(627)
				(columnIndex)++;
			}
			HX_STACK_LINE(630)
			hx::AddEq(rowIndex,this->widthInTiles);
			HX_STACK_LINE(631)
			hx::AddEq(this->_flashPoint->y,this->_scaledTileHeight);
			HX_STACK_LINE(632)
			(row)++;
		}
	}
return null();
}


Void FlxTilemap_obj::draw( ){
{
		HX_STACK_FRAME("flixel.tile.FlxTilemap","draw",0x7d740dc8,"flixel.tile.FlxTilemap.draw","flixel/tile/FlxTilemap.hx",642,0x448feb74)
		HX_STACK_THIS(this)
		HX_STACK_LINE(643)
		if (((this->cameras == null()))){
			HX_STACK_LINE(645)
			this->cameras = ::flixel::FlxG_obj::cameras->list;
		}
		HX_STACK_LINE(648)
		::flixel::FlxCamera camera;		HX_STACK_VAR(camera,"camera");
		HX_STACK_LINE(649)
		::flixel::tile::FlxTilemapBuffer buffer;		HX_STACK_VAR(buffer,"buffer");
		HX_STACK_LINE(650)
		int i = (int)0;		HX_STACK_VAR(i,"i");
		HX_STACK_LINE(651)
		int l = this->cameras->length;		HX_STACK_VAR(l,"l");
		HX_STACK_LINE(653)
		while(((i < l))){
			HX_STACK_LINE(655)
			camera = this->cameras->__get(i).StaticCast< ::flixel::FlxCamera >();
			HX_STACK_LINE(657)
			if (((bool(!(camera->visible)) || bool(!(camera->exists))))){
				HX_STACK_LINE(659)
				continue;
			}
			HX_STACK_LINE(662)
			if (((this->_buffers->__get(i).StaticCast< ::flixel::tile::FlxTilemapBuffer >() == null()))){
				HX_STACK_LINE(664)
				this->_buffers[i] = ::flixel::tile::FlxTilemapBuffer_obj::__new(this->_tileWidth,this->_tileHeight,this->widthInTiles,this->heightInTiles,camera,this->scaleX,this->scaleY);
				HX_STACK_LINE(665)
				this->_buffers->__get(i).StaticCast< ::flixel::tile::FlxTilemapBuffer >()->forceComplexRender = this->forceComplexRender;
			}
			HX_STACK_LINE(668)
			buffer = this->_buffers->__get((i)++).StaticCast< ::flixel::tile::FlxTilemapBuffer >();
			HX_STACK_LINE(669)
			buffer->dirty = true;
			HX_STACK_LINE(690)
			this->drawTilemap(buffer,camera);
			HX_STACK_LINE(694)
			(::flixel::FlxBasic_obj::_VISIBLECOUNT)++;
		}
	}
return null();
}


Array< int > FlxTilemap_obj::getData( hx::Null< bool >  __o_Simple){
bool Simple = __o_Simple.Default(false);
	HX_STACK_FRAME("flixel.tile.FlxTilemap","getData",0x9852969c,"flixel.tile.FlxTilemap.getData","flixel/tile/FlxTilemap.hx",706,0x448feb74)
	HX_STACK_THIS(this)
	HX_STACK_ARG(Simple,"Simple")
{
		HX_STACK_LINE(707)
		if ((!(Simple))){
			HX_STACK_LINE(709)
			return this->_data;
		}
		HX_STACK_LINE(712)
		int i = (int)0;		HX_STACK_VAR(i,"i");
		HX_STACK_LINE(713)
		int l = this->_data->length;		HX_STACK_VAR(l,"l");
		HX_STACK_LINE(714)
		Array< int > data = Array_obj< int >::__new();		HX_STACK_VAR(data,"data");
		HX_STACK_LINE(715)
		::flixel::util::FlxArrayUtil_obj::setLength_Int(data,l);
		HX_STACK_LINE(717)
		while(((i < l))){
			HX_STACK_LINE(719)
			if (((this->_tileObjects->__get(this->_data->__get(i)).StaticCast< ::flixel::tile::FlxTile >()->allowCollisions > (int)0))){
				HX_STACK_LINE(719)
				data[i] = (int)1;
			}
			else{
				HX_STACK_LINE(719)
				data[i] = (int)0;
			}
			HX_STACK_LINE(720)
			(i)++;
		}
		HX_STACK_LINE(723)
		return data;
	}
}


HX_DEFINE_DYNAMIC_FUNC1(FlxTilemap_obj,getData,return )

Void FlxTilemap_obj::setDirty( hx::Null< bool >  __o_Dirty){
bool Dirty = __o_Dirty.Default(true);
	HX_STACK_FRAME("flixel.tile.FlxTilemap","setDirty",0x6396ccd4,"flixel.tile.FlxTilemap.setDirty","flixel/tile/FlxTilemap.hx",733,0x448feb74)
	HX_STACK_THIS(this)
	HX_STACK_ARG(Dirty,"Dirty")
{
		HX_STACK_LINE(734)
		int i = (int)0;		HX_STACK_VAR(i,"i");
		HX_STACK_LINE(735)
		int l = this->_buffers->length;		HX_STACK_VAR(l,"l");
		HX_STACK_LINE(737)
		while(((i < l))){
			HX_STACK_LINE(739)
			this->_buffers->__get((i)++).StaticCast< ::flixel::tile::FlxTilemapBuffer >()->dirty = Dirty;
		}
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC1(FlxTilemap_obj,setDirty,(void))

Array< ::Dynamic > FlxTilemap_obj::findPath( ::flixel::util::FlxPoint Start,::flixel::util::FlxPoint End,hx::Null< bool >  __o_Simplify,hx::Null< bool >  __o_RaySimplify,hx::Null< bool >  __o_WideDiagonal){
bool Simplify = __o_Simplify.Default(true);
bool RaySimplify = __o_RaySimplify.Default(false);
bool WideDiagonal = __o_WideDiagonal.Default(true);
	HX_STACK_FRAME("flixel.tile.FlxTilemap","findPath",0x18780642,"flixel.tile.FlxTilemap.findPath","flixel/tile/FlxTilemap.hx",755,0x448feb74)
	HX_STACK_THIS(this)
	HX_STACK_ARG(Start,"Start")
	HX_STACK_ARG(End,"End")
	HX_STACK_ARG(Simplify,"Simplify")
	HX_STACK_ARG(RaySimplify,"RaySimplify")
	HX_STACK_ARG(WideDiagonal,"WideDiagonal")
{
		HX_STACK_LINE(757)
		int _g = (::Std_obj::_int((Float(((Start->y - this->y))) / Float(this->_scaledTileHeight))) * this->widthInTiles);		HX_STACK_VAR(_g,"_g");
		HX_STACK_LINE(757)
		int startIndex = (_g + ::Std_obj::_int((Float(((Start->x - this->x))) / Float(this->_scaledTileWidth))));		HX_STACK_VAR(startIndex,"startIndex");
		HX_STACK_LINE(758)
		int _g1 = (::Std_obj::_int((Float(((End->y - this->y))) / Float(this->_scaledTileHeight))) * this->widthInTiles);		HX_STACK_VAR(_g1,"_g1");
		HX_STACK_LINE(758)
		int endIndex = (_g1 + ::Std_obj::_int((Float(((End->x - this->x))) / Float(this->_scaledTileWidth))));		HX_STACK_VAR(endIndex,"endIndex");
		HX_STACK_LINE(761)
		if (((bool((this->_tileObjects->__get(this->_data->__get(startIndex)).StaticCast< ::flixel::tile::FlxTile >()->allowCollisions > (int)0)) || bool((this->_tileObjects->__get(this->_data->__get(endIndex)).StaticCast< ::flixel::tile::FlxTile >()->allowCollisions > (int)0))))){
			HX_STACK_LINE(763)
			return null();
		}
		HX_STACK_LINE(767)
		Array< int > distances = this->computePathDistance(startIndex,endIndex,WideDiagonal,null());		HX_STACK_VAR(distances,"distances");
		HX_STACK_LINE(769)
		if (((distances == null()))){
			HX_STACK_LINE(771)
			return null();
		}
		HX_STACK_LINE(775)
		Array< ::Dynamic > points = Array_obj< ::Dynamic >::__new();		HX_STACK_VAR(points,"points");
		HX_STACK_LINE(776)
		this->walkPath(distances,endIndex,points);
		HX_STACK_LINE(779)
		::flixel::util::FlxPoint node;		HX_STACK_VAR(node,"node");
		HX_STACK_LINE(780)
		node = points->__get((points->length - (int)1)).StaticCast< ::flixel::util::FlxPoint >();
		HX_STACK_LINE(781)
		node->set_x(Start->x);
		HX_STACK_LINE(782)
		node->set_y(Start->y);
		HX_STACK_LINE(783)
		node = points->__get((int)0).StaticCast< ::flixel::util::FlxPoint >();
		HX_STACK_LINE(784)
		node->set_x(End->x);
		HX_STACK_LINE(785)
		node->set_y(End->y);
		HX_STACK_LINE(788)
		if ((Simplify)){
			HX_STACK_LINE(790)
			this->simplifyPath(points);
		}
		HX_STACK_LINE(792)
		if ((RaySimplify)){
			HX_STACK_LINE(794)
			this->raySimplifyPath(points);
		}
		HX_STACK_LINE(798)
		Array< ::Dynamic > path = Array_obj< ::Dynamic >::__new();		HX_STACK_VAR(path,"path");
		HX_STACK_LINE(799)
		int i = (points->length - (int)1);		HX_STACK_VAR(i,"i");
		HX_STACK_LINE(801)
		while(((i >= (int)0))){
			HX_STACK_LINE(803)
			node = points->__get((i)--).StaticCast< ::flixel::util::FlxPoint >();
			HX_STACK_LINE(805)
			if (((node != null()))){
				HX_STACK_LINE(807)
				path->push(node);
			}
		}
		HX_STACK_LINE(811)
		return path;
	}
}


HX_DEFINE_DYNAMIC_FUNC5(FlxTilemap_obj,findPath,return )

bool FlxTilemap_obj::overlaps( ::flixel::FlxBasic ObjectOrGroup,hx::Null< bool >  __o_InScreenSpace,::flixel::FlxCamera Camera){
bool InScreenSpace = __o_InScreenSpace.Default(false);
	HX_STACK_FRAME("flixel.tile.FlxTilemap","overlaps",0xc0bce6d0,"flixel.tile.FlxTilemap.overlaps","flixel/tile/FlxTilemap.hx",825,0x448feb74)
	HX_STACK_THIS(this)
	HX_STACK_ARG(ObjectOrGroup,"ObjectOrGroup")
	HX_STACK_ARG(InScreenSpace,"InScreenSpace")
	HX_STACK_ARG(Camera,"Camera")
{
		HX_STACK_LINE(826)
		::flixel::system::FlxCollisionType objType = ObjectOrGroup->collisionType;		HX_STACK_VAR(objType,"objType");
		HX_STACK_LINE(827)
		if (((objType == ::flixel::system::FlxCollisionType_obj::SPRITEGROUP))){
			HX_STACK_LINE(829)
			ObjectOrGroup = ::Reflect_obj::field(ObjectOrGroup,HX_CSTRING("group"));
			HX_STACK_LINE(830)
			objType = ::flixel::system::FlxCollisionType_obj::GROUP;
		}
		HX_STACK_LINE(833)
		if (((objType == ::flixel::system::FlxCollisionType_obj::GROUP))){
			HX_STACK_LINE(835)
			bool results = false;		HX_STACK_VAR(results,"results");
			HX_STACK_LINE(836)
			::flixel::FlxBasic basic;		HX_STACK_VAR(basic,"basic");
			HX_STACK_LINE(837)
			int i = (int)0;		HX_STACK_VAR(i,"i");
			HX_STACK_LINE(838)
			::flixel::group::FlxTypedGroup grp = ObjectOrGroup;		HX_STACK_VAR(grp,"grp");
			HX_STACK_LINE(839)
			Array< ::Dynamic > members = grp->get_members();		HX_STACK_VAR(members,"members");
			HX_STACK_LINE(841)
			while(((i < grp->length))){
				HX_STACK_LINE(843)
				basic = members->__get((i)++).StaticCast< ::flixel::FlxBasic >();
				HX_STACK_LINE(845)
				if (((bool((basic != null())) && bool(basic->exists)))){
					HX_STACK_LINE(847)
					objType = basic->collisionType;
					HX_STACK_LINE(848)
					if (((bool((objType == ::flixel::system::FlxCollisionType_obj::OBJECT)) || bool((objType == ::flixel::system::FlxCollisionType_obj::TILEMAP))))){
						HX_STACK_LINE(850)
						if ((this->overlapsWithCallback(hx::TCast< flixel::FlxObject >::cast(basic),null(),null(),null()))){
							HX_STACK_LINE(852)
							results = true;
						}
					}
					else{
						HX_STACK_LINE(857)
						if ((this->overlaps(basic,InScreenSpace,Camera))){
							HX_STACK_LINE(859)
							results = true;
						}
					}
				}
			}
			HX_STACK_LINE(865)
			return results;
		}
		else{
			HX_STACK_LINE(867)
			if (((bool((objType == ::flixel::system::FlxCollisionType_obj::OBJECT)) || bool((objType == ::flixel::system::FlxCollisionType_obj::TILEMAP))))){
				HX_STACK_LINE(869)
				return this->overlapsWithCallback(hx::TCast< flixel::FlxObject >::cast(ObjectOrGroup),null(),null(),null());
			}
		}
		HX_STACK_LINE(872)
		return false;
	}
}


bool FlxTilemap_obj::overlapsAt( Float X,Float Y,::flixel::FlxBasic ObjectOrGroup,hx::Null< bool >  __o_InScreenSpace,::flixel::FlxCamera Camera){
bool InScreenSpace = __o_InScreenSpace.Default(false);
	HX_STACK_FRAME("flixel.tile.FlxTilemap","overlapsAt",0x16e073e3,"flixel.tile.FlxTilemap.overlapsAt","flixel/tile/FlxTilemap.hx",888,0x448feb74)
	HX_STACK_THIS(this)
	HX_STACK_ARG(X,"X")
	HX_STACK_ARG(Y,"Y")
	HX_STACK_ARG(ObjectOrGroup,"ObjectOrGroup")
	HX_STACK_ARG(InScreenSpace,"InScreenSpace")
	HX_STACK_ARG(Camera,"Camera")
{
		HX_STACK_LINE(889)
		::flixel::system::FlxCollisionType objType = ObjectOrGroup->collisionType;		HX_STACK_VAR(objType,"objType");
		HX_STACK_LINE(890)
		if (((ObjectOrGroup->collisionType == ::flixel::system::FlxCollisionType_obj::SPRITEGROUP))){
			HX_STACK_LINE(892)
			ObjectOrGroup = ::Reflect_obj::field(ObjectOrGroup,HX_CSTRING("group"));
			HX_STACK_LINE(893)
			objType = ::flixel::system::FlxCollisionType_obj::GROUP;
		}
		HX_STACK_LINE(896)
		if (((objType == ::flixel::system::FlxCollisionType_obj::GROUP))){
			HX_STACK_LINE(898)
			bool results = false;		HX_STACK_VAR(results,"results");
			HX_STACK_LINE(899)
			::flixel::FlxBasic basic;		HX_STACK_VAR(basic,"basic");
			HX_STACK_LINE(900)
			int i = (int)0;		HX_STACK_VAR(i,"i");
			HX_STACK_LINE(901)
			::flixel::group::FlxTypedGroup grp = ObjectOrGroup;		HX_STACK_VAR(grp,"grp");
			HX_STACK_LINE(902)
			Array< ::Dynamic > members = grp->get_members();		HX_STACK_VAR(members,"members");
			HX_STACK_LINE(904)
			while(((i < grp->length))){
				HX_STACK_LINE(906)
				basic = members->__get((i)++).StaticCast< ::flixel::FlxBasic >();
				HX_STACK_LINE(908)
				if (((bool((basic != null())) && bool(basic->exists)))){
					HX_STACK_LINE(910)
					objType = basic->collisionType;
					HX_STACK_LINE(911)
					if (((bool((objType == ::flixel::system::FlxCollisionType_obj::OBJECT)) || bool((objType == ::flixel::system::FlxCollisionType_obj::TILEMAP))))){
						HX_STACK_LINE(913)
						this->_point->set_x(X);
						HX_STACK_LINE(914)
						this->_point->set_y(Y);
						HX_STACK_LINE(916)
						if ((this->overlapsWithCallback(hx::TCast< flixel::FlxObject >::cast(basic),null(),false,this->_point))){
							HX_STACK_LINE(918)
							results = true;
						}
					}
					else{
						HX_STACK_LINE(923)
						if ((this->overlapsAt(X,Y,basic,InScreenSpace,Camera))){
							HX_STACK_LINE(925)
							results = true;
						}
					}
				}
			}
			HX_STACK_LINE(931)
			return results;
		}
		else{
			HX_STACK_LINE(933)
			if (((bool((objType == ::flixel::system::FlxCollisionType_obj::OBJECT)) || bool((objType == ::flixel::system::FlxCollisionType_obj::TILEMAP))))){
				HX_STACK_LINE(935)
				this->_point->set_x(X);
				HX_STACK_LINE(936)
				this->_point->set_y(Y);
				HX_STACK_LINE(938)
				return this->overlapsWithCallback(hx::TCast< flixel::FlxObject >::cast(ObjectOrGroup),null(),false,this->_point);
			}
		}
		HX_STACK_LINE(941)
		return false;
	}
}


bool FlxTilemap_obj::overlapsWithCallback( ::flixel::FlxObject Object,Dynamic Callback,hx::Null< bool >  __o_FlipCallbackParams,::flixel::util::FlxPoint Position){
bool FlipCallbackParams = __o_FlipCallbackParams.Default(false);
	HX_STACK_FRAME("flixel.tile.FlxTilemap","overlapsWithCallback",0xe7b56cdb,"flixel.tile.FlxTilemap.overlapsWithCallback","flixel/tile/FlxTilemap.hx",956,0x448feb74)
	HX_STACK_THIS(this)
	HX_STACK_ARG(Object,"Object")
	HX_STACK_ARG(Callback,"Callback")
	HX_STACK_ARG(FlipCallbackParams,"FlipCallbackParams")
	HX_STACK_ARG(Position,"Position")
{
		HX_STACK_LINE(957)
		bool results = false;		HX_STACK_VAR(results,"results");
		HX_STACK_LINE(959)
		Float X = this->x;		HX_STACK_VAR(X,"X");
		HX_STACK_LINE(960)
		Float Y = this->y;		HX_STACK_VAR(Y,"Y");
		HX_STACK_LINE(962)
		if (((Position != null()))){
			HX_STACK_LINE(964)
			X = Position->x;
			HX_STACK_LINE(965)
			Y = Position->y;
		}
		HX_STACK_LINE(969)
		int selectionX = ::Math_obj::floor((Float(((Object->x - X))) / Float(this->_scaledTileWidth)));		HX_STACK_VAR(selectionX,"selectionX");
		HX_STACK_LINE(970)
		int selectionY = ::Math_obj::floor((Float(((Object->y - Y))) / Float(this->_scaledTileHeight)));		HX_STACK_VAR(selectionY,"selectionY");
		HX_STACK_LINE(971)
		int selectionWidth = ((selectionX + ::Math_obj::ceil((Float(Object->get_width()) / Float(this->_scaledTileWidth)))) + (int)1);		HX_STACK_VAR(selectionWidth,"selectionWidth");
		HX_STACK_LINE(972)
		int selectionHeight = ((selectionY + ::Math_obj::ceil((Float(Object->get_height()) / Float(this->_scaledTileHeight)))) + (int)1);		HX_STACK_VAR(selectionHeight,"selectionHeight");
		struct _Function_1_1{
			inline static Float Block( ::flixel::tile::FlxTilemap_obj *__this,int &selectionWidth){
				HX_STACK_FRAME("*","closure",0x5bdab937,"*.closure","flixel/tile/FlxTilemap.hx",975,0x448feb74)
				{
					HX_STACK_LINE(975)
					Float Max = __this->widthInTiles;		HX_STACK_VAR(Max,"Max");
					HX_STACK_LINE(975)
					Float lowerBound;		HX_STACK_VAR(lowerBound,"lowerBound");
					HX_STACK_LINE(975)
					if (((selectionWidth < (int)0))){
						HX_STACK_LINE(975)
						lowerBound = (int)0;
					}
					else{
						HX_STACK_LINE(975)
						lowerBound = selectionWidth;
					}
					HX_STACK_LINE(975)
					return (  (((lowerBound > Max))) ? Float(Max) : Float(lowerBound) );
				}
				return null();
			}
		};
		HX_STACK_LINE(975)
		selectionWidth = ::Std_obj::_int(_Function_1_1::Block(this,selectionWidth));
		struct _Function_1_2{
			inline static Float Block( ::flixel::tile::FlxTilemap_obj *__this,int &selectionHeight){
				HX_STACK_FRAME("*","closure",0x5bdab937,"*.closure","flixel/tile/FlxTilemap.hx",976,0x448feb74)
				{
					HX_STACK_LINE(976)
					Float Max = __this->heightInTiles;		HX_STACK_VAR(Max,"Max");
					HX_STACK_LINE(976)
					Float lowerBound;		HX_STACK_VAR(lowerBound,"lowerBound");
					HX_STACK_LINE(976)
					if (((selectionHeight < (int)0))){
						HX_STACK_LINE(976)
						lowerBound = (int)0;
					}
					else{
						HX_STACK_LINE(976)
						lowerBound = selectionHeight;
					}
					HX_STACK_LINE(976)
					return (  (((lowerBound > Max))) ? Float(Max) : Float(lowerBound) );
				}
				return null();
			}
		};
		HX_STACK_LINE(976)
		selectionHeight = ::Std_obj::_int(_Function_1_2::Block(this,selectionHeight));
		HX_STACK_LINE(979)
		int rowStart = (selectionY * this->widthInTiles);		HX_STACK_VAR(rowStart,"rowStart");
		HX_STACK_LINE(980)
		int row = selectionY;		HX_STACK_VAR(row,"row");
		HX_STACK_LINE(981)
		int column;		HX_STACK_VAR(column,"column");
		HX_STACK_LINE(982)
		::flixel::tile::FlxTile tile;		HX_STACK_VAR(tile,"tile");
		HX_STACK_LINE(983)
		bool overlapFound;		HX_STACK_VAR(overlapFound,"overlapFound");
		HX_STACK_LINE(984)
		Float deltaX = (X - this->last->x);		HX_STACK_VAR(deltaX,"deltaX");
		HX_STACK_LINE(985)
		Float deltaY = (Y - this->last->y);		HX_STACK_VAR(deltaY,"deltaY");
		HX_STACK_LINE(987)
		while(((row < selectionHeight))){
			HX_STACK_LINE(989)
			column = selectionX;
			HX_STACK_LINE(991)
			while(((column < selectionWidth))){
				HX_STACK_LINE(993)
				int dataIndex = this->_data->__get((rowStart + column));		HX_STACK_VAR(dataIndex,"dataIndex");
				HX_STACK_LINE(995)
				if (((dataIndex < (int)0))){
					HX_STACK_LINE(997)
					(column)++;
					HX_STACK_LINE(998)
					continue;
				}
				HX_STACK_LINE(1001)
				tile = this->_tileObjects->__get(dataIndex).StaticCast< ::flixel::tile::FlxTile >();
				HX_STACK_LINE(1002)
				tile->set_width(this->_scaledTileWidth);
				HX_STACK_LINE(1003)
				tile->set_height(this->_scaledTileHeight);
				HX_STACK_LINE(1004)
				tile->set_x((X + (column * tile->get_width())));
				HX_STACK_LINE(1005)
				tile->set_y((Y + (row * tile->get_height())));
				HX_STACK_LINE(1006)
				tile->last->set_x((tile->x - deltaX));
				HX_STACK_LINE(1007)
				tile->last->set_y((tile->y - deltaY));
				HX_STACK_LINE(1009)
				if (((  (((  ((((Object->x + Object->get_width()) > tile->x))) ? bool((Object->x < (tile->x + tile->get_width()))) : bool(false) ))) ? bool(((Object->y + Object->get_height()) > tile->y)) : bool(false) ))){
					HX_STACK_LINE(1009)
					overlapFound = (Object->y < (tile->y + tile->get_height()));
				}
				else{
					HX_STACK_LINE(1009)
					overlapFound = false;
				}
				HX_STACK_LINE(1012)
				if (((tile->allowCollisions != (int)0))){
					HX_STACK_LINE(1014)
					if (((Callback != null()))){
						HX_STACK_LINE(1016)
						if ((FlipCallbackParams)){
							HX_STACK_LINE(1018)
							overlapFound = Callback(Object,tile).Cast< bool >();
						}
						else{
							HX_STACK_LINE(1022)
							overlapFound = Callback(tile,Object).Cast< bool >();
						}
					}
				}
				HX_STACK_LINE(1027)
				if ((overlapFound)){
					struct _Function_4_1{
						inline static bool Block( ::flixel::tile::FlxTile &tile,::flixel::FlxObject &Object){
							HX_STACK_FRAME("*","closure",0x5bdab937,"*.closure","flixel/tile/FlxTilemap.hx",1029,0x448feb74)
							{
								HX_STACK_LINE(1029)
								return (  ((!(((tile->filter == null()))))) ? bool(::Std_obj::is(Object,tile->filter)) : bool(true) );
							}
							return null();
						}
					};
					HX_STACK_LINE(1029)
					if (((  (((tile->callbackFunction != null()))) ? bool(_Function_4_1::Block(tile,Object)) : bool(false) ))){
						HX_STACK_LINE(1031)
						tile->mapIndex = (rowStart + column);
						HX_STACK_LINE(1032)
						tile->callbackFunction(tile,Object);
					}
					HX_STACK_LINE(1035)
					if (((tile->allowCollisions != (int)0))){
						HX_STACK_LINE(1037)
						results = true;
					}
				}
				HX_STACK_LINE(1041)
				(column)++;
			}
			HX_STACK_LINE(1044)
			hx::AddEq(rowStart,this->widthInTiles);
			HX_STACK_LINE(1045)
			(row)++;
		}
		HX_STACK_LINE(1048)
		return results;
	}
}


HX_DEFINE_DYNAMIC_FUNC4(FlxTilemap_obj,overlapsWithCallback,return )

bool FlxTilemap_obj::overlapsPoint( ::flixel::util::FlxPoint WorldPoint,hx::Null< bool >  __o_InScreenSpace,::flixel::FlxCamera Camera){
bool InScreenSpace = __o_InScreenSpace.Default(false);
	HX_STACK_FRAME("flixel.tile.FlxTilemap","overlapsPoint",0xaeb98b60,"flixel.tile.FlxTilemap.overlapsPoint","flixel/tile/FlxTilemap.hx",1060,0x448feb74)
	HX_STACK_THIS(this)
	HX_STACK_ARG(WorldPoint,"WorldPoint")
	HX_STACK_ARG(InScreenSpace,"InScreenSpace")
	HX_STACK_ARG(Camera,"Camera")
{
		HX_STACK_LINE(1061)
		if ((!(InScreenSpace))){
			HX_STACK_LINE(1063)
			return (this->_tileObjects->__get(this->_data->__get(::Math_obj::floor(((::Math_obj::floor((Float(((WorldPoint->y - this->y))) / Float(this->_scaledTileHeight))) * this->widthInTiles) + (Float(((WorldPoint->x - this->x))) / Float(this->_scaledTileWidth)))))).StaticCast< ::flixel::tile::FlxTile >()->allowCollisions > (int)0);
		}
		HX_STACK_LINE(1066)
		if (((Camera == null()))){
			HX_STACK_LINE(1068)
			Camera = ::flixel::FlxG_obj::camera;
		}
		HX_STACK_LINE(1071)
		WorldPoint->set_x((WorldPoint->x - Camera->scroll->x));
		HX_STACK_LINE(1072)
		WorldPoint->set_y((WorldPoint->y - Camera->scroll->y));
		HX_STACK_LINE(1073)
		this->getScreenXY(this->_point,Camera);
		HX_STACK_LINE(1075)
		return (this->_tileObjects->__get(this->_data->__get(::Std_obj::_int(((::Std_obj::_int((Float(((WorldPoint->y - WorldPoint->y))) / Float(this->_scaledTileHeight))) * this->widthInTiles) + (Float(((WorldPoint->x - WorldPoint->x))) / Float(this->_scaledTileWidth)))))).StaticCast< ::flixel::tile::FlxTile >()->allowCollisions > (int)0);
	}
}


int FlxTilemap_obj::getTile( int X,int Y){
	HX_STACK_FRAME("flixel.tile.FlxTilemap","getTile",0xa2ec0ba0,"flixel.tile.FlxTilemap.getTile","flixel/tile/FlxTilemap.hx",1087,0x448feb74)
	HX_STACK_THIS(this)
	HX_STACK_ARG(X,"X")
	HX_STACK_ARG(Y,"Y")
	HX_STACK_LINE(1087)
	return this->_data->__get(((Y * this->widthInTiles) + X));
}


HX_DEFINE_DYNAMIC_FUNC2(FlxTilemap_obj,getTile,return )

int FlxTilemap_obj::getTileByIndex( int Index){
	HX_STACK_FRAME("flixel.tile.FlxTilemap","getTileByIndex",0x27fbf9fb,"flixel.tile.FlxTilemap.getTileByIndex","flixel/tile/FlxTilemap.hx",1098,0x448feb74)
	HX_STACK_THIS(this)
	HX_STACK_ARG(Index,"Index")
	HX_STACK_LINE(1098)
	return this->_data->__get(Index);
}


HX_DEFINE_DYNAMIC_FUNC1(FlxTilemap_obj,getTileByIndex,return )

int FlxTilemap_obj::getTileCollisions( int Index){
	HX_STACK_FRAME("flixel.tile.FlxTilemap","getTileCollisions",0x0a549381,"flixel.tile.FlxTilemap.getTileCollisions","flixel/tile/FlxTilemap.hx",1109,0x448feb74)
	HX_STACK_THIS(this)
	HX_STACK_ARG(Index,"Index")
	HX_STACK_LINE(1109)
	return this->_tileObjects->__get(Index).StaticCast< ::flixel::tile::FlxTile >()->allowCollisions;
}


HX_DEFINE_DYNAMIC_FUNC1(FlxTilemap_obj,getTileCollisions,return )

Array< int > FlxTilemap_obj::getTileInstances( int Index){
	HX_STACK_FRAME("flixel.tile.FlxTilemap","getTileInstances",0xee32e37e,"flixel.tile.FlxTilemap.getTileInstances","flixel/tile/FlxTilemap.hx",1119,0x448feb74)
	HX_STACK_THIS(this)
	HX_STACK_ARG(Index,"Index")
	HX_STACK_LINE(1120)
	Array< int > array = null();		HX_STACK_VAR(array,"array");
	HX_STACK_LINE(1121)
	int i = (int)0;		HX_STACK_VAR(i,"i");
	HX_STACK_LINE(1122)
	int l = (this->widthInTiles * this->heightInTiles);		HX_STACK_VAR(l,"l");
	HX_STACK_LINE(1124)
	while(((i < l))){
		HX_STACK_LINE(1126)
		if (((this->_data->__get(i) == Index))){
			HX_STACK_LINE(1128)
			if (((array == null()))){
				HX_STACK_LINE(1130)
				array = Array_obj< int >::__new();
			}
			HX_STACK_LINE(1132)
			array->push(i);
		}
		HX_STACK_LINE(1135)
		(i)++;
	}
	HX_STACK_LINE(1138)
	return array;
}


HX_DEFINE_DYNAMIC_FUNC1(FlxTilemap_obj,getTileInstances,return )

Array< ::Dynamic > FlxTilemap_obj::getTileCoords( int Index,hx::Null< bool >  __o_Midpoint){
bool Midpoint = __o_Midpoint.Default(true);
	HX_STACK_FRAME("flixel.tile.FlxTilemap","getTileCoords",0x02899bde,"flixel.tile.FlxTilemap.getTileCoords","flixel/tile/FlxTilemap.hx",1149,0x448feb74)
	HX_STACK_THIS(this)
	HX_STACK_ARG(Index,"Index")
	HX_STACK_ARG(Midpoint,"Midpoint")
{
		HX_STACK_LINE(1150)
		Array< ::Dynamic > array = null();		HX_STACK_VAR(array,"array");
		HX_STACK_LINE(1152)
		::flixel::util::FlxPoint point;		HX_STACK_VAR(point,"point");
		HX_STACK_LINE(1153)
		int i = (int)0;		HX_STACK_VAR(i,"i");
		HX_STACK_LINE(1154)
		int l = (this->widthInTiles * this->heightInTiles);		HX_STACK_VAR(l,"l");
		HX_STACK_LINE(1156)
		while(((i < l))){
			HX_STACK_LINE(1158)
			if (((this->_data->__get(i) == Index))){
				HX_STACK_LINE(1160)
				Float _g = (this->x + (::Std_obj::_int(hx::Mod(i,this->widthInTiles)) * this->_scaledTileWidth));		HX_STACK_VAR(_g,"_g");
				HX_STACK_LINE(1160)
				point = ::flixel::util::FlxPoint_obj::__new(_g,(this->y + (::Std_obj::_int((Float(i) / Float(this->widthInTiles))) * this->_scaledTileHeight)));
				HX_STACK_LINE(1162)
				if ((Midpoint)){
					HX_STACK_LINE(1164)
					{
						HX_STACK_LINE(1164)
						::flixel::util::FlxPoint _g1 = point;		HX_STACK_VAR(_g1,"_g1");
						HX_STACK_LINE(1164)
						_g1->set_x((_g1->x + (this->_scaledTileWidth * 0.5)));
					}
					HX_STACK_LINE(1165)
					{
						HX_STACK_LINE(1165)
						::flixel::util::FlxPoint _g1 = point;		HX_STACK_VAR(_g1,"_g1");
						HX_STACK_LINE(1165)
						_g1->set_y((_g1->y + (this->_scaledTileHeight * 0.5)));
					}
				}
				HX_STACK_LINE(1168)
				if (((array == null()))){
					HX_STACK_LINE(1170)
					array = Array_obj< ::Dynamic >::__new();
				}
				HX_STACK_LINE(1172)
				array->push(point);
			}
			HX_STACK_LINE(1175)
			(i)++;
		}
		HX_STACK_LINE(1178)
		return array;
	}
}


HX_DEFINE_DYNAMIC_FUNC2(FlxTilemap_obj,getTileCoords,return )

bool FlxTilemap_obj::setTile( int X,int Y,int Tile,hx::Null< bool >  __o_UpdateGraphics){
bool UpdateGraphics = __o_UpdateGraphics.Default(true);
	HX_STACK_FRAME("flixel.tile.FlxTilemap","setTile",0x95ed9cac,"flixel.tile.FlxTilemap.setTile","flixel/tile/FlxTilemap.hx",1191,0x448feb74)
	HX_STACK_THIS(this)
	HX_STACK_ARG(X,"X")
	HX_STACK_ARG(Y,"Y")
	HX_STACK_ARG(Tile,"Tile")
	HX_STACK_ARG(UpdateGraphics,"UpdateGraphics")
{
		HX_STACK_LINE(1192)
		if (((bool((X >= this->widthInTiles)) || bool((Y >= this->heightInTiles))))){
			HX_STACK_LINE(1194)
			return false;
		}
		HX_STACK_LINE(1197)
		return this->setTileByIndex(((Y * this->widthInTiles) + X),Tile,UpdateGraphics);
	}
}


HX_DEFINE_DYNAMIC_FUNC4(FlxTilemap_obj,setTile,return )

bool FlxTilemap_obj::setTileByIndex( int Index,int Tile,hx::Null< bool >  __o_UpdateGraphics){
bool UpdateGraphics = __o_UpdateGraphics.Default(true);
	HX_STACK_FRAME("flixel.tile.FlxTilemap","setTileByIndex",0x481be26f,"flixel.tile.FlxTilemap.setTileByIndex","flixel/tile/FlxTilemap.hx",1209,0x448feb74)
	HX_STACK_THIS(this)
	HX_STACK_ARG(Index,"Index")
	HX_STACK_ARG(Tile,"Tile")
	HX_STACK_ARG(UpdateGraphics,"UpdateGraphics")
{
		HX_STACK_LINE(1210)
		if (((Index >= this->_data->length))){
			HX_STACK_LINE(1212)
			return false;
		}
		HX_STACK_LINE(1215)
		bool ok = true;		HX_STACK_VAR(ok,"ok");
		HX_STACK_LINE(1216)
		this->_data[Index] = Tile;
		HX_STACK_LINE(1218)
		if ((!(UpdateGraphics))){
			HX_STACK_LINE(1220)
			return ok;
		}
		HX_STACK_LINE(1223)
		this->setDirty(null());
		HX_STACK_LINE(1225)
		if (((this->_auto == (int)0))){
			HX_STACK_LINE(1227)
			this->updateTile(Index);
			HX_STACK_LINE(1228)
			return ok;
		}
		HX_STACK_LINE(1232)
		int i;		HX_STACK_VAR(i,"i");
		HX_STACK_LINE(1233)
		int row = (::Std_obj::_int((Float(Index) / Float(this->widthInTiles))) - (int)1);		HX_STACK_VAR(row,"row");
		HX_STACK_LINE(1234)
		int rowLength = (row + (int)3);		HX_STACK_VAR(rowLength,"rowLength");
		HX_STACK_LINE(1235)
		int column = (hx::Mod(Index,this->widthInTiles) - (int)1);		HX_STACK_VAR(column,"column");
		HX_STACK_LINE(1236)
		int columnHeight = (column + (int)3);		HX_STACK_VAR(columnHeight,"columnHeight");
		HX_STACK_LINE(1238)
		while(((row < rowLength))){
			HX_STACK_LINE(1240)
			column = (columnHeight - (int)3);
			HX_STACK_LINE(1242)
			while(((column < columnHeight))){
				HX_STACK_LINE(1244)
				if (((bool((bool((bool((row >= (int)0)) && bool((row < this->heightInTiles)))) && bool((column >= (int)0)))) && bool((column < this->widthInTiles))))){
					HX_STACK_LINE(1246)
					i = ((row * this->widthInTiles) + column);
					HX_STACK_LINE(1247)
					this->autoTile(i);
					HX_STACK_LINE(1248)
					this->updateTile(i);
				}
				HX_STACK_LINE(1250)
				(column)++;
			}
			HX_STACK_LINE(1253)
			(row)++;
		}
		HX_STACK_LINE(1256)
		return ok;
	}
}


HX_DEFINE_DYNAMIC_FUNC3(FlxTilemap_obj,setTileByIndex,return )

Void FlxTilemap_obj::setTileProperties( int Tile,hx::Null< int >  __o_AllowCollisions,Dynamic Callback,::Class CallbackFilter,hx::Null< int >  __o_Range){
int AllowCollisions = __o_AllowCollisions.Default(4369);
int Range = __o_Range.Default(1);
	HX_STACK_FRAME("flixel.tile.FlxTilemap","setTileProperties",0x96b8abbf,"flixel.tile.FlxTilemap.setTileProperties","flixel/tile/FlxTilemap.hx",1270,0x448feb74)
	HX_STACK_THIS(this)
	HX_STACK_ARG(Tile,"Tile")
	HX_STACK_ARG(AllowCollisions,"AllowCollisions")
	HX_STACK_ARG(Callback,"Callback")
	HX_STACK_ARG(CallbackFilter,"CallbackFilter")
	HX_STACK_ARG(Range,"Range")
{
		HX_STACK_LINE(1271)
		if (((Range <= (int)0))){
			HX_STACK_LINE(1273)
			Range = (int)1;
		}
		HX_STACK_LINE(1276)
		::flixel::tile::FlxTile tile;		HX_STACK_VAR(tile,"tile");
		HX_STACK_LINE(1277)
		int i = Tile;		HX_STACK_VAR(i,"i");
		HX_STACK_LINE(1278)
		int l = (Tile + Range);		HX_STACK_VAR(l,"l");
		HX_STACK_LINE(1280)
		while(((i < l))){
			HX_STACK_LINE(1282)
			tile = this->_tileObjects->__get((i)++).StaticCast< ::flixel::tile::FlxTile >();
			HX_STACK_LINE(1283)
			if (((tile != null()))){
				HX_STACK_LINE(1284)
				tile->allowCollisions = AllowCollisions;
				HX_STACK_LINE(1285)
				tile->callbackFunction = Callback;
				HX_STACK_LINE(1286)
				tile->filter = CallbackFilter;
			}
		}
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC5(FlxTilemap_obj,setTileProperties,(void))

Void FlxTilemap_obj::follow( ::flixel::FlxCamera Camera,hx::Null< int >  __o_Border,hx::Null< bool >  __o_UpdateWorld){
int Border = __o_Border.Default(0);
bool UpdateWorld = __o_UpdateWorld.Default(true);
	HX_STACK_FRAME("flixel.tile.FlxTilemap","follow",0xe6a96c35,"flixel.tile.FlxTilemap.follow","flixel/tile/FlxTilemap.hx",1299,0x448feb74)
	HX_STACK_THIS(this)
	HX_STACK_ARG(Camera,"Camera")
	HX_STACK_ARG(Border,"Border")
	HX_STACK_ARG(UpdateWorld,"UpdateWorld")
{
		HX_STACK_LINE(1300)
		if (((Camera == null()))){
			HX_STACK_LINE(1302)
			Camera = ::flixel::FlxG_obj::camera;
		}
		HX_STACK_LINE(1305)
		Float _g = (this->get_width() - ((Border * this->_scaledTileWidth) * (int)2));		HX_STACK_VAR(_g,"_g");
		HX_STACK_LINE(1305)
		Camera->setBounds((this->x + (Border * this->_scaledTileWidth)),(this->y + (Border * this->_scaledTileHeight)),_g,(this->get_height() - ((Border * this->_scaledTileHeight) * (int)2)),UpdateWorld);
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC3(FlxTilemap_obj,follow,(void))

::flixel::util::FlxRect FlxTilemap_obj::getBounds( ::flixel::util::FlxRect Bounds){
	HX_STACK_FRAME("flixel.tile.FlxTilemap","getBounds",0x86b34767,"flixel.tile.FlxTilemap.getBounds","flixel/tile/FlxTilemap.hx",1315,0x448feb74)
	HX_STACK_THIS(this)
	HX_STACK_ARG(Bounds,"Bounds")
	HX_STACK_LINE(1316)
	if (((Bounds == null()))){
		HX_STACK_LINE(1318)
		Bounds = ::flixel::util::FlxRect_obj::__new(null(),null(),null(),null());
	}
	HX_STACK_LINE(1321)
	Float Width = this->get_width();		HX_STACK_VAR(Width,"Width");
	HX_STACK_LINE(1321)
	Float Height = this->get_height();		HX_STACK_VAR(Height,"Height");
	HX_STACK_LINE(1321)
	Bounds->x = this->x;
	HX_STACK_LINE(1321)
	Bounds->y = this->y;
	HX_STACK_LINE(1321)
	Bounds->width = Width;
	HX_STACK_LINE(1321)
	Bounds->height = Height;
	HX_STACK_LINE(1321)
	return Bounds;
}


HX_DEFINE_DYNAMIC_FUNC1(FlxTilemap_obj,getBounds,return )

bool FlxTilemap_obj::ray( ::flixel::util::FlxPoint Start,::flixel::util::FlxPoint End,::flixel::util::FlxPoint Result,hx::Null< Float >  __o_Resolution){
Float Resolution = __o_Resolution.Default(1);
	HX_STACK_FRAME("flixel.tile.FlxTilemap","ray",0xbe0558a6,"flixel.tile.FlxTilemap.ray","flixel/tile/FlxTilemap.hx",1335,0x448feb74)
	HX_STACK_THIS(this)
	HX_STACK_ARG(Start,"Start")
	HX_STACK_ARG(End,"End")
	HX_STACK_ARG(Result,"Result")
	HX_STACK_ARG(Resolution,"Resolution")
{
		HX_STACK_LINE(1336)
		Float step = this->_scaledTileWidth;		HX_STACK_VAR(step,"step");
		HX_STACK_LINE(1338)
		if (((this->_scaledTileHeight < this->_scaledTileWidth))){
			HX_STACK_LINE(1340)
			step = this->_scaledTileHeight;
		}
		HX_STACK_LINE(1343)
		hx::DivEq(step,Resolution);
		HX_STACK_LINE(1344)
		Float deltaX = (End->x - Start->x);		HX_STACK_VAR(deltaX,"deltaX");
		HX_STACK_LINE(1345)
		Float deltaY = (End->y - Start->y);		HX_STACK_VAR(deltaY,"deltaY");
		HX_STACK_LINE(1346)
		Float distance = ::Math_obj::sqrt(((deltaX * deltaX) + (deltaY * deltaY)));		HX_STACK_VAR(distance,"distance");
		HX_STACK_LINE(1347)
		int steps = ::Math_obj::ceil((Float(distance) / Float(step)));		HX_STACK_VAR(steps,"steps");
		HX_STACK_LINE(1348)
		Float stepX = (Float(deltaX) / Float(steps));		HX_STACK_VAR(stepX,"stepX");
		HX_STACK_LINE(1349)
		Float stepY = (Float(deltaY) / Float(steps));		HX_STACK_VAR(stepY,"stepY");
		HX_STACK_LINE(1350)
		Float curX = ((Start->x - stepX) - this->x);		HX_STACK_VAR(curX,"curX");
		HX_STACK_LINE(1351)
		Float curY = ((Start->y - stepY) - this->y);		HX_STACK_VAR(curY,"curY");
		HX_STACK_LINE(1352)
		int tileX;		HX_STACK_VAR(tileX,"tileX");
		HX_STACK_LINE(1353)
		int tileY;		HX_STACK_VAR(tileY,"tileY");
		HX_STACK_LINE(1354)
		int i = (int)0;		HX_STACK_VAR(i,"i");
		HX_STACK_LINE(1356)
		while(((i < steps))){
			HX_STACK_LINE(1358)
			hx::AddEq(curX,stepX);
			HX_STACK_LINE(1359)
			hx::AddEq(curY,stepY);
			HX_STACK_LINE(1361)
			if (((  ((!(((  ((!(((  ((!(((curX < (int)0))))) ? bool((curX > this->get_width())) : bool(true) ))))) ? bool((curY < (int)0)) : bool(true) ))))) ? bool((curY > this->get_height())) : bool(true) ))){
				HX_STACK_LINE(1363)
				(i)++;
				HX_STACK_LINE(1364)
				continue;
			}
			HX_STACK_LINE(1367)
			tileX = ::Math_obj::floor((Float(curX) / Float(this->_scaledTileWidth)));
			HX_STACK_LINE(1368)
			tileY = ::Math_obj::floor((Float(curY) / Float(this->_scaledTileHeight)));
			HX_STACK_LINE(1370)
			if (((this->_tileObjects->__get(this->_data->__get(((tileY * this->widthInTiles) + tileX))).StaticCast< ::flixel::tile::FlxTile >()->allowCollisions != (int)0))){
				HX_STACK_LINE(1373)
				hx::MultEq(tileX,::Std_obj::_int(this->_scaledTileWidth));
				HX_STACK_LINE(1374)
				hx::MultEq(tileY,::Std_obj::_int(this->_scaledTileHeight));
				HX_STACK_LINE(1375)
				Float rx = (int)0;		HX_STACK_VAR(rx,"rx");
				HX_STACK_LINE(1376)
				Float ry = (int)0;		HX_STACK_VAR(ry,"ry");
				HX_STACK_LINE(1377)
				Float q;		HX_STACK_VAR(q,"q");
				HX_STACK_LINE(1378)
				Float lx = (curX - stepX);		HX_STACK_VAR(lx,"lx");
				HX_STACK_LINE(1379)
				Float ly = (curY - stepY);		HX_STACK_VAR(ly,"ly");
				HX_STACK_LINE(1382)
				q = tileX;
				HX_STACK_LINE(1384)
				if (((deltaX < (int)0))){
					HX_STACK_LINE(1386)
					hx::AddEq(q,this->_scaledTileWidth);
				}
				HX_STACK_LINE(1389)
				rx = q;
				HX_STACK_LINE(1390)
				ry = (ly + (stepY * ((Float(((q - lx))) / Float(stepX)))));
				HX_STACK_LINE(1392)
				if (((bool((ry > tileY)) && bool((ry < (tileY + this->_scaledTileHeight)))))){
					HX_STACK_LINE(1394)
					if (((Result != null()))){
						HX_STACK_LINE(1396)
						Result->set_x(rx);
						HX_STACK_LINE(1397)
						Result->set_y(ry);
					}
					HX_STACK_LINE(1400)
					return false;
				}
				HX_STACK_LINE(1404)
				q = tileY;
				HX_STACK_LINE(1406)
				if (((deltaY < (int)0))){
					HX_STACK_LINE(1408)
					hx::AddEq(q,this->_scaledTileHeight);
				}
				HX_STACK_LINE(1411)
				rx = (lx + (stepX * ((Float(((q - ly))) / Float(stepY)))));
				HX_STACK_LINE(1412)
				ry = q;
				HX_STACK_LINE(1414)
				if (((bool((rx > tileX)) && bool((rx < (tileX + this->_scaledTileWidth)))))){
					HX_STACK_LINE(1416)
					if (((Result != null()))){
						HX_STACK_LINE(1418)
						Result->set_x(rx);
						HX_STACK_LINE(1419)
						Result->set_y(ry);
					}
					HX_STACK_LINE(1422)
					return false;
				}
				HX_STACK_LINE(1425)
				return true;
			}
			HX_STACK_LINE(1428)
			(i)++;
		}
		HX_STACK_LINE(1431)
		return true;
	}
}


HX_DEFINE_DYNAMIC_FUNC4(FlxTilemap_obj,ray,return )

::flixel::util::FlxPoint FlxTilemap_obj::rayHit( ::flixel::util::FlxPoint Start,::flixel::util::FlxPoint End,hx::Null< Float >  __o_Resolution){
Float Resolution = __o_Resolution.Default(1);
	HX_STACK_FRAME("flixel.tile.FlxTilemap","rayHit",0xabd2114d,"flixel.tile.FlxTilemap.rayHit","flixel/tile/FlxTilemap.hx",1449,0x448feb74)
	HX_STACK_THIS(this)
	HX_STACK_ARG(Start,"Start")
	HX_STACK_ARG(End,"End")
	HX_STACK_ARG(Resolution,"Resolution")
{
		HX_STACK_LINE(1450)
		::flixel::util::FlxPoint Result = null();		HX_STACK_VAR(Result,"Result");
		HX_STACK_LINE(1451)
		Float step = this->_scaledTileWidth;		HX_STACK_VAR(step,"step");
		HX_STACK_LINE(1453)
		if (((this->_scaledTileHeight < this->_scaledTileWidth))){
			HX_STACK_LINE(1455)
			step = this->_scaledTileHeight;
		}
		HX_STACK_LINE(1458)
		hx::DivEq(step,Resolution);
		HX_STACK_LINE(1459)
		Float deltaX = (End->x - Start->x);		HX_STACK_VAR(deltaX,"deltaX");
		HX_STACK_LINE(1460)
		Float deltaY = (End->y - Start->y);		HX_STACK_VAR(deltaY,"deltaY");
		HX_STACK_LINE(1461)
		Float distance = ::Math_obj::sqrt(((deltaX * deltaX) + (deltaY * deltaY)));		HX_STACK_VAR(distance,"distance");
		HX_STACK_LINE(1462)
		int steps = ::Math_obj::ceil((Float(distance) / Float(step)));		HX_STACK_VAR(steps,"steps");
		HX_STACK_LINE(1463)
		Float stepX = (Float(deltaX) / Float(steps));		HX_STACK_VAR(stepX,"stepX");
		HX_STACK_LINE(1464)
		Float stepY = (Float(deltaY) / Float(steps));		HX_STACK_VAR(stepY,"stepY");
		HX_STACK_LINE(1465)
		Float curX = ((Start->x - stepX) - this->x);		HX_STACK_VAR(curX,"curX");
		HX_STACK_LINE(1466)
		Float curY = ((Start->y - stepY) - this->y);		HX_STACK_VAR(curY,"curY");
		HX_STACK_LINE(1467)
		int tileX;		HX_STACK_VAR(tileX,"tileX");
		HX_STACK_LINE(1468)
		int tileY;		HX_STACK_VAR(tileY,"tileY");
		HX_STACK_LINE(1469)
		int i = (int)0;		HX_STACK_VAR(i,"i");
		HX_STACK_LINE(1471)
		while(((i < steps))){
			HX_STACK_LINE(1473)
			hx::AddEq(curX,stepX);
			HX_STACK_LINE(1474)
			hx::AddEq(curY,stepY);
			HX_STACK_LINE(1476)
			if (((  ((!(((  ((!(((  ((!(((curX < (int)0))))) ? bool((curX > this->get_width())) : bool(true) ))))) ? bool((curY < (int)0)) : bool(true) ))))) ? bool((curY > this->get_height())) : bool(true) ))){
				HX_STACK_LINE(1478)
				(i)++;
				HX_STACK_LINE(1479)
				continue;
			}
			HX_STACK_LINE(1482)
			tileX = ::Math_obj::floor((Float(curX) / Float(this->_scaledTileWidth)));
			HX_STACK_LINE(1483)
			tileY = ::Math_obj::floor((Float(curY) / Float(this->_scaledTileHeight)));
			HX_STACK_LINE(1485)
			if (((this->_tileObjects->__get(this->_data->__get(((tileY * this->widthInTiles) + tileX))).StaticCast< ::flixel::tile::FlxTile >()->allowCollisions != (int)0))){
				HX_STACK_LINE(1488)
				hx::MultEq(tileX,::Std_obj::_int(this->_scaledTileWidth));
				HX_STACK_LINE(1489)
				hx::MultEq(tileY,::Std_obj::_int(this->_scaledTileHeight));
				HX_STACK_LINE(1490)
				Float rx = (int)0;		HX_STACK_VAR(rx,"rx");
				HX_STACK_LINE(1491)
				Float ry = (int)0;		HX_STACK_VAR(ry,"ry");
				HX_STACK_LINE(1492)
				Float q;		HX_STACK_VAR(q,"q");
				HX_STACK_LINE(1493)
				Float lx = (curX - stepX);		HX_STACK_VAR(lx,"lx");
				HX_STACK_LINE(1494)
				Float ly = (curY - stepY);		HX_STACK_VAR(ly,"ly");
				HX_STACK_LINE(1497)
				q = tileX;
				HX_STACK_LINE(1499)
				if (((deltaX < (int)0))){
					HX_STACK_LINE(1501)
					hx::AddEq(q,this->_scaledTileWidth);
				}
				HX_STACK_LINE(1504)
				rx = q;
				HX_STACK_LINE(1505)
				ry = (ly + (stepY * ((Float(((q - lx))) / Float(stepX)))));
				HX_STACK_LINE(1507)
				if (((bool((ry > tileY)) && bool((ry < (tileY + this->_scaledTileHeight)))))){
					HX_STACK_LINE(1509)
					if (((Result == null()))){
						HX_STACK_LINE(1511)
						Result = ::flixel::util::FlxPoint_obj::__new(null(),null());
					}
					HX_STACK_LINE(1514)
					Result->set_x(rx);
					HX_STACK_LINE(1515)
					Result->set_y(ry);
					HX_STACK_LINE(1516)
					return Result;
				}
				HX_STACK_LINE(1520)
				q = tileY;
				HX_STACK_LINE(1522)
				if (((deltaY < (int)0))){
					HX_STACK_LINE(1524)
					hx::AddEq(q,this->_scaledTileHeight);
				}
				HX_STACK_LINE(1527)
				rx = (lx + (stepX * ((Float(((q - ly))) / Float(stepY)))));
				HX_STACK_LINE(1528)
				ry = q;
				HX_STACK_LINE(1530)
				if (((bool((rx > tileX)) && bool((rx < (tileX + this->_scaledTileWidth)))))){
					HX_STACK_LINE(1532)
					if (((Result == null()))){
						HX_STACK_LINE(1534)
						Result = ::flixel::util::FlxPoint_obj::__new(null(),null());
					}
					HX_STACK_LINE(1537)
					Result->set_x(rx);
					HX_STACK_LINE(1538)
					Result->set_y(ry);
					HX_STACK_LINE(1539)
					return Result;
				}
				HX_STACK_LINE(1542)
				return null();
			}
			HX_STACK_LINE(1545)
			(i)++;
		}
		HX_STACK_LINE(1548)
		return null();
	}
}


HX_DEFINE_DYNAMIC_FUNC3(FlxTilemap_obj,rayHit,return )

Void FlxTilemap_obj::updateFrameData( ){
{
		HX_STACK_FRAME("flixel.tile.FlxTilemap","updateFrameData",0x0334926a,"flixel.tile.FlxTilemap.updateFrameData","flixel/tile/FlxTilemap.hx",1557,0x448feb74)
		HX_STACK_THIS(this)
		HX_STACK_LINE(1557)
		if (((bool((bool((this->cachedGraphics != null())) && bool((this->_tileWidth >= (int)1)))) && bool((this->_tileHeight >= (int)1))))){
			HX_STACK_LINE(1559)
			this->framesData = this->cachedGraphics->get_tilesheet()->getSpriteSheetFrames(this->region,::flash::geom::Point_obj::__new((int)0,(int)0));
			HX_STACK_LINE(1561)
			this->_rectIDs = Array_obj< int >::__new();
			HX_STACK_LINE(1562)
			::flixel::util::FlxArrayUtil_obj::setLength_Int(this->_rectIDs,this->totalTiles);
			HX_STACK_LINE(1564)
			int i = (int)0;		HX_STACK_VAR(i,"i");
			HX_STACK_LINE(1566)
			while(((i < this->totalTiles))){
				HX_STACK_LINE(1568)
				this->updateTile((i)++);
			}
		}
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC0(FlxTilemap_obj,updateFrameData,(void))

::flixel::FlxSprite FlxTilemap_obj::tileToFlxSprite( int X,int Y,hx::Null< int >  __o_NewTile){
int NewTile = __o_NewTile.Default(0);
	HX_STACK_FRAME("flixel.tile.FlxTilemap","tileToFlxSprite",0x2b66754a,"flixel.tile.FlxTilemap.tileToFlxSprite","flixel/tile/FlxTilemap.hx",1583,0x448feb74)
	HX_STACK_THIS(this)
	HX_STACK_ARG(X,"X")
	HX_STACK_ARG(Y,"Y")
	HX_STACK_ARG(NewTile,"NewTile")
{
		HX_STACK_LINE(1584)
		int rowIndex = (X + (Y * this->widthInTiles));		HX_STACK_VAR(rowIndex,"rowIndex");
		HX_STACK_LINE(1586)
		::flash::geom::Rectangle rect = null();		HX_STACK_VAR(rect,"rect");
		HX_STACK_LINE(1592)
		::flixel::tile::FlxTile tile = this->_tileObjects->__get(this->_data->__get(rowIndex)).StaticCast< ::flixel::tile::FlxTile >();		HX_STACK_VAR(tile,"tile");
		HX_STACK_LINE(1594)
		if (((bool((tile == null())) || bool(!(tile->visible))))){
		}
		else{
			HX_STACK_LINE(1600)
			int rx = (((this->_data->__get(rowIndex) - this->_startingIndex)) * ((this->_tileWidth + this->region->spacingX)));		HX_STACK_VAR(rx,"rx");
			HX_STACK_LINE(1601)
			int ry = (int)0;		HX_STACK_VAR(ry,"ry");
			HX_STACK_LINE(1603)
			if (((rx >= this->region->width))){
				HX_STACK_LINE(1605)
				ry = (::Std_obj::_int((Float(rx) / Float(this->region->width))) * ((this->_tileHeight + this->region->spacingY)));
				HX_STACK_LINE(1606)
				hx::ModEq(rx,this->region->width);
			}
			HX_STACK_LINE(1609)
			rect = ::flash::geom::Rectangle_obj::__new((rx + this->region->startX),(ry + this->region->startY),this->_tileWidth,this->_tileHeight);
		}
		HX_STACK_LINE(1614)
		::flash::geom::Point pt = ::flash::geom::Point_obj::__new((int)0,(int)0);		HX_STACK_VAR(pt,"pt");
		HX_STACK_LINE(1615)
		::flixel::FlxSprite tileSprite = ::flixel::FlxSprite_obj::__new(null(),null(),null());		HX_STACK_VAR(tileSprite,"tileSprite");
		HX_STACK_LINE(1616)
		tileSprite->makeGraphic(this->_tileWidth,this->_tileHeight,(int)0,true,null());
		HX_STACK_LINE(1617)
		tileSprite->set_x(((X * this->_tileWidth) + this->x));
		HX_STACK_LINE(1618)
		tileSprite->set_y(((Y * this->_tileHeight) + this->y));
		HX_STACK_LINE(1619)
		tileSprite->scale->set_x(this->scaleX);
		HX_STACK_LINE(1620)
		tileSprite->scale->set_y(this->scaleY);
		HX_STACK_LINE(1622)
		if (((rect != null()))){
			HX_STACK_LINE(1624)
			tileSprite->get_pixels()->copyPixels(this->cachedGraphics->bitmap,rect,pt,null(),null(),null());
		}
		HX_STACK_LINE(1627)
		tileSprite->dirty = true;
		HX_STACK_LINE(1628)
		tileSprite->updateFrameData();
		HX_STACK_LINE(1630)
		if (((NewTile >= (int)0))){
			HX_STACK_LINE(1632)
			this->setTile(X,Y,NewTile,null());
		}
		HX_STACK_LINE(1635)
		return tileSprite;
	}
}


HX_DEFINE_DYNAMIC_FUNC3(FlxTilemap_obj,tileToFlxSprite,return )

Void FlxTilemap_obj::updateBuffers( ){
{
		HX_STACK_FRAME("flixel.tile.FlxTilemap","updateBuffers",0xf5face26,"flixel.tile.FlxTilemap.updateBuffers","flixel/tile/FlxTilemap.hx",1642,0x448feb74)
		HX_STACK_THIS(this)
		HX_STACK_LINE(1643)
		int i = (int)0;		HX_STACK_VAR(i,"i");
		HX_STACK_LINE(1644)
		int l;		HX_STACK_VAR(l,"l");
		HX_STACK_LINE(1646)
		if (((this->_buffers != null()))){
			HX_STACK_LINE(1648)
			i = (int)0;
			HX_STACK_LINE(1649)
			l = this->_buffers->length;
			HX_STACK_LINE(1651)
			{
				HX_STACK_LINE(1651)
				int _g = (int)0;		HX_STACK_VAR(_g,"_g");
				HX_STACK_LINE(1651)
				while(((_g < l))){
					HX_STACK_LINE(1651)
					int i1 = (_g)++;		HX_STACK_VAR(i1,"i1");
					HX_STACK_LINE(1653)
					this->_buffers->__get(i1).StaticCast< ::flixel::tile::FlxTilemapBuffer >()->destroy();
				}
			}
			HX_STACK_LINE(1656)
			this->_buffers = null();
		}
		HX_STACK_LINE(1659)
		this->_buffers = Array_obj< ::Dynamic >::__new();
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC0(FlxTilemap_obj,updateBuffers,(void))

Void FlxTilemap_obj::drawTilemap( ::flixel::tile::FlxTilemapBuffer Buffer,::flixel::FlxCamera Camera){
{
		HX_STACK_FRAME("flixel.tile.FlxTilemap","drawTilemap",0x2b20d346,"flixel.tile.FlxTilemap.drawTilemap","flixel/tile/FlxTilemap.hx",1669,0x448feb74)
		HX_STACK_THIS(this)
		HX_STACK_ARG(Buffer,"Buffer")
		HX_STACK_ARG(Camera,"Camera")
		HX_STACK_LINE(1673)
		this->_helperPoint->x = (this->x - (Camera->scroll->x * this->scrollFactor->x));
		HX_STACK_LINE(1674)
		this->_helperPoint->y = (this->y - (Camera->scroll->y * this->scrollFactor->y));
		HX_STACK_LINE(1676)
		int tileID;		HX_STACK_VAR(tileID,"tileID");
		HX_STACK_LINE(1677)
		Float drawX;		HX_STACK_VAR(drawX,"drawX");
		HX_STACK_LINE(1678)
		Float drawY;		HX_STACK_VAR(drawY,"drawY");
		HX_STACK_LINE(1680)
		Float hackScaleX = (this->tileScaleHack * this->scaleX);		HX_STACK_VAR(hackScaleX,"hackScaleX");
		HX_STACK_LINE(1681)
		Float hackScaleY = (this->tileScaleHack * this->scaleY);		HX_STACK_VAR(hackScaleY,"hackScaleY");
		HX_STACK_LINE(1684)
		::flixel::system::layer::DrawStackItem drawItem = Camera->getDrawStackItem(this->cachedGraphics,false,(int)0,null());		HX_STACK_VAR(drawItem,"drawItem");
		HX_STACK_LINE(1688)
		Array< Float > currDrawData = drawItem->drawData;		HX_STACK_VAR(currDrawData,"currDrawData");
		HX_STACK_LINE(1689)
		int currIndex = drawItem->position;		HX_STACK_VAR(currIndex,"currIndex");
		HX_STACK_LINE(1693)
		this->_point->set_x(((Camera->scroll->x * this->scrollFactor->x) - this->x));
		HX_STACK_LINE(1694)
		this->_point->set_y(((Camera->scroll->y * this->scrollFactor->y) - this->y));
		HX_STACK_LINE(1696)
		int screenXInTiles = ::Math_obj::floor((Float(this->_point->x) / Float(this->_scaledTileWidth)));		HX_STACK_VAR(screenXInTiles,"screenXInTiles");
		HX_STACK_LINE(1697)
		int screenYInTiles = ::Math_obj::floor((Float(this->_point->y) / Float(this->_scaledTileHeight)));		HX_STACK_VAR(screenYInTiles,"screenYInTiles");
		HX_STACK_LINE(1698)
		int screenRows = Buffer->rows;		HX_STACK_VAR(screenRows,"screenRows");
		HX_STACK_LINE(1699)
		int screenColumns = Buffer->columns;		HX_STACK_VAR(screenColumns,"screenColumns");
		HX_STACK_LINE(1702)
		if (((screenXInTiles < (int)0))){
			HX_STACK_LINE(1704)
			screenXInTiles = (int)0;
		}
		HX_STACK_LINE(1706)
		if (((screenXInTiles > (this->widthInTiles - screenColumns)))){
			HX_STACK_LINE(1708)
			screenXInTiles = (this->widthInTiles - screenColumns);
		}
		HX_STACK_LINE(1710)
		if (((screenYInTiles < (int)0))){
			HX_STACK_LINE(1712)
			screenYInTiles = (int)0;
		}
		HX_STACK_LINE(1714)
		if (((screenYInTiles > (this->heightInTiles - screenRows)))){
			HX_STACK_LINE(1716)
			screenYInTiles = (this->heightInTiles - screenRows);
		}
		HX_STACK_LINE(1719)
		int rowIndex = ((screenYInTiles * this->widthInTiles) + screenXInTiles);		HX_STACK_VAR(rowIndex,"rowIndex");
		HX_STACK_LINE(1720)
		this->_flashPoint->y = (int)0;
		HX_STACK_LINE(1721)
		int row = (int)0;		HX_STACK_VAR(row,"row");
		HX_STACK_LINE(1722)
		int column;		HX_STACK_VAR(column,"column");
		HX_STACK_LINE(1723)
		int columnIndex;		HX_STACK_VAR(columnIndex,"columnIndex");
		HX_STACK_LINE(1724)
		::flixel::tile::FlxTile tile;		HX_STACK_VAR(tile,"tile");
		HX_STACK_LINE(1727)
		::flash::display::BitmapData debugTile;		HX_STACK_VAR(debugTile,"debugTile");
		HX_STACK_LINE(1730)
		while(((row < screenRows))){
			HX_STACK_LINE(1732)
			columnIndex = rowIndex;
			HX_STACK_LINE(1733)
			column = (int)0;
			HX_STACK_LINE(1734)
			this->_flashPoint->x = (int)0;
			HX_STACK_LINE(1736)
			while(((column < screenColumns))){
				HX_STACK_LINE(1774)
				tileID = this->_rectIDs->__get(columnIndex);
				HX_STACK_LINE(1776)
				if (((tileID != (int)-1))){
					HX_STACK_LINE(1778)
					drawX = (this->_helperPoint->x + (hx::Mod(columnIndex,this->widthInTiles) * this->_scaledTileWidth));
					HX_STACK_LINE(1779)
					drawY = (this->_helperPoint->y + (::Math_obj::floor((Float(columnIndex) / Float(this->widthInTiles))) * this->_scaledTileHeight));
					HX_STACK_LINE(1782)
					currDrawData[(currIndex)++] = drawX;
					HX_STACK_LINE(1783)
					currDrawData[(currIndex)++] = drawY;
					HX_STACK_LINE(1788)
					currDrawData[(currIndex)++] = tileID;
					HX_STACK_LINE(1791)
					currDrawData[(currIndex)++] = hackScaleX;
					HX_STACK_LINE(1792)
					currDrawData[(currIndex)++] = (int)0;
					HX_STACK_LINE(1793)
					currDrawData[(currIndex)++] = (int)0;
					HX_STACK_LINE(1795)
					currDrawData[(currIndex)++] = hackScaleY;
					HX_STACK_LINE(1799)
					currDrawData[(currIndex)++] = 1.0;
				}
				HX_STACK_LINE(1807)
				(column)++;
				HX_STACK_LINE(1808)
				(columnIndex)++;
			}
			HX_STACK_LINE(1814)
			hx::AddEq(rowIndex,this->widthInTiles);
			HX_STACK_LINE(1815)
			(row)++;
		}
		HX_STACK_LINE(1819)
		drawItem->position = currIndex;
		HX_STACK_LINE(1822)
		Buffer->x = (screenXInTiles * this->_scaledTileWidth);
		HX_STACK_LINE(1823)
		Buffer->y = (screenYInTiles * this->_scaledTileHeight);
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC2(FlxTilemap_obj,drawTilemap,(void))

Void FlxTilemap_obj::simplifyPath( Array< ::Dynamic > Points){
{
		HX_STACK_FRAME("flixel.tile.FlxTilemap","simplifyPath",0x8a506712,"flixel.tile.FlxTilemap.simplifyPath","flixel/tile/FlxTilemap.hx",1857,0x448feb74)
		HX_STACK_THIS(this)
		HX_STACK_ARG(Points,"Points")
		HX_STACK_LINE(1858)
		Float deltaPrevious;		HX_STACK_VAR(deltaPrevious,"deltaPrevious");
		HX_STACK_LINE(1859)
		Float deltaNext;		HX_STACK_VAR(deltaNext,"deltaNext");
		HX_STACK_LINE(1860)
		::flixel::util::FlxPoint last = Points->__get((int)0).StaticCast< ::flixel::util::FlxPoint >();		HX_STACK_VAR(last,"last");
		HX_STACK_LINE(1861)
		::flixel::util::FlxPoint node;		HX_STACK_VAR(node,"node");
		HX_STACK_LINE(1862)
		int i = (int)1;		HX_STACK_VAR(i,"i");
		HX_STACK_LINE(1863)
		int l = (Points->length - (int)1);		HX_STACK_VAR(l,"l");
		HX_STACK_LINE(1865)
		while(((i < l))){
			HX_STACK_LINE(1867)
			node = Points->__get(i).StaticCast< ::flixel::util::FlxPoint >();
			HX_STACK_LINE(1868)
			deltaPrevious = (Float(((node->x - last->x))) / Float(((node->y - last->y))));
			HX_STACK_LINE(1869)
			deltaNext = (Float(((node->x - Points->__get((i + (int)1)).StaticCast< ::flixel::util::FlxPoint >()->x))) / Float(((node->y - Points->__get((i + (int)1)).StaticCast< ::flixel::util::FlxPoint >()->y))));
			HX_STACK_LINE(1871)
			if (((bool((bool((last->x == Points->__get((i + (int)1)).StaticCast< ::flixel::util::FlxPoint >()->x)) || bool((last->y == Points->__get((i + (int)1)).StaticCast< ::flixel::util::FlxPoint >()->y)))) || bool((deltaPrevious == deltaNext))))){
				HX_STACK_LINE(1873)
				Points[i] = null();
			}
			else{
				HX_STACK_LINE(1877)
				last = node;
			}
			HX_STACK_LINE(1880)
			(i)++;
		}
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC1(FlxTilemap_obj,simplifyPath,(void))

Void FlxTilemap_obj::raySimplifyPath( Array< ::Dynamic > Points){
{
		HX_STACK_FRAME("flixel.tile.FlxTilemap","raySimplifyPath",0xc5bc2714,"flixel.tile.FlxTilemap.raySimplifyPath","flixel/tile/FlxTilemap.hx",1890,0x448feb74)
		HX_STACK_THIS(this)
		HX_STACK_ARG(Points,"Points")
		HX_STACK_LINE(1891)
		::flixel::util::FlxPoint source = Points->__get((int)0).StaticCast< ::flixel::util::FlxPoint >();		HX_STACK_VAR(source,"source");
		HX_STACK_LINE(1892)
		int lastIndex = (int)-1;		HX_STACK_VAR(lastIndex,"lastIndex");
		HX_STACK_LINE(1893)
		::flixel::util::FlxPoint node;		HX_STACK_VAR(node,"node");
		HX_STACK_LINE(1894)
		int i = (int)1;		HX_STACK_VAR(i,"i");
		HX_STACK_LINE(1895)
		int l = Points->length;		HX_STACK_VAR(l,"l");
		HX_STACK_LINE(1897)
		while(((i < l))){
			HX_STACK_LINE(1899)
			node = Points->__get((i)++).StaticCast< ::flixel::util::FlxPoint >();
			HX_STACK_LINE(1901)
			if (((node == null()))){
				HX_STACK_LINE(1903)
				continue;
			}
			HX_STACK_LINE(1906)
			if ((this->ray(source,node,this->_point,null()))){
				HX_STACK_LINE(1908)
				if (((lastIndex >= (int)0))){
					HX_STACK_LINE(1910)
					Points[lastIndex] = null();
				}
			}
			else{
				HX_STACK_LINE(1915)
				source = Points->__get(lastIndex).StaticCast< ::flixel::util::FlxPoint >();
			}
			HX_STACK_LINE(1918)
			lastIndex = (i - (int)1);
		}
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC1(FlxTilemap_obj,raySimplifyPath,(void))

Array< int > FlxTilemap_obj::computePathDistance( int StartIndex,int EndIndex,bool WideDiagonal,hx::Null< bool >  __o_StopOnEnd){
bool StopOnEnd = __o_StopOnEnd.Default(true);
	HX_STACK_FRAME("flixel.tile.FlxTilemap","computePathDistance",0x95b706cd,"flixel.tile.FlxTilemap.computePathDistance","flixel/tile/FlxTilemap.hx",1933,0x448feb74)
	HX_STACK_THIS(this)
	HX_STACK_ARG(StartIndex,"StartIndex")
	HX_STACK_ARG(EndIndex,"EndIndex")
	HX_STACK_ARG(WideDiagonal,"WideDiagonal")
	HX_STACK_ARG(StopOnEnd,"StopOnEnd")
{
		HX_STACK_LINE(1936)
		int mapSize = (this->widthInTiles * this->heightInTiles);		HX_STACK_VAR(mapSize,"mapSize");
		HX_STACK_LINE(1937)
		Array< int > distances = Array_obj< int >::__new();		HX_STACK_VAR(distances,"distances");
		HX_STACK_LINE(1938)
		::flixel::util::FlxArrayUtil_obj::setLength_Int(distances,mapSize);
		HX_STACK_LINE(1939)
		int i = (int)0;		HX_STACK_VAR(i,"i");
		HX_STACK_LINE(1941)
		while(((i < mapSize))){
			HX_STACK_LINE(1943)
			if (((this->_tileObjects->__get(this->_data->__get(i)).StaticCast< ::flixel::tile::FlxTile >()->allowCollisions != (int)0))){
				HX_STACK_LINE(1945)
				distances[i] = (int)-2;
			}
			else{
				HX_STACK_LINE(1949)
				distances[i] = (int)-1;
			}
			HX_STACK_LINE(1951)
			(i)++;
		}
		HX_STACK_LINE(1954)
		distances[StartIndex] = (int)0;
		HX_STACK_LINE(1955)
		int distance = (int)1;		HX_STACK_VAR(distance,"distance");
		HX_STACK_LINE(1956)
		Array< int > neighbors = Array_obj< int >::__new().Add(StartIndex);		HX_STACK_VAR(neighbors,"neighbors");
		HX_STACK_LINE(1957)
		Array< int > current;		HX_STACK_VAR(current,"current");
		HX_STACK_LINE(1958)
		int currentIndex;		HX_STACK_VAR(currentIndex,"currentIndex");
		HX_STACK_LINE(1959)
		bool left;		HX_STACK_VAR(left,"left");
		HX_STACK_LINE(1960)
		bool right;		HX_STACK_VAR(right,"right");
		HX_STACK_LINE(1961)
		bool up;		HX_STACK_VAR(up,"up");
		HX_STACK_LINE(1962)
		bool down;		HX_STACK_VAR(down,"down");
		HX_STACK_LINE(1963)
		int currentLength;		HX_STACK_VAR(currentLength,"currentLength");
		HX_STACK_LINE(1964)
		bool foundEnd = false;		HX_STACK_VAR(foundEnd,"foundEnd");
		HX_STACK_LINE(1966)
		while(((neighbors->length > (int)0))){
			HX_STACK_LINE(1968)
			current = neighbors;
			HX_STACK_LINE(1969)
			neighbors = Array_obj< int >::__new();
			HX_STACK_LINE(1971)
			i = (int)0;
			HX_STACK_LINE(1972)
			currentLength = current->length;
			HX_STACK_LINE(1973)
			while(((i < currentLength))){
				HX_STACK_LINE(1975)
				currentIndex = current->__get((i)++);
				HX_STACK_LINE(1977)
				if (((currentIndex == ::Std_obj::_int(EndIndex)))){
					HX_STACK_LINE(1979)
					foundEnd = true;
					HX_STACK_LINE(1980)
					if ((StopOnEnd)){
						HX_STACK_LINE(1981)
						neighbors = Array_obj< int >::__new();
						HX_STACK_LINE(1982)
						break;
					}
				}
				HX_STACK_LINE(1987)
				left = (hx::Mod(currentIndex,this->widthInTiles) > (int)0);
				HX_STACK_LINE(1988)
				right = (hx::Mod(currentIndex,this->widthInTiles) < (this->widthInTiles - (int)1));
				HX_STACK_LINE(1989)
				up = ((Float(currentIndex) / Float(this->widthInTiles)) > (int)0);
				HX_STACK_LINE(1990)
				down = ((Float(currentIndex) / Float(this->widthInTiles)) < (this->heightInTiles - (int)1));
				HX_STACK_LINE(1992)
				int index;		HX_STACK_VAR(index,"index");
				HX_STACK_LINE(1994)
				if ((up)){
					HX_STACK_LINE(1996)
					index = (currentIndex - this->widthInTiles);
					HX_STACK_LINE(1998)
					if (((distances->__get(index) == (int)-1))){
						HX_STACK_LINE(2000)
						distances[index] = distance;
						HX_STACK_LINE(2001)
						neighbors->push(index);
					}
				}
				HX_STACK_LINE(2004)
				if ((right)){
					HX_STACK_LINE(2006)
					index = (currentIndex + (int)1);
					HX_STACK_LINE(2008)
					if (((distances->__get(index) == (int)-1))){
						HX_STACK_LINE(2010)
						distances[index] = distance;
						HX_STACK_LINE(2011)
						neighbors->push(index);
					}
				}
				HX_STACK_LINE(2014)
				if ((down)){
					HX_STACK_LINE(2016)
					index = (currentIndex + this->widthInTiles);
					HX_STACK_LINE(2018)
					if (((distances->__get(index) == (int)-1))){
						HX_STACK_LINE(2020)
						distances[index] = distance;
						HX_STACK_LINE(2021)
						neighbors->push(index);
					}
				}
				HX_STACK_LINE(2024)
				if ((left)){
					HX_STACK_LINE(2026)
					index = (currentIndex - (int)1);
					HX_STACK_LINE(2028)
					if (((distances->__get(index) == (int)-1))){
						HX_STACK_LINE(2030)
						distances[index] = distance;
						HX_STACK_LINE(2031)
						neighbors->push(index);
					}
				}
				HX_STACK_LINE(2034)
				if (((bool(up) && bool(right)))){
					HX_STACK_LINE(2036)
					index = ((currentIndex - this->widthInTiles) + (int)1);
					HX_STACK_LINE(2038)
					if (((bool((bool((bool(WideDiagonal) && bool((distances->__get(index) == (int)-1)))) && bool((distances->__get((currentIndex - this->widthInTiles)) >= (int)-1)))) && bool((distances->__get((currentIndex + (int)1)) >= (int)-1))))){
						HX_STACK_LINE(2040)
						distances[index] = distance;
						HX_STACK_LINE(2041)
						neighbors->push(index);
					}
					else{
						HX_STACK_LINE(2043)
						if (((bool(!(WideDiagonal)) && bool((distances->__get(index) == (int)-1))))){
							HX_STACK_LINE(2045)
							distances[index] = distance;
							HX_STACK_LINE(2046)
							neighbors->push(index);
						}
					}
				}
				HX_STACK_LINE(2049)
				if (((bool(right) && bool(down)))){
					HX_STACK_LINE(2051)
					index = ((currentIndex + this->widthInTiles) + (int)1);
					HX_STACK_LINE(2053)
					if (((bool((bool((bool(WideDiagonal) && bool((distances->__get(index) == (int)-1)))) && bool((distances->__get((currentIndex + this->widthInTiles)) >= (int)-1)))) && bool((distances->__get((currentIndex + (int)1)) >= (int)-1))))){
						HX_STACK_LINE(2055)
						distances[index] = distance;
						HX_STACK_LINE(2056)
						neighbors->push(index);
					}
					else{
						HX_STACK_LINE(2058)
						if (((bool(!(WideDiagonal)) && bool((distances->__get(index) == (int)-1))))){
							HX_STACK_LINE(2060)
							distances[index] = distance;
							HX_STACK_LINE(2061)
							neighbors->push(index);
						}
					}
				}
				HX_STACK_LINE(2064)
				if (((bool(left) && bool(down)))){
					HX_STACK_LINE(2066)
					index = ((currentIndex + this->widthInTiles) - (int)1);
					HX_STACK_LINE(2068)
					if (((bool((bool((bool(WideDiagonal) && bool((distances->__get(index) == (int)-1)))) && bool((distances->__get((currentIndex + this->widthInTiles)) >= (int)-1)))) && bool((distances->__get((currentIndex - (int)1)) >= (int)-1))))){
						HX_STACK_LINE(2070)
						distances[index] = distance;
						HX_STACK_LINE(2071)
						neighbors->push(index);
					}
					else{
						HX_STACK_LINE(2073)
						if (((bool(!(WideDiagonal)) && bool((distances->__get(index) == (int)-1))))){
							HX_STACK_LINE(2075)
							distances[index] = distance;
							HX_STACK_LINE(2076)
							neighbors->push(index);
						}
					}
				}
				HX_STACK_LINE(2079)
				if (((bool(up) && bool(left)))){
					HX_STACK_LINE(2081)
					index = ((currentIndex - this->widthInTiles) - (int)1);
					HX_STACK_LINE(2083)
					if (((bool((bool((bool(WideDiagonal) && bool((distances->__get(index) == (int)-1)))) && bool((distances->__get((currentIndex - this->widthInTiles)) >= (int)-1)))) && bool((distances->__get((currentIndex - (int)1)) >= (int)-1))))){
						HX_STACK_LINE(2085)
						distances[index] = distance;
						HX_STACK_LINE(2086)
						neighbors->push(index);
					}
					else{
						HX_STACK_LINE(2088)
						if (((bool(!(WideDiagonal)) && bool((distances->__get(index) == (int)-1))))){
							HX_STACK_LINE(2090)
							distances[index] = distance;
							HX_STACK_LINE(2091)
							neighbors->push(index);
						}
					}
				}
			}
			HX_STACK_LINE(2096)
			(distance)++;
		}
		HX_STACK_LINE(2098)
		if ((!(foundEnd))){
			HX_STACK_LINE(2100)
			distances = null();
		}
		HX_STACK_LINE(2103)
		return distances;
	}
}


HX_DEFINE_DYNAMIC_FUNC4(FlxTilemap_obj,computePathDistance,return )

Void FlxTilemap_obj::walkPath( Array< int > Data,int Start,Array< ::Dynamic > Points){
{
		HX_STACK_FRAME("flixel.tile.FlxTilemap","walkPath",0xd33d3b12,"flixel.tile.FlxTilemap.walkPath","flixel/tile/FlxTilemap.hx",2114,0x448feb74)
		HX_STACK_THIS(this)
		HX_STACK_ARG(Data,"Data")
		HX_STACK_ARG(Start,"Start")
		HX_STACK_ARG(Points,"Points")
		HX_STACK_LINE(2115)
		Float _g = ((this->x + (::Math_obj::floor(hx::Mod(Start,this->widthInTiles)) * this->_scaledTileWidth)) + (this->_scaledTileWidth * 0.5));		HX_STACK_VAR(_g,"_g");
		HX_STACK_LINE(2115)
		Points->push(::flixel::util::FlxPoint_obj::__new(_g,((this->y + (::Math_obj::floor((Float(Start) / Float(this->widthInTiles))) * this->_scaledTileHeight)) + (this->_scaledTileHeight * 0.5))));
		HX_STACK_LINE(2117)
		if (((Data->__get(Start) == (int)0))){
			HX_STACK_LINE(2119)
			return null();
		}
		HX_STACK_LINE(2123)
		bool left = (hx::Mod(Start,this->widthInTiles) > (int)0);		HX_STACK_VAR(left,"left");
		HX_STACK_LINE(2124)
		bool right = (hx::Mod(Start,this->widthInTiles) < (this->widthInTiles - (int)1));		HX_STACK_VAR(right,"right");
		HX_STACK_LINE(2125)
		bool up = ((Float(Start) / Float(this->widthInTiles)) > (int)0);		HX_STACK_VAR(up,"up");
		HX_STACK_LINE(2126)
		bool down = ((Float(Start) / Float(this->widthInTiles)) < (this->heightInTiles - (int)1));		HX_STACK_VAR(down,"down");
		HX_STACK_LINE(2128)
		int current = Data->__get(Start);		HX_STACK_VAR(current,"current");
		HX_STACK_LINE(2129)
		int i;		HX_STACK_VAR(i,"i");
		HX_STACK_LINE(2131)
		if ((up)){
			HX_STACK_LINE(2133)
			i = (Start - this->widthInTiles);
			HX_STACK_LINE(2135)
			if (((bool((bool((i >= (int)0)) && bool((Data->__get(i) >= (int)0)))) && bool((Data->__get(i) < current))))){
				HX_STACK_LINE(2137)
				return null(this->walkPath(Data,i,Points));
			}
		}
		HX_STACK_LINE(2140)
		if ((right)){
			HX_STACK_LINE(2142)
			i = (Start + (int)1);
			HX_STACK_LINE(2144)
			if (((bool((bool((i >= (int)0)) && bool((Data->__get(i) >= (int)0)))) && bool((Data->__get(i) < current))))){
				HX_STACK_LINE(2146)
				return null(this->walkPath(Data,i,Points));
			}
		}
		HX_STACK_LINE(2149)
		if ((down)){
			HX_STACK_LINE(2151)
			i = (Start + this->widthInTiles);
			HX_STACK_LINE(2153)
			if (((bool((bool((i >= (int)0)) && bool((Data->__get(i) >= (int)0)))) && bool((Data->__get(i) < current))))){
				HX_STACK_LINE(2155)
				return null(this->walkPath(Data,i,Points));
			}
		}
		HX_STACK_LINE(2158)
		if ((left)){
			HX_STACK_LINE(2160)
			i = (Start - (int)1);
			HX_STACK_LINE(2162)
			if (((bool((bool((i >= (int)0)) && bool((Data->__get(i) >= (int)0)))) && bool((Data->__get(i) < current))))){
				HX_STACK_LINE(2164)
				return null(this->walkPath(Data,i,Points));
			}
		}
		HX_STACK_LINE(2167)
		if (((bool(up) && bool(right)))){
			HX_STACK_LINE(2169)
			i = ((Start - this->widthInTiles) + (int)1);
			HX_STACK_LINE(2171)
			if (((bool((bool((i >= (int)0)) && bool((Data->__get(i) >= (int)0)))) && bool((Data->__get(i) < current))))){
				HX_STACK_LINE(2173)
				return null(this->walkPath(Data,i,Points));
			}
		}
		HX_STACK_LINE(2176)
		if (((bool(right) && bool(down)))){
			HX_STACK_LINE(2178)
			i = ((Start + this->widthInTiles) + (int)1);
			HX_STACK_LINE(2180)
			if (((bool((bool((i >= (int)0)) && bool((Data->__get(i) >= (int)0)))) && bool((Data->__get(i) < current))))){
				HX_STACK_LINE(2182)
				return null(this->walkPath(Data,i,Points));
			}
		}
		HX_STACK_LINE(2185)
		if (((bool(left) && bool(down)))){
			HX_STACK_LINE(2187)
			i = ((Start + this->widthInTiles) - (int)1);
			HX_STACK_LINE(2189)
			if (((bool((bool((i >= (int)0)) && bool((Data->__get(i) >= (int)0)))) && bool((Data->__get(i) < current))))){
				HX_STACK_LINE(2191)
				return null(this->walkPath(Data,i,Points));
			}
		}
		HX_STACK_LINE(2194)
		if (((bool(up) && bool(left)))){
			HX_STACK_LINE(2196)
			i = ((Start - this->widthInTiles) - (int)1);
			HX_STACK_LINE(2198)
			if (((bool((bool((i >= (int)0)) && bool((Data->__get(i) >= (int)0)))) && bool((Data->__get(i) < current))))){
				HX_STACK_LINE(2200)
				return null(this->walkPath(Data,i,Points));
			}
		}
		HX_STACK_LINE(2204)
		return null();
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC3(FlxTilemap_obj,walkPath,(void))

Void FlxTilemap_obj::updateTile( int Index){
{
		HX_STACK_FRAME("flixel.tile.FlxTilemap","updateTile",0x18c3429b,"flixel.tile.FlxTilemap.updateTile","flixel/tile/FlxTilemap.hx",2213,0x448feb74)
		HX_STACK_THIS(this)
		HX_STACK_ARG(Index,"Index")
		HX_STACK_LINE(2214)
		::flixel::tile::FlxTile tile = this->_tileObjects->__get(this->_data->__get(Index)).StaticCast< ::flixel::tile::FlxTile >();		HX_STACK_VAR(tile,"tile");
		HX_STACK_LINE(2216)
		if (((bool((tile == null())) || bool(!(tile->visible))))){
			HX_STACK_LINE(2221)
			this->_rectIDs[Index] = (int)-1;
			HX_STACK_LINE(2224)
			return null();
		}
		HX_STACK_LINE(2238)
		this->_rectIDs[Index] = this->framesData->frames->__get((this->_data->__get(Index) - this->_startingIndex)).StaticCast< ::flixel::system::layer::frames::FlxFrame >()->tileID;
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC1(FlxTilemap_obj,updateTile,(void))

Void FlxTilemap_obj::autoTile( int Index){
{
		HX_STACK_FRAME("flixel.tile.FlxTilemap","autoTile",0xabb4ce01,"flixel.tile.FlxTilemap.autoTile","flixel/tile/FlxTilemap.hx",2248,0x448feb74)
		HX_STACK_THIS(this)
		HX_STACK_ARG(Index,"Index")
		HX_STACK_LINE(2249)
		if (((this->_data->__get(Index) == (int)0))){
			HX_STACK_LINE(2251)
			return null();
		}
		HX_STACK_LINE(2254)
		this->_data[Index] = (int)0;
		HX_STACK_LINE(2257)
		if (((bool(((Index - this->widthInTiles) < (int)0)) || bool((this->_data->__get((Index - this->widthInTiles)) > (int)0))))){
			HX_STACK_LINE(2259)
			hx::AddEq(this->_data[Index],(int)1);
		}
		HX_STACK_LINE(2262)
		if (((bool((hx::Mod(Index,this->widthInTiles) >= (this->widthInTiles - (int)1))) || bool((this->_data->__get((Index + (int)1)) > (int)0))))){
			HX_STACK_LINE(2264)
			hx::AddEq(this->_data[Index],(int)2);
		}
		HX_STACK_LINE(2267)
		if (((  ((!(((::Std_obj::_int((Index + this->widthInTiles)) >= this->totalTiles))))) ? bool((this->_data->__get((Index + this->widthInTiles)) > (int)0)) : bool(true) ))){
			HX_STACK_LINE(2269)
			hx::AddEq(this->_data[Index],(int)4);
		}
		HX_STACK_LINE(2272)
		if (((bool((hx::Mod(Index,this->widthInTiles) <= (int)0)) || bool((this->_data->__get((Index - (int)1)) > (int)0))))){
			HX_STACK_LINE(2274)
			hx::AddEq(this->_data[Index],(int)8);
		}
		HX_STACK_LINE(2278)
		if (((bool((this->_auto == (int)2)) && bool((this->_data->__get(Index) == (int)15))))){
			HX_STACK_LINE(2281)
			if (((  (((  (((hx::Mod(Index,this->widthInTiles) > (int)0))) ? bool((::Std_obj::_int((Index + this->widthInTiles)) < this->totalTiles)) : bool(false) ))) ? bool((this->_data->__get(((Index + this->widthInTiles) - (int)1)) <= (int)0)) : bool(false) ))){
				HX_STACK_LINE(2283)
				this->_data[Index] = (int)1;
			}
			HX_STACK_LINE(2286)
			if (((bool((bool((hx::Mod(Index,this->widthInTiles) > (int)0)) && bool(((Index - this->widthInTiles) >= (int)0)))) && bool((this->_data->__get(((Index - this->widthInTiles) - (int)1)) <= (int)0))))){
				HX_STACK_LINE(2288)
				this->_data[Index] = (int)2;
			}
			HX_STACK_LINE(2291)
			if (((bool((bool((hx::Mod(Index,this->widthInTiles) < (this->widthInTiles - (int)1))) && bool(((Index - this->widthInTiles) >= (int)0)))) && bool((this->_data->__get(((Index - this->widthInTiles) + (int)1)) <= (int)0))))){
				HX_STACK_LINE(2293)
				this->_data[Index] = (int)4;
			}
			HX_STACK_LINE(2296)
			if (((  (((  (((hx::Mod(Index,this->widthInTiles) < (this->widthInTiles - (int)1)))) ? bool((::Std_obj::_int((Index + this->widthInTiles)) < this->totalTiles)) : bool(false) ))) ? bool((this->_data->__get(((Index + this->widthInTiles) + (int)1)) <= (int)0)) : bool(false) ))){
				HX_STACK_LINE(2298)
				this->_data[Index] = (int)8;
			}
		}
		HX_STACK_LINE(2302)
		hx::AddEq(this->_data[Index],(int)1);
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC1(FlxTilemap_obj,autoTile,(void))

bool FlxTilemap_obj::set_forceComplexRender( bool Value){
	HX_STACK_FRAME("flixel.tile.FlxTilemap","set_forceComplexRender",0x65b6293c,"flixel.tile.FlxTilemap.set_forceComplexRender","flixel/tile/FlxTilemap.hx",2306,0x448feb74)
	HX_STACK_THIS(this)
	HX_STACK_ARG(Value,"Value")
	HX_STACK_LINE(2307)
	int i = (int)0;		HX_STACK_VAR(i,"i");
	HX_STACK_LINE(2308)
	int l;		HX_STACK_VAR(l,"l");
	HX_STACK_LINE(2310)
	if (((this->_buffers != null()))){
		HX_STACK_LINE(2312)
		i = (int)0;
		HX_STACK_LINE(2313)
		l = this->_buffers->length;
		HX_STACK_LINE(2315)
		{
			HX_STACK_LINE(2315)
			int _g = (int)0;		HX_STACK_VAR(_g,"_g");
			HX_STACK_LINE(2315)
			while(((_g < l))){
				HX_STACK_LINE(2315)
				int i1 = (_g)++;		HX_STACK_VAR(i1,"i1");
				HX_STACK_LINE(2317)
				this->_buffers->__get(i1).StaticCast< ::flixel::tile::FlxTilemapBuffer >()->forceComplexRender = Value;
			}
		}
	}
	HX_STACK_LINE(2321)
	return this->super::set_forceComplexRender(Value);
}


Float FlxTilemap_obj::set_scaleX( Float Scale){
	HX_STACK_FRAME("flixel.tile.FlxTilemap","set_scaleX",0x433c858f,"flixel.tile.FlxTilemap.set_scaleX","flixel/tile/FlxTilemap.hx",2325,0x448feb74)
	HX_STACK_THIS(this)
	HX_STACK_ARG(Scale,"Scale")
	HX_STACK_LINE(2326)
	Scale = ::Math_obj::abs(Scale);
	HX_STACK_LINE(2327)
	this->scaleX = Scale;
	HX_STACK_LINE(2328)
	this->_scaledTileWidth = (this->_tileWidth * Scale);
	HX_STACK_LINE(2329)
	this->set_width((this->widthInTiles * this->_scaledTileWidth));
	HX_STACK_LINE(2331)
	if (((this->cameras != null()))){
		HX_STACK_LINE(2333)
		int i = (int)0;		HX_STACK_VAR(i,"i");
		HX_STACK_LINE(2334)
		int l = this->cameras->length;		HX_STACK_VAR(l,"l");
		HX_STACK_LINE(2335)
		while(((i < l))){
			HX_STACK_LINE(2337)
			if (((this->_buffers->__get(i).StaticCast< ::flixel::tile::FlxTilemapBuffer >() != null()))){
				HX_STACK_LINE(2339)
				this->_buffers->__get(i).StaticCast< ::flixel::tile::FlxTilemapBuffer >()->updateColumns(this->_tileWidth,this->widthInTiles,Scale,this->cameras->__get(i).StaticCast< ::flixel::FlxCamera >());
			}
			HX_STACK_LINE(2341)
			(i)++;
		}
	}
	HX_STACK_LINE(2345)
	return Scale;
}


HX_DEFINE_DYNAMIC_FUNC1(FlxTilemap_obj,set_scaleX,return )

Float FlxTilemap_obj::set_scaleY( Float Scale){
	HX_STACK_FRAME("flixel.tile.FlxTilemap","set_scaleY",0x433c8590,"flixel.tile.FlxTilemap.set_scaleY","flixel/tile/FlxTilemap.hx",2349,0x448feb74)
	HX_STACK_THIS(this)
	HX_STACK_ARG(Scale,"Scale")
	HX_STACK_LINE(2350)
	Scale = ::Math_obj::abs(Scale);
	HX_STACK_LINE(2351)
	this->scaleY = Scale;
	HX_STACK_LINE(2352)
	this->_scaledTileHeight = (this->_tileHeight * Scale);
	HX_STACK_LINE(2353)
	this->set_height((this->heightInTiles * this->_scaledTileHeight));
	HX_STACK_LINE(2355)
	if (((this->cameras != null()))){
		HX_STACK_LINE(2357)
		int i = (int)0;		HX_STACK_VAR(i,"i");
		HX_STACK_LINE(2358)
		int l = this->cameras->length;		HX_STACK_VAR(l,"l");
		HX_STACK_LINE(2359)
		while(((i < l))){
			HX_STACK_LINE(2361)
			if (((this->_buffers->__get(i).StaticCast< ::flixel::tile::FlxTilemapBuffer >() != null()))){
				HX_STACK_LINE(2363)
				this->_buffers->__get(i).StaticCast< ::flixel::tile::FlxTilemapBuffer >()->updateRows(this->_tileHeight,this->heightInTiles,Scale,this->cameras->__get(i).StaticCast< ::flixel::FlxCamera >());
			}
			HX_STACK_LINE(2365)
			(i)++;
		}
	}
	HX_STACK_LINE(2369)
	return Scale;
}


HX_DEFINE_DYNAMIC_FUNC1(FlxTilemap_obj,set_scaleY,return )

int FlxTilemap_obj::OFF;

int FlxTilemap_obj::AUTO;

int FlxTilemap_obj::ALT;


FlxTilemap_obj::FlxTilemap_obj()
{
}

void FlxTilemap_obj::__Mark(HX_MARK_PARAMS)
{
	HX_MARK_BEGIN_CLASS(FlxTilemap);
	HX_MARK_MEMBER_NAME(_auto,"auto");
	HX_MARK_MEMBER_NAME(widthInTiles,"widthInTiles");
	HX_MARK_MEMBER_NAME(heightInTiles,"heightInTiles");
	HX_MARK_MEMBER_NAME(totalTiles,"totalTiles");
	HX_MARK_MEMBER_NAME(tileScaleHack,"tileScaleHack");
	HX_MARK_MEMBER_NAME(customTileRemap,"customTileRemap");
	HX_MARK_MEMBER_NAME(scaleX,"scaleX");
	HX_MARK_MEMBER_NAME(scaleY,"scaleY");
	HX_MARK_MEMBER_NAME(_randomIndices,"_randomIndices");
	HX_MARK_MEMBER_NAME(_randomChoices,"_randomChoices");
	HX_MARK_MEMBER_NAME(_randomLambda,"_randomLambda");
	HX_MARK_MEMBER_NAME(_flashPoint,"_flashPoint");
	HX_MARK_MEMBER_NAME(_flashRect,"_flashRect");
	HX_MARK_MEMBER_NAME(_buffers,"_buffers");
	HX_MARK_MEMBER_NAME(_data,"_data");
	HX_MARK_MEMBER_NAME(_tileWidth,"_tileWidth");
	HX_MARK_MEMBER_NAME(_tileHeight,"_tileHeight");
	HX_MARK_MEMBER_NAME(_scaledTileWidth,"_scaledTileWidth");
	HX_MARK_MEMBER_NAME(_scaledTileHeight,"_scaledTileHeight");
	HX_MARK_MEMBER_NAME(_tileObjects,"_tileObjects");
	HX_MARK_MEMBER_NAME(_lastVisualDebug,"_lastVisualDebug");
	HX_MARK_MEMBER_NAME(_startingIndex,"_startingIndex");
	HX_MARK_MEMBER_NAME(_helperPoint,"_helperPoint");
	HX_MARK_MEMBER_NAME(_rectIDs,"_rectIDs");
	::flixel::FlxObject_obj::__Mark(HX_MARK_ARG);
	HX_MARK_END_CLASS();
}

void FlxTilemap_obj::__Visit(HX_VISIT_PARAMS)
{
	HX_VISIT_MEMBER_NAME(_auto,"auto");
	HX_VISIT_MEMBER_NAME(widthInTiles,"widthInTiles");
	HX_VISIT_MEMBER_NAME(heightInTiles,"heightInTiles");
	HX_VISIT_MEMBER_NAME(totalTiles,"totalTiles");
	HX_VISIT_MEMBER_NAME(tileScaleHack,"tileScaleHack");
	HX_VISIT_MEMBER_NAME(customTileRemap,"customTileRemap");
	HX_VISIT_MEMBER_NAME(scaleX,"scaleX");
	HX_VISIT_MEMBER_NAME(scaleY,"scaleY");
	HX_VISIT_MEMBER_NAME(_randomIndices,"_randomIndices");
	HX_VISIT_MEMBER_NAME(_randomChoices,"_randomChoices");
	HX_VISIT_MEMBER_NAME(_randomLambda,"_randomLambda");
	HX_VISIT_MEMBER_NAME(_flashPoint,"_flashPoint");
	HX_VISIT_MEMBER_NAME(_flashRect,"_flashRect");
	HX_VISIT_MEMBER_NAME(_buffers,"_buffers");
	HX_VISIT_MEMBER_NAME(_data,"_data");
	HX_VISIT_MEMBER_NAME(_tileWidth,"_tileWidth");
	HX_VISIT_MEMBER_NAME(_tileHeight,"_tileHeight");
	HX_VISIT_MEMBER_NAME(_scaledTileWidth,"_scaledTileWidth");
	HX_VISIT_MEMBER_NAME(_scaledTileHeight,"_scaledTileHeight");
	HX_VISIT_MEMBER_NAME(_tileObjects,"_tileObjects");
	HX_VISIT_MEMBER_NAME(_lastVisualDebug,"_lastVisualDebug");
	HX_VISIT_MEMBER_NAME(_startingIndex,"_startingIndex");
	HX_VISIT_MEMBER_NAME(_helperPoint,"_helperPoint");
	HX_VISIT_MEMBER_NAME(_rectIDs,"_rectIDs");
	::flixel::FlxObject_obj::__Visit(HX_VISIT_ARG);
}

Dynamic FlxTilemap_obj::__Field(const ::String &inName,bool inCallProp)
{
	switch(inName.length) {
	case 3:
		if (HX_FIELD_EQ(inName,"ray") ) { return ray_dyn(); }
		break;
	case 4:
		if (HX_FIELD_EQ(inName,"auto") ) { return _auto; }
		if (HX_FIELD_EQ(inName,"draw") ) { return draw_dyn(); }
		break;
	case 5:
		if (HX_FIELD_EQ(inName,"_data") ) { return _data; }
		break;
	case 6:
		if (HX_FIELD_EQ(inName,"scaleX") ) { return scaleX; }
		if (HX_FIELD_EQ(inName,"scaleY") ) { return scaleY; }
		if (HX_FIELD_EQ(inName,"update") ) { return update_dyn(); }
		if (HX_FIELD_EQ(inName,"follow") ) { return follow_dyn(); }
		if (HX_FIELD_EQ(inName,"rayHit") ) { return rayHit_dyn(); }
		break;
	case 7:
		if (HX_FIELD_EQ(inName,"destroy") ) { return destroy_dyn(); }
		if (HX_FIELD_EQ(inName,"loadMap") ) { return loadMap_dyn(); }
		if (HX_FIELD_EQ(inName,"getData") ) { return getData_dyn(); }
		if (HX_FIELD_EQ(inName,"getTile") ) { return getTile_dyn(); }
		if (HX_FIELD_EQ(inName,"setTile") ) { return setTile_dyn(); }
		break;
	case 8:
		if (HX_FIELD_EQ(inName,"_buffers") ) { return _buffers; }
		if (HX_FIELD_EQ(inName,"_rectIDs") ) { return _rectIDs; }
		if (HX_FIELD_EQ(inName,"setDirty") ) { return setDirty_dyn(); }
		if (HX_FIELD_EQ(inName,"findPath") ) { return findPath_dyn(); }
		if (HX_FIELD_EQ(inName,"overlaps") ) { return overlaps_dyn(); }
		if (HX_FIELD_EQ(inName,"walkPath") ) { return walkPath_dyn(); }
		if (HX_FIELD_EQ(inName,"autoTile") ) { return autoTile_dyn(); }
		break;
	case 9:
		if (HX_FIELD_EQ(inName,"getBounds") ) { return getBounds_dyn(); }
		break;
	case 10:
		if (HX_FIELD_EQ(inName,"totalTiles") ) { return totalTiles; }
		if (HX_FIELD_EQ(inName,"_flashRect") ) { return _flashRect; }
		if (HX_FIELD_EQ(inName,"_tileWidth") ) { return _tileWidth; }
		if (HX_FIELD_EQ(inName,"overlapsAt") ) { return overlapsAt_dyn(); }
		if (HX_FIELD_EQ(inName,"updateTile") ) { return updateTile_dyn(); }
		if (HX_FIELD_EQ(inName,"set_scaleX") ) { return set_scaleX_dyn(); }
		if (HX_FIELD_EQ(inName,"set_scaleY") ) { return set_scaleY_dyn(); }
		break;
	case 11:
		if (HX_FIELD_EQ(inName,"_flashPoint") ) { return _flashPoint; }
		if (HX_FIELD_EQ(inName,"_tileHeight") ) { return _tileHeight; }
		if (HX_FIELD_EQ(inName,"drawTilemap") ) { return drawTilemap_dyn(); }
		break;
	case 12:
		if (HX_FIELD_EQ(inName,"widthInTiles") ) { return widthInTiles; }
		if (HX_FIELD_EQ(inName,"_tileObjects") ) { return _tileObjects; }
		if (HX_FIELD_EQ(inName,"_helperPoint") ) { return _helperPoint; }
		if (HX_FIELD_EQ(inName,"simplifyPath") ) { return simplifyPath_dyn(); }
		break;
	case 13:
		if (HX_FIELD_EQ(inName,"heightInTiles") ) { return heightInTiles; }
		if (HX_FIELD_EQ(inName,"tileScaleHack") ) { return tileScaleHack; }
		if (HX_FIELD_EQ(inName,"_randomLambda") ) { return _randomLambda; }
		if (HX_FIELD_EQ(inName,"overlapsPoint") ) { return overlapsPoint_dyn(); }
		if (HX_FIELD_EQ(inName,"getTileCoords") ) { return getTileCoords_dyn(); }
		if (HX_FIELD_EQ(inName,"updateBuffers") ) { return updateBuffers_dyn(); }
		break;
	case 14:
		if (HX_FIELD_EQ(inName,"_randomIndices") ) { return _randomIndices; }
		if (HX_FIELD_EQ(inName,"_randomChoices") ) { return _randomChoices; }
		if (HX_FIELD_EQ(inName,"_startingIndex") ) { return _startingIndex; }
		if (HX_FIELD_EQ(inName,"getTileByIndex") ) { return getTileByIndex_dyn(); }
		if (HX_FIELD_EQ(inName,"setTileByIndex") ) { return setTileByIndex_dyn(); }
		break;
	case 15:
		if (HX_FIELD_EQ(inName,"customTileRemap") ) { return customTileRemap; }
		if (HX_FIELD_EQ(inName,"updateFrameData") ) { return updateFrameData_dyn(); }
		if (HX_FIELD_EQ(inName,"tileToFlxSprite") ) { return tileToFlxSprite_dyn(); }
		if (HX_FIELD_EQ(inName,"raySimplifyPath") ) { return raySimplifyPath_dyn(); }
		break;
	case 16:
		if (HX_FIELD_EQ(inName,"_scaledTileWidth") ) { return _scaledTileWidth; }
		if (HX_FIELD_EQ(inName,"_lastVisualDebug") ) { return _lastVisualDebug; }
		if (HX_FIELD_EQ(inName,"getTileInstances") ) { return getTileInstances_dyn(); }
		break;
	case 17:
		if (HX_FIELD_EQ(inName,"_scaledTileHeight") ) { return _scaledTileHeight; }
		if (HX_FIELD_EQ(inName,"drawDebugOnCamera") ) { return drawDebugOnCamera_dyn(); }
		if (HX_FIELD_EQ(inName,"getTileCollisions") ) { return getTileCollisions_dyn(); }
		if (HX_FIELD_EQ(inName,"setTileProperties") ) { return setTileProperties_dyn(); }
		break;
	case 19:
		if (HX_FIELD_EQ(inName,"computePathDistance") ) { return computePathDistance_dyn(); }
		break;
	case 20:
		if (HX_FIELD_EQ(inName,"overlapsWithCallback") ) { return overlapsWithCallback_dyn(); }
		break;
	case 21:
		if (HX_FIELD_EQ(inName,"setCustomTileMappings") ) { return setCustomTileMappings_dyn(); }
		break;
	case 22:
		if (HX_FIELD_EQ(inName,"set_forceComplexRender") ) { return set_forceComplexRender_dyn(); }
	}
	return super::__Field(inName,inCallProp);
}

Dynamic FlxTilemap_obj::__SetField(const ::String &inName,const Dynamic &inValue,bool inCallProp)
{
	switch(inName.length) {
	case 4:
		if (HX_FIELD_EQ(inName,"auto") ) { _auto=inValue.Cast< int >(); return inValue; }
		break;
	case 5:
		if (HX_FIELD_EQ(inName,"_data") ) { _data=inValue.Cast< Array< int > >(); return inValue; }
		break;
	case 6:
		if (HX_FIELD_EQ(inName,"scaleX") ) { if (inCallProp) return set_scaleX(inValue);scaleX=inValue.Cast< Float >(); return inValue; }
		if (HX_FIELD_EQ(inName,"scaleY") ) { if (inCallProp) return set_scaleY(inValue);scaleY=inValue.Cast< Float >(); return inValue; }
		break;
	case 8:
		if (HX_FIELD_EQ(inName,"_buffers") ) { _buffers=inValue.Cast< Array< ::Dynamic > >(); return inValue; }
		if (HX_FIELD_EQ(inName,"_rectIDs") ) { _rectIDs=inValue.Cast< Array< int > >(); return inValue; }
		break;
	case 10:
		if (HX_FIELD_EQ(inName,"totalTiles") ) { totalTiles=inValue.Cast< int >(); return inValue; }
		if (HX_FIELD_EQ(inName,"_flashRect") ) { _flashRect=inValue.Cast< ::flash::geom::Rectangle >(); return inValue; }
		if (HX_FIELD_EQ(inName,"_tileWidth") ) { _tileWidth=inValue.Cast< int >(); return inValue; }
		break;
	case 11:
		if (HX_FIELD_EQ(inName,"_flashPoint") ) { _flashPoint=inValue.Cast< ::flash::geom::Point >(); return inValue; }
		if (HX_FIELD_EQ(inName,"_tileHeight") ) { _tileHeight=inValue.Cast< int >(); return inValue; }
		break;
	case 12:
		if (HX_FIELD_EQ(inName,"widthInTiles") ) { widthInTiles=inValue.Cast< int >(); return inValue; }
		if (HX_FIELD_EQ(inName,"_tileObjects") ) { _tileObjects=inValue.Cast< Array< ::Dynamic > >(); return inValue; }
		if (HX_FIELD_EQ(inName,"_helperPoint") ) { _helperPoint=inValue.Cast< ::flash::geom::Point >(); return inValue; }
		break;
	case 13:
		if (HX_FIELD_EQ(inName,"heightInTiles") ) { heightInTiles=inValue.Cast< int >(); return inValue; }
		if (HX_FIELD_EQ(inName,"tileScaleHack") ) { tileScaleHack=inValue.Cast< Float >(); return inValue; }
		if (HX_FIELD_EQ(inName,"_randomLambda") ) { _randomLambda=inValue.Cast< Dynamic >(); return inValue; }
		break;
	case 14:
		if (HX_FIELD_EQ(inName,"_randomIndices") ) { _randomIndices=inValue.Cast< Array< int > >(); return inValue; }
		if (HX_FIELD_EQ(inName,"_randomChoices") ) { _randomChoices=inValue.Cast< Array< ::Dynamic > >(); return inValue; }
		if (HX_FIELD_EQ(inName,"_startingIndex") ) { _startingIndex=inValue.Cast< int >(); return inValue; }
		break;
	case 15:
		if (HX_FIELD_EQ(inName,"customTileRemap") ) { customTileRemap=inValue.Cast< Array< int > >(); return inValue; }
		break;
	case 16:
		if (HX_FIELD_EQ(inName,"_scaledTileWidth") ) { _scaledTileWidth=inValue.Cast< Float >(); return inValue; }
		if (HX_FIELD_EQ(inName,"_lastVisualDebug") ) { _lastVisualDebug=inValue.Cast< bool >(); return inValue; }
		break;
	case 17:
		if (HX_FIELD_EQ(inName,"_scaledTileHeight") ) { _scaledTileHeight=inValue.Cast< Float >(); return inValue; }
	}
	return super::__SetField(inName,inValue,inCallProp);
}

void FlxTilemap_obj::__GetFields(Array< ::String> &outFields)
{
	outFields->push(HX_CSTRING("auto"));
	outFields->push(HX_CSTRING("widthInTiles"));
	outFields->push(HX_CSTRING("heightInTiles"));
	outFields->push(HX_CSTRING("totalTiles"));
	outFields->push(HX_CSTRING("tileScaleHack"));
	outFields->push(HX_CSTRING("customTileRemap"));
	outFields->push(HX_CSTRING("scaleX"));
	outFields->push(HX_CSTRING("scaleY"));
	outFields->push(HX_CSTRING("_randomIndices"));
	outFields->push(HX_CSTRING("_randomChoices"));
	outFields->push(HX_CSTRING("_flashPoint"));
	outFields->push(HX_CSTRING("_flashRect"));
	outFields->push(HX_CSTRING("_buffers"));
	outFields->push(HX_CSTRING("_data"));
	outFields->push(HX_CSTRING("_tileWidth"));
	outFields->push(HX_CSTRING("_tileHeight"));
	outFields->push(HX_CSTRING("_scaledTileWidth"));
	outFields->push(HX_CSTRING("_scaledTileHeight"));
	outFields->push(HX_CSTRING("_tileObjects"));
	outFields->push(HX_CSTRING("_lastVisualDebug"));
	outFields->push(HX_CSTRING("_startingIndex"));
	outFields->push(HX_CSTRING("_helperPoint"));
	outFields->push(HX_CSTRING("_rectIDs"));
	super::__GetFields(outFields);
};

static ::String sStaticFields[] = {
	HX_CSTRING("OFF"),
	HX_CSTRING("AUTO"),
	HX_CSTRING("ALT"),
	String(null()) };

#if HXCPP_SCRIPTABLE
static hx::StorageInfo sMemberStorageInfo[] = {
	{hx::fsInt,(int)offsetof(FlxTilemap_obj,_auto),HX_CSTRING("auto")},
	{hx::fsInt,(int)offsetof(FlxTilemap_obj,widthInTiles),HX_CSTRING("widthInTiles")},
	{hx::fsInt,(int)offsetof(FlxTilemap_obj,heightInTiles),HX_CSTRING("heightInTiles")},
	{hx::fsInt,(int)offsetof(FlxTilemap_obj,totalTiles),HX_CSTRING("totalTiles")},
	{hx::fsFloat,(int)offsetof(FlxTilemap_obj,tileScaleHack),HX_CSTRING("tileScaleHack")},
	{hx::fsObject /*Array< int >*/ ,(int)offsetof(FlxTilemap_obj,customTileRemap),HX_CSTRING("customTileRemap")},
	{hx::fsFloat,(int)offsetof(FlxTilemap_obj,scaleX),HX_CSTRING("scaleX")},
	{hx::fsFloat,(int)offsetof(FlxTilemap_obj,scaleY),HX_CSTRING("scaleY")},
	{hx::fsObject /*Array< int >*/ ,(int)offsetof(FlxTilemap_obj,_randomIndices),HX_CSTRING("_randomIndices")},
	{hx::fsObject /*Array< ::Dynamic >*/ ,(int)offsetof(FlxTilemap_obj,_randomChoices),HX_CSTRING("_randomChoices")},
	{hx::fsObject /*Dynamic*/ ,(int)offsetof(FlxTilemap_obj,_randomLambda),HX_CSTRING("_randomLambda")},
	{hx::fsObject /*::flash::geom::Point*/ ,(int)offsetof(FlxTilemap_obj,_flashPoint),HX_CSTRING("_flashPoint")},
	{hx::fsObject /*::flash::geom::Rectangle*/ ,(int)offsetof(FlxTilemap_obj,_flashRect),HX_CSTRING("_flashRect")},
	{hx::fsObject /*Array< ::Dynamic >*/ ,(int)offsetof(FlxTilemap_obj,_buffers),HX_CSTRING("_buffers")},
	{hx::fsObject /*Array< int >*/ ,(int)offsetof(FlxTilemap_obj,_data),HX_CSTRING("_data")},
	{hx::fsInt,(int)offsetof(FlxTilemap_obj,_tileWidth),HX_CSTRING("_tileWidth")},
	{hx::fsInt,(int)offsetof(FlxTilemap_obj,_tileHeight),HX_CSTRING("_tileHeight")},
	{hx::fsFloat,(int)offsetof(FlxTilemap_obj,_scaledTileWidth),HX_CSTRING("_scaledTileWidth")},
	{hx::fsFloat,(int)offsetof(FlxTilemap_obj,_scaledTileHeight),HX_CSTRING("_scaledTileHeight")},
	{hx::fsObject /*Array< ::Dynamic >*/ ,(int)offsetof(FlxTilemap_obj,_tileObjects),HX_CSTRING("_tileObjects")},
	{hx::fsBool,(int)offsetof(FlxTilemap_obj,_lastVisualDebug),HX_CSTRING("_lastVisualDebug")},
	{hx::fsInt,(int)offsetof(FlxTilemap_obj,_startingIndex),HX_CSTRING("_startingIndex")},
	{hx::fsObject /*::flash::geom::Point*/ ,(int)offsetof(FlxTilemap_obj,_helperPoint),HX_CSTRING("_helperPoint")},
	{hx::fsObject /*Array< int >*/ ,(int)offsetof(FlxTilemap_obj,_rectIDs),HX_CSTRING("_rectIDs")},
	{ hx::fsUnknown, 0, null()}
};
#endif

static ::String sMemberFields[] = {
	HX_CSTRING("auto"),
	HX_CSTRING("widthInTiles"),
	HX_CSTRING("heightInTiles"),
	HX_CSTRING("totalTiles"),
	HX_CSTRING("tileScaleHack"),
	HX_CSTRING("customTileRemap"),
	HX_CSTRING("scaleX"),
	HX_CSTRING("scaleY"),
	HX_CSTRING("_randomIndices"),
	HX_CSTRING("_randomChoices"),
	HX_CSTRING("_randomLambda"),
	HX_CSTRING("_flashPoint"),
	HX_CSTRING("_flashRect"),
	HX_CSTRING("_buffers"),
	HX_CSTRING("_data"),
	HX_CSTRING("_tileWidth"),
	HX_CSTRING("_tileHeight"),
	HX_CSTRING("_scaledTileWidth"),
	HX_CSTRING("_scaledTileHeight"),
	HX_CSTRING("_tileObjects"),
	HX_CSTRING("_lastVisualDebug"),
	HX_CSTRING("_startingIndex"),
	HX_CSTRING("_helperPoint"),
	HX_CSTRING("_rectIDs"),
	HX_CSTRING("destroy"),
	HX_CSTRING("loadMap"),
	HX_CSTRING("setCustomTileMappings"),
	HX_CSTRING("update"),
	HX_CSTRING("drawDebugOnCamera"),
	HX_CSTRING("draw"),
	HX_CSTRING("getData"),
	HX_CSTRING("setDirty"),
	HX_CSTRING("findPath"),
	HX_CSTRING("overlaps"),
	HX_CSTRING("overlapsAt"),
	HX_CSTRING("overlapsWithCallback"),
	HX_CSTRING("overlapsPoint"),
	HX_CSTRING("getTile"),
	HX_CSTRING("getTileByIndex"),
	HX_CSTRING("getTileCollisions"),
	HX_CSTRING("getTileInstances"),
	HX_CSTRING("getTileCoords"),
	HX_CSTRING("setTile"),
	HX_CSTRING("setTileByIndex"),
	HX_CSTRING("setTileProperties"),
	HX_CSTRING("follow"),
	HX_CSTRING("getBounds"),
	HX_CSTRING("ray"),
	HX_CSTRING("rayHit"),
	HX_CSTRING("updateFrameData"),
	HX_CSTRING("tileToFlxSprite"),
	HX_CSTRING("updateBuffers"),
	HX_CSTRING("drawTilemap"),
	HX_CSTRING("simplifyPath"),
	HX_CSTRING("raySimplifyPath"),
	HX_CSTRING("computePathDistance"),
	HX_CSTRING("walkPath"),
	HX_CSTRING("updateTile"),
	HX_CSTRING("autoTile"),
	HX_CSTRING("set_forceComplexRender"),
	HX_CSTRING("set_scaleX"),
	HX_CSTRING("set_scaleY"),
	String(null()) };

static void sMarkStatics(HX_MARK_PARAMS) {
	HX_MARK_MEMBER_NAME(FlxTilemap_obj::__mClass,"__mClass");
	HX_MARK_MEMBER_NAME(FlxTilemap_obj::OFF,"OFF");
	HX_MARK_MEMBER_NAME(FlxTilemap_obj::AUTO,"AUTO");
	HX_MARK_MEMBER_NAME(FlxTilemap_obj::ALT,"ALT");
};

#ifdef HXCPP_VISIT_ALLOCS
static void sVisitStatics(HX_VISIT_PARAMS) {
	HX_VISIT_MEMBER_NAME(FlxTilemap_obj::__mClass,"__mClass");
	HX_VISIT_MEMBER_NAME(FlxTilemap_obj::OFF,"OFF");
	HX_VISIT_MEMBER_NAME(FlxTilemap_obj::AUTO,"AUTO");
	HX_VISIT_MEMBER_NAME(FlxTilemap_obj::ALT,"ALT");
};

#endif

Class FlxTilemap_obj::__mClass;

void FlxTilemap_obj::__register()
{
	hx::Static(__mClass) = hx::RegisterClass(HX_CSTRING("flixel.tile.FlxTilemap"), hx::TCanCast< FlxTilemap_obj> ,sStaticFields,sMemberFields,
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

void FlxTilemap_obj::__boot()
{
	OFF= (int)0;
	AUTO= (int)1;
	ALT= (int)2;
}

} // end namespace flixel
} // end namespace tile
