#include <stdlib.h>
#include <math.h>
#include <stdio.h>
#include <string.h>
#include "bool.h"
#include "objects/objects.h"
#include "vertigo.h"
#include "polygrap.h"
#ifdef TIMESTAT
#  include "timestat.h"
#endif
#include "carrier.h"
#include "message.h"
#include "map.h"
#  include "sound.h"
#  define LSOSPEED 1000



/* In MYMATH.C */
cartvektor vplus(cartvektor a, cartvektor b);
cartvektor vminus(cartvektor a, cartvektor b);
cartvektor vkryds(cartvektor a, cartvektor b);
cartvektor svmult(float a, cartvektor b);
extern int sgn(float x);
#include "mymath.h"

/* In GRAPHICS.C */
void sort_poly_queue(void);
void draw_poly_queue(void);
void draw_object(int id, cartvektor pos);

static cartvektor carrier_pos, carrier_vel;
static ori_vector carr_orient;
static float carr_azi, carr_nosealt, carr_roll;
static float carrier_speed;
static const float carr_roll_period =15.0/(2*PI);
static const float carr_pitch_period=25.0/(2*PI);
static const float carr_heave_period=25.0/(2*PI);
/* According to Flight of the Intruder, heave period is 8 sec! */
static float carr_roll_ampl;
static float carr_pitch_ampl;
static float carr_heave_ampl;
static float carr_omega_roll=0;
static float carr_omega_pitch=0;
static float carr_omega_top=0;
static float carr_omega_top_max=0.5*PI/180;
static cartvektor wire_pos[4][2];
/* For ILS */
#define      V_DECK        (9.20*PI/180)
static float sin_v_deck;
static float cos_v_deck;
#define      V_GLIDE       (3.5*PI/180)
static float sin_v_glide, sin_v_glidePI2;
static float cos_v_glide, cos_v_glidePI2;
static float cos_carr_azi, sin_carr_azi;
/* For LSO */
static bool  guiding   = false;
static int   ldg_phase = 0;
static unsigned long int guide_wait;

static bool waveoff_lamp = false;
static unsigned long int waveoff_time = 0;

static int n_sum;
static float slope_err, lineup_err, /* speed_err,*/ AOA_err, roll_err;
static bool forgot_hook, forgot_gear;
static bool ILS_always_off, HUD_always_off;
static bool auto_coord_always_off, wind_always_active;
static bool pengine_always_real /*, anti_bounce_always_off*/;
static bool auto_throttle_always_off;

static light lightlist[NCARRIERLIGHTS];

static cartvektor cat_ini[4];
static cartvektor cat_dirvect[4];
static float      cat_dir[4];
static cartvektor cat_pos;
static float      cat_time;
static float      rail_pos;
static float      v_cat;
static int        cat_wait;
static float      JBD_pos[4];
static int        fuel_playlist[4];
static int        fuel_play_id;
static int        fuel_play_delay;

static float      average_AoA;
static unsigned long int AoA_sample_time;

extern int        cat_phase;
extern int        on_catapult;
extern unsigned long int enter_cat_time;

extern unsigned long int lasttick;
extern int nwaypoints, carr_wpt_id;
extern waypoint waypointlst[maxnwaypoints];




void init_carrier(int xpos, int ypos)
{
 extern float wind_direction, wind_speed;

 carrier_pos.x=1000.0*xpos;
 carrier_pos.y=1000.0*ypos;
 carrier_pos.z=0;

 carr_azi=wind_direction;
 carr_nosealt=0;
 carr_roll=0;

 carr_azi     *= PI/180;
 carr_nosealt *= PI/180;
 carr_roll    *= PI/180;

 /* For ILS */
 cos_carr_azi=cos(carr_azi);
 sin_carr_azi=sin(carr_azi);
 sin_v_deck  = sin(V_DECK);
 cos_v_deck  = cos(V_DECK);
 sin_v_glide = sin(V_GLIDE);
 cos_v_glide = cos(V_GLIDE);
 sin_v_glidePI2 = sin(V_GLIDE+PI/2);
 cos_v_glidePI2 = cos(V_GLIDE+PI/2);


 carrier_speed=25*0.5144-wind_speed; /* Target speed 25 kts */
 if (carrier_speed < 0) carrier_speed=0;

 carrier_vel.x = carrier_speed*cos((float)PI*wind_direction/180);
 carrier_vel.y = carrier_speed*sin((float)PI*wind_direction/180);
 carrier_vel.z = 0;

 carr_roll_ampl  = ( 0.8*3.0 * wind_speed/16) * (PI/180);  /* rad */
 carr_pitch_ampl = ( 0.8*1.5 * wind_speed/16) * (PI/180);  /* rad */
                  /* ^ max ampl. in degrees */
 carr_heave_ampl = ( 0.8*1.5 * wind_speed/16);             /* meters */
                  /* ^ max ampl. in meters */
                                   /* ^   max. wind speed */
 carr_orient.rot=true;

 if (carr_wpt_id==-1) { /* First call: not defined */
    carr_wpt_id=nwaypoints;
    nwaypoints++;
 }
 waypointlst[carr_wpt_id].pos.x=carrier_pos.x;
 waypointlst[carr_wpt_id].pos.y=carrier_pos.y;
 waypointlst[carr_wpt_id].pos.z=carrier_pos.z;
 strcpy(waypointlst[carr_wpt_id].ident,"NIMITZ");

 /* Arrestor wires */
 {
 float v=9.20*PI/180;
 float sin_v=sin(v);
 float cos_v=cos(v);
 float yc_0= 18.6;
 float xc_0=-78.4;
 int i;

 for (i=0; i<4; i++){
  float b=35.2;
  float l=12.43;
  float xc=xc_0+(l*i)*cos_v;
  float yc=yc_0+(l*i)*sin_v;

  wire_pos[i][0].x= xc;
  wire_pos[i][0].y= yc;
  wire_pos[i][0].z= 20.0;

  wire_pos[i][1].x= xc+sin_v*b;
  wire_pos[i][1].y= yc-cos_v*b;
  wire_pos[i][1].z= 20.0;

  JBD_pos[i]=0;
  }
 }
 init_carrier_lights();
 init_catapults();

 update_carrier();
}



