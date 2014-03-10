#ifndef INCLUDED_flixel_ui_FlxButton
#define INCLUDED_flixel_ui_FlxButton

#ifndef HXCPP_H
#include <hxcpp.h>
#endif

#include <flixel/ui/FlxTypedButton.h>
HX_DECLARE_CLASS1(flixel,FlxBasic)
HX_DECLARE_CLASS1(flixel,FlxObject)
HX_DECLARE_CLASS1(flixel,FlxSprite)
HX_DECLARE_CLASS2(flixel,interfaces,IFlxDestroyable)
HX_DECLARE_CLASS2(flixel,ui,FlxButton)
HX_DECLARE_CLASS2(flixel,ui,FlxTypedButton)
namespace flixel{
namespace ui{


class HXCPP_CLASS_ATTRIBUTES  FlxButton_obj : public ::flixel::ui::FlxTypedButton_obj{
	public:
		typedef ::flixel::ui::FlxTypedButton_obj super;
		typedef FlxButton_obj OBJ_;
		FlxButton_obj();
		Void __construct(hx::Null< Float >  __o_X,hx::Null< Float >  __o_Y,::String Label,Dynamic OnClick);

	public:
		inline void *operator new( size_t inSize, bool inContainer=true)
			{ return hx::Object::operator new(inSize,inContainer); }
		static hx::ObjectPtr< FlxButton_obj > __new(hx::Null< Float >  __o_X,hx::Null< Float >  __o_Y,::String Label,Dynamic OnClick);
		static Dynamic __CreateEmpty();
		static Dynamic __Create(hx::DynamicArray inArgs);
		//~FlxButton_obj();

		HX_DO_RTTI;
		static void __boot();
		static void __register();
		::String __ToString() const { return HX_CSTRING("FlxButton"); }

		virtual Void resetHelpers( );

		static int NORMAL;
		static int HIGHLIGHT;
		static int PRESSED;
};

} // end namespace flixel
} // end namespace ui

#endif /* INCLUDED_flixel_ui_FlxButton */ 
