#include <math.h>
#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#ifndef LINUX
#  include <conio.h>
#endif
#include "bool.h"
#include "objects/objects.h"
#include "vertigo.h"
#include "mymath.h"
#include "gen_wing.h"
#include "polygrap.h"


extern int        nwingsections, nelements;
extern short      npropengines, njetengines, nrocketengines, ngears, nhardpts, nguns;
extern short      nfueltanks;
extern short      current_model;
extern char       modelname[70];
extern planemodel modeltable[nmodels];

extern wingspecs		wingsection[maxnwingsections+1];
extern aeroelement		element[maxnelements+1];
extern jetengine		jengine[maxnjetengines+1];
extern propengine		pengine[maxnpropengines+1];
extern rocketengine		rengine[maxnpropengines+1];
extern undercarriage	gear[maxngears+maxnhardpts+1];
extern arrestor_hook	hook;
extern cannon			gun[maxnguns+1];
extern tank				fueltank[maxnfueltanks+1];
extern a_brake			airbrake;
extern instrum_par		instrum;

extern float rho_fuel;
extern float flapresponse, flap, slat_eff;
extern float noflapfrontarea,noflapdragcoeff,noflapcurvature,noflapdeflect;
extern float nooutflapfrontarea,nooutflapdragcoeff,nooutflapcurvature,nooutflapdeflect;
extern float noflap_front_liftcenter;
extern float flap_cp_travel;

extern cartvektor pilotpos;

extern object3D object[maxnobjects];
extern int nobjects;

extern bool center_ok[maxnobjects];
extern int  poly_plane_id[nmodels];
extern int  cockpit_id[nmodels];

extern bool show_hud, calc_all, auto_throttle;

extern float meatball_tilt, ldg_aim_offset, desired_ldg_spd, desired_ldg_AOA;
extern ctrl_props controls;

extern float stall_angle;

extern float elevator_gain, aileron_gain, rudder_gain;
extern float elevator_vmax, aileron_vmax, rudder_vmax;

extern aeroelement outer_wing;
extern aeroelement inner_wing;
extern aeroelement no_glove_body;
extern tank        outer_wing_tank;

extern bool ab_burning, ab_stopping;

extern float front_superdrag, left_superdrag, top_superdrag;

/* in VERTIGO.C */
extern void errorexit(int fejl);



