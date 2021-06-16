
#include "keyinp.h"



void keyinput() // Keyboard input. Only to be called if buffer is not empty 
{
 #define gain 1

 int i;
 int ind;
 int store_mouse_x = 0;
 int store_mouse_y = 0;

 ind=readkey();

 switch(ind >> 8) {

  case  KEY_ESC :
    engine_sound(false);
    if (ab_burning)
      ab_sound(false);
    if (stall_horn_on) {
      stall_horn(false);
      stall_horn_on=false;
    }
    if (playing_gear_rumble) {
      play_gear_rumble(0);
      playing_gear_rumble=false;
    }
    startpausetick=ticks_8h;
    if (logging) close_log();
		if (mouse_active) {
          store_mouse_x = mouse_x;
					store_mouse_y = mouse_y;
    }
#ifdef MGUI
/*
        if (paging==true) {
          setactivepage(0);
          setcolor(LIGHTGRAY);
          setfillstyle(SOLID_FILL,LIGHTGRAY);
          bar(0,0,xpixels,ypixels);

          setvisualpage(0);

          set_BGI_mode_pages(1);
          setgraphmode(gmode);
          setcolor(LIGHTGRAY);
          setfillstyle(SOLID_FILL,LIGHTGRAY);
          bar(0,0,xpixels,ypixels);
        }
*/
        main_menu_form(false);

        if (poly_plane_id[current_model]!=F14)
           on_catapult=0;
        running_time=time_of_day;
        set_view_geometry();
        setup_palette();
        find_mag_lim_id();
        update_stars();
	
/*
        if (paging==true) {
          set_BGI_mode_pages(2);
          setgraphmode(gmode);

          setactivepage(page);
          page++;
          page=page % 2;
          setvisualpage(page);
        }
        setup_palette();
		

        if (!detail_jet && ab_burning)
          ab_burning = false;

      
        if (mouse_active) {
          show_ctrlpos=true;
        }
*/
#endif // MGUI 

#ifdef TEXTUI
    mainmenu();
#endif
       
#ifdef CGUI
		

    main_menu_cgui(false);

    if (poly_plane_id[current_model]!=F14)
      on_catapult=0;
    running_time=time_of_day;
    set_view_geometry();
    setup_palette();
    find_mag_lim_id();
    update_stars();

    if (!detail_jet && ab_burning)
      ab_burning = false;

    if (mouse_active) {
      show_ctrlpos=true;
    }
#endif

		if (mouse_active) {
      position_mouse(store_mouse_x, store_mouse_y);
    }
			 
    pausetick += ticks_8h-startpausetick;
    calcnumber=ncalcperframe;
    engine_sound(true);
    if (ab_burning)
      ab_sound(true);
    break;

	case KEY_P :
		if (!(key_shifts & (KB_SHIFT_FLAG | KB_ALT_FLAG | KB_CTRL_FLAG))) {
	  textprintf(active_page, font, 305*xscl,20*yscl, makecol(255,100,100), "PAUSE");
      engine_sound(false);
      if (ab_burning)
        ab_sound(false);
      if (stall_horn_on) {
         stall_horn(false);
         stall_horn_on=false;
      }
      if (playing_gear_rumble) {
         play_gear_rumble(0);
         playing_gear_rumble=false;
      }
	    flip();
      startpausetick=ticks_8h;
			if (mouse_active) {
          store_mouse_x = mouse_x;
					store_mouse_y = mouse_y;
			}
      // Read joystick in waiting loop in order to keep FLCS FCLK awake
      while(!keypressed())
#ifndef LINUX
      readjoy (s,joymask);
#else 
      yield_timeslice();
#endif
      readkey();
      flip();
			if (mouse_active) {
        position_mouse(store_mouse_x, store_mouse_y);
			}
      pausetick += ticks_8h-startpausetick;
      calcnumber=ncalcperframe;
      engine_sound(true);
      if (ab_burning)
        ab_sound(true);
		}
		break;

  case KEY_F1 :
    if (!(key_shifts & (KB_SHIFT_FLAG | KB_ALT_FLAG | KB_CTRL_FLAG))) {
      if (throttle_type == 0) {
        int i;

        throttle=0;
        if (auto_throttle) auto_throttle=false;

        if (detail_jet) {
          for (i=0; i<njetengines; i++) {
            jengine[i].throttle   = 0;
            jengine[i].ab_throttle= 0;
          }
        }
      }
    }
    if (key_shifts & KB_CTRL_FLAG) 
      prop_ctrl=0;
    break;

  case KEY_F2 : 
    if (throttle_type == 0) {
      int i;

      if (!(key_shifts & (KB_SHIFT_FLAG | KB_ALT_FLAG | KB_CTRL_FLAG))) {
        if (throttle > 4) throttle -= 5*gain;
        else throttle = 0;
      }

      if (key_shifts & KB_SHIFT_FLAG) {
        if (throttle >= 1)   throttle -= gain;
      }

      if (auto_throttle) auto_throttle=false;

      if (detail_jet) {
        for (i=0; i<njetengines; i++) {
          if (jengine[i].ab_throttle > 0) {
            throttle = 100;
            jengine[i].throttle = 100;
            jengine[i].ab_throttle--;
          }
          else {
            jengine[i].throttle=throttle;
          }
        }
      }
    }
    if (key_shifts & KB_CTRL_FLAG) {
      if (prop_ctrl > 4)   prop_ctrl -= 5;
    }
    break;

  case KEY_F3 : 
    if (throttle_type == 0) {
      int i;

      if (!(key_shifts & (KB_SHIFT_FLAG | KB_ALT_FLAG | KB_CTRL_FLAG))) {
        if (throttle < 96)  throttle += 5*gain;
        else throttle = 100;
      }

      if (key_shifts & KB_SHIFT_FLAG) {
        if (throttle <= 99)   throttle += gain;
      }

      if (auto_throttle) auto_throttle=false;

      if (detail_jet) {
        for (i=0; i<njetengines; i++) {
          if (jengine[i].throttle < 96) {
            jengine[i].throttle = throttle;
          }
          else {
            if (jengine[i].ab_throttle < jengine[i].n_abstages) {
              throttle = 100;
              jengine[i].throttle = 100;
              jengine[i].ab_throttle++;
            }
          }
        }
      }
    }
    if (key_shifts & KB_CTRL_FLAG) {
      if (prop_ctrl < 96)   prop_ctrl += 5;
    }
    break;

  case KEY_F4 :  
    if (!(key_shifts & (KB_SHIFT_FLAG | KB_ALT_FLAG | KB_CTRL_FLAG))) {
      if (throttle_type == 0) {
        int i;

        throttle=100;
        if (auto_throttle) auto_throttle=false;

        if (detail_jet) {
          for (i=0; i<njetengines; i++) {
            if (jengine[i].throttle < 100)
              jengine[i].throttle = throttle;
            else
              if (jengine[i].ab_throttle < jengine[i].n_abstages)
		          jengine[i].ab_throttle++;
          }
        }
      }
    }
    if (key_shifts & KB_CTRL_FLAG) 
      prop_ctrl=100;
    break;

  case KEY_F5 :
    setflap=0; 
    break;

  case KEY_F6 :
    setflap=8; 
    break;

  case KEY_F7 :
    setflap=16; 
    break;

  case KEY_F8 :
    setflap=24; 
    break;

  case KEY_F9 :
      if (poly_plane_id[current_model]==F14) {
        manual_sweep = true;
        set_sweep    = 20;
      }
      else {
		  for (i=0; i<njetengines; i++) jengine[i].vectordesire=jengine[i].vectoruplim;
      }
		break;

  case KEY_F10 :
		if (!(key_shifts & (KB_SHIFT_FLAG | KB_ALT_FLAG | KB_CTRL_FLAG))) {
      if (poly_plane_id[current_model]==F14) {
        manual_sweep = true;
        set_sweep   -= 5;
        if (set_sweep < 20) set_sweep=20;
      }
      else {
				for (i=0; i<njetengines; i++) {
		      jengine[i].vectordesire -= 15;
		      if (jengine[i].vectordesire < jengine[i].vectoruplim)
			    jengine[i].vectordesire=jengine[i].vectoruplim;
				}
      }
		}
    if (key_shifts & KB_SHIFT_FLAG) {
      for (i=0; i<njetengines; i++) {
		    jengine[i].vectordesire -= 3;
		    if (jengine[i].vectordesire < jengine[i].vectoruplim)
			  jengine[i].vectordesire=jengine[i].vectoruplim;
			}
		}
		break;

  case KEY_F11 :
		if (!(key_shifts & (KB_SHIFT_FLAG | KB_ALT_FLAG | KB_CTRL_FLAG))) {
      if (poly_plane_id[current_model]==F14) {
        manual_sweep = true;
        set_sweep   += 5;
        if (set_sweep > 68) set_sweep=68;
      }
      else {
		    for (i=0; i<njetengines; i++) {
		      jengine[i].vectordesire += 15;
		      if (jengine[i].vectordesire > jengine[i].vectordnlim)
			    jengine[i].vectordesire=jengine[i].vectordnlim;
				}
		  }
    }
    if (key_shifts & KB_SHIFT_FLAG) {
			for (i=0; i<njetengines; i++) {
		    jengine[i].vectordesire += 3;
		    if (jengine[i].vectordesire > jengine[i].vectordnlim)
			  jengine[i].vectordesire=jengine[i].vectordnlim;
			}
		}
		break;

  case KEY_F12 :
      if (poly_plane_id[current_model]==F14) {
        manual_sweep = true;
        set_sweep    = 68;
      }
      else {
		  for (i=0; i<njetengines; i++) jengine[i].vectordesire=jengine[i].vectordnlim;
      }
		break;

  case  KEY_UP :
		if (!(key_shifts & (KB_SHIFT_FLAG | KB_ALT_FLAG | KB_CTRL_FLAG))) {
      if (viewpoint != 10)
		  viewpoint=0;
      else {
        set_panhoriz_int=0;
        set_panvert_int=0;
      }
      if (show_map) {
         show_map=false;
			}
      refresh_palette = 1;
		}
		if (key_shifts & KB_SHIFT_FLAG)
		  if (elevatortrim <  300) elevatortrim += 3;
    break;

  case  KEY_DOWN :
		if (!(key_shifts & (KB_SHIFT_FLAG | KB_ALT_FLAG | KB_CTRL_FLAG))) {
      viewpoint=1;
      if (show_map) {
        show_map=false;
			}
      refresh_palette = 1;
		}
		if (key_shifts & KB_SHIFT_FLAG)
			if (elevatortrim > -300) elevatortrim -= 3;
    break;

  case  KEY_LEFT :
		if (!(key_shifts & (KB_SHIFT_FLAG | KB_ALT_FLAG | KB_CTRL_FLAG))) {
      if (viewpoint != 10) {
         if (viewpoint==1) {
           setup_cockpit_panning();
           panhoriz_int = PI-0.01;
         }
         else
           setup_cockpit_panning();
			}
      set_panhoriz_int=PI/2;
      set_panvert_int=0;

      if (show_map) {
        show_map=false;
			}
      refresh_palette = 1;
		}
		if (key_shifts & KB_SHIFT_FLAG)
			if (ailerontrim > -100) ailerontrim -= 2;
		if (key_shifts & (KB_ALT_FLAG | KB_CTRL_FLAG))
			if (ruddertrim > -100) ruddertrim -= 2;
    break;

  case  KEY_RIGHT : 
		if (!(key_shifts & (KB_SHIFT_FLAG | KB_ALT_FLAG | KB_CTRL_FLAG))) {
      if (viewpoint != 10) {
         if (viewpoint==1) {
           setup_cockpit_panning();
           panhoriz_int = PI+0.01;
         }
         else
           setup_cockpit_panning();
			}
      set_panhoriz_int=3*PI/2;
      set_panvert_int=0;

      if (show_map) {
        show_map=false;
			}
      refresh_palette = 1;
		}
		if (key_shifts & KB_SHIFT_FLAG)
			if (ailerontrim <  100) ailerontrim += 2;
		if (key_shifts & (KB_ALT_FLAG | KB_CTRL_FLAG))
			if (ruddertrim <  100) ruddertrim += 2;
    break;

  case  KEY_HOME: 
      {
        cartvektor carr_pos, tower_pos;
        float carr_afst, tower_afst;

        carr_pos    = get_carrier_pos();
        tower_pos.x = 1200;
        tower_pos.y = 50;
        carr_afst   = sqrt(SQR(carr_pos.x-x)+SQR(carr_pos.y-y));
        tower_afst  = sqrt(SQR(tower_pos.x-x)+SQR(tower_pos.y-y));
        if (carr_afst > tower_afst)
		     viewpoint=4;
        else
           viewpoint=7;
        if (show_map) {
           show_map=false;
		}
		refresh_palette = 1;
      }
      break;

  case  KEY_END : 
		viewpoint=5;
      if (show_map) {
         show_map=false;
	  }
      refresh_palette = 1;
      break;

  case  KEY_INSERT :   
      viewpoint=6;
      if (show_map) {
         show_map=false;
	  }
      refresh_palette = 1;
      break;

  case KEY_ASTERISK :
      viewpoint=8;
      if (show_map) {
         show_map=false;
         refresh_palette = 1;
         }
      break;

  case KEY_SLASH_PAD :
      viewpoint=9;
      if (show_map) {
         show_map=false;
         refresh_palette = 1;
         }
      break;

  case  KEY_H :
    if (!(key_shifts & (KB_SHIFT_FLAG | KB_ALT_FLAG | KB_CTRL_FLAG)))
      sethook=!sethook;
    if (key_shifts & KB_ALT_FLAG) {
      if (show_hud) {
        if (color_hud) {
           color_hud = false;
           hud_red   = LIGHTGREEN;
           hud_blue  = LIGHTGREEN;
           hud_white = LIGHTGREEN;
        }
        else {
           show_hud             = false;
           nlcos_bullets_flying = 0;
        }
      }
      else {
        show_hud  = true;
        color_hud = true;
        hud_red   = LIGHTRED;
        hud_blue  = LIGHTBLUE;
        hud_white = WHITE;
      }
    }
    break;

  case  KEY_X: 
    if (!(key_shifts & (KB_SHIFT_FLAG | KB_ALT_FLAG | KB_CTRL_FLAG))){ 
      // Center rudder
      if ( rudder_type==0 ) setrudder=0;
    }
    if (key_shifts & KB_ALT_FLAG) crash=true; 
    break;

  case  KEY_C: 
    if (!(key_shifts & (KB_SHIFT_FLAG | KB_ALT_FLAG | KB_CTRL_FLAG))){ 
      if ((setrudder < 24) && (rudder_type==0) ) setrudder += gain;
    }
    if (key_shifts & KB_ALT_FLAG) {
			if (mouse_active) position_mouse(SCREEN_W/2,SCREEN_H/2);
			else
#ifndef LINUX
      joy_center();
#else
			;
#endif
		}

    break;

  case  KEY_W:
		if (!(key_shifts & (KB_SHIFT_FLAG | KB_ALT_FLAG | KB_CTRL_FLAG)))
      whlbrakes=!whlbrakes;
    if (key_shifts & KB_SHIFT_FLAG) {
      active_waypoint++;
      if (active_waypoint > nwaypoints-1) active_waypoint=0;
    }
    if (key_shifts & KB_ALT_FLAG) {
      active_waypoint--;
      if (active_waypoint < 0) active_waypoint=nwaypoints-1;
    }
    break;

  case KEY_B :
    if (!(key_shifts & (KB_SHIFT_FLAG | KB_ALT_FLAG | KB_CTRL_FLAG))) 
      setabrk=!setabrk;
    if (key_shifts & KB_SHIFT_FLAG) 
      setabrk=true;
    if (key_shifts & KB_ALT_FLAG) 
      setabrk=false;
    break;

  case KEY_Z :
    if (!(key_shifts & (KB_SHIFT_FLAG | KB_ALT_FLAG | KB_CTRL_FLAG))) {
      if ((setrudder > -24) && (rudder_type==0)) setrudder -= gain;
    }
    break;

	case KEY_E :
    if (!(key_shifts & (KB_SHIFT_FLAG | KB_ALT_FLAG | KB_CTRL_FLAG))) {
      if (njetengines > 0) {
        int i;
        for (i=0; i<njetengines; i++)
          if (rnd(100) > 25) jengine[i].ignition = true;
      }
	    if (nrocketengines > 0) {
        int i;
        for (i=0; i<nrocketengines; i++)
            rengine[i].ignition = !rengine[i].ignition;
		    if (poly_plane_id[current_model]==LM && !rengine[0].ignition) {
			    play_wav(ENGINE_STOP_WAV, 255, 180, 1000, false);
				}
			}
    }
    if (key_shifts & KB_SHIFT_FLAG) {
	    engineering_mode = !engineering_mode;
	    if (engineering_mode)
		  set_message("Engineering mode ON",2,YELLOW);
	    else
		  set_message("Engineering mode OFF",2,YELLOW);
		}
	  break;

  case KEY_L :
		if (key_shifts & KB_SHIFT_FLAG) {
	    logging = !logging;
	    if (logging)
		    open_log();
	    else
		    close_log();
		}
	  break;

  case KEY_D :
    if (!(key_shifts & (KB_SHIFT_FLAG | KB_ALT_FLAG | KB_CTRL_FLAG)))
      show_cockpit = !show_cockpit;
    if (key_shifts & KB_SHIFT_FLAG)
      show_plane_inside = !show_plane_inside;
    break;

	case KEY_S :
    if (!(key_shifts & (KB_SHIFT_FLAG | KB_ALT_FLAG | KB_CTRL_FLAG)))
      manual_sweep=!manual_sweep;
    break;

	case KEY_R :
    if (!(key_shifts & (KB_SHIFT_FLAG | KB_ALT_FLAG | KB_CTRL_FLAG)))
      rcs_control = !rcs_control;
    break;

	case KEY_G :
    if (!(key_shifts & (KB_SHIFT_FLAG | KB_ALT_FLAG | KB_CTRL_FLAG)))
      setgear=!setgear;
    break;

	case KEY_J :
    if (!(key_shifts & (KB_SHIFT_FLAG | KB_ALT_FLAG | KB_CTRL_FLAG)))
      show_ctrlpos=!show_ctrlpos;
    break;

	case KEY_I :
		if (!(key_shifts & (KB_SHIFT_FLAG | KB_ALT_FLAG | KB_CTRL_FLAG)))
      HUDmode = ILS;
    if (key_shifts & KB_SHIFT_FLAG)
      show_instruments =!show_instruments;
    break;

	case KEY_N :
    if (!(key_shifts & (KB_SHIFT_FLAG | KB_ALT_FLAG | KB_CTRL_FLAG)))
      HUDmode = NAVIGATION;
    break;

	case KEY_Q :
		if (!(key_shifts & (KB_SHIFT_FLAG | KB_ALT_FLAG | KB_CTRL_FLAG))) {
      if (poly_plane_id[current_model]==F14 && DLC_active && DLC_spoiler >= 1.0)
        DLC_spoiler--;
		}
    if (key_shifts & KB_SHIFT_FLAG)
      crash=true;
    break;

	case KEY_A :
    if (!(key_shifts & (KB_SHIFT_FLAG | KB_ALT_FLAG | KB_CTRL_FLAG))) {
			if (poly_plane_id[current_model]==F14 && DLC_active && DLC_spoiler <= 14.0)
        DLC_spoiler++;
		} 
    break;

	case KEY_M :
    if (!(key_shifts & (KB_SHIFT_FLAG | KB_ALT_FLAG | KB_CTRL_FLAG))) {
			show_map=!show_map;
      refresh_palette = 1;
    }
    break;

	case KEY_T :
		if (!(key_shifts & (KB_SHIFT_FLAG | KB_ALT_FLAG | KB_CTRL_FLAG)))
      auto_throttle=!auto_throttle;
    if (key_shifts & KB_SHIFT_FLAG) {
      int ntried        = 0;
      bool found_target = false;

      while( !found_target && ntried < ntargets) {
        ntried++;
        selected_target = (selected_target+1) % ntargets;
        if (target[selected_target].strength > target[selected_target].nhits)
          found_target=true;
      }
      if (!found_target)
        selected_target=-1;
		} 
    break;

  case KEY_F:
		if (key_shifts & KB_SHIFT_FLAG) {
       bool failure_possible = false;
       int i;

       for (i=0; i<npropengines; i++)
         if (pengine[i].power > 0) failure_possible = true;
       if (detail_jet) {
         for (i=0; i<njetengines; i++)
           if (jengine[i].ignition == true) failure_possible = true;
       }
       else {
         for (i=0; i<njetengines; i++)
           if (jengine[i].power > 0) failure_possible = true;
       }
       if (failure_possible && !failure_upcoming) {
         failure_upcoming=true;
         set_message("Engine failure coming up!",5,YELLOW);
         i=rnd(60);
         failure_time=lasttick+tickspersec*i;
       }
     }
     break;

	case  KEY_PLUS_PAD :
    if (show_map) {
      if (map_zoom>4) map_zoom /= 2;
    }
    else {
		  // Limit needs to be big (25) in order not to crash the polygon drawer
		  if (!engineering_mode) {
				if (set_traildist > 25) set_traildist /= 1.5;
		  }
		  else {
				if (set_traildist > 1) set_traildist /= 1.1;
		  }
	  }
		break;

  case  KEY_MINUS_PAD :
    if (show_map) {
      if (map_zoom<=((mapsize-1)/4)) map_zoom *= 2;
    }
    else
		  if (set_traildist < 10000) set_traildist *= 1.5;
		break;

	case KEY_4_PAD:
      if (viewpoint == 5 || viewpoint == 6) { // Outside views
		  if (!engineering_mode) {
			set_panhoriz -= PI/16;
		  }
		  else {
			set_panhoriz -= PI/128;
		  }
		  panhorizsgn=-1;
          if (set_panhoriz < 0)    set_panhoriz += 2*PI;
      }
      else {
        if (viewpoint != 10) {
          if (viewpoint==1){
            setup_cockpit_panning();
            set_panhoriz_int = PI+PI/16;
            panhoriz_int     = PI+PI/8;
          }
          else
            setup_cockpit_panning();
        }
        set_panhoriz_int += PI/16;
		  if (set_panhoriz_int > 2*PI) set_panhoriz_int -= 2*PI;
        if (set_panhoriz_int > PI-PI/8 && set_panhoriz_int < PI+PI/8)
        set_panhoriz_int = PI-PI/8;
      }
		break;

  case KEY_6_PAD:
      if (viewpoint == 5 || viewpoint == 6) {// Outside views
		  if (!engineering_mode) {
			set_panhoriz += PI/16;
		  }
		  else {
			set_panhoriz += PI/128;
		  }
          panhorizsgn=1;
          if (set_panhoriz >= 2*PI) set_panhoriz -= 2*PI;
      }
      else {
        if (viewpoint != 10) {
          if (viewpoint==1){
            setup_cockpit_panning();
            set_panhoriz_int = PI-PI/16;
            panhoriz_int     = PI-PI/8;
          }
          else
            setup_cockpit_panning();
        }
        set_panhoriz_int -= PI/16;
		  if (set_panhoriz_int < 0) set_panhoriz_int += 2*PI;
        if (set_panhoriz_int > PI-PI/8 && set_panhoriz_int < PI+PI/8)
        set_panhoriz_int = PI+PI/8;
      }
		break;

	case KEY_2_PAD :
      if (viewpoint == 5 || viewpoint == 6) {/* Outside views */
		  if (!engineering_mode) {
			set_panvert -= PI/16;
		  }
		  else {
			set_panvert -= PI/128;
		  }
          if (set_panvert < -7*PI/16) set_panvert =-7*PI/16;
      }
      else {
        if (viewpoint != 10)
           setup_cockpit_panning();
        set_panvert_int -= PI/16;
		if (set_panvert_int < -7*PI/16) set_panvert_int = -7*PI/16;  
      }
		break;

  case KEY_8_PAD :
      if (viewpoint == 5 || viewpoint == 6) {/* Outside views */
		  if (!engineering_mode) {
			set_panvert += PI/16;
		  }
		  else {
			set_panvert += PI/128;
		  }
          if (set_panvert > 7*PI/16) set_panvert = 7*PI/16;
      }
      else {
        if (viewpoint != 10)
           setup_cockpit_panning();
        set_panvert_int += PI/16;
		if (set_panvert_int > 7*PI/16) set_panvert_int = 7*PI/16;
      }
		break;

  case KEY_5_PAD : // center view
	  if (viewpoint == 5 || viewpoint == 6) {/* Outside views */
      }
      else {
        if (viewpoint != 10)
        setup_cockpit_panning();
        set_panvert_int  = 0;
		set_panhoriz_int = 0;
	  }
	    break;

	case KEY_ENTER :
    HUDmode = AIRAIR; 
	  break;

	case KEY_BACKSPACE :
    HUDmode = AIRGROUND; 
		break;

  default : ;
 }




 if ( rudder_type==0 ) // Keyboard for rudder control
 {
  if (ctrlexpo==true) {
   // max linear stroke 25 for rudder
   float norm;
   norm=(float) setrudder/25;
   rudder=25*(norm+/*2**/pow(norm,5));
   // tilsvarende for joyx,y tidligere
  }
  else rudder=setrudder;

  rudder=rudder_gain*(rudder+ruddertrim*0.1)/2; // giver bedre kontrol

  if (poly_plane_id[current_model]==F14)
    element[3].left.deflect=-rudder*1.5;
  else
    element[rudderid].left.deflect=-rudder*1.5;
  tail_rudder=rudder;
  gear[steerwhlid].steer=setrudder;
 }

}

