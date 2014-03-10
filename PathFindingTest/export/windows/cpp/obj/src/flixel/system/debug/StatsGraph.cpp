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
#ifndef INCLUDED_flash_display_Shape
#include <flash/display/Shape.h>
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
#ifndef INCLUDED_flash_text_TextField
#include <flash/text/TextField.h>
#endif
#ifndef INCLUDED_flash_text_TextFormat
#include <flash/text/TextFormat.h>
#endif
#ifndef INCLUDED_flash_text_TextFormatAlign
#include <flash/text/TextFormatAlign.h>
#endif
#ifndef INCLUDED_flixel_system_debug_DebuggerUtil
#include <flixel/system/debug/DebuggerUtil.h>
#endif
#ifndef INCLUDED_flixel_system_debug_StatsGraph
#include <flixel/system/debug/StatsGraph.h>
#endif
#ifndef INCLUDED_flixel_util_FlxMath
#include <flixel/util/FlxMath.h>
#endif
#ifndef INCLUDED_hxMath
#include <hxMath.h>
#endif
namespace flixel{
namespace system{
namespace debug{

Void StatsGraph_obj::__construct(int X,int Y,int Width,int Height,int GraphColor,::String Unit)
{
HX_STACK_FRAME("flixel.system.debug.StatsGraph","new",0x163af7c9,"flixel.system.debug.StatsGraph.new","flixel/system/debug/StatsGraph.hx",15,0x92e18906)

HX_STACK_ARG(X,"X")

HX_STACK_ARG(Y,"Y")

HX_STACK_ARG(Width,"Width")

HX_STACK_ARG(Height,"Height")

HX_STACK_ARG(GraphColor,"GraphColor")

HX_STACK_ARG(Unit,"Unit")
{
	HX_STACK_LINE(34)
	this->maxValue = 5e-324;
	HX_STACK_LINE(33)
	this->minValue = 1.79e+308;
	HX_STACK_LINE(50)
	super::__construct();
	HX_STACK_LINE(51)
	this->set_x(X);
	HX_STACK_LINE(52)
	this->set_y(Y);
	HX_STACK_LINE(53)
	this->_width = Width;
	HX_STACK_LINE(54)
	this->_height = Height;
	HX_STACK_LINE(55)
	this->graphColor = GraphColor;
	HX_STACK_LINE(56)
	this->_unit = Unit;
	HX_STACK_LINE(58)
	this->history = Array_obj< Float >::__new();
	HX_STACK_LINE(60)
	this->_axis = ::flash::display::Shape_obj::__new();
	HX_STACK_LINE(61)
	this->_axis->set_x((this->get_x() + (int)50));
	HX_STACK_LINE(63)
	this->maxLabel = ::flixel::system::debug::DebuggerUtil_obj::createTextField((int)0,(int)0,(int)-1426063361,(int)11);
	HX_STACK_LINE(64)
	this->curLabel = ::flixel::system::debug::DebuggerUtil_obj::createTextField((int)0,((Float(this->_height) / Float((int)2)) - 5.5),this->graphColor,(int)11);
	HX_STACK_LINE(65)
	this->minLabel = ::flixel::system::debug::DebuggerUtil_obj::createTextField((int)0,(this->_height - (int)11),(int)-1426063361,(int)11);
	HX_STACK_LINE(66)
	this->avgLabel = ::flixel::system::debug::DebuggerUtil_obj::createTextField((Float(this->_width) / Float((int)2)),((Float(this->_height) / Float((int)2)) - 5.5),(int)-1426063361,(int)11);
	HX_STACK_LINE(67)
	this->avgLabel->set_width(this->_width);
	HX_STACK_LINE(68)
	this->avgLabel->get_defaultTextFormat()->align = ::flash::text::TextFormatAlign_obj::CENTER;
	HX_STACK_LINE(70)
	this->avgLabel->set_alpha(0.5);
	HX_STACK_LINE(72)
	this->addChild(this->_axis);
	HX_STACK_LINE(73)
	this->addChild(this->maxLabel);
	HX_STACK_LINE(74)
	this->addChild(this->curLabel);
	HX_STACK_LINE(75)
	this->addChild(this->minLabel);
	HX_STACK_LINE(76)
	this->addChild(this->avgLabel);
	HX_STACK_LINE(78)
	this->drawAxis();
}
;
	return null();
}

//StatsGraph_obj::~StatsGraph_obj() { }

Dynamic StatsGraph_obj::__CreateEmpty() { return  new StatsGraph_obj; }
hx::ObjectPtr< StatsGraph_obj > StatsGraph_obj::__new(int X,int Y,int Width,int Height,int GraphColor,::String Unit)
{  hx::ObjectPtr< StatsGraph_obj > result = new StatsGraph_obj();
	result->__construct(X,Y,Width,Height,GraphColor,Unit);
	return result;}

Dynamic StatsGraph_obj::__Create(hx::DynamicArray inArgs)
{  hx::ObjectPtr< StatsGraph_obj > result = new StatsGraph_obj();
	result->__construct(inArgs[0],inArgs[1],inArgs[2],inArgs[3],inArgs[4],inArgs[5]);
	return result;}

Void StatsGraph_obj::drawAxis( ){
{
		HX_STACK_FRAME("flixel.system.debug.StatsGraph","drawAxis",0x602722bc,"flixel.system.debug.StatsGraph.drawAxis","flixel/system/debug/StatsGraph.hx",85,0x92e18906)
		HX_STACK_THIS(this)
		HX_STACK_LINE(86)
		::flash::display::Graphics gfx = this->_axis->get_graphics();		HX_STACK_VAR(gfx,"gfx");
		HX_STACK_LINE(87)
		gfx->clear();
		HX_STACK_LINE(88)
		gfx->beginFill((int)0,null());
		HX_STACK_LINE(89)
		gfx->lineStyle((int)1,(int)16777215,0.5,null(),null(),null(),null(),null());
		HX_STACK_LINE(92)
		gfx->moveTo((int)0,(int)0);
		HX_STACK_LINE(93)
		gfx->lineTo((int)0,this->_height);
		HX_STACK_LINE(96)
		gfx->moveTo((int)0,this->_height);
		HX_STACK_LINE(97)
		gfx->lineTo((this->_width - this->_axis->get_x()),this->_height);
		HX_STACK_LINE(99)
		gfx->endFill();
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC0(StatsGraph_obj,drawAxis,(void))

Void StatsGraph_obj::drawGraph( ){
{
		HX_STACK_FRAME("flixel.system.debug.StatsGraph","drawGraph",0x328160d3,"flixel.system.debug.StatsGraph.drawGraph","flixel/system/debug/StatsGraph.hx",106,0x92e18906)
		HX_STACK_THIS(this)
		HX_STACK_LINE(107)
		::flash::display::Graphics gfx = this->get_graphics();		HX_STACK_VAR(gfx,"gfx");
		HX_STACK_LINE(108)
		gfx->clear();
		HX_STACK_LINE(109)
		gfx->lineStyle((int)1,this->graphColor,(int)1,null(),null(),null(),null(),null());
		HX_STACK_LINE(110)
		Float _g = this->_axis->get_x();		HX_STACK_VAR(_g,"_g");
		HX_STACK_LINE(110)
		gfx->moveTo(_g,this->_axis->get_y());
		HX_STACK_LINE(112)
		Float inc = (Float(((this->_width - this->_axis->get_x()))) / Float((int)29));		HX_STACK_VAR(inc,"inc");
		HX_STACK_LINE(113)
		Float range = (this->maxValue - this->minValue);		HX_STACK_VAR(range,"range");
		HX_STACK_LINE(114)
		Float value;		HX_STACK_VAR(value,"value");
		HX_STACK_LINE(116)
		{
			HX_STACK_LINE(116)
			int _g1 = (int)0;		HX_STACK_VAR(_g1,"_g1");
			HX_STACK_LINE(116)
			int _g2 = this->history->length;		HX_STACK_VAR(_g2,"_g2");
			HX_STACK_LINE(116)
			while(((_g1 < _g2))){
				HX_STACK_LINE(116)
				int i = (_g1)++;		HX_STACK_VAR(i,"i");
				HX_STACK_LINE(118)
				value = (Float(((this->history->__get(i) - this->minValue))) / Float(range));
				HX_STACK_LINE(119)
				gfx->lineTo((this->_axis->get_x() + (i * inc)),((-(value) * this->_height) + this->_height));
			}
		}
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC0(StatsGraph_obj,drawGraph,(void))

Void StatsGraph_obj::update( Float Value,Dynamic Average){
{
		HX_STACK_FRAME("flixel.system.debug.StatsGraph","update",0xe8382640,"flixel.system.debug.StatsGraph.update","flixel/system/debug/StatsGraph.hx",124,0x92e18906)
		HX_STACK_THIS(this)
		HX_STACK_ARG(Value,"Value")
		HX_STACK_ARG(Average,"Average")
		HX_STACK_LINE(125)
		this->history->unshift(Value);
		HX_STACK_LINE(127)
		if (((this->history->length > (int)30))){
			HX_STACK_LINE(128)
			this->history->pop();
		}
		HX_STACK_LINE(132)
		this->maxValue = ::Math_obj::max(this->maxValue,Value);
		HX_STACK_LINE(133)
		this->minValue = ::Math_obj::min(this->minValue,Value);
		HX_STACK_LINE(135)
		this->minLabel->set_text(((::flixel::util::FlxMath_obj::roundDecimal(this->minValue,(int)1) + HX_CSTRING(" ")) + this->_unit));
		HX_STACK_LINE(136)
		this->curLabel->set_text(((::flixel::util::FlxMath_obj::roundDecimal(Value,(int)1) + HX_CSTRING(" ")) + this->_unit));
		HX_STACK_LINE(137)
		this->maxLabel->set_text(((::flixel::util::FlxMath_obj::roundDecimal(this->maxValue,(int)1) + HX_CSTRING(" ")) + this->_unit));
		HX_STACK_LINE(139)
		if (((Average == null()))){
			HX_STACK_LINE(140)
			Average = this->average();
		}
		HX_STACK_LINE(142)
		this->avgLabel->set_text((((HX_CSTRING("Avg: ") + ::flixel::util::FlxMath_obj::roundDecimal(Average,(int)1)) + HX_CSTRING(" ")) + this->_unit));
		HX_STACK_LINE(144)
		this->drawGraph();
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC2(StatsGraph_obj,update,(void))

Float StatsGraph_obj::average( ){
	HX_STACK_FRAME("flixel.system.debug.StatsGraph","average",0x0df50146,"flixel.system.debug.StatsGraph.average","flixel/system/debug/StatsGraph.hx",148,0x92e18906)
	HX_STACK_THIS(this)
	HX_STACK_LINE(149)
	Float sum = (int)0;		HX_STACK_VAR(sum,"sum");
	HX_STACK_LINE(150)
	{
		HX_STACK_LINE(150)
		int _g = (int)0;		HX_STACK_VAR(_g,"_g");
		HX_STACK_LINE(150)
		Array< Float > _g1 = this->history;		HX_STACK_VAR(_g1,"_g1");
		HX_STACK_LINE(150)
		while(((_g < _g1->length))){
			HX_STACK_LINE(150)
			Float value = _g1->__get(_g);		HX_STACK_VAR(value,"value");
			HX_STACK_LINE(150)
			++(_g);
			HX_STACK_LINE(151)
			hx::AddEq(sum,value);
		}
	}
	HX_STACK_LINE(153)
	return (Float(sum) / Float(this->history->length));
}


HX_DEFINE_DYNAMIC_FUNC0(StatsGraph_obj,average,return )

Void StatsGraph_obj::destroy( ){
{
		HX_STACK_FRAME("flixel.system.debug.StatsGraph","destroy",0xcf9fbce3,"flixel.system.debug.StatsGraph.destroy","flixel/system/debug/StatsGraph.hx",157,0x92e18906)
		HX_STACK_THIS(this)
		HX_STACK_LINE(158)
		if (((this->_axis != null()))){
			HX_STACK_LINE(160)
			this->removeChild(this->_axis);
			HX_STACK_LINE(161)
			this->_axis = null();
		}
		HX_STACK_LINE(164)
		if (((this->minLabel != null()))){
			HX_STACK_LINE(166)
			this->removeChild(this->minLabel);
			HX_STACK_LINE(167)
			this->minLabel = null();
		}
		HX_STACK_LINE(169)
		if (((this->curLabel != null()))){
			HX_STACK_LINE(171)
			this->removeChild(this->curLabel);
			HX_STACK_LINE(172)
			this->curLabel = null();
		}
		HX_STACK_LINE(174)
		if (((this->maxLabel != null()))){
			HX_STACK_LINE(176)
			this->removeChild(this->maxLabel);
			HX_STACK_LINE(177)
			this->maxLabel = null();
		}
		HX_STACK_LINE(179)
		if (((this->avgLabel != null()))){
			HX_STACK_LINE(181)
			this->removeChild(this->avgLabel);
			HX_STACK_LINE(182)
			this->avgLabel = null();
		}
		HX_STACK_LINE(185)
		this->history = null();
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC0(StatsGraph_obj,destroy,(void))

int StatsGraph_obj::AXIS_COLOR;

Float StatsGraph_obj::AXIS_ALPHA;

int StatsGraph_obj::LABEL_WIDTH;

int StatsGraph_obj::HISTORY_MAX;


StatsGraph_obj::StatsGraph_obj()
{
}

void StatsGraph_obj::__Mark(HX_MARK_PARAMS)
{
	HX_MARK_BEGIN_CLASS(StatsGraph);
	HX_MARK_MEMBER_NAME(_axis,"_axis");
	HX_MARK_MEMBER_NAME(_axisWidth,"_axisWidth");
	HX_MARK_MEMBER_NAME(_width,"_width");
	HX_MARK_MEMBER_NAME(_height,"_height");
	HX_MARK_MEMBER_NAME(_unit,"_unit");
	HX_MARK_MEMBER_NAME(minLabel,"minLabel");
	HX_MARK_MEMBER_NAME(curLabel,"curLabel");
	HX_MARK_MEMBER_NAME(maxLabel,"maxLabel");
	HX_MARK_MEMBER_NAME(avgLabel,"avgLabel");
	HX_MARK_MEMBER_NAME(minValue,"minValue");
	HX_MARK_MEMBER_NAME(maxValue,"maxValue");
	HX_MARK_MEMBER_NAME(graphColor,"graphColor");
	HX_MARK_MEMBER_NAME(history,"history");
	::flash::display::DisplayObjectContainer_obj::__Mark(HX_MARK_ARG);
	HX_MARK_END_CLASS();
}

void StatsGraph_obj::__Visit(HX_VISIT_PARAMS)
{
	HX_VISIT_MEMBER_NAME(_axis,"_axis");
	HX_VISIT_MEMBER_NAME(_axisWidth,"_axisWidth");
	HX_VISIT_MEMBER_NAME(_width,"_width");
	HX_VISIT_MEMBER_NAME(_height,"_height");
	HX_VISIT_MEMBER_NAME(_unit,"_unit");
	HX_VISIT_MEMBER_NAME(minLabel,"minLabel");
	HX_VISIT_MEMBER_NAME(curLabel,"curLabel");
	HX_VISIT_MEMBER_NAME(maxLabel,"maxLabel");
	HX_VISIT_MEMBER_NAME(avgLabel,"avgLabel");
	HX_VISIT_MEMBER_NAME(minValue,"minValue");
	HX_VISIT_MEMBER_NAME(maxValue,"maxValue");
	HX_VISIT_MEMBER_NAME(graphColor,"graphColor");
	HX_VISIT_MEMBER_NAME(history,"history");
	::flash::display::DisplayObjectContainer_obj::__Visit(HX_VISIT_ARG);
}

Dynamic StatsGraph_obj::__Field(const ::String &inName,bool inCallProp)
{
	switch(inName.length) {
	case 5:
		if (HX_FIELD_EQ(inName,"_axis") ) { return _axis; }
		if (HX_FIELD_EQ(inName,"_unit") ) { return _unit; }
		break;
	case 6:
		if (HX_FIELD_EQ(inName,"_width") ) { return _width; }
		if (HX_FIELD_EQ(inName,"update") ) { return update_dyn(); }
		break;
	case 7:
		if (HX_FIELD_EQ(inName,"_height") ) { return _height; }
		if (HX_FIELD_EQ(inName,"history") ) { return history; }
		if (HX_FIELD_EQ(inName,"average") ) { return average_dyn(); }
		if (HX_FIELD_EQ(inName,"destroy") ) { return destroy_dyn(); }
		break;
	case 8:
		if (HX_FIELD_EQ(inName,"minLabel") ) { return minLabel; }
		if (HX_FIELD_EQ(inName,"curLabel") ) { return curLabel; }
		if (HX_FIELD_EQ(inName,"maxLabel") ) { return maxLabel; }
		if (HX_FIELD_EQ(inName,"avgLabel") ) { return avgLabel; }
		if (HX_FIELD_EQ(inName,"minValue") ) { return minValue; }
		if (HX_FIELD_EQ(inName,"maxValue") ) { return maxValue; }
		if (HX_FIELD_EQ(inName,"drawAxis") ) { return drawAxis_dyn(); }
		break;
	case 9:
		if (HX_FIELD_EQ(inName,"drawGraph") ) { return drawGraph_dyn(); }
		break;
	case 10:
		if (HX_FIELD_EQ(inName,"_axisWidth") ) { return _axisWidth; }
		if (HX_FIELD_EQ(inName,"graphColor") ) { return graphColor; }
	}
	return super::__Field(inName,inCallProp);
}

Dynamic StatsGraph_obj::__SetField(const ::String &inName,const Dynamic &inValue,bool inCallProp)
{
	switch(inName.length) {
	case 5:
		if (HX_FIELD_EQ(inName,"_axis") ) { _axis=inValue.Cast< ::flash::display::Shape >(); return inValue; }
		if (HX_FIELD_EQ(inName,"_unit") ) { _unit=inValue.Cast< ::String >(); return inValue; }
		break;
	case 6:
		if (HX_FIELD_EQ(inName,"_width") ) { _width=inValue.Cast< int >(); return inValue; }
		break;
	case 7:
		if (HX_FIELD_EQ(inName,"_height") ) { _height=inValue.Cast< int >(); return inValue; }
		if (HX_FIELD_EQ(inName,"history") ) { history=inValue.Cast< Array< Float > >(); return inValue; }
		break;
	case 8:
		if (HX_FIELD_EQ(inName,"minLabel") ) { minLabel=inValue.Cast< ::flash::text::TextField >(); return inValue; }
		if (HX_FIELD_EQ(inName,"curLabel") ) { curLabel=inValue.Cast< ::flash::text::TextField >(); return inValue; }
		if (HX_FIELD_EQ(inName,"maxLabel") ) { maxLabel=inValue.Cast< ::flash::text::TextField >(); return inValue; }
		if (HX_FIELD_EQ(inName,"avgLabel") ) { avgLabel=inValue.Cast< ::flash::text::TextField >(); return inValue; }
		if (HX_FIELD_EQ(inName,"minValue") ) { minValue=inValue.Cast< Float >(); return inValue; }
		if (HX_FIELD_EQ(inName,"maxValue") ) { maxValue=inValue.Cast< Float >(); return inValue; }
		break;
	case 10:
		if (HX_FIELD_EQ(inName,"_axisWidth") ) { _axisWidth=inValue.Cast< int >(); return inValue; }
		if (HX_FIELD_EQ(inName,"graphColor") ) { graphColor=inValue.Cast< int >(); return inValue; }
	}
	return super::__SetField(inName,inValue,inCallProp);
}

void StatsGraph_obj::__GetFields(Array< ::String> &outFields)
{
	outFields->push(HX_CSTRING("_axis"));
	outFields->push(HX_CSTRING("_axisWidth"));
	outFields->push(HX_CSTRING("_width"));
	outFields->push(HX_CSTRING("_height"));
	outFields->push(HX_CSTRING("_unit"));
	outFields->push(HX_CSTRING("minLabel"));
	outFields->push(HX_CSTRING("curLabel"));
	outFields->push(HX_CSTRING("maxLabel"));
	outFields->push(HX_CSTRING("avgLabel"));
	outFields->push(HX_CSTRING("minValue"));
	outFields->push(HX_CSTRING("maxValue"));
	outFields->push(HX_CSTRING("graphColor"));
	outFields->push(HX_CSTRING("history"));
	super::__GetFields(outFields);
};

static ::String sStaticFields[] = {
	HX_CSTRING("AXIS_COLOR"),
	HX_CSTRING("AXIS_ALPHA"),
	HX_CSTRING("LABEL_WIDTH"),
	HX_CSTRING("HISTORY_MAX"),
	String(null()) };

#if HXCPP_SCRIPTABLE
static hx::StorageInfo sMemberStorageInfo[] = {
	{hx::fsObject /*::flash::display::Shape*/ ,(int)offsetof(StatsGraph_obj,_axis),HX_CSTRING("_axis")},
	{hx::fsInt,(int)offsetof(StatsGraph_obj,_axisWidth),HX_CSTRING("_axisWidth")},
	{hx::fsInt,(int)offsetof(StatsGraph_obj,_width),HX_CSTRING("_width")},
	{hx::fsInt,(int)offsetof(StatsGraph_obj,_height),HX_CSTRING("_height")},
	{hx::fsString,(int)offsetof(StatsGraph_obj,_unit),HX_CSTRING("_unit")},
	{hx::fsObject /*::flash::text::TextField*/ ,(int)offsetof(StatsGraph_obj,minLabel),HX_CSTRING("minLabel")},
	{hx::fsObject /*::flash::text::TextField*/ ,(int)offsetof(StatsGraph_obj,curLabel),HX_CSTRING("curLabel")},
	{hx::fsObject /*::flash::text::TextField*/ ,(int)offsetof(StatsGraph_obj,maxLabel),HX_CSTRING("maxLabel")},
	{hx::fsObject /*::flash::text::TextField*/ ,(int)offsetof(StatsGraph_obj,avgLabel),HX_CSTRING("avgLabel")},
	{hx::fsFloat,(int)offsetof(StatsGraph_obj,minValue),HX_CSTRING("minValue")},
	{hx::fsFloat,(int)offsetof(StatsGraph_obj,maxValue),HX_CSTRING("maxValue")},
	{hx::fsInt,(int)offsetof(StatsGraph_obj,graphColor),HX_CSTRING("graphColor")},
	{hx::fsObject /*Array< Float >*/ ,(int)offsetof(StatsGraph_obj,history),HX_CSTRING("history")},
	{ hx::fsUnknown, 0, null()}
};
#endif

static ::String sMemberFields[] = {
	HX_CSTRING("_axis"),
	HX_CSTRING("_axisWidth"),
	HX_CSTRING("_width"),
	HX_CSTRING("_height"),
	HX_CSTRING("_unit"),
	HX_CSTRING("minLabel"),
	HX_CSTRING("curLabel"),
	HX_CSTRING("maxLabel"),
	HX_CSTRING("avgLabel"),
	HX_CSTRING("minValue"),
	HX_CSTRING("maxValue"),
	HX_CSTRING("graphColor"),
	HX_CSTRING("history"),
	HX_CSTRING("drawAxis"),
	HX_CSTRING("drawGraph"),
	HX_CSTRING("update"),
	HX_CSTRING("average"),
	HX_CSTRING("destroy"),
	String(null()) };

static void sMarkStatics(HX_MARK_PARAMS) {
	HX_MARK_MEMBER_NAME(StatsGraph_obj::__mClass,"__mClass");
	HX_MARK_MEMBER_NAME(StatsGraph_obj::AXIS_COLOR,"AXIS_COLOR");
	HX_MARK_MEMBER_NAME(StatsGraph_obj::AXIS_ALPHA,"AXIS_ALPHA");
	HX_MARK_MEMBER_NAME(StatsGraph_obj::LABEL_WIDTH,"LABEL_WIDTH");
	HX_MARK_MEMBER_NAME(StatsGraph_obj::HISTORY_MAX,"HISTORY_MAX");
};

#ifdef HXCPP_VISIT_ALLOCS
static void sVisitStatics(HX_VISIT_PARAMS) {
	HX_VISIT_MEMBER_NAME(StatsGraph_obj::__mClass,"__mClass");
	HX_VISIT_MEMBER_NAME(StatsGraph_obj::AXIS_COLOR,"AXIS_COLOR");
	HX_VISIT_MEMBER_NAME(StatsGraph_obj::AXIS_ALPHA,"AXIS_ALPHA");
	HX_VISIT_MEMBER_NAME(StatsGraph_obj::LABEL_WIDTH,"LABEL_WIDTH");
	HX_VISIT_MEMBER_NAME(StatsGraph_obj::HISTORY_MAX,"HISTORY_MAX");
};

#endif

Class StatsGraph_obj::__mClass;

void StatsGraph_obj::__register()
{
	hx::Static(__mClass) = hx::RegisterClass(HX_CSTRING("flixel.system.debug.StatsGraph"), hx::TCanCast< StatsGraph_obj> ,sStaticFields,sMemberFields,
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

void StatsGraph_obj::__boot()
{
	AXIS_COLOR= (int)16777215;
	AXIS_ALPHA= 0.5;
	LABEL_WIDTH= (int)50;
	HISTORY_MAX= (int)30;
}

} // end namespace flixel
} // end namespace system
} // end namespace debug
