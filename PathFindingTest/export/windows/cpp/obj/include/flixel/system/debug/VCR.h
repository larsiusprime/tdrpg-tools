#ifndef INCLUDED_flixel_system_debug_VCR
#define INCLUDED_flixel_system_debug_VCR

#ifndef HXCPP_H
#include <hxcpp.h>
#endif

HX_DECLARE_CLASS2(flash,display,DisplayObject)
HX_DECLARE_CLASS2(flash,display,DisplayObjectContainer)
HX_DECLARE_CLASS2(flash,display,IBitmapDrawable)
HX_DECLARE_CLASS2(flash,display,InteractiveObject)
HX_DECLARE_CLASS2(flash,display,Sprite)
HX_DECLARE_CLASS2(flash,events,EventDispatcher)
HX_DECLARE_CLASS2(flash,events,IEventDispatcher)
HX_DECLARE_CLASS2(flash,text,TextField)
HX_DECLARE_CLASS2(flixel,interfaces,IFlxDestroyable)
HX_DECLARE_CLASS3(flixel,system,debug,FlxDebugger)
HX_DECLARE_CLASS3(flixel,system,debug,VCR)
HX_DECLARE_CLASS3(flixel,system,ui,FlxSystemButton)
namespace flixel{
namespace system{
namespace debug{


class HXCPP_CLASS_ATTRIBUTES  VCR_obj : public hx::Object{
	public:
		typedef hx::Object super;
		typedef VCR_obj OBJ_;
		VCR_obj();
		Void __construct(::flixel::system::debug::FlxDebugger Debugger);

	public:
		inline void *operator new( size_t inSize, bool inContainer=true)
			{ return hx::Object::operator new(inSize,inContainer); }
		static hx::ObjectPtr< VCR_obj > __new(::flixel::system::debug::FlxDebugger Debugger);
		static Dynamic __CreateEmpty();
		static Dynamic __Create(hx::DynamicArray inArgs);
		//~VCR_obj();

		HX_DO_RTTI;
		static void __boot();
		static void __register();
		void __Mark(HX_MARK_PARAMS);
		void __Visit(HX_VISIT_PARAMS);
		::String __ToString() const { return HX_CSTRING("VCR"); }

		::flash::text::TextField runtimeDisplay;
		int runtime;
		::flixel::system::ui::FlxSystemButton playbackToggleBtn;
		::flixel::system::ui::FlxSystemButton stepBtn;
		::flixel::system::ui::FlxSystemButton restartBtn;
		::flixel::system::ui::FlxSystemButton recordBtn;
		::flixel::system::ui::FlxSystemButton openBtn;
		virtual Void onPause( );
		Dynamic onPause_dyn();

		virtual Void onResume( );
		Dynamic onResume_dyn();

		virtual Void onStep( );
		Dynamic onStep_dyn();

};

} // end namespace flixel
} // end namespace system
} // end namespace debug

#endif /* INCLUDED_flixel_system_debug_VCR */ 
