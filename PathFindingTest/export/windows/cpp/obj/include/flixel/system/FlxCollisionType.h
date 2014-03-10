#ifndef INCLUDED_flixel_system_FlxCollisionType
#define INCLUDED_flixel_system_FlxCollisionType

#ifndef HXCPP_H
#include <hxcpp.h>
#endif

HX_DECLARE_CLASS2(flixel,system,FlxCollisionType)
namespace flixel{
namespace system{


class FlxCollisionType_obj : public hx::EnumBase_obj
{
	typedef hx::EnumBase_obj super;
		typedef FlxCollisionType_obj OBJ_;

	public:
		FlxCollisionType_obj() {};
		HX_DO_ENUM_RTTI;
		static void __boot();
		static void __register();
		::String GetEnumName( ) const { return HX_CSTRING("flixel.system.FlxCollisionType"); }
		::String __ToString() const { return HX_CSTRING("FlxCollisionType.") + tag; }

		static ::flixel::system::FlxCollisionType GROUP;
		static inline ::flixel::system::FlxCollisionType GROUP_dyn() { return GROUP; }
		static ::flixel::system::FlxCollisionType NONE;
		static inline ::flixel::system::FlxCollisionType NONE_dyn() { return NONE; }
		static ::flixel::system::FlxCollisionType OBJECT;
		static inline ::flixel::system::FlxCollisionType OBJECT_dyn() { return OBJECT; }
		static ::flixel::system::FlxCollisionType SPRITEGROUP;
		static inline ::flixel::system::FlxCollisionType SPRITEGROUP_dyn() { return SPRITEGROUP; }
		static ::flixel::system::FlxCollisionType TILEMAP;
		static inline ::flixel::system::FlxCollisionType TILEMAP_dyn() { return TILEMAP; }
};

} // end namespace flixel
} // end namespace system

#endif /* INCLUDED_flixel_system_FlxCollisionType */ 