void update_carrier()
{
 extern float dt;
 extern unsigned long int lasttick;
 extern long nframes;
 extern float joytid;
 extern float carr_init_tid;

 cartvektor top0, left0;

 float tid=carr_init_tid+(lasttick+nframes*joytid)/(float)tickspersec;

 carrier_pos.x += carrier_vel.x * dt;
 carrier_pos.y += carrier_vel.y * dt;
 waypointlst[carr_wpt_id].pos.x=carrier_pos.x;
 waypointlst[carr_wpt_id].pos.y=carrier_pos.y;
 waypointlst[carr_wpt_id].pos.z=carrier_pos.z;

 carr_roll     = carr_roll_ampl *sin(tid/carr_roll_period);
 carr_nosealt  = carr_pitch_ampl*sin(tid/carr_pitch_period);
 carrier_pos.z = carr_heave_ampl*sin(tid/carr_heave_period);

 carr_orient.front.x=cos(carr_azi)*cos(carr_nosealt);
 carr_orient.front.y=sin(carr_azi)*cos(carr_nosealt);
 carr_orient.front.z=sin(carr_nosealt);

 /* Overhead vektor for roll=0 */
 top0.x=cos(carr_azi)*cos(carr_nosealt+PI/2);
 top0.y=sin(carr_azi)*cos(carr_nosealt+PI/2);
 top0.z=sin(carr_nosealt+PI/2);

 /* Bagbord vektor for roll=0 */
 left0=vkryds(top0,carr_orient.front);

 /* Bagbord vektor */
 carr_orient.left=vplus(svmult(cos(carr_roll),left0),svmult(sin(carr_roll),top0));

 /* Overhead vektor */
 carr_orient.top=vkryds(carr_orient.front,carr_orient.left);

 carr_omega_roll  =( carr_roll_ampl/ carr_roll_period)*cos(tid/ carr_roll_period);
 carr_omega_pitch =(carr_pitch_ampl/carr_pitch_period)*cos(tid/carr_pitch_period);

 if (groundalt(carrier_pos.x+carrier_vel.x*200,carrier_pos.y+carrier_vel.y*200) > 0) {
    /* Ground collission imminent */
    if (carr_omega_top < carr_omega_top_max)
       carr_omega_top += carr_omega_top_max*dt/10;
 }
 else if (carr_omega_top != 0) {
    carr_omega_top -= carr_omega_top_max*dt/100;
    if (carr_omega_top < 0) carr_omega_top=0;
 }
 if (carr_omega_top != 0) {
    carr_azi     += carr_omega_top*dt;
    carrier_vel.x = carrier_speed*cos(carr_azi);
    carrier_vel.y = carrier_speed*sin(carr_azi);
    cos_carr_azi  = cos(carr_azi);
    sin_carr_azi  = sin(carr_azi);
 }
}



cartvektor get_carrier_pos()
{
 return(carrier_pos);
}



cartvektor get_carrier_speed(float x, float y)
{
 float xc,yc,zc=20.0;
 cartvektor transf,locv;
 cartvektor loc_vel=carrier_vel;

 transf.x=x-carrier_pos.x;
 transf.y=y-carrier_pos.y;
 transf.z=20.0;

 xc=VPRIK(carr_orient.front, transf);
 yc=VPRIK(carr_orient.left, transf);

 locv.x =  0;
 locv.y = -carr_omega_roll*zc;  /* Fortegn OK */
 locv.z =  carr_omega_roll*yc;  /* Fortegn OK */
 locv.z+=  carr_omega_pitch*xc; /* Fortegn OK */
 locv.y =  carr_omega_top*xc;

 loc_vel=vplus(loc_vel,svmult(locv.y,carr_orient.left));
 loc_vel=vplus(loc_vel,svmult(locv.z,carr_orient.top));

 /* Oevrige komponenter regnes for negligible */

 return(loc_vel);
}



float carrier_deck_alt(float x, float y)
{
 float xc,yc,zc;
 cartvektor transf;
 bool on_deck=true;

 transf.x=x-carrier_pos.x;
 transf.y=y-carrier_pos.y;
 transf.z=20.0;

 xc=VPRIK(carr_orient.front, transf);
 yc=VPRIK(carr_orient.left, transf);

 if (xc >  199.3) on_deck=false;
 if (xc < -132.3) on_deck=false;
 if (yc >   41.8) on_deck=false;
 if (yc <  -34.8) on_deck=false;
 if (on_deck) {
    if ((xc > 119.1) && (yc > -0.07856*xc+28.86)) on_deck=false; /* 1-2 */
    if ((xc > 119.1) && (yc <  0.09227*xc-31.59)) on_deck=false; /* 0-3 */
    if ((xc >  92.8) && (xc < 119.1) && (yc > -0.84791*xc+ 120.49)) on_deck=false; /* 2-4 */
    if ((xc >  98.0) && (xc < 119.1) && (yc <  0.67299*xc- 100.75)) on_deck=false; /* 3-7 */
    if ((xc >  48.2) && (xc <  65.7) && (yc >  0.29143*xc+  22.65)) on_deck=false; /* 5-6 */
    if ((xc > -86.5) && (xc <  48.2) && (yc > -0.00891*xc+  37.13)) on_deck=false; /* 6-8 */
 }
 if (on_deck) {
    if ((xc > -91.8) && (xc < -86.5) && (yc >  3.45283*xc+ 336.57)) on_deck=false; /* 8-9 */
    if ((xc >-131.0) && (xc < -91.8) && (yc >  0.07398*xc+  26.39)) on_deck=false; /* 9-12 */
    if ((xc >-132.3) && (xc <-131.0) && (yc >  7.76923*xc+1034.47)) on_deck=false; /* 12-13 */
    if ((xc >-132.3) && (xc <-127.7) && (yc < -6.21739*xc+ 829.16)) on_deck=false; /* 13-14 */
    if ((xc >-127.7) && (xc <-114.7) && (yc <  0.10769*xc-   8.25)) on_deck=false; /* 14-15 */
    if ((xc >-114.7) && (xc <-110.0) && (yc < -1.08511*xc- 145.06)) on_deck=false; /* 15-16 */
    if ((xc >-110.0) && (xc < -80.1) && (yc < -0.10368*xc  -37.10)) on_deck=false; /* 16-10 */
    if ((xc >- 80.1) && (xc < -78.7) && (yc < -4.28571*xc- 372.09)) on_deck=false; /* 10-11 */
 }

 if (on_deck) {
  zc  = 20.0+carrier_pos.z;
  zc += carr_orient.left.z*yc;
  zc += carr_orient.front.z*xc;
  if ((xc < -4.0) && (xc > -41.4) && (yc < -25.0) && (yc > -32.8)) zc += 16.2;
  return(zc);
 }
 else return(0);
}



