#include <hxcpp.h>

#ifndef INCLUDED_Std
#include <Std.h>
#endif
#ifndef INCLUDED_flash_Lib
#include <flash/Lib.h>
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
#ifndef INCLUDED_flash_events_Event
#include <flash/events/Event.h>
#endif
#ifndef INCLUDED_flash_events_EventDispatcher
#include <flash/events/EventDispatcher.h>
#endif
#ifndef INCLUDED_flash_events_IEventDispatcher
#include <flash/events/IEventDispatcher.h>
#endif
#ifndef INCLUDED_flash_events_MouseEvent
#include <flash/events/MouseEvent.h>
#endif
#ifndef INCLUDED_flash_geom_Point
#include <flash/geom/Point.h>
#endif
#ifndef INCLUDED_flash_geom_Rectangle
#include <flash/geom/Rectangle.h>
#endif
#ifndef INCLUDED_flash_net_URLRequest
#include <flash/net/URLRequest.h>
#endif
#ifndef INCLUDED_flash_text_TextField
#include <flash/text/TextField.h>
#endif
#ifndef INCLUDED_flash_text_TextFieldAutoSize
#include <flash/text/TextFieldAutoSize.h>
#endif
#ifndef INCLUDED_flash_text_TextFormat
#include <flash/text/TextFormat.h>
#endif
#ifndef INCLUDED_flixel_FlxG
#include <flixel/FlxG.h>
#endif
#ifndef INCLUDED_flixel_FlxGame
#include <flixel/FlxGame.h>
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
#ifndef INCLUDED_flixel_system_FlxAssets
#include <flixel/system/FlxAssets.h>
#endif
#ifndef INCLUDED_flixel_system_FlxVersion
#include <flixel/system/FlxVersion.h>
#endif
#ifndef INCLUDED_flixel_system_debug_ButtonAlignment
#include <flixel/system/debug/ButtonAlignment.h>
#endif
#ifndef INCLUDED_flixel_system_debug_Console
#include <flixel/system/debug/Console.h>
#endif
#ifndef INCLUDED_flixel_system_debug_DebuggerLayout
#include <flixel/system/debug/DebuggerLayout.h>
#endif
#ifndef INCLUDED_flixel_system_debug_FlxDebugger
#include <flixel/system/debug/FlxDebugger.h>
#endif
#ifndef INCLUDED_flixel_system_debug_GraphicConsole
#include <flixel/system/debug/GraphicConsole.h>
#endif
#ifndef INCLUDED_flixel_system_debug_GraphicLog
#include <flixel/system/debug/GraphicLog.h>
#endif
#ifndef INCLUDED_flixel_system_debug_GraphicStats
#include <flixel/system/debug/GraphicStats.h>
#endif
#ifndef INCLUDED_flixel_system_debug_GraphicWatch
#include <flixel/system/debug/GraphicWatch.h>
#endif
#ifndef INCLUDED_flixel_system_debug_Log
#include <flixel/system/debug/Log.h>
#endif
#ifndef INCLUDED_flixel_system_debug_Stats
#include <flixel/system/debug/Stats.h>
#endif
#ifndef INCLUDED_flixel_system_debug_VCR
#include <flixel/system/debug/VCR.h>
#endif
#ifndef INCLUDED_flixel_system_debug_Watch
#include <flixel/system/debug/Watch.h>
#endif
#ifndef INCLUDED_flixel_system_debug_Window
#include <flixel/system/debug/Window.h>
#endif
#ifndef INCLUDED_flixel_system_debug__FlxDebugger_GraphicDrawDebug
#include <flixel/system/debug/_FlxDebugger/GraphicDrawDebug.h>
#endif
#ifndef INCLUDED_flixel_system_debug__FlxDebugger_GraphicFlixel
#include <flixel/system/debug/_FlxDebugger/GraphicFlixel.h>
#endif
#ifndef INCLUDED_flixel_system_frontEnds_DebuggerFrontEnd
#include <flixel/system/frontEnds/DebuggerFrontEnd.h>
#endif
#ifndef INCLUDED_flixel_system_frontEnds_VCRFrontEnd
#include <flixel/system/frontEnds/VCRFrontEnd.h>
#endif
#ifndef INCLUDED_flixel_system_ui_FlxSystemButton
#include <flixel/system/ui/FlxSystemButton.h>
#endif
#ifndef INCLUDED_flixel_util_FlxArrayUtil
#include <flixel/util/FlxArrayUtil.h>
#endif
#ifndef INCLUDED_flixel_util_FlxPoint
#include <flixel/util/FlxPoint.h>
#endif
namespace flixel{
namespace system{
namespace debug{

Void FlxDebugger_obj::__construct(Float Width,Float Height)
{
HX_STACK_FRAME("flixel.system.debug.FlxDebugger","new",0x06ebd57d,"flixel.system.debug.FlxDebugger.new","flixel/system/debug/FlxDebugger.hx",36,0xd9fc0a74)

HX_STACK_ARG(Width,"Width")

HX_STACK_ARG(Height,"Height")
{
	HX_STACK_LINE(70)
	this->hasMouse = false;
	HX_STACK_LINE(347)
	super::__construct();
	HX_STACK_LINE(348)
	this->set_visible(false);
	HX_STACK_LINE(349)
	this->_layout = ::flixel::system::debug::DebuggerLayout_obj::STANDARD;
	HX_STACK_LINE(350)
	this->_screen = ::flash::geom::Point_obj::__new(null(),null());
	HX_STACK_LINE(352)
	this->_topBar = ::flash::display::Sprite_obj::__new();
	HX_STACK_LINE(353)
	this->_topBar->get_graphics()->beginFill((int)0,0.66666666666666663);
	HX_STACK_LINE(354)
	this->_topBar->get_graphics()->drawRect((int)0,(int)0,::flash::Lib_obj::get_current()->get_stage()->get_stageWidth(),(int)20);
	HX_STACK_LINE(355)
	this->_topBar->get_graphics()->endFill();
	HX_STACK_LINE(356)
	this->addChild(this->_topBar);
	HX_STACK_LINE(358)
	::flash::text::TextField txt = ::flash::text::TextField_obj::__new();		HX_STACK_VAR(txt,"txt");
	HX_STACK_LINE(359)
	txt->set_height((int)20);
	HX_STACK_LINE(360)
	txt->set_selectable(false);
	HX_STACK_LINE(361)
	txt->set_y((int)-9);
	HX_STACK_LINE(362)
	txt->set_multiline(false);
	HX_STACK_LINE(363)
	txt->set_embedFonts(true);
	HX_STACK_LINE(364)
	::flash::text::TextFormat format = ::flash::text::TextFormat_obj::__new(::flixel::system::FlxAssets_obj::FONT_DEBUGGER,(int)12,(int)-1,null(),null(),null(),null(),null(),null(),null(),null(),null(),null());		HX_STACK_VAR(format,"format");
	HX_STACK_LINE(365)
	txt->set_defaultTextFormat(format);
	HX_STACK_LINE(366)
	txt->set_autoSize(::flash::text::TextFieldAutoSize_obj::LEFT);
	HX_STACK_LINE(367)
	txt->set_text(::Std_obj::string(::flixel::FlxG_obj::VERSION));
	HX_STACK_LINE(369)
	this->_leftButtons = Array_obj< ::Dynamic >::__new();
	HX_STACK_LINE(370)
	this->_rightButtons = Array_obj< ::Dynamic >::__new();
	HX_STACK_LINE(371)
	this->_middleButtons = Array_obj< ::Dynamic >::__new();
	HX_STACK_LINE(373)
	this->addChild(this->log = ::flixel::system::debug::Log_obj::__new());
	HX_STACK_LINE(374)
	this->addChild(this->watch = ::flixel::system::debug::Watch_obj::__new());
	HX_STACK_LINE(375)
	this->addChild(this->console = ::flixel::system::debug::Console_obj::__new());
	HX_STACK_LINE(376)
	this->addChild(this->stats = ::flixel::system::debug::Stats_obj::__new());
	HX_STACK_LINE(378)
	this->stats->set_visible(true);
	HX_STACK_LINE(380)
	this->vcr = ::flixel::system::debug::VCR_obj::__new(hx::ObjectPtr<OBJ_>(this));
	HX_STACK_LINE(382)
	this->addButton(::flixel::system::debug::ButtonAlignment_obj::LEFT,::flixel::system::debug::_FlxDebugger::GraphicFlixel_obj::__new((int)0,(int)0,null(),null()),this->openHomepage_dyn(),null(),null());
	HX_STACK_LINE(383)
	this->addButton(::flixel::system::debug::ButtonAlignment_obj::LEFT,null(),this->openHomepage_dyn(),null(),null())->addChild(txt);
	HX_STACK_LINE(385)
	this->addButton(::flixel::system::debug::ButtonAlignment_obj::RIGHT,::flixel::system::debug::GraphicLog_obj::__new((int)0,(int)0,null(),null()),this->log->toggleVisibility_dyn(),true,null())->set_toggled(!(this->log->get_visible()));
	HX_STACK_LINE(386)
	this->addButton(::flixel::system::debug::ButtonAlignment_obj::RIGHT,::flixel::system::debug::GraphicWatch_obj::__new((int)0,(int)0,null(),null()),this->watch->toggleVisibility_dyn(),true,null())->set_toggled(!(this->watch->get_visible()));
	HX_STACK_LINE(387)
	this->addButton(::flixel::system::debug::ButtonAlignment_obj::RIGHT,::flixel::system::debug::GraphicConsole_obj::__new((int)0,(int)0,null(),null()),this->console->toggleVisibility_dyn(),true,null())->set_toggled(!(this->console->get_visible()));
	HX_STACK_LINE(388)
	this->addButton(::flixel::system::debug::ButtonAlignment_obj::RIGHT,::flixel::system::debug::GraphicStats_obj::__new((int)0,(int)0,null(),null()),this->stats->toggleVisibility_dyn(),true,null())->set_toggled(!(this->stats->get_visible()));
	HX_STACK_LINE(389)
	this->addButton(::flixel::system::debug::ButtonAlignment_obj::RIGHT,::flixel::system::debug::_FlxDebugger::GraphicDrawDebug_obj::__new((int)0,(int)0,null(),null()),this->toggleVisualDebug_dyn(),true,null())->set_toggled(!(::flixel::FlxG_obj::debugger->drawDebug));
	HX_STACK_LINE(395)
	{
		HX_STACK_LINE(395)
		this->_screen->x = Width;
		HX_STACK_LINE(395)
		this->_screen->y = Height;
		HX_STACK_LINE(395)
		this->_screenBounds = ::flash::geom::Rectangle_obj::__new((int)2,21.,(this->_screen->x - (int)4),((this->_screen->y - (int)4) - (int)20));
		HX_STACK_LINE(395)
		this->stats->updateBounds(this->_screenBounds);
		HX_STACK_LINE(395)
		this->log->updateBounds(this->_screenBounds);
		HX_STACK_LINE(395)
		this->watch->updateBounds(this->_screenBounds);
		HX_STACK_LINE(395)
		this->console->updateBounds(this->_screenBounds);
		HX_STACK_LINE(395)
		this->_topBar->set_width(::flash::Lib_obj::get_current()->get_stage()->get_stageWidth());
		HX_STACK_LINE(395)
		this->resetButtonLayout();
		HX_STACK_LINE(395)
		this->resetLayout();
		HX_STACK_LINE(395)
		this->set_scaleX((Float((int)1) / Float(::flixel::FlxG_obj::game->get_scaleX())));
		HX_STACK_LINE(395)
		this->set_scaleY((Float((int)1) / Float(::flixel::FlxG_obj::game->get_scaleY())));
		HX_STACK_LINE(395)
		Float _g = ::flixel::FlxG_obj::game->get_x();		HX_STACK_VAR(_g,"_g");
		HX_STACK_LINE(395)
		this->set_x((-(_g) * this->get_scaleX()));
		HX_STACK_LINE(395)
		Float _g1 = ::flixel::FlxG_obj::game->get_y();		HX_STACK_VAR(_g1,"_g1");
		HX_STACK_LINE(395)
		this->set_y((-(_g1) * this->get_scaleY()));
	}
	HX_STACK_LINE(397)
	this->addEventListener(::flash::events::MouseEvent_obj::MOUSE_OVER,this->onMouseOver_dyn(),null(),null(),null());
	HX_STACK_LINE(398)
	this->addEventListener(::flash::events::MouseEvent_obj::MOUSE_OUT,this->onMouseOut_dyn(),null(),null(),null());
}
;
	return null();
}

//FlxDebugger_obj::~FlxDebugger_obj() { }

Dynamic FlxDebugger_obj::__CreateEmpty() { return  new FlxDebugger_obj; }
hx::ObjectPtr< FlxDebugger_obj > FlxDebugger_obj::__new(Float Width,Float Height)
{  hx::ObjectPtr< FlxDebugger_obj > result = new FlxDebugger_obj();
	result->__construct(Width,Height);
	return result;}

Dynamic FlxDebugger_obj::__Create(hx::DynamicArray inArgs)
{  hx::ObjectPtr< FlxDebugger_obj > result = new FlxDebugger_obj();
	result->__construct(inArgs[0],inArgs[1]);
	return result;}

Void FlxDebugger_obj::destroy( ){
{
		HX_STACK_FRAME("flixel.system.debug.FlxDebugger","destroy",0x0aa38497,"flixel.system.debug.FlxDebugger.destroy","flixel/system/debug/FlxDebugger.hx",105,0xd9fc0a74)
		HX_STACK_THIS(this)
		HX_STACK_LINE(106)
		this->_screen = null();
		HX_STACK_LINE(108)
		{
			HX_STACK_LINE(108)
			int _g = (int)0;		HX_STACK_VAR(_g,"_g");
			HX_STACK_LINE(108)
			Array< ::Dynamic > _g1 = this->_rightButtons;		HX_STACK_VAR(_g1,"_g1");
			HX_STACK_LINE(108)
			while(((_g < _g1->length))){
				HX_STACK_LINE(108)
				::flixel::system::ui::FlxSystemButton o = _g1->__get(_g).StaticCast< ::flixel::system::ui::FlxSystemButton >();		HX_STACK_VAR(o,"o");
				HX_STACK_LINE(108)
				++(_g);
				HX_STACK_LINE(110)
				o->destroy();
			}
		}
		HX_STACK_LINE(112)
		this->_rightButtons = null();
		HX_STACK_LINE(114)
		{
			HX_STACK_LINE(114)
			int _g = (int)0;		HX_STACK_VAR(_g,"_g");
			HX_STACK_LINE(114)
			Array< ::Dynamic > _g1 = this->_leftButtons;		HX_STACK_VAR(_g1,"_g1");
			HX_STACK_LINE(114)
			while(((_g < _g1->length))){
				HX_STACK_LINE(114)
				::flixel::system::ui::FlxSystemButton o = _g1->__get(_g).StaticCast< ::flixel::system::ui::FlxSystemButton >();		HX_STACK_VAR(o,"o");
				HX_STACK_LINE(114)
				++(_g);
				HX_STACK_LINE(116)
				o->destroy();
			}
		}
		HX_STACK_LINE(118)
		this->_leftButtons = null();
		HX_STACK_LINE(120)
		{
			HX_STACK_LINE(120)
			int _g = (int)0;		HX_STACK_VAR(_g,"_g");
			HX_STACK_LINE(120)
			Array< ::Dynamic > _g1 = this->_middleButtons;		HX_STACK_VAR(_g1,"_g1");
			HX_STACK_LINE(120)
			while(((_g < _g1->length))){
				HX_STACK_LINE(120)
				::flixel::system::ui::FlxSystemButton o = _g1->__get(_g).StaticCast< ::flixel::system::ui::FlxSystemButton >();		HX_STACK_VAR(o,"o");
				HX_STACK_LINE(120)
				++(_g);
				HX_STACK_LINE(122)
				o->destroy();
			}
		}
		HX_STACK_LINE(124)
		this->_middleButtons = null();
		HX_STACK_LINE(126)
		this->removeChild(this->_topBar);
		HX_STACK_LINE(127)
		this->_topBar = null();
		HX_STACK_LINE(129)
		if (((this->log != null()))){
			HX_STACK_LINE(131)
			this->removeChild(this->log);
			HX_STACK_LINE(132)
			this->log->destroy();
			HX_STACK_LINE(133)
			this->log = null();
		}
		HX_STACK_LINE(135)
		if (((this->watch != null()))){
			HX_STACK_LINE(137)
			this->removeChild(this->watch);
			HX_STACK_LINE(138)
			this->watch->destroy();
			HX_STACK_LINE(139)
			this->watch = null();
		}
		HX_STACK_LINE(141)
		if (((this->stats != null()))){
			HX_STACK_LINE(143)
			this->removeChild(this->stats);
			HX_STACK_LINE(144)
			this->stats->destroy();
			HX_STACK_LINE(145)
			this->stats = null();
		}
		HX_STACK_LINE(147)
		if (((this->console != null()))){
			HX_STACK_LINE(149)
			this->removeChild(this->console);
			HX_STACK_LINE(150)
			this->console->destroy();
			HX_STACK_LINE(151)
			this->console = null();
		}
		HX_STACK_LINE(154)
		this->removeEventListener(::flash::events::MouseEvent_obj::MOUSE_OVER,this->onMouseOver_dyn(),null());
		HX_STACK_LINE(155)
		this->removeEventListener(::flash::events::MouseEvent_obj::MOUSE_OUT,this->onMouseOut_dyn(),null());
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC0(FlxDebugger_obj,destroy,(void))

Void FlxDebugger_obj::setLayout( ::flixel::system::debug::DebuggerLayout Layout){
{
		HX_STACK_FRAME("flixel.system.debug.FlxDebugger","setLayout",0x62385cc9,"flixel.system.debug.FlxDebugger.setLayout","flixel/system/debug/FlxDebugger.hx",164,0xd9fc0a74)
		HX_STACK_THIS(this)
		HX_STACK_ARG(Layout,"Layout")
		HX_STACK_LINE(165)
		this->_layout = Layout;
		HX_STACK_LINE(166)
		this->resetLayout();
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC1(FlxDebugger_obj,setLayout,(void))

Void FlxDebugger_obj::resetLayout( ){
{
		HX_STACK_FRAME("flixel.system.debug.FlxDebugger","resetLayout",0xf3cb1bf6,"flixel.system.debug.FlxDebugger.resetLayout","flixel/system/debug/FlxDebugger.hx",175,0xd9fc0a74)
		HX_STACK_THIS(this)
		HX_STACK_LINE(175)
		::flixel::system::debug::DebuggerLayout _g = this->_layout;		HX_STACK_VAR(_g,"_g");
		HX_STACK_LINE(175)
		switch( (int)(_g->__Index())){
			case (int)1: {
				HX_STACK_LINE(178)
				this->log->resize((Float(this->_screen->x) / Float((int)4)),(int)68);
				HX_STACK_LINE(179)
				this->log->reposition((int)0,this->_screen->y);
				HX_STACK_LINE(180)
				this->console->resize(((Float(this->_screen->x) / Float((int)2)) - (int)8),(int)35);
				HX_STACK_LINE(181)
				Float _g1 = this->log->get_x();		HX_STACK_VAR(_g1,"_g1");
				HX_STACK_LINE(181)
				this->console->reposition(((_g1 + this->log->get_width()) + (int)2),this->_screen->y);
				HX_STACK_LINE(182)
				this->watch->resize((Float(this->_screen->x) / Float((int)4)),(int)68);
				HX_STACK_LINE(183)
				this->watch->reposition(this->_screen->x,this->_screen->y);
				HX_STACK_LINE(184)
				this->stats->reposition(this->_screen->x,(int)0);
			}
			;break;
			case (int)2: {
				HX_STACK_LINE(186)
				this->console->resize((this->_screen->x - (int)4),(int)35);
				HX_STACK_LINE(187)
				this->console->reposition((int)2,this->_screen->y);
				HX_STACK_LINE(188)
				this->log->resize((Float(((this->_screen->x - (int)6))) / Float((int)2)),(Float(this->_screen->y) / Float((int)2)));
				HX_STACK_LINE(189)
				Float _g1 = (this->_screen->y - this->log->get_height());		HX_STACK_VAR(_g1,"_g1");
				HX_STACK_LINE(189)
				this->log->reposition((int)0,((_g1 - this->console->get_height()) - 3.));
				HX_STACK_LINE(190)
				this->watch->resize((Float(((this->_screen->x - (int)6))) / Float((int)2)),(Float(this->_screen->y) / Float((int)2)));
				HX_STACK_LINE(191)
				Float _g2 = (this->_screen->y - this->watch->get_height());		HX_STACK_VAR(_g2,"_g2");
				HX_STACK_LINE(191)
				this->watch->reposition(this->_screen->x,((_g2 - this->console->get_height()) - 3.));
				HX_STACK_LINE(192)
				this->stats->reposition(this->_screen->x,(int)0);
			}
			;break;
			case (int)3: {
				HX_STACK_LINE(194)
				this->console->resize((this->_screen->x - (int)4),(int)35);
				HX_STACK_LINE(195)
				this->console->reposition((int)0,(int)0);
				HX_STACK_LINE(196)
				this->log->resize((Float(((this->_screen->x - (int)6))) / Float((int)2)),(Float(this->_screen->y) / Float((int)4)));
				HX_STACK_LINE(197)
				this->log->reposition((int)0,((this->console->get_height() + (int)2) + (int)15));
				HX_STACK_LINE(198)
				this->watch->resize((Float(((this->_screen->x - (int)6))) / Float((int)2)),(Float(this->_screen->y) / Float((int)4)));
				HX_STACK_LINE(199)
				this->watch->reposition(this->_screen->x,((this->console->get_height() + (int)2) + (int)15));
				HX_STACK_LINE(200)
				this->stats->reposition(this->_screen->x,this->_screen->y);
			}
			;break;
			case (int)4: {
				HX_STACK_LINE(202)
				this->console->resize((this->_screen->x - (int)4),(int)35);
				HX_STACK_LINE(203)
				this->console->reposition((int)2,this->_screen->y);
				HX_STACK_LINE(204)
				this->log->resize((Float(this->_screen->x) / Float((int)3)),(((Float((((this->_screen->y - (int)15) - 5.))) / Float((int)2)) - (Float(this->console->get_height()) / Float((int)2))) - (int)2));
				HX_STACK_LINE(205)
				this->log->reposition((int)0,(int)0);
				HX_STACK_LINE(206)
				this->watch->resize((Float(this->_screen->x) / Float((int)3)),((Float((((this->_screen->y - (int)15) - 5.))) / Float((int)2)) - (Float(this->console->get_height()) / Float((int)2))));
				HX_STACK_LINE(207)
				Float _g3 = this->log->get_y();		HX_STACK_VAR(_g3,"_g3");
				HX_STACK_LINE(207)
				this->watch->reposition((int)0,((_g3 + this->log->get_height()) + (int)2));
				HX_STACK_LINE(208)
				this->stats->reposition(this->_screen->x,(int)0);
			}
			;break;
			case (int)5: {
				HX_STACK_LINE(210)
				this->console->resize((this->_screen->x - (int)4),(int)35);
				HX_STACK_LINE(211)
				this->console->reposition((int)2,this->_screen->y);
				HX_STACK_LINE(212)
				this->log->resize((Float(this->_screen->x) / Float((int)3)),(((Float((((this->_screen->y - (int)15) - 5.))) / Float((int)2)) - (Float(this->console->get_height()) / Float((int)2))) - (int)2));
				HX_STACK_LINE(213)
				this->log->reposition(this->_screen->x,(int)0);
				HX_STACK_LINE(214)
				this->watch->resize((Float(this->_screen->x) / Float((int)3)),((Float((((this->_screen->y - (int)15) - 5.))) / Float((int)2)) - (Float(this->console->get_height()) / Float((int)2))));
				HX_STACK_LINE(215)
				Float _g4 = this->log->get_y();		HX_STACK_VAR(_g4,"_g4");
				HX_STACK_LINE(215)
				this->watch->reposition(this->_screen->x,((_g4 + this->log->get_height()) + (int)2));
				HX_STACK_LINE(216)
				this->stats->reposition((int)0,(int)0);
			}
			;break;
			case (int)0: {
				HX_STACK_LINE(218)
				this->console->resize((this->_screen->x - (int)4),(int)35);
				HX_STACK_LINE(219)
				this->console->reposition((int)2,this->_screen->y);
				HX_STACK_LINE(220)
				this->log->resize((Float(((this->_screen->x - (int)6))) / Float((int)2)),(Float(this->_screen->y) / Float((int)4)));
				HX_STACK_LINE(221)
				Float _g5 = (this->_screen->y - this->log->get_height());		HX_STACK_VAR(_g5,"_g5");
				HX_STACK_LINE(221)
				this->log->reposition((int)0,((_g5 - this->console->get_height()) - 3.));
				HX_STACK_LINE(222)
				this->watch->resize((Float(((this->_screen->x - (int)6))) / Float((int)2)),(Float(this->_screen->y) / Float((int)4)));
				HX_STACK_LINE(223)
				Float _g6 = (this->_screen->y - this->watch->get_height());		HX_STACK_VAR(_g6,"_g6");
				HX_STACK_LINE(223)
				this->watch->reposition(this->_screen->x,((_g6 - this->console->get_height()) - 3.));
				HX_STACK_LINE(224)
				this->stats->reposition(this->_screen->x,(int)0);
			}
			;break;
		}
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC0(FlxDebugger_obj,resetLayout,(void))

Void FlxDebugger_obj::onResize( Float Width,Float Height){
{
		HX_STACK_FRAME("flixel.system.debug.FlxDebugger","onResize",0x5bb7a236,"flixel.system.debug.FlxDebugger.onResize","flixel/system/debug/FlxDebugger.hx",229,0xd9fc0a74)
		HX_STACK_THIS(this)
		HX_STACK_ARG(Width,"Width")
		HX_STACK_ARG(Height,"Height")
		HX_STACK_LINE(230)
		this->_screen->x = Width;
		HX_STACK_LINE(231)
		this->_screen->y = Height;
		HX_STACK_LINE(232)
		this->_screenBounds = ::flash::geom::Rectangle_obj::__new((int)2,21.,(this->_screen->x - (int)4),((this->_screen->y - (int)4) - (int)20));
		HX_STACK_LINE(233)
		this->stats->updateBounds(this->_screenBounds);
		HX_STACK_LINE(234)
		this->log->updateBounds(this->_screenBounds);
		HX_STACK_LINE(235)
		this->watch->updateBounds(this->_screenBounds);
		HX_STACK_LINE(236)
		this->console->updateBounds(this->_screenBounds);
		HX_STACK_LINE(237)
		this->_topBar->set_width(::flash::Lib_obj::get_current()->get_stage()->get_stageWidth());
		HX_STACK_LINE(238)
		this->resetButtonLayout();
		HX_STACK_LINE(239)
		this->resetLayout();
		HX_STACK_LINE(240)
		this->set_scaleX((Float((int)1) / Float(::flixel::FlxG_obj::game->get_scaleX())));
		HX_STACK_LINE(241)
		this->set_scaleY((Float((int)1) / Float(::flixel::FlxG_obj::game->get_scaleY())));
		HX_STACK_LINE(242)
		Float _g = ::flixel::FlxG_obj::game->get_x();		HX_STACK_VAR(_g,"_g");
		HX_STACK_LINE(242)
		this->set_x((-(_g) * this->get_scaleX()));
		HX_STACK_LINE(243)
		Float _g1 = ::flixel::FlxG_obj::game->get_y();		HX_STACK_VAR(_g1,"_g1");
		HX_STACK_LINE(243)
		this->set_y((-(_g1) * this->get_scaleY()));
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC2(FlxDebugger_obj,onResize,(void))

Float FlxDebugger_obj::hAlignButtons( Array< ::Dynamic > Sprites,hx::Null< Float >  __o_Padding,hx::Null< bool >  __o_Set,hx::Null< Float >  __o_LeftOffset){
Float Padding = __o_Padding.Default(0);
bool Set = __o_Set.Default(true);
Float LeftOffset = __o_LeftOffset.Default(0);
	HX_STACK_FRAME("flixel.system.debug.FlxDebugger","hAlignButtons",0x74a569e1,"flixel.system.debug.FlxDebugger.hAlignButtons","flixel/system/debug/FlxDebugger.hx",250,0xd9fc0a74)
	HX_STACK_THIS(this)
	HX_STACK_ARG(Sprites,"Sprites")
	HX_STACK_ARG(Padding,"Padding")
	HX_STACK_ARG(Set,"Set")
	HX_STACK_ARG(LeftOffset,"LeftOffset")
{
		HX_STACK_LINE(251)
		Float width = (int)0;		HX_STACK_VAR(width,"width");
		HX_STACK_LINE(252)
		Float last = LeftOffset;		HX_STACK_VAR(last,"last");
		HX_STACK_LINE(254)
		{
			HX_STACK_LINE(254)
			int _g1 = (int)0;		HX_STACK_VAR(_g1,"_g1");
			HX_STACK_LINE(254)
			int _g = Sprites->length;		HX_STACK_VAR(_g,"_g");
			HX_STACK_LINE(254)
			while(((_g1 < _g))){
				HX_STACK_LINE(254)
				int i = (_g1)++;		HX_STACK_VAR(i,"i");
				HX_STACK_LINE(256)
				::flash::display::Sprite o = Sprites->__get(i).StaticCast< ::flixel::system::ui::FlxSystemButton >();		HX_STACK_VAR(o,"o");
				HX_STACK_LINE(257)
				hx::AddEq(width,(o->get_width() + Padding));
				HX_STACK_LINE(258)
				if ((Set)){
					HX_STACK_LINE(259)
					o->set_x(last);
				}
				HX_STACK_LINE(261)
				Float _g2 = o->get_x();		HX_STACK_VAR(_g2,"_g2");
				HX_STACK_LINE(261)
				last = ((_g2 + o->get_width()) + Padding);
			}
		}
		HX_STACK_LINE(264)
		return width;
	}
}


HX_DEFINE_DYNAMIC_FUNC4(FlxDebugger_obj,hAlignButtons,return )

Void FlxDebugger_obj::resetButtonLayout( ){
{
		HX_STACK_FRAME("flixel.system.debug.FlxDebugger","resetButtonLayout",0x30f7f488,"flixel.system.debug.FlxDebugger.resetButtonLayout","flixel/system/debug/FlxDebugger.hx",271,0xd9fc0a74)
		HX_STACK_THIS(this)
		HX_STACK_LINE(272)
		this->hAlignButtons(this->_leftButtons,(int)10,true,(int)10);
		HX_STACK_LINE(274)
		Float _g = (::flash::Lib_obj::get_current()->get_stage()->get_stageWidth() * 0.5);		HX_STACK_VAR(_g,"_g");
		HX_STACK_LINE(274)
		Float offset = (_g - (this->hAlignButtons(this->_middleButtons,(int)10,false,null()) * 0.5));		HX_STACK_VAR(offset,"offset");
		HX_STACK_LINE(275)
		this->hAlignButtons(this->_middleButtons,(int)10,true,offset);
		HX_STACK_LINE(277)
		int _g1 = ::flash::Lib_obj::get_current()->get_stage()->get_stageWidth();		HX_STACK_VAR(_g1,"_g1");
		HX_STACK_LINE(277)
		Float offset1 = (_g1 - this->hAlignButtons(this->_rightButtons,(int)10,false,null()));		HX_STACK_VAR(offset1,"offset1");
		HX_STACK_LINE(278)
		this->hAlignButtons(this->_rightButtons,(int)10,true,offset1);
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC0(FlxDebugger_obj,resetButtonLayout,(void))

::flixel::system::ui::FlxSystemButton FlxDebugger_obj::addButton( ::flixel::system::debug::ButtonAlignment Position,::flash::display::BitmapData Icon,Dynamic UpHandler,hx::Null< bool >  __o_ToggleMode,hx::Null< bool >  __o_UpdateLayout){
bool ToggleMode = __o_ToggleMode.Default(false);
bool UpdateLayout = __o_UpdateLayout.Default(false);
	HX_STACK_FRAME("flixel.system.debug.FlxDebugger","addButton",0x3bdccfd0,"flixel.system.debug.FlxDebugger.addButton","flixel/system/debug/FlxDebugger.hx",292,0xd9fc0a74)
	HX_STACK_THIS(this)
	HX_STACK_ARG(Position,"Position")
	HX_STACK_ARG(Icon,"Icon")
	HX_STACK_ARG(UpHandler,"UpHandler")
	HX_STACK_ARG(ToggleMode,"ToggleMode")
	HX_STACK_ARG(UpdateLayout,"UpdateLayout")
{
		HX_STACK_LINE(293)
		::flixel::system::ui::FlxSystemButton button = ::flixel::system::ui::FlxSystemButton_obj::__new(Icon,UpHandler,ToggleMode);		HX_STACK_VAR(button,"button");
		HX_STACK_LINE(295)
		Array< ::Dynamic > array;		HX_STACK_VAR(array,"array");
		HX_STACK_LINE(296)
		switch( (int)(Position->__Index())){
			case (int)0: {
				HX_STACK_LINE(299)
				array = this->_leftButtons;
			}
			;break;
			case (int)1: {
				HX_STACK_LINE(301)
				array = this->_middleButtons;
			}
			;break;
			case (int)2: {
				HX_STACK_LINE(303)
				array = this->_rightButtons;
			}
			;break;
		}
		HX_STACK_LINE(306)
		button->set_y((10. - (Float(button->get_height()) / Float((int)2))));
		HX_STACK_LINE(307)
		array->push(button);
		HX_STACK_LINE(308)
		this->addChild(button);
		HX_STACK_LINE(310)
		if ((UpdateLayout)){
			HX_STACK_LINE(312)
			this->resetButtonLayout();
		}
		HX_STACK_LINE(315)
		return button;
	}
}


HX_DEFINE_DYNAMIC_FUNC5(FlxDebugger_obj,addButton,return )

Void FlxDebugger_obj::removeButton( ::flixel::system::ui::FlxSystemButton Button,hx::Null< bool >  __o_UpdateLayout){
bool UpdateLayout = __o_UpdateLayout.Default(true);
	HX_STACK_FRAME("flixel.system.debug.FlxDebugger","removeButton",0xec3cec99,"flixel.system.debug.FlxDebugger.removeButton","flixel/system/debug/FlxDebugger.hx",325,0xd9fc0a74)
	HX_STACK_THIS(this)
	HX_STACK_ARG(Button,"Button")
	HX_STACK_ARG(UpdateLayout,"UpdateLayout")
{
		HX_STACK_LINE(326)
		this->removeChild(Button);
		HX_STACK_LINE(327)
		Button->destroy();
		HX_STACK_LINE(328)
		this->removeButtonFromArray(this->_leftButtons,Button);
		HX_STACK_LINE(329)
		this->removeButtonFromArray(this->_middleButtons,Button);
		HX_STACK_LINE(330)
		this->removeButtonFromArray(this->_rightButtons,Button);
		HX_STACK_LINE(332)
		if ((UpdateLayout)){
			HX_STACK_LINE(334)
			this->resetButtonLayout();
		}
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC2(FlxDebugger_obj,removeButton,(void))

Void FlxDebugger_obj::onMouseOver( ::flash::events::MouseEvent E){
{
		HX_STACK_FRAME("flixel.system.debug.FlxDebugger","onMouseOver",0x134e1717,"flixel.system.debug.FlxDebugger.onMouseOver","flixel/system/debug/FlxDebugger.hx",407,0xd9fc0a74)
		HX_STACK_THIS(this)
		HX_STACK_ARG(E,"E")
		HX_STACK_LINE(408)
		this->hasMouse = true;
		HX_STACK_LINE(410)
		::flixel::FlxG_obj::mouse->set_useSystemCursor(true);
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC1(FlxDebugger_obj,onMouseOver,(void))

Void FlxDebugger_obj::onMouseOut( ::flash::events::MouseEvent E){
{
		HX_STACK_FRAME("flixel.system.debug.FlxDebugger","onMouseOut",0x752e442b,"flixel.system.debug.FlxDebugger.onMouseOut","flixel/system/debug/FlxDebugger.hx",420,0xd9fc0a74)
		HX_STACK_THIS(this)
		HX_STACK_ARG(E,"E")
		HX_STACK_LINE(421)
		this->hasMouse = false;
		HX_STACK_LINE(424)
		if ((!(::flixel::FlxG_obj::vcr->paused))){
			HX_STACK_LINE(426)
			::flixel::FlxG_obj::mouse->set_useSystemCursor(false);
		}
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC1(FlxDebugger_obj,onMouseOut,(void))

Void FlxDebugger_obj::removeButtonFromArray( Array< ::Dynamic > Arr,::flixel::system::ui::FlxSystemButton Button){
{
		HX_STACK_FRAME("flixel.system.debug.FlxDebugger","removeButtonFromArray",0xbb326ff6,"flixel.system.debug.FlxDebugger.removeButtonFromArray","flixel/system/debug/FlxDebugger.hx",432,0xd9fc0a74)
		HX_STACK_THIS(this)
		HX_STACK_ARG(Arr,"Arr")
		HX_STACK_ARG(Button,"Button")
		HX_STACK_LINE(433)
		int index = ::flixel::util::FlxArrayUtil_obj::indexOf_flixel_system_ui_FlxSystemButton(Arr,Button,null());		HX_STACK_VAR(index,"index");
		HX_STACK_LINE(434)
		if (((index != (int)-1))){
			HX_STACK_LINE(436)
			Arr->splice(index,(int)1);
		}
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC2(FlxDebugger_obj,removeButtonFromArray,(void))

Void FlxDebugger_obj::toggleVisualDebug( ){
{
		HX_STACK_FRAME("flixel.system.debug.FlxDebugger","toggleVisualDebug",0xec871e1c,"flixel.system.debug.FlxDebugger.toggleVisualDebug","flixel/system/debug/FlxDebugger.hx",442,0xd9fc0a74)
		HX_STACK_THIS(this)
		HX_STACK_LINE(442)
		::flixel::FlxG_obj::debugger->drawDebug = !(::flixel::FlxG_obj::debugger->drawDebug);
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC0(FlxDebugger_obj,toggleVisualDebug,(void))

Void FlxDebugger_obj::openHomepage( ){
{
		HX_STACK_FRAME("flixel.system.debug.FlxDebugger","openHomepage",0x2c4a291b,"flixel.system.debug.FlxDebugger.openHomepage","flixel/system/debug/FlxDebugger.hx",447,0xd9fc0a74)
		HX_STACK_THIS(this)
		HX_STACK_LINE(447)
		::flash::Lib_obj::getURL(::flash::net::URLRequest_obj::__new(HX_CSTRING("http://www.haxeflixel.com")),HX_CSTRING("_blank"));
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC0(FlxDebugger_obj,openHomepage,(void))

int FlxDebugger_obj::GUTTER;

int FlxDebugger_obj::TOP_HEIGHT;


FlxDebugger_obj::FlxDebugger_obj()
{
}

void FlxDebugger_obj::__Mark(HX_MARK_PARAMS)
{
	HX_MARK_BEGIN_CLASS(FlxDebugger);
	HX_MARK_MEMBER_NAME(stats,"stats");
	HX_MARK_MEMBER_NAME(log,"log");
	HX_MARK_MEMBER_NAME(watch,"watch");
	HX_MARK_MEMBER_NAME(vcr,"vcr");
	HX_MARK_MEMBER_NAME(console,"console");
	HX_MARK_MEMBER_NAME(hasMouse,"hasMouse");
	HX_MARK_MEMBER_NAME(_layout,"_layout");
	HX_MARK_MEMBER_NAME(_screen,"_screen");
	HX_MARK_MEMBER_NAME(_screenBounds,"_screenBounds");
	HX_MARK_MEMBER_NAME(_middleButtons,"_middleButtons");
	HX_MARK_MEMBER_NAME(_leftButtons,"_leftButtons");
	HX_MARK_MEMBER_NAME(_rightButtons,"_rightButtons");
	HX_MARK_MEMBER_NAME(_topBar,"_topBar");
	::flash::display::DisplayObjectContainer_obj::__Mark(HX_MARK_ARG);
	HX_MARK_END_CLASS();
}

void FlxDebugger_obj::__Visit(HX_VISIT_PARAMS)
{
	HX_VISIT_MEMBER_NAME(stats,"stats");
	HX_VISIT_MEMBER_NAME(log,"log");
	HX_VISIT_MEMBER_NAME(watch,"watch");
	HX_VISIT_MEMBER_NAME(vcr,"vcr");
	HX_VISIT_MEMBER_NAME(console,"console");
	HX_VISIT_MEMBER_NAME(hasMouse,"hasMouse");
	HX_VISIT_MEMBER_NAME(_layout,"_layout");
	HX_VISIT_MEMBER_NAME(_screen,"_screen");
	HX_VISIT_MEMBER_NAME(_screenBounds,"_screenBounds");
	HX_VISIT_MEMBER_NAME(_middleButtons,"_middleButtons");
	HX_VISIT_MEMBER_NAME(_leftButtons,"_leftButtons");
	HX_VISIT_MEMBER_NAME(_rightButtons,"_rightButtons");
	HX_VISIT_MEMBER_NAME(_topBar,"_topBar");
	::flash::display::DisplayObjectContainer_obj::__Visit(HX_VISIT_ARG);
}

Dynamic FlxDebugger_obj::__Field(const ::String &inName,bool inCallProp)
{
	switch(inName.length) {
	case 3:
		if (HX_FIELD_EQ(inName,"log") ) { return log; }
		if (HX_FIELD_EQ(inName,"vcr") ) { return vcr; }
		break;
	case 5:
		if (HX_FIELD_EQ(inName,"stats") ) { return stats; }
		if (HX_FIELD_EQ(inName,"watch") ) { return watch; }
		break;
	case 7:
		if (HX_FIELD_EQ(inName,"console") ) { return console; }
		if (HX_FIELD_EQ(inName,"_layout") ) { return _layout; }
		if (HX_FIELD_EQ(inName,"_screen") ) { return _screen; }
		if (HX_FIELD_EQ(inName,"_topBar") ) { return _topBar; }
		if (HX_FIELD_EQ(inName,"destroy") ) { return destroy_dyn(); }
		break;
	case 8:
		if (HX_FIELD_EQ(inName,"hasMouse") ) { return hasMouse; }
		if (HX_FIELD_EQ(inName,"onResize") ) { return onResize_dyn(); }
		break;
	case 9:
		if (HX_FIELD_EQ(inName,"setLayout") ) { return setLayout_dyn(); }
		if (HX_FIELD_EQ(inName,"addButton") ) { return addButton_dyn(); }
		break;
	case 10:
		if (HX_FIELD_EQ(inName,"onMouseOut") ) { return onMouseOut_dyn(); }
		break;
	case 11:
		if (HX_FIELD_EQ(inName,"resetLayout") ) { return resetLayout_dyn(); }
		if (HX_FIELD_EQ(inName,"onMouseOver") ) { return onMouseOver_dyn(); }
		break;
	case 12:
		if (HX_FIELD_EQ(inName,"_leftButtons") ) { return _leftButtons; }
		if (HX_FIELD_EQ(inName,"removeButton") ) { return removeButton_dyn(); }
		if (HX_FIELD_EQ(inName,"openHomepage") ) { return openHomepage_dyn(); }
		break;
	case 13:
		if (HX_FIELD_EQ(inName,"_screenBounds") ) { return _screenBounds; }
		if (HX_FIELD_EQ(inName,"_rightButtons") ) { return _rightButtons; }
		if (HX_FIELD_EQ(inName,"hAlignButtons") ) { return hAlignButtons_dyn(); }
		break;
	case 14:
		if (HX_FIELD_EQ(inName,"_middleButtons") ) { return _middleButtons; }
		break;
	case 17:
		if (HX_FIELD_EQ(inName,"resetButtonLayout") ) { return resetButtonLayout_dyn(); }
		if (HX_FIELD_EQ(inName,"toggleVisualDebug") ) { return toggleVisualDebug_dyn(); }
		break;
	case 21:
		if (HX_FIELD_EQ(inName,"removeButtonFromArray") ) { return removeButtonFromArray_dyn(); }
	}
	return super::__Field(inName,inCallProp);
}

Dynamic FlxDebugger_obj::__SetField(const ::String &inName,const Dynamic &inValue,bool inCallProp)
{
	switch(inName.length) {
	case 3:
		if (HX_FIELD_EQ(inName,"log") ) { log=inValue.Cast< ::flixel::system::debug::Log >(); return inValue; }
		if (HX_FIELD_EQ(inName,"vcr") ) { vcr=inValue.Cast< ::flixel::system::debug::VCR >(); return inValue; }
		break;
	case 5:
		if (HX_FIELD_EQ(inName,"stats") ) { stats=inValue.Cast< ::flixel::system::debug::Stats >(); return inValue; }
		if (HX_FIELD_EQ(inName,"watch") ) { watch=inValue.Cast< ::flixel::system::debug::Watch >(); return inValue; }
		break;
	case 7:
		if (HX_FIELD_EQ(inName,"console") ) { console=inValue.Cast< ::flixel::system::debug::Console >(); return inValue; }
		if (HX_FIELD_EQ(inName,"_layout") ) { _layout=inValue.Cast< ::flixel::system::debug::DebuggerLayout >(); return inValue; }
		if (HX_FIELD_EQ(inName,"_screen") ) { _screen=inValue.Cast< ::flash::geom::Point >(); return inValue; }
		if (HX_FIELD_EQ(inName,"_topBar") ) { _topBar=inValue.Cast< ::flash::display::Sprite >(); return inValue; }
		break;
	case 8:
		if (HX_FIELD_EQ(inName,"hasMouse") ) { hasMouse=inValue.Cast< bool >(); return inValue; }
		break;
	case 12:
		if (HX_FIELD_EQ(inName,"_leftButtons") ) { _leftButtons=inValue.Cast< Array< ::Dynamic > >(); return inValue; }
		break;
	case 13:
		if (HX_FIELD_EQ(inName,"_screenBounds") ) { _screenBounds=inValue.Cast< ::flash::geom::Rectangle >(); return inValue; }
		if (HX_FIELD_EQ(inName,"_rightButtons") ) { _rightButtons=inValue.Cast< Array< ::Dynamic > >(); return inValue; }
		break;
	case 14:
		if (HX_FIELD_EQ(inName,"_middleButtons") ) { _middleButtons=inValue.Cast< Array< ::Dynamic > >(); return inValue; }
	}
	return super::__SetField(inName,inValue,inCallProp);
}

void FlxDebugger_obj::__GetFields(Array< ::String> &outFields)
{
	outFields->push(HX_CSTRING("stats"));
	outFields->push(HX_CSTRING("log"));
	outFields->push(HX_CSTRING("watch"));
	outFields->push(HX_CSTRING("vcr"));
	outFields->push(HX_CSTRING("console"));
	outFields->push(HX_CSTRING("hasMouse"));
	outFields->push(HX_CSTRING("_layout"));
	outFields->push(HX_CSTRING("_screen"));
	outFields->push(HX_CSTRING("_screenBounds"));
	outFields->push(HX_CSTRING("_middleButtons"));
	outFields->push(HX_CSTRING("_leftButtons"));
	outFields->push(HX_CSTRING("_rightButtons"));
	outFields->push(HX_CSTRING("_topBar"));
	super::__GetFields(outFields);
};

static ::String sStaticFields[] = {
	HX_CSTRING("GUTTER"),
	HX_CSTRING("TOP_HEIGHT"),
	String(null()) };

#if HXCPP_SCRIPTABLE
static hx::StorageInfo sMemberStorageInfo[] = {
	{hx::fsObject /*::flixel::system::debug::Stats*/ ,(int)offsetof(FlxDebugger_obj,stats),HX_CSTRING("stats")},
	{hx::fsObject /*::flixel::system::debug::Log*/ ,(int)offsetof(FlxDebugger_obj,log),HX_CSTRING("log")},
	{hx::fsObject /*::flixel::system::debug::Watch*/ ,(int)offsetof(FlxDebugger_obj,watch),HX_CSTRING("watch")},
	{hx::fsObject /*::flixel::system::debug::VCR*/ ,(int)offsetof(FlxDebugger_obj,vcr),HX_CSTRING("vcr")},
	{hx::fsObject /*::flixel::system::debug::Console*/ ,(int)offsetof(FlxDebugger_obj,console),HX_CSTRING("console")},
	{hx::fsBool,(int)offsetof(FlxDebugger_obj,hasMouse),HX_CSTRING("hasMouse")},
	{hx::fsObject /*::flixel::system::debug::DebuggerLayout*/ ,(int)offsetof(FlxDebugger_obj,_layout),HX_CSTRING("_layout")},
	{hx::fsObject /*::flash::geom::Point*/ ,(int)offsetof(FlxDebugger_obj,_screen),HX_CSTRING("_screen")},
	{hx::fsObject /*::flash::geom::Rectangle*/ ,(int)offsetof(FlxDebugger_obj,_screenBounds),HX_CSTRING("_screenBounds")},
	{hx::fsObject /*Array< ::Dynamic >*/ ,(int)offsetof(FlxDebugger_obj,_middleButtons),HX_CSTRING("_middleButtons")},
	{hx::fsObject /*Array< ::Dynamic >*/ ,(int)offsetof(FlxDebugger_obj,_leftButtons),HX_CSTRING("_leftButtons")},
	{hx::fsObject /*Array< ::Dynamic >*/ ,(int)offsetof(FlxDebugger_obj,_rightButtons),HX_CSTRING("_rightButtons")},
	{hx::fsObject /*::flash::display::Sprite*/ ,(int)offsetof(FlxDebugger_obj,_topBar),HX_CSTRING("_topBar")},
	{ hx::fsUnknown, 0, null()}
};
#endif

static ::String sMemberFields[] = {
	HX_CSTRING("stats"),
	HX_CSTRING("log"),
	HX_CSTRING("watch"),
	HX_CSTRING("vcr"),
	HX_CSTRING("console"),
	HX_CSTRING("hasMouse"),
	HX_CSTRING("_layout"),
	HX_CSTRING("_screen"),
	HX_CSTRING("_screenBounds"),
	HX_CSTRING("_middleButtons"),
	HX_CSTRING("_leftButtons"),
	HX_CSTRING("_rightButtons"),
	HX_CSTRING("_topBar"),
	HX_CSTRING("destroy"),
	HX_CSTRING("setLayout"),
	HX_CSTRING("resetLayout"),
	HX_CSTRING("onResize"),
	HX_CSTRING("hAlignButtons"),
	HX_CSTRING("resetButtonLayout"),
	HX_CSTRING("addButton"),
	HX_CSTRING("removeButton"),
	HX_CSTRING("onMouseOver"),
	HX_CSTRING("onMouseOut"),
	HX_CSTRING("removeButtonFromArray"),
	HX_CSTRING("toggleVisualDebug"),
	HX_CSTRING("openHomepage"),
	String(null()) };

static void sMarkStatics(HX_MARK_PARAMS) {
	HX_MARK_MEMBER_NAME(FlxDebugger_obj::__mClass,"__mClass");
	HX_MARK_MEMBER_NAME(FlxDebugger_obj::GUTTER,"GUTTER");
	HX_MARK_MEMBER_NAME(FlxDebugger_obj::TOP_HEIGHT,"TOP_HEIGHT");
};

#ifdef HXCPP_VISIT_ALLOCS
static void sVisitStatics(HX_VISIT_PARAMS) {
	HX_VISIT_MEMBER_NAME(FlxDebugger_obj::__mClass,"__mClass");
	HX_VISIT_MEMBER_NAME(FlxDebugger_obj::GUTTER,"GUTTER");
	HX_VISIT_MEMBER_NAME(FlxDebugger_obj::TOP_HEIGHT,"TOP_HEIGHT");
};

#endif

Class FlxDebugger_obj::__mClass;

void FlxDebugger_obj::__register()
{
	hx::Static(__mClass) = hx::RegisterClass(HX_CSTRING("flixel.system.debug.FlxDebugger"), hx::TCanCast< FlxDebugger_obj> ,sStaticFields,sMemberFields,
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

void FlxDebugger_obj::__boot()
{
	GUTTER= (int)2;
	TOP_HEIGHT= (int)20;
}

} // end namespace flixel
} // end namespace system
} // end namespace debug
