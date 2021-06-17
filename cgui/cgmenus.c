
#include <cgui.h>
#include <allegro.h>
#include <string.h>
#include <math.h>

#include "../config.h"
#include "../mtable.h"
#include "../bool.h"
#include "../objects/objects.h"
#include "../vertigo.h"
#include "../joystick.h"
#include "../blt_inst.h"
#include "../polygrap.h"
#include "../mymath.h"

extern bool  crash;
extern planemodel modeltable[nmodels];
extern short current_model;
extern bool  detail_prop, detail_jet, wind_active, auto_coordination;
extern int   start_loc_selection;
extern float time_of_day;
extern short talk_volume, engine_volume, effect_volume;
extern int   scrndiag;
extern float viewdist;
extern short ground_view;
extern short groundtype;
extern int   star_mag_lim;
extern bool  make_stars_bright;
extern float latitude;
extern float sidereal_time;
extern bool  ctrlexpo;
extern short stick_type, throttle_type, rudder_type;
extern bool  mouse_active, mouse_avail;
extern int   joymask;
extern int   joyxzero,joyyzero,joyx,joyy,joy2xzero,joy2x,joy2y,joymask;
extern int   hatup,hatdown,hatleft,hatright;
extern int   throttle_idle, throttle_mil;
extern float joyxgain,joyygain,joy2xgain,joy2ygain;
extern int   nullzone, joy_n_sample;
extern short ncalcperframe;
extern float start_fuel_fraction;
extern bool  show_plane_inside;
extern bool  show_cockpit;
extern bool  smooth_pan;
extern int   graphmode;

extern DATAFILE *data;

/* In JOYSTICK.C */
extern STICK s[1];

extern void init_wind(int center_dir, int scatter_dir);
extern void report_wind();
extern void fill_fuel_tanks();
extern float get_aircraft_empty_weight();
extern float get_aircraft_fuel_weight();

static int sticksel, throtsel, rudsel;
static int sel_ctrlexpo, cjoynull, cjoyfilter;
static int cmodel, cloc;
static int cfuel, old_cfuel;
static int curr_time, old_ctime;
static int cdiag, cvdist;
static int cfract, cdraw_dist;
static int cncalc;
static int cshowcpit, cshowplane, csmpan;
static int starsel, cbright;
static float clatitude, cstartime;
static int propcheck, jetcheck, windcheck, accheck;
static int talk_vol, engine_vol, effect_vol;
static bool  model_changed;
static bool  StartUp;
static bool  wind_changed;
static int   exitGUI;
static int   grares;
static FONT *font_org;
static FONT *font_text;

static char  calib_msg[128];
static int   calib_phase;
static bool  cancel_calibrate, continue_calibrate;
static bool  test_calib;

static int idbtn_calib;

typedef struct {
   int *i;
   int id;
   int id2;
} t_stdata;




//***************
// Graphics setup
//***************

void change_landscape() {
 #include "../map.h"

 extern int airfieldalt;
 extern int horizon_color;
 extern float x,y,z;

 float oldgroundalt=0;

 if (!StartUp) oldgroundalt=groundalt(x,y);

 switch(cfract) {

 case 1: groundtype = 1;
         if (!StartUp) {
           extern enum HUD_modes HUDmode;
           extern cartvektor get_carrier_pos();

           cartvektor c_pos=get_carrier_pos();
           while ( (HUDmode==ILS && groundalt(x,y) > 0) ||
                    groundalt(c_pos.x,c_pos.y) > -2000 ) {
             /* HUDmode==ILS means we are on final to carrier */
             init_map();
             c_pos=get_carrier_pos();
           }
           create_sea();
           z += groundalt(x,y)-oldgroundalt;
         }
         break;

 case 0: groundtype = 0;
         if (!StartUp) {
           airfieldalt=0;
           horizon_color=GREEN;
           z += groundalt(x,y)-oldgroundalt;
         }
         break;
 }
}



static void close_graphics_setup(void *data) {

  graphmode = grares;
  scrndiag  = cdiag;
  viewdist  = (float) cvdist/100;
  if (cfract != groundtype) change_landscape(); 
  ground_view = cdraw_dist;
  ncalcperframe = cncalc; 
  show_cockpit = cshowcpit;
  show_plane_inside = cshowplane;
  smooth_pan = csmpan;
  switch(starsel) {
    case 0:  star_mag_lim = 5; break;
    case 1:  star_mag_lim = 3; break;
    case 2:  star_mag_lim = 0; break;
    default: star_mag_lim = 0; break;
  }
  make_stars_bright=cbright;
  latitude = clatitude * PI / 180.0;
  sidereal_time = cstartime;

  CloseWin(NULL);
}