int hook_deck_pos(float x, float y)
{
 float xc,yc;
 float a,b,x1,y1,x2,y2;
 int pos=-1;
 cartvektor transf;

 transf.x=x-carrier_pos.x;
 transf.y=y-carrier_pos.y;
 transf.z=20.0;

 xc=VPRIK(carr_orient.front, transf);
 yc=VPRIK(carr_orient.left, transf);

 x1=wire_pos[0][0].x;
 y1=wire_pos[0][0].y;
 x2=wire_pos[3][0].x;
 y2=wire_pos[3][0].y;
 a=(y2-y1)/(x2-x1);
 b=y1-a*x1;
 if (yc > a*xc+b) pos=5; /* Port of wires */

 x1=wire_pos[0][1].x;
 y1=wire_pos[0][1].y;
 x2=wire_pos[3][1].x;
 y2=wire_pos[3][1].y;
 a=(y2-y1)/(x2-x1);
 b=y1-a*x1;
 if (yc < a*xc+b) pos=6; /* Stb. of wires */

 if (pos == -1) {
    x1=wire_pos[0][0].x;
    y1=wire_pos[0][0].y;
    x2=wire_pos[0][1].x;
    y2=wire_pos[0][1].y;
    a=(y2-y1)/(x2-x1);
    b=y1-a*x1;
    if (yc < a*xc+b) pos=0; /* aft of wire 1 */
 }
 if (pos == -1) {
    x1=wire_pos[1][0].x;
    y1=wire_pos[1][0].y;
    x2=wire_pos[1][1].x;
    y2=wire_pos[1][1].y;
    a=(y2-y1)/(x2-x1);
    b=y1-a*x1;
    if (yc < a*xc+b) pos=1; /* aft of wire 2 */
 }
 if (pos == -1) {
    x1=wire_pos[2][0].x;
    y1=wire_pos[2][0].y;
    x2=wire_pos[2][1].x;
    y2=wire_pos[2][1].y;
    a=(y2-y1)/(x2-x1);
    b=y1-a*x1;
    if (yc < a*xc+b) pos=2; /* aft of wire 3 */
 }
 if (pos == -1) {
    x1=wire_pos[3][0].x;
    y1=wire_pos[3][0].y;
    x2=wire_pos[3][1].x;
    y2=wire_pos[3][1].y;
    a=(y2-y1)/(x2-x1);
    b=y1-a*x1;
    if (yc < a*xc+b) pos=3; /* Aft of wire 4 */ else pos=4; /* all wires passed */
 }


 return(pos);
}



void draw_carrier_lines()
{
 extern int wire_trap;
 int i;

 for (i=0; i<4; i++) {
     if (wire_trap-1 != i)
        draw_rot_line(wire_pos[i][0],wire_pos[i][1],carrier_pos,carr_orient,DARKGRAY_SHADE,1000);
 }
}



void draw_meatball()
{
 /* The ball is drawn as seen from the aircraft, not the
    viewing position, that may be elsewhere */

 extern float meatball_tilt;
 extern unsigned long int ticks_8h;
 cartvektor ILSspecs = ILS_signal();
 cartvektor ball_pos, l1, l2;

 if (ILSspecs.x < 4000 && ILSspecs.x > 0 &&
     fabs(ILSspecs.y) < 40 && fabs(ILSspecs.z) < 10) {

     ball_pos.x=16.96;
     ball_pos.y=40.70;
     ball_pos.z=20.0;

     /* Green Indexer */
     l1    = ball_pos;
     l1.y -= 2.2;
     l2    = ball_pos;
     l2.y -= 0.9;
     draw_rot_line(l1,l2,carrier_pos,carr_orient,LIGHTGREEN,4000);
     l1    = ball_pos;
     l1.y += 2.2;
     l2    = ball_pos;
     l2.y += 0.9;
     draw_rot_line(l1,l2,carrier_pos,carr_orient,LIGHTGREEN,4000);

     if (waveoff_lamp==true) {
        l1    = ball_pos;
        l1.y -= 0.7;
        l1.z -= 0.3;
        l2    = ball_pos;
        l2.y -= 0.7;
        l2.z += 0.5;
        draw_rot_line(l1,l2,carrier_pos,carr_orient,LIGHTRED,4000);
        l1.y += 0.1;
        l2.y += 0.1;
        draw_rot_line(l1,l2,carrier_pos,carr_orient,LIGHTRED,4000);
        l1    = ball_pos;
        l1.y += 0.7;
        l1.z -= 0.3;
        l2    = ball_pos;
        l2.y += 0.7;
        l2.z += 0.5;
        draw_rot_line(l1,l2,carrier_pos,carr_orient,LIGHTRED,4000);
        l1.y -= 0.1;
        l2.y -= 0.1;
        draw_rot_line(l1,l2,carrier_pos,carr_orient,LIGHTRED,4000);
        if (ticks_8h-waveoff_time > 5000) waveoff_lamp=false;
     }

     ILSspecs.z=-ILSspecs.z;
     ILSspecs.z+=ILSspecs.y*meatball_tilt;

   if (fabs(ILSspecs.y) < 20) {

     if (fabs(ILSspecs.z) < 0.18)   /* 0.18 */
       draw_rot_point(ball_pos,carrier_pos,carr_orient,YELLOW,4000,true,0);
     if (ILSspecs.z > 0.12 && ILSspecs.z < 0.48) {   /* 0.12 0.48 */
        l1    = ball_pos;
        l1.z += 0.3;  /* 0.4 */
        draw_rot_point(l1,carrier_pos,carr_orient,YELLOW,4000,true,0.5);
     }
     if (ILSspecs.z > 0.42 && ILSspecs.z < 0.78) {   /* 0.42 0.78 */
        l1    = ball_pos;
        l1.z += 0.6;  /* 0.8 */
        draw_rot_point(l1,carrier_pos,carr_orient,YELLOW,4000,true,1);
     }
     if (ILSspecs.z < -0.12 && ILSspecs.z > -0.48) { /* -0.12 -0.48 */
        l1    = ball_pos;
        l1.z -= 0.3;  /* -0.4 */
        draw_rot_point(l1,carrier_pos,carr_orient,YELLOW,4000,true,-0.5);
     }
     if (ILSspecs.z < -0.42 && ILSspecs.z > -0.95) { /* -0.42 -0.95 */
        l1    = ball_pos;
        l1.z -= 0.6;  /* -0.8 */
        draw_rot_point(l1,carrier_pos,carr_orient,LIGHTRED,4000,true,-1);
     }
   }
 }

}



void draw_antennas()
{
 cartvektor a,b;

 a.x=-18.0;
 a.y=-28.0;
 a.z= 36.2;

 b.x=-18.0;
 b.y=-28.0;
 b.z= 57.0;

 draw_rot_line(a,b,carrier_pos,carr_orient,GRAY_SHADE,2000);

 a.x=-18.0;
 a.y=-20.0;
 a.z= 47.0;

 b.x=-18.0;
 b.y=-36.0;
 b.z= 47.0;

 draw_rot_line(a,b,carrier_pos,carr_orient,GRAY_SHADE,2000);

 a.x=-18.0;
 a.y=-20.0;
 a.z= 53.7;

 b.x=-18.0;
 b.y=-36.0;
 b.z= 53.7;

 draw_rot_line(a,b,carrier_pos,carr_orient,GRAY_SHADE,2000);
}



