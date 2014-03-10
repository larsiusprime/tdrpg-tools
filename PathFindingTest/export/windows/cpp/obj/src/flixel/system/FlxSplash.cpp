#include <hxcpp.h>

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
#ifndef INCLUDED_flixel_FlxBasic
#include <flixel/FlxBasic.h>
#endif
#ifndef INCLUDED_flixel_FlxG
#include <flixel/FlxG.h>
#endif
#ifndef INCLUDED_flixel_FlxGame
#include <flixel/FlxGame.h>
#endif
#ifndef INCLUDED_flixel_FlxState
#include <flixel/FlxState.h>
#endif
#ifndef INCLUDED_flixel_group_FlxGroup
#include <flixel/group/FlxGroup.h>
#endif
#ifndef INCLUDED_flixel_group_FlxTypedGroup
#include <flixel/group/FlxTypedGroup.h>
#endif
#ifndef INCLUDED_flixel_input_keyboard_FlxKeyboard
#include <flixel/input/keyboard/FlxKeyboard.h>
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
#ifndef INCLUDED_flixel_system_FlxSplash
#include <flixel/system/FlxSplash.h>
#endif
#ifndef INCLUDED_flixel_system_frontEnds_CameraFrontEnd
#include <flixel/system/frontEnds/CameraFrontEnd.h>
#endif
#ifndef INCLUDED_flixel_tweens_FlxEase
#include <flixel/tweens/FlxEase.h>
#endif
#ifndef INCLUDED_flixel_tweens_FlxTween
#include <flixel/tweens/FlxTween.h>
#endif
#ifndef INCLUDED_flixel_util_FlxTimer
#include <flixel/util/FlxTimer.h>
#endif
namespace flixel{
namespace system{

Void FlxSplash_obj::__construct(::Class NextState)
{
HX_STACK_FRAME("flixel.system.FlxSplash","new",0x887e165e,"flixel.system.FlxSplash.new","flixel/system/FlxSplash.hx",21,0xa5de80f2)

HX_STACK_ARG(NextState,"NextState")
{
	HX_STACK_LINE(32)
	this->_curPart = (int)0;
	HX_STACK_LINE(39)
	this->_nextState = NextState;
	HX_STACK_LINE(40)
	super::__construct(null());
}
;
	return null();
}

//FlxSplash_obj::~FlxSplash_obj() { }

Dynamic FlxSplash_obj::__CreateEmpty() { return  new FlxSplash_obj; }
hx::ObjectPtr< FlxSplash_obj > FlxSplash_obj::__new(::Class NextState)
{  hx::ObjectPtr< FlxSplash_obj > result = new FlxSplash_obj();
	result->__construct(NextState);
	return result;}

Dynamic FlxSplash_obj::__Create(hx::DynamicArray inArgs)
{  hx::ObjectPtr< FlxSplash_obj > result = new FlxSplash_obj();
	result->__construct(inArgs[0]);
	return result;}

Void FlxSplash_obj::destroy( ){
{
		HX_STACK_FRAME("flixel.system.FlxSplash","destroy",0xef7e49f8,"flixel.system.FlxSplash.destroy","flixel/system/FlxSplash.hx",44,0xa5de80f2)
		HX_STACK_THIS(this)
		HX_STACK_LINE(45)
		this->_nextState = null();
		HX_STACK_LINE(46)
		this->_sprite = null();
		HX_STACK_LINE(47)
		this->_gfx = null();
		HX_STACK_LINE(48)
		this->_text = null();
		HX_STACK_LINE(49)
		this->_times = null();
		HX_STACK_LINE(50)
		this->_colors = null();
		HX_STACK_LINE(51)
		this->_functions = null();
		HX_STACK_LINE(52)
		this->super::destroy();
	}
return null();
}


Void FlxSplash_obj::onResize( int Width,int Height){
{
		HX_STACK_FRAME("flixel.system.FlxSplash","onResize",0xb64991b5,"flixel.system.FlxSplash.onResize","flixel/system/FlxSplash.hx",56,0xa5de80f2)
		HX_STACK_THIS(this)
		HX_STACK_ARG(Width,"Width")
		HX_STACK_ARG(Height,"Height")
		HX_STACK_LINE(57)
		this->super::onResize(Width,Height);
		HX_STACK_LINE(59)
		this->_sprite->set_x((Float(Width) / Float((int)2)));
		HX_STACK_LINE(60)
		this->_sprite->set_y(((Float(Height) / Float((int)2)) - ((int)20 * ::flixel::FlxG_obj::game->get_scaleY())));
		HX_STACK_LINE(62)
		this->_text->set_width((Float(Width) / Float(::flixel::FlxG_obj::game->get_scaleX())));
		HX_STACK_LINE(63)
		this->_text->set_x((int)0);
		HX_STACK_LINE(64)
		Float _g = this->_sprite->get_y();		HX_STACK_VAR(_g,"_g");
		HX_STACK_LINE(64)
		this->_text->set_y((_g + ((int)80 * ::flixel::FlxG_obj::game->get_scaleY())));
		HX_STACK_LINE(66)
		this->_sprite->set_scaleX(this->_text->set_scaleX(::flixel::FlxG_obj::game->get_scaleX()));
		HX_STACK_LINE(67)
		this->_sprite->set_scaleY(this->_text->set_scaleY(::flixel::FlxG_obj::game->get_scaleY()));
	}
return null();
}


Void FlxSplash_obj::create( ){
{
		HX_STACK_FRAME("flixel.system.FlxSplash","create",0x2dc273be,"flixel.system.FlxSplash.create","flixel/system/FlxSplash.hx",71,0xa5de80f2)
		HX_STACK_THIS(this)
		HX_STACK_LINE(72)
		this->_cachedBgColor = ::flixel::FlxG_obj::cameras->get_bgColor();
		HX_STACK_LINE(73)
		::flixel::FlxG_obj::cameras->set_bgColor((int)-16777216);
		HX_STACK_LINE(76)
		this->_cachedTimestep = ::flixel::FlxG_obj::fixedTimestep;
		HX_STACK_LINE(77)
		::flixel::FlxG_obj::fixedTimestep = false;
		HX_STACK_LINE(79)
		this->_cachedAutoPause = ::flixel::FlxG_obj::autoPause;
		HX_STACK_LINE(80)
		::flixel::FlxG_obj::autoPause = false;
		HX_STACK_LINE(83)
		::flixel::FlxG_obj::keys->enabled = false;
		HX_STACK_LINE(86)
		this->_times = Array_obj< Float >::__new().Add(0.041).Add(0.184).Add(0.334).Add(0.495).Add(0.636);
		HX_STACK_LINE(87)
		this->_colors = Array_obj< int >::__new().Add((int)47394).Add((int)16761138).Add((int)16066382).Add((int)3555839).Add((int)314875);
		HX_STACK_LINE(88)
		this->_functions = Dynamic( Array_obj<Dynamic>::__new().Add(this->drawGreen_dyn()).Add(this->drawYellow_dyn()).Add(this->drawRed_dyn()).Add(this->drawBlue_dyn()).Add(this->drawLightBlue_dyn()));
		HX_STACK_LINE(90)
		{
			HX_STACK_LINE(90)
			int _g = (int)0;		HX_STACK_VAR(_g,"_g");
			HX_STACK_LINE(90)
			Array< Float > _g1 = this->_times;		HX_STACK_VAR(_g1,"_g1");
			HX_STACK_LINE(90)
			while(((_g < _g1->length))){
				HX_STACK_LINE(90)
				Float time = _g1->__get(_g);		HX_STACK_VAR(time,"time");
				HX_STACK_LINE(90)
				++(_g);
				HX_STACK_LINE(92)
				::flixel::util::FlxTimer_obj::start(time,this->timerCallback_dyn(),null());
			}
		}
		HX_STACK_LINE(95)
		int stageWidth = ::flash::Lib_obj::get_current()->get_stage()->get_stageWidth();		HX_STACK_VAR(stageWidth,"stageWidth");
		HX_STACK_LINE(96)
		int stageHeight = ::flash::Lib_obj::get_current()->get_stage()->get_stageHeight();		HX_STACK_VAR(stageHeight,"stageHeight");
		HX_STACK_LINE(98)
		this->_sprite = ::flash::display::Sprite_obj::__new();
		HX_STACK_LINE(99)
		::flash::Lib_obj::get_current()->get_stage()->addChild(this->_sprite);
		HX_STACK_LINE(100)
		this->_gfx = this->_sprite->get_graphics();
		HX_STACK_LINE(102)
		this->_text = ::flash::text::TextField_obj::__new();
		HX_STACK_LINE(103)
		this->_text->set_selectable(false);
		HX_STACK_LINE(104)
		this->_text->set_embedFonts(true);
		HX_STACK_LINE(105)
		::flash::text::TextFormat dtf = ::flash::text::TextFormat_obj::__new(::flixel::system::FlxAssets_obj::FONT_DEFAULT,(int)16,(int)16777215,null(),null(),null(),null(),null(),null(),null(),null(),null(),null());		HX_STACK_VAR(dtf,"dtf");
		HX_STACK_LINE(106)
		dtf->align = ::flash::text::TextFormatAlign_obj::CENTER;
		HX_STACK_LINE(107)
		this->_text->set_defaultTextFormat(dtf);
		HX_STACK_LINE(108)
		this->_text->set_text(HX_CSTRING("HaxeFlixel"));
		HX_STACK_LINE(109)
		::flash::Lib_obj::get_current()->get_stage()->addChild(this->_text);
		HX_STACK_LINE(111)
		this->onResize(stageWidth,stageHeight);
	}
return null();
}


Void FlxSplash_obj::timerCallback( ::flixel::util::FlxTimer Timer){
{
		HX_STACK_FRAME("flixel.system.FlxSplash","timerCallback",0x874bd228,"flixel.system.FlxSplash.timerCallback","flixel/system/FlxSplash.hx",119,0xa5de80f2)
		HX_STACK_THIS(this)
		HX_STACK_ARG(Timer,"Timer")
		HX_STACK_LINE(120)
		this->_functions->__GetItem(this->_curPart)().Cast< Void >();
		HX_STACK_LINE(121)
		this->_text->set_textColor(this->_colors->__get(this->_curPart));
		HX_STACK_LINE(122)
		this->_text->set_text(HX_CSTRING("HaxeFlixel"));
		HX_STACK_LINE(123)
		(this->_curPart)++;
		HX_STACK_LINE(125)
		if (((this->_curPart == (int)5))){
			struct _Function_2_1{
				inline static Dynamic Block( ){
					HX_STACK_FRAME("*","closure",0x5bdab937,"*.closure","flixel/system/FlxSplash.hx",128,0xa5de80f2)
					{
						hx::Anon __result = hx::Anon_obj::Create();
						__result->Add(HX_CSTRING("alpha") , (int)0,false);
						return __result;
					}
					return null();
				}
			};
			HX_STACK_LINE(128)
			Dynamic _g = _Function_2_1::Block();		HX_STACK_VAR(_g,"_g");
			struct _Function_2_2{
				inline static Dynamic Block( ::flixel::system::FlxSplash_obj *__this){
					HX_STACK_FRAME("*","closure",0x5bdab937,"*.closure","flixel/system/FlxSplash.hx",128,0xa5de80f2)
					{
						hx::Anon __result = hx::Anon_obj::Create();
						__result->Add(HX_CSTRING("ease") , ::flixel::tweens::FlxEase_obj::quadOut_dyn(),false);
						__result->Add(HX_CSTRING("complete") , __this->onComplete_dyn(),false);
						return __result;
					}
					return null();
				}
			};
			HX_STACK_LINE(128)
			::flixel::tweens::FlxTween_obj::multiVar(this->_sprite,_g,3.0,_Function_2_2::Block(this));
			struct _Function_2_3{
				inline static Dynamic Block( ){
					HX_STACK_FRAME("*","closure",0x5bdab937,"*.closure","flixel/system/FlxSplash.hx",129,0xa5de80f2)
					{
						hx::Anon __result = hx::Anon_obj::Create();
						__result->Add(HX_CSTRING("alpha") , (int)0,false);
						return __result;
					}
					return null();
				}
			};
			HX_STACK_LINE(129)
			Dynamic _g1 = _Function_2_3::Block();		HX_STACK_VAR(_g1,"_g1");
			struct _Function_2_4{
				inline static Dynamic Block( ){
					HX_STACK_FRAME("*","closure",0x5bdab937,"*.closure","flixel/system/FlxSplash.hx",129,0xa5de80f2)
					{
						hx::Anon __result = hx::Anon_obj::Create();
						__result->Add(HX_CSTRING("ease") , ::flixel::tweens::FlxEase_obj::quadOut_dyn(),false);
						return __result;
					}
					return null();
				}
			};
			HX_STACK_LINE(129)
			::flixel::tweens::FlxTween_obj::multiVar(this->_text,_g1,3.0,_Function_2_4::Block());
		}
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC1(FlxSplash_obj,timerCallback,(void))

Void FlxSplash_obj::drawGreen( ){
{
		HX_STACK_FRAME("flixel.system.FlxSplash","drawGreen",0xf0f01c9d,"flixel.system.FlxSplash.drawGreen","flixel/system/FlxSplash.hx",134,0xa5de80f2)
		HX_STACK_THIS(this)
		HX_STACK_LINE(135)
		this->_gfx->beginFill((int)47394,null());
		HX_STACK_LINE(136)
		this->_gfx->moveTo((int)0,(int)-37);
		HX_STACK_LINE(137)
		this->_gfx->lineTo((int)1,(int)-37);
		HX_STACK_LINE(138)
		this->_gfx->lineTo((int)37,(int)0);
		HX_STACK_LINE(139)
		this->_gfx->lineTo((int)37,(int)1);
		HX_STACK_LINE(140)
		this->_gfx->lineTo((int)1,(int)37);
		HX_STACK_LINE(141)
		this->_gfx->lineTo((int)0,(int)37);
		HX_STACK_LINE(142)
		this->_gfx->lineTo((int)-37,(int)1);
		HX_STACK_LINE(143)
		this->_gfx->lineTo((int)-37,(int)0);
		HX_STACK_LINE(144)
		this->_gfx->lineTo((int)0,(int)-37);
		HX_STACK_LINE(145)
		this->_gfx->endFill();
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC0(FlxSplash_obj,drawGreen,(void))

Void FlxSplash_obj::drawYellow( ){
{
		HX_STACK_FRAME("flixel.system.FlxSplash","drawYellow",0x9c05b05a,"flixel.system.FlxSplash.drawYellow","flixel/system/FlxSplash.hx",149,0xa5de80f2)
		HX_STACK_THIS(this)
		HX_STACK_LINE(150)
		this->_gfx->beginFill((int)16761138,null());
		HX_STACK_LINE(151)
		this->_gfx->moveTo((int)-50,(int)-50);
		HX_STACK_LINE(152)
		this->_gfx->lineTo((int)-25,(int)-50);
		HX_STACK_LINE(153)
		this->_gfx->lineTo((int)0,(int)-37);
		HX_STACK_LINE(154)
		this->_gfx->lineTo((int)-37,(int)0);
		HX_STACK_LINE(155)
		this->_gfx->lineTo((int)-50,(int)-25);
		HX_STACK_LINE(156)
		this->_gfx->lineTo((int)-50,(int)-50);
		HX_STACK_LINE(157)
		this->_gfx->endFill();
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC0(FlxSplash_obj,drawYellow,(void))

Void FlxSplash_obj::drawRed( ){
{
		HX_STACK_FRAME("flixel.system.FlxSplash","drawRed",0xc6cedcab,"flixel.system.FlxSplash.drawRed","flixel/system/FlxSplash.hx",161,0xa5de80f2)
		HX_STACK_THIS(this)
		HX_STACK_LINE(162)
		this->_gfx->beginFill((int)16066382,null());
		HX_STACK_LINE(163)
		this->_gfx->moveTo((int)50,(int)-50);
		HX_STACK_LINE(164)
		this->_gfx->lineTo((int)25,(int)-50);
		HX_STACK_LINE(165)
		this->_gfx->lineTo((int)1,(int)-37);
		HX_STACK_LINE(166)
		this->_gfx->lineTo((int)37,(int)0);
		HX_STACK_LINE(167)
		this->_gfx->lineTo((int)50,(int)-25);
		HX_STACK_LINE(168)
		this->_gfx->lineTo((int)50,(int)-50);
		HX_STACK_LINE(169)
		this->_gfx->endFill();
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC0(FlxSplash_obj,drawRed,(void))

Void FlxSplash_obj::drawBlue( ){
{
		HX_STACK_FRAME("flixel.system.FlxSplash","drawBlue",0x23a42e00,"flixel.system.FlxSplash.drawBlue","flixel/system/FlxSplash.hx",173,0xa5de80f2)
		HX_STACK_THIS(this)
		HX_STACK_LINE(174)
		this->_gfx->beginFill((int)3555839,null());
		HX_STACK_LINE(175)
		this->_gfx->moveTo((int)-50,(int)50);
		HX_STACK_LINE(176)
		this->_gfx->lineTo((int)-25,(int)50);
		HX_STACK_LINE(177)
		this->_gfx->lineTo((int)0,(int)37);
		HX_STACK_LINE(178)
		this->_gfx->lineTo((int)-37,(int)1);
		HX_STACK_LINE(179)
		this->_gfx->lineTo((int)-50,(int)25);
		HX_STACK_LINE(180)
		this->_gfx->lineTo((int)-50,(int)50);
		HX_STACK_LINE(181)
		this->_gfx->endFill();
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC0(FlxSplash_obj,drawBlue,(void))

Void FlxSplash_obj::drawLightBlue( ){
{
		HX_STACK_FRAME("flixel.system.FlxSplash","drawLightBlue",0x099f256a,"flixel.system.FlxSplash.drawLightBlue","flixel/system/FlxSplash.hx",185,0xa5de80f2)
		HX_STACK_THIS(this)
		HX_STACK_LINE(186)
		this->_gfx->beginFill((int)314875,null());
		HX_STACK_LINE(187)
		this->_gfx->moveTo((int)50,(int)50);
		HX_STACK_LINE(188)
		this->_gfx->lineTo((int)25,(int)50);
		HX_STACK_LINE(189)
		this->_gfx->lineTo((int)1,(int)37);
		HX_STACK_LINE(190)
		this->_gfx->lineTo((int)37,(int)1);
		HX_STACK_LINE(191)
		this->_gfx->lineTo((int)50,(int)25);
		HX_STACK_LINE(192)
		this->_gfx->lineTo((int)50,(int)50);
		HX_STACK_LINE(193)
		this->_gfx->endFill();
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC0(FlxSplash_obj,drawLightBlue,(void))

Void FlxSplash_obj::onComplete( ::flixel::tweens::FlxTween Tween){
{
		HX_STACK_FRAME("flixel.system.FlxSplash","onComplete",0xe7646aba,"flixel.system.FlxSplash.onComplete","flixel/system/FlxSplash.hx",197,0xa5de80f2)
		HX_STACK_THIS(this)
		HX_STACK_ARG(Tween,"Tween")
		HX_STACK_LINE(198)
		::flixel::FlxG_obj::cameras->set_bgColor(this->_cachedBgColor);
		HX_STACK_LINE(199)
		::flixel::FlxG_obj::fixedTimestep = this->_cachedTimestep;
		HX_STACK_LINE(200)
		::flixel::FlxG_obj::autoPause = this->_cachedAutoPause;
		HX_STACK_LINE(202)
		::flixel::FlxG_obj::keys->enabled = true;
		HX_STACK_LINE(204)
		::flash::Lib_obj::get_current()->get_stage()->removeChild(this->_sprite);
		HX_STACK_LINE(205)
		::flash::Lib_obj::get_current()->get_stage()->removeChild(this->_text);
		HX_STACK_LINE(206)
		{
			HX_STACK_LINE(206)
			::flixel::FlxState State = ::Type_obj::createInstance(this->_nextState,Dynamic( Array_obj<Dynamic>::__new()));		HX_STACK_VAR(State,"State");
			HX_STACK_LINE(206)
			::flixel::FlxG_obj::game->_requestedState = State;
		}
		HX_STACK_LINE(207)
		::flixel::FlxG_obj::game->_gameJustStarted = true;
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC1(FlxSplash_obj,onComplete,(void))


FlxSplash_obj::FlxSplash_obj()
{
}

void FlxSplash_obj::__Mark(HX_MARK_PARAMS)
{
	HX_MARK_BEGIN_CLASS(FlxSplash);
	HX_MARK_MEMBER_NAME(_nextState,"_nextState");
	HX_MARK_MEMBER_NAME(_sprite,"_sprite");
	HX_MARK_MEMBER_NAME(_gfx,"_gfx");
	HX_MARK_MEMBER_NAME(_text,"_text");
	HX_MARK_MEMBER_NAME(_times,"_times");
	HX_MARK_MEMBER_NAME(_colors,"_colors");
	HX_MARK_MEMBER_NAME(_functions,"_functions");
	HX_MARK_MEMBER_NAME(_curPart,"_curPart");
	HX_MARK_MEMBER_NAME(_cachedBgColor,"_cachedBgColor");
	HX_MARK_MEMBER_NAME(_cachedTimestep,"_cachedTimestep");
	HX_MARK_MEMBER_NAME(_cachedAutoPause,"_cachedAutoPause");
	::flixel::FlxState_obj::__Mark(HX_MARK_ARG);
	HX_MARK_END_CLASS();
}

void FlxSplash_obj::__Visit(HX_VISIT_PARAMS)
{
	HX_VISIT_MEMBER_NAME(_nextState,"_nextState");
	HX_VISIT_MEMBER_NAME(_sprite,"_sprite");
	HX_VISIT_MEMBER_NAME(_gfx,"_gfx");
	HX_VISIT_MEMBER_NAME(_text,"_text");
	HX_VISIT_MEMBER_NAME(_times,"_times");
	HX_VISIT_MEMBER_NAME(_colors,"_colors");
	HX_VISIT_MEMBER_NAME(_functions,"_functions");
	HX_VISIT_MEMBER_NAME(_curPart,"_curPart");
	HX_VISIT_MEMBER_NAME(_cachedBgColor,"_cachedBgColor");
	HX_VISIT_MEMBER_NAME(_cachedTimestep,"_cachedTimestep");
	HX_VISIT_MEMBER_NAME(_cachedAutoPause,"_cachedAutoPause");
	::flixel::FlxState_obj::__Visit(HX_VISIT_ARG);
}

Dynamic FlxSplash_obj::__Field(const ::String &inName,bool inCallProp)
{
	switch(inName.length) {
	case 4:
		if (HX_FIELD_EQ(inName,"_gfx") ) { return _gfx; }
		break;
	case 5:
		if (HX_FIELD_EQ(inName,"_text") ) { return _text; }
		break;
	case 6:
		if (HX_FIELD_EQ(inName,"_times") ) { return _times; }
		if (HX_FIELD_EQ(inName,"create") ) { return create_dyn(); }
		break;
	case 7:
		if (HX_FIELD_EQ(inName,"_sprite") ) { return _sprite; }
		if (HX_FIELD_EQ(inName,"_colors") ) { return _colors; }
		if (HX_FIELD_EQ(inName,"destroy") ) { return destroy_dyn(); }
		if (HX_FIELD_EQ(inName,"drawRed") ) { return drawRed_dyn(); }
		break;
	case 8:
		if (HX_FIELD_EQ(inName,"_curPart") ) { return _curPart; }
		if (HX_FIELD_EQ(inName,"onResize") ) { return onResize_dyn(); }
		if (HX_FIELD_EQ(inName,"drawBlue") ) { return drawBlue_dyn(); }
		break;
	case 9:
		if (HX_FIELD_EQ(inName,"drawGreen") ) { return drawGreen_dyn(); }
		break;
	case 10:
		if (HX_FIELD_EQ(inName,"_nextState") ) { return _nextState; }
		if (HX_FIELD_EQ(inName,"_functions") ) { return _functions; }
		if (HX_FIELD_EQ(inName,"drawYellow") ) { return drawYellow_dyn(); }
		if (HX_FIELD_EQ(inName,"onComplete") ) { return onComplete_dyn(); }
		break;
	case 13:
		if (HX_FIELD_EQ(inName,"timerCallback") ) { return timerCallback_dyn(); }
		if (HX_FIELD_EQ(inName,"drawLightBlue") ) { return drawLightBlue_dyn(); }
		break;
	case 14:
		if (HX_FIELD_EQ(inName,"_cachedBgColor") ) { return _cachedBgColor; }
		break;
	case 15:
		if (HX_FIELD_EQ(inName,"_cachedTimestep") ) { return _cachedTimestep; }
		break;
	case 16:
		if (HX_FIELD_EQ(inName,"_cachedAutoPause") ) { return _cachedAutoPause; }
	}
	return super::__Field(inName,inCallProp);
}

Dynamic FlxSplash_obj::__SetField(const ::String &inName,const Dynamic &inValue,bool inCallProp)
{
	switch(inName.length) {
	case 4:
		if (HX_FIELD_EQ(inName,"_gfx") ) { _gfx=inValue.Cast< ::flash::display::Graphics >(); return inValue; }
		break;
	case 5:
		if (HX_FIELD_EQ(inName,"_text") ) { _text=inValue.Cast< ::flash::text::TextField >(); return inValue; }
		break;
	case 6:
		if (HX_FIELD_EQ(inName,"_times") ) { _times=inValue.Cast< Array< Float > >(); return inValue; }
		break;
	case 7:
		if (HX_FIELD_EQ(inName,"_sprite") ) { _sprite=inValue.Cast< ::flash::display::Sprite >(); return inValue; }
		if (HX_FIELD_EQ(inName,"_colors") ) { _colors=inValue.Cast< Array< int > >(); return inValue; }
		break;
	case 8:
		if (HX_FIELD_EQ(inName,"_curPart") ) { _curPart=inValue.Cast< int >(); return inValue; }
		break;
	case 10:
		if (HX_FIELD_EQ(inName,"_nextState") ) { _nextState=inValue.Cast< ::Class >(); return inValue; }
		if (HX_FIELD_EQ(inName,"_functions") ) { _functions=inValue.Cast< Dynamic >(); return inValue; }
		break;
	case 14:
		if (HX_FIELD_EQ(inName,"_cachedBgColor") ) { _cachedBgColor=inValue.Cast< int >(); return inValue; }
		break;
	case 15:
		if (HX_FIELD_EQ(inName,"_cachedTimestep") ) { _cachedTimestep=inValue.Cast< bool >(); return inValue; }
		break;
	case 16:
		if (HX_FIELD_EQ(inName,"_cachedAutoPause") ) { _cachedAutoPause=inValue.Cast< bool >(); return inValue; }
	}
	return super::__SetField(inName,inValue,inCallProp);
}

void FlxSplash_obj::__GetFields(Array< ::String> &outFields)
{
	outFields->push(HX_CSTRING("_nextState"));
	outFields->push(HX_CSTRING("_sprite"));
	outFields->push(HX_CSTRING("_gfx"));
	outFields->push(HX_CSTRING("_text"));
	outFields->push(HX_CSTRING("_times"));
	outFields->push(HX_CSTRING("_colors"));
	outFields->push(HX_CSTRING("_functions"));
	outFields->push(HX_CSTRING("_curPart"));
	outFields->push(HX_CSTRING("_cachedBgColor"));
	outFields->push(HX_CSTRING("_cachedTimestep"));
	outFields->push(HX_CSTRING("_cachedAutoPause"));
	super::__GetFields(outFields);
};

static ::String sStaticFields[] = {
	String(null()) };

#if HXCPP_SCRIPTABLE
static hx::StorageInfo sMemberStorageInfo[] = {
	{hx::fsObject /*::Class*/ ,(int)offsetof(FlxSplash_obj,_nextState),HX_CSTRING("_nextState")},
	{hx::fsObject /*::flash::display::Sprite*/ ,(int)offsetof(FlxSplash_obj,_sprite),HX_CSTRING("_sprite")},
	{hx::fsObject /*::flash::display::Graphics*/ ,(int)offsetof(FlxSplash_obj,_gfx),HX_CSTRING("_gfx")},
	{hx::fsObject /*::flash::text::TextField*/ ,(int)offsetof(FlxSplash_obj,_text),HX_CSTRING("_text")},
	{hx::fsObject /*Array< Float >*/ ,(int)offsetof(FlxSplash_obj,_times),HX_CSTRING("_times")},
	{hx::fsObject /*Array< int >*/ ,(int)offsetof(FlxSplash_obj,_colors),HX_CSTRING("_colors")},
	{hx::fsObject /*Dynamic*/ ,(int)offsetof(FlxSplash_obj,_functions),HX_CSTRING("_functions")},
	{hx::fsInt,(int)offsetof(FlxSplash_obj,_curPart),HX_CSTRING("_curPart")},
	{hx::fsInt,(int)offsetof(FlxSplash_obj,_cachedBgColor),HX_CSTRING("_cachedBgColor")},
	{hx::fsBool,(int)offsetof(FlxSplash_obj,_cachedTimestep),HX_CSTRING("_cachedTimestep")},
	{hx::fsBool,(int)offsetof(FlxSplash_obj,_cachedAutoPause),HX_CSTRING("_cachedAutoPause")},
	{ hx::fsUnknown, 0, null()}
};
#endif

static ::String sMemberFields[] = {
	HX_CSTRING("_nextState"),
	HX_CSTRING("_sprite"),
	HX_CSTRING("_gfx"),
	HX_CSTRING("_text"),
	HX_CSTRING("_times"),
	HX_CSTRING("_colors"),
	HX_CSTRING("_functions"),
	HX_CSTRING("_curPart"),
	HX_CSTRING("_cachedBgColor"),
	HX_CSTRING("_cachedTimestep"),
	HX_CSTRING("_cachedAutoPause"),
	HX_CSTRING("destroy"),
	HX_CSTRING("onResize"),
	HX_CSTRING("create"),
	HX_CSTRING("timerCallback"),
	HX_CSTRING("drawGreen"),
	HX_CSTRING("drawYellow"),
	HX_CSTRING("drawRed"),
	HX_CSTRING("drawBlue"),
	HX_CSTRING("drawLightBlue"),
	HX_CSTRING("onComplete"),
	String(null()) };

static void sMarkStatics(HX_MARK_PARAMS) {
	HX_MARK_MEMBER_NAME(FlxSplash_obj::__mClass,"__mClass");
};

#ifdef HXCPP_VISIT_ALLOCS
static void sVisitStatics(HX_VISIT_PARAMS) {
	HX_VISIT_MEMBER_NAME(FlxSplash_obj::__mClass,"__mClass");
};

#endif

Class FlxSplash_obj::__mClass;

void FlxSplash_obj::__register()
{
	hx::Static(__mClass) = hx::RegisterClass(HX_CSTRING("flixel.system.FlxSplash"), hx::TCanCast< FlxSplash_obj> ,sStaticFields,sMemberFields,
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

void FlxSplash_obj::__boot()
{
}

} // end namespace flixel
} // end namespace system
