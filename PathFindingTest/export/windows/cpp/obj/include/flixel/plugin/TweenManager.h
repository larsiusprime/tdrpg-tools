#ifndef INCLUDED_flixel_plugin_TweenManager
#define INCLUDED_flixel_plugin_TweenManager

#ifndef HXCPP_H
#include <hxcpp.h>
#endif

#include <flixel/plugin/FlxPlugin.h>
HX_DECLARE_CLASS1(flixel,FlxBasic)
HX_DECLARE_CLASS2(flixel,interfaces,IFlxDestroyable)
HX_DECLARE_CLASS2(flixel,plugin,FlxPlugin)
HX_DECLARE_CLASS2(flixel,plugin,TweenManager)
HX_DECLARE_CLASS2(flixel,tweens,FlxTween)
namespace flixel{
namespace plugin{


class HXCPP_CLASS_ATTRIBUTES  TweenManager_obj : public ::flixel::plugin::FlxPlugin_obj{
	public:
		typedef ::flixel::plugin::FlxPlugin_obj super;
		typedef TweenManager_obj OBJ_;
		TweenManager_obj();
		Void __construct();

	public:
		inline void *operator new( size_t inSize, bool inContainer=true)
			{ return hx::Object::operator new(inSize,inContainer); }
		static hx::ObjectPtr< TweenManager_obj > __new();
		static Dynamic __CreateEmpty();
		static Dynamic __Create(hx::DynamicArray inArgs);
		//~TweenManager_obj();

		HX_DO_RTTI;
		static void __boot();
		static void __register();
		void __Mark(HX_MARK_PARAMS);
		void __Visit(HX_VISIT_PARAMS);
		::String __ToString() const { return HX_CSTRING("TweenManager"); }

		Array< ::Dynamic > list;
		virtual Void update( );

		virtual ::flixel::tweens::FlxTween add( ::flixel::tweens::FlxTween Tween,hx::Null< bool >  Start);
		Dynamic add_dyn();

		virtual ::flixel::tweens::FlxTween remove( ::flixel::tweens::FlxTween Tween,hx::Null< bool >  Destroy);
		Dynamic remove_dyn();

		virtual Void clear( hx::Null< bool >  Destroy);
		Dynamic clear_dyn();

		virtual Void onStateSwitch( );

};

} // end namespace flixel
} // end namespace plugin

#endif /* INCLUDED_flixel_plugin_TweenManager */ 
