#include <hxcpp.h>

#ifndef INCLUDED_Std
#include <Std.h>
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
#ifndef INCLUDED_flixel_interfaces_IFlxDestroyable
#include <flixel/interfaces/IFlxDestroyable.h>
#endif
#ifndef INCLUDED_flixel_system_layer_TileSheetData
#include <flixel/system/layer/TileSheetData.h>
#endif
#ifndef INCLUDED_flixel_system_layer_frames_FlxFrame
#include <flixel/system/layer/frames/FlxFrame.h>
#endif
#ifndef INCLUDED_flixel_util_FlxAngle
#include <flixel/util/FlxAngle.h>
#endif
#ifndef INCLUDED_flixel_util_FlxPoint
#include <flixel/util/FlxPoint.h>
#endif
namespace flixel{
namespace system{
namespace layer{
namespace frames{

Void FlxFrame_obj::__construct(::flixel::system::layer::TileSheetData tileSheet)
{
HX_STACK_FRAME("flixel.system.layer.frames.FlxFrame","new",0x842bb9ab,"flixel.system.layer.frames.FlxFrame.new","flixel/system/layer/frames/FlxFrame.hx",12,0x455cb825)

HX_STACK_ARG(tileSheet,"tileSheet")
{
	HX_STACK_LINE(24)
	this->additionalAngle = (int)0;
	HX_STACK_LINE(23)
	this->tileID = (int)-1;
	HX_STACK_LINE(21)
	this->trimmed = false;
	HX_STACK_LINE(20)
	this->rotated = false;
	HX_STACK_LINE(38)
	this->_tileSheet = tileSheet;
	HX_STACK_LINE(39)
	this->additionalAngle = (int)0;
	HX_STACK_LINE(41)
	this->sourceSize = ::flixel::util::FlxPoint_obj::__new(null(),null());
	HX_STACK_LINE(42)
	this->offset = ::flixel::util::FlxPoint_obj::__new(null(),null());
	HX_STACK_LINE(43)
	this->center = ::flixel::util::FlxPoint_obj::__new(null(),null());
}
;
	return null();
}

//FlxFrame_obj::~FlxFrame_obj() { }

Dynamic FlxFrame_obj::__CreateEmpty() { return  new FlxFrame_obj; }
hx::ObjectPtr< FlxFrame_obj > FlxFrame_obj::__new(::flixel::system::layer::TileSheetData tileSheet)
{  hx::ObjectPtr< FlxFrame_obj > result = new FlxFrame_obj();
	result->__construct(tileSheet);
	return result;}

Dynamic FlxFrame_obj::__Create(hx::DynamicArray inArgs)
{  hx::ObjectPtr< FlxFrame_obj > result = new FlxFrame_obj();
	result->__construct(inArgs[0]);
	return result;}

::flash::display::BitmapData FlxFrame_obj::getBitmap( ){
	HX_STACK_FRAME("flixel.system.layer.frames.FlxFrame","getBitmap",0x24590cb0,"flixel.system.layer.frames.FlxFrame.getBitmap","flixel/system/layer/frames/FlxFrame.hx",47,0x455cb825)
	HX_STACK_THIS(this)
	HX_STACK_LINE(48)
	if (((this->_bitmapData != null()))){
		HX_STACK_LINE(50)
		return this->_bitmapData;
	}
	HX_STACK_LINE(53)
	int _g = ::Std_obj::_int(this->sourceSize->x);		HX_STACK_VAR(_g,"_g");
	HX_STACK_LINE(53)
	this->_bitmapData = ::flash::display::BitmapData_obj::__new(_g,::Std_obj::_int(this->sourceSize->y),true,(int)0,null());
	HX_STACK_LINE(55)
	if ((this->rotated)){
		HX_STACK_LINE(57)
		int _g1 = ::Std_obj::_int(this->frame->width);		HX_STACK_VAR(_g1,"_g1");
		HX_STACK_LINE(57)
		::flash::display::BitmapData temp = ::flash::display::BitmapData_obj::__new(_g1,::Std_obj::_int(this->frame->height),true,(int)0,null());		HX_STACK_VAR(temp,"temp");
		HX_STACK_LINE(58)
		::flixel::system::layer::frames::FlxFrame_obj::POINT->x = ::flixel::system::layer::frames::FlxFrame_obj::POINT->y = (int)0;
		HX_STACK_LINE(59)
		temp->copyPixels(this->_tileSheet->bitmap,this->frame,::flixel::system::layer::frames::FlxFrame_obj::POINT,null(),null(),null());
		HX_STACK_LINE(61)
		::flixel::system::layer::frames::FlxFrame_obj::MATRIX->identity();
		HX_STACK_LINE(62)
		::flixel::system::layer::frames::FlxFrame_obj::MATRIX->translate((-0.5 * this->frame->width),(-0.5 * this->frame->height));
		HX_STACK_LINE(63)
		::flixel::system::layer::frames::FlxFrame_obj::MATRIX->rotate((-90. * ::flixel::util::FlxAngle_obj::TO_RAD));
		HX_STACK_LINE(64)
		::flixel::system::layer::frames::FlxFrame_obj::MATRIX->translate((this->offset->x + (0.5 * this->frame->height)),(this->offset->y + (0.5 * this->frame->width)));
		HX_STACK_LINE(66)
		this->_bitmapData->draw(temp,::flixel::system::layer::frames::FlxFrame_obj::MATRIX,null(),null(),null(),null());
		HX_STACK_LINE(67)
		temp->dispose();
	}
	else{
		HX_STACK_LINE(71)
		::flixel::system::layer::frames::FlxFrame_obj::POINT->x = this->offset->x;
		HX_STACK_LINE(72)
		::flixel::system::layer::frames::FlxFrame_obj::POINT->y = this->offset->y;
		HX_STACK_LINE(73)
		this->_bitmapData->copyPixels(this->_tileSheet->bitmap,this->frame,::flixel::system::layer::frames::FlxFrame_obj::POINT,null(),null(),null());
	}
	HX_STACK_LINE(76)
	return this->_bitmapData;
}


HX_DEFINE_DYNAMIC_FUNC0(FlxFrame_obj,getBitmap,return )

::flash::display::BitmapData FlxFrame_obj::getHReversedBitmap( ){
	HX_STACK_FRAME("flixel.system.layer.frames.FlxFrame","getHReversedBitmap",0x2e895438,"flixel.system.layer.frames.FlxFrame.getHReversedBitmap","flixel/system/layer/frames/FlxFrame.hx",80,0x455cb825)
	HX_STACK_THIS(this)
	HX_STACK_LINE(81)
	if (((this->_hReversedBitmapData != null()))){
		HX_STACK_LINE(83)
		return this->_hReversedBitmapData;
	}
	HX_STACK_LINE(86)
	::flash::display::BitmapData normalFrame = this->getBitmap();		HX_STACK_VAR(normalFrame,"normalFrame");
	HX_STACK_LINE(87)
	::flixel::system::layer::frames::FlxFrame_obj::MATRIX->identity();
	HX_STACK_LINE(88)
	::flixel::system::layer::frames::FlxFrame_obj::MATRIX->scale((int)-1,(int)1);
	HX_STACK_LINE(89)
	::flixel::system::layer::frames::FlxFrame_obj::MATRIX->translate(::Std_obj::_int(this->sourceSize->x),(int)0);
	HX_STACK_LINE(90)
	int _g = ::Std_obj::_int(this->sourceSize->x);		HX_STACK_VAR(_g,"_g");
	HX_STACK_LINE(90)
	this->_hReversedBitmapData = ::flash::display::BitmapData_obj::__new(_g,::Std_obj::_int(this->sourceSize->y),true,(int)0,null());
	HX_STACK_LINE(91)
	this->_hReversedBitmapData->draw(normalFrame,::flixel::system::layer::frames::FlxFrame_obj::MATRIX,null(),null(),null(),null());
	HX_STACK_LINE(93)
	return this->_hReversedBitmapData;
}


HX_DEFINE_DYNAMIC_FUNC0(FlxFrame_obj,getHReversedBitmap,return )

::flash::display::BitmapData FlxFrame_obj::getVReversedBitmap( ){
	HX_STACK_FRAME("flixel.system.layer.frames.FlxFrame","getVReversedBitmap",0x544c10c6,"flixel.system.layer.frames.FlxFrame.getVReversedBitmap","flixel/system/layer/frames/FlxFrame.hx",97,0x455cb825)
	HX_STACK_THIS(this)
	HX_STACK_LINE(98)
	if (((this->_vReversedBitmapData != null()))){
		HX_STACK_LINE(100)
		return this->_vReversedBitmapData;
	}
	HX_STACK_LINE(103)
	::flash::display::BitmapData normalFrame = this->getBitmap();		HX_STACK_VAR(normalFrame,"normalFrame");
	HX_STACK_LINE(104)
	::flixel::system::layer::frames::FlxFrame_obj::MATRIX->identity();
	HX_STACK_LINE(105)
	::flixel::system::layer::frames::FlxFrame_obj::MATRIX->scale((int)1,(int)-1);
	HX_STACK_LINE(106)
	::flixel::system::layer::frames::FlxFrame_obj::MATRIX->translate((int)0,::Std_obj::_int(this->sourceSize->y));
	HX_STACK_LINE(107)
	int _g = ::Std_obj::_int(this->sourceSize->x);		HX_STACK_VAR(_g,"_g");
	HX_STACK_LINE(107)
	this->_vReversedBitmapData = ::flash::display::BitmapData_obj::__new(_g,::Std_obj::_int(this->sourceSize->y),true,(int)0,null());
	HX_STACK_LINE(108)
	this->_vReversedBitmapData->draw(normalFrame,::flixel::system::layer::frames::FlxFrame_obj::MATRIX,null(),null(),null(),null());
	HX_STACK_LINE(110)
	return this->_vReversedBitmapData;
}


HX_DEFINE_DYNAMIC_FUNC0(FlxFrame_obj,getVReversedBitmap,return )

::flash::display::BitmapData FlxFrame_obj::getHVReversedBitmap( ){
	HX_STACK_FRAME("flixel.system.layer.frames.FlxFrame","getHVReversedBitmap",0x3a9fc220,"flixel.system.layer.frames.FlxFrame.getHVReversedBitmap","flixel/system/layer/frames/FlxFrame.hx",114,0x455cb825)
	HX_STACK_THIS(this)
	HX_STACK_LINE(115)
	if (((this->_hvReversedBitmapData != null()))){
		HX_STACK_LINE(117)
		return this->_hvReversedBitmapData;
	}
	HX_STACK_LINE(120)
	::flash::display::BitmapData normalFrame = this->getBitmap();		HX_STACK_VAR(normalFrame,"normalFrame");
	HX_STACK_LINE(121)
	::flixel::system::layer::frames::FlxFrame_obj::MATRIX->identity();
	HX_STACK_LINE(122)
	::flixel::system::layer::frames::FlxFrame_obj::MATRIX->scale((int)-1,(int)-1);
	HX_STACK_LINE(123)
	int _g = ::Std_obj::_int(this->sourceSize->x);		HX_STACK_VAR(_g,"_g");
	HX_STACK_LINE(123)
	::flixel::system::layer::frames::FlxFrame_obj::MATRIX->translate(_g,::Std_obj::_int(this->sourceSize->y));
	HX_STACK_LINE(124)
	int _g1 = ::Std_obj::_int(this->sourceSize->x);		HX_STACK_VAR(_g1,"_g1");
	HX_STACK_LINE(124)
	this->_hvReversedBitmapData = ::flash::display::BitmapData_obj::__new(_g1,::Std_obj::_int(this->sourceSize->y),true,(int)0,null());
	HX_STACK_LINE(125)
	this->_hvReversedBitmapData->draw(normalFrame,::flixel::system::layer::frames::FlxFrame_obj::MATRIX,null(),null(),null(),null());
	HX_STACK_LINE(127)
	return this->_hvReversedBitmapData;
}


HX_DEFINE_DYNAMIC_FUNC0(FlxFrame_obj,getHVReversedBitmap,return )

Void FlxFrame_obj::destroy( ){
{
		HX_STACK_FRAME("flixel.system.layer.frames.FlxFrame","destroy",0x6c1417c5,"flixel.system.layer.frames.FlxFrame.destroy","flixel/system/layer/frames/FlxFrame.hx",131,0x455cb825)
		HX_STACK_THIS(this)
		HX_STACK_LINE(132)
		this->name = null();
		HX_STACK_LINE(133)
		this->frame = null();
		HX_STACK_LINE(135)
		this->sourceSize = null();
		HX_STACK_LINE(136)
		this->offset = null();
		HX_STACK_LINE(137)
		this->center = null();
		HX_STACK_LINE(139)
		this->_tileSheet = null();
		HX_STACK_LINE(141)
		this->destroyBitmapDatas();
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC0(FlxFrame_obj,destroy,(void))

Void FlxFrame_obj::destroyBitmapDatas( ){
{
		HX_STACK_FRAME("flixel.system.layer.frames.FlxFrame","destroyBitmapDatas",0x68a588d5,"flixel.system.layer.frames.FlxFrame.destroyBitmapDatas","flixel/system/layer/frames/FlxFrame.hx",145,0x455cb825)
		HX_STACK_THIS(this)
		HX_STACK_LINE(146)
		if (((this->_bitmapData != null()))){
			HX_STACK_LINE(148)
			this->_bitmapData->dispose();
			HX_STACK_LINE(149)
			this->_bitmapData = null();
		}
		HX_STACK_LINE(152)
		if (((this->_hReversedBitmapData != null()))){
			HX_STACK_LINE(154)
			this->_hReversedBitmapData->dispose();
			HX_STACK_LINE(155)
			this->_hReversedBitmapData = null();
		}
		HX_STACK_LINE(158)
		if (((this->_vReversedBitmapData != null()))){
			HX_STACK_LINE(160)
			this->_vReversedBitmapData->dispose();
			HX_STACK_LINE(161)
			this->_vReversedBitmapData = null();
		}
		HX_STACK_LINE(164)
		if (((this->_hvReversedBitmapData != null()))){
			HX_STACK_LINE(166)
			this->_hvReversedBitmapData->dispose();
			HX_STACK_LINE(167)
			this->_hvReversedBitmapData = null();
		}
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC0(FlxFrame_obj,destroyBitmapDatas,(void))

::flash::geom::Point FlxFrame_obj::POINT;

::flash::geom::Matrix FlxFrame_obj::MATRIX;


FlxFrame_obj::FlxFrame_obj()
{
}

void FlxFrame_obj::__Mark(HX_MARK_PARAMS)
{
	HX_MARK_BEGIN_CLASS(FlxFrame);
	HX_MARK_MEMBER_NAME(name,"name");
	HX_MARK_MEMBER_NAME(frame,"frame");
	HX_MARK_MEMBER_NAME(rotated,"rotated");
	HX_MARK_MEMBER_NAME(trimmed,"trimmed");
	HX_MARK_MEMBER_NAME(tileID,"tileID");
	HX_MARK_MEMBER_NAME(additionalAngle,"additionalAngle");
	HX_MARK_MEMBER_NAME(sourceSize,"sourceSize");
	HX_MARK_MEMBER_NAME(offset,"offset");
	HX_MARK_MEMBER_NAME(center,"center");
	HX_MARK_MEMBER_NAME(_bitmapData,"_bitmapData");
	HX_MARK_MEMBER_NAME(_hReversedBitmapData,"_hReversedBitmapData");
	HX_MARK_MEMBER_NAME(_vReversedBitmapData,"_vReversedBitmapData");
	HX_MARK_MEMBER_NAME(_hvReversedBitmapData,"_hvReversedBitmapData");
	HX_MARK_MEMBER_NAME(_tileSheet,"_tileSheet");
	HX_MARK_END_CLASS();
}

void FlxFrame_obj::__Visit(HX_VISIT_PARAMS)
{
	HX_VISIT_MEMBER_NAME(name,"name");
	HX_VISIT_MEMBER_NAME(frame,"frame");
	HX_VISIT_MEMBER_NAME(rotated,"rotated");
	HX_VISIT_MEMBER_NAME(trimmed,"trimmed");
	HX_VISIT_MEMBER_NAME(tileID,"tileID");
	HX_VISIT_MEMBER_NAME(additionalAngle,"additionalAngle");
	HX_VISIT_MEMBER_NAME(sourceSize,"sourceSize");
	HX_VISIT_MEMBER_NAME(offset,"offset");
	HX_VISIT_MEMBER_NAME(center,"center");
	HX_VISIT_MEMBER_NAME(_bitmapData,"_bitmapData");
	HX_VISIT_MEMBER_NAME(_hReversedBitmapData,"_hReversedBitmapData");
	HX_VISIT_MEMBER_NAME(_vReversedBitmapData,"_vReversedBitmapData");
	HX_VISIT_MEMBER_NAME(_hvReversedBitmapData,"_hvReversedBitmapData");
	HX_VISIT_MEMBER_NAME(_tileSheet,"_tileSheet");
}

Dynamic FlxFrame_obj::__Field(const ::String &inName,bool inCallProp)
{
	switch(inName.length) {
	case 4:
		if (HX_FIELD_EQ(inName,"name") ) { return name; }
		break;
	case 5:
		if (HX_FIELD_EQ(inName,"POINT") ) { return POINT; }
		if (HX_FIELD_EQ(inName,"frame") ) { return frame; }
		break;
	case 6:
		if (HX_FIELD_EQ(inName,"MATRIX") ) { return MATRIX; }
		if (HX_FIELD_EQ(inName,"tileID") ) { return tileID; }
		if (HX_FIELD_EQ(inName,"offset") ) { return offset; }
		if (HX_FIELD_EQ(inName,"center") ) { return center; }
		break;
	case 7:
		if (HX_FIELD_EQ(inName,"rotated") ) { return rotated; }
		if (HX_FIELD_EQ(inName,"trimmed") ) { return trimmed; }
		if (HX_FIELD_EQ(inName,"destroy") ) { return destroy_dyn(); }
		break;
	case 9:
		if (HX_FIELD_EQ(inName,"getBitmap") ) { return getBitmap_dyn(); }
		break;
	case 10:
		if (HX_FIELD_EQ(inName,"sourceSize") ) { return sourceSize; }
		if (HX_FIELD_EQ(inName,"_tileSheet") ) { return _tileSheet; }
		break;
	case 11:
		if (HX_FIELD_EQ(inName,"_bitmapData") ) { return _bitmapData; }
		break;
	case 15:
		if (HX_FIELD_EQ(inName,"additionalAngle") ) { return additionalAngle; }
		break;
	case 18:
		if (HX_FIELD_EQ(inName,"getHReversedBitmap") ) { return getHReversedBitmap_dyn(); }
		if (HX_FIELD_EQ(inName,"getVReversedBitmap") ) { return getVReversedBitmap_dyn(); }
		if (HX_FIELD_EQ(inName,"destroyBitmapDatas") ) { return destroyBitmapDatas_dyn(); }
		break;
	case 19:
		if (HX_FIELD_EQ(inName,"getHVReversedBitmap") ) { return getHVReversedBitmap_dyn(); }
		break;
	case 20:
		if (HX_FIELD_EQ(inName,"_hReversedBitmapData") ) { return _hReversedBitmapData; }
		if (HX_FIELD_EQ(inName,"_vReversedBitmapData") ) { return _vReversedBitmapData; }
		break;
	case 21:
		if (HX_FIELD_EQ(inName,"_hvReversedBitmapData") ) { return _hvReversedBitmapData; }
	}
	return super::__Field(inName,inCallProp);
}

Dynamic FlxFrame_obj::__SetField(const ::String &inName,const Dynamic &inValue,bool inCallProp)
{
	switch(inName.length) {
	case 4:
		if (HX_FIELD_EQ(inName,"name") ) { name=inValue.Cast< ::String >(); return inValue; }
		break;
	case 5:
		if (HX_FIELD_EQ(inName,"POINT") ) { POINT=inValue.Cast< ::flash::geom::Point >(); return inValue; }
		if (HX_FIELD_EQ(inName,"frame") ) { frame=inValue.Cast< ::flash::geom::Rectangle >(); return inValue; }
		break;
	case 6:
		if (HX_FIELD_EQ(inName,"MATRIX") ) { MATRIX=inValue.Cast< ::flash::geom::Matrix >(); return inValue; }
		if (HX_FIELD_EQ(inName,"tileID") ) { tileID=inValue.Cast< int >(); return inValue; }
		if (HX_FIELD_EQ(inName,"offset") ) { offset=inValue.Cast< ::flixel::util::FlxPoint >(); return inValue; }
		if (HX_FIELD_EQ(inName,"center") ) { center=inValue.Cast< ::flixel::util::FlxPoint >(); return inValue; }
		break;
	case 7:
		if (HX_FIELD_EQ(inName,"rotated") ) { rotated=inValue.Cast< bool >(); return inValue; }
		if (HX_FIELD_EQ(inName,"trimmed") ) { trimmed=inValue.Cast< bool >(); return inValue; }
		break;
	case 10:
		if (HX_FIELD_EQ(inName,"sourceSize") ) { sourceSize=inValue.Cast< ::flixel::util::FlxPoint >(); return inValue; }
		if (HX_FIELD_EQ(inName,"_tileSheet") ) { _tileSheet=inValue.Cast< ::flixel::system::layer::TileSheetData >(); return inValue; }
		break;
	case 11:
		if (HX_FIELD_EQ(inName,"_bitmapData") ) { _bitmapData=inValue.Cast< ::flash::display::BitmapData >(); return inValue; }
		break;
	case 15:
		if (HX_FIELD_EQ(inName,"additionalAngle") ) { additionalAngle=inValue.Cast< Float >(); return inValue; }
		break;
	case 20:
		if (HX_FIELD_EQ(inName,"_hReversedBitmapData") ) { _hReversedBitmapData=inValue.Cast< ::flash::display::BitmapData >(); return inValue; }
		if (HX_FIELD_EQ(inName,"_vReversedBitmapData") ) { _vReversedBitmapData=inValue.Cast< ::flash::display::BitmapData >(); return inValue; }
		break;
	case 21:
		if (HX_FIELD_EQ(inName,"_hvReversedBitmapData") ) { _hvReversedBitmapData=inValue.Cast< ::flash::display::BitmapData >(); return inValue; }
	}
	return super::__SetField(inName,inValue,inCallProp);
}

void FlxFrame_obj::__GetFields(Array< ::String> &outFields)
{
	outFields->push(HX_CSTRING("name"));
	outFields->push(HX_CSTRING("frame"));
	outFields->push(HX_CSTRING("rotated"));
	outFields->push(HX_CSTRING("trimmed"));
	outFields->push(HX_CSTRING("tileID"));
	outFields->push(HX_CSTRING("additionalAngle"));
	outFields->push(HX_CSTRING("sourceSize"));
	outFields->push(HX_CSTRING("offset"));
	outFields->push(HX_CSTRING("center"));
	outFields->push(HX_CSTRING("_bitmapData"));
	outFields->push(HX_CSTRING("_hReversedBitmapData"));
	outFields->push(HX_CSTRING("_vReversedBitmapData"));
	outFields->push(HX_CSTRING("_hvReversedBitmapData"));
	outFields->push(HX_CSTRING("_tileSheet"));
	super::__GetFields(outFields);
};

static ::String sStaticFields[] = {
	HX_CSTRING("POINT"),
	HX_CSTRING("MATRIX"),
	String(null()) };

#if HXCPP_SCRIPTABLE
static hx::StorageInfo sMemberStorageInfo[] = {
	{hx::fsString,(int)offsetof(FlxFrame_obj,name),HX_CSTRING("name")},
	{hx::fsObject /*::flash::geom::Rectangle*/ ,(int)offsetof(FlxFrame_obj,frame),HX_CSTRING("frame")},
	{hx::fsBool,(int)offsetof(FlxFrame_obj,rotated),HX_CSTRING("rotated")},
	{hx::fsBool,(int)offsetof(FlxFrame_obj,trimmed),HX_CSTRING("trimmed")},
	{hx::fsInt,(int)offsetof(FlxFrame_obj,tileID),HX_CSTRING("tileID")},
	{hx::fsFloat,(int)offsetof(FlxFrame_obj,additionalAngle),HX_CSTRING("additionalAngle")},
	{hx::fsObject /*::flixel::util::FlxPoint*/ ,(int)offsetof(FlxFrame_obj,sourceSize),HX_CSTRING("sourceSize")},
	{hx::fsObject /*::flixel::util::FlxPoint*/ ,(int)offsetof(FlxFrame_obj,offset),HX_CSTRING("offset")},
	{hx::fsObject /*::flixel::util::FlxPoint*/ ,(int)offsetof(FlxFrame_obj,center),HX_CSTRING("center")},
	{hx::fsObject /*::flash::display::BitmapData*/ ,(int)offsetof(FlxFrame_obj,_bitmapData),HX_CSTRING("_bitmapData")},
	{hx::fsObject /*::flash::display::BitmapData*/ ,(int)offsetof(FlxFrame_obj,_hReversedBitmapData),HX_CSTRING("_hReversedBitmapData")},
	{hx::fsObject /*::flash::display::BitmapData*/ ,(int)offsetof(FlxFrame_obj,_vReversedBitmapData),HX_CSTRING("_vReversedBitmapData")},
	{hx::fsObject /*::flash::display::BitmapData*/ ,(int)offsetof(FlxFrame_obj,_hvReversedBitmapData),HX_CSTRING("_hvReversedBitmapData")},
	{hx::fsObject /*::flixel::system::layer::TileSheetData*/ ,(int)offsetof(FlxFrame_obj,_tileSheet),HX_CSTRING("_tileSheet")},
	{ hx::fsUnknown, 0, null()}
};
#endif

static ::String sMemberFields[] = {
	HX_CSTRING("name"),
	HX_CSTRING("frame"),
	HX_CSTRING("rotated"),
	HX_CSTRING("trimmed"),
	HX_CSTRING("tileID"),
	HX_CSTRING("additionalAngle"),
	HX_CSTRING("sourceSize"),
	HX_CSTRING("offset"),
	HX_CSTRING("center"),
	HX_CSTRING("_bitmapData"),
	HX_CSTRING("_hReversedBitmapData"),
	HX_CSTRING("_vReversedBitmapData"),
	HX_CSTRING("_hvReversedBitmapData"),
	HX_CSTRING("_tileSheet"),
	HX_CSTRING("getBitmap"),
	HX_CSTRING("getHReversedBitmap"),
	HX_CSTRING("getVReversedBitmap"),
	HX_CSTRING("getHVReversedBitmap"),
	HX_CSTRING("destroy"),
	HX_CSTRING("destroyBitmapDatas"),
	String(null()) };

static void sMarkStatics(HX_MARK_PARAMS) {
	HX_MARK_MEMBER_NAME(FlxFrame_obj::__mClass,"__mClass");
	HX_MARK_MEMBER_NAME(FlxFrame_obj::POINT,"POINT");
	HX_MARK_MEMBER_NAME(FlxFrame_obj::MATRIX,"MATRIX");
};

#ifdef HXCPP_VISIT_ALLOCS
static void sVisitStatics(HX_VISIT_PARAMS) {
	HX_VISIT_MEMBER_NAME(FlxFrame_obj::__mClass,"__mClass");
	HX_VISIT_MEMBER_NAME(FlxFrame_obj::POINT,"POINT");
	HX_VISIT_MEMBER_NAME(FlxFrame_obj::MATRIX,"MATRIX");
};

#endif

Class FlxFrame_obj::__mClass;

void FlxFrame_obj::__register()
{
	hx::Static(__mClass) = hx::RegisterClass(HX_CSTRING("flixel.system.layer.frames.FlxFrame"), hx::TCanCast< FlxFrame_obj> ,sStaticFields,sMemberFields,
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

void FlxFrame_obj::__boot()
{
	POINT= ::flash::geom::Point_obj::__new(null(),null());
	MATRIX= ::flash::geom::Matrix_obj::__new(null(),null(),null(),null(),null(),null());
}

} // end namespace flixel
} // end namespace system
} // end namespace layer
} // end namespace frames