void init_carrier_lights()
{
 float v=9.20*PI/180;
 float sin_v=sin(v);
 float cos_v=cos(v);
 float yc_0=  6.35;
 float xc_0=-132.3;
 int i;

 /* Mast beacon */
 lightlist[0].pos.x    =-18.0;
 lightlist[0].pos.y    =-28.0;
 lightlist[0].pos.z    = 57.0;
 lightlist[0].color    = LIGHTRED;
 lightlist[0].showdist = 4000;
 lightlist[0].bright   = true;

 /* Center line */
 for (i=0; i<17; i++){
  float l=14.0;
  float xc=xc_0+(l/2+3+l*i)*cos_v+(13.25+0.5)*sin_v;
  float yc=yc_0+(l/2+3+l*i)*sin_v-(13.25+0.5)*cos_v;

  lightlist[i+1].pos.x =   xc;
  lightlist[i+1].pos.y =   yc;
  lightlist[i+1].pos.z = 20.0;
  lightlist[i+1].color = WHITE;

  if (!(i % 2)) {
     lightlist[i+1].bright=true;
     lightlist[i+1].showdist=4000;
     }
  else {
     lightlist[i+1].bright=false;
     lightlist[i+1].showdist=3000;
     }
 }

 /* Port edge */
 for (i=0; i<16; i++){
  float l=14.0;
  float xc=xc_0+(l/2+3+l*i)*cos_v+1.8*sin_v;
  float yc=yc_0+(l/2+3+l*i)*sin_v-1.8*cos_v;

  lightlist[i+18].pos.x    =    xc;
  lightlist[i+18].pos.y    =    yc;
  lightlist[i+18].pos.z    =  20.0;
  lightlist[i+18].color    = WHITE;
  lightlist[i+18].bright   = false;
  lightlist[i+18].showdist =  3000;
 }

 /* Stb. edge */
 for (i=0; i<17; i++){
  float l=14.0;
  float xc=xc_0+(l/2+3+l*i)*cos_v+25.7*sin_v;
  float yc=yc_0+(l/2+3+l*i)*sin_v-25.7*cos_v;

  lightlist[i+34].pos.x    =    xc;
  lightlist[i+34].pos.y    =    yc;
  lightlist[i+34].pos.z    =  20.0;
  lightlist[i+34].color    = WHITE;
  lightlist[i+34].bright   = false;
  lightlist[i+34].showdist =  3000;
 }

 /* Threshold */
 for (i=0; i<11; i++){
  float spacing=2.0;
  float pos = 13.75+(i-5)*spacing;
  float xc=xc_0+pos*sin_v;
  float yc=yc_0-pos*cos_v;

  lightlist[i+51].pos.x    =    xc;
  lightlist[i+51].pos.y    =    yc;
  lightlist[i+51].pos.z    =  20.0;
  lightlist[i+51].color    = WHITE;
  lightlist[i+51].bright   = false;
  lightlist[i+51].showdist =  3000;
 }

 /* Drop lights */
 for (i=0; i<5; i++){
  float zh = 17.5 - 2.5*i;

  lightlist[i+62].pos.x    =  -131;
  lightlist[i+62].pos.y    =  -7.4;
  lightlist[i+62].pos.z    =    zh;
  lightlist[i+62].color    = WHITE;
  lightlist[i+62].bright   = false;
  lightlist[i+62].showdist =  3000;
 }

}



void draw_carrier_lights()
{
 int i;
 for (i=0; i<NCARRIERLIGHTS; i++){
     draw_rot_point(lightlist[i].pos,carrier_pos,carr_orient,
                    lightlist[i].color,lightlist[i].showdist,
                    lightlist[i].bright,0);
 }
}



void draw_carrier()
{
 /* In VERTIGO.C */
 extern float running_time;

 draw_rot_object(NIMITZ_HULL,carrier_pos,carr_orient);
 sort_poly_queue();
 draw_poly_queue();

 draw_rot_object(NIMITZ_DECK,carrier_pos,carr_orient);
 sort_poly_queue();
 draw_poly_queue();

 draw_rot_object(NIMITZ_MARK1,carrier_pos,carr_orient);
 sort_poly_queue();
 draw_poly_queue();

 draw_rot_object(NIMITZ_MARK2,carrier_pos,carr_orient);
 draw_poly_queue();


 draw_carrier_lines();
 draw_meatball();
 draw_antennas();
 if (running_time > 17.75 || running_time < 6.25) draw_carrier_lights();
}



void draw_JBD()
{
 draw_rot_object(NIMITZ_JBD,carrier_pos,carr_orient);
}



cartvektor get_trap_pos(int wire_no, int side)
{
 cartvektor trap_pos,global_pos;

 trap_pos=wire_pos[wire_no-1][side];

 global_pos = carrier_pos;
 global_pos = vplus(global_pos, svmult(trap_pos.x,carr_orient.front));
 global_pos = vplus(global_pos, svmult(trap_pos.y,carr_orient.left));
 global_pos = vplus(global_pos, svmult(trap_pos.z,carr_orient.top));

 return(global_pos);
}



cartvektor get_LSO_pos()
{
 cartvektor LSO_pos,global_pos;

 LSO_pos.x=-95.8;
 LSO_pos.y= 22.5;
 LSO_pos.z= 20.5;

 global_pos = carrier_pos;
 global_pos = vplus(global_pos, svmult(LSO_pos.x,carr_orient.front));
 global_pos = vplus(global_pos, svmult(LSO_pos.y,carr_orient.left));
 global_pos = vplus(global_pos, svmult(LSO_pos.z,carr_orient.top));

 return(global_pos);
}



