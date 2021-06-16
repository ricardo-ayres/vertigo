#include <stdio.h>
#include <stdlib.h>
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
#include "mgerror.h"

#define OLD_MGUI

#include "mgui.h"
#undef SMALL_FONT

typedef struct { int val; char *name;} locstruct;

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
/*
extern bool show_cockpit;
extern bool show_plane_inside;
*/

/* In JOYSTICK.C */
extern STICK s[1];

extern void init_wind(int center_dir, int scatter_dir);
extern void report_wind();
extern void fill_fuel_tanks();
extern float get_aircraft_empty_weight();
extern float get_aircraft_fuel_weight();

/* In mymath.c */
extern int sgn(float x);

static int   exitGUI;
static short set_model;
static bool  model_changed;
static bool  wind_changed;
static bool  StartUp;
static bool  setup;
static int   calib_phase;
static bool  cancel_calibrate, continue_calibrate;
static int   lastx1, lasty1, lastx2, lasty2;
static bool  test_calib;

static MOBJECT shell;
static MOBJECT ctrl_shell;
static MOBJECT fov_label;
static MOBJECT drawdist_edit;
static MOBJECT ncalc_edit;
static MOBJECT joypos_label;
static MOBJECT calib_instruct_label;
static MOBJECT joy_draw;
static MOBJECT calibbtn;
static MOBJECT recenterbtn;
static MOBJECT analog_rudder_rb, key_rudder_rb;
static MOBJECT analog_throttle_rb, key_throttle_rb;
static MOBJECT joy2_rb, joy4_rb;
static MOBJECT fuelweight_label;
static MOBJECT graphics_shell;

static MTColor black, white, cadetblue, seagreen;


static void *color_buffer;


static locstruct loc_names[]=
{
  {RWY_00              ,"Runway 00"},
  {RWY_00_FINAL        ,"Runway 00, on final"},
  {RWY_00_APPROACH     ,"Runway 00, on approach"},
  {TARMAC              ,"Tarmac"},
  {CARR_DECK           ,"Carrier, on deck"},
  {CARR_FINAL          ,"Carrier, on final"},
  {CARR_APPROACH       ,"Carrier, on approach"},
  {CARR_CAT            ,"Carrier, on catapult"},
  {HIGH_ALT            ,"High altitude"},
  {HIGH_ALT            ,"Moon, on surface"},
  {HIGH_ALT            ,"Moon, Low Gate descent"}
};



void setup_gui_pallette()
{
 MSetDefaultForegroundRGB(  0,  0,  0);
 MSetDefaultBackgroundRGB(200,200,200);
 black     = MBlackColor();
 white     = MWhiteColor();
 cadetblue = MAllocColor(0x60, 0x85, 0x95);
 seagreen  = MAllocColor(0x70, 0xa5, 0xa0);
}



/******************/
/* Aircraft shell */
/******************/



void aircraft_done_CB(MOBJECT obj, void *a, void *tshell)
{
        MShellUnrealize((MOBJECT )tshell);
        MShellDestroy((MOBJECT )tshell);
        MObjectSetSensitive(shell);
}



void aircraft_radio_CB(MOBJECT rb, MVALUE status, void *ii)
{
	set_model = (int)ii;

	if (current_model != set_model) {
		select_model(set_model);
		fill_fuel_tanks();
		model_changed = true;
	}

}



void aircraft_CB(MOBJECT obj, void *item, void *udata)
{
 MOBJECT aircraft_shell;
 MOBJECT donebtn;
 MOBJECT rform, rb;
 int i;

 aircraft_shell = MCreateShell("Aircraft menu", SF_MODAL | SF_IGNORE_WM_CLOSE );

 rform = MCreateRowForm(aircraft_shell);
 MCreateLabel(rform, "Select aircraft to fly", HELV_N_FONT);

 for (i=nmodels-1 ; i>=0 ; i--) {
	rb = MCreateRButton(rform, modeltable[i].name, TIMES_N_FONT);
	MRButtonSetCallback(rb, aircraft_radio_CB, (void *)i);
	if (current_model == i) MRButtonActivate(rb);
 }

 donebtn = MCreatePButton(aircraft_shell, "Done", TIMES_N_FONT);
 MPButtonSetCallback(donebtn, aircraft_done_CB, aircraft_shell);
 MObjectSetPopupHelp(donebtn,
     "Click here when you are finished selecting aircraft", 1000, 0);

 MShellRealize (aircraft_shell);
 MObjectSetUnsensitive(shell);

}



/******************/
/* Location shell */
/******************/



void location_done_CB(MOBJECT obj, void *a, void *tshell)
{
        MShellUnrealize((MOBJECT )tshell);
        MShellDestroy((MOBJECT )tshell);
        MObjectSetSensitive(shell);
}



void location_radio_CB(MOBJECT rb, MVALUE status, void *ii)
{
	start_loc_selection=(int)ii;
}



void location_CB(MOBJECT obj, void *item, void *udata)
{
 MOBJECT location_shell;
 MOBJECT donebtn;
 MOBJECT rform, rb;
 int i;

 location_shell = MCreateShell("Location menu", SF_MODAL | SF_IGNORE_WM_CLOSE );

 rform = MCreateRowForm(location_shell);
 MCreateLabel(rform, "Select location to fly from", HELV_N_FONT);

 for (i=0; i<=MOON_ALT ; i++) {
	rb = MCreateRButton(rform, loc_names[i].name, TIMES_N_FONT);
	MRButtonSetCallback(rb, location_radio_CB, (void *)i);
	if (start_loc_selection == i) MRButtonActivate(rb);
 }

 donebtn = MCreatePButton(location_shell, "Done", TIMES_N_FONT);
 MPButtonSetCallback(donebtn, location_done_CB, location_shell);
 MObjectSetPopupHelp(donebtn,
     "Click here when you are finished selecting location", 1000, 0);

 MShellRealize (location_shell);
 MObjectSetUnsensitive(shell);

}



/**************/
/* Time shell */
/**************/

void time_done_CB(MOBJECT obj, void *a, void *tshell)
{
        MShellUnrealize((MOBJECT )tshell);
        MShellDestroy((MOBJECT )tshell);
        MObjectSetSensitive(shell);
}



void time_radio_CB(MOBJECT rb, MVALUE status, void *ii)
{

 switch((int)ii) {

 case 1: time_of_day = 12.0;
         break;

 case 2: time_of_day = 18.0;
         break;

 case 3: time_of_day = 24.0;
         break;

 case 4: time_of_day =  6.0;
         break;
 }
}



void time_CB(MOBJECT obj, void *item, void *udata)
{
 MOBJECT time_shell;
 MOBJECT donebtn;
 MOBJECT rform, rb;

 time_shell = MCreateShell("Time menu", SF_MODAL | SF_IGNORE_WM_CLOSE );

 rform = MCreateRowForm(time_shell);
 MCreateLabel(rform, "Select time for start of flight", HELV_N_FONT);
 rb = MCreateRButton(rform, "Day", TIMES_N_FONT);
 MRButtonSetCallback(rb, time_radio_CB, (void *)1);
 if (time_of_day == 12.0 ) 
    MRButtonActivate(rb);
 rb = MCreateRButton(rform, "Dusk", TIMES_N_FONT);
 MRButtonSetCallback(rb, time_radio_CB, (void *)2);
 if (time_of_day == 18.0 )
    MRButtonActivate(rb);
 rb = MCreateRButton(rform, "Night", TIMES_N_FONT);
 MRButtonSetCallback(rb, time_radio_CB, (void *)3);
 if (time_of_day == 24.0 )
    MRButtonActivate(rb);
 rb = MCreateRButton(rform, "Dawn", TIMES_N_FONT);
 MRButtonSetCallback(rb, time_radio_CB, (void *)4);
 if (time_of_day == 6.0 )
    MRButtonActivate(rb);

 donebtn = MCreatePButton(time_shell, "Done", TIMES_N_FONT);
 MPButtonSetCallback(donebtn, time_done_CB, time_shell);
 MObjectSetPopupHelp(donebtn,
     "Click here when you are finished selecting time", 1000, 0);

 MShellRealize (time_shell);
 MObjectSetUnsensitive(shell);

}


