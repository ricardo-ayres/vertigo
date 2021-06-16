/* Vertigo main programme */

/*
    This file is part of the source code for the Vertigo flight simulator
    Copyright (C) 1998-2002 Anton Norup Soerensen, a_norup@post.tele.dk

    This program is free software; you can redistribute it and/or modify
    it under the terms of the GNU General Public License as published by
    the Free Software Foundation; either version 2 of the License, or
    (at your option) any later version.

    This program is distributed in the hope that it will be useful,
    but WITHOUT ANY WARRANTY; without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
    GNU General Public License for more details.

    You should have received a copy of the GNU General Public License
    along with this program; if not, write to the Free Software
    Foundation, Inc., 675 Mass Ave, Cambridge, MA 02139, USA.
*/

#include <stdio.h>
#include <math.h>
#ifndef LINUX
#  include <bios.h>
#else
#  include <string.h>
#endif

#include <float.h>


#include "bool.h"
#include "objects/objects.h"
#include "vertigo.h"
#include "mymath.h"

#ifdef MGUI
#  include "mgui.h" // Not needed for djgpp
#  include "mgui/mgmenus.h"
#  include "mgui/mgerror.h"
#endif

#ifdef CGUI
#  include <cgui.h>
#  include "cgui/cgmenus.h"
#endif

#ifndef LINUX
#  include <pc.h>
#endif
#define  rnd(a)        random() % (int) a

#include "map.h"
#ifdef TIMESTAT
#  include "timestat.h"
#endif
#include "joystick.h"
#include "polygrap.h"
#include "config.h"
#include "mtable.h"
#include "message.h"
#include "carrier.h"
#include "aoa360.h"
#include "blt_inst.h"
#include "astro.h"
#include "gen_wing.h"
#include "accel.h"

#include <allegro.h>
#include "sound.h"

#define DBUF

/* Contains current model */
wingspecs		wingsection[maxnwingsections+1];
aeroelement		element[maxnelements+1];  /* +1 for at undgaa fejl ved n..=0 */
jetengine		jengine[maxnjetengines+1];
rocketengine	rengine[maxnrocketengines+1];
propengine		pengine[maxnpropengines+1];
undercarriage	gear[maxngears+maxnhardpts+1];
arrestor_hook	hook;
cannon			gun[maxnguns+1];
tank			fueltank[maxnfueltanks+1];
a_brake			airbrake;
ctrl_props		controls;
instrum_par		instrum;

int   nwingsections, nelements;
short njetengines, npropengines, nrocketengines, ngears, nhardpts, nguns, nfueltanks;
short current_model=5; /* Corsair=1, F14=5 */ /* Overskrives af VER_CNF.*CC Se mtable.c for numre */

float elevator_gain, aileron_gain, rudder_gain;
float elevator_vmax, aileron_vmax, rudder_vmax;

char modelname[70];

/* Contains all models */
planemodel modeltable[nmodels];

cartvektor pilotpos;

cartvektor front, left, top, acc,v, prev_v, avg_v;
cartvektor cg;
float avg_accleft=0;
float avg_acctop=0;
float last_ballangle=0;

float pitch, yaw, prev_pitch, prev_yaw, avg_pitch, avg_yaw;
float dt=0;
float dtperframe=0;
long  ncalc,nframes;
short ncalcperframe=6;
short calcnumber;
float wfront,wleft,wtop;
float waccfront,waccleft,wacctop;
float aileron,elevator,rudder,tail_rudder,wheel_rudder,throttle;
int   prop_ctrl=100;
float setrudder=0;
float flap,setflap,flapresponse, slat_eff;
float noflapfrontarea,noflapdragcoeff,noflapcurvature,noflapdeflect;
float nooutflapfrontarea,nooutflapdragcoeff,nooutflapcurvature,nooutflapdeflect;
float noflap_front_liftcenter;
float flap_cp_travel;
float rho_fuel;
bool  setgear, setabrk;
bool  whlbrakes=false;

float G = 9.82; // m/s^2

bool  show_hud  = true;
bool  color_hud = false;
int   hud_red   = LIGHTGREEN;
int   hud_blue  = LIGHTGREEN;
int   hud_white = LIGHTGREEN;
enum  HUD_modes HUDmode = NAVIGATION;

bool  show_instruments = true;

bool  show_ctrlpos=false;
bool  stall_horn_on=false;
float stall_angle=10.0*(PI/180);
float aircraft_mach_number=0;

float front_superdrag, left_superdrag, top_superdrag;
float superdragfak;

bool show_cockpit      = true;
bool show_plane_inside = true;

bool  playing_gear_rumble=false;
float gear_rumble_strength;

/* For auto-coordination */
bool  auto_coordination=false;
float prev_rudder_deflect=0;

/* Save some time: */
float cos_roll, sin_roll, cos_nosealt, sin_nosealt, cos_azi, sin_azi;
float int_cos[91], int_sin[91];

bool  sethook=false;
int   last_hook_status=-1;
int   wire_trap=0;
bool  bolter_status=false;

/* F-14 only */
float sweep        =20.0;
float set_sweep    =20.0;
float manual_sweep = false;
float glove_vane   = 0.0;
float desire_vane  = 0.0;
float set_stb_spoiler  = 0.0;
float set_port_spoiler = 0.0;
float stb_spoiler  = 0.0;
float port_spoiler = 0.0;
float DLC_spoiler  = 0.0;
bool  DLC_active   = false;
aeroelement outer_wing;
aeroelement inner_wing;
aeroelement no_glove_body;
tank        outer_wing_tank;

