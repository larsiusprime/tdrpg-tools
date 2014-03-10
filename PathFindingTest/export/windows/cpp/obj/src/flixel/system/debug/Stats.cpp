#include <hxcpp.h>

#ifndef INCLUDED_Std
#include <Std.h>
#endif
#ifndef INCLUDED_flash_display_Bitmap
#include <flash/display/Bitmap.h>
#endif
#ifndef INCLUDED_flash_display_BitmapData
#include <flash/display/BitmapData.h>
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
#ifndef INCLUDED_flash_geom_Rectangle
#include <flash/geom/Rectangle.h>
#endif
#ifndef INCLUDED_flash_system_System
#include <flash/system/System.h>
#endif
#ifndef INCLUDED_flash_text_TextField
#include <flash/text/TextField.h>
#endif
#ifndef INCLUDED_flixel_FlxG
#include <flixel/FlxG.h>
#endif
#ifndef INCLUDED_flixel_FlxGame
#include <flixel/FlxGame.h>
#endif
#ifndef INCLUDED_flixel_system_FlxList
#include <flixel/system/FlxList.h>
#endif
#ifndef INCLUDED_flixel_system_FlxQuadTree
#include <flixel/system/FlxQuadTree.h>
#endif
#ifndef INCLUDED_flixel_system_debug_DebuggerUtil
#include <flixel/system/debug/DebuggerUtil.h>
#endif
#ifndef INCLUDED_flixel_system_debug_GraphicStats
#include <flixel/system/debug/GraphicStats.h>
#endif
#ifndef INCLUDED_flixel_system_debug_Stats
#include <flixel/system/debug/Stats.h>
#endif
#ifndef INCLUDED_flixel_system_debug_StatsGraph
#include <flixel/system/debug/StatsGraph.h>
#endif
#ifndef INCLUDED_flixel_system_debug_Window
#include <flixel/system/debug/Window.h>
#endif
#ifndef INCLUDED_flixel_util_FlxMath
#include <flixel/util/FlxMath.h>
#endif
#ifndef INCLUDED_flixel_util_FlxRect
#include <flixel/util/FlxRect.h>
#endif
namespace flixel{
namespace system{
namespace debug{

Void Stats_obj::__construct()
{
HX_STACK_FRAME("flixel.system.debug.Stats","new",0x4140b8e9,"flixel.system.debug.Stats.new","flixel/system/debug/Stats.hx",20,0xa5a2e9c8)
{
	HX_STACK_LINE(93)
	this->_drawCallsMarker = (int)0;
	HX_STACK_LINE(91)
	this->drawCallsCount = (int)0;
	HX_STACK_LINE(88)
	this->_paused = true;
	HX_STACK_LINE(86)
	this->_activeObjectMarker = (int)0;
	HX_STACK_LINE(83)
	this->_visibleObjectMarker = (int)0;
	HX_STACK_LINE(80)
	this->_drawMarker = (int)0;
	HX_STACK_LINE(77)
	this->_updateMarker = (int)0;
	HX_STACK_LINE(74)
	this->_updateTimer = (int)0;
	HX_STACK_LINE(73)
	this->_lastTime = (int)0;
	HX_STACK_LINE(71)
	this->drawTime = (int)0;
	HX_STACK_LINE(70)
	this->updateTime = (int)0;
	HX_STACK_LINE(69)
	this->activeCount = (int)0;
	HX_STACK_LINE(68)
	this->visibleCount = (int)0;
	HX_STACK_LINE(67)
	this->flashPlayerFramerate = (int)0;
	HX_STACK_LINE(58)
	this->_itvTime = (int)0;
	HX_STACK_LINE(101)
	super::__construct(HX_CSTRING("stats"),::flixel::system::debug::GraphicStats_obj::__new((int)0,(int)0,null(),null()),(int)0,(int)0,false,null(),null());
	HX_STACK_LINE(103)
	this->minSize->y = (int)195;
	HX_STACK_LINE(104)
	this->resize((int)160,(int)195);
	HX_STACK_LINE(106)
	this->start();
	HX_STACK_LINE(108)
	this->_update = Array_obj< int >::__new();
	HX_STACK_LINE(109)
	this->_draw = Array_obj< int >::__new();
	HX_STACK_LINE(110)
	this->_activeObject = Array_obj< int >::__new();
	HX_STACK_LINE(111)
	this->_visibleObject = Array_obj< int >::__new();
	HX_STACK_LINE(114)
	this->_drawCalls = Array_obj< int >::__new();
	HX_STACK_LINE(117)
	int graphHeight = (int)40;		HX_STACK_VAR(graphHeight,"graphHeight");
	HX_STACK_LINE(118)
	int gutter = (int)5;		HX_STACK_VAR(gutter,"gutter");
	HX_STACK_LINE(120)
	this->fpsGraph = ::flixel::system::debug::StatsGraph_obj::__new(gutter,(::Std_obj::_int(this->_header->get_height()) + (int)5),(int)150,graphHeight,(int)-6881536,HX_CSTRING("fps"));
	HX_STACK_LINE(121)
	this->addChild(this->fpsGraph);
	HX_STACK_LINE(122)
	this->fpsGraph->maxValue = ::flixel::FlxG_obj::drawFramerate;
	HX_STACK_LINE(123)
	this->fpsGraph->minValue = (int)0;
	HX_STACK_LINE(125)
	this->memoryGraph = ::flixel::system::debug::StatsGraph_obj::__new(gutter,((::Std_obj::_int(this->_header->get_height()) + graphHeight) + (int)20),(int)150,graphHeight,(int)-16737025,HX_CSTRING("MB"));
	HX_STACK_LINE(126)
	this->addChild(this->memoryGraph);
	HX_STACK_LINE(128)
	this->addChild(this->_leftTextField = ::flixel::system::debug::DebuggerUtil_obj::createTextField(gutter,((graphHeight * (int)2) + (int)45),(int)-1426063361,(int)11));
	HX_STACK_LINE(129)
	this->addChild(this->_rightTextField = ::flixel::system::debug::DebuggerUtil_obj::createTextField((gutter + (int)70),((graphHeight * (int)2) + (int)45),(int)-1,(int)11));
	HX_STACK_LINE(131)
	this->_leftTextField->set_multiline(this->_rightTextField->set_multiline(true));
	HX_STACK_LINE(132)
	this->_leftTextField->set_wordWrap(this->_rightTextField->set_wordWrap(true));
	HX_STACK_LINE(134)
	this->_leftTextField->set_text(HX_CSTRING("Update: \nDraw:\nDrawTiles:\nQuadTrees: \nLists:"));
}
;
	return null();
}

//Stats_obj::~Stats_obj() { }

Dynamic Stats_obj::__CreateEmpty() { return  new Stats_obj; }
hx::ObjectPtr< Stats_obj > Stats_obj::__new()
{  hx::ObjectPtr< Stats_obj > result = new Stats_obj();
	result->__construct();
	return result;}

Dynamic Stats_obj::__Create(hx::DynamicArray inArgs)
{  hx::ObjectPtr< Stats_obj > result = new Stats_obj();
	result->__construct();
	return result;}

Void Stats_obj::start( ){
{
		HX_STACK_FRAME("flixel.system.debug.Stats","start",0x886a512b,"flixel.system.debug.Stats.start","flixel/system/debug/Stats.hx",142,0xa5a2e9c8)
		HX_STACK_THIS(this)
		HX_STACK_LINE(142)
		if ((this->_paused)){
			HX_STACK_LINE(144)
			this->_paused = false;
			HX_STACK_LINE(145)
			this->_initTime = this->_itvTime = ::flixel::FlxG_obj::game->ticks;
			HX_STACK_LINE(146)
			this->_totalCount = this->_frameCount = (int)0;
		}
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC0(Stats_obj,start,(void))

Void Stats_obj::stop( ){
{
		HX_STACK_FRAME("flixel.system.debug.Stats","stop",0xdaba7f59,"flixel.system.debug.Stats.stop","flixel/system/debug/Stats.hx",155,0xa5a2e9c8)
		HX_STACK_THIS(this)
		HX_STACK_LINE(155)
		this->_paused = true;
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC0(Stats_obj,stop,(void))

Void Stats_obj::destroy( ){
{
		HX_STACK_FRAME("flixel.system.debug.Stats","destroy",0x23ec8e03,"flixel.system.debug.Stats.destroy","flixel/system/debug/Stats.hx",162,0xa5a2e9c8)
		HX_STACK_THIS(this)
		HX_STACK_LINE(163)
		if (((this->fpsGraph != null()))){
			HX_STACK_LINE(165)
			this->fpsGraph->destroy();
			HX_STACK_LINE(166)
			this->removeChild(this->fpsGraph);
		}
		HX_STACK_LINE(168)
		this->fpsGraph = null();
		HX_STACK_LINE(170)
		if (((this->memoryGraph != null()))){
			HX_STACK_LINE(172)
			this->removeChild(this->memoryGraph);
		}
		HX_STACK_LINE(174)
		this->memoryGraph = null();
		HX_STACK_LINE(176)
		if (((this->_leftTextField != null()))){
			HX_STACK_LINE(178)
			this->removeChild(this->_leftTextField);
		}
		HX_STACK_LINE(180)
		this->_leftTextField = null();
		HX_STACK_LINE(182)
		if (((this->_rightTextField != null()))){
			HX_STACK_LINE(184)
			this->removeChild(this->_rightTextField);
		}
		HX_STACK_LINE(186)
		this->_rightTextField = null();
		HX_STACK_LINE(188)
		this->_update = null();
		HX_STACK_LINE(189)
		this->_draw = null();
		HX_STACK_LINE(190)
		this->_activeObject = null();
		HX_STACK_LINE(191)
		this->_visibleObject = null();
		HX_STACK_LINE(194)
		this->_drawCalls = null();
		HX_STACK_LINE(197)
		this->super::destroy();
	}
return null();
}


Void Stats_obj::update( ){
{
		HX_STACK_FRAME("flixel.system.debug.Stats","update",0x55a7d920,"flixel.system.debug.Stats.update","flixel/system/debug/Stats.hx",205,0xa5a2e9c8)
		HX_STACK_THIS(this)
		HX_STACK_LINE(206)
		if ((this->_paused)){
			HX_STACK_LINE(208)
			return null();
		}
		HX_STACK_LINE(210)
		int time = this->_currentTime = ::flixel::FlxG_obj::game->ticks;		HX_STACK_VAR(time,"time");
		HX_STACK_LINE(212)
		int elapsed = (time - this->_lastTime);		HX_STACK_VAR(elapsed,"elapsed");
		HX_STACK_LINE(214)
		if (((elapsed > (int)250))){
			HX_STACK_LINE(216)
			elapsed = (int)250;
		}
		HX_STACK_LINE(218)
		this->_lastTime = time;
		HX_STACK_LINE(220)
		hx::AddEq(this->_updateTimer,elapsed);
		HX_STACK_LINE(222)
		(this->_frameCount)++;
		HX_STACK_LINE(223)
		(this->_totalCount)++;
		HX_STACK_LINE(225)
		if (((this->_updateTimer > (int)250))){
			HX_STACK_LINE(227)
			this->fpsGraph->update((Float(this->_frameCount) / Float(((Float(((this->_currentTime - this->_itvTime))) / Float((int)1000))))),(Float(this->_totalCount) / Float(((Float(((this->_currentTime - this->_initTime))) / Float((int)1000))))));
			HX_STACK_LINE(228)
			this->memoryGraph->update((Float((Float(::flash::system::System_obj::get_totalMemory()) / Float((int)1024))) / Float((int)1000)),null());
			HX_STACK_LINE(229)
			this->updateTexts();
			HX_STACK_LINE(231)
			this->_frameCount = (int)0;
			HX_STACK_LINE(232)
			this->_itvTime = this->_currentTime;
			HX_STACK_LINE(234)
			this->updateTime = (int)0;
			HX_STACK_LINE(235)
			{
				HX_STACK_LINE(235)
				int _g1 = (int)0;		HX_STACK_VAR(_g1,"_g1");
				HX_STACK_LINE(235)
				int _g = this->_updateMarker;		HX_STACK_VAR(_g,"_g");
				HX_STACK_LINE(235)
				while(((_g1 < _g))){
					HX_STACK_LINE(235)
					int i = (_g1)++;		HX_STACK_VAR(i,"i");
					HX_STACK_LINE(237)
					hx::AddEq(this->updateTime,this->_update->__get(i));
				}
			}
			HX_STACK_LINE(240)
			{
				HX_STACK_LINE(240)
				int _g1 = (int)0;		HX_STACK_VAR(_g1,"_g1");
				HX_STACK_LINE(240)
				int _g = this->_activeObjectMarker;		HX_STACK_VAR(_g,"_g");
				HX_STACK_LINE(240)
				while(((_g1 < _g))){
					HX_STACK_LINE(240)
					int i = (_g1)++;		HX_STACK_VAR(i,"i");
					HX_STACK_LINE(242)
					hx::AddEq(this->activeCount,this->_activeObject->__get(i));
				}
			}
			HX_STACK_LINE(244)
			this->activeCount = ::Std_obj::_int((Float(this->activeCount) / Float(this->_activeObjectMarker)));
			HX_STACK_LINE(246)
			this->drawTime = (int)0;
			HX_STACK_LINE(247)
			{
				HX_STACK_LINE(247)
				int _g1 = (int)0;		HX_STACK_VAR(_g1,"_g1");
				HX_STACK_LINE(247)
				int _g = this->_drawMarker;		HX_STACK_VAR(_g,"_g");
				HX_STACK_LINE(247)
				while(((_g1 < _g))){
					HX_STACK_LINE(247)
					int i = (_g1)++;		HX_STACK_VAR(i,"i");
					HX_STACK_LINE(249)
					hx::AddEq(this->drawTime,this->_draw->__get(i));
				}
			}
			HX_STACK_LINE(252)
			{
				HX_STACK_LINE(252)
				int _g1 = (int)0;		HX_STACK_VAR(_g1,"_g1");
				HX_STACK_LINE(252)
				int _g = this->_visibleObjectMarker;		HX_STACK_VAR(_g,"_g");
				HX_STACK_LINE(252)
				while(((_g1 < _g))){
					HX_STACK_LINE(252)
					int i = (_g1)++;		HX_STACK_VAR(i,"i");
					HX_STACK_LINE(254)
					hx::AddEq(this->visibleCount,this->_visibleObject->__get(i));
				}
			}
			HX_STACK_LINE(256)
			this->visibleCount = ::Std_obj::_int((Float(this->visibleCount) / Float(this->_visibleObjectMarker)));
			HX_STACK_LINE(259)
			{
				HX_STACK_LINE(259)
				int _g1 = (int)0;		HX_STACK_VAR(_g1,"_g1");
				HX_STACK_LINE(259)
				int _g = this->_drawCallsMarker;		HX_STACK_VAR(_g,"_g");
				HX_STACK_LINE(259)
				while(((_g1 < _g))){
					HX_STACK_LINE(259)
					int i = (_g1)++;		HX_STACK_VAR(i,"i");
					HX_STACK_LINE(261)
					hx::AddEq(this->drawCallsCount,this->_drawCalls->__get(i));
				}
			}
			HX_STACK_LINE(263)
			this->drawCallsCount = ::Std_obj::_int((Float(this->drawCallsCount) / Float(this->_drawCallsMarker)));
			HX_STACK_LINE(266)
			this->_updateMarker = (int)0;
			HX_STACK_LINE(267)
			this->_drawMarker = (int)0;
			HX_STACK_LINE(268)
			this->_activeObjectMarker = (int)0;
			HX_STACK_LINE(269)
			this->_visibleObjectMarker = (int)0;
			HX_STACK_LINE(271)
			this->_drawCallsMarker = (int)0;
			HX_STACK_LINE(274)
			hx::SubEq(this->_updateTimer,(int)250);
		}
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC0(Stats_obj,update,(void))

Void Stats_obj::updateTexts( ){
{
		HX_STACK_FRAME("flixel.system.debug.Stats","updateTexts",0xaa77cde6,"flixel.system.debug.Stats.updateTexts","flixel/system/debug/Stats.hx",279,0xa5a2e9c8)
		HX_STACK_THIS(this)
		HX_STACK_LINE(280)
		Float updTime = ::flixel::util::FlxMath_obj::roundDecimal((Float(this->updateTime) / Float(this->_updateMarker)),(int)1);		HX_STACK_VAR(updTime,"updTime");
		HX_STACK_LINE(281)
		Float drwTime = ::flixel::util::FlxMath_obj::roundDecimal((Float(this->drawTime) / Float(this->_drawMarker)),(int)1);		HX_STACK_VAR(drwTime,"drwTime");
		HX_STACK_LINE(283)
		this->_rightTextField->set_text(((((((((((((this->activeCount + HX_CSTRING(" (")) + updTime) + HX_CSTRING("ms)\n")) + this->visibleCount) + HX_CSTRING(" (")) + drwTime) + HX_CSTRING("ms)\n")) + this->drawCallsCount) + HX_CSTRING("\n")) + ::flixel::system::FlxQuadTree_obj::_NUM_CACHED_QUAD_TREES) + HX_CSTRING("\n")) + ::flixel::system::FlxList_obj::_NUM_CACHED_FLX_LIST));
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC0(Stats_obj,updateTexts,(void))

Float Stats_obj::currentFps( ){
	HX_STACK_FRAME("flixel.system.debug.Stats","currentFps",0x0f27b7c7,"flixel.system.debug.Stats.currentFps","flixel/system/debug/Stats.hx",297,0xa5a2e9c8)
	HX_STACK_THIS(this)
	HX_STACK_LINE(297)
	return (Float(this->_frameCount) / Float(((Float(((this->_currentTime - this->_itvTime))) / Float((int)1000)))));
}


HX_DEFINE_DYNAMIC_FUNC0(Stats_obj,currentFps,return )

Float Stats_obj::averageFps( ){
	HX_STACK_FRAME("flixel.system.debug.Stats","averageFps",0xceceb123,"flixel.system.debug.Stats.averageFps","flixel/system/debug/Stats.hx",305,0xa5a2e9c8)
	HX_STACK_THIS(this)
	HX_STACK_LINE(305)
	return (Float(this->_totalCount) / Float(((Float(((this->_currentTime - this->_initTime))) / Float((int)1000)))));
}


HX_DEFINE_DYNAMIC_FUNC0(Stats_obj,averageFps,return )

Float Stats_obj::runningTime( ){
	HX_STACK_FRAME("flixel.system.debug.Stats","runningTime",0xc36deb35,"flixel.system.debug.Stats.runningTime","flixel/system/debug/Stats.hx",313,0xa5a2e9c8)
	HX_STACK_THIS(this)
	HX_STACK_LINE(313)
	return (Float(((this->_currentTime - this->_initTime))) / Float((int)1000));
}


HX_DEFINE_DYNAMIC_FUNC0(Stats_obj,runningTime,return )

Float Stats_obj::intervalTime( ){
	HX_STACK_FRAME("flixel.system.debug.Stats","intervalTime",0x2b393649,"flixel.system.debug.Stats.intervalTime","flixel/system/debug/Stats.hx",321,0xa5a2e9c8)
	HX_STACK_THIS(this)
	HX_STACK_LINE(321)
	return (Float(((this->_currentTime - this->_itvTime))) / Float((int)1000));
}


HX_DEFINE_DYNAMIC_FUNC0(Stats_obj,intervalTime,return )

Float Stats_obj::currentMem( ){
	HX_STACK_FRAME("flixel.system.debug.Stats","currentMem",0x0f2cfdf3,"flixel.system.debug.Stats.currentMem","flixel/system/debug/Stats.hx",329,0xa5a2e9c8)
	HX_STACK_THIS(this)
	HX_STACK_LINE(329)
	return (Float((Float(::flash::system::System_obj::get_totalMemory()) / Float((int)1024))) / Float((int)1000));
}


HX_DEFINE_DYNAMIC_FUNC0(Stats_obj,currentMem,return )

Void Stats_obj::flixelUpdate( int Time){
{
		HX_STACK_FRAME("flixel.system.debug.Stats","flixelUpdate",0xcd6ea7dc,"flixel.system.debug.Stats.flixelUpdate","flixel/system/debug/Stats.hx",338,0xa5a2e9c8)
		HX_STACK_THIS(this)
		HX_STACK_ARG(Time,"Time")
		HX_STACK_LINE(339)
		if ((this->_paused)){
			HX_STACK_LINE(339)
			return null();
		}
		HX_STACK_LINE(340)
		this->_update[(this->_updateMarker)++] = Time;
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC1(Stats_obj,flixelUpdate,(void))

Void Stats_obj::flixelDraw( int Time){
{
		HX_STACK_FRAME("flixel.system.debug.Stats","flixelDraw",0x95df2317,"flixel.system.debug.Stats.flixelDraw","flixel/system/debug/Stats.hx",349,0xa5a2e9c8)
		HX_STACK_THIS(this)
		HX_STACK_ARG(Time,"Time")
		HX_STACK_LINE(350)
		if ((this->_paused)){
			HX_STACK_LINE(350)
			return null();
		}
		HX_STACK_LINE(351)
		this->_draw[(this->_drawMarker)++] = Time;
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC1(Stats_obj,flixelDraw,(void))

Void Stats_obj::activeObjects( int Count){
{
		HX_STACK_FRAME("flixel.system.debug.Stats","activeObjects",0xe23f0177,"flixel.system.debug.Stats.activeObjects","flixel/system/debug/Stats.hx",360,0xa5a2e9c8)
		HX_STACK_THIS(this)
		HX_STACK_ARG(Count,"Count")
		HX_STACK_LINE(361)
		if ((this->_paused)){
			HX_STACK_LINE(361)
			return null();
		}
		HX_STACK_LINE(362)
		this->_activeObject[(this->_activeObjectMarker)++] = Count;
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC1(Stats_obj,activeObjects,(void))

Void Stats_obj::visibleObjects( int Count){
{
		HX_STACK_FRAME("flixel.system.debug.Stats","visibleObjects",0xb04fac99,"flixel.system.debug.Stats.visibleObjects","flixel/system/debug/Stats.hx",371,0xa5a2e9c8)
		HX_STACK_THIS(this)
		HX_STACK_ARG(Count,"Count")
		HX_STACK_LINE(372)
		if ((this->_paused)){
			HX_STACK_LINE(372)
			return null();
		}
		HX_STACK_LINE(373)
		this->_visibleObject[(this->_visibleObjectMarker)++] = Count;
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC1(Stats_obj,visibleObjects,(void))

Void Stats_obj::drawCalls( int Drawcalls){
{
		HX_STACK_FRAME("flixel.system.debug.Stats","drawCalls",0x77ae1cba,"flixel.system.debug.Stats.drawCalls","flixel/system/debug/Stats.hx",383,0xa5a2e9c8)
		HX_STACK_THIS(this)
		HX_STACK_ARG(Drawcalls,"Drawcalls")
		HX_STACK_LINE(384)
		if ((this->_paused)){
			HX_STACK_LINE(384)
			return null();
		}
		HX_STACK_LINE(385)
		this->_drawCalls[(this->_drawCallsMarker)++] = Drawcalls;
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC1(Stats_obj,drawCalls,(void))

Void Stats_obj::onFocus( ){
{
		HX_STACK_FRAME("flixel.system.debug.Stats","onFocus",0x9a2d5f42,"flixel.system.debug.Stats.onFocus","flixel/system/debug/Stats.hx",394,0xa5a2e9c8)
		HX_STACK_THIS(this)
		HX_STACK_LINE(394)
		this->_paused = false;
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC0(Stats_obj,onFocus,(void))

Void Stats_obj::onFocusLost( ){
{
		HX_STACK_FRAME("flixel.system.debug.Stats","onFocusLost",0xf8cbfe46,"flixel.system.debug.Stats.onFocusLost","flixel/system/debug/Stats.hx",402,0xa5a2e9c8)
		HX_STACK_THIS(this)
		HX_STACK_LINE(402)
		this->_paused = true;
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC0(Stats_obj,onFocusLost,(void))

int Stats_obj::UPDATE_DELAY;

int Stats_obj::INITIAL_WIDTH;

int Stats_obj::MIN_HEIGHT;

int Stats_obj::FPS_COLOR;

int Stats_obj::MEMORY_COLOR;

int Stats_obj::LABEL_COLOR;

int Stats_obj::TEXT_SIZE;

int Stats_obj::DECIMALS;


Stats_obj::Stats_obj()
{
}

void Stats_obj::__Mark(HX_MARK_PARAMS)
{
	HX_MARK_BEGIN_CLASS(Stats);
	HX_MARK_MEMBER_NAME(_leftTextField,"_leftTextField");
	HX_MARK_MEMBER_NAME(_rightTextField,"_rightTextField");
	HX_MARK_MEMBER_NAME(_itvTime,"_itvTime");
	HX_MARK_MEMBER_NAME(_initTime,"_initTime");
	HX_MARK_MEMBER_NAME(_frameCount,"_frameCount");
	HX_MARK_MEMBER_NAME(_totalCount,"_totalCount");
	HX_MARK_MEMBER_NAME(_currentTime,"_currentTime");
	HX_MARK_MEMBER_NAME(fpsGraph,"fpsGraph");
	HX_MARK_MEMBER_NAME(memoryGraph,"memoryGraph");
	HX_MARK_MEMBER_NAME(flashPlayerFramerate,"flashPlayerFramerate");
	HX_MARK_MEMBER_NAME(visibleCount,"visibleCount");
	HX_MARK_MEMBER_NAME(activeCount,"activeCount");
	HX_MARK_MEMBER_NAME(updateTime,"updateTime");
	HX_MARK_MEMBER_NAME(drawTime,"drawTime");
	HX_MARK_MEMBER_NAME(_lastTime,"_lastTime");
	HX_MARK_MEMBER_NAME(_updateTimer,"_updateTimer");
	HX_MARK_MEMBER_NAME(_update,"_update");
	HX_MARK_MEMBER_NAME(_updateMarker,"_updateMarker");
	HX_MARK_MEMBER_NAME(_draw,"_draw");
	HX_MARK_MEMBER_NAME(_drawMarker,"_drawMarker");
	HX_MARK_MEMBER_NAME(_visibleObject,"_visibleObject");
	HX_MARK_MEMBER_NAME(_visibleObjectMarker,"_visibleObjectMarker");
	HX_MARK_MEMBER_NAME(_activeObject,"_activeObject");
	HX_MARK_MEMBER_NAME(_activeObjectMarker,"_activeObjectMarker");
	HX_MARK_MEMBER_NAME(_paused,"_paused");
	HX_MARK_MEMBER_NAME(drawCallsCount,"drawCallsCount");
	HX_MARK_MEMBER_NAME(_drawCalls,"_drawCalls");
	HX_MARK_MEMBER_NAME(_drawCallsMarker,"_drawCallsMarker");
	::flixel::system::debug::Window_obj::__Mark(HX_MARK_ARG);
	HX_MARK_END_CLASS();
}

void Stats_obj::__Visit(HX_VISIT_PARAMS)
{
	HX_VISIT_MEMBER_NAME(_leftTextField,"_leftTextField");
	HX_VISIT_MEMBER_NAME(_rightTextField,"_rightTextField");
	HX_VISIT_MEMBER_NAME(_itvTime,"_itvTime");
	HX_VISIT_MEMBER_NAME(_initTime,"_initTime");
	HX_VISIT_MEMBER_NAME(_frameCount,"_frameCount");
	HX_VISIT_MEMBER_NAME(_totalCount,"_totalCount");
	HX_VISIT_MEMBER_NAME(_currentTime,"_currentTime");
	HX_VISIT_MEMBER_NAME(fpsGraph,"fpsGraph");
	HX_VISIT_MEMBER_NAME(memoryGraph,"memoryGraph");
	HX_VISIT_MEMBER_NAME(flashPlayerFramerate,"flashPlayerFramerate");
	HX_VISIT_MEMBER_NAME(visibleCount,"visibleCount");
	HX_VISIT_MEMBER_NAME(activeCount,"activeCount");
	HX_VISIT_MEMBER_NAME(updateTime,"updateTime");
	HX_VISIT_MEMBER_NAME(drawTime,"drawTime");
	HX_VISIT_MEMBER_NAME(_lastTime,"_lastTime");
	HX_VISIT_MEMBER_NAME(_updateTimer,"_updateTimer");
	HX_VISIT_MEMBER_NAME(_update,"_update");
	HX_VISIT_MEMBER_NAME(_updateMarker,"_updateMarker");
	HX_VISIT_MEMBER_NAME(_draw,"_draw");
	HX_VISIT_MEMBER_NAME(_drawMarker,"_drawMarker");
	HX_VISIT_MEMBER_NAME(_visibleObject,"_visibleObject");
	HX_VISIT_MEMBER_NAME(_visibleObjectMarker,"_visibleObjectMarker");
	HX_VISIT_MEMBER_NAME(_activeObject,"_activeObject");
	HX_VISIT_MEMBER_NAME(_activeObjectMarker,"_activeObjectMarker");
	HX_VISIT_MEMBER_NAME(_paused,"_paused");
	HX_VISIT_MEMBER_NAME(drawCallsCount,"drawCallsCount");
	HX_VISIT_MEMBER_NAME(_drawCalls,"_drawCalls");
	HX_VISIT_MEMBER_NAME(_drawCallsMarker,"_drawCallsMarker");
	::flixel::system::debug::Window_obj::__Visit(HX_VISIT_ARG);
}

Dynamic Stats_obj::__Field(const ::String &inName,bool inCallProp)
{
	switch(inName.length) {
	case 4:
		if (HX_FIELD_EQ(inName,"stop") ) { return stop_dyn(); }
		break;
	case 5:
		if (HX_FIELD_EQ(inName,"_draw") ) { return _draw; }
		if (HX_FIELD_EQ(inName,"start") ) { return start_dyn(); }
		break;
	case 6:
		if (HX_FIELD_EQ(inName,"update") ) { return update_dyn(); }
		break;
	case 7:
		if (HX_FIELD_EQ(inName,"_update") ) { return _update; }
		if (HX_FIELD_EQ(inName,"_paused") ) { return _paused; }
		if (HX_FIELD_EQ(inName,"destroy") ) { return destroy_dyn(); }
		if (HX_FIELD_EQ(inName,"onFocus") ) { return onFocus_dyn(); }
		break;
	case 8:
		if (HX_FIELD_EQ(inName,"_itvTime") ) { return _itvTime; }
		if (HX_FIELD_EQ(inName,"fpsGraph") ) { return fpsGraph; }
		if (HX_FIELD_EQ(inName,"drawTime") ) { return drawTime; }
		break;
	case 9:
		if (HX_FIELD_EQ(inName,"_initTime") ) { return _initTime; }
		if (HX_FIELD_EQ(inName,"_lastTime") ) { return _lastTime; }
		if (HX_FIELD_EQ(inName,"drawCalls") ) { return drawCalls_dyn(); }
		break;
	case 10:
		if (HX_FIELD_EQ(inName,"updateTime") ) { return updateTime; }
		if (HX_FIELD_EQ(inName,"_drawCalls") ) { return _drawCalls; }
		if (HX_FIELD_EQ(inName,"currentFps") ) { return currentFps_dyn(); }
		if (HX_FIELD_EQ(inName,"averageFps") ) { return averageFps_dyn(); }
		if (HX_FIELD_EQ(inName,"currentMem") ) { return currentMem_dyn(); }
		if (HX_FIELD_EQ(inName,"flixelDraw") ) { return flixelDraw_dyn(); }
		break;
	case 11:
		if (HX_FIELD_EQ(inName,"_frameCount") ) { return _frameCount; }
		if (HX_FIELD_EQ(inName,"_totalCount") ) { return _totalCount; }
		if (HX_FIELD_EQ(inName,"memoryGraph") ) { return memoryGraph; }
		if (HX_FIELD_EQ(inName,"activeCount") ) { return activeCount; }
		if (HX_FIELD_EQ(inName,"_drawMarker") ) { return _drawMarker; }
		if (HX_FIELD_EQ(inName,"updateTexts") ) { return updateTexts_dyn(); }
		if (HX_FIELD_EQ(inName,"runningTime") ) { return runningTime_dyn(); }
		if (HX_FIELD_EQ(inName,"onFocusLost") ) { return onFocusLost_dyn(); }
		break;
	case 12:
		if (HX_FIELD_EQ(inName,"_currentTime") ) { return _currentTime; }
		if (HX_FIELD_EQ(inName,"visibleCount") ) { return visibleCount; }
		if (HX_FIELD_EQ(inName,"_updateTimer") ) { return _updateTimer; }
		if (HX_FIELD_EQ(inName,"intervalTime") ) { return intervalTime_dyn(); }
		if (HX_FIELD_EQ(inName,"flixelUpdate") ) { return flixelUpdate_dyn(); }
		break;
	case 13:
		if (HX_FIELD_EQ(inName,"_updateMarker") ) { return _updateMarker; }
		if (HX_FIELD_EQ(inName,"_activeObject") ) { return _activeObject; }
		if (HX_FIELD_EQ(inName,"activeObjects") ) { return activeObjects_dyn(); }
		break;
	case 14:
		if (HX_FIELD_EQ(inName,"_leftTextField") ) { return _leftTextField; }
		if (HX_FIELD_EQ(inName,"_visibleObject") ) { return _visibleObject; }
		if (HX_FIELD_EQ(inName,"drawCallsCount") ) { return drawCallsCount; }
		if (HX_FIELD_EQ(inName,"visibleObjects") ) { return visibleObjects_dyn(); }
		break;
	case 15:
		if (HX_FIELD_EQ(inName,"_rightTextField") ) { return _rightTextField; }
		break;
	case 16:
		if (HX_FIELD_EQ(inName,"_drawCallsMarker") ) { return _drawCallsMarker; }
		break;
	case 19:
		if (HX_FIELD_EQ(inName,"_activeObjectMarker") ) { return _activeObjectMarker; }
		break;
	case 20:
		if (HX_FIELD_EQ(inName,"flashPlayerFramerate") ) { return flashPlayerFramerate; }
		if (HX_FIELD_EQ(inName,"_visibleObjectMarker") ) { return _visibleObjectMarker; }
	}
	return super::__Field(inName,inCallProp);
}

Dynamic Stats_obj::__SetField(const ::String &inName,const Dynamic &inValue,bool inCallProp)
{
	switch(inName.length) {
	case 5:
		if (HX_FIELD_EQ(inName,"_draw") ) { _draw=inValue.Cast< Array< int > >(); return inValue; }
		break;
	case 7:
		if (HX_FIELD_EQ(inName,"_update") ) { _update=inValue.Cast< Array< int > >(); return inValue; }
		if (HX_FIELD_EQ(inName,"_paused") ) { _paused=inValue.Cast< bool >(); return inValue; }
		break;
	case 8:
		if (HX_FIELD_EQ(inName,"_itvTime") ) { _itvTime=inValue.Cast< int >(); return inValue; }
		if (HX_FIELD_EQ(inName,"fpsGraph") ) { fpsGraph=inValue.Cast< ::flixel::system::debug::StatsGraph >(); return inValue; }
		if (HX_FIELD_EQ(inName,"drawTime") ) { drawTime=inValue.Cast< int >(); return inValue; }
		break;
	case 9:
		if (HX_FIELD_EQ(inName,"_initTime") ) { _initTime=inValue.Cast< int >(); return inValue; }
		if (HX_FIELD_EQ(inName,"_lastTime") ) { _lastTime=inValue.Cast< int >(); return inValue; }
		break;
	case 10:
		if (HX_FIELD_EQ(inName,"updateTime") ) { updateTime=inValue.Cast< int >(); return inValue; }
		if (HX_FIELD_EQ(inName,"_drawCalls") ) { _drawCalls=inValue.Cast< Array< int > >(); return inValue; }
		break;
	case 11:
		if (HX_FIELD_EQ(inName,"_frameCount") ) { _frameCount=inValue.Cast< int >(); return inValue; }
		if (HX_FIELD_EQ(inName,"_totalCount") ) { _totalCount=inValue.Cast< int >(); return inValue; }
		if (HX_FIELD_EQ(inName,"memoryGraph") ) { memoryGraph=inValue.Cast< ::flixel::system::debug::StatsGraph >(); return inValue; }
		if (HX_FIELD_EQ(inName,"activeCount") ) { activeCount=inValue.Cast< int >(); return inValue; }
		if (HX_FIELD_EQ(inName,"_drawMarker") ) { _drawMarker=inValue.Cast< int >(); return inValue; }
		break;
	case 12:
		if (HX_FIELD_EQ(inName,"_currentTime") ) { _currentTime=inValue.Cast< int >(); return inValue; }
		if (HX_FIELD_EQ(inName,"visibleCount") ) { visibleCount=inValue.Cast< int >(); return inValue; }
		if (HX_FIELD_EQ(inName,"_updateTimer") ) { _updateTimer=inValue.Cast< int >(); return inValue; }
		break;
	case 13:
		if (HX_FIELD_EQ(inName,"_updateMarker") ) { _updateMarker=inValue.Cast< int >(); return inValue; }
		if (HX_FIELD_EQ(inName,"_activeObject") ) { _activeObject=inValue.Cast< Array< int > >(); return inValue; }
		break;
	case 14:
		if (HX_FIELD_EQ(inName,"_leftTextField") ) { _leftTextField=inValue.Cast< ::flash::text::TextField >(); return inValue; }
		if (HX_FIELD_EQ(inName,"_visibleObject") ) { _visibleObject=inValue.Cast< Array< int > >(); return inValue; }
		if (HX_FIELD_EQ(inName,"drawCallsCount") ) { drawCallsCount=inValue.Cast< int >(); return inValue; }
		break;
	case 15:
		if (HX_FIELD_EQ(inName,"_rightTextField") ) { _rightTextField=inValue.Cast< ::flash::text::TextField >(); return inValue; }
		break;
	case 16:
		if (HX_FIELD_EQ(inName,"_drawCallsMarker") ) { _drawCallsMarker=inValue.Cast< int >(); return inValue; }
		break;
	case 19:
		if (HX_FIELD_EQ(inName,"_activeObjectMarker") ) { _activeObjectMarker=inValue.Cast< int >(); return inValue; }
		break;
	case 20:
		if (HX_FIELD_EQ(inName,"flashPlayerFramerate") ) { flashPlayerFramerate=inValue.Cast< Float >(); return inValue; }
		if (HX_FIELD_EQ(inName,"_visibleObjectMarker") ) { _visibleObjectMarker=inValue.Cast< int >(); return inValue; }
	}
	return super::__SetField(inName,inValue,inCallProp);
}

void Stats_obj::__GetFields(Array< ::String> &outFields)
{
	outFields->push(HX_CSTRING("_leftTextField"));
	outFields->push(HX_CSTRING("_rightTextField"));
	outFields->push(HX_CSTRING("_itvTime"));
	outFields->push(HX_CSTRING("_initTime"));
	outFields->push(HX_CSTRING("_frameCount"));
	outFields->push(HX_CSTRING("_totalCount"));
	outFields->push(HX_CSTRING("_currentTime"));
	outFields->push(HX_CSTRING("fpsGraph"));
	outFields->push(HX_CSTRING("memoryGraph"));
	outFields->push(HX_CSTRING("flashPlayerFramerate"));
	outFields->push(HX_CSTRING("visibleCount"));
	outFields->push(HX_CSTRING("activeCount"));
	outFields->push(HX_CSTRING("updateTime"));
	outFields->push(HX_CSTRING("drawTime"));
	outFields->push(HX_CSTRING("_lastTime"));
	outFields->push(HX_CSTRING("_updateTimer"));
	outFields->push(HX_CSTRING("_update"));
	outFields->push(HX_CSTRING("_updateMarker"));
	outFields->push(HX_CSTRING("_draw"));
	outFields->push(HX_CSTRING("_drawMarker"));
	outFields->push(HX_CSTRING("_visibleObject"));
	outFields->push(HX_CSTRING("_visibleObjectMarker"));
	outFields->push(HX_CSTRING("_activeObject"));
	outFields->push(HX_CSTRING("_activeObjectMarker"));
	outFields->push(HX_CSTRING("_paused"));
	outFields->push(HX_CSTRING("drawCallsCount"));
	outFields->push(HX_CSTRING("_drawCalls"));
	outFields->push(HX_CSTRING("_drawCallsMarker"));
	super::__GetFields(outFields);
};

static ::String sStaticFields[] = {
	HX_CSTRING("UPDATE_DELAY"),
	HX_CSTRING("INITIAL_WIDTH"),
	HX_CSTRING("MIN_HEIGHT"),
	HX_CSTRING("FPS_COLOR"),
	HX_CSTRING("MEMORY_COLOR"),
	HX_CSTRING("LABEL_COLOR"),
	HX_CSTRING("TEXT_SIZE"),
	HX_CSTRING("DECIMALS"),
	String(null()) };

#if HXCPP_SCRIPTABLE
static hx::StorageInfo sMemberStorageInfo[] = {
	{hx::fsObject /*::flash::text::TextField*/ ,(int)offsetof(Stats_obj,_leftTextField),HX_CSTRING("_leftTextField")},
	{hx::fsObject /*::flash::text::TextField*/ ,(int)offsetof(Stats_obj,_rightTextField),HX_CSTRING("_rightTextField")},
	{hx::fsInt,(int)offsetof(Stats_obj,_itvTime),HX_CSTRING("_itvTime")},
	{hx::fsInt,(int)offsetof(Stats_obj,_initTime),HX_CSTRING("_initTime")},
	{hx::fsInt,(int)offsetof(Stats_obj,_frameCount),HX_CSTRING("_frameCount")},
	{hx::fsInt,(int)offsetof(Stats_obj,_totalCount),HX_CSTRING("_totalCount")},
	{hx::fsInt,(int)offsetof(Stats_obj,_currentTime),HX_CSTRING("_currentTime")},
	{hx::fsObject /*::flixel::system::debug::StatsGraph*/ ,(int)offsetof(Stats_obj,fpsGraph),HX_CSTRING("fpsGraph")},
	{hx::fsObject /*::flixel::system::debug::StatsGraph*/ ,(int)offsetof(Stats_obj,memoryGraph),HX_CSTRING("memoryGraph")},
	{hx::fsFloat,(int)offsetof(Stats_obj,flashPlayerFramerate),HX_CSTRING("flashPlayerFramerate")},
	{hx::fsInt,(int)offsetof(Stats_obj,visibleCount),HX_CSTRING("visibleCount")},
	{hx::fsInt,(int)offsetof(Stats_obj,activeCount),HX_CSTRING("activeCount")},
	{hx::fsInt,(int)offsetof(Stats_obj,updateTime),HX_CSTRING("updateTime")},
	{hx::fsInt,(int)offsetof(Stats_obj,drawTime),HX_CSTRING("drawTime")},
	{hx::fsInt,(int)offsetof(Stats_obj,_lastTime),HX_CSTRING("_lastTime")},
	{hx::fsInt,(int)offsetof(Stats_obj,_updateTimer),HX_CSTRING("_updateTimer")},
	{hx::fsObject /*Array< int >*/ ,(int)offsetof(Stats_obj,_update),HX_CSTRING("_update")},
	{hx::fsInt,(int)offsetof(Stats_obj,_updateMarker),HX_CSTRING("_updateMarker")},
	{hx::fsObject /*Array< int >*/ ,(int)offsetof(Stats_obj,_draw),HX_CSTRING("_draw")},
	{hx::fsInt,(int)offsetof(Stats_obj,_drawMarker),HX_CSTRING("_drawMarker")},
	{hx::fsObject /*Array< int >*/ ,(int)offsetof(Stats_obj,_visibleObject),HX_CSTRING("_visibleObject")},
	{hx::fsInt,(int)offsetof(Stats_obj,_visibleObjectMarker),HX_CSTRING("_visibleObjectMarker")},
	{hx::fsObject /*Array< int >*/ ,(int)offsetof(Stats_obj,_activeObject),HX_CSTRING("_activeObject")},
	{hx::fsInt,(int)offsetof(Stats_obj,_activeObjectMarker),HX_CSTRING("_activeObjectMarker")},
	{hx::fsBool,(int)offsetof(Stats_obj,_paused),HX_CSTRING("_paused")},
	{hx::fsInt,(int)offsetof(Stats_obj,drawCallsCount),HX_CSTRING("drawCallsCount")},
	{hx::fsObject /*Array< int >*/ ,(int)offsetof(Stats_obj,_drawCalls),HX_CSTRING("_drawCalls")},
	{hx::fsInt,(int)offsetof(Stats_obj,_drawCallsMarker),HX_CSTRING("_drawCallsMarker")},
	{ hx::fsUnknown, 0, null()}
};
#endif

static ::String sMemberFields[] = {
	HX_CSTRING("_leftTextField"),
	HX_CSTRING("_rightTextField"),
	HX_CSTRING("_itvTime"),
	HX_CSTRING("_initTime"),
	HX_CSTRING("_frameCount"),
	HX_CSTRING("_totalCount"),
	HX_CSTRING("_currentTime"),
	HX_CSTRING("fpsGraph"),
	HX_CSTRING("memoryGraph"),
	HX_CSTRING("flashPlayerFramerate"),
	HX_CSTRING("visibleCount"),
	HX_CSTRING("activeCount"),
	HX_CSTRING("updateTime"),
	HX_CSTRING("drawTime"),
	HX_CSTRING("_lastTime"),
	HX_CSTRING("_updateTimer"),
	HX_CSTRING("_update"),
	HX_CSTRING("_updateMarker"),
	HX_CSTRING("_draw"),
	HX_CSTRING("_drawMarker"),
	HX_CSTRING("_visibleObject"),
	HX_CSTRING("_visibleObjectMarker"),
	HX_CSTRING("_activeObject"),
	HX_CSTRING("_activeObjectMarker"),
	HX_CSTRING("_paused"),
	HX_CSTRING("drawCallsCount"),
	HX_CSTRING("_drawCalls"),
	HX_CSTRING("_drawCallsMarker"),
	HX_CSTRING("start"),
	HX_CSTRING("stop"),
	HX_CSTRING("destroy"),
	HX_CSTRING("update"),
	HX_CSTRING("updateTexts"),
	HX_CSTRING("currentFps"),
	HX_CSTRING("averageFps"),
	HX_CSTRING("runningTime"),
	HX_CSTRING("intervalTime"),
	HX_CSTRING("currentMem"),
	HX_CSTRING("flixelUpdate"),
	HX_CSTRING("flixelDraw"),
	HX_CSTRING("activeObjects"),
	HX_CSTRING("visibleObjects"),
	HX_CSTRING("drawCalls"),
	HX_CSTRING("onFocus"),
	HX_CSTRING("onFocusLost"),
	String(null()) };

static void sMarkStatics(HX_MARK_PARAMS) {
	HX_MARK_MEMBER_NAME(Stats_obj::__mClass,"__mClass");
	HX_MARK_MEMBER_NAME(Stats_obj::UPDATE_DELAY,"UPDATE_DELAY");
	HX_MARK_MEMBER_NAME(Stats_obj::INITIAL_WIDTH,"INITIAL_WIDTH");
	HX_MARK_MEMBER_NAME(Stats_obj::MIN_HEIGHT,"MIN_HEIGHT");
	HX_MARK_MEMBER_NAME(Stats_obj::FPS_COLOR,"FPS_COLOR");
	HX_MARK_MEMBER_NAME(Stats_obj::MEMORY_COLOR,"MEMORY_COLOR");
	HX_MARK_MEMBER_NAME(Stats_obj::LABEL_COLOR,"LABEL_COLOR");
	HX_MARK_MEMBER_NAME(Stats_obj::TEXT_SIZE,"TEXT_SIZE");
	HX_MARK_MEMBER_NAME(Stats_obj::DECIMALS,"DECIMALS");
};

#ifdef HXCPP_VISIT_ALLOCS
static void sVisitStatics(HX_VISIT_PARAMS) {
	HX_VISIT_MEMBER_NAME(Stats_obj::__mClass,"__mClass");
	HX_VISIT_MEMBER_NAME(Stats_obj::UPDATE_DELAY,"UPDATE_DELAY");
	HX_VISIT_MEMBER_NAME(Stats_obj::INITIAL_WIDTH,"INITIAL_WIDTH");
	HX_VISIT_MEMBER_NAME(Stats_obj::MIN_HEIGHT,"MIN_HEIGHT");
	HX_VISIT_MEMBER_NAME(Stats_obj::FPS_COLOR,"FPS_COLOR");
	HX_VISIT_MEMBER_NAME(Stats_obj::MEMORY_COLOR,"MEMORY_COLOR");
	HX_VISIT_MEMBER_NAME(Stats_obj::LABEL_COLOR,"LABEL_COLOR");
	HX_VISIT_MEMBER_NAME(Stats_obj::TEXT_SIZE,"TEXT_SIZE");
	HX_VISIT_MEMBER_NAME(Stats_obj::DECIMALS,"DECIMALS");
};

#endif

Class Stats_obj::__mClass;

void Stats_obj::__register()
{
	hx::Static(__mClass) = hx::RegisterClass(HX_CSTRING("flixel.system.debug.Stats"), hx::TCanCast< Stats_obj> ,sStaticFields,sMemberFields,
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

void Stats_obj::__boot()
{
	UPDATE_DELAY= (int)250;
	INITIAL_WIDTH= (int)160;
	MIN_HEIGHT= (int)195;
	FPS_COLOR= (int)-6881536;
	MEMORY_COLOR= (int)-16737025;
	LABEL_COLOR= (int)-1426063361;
	TEXT_SIZE= (int)11;
	DECIMALS= (int)1;
}

} // end namespace flixel
} // end namespace system
} // end namespace debug
