
/*
    This file is part of the source code for the Vertigo flight simulator
    Copyright (C) 1998-2001 Anton Norup Soerensen, a_norup@post.tele.dk

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

/*
#define DEBUG true
*/

/*
#define TIMESTAT true
*/

/*
#define MATRIX true
*/
/*
#define NO_RANDOMIZE true
*/

#define BLACK 0
#define BLUE 1
#define GREEN 2
#define CYAN 3
#define RED 4
#define MAGENTA 5
#define BROWN 6
#define LIGHTGRAY 7
#define DARKGRAY 8
#define LIGHTBLUE 9
#define LIGHTGREEN 10
#define LIGHTCYAN 11
#define LIGHTRED 12
#define LIGHTMAGENTA 13
#define YELLOW 14
#define WHITE 15

#ifdef LINUX
#  define cprintf printf
#endif

#define VERSION "0.26"
#define DATE    "April 2002"

#define nmodels 9
#define maxnwingsections 10
#define maxnelements 10
#define maxnjetengines 4
#define maxnpropengines 4
#define maxnrocketengines 4
#define maxngears 4
#define maxnhardpts 6
#define maxnguns 6
#define maxnfueltanks 6

#define elevatorid 1     /* Common to ALL models, except F-14 */
#define rudderid 2
#define stbflapid 3
#define portflapid 4
#define stbaileronid 5
#define portaileronid 6
#define steerwhlid 0

#ifndef LINUX
#  define cnf_file "VER_CFG.GCC"
#else
#  define cnf_file "ver_cfg.lnx"

#endif

#define tickspersec 1000



typedef struct {
	float area;
	float aspect;
	float dragcoeff;
	float masscenter;
	float liftcenter;
	float dragcenter;
	float deflect;
	float oswald;         /* Induced drag efficiency factor */
} specs;

typedef struct {
	float weight;
	float topcurvature;
	specs front,left,top;
} aeroelement;



enum airfoilid {
	GENERIC      =  0,
	NACA0012     =  1             /* Not enabled currently */
};



typedef struct {
	float      area;
	float      aspect;
	float      sweepback;
	float      dihedral;
	float      pitchup;
	float      weight;
	enum airfoilid airfoiltype;
	float      oswald;                /* Induced drag efficiency factor */
	float      deflect;
	cartvektor aerocenter;
	cartvektor masscenter;
	cartvektor normal;
	cartvektor leadingedge;
	float      ailerongain;
	float      curvature;             /* Parameter for the generic profile */
} wingspecs;



typedef struct {
	float weight;
	specs front,left,top;
	float throttle,rpm;

	float response;  /* Simple model only */
	float power;     /* Simple model only */

	float vectoruplim,vectordnlim;
	float vectorpos,vectordesire;
	float vectorresponse;

   float rpm_response;   /* %/sec */
   float ab_response;    /* stages/sec */
   float idle_rpm;       /* % */

   float idle_thrust;    /* Newton */
   float mil_thrust;     /* Newton */
   float ab_stg_thrust;  /* Newton */

   int   n_abstages;
   int   ab_throttle;
   float ab_status;

   float idle_fflow;     /* kg/sec */
   float mil_fflow;      /* kg/sec */
   float ab_stg_fflow;   /* kg/sec */
   float fflw;

   float stall_pitchup;
   float stall_pitchdown;
   float stall_yawleft;
   float stall_yawright;

   float egt;

   float inlet_ramp_m0;
   float inlet_ramp_slope;

   bool  ignition;
   bool  compressor_stall;

} jetengine;

typedef struct {
	float weight;
	specs front,left,top;
	float throttle,rpm,rpm_percent,last_rpm;
   float rpm_omega_idle,rpm_omega_high;
	float response;
	float power,torque;
   cartvektor spinnerloc;
   float inertimoment;
   float radius;
   float aspect_ratio;
   float pitch, min_pitch, max_pitch;
   float curvature;
   float front_dragcoeff, top_dragcoeff;
   float front_area, top_area;
   float v_inflow;
   float omega_vortex, vortex_gain;
   int   n_blades;
   float mani_ref_press, mani_press;
   float mani_min, mani_max;
   int   blower_speeds, current_blower_speed;
   float blower_alt[2];
   float blower_fak[2];
   float reduct_gear;
   float fuel_eff;
} propengine;

typedef struct {
	float weight;
	specs front,left,top;
	cartvektor thrustvector;
	float throttle;
	float max_thrust;
	float min_thrust_fraction;
	float specific_impulse;
	bool  ignition;
} rocketengine;