bool eagle_landed = false;
unsigned long int lm_call_wait=0;

bool rcs_control = false; 

/* Auto-throttle (F-14 and LM only) */
bool  auto_throttle= false;
float auto_throttle_setting=0;
float auto_throttle_integrator=0;
float last_throttle_error_signal=0;
float last_pitch=0;

/* For guns */
bool       fire_guns           = false;
bool       shot_fired          = false;
projectile bullet[maxnbullets];
int        nactive_bullets     = 0;
int        last_fired_bullet   =-1;
#define    nlcos_bullets        30
projectile lcos_bullet[nlcos_bullets];
int        nlcos_bullets_flying= 0;

int start_loc_selection=RWY_00;
int world = EARTH;

/* bool bounce_kludge = false; */

/* Graphics variables */
bool  paging;
int   xpixels,ypixels,xcenter,ycenter;
float xpixperrad,ypixperrad,xscl,yscl;
int   scrndiag;
float scrnwidth,scrnheight,viewdist,cos_diag;
bool many_colors=true;
short colortable[16][16];
int refresh_palette = 0;
int   gmode;
int graphmode = R640X480;

PALETTE verpal;

BITMAP *page1, *page2;
BITMAP *active_page;

DATAFILE *data;
FONT *font_big;
FONT *font_med;
FONT *font_sml; 

/* For player viewpoint */
short viewpoint=0;
cartvektor viewfront,viewleft,viewtop;
float viewx,viewy,viewz;
float traildist        = 100;
float panhoriz         = PI;
float panvert          = 0;
float panhoriz_int     = 0;
float panvert_int      = 0;
float set_traildist    = 100;
float set_panhoriz     = PI;
float set_panvert      = 0;
float set_panhoriz_int = 0;
float set_panvert_int  = 0;
bool  smooth_pan       = true;
int   panhorizsgn      = 1;

/* For controls */
int       joyxzero,joyyzero,joyx,joyy,joy2xzero,joy2x,joy2y;
int       hatup,hatdown,hatleft,hatright;
float     joyxgain,joyygain,joy2xgain,joy2ygain;
int       throttle_idle, throttle_mil;
int       joymask        =15;
bool      hatisleft      = false;
bool      hatisright     = false;
int       nullzone       =20;
int       joy_n_sample   = 1;
int       elevatortrim   = 0;
int       ailerontrim    = 0;
int       ruddertrim     = 0;
short     stick_type     = 0;
short     throttle_type  = 0;
short     rudder_type    = 0;
bool      ctrlexpo       = true;
bool      whlbrkbtn      = false;

bool joystick_active     = false;

const int    mousenullz     = 6;
bool         mouse_active   = false;
bool         mouse_avail    = true;
//GrMouseEvent mouse_status;

/* Plane position and attitude */
float x,y,z;
float azi,nosealt,roll;

short groundtype=1; /* Fractal landscape as default */
int airfieldalt=0;

float tas, ias;
float lastgroundalt = 0;

float gpull;
float gnegmax=1.0;
float gposmax=1.0;

bool crash=false;
bool calc_all;
bool detail_prop=true;
bool detail_jet=true;
/* bool body_gyro_active=false; */
bool wind_active=true;

bool show_map=false;
short map_zoom=(mapsize-1)/8;

cartvektor wind,v_air;
float wind_direction, wind_speed;

int ground_view=8;

float meatball_tilt, ldg_aim_offset, desired_ldg_spd, desired_ldg_AOA;

/* For msec timer */
unsigned long int starttick,pausetick,lasttick,startpausetick,fire_t_start;
unsigned long int ticks_8h;
bool msec_running=false;
float joytid;

float time_of_day  = 12.0;
float running_time = 0;
float elapsed_time = 0;
float last_palette_time = 0;

bool failure_upcoming=false;
unsigned long int failure_time;

unsigned long int enter_cat_time=0;
float last_warn_time=0;

/* Visual objects */
bool center_ok[maxnobjects];

int  poly_plane_id[nmodels]={T17,CORSAIR,U2,F104,HARRIER,F14,T17,X15,LM}; /* link polygon model to aircraft */
int  cockpit_id[nmodels]={T17_CP,CORSAIR_CP,U2_CP,F104_CP,HARRIER_CP,F14_CP,T17_CP,F104_CP,HARRIER_CP};

object3D object[maxnobjects];
int nobjects=0;

objectpos file_objectpos[maxnposobj];
int       nobjectpos=0;

poly_scrcoord poly_queue[max_poly_queue_length];
int poly_queue_length=0;

cartvektor sun;
float sun_hour;

int horizon_color=GREEN;

int nwaypoints=0;
int active_waypoint=0;
int rw_wpt_id, carr_wpt_id=-1;

waypoint waypointlst[maxnwaypoints];

short talk_volume  =255;
short engine_volume=255;
short effect_volume=128;

float carr_init_tid=  0;
int   on_catapult  =  0;
int   cat_phase    =  0;

/* Stars */
int star_mag_lim       = 5;
bool make_stars_bright = false;
float latitude         = 55.66 * PI / 180.0; /* Copenhagen */ 
/* 6.0: Midnight winter */
float sidereal_time    = 6.0; /* Hours */

/* Targets */
int ntargets = 5;
int selected_target = 0;
target_specs target[maxntargets];

/* For low-pass filtering of instrument output */
float last_ftmin   = 0;
float last_feet    = 0;
float last_ias     = 0;
float filter_const = 0;

/* Fuel */
float start_fuel_fraction = 1.0;
float total_fuel          = 0;
float total_fuel_flow     = 0;