void create_geom_status_string(void *data, char *s) {
  float fov;

  fov = (180.0/PI)*2*atan((float)(0.5*cdiag*0.0254/1.41)/(cvdist/100.0));
  sprintf(s, "Current horizontal field of view: %d degrees", (int) fov);
}


void catch_edit_geom(void *data) {
  t_stdata *st_data = data;
  int scan, ascii, offset;

  GetEditData(&scan, &ascii, &offset);
  if (ascii == '\r') {
    // Corrects illegal values quitely 
    if (cdiag < 10) cdiag = 10;
    if (cdiag > 50) cdiag = 50;
    if (cvdist < 10) cvdist = 10;
    if (cvdist > 500) cvdist = 500;
    if (cdraw_dist <  4) cdraw_dist =  4;
    //if (cdraw_dist > 10) cdraw_dist = 10;
    if (cncalc <   1) cncalc =   1;
    if (cncalc > 100) cncalc = 100;
    if (clatitude < -90) clatitude = -90;
    if (clatitude >  90) clatitude =  90;
    if (cstartime <  0) cstartime =  0;
    if (cstartime > 24) cstartime = 24;
    Refresh(st_data->id);
  }
}


void graphics_setup_window(void *data) {

  static const char *gfxmode_strs[] = {
    "640x480",
    "800x600",
    "1024x768",
    "1366x768",
    "1440x900",
    "1920x1080",
    };
  //gfxmode_strs must comply with the definitions in config.h
  static int id, id2, id3, id4, id5, id6, id7;
  static t_stdata st_data;

  MkDialogue(ADAPTIVE, "Graphics setup", 0);

  grares = graphmode;
  if (StartUp) {
    AddTag(DOWNLEFT,"");
    id = AddDropDownS(DOWNLEFT, 0, "~Graphics resolution ", &grares, gfxmode_strs, 6);
    HookSpinButtons(id, &grares, 1, 1, 0, 5);
    AddTag(DOWNLEFT,"");
  }

  StartContainer(DOWNLEFT, ADAPTIVE, "Screen geometry", CT_BORDER);

  cdiag = scrndiag;
  id2 = AddEditBox(DOWNLEFT, 30, "~Screen / window diagonal (inches)", FINT, 0, &cdiag);
  AddHandler(id2, catch_edit_geom, &st_data);

  cvdist = viewdist*100;
  id3 = AddEditBox(DOWNLEFT, 30, "~Viewing distance (cm)            ", FINT, 0, &cvdist);
  AddHandler(id3, catch_edit_geom, &st_data);

  st_data.id = AddStatusField(DOWNLEFT, 360, create_geom_status_string, &st_data);
  st_data.i = &cdiag;

  EndContainer();
  AddTag(DOWNLEFT,"");

  //StartContainer(DOWNLEFT, ADAPTIVE, "Landscape type", CT_BORDER);
  cfract = groundtype;
  AddCheck(DOWNLEFT, "Fractal hills", &cfract);
  //EndContainer();
  AddTag(DOWNLEFT,"");

  //StartContainer(DOWNLEFT, ADAPTIVE, "", CT_BORDER);
  cdraw_dist = ground_view; 
  id4 = AddEditBox(DOWNLEFT, 30, "~Landscape drawing distance (km)", FINT, 0, &cdraw_dist);
  AddHandler(id4, catch_edit_geom, &st_data);
  //EndContainer();
  AddTag(DOWNLEFT,"");

  //StartContainer(DOWNLEFT, ADAPTIVE, "", CT_BORDER);
  cncalc = ncalcperframe;
  id5 = AddEditBox(DOWNLEFT, 30, "~Number of model iterations per screen update", FINT, 0, &cncalc);
  AddHandler(id5, catch_edit_geom, &st_data);
  //EndContainer();
  AddTag(DOWNLEFT,"");

  StartContainer(DOWNLEFT, ADAPTIVE, "Cockpit views", CT_BORDER);
  cshowcpit = show_cockpit;
  AddCheck(DOWNLEFT | FILLSPACE, "Show 3D cockpit", &cshowcpit);
  cshowplane = show_plane_inside;
  AddCheck(DOWNLEFT | FILLSPACE, "Show aircraft from inside", &cshowplane);
  csmpan = smooth_pan;
  AddCheck(DOWNLEFT | FILLSPACE, "Smooth panning", &csmpan);
  EndContainer();
  AddTag(DOWNLEFT,"");

  StartContainer(DOWNLEFT, ADAPTIVE, "Stars", CT_BORDER);
  StartContainer(DOWNLEFT, ADAPTIVE, "", CT_BORDER);
  MkRadioContainer(DOWNLEFT, &starsel, R_VERTICAL);
  switch(star_mag_lim) {
  case 5:  starsel = 0; break;
  case 3:  starsel = 1; break;
  case 0:  starsel = 2; break;
  default: starsel = 0; break;
  }
  AddRadioButton("Show ~all stars");
  AddRadioButton("Show only ~bright stars");
  AddRadioButton("Show ~no stars");
  EndRadioContainer();
  cbright = make_stars_bright;
  AddCheck(DOWNLEFT, "~Make stars brighter", &cbright);
  EndContainer();
  StartContainer(RIGHT, ADAPTIVE, "", CT_BORDER);
  clatitude = latitude*180.0/PI;
  id6 = AddEditBox(DOWNLEFT, 40, "~Geographic latitude (degrees)", FFLOAT, 0, &clatitude);
  AddHandler(id6, catch_edit_geom, &st_data);
  cstartime = sidereal_time;
  id7 = AddEditBox(DOWNLEFT, 40, "~Star time (hours)            ", FFLOAT, 0, &cstartime);
  AddHandler(id7, catch_edit_geom, &st_data);
  EndContainer();
  EndContainer();
  AddTag(DOWNLEFT,"");


  AddButton(DOWNLEFT, "~Ok", close_graphics_setup, NULL);

  DisplayWin();
}



