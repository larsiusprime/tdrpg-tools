#ifndef INCLUDED_flixel_system_debug_FlxDebugger
#define INCLUDED_flixel_system_debug_FlxDebugger

#ifndef HXCPP_H
#include <hxcpp.h>
#endif

#include <flash/display/Sprite.h>
HX_DECLARE_CLASS2(flash,display,BitmapData)
HX_DECLARE_CLASS2(flash,display,DisplayObject)
HX_DECLARE_CLASS2(flash,display,DisplayObjectContainer)
HX_DECLARE_CLASS2(flash,display,IBitmapDrawable)
HX_DECLARE_CLASS2(flash,display,InteractiveObject)
HX_DECLARE_CLASS2(flash,display,Sprite)
HX_DECLARE_CLASS2(flash,events,Event)
HX_DECLARE_CLASS2(flash,events,EventDispatcher)
HX_DECLARE_CLASS2(flash,events,IEventDispatcher)
HX_DECLARE_CLASS2(flash,events,MouseEvent)
HX_DECLARE_CLASS2(flash,geom,Point)
HX_DECLARE_CLASS2(flash,geom,Rectangle)
HX_DECLARE_CLASS2(flixel,interfaces,IFlxDestroyable)
HX_DECLARE_CLASS3(flixel,system,debug,ButtonAlignment)
HX_DECLARE_CLASS3(flixel,system,debug,Console)
HX_DECLARE_CLASS3(flixel,system,debug,DebuggerLayout)
HX_DECLARE_CLASS3(flixel,system,debug,FlxDebugger)
HX_DECLARE_CLASS3(flixel,system,debug,Log)
HX_DECLARE_CLASS3(flixel,system,debug,Stats)
HX_DECLARE_CLASS3(flixel,system,debug,VCR)
HX_DECLARE_CLASS3(flixel,system,debug,Watch)
HX_DECLARE_CLASS3(flixel,system,debug,Window)
HX_DECLARE_CLASS3(flixel,system,ui,FlxSystemButton)
namespace flixel{
namespace system{
namespace debug{


class HXCPP_CLASS_ATTRIBUTES  FlxDebugger_obj : public ::flash::display::Sprite_obj{
	public:
		typedef ::flash::display::Sprite_obj super;
		typedef FlxDebugger_obj OBJ_;
		FlxDebugger_obj();
		Void __construct(Float Width,Float Height);

	public:
		inline void *operator new( size_t inSize, bool inContainer=true)
			{ return hx::Object::operator new(inSize,inContainer); }
		static hx::ObjectPtr< FlxDebugger_obj > __new(Float Width,Float Height);
		static Dynamic __CreateEmpty();
		static Dynamic __Create(hx::DynamicArray inArgs);
		//~FlxDebugger_obj();

		HX_DO_RTTI;
		static void __boot();
		static void __register();
		void __Mark(HX_MARK_PARAMS);
		void __Visit(HX_VISIT_PARAMS);
		::String __ToString() const { return HX_CSTRING("FlxDebugger"); }

		::flixel::system::debug::Stats stats;
		::flixel::system::debug::Log log;
		::flixel::system::debug::Watch watch;
		::flixel::system::debug::VCR vcr;
		::flixel::system::debug::Console console;
		bool hasMouse;
		::flixel::system::debug::DebuggerLayout _layout;
		::flash::geom::Point _screen;
		::flash::geom::Rectangle _screenBounds;
		Array< ::Dynamic > _middleButtons;
		Array< ::Dynamic > _leftButtons;
		Array< ::Dynamic > _rightButtons;
		::flash::display::Sprite _topBar;
		virtual Void destroy( );
		Dynamic destroy_dyn();

		virtual Void setLayout( ::flixel::system::debug::DebuggerLayout Layout);
		Dynamic setLayout_dyn();

		virtual Void resetLayout( );
		Dynamic resetLayout_dyn();

		virtual Void onResize( Float Width,Float Height);
		Dynamic onResize_dyn();

		virtual Float hAlignButtons( Array< ::Dynamic > Sprites,hx::Null< Float >  Padding,hx::Null< bool >  Set,hx::Null< Float >  LeftOffset);
		Dynamic hAlignButtons_dyn();

		virtual Void resetButtonLayout( );
		Dynamic resetButtonLayout_dyn();

		virtual ::flixel::system::ui::FlxSystemButton addButton( ::flixel::system::debug::ButtonAlignment Position,::flash::display::BitmapData Icon,Dynamic UpHandler,hx::Null< bool >  ToggleMode,hx::Null< bool >  UpdateLayout);
		Dynamic addButton_dyn();

		virtual Void removeButton( ::flixel::system::ui::FlxSystemButton Button,hx::Null< bool >  UpdateLayout);
		Dynamic removeButton_dyn();

		virtual Void onMouseOver( ::flash::events::MouseEvent E);
		Dynamic onMouseOver_dyn();

		virtual Void onMouseOut( ::flash::events::MouseEvent E);
		Dynamic onMouseOut_dyn();

		virtual Void removeButtonFromArray( Array< ::Dynamic > Arr,::flixel::system::ui::FlxSystemButton Button);
		Dynamic removeButtonFromArray_dyn();

		virtual Void toggleVisualDebug( );
		Dynamic toggleVisualDebug_dyn();

		virtual Void openHomepage( );
		Dynamic openHomepage_dyn();

		static int GUTTER;
		static int TOP_HEIGHT;
};

} // end namespace flixel
} // end namespace system
} // end namespace debug

#endif /* INCLUDED_flixel_system_debug_FlxDebugger */ 