bool ab_ignition = FALSE;
bool ab_burning  = FALSE;
bool ab_starting = FALSE;
bool ab_stopping = FALSE;

bool engineering_mode = false;

// For logging of flight data
bool logging = FALSE;
char logname[12];
logstr logdata;
float next_log_time, start_log_time;
float log_period = 1.0; // Seconds
int nlogentries = 0;
FILE *log_fp;

/* External global variables and procedures/functions */
/* In MYMATH.C */
extern float arccos(float v);
extern float arcsin(float v);
extern int sgn(float x);
extern cartvektor vkryds(cartvektor a, cartvektor b);
extern cartvektor vplus(cartvektor a, cartvektor b);
extern cartvektor vminus(cartvektor a, cartvektor b);
extern cartvektor svmult(float a, cartvektor b);
extern float degtorad(float v);

#ifdef MATRIX
  /* 3D geometry by matrices - not used, just for demo */
  extern void translate3D(cartvektor a, mat4 b);
  extern void scale3D(cartvektor a, mat4 b);
  extern void matrix_mult444(mat4 a, mat4 b, mat4 c);
  extern cartvektor matrix_mult411(mat4 a, cartvektor b);
  extern void rot3D(float theta, int ax, mat4 b);
  extern void genrot3D(cartvektor p, cartvektor q, float gamma, mat4 r);
#endif

/* Pre-declaration */
void init_wind(int center_dir, int scatter_dir);
void report_wind();
void init_targets();
void fill_fuel_tanks();
void setup_cockpit_panning();
void close_log();
void write_log();
void keyinput();

/* In JOYSTICK.C */
extern STICK s[1];


#include "graphics.c"



void warningmessage(char *text)
{
 #ifdef MGUI
 mgwarning(text);
#else
 printf(text);
 printf("\n\r");
#endif
}



void errormessage(char *text)
{
 #ifdef MGUI
 mgerror(text);
#else
 printf(text);
 printf("\n\r");
 errorexit(1);
#endif
}



void set_view_geometry()
{
/* Reference: min 14" skaerm har bredde 27 cm og hoejde 20 cm */
 scrnwidth= (float) 0.27*scrndiag/14;
 scrnheight= (float) 0.20*scrndiag/14;
 xpixperrad=xpixels/(2*atan((scrnwidth/2)/viewdist));
 ypixperrad=ypixels/(2*atan((scrnheight/2)/viewdist));
 xcenter=xpixels/2;
 ycenter=ypixels/2;
 xscl= (float) xpixels/640;
 yscl= (float) ypixels/480; /* Skalering relativt til 640*480 */
 /* retningsvektor prik synsvektor > cos_diag hvis synlig */
 cos_diag=viewdist/sqrt(SQR(scrndiag*2.54/(2.0*100.0))+SQR(viewdist));
}



void flip()
{
#ifndef DBUF
 show_video_bitmap(active_page);

 if (active_page == page1) {
   active_page = page2;
 }
 else {
   active_page = page1;
 }
#else
 blit(page2, screen, 0, 0, 0, 0, SCREEN_W, SCREEN_H);
#endif
}



int setup_graph()
{
 extern void setviewpoint();

 int scx=0, scy=0;
 int i;

 paging=true;

 set_color_depth(8); // 8 BPP - hopefully soon to increase!?

 switch(graphmode) {
   case  R640X480: scx =  640; scy = 480; break;
   case  R800X600: scx =  800; scy = 600; break;
   case R1024X768: scx = 1024; scy = 768; break;
 }

 if (set_gfx_mode(GFX_AUTODETECT, scx, scy, 0, 2*scy) != 0) {
      if (set_gfx_mode(GFX_SAFE, scx, scy, 0, 0) != 0) {
         set_gfx_mode(GFX_TEXT, 0, 0, 0, 0);
         allegro_message("Unable to set any graphic mode\n%s\n", allegro_error);
         return 1;
      }
 }

#ifndef DBUF
 page1 = create_video_bitmap(SCREEN_W, SCREEN_H);
 page2 = create_video_bitmap(SCREEN_W, SCREEN_H);

 if ((!page1) || (!page2)) {
      set_gfx_mode(GFX_TEXT, 0, 0, 0, 0);
      allegro_message("Unable to create two video memory pages\n");
      return 1;
 }

 active_page = page2;

#else

 page2 = create_bitmap(SCREEN_W, SCREEN_H);

 active_page = page2;

#endif

 

 set_palette(default_palette);
 for (i=0; i<256; i++)
      verpal[i] = default_palette[i];
 text_mode(-1);
  
 xpixels=SCREEN_W;
 ypixels=SCREEN_H;

 set_view_geometry();

 setviewpoint();

 return 0;
}




void check_equip()
{
#ifndef LINUX

 #define CO_PROCESSOR_MASK 0x0002

 int equip_check;
 #ifndef MGUI
 int status;
 #endif

 /* get the current equipment configuration */
 equip_check = biosequip();

 /* check to see if there is a coprocessor installed */
 if (equip_check & CO_PROCESSOR_MASK)
   {
 #ifndef MGUI
    //printf("Math coprocessor detected.\n\r");
 #endif
   }
 else
    errormessage("No math coprocessor installed.\nVertigo will not run.");

 #ifndef MGUI
 /* Check if analog joystick is supported */
 status=readjoy(s,15);
 if (status & 1)
	printf("Analog channel #1 NOT operative\n\r");
 else
	printf("Analog channel #1 connected\n\r");
 if (status & 2)
	printf("Analog channel #2 NOT operative\n\r");
 else
	printf("Analog channel #2 connected\n\r");
 if (status & 4)
	printf("Analog channel #3 NOT operative\n\r");
 else
	printf("Analog channel #3 connected\n\r");
 if (status & 8)
	printf("Analog channel #4 NOT operative\n\r");
 else
	printf("Analog channel #4 connected\n\r");
 #endif
#endif

#ifndef LINUX

 if (readjoy(s,3)) {
    joystick_active=false;
    if (!mouse_avail)
         errormessage("No joystick or mouse found.\nVertigo cannot run.");
 }
 else
   joystick_active=true;

#endif

}