//***************
// Controls setup
//***************


static void close_calibration()
{
  //FlushGenEvents();
  CloseWin(NULL);
}



static void continue_calibration(void *data)
{
  continue_calibrate=true;
}



static void cancel_calibration(void *data)
{
  cancel_calibrate=true;
}



void joyupdate(void *data) {
	t_stdata *st_data = data;
  char str[128];
  static int joyxlow,joyxhi,joyylow,joyyhi,joy2xlow,joy2xhi,diff;

  joymask=15;

  readjoy(s,joymask);

  Refresh(st_data->id);
  Refresh(st_data->id2);

  switch(calib_phase) {

    case  0: /* Wait for button release */
             if (s->b[0]!=1)
                calib_phase++;
             break;

    case  1: /* Ask for center position */
             if (rudder_type==1)
	             sprintf(str,"Center stick and rudder, then press [Fire] or [Continue]");
             else
	             sprintf(str,"Center stick, then press [Fire] or [Continue]");
             strcpy(calib_msg, str);
             calib_phase++;
             break;

             case  2: /* Get center position */
             if (s->b[0]==1 || continue_calibrate) {
                joyxzero=s->a[0];
                joyyzero=s->a[1];
                joy2xzero=s->a[2];
                calib_phase++;
             }
             break;

    case  3: /* Wait for button release */
             if (s->b[0]!=1)
                calib_phase++;
             continue_calibrate=false;
             break;

    case  4: /* Ask for upper left position */
             if (rudder_type==1)
	             sprintf(str,"Move stick to upper left and push left pedal, then press [Fire] or [Continue]");
             else
	             sprintf(str,"Move stick to upper left, then press ");
             strcpy(calib_msg, str);
             calib_phase++;
             break;

    case  5: /* Get upper left position */
             if (s->b[0]==1 || continue_calibrate) {
                joyxlow=s->a[0];
                joyylow=s->a[1];
                joy2xlow=s->a[2];
                calib_phase++;
             }
             break;

    case  6: /* Wait for button release */
             if (s->b[0]!=1)
                calib_phase++;
             continue_calibrate=false;
             break;

    case  7: /* Ask for lower right position */
             if (rudder_type==1)
	             sprintf(str,"Move stick to lower right and push right pedal, then press [Fire] or [Continue]");
             else
	             sprintf(str,"Move stick to lower right, then press [Fire] or [Continue]");
             strcpy(calib_msg, str);
             calib_phase++;
             break;

    case  8: /* Get lower right position */
             if (s->b[0]==1 || continue_calibrate) {
                joyxhi=s->a[0];
                joyyhi=s->a[1];
                joy2xhi=s->a[2];

                diff=joyxzero-joyxlow;
                if (diff > ( joyxhi-joyxzero))  diff=joyxhi-joyxzero; /* vaelg mindste */
                if (diff!=0) joyxgain=300/((float)diff);
                else joyxgain=0;

                diff=joyyzero-joyylow;
                if (diff > ( joyyhi-joyyzero))  diff=joyyhi-joyyzero;
                if (diff!=0) joyygain=300/((float)diff);
                else joyygain=0;

                diff=joy2xzero-joy2xlow;
                if (diff > ( joy2xhi-joy2xzero))  diff=joy2xhi-joy2xzero;
                if (diff!=0) joy2xgain=25/((float)diff);
                else joy2xgain=0;

                calib_phase++;
             }
             break;

    case  9: /* Wait for button release */
             if (s->b[0]!=1) {
                calib_phase++;
                if (stick_type!=2) {
                   hatup=0;
                   hatdown=0;
                   hatleft=0;
                   hatright=0;
                   calib_phase+=11;
                }
             }
             continue_calibrate=false;
             break;

    case 21: /* Wait for button release */
             if (s->b[0]!=1) {
                calib_phase++;
                if (throttle_type!=1) {
                   throttle_idle=0;
                   throttle_mil=0;
                   calib_phase+=6;
                }
             }
             continue_calibrate=false;
             break;

    case 22: /* Ask for throttle idle position */
             sprintf(str,"Move throttle to idle position, then press [Fire] or [Continue]");
             strcpy(calib_msg, str);
             calib_phase++;
             break;

    case 23: /* Get throttle idle position */
             if (s->b[0]==1 || continue_calibrate) {
                throttle_idle=s->a[3];
                calib_phase++;
             }
             break;

    case 24: /* Wait for button release */
             if (s->b[0]!=1)
                calib_phase++;
             continue_calibrate=false;
             break;

    case 25: /* Ask for military throttle position */
             sprintf(str,"Move throttle to full power position, then press [Fire] or [Continue]");
             strcpy(calib_msg, str);
             calib_phase++;
             break;

    case 26: /* Get military throttle position */
             if (s->b[0]==1 || continue_calibrate) {
                throttle_mil=s->a[3];
                calib_phase++;
             }
             break;

    case 27: /* Wait for button release */
             if (s->b[0]!=1)
                calib_phase++;
             continue_calibrate=false;
             break;

    case 28: /* Test calibration */
             sprintf(str,"Check calibration, then press [Fire] or [Continue]");
             strcpy(calib_msg, str);
             test_calib=true;
             calib_phase++;
             break;

    case 29: /* Wait while checking */
             if (s->b[0]==1 || continue_calibrate) {
                calib_phase++;
             }
             break;

    case 30: /* Wait for button release */
             if (s->b[0]!=1)
                calib_phase++;
             continue_calibrate=false;
             break;
  }

  if (cancel_calibrate) {
      throttle_idle=0;
      throttle_mil=0;
      hatup=0;
      hatdown=0;
      hatleft=0;
      hatright=0;
      joyxzero=0;
      joyyzero=0;
      joy2xzero=0;
   }

  if (calib_phase < 31 && !cancel_calibrate)
    GenEvent(joyupdate, st_data, 50, 0);
  else {
    close_calibration();
  }
}



