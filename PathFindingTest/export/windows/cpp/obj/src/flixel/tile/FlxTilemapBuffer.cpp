#include <hxcpp.h>

#ifndef INCLUDED_Std
#include <Std.h>
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
#ifndef INCLUDED_flixel_interfaces_IFlxDestroyable
#include <flixel/interfaces/IFlxDestroyable.h>
#endif
#ifndef INCLUDED_flixel_tile_FlxTilemapBuffer
#include <flixel/tile/FlxTilemapBuffer.h>
#endif
#ifndef INCLUDED_hxMath
#include <hxMath.h>
#endif
namespace flixel{
namespace tile{

Void FlxTilemapBuffer_obj::__construct(int TileWidth,int TileHeight,int WidthInTiles,int HeightInTiles,::flixel::FlxCamera Camera,hx::Null< Float >  __o_ScaleX,hx::Null< Float >  __o_ScaleY)
{
HX_STACK_FRAME("flixel.tile.FlxTilemapBuffer","new",0x92818fbc,"flixel.tile.FlxTilemapBuffer.new","flixel/tile/FlxTilemapBuffer.hx",14,0x56d29ad4)

HX_STACK_ARG(TileWidth,"TileWidth")

HX_STACK_ARG(TileHeight,"TileHeight")

HX_STACK_ARG(WidthInTiles,"WidthInTiles")

HX_STACK_ARG(HeightInTiles,"HeightInTiles")

HX_STACK_ARG(Camera,"Camera")

HX_STACK_ARG(__o_ScaleX,"ScaleX")

HX_STACK_ARG(__o_ScaleY,"ScaleY")
Float ScaleX = __o_ScaleX.Default(1.0);
Float ScaleY = __o_ScaleY.Default(1.0);
{
	HX_STACK_LINE(45)
	this->forceComplexRender = false;
	HX_STACK_LINE(64)
	this->updateColumns(TileWidth,WidthInTiles,ScaleX,Camera);
	HX_STACK_LINE(65)
	this->updateRows(TileHeight,HeightInTiles,ScaleY,Camera);
	HX_STACK_LINE(73)
	this->dirty = true;
}
;
	return null();
}

//FlxTilemapBuffer_obj::~FlxTilemapBuffer_obj() { }

Dynamic FlxTilemapBuffer_obj::__CreateEmpty() { return  new FlxTilemapBuffer_obj; }
hx::ObjectPtr< FlxTilemapBuffer_obj > FlxTilemapBuffer_obj::__new(int TileWidth,int TileHeight,int WidthInTiles,int HeightInTiles,::flixel::FlxCamera Camera,hx::Null< Float >  __o_ScaleX,hx::Null< Float >  __o_ScaleY)
{  hx::ObjectPtr< FlxTilemapBuffer_obj > result = new FlxTilemapBuffer_obj();
	result->__construct(TileWidth,TileHeight,WidthInTiles,HeightInTiles,Camera,__o_ScaleX,__o_ScaleY);
	return result;}

Dynamic FlxTilemapBuffer_obj::__Create(hx::DynamicArray inArgs)
{  hx::ObjectPtr< FlxTilemapBuffer_obj > result = new FlxTilemapBuffer_obj();
	result->__construct(inArgs[0],inArgs[1],inArgs[2],inArgs[3],inArgs[4],inArgs[5],inArgs[6]);
	return result;}

Void FlxTilemapBuffer_obj::destroy( ){
{
		HX_STACK_FRAME("flixel.tile.FlxTilemapBuffer","destroy",0x52dcca56,"flixel.tile.FlxTilemapBuffer.destroy","flixel/tile/FlxTilemapBuffer.hx",80,0x56d29ad4)
		HX_STACK_THIS(this)
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC0(FlxTilemapBuffer_obj,destroy,(void))

Void FlxTilemapBuffer_obj::updateColumns( int TileWidth,int WidthInTiles,hx::Null< Float >  __o_ScaleX,::flixel::FlxCamera Camera){
Float ScaleX = __o_ScaleX.Default(1.0);
	HX_STACK_FRAME("flixel.tile.FlxTilemapBuffer","updateColumns",0xed291c30,"flixel.tile.FlxTilemapBuffer.updateColumns","flixel/tile/FlxTilemapBuffer.hx",134,0x56d29ad4)
	HX_STACK_THIS(this)
	HX_STACK_ARG(TileWidth,"TileWidth")
	HX_STACK_ARG(WidthInTiles,"WidthInTiles")
	HX_STACK_ARG(ScaleX,"ScaleX")
	HX_STACK_ARG(Camera,"Camera")
{
		HX_STACK_LINE(135)
		if (((WidthInTiles < (int)0))){
			HX_STACK_LINE(137)
			WidthInTiles = (int)0;
		}
		HX_STACK_LINE(140)
		if (((Camera == null()))){
			HX_STACK_LINE(142)
			Camera = ::flixel::FlxG_obj::camera;
		}
		HX_STACK_LINE(145)
		this->columns = (::Math_obj::ceil((Float(Camera->width) / Float(((TileWidth * ScaleX))))) + (int)1);
		HX_STACK_LINE(147)
		if (((this->columns > WidthInTiles))){
			HX_STACK_LINE(149)
			this->columns = WidthInTiles;
		}
		HX_STACK_LINE(152)
		this->width = ::Std_obj::_int(((this->columns * TileWidth) * ScaleX));
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC4(FlxTilemapBuffer_obj,updateColumns,(void))

Void FlxTilemapBuffer_obj::updateRows( int TileHeight,int HeightInTiles,hx::Null< Float >  __o_ScaleY,::flixel::FlxCamera Camera){
Float ScaleY = __o_ScaleY.Default(1.0);
	HX_STACK_FRAME("flixel.tile.FlxTilemapBuffer","updateRows",0xf31d03e6,"flixel.tile.FlxTilemapBuffer.updateRows","flixel/tile/FlxTilemapBuffer.hx",156,0x56d29ad4)
	HX_STACK_THIS(this)
	HX_STACK_ARG(TileHeight,"TileHeight")
	HX_STACK_ARG(HeightInTiles,"HeightInTiles")
	HX_STACK_ARG(ScaleY,"ScaleY")
	HX_STACK_ARG(Camera,"Camera")
{
		HX_STACK_LINE(157)
		if (((HeightInTiles < (int)0))){
			HX_STACK_LINE(159)
			HeightInTiles = (int)0;
		}
		HX_STACK_LINE(162)
		if (((Camera == null()))){
			HX_STACK_LINE(164)
			Camera = ::flixel::FlxG_obj::camera;
		}
		HX_STACK_LINE(167)
		this->rows = (::Math_obj::ceil((Float(Camera->height) / Float(((TileHeight * ScaleY))))) + (int)1);
		HX_STACK_LINE(169)
		if (((this->rows > HeightInTiles))){
			HX_STACK_LINE(171)
			this->rows = HeightInTiles;
		}
		HX_STACK_LINE(174)
		this->height = ::Std_obj::_int(((this->rows * TileHeight) * ScaleY));
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC4(FlxTilemapBuffer_obj,updateRows,(void))


FlxTilemapBuffer_obj::FlxTilemapBuffer_obj()
{
}

Dynamic FlxTilemapBuffer_obj::__Field(const ::String &inName,bool inCallProp)
{
	switch(inName.length) {
	case 1:
		if (HX_FIELD_EQ(inName,"x") ) { return x; }
		if (HX_FIELD_EQ(inName,"y") ) { return y; }
		break;
	case 4:
		if (HX_FIELD_EQ(inName,"rows") ) { return rows; }
		break;
	case 5:
		if (HX_FIELD_EQ(inName,"width") ) { return width; }
		if (HX_FIELD_EQ(inName,"dirty") ) { return dirty; }
		break;
	case 6:
		if (HX_FIELD_EQ(inName,"height") ) { return height; }
		break;
	case 7:
		if (HX_FIELD_EQ(inName,"columns") ) { return columns; }
		if (HX_FIELD_EQ(inName,"destroy") ) { return destroy_dyn(); }
		break;
	case 10:
		if (HX_FIELD_EQ(inName,"updateRows") ) { return updateRows_dyn(); }
		break;
	case 13:
		if (HX_FIELD_EQ(inName,"updateColumns") ) { return updateColumns_dyn(); }
		break;
	case 18:
		if (HX_FIELD_EQ(inName,"forceComplexRender") ) { return forceComplexRender; }
	}
	return super::__Field(inName,inCallProp);
}

Dynamic FlxTilemapBuffer_obj::__SetField(const ::String &inName,const Dynamic &inValue,bool inCallProp)
{
	switch(inName.length) {
	case 1:
		if (HX_FIELD_EQ(inName,"x") ) { x=inValue.Cast< Float >(); return inValue; }
		if (HX_FIELD_EQ(inName,"y") ) { y=inValue.Cast< Float >(); return inValue; }
		break;
	case 4:
		if (HX_FIELD_EQ(inName,"rows") ) { rows=inValue.Cast< int >(); return inValue; }
		break;
	case 5:
		if (HX_FIELD_EQ(inName,"width") ) { width=inValue.Cast< Float >(); return inValue; }
		if (HX_FIELD_EQ(inName,"dirty") ) { dirty=inValue.Cast< bool >(); return inValue; }
		break;
	case 6:
		if (HX_FIELD_EQ(inName,"height") ) { height=inValue.Cast< Float >(); return inValue; }
		break;
	case 7:
		if (HX_FIELD_EQ(inName,"columns") ) { columns=inValue.Cast< int >(); return inValue; }
		break;
	case 18:
		if (HX_FIELD_EQ(inName,"forceComplexRender") ) { forceComplexRender=inValue.Cast< bool >(); return inValue; }
	}
	return super::__SetField(inName,inValue,inCallProp);
}

void FlxTilemapBuffer_obj::__GetFields(Array< ::String> &outFields)
{
	outFields->push(HX_CSTRING("x"));
	outFields->push(HX_CSTRING("y"));
	outFields->push(HX_CSTRING("width"));
	outFields->push(HX_CSTRING("height"));
	outFields->push(HX_CSTRING("dirty"));
	outFields->push(HX_CSTRING("rows"));
	outFields->push(HX_CSTRING("columns"));
	outFields->push(HX_CSTRING("forceComplexRender"));
	super::__GetFields(outFields);
};

static ::String sStaticFields[] = {
	String(null()) };

#if HXCPP_SCRIPTABLE
static hx::StorageInfo sMemberStorageInfo[] = {
	{hx::fsFloat,(int)offsetof(FlxTilemapBuffer_obj,x),HX_CSTRING("x")},
	{hx::fsFloat,(int)offsetof(FlxTilemapBuffer_obj,y),HX_CSTRING("y")},
	{hx::fsFloat,(int)offsetof(FlxTilemapBuffer_obj,width),HX_CSTRING("width")},
	{hx::fsFloat,(int)offsetof(FlxTilemapBuffer_obj,height),HX_CSTRING("height")},
	{hx::fsBool,(int)offsetof(FlxTilemapBuffer_obj,dirty),HX_CSTRING("dirty")},
	{hx::fsInt,(int)offsetof(FlxTilemapBuffer_obj,rows),HX_CSTRING("rows")},
	{hx::fsInt,(int)offsetof(FlxTilemapBuffer_obj,columns),HX_CSTRING("columns")},
	{hx::fsBool,(int)offsetof(FlxTilemapBuffer_obj,forceComplexRender),HX_CSTRING("forceComplexRender")},
	{ hx::fsUnknown, 0, null()}
};
#endif

static ::String sMemberFields[] = {
	HX_CSTRING("x"),
	HX_CSTRING("y"),
	HX_CSTRING("width"),
	HX_CSTRING("height"),
	HX_CSTRING("dirty"),
	HX_CSTRING("rows"),
	HX_CSTRING("columns"),
	HX_CSTRING("forceComplexRender"),
	HX_CSTRING("destroy"),
	HX_CSTRING("updateColumns"),
	HX_CSTRING("updateRows"),
	String(null()) };

static void sMarkStatics(HX_MARK_PARAMS) {
	HX_MARK_MEMBER_NAME(FlxTilemapBuffer_obj::__mClass,"__mClass");
};

#ifdef HXCPP_VISIT_ALLOCS
static void sVisitStatics(HX_VISIT_PARAMS) {
	HX_VISIT_MEMBER_NAME(FlxTilemapBuffer_obj::__mClass,"__mClass");
};

#endif

Class FlxTilemapBuffer_obj::__mClass;

void FlxTilemapBuffer_obj::__register()
{
	hx::Static(__mClass) = hx::RegisterClass(HX_CSTRING("flixel.tile.FlxTilemapBuffer"), hx::TCanCast< FlxTilemapBuffer_obj> ,sStaticFields,sMemberFields,
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

void FlxTilemapBuffer_obj::__boot()
{
}

} // end namespace flixel
} // end namespace tile