void update_clock()
{
 ticks_8h++;
}



void init_mouse()
{
  if (!install_mouse())
	errormessage("No mouse found.\nVertigo cannot run.");

  set_mouse_range(0, 0, SCREEN_W-1, SCREEN_H-1); //Default values
  position_mouse(xpixels/2,ypixels/2);
}



void load_objects()
{
 FILE *fp;
 int i;


 if(!(fp=fopen("objects/objects.dat","rb"))) {
          errormessage("Cannot read OBJECTS/OBJECTS.DAT");
       }

 if(fread(&object,sizeof(object3D)*maxnobjects,1,fp)!=1)
      errormessage("Error while reading objects.");

 for (i=0; i<maxnobjects; i++) {
     int j, nfacets;

     nfacets=object[i].nfacets;

     for (j=0; j<object[i].nctrl_srf; j++) nfacets+=object[i].ctrl_surface[j].nctrlpoly;

       if ((object[i].vertex = malloc(object[i].nvertices*sizeof(cartvektor))) == NULL)
          errormessage("Not enough memory.");

       if ((object[i].facet = malloc(nfacets*sizeof(polygon_struct))) == NULL)
         errormessage("Not enough memory.");

       fread(object[i].vertex, object[i].nvertices*sizeof(cartvektor), 1, fp);
       fread(object[i].facet,  nfacets*sizeof(polygon_struct), 1, fp);
 }
 fclose(fp);
}



void load_object_pos()
{
 FILE *fp;
 char string[80];

 if ((fp=fopen("objects/objects.pos","r")) == NULL)
        errormessage("Cannot open file: OBJECTS/OBJECTS.POS\n\r");

 fscanf(fp,"%s", string);
 while(!feof(fp)) {
       if (string[0]=='#') {
         bool endfound = false;
         char ch;
         while(!feof(fp) && !endfound) {
          fscanf(fp, "%c", &ch);
          if ( ch == 10 ) endfound = true;
         }
       }
       else {
         sscanf(string, "%d", &file_objectpos[nobjectpos].object);

         if (!feof(fp)) {
           fscanf(fp, "%f", &file_objectpos[nobjectpos].pos.x);
         }
         else errormessage("Error in file format: OBJECTS/OBJECTS.POS\n\r");
         if (!feof(fp)) {
           fscanf(fp, "%f", &file_objectpos[nobjectpos].pos.y);
         }
         else errormessage("Error in file format: OBJECTS/OBJECTS.POS\n\r");
         if (!feof(fp)) {
           fscanf(fp, "%f", &file_objectpos[nobjectpos].pos.z);
         }
         else errormessage("Error in file format: OBJECTS/OBJECTS.POS\n\r");
         if (!feof(fp)) {
           fscanf(fp, "%f", &file_objectpos[nobjectpos].rot);
         }
         else errormessage("Error in file format: OBJECTS/OBJECTS.POS\n\r");
         if (!feof(fp)) {
           int draw_now;
           fscanf(fp, "%d", &draw_now);
           file_objectpos[nobjectpos].draw_now=(bool)draw_now;
         }
         else errormessage("Error in file format: OBJECTS/OBJECTS.POS\n\r");

/*
         sprintf(string, "%d %f %f %f %f %d",
               file_objectpos[nobjectpos].object,
               file_objectpos[nobjectpos].pos.x,
               file_objectpos[nobjectpos].pos.y,
               file_objectpos[nobjectpos].pos.z,
               file_objectpos[nobjectpos].rot,
               file_objectpos[nobjectpos].draw_now);
         warningmessage(string);
*/
         nobjectpos++;
       }
       fscanf(fp,"%s", string);
 }
 fclose(fp);
}






