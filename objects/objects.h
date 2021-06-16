
#define maxnedges     8
#define maxnobjects  31
#define maxnctrlsrf  17
#define maxctrlpoly   6

#define maxnposobj  100

#define DARKGREEN   5    /* Replaces magenta */
#define GREEN_HAZE 13    /* Replaces lightmagenta */
#define BLUE_HAZE  10    /* Replaces lightgreen */
#define BROWN_HAZE 14    /* Replaces yellow */

#define WHITE_SHADE     208
#define YELLOW_SHADE    209
#define GRAY_SHADE      210
#define DARKGRAY_SHADE  211
#define SKY_BLUE        220


typedef struct {
	float x,y,z;
	} cartvektor;

typedef struct {
   int           nedges;
   short         color;
   int           edge[maxnedges];
   } polygon_struct;

typedef struct {
   cartvektor hinge;
   cartvektor axis;
   cartvektor front, left, top;
   float      rudder_gain;
   float      aileron_gain;
   float      elevator_gain;
   float      flap_gain;
   float      brake_gain;
   float      gear_gain;
   int        gear_id;
   int        nctrlpoly;
   int        poly_id[maxctrlpoly];
   } ctrl_srf;

typedef struct {
	int		r, g, b;
} coltriple;

typedef struct {
   int           nvertices;
   int           nfacets;
   cartvektor    *vertex;
   polygon_struct       *facet;
   float         max_draw_dist;
   float         always_draw_dist;
   int           nctrl_srf;
   ctrl_srf      ctrl_surface[maxnctrlsrf];
   coltriple     colarr[16];
   } object3D;

enum objectname {
	    HARRIER      =  0,
	    CORSAIR      =  1,
	    HANGAR       =  2,
	    TOWER        =  3,
	    U2           =  4,
	    RUNWAY       =  5,
	    RW_MARK      =  6,
	    MAP          =  7,
	    T17          =  8,
       F104         =  9,
       NIMITZ_HULL  = 10,
       NIMITZ_DECK  = 11,
       NIMITZ_MARK1 = 12,
       NIMITZ_MARK2 = 13,
       NIMITZ_JBD   = 14,
       F14          = 15,
       WINDBAG      = 16,
       TARGET       = 17,
       T17_CP       = 18,
       CORSAIR_CP   = 19,
       U2_CP        = 20,
       F104_CP      = 21,
       HARRIER_CP   = 22,
       F14_CP       = 23,
       ADDON1       = 24,
       ADDON2       = 25,
       ADDON3       = 26,
		X15			= 27,
		LM			= 28,
		SUN			= 29,
		LM_ASCENT	= 30
	  };

typedef struct {
   int        object;
   cartvektor pos;
   float      rot;
   bool       draw_now;
   } objectpos;
