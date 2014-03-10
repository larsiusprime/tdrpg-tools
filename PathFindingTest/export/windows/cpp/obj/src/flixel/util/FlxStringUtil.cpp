#include <hxcpp.h>

#ifndef INCLUDED_IMap
#include <IMap.h>
#endif
#ifndef INCLUDED_Std
#include <Std.h>
#endif
#ifndef INCLUDED_StringBuf
#include <StringBuf.h>
#endif
#ifndef INCLUDED_StringTools
#include <StringTools.h>
#endif
#ifndef INCLUDED_Type
#include <Type.h>
#endif
#ifndef INCLUDED_flash_display_BitmapData
#include <flash/display/BitmapData.h>
#endif
#ifndef INCLUDED_flash_display_BlendMode
#include <flash/display/BlendMode.h>
#endif
#ifndef INCLUDED_flash_display_IBitmapDrawable
#include <flash/display/IBitmapDrawable.h>
#endif
#ifndef INCLUDED_flash_geom_ColorTransform
#include <flash/geom/ColorTransform.h>
#endif
#ifndef INCLUDED_flash_geom_Matrix
#include <flash/geom/Matrix.h>
#endif
#ifndef INCLUDED_flash_geom_Rectangle
#include <flash/geom/Rectangle.h>
#endif
#ifndef INCLUDED_flixel_FlxG
#include <flixel/FlxG.h>
#endif
#ifndef INCLUDED_flixel_system_frontEnds_DebuggerFrontEnd
#include <flixel/system/frontEnds/DebuggerFrontEnd.h>
#endif
#ifndef INCLUDED_flixel_util_FlxArrayUtil
#include <flixel/util/FlxArrayUtil.h>
#endif
#ifndef INCLUDED_flixel_util_FlxMath
#include <flixel/util/FlxMath.h>
#endif
#ifndef INCLUDED_flixel_util_FlxStringUtil
#include <flixel/util/FlxStringUtil.h>
#endif
#ifndef INCLUDED_haxe_ds_StringMap
#include <haxe/ds/StringMap.h>
#endif
#ifndef INCLUDED_hxMath
#include <hxMath.h>
#endif
#ifndef INCLUDED_openfl_Assets
#include <openfl/Assets.h>
#endif
namespace flixel{
namespace util{

Void FlxStringUtil_obj::__construct()
{
	return null();
}

//FlxStringUtil_obj::~FlxStringUtil_obj() { }

Dynamic FlxStringUtil_obj::__CreateEmpty() { return  new FlxStringUtil_obj; }
hx::ObjectPtr< FlxStringUtil_obj > FlxStringUtil_obj::__new()
{  hx::ObjectPtr< FlxStringUtil_obj > result = new FlxStringUtil_obj();
	result->__construct();
	return result;}

Dynamic FlxStringUtil_obj::__Create(hx::DynamicArray inArgs)
{  hx::ObjectPtr< FlxStringUtil_obj > result = new FlxStringUtil_obj();
	result->__construct();
	return result;}

::String FlxStringUtil_obj::formatTicks( int StartTicks,int EndTicks){
	HX_STACK_FRAME("flixel.util.FlxStringUtil","formatTicks",0xe4bb609c,"flixel.util.FlxStringUtil.formatTicks","flixel/util/FlxStringUtil.hx",27,0x4e012e33)
	HX_STACK_ARG(StartTicks,"StartTicks")
	HX_STACK_ARG(EndTicks,"EndTicks")
	HX_STACK_LINE(27)
	return ((Float(::Math_obj::abs((EndTicks - StartTicks))) / Float((int)1000)) + HX_CSTRING("s"));
}


STATIC_HX_DEFINE_DYNAMIC_FUNC2(FlxStringUtil_obj,formatTicks,return )

::String FlxStringUtil_obj::formatTime( Float Seconds,hx::Null< bool >  __o_ShowMS){
bool ShowMS = __o_ShowMS.Default(false);
	HX_STACK_FRAME("flixel.util.FlxStringUtil","formatTime",0xcfa9a0a7,"flixel.util.FlxStringUtil.formatTime","flixel/util/FlxStringUtil.hx",38,0x4e012e33)
	HX_STACK_ARG(Seconds,"Seconds")
	HX_STACK_ARG(ShowMS,"ShowMS")
{
		HX_STACK_LINE(39)
		::String timeString = (::Std_obj::_int((Float(Seconds) / Float((int)60))) + HX_CSTRING(":"));		HX_STACK_VAR(timeString,"timeString");
		HX_STACK_LINE(40)
		int timeStringHelper = hx::Mod(::Std_obj::_int(Seconds),(int)60);		HX_STACK_VAR(timeStringHelper,"timeStringHelper");
		HX_STACK_LINE(41)
		if (((timeStringHelper < (int)10))){
			HX_STACK_LINE(43)
			hx::AddEq(timeString,HX_CSTRING("0"));
		}
		HX_STACK_LINE(45)
		hx::AddEq(timeString,timeStringHelper);
		HX_STACK_LINE(46)
		if ((ShowMS)){
			HX_STACK_LINE(48)
			hx::AddEq(timeString,HX_CSTRING("."));
			HX_STACK_LINE(49)
			timeStringHelper = ::Std_obj::_int((((Seconds - ::Std_obj::_int(Seconds))) * (int)100));
			HX_STACK_LINE(50)
			if (((timeStringHelper < (int)10))){
				HX_STACK_LINE(52)
				hx::AddEq(timeString,HX_CSTRING("0"));
			}
			HX_STACK_LINE(54)
			hx::AddEq(timeString,timeStringHelper);
		}
		HX_STACK_LINE(57)
		return timeString;
	}
}


STATIC_HX_DEFINE_DYNAMIC_FUNC2(FlxStringUtil_obj,formatTime,return )

::String FlxStringUtil_obj::formatArray( Dynamic AnyArray){
	HX_STACK_FRAME("flixel.util.FlxStringUtil","formatArray",0xfa1c9fbf,"flixel.util.FlxStringUtil.formatArray","flixel/util/FlxStringUtil.hx",68,0x4e012e33)
	HX_STACK_ARG(AnyArray,"AnyArray")
	HX_STACK_LINE(69)
	::String string = HX_CSTRING("");		HX_STACK_VAR(string,"string");
	HX_STACK_LINE(70)
	if (((bool((AnyArray != null())) && bool((AnyArray->__Field(HX_CSTRING("length"),true) > (int)0))))){
		HX_STACK_LINE(72)
		string = ::Std_obj::string(AnyArray->__GetItem((int)0));
		HX_STACK_LINE(73)
		int i = (int)1;		HX_STACK_VAR(i,"i");
		HX_STACK_LINE(74)
		int l = AnyArray->__Field(HX_CSTRING("length"),true);		HX_STACK_VAR(l,"l");
		HX_STACK_LINE(75)
		while(((i < l))){
			HX_STACK_LINE(77)
			hx::AddEq(string,(HX_CSTRING(", ") + ::Std_obj::string(AnyArray->__GetItem((i)++))));
		}
	}
	HX_STACK_LINE(80)
	return string;
}


STATIC_HX_DEFINE_DYNAMIC_FUNC1(FlxStringUtil_obj,formatArray,return )

::String FlxStringUtil_obj::formatStringMap( ::haxe::ds::StringMap AnyMap){
	HX_STACK_FRAME("flixel.util.FlxStringUtil","formatStringMap",0x51016f71,"flixel.util.FlxStringUtil.formatStringMap","flixel/util/FlxStringUtil.hx",90,0x4e012e33)
	HX_STACK_ARG(AnyMap,"AnyMap")
	HX_STACK_LINE(91)
	::String string = HX_CSTRING("");		HX_STACK_VAR(string,"string");
	HX_STACK_LINE(92)
	for(::cpp::FastIterator_obj< ::String > *__it = ::cpp::CreateFastIterator< ::String >(AnyMap->keys());  __it->hasNext(); ){
		::String key = __it->next();
		{
			HX_STACK_LINE(93)
			hx::AddEq(string,::Std_obj::string(key));
			HX_STACK_LINE(94)
			hx::AddEq(string,HX_CSTRING(", "));
		}
;
	}
	HX_STACK_LINE(97)
	return string.substring((int)0,(string.length - (int)2));
}


STATIC_HX_DEFINE_DYNAMIC_FUNC1(FlxStringUtil_obj,formatStringMap,return )

::String FlxStringUtil_obj::formatMoney( Float Amount,hx::Null< bool >  __o_ShowDecimal,hx::Null< bool >  __o_EnglishStyle){
bool ShowDecimal = __o_ShowDecimal.Default(true);
bool EnglishStyle = __o_EnglishStyle.Default(true);
	HX_STACK_FRAME("flixel.util.FlxStringUtil","formatMoney",0xe0ecec66,"flixel.util.FlxStringUtil.formatMoney","flixel/util/FlxStringUtil.hx",112,0x4e012e33)
	HX_STACK_ARG(Amount,"Amount")
	HX_STACK_ARG(ShowDecimal,"ShowDecimal")
	HX_STACK_ARG(EnglishStyle,"EnglishStyle")
{
		HX_STACK_LINE(113)
		int helper;		HX_STACK_VAR(helper,"helper");
		HX_STACK_LINE(114)
		int amount = ::Math_obj::floor(Amount);		HX_STACK_VAR(amount,"amount");
		HX_STACK_LINE(115)
		::String string = HX_CSTRING("");		HX_STACK_VAR(string,"string");
		HX_STACK_LINE(116)
		::String comma = HX_CSTRING("");		HX_STACK_VAR(comma,"comma");
		HX_STACK_LINE(117)
		::String zeroes = HX_CSTRING("");		HX_STACK_VAR(zeroes,"zeroes");
		HX_STACK_LINE(118)
		while(((amount > (int)0))){
			HX_STACK_LINE(120)
			if (((bool((string.length > (int)0)) && bool((comma.length <= (int)0))))){
				HX_STACK_LINE(122)
				if ((EnglishStyle)){
					HX_STACK_LINE(124)
					comma = HX_CSTRING(",");
				}
				else{
					HX_STACK_LINE(128)
					comma = HX_CSTRING(".");
				}
			}
			HX_STACK_LINE(131)
			zeroes = HX_CSTRING("");
			HX_STACK_LINE(132)
			helper = (amount - (::Math_obj::floor((Float(amount) / Float((int)1000))) * (int)1000));
			HX_STACK_LINE(133)
			amount = ::Math_obj::floor((Float(amount) / Float((int)1000)));
			HX_STACK_LINE(134)
			if (((amount > (int)0))){
				HX_STACK_LINE(136)
				if (((helper < (int)100))){
					HX_STACK_LINE(138)
					hx::AddEq(zeroes,HX_CSTRING("0"));
				}
				HX_STACK_LINE(140)
				if (((helper < (int)10))){
					HX_STACK_LINE(142)
					hx::AddEq(zeroes,HX_CSTRING("0"));
				}
			}
			HX_STACK_LINE(145)
			string = (((zeroes + helper) + comma) + string);
		}
		HX_STACK_LINE(147)
		if ((ShowDecimal)){
			HX_STACK_LINE(149)
			int _g = ::Std_obj::_int((Amount * (int)100));		HX_STACK_VAR(_g,"_g");
			HX_STACK_LINE(149)
			amount = (_g - (::Std_obj::_int(Amount) * (int)100));
			HX_STACK_LINE(150)
			hx::AddEq(string,(((  ((EnglishStyle)) ? ::String(HX_CSTRING(".")) : ::String(HX_CSTRING(",")) )) + amount));
			HX_STACK_LINE(151)
			if (((amount < (int)10))){
				HX_STACK_LINE(153)
				hx::AddEq(string,HX_CSTRING("0"));
			}
		}
		HX_STACK_LINE(156)
		return string;
	}
}


STATIC_HX_DEFINE_DYNAMIC_FUNC3(FlxStringUtil_obj,formatMoney,return )

::String FlxStringUtil_obj::filterDigits( ::String Input){
	HX_STACK_FRAME("flixel.util.FlxStringUtil","filterDigits",0xab6a2081,"flixel.util.FlxStringUtil.filterDigits","flixel/util/FlxStringUtil.hx",166,0x4e012e33)
	HX_STACK_ARG(Input,"Input")
	HX_STACK_LINE(167)
	::StringBuf output = ::StringBuf_obj::__new();		HX_STACK_VAR(output,"output");
	HX_STACK_LINE(168)
	{
		HX_STACK_LINE(168)
		int _g1 = (int)0;		HX_STACK_VAR(_g1,"_g1");
		HX_STACK_LINE(168)
		int _g = Input.length;		HX_STACK_VAR(_g,"_g");
		HX_STACK_LINE(168)
		while(((_g1 < _g))){
			HX_STACK_LINE(168)
			int i = (_g1)++;		HX_STACK_VAR(i,"i");
			HX_STACK_LINE(169)
			Dynamic c = Input.charCodeAt(i);		HX_STACK_VAR(c,"c");
			HX_STACK_LINE(170)
			if (((bool((c >= (int)48)) && bool((c <= (int)57))))){
				HX_STACK_LINE(171)
				int c1 = c;		HX_STACK_VAR(c1,"c1");
				HX_STACK_LINE(171)
				output->b->push(::String::fromCharCode(c1));
			}
		}
	}
	HX_STACK_LINE(174)
	return output->b->join(HX_CSTRING(""));
}


STATIC_HX_DEFINE_DYNAMIC_FUNC1(FlxStringUtil_obj,filterDigits,return )

::String FlxStringUtil_obj::htmlFormat( ::String Text,hx::Null< int >  __o_Size,::String __o_Color,hx::Null< bool >  __o_Bold,hx::Null< bool >  __o_Italic,hx::Null< bool >  __o_Underlined){
int Size = __o_Size.Default(12);
::String Color = __o_Color.Default(HX_CSTRING("FFFFFF"));
bool Bold = __o_Bold.Default(false);
bool Italic = __o_Italic.Default(false);
bool Underlined = __o_Underlined.Default(false);
	HX_STACK_FRAME("flixel.util.FlxStringUtil","htmlFormat",0x8e97acc5,"flixel.util.FlxStringUtil.htmlFormat","flixel/util/FlxStringUtil.hx",190,0x4e012e33)
	HX_STACK_ARG(Text,"Text")
	HX_STACK_ARG(Size,"Size")
	HX_STACK_ARG(Color,"Color")
	HX_STACK_ARG(Bold,"Bold")
	HX_STACK_ARG(Italic,"Italic")
	HX_STACK_ARG(Underlined,"Underlined")
{
		HX_STACK_LINE(191)
		::String prefix = ((((HX_CSTRING("<font size='") + Size) + HX_CSTRING("' color='#")) + Color) + HX_CSTRING("'>"));		HX_STACK_VAR(prefix,"prefix");
		HX_STACK_LINE(192)
		::String suffix = HX_CSTRING("</font>");		HX_STACK_VAR(suffix,"suffix");
		HX_STACK_LINE(194)
		if ((Bold)){
			HX_STACK_LINE(196)
			prefix = (HX_CSTRING("<b>") + prefix);
			HX_STACK_LINE(197)
			suffix = (suffix + HX_CSTRING("</b>"));
		}
		HX_STACK_LINE(199)
		if ((Italic)){
			HX_STACK_LINE(201)
			prefix = (HX_CSTRING("<i>") + prefix);
			HX_STACK_LINE(202)
			suffix = (suffix + HX_CSTRING("</i>"));
		}
		HX_STACK_LINE(204)
		if ((Underlined)){
			HX_STACK_LINE(206)
			prefix = (HX_CSTRING("<u>") + prefix);
			HX_STACK_LINE(207)
			suffix = (suffix + HX_CSTRING("</u>"));
		}
		HX_STACK_LINE(210)
		return ((prefix + Text) + suffix);
	}
}


STATIC_HX_DEFINE_DYNAMIC_FUNC6(FlxStringUtil_obj,htmlFormat,return )

::String FlxStringUtil_obj::getDomain( ::String url){
	HX_STACK_FRAME("flixel.util.FlxStringUtil","getDomain",0x05683217,"flixel.util.FlxStringUtil.getDomain","flixel/util/FlxStringUtil.hx",248,0x4e012e33)
	HX_STACK_ARG(url,"url")
	HX_STACK_LINE(249)
	int urlStart = (url.indexOf(HX_CSTRING("://"),null()) + (int)3);		HX_STACK_VAR(urlStart,"urlStart");
	HX_STACK_LINE(250)
	int urlEnd = url.indexOf(HX_CSTRING("/"),urlStart);		HX_STACK_VAR(urlEnd,"urlEnd");
	HX_STACK_LINE(251)
	::String home = url.substring(urlStart,urlEnd);		HX_STACK_VAR(home,"home");
	HX_STACK_LINE(252)
	int LastDot = (home.lastIndexOf(HX_CSTRING("."),null()) - (int)1);		HX_STACK_VAR(LastDot,"LastDot");
	HX_STACK_LINE(253)
	int domEnd = (home.lastIndexOf(HX_CSTRING("."),LastDot) + (int)1);		HX_STACK_VAR(domEnd,"domEnd");
	HX_STACK_LINE(254)
	home = home.substring(domEnd,home.length);
	HX_STACK_LINE(255)
	home = home.split(HX_CSTRING(":"))->__get((int)0);
	HX_STACK_LINE(256)
	if (((home == HX_CSTRING("")))){
		HX_STACK_LINE(256)
		return HX_CSTRING("local");
	}
	else{
		HX_STACK_LINE(256)
		return home;
	}
	HX_STACK_LINE(256)
	return null();
}


STATIC_HX_DEFINE_DYNAMIC_FUNC1(FlxStringUtil_obj,getDomain,return )

bool FlxStringUtil_obj::sameClassName( Dynamic Obj1,Dynamic Obj2,hx::Null< bool >  __o_Simple){
bool Simple = __o_Simple.Default(true);
	HX_STACK_FRAME("flixel.util.FlxStringUtil","sameClassName",0x3be7dc7a,"flixel.util.FlxStringUtil.sameClassName","flixel/util/FlxStringUtil.hx",268,0x4e012e33)
	HX_STACK_ARG(Obj1,"Obj1")
	HX_STACK_ARG(Obj2,"Obj2")
	HX_STACK_ARG(Simple,"Simple")
{
		HX_STACK_LINE(269)
		::String _g;		HX_STACK_VAR(_g,"_g");
		HX_STACK_LINE(269)
		{
			HX_STACK_LINE(269)
			::Class cl;		HX_STACK_VAR(cl,"cl");
			HX_STACK_LINE(269)
			if ((::Std_obj::is(Obj1,hx::ClassOf< ::Class >()))){
				HX_STACK_LINE(269)
				cl = Obj1;
			}
			else{
				HX_STACK_LINE(269)
				cl = ::Type_obj::getClass(Obj1);
			}
			HX_STACK_LINE(269)
			::String s = ::Type_obj::getClassName(cl);		HX_STACK_VAR(s,"s");
			HX_STACK_LINE(269)
			if (((s != null()))){
				HX_STACK_LINE(269)
				s = ::StringTools_obj::replace(s,HX_CSTRING("::"),HX_CSTRING("."));
				HX_STACK_LINE(269)
				if ((Simple)){
					HX_STACK_LINE(269)
					s = s.substr((s.lastIndexOf(HX_CSTRING("."),null()) + (int)1),null());
				}
			}
			HX_STACK_LINE(269)
			_g = s;
		}
		struct _Function_1_1{
			inline static ::String Block( Dynamic &Obj2,bool &Simple){
				HX_STACK_FRAME("*","closure",0x5bdab937,"*.closure","flixel/util/FlxStringUtil.hx",269,0x4e012e33)
				{
					HX_STACK_LINE(269)
					::Class cl;		HX_STACK_VAR(cl,"cl");
					HX_STACK_LINE(269)
					if ((::Std_obj::is(Obj2,hx::ClassOf< ::Class >()))){
						HX_STACK_LINE(269)
						cl = Obj2;
					}
					else{
						HX_STACK_LINE(269)
						cl = ::Type_obj::getClass(Obj2);
					}
					HX_STACK_LINE(269)
					::String s = ::Type_obj::getClassName(cl);		HX_STACK_VAR(s,"s");
					HX_STACK_LINE(269)
					if (((s != null()))){
						HX_STACK_LINE(269)
						s = ::StringTools_obj::replace(s,HX_CSTRING("::"),HX_CSTRING("."));
						HX_STACK_LINE(269)
						if ((Simple)){
							HX_STACK_LINE(269)
							s = s.substr((s.lastIndexOf(HX_CSTRING("."),null()) + (int)1),null());
						}
					}
					HX_STACK_LINE(269)
					return s;
				}
				return null();
			}
		};
		HX_STACK_LINE(269)
		return (_g == _Function_1_1::Block(Obj2,Simple));
	}
}


STATIC_HX_DEFINE_DYNAMIC_FUNC3(FlxStringUtil_obj,sameClassName,return )

Array< int > FlxStringUtil_obj::toIntArray( ::String Data){
	HX_STACK_FRAME("flixel.util.FlxStringUtil","toIntArray",0xa370d488,"flixel.util.FlxStringUtil.toIntArray","flixel/util/FlxStringUtil.hx",280,0x4e012e33)
	HX_STACK_ARG(Data,"Data")
	HX_STACK_LINE(281)
	if (((bool((Data != null())) && bool((Data != HX_CSTRING("")))))){
		HX_STACK_LINE(283)
		Array< ::String > strArray = Data.split(HX_CSTRING(","));		HX_STACK_VAR(strArray,"strArray");
		HX_STACK_LINE(284)
		Array< int > iArray = Array_obj< int >::__new();		HX_STACK_VAR(iArray,"iArray");
		HX_STACK_LINE(285)
		{
			HX_STACK_LINE(285)
			int _g = (int)0;		HX_STACK_VAR(_g,"_g");
			HX_STACK_LINE(285)
			while(((_g < strArray->length))){
				HX_STACK_LINE(285)
				::String str = strArray->__get(_g);		HX_STACK_VAR(str,"str");
				HX_STACK_LINE(285)
				++(_g);
				HX_STACK_LINE(287)
				iArray->push(::Std_obj::parseInt(str));
			}
		}
		HX_STACK_LINE(289)
		return iArray;
	}
	HX_STACK_LINE(291)
	return null();
}


STATIC_HX_DEFINE_DYNAMIC_FUNC1(FlxStringUtil_obj,toIntArray,return )

Array< Float > FlxStringUtil_obj::toFloatArray( ::String Data){
	HX_STACK_FRAME("flixel.util.FlxStringUtil","toFloatArray",0xcff15c3b,"flixel.util.FlxStringUtil.toFloatArray","flixel/util/FlxStringUtil.hx",301,0x4e012e33)
	HX_STACK_ARG(Data,"Data")
	HX_STACK_LINE(302)
	if (((bool((Data != null())) && bool((Data != HX_CSTRING("")))))){
		HX_STACK_LINE(304)
		Array< ::String > strArray = Data.split(HX_CSTRING(","));		HX_STACK_VAR(strArray,"strArray");
		HX_STACK_LINE(305)
		Array< Float > fArray = Array_obj< Float >::__new();		HX_STACK_VAR(fArray,"fArray");
		HX_STACK_LINE(306)
		{
			HX_STACK_LINE(306)
			int _g = (int)0;		HX_STACK_VAR(_g,"_g");
			HX_STACK_LINE(306)
			while(((_g < strArray->length))){
				HX_STACK_LINE(306)
				::String str = strArray->__get(_g);		HX_STACK_VAR(str,"str");
				HX_STACK_LINE(306)
				++(_g);
				HX_STACK_LINE(308)
				fArray->push(::Std_obj::parseFloat(str));
			}
		}
		HX_STACK_LINE(310)
		return fArray;
	}
	HX_STACK_LINE(312)
	return null();
}


STATIC_HX_DEFINE_DYNAMIC_FUNC1(FlxStringUtil_obj,toFloatArray,return )

::String FlxStringUtil_obj::arrayToCSV( Array< int > Data,int Width,hx::Null< bool >  __o_Invert){
bool Invert = __o_Invert.Default(false);
	HX_STACK_FRAME("flixel.util.FlxStringUtil","arrayToCSV",0xd181e275,"flixel.util.FlxStringUtil.arrayToCSV","flixel/util/FlxStringUtil.hx",324,0x4e012e33)
	HX_STACK_ARG(Data,"Data")
	HX_STACK_ARG(Width,"Width")
	HX_STACK_ARG(Invert,"Invert")
{
		HX_STACK_LINE(325)
		int row = (int)0;		HX_STACK_VAR(row,"row");
		HX_STACK_LINE(326)
		int column;		HX_STACK_VAR(column,"column");
		HX_STACK_LINE(327)
		::String csv = HX_CSTRING("");		HX_STACK_VAR(csv,"csv");
		HX_STACK_LINE(328)
		int Height = ::Std_obj::_int((Float(Data->length) / Float(Width)));		HX_STACK_VAR(Height,"Height");
		HX_STACK_LINE(329)
		int index;		HX_STACK_VAR(index,"index");
		HX_STACK_LINE(330)
		int offset = (int)0;		HX_STACK_VAR(offset,"offset");
		HX_STACK_LINE(332)
		while(((row < Height))){
			HX_STACK_LINE(334)
			column = (int)0;
			HX_STACK_LINE(336)
			while(((column < Width))){
				HX_STACK_LINE(338)
				index = Data->__get(offset);
				HX_STACK_LINE(340)
				if ((Invert)){
					HX_STACK_LINE(342)
					if (((index == (int)0))){
						HX_STACK_LINE(344)
						index = (int)1;
					}
					else{
						HX_STACK_LINE(346)
						if (((index == (int)1))){
							HX_STACK_LINE(348)
							index = (int)0;
						}
					}
				}
				HX_STACK_LINE(352)
				if (((column == (int)0))){
					HX_STACK_LINE(354)
					if (((row == (int)0))){
						HX_STACK_LINE(356)
						hx::AddEq(csv,index);
					}
					else{
						HX_STACK_LINE(360)
						hx::AddEq(csv,(HX_CSTRING("\n") + index));
					}
				}
				else{
					HX_STACK_LINE(365)
					hx::AddEq(csv,(HX_CSTRING(", ") + index));
				}
				HX_STACK_LINE(368)
				(column)++;
				HX_STACK_LINE(369)
				(offset)++;
			}
			HX_STACK_LINE(372)
			(row)++;
		}
		HX_STACK_LINE(375)
		return csv;
	}
}


STATIC_HX_DEFINE_DYNAMIC_FUNC3(FlxStringUtil_obj,arrayToCSV,return )

::String FlxStringUtil_obj::bitmapToCSV( ::flash::display::BitmapData Bitmap,hx::Null< bool >  __o_Invert,hx::Null< int >  __o_Scale,Array< int > ColorMap){
bool Invert = __o_Invert.Default(false);
int Scale = __o_Scale.Default(1);
	HX_STACK_FRAME("flixel.util.FlxStringUtil","bitmapToCSV",0x6fd72f79,"flixel.util.FlxStringUtil.bitmapToCSV","flixel/util/FlxStringUtil.hx",389,0x4e012e33)
	HX_STACK_ARG(Bitmap,"Bitmap")
	HX_STACK_ARG(Invert,"Invert")
	HX_STACK_ARG(Scale,"Scale")
	HX_STACK_ARG(ColorMap,"ColorMap")
{
		HX_STACK_LINE(390)
		if (((Scale < (int)1))){
			HX_STACK_LINE(392)
			Scale = (int)1;
		}
		HX_STACK_LINE(396)
		if (((Scale > (int)1))){
			HX_STACK_LINE(398)
			::flash::display::BitmapData bd = Bitmap;		HX_STACK_VAR(bd,"bd");
			HX_STACK_LINE(399)
			int _g = (Bitmap->get_width() * Scale);		HX_STACK_VAR(_g,"_g");
			HX_STACK_LINE(399)
			Bitmap = ::flash::display::BitmapData_obj::__new(_g,(Bitmap->get_height() * Scale),null(),null(),null());
			HX_STACK_LINE(422)
			::flash::geom::Matrix mtx = ::flash::geom::Matrix_obj::__new(null(),null(),null(),null(),null(),null());		HX_STACK_VAR(mtx,"mtx");
			HX_STACK_LINE(423)
			mtx->scale(Scale,Scale);
			HX_STACK_LINE(424)
			Bitmap->draw(bd,mtx,null(),null(),null(),null());
		}
		HX_STACK_LINE(429)
		int row = (int)0;		HX_STACK_VAR(row,"row");
		HX_STACK_LINE(430)
		int column;		HX_STACK_VAR(column,"column");
		HX_STACK_LINE(431)
		int pixel;		HX_STACK_VAR(pixel,"pixel");
		HX_STACK_LINE(432)
		::String csv = HX_CSTRING("");		HX_STACK_VAR(csv,"csv");
		HX_STACK_LINE(433)
		int bitmapWidth = Bitmap->get_width();		HX_STACK_VAR(bitmapWidth,"bitmapWidth");
		HX_STACK_LINE(434)
		int bitmapHeight = Bitmap->get_height();		HX_STACK_VAR(bitmapHeight,"bitmapHeight");
		HX_STACK_LINE(436)
		while(((row < bitmapHeight))){
			HX_STACK_LINE(438)
			column = (int)0;
			HX_STACK_LINE(440)
			while(((column < bitmapWidth))){
				HX_STACK_LINE(443)
				pixel = Bitmap->getPixel(column,row);
				HX_STACK_LINE(445)
				if (((ColorMap != null()))){
					HX_STACK_LINE(447)
					pixel = ::flixel::util::FlxArrayUtil_obj::indexOf_Int(ColorMap,pixel,null());
				}
				else{
					HX_STACK_LINE(449)
					if (((bool((bool(Invert) && bool((pixel > (int)0)))) || bool((bool(!(Invert)) && bool((pixel == (int)0))))))){
						HX_STACK_LINE(451)
						pixel = (int)1;
					}
					else{
						HX_STACK_LINE(455)
						pixel = (int)0;
					}
				}
				HX_STACK_LINE(459)
				if (((column == (int)0))){
					HX_STACK_LINE(461)
					if (((row == (int)0))){
						HX_STACK_LINE(463)
						hx::AddEq(csv,pixel);
					}
					else{
						HX_STACK_LINE(467)
						hx::AddEq(csv,(HX_CSTRING("\n") + pixel));
					}
				}
				else{
					HX_STACK_LINE(472)
					hx::AddEq(csv,(HX_CSTRING(", ") + pixel));
				}
				HX_STACK_LINE(475)
				(column)++;
			}
			HX_STACK_LINE(478)
			(row)++;
		}
		HX_STACK_LINE(481)
		return csv;
	}
}


STATIC_HX_DEFINE_DYNAMIC_FUNC4(FlxStringUtil_obj,bitmapToCSV,return )

::String FlxStringUtil_obj::imageToCSV( Dynamic ImageFile,hx::Null< bool >  __o_Invert,hx::Null< int >  __o_Scale){
bool Invert = __o_Invert.Default(false);
int Scale = __o_Scale.Default(1);
	HX_STACK_FRAME("flixel.util.FlxStringUtil","imageToCSV",0xe3229173,"flixel.util.FlxStringUtil.imageToCSV","flixel/util/FlxStringUtil.hx",494,0x4e012e33)
	HX_STACK_ARG(ImageFile,"ImageFile")
	HX_STACK_ARG(Invert,"Invert")
	HX_STACK_ARG(Scale,"Scale")
{
		HX_STACK_LINE(495)
		::flash::display::BitmapData tempBitmapData;		HX_STACK_VAR(tempBitmapData,"tempBitmapData");
		HX_STACK_LINE(497)
		if ((::Std_obj::is(ImageFile,hx::ClassOf< ::String >()))){
			HX_STACK_LINE(499)
			::String id = ImageFile;		HX_STACK_VAR(id,"id");
			HX_STACK_LINE(499)
			tempBitmapData = ::openfl::Assets_obj::getBitmapData(id,false);
		}
		else{
			HX_STACK_LINE(503)
			tempBitmapData = ::Type_obj::createInstance(ImageFile,Dynamic( Array_obj<Dynamic>::__new()))->__Field(HX_CSTRING("bitmapData"),true);
		}
		HX_STACK_LINE(506)
		return ::flixel::util::FlxStringUtil_obj::bitmapToCSV(tempBitmapData,Invert,Scale,null());
	}
}


STATIC_HX_DEFINE_DYNAMIC_FUNC3(FlxStringUtil_obj,imageToCSV,return )

::String FlxStringUtil_obj::getDebugString( Dynamic LabelValuePairs){
	HX_STACK_FRAME("flixel.util.FlxStringUtil","getDebugString",0x47d891d1,"flixel.util.FlxStringUtil.getDebugString","flixel/util/FlxStringUtil.hx",516,0x4e012e33)
	HX_STACK_ARG(LabelValuePairs,"LabelValuePairs")
	HX_STACK_LINE(517)
	::String output = HX_CSTRING("(");		HX_STACK_VAR(output,"output");
	HX_STACK_LINE(518)
	{
		HX_STACK_LINE(518)
		int _g = (int)0;		HX_STACK_VAR(_g,"_g");
		HX_STACK_LINE(518)
		while(((_g < LabelValuePairs->__Field(HX_CSTRING("length"),true)))){
			HX_STACK_LINE(518)
			Dynamic pair = LabelValuePairs->__GetItem(_g);		HX_STACK_VAR(pair,"pair");
			HX_STACK_LINE(518)
			++(_g);
			HX_STACK_LINE(520)
			hx::AddEq(output,(pair->__Field(HX_CSTRING("label"),true) + HX_CSTRING(": ")));
			HX_STACK_LINE(521)
			Dynamic value = pair->__Field(HX_CSTRING("value"),true);		HX_STACK_VAR(value,"value");
			HX_STACK_LINE(522)
			if ((::Std_obj::is(value,hx::ClassOf< ::Float >()))){
				HX_STACK_LINE(524)
				value = ::flixel::util::FlxMath_obj::roundDecimal(value,::flixel::FlxG_obj::debugger->precision);
			}
			HX_STACK_LINE(526)
			hx::AddEq(output,(::Std_obj::string(value) + HX_CSTRING(" | ")));
		}
	}
	HX_STACK_LINE(529)
	output = ::StringTools_obj::trim(output.substr((int)0,(output.length - (int)2)));
	HX_STACK_LINE(530)
	return (output + HX_CSTRING(")"));
}


STATIC_HX_DEFINE_DYNAMIC_FUNC1(FlxStringUtil_obj,getDebugString,return )


FlxStringUtil_obj::FlxStringUtil_obj()
{
}

Dynamic FlxStringUtil_obj::__Field(const ::String &inName,bool inCallProp)
{
	switch(inName.length) {
	case 9:
		if (HX_FIELD_EQ(inName,"getDomain") ) { return getDomain_dyn(); }
		break;
	case 10:
		if (HX_FIELD_EQ(inName,"formatTime") ) { return formatTime_dyn(); }
		if (HX_FIELD_EQ(inName,"htmlFormat") ) { return htmlFormat_dyn(); }
		if (HX_FIELD_EQ(inName,"toIntArray") ) { return toIntArray_dyn(); }
		if (HX_FIELD_EQ(inName,"arrayToCSV") ) { return arrayToCSV_dyn(); }
		if (HX_FIELD_EQ(inName,"imageToCSV") ) { return imageToCSV_dyn(); }
		break;
	case 11:
		if (HX_FIELD_EQ(inName,"formatTicks") ) { return formatTicks_dyn(); }
		if (HX_FIELD_EQ(inName,"formatArray") ) { return formatArray_dyn(); }
		if (HX_FIELD_EQ(inName,"formatMoney") ) { return formatMoney_dyn(); }
		if (HX_FIELD_EQ(inName,"bitmapToCSV") ) { return bitmapToCSV_dyn(); }
		break;
	case 12:
		if (HX_FIELD_EQ(inName,"filterDigits") ) { return filterDigits_dyn(); }
		if (HX_FIELD_EQ(inName,"toFloatArray") ) { return toFloatArray_dyn(); }
		break;
	case 13:
		if (HX_FIELD_EQ(inName,"sameClassName") ) { return sameClassName_dyn(); }
		break;
	case 14:
		if (HX_FIELD_EQ(inName,"getDebugString") ) { return getDebugString_dyn(); }
		break;
	case 15:
		if (HX_FIELD_EQ(inName,"formatStringMap") ) { return formatStringMap_dyn(); }
	}
	return super::__Field(inName,inCallProp);
}

Dynamic FlxStringUtil_obj::__SetField(const ::String &inName,const Dynamic &inValue,bool inCallProp)
{
	return super::__SetField(inName,inValue,inCallProp);
}

void FlxStringUtil_obj::__GetFields(Array< ::String> &outFields)
{
	super::__GetFields(outFields);
};

static ::String sStaticFields[] = {
	HX_CSTRING("formatTicks"),
	HX_CSTRING("formatTime"),
	HX_CSTRING("formatArray"),
	HX_CSTRING("formatStringMap"),
	HX_CSTRING("formatMoney"),
	HX_CSTRING("filterDigits"),
	HX_CSTRING("htmlFormat"),
	HX_CSTRING("getDomain"),
	HX_CSTRING("sameClassName"),
	HX_CSTRING("toIntArray"),
	HX_CSTRING("toFloatArray"),
	HX_CSTRING("arrayToCSV"),
	HX_CSTRING("bitmapToCSV"),
	HX_CSTRING("imageToCSV"),
	HX_CSTRING("getDebugString"),
	String(null()) };

#if HXCPP_SCRIPTABLE
static hx::StorageInfo *sMemberStorageInfo = 0;
#endif

static ::String sMemberFields[] = {
	String(null()) };

static void sMarkStatics(HX_MARK_PARAMS) {
	HX_MARK_MEMBER_NAME(FlxStringUtil_obj::__mClass,"__mClass");
};

#ifdef HXCPP_VISIT_ALLOCS
static void sVisitStatics(HX_VISIT_PARAMS) {
	HX_VISIT_MEMBER_NAME(FlxStringUtil_obj::__mClass,"__mClass");
};

#endif

Class FlxStringUtil_obj::__mClass;

void FlxStringUtil_obj::__register()
{
	hx::Static(__mClass) = hx::RegisterClass(HX_CSTRING("flixel.util.FlxStringUtil"), hx::TCanCast< FlxStringUtil_obj> ,sStaticFields,sMemberFields,
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

void FlxStringUtil_obj::__boot()
{
}

} // end namespace flixel
} // end namespace util
