
#include <stdio.h>
#include <math.h>
#include "bool.h"
#include "objects/objects.h"
#include "vertigo.h"
#include "mymath.h"
#define  rnd(a)        random() % (int) a
#include "map.h"
#include "joystick.h"
#include "message.h"
#include "carrier.h"
#include <allegro.h>
#include "sound.h"
#include "astro.h"

#ifdef CGUI
#  include "cgui/cgmenus.h"
#endif

//Global variable references in vertigo.c
extern float setrudder;
extern bool setgear, setabrk;
extern bool whlbrakes;
extern bool sethook;
extern bool show_instruments;
extern bool show_ctrlpos;
extern bool show_map;
extern bool show_cockpit;
extern bool show_plane_inside;
extern bool stall_horn_on;
extern short rudder_type;
extern bool ab_burning;
extern bool playing_gear_rumble;
extern unsigned long int startpausetick, pausetick, lasttick, ticks_8h;
extern bool logging;
extern bool mouse_active;
extern short calcnumber;
extern short ncalcperframe;
extern short map_zoom;
extern float xscl,yscl;
extern bool crash;
extern bool engineering_mode;
extern float set_traildist;
extern int refresh_palette;
extern float set_panhoriz;
extern int   panhorizsgn;
extern float set_panhoriz_int;
extern float set_panvert;
extern float set_panvert_int;
extern float panhoriz_int;
extern int nwaypoints;
extern int active_waypoint;
extern int elevatortrim;
extern int ailerontrim;
extern int ruddertrim;
extern int  poly_plane_id[nmodels];
extern short current_model;
extern float DLC_spoiler;
extern bool  DLC_active;
extern bool  auto_throttle;
extern short viewpoint;
extern enum  HUD_modes HUDmode;
extern int ntargets;
extern int selected_target;
extern target_specs target[maxntargets];
extern short njetengines, npropengines, nrocketengines;
extern jetengine jengine[maxnjetengines+1];
extern bool detail_jet;
extern propengine pengine[maxnpropengines+1];
extern rocketengine rengine[maxnrocketengines+1];
extern unsigned long int failure_time;
extern bool failure_upcoming;
extern float manual_sweep;
extern bool rcs_control;
extern bool ctrlexpo;
extern float rudder_gain, rudder;
extern aeroelement element[maxnelements+1];
extern float tail_rudder;
extern undercarriage gear[maxngears+maxnhardpts+1];
extern bool show_hud;
extern bool color_hud;
extern int hud_red;
extern int hud_blue;
extern int hud_white;
extern int nlcos_bullets_flying;
extern float throttle;
extern short throttle_type;
extern int prop_ctrl;
extern float setflap;
extern float set_sweep;
extern float x,y;
extern int joymask;
extern int on_catapult;
extern float running_time;
extern float time_of_day;

extern BITMAP *active_page;


// In JOYSTICK.C
extern STICK s[1];

void setup_cockpit_panning();
void open_log();
void close_log();
void init_mouse();
void joy_center();
void flip();
void set_view_geometry();
void setup_palette();