int init()
{
 int i;
 int analog_status=15; /* Default: No channels working */
 bool mousebtn=false;

 check_equip();

 allegro_init();
 /* Init msec clock */
 msec_running=true;
 install_timer();
 install_int(update_clock, 1000 / tickspersec);

 install_keyboard();

 init_sound();

 data = load_datafile("fonts.dat");
 if (!data) {
      set_gfx_mode(GFX_TEXT, 0, 0, 0, 0);
      allegro_message("Error loading fonts\n");
      return 1;
 }

 for (i=0; i<91; i++) {
   int_sin[i]=sin(degtorad(i));
   int_cos[i]=cos(degtorad(i));
 }

 if(access(cnf_file,0)) { /* VER_CNF.* NOT present */

#ifdef LINUX
printf("%s missing, so we start configuring.\n", cnf_file);
#endif
   scrndiag=16;
   viewdist=0.20;
   if (mouse_avail) {
      joystick_active=false;
      mouse_active=true;
      show_ctrlpos=true;
   }
 }
 else {               /* VER_CNF.*CC present */
#ifndef LINUX
     readjoy(s,joymask);
     /*mousebtn=(mouse_b != 0);*/
#endif
     if ((s->b[0]==1) || (mousebtn==true)) {
       scrndiag=16;
       viewdist=0.40;
       /* select_magnif(); */
       }
     else {
     load_config();
   }
 }


 joymask=3;
 if (throttle_type==1) joymask=joymask | 8;
 if (rudder_type  ==1) joymask=joymask | 4;

 /* Test if joystick configuration is working properly */
 /* Will silently disable non-working functions */
#ifndef LINUX
 analog_status=readjoy(s,joymask);
#endif
 if (analog_status & 3)
    stick_type=0;
 if (analog_status & 4)
    rudder_type=0;
 if (analog_status & 8) {
    throttle_type=0;
    if (stick_type==2)
       stick_type=1;
 }

 if (stick_type)
    mouse_active=false;

 #ifndef NO_RANDOMIZE
  srandom(time(0));
 #endif

 message_reset();
 set_message("Welcome to Vertigo.    Press [ESC] for main menu.",4,YELLOW);

 init_mtable();
 load_objects();
 load_object_pos();
 init_airfield_lights();

 select_model(current_model);
 fill_fuel_tanks();

#ifdef CGUI
 main_menu_cgui(true);
#endif
#ifdef MGUI
 main_menu_form(true);
#endif

 running_time = time_of_day;

 if (start_loc_selection >= MOON_SURF) world = MOON;
 if(start_loc_selection <= TARMAC)
   init_wind( 0,  30);
 else
   init_wind( 0, 179);
 report_wind();
 update_windbag();

 if (groundtype > 0) {
    cartvektor pos;

    init_map();
    pos=find_lowest_point();
    init_carrier(pos.x,pos.y);
 }
 else init_carrier(20,20);
 init_waypoints();

 init_targets();

 update_sun(running_time);

 /* Centrerede styreflader */
 aileron    = 0;
 rudder     = 0;
 tail_rudder= 0;
 elevator   = 0;
 flap       = 0;
 setflap    = 0;

 init_aoa_data();

 init_stars();

 if( (start_loc_selection <= TARMAC) || (start_loc_selection == HIGH_ALT) )
      define_start_loc_airfield(start_loc_selection);
 else {
	if (start_loc_selection <= CARR_CAT)
		define_start_loc_carrier(start_loc_selection);
	else
		define_start_loc_moon(start_loc_selection);
 }     

 if (groundtype > 0) {
    cartvektor c_pos=get_carrier_pos();
    float prev_alt, prev_groundalt;

    prev_groundalt=groundalt(x,y);
    if (prev_groundalt < 0) prev_groundalt=0;
    prev_alt=z-prev_groundalt;

    while ( (HUDmode==ILS && groundalt(x,y) > 0) || groundalt(c_pos.x,c_pos.y) > -1000 ) {
     /* HUDmode==ILS means we are on final to carrier */
     init_map();
     c_pos=get_carrier_pos();
    }
    create_sea();
    if (start_loc_selection <= TARMAC  || start_loc_selection== CARR_APPROACH) {
       z = groundalt(x,y)+prev_alt;
    }
 }
 last_feet = z / 0.3048;

 setup_graph();

 if (SCREEN_W > 800) {
  font_big = (FONT *)find_datafile_object(data, "fnt8x8")->dat;
  font_med = (FONT *)find_datafile_object(data, "fnt7x8")->dat;
  font_sml = (FONT *)find_datafile_object(data, "fnt5x6")->dat;
 } 
 else {
  font_big = (FONT *)find_datafile_object(data, "fnt7x8")->dat;
  font_med = (FONT *)find_datafile_object(data, "fnt5x6")->dat;
  font_sml = (FONT *)find_datafile_object(data, "fnt4x5")->dat;
 }

 if (mouse_active) {
    init_mouse();
    show_ctrlpos=true;
 }

 make_instruments();

 init_prop_graph();

 /* Init average velocity-vector */
 prev_v=v;
 avg_v=v;
 pitch=yaw=0;

 /* No bullets in the air */
 for (i=0; i<maxnbullets; i++) bullet[i].active=false;

 ncalc=0;
 nframes=0;

 /* Init msec clock */
 msec_running=true;
 ticks_8h  = 0;
 starttick = 0;
 lasttick  = 0;
 pausetick = 0;

#ifdef TIMESTAT
 /* For timing statistics */
 clock_reset();
 clock_set_name( 0,"Graphics in total");
 clock_set_name( 1,"Flight model in total");
 clock_set_name( 2,"Polygon Z-sorting");
 clock_set_name( 3,"Polygon drawing");
 clock_set_name( 4,"Clrscr + horizon");
 clock_set_name( 5,"filled_poly_to_queue (fptq)");
 clock_set_name( 6,"draw_poly_plane   - fptq");
 clock_set_name( 7,"map_to_poly_queue - fptq");
 clock_set_name( 8,"draw_object       - fptq");
 clock_set_name( 9,"fptq:calc_line_project");
 clock_set_name(10,"fptq:calc_frame_line");
 clock_set_name(11,"fptq:3D-transform");
 clock_set_name(12,"fptq:Place lines");
 clock_set_name(13,"HUD");
 clock_set_name(14,"Instruments");
#endif

 if (joystick_active) { /* Joystick */
    /* Find ud af, hvor lang tid det tager at laese joystick */
    /* Er korrektion ordentligt maskin-uafhaengig? */
    ticks_8h=0;
    for (i=0 ; i<500 ; i++) polljoy(s, 0, joymask, 1, 0);
    /* joytid=2.0*(float)ticks_8h/1145.0; */ /* tweaket manuelt */
    joytid=ticks_8h/(float)tickspersec;
 }
 else joytid=0;
 ticks_8h=100; /* To avoid zero time step on first iteration */

 return 0;
}



