#ifndef LINUX
#  include <dos.h>
#endif

#include <stdlib.h>
#include <stdio.h>
#include <math.h>
#include <string.h>
#include "joystick.h"
#include "bool.h"
#include "objects/objects.h"
#include "vertigo.h"
#include "map.h"
#include "message.h"
#include "carrier.h"
#include "mymath.h"
#include "config.h"
#include "mgui/mgerror.h"

#include "sound.h"
#define ATCSPEED 1000

#define rnd(a)        random() % (int) a

// in VERTIGO.C 
extern int joyxzero,joyyzero,joyx,joyy,joy2xzero,joy2x,joy2y,joymask;
extern int hatup,hatdown,hatleft,hatright;
extern int throttle_idle, throttle_mil;
extern float joyxgain,joyygain,joy2xgain,joy2ygain;
extern int nullzone, joy_n_sample;
extern bool mouse_active;
extern int scrndiag;
extern float viewdist;
extern STICK s[1];
extern bool ctrlexpo, msec_running;

extern bool detail_prop, detail_jet; /*, body_gyro_active*/;
extern bool wind_active;
extern bool auto_coordination;
extern bool show_instruments;

extern short stick_type, throttle_type, rudder_type;

extern short current_model;

extern short ncalcperframe;

extern short ground_view;

extern short talk_volume, engine_volume, effect_volume;

extern void setup_graph();
extern void errormessage(char *text);
extern void errorexit(int fejl);
extern void Pause(int msec);

extern short groundtype;
extern int airfieldalt;

extern float time_of_day;

extern int star_mag_lim;
extern bool make_stars_bright;
extern float latitude;
extern float sidereal_time;
extern float start_fuel_fraction;
extern bool show_cockpit;
extern bool show_plane_inside;
extern bool smooth_pan;

extern int horizon_color;

extern int start_loc_selection;
extern int world;

extern int graphmode;

extern void init_wind(int center_dir, int scatter_dir);
extern void report_wind();

// In JOYSTICK.C 
extern unsigned int readjoy(STICK *s, int joymask);

// In MAP.C 
extern void init_map();

// In MYMATH.C 
cartvektor svmult(float a, cartvektor b);



void save_config(void)
{
 FILE *fp;

 if((fp=fopen(cnf_file,"wb"))==NULL)
   errormessage("Cannot create configuration file");
 fwrite(&stick_type        ,sizeof(short),1,fp);
 fwrite(&throttle_type     ,sizeof(short),1,fp);
 fwrite(&rudder_type       ,sizeof(short),1,fp);
 fwrite(&joyxzero          ,sizeof(int)  ,1,fp);
 fwrite(&joyyzero          ,sizeof(int)  ,1,fp);
 fwrite(&joy2xzero         ,sizeof(int)  ,1,fp);
 fwrite(&hatup             ,sizeof(int)  ,1,fp);
 fwrite(&hatdown           ,sizeof(int)  ,1,fp);
 fwrite(&hatleft           ,sizeof(int)  ,1,fp);
 fwrite(&hatright          ,sizeof(int)  ,1,fp);
 fwrite(&throttle_idle     ,sizeof(int)  ,1,fp);
 fwrite(&throttle_mil      ,sizeof(int)  ,1,fp);
 fwrite(&joyxgain          ,sizeof(float),1,fp);
 fwrite(&joyygain          ,sizeof(float),1,fp);
 fwrite(&joy2xgain         ,sizeof(float),1,fp);
 fwrite(&joy2ygain         ,sizeof(float),1,fp);
 fwrite(&nullzone          ,sizeof(int)  ,1,fp);
 fwrite(&joy_n_sample      ,sizeof(int)  ,1,fp);
 fwrite(&scrndiag          ,sizeof(int)  ,1,fp);
 fwrite(&viewdist          ,sizeof(float),1,fp);
 fwrite(&current_model     ,sizeof(short),1,fp);
 fwrite(&ctrlexpo          ,sizeof(bool) ,1,fp);
 fwrite(&ncalcperframe     ,sizeof(short),1,fp);
 fwrite(&groundtype        ,sizeof(short),1,fp);
 fwrite(&detail_prop       ,sizeof(bool) ,1,fp);
 fwrite(&detail_jet        ,sizeof(bool) ,1,fp);
 fwrite(&wind_active       ,sizeof(bool) ,1,fp);
 fwrite(&ground_view       ,sizeof(short),1,fp);
 fwrite(&talk_volume       ,sizeof(short),1,fp);
 fwrite(&engine_volume     ,sizeof(short),1,fp);
 fwrite(&effect_volume     ,sizeof(short),1,fp);
 fwrite(&auto_coordination ,sizeof(bool) ,1,fp);
 fwrite(&time_of_day       ,sizeof(float),1,fp);
 fwrite(&start_loc_selection ,sizeof(int)  ,1,fp);
 fwrite(&star_mag_lim      ,sizeof(int)  ,1,fp);
 fwrite(&make_stars_bright ,sizeof(bool) ,1,fp);
 fwrite(&latitude          ,sizeof(float),1,fp);
 fwrite(&sidereal_time     ,sizeof(float),1,fp);
 fwrite(&mouse_active      ,sizeof(bool) ,1,fp);
 fwrite(&show_instruments  ,sizeof(bool) ,1,fp);
 fwrite(&start_fuel_fraction, sizeof(float),1,fp);
 fwrite(&show_cockpit      ,sizeof(bool) ,1,fp);
 fwrite(&show_plane_inside ,sizeof(bool) ,1,fp);
 fwrite(&smooth_pan        ,sizeof(bool) ,1,fp);
 fwrite(&graphmode         ,sizeof(int)  ,1,fp);
 fclose(fp);
}