void create_calib_msg(void *data, char *str)
{
  sprintf(str, "%s", calib_msg);
}



void create_joystatus_string(void *data, char *str)
{
  sprintf(str, "X1:%4.0i Y1:%4.0i X2:%4.0i Y2:%4.0i    ", s->a[0],s->a[1],s->a[2],s->a[3]);
}



void calibrate_window(void *data) {

  static t_stdata st_data;

  MkDialogue(ADAPTIVE, "Calibration", 0);

  strcpy(calib_msg,"Release fire button");

  st_data.id2 = AddStatusField(DOWNLEFT, 300, create_calib_msg, &st_data);
  st_data.id  = AddStatusField(DOWNLEFT, 300, create_joystatus_string, &st_data);
 

  AddButton(DOWNLEFT, "~Continue", continue_calibration, NULL);


  AddButton(DOWNLEFT, "C~ancel", cancel_calibration, NULL);

  DisplayWin();

  calib_phase=0;
  cancel_calibrate=false;
  continue_calibrate=false;
  test_calib = false;

  GenEvent(joyupdate, &st_data, 50, 0);
}



static void close_controls_setup(void *data) {

  if (sticksel==0) {
    stick_type=1;
    mouse_active=false;
  }
  else {
    stick_type=0;
    mouse_active=true;
  }

  if (throtsel==0) {
    throttle_type=1;
  }
  else {
    throttle_type=0;
  }

  if (rudsel==0) {
    rudder_type=1;
  }
  else {
    rudder_type=0;
  }

  if (sel_ctrlexpo==0) ctrlexpo=1;
  else ctrlexpo=0;
  joy_n_sample = cjoyfilter; 
  nullzone = cjoynull;

  CloseWin(NULL);
}




