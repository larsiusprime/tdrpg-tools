#ifndef INCLUDED_flixel_system_debug_StatsGraph
#define INCLUDED_flixel_system_debug_StatsGraph

#ifndef HXCPP_H
#include <hxcpp.h>
#endif

#include <flash/display/Sprite.h>
HX_DECLARE_CLASS2(flash,display,DisplayObject)
HX_DECLARE_CLASS2(flash,display,DisplayObjectContainer)
HX_DECLARE_CLASS2(flash,display,IBitmapDrawable)
HX_DECLARE_CLASS2(flash,display,InteractiveObject)
HX_DECLARE_CLASS2(flash,display,Shape)
HX_DECLARE_CLASS2(flash,display,Sprite)
HX_DECLARE_CLASS2(flash,events,EventDispatcher)
HX_DECLARE_CLASS2(flash,events,IEventDispatcher)
HX_DECLARE_CLASS2(flash,text,TextField)
HX_DECLARE_CLASS3(flixel,system,debug,StatsGraph)
namespace flixel{
namespace system{
namespace debug{


class HXCPP_CLASS_ATTRIBUTES  StatsGraph_obj : public ::flash::display::Sprite_obj{
	public:
		typedef ::flash::display::Sprite_obj super;
		typedef StatsGraph_obj OBJ_;
		StatsGraph_obj();
		Void __construct(int X,int Y,int Width,int Height,int GraphColor,::String Unit);

	public:
		inline void *operator new( size_t inSize, bool inContainer=true)
			{ return hx::Object::operator new(inSize,inContainer); }
		static hx::ObjectPtr< StatsGraph_obj > __new(int X,int Y,int Width,int Height,int GraphColor,::String Unit);
		static Dynamic __CreateEmpty();
		static Dynamic __Create(hx::DynamicArray inArgs);
		//~StatsGraph_obj();

		HX_DO_RTTI;
		static void __boot();
		static void __register();
		void __Mark(HX_MARK_PARAMS);
		void __Visit(HX_VISIT_PARAMS);
		::String __ToString() const { return HX_CSTRING("StatsGraph"); }

		::flash::display::Shape _axis;
		int _axisWidth;
		int _width;
		int _height;
		::String _unit;
		::flash::text::TextField minLabel;
		::flash::text::TextField curLabel;
		::flash::text::TextField maxLabel;
		::flash::text::TextField avgLabel;
		Float minValue;
		Float maxValue;
		int graphColor;
		Array< Float > history;
		virtual Void drawAxis( );
		Dynamic drawAxis_dyn();

		virtual Void drawGraph( );
		Dynamic drawGraph_dyn();

		virtual Void update( Float Value,Dynamic Average);
		Dynamic update_dyn();

		virtual Float average( );
		Dynamic average_dyn();

		virtual Void destroy( );
		Dynamic destroy_dyn();

		static int AXIS_COLOR;
		static Float AXIS_ALPHA;
		static int LABEL_WIDTH;
		static int HISTORY_MAX;
};

} // end namespace flixel
} // end namespace system
} // end namespace debug

#endif /* INCLUDED_flixel_system_debug_StatsGraph */ 
