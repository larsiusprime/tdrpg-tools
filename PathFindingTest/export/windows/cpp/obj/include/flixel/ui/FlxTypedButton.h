#ifndef INCLUDED_flixel_ui_FlxTypedButton
#define INCLUDED_flixel_ui_FlxTypedButton

#ifndef HXCPP_H
#include <hxcpp.h>
#endif

#include <flixel/FlxSprite.h>
HX_DECLARE_CLASS2(flash,events,Event)
HX_DECLARE_CLASS2(flash,events,MouseEvent)
HX_DECLARE_CLASS1(flixel,FlxBasic)
HX_DECLARE_CLASS1(flixel,FlxObject)
HX_DECLARE_CLASS1(flixel,FlxSprite)
HX_DECLARE_CLASS3(flixel,input,touch,FlxTouch)
HX_DECLARE_CLASS2(flixel,interfaces,IFlxDestroyable)
HX_DECLARE_CLASS2(flixel,ui,FlxTypedButton)
HX_DECLARE_CLASS3(flixel,ui,_FlxTypedButton,FlxButtonEvent)
HX_DECLARE_CLASS2(flixel,util,FlxPoint)
namespace flixel{
namespace ui{


class HXCPP_CLASS_ATTRIBUTES  FlxTypedButton_obj : public ::flixel::FlxSprite_obj{
	public:
		typedef ::flixel::FlxSprite_obj super;
		typedef FlxTypedButton_obj OBJ_;
		FlxTypedButton_obj();
		Void __construct(hx::Null< Float >  __o_X,hx::Null< Float >  __o_Y,::String Label,Dynamic OnClick);

	public:
		inline void *operator new( size_t inSize, bool inContainer=true)
			{ return hx::Object::operator new(inSize,inContainer); }
		static hx::ObjectPtr< FlxTypedButton_obj > __new(hx::Null< Float >  __o_X,hx::Null< Float >  __o_Y,::String Label,Dynamic OnClick);
		static Dynamic __CreateEmpty();
		static Dynamic __Create(hx::DynamicArray inArgs);
		//~FlxTypedButton_obj();

		HX_DO_RTTI;
		static void __boot();
		static void __register();
		void __Mark(HX_MARK_PARAMS);
		void __Visit(HX_VISIT_PARAMS);
		::String __ToString() const { return HX_CSTRING("FlxTypedButton"); }

		Dynamic label;
		Array< ::Dynamic > labelOffsets;
		Array< Float > labelAlphas;
		bool allowSwiping;
		bool allowHighlightOnMobile;
		int status;
		::flixel::ui::_FlxTypedButton::FlxButtonEvent onUp;
		::flixel::ui::_FlxTypedButton::FlxButtonEvent onDown;
		::flixel::ui::_FlxTypedButton::FlxButtonEvent onOver;
		::flixel::ui::_FlxTypedButton::FlxButtonEvent onOut;
		::flixel::input::touch::FlxTouch _pressedTouch;
		bool _pressedMouse;
		virtual Void destroy( );

		virtual Void update( );

		virtual Void draw( );

		virtual Void drawDebug( );

		virtual Void updateButton( );
		Dynamic updateButton_dyn();

		virtual Void updateStatus( bool Overlap,bool JustPressed,bool Pressed,::flixel::input::touch::FlxTouch Touch);
		Dynamic updateStatus_dyn();

		virtual int set_status( int Value);
		Dynamic set_status_dyn();

		virtual Void onUpEventListener( ::flash::events::MouseEvent E);
		Dynamic onUpEventListener_dyn();

		virtual Void onUpHandler( );
		Dynamic onUpHandler_dyn();

		virtual Void onDownHandler( );
		Dynamic onDownHandler_dyn();

		virtual Void onOverHandler( );
		Dynamic onOverHandler_dyn();

		virtual Void onOutHandler( );
		Dynamic onOutHandler_dyn();

};

} // end namespace flixel
} // end namespace ui

#endif /* INCLUDED_flixel_ui_FlxTypedButton */ 
