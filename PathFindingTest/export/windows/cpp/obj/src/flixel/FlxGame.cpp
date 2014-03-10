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
#ifndef INCLUDED_flash_Lib
#include <flash/Lib.h>
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
#ifndef INCLUDED_flash_display_MovieClip
#include <flash/display/MovieClip.h>
#endif
#ifndef INCLUDED_flash_display_Sprite
#include <flash/display/Sprite.h>
#endif
#ifndef INCLUDED_flash_display_Stage
#include <flash/display/Stage.h>
#endif
#ifndef INCLUDED_flash_display_StageAlign
#include <flash/display/StageAlign.h>
#endif
#ifndef INCLUDED_flash_display_StageScaleMode
#include <flash/display/StageScaleMode.h>
#endif
#ifndef INCLUDED_flash_events_Event
#include <flash/events/Event.h>
#endif
#ifndef INCLUDED_flash_events_EventDispatcher
#include <flash/events/EventDispatcher.h>
#endif
#ifndef INCLUDED_flash_events_FocusEvent
#include <flash/events/FocusEvent.h>
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
#ifndef INCLUDED_flixel_FlxGame
#include <flixel/FlxGame.h>
#endif
#ifndef INCLUDED_flixel_FlxObject
#include <flixel/FlxObject.h>
#endif
#ifndef INCLUDED_flixel_FlxState
#include <flixel/FlxState.h>
#endif
#ifndef INCLUDED_flixel_FlxSubState
#include <flixel/FlxSubState.h>
#endif
#ifndef INCLUDED_flixel_group_FlxGroup
#include <flixel/group/FlxGroup.h>
#endif
#ifndef INCLUDED_flixel_group_FlxTypedGroup
#include <flixel/group/FlxTypedGroup.h>
#endif
#ifndef INCLUDED_flixel_input_FlxSwipe
#include <flixel/input/FlxSwipe.h>
#endif
#ifndef INCLUDED_flixel_input_mouse_FlxMouse
#include <flixel/input/mouse/FlxMouse.h>
#endif
#ifndef INCLUDED_flixel_interfaces_IFlxDestroyable
#include <flixel/interfaces/IFlxDestroyable.h>
#endif
#ifndef INCLUDED_flixel_interfaces_IFlxInput
#include <flixel/interfaces/IFlxInput.h>
#endif
#ifndef INCLUDED_flixel_plugin_FlxPlugin
#include <flixel/plugin/FlxPlugin.h>
#endif
#ifndef INCLUDED_flixel_system_debug_Console
#include <flixel/system/debug/Console.h>
#endif
#ifndef INCLUDED_flixel_system_debug_FlxDebugger
#include <flixel/system/debug/FlxDebugger.h>
#endif
#ifndef INCLUDED_flixel_system_debug_Log
#include <flixel/system/debug/Log.h>
#endif
#ifndef INCLUDED_flixel_system_debug_LogStyle
#include <flixel/system/debug/LogStyle.h>
#endif
#ifndef INCLUDED_flixel_system_debug_Stats
#include <flixel/system/debug/Stats.h>
#endif
#ifndef INCLUDED_flixel_system_debug_Watch
#include <flixel/system/debug/Watch.h>
#endif
#ifndef INCLUDED_flixel_system_debug_Window
#include <flixel/system/debug/Window.h>
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
#ifndef INCLUDED_flixel_system_frontEnds_InputFrontEnd
#include <flixel/system/frontEnds/InputFrontEnd.h>
#endif
#ifndef INCLUDED_flixel_system_frontEnds_LogFrontEnd
#include <flixel/system/frontEnds/LogFrontEnd.h>
#endif
#ifndef INCLUDED_flixel_system_frontEnds_PluginFrontEnd
#include <flixel/system/frontEnds/PluginFrontEnd.h>
#endif
#ifndef INCLUDED_flixel_system_frontEnds_SoundFrontEnd
#include <flixel/system/frontEnds/SoundFrontEnd.h>
#endif
#ifndef INCLUDED_flixel_system_frontEnds_VCRFrontEnd
#include <flixel/system/frontEnds/VCRFrontEnd.h>
#endif
#ifndef INCLUDED_flixel_system_layer_TileSheetExt
#include <flixel/system/layer/TileSheetExt.h>
#endif
#ifndef INCLUDED_flixel_system_scaleModes_BaseScaleMode
#include <flixel/system/scaleModes/BaseScaleMode.h>
#endif
#ifndef INCLUDED_flixel_system_ui_FlxFocusLostScreen
#include <flixel/system/ui/FlxFocusLostScreen.h>
#endif
#ifndef INCLUDED_flixel_system_ui_FlxSoundTray
#include <flixel/system/ui/FlxSoundTray.h>
#endif
#ifndef INCLUDED_flixel_text_pxText_PxBitmapFont
#include <flixel/text/pxText/PxBitmapFont.h>
#endif
#ifndef INCLUDED_flixel_util_FlxPoint
#include <flixel/util/FlxPoint.h>
#endif
#ifndef INCLUDED_haxe_ds_StringMap
#include <haxe/ds/StringMap.h>
#endif
#ifndef INCLUDED_openfl_display_Tilesheet
#include <openfl/display/Tilesheet.h>
#endif
namespace flixel{

Void FlxGame_obj::__construct(hx::Null< int >  __o_GameSizeX,hx::Null< int >  __o_GameSizeY,::Class InitialState,hx::Null< Float >  __o_Zoom,hx::Null< int >  __o_UpdateFramerate,hx::Null< int >  __o_DrawFramerate,hx::Null< bool >  __o_SkipSplash,hx::Null< bool >  __o_StartFullscreen)
{
HX_STACK_FRAME("flixel.FlxGame","new",0xde7d5f44,"flixel.FlxGame.new","flixel/FlxGame.hx",36,0x34f39fed)

HX_STACK_ARG(__o_GameSizeX,"GameSizeX")

HX_STACK_ARG(__o_GameSizeY,"GameSizeY")

HX_STACK_ARG(InitialState,"InitialState")

HX_STACK_ARG(__o_Zoom,"Zoom")

HX_STACK_ARG(__o_UpdateFramerate,"UpdateFramerate")

HX_STACK_ARG(__o_DrawFramerate,"DrawFramerate")

HX_STACK_ARG(__o_SkipSplash,"SkipSplash")

HX_STACK_ARG(__o_StartFullscreen,"StartFullscreen")
int GameSizeX = __o_GameSizeX.Default(640);
int GameSizeY = __o_GameSizeY.Default(480);
Float Zoom = __o_Zoom.Default(1);
int UpdateFramerate = __o_UpdateFramerate.Default(60);
int DrawFramerate = __o_DrawFramerate.Default(60);
bool SkipSplash = __o_SkipSplash.Default(false);
bool StartFullscreen = __o_StartFullscreen.Default(false);
{
	HX_STACK_LINE(172)
	this->_resetGame = false;
	HX_STACK_LINE(162)
	this->_startFullscreen = false;
	HX_STACK_LINE(157)
	this->_skipSplash = false;
	HX_STACK_LINE(152)
	this->_customFocusLostScreen = hx::ClassOf< ::flixel::system::ui::FlxFocusLostScreen >();
	HX_STACK_LINE(145)
	this->_customSoundTray = hx::ClassOf< ::flixel::system::ui::FlxSoundTray >();
	HX_STACK_LINE(124)
	this->_onFocusFiredOnce = false;
	HX_STACK_LINE(117)
	this->_lostFocus = false;
	HX_STACK_LINE(90)
	this->_total = (int)0;
	HX_STACK_LINE(77)
	this->_gameJustStarted = false;
	HX_STACK_LINE(71)
	this->ticks = (int)0;
	HX_STACK_LINE(41)
	this->focusLostFramerate = (int)10;
	HX_STACK_LINE(203)
	super::__construct();
	HX_STACK_LINE(206)
	this->_startFullscreen = StartFullscreen;
	HX_STACK_LINE(210)
	this->_inputContainer = ::flash::display::Sprite_obj::__new();
	HX_STACK_LINE(213)
	::flixel::FlxG_obj::init(hx::ObjectPtr<OBJ_>(this),GameSizeX,GameSizeY,Zoom);
	HX_STACK_LINE(215)
	::flixel::FlxG_obj::set_updateFramerate(UpdateFramerate);
	HX_STACK_LINE(216)
	::flixel::FlxG_obj::set_drawFramerate(DrawFramerate);
	HX_STACK_LINE(217)
	this->_accumulator = this->_stepMS;
	HX_STACK_LINE(218)
	this->_skipSplash = SkipSplash;
	HX_STACK_LINE(225)
	if (((InitialState == null()))){
		HX_STACK_LINE(225)
		this->_initialState = hx::ClassOf< ::flixel::FlxState >();
	}
	else{
		HX_STACK_LINE(225)
		this->_initialState = InitialState;
	}
	HX_STACK_LINE(227)
	this->addEventListener(::flash::events::Event_obj::ADDED_TO_STAGE,this->create_dyn(),null(),null(),null());
}
;
	return null();
}

//FlxGame_obj::~FlxGame_obj() { }

Dynamic FlxGame_obj::__CreateEmpty() { return  new FlxGame_obj; }
hx::ObjectPtr< FlxGame_obj > FlxGame_obj::__new(hx::Null< int >  __o_GameSizeX,hx::Null< int >  __o_GameSizeY,::Class InitialState,hx::Null< Float >  __o_Zoom,hx::Null< int >  __o_UpdateFramerate,hx::Null< int >  __o_DrawFramerate,hx::Null< bool >  __o_SkipSplash,hx::Null< bool >  __o_StartFullscreen)
{  hx::ObjectPtr< FlxGame_obj > result = new FlxGame_obj();
	result->__construct(__o_GameSizeX,__o_GameSizeY,InitialState,__o_Zoom,__o_UpdateFramerate,__o_DrawFramerate,__o_SkipSplash,__o_StartFullscreen);
	return result;}

Dynamic FlxGame_obj::__Create(hx::DynamicArray inArgs)
{  hx::ObjectPtr< FlxGame_obj > result = new FlxGame_obj();
	result->__construct(inArgs[0],inArgs[1],inArgs[2],inArgs[3],inArgs[4],inArgs[5],inArgs[6],inArgs[7]);
	return result;}

Void FlxGame_obj::create( ::flash::events::Event FlashEvent){
{
		HX_STACK_FRAME("flixel.FlxGame","create",0x90873e98,"flixel.FlxGame.create","flixel/FlxGame.hx",234,0x34f39fed)
		HX_STACK_THIS(this)
		HX_STACK_ARG(FlashEvent,"FlashEvent")
		HX_STACK_LINE(235)
		if (((this->get_stage() == null()))){
			HX_STACK_LINE(237)
			return null();
		}
		HX_STACK_LINE(239)
		this->removeEventListener(::flash::events::Event_obj::ADDED_TO_STAGE,this->create_dyn(),null());
		HX_STACK_LINE(241)
		this->_total = ::flash::Lib_obj::getTimer();
		HX_STACK_LINE(244)
		::flixel::FlxG_obj::set_fullscreen(this->_startFullscreen);
		HX_STACK_LINE(248)
		this->get_stage()->set_scaleMode(::flash::display::StageScaleMode_obj::NO_SCALE);
		HX_STACK_LINE(249)
		this->get_stage()->set_align(::flash::display::StageAlign_obj::TOP_LEFT);
		HX_STACK_LINE(250)
		this->get_stage()->set_frameRate(::flixel::FlxG_obj::drawFramerate);
		HX_STACK_LINE(252)
		this->addChild(this->_inputContainer);
		HX_STACK_LINE(256)
		int _g = ::flash::Lib_obj::get_current()->get_stage()->get_stageWidth();		HX_STACK_VAR(_g,"_g");
		HX_STACK_LINE(256)
		this->debugger = ::flixel::system::debug::FlxDebugger_obj::__new(_g,::flash::Lib_obj::get_current()->get_stage()->get_stageHeight());
		HX_STACK_LINE(257)
		this->addChild(this->debugger);
		HX_STACK_LINE(264)
		this->soundTray = ::Type_obj::createInstance(this->_customSoundTray,Dynamic( Array_obj<Dynamic>::__new()));
		HX_STACK_LINE(265)
		this->addChild(this->soundTray);
		HX_STACK_LINE(269)
		this->_focusLostScreen = ::Type_obj::createInstance(this->_customFocusLostScreen,Dynamic( Array_obj<Dynamic>::__new()));
		HX_STACK_LINE(270)
		this->addChild(this->_focusLostScreen);
		HX_STACK_LINE(276)
		this->get_stage()->addEventListener(::flash::events::FocusEvent_obj::FOCUS_OUT,this->onFocusLost_dyn(),null(),null(),null());
		HX_STACK_LINE(277)
		this->get_stage()->addEventListener(::flash::events::FocusEvent_obj::FOCUS_IN,this->onFocus_dyn(),null(),null(),null());
		HX_STACK_LINE(284)
		{
			HX_STACK_LINE(284)
			this->_requestedState = ::Type_obj::createInstance(this->_initialState,Dynamic( Array_obj<Dynamic>::__new()));
			HX_STACK_LINE(284)
			this->_gameJustStarted = true;
			HX_STACK_LINE(284)
			if ((::Std_obj::is(this->_requestedState,hx::ClassOf< ::flixel::FlxSubState >()))){
				HX_STACK_LINE(284)
				HX_STACK_DO_THROW(HX_CSTRING("You can't set FlxSubState class instance as the state for you game"));
			}
			HX_STACK_LINE(284)
			::flixel::FlxG_obj::reset();
		}
		HX_STACK_LINE(285)
		this->switchState();
		HX_STACK_LINE(287)
		if (((::Std_obj::_int((Float((int)1000) / Float(::flixel::FlxG_obj::game->_stepMS))) < ::flixel::FlxG_obj::drawFramerate))){
			HX_STACK_LINE(289)
			::flixel::FlxG_obj::log->advanced(HX_CSTRING("FlxG.updateFramerate: The update framerate shouldn't be smaller than the draw framerate, since it can slow down your game."),::flixel::system::debug::LogStyle_obj::WARNING,true);
		}
		HX_STACK_LINE(293)
		this->get_stage()->addEventListener(::flash::events::Event_obj::ENTER_FRAME,this->onEnterFrame_dyn(),null(),null(),null());
		HX_STACK_LINE(297)
		this->get_stage()->addEventListener(::flash::events::Event_obj::RESIZE,this->onResize_dyn(),null(),null(),null());
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC1(FlxGame_obj,create,(void))

Void FlxGame_obj::onFocus( ::flash::events::Event FlashEvent){
{
		HX_STACK_FRAME("flixel.FlxGame","onFocus",0x6f2bcf1d,"flixel.FlxGame.onFocus","flixel/FlxGame.hx",301,0x34f39fed)
		HX_STACK_THIS(this)
		HX_STACK_ARG(FlashEvent,"FlashEvent")
		HX_STACK_LINE(311)
		if ((!(this->_onFocusFiredOnce))){
			HX_STACK_LINE(313)
			this->_onFocusFiredOnce = true;
			HX_STACK_LINE(314)
			return null();
		}
		HX_STACK_LINE(318)
		this->_lostFocus = false;
		HX_STACK_LINE(320)
		if ((!(::flixel::FlxG_obj::autoPause))){
			HX_STACK_LINE(322)
			this->_state->onFocus();
			HX_STACK_LINE(323)
			return null();
		}
		HX_STACK_LINE(327)
		if (((this->_focusLostScreen != null()))){
			HX_STACK_LINE(329)
			this->_focusLostScreen->set_visible(false);
		}
		HX_STACK_LINE(334)
		this->debugger->stats->onFocus();
		HX_STACK_LINE(337)
		this->get_stage()->set_frameRate(::flixel::FlxG_obj::drawFramerate);
		HX_STACK_LINE(339)
		::flixel::FlxG_obj::sound->onFocus();
		HX_STACK_LINE(341)
		{
			HX_STACK_LINE(341)
			int _g = (int)0;		HX_STACK_VAR(_g,"_g");
			HX_STACK_LINE(341)
			Array< ::flixel::interfaces::IFlxInput > _g1 = ::flixel::FlxG_obj::inputs->list;		HX_STACK_VAR(_g1,"_g1");
			HX_STACK_LINE(341)
			while(((_g < _g1->length))){
				HX_STACK_LINE(341)
				::flixel::interfaces::IFlxInput input = _g1->__get(_g);		HX_STACK_VAR(input,"input");
				HX_STACK_LINE(341)
				++(_g);
				HX_STACK_LINE(341)
				input->onFocus();
			}
		}
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC1(FlxGame_obj,onFocus,(void))

Void FlxGame_obj::onFocusLost( ::flash::events::Event FlashEvent){
{
		HX_STACK_FRAME("flixel.FlxGame","onFocusLost",0xb7eef7a1,"flixel.FlxGame.onFocusLost","flixel/FlxGame.hx",345,0x34f39fed)
		HX_STACK_THIS(this)
		HX_STACK_ARG(FlashEvent,"FlashEvent")
		HX_STACK_LINE(353)
		this->_lostFocus = true;
		HX_STACK_LINE(355)
		if ((!(::flixel::FlxG_obj::autoPause))){
			HX_STACK_LINE(357)
			this->_state->onFocusLost();
			HX_STACK_LINE(358)
			return null();
		}
		HX_STACK_LINE(362)
		if (((this->_focusLostScreen != null()))){
			HX_STACK_LINE(364)
			this->_focusLostScreen->set_visible(true);
		}
		HX_STACK_LINE(369)
		this->debugger->stats->onFocusLost();
		HX_STACK_LINE(372)
		this->get_stage()->set_frameRate(this->focusLostFramerate);
		HX_STACK_LINE(374)
		::flixel::FlxG_obj::sound->onFocusLost();
		HX_STACK_LINE(376)
		{
			HX_STACK_LINE(376)
			int _g = (int)0;		HX_STACK_VAR(_g,"_g");
			HX_STACK_LINE(376)
			Array< ::flixel::interfaces::IFlxInput > _g1 = ::flixel::FlxG_obj::inputs->list;		HX_STACK_VAR(_g1,"_g1");
			HX_STACK_LINE(376)
			while(((_g < _g1->length))){
				HX_STACK_LINE(376)
				::flixel::interfaces::IFlxInput input = _g1->__get(_g);		HX_STACK_VAR(input,"input");
				HX_STACK_LINE(376)
				++(_g);
				HX_STACK_LINE(376)
				input->onFocusLost();
			}
		}
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC1(FlxGame_obj,onFocusLost,(void))

Void FlxGame_obj::onResize( ::flash::events::Event E){
{
		HX_STACK_FRAME("flixel.FlxGame","onResize",0xebfa470f,"flixel.FlxGame.onResize","flixel/FlxGame.hx",381,0x34f39fed)
		HX_STACK_THIS(this)
		HX_STACK_ARG(E,"E")
		HX_STACK_LINE(382)
		int width = ::flash::Lib_obj::get_current()->get_stage()->get_stageWidth();		HX_STACK_VAR(width,"width");
		HX_STACK_LINE(383)
		int height = ::flash::Lib_obj::get_current()->get_stage()->get_stageHeight();		HX_STACK_VAR(height,"height");
		HX_STACK_LINE(386)
		::flixel::FlxG_obj::bitmap->onContext();
		HX_STACK_LINE(389)
		::flixel::FlxG_obj::_scaleMode->onMeasure(width,height);
		HX_STACK_LINE(391)
		this->_state->onResize(width,height);
		HX_STACK_LINE(392)
		{
			HX_STACK_LINE(392)
			int _g = (int)0;		HX_STACK_VAR(_g,"_g");
			HX_STACK_LINE(392)
			Array< ::Dynamic > _g1 = ::flixel::FlxG_obj::plugins->list;		HX_STACK_VAR(_g1,"_g1");
			HX_STACK_LINE(392)
			while(((_g < _g1->length))){
				HX_STACK_LINE(392)
				::flixel::plugin::FlxPlugin plugin = _g1->__get(_g).StaticCast< ::flixel::plugin::FlxPlugin >();		HX_STACK_VAR(plugin,"plugin");
				HX_STACK_LINE(392)
				++(_g);
				HX_STACK_LINE(392)
				if ((plugin->exists)){
					HX_STACK_LINE(392)
					plugin->onResize(width,height);
				}
			}
		}
		HX_STACK_LINE(395)
		{
			HX_STACK_LINE(395)
			::flixel::system::debug::FlxDebugger _this = this->debugger;		HX_STACK_VAR(_this,"_this");
			HX_STACK_LINE(395)
			_this->_screen->x = width;
			HX_STACK_LINE(395)
			_this->_screen->y = height;
			HX_STACK_LINE(395)
			_this->_screenBounds = ::flash::geom::Rectangle_obj::__new((int)2,21.,(_this->_screen->x - (int)4),((_this->_screen->y - (int)4) - (int)20));
			HX_STACK_LINE(395)
			_this->stats->updateBounds(_this->_screenBounds);
			HX_STACK_LINE(395)
			_this->log->updateBounds(_this->_screenBounds);
			HX_STACK_LINE(395)
			_this->watch->updateBounds(_this->_screenBounds);
			HX_STACK_LINE(395)
			_this->console->updateBounds(_this->_screenBounds);
			HX_STACK_LINE(395)
			_this->_topBar->set_width(::flash::Lib_obj::get_current()->get_stage()->get_stageWidth());
			HX_STACK_LINE(395)
			_this->resetButtonLayout();
			HX_STACK_LINE(395)
			_this->resetLayout();
			HX_STACK_LINE(395)
			_this->set_scaleX((Float((int)1) / Float(::flixel::FlxG_obj::game->get_scaleX())));
			HX_STACK_LINE(395)
			_this->set_scaleY((Float((int)1) / Float(::flixel::FlxG_obj::game->get_scaleY())));
			HX_STACK_LINE(395)
			Float _g = ::flixel::FlxG_obj::game->get_x();		HX_STACK_VAR(_g,"_g");
			HX_STACK_LINE(395)
			_this->set_x((-(_g) * _this->get_scaleX()));
			HX_STACK_LINE(395)
			Float _g1 = ::flixel::FlxG_obj::game->get_y();		HX_STACK_VAR(_g1,"_g1");
			HX_STACK_LINE(395)
			_this->set_y((-(_g1) * _this->get_scaleY()));
		}
		HX_STACK_LINE(399)
		if (((this->_focusLostScreen != null()))){
			HX_STACK_LINE(401)
			this->_focusLostScreen->draw();
		}
		HX_STACK_LINE(406)
		if (((this->soundTray != null()))){
			HX_STACK_LINE(408)
			this->soundTray->screenCenter();
		}
		HX_STACK_LINE(412)
		this->_inputContainer->set_scaleX((Float((int)1) / Float(::flixel::FlxG_obj::game->get_scaleX())));
		HX_STACK_LINE(413)
		this->_inputContainer->set_scaleY((Float((int)1) / Float(::flixel::FlxG_obj::game->get_scaleY())));
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC1(FlxGame_obj,onResize,(void))

Void FlxGame_obj::onEnterFrame( ::flash::events::Event FlashEvent){
{
		HX_STACK_FRAME("flixel.FlxGame","onEnterFrame",0x001b1a90,"flixel.FlxGame.onEnterFrame","flixel/FlxGame.hx",420,0x34f39fed)
		HX_STACK_THIS(this)
		HX_STACK_ARG(FlashEvent,"FlashEvent")
		HX_STACK_LINE(421)
		this->ticks = ::flash::Lib_obj::getTimer();
		HX_STACK_LINE(422)
		this->_elapsedMS = (this->ticks - this->_total);
		HX_STACK_LINE(423)
		this->_total = this->ticks;
		HX_STACK_LINE(426)
		if (((bool((this->soundTray != null())) && bool(this->soundTray->active)))){
			HX_STACK_LINE(428)
			this->soundTray->update(this->_elapsedMS);
		}
		HX_STACK_LINE(432)
		if (((bool(!(this->_lostFocus)) || bool(!(::flixel::FlxG_obj::autoPause))))){
			HX_STACK_LINE(434)
			if ((::flixel::FlxG_obj::vcr->paused)){
				HX_STACK_LINE(436)
				if ((::flixel::FlxG_obj::vcr->stepRequested)){
					HX_STACK_LINE(438)
					::flixel::FlxG_obj::vcr->stepRequested = false;
				}
				else{
					HX_STACK_LINE(440)
					if (((this->_state == this->_requestedState))){
						HX_STACK_LINE(442)
						return null();
					}
				}
			}
			HX_STACK_LINE(446)
			if ((::flixel::FlxG_obj::fixedTimestep)){
				HX_STACK_LINE(448)
				hx::AddEq(this->_accumulator,this->_elapsedMS);
				HX_STACK_LINE(449)
				if (((this->_accumulator > this->_maxAccumulation))){
					HX_STACK_LINE(451)
					this->_accumulator = this->_maxAccumulation;
				}
				HX_STACK_LINE(454)
				while(((this->_accumulator > this->_stepMS))){
					HX_STACK_LINE(457)
					this->step();
					HX_STACK_LINE(458)
					this->_accumulator = (this->_accumulator - this->_stepMS);
				}
			}
			else{
				HX_STACK_LINE(463)
				this->step();
			}
			HX_STACK_LINE(467)
			::flixel::FlxBasic_obj::_VISIBLECOUNT = (int)0;
			HX_STACK_LINE(470)
			this->draw();
			HX_STACK_LINE(473)
			if ((::flixel::FlxG_obj::debugger->visible)){
				HX_STACK_LINE(475)
				this->debugger->watch->update();
			}
			HX_STACK_LINE(477)
			this->debugger->stats->visibleObjects(::flixel::FlxBasic_obj::_VISIBLECOUNT);
			HX_STACK_LINE(478)
			this->debugger->stats->update();
		}
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC1(FlxGame_obj,onEnterFrame,(void))

Void FlxGame_obj::resetGame( ){
{
		HX_STACK_FRAME("flixel.FlxGame","resetGame",0xde30cf45,"flixel.FlxGame.resetGame","flixel/FlxGame.hx",488,0x34f39fed)
		HX_STACK_THIS(this)
		HX_STACK_LINE(490)
		this->_requestedState = ::Type_obj::createInstance(this->_initialState,Dynamic( Array_obj<Dynamic>::__new()));
		HX_STACK_LINE(491)
		this->_gameJustStarted = true;
		HX_STACK_LINE(506)
		if ((::Std_obj::is(this->_requestedState,hx::ClassOf< ::flixel::FlxSubState >()))){
			HX_STACK_LINE(508)
			HX_STACK_DO_THROW(HX_CSTRING("You can't set FlxSubState class instance as the state for you game"));
		}
		HX_STACK_LINE(512)
		::flixel::FlxG_obj::reset();
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC0(FlxGame_obj,resetGame,(void))

Void FlxGame_obj::switchState( ){
{
		HX_STACK_FRAME("flixel.FlxGame","switchState",0xedf41a61,"flixel.FlxGame.switchState","flixel/FlxGame.hx",521,0x34f39fed)
		HX_STACK_THIS(this)
		HX_STACK_LINE(523)
		::flixel::text::pxText::PxBitmapFont_obj::clearStorage();
		HX_STACK_LINE(524)
		::flixel::FlxG_obj::bitmap->clearCache();
		HX_STACK_LINE(525)
		::flixel::FlxG_obj::cameras->reset(null());
		HX_STACK_LINE(526)
		::flixel::FlxG_obj::inputs->reset();
		HX_STACK_LINE(528)
		::flixel::FlxG_obj::sound->destroy(null());
		HX_STACK_LINE(530)
		{
			HX_STACK_LINE(530)
			int _g = (int)0;		HX_STACK_VAR(_g,"_g");
			HX_STACK_LINE(530)
			Array< ::Dynamic > _g1 = ::flixel::FlxG_obj::plugins->list;		HX_STACK_VAR(_g1,"_g1");
			HX_STACK_LINE(530)
			while(((_g < _g1->length))){
				HX_STACK_LINE(530)
				::flixel::plugin::FlxPlugin plugin = _g1->__get(_g).StaticCast< ::flixel::plugin::FlxPlugin >();		HX_STACK_VAR(plugin,"plugin");
				HX_STACK_LINE(530)
				++(_g);
				HX_STACK_LINE(530)
				if ((plugin->exists)){
					HX_STACK_LINE(530)
					plugin->onStateSwitch();
				}
			}
		}
		HX_STACK_LINE(538)
		if (((this->debugger != null()))){
			HX_STACK_LINE(540)
			this->debugger->watch->removeAll();
		}
		HX_STACK_LINE(545)
		if (((this->_state != null()))){
			HX_STACK_LINE(547)
			this->_state->destroy();
		}
		HX_STACK_LINE(551)
		this->_state = this->_requestedState;
		HX_STACK_LINE(553)
		this->_state->create();
		HX_STACK_LINE(555)
		if ((this->_gameJustStarted)){
			HX_STACK_LINE(557)
			this->gameStart();
		}
		HX_STACK_LINE(561)
		{
			HX_STACK_LINE(561)
			Dynamic value = this->_state;		HX_STACK_VAR(value,"value");
			HX_STACK_LINE(561)
			this->debugger->console->registeredObjects->set(HX_CSTRING("state"),value);
		}
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC0(FlxGame_obj,switchState,(void))

Void FlxGame_obj::gameStart( ){
{
		HX_STACK_FRAME("flixel.FlxGame","gameStart",0x0d0c34f4,"flixel.FlxGame.gameStart","flixel/FlxGame.hx",566,0x34f39fed)
		HX_STACK_THIS(this)
		HX_STACK_LINE(568)
		::flixel::FlxG_obj::mouse->onGameStart();
		HX_STACK_LINE(570)
		this->_gameJustStarted = false;
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC0(FlxGame_obj,gameStart,(void))

Void FlxGame_obj::step( ){
{
		HX_STACK_FRAME("flixel.FlxGame","step",0xd28f5fe8,"flixel.FlxGame.step","flixel/FlxGame.hx",580,0x34f39fed)
		HX_STACK_THIS(this)
		HX_STACK_LINE(582)
		if ((this->_resetGame)){
			HX_STACK_LINE(584)
			{
				HX_STACK_LINE(584)
				this->_requestedState = ::Type_obj::createInstance(this->_initialState,Dynamic( Array_obj<Dynamic>::__new()));
				HX_STACK_LINE(584)
				this->_gameJustStarted = true;
				HX_STACK_LINE(584)
				if ((::Std_obj::is(this->_requestedState,hx::ClassOf< ::flixel::FlxSubState >()))){
					HX_STACK_LINE(584)
					HX_STACK_DO_THROW(HX_CSTRING("You can't set FlxSubState class instance as the state for you game"));
				}
				HX_STACK_LINE(584)
				::flixel::FlxG_obj::reset();
			}
			HX_STACK_LINE(585)
			this->_resetGame = false;
		}
		HX_STACK_LINE(617)
		::flixel::FlxBasic_obj::_ACTIVECOUNT = (int)0;
		HX_STACK_LINE(620)
		this->update();
		HX_STACK_LINE(623)
		this->debugger->stats->activeObjects(::flixel::FlxBasic_obj::_ACTIVECOUNT);
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC0(FlxGame_obj,step,(void))

Void FlxGame_obj::update( ){
{
		HX_STACK_FRAME("flixel.FlxGame","update",0x9b7d5da5,"flixel.FlxGame.update","flixel/FlxGame.hx",632,0x34f39fed)
		HX_STACK_THIS(this)
		HX_STACK_LINE(633)
		if (((this->_state != this->_requestedState))){
			HX_STACK_LINE(635)
			this->switchState();
		}
		HX_STACK_LINE(639)
		if ((::flixel::FlxG_obj::debugger->visible)){
			HX_STACK_LINE(641)
			this->ticks = ::flash::Lib_obj::getTimer();
		}
		HX_STACK_LINE(645)
		if ((::flixel::FlxG_obj::fixedTimestep)){
			HX_STACK_LINE(647)
			::flixel::FlxG_obj::elapsed = (::flixel::FlxG_obj::timeScale * this->_stepSeconds);
		}
		else{
			HX_STACK_LINE(651)
			::flixel::FlxG_obj::elapsed = (::flixel::FlxG_obj::timeScale * ((Float(this->_elapsedMS) / Float((int)1000))));
		}
		HX_STACK_LINE(654)
		this->updateInput();
		HX_STACK_LINE(657)
		::flixel::FlxG_obj::sound->update();
		HX_STACK_LINE(659)
		{
			HX_STACK_LINE(659)
			int _g = (int)0;		HX_STACK_VAR(_g,"_g");
			HX_STACK_LINE(659)
			Array< ::Dynamic > _g1 = ::flixel::FlxG_obj::plugins->list;		HX_STACK_VAR(_g1,"_g1");
			HX_STACK_LINE(659)
			while(((_g < _g1->length))){
				HX_STACK_LINE(659)
				::flixel::plugin::FlxPlugin plugin = _g1->__get(_g).StaticCast< ::flixel::plugin::FlxPlugin >();		HX_STACK_VAR(plugin,"plugin");
				HX_STACK_LINE(659)
				++(_g);
				HX_STACK_LINE(659)
				if (((bool(plugin->exists) && bool(plugin->active)))){
					HX_STACK_LINE(659)
					plugin->update();
				}
			}
		}
		HX_STACK_LINE(661)
		this->_state->tryUpdate();
		HX_STACK_LINE(663)
		{
			HX_STACK_LINE(663)
			int _g = (int)0;		HX_STACK_VAR(_g,"_g");
			HX_STACK_LINE(663)
			Array< ::Dynamic > _g1 = ::flixel::FlxG_obj::cameras->list;		HX_STACK_VAR(_g1,"_g1");
			HX_STACK_LINE(663)
			while(((_g < _g1->length))){
				HX_STACK_LINE(663)
				::flixel::FlxCamera camera = _g1->__get(_g).StaticCast< ::flixel::FlxCamera >();		HX_STACK_VAR(camera,"camera");
				HX_STACK_LINE(663)
				++(_g);
				HX_STACK_LINE(663)
				if (((bool((camera != null())) && bool(camera->exists)))){
					HX_STACK_LINE(663)
					if ((camera->active)){
						HX_STACK_LINE(663)
						camera->update();
					}
					HX_STACK_LINE(663)
					if (((camera->target == null()))){
						HX_STACK_LINE(663)
						camera->flashSprite->set_x((camera->x + camera->_flashOffset->x));
						HX_STACK_LINE(663)
						camera->flashSprite->set_y((camera->y + camera->_flashOffset->y));
					}
					HX_STACK_LINE(663)
					camera->flashSprite->set_visible(camera->visible);
				}
			}
		}
		HX_STACK_LINE(666)
		this->debugger->stats->flixelUpdate((::flash::Lib_obj::getTimer() - this->ticks));
		HX_STACK_LINE(670)
		{
			HX_STACK_LINE(670)
			int _g = (int)0;		HX_STACK_VAR(_g,"_g");
			HX_STACK_LINE(670)
			Array< ::Dynamic > _g1 = ::flixel::FlxG_obj::swipes;		HX_STACK_VAR(_g1,"_g1");
			HX_STACK_LINE(670)
			while(((_g < _g1->length))){
				HX_STACK_LINE(670)
				::flixel::input::FlxSwipe swipe = _g1->__get(_g).StaticCast< ::flixel::input::FlxSwipe >();		HX_STACK_VAR(swipe,"swipe");
				HX_STACK_LINE(670)
				++(_g);
				HX_STACK_LINE(672)
				swipe = null();
			}
		}
		HX_STACK_LINE(674)
		::flixel::FlxG_obj::swipes = Array_obj< ::Dynamic >::__new();
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC0(FlxGame_obj,update,(void))

Void FlxGame_obj::updateInput( ){
{
		HX_STACK_FRAME("flixel.FlxGame","updateInput",0x1a1f4025,"flixel.FlxGame.updateInput","flixel/FlxGame.hx",722,0x34f39fed)
		HX_STACK_THIS(this)
		HX_STACK_LINE(722)
		int _g = (int)0;		HX_STACK_VAR(_g,"_g");
		HX_STACK_LINE(722)
		Array< ::flixel::interfaces::IFlxInput > _g1 = ::flixel::FlxG_obj::inputs->list;		HX_STACK_VAR(_g1,"_g1");
		HX_STACK_LINE(722)
		while(((_g < _g1->length))){
			HX_STACK_LINE(722)
			::flixel::interfaces::IFlxInput input = _g1->__get(_g);		HX_STACK_VAR(input,"input");
			HX_STACK_LINE(722)
			++(_g);
			HX_STACK_LINE(722)
			input->update();
		}
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC0(FlxGame_obj,updateInput,(void))

Void FlxGame_obj::draw( ){
{
		HX_STACK_FRAME("flixel.FlxGame","draw",0xc8a3a4a0,"flixel.FlxGame.draw","flixel/FlxGame.hx",741,0x34f39fed)
		HX_STACK_THIS(this)
		HX_STACK_LINE(743)
		if ((::flixel::FlxG_obj::debugger->visible)){
			HX_STACK_LINE(746)
			this->ticks = ::flash::Lib_obj::getTimer();
		}
		HX_STACK_LINE(751)
		::flixel::system::layer::TileSheetExt_obj::_DRAWCALLS = (int)0;
		HX_STACK_LINE(754)
		{
			HX_STACK_LINE(754)
			int _g = (int)0;		HX_STACK_VAR(_g,"_g");
			HX_STACK_LINE(754)
			Array< ::Dynamic > _g1 = ::flixel::FlxG_obj::cameras->list;		HX_STACK_VAR(_g1,"_g1");
			HX_STACK_LINE(754)
			while(((_g < _g1->length))){
				HX_STACK_LINE(754)
				::flixel::FlxCamera camera = _g1->__get(_g).StaticCast< ::flixel::FlxCamera >();		HX_STACK_VAR(camera,"camera");
				HX_STACK_LINE(754)
				++(_g);
				HX_STACK_LINE(754)
				if (((bool((bool((camera == null())) || bool(!(camera->exists)))) || bool(!(camera->visible))))){
					HX_STACK_LINE(754)
					continue;
				}
				HX_STACK_LINE(754)
				camera->clearDrawStack();
				HX_STACK_LINE(754)
				camera->canvas->get_graphics()->clear();
				HX_STACK_LINE(754)
				camera->debugLayer->get_graphics()->clear();
				HX_STACK_LINE(754)
				camera->fill((int(camera->bgColor) & int((int)16777215)),camera->useBgAlphaBlending,(Float(((int((int(camera->bgColor) >> int((int)24))) & int((int)255)))) / Float((int)255)),null());
			}
		}
		HX_STACK_LINE(756)
		{
			HX_STACK_LINE(756)
			int _g = (int)0;		HX_STACK_VAR(_g,"_g");
			HX_STACK_LINE(756)
			Array< ::Dynamic > _g1 = ::flixel::FlxG_obj::plugins->list;		HX_STACK_VAR(_g1,"_g1");
			HX_STACK_LINE(756)
			while(((_g < _g1->length))){
				HX_STACK_LINE(756)
				::flixel::plugin::FlxPlugin plugin = _g1->__get(_g).StaticCast< ::flixel::plugin::FlxPlugin >();		HX_STACK_VAR(plugin,"plugin");
				HX_STACK_LINE(756)
				++(_g);
				HX_STACK_LINE(756)
				if (((bool(plugin->exists) && bool(plugin->visible)))){
					HX_STACK_LINE(756)
					plugin->draw();
				}
			}
		}
		HX_STACK_LINE(759)
		if ((::flixel::FlxG_obj::debugger->drawDebug)){
			HX_STACK_LINE(761)
			int _g = (int)0;		HX_STACK_VAR(_g,"_g");
			HX_STACK_LINE(761)
			Array< ::Dynamic > _g1 = ::flixel::FlxG_obj::plugins->list;		HX_STACK_VAR(_g1,"_g1");
			HX_STACK_LINE(761)
			while(((_g < _g1->length))){
				HX_STACK_LINE(761)
				::flixel::plugin::FlxPlugin plugin = _g1->__get(_g).StaticCast< ::flixel::plugin::FlxPlugin >();		HX_STACK_VAR(plugin,"plugin");
				HX_STACK_LINE(761)
				++(_g);
				HX_STACK_LINE(761)
				if (((bool((bool(plugin->exists) && bool(plugin->visible))) && bool(!(plugin->ignoreDrawDebug))))){
					HX_STACK_LINE(761)
					plugin->drawDebug();
				}
			}
		}
		HX_STACK_LINE(765)
		this->_state->draw();
		HX_STACK_LINE(768)
		if ((::flixel::FlxG_obj::debugger->drawDebug)){
			HX_STACK_LINE(770)
			this->_state->drawDebug();
		}
		HX_STACK_LINE(775)
		{
			HX_STACK_LINE(775)
			int _g = (int)0;		HX_STACK_VAR(_g,"_g");
			HX_STACK_LINE(775)
			Array< ::Dynamic > _g1 = ::flixel::FlxG_obj::cameras->list;		HX_STACK_VAR(_g1,"_g1");
			HX_STACK_LINE(775)
			while(((_g < _g1->length))){
				HX_STACK_LINE(775)
				::flixel::FlxCamera camera = _g1->__get(_g).StaticCast< ::flixel::FlxCamera >();		HX_STACK_VAR(camera,"camera");
				HX_STACK_LINE(775)
				++(_g);
				HX_STACK_LINE(775)
				if (((bool((bool((camera != null())) && bool(camera->exists))) && bool(camera->visible)))){
					HX_STACK_LINE(775)
					camera->render();
				}
			}
		}
		HX_STACK_LINE(778)
		this->debugger->stats->drawCalls(::flixel::system::layer::TileSheetExt_obj::_DRAWCALLS);
		HX_STACK_LINE(782)
		{
			HX_STACK_LINE(782)
			int _g = (int)0;		HX_STACK_VAR(_g,"_g");
			HX_STACK_LINE(782)
			Array< ::Dynamic > _g1 = ::flixel::FlxG_obj::cameras->list;		HX_STACK_VAR(_g1,"_g1");
			HX_STACK_LINE(782)
			while(((_g < _g1->length))){
				HX_STACK_LINE(782)
				::flixel::FlxCamera camera = _g1->__get(_g).StaticCast< ::flixel::FlxCamera >();		HX_STACK_VAR(camera,"camera");
				HX_STACK_LINE(782)
				++(_g);
				HX_STACK_LINE(782)
				if (((bool((bool((camera == null())) || bool(!(camera->exists)))) || bool(!(camera->visible))))){
					HX_STACK_LINE(782)
					continue;
				}
				HX_STACK_LINE(782)
				camera->drawFX();
			}
		}
		HX_STACK_LINE(785)
		this->debugger->stats->flixelDraw((::flash::Lib_obj::getTimer() - this->ticks));
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC0(FlxGame_obj,draw,(void))


FlxGame_obj::FlxGame_obj()
{
}

void FlxGame_obj::__Mark(HX_MARK_PARAMS)
{
	HX_MARK_BEGIN_CLASS(FlxGame);
	HX_MARK_MEMBER_NAME(focusLostFramerate,"focusLostFramerate");
	HX_MARK_MEMBER_NAME(soundTray,"soundTray");
	HX_MARK_MEMBER_NAME(debugger,"debugger");
	HX_MARK_MEMBER_NAME(ticks,"ticks");
	HX_MARK_MEMBER_NAME(_gameJustStarted,"_gameJustStarted");
	HX_MARK_MEMBER_NAME(_initialState,"_initialState");
	HX_MARK_MEMBER_NAME(_state,"_state");
	HX_MARK_MEMBER_NAME(_total,"_total");
	HX_MARK_MEMBER_NAME(_accumulator,"_accumulator");
	HX_MARK_MEMBER_NAME(_elapsedMS,"_elapsedMS");
	HX_MARK_MEMBER_NAME(_stepMS,"_stepMS");
	HX_MARK_MEMBER_NAME(_stepSeconds,"_stepSeconds");
	HX_MARK_MEMBER_NAME(_maxAccumulation,"_maxAccumulation");
	HX_MARK_MEMBER_NAME(_lostFocus,"_lostFocus");
	HX_MARK_MEMBER_NAME(_onFocusFiredOnce,"_onFocusFiredOnce");
	HX_MARK_MEMBER_NAME(_focusLostScreen,"_focusLostScreen");
	HX_MARK_MEMBER_NAME(_inputContainer,"_inputContainer");
	HX_MARK_MEMBER_NAME(_customSoundTray,"_customSoundTray");
	HX_MARK_MEMBER_NAME(_customFocusLostScreen,"_customFocusLostScreen");
	HX_MARK_MEMBER_NAME(_skipSplash,"_skipSplash");
	HX_MARK_MEMBER_NAME(_startFullscreen,"_startFullscreen");
	HX_MARK_MEMBER_NAME(_requestedState,"_requestedState");
	HX_MARK_MEMBER_NAME(_resetGame,"_resetGame");
	::flash::display::DisplayObjectContainer_obj::__Mark(HX_MARK_ARG);
	HX_MARK_END_CLASS();
}

void FlxGame_obj::__Visit(HX_VISIT_PARAMS)
{
	HX_VISIT_MEMBER_NAME(focusLostFramerate,"focusLostFramerate");
	HX_VISIT_MEMBER_NAME(soundTray,"soundTray");
	HX_VISIT_MEMBER_NAME(debugger,"debugger");
	HX_VISIT_MEMBER_NAME(ticks,"ticks");
	HX_VISIT_MEMBER_NAME(_gameJustStarted,"_gameJustStarted");
	HX_VISIT_MEMBER_NAME(_initialState,"_initialState");
	HX_VISIT_MEMBER_NAME(_state,"_state");
	HX_VISIT_MEMBER_NAME(_total,"_total");
	HX_VISIT_MEMBER_NAME(_accumulator,"_accumulator");
	HX_VISIT_MEMBER_NAME(_elapsedMS,"_elapsedMS");
	HX_VISIT_MEMBER_NAME(_stepMS,"_stepMS");
	HX_VISIT_MEMBER_NAME(_stepSeconds,"_stepSeconds");
	HX_VISIT_MEMBER_NAME(_maxAccumulation,"_maxAccumulation");
	HX_VISIT_MEMBER_NAME(_lostFocus,"_lostFocus");
	HX_VISIT_MEMBER_NAME(_onFocusFiredOnce,"_onFocusFiredOnce");
	HX_VISIT_MEMBER_NAME(_focusLostScreen,"_focusLostScreen");
	HX_VISIT_MEMBER_NAME(_inputContainer,"_inputContainer");
	HX_VISIT_MEMBER_NAME(_customSoundTray,"_customSoundTray");
	HX_VISIT_MEMBER_NAME(_customFocusLostScreen,"_customFocusLostScreen");
	HX_VISIT_MEMBER_NAME(_skipSplash,"_skipSplash");
	HX_VISIT_MEMBER_NAME(_startFullscreen,"_startFullscreen");
	HX_VISIT_MEMBER_NAME(_requestedState,"_requestedState");
	HX_VISIT_MEMBER_NAME(_resetGame,"_resetGame");
	::flash::display::DisplayObjectContainer_obj::__Visit(HX_VISIT_ARG);
}

Dynamic FlxGame_obj::__Field(const ::String &inName,bool inCallProp)
{
	switch(inName.length) {
	case 4:
		if (HX_FIELD_EQ(inName,"step") ) { return step_dyn(); }
		if (HX_FIELD_EQ(inName,"draw") ) { return draw_dyn(); }
		break;
	case 5:
		if (HX_FIELD_EQ(inName,"ticks") ) { return ticks; }
		break;
	case 6:
		if (HX_FIELD_EQ(inName,"_state") ) { return _state; }
		if (HX_FIELD_EQ(inName,"_total") ) { return _total; }
		if (HX_FIELD_EQ(inName,"create") ) { return create_dyn(); }
		if (HX_FIELD_EQ(inName,"update") ) { return update_dyn(); }
		break;
	case 7:
		if (HX_FIELD_EQ(inName,"_stepMS") ) { return _stepMS; }
		if (HX_FIELD_EQ(inName,"onFocus") ) { return onFocus_dyn(); }
		break;
	case 8:
		if (HX_FIELD_EQ(inName,"debugger") ) { return debugger; }
		if (HX_FIELD_EQ(inName,"onResize") ) { return onResize_dyn(); }
		break;
	case 9:
		if (HX_FIELD_EQ(inName,"soundTray") ) { return soundTray; }
		if (HX_FIELD_EQ(inName,"resetGame") ) { return resetGame_dyn(); }
		if (HX_FIELD_EQ(inName,"gameStart") ) { return gameStart_dyn(); }
		break;
	case 10:
		if (HX_FIELD_EQ(inName,"_elapsedMS") ) { return _elapsedMS; }
		if (HX_FIELD_EQ(inName,"_lostFocus") ) { return _lostFocus; }
		if (HX_FIELD_EQ(inName,"_resetGame") ) { return _resetGame; }
		break;
	case 11:
		if (HX_FIELD_EQ(inName,"_skipSplash") ) { return _skipSplash; }
		if (HX_FIELD_EQ(inName,"onFocusLost") ) { return onFocusLost_dyn(); }
		if (HX_FIELD_EQ(inName,"switchState") ) { return switchState_dyn(); }
		if (HX_FIELD_EQ(inName,"updateInput") ) { return updateInput_dyn(); }
		break;
	case 12:
		if (HX_FIELD_EQ(inName,"_accumulator") ) { return _accumulator; }
		if (HX_FIELD_EQ(inName,"_stepSeconds") ) { return _stepSeconds; }
		if (HX_FIELD_EQ(inName,"onEnterFrame") ) { return onEnterFrame_dyn(); }
		break;
	case 13:
		if (HX_FIELD_EQ(inName,"_initialState") ) { return _initialState; }
		break;
	case 15:
		if (HX_FIELD_EQ(inName,"_inputContainer") ) { return _inputContainer; }
		if (HX_FIELD_EQ(inName,"_requestedState") ) { return _requestedState; }
		break;
	case 16:
		if (HX_FIELD_EQ(inName,"_gameJustStarted") ) { return _gameJustStarted; }
		if (HX_FIELD_EQ(inName,"_maxAccumulation") ) { return _maxAccumulation; }
		if (HX_FIELD_EQ(inName,"_focusLostScreen") ) { return _focusLostScreen; }
		if (HX_FIELD_EQ(inName,"_customSoundTray") ) { return _customSoundTray; }
		if (HX_FIELD_EQ(inName,"_startFullscreen") ) { return _startFullscreen; }
		break;
	case 17:
		if (HX_FIELD_EQ(inName,"_onFocusFiredOnce") ) { return _onFocusFiredOnce; }
		break;
	case 18:
		if (HX_FIELD_EQ(inName,"focusLostFramerate") ) { return focusLostFramerate; }
		break;
	case 22:
		if (HX_FIELD_EQ(inName,"_customFocusLostScreen") ) { return _customFocusLostScreen; }
	}
	return super::__Field(inName,inCallProp);
}

Dynamic FlxGame_obj::__SetField(const ::String &inName,const Dynamic &inValue,bool inCallProp)
{
	switch(inName.length) {
	case 5:
		if (HX_FIELD_EQ(inName,"ticks") ) { ticks=inValue.Cast< int >(); return inValue; }
		break;
	case 6:
		if (HX_FIELD_EQ(inName,"_state") ) { _state=inValue.Cast< ::flixel::FlxState >(); return inValue; }
		if (HX_FIELD_EQ(inName,"_total") ) { _total=inValue.Cast< int >(); return inValue; }
		break;
	case 7:
		if (HX_FIELD_EQ(inName,"_stepMS") ) { _stepMS=inValue.Cast< int >(); return inValue; }
		break;
	case 8:
		if (HX_FIELD_EQ(inName,"debugger") ) { debugger=inValue.Cast< ::flixel::system::debug::FlxDebugger >(); return inValue; }
		break;
	case 9:
		if (HX_FIELD_EQ(inName,"soundTray") ) { soundTray=inValue.Cast< ::flixel::system::ui::FlxSoundTray >(); return inValue; }
		break;
	case 10:
		if (HX_FIELD_EQ(inName,"_elapsedMS") ) { _elapsedMS=inValue.Cast< int >(); return inValue; }
		if (HX_FIELD_EQ(inName,"_lostFocus") ) { _lostFocus=inValue.Cast< bool >(); return inValue; }
		if (HX_FIELD_EQ(inName,"_resetGame") ) { _resetGame=inValue.Cast< bool >(); return inValue; }
		break;
	case 11:
		if (HX_FIELD_EQ(inName,"_skipSplash") ) { _skipSplash=inValue.Cast< bool >(); return inValue; }
		break;
	case 12:
		if (HX_FIELD_EQ(inName,"_accumulator") ) { _accumulator=inValue.Cast< int >(); return inValue; }
		if (HX_FIELD_EQ(inName,"_stepSeconds") ) { _stepSeconds=inValue.Cast< Float >(); return inValue; }
		break;
	case 13:
		if (HX_FIELD_EQ(inName,"_initialState") ) { _initialState=inValue.Cast< ::Class >(); return inValue; }
		break;
	case 15:
		if (HX_FIELD_EQ(inName,"_inputContainer") ) { _inputContainer=inValue.Cast< ::flash::display::Sprite >(); return inValue; }
		if (HX_FIELD_EQ(inName,"_requestedState") ) { _requestedState=inValue.Cast< ::flixel::FlxState >(); return inValue; }
		break;
	case 16:
		if (HX_FIELD_EQ(inName,"_gameJustStarted") ) { _gameJustStarted=inValue.Cast< bool >(); return inValue; }
		if (HX_FIELD_EQ(inName,"_maxAccumulation") ) { _maxAccumulation=inValue.Cast< int >(); return inValue; }
		if (HX_FIELD_EQ(inName,"_focusLostScreen") ) { _focusLostScreen=inValue.Cast< ::flixel::system::ui::FlxFocusLostScreen >(); return inValue; }
		if (HX_FIELD_EQ(inName,"_customSoundTray") ) { _customSoundTray=inValue.Cast< ::Class >(); return inValue; }
		if (HX_FIELD_EQ(inName,"_startFullscreen") ) { _startFullscreen=inValue.Cast< bool >(); return inValue; }
		break;
	case 17:
		if (HX_FIELD_EQ(inName,"_onFocusFiredOnce") ) { _onFocusFiredOnce=inValue.Cast< bool >(); return inValue; }
		break;
	case 18:
		if (HX_FIELD_EQ(inName,"focusLostFramerate") ) { focusLostFramerate=inValue.Cast< int >(); return inValue; }
		break;
	case 22:
		if (HX_FIELD_EQ(inName,"_customFocusLostScreen") ) { _customFocusLostScreen=inValue.Cast< ::Class >(); return inValue; }
	}
	return super::__SetField(inName,inValue,inCallProp);
}

void FlxGame_obj::__GetFields(Array< ::String> &outFields)
{
	outFields->push(HX_CSTRING("focusLostFramerate"));
	outFields->push(HX_CSTRING("soundTray"));
	outFields->push(HX_CSTRING("debugger"));
	outFields->push(HX_CSTRING("ticks"));
	outFields->push(HX_CSTRING("_gameJustStarted"));
	outFields->push(HX_CSTRING("_initialState"));
	outFields->push(HX_CSTRING("_state"));
	outFields->push(HX_CSTRING("_total"));
	outFields->push(HX_CSTRING("_accumulator"));
	outFields->push(HX_CSTRING("_elapsedMS"));
	outFields->push(HX_CSTRING("_stepMS"));
	outFields->push(HX_CSTRING("_stepSeconds"));
	outFields->push(HX_CSTRING("_maxAccumulation"));
	outFields->push(HX_CSTRING("_lostFocus"));
	outFields->push(HX_CSTRING("_onFocusFiredOnce"));
	outFields->push(HX_CSTRING("_focusLostScreen"));
	outFields->push(HX_CSTRING("_inputContainer"));
	outFields->push(HX_CSTRING("_customSoundTray"));
	outFields->push(HX_CSTRING("_customFocusLostScreen"));
	outFields->push(HX_CSTRING("_skipSplash"));
	outFields->push(HX_CSTRING("_startFullscreen"));
	outFields->push(HX_CSTRING("_requestedState"));
	outFields->push(HX_CSTRING("_resetGame"));
	super::__GetFields(outFields);
};

static ::String sStaticFields[] = {
	String(null()) };

#if HXCPP_SCRIPTABLE
static hx::StorageInfo sMemberStorageInfo[] = {
	{hx::fsInt,(int)offsetof(FlxGame_obj,focusLostFramerate),HX_CSTRING("focusLostFramerate")},
	{hx::fsObject /*::flixel::system::ui::FlxSoundTray*/ ,(int)offsetof(FlxGame_obj,soundTray),HX_CSTRING("soundTray")},
	{hx::fsObject /*::flixel::system::debug::FlxDebugger*/ ,(int)offsetof(FlxGame_obj,debugger),HX_CSTRING("debugger")},
	{hx::fsInt,(int)offsetof(FlxGame_obj,ticks),HX_CSTRING("ticks")},
	{hx::fsBool,(int)offsetof(FlxGame_obj,_gameJustStarted),HX_CSTRING("_gameJustStarted")},
	{hx::fsObject /*::Class*/ ,(int)offsetof(FlxGame_obj,_initialState),HX_CSTRING("_initialState")},
	{hx::fsObject /*::flixel::FlxState*/ ,(int)offsetof(FlxGame_obj,_state),HX_CSTRING("_state")},
	{hx::fsInt,(int)offsetof(FlxGame_obj,_total),HX_CSTRING("_total")},
	{hx::fsInt,(int)offsetof(FlxGame_obj,_accumulator),HX_CSTRING("_accumulator")},
	{hx::fsInt,(int)offsetof(FlxGame_obj,_elapsedMS),HX_CSTRING("_elapsedMS")},
	{hx::fsInt,(int)offsetof(FlxGame_obj,_stepMS),HX_CSTRING("_stepMS")},
	{hx::fsFloat,(int)offsetof(FlxGame_obj,_stepSeconds),HX_CSTRING("_stepSeconds")},
	{hx::fsInt,(int)offsetof(FlxGame_obj,_maxAccumulation),HX_CSTRING("_maxAccumulation")},
	{hx::fsBool,(int)offsetof(FlxGame_obj,_lostFocus),HX_CSTRING("_lostFocus")},
	{hx::fsBool,(int)offsetof(FlxGame_obj,_onFocusFiredOnce),HX_CSTRING("_onFocusFiredOnce")},
	{hx::fsObject /*::flixel::system::ui::FlxFocusLostScreen*/ ,(int)offsetof(FlxGame_obj,_focusLostScreen),HX_CSTRING("_focusLostScreen")},
	{hx::fsObject /*::flash::display::Sprite*/ ,(int)offsetof(FlxGame_obj,_inputContainer),HX_CSTRING("_inputContainer")},
	{hx::fsObject /*::Class*/ ,(int)offsetof(FlxGame_obj,_customSoundTray),HX_CSTRING("_customSoundTray")},
	{hx::fsObject /*::Class*/ ,(int)offsetof(FlxGame_obj,_customFocusLostScreen),HX_CSTRING("_customFocusLostScreen")},
	{hx::fsBool,(int)offsetof(FlxGame_obj,_skipSplash),HX_CSTRING("_skipSplash")},
	{hx::fsBool,(int)offsetof(FlxGame_obj,_startFullscreen),HX_CSTRING("_startFullscreen")},
	{hx::fsObject /*::flixel::FlxState*/ ,(int)offsetof(FlxGame_obj,_requestedState),HX_CSTRING("_requestedState")},
	{hx::fsBool,(int)offsetof(FlxGame_obj,_resetGame),HX_CSTRING("_resetGame")},
	{ hx::fsUnknown, 0, null()}
};
#endif

static ::String sMemberFields[] = {
	HX_CSTRING("focusLostFramerate"),
	HX_CSTRING("soundTray"),
	HX_CSTRING("debugger"),
	HX_CSTRING("ticks"),
	HX_CSTRING("_gameJustStarted"),
	HX_CSTRING("_initialState"),
	HX_CSTRING("_state"),
	HX_CSTRING("_total"),
	HX_CSTRING("_accumulator"),
	HX_CSTRING("_elapsedMS"),
	HX_CSTRING("_stepMS"),
	HX_CSTRING("_stepSeconds"),
	HX_CSTRING("_maxAccumulation"),
	HX_CSTRING("_lostFocus"),
	HX_CSTRING("_onFocusFiredOnce"),
	HX_CSTRING("_focusLostScreen"),
	HX_CSTRING("_inputContainer"),
	HX_CSTRING("_customSoundTray"),
	HX_CSTRING("_customFocusLostScreen"),
	HX_CSTRING("_skipSplash"),
	HX_CSTRING("_startFullscreen"),
	HX_CSTRING("_requestedState"),
	HX_CSTRING("_resetGame"),
	HX_CSTRING("create"),
	HX_CSTRING("onFocus"),
	HX_CSTRING("onFocusLost"),
	HX_CSTRING("onResize"),
	HX_CSTRING("onEnterFrame"),
	HX_CSTRING("resetGame"),
	HX_CSTRING("switchState"),
	HX_CSTRING("gameStart"),
	HX_CSTRING("step"),
	HX_CSTRING("update"),
	HX_CSTRING("updateInput"),
	HX_CSTRING("draw"),
	String(null()) };

static void sMarkStatics(HX_MARK_PARAMS) {
	HX_MARK_MEMBER_NAME(FlxGame_obj::__mClass,"__mClass");
};

#ifdef HXCPP_VISIT_ALLOCS
static void sVisitStatics(HX_VISIT_PARAMS) {
	HX_VISIT_MEMBER_NAME(FlxGame_obj::__mClass,"__mClass");
};

#endif

Class FlxGame_obj::__mClass;

void FlxGame_obj::__register()
{
	hx::Static(__mClass) = hx::RegisterClass(HX_CSTRING("flixel.FlxGame"), hx::TCanCast< FlxGame_obj> ,sStaticFields,sMemberFields,
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

void FlxGame_obj::__boot()
{
}

} // end namespace flixel