cartvektor ILS_signal()
{
 extern float ldg_aim_offset;
 cartvektor ils_specs, carrier_target, global_target, tgt_to_plane;
 cartvektor carrier_path, global_path, tgt_point, point_to_plane, pln_pos;
 cartvektor c_path_top, g_path_top, g_path_left;
 float tgt_dist;

 extern float x,y,z;
 extern cartvektor pilotpos,front,left,top,v;

 pln_pos.x=x; pln_pos.y=y; pln_pos.z=z;
 pln_pos=vplus(pln_pos,svmult(pilotpos.x,front));
 pln_pos=vplus(pln_pos,svmult(pilotpos.y,left));
 pln_pos=vplus(pln_pos,svmult(pilotpos.z,top));

 /* Aiming point on carrier */
 carrier_target.x = 20.78;
 carrier_target.y = 16.75;
 carrier_target.z = 20.0 + ldg_aim_offset;

 /* Aiming point in global coordinates */
 global_target = carrier_pos;
 global_target = vplus(global_target, svmult(carrier_target.x,carr_orient.front));
 global_target = vplus(global_target, svmult(carrier_target.y,carr_orient.left));
 global_target = vplus(global_target, svmult(carrier_target.z,carr_orient.top));

 /* Glide slope in carrier coordinates */
 carrier_path.x=-cos_v_glide*cos_v_deck;
 carrier_path.y=-cos_v_glide*sin_v_deck;
 carrier_path.z= sin_v_glide;

 /* Vertical normal to glide slope in carrier coordinates */
 c_path_top.x=-cos_v_glidePI2*cos_v_deck;
 c_path_top.y=-cos_v_glidePI2*sin_v_deck;
 c_path_top.z= sin_v_glidePI2;

 /* Glide slope in global coordinates */
 global_path.x = cos_carr_azi*carrier_path.x-sin_carr_azi*carrier_path.y;
 global_path.y = cos_carr_azi*carrier_path.y+sin_carr_azi*carrier_path.x;
 global_path.z = carrier_path.z;

 /* Vertical normal to glide slope in global coordinates */
 g_path_top.x = cos_carr_azi*c_path_top.x-sin_carr_azi*c_path_top.y;
 g_path_top.y = cos_carr_azi*c_path_top.y+sin_carr_azi*c_path_top.x;
 g_path_top.z = c_path_top.z;

 g_path_left=vkryds(g_path_top,global_path);

 tgt_dist=sqrt(SQR(global_target.x-x)+SQR(global_target.y-y)+SQR(global_target.z-z));
 tgt_point=vplus(global_target,svmult(tgt_dist,global_path));
 point_to_plane=vminus(tgt_point,pln_pos);

 tgt_to_plane=vminus(global_target,pln_pos);
 if (VPRIK(tgt_to_plane,global_path) > 0) tgt_dist=-1;
 if (VPRIK(v,global_path) > 0) tgt_dist=-1;


 ils_specs.x=tgt_dist;
 /* Returns tan(angle) which is close to the angle for deviations */
 ils_specs.y=VPRIK(g_path_left,point_to_plane)*180/(tgt_dist*PI);
 ils_specs.z=VPRIK(g_path_top ,point_to_plane)*180/(tgt_dist*PI);

 return(ils_specs);
}



void show_ldg_stats()
{
 extern int wire_trap;
 extern short current_model;
 extern short npropengines;

 char report[MESSAGE_NAMELEN];
 char to_scramble[6];
 char scrambled[]="ACAB";
 float score=5.0;

 slope_err=sqrt(slope_err/n_sum);
 lineup_err=sqrt(lineup_err/n_sum);
 AOA_err=sqrt(AOA_err/n_sum);
 /* speed_err=sqrt(speed_err/n_sum); */
 roll_err=sqrt(roll_err/n_sum);

 score -= 2.0*slope_err;                       /* 2.0 */
 score -= 0.5*lineup_err;                      /* 0.3 */
 score -= 0.4*AOA_err;                         /* 0.5 */
 /* score -= 0.4*speed_err; */                 /* 0.5 */
 score -= 0.2*roll_err;                        /* 0.2 */
 if (forgot_gear || forgot_hook) score -= 1;   /* -1  */
 score -= 0.8*fabs(3-wire_trap);               /* 1.0 */

 if (score > 4.2) {
    set_message("Landing grade: _OK_, 4 points",10,YELLOW);
 }
 if (score <= 4.2 && score > 3.6) {
    set_message("Landing grade: OK, 4 points",10,YELLOW);
 }
 if (score <= 3.6 && score > 2.5) {
    set_message("Landing grade: (OK), 3 points",10,YELLOW);
 }
 if (score <= 2.5 && score > 1.0) {
    set_message("Landing grade: no grade, 2 points",10,YELLOW);
 }
 if (score <= 1.0 && score >-1.0) {
    set_message("Landing grade: cut pass, 1 point",10,YELLOW);
 }
 if (score <= -1.0) {
    set_message("Landing grade: cut pass, 0 points",10,YELLOW);
 }

 if (HUD_always_off)         score += 1;
 if (ILS_always_off)         score += 0.5;
 if (auto_coord_always_off)  score += 1;
 if (wind_always_active)     score += 1;
 /* if (anti_bounce_always_off) score += 1; */
 score += 0.5; /* Makes 10.0 max */
 if (!pengine_always_real && npropengines > 0) score -= 1;
 if (!auto_throttle_always_off)                score -= 1;


 sprintf(report,"Overall score: %2.2f",score);
 set_message(report,10,YELLOW);
 sprintf(to_scramble,"%05.2f",score);
 scrambled[0] += to_scramble[1]-'0';
 scrambled[1] += to_scramble[4]-'0';
 scrambled[1] += to_scramble[3]-'0';
 scrambled[2] += to_scramble[0]-'0';
 scrambled[2] += to_scramble[4]-'0';
 scrambled[3] += to_scramble[3]-'0';
 scrambled[3] += to_scramble[1]-'0';
 if (HUD_always_off==true) {
    scrambled[0] += 5;
    scrambled[1] += 2;
 }
 if (ILS_always_off==true) {
    scrambled[0] += 3;
    scrambled[3] += 1;
 }
 if (auto_coord_always_off)  scrambled[0] += 1;
 if (wind_always_active)     scrambled[1] += 1;
 /* if (anti_bounce_always_off) scrambled[2] += 1; */
 if (!pengine_always_real && npropengines > 0 )   scrambled[3] += 1;
 if (!auto_throttle_always_off)                   scrambled[1] += 1;

 scrambled[0] += (char)current_model;
 scrambled[2] += 7-(char)current_model;

 sprintf(report,"Validation code %s",scrambled);
 set_message(report,10,YELLOW);

 set_message("RMS deviations",10,YELLOW);
 sprintf(report,"Glide slope %2.2f degrees",slope_err);
 set_message(report,10,YELLOW);
 sprintf(report,"Line-up     %2.2f degrees",lineup_err);
 set_message(report,10,YELLOW);
 sprintf(report,"AoA         %2.2f degrees",AOA_err);
 set_message(report,10,YELLOW);
 /*
 sprintf(report,"Airspeed    %2.2f knots",speed_err);
 set_message(report,10,YELLOW);
 */
 sprintf(report,"Roll        %2.2f degrees",roll_err);
 set_message(report,10,YELLOW);

 if (forgot_gear)
    set_message("You forgot to lower your gear",10,YELLOW);

 if (forgot_hook)
    set_message("You forgot to lower your hook",10,YELLOW);
}



