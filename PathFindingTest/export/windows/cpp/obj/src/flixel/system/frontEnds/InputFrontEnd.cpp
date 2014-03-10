#include <hxcpp.h>

#ifndef INCLUDED_Std
#include <Std.h>
#endif
#ifndef INCLUDED_StringTools
#include <StringTools.h>
#endif
#ifndef INCLUDED_Type
#include <Type.h>
#endif
#ifndef INCLUDED_flixel_input_gamepad_FlxGamepadManager
#include <flixel/input/gamepad/FlxGamepadManager.h>
#endif
#ifndef INCLUDED_flixel_input_keyboard_FlxKeyboard
#include <flixel/input/keyboard/FlxKeyboard.h>
#endif
#ifndef INCLUDED_flixel_input_mouse_FlxMouse
#include <flixel/input/mouse/FlxMouse.h>
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
#ifndef INCLUDED_flixel_system_frontEnds_InputFrontEnd
#include <flixel/system/frontEnds/InputFrontEnd.h>
#endif
#ifndef INCLUDED_flixel_util_FlxPoint
#include <flixel/util/FlxPoint.h>
#endif
namespace flixel{
namespace system{
namespace frontEnds{

Void InputFrontEnd_obj::__construct()
{
HX_STACK_FRAME("flixel.system.frontEnds.InputFrontEnd","new",0x5285aa54,"flixel.system.frontEnds.InputFrontEnd.new","flixel/system/frontEnds/InputFrontEnd.hx",52,0x759f67bd)
{
	HX_STACK_LINE(52)
	this->list = Array_obj< ::flixel::interfaces::IFlxInput >::__new();
}
;
	return null();
}

//InputFrontEnd_obj::~InputFrontEnd_obj() { }

Dynamic InputFrontEnd_obj::__CreateEmpty() { return  new InputFrontEnd_obj; }
hx::ObjectPtr< InputFrontEnd_obj > InputFrontEnd_obj::__new()
{  hx::ObjectPtr< InputFrontEnd_obj > result = new InputFrontEnd_obj();
	result->__construct();
	return result;}

Dynamic InputFrontEnd_obj::__Create(hx::DynamicArray inArgs)
{  hx::ObjectPtr< InputFrontEnd_obj > result = new InputFrontEnd_obj();
	result->__construct();
	return result;}

::flixel::input::gamepad::FlxGamepadManager InputFrontEnd_obj::add_flixel_input_gamepad_FlxGamepadManager( ::flixel::input::gamepad::FlxGamepadManager Input){
	HX_STACK_FRAME("flixel.system.frontEnds.InputFrontEnd","add_flixel_input_gamepad_FlxGamepadManager",0x189964b2,"flixel.system.frontEnds.InputFrontEnd.add_flixel_input_gamepad_FlxGamepadManager","flixel/system/frontEnds/InputFrontEnd.hx",25,0x759f67bd)
	HX_STACK_THIS(this)
	HX_STACK_ARG(Input,"Input")
	HX_STACK_LINE(27)
	{
		HX_STACK_LINE(27)
		int _g = (int)0;		HX_STACK_VAR(_g,"_g");
		HX_STACK_LINE(27)
		Array< ::flixel::interfaces::IFlxInput > _g1 = this->list;		HX_STACK_VAR(_g1,"_g1");
		HX_STACK_LINE(27)
		while(((_g < _g1->length))){
			HX_STACK_LINE(27)
			::flixel::interfaces::IFlxInput input = _g1->__get(_g);		HX_STACK_VAR(input,"input");
			HX_STACK_LINE(27)
			++(_g);
			struct _Function_3_1{
				inline static bool Block( ::flixel::input::gamepad::FlxGamepadManager &Input,::flixel::interfaces::IFlxInput &input){
					HX_STACK_FRAME("*","closure",0x5bdab937,"*.closure","flixel/system/frontEnds/InputFrontEnd.hx",29,0x759f67bd)
					{
						HX_STACK_LINE(29)
						bool Simple = true;		HX_STACK_VAR(Simple,"Simple");
						HX_STACK_LINE(29)
						::String _g2;		HX_STACK_VAR(_g2,"_g2");
						HX_STACK_LINE(29)
						{
							HX_STACK_LINE(29)
							::Class cl;		HX_STACK_VAR(cl,"cl");
							HX_STACK_LINE(29)
							if ((::Std_obj::is(Input,hx::ClassOf< ::Class >()))){
								HX_STACK_LINE(29)
								cl = Input;
							}
							else{
								HX_STACK_LINE(29)
								cl = ::Type_obj::getClass(Input);
							}
							HX_STACK_LINE(29)
							::String s = ::Type_obj::getClassName(cl);		HX_STACK_VAR(s,"s");
							HX_STACK_LINE(29)
							if (((s != null()))){
								HX_STACK_LINE(29)
								s = ::StringTools_obj::replace(s,HX_CSTRING("::"),HX_CSTRING("."));
								HX_STACK_LINE(29)
								if ((Simple)){
									HX_STACK_LINE(29)
									s = s.substr((s.lastIndexOf(HX_CSTRING("."),null()) + (int)1),null());
								}
							}
							HX_STACK_LINE(29)
							_g2 = s;
						}
						struct _Function_4_1{
							inline static ::String Block( ::flixel::interfaces::IFlxInput &input,bool &Simple){
								HX_STACK_FRAME("*","closure",0x5bdab937,"*.closure","flixel/system/frontEnds/InputFrontEnd.hx",29,0x759f67bd)
								{
									HX_STACK_LINE(29)
									::Class cl;		HX_STACK_VAR(cl,"cl");
									HX_STACK_LINE(29)
									if ((::Std_obj::is(input,hx::ClassOf< ::Class >()))){
										HX_STACK_LINE(29)
										cl = input;
									}
									else{
										HX_STACK_LINE(29)
										cl = ::Type_obj::getClass(input);
									}
									HX_STACK_LINE(29)
									::String s = ::Type_obj::getClassName(cl);		HX_STACK_VAR(s,"s");
									HX_STACK_LINE(29)
									if (((s != null()))){
										HX_STACK_LINE(29)
										s = ::StringTools_obj::replace(s,HX_CSTRING("::"),HX_CSTRING("."));
										HX_STACK_LINE(29)
										if ((Simple)){
											HX_STACK_LINE(29)
											s = s.substr((s.lastIndexOf(HX_CSTRING("."),null()) + (int)1),null());
										}
									}
									HX_STACK_LINE(29)
									return s;
								}
								return null();
							}
						};
						HX_STACK_LINE(29)
						return (_g2 == _Function_4_1::Block(input,Simple));
					}
					return null();
				}
			};
			HX_STACK_LINE(29)
			if ((_Function_3_1::Block(Input,input))){
				HX_STACK_LINE(31)
				return Input;
			}
		}
	}
	HX_STACK_LINE(35)
	this->list->push(Input);
	HX_STACK_LINE(36)
	return Input;
}


HX_DEFINE_DYNAMIC_FUNC1(InputFrontEnd_obj,add_flixel_input_gamepad_FlxGamepadManager,return )

::flixel::input::touch::FlxTouchManager InputFrontEnd_obj::add_flixel_input_touch_FlxTouchManager( ::flixel::input::touch::FlxTouchManager Input){
	HX_STACK_FRAME("flixel.system.frontEnds.InputFrontEnd","add_flixel_input_touch_FlxTouchManager",0x760d6272,"flixel.system.frontEnds.InputFrontEnd.add_flixel_input_touch_FlxTouchManager","flixel/system/frontEnds/InputFrontEnd.hx",25,0x759f67bd)
	HX_STACK_THIS(this)
	HX_STACK_ARG(Input,"Input")
	HX_STACK_LINE(27)
	{
		HX_STACK_LINE(27)
		int _g = (int)0;		HX_STACK_VAR(_g,"_g");
		HX_STACK_LINE(27)
		Array< ::flixel::interfaces::IFlxInput > _g1 = this->list;		HX_STACK_VAR(_g1,"_g1");
		HX_STACK_LINE(27)
		while(((_g < _g1->length))){
			HX_STACK_LINE(27)
			::flixel::interfaces::IFlxInput input = _g1->__get(_g);		HX_STACK_VAR(input,"input");
			HX_STACK_LINE(27)
			++(_g);
			struct _Function_3_1{
				inline static bool Block( ::flixel::input::touch::FlxTouchManager &Input,::flixel::interfaces::IFlxInput &input){
					HX_STACK_FRAME("*","closure",0x5bdab937,"*.closure","flixel/system/frontEnds/InputFrontEnd.hx",29,0x759f67bd)
					{
						HX_STACK_LINE(29)
						bool Simple = true;		HX_STACK_VAR(Simple,"Simple");
						HX_STACK_LINE(29)
						::String _g2;		HX_STACK_VAR(_g2,"_g2");
						HX_STACK_LINE(29)
						{
							HX_STACK_LINE(29)
							::Class cl;		HX_STACK_VAR(cl,"cl");
							HX_STACK_LINE(29)
							if ((::Std_obj::is(Input,hx::ClassOf< ::Class >()))){
								HX_STACK_LINE(29)
								cl = Input;
							}
							else{
								HX_STACK_LINE(29)
								cl = ::Type_obj::getClass(Input);
							}
							HX_STACK_LINE(29)
							::String s = ::Type_obj::getClassName(cl);		HX_STACK_VAR(s,"s");
							HX_STACK_LINE(29)
							if (((s != null()))){
								HX_STACK_LINE(29)
								s = ::StringTools_obj::replace(s,HX_CSTRING("::"),HX_CSTRING("."));
								HX_STACK_LINE(29)
								if ((Simple)){
									HX_STACK_LINE(29)
									s = s.substr((s.lastIndexOf(HX_CSTRING("."),null()) + (int)1),null());
								}
							}
							HX_STACK_LINE(29)
							_g2 = s;
						}
						struct _Function_4_1{
							inline static ::String Block( ::flixel::interfaces::IFlxInput &input,bool &Simple){
								HX_STACK_FRAME("*","closure",0x5bdab937,"*.closure","flixel/system/frontEnds/InputFrontEnd.hx",29,0x759f67bd)
								{
									HX_STACK_LINE(29)
									::Class cl;		HX_STACK_VAR(cl,"cl");
									HX_STACK_LINE(29)
									if ((::Std_obj::is(input,hx::ClassOf< ::Class >()))){
										HX_STACK_LINE(29)
										cl = input;
									}
									else{
										HX_STACK_LINE(29)
										cl = ::Type_obj::getClass(input);
									}
									HX_STACK_LINE(29)
									::String s = ::Type_obj::getClassName(cl);		HX_STACK_VAR(s,"s");
									HX_STACK_LINE(29)
									if (((s != null()))){
										HX_STACK_LINE(29)
										s = ::StringTools_obj::replace(s,HX_CSTRING("::"),HX_CSTRING("."));
										HX_STACK_LINE(29)
										if ((Simple)){
											HX_STACK_LINE(29)
											s = s.substr((s.lastIndexOf(HX_CSTRING("."),null()) + (int)1),null());
										}
									}
									HX_STACK_LINE(29)
									return s;
								}
								return null();
							}
						};
						HX_STACK_LINE(29)
						return (_g2 == _Function_4_1::Block(input,Simple));
					}
					return null();
				}
			};
			HX_STACK_LINE(29)
			if ((_Function_3_1::Block(Input,input))){
				HX_STACK_LINE(31)
				return Input;
			}
		}
	}
	HX_STACK_LINE(35)
	this->list->push(Input);
	HX_STACK_LINE(36)
	return Input;
}


HX_DEFINE_DYNAMIC_FUNC1(InputFrontEnd_obj,add_flixel_input_touch_FlxTouchManager,return )

::flixel::input::mouse::FlxMouse InputFrontEnd_obj::add_flixel_input_mouse_FlxMouse( ::flixel::input::mouse::FlxMouse Input){
	HX_STACK_FRAME("flixel.system.frontEnds.InputFrontEnd","add_flixel_input_mouse_FlxMouse",0xe1e4487b,"flixel.system.frontEnds.InputFrontEnd.add_flixel_input_mouse_FlxMouse","flixel/system/frontEnds/InputFrontEnd.hx",25,0x759f67bd)
	HX_STACK_THIS(this)
	HX_STACK_ARG(Input,"Input")
	HX_STACK_LINE(27)
	{
		HX_STACK_LINE(27)
		int _g = (int)0;		HX_STACK_VAR(_g,"_g");
		HX_STACK_LINE(27)
		Array< ::flixel::interfaces::IFlxInput > _g1 = this->list;		HX_STACK_VAR(_g1,"_g1");
		HX_STACK_LINE(27)
		while(((_g < _g1->length))){
			HX_STACK_LINE(27)
			::flixel::interfaces::IFlxInput input = _g1->__get(_g);		HX_STACK_VAR(input,"input");
			HX_STACK_LINE(27)
			++(_g);
			struct _Function_3_1{
				inline static bool Block( ::flixel::input::mouse::FlxMouse &Input,::flixel::interfaces::IFlxInput &input){
					HX_STACK_FRAME("*","closure",0x5bdab937,"*.closure","flixel/system/frontEnds/InputFrontEnd.hx",29,0x759f67bd)
					{
						HX_STACK_LINE(29)
						bool Simple = true;		HX_STACK_VAR(Simple,"Simple");
						HX_STACK_LINE(29)
						::String _g2;		HX_STACK_VAR(_g2,"_g2");
						HX_STACK_LINE(29)
						{
							HX_STACK_LINE(29)
							::Class cl;		HX_STACK_VAR(cl,"cl");
							HX_STACK_LINE(29)
							if ((::Std_obj::is(Input,hx::ClassOf< ::Class >()))){
								HX_STACK_LINE(29)
								cl = Input;
							}
							else{
								HX_STACK_LINE(29)
								cl = ::Type_obj::getClass(Input);
							}
							HX_STACK_LINE(29)
							::String s = ::Type_obj::getClassName(cl);		HX_STACK_VAR(s,"s");
							HX_STACK_LINE(29)
							if (((s != null()))){
								HX_STACK_LINE(29)
								s = ::StringTools_obj::replace(s,HX_CSTRING("::"),HX_CSTRING("."));
								HX_STACK_LINE(29)
								if ((Simple)){
									HX_STACK_LINE(29)
									s = s.substr((s.lastIndexOf(HX_CSTRING("."),null()) + (int)1),null());
								}
							}
							HX_STACK_LINE(29)
							_g2 = s;
						}
						struct _Function_4_1{
							inline static ::String Block( ::flixel::interfaces::IFlxInput &input,bool &Simple){
								HX_STACK_FRAME("*","closure",0x5bdab937,"*.closure","flixel/system/frontEnds/InputFrontEnd.hx",29,0x759f67bd)
								{
									HX_STACK_LINE(29)
									::Class cl;		HX_STACK_VAR(cl,"cl");
									HX_STACK_LINE(29)
									if ((::Std_obj::is(input,hx::ClassOf< ::Class >()))){
										HX_STACK_LINE(29)
										cl = input;
									}
									else{
										HX_STACK_LINE(29)
										cl = ::Type_obj::getClass(input);
									}
									HX_STACK_LINE(29)
									::String s = ::Type_obj::getClassName(cl);		HX_STACK_VAR(s,"s");
									HX_STACK_LINE(29)
									if (((s != null()))){
										HX_STACK_LINE(29)
										s = ::StringTools_obj::replace(s,HX_CSTRING("::"),HX_CSTRING("."));
										HX_STACK_LINE(29)
										if ((Simple)){
											HX_STACK_LINE(29)
											s = s.substr((s.lastIndexOf(HX_CSTRING("."),null()) + (int)1),null());
										}
									}
									HX_STACK_LINE(29)
									return s;
								}
								return null();
							}
						};
						HX_STACK_LINE(29)
						return (_g2 == _Function_4_1::Block(input,Simple));
					}
					return null();
				}
			};
			HX_STACK_LINE(29)
			if ((_Function_3_1::Block(Input,input))){
				HX_STACK_LINE(31)
				return Input;
			}
		}
	}
	HX_STACK_LINE(35)
	this->list->push(Input);
	HX_STACK_LINE(36)
	return Input;
}


HX_DEFINE_DYNAMIC_FUNC1(InputFrontEnd_obj,add_flixel_input_mouse_FlxMouse,return )

::flixel::input::keyboard::FlxKeyboard InputFrontEnd_obj::add_flixel_input_keyboard_FlxKeyboard( ::flixel::input::keyboard::FlxKeyboard Input){
	HX_STACK_FRAME("flixel.system.frontEnds.InputFrontEnd","add_flixel_input_keyboard_FlxKeyboard",0xa934da2f,"flixel.system.frontEnds.InputFrontEnd.add_flixel_input_keyboard_FlxKeyboard","flixel/system/frontEnds/InputFrontEnd.hx",25,0x759f67bd)
	HX_STACK_THIS(this)
	HX_STACK_ARG(Input,"Input")
	HX_STACK_LINE(27)
	{
		HX_STACK_LINE(27)
		int _g = (int)0;		HX_STACK_VAR(_g,"_g");
		HX_STACK_LINE(27)
		Array< ::flixel::interfaces::IFlxInput > _g1 = this->list;		HX_STACK_VAR(_g1,"_g1");
		HX_STACK_LINE(27)
		while(((_g < _g1->length))){
			HX_STACK_LINE(27)
			::flixel::interfaces::IFlxInput input = _g1->__get(_g);		HX_STACK_VAR(input,"input");
			HX_STACK_LINE(27)
			++(_g);
			struct _Function_3_1{
				inline static bool Block( ::flixel::input::keyboard::FlxKeyboard &Input,::flixel::interfaces::IFlxInput &input){
					HX_STACK_FRAME("*","closure",0x5bdab937,"*.closure","flixel/system/frontEnds/InputFrontEnd.hx",29,0x759f67bd)
					{
						HX_STACK_LINE(29)
						bool Simple = true;		HX_STACK_VAR(Simple,"Simple");
						HX_STACK_LINE(29)
						::String _g2;		HX_STACK_VAR(_g2,"_g2");
						HX_STACK_LINE(29)
						{
							HX_STACK_LINE(29)
							::Class cl;		HX_STACK_VAR(cl,"cl");
							HX_STACK_LINE(29)
							if ((::Std_obj::is(Input,hx::ClassOf< ::Class >()))){
								HX_STACK_LINE(29)
								cl = Input;
							}
							else{
								HX_STACK_LINE(29)
								cl = ::Type_obj::getClass(Input);
							}
							HX_STACK_LINE(29)
							::String s = ::Type_obj::getClassName(cl);		HX_STACK_VAR(s,"s");
							HX_STACK_LINE(29)
							if (((s != null()))){
								HX_STACK_LINE(29)
								s = ::StringTools_obj::replace(s,HX_CSTRING("::"),HX_CSTRING("."));
								HX_STACK_LINE(29)
								if ((Simple)){
									HX_STACK_LINE(29)
									s = s.substr((s.lastIndexOf(HX_CSTRING("."),null()) + (int)1),null());
								}
							}
							HX_STACK_LINE(29)
							_g2 = s;
						}
						struct _Function_4_1{
							inline static ::String Block( ::flixel::interfaces::IFlxInput &input,bool &Simple){
								HX_STACK_FRAME("*","closure",0x5bdab937,"*.closure","flixel/system/frontEnds/InputFrontEnd.hx",29,0x759f67bd)
								{
									HX_STACK_LINE(29)
									::Class cl;		HX_STACK_VAR(cl,"cl");
									HX_STACK_LINE(29)
									if ((::Std_obj::is(input,hx::ClassOf< ::Class >()))){
										HX_STACK_LINE(29)
										cl = input;
									}
									else{
										HX_STACK_LINE(29)
										cl = ::Type_obj::getClass(input);
									}
									HX_STACK_LINE(29)
									::String s = ::Type_obj::getClassName(cl);		HX_STACK_VAR(s,"s");
									HX_STACK_LINE(29)
									if (((s != null()))){
										HX_STACK_LINE(29)
										s = ::StringTools_obj::replace(s,HX_CSTRING("::"),HX_CSTRING("."));
										HX_STACK_LINE(29)
										if ((Simple)){
											HX_STACK_LINE(29)
											s = s.substr((s.lastIndexOf(HX_CSTRING("."),null()) + (int)1),null());
										}
									}
									HX_STACK_LINE(29)
									return s;
								}
								return null();
							}
						};
						HX_STACK_LINE(29)
						return (_g2 == _Function_4_1::Block(input,Simple));
					}
					return null();
				}
			};
			HX_STACK_LINE(29)
			if ((_Function_3_1::Block(Input,input))){
				HX_STACK_LINE(31)
				return Input;
			}
		}
	}
	HX_STACK_LINE(35)
	this->list->push(Input);
	HX_STACK_LINE(36)
	return Input;
}


HX_DEFINE_DYNAMIC_FUNC1(InputFrontEnd_obj,add_flixel_input_keyboard_FlxKeyboard,return )

Void InputFrontEnd_obj::reset( ){
{
		HX_STACK_FRAME("flixel.system.frontEnds.InputFrontEnd","reset",0x8c9b88c3,"flixel.system.frontEnds.InputFrontEnd.reset","flixel/system/frontEnds/InputFrontEnd.hx",44,0x759f67bd)
		HX_STACK_THIS(this)
		HX_STACK_LINE(44)
		int _g = (int)0;		HX_STACK_VAR(_g,"_g");
		HX_STACK_LINE(44)
		Array< ::flixel::interfaces::IFlxInput > _g1 = this->list;		HX_STACK_VAR(_g1,"_g1");
		HX_STACK_LINE(44)
		while(((_g < _g1->length))){
			HX_STACK_LINE(44)
			::flixel::interfaces::IFlxInput input = _g1->__get(_g);		HX_STACK_VAR(input,"input");
			HX_STACK_LINE(44)
			++(_g);
			HX_STACK_LINE(46)
			input->reset();
		}
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC0(InputFrontEnd_obj,reset,(void))

Void InputFrontEnd_obj::update( ){
{
		HX_STACK_FRAME("flixel.system.frontEnds.InputFrontEnd","update",0xfa095c95,"flixel.system.frontEnds.InputFrontEnd.update","flixel/system/frontEnds/InputFrontEnd.hx",60,0x759f67bd)
		HX_STACK_THIS(this)
		HX_STACK_LINE(60)
		int _g = (int)0;		HX_STACK_VAR(_g,"_g");
		HX_STACK_LINE(60)
		Array< ::flixel::interfaces::IFlxInput > _g1 = this->list;		HX_STACK_VAR(_g1,"_g1");
		HX_STACK_LINE(60)
		while(((_g < _g1->length))){
			HX_STACK_LINE(60)
			::flixel::interfaces::IFlxInput input = _g1->__get(_g);		HX_STACK_VAR(input,"input");
			HX_STACK_LINE(60)
			++(_g);
			HX_STACK_LINE(62)
			input->update();
		}
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC0(InputFrontEnd_obj,update,(void))

Void InputFrontEnd_obj::onFocus( ){
{
		HX_STACK_FRAME("flixel.system.frontEnds.InputFrontEnd","onFocus",0xcb1ee22d,"flixel.system.frontEnds.InputFrontEnd.onFocus","flixel/system/frontEnds/InputFrontEnd.hx",71,0x759f67bd)
		HX_STACK_THIS(this)
		HX_STACK_LINE(71)
		int _g = (int)0;		HX_STACK_VAR(_g,"_g");
		HX_STACK_LINE(71)
		Array< ::flixel::interfaces::IFlxInput > _g1 = this->list;		HX_STACK_VAR(_g1,"_g1");
		HX_STACK_LINE(71)
		while(((_g < _g1->length))){
			HX_STACK_LINE(71)
			::flixel::interfaces::IFlxInput input = _g1->__get(_g);		HX_STACK_VAR(input,"input");
			HX_STACK_LINE(71)
			++(_g);
			HX_STACK_LINE(73)
			input->onFocus();
		}
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC0(InputFrontEnd_obj,onFocus,(void))

Void InputFrontEnd_obj::onFocusLost( ){
{
		HX_STACK_FRAME("flixel.system.frontEnds.InputFrontEnd","onFocusLost",0x5cd0d2b1,"flixel.system.frontEnds.InputFrontEnd.onFocusLost","flixel/system/frontEnds/InputFrontEnd.hx",82,0x759f67bd)
		HX_STACK_THIS(this)
		HX_STACK_LINE(82)
		int _g = (int)0;		HX_STACK_VAR(_g,"_g");
		HX_STACK_LINE(82)
		Array< ::flixel::interfaces::IFlxInput > _g1 = this->list;		HX_STACK_VAR(_g1,"_g1");
		HX_STACK_LINE(82)
		while(((_g < _g1->length))){
			HX_STACK_LINE(82)
			::flixel::interfaces::IFlxInput input = _g1->__get(_g);		HX_STACK_VAR(input,"input");
			HX_STACK_LINE(82)
			++(_g);
			HX_STACK_LINE(84)
			input->onFocusLost();
		}
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC0(InputFrontEnd_obj,onFocusLost,(void))

Void InputFrontEnd_obj::destroy( ){
{
		HX_STACK_FRAME("flixel.system.frontEnds.InputFrontEnd","destroy",0x54de10ee,"flixel.system.frontEnds.InputFrontEnd.destroy","flixel/system/frontEnds/InputFrontEnd.hx",93,0x759f67bd)
		HX_STACK_THIS(this)
		HX_STACK_LINE(93)
		int _g = (int)0;		HX_STACK_VAR(_g,"_g");
		HX_STACK_LINE(93)
		Array< ::flixel::interfaces::IFlxInput > _g1 = this->list;		HX_STACK_VAR(_g1,"_g1");
		HX_STACK_LINE(93)
		while(((_g < _g1->length))){
			HX_STACK_LINE(93)
			::flixel::interfaces::IFlxInput input = _g1->__get(_g);		HX_STACK_VAR(input,"input");
			HX_STACK_LINE(93)
			++(_g);
			HX_STACK_LINE(95)
			input->destroy();
			HX_STACK_LINE(96)
			input = null();
		}
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC0(InputFrontEnd_obj,destroy,(void))


InputFrontEnd_obj::InputFrontEnd_obj()
{
}

void InputFrontEnd_obj::__Mark(HX_MARK_PARAMS)
{
	HX_MARK_BEGIN_CLASS(InputFrontEnd);
	HX_MARK_MEMBER_NAME(list,"list");
	HX_MARK_END_CLASS();
}

void InputFrontEnd_obj::__Visit(HX_VISIT_PARAMS)
{
	HX_VISIT_MEMBER_NAME(list,"list");
}

Dynamic InputFrontEnd_obj::__Field(const ::String &inName,bool inCallProp)
{
	switch(inName.length) {
	case 4:
		if (HX_FIELD_EQ(inName,"list") ) { return list; }
		break;
	case 5:
		if (HX_FIELD_EQ(inName,"reset") ) { return reset_dyn(); }
		break;
	case 6:
		if (HX_FIELD_EQ(inName,"update") ) { return update_dyn(); }
		break;
	case 7:
		if (HX_FIELD_EQ(inName,"onFocus") ) { return onFocus_dyn(); }
		if (HX_FIELD_EQ(inName,"destroy") ) { return destroy_dyn(); }
		break;
	case 11:
		if (HX_FIELD_EQ(inName,"onFocusLost") ) { return onFocusLost_dyn(); }
		break;
	case 31:
		if (HX_FIELD_EQ(inName,"add_flixel_input_mouse_FlxMouse") ) { return add_flixel_input_mouse_FlxMouse_dyn(); }
		break;
	case 37:
		if (HX_FIELD_EQ(inName,"add_flixel_input_keyboard_FlxKeyboard") ) { return add_flixel_input_keyboard_FlxKeyboard_dyn(); }
		break;
	case 38:
		if (HX_FIELD_EQ(inName,"add_flixel_input_touch_FlxTouchManager") ) { return add_flixel_input_touch_FlxTouchManager_dyn(); }
		break;
	case 42:
		if (HX_FIELD_EQ(inName,"add_flixel_input_gamepad_FlxGamepadManager") ) { return add_flixel_input_gamepad_FlxGamepadManager_dyn(); }
	}
	return super::__Field(inName,inCallProp);
}

Dynamic InputFrontEnd_obj::__SetField(const ::String &inName,const Dynamic &inValue,bool inCallProp)
{
	switch(inName.length) {
	case 4:
		if (HX_FIELD_EQ(inName,"list") ) { list=inValue.Cast< Array< ::flixel::interfaces::IFlxInput > >(); return inValue; }
	}
	return super::__SetField(inName,inValue,inCallProp);
}

void InputFrontEnd_obj::__GetFields(Array< ::String> &outFields)
{
	outFields->push(HX_CSTRING("list"));
	super::__GetFields(outFields);
};

static ::String sStaticFields[] = {
	String(null()) };

#if HXCPP_SCRIPTABLE
static hx::StorageInfo sMemberStorageInfo[] = {
	{hx::fsObject /*Array< ::flixel::interfaces::IFlxInput >*/ ,(int)offsetof(InputFrontEnd_obj,list),HX_CSTRING("list")},
	{ hx::fsUnknown, 0, null()}
};
#endif

static ::String sMemberFields[] = {
	HX_CSTRING("add_flixel_input_gamepad_FlxGamepadManager"),
	HX_CSTRING("add_flixel_input_touch_FlxTouchManager"),
	HX_CSTRING("add_flixel_input_mouse_FlxMouse"),
	HX_CSTRING("add_flixel_input_keyboard_FlxKeyboard"),
	HX_CSTRING("list"),
	HX_CSTRING("reset"),
	HX_CSTRING("update"),
	HX_CSTRING("onFocus"),
	HX_CSTRING("onFocusLost"),
	HX_CSTRING("destroy"),
	String(null()) };

static void sMarkStatics(HX_MARK_PARAMS) {
	HX_MARK_MEMBER_NAME(InputFrontEnd_obj::__mClass,"__mClass");
};

#ifdef HXCPP_VISIT_ALLOCS
static void sVisitStatics(HX_VISIT_PARAMS) {
	HX_VISIT_MEMBER_NAME(InputFrontEnd_obj::__mClass,"__mClass");
};

#endif

Class InputFrontEnd_obj::__mClass;

void InputFrontEnd_obj::__register()
{
	hx::Static(__mClass) = hx::RegisterClass(HX_CSTRING("flixel.system.frontEnds.InputFrontEnd"), hx::TCanCast< InputFrontEnd_obj> ,sStaticFields,sMemberFields,
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

void InputFrontEnd_obj::__boot()
{
}

} // end namespace flixel
} // end namespace system
} // end namespace frontEnds