void stickRB_handler()
{
  if (sticksel==0)
    Activate(idbtn_calib);
  else
    DeActivate(idbtn_calib);
  Refresh(idbtn_calib);
}



void controls_setup_window(void *data) {

  static int idrb_stick, idrb_throttle, idrb_pedals, idsl_null, idsl_filter;
  int     analog_status=15;

#ifndef LINUX
  analog_status=readjoy(s,15);
#endif

  MkDialogue(ADAPTIVE, "Controls setup", 0);
  
  StartContainer(DOWNLEFT, ADAPTIVE, "Controller selection", CT_BORDER);

  StartContainer(DOWNLEFT, ADAPTIVE, "Stick", CT_BORDER);
  if (mouse_active) sticksel = 1;
  else sticksel = 0;
  MkRadioContainer(DOWNLEFT, &sticksel, R_VERTICAL);
  idrb_stick = AddRadioButton("~Joystick");
  AddRadioButton("~Mouse");
  EndRadioContainer(); 
  EndContainer();
  if (analog_status & 3) DeActivate(idrb_stick);
  AddHandler(idrb_stick, stickRB_handler, NULL);

  StartContainer(RIGHT, ADAPTIVE, "Throttle", CT_BORDER);
  if (throttle_type==1) throtsel = 0; //analog
  else throtsel = 1; //key
  MkRadioContainer(DOWNLEFT, &throtsel, R_VERTICAL);
  idrb_throttle = AddRadioButton("Analog ~Throttle");
  AddRadioButton("~Keyboard");
  EndRadioContainer();
  EndContainer();
  if (analog_status & 8) DeActivate(idrb_throttle);

  StartContainer(RIGHT, ADAPTIVE, "Rudder", CT_BORDER);
  if (rudder_type==1) rudsel = 0; //analog
  else rudsel = 1; //key
  MkRadioContainer(DOWNLEFT, &rudsel, R_VERTICAL);
  idrb_pedals = AddRadioButton("~Pedals");
  AddRadioButton("K~eyboard");
  EndRadioContainer();
  EndContainer();
  if (analog_status & 4) DeActivate(idrb_pedals);
  EndContainer();

  AddTag(DOWNLEFT, "");
  idbtn_calib = AddButton(DOWNLEFT, "Calibrate joystick", calibrate_window, NULL);
  AddTag(DOWNLEFT, "");
  stickRB_handler();

  StartContainer(DOWNLEFT, ADAPTIVE, "Response type", CT_BORDER);
  if (ctrlexpo) sel_ctrlexpo=0; 
  else sel_ctrlexpo=1;
  MkRadioContainer(DOWNLEFT, &sel_ctrlexpo, R_HORIZONTAL);
  AddRadioButton("~Exponential");
  AddRadioButton("~Linear");
  EndRadioContainer();

  EndContainer();

  AddTag(DOWNLEFT, "");

  StartContainer(DOWNLEFT, ADAPTIVE, "", CT_BORDER);
  cjoynull=nullzone;
  AddTag(DOWNLEFT, "Joystick Null Zone");
  idsl_null = AddSlider(RIGHT, 100, &cjoynull, 0, 100, SL_SCALE|SL_LABEL, idsl_null);
  if (analog_status & 3) DeActivate(idsl_null);

  cjoyfilter = joy_n_sample;
  AddTag(DOWNLEFT, "Joystick noise filter");
  idsl_filter = AddSlider(RIGHT, 50, &cjoyfilter, 1, 5, SL_SCALE|SL_LABEL, idsl_filter);
  if (analog_status & 3) DeActivate(idsl_filter);
  EndContainer();

  AddButton(DOWNLEFT, "~Ok", close_controls_setup, NULL);

  DisplayWin();
}






