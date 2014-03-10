#ifndef INCLUDED_flixel_system_debug_Console
#define INCLUDED_flixel_system_debug_Console

#ifndef HXCPP_H
#include <hxcpp.h>
#endif

#include <flixel/system/debug/Window.h>
HX_DECLARE_CLASS0(IMap)
HX_DECLARE_CLASS2(flash,display,DisplayObject)
HX_DECLARE_CLASS2(flash,display,DisplayObjectContainer)
HX_DECLARE_CLASS2(flash,display,IBitmapDrawable)
HX_DECLARE_CLASS2(flash,display,InteractiveObject)
HX_DECLARE_CLASS2(flash,display,Sprite)
HX_DECLARE_CLASS2(flash,events,Event)
HX_DECLARE_CLASS2(flash,events,EventDispatcher)
HX_DECLARE_CLASS2(flash,events,FocusEvent)
HX_DECLARE_CLASS2(flash,events,IEventDispatcher)
HX_DECLARE_CLASS2(flash,events,KeyboardEvent)
HX_DECLARE_CLASS2(flash,text,TextField)
HX_DECLARE_CLASS1(flixel,FlxBasic)
HX_DECLARE_CLASS1(flixel,FlxObject)
HX_DECLARE_CLASS2(flixel,interfaces,IFlxDestroyable)
HX_DECLARE_CLASS3(flixel,system,debug,Console)
HX_DECLARE_CLASS3(flixel,system,debug,Window)
HX_DECLARE_CLASS2(haxe,ds,StringMap)
namespace flixel{
namespace system{
namespace debug{


class HXCPP_CLASS_ATTRIBUTES  Console_obj : public ::flixel::system::debug::Window_obj{
	public:
		typedef ::flixel::system::debug::Window_obj super;
		typedef Console_obj OBJ_;
		Console_obj();
		Void __construct();

	public:
		inline void *operator new( size_t inSize, bool inContainer=true)
			{ return hx::Object::operator new(inSize,inContainer); }
		static hx::ObjectPtr< Console_obj > __new();
		static Dynamic __CreateEmpty();
		static Dynamic __Create(hx::DynamicArray inArgs);
		//~Console_obj();

		HX_DO_RTTI;
		static void __boot();
		static void __register();
		void __Mark(HX_MARK_PARAMS);
		void __Visit(HX_VISIT_PARAMS);
		::String __ToString() const { return HX_CSTRING("Console"); }

		::haxe::ds::StringMap registeredObjects;
		::haxe::ds::StringMap registeredFunctions;
		Array< ::Dynamic > objectStack;
		Array< ::String > cmdHistory;
		Dynamic commands;
		int _historyIndex;
		::flash::text::TextField _input;
		virtual Void onFocus( ::flash::events::FocusEvent e);
		Dynamic onFocus_dyn();

		virtual Void onFocusLost( ::flash::events::FocusEvent e);
		Dynamic onFocusLost_dyn();

		virtual Void onKeyPress( ::flash::events::KeyboardEvent e);
		Dynamic onKeyPress_dyn();

		virtual Void processCommand( );
		Dynamic processCommand_dyn();

		virtual Void overrideDefaultSelection( ::flash::events::Event e);
		Dynamic overrideDefaultSelection_dyn();

		virtual ::String getPreviousCommand( );
		Dynamic getPreviousCommand_dyn();

		virtual ::String getNextCommand( );
		Dynamic getNextCommand_dyn();

		virtual Void registerObject( ::String ObjectAlias,Dynamic AnyObject);
		Dynamic registerObject_dyn();

		virtual Void registerFunction( ::String FunctionAlias,Dynamic Function);
		Dynamic registerFunction_dyn();

		virtual Void addCommand( Array< ::String > Aliases,Dynamic ProcessFunction,::String Help,::String ParamHelp,hx::Null< int >  NumParams,hx::Null< int >  ParamCutoff);
		Dynamic addCommand_dyn();

		virtual Void destroy( );

		virtual Void updateSize( );

		static ::String _DEFAULT_TEXT;
		static int _HISTORY_MAX;
};

} // end namespace flixel
} // end namespace system
} // end namespace debug

#endif /* INCLUDED_flixel_system_debug_Console */ 
