#include <hxcpp.h>

#ifndef INCLUDED_IMap
#include <IMap.h>
#endif
#ifndef INCLUDED_Std
#include <Std.h>
#endif
#ifndef INCLUDED_Type
#include <Type.h>
#endif
#ifndef INCLUDED_flash_display_BitmapData
#include <flash/display/BitmapData.h>
#endif
#ifndef INCLUDED_flash_display_IBitmapDrawable
#include <flash/display/IBitmapDrawable.h>
#endif
#ifndef INCLUDED_flash_geom_Point
#include <flash/geom/Point.h>
#endif
#ifndef INCLUDED_flash_geom_Rectangle
#include <flash/geom/Rectangle.h>
#endif
#ifndef INCLUDED_flixel_interfaces_IFlxDestroyable
#include <flixel/interfaces/IFlxDestroyable.h>
#endif
#ifndef INCLUDED_flixel_system_frontEnds_BitmapFrontEnd
#include <flixel/system/frontEnds/BitmapFrontEnd.h>
#endif
#ifndef INCLUDED_flixel_system_layer_TileSheetData
#include <flixel/system/layer/TileSheetData.h>
#endif
#ifndef INCLUDED_flixel_system_layer_TileSheetExt
#include <flixel/system/layer/TileSheetExt.h>
#endif
#ifndef INCLUDED_flixel_util_loaders_CachedGraphics
#include <flixel/util/loaders/CachedGraphics.h>
#endif
#ifndef INCLUDED_flixel_util_loaders_TextureRegion
#include <flixel/util/loaders/TextureRegion.h>
#endif
#ifndef INCLUDED_haxe_ds_StringMap
#include <haxe/ds/StringMap.h>
#endif
#ifndef INCLUDED_openfl_AssetCache
#include <openfl/AssetCache.h>
#endif
#ifndef INCLUDED_openfl_Assets
#include <openfl/Assets.h>
#endif
#ifndef INCLUDED_openfl_display_Tilesheet
#include <openfl/display/Tilesheet.h>
#endif
namespace flixel{
namespace system{
namespace frontEnds{

Void BitmapFrontEnd_obj::__construct()
{
HX_STACK_FRAME("flixel.system.frontEnds.BitmapFrontEnd","new",0x0f2331ed,"flixel.system.frontEnds.BitmapFrontEnd.new","flixel/system/frontEnds/BitmapFrontEnd.hx",21,0x91a05ae2)
{
	HX_STACK_LINE(21)
	this->clearCache();
}
;
	return null();
}

//BitmapFrontEnd_obj::~BitmapFrontEnd_obj() { }

Dynamic BitmapFrontEnd_obj::__CreateEmpty() { return  new BitmapFrontEnd_obj; }
hx::ObjectPtr< BitmapFrontEnd_obj > BitmapFrontEnd_obj::__new()
{  hx::ObjectPtr< BitmapFrontEnd_obj > result = new BitmapFrontEnd_obj();
	result->__construct();
	return result;}

Dynamic BitmapFrontEnd_obj::__Create(hx::DynamicArray inArgs)
{  hx::ObjectPtr< BitmapFrontEnd_obj > result = new BitmapFrontEnd_obj();
	result->__construct();
	return result;}

::flixel::util::loaders::CachedGraphics BitmapFrontEnd_obj::get_whitePixel( ){
	HX_STACK_FRAME("flixel.system.frontEnds.BitmapFrontEnd","get_whitePixel",0xa476cef9,"flixel.system.frontEnds.BitmapFrontEnd.get_whitePixel","flixel/system/frontEnds/BitmapFrontEnd.hx",30,0x91a05ae2)
	HX_STACK_THIS(this)
	HX_STACK_LINE(31)
	if (((this->_whitePixel == null()))){
		HX_STACK_LINE(33)
		::flash::display::BitmapData bd = ::flash::display::BitmapData_obj::__new((int)2,(int)2,true,(int)-1,null());		HX_STACK_VAR(bd,"bd");
		HX_STACK_LINE(34)
		this->_whitePixel = ::flixel::util::loaders::CachedGraphics_obj::__new(HX_CSTRING("whitePixel"),bd,true);
		HX_STACK_LINE(35)
		{
			HX_STACK_LINE(35)
			::flixel::system::layer::TileSheetData _this = this->_whitePixel->get_tilesheet();		HX_STACK_VAR(_this,"_this");
			HX_STACK_LINE(35)
			::flash::geom::Rectangle tileRect = ::flash::geom::Rectangle_obj::__new((int)0,(int)0,(int)1,(int)1);		HX_STACK_VAR(tileRect,"tileRect");
			HX_STACK_LINE(35)
			::flash::geom::Point point = ::flash::geom::Point_obj::__new((int)0,(int)0);		HX_STACK_VAR(point,"point");
			HX_STACK_LINE(35)
			_this->tileSheet->addTileRectID(tileRect,point);
		}
	}
	HX_STACK_LINE(38)
	return this->_whitePixel;
}


HX_DEFINE_DYNAMIC_FUNC0(BitmapFrontEnd_obj,get_whitePixel,return )

Void BitmapFrontEnd_obj::onContext( ){
{
		HX_STACK_FRAME("flixel.system.frontEnds.BitmapFrontEnd","onContext",0x0e82d7dd,"flixel.system.frontEnds.BitmapFrontEnd.onContext","flixel/system/frontEnds/BitmapFrontEnd.hx",42,0x91a05ae2)
		HX_STACK_THIS(this)
		HX_STACK_LINE(43)
		::flixel::util::loaders::CachedGraphics obj;		HX_STACK_VAR(obj,"obj");
		HX_STACK_LINE(45)
		if (((this->_cache != null()))){
			HX_STACK_LINE(47)
			for(::cpp::FastIterator_obj< ::String > *__it = ::cpp::CreateFastIterator< ::String >(this->_cache->keys());  __it->hasNext(); ){
				::String key = __it->next();
				{
					HX_STACK_LINE(49)
					obj = this->_cache->get(key);
					HX_STACK_LINE(50)
					if (((bool((obj != null())) && bool(obj->isDumped)))){
						HX_STACK_LINE(52)
						obj->onContext();
					}
				}
;
			}
		}
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC0(BitmapFrontEnd_obj,onContext,(void))

Void BitmapFrontEnd_obj::dumpCache( ){
{
		HX_STACK_FRAME("flixel.system.frontEnds.BitmapFrontEnd","dumpCache",0xf899b9bb,"flixel.system.frontEnds.BitmapFrontEnd.dumpCache","flixel/system/frontEnds/BitmapFrontEnd.hx",64,0x91a05ae2)
		HX_STACK_THIS(this)
		HX_STACK_LINE(66)
		::flixel::util::loaders::CachedGraphics obj;		HX_STACK_VAR(obj,"obj");
		HX_STACK_LINE(68)
		if (((this->_cache != null()))){
			HX_STACK_LINE(70)
			for(::cpp::FastIterator_obj< ::String > *__it = ::cpp::CreateFastIterator< ::String >(this->_cache->keys());  __it->hasNext(); ){
				::String key = __it->next();
				{
					HX_STACK_LINE(72)
					obj = this->_cache->get(key);
					HX_STACK_LINE(73)
					if (((bool((obj != null())) && bool(((bool((obj->assetsClass != null())) || bool((obj->assetsKey != null())))))))){
						HX_STACK_LINE(75)
						obj->dump();
					}
				}
;
			}
		}
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC0(BitmapFrontEnd_obj,dumpCache,(void))

bool BitmapFrontEnd_obj::checkCache( ::String Key){
	HX_STACK_FRAME("flixel.system.frontEnds.BitmapFrontEnd","checkCache",0xe81c366d,"flixel.system.frontEnds.BitmapFrontEnd.checkCache","flixel/system/frontEnds/BitmapFrontEnd.hx",90,0x91a05ae2)
	HX_STACK_THIS(this)
	HX_STACK_ARG(Key,"Key")
	HX_STACK_LINE(90)
	if ((this->_cache->exists(Key))){
		HX_STACK_LINE(90)
		return (this->_cache->get(Key) != null());
	}
	else{
		HX_STACK_LINE(90)
		return false;
	}
	HX_STACK_LINE(90)
	return false;
}


HX_DEFINE_DYNAMIC_FUNC1(BitmapFrontEnd_obj,checkCache,return )

::flixel::util::loaders::CachedGraphics BitmapFrontEnd_obj::create( int Width,int Height,int Color,hx::Null< bool >  __o_Unique,::String Key){
bool Unique = __o_Unique.Default(false);
	HX_STACK_FRAME("flixel.system.frontEnds.BitmapFrontEnd","create",0xd385bb8f,"flixel.system.frontEnds.BitmapFrontEnd.create","flixel/system/frontEnds/BitmapFrontEnd.hx",104,0x91a05ae2)
	HX_STACK_THIS(this)
	HX_STACK_ARG(Width,"Width")
	HX_STACK_ARG(Height,"Height")
	HX_STACK_ARG(Color,"Color")
	HX_STACK_ARG(Unique,"Unique")
	HX_STACK_ARG(Key,"Key")
{
		HX_STACK_LINE(105)
		::String key = Key;		HX_STACK_VAR(key,"key");
		HX_STACK_LINE(106)
		if (((key == null()))){
			HX_STACK_LINE(108)
			key = ((((Width + HX_CSTRING("x")) + Height) + HX_CSTRING(":")) + Color);
			HX_STACK_LINE(109)
			if (((  ((Unique)) ? bool(this->checkCache(key)) : bool(false) ))){
				HX_STACK_LINE(111)
				key = this->getUniqueKey(key);
			}
		}
		HX_STACK_LINE(114)
		if ((!(this->checkCache(key)))){
			HX_STACK_LINE(116)
			::flixel::util::loaders::CachedGraphics value = ::flixel::util::loaders::CachedGraphics_obj::__new(key,::flash::display::BitmapData_obj::__new(Width,Height,true,Color,null()),null());		HX_STACK_VAR(value,"value");
			HX_STACK_LINE(116)
			this->_cache->set(key,value);
		}
		HX_STACK_LINE(119)
		return this->_cache->get(key);
	}
}


HX_DEFINE_DYNAMIC_FUNC5(BitmapFrontEnd_obj,create,return )

::flixel::util::loaders::CachedGraphics BitmapFrontEnd_obj::add( Dynamic Graphic,hx::Null< bool >  __o_Unique,::String Key){
bool Unique = __o_Unique.Default(false);
	HX_STACK_FRAME("flixel.system.frontEnds.BitmapFrontEnd","add",0x0f1953ae,"flixel.system.frontEnds.BitmapFrontEnd.add","flixel/system/frontEnds/BitmapFrontEnd.hx",132,0x91a05ae2)
	HX_STACK_THIS(this)
	HX_STACK_ARG(Graphic,"Graphic")
	HX_STACK_ARG(Unique,"Unique")
	HX_STACK_ARG(Key,"Key")
{
		HX_STACK_LINE(132)
		return this->addWithSpaces(Graphic,(int)0,(int)0,(int)1,(int)1,Unique,Key);
	}
}


HX_DEFINE_DYNAMIC_FUNC3(BitmapFrontEnd_obj,add,return )

::flixel::util::loaders::CachedGraphics BitmapFrontEnd_obj::addWithSpaces( Dynamic Graphic,int FrameWidth,int FrameHeight,hx::Null< int >  __o_SpacingX,hx::Null< int >  __o_SpacingY,hx::Null< bool >  __o_Unique,::String Key){
int SpacingX = __o_SpacingX.Default(1);
int SpacingY = __o_SpacingY.Default(1);
bool Unique = __o_Unique.Default(false);
	HX_STACK_FRAME("flixel.system.frontEnds.BitmapFrontEnd","addWithSpaces",0x971bd0e1,"flixel.system.frontEnds.BitmapFrontEnd.addWithSpaces","flixel/system/frontEnds/BitmapFrontEnd.hx",149,0x91a05ae2)
	HX_STACK_THIS(this)
	HX_STACK_ARG(Graphic,"Graphic")
	HX_STACK_ARG(FrameWidth,"FrameWidth")
	HX_STACK_ARG(FrameHeight,"FrameHeight")
	HX_STACK_ARG(SpacingX,"SpacingX")
	HX_STACK_ARG(SpacingY,"SpacingY")
	HX_STACK_ARG(Unique,"Unique")
	HX_STACK_ARG(Key,"Key")
{
		HX_STACK_LINE(150)
		if (((Graphic == null()))){
			HX_STACK_LINE(152)
			return null();
		}
		HX_STACK_LINE(155)
		::flixel::util::loaders::TextureRegion region = null();		HX_STACK_VAR(region,"region");
		HX_STACK_LINE(156)
		::flixel::util::loaders::CachedGraphics graphic = null();		HX_STACK_VAR(graphic,"graphic");
		HX_STACK_LINE(158)
		bool isClass = true;		HX_STACK_VAR(isClass,"isClass");
		HX_STACK_LINE(159)
		bool isBitmap = true;		HX_STACK_VAR(isBitmap,"isBitmap");
		HX_STACK_LINE(160)
		bool isRegion = true;		HX_STACK_VAR(isRegion,"isRegion");
		HX_STACK_LINE(161)
		bool isGraphics = true;		HX_STACK_VAR(isGraphics,"isGraphics");
		HX_STACK_LINE(163)
		if ((::Std_obj::is(Graphic,hx::ClassOf< ::flixel::util::loaders::CachedGraphics >()))){
			HX_STACK_LINE(165)
			isClass = false;
			HX_STACK_LINE(166)
			isBitmap = false;
			HX_STACK_LINE(167)
			isRegion = false;
			HX_STACK_LINE(168)
			isGraphics = true;
			HX_STACK_LINE(170)
			graphic = hx::TCast< flixel::util::loaders::CachedGraphics >::cast(Graphic);
			HX_STACK_LINE(172)
			if (((bool(!(Unique)) && bool(((bool((FrameWidth <= (int)0)) && bool((FrameHeight <= (int)0)))))))){
				HX_STACK_LINE(174)
				return graphic;
			}
		}
		else{
			HX_STACK_LINE(177)
			if ((::Std_obj::is(Graphic,hx::ClassOf< ::Class >()))){
				HX_STACK_LINE(179)
				isClass = true;
				HX_STACK_LINE(180)
				isBitmap = false;
				HX_STACK_LINE(181)
				isRegion = false;
				HX_STACK_LINE(182)
				isGraphics = false;
			}
			else{
				HX_STACK_LINE(184)
				if ((::Std_obj::is(Graphic,hx::ClassOf< ::flash::display::BitmapData >()))){
					HX_STACK_LINE(186)
					isClass = false;
					HX_STACK_LINE(187)
					isBitmap = true;
					HX_STACK_LINE(188)
					isRegion = false;
					HX_STACK_LINE(189)
					isGraphics = false;
				}
				else{
					HX_STACK_LINE(191)
					if ((::Std_obj::is(Graphic,hx::ClassOf< ::flixel::util::loaders::TextureRegion >()))){
						HX_STACK_LINE(193)
						isClass = false;
						HX_STACK_LINE(194)
						isBitmap = false;
						HX_STACK_LINE(195)
						isRegion = true;
						HX_STACK_LINE(196)
						isGraphics = false;
						HX_STACK_LINE(198)
						region = hx::TCast< flixel::util::loaders::TextureRegion >::cast(Graphic);
					}
					else{
						HX_STACK_LINE(200)
						if ((::Std_obj::is(Graphic,hx::ClassOf< ::String >()))){
							HX_STACK_LINE(202)
							isClass = false;
							HX_STACK_LINE(203)
							isBitmap = false;
							HX_STACK_LINE(204)
							isRegion = false;
							HX_STACK_LINE(205)
							isGraphics = false;
						}
						else{
							HX_STACK_LINE(209)
							return null();
						}
					}
				}
			}
		}
		HX_STACK_LINE(212)
		::String additionalKey = HX_CSTRING("");		HX_STACK_VAR(additionalKey,"additionalKey");
		HX_STACK_LINE(214)
		if (((bool((FrameWidth > (int)0)) || bool((FrameHeight > (int)0))))){
			HX_STACK_LINE(216)
			additionalKey = (((((((HX_CSTRING("FrameSize:") + FrameWidth) + HX_CSTRING("_")) + FrameHeight) + HX_CSTRING("_Spacing:")) + SpacingX) + HX_CSTRING("_")) + SpacingY);
		}
		HX_STACK_LINE(219)
		::String key = Key;		HX_STACK_VAR(key,"key");
		HX_STACK_LINE(220)
		if (((key == null()))){
			HX_STACK_LINE(222)
			if ((isClass)){
				HX_STACK_LINE(224)
				key = ::Type_obj::getClassName(hx::TCast< Class >::cast(Graphic));
			}
			else{
				HX_STACK_LINE(226)
				if ((isBitmap)){
					HX_STACK_LINE(228)
					if ((!(Unique))){
						HX_STACK_LINE(230)
						key = this->getCacheKeyFor(Graphic);
						HX_STACK_LINE(231)
						if (((key == null()))){
							HX_STACK_LINE(233)
							key = this->getUniqueKey(null());
						}
					}
				}
				else{
					HX_STACK_LINE(237)
					if ((isRegion)){
						HX_STACK_LINE(239)
						key = region->data->key;
					}
					else{
						HX_STACK_LINE(241)
						if ((isGraphics)){
							HX_STACK_LINE(243)
							key = graphic->key;
						}
						else{
							HX_STACK_LINE(247)
							key = Graphic;
						}
					}
				}
			}
			HX_STACK_LINE(250)
			hx::AddEq(key,additionalKey);
			HX_STACK_LINE(252)
			if ((Unique)){
				HX_STACK_LINE(254)
				key = this->getUniqueKey((  (((key == null()))) ? ::String(HX_CSTRING("pixels")) : ::String(key) ));
			}
		}
		HX_STACK_LINE(259)
		if ((!(this->checkCache(key)))){
			HX_STACK_LINE(261)
			::flash::display::BitmapData bd = null();		HX_STACK_VAR(bd,"bd");
			HX_STACK_LINE(262)
			if ((isClass)){
				HX_STACK_LINE(264)
				bd = ::Type_obj::createInstance(hx::TCast< Class >::cast(Graphic),Dynamic( Array_obj<Dynamic>::__new().Add((int)0).Add((int)0)));
			}
			else{
				HX_STACK_LINE(266)
				if ((isBitmap)){
					HX_STACK_LINE(268)
					bd = Graphic;
				}
				else{
					HX_STACK_LINE(270)
					if ((isRegion)){
						HX_STACK_LINE(272)
						bd = region->data->bitmap;
					}
					else{
						HX_STACK_LINE(274)
						if ((isGraphics)){
							HX_STACK_LINE(276)
							bd = graphic->bitmap;
						}
						else{
							HX_STACK_LINE(280)
							::String id = Graphic;		HX_STACK_VAR(id,"id");
							HX_STACK_LINE(280)
							bd = ::openfl::Assets_obj::getBitmapData(id,false);
						}
					}
				}
			}
			HX_STACK_LINE(283)
			if (((bool((FrameWidth > (int)0)) || bool((FrameHeight > (int)0))))){
				HX_STACK_LINE(285)
				int numHorizontalFrames;		HX_STACK_VAR(numHorizontalFrames,"numHorizontalFrames");
				HX_STACK_LINE(285)
				if (((FrameWidth == (int)0))){
					HX_STACK_LINE(285)
					numHorizontalFrames = (int)1;
				}
				else{
					HX_STACK_LINE(285)
					numHorizontalFrames = ::Std_obj::_int((Float(bd->get_width()) / Float(FrameWidth)));
				}
				HX_STACK_LINE(286)
				int numVerticalFrames;		HX_STACK_VAR(numVerticalFrames,"numVerticalFrames");
				HX_STACK_LINE(286)
				if (((FrameHeight == (int)0))){
					HX_STACK_LINE(286)
					numVerticalFrames = (int)1;
				}
				else{
					HX_STACK_LINE(286)
					numVerticalFrames = ::Std_obj::_int((Float(bd->get_height()) / Float(FrameHeight)));
				}
				HX_STACK_LINE(288)
				if (((FrameWidth == (int)0))){
					HX_STACK_LINE(288)
					FrameWidth = bd->get_width();
				}
				else{
					HX_STACK_LINE(288)
					FrameWidth = FrameWidth;
				}
				HX_STACK_LINE(289)
				if (((FrameHeight == (int)0))){
					HX_STACK_LINE(289)
					FrameHeight = bd->get_height();
				}
				else{
					HX_STACK_LINE(289)
					FrameHeight = FrameHeight;
				}
				HX_STACK_LINE(291)
				int _g = (bd->get_width() + (numHorizontalFrames * SpacingX));		HX_STACK_VAR(_g,"_g");
				HX_STACK_LINE(291)
				::flash::display::BitmapData tempBitmap = ::flash::display::BitmapData_obj::__new(_g,(bd->get_height() + (numVerticalFrames * SpacingY)),true,(int)0,null());		HX_STACK_VAR(tempBitmap,"tempBitmap");
				HX_STACK_LINE(292)
				tempBitmap->lock();
				HX_STACK_LINE(293)
				::flash::geom::Rectangle tempRect = ::flash::geom::Rectangle_obj::__new((int)0,(int)0,FrameWidth,FrameHeight);		HX_STACK_VAR(tempRect,"tempRect");
				HX_STACK_LINE(294)
				::flash::geom::Point tempPoint = ::flash::geom::Point_obj::__new(null(),null());		HX_STACK_VAR(tempPoint,"tempPoint");
				HX_STACK_LINE(296)
				{
					HX_STACK_LINE(296)
					int _g1 = (int)0;		HX_STACK_VAR(_g1,"_g1");
					HX_STACK_LINE(296)
					while(((_g1 < numHorizontalFrames))){
						HX_STACK_LINE(296)
						int i = (_g1)++;		HX_STACK_VAR(i,"i");
						HX_STACK_LINE(298)
						tempPoint->x = (i * ((FrameWidth + SpacingX)));
						HX_STACK_LINE(299)
						tempRect->x = (i * FrameWidth);
						HX_STACK_LINE(301)
						{
							HX_STACK_LINE(301)
							int _g2 = (int)0;		HX_STACK_VAR(_g2,"_g2");
							HX_STACK_LINE(301)
							int _g11 = numVerticalFrames;		HX_STACK_VAR(_g11,"_g11");
							HX_STACK_LINE(301)
							while(((_g2 < _g11))){
								HX_STACK_LINE(301)
								int j = (_g2)++;		HX_STACK_VAR(j,"j");
								HX_STACK_LINE(303)
								tempPoint->y = (j * ((FrameHeight + SpacingY)));
								HX_STACK_LINE(304)
								tempRect->y = (j * FrameHeight);
								HX_STACK_LINE(305)
								tempBitmap->copyPixels(bd,tempRect,tempPoint,null(),null(),null());
							}
						}
					}
				}
				HX_STACK_LINE(308)
				tempBitmap->unlock(null());
				HX_STACK_LINE(309)
				bd = tempBitmap;
			}
			HX_STACK_LINE(312)
			if ((Unique)){
				HX_STACK_LINE(314)
				bd = bd->clone();
			}
			HX_STACK_LINE(317)
			::flixel::util::loaders::CachedGraphics co = ::flixel::util::loaders::CachedGraphics_obj::__new(key,bd,null());		HX_STACK_VAR(co,"co");
			HX_STACK_LINE(319)
			if (((bool(isClass) && bool(!(Unique))))){
				HX_STACK_LINE(321)
				co->assetsClass = Graphic;
			}
			else{
				HX_STACK_LINE(323)
				if (((bool((bool((bool(!(isClass)) && bool(!(isBitmap)))) && bool(!(isRegion)))) && bool(!(Unique))))){
					HX_STACK_LINE(325)
					co->assetsKey = Graphic;
				}
			}
			HX_STACK_LINE(328)
			this->_cache->set(key,co);
		}
		HX_STACK_LINE(331)
		return this->_cache->get(key);
	}
}


HX_DEFINE_DYNAMIC_FUNC7(BitmapFrontEnd_obj,addWithSpaces,return )

::flixel::util::loaders::CachedGraphics BitmapFrontEnd_obj::get( ::String key){
	HX_STACK_FRAME("flixel.system.frontEnds.BitmapFrontEnd","get",0x0f1de223,"flixel.system.frontEnds.BitmapFrontEnd.get","flixel/system/frontEnds/BitmapFrontEnd.hx",341,0x91a05ae2)
	HX_STACK_THIS(this)
	HX_STACK_ARG(key,"key")
	HX_STACK_LINE(341)
	return this->_cache->get(key);
}


HX_DEFINE_DYNAMIC_FUNC1(BitmapFrontEnd_obj,get,return )

::String BitmapFrontEnd_obj::getCacheKeyFor( ::flash::display::BitmapData bmd){
	HX_STACK_FRAME("flixel.system.frontEnds.BitmapFrontEnd","getCacheKeyFor",0xfaa1a129,"flixel.system.frontEnds.BitmapFrontEnd.getCacheKeyFor","flixel/system/frontEnds/BitmapFrontEnd.hx",351,0x91a05ae2)
	HX_STACK_THIS(this)
	HX_STACK_ARG(bmd,"bmd")
	HX_STACK_LINE(352)
	for(::cpp::FastIterator_obj< ::String > *__it = ::cpp::CreateFastIterator< ::String >(this->_cache->keys());  __it->hasNext(); ){
		::String key = __it->next();
		{
			HX_STACK_LINE(354)
			::flash::display::BitmapData data = this->_cache->get(key)->__Field(HX_CSTRING("bitmap"),true);		HX_STACK_VAR(data,"data");
			HX_STACK_LINE(355)
			if (((data == bmd))){
				HX_STACK_LINE(357)
				return key;
			}
		}
;
	}
	HX_STACK_LINE(360)
	return null();
}


HX_DEFINE_DYNAMIC_FUNC1(BitmapFrontEnd_obj,getCacheKeyFor,return )

::String BitmapFrontEnd_obj::getUniqueKey( ::String __o_baseKey){
::String baseKey = __o_baseKey.Default(HX_CSTRING("pixels"));
	HX_STACK_FRAME("flixel.system.frontEnds.BitmapFrontEnd","getUniqueKey",0x2898506b,"flixel.system.frontEnds.BitmapFrontEnd.getUniqueKey","flixel/system/frontEnds/BitmapFrontEnd.hx",370,0x91a05ae2)
	HX_STACK_THIS(this)
	HX_STACK_ARG(baseKey,"baseKey")
{
		HX_STACK_LINE(371)
		if ((this->checkCache(baseKey))){
			HX_STACK_LINE(373)
			int inc = (int)0;		HX_STACK_VAR(inc,"inc");
			HX_STACK_LINE(374)
			::String ukey;		HX_STACK_VAR(ukey,"ukey");
			HX_STACK_LINE(375)
			do{
				HX_STACK_LINE(377)
				ukey = (baseKey + (inc)++);
			}
while((this->checkCache(ukey)));
			HX_STACK_LINE(379)
			baseKey = ukey;
		}
		HX_STACK_LINE(381)
		return baseKey;
	}
}


HX_DEFINE_DYNAMIC_FUNC1(BitmapFrontEnd_obj,getUniqueKey,return )

Void BitmapFrontEnd_obj::remove( ::String key){
{
		HX_STACK_FRAME("flixel.system.frontEnds.BitmapFrontEnd","remove",0x5bfef0d7,"flixel.system.frontEnds.BitmapFrontEnd.remove","flixel/system/frontEnds/BitmapFrontEnd.hx",386,0x91a05ae2)
		HX_STACK_THIS(this)
		HX_STACK_ARG(key,"key")
		HX_STACK_LINE(386)
		if (((  (((key != null()))) ? bool(this->_cache->exists(key)) : bool(false) ))){
			HX_STACK_LINE(388)
			::flixel::util::loaders::CachedGraphics obj = this->_cache->get(key);		HX_STACK_VAR(obj,"obj");
			HX_STACK_LINE(389)
			if (((this->inOpenFlAssets(obj->bitmap) == false))){
				HX_STACK_LINE(391)
				this->_cache->remove(key);
				HX_STACK_LINE(392)
				obj->destroy();
			}
		}
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC1(BitmapFrontEnd_obj,remove,(void))

Void BitmapFrontEnd_obj::clearCache( ){
{
		HX_STACK_FRAME("flixel.system.frontEnds.BitmapFrontEnd","clearCache",0xad367388,"flixel.system.frontEnds.BitmapFrontEnd.clearCache","flixel/system/frontEnds/BitmapFrontEnd.hx",401,0x91a05ae2)
		HX_STACK_THIS(this)
		HX_STACK_LINE(402)
		::flixel::util::loaders::CachedGraphics obj;		HX_STACK_VAR(obj,"obj");
		HX_STACK_LINE(404)
		if (((this->_cache == null()))){
			HX_STACK_LINE(406)
			this->_cache = ::haxe::ds::StringMap_obj::__new();
		}
		HX_STACK_LINE(409)
		for(::cpp::FastIterator_obj< ::String > *__it = ::cpp::CreateFastIterator< ::String >(this->_cache->keys());  __it->hasNext(); ){
			::String key = __it->next();
			{
				HX_STACK_LINE(411)
				obj = this->_cache->get(key);
				HX_STACK_LINE(412)
				if (((  (((bool((obj != null())) && bool(!(obj->persist))))) ? bool((this->inOpenFlAssets(obj->bitmap) == false)) : bool(false) ))){
					HX_STACK_LINE(414)
					this->_cache->remove(key);
					HX_STACK_LINE(415)
					obj->destroy();
					HX_STACK_LINE(416)
					obj = null();
				}
			}
;
		}
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC0(BitmapFrontEnd_obj,clearCache,(void))

bool BitmapFrontEnd_obj::inOpenFlAssets( ::flash::display::BitmapData bitmap){
	HX_STACK_FRAME("flixel.system.frontEnds.BitmapFrontEnd","inOpenFlAssets",0xc245f36b,"flixel.system.frontEnds.BitmapFrontEnd.inOpenFlAssets","flixel/system/frontEnds/BitmapFrontEnd.hx",422,0x91a05ae2)
	HX_STACK_THIS(this)
	HX_STACK_ARG(bitmap,"bitmap")
	HX_STACK_LINE(423)
	::haxe::ds::StringMap bitmapDataCache = ::openfl::Assets_obj::cache->bitmapData;		HX_STACK_VAR(bitmapDataCache,"bitmapDataCache");
	HX_STACK_LINE(424)
	if (((bitmapDataCache != null()))){
		HX_STACK_LINE(426)
		for(::cpp::FastIterator_obj< ::flash::display::BitmapData > *__it = ::cpp::CreateFastIterator< ::flash::display::BitmapData >(bitmapDataCache->iterator());  __it->hasNext(); ){
			::flash::display::BitmapData bd = __it->next();
			if (((bd == bitmap))){
				HX_STACK_LINE(430)
				return true;
			}
;
		}
	}
	HX_STACK_LINE(434)
	return false;
}


HX_DEFINE_DYNAMIC_FUNC1(BitmapFrontEnd_obj,inOpenFlAssets,return )


BitmapFrontEnd_obj::BitmapFrontEnd_obj()
{
}

void BitmapFrontEnd_obj::__Mark(HX_MARK_PARAMS)
{
	HX_MARK_BEGIN_CLASS(BitmapFrontEnd);
	HX_MARK_MEMBER_NAME(_cache,"_cache");
	HX_MARK_MEMBER_NAME(whitePixel,"whitePixel");
	HX_MARK_MEMBER_NAME(_whitePixel,"_whitePixel");
	HX_MARK_END_CLASS();
}

void BitmapFrontEnd_obj::__Visit(HX_VISIT_PARAMS)
{
	HX_VISIT_MEMBER_NAME(_cache,"_cache");
	HX_VISIT_MEMBER_NAME(whitePixel,"whitePixel");
	HX_VISIT_MEMBER_NAME(_whitePixel,"_whitePixel");
}

Dynamic BitmapFrontEnd_obj::__Field(const ::String &inName,bool inCallProp)
{
	switch(inName.length) {
	case 3:
		if (HX_FIELD_EQ(inName,"add") ) { return add_dyn(); }
		if (HX_FIELD_EQ(inName,"get") ) { return get_dyn(); }
		break;
	case 6:
		if (HX_FIELD_EQ(inName,"_cache") ) { return _cache; }
		if (HX_FIELD_EQ(inName,"create") ) { return create_dyn(); }
		if (HX_FIELD_EQ(inName,"remove") ) { return remove_dyn(); }
		break;
	case 9:
		if (HX_FIELD_EQ(inName,"onContext") ) { return onContext_dyn(); }
		if (HX_FIELD_EQ(inName,"dumpCache") ) { return dumpCache_dyn(); }
		break;
	case 10:
		if (HX_FIELD_EQ(inName,"whitePixel") ) { return inCallProp ? get_whitePixel() : whitePixel; }
		if (HX_FIELD_EQ(inName,"checkCache") ) { return checkCache_dyn(); }
		if (HX_FIELD_EQ(inName,"clearCache") ) { return clearCache_dyn(); }
		break;
	case 11:
		if (HX_FIELD_EQ(inName,"_whitePixel") ) { return _whitePixel; }
		break;
	case 12:
		if (HX_FIELD_EQ(inName,"getUniqueKey") ) { return getUniqueKey_dyn(); }
		break;
	case 13:
		if (HX_FIELD_EQ(inName,"addWithSpaces") ) { return addWithSpaces_dyn(); }
		break;
	case 14:
		if (HX_FIELD_EQ(inName,"get_whitePixel") ) { return get_whitePixel_dyn(); }
		if (HX_FIELD_EQ(inName,"getCacheKeyFor") ) { return getCacheKeyFor_dyn(); }
		if (HX_FIELD_EQ(inName,"inOpenFlAssets") ) { return inOpenFlAssets_dyn(); }
	}
	return super::__Field(inName,inCallProp);
}

Dynamic BitmapFrontEnd_obj::__SetField(const ::String &inName,const Dynamic &inValue,bool inCallProp)
{
	switch(inName.length) {
	case 6:
		if (HX_FIELD_EQ(inName,"_cache") ) { _cache=inValue.Cast< ::haxe::ds::StringMap >(); return inValue; }
		break;
	case 10:
		if (HX_FIELD_EQ(inName,"whitePixel") ) { whitePixel=inValue.Cast< ::flixel::util::loaders::CachedGraphics >(); return inValue; }
		break;
	case 11:
		if (HX_FIELD_EQ(inName,"_whitePixel") ) { _whitePixel=inValue.Cast< ::flixel::util::loaders::CachedGraphics >(); return inValue; }
	}
	return super::__SetField(inName,inValue,inCallProp);
}

void BitmapFrontEnd_obj::__GetFields(Array< ::String> &outFields)
{
	outFields->push(HX_CSTRING("_cache"));
	outFields->push(HX_CSTRING("whitePixel"));
	outFields->push(HX_CSTRING("_whitePixel"));
	super::__GetFields(outFields);
};

static ::String sStaticFields[] = {
	String(null()) };

#if HXCPP_SCRIPTABLE
static hx::StorageInfo sMemberStorageInfo[] = {
	{hx::fsObject /*::haxe::ds::StringMap*/ ,(int)offsetof(BitmapFrontEnd_obj,_cache),HX_CSTRING("_cache")},
	{hx::fsObject /*::flixel::util::loaders::CachedGraphics*/ ,(int)offsetof(BitmapFrontEnd_obj,whitePixel),HX_CSTRING("whitePixel")},
	{hx::fsObject /*::flixel::util::loaders::CachedGraphics*/ ,(int)offsetof(BitmapFrontEnd_obj,_whitePixel),HX_CSTRING("_whitePixel")},
	{ hx::fsUnknown, 0, null()}
};
#endif

static ::String sMemberFields[] = {
	HX_CSTRING("_cache"),
	HX_CSTRING("whitePixel"),
	HX_CSTRING("_whitePixel"),
	HX_CSTRING("get_whitePixel"),
	HX_CSTRING("onContext"),
	HX_CSTRING("dumpCache"),
	HX_CSTRING("checkCache"),
	HX_CSTRING("create"),
	HX_CSTRING("add"),
	HX_CSTRING("addWithSpaces"),
	HX_CSTRING("get"),
	HX_CSTRING("getCacheKeyFor"),
	HX_CSTRING("getUniqueKey"),
	HX_CSTRING("remove"),
	HX_CSTRING("clearCache"),
	HX_CSTRING("inOpenFlAssets"),
	String(null()) };

static void sMarkStatics(HX_MARK_PARAMS) {
	HX_MARK_MEMBER_NAME(BitmapFrontEnd_obj::__mClass,"__mClass");
};

#ifdef HXCPP_VISIT_ALLOCS
static void sVisitStatics(HX_VISIT_PARAMS) {
	HX_VISIT_MEMBER_NAME(BitmapFrontEnd_obj::__mClass,"__mClass");
};

#endif

Class BitmapFrontEnd_obj::__mClass;

void BitmapFrontEnd_obj::__register()
{
	hx::Static(__mClass) = hx::RegisterClass(HX_CSTRING("flixel.system.frontEnds.BitmapFrontEnd"), hx::TCanCast< BitmapFrontEnd_obj> ,sStaticFields,sMemberFields,
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

void BitmapFrontEnd_obj::__boot()
{
}

} // end namespace flixel
} // end namespace system
} // end namespace frontEnds