void finish()
{
#ifdef TIMESTAT
 int i;
#endif

 flip();

 textprintf(screen, font, 0, 2*text_height(font), makecol(255,255,255), "Seconds:     %5.1f", (lasttick+nframes*joytid)/(float)tickspersec);
 textprintf(screen, font, 0, 4*text_height(font), makecol(255,255,255), "Ncalc/sec:   %5.1f", ncalc*(float)tickspersec/lasttick);
 textprintf(screen, font, 0, 6*text_height(font), makecol(255,255,255), "Nframes/sec: %5.1f", nframes*(float)tickspersec/lasttick);
 
#ifdef TIMESTAT
 textprintf(screen, font, 10, 13*text_height(font), makecol(255,255,0), "Time usage in percent:");
 for (i=0; i<NCLOCKS; i++) {
	textprintf(active_page, font, 10, (14+i)*text_height(font), makecol(255,255,0), clock_read_name(i));
    //moveto(200,(14+i)*textheight(" "));
    printfg((clock_read(i)/(lasttick+nframes*joytid))*1000,4,4);
 }
#endif

 while(keypressed()) readkey();

 if (!mouse_active) { /* Joystick */
	textprintf(screen, font, 0, 11*text_height(font), makecol(255,0,0), "Press joystick button #1 or a key to exit");
  do { /* Wait for player to release button */
	readjoy(s,joymask);
	Pause(50);
     } while (s->b[0]==1);
  do {
	readjoy(s,joymask);
	Pause(50);
     } while (s->b[0]==0 && !keypressed());
 }
 else {  /* mouse */
		textprintf(screen, font, 0, 11*text_height(font), makecol(255,0,0), "Press mouse button #1 or a key to exit");
  do {
  } while(mouse_b);
  do {
  } while(!keypressed() && !(mouse_b));
 }
 if (keypressed())
   readkey();
 if (logging) close_log();
 msec_running=false;
 destroy_bitmap(page1);
 destroy_bitmap(page2);
 exit_sound();
 unload_datafile(data);
 allegro_exit();
 while(keypressed()) readkey();
 save_config();
}



void errorexit(int fejl)
{
 /* To be used instead of exit() to avoid timer-crash etc. */
 /* Use parameter 0 for quick exit, 1 for key-pause */
#ifndef LINUX
 if (fejl==0) ; // clrscr();
 else {
  //printf("Hit any key to exit.\n\r");
  //while(!keypressed());
  //readkey();
 }
#endif
 if (logging) close_log();
 msec_running=false;
 exit_sound();
 allegro_exit();
 exit(fejl);
}



void Pause(int msec)
{
 if (msec_running==true)
     rest(msec);
 else
  #ifndef LINUX
     delay(msec);
  #else
     usleep(msec*1000L);
  #endif
}



void open_log()
{
	char msgstr[255];
	bool nofile = FALSE;
	int i=0;

	while (nofile == FALSE) {
		i++;
		sprintf(logname,"fdata%03d.log",i);
		if ((log_fp=fopen(logname,"r")) == NULL) nofile = TRUE;
		else fclose(log_fp);
	}
	
	if ((log_fp=fopen(logname,"w")) == NULL) {
		sprintf(msgstr,"Cannot open file: %s\n\r",logname);
		errormessage(msgstr);
	}

	sprintf(msgstr,"Logging to file %s", logname);
	set_message(msgstr,2,YELLOW);
	next_log_time  = running_time;
	start_log_time = running_time;
	nlogentries=0;
}



void close_log()
{
	set_message("Closing log",2,YELLOW);
	fclose(log_fp);
	logging = false;
}



void write_log()
{
	char text[255];
	sprintf(text, "%6.2f   %6.2f   %6.2f   %6.2f   %6.2f   %6.2f   %6.2f   %6.2f   %6.2f   %6.2f   %6.2f   %6.2f   %6.2f   %6.2f   %6.2f   %6.2f\n",(running_time-start_log_time)*3600.,
		logdata.x, logdata.y, logdata.z,
		logdata.omega_front, logdata.omega_left, logdata.omega_top,
		logdata.v_z,
		logdata.tas, logdata.ias, logdata.mach,
		logdata.AoA, logdata.yaw,
		logdata.acc_front, logdata.acc_left, logdata.acc_top );
	fprintf(log_fp, text);
	nlogentries++;
	next_log_time = start_log_time + nlogentries * log_period / 3600.0;
}


