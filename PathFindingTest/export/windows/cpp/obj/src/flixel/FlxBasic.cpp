#include <hxcpp.h>

#ifndef INCLUDED_flixel_FlxBasic
#include <flixel/FlxBasic.h>
#endif
#ifndef INCLUDED_flixel_FlxCamera
#include <flixel/FlxCamera.h>
#endif
#ifndef INCLUDED_flixel_FlxG
#include <flixel/FlxG.h>
#endif
#ifndef INCLUDED_flixel_interfaces_IFlxDestroyable
#include <flixel/interfaces/IFlxDestroyable.h>
#endif
#ifndef INCLUDED_flixel_system_FlxCollisionType
#include <flixel/system/FlxCollisionType.h>
#endif
#ifndef INCLUDED_flixel_system_frontEnds_CameraFrontEnd
#include <flixel/system/frontEnds/CameraFrontEnd.h>
#endif
#ifndef INCLUDED_flixel_util_FlxStringUtil
#include <flixel/util/FlxStringUtil.h>
#endif
namespace flixel{

Void FlxBasic_obj::__construct()
{
HX_STACK_FRAME("flixel.FlxBasic","new",0x9d630540,"flixel.FlxBasic.new","flixel/FlxBasic.hx",12,0xd8d6cfcf)
{
	HX_STACK_LINE(53)
	this->ignoreDrawDebug = false;
	HX_STACK_LINE(41)
	this->exists = true;
	HX_STACK_LINE(36)
	this->alive = true;
	HX_STACK_LINE(31)
	this->visible = true;
	HX_STACK_LINE(27)
	this->active = true;
	HX_STACK_LINE(18)
	this->ID = (int)-1;
	HX_STACK_LINE(63)
	this->collisionType = ::flixel::system::FlxCollisionType_obj::NONE;
}
;
	return null();
}

//FlxBasic_obj::~FlxBasic_obj() { }

Dynamic FlxBasic_obj::__CreateEmpty() { return  new FlxBasic_obj; }
hx::ObjectPtr< FlxBasic_obj > FlxBasic_obj::__new()
{  hx::ObjectPtr< FlxBasic_obj > result = new FlxBasic_obj();
	result->__construct();
	return result;}

Dynamic FlxBasic_obj::__Create(hx::DynamicArray inArgs)
{  hx::ObjectPtr< FlxBasic_obj > result = new FlxBasic_obj();
	result->__construct();
	return result;}

hx::Object *FlxBasic_obj::__ToInterface(const hx::type_info &inType) {
	if (inType==typeid( ::flixel::interfaces::IFlxDestroyable_obj)) return operator ::flixel::interfaces::IFlxDestroyable_obj *();
	return super::__ToInterface(inType);
}

Void FlxBasic_obj::destroy( ){
{
		HX_STACK_FRAME("flixel.FlxBasic","destroy",0xc50151da,"flixel.FlxBasic.destroy","flixel/FlxBasic.hx",71,0xd8d6cfcf)
		HX_STACK_THIS(this)
		HX_STACK_LINE(72)
		this->set_exists(false);
		HX_STACK_LINE(73)
		this->collisionType = null();
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC0(FlxBasic_obj,destroy,(void))

Void FlxBasic_obj::kill( ){
{
		HX_STACK_FRAME("flixel.FlxBasic","kill",0x1748eebe,"flixel.FlxBasic.kill","flixel/FlxBasic.hx",81,0xd8d6cfcf)
		HX_STACK_THIS(this)
		HX_STACK_LINE(82)
		this->set_alive(false);
		HX_STACK_LINE(83)
		this->set_exists(false);
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC0(FlxBasic_obj,kill,(void))

Void FlxBasic_obj::revive( ){
{
		HX_STACK_FRAME("flixel.FlxBasic","revive",0xb3f01175,"flixel.FlxBasic.revive","flixel/FlxBasic.hx",91,0xd8d6cfcf)
		HX_STACK_THIS(this)
		HX_STACK_LINE(92)
		this->set_alive(true);
		HX_STACK_LINE(93)
		this->set_exists(true);
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC0(FlxBasic_obj,revive,(void))

Void FlxBasic_obj::update( ){
{
		HX_STACK_FRAME("flixel.FlxBasic","update",0x307e9d29,"flixel.FlxBasic.update","flixel/FlxBasic.hx",103,0xd8d6cfcf)
		HX_STACK_THIS(this)
		HX_STACK_LINE(103)
		(::flixel::FlxBasic_obj::_ACTIVECOUNT)++;
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC0(FlxBasic_obj,update,(void))

Void FlxBasic_obj::draw( ){
{
		HX_STACK_FRAME("flixel.FlxBasic","draw",0x12af3b24,"flixel.FlxBasic.draw","flixel/FlxBasic.hx",112,0xd8d6cfcf)
		HX_STACK_THIS(this)
		HX_STACK_LINE(114)
		if (((this->cameras == null()))){
			HX_STACK_LINE(116)
			this->cameras = ::flixel::FlxG_obj::cameras->list;
		}
		HX_STACK_LINE(119)
		{
			HX_STACK_LINE(119)
			int _g = (int)0;		HX_STACK_VAR(_g,"_g");
			HX_STACK_LINE(119)
			Array< ::Dynamic > _g1 = this->cameras;		HX_STACK_VAR(_g1,"_g1");
			HX_STACK_LINE(119)
			while(((_g < _g1->length))){
				HX_STACK_LINE(119)
				::flixel::FlxCamera camera = _g1->__get(_g).StaticCast< ::flixel::FlxCamera >();		HX_STACK_VAR(camera,"camera");
				HX_STACK_LINE(119)
				++(_g);
				HX_STACK_LINE(121)
				(::flixel::FlxBasic_obj::_VISIBLECOUNT)++;
			}
		}
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC0(FlxBasic_obj,draw,(void))

Void FlxBasic_obj::drawDebug( ){
{
		HX_STACK_FRAME("flixel.FlxBasic","drawDebug",0xb060a48f,"flixel.FlxBasic.drawDebug","flixel/FlxBasic.hx",129,0xd8d6cfcf)
		HX_STACK_THIS(this)
		HX_STACK_LINE(129)
		if ((!(this->ignoreDrawDebug))){
			HX_STACK_LINE(131)
			int i = (int)0;		HX_STACK_VAR(i,"i");
			HX_STACK_LINE(132)
			if (((this->cameras == null()))){
				HX_STACK_LINE(134)
				this->cameras = ::flixel::FlxG_obj::cameras->list;
			}
			HX_STACK_LINE(136)
			int l = this->cameras->length;		HX_STACK_VAR(l,"l");
			HX_STACK_LINE(137)
			while(((i < l))){
				HX_STACK_LINE(139)
				this->drawDebugOnCamera(this->cameras->__get((i)++).StaticCast< ::flixel::FlxCamera >());
			}
		}
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC0(FlxBasic_obj,drawDebug,(void))

Void FlxBasic_obj::drawDebugOnCamera( ::flixel::FlxCamera Camera){
{
		HX_STACK_FRAME("flixel.FlxBasic","drawDebugOnCamera",0xfd6944d3,"flixel.FlxBasic.drawDebugOnCamera","flixel/FlxBasic.hx",149,0xd8d6cfcf)
		HX_STACK_THIS(this)
		HX_STACK_ARG(Camera,"Camera")
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC1(FlxBasic_obj,drawDebugOnCamera,(void))

bool FlxBasic_obj::set_visible( bool Value){
	HX_STACK_FRAME("flixel.FlxBasic","set_visible",0x942af475,"flixel.FlxBasic.set_visible","flixel/FlxBasic.hx",157,0xd8d6cfcf)
	HX_STACK_THIS(this)
	HX_STACK_ARG(Value,"Value")
	HX_STACK_LINE(157)
	return this->visible = Value;
}


HX_DEFINE_DYNAMIC_FUNC1(FlxBasic_obj,set_visible,return )

bool FlxBasic_obj::set_active( bool Value){
	HX_STACK_FRAME("flixel.FlxBasic","set_active",0x086e7723,"flixel.FlxBasic.set_active","flixel/FlxBasic.hx",161,0xd8d6cfcf)
	HX_STACK_THIS(this)
	HX_STACK_ARG(Value,"Value")
	HX_STACK_LINE(161)
	return this->active = Value;
}


HX_DEFINE_DYNAMIC_FUNC1(FlxBasic_obj,set_active,return )

bool FlxBasic_obj::set_alive( bool Value){
	HX_STACK_FRAME("flixel.FlxBasic","set_alive",0x59c1c910,"flixel.FlxBasic.set_alive","flixel/FlxBasic.hx",165,0xd8d6cfcf)
	HX_STACK_THIS(this)
	HX_STACK_ARG(Value,"Value")
	HX_STACK_LINE(165)
	return this->alive = Value;
}


HX_DEFINE_DYNAMIC_FUNC1(FlxBasic_obj,set_alive,return )

bool FlxBasic_obj::set_exists( bool Value){
	HX_STACK_FRAME("flixel.FlxBasic","set_exists",0xb2085339,"flixel.FlxBasic.set_exists","flixel/FlxBasic.hx",169,0xd8d6cfcf)
	HX_STACK_THIS(this)
	HX_STACK_ARG(Value,"Value")
	HX_STACK_LINE(169)
	return this->exists = Value;
}


HX_DEFINE_DYNAMIC_FUNC1(FlxBasic_obj,set_exists,return )

::String FlxBasic_obj::toString( ){
	HX_STACK_FRAME("flixel.FlxBasic","toString",0x03b3efcc,"flixel.FlxBasic.toString","flixel/FlxBasic.hx",176,0xd8d6cfcf)
	HX_STACK_THIS(this)
	struct _Function_1_1{
		inline static Dynamic Block( ::flixel::FlxBasic_obj *__this){
			HX_STACK_FRAME("*","closure",0x5bdab937,"*.closure","flixel/FlxBasic.hx",177,0xd8d6cfcf)
			{
				hx::Anon __result = hx::Anon_obj::Create();
				__result->Add(HX_CSTRING("label") , HX_CSTRING("active"),false);
				__result->Add(HX_CSTRING("value") , __this->active,false);
				return __result;
			}
			return null();
		}
	};
	HX_STACK_LINE(177)
	Dynamic _g = _Function_1_1::Block(this);		HX_STACK_VAR(_g,"_g");
	struct _Function_1_2{
		inline static Dynamic Block( ::flixel::FlxBasic_obj *__this){
			HX_STACK_FRAME("*","closure",0x5bdab937,"*.closure","flixel/FlxBasic.hx",178,0xd8d6cfcf)
			{
				hx::Anon __result = hx::Anon_obj::Create();
				__result->Add(HX_CSTRING("label") , HX_CSTRING("visible"),false);
				__result->Add(HX_CSTRING("value") , __this->visible,false);
				return __result;
			}
			return null();
		}
	};
	HX_STACK_LINE(178)
	Dynamic _g1 = _Function_1_2::Block(this);		HX_STACK_VAR(_g1,"_g1");
	struct _Function_1_3{
		inline static Dynamic Block( ::flixel::FlxBasic_obj *__this){
			HX_STACK_FRAME("*","closure",0x5bdab937,"*.closure","flixel/FlxBasic.hx",179,0xd8d6cfcf)
			{
				hx::Anon __result = hx::Anon_obj::Create();
				__result->Add(HX_CSTRING("label") , HX_CSTRING("alive"),false);
				__result->Add(HX_CSTRING("value") , __this->alive,false);
				return __result;
			}
			return null();
		}
	};
	HX_STACK_LINE(179)
	Dynamic _g2 = _Function_1_3::Block(this);		HX_STACK_VAR(_g2,"_g2");
	struct _Function_1_4{
		inline static Dynamic Block( ::flixel::FlxBasic_obj *__this){
			HX_STACK_FRAME("*","closure",0x5bdab937,"*.closure","flixel/FlxBasic.hx",180,0xd8d6cfcf)
			{
				hx::Anon __result = hx::Anon_obj::Create();
				__result->Add(HX_CSTRING("label") , HX_CSTRING("exists"),false);
				__result->Add(HX_CSTRING("value") , __this->exists,false);
				return __result;
			}
			return null();
		}
	};
	HX_STACK_LINE(177)
	return ::flixel::util::FlxStringUtil_obj::getDebugString(Dynamic( Array_obj<Dynamic>::__new().Add(_g).Add(_g1).Add(_g2).Add(_Function_1_4::Block(this))));
}


HX_DEFINE_DYNAMIC_FUNC0(FlxBasic_obj,toString,return )

int FlxBasic_obj::_ACTIVECOUNT;

int FlxBasic_obj::_VISIBLECOUNT;


FlxBasic_obj::FlxBasic_obj()
{
}

void FlxBasic_obj::__Mark(HX_MARK_PARAMS)
{
	HX_MARK_BEGIN_CLASS(FlxBasic);
	HX_MARK_MEMBER_NAME(ID,"ID");
	HX_MARK_MEMBER_NAME(cameras,"cameras");
	HX_MARK_MEMBER_NAME(active,"active");
	HX_MARK_MEMBER_NAME(visible,"visible");
	HX_MARK_MEMBER_NAME(alive,"alive");
	HX_MARK_MEMBER_NAME(exists,"exists");
	HX_MARK_MEMBER_NAME(collisionType,"collisionType");
	HX_MARK_MEMBER_NAME(ignoreDrawDebug,"ignoreDrawDebug");
	HX_MARK_END_CLASS();
}

void FlxBasic_obj::__Visit(HX_VISIT_PARAMS)
{
	HX_VISIT_MEMBER_NAME(ID,"ID");
	HX_VISIT_MEMBER_NAME(cameras,"cameras");
	HX_VISIT_MEMBER_NAME(active,"active");
	HX_VISIT_MEMBER_NAME(visible,"visible");
	HX_VISIT_MEMBER_NAME(alive,"alive");
	HX_VISIT_MEMBER_NAME(exists,"exists");
	HX_VISIT_MEMBER_NAME(collisionType,"collisionType");
	HX_VISIT_MEMBER_NAME(ignoreDrawDebug,"ignoreDrawDebug");
}

Dynamic FlxBasic_obj::__Field(const ::String &inName,bool inCallProp)
{
	switch(inName.length) {
	case 2:
		if (HX_FIELD_EQ(inName,"ID") ) { return ID; }
		break;
	case 4:
		if (HX_FIELD_EQ(inName,"kill") ) { return kill_dyn(); }
		if (HX_FIELD_EQ(inName,"draw") ) { return draw_dyn(); }
		break;
	case 5:
		if (HX_FIELD_EQ(inName,"alive") ) { return alive; }
		break;
	case 6:
		if (HX_FIELD_EQ(inName,"active") ) { return active; }
		if (HX_FIELD_EQ(inName,"exists") ) { return exists; }
		if (HX_FIELD_EQ(inName,"revive") ) { return revive_dyn(); }
		if (HX_FIELD_EQ(inName,"update") ) { return update_dyn(); }
		break;
	case 7:
		if (HX_FIELD_EQ(inName,"cameras") ) { return cameras; }
		if (HX_FIELD_EQ(inName,"visible") ) { return visible; }
		if (HX_FIELD_EQ(inName,"destroy") ) { return destroy_dyn(); }
		break;
	case 8:
		if (HX_FIELD_EQ(inName,"toString") ) { return toString_dyn(); }
		break;
	case 9:
		if (HX_FIELD_EQ(inName,"drawDebug") ) { return drawDebug_dyn(); }
		if (HX_FIELD_EQ(inName,"set_alive") ) { return set_alive_dyn(); }
		break;
	case 10:
		if (HX_FIELD_EQ(inName,"set_active") ) { return set_active_dyn(); }
		if (HX_FIELD_EQ(inName,"set_exists") ) { return set_exists_dyn(); }
		break;
	case 11:
		if (HX_FIELD_EQ(inName,"set_visible") ) { return set_visible_dyn(); }
		break;
	case 12:
		if (HX_FIELD_EQ(inName,"_ACTIVECOUNT") ) { return _ACTIVECOUNT; }
		break;
	case 13:
		if (HX_FIELD_EQ(inName,"_VISIBLECOUNT") ) { return _VISIBLECOUNT; }
		if (HX_FIELD_EQ(inName,"collisionType") ) { return collisionType; }
		break;
	case 15:
		if (HX_FIELD_EQ(inName,"ignoreDrawDebug") ) { return ignoreDrawDebug; }
		break;
	case 17:
		if (HX_FIELD_EQ(inName,"drawDebugOnCamera") ) { return drawDebugOnCamera_dyn(); }
	}
	return super::__Field(inName,inCallProp);
}

Dynamic FlxBasic_obj::__SetField(const ::String &inName,const Dynamic &inValue,bool inCallProp)
{
	switch(inName.length) {
	case 2:
		if (HX_FIELD_EQ(inName,"ID") ) { ID=inValue.Cast< int >(); return inValue; }
		break;
	case 5:
		if (HX_FIELD_EQ(inName,"alive") ) { if (inCallProp) return set_alive(inValue);alive=inValue.Cast< bool >(); return inValue; }
		break;
	case 6:
		if (HX_FIELD_EQ(inName,"active") ) { if (inCallProp) return set_active(inValue);active=inValue.Cast< bool >(); return inValue; }
		if (HX_FIELD_EQ(inName,"exists") ) { if (inCallProp) return set_exists(inValue);exists=inValue.Cast< bool >(); return inValue; }
		break;
	case 7:
		if (HX_FIELD_EQ(inName,"cameras") ) { cameras=inValue.Cast< Array< ::Dynamic > >(); return inValue; }
		if (HX_FIELD_EQ(inName,"visible") ) { if (inCallProp) return set_visible(inValue);visible=inValue.Cast< bool >(); return inValue; }
		break;
	case 12:
		if (HX_FIELD_EQ(inName,"_ACTIVECOUNT") ) { _ACTIVECOUNT=inValue.Cast< int >(); return inValue; }
		break;
	case 13:
		if (HX_FIELD_EQ(inName,"_VISIBLECOUNT") ) { _VISIBLECOUNT=inValue.Cast< int >(); return inValue; }
		if (HX_FIELD_EQ(inName,"collisionType") ) { collisionType=inValue.Cast< ::flixel::system::FlxCollisionType >(); return inValue; }
		break;
	case 15:
		if (HX_FIELD_EQ(inName,"ignoreDrawDebug") ) { ignoreDrawDebug=inValue.Cast< bool >(); return inValue; }
	}
	return super::__SetField(inName,inValue,inCallProp);
}

void FlxBasic_obj::__GetFields(Array< ::String> &outFields)
{
	outFields->push(HX_CSTRING("ID"));
	outFields->push(HX_CSTRING("cameras"));
	outFields->push(HX_CSTRING("active"));
	outFields->push(HX_CSTRING("visible"));
	outFields->push(HX_CSTRING("alive"));
	outFields->push(HX_CSTRING("exists"));
	outFields->push(HX_CSTRING("collisionType"));
	outFields->push(HX_CSTRING("ignoreDrawDebug"));
	super::__GetFields(outFields);
};

static ::String sStaticFields[] = {
	HX_CSTRING("_ACTIVECOUNT"),
	HX_CSTRING("_VISIBLECOUNT"),
	String(null()) };

#if HXCPP_SCRIPTABLE
static hx::StorageInfo sMemberStorageInfo[] = {
	{hx::fsInt,(int)offsetof(FlxBasic_obj,ID),HX_CSTRING("ID")},
	{hx::fsObject /*Array< ::Dynamic >*/ ,(int)offsetof(FlxBasic_obj,cameras),HX_CSTRING("cameras")},
	{hx::fsBool,(int)offsetof(FlxBasic_obj,active),HX_CSTRING("active")},
	{hx::fsBool,(int)offsetof(FlxBasic_obj,visible),HX_CSTRING("visible")},
	{hx::fsBool,(int)offsetof(FlxBasic_obj,alive),HX_CSTRING("alive")},
	{hx::fsBool,(int)offsetof(FlxBasic_obj,exists),HX_CSTRING("exists")},
	{hx::fsObject /*::flixel::system::FlxCollisionType*/ ,(int)offsetof(FlxBasic_obj,collisionType),HX_CSTRING("collisionType")},
	{hx::fsBool,(int)offsetof(FlxBasic_obj,ignoreDrawDebug),HX_CSTRING("ignoreDrawDebug")},
	{ hx::fsUnknown, 0, null()}
};
#endif

static ::String sMemberFields[] = {
	HX_CSTRING("ID"),
	HX_CSTRING("cameras"),
	HX_CSTRING("active"),
	HX_CSTRING("visible"),
	HX_CSTRING("alive"),
	HX_CSTRING("exists"),
	HX_CSTRING("collisionType"),
	HX_CSTRING("ignoreDrawDebug"),
	HX_CSTRING("destroy"),
	HX_CSTRING("kill"),
	HX_CSTRING("revive"),
	HX_CSTRING("update"),
	HX_CSTRING("draw"),
	HX_CSTRING("drawDebug"),
	HX_CSTRING("drawDebugOnCamera"),
	HX_CSTRING("set_visible"),
	HX_CSTRING("set_active"),
	HX_CSTRING("set_alive"),
	HX_CSTRING("set_exists"),
	HX_CSTRING("toString"),
	String(null()) };

static void sMarkStatics(HX_MARK_PARAMS) {
	HX_MARK_MEMBER_NAME(FlxBasic_obj::__mClass,"__mClass");
	HX_MARK_MEMBER_NAME(FlxBasic_obj::_ACTIVECOUNT,"_ACTIVECOUNT");
	HX_MARK_MEMBER_NAME(FlxBasic_obj::_VISIBLECOUNT,"_VISIBLECOUNT");
};

#ifdef HXCPP_VISIT_ALLOCS
static void sVisitStatics(HX_VISIT_PARAMS) {
	HX_VISIT_MEMBER_NAME(FlxBasic_obj::__mClass,"__mClass");
	HX_VISIT_MEMBER_NAME(FlxBasic_obj::_ACTIVECOUNT,"_ACTIVECOUNT");
	HX_VISIT_MEMBER_NAME(FlxBasic_obj::_VISIBLECOUNT,"_VISIBLECOUNT");
};

#endif

Class FlxBasic_obj::__mClass;

void FlxBasic_obj::__register()
{
	hx::Static(__mClass) = hx::RegisterClass(HX_CSTRING("flixel.FlxBasic"), hx::TCanCast< FlxBasic_obj> ,sStaticFields,sMemberFields,
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

void FlxBasic_obj::__boot()
{
	_ACTIVECOUNT= (int)0;
	_VISIBLECOUNT= (int)0;
}

} // end namespace flixel
