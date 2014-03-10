#ifndef INCLUDED_flixel_util_FlxVector
#define INCLUDED_flixel_util_FlxVector

#ifndef HXCPP_H
#include <hxcpp.h>
#endif

#include <flixel/util/FlxPoint.h>
HX_DECLARE_CLASS2(flixel,interfaces,IFlxDestroyable)
HX_DECLARE_CLASS2(flixel,util,FlxPoint)
HX_DECLARE_CLASS2(flixel,util,FlxVector)
namespace flixel{
namespace util{


class HXCPP_CLASS_ATTRIBUTES  FlxVector_obj : public ::flixel::util::FlxPoint_obj{
	public:
		typedef ::flixel::util::FlxPoint_obj super;
		typedef FlxVector_obj OBJ_;
		FlxVector_obj();
		Void __construct(hx::Null< Float >  __o_X,hx::Null< Float >  __o_Y);

	public:
		inline void *operator new( size_t inSize, bool inContainer=false)
			{ return hx::Object::operator new(inSize,inContainer); }
		static hx::ObjectPtr< FlxVector_obj > __new(hx::Null< Float >  __o_X,hx::Null< Float >  __o_Y);
		static Dynamic __CreateEmpty();
		static Dynamic __Create(hx::DynamicArray inArgs);
		//~FlxVector_obj();

		HX_DO_RTTI;
		static void __boot();
		static void __register();
		::String __ToString() const { return HX_CSTRING("FlxVector"); }

		virtual ::flixel::util::FlxPoint set( hx::Null< Float >  X,hx::Null< Float >  Y);

		virtual ::flixel::util::FlxVector scale( Float k);
		Dynamic scale_dyn();

		virtual ::flixel::util::FlxVector scaleNew( Float k);
		Dynamic scaleNew_dyn();

		virtual ::flixel::util::FlxVector add( ::flixel::util::FlxVector v);
		Dynamic add_dyn();

		virtual ::flixel::util::FlxVector addNew( ::flixel::util::FlxVector v);
		Dynamic addNew_dyn();

		virtual ::flixel::util::FlxVector substract( ::flixel::util::FlxVector v);
		Dynamic substract_dyn();

		virtual ::flixel::util::FlxVector substractNew( ::flixel::util::FlxVector v);
		Dynamic substractNew_dyn();

		virtual Float dotProduct( ::flixel::util::FlxVector v);
		Dynamic dotProduct_dyn();

		virtual Float dotProdWithNormalizing( ::flixel::util::FlxVector v);
		Dynamic dotProdWithNormalizing_dyn();

		virtual bool isPerpendicular( ::flixel::util::FlxVector v);
		Dynamic isPerpendicular_dyn();

		virtual Float crossProductLength( ::flixel::util::FlxVector v);
		Dynamic crossProductLength_dyn();

		virtual bool isParallel( ::flixel::util::FlxVector v);
		Dynamic isParallel_dyn();

		virtual bool isZero( );
		Dynamic isZero_dyn();

		virtual ::flixel::util::FlxVector zero( );
		Dynamic zero_dyn();

		virtual ::flixel::util::FlxVector normalize( );
		Dynamic normalize_dyn();

		virtual Float get_dx( );
		Dynamic get_dx_dyn();

		virtual Float get_dy( );
		Dynamic get_dy_dyn();

		virtual bool isNormalized( );
		Dynamic isNormalized_dyn();

		virtual bool equals( ::flixel::util::FlxVector v);
		Dynamic equals_dyn();

		virtual Float get_length( );
		Dynamic get_length_dyn();

		virtual Float set_length( Float l);
		Dynamic set_length_dyn();

		virtual Float get_lengthSquared( );
		Dynamic get_lengthSquared_dyn();

		virtual Float get_degrees( );
		Dynamic get_degrees_dyn();

		virtual Float set_degrees( Float degs);
		Dynamic set_degrees_dyn();

		virtual Float get_radians( );
		Dynamic get_radians_dyn();

		virtual Float set_radians( Float rads);
		Dynamic set_radians_dyn();

