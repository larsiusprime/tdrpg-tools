#ifndef INCLUDED_Seeker
#define INCLUDED_Seeker

#ifndef HXCPP_H
#include <hxcpp.h>
#endif

#include <flixel/FlxSprite.h>
HX_DECLARE_CLASS0(Seeker)
HX_DECLARE_CLASS1(flixel,FlxBasic)
HX_DECLARE_CLASS1(flixel,FlxObject)
HX_DECLARE_CLASS1(flixel,FlxSprite)
HX_DECLARE_CLASS2(flixel,interfaces,IFlxDestroyable)
HX_DECLARE_CLASS2(flixel,util,FlxPoint)
HX_DECLARE_CLASS2(flixel,util,FlxVector)


class HXCPP_CLASS_ATTRIBUTES  Seeker_obj : public ::flixel::FlxSprite_obj{
	public:
		typedef ::flixel::FlxSprite_obj super;
		typedef Seeker_obj OBJ_;
		Seeker_obj();
		Void __construct(Float X,Float Y,Dynamic SimpleGraphic);

	public:
		inline void *operator new( size_t inSize, bool inContainer=true)
			{ return hx::Object::operator new(inSize,inContainer); }
		static hx::ObjectPtr< Seeker_obj > __new(Float X,Float Y,Dynamic SimpleGraphic);
		static Dynamic __CreateEmpty();
		static Dynamic __Create(hx::DynamicArray inArgs);
		//~Seeker_obj();

		HX_DO_RTTI;
		static void __boot();
		static void __register();
		void __Mark(HX_MARK_PARAMS);
		void __Visit(HX_VISIT_PARAMS);
		::String __ToString() const { return HX_CSTRING("Seeker"); }

		bool moving;
		::flixel::util::FlxPoint dest;
		::flixel::util::FlxVector vec;
		virtual Void moveTo( Float X,Float Y,Float Time);
		Dynamic moveTo_dyn();

		virtual Void finishMoveTo( );
		Dynamic finishMoveTo_dyn();

		virtual Void update( );

		virtual int signOf( Float f);
		Dynamic signOf_dyn();

};


#endif /* INCLUDED_Seeker */ 
