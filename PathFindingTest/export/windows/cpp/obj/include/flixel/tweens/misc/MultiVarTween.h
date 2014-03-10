#ifndef INCLUDED_flixel_tweens_misc_MultiVarTween
#define INCLUDED_flixel_tweens_misc_MultiVarTween

#ifndef HXCPP_H
#include <hxcpp.h>
#endif

#include <flixel/tweens/FlxTween.h>
HX_DECLARE_CLASS2(flixel,interfaces,IFlxDestroyable)
HX_DECLARE_CLASS2(flixel,tweens,FlxTween)
HX_DECLARE_CLASS3(flixel,tweens,misc,MultiVarTween)
namespace flixel{
namespace tweens{
namespace misc{


class HXCPP_CLASS_ATTRIBUTES  MultiVarTween_obj : public ::flixel::tweens::FlxTween_obj{
	public:
		typedef ::flixel::tweens::FlxTween_obj super;
		typedef MultiVarTween_obj OBJ_;
		MultiVarTween_obj();
		Void __construct(Dynamic complete,hx::Null< int >  __o_type);

	public:
		inline void *operator new( size_t inSize, bool inContainer=true)
			{ return hx::Object::operator new(inSize,inContainer); }
		static hx::ObjectPtr< MultiVarTween_obj > __new(Dynamic complete,hx::Null< int >  __o_type);
		static Dynamic __CreateEmpty();
		static Dynamic __Create(hx::DynamicArray inArgs);
		//~MultiVarTween_obj();

		HX_DO_RTTI;
		static void __boot();
		static void __register();
		void __Mark(HX_MARK_PARAMS);
		void __Visit(HX_VISIT_PARAMS);
		::String __ToString() const { return HX_CSTRING("MultiVarTween"); }

		Dynamic _object;
		Dynamic _properties;
		Array< ::String > _vars;
		Array< Float > _start;
		Array< Float > _range;
		virtual Void destroy( );

		virtual ::flixel::tweens::misc::MultiVarTween tween( Dynamic object,Dynamic properties,Float duration,Dynamic ease);
		Dynamic tween_dyn();

		virtual Void update( );

		virtual Void initialize( );
		Dynamic initialize_dyn();

};

} // end namespace flixel
} // end namespace tweens
} // end namespace misc

#endif /* INCLUDED_flixel_tweens_misc_MultiVarTween */ 