//************
// Sound setup
//************
static void close_sound_setup(void *data) {

	talk_volume = talk_vol;
	engine_volume = engine_vol;
	effect_volume = effect_vol;
  
  CloseWin(NULL);
}

void sound_setup_window(void *data) {
	int id1;

	talk_vol = talk_volume;
	engine_vol = engine_volume;
	effect_vol = effect_volume;

	MkDialogue(ADAPTIVE, "Sound setup", 0);
  
	StartContainer(DOWNLEFT, ADAPTIVE, "", CT_BORDER);
	AddTag(DOWNLEFT, "Speech volume:");
  id1 = AddSlider(RIGHT, 100, &talk_vol, 0, 255, SL_SCALE, id1);

	AddTag(DOWNLEFT, "Engine volume:");
  id1 = AddSlider(RIGHT, 100, &engine_vol, 0, 255, SL_SCALE, id1);

	AddTag(DOWNLEFT, "Misc.  volume:");
  id1 = AddSlider(RIGHT, 100, &effect_vol, 0, 255, SL_SCALE, id1);
  EndContainer();

	AddButton(DOWNLEFT, "~Ok", close_sound_setup, NULL);
	

	DisplayWin();
}





//***************
// Flight options
//***************

static void close_flight_options(void *data) {

	if (current_model != cmodel) {
		select_model(cmodel);
		fill_fuel_tanks();
		model_changed = true;
	}

  start_loc_selection = cloc;

	if ((old_cfuel != cfuel) || (current_model != cmodel)) {
    start_fuel_fraction = (float)cfuel/100.0;
	  fill_fuel_tanks();
	}

	if (old_ctime != curr_time) {
	  switch (curr_time) {
	    case 0 : time_of_day=12.0; break;
	    case 1 : time_of_day=18.0; break;
	    case 2 : time_of_day=24.0; break;
	    case 3 : time_of_day= 6.0; break;
		}
	}

	detail_prop = propcheck;
	detail_jet = jetcheck;
	if (wind_active != windcheck) {
    /* User is selecting - otherwise button status is initialized */
    wind_active  = windcheck;
    wind_changed = true;
	}
	auto_coordination = !accheck;

  CloseWin(NULL);
}

void create_status_string(void *data, char *s) {

	if (old_cfuel != cfuel) {
	 start_fuel_fraction = (float)cfuel/100.0;
	 fill_fuel_tanks();
	}
  sprintf(s, "Current total weight  %d kg", (int) (get_aircraft_empty_weight() + get_aircraft_fuel_weight()));
}

void catch_edit_fuel(void *data) {
	t_stdata *st_data = data;
   int scan, ascii, offset;

   GetEditData(&scan, &ascii, &offset);
   if (ascii == '\r') {
     if (cfuel <   0) cfuel = 0;
     if (cfuel > 100) cfuel = 100;
     Refresh(st_data->id);
   }
}

