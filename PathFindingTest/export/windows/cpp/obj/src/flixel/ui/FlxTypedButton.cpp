#include <hxcpp.h>

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
#ifndef INCLUDED_flixel_input_mouse_FlxMouse
#include <flixel/input/mouse/FlxMouse.h>
#endif
#ifndef INCLUDED_flixel_input_mouse_FlxMouseButton
#include <flixel/input/mouse/FlxMouseButton.h>
#endif
#ifndef INCLUDED_flixel_input_touch_FlxTouch
#include <flixel/input/touch/FlxTouch.h>
#endif
#ifndef INCLUDED_flixel_input_touch_FlxTouchManager
#include <flixel/input/touch/FlxTouchManager.h>
#endif
#ifndef INCLUDED_flixel_interfaces_IFlxDestroyable
#include <flixel/interfaces/IFlxDestroyable.h>
#endif
#ifndef INCLUDED_flixel_interfaces_IFlxInput
#include <flixel/interfaces/IFlxInput.h>
#endif
#ifndef INCLUDED_flixel_system_FlxSound
#include <flixel/system/FlxSound.h>
#endif
#ifndef INCLUDED_flixel_system_frontEnds_CameraFrontEnd
#include <flixel/system/frontEnds/CameraFrontEnd.h>
#endif
#ifndef INCLUDED_flixel_system_layer_frames_FlxFrame
#include <flixel/system/layer/frames/FlxFrame.h>
#endif
#ifndef INCLUDED_flixel_system_layer_frames_FlxSpriteFrames
#include <flixel/system/layer/frames/FlxSpriteFrames.h>
#endif
#ifndef INCLUDED_flixel_ui_FlxTypedButton
#include <flixel/ui/FlxTypedButton.h>
#endif
#ifndef INCLUDED_flixel_ui__FlxTypedButton_FlxButtonEvent
#include <flixel/ui/_FlxTypedButton/FlxButtonEvent.h>
#endif
#ifndef INCLUDED_flixel_ui__FlxTypedButton_GraphicButton
#include <flixel/ui/_FlxTypedButton/GraphicButton.h>
#endif
#ifndef INCLUDED_flixel_util_FlxPoint
#include <flixel/util/FlxPoint.h>
#endif
namespace flixel{
namespace ui{

Void FlxTypedButton_obj::__construct(hx::Null< Float >  __o_X,hx::Null< Float >  __o_Y,::String Label,Dynamic OnClick)
{
HX_STACK_FRAME("flixel.ui.FlxTypedButton","new",0xc7e33f04,"flixel.ui.FlxTypedButton.new","flixel/ui/FlxTypedButton.hx",17,0x752be24c)

HX_STACK_ARG(__o_X,"X")

HX_STACK_ARG(__o_Y,"Y")

HX_STACK_ARG(Label,"Label")

HX_STACK_ARG(OnClick,"OnClick")
Float X = __o_X.Default(0);
Float Y = __o_Y.Default(0);
{
	HX_STACK_LINE(70)
	this->_pressedMouse = false;
	HX_STACK_LINE(40)
	this->allowHighlightOnMobile = false;
	HX_STACK_LINE(35)
	this->allowSwiping = true;
	HX_STACK_LINE(82)
	super::__construct(X,Y,null());
	HX_STACK_LINE(84)
	this->loadGraphic(hx::ClassOf< ::flixel::ui::_FlxTypedButton::GraphicButton >(),true,false,(int)80,(int)20,null(),null());
	HX_STACK_LINE(86)
	this->onUp = ::flixel::ui::_FlxTypedButton::FlxButtonEvent_obj::__new(OnClick,null());
	HX_STACK_LINE(87)
	this->onDown = ::flixel::ui::_FlxTypedButton::FlxButtonEvent_obj::__new(null(),null());
	HX_STACK_LINE(88)
	this->onOver = ::flixel::ui::_FlxTypedButton::FlxButtonEvent_obj::__new(null(),null());
	HX_STACK_LINE(89)
	this->onOut = ::flixel::ui::_FlxTypedButton::FlxButtonEvent_obj::__new(null(),null());
	HX_STACK_LINE(91)
	this->labelAlphas = Array_obj< Float >::__new().Add(0.8).Add(1.0).Add(0.5);
	HX_STACK_LINE(92)
	::flixel::util::FlxPoint _g = ::flixel::util::FlxPoint_obj::__new(null(),null());		HX_STACK_VAR(_g,"_g");
	HX_STACK_LINE(92)
	::flixel::util::FlxPoint _g1 = ::flixel::util::FlxPoint_obj::__new(null(),null());		HX_STACK_VAR(_g1,"_g1");
	HX_STACK_LINE(92)
	this->labelOffsets = Array_obj< ::Dynamic >::__new().Add(_g).Add(_g1).Add(::flixel::util::FlxPoint_obj::__new((int)0,(int)1));
	HX_STACK_LINE(94)
	this->set_status((int)0);
	HX_STACK_LINE(97)
	this->scrollFactor->set(null(),null());
	HX_STACK_LINE(100)
	::flash::Lib_obj::get_current()->get_stage()->addEventListener(::flash::events::MouseEvent_obj::MOUSE_UP,this->onUpEventListener_dyn(),null(),null(),null());
}
;
	return null();
}

//FlxTypedButton_obj::~FlxTypedButton_obj() { }

Dynamic FlxTypedButton_obj::__CreateEmpty() { return  new FlxTypedButton_obj; }
hx::ObjectPtr< FlxTypedButton_obj > FlxTypedButton_obj::__new(hx::Null< Float >  __o_X,hx::Null< Float >  __o_Y,::String Label,Dynamic OnClick)
{  hx::ObjectPtr< FlxTypedButton_obj > result = new FlxTypedButton_obj();
	result->__construct(__o_X,__o_Y,Label,OnClick);
	return result;}

Dynamic FlxTypedButton_obj::__Create(hx::DynamicArray inArgs)
{  hx::ObjectPtr< FlxTypedButton_obj > result = new FlxTypedButton_obj();
	result->__construct(inArgs[0],inArgs[1],inArgs[2],inArgs[3]);
	return result;}

Void FlxTypedButton_obj::destroy( ){
{
		HX_STACK_FRAME("flixel.ui.FlxTypedButton","destroy",0xe11bbd9e,"flixel.ui.FlxTypedButton.destroy","flixel/ui/FlxTypedButton.hx",108,0x752be24c)
		HX_STACK_THIS(this)
		HX_STACK_LINE(109)
		this->label = ::flixel::FlxG_obj::safeDestroy(this->label);
		HX_STACK_LINE(111)
		this->onUp = ::flixel::FlxG_obj::safeDestroy(this->onUp);
		HX_STACK_LINE(112)
		this->onDown = ::flixel::FlxG_obj::safeDestroy(this->onDown);
		HX_STACK_LINE(113)
		this->onOver = ::flixel::FlxG_obj::safeDestroy(this->onOver);
		HX_STACK_LINE(114)
		this->onOut = ::flixel::FlxG_obj::safeDestroy(this->onOut);
		HX_STACK_LINE(116)
		this->labelOffsets = null();
		HX_STACK_LINE(117)
		this->labelAlphas = null();
		HX_STACK_LINE(118)
		this->_pressedTouch = null();
		HX_STACK_LINE(121)
		::flash::Lib_obj::get_current()->get_stage()->removeEventListener(::flash::events::MouseEvent_obj::MOUSE_UP,this->onUpEventListener_dyn(),null());
		HX_STACK_LINE(124)
		this->super::destroy();
	}
return null();
}


Void FlxTypedButton_obj::update( ){
{
		HX_STACK_FRAME("flixel.ui.FlxTypedButton","update",0xc4b5d5e5,"flixel.ui.FlxTypedButton.update","flixel/ui/FlxTypedButton.hx",131,0x752be24c)
		HX_STACK_THIS(this)
		HX_STACK_LINE(132)
		this->super::update();
		HX_STACK_LINE(134)
		if ((!(this->visible))){
			HX_STACK_LINE(136)
			return null();
		}
		HX_STACK_LINE(141)
		this->updateButton();
		HX_STACK_LINE(145)
		if (((this->label != null()))){
			HX_STACK_LINE(147)
			this->label->__Field(HX_CSTRING("set_x"),true)(this->x);
			HX_STACK_LINE(148)
			this->label->__Field(HX_CSTRING("set_y"),true)(this->y);
			HX_STACK_LINE(150)
			{
				HX_STACK_LINE(150)
				Dynamic _g = this->label;		HX_STACK_VAR(_g,"_g");
				HX_STACK_LINE(150)
				_g->__Field(HX_CSTRING("set_x"),true)((_g->__Field(HX_CSTRING("x"),true) + this->labelOffsets->__get(this->status).StaticCast< ::flixel::util::FlxPoint >()->x));
			}
			HX_STACK_LINE(151)
			{
				HX_STACK_LINE(151)
				Dynamic _g = this->label;		HX_STACK_VAR(_g,"_g");
				HX_STACK_LINE(151)
				_g->__Field(HX_CSTRING("set_y"),true)((_g->__Field(HX_CSTRING("y"),true) + this->labelOffsets->__get(this->status).StaticCast< ::flixel::util::FlxPoint >()->y));
			}
			HX_STACK_LINE(153)
			this->label->__FieldRef(HX_CSTRING("scrollFactor")) = this->scrollFactor;
		}
		HX_STACK_LINE(158)
		int nextFrame = this->status;		HX_STACK_VAR(nextFrame,"nextFrame");
		HX_STACK_LINE(168)
		this->set_frame(this->framesData->frames->__get(nextFrame).StaticCast< ::flixel::system::layer::frames::FlxFrame >());
	}
return null();
}


Void FlxTypedButton_obj::draw( ){
{
		HX_STACK_FRAME("flixel.ui.FlxTypedButton","draw",0x18618ce0,"flixel.ui.FlxTypedButton.draw","flixel/ui/FlxTypedButton.hx",175,0x752be24c)
		HX_STACK_THIS(this)
		HX_STACK_LINE(176)
		this->super::draw();
		HX_STACK_LINE(178)
		if (((this->label != null()))){
			HX_STACK_LINE(180)
			this->label->__FieldRef(HX_CSTRING("cameras")) = this->cameras;
			HX_STACK_LINE(181)
			this->label->__Field(HX_CSTRING("draw"),true)();
		}
	}
return null();
}


Void FlxTypedButton_obj::drawDebug( ){
{
		HX_STACK_FRAME("flixel.ui.FlxTypedButton","drawDebug",0xd8c08953,"flixel.ui.FlxTypedButton.drawDebug","flixel/ui/FlxTypedButton.hx",190,0x752be24c)
		HX_STACK_THIS(this)
		HX_STACK_LINE(191)
		this->super::drawDebug();
		HX_STACK_LINE(193)
		if (((this->label != null()))){
			HX_STACK_LINE(195)
			this->label->__Field(HX_CSTRING("drawDebug"),true)();
		}
	}
return null();
}


Void FlxTypedButton_obj::updateButton( ){
{
		HX_STACK_FRAME("flixel.ui.FlxTypedButton","updateButton",0x576ba5b7,"flixel.ui.FlxTypedButton.updateButton","flixel/ui/FlxTypedButton.hx",205,0x752be24c)
		HX_STACK_THIS(this)
		HX_STACK_LINE(206)
		if (((this->cameras == null()))){
			HX_STACK_LINE(208)
			this->cameras = ::flixel::FlxG_obj::cameras->list;
		}
		HX_STACK_LINE(212)
		bool overlapFound = false;		HX_STACK_VAR(overlapFound,"overlapFound");
		HX_STACK_LINE(215)
		{
			HX_STACK_LINE(215)
			int _g = (int)0;		HX_STACK_VAR(_g,"_g");
			HX_STACK_LINE(215)
			Array< ::Dynamic > _g1 = this->cameras;		HX_STACK_VAR(_g1,"_g1");
			HX_STACK_LINE(215)
			while(((_g < _g1->length))){
				HX_STACK_LINE(215)
				::flixel::FlxCamera camera = _g1->__get(_g).StaticCast< ::flixel::FlxCamera >();		HX_STACK_VAR(camera,"camera");
				HX_STACK_LINE(215)
				++(_g);
				HX_STACK_LINE(218)
				::flixel::FlxG_obj::mouse->getWorldPosition(camera,this->_point);
				HX_STACK_LINE(220)
				if ((this->overlapsPoint(this->_point,true,camera))){
					HX_STACK_LINE(222)
					overlapFound = true;
					struct _Function_4_1{
						inline static bool Block( ){
							HX_STACK_FRAME("*","closure",0x5bdab937,"*.closure","flixel/ui/FlxTypedButton.hx",223,0x752be24c)
							{
								HX_STACK_LINE(223)
								::flixel::input::mouse::FlxMouseButton _this = ::flixel::FlxG_obj::mouse->_leftButton;		HX_STACK_VAR(_this,"_this");
								HX_STACK_LINE(223)
								return (bool((_this->current == (int)2)) || bool((_this->current == (int)-2)));
							}
							return null();
						}
					};
					HX_STACK_LINE(223)
					this->updateStatus(true,_Function_4_1::Block(),(::flixel::FlxG_obj::mouse->_leftButton->current > (int)0),null());
					HX_STACK_LINE(224)
					break;
				}
				HX_STACK_LINE(229)
				{
					HX_STACK_LINE(229)
					int _g2 = (int)0;		HX_STACK_VAR(_g2,"_g2");
					HX_STACK_LINE(229)
					Array< ::Dynamic > _g3 = ::flixel::FlxG_obj::touches->list;		HX_STACK_VAR(_g3,"_g3");
					HX_STACK_LINE(229)
					while(((_g2 < _g3->length))){
						HX_STACK_LINE(229)
						::flixel::input::touch::FlxTouch touch = _g3->__get(_g2).StaticCast< ::flixel::input::touch::FlxTouch >();		HX_STACK_VAR(touch,"touch");
						HX_STACK_LINE(229)
						++(_g2);
						HX_STACK_LINE(231)
						touch->getWorldPosition(camera,this->_point);
						HX_STACK_LINE(233)
						if ((this->overlapsPoint(this->_point,true,camera))){
							HX_STACK_LINE(235)
							overlapFound = true;
							HX_STACK_LINE(236)
							this->updateStatus(true,(touch->_current == (int)2),(touch->_current > (int)0),touch);
							HX_STACK_LINE(237)
							break;
						}
					}
				}
			}
		}
		HX_STACK_LINE(243)
		if ((!(overlapFound))){
			HX_STACK_LINE(245)
			this->updateStatus(false,false,false,null());
		}
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC0(FlxTypedButton_obj,updateButton,(void))

Void FlxTypedButton_obj::updateStatus( bool Overlap,bool JustPressed,bool Pressed,::flixel::input::touch::FlxTouch Touch){
{
		HX_STACK_FRAME("flixel.ui.FlxTypedButton","updateStatus",0x83872af7,"flixel.ui.FlxTypedButton.updateStatus","flixel/ui/FlxTypedButton.hx",258,0x752be24c)
		HX_STACK_THIS(this)
		HX_STACK_ARG(Overlap,"Overlap")
		HX_STACK_ARG(JustPressed,"JustPressed")
		HX_STACK_ARG(Pressed,"Pressed")
		HX_STACK_ARG(Touch,"Touch")
		HX_STACK_LINE(259)
		if ((Overlap)){
			HX_STACK_LINE(261)
			if ((JustPressed)){
				HX_STACK_LINE(263)
				this->_pressedTouch = Touch;
				HX_STACK_LINE(264)
				if (((Touch == null()))){
					HX_STACK_LINE(266)
					this->_pressedMouse = true;
				}
				HX_STACK_LINE(268)
				this->onDownHandler();
			}
			else{
				HX_STACK_LINE(270)
				if (((this->status == (int)0))){
					HX_STACK_LINE(273)
					if (((bool(this->allowSwiping) && bool(Pressed)))){
						HX_STACK_LINE(275)
						this->onDownHandler();
					}
					else{
						HX_STACK_LINE(279)
						this->onOverHandler();
					}
				}
			}
		}
		else{
			HX_STACK_LINE(283)
			if (((this->status != (int)0))){
				HX_STACK_LINE(285)
				this->onOutHandler();
			}
		}
		HX_STACK_LINE(290)
		if (((bool((this->_pressedTouch != null())) && bool((this->_pressedTouch->_current == (int)-1))))){
			HX_STACK_LINE(292)
			this->onUpHandler();
		}
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC4(FlxTypedButton_obj,updateStatus,(void))

int FlxTypedButton_obj::set_status( int Value){
	HX_STACK_FRAME("flixel.ui.FlxTypedButton","set_status",0x23ac634b,"flixel.ui.FlxTypedButton.set_status","flixel/ui/FlxTypedButton.hx",298,0x752be24c)
	HX_STACK_THIS(this)
	HX_STACK_ARG(Value,"Value")
	HX_STACK_LINE(299)
	if (((bool((this->labelAlphas->length > Value)) && bool((this->label != null()))))){
		HX_STACK_LINE(301)
		this->label->__Field(HX_CSTRING("set_alpha"),true)((this->alpha * this->labelAlphas->__get(Value)));
	}
	HX_STACK_LINE(303)
	return this->status = Value;
}


HX_DEFINE_DYNAMIC_FUNC1(FlxTypedButton_obj,set_status,return )

Void FlxTypedButton_obj::onUpEventListener( ::flash::events::MouseEvent E){
{
		HX_STACK_FRAME("flixel.ui.FlxTypedButton","onUpEventListener",0x0f960298,"flixel.ui.FlxTypedButton.onUpEventListener","flixel/ui/FlxTypedButton.hx",313,0x752be24c)
		HX_STACK_THIS(this)
		HX_STACK_ARG(E,"E")
		HX_STACK_LINE(313)
		if (((bool((bool((bool(this->visible) && bool(this->exists))) && bool(this->active))) && bool((this->status == (int)2))))){
			HX_STACK_LINE(315)
			this->onUpHandler();
		}
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC1(FlxTypedButton_obj,onUpEventListener,(void))

Void FlxTypedButton_obj::onUpHandler( ){
{
		HX_STACK_FRAME("flixel.ui.FlxTypedButton","onUpHandler",0xf0255834,"flixel.ui.FlxTypedButton.onUpHandler","flixel/ui/FlxTypedButton.hx",324,0x752be24c)
		HX_STACK_THIS(this)
		HX_STACK_LINE(325)
		this->set_status((int)0);
		HX_STACK_LINE(326)
		this->_pressedMouse = false;
		HX_STACK_LINE(327)
		this->_pressedTouch = null();
		HX_STACK_LINE(329)
		{
			HX_STACK_LINE(329)
			::flixel::ui::_FlxTypedButton::FlxButtonEvent _this = this->onUp;		HX_STACK_VAR(_this,"_this");
			HX_STACK_LINE(329)
			if (((_this->callback != null()))){
				HX_STACK_LINE(329)
				_this->callback();
			}
			HX_STACK_LINE(329)
			if (((_this->sound != null()))){
				HX_STACK_LINE(329)
				_this->sound->play(true);
			}
		}
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC0(FlxTypedButton_obj,onUpHandler,(void))

Void FlxTypedButton_obj::onDownHandler( ){
{
		HX_STACK_FRAME("flixel.ui.FlxTypedButton","onDownHandler",0x6003504d,"flixel.ui.FlxTypedButton.onDownHandler","flixel/ui/FlxTypedButton.hx",336,0x752be24c)
		HX_STACK_THIS(this)
		HX_STACK_LINE(337)
		this->set_status((int)2);
		HX_STACK_LINE(339)
		{
			HX_STACK_LINE(339)
			::flixel::ui::_FlxTypedButton::FlxButtonEvent _this = this->onDown;		HX_STACK_VAR(_this,"_this");
			HX_STACK_LINE(339)
			if (((_this->callback != null()))){
				HX_STACK_LINE(339)
				_this->callback();
			}
			HX_STACK_LINE(339)
			if (((_this->sound != null()))){
				HX_STACK_LINE(339)
				_this->sound->play(true);
			}
		}
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC0(FlxTypedButton_obj,onDownHandler,(void))

Void FlxTypedButton_obj::onOverHandler( ){
{
		HX_STACK_FRAME("flixel.ui.FlxTypedButton","onOverHandler",0x3b6b999b,"flixel.ui.FlxTypedButton.onOverHandler","flixel/ui/FlxTypedButton.hx",346,0x752be24c)
		HX_STACK_THIS(this)
		HX_STACK_LINE(347)
		this->set_status((int)1);
		HX_STACK_LINE(349)
		{
			HX_STACK_LINE(349)
			::flixel::ui::_FlxTypedButton::FlxButtonEvent _this = this->onOver;		HX_STACK_VAR(_this,"_this");
			HX_STACK_LINE(349)
			if (((_this->callback != null()))){
				HX_STACK_LINE(349)
				_this->callback();
			}
			HX_STACK_LINE(349)
			if (((_this->sound != null()))){
				HX_STACK_LINE(349)
				_this->sound->play(true);
			}
		}
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC0(FlxTypedButton_obj,onOverHandler,(void))

Void FlxTypedButton_obj::onOutHandler( ){
{
		HX_STACK_FRAME("flixel.ui.FlxTypedButton","onOutHandler",0x1cacc3b7,"flixel.ui.FlxTypedButton.onOutHandler","flixel/ui/FlxTypedButton.hx",356,0x752be24c)
		HX_STACK_THIS(this)
		HX_STACK_LINE(357)
		this->set_status((int)0);
		HX_STACK_LINE(359)
		{
			HX_STACK_LINE(359)
			::flixel::ui::_FlxTypedButton::FlxButtonEvent _this = this->onOut;		HX_STACK_VAR(_this,"_this");
			HX_STACK_LINE(359)
			if (((_this->callback != null()))){
				HX_STACK_LINE(359)
				_this->callback();
			}
			HX_STACK_LINE(359)
			if (((_this->sound != null()))){
				HX_STACK_LINE(359)
				_this->sound->play(true);
			}
		}
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC0(FlxTypedButton_obj,onOutHandler,(void))


FlxTypedButton_obj::FlxTypedButton_obj()
{
}

void FlxTypedButton_obj::__Mark(HX_MARK_PARAMS)
{
	HX_MARK_BEGIN_CLASS(FlxTypedButton);
	HX_MARK_MEMBER_NAME(label,"label");
	HX_MARK_MEMBER_NAME(labelOffsets,"labelOffsets");
	HX_MARK_MEMBER_NAME(labelAlphas,"labelAlphas");
	HX_MARK_MEMBER_NAME(allowSwiping,"allowSwiping");
	HX_MARK_MEMBER_NAME(allowHighlightOnMobile,"allowHighlightOnMobile");
	HX_MARK_MEMBER_NAME(status,"status");
	HX_MARK_MEMBER_NAME(onUp,"onUp");
	HX_MARK_MEMBER_NAME(onDown,"onDown");
	HX_MARK_MEMBER_NAME(onOver,"onOver");
	HX_MARK_MEMBER_NAME(onOut,"onOut");
	HX_MARK_MEMBER_NAME(_pressedTouch,"_pressedTouch");
	HX_MARK_MEMBER_NAME(_pressedMouse,"_pressedMouse");
	::flixel::FlxSprite_obj::__Mark(HX_MARK_ARG);
	HX_MARK_END_CLASS();
}

void FlxTypedButton_obj::__Visit(HX_VISIT_PARAMS)
{
	HX_VISIT_MEMBER_NAME(label,"label");
	HX_VISIT_MEMBER_NAME(labelOffsets,"labelOffsets");
	HX_VISIT_MEMBER_NAME(labelAlphas,"labelAlphas");
	HX_VISIT_MEMBER_NAME(allowSwiping,"allowSwiping");
	HX_VISIT_MEMBER_NAME(allowHighlightOnMobile,"allowHighlightOnMobile");
	HX_VISIT_MEMBER_NAME(status,"status");
	HX_VISIT_MEMBER_NAME(onUp,"onUp");
	HX_VISIT_MEMBER_NAME(onDown,"onDown");
	HX_VISIT_MEMBER_NAME(onOver,"onOver");
	HX_VISIT_MEMBER_NAME(onOut,"onOut");
	HX_VISIT_MEMBER_NAME(_pressedTouch,"_pressedTouch");
	HX_VISIT_MEMBER_NAME(_pressedMouse,"_pressedMouse");
	::flixel::FlxSprite_obj::__Visit(HX_VISIT_ARG);
}

Dynamic FlxTypedButton_obj::__Field(const ::String &inName,bool inCallProp)
{
	switch(inName.length) {
	case 4:
		if (HX_FIELD_EQ(inName,"onUp") ) { return onUp; }
		if (HX_FIELD_EQ(inName,"draw") ) { return draw_dyn(); }
		break;
	case 5:
		if (HX_FIELD_EQ(inName,"label") ) { return label; }
		if (HX_FIELD_EQ(inName,"onOut") ) { return onOut; }
		break;
	case 6:
		if (HX_FIELD_EQ(inName,"status") ) { return status; }
		if (HX_FIELD_EQ(inName,"onDown") ) { return onDown; }
		if (HX_FIELD_EQ(inName,"onOver") ) { return onOver; }
		if (HX_FIELD_EQ(inName,"update") ) { return update_dyn(); }
		break;
	case 7:
		if (HX_FIELD_EQ(inName,"destroy") ) { return destroy_dyn(); }
		break;
	case 9:
		if (HX_FIELD_EQ(inName,"drawDebug") ) { return drawDebug_dyn(); }
		break;
	case 10:
		if (HX_FIELD_EQ(inName,"set_status") ) { return set_status_dyn(); }
		break;
	case 11:
		if (HX_FIELD_EQ(inName,"labelAlphas") ) { return labelAlphas; }
		if (HX_FIELD_EQ(inName,"onUpHandler") ) { return onUpHandler_dyn(); }
		break;
	case 12:
		if (HX_FIELD_EQ(inName,"labelOffsets") ) { return labelOffsets; }
		if (HX_FIELD_EQ(inName,"allowSwiping") ) { return allowSwiping; }
		if (HX_FIELD_EQ(inName,"updateButton") ) { return updateButton_dyn(); }
		if (HX_FIELD_EQ(inName,"updateStatus") ) { return updateStatus_dyn(); }
		if (HX_FIELD_EQ(inName,"onOutHandler") ) { return onOutHandler_dyn(); }
		break;
	case 13:
		if (HX_FIELD_EQ(inName,"_pressedTouch") ) { return _pressedTouch; }
		if (HX_FIELD_EQ(inName,"_pressedMouse") ) { return _pressedMouse; }
		if (HX_FIELD_EQ(inName,"onDownHandler") ) { return onDownHandler_dyn(); }
		if (HX_FIELD_EQ(inName,"onOverHandler") ) { return onOverHandler_dyn(); }
		break;
	case 17:
		if (HX_FIELD_EQ(inName,"onUpEventListener") ) { return onUpEventListener_dyn(); }
		break;
	case 22:
		if (HX_FIELD_EQ(inName,"allowHighlightOnMobile") ) { return allowHighlightOnMobile; }
	}
	return super::__Field(inName,inCallProp);
}

Dynamic FlxTypedButton_obj::__SetField(const ::String &inName,const Dynamic &inValue,bool inCallProp)
{
	switch(inName.length) {
	case 4:
		if (HX_FIELD_EQ(inName,"onUp") ) { onUp=inValue.Cast< ::flixel::ui::_FlxTypedButton::FlxButtonEvent >(); return inValue; }
		break;
	case 5:
		if (HX_FIELD_EQ(inName,"label") ) { label=inValue.Cast< Dynamic >(); return inValue; }
		if (HX_FIELD_EQ(inName,"onOut") ) { onOut=inValue.Cast< ::flixel::ui::_FlxTypedButton::FlxButtonEvent >(); return inValue; }
		break;
	case 6:
		if (HX_FIELD_EQ(inName,"status") ) { if (inCallProp) return set_status(inValue);status=inValue.Cast< int >(); return inValue; }
		if (HX_FIELD_EQ(inName,"onDown") ) { onDown=inValue.Cast< ::flixel::ui::_FlxTypedButton::FlxButtonEvent >(); return inValue; }
		if (HX_FIELD_EQ(inName,"onOver") ) { onOver=inValue.Cast< ::flixel::ui::_FlxTypedButton::FlxButtonEvent >(); return inValue; }
		break;
	case 11:
		if (HX_FIELD_EQ(inName,"labelAlphas") ) { labelAlphas=inValue.Cast< Array< Float > >(); return inValue; }
		break;
	case 12:
		if (HX_FIELD_EQ(inName,"labelOffsets") ) { labelOffsets=inValue.Cast< Array< ::Dynamic > >(); return inValue; }
		if (HX_FIELD_EQ(inName,"allowSwiping") ) { allowSwiping=inValue.Cast< bool >(); return inValue; }
		break;
	case 13:
		if (HX_FIELD_EQ(inName,"_pressedTouch") ) { _pressedTouch=inValue.Cast< ::flixel::input::touch::FlxTouch >(); return inValue; }
		if (HX_FIELD_EQ(inName,"_pressedMouse") ) { _pressedMouse=inValue.Cast< bool >(); return inValue; }
		break;
	case 22:
		if (HX_FIELD_EQ(inName,"allowHighlightOnMobile") ) { allowHighlightOnMobile=inValue.Cast< bool >(); return inValue; }
	}
	return super::__SetField(inName,inValue,inCallProp);
}

void FlxTypedButton_obj::__GetFields(Array< ::String> &outFields)
{
	outFields->push(HX_CSTRING("label"));
	outFields->push(HX_CSTRING("labelOffsets"));
	outFields->push(HX_CSTRING("labelAlphas"));
	outFields->push(HX_CSTRING("allowSwiping"));
	outFields->push(HX_CSTRING("allowHighlightOnMobile"));
	outFields->push(HX_CSTRING("status"));
	outFields->push(HX_CSTRING("onUp"));
	outFields->push(HX_CSTRING("onDown"));
	outFields->push(HX_CSTRING("onOver"));
	outFields->push(HX_CSTRING("onOut"));
	outFields->push(HX_CSTRING("_pressedTouch"));
	outFields->push(HX_CSTRING("_pressedMouse"));
	super::__GetFields(outFields);
};

static ::String sStaticFields[] = {
	String(null()) };

#if HXCPP_SCRIPTABLE
static hx::StorageInfo sMemberStorageInfo[] = {
	{hx::fsObject /*Dynamic*/ ,(int)offsetof(FlxTypedButton_obj,label),HX_CSTRING("label")},
	{hx::fsObject /*Array< ::Dynamic >*/ ,(int)offsetof(FlxTypedButton_obj,labelOffsets),HX_CSTRING("labelOffsets")},
	{hx::fsObject /*Array< Float >*/ ,(int)offsetof(FlxTypedButton_obj,labelAlphas),HX_CSTRING("labelAlphas")},
	{hx::fsBool,(int)offsetof(FlxTypedButton_obj,allowSwiping),HX_CSTRING("allowSwiping")},
	{hx::fsBool,(int)offsetof(FlxTypedButton_obj,allowHighlightOnMobile),HX_CSTRING("allowHighlightOnMobile")},
	{hx::fsInt,(int)offsetof(FlxTypedButton_obj,status),HX_CSTRING("status")},
	{hx::fsObject /*::flixel::ui::_FlxTypedButton::FlxButtonEvent*/ ,(int)offsetof(FlxTypedButton_obj,onUp),HX_CSTRING("onUp")},
	{hx::fsObject /*::flixel::ui::_FlxTypedButton::FlxButtonEvent*/ ,(int)offsetof(FlxTypedButton_obj,onDown),HX_CSTRING("onDown")},
	{hx::fsObject /*::flixel::ui::_FlxTypedButton::FlxButtonEvent*/ ,(int)offsetof(FlxTypedButton_obj,onOver),HX_CSTRING("onOver")},
	{hx::fsObject /*::flixel::ui::_FlxTypedButton::FlxButtonEvent*/ ,(int)offsetof(FlxTypedButton_obj,onOut),HX_CSTRING("onOut")},
	{hx::fsObject /*::flixel::input::touch::FlxTouch*/ ,(int)offsetof(FlxTypedButton_obj,_pressedTouch),HX_CSTRING("_pressedTouch")},
	{hx::fsBool,(int)offsetof(FlxTypedButton_obj,_pressedMouse),HX_CSTRING("_pressedMouse")},
	{ hx::fsUnknown, 0, null()}
};
#endif

static ::String sMemberFields[] = {
	HX_CSTRING("label"),
	HX_CSTRING("labelOffsets"),
	HX_CSTRING("labelAlphas"),
	HX_CSTRING("allowSwiping"),
	HX_CSTRING("allowHighlightOnMobile"),
	HX_CSTRING("status"),
	HX_CSTRING("onUp"),
	HX_CSTRING("onDown"),
	HX_CSTRING("onOver"),
	HX_CSTRING("onOut"),
	HX_CSTRING("_pressedTouch"),
	HX_CSTRING("_pressedMouse"),
	HX_CSTRING("destroy"),
	HX_CSTRING("update"),
	HX_CSTRING("draw"),
	HX_CSTRING("drawDebug"),
	HX_CSTRING("updateButton"),
	HX_CSTRING("updateStatus"),
	HX_CSTRING("set_status"),
	HX_CSTRING("onUpEventListener"),
	HX_CSTRING("onUpHandler"),
	HX_CSTRING("onDownHandler"),
	HX_CSTRING("onOverHandler"),
	HX_CSTRING("onOutHandler"),
	String(null()) };

static void sMarkStatics(HX_MARK_PARAMS) {
	HX_MARK_MEMBER_NAME(FlxTypedButton_obj::__mClass,"__mClass");
};

#ifdef HXCPP_VISIT_ALLOCS
static void sVisitStatics(HX_VISIT_PARAMS) {
	HX_VISIT_MEMBER_NAME(FlxTypedButton_obj::__mClass,"__mClass");
};

#endif

Class FlxTypedButton_obj::__mClass;

void FlxTypedButton_obj::__register()
{
	hx::Static(__mClass) = hx::RegisterClass(HX_CSTRING("flixel.ui.FlxTypedButton"), hx::TCanCast< FlxTypedButton_obj> ,sStaticFields,sMemberFields,
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

void FlxTypedButton_obj::__boot()
{
}

} // end namespace flixel
} // end namespace ui