void LSO_comms()
{
 #define NAUT_MILE 1820.0
 extern unsigned long int ticks_8h;
 extern cartvektor v_air, front;
 extern float desired_ldg_spd;
 extern float roll;
 extern bool sethook;
 extern arrestor_hook hook;
 extern undercarriage gear[maxngears+maxnhardpts+1];
 extern short current_model;
 extern bool bolter_status;
 extern float desired_ldg_AOA, pitch;
 extern bool show_hud;
 extern enum HUD_modes HUDmode;
 extern bool wind_active, detail_prop, auto_coordination /*, bounce_kludge*/;
 extern bool auto_throttle;
 extern int  poly_plane_id[];
 extern int sample_len[];

 cartvektor ils_specs = ILS_signal();
 float tas=VPRIK(v_air,front)/0.5144;

 if (!guiding) {
  if ( (ils_specs.x < NAUT_MILE) && (ils_specs.x > 0.95*NAUT_MILE) &&
       (fabs(ils_specs.y) < 10) && (fabs(ils_specs.z) < 2) &&
       /* Caution: desired_ldg_spd is getting obsolete */
       (tas < 2*desired_ldg_spd)
       && (current_model!=4) /* not harrier */) {
     set_message("102, three quarters of a mile, call the ball",3,YELLOW);
     play_rdo_wav(CALL_BALL_WAV, 255, 128, LSOSPEED);
     guiding   = true;
     ldg_phase = 0;
     guide_wait= ticks_8h;
     /* reset pilot statistics */
     n_sum     = 0;
     slope_err = 0;
     lineup_err= 0;
     /* speed_err = 0; */
     AOA_err   = 0;
     roll_err  = 0;
     forgot_hook           = false;
     forgot_gear           = false;
     ILS_always_off        = true;
     HUD_always_off        = true;
     auto_coord_always_off = true;
     wind_always_active    = true;
     pengine_always_real   = true;
     /* anti_bounce_always_off= true; */
     auto_throttle_always_off = true;
     average_AoA     = pitch*180/PI;
     AoA_sample_time = ticks_8h;
  }
 }
 else {
     bool abort_ldg = false;
     /* pilot error statistics */
     n_sum++;
     slope_err += SQR(ils_specs.z);
     lineup_err+= SQR(ils_specs.y);
     /* speed_err += SQR(desired_ldg_spd-tas); */
     AOA_err   += SQR(desired_ldg_AOA-pitch*180/PI);
     roll_err  += SQR(roll*180/PI);
     /* Low-pass filtered AoA */
     if (ticks_8h-AoA_sample_time > 100)
       average_AoA = 0.95 * average_AoA + 0.05 * pitch*180/PI;

     /*
       setcolor(YELLOW);
       moveto(300,300);
       outtext("AoA ");
       printfg(average_AoA*100.,6,5);
     */

     if (HUDmode==ILS && show_hud==true) ILS_always_off         = false;
     if (show_hud==true)                 HUD_always_off         = false;
     if (auto_coordination)              auto_coord_always_off  = false;
     if (!wind_active)                   wind_always_active     = false;
     if (!detail_prop)                   pengine_always_real    = false;
     /* if (bounce_kludge)                  anti_bounce_always_off = false; */
     if (auto_throttle)                  auto_throttle_always_off = false;

     if ((ldg_phase==0) && (ticks_8h-guide_wait > 3000)) {

        char text[80];

        extern float get_aircraft_fuel_weight();

        float fuel_kpnds = get_aircraft_fuel_weight() / (0.4536 * 1000);


        if (poly_plane_id[current_model]==F14)
           sprintf(text,"102 Tomcat ball, %02.1f", fuel_kpnds);
        else
           sprintf(text,"102 virtual ball, %02.1f", fuel_kpnds);

        set_message(text,3,YELLOW);
        if (poly_plane_id[current_model]==F14)
          play_rdo_wav(TOM_BALL_WAV, 255, 128, 1000);
        else
          play_rdo_wav(BALL_WAV, 255, 128, 1000);
        ldg_phase=1;
        guide_wait = ticks_8h;

        sprintf(text, "%4.1f", fuel_kpnds);

        fuel_play_id    = 0;
        fuel_play_delay = 0;

        fuel_playlist[0]=text[0];
        if (fuel_playlist[0] != ' ')
           fuel_playlist[0] += NUM_0_WAV - '0';
        else {
           fuel_playlist[0] = 0;
        }

        fuel_playlist[1]=text[1];
        if (fuel_playlist[1] != ' ')
           fuel_playlist[1] += NUM_0_WAV - '0';
        else
           fuel_playlist[1] = 0; /* Should never occur */

        fuel_playlist[2] = POINT_WAV;

        fuel_playlist[3]=text[3];
        if (fuel_playlist[3] != ' ')
           fuel_playlist[3] += NUM_0_WAV - '0';
        else
           fuel_playlist[3] = 0; /* Should never occur */
     }

     if ((ldg_phase==1) && (ticks_8h-guide_wait > 2200) && (fuel_play_id == 0)) {
        guide_wait = ticks_8h;
        if (fuel_playlist[0] != 0) {
           play_rdo_wav(fuel_playlist[fuel_play_id], 255, 128, 1000);
           fuel_play_delay = sample_len[fuel_playlist[fuel_play_id]];
        }
        else
           fuel_play_delay = 0;
        fuel_play_id++;
     }

     if ((ldg_phase==1) && (ticks_8h-guide_wait > fuel_play_delay) && (fuel_play_id == 1)) {
        guide_wait = ticks_8h;
        play_rdo_wav(fuel_playlist[fuel_play_id], 255, 128, 1000);
        fuel_play_delay = sample_len[fuel_playlist[fuel_play_id]];
        fuel_play_id++;
     }

     if ((ldg_phase==1) && (ticks_8h-guide_wait > fuel_play_delay) && (fuel_play_id == 2)) {
        guide_wait = ticks_8h;
        play_rdo_wav(fuel_playlist[fuel_play_id], 255, 128, 1000);
        fuel_play_delay = sample_len[fuel_playlist[fuel_play_id]];
        fuel_play_id++;
     }

     if ((ldg_phase==1) && (ticks_8h-guide_wait > fuel_play_delay) && (fuel_play_id == 3)) {
        guide_wait = ticks_8h;
        play_rdo_wav(fuel_playlist[fuel_play_id], 255, 128, 1000);
        fuel_play_delay = sample_len[fuel_playlist[fuel_play_id]];
        fuel_play_id++;
     }

     if ((ldg_phase==1) && (ticks_8h-guide_wait > 500+fuel_play_delay) && (fuel_play_id == 4)) {
        set_message("Roger ball",3,YELLOW);
        play_rdo_wav(ROGER_BALL_WAV, 255, 128, LSOSPEED);
        ldg_phase=2;
        guide_wait = ticks_8h-1000;
     }
     if ((ldg_phase==2) && (ticks_8h-guide_wait > 4000)) {
        int worst=0;
        float worst_angle=0;

        /* Too much bank? */
        if ((fabs(roll*180/PI) > 5) ||
            (fabs(desired_ldg_AOA-pitch*180/PI) > 4)) worst=6;

        /* Glide path */
        /* Altitude error higher priority than line-up */
        if (fabs(ils_specs.y) > 3*fabs(ils_specs.z)) {
            if (fabs(ils_specs.y) > 0.5) {
               worst=1;
               worst_angle=fabs(ils_specs.y);
            }
        }
        else {
            if (fabs(ils_specs.z) > 0.2) {
               worst=2;
               worst_angle=fabs(4*ils_specs.z);
            }
        }

        if (fabs(desired_ldg_AOA-average_AoA) > 0.75*worst_angle) {
           if (fabs(desired_ldg_AOA-average_AoA) > 0.4) {
              worst=3;
           }
        }

        /*
        if (fabs(desired_ldg_spd-tas) > 5*worst_angle) {
           if (fabs(desired_ldg_spd-tas) > 3) {
              worst=3;
           }
        }
        */

        if (sethook==false && hook.exists==true) {
            worst=4;
            forgot_hook=true;
        }

        if (gear[0].down==0) {
            worst=5;
            forgot_gear=true;
        }

        if ((worst==0) && (ticks_8h-guide_wait > 10000)){  /* keep it coming */
            worst=7;
        }

        if (worst!=0) guide_wait=ticks_8h;

        switch(worst) {

        /* "come left" and "come right" samples are not used */

        case 1:
               if (fabs(ils_specs.y > 1)) {
                  if (ils_specs.y > 0) {
                     set_message("You're lined up left",2,YELLOW);
                     play_rdo_wav(LEFT_WAV, 255, 128, LSOSPEED);
                  }
                  else {
                     set_message("You're lined up right",2,YELLOW);
                     play_rdo_wav(RIGHT_WAV, 255, 128, LSOSPEED);
                  }
               }
               else {
                  if (ils_specs.y > 0) {
                     set_message("You're a little lined up left",2,YELLOW);
                     play_rdo_wav(LITTLE_LEFT_WAV, 255, 128, LSOSPEED);
                  }
                  else {
                     set_message("You're a little lined up right",2,YELLOW);
                     play_rdo_wav(LITTLE_RIGHT_WAV, 255, 128, LSOSPEED);
                  }
               }
               break;

        case 2:
               if (fabs(ils_specs.z) > 0.5) {
                  if ( ils_specs.z > 0) {
                     if ((desired_ldg_AOA-average_AoA) > -2) {
                        set_message("You're low",2,YELLOW);
                        play_rdo_wav(LOW_WAV, 255, 128, LSOSPEED);
                     }
                     else {
                        set_message("POWER",2,YELLOW);
                        play_rdo_wav(POWER_WAV, 255, 128, LSOSPEED);
                     }
                  }
                  else {
                     set_message("You're high",2,YELLOW);
                     play_rdo_wav(HIGH_WAV, 255, 128, LSOSPEED);
                  }
               }
               else {
                  if ( ils_specs.z > 0) {
                     set_message("You're a little low",2,YELLOW);
                     play_rdo_wav(LITTLE_LOW_WAV, 255, 128, LSOSPEED);
                  }
                  else {
                     set_message("You're a little high",2,YELLOW);
                     play_rdo_wav(LITTLE_HIGH_WAV, 255, 128, LSOSPEED);
                  }
               }
               break;

        /* Caution: TAS is used: works only at zero altitude */
        /*
        case 3:
               if (fabs(desired_ldg_spd-tas) > 6) {
                  if ((desired_ldg_spd-tas) > 0) {
                     if (ils_specs.z > -0.5) {
                        set_message("You're slow",2,YELLOW);
                        play_rdo_wav(SLOW_WAV, 255, 128, LSOSPEED);
                     }
                     else {
                        set_message("POWER",2,YELLOW);
                        play_rdo_wav(POWER_WAV, 255, 128, LSOSPEED);
                     }
                  }
                  else {
                     set_message("You're fast",2,YELLOW);
                     play_rdo_wav(FAST_WAV, 255, 128, LSOSPEED);
                  }
               }
               else {
                  if ((desired_ldg_spd-tas) > 0) {
                     set_message("You're a little slow",2,YELLOW);
                     play_rdo_wav(LITTLE_SLOW_WAV, 255, 128, LSOSPEED);
                  }
                  else {
                     set_message("You're a little fast",2,YELLOW);
                     play_rdo_wav(LITTLE_FAST_WAV, 255, 128, LSOSPEED);
                  }
               }
               break;
        */
        case 3:
               if (fabs(desired_ldg_AOA-average_AoA) > 1) {
                  if ((average_AoA-desired_ldg_AOA) > 0) {
                     if (ils_specs.z > -0.5) {
                        set_message("You're slow",2,YELLOW);
                        play_rdo_wav(SLOW_WAV, 255, 128, LSOSPEED);
                     }
                     else {
                        set_message("POWER",2,YELLOW);
                        play_rdo_wav(POWER_WAV, 255, 128, LSOSPEED);
                     }
                  }
                  else {
                     set_message("You're fast",2,YELLOW);
                     play_rdo_wav(FAST_WAV, 255, 128, LSOSPEED);
                  }
               }
               else {
                  if ((average_AoA-desired_ldg_AOA) > 0) {
                     set_message("You're a little slow",2,YELLOW);
                     play_rdo_wav(LITTLE_SLOW_WAV, 255, 128, LSOSPEED);
                  }
                  else {
                     set_message("You're a little fast",2,YELLOW);
                     play_rdo_wav(LITTLE_FAST_WAV, 255, 128, LSOSPEED);
                  }
               }
               break;
        case 4:
               set_message("Lower your hook",2,YELLOW);
               play_rdo_wav(LOWER_HOOK_WAV, 255, 128, LSOSPEED);
               break;

        case 5:
               set_message("Lower your gear",2,YELLOW);
               play_rdo_wav(LOWER_GEAR_WAV, 255, 128, LSOSPEED);
               break;

        case 6:
               set_message("Attitude",2,YELLOW);
               play_rdo_wav(ATTITUDE_WAV, 255, 128, LSOSPEED);
               break;

        case 7:
               set_message("Keep it coming",2,YELLOW);
               play_rdo_wav(KEEP_COMING_WAV, 255, 128, LSOSPEED);
               break;


        default:
        }


     }

     if ( (ils_specs.x < 250 && ldg_phase==2) || abort_ldg==true ) {
        extern short ngears;

        bool waveoff=abort_ldg;
        int i;

        ldg_phase=3;
        for (i=0 ; i<ngears ; i++)
            if (gear[i].down!=1)                      waveoff=true;
        if (hook.down!=1 && hook.exists==true)        waveoff=true;
        if (fabs(ils_specs.y) > 1.5)                  waveoff=true;
        if (fabs(ils_specs.z) > 0.8)                  waveoff=true;
        if (fabs(roll*180/PI) > 5)                    waveoff=true;
        if (fabs(desired_ldg_AOA-pitch*180/PI) > 2)   waveoff=true;

        if (waveoff) {
           set_message("WAVEOFF, WAVEOFF",2,YELLOW);
           play_rdo_wav(WAVEOFF_WAV, 255, 128, LSOSPEED);
           set_message("Landing grade: 0 points",10,YELLOW);
           guiding=false;
           waveoff_lamp=true;
           waveoff_time=ticks_8h;
        }
     }
     if (ldg_phase==3) {
        extern int wire_trap;

        if (bolter_status==true) {
           set_message("BOLTER, BOLTER",3,YELLOW);
           play_rdo_wav(BOLTER_WAV, 255, 128, LSOSPEED);
           set_message("Landing grade: 0 points",10,YELLOW);
           guiding=false;
        }
        if (wire_trap > 0) {
           guiding=false;
           show_ldg_stats();
        }
        if (ils_specs.x < 0) {
           /* Ball passed - only watch for bolter */
           ldg_phase=4;
           guide_wait=ticks_8h;
        }
     }
     if (ldg_phase==4) {
        if ((ticks_8h-guide_wait) > 5000)
           guiding=false;

        if (bolter_status==true) {
           set_message("BOLTER, BOLTER",3,YELLOW);
           play_rdo_wav(BOLTER_WAV, 255, 128, LSOSPEED);
           set_message("Landing grade: 0 points",10,YELLOW);
           guiding=false;
        }
     }
 }
}