void flight_options_window(void *data) {
	// Oops! Here the model mames and locations are hard-coded :-(
	static const char *air_strs[] = {modeltable[0].name, modeltable[1].name, modeltable[2].name, modeltable[3].name, modeltable[4].name, modeltable[5].name, modeltable[6].name, modeltable[7].name, modeltable[8].name}; 
  static const char *loc_strs[] = {"Runway 00", "Runway 00, on final", "Runway 00, on approach",
		                               "Tarmac", "Carrier, on deck", "Carrier, on final",
	                                 "Carrier, on approach", "Carrier, on catapult",
                                   "High altitude", "Moon, on surface", "Moon, Low Gate descent"};
  static const char *tim_strs[] = {"Day", "Dusk", "Night", "Dawn"};
  static int winid;
	static t_stdata st_data;
	int id, id2, id3, id4;
	char    text[80];
	
	cmodel = current_model;
	cloc   = start_loc_selection;
	cfuel  = 100.0 * start_fuel_fraction;
	old_cfuel = cfuel;

	winid=MkDialogue(ADAPTIVE, "Flight options", 0);

	AddTag(DOWNLEFT,"");

	// Aircraft selection
	id = AddDropDownS(DOWNLEFT, 0, "~Aircraft: ", &cmodel, air_strs, nmodels);
	HookSpinButtons(id, &cmodel, 1, 1, 0, nmodels-1);

	AddTag(DOWNLEFT,"");

	// Fuel load
	StartContainer(DOWNLEFT, ADAPTIVE, "Fuel load:", CT_BORDER);

	id3 = AddEditBox(DOWNLEFT, 40, "~Fill tanks to %:", FINT, 0, &cfuel);
	AddHandler(id3, catch_edit_fuel, &st_data);
	
	sprintf(text,"Aircraft empty weight %d kg", (int) get_aircraft_empty_weight());
	AddTextBox(DOWNLEFT, text, 250, 0, TB_FRAMERAISE |  TB_PREFORMAT | TB_LINEFEED_);

	st_data.id = AddStatusField(DOWNLEFT, 300, create_status_string, &st_data);
	st_data.i = &cfuel;

	EndContainer();

  AddTag(DOWNLEFT,"");

  // Location
	if (StartUp) {
	  id2 = AddDropDownS(DOWNLEFT, 0, "~Location: ", &cloc, loc_strs, MOON_ALT+1);
	  HookSpinButtons(id2, &cloc, 1, 1, 0, MOON_ALT);

		AddTag(DOWNLEFT,"");
	}

	switch ((int)time_of_day) {
	  case 12 : curr_time=0; break;
	  case 18 : curr_time=1; break;
	  case 24 : curr_time=2; break;
	  case  6 : curr_time=3; break;
		default : curr_time=0; break;
	}
	old_ctime = curr_time;

	id4 = AddDropDownS(DOWNLEFT, 0, "~Time: ", &curr_time, tim_strs, 4);
	HookSpinButtons(id4, &curr_time, 1, 1, 0, 3);

	AddTag(DOWNLEFT,"");

	StartContainer(DOWNLEFT, ADAPTIVE, "Realism options:", CT_BORDER);

	if (detail_prop) propcheck=1;
	else propcheck=0;
	AddCheck(DOWNLEFT, "Realistic ~prop engine", &propcheck);

  if (detail_jet) jetcheck=1;
	else jetcheck=0;
	AddCheck(DOWNLEFT, "Realistic ~jet  engine", &jetcheck);

  if (wind_active) windcheck=1;
	else windcheck=0;
	AddCheck(DOWNLEFT, "~Wind                 ", &windcheck);

	if (!auto_coordination) accheck=1;
	else accheck=0;
	AddCheck(DOWNLEFT, "Manual ~rudder control", &accheck);

	AddTag(DOWNLEFT,"Check all for max realism.");

	EndContainer();

	AddTag(DOWNLEFT,"");

	AddButton(DOWNLEFT, "~Ok", close_flight_options, &winid);

	DisplayWin();
}

//**********************
// For Help -> Show Keys
//**********************

static void close_show_keys(void *data) {

  CloseWin(NULL);
}

static void show_keys(void *data nouse) {
  int id;
  static int winid;

  winid = MkDialogue(ADAPTIVE, "Keys reference", W_FLOATING);
  id = AddTextBox(DOWNLEFT, "keys.txt", 670, 54, TB_TEXTFILE|TB_FRAMESINK|TB_PREFORMAT|3); 
  MakeStretchable(id, NULL, NULL, 0);
  AddButton(DOWNLEFT, "~Close", close_show_keys, &winid);
  DisplayWin();
}


//************************
// For Help -> Show Manual
//************************

static void close_show_manual(void *data) {

  CloseWin(NULL);
}

static void show_manual(void *data nouse) {
  int id;
  static int winid;

  winid = MkDialogue(ADAPTIVE, "Vertigo manual", W_FLOATING);
 id = AddTextBox(DOWNLEFT, "vertigo.txt", 670, 54, TB_TEXTFILE|TB_FRAMESINK|TB_PREFORMAT|3); 
  MakeStretchable(id, NULL, NULL, 0);
  AddButton(DOWNLEFT, "~Close", close_show_manual, &winid);
  DisplayWin();
}


//******************
// For Help -> About
//****************** 

void close_about_window(void *data) {

   CloseWin(NULL);
}