/*****************/
/* Realism shell */
/*****************/

void real_done_CB(MOBJECT obj, void *a, void *rshell)
{
 MShellUnrealize((MOBJECT )rshell);
 MShellDestroy((MOBJECT )rshell);
 MObjectSetSensitive(shell);
}



void real_toggle_CB(MOBJECT rb, MVALUE status, void *ii)
{
 switch((int)ii) {

 case 1: detail_prop=(int)status;
         break;

 case 2: detail_jet =(int)status;
         break;


 case 3: if (wind_active!=(int)status) {
           /* User is selecting - otherwise button status is initialized */
           wind_active  = (int)status;
           wind_changed = true;
         }
         break;

 case 4: auto_coordination=!(int)status;
         break;
 }
}



void realism_CB(MOBJECT obj, void *item, void *udata)
{
 MOBJECT real_shell;
 MOBJECT donebtn;
 MOBJECT rform, tb;

 real_shell = MCreateShell("Realism menu", SF_MODAL | SF_IGNORE_WM_CLOSE);

 rform = MCreateRowForm(real_shell);
 MCreateLabel(rform, "Set realism options", HELV_N_FONT);
 MCreateLabel(rform, "Push all buttons in for max. realism", TIMES_N_FONT);
 tb = MCreateTButton(rform, "Realistic propeller engine", TIMES_N_FONT);
 MTButtonSetCallback(tb, real_toggle_CB, (void *)1);
 MObjectSetPopupHelp(tb,
     "Activate for torque, p-factor etc.", 1000, 0);
 if (detail_prop)
    MTButtonActivate(tb);

 tb = MCreateTButton(rform, "Realistic jet engine", TIMES_N_FONT);
 MTButtonSetCallback(tb, real_toggle_CB, (void *)2);
 MObjectSetPopupHelp(tb,
     "Activate for afterburner, fuel consumption etc.", 1000, 0);
 if (detail_jet)
    MTButtonActivate(tb);

 tb = MCreateTButton(rform, "Wind", TIMES_N_FONT);
 MTButtonSetCallback(tb, real_toggle_CB, (void *)3);
 MObjectSetPopupHelp(tb,
     "Activate for wind of random strength and direction", 1000, 0);
 if (wind_active)
    MTButtonSetActivationStatus(tb,True);

 tb = MCreateTButton(rform, "Manual rudder control", TIMES_N_FONT);
 MTButtonSetCallback(tb, real_toggle_CB, (void *)4);
 MObjectSetPopupHelp(tb,
     "Disable for automatic yaw elimination", 1000, 0);
 if (!auto_coordination)
    MTButtonActivate(tb);

 donebtn = MCreatePButton(real_shell, "Done", TIMES_N_FONT);
 MPButtonSetCallback(donebtn, real_done_CB, real_shell);
 MObjectSetPopupHelp(donebtn,
     "Click here when you are finished setting realism options", 1000, 0);


 MShellRealize (real_shell);
 MObjectSetUnsensitive(shell);
}

/*************/
/* Fuel load */
/*************/


void update_fuelweight_label()
{
 char text[80];

 sprintf(text,"Aircraft total weight %d kg",
         (int) (get_aircraft_empty_weight() + get_aircraft_fuel_weight()));
 MObjectSetText(fuelweight_label, text);
}



void fuelload_done_CB(MOBJECT obj, void *a, void *fshell)
{
 MShellUnrealize((MOBJECT )fshell);
 MShellDestroy((MOBJECT )fshell);
 MObjectSetSensitive(shell);
}

 

void Val_fuel_CB(MOBJECT edit, EDIT_VAL *ev, void *ii)
{
 float val;

 sscanf(ev->text,"%f",&val);
 if ( (val > -1) && (val < 101)) {
    ev->text_validated  = True;
    start_fuel_fraction = val / 100.0;
    fill_fuel_tanks();
    update_fuelweight_label();
 }
 else {
    ev->text_validated = False;
    MMessageDialog("Message", "Fuel load percentage must be >=0 and <= 100", " Ok ", NULL);
 }
}



void fuelload_CB(MOBJECT obj, void *item, void *udata)
{
 MOBJECT fuel_shell;
 MOBJECT edit;
 MOBJECT donebtn;
 char    text[80];


 fuel_shell = MCreateShell("Fuel load", SF_MODAL | SF_IGNORE_WM_CLOSE);

 MCreateLabel(fuel_shell, "Load percentage", TIMES_SMALL);
 sprintf(text,"%f", 100.0 * start_fuel_fraction);
 edit = MCreateEdit(fuel_shell, text, 3, DEFAULT_FONT);
 MEditSetFilter(edit, DIGIT, "");
 MEditSetValCallback(edit, Val_fuel_CB, NULL);
#ifndef LINUX
 MEditSetValidatedColors(edit, cadetblue, white);
 MEditSetNotValidatedColors(edit, seagreen, black);
#endif

 sprintf(text,"Aircraft empty weight %d kg", (int) get_aircraft_empty_weight());
 MCreateLabel(fuel_shell, text, TIMES_SMALL);

 fuelweight_label = MCreateLabel(fuel_shell, "", TIMES_SMALL);
 update_fuelweight_label();

 donebtn = MCreatePButton(fuel_shell, "Done", TIMES_N_FONT);
 MPButtonSetCallback(donebtn, fuelload_done_CB, fuel_shell);
 MObjectSetPopupHelp(donebtn,
     "Click here when you are finished setting fuel load", 1000, 0);

 MShellRealize (fuel_shell);
 MObjectSetUnsensitive(shell);
}



/*************************/
/* More graphics options */
/*************************/



void cockpit_toggle_CB(MOBJECT rb, MVALUE status, void *ii)
{
 show_cockpit = (int)status;
}



void showplane_toggle_CB(MOBJECT rb, MVALUE status, void *ii)
{
 show_plane_inside = (int)status;
}



void smooth_pan_toggle_CB(MOBJECT rb, MVALUE status, void *ii)
{
 smooth_pan = (int)status;
}



void stars_radio_CB(MOBJECT rb, MVALUE status, void *ii)
{
 switch((int)ii) {

 case 1: star_mag_lim = 5;
         break;

 case 2: star_mag_lim = 3;
         break;

 case 3: star_mag_lim = 0;
         break;
 }
}



void stars_toggle_CB(MOBJECT rb, MVALUE status, void *ii)
{
 make_stars_bright = (int)status;
}



void Val_latitude_CB(MOBJECT edit, EDIT_VAL *ev, void *ii)
{
 float val;

 sscanf(ev->text,"%f",&val);
 if ( (val >= -90) && (val <= 90)) {
    ev->text_validated = True;
    latitude = val * PI / 180.0;
 }
 else {
    ev->text_validated = False;
    MMessageDialog("Message",
                   "Latitude must be >= -90 and <= 90", " Ok ", NULL);
 }
}



void Val_sidereal_CB(MOBJECT edit, EDIT_VAL *ev, void *ii)
{
 float val;

 sscanf(ev->text,"%f",&val);
 if ( (val >= 0) && (val < 24)) {
    ev->text_validated = True;
    sidereal_time = val;
 }
 else {
    ev->text_validated = False;
    MMessageDialog("Message",
                   "Sidereal time must be >= 0 and < 24", " Ok ", NULL);
 }
}



void more_graphics_done_CB(MOBJECT obj, void *a, void *mgshell)
{
 MShellUnrealize((MOBJECT )mgshell);
 MShellDestroy((MOBJECT )mgshell);
 MObjectSetSensitive(graphics_shell);
}