void load_conf_error()
{
 errormessage("Trouble reading configuration.\n\r Please delete the file `ver_cfg.*' and start again.");
}



void load_config(void)
{
 FILE *fp;

 if(!(fp=fopen(cnf_file,"rb"))) {
          errormessage("Cannot open configuration file.");
       }
 if(fread(&stick_type,sizeof(short),1,fp)!=1)
      load_conf_error();
 if(fread(&throttle_type,sizeof(short),1,fp)!=1)
      load_conf_error();
 if(fread(&rudder_type,sizeof(short),1,fp)!=1)
      load_conf_error();
 if(fread(&joyxzero,sizeof(int),1,fp)!=1)
      load_conf_error();
 if(fread(&joyyzero,sizeof(int),1,fp)!=1)
      load_conf_error();
 if(fread(&joy2xzero,sizeof(int),1,fp)!=1)
      load_conf_error();
 if(fread(&hatup,sizeof(int),1,fp)!=1)
      load_conf_error();
 if(fread(&hatdown,sizeof(int),1,fp)!=1)
      load_conf_error();
 if(fread(&hatleft,sizeof(int),1,fp)!=1)
      load_conf_error();
 if(fread(&hatright,sizeof(int),1,fp)!=1)
      load_conf_error();
 if(fread(&throttle_idle,sizeof(int),1,fp)!=1)
      load_conf_error();
 if(fread(&throttle_mil,sizeof(int),1,fp)!=1)
      load_conf_error();
 if(fread(&joyxgain,sizeof(float),1,fp)!=1)
      load_conf_error();
 if(fread(&joyygain,sizeof(float),1,fp)!=1)
      load_conf_error();
 if(fread(&joy2xgain,sizeof(float),1,fp)!=1)
      load_conf_error();
 if(fread(&joy2ygain,sizeof(float),1,fp)!=1)
      load_conf_error();
 if(fread(&nullzone,sizeof(int),1,fp)!=1)
      load_conf_error();
 if(fread(&joy_n_sample,sizeof(int),1,fp)!=1)
      load_conf_error();
 if(fread(&scrndiag,sizeof(int),1,fp)!=1)
      load_conf_error();
 if(fread(&viewdist,sizeof(float),1,fp)!=1)
      load_conf_error();
 if(fread(&current_model,sizeof(short),1,fp)!=1)
      load_conf_error();
 if(fread(&ctrlexpo,sizeof(bool),1,fp)!=1)
      load_conf_error();
 if(fread(&ncalcperframe,sizeof(short),1,fp)!=1)
      load_conf_error();
 if(fread(&groundtype,sizeof(short),1,fp)!=1)
      load_conf_error();
 if(fread(&detail_prop,sizeof(bool),1,fp)!=1)
      load_conf_error();
  if(fread(&detail_jet,sizeof(bool),1,fp)!=1)
      load_conf_error();
 if(fread(&wind_active,sizeof(bool),1,fp)!=1)
      load_conf_error();
 if(fread(&ground_view,sizeof(short),1,fp)!=1)
      load_conf_error();
 if(fread(&talk_volume,sizeof(short),1,fp)!=1)
      load_conf_error();
 if(fread(&engine_volume,sizeof(short),1,fp)!=1)
      load_conf_error();
 if(fread(&effect_volume,sizeof(short),1,fp)!=1)
      load_conf_error();
 if(fread(&auto_coordination,sizeof(bool),1,fp)!=1)
      load_conf_error();
 if(fread(&time_of_day,sizeof(float),1,fp)!=1)
      load_conf_error();
 if(fread(&start_loc_selection,sizeof(int),1,fp)!=1)
      load_conf_error();
 if(fread(&star_mag_lim,sizeof(int),1,fp)!=1)
      load_conf_error();
 if(fread(&make_stars_bright,sizeof(bool),1,fp)!=1)
      load_conf_error();
 if(fread(&latitude,sizeof(float),1,fp)!=1)
      load_conf_error();
 if(fread(&sidereal_time,sizeof(float),1,fp)!=1)
      load_conf_error();
 if(fread(&mouse_active,sizeof(bool),1,fp)!=1)
      load_conf_error();
 if(fread(&show_instruments,sizeof(bool),1,fp)!=1)
      load_conf_error();
 if(fread(&start_fuel_fraction,sizeof(float),1,fp)!=1)
      load_conf_error();
 if(fread(&show_cockpit,sizeof(bool),1,fp)!=1)
      load_conf_error();
 if(fread(&show_plane_inside,sizeof(bool),1,fp)!=1)
      load_conf_error();
 if(fread(&smooth_pan,sizeof(bool),1,fp)!=1)
      load_conf_error();
  if(fread(&graphmode,sizeof(int),1,fp)!=1)
      load_conf_error();
 fclose(fp);
}



