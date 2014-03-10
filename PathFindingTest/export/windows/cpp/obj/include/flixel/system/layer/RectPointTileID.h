#ifndef INCLUDED_flixel_system_layer_RectPointTileID
#define INCLUDED_flixel_system_layer_RectPointTileID

#ifndef HXCPP_H
#include <hxcpp.h>
#endif

HX_DECLARE_CLASS2(flash,geom,Point)
HX_DECLARE_CLASS2(flash,geom,Rectangle)
HX_DECLARE_CLASS3(flixel,system,layer,RectPointTileID)
namespace flixel{
namespace system{
namespace layer{


class HXCPP_CLASS_ATTRIBUTES  RectPointTileID_obj : public hx::Object{
	public:
		typedef hx::Object super;
		typedef RectPointTileID_obj OBJ_;
		RectPointTileID_obj();
		Void __construct(int id,::flash::geom::Rectangle rect,::flash::geom::Point point);

	public:
		inline void *operator new( size_t inSize, bool inContainer=true)
			{ return hx::Object::operator new(inSize,inContainer); }
		static hx::ObjectPtr< RectPointTileID_obj > __new(int id,::flash::geom::Rectangle rect,::flash::geom::Point point);
		static Dynamic __CreateEmpty();
		static Dynamic __Create(hx::DynamicArray inArgs);
		//~RectPointTileID_obj();

		HX_DO_RTTI;
		static void __boot();
		static void __register();
		void __Mark(HX_MARK_PARAMS);
		void __Visit(HX_VISIT_PARAMS);
		::String __ToString() const { return HX_CSTRING("RectPointTileID"); }

		::flash::geom::Rectangle rect;
		::flash::geom::Point point;
		int id;
		virtual Void destroy( );
		Dynamic destroy_dyn();

};

} // end namespace flixel
} // end namespace system
} // end namespace layer

#endif /* INCLUDED_flixel_system_layer_RectPointTileID */ 