void analoginput()   /* Modtag kontrolkommandoer via joystick / mus */
{


 if (mouse_active){

   joyx = mouse_x - xpixels/2;
   if (joyx>0) { joyx -= mousenullz; if (joyx<0) joyx=0; }
   else { joyx += mousenullz; if (joyx>0) joyx=0;}
   joyx *= 3;
   joyx += ailerontrim;
   if (fabs(joyx) > 300) joyx=sgn(joyx)*300;

   joyy = mouse_y - ypixels/2;
   if (joyy>0) { joyy -= mousenullz; if (joyy<0) joyy=0; }
   else { joyy += mousenullz; if (joyy>0) joyy=0;}
   joyy *= 3;
   joyy -= elevatortrim;
   if (fabs(joyy) > 300) joyy=sgn(joyy)*300;

/*
   if (mouse_status.key)
   printf("Analoginput: Key %d Kbdstat %d\n\r",mouse_status.key,mouse_status.kbstat);
*/

  /* Emulate joystick buttons */
   if (mouse_b & 1)
      s->b[0]=true;
   else
      s->b[0]=false;

     if (mouse_b & 2)
      s->b[1]=true;
   else
      s->b[1]=false;

/*
   printf("flags %d  buttons %d  key %d  kbstat %d\n\r",mouse_status.flags,mouse_status.buttons,mouse_status.key,mouse_status.kbstat);
*/

 }
 else {
   readjoy (s,joymask);

   joyx=s->a[0]-joyxzero;
   if (joyx>0) { joyx -= nullzone; if (joyx<0) joyx=0; }
   else { joyx += nullzone; if (joyx>0) joyx=0;}
   joyx *= joyxgain;
   joyx += ailerontrim;
   /* Korrektion for asymmetrisk maksimalt udslag: */
   /* Faktor 300 stammer fra config.c */
   /* Nullzone ignoreres */
   if (fabs(joyx) > 300) joyx=sgn(joyx)*300;

   joyy=s->a[1]-joyyzero;
   if (joyy>0) { joyy -= nullzone; if (joyy<0) joyy=0; }
   else { joyy += nullzone; if (joyy>0) joyy=0;}
   joyy *= joyygain;
   joyy -= elevatortrim;
   if (fabs(joyy) > 300) joyy=sgn(joyy)*300;
 }

 if (rudder_type==1) { /* Rudder pedals */
   joy2x=s->a[2]-joy2xzero;
   if (joy2x>0) { joy2x -= nullzone; if (joy2x<0) joy2x=0; }
   else { joy2x += nullzone; if (joy2x>0) joy2x=0;}

   setrudder    = rudder_gain*joy2x*joy2xgain;
   wheel_rudder = setrudder;
   if (fabs(wheel_rudder) > 25) wheel_rudder=sgn(wheel_rudder)*25;
   setrudder   += ruddertrim*0.1;
   if (fabs(setrudder) > 25) setrudder=sgn(setrudder)*25;
 }

 if (throttle_type==1) { /* Analog throttle */
   joy2y=s->a[3];
   throttle=100-(100.0*(joy2y-throttle_mil))/(throttle_idle-throttle_mil);
   if (throttle > 100) throttle=100;
   if (throttle <   0) throttle=  0;
   if (auto_throttle)
      if ( (poly_plane_id[current_model]==F14) &&
		   (throttle > 80  || throttle < 10)   ) auto_throttle=false;
 }

 /* Fire-button */
 if (s->b[0]==true) {
   if (fire_guns==false) {
     unsigned long int nowtick=ticks_8h;
     int i;
     for (i=0; i<nguns; i++) gun[i].t_last_shot=nowtick-tickspersec/gun[i].fire_rate;
     fire_guns=true;
   }
 }
 else fire_guns=false;

 /* Hjul-bremser */
 if (s->b[1]==true)
	{whlbrakes=true; whlbrkbtn=true;}
 else if (whlbrkbtn==true)
	{whlbrkbtn=false; whlbrakes=false;}

 if (stick_type==2) {   /* Hat */
  joy2y=s->a[3]*joy2ygain;

  if (abs(joy2y-hatup)<100   && elevatortrim < 300 ) elevatortrim++;
  if (abs(joy2y-hatdown)<100 && elevatortrim > -300) elevatortrim--;
  if (abs(joy2y-hatleft)<100)  {viewpoint=2; hatisleft=true;}
	else if (hatisleft==true)   {viewpoint=0; hatisleft=false;}
  if (abs(joy2y-hatright)<100) {viewpoint=3; hatisright=true;}
	else if (hatisright==true)  {viewpoint=0; hatisright=false;}
 }

 if (ctrlexpo==true) {
   /* Normal max linear udslag 300 */
   float norm;
   norm=(float) joyx/300;
   joyx=150*(norm+/*2**/pow(norm,5));
   norm=(float) joyy/300;
   joyy=150*(norm+/*2**/pow(norm,5));
   /* tilsvarende for rudder senere */
 }

 {  /* Aileron stuff */
 extern float atmospheric_density(float z);

 float desire,dail,daildt;

 ias = tas / sqrt(1.225/atmospheric_density(z));

 desire=aileron_gain*joyx*(0.10/3); /* 10 deg stroke */

 if (ias > aileron_vmax)
    desire /= SQR( ias / aileron_vmax);

 /*
 setcolor(YELLOW);
 moveto(10*xscl,10*yscl);
 if (ias > aileron_vmax)
   printfg(100./SQR( ias / aileron_vmax),6,5);
 else
   printfg(100,6,5);
 */

 desire -= aileron;

 if (poly_plane_id[current_model]==F14) {
    element[2].top.deflect= 0;
    element[1].top.deflect= 0;
    set_stb_spoiler           = 0;
    set_port_spoiler          = 0;

    if (DLC_active) {
       set_port_spoiler += DLC_spoiler/55.0;
       set_stb_spoiler  += DLC_spoiler/55.0;
    }
 }

 if (desire!=0)
 {
  daildt=controls.aileronrate*dtperframe;
  if (fabs(desire)>daildt)
     dail=daildt*sgn(desire);
   else
     dail=desire;
  aileron+=dail;
 }
  if (poly_plane_id[current_model]==F14) {
    element[1].top.deflect=-aileron;
    element[2].top.deflect= aileron;
    if (sweep < 55) {
      if (aileron > 0)
        /* Non-linear differential spoiler response for smooth
           low speed flight */
        set_stb_spoiler  +=  0.5*SQR(aileron/10);  /* aileron/20 */
      else
        set_port_spoiler +=  0.5*SQR(aileron/10);

      if (set_port_spoiler > 1) set_port_spoiler=1;
      if (set_stb_spoiler  > 1) set_stb_spoiler =1;
    }
  }
  else {
    element[stbaileronid].top.deflect=-aileron;
    element[portaileronid].top.deflect=aileron;
  }
 }

 { /* Elevator */
 float desire,delev,delevdt;

 desire=elevator_gain*joyy*(0.20/3); /* 20 deg stroke */

 if (ias > elevator_vmax)
    desire /= SQR( ias / elevator_vmax);

 desire -= elevator;


 if (desire!=0)
 {
  delevdt=controls.elevatorrate*dtperframe;
  if (fabs(desire)>delevdt)
     delev=delevdt*sgn(desire);
   else
     delev=desire;
  elevator+=delev;
 }
  if (poly_plane_id[current_model]==F14) {
    element[1].top.deflect -= elevator;
    element[2].top.deflect -= elevator;
  }
  else
    element[elevatorid].top.deflect = -elevator;
 }


 if ( rudder_type==1 ) {
 float desire, desire_whl, drud, druddt;

 if (ctrlexpo==true) {
   /* max linear udslag 25 for rudder */
   float norm;
   norm=(float) setrudder/25;
   desire=(1.5*8.33)*(norm+/*2**/pow(norm,5));
   /* tilsvarende for joyx,y tidligere */

   norm=(float) wheel_rudder/25;
   desire_whl=8.33*(norm+2*pow(norm,5));
 }
 else {
   desire=setrudder;
   desire_whl=wheel_rudder;
 }
 desire/=2;

 if (ias > rudder_vmax)
    desire /= SQR( ias / rudder_vmax);

 desire-=rudder;
 if (desire!=0)
 {
  druddt=controls.rudderrate*dtperframe;
  if (fabs(desire)>druddt)
     drud=druddt*sgn(desire);
   else
     drud=desire;
  rudder+=drud;
  if (poly_plane_id[current_model]==F14)
    element[3].left.deflect=-rudder*1.5;
  else
    element[rudderid].left.deflect=-rudder*1.5;
  tail_rudder=rudder*1.5;

  gear[steerwhlid].steer=desire_whl;
 }
 }
}



