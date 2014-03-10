#include <hxcpp.h>

#ifndef INCLUDED_Std
#include <Std.h>
#endif
#ifndef INCLUDED_StringTools
#include <StringTools.h>
#endif
#ifndef INCLUDED_Type
#include <Type.h>
#endif
#ifndef INCLUDED_flixel_FlxBasic
#include <flixel/FlxBasic.h>
#endif
#ifndef INCLUDED_flixel_interfaces_IFlxDestroyable
#include <flixel/interfaces/IFlxDestroyable.h>
#endif
#ifndef INCLUDED_flixel_plugin_FlxPlugin
#include <flixel/plugin/FlxPlugin.h>
#endif
#ifndef INCLUDED_flixel_plugin_PathManager
#include <flixel/plugin/PathManager.h>
#endif
#ifndef INCLUDED_flixel_plugin_TimerManager
#include <flixel/plugin/TimerManager.h>
#endif
#ifndef INCLUDED_flixel_plugin_TweenManager
#include <flixel/plugin/TweenManager.h>
#endif
#ifndef INCLUDED_flixel_system_frontEnds_PluginFrontEnd
#include <flixel/system/frontEnds/PluginFrontEnd.h>
#endif
#ifndef INCLUDED_flixel_tweens_FlxTween
#include <flixel/tweens/FlxTween.h>
#endif
#ifndef INCLUDED_flixel_util_FlxPath
#include <flixel/util/FlxPath.h>
#endif
#ifndef INCLUDED_flixel_util_FlxTimer
#include <flixel/util/FlxTimer.h>
#endif
namespace flixel{
namespace system{
namespace frontEnds{

Void PluginFrontEnd_obj::__construct()
{
HX_STACK_FRAME("flixel.system.frontEnds.PluginFrontEnd","new",0x6ca9c2b1,"flixel.system.frontEnds.PluginFrontEnd.new","flixel/system/frontEnds/PluginFrontEnd.hx",116,0xbff70e9e)
{
	HX_STACK_LINE(117)
	this->list = Array_obj< ::Dynamic >::__new();
	HX_STACK_LINE(119)
	this->add_flixel_plugin_TimerManager(::flixel::util::FlxTimer_obj::manager = ::flixel::plugin::TimerManager_obj::__new());
	HX_STACK_LINE(120)
	this->add_flixel_plugin_TweenManager(::flixel::tweens::FlxTween_obj::manager = ::flixel::plugin::TweenManager_obj::__new());
	HX_STACK_LINE(121)
	this->add_flixel_plugin_PathManager(::flixel::util::FlxPath_obj::manager = ::flixel::plugin::PathManager_obj::__new());
}
;
	return null();
}

//PluginFrontEnd_obj::~PluginFrontEnd_obj() { }

Dynamic PluginFrontEnd_obj::__CreateEmpty() { return  new PluginFrontEnd_obj; }
hx::ObjectPtr< PluginFrontEnd_obj > PluginFrontEnd_obj::__new()
{  hx::ObjectPtr< PluginFrontEnd_obj > result = new PluginFrontEnd_obj();
	result->__construct();
	return result;}

Dynamic PluginFrontEnd_obj::__Create(hx::DynamicArray inArgs)
{  hx::ObjectPtr< PluginFrontEnd_obj > result = new PluginFrontEnd_obj();
	result->__construct();
	return result;}

::flixel::plugin::PathManager PluginFrontEnd_obj::add_flixel_plugin_PathManager( ::flixel::plugin::PathManager Plugin){
	HX_STACK_FRAME("flixel.system.frontEnds.PluginFrontEnd","add_flixel_plugin_PathManager",0x40533852,"flixel.system.frontEnds.PluginFrontEnd.add_flixel_plugin_PathManager","flixel/system/frontEnds/PluginFrontEnd.hx",27,0xbff70e9e)
	HX_STACK_THIS(this)
	HX_STACK_ARG(Plugin,"Plugin")
	HX_STACK_LINE(29)
	{
		HX_STACK_LINE(29)
		int _g = (int)0;		HX_STACK_VAR(_g,"_g");
		HX_STACK_LINE(29)
		Array< ::Dynamic > _g1 = this->list;		HX_STACK_VAR(_g1,"_g1");
		HX_STACK_LINE(29)
		while(((_g < _g1->length))){
			HX_STACK_LINE(29)
			::flixel::plugin::FlxPlugin plugin = _g1->__get(_g).StaticCast< ::flixel::plugin::FlxPlugin >();		HX_STACK_VAR(plugin,"plugin");
			HX_STACK_LINE(29)
			++(_g);
			struct _Function_3_1{
				inline static bool Block( ::flixel::plugin::PathManager &Plugin,::flixel::plugin::FlxPlugin &plugin){
					HX_STACK_FRAME("*","closure",0x5bdab937,"*.closure","flixel/system/frontEnds/PluginFrontEnd.hx",31,0xbff70e9e)
					{
						HX_STACK_LINE(31)
						bool Simple = true;		HX_STACK_VAR(Simple,"Simple");
						HX_STACK_LINE(31)
						::String _g2;		HX_STACK_VAR(_g2,"_g2");
						HX_STACK_LINE(31)
						{
							HX_STACK_LINE(31)
							::Class cl;		HX_STACK_VAR(cl,"cl");
							HX_STACK_LINE(31)
							if ((::Std_obj::is(Plugin,hx::ClassOf< ::Class >()))){
								HX_STACK_LINE(31)
								cl = Plugin;
							}
							else{
								HX_STACK_LINE(31)
								cl = ::Type_obj::getClass(Plugin);
							}
							HX_STACK_LINE(31)
							::String s = ::Type_obj::getClassName(cl);		HX_STACK_VAR(s,"s");
							HX_STACK_LINE(31)
							if (((s != null()))){
								HX_STACK_LINE(31)
								s = ::StringTools_obj::replace(s,HX_CSTRING("::"),HX_CSTRING("."));
								HX_STACK_LINE(31)
								if ((Simple)){
									HX_STACK_LINE(31)
									s = s.substr((s.lastIndexOf(HX_CSTRING("."),null()) + (int)1),null());
								}
							}
							HX_STACK_LINE(31)
							_g2 = s;
						}
						struct _Function_4_1{
							inline static ::String Block( ::flixel::plugin::FlxPlugin &plugin,bool &Simple){
								HX_STACK_FRAME("*","closure",0x5bdab937,"*.closure","flixel/system/frontEnds/PluginFrontEnd.hx",31,0xbff70e9e)
								{
									HX_STACK_LINE(31)
									::Class cl;		HX_STACK_VAR(cl,"cl");
									HX_STACK_LINE(31)
									if ((::Std_obj::is(plugin,hx::ClassOf< ::Class >()))){
										HX_STACK_LINE(31)
										cl = plugin;
									}
									else{
										HX_STACK_LINE(31)
										cl = ::Type_obj::getClass(plugin);
									}
									HX_STACK_LINE(31)
									::String s = ::Type_obj::getClassName(cl);		HX_STACK_VAR(s,"s");
									HX_STACK_LINE(31)
									if (((s != null()))){
										HX_STACK_LINE(31)
										s = ::StringTools_obj::replace(s,HX_CSTRING("::"),HX_CSTRING("."));
										HX_STACK_LINE(31)
										if ((Simple)){
											HX_STACK_LINE(31)
											s = s.substr((s.lastIndexOf(HX_CSTRING("."),null()) + (int)1),null());
										}
									}
									HX_STACK_LINE(31)
									return s;
								}
								return null();
							}
						};
						HX_STACK_LINE(31)
						return (_g2 == _Function_4_1::Block(plugin,Simple));
					}
					return null();
				}
			};
			HX_STACK_LINE(31)
			if ((_Function_3_1::Block(Plugin,plugin))){
				HX_STACK_LINE(33)
				return Plugin;
			}
		}
	}
	HX_STACK_LINE(38)
	this->list->push(Plugin);
	HX_STACK_LINE(39)
	return Plugin;
}


HX_DEFINE_DYNAMIC_FUNC1(PluginFrontEnd_obj,add_flixel_plugin_PathManager,return )

::flixel::plugin::TweenManager PluginFrontEnd_obj::add_flixel_plugin_TweenManager( ::flixel::plugin::TweenManager Plugin){
	HX_STACK_FRAME("flixel.system.frontEnds.PluginFrontEnd","add_flixel_plugin_TweenManager",0xcad736f8,"flixel.system.frontEnds.PluginFrontEnd.add_flixel_plugin_TweenManager","flixel/system/frontEnds/PluginFrontEnd.hx",27,0xbff70e9e)
	HX_STACK_THIS(this)
	HX_STACK_ARG(Plugin,"Plugin")
	HX_STACK_LINE(29)
	{
		HX_STACK_LINE(29)
		int _g = (int)0;		HX_STACK_VAR(_g,"_g");
		HX_STACK_LINE(29)
		Array< ::Dynamic > _g1 = this->list;		HX_STACK_VAR(_g1,"_g1");
		HX_STACK_LINE(29)
		while(((_g < _g1->length))){
			HX_STACK_LINE(29)
			::flixel::plugin::FlxPlugin plugin = _g1->__get(_g).StaticCast< ::flixel::plugin::FlxPlugin >();		HX_STACK_VAR(plugin,"plugin");
			HX_STACK_LINE(29)
			++(_g);
			struct _Function_3_1{
				inline static bool Block( ::flixel::plugin::TweenManager &Plugin,::flixel::plugin::FlxPlugin &plugin){
					HX_STACK_FRAME("*","closure",0x5bdab937,"*.closure","flixel/system/frontEnds/PluginFrontEnd.hx",31,0xbff70e9e)
					{
						HX_STACK_LINE(31)
						bool Simple = true;		HX_STACK_VAR(Simple,"Simple");
						HX_STACK_LINE(31)
						::String _g2;		HX_STACK_VAR(_g2,"_g2");
						HX_STACK_LINE(31)
						{
							HX_STACK_LINE(31)
							::Class cl;		HX_STACK_VAR(cl,"cl");
							HX_STACK_LINE(31)
							if ((::Std_obj::is(Plugin,hx::ClassOf< ::Class >()))){
								HX_STACK_LINE(31)
								cl = Plugin;
							}
							else{
								HX_STACK_LINE(31)
								cl = ::Type_obj::getClass(Plugin);
							}
							HX_STACK_LINE(31)
							::String s = ::Type_obj::getClassName(cl);		HX_STACK_VAR(s,"s");
							HX_STACK_LINE(31)
							if (((s != null()))){
								HX_STACK_LINE(31)
								s = ::StringTools_obj::replace(s,HX_CSTRING("::"),HX_CSTRING("."));
								HX_STACK_LINE(31)
								if ((Simple)){
									HX_STACK_LINE(31)
									s = s.substr((s.lastIndexOf(HX_CSTRING("."),null()) + (int)1),null());
								}
							}
							HX_STACK_LINE(31)
							_g2 = s;
						}
						struct _Function_4_1{
							inline static ::String Block( ::flixel::plugin::FlxPlugin &plugin,bool &Simple){
								HX_STACK_FRAME("*","closure",0x5bdab937,"*.closure","flixel/system/frontEnds/PluginFrontEnd.hx",31,0xbff70e9e)
								{
									HX_STACK_LINE(31)
									::Class cl;		HX_STACK_VAR(cl,"cl");
									HX_STACK_LINE(31)
									if ((::Std_obj::is(plugin,hx::ClassOf< ::Class >()))){
										HX_STACK_LINE(31)
										cl = plugin;
									}
									else{
										HX_STACK_LINE(31)
										cl = ::Type_obj::getClass(plugin);
									}
									HX_STACK_LINE(31)
									::String s = ::Type_obj::getClassName(cl);		HX_STACK_VAR(s,"s");
									HX_STACK_LINE(31)
									if (((s != null()))){
										HX_STACK_LINE(31)
										s = ::StringTools_obj::replace(s,HX_CSTRING("::"),HX_CSTRING("."));
										HX_STACK_LINE(31)
										if ((Simple)){
											HX_STACK_LINE(31)
											s = s.substr((s.lastIndexOf(HX_CSTRING("."),null()) + (int)1),null());
										}
									}
									HX_STACK_LINE(31)
									return s;
								}
								return null();
							}
						};
						HX_STACK_LINE(31)
						return (_g2 == _Function_4_1::Block(plugin,Simple));
					}
					return null();
				}
			};
			HX_STACK_LINE(31)
			if ((_Function_3_1::Block(Plugin,plugin))){
				HX_STACK_LINE(33)
				return Plugin;
			}
		}
	}
	HX_STACK_LINE(38)
	this->list->push(Plugin);
	HX_STACK_LINE(39)
	return Plugin;
}


HX_DEFINE_DYNAMIC_FUNC1(PluginFrontEnd_obj,add_flixel_plugin_TweenManager,return )

::flixel::plugin::TimerManager PluginFrontEnd_obj::add_flixel_plugin_TimerManager( ::flixel::plugin::TimerManager Plugin){
	HX_STACK_FRAME("flixel.system.frontEnds.PluginFrontEnd","add_flixel_plugin_TimerManager",0xa5cae0de,"flixel.system.frontEnds.PluginFrontEnd.add_flixel_plugin_TimerManager","flixel/system/frontEnds/PluginFrontEnd.hx",27,0xbff70e9e)
	HX_STACK_THIS(this)
	HX_STACK_ARG(Plugin,"Plugin")
	HX_STACK_LINE(29)
	{
		HX_STACK_LINE(29)
		int _g = (int)0;		HX_STACK_VAR(_g,"_g");
		HX_STACK_LINE(29)
		Array< ::Dynamic > _g1 = this->list;		HX_STACK_VAR(_g1,"_g1");
		HX_STACK_LINE(29)
		while(((_g < _g1->length))){
			HX_STACK_LINE(29)
			::flixel::plugin::FlxPlugin plugin = _g1->__get(_g).StaticCast< ::flixel::plugin::FlxPlugin >();		HX_STACK_VAR(plugin,"plugin");
			HX_STACK_LINE(29)
			++(_g);
			struct _Function_3_1{
				inline static bool Block( ::flixel::plugin::TimerManager &Plugin,::flixel::plugin::FlxPlugin &plugin){
					HX_STACK_FRAME("*","closure",0x5bdab937,"*.closure","flixel/system/frontEnds/PluginFrontEnd.hx",31,0xbff70e9e)
					{
						HX_STACK_LINE(31)
						bool Simple = true;		HX_STACK_VAR(Simple,"Simple");
						HX_STACK_LINE(31)
						::String _g2;		HX_STACK_VAR(_g2,"_g2");
						HX_STACK_LINE(31)
						{
							HX_STACK_LINE(31)
							::Class cl;		HX_STACK_VAR(cl,"cl");
							HX_STACK_LINE(31)
							if ((::Std_obj::is(Plugin,hx::ClassOf< ::Class >()))){
								HX_STACK_LINE(31)
								cl = Plugin;
							}
							else{
								HX_STACK_LINE(31)
								cl = ::Type_obj::getClass(Plugin);
							}
							HX_STACK_LINE(31)
							::String s = ::Type_obj::getClassName(cl);		HX_STACK_VAR(s,"s");
							HX_STACK_LINE(31)
							if (((s != null()))){
								HX_STACK_LINE(31)
								s = ::StringTools_obj::replace(s,HX_CSTRING("::"),HX_CSTRING("."));
								HX_STACK_LINE(31)
								if ((Simple)){
									HX_STACK_LINE(31)
									s = s.substr((s.lastIndexOf(HX_CSTRING("."),null()) + (int)1),null());
								}
							}
							HX_STACK_LINE(31)
							_g2 = s;
						}
						struct _Function_4_1{
							inline static ::String Block( ::flixel::plugin::FlxPlugin &plugin,bool &Simple){
								HX_STACK_FRAME("*","closure",0x5bdab937,"*.closure","flixel/system/frontEnds/PluginFrontEnd.hx",31,0xbff70e9e)
								{
									HX_STACK_LINE(31)
									::Class cl;		HX_STACK_VAR(cl,"cl");
									HX_STACK_LINE(31)
									if ((::Std_obj::is(plugin,hx::ClassOf< ::Class >()))){
										HX_STACK_LINE(31)
										cl = plugin;
									}
									else{
										HX_STACK_LINE(31)
										cl = ::Type_obj::getClass(plugin);
									}
									HX_STACK_LINE(31)
									::String s = ::Type_obj::getClassName(cl);		HX_STACK_VAR(s,"s");
									HX_STACK_LINE(31)
									if (((s != null()))){
										HX_STACK_LINE(31)
										s = ::StringTools_obj::replace(s,HX_CSTRING("::"),HX_CSTRING("."));
										HX_STACK_LINE(31)
										if ((Simple)){
											HX_STACK_LINE(31)
											s = s.substr((s.lastIndexOf(HX_CSTRING("."),null()) + (int)1),null());
										}
									}
									HX_STACK_LINE(31)
									return s;
								}
								return null();
							}
						};
						HX_STACK_LINE(31)
						return (_g2 == _Function_4_1::Block(plugin,Simple));
					}
					return null();
				}
			};
			HX_STACK_LINE(31)
			if ((_Function_3_1::Block(Plugin,plugin))){
				HX_STACK_LINE(33)
				return Plugin;
			}
		}
	}
	HX_STACK_LINE(38)
	this->list->push(Plugin);
	HX_STACK_LINE(39)
	return Plugin;
}


HX_DEFINE_DYNAMIC_FUNC1(PluginFrontEnd_obj,add_flixel_plugin_TimerManager,return )

::flixel::plugin::FlxPlugin PluginFrontEnd_obj::get( ::Class ClassType){
	HX_STACK_FRAME("flixel.system.frontEnds.PluginFrontEnd","get",0x6ca472e7,"flixel.system.frontEnds.PluginFrontEnd.get","flixel/system/frontEnds/PluginFrontEnd.hx",49,0xbff70e9e)
	HX_STACK_THIS(this)
	HX_STACK_ARG(ClassType,"ClassType")
	HX_STACK_LINE(50)
	{
		HX_STACK_LINE(50)
		int _g = (int)0;		HX_STACK_VAR(_g,"_g");
		HX_STACK_LINE(50)
		Array< ::Dynamic > _g1 = this->list;		HX_STACK_VAR(_g1,"_g1");
		HX_STACK_LINE(50)
		while(((_g < _g1->length))){
			HX_STACK_LINE(50)
			::flixel::plugin::FlxPlugin plugin = _g1->__get(_g).StaticCast< ::flixel::plugin::FlxPlugin >();		HX_STACK_VAR(plugin,"plugin");
			HX_STACK_LINE(50)
			++(_g);
			HX_STACK_LINE(52)
			if ((::Std_obj::is(plugin,ClassType))){
				HX_STACK_LINE(54)
				return plugin;
			}
		}
	}
	HX_STACK_LINE(58)
	return null();
}


HX_DEFINE_DYNAMIC_FUNC1(PluginFrontEnd_obj,get,return )

::flixel::plugin::FlxPlugin PluginFrontEnd_obj::remove( ::flixel::plugin::FlxPlugin Plugin){
	HX_STACK_FRAME("flixel.system.frontEnds.PluginFrontEnd","remove",0x66803293,"flixel.system.frontEnds.PluginFrontEnd.remove","flixel/system/frontEnds/PluginFrontEnd.hx",68,0xbff70e9e)
	HX_STACK_THIS(this)
	HX_STACK_ARG(Plugin,"Plugin")
	HX_STACK_LINE(70)
	int i = (this->list->length - (int)1);		HX_STACK_VAR(i,"i");
	HX_STACK_LINE(72)
	while(((i >= (int)0))){
		HX_STACK_LINE(74)
		if (((this->list->__get(i).StaticCast< ::flixel::plugin::FlxPlugin >() == Plugin))){
			HX_STACK_LINE(76)
			this->list->splice(i,(int)1);
			HX_STACK_LINE(77)
			return Plugin;
		}
		HX_STACK_LINE(79)
		(i)--;
	}
	HX_STACK_LINE(82)
	return Plugin;
}


HX_DEFINE_DYNAMIC_FUNC1(PluginFrontEnd_obj,remove,return )

bool PluginFrontEnd_obj::removeType( ::Class ClassType){
	HX_STACK_FRAME("flixel.system.frontEnds.PluginFrontEnd","removeType",0x8b4a96ed,"flixel.system.frontEnds.PluginFrontEnd.removeType","flixel/system/frontEnds/PluginFrontEnd.hx",92,0xbff70e9e)
	HX_STACK_THIS(this)
	HX_STACK_ARG(ClassType,"ClassType")
	HX_STACK_LINE(94)
	bool results = false;		HX_STACK_VAR(results,"results");
	HX_STACK_LINE(95)
	int i = (this->list->length - (int)1);		HX_STACK_VAR(i,"i");
	HX_STACK_LINE(97)
	while(((i >= (int)0))){
		HX_STACK_LINE(99)
		if ((::Std_obj::is(this->list->__get(i).StaticCast< ::flixel::plugin::FlxPlugin >(),ClassType))){
			HX_STACK_LINE(101)
			this->list->splice(i,(int)1);
			HX_STACK_LINE(102)
			results = true;
		}
		HX_STACK_LINE(104)
		(i)--;
	}
	HX_STACK_LINE(107)
	return results;
}


HX_DEFINE_DYNAMIC_FUNC1(PluginFrontEnd_obj,removeType,return )

Void PluginFrontEnd_obj::update( ){
{
		HX_STACK_FRAME("flixel.system.frontEnds.PluginFrontEnd","update",0xe8fd1c58,"flixel.system.frontEnds.PluginFrontEnd.update","flixel/system/frontEnds/PluginFrontEnd.hx",129,0xbff70e9e)
		HX_STACK_THIS(this)
		HX_STACK_LINE(129)
		int _g = (int)0;		HX_STACK_VAR(_g,"_g");
		HX_STACK_LINE(129)
		Array< ::Dynamic > _g1 = this->list;		HX_STACK_VAR(_g1,"_g1");
		HX_STACK_LINE(129)
		while(((_g < _g1->length))){
			HX_STACK_LINE(129)
			::flixel::plugin::FlxPlugin plugin = _g1->__get(_g).StaticCast< ::flixel::plugin::FlxPlugin >();		HX_STACK_VAR(plugin,"plugin");
			HX_STACK_LINE(129)
			++(_g);
			HX_STACK_LINE(131)
			if (((bool(plugin->exists) && bool(plugin->active)))){
				HX_STACK_LINE(133)
				plugin->update();
			}
		}
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC0(PluginFrontEnd_obj,update,(void))

Void PluginFrontEnd_obj::draw( ){
{
		HX_STACK_FRAME("flixel.system.frontEnds.PluginFrontEnd","draw",0xa14e4093,"flixel.system.frontEnds.PluginFrontEnd.draw","flixel/system/frontEnds/PluginFrontEnd.hx",143,0xbff70e9e)
		HX_STACK_THIS(this)
		HX_STACK_LINE(143)
		int _g = (int)0;		HX_STACK_VAR(_g,"_g");
		HX_STACK_LINE(143)
		Array< ::Dynamic > _g1 = this->list;		HX_STACK_VAR(_g1,"_g1");
		HX_STACK_LINE(143)
		while(((_g < _g1->length))){
			HX_STACK_LINE(143)
			::flixel::plugin::FlxPlugin plugin = _g1->__get(_g).StaticCast< ::flixel::plugin::FlxPlugin >();		HX_STACK_VAR(plugin,"plugin");
			HX_STACK_LINE(143)
			++(_g);
			HX_STACK_LINE(145)
			if (((bool(plugin->exists) && bool(plugin->visible)))){
				HX_STACK_LINE(147)
				plugin->draw();
			}
		}
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC0(PluginFrontEnd_obj,draw,(void))

Void PluginFrontEnd_obj::onStateSwitch( ){
{
		HX_STACK_FRAME("flixel.system.frontEnds.PluginFrontEnd","onStateSwitch",0xb3451597,"flixel.system.frontEnds.PluginFrontEnd.onStateSwitch","flixel/system/frontEnds/PluginFrontEnd.hx",157,0xbff70e9e)
		HX_STACK_THIS(this)
		HX_STACK_LINE(157)
		int _g = (int)0;		HX_STACK_VAR(_g,"_g");
		HX_STACK_LINE(157)
		Array< ::Dynamic > _g1 = this->list;		HX_STACK_VAR(_g1,"_g1");
		HX_STACK_LINE(157)
		while(((_g < _g1->length))){
			HX_STACK_LINE(157)
			::flixel::plugin::FlxPlugin plugin = _g1->__get(_g).StaticCast< ::flixel::plugin::FlxPlugin >();		HX_STACK_VAR(plugin,"plugin");
			HX_STACK_LINE(157)
			++(_g);
			HX_STACK_LINE(159)
			if ((plugin->exists)){
				HX_STACK_LINE(161)
				plugin->onStateSwitch();
			}
		}
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC0(PluginFrontEnd_obj,onStateSwitch,(void))

Void PluginFrontEnd_obj::onResize( int Width,int Height){
{
		HX_STACK_FRAME("flixel.system.frontEnds.PluginFrontEnd","onResize",0x67ed5882,"flixel.system.frontEnds.PluginFrontEnd.onResize","flixel/system/frontEnds/PluginFrontEnd.hx",173,0xbff70e9e)
		HX_STACK_THIS(this)
		HX_STACK_ARG(Width,"Width")
		HX_STACK_ARG(Height,"Height")
		HX_STACK_LINE(173)
		int _g = (int)0;		HX_STACK_VAR(_g,"_g");
		HX_STACK_LINE(173)
		Array< ::Dynamic > _g1 = this->list;		HX_STACK_VAR(_g1,"_g1");
		HX_STACK_LINE(173)
		while(((_g < _g1->length))){
			HX_STACK_LINE(173)
			::flixel::plugin::FlxPlugin plugin = _g1->__get(_g).StaticCast< ::flixel::plugin::FlxPlugin >();		HX_STACK_VAR(plugin,"plugin");
			HX_STACK_LINE(173)
			++(_g);
			HX_STACK_LINE(175)
			if ((plugin->exists)){
				HX_STACK_LINE(177)
				plugin->onResize(Width,Height);
			}
		}
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC2(PluginFrontEnd_obj,onResize,(void))

Void PluginFrontEnd_obj::drawDebug( ){
{
		HX_STACK_FRAME("flixel.system.frontEnds.PluginFrontEnd","drawDebug",0xebcc8cc0,"flixel.system.frontEnds.PluginFrontEnd.drawDebug","flixel/system/frontEnds/PluginFrontEnd.hx",188,0xbff70e9e)
		HX_STACK_THIS(this)
		HX_STACK_LINE(188)
		int _g = (int)0;		HX_STACK_VAR(_g,"_g");
		HX_STACK_LINE(188)
		Array< ::Dynamic > _g1 = this->list;		HX_STACK_VAR(_g1,"_g1");
		HX_STACK_LINE(188)
		while(((_g < _g1->length))){
			HX_STACK_LINE(188)
			::flixel::plugin::FlxPlugin plugin = _g1->__get(_g).StaticCast< ::flixel::plugin::FlxPlugin >();		HX_STACK_VAR(plugin,"plugin");
			HX_STACK_LINE(188)
			++(_g);
			HX_STACK_LINE(190)
			if (((bool((bool(plugin->exists) && bool(plugin->visible))) && bool(!(plugin->ignoreDrawDebug))))){
				HX_STACK_LINE(192)
				plugin->drawDebug();
			}
		}
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC0(PluginFrontEnd_obj,drawDebug,(void))


PluginFrontEnd_obj::PluginFrontEnd_obj()
{
}

void PluginFrontEnd_obj::__Mark(HX_MARK_PARAMS)
{
	HX_MARK_BEGIN_CLASS(PluginFrontEnd);
	HX_MARK_MEMBER_NAME(list,"list");
	HX_MARK_END_CLASS();
}

void PluginFrontEnd_obj::__Visit(HX_VISIT_PARAMS)
{
	HX_VISIT_MEMBER_NAME(list,"list");
}

Dynamic PluginFrontEnd_obj::__Field(const ::String &inName,bool inCallProp)
{
	switch(inName.length) {
	case 3:
		if (HX_FIELD_EQ(inName,"get") ) { return get_dyn(); }
		break;
	case 4:
		if (HX_FIELD_EQ(inName,"list") ) { return list; }
		if (HX_FIELD_EQ(inName,"draw") ) { return draw_dyn(); }
		break;
	case 6:
		if (HX_FIELD_EQ(inName,"remove") ) { return remove_dyn(); }
		if (HX_FIELD_EQ(inName,"update") ) { return update_dyn(); }
		break;
	case 8:
		if (HX_FIELD_EQ(inName,"onResize") ) { return onResize_dyn(); }
		break;
	case 9:
		if (HX_FIELD_EQ(inName,"drawDebug") ) { return drawDebug_dyn(); }
		break;
	case 10:
		if (HX_FIELD_EQ(inName,"removeType") ) { return removeType_dyn(); }
		break;
	case 13:
		if (HX_FIELD_EQ(inName,"onStateSwitch") ) { return onStateSwitch_dyn(); }
		break;
	case 29:
		if (HX_FIELD_EQ(inName,"add_flixel_plugin_PathManager") ) { return add_flixel_plugin_PathManager_dyn(); }
		break;
	case 30:
		if (HX_FIELD_EQ(inName,"add_flixel_plugin_TweenManager") ) { return add_flixel_plugin_TweenManager_dyn(); }
		if (HX_FIELD_EQ(inName,"add_flixel_plugin_TimerManager") ) { return add_flixel_plugin_TimerManager_dyn(); }
	}
	return super::__Field(inName,inCallProp);
}

Dynamic PluginFrontEnd_obj::__SetField(const ::String &inName,const Dynamic &inValue,bool inCallProp)
{
	switch(inName.length) {
	case 4:
		if (HX_FIELD_EQ(inName,"list") ) { list=inValue.Cast< Array< ::Dynamic > >(); return inValue; }
	}
	return super::__SetField(inName,inValue,inCallProp);
}

void PluginFrontEnd_obj::__GetFields(Array< ::String> &outFields)
{
	outFields->push(HX_CSTRING("list"));
	super::__GetFields(outFields);
};

static ::String sStaticFields[] = {
	String(null()) };

#if HXCPP_SCRIPTABLE
static hx::StorageInfo sMemberStorageInfo[] = {
	{hx::fsObject /*Array< ::Dynamic >*/ ,(int)offsetof(PluginFrontEnd_obj,list),HX_CSTRING("list")},
	{ hx::fsUnknown, 0, null()}
};
#endif

static ::String sMemberFields[] = {
	HX_CSTRING("add_flixel_plugin_PathManager"),
	HX_CSTRING("add_flixel_plugin_TweenManager"),
	HX_CSTRING("add_flixel_plugin_TimerManager"),
	HX_CSTRING("list"),
	HX_CSTRING("get"),
	HX_CSTRING("remove"),
	HX_CSTRING("removeType"),
	HX_CSTRING("update"),
	HX_CSTRING("draw"),
	HX_CSTRING("onStateSwitch"),
	HX_CSTRING("onResize"),
	HX_CSTRING("drawDebug"),
	String(null()) };

static void sMarkStatics(HX_MARK_PARAMS) {
	HX_MARK_MEMBER_NAME(PluginFrontEnd_obj::__mClass,"__mClass");
};

#ifdef HXCPP_VISIT_ALLOCS
static void sVisitStatics(HX_VISIT_PARAMS) {
	HX_VISIT_MEMBER_NAME(PluginFrontEnd_obj::__mClass,"__mClass");
};

#endif

Class PluginFrontEnd_obj::__mClass;

void PluginFrontEnd_obj::__register()
{
	hx::Static(__mClass) = hx::RegisterClass(HX_CSTRING("flixel.system.frontEnds.PluginFrontEnd"), hx::TCanCast< PluginFrontEnd_obj> ,sStaticFields,sMemberFields,
	&__CreateEmpty, &__Create,
	&super::__SGetClass(), 0, sMarkStatics
#ifdef HXCPP_VISIT_ALLOCS
    , sVisitStatics
#endif
#ifdef HXCPP_SCRIPTABLE
    , sMemberStorageInfo
#endif
);
}

void PluginFrontEnd_obj::__boot()
{
}

} // end namespace flixel
} // end namespace system
} // end namespace frontEnds