void init_catapults()
{
  cat_ini[0].x = -22.5+1;
  cat_ini[0].y =  33.0;
  cat_ini[0].z =  20.0;
  cat_dir[0]   =   0.000;
  cat_dirvect[0].x = cos( PI*cat_dir[0]/180.);
  cat_dirvect[0].y = sin( PI*cat_dir[0]/180.);
  cat_dirvect[0].z = 0;

  cat_ini[1].x =  -2.7+1;
  cat_ini[1].y =  20.8;
  cat_ini[1].z =  20.0;
  cat_dir[1]   =   5.149;
  cat_dirvect[1].x = cos( PI*cat_dir[1]/180.);
  cat_dirvect[1].y = sin( PI*cat_dir[1]/180.);
  cat_dirvect[1].z = 0;

  cat_ini[2].x =  89.0+1;
  cat_ini[2].y =   6.4;
  cat_ini[2].z =  20.0;
  cat_dir[2]   =   1.525;
  cat_dirvect[2].x = cos( PI*cat_dir[2]/180.);
  cat_dirvect[2].y = sin( PI*cat_dir[2]/180.);
  cat_dirvect[2].z = 0;

  cat_ini[3].x =  94.3+1;
  cat_ini[3].y = -17.2;
  cat_ini[3].z =  20.0;
  cat_dir[3]   =   5.026;
  cat_dirvect[3].x = cos( PI*cat_dir[3]/180.);
  cat_dirvect[3].y = sin( PI*cat_dir[3]/180.);
  cat_dirvect[3].z = 0;

  cat_pos = cat_ini[0];

  cat_phase = 0;

  cat_time = 0;

  rail_pos = 0;

  v_cat = 0;

  cat_wait = 0;
}



