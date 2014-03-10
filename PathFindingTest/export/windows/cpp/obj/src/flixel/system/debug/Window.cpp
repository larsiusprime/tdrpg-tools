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
#ifndef INCLUDED_flash_display_PixelSnapping
#include <flash/display/PixelSnapping.h>
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
#ifndef INCLUDED_flash_text_TextField
#include <flash/text/TextField.h>
#endif
#ifndef INCLUDED_flash_text_TextFormat
#include <flash/text/TextFormat.h>
#endif
#ifndef INCLUDED_flixel_FlxG
#include <flixel/FlxG.h>
#endif
#ifndef INCLUDED_flixel_interfaces_IFlxDestroyable
#include <flixel/interfaces/IFlxDestroyable.h>
#endif
#ifndef INCLUDED_flixel_system_FlxAssets
#include <flixel/system/FlxAssets.h>
#endif
#ifndef INCLUDED_flixel_system_debug_Window
#include <flixel/system/debug/Window.h>
#endif
#ifndef INCLUDED_flixel_system_debug__Window_GraphicCloseButton
#include <flixel/system/debug/_Window/GraphicCloseButton.h>
#endif
#ifndef INCLUDED_flixel_system_debug__Window_GraphicWindowHandle
#include <flixel/system/debug/_Window/GraphicWindowHandle.h>
#endif
#ifndef INCLUDED_flixel_system_ui_FlxSystemButton
#include <flixel/system/ui/FlxSystemButton.h>
#endif
#ifndef INCLUDED_flixel_util_FlxSave
#include <flixel/util/FlxSave.h>
#endif
#ifndef INCLUDED_hxMath
#include <hxMath.h>
#endif
namespace flixel{
namespace system{
namespace debug{

Void Window_obj::__construct(::String Title,::flash::display::BitmapData Icon,hx::Null< Float >  __o_Width,hx::Null< Float >  __o_Height,hx::Null< bool >  __o_Resizable,::flash::geom::Rectangle Bounds,hx::Null< bool >  __o_Closable)
{
HX_STACK_FRAME("flixel.system.debug.Window","new",0x5aefd38a,"flixel.system.debug.Window.new","flixel/system/debug/Window.hx",95,0xb8dfd4e5)

HX_STACK_ARG(Title,"Title")

HX_STACK_ARG(Icon,"Icon")

HX_STACK_ARG(__o_Width,"Width")

HX_STACK_ARG(__o_Height,"Height")

HX_STACK_ARG(__o_Resizable,"Resizable")

HX_STACK_ARG(Bounds,"Bounds")

HX_STACK_ARG(__o_Closable,"Closable")
Float Width = __o_Width.Default(0);
Float Height = __o_Height.Default(0);
bool Resizable = __o_Resizable.Default(true);
bool Closable = __o_Closable.Default(false);
{
	HX_STACK_LINE(96)
	super::__construct();
	HX_STACK_LINE(98)
	this->_width = ::Std_obj::_int(::Math_obj::abs(Width));
	HX_STACK_LINE(99)
	this->_height = ::Std_obj::_int(::Math_obj::abs(Height));
	HX_STACK_LINE(100)
	this->updateBounds(Bounds);
	HX_STACK_LINE(101)
	this->_drag = ::flash::geom::Point_obj::__new(null(),null());
	HX_STACK_LINE(103)
	this->_resizable = Resizable;
	HX_STACK_LINE(105)
	this->_shadow = ::flash::display::Bitmap_obj::__new(::flash::display::BitmapData_obj::__new((int)1,(int)2,true,(int)-16777216,null()),null(),null());
	HX_STACK_LINE(106)
	this->addChild(this->_shadow);
	HX_STACK_LINE(107)
	this->_background = ::flash::display::Bitmap_obj::__new(::flash::display::BitmapData_obj::__new((int)1,(int)1,true,(int)-580952225,null()),null(),null());
	HX_STACK_LINE(108)
	this->_background->set_y((int)15);
	HX_STACK_LINE(109)
	this->addChild(this->_background);
	HX_STACK_LINE(110)
	this->_header = ::flash::display::Bitmap_obj::__new(::flash::display::BitmapData_obj::__new((int)1,(int)15,true,(int)-1157627904,null()),null(),null());
	HX_STACK_LINE(111)
	this->addChild(this->_header);
	HX_STACK_LINE(113)
	this->_title = ::flash::text::TextField_obj::__new();
	HX_STACK_LINE(114)
	this->_title->set_x((int)2);
	HX_STACK_LINE(115)
	this->_title->set_y((int)-1);
	HX_STACK_LINE(116)
	this->_title->set_alpha(0.8);
	HX_STACK_LINE(117)
	this->_title->set_height((int)20);
	HX_STACK_LINE(118)
	this->_title->set_selectable(false);
	HX_STACK_LINE(119)
	this->_title->set_multiline(false);
	HX_STACK_LINE(120)
	this->_title->set_embedFonts(true);
	HX_STACK_LINE(121)
	this->_title->set_defaultTextFormat(::flash::text::TextFormat_obj::__new(::flixel::system::FlxAssets_obj::FONT_DEBUGGER,(int)12,(int)16777215,null(),null(),null(),null(),null(),null(),null(),null(),null(),null()));
	HX_STACK_LINE(122)
	this->_title->set_text(Title);
	HX_STACK_LINE(123)
	this->addChild(this->_title);
	HX_STACK_LINE(125)
	if (((Icon != null()))){
		HX_STACK_LINE(127)
		::flash::display::Bitmap _icon = ::flash::display::Bitmap_obj::__new(Icon,null(),null());		HX_STACK_VAR(_icon,"_icon");
		HX_STACK_LINE(128)
		_icon->set_x((int)5);
		HX_STACK_LINE(129)
		_icon->set_y((int)2);
		HX_STACK_LINE(130)
		_icon->set_alpha(0.8);
		HX_STACK_LINE(131)
		Float _g = _icon->get_x();		HX_STACK_VAR(_g,"_g");
		HX_STACK_LINE(131)
		this->_title->set_x(((_g + _icon->get_width()) + (int)2));
		HX_STACK_LINE(132)
		this->addChild(_icon);
	}
	HX_STACK_LINE(135)
	if ((this->_resizable)){
		HX_STACK_LINE(137)
		this->_handle = ::flash::display::Bitmap_obj::__new(::flixel::system::debug::_Window::GraphicWindowHandle_obj::__new((int)0,(int)0,null(),null()),null(),null());
		HX_STACK_LINE(138)
		this->addChild(this->_handle);
	}
	HX_STACK_LINE(141)
	if ((Closable)){
		HX_STACK_LINE(143)
		this->_closeButton = ::flixel::system::ui::FlxSystemButton_obj::__new(::flixel::system::debug::_Window::GraphicCloseButton_obj::__new((int)0,(int)0,null(),null()),this->close_dyn(),null());
		HX_STACK_LINE(144)
		this->_closeButton->set_alpha(0.8);
		HX_STACK_LINE(145)
		this->addChild(this->_closeButton);
	}
	HX_STACK_LINE(148)
	if (((bool((this->_width != (int)0)) || bool((this->_height != (int)0))))){
		HX_STACK_LINE(150)
		this->updateSize();
	}
	HX_STACK_LINE(152)
	this->bound();
	HX_STACK_LINE(154)
	this->addEventListener(::flash::events::Event_obj::ENTER_FRAME,this->init_dyn(),null(),null(),null());
	HX_STACK_LINE(156)
	this->_id = (::flixel::system::debug::Window_obj::WINDOW_AMOUNT)++;
	HX_STACK_LINE(157)
	if (((::flixel::FlxG_obj::save->data->__Field(HX_CSTRING("windowSettings"),true) != null()))){
		HX_STACK_LINE(159)
		this->set_visible(::flixel::FlxG_obj::save->data->__Field(HX_CSTRING("windowSettings"),true)->__GetItem(this->_id));
	}
	else{
		HX_STACK_LINE(163)
		::flixel::FlxG_obj::save->data->__FieldRef(HX_CSTRING("windowSettings")) = Array_obj< bool >::__new();
	}
}
;
	return null();
}

//Window_obj::~Window_obj() { }

Dynamic Window_obj::__CreateEmpty() { return  new Window_obj; }
hx::ObjectPtr< Window_obj > Window_obj::__new(::String Title,::flash::display::BitmapData Icon,hx::Null< Float >  __o_Width,hx::Null< Float >  __o_Height,hx::Null< bool >  __o_Resizable,::flash::geom::Rectangle Bounds,hx::Null< bool >  __o_Closable)
{  hx::ObjectPtr< Window_obj > result = new Window_obj();
	result->__construct(Title,Icon,__o_Width,__o_Height,__o_Resizable,Bounds,__o_Closable);
	return result;}

Dynamic Window_obj::__Create(hx::DynamicArray inArgs)
{  hx::ObjectPtr< Window_obj > result = new Window_obj();
	result->__construct(inArgs[0],inArgs[1],inArgs[2],inArgs[3],inArgs[4],inArgs[5],inArgs[6]);
	return result;}

Void Window_obj::destroy( ){
{
		HX_STACK_FRAME("flixel.system.debug.Window","destroy",0x5fb40d24,"flixel.system.debug.Window.destroy","flixel/system/debug/Window.hx",171,0xb8dfd4e5)
		HX_STACK_THIS(this)
		HX_STACK_LINE(172)
		this->minSize = null();
		HX_STACK_LINE(173)
		this->maxSize = null();
		HX_STACK_LINE(174)
		this->_bounds = null();
		HX_STACK_LINE(175)
		if (((this->_shadow != null()))){
			HX_STACK_LINE(177)
			this->removeChild(this->_shadow);
		}
		HX_STACK_LINE(179)
		this->_shadow = null();
		HX_STACK_LINE(180)
		if (((this->_background != null()))){
			HX_STACK_LINE(182)
			this->removeChild(this->_background);
		}
		HX_STACK_LINE(184)
		this->_background = null();
		HX_STACK_LINE(185)
		if (((this->_header != null()))){
			HX_STACK_LINE(187)
			this->removeChild(this->_header);
		}
		HX_STACK_LINE(189)
		this->_header = null();
		HX_STACK_LINE(190)
		if (((this->_title != null()))){
			HX_STACK_LINE(192)
			this->removeChild(this->_title);
		}
		HX_STACK_LINE(194)
		this->_title = null();
		HX_STACK_LINE(195)
		if (((this->_handle != null()))){
			HX_STACK_LINE(197)
			this->removeChild(this->_handle);
		}
		HX_STACK_LINE(199)
		this->_handle = null();
		HX_STACK_LINE(200)
		this->_drag = null();
		HX_STACK_LINE(201)
		this->_closeButton = ::flixel::FlxG_obj::safeDestroy(this->_closeButton);
		HX_STACK_LINE(202)
		this->get_stage()->removeEventListener(::flash::events::MouseEvent_obj::MOUSE_MOVE,this->onMouseMove_dyn(),null());
		HX_STACK_LINE(203)
		this->get_stage()->removeEventListener(::flash::events::MouseEvent_obj::MOUSE_DOWN,this->onMouseDown_dyn(),null());
		HX_STACK_LINE(204)
		this->get_stage()->removeEventListener(::flash::events::MouseEvent_obj::MOUSE_UP,this->onMouseUp_dyn(),null());
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC0(Window_obj,destroy,(void))

Void Window_obj::resize( Float Width,Float Height){
{
		HX_STACK_FRAME("flixel.system.debug.Window","resize",0x4ec62d0a,"flixel.system.debug.Window.resize","flixel/system/debug/Window.hx",213,0xb8dfd4e5)
		HX_STACK_THIS(this)
		HX_STACK_ARG(Width,"Width")
		HX_STACK_ARG(Height,"Height")
		HX_STACK_LINE(214)
		this->_width = ::Std_obj::_int(::Math_obj::abs(Width));
		HX_STACK_LINE(215)
		this->_height = ::Std_obj::_int(::Math_obj::abs(Height));
		HX_STACK_LINE(216)
		this->updateSize();
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC2(Window_obj,resize,(void))

Void Window_obj::reposition( Float X,Float Y){
{
		HX_STACK_FRAME("flixel.system.debug.Window","reposition",0x0fe38572,"flixel.system.debug.Window.reposition","flixel/system/debug/Window.hx",225,0xb8dfd4e5)
		HX_STACK_THIS(this)
		HX_STACK_ARG(X,"X")
		HX_STACK_ARG(Y,"Y")
		HX_STACK_LINE(226)
		this->set_x(X);
		HX_STACK_LINE(227)
		this->set_y(Y);
		HX_STACK_LINE(228)
		this->bound();
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC2(Window_obj,reposition,(void))

Void Window_obj::updateBounds( ::flash::geom::Rectangle Bounds){
{
		HX_STACK_FRAME("flixel.system.debug.Window","updateBounds",0x436474f4,"flixel.system.debug.Window.updateBounds","flixel/system/debug/Window.hx",232,0xb8dfd4e5)
		HX_STACK_THIS(this)
		HX_STACK_ARG(Bounds,"Bounds")
		HX_STACK_LINE(233)
		this->_bounds = Bounds;
		HX_STACK_LINE(234)
		this->minSize = ::flash::geom::Point_obj::__new((int)50,(int)30);
		HX_STACK_LINE(235)
		if (((this->_bounds != null()))){
			HX_STACK_LINE(237)
			this->maxSize = ::flash::geom::Point_obj::__new(this->_bounds->width,this->_bounds->height);
		}
		else{
			HX_STACK_LINE(241)
			this->maxSize = ::flash::geom::Point_obj::__new(1.79e+308,1.79e+308);
		}
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC1(Window_obj,updateBounds,(void))

Void Window_obj::toggleVisibility( ){
{
		HX_STACK_FRAME("flixel.system.debug.Window","toggleVisibility",0xc9aafd1c,"flixel.system.debug.Window.toggleVisibility","flixel/system/debug/Window.hx",246,0xb8dfd4e5)
		HX_STACK_THIS(this)
		HX_STACK_LINE(247)
		this->set_visible(!(this->get_visible()));
		HX_STACK_LINE(248)
		hx::IndexRef((::flixel::FlxG_obj::save->data->__Field(HX_CSTRING("windowSettings"),true)).mPtr,this->_id) = this->get_visible();
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC0(Window_obj,toggleVisibility,(void))

Void Window_obj::init( ::flash::events::Event E){
{
		HX_STACK_FRAME("flixel.system.debug.Window","init",0x33a1fca6,"flixel.system.debug.Window.init","flixel/system/debug/Window.hx",257,0xb8dfd4e5)
		HX_STACK_THIS(this)
		HX_STACK_ARG(E,"E")
		HX_STACK_LINE(261)
		if (((this->get_stage() == null()))){
			HX_STACK_LINE(264)
			return null();
		}
		HX_STACK_LINE(266)
		this->removeEventListener(::flash::events::Event_obj::ENTER_FRAME,this->init_dyn(),null());
		HX_STACK_LINE(268)
		this->get_stage()->addEventListener(::flash::events::MouseEvent_obj::MOUSE_MOVE,this->onMouseMove_dyn(),null(),null(),null());
		HX_STACK_LINE(269)
		this->get_stage()->addEventListener(::flash::events::MouseEvent_obj::MOUSE_DOWN,this->onMouseDown_dyn(),null(),null(),null());
		HX_STACK_LINE(270)
		this->get_stage()->addEventListener(::flash::events::MouseEvent_obj::MOUSE_UP,this->onMouseUp_dyn(),null(),null(),null());
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC1(Window_obj,init,(void))

Void Window_obj::onMouseMove( ::flash::events::MouseEvent E){
{
		HX_STACK_FRAME("flixel.system.debug.Window","onMouseMove",0xdd6abbe1,"flixel.system.debug.Window.onMouseMove","flixel/system/debug/Window.hx",277,0xb8dfd4e5)
		HX_STACK_THIS(this)
		HX_STACK_ARG(E,"E")
		HX_STACK_LINE(278)
		if ((!(this->get_parent()->get_visible()))){
			HX_STACK_LINE(280)
			this->_overHandle = this->_overHeader = false;
			HX_STACK_LINE(281)
			return null();
		}
		HX_STACK_LINE(284)
		if ((this->_dragging)){
			HX_STACK_LINE(286)
			this->_overHeader = true;
			HX_STACK_LINE(287)
			Float _g = (this->get_parent()->get_mouseX() - this->_drag->x);		HX_STACK_VAR(_g,"_g");
			HX_STACK_LINE(287)
			this->reposition(_g,(this->get_parent()->get_mouseY() - this->_drag->y));
		}
		else{
			HX_STACK_LINE(289)
			if ((this->_resizing)){
				HX_STACK_LINE(291)
				this->_overHandle = true;
				HX_STACK_LINE(292)
				Float _g1 = (this->get_mouseX() - this->_drag->x);		HX_STACK_VAR(_g1,"_g1");
				HX_STACK_LINE(292)
				this->resize(_g1,(this->get_mouseY() - this->_drag->y));
			}
			else{
				HX_STACK_LINE(294)
				if (((  (((  (((  (((this->get_mouseX() >= (int)0))) ? bool((this->get_mouseX() <= this->_width)) : bool(false) ))) ? bool((this->get_mouseY() >= (int)0)) : bool(false) ))) ? bool((this->get_mouseY() <= this->_height)) : bool(false) ))){
					HX_STACK_LINE(296)
					Float _g2 = this->get_mouseX();		HX_STACK_VAR(_g2,"_g2");
					HX_STACK_LINE(296)
					if (((_g2 <= this->_header->get_width()))){
						HX_STACK_LINE(296)
						Float _g3 = this->get_mouseY();		HX_STACK_VAR(_g3,"_g3");
						HX_STACK_LINE(296)
						this->_overHeader = (_g3 <= this->_header->get_height());
					}
					else{
						HX_STACK_LINE(296)
						this->_overHeader = false;
					}
					HX_STACK_LINE(297)
					if ((this->_resizable)){
						HX_STACK_LINE(299)
						Float _g4 = this->get_mouseX();		HX_STACK_VAR(_g4,"_g4");
						HX_STACK_LINE(299)
						if (((_g4 >= (this->_width - this->_handle->get_width())))){
							HX_STACK_LINE(299)
							Float _g5 = this->get_mouseY();		HX_STACK_VAR(_g5,"_g5");
							HX_STACK_LINE(299)
							this->_overHandle = (_g5 >= (this->_height - this->_handle->get_height()));
						}
						else{
							HX_STACK_LINE(299)
							this->_overHandle = false;
						}
					}
				}
				else{
					HX_STACK_LINE(304)
					this->_overHandle = this->_overHeader = false;
				}
			}
		}
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC1(Window_obj,onMouseMove,(void))

Void Window_obj::onMouseDown( ::flash::events::MouseEvent E){
{
		HX_STACK_FRAME("flixel.system.debug.Window","onMouseDown",0xd777d132,"flixel.system.debug.Window.onMouseDown","flixel/system/debug/Window.hx",313,0xb8dfd4e5)
		HX_STACK_THIS(this)
		HX_STACK_ARG(E,"E")
		HX_STACK_LINE(313)
		if ((this->_overHeader)){
			HX_STACK_LINE(315)
			this->get_parent()->addChild(hx::ObjectPtr<OBJ_>(this));
			HX_STACK_LINE(316)
			this->_dragging = true;
			HX_STACK_LINE(317)
			this->_drag->x = this->get_mouseX();
			HX_STACK_LINE(318)
			this->_drag->y = this->get_mouseY();
		}
		else{
			HX_STACK_LINE(320)
			if ((this->_overHandle)){
				HX_STACK_LINE(322)
				this->_resizing = true;
				HX_STACK_LINE(323)
				this->_drag->x = (this->_width - this->get_mouseX());
				HX_STACK_LINE(324)
				this->_drag->y = (this->_height - this->get_mouseY());
			}
		}
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC1(Window_obj,onMouseDown,(void))

Void Window_obj::onMouseUp( ::flash::events::MouseEvent E){
{
		HX_STACK_FRAME("flixel.system.debug.Window","onMouseUp",0x62a36b2b,"flixel.system.debug.Window.onMouseUp","flixel/system/debug/Window.hx",332,0xb8dfd4e5)
		HX_STACK_THIS(this)
		HX_STACK_ARG(E,"E")
		HX_STACK_LINE(333)
		this->_dragging = false;
		HX_STACK_LINE(334)
		this->_resizing = false;
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC1(Window_obj,onMouseUp,(void))

Void Window_obj::bound( ){
{
		HX_STACK_FRAME("flixel.system.debug.Window","bound",0xf2ff51e8,"flixel.system.debug.Window.bound","flixel/system/debug/Window.hx",344,0xb8dfd4e5)
		HX_STACK_THIS(this)
		HX_STACK_LINE(344)
		if (((this->_bounds != null()))){
			struct _Function_2_1{
				inline static Float Block( ::flixel::system::debug::Window_obj *__this){
					HX_STACK_FRAME("*","closure",0x5bdab937,"*.closure","flixel/system/debug/Window.hx",346,0xb8dfd4e5)
					{
						HX_STACK_LINE(346)
						Float Value = __this->get_x();		HX_STACK_VAR(Value,"Value");
						HX_STACK_LINE(346)
						Float Min = __this->_bounds->get_left();		HX_STACK_VAR(Min,"Min");
						HX_STACK_LINE(346)
						Float Max = (__this->_bounds->get_right() - __this->_width);		HX_STACK_VAR(Max,"Max");
						HX_STACK_LINE(346)
						Float lowerBound;		HX_STACK_VAR(lowerBound,"lowerBound");
						HX_STACK_LINE(346)
						if (((Value < Min))){
							HX_STACK_LINE(346)
							lowerBound = Min;
						}
						else{
							HX_STACK_LINE(346)
							lowerBound = Value;
						}
						HX_STACK_LINE(346)
						return (  (((lowerBound > Max))) ? Float(Max) : Float(lowerBound) );
					}
					return null();
				}
			};
			HX_STACK_LINE(346)
			this->set_x(_Function_2_1::Block(this));
			struct _Function_2_2{
				inline static Float Block( ::flixel::system::debug::Window_obj *__this){
					HX_STACK_FRAME("*","closure",0x5bdab937,"*.closure","flixel/system/debug/Window.hx",347,0xb8dfd4e5)
					{
						HX_STACK_LINE(347)
						Float Value = __this->get_y();		HX_STACK_VAR(Value,"Value");
						HX_STACK_LINE(347)
						Float Min = __this->_bounds->get_top();		HX_STACK_VAR(Min,"Min");
						HX_STACK_LINE(347)
						Float Max = (__this->_bounds->get_bottom() - __this->_height);		HX_STACK_VAR(Max,"Max");
						HX_STACK_LINE(347)
						Float lowerBound;		HX_STACK_VAR(lowerBound,"lowerBound");
						HX_STACK_LINE(347)
						if (((Value < Min))){
							HX_STACK_LINE(347)
							lowerBound = Min;
						}
						else{
							HX_STACK_LINE(347)
							lowerBound = Value;
						}
						HX_STACK_LINE(347)
						return (  (((lowerBound > Max))) ? Float(Max) : Float(lowerBound) );
					}
					return null();
				}
			};
			HX_STACK_LINE(347)
			this->set_y(_Function_2_2::Block(this));
		}
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC0(Window_obj,bound,(void))

Void Window_obj::updateSize( ){
{
		HX_STACK_FRAME("flixel.system.debug.Window","updateSize",0x6f89a180,"flixel.system.debug.Window.updateSize","flixel/system/debug/Window.hx",355,0xb8dfd4e5)
		HX_STACK_THIS(this)
		struct _Function_1_1{
			inline static Float Block( ::flixel::system::debug::Window_obj *__this){
				HX_STACK_FRAME("*","closure",0x5bdab937,"*.closure","flixel/system/debug/Window.hx",356,0xb8dfd4e5)
				{
					HX_STACK_LINE(356)
					Float Value = __this->_width;		HX_STACK_VAR(Value,"Value");
					HX_STACK_LINE(356)
					Float Min = __this->minSize->x;		HX_STACK_VAR(Min,"Min");
					HX_STACK_LINE(356)
					Float Max = __this->maxSize->x;		HX_STACK_VAR(Max,"Max");
					HX_STACK_LINE(356)
					Float lowerBound;		HX_STACK_VAR(lowerBound,"lowerBound");
					HX_STACK_LINE(356)
					if (((Value < Min))){
						HX_STACK_LINE(356)
						lowerBound = Min;
					}
					else{
						HX_STACK_LINE(356)
						lowerBound = Value;
					}
					HX_STACK_LINE(356)
					return (  (((lowerBound > Max))) ? Float(Max) : Float(lowerBound) );
				}
				return null();
			}
		};
		HX_STACK_LINE(356)
		this->_width = ::Std_obj::_int(_Function_1_1::Block(this));
		struct _Function_1_2{
			inline static Float Block( ::flixel::system::debug::Window_obj *__this){
				HX_STACK_FRAME("*","closure",0x5bdab937,"*.closure","flixel/system/debug/Window.hx",357,0xb8dfd4e5)
				{
					HX_STACK_LINE(357)
					Float Value = __this->_height;		HX_STACK_VAR(Value,"Value");
					HX_STACK_LINE(357)
					Float Min = __this->minSize->y;		HX_STACK_VAR(Min,"Min");
					HX_STACK_LINE(357)
					Float Max = __this->maxSize->y;		HX_STACK_VAR(Max,"Max");
					HX_STACK_LINE(357)
					Float lowerBound;		HX_STACK_VAR(lowerBound,"lowerBound");
					HX_STACK_LINE(357)
					if (((Value < Min))){
						HX_STACK_LINE(357)
						lowerBound = Min;
					}
					else{
						HX_STACK_LINE(357)
						lowerBound = Value;
					}
					HX_STACK_LINE(357)
					return (  (((lowerBound > Max))) ? Float(Max) : Float(lowerBound) );
				}
				return null();
			}
		};
		HX_STACK_LINE(357)
		this->_height = ::Std_obj::_int(_Function_1_2::Block(this));
		HX_STACK_LINE(359)
		this->_header->set_scaleX(this->_width);
		HX_STACK_LINE(360)
		this->_background->set_scaleX(this->_width);
		HX_STACK_LINE(361)
		this->_background->set_scaleY((this->_height - (int)15));
		HX_STACK_LINE(362)
		this->_shadow->set_scaleX(this->_width);
		HX_STACK_LINE(363)
		this->_shadow->set_y(this->_height);
		HX_STACK_LINE(364)
		this->_title->set_width((this->_width - (int)4));
		HX_STACK_LINE(365)
		if ((this->_resizable)){
			HX_STACK_LINE(367)
			this->_handle->set_x((this->_width - this->_handle->get_width()));
			HX_STACK_LINE(368)
			this->_handle->set_y((this->_height - this->_handle->get_height()));
		}
		HX_STACK_LINE(370)
		if (((this->_closeButton != null()))){
			HX_STACK_LINE(372)
			this->_closeButton->set_x(((this->_width - this->_closeButton->get_width()) - (int)3));
			HX_STACK_LINE(373)
			this->_closeButton->set_y((int)3);
		}
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC0(Window_obj,updateSize,(void))

Void Window_obj::close( ){
{
		HX_STACK_FRAME("flixel.system.debug.Window","close",0x8465b962,"flixel.system.debug.Window.close","flixel/system/debug/Window.hx",378,0xb8dfd4e5)
		HX_STACK_THIS(this)
		HX_STACK_LINE(379)
		this->destroy();
		HX_STACK_LINE(380)
		this->get_parent()->removeChild(hx::ObjectPtr<OBJ_>(this));
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC0(Window_obj,close,(void))

int Window_obj::BG_COLOR;

int Window_obj::TOP_COLOR;

Float Window_obj::HEADER_ALPHA;

int Window_obj::WINDOW_AMOUNT;


Window_obj::Window_obj()
{
}

void Window_obj::__Mark(HX_MARK_PARAMS)
{
	HX_MARK_BEGIN_CLASS(Window);
	HX_MARK_MEMBER_NAME(minSize,"minSize");
	HX_MARK_MEMBER_NAME(maxSize,"maxSize");
	HX_MARK_MEMBER_NAME(_width,"_width");
	HX_MARK_MEMBER_NAME(_height,"_height");
	HX_MARK_MEMBER_NAME(_bounds,"_bounds");
	HX_MARK_MEMBER_NAME(_background,"_background");
	HX_MARK_MEMBER_NAME(_header,"_header");
	HX_MARK_MEMBER_NAME(_shadow,"_shadow");
	HX_MARK_MEMBER_NAME(_title,"_title");
	HX_MARK_MEMBER_NAME(_handle,"_handle");
	HX_MARK_MEMBER_NAME(_closeButton,"_closeButton");
	HX_MARK_MEMBER_NAME(_overHeader,"_overHeader");
	HX_MARK_MEMBER_NAME(_overHandle,"_overHandle");
	HX_MARK_MEMBER_NAME(_drag,"_drag");
	HX_MARK_MEMBER_NAME(_dragging,"_dragging");
	HX_MARK_MEMBER_NAME(_resizing,"_resizing");
	HX_MARK_MEMBER_NAME(_resizable,"_resizable");
	HX_MARK_MEMBER_NAME(_id,"_id");
	::flash::display::DisplayObjectContainer_obj::__Mark(HX_MARK_ARG);
	HX_MARK_END_CLASS();
}

void Window_obj::__Visit(HX_VISIT_PARAMS)
{
	HX_VISIT_MEMBER_NAME(minSize,"minSize");
	HX_VISIT_MEMBER_NAME(maxSize,"maxSize");
	HX_VISIT_MEMBER_NAME(_width,"_width");
	HX_VISIT_MEMBER_NAME(_height,"_height");
	HX_VISIT_MEMBER_NAME(_bounds,"_bounds");
	HX_VISIT_MEMBER_NAME(_background,"_background");
	HX_VISIT_MEMBER_NAME(_header,"_header");
	HX_VISIT_MEMBER_NAME(_shadow,"_shadow");
	HX_VISIT_MEMBER_NAME(_title,"_title");
	HX_VISIT_MEMBER_NAME(_handle,"_handle");
	HX_VISIT_MEMBER_NAME(_closeButton,"_closeButton");
	HX_VISIT_MEMBER_NAME(_overHeader,"_overHeader");
	HX_VISIT_MEMBER_NAME(_overHandle,"_overHandle");
	HX_VISIT_MEMBER_NAME(_drag,"_drag");
	HX_VISIT_MEMBER_NAME(_dragging,"_dragging");
	HX_VISIT_MEMBER_NAME(_resizing,"_resizing");
	HX_VISIT_MEMBER_NAME(_resizable,"_resizable");
	HX_VISIT_MEMBER_NAME(_id,"_id");
	::flash::display::DisplayObjectContainer_obj::__Visit(HX_VISIT_ARG);
}

Dynamic Window_obj::__Field(const ::String &inName,bool inCallProp)
{
	switch(inName.length) {
	case 3:
		if (HX_FIELD_EQ(inName,"_id") ) { return _id; }
		break;
	case 4:
		if (HX_FIELD_EQ(inName,"init") ) { return init_dyn(); }
		break;
	case 5:
		if (HX_FIELD_EQ(inName,"_drag") ) { return _drag; }
		if (HX_FIELD_EQ(inName,"bound") ) { return bound_dyn(); }
		if (HX_FIELD_EQ(inName,"close") ) { return close_dyn(); }
		break;
	case 6:
		if (HX_FIELD_EQ(inName,"_width") ) { return _width; }
		if (HX_FIELD_EQ(inName,"_title") ) { return _title; }
		if (HX_FIELD_EQ(inName,"resize") ) { return resize_dyn(); }
		break;
	case 7:
		if (HX_FIELD_EQ(inName,"minSize") ) { return minSize; }
		if (HX_FIELD_EQ(inName,"maxSize") ) { return maxSize; }
		if (HX_FIELD_EQ(inName,"_height") ) { return _height; }
		if (HX_FIELD_EQ(inName,"_bounds") ) { return _bounds; }
		if (HX_FIELD_EQ(inName,"_header") ) { return _header; }
		if (HX_FIELD_EQ(inName,"_shadow") ) { return _shadow; }
		if (HX_FIELD_EQ(inName,"_handle") ) { return _handle; }
		if (HX_FIELD_EQ(inName,"destroy") ) { return destroy_dyn(); }
		break;
	case 9:
		if (HX_FIELD_EQ(inName,"_dragging") ) { return _dragging; }
		if (HX_FIELD_EQ(inName,"_resizing") ) { return _resizing; }
		if (HX_FIELD_EQ(inName,"onMouseUp") ) { return onMouseUp_dyn(); }
		break;
	case 10:
		if (HX_FIELD_EQ(inName,"_resizable") ) { return _resizable; }
		if (HX_FIELD_EQ(inName,"reposition") ) { return reposition_dyn(); }
		if (HX_FIELD_EQ(inName,"updateSize") ) { return updateSize_dyn(); }
		break;
	case 11:
		if (HX_FIELD_EQ(inName,"_background") ) { return _background; }
		if (HX_FIELD_EQ(inName,"_overHeader") ) { return _overHeader; }
		if (HX_FIELD_EQ(inName,"_overHandle") ) { return _overHandle; }
		if (HX_FIELD_EQ(inName,"onMouseMove") ) { return onMouseMove_dyn(); }
		if (HX_FIELD_EQ(inName,"onMouseDown") ) { return onMouseDown_dyn(); }
		break;
	case 12:
		if (HX_FIELD_EQ(inName,"_closeButton") ) { return _closeButton; }
		if (HX_FIELD_EQ(inName,"updateBounds") ) { return updateBounds_dyn(); }
		break;
	case 13:
		if (HX_FIELD_EQ(inName,"WINDOW_AMOUNT") ) { return WINDOW_AMOUNT; }
		break;
	case 16:
		if (HX_FIELD_EQ(inName,"toggleVisibility") ) { return toggleVisibility_dyn(); }
	}
	return super::__Field(inName,inCallProp);
}

Dynamic Window_obj::__SetField(const ::String &inName,const Dynamic &inValue,bool inCallProp)
{
	switch(inName.length) {
	case 3:
		if (HX_FIELD_EQ(inName,"_id") ) { _id=inValue.Cast< int >(); return inValue; }
		break;
	case 5:
		if (HX_FIELD_EQ(inName,"_drag") ) { _drag=inValue.Cast< ::flash::geom::Point >(); return inValue; }
		break;
	case 6:
		if (HX_FIELD_EQ(inName,"_width") ) { _width=inValue.Cast< int >(); return inValue; }
		if (HX_FIELD_EQ(inName,"_title") ) { _title=inValue.Cast< ::flash::text::TextField >(); return inValue; }
		break;
	case 7:
		if (HX_FIELD_EQ(inName,"minSize") ) { minSize=inValue.Cast< ::flash::geom::Point >(); return inValue; }
		if (HX_FIELD_EQ(inName,"maxSize") ) { maxSize=inValue.Cast< ::flash::geom::Point >(); return inValue; }
		if (HX_FIELD_EQ(inName,"_height") ) { _height=inValue.Cast< int >(); return inValue; }
		if (HX_FIELD_EQ(inName,"_bounds") ) { _bounds=inValue.Cast< ::flash::geom::Rectangle >(); return inValue; }
		if (HX_FIELD_EQ(inName,"_header") ) { _header=inValue.Cast< ::flash::display::Bitmap >(); return inValue; }
		if (HX_FIELD_EQ(inName,"_shadow") ) { _shadow=inValue.Cast< ::flash::display::Bitmap >(); return inValue; }
		if (HX_FIELD_EQ(inName,"_handle") ) { _handle=inValue.Cast< ::flash::display::Bitmap >(); return inValue; }
		break;
	case 9:
		if (HX_FIELD_EQ(inName,"_dragging") ) { _dragging=inValue.Cast< bool >(); return inValue; }
		if (HX_FIELD_EQ(inName,"_resizing") ) { _resizing=inValue.Cast< bool >(); return inValue; }
		break;
	case 10:
		if (HX_FIELD_EQ(inName,"_resizable") ) { _resizable=inValue.Cast< bool >(); return inValue; }
		break;
	case 11:
		if (HX_FIELD_EQ(inName,"_background") ) { _background=inValue.Cast< ::flash::display::Bitmap >(); return inValue; }
		if (HX_FIELD_EQ(inName,"_overHeader") ) { _overHeader=inValue.Cast< bool >(); return inValue; }
		if (HX_FIELD_EQ(inName,"_overHandle") ) { _overHandle=inValue.Cast< bool >(); return inValue; }
		break;
	case 12:
		if (HX_FIELD_EQ(inName,"_closeButton") ) { _closeButton=inValue.Cast< ::flixel::system::ui::FlxSystemButton >(); return inValue; }
		break;
	case 13:
		if (HX_FIELD_EQ(inName,"WINDOW_AMOUNT") ) { WINDOW_AMOUNT=inValue.Cast< int >(); return inValue; }
	}
	return super::__SetField(inName,inValue,inCallProp);
}

void Window_obj::__GetFields(Array< ::String> &outFields)
{
	outFields->push(HX_CSTRING("minSize"));
	outFields->push(HX_CSTRING("maxSize"));
	outFields->push(HX_CSTRING("_width"));
	outFields->push(HX_CSTRING("_height"));
	outFields->push(HX_CSTRING("_bounds"));
	outFields->push(HX_CSTRING("_background"));
	outFields->push(HX_CSTRING("_header"));
	outFields->push(HX_CSTRING("_shadow"));
	outFields->push(HX_CSTRING("_title"));
	outFields->push(HX_CSTRING("_handle"));
	outFields->push(HX_CSTRING("_closeButton"));
	outFields->push(HX_CSTRING("_overHeader"));
	outFields->push(HX_CSTRING("_overHandle"));
	outFields->push(HX_CSTRING("_drag"));
	outFields->push(HX_CSTRING("_dragging"));
	outFields->push(HX_CSTRING("_resizing"));
	outFields->push(HX_CSTRING("_resizable"));
	outFields->push(HX_CSTRING("_id"));
	super::__GetFields(outFields);
};

static ::String sStaticFields[] = {
	HX_CSTRING("BG_COLOR"),
	HX_CSTRING("TOP_COLOR"),
	HX_CSTRING("HEADER_ALPHA"),
	HX_CSTRING("WINDOW_AMOUNT"),
	String(null()) };

#if HXCPP_SCRIPTABLE
static hx::StorageInfo sMemberStorageInfo[] = {
	{hx::fsObject /*::flash::geom::Point*/ ,(int)offsetof(Window_obj,minSize),HX_CSTRING("minSize")},
	{hx::fsObject /*::flash::geom::Point*/ ,(int)offsetof(Window_obj,maxSize),HX_CSTRING("maxSize")},
	{hx::fsInt,(int)offsetof(Window_obj,_width),HX_CSTRING("_width")},
	{hx::fsInt,(int)offsetof(Window_obj,_height),HX_CSTRING("_height")},
	{hx::fsObject /*::flash::geom::Rectangle*/ ,(int)offsetof(Window_obj,_bounds),HX_CSTRING("_bounds")},
	{hx::fsObject /*::flash::display::Bitmap*/ ,(int)offsetof(Window_obj,_background),HX_CSTRING("_background")},
	{hx::fsObject /*::flash::display::Bitmap*/ ,(int)offsetof(Window_obj,_header),HX_CSTRING("_header")},
	{hx::fsObject /*::flash::display::Bitmap*/ ,(int)offsetof(Window_obj,_shadow),HX_CSTRING("_shadow")},
	{hx::fsObject /*::flash::text::TextField*/ ,(int)offsetof(Window_obj,_title),HX_CSTRING("_title")},
	{hx::fsObject /*::flash::display::Bitmap*/ ,(int)offsetof(Window_obj,_handle),HX_CSTRING("_handle")},
	{hx::fsObject /*::flixel::system::ui::FlxSystemButton*/ ,(int)offsetof(Window_obj,_closeButton),HX_CSTRING("_closeButton")},
	{hx::fsBool,(int)offsetof(Window_obj,_overHeader),HX_CSTRING("_overHeader")},
	{hx::fsBool,(int)offsetof(Window_obj,_overHandle),HX_CSTRING("_overHandle")},
	{hx::fsObject /*::flash::geom::Point*/ ,(int)offsetof(Window_obj,_drag),HX_CSTRING("_drag")},
	{hx::fsBool,(int)offsetof(Window_obj,_dragging),HX_CSTRING("_dragging")},
	{hx::fsBool,(int)offsetof(Window_obj,_resizing),HX_CSTRING("_resizing")},
	{hx::fsBool,(int)offsetof(Window_obj,_resizable),HX_CSTRING("_resizable")},
	{hx::fsInt,(int)offsetof(Window_obj,_id),HX_CSTRING("_id")},
	{ hx::fsUnknown, 0, null()}
};
#endif

static ::String sMemberFields[] = {
	HX_CSTRING("minSize"),
	HX_CSTRING("maxSize"),
	HX_CSTRING("_width"),
	HX_CSTRING("_height"),
	HX_CSTRING("_bounds"),
	HX_CSTRING("_background"),
	HX_CSTRING("_header"),
	HX_CSTRING("_shadow"),
	HX_CSTRING("_title"),
	HX_CSTRING("_handle"),
	HX_CSTRING("_closeButton"),
	HX_CSTRING("_overHeader"),
	HX_CSTRING("_overHandle"),
	HX_CSTRING("_drag"),
	HX_CSTRING("_dragging"),
	HX_CSTRING("_resizing"),
	HX_CSTRING("_resizable"),
	HX_CSTRING("_id"),
	HX_CSTRING("destroy"),
	HX_CSTRING("resize"),
	HX_CSTRING("reposition"),
	HX_CSTRING("updateBounds"),
	HX_CSTRING("toggleVisibility"),
	HX_CSTRING("init"),
	HX_CSTRING("onMouseMove"),
	HX_CSTRING("onMouseDown"),
	HX_CSTRING("onMouseUp"),
	HX_CSTRING("bound"),
	HX_CSTRING("updateSize"),
	HX_CSTRING("close"),
	String(null()) };

static void sMarkStatics(HX_MARK_PARAMS) {
	HX_MARK_MEMBER_NAME(Window_obj::__mClass,"__mClass");
	HX_MARK_MEMBER_NAME(Window_obj::BG_COLOR,"BG_COLOR");
	HX_MARK_MEMBER_NAME(Window_obj::TOP_COLOR,"TOP_COLOR");
	HX_MARK_MEMBER_NAME(Window_obj::HEADER_ALPHA,"HEADER_ALPHA");
	HX_MARK_MEMBER_NAME(Window_obj::WINDOW_AMOUNT,"WINDOW_AMOUNT");
};

#ifdef HXCPP_VISIT_ALLOCS
static void sVisitStatics(HX_VISIT_PARAMS) {
	HX_VISIT_MEMBER_NAME(Window_obj::__mClass,"__mClass");
	HX_VISIT_MEMBER_NAME(Window_obj::BG_COLOR,"BG_COLOR");
	HX_VISIT_MEMBER_NAME(Window_obj::TOP_COLOR,"TOP_COLOR");
	HX_VISIT_MEMBER_NAME(Window_obj::HEADER_ALPHA,"HEADER_ALPHA");
	HX_VISIT_MEMBER_NAME(Window_obj::WINDOW_AMOUNT,"WINDOW_AMOUNT");
};

#endif

Class Window_obj::__mClass;

void Window_obj::__register()
{
	hx::Static(__mClass) = hx::RegisterClass(HX_CSTRING("flixel.system.debug.Window"), hx::TCanCast< Window_obj> ,sStaticFields,sMemberFields,
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

void Window_obj::__boot()
{
	BG_COLOR= (int)-580952225;
	TOP_COLOR= (int)-1157627904;
	HEADER_ALPHA= 0.8;
	WINDOW_AMOUNT= (int)0;
}

} // end namespace flixel
} // end namespace system
} // end namespace debug
