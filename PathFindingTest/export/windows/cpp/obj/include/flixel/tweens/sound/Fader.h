#ifndef INCLUDED_flixel_tweens_sound_Fader
#define INCLUDED_flixel_tweens_sound_Fader

#ifndef HXCPP_H
#include <hxcpp.h>
#endif

#include <flixel/tweens/FlxTween.h>
HX_DECLARE_CLASS2(flixel,interfaces,IFlxDestroyable)
HX_DECLARE_CLASS2(flixel,tweens,FlxTween)
HX_DECLARE_CLASS3(flixel,tweens,sound,Fader)
namespace flixel{
namespace tweens{
namespace sound{


class HXCPP_CLASS_ATTRIBUTES  Fader_obj : public ::flixel::tweens::FlxTween_obj{
	public:
		typedef ::flixel::tweens::FlxTween_obj super;
		typedef Fader_obj OBJ_;
		Fader_obj();
		Void __construct(Dynamic complete,hx::Null< int >  __o_type);

	public:
		inline void *operator new( size_t inSize, bool inContainer=true)
			{ return hx::Object::operator new(inSize,inContainer); }
		static hx::ObjectPtr< Fader_obj > __new(Dynamic complete,hx::Null< int >  __o_type);
		static Dynamic __CreateEmpty();
		static Dynamic __Create(hx::DynamicArray inArgs);
		//~Fader_obj();

		HX_DO_RTTI;
		static void __boot();
		static void __register();
		::String __ToString() const { return HX_CSTRING("Fader"); }

		Float _start;
		Float _range;
		virtual Void fadeTo( Float volume,Float duration,Dynamic ease);
		Dynamic fadeTo_dyn();

		virtual Void update( );

};

} // end namespace flixel
} // end namespace tweens
} // end namespace sound

#endif /* INCLUDED_flixel_tweens_sound_Fader */ 