void joy_center()
{
 readjoy(s,joymask);
 joyxzero=s->a[0];
 joyyzero=s->a[1];
 joy2xzero=s->a[2];
}



void define_start_loc_airfield(int selection)
{
 extern float x, y, z, azi, nosealt, roll, wfront, wleft, wtop, throttle, G;
 extern float desired_ldg_spd, setflap, flap;
 extern short ngears;
 extern cartvektor v;
 extern bool setgear, setabrk, whlbrakes;
 extern enum HUD_modes HUDmode;
 extern undercarriage gear[maxngears+maxnhardpts+1];
 extern int active_waypoint, rw_wpt_id;
 extern short njetengines;
 extern jetengine jengine[maxnjetengines+1];

 int i;

 world = EARTH;
 G = 9.82; // m/s^2

  switch(selection) {

  case RWY_00: /* On R/W */
      /* Start position */
      x = 1200;  /* 1200 meter for R/W */
      y = 0;
      z = 1.6;   /* 1.8 meter for R/W */
      if (groundalt(x,y) > 0) z += groundalt(x,y); /* Lift a/c to local ground altitude */

      /* Start velocity */
      v.x = 0.1;   /* meter/sec */
      v.y = 0.0;
      v.z = 0.0;

      /* Start attitude */
      azi     = 0.0;
      nosealt = 0.0;
      roll    = 0.0;

      azi     *= PI/180.;
      nosealt *= PI/180.;
      roll    *= PI/180;

      /* Start angular velocity */
      wfront = 0.0;      /* roll */ /* radians per sec. */
      wleft  = 0.0;      /* pitch */
      wtop   = 0.0;      /* yaw, spin */

      setgear   = true;  /* false : gear up */
      setabrk   = false; /* false: brake retracted */
      throttle  = 0;
      whlbrakes = false;
      active_waypoint = rw_wpt_id;

      if (njetengines > 0 && detail_jet) {
        int i;
        for (i=0; i<njetengines; i++)
          jengine[i].rpm=jengine[i].idle_rpm;
      }

      set_message("Player cleared for takeoff, runway 00",4,YELLOW);


		break;

  case RWY_00_FINAL: /* R/W final */
      /* Start position */
      x = -2000;
      y =     0;
      z =   groundalt(1200,0)+200;
      if (z < groundalt(x,y)) z=groundalt(x,y)+100;

      /* Start velocity (not corrected for wind) */
      v.x = desired_ldg_spd*0.5144*1.2;   /* meter/sec */
      v.y =   0.0;
      v.z =   0.0;

      /* Start attitude */
      azi     = 0.0;
      nosealt = 0.0;
      roll    = 0.0;

      azi     *= PI/180.;
      nosealt *= PI/180.;
      roll    *= PI/180;

      /* Start angular velocity */
      wfront = 0.0;      /* roll */ /* radians per sec. */
      wleft  = 0.0;      /* pitch */
      wtop   = 0.0;      /* yaw, spin */

      setgear   = true;  /* false : gear up */
      setabrk   = false; /* false: brake retracted */
      throttle  = 50;
      whlbrakes = false;
      setflap   = 24;
      flap      = setflap-0.1;
      HUDmode   = NAVIGATION;
      active_waypoint = rw_wpt_id;

      if (njetengines > 0 && detail_jet) {
        int i;
        for (i=0; i<njetengines; i++) {
          jengine[i].rpm=jengine[i].idle_rpm;
          jengine[i].throttle=throttle;
        }
      }

      set_message("Player cleared for landing, runway 00",4,YELLOW);

		break;


  case RWY_00_APPROACH: /* R/W approach */
      /* Start position */
      x = -8000+rnd(2000);
      y =  rnd(2000)-1000;
      z =  rnd(1000)+50;
      if (groundalt(x,y) > 0) z += groundalt(x,y);


      /* Start velocity (not corrected for wind) */
      v.x = desired_ldg_spd*0.5144;   /* meter/sec */
      v.y =   0.0;
      v.z =   0.0;
      v   = svmult(rnd(100)/100.0+1,v);

      /* Start attitude */
      azi     = 0.0;
      nosealt = 0.0;
      roll    = 0.0;

      azi     *= PI/180.;
      nosealt *= PI/180.;
      roll    *= PI/180;

      /* Start angular velocity */
      wfront = 0.0;      /* roll */ /* radians per sec. */
      wleft  = 0.0;      /* pitch */
      wtop   = 0.0;      /* yaw, spin */

      setgear   = false;  /* false : gear up */
      setabrk   = false; /* false: brake retracted */
      throttle  = 50;
      whlbrakes = false;
      setflap   = 0;
      HUDmode   = NAVIGATION;
      for (i=0; i<ngears; i++)
          if (gear[i].downrate>0) gear[i].down=0;
      active_waypoint = rw_wpt_id;

      if (njetengines > 0 && detail_jet) {
        int i;
        for (i=0; i<njetengines; i++) {
          jengine[i].rpm=jengine[i].idle_rpm;
          jengine[i].throttle=throttle;
        }
      }

      set_message("Player cleared for landing, runway 00",4,YELLOW);

		break;


  case TARMAC: /* Tarmac */
      /* Start position */
      x = 2050;
      y =  140;
      z =    1.6;
      z += groundalt(x,y); /* Lift a/c to local ground altitude */

      /* Start velocity */
      v.x = 0.1;   /* meter/sec */
      v.y = 0.0;
      v.z = 0.0;

      /* Start attitude */
      azi     =270.0;
      nosealt =  0.0;
      roll    =  0.0;

      azi     *= PI/180.;
      nosealt *= PI/180.;
      roll    *= PI/180;

      /* Start angular velocity */
      wfront = 0.0;      /* roll */ /* radians per sec. */
      wleft  = 0.0;      /* pitch */
      wtop   = 0.0;      /* yaw, spin */

      setgear   = true;  /* false : gear up */
      setabrk   = false; /* false: brake retracted */
      throttle  = 0;
      whlbrakes = true;
      active_waypoint = rw_wpt_id;

      if (njetengines > 0 && detail_jet) {
        int i;
        for (i=0; i<njetengines; i++)
          jengine[i].rpm=0;
      }

      set_message("Player cleared for taxi, runway 00",4,YELLOW);

		break;



case HIGH_ALT: /* High altitude: 50.000 ft, 500 kts TAS */
      /* Start position */
      x = -175.*1000.*1.852; // 175nm from base
      y =      0.;
      z =  50000. * 0.3048;
     
      /* Start velocity */
      v.x = 257.;   /* meter/sec */
      v.y = 0.0;
      v.z = 0.0;

      /* Start attitude */
      azi     =  0.0;
      nosealt =  0.0;
      roll    =  0.0;

      azi     *= PI/180.;
      nosealt *= PI/180.;
      roll    *= PI/180;

      /* Start angular velocity */
      wfront = 0.0;      /* roll */ /* radians per sec. */
      wleft  = 0.0;      /* pitch */
      wtop   = 0.0;      /* yaw, spin */

      setgear   = false;  /* false : gear up */
      setabrk   = false; /* false: brake retracted */
      throttle  = 0;
      whlbrakes = false;
	  setflap   = 0;
      HUDmode   = NAVIGATION;
	  for (i=0; i<ngears; i++)
          if (gear[i].downrate>0) gear[i].down=0;
      active_waypoint = rw_wpt_id;

      if (njetengines > 0 && detail_jet) {
        int i;
        for (i=0; i<njetengines; i++)
          jengine[i].rpm=jengine[i].idle_rpm;
      }

      set_message("Player released from mother aircraft",4,YELLOW);

      break;

		

  default:;
  }
}