#include "fltmodel.c"



#include "instrum.c"



/*
#ifdef MATRIX
  #include "matrix.c"
#endif
*/



#ifdef MGUI
void MGUIMain(int argc, char *argv[])
#else
int main(int argc, char *argv[])
#endif
{
 int i;

 /* DISABLE SOUND UNTIL FIXED */
 set_nosound();
 /*
 for (i=1; i<argc; i++) {
   if (!strcmp(argv[i],"-nosound")) set_nosound();
 }
 */

 init();

 analoginput();
 engine_sound(true);
 if (keypressed()) keyinput();
 findangles();
 while (crash == false)
 {
  unsigned long int nowtick=ticks_8h;

  dtperframe  = (nowtick-starttick-pausetick-lasttick)/(float)tickspersec;
  dtperframe += joytid/tickspersec;
  lasttick    = nowtick-starttick-pausetick;
  dt          = dtperframe/ncalcperframe;
  elapsed_time= (lasttick/(float)tickspersec)/3600.0;
  running_time= time_of_day+elapsed_time;

  /* seems to take on strange values on first iteration */
#ifdef TIMESTAT
  clock_start(0);
#endif
  visual();
  /* plotaero(); */
#ifdef TIMESTAT
  clock_stop(0);
#endif

  analoginput();

#ifdef TIMESTAT
  clock_start(1);
#endif

  calc_all=true;
  
  for (calcnumber=0; calcnumber < ncalcperframe; calcnumber++)
  {
   if (keypressed()) keyinput();
   findangles();
   if ( poly_plane_id[current_model] == LM ) {
	   if (auto_throttle) update_LM_auto_throttle();
	   LM_descent_callout();
   }
   updaterpm();
   updateflap();
   updatevector();
   updategear();
   updateairbrake();
   updatehook();
   
   if ( poly_plane_id[current_model] == F14 ) {
      updatesweep();
      updatesweepfltmodel();
      update_glove_vane();
      update_DLC();
      update_spoilers();
      if (auto_throttle) update_F14_auto_throttle();
      update_catapults();
   }

   update_JBD();
   findaccel();
   applyaccel();
   motion();
   update_carrier();
   ncalc++;
   
   if ((z-groundalt(x,y)) < 0 && crash==false) {
     crash=true;
     calcnumber=ncalcperframe;
     play_wav(CRASH_WAV, 255, 180, 1000, false);
   }

  } // endfor calcnumber
  LSO_comms();
  update_bullets();
  update_targets();
  update_stall_horn();
  update_gear_rumble();
  update_panning();
  
#ifdef TIMESTAT
  clock_stop(1);
#endif
  nframes++;
  flip();

   if (refresh_palette) {
      refresh_palette++;
      if (refresh_palette > 2) {
		  setviewpoint();
		  setup_palette();
	  }
   }

   if ((running_time-last_palette_time) > (1.0 / 3600.0)) // Every sec 
     setup_palette();

   if(logging) {
	   if (running_time > next_log_time )
			write_log();
   }

 } // endwhile !crash
 engine_sound(false);
 if (ab_burning)
        ab_sound(false);
 if (playing_gear_rumble) {
    play_gear_rumble(0);
    playing_gear_rumble=false;
 }
 finish();
#ifndef MGUI
 return(0);
#endif
}

END_OF_MAIN()
