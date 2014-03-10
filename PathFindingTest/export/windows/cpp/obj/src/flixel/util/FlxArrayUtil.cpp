#include <hxcpp.h>

#ifndef INCLUDED_flash_display_DisplayObject
#include <flash/display/DisplayObject.h>
#endif
#ifndef INCLUDED_flash_display_DisplayObjectContainer
#include <flash/display/DisplayObjectContainer.h>
#endif
#ifndef INCLUDED_flash_display_IBitmapDrawable
#include <flash/display/IBitmapDrawable.h>
#endif
#ifndef INCLUDED_flash_display_InteractiveObject
#include <flash/display/InteractiveObject.h>
#endif
#ifndef INCLUDED_flash_display_Sprite
#include <flash/display/Sprite.h>
#endif
#ifndef INCLUDED_flash_events_EventDispatcher
#include <flash/events/EventDispatcher.h>
#endif
#ifndef INCLUDED_flash_events_IEventDispatcher
#include <flash/events/IEventDispatcher.h>
#endif
#ifndef INCLUDED_flixel_FlxBasic
#include <flixel/FlxBasic.h>
#endif
#ifndef INCLUDED_flixel_FlxCamera
#include <flixel/FlxCamera.h>
#endif
#ifndef INCLUDED_flixel_input_keyboard_FlxKey
#include <flixel/input/keyboard/FlxKey.h>
#endif
#ifndef INCLUDED_flixel_interfaces_IFlxDestroyable
#include <flixel/interfaces/IFlxDestroyable.h>
#endif
#ifndef INCLUDED_flixel_system_debug_WatchEntry
#include <flixel/system/debug/WatchEntry.h>
#endif
#ifndef INCLUDED_flixel_system_layer_frames_FlxFrame
#include <flixel/system/layer/frames/FlxFrame.h>
#endif
#ifndef INCLUDED_flixel_system_replay_FrameRecord
#include <flixel/system/replay/FrameRecord.h>
#endif
#ifndef INCLUDED_flixel_system_ui_FlxSystemButton
#include <flixel/system/ui/FlxSystemButton.h>
#endif
#ifndef INCLUDED_flixel_text_FlxTextFormat
#include <flixel/text/FlxTextFormat.h>
#endif
#ifndef INCLUDED_flixel_tweens_FlxTween
#include <flixel/tweens/FlxTween.h>
#endif
#ifndef INCLUDED_flixel_util_FlxArrayUtil
#include <flixel/util/FlxArrayUtil.h>
#endif
#ifndef INCLUDED_flixel_util_FlxPath
#include <flixel/util/FlxPath.h>
#endif
#ifndef INCLUDED_flixel_util_FlxPoint
#include <flixel/util/FlxPoint.h>
#endif
#ifndef INCLUDED_flixel_util_FlxRandom
#include <flixel/util/FlxRandom.h>
#endif
#ifndef INCLUDED_flixel_util_FlxTimer
#include <flixel/util/FlxTimer.h>
#endif
namespace flixel{
namespace util{

Void FlxArrayUtil_obj::__construct()
{
	return null();
}

//FlxArrayUtil_obj::~FlxArrayUtil_obj() { }

Dynamic FlxArrayUtil_obj::__CreateEmpty() { return  new FlxArrayUtil_obj; }
hx::ObjectPtr< FlxArrayUtil_obj > FlxArrayUtil_obj::__new()
{  hx::ObjectPtr< FlxArrayUtil_obj > result = new FlxArrayUtil_obj();
	result->__construct();
	return result;}

Dynamic FlxArrayUtil_obj::__Create(hx::DynamicArray inArgs)
{  hx::ObjectPtr< FlxArrayUtil_obj > result = new FlxArrayUtil_obj();
	result->__construct();
	return result;}

Array< ::Dynamic > FlxArrayUtil_obj::fastSplice_flixel_text_FlxTextFormat( Array< ::Dynamic > array,::flixel::text::FlxTextFormat element){
	HX_STACK_FRAME("flixel.util.FlxArrayUtil","fastSplice_flixel_text_FlxTextFormat",0xed3cac0b,"flixel.util.FlxArrayUtil.fastSplice_flixel_text_FlxTextFormat","flixel/util/FlxArrayUtil.hx",98,0xa0dc755b)
	HX_STACK_ARG(array,"array")
	HX_STACK_ARG(element,"element")
	HX_STACK_LINE(99)
	int index = ::flixel::util::FlxArrayUtil_obj::indexOf_fastSplice_T(array,element,null());		HX_STACK_VAR(index,"index");
	HX_STACK_LINE(100)
	if (((index >= (int)0))){
		HX_STACK_LINE(102)
		array[index] = array->__get((array->length - (int)1)).StaticCast< ::flixel::text::FlxTextFormat >();
		HX_STACK_LINE(103)
		array->pop().StaticCast< ::flixel::text::FlxTextFormat >();
	}
	HX_STACK_LINE(105)
	return array;
}


STATIC_HX_DEFINE_DYNAMIC_FUNC2(FlxArrayUtil_obj,fastSplice_flixel_text_FlxTextFormat,return )

Void FlxArrayUtil_obj::setLength_flixel_system_replay_FrameRecord( Array< ::Dynamic > array,int newLength){
{
		HX_STACK_FRAME("flixel.util.FlxArrayUtil","setLength_flixel_system_replay_FrameRecord",0x79844eb5,"flixel.util.FlxArrayUtil.setLength_flixel_system_replay_FrameRecord","flixel/util/FlxArrayUtil.hx",43,0xa0dc755b)
		HX_STACK_ARG(array,"array")
		HX_STACK_ARG(newLength,"newLength")
		HX_STACK_LINE(44)
		if (((newLength < (int)0))){
			HX_STACK_LINE(44)
			return null();
		}
		HX_STACK_LINE(45)
		int oldLength = array->length;		HX_STACK_VAR(oldLength,"oldLength");
		HX_STACK_LINE(46)
		int diff = (newLength - oldLength);		HX_STACK_VAR(diff,"diff");
		HX_STACK_LINE(47)
		if (((diff < (int)0))){
			HX_STACK_LINE(52)
			diff = -(diff);
			HX_STACK_LINE(53)
			{
				HX_STACK_LINE(53)
				int _g = (int)0;		HX_STACK_VAR(_g,"_g");
				HX_STACK_LINE(53)
				while(((_g < diff))){
					HX_STACK_LINE(53)
					int i = (_g)++;		HX_STACK_VAR(i,"i");
					HX_STACK_LINE(55)
					array->pop().StaticCast< ::flixel::system::replay::FrameRecord >();
				}
			}
		}
	}
return null();
}


STATIC_HX_DEFINE_DYNAMIC_FUNC2(FlxArrayUtil_obj,setLength_flixel_system_replay_FrameRecord,(void))

Dynamic FlxArrayUtil_obj::getRandom_flixel_group_FlxTypedGroup_T( Dynamic Objects,hx::Null< int >  __o_StartIndex,hx::Null< int >  __o_EndIndex){
int StartIndex = __o_StartIndex.Default(0);
int EndIndex = __o_EndIndex.Default(0);
	HX_STACK_FRAME("flixel.util.FlxArrayUtil","getRandom_flixel_group_FlxTypedGroup_T",0x238278ca,"flixel.util.FlxArrayUtil.getRandom_flixel_group_FlxTypedGroup_T","flixel/util/FlxArrayUtil.hx",85,0xa0dc755b)
	HX_STACK_ARG(Objects,"Objects")
	HX_STACK_ARG(StartIndex,"StartIndex")
	HX_STACK_ARG(EndIndex,"EndIndex")
{
		HX_STACK_LINE(85)
		return ::flixel::util::FlxRandom_obj::getObject_getRandom_T(Objects,StartIndex,EndIndex);
	}
}


STATIC_HX_DEFINE_DYNAMIC_FUNC3(FlxArrayUtil_obj,getRandom_flixel_group_FlxTypedGroup_T,return )

Void FlxArrayUtil_obj::setLength_flixel_input_keyboard_FlxKey( Array< ::Dynamic > array,int newLength){
{
		HX_STACK_FRAME("flixel.util.FlxArrayUtil","setLength_flixel_input_keyboard_FlxKey",0xfee37d4f,"flixel.util.FlxArrayUtil.setLength_flixel_input_keyboard_FlxKey","flixel/util/FlxArrayUtil.hx",43,0xa0dc755b)
		HX_STACK_ARG(array,"array")
		HX_STACK_ARG(newLength,"newLength")
		HX_STACK_LINE(44)
		if (((newLength < (int)0))){
			HX_STACK_LINE(44)
			return null();
		}
		HX_STACK_LINE(45)
		int oldLength = array->length;		HX_STACK_VAR(oldLength,"oldLength");
		HX_STACK_LINE(46)
		int diff = (newLength - oldLength);		HX_STACK_VAR(diff,"diff");
		HX_STACK_LINE(47)
		if (((diff < (int)0))){
			HX_STACK_LINE(52)
			diff = -(diff);
			HX_STACK_LINE(53)
			{
				HX_STACK_LINE(53)
				int _g = (int)0;		HX_STACK_VAR(_g,"_g");
				HX_STACK_LINE(53)
				while(((_g < diff))){
					HX_STACK_LINE(53)
					int i = (_g)++;		HX_STACK_VAR(i,"i");
					HX_STACK_LINE(55)
					array->pop().StaticCast< ::flixel::input::keyboard::FlxKey >();
				}
			}
		}
	}
return null();
}


STATIC_HX_DEFINE_DYNAMIC_FUNC2(FlxArrayUtil_obj,setLength_flixel_input_keyboard_FlxKey,(void))

int FlxArrayUtil_obj::indexOf_flixel_FlxCamera( Array< ::Dynamic > array,::flixel::FlxCamera whatToFind,hx::Null< int >  __o_fromIndex){
int fromIndex = __o_fromIndex.Default(0);
	HX_STACK_FRAME("flixel.util.FlxArrayUtil","indexOf_flixel_FlxCamera",0xccc86015,"flixel.util.FlxArrayUtil.indexOf_flixel_FlxCamera","flixel/util/FlxArrayUtil.hx",18,0xa0dc755b)
	HX_STACK_ARG(array,"array")
	HX_STACK_ARG(whatToFind,"whatToFind")
	HX_STACK_ARG(fromIndex,"fromIndex")
{
		HX_STACK_LINE(22)
		int index = (int)-1;		HX_STACK_VAR(index,"index");
		HX_STACK_LINE(23)
		int len = array->length;		HX_STACK_VAR(len,"len");
		HX_STACK_LINE(24)
		{
			HX_STACK_LINE(24)
			int _g = fromIndex;		HX_STACK_VAR(_g,"_g");
			HX_STACK_LINE(24)
			while(((_g < len))){
				HX_STACK_LINE(24)
				int i = (_g)++;		HX_STACK_VAR(i,"i");
				HX_STACK_LINE(26)
				if (((array->__get(i).StaticCast< ::flixel::FlxCamera >() == whatToFind))){
					HX_STACK_LINE(28)
					index = i;
					HX_STACK_LINE(29)
					break;
				}
			}
		}
		HX_STACK_LINE(32)
		return index;
	}
}


STATIC_HX_DEFINE_DYNAMIC_FUNC3(FlxArrayUtil_obj,indexOf_flixel_FlxCamera,return )

Void FlxArrayUtil_obj::setLength_Int( Array< int > array,int newLength){
{
		HX_STACK_FRAME("flixel.util.FlxArrayUtil","setLength_Int",0x3efc372d,"flixel.util.FlxArrayUtil.setLength_Int","flixel/util/FlxArrayUtil.hx",43,0xa0dc755b)
		HX_STACK_ARG(array,"array")
		HX_STACK_ARG(newLength,"newLength")
		HX_STACK_LINE(44)
		if (((newLength < (int)0))){
			HX_STACK_LINE(44)
			return null();
		}
		HX_STACK_LINE(45)
		int oldLength = array->length;		HX_STACK_VAR(oldLength,"oldLength");
		HX_STACK_LINE(46)
		int diff = (newLength - oldLength);		HX_STACK_VAR(diff,"diff");
		HX_STACK_LINE(47)
		if (((diff < (int)0))){
			HX_STACK_LINE(52)
			diff = -(diff);
			HX_STACK_LINE(53)
			{
				HX_STACK_LINE(53)
				int _g = (int)0;		HX_STACK_VAR(_g,"_g");
				HX_STACK_LINE(53)
				while(((_g < diff))){
					HX_STACK_LINE(53)
					int i = (_g)++;		HX_STACK_VAR(i,"i");
					HX_STACK_LINE(55)
					array->pop();
				}
			}
		}
	}
return null();
}


STATIC_HX_DEFINE_DYNAMIC_FUNC2(FlxArrayUtil_obj,setLength_Int,(void))

Array< ::Dynamic > FlxArrayUtil_obj::fastSplice_flixel_tweens_FlxTween( Array< ::Dynamic > array,::flixel::tweens::FlxTween element){
	HX_STACK_FRAME("flixel.util.FlxArrayUtil","fastSplice_flixel_tweens_FlxTween",0x134d3569,"flixel.util.FlxArrayUtil.fastSplice_flixel_tweens_FlxTween","flixel/util/FlxArrayUtil.hx",98,0xa0dc755b)
	HX_STACK_ARG(array,"array")
	HX_STACK_ARG(element,"element")
	HX_STACK_LINE(99)
	int index = ::flixel::util::FlxArrayUtil_obj::indexOf_fastSplice_T(array,element,null());		HX_STACK_VAR(index,"index");
	HX_STACK_LINE(100)
	if (((index >= (int)0))){
		HX_STACK_LINE(102)
		array[index] = array->__get((array->length - (int)1)).StaticCast< ::flixel::tweens::FlxTween >();
		HX_STACK_LINE(103)
		array->pop().StaticCast< ::flixel::tweens::FlxTween >();
	}
	HX_STACK_LINE(105)
	return array;
}


STATIC_HX_DEFINE_DYNAMIC_FUNC2(FlxArrayUtil_obj,fastSplice_flixel_tweens_FlxTween,return )

int FlxArrayUtil_obj::indexOf_flixel_tweens_FlxTween( Array< ::Dynamic > array,::flixel::tweens::FlxTween whatToFind,hx::Null< int >  __o_fromIndex){
int fromIndex = __o_fromIndex.Default(0);
	HX_STACK_FRAME("flixel.util.FlxArrayUtil","indexOf_flixel_tweens_FlxTween",0x70f3556e,"flixel.util.FlxArrayUtil.indexOf_flixel_tweens_FlxTween","flixel/util/FlxArrayUtil.hx",18,0xa0dc755b)
	HX_STACK_ARG(array,"array")
	HX_STACK_ARG(whatToFind,"whatToFind")
	HX_STACK_ARG(fromIndex,"fromIndex")
{
		HX_STACK_LINE(22)
		int index = (int)-1;		HX_STACK_VAR(index,"index");
		HX_STACK_LINE(23)
		int len = array->length;		HX_STACK_VAR(len,"len");
		HX_STACK_LINE(24)
		{
			HX_STACK_LINE(24)
			int _g = fromIndex;		HX_STACK_VAR(_g,"_g");
			HX_STACK_LINE(24)
			while(((_g < len))){
				HX_STACK_LINE(24)
				int i = (_g)++;		HX_STACK_VAR(i,"i");
				HX_STACK_LINE(26)
				if (((array->__get(i).StaticCast< ::flixel::tweens::FlxTween >() == whatToFind))){
					HX_STACK_LINE(28)
					index = i;
					HX_STACK_LINE(29)
					break;
				}
			}
		}
		HX_STACK_LINE(32)
		return index;
	}
}


STATIC_HX_DEFINE_DYNAMIC_FUNC3(FlxArrayUtil_obj,indexOf_flixel_tweens_FlxTween,return )

Void FlxArrayUtil_obj::setLength_Float( Array< Float > array,int newLength){
{
		HX_STACK_FRAME("flixel.util.FlxArrayUtil","setLength_Float",0x64507b5a,"flixel.util.FlxArrayUtil.setLength_Float","flixel/util/FlxArrayUtil.hx",43,0xa0dc755b)
		HX_STACK_ARG(array,"array")
		HX_STACK_ARG(newLength,"newLength")
		HX_STACK_LINE(44)
		if (((newLength < (int)0))){
			HX_STACK_LINE(44)
			return null();
		}
		HX_STACK_LINE(45)
		int oldLength = array->length;		HX_STACK_VAR(oldLength,"oldLength");
		HX_STACK_LINE(46)
		int diff = (newLength - oldLength);		HX_STACK_VAR(diff,"diff");
		HX_STACK_LINE(47)
		if (((diff < (int)0))){
			HX_STACK_LINE(52)
			diff = -(diff);
			HX_STACK_LINE(53)
			{
				HX_STACK_LINE(53)
				int _g = (int)0;		HX_STACK_VAR(_g,"_g");
				HX_STACK_LINE(53)
				while(((_g < diff))){
					HX_STACK_LINE(53)
					int i = (_g)++;		HX_STACK_VAR(i,"i");
					HX_STACK_LINE(55)
					array->pop();
				}
			}
		}
	}
return null();
}


STATIC_HX_DEFINE_DYNAMIC_FUNC2(FlxArrayUtil_obj,setLength_Float,(void))

Void FlxArrayUtil_obj::setLength_String( Array< ::String > array,int newLength){
{
		HX_STACK_FRAME("flixel.util.FlxArrayUtil","setLength_String",0x31f57953,"flixel.util.FlxArrayUtil.setLength_String","flixel/util/FlxArrayUtil.hx",43,0xa0dc755b)
		HX_STACK_ARG(array,"array")
		HX_STACK_ARG(newLength,"newLength")
		HX_STACK_LINE(44)
		if (((newLength < (int)0))){
			HX_STACK_LINE(44)
			return null();
		}
		HX_STACK_LINE(45)
		int oldLength = array->length;		HX_STACK_VAR(oldLength,"oldLength");
		HX_STACK_LINE(46)
		int diff = (newLength - oldLength);		HX_STACK_VAR(diff,"diff");
		HX_STACK_LINE(47)
		if (((diff < (int)0))){
			HX_STACK_LINE(52)
			diff = -(diff);
			HX_STACK_LINE(53)
			{
				HX_STACK_LINE(53)
				int _g = (int)0;		HX_STACK_VAR(_g,"_g");
				HX_STACK_LINE(53)
				while(((_g < diff))){
					HX_STACK_LINE(53)
					int i = (_g)++;		HX_STACK_VAR(i,"i");
					HX_STACK_LINE(55)
					array->pop();
				}
			}
		}
	}
return null();
}


STATIC_HX_DEFINE_DYNAMIC_FUNC2(FlxArrayUtil_obj,setLength_String,(void))

Array< ::Dynamic > FlxArrayUtil_obj::fastSplice_flixel_util_FlxTimer( Array< ::Dynamic > array,::flixel::util::FlxTimer element){
	HX_STACK_FRAME("flixel.util.FlxArrayUtil","fastSplice_flixel_util_FlxTimer",0x46676ae9,"flixel.util.FlxArrayUtil.fastSplice_flixel_util_FlxTimer","flixel/util/FlxArrayUtil.hx",98,0xa0dc755b)
	HX_STACK_ARG(array,"array")
	HX_STACK_ARG(element,"element")
	HX_STACK_LINE(99)
	int index = ::flixel::util::FlxArrayUtil_obj::indexOf_fastSplice_T(array,element,null());		HX_STACK_VAR(index,"index");
	HX_STACK_LINE(100)
	if (((index >= (int)0))){
		HX_STACK_LINE(102)
		array[index] = array->__get((array->length - (int)1)).StaticCast< ::flixel::util::FlxTimer >();
		HX_STACK_LINE(103)
		array->pop().StaticCast< ::flixel::util::FlxTimer >();
	}
	HX_STACK_LINE(105)
	return array;
}


STATIC_HX_DEFINE_DYNAMIC_FUNC2(FlxArrayUtil_obj,fastSplice_flixel_util_FlxTimer,return )

int FlxArrayUtil_obj::indexOf_flixel_util_FlxTimer( Array< ::Dynamic > array,::flixel::util::FlxTimer whatToFind,hx::Null< int >  __o_fromIndex){
int fromIndex = __o_fromIndex.Default(0);
	HX_STACK_FRAME("flixel.util.FlxArrayUtil","indexOf_flixel_util_FlxTimer",0x71470fae,"flixel.util.FlxArrayUtil.indexOf_flixel_util_FlxTimer","flixel/util/FlxArrayUtil.hx",18,0xa0dc755b)
	HX_STACK_ARG(array,"array")
	HX_STACK_ARG(whatToFind,"whatToFind")
	HX_STACK_ARG(fromIndex,"fromIndex")
{
		HX_STACK_LINE(22)
		int index = (int)-1;		HX_STACK_VAR(index,"index");
		HX_STACK_LINE(23)
		int len = array->length;		HX_STACK_VAR(len,"len");
		HX_STACK_LINE(24)
		{
			HX_STACK_LINE(24)
			int _g = fromIndex;		HX_STACK_VAR(_g,"_g");
			HX_STACK_LINE(24)
			while(((_g < len))){
				HX_STACK_LINE(24)
				int i = (_g)++;		HX_STACK_VAR(i,"i");
				HX_STACK_LINE(26)
				if (((array->__get(i).StaticCast< ::flixel::util::FlxTimer >() == whatToFind))){
					HX_STACK_LINE(28)
					index = i;
					HX_STACK_LINE(29)
					break;
				}
			}
		}
		HX_STACK_LINE(32)
		return index;
	}
}


STATIC_HX_DEFINE_DYNAMIC_FUNC3(FlxArrayUtil_obj,indexOf_flixel_util_FlxTimer,return )

int FlxArrayUtil_obj::indexOf_flixel_util_FlxPoint( Array< ::Dynamic > array,::flixel::util::FlxPoint whatToFind,hx::Null< int >  __o_fromIndex){
int fromIndex = __o_fromIndex.Default(0);
	HX_STACK_FRAME("flixel.util.FlxArrayUtil","indexOf_flixel_util_FlxPoint",0x27a10439,"flixel.util.FlxArrayUtil.indexOf_flixel_util_FlxPoint","flixel/util/FlxArrayUtil.hx",18,0xa0dc755b)
	HX_STACK_ARG(array,"array")
	HX_STACK_ARG(whatToFind,"whatToFind")
	HX_STACK_ARG(fromIndex,"fromIndex")
{
		HX_STACK_LINE(22)
		int index = (int)-1;		HX_STACK_VAR(index,"index");
		HX_STACK_LINE(23)
		int len = array->length;		HX_STACK_VAR(len,"len");
		HX_STACK_LINE(24)
		{
			HX_STACK_LINE(24)
			int _g = fromIndex;		HX_STACK_VAR(_g,"_g");
			HX_STACK_LINE(24)
			while(((_g < len))){
				HX_STACK_LINE(24)
				int i = (_g)++;		HX_STACK_VAR(i,"i");
				HX_STACK_LINE(26)
				if (((array->__get(i).StaticCast< ::flixel::util::FlxPoint >() == whatToFind))){
					HX_STACK_LINE(28)
					index = i;
					HX_STACK_LINE(29)
					break;
				}
			}
		}
		HX_STACK_LINE(32)
		return index;
	}
}


STATIC_HX_DEFINE_DYNAMIC_FUNC3(FlxArrayUtil_obj,indexOf_flixel_util_FlxPoint,return )

Array< ::Dynamic > FlxArrayUtil_obj::fastSplice_flixel_util_FlxPath( Array< ::Dynamic > array,::flixel::util::FlxPath element){
	HX_STACK_FRAME("flixel.util.FlxArrayUtil","fastSplice_flixel_util_FlxPath",0xb8c4eb01,"flixel.util.FlxArrayUtil.fastSplice_flixel_util_FlxPath","flixel/util/FlxArrayUtil.hx",98,0xa0dc755b)
	HX_STACK_ARG(array,"array")
	HX_STACK_ARG(element,"element")
	HX_STACK_LINE(99)
	int index = ::flixel::util::FlxArrayUtil_obj::indexOf_fastSplice_T(array,element,null());		HX_STACK_VAR(index,"index");
	HX_STACK_LINE(100)
	if (((index >= (int)0))){
		HX_STACK_LINE(102)
		array[index] = array->__get((array->length - (int)1)).StaticCast< ::flixel::util::FlxPath >();
		HX_STACK_LINE(103)
		array->pop().StaticCast< ::flixel::util::FlxPath >();
	}
	HX_STACK_LINE(105)
	return array;
}


STATIC_HX_DEFINE_DYNAMIC_FUNC2(FlxArrayUtil_obj,fastSplice_flixel_util_FlxPath,return )

int FlxArrayUtil_obj::indexOf_flixel_util_FlxPath( Array< ::Dynamic > array,::flixel::util::FlxPath whatToFind,hx::Null< int >  __o_fromIndex){
int fromIndex = __o_fromIndex.Default(0);
	HX_STACK_FRAME("flixel.util.FlxArrayUtil","indexOf_flixel_util_FlxPath",0xedc4c5dc,"flixel.util.FlxArrayUtil.indexOf_flixel_util_FlxPath","flixel/util/FlxArrayUtil.hx",18,0xa0dc755b)
	HX_STACK_ARG(array,"array")
	HX_STACK_ARG(whatToFind,"whatToFind")
	HX_STACK_ARG(fromIndex,"fromIndex")
{
		HX_STACK_LINE(22)
		int index = (int)-1;		HX_STACK_VAR(index,"index");
		HX_STACK_LINE(23)
		int len = array->length;		HX_STACK_VAR(len,"len");
		HX_STACK_LINE(24)
		{
			HX_STACK_LINE(24)
			int _g = fromIndex;		HX_STACK_VAR(_g,"_g");
			HX_STACK_LINE(24)
			while(((_g < len))){
				HX_STACK_LINE(24)
				int i = (_g)++;		HX_STACK_VAR(i,"i");
				HX_STACK_LINE(26)
				if (((array->__get(i).StaticCast< ::flixel::util::FlxPath >() == whatToFind))){
					HX_STACK_LINE(28)
					index = i;
					HX_STACK_LINE(29)
					break;
				}
			}
		}
		HX_STACK_LINE(32)
		return index;
	}
}


STATIC_HX_DEFINE_DYNAMIC_FUNC3(FlxArrayUtil_obj,indexOf_flixel_util_FlxPath,return )

int FlxArrayUtil_obj::indexOf_flixel_util_FlxPool_T( Dynamic array,Dynamic whatToFind,hx::Null< int >  __o_fromIndex){
int fromIndex = __o_fromIndex.Default(0);
	HX_STACK_FRAME("flixel.util.FlxArrayUtil","indexOf_flixel_util_FlxPool_T",0x89385ee8,"flixel.util.FlxArrayUtil.indexOf_flixel_util_FlxPool_T","flixel/util/FlxArrayUtil.hx",18,0xa0dc755b)
	HX_STACK_ARG(array,"array")
	HX_STACK_ARG(whatToFind,"whatToFind")
	HX_STACK_ARG(fromIndex,"fromIndex")
{
		HX_STACK_LINE(22)
		int index = (int)-1;		HX_STACK_VAR(index,"index");
		HX_STACK_LINE(23)
		int len = array->__Field(HX_CSTRING("length"),true);		HX_STACK_VAR(len,"len");
		HX_STACK_LINE(24)
		{
			HX_STACK_LINE(24)
			int _g = fromIndex;		HX_STACK_VAR(_g,"_g");
			HX_STACK_LINE(24)
			while(((_g < len))){
				HX_STACK_LINE(24)
				int i = (_g)++;		HX_STACK_VAR(i,"i");
				HX_STACK_LINE(26)
				if (((array->__GetItem(i) == whatToFind))){
					HX_STACK_LINE(28)
					index = i;
					HX_STACK_LINE(29)
					break;
				}
			}
		}
		HX_STACK_LINE(32)
		return index;
	}
}


STATIC_HX_DEFINE_DYNAMIC_FUNC3(FlxArrayUtil_obj,indexOf_flixel_util_FlxPool_T,return )

int FlxArrayUtil_obj::indexOf_flixel_system_ui_FlxSystemButton( Array< ::Dynamic > array,::flixel::system::ui::FlxSystemButton whatToFind,hx::Null< int >  __o_fromIndex){
int fromIndex = __o_fromIndex.Default(0);
	HX_STACK_FRAME("flixel.util.FlxArrayUtil","indexOf_flixel_system_ui_FlxSystemButton",0xe81c3096,"flixel.util.FlxArrayUtil.indexOf_flixel_system_ui_FlxSystemButton","flixel/util/FlxArrayUtil.hx",18,0xa0dc755b)
	HX_STACK_ARG(array,"array")
	HX_STACK_ARG(whatToFind,"whatToFind")
	HX_STACK_ARG(fromIndex,"fromIndex")
{
		HX_STACK_LINE(22)
		int index = (int)-1;		HX_STACK_VAR(index,"index");
		HX_STACK_LINE(23)
		int len = array->length;		HX_STACK_VAR(len,"len");
		HX_STACK_LINE(24)
		{
			HX_STACK_LINE(24)
			int _g = fromIndex;		HX_STACK_VAR(_g,"_g");
			HX_STACK_LINE(24)
			while(((_g < len))){
				HX_STACK_LINE(24)
				int i = (_g)++;		HX_STACK_VAR(i,"i");
				HX_STACK_LINE(26)
				if (((array->__get(i).StaticCast< ::flixel::system::ui::FlxSystemButton >() == whatToFind))){
					HX_STACK_LINE(28)
					index = i;
					HX_STACK_LINE(29)
					break;
				}
			}
		}
		HX_STACK_LINE(32)
		return index;
	}
}


STATIC_HX_DEFINE_DYNAMIC_FUNC3(FlxArrayUtil_obj,indexOf_flixel_system_ui_FlxSystemButton,return )

int FlxArrayUtil_obj::indexOf_flixel_system_debug_WatchEntry( Array< ::Dynamic > array,::flixel::system::debug::WatchEntry whatToFind,hx::Null< int >  __o_fromIndex){
int fromIndex = __o_fromIndex.Default(0);
	HX_STACK_FRAME("flixel.util.FlxArrayUtil","indexOf_flixel_system_debug_WatchEntry",0xd01377fd,"flixel.util.FlxArrayUtil.indexOf_flixel_system_debug_WatchEntry","flixel/util/FlxArrayUtil.hx",18,0xa0dc755b)
	HX_STACK_ARG(array,"array")
	HX_STACK_ARG(whatToFind,"whatToFind")
	HX_STACK_ARG(fromIndex,"fromIndex")
{
		HX_STACK_LINE(22)
		int index = (int)-1;		HX_STACK_VAR(index,"index");
		HX_STACK_LINE(23)
		int len = array->length;		HX_STACK_VAR(len,"len");
		HX_STACK_LINE(24)
		{
			HX_STACK_LINE(24)
			int _g = fromIndex;		HX_STACK_VAR(_g,"_g");
			HX_STACK_LINE(24)
			while(((_g < len))){
				HX_STACK_LINE(24)
				int i = (_g)++;		HX_STACK_VAR(i,"i");
				HX_STACK_LINE(26)
				if (((array->__get(i).StaticCast< ::flixel::system::debug::WatchEntry >() == whatToFind))){
					HX_STACK_LINE(28)
					index = i;
					HX_STACK_LINE(29)
					break;
				}
			}
		}
		HX_STACK_LINE(32)
		return index;
	}
}


STATIC_HX_DEFINE_DYNAMIC_FUNC3(FlxArrayUtil_obj,indexOf_flixel_system_debug_WatchEntry,return )

Array< ::Dynamic > FlxArrayUtil_obj::fastSplice_flixel_system_debug_WatchEntry( Array< ::Dynamic > array,::flixel::system::debug::WatchEntry element){
	HX_STACK_FRAME("flixel.util.FlxArrayUtil","fastSplice_flixel_system_debug_WatchEntry",0x10964af8,"flixel.util.FlxArrayUtil.fastSplice_flixel_system_debug_WatchEntry","flixel/util/FlxArrayUtil.hx",98,0xa0dc755b)
	HX_STACK_ARG(array,"array")
	HX_STACK_ARG(element,"element")
	HX_STACK_LINE(99)
	int index = ::flixel::util::FlxArrayUtil_obj::indexOf_fastSplice_T(array,element,null());		HX_STACK_VAR(index,"index");
	HX_STACK_LINE(100)
	if (((index >= (int)0))){
		HX_STACK_LINE(102)
		array[index] = array->__get((array->length - (int)1)).StaticCast< ::flixel::system::debug::WatchEntry >();
		HX_STACK_LINE(103)
		array->pop().StaticCast< ::flixel::system::debug::WatchEntry >();
	}
	HX_STACK_LINE(105)
	return array;
}


STATIC_HX_DEFINE_DYNAMIC_FUNC2(FlxArrayUtil_obj,fastSplice_flixel_system_debug_WatchEntry,return )

int FlxArrayUtil_obj::indexOf_String( Array< ::String > array,::String whatToFind,hx::Null< int >  __o_fromIndex){
int fromIndex = __o_fromIndex.Default(0);
	HX_STACK_FRAME("flixel.util.FlxArrayUtil","indexOf_String",0x154c6012,"flixel.util.FlxArrayUtil.indexOf_String","flixel/util/FlxArrayUtil.hx",18,0xa0dc755b)
	HX_STACK_ARG(array,"array")
	HX_STACK_ARG(whatToFind,"whatToFind")
	HX_STACK_ARG(fromIndex,"fromIndex")
{
		HX_STACK_LINE(22)
		int index = (int)-1;		HX_STACK_VAR(index,"index");
		HX_STACK_LINE(23)
		int len = array->length;		HX_STACK_VAR(len,"len");
		HX_STACK_LINE(24)
		{
			HX_STACK_LINE(24)
			int _g = fromIndex;		HX_STACK_VAR(_g,"_g");
			HX_STACK_LINE(24)
			while(((_g < len))){
				HX_STACK_LINE(24)
				int i = (_g)++;		HX_STACK_VAR(i,"i");
				HX_STACK_LINE(26)
				if (((array->__get(i) == whatToFind))){
					HX_STACK_LINE(28)
					index = i;
					HX_STACK_LINE(29)
					break;
				}
			}
		}
		HX_STACK_LINE(32)
		return index;
	}
}


STATIC_HX_DEFINE_DYNAMIC_FUNC3(FlxArrayUtil_obj,indexOf_String,return )

Void FlxArrayUtil_obj::setLength_flixel_group_FlxTypedGroup_T( Dynamic array,int newLength){
{
		HX_STACK_FRAME("flixel.util.FlxArrayUtil","setLength_flixel_group_FlxTypedGroup_T",0x1139627b,"flixel.util.FlxArrayUtil.setLength_flixel_group_FlxTypedGroup_T","flixel/util/FlxArrayUtil.hx",43,0xa0dc755b)
		HX_STACK_ARG(array,"array")
		HX_STACK_ARG(newLength,"newLength")
		HX_STACK_LINE(44)
		if (((newLength < (int)0))){
			HX_STACK_LINE(44)
			return null();
		}
		HX_STACK_LINE(45)
		int oldLength = array->__Field(HX_CSTRING("length"),true);		HX_STACK_VAR(oldLength,"oldLength");
		HX_STACK_LINE(46)
		int diff = (newLength - oldLength);		HX_STACK_VAR(diff,"diff");
		HX_STACK_LINE(47)
		if (((diff < (int)0))){
			HX_STACK_LINE(52)
			diff = -(diff);
			HX_STACK_LINE(53)
			{
				HX_STACK_LINE(53)
				int _g = (int)0;		HX_STACK_VAR(_g,"_g");
				HX_STACK_LINE(53)
				while(((_g < diff))){
					HX_STACK_LINE(53)
					int i = (_g)++;		HX_STACK_VAR(i,"i");
					HX_STACK_LINE(55)
					array->__Field(HX_CSTRING("pop"),true)();
				}
			}
		}
	}
return null();
}


STATIC_HX_DEFINE_DYNAMIC_FUNC2(FlxArrayUtil_obj,setLength_flixel_group_FlxTypedGroup_T,(void))

int FlxArrayUtil_obj::indexOf_flixel_group_FlxTypedGroup_T( Dynamic array,Dynamic whatToFind,hx::Null< int >  __o_fromIndex){
int fromIndex = __o_fromIndex.Default(0);
	HX_STACK_FRAME("flixel.util.FlxArrayUtil","indexOf_flixel_group_FlxTypedGroup_T",0xeb50907a,"flixel.util.FlxArrayUtil.indexOf_flixel_group_FlxTypedGroup_T","flixel/util/FlxArrayUtil.hx",18,0xa0dc755b)
	HX_STACK_ARG(array,"array")
	HX_STACK_ARG(whatToFind,"whatToFind")
	HX_STACK_ARG(fromIndex,"fromIndex")
{
		HX_STACK_LINE(22)
		int index = (int)-1;		HX_STACK_VAR(index,"index");
		HX_STACK_LINE(23)
		int len = array->__Field(HX_CSTRING("length"),true);		HX_STACK_VAR(len,"len");
		HX_STACK_LINE(24)
		{
			HX_STACK_LINE(24)
			int _g = fromIndex;		HX_STACK_VAR(_g,"_g");
			HX_STACK_LINE(24)
			while(((_g < len))){
				HX_STACK_LINE(24)
				int i = (_g)++;		HX_STACK_VAR(i,"i");
				HX_STACK_LINE(26)
				if (((array->__GetItem(i) == whatToFind))){
					HX_STACK_LINE(28)
					index = i;
					HX_STACK_LINE(29)
					break;
				}
			}
		}
		HX_STACK_LINE(32)
		return index;
	}
}


STATIC_HX_DEFINE_DYNAMIC_FUNC3(FlxArrayUtil_obj,indexOf_flixel_group_FlxTypedGroup_T,return )

int FlxArrayUtil_obj::indexOf_flixel_system_layer_frames_FlxFrame( Array< ::Dynamic > array,::flixel::system::layer::frames::FlxFrame whatToFind,hx::Null< int >  __o_fromIndex){
int fromIndex = __o_fromIndex.Default(0);
	HX_STACK_FRAME("flixel.util.FlxArrayUtil","indexOf_flixel_system_layer_frames_FlxFrame",0x3b4f3e78,"flixel.util.FlxArrayUtil.indexOf_flixel_system_layer_frames_FlxFrame","flixel/util/FlxArrayUtil.hx",18,0xa0dc755b)
	HX_STACK_ARG(array,"array")
	HX_STACK_ARG(whatToFind,"whatToFind")
	HX_STACK_ARG(fromIndex,"fromIndex")
{
		HX_STACK_LINE(22)
		int index = (int)-1;		HX_STACK_VAR(index,"index");
		HX_STACK_LINE(23)
		int len = array->length;		HX_STACK_VAR(len,"len");
		HX_STACK_LINE(24)
		{
			HX_STACK_LINE(24)
			int _g = fromIndex;		HX_STACK_VAR(_g,"_g");
			HX_STACK_LINE(24)
			while(((_g < len))){
				HX_STACK_LINE(24)
				int i = (_g)++;		HX_STACK_VAR(i,"i");
				HX_STACK_LINE(26)
				if (((array->__get(i).StaticCast< ::flixel::system::layer::frames::FlxFrame >() == whatToFind))){
					HX_STACK_LINE(28)
					index = i;
					HX_STACK_LINE(29)
					break;
				}
			}
		}
		HX_STACK_LINE(32)
		return index;
	}
}


STATIC_HX_DEFINE_DYNAMIC_FUNC3(FlxArrayUtil_obj,indexOf_flixel_system_layer_frames_FlxFrame,return )

int FlxArrayUtil_obj::indexOf_Float( Array< Float > array,Float whatToFind,hx::Null< int >  __o_fromIndex){
int fromIndex = __o_fromIndex.Default(0);
	HX_STACK_FRAME("flixel.util.FlxArrayUtil","indexOf_Float",0x2f60f17b,"flixel.util.FlxArrayUtil.indexOf_Float","flixel/util/FlxArrayUtil.hx",18,0xa0dc755b)
	HX_STACK_ARG(array,"array")
	HX_STACK_ARG(whatToFind,"whatToFind")
	HX_STACK_ARG(fromIndex,"fromIndex")
{
		HX_STACK_LINE(22)
		int index = (int)-1;		HX_STACK_VAR(index,"index");
		HX_STACK_LINE(23)
		int len = array->length;		HX_STACK_VAR(len,"len");
		HX_STACK_LINE(24)
		{
			HX_STACK_LINE(24)
			int _g = fromIndex;		HX_STACK_VAR(_g,"_g");
			HX_STACK_LINE(24)
			while(((_g < len))){
				HX_STACK_LINE(24)
				int i = (_g)++;		HX_STACK_VAR(i,"i");
				HX_STACK_LINE(26)
				if (((array->__get(i) == whatToFind))){
					HX_STACK_LINE(28)
					index = i;
					HX_STACK_LINE(29)
					break;
				}
			}
		}
		HX_STACK_LINE(32)
		return index;
	}
}


STATIC_HX_DEFINE_DYNAMIC_FUNC3(FlxArrayUtil_obj,indexOf_Float,return )

int FlxArrayUtil_obj::indexOf_fastSplice_T( Dynamic array,Dynamic whatToFind,hx::Null< int >  __o_fromIndex){
int fromIndex = __o_fromIndex.Default(0);
	HX_STACK_FRAME("flixel.util.FlxArrayUtil","indexOf_fastSplice_T",0x83fdfc2e,"flixel.util.FlxArrayUtil.indexOf_fastSplice_T","flixel/util/FlxArrayUtil.hx",18,0xa0dc755b)
	HX_STACK_ARG(array,"array")
	HX_STACK_ARG(whatToFind,"whatToFind")
	HX_STACK_ARG(fromIndex,"fromIndex")
{
		HX_STACK_LINE(22)
		int index = (int)-1;		HX_STACK_VAR(index,"index");
		HX_STACK_LINE(23)
		int len = array->__Field(HX_CSTRING("length"),true);		HX_STACK_VAR(len,"len");
		HX_STACK_LINE(24)
		{
			HX_STACK_LINE(24)
			int _g = fromIndex;		HX_STACK_VAR(_g,"_g");
			HX_STACK_LINE(24)
			while(((_g < len))){
				HX_STACK_LINE(24)
				int i = (_g)++;		HX_STACK_VAR(i,"i");
				HX_STACK_LINE(26)
				if (((array->__GetItem(i) == whatToFind))){
					HX_STACK_LINE(28)
					index = i;
					HX_STACK_LINE(29)
					break;
				}
			}
		}
		HX_STACK_LINE(32)
		return index;
	}
}


STATIC_HX_DEFINE_DYNAMIC_FUNC3(FlxArrayUtil_obj,indexOf_fastSplice_T,return )

int FlxArrayUtil_obj::indexOf_Int( Array< int > array,int whatToFind,hx::Null< int >  __o_fromIndex){
int fromIndex = __o_fromIndex.Default(0);
	HX_STACK_FRAME("flixel.util.FlxArrayUtil","indexOf_Int",0x6eed330e,"flixel.util.FlxArrayUtil.indexOf_Int","flixel/util/FlxArrayUtil.hx",18,0xa0dc755b)
	HX_STACK_ARG(array,"array")
	HX_STACK_ARG(whatToFind,"whatToFind")
	HX_STACK_ARG(fromIndex,"fromIndex")
{
		HX_STACK_LINE(22)
		int index = (int)-1;		HX_STACK_VAR(index,"index");
		HX_STACK_LINE(23)
		int len = array->length;		HX_STACK_VAR(len,"len");
		HX_STACK_LINE(24)
		{
			HX_STACK_LINE(24)
			int _g = fromIndex;		HX_STACK_VAR(_g,"_g");
			HX_STACK_LINE(24)
			while(((_g < len))){
				HX_STACK_LINE(24)
				int i = (_g)++;		HX_STACK_VAR(i,"i");
				HX_STACK_LINE(26)
				if (((array->__get(i) == whatToFind))){
					HX_STACK_LINE(28)
					index = i;
					HX_STACK_LINE(29)
					break;
				}
			}
		}
		HX_STACK_LINE(32)
		return index;
	}
}


STATIC_HX_DEFINE_DYNAMIC_FUNC3(FlxArrayUtil_obj,indexOf_Int,return )


FlxArrayUtil_obj::FlxArrayUtil_obj()
{
}

Dynamic FlxArrayUtil_obj::__Field(const ::String &inName,bool inCallProp)
{
	switch(inName.length) {
	case 11:
		if (HX_FIELD_EQ(inName,"indexOf_Int") ) { return indexOf_Int_dyn(); }
		break;
	case 13:
		if (HX_FIELD_EQ(inName,"setLength_Int") ) { return setLength_Int_dyn(); }
		if (HX_FIELD_EQ(inName,"indexOf_Float") ) { return indexOf_Float_dyn(); }
		break;
	case 14:
		if (HX_FIELD_EQ(inName,"indexOf_String") ) { return indexOf_String_dyn(); }
		break;
	case 15:
		if (HX_FIELD_EQ(inName,"setLength_Float") ) { return setLength_Float_dyn(); }
		break;
	case 16:
		if (HX_FIELD_EQ(inName,"setLength_String") ) { return setLength_String_dyn(); }
		break;
	case 20:
		if (HX_FIELD_EQ(inName,"indexOf_fastSplice_T") ) { return indexOf_fastSplice_T_dyn(); }
		break;
	case 24:
		if (HX_FIELD_EQ(inName,"indexOf_flixel_FlxCamera") ) { return indexOf_flixel_FlxCamera_dyn(); }
		break;
	case 27:
		if (HX_FIELD_EQ(inName,"indexOf_flixel_util_FlxPath") ) { return indexOf_flixel_util_FlxPath_dyn(); }
		break;
	case 28:
		if (HX_FIELD_EQ(inName,"indexOf_flixel_util_FlxTimer") ) { return indexOf_flixel_util_FlxTimer_dyn(); }
		if (HX_FIELD_EQ(inName,"indexOf_flixel_util_FlxPoint") ) { return indexOf_flixel_util_FlxPoint_dyn(); }
		break;
	case 29:
		if (HX_FIELD_EQ(inName,"indexOf_flixel_util_FlxPool_T") ) { return indexOf_flixel_util_FlxPool_T_dyn(); }
		break;
	case 30:
		if (HX_FIELD_EQ(inName,"indexOf_flixel_tweens_FlxTween") ) { return indexOf_flixel_tweens_FlxTween_dyn(); }
		if (HX_FIELD_EQ(inName,"fastSplice_flixel_util_FlxPath") ) { return fastSplice_flixel_util_FlxPath_dyn(); }
		break;
	case 31:
		if (HX_FIELD_EQ(inName,"fastSplice_flixel_util_FlxTimer") ) { return fastSplice_flixel_util_FlxTimer_dyn(); }
		break;
	case 33:
		if (HX_FIELD_EQ(inName,"fastSplice_flixel_tweens_FlxTween") ) { return fastSplice_flixel_tweens_FlxTween_dyn(); }
		break;
	case 36:
		if (HX_FIELD_EQ(inName,"fastSplice_flixel_text_FlxTextFormat") ) { return fastSplice_flixel_text_FlxTextFormat_dyn(); }
		if (HX_FIELD_EQ(inName,"indexOf_flixel_group_FlxTypedGroup_T") ) { return indexOf_flixel_group_FlxTypedGroup_T_dyn(); }
		break;
	case 38:
		if (HX_FIELD_EQ(inName,"getRandom_flixel_group_FlxTypedGroup_T") ) { return getRandom_flixel_group_FlxTypedGroup_T_dyn(); }
		if (HX_FIELD_EQ(inName,"setLength_flixel_input_keyboard_FlxKey") ) { return setLength_flixel_input_keyboard_FlxKey_dyn(); }
		if (HX_FIELD_EQ(inName,"indexOf_flixel_system_debug_WatchEntry") ) { return indexOf_flixel_system_debug_WatchEntry_dyn(); }
		if (HX_FIELD_EQ(inName,"setLength_flixel_group_FlxTypedGroup_T") ) { return setLength_flixel_group_FlxTypedGroup_T_dyn(); }
		break;
	case 40:
		if (HX_FIELD_EQ(inName,"indexOf_flixel_system_ui_FlxSystemButton") ) { return indexOf_flixel_system_ui_FlxSystemButton_dyn(); }
		break;
	case 41:
		if (HX_FIELD_EQ(inName,"fastSplice_flixel_system_debug_WatchEntry") ) { return fastSplice_flixel_system_debug_WatchEntry_dyn(); }
		break;
	case 42:
		if (HX_FIELD_EQ(inName,"setLength_flixel_system_replay_FrameRecord") ) { return setLength_flixel_system_replay_FrameRecord_dyn(); }
		break;
	case 43:
		if (HX_FIELD_EQ(inName,"indexOf_flixel_system_layer_frames_FlxFrame") ) { return indexOf_flixel_system_layer_frames_FlxFrame_dyn(); }
	}
	return super::__Field(inName,inCallProp);
}

Dynamic FlxArrayUtil_obj::__SetField(const ::String &inName,const Dynamic &inValue,bool inCallProp)
{
	return super::__SetField(inName,inValue,inCallProp);
}

void FlxArrayUtil_obj::__GetFields(Array< ::String> &outFields)
{
	super::__GetFields(outFields);
};

static ::String sStaticFields[] = {
	HX_CSTRING("fastSplice_flixel_text_FlxTextFormat"),
	HX_CSTRING("setLength_flixel_system_replay_FrameRecord"),
	HX_CSTRING("getRandom_flixel_group_FlxTypedGroup_T"),
	HX_CSTRING("setLength_flixel_input_keyboard_FlxKey"),
	HX_CSTRING("indexOf_flixel_FlxCamera"),
	HX_CSTRING("setLength_Int"),
	HX_CSTRING("fastSplice_flixel_tweens_FlxTween"),
	HX_CSTRING("indexOf_flixel_tweens_FlxTween"),
	HX_CSTRING("setLength_Float"),
	HX_CSTRING("setLength_String"),
	HX_CSTRING("fastSplice_flixel_util_FlxTimer"),
	HX_CSTRING("indexOf_flixel_util_FlxTimer"),
	HX_CSTRING("indexOf_flixel_util_FlxPoint"),
	HX_CSTRING("fastSplice_flixel_util_FlxPath"),
	HX_CSTRING("indexOf_flixel_util_FlxPath"),
	HX_CSTRING("indexOf_flixel_util_FlxPool_T"),
	HX_CSTRING("indexOf_flixel_system_ui_FlxSystemButton"),
	HX_CSTRING("indexOf_flixel_system_debug_WatchEntry"),
	HX_CSTRING("fastSplice_flixel_system_debug_WatchEntry"),
	HX_CSTRING("indexOf_String"),
	HX_CSTRING("setLength_flixel_group_FlxTypedGroup_T"),
	HX_CSTRING("indexOf_flixel_group_FlxTypedGroup_T"),
	HX_CSTRING("indexOf_flixel_system_layer_frames_FlxFrame"),
	HX_CSTRING("indexOf_Float"),
	HX_CSTRING("indexOf_fastSplice_T"),
	HX_CSTRING("indexOf_Int"),
	String(null()) };

#if HXCPP_SCRIPTABLE
static hx::StorageInfo *sMemberStorageInfo = 0;
#endif

static ::String sMemberFields[] = {
	String(null()) };

static void sMarkStatics(HX_MARK_PARAMS) {
	HX_MARK_MEMBER_NAME(FlxArrayUtil_obj::__mClass,"__mClass");
};

#ifdef HXCPP_VISIT_ALLOCS
static void sVisitStatics(HX_VISIT_PARAMS) {
	HX_VISIT_MEMBER_NAME(FlxArrayUtil_obj::__mClass,"__mClass");
};

#endif

Class FlxArrayUtil_obj::__mClass;

void FlxArrayUtil_obj::__register()
{
	hx::Static(__mClass) = hx::RegisterClass(HX_CSTRING("flixel.util.FlxArrayUtil"), hx::TCanCast< FlxArrayUtil_obj> ,sStaticFields,sMemberFields,
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

void FlxArrayUtil_obj::__boot()
{
}

} // end namespace flixel
} // end namespace util
