#include <hxcpp.h>

#ifndef INCLUDED_Type
#include <Type.h>
#endif
#ifndef INCLUDED_flash_Lib
#include <flash/Lib.h>
#endif
#ifndef INCLUDED_flash_display_BlendMode
#include <flash/display/BlendMode.h>
#endif
#ifndef INCLUDED_flash_display_DisplayObject
#include <flash/display/DisplayObject.h>
#endif
#ifndef INCLUDED_flash_display_DisplayObjectContainer
#include <flash/display/DisplayObjectContainer.h>
#endif
#ifndef INCLUDED_flash_display_Graphics
#include <flash/display/Graphics.h>
#endif
#ifndef INCLUDED_flash_display_IBitmapDrawable
#include <flash/display/IBitmapDrawable.h>
#endif
#ifndef INCLUDED_flash_display_InteractiveObject
#include <flash/display/InteractiveObject.h>
#endif
#ifndef INCLUDED_flash_display_LoaderInfo
#include <flash/display/LoaderInfo.h>
#endif
#ifndef INCLUDED_flash_display_PixelSnapping
#include <flash/display/PixelSnapping.h>
#endif
#ifndef INCLUDED_flash_display_Stage
#include <flash/display/Stage.h>
#endif
#ifndef INCLUDED_flash_events_Event
#include <flash/events/Event.h>
#endif
#ifndef INCLUDED_flash_events_EventDispatcher
#include <flash/events/EventDispatcher.h>
#endif
#ifndef INCLUDED_flash_events_EventPhase
#include <flash/events/EventPhase.h>
#endif
#ifndef INCLUDED_flash_events_IEventDispatcher
#include <flash/events/IEventDispatcher.h>
#endif
#ifndef INCLUDED_flash_geom_ColorTransform
#include <flash/geom/ColorTransform.h>
#endif
#ifndef INCLUDED_flash_geom_Matrix
#include <flash/geom/Matrix.h>
#endif
#ifndef INCLUDED_flash_geom_Point
#include <flash/geom/Point.h>
#endif
#ifndef INCLUDED_flash_geom_Rectangle
#include <flash/geom/Rectangle.h>
#endif
#ifndef INCLUDED_flash_geom_Transform
#include <flash/geom/Transform.h>
#endif
#ifndef INCLUDED_flash_net_URLLoader
#include <flash/net/URLLoader.h>
#endif
namespace flash{
namespace display{

Void DisplayObject_obj::__construct(Dynamic handle,::String type)
{
HX_STACK_FRAME("flash.display.DisplayObject","new",0x50b3ae89,"flash.display.DisplayObject.new","flash/display/DisplayObject.hx",55,0x869a4209)

HX_STACK_ARG(handle,"handle")

HX_STACK_ARG(type,"type")
{
	HX_STACK_LINE(57)
	super::__construct(hx::ObjectPtr<OBJ_>(this));
	HX_STACK_LINE(59)
	this->__parent = null();
	HX_STACK_LINE(60)
	this->__handle = handle;
	HX_STACK_LINE(61)
	this->__id = ::flash::display::DisplayObject_obj::lime_display_object_get_id(this->__handle);
	HX_STACK_LINE(62)
	this->set_name(((type + HX_CSTRING(" ")) + this->__id));
}
;
	return null();
}

//DisplayObject_obj::~DisplayObject_obj() { }

Dynamic DisplayObject_obj::__CreateEmpty() { return  new DisplayObject_obj; }
hx::ObjectPtr< DisplayObject_obj > DisplayObject_obj::__new(Dynamic handle,::String type)
{  hx::ObjectPtr< DisplayObject_obj > result = new DisplayObject_obj();
	result->__construct(handle,type);
	return result;}

Dynamic DisplayObject_obj::__Create(hx::DynamicArray inArgs)
{  hx::ObjectPtr< DisplayObject_obj > result = new DisplayObject_obj();
	result->__construct(inArgs[0],inArgs[1]);
	return result;}

hx::Object *DisplayObject_obj::__ToInterface(const hx::type_info &inType) {
	if (inType==typeid( ::flash::display::IBitmapDrawable_obj)) return operator ::flash::display::IBitmapDrawable_obj *();
	return super::__ToInterface(inType);
}

bool DisplayObject_obj::dispatchEvent( ::flash::events::Event event){
	HX_STACK_FRAME("flash.display.DisplayObject","dispatchEvent",0x68255269,"flash.display.DisplayObject.dispatchEvent","flash/display/DisplayObject.hx",67,0x869a4209)
	HX_STACK_THIS(this)
	HX_STACK_ARG(event,"event")
	HX_STACK_LINE(69)
	bool result = this->__dispatchEvent(event);		HX_STACK_VAR(result,"result");
	HX_STACK_LINE(71)
	if ((event->__getIsCancelled())){
		HX_STACK_LINE(72)
		return true;
	}
	HX_STACK_LINE(74)
	if (((  ((event->get_bubbles())) ? bool((this->get_parent() != null())) : bool(false) ))){
		HX_STACK_LINE(76)
		this->get_parent()->dispatchEvent(event);
	}
	HX_STACK_LINE(80)
	return result;
}


::flash::geom::Rectangle DisplayObject_obj::getBounds( ::flash::display::DisplayObject targetCoordinateSpace){
	HX_STACK_FRAME("flash.display.DisplayObject","getBounds",0x89fe7294,"flash.display.DisplayObject.getBounds","flash/display/DisplayObject.hx",85,0x869a4209)
	HX_STACK_THIS(this)
	HX_STACK_ARG(targetCoordinateSpace,"targetCoordinateSpace")
	HX_STACK_LINE(87)
	::flash::geom::Rectangle result = ::flash::geom::Rectangle_obj::__new(null(),null(),null(),null());		HX_STACK_VAR(result,"result");
	HX_STACK_LINE(88)
	::flash::display::DisplayObject_obj::lime_display_object_get_bounds(this->__handle,targetCoordinateSpace->__handle,result,true);
	HX_STACK_LINE(89)
	return result;
}


HX_DEFINE_DYNAMIC_FUNC1(DisplayObject_obj,getBounds,return )

::flash::geom::Rectangle DisplayObject_obj::getRect( ::flash::display::DisplayObject targetCoordinateSpace){
	HX_STACK_FRAME("flash.display.DisplayObject","getRect",0x1a3ea383,"flash.display.DisplayObject.getRect","flash/display/DisplayObject.hx",94,0x869a4209)
	HX_STACK_THIS(this)
	HX_STACK_ARG(targetCoordinateSpace,"targetCoordinateSpace")
	HX_STACK_LINE(96)
	::flash::geom::Rectangle result = ::flash::geom::Rectangle_obj::__new(null(),null(),null(),null());		HX_STACK_VAR(result,"result");
	HX_STACK_LINE(97)
	::flash::display::DisplayObject_obj::lime_display_object_get_bounds(this->__handle,targetCoordinateSpace->__handle,result,false);
	HX_STACK_LINE(98)
	return result;
}


HX_DEFINE_DYNAMIC_FUNC1(DisplayObject_obj,getRect,return )

::flash::geom::Point DisplayObject_obj::globalToLocal( ::flash::geom::Point point){
	HX_STACK_FRAME("flash.display.DisplayObject","globalToLocal",0x0d6eda36,"flash.display.DisplayObject.globalToLocal","flash/display/DisplayObject.hx",103,0x869a4209)
	HX_STACK_THIS(this)
	HX_STACK_ARG(point,"point")
	HX_STACK_LINE(105)
	::flash::geom::Point result = point->clone();		HX_STACK_VAR(result,"result");
	HX_STACK_LINE(106)
	::flash::display::DisplayObject_obj::lime_display_object_global_to_local(this->__handle,result);
	HX_STACK_LINE(107)
	return result;
}


HX_DEFINE_DYNAMIC_FUNC1(DisplayObject_obj,globalToLocal,return )

bool DisplayObject_obj::hitTestObject( ::flash::display::DisplayObject object){
	HX_STACK_FRAME("flash.display.DisplayObject","hitTestObject",0x7924e04d,"flash.display.DisplayObject.hitTestObject","flash/display/DisplayObject.hx",112,0x869a4209)
	HX_STACK_THIS(this)
	HX_STACK_ARG(object,"object")
	HX_STACK_LINE(114)
	if (((  (((  (((object != null()))) ? bool((object->get_parent() != null())) : bool(false) ))) ? bool((this->get_parent() != null())) : bool(false) ))){
		HX_STACK_LINE(116)
		::flash::geom::Matrix currentMatrix = this->get_transform()->get_concatenatedMatrix();		HX_STACK_VAR(currentMatrix,"currentMatrix");
		HX_STACK_LINE(117)
		::flash::geom::Matrix targetMatrix = object->get_transform()->get_concatenatedMatrix();		HX_STACK_VAR(targetMatrix,"targetMatrix");
		HX_STACK_LINE(119)
		::flash::geom::Point xPoint = ::flash::geom::Point_obj::__new((int)1,(int)0);		HX_STACK_VAR(xPoint,"xPoint");
		HX_STACK_LINE(120)
		::flash::geom::Point yPoint = ::flash::geom::Point_obj::__new((int)0,(int)1);		HX_STACK_VAR(yPoint,"yPoint");
		HX_STACK_LINE(122)
		Float _g = this->get_width();		HX_STACK_VAR(_g,"_g");
		HX_STACK_LINE(122)
		Float currentWidth = (_g * currentMatrix->deltaTransformPoint(xPoint)->get_length());		HX_STACK_VAR(currentWidth,"currentWidth");
		HX_STACK_LINE(123)
		Float _g1 = this->get_height();		HX_STACK_VAR(_g1,"_g1");
		HX_STACK_LINE(123)
		Float currentHeight = (_g1 * currentMatrix->deltaTransformPoint(yPoint)->get_length());		HX_STACK_VAR(currentHeight,"currentHeight");
		HX_STACK_LINE(124)
		Float _g2 = object->get_width();		HX_STACK_VAR(_g2,"_g2");
		HX_STACK_LINE(124)
		Float targetWidth = (_g2 * targetMatrix->deltaTransformPoint(xPoint)->get_length());		HX_STACK_VAR(targetWidth,"targetWidth");
		HX_STACK_LINE(125)
		Float _g3 = object->get_height();		HX_STACK_VAR(_g3,"_g3");
		HX_STACK_LINE(125)
		Float targetHeight = (_g3 * targetMatrix->deltaTransformPoint(yPoint)->get_length());		HX_STACK_VAR(targetHeight,"targetHeight");
		HX_STACK_LINE(127)
		::flash::geom::Rectangle currentRect = ::flash::geom::Rectangle_obj::__new(currentMatrix->tx,currentMatrix->ty,currentWidth,currentHeight);		HX_STACK_VAR(currentRect,"currentRect");
		HX_STACK_LINE(128)
		::flash::geom::Rectangle targetRect = ::flash::geom::Rectangle_obj::__new(targetMatrix->tx,targetMatrix->ty,targetWidth,targetHeight);		HX_STACK_VAR(targetRect,"targetRect");
		HX_STACK_LINE(130)
		return currentRect->intersects(targetRect);
	}
	HX_STACK_LINE(134)
	return false;
}


HX_DEFINE_DYNAMIC_FUNC1(DisplayObject_obj,hitTestObject,return )

bool DisplayObject_obj::hitTestPoint( Float x,Float y,hx::Null< bool >  __o_shapeFlag){
bool shapeFlag = __o_shapeFlag.Default(false);
	HX_STACK_FRAME("flash.display.DisplayObject","hitTestPoint",0x6fc33e82,"flash.display.DisplayObject.hitTestPoint","flash/display/DisplayObject.hx",141,0x869a4209)
	HX_STACK_THIS(this)
	HX_STACK_ARG(x,"x")
	HX_STACK_ARG(y,"y")
	HX_STACK_ARG(shapeFlag,"shapeFlag")
{
		HX_STACK_LINE(141)
		return ::flash::display::DisplayObject_obj::lime_display_object_hit_test_point(this->__handle,x,y,shapeFlag,true);
	}
}


HX_DEFINE_DYNAMIC_FUNC3(DisplayObject_obj,hitTestPoint,return )

::flash::geom::Point DisplayObject_obj::localToGlobal( ::flash::geom::Point point){
	HX_STACK_FRAME("flash.display.DisplayObject","localToGlobal",0xe9abcd32,"flash.display.DisplayObject.localToGlobal","flash/display/DisplayObject.hx",146,0x869a4209)
	HX_STACK_THIS(this)
	HX_STACK_ARG(point,"point")
	HX_STACK_LINE(148)
	::flash::geom::Point result = point->clone();		HX_STACK_VAR(result,"result");
	HX_STACK_LINE(149)
	::flash::display::DisplayObject_obj::lime_display_object_local_to_global(this->__handle,result);
	HX_STACK_LINE(150)
	return result;
}


HX_DEFINE_DYNAMIC_FUNC1(DisplayObject_obj,localToGlobal,return )

::String DisplayObject_obj::toString( ){
	HX_STACK_FRAME("flash.display.DisplayObject","toString",0xce6bfde3,"flash.display.DisplayObject.toString","flash/display/DisplayObject.hx",157,0x869a4209)
	HX_STACK_THIS(this)
	HX_STACK_LINE(157)
	return this->get_name();
}


::flash::display::InteractiveObject DisplayObject_obj::__asInteractiveObject( ){
	HX_STACK_FRAME("flash.display.DisplayObject","__asInteractiveObject",0x59463e38,"flash.display.DisplayObject.__asInteractiveObject","flash/display/DisplayObject.hx",164,0x869a4209)
	HX_STACK_THIS(this)
	HX_STACK_LINE(164)
	return null();
}


HX_DEFINE_DYNAMIC_FUNC0(DisplayObject_obj,__asInteractiveObject,return )

Void DisplayObject_obj::__broadcast( ::flash::events::Event event){
{
		HX_STACK_FRAME("flash.display.DisplayObject","__broadcast",0x765d9b0a,"flash.display.DisplayObject.__broadcast","flash/display/DisplayObject.hx",171,0x869a4209)
		HX_STACK_THIS(this)
		HX_STACK_ARG(event,"event")
		HX_STACK_LINE(171)
		this->__dispatchEvent(event);
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC1(DisplayObject_obj,__broadcast,(void))

bool DisplayObject_obj::__contains( ::flash::display::DisplayObject child){
	HX_STACK_FRAME("flash.display.DisplayObject","__contains",0xc13ff636,"flash.display.DisplayObject.__contains","flash/display/DisplayObject.hx",178,0x869a4209)
	HX_STACK_THIS(this)
	HX_STACK_ARG(child,"child")
	HX_STACK_LINE(178)
	return false;
}


HX_DEFINE_DYNAMIC_FUNC1(DisplayObject_obj,__contains,return )

bool DisplayObject_obj::__dispatchEvent( ::flash::events::Event event){
	HX_STACK_FRAME("flash.display.DisplayObject","__dispatchEvent",0x499ff789,"flash.display.DisplayObject.__dispatchEvent","flash/display/DisplayObject.hx",183,0x869a4209)
	HX_STACK_THIS(this)
	HX_STACK_ARG(event,"event")
	HX_STACK_LINE(185)
	if (((event->get_target() == null()))){
		HX_STACK_LINE(187)
		event->set_target(hx::ObjectPtr<OBJ_>(this));
	}
	HX_STACK_LINE(191)
	event->set_currentTarget(hx::ObjectPtr<OBJ_>(this));
	HX_STACK_LINE(192)
	return this->super::dispatchEvent(event);
}


HX_DEFINE_DYNAMIC_FUNC1(DisplayObject_obj,__dispatchEvent,return )

Void DisplayObject_obj::__drawToSurface( Dynamic surface,::flash::geom::Matrix matrix,::flash::geom::ColorTransform colorTransform,::String blendMode,::flash::geom::Rectangle clipRect,bool smoothing){
{
		HX_STACK_FRAME("flash.display.DisplayObject","__drawToSurface",0x6f3fe1d7,"flash.display.DisplayObject.__drawToSurface","flash/display/DisplayObject.hx",199,0x869a4209)
		HX_STACK_THIS(this)
		HX_STACK_ARG(surface,"surface")
		HX_STACK_ARG(matrix,"matrix")
		HX_STACK_ARG(colorTransform,"colorTransform")
		HX_STACK_ARG(blendMode,"blendMode")
		HX_STACK_ARG(clipRect,"clipRect")
		HX_STACK_ARG(smoothing,"smoothing")
		HX_STACK_LINE(199)
		::flash::display::DisplayObject_obj::lime_display_object_draw_to_surface(this->__handle,surface,matrix,colorTransform,blendMode,clipRect);
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC6(DisplayObject_obj,__drawToSurface,(void))

::flash::display::DisplayObject DisplayObject_obj::__findByID( int id){
	HX_STACK_FRAME("flash.display.DisplayObject","__findByID",0x287ba262,"flash.display.DisplayObject.__findByID","flash/display/DisplayObject.hx",204,0x869a4209)
	HX_STACK_THIS(this)
	HX_STACK_ARG(id,"id")
	HX_STACK_LINE(206)
	if (((this->__id == id))){
		HX_STACK_LINE(208)
		return hx::ObjectPtr<OBJ_>(this);
	}
	HX_STACK_LINE(212)
	return null();
}


HX_DEFINE_DYNAMIC_FUNC1(DisplayObject_obj,__findByID,return )

Void DisplayObject_obj::__fireEvent( ::flash::events::Event event){
{
		HX_STACK_FRAME("flash.display.DisplayObject","__fireEvent",0x08b1288d,"flash.display.DisplayObject.__fireEvent","flash/display/DisplayObject.hx",217,0x869a4209)
		HX_STACK_THIS(this)
		HX_STACK_ARG(event,"event")
		HX_STACK_LINE(219)
		Array< ::Dynamic > stack = Array_obj< ::Dynamic >::__new();		HX_STACK_VAR(stack,"stack");
		HX_STACK_LINE(221)
		if (((this->__parent != null()))){
			HX_STACK_LINE(223)
			this->__parent->__getInteractiveObjectStack(stack);
		}
		HX_STACK_LINE(227)
		if (((stack->length > (int)0))){
			HX_STACK_LINE(229)
			event->__setPhase(::flash::events::EventPhase_obj::CAPTURING_PHASE);
			HX_STACK_LINE(230)
			stack->reverse();
			HX_STACK_LINE(232)
			{
				HX_STACK_LINE(232)
				int _g = (int)0;		HX_STACK_VAR(_g,"_g");
				HX_STACK_LINE(232)
				while(((_g < stack->length))){
					HX_STACK_LINE(232)
					::flash::display::InteractiveObject object = stack->__get(_g).StaticCast< ::flash::display::InteractiveObject >();		HX_STACK_VAR(object,"object");
					HX_STACK_LINE(232)
					++(_g);
					HX_STACK_LINE(234)
					event->set_currentTarget(object);
					HX_STACK_LINE(235)
					object->__dispatchEvent(event);
					HX_STACK_LINE(237)
					if ((event->__getIsCancelled())){
						HX_STACK_LINE(239)
						return null();
					}
				}
			}
		}
		HX_STACK_LINE(247)
		event->__setPhase(::flash::events::EventPhase_obj::AT_TARGET);
		HX_STACK_LINE(248)
		event->set_currentTarget(hx::ObjectPtr<OBJ_>(this));
		HX_STACK_LINE(249)
		this->__dispatchEvent(event);
		HX_STACK_LINE(251)
		if ((event->__getIsCancelled())){
			HX_STACK_LINE(253)
			return null();
		}
		HX_STACK_LINE(257)
		if ((event->get_bubbles())){
			HX_STACK_LINE(259)
			event->__setPhase(::flash::events::EventPhase_obj::BUBBLING_PHASE);
			HX_STACK_LINE(260)
			stack->reverse();
			HX_STACK_LINE(262)
			{
				HX_STACK_LINE(262)
				int _g = (int)0;		HX_STACK_VAR(_g,"_g");
				HX_STACK_LINE(262)
				while(((_g < stack->length))){
					HX_STACK_LINE(262)
					::flash::display::InteractiveObject object = stack->__get(_g).StaticCast< ::flash::display::InteractiveObject >();		HX_STACK_VAR(object,"object");
					HX_STACK_LINE(262)
					++(_g);
					HX_STACK_LINE(264)
					event->set_currentTarget(object);
					HX_STACK_LINE(265)
					object->__dispatchEvent(event);
					HX_STACK_LINE(267)
					if ((event->__getIsCancelled())){
						HX_STACK_LINE(269)
						return null();
					}
				}
			}
		}
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC1(DisplayObject_obj,__fireEvent,(void))

::flash::geom::ColorTransform DisplayObject_obj::__getColorTransform( ){
	HX_STACK_FRAME("flash.display.DisplayObject","__getColorTransform",0x7a2c2fc8,"flash.display.DisplayObject.__getColorTransform","flash/display/DisplayObject.hx",280,0x869a4209)
	HX_STACK_THIS(this)
	HX_STACK_LINE(282)
	::flash::geom::ColorTransform colorTransform = ::flash::geom::ColorTransform_obj::__new(null(),null(),null(),null(),null(),null(),null(),null());		HX_STACK_VAR(colorTransform,"colorTransform");
	HX_STACK_LINE(283)
	::flash::display::DisplayObject_obj::lime_display_object_get_color_transform(this->__handle,colorTransform,false);
	HX_STACK_LINE(284)
	return colorTransform;
}


HX_DEFINE_DYNAMIC_FUNC0(DisplayObject_obj,__getColorTransform,return )

::flash::geom::ColorTransform DisplayObject_obj::__getConcatenatedColorTransform( ){
	HX_STACK_FRAME("flash.display.DisplayObject","__getConcatenatedColorTransform",0x4bca23b7,"flash.display.DisplayObject.__getConcatenatedColorTransform","flash/display/DisplayObject.hx",289,0x869a4209)
	HX_STACK_THIS(this)
	HX_STACK_LINE(291)
	::flash::geom::ColorTransform colorTransform = ::flash::geom::ColorTransform_obj::__new(null(),null(),null(),null(),null(),null(),null(),null());		HX_STACK_VAR(colorTransform,"colorTransform");
	HX_STACK_LINE(292)
	::flash::display::DisplayObject_obj::lime_display_object_get_color_transform(this->__handle,colorTransform,true);
	HX_STACK_LINE(293)
	return colorTransform;
}


HX_DEFINE_DYNAMIC_FUNC0(DisplayObject_obj,__getConcatenatedColorTransform,return )

::flash::geom::Matrix DisplayObject_obj::__getConcatenatedMatrix( ){
	HX_STACK_FRAME("flash.display.DisplayObject","__getConcatenatedMatrix",0x34d3a46f,"flash.display.DisplayObject.__getConcatenatedMatrix","flash/display/DisplayObject.hx",298,0x869a4209)
	HX_STACK_THIS(this)
	HX_STACK_LINE(300)
	::flash::geom::Matrix matrix = ::flash::geom::Matrix_obj::__new(null(),null(),null(),null(),null(),null());		HX_STACK_VAR(matrix,"matrix");
	HX_STACK_LINE(301)
	::flash::display::DisplayObject_obj::lime_display_object_get_matrix(this->__handle,matrix,true);
	HX_STACK_LINE(302)
	return matrix;
}


HX_DEFINE_DYNAMIC_FUNC0(DisplayObject_obj,__getConcatenatedMatrix,return )

Void DisplayObject_obj::__getInteractiveObjectStack( Array< ::Dynamic > stack){
{
		HX_STACK_FRAME("flash.display.DisplayObject","__getInteractiveObjectStack",0x5e3ef486,"flash.display.DisplayObject.__getInteractiveObjectStack","flash/display/DisplayObject.hx",307,0x869a4209)
		HX_STACK_THIS(this)
		HX_STACK_ARG(stack,"stack")
		HX_STACK_LINE(309)
		::flash::display::InteractiveObject interactive = this->__asInteractiveObject();		HX_STACK_VAR(interactive,"interactive");
		HX_STACK_LINE(311)
		if (((interactive != null()))){
			HX_STACK_LINE(313)
			stack->push(interactive);
		}
		HX_STACK_LINE(317)
		if (((this->__parent != null()))){
			HX_STACK_LINE(319)
			this->__parent->__getInteractiveObjectStack(stack);
		}
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC1(DisplayObject_obj,__getInteractiveObjectStack,(void))

::flash::geom::Matrix DisplayObject_obj::__getMatrix( ){
	HX_STACK_FRAME("flash.display.DisplayObject","__getMatrix",0xcf62b780,"flash.display.DisplayObject.__getMatrix","flash/display/DisplayObject.hx",326,0x869a4209)
	HX_STACK_THIS(this)
	HX_STACK_LINE(328)
	::flash::geom::Matrix matrix = ::flash::geom::Matrix_obj::__new(null(),null(),null(),null(),null(),null());		HX_STACK_VAR(matrix,"matrix");
	HX_STACK_LINE(329)
	::flash::display::DisplayObject_obj::lime_display_object_get_matrix(this->__handle,matrix,false);
	HX_STACK_LINE(330)
	return matrix;
}


HX_DEFINE_DYNAMIC_FUNC0(DisplayObject_obj,__getMatrix,return )

Void DisplayObject_obj::__getObjectsUnderPoint( ::flash::geom::Point point,Array< ::Dynamic > result){
{
		HX_STACK_FRAME("flash.display.DisplayObject","__getObjectsUnderPoint",0xbc5ef32d,"flash.display.DisplayObject.__getObjectsUnderPoint","flash/display/DisplayObject.hx",337,0x869a4209)
		HX_STACK_THIS(this)
		HX_STACK_ARG(point,"point")
		HX_STACK_ARG(result,"result")
		HX_STACK_LINE(337)
		if ((::flash::display::DisplayObject_obj::lime_display_object_hit_test_point(this->__handle,point->x,point->y,true,false))){
			HX_STACK_LINE(339)
			result->push(hx::ObjectPtr<OBJ_>(this));
		}
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC2(DisplayObject_obj,__getObjectsUnderPoint,(void))

::flash::geom::Rectangle DisplayObject_obj::__getPixelBounds( ){
	HX_STACK_FRAME("flash.display.DisplayObject","__getPixelBounds",0xafd803fc,"flash.display.DisplayObject.__getPixelBounds","flash/display/DisplayObject.hx",346,0x869a4209)
	HX_STACK_THIS(this)
	HX_STACK_LINE(348)
	::flash::geom::Rectangle bounds = ::flash::geom::Rectangle_obj::__new(null(),null(),null(),null());		HX_STACK_VAR(bounds,"bounds");
	HX_STACK_LINE(349)
	::flash::display::DisplayObject_obj::lime_display_object_get_pixel_bounds(this->__handle,bounds);
	HX_STACK_LINE(350)
	return bounds;
}


HX_DEFINE_DYNAMIC_FUNC0(DisplayObject_obj,__getPixelBounds,return )

Void DisplayObject_obj::__onAdded( ::flash::display::DisplayObject object,bool isOnStage){
{
		HX_STACK_FRAME("flash.display.DisplayObject","__onAdded",0xdb5a26ea,"flash.display.DisplayObject.__onAdded","flash/display/DisplayObject.hx",355,0x869a4209)
		HX_STACK_THIS(this)
		HX_STACK_ARG(object,"object")
		HX_STACK_ARG(isOnStage,"isOnStage")
		HX_STACK_LINE(357)
		if (((object == hx::ObjectPtr<OBJ_>(this)))){
			HX_STACK_LINE(359)
			::flash::events::Event event = ::flash::events::Event_obj::__new(::flash::events::Event_obj::ADDED,true,false);		HX_STACK_VAR(event,"event");
			HX_STACK_LINE(360)
			event->set_target(hx::ObjectPtr<OBJ_>(this));
			HX_STACK_LINE(361)
			this->dispatchEvent(event);
		}
		HX_STACK_LINE(365)
		if ((isOnStage)){
			HX_STACK_LINE(367)
			::flash::events::Event event = ::flash::events::Event_obj::__new(::flash::events::Event_obj::ADDED_TO_STAGE,false,false);		HX_STACK_VAR(event,"event");
			HX_STACK_LINE(368)
			event->set_target(object);
			HX_STACK_LINE(369)
			this->dispatchEvent(event);
		}
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC2(DisplayObject_obj,__onAdded,(void))

Void DisplayObject_obj::__onRemoved( ::flash::display::DisplayObject object,bool wasOnStage){
{
		HX_STACK_FRAME("flash.display.DisplayObject","__onRemoved",0x61eed04a,"flash.display.DisplayObject.__onRemoved","flash/display/DisplayObject.hx",376,0x869a4209)
		HX_STACK_THIS(this)
		HX_STACK_ARG(object,"object")
		HX_STACK_ARG(wasOnStage,"wasOnStage")
		HX_STACK_LINE(378)
		if (((object == hx::ObjectPtr<OBJ_>(this)))){
			HX_STACK_LINE(380)
			::flash::events::Event event = ::flash::events::Event_obj::__new(::flash::events::Event_obj::REMOVED,true,false);		HX_STACK_VAR(event,"event");
			HX_STACK_LINE(381)
			event->set_target(hx::ObjectPtr<OBJ_>(this));
			HX_STACK_LINE(382)
			this->dispatchEvent(event);
		}
		HX_STACK_LINE(386)
		if ((wasOnStage)){
			HX_STACK_LINE(388)
			::flash::events::Event event = ::flash::events::Event_obj::__new(::flash::events::Event_obj::REMOVED_FROM_STAGE,false,false);		HX_STACK_VAR(event,"event");
			HX_STACK_LINE(389)
			event->set_target(object);
			HX_STACK_LINE(390)
			this->dispatchEvent(event);
		}
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC2(DisplayObject_obj,__onRemoved,(void))

Void DisplayObject_obj::__setColorTransform( ::flash::geom::ColorTransform colorTransform){
{
		HX_STACK_FRAME("flash.display.DisplayObject","__setColorTransform",0x9d9a07d4,"flash.display.DisplayObject.__setColorTransform","flash/display/DisplayObject.hx",399,0x869a4209)
		HX_STACK_THIS(this)
		HX_STACK_ARG(colorTransform,"colorTransform")
		HX_STACK_LINE(399)
		::flash::display::DisplayObject_obj::lime_display_object_set_color_transform(this->__handle,colorTransform);
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC1(DisplayObject_obj,__setColorTransform,(void))

Void DisplayObject_obj::__setMatrix( ::flash::geom::Matrix matrix){
{
		HX_STACK_FRAME("flash.display.DisplayObject","__setMatrix",0xb2b3a38c,"flash.display.DisplayObject.__setMatrix","flash/display/DisplayObject.hx",406,0x869a4209)
		HX_STACK_THIS(this)
		HX_STACK_ARG(matrix,"matrix")
		HX_STACK_LINE(406)
		::flash::display::DisplayObject_obj::lime_display_object_set_matrix(this->__handle,matrix);
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC1(DisplayObject_obj,__setMatrix,(void))

::flash::display::DisplayObjectContainer DisplayObject_obj::__setParent( ::flash::display::DisplayObjectContainer parent){
	HX_STACK_FRAME("flash.display.DisplayObject","__setParent",0xe4697275,"flash.display.DisplayObject.__setParent","flash/display/DisplayObject.hx",411,0x869a4209)
	HX_STACK_THIS(this)
	HX_STACK_ARG(parent,"parent")
	HX_STACK_LINE(413)
	if (((parent == this->__parent))){
		HX_STACK_LINE(415)
		return parent;
	}
	HX_STACK_LINE(419)
	if (((this->__parent != null()))){
		HX_STACK_LINE(421)
		this->__parent->__removeChildFromArray(hx::ObjectPtr<OBJ_>(this));
	}
	HX_STACK_LINE(425)
	if (((bool((this->__parent == null())) && bool((parent != null()))))){
		HX_STACK_LINE(427)
		this->__parent = parent;
		HX_STACK_LINE(428)
		this->__onAdded(hx::ObjectPtr<OBJ_>(this),(this->get_stage() != null()));
	}
	else{
		HX_STACK_LINE(430)
		if (((bool((this->__parent != null())) && bool((parent == null()))))){
			HX_STACK_LINE(432)
			bool wasOnStage = (this->get_stage() != null());		HX_STACK_VAR(wasOnStage,"wasOnStage");
			HX_STACK_LINE(433)
			this->__parent = parent;
			HX_STACK_LINE(434)
			this->__onRemoved(hx::ObjectPtr<OBJ_>(this),wasOnStage);
		}
		else{
			HX_STACK_LINE(438)
			this->__parent = parent;
		}
	}
	HX_STACK_LINE(442)
	return parent;
}


HX_DEFINE_DYNAMIC_FUNC1(DisplayObject_obj,__setParent,return )

Float DisplayObject_obj::get_alpha( ){
	HX_STACK_FRAME("flash.display.DisplayObject","get_alpha",0x0cca669e,"flash.display.DisplayObject.get_alpha","flash/display/DisplayObject.hx",454,0x869a4209)
	HX_STACK_THIS(this)
	HX_STACK_LINE(454)
	return ::flash::display::DisplayObject_obj::lime_display_object_get_alpha(this->__handle);
}


HX_DEFINE_DYNAMIC_FUNC0(DisplayObject_obj,get_alpha,return )

Float DisplayObject_obj::set_alpha( Float value){
	HX_STACK_FRAME("flash.display.DisplayObject","set_alpha",0xf01b52aa,"flash.display.DisplayObject.set_alpha","flash/display/DisplayObject.hx",455,0x869a4209)
	HX_STACK_THIS(this)
	HX_STACK_ARG(value,"value")
	HX_STACK_LINE(457)
	::flash::display::DisplayObject_obj::lime_display_object_set_alpha(this->__handle,value);
	HX_STACK_LINE(458)
	return value;
}


HX_DEFINE_DYNAMIC_FUNC1(DisplayObject_obj,set_alpha,return )

Dynamic DisplayObject_obj::get_opaqueBackground( ){
	HX_STACK_FRAME("flash.display.DisplayObject","get_opaqueBackground",0x28f9c0ef,"flash.display.DisplayObject.get_opaqueBackground","flash/display/DisplayObject.hx",463,0x869a4209)
	HX_STACK_THIS(this)
	HX_STACK_LINE(465)
	int i = ::flash::display::DisplayObject_obj::lime_display_object_get_bg(this->__handle);		HX_STACK_VAR(i,"i");
	HX_STACK_LINE(467)
	if (((((int(i) & int((int)16777216))) == (int)0))){
		HX_STACK_LINE(469)
		return null();
	}
	HX_STACK_LINE(473)
	return (int(i) & int((int)16777215));
}


HX_DEFINE_DYNAMIC_FUNC0(DisplayObject_obj,get_opaqueBackground,return )

Dynamic DisplayObject_obj::set_opaqueBackground( Dynamic value){
	HX_STACK_FRAME("flash.display.DisplayObject","set_opaqueBackground",0xf5b17863,"flash.display.DisplayObject.set_opaqueBackground","flash/display/DisplayObject.hx",478,0x869a4209)
	HX_STACK_THIS(this)
	HX_STACK_ARG(value,"value")
	HX_STACK_LINE(480)
	if (((value == null()))){
		HX_STACK_LINE(482)
		::flash::display::DisplayObject_obj::lime_display_object_set_bg(this->__handle,(int)0);
	}
	else{
		HX_STACK_LINE(486)
		::flash::display::DisplayObject_obj::lime_display_object_set_bg(this->__handle,value);
	}
	HX_STACK_LINE(490)
	return value;
}


HX_DEFINE_DYNAMIC_FUNC1(DisplayObject_obj,set_opaqueBackground,return )

::flash::display::BlendMode DisplayObject_obj::get_blendMode( ){
	HX_STACK_FRAME("flash.display.DisplayObject","get_blendMode",0x6f5c4394,"flash.display.DisplayObject.get_blendMode","flash/display/DisplayObject.hx",495,0x869a4209)
	HX_STACK_THIS(this)
	HX_STACK_LINE(497)
	int i = ::flash::display::DisplayObject_obj::lime_display_object_get_blend_mode(this->__handle);		HX_STACK_VAR(i,"i");
	HX_STACK_LINE(498)
	return ::Type_obj::createEnumIndex(hx::ClassOf< ::flash::display::BlendMode >(),i,null());
}


HX_DEFINE_DYNAMIC_FUNC0(DisplayObject_obj,get_blendMode,return )

::flash::display::BlendMode DisplayObject_obj::set_blendMode( ::flash::display::BlendMode value){
	HX_STACK_FRAME("flash.display.DisplayObject","set_blendMode",0xb46225a0,"flash.display.DisplayObject.set_blendMode","flash/display/DisplayObject.hx",503,0x869a4209)
	HX_STACK_THIS(this)
	HX_STACK_ARG(value,"value")
	HX_STACK_LINE(505)
	::flash::display::DisplayObject_obj::lime_display_object_set_blend_mode(this->__handle,value->__Index());
	HX_STACK_LINE(506)
	return value;
}


HX_DEFINE_DYNAMIC_FUNC1(DisplayObject_obj,set_blendMode,return )

bool DisplayObject_obj::get_cacheAsBitmap( ){
	HX_STACK_FRAME("flash.display.DisplayObject","get_cacheAsBitmap",0x19f48223,"flash.display.DisplayObject.get_cacheAsBitmap","flash/display/DisplayObject.hx",511,0x869a4209)
	HX_STACK_THIS(this)
	HX_STACK_LINE(511)
	return ::flash::display::DisplayObject_obj::lime_display_object_get_cache_as_bitmap(this->__handle);
}


HX_DEFINE_DYNAMIC_FUNC0(DisplayObject_obj,get_cacheAsBitmap,return )

bool DisplayObject_obj::set_cacheAsBitmap( bool value){
	HX_STACK_FRAME("flash.display.DisplayObject","set_cacheAsBitmap",0x3d625a2f,"flash.display.DisplayObject.set_cacheAsBitmap","flash/display/DisplayObject.hx",512,0x869a4209)
	HX_STACK_THIS(this)
	HX_STACK_ARG(value,"value")
	HX_STACK_LINE(514)
	::flash::display::DisplayObject_obj::lime_display_object_set_cache_as_bitmap(this->__handle,value);
	HX_STACK_LINE(515)
	return value;
}


HX_DEFINE_DYNAMIC_FUNC1(DisplayObject_obj,set_cacheAsBitmap,return )

bool DisplayObject_obj::get_pedanticBitmapCaching( ){
	HX_STACK_FRAME("flash.display.DisplayObject","get_pedanticBitmapCaching",0x7ff6845e,"flash.display.DisplayObject.get_pedanticBitmapCaching","flash/display/DisplayObject.hx",520,0x869a4209)
	HX_STACK_THIS(this)
	HX_STACK_LINE(520)
	return ::flash::display::DisplayObject_obj::lime_display_object_get_pedantic_bitmap_caching(this->__handle);
}


HX_DEFINE_DYNAMIC_FUNC0(DisplayObject_obj,get_pedanticBitmapCaching,return )

bool DisplayObject_obj::set_pedanticBitmapCaching( bool value){
	HX_STACK_FRAME("flash.display.DisplayObject","set_pedanticBitmapCaching",0xec4d486a,"flash.display.DisplayObject.set_pedanticBitmapCaching","flash/display/DisplayObject.hx",521,0x869a4209)
	HX_STACK_THIS(this)
	HX_STACK_ARG(value,"value")
	HX_STACK_LINE(523)
	::flash::display::DisplayObject_obj::lime_display_object_set_pedantic_bitmap_caching(this->__handle,value);
	HX_STACK_LINE(524)
	return value;
}


HX_DEFINE_DYNAMIC_FUNC1(DisplayObject_obj,set_pedanticBitmapCaching,return )

::flash::display::PixelSnapping DisplayObject_obj::get_pixelSnapping( ){
	HX_STACK_FRAME("flash.display.DisplayObject","get_pixelSnapping",0x6886ada2,"flash.display.DisplayObject.get_pixelSnapping","flash/display/DisplayObject.hx",529,0x869a4209)
	HX_STACK_THIS(this)
	HX_STACK_LINE(531)
	int i = ::flash::display::DisplayObject_obj::lime_display_object_get_pixel_snapping(this->__handle);		HX_STACK_VAR(i,"i");
	HX_STACK_LINE(532)
	return ::Type_obj::createEnumIndex(hx::ClassOf< ::flash::display::PixelSnapping >(),i,null());
}


HX_DEFINE_DYNAMIC_FUNC0(DisplayObject_obj,get_pixelSnapping,return )

::flash::display::PixelSnapping DisplayObject_obj::set_pixelSnapping( ::flash::display::PixelSnapping value){
	HX_STACK_FRAME("flash.display.DisplayObject","set_pixelSnapping",0x8bf485ae,"flash.display.DisplayObject.set_pixelSnapping","flash/display/DisplayObject.hx",537,0x869a4209)
	HX_STACK_THIS(this)
	HX_STACK_ARG(value,"value")
	HX_STACK_LINE(539)
	if (((value == null()))){
		HX_STACK_LINE(541)
		::flash::display::DisplayObject_obj::lime_display_object_set_pixel_snapping(this->__handle,(int)0);
	}
	else{
		HX_STACK_LINE(545)
		::flash::display::DisplayObject_obj::lime_display_object_set_pixel_snapping(this->__handle,value->__Index());
	}
	HX_STACK_LINE(549)
	return value;
}


HX_DEFINE_DYNAMIC_FUNC1(DisplayObject_obj,set_pixelSnapping,return )

Dynamic DisplayObject_obj::get_filters( ){
	HX_STACK_FRAME("flash.display.DisplayObject","get_filters",0xf858b0fb,"flash.display.DisplayObject.get_filters","flash/display/DisplayObject.hx",554,0x869a4209)
	HX_STACK_THIS(this)
	HX_STACK_LINE(556)
	if (((this->__filters == null()))){
		HX_STACK_LINE(556)
		return Dynamic( Array_obj<Dynamic>::__new());
	}
	HX_STACK_LINE(557)
	Dynamic result = Dynamic( Array_obj<Dynamic>::__new() );		HX_STACK_VAR(result,"result");
	HX_STACK_LINE(559)
	{
		HX_STACK_LINE(559)
		int _g = (int)0;		HX_STACK_VAR(_g,"_g");
		HX_STACK_LINE(559)
		Dynamic _g1 = this->__filters;		HX_STACK_VAR(_g1,"_g1");
		HX_STACK_LINE(559)
		while(((_g < _g1->__Field(HX_CSTRING("length"),true)))){
			HX_STACK_LINE(559)
			Dynamic filter = _g1->__GetItem(_g);		HX_STACK_VAR(filter,"filter");
			HX_STACK_LINE(559)
			++(_g);
			HX_STACK_LINE(561)
			result->__Field(HX_CSTRING("push"),true)(filter->__Field(HX_CSTRING("clone"),true)());
		}
	}
	HX_STACK_LINE(565)
	return result;
}


HX_DEFINE_DYNAMIC_FUNC0(DisplayObject_obj,get_filters,return )

Dynamic DisplayObject_obj::set_filters( Dynamic value){
	HX_STACK_FRAME("flash.display.DisplayObject","set_filters",0x02c5b807,"flash.display.DisplayObject.set_filters","flash/display/DisplayObject.hx",570,0x869a4209)
	HX_STACK_THIS(this)
	HX_STACK_ARG(value,"value")
	HX_STACK_LINE(572)
	if (((  ((!(((this->get_filters() == null()))))) ? bool((value == null())) : bool(true) ))){
		HX_STACK_LINE(574)
		this->__filters = null();
	}
	else{
		HX_STACK_LINE(578)
		this->__filters = Dynamic( Array_obj<Dynamic>::__new() );
		HX_STACK_LINE(580)
		{
			HX_STACK_LINE(580)
			int _g = (int)0;		HX_STACK_VAR(_g,"_g");
			HX_STACK_LINE(580)
			while(((_g < value->__Field(HX_CSTRING("length"),true)))){
				HX_STACK_LINE(580)
				Dynamic filter = value->__GetItem(_g);		HX_STACK_VAR(filter,"filter");
				HX_STACK_LINE(580)
				++(_g);
				HX_STACK_LINE(582)
				this->__filters->__Field(HX_CSTRING("push"),true)(filter->__Field(HX_CSTRING("clone"),true)());
			}
		}
	}
	HX_STACK_LINE(588)
	::flash::display::DisplayObject_obj::lime_display_object_set_filters(this->__handle,this->__filters);
	HX_STACK_LINE(589)
	return this->get_filters();
}


HX_DEFINE_DYNAMIC_FUNC1(DisplayObject_obj,set_filters,return )

::flash::display::Graphics DisplayObject_obj::get_graphics( ){
	HX_STACK_FRAME("flash.display.DisplayObject","get_graphics",0x5323418b,"flash.display.DisplayObject.get_graphics","flash/display/DisplayObject.hx",594,0x869a4209)
	HX_STACK_THIS(this)
	HX_STACK_LINE(596)
	if (((this->__graphicsCache == null()))){
		HX_STACK_LINE(598)
		this->__graphicsCache = ::flash::display::Graphics_obj::__new(::flash::display::DisplayObject_obj::lime_display_object_get_graphics(this->__handle));
	}
	HX_STACK_LINE(602)
	return this->__graphicsCache;
}


HX_DEFINE_DYNAMIC_FUNC0(DisplayObject_obj,get_graphics,return )

Float DisplayObject_obj::get_height( ){
	HX_STACK_FRAME("flash.display.DisplayObject","get_height",0xe45fa0a7,"flash.display.DisplayObject.get_height","flash/display/DisplayObject.hx",607,0x869a4209)
	HX_STACK_THIS(this)
	HX_STACK_LINE(607)
	return ::flash::display::DisplayObject_obj::lime_display_object_get_height(this->__handle);
}


HX_DEFINE_DYNAMIC_FUNC0(DisplayObject_obj,get_height,return )

Float DisplayObject_obj::set_height( Float value){
	HX_STACK_FRAME("flash.display.DisplayObject","set_height",0xe7dd3f1b,"flash.display.DisplayObject.set_height","flash/display/DisplayObject.hx",608,0x869a4209)
	HX_STACK_THIS(this)
	HX_STACK_ARG(value,"value")
	HX_STACK_LINE(610)
	::flash::display::DisplayObject_obj::lime_display_object_set_height(this->__handle,value);
	HX_STACK_LINE(611)
	return value;
}


HX_DEFINE_DYNAMIC_FUNC1(DisplayObject_obj,set_height,return )

::flash::display::DisplayObject DisplayObject_obj::set_mask( ::flash::display::DisplayObject value){
	HX_STACK_FRAME("flash.display.DisplayObject","set_mask",0x0c6b8320,"flash.display.DisplayObject.set_mask","flash/display/DisplayObject.hx",616,0x869a4209)
	HX_STACK_THIS(this)
	HX_STACK_ARG(value,"value")
	HX_STACK_LINE(618)
	this->mask = value;
	HX_STACK_LINE(619)
	::flash::display::DisplayObject_obj::lime_display_object_set_mask(this->__handle,(  (((value == null()))) ? Dynamic(null()) : Dynamic(value->__handle) ));
	HX_STACK_LINE(620)
	return value;
}


HX_DEFINE_DYNAMIC_FUNC1(DisplayObject_obj,set_mask,return )

Float DisplayObject_obj::get_mouseX( ){
	HX_STACK_FRAME("flash.display.DisplayObject","get_mouseX",0xae21e353,"flash.display.DisplayObject.get_mouseX","flash/display/DisplayObject.hx",625,0x869a4209)
	HX_STACK_THIS(this)
	HX_STACK_LINE(625)
	return ::flash::display::DisplayObject_obj::lime_display_object_get_mouse_x(this->__handle);
}


HX_DEFINE_DYNAMIC_FUNC0(DisplayObject_obj,get_mouseX,return )

Float DisplayObject_obj::get_mouseY( ){
	HX_STACK_FRAME("flash.display.DisplayObject","get_mouseY",0xae21e354,"flash.display.DisplayObject.get_mouseY","flash/display/DisplayObject.hx",626,0x869a4209)
	HX_STACK_THIS(this)
	HX_STACK_LINE(626)
	return ::flash::display::DisplayObject_obj::lime_display_object_get_mouse_y(this->__handle);
}


HX_DEFINE_DYNAMIC_FUNC0(DisplayObject_obj,get_mouseY,return )

::String DisplayObject_obj::get_name( ){
	HX_STACK_FRAME("flash.display.DisplayObject","get_name",0x5eb75b0b,"flash.display.DisplayObject.get_name","flash/display/DisplayObject.hx",629,0x869a4209)
	HX_STACK_THIS(this)
	HX_STACK_LINE(629)
	return ::flash::display::DisplayObject_obj::lime_display_object_get_name(this->__handle);
}


HX_DEFINE_DYNAMIC_FUNC0(DisplayObject_obj,get_name,return )

::String DisplayObject_obj::set_name( ::String value){
	HX_STACK_FRAME("flash.display.DisplayObject","set_name",0x0d14b47f,"flash.display.DisplayObject.set_name","flash/display/DisplayObject.hx",630,0x869a4209)
	HX_STACK_THIS(this)
	HX_STACK_ARG(value,"value")
	HX_STACK_LINE(632)
	::flash::display::DisplayObject_obj::lime_display_object_set_name(this->__handle,value);
	HX_STACK_LINE(633)
	return value;
}


HX_DEFINE_DYNAMIC_FUNC1(DisplayObject_obj,set_name,return )

::flash::display::DisplayObjectContainer DisplayObject_obj::get_parent( ){
	HX_STACK_FRAME("flash.display.DisplayObject","get_parent",0xcf919dea,"flash.display.DisplayObject.get_parent","flash/display/DisplayObject.hx",638,0x869a4209)
	HX_STACK_THIS(this)
	HX_STACK_LINE(638)
	return this->__parent;
}


HX_DEFINE_DYNAMIC_FUNC0(DisplayObject_obj,get_parent,return )

Float DisplayObject_obj::get_rotation( ){
	HX_STACK_FRAME("flash.display.DisplayObject","get_rotation",0x494185fe,"flash.display.DisplayObject.get_rotation","flash/display/DisplayObject.hx",641,0x869a4209)
	HX_STACK_THIS(this)
	HX_STACK_LINE(641)
	return ::flash::display::DisplayObject_obj::lime_display_object_get_rotation(this->__handle);
}


HX_DEFINE_DYNAMIC_FUNC0(DisplayObject_obj,get_rotation,return )

Float DisplayObject_obj::set_rotation( Float value){
	HX_STACK_FRAME("flash.display.DisplayObject","set_rotation",0x5e3aa972,"flash.display.DisplayObject.set_rotation","flash/display/DisplayObject.hx",642,0x869a4209)
	HX_STACK_THIS(this)
	HX_STACK_ARG(value,"value")
	HX_STACK_LINE(644)
	::flash::display::DisplayObject_obj::lime_display_object_set_rotation(this->__handle,value);
	HX_STACK_LINE(645)
	return value;
}


HX_DEFINE_DYNAMIC_FUNC1(DisplayObject_obj,set_rotation,return )

::flash::geom::Rectangle DisplayObject_obj::get_scale9Grid( ){
	HX_STACK_FRAME("flash.display.DisplayObject","get_scale9Grid",0xebd14995,"flash.display.DisplayObject.get_scale9Grid","flash/display/DisplayObject.hx",650,0x869a4209)
	HX_STACK_THIS(this)
	HX_STACK_LINE(650)
	if (((this->__scale9Grid == null()))){
		HX_STACK_LINE(650)
		return null();
	}
	else{
		HX_STACK_LINE(650)
		return this->__scale9Grid->clone();
	}
	HX_STACK_LINE(650)
	return null();
}


HX_DEFINE_DYNAMIC_FUNC0(DisplayObject_obj,get_scale9Grid,return )

::flash::geom::Rectangle DisplayObject_obj::set_scale9Grid( ::flash::geom::Rectangle value){
	HX_STACK_FRAME("flash.display.DisplayObject","set_scale9Grid",0x0bf13209,"flash.display.DisplayObject.set_scale9Grid","flash/display/DisplayObject.hx",651,0x869a4209)
	HX_STACK_THIS(this)
	HX_STACK_ARG(value,"value")
	HX_STACK_LINE(653)
	if (((value == null()))){
		HX_STACK_LINE(653)
		this->__scale9Grid = null();
	}
	else{
		HX_STACK_LINE(653)
		this->__scale9Grid = value->clone();
	}
	HX_STACK_LINE(654)
	::flash::display::DisplayObject_obj::lime_display_object_set_scale9_grid(this->__handle,this->__scale9Grid);
	HX_STACK_LINE(655)
	return value;
}


HX_DEFINE_DYNAMIC_FUNC1(DisplayObject_obj,set_scale9Grid,return )

Float DisplayObject_obj::get_scaleX( ){
	HX_STACK_FRAME("flash.display.DisplayObject","get_scaleX",0x1e39834e,"flash.display.DisplayObject.get_scaleX","flash/display/DisplayObject.hx",660,0x869a4209)
	HX_STACK_THIS(this)
	HX_STACK_LINE(660)
	return ::flash::display::DisplayObject_obj::lime_display_object_get_scale_x(this->__handle);
}


HX_DEFINE_DYNAMIC_FUNC0(DisplayObject_obj,get_scaleX,return )

Float DisplayObject_obj::set_scaleX( Float value){
	HX_STACK_FRAME("flash.display.DisplayObject","set_scaleX",0x21b721c2,"flash.display.DisplayObject.set_scaleX","flash/display/DisplayObject.hx",661,0x869a4209)
	HX_STACK_THIS(this)
	HX_STACK_ARG(value,"value")
	HX_STACK_LINE(663)
	::flash::display::DisplayObject_obj::lime_display_object_set_scale_x(this->__handle,value);
	HX_STACK_LINE(664)
	return value;
}


HX_DEFINE_DYNAMIC_FUNC1(DisplayObject_obj,set_scaleX,return )

Float DisplayObject_obj::get_scaleY( ){
	HX_STACK_FRAME("flash.display.DisplayObject","get_scaleY",0x1e39834f,"flash.display.DisplayObject.get_scaleY","flash/display/DisplayObject.hx",669,0x869a4209)
	HX_STACK_THIS(this)
	HX_STACK_LINE(669)
	return ::flash::display::DisplayObject_obj::lime_display_object_get_scale_y(this->__handle);
}


HX_DEFINE_DYNAMIC_FUNC0(DisplayObject_obj,get_scaleY,return )

Float DisplayObject_obj::set_scaleY( Float value){
	HX_STACK_FRAME("flash.display.DisplayObject","set_scaleY",0x21b721c3,"flash.display.DisplayObject.set_scaleY","flash/display/DisplayObject.hx",670,0x869a4209)
	HX_STACK_THIS(this)
	HX_STACK_ARG(value,"value")
	HX_STACK_LINE(672)
	::flash::display::DisplayObject_obj::lime_display_object_set_scale_y(this->__handle,value);
	HX_STACK_LINE(673)
	return value;
}


HX_DEFINE_DYNAMIC_FUNC1(DisplayObject_obj,set_scaleY,return )

::flash::geom::Rectangle DisplayObject_obj::get_scrollRect( ){
	HX_STACK_FRAME("flash.display.DisplayObject","get_scrollRect",0x6615d491,"flash.display.DisplayObject.get_scrollRect","flash/display/DisplayObject.hx",678,0x869a4209)
	HX_STACK_THIS(this)
	HX_STACK_LINE(678)
	if (((this->__scrollRect == null()))){
		HX_STACK_LINE(678)
		return null();
	}
	else{
		HX_STACK_LINE(678)
		return this->__scrollRect->clone();
	}
	HX_STACK_LINE(678)
	return null();
}


HX_DEFINE_DYNAMIC_FUNC0(DisplayObject_obj,get_scrollRect,return )

::flash::geom::Rectangle DisplayObject_obj::set_scrollRect( ::flash::geom::Rectangle value){
	HX_STACK_FRAME("flash.display.DisplayObject","set_scrollRect",0x8635bd05,"flash.display.DisplayObject.set_scrollRect","flash/display/DisplayObject.hx",679,0x869a4209)
	HX_STACK_THIS(this)
	HX_STACK_ARG(value,"value")
	HX_STACK_LINE(681)
	if (((value == null()))){
		HX_STACK_LINE(681)
		this->__scrollRect = null();
	}
	else{
		HX_STACK_LINE(681)
		this->__scrollRect = value->clone();
	}
	HX_STACK_LINE(682)
	::flash::display::DisplayObject_obj::lime_display_object_set_scroll_rect(this->__handle,this->__scrollRect);
	HX_STACK_LINE(683)
	return value;
}


HX_DEFINE_DYNAMIC_FUNC1(DisplayObject_obj,set_scrollRect,return )

::flash::display::Stage DisplayObject_obj::get_stage( ){
	HX_STACK_FRAME("flash.display.DisplayObject","get_stage",0x6f3f29fe,"flash.display.DisplayObject.get_stage","flash/display/DisplayObject.hx",688,0x869a4209)
	HX_STACK_THIS(this)
	HX_STACK_LINE(690)
	if (((this->__parent != null()))){
		HX_STACK_LINE(692)
		return this->__parent->get_stage();
	}
	HX_STACK_LINE(696)
	return null();
}


HX_DEFINE_DYNAMIC_FUNC0(DisplayObject_obj,get_stage,return )

::flash::geom::Transform DisplayObject_obj::get_transform( ){
	HX_STACK_FRAME("flash.display.DisplayObject","get_transform",0xa8b78cac,"flash.display.DisplayObject.get_transform","flash/display/DisplayObject.hx",701,0x869a4209)
	HX_STACK_THIS(this)
	HX_STACK_LINE(701)
	return ::flash::geom::Transform_obj::__new(hx::ObjectPtr<OBJ_>(this));
}


HX_DEFINE_DYNAMIC_FUNC0(DisplayObject_obj,get_transform,return )

::flash::geom::Transform DisplayObject_obj::set_transform( ::flash::geom::Transform value){
	HX_STACK_FRAME("flash.display.DisplayObject","set_transform",0xedbd6eb8,"flash.display.DisplayObject.set_transform","flash/display/DisplayObject.hx",702,0x869a4209)
	HX_STACK_THIS(this)
	HX_STACK_ARG(value,"value")
	HX_STACK_LINE(704)
	this->__setMatrix(value->get_matrix());
	HX_STACK_LINE(705)
	this->__setColorTransform(value->get_colorTransform());
	HX_STACK_LINE(706)
	return value;
}


HX_DEFINE_DYNAMIC_FUNC1(DisplayObject_obj,set_transform,return )

bool DisplayObject_obj::get_visible( ){
	HX_STACK_FRAME("flash.display.DisplayObject","get_visible",0x923687b2,"flash.display.DisplayObject.get_visible","flash/display/DisplayObject.hx",711,0x869a4209)
	HX_STACK_THIS(this)
	HX_STACK_LINE(711)
	return ::flash::display::DisplayObject_obj::lime_display_object_get_visible(this->__handle);
}


HX_DEFINE_DYNAMIC_FUNC0(DisplayObject_obj,get_visible,return )

bool DisplayObject_obj::set_visible( bool value){
	HX_STACK_FRAME("flash.display.DisplayObject","set_visible",0x9ca38ebe,"flash.display.DisplayObject.set_visible","flash/display/DisplayObject.hx",712,0x869a4209)
	HX_STACK_THIS(this)
	HX_STACK_ARG(value,"value")
	HX_STACK_LINE(714)
	::flash::display::DisplayObject_obj::lime_display_object_set_visible(this->__handle,value);
	HX_STACK_LINE(715)
	return value;
}


HX_DEFINE_DYNAMIC_FUNC1(DisplayObject_obj,set_visible,return )

Float DisplayObject_obj::get_width( ){
	HX_STACK_FRAME("flash.display.DisplayObject","get_width",0xb5967546,"flash.display.DisplayObject.get_width","flash/display/DisplayObject.hx",720,0x869a4209)
	HX_STACK_THIS(this)
	HX_STACK_LINE(720)
	return ::flash::display::DisplayObject_obj::lime_display_object_get_width(this->__handle);
}


HX_DEFINE_DYNAMIC_FUNC0(DisplayObject_obj,get_width,return )

Float DisplayObject_obj::set_width( Float value){
	HX_STACK_FRAME("flash.display.DisplayObject","set_width",0x98e76152,"flash.display.DisplayObject.set_width","flash/display/DisplayObject.hx",721,0x869a4209)
	HX_STACK_THIS(this)
	HX_STACK_ARG(value,"value")
	HX_STACK_LINE(723)
	::flash::display::DisplayObject_obj::lime_display_object_set_width(this->__handle,value);
	HX_STACK_LINE(724)
	return value;
}


HX_DEFINE_DYNAMIC_FUNC1(DisplayObject_obj,set_width,return )

Float DisplayObject_obj::get_x( ){
	HX_STACK_FRAME("flash.display.DisplayObject","get_x",0xa0131fb8,"flash.display.DisplayObject.get_x","flash/display/DisplayObject.hx",729,0x869a4209)
	HX_STACK_THIS(this)
	HX_STACK_LINE(729)
	return ::flash::display::DisplayObject_obj::lime_display_object_get_x(this->__handle);
}


HX_DEFINE_DYNAMIC_FUNC0(DisplayObject_obj,get_x,return )

Float DisplayObject_obj::set_x( Float value){
	HX_STACK_FRAME("flash.display.DisplayObject","set_x",0x88e215c4,"flash.display.DisplayObject.set_x","flash/display/DisplayObject.hx",730,0x869a4209)
	HX_STACK_THIS(this)
	HX_STACK_ARG(value,"value")
	HX_STACK_LINE(732)
	::flash::display::DisplayObject_obj::lime_display_object_set_x(this->__handle,value);
	HX_STACK_LINE(733)
	return value;
}


HX_DEFINE_DYNAMIC_FUNC1(DisplayObject_obj,set_x,return )

Float DisplayObject_obj::get_y( ){
	HX_STACK_FRAME("flash.display.DisplayObject","get_y",0xa0131fb9,"flash.display.DisplayObject.get_y","flash/display/DisplayObject.hx",738,0x869a4209)
	HX_STACK_THIS(this)
	HX_STACK_LINE(738)
	return ::flash::display::DisplayObject_obj::lime_display_object_get_y(this->__handle);
}


HX_DEFINE_DYNAMIC_FUNC0(DisplayObject_obj,get_y,return )

Float DisplayObject_obj::set_y( Float value){
	HX_STACK_FRAME("flash.display.DisplayObject","set_y",0x88e215c5,"flash.display.DisplayObject.set_y","flash/display/DisplayObject.hx",739,0x869a4209)
	HX_STACK_THIS(this)
	HX_STACK_ARG(value,"value")
	HX_STACK_LINE(741)
	::flash::display::DisplayObject_obj::lime_display_object_set_y(this->__handle,value);
	HX_STACK_LINE(742)
	return value;
}


HX_DEFINE_DYNAMIC_FUNC1(DisplayObject_obj,set_y,return )

Dynamic DisplayObject_obj::lime_create_display_object;

Dynamic DisplayObject_obj::lime_display_object_get_graphics;

Dynamic DisplayObject_obj::lime_display_object_draw_to_surface;

Dynamic DisplayObject_obj::lime_display_object_get_id;

Dynamic DisplayObject_obj::lime_display_object_get_x;

Dynamic DisplayObject_obj::lime_display_object_set_x;

Dynamic DisplayObject_obj::lime_display_object_get_y;

Dynamic DisplayObject_obj::lime_display_object_set_y;

Dynamic DisplayObject_obj::lime_display_object_get_scale_x;

Dynamic DisplayObject_obj::lime_display_object_set_scale_x;

Dynamic DisplayObject_obj::lime_display_object_get_scale_y;

Dynamic DisplayObject_obj::lime_display_object_set_scale_y;

Dynamic DisplayObject_obj::lime_display_object_get_mouse_x;

Dynamic DisplayObject_obj::lime_display_object_get_mouse_y;

Dynamic DisplayObject_obj::lime_display_object_get_rotation;

Dynamic DisplayObject_obj::lime_display_object_set_rotation;

Dynamic DisplayObject_obj::lime_display_object_get_bg;

Dynamic DisplayObject_obj::lime_display_object_set_bg;

Dynamic DisplayObject_obj::lime_display_object_get_name;

Dynamic DisplayObject_obj::lime_display_object_set_name;

Dynamic DisplayObject_obj::lime_display_object_get_width;

Dynamic DisplayObject_obj::lime_display_object_set_width;

Dynamic DisplayObject_obj::lime_display_object_get_height;

Dynamic DisplayObject_obj::lime_display_object_set_height;

Dynamic DisplayObject_obj::lime_display_object_get_alpha;

Dynamic DisplayObject_obj::lime_display_object_set_alpha;

Dynamic DisplayObject_obj::lime_display_object_get_blend_mode;

Dynamic DisplayObject_obj::lime_display_object_set_blend_mode;

Dynamic DisplayObject_obj::lime_display_object_get_cache_as_bitmap;

Dynamic DisplayObject_obj::lime_display_object_set_cache_as_bitmap;

Dynamic DisplayObject_obj::lime_display_object_get_pedantic_bitmap_caching;

Dynamic DisplayObject_obj::lime_display_object_set_pedantic_bitmap_caching;

Dynamic DisplayObject_obj::lime_display_object_get_pixel_snapping;

Dynamic DisplayObject_obj::lime_display_object_set_pixel_snapping;

Dynamic DisplayObject_obj::lime_display_object_get_visible;

Dynamic DisplayObject_obj::lime_display_object_set_visible;

Dynamic DisplayObject_obj::lime_display_object_set_filters;

Dynamic DisplayObject_obj::lime_display_object_global_to_local;

Dynamic DisplayObject_obj::lime_display_object_local_to_global;

Dynamic DisplayObject_obj::lime_display_object_set_scale9_grid;

Dynamic DisplayObject_obj::lime_display_object_set_scroll_rect;

Dynamic DisplayObject_obj::lime_display_object_set_mask;

Dynamic DisplayObject_obj::lime_display_object_set_matrix;

Dynamic DisplayObject_obj::lime_display_object_get_matrix;

Dynamic DisplayObject_obj::lime_display_object_get_color_transform;

Dynamic DisplayObject_obj::lime_display_object_set_color_transform;

Dynamic DisplayObject_obj::lime_display_object_get_pixel_bounds;

Dynamic DisplayObject_obj::lime_display_object_get_bounds;

Dynamic DisplayObject_obj::lime_display_object_hit_test_point;


DisplayObject_obj::DisplayObject_obj()
{
}

void DisplayObject_obj::__Mark(HX_MARK_PARAMS)
{
	HX_MARK_BEGIN_CLASS(DisplayObject);
	HX_MARK_MEMBER_NAME(graphics,"graphics");
	HX_MARK_MEMBER_NAME(loaderInfo,"loaderInfo");
	HX_MARK_MEMBER_NAME(mask,"mask");
	HX_MARK_MEMBER_NAME(mouseX,"mouseX");
	HX_MARK_MEMBER_NAME(mouseY,"mouseY");
	HX_MARK_MEMBER_NAME(parent,"parent");
	HX_MARK_MEMBER_NAME(stage,"stage");
	HX_MARK_MEMBER_NAME(__handle,"__handle");
	HX_MARK_MEMBER_NAME(__filters,"__filters");
	HX_MARK_MEMBER_NAME(__graphicsCache,"__graphicsCache");
	HX_MARK_MEMBER_NAME(__id,"__id");
	HX_MARK_MEMBER_NAME(__parent,"__parent");
	HX_MARK_MEMBER_NAME(__scale9Grid,"__scale9Grid");
	HX_MARK_MEMBER_NAME(__scrollRect,"__scrollRect");
	::flash::events::EventDispatcher_obj::__Mark(HX_MARK_ARG);
	HX_MARK_END_CLASS();
}

void DisplayObject_obj::__Visit(HX_VISIT_PARAMS)
{
	HX_VISIT_MEMBER_NAME(graphics,"graphics");
	HX_VISIT_MEMBER_NAME(loaderInfo,"loaderInfo");
	HX_VISIT_MEMBER_NAME(mask,"mask");
	HX_VISIT_MEMBER_NAME(mouseX,"mouseX");
	HX_VISIT_MEMBER_NAME(mouseY,"mouseY");
	HX_VISIT_MEMBER_NAME(parent,"parent");
	HX_VISIT_MEMBER_NAME(stage,"stage");
	HX_VISIT_MEMBER_NAME(__handle,"__handle");
	HX_VISIT_MEMBER_NAME(__filters,"__filters");
	HX_VISIT_MEMBER_NAME(__graphicsCache,"__graphicsCache");
	HX_VISIT_MEMBER_NAME(__id,"__id");
	HX_VISIT_MEMBER_NAME(__parent,"__parent");
	HX_VISIT_MEMBER_NAME(__scale9Grid,"__scale9Grid");
	HX_VISIT_MEMBER_NAME(__scrollRect,"__scrollRect");
	::flash::events::EventDispatcher_obj::__Visit(HX_VISIT_ARG);
}

Dynamic DisplayObject_obj::__Field(const ::String &inName,bool inCallProp)
{
	switch(inName.length) {
	case 1:
		if (HX_FIELD_EQ(inName,"x") ) { return get_x(); }
		if (HX_FIELD_EQ(inName,"y") ) { return get_y(); }
		break;
	case 4:
		if (HX_FIELD_EQ(inName,"mask") ) { return mask; }
		if (HX_FIELD_EQ(inName,"name") ) { return get_name(); }
		if (HX_FIELD_EQ(inName,"__id") ) { return __id; }
		break;
	case 5:
		if (HX_FIELD_EQ(inName,"alpha") ) { return get_alpha(); }
		if (HX_FIELD_EQ(inName,"stage") ) { return inCallProp ? get_stage() : stage; }
		if (HX_FIELD_EQ(inName,"width") ) { return get_width(); }
		if (HX_FIELD_EQ(inName,"get_x") ) { return get_x_dyn(); }
		if (HX_FIELD_EQ(inName,"set_x") ) { return set_x_dyn(); }
		if (HX_FIELD_EQ(inName,"get_y") ) { return get_y_dyn(); }
		if (HX_FIELD_EQ(inName,"set_y") ) { return set_y_dyn(); }
		break;
	case 6:
		if (HX_FIELD_EQ(inName,"height") ) { return get_height(); }
		if (HX_FIELD_EQ(inName,"mouseX") ) { return inCallProp ? get_mouseX() : mouseX; }
		if (HX_FIELD_EQ(inName,"mouseY") ) { return inCallProp ? get_mouseY() : mouseY; }
		if (HX_FIELD_EQ(inName,"parent") ) { return inCallProp ? get_parent() : parent; }
		if (HX_FIELD_EQ(inName,"scaleX") ) { return get_scaleX(); }
		if (HX_FIELD_EQ(inName,"scaleY") ) { return get_scaleY(); }
		break;
	case 7:
		if (HX_FIELD_EQ(inName,"filters") ) { return get_filters(); }
		if (HX_FIELD_EQ(inName,"visible") ) { return get_visible(); }
		if (HX_FIELD_EQ(inName,"getRect") ) { return getRect_dyn(); }
		break;
	case 8:
		if (HX_FIELD_EQ(inName,"graphics") ) { return inCallProp ? get_graphics() : graphics; }
		if (HX_FIELD_EQ(inName,"rotation") ) { return get_rotation(); }
		if (HX_FIELD_EQ(inName,"__handle") ) { return __handle; }
		if (HX_FIELD_EQ(inName,"__parent") ) { return __parent; }
		if (HX_FIELD_EQ(inName,"toString") ) { return toString_dyn(); }
		if (HX_FIELD_EQ(inName,"set_mask") ) { return set_mask_dyn(); }
		if (HX_FIELD_EQ(inName,"get_name") ) { return get_name_dyn(); }
		if (HX_FIELD_EQ(inName,"set_name") ) { return set_name_dyn(); }
		break;
	case 9:
		if (HX_FIELD_EQ(inName,"blendMode") ) { return get_blendMode(); }
		if (HX_FIELD_EQ(inName,"transform") ) { return get_transform(); }
		if (HX_FIELD_EQ(inName,"__filters") ) { return __filters; }
		if (HX_FIELD_EQ(inName,"getBounds") ) { return getBounds_dyn(); }
		if (HX_FIELD_EQ(inName,"__onAdded") ) { return __onAdded_dyn(); }
		if (HX_FIELD_EQ(inName,"get_alpha") ) { return get_alpha_dyn(); }
		if (HX_FIELD_EQ(inName,"set_alpha") ) { return set_alpha_dyn(); }
		if (HX_FIELD_EQ(inName,"get_stage") ) { return get_stage_dyn(); }
		if (HX_FIELD_EQ(inName,"get_width") ) { return get_width_dyn(); }
		if (HX_FIELD_EQ(inName,"set_width") ) { return set_width_dyn(); }
		break;
	case 10:
		if (HX_FIELD_EQ(inName,"loaderInfo") ) { return loaderInfo; }
		if (HX_FIELD_EQ(inName,"scale9Grid") ) { return get_scale9Grid(); }
		if (HX_FIELD_EQ(inName,"scrollRect") ) { return get_scrollRect(); }
		if (HX_FIELD_EQ(inName,"__contains") ) { return __contains_dyn(); }
		if (HX_FIELD_EQ(inName,"__findByID") ) { return __findByID_dyn(); }
		if (HX_FIELD_EQ(inName,"get_height") ) { return get_height_dyn(); }
		if (HX_FIELD_EQ(inName,"set_height") ) { return set_height_dyn(); }
		if (HX_FIELD_EQ(inName,"get_mouseX") ) { return get_mouseX_dyn(); }
		if (HX_FIELD_EQ(inName,"get_mouseY") ) { return get_mouseY_dyn(); }
		if (HX_FIELD_EQ(inName,"get_parent") ) { return get_parent_dyn(); }
		if (HX_FIELD_EQ(inName,"get_scaleX") ) { return get_scaleX_dyn(); }
		if (HX_FIELD_EQ(inName,"set_scaleX") ) { return set_scaleX_dyn(); }
		if (HX_FIELD_EQ(inName,"get_scaleY") ) { return get_scaleY_dyn(); }
		if (HX_FIELD_EQ(inName,"set_scaleY") ) { return set_scaleY_dyn(); }
		break;
	case 11:
		if (HX_FIELD_EQ(inName,"__broadcast") ) { return __broadcast_dyn(); }
		if (HX_FIELD_EQ(inName,"__fireEvent") ) { return __fireEvent_dyn(); }
		if (HX_FIELD_EQ(inName,"__getMatrix") ) { return __getMatrix_dyn(); }
		if (HX_FIELD_EQ(inName,"__onRemoved") ) { return __onRemoved_dyn(); }
		if (HX_FIELD_EQ(inName,"__setMatrix") ) { return __setMatrix_dyn(); }
		if (HX_FIELD_EQ(inName,"__setParent") ) { return __setParent_dyn(); }
		if (HX_FIELD_EQ(inName,"get_filters") ) { return get_filters_dyn(); }
		if (HX_FIELD_EQ(inName,"set_filters") ) { return set_filters_dyn(); }
		if (HX_FIELD_EQ(inName,"get_visible") ) { return get_visible_dyn(); }
		if (HX_FIELD_EQ(inName,"set_visible") ) { return set_visible_dyn(); }
		break;
	case 12:
		if (HX_FIELD_EQ(inName,"__scale9Grid") ) { return __scale9Grid; }
		if (HX_FIELD_EQ(inName,"__scrollRect") ) { return __scrollRect; }
		if (HX_FIELD_EQ(inName,"hitTestPoint") ) { return hitTestPoint_dyn(); }
		if (HX_FIELD_EQ(inName,"get_graphics") ) { return get_graphics_dyn(); }
		if (HX_FIELD_EQ(inName,"get_rotation") ) { return get_rotation_dyn(); }
		if (HX_FIELD_EQ(inName,"set_rotation") ) { return set_rotation_dyn(); }
		break;
	case 13:
		if (HX_FIELD_EQ(inName,"cacheAsBitmap") ) { return get_cacheAsBitmap(); }
		if (HX_FIELD_EQ(inName,"pixelSnapping") ) { return get_pixelSnapping(); }
		if (HX_FIELD_EQ(inName,"dispatchEvent") ) { return dispatchEvent_dyn(); }
		if (HX_FIELD_EQ(inName,"globalToLocal") ) { return globalToLocal_dyn(); }
		if (HX_FIELD_EQ(inName,"hitTestObject") ) { return hitTestObject_dyn(); }
		if (HX_FIELD_EQ(inName,"localToGlobal") ) { return localToGlobal_dyn(); }
		if (HX_FIELD_EQ(inName,"get_blendMode") ) { return get_blendMode_dyn(); }
		if (HX_FIELD_EQ(inName,"set_blendMode") ) { return set_blendMode_dyn(); }
		if (HX_FIELD_EQ(inName,"get_transform") ) { return get_transform_dyn(); }
		if (HX_FIELD_EQ(inName,"set_transform") ) { return set_transform_dyn(); }
		break;
	case 14:
		if (HX_FIELD_EQ(inName,"get_scale9Grid") ) { return get_scale9Grid_dyn(); }
		if (HX_FIELD_EQ(inName,"set_scale9Grid") ) { return set_scale9Grid_dyn(); }
		if (HX_FIELD_EQ(inName,"get_scrollRect") ) { return get_scrollRect_dyn(); }
		if (HX_FIELD_EQ(inName,"set_scrollRect") ) { return set_scrollRect_dyn(); }
		break;
	case 15:
		if (HX_FIELD_EQ(inName,"__graphicsCache") ) { return __graphicsCache; }
		if (HX_FIELD_EQ(inName,"__dispatchEvent") ) { return __dispatchEvent_dyn(); }
		if (HX_FIELD_EQ(inName,"__drawToSurface") ) { return __drawToSurface_dyn(); }
		break;
	case 16:
		if (HX_FIELD_EQ(inName,"opaqueBackground") ) { return get_opaqueBackground(); }
		if (HX_FIELD_EQ(inName,"__getPixelBounds") ) { return __getPixelBounds_dyn(); }
		break;
	case 17:
		if (HX_FIELD_EQ(inName,"get_cacheAsBitmap") ) { return get_cacheAsBitmap_dyn(); }
		if (HX_FIELD_EQ(inName,"set_cacheAsBitmap") ) { return set_cacheAsBitmap_dyn(); }
		if (HX_FIELD_EQ(inName,"get_pixelSnapping") ) { return get_pixelSnapping_dyn(); }
		if (HX_FIELD_EQ(inName,"set_pixelSnapping") ) { return set_pixelSnapping_dyn(); }
		break;
	case 19:
		if (HX_FIELD_EQ(inName,"__getColorTransform") ) { return __getColorTransform_dyn(); }
		if (HX_FIELD_EQ(inName,"__setColorTransform") ) { return __setColorTransform_dyn(); }
		break;
	case 20:
		if (HX_FIELD_EQ(inName,"get_opaqueBackground") ) { return get_opaqueBackground_dyn(); }
		if (HX_FIELD_EQ(inName,"set_opaqueBackground") ) { return set_opaqueBackground_dyn(); }
		break;
	case 21:
		if (HX_FIELD_EQ(inName,"pedanticBitmapCaching") ) { return get_pedanticBitmapCaching(); }
		if (HX_FIELD_EQ(inName,"__asInteractiveObject") ) { return __asInteractiveObject_dyn(); }
		break;
	case 22:
		if (HX_FIELD_EQ(inName,"__getObjectsUnderPoint") ) { return __getObjectsUnderPoint_dyn(); }
		break;
	case 23:
		if (HX_FIELD_EQ(inName,"__getConcatenatedMatrix") ) { return __getConcatenatedMatrix_dyn(); }
		break;
	case 25:
		if (HX_FIELD_EQ(inName,"lime_display_object_get_x") ) { return lime_display_object_get_x; }
		if (HX_FIELD_EQ(inName,"lime_display_object_set_x") ) { return lime_display_object_set_x; }
		if (HX_FIELD_EQ(inName,"lime_display_object_get_y") ) { return lime_display_object_get_y; }
		if (HX_FIELD_EQ(inName,"lime_display_object_set_y") ) { return lime_display_object_set_y; }
		if (HX_FIELD_EQ(inName,"get_pedanticBitmapCaching") ) { return get_pedanticBitmapCaching_dyn(); }
		if (HX_FIELD_EQ(inName,"set_pedanticBitmapCaching") ) { return set_pedanticBitmapCaching_dyn(); }
		break;
	case 26:
		if (HX_FIELD_EQ(inName,"lime_create_display_object") ) { return lime_create_display_object; }
		if (HX_FIELD_EQ(inName,"lime_display_object_get_id") ) { return lime_display_object_get_id; }
		if (HX_FIELD_EQ(inName,"lime_display_object_get_bg") ) { return lime_display_object_get_bg; }
		if (HX_FIELD_EQ(inName,"lime_display_object_set_bg") ) { return lime_display_object_set_bg; }
		break;
	case 27:
		if (HX_FIELD_EQ(inName,"__getInteractiveObjectStack") ) { return __getInteractiveObjectStack_dyn(); }
		break;
	case 28:
		if (HX_FIELD_EQ(inName,"lime_display_object_get_name") ) { return lime_display_object_get_name; }
		if (HX_FIELD_EQ(inName,"lime_display_object_set_name") ) { return lime_display_object_set_name; }
		if (HX_FIELD_EQ(inName,"lime_display_object_set_mask") ) { return lime_display_object_set_mask; }
		break;
	case 29:
		if (HX_FIELD_EQ(inName,"lime_display_object_get_width") ) { return lime_display_object_get_width; }
		if (HX_FIELD_EQ(inName,"lime_display_object_set_width") ) { return lime_display_object_set_width; }
		if (HX_FIELD_EQ(inName,"lime_display_object_get_alpha") ) { return lime_display_object_get_alpha; }
		if (HX_FIELD_EQ(inName,"lime_display_object_set_alpha") ) { return lime_display_object_set_alpha; }
		break;
	case 30:
		if (HX_FIELD_EQ(inName,"lime_display_object_get_height") ) { return lime_display_object_get_height; }
		if (HX_FIELD_EQ(inName,"lime_display_object_set_height") ) { return lime_display_object_set_height; }
		if (HX_FIELD_EQ(inName,"lime_display_object_set_matrix") ) { return lime_display_object_set_matrix; }
		if (HX_FIELD_EQ(inName,"lime_display_object_get_matrix") ) { return lime_display_object_get_matrix; }
		if (HX_FIELD_EQ(inName,"lime_display_object_get_bounds") ) { return lime_display_object_get_bounds; }
		break;
	case 31:
		if (HX_FIELD_EQ(inName,"lime_display_object_get_scale_x") ) { return lime_display_object_get_scale_x; }
		if (HX_FIELD_EQ(inName,"lime_display_object_set_scale_x") ) { return lime_display_object_set_scale_x; }
		if (HX_FIELD_EQ(inName,"lime_display_object_get_scale_y") ) { return lime_display_object_get_scale_y; }
		if (HX_FIELD_EQ(inName,"lime_display_object_set_scale_y") ) { return lime_display_object_set_scale_y; }
		if (HX_FIELD_EQ(inName,"lime_display_object_get_mouse_x") ) { return lime_display_object_get_mouse_x; }
		if (HX_FIELD_EQ(inName,"lime_display_object_get_mouse_y") ) { return lime_display_object_get_mouse_y; }
		if (HX_FIELD_EQ(inName,"lime_display_object_get_visible") ) { return lime_display_object_get_visible; }
		if (HX_FIELD_EQ(inName,"lime_display_object_set_visible") ) { return lime_display_object_set_visible; }
		if (HX_FIELD_EQ(inName,"lime_display_object_set_filters") ) { return lime_display_object_set_filters; }
		if (HX_FIELD_EQ(inName,"__getConcatenatedColorTransform") ) { return __getConcatenatedColorTransform_dyn(); }
		break;
	case 32:
		if (HX_FIELD_EQ(inName,"lime_display_object_get_graphics") ) { return lime_display_object_get_graphics; }
		if (HX_FIELD_EQ(inName,"lime_display_object_get_rotation") ) { return lime_display_object_get_rotation; }
		if (HX_FIELD_EQ(inName,"lime_display_object_set_rotation") ) { return lime_display_object_set_rotation; }
		break;
	case 34:
		if (HX_FIELD_EQ(inName,"lime_display_object_get_blend_mode") ) { return lime_display_object_get_blend_mode; }
		if (HX_FIELD_EQ(inName,"lime_display_object_set_blend_mode") ) { return lime_display_object_set_blend_mode; }
		if (HX_FIELD_EQ(inName,"lime_display_object_hit_test_point") ) { return lime_display_object_hit_test_point; }
		break;
	case 35:
		if (HX_FIELD_EQ(inName,"lime_display_object_draw_to_surface") ) { return lime_display_object_draw_to_surface; }
		if (HX_FIELD_EQ(inName,"lime_display_object_global_to_local") ) { return lime_display_object_global_to_local; }
		if (HX_FIELD_EQ(inName,"lime_display_object_local_to_global") ) { return lime_display_object_local_to_global; }
		if (HX_FIELD_EQ(inName,"lime_display_object_set_scale9_grid") ) { return lime_display_object_set_scale9_grid; }
		if (HX_FIELD_EQ(inName,"lime_display_object_set_scroll_rect") ) { return lime_display_object_set_scroll_rect; }
		break;
	case 36:
		if (HX_FIELD_EQ(inName,"lime_display_object_get_pixel_bounds") ) { return lime_display_object_get_pixel_bounds; }
		break;
	case 38:
		if (HX_FIELD_EQ(inName,"lime_display_object_get_pixel_snapping") ) { return lime_display_object_get_pixel_snapping; }
		if (HX_FIELD_EQ(inName,"lime_display_object_set_pixel_snapping") ) { return lime_display_object_set_pixel_snapping; }
		break;
	case 39:
		if (HX_FIELD_EQ(inName,"lime_display_object_get_cache_as_bitmap") ) { return lime_display_object_get_cache_as_bitmap; }
		if (HX_FIELD_EQ(inName,"lime_display_object_set_cache_as_bitmap") ) { return lime_display_object_set_cache_as_bitmap; }
		if (HX_FIELD_EQ(inName,"lime_display_object_get_color_transform") ) { return lime_display_object_get_color_transform; }
		if (HX_FIELD_EQ(inName,"lime_display_object_set_color_transform") ) { return lime_display_object_set_color_transform; }
		break;
	case 47:
		if (HX_FIELD_EQ(inName,"lime_display_object_get_pedantic_bitmap_caching") ) { return lime_display_object_get_pedantic_bitmap_caching; }
		if (HX_FIELD_EQ(inName,"lime_display_object_set_pedantic_bitmap_caching") ) { return lime_display_object_set_pedantic_bitmap_caching; }
	}
	return super::__Field(inName,inCallProp);
}

Dynamic DisplayObject_obj::__SetField(const ::String &inName,const Dynamic &inValue,bool inCallProp)
{
	switch(inName.length) {
	case 1:
		if (HX_FIELD_EQ(inName,"x") ) { return set_x(inValue); }
		if (HX_FIELD_EQ(inName,"y") ) { return set_y(inValue); }
		break;
	case 4:
		if (HX_FIELD_EQ(inName,"mask") ) { if (inCallProp) return set_mask(inValue);mask=inValue.Cast< ::flash::display::DisplayObject >(); return inValue; }
		if (HX_FIELD_EQ(inName,"name") ) { return set_name(inValue); }
		if (HX_FIELD_EQ(inName,"__id") ) { __id=inValue.Cast< int >(); return inValue; }
		break;
	case 5:
		if (HX_FIELD_EQ(inName,"alpha") ) { return set_alpha(inValue); }
		if (HX_FIELD_EQ(inName,"stage") ) { stage=inValue.Cast< ::flash::display::Stage >(); return inValue; }
		if (HX_FIELD_EQ(inName,"width") ) { return set_width(inValue); }
		break;
	case 6:
		if (HX_FIELD_EQ(inName,"height") ) { return set_height(inValue); }
		if (HX_FIELD_EQ(inName,"mouseX") ) { mouseX=inValue.Cast< Float >(); return inValue; }
		if (HX_FIELD_EQ(inName,"mouseY") ) { mouseY=inValue.Cast< Float >(); return inValue; }
		if (HX_FIELD_EQ(inName,"parent") ) { parent=inValue.Cast< ::flash::display::DisplayObjectContainer >(); return inValue; }
		if (HX_FIELD_EQ(inName,"scaleX") ) { return set_scaleX(inValue); }
		if (HX_FIELD_EQ(inName,"scaleY") ) { return set_scaleY(inValue); }
		break;
	case 7:
		if (HX_FIELD_EQ(inName,"filters") ) { return set_filters(inValue); }
		if (HX_FIELD_EQ(inName,"visible") ) { return set_visible(inValue); }
		break;
	case 8:
		if (HX_FIELD_EQ(inName,"graphics") ) { graphics=inValue.Cast< ::flash::display::Graphics >(); return inValue; }
		if (HX_FIELD_EQ(inName,"rotation") ) { return set_rotation(inValue); }
		if (HX_FIELD_EQ(inName,"__handle") ) { __handle=inValue.Cast< Dynamic >(); return inValue; }
		if (HX_FIELD_EQ(inName,"__parent") ) { __parent=inValue.Cast< ::flash::display::DisplayObjectContainer >(); return inValue; }
		break;
	case 9:
		if (HX_FIELD_EQ(inName,"blendMode") ) { return set_blendMode(inValue); }
		if (HX_FIELD_EQ(inName,"transform") ) { return set_transform(inValue); }
		if (HX_FIELD_EQ(inName,"__filters") ) { __filters=inValue.Cast< Dynamic >(); return inValue; }
		break;
	case 10:
		if (HX_FIELD_EQ(inName,"loaderInfo") ) { loaderInfo=inValue.Cast< ::flash::display::LoaderInfo >(); return inValue; }
		if (HX_FIELD_EQ(inName,"scale9Grid") ) { return set_scale9Grid(inValue); }
		if (HX_FIELD_EQ(inName,"scrollRect") ) { return set_scrollRect(inValue); }
		break;
	case 12:
		if (HX_FIELD_EQ(inName,"__scale9Grid") ) { __scale9Grid=inValue.Cast< ::flash::geom::Rectangle >(); return inValue; }
		if (HX_FIELD_EQ(inName,"__scrollRect") ) { __scrollRect=inValue.Cast< ::flash::geom::Rectangle >(); return inValue; }
		break;
	case 13:
		if (HX_FIELD_EQ(inName,"cacheAsBitmap") ) { return set_cacheAsBitmap(inValue); }
		if (HX_FIELD_EQ(inName,"pixelSnapping") ) { return set_pixelSnapping(inValue); }
		break;
	case 15:
		if (HX_FIELD_EQ(inName,"__graphicsCache") ) { __graphicsCache=inValue.Cast< ::flash::display::Graphics >(); return inValue; }
		break;
	case 16:
		if (HX_FIELD_EQ(inName,"opaqueBackground") ) { return set_opaqueBackground(inValue); }
		break;
	case 21:
		if (HX_FIELD_EQ(inName,"pedanticBitmapCaching") ) { return set_pedanticBitmapCaching(inValue); }
		break;
	case 25:
		if (HX_FIELD_EQ(inName,"lime_display_object_get_x") ) { lime_display_object_get_x=inValue.Cast< Dynamic >(); return inValue; }
		if (HX_FIELD_EQ(inName,"lime_display_object_set_x") ) { lime_display_object_set_x=inValue.Cast< Dynamic >(); return inValue; }
		if (HX_FIELD_EQ(inName,"lime_display_object_get_y") ) { lime_display_object_get_y=inValue.Cast< Dynamic >(); return inValue; }
		if (HX_FIELD_EQ(inName,"lime_display_object_set_y") ) { lime_display_object_set_y=inValue.Cast< Dynamic >(); return inValue; }
		break;
	case 26:
		if (HX_FIELD_EQ(inName,"lime_create_display_object") ) { lime_create_display_object=inValue.Cast< Dynamic >(); return inValue; }
		if (HX_FIELD_EQ(inName,"lime_display_object_get_id") ) { lime_display_object_get_id=inValue.Cast< Dynamic >(); return inValue; }
		if (HX_FIELD_EQ(inName,"lime_display_object_get_bg") ) { lime_display_object_get_bg=inValue.Cast< Dynamic >(); return inValue; }
		if (HX_FIELD_EQ(inName,"lime_display_object_set_bg") ) { lime_display_object_set_bg=inValue.Cast< Dynamic >(); return inValue; }
		break;
	case 28:
		if (HX_FIELD_EQ(inName,"lime_display_object_get_name") ) { lime_display_object_get_name=inValue.Cast< Dynamic >(); return inValue; }
		if (HX_FIELD_EQ(inName,"lime_display_object_set_name") ) { lime_display_object_set_name=inValue.Cast< Dynamic >(); return inValue; }
		if (HX_FIELD_EQ(inName,"lime_display_object_set_mask") ) { lime_display_object_set_mask=inValue.Cast< Dynamic >(); return inValue; }
		break;
	case 29:
		if (HX_FIELD_EQ(inName,"lime_display_object_get_width") ) { lime_display_object_get_width=inValue.Cast< Dynamic >(); return inValue; }
		if (HX_FIELD_EQ(inName,"lime_display_object_set_width") ) { lime_display_object_set_width=inValue.Cast< Dynamic >(); return inValue; }
		if (HX_FIELD_EQ(inName,"lime_display_object_get_alpha") ) { lime_display_object_get_alpha=inValue.Cast< Dynamic >(); return inValue; }
		if (HX_FIELD_EQ(inName,"lime_display_object_set_alpha") ) { lime_display_object_set_alpha=inValue.Cast< Dynamic >(); return inValue; }
		break;
	case 30:
		if (HX_FIELD_EQ(inName,"lime_display_object_get_height") ) { lime_display_object_get_height=inValue.Cast< Dynamic >(); return inValue; }
		if (HX_FIELD_EQ(inName,"lime_display_object_set_height") ) { lime_display_object_set_height=inValue.Cast< Dynamic >(); return inValue; }
		if (HX_FIELD_EQ(inName,"lime_display_object_set_matrix") ) { lime_display_object_set_matrix=inValue.Cast< Dynamic >(); return inValue; }
		if (HX_FIELD_EQ(inName,"lime_display_object_get_matrix") ) { lime_display_object_get_matrix=inValue.Cast< Dynamic >(); return inValue; }
		if (HX_FIELD_EQ(inName,"lime_display_object_get_bounds") ) { lime_display_object_get_bounds=inValue.Cast< Dynamic >(); return inValue; }
		break;
	case 31:
		if (HX_FIELD_EQ(inName,"lime_display_object_get_scale_x") ) { lime_display_object_get_scale_x=inValue.Cast< Dynamic >(); return inValue; }
		if (HX_FIELD_EQ(inName,"lime_display_object_set_scale_x") ) { lime_display_object_set_scale_x=inValue.Cast< Dynamic >(); return inValue; }
		if (HX_FIELD_EQ(inName,"lime_display_object_get_scale_y") ) { lime_display_object_get_scale_y=inValue.Cast< Dynamic >(); return inValue; }
		if (HX_FIELD_EQ(inName,"lime_display_object_set_scale_y") ) { lime_display_object_set_scale_y=inValue.Cast< Dynamic >(); return inValue; }
		if (HX_FIELD_EQ(inName,"lime_display_object_get_mouse_x") ) { lime_display_object_get_mouse_x=inValue.Cast< Dynamic >(); return inValue; }
		if (HX_FIELD_EQ(inName,"lime_display_object_get_mouse_y") ) { lime_display_object_get_mouse_y=inValue.Cast< Dynamic >(); return inValue; }
		if (HX_FIELD_EQ(inName,"lime_display_object_get_visible") ) { lime_display_object_get_visible=inValue.Cast< Dynamic >(); return inValue; }
		if (HX_FIELD_EQ(inName,"lime_display_object_set_visible") ) { lime_display_object_set_visible=inValue.Cast< Dynamic >(); return inValue; }
		if (HX_FIELD_EQ(inName,"lime_display_object_set_filters") ) { lime_display_object_set_filters=inValue.Cast< Dynamic >(); return inValue; }
		break;
	case 32:
		if (HX_FIELD_EQ(inName,"lime_display_object_get_graphics") ) { lime_display_object_get_graphics=inValue.Cast< Dynamic >(); return inValue; }
		if (HX_FIELD_EQ(inName,"lime_display_object_get_rotation") ) { lime_display_object_get_rotation=inValue.Cast< Dynamic >(); return inValue; }
		if (HX_FIELD_EQ(inName,"lime_display_object_set_rotation") ) { lime_display_object_set_rotation=inValue.Cast< Dynamic >(); return inValue; }
		break;
	case 34:
		if (HX_FIELD_EQ(inName,"lime_display_object_get_blend_mode") ) { lime_display_object_get_blend_mode=inValue.Cast< Dynamic >(); return inValue; }
		if (HX_FIELD_EQ(inName,"lime_display_object_set_blend_mode") ) { lime_display_object_set_blend_mode=inValue.Cast< Dynamic >(); return inValue; }
		if (HX_FIELD_EQ(inName,"lime_display_object_hit_test_point") ) { lime_display_object_hit_test_point=inValue.Cast< Dynamic >(); return inValue; }
		break;
	case 35:
		if (HX_FIELD_EQ(inName,"lime_display_object_draw_to_surface") ) { lime_display_object_draw_to_surface=inValue.Cast< Dynamic >(); return inValue; }
		if (HX_FIELD_EQ(inName,"lime_display_object_global_to_local") ) { lime_display_object_global_to_local=inValue.Cast< Dynamic >(); return inValue; }
		if (HX_FIELD_EQ(inName,"lime_display_object_local_to_global") ) { lime_display_object_local_to_global=inValue.Cast< Dynamic >(); return inValue; }
		if (HX_FIELD_EQ(inName,"lime_display_object_set_scale9_grid") ) { lime_display_object_set_scale9_grid=inValue.Cast< Dynamic >(); return inValue; }
		if (HX_FIELD_EQ(inName,"lime_display_object_set_scroll_rect") ) { lime_display_object_set_scroll_rect=inValue.Cast< Dynamic >(); return inValue; }
		break;
	case 36:
		if (HX_FIELD_EQ(inName,"lime_display_object_get_pixel_bounds") ) { lime_display_object_get_pixel_bounds=inValue.Cast< Dynamic >(); return inValue; }
		break;
	case 38:
		if (HX_FIELD_EQ(inName,"lime_display_object_get_pixel_snapping") ) { lime_display_object_get_pixel_snapping=inValue.Cast< Dynamic >(); return inValue; }
		if (HX_FIELD_EQ(inName,"lime_display_object_set_pixel_snapping") ) { lime_display_object_set_pixel_snapping=inValue.Cast< Dynamic >(); return inValue; }
		break;
	case 39:
		if (HX_FIELD_EQ(inName,"lime_display_object_get_cache_as_bitmap") ) { lime_display_object_get_cache_as_bitmap=inValue.Cast< Dynamic >(); return inValue; }
		if (HX_FIELD_EQ(inName,"lime_display_object_set_cache_as_bitmap") ) { lime_display_object_set_cache_as_bitmap=inValue.Cast< Dynamic >(); return inValue; }
		if (HX_FIELD_EQ(inName,"lime_display_object_get_color_transform") ) { lime_display_object_get_color_transform=inValue.Cast< Dynamic >(); return inValue; }
		if (HX_FIELD_EQ(inName,"lime_display_object_set_color_transform") ) { lime_display_object_set_color_transform=inValue.Cast< Dynamic >(); return inValue; }
		break;
	case 47:
		if (HX_FIELD_EQ(inName,"lime_display_object_get_pedantic_bitmap_caching") ) { lime_display_object_get_pedantic_bitmap_caching=inValue.Cast< Dynamic >(); return inValue; }
		if (HX_FIELD_EQ(inName,"lime_display_object_set_pedantic_bitmap_caching") ) { lime_display_object_set_pedantic_bitmap_caching=inValue.Cast< Dynamic >(); return inValue; }
	}
	return super::__SetField(inName,inValue,inCallProp);
}

void DisplayObject_obj::__GetFields(Array< ::String> &outFields)
{
	outFields->push(HX_CSTRING("alpha"));
	outFields->push(HX_CSTRING("blendMode"));
	outFields->push(HX_CSTRING("cacheAsBitmap"));
	outFields->push(HX_CSTRING("filters"));
	outFields->push(HX_CSTRING("graphics"));
	outFields->push(HX_CSTRING("height"));
	outFields->push(HX_CSTRING("loaderInfo"));
	outFields->push(HX_CSTRING("mask"));
	outFields->push(HX_CSTRING("mouseX"));
	outFields->push(HX_CSTRING("mouseY"));
	outFields->push(HX_CSTRING("name"));
	outFields->push(HX_CSTRING("opaqueBackground"));
	outFields->push(HX_CSTRING("parent"));
	outFields->push(HX_CSTRING("pedanticBitmapCaching"));
	outFields->push(HX_CSTRING("pixelSnapping"));
	outFields->push(HX_CSTRING("rotation"));
	outFields->push(HX_CSTRING("scale9Grid"));
	outFields->push(HX_CSTRING("scaleX"));
	outFields->push(HX_CSTRING("scaleY"));
	outFields->push(HX_CSTRING("scrollRect"));
	outFields->push(HX_CSTRING("stage"));
	outFields->push(HX_CSTRING("transform"));
	outFields->push(HX_CSTRING("visible"));
	outFields->push(HX_CSTRING("width"));
	outFields->push(HX_CSTRING("x"));
	outFields->push(HX_CSTRING("y"));
	outFields->push(HX_CSTRING("__handle"));
	outFields->push(HX_CSTRING("__filters"));
	outFields->push(HX_CSTRING("__graphicsCache"));
	outFields->push(HX_CSTRING("__id"));
	outFields->push(HX_CSTRING("__parent"));
	outFields->push(HX_CSTRING("__scale9Grid"));
	outFields->push(HX_CSTRING("__scrollRect"));
	super::__GetFields(outFields);
};

static ::String sStaticFields[] = {
	HX_CSTRING("lime_create_display_object"),
	HX_CSTRING("lime_display_object_get_graphics"),
	HX_CSTRING("lime_display_object_draw_to_surface"),
	HX_CSTRING("lime_display_object_get_id"),
	HX_CSTRING("lime_display_object_get_x"),
	HX_CSTRING("lime_display_object_set_x"),
	HX_CSTRING("lime_display_object_get_y"),
	HX_CSTRING("lime_display_object_set_y"),
	HX_CSTRING("lime_display_object_get_scale_x"),
	HX_CSTRING("lime_display_object_set_scale_x"),
	HX_CSTRING("lime_display_object_get_scale_y"),
	HX_CSTRING("lime_display_object_set_scale_y"),
	HX_CSTRING("lime_display_object_get_mouse_x"),
	HX_CSTRING("lime_display_object_get_mouse_y"),
	HX_CSTRING("lime_display_object_get_rotation"),
	HX_CSTRING("lime_display_object_set_rotation"),
	HX_CSTRING("lime_display_object_get_bg"),
	HX_CSTRING("lime_display_object_set_bg"),
	HX_CSTRING("lime_display_object_get_name"),
	HX_CSTRING("lime_display_object_set_name"),
	HX_CSTRING("lime_display_object_get_width"),
	HX_CSTRING("lime_display_object_set_width"),
	HX_CSTRING("lime_display_object_get_height"),
	HX_CSTRING("lime_display_object_set_height"),
	HX_CSTRING("lime_display_object_get_alpha"),
	HX_CSTRING("lime_display_object_set_alpha"),
	HX_CSTRING("lime_display_object_get_blend_mode"),
	HX_CSTRING("lime_display_object_set_blend_mode"),
	HX_CSTRING("lime_display_object_get_cache_as_bitmap"),
	HX_CSTRING("lime_display_object_set_cache_as_bitmap"),
	HX_CSTRING("lime_display_object_get_pedantic_bitmap_caching"),
	HX_CSTRING("lime_display_object_set_pedantic_bitmap_caching"),
	HX_CSTRING("lime_display_object_get_pixel_snapping"),
	HX_CSTRING("lime_display_object_set_pixel_snapping"),
	HX_CSTRING("lime_display_object_get_visible"),
	HX_CSTRING("lime_display_object_set_visible"),
	HX_CSTRING("lime_display_object_set_filters"),
	HX_CSTRING("lime_display_object_global_to_local"),
	HX_CSTRING("lime_display_object_local_to_global"),
	HX_CSTRING("lime_display_object_set_scale9_grid"),
	HX_CSTRING("lime_display_object_set_scroll_rect"),
	HX_CSTRING("lime_display_object_set_mask"),
	HX_CSTRING("lime_display_object_set_matrix"),
	HX_CSTRING("lime_display_object_get_matrix"),
	HX_CSTRING("lime_display_object_get_color_transform"),
	HX_CSTRING("lime_display_object_set_color_transform"),
	HX_CSTRING("lime_display_object_get_pixel_bounds"),
	HX_CSTRING("lime_display_object_get_bounds"),
	HX_CSTRING("lime_display_object_hit_test_point"),
	String(null()) };

#if HXCPP_SCRIPTABLE
static hx::StorageInfo sMemberStorageInfo[] = {
	{hx::fsObject /*::flash::display::Graphics*/ ,(int)offsetof(DisplayObject_obj,graphics),HX_CSTRING("graphics")},
	{hx::fsObject /*::flash::display::LoaderInfo*/ ,(int)offsetof(DisplayObject_obj,loaderInfo),HX_CSTRING("loaderInfo")},
	{hx::fsObject /*::flash::display::DisplayObject*/ ,(int)offsetof(DisplayObject_obj,mask),HX_CSTRING("mask")},
	{hx::fsFloat,(int)offsetof(DisplayObject_obj,mouseX),HX_CSTRING("mouseX")},
	{hx::fsFloat,(int)offsetof(DisplayObject_obj,mouseY),HX_CSTRING("mouseY")},
	{hx::fsObject /*::flash::display::DisplayObjectContainer*/ ,(int)offsetof(DisplayObject_obj,parent),HX_CSTRING("parent")},
	{hx::fsObject /*::flash::display::Stage*/ ,(int)offsetof(DisplayObject_obj,stage),HX_CSTRING("stage")},
	{hx::fsObject /*Dynamic*/ ,(int)offsetof(DisplayObject_obj,__handle),HX_CSTRING("__handle")},
	{hx::fsObject /*Dynamic*/ ,(int)offsetof(DisplayObject_obj,__filters),HX_CSTRING("__filters")},
	{hx::fsObject /*::flash::display::Graphics*/ ,(int)offsetof(DisplayObject_obj,__graphicsCache),HX_CSTRING("__graphicsCache")},
	{hx::fsInt,(int)offsetof(DisplayObject_obj,__id),HX_CSTRING("__id")},
	{hx::fsObject /*::flash::display::DisplayObjectContainer*/ ,(int)offsetof(DisplayObject_obj,__parent),HX_CSTRING("__parent")},
	{hx::fsObject /*::flash::geom::Rectangle*/ ,(int)offsetof(DisplayObject_obj,__scale9Grid),HX_CSTRING("__scale9Grid")},
	{hx::fsObject /*::flash::geom::Rectangle*/ ,(int)offsetof(DisplayObject_obj,__scrollRect),HX_CSTRING("__scrollRect")},
	{ hx::fsUnknown, 0, null()}
};
#endif

static ::String sMemberFields[] = {
	HX_CSTRING("graphics"),
	HX_CSTRING("loaderInfo"),
	HX_CSTRING("mask"),
	HX_CSTRING("mouseX"),
	HX_CSTRING("mouseY"),
	HX_CSTRING("parent"),
	HX_CSTRING("stage"),
	HX_CSTRING("__handle"),
	HX_CSTRING("__filters"),
	HX_CSTRING("__graphicsCache"),
	HX_CSTRING("__id"),
	HX_CSTRING("__parent"),
	HX_CSTRING("__scale9Grid"),
	HX_CSTRING("__scrollRect"),
	HX_CSTRING("dispatchEvent"),
	HX_CSTRING("getBounds"),
	HX_CSTRING("getRect"),
	HX_CSTRING("globalToLocal"),
	HX_CSTRING("hitTestObject"),
	HX_CSTRING("hitTestPoint"),
	HX_CSTRING("localToGlobal"),
	HX_CSTRING("toString"),
	HX_CSTRING("__asInteractiveObject"),
	HX_CSTRING("__broadcast"),
	HX_CSTRING("__contains"),
	HX_CSTRING("__dispatchEvent"),
	HX_CSTRING("__drawToSurface"),
	HX_CSTRING("__findByID"),
	HX_CSTRING("__fireEvent"),
	HX_CSTRING("__getColorTransform"),
	HX_CSTRING("__getConcatenatedColorTransform"),
	HX_CSTRING("__getConcatenatedMatrix"),
	HX_CSTRING("__getInteractiveObjectStack"),
	HX_CSTRING("__getMatrix"),
	HX_CSTRING("__getObjectsUnderPoint"),
	HX_CSTRING("__getPixelBounds"),
	HX_CSTRING("__onAdded"),
	HX_CSTRING("__onRemoved"),
	HX_CSTRING("__setColorTransform"),
	HX_CSTRING("__setMatrix"),
	HX_CSTRING("__setParent"),
	HX_CSTRING("get_alpha"),
	HX_CSTRING("set_alpha"),
	HX_CSTRING("get_opaqueBackground"),
	HX_CSTRING("set_opaqueBackground"),
	HX_CSTRING("get_blendMode"),
	HX_CSTRING("set_blendMode"),
	HX_CSTRING("get_cacheAsBitmap"),
	HX_CSTRING("set_cacheAsBitmap"),
	HX_CSTRING("get_pedanticBitmapCaching"),
	HX_CSTRING("set_pedanticBitmapCaching"),
	HX_CSTRING("get_pixelSnapping"),
	HX_CSTRING("set_pixelSnapping"),
	HX_CSTRING("get_filters"),
	HX_CSTRING("set_filters"),
	HX_CSTRING("get_graphics"),
	HX_CSTRING("get_height"),
	HX_CSTRING("set_height"),
	HX_CSTRING("set_mask"),
	HX_CSTRING("get_mouseX"),
	HX_CSTRING("get_mouseY"),
	HX_CSTRING("get_name"),
	HX_CSTRING("set_name"),
	HX_CSTRING("get_parent"),
	HX_CSTRING("get_rotation"),
	HX_CSTRING("set_rotation"),
	HX_CSTRING("get_scale9Grid"),
	HX_CSTRING("set_scale9Grid"),
	HX_CSTRING("get_scaleX"),
	HX_CSTRING("set_scaleX"),
	HX_CSTRING("get_scaleY"),
	HX_CSTRING("set_scaleY"),
	HX_CSTRING("get_scrollRect"),
	HX_CSTRING("set_scrollRect"),
	HX_CSTRING("get_stage"),
	HX_CSTRING("get_transform"),
	HX_CSTRING("set_transform"),
	HX_CSTRING("get_visible"),
	HX_CSTRING("set_visible"),
	HX_CSTRING("get_width"),
	HX_CSTRING("set_width"),
	HX_CSTRING("get_x"),
	HX_CSTRING("set_x"),
	HX_CSTRING("get_y"),
	HX_CSTRING("set_y"),
	String(null()) };

static void sMarkStatics(HX_MARK_PARAMS) {
	HX_MARK_MEMBER_NAME(DisplayObject_obj::__mClass,"__mClass");
	HX_MARK_MEMBER_NAME(DisplayObject_obj::lime_create_display_object,"lime_create_display_object");
	HX_MARK_MEMBER_NAME(DisplayObject_obj::lime_display_object_get_graphics,"lime_display_object_get_graphics");
	HX_MARK_MEMBER_NAME(DisplayObject_obj::lime_display_object_draw_to_surface,"lime_display_object_draw_to_surface");
	HX_MARK_MEMBER_NAME(DisplayObject_obj::lime_display_object_get_id,"lime_display_object_get_id");
	HX_MARK_MEMBER_NAME(DisplayObject_obj::lime_display_object_get_x,"lime_display_object_get_x");
	HX_MARK_MEMBER_NAME(DisplayObject_obj::lime_display_object_set_x,"lime_display_object_set_x");
	HX_MARK_MEMBER_NAME(DisplayObject_obj::lime_display_object_get_y,"lime_display_object_get_y");
	HX_MARK_MEMBER_NAME(DisplayObject_obj::lime_display_object_set_y,"lime_display_object_set_y");
	HX_MARK_MEMBER_NAME(DisplayObject_obj::lime_display_object_get_scale_x,"lime_display_object_get_scale_x");
	HX_MARK_MEMBER_NAME(DisplayObject_obj::lime_display_object_set_scale_x,"lime_display_object_set_scale_x");
	HX_MARK_MEMBER_NAME(DisplayObject_obj::lime_display_object_get_scale_y,"lime_display_object_get_scale_y");
	HX_MARK_MEMBER_NAME(DisplayObject_obj::lime_display_object_set_scale_y,"lime_display_object_set_scale_y");
	HX_MARK_MEMBER_NAME(DisplayObject_obj::lime_display_object_get_mouse_x,"lime_display_object_get_mouse_x");
	HX_MARK_MEMBER_NAME(DisplayObject_obj::lime_display_object_get_mouse_y,"lime_display_object_get_mouse_y");
	HX_MARK_MEMBER_NAME(DisplayObject_obj::lime_display_object_get_rotation,"lime_display_object_get_rotation");
	HX_MARK_MEMBER_NAME(DisplayObject_obj::lime_display_object_set_rotation,"lime_display_object_set_rotation");
	HX_MARK_MEMBER_NAME(DisplayObject_obj::lime_display_object_get_bg,"lime_display_object_get_bg");
	HX_MARK_MEMBER_NAME(DisplayObject_obj::lime_display_object_set_bg,"lime_display_object_set_bg");
	HX_MARK_MEMBER_NAME(DisplayObject_obj::lime_display_object_get_name,"lime_display_object_get_name");
	HX_MARK_MEMBER_NAME(DisplayObject_obj::lime_display_object_set_name,"lime_display_object_set_name");
	HX_MARK_MEMBER_NAME(DisplayObject_obj::lime_display_object_get_width,"lime_display_object_get_width");
	HX_MARK_MEMBER_NAME(DisplayObject_obj::lime_display_object_set_width,"lime_display_object_set_width");
	HX_MARK_MEMBER_NAME(DisplayObject_obj::lime_display_object_get_height,"lime_display_object_get_height");
	HX_MARK_MEMBER_NAME(DisplayObject_obj::lime_display_object_set_height,"lime_display_object_set_height");
	HX_MARK_MEMBER_NAME(DisplayObject_obj::lime_display_object_get_alpha,"lime_display_object_get_alpha");
	HX_MARK_MEMBER_NAME(DisplayObject_obj::lime_display_object_set_alpha,"lime_display_object_set_alpha");
	HX_MARK_MEMBER_NAME(DisplayObject_obj::lime_display_object_get_blend_mode,"lime_display_object_get_blend_mode");
	HX_MARK_MEMBER_NAME(DisplayObject_obj::lime_display_object_set_blend_mode,"lime_display_object_set_blend_mode");
	HX_MARK_MEMBER_NAME(DisplayObject_obj::lime_display_object_get_cache_as_bitmap,"lime_display_object_get_cache_as_bitmap");
	HX_MARK_MEMBER_NAME(DisplayObject_obj::lime_display_object_set_cache_as_bitmap,"lime_display_object_set_cache_as_bitmap");
	HX_MARK_MEMBER_NAME(DisplayObject_obj::lime_display_object_get_pedantic_bitmap_caching,"lime_display_object_get_pedantic_bitmap_caching");
	HX_MARK_MEMBER_NAME(DisplayObject_obj::lime_display_object_set_pedantic_bitmap_caching,"lime_display_object_set_pedantic_bitmap_caching");
	HX_MARK_MEMBER_NAME(DisplayObject_obj::lime_display_object_get_pixel_snapping,"lime_display_object_get_pixel_snapping");
	HX_MARK_MEMBER_NAME(DisplayObject_obj::lime_display_object_set_pixel_snapping,"lime_display_object_set_pixel_snapping");
	HX_MARK_MEMBER_NAME(DisplayObject_obj::lime_display_object_get_visible,"lime_display_object_get_visible");
	HX_MARK_MEMBER_NAME(DisplayObject_obj::lime_display_object_set_visible,"lime_display_object_set_visible");
	HX_MARK_MEMBER_NAME(DisplayObject_obj::lime_display_object_set_filters,"lime_display_object_set_filters");
	HX_MARK_MEMBER_NAME(DisplayObject_obj::lime_display_object_global_to_local,"lime_display_object_global_to_local");
	HX_MARK_MEMBER_NAME(DisplayObject_obj::lime_display_object_local_to_global,"lime_display_object_local_to_global");
	HX_MARK_MEMBER_NAME(DisplayObject_obj::lime_display_object_set_scale9_grid,"lime_display_object_set_scale9_grid");
	HX_MARK_MEMBER_NAME(DisplayObject_obj::lime_display_object_set_scroll_rect,"lime_display_object_set_scroll_rect");
	HX_MARK_MEMBER_NAME(DisplayObject_obj::lime_display_object_set_mask,"lime_display_object_set_mask");
	HX_MARK_MEMBER_NAME(DisplayObject_obj::lime_display_object_set_matrix,"lime_display_object_set_matrix");
	HX_MARK_MEMBER_NAME(DisplayObject_obj::lime_display_object_get_matrix,"lime_display_object_get_matrix");
	HX_MARK_MEMBER_NAME(DisplayObject_obj::lime_display_object_get_color_transform,"lime_display_object_get_color_transform");
	HX_MARK_MEMBER_NAME(DisplayObject_obj::lime_display_object_set_color_transform,"lime_display_object_set_color_transform");
	HX_MARK_MEMBER_NAME(DisplayObject_obj::lime_display_object_get_pixel_bounds,"lime_display_object_get_pixel_bounds");
	HX_MARK_MEMBER_NAME(DisplayObject_obj::lime_display_object_get_bounds,"lime_display_object_get_bounds");
	HX_MARK_MEMBER_NAME(DisplayObject_obj::lime_display_object_hit_test_point,"lime_display_object_hit_test_point");
};

#ifdef HXCPP_VISIT_ALLOCS
static void sVisitStatics(HX_VISIT_PARAMS) {
	HX_VISIT_MEMBER_NAME(DisplayObject_obj::__mClass,"__mClass");
	HX_VISIT_MEMBER_NAME(DisplayObject_obj::lime_create_display_object,"lime_create_display_object");
	HX_VISIT_MEMBER_NAME(DisplayObject_obj::lime_display_object_get_graphics,"lime_display_object_get_graphics");
	HX_VISIT_MEMBER_NAME(DisplayObject_obj::lime_display_object_draw_to_surface,"lime_display_object_draw_to_surface");
	HX_VISIT_MEMBER_NAME(DisplayObject_obj::lime_display_object_get_id,"lime_display_object_get_id");
	HX_VISIT_MEMBER_NAME(DisplayObject_obj::lime_display_object_get_x,"lime_display_object_get_x");
	HX_VISIT_MEMBER_NAME(DisplayObject_obj::lime_display_object_set_x,"lime_display_object_set_x");
	HX_VISIT_MEMBER_NAME(DisplayObject_obj::lime_display_object_get_y,"lime_display_object_get_y");
	HX_VISIT_MEMBER_NAME(DisplayObject_obj::lime_display_object_set_y,"lime_display_object_set_y");
	HX_VISIT_MEMBER_NAME(DisplayObject_obj::lime_display_object_get_scale_x,"lime_display_object_get_scale_x");
	HX_VISIT_MEMBER_NAME(DisplayObject_obj::lime_display_object_set_scale_x,"lime_display_object_set_scale_x");
	HX_VISIT_MEMBER_NAME(DisplayObject_obj::lime_display_object_get_scale_y,"lime_display_object_get_scale_y");
	HX_VISIT_MEMBER_NAME(DisplayObject_obj::lime_display_object_set_scale_y,"lime_display_object_set_scale_y");
	HX_VISIT_MEMBER_NAME(DisplayObject_obj::lime_display_object_get_mouse_x,"lime_display_object_get_mouse_x");
	HX_VISIT_MEMBER_NAME(DisplayObject_obj::lime_display_object_get_mouse_y,"lime_display_object_get_mouse_y");
	HX_VISIT_MEMBER_NAME(DisplayObject_obj::lime_display_object_get_rotation,"lime_display_object_get_rotation");
	HX_VISIT_MEMBER_NAME(DisplayObject_obj::lime_display_object_set_rotation,"lime_display_object_set_rotation");
	HX_VISIT_MEMBER_NAME(DisplayObject_obj::lime_display_object_get_bg,"lime_display_object_get_bg");
	HX_VISIT_MEMBER_NAME(DisplayObject_obj::lime_display_object_set_bg,"lime_display_object_set_bg");
	HX_VISIT_MEMBER_NAME(DisplayObject_obj::lime_display_object_get_name,"lime_display_object_get_name");
	HX_VISIT_MEMBER_NAME(DisplayObject_obj::lime_display_object_set_name,"lime_display_object_set_name");
	HX_VISIT_MEMBER_NAME(DisplayObject_obj::lime_display_object_get_width,"lime_display_object_get_width");
	HX_VISIT_MEMBER_NAME(DisplayObject_obj::lime_display_object_set_width,"lime_display_object_set_width");
	HX_VISIT_MEMBER_NAME(DisplayObject_obj::lime_display_object_get_height,"lime_display_object_get_height");
	HX_VISIT_MEMBER_NAME(DisplayObject_obj::lime_display_object_set_height,"lime_display_object_set_height");
	HX_VISIT_MEMBER_NAME(DisplayObject_obj::lime_display_object_get_alpha,"lime_display_object_get_alpha");
	HX_VISIT_MEMBER_NAME(DisplayObject_obj::lime_display_object_set_alpha,"lime_display_object_set_alpha");
	HX_VISIT_MEMBER_NAME(DisplayObject_obj::lime_display_object_get_blend_mode,"lime_display_object_get_blend_mode");
	HX_VISIT_MEMBER_NAME(DisplayObject_obj::lime_display_object_set_blend_mode,"lime_display_object_set_blend_mode");
	HX_VISIT_MEMBER_NAME(DisplayObject_obj::lime_display_object_get_cache_as_bitmap,"lime_display_object_get_cache_as_bitmap");
	HX_VISIT_MEMBER_NAME(DisplayObject_obj::lime_display_object_set_cache_as_bitmap,"lime_display_object_set_cache_as_bitmap");
	HX_VISIT_MEMBER_NAME(DisplayObject_obj::lime_display_object_get_pedantic_bitmap_caching,"lime_display_object_get_pedantic_bitmap_caching");
	HX_VISIT_MEMBER_NAME(DisplayObject_obj::lime_display_object_set_pedantic_bitmap_caching,"lime_display_object_set_pedantic_bitmap_caching");
	HX_VISIT_MEMBER_NAME(DisplayObject_obj::lime_display_object_get_pixel_snapping,"lime_display_object_get_pixel_snapping");
	HX_VISIT_MEMBER_NAME(DisplayObject_obj::lime_display_object_set_pixel_snapping,"lime_display_object_set_pixel_snapping");
	HX_VISIT_MEMBER_NAME(DisplayObject_obj::lime_display_object_get_visible,"lime_display_object_get_visible");
	HX_VISIT_MEMBER_NAME(DisplayObject_obj::lime_display_object_set_visible,"lime_display_object_set_visible");
	HX_VISIT_MEMBER_NAME(DisplayObject_obj::lime_display_object_set_filters,"lime_display_object_set_filters");
	HX_VISIT_MEMBER_NAME(DisplayObject_obj::lime_display_object_global_to_local,"lime_display_object_global_to_local");
	HX_VISIT_MEMBER_NAME(DisplayObject_obj::lime_display_object_local_to_global,"lime_display_object_local_to_global");
	HX_VISIT_MEMBER_NAME(DisplayObject_obj::lime_display_object_set_scale9_grid,"lime_display_object_set_scale9_grid");
	HX_VISIT_MEMBER_NAME(DisplayObject_obj::lime_display_object_set_scroll_rect,"lime_display_object_set_scroll_rect");
	HX_VISIT_MEMBER_NAME(DisplayObject_obj::lime_display_object_set_mask,"lime_display_object_set_mask");
	HX_VISIT_MEMBER_NAME(DisplayObject_obj::lime_display_object_set_matrix,"lime_display_object_set_matrix");
	HX_VISIT_MEMBER_NAME(DisplayObject_obj::lime_display_object_get_matrix,"lime_display_object_get_matrix");
	HX_VISIT_MEMBER_NAME(DisplayObject_obj::lime_display_object_get_color_transform,"lime_display_object_get_color_transform");
	HX_VISIT_MEMBER_NAME(DisplayObject_obj::lime_display_object_set_color_transform,"lime_display_object_set_color_transform");
	HX_VISIT_MEMBER_NAME(DisplayObject_obj::lime_display_object_get_pixel_bounds,"lime_display_object_get_pixel_bounds");
	HX_VISIT_MEMBER_NAME(DisplayObject_obj::lime_display_object_get_bounds,"lime_display_object_get_bounds");
	HX_VISIT_MEMBER_NAME(DisplayObject_obj::lime_display_object_hit_test_point,"lime_display_object_hit_test_point");
};

#endif

Class DisplayObject_obj::__mClass;

void DisplayObject_obj::__register()
{
	hx::Static(__mClass) = hx::RegisterClass(HX_CSTRING("flash.display.DisplayObject"), hx::TCanCast< DisplayObject_obj> ,sStaticFields,sMemberFields,
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

void DisplayObject_obj::__boot()
{
	lime_create_display_object= ::flash::Lib_obj::load(HX_CSTRING("lime"),HX_CSTRING("lime_create_display_object"),(int)0);
	lime_display_object_get_graphics= ::flash::Lib_obj::load(HX_CSTRING("lime"),HX_CSTRING("lime_display_object_get_graphics"),(int)1);
	lime_display_object_draw_to_surface= ::flash::Lib_obj::load(HX_CSTRING("lime"),HX_CSTRING("lime_display_object_draw_to_surface"),(int)-1);
	lime_display_object_get_id= ::flash::Lib_obj::load(HX_CSTRING("lime"),HX_CSTRING("lime_display_object_get_id"),(int)1);
	lime_display_object_get_x= ::flash::Lib_obj::load(HX_CSTRING("lime"),HX_CSTRING("lime_display_object_get_x"),(int)1);
	lime_display_object_set_x= ::flash::Lib_obj::load(HX_CSTRING("lime"),HX_CSTRING("lime_display_object_set_x"),(int)2);
	lime_display_object_get_y= ::flash::Lib_obj::load(HX_CSTRING("lime"),HX_CSTRING("lime_display_object_get_y"),(int)1);
	lime_display_object_set_y= ::flash::Lib_obj::load(HX_CSTRING("lime"),HX_CSTRING("lime_display_object_set_y"),(int)2);
	lime_display_object_get_scale_x= ::flash::Lib_obj::load(HX_CSTRING("lime"),HX_CSTRING("lime_display_object_get_scale_x"),(int)1);
	lime_display_object_set_scale_x= ::flash::Lib_obj::load(HX_CSTRING("lime"),HX_CSTRING("lime_display_object_set_scale_x"),(int)2);
	lime_display_object_get_scale_y= ::flash::Lib_obj::load(HX_CSTRING("lime"),HX_CSTRING("lime_display_object_get_scale_y"),(int)1);
	lime_display_object_set_scale_y= ::flash::Lib_obj::load(HX_CSTRING("lime"),HX_CSTRING("lime_display_object_set_scale_y"),(int)2);
	lime_display_object_get_mouse_x= ::flash::Lib_obj::load(HX_CSTRING("lime"),HX_CSTRING("lime_display_object_get_mouse_x"),(int)1);
	lime_display_object_get_mouse_y= ::flash::Lib_obj::load(HX_CSTRING("lime"),HX_CSTRING("lime_display_object_get_mouse_y"),(int)1);
	lime_display_object_get_rotation= ::flash::Lib_obj::load(HX_CSTRING("lime"),HX_CSTRING("lime_display_object_get_rotation"),(int)1);
	lime_display_object_set_rotation= ::flash::Lib_obj::load(HX_CSTRING("lime"),HX_CSTRING("lime_display_object_set_rotation"),(int)2);
	lime_display_object_get_bg= ::flash::Lib_obj::load(HX_CSTRING("lime"),HX_CSTRING("lime_display_object_get_bg"),(int)1);
	lime_display_object_set_bg= ::flash::Lib_obj::load(HX_CSTRING("lime"),HX_CSTRING("lime_display_object_set_bg"),(int)2);
	lime_display_object_get_name= ::flash::Lib_obj::load(HX_CSTRING("lime"),HX_CSTRING("lime_display_object_get_name"),(int)1);
	lime_display_object_set_name= ::flash::Lib_obj::load(HX_CSTRING("lime"),HX_CSTRING("lime_display_object_set_name"),(int)2);
	lime_display_object_get_width= ::flash::Lib_obj::load(HX_CSTRING("lime"),HX_CSTRING("lime_display_object_get_width"),(int)1);
	lime_display_object_set_width= ::flash::Lib_obj::load(HX_CSTRING("lime"),HX_CSTRING("lime_display_object_set_width"),(int)2);
	lime_display_object_get_height= ::flash::Lib_obj::load(HX_CSTRING("lime"),HX_CSTRING("lime_display_object_get_height"),(int)1);
	lime_display_object_set_height= ::flash::Lib_obj::load(HX_CSTRING("lime"),HX_CSTRING("lime_display_object_set_height"),(int)2);
	lime_display_object_get_alpha= ::flash::Lib_obj::load(HX_CSTRING("lime"),HX_CSTRING("lime_display_object_get_alpha"),(int)1);
	lime_display_object_set_alpha= ::flash::Lib_obj::load(HX_CSTRING("lime"),HX_CSTRING("lime_display_object_set_alpha"),(int)2);
	lime_display_object_get_blend_mode= ::flash::Lib_obj::load(HX_CSTRING("lime"),HX_CSTRING("lime_display_object_get_blend_mode"),(int)1);
	lime_display_object_set_blend_mode= ::flash::Lib_obj::load(HX_CSTRING("lime"),HX_CSTRING("lime_display_object_set_blend_mode"),(int)2);
	lime_display_object_get_cache_as_bitmap= ::flash::Lib_obj::load(HX_CSTRING("lime"),HX_CSTRING("lime_display_object_get_cache_as_bitmap"),(int)1);
	lime_display_object_set_cache_as_bitmap= ::flash::Lib_obj::load(HX_CSTRING("lime"),HX_CSTRING("lime_display_object_set_cache_as_bitmap"),(int)2);
	lime_display_object_get_pedantic_bitmap_caching= ::flash::Lib_obj::load(HX_CSTRING("lime"),HX_CSTRING("lime_display_object_get_pedantic_bitmap_caching"),(int)1);
	lime_display_object_set_pedantic_bitmap_caching= ::flash::Lib_obj::load(HX_CSTRING("lime"),HX_CSTRING("lime_display_object_set_pedantic_bitmap_caching"),(int)2);
	lime_display_object_get_pixel_snapping= ::flash::Lib_obj::load(HX_CSTRING("lime"),HX_CSTRING("lime_display_object_get_pixel_snapping"),(int)1);
	lime_display_object_set_pixel_snapping= ::flash::Lib_obj::load(HX_CSTRING("lime"),HX_CSTRING("lime_display_object_set_pixel_snapping"),(int)2);
	lime_display_object_get_visible= ::flash::Lib_obj::load(HX_CSTRING("lime"),HX_CSTRING("lime_display_object_get_visible"),(int)1);
	lime_display_object_set_visible= ::flash::Lib_obj::load(HX_CSTRING("lime"),HX_CSTRING("lime_display_object_set_visible"),(int)2);
	lime_display_object_set_filters= ::flash::Lib_obj::load(HX_CSTRING("lime"),HX_CSTRING("lime_display_object_set_filters"),(int)2);
	lime_display_object_global_to_local= ::flash::Lib_obj::load(HX_CSTRING("lime"),HX_CSTRING("lime_display_object_global_to_local"),(int)2);
	lime_display_object_local_to_global= ::flash::Lib_obj::load(HX_CSTRING("lime"),HX_CSTRING("lime_display_object_local_to_global"),(int)2);
	lime_display_object_set_scale9_grid= ::flash::Lib_obj::load(HX_CSTRING("lime"),HX_CSTRING("lime_display_object_set_scale9_grid"),(int)2);
	lime_display_object_set_scroll_rect= ::flash::Lib_obj::load(HX_CSTRING("lime"),HX_CSTRING("lime_display_object_set_scroll_rect"),(int)2);
	lime_display_object_set_mask= ::flash::Lib_obj::load(HX_CSTRING("lime"),HX_CSTRING("lime_display_object_set_mask"),(int)2);
	lime_display_object_set_matrix= ::flash::Lib_obj::load(HX_CSTRING("lime"),HX_CSTRING("lime_display_object_set_matrix"),(int)2);
	lime_display_object_get_matrix= ::flash::Lib_obj::load(HX_CSTRING("lime"),HX_CSTRING("lime_display_object_get_matrix"),(int)3);
	lime_display_object_get_color_transform= ::flash::Lib_obj::load(HX_CSTRING("lime"),HX_CSTRING("lime_display_object_get_color_transform"),(int)3);
	lime_display_object_set_color_transform= ::flash::Lib_obj::load(HX_CSTRING("lime"),HX_CSTRING("lime_display_object_set_color_transform"),(int)2);
	lime_display_object_get_pixel_bounds= ::flash::Lib_obj::load(HX_CSTRING("lime"),HX_CSTRING("lime_display_object_get_pixel_bounds"),(int)2);
	lime_display_object_get_bounds= ::flash::Lib_obj::load(HX_CSTRING("lime"),HX_CSTRING("lime_display_object_get_bounds"),(int)4);
	lime_display_object_hit_test_point= ::flash::Lib_obj::load(HX_CSTRING("lime"),HX_CSTRING("lime_display_object_hit_test_point"),(int)5);
}

} // end namespace flash
} // end namespace display
