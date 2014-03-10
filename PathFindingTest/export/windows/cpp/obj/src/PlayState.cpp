#include <hxcpp.h>

#ifndef INCLUDED_PlayState
#include <PlayState.h>
#endif
#ifndef INCLUDED_Seeker
#include <Seeker.h>
#endif
#ifndef INCLUDED_Std
#include <Std.h>
#endif
#ifndef INCLUDED_flixel_FlxBasic
#include <flixel/FlxBasic.h>
#endif
#ifndef INCLUDED_flixel_FlxG
#include <flixel/FlxG.h>
#endif
#ifndef INCLUDED_flixel_FlxObject
#include <flixel/FlxObject.h>
#endif
#ifndef INCLUDED_flixel_FlxSprite
#include <flixel/FlxSprite.h>
#endif
#ifndef INCLUDED_flixel_FlxState
#include <flixel/FlxState.h>
#endif
#ifndef INCLUDED_flixel_group_FlxGroup
#include <flixel/group/FlxGroup.h>
#endif
#ifndef INCLUDED_flixel_group_FlxTypedGroup
#include <flixel/group/FlxTypedGroup.h>
#endif
#ifndef INCLUDED_flixel_input_keyboard_FlxKeyList
#include <flixel/input/keyboard/FlxKeyList.h>
#endif
#ifndef INCLUDED_flixel_input_keyboard_FlxKeyboard
#include <flixel/input/keyboard/FlxKeyboard.h>
#endif
#ifndef INCLUDED_flixel_input_mouse_FlxMouse
#include <flixel/input/mouse/FlxMouse.h>
#endif
#ifndef INCLUDED_flixel_input_mouse_FlxMouseButton
#include <flixel/input/mouse/FlxMouseButton.h>
#endif
#ifndef INCLUDED_flixel_interfaces_IFlxDestroyable
#include <flixel/interfaces/IFlxDestroyable.h>
#endif
#ifndef INCLUDED_flixel_interfaces_IFlxInput
#include <flixel/interfaces/IFlxInput.h>
#endif
#ifndef INCLUDED_flixel_tile_FlxTilemap
#include <flixel/tile/FlxTilemap.h>
#endif
#ifndef INCLUDED_flixel_util_FlxPoint
#include <flixel/util/FlxPoint.h>
#endif
#ifndef INCLUDED_haxe_Log
#include <haxe/Log.h>
#endif
#ifndef INCLUDED_hxMath
#include <hxMath.h>
#endif

Void PlayState_obj::__construct(Dynamic MaxSize)
{
HX_STACK_FRAME("PlayState","new",0xf8bf96cf,"PlayState.new","PlayState.hx",19,0xb30d7781)

HX_STACK_ARG(MaxSize,"MaxSize")
{
	HX_STACK_LINE(27)
	this->SPEED = (int)64;
	HX_STACK_LINE(23)
	this->distances = null();
	HX_STACK_LINE(19)
	super::__construct(MaxSize);
}
;
	return null();
}

//PlayState_obj::~PlayState_obj() { }

Dynamic PlayState_obj::__CreateEmpty() { return  new PlayState_obj; }
hx::ObjectPtr< PlayState_obj > PlayState_obj::__new(Dynamic MaxSize)
{  hx::ObjectPtr< PlayState_obj > result = new PlayState_obj();
	result->__construct(MaxSize);
	return result;}

Dynamic PlayState_obj::__Create(hx::DynamicArray inArgs)
{  hx::ObjectPtr< PlayState_obj > result = new PlayState_obj();
	result->__construct(inArgs[0]);
	return result;}

Void PlayState_obj::create( ){
{
		HX_STACK_FRAME("PlayState","create",0x82220fed,"PlayState.create","PlayState.hx",34,0xb30d7781)
		HX_STACK_THIS(this)
		HX_STACK_LINE(35)
		this->set_bgColor((int)-1);
		HX_STACK_LINE(36)
		this->super::create();
		HX_STACK_LINE(37)
		this->makeTiles();
	}
return null();
}