void more_graphics_CB(MOBJECT obj, void *item, void *udata)
{
 MOBJECT mg_shell;
 MOBJECT misc_rform;
 MOBJECT moretb;
 MOBJECT star_rform, starrb, startb, star_cform, starpos_rform, allstar_rform;
 MOBJECT edit;
 char    tekst[10];
 MOBJECT donebtn;

 setup=True;
 mg_shell = MCreateShell("More graphics options", SF_MODAL | SF_IGNORE_WM_CLOSE);

 misc_rform = MCreateRowForm(mg_shell);

 MCreateLabel(misc_rform, "Push in to activate options", TIMES_SMALL);

 moretb=MCreateTButton(misc_rform, "Show cockpit", TIMES_N_FONT);
 MObjectSetPopupHelp(moretb,
 "Displays the cockpit and canopy frames"
  , 1000, 0);
 MTButtonSetCallback(moretb, cockpit_toggle_CB, NULL);
 if (show_cockpit == true)
    MTButtonSetActivationStatus(moretb,True);

 moretb=MCreateTButton(misc_rform, "Show plane from inside", TIMES_N_FONT);
 MObjectSetPopupHelp(moretb,
 "Displays the airframe seen from the cockpit"
  , 1000, 0);
 MTButtonSetCallback(moretb, showplane_toggle_CB, NULL);
 if (show_plane_inside == true)
    MTButtonSetActivationStatus(moretb,True);

 moretb=MCreateTButton(misc_rform, "Smooth panning", TIMES_N_FONT);
 MObjectSetPopupHelp(moretb,
 "Smooth and slow panning"
  , 1000, 0);
 MTButtonSetCallback(moretb, smooth_pan_toggle_CB, NULL);
 if (smooth_pan == true)
    MTButtonSetActivationStatus(moretb,True);


 allstar_rform=MCreateRowForm(mg_shell);
 MCreateLabel(allstar_rform, "Stars", HELV_N_FONT);
 star_cform=MCreateColForm(allstar_rform);
 MObjectSetShadow(star_cform, WS_NONE, 0, 0);
 star_rform=MCreateRowForm(star_cform);
 starrb=MCreateRButton(star_rform, "Show all stars", TIMES_N_FONT);
 MTButtonSetCallback(starrb, stars_radio_CB, (void *)1);
 MObjectSetPopupHelp(starrb,
 "For a nice sky on a fast machine"
  , 1000, 0);
 if (star_mag_lim == 5)
    MRButtonActivate(starrb);
 starrb=MCreateRButton(star_rform, "Show only bright stars", TIMES_N_FONT);
 MTButtonSetCallback(starrb, stars_radio_CB, (void *)2);
 MObjectSetPopupHelp(starrb,
 "Improves frame rate on slower machines"
  , 1000, 0);
 if (star_mag_lim == 3)
    MRButtonActivate(starrb);
 starrb=MCreateRButton(star_rform, "Show no stars", TIMES_N_FONT);
 MTButtonSetCallback(starrb, stars_radio_CB, (void *)3);
 MObjectSetPopupHelp(starrb,
 "Use to simulate overcast and improve frame rate"
  , 1000, 0);
 if (star_mag_lim == 0)
    MRButtonActivate(starrb);
 startb=MCreateTButton(star_rform, "Make stars brighter", TIMES_N_FONT);
 MObjectSetPopupHelp(startb,
 "Makes all stars easily visible"
  , 1000, 0);
 MTButtonSetCallback(startb, stars_toggle_CB, NULL);
 if (make_stars_bright == true)
    MTButtonSetActivationStatus(startb,True);

 starpos_rform=MCreateRowForm(star_cform);
 MCreateLabel(starpos_rform, "Geographic latitude (degrees)", TIMES_SMALL);
 sprintf(tekst,"%f",latitude*180.0/PI);
 edit = MCreateEdit(starpos_rform, tekst, 6, DEFAULT_FONT);
 //MEditSetFilter(edit, FLOAT, "");
 MEditSetFilter(edit, DIGIT, ""); // MGUI 334
 MEditSetValCallback(edit, Val_latitude_CB, NULL);
#ifndef LINUX
 MEditSetValidatedColors(edit, cadetblue, white);
 MEditSetNotValidatedColors(edit, seagreen, black);
#endif
 MObjectSetPopupHelp(edit,
 "Enter the latitude of the location for flight, -90 <= latitude <= 90 degrees"
  , 1000, 0);

 MCreateLabel(starpos_rform, "Sidereal time (hours)", TIMES_SMALL);
 sprintf(tekst,"%f",sidereal_time);
 edit = MCreateEdit(starpos_rform, tekst, 4, DEFAULT_FONT);
 // MEditSetFilter(edit, FLOAT, "");
 MEditSetFilter(edit, DIGIT, ""); //MGUI 334
 MEditSetValCallback(edit, Val_sidereal_CB, NULL);
#ifndef LINUX
 MEditSetValidatedColors(edit, cadetblue, white);
 MEditSetNotValidatedColors(edit, seagreen, black);
#endif
 MObjectSetPopupHelp(edit,
 "Enter the rotation (hour angle at south) of the sky, 0 <= time < 24 hours"
  , 1000, 0);



 donebtn = MCreatePButton(mg_shell, "Done", TIMES_N_FONT);
 MPButtonSetCallback(donebtn, more_graphics_done_CB, mg_shell);
 MObjectSetPopupHelp(donebtn,
     "Click here when you are finished configuring graphics", 1000, 0);

 setup=False;
 MShellRealize (mg_shell);
 MObjectSetUnsensitive(graphics_shell);
}



/**********************/
/* Configure graphics */
/**********************/



void graphics_done_CB(MOBJECT obj, void *a, void *gshell)
{
 MShellUnrealize((MOBJECT )gshell);
 MShellDestroy((MOBJECT )gshell);
 MObjectSetSensitive(shell);
}



void update_fov_label()
{
 float fov;
 char fov_text[80];

 fov = (180.0/PI)*2*atan((float)(0.5*scrndiag*0.0254/1.41)/viewdist);
 sprintf(fov_text,"%d degrees.", (int)fov);
 MObjectSetText(fov_label, fov_text);
}



void Val_scrndiag_CB(MOBJECT edit, EDIT_VAL *ev, void *ii)
{
 int val;

 sscanf(ev->text,"%d",&val);
 if ( (val >= 10) && (val <= 50)) {
    ev->text_validated = True;
    scrndiag = val;
    update_fov_label();
 }
 else {
    ev->text_validated = False;
    MMessageDialog("Message", "Diagonal must be >= 10 and <= 50", " Ok ", NULL);
 }
}



void Val_viewdist_CB(MOBJECT edit, EDIT_VAL *ev, void *ii)
{
 int val;

 sscanf(ev->text,"%d",&val);
 if ( (val >= 10) && (val <= 500)) {
    ev->text_validated = True;
    viewdist = (float) 0.01*val;
    update_fov_label();
 }
 else {
    ev->text_validated = False;
    MMessageDialog("Message",
                   "Distance must be >= 10 and <= 500", " Ok ", NULL);
 }
}



void Val_groundview_CB(MOBJECT edit, EDIT_VAL *ev, void *ii)
{
 int val;

 sscanf(ev->text,"%d",&val);
 if ( (val >= 4) && (val <= 10)) {
    ev->text_validated = True;
    ground_view = val;
 }
 else {
    ev->text_validated = False;
    MMessageDialog("Message",
                   "Distance must be >= 4 and <= 10", " Ok ", NULL);
 }
}



void Val_ncalc_CB(MOBJECT edit, EDIT_VAL *ev, void *ii)
{
 int val;

 sscanf(ev->text,"%d",&val);
 if ( (val >= 1) && (val <= 100)) {
    ev->text_validated = True;
    ncalcperframe = val;
 }
 else {
    ev->text_validated = False;
    MMessageDialog("Message",
                   "Number of iterations must be >= 1 and <= 100", " Ok ", NULL);
 }
}



