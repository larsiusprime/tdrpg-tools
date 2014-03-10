#ifndef INCLUDED_PlayState
#define INCLUDED_PlayState

#ifndef HXCPP_H
#include <hxcpp.h>
#endif

#include <flixel/FlxState.h>
HX_DECLARE_CLASS0(PlayState)
HX_DECLARE_CLASS1(flixel,FlxBasic)
HX_DECLARE_CLASS1(flixel,FlxObject)
HX_DECLARE_CLASS1(flixel,FlxSprite)
HX_DECLARE_CLASS1(flixel,FlxState)
HX_DECLARE_CLASS2(flixel,group,FlxGroup)
HX_DECLARE_CLASS2(flixel,group,FlxTypedGroup)
HX_DECLARE_CLASS2(flixel,interfaces,IFlxDestroyable)
HX_DECLARE_CLASS2(flixel,tile,FlxTilemap)
HX_DECLARE_CLASS2(flixel,util,FlxPoint)


class HXCPP_CLASS_ATTRIBUTES  PlayState_obj : public ::flixel::FlxState_obj{
	public:
		typedef ::flixel::FlxState_obj super;
		typedef PlayState_obj OBJ_;
		PlayState_obj();
		Void __construct(Dynamic MaxSize);

	public:
		inline void *operator new( size_t inSize, bool inContainer=true)
			{ return hx::Object::operator new(inSize,inContainer); }
		static hx::ObjectPtr< PlayState_obj > __new(Dynamic MaxSize);
		static Dynamic __CreateEmpty();
		static Dynamic __Create(hx::DynamicArray inArgs);
		//~PlayState_obj();

		HX_DO_RTTI;
		static void __boot();
		static void __register();
		void __Mark(HX_MARK_PARAMS);
		void __Visit(HX_VISIT_PARAMS);
		::String __ToString() const { return HX_CSTRING("PlayState"); }

		::flixel::tile::FlxTilemap tilemap;
		::flixel::tile::FlxTilemap distmap;
		Array< int > distances;
		::flixel::util::FlxPoint mcguffin;
		::flixel::FlxSprite mcguffinSprite;
		int SPEED;
		::flixel::group::FlxGroup group_seekers;
		virtual Void create( );

		virtual Void destroy( );

		virtual Void update( );

		virtual Void updateSeekers( );
		Dynamic updateSeekers_dyn();

		virtual Void placeSeeker( );
		Dynamic placeSeeker_dyn();

		virtual Void placeMcguffin( Float X,Float Y);
		Dynamic placeMcguffin_dyn();

		virtual Void updateDistance( );
		Dynamic updateDistance_dyn();

		virtual Void clickTile( int value);
		Dynamic clickTile_dyn();

		virtual Void makeTiles( );
		Dynamic makeTiles_dyn();

};


#endif /* INCLUDED_PlayState */ 