static void about_window(void *data nouse) {
  static int winid;
  char text[80]="";

  winid=MkDialogue(ADAPTIVE, "About Vertigo", 0);

  strcpy(text, "Version ");
  strcat(text, VERSION);
  strcat(text, ", ");
  strcat(text, DATE);

StartContainer(DOWNLEFT, ADAPTIVE, "", CT_BORDER);

  AddTag(DOWNLEFT,"        VERTIGO");
  AddTag(DOWNLEFT,"    flight simulator");
  AddTag(DOWNLEFT,text);
  AddTag(DOWNLEFT,"By Anton Norup Sørensen");
  AddTag(DOWNLEFT,"");
  AddTag(DOWNLEFT,"This program is FREEWARE");
  AddTag(DOWNLEFT,"Source distributed under");
  AddTag(DOWNLEFT,"GNU General Public License");
  AddTag(DOWNLEFT,"");
  AddTag(DOWNLEFT,"Built using the libraries:");
  AddTag(DOWNLEFT,"Allegro by Shawn Hargreaves");
  AddTag(DOWNLEFT,"CGUI by Christer Sandberg");
  AddTag(DOWNLEFT,"See the manual for more credits");

EndContainer();


  AddButton(DOWNLEFT, "~Ok!", close_about_window, &winid);
  DisplayWin();
}



// Menu items in main window

void program_setup_menu(void *data) {
	MkMenuItem(0, "Graphics", "", graphics_setup_window, NULL);
	MkMenuItem(0, "Sound", "", sound_setup_window, NULL);
	MkMenuItem(0, "Controls", "", controls_setup_window, NULL);
}

void help_menu(void *data) {
	MkMenuItem(0, "~Manual", "", show_manual, NULL);
	MkMenuItem(0, "~Keys", "", show_keys, NULL);
	MkMenuItem(0, "~About", "", about_window, NULL);
}



void stop_program(void *data nouse) {
   
	crash = true;
	exitGUI = true;

  StopProcessEvents();
  CloseWin(NULL);
}

void close_main_window(void *data nouse) {
  StopProcessEvents();
  CloseWin(NULL);
}



void main_menu(void) {
  MkDialogue(ADAPTIVE, "Vertigo main menu", 0);

  MakeMenuBar();
	MkMenuBarItem(" Program ~Setup ", program_setup_menu, NULL);
	MkMenuBarItem(" ~Help ", help_menu, NULL);
	EndMenuBar();
  AddTag(DOWNLEFT,"");
  SetCguiFont(font_org);
  AddTag(DOWNLEFT,"       VERTIGO");
  AddTag(DOWNLEFT,"   flight simulator");
  SetCguiFont(font_text);
  AddTag(DOWNLEFT,"");
  AddButton(DOWNLEFT, "Flight ~Options", flight_options_window, NULL);
  AddTag(DOWNLEFT,"");
  AddButton(DOWNLEFT, "~Fly!", close_main_window, NULL);
  AddButton(RIGHT|ALIGNRIGHT, "~Quit", stop_program, NULL);
  DisplayWin();
  ProcessEvents();
}



int main_menu_cgui(bool startup) {

  StartUp = startup;
  exitGUI      = false;
  wind_changed = false;

  if (startup) {
    int scx=0, scy=0;
		int refresh = 0;

    switch(graphmode) {
      case  R640X480: scx =  640; scy = 480; refresh =  0; break;
      case  R800X600: scx =  800; scy = 600; refresh =  0; break;
      case R1024X768: scx = 1024; scy = 768; refresh = 70; break;
      case R1366X768: scx = 1366; scy = 768; refresh = 70; break;
      case R1440X900: scx = 1440; scy = 900; refresh = 70; break;
      case R1920X1080: scx = 1920; scy = 1080; refresh = 70; break;
    }

    request_refresh_rate(refresh);
    if (set_gfx_mode(GFX_AUTODETECT, scx, scy, 0, 0) != 0) {
      if (set_gfx_mode(GFX_SAFE, scx, scy, 0, 0) != 0) {
         set_gfx_mode(GFX_TEXT, 0, 0, 0, 0);
         allegro_message("Unable to set any graphic mode\n%s\n", allegro_error);
         return 1;
      }
    }
    clear_to_color(screen, 255);
    InitCgui(0, 0, 0);
    //SetCguiColors(1);
  }
  else {
    InitCgui(0,0,0);
    //SetCguiColors(0);
  }
  font_org = GetCguiFont();
  font_text = (FONT *)find_datafile_object(data, "fnt7x8")->dat;
  SetCguiFont(font_text);
  main_menu();
  DeInitCgui();

  if (crash==true) {
   save_config();
   errorexit(0);
  }

	// Apply user selections
  if (model_changed == true) {
     if (!startup) { 
       dial_cleanup();
       make_instruments();
     }
  }
  if (!StartUp) {
    if (wind_changed) {
      init_wind(0,179);
      report_wind();
      update_windbag();
    }
  }
  save_config();
 
  return 0;
}