void define_start_loc_carrier(int selection)
{
 extern float x, y, z, azi, nosealt, roll, wfront, wleft, wtop, throttle, G;
 extern float desired_ldg_spd, setflap, flap;
 extern short ngears;
 extern cartvektor v;
 extern bool setgear, setabrk, whlbrakes, sethook;
 extern undercarriage gear[maxngears+maxnhardpts+1];
 extern enum HUD_modes HUDmode;
 extern int active_waypoint, carr_wpt_id;
 extern float carr_init_tid;
 extern short njetengines;
 extern jetengine jengine[maxnjetengines+1];


 int i;
 
 world = EARTH;
 G = 9.82; // m/s^2
 
  switch(selection) {

  case CARR_DECK: /* Carrier: on deck */
      {
      extern float wind_direction;

      float approach_head=wind_direction /* +9.2 */ ;

      cartvektor c_pos=get_carrier_pos();
      cartvektor c_spd;
      float      c_abs_spd;

      /* Start position */
      /* start_loc_selection=10; */

      x = c_pos.x-87*cos((float)PI*approach_head/180);
      y = c_pos.y-87*sin((float)PI*approach_head/180);
      z = c_pos.z+20+1.8;

      c_spd=get_carrier_speed(x,y);
      c_abs_spd=sqrt(SQR(c_spd.x)+SQR(c_spd.y));
      /* Start velocity */
      v.x =   c_abs_spd*cos((float)PI*approach_head/180);   /* meter/sec */
      v.y =   c_abs_spd*sin((float)PI*approach_head/180);
      v.z =   0.0;

      /* Start attitude */
      azi     = approach_head+9.2;
      nosealt = 0.0;
      roll    = 0.0;

      azi     *= PI/180.;
      nosealt *= PI/180.;
      roll    *= PI/180.;

      /* Start angular velocity */
      wfront = 0.0;      /* roll */ /* radians per sec. */
      wleft  = 0.0;      /* pitch */
      wtop   = 0.0;      /* yaw, spin */

      setgear   = true;  /* false : gear up */
      setabrk   = false; /* false: brake retracted */
      throttle  = 0;
      whlbrakes = true;
      active_waypoint = carr_wpt_id;
      }

      if (njetengines > 0 && detail_jet) {
        int i;
        for (i=0; i<njetengines; i++)
          jengine[i].rpm=jengine[i].idle_rpm;
      }

      play_rdo_wav(WIND_AXI_WAV, 255, 128, ATCSPEED);
      set_message("99 Battlestar, winds axial at 25 knots",4,YELLOW);

      carr_init_tid = 0; /* Carrier must be level at start */

		break;

  case CARR_FINAL: /* Carrier final */
      {
      extern float wind_direction;

      float approach_head=wind_direction+9.2;
      float start_dist=desired_ldg_spd*40;    /* 40. org val., 20 for ball test */
      cartvektor c_pos=get_carrier_pos();

      /* Start position */
      /* start_loc_selection=11; */

      x = c_pos.x-start_dist*cos((float)PI*approach_head/180);
      y = c_pos.y-start_dist*sin((float)PI*approach_head/180);
      z = 0.061*start_dist+20;
      /* if (groundalt(x,y) > 0) z += groundalt(x,y); */ /* Lift a/c to local ground altitude */

      /* Start velocity (not corrected for wind)*/
      v.x = desired_ldg_spd*0.5144*1.1*cos((float)PI*approach_head/180);   /* meter/sec */
      v.y = desired_ldg_spd*0.5144*1.1*sin((float)PI*approach_head/180);
      v.z =   0.0;

      /* Start attitude */
      azi     = approach_head;
      nosealt = 0.0;
      roll    = 0.0;

      azi     *= PI/180.;
      nosealt *= PI/180.;
      roll    *= PI/180;

      /* Start angular velocity */
      wfront = 0.0;      /* roll */ /* radians per sec. */
      wleft  = 0.0;      /* pitch */
      wtop   = 0.0;      /* yaw, spin */

      setgear   = true;  /* false : gear up */
      setabrk   = true; /* false: brake retracted */
      setflap   = 24;
      flap      = setflap-0.1;
      sethook   = true;
      throttle  = 50;
      whlbrakes = false;
      HUDmode   = ILS;
      active_waypoint = carr_wpt_id;
      }

      if (njetengines > 0 && detail_jet) {
        int i;
        for (i=0; i<njetengines; i++) {
          jengine[i].rpm=jengine[i].idle_rpm;
          jengine[i].throttle=throttle;
        }
      }

      play_rdo_wav(WIND_AXI_WAV, 255, 128, ATCSPEED);
      set_message("99 Battlestar, winds axial at 25 knots",4,YELLOW);

      carr_init_tid = rnd(300)/10;

      break;

  case CARR_APPROACH:  /* Carrier approach */
      {
      extern float wind_direction;

      float approach_head=wind_direction+9.2;
      float start_dist=desired_ldg_spd*80;
      cartvektor c_pos=get_carrier_pos();

      /* Start position */
      /* start_loc_selection=12; */

      x = c_pos.x-start_dist*cos((float)PI*approach_head/180);
      x+= rnd(6000)-3000;
      y = c_pos.y-start_dist*sin((float)PI*approach_head/180);
      y+= rnd(6000)-3000;
      z = 0.061*start_dist+20;
      z+= rnd(500);

      if (groundalt(x,y) > 0) z+= groundalt(x,y);  /* Lift a/c to local ground altitude */

      /* Start velocity (not corrected for wind)*/
      v.x = desired_ldg_spd*0.5144*1.1*cos((float)PI*approach_head/180);   /* meter/sec */
      v.y = desired_ldg_spd*0.5144*1.1*sin((float)PI*approach_head/180);
      v.z =   0.0;
      v   = svmult(rnd(100)/100.0+1,v);

      /* Start attitude */
      azi     = approach_head;
      nosealt = 0.0;
      roll    = 0.0;

      azi     *= PI/180.;
      nosealt *= PI/180.;
      roll    *= PI/180;

      /* Start angular velocity */
      wfront = 0.0;      /* roll */ /* radians per sec. */
      wleft  = 0.0;      /* pitch */
      wtop   = 0.0;      /* yaw, spin */

      setgear   = false;  /* false: gear up */
      setabrk   = false;  /* false: brake retracted */
      setflap   = 0;
      sethook   = false;
      throttle  = 50;
      whlbrakes = false;
      HUDmode   = NAVIGATION;
      for (i=0; i<ngears; i++)
          if (gear[i].downrate>0) gear[i].down=0;
      }
      active_waypoint = carr_wpt_id;

      if (njetengines > 0 && detail_jet) {
        int i;
        for (i=0; i<njetengines; i++) {
          jengine[i].rpm=jengine[i].idle_rpm;
          jengine[i].throttle=throttle;
        }
      }

      play_rdo_wav(WIND_AXI_WAV, 255, 128, ATCSPEED);
      set_message("99 Battlestar, winds axial at 25 knots",4,YELLOW);

      carr_init_tid = rnd(300)/10;

      break;

  case CARR_CAT: /* Carrier: on catapult */
      {
      extern float wind_direction;
      extern int   on_catapult;
      extern int   poly_plane_id[nmodels];

      cartvektor c_pos=get_carrier_pos();
      cartvektor c_spd;
      float      c_abs_spd;

      cartvektor cat_pos[4];
      float      cat_dir[4];

      float cos_front = cos((float)PI*wind_direction/180.0);
      float sin_front = sin((float)PI*wind_direction/180.0);

      cat_pos[0].x = -22.5+1;
      cat_pos[0].y =  33.0;
      cat_pos[0].z =  20.0;
      cat_dir[0]   =   0.000;

      cat_pos[1].x =  -2.7+1;
      cat_pos[1].y =  20.8;
      cat_pos[1].z =  20.0;
      cat_dir[1]   =   5.149;

      cat_pos[2].x =  89.0+1;
      cat_pos[2].y =   6.4;
      cat_pos[2].z =  20.0;
      cat_dir[2]   =   1.525;

      cat_pos[3].x =  94.3+1;
      cat_pos[3].y = -17.2;
      cat_pos[3].z =  20.0;
      cat_dir[3]   =   5.026;

      on_catapult = rnd(4)+1;

      /* Start position */

      x = c_pos.x+cat_pos[on_catapult-1].x*cos_front
                 -cat_pos[on_catapult-1].y*sin_front;

      y = c_pos.y+cat_pos[on_catapult-1].x*sin_front
                 +cat_pos[on_catapult-1].y*cos_front;

      z = c_pos.z+cat_pos[on_catapult-1].z+1.8;

      c_spd=get_carrier_speed(x,y);
      c_abs_spd=sqrt(SQR(c_spd.x)+SQR(c_spd.y));

      /* Start velocity */
      v.x =   c_abs_spd*cos_front;   /* meter/sec */
      v.y =   c_abs_spd*sin_front;
      v.z =   0.0;

      /* Start attitude */
      azi     = wind_direction + cat_dir[on_catapult-1];

      cos_front = cos((float)PI*azi/180.0);
      sin_front = sin((float)PI*azi/180.0);

      x -= gear[steerwhlid].hingepos.x*cos_front -
           gear[steerwhlid].hingepos.y*sin_front;

      y -= gear[steerwhlid].hingepos.x*sin_front +
           gear[steerwhlid].hingepos.y*cos_front;

      nosealt = 0.0;
      roll    = 0.0;

      azi     *= PI/180.;
      nosealt *= PI/180.;
      roll    *= PI/180.;

      /* Start angular velocity */
      wfront = 0.0;      /* roll */ /* radians per sec. */
      wleft  = 0.0;      /* pitch */
      wtop   = 0.0;      /* yaw, spin */

      setgear   = true;  /* false : gear up */
      setabrk   = false; /* false: brake retracted */
      setflap   = 24;
      flap      = setflap-0.1;
      throttle  = 0;
      whlbrakes = false;
      active_waypoint = carr_wpt_id;

      /* Only F-14 can be launched */
      if (poly_plane_id[current_model]!=F14)
         on_catapult=0;
      }

      if (njetengines > 0 && detail_jet) {
        int i;
        for (i=0; i<njetengines; i++)
          jengine[i].rpm=jengine[i].idle_rpm;
      }

      play_rdo_wav(WIND_AXI_WAV, 255, 128, ATCSPEED);
      set_message("99 Battlestar, winds axial at 25 knots",4,YELLOW);

      carr_init_tid = 0; /* Carrier must be level at start */

		break;

  default:;
  }
}



