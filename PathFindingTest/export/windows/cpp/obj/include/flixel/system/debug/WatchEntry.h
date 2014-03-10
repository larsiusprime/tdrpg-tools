#ifndef INCLUDED_flixel_system_debug_WatchEntry
#define INCLUDED_flixel_system_debug_WatchEntry

#ifndef HXCPP_H
#include <hxcpp.h>
#endif

HX_DECLARE_CLASS2(flash,display,DisplayObject)
HX_DECLARE_CLASS2(flash,display,IBitmapDrawable)
HX_DECLARE_CLASS2(flash,display,InteractiveObject)
HX_DECLARE_CLASS2(flash,events,Event)
HX_DECLARE_CLASS2(flash,events,EventDispatcher)
HX_DECLARE_CLASS2(flash,events,IEventDispatcher)
HX_DECLARE_CLASS2(flash,events,KeyboardEvent)
HX_DECLARE_CLASS2(flash,events,MouseEvent)
HX_DECLARE_CLASS2(flash,text,TextField)
HX_DECLARE_CLASS2(flash,text,TextFormat)
HX_DECLARE_CLASS3(flixel,system,debug,WatchEntry)
namespace flixel{
namespace system{
namespace debug{


class HXCPP_CLASS_ATTRIBUTES  WatchEntry_obj : public hx::Object{
	public:
		typedef hx::Object super;
		typedef WatchEntry_obj OBJ_;
		WatchEntry_obj();
		Void __construct(Float Y,Float NameWidth,Float ValueWidth,Dynamic Obj,::String Field,::String Custom);

	public:
		inline void *operator new( size_t inSize, bool inContainer=true)
			{ return hx::Object::operator new(inSize,inContainer); }
		static hx::ObjectPtr< WatchEntry_obj > __new(Float Y,Float NameWidth,Float ValueWidth,Dynamic Obj,::String Field,::String Custom);
		static Dynamic __CreateEmpty();
		static Dynamic __Create(hx::DynamicArray inArgs);
		//~WatchEntry_obj();

		HX_DO_RTTI;
		static void __boot();
		static void __register();
		void __Mark(HX_MARK_PARAMS);
		void __Visit(HX_VISIT_PARAMS);
		::String __ToString() const { return HX_CSTRING("WatchEntry"); }

		Dynamic object;
		::String field;
		::String custom;
		::flash::text::TextField nameDisplay;
		::flash::text::TextField valueDisplay;
		bool editing;
		Dynamic oldValue;
		::flash::text::TextFormat _whiteText;
		::flash::text::TextFormat _blackText;
		bool quickWatch;
		virtual Void destroy( );
		Dynamic destroy_dyn();

		virtual Void setY( Float Y);
		Dynamic setY_dyn();

		virtual Void updateWidth( Float NameWidth,Float ValueWidth);
		Dynamic updateWidth_dyn();

		virtual bool updateValue( );
		Dynamic updateValue_dyn();

		virtual Void onMouseUp( ::flash::events::MouseEvent FlashEvent);
		Dynamic onMouseUp_dyn();

		virtual Void onKeyUp( ::flash::events::KeyboardEvent FlashEvent);
		Dynamic onKeyUp_dyn();

		virtual Void cancel( );
		Dynamic cancel_dyn();

		virtual Void submit( );
		Dynamic submit_dyn();

		virtual Void doneEditing( );
		Dynamic doneEditing_dyn();

};

} // end namespace flixel
} // end namespace system
} // end namespace debug

#endif /* INCLUDED_flixel_system_debug_WatchEntry */ 