typedef struct {
	float weight;
	cartvektor hingepos;
	float length;
	float stroke,strokepos;
	float spring,damping;
	float down,downrate;
	float steergain;
	float brakeeffect;
	float area,dragcoeff;
	float steer;
	float wheel_radius;
	float wheel_omega;
	float wheel_moment;
	bool  skid;
} undercarriage;

typedef struct {
	bool  exists;
	cartvektor hingepos;
	float length;
	float down, downrate;
	float deaccel;
} arrestor_hook;

typedef struct {
	float area,dragcoeff;
	float out,outrate;
	cartvektor pos;
} a_brake;

typedef struct {
   cartvektor pos;
   cartvektor aim;
   int        nrounds;
   float      muzzle_vel;
   float      fire_rate;
   float      projectile_mass;
   unsigned long int      t_last_shot;
   float      recoil;
   int        tracer_freq;
} cannon;

typedef struct {
   cartvektor pos;
   float capacity;
   float content;
} tank;

typedef struct {
   float elevatorrate;
   float aileronrate;
   float rudderrate;
} ctrl_props;

typedef struct {
   float max_vv;
   float min_ias;
   float max_ias;
   float max_fuel_flow;
} instrum_par;

typedef struct {
	char			name[70];
	wingspecs		wingsection[maxnwingsections];
	aeroelement		element[maxnelements];
	jetengine		jengine[maxnjetengines];
	propengine		pengine[maxnpropengines];
	rocketengine	rengine[maxnrocketengines];
	undercarriage	gear[maxngears+maxnhardpts];
	arrestor_hook	hook;
	cannon			gun[maxnguns];
	a_brake       airbrake;
	tank          fueltank[maxnfueltanks];
	int           nelements;
	int           nwingsections;
	unsigned char njetengines;
	unsigned char npropengines;
	unsigned char nrocketengines;
	unsigned char ngears;
	unsigned char nhardpts;
	unsigned char nguns;
	unsigned char nfueltanks;
	float         rho_fuel;
	float         flapresponse;
	float         flap_cp_travel;
	cartvektor    pilotpos;
	bool          show_hud;
	float         meatball_tilt;
	float         ldg_aim_offset;
	float         desired_ldg_spd;
	float         desired_ldg_AOA;
	ctrl_props    controls;
	float         stall_angle;
	float         elevator_gain;
	float         aileron_gain;
	float         rudder_gain;
	float         aileron_vmax;
	float         elevator_vmax;
	float         rudder_vmax;
	float         slat_eff;
	instrum_par   instrum;
	float         front_superdrag;
	float         left_superdrag;
	float         top_superdrag;
} planemodel;

typedef struct {
   cartvektor pos;
   cartvektor velocity;
   float      mass;
   bool       active;
   bool       tracer;
   float      starttime;
   } projectile;

#define maxnbullets 500

#ifdef MATRIX
  typedef float mat4[4][4];

  enum axis { xaxis = 0,
	      yaxis = 1,
		   zaxis = 2
	    };
#endif

typedef struct {
   short color;
   int   fill;
   int   nedges;
   int   scr_coords[maxnedges*4]; /* How many is needed in worst case? */
   float dist;
   } poly_scrcoord;

typedef struct {
   /* x,y contains projected coordinates. z contains status */
   cartvektor    first;
   cartvektor    last;
   } linecoord;

#define max_poly_queue_length 2000



typedef struct {
   cartvektor pos;
   char       ident[8];
   } waypoint;

#define maxnwaypoints 10


enum HUD_modes {
        AIRAIR     = 0,
        AIRGROUND  = 1,
        NAVIGATION = 2,
        ILS        = 3
     };

typedef struct {
   cartvektor pos;
   cartvektor vel;
   cartvektor radcen;
   cartvektor front;
   cartvektor left;
   cartvektor top;
   float rad;
   float omega;
   float hitrad;
   int   strength;
   int   nhits;
   } target_specs;

#define maxntargets 5

// Struct to contain data to be logged
typedef struct {
	float x,y,z;
	float acc_front, acc_left, acc_top;
	float v_z;
	float ias, tas, mach;
	float AoA, yaw;
	float omega_front, omega_left, omega_top;
} logstr;

/* Pre-declarations */
void errorexit(int fejl);
void Pause(int msec);
void sort_poly_queue(void);
void draw_poly_queue(void);