void groundtype_radio_CB(MOBJECT rb, MVALUE status, void *ii)
{
 #include "../map.h"

 extern int airfieldalt;
 extern int horizon_color;
 extern float x,y,z;

 float oldgroundalt=0;

 if (!StartUp) oldgroundalt=groundalt(x,y);

 switch((int)ii) {

 case 1: groundtype = 1;
         MObjectSetSensitive(drawdist_edit);
         if (!StartUp && !setup && status) {
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

 case 2: groundtype = 0;
         MObjectSetUnsensitive(drawdist_edit);
         if (!StartUp && !setup && status) {
           airfieldalt=0;
           horizon_color=GREEN;
           z += groundalt(x,y)-oldgroundalt;
         }
         break;
 }
}




void graphics_CB(MOBJECT obj, void *item, void *udata)
{
 MOBJECT edit;
 MOBJECT geom_rform;
 MOBJECT ground_cform;
 MOBJECT rform, rb1, rb2;
 MOBJECT drawdist_rform;
 MOBJECT ncalc_rform;
 MOBJECT donebtn;
 MOBJECT mgbtn;
 char    tekst[10];

 setup=True;
 graphics_shell = MCreateShell("Graphics configuration", SF_MODAL | SF_IGNORE_WM_CLOSE);

 geom_rform = MCreateRowForm(graphics_shell);
 MCreateLabel(geom_rform, "Screen geometry",HELV_N_FONT);
 MCreateLabel(geom_rform, "Screen / window diagonal (inches)", TIMES_SMALL);
 sprintf(tekst,"%d",scrndiag);
 edit = MCreateEdit(geom_rform, tekst, 2, DEFAULT_FONT);
 MEditSetFilter(edit, DIGIT, "");
 MEditSetValCallback(edit, Val_scrndiag_CB, NULL);
#ifndef LINUX
 MEditSetValidatedColors(edit, cadetblue, white);
 MEditSetNotValidatedColors(edit, seagreen, black);
#endif
 MObjectSetPopupHelp(edit,
 "Enter diagonal length of your monitor or the window used, min 10in, max 50in."
  , 1000, 0);

 MCreateLabel(geom_rform, "Viewing distance (cm)", TIMES_SMALL);
 sprintf(tekst,"%d",(int)(100.001*viewdist));
 edit = MCreateEdit(geom_rform, tekst, 3, DEFAULT_FONT);
 MEditSetFilter(edit, DIGIT, "");
 MEditSetValCallback(edit, Val_viewdist_CB, NULL);
#ifndef LINUX
 MEditSetValidatedColors(edit, cadetblue, white);
 MEditSetNotValidatedColors(edit, seagreen, black);
#endif
 MObjectSetPopupHelp(edit,
 "Enter the distance from your eyes to the screen, min 10cm, max 500cm."
  , 1000, 0);

 MCreateLabel(geom_rform, "Current horizontal field of view:",TIMES_SMALL);
 fov_label = MCreateLabel(geom_rform, "", TIMES_SMALL);
 update_fov_label();

 ground_cform = MCreateColForm(graphics_shell);
 MObjectSetShadow(ground_cform, WS_NONE, 0, 0);

 rform = MCreateRowForm(ground_cform);
 MCreateLabel(rform, "Ground type", HELV_N_FONT);
 rb1 = MCreateRButton(rform, "Fractal", TIMES_N_FONT);
 MTButtonSetCallback(rb1, groundtype_radio_CB, (void *)1);
 MObjectSetPopupHelp(rb1,
 "Use this for nice graphics on fast machines."
  , 1000, 0);
 rb2 = MCreateRButton(rform, "Flat", TIMES_N_FONT);
 MTButtonSetCallback(rb2, groundtype_radio_CB, (void *)2);
 MObjectSetPopupHelp(rb2,
 "Use this for good frame rate on slow machines."
  , 1000, 0);

 drawdist_rform = MCreateRowForm(ground_cform);
 MCreateLabel(drawdist_rform, "Landscape drawing distance (km)", TIMES_SMALL);
 sprintf(tekst,"%d",ground_view);
 drawdist_edit = MCreateEdit(drawdist_rform, tekst, 2, DEFAULT_FONT);
 MEditSetFilter(drawdist_edit, DIGIT, "");
 MEditSetValCallback(drawdist_edit, Val_groundview_CB, NULL);
#ifndef LINUX
 MEditSetValidatedColors(drawdist_edit, cadetblue, white);
 MEditSetNotValidatedColors(drawdist_edit, seagreen, black);
#endif
 MObjectSetPopupHelp(drawdist_edit,
 "To increase frame rate, use a small value. Min 4km, max 10km."
  , 1000, 0);

 if (groundtype > 0 )
    MRButtonActivate(rb1);
 if (groundtype == 0 )
    MRButtonActivate(rb2);

 ncalc_rform = MCreateRowForm(graphics_shell);
 MCreateLabel(ncalc_rform, "Number of model iterations per screen update", TIMES_SMALL);
 sprintf(tekst,"%d",ncalcperframe);
 ncalc_edit = MCreateEdit(ncalc_rform, tekst, 2, DEFAULT_FONT);
 MEditSetFilter(ncalc_edit, DIGIT, "");
 MEditSetValCallback(ncalc_edit, Val_ncalc_CB, NULL);
#ifndef LINUX
 MEditSetValidatedColors(ncalc_edit, cadetblue, white);
 MEditSetNotValidatedColors(ncalc_edit, seagreen, black);
#endif
 MObjectSetPopupHelp(ncalc_edit,
 "Set this so you have 50 to 100 iterations per second. Min 1, max 100"
  , 1000, 0);



 mgbtn = MCreatePButton(graphics_shell, "More graphics options", TIMES_N_FONT);
 MPButtonSetCallback(mgbtn, more_graphics_CB, graphics_shell);
 MObjectSetPopupHelp(mgbtn,
     "Click here for more graphics options", 1000, 0);

 donebtn = MCreatePButton(graphics_shell, "Done", TIMES_N_FONT);
 MPButtonSetCallback(donebtn, graphics_done_CB, graphics_shell);
 MObjectSetPopupHelp(donebtn,
     "Click here when you are finished configuring graphics", 1000, 0);

 setup=False;
 MShellRealize (graphics_shell);
 MObjectSetUnsensitive(shell);
}


/**********************/
/* Calibrate joystick */
/**********************/


void calib_done_CB(MOBJECT obj, void *a, void *cshell)
{
 cancel_calibrate=true;
}



void continue_calib_CB(MOBJECT obj, void *a, void *cshell)
{
 continue_calibrate=true;
}



void CalibTimerCB(TIMEOUT_ID id, void *sbar)
{
	char str[128];
   static int joyxlow,joyxhi,joyylow,joyyhi,joy2xlow,joy2xhi,diff;

   joymask=15;

   readjoy(s,joymask);

   sprintf(str,"X1:%4.0i Y1:%4.0i X2:%4.0i Y2:%4.0i    ",
               s->a[0],s->a[1],s->a[2],s->a[3]);
	MObjectSetText(joypos_label, str);

   switch(calib_phase) {

    case  0: /* Wait for button release */
             MDrawFilledBox(joy_draw,0,0,127,127,white);
             if (s->b[0]!=1)
                calib_phase++;
             break;

    case  1: /* Ask for center position */
             if (rudder_type==1)
	             sprintf(str,"Center stick and rudder, then press [Fire] or [Continue]");
             else
	             sprintf(str,"Center stick, then press [Fire] or [Continue]");
             MObjectSetText(calib_instruct_label, str);
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
             MObjectSetText(calib_instruct_label, str);
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
             MObjectSetText(calib_instruct_label, str);
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

    case 10: /* Ask for hat up position */
             sprintf(str,"Move hat up, then press [Fire] or [Continue]");
             MObjectSetText(calib_instruct_label, str);
             calib_phase++;
             break;

    case 11: /* Get hat up position */
             if (s->b[0]==1 || continue_calibrate) {
                hatup=s->a[3];
                calib_phase++;
             }
             break;

    case 12: /* Wait for button release */
             if (s->b[0]!=1)
                calib_phase++;
             continue_calibrate=false;
             break;

    case 13: /* Ask for hat down position */
             sprintf(str,"Move hat down, then press [Fire] or [Continue]");
             MObjectSetText(calib_instruct_label, str);
             calib_phase++;
             break;

    case 14: /* Get hat down position */
             if (s->b[0]==1 || continue_calibrate) {
                hatdown=s->a[3];
                diff=hatdown-hatup;
                if (diff!=0) joy2ygain=450/((float)diff);
                else joy2ygain=0;
                hatup   *= joy2ygain;
                hatdown *= joy2ygain;
                calib_phase++;
             }
             break;

    case 15: /* Wait for button release */
             if (s->b[0]!=1)
                calib_phase++;
             continue_calibrate=false;
             break;

    case 16: /* Ask for hat left position */
             sprintf(str,"Move hat left, then press [Fire] or [Continue]");
             MObjectSetText(calib_instruct_label, str);
             calib_phase++;
             break;

    case 17: /* Get hat left position */
             if (s->b[0]==1 || continue_calibrate) {
                hatleft=s->a[3];
                hatleft  *= joy2ygain;
                calib_phase++;
             }
             break;

    case 18: /* Wait for button release */
             if (s->b[0]!=1)
                calib_phase++;
             continue_calibrate=false;
             break;

    case 19: /* Ask for hat right position */
             sprintf(str,"Move hat right, then press [Fire] or [Continue]");
             MObjectSetText(calib_instruct_label, str);
             calib_phase++;
             break;

    case 20: /* Get hat right position */
             if (s->b[0]==1 || continue_calibrate) {
                hatright=s->a[3];
                hatright  *= joy2ygain;
                calib_phase++;
             }
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
             MObjectSetText(calib_instruct_label, str);
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
             MObjectSetText(calib_instruct_label, str);
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
             MObjectSetText(calib_instruct_label, str);
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


	if (calib_phase < 31 && !cancel_calibrate) {
      int x1=s->a[0];
      int y1=s->a[1];
      int x2=s->a[2];
      int y2=s->a[3];

      if (test_calib) {
        int joyx, joyy, joy2x, joy2y;

        joyx=s->a[0]-joyxzero;
        if (joyx>0) { joyx -= nullzone; if (joyx<0) joyx=0; }
        else { joyx += nullzone; if (joyx>0) joyx=0;}
        joyx *= joyxgain;
        if (fabs(joyx) > 300) joyx=sgn(joyx)*300;

        x1=joyx/6 + 50;

        joyy=s->a[1]-joyyzero;
        if (joyy>0) { joyy -= nullzone; if (joyy<0) joyy=0; }
        else { joyy += nullzone; if (joyy>0) joyy=0;}
        joyy *= joyygain;
        if (fabs(joyy) > 300) joyy=sgn(joyy)*300;

        y1=joyy/6 + 50;

        if (rudder_type==1) {
           joy2x=s->a[2]-joy2xzero;
           if (joy2x>0) { joy2x -= nullzone; if (joy2x<0) joy2x=0; }
           else { joy2x += nullzone; if (joy2x>0) joy2x=0;}
           joy2x *= joy2xgain;
           if (fabs(joy2x) > 300) joy2x=sgn(joy2x)*300;

           x2=joy2x*2 + 54;
        }
        else
          x2=54;

        if (throttle_type==1) { /* Analog throttle */
           joy2y=s->a[3];
           /*
           y2=100-(100.0*(joy2y-throttle_mil))/(throttle_idle-throttle_mil);
           if (y2 > 100) y2=100;
           if (y2 <   0) y2=  0;

           y2=y2+4;
           */
           y2=(100.0*(joy2y-throttle_mil))/(throttle_idle-throttle_mil);
           if (y2 > 100) y2=100;
           if (y2 <   0) y2=  0;

           y2=y2+4;
        }
        else
          y2=54;

        MDrawLine(joy_draw, 54, 0, 54, 108, cadetblue);
        MDrawLine(joy_draw, 0, 54, 108, 54, cadetblue);
      }
      else {
        if ((x1 < 0) || (x1 > 2000)) x1 = 100;
        else x1/=20;

        if ((y1 < 0) || (y1 > 2000)) y1 = 100;
        else y1/=20;

        if ((x2 < 0) || (x2 > 2000)) x2 = 100;
        else x2/=20;

        if ((y2 < 0) || (y2 > 2000)) y2 = 100;
        else y2/=20;
      }

      if (lastx1!=x1 || lasty1!=y1) {
         MDrawLine(joy_draw, lastx1+4, lasty1, lastx1+4, lasty1+8, white);
         MDrawLine(joy_draw, lastx1, lasty1+4, lastx1+8, lasty1+4, white);
      }
      MDrawLine(joy_draw, x1+4, y1, x1+4, y1+8, black);
      MDrawLine(joy_draw, x1, y1+4, x1+8, y1+4, black);

      if (lastx2!=x2)
         MDrawLine(joy_draw,lastx2,100,lastx2,107,white);
      MDrawLine(joy_draw,    x2,100,    x2,107,black);

      if (lasty2!=y2)
         MDrawLine(joy_draw, 100, lasty2, 107, lasty2, white);
      MDrawLine(joy_draw, 100, y2, 107, y2, black);


      lastx1=x1;
      lasty1=y1;
      lastx2=x2;
      lasty2=y2;
   	MAddTimeout(10L, CalibTimerCB, sbar);
   }
   else {
      MShellUnrealize((MOBJECT) sbar);
      MShellDestroy(  (MOBJECT) sbar);
      MObjectSetSensitive(ctrl_shell);
   }


}



void calib_CB(MOBJECT obj, void *item, void *udata)
{
 MOBJECT calib_shell;
 MOBJECT donebtn, nextbtn;

 calib_shell = MCreateShell("Joystick calibration", SF_MODAL | SF_IGNORE_WM_CLOSE);

 calib_instruct_label=MCreateLabel(calib_shell,
 "-----------------------Release fire button-----------------------",
 HELV_N_FONT);

 joy_draw = MCreateDrawArea(calib_shell, 109, 109);

 joypos_label=MCreateLabel(calib_shell,"",HELV_N_FONT);

 nextbtn = MCreatePButton(calib_shell, "Continue", TIMES_L_FONT);
 MPButtonSetCallback(nextbtn, continue_calib_CB, calib_shell);
 MObjectSetResize(nextbtn, False, False);
 MObjectSetPopupHelp(nextbtn,
     "Click here for next calibration step", 1000, 0);

 donebtn = MCreatePButton(calib_shell, "Cancel", TIMES_L_FONT);
 MPButtonSetCallback(donebtn, calib_done_CB, calib_shell);
 MObjectSetResize(donebtn, False, False);
 MObjectSetPopupHelp(donebtn,
     "Click here to abort the calibration", 1000, 0);

 calib_phase=0;
 cancel_calibrate=false;
 continue_calibrate=false;
 lastx1=lasty1=lastx2=lasty2=0;
 test_calib=false;

 MAddTimeout(10L, CalibTimerCB, calib_shell);

 MShellRealize (calib_shell);
 MObjectSetUnsensitive(ctrl_shell);

}



void joy_center_CB()
{
 readjoy(s,15);
 joyxzero=s->a[0];
 joyyzero=s->a[1];
 joy2xzero=s->a[2];
}



/*******************/
/* Controls config */
/*******************/



void linexp_CB(MOBJECT rb, MVALUE status, void *ii)
{

 if (status) {

   switch((int)ii) {

   case 1: ctrlexpo=true;
           break;

   case 2: ctrlexpo=false;
           break;
   }
 }
}



void stick_select_CB(MOBJECT rb, MVALUE status, void *ii)
{

 if (status) {

   switch((int)ii) {

   case 1: stick_type=1;
           mouse_active=false;
           if (!setup) {
              MObjectSetSensitive(calibbtn);
              MObjectSetSensitive(recenterbtn);
           }
           break;

   case 2: stick_type=2;
           mouse_active=false;
           if (!setup) {
              MObjectSetSensitive(calibbtn);
              MObjectSetSensitive(recenterbtn);
              MRButtonActivate(key_throttle_rb);
           }
           break;

   case 3: stick_type=0;
           mouse_active=true;
           if (!setup) {
              MObjectSetUnsensitive(calibbtn);
              MObjectSetUnsensitive(recenterbtn);
              MRButtonActivate(key_rudder_rb);
              MRButtonActivate(key_throttle_rb);
           }
           break;
   }
 }
}



void throttle_select_CB(MOBJECT rb, MVALUE status, void *ii)
{

 if (status) {

   switch((int)ii) {

   case 1: throttle_type=1;
           /* Caution: assumes stick is available */
           if (stick_type==0 || stick_type==2)
              MRButtonActivate(joy2_rb);
           break;

   case 2: throttle_type=0;
           break;
   }

 }
}



void rudder_select_CB(MOBJECT rb, MVALUE status, void *ii)
{

 if (status) {

   switch((int)ii) {

   case 1: rudder_type=1;
           /* Caution: assumes stick is available */
           if (stick_type==0)
              MRButtonActivate(joy2_rb);
           break;

   case 2: rudder_type=0;
           break;
   }

 }
}



void Val_nullzone_CB(MOBJECT edit, EDIT_VAL *ev, void *ii)
{
 int val;

 sscanf(ev->text,"%d",&val);
 if ( (val >= 0) && (val <= 100)) {
    ev->text_validated = True;

    nullzone = val;

 }
 else {
    ev->text_validated = False;
    MMessageDialog("Message", "Null zone must be between 0 and 100", " Ok ", NULL);
 }
}



void Val_noisefilter_CB(MOBJECT edit, EDIT_VAL *ev, void *ii)
{
 int val;

 sscanf(ev->text,"%d",&val);
 if ( (val >= 1) && (val <= 5)) {
    ev->text_validated = True;

    joy_n_sample = val;

 }
 else {
    ev->text_validated = False;
    MMessageDialog("Message", "Filter strength must be between 1 and 5", " Ok ", NULL);
 }
}



bool calibration_ok()
{
 bool status = true;

 if (joyxzero==0 && stick_type!=0)
    status=false;
 if (joyyzero==0 && stick_type!=0)
    status=false;
 if (joy2xzero==0 && rudder_type==1)
    status=false;
 if (throttle_idle==throttle_mil && throttle_type==1)
    status=false;
 if (hatup==hatdown && stick_type==2)
    status=false;

 return status;
}



void ctrl_done_CB(MOBJECT obj, void *a, void *cshell)
{
 if (!calibration_ok()) {
    MMessageDialog("Message", "You must calibrate first", " Ok ", NULL);
    return;
 }

 MShellUnrealize((MOBJECT )cshell);
 MShellDestroy((MOBJECT )cshell);
 MObjectSetSensitive(shell);
}



void ctrl_CB(MOBJECT obj, void *item, void *udata)
{
 MOBJECT donebtn;
 MOBJECT ctrl_sel_rform;
 MOBJECT ctrl_cform;
 MOBJECT stick_rform, throttle_rform, rudder_rform;
 MOBJECT rb;
 MOBJECT calib_cform;
 MOBJECT linexp_rform, linexp_cform;
 MOBJECT edit_cform, null_rform, noise_rform, edit;
 char    tekst[10];
 int     analog_status=15;


 #ifndef LINUX
  analog_status=readjoy(s,15);
 #endif

 setup=true;

 ctrl_shell = MCreateShell("Controls configuration", SF_MODAL | SF_IGNORE_WM_CLOSE);

 ctrl_sel_rform=MCreateRowForm(ctrl_shell);

 MCreateLabel(ctrl_sel_rform, "Controller selection", HELV_N_FONT);

 ctrl_cform=MCreateColForm(ctrl_sel_rform);
 MObjectSetShadow(ctrl_cform, WS_NONE, 0, 0);

 stick_rform=MCreateRowForm(ctrl_cform);
 MCreateLabel(stick_rform, "Stick", HELV_N_FONT);

 joy2_rb = MCreateRButton(stick_rform, "2-button stick", TIMES_N_FONT);
 MTButtonSetCallback(joy2_rb, stick_select_CB, (void *)1);
 MObjectSetPopupHelp(joy2_rb,
 "E.g. Standard joystick, Thrustmaster F-16 FLCS, ..."
  , 1000, 0);
 if (analog_status & 3)
    MObjectSetUnsensitive(joy2_rb);
 else
    if (stick_type==1)
       MRButtonActivate(joy2_rb);


 joy4_rb = MCreateRButton(stick_rform, "4-button stick w. 4-way hat", TIMES_N_FONT);
 MTButtonSetCallback(joy4_rb, stick_select_CB, (void *)2);
 MObjectSetPopupHelp(joy4_rb,
 "E.g. Wingman Extreme, ..."
  , 1000, 0);
 if (analog_status & 11)
    MObjectSetUnsensitive(joy4_rb);
 else
    if (stick_type==2)
       MRButtonActivate(joy4_rb);

 rb = MCreateRButton(stick_rform, "Mouse", TIMES_N_FONT);
 MTButtonSetCallback(rb, stick_select_CB, (void *)3);
 MObjectSetPopupHelp(rb,
 "Only use this, if you don't have a joystick."
  , 1000, 0);
 if (!mouse_avail)
    MObjectSetUnsensitive(rb);
 if (mouse_active)
    MRButtonActivate(rb);




 throttle_rform=MCreateRowForm(ctrl_cform);
 MCreateLabel(throttle_rform, "Throttle", HELV_N_FONT);

 analog_throttle_rb = MCreateRButton(throttle_rform, "Analog throttle", TIMES_N_FONT);
 MTButtonSetCallback(analog_throttle_rb, throttle_select_CB, (void *)1);
 MObjectSetPopupHelp(analog_throttle_rb,
 "E.g. Thrustmaster F-16 TQS, ..."
  , 1000, 0);
 if (analog_status & 8)
   MObjectSetUnsensitive(analog_throttle_rb);
 else
   if (throttle_type==1)
      MRButtonActivate(analog_throttle_rb);

 key_throttle_rb = MCreateRButton(throttle_rform, "Keyboard", TIMES_N_FONT);
 MTButtonSetCallback(key_throttle_rb, throttle_select_CB, (void *)2);
 MObjectSetPopupHelp(key_throttle_rb,
 "Keyboard"
  , 1000, 0);
 if (throttle_type==0)
    MRButtonActivate(key_throttle_rb);


 rudder_rform=MCreateRowForm(ctrl_cform);
 MCreateLabel(rudder_rform, "Rudder", HELV_N_FONT);

 analog_rudder_rb = MCreateRButton(rudder_rform, "Analog rudder pedals", TIMES_N_FONT);
 MTButtonSetCallback(analog_rudder_rb, rudder_select_CB, (void *)1);
 MObjectSetPopupHelp(analog_rudder_rb,
 "E.g. Thrustmaster RCS, ..."
  , 1000, 0);
 if (analog_status & 4)
   MObjectSetUnsensitive(analog_rudder_rb);
 else
   if (rudder_type==1)
      MRButtonActivate(analog_rudder_rb);

 key_rudder_rb = MCreateRButton(rudder_rform, "Keyboard", TIMES_N_FONT);
 MTButtonSetCallback(key_rudder_rb, rudder_select_CB, (void *)2);
 MObjectSetPopupHelp(key_rudder_rb,
 "Keyboard"
  , 1000, 0);
 if (rudder_type==0)
    MRButtonActivate(key_rudder_rb);


 calib_cform=MCreateColForm(ctrl_shell);
 MObjectSetShadow(calib_cform, WS_NONE, 0, 0);

 calibbtn = MCreatePButton(calib_cform, "Calibrate", TIMES_L_FONT);
 MPButtonSetCallback(calibbtn, calib_CB, NULL);
 MObjectSetResize(calibbtn, False, False);
 MObjectSetPopupHelp(calibbtn,
     "For calibrating analog controls", 1000, 0);



 recenterbtn = MCreatePButton(calib_cform, "Re-center", TIMES_L_FONT);
 MPButtonSetCallback(recenterbtn, joy_center_CB, NULL);
 MObjectSetResize(recenterbtn, False, False);
 MObjectSetPopupHelp(recenterbtn,
     "For quick centering of analog controls", 1000, 0);

 if (stick_type==0) {
    MObjectSetUnsensitive(calibbtn);
    MObjectSetUnsensitive(recenterbtn);
 }

 linexp_rform=MCreateRowForm(ctrl_shell);

 MCreateLabel(linexp_rform, "Response type", TIMES_SMALL);

 linexp_cform=MCreateColForm(linexp_rform);
 MObjectSetShadow(linexp_cform, WS_NONE, 0, 0);

 rb = MCreateRButton(linexp_cform, "Exponential", TIMES_N_FONT);
 MRButtonSetCallback(rb, linexp_CB, (void *)1);
 MObjectSetPopupHelp(rb,
 "Small gain at small deflection and vice versa"
  , 1000, 0);
 if (ctrlexpo)
   MRButtonActivate(rb);

 rb = MCreateRButton(linexp_cform, "Linear", TIMES_N_FONT);
 MRButtonSetCallback(rb, linexp_CB, (void *)2);
 MObjectSetPopupHelp(rb,
 "Even sensitivity"
  , 1000, 0);
 if (!ctrlexpo)
   MRButtonActivate(rb);


 edit_cform=MCreateColForm(ctrl_shell);
 MObjectSetShadow(edit_cform, WS_NONE, 0, 0);

 null_rform=MCreateRowForm(edit_cform);
 MCreateLabel(null_rform, "Joystick null zone", TIMES_SMALL);
 sprintf(tekst,"%d", nullzone);
 edit = MCreateEdit(null_rform, tekst, 3, DEFAULT_FONT);
 MEditSetFilter(edit, DIGIT, "");
 MEditSetValCallback(edit, Val_nullzone_CB, NULL);
#ifndef LINUX
 MEditSetValidatedColors(edit, cadetblue, white);
 MEditSetNotValidatedColors(edit, seagreen, black);
#endif
 MObjectSetPopupHelp(edit,
 "Set the size of a central region with no control response, 0 <= size <= 100"
  , 1000, 0);


 noise_rform=MCreateRowForm(edit_cform);
 MCreateLabel(noise_rform, "Joystick noise filter", TIMES_SMALL);
 sprintf(tekst,"%d", joy_n_sample);
 edit = MCreateEdit(noise_rform, tekst, 3, DEFAULT_FONT);
 MEditSetFilter(edit, DIGIT, "");
 MEditSetValCallback(edit, Val_noisefilter_CB, NULL);
#ifndef LINUX
 MEditSetValidatedColors(edit, cadetblue, white);
 MEditSetNotValidatedColors(edit, seagreen, black);
#endif
 MObjectSetPopupHelp(edit,
 "Enter 1 if no joystick jitter is present, or up to 5 otherwise"
  , 1000, 0);




 donebtn = MCreatePButton(ctrl_shell, "Done", TIMES_L_FONT);
 MPButtonSetCallback(donebtn, ctrl_done_CB, ctrl_shell);
 MObjectSetResize(donebtn, False, False);
 MObjectSetPopupHelp(donebtn,
     "Click here when you are finished defining controls", 1000, 0);

 setup=false;

 MShellRealize (ctrl_shell);
 MObjectSetUnsensitive(shell);
}



/********************/
/* Set sound volume */
/********************/

#ifdef ALLEGRO

void sound_done_CB(MOBJECT obj, void *a, void *sshell)
{
 MShellUnrealize((MOBJECT )sshell);
 MShellDestroy((MOBJECT )sshell);
 MObjectSetSensitive(shell);
}

 

void Val_vol_CB(MOBJECT edit, EDIT_VAL *ev, void *ii)
{
 int val;

 sscanf(ev->text,"%d",&val);
 if ( (val > -1) && (val < 256)) {
    ev->text_validated = True;
    switch((int) ii) {
      case 1: talk_volume = val;
              break;
      case 2: engine_volume = val;
              break;
      case 3: effect_volume = val;
              break;
    }
 }
 else {
    ev->text_validated = False;
    MMessageDialog("Message", "Volume must be >=0 and < 256", " Ok ", NULL);
 }
}



void sound_CB(MOBJECT obj, void *item, void *udata)
{
 MOBJECT sound_shell;
 MOBJECT edit;
 MOBJECT donebtn;
 char    tekst[10];

 sound_shell = MCreateShell("Sound volume", SF_MODAL | SF_IGNORE_WM_CLOSE);

 MCreateLabel(sound_shell, "Speech volume", TIMES_SMALL);
 sprintf(tekst,"%d",talk_volume);
 edit = MCreateEdit(sound_shell, tekst, 3, DEFAULT_FONT);
 MEditSetFilter(edit, DIGIT, "");
 MEditSetValCallback(edit, Val_vol_CB, (void *) 1);
#ifndef LINUX
 MEditSetValidatedColors(edit, cadetblue, white);
 MEditSetNotValidatedColors(edit, seagreen, black);
#endif

 MCreateLabel(sound_shell, "Engine volume", TIMES_SMALL);
 sprintf(tekst,"%d",engine_volume);
 edit = MCreateEdit(sound_shell, tekst, 3, DEFAULT_FONT);
 MEditSetFilter(edit, DIGIT, "");
 MEditSetValCallback(edit, Val_vol_CB, (void *) 2);
#ifndef LINUX
 MEditSetValidatedColors(edit, cadetblue, white);
 MEditSetNotValidatedColors(edit, seagreen, black);
#endif

 MCreateLabel(sound_shell, "Miscellaneous volume", TIMES_SMALL);
 sprintf(tekst,"%d",effect_volume);
 edit = MCreateEdit(sound_shell, tekst, 3, DEFAULT_FONT);
 MEditSetFilter(edit, DIGIT, "");
 MEditSetValCallback(edit, Val_vol_CB, (void *) 3);
#ifndef LINUX
 MEditSetValidatedColors(edit, cadetblue, white);
 MEditSetNotValidatedColors(edit, seagreen, black);
#endif

 /* ScrollBar: ver 1.9.8 */
 /* 2nd par: 0:hor 1:vert */
 /* 3rd par: ? */
 /*
 MCreateLabel(sound_shell, "Miscellaneous volume", TIMES_SMALL);
 sprintf(tekst,"%d",effect_volume);
 edit = MCreateScrollBar(sound_shell, 0, 10, 255);
 MScrollBarSetPos(edit, effect_volume);
 MScrollBarSetIncr(edit,4);
 */

 donebtn = MCreatePButton(sound_shell, "Done", TIMES_N_FONT);
 MPButtonSetCallback(donebtn, sound_done_CB, sound_shell);
 MObjectSetPopupHelp(donebtn,
     "Click here when you are finished setting volume", 1000, 0);

 MShellRealize (sound_shell);
 MObjectSetUnsensitive(shell);
}

#endif



/*******************/
/* View text shell */
/*******************/

void view_done_CB(MOBJECT obj, void *a, void *vshell)
{
  MShellUnrealize((MOBJECT )vshell);
  MShellDestroy((MOBJECT )vshell);
  MObjectSetSensitive(shell);
}



void view_CB(MOBJECT obj, void *item, void *udata)
{
 MOBJECT view_shell;
 MOBJECT donebtn;
 MOBJECT sfile;
 int subject = (int) udata;
 char title[80]="";
 char filename[80]="";

 switch (subject)
 {
  case 1: strcpy(title,"View documentation");
          strcpy(filename,"vertigo.txt");
          break;

  case 2: strcpy(title,"Keyboard reference");
          strcpy(filename,"keys.txt");
          break;

  case 3: strcpy(title,"Installation instructions");
          strcpy(filename,"install.txt");
          break;

  default: ;
 }

 view_shell = MCreateShell(title, SF_MODAL | SF_IGNORE_WM_CLOSE);

 sfile=MCreateSFile(view_shell, filename, FIXED_SMALL, 20, 80);

 donebtn = MCreatePButton(view_shell, "Close", TIMES_L_FONT);
 MPButtonSetCallback(donebtn, view_done_CB, view_shell);
 MObjectSetResize(donebtn, False, False);
 MObjectSetPopupHelp(donebtn,
     "Click here when you are finished viewing", 1000, 0);

 MShellRealize (view_shell);
 MObjectSetUnsensitive(shell);
}



void ExitCB(MOBJECT obj, void *a, void *shell)
{

/*
        MObjectSetUnsensitive(shell);
        if (MMessageDialog("Exit",
          "Do you really\nwant to quit ?",
          "Yes", "Cancel", NULL) != 0) {
                        MObjectSetSensitive(shell);
                        return;
                        }
*/
        MShellUnrealize((MOBJECT )shell);
        MShellDestroy((MOBJECT )shell);

        crash   = true;
        exitGUI = True;
}



void FlyCB(MOBJECT obj, void *a, void *shell)
{
 if (!mouse_avail && stick_type==0) {
    MObjectSetUnsensitive(shell);
    MMessageDialog("Message", "Please set up your joystick before flying.", "Ok", NULL);
    MObjectSetSensitive(shell);
 }
 else {
        MShellUnrealize((MOBJECT )shell);
        MShellDestroy((MOBJECT )shell);

        exitGUI = True;
 }
}



void main_menu_form(bool startup)
{
  MOBJECT menu;
  MOBJECT options_pdown, config_pdown, help_pdown;
  MOBJECT bottomrow, bottombtn;
  PULLDOWN_ITEM aircraft_pd_id, location_pd_id, time_pd_id, realism_pd_id, fuelload_pd_id;
  PULLDOWN_ITEM graphics_pd_id, controls_pd_id;
  PULLDOWN_ITEM view_docs_pd_id, view_install_pd_id;
  PULLDOWN_ITEM view_keys_pd_id;
#ifdef ALLEGRO
  PULLDOWN_ITEM sound_pd_id;
#endif
  char text[80]="";

  if (startup)
     setup_gui_pallette();
  /*
  else
     GrRestoreColors(color_buffer);
	 */

  StartUp      = startup;
  exitGUI      = False;
  wind_changed = False;
  setup        = True;

  shell = MCreateShell("Vertigo main menu", SF_IGNORE_WM_CLOSE);

  /* Aircraft selection */
  menu = MCreateMenuBar(shell, HELV_L_FONT);
  MObjectSetFont(menu,TIMES_N_FONT,0);
  set_model=current_model;
  model_changed = false;

  
  /* Flight options */
  options_pdown  = MCreatePullDown(menu, "Options");
  aircraft_pd_id = MPullDownAddItem(options_pdown, "Aircraft", aircraft_CB, NULL);
  if (startup)
	location_pd_id = MPullDownAddItem(options_pdown, "Location", location_CB, NULL);
  time_pd_id     = MPullDownAddItem(options_pdown, "Time", time_CB, NULL);
  realism_pd_id  = MPullDownAddItem(options_pdown, "Realism", realism_CB, NULL);
  fuelload_pd_id = MPullDownAddItem(options_pdown, "Fuel load", fuelload_CB, NULL);


  /* Program config */
  config_pdown = MCreatePullDown(menu, "Config");
  graphics_pd_id = MPullDownAddItem(config_pdown,
                                    "Graphics", graphics_CB, NULL);
  controls_pd_id = MPullDownAddItem(config_pdown, "Controls", ctrl_CB, NULL);
#ifdef ALLEGRO
  sound_pd_id    = MPullDownAddItem(config_pdown, "Sound", sound_CB, NULL);
#endif

  /* Help */
  help_pdown = MCreatePullDown(menu, "Help");
  view_docs_pd_id    = MPullDownAddItem(help_pdown,
                       "Documentation", view_CB, (void *) 1);
  view_keys_pd_id    = MPullDownAddItem(help_pdown,
                       "Key layout",    view_CB, (void *) 2);
  view_install_pd_id = MPullDownAddItem(help_pdown,
                       "Installation",  view_CB, (void *) 3);

  /* About */
  MCreateLabel(shell, "The", HELV_N_FONT);
  MCreateLabel(shell, "Vertigo", HELV_L_FONT);
  MCreateLabel(shell, "flight simulator", HELV_N_FONT);
  strcpy(text, "Version ");
  strcat(text, VERSION);
  strcat(text, ", ");
  strcat(text, DATE);
  MCreateLabel(shell, text, HELV_N_FONT);
#ifdef LINUX
  MCreateLabel(shell, "By Anton Norup Sørensen", TIMES_SMALL);
#else
  MCreateLabel(shell, "By Anton Norup Sorensen", TIMES_SMALL);
#endif

  MCreateLabel(shell, "This program is FREEWARE", TIMES_N_FONT);
  MCreateLabel(shell, "Source distributed under:", TIMES_N_FONT);
  MCreateLabel(shell, "GNU General Public License", TIMES_N_FONT);


  /* Buttons at bottom */
  bottomrow = MCreateColForm(shell);
  bottombtn = MCreatePButton(bottomrow, "Fly!", TIMES_L_FONT);
  MPButtonSetCallback(bottombtn, FlyCB, shell);
  MObjectSetPopupHelp(bottombtn, "Click here to start flying", 1000, 0);
  bottombtn = MCreatePButton(bottomrow, "Quit", TIMES_L_FONT);
  /* Makes l-r spacing wider */
  MObjectSetAttachment(bottombtn, True, True, False, True);
  MPButtonSetCallback(bottombtn, ExitCB, shell);
  MObjectSetPopupHelp(bottombtn, "Click here to exit from program", 1000, 0);
  MShellRealize (shell);
  /* MShellRealizeXY (shell,0,0); */

  /* Accept input */
  setup = False;
  MLoopWhileFlag(&exitGUI, false);


  /*
  if (startup) {
     int size = GrColorSaveBufferSize();

     color_buffer = malloc(size);
     if (color_buffer)
        GrSaveColors(color_buffer);
     else
        mgerror("Not enough memory for color buffer");
  }
  */


  /* Erase window (does not work!) */
  MShellUnrealize(shell);
  MShellDestroy(shell);

  /* Quit? */
  if (crash==true) {
   MGUITerm();

   free(color_buffer);

   save_config();
   errorexit(0);
  }

  /* Apply user selections */
  if (model_changed == true) {
     dial_cleanup();
     make_instruments();
  }
  if (!startup) {
    if (wind_changed) {
      init_wind(0,179);
      report_wind();
      update_windbag();
    }
  }

  save_config();
}