void update_catapults()
{
 extern float dt;
 extern float throttle;
 extern bool  detail_jet;
 extern short njetengines;
 extern jetengine     jengine[maxnjetengines+1];

 #define CAT_ACCEL 20 /* m/sec^2 */
 #define rnd(a)        random() % (int) a

 if (on_catapult > 0) {
  bool launch_ok = false;

  if (detail_jet) {
    int i;

    for (i=0; i<njetengines; i++) {
      if (jengine[i].ab_status > 0) launch_ok = true;
    }

  }
  else
    if (throttle >= 95) launch_ok = true;


  switch (cat_phase) {

   case 0:
           if (launch_ok) {
             cat_phase = 1;
             cat_time = lasttick/(float)tickspersec;
           }
           cat_pos = cat_ini[on_catapult-1];
           cat_wait = 4 + rnd(4);
           break;

   case 1:
           if (!launch_ok)
              cat_phase = 0;
           if (launch_ok && ((lasttick/(float)tickspersec)-cat_time) > cat_wait) {
              cat_phase = 2;
              cat_time  = lasttick/(float)tickspersec;
              rail_pos  = 0;
              play_wav(CAT_LNCH_WAV, 255, 128, 1000, false);
           }
           cat_pos = cat_ini[on_catapult-1];
           break;

   case 2:
           v_cat      = CAT_ACCEL * ((lasttick/(float)tickspersec)-cat_time);
           rail_pos  += v_cat*dt;
           cat_pos    = cat_ini[on_catapult-1];
           cat_pos.x += cat_dirvect[on_catapult-1].x*rail_pos;
           cat_pos.y += cat_dirvect[on_catapult-1].y*rail_pos;

           if (rail_pos > 100) {
             on_catapult   =0;
             enter_cat_time=0;
             cat_phase     =0;
           }
           break;

   default:
  }
 }
}



cartvektor get_catapult_pos()
{
 cartvektor global_pos;

 global_pos = carrier_pos;
 global_pos = vplus(global_pos, svmult(cat_pos.x,carr_orient.front));
 global_pos = vplus(global_pos, svmult(cat_pos.y,carr_orient.left));
 global_pos = vplus(global_pos, svmult(cat_pos.z,carr_orient.top));

 return(global_pos);
}



cartvektor get_catapult_init_pos(int i)
{
 cartvektor global_pos;

 global_pos = carrier_pos;
 global_pos = vplus(global_pos, svmult(cat_ini[i].x,carr_orient.front));
 global_pos = vplus(global_pos, svmult(cat_ini[i].y,carr_orient.left));
 global_pos = vplus(global_pos, svmult(cat_ini[i].z,carr_orient.top));

 return(global_pos);
}



void update_JBD()
{
 int i;

 for (i=0; i<4; i++) {
   float desire, dJBD, dJBDdt;
   float set_JBD;

   if (on_catapult == i+1)
      set_JBD=1;
   else
      set_JBD=0;

   desire=set_JBD-JBD_pos[i];
   if (desire != 0) {
     float vin, cosvin, sinvin, lng;
     extern float dt;
     extern object3D object[maxnobjects];

     dJBDdt=0.33*dt;            /* full stroke in 3 sec */
     if (fabs(desire)>dJBDdt)
        dJBD=dJBDdt*sgn(desire);
     else
        dJBD=desire;
     JBD_pos[i] += dJBD;

     vin = JBD_pos[i]*PI/3;
     cosvin = cos(vin);
     sinvin = sin(vin);
     if (i==0)
        lng = 2.8;
     else
        lng = 3.8;

     (object[NIMITZ_JBD].vertex+3+4*i)->x =
     (object[NIMITZ_JBD].vertex+0+4*i)->x - lng*cosvin;

     (object[NIMITZ_JBD].vertex+3+4*i)->z =
     (object[NIMITZ_JBD].vertex+0+4*i)->z + lng*sinvin;

     (object[NIMITZ_JBD].vertex+2+4*i)->x =
     (object[NIMITZ_JBD].vertex+1+4*i)->x - lng*cosvin;

     (object[NIMITZ_JBD].vertex+2+4*i)->z =
     (object[NIMITZ_JBD].vertex+1+4*i)->z + lng*sinvin;
   }

 }
}
