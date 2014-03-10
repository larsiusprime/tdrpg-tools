#include <hxcpp.h>

#ifndef INCLUDED_Std
#include <Std.h>
#endif
#ifndef INCLUDED_flixel_FlxBasic
#include <flixel/FlxBasic.h>
#endif
#ifndef INCLUDED_flixel_FlxObject
#include <flixel/FlxObject.h>
#endif
#ifndef INCLUDED_flixel_FlxSprite
#include <flixel/FlxSprite.h>
#endif
#ifndef INCLUDED_flixel_interfaces_IFlxDestroyable
#include <flixel/interfaces/IFlxDestroyable.h>
#endif
#ifndef INCLUDED_flixel_text_FlxText
#include <flixel/text/FlxText.h>
#endif
#ifndef INCLUDED_flixel_ui_FlxButton
#include <flixel/ui/FlxButton.h>
#endif
#ifndef INCLUDED_flixel_ui_FlxTypedButton
#include <flixel/ui/FlxTypedButton.h>
#endif
#ifndef INCLUDED_flixel_util_FlxPoint
#include <flixel/util/FlxPoint.h>
#endif
namespace flixel{
namespace ui{

Void FlxButton_obj::__construct(hx::Null< Float >  __o_X,hx::Null< Float >  __o_Y,::String Label,Dynamic OnClick)
{
HX_STACK_FRAME("flixel.ui.FlxButton","new",0x776c1d8e,"flixel.ui.FlxButton.new","flixel/ui/FlxButton.hx",34,0xc64cf442)

HX_STACK_ARG(__o_X,"X")

HX_STACK_ARG(__o_Y,"Y")

HX_STACK_ARG(Label,"Label")

HX_STACK_ARG(OnClick,"OnClick")
Float X = __o_X.Default(0);
Float Y = __o_Y.Default(0);
{
	HX_STACK_LINE(35)
	super::__construct(X,Y,Label,OnClick);
	HX_STACK_LINE(37)
	if (((Label != null()))){
		HX_STACK_LINE(39)
		{
			HX_STACK_LINE(39)
			int _g = (int)0;		HX_STACK_VAR(_g,"_g");
			HX_STACK_LINE(39)
			Array< ::Dynamic > _g1 = this->labelOffsets;		HX_STACK_VAR(_g1,"_g1");
			HX_STACK_LINE(39)
			while(((_g < _g1->length))){
				HX_STACK_LINE(39)
				::flixel::util::FlxPoint point = _g1->__get(_g).StaticCast< ::flixel::util::FlxPoint >();		HX_STACK_VAR(point,"point");
				HX_STACK_LINE(39)
				++(_g);
				HX_STACK_LINE(41)
				point->set((point->x - (int)1),(point->y + (int)3));
			}
		}
		HX_STACK_LINE(43)
		this->label = ::flixel::text::FlxText_obj::__new((X + this->labelOffsets->__get((int)0).StaticCast< ::flixel::util::FlxPoint >()->x),(Y + this->labelOffsets->__get((int)0).StaticCast< ::flixel::util::FlxPoint >()->y),(int)80,Label,null(),null());
		HX_STACK_LINE(44)
		this->label->__Field(HX_CSTRING("setFormat"),true)(null(),(int)8,(int)3355443,HX_CSTRING("center"),null(),null(),null());
		HX_STACK_LINE(45)
		this->label->__Field(HX_CSTRING("set_alpha"),true)(this->labelAlphas->__get(this->status));
	}
}
;
	return null();
}

//FlxButton_obj::~FlxButton_obj() { }

Dynamic FlxButton_obj::__CreateEmpty() { return  new FlxButton_obj; }
hx::ObjectPtr< FlxButton_obj > FlxButton_obj::__new(hx::Null< Float >  __o_X,hx::Null< Float >  __o_Y,::String Label,Dynamic OnClick)
{  hx::ObjectPtr< FlxButton_obj > result = new FlxButton_obj();
	result->__construct(__o_X,__o_Y,Label,OnClick);
	return result;}

Dynamic FlxButton_obj::__Create(hx::DynamicArray inArgs)
{  hx::ObjectPtr< FlxButton_obj > result = new FlxButton_obj();
	result->__construct(inArgs[0],inArgs[1],inArgs[2],inArgs[3]);
	return result;}

Void FlxButton_obj::resetHelpers( ){
{
		HX_STACK_FRAME("flixel.ui.FlxButton","resetHelpers",0x0b952648,"flixel.ui.FlxButton.resetHelpers","flixel/ui/FlxButton.hx",53,0xc64cf442)
		HX_STACK_THIS(this)
		HX_STACK_LINE(54)
		this->super::resetHelpers();
		HX_STACK_LINE(56)
		if (((this->label != null()))){
			HX_STACK_LINE(58)
			this->label->__Field(HX_CSTRING("set_width"),true)(this->label->__FieldRef(HX_CSTRING("frameWidth")) = ::Std_obj::_int(this->get_width()));
			HX_STACK_LINE(59)
			this->label->__Field(HX_CSTRING("set_size"),true)(this->label->__Field(HX_CSTRING("get_size"),true)());
		}
	}
return null();
}


int FlxButton_obj::NORMAL;

int FlxButton_obj::HIGHLIGHT;

int FlxButton_obj::PRESSED;


FlxButton_obj::FlxButton_obj()
{
}

Dynamic FlxButton_obj::__Field(const ::String &inName,bool inCallProp)
{
	switch(inName.length) {
	case 12:
		if (HX_FIELD_EQ(inName,"resetHelpers") ) { return resetHelpers_dyn(); }
	}
	return super::__Field(inName,inCallProp);
}

Dynamic FlxButton_obj::__SetField(const ::String &inName,const Dynamic &inValue,bool inCallProp)
{
	return super::__SetField(inName,inValue,inCallProp);
}

void FlxButton_obj::__GetFields(Array< ::String> &outFields)
{
	super::__GetFields(outFields);
};

static ::String sStaticFields[] = {
	HX_CSTRING("NORMAL"),
	HX_CSTRING("HIGHLIGHT"),
	HX_CSTRING("PRESSED"),
	String(null()) };

#if HXCPP_SCRIPTABLE
static hx::StorageInfo *sMemberStorageInfo = 0;
#endif

static ::String sMemberFields[] = {
	HX_CSTRING("resetHelpers"),
	String(null()) };

static void sMarkStatics(HX_MARK_PARAMS) {
	HX_MARK_MEMBER_NAME(FlxButton_obj::__mClass,"__mClass");
	HX_MARK_MEMBER_NAME(FlxButton_obj::NORMAL,"NORMAL");
	HX_MARK_MEMBER_NAME(FlxButton_obj::HIGHLIGHT,"HIGHLIGHT");
	HX_MARK_MEMBER_NAME(FlxButton_obj::PRESSED,"PRESSED");
};

#ifdef HXCPP_VISIT_ALLOCS
static void sVisitStatics(HX_VISIT_PARAMS) {
	HX_VISIT_MEMBER_NAME(FlxButton_obj::__mClass,"__mClass");
	HX_VISIT_MEMBER_NAME(FlxButton_obj::NORMAL,"NORMAL");
	HX_VISIT_MEMBER_NAME(FlxButton_obj::HIGHLIGHT,"HIGHLIGHT");
	HX_VISIT_MEMBER_NAME(FlxButton_obj::PRESSED,"PRESSED");
};

#endif

Class FlxButton_obj::__mClass;

void FlxButton_obj::__register()
{
	hx::Static(__mClass) = hx::RegisterClass(HX_CSTRING("flixel.ui.FlxButton"), hx::TCanCast< FlxButton_obj> ,sStaticFields,sMemberFields,
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

void FlxButton_obj::__boot()
{
	NORMAL= (int)0;
	HIGHLIGHT= (int)1;
	PRESSED= (int)2;
}

} // end namespace flixel
} // end namespace ui