void correct_masscenter()
{
 /* Forskyder koordinater, saa massemidtpunkt falder sammen med origo */
 /* Calculates for empty fuel tanks */
 int i;
 float totmass=0;
 float mx=0;
 float my=0;
 float mz=0;

 /* find massemidtpunkt */

 for (i=0; i<nwingsections; i++)
 {
  totmass += element[i].weight;
  mx += wingsection[i].weight*wingsection[i].masscenter.x;
  my += wingsection[i].weight*wingsection[i].masscenter.y;
  mz += wingsection[i].weight*wingsection[i].masscenter.z;
 };
 for (i=0; i<nelements; i++)
 {
  totmass += element[i].weight;
  mx += element[i].weight*element[i].front.masscenter;
  my += element[i].weight*element[i].left.masscenter;
  mz += element[i].weight*element[i].top.masscenter;
 };
 for (i=0; i<njetengines; i++)
 {
  totmass += jengine[i].weight;
  mx += jengine[i].weight*jengine[i].front.masscenter;
  my += jengine[i].weight*jengine[i].left.masscenter;
  mz += jengine[i].weight*jengine[i].top.masscenter;
 };
 for (i=0; i<npropengines; i++)
 {
  totmass += pengine[i].weight;
  mx += pengine[i].weight*pengine[i].front.masscenter;
  my += pengine[i].weight*pengine[i].left.masscenter;
  mz += pengine[i].weight*pengine[i].top.masscenter;
 };
 for (i=0; i<nrocketengines; i++)
 {
  totmass += rengine[i].weight;
  mx += rengine[i].weight*rengine[i].front.masscenter;
  my += rengine[i].weight*rengine[i].left.masscenter;
  mz += rengine[i].weight*rengine[i].top.masscenter;
 };

 for (i=0; i<ngears; i++)
 {
  totmass += gear[i].weight;
  mx += gear[i].weight*gear[i].hingepos.x;
  my += gear[i].weight*gear[i].hingepos.y;
  mz += gear[i].weight*(gear[i].hingepos.z-gear[i].length*gear[i].down);
 };

 mx /= totmass;
 my /= totmass;
 mz /= totmass;

 /* printf("%4.4f %4.4f %4.4f",mx,my,mz); */

 for (i=0; i<nwingsections; i++)
 {
  wingsection[i].masscenter.x -= mx;
  wingsection[i].masscenter.y -= my;
  wingsection[i].masscenter.z -= mz;
  wingsection[i].aerocenter.x -= mx;
  wingsection[i].aerocenter.y -= my;
  wingsection[i].aerocenter.z -= mz;
 };
 for (i=0; i<nelements; i++)
 {
  element[i].front.masscenter -= mx;
  element[i].left.masscenter  -= my;
  element[i].top.masscenter   -= mz;
  element[i].front.liftcenter -= mx;
  element[i].left.liftcenter  -= my;
  element[i].top.liftcenter   -= mz;
  element[i].front.dragcenter -= mx;
  element[i].left.dragcenter  -= my;
  element[i].top.dragcenter   -= mz;
 };
 for (i=0; i<njetengines; i++)
 {
  jengine[i].front.masscenter -= mx;
  jengine[i].left.masscenter  -= my;
  jengine[i].top.masscenter   -= mz;
  jengine[i].front.liftcenter -= mx;
  jengine[i].left.liftcenter  -= my;
  jengine[i].top.liftcenter   -= mz;
  jengine[i].front.dragcenter -= mx;
  jengine[i].left.dragcenter  -= my;
  jengine[i].top.dragcenter   -= mz;
 };
 for (i=0; i<npropengines; i++)
 {
  pengine[i].front.masscenter -= mx;
  pengine[i].left.masscenter  -= my;
  pengine[i].top.masscenter   -= mz;
  pengine[i].front.liftcenter -= mx;
  pengine[i].left.liftcenter  -= my;
  pengine[i].top.liftcenter   -= mz;
  pengine[i].front.dragcenter -= mx;
  pengine[i].left.dragcenter  -= my;
  pengine[i].top.dragcenter   -= mz;
  pengine[i].spinnerloc.x     -= mx;
  pengine[i].spinnerloc.y     -= my;
  pengine[i].spinnerloc.z     -= mz;
 };
 for (i=0; i<nrocketengines; i++)
 {
  rengine[i].front.masscenter -= mx;
  rengine[i].left.masscenter  -= my;
  rengine[i].top.masscenter   -= mz;
  rengine[i].front.liftcenter -= mx;
  rengine[i].left.liftcenter  -= my;
  rengine[i].top.liftcenter   -= mz;
  rengine[i].front.dragcenter -= mx;
  rengine[i].left.dragcenter  -= my;
  rengine[i].top.dragcenter   -= mz;
 };

 for (i=0; i<ngears+nhardpts; i++)
 {
  gear[i].hingepos.x -= mx;
  gear[i].hingepos.y -= my;
  gear[i].hingepos.z -= mz;
 };

 for (i=0; i<nfueltanks; i++)
 {
  fueltank[i].pos.x -= mx;
  fueltank[i].pos.y -= my;
  fueltank[i].pos.z -= mz;
 };

 hook.hingepos.x -= mx;
 hook.hingepos.y -= my;
 hook.hingepos.z -= mz;

 airbrake.pos.x -= mx;
 airbrake.pos.y -= my;
 airbrake.pos.z -= mz;

 pilotpos.x -= mx;
 pilotpos.y -= my;
 pilotpos.z -= mz;

 if (center_ok[poly_plane_id[current_model]] != true) {
  int id=poly_plane_id[current_model];
  center_ok[id]=true;
  for (i=0; i<object[id].nvertices; i++) {
   object[id].vertex[i].x-=mx;
   object[id].vertex[i].y-=my;
   object[id].vertex[i].z-=mz;
  }
  for (i=0; i<object[id].nctrl_srf; i++) {
   object[id].ctrl_surface[i].hinge.x-=mx;
   object[id].ctrl_surface[i].hinge.y-=my;
   object[id].ctrl_surface[i].hinge.z-=mz;
  }
  if (id==F14) {
    const float fulcrum_y=2.91;
    const float cos20    =0.9397;
    const float sin20    =0.3420;

    setup_sweep_buffer();
    outer_wing=element[6];
    inner_wing=element[4];
    no_glove_body=element[0];
    outer_wing_tank=fueltank[0];

    /* Convert coords to 0 deg sweep */
    /* Approximations ok because of small initial sweep of 20 deg. */
    outer_wing.front.masscenter=outer_wing.front.masscenter+(outer_wing.left.masscenter-fulcrum_y)*sin20;
    outer_wing.front.liftcenter=outer_wing.front.liftcenter+(outer_wing.left.liftcenter-fulcrum_y)*sin20;
    outer_wing.front.dragcenter=outer_wing.front.dragcenter+(outer_wing.left.dragcenter-fulcrum_y)*sin20;

    outer_wing.left.masscenter=fulcrum_y+(outer_wing.left.masscenter-fulcrum_y)/cos20;
    outer_wing.left.liftcenter=fulcrum_y+(outer_wing.left.liftcenter-fulcrum_y)/cos20;
    outer_wing.left.dragcenter=fulcrum_y+(outer_wing.left.dragcenter-fulcrum_y)/cos20;
    outer_wing.front.area     =fulcrum_y+(outer_wing.front.area     -fulcrum_y)/cos20;

    inner_wing.front.masscenter=inner_wing.front.masscenter+(inner_wing.left.masscenter-fulcrum_y)*sin20;
    inner_wing.front.liftcenter=inner_wing.front.liftcenter+(inner_wing.left.liftcenter-fulcrum_y)*sin20;
    inner_wing.front.dragcenter=inner_wing.front.dragcenter+(inner_wing.left.dragcenter-fulcrum_y)*sin20;

    inner_wing.left.masscenter=fulcrum_y+(inner_wing.left.masscenter-fulcrum_y)/cos20;
    inner_wing.left.liftcenter=fulcrum_y+(inner_wing.left.liftcenter-fulcrum_y)/cos20;
    inner_wing.left.dragcenter=fulcrum_y+(inner_wing.left.dragcenter-fulcrum_y)/cos20;
    inner_wing.front.area     =fulcrum_y+(inner_wing.front.area     -fulcrum_y)/cos20;

    outer_wing_tank.pos.x=outer_wing_tank.pos.x+(outer_wing_tank.pos.y-fulcrum_y)*sin20;
    outer_wing_tank.pos.y=fulcrum_y+(outer_wing_tank.pos.y-fulcrum_y)/cos20;
  }
 }

 if (cockpit_id[current_model] > -1) {
   if (center_ok[cockpit_id[current_model]] != true) {
     int id=cockpit_id[current_model];
     center_ok[id]=true;
     for (i=0; i<object[id].nvertices; i++) {
       object[id].vertex[i].x-=mx;
       object[id].vertex[i].y-=my;
       object[id].vertex[i].z-=mz;
     }
   }
 }
}



