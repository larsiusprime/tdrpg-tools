#ifndef INCLUDED_flixel_system_BeepSound
#define INCLUDED_flixel_system_BeepSound

#ifndef HXCPP_H
#include <hxcpp.h>
#endif

#include <flash/media/Sound.h>
HX_DECLARE_CLASS2(flash,events,EventDispatcher)
HX_DECLARE_CLASS2(flash,events,IEventDispatcher)
HX_DECLARE_CLASS2(flash,media,Sound)
HX_DECLARE_CLASS2(flash,media,SoundLoaderContext)
HX_DECLARE_CLASS2(flash,net,URLRequest)
HX_DECLARE_CLASS2(flixel,system,BeepSound)
namespace flixel{
namespace system{


class HXCPP_CLASS_ATTRIBUTES  BeepSound_obj : public ::flash::media::Sound_obj{
	public:
		typedef ::flash::media::Sound_obj super;
		typedef BeepSound_obj OBJ_;
		BeepSound_obj();
		Void __construct(::flash::net::URLRequest stream,::flash::media::SoundLoaderContext context,Dynamic __o_forcePlayAsMusic);

	public:
		inline void *operator new( size_t inSize, bool inContainer=true)
			{ return hx::Object::operator new(inSize,inContainer); }
		static hx::ObjectPtr< BeepSound_obj > __new(::flash::net::URLRequest stream,::flash::media::SoundLoaderContext context,Dynamic __o_forcePlayAsMusic);
		static Dynamic __CreateEmpty();
		static Dynamic __Create(hx::DynamicArray inArgs);
		//~BeepSound_obj();

		HX_DO_RTTI;
		static void __boot();
		static void __register();
		::String __ToString() const { return HX_CSTRING("BeepSound"); }

		static ::String resourceName;
};

} // end namespace flixel
} // end namespace system

#endif /* INCLUDED_flixel_system_BeepSound */ 