Void PlayState_obj::destroy( ){
{
		HX_STACK_FRAME("PlayState","destroy",0x6ec756e9,"PlayState.destroy","PlayState.hx",46,0xb30d7781)
		HX_STACK_THIS(this)
		HX_STACK_LINE(46)
		this->super::destroy();
	}
return null();
}


Void PlayState_obj::update( ){
{
		HX_STACK_FRAME("PlayState","update",0x8d182efa,"PlayState.update","PlayState.hx",53,0xb30d7781)
		HX_STACK_THIS(this)
		HX_STACK_LINE(54)
		this->super::update();
		HX_STACK_LINE(56)
		if ((::flixel::FlxG_obj::keys->checkStatus((int)46,::flixel::FlxG_obj::keys->justPressed->checkStatus))){
			HX_STACK_LINE(57)
			::flixel::FlxBasic seeker = this->group_seekers->getFirstAlive();		HX_STACK_VAR(seeker,"seeker");
			HX_STACK_LINE(58)
			seeker->kill();
		}
		else{
			HX_STACK_LINE(59)
			if ((::flixel::FlxG_obj::keys->checkStatus((int)32,::flixel::FlxG_obj::keys->justPressed->checkStatus))){
				HX_STACK_LINE(60)
				this->placeSeeker();
			}
		}
		HX_STACK_LINE(63)
		if (((::flixel::FlxG_obj::mouse->_leftButton->current > (int)0))){
			HX_STACK_LINE(64)
			this->clickTile((int)1);
		}
		else{
			HX_STACK_LINE(65)
			if (((::flixel::FlxG_obj::mouse->_rightButton->current > (int)0))){
				HX_STACK_LINE(66)
				this->clickTile((int)0);
			}
			else{
				HX_STACK_LINE(67)
				if (((::flixel::FlxG_obj::mouse->_middleButton->current > (int)0))){
					HX_STACK_LINE(68)
					this->placeMcguffin(::flixel::FlxG_obj::mouse->x,::flixel::FlxG_obj::mouse->y);
				}
			}
		}
		HX_STACK_LINE(70)
		this->updateSeekers();
	}
return null();
}


