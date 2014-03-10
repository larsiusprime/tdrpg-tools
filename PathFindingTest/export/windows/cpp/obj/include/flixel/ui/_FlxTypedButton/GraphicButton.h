#ifndef INCLUDED_flixel_ui__FlxTypedButton_GraphicButton
#define INCLUDED_flixel_ui__FlxTypedButton_GraphicButton

#ifndef HXCPP_H
#include <hxcpp.h>
#endif

#include <flash/display/BitmapData.h>
HX_DECLARE_CLASS2(flash,display,BitmapData)
HX_DECLARE_CLASS2(flash,display,IBitmapDrawable)
HX_DECLARE_CLASS3(flixel,ui,_FlxTypedButton,GraphicButton)
namespace flixel{
namespace ui{
namespace _FlxTypedButton{


class HXCPP_CLASS_ATTRIBUTES  GraphicButton_obj : public ::flash::display::BitmapData_obj{
	public:
		typedef ::flash::display::BitmapData_obj super;
		typedef GraphicButton_obj OBJ_;
		GraphicButton_obj();
		Void __construct(int width,int height,Dynamic __o_transparent,Dynamic __o_fillRGBA);

	public:
		inline void *operator new( size_t inSize, bool inContainer=true)
			{ return hx::Object::operator new(inSize,inContainer); }
		static hx::ObjectPtr< GraphicButton_obj > __new(int width,int height,Dynamic __o_transparent,Dynamic __o_fillRGBA);
		static Dynamic __CreateEmpty();
		static Dynamic __Create(hx::DynamicArray inArgs);
		//~GraphicButton_obj();

		HX_DO_RTTI;
		static void __boot();
		static void __register();
		::String __ToString() const { return HX_CSTRING("GraphicButton"); }

		static ::String resourceName;
};

} // end namespace flixel
} // end namespace ui
} // end namespace _FlxTypedButton

#endif /* INCLUDED_flixel_ui__FlxTypedButton_GraphicButton */ 