void define_start_loc_moon(int selection)
{
 extern float x, y, z, azi, nosealt, roll, wfront, wleft, wtop, throttle, G;
 extern float  setflap; // desired_ldg_spd, flap;
 extern short ngears;
 extern cartvektor v;
 extern bool setgear, setabrk, whlbrakes;
 extern enum HUD_modes HUDmode;
 extern undercarriage gear[maxngears+maxnhardpts+1];
 extern int active_waypoint, rw_wpt_id;
 extern short njetengines;
 extern jetengine jengine[maxnjetengines+1];
 extern bool rcs_control;

 int i;

  world = MOON;
  G = 9.82 * 0.17; // m/s^2
  rcs_control = true;

  switch(selection) {

  case MOON_SURF: /* On R/W */
      /* Start position */
      x = 1200;
      y = 200;
      z = 2.5;
      if (groundalt(x,y) > 0) z += groundalt(x,y); /* Lift a/c to local ground altitude */

      /* Start velocity */
      v.x = 0.1;   /* meter/sec */
      v.y = 0.0;
      v.z = 0.0;

      /* Start attitude */
      azi     = 0.0;
      nosealt = 0.0;
      roll    = 0.0;

      azi     *= PI/180.;
      nosealt *= PI/180.;
      roll    *= PI/180;

      /* Start angular velocity */
      wfront = 0.0;      /* roll */ /* radians per sec. */
      wleft  = 0.0;      /* pitch */
      wtop   = 0.0;      /* yaw, spin */

      setgear   = true;  /* false : gear up */
      setabrk   = false; /* false: brake retracted */
      throttle  = 0;
      whlbrakes = false;
      active_waypoint = rw_wpt_id;

      if (njetengines > 0 && detail_jet) {
        int i;
        for (i=0; i<njetengines; i++)
          jengine[i].rpm=jengine[i].idle_rpm;
      }

      set_message("Houston, Tranquility base here. The Eagle has landed!",4,YELLOW);


		break;



case MOON_ALT: /* Descent, "Low Gate" */
      /* Start position */
      x =    500.;
      y =      0.;
      z =    156.;
	  if (groundalt(x,y) > 0) z += groundalt(x,y); /* Lift a/c to local ground altitude */
     
      /* Start velocity */
      v.x = 20.7;   /* meter/sec */
      v.y =  0.0;
      v.z = -4.9;

      /* Start attitude */
      azi     =  0.0;
      nosealt =  0.0;
      roll    =  0.0;

      azi     *= PI/180.;
      nosealt *= PI/180.;
      roll    *= PI/180;

      /* Start angular velocity */
      wfront = 0.0;      /* roll */ /* radians per sec. */
      wleft  = 0.0;      /* pitch */
      wtop   = 0.0;      /* yaw, spin */

      setgear   = true;  /* false : gear up */
      setabrk   = false; /* false: brake retracted */
      throttle  = 0;
      whlbrakes = false;
      setflap   = 0;
      HUDmode   = NAVIGATION;
	  for (i=0; i<ngears; i++)
          if (gear[i].downrate>0) gear[i].down=0;
      active_waypoint = rw_wpt_id;

      if (njetengines > 0 && detail_jet) {
        int i;
        for (i=0; i<njetengines; i++)
          jengine[i].rpm=jengine[i].idle_rpm;
      }

      set_message("Prepare for descent",4,YELLOW);

      break;

  default:;
  }
}