Void PlayState_obj::updateSeekers( ){
{
		HX_STACK_FRAME("PlayState","updateSeekers",0xfdad6914,"PlayState.updateSeekers","PlayState.hx",73,0xb30d7781)
		HX_STACK_THIS(this)
		HX_STACK_LINE(74)
		::flixel::FlxG_obj::overlap(this->tilemap,this->group_seekers,null(),::flixel::FlxObject_obj::separate_dyn());
		HX_STACK_LINE(75)
		::flixel::FlxG_obj::overlap(this->group_seekers,this->group_seekers,null(),::flixel::FlxObject_obj::separate_dyn());
		HX_STACK_LINE(77)
		::Seeker seeker;		HX_STACK_VAR(seeker,"seeker");
		HX_STACK_LINE(78)
		{
			HX_STACK_LINE(78)
			int _g = (int)0;		HX_STACK_VAR(_g,"_g");
			HX_STACK_LINE(78)
			Array< ::Dynamic > _g1 = this->group_seekers->get_members();		HX_STACK_VAR(_g1,"_g1");
			HX_STACK_LINE(78)
			while(((_g < _g1->length))){
				HX_STACK_LINE(78)
				::flixel::FlxBasic basic = _g1->__get(_g).StaticCast< ::flixel::FlxBasic >();		HX_STACK_VAR(basic,"basic");
				HX_STACK_LINE(78)
				++(_g);
				HX_STACK_LINE(79)
				seeker = basic;
				HX_STACK_LINE(80)
				if ((!(seeker->moving))){
					HX_STACK_LINE(82)
					int tx = ::Std_obj::_int((Float(((seeker->x - seeker->offset->x))) / Float((int)16)));		HX_STACK_VAR(tx,"tx");
					HX_STACK_LINE(83)
					int ty = ::Std_obj::_int((Float(((seeker->y - seeker->offset->y))) / Float((int)16)));		HX_STACK_VAR(ty,"ty");
					HX_STACK_LINE(85)
					int bestX = (int)0;		HX_STACK_VAR(bestX,"bestX");
					HX_STACK_LINE(86)
					int bestY = (int)0;		HX_STACK_VAR(bestY,"bestY");
					HX_STACK_LINE(87)
					Float bestDist = ::Math_obj::POSITIVE_INFINITY;		HX_STACK_VAR(bestDist,"bestDist");
					HX_STACK_LINE(88)
					Array< Float > _g2 = Array_obj< Float >::__new().Add((int)999).Add((int)999).Add((int)999);		HX_STACK_VAR(_g2,"_g2");
					HX_STACK_LINE(88)
					Array< Float > _g11 = Array_obj< Float >::__new().Add((int)999).Add((int)999).Add((int)999);		HX_STACK_VAR(_g11,"_g11");
					HX_STACK_LINE(88)
					Array< ::Dynamic > neighbors = Array_obj< ::Dynamic >::__new().Add(_g2).Add(_g11).Add(Array_obj< Float >::__new().Add((int)999).Add((int)999).Add((int)999));		HX_STACK_VAR(neighbors,"neighbors");
					HX_STACK_LINE(89)
					{
						HX_STACK_LINE(89)
						int _g3 = (int)-1;		HX_STACK_VAR(_g3,"_g3");
						HX_STACK_LINE(89)
						int _g21 = (int)2;		HX_STACK_VAR(_g21,"_g21");
						HX_STACK_LINE(89)
						while(((_g3 < _g21))){
							HX_STACK_LINE(89)
							int yy = (_g3)++;		HX_STACK_VAR(yy,"yy");
							HX_STACK_LINE(90)
							{
								HX_STACK_LINE(90)
								int _g5 = (int)-1;		HX_STACK_VAR(_g5,"_g5");
								HX_STACK_LINE(90)
								int _g4 = (int)2;		HX_STACK_VAR(_g4,"_g4");
								HX_STACK_LINE(90)
								while(((_g5 < _g4))){
									HX_STACK_LINE(90)
									int xx = (_g5)++;		HX_STACK_VAR(xx,"xx");
									HX_STACK_LINE(91)
									int theX = (tx + xx);		HX_STACK_VAR(theX,"theX");
									HX_STACK_LINE(92)
									int theY = (ty + yy);		HX_STACK_VAR(theY,"theY");
									HX_STACK_LINE(94)
									if (((bool((theX >= (int)0)) && bool((theY < this->distmap->widthInTiles))))){
										HX_STACK_LINE(95)
										if (((bool((theY >= (int)0)) && bool((theY < this->distmap->heightInTiles))))){
											HX_STACK_LINE(96)
											if (((bool((xx == (int)0)) || bool((yy == (int)0))))){
												HX_STACK_LINE(97)
												Float distance = this->distances->__get(((theY * this->distmap->widthInTiles) + theX));		HX_STACK_VAR(distance,"distance");
												HX_STACK_LINE(98)
												neighbors->__get((yy + (int)1)).StaticCast< Array< Float > >()[(xx + (int)1)] = distance;
												HX_STACK_LINE(99)
												if (((distance > (int)0))){
													HX_STACK_LINE(100)
													if (((bool((distance < bestDist)) || bool((bool((bestX == (int)0)) && bool((bestY == (int)0))))))){
														HX_STACK_LINE(102)
														bestDist = distance;
														HX_STACK_LINE(103)
														bestX = xx;
														HX_STACK_LINE(104)
														bestY = yy;
													}
												}
											}
										}
									}
								}
							}
						}
					}
					HX_STACK_LINE(113)
					if ((!(((bool((bestX == (int)0)) && bool((bestY == (int)0))))))){
						HX_STACK_LINE(115)
						seeker->moveTo((((tx * (int)16) + (bestX * (int)16)) + seeker->offset->x),(((ty * (int)16) + (bestY * (int)16)) + seeker->offset->y),0.25);
					}
				}
			}
		}
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC0(PlayState_obj,updateSeekers,(void))

Void PlayState_obj::placeSeeker( ){
{
		HX_STACK_FRAME("PlayState","placeSeeker",0x9826317b,"PlayState.placeSeeker","PlayState.hx",121,0xb30d7781)
		HX_STACK_THIS(this)
		HX_STACK_LINE(122)
		int tx = ::Std_obj::_int((Float(::flixel::FlxG_obj::mouse->x) / Float((int)16)));		HX_STACK_VAR(tx,"tx");
		HX_STACK_LINE(123)
		int ty = ::Std_obj::_int((Float(::flixel::FlxG_obj::mouse->y) / Float((int)16)));		HX_STACK_VAR(ty,"ty");
		HX_STACK_LINE(125)
		::Seeker seeker = this->group_seekers->getFirstDead();		HX_STACK_VAR(seeker,"seeker");
		HX_STACK_LINE(126)
		if (((seeker == null()))){
			HX_STACK_LINE(127)
			seeker = ::Seeker_obj::__new((tx * (int)16),(ty * (int)16),HX_CSTRING("assets/images/seeker.png"));
			HX_STACK_LINE(128)
			seeker->offset->set_x((int)2);
			HX_STACK_LINE(129)
			seeker->offset->set_y((int)2);
			HX_STACK_LINE(130)
			{
				HX_STACK_LINE(130)
				::Seeker _g = seeker;		HX_STACK_VAR(_g,"_g");
				HX_STACK_LINE(130)
				_g->set_x((_g->x + (int)2));
			}
			HX_STACK_LINE(131)
			{
				HX_STACK_LINE(131)
				::Seeker _g = seeker;		HX_STACK_VAR(_g,"_g");
				HX_STACK_LINE(131)
				_g->set_y((_g->y + (int)2));
			}
			HX_STACK_LINE(132)
			seeker->set_width((int)12);
			HX_STACK_LINE(133)
			seeker->set_height((int)12);
			HX_STACK_LINE(134)
			seeker->set_solid(true);
		}
		else{
			HX_STACK_LINE(136)
			seeker->reset((tx * (int)16),(ty * (int)16));
			HX_STACK_LINE(137)
			seeker->offset->set_x((int)2);
			HX_STACK_LINE(138)
			seeker->offset->set_y((int)2);
			HX_STACK_LINE(139)
			{
				HX_STACK_LINE(139)
				::Seeker _g = seeker;		HX_STACK_VAR(_g,"_g");
				HX_STACK_LINE(139)
				_g->set_x((_g->x + (int)2));
			}
			HX_STACK_LINE(140)
			{
				HX_STACK_LINE(140)
				::Seeker _g = seeker;		HX_STACK_VAR(_g,"_g");
				HX_STACK_LINE(140)
				_g->set_y((_g->y + (int)2));
			}
			HX_STACK_LINE(141)
			seeker->set_width((int)12);
			HX_STACK_LINE(142)
			seeker->set_height((int)12);
		}
		HX_STACK_LINE(144)
		this->group_seekers->add(seeker);
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC0(PlayState_obj,placeSeeker,(void))

Void PlayState_obj::placeMcguffin( Float X,Float Y){
{
		HX_STACK_FRAME("PlayState","placeMcguffin",0x7831293f,"PlayState.placeMcguffin","PlayState.hx",147,0xb30d7781)
		HX_STACK_THIS(this)
		HX_STACK_ARG(X,"X")
		HX_STACK_ARG(Y,"Y")
		HX_STACK_LINE(148)
		this->mcguffin->set_x(::Std_obj::_int((Float(X) / Float((int)16))));
		HX_STACK_LINE(149)
		this->mcguffin->set_y(::Std_obj::_int((Float(Y) / Float((int)16))));
		HX_STACK_LINE(151)
		this->mcguffinSprite->set_x(::Std_obj::_int((this->mcguffin->x * (int)16)));
		HX_STACK_LINE(152)
		this->mcguffinSprite->set_y(::Std_obj::_int((this->mcguffin->y * (int)16)));
		HX_STACK_LINE(154)
		this->updateDistance();
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC2(PlayState_obj,placeMcguffin,(void))

Void PlayState_obj::updateDistance( ){
{
		HX_STACK_FRAME("PlayState","updateDistance",0x0b62084f,"PlayState.updateDistance","PlayState.hx",157,0xb30d7781)
		HX_STACK_THIS(this)
		HX_STACK_LINE(158)
		int startX = ::Std_obj::_int(((this->mcguffin->y * this->tilemap->widthInTiles) + this->mcguffin->x));		HX_STACK_VAR(startX,"startX");
		HX_STACK_LINE(159)
		int endX = (int)0;		HX_STACK_VAR(endX,"endX");
		HX_STACK_LINE(160)
		if (((startX == endX))){
			HX_STACK_LINE(161)
			endX = (int)1;
		}
		HX_STACK_LINE(164)
		this->distances = this->tilemap->computePathDistance(startX,endX,true,false);
		HX_STACK_LINE(166)
		int maxDistance = (int)1;		HX_STACK_VAR(maxDistance,"maxDistance");
		HX_STACK_LINE(167)
		{
			HX_STACK_LINE(167)
			int _g = (int)0;		HX_STACK_VAR(_g,"_g");
			HX_STACK_LINE(167)
			Array< int > _g1 = this->distances;		HX_STACK_VAR(_g1,"_g1");
			HX_STACK_LINE(167)
			while(((_g < _g1->length))){
				HX_STACK_LINE(167)
				int dist = _g1->__get(_g);		HX_STACK_VAR(dist,"dist");
				HX_STACK_LINE(167)
				++(_g);
				HX_STACK_LINE(168)
				if (((dist > maxDistance))){
					HX_STACK_LINE(169)
					maxDistance = dist;
				}
			}
		}
		HX_STACK_LINE(173)
		{
			HX_STACK_LINE(173)
			int _g1 = (int)0;		HX_STACK_VAR(_g1,"_g1");
			HX_STACK_LINE(173)
			int _g = this->distances->length;		HX_STACK_VAR(_g,"_g");
			HX_STACK_LINE(173)
			while(((_g1 < _g))){
				HX_STACK_LINE(173)
				int i = (_g1)++;		HX_STACK_VAR(i,"i");
				HX_STACK_LINE(174)
				int disti = (int)0;		HX_STACK_VAR(disti,"disti");
				HX_STACK_LINE(175)
				if (((this->distances->__get(i) < (int)0))){
					HX_STACK_LINE(176)
					disti = (int)1000;
				}
				else{
					HX_STACK_LINE(178)
					disti = ::Std_obj::_int(((int)999 * ((Float(this->distances->__get(i)) / Float(maxDistance)))));
				}
				HX_STACK_LINE(180)
				this->distmap->setTileByIndex(i,disti,true);
			}
		}
		HX_STACK_LINE(183)
		::haxe::Log_obj::trace(HX_CSTRING("BOINK"),hx::SourceInfo(HX_CSTRING("PlayState.hx"),183,HX_CSTRING("PlayState"),HX_CSTRING("updateDistance")));
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC0(PlayState_obj,updateDistance,(void))

Void PlayState_obj::clickTile( int value){
{
		HX_STACK_FRAME("PlayState","clickTile",0x684efb45,"PlayState.clickTile","PlayState.hx",186,0xb30d7781)
		HX_STACK_THIS(this)
		HX_STACK_ARG(value,"value")
		HX_STACK_LINE(187)
		int tx = ::Std_obj::_int((Float(::flixel::FlxG_obj::mouse->x) / Float((int)16)));		HX_STACK_VAR(tx,"tx");
		HX_STACK_LINE(188)
		int ty = ::Std_obj::_int((Float(::flixel::FlxG_obj::mouse->y) / Float((int)16)));		HX_STACK_VAR(ty,"ty");
		HX_STACK_LINE(189)
		this->tilemap->setTile(tx,ty,value,true);
		HX_STACK_LINE(191)
		this->tilemap->setTileProperties((int)0,(int)0,null(),null(),null());
		HX_STACK_LINE(192)
		this->tilemap->setTileProperties((int)1,(int)4369,null(),null(),null());
		HX_STACK_LINE(194)
		this->updateDistance();
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC1(PlayState_obj,clickTile,(void))

Void PlayState_obj::makeTiles( ){
{
		HX_STACK_FRAME("PlayState","makeTiles",0x20203866,"PlayState.makeTiles","PlayState.hx",197,0xb30d7781)
		HX_STACK_THIS(this)
		HX_STACK_LINE(198)
		this->tilemap = ::flixel::tile::FlxTilemap_obj::__new();
		HX_STACK_LINE(199)
		this->distmap = ::flixel::tile::FlxTilemap_obj::__new();
		HX_STACK_LINE(200)
		this->tilemap->set_scaleX((int)16);
		HX_STACK_LINE(201)
		this->tilemap->set_scaleY((int)16);
		HX_STACK_LINE(202)
		this->distmap->set_scaleX((int)16);
		HX_STACK_LINE(203)
		this->distmap->set_scaleY((int)16);
		HX_STACK_LINE(205)
		int tw = ::Std_obj::_int((Float(::flixel::FlxG_obj::width) / Float((int)16)));		HX_STACK_VAR(tw,"tw");
		HX_STACK_LINE(206)
		int th = ::Std_obj::_int((Float(::flixel::FlxG_obj::height) / Float((int)16)));		HX_STACK_VAR(th,"th");
		HX_STACK_LINE(208)
		Array< int > arr = Array_obj< int >::__new();		HX_STACK_VAR(arr,"arr");
		HX_STACK_LINE(209)
		Array< int > arr2 = Array_obj< int >::__new();		HX_STACK_VAR(arr2,"arr2");
		HX_STACK_LINE(210)
		{
			HX_STACK_LINE(210)
			int _g = (int)0;		HX_STACK_VAR(_g,"_g");
			HX_STACK_LINE(210)
			while(((_g < tw))){
				HX_STACK_LINE(210)
				int ww = (_g)++;		HX_STACK_VAR(ww,"ww");
				HX_STACK_LINE(212)
				{
					HX_STACK_LINE(212)
					int _g1 = (int)0;		HX_STACK_VAR(_g1,"_g1");
					HX_STACK_LINE(212)
					while(((_g1 < th))){
						HX_STACK_LINE(212)
						int hh = (_g1)++;		HX_STACK_VAR(hh,"hh");
						HX_STACK_LINE(214)
						arr->push((int)0);
						HX_STACK_LINE(215)
						arr2->push((int)0);
					}
				}
			}
		}
		HX_STACK_LINE(219)
		this->tilemap->widthInTiles = tw;
		HX_STACK_LINE(220)
		this->tilemap->heightInTiles = th;
		HX_STACK_LINE(221)
		this->distmap->widthInTiles = tw;
		HX_STACK_LINE(222)
		this->distmap->heightInTiles = th;
		HX_STACK_LINE(224)
		this->tilemap->loadMap(arr,HX_CSTRING("assets/images/tileset.png"),(int)1,(int)1,null(),null(),null(),null());
		HX_STACK_LINE(225)
		this->distmap->loadMap(arr2,HX_CSTRING("assets/images/heat.png"),(int)1,(int)1,null(),null(),null(),null());
		HX_STACK_LINE(226)
		this->add(this->distmap);
		HX_STACK_LINE(229)
		this->tilemap->setTileProperties((int)0,(int)0,null(),null(),null());
		HX_STACK_LINE(230)
		this->tilemap->setTileProperties((int)1,(int)4369,null(),null(),null());
		HX_STACK_LINE(231)
		this->tilemap->set_solid(true);
		HX_STACK_LINE(233)
		this->group_seekers = ::flixel::group::FlxGroup_obj::__new(null());
		HX_STACK_LINE(234)
		this->add(this->group_seekers);
		HX_STACK_LINE(236)
		this->mcguffin = ::flixel::util::FlxPoint_obj::__new((int)0,(int)0);
		HX_STACK_LINE(237)
		this->mcguffinSprite = ::flixel::FlxSprite_obj::__new((int)0,(int)0,HX_CSTRING("assets/images/mcguffin.png"));
		HX_STACK_LINE(238)
		this->add(this->mcguffinSprite);
		HX_STACK_LINE(240)
		this->placeMcguffin((int)0,(int)0);
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC0(PlayState_obj,makeTiles,(void))


PlayState_obj::PlayState_obj()
{
}

void PlayState_obj::__Mark(HX_MARK_PARAMS)
{
	HX_MARK_BEGIN_CLASS(PlayState);
	HX_MARK_MEMBER_NAME(tilemap,"tilemap");
	HX_MARK_MEMBER_NAME(distmap,"distmap");
	HX_MARK_MEMBER_NAME(distances,"distances");
	HX_MARK_MEMBER_NAME(mcguffin,"mcguffin");
	HX_MARK_MEMBER_NAME(mcguffinSprite,"mcguffinSprite");
	HX_MARK_MEMBER_NAME(SPEED,"SPEED");
	HX_MARK_MEMBER_NAME(group_seekers,"group_seekers");
	::flixel::FlxState_obj::__Mark(HX_MARK_ARG);
	HX_MARK_END_CLASS();
}

void PlayState_obj::__Visit(HX_VISIT_PARAMS)
{
	HX_VISIT_MEMBER_NAME(tilemap,"tilemap");
	HX_VISIT_MEMBER_NAME(distmap,"distmap");
	HX_VISIT_MEMBER_NAME(distances,"distances");
	HX_VISIT_MEMBER_NAME(mcguffin,"mcguffin");
	HX_VISIT_MEMBER_NAME(mcguffinSprite,"mcguffinSprite");
	HX_VISIT_MEMBER_NAME(SPEED,"SPEED");
	HX_VISIT_MEMBER_NAME(group_seekers,"group_seekers");
	::flixel::FlxState_obj::__Visit(HX_VISIT_ARG);
}

Dynamic PlayState_obj::__Field(const ::String &inName,bool inCallProp)
{
	switch(inName.length) {
	case 5:
		if (HX_FIELD_EQ(inName,"SPEED") ) { return SPEED; }
		break;
	case 6:
		if (HX_FIELD_EQ(inName,"create") ) { return create_dyn(); }
		if (HX_FIELD_EQ(inName,"update") ) { return update_dyn(); }
		break;
	case 7:
		if (HX_FIELD_EQ(inName,"tilemap") ) { return tilemap; }
		if (HX_FIELD_EQ(inName,"distmap") ) { return distmap; }
		if (HX_FIELD_EQ(inName,"destroy") ) { return destroy_dyn(); }
		break;
	case 8:
		if (HX_FIELD_EQ(inName,"mcguffin") ) { return mcguffin; }
		break;
	case 9:
		if (HX_FIELD_EQ(inName,"distances") ) { return distances; }
		if (HX_FIELD_EQ(inName,"clickTile") ) { return clickTile_dyn(); }
		if (HX_FIELD_EQ(inName,"makeTiles") ) { return makeTiles_dyn(); }
		break;
	case 11:
		if (HX_FIELD_EQ(inName,"placeSeeker") ) { return placeSeeker_dyn(); }
		break;
	case 13:
		if (HX_FIELD_EQ(inName,"group_seekers") ) { return group_seekers; }
		if (HX_FIELD_EQ(inName,"updateSeekers") ) { return updateSeekers_dyn(); }
		if (HX_FIELD_EQ(inName,"placeMcguffin") ) { return placeMcguffin_dyn(); }
		break;
	case 14:
		if (HX_FIELD_EQ(inName,"mcguffinSprite") ) { return mcguffinSprite; }
		if (HX_FIELD_EQ(inName,"updateDistance") ) { return updateDistance_dyn(); }
	}
	return super::__Field(inName,inCallProp);
}

Dynamic PlayState_obj::__SetField(const ::String &inName,const Dynamic &inValue,bool inCallProp)
{
	switch(inName.length) {
	case 5:
		if (HX_FIELD_EQ(inName,"SPEED") ) { SPEED=inValue.Cast< int >(); return inValue; }
		break;
	case 7:
		if (HX_FIELD_EQ(inName,"tilemap") ) { tilemap=inValue.Cast< ::flixel::tile::FlxTilemap >(); return inValue; }
		if (HX_FIELD_EQ(inName,"distmap") ) { distmap=inValue.Cast< ::flixel::tile::FlxTilemap >(); return inValue; }
		break;
	case 8:
		if (HX_FIELD_EQ(inName,"mcguffin") ) { mcguffin=inValue.Cast< ::flixel::util::FlxPoint >(); return inValue; }
		break;
	case 9:
		if (HX_FIELD_EQ(inName,"distances") ) { distances=inValue.Cast< Array< int > >(); return inValue; }
		break;
	case 13:
		if (HX_FIELD_EQ(inName,"group_seekers") ) { group_seekers=inValue.Cast< ::flixel::group::FlxGroup >(); return inValue; }
		break;
	case 14:
		if (HX_FIELD_EQ(inName,"mcguffinSprite") ) { mcguffinSprite=inValue.Cast< ::flixel::FlxSprite >(); return inValue; }
	}
	return super::__SetField(inName,inValue,inCallProp);
}

void PlayState_obj::__GetFields(Array< ::String> &outFields)
{
	outFields->push(HX_CSTRING("tilemap"));
	outFields->push(HX_CSTRING("distmap"));
	outFields->push(HX_CSTRING("distances"));
	outFields->push(HX_CSTRING("mcguffin"));
	outFields->push(HX_CSTRING("mcguffinSprite"));
	outFields->push(HX_CSTRING("SPEED"));
	outFields->push(HX_CSTRING("group_seekers"));
	super::__GetFields(outFields);
};

static ::String sStaticFields[] = {
	String(null()) };

#if HXCPP_SCRIPTABLE
static hx::StorageInfo sMemberStorageInfo[] = {
	{hx::fsObject /*::flixel::tile::FlxTilemap*/ ,(int)offsetof(PlayState_obj,tilemap),HX_CSTRING("tilemap")},
	{hx::fsObject /*::flixel::tile::FlxTilemap*/ ,(int)offsetof(PlayState_obj,distmap),HX_CSTRING("distmap")},
	{hx::fsObject /*Array< int >*/ ,(int)offsetof(PlayState_obj,distances),HX_CSTRING("distances")},
	{hx::fsObject /*::flixel::util::FlxPoint*/ ,(int)offsetof(PlayState_obj,mcguffin),HX_CSTRING("mcguffin")},
	{hx::fsObject /*::flixel::FlxSprite*/ ,(int)offsetof(PlayState_obj,mcguffinSprite),HX_CSTRING("mcguffinSprite")},
	{hx::fsInt,(int)offsetof(PlayState_obj,SPEED),HX_CSTRING("SPEED")},
	{hx::fsObject /*::flixel::group::FlxGroup*/ ,(int)offsetof(PlayState_obj,group_seekers),HX_CSTRING("group_seekers")},
	{ hx::fsUnknown, 0, null()}
};
#endif

static ::String sMemberFields[] = {
	HX_CSTRING("tilemap"),
	HX_CSTRING("distmap"),
	HX_CSTRING("distances"),
	HX_CSTRING("mcguffin"),
	HX_CSTRING("mcguffinSprite"),
	HX_CSTRING("SPEED"),
	HX_CSTRING("group_seekers"),
	HX_CSTRING("create"),
	HX_CSTRING("destroy"),
	HX_CSTRING("update"),
	HX_CSTRING("updateSeekers"),
	HX_CSTRING("placeSeeker"),
	HX_CSTRING("placeMcguffin"),
	HX_CSTRING("updateDistance"),
	HX_CSTRING("clickTile"),
	HX_CSTRING("makeTiles"),
	String(null()) };

static void sMarkStatics(HX_MARK_PARAMS) {
	HX_MARK_MEMBER_NAME(PlayState_obj::__mClass,"__mClass");
};

#ifdef HXCPP_VISIT_ALLOCS
static void sVisitStatics(HX_VISIT_PARAMS) {
	HX_VISIT_MEMBER_NAME(PlayState_obj::__mClass,"__mClass");
};

#endif

Class PlayState_obj::__mClass;

void PlayState_obj::__register()
{
	hx::Static(__mClass) = hx::RegisterClass(HX_CSTRING("PlayState"), hx::TCanCast< PlayState_obj> ,sStaticFields,sMemberFields,
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

void PlayState_obj::__boot()
{
}

