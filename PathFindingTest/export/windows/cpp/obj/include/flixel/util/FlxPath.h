#ifndef INCLUDED_flixel_util_FlxPath
#define INCLUDED_flixel_util_FlxPath

#ifndef HXCPP_H
#include <hxcpp.h>
#endif

HX_DECLARE_CLASS1(flixel,FlxBasic)
HX_DECLARE_CLASS1(flixel,FlxCamera)
HX_DECLARE_CLASS1(flixel,FlxObject)
HX_DECLARE_CLASS2(flixel,interfaces,IFlxDestroyable)
HX_DECLARE_CLASS2(flixel,plugin,FlxPlugin)
HX_DECLARE_CLASS2(flixel,plugin,PathManager)
HX_DECLARE_CLASS2(flixel,util,FlxPath)
HX_DECLARE_CLASS2(flixel,util,FlxPoint)
HX_DECLARE_CLASS2(flixel,util,FlxPool_flixel_util_FlxPath)
namespace flixel{
namespace util{


class HXCPP_CLASS_ATTRIBUTES  FlxPath_obj : public hx::Object{
	public:
		typedef hx::Object super;
		typedef FlxPath_obj OBJ_;
		FlxPath_obj();
		Void __construct();

	public:
		inline void *operator new( size_t inSize, bool inContainer=true)
			{ return hx::Object::operator new(inSize,inContainer); }
		static hx::ObjectPtr< FlxPath_obj > __new();
		static Dynamic __CreateEmpty();
		static Dynamic __Create(hx::DynamicArray inArgs);
		//~FlxPath_obj();

		HX_DO_RTTI;
		static void __boot();
		static void __register();
		void __Mark(HX_MARK_PARAMS);
		void __Visit(HX_VISIT_PARAMS);
		::String __ToString() const { return HX_CSTRING("FlxPath"); }

		Array< ::Dynamic > nodes;
		::flixel::FlxObject object;
		bool usePooling;
		Float speed;
		Float angle;
		bool autoCenter;
		int _nodeIndex;
		int _mode;
		int _inc;
		bool _autoRotate;
		bool paused;
		bool finished;
		Dynamic onComplete;
		Dynamic &onComplete_dyn() { return onComplete;}
		int debugColor;
		Float debugScrollX;
		Float debugScrollY;
		bool ignoreDrawDebug;
		virtual ::flixel::util::FlxPath reset( );
		Dynamic reset_dyn();

		virtual ::flixel::util::FlxPath run( ::flixel::FlxObject Object,Array< ::Dynamic > Nodes,hx::Null< Float >  Speed,hx::Null< int >  Mode,hx::Null< bool >  AutoRotate,hx::Null< bool >  UsePooling);
		Dynamic run_dyn();

		virtual ::flixel::util::FlxPath restart( );
		Dynamic restart_dyn();

		virtual Void setNode( int NodeIndex);
		Dynamic setNode_dyn();

		virtual Void update( );
		Dynamic update_dyn();

		virtual ::flixel::util::FlxPoint advancePath( hx::Null< bool >  Snap);
		Dynamic advancePath_dyn();

		virtual Void abort( );
		Dynamic abort_dyn();

		virtual Void destroy( );
		Dynamic destroy_dyn();

		virtual ::flixel::util::FlxPath add( Float X,Float Y);
		Dynamic add_dyn();

		virtual ::flixel::util::FlxPath addAt( Float X,Float Y,int Index);
		Dynamic addAt_dyn();

		virtual ::flixel::util::FlxPath addPoint( ::flixel::util::FlxPoint Node,hx::Null< bool >  AsReference);
		Dynamic addPoint_dyn();

		virtual ::flixel::util::FlxPath addPointAt( ::flixel::util::FlxPoint Node,int Index,hx::Null< bool >  AsReference);
		Dynamic addPointAt_dyn();

		virtual ::flixel::util::FlxPoint remove( ::flixel::util::FlxPoint Node);
		Dynamic remove_dyn();

		virtual ::flixel::util::FlxPoint removeAt( int Index);
		Dynamic removeAt_dyn();

		virtual ::flixel::util::FlxPoint head( );
		Dynamic head_dyn();

		virtual ::flixel::util::FlxPoint tail( );
		Dynamic tail_dyn();

		virtual Void drawDebug( ::flixel::FlxCamera Camera);
		Dynamic drawDebug_dyn();

		static ::flixel::util::FlxPool_flixel_util_FlxPath pool;
		static ::flixel::util::FlxPath recycle( );
		static Dynamic recycle_dyn();

		static Void put( ::flixel::util::FlxPath path);
		static Dynamic put_dyn();

		static ::flixel::util::FlxPath start( ::flixel::FlxObject Object,Array< ::Dynamic > Nodes,hx::Null< Float >  Speed,hx::Null< int >  Mode,hx::Null< bool >  AutoRotate,hx::Null< bool >  UsePooling);
		static Dynamic start_dyn();

		static int FORWARD;
		static int BACKWARD;
		static int LOOP_FORWARD;
		static int LOOP_BACKWARD;
		static int YOYO;
		static int HORIZONTAL_ONLY;
		static int VERTICAL_ONLY;
		static ::flixel::util::FlxPoint _point;
		static ::flixel::plugin::PathManager manager;
};

} // end namespace flixel
} // end namespace util

#endif /* INCLUDED_flixel_util_FlxPath */ 
