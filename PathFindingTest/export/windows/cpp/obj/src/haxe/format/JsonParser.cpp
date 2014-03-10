#include <hxcpp.h>

#ifndef INCLUDED_Std
#include <Std.h>
#endif
#ifndef INCLUDED_StringBuf
#include <StringBuf.h>
#endif
#ifndef INCLUDED_haxe_format_JsonParser
#include <haxe/format/JsonParser.h>
#endif
namespace haxe{
namespace format{

Void JsonParser_obj::__construct(::String str)
{
HX_STACK_FRAME("haxe.format.JsonParser","new",0xa017eec8,"haxe.format.JsonParser.new","C:\\HaxeToolkit\\haxe\\std/haxe/format/JsonParser.hx",12,0x53425a8f)

HX_STACK_ARG(str,"str")
{
	HX_STACK_LINE(13)
	this->str = str;
	HX_STACK_LINE(14)
	this->pos = (int)0;
}
;
	return null();
}

//JsonParser_obj::~JsonParser_obj() { }

Dynamic JsonParser_obj::__CreateEmpty() { return  new JsonParser_obj; }
hx::ObjectPtr< JsonParser_obj > JsonParser_obj::__new(::String str)
{  hx::ObjectPtr< JsonParser_obj > result = new JsonParser_obj();
	result->__construct(str);
	return result;}

Dynamic JsonParser_obj::__Create(hx::DynamicArray inArgs)
{  hx::ObjectPtr< JsonParser_obj > result = new JsonParser_obj();
	result->__construct(inArgs[0]);
	return result;}

Dynamic JsonParser_obj::parseRec( ){
	HX_STACK_FRAME("haxe.format.JsonParser","parseRec",0xda258b75,"haxe.format.JsonParser.parseRec","C:\\HaxeToolkit\\haxe\\std/haxe/format/JsonParser.hx",18,0x53425a8f)
	HX_STACK_THIS(this)
	HX_STACK_LINE(18)
	while((true)){
		HX_STACK_LINE(19)
		int c;		HX_STACK_VAR(c,"c");
		HX_STACK_LINE(19)
		{
			HX_STACK_LINE(19)
			int index = (this->pos)++;		HX_STACK_VAR(index,"index");
			HX_STACK_LINE(19)
			c = this->str.cca(index);
		}
		HX_STACK_LINE(20)
		switch( (int)(c)){
			case (int)32: case (int)13: case (int)10: case (int)9: {
			}
			;break;
			case (int)123: {
				struct _Function_3_1{
					inline static Dynamic Block( ){
						HX_STACK_FRAME("*","closure",0x5bdab937,"*.closure","C:\\HaxeToolkit\\haxe\\std/haxe/format/JsonParser.hx",24,0x53425a8f)
						{
							hx::Anon __result = hx::Anon_obj::Create();
							return __result;
						}
						return null();
					}
				};
				HX_STACK_LINE(24)
				Dynamic obj = _Function_3_1::Block();		HX_STACK_VAR(obj,"obj");
				HX_STACK_LINE(24)
				::String field = null();		HX_STACK_VAR(field,"field");
				HX_STACK_LINE(24)
				Dynamic comma = null();		HX_STACK_VAR(comma,"comma");
				HX_STACK_LINE(25)
				while((true)){
					HX_STACK_LINE(26)
					int c1;		HX_STACK_VAR(c1,"c1");
					HX_STACK_LINE(26)
					{
						HX_STACK_LINE(26)
						int index = (this->pos)++;		HX_STACK_VAR(index,"index");
						HX_STACK_LINE(26)
						c1 = this->str.cca(index);
					}
					HX_STACK_LINE(27)
					switch( (int)(c1)){
						case (int)32: case (int)13: case (int)10: case (int)9: {
						}
						;break;
						case (int)125: {
							HX_STACK_LINE(31)
							if (((bool((field != null())) || bool((comma == false))))){
								HX_STACK_LINE(32)
								this->invalidChar();
							}
							HX_STACK_LINE(33)
							return obj;
						}
						;break;
						case (int)58: {
							HX_STACK_LINE(35)
							if (((field == null()))){
								HX_STACK_LINE(36)
								this->invalidChar();
							}
							HX_STACK_LINE(37)
							{
								HX_STACK_LINE(37)
								Dynamic value = this->parseRec();		HX_STACK_VAR(value,"value");
								HX_STACK_LINE(37)
								if (((obj != null()))){
									HX_STACK_LINE(37)
									obj->__SetField(field,value,false);
								}
							}
							HX_STACK_LINE(38)
							field = null();
							HX_STACK_LINE(39)
							comma = true;
						}
						;break;
						case (int)44: {
							HX_STACK_LINE(41)
							if ((comma)){
								HX_STACK_LINE(41)
								comma = false;
							}
							else{
								HX_STACK_LINE(41)
								this->invalidChar();
							}
						}
						;break;
						case (int)34: {
							HX_STACK_LINE(43)
							if ((comma)){
								HX_STACK_LINE(43)
								this->invalidChar();
							}
							HX_STACK_LINE(44)
							field = this->parseString();
						}
						;break;
						default: {
							HX_STACK_LINE(46)
							this->invalidChar();
						}
					}
				}
			}
			;break;
			case (int)91: {
				HX_STACK_LINE(50)
				Dynamic arr = Dynamic( Array_obj<Dynamic>::__new());		HX_STACK_VAR(arr,"arr");
				HX_STACK_LINE(50)
				Dynamic comma = null();		HX_STACK_VAR(comma,"comma");
				HX_STACK_LINE(51)
				while((true)){
					HX_STACK_LINE(52)
					int c1;		HX_STACK_VAR(c1,"c1");
					HX_STACK_LINE(52)
					{
						HX_STACK_LINE(52)
						int index = (this->pos)++;		HX_STACK_VAR(index,"index");
						HX_STACK_LINE(52)
						c1 = this->str.cca(index);
					}
					HX_STACK_LINE(53)
					switch( (int)(c1)){
						case (int)32: case (int)13: case (int)10: case (int)9: {
						}
						;break;
						case (int)93: {
							HX_STACK_LINE(57)
							if (((comma == false))){
								HX_STACK_LINE(57)
								this->invalidChar();
							}
							HX_STACK_LINE(58)
							return arr;
						}
						;break;
						case (int)44: {
							HX_STACK_LINE(60)
							if ((comma)){
								HX_STACK_LINE(60)
								comma = false;
							}
							else{
								HX_STACK_LINE(60)
								this->invalidChar();
							}
						}
						;break;
						default: {
							HX_STACK_LINE(62)
							if ((comma)){
								HX_STACK_LINE(62)
								this->invalidChar();
							}
							HX_STACK_LINE(63)
							(this->pos)--;
							HX_STACK_LINE(64)
							arr->__Field(HX_CSTRING("push"),true)(this->parseRec());
							HX_STACK_LINE(65)
							comma = true;
						}
					}
				}
			}
			;break;
			case (int)116: {
				HX_STACK_LINE(69)
				int save = this->pos;		HX_STACK_VAR(save,"save");
				struct _Function_3_1{
					inline static int Block( ::haxe::format::JsonParser_obj *__this){
						HX_STACK_FRAME("*","closure",0x5bdab937,"*.closure","C:\\HaxeToolkit\\haxe\\std/haxe/format/JsonParser.hx",70,0x53425a8f)
						{
							HX_STACK_LINE(70)
							int index = (__this->pos)++;		HX_STACK_VAR(index,"index");
							HX_STACK_LINE(70)
							return __this->str.cca(index);
						}
						return null();
					}
				};
				struct _Function_3_2{
					inline static int Block( ::haxe::format::JsonParser_obj *__this){
						HX_STACK_FRAME("*","closure",0x5bdab937,"*.closure","C:\\HaxeToolkit\\haxe\\std/haxe/format/JsonParser.hx",70,0x53425a8f)
						{
							HX_STACK_LINE(70)
							int index = (__this->pos)++;		HX_STACK_VAR(index,"index");
							HX_STACK_LINE(70)
							return __this->str.cca(index);
						}
						return null();
					}
				};
				struct _Function_3_3{
					inline static int Block( ::haxe::format::JsonParser_obj *__this){
						HX_STACK_FRAME("*","closure",0x5bdab937,"*.closure","C:\\HaxeToolkit\\haxe\\std/haxe/format/JsonParser.hx",70,0x53425a8f)
						{
							HX_STACK_LINE(70)
							int index = (__this->pos)++;		HX_STACK_VAR(index,"index");
							HX_STACK_LINE(70)
							return __this->str.cca(index);
						}
						return null();
					}
				};
				HX_STACK_LINE(70)
				if (((  ((!(((  ((!(((_Function_3_1::Block(this) != (int)114))))) ? bool((_Function_3_2::Block(this) != (int)117)) : bool(true) ))))) ? bool((_Function_3_3::Block(this) != (int)101)) : bool(true) ))){
					HX_STACK_LINE(71)
					this->pos = save;
					HX_STACK_LINE(72)
					this->invalidChar();
				}
				HX_STACK_LINE(74)
				return true;
			}
			;break;
			case (int)102: {
				HX_STACK_LINE(76)
				int save = this->pos;		HX_STACK_VAR(save,"save");
				struct _Function_3_1{
					inline static int Block( ::haxe::format::JsonParser_obj *__this){
						HX_STACK_FRAME("*","closure",0x5bdab937,"*.closure","C:\\HaxeToolkit\\haxe\\std/haxe/format/JsonParser.hx",77,0x53425a8f)
						{
							HX_STACK_LINE(77)
							int index = (__this->pos)++;		HX_STACK_VAR(index,"index");
							HX_STACK_LINE(77)
							return __this->str.cca(index);
						}
						return null();
					}
				};
				struct _Function_3_2{
					inline static int Block( ::haxe::format::JsonParser_obj *__this){
						HX_STACK_FRAME("*","closure",0x5bdab937,"*.closure","C:\\HaxeToolkit\\haxe\\std/haxe/format/JsonParser.hx",77,0x53425a8f)
						{
							HX_STACK_LINE(77)
							int index = (__this->pos)++;		HX_STACK_VAR(index,"index");
							HX_STACK_LINE(77)
							return __this->str.cca(index);
						}
						return null();
					}
				};
				struct _Function_3_3{
					inline static int Block( ::haxe::format::JsonParser_obj *__this){
						HX_STACK_FRAME("*","closure",0x5bdab937,"*.closure","C:\\HaxeToolkit\\haxe\\std/haxe/format/JsonParser.hx",77,0x53425a8f)
						{
							HX_STACK_LINE(77)
							int index = (__this->pos)++;		HX_STACK_VAR(index,"index");
							HX_STACK_LINE(77)
							return __this->str.cca(index);
						}
						return null();
					}
				};
				struct _Function_3_4{
					inline static int Block( ::haxe::format::JsonParser_obj *__this){
						HX_STACK_FRAME("*","closure",0x5bdab937,"*.closure","C:\\HaxeToolkit\\haxe\\std/haxe/format/JsonParser.hx",77,0x53425a8f)
						{
							HX_STACK_LINE(77)
							int index = (__this->pos)++;		HX_STACK_VAR(index,"index");
							HX_STACK_LINE(77)
							return __this->str.cca(index);
						}
						return null();
					}
				};
				HX_STACK_LINE(77)
				if (((  ((!(((  ((!(((  ((!(((_Function_3_1::Block(this) != (int)97))))) ? bool((_Function_3_2::Block(this) != (int)108)) : bool(true) ))))) ? bool((_Function_3_3::Block(this) != (int)115)) : bool(true) ))))) ? bool((_Function_3_4::Block(this) != (int)101)) : bool(true) ))){
					HX_STACK_LINE(78)
					this->pos = save;
					HX_STACK_LINE(79)
					this->invalidChar();
				}
				HX_STACK_LINE(81)
				return false;
			}
			;break;
			case (int)110: {
				HX_STACK_LINE(83)
				int save = this->pos;		HX_STACK_VAR(save,"save");
				struct _Function_3_1{
					inline static int Block( ::haxe::format::JsonParser_obj *__this){
						HX_STACK_FRAME("*","closure",0x5bdab937,"*.closure","C:\\HaxeToolkit\\haxe\\std/haxe/format/JsonParser.hx",84,0x53425a8f)
						{
							HX_STACK_LINE(84)
							int index = (__this->pos)++;		HX_STACK_VAR(index,"index");
							HX_STACK_LINE(84)
							return __this->str.cca(index);
						}
						return null();
					}
				};
				struct _Function_3_2{
					inline static int Block( ::haxe::format::JsonParser_obj *__this){
						HX_STACK_FRAME("*","closure",0x5bdab937,"*.closure","C:\\HaxeToolkit\\haxe\\std/haxe/format/JsonParser.hx",84,0x53425a8f)
						{
							HX_STACK_LINE(84)
							int index = (__this->pos)++;		HX_STACK_VAR(index,"index");
							HX_STACK_LINE(84)
							return __this->str.cca(index);
						}
						return null();
					}
				};
				struct _Function_3_3{
					inline static int Block( ::haxe::format::JsonParser_obj *__this){
						HX_STACK_FRAME("*","closure",0x5bdab937,"*.closure","C:\\HaxeToolkit\\haxe\\std/haxe/format/JsonParser.hx",84,0x53425a8f)
						{
							HX_STACK_LINE(84)
							int index = (__this->pos)++;		HX_STACK_VAR(index,"index");
							HX_STACK_LINE(84)
							return __this->str.cca(index);
						}
						return null();
					}
				};
				HX_STACK_LINE(84)
				if (((  ((!(((  ((!(((_Function_3_1::Block(this) != (int)117))))) ? bool((_Function_3_2::Block(this) != (int)108)) : bool(true) ))))) ? bool((_Function_3_3::Block(this) != (int)108)) : bool(true) ))){
					HX_STACK_LINE(85)
					this->pos = save;
					HX_STACK_LINE(86)
					this->invalidChar();
				}
				HX_STACK_LINE(88)
				return null();
			}
			;break;
			case (int)34: {
				HX_STACK_LINE(90)
				return this->parseString();
			}
			;break;
			case (int)48: case (int)49: case (int)50: case (int)51: case (int)52: case (int)53: case (int)54: case (int)55: case (int)56: case (int)57: case (int)45: {
				HX_STACK_LINE(92)
				int c1 = c;		HX_STACK_VAR(c1,"c1");
				HX_STACK_LINE(92)
				int start = (this->pos - (int)1);		HX_STACK_VAR(start,"start");
				HX_STACK_LINE(92)
				bool minus = (c1 == (int)45);		HX_STACK_VAR(minus,"minus");
				HX_STACK_LINE(92)
				bool digit = !(minus);		HX_STACK_VAR(digit,"digit");
				HX_STACK_LINE(92)
				bool zero = (c1 == (int)48);		HX_STACK_VAR(zero,"zero");
				HX_STACK_LINE(92)
				bool point = false;		HX_STACK_VAR(point,"point");
				HX_STACK_LINE(92)
				bool e = false;		HX_STACK_VAR(e,"e");
				HX_STACK_LINE(92)
				bool pm = false;		HX_STACK_VAR(pm,"pm");
				HX_STACK_LINE(92)
				bool end = false;		HX_STACK_VAR(end,"end");
				HX_STACK_LINE(92)
				while((true)){
					HX_STACK_LINE(92)
					{
						HX_STACK_LINE(92)
						int index = (this->pos)++;		HX_STACK_VAR(index,"index");
						HX_STACK_LINE(92)
						c1 = this->str.cca(index);
					}
					HX_STACK_LINE(92)
					switch( (int)(c1)){
						case (int)48: {
							HX_STACK_LINE(92)
							if (((bool(zero) && bool(!(point))))){
								HX_STACK_LINE(92)
								this->invalidNumber(start);
							}
							HX_STACK_LINE(92)
							if ((minus)){
								HX_STACK_LINE(92)
								minus = false;
								HX_STACK_LINE(92)
								zero = true;
							}
							HX_STACK_LINE(92)
							digit = true;
						}
						;break;
						case (int)49: case (int)50: case (int)51: case (int)52: case (int)53: case (int)54: case (int)55: case (int)56: case (int)57: {
							HX_STACK_LINE(92)
							if (((bool(zero) && bool(!(point))))){
								HX_STACK_LINE(92)
								this->invalidNumber(start);
							}
							HX_STACK_LINE(92)
							if ((minus)){
								HX_STACK_LINE(92)
								minus = false;
							}
							HX_STACK_LINE(92)
							digit = true;
							HX_STACK_LINE(92)
							zero = false;
						}
						;break;
						case (int)46: {
							HX_STACK_LINE(92)
							if (((bool(minus) || bool(point)))){
								HX_STACK_LINE(92)
								this->invalidNumber(start);
							}
							HX_STACK_LINE(92)
							digit = false;
							HX_STACK_LINE(92)
							point = true;
						}
						;break;
						case (int)101: case (int)69: {
							HX_STACK_LINE(92)
							if (((bool((bool(minus) || bool(zero))) || bool(e)))){
								HX_STACK_LINE(92)
								this->invalidNumber(start);
							}
							HX_STACK_LINE(92)
							digit = false;
							HX_STACK_LINE(92)
							e = true;
						}
						;break;
						case (int)43: case (int)45: {
							HX_STACK_LINE(92)
							if (((bool(!(e)) || bool(pm)))){
								HX_STACK_LINE(92)
								this->invalidNumber(start);
							}
							HX_STACK_LINE(92)
							digit = false;
							HX_STACK_LINE(92)
							pm = true;
						}
						;break;
						default: {
							HX_STACK_LINE(92)
							if ((!(digit))){
								HX_STACK_LINE(92)
								this->invalidNumber(start);
							}
							HX_STACK_LINE(92)
							(this->pos)--;
							HX_STACK_LINE(92)
							end = true;
						}
					}
					HX_STACK_LINE(92)
					if ((end)){
						HX_STACK_LINE(92)
						break;
					}
				}
				HX_STACK_LINE(92)
				Float f = ::Std_obj::parseFloat(this->str.substr(start,(this->pos - start)));		HX_STACK_VAR(f,"f");
				HX_STACK_LINE(92)
				int i = ::Std_obj::_int(f);		HX_STACK_VAR(i,"i");
				HX_STACK_LINE(92)
				if (((i == f))){
					HX_STACK_LINE(92)
					return i;
				}
				else{
					HX_STACK_LINE(92)
					return f;
				}
			}
			;break;
			default: {
				HX_STACK_LINE(94)
				this->invalidChar();
			}
		}
	}
	HX_STACK_LINE(18)
	return null();
}


HX_DEFINE_DYNAMIC_FUNC0(JsonParser_obj,parseRec,return )

::String JsonParser_obj::parseString( ){
	HX_STACK_FRAME("haxe.format.JsonParser","parseString",0x8c919bcc,"haxe.format.JsonParser.parseString","C:\\HaxeToolkit\\haxe\\std/haxe/format/JsonParser.hx",99,0x53425a8f)
	HX_STACK_THIS(this)
	HX_STACK_LINE(100)
	int start = this->pos;		HX_STACK_VAR(start,"start");
	HX_STACK_LINE(101)
	::StringBuf buf = ::StringBuf_obj::__new();		HX_STACK_VAR(buf,"buf");
	HX_STACK_LINE(102)
	while((true)){
		HX_STACK_LINE(103)
		int c;		HX_STACK_VAR(c,"c");
		HX_STACK_LINE(103)
		{
			HX_STACK_LINE(103)
			int index = (this->pos)++;		HX_STACK_VAR(index,"index");
			HX_STACK_LINE(103)
			c = this->str.cca(index);
		}
		HX_STACK_LINE(104)
		if (((c == (int)34))){
			HX_STACK_LINE(105)
			break;
		}
		HX_STACK_LINE(106)
		if (((c == (int)92))){
			HX_STACK_LINE(107)
			buf->b->push(this->str.substr(start,((this->pos - start) - (int)1)));
			HX_STACK_LINE(108)
			{
				HX_STACK_LINE(108)
				int index = (this->pos)++;		HX_STACK_VAR(index,"index");
				HX_STACK_LINE(108)
				c = this->str.cca(index);
			}
			HX_STACK_LINE(109)
			switch( (int)(c)){
				case (int)114: {
					HX_STACK_LINE(110)
					buf->b->push(HX_CSTRING("\r"));
				}
				;break;
				case (int)110: {
					HX_STACK_LINE(111)
					buf->b->push(HX_CSTRING("\n"));
				}
				;break;
				case (int)116: {
					HX_STACK_LINE(112)
					buf->b->push(HX_CSTRING("\t"));
				}
				;break;
				case (int)98: {
					HX_STACK_LINE(113)
					buf->b->push(HX_CSTRING("\x08"""));
				}
				;break;
				case (int)102: {
					HX_STACK_LINE(114)
					buf->b->push(HX_CSTRING("\x0c"""));
				}
				;break;
				case (int)47: case (int)92: case (int)34: {
					HX_STACK_LINE(115)
					buf->b->push(::String::fromCharCode(c));
				}
				;break;
				case (int)117: {
					HX_STACK_LINE(117)
					Dynamic uc = ::Std_obj::parseInt((HX_CSTRING("0x") + this->str.substr(this->pos,(int)4)));		HX_STACK_VAR(uc,"uc");
					HX_STACK_LINE(118)
					hx::AddEq(this->pos,(int)4);
					HX_STACK_LINE(120)
					if (((uc <= (int)127))){
						HX_STACK_LINE(121)
						int c1 = uc;		HX_STACK_VAR(c1,"c1");
						HX_STACK_LINE(121)
						buf->b->push(::String::fromCharCode(c1));
					}
					else{
						HX_STACK_LINE(122)
						if (((uc <= (int)2047))){
							HX_STACK_LINE(123)
							buf->b->push(::String::fromCharCode((int((int)192) | int((int(uc) >> int((int)6))))));
							HX_STACK_LINE(124)
							buf->b->push(::String::fromCharCode((int((int)128) | int((int(uc) & int((int)63))))));
						}
						else{
							HX_STACK_LINE(125)
							if (((uc <= (int)65535))){
								HX_STACK_LINE(126)
								buf->b->push(::String::fromCharCode((int((int)224) | int((int(uc) >> int((int)12))))));
								HX_STACK_LINE(127)
								buf->b->push(::String::fromCharCode((int((int)128) | int((int((int(uc) >> int((int)6))) & int((int)63))))));
								HX_STACK_LINE(128)
								buf->b->push(::String::fromCharCode((int((int)128) | int((int(uc) & int((int)63))))));
							}
							else{
								HX_STACK_LINE(130)
								buf->b->push(::String::fromCharCode((int((int)240) | int((int(uc) >> int((int)18))))));
								HX_STACK_LINE(131)
								buf->b->push(::String::fromCharCode((int((int)128) | int((int((int(uc) >> int((int)12))) & int((int)63))))));
								HX_STACK_LINE(132)
								buf->b->push(::String::fromCharCode((int((int)128) | int((int((int(uc) >> int((int)6))) & int((int)63))))));
								HX_STACK_LINE(133)
								buf->b->push(::String::fromCharCode((int((int)128) | int((int(uc) & int((int)63))))));
							}
						}
					}
				}
				;break;
				default: {
					HX_STACK_LINE(139)
					HX_STACK_DO_THROW((((HX_CSTRING("Invalid escape sequence \\") + ::String::fromCharCode(c)) + HX_CSTRING(" at position ")) + ((this->pos - (int)1))));
				}
			}
			HX_STACK_LINE(141)
			start = this->pos;
		}
		else{
			HX_STACK_LINE(145)
			if (((c >= (int)128))){
				HX_STACK_LINE(146)
				(this->pos)++;
				HX_STACK_LINE(147)
				if (((c >= (int)252))){
					HX_STACK_LINE(147)
					hx::AddEq(this->pos,(int)4);
				}
				else{
					HX_STACK_LINE(148)
					if (((c >= (int)248))){
						HX_STACK_LINE(148)
						hx::AddEq(this->pos,(int)3);
					}
					else{
						HX_STACK_LINE(149)
						if (((c >= (int)240))){
							HX_STACK_LINE(149)
							hx::AddEq(this->pos,(int)2);
						}
						else{
							HX_STACK_LINE(150)
							if (((c >= (int)224))){
								HX_STACK_LINE(150)
								(this->pos)++;
							}
						}
					}
				}
			}
			else{
				HX_STACK_LINE(153)
				if (((c == (int)0))){
					HX_STACK_LINE(154)
					HX_STACK_DO_THROW(HX_CSTRING("Unclosed string"));
				}
			}
		}
	}
	HX_STACK_LINE(156)
	buf->b->push(this->str.substr(start,((this->pos - start) - (int)1)));
	HX_STACK_LINE(157)
	return buf->b->join(HX_CSTRING(""));
}


HX_DEFINE_DYNAMIC_FUNC0(JsonParser_obj,parseString,return )

Void JsonParser_obj::invalidChar( ){
{
		HX_STACK_FRAME("haxe.format.JsonParser","invalidChar",0xa9f373d5,"haxe.format.JsonParser.invalidChar","C:\\HaxeToolkit\\haxe\\std/haxe/format/JsonParser.hx",202,0x53425a8f)
		HX_STACK_THIS(this)
		HX_STACK_LINE(203)
		(this->pos)--;
		HX_STACK_LINE(204)
		HX_STACK_DO_THROW((((HX_CSTRING("Invalid char ") + this->str.cca(this->pos)) + HX_CSTRING(" at position ")) + this->pos));
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC0(JsonParser_obj,invalidChar,(void))

Void JsonParser_obj::invalidNumber( int start){
{
		HX_STACK_FRAME("haxe.format.JsonParser","invalidNumber",0x8e9d1988,"haxe.format.JsonParser.invalidNumber","C:\\HaxeToolkit\\haxe\\std/haxe/format/JsonParser.hx",208,0x53425a8f)
		HX_STACK_THIS(this)
		HX_STACK_ARG(start,"start")
		HX_STACK_LINE(208)
		HX_STACK_DO_THROW((((HX_CSTRING("Invalid number at position ") + start) + HX_CSTRING(": ")) + this->str.substr(start,(this->pos - start))));
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC1(JsonParser_obj,invalidNumber,(void))


JsonParser_obj::JsonParser_obj()
{
}

void JsonParser_obj::__Mark(HX_MARK_PARAMS)
{
	HX_MARK_BEGIN_CLASS(JsonParser);
	HX_MARK_MEMBER_NAME(str,"str");
	HX_MARK_MEMBER_NAME(pos,"pos");
	HX_MARK_END_CLASS();
}

void JsonParser_obj::__Visit(HX_VISIT_PARAMS)
{
	HX_VISIT_MEMBER_NAME(str,"str");
	HX_VISIT_MEMBER_NAME(pos,"pos");
}

Dynamic JsonParser_obj::__Field(const ::String &inName,bool inCallProp)
{
	switch(inName.length) {
	case 3:
		if (HX_FIELD_EQ(inName,"str") ) { return str; }
		if (HX_FIELD_EQ(inName,"pos") ) { return pos; }
		break;
	case 8:
		if (HX_FIELD_EQ(inName,"parseRec") ) { return parseRec_dyn(); }
		break;
	case 11:
		if (HX_FIELD_EQ(inName,"parseString") ) { return parseString_dyn(); }
		if (HX_FIELD_EQ(inName,"invalidChar") ) { return invalidChar_dyn(); }
		break;
	case 13:
		if (HX_FIELD_EQ(inName,"invalidNumber") ) { return invalidNumber_dyn(); }
	}
	return super::__Field(inName,inCallProp);
}

Dynamic JsonParser_obj::__SetField(const ::String &inName,const Dynamic &inValue,bool inCallProp)
{
	switch(inName.length) {
	case 3:
		if (HX_FIELD_EQ(inName,"str") ) { str=inValue.Cast< ::String >(); return inValue; }
		if (HX_FIELD_EQ(inName,"pos") ) { pos=inValue.Cast< int >(); return inValue; }
	}
	return super::__SetField(inName,inValue,inCallProp);
}

void JsonParser_obj::__GetFields(Array< ::String> &outFields)
{
	outFields->push(HX_CSTRING("str"));
	outFields->push(HX_CSTRING("pos"));
	super::__GetFields(outFields);
};

static ::String sStaticFields[] = {
	String(null()) };

#if HXCPP_SCRIPTABLE
static hx::StorageInfo sMemberStorageInfo[] = {
	{hx::fsString,(int)offsetof(JsonParser_obj,str),HX_CSTRING("str")},
	{hx::fsInt,(int)offsetof(JsonParser_obj,pos),HX_CSTRING("pos")},
	{ hx::fsUnknown, 0, null()}
};
#endif

static ::String sMemberFields[] = {
	HX_CSTRING("str"),
	HX_CSTRING("pos"),
	HX_CSTRING("parseRec"),
	HX_CSTRING("parseString"),
	HX_CSTRING("invalidChar"),
	HX_CSTRING("invalidNumber"),
	String(null()) };

static void sMarkStatics(HX_MARK_PARAMS) {
	HX_MARK_MEMBER_NAME(JsonParser_obj::__mClass,"__mClass");
};

#ifdef HXCPP_VISIT_ALLOCS
static void sVisitStatics(HX_VISIT_PARAMS) {
	HX_VISIT_MEMBER_NAME(JsonParser_obj::__mClass,"__mClass");
};

#endif

Class JsonParser_obj::__mClass;

void JsonParser_obj::__register()
{
	hx::Static(__mClass) = hx::RegisterClass(HX_CSTRING("haxe.format.JsonParser"), hx::TCanCast< JsonParser_obj> ,sStaticFields,sMemberFields,
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

void JsonParser_obj::__boot()
{
}

} // end namespace haxe
} // end namespace format