void select_model(int n)
{
 int i;
 int flapid;
 float oldrpm=0;
 float oldthr=0;
 float olddown=gear[0].down;
 float oldhookdown=hook.down;
 float oldout=airbrake.out;

 if (npropengines > 0) {
   oldrpm=pengine[0].rpm_percent;
   oldthr=pengine[0].throttle;
 }
 if (njetengines  > 0) {
   oldrpm=jengine[0].rpm;
   oldthr=jengine[0].throttle;
 }

 current_model=n;
 strcpy(modelname,modeltable[n].name);
 nwingsections= modeltable[n].nwingsections;
 nelements    = modeltable[n].nelements;
 npropengines = modeltable[n].npropengines;
 njetengines  = modeltable[n].njetengines;
 nrocketengines  = modeltable[n].nrocketengines;
 ngears       = modeltable[n].ngears;
 nhardpts     = modeltable[n].nhardpts;
 nguns        = modeltable[n].nguns;
 nfueltanks   = modeltable[n].nfueltanks;
 for ( i=0; i<nwingsections ; i++ )
	wingsection[i]=modeltable[n].wingsection[i];
 for ( i=0; i<nelements ; i++ )
	element[i]=modeltable[n].element[i];
 for ( i=0; i<npropengines ; i++ ) {
	pengine[i]=modeltable[n].pengine[i];
	pengine[i].rpm_percent=oldrpm;
	pengine[i].throttle=oldthr;
 }
 for ( i=0; i<njetengines ; i++ ) {
	jengine[i]=modeltable[n].jengine[i];
	jengine[i].throttle=oldthr;
        if (oldrpm > jengine[i].idle_rpm)
	  jengine[i].rpm=oldrpm;
        else
          jengine[i].rpm=jengine[i].idle_rpm;
 }
 for ( i=0; i<nrocketengines ; i++ ) {
	rengine[i]=modeltable[n].rengine[i];
 }

 for ( i=0; i<ngears+nhardpts ; i++ )
	gear[i]=modeltable[n].gear[i];
 for ( i=0; i<ngears; i++ )
	gear[i].down=olddown;
 for ( i=0; i<nguns; i++ )
	gun[i]=modeltable[n].gun[i];
 for ( i=0; i<nfueltanks; i++ )
	fueltank[i]=modeltable[n].fueltank[i];


 hook         = modeltable[n].hook;
 if (hook.exists) hook.down = oldhookdown;
 airbrake     = modeltable[n].airbrake;
 airbrake.out = oldout;
 rho_fuel     = modeltable[n].rho_fuel;
 flapresponse = modeltable[n].flapresponse;
 pilotpos     = modeltable[n].pilotpos;
 show_hud     = modeltable[n].show_hud;
 meatball_tilt  = modeltable[n].meatball_tilt;
 ldg_aim_offset = modeltable[n].ldg_aim_offset;
 desired_ldg_spd= modeltable[n].desired_ldg_spd;
 desired_ldg_AOA= modeltable[n].desired_ldg_AOA;
 controls       = modeltable[n].controls;
 instrum        = modeltable[n].instrum;
 stall_angle    = modeltable[n].stall_angle;
 slat_eff       = modeltable[n].slat_eff;

 elevator_gain = modeltable[n].elevator_gain;
 aileron_gain  = modeltable[n].aileron_gain;
 rudder_gain   = modeltable[n].rudder_gain;

 elevator_vmax = modeltable[n].elevator_vmax;
 aileron_vmax  = modeltable[n].aileron_vmax;
 rudder_vmax   = modeltable[n].rudder_vmax;

 front_superdrag = modeltable[n].front_superdrag;
 left_superdrag  = modeltable[n].left_superdrag;
 top_superdrag   = modeltable[n].top_superdrag;

 if (poly_plane_id[current_model]==F14) flapid=4;
 else flapid=stbflapid;

 noflapfrontarea=element[flapid].front.area;
 noflapdragcoeff=element[flapid].front.dragcoeff;
 noflapcurvature=element[flapid].topcurvature;
 noflapdeflect  =element[flapid].top.deflect;

 if (poly_plane_id[current_model]==F14) flapid=6; /* Outboard */
 nooutflapfrontarea=element[flapid].front.area;
 nooutflapdragcoeff=element[flapid].front.dragcoeff;
 nooutflapcurvature=element[flapid].topcurvature;
 nooutflapdeflect  =element[flapid].top.deflect;

 flap += 0.1; /* Will make sure flap parameters are updated */

 correct_masscenter();

 noflap_front_liftcenter = element[flapid].front.liftcenter;
 flap_cp_travel = modeltable[n].flap_cp_travel;

 calc_all=true;

 /* Ensure fixed gear is out */
 for ( i=0; i<ngears; i++ )
	if (gear[i].downrate==0) gear[i].down=1;

 auto_throttle=false;

 if (ab_burning) {
   if (njetengines == 0)
     ab_burning = false;
   else
     if (jengine[0].n_abstages == 0) {
       ab_burning = false;
       ab_stopping = true;
     }
 }
}