		virtual ::flixel::util::FlxVector rotateByRadians( Float rads);
		Dynamic rotateByRadians_dyn();

		virtual ::flixel::util::FlxVector rotateByDegrees( Float degs);
		Dynamic rotateByDegrees_dyn();

		virtual ::flixel::util::FlxVector rotateWithTrig( Float sin,Float cos);
		Dynamic rotateWithTrig_dyn();

		virtual ::flixel::util::FlxVector rightNormal( ::flixel::util::FlxVector vec);
		Dynamic rightNormal_dyn();

		virtual Float get_rx( );
		Dynamic get_rx_dyn();

		virtual Float get_ry( );
		Dynamic get_ry_dyn();

		virtual ::flixel::util::FlxVector leftNormal( ::flixel::util::FlxVector vec);
		Dynamic leftNormal_dyn();

		virtual Float get_lx( );
		Dynamic get_lx_dyn();

		virtual Float get_ly( );
		Dynamic get_ly_dyn();

		virtual ::flixel::util::FlxVector negate( );
		Dynamic negate_dyn();

		virtual ::flixel::util::FlxVector negateNew( );
		Dynamic negateNew_dyn();

		virtual ::flixel::util::FlxVector projectTo( ::flixel::util::FlxVector v,::flixel::util::FlxVector proj);
		Dynamic projectTo_dyn();

		virtual ::flixel::util::FlxVector projectToNormalized( ::flixel::util::FlxVector v,::flixel::util::FlxVector proj);
		Dynamic projectToNormalized_dyn();

		virtual Float perpProduct( ::flixel::util::FlxVector v);
		Dynamic perpProduct_dyn();

		virtual Float ratio( ::flixel::util::FlxVector a,::flixel::util::FlxVector b,::flixel::util::FlxVector v);
		Dynamic ratio_dyn();

		virtual ::flixel::util::FlxVector findIntersection( ::flixel::util::FlxVector a,::flixel::util::FlxVector b,::flixel::util::FlxVector v,::flixel::util::FlxVector intersection);
		Dynamic findIntersection_dyn();

		virtual ::flixel::util::FlxVector findIntersectionInBounds( ::flixel::util::FlxVector a,::flixel::util::FlxVector b,::flixel::util::FlxVector v,::flixel::util::FlxVector intersection);
		Dynamic findIntersectionInBounds_dyn();

		virtual ::flixel::util::FlxVector truncate( Float max);
		Dynamic truncate_dyn();

		virtual Float radiansBetween( ::flixel::util::FlxVector v);
		Dynamic radiansBetween_dyn();

		virtual Float degreesBetween( ::flixel::util::FlxVector v);
		Dynamic degreesBetween_dyn();

		virtual int sign( ::flixel::util::FlxVector a,::flixel::util::FlxVector b);
		Dynamic sign_dyn();

		virtual Float dist( ::flixel::util::FlxVector v);
		Dynamic dist_dyn();

		virtual Float distSquared( ::flixel::util::FlxVector v);
		Dynamic distSquared_dyn();

		virtual ::flixel::util::FlxVector bounce( ::flixel::util::FlxVector normal,hx::Null< Float >  bounceCoeff);
		Dynamic bounce_dyn();

		virtual ::flixel::util::FlxVector bounceWithFriction( ::flixel::util::FlxVector normal,hx::Null< Float >  bounceCoeff,hx::Null< Float >  friction);
		Dynamic bounceWithFriction_dyn();

		virtual bool isValid( );
		Dynamic isValid_dyn();

		virtual ::flixel::util::FlxVector clone( ::flixel::util::FlxVector vec);
		Dynamic clone_dyn();

		static Float EPSILON;
		static Float EPSILON_SQUARED;
		static ::flixel::util::FlxVector _vector1;
		static ::flixel::util::FlxVector _vector2;
		static ::flixel::util::FlxVector _vector3;
};

} // end namespace flixel
} // end namespace util

#endif /* INCLUDED_flixel_util_FlxVector */ 