void copy_to_mtable(int n)
{
 int i;

 strcpy(modeltable[n].name,modelname);
 convert_wing_angles();
 for ( i=0; i<nwingsections ; i++ )
	modeltable[n].wingsection[i]=wingsection[i];
 for ( i=0; i<nelements ; i++ )
	modeltable[n].element[i]=element[i];
 for ( i=0; i<npropengines ; i++ )
	modeltable[n].pengine[i]=pengine[i];
 for ( i=0; i<njetengines ; i++ )
	modeltable[n].jengine[i]=jengine[i];
 for ( i=0; i<nrocketengines ; i++ )
	modeltable[n].rengine[i]=rengine[i];
 for ( i=0; i<ngears+nhardpts ; i++ )
	modeltable[n].gear[i]=gear[i];
 for ( i=0; i<nguns; i++ )
	modeltable[n].gun[i]=gun[i];
 for ( i=0; i<nfueltanks; i++ )
	modeltable[n].fueltank[i]=fueltank[i];

 modeltable[n].nwingsections= nwingsections;
 modeltable[n].nelements    = nelements;
 modeltable[n].npropengines = npropengines;
 modeltable[n].njetengines  = njetengines;
 modeltable[n].nrocketengines  = nrocketengines;
 modeltable[n].ngears       = ngears;
 modeltable[n].nhardpts     = nhardpts;
 modeltable[n].rho_fuel     = rho_fuel;
 modeltable[n].flapresponse = flapresponse;
 modeltable[n].pilotpos     = pilotpos;
 modeltable[n].airbrake     = airbrake;
 modeltable[n].nguns        = nguns;
 modeltable[n].nfueltanks   = nfueltanks;
 modeltable[n].show_hud     = show_hud;
 modeltable[n].hook         = hook;
 modeltable[n].meatball_tilt   = meatball_tilt;
 modeltable[n].ldg_aim_offset  = ldg_aim_offset;
 modeltable[n].desired_ldg_spd = desired_ldg_spd;
 modeltable[n].desired_ldg_AOA = desired_ldg_AOA;
 modeltable[n].controls        = controls;
 modeltable[n].instrum         = instrum;
 modeltable[n].stall_angle     = stall_angle;
 modeltable[n].flap_cp_travel  = flap_cp_travel;
 modeltable[n].slat_eff        = slat_eff;
 modeltable[n].elevator_gain   = elevator_gain;
 modeltable[n].aileron_gain    = aileron_gain;
 modeltable[n].rudder_gain     = rudder_gain;
 modeltable[n].elevator_vmax   = elevator_vmax;
 modeltable[n].aileron_vmax    = aileron_vmax;
 modeltable[n].rudder_vmax     = rudder_vmax;
 modeltable[n].front_superdrag = front_superdrag;
 modeltable[n].left_superdrag  = left_superdrag;
 modeltable[n].top_superdrag   = top_superdrag;
}



void init_mtable()
{
 int i;

 for (i=0; i<maxnobjects; i++)
  center_ok[i]=false;

 #include "airplane/t17.c"
 copy_to_mtable(0);

 #include "airplane/corsair.c"
 copy_to_mtable(1);

 #include "airplane/u2plane.c"
 copy_to_mtable(2);

 #include "airplane/f104.c"
 copy_to_mtable(3);

 #include "airplane/harrier.c"
 copy_to_mtable(4);

 #include "airplane/f14.c"
 copy_to_mtable(5);

 #include "airplane/xt17.c"
 copy_to_mtable(6);

 #include "airplane/x15.c"
 copy_to_mtable(7);

 #include "airplane/lm.c"
 copy_to_mtable(8);
}
