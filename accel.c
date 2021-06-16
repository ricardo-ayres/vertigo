/* Routines for the general orientation wing */

#include <stdlib.h>
#include <stdio.h>
#include <math.h>
#include "bool.h"
#include "objects/objects.h"
#include "vertigo.h"
#include "message.h"
#include "sound.h"
#include "aoa360.h"
#include "carrier.h"
#include "map.h"
#include "config.h"
#define  rnd(a)        random() % (int) a

extern int nwingsections, nelements;
extern short npropengines,njetengines, nrocketengines,ngears,nhardpts, nguns, nfueltanks;
extern short current_model;
extern char modelname[70];
extern planemodel modeltable[nmodels];

extern wingspecs     wingsection[maxnwingsections+1];
extern aeroelement   element[maxnelements+1];
extern jetengine     jengine[maxnjetengines+1];
extern rocketengine		rengine[maxnrocketengines+1];
extern propengine    pengine[maxnpropengines+1];
extern undercarriage gear[maxngears+maxnhardpts+1];
extern arrestor_hook hook;
extern cannon        gun[maxnguns+1];
extern a_brake       airbrake;
extern tank          fueltank[maxnfueltanks+1];

extern float avg_accleft;
extern float avg_acctop;
extern float gpull, gnegmax, gposmax;
extern float G;
extern float rho_fuel;
extern float elapsed_time;
extern float x,y,z;
extern float yaw, prev_yaw;
extern float pitch;
extern cartvektor front,left,top,acc,v;
extern cartvektor cg;
extern float wfront,wleft,wtop;
extern float waccfront,waccleft,wacctop;
extern float cos_roll, sin_roll, cos_nosealt, sin_nosealt;
extern float dt;
extern long  ncalc;
extern short ncalcperframe;
extern float aileron,elevator,rudder,tail_rudder,wheel_rudder,throttle;
extern cartvektor v_air;
extern bool  whlbrakes;
extern bool  crash;
extern bool calc_all;
extern bool show_map;
extern bool detail_prop;
extern bool detail_jet;
extern int   prop_ctrl;
extern short groundtype;
/* For guns */
extern bool       fire_guns;
extern bool       shot_fired;
extern projectile bullet[maxnbullets];
extern int        nactive_bullets;
extern int        last_fired_bullet;

extern int  poly_plane_id[nmodels];

extern int world;

extern int   cat_phase;
extern int   on_catapult;
extern int   last_hook_status;
extern int   wire_trap;
extern bool  bolter_status;

/* For auto-coordination */
extern bool  auto_coordination;
extern float prev_rudder_deflect;

/* F-14 only */
extern float sweep;
extern float stb_spoiler;
extern float port_spoiler;
extern float DLC_spoiler;
extern bool  DLC_active;

extern float xscl, yscl;

extern bool ab_ignition;
extern bool ab_burning;
extern bool ab_starting;
extern bool ab_stopping;

extern unsigned long int ticks_8h;

/* External global variables and procedures/functions */
/* In MYMATH.C */
extern float arccos(float v);
extern float arcsin(float v);
extern int sgn(float x);
extern cartvektor vkryds(cartvektor a, cartvektor b);
extern cartvektor vplus(cartvektor a, cartvektor b);
extern cartvektor vminus(cartvektor a, cartvektor b);
extern cartvektor svmult(float a, cartvektor b);
extern float radtodeg(float v);
#include "mymath.h"

extern float atmospheric_density(float z);
extern float cl(float alpha, float sf, float curv, float slat);
extern void draw_vector(cartvektor a, cartvektor b, int color);
extern float superdrag(float m);
extern float flow_quality(float aoa);


extern unsigned long int enter_cat_time;

extern float gear_rumble_strength;

extern float total_fuel_flow;

extern float aircraft_mach_number, tas;
extern float front_superdrag, left_superdrag, top_superdrag;
extern float superdragfak;

void findaccel()
{
 static float mx;
 static float my;
 static float mz;
 static float totmass;
 static float ix;
 static float iy;
 static float iz;
 static float density;
 static cartvektor iprop[maxnpropengines+1];

 int   i,j;
 float vfront,vleft,vtop;
 float lift,drag;
 float locvtop,locvleft,locvfront=0;
 float cltop,clleft;
 float cdifront,cdileft;
 float thrust;
 float frontprofdrag,frontinddrag;
 float norm,combpitch,combyaw;
 float accfront, accleft, acctop;
 unsigned long int nowtick;

 if (calc_all==true) {

  calc_all=false;

  avg_accleft = 0;
  avg_acctop  = 0;

  mx=my=mz=0;
  totmass=0;
  ix=iy=iz=0;
  for (i=0; i<npropengines; i++) iprop[i].x=iprop[i].y=iprop[i].z=0;

  /* Parameters that requires updating less frequently */

  /* Find centre of gravity */
  /* mx,my,mz=0,0,0 ud fra initialisering, hvis fordeling er konstant */

 for (i=0; i<nwingsections; i++)
 {
  totmass+=wingsection[i].weight;
  mx+=wingsection[i].weight*wingsection[i].masscenter.x;
  my+=wingsection[i].weight*wingsection[i].masscenter.y;
  mz+=wingsection[i].weight*wingsection[i].masscenter.z;
 };
 for (i=0; i<nelements; i++)
 {
  totmass+=element[i].weight;
  mx+=element[i].weight*element[i].front.masscenter;
  my+=element[i].weight*element[i].left.masscenter;
  mz+=element[i].weight*element[i].top.masscenter;
 };
 for (i=0; i<njetengines; i++)
 {
  totmass+=jengine[i].weight;
  mx+=jengine[i].weight*jengine[i].front.masscenter;
  my+=jengine[i].weight*jengine[i].left.masscenter;
  mz+=jengine[i].weight*jengine[i].top.masscenter;
 };
 for (i=0; i<npropengines; i++)
 {
  totmass+=pengine[i].weight;
  mx+=pengine[i].weight*pengine[i].front.masscenter;
  my+=pengine[i].weight*pengine[i].left.masscenter;
  mz+=pengine[i].weight*pengine[i].top.masscenter;
 };
 for (i=0; i<nrocketengines; i++)
 {
  totmass+=rengine[i].weight;
  mx+=rengine[i].weight*rengine[i].front.masscenter;
  my+=rengine[i].weight*rengine[i].left.masscenter;
  mz+=rengine[i].weight*rengine[i].top.masscenter;
 };

 for (i=0; i<ngears; i++)
 {
  totmass+=gear[i].weight;
  mx+=gear[i].weight*gear[i].hingepos.x;
  my+=gear[i].weight*gear[i].hingepos.y;
  mz+=gear[i].weight*(gear[i].hingepos.z-gear[i].length*gear[i].down);
 };

 for (i=0; i<nfueltanks; i++)
 {
  totmass+=fueltank[i].content * rho_fuel;
  mx+=fueltank[i].content*rho_fuel*fueltank[i].pos.x;
  my+=fueltank[i].content*rho_fuel*fueltank[i].pos.y;
  mz+=fueltank[i].content*rho_fuel*fueltank[i].pos.z;
 };

 mx/=totmass;
 my/=totmass;
 mz/=totmass;

 cg.x = mx;
 cg.y = my;
 cg.z = mz;

 /* find inertimoment */
 for (i=0; i<nwingsections; i++)
 {
  ix+=wingsection[i].weight*(
      SQR(wingsection[i].masscenter.y-my)+SQR(wingsection[i].masscenter.z-mz));
  iy+=wingsection[i].weight*(
      SQR(wingsection[i].masscenter.x-mx)+SQR(wingsection[i].masscenter.z-mz));
  iz+=wingsection[i].weight*(
      SQR(wingsection[i].masscenter.x-mx)+SQR(wingsection[i].masscenter.y-my));

  for (j=0; j<npropengines; j++) {
    iprop[j].x+=wingsection[i].weight*(
       SQR(wingsection[i].masscenter.y-pengine[j].spinnerloc.y)+
       SQR(wingsection[i].masscenter.z-pengine[j].spinnerloc.z));
    iprop[j].y+=wingsection[i].weight*(
       SQR(wingsection[i].masscenter.x-pengine[j].spinnerloc.x)+
       SQR(wingsection[i].masscenter.z-pengine[j].spinnerloc.z));
    iprop[j].z+=wingsection[i].weight*(
       SQR(wingsection[i].masscenter.x-pengine[j].spinnerloc.x)+
       SQR(wingsection[i].masscenter.y-pengine[j].spinnerloc.y));
  }
 }

 for (i=0; i<nelements; i++)
 {
  ix+=element[i].weight*(
     SQR(element[i].left.masscenter-my)+SQR(element[i].top.masscenter-mz));
  iy+=element[i].weight*(
     SQR(element[i].front.masscenter-mx)+SQR(element[i].top.masscenter-mz));
  iz+=element[i].weight*(
     SQR(element[i].front.masscenter-mx)+SQR(element[i].left.masscenter-my));

  for (j=0; j<npropengines; j++) {
    iprop[j].x+=element[i].weight*(
       SQR(element[i].left.masscenter-pengine[j].spinnerloc.y)+
       SQR(element[i].top.masscenter-pengine[j].spinnerloc.z));
    iprop[j].y+=element[i].weight*(
       SQR(element[i].front.masscenter-pengine[j].spinnerloc.x)+
       SQR(element[i].top.masscenter-pengine[j].spinnerloc.z));
    iprop[j].z+=element[i].weight*(
       SQR(element[i].front.masscenter-pengine[j].spinnerloc.x)+
       SQR(element[i].left.masscenter-pengine[j].spinnerloc.y));
  }
 }

 for (i=0; i<njetengines; i++)
 {
  ix+=jengine[i].weight*(
     SQR(jengine[i].left.masscenter-my)+SQR(jengine[i].top.masscenter-mz));
  iy+=jengine[i].weight*(
     SQR(jengine[i].front.masscenter-mx)+SQR(jengine[i].top.masscenter-mz));
  iz+=jengine[i].weight*(
     SQR(jengine[i].front.masscenter-mx)+SQR(jengine[i].left.masscenter-my));
 }

 for (i=0; i<nrocketengines; i++)
 {
  ix+=rengine[i].weight*(
     SQR(rengine[i].left.masscenter-my)+SQR(rengine[i].top.masscenter-mz));
  iy+=rengine[i].weight*(
     SQR(rengine[i].front.masscenter-mx)+SQR(rengine[i].top.masscenter-mz));
  iz+=rengine[i].weight*(
     SQR(rengine[i].front.masscenter-mx)+SQR(rengine[i].left.masscenter-my));
 }

 for (i=0; i<npropengines; i++)
 {
  ix+=pengine[i].weight*(
     SQR(pengine[i].left.masscenter-my)+SQR(pengine[i].top.masscenter-mz));
  iy+=pengine[i].weight*(
     SQR(pengine[i].front.masscenter-mx)+SQR(pengine[i].top.masscenter-mz));
  iz+=pengine[i].weight*(
     SQR(pengine[i].front.masscenter-mx)+SQR(pengine[i].left.masscenter-my));

  for (j=0; j<npropengines; j++) {
    iprop[j].x+=pengine[i].weight*(
       SQR(pengine[i].left.masscenter-pengine[j].spinnerloc.y)+
       SQR(pengine[i].top.masscenter-pengine[j].spinnerloc.z));
    iprop[j].y+=pengine[i].weight*(
       SQR(pengine[i].front.masscenter-pengine[j].spinnerloc.x)+
       SQR(pengine[i].top.masscenter-pengine[j].spinnerloc.z));
    iprop[j].z+=pengine[i].weight*(
       SQR(pengine[i].front.masscenter-pengine[j].spinnerloc.x)+
       SQR(pengine[i].left.masscenter-pengine[j].spinnerloc.y));
  }
 }

 for (i=0; i<ngears; i++)
 {
  ix+=gear[i].weight*(
     SQR(gear[i].hingepos.y-my)+SQR(gear[i].hingepos.z-mz));
  iy+=gear[i].weight*(
     SQR(gear[i].hingepos.x-mx)+SQR(gear[i].hingepos.z-mz));
  iz+=gear[i].weight*(
     SQR(gear[i].hingepos.x-mx)+SQR(gear[i].hingepos.y-my));

  for (j=0; j<npropengines; j++) {
    iprop[j].x+=gear[i].weight*(
       SQR(gear[i].hingepos.y-pengine[j].spinnerloc.y)+
       SQR(gear[i].hingepos.z-pengine[j].spinnerloc.z));
    iprop[j].y+=gear[i].weight*(
       SQR(gear[i].hingepos.x-pengine[j].spinnerloc.x)+
       SQR(gear[i].hingepos.z-pengine[j].spinnerloc.z));
    iprop[j].z+=gear[i].weight*(
       SQR(gear[i].hingepos.x-pengine[j].spinnerloc.x)+
       SQR(gear[i].hingepos.y-pengine[j].spinnerloc.y));
  }
 }

 for (i=0; i<nfueltanks; i++)
 {
  ix+=fueltank[i].content*rho_fuel*(
     SQR(fueltank[i].pos.y-my)+SQR(fueltank[i].pos.z-mz));
  iy+=fueltank[i].content*rho_fuel*(
     SQR(fueltank[i].pos.x-mx)+SQR(fueltank[i].pos.z-mz));
  iz+=fueltank[i].content*rho_fuel*(
     SQR(fueltank[i].pos.x-mx)+SQR(fueltank[i].pos.y-my));

  for (j=0; j<npropengines; j++) {
    iprop[j].x+=fueltank[i].content*rho_fuel*(
       SQR(fueltank[i].pos.y-pengine[j].spinnerloc.y)+
       SQR(fueltank[i].pos.z-pengine[j].spinnerloc.z));
    iprop[j].y+=fueltank[i].content*rho_fuel*(
       SQR(fueltank[i].pos.x-pengine[j].spinnerloc.x)+
       SQR(fueltank[i].pos.z-pengine[j].spinnerloc.z));
    iprop[j].z+=fueltank[i].content*rho_fuel*(
       SQR(fueltank[i].pos.x-pengine[j].spinnerloc.x)+
       SQR(fueltank[i].pos.y-pengine[j].spinnerloc.y));
  }
 }

  density=atmospheric_density(z);
  total_fuel_flow=0;
  superdragfak = superdrag(aircraft_mach_number);
 }; /* No more for calc_all - All below is calculated every time */

 accfront=0;
 accleft=0;
 acctop=0;
 waccfront=0;
 waccleft=0;
 wacctop=0;

 vfront=VPRIK(v_air,front);
 vleft=VPRIK(v_air,left);
 vtop=VPRIK(v_air,top);

 if (auto_coordination) {
  /* PD servo for auto-coordination of yaw */
  float cp=50.0;
  float cd=500.0;
  float change, deflect, drudderdt;
  float desired_change=yaw*cp*180.0/PI-prev_rudder_deflect;

  desired_change += cd*(yaw-prev_yaw)/dt;

  drudderdt=180*dt; /* 180 deg/sec */
  if (fabs(desired_change)>drudderdt)
     change=drudderdt*sgn(desired_change);
  else
     change=desired_change;
  deflect=prev_rudder_deflect+change;

  if (fabs(deflect) > 15) deflect=sgn(deflect)*15;
  /* Note that rudder and deflect are of opposite sign */
  if (poly_plane_id[current_model]==F14)
    element[3].left.deflect=deflect;
  else
    element[rudderid].left.deflect=deflect;
  tail_rudder=-deflect;

  prev_rudder_deflect=deflect;
 }


 /***********************************************/
 /* Forces from the general-orientation airfoil */
 /***********************************************/
 for (i=0; i<nwingsections; i++)
 {
  cartvektor locv, v_res, f_res;
  float v_lead, v_norm, v_airfoil;
  float AoA;
  float c_l;
  float lift, norm_lift, lead_lift;

  /* Calculate local velocity due to angular velocity */
  locv.z  =-wfront*wingsection[i].aerocenter.y;
  locv.z += wleft *wingsection[i].aerocenter.x;
  locv.y  =-wtop  *wingsection[i].aerocenter.x;
  locv.y -= wfront*wingsection[i].aerocenter.z;
  locv.x  =-wtop  *wingsection[i].aerocenter.y;
  locv.x -= wleft *wingsection[i].aerocenter.z;

  /* Include prop-wash in local velocity */
  if (detail_prop && npropengines > 0) {
    for (j=0; j<npropengines; j++) {
     if (fabs(pengine[j].spinnerloc.y-wingsection[i].aerocenter.y) < pengine[j].radius &&
         fabs(pengine[j].spinnerloc.z-wingsection[i].aerocenter.z ) < pengine[j].radius) {
        float v_inflow=pengine[j].v_inflow;
        float flow_fak;

        if (v_inflow > 0) flow_fak=1; /* Actually 2, but feels too strong */
        else flow_fak=0.5;
        locv.x += flow_fak*v_inflow;
        /* The rudderid does not apply */
        /*
        if ( i == rudderid) {
           locv.y -= pengine[j].omega_vortex*pengine[j].vortex_gain*(pengine[j].spinnerloc.z-wingsection[i].aerocenter.z);
        }
        */
     }
    }
  }

  v_res.x = vfront + locv.x;
  v_res.y = vleft  + locv.y;
  v_res.z = vtop   + locv.z;

  /* The wind vector is now projected onto the plane defined by the
     wing normal vector and the leading edge normal vector */
  v_lead=VPRIK(v_res , wingsection[i].leadingedge);
  v_norm=VPRIK(v_res , wingsection[i].normal);

  v_airfoil = sqrt( SQR(v_lead) + SQR(v_norm) );

  /* This calculation of nyazi avoids the poorly defined regions
     of arccos and arcsin */
  /* Can this be converted in a simpler way? */
  if (fabs(v_airfoil)>1e-9) {
       if ( fabs(v_lead) < fabs(v_norm) ) {
            AoA=arccos( v_lead / v_airfoil );
            if ( v_norm > 0) AoA=-AoA;
       }
       else {
            AoA = -arcsin( v_norm / v_airfoil );
            if (v_lead < 0)
               AoA = PI-AoA;
            if (AoA < -PI)
               AoA += 2*PI;
            if (AoA > PI)
               AoA -= 2*PI;
       }
     }
  else
     AoA=0;


  /* Generic profile only */
  /*
  c_l=cl(AoA*180./PI + wingsection[i].ailerongain*aileron,
         wingsection[i].aspect,
         wingsection[i].curvature);
  */

  c_l=cl_naca(AoA*180./PI);


  lift=0.5*density*SQR(v_airfoil)*wingsection[i].area*c_l;

  /* Lift is per definition perpendicular to the airflow */
  /* Now find the lead and norm components of the lift vector */
  if (fabs(v_airfoil)>1e-9) {
      norm_lift = lift*(v_lead/v_airfoil);
      lead_lift =-lift*(v_norm/v_airfoil);
  }
  else {
      norm_lift=0;
      lead_lift=0;
  }

  /* Project forces onto x,y,z */
  f_res = svmult( norm_lift, wingsection[i].normal );
  f_res = vplus( f_res, svmult( lead_lift, wingsection[i].leadingedge));

  accfront += f_res.x/totmass; /* Sign OK */
  accleft  -= f_res.y/totmass; /* Sign OK */
  acctop   += f_res.z/totmass; /* Sign OK */

  waccfront += f_res.y*(wingsection[i].aerocenter.z-cg.z)/ix; /* Sign OK */
  waccfront -= f_res.z*(wingsection[i].aerocenter.y-cg.y)/ix; /* Sign OK */
  waccleft  -= f_res.x*(wingsection[i].aerocenter.z-cg.z)/iy; /* Sign OK */
  waccleft  += f_res.z*(wingsection[i].aerocenter.x-cg.x)/iy; /* Sign OK */
  wacctop   -= f_res.x*(wingsection[i].aerocenter.y-cg.y)/iz; /* Sign OK */
  wacctop   += f_res.y*(wingsection[i].aerocenter.x-cg.x)/iz; /* Sign OK */




/*
   if((ncalc % ncalcperframe)==0) {
       setcolor(YELLOW);
       moveto(100*xscl,(50+100*i)*yscl);
       outtext("VX     ");
       printfg((vfront+locv.x)*100.,6,5);
       moveto(200*xscl,(50+100*i)*yscl);
       outtext("VY     ");
       printfg((vleft+locv.y)*100.,6,5);
       moveto(300*xscl,(50+100*i)*yscl);
       outtext("VZ     ");
       printfg((vtop+locv.z)*100.,6,5);

       moveto(100*xscl,(60+100*i)*yscl);
       outtext("v_lead ");
       printfg(v_lead*100.,6,5);
       moveto(300*xscl,(60+100*i)*yscl);
       outtext("v_norm ");
       printfg(v_norm*100.,6,5);

       moveto(100*xscl,(70+100*i)*yscl);
       outtext("AoA    ");
       printfg((AoA*180./PI)*100.,6,5);

       moveto(100*xscl,(80+100*i)*yscl);
       outtext("v_airf ");
       printfg(v_airfoil*100.,6,5);
*/
       /* f_res = svmult( lead_lift, wingsection[i].leadingedge); */
/*
       moveto(100*xscl,(90+100*i)*yscl);
       outtext("FX     ");
       printfg(f_res.x*100.,6,5);
       moveto(200*xscl,(90+100*i)*yscl);
       outtext("FY     ");
       printfg(f_res.y*100.,6,5);
       moveto(300*xscl,(90+100*i)*yscl);
       outtext("FZ     ");
       printfg(f_res.z*100.,6,5);


       moveto(100*xscl,(100+100*i)*yscl);
       outtext("NX     ");
       printfg(wingsection[i].normal.x*100.,6,5);
       moveto(200*xscl,(100+100*i)*yscl);
       outtext("NY     ");
       printfg(wingsection[i].normal.y*100.,6,5);
       moveto(300*xscl,(100+100*i)*yscl);
       outtext("NZ     ");
       printfg(wingsection[i].normal.z*100.,6,5);


       moveto(100*xscl,(110+100*i)*yscl);
       outtext("LX     ");
       printfg(wingsection[i].leadingedge.x*100.,6,5);
       moveto(200*xscl,(110+100*i)*yscl);
       outtext("LY     ");
       printfg(wingsection[i].leadingedge.y*100.,6,5);
       moveto(300*xscl,(110+100*i)*yscl);
       outtext("LZ     ");
       printfg(wingsection[i].leadingedge.z*100.,6,5);
    }
*/

  /* Torque from gravity */
  waccfront += cos_roll    *G*wingsection[i].weight*(wingsection[i].masscenter.y-cg.y)/ix;
  waccfront += sin_roll    *G*wingsection[i].weight*(wingsection[i].masscenter.z-cg.z)/ix;
  waccleft  -= cos_nosealt *G*wingsection[i].weight*(wingsection[i].masscenter.x-cg.x)/iy;
  waccleft  += sin_nosealt *G*wingsection[i].weight*(wingsection[i].masscenter.z-cg.z)/iy;
  wacctop   += sin_roll    *G*wingsection[i].weight*(wingsection[i].masscenter.x-cg.x)/iz;
  wacctop   += sin_nosealt *G*wingsection[i].weight*(wingsection[i].masscenter.y-cg.y)/iz;


 }


 for (i=0; i<nelements; i++)
 {
  float cos_combpitch, sin_combpitch;
  float slatpos;
  int j;
  extern float flap, slat_eff;

  /* Beregn lokale hastigheder som foelge af vinkelhastigheder */
  locvtop    =-wfront*element[i].left.liftcenter;
  locvtop   += wleft*element[i].front.liftcenter;
  locvleft   =-wtop*element[i].front.liftcenter;
  locvleft  -= wfront*element[i].top.liftcenter;
  locvfront  =-wtop*element[i].left.liftcenter;
  locvfront -= wleft*element[i].top.liftcenter;

  if (detail_prop && npropengines > 0) {
    for (j=0; j<npropengines; j++) {
     if (fabs(pengine[j].spinnerloc.y-element[i].left.liftcenter) < pengine[j].radius &&
         fabs(pengine[j].spinnerloc.z-element[i].top.liftcenter ) < pengine[j].radius) {
        float v_inflow=pengine[j].v_inflow;
        float flow_fak;

        if (v_inflow > 0) flow_fak=1; /* Actually 2, but feels too strong */
        else flow_fak=0.5;
        locvfront += flow_fak*v_inflow;

        if ( i == rudderid) {
           locvleft -= pengine[j].omega_vortex*pengine[j].vortex_gain*(pengine[j].spinnerloc.z-element[i].top.liftcenter);
        }

     }
    }
  }

  norm=sqrt((SQR(vfront+locvfront)+SQR(vtop+locvtop)));
  if (fabs(norm)>1e-9) {                               /* Avoid div. by 0 */
     combpitch=arccos((vfront+locvfront)/norm);
     if ((vtop+locvtop) > 0) combpitch=-combpitch;
     }
  else
     combpitch=0;

  cos_combpitch=cos(combpitch);
  sin_combpitch=sin(combpitch);

  norm=sqrt((SQR(vfront+locvfront)+SQR(vleft+locvleft))); /* Div. by 0 possible!!! */
  if (fabs(norm)>1e-9) {                               /* Avoid div. by 0 */
     combyaw=arccos((vfront+locvfront)/norm);
     if ((vleft+locvleft) < 0) combyaw=-combyaw;
     }
  else
     combyaw=0;

  if (poly_plane_id[current_model]==F14) {
     if ( i >= 4 && i <= 7)
        slatpos = slat_eff*flap/24;
     else
        slatpos = 0;
  }
  else {
     if (i==stbflapid || i==portflapid)
        slatpos = slat_eff*flap/24;
     else
        slatpos = 0;
  }

  /* Lift i top-retning */
  cltop=cl((combpitch)*180/PI+element[i].top.deflect,element[i].top.aspect,element[i].topcurvature, slatpos);


  if (poly_plane_id[current_model]==F14) {
    if (i==4 || i==6) cltop=cltop/(1.0+1.5*stb_spoiler);
    if (i==5 || i==7) cltop=cltop/(1.0+1.5*port_spoiler);
  }


  lift=0.5*density*SQR(vfront+locvfront)*element[i].top.area*cltop;

  /* Liftvektor er vinkelret paa stroemningsretningen */
  /* Som 0.17 */
  acctop    += cos_combpitch*lift/totmass;
  accfront  += sin_combpitch*lift/totmass;
  waccfront -= (element[i].left.liftcenter-cg.y)*lift/ix;
  waccleft  += (element[i].front.liftcenter-cg.x)*lift/iy;

  /* Foreslaaet aendring 0.18
  acctop    += cos_combpitch*lift/totmass;
  accfront  += sin_combpitch*lift/totmass;
  waccfront -= cos_combpitch*element[i].left.liftcenter*lift/ix;
  waccleft  += cos_combpitch*element[i].front.liftcenter*lift/iy;
  wacctop   += sin_combpitch*element[i].left.liftcenter*lift/iz;
  */

  /* Lift i side-retning */
  clleft=cl((combyaw)*180/PI+element[i].left.deflect,element[i].left.aspect,0,0);
  lift=0.5*density*SQR(vfront)*element[i].left.area*clleft;

  /* Left modsat rettet lokal Y */
  accleft   -= cos(combyaw)*lift/totmass;
  accfront  -= sin(combyaw)*lift/totmass; /* fortegn OK??? */
  waccfront += (element[i].top.liftcenter-cg.z)*lift/ix;
  wacctop   += (element[i].front.liftcenter-cg.x)*lift/iz;

  /* Lift i front-retning ikke implementeret (Normalt unoedvendigt)*/

  /* Drag i front-retning - Induceret drag kun i front-retning */
  /* Mulighed for optimering:
     gang 0.5*density*SQR(vfront+locvfront) paa til sidst */
  /* Hvorfor er der negativ adverse yaw? */
  frontprofdrag=0.5*density*SQR(vfront+locvfront)*element[i].front.area*
	element[i].front.dragcoeff;

  if (poly_plane_id[current_model]==F14) {
    if (i==4 || i==6) frontprofdrag=frontprofdrag*(1.0+4*stb_spoiler);
    if (i==5 || i==7) frontprofdrag=frontprofdrag*(1.0+4*port_spoiler);
  }

  frontprofdrag *= 1.0 + (superdragfak * front_superdrag);

  cdifront=SQR(cltop)/(PI*element[i].top.aspect*element[i].top.oswald);
  frontinddrag=0.5*density*SQR(vfront+locvfront)*element[i].top.area*
	cdifront;

  cdileft=SQR(clleft)/(PI*element[i].left.aspect);
  frontinddrag += 0.5*density*SQR(vfront+locvfront)*
	element[i].left.area*cdileft;

  drag=frontprofdrag+frontinddrag;
  drag *= sgn(vfront+locvfront); /* Drag er typisk positiv */

  /* Som i 0.17 */
  accfront -= drag/totmass;
  waccleft += (element[i].top.dragcenter-cg.z)*drag/iy;
  wacctop  += (element[i].left.dragcenter-cg.y)*drag/iz;

  /* Foreslaaet aendring v. 0.18
  accfront -= cos_combpitch*drag/totmass;
  acctop   += sin_combpitch*drag/totmass;
  waccleft += cos_combpitch*element[i].top.dragcenter*drag/iy;
  wacctop  += cos_combpitch*element[i].left.dragcenter*drag/iz;
  waccfront-= sin_combpitch*element[i].left.dragcenter*drag/ix;
  */

  /* Drag i top-retning */
  drag=0.5*density*SQR(vtop+locvtop)*element[i].top.area*
  element[i].top.dragcoeff;
  drag *= 1.0 + (superdragfak * top_superdrag);
  drag *= sgn(vtop+locvtop);
  acctop    -= drag/totmass;
  waccleft  -= (element[i].front.dragcenter-cg.x)*drag/iy;
  waccfront += (element[i].left.dragcenter-cg.y)*drag/ix;

  /* Drag i side-retning */
  drag=0.5*density*SQR(vleft+locvleft)*element[i].left.area*
  element[i].left.dragcoeff;
  drag *= 1.0 + (superdragfak * left_superdrag);
  drag *= sgn(vleft+locvleft);
  accleft   -= drag/totmass;
  wacctop   += (element[i].front.dragcenter-cg.x)*drag/iz;
  waccfront += (element[i].top.dragcenter-cg.z)*drag/ix;

  /* Torque from gravity */
  waccfront += cos_roll    *G*element[i].weight*(element[i].left.masscenter -cg.y)/ix;
  waccfront += sin_roll    *G*element[i].weight*(element[i].top.masscenter  -cg.z)/ix;
  waccleft  -= cos_nosealt *G*element[i].weight*(element[i].front.masscenter-cg.x)/iy; /* mangler G */
  waccleft  += sin_nosealt *G*element[i].weight*(element[i].top.masscenter  -cg.z)/iy; /* mangler G */
  wacctop   += sin_roll    *G*element[i].weight*(element[i].front.masscenter-cg.x)/iz;
  wacctop   += sin_nosealt *G*element[i].weight*(element[i].left.masscenter -cg.y)/iz; /* mangler G */

 }

 /*
 if (true==false){
 */
 /* Gyroscopic forces on body */
 /* Calculations checked by real gyro */
 /* Local variables obey standard Cartesian orientation */
 /* Seems to be correct, but seems to behave oppositely */
 /* of the expected "tennis racket" effect. */
 /* Replaced by routine below, although behaviour is (almost?) identical */
 /*
  cartvektor Omega, L_c, Tau;

  Omega.x = wfront;
  Omega.y =-wleft;
  Omega.z =-wtop;

  L_c.x   = ix * Omega.x;
  L_c.y   = iy * Omega.y;
  L_c.z   = iz * Omega.z;

  Tau = vkryds( Omega, L_c );
 */
  /*Signs opposite of what expected*/
 /*
  waccfront -= Tau.x / ix;
  waccleft  += Tau.y / iy;
  wacctop   += Tau.z / iz;
 }
 */

 /*if (body_gyro_active)*/{
 /* Gyroscopic forces on body */
 /* See Herbert Goldstein: Classical Mechaninc 2.nd ed. (5-40) */
  cartvektor Omega;

  Omega.x = wfront; /* + */
  Omega.y =-wleft;  /* - */
  Omega.z =-wtop;   /* - */

  waccfront += ( Omega.y * Omega.z * ( iy - iz ) ) / ix;
  waccleft  -= ( Omega.z * Omega.x * ( iz - ix ) ) / iy;
  wacctop   -= ( Omega.x * Omega.y * ( ix - iy ) ) / iz;
 }



#include "propel.c"



#include "jet_eng.c"



#include "rock_eng.c"


 /* Drag in front-direction from airbrakes */
  drag      = 0.5*density*SQR(vfront+locvfront)*airbrake.area*
		   airbrake.dragcoeff*airbrake.out;
  drag     *= 1.0 + (superdragfak * 2.0);
  drag     *= sgn(vfront+locvfront);
  accfront -= drag/totmass;
  waccleft += (airbrake.pos.z-cg.z)*drag/iy;
  wacctop  += (airbrake.pos.y-cg.y)*drag/iz;

 for (i=0; i<nfueltanks; i++) {
   /* Torque from gravity */
   waccfront += cos_roll    *G*fueltank[i].content*rho_fuel*(fueltank[i].pos.y-cg.y) /ix;
   waccfront += sin_roll    *G*fueltank[i].content*rho_fuel*(fueltank[i].pos.z-cg.z) /ix;
   waccleft  -= cos_nosealt *G*fueltank[i].content*rho_fuel*(fueltank[i].pos.x-cg.x) /iy;
   waccleft  += sin_nosealt *G*fueltank[i].content*rho_fuel*(fueltank[i].pos.z-cg.z) /iy;
   wacctop   += sin_roll    *G*fueltank[i].content*rho_fuel*(fueltank[i].pos.x-cg.x) /iz;
   wacctop   += sin_nosealt *G*fueltank[i].content*rho_fuel*(fueltank[i].pos.y-cg.y) /iz;
 }

 gear_rumble_strength=0;

 for (i=0; i<ngears+nhardpts; i++)
 {
  float gearzpos=gear[i].hingepos.z-gear[i].length*gear[i].down;

  /* Local velocities */
  locvtop    =-wfront*gear[i].hingepos.y;
  locvtop   += wleft*gear[i].hingepos.x;
  locvleft   =-wtop*gear[i].hingepos.x;
  locvleft  -= wfront*gearzpos;
  locvfront  =-wtop*gear[i].hingepos.y;
  locvfront -= wleft*gearzpos;

  /* Profile drag in front-direction */
  drag      = 0.5*density*SQR(vfront+locvfront)*gear[i].area*
		   gear[i].dragcoeff*gear[i].down;
  drag     *= 1.0 + (superdragfak * 2.0);
  drag     *= sgn(vfront+locvfront);
  accfront -= drag/totmass;
  waccleft += (gearzpos-cg.z)*drag/iy;
  wacctop  += (gear[i].hingepos.y-cg.y)*drag/iz;

  /* No drag in top-direction */

  /* Drag in side-direction */
  drag      = 0.5*density*SQR(vleft+locvleft)*gear[i].area*
	      gear[i].dragcoeff*gear[i].down;
  drag     *= 1.0 + (superdragfak * 2.0);
  drag     *= sgn(vleft+locvleft);
  accleft  -= drag/totmass;
  wacctop  += (gear[i].hingepos.x-cg.x)*drag/iz;
  waccfront+= (gearzpos-cg.z)*drag/ix;

  /* Torque from gravity on gear */
  waccfront += cos_roll    *G*gear[i].weight*(gear[i].hingepos.y-cg.y)/ix;
  waccfront += sin_roll    *G*gear[i].weight*(gearzpos          -cg.z)/ix;
  waccleft  -= cos_nosealt *G*gear[i].weight*(gear[i].hingepos.x-cg.x)/iy;
  waccleft  += sin_nosealt *G*gear[i].weight*(gearzpos          -cg.z)/iy;
  wacctop   += sin_roll    *G*gear[i].weight*(gear[i].hingepos.x-cg.x)/iz;
  wacctop   += sin_nosealt *G*gear[i].weight*(gear[i].hingepos.y-cg.y)/iz;

  if (gear[i].down>0 || i>=ngears) {

   /* Gear is down or not completely retracted, or hardpoint*/
   float wheelalt, deckalt;
   cartvektor pln,wheel;
   bool on_carrier=false;

   wheel.x=gear[i].hingepos.x;
   wheel.y=gear[i].hingepos.y;
   wheel.z=gear[i].hingepos.z-(gear[i].length+gear[i].stroke)*gear[i].down;
   pln.x=x; pln.y=y; pln.z=z;
   pln=vplus(pln,svmult(wheel.x,front));
   pln=vplus(pln,svmult(-wheel.y,left));
   pln=vplus(pln,svmult(wheel.z,top));
   deckalt=carrier_deck_alt(pln.x,pln.y);

   if (deckalt > 0) {
      on_carrier=true;
      wheelalt=pln.z-deckalt;
   }
   else
      wheelalt=pln.z-groundalt(pln.x,pln.y);

   /* Re-calculate speeds, this time without wind-speed */
   vfront=VPRIK(v,front);
   vleft =VPRIK(v,left );
   /* vtop  =VPRIK(v,top  ); */
   vtop=v.z;

   if (on_carrier) {
      cartvektor v_carrier=get_carrier_speed(pln.x,pln.y);

      vfront-=VPRIK(v_carrier,front);
      vleft -=VPRIK(v_carrier,left );
      vtop  -=VPRIK(v_carrier,top  );
   }


   if (poly_plane_id[current_model]==F14 && i==steerwhlid && on_catapult==0 && on_carrier && wire_trap==0) {
      int j;

      for (j=0; j<4; j++) {
        cartvektor whl_to_cat = vminus(pln, get_catapult_init_pos(j));
        if ((whl_to_cat.x*whl_to_cat.x+whl_to_cat.y*whl_to_cat.y) < 0.25) {
           /* Locks for distance sqrt(0.25)= 0.5 meter */
           /* OK, so we are on a cat-position */
           /* Now determine if the relative speed is too large for locking */
           locvleft   =-wtop*wheel.x;
           locvleft  -= wfront*wheel.z;
           locvfront  =-wtop*wheel.y;
           locvfront -= wleft*wheel.z;

           if ( ( fabs(vleft+locvleft)+fabs(vfront+locvfront) ) < 3 )
              on_catapult=j+1;
        }
      }
   }


   if (wheelalt < 0) {   /* Wheel touches ground */

    float force ,dampforce;
    float testvleft,testvfront;
    float whlyaw,testwhlyaw;
    float testfrontspeed,testsidespeed,testvhoriz;
    float frontspeed,sidespeed,vhoriz;
    float testlocvleft,testlocvfront;
    float frontforce,sideforce,gnidcoeff,whl_frc_front,whl_frc_left;
    float testwtop,testwfront,testwleft;
    float combyaw,testcombyaw;
    bool  sideskid=false;
    bool  touchdown=false;
    cartvektor gndnorm;

    if ((top.z < 0 || (((pln.z-wheelalt)/*=groundalt*/<1e-3) && groundtype!=0 && world==EARTH)) && !crash){
       crash=true;
       play_wav(CRASH_WAV, 255, 180, 1000, false);
    }
    gndnorm=groundnorm(pln.x,pln.y);

    if (poly_plane_id[current_model]==F14 && DLC_active && sweep < 55) DLC_spoiler=55.0;

    /* Beregning af hastigheder denne gang for hjulets position */
    locvtop    =-wfront*wheel.y;
    locvtop   += wleft*wheel.x;
    locvleft   =-wtop*wheel.x;
    locvleft  -= wfront*wheel.z;
    locvfront  =-wtop*wheel.y;
    locvfront -= wleft*wheel.z;
    norm=sqrt((SQR(vfront+locvfront)+SQR(vleft+locvleft)));
    if (fabs(norm)>1e-9) {                               /* Avoid div. by 0 */
       combyaw=arccos((vfront+locvfront)/norm);
       if ((vleft+locvleft) < 0) combyaw=-combyaw;
       }
    else
       combyaw=0;

    /*
    if((ncalc % ncalcperframe)==0) {
       setcolor(YELLOW);
       moveto(110*xscl,(50+20*i)*yscl);
       printfg(-wheelalt*100.,6,5);
       moveto(160*xscl,(50+20*i)*yscl);
       printfg((vleft+locvleft)*100.,6,5);
       moveto(210*xscl,(50+20*i)*yscl);
       printfg((vtop+locvtop)*100.,6,5);
    }
    */


    /* Gear-spring forces with damping */
    /* Wheelalt is typically about -0.1 */
    force     = -wheelalt*gear[i].spring; /* always positive */

    dampforce = -(vtop+locvtop)*gear[i].spring*gear[i].damping;
    force    +=  dampforce;

    /*
      if(((ncalc % ncalcperframe)==0) && (i==0)) {
       setcolor(YELLOW);
       moveto(10*xscl,10*yscl);
       printfg(v.z*100.,6,5);
       moveto(100*xscl,10*yscl);
       printfg(vtop*100.,6,5);
      }
    */

    if (force<0) force=0;

    /* for acceleration af massemidtpunkt */

    acctop   += VPRIK(top,gndnorm)*force/totmass;
    accfront += VPRIK(front,gndnorm)*force/totmass;
    accleft  += VPRIK(left,gndnorm)*force/totmass;

    /* angulaer acceleration */
    waccleft  += ((wheel.x-cg.x)*cos_nosealt-(wheel.z-cg.z)*sin_nosealt)*force/iy;
    waccfront -= ((wheel.y-cg.y)*cos_roll+(wheel.z-cg.z)*sin_roll)*force/ix;

    /* wacctop er mangelfuldt beregnet (nu udeladt)
    har brug for sidevaerts vinkel af naese i forhold til horisont
    wacctop=wacctop-wheel.y*sin(nosealt)*cos(roll)*force/iz;
    wacctop=wacctop+wheel.x*sin(roll)*force/iz;
    */

    if (gear[i].strokepos==0) touchdown=true;
    gear[i].strokepos=-wheelalt;

    /* Rulle-og bremsekraefter */

    gnidcoeff=1.0; /* ca=1 iflg Christiansen, Both : Mekanik, tabel 3.1 */

    if (i >= ngears) gnidcoeff=gear[i].brakeeffect;  /* hardpoint */

    /* Foerst vinkelret paa rulle-retning: */

	/* yaw:rad gear[i].steer:grader (+/- ca. 30) */
	/* yaw er negativ, naar luftstroem rammer fra styrbord/hoejre */
	/* steer er positiv, naar der drejes mod styrbord/hoejre */
	/* whlyaw er vinkel:rad mellem hjulretning og hastighed */
	/* whlyaw har samme orientering som yaw */
	/* Steergain positiv for naesehjul, negativ for halehjul */
    whlyaw=combyaw+gear[i].steer*gear[i].steergain*PI/180;

	/* horisontal fart */
    /* vhoriz=sqrt(SQR(v.x)+SQR(v.y)); */ /* korrekt, men svaer at bruge til check */
    vhoriz=sqrt(SQR(vfront+locvfront)+SQR(vleft+locvleft)); /* kun OK, hvis fly vandret */

	/* sidespeed er hastighed vinkelret paa rulle-retningen */
	/* negativ, naar hjul glider mod styrbord (fart fra styrbord) */
    sidespeed=sin(whlyaw)*vhoriz;

	/* kraft kun afh. af normalkraft og gnid-koeff, ikke af fart */
    sideforce=force*gnidcoeff;

	/* positiv, naar vfront er positiv */
    whl_frc_front=fabs(sin(gear[i].steer*PI/180)*sideforce)*sgn(vfront+locvfront);

	/* negativ, naar fart ind fra styrbord, samme fortegn som vleft */
    whl_frc_left=fabs(cos(gear[i].steer*PI/180)*sideforce)*sgn(sidespeed); /* *sgn(vleft+locvleft); */

    /* Test nu virkning af fulde kraefter */
    /* Hvis den lokale hastighed skifter fortegn, er kraefter for store */
    /* find da kraefter ved interpolation */

    /* kopi af tidl. beregninger */
    testvleft     = vleft-dt*whl_frc_left/totmass;
    testwtop      = wtop+dt*(wheel.x-cg.x)*whl_frc_left/iz;
    testwfront    = wfront+dt*(wheel.z-cg.z)*whl_frc_left/ix;
    testlocvleft  =-testwtop*(wheel.x-cg.x);
    testlocvleft -= testwfront*(wheel.z-cg.z);
    norm          = sqrt((SQR(testvleft+testlocvleft)+SQR(vfront+locvfront)));
    if (fabs(norm)>1e-9) {                               /* Avoid div. by 0 */
       testcombyaw   = arccos((vfront+locvfront)/norm);
       if ((testvleft+testlocvleft) < 0) testcombyaw=-testcombyaw;
       }
    else
       testcombyaw=0;
    testwhlyaw    = testcombyaw+gear[i].steer*gear[i].steergain*PI/180;
    testvhoriz    = sqrt(SQR(vfront+locvfront)+SQR(testvleft+testlocvleft));
    testsidespeed = sin(testwhlyaw)*testvhoriz;

    /* This section contains some damping factors to avoid
       oscillations. They are not really justified py physics */

    if (sidespeed*testsidespeed < 0) /* Opposite sign -> overcorrection */
     {
      /* if(calcnumber==(ncalcperframe-1)){  */

      /*} */
      if (fabs(sidespeed>1e-9)){
         whl_frc_left *= 0.5/(1+fabs(testsidespeed/sidespeed));
         /* 0.5 Is a damping factor - analogous to the elastic properties */
         }
      else
         whl_frc_left=0;
     }
    else
     {
      if (fabs(sidespeed) > 1.0) {
       /* If threshold is lowered near 0, instability is worsening */
       sideskid=true;
       whl_frc_left *= 0.5; /* Skidding */

      }
     }
    /* acc modsat rettet bevaegelse */
    accleft   -= whl_frc_left/totmass;

    /* fortegn checket */
/**************************************/
/* Her indgaar den problematiske wtop */
    wacctop   += (wheel.x-cg.x)*whl_frc_left/iz;

    waccfront += (wheel.z-cg.z)*whl_frc_left/ix;

    /*
    accfront=accfront-whl_frc_front/totmass;
    */
    /* ikke checket */
    /*
    waccleft=waccleft+wheel.z*whl_frc_front/iy;
    */

    /* Kraefter parallelle med rulleretning: rullemodstand og bremse */

    /* frontspeed er hastighed parallelt med rulle-retningen */

    frontspeed=(vfront+locvfront)*fabs(cos(whlyaw));
    frontforce=0;

    if (i < ngears) { /* Wheel rotaional acceleration */
       float rollspeed, diff_omega, d_omega_avail;
       int volume;

       rollspeed  = gear[i].wheel_radius*gear[i].wheel_omega;
       diff_omega = (frontspeed-rollspeed)/gear[i].wheel_radius;
       d_omega_avail= (dt*force*gnidcoeff*gear[i].wheel_radius)/gear[i].wheel_moment;


       if (fabs(diff_omega) < d_omega_avail) {
          gear[i].wheel_omega = frontspeed/gear[i].wheel_radius;
          frontforce+=force*gnidcoeff*diff_omega/d_omega_avail;
       }
       else {
          gear[i].wheel_omega += d_omega_avail*sgn(diff_omega);
          frontforce+=force*gnidcoeff*sgn(diff_omega);
       }

       volume=10*fabs(frontspeed-rollspeed);
       if (volume > 255) volume=255;
       if (touchdown  && volume > 50 && !crash) play_wav(TOUCHDN_WAV, volume, 180, 1000, false);
    }

	// Moon landing
	if (i < ngears && world == MOON) {
		extern bool eagle_landed;

		if (eagle_landed == false && poly_plane_id[current_model]==LM) {
			if (VPRIK(v,v) < 0.01) {
				eagle_landed = true;
				play_wav(EAGLE_LAND_WAV, 255, 180, 1000, false);
			}
		}
	}

    /* Ground rolling rumble volume */
    if (i < ngears) {
       float volume, altvol;

       volume = fabs(frontspeed) / 20 - 0.1;
       if (volume > 1) volume=1;
       if (volume < 0) volume=0;

       altvol=-wheelalt*10;
       if (altvol > 1) altvol=1;
       if (altvol < 0) altvol=0;

       volume *= altvol;

       if (volume > gear_rumble_strength)
          gear_rumble_strength = volume;
    }


	/* kraft afh. af normalkraft og gnid-koeff, */
	/* samt rullemodstand (0.015 iflg. C&B Mek. s. 7-24) og bremse */
    frontforce+=force*gnidcoeff*(0.015+(whlbrakes==true || gear[i].skid)*gear[i].brakeeffect);

    if (i >= ngears) frontforce=force*gear[i].brakeeffect; /* Hardpoint */

	/* positiv, naar vfront er positiv */
    whl_frc_front=fabs(cos(gear[i].steer*PI/180)*frontforce)*sgn(vfront+locvfront);

	/* negativ, naar fart ind fra styrbord, samme fortegn som vleft */
    /*
    whl_frc_left=fabs(cos(gear[i].steer*pi/180)*sideforce)*sgn(vleft+locvleft);
    */

    /* Test nu virkning af fulde kraefter */
    /* Hvis den lokale hastighed skifter fortegn, er kraefter for store */
    /* find da kraefter ved interpolation */

    /* kopi af tidl. beregninger */
    testvfront     = vfront-dt*whl_frc_front/totmass;
    testwtop       = wtop+dt*(wheel.y-cg.y)*whl_frc_front/iz;
    testwleft      = wleft+dt*(wheel.z-cg.z)*whl_frc_front/iy;
    testlocvfront  =-testwtop*(wheel.y-cg.y);
    testlocvfront -= testwleft*(wheel.z-cg.z);
    testlocvleft   =-testwtop*(wheel.x-cg.x);
    testlocvleft  -= wfront*(wheel.z-cg.z);
    norm           = sqrt((SQR(vleft+testlocvleft)+SQR(testvfront+testlocvfront)));
    if (fabs(norm)>1e-9) {                               /* Avoid div. by 0 */
       testcombyaw    = arccos((testvfront+testlocvfront)/norm);
       if ((vleft+testlocvleft) < 0) testcombyaw=-testcombyaw;
       }
    else
       testcombyaw=0;
    testwhlyaw     = testcombyaw+gear[i].steer*gear[i].steergain*PI/180;
    testvhoriz     = sqrt(SQR(testvfront+testlocvfront)+SQR(vleft+testlocvleft));
    testfrontspeed = (testvfront+testlocvfront)*fabs(cos(testwhlyaw));

    if (frontspeed*testfrontspeed < 0) /* modsat fortegn */
     {
      if (fabs(frontspeed)>1e-9){
         whl_frc_front /= (1+fabs(testfrontspeed/frontspeed));
         }
      else whl_frc_front=0;
     }
    else
	if (sideskid==true) {
	/* Kun skid i front-retning hvis ogsaa skid til siden
	   dette emulerer ABS bremser */
		whl_frc_front *= 0.5; /* Skidding */
	}

    if (!(i == steerwhlid && on_catapult != 0)) {
    /* acc modsat rettet bevaegelse */
    accfront -= whl_frc_front/totmass;

    /* naese-ned moment */
    waccleft += (wheel.z-cg.z)*whl_frc_front/iy;

    /* spin-moment */
    wacctop  += (wheel.y-cg.y)*whl_frc_front/iz;
    }

   }
   else gear[i].strokepos=0;
  }
 }

 if(hook.exists) {
  if (wire_trap==0){

  if(hook.down>0) {
   float krogalt;
   cartvektor pln,krog;
   bool on_carrier=false;
   int hook_status;

   krog.x=hook.hingepos.x-hook.length*(1-hook.down*0.643);
   krog.y=hook.hingepos.y;
   krog.z=hook.hingepos.z-hook.length*hook.down*0.766;
   pln.x=x; pln.y=y; pln.z=z;
   pln=vplus(pln,svmult(krog.x,front));
   pln=vplus(pln,svmult(-krog.y,left));
   pln=vplus(pln,svmult(krog.z,top));
   krogalt=pln.z-carrier_deck_alt(pln.x,pln.y);
   if (krogalt < 0) {
      on_carrier=true;
   }



   if (on_carrier) {
      hook_status=hook_deck_pos(pln.x,pln.y);
      if (hook_status < 5 && hook_status > 0 && last_hook_status==(hook_status-1)) {
         /* Trapped a wire */
         char report[MESSAGE_NAMELEN];

         wire_trap=hook_status;
         sprintf(report,"Caught the %d wire",wire_trap);
         set_message(report,8,YELLOW);
      }
      if (hook_status > 3 && last_hook_status==-1) {
         /* Poorly placed */
         bolter_status=true;
         /*
         set_message("BOLTER, BOLTER, BOLTER",4,YELLOW);
         */
      }

      last_hook_status=hook_status;
   }
   else {
      hook_status=hook_deck_pos(pln.x,pln.y);
      if (hook_status==4) {
         bolter_status=true;
         last_hook_status=hook_status;
      }
      else {
        last_hook_status=-1;
        bolter_status=false;
      }
   }
  }

  }
  else {
   /* Wire trapped */
   if (hook.down==0) wire_trap=0; /* Released by raising hook */
   else {
     cartvektor v_carrier=get_carrier_speed(x,y);
     float f_wire;
     int side;

	 f_wire = totmass * 9.82 /* m/sec^2 */ * hook.deaccel / 2;

     for (side=0; side < 2; side++) {
        /* All cartvektors work in x,y,z space */
        cartvektor trap_pos=get_trap_pos(wire_trap,side);
        cartvektor hook_base, hook_to_wire, v_hook, v_rel_carrier;

        locvtop    =-wfront*(hook.hingepos.y-cg.y);
        locvtop   += wleft*(hook.hingepos.x-cg.x);
        locvleft   =-wtop*(hook.hingepos.x-cg.x);
        locvleft  -= wfront*(hook.hingepos.z-cg.z);
        locvfront  =-wtop*(hook.hingepos.y-cg.y);
        locvfront -= wleft*(hook.hingepos.z-cg.z);
        v_hook     = v;
        v_hook     = vplus(v_hook,svmult(locvfront,front));
        v_hook     = vplus(v_hook,svmult(locvleft ,left ));
        v_hook     = vplus(v_hook,svmult(locvtop  ,top  ));

        v_rel_carrier=vminus(v_hook,v_carrier);

        hook_base.x=x; hook_base.y=y; hook_base.z=z;
        hook_base=vplus(hook_base,svmult(hook.hingepos.x,front));
        hook_base=vplus(hook_base,svmult(-hook.hingepos.y,left));
        hook_base=vplus(hook_base,svmult(hook.hingepos.z,top));

        hook_to_wire=vminus(trap_pos,hook_base);

        if ((ncalc % ncalcperframe)==0 && !show_map) {
           /* Graphics code inside the flight model! Yikes! */
           draw_vector(hook_base,trap_pos, DARKGRAY_SHADE);
        }

        if (VPRIK(hook_to_wire,v_rel_carrier) < 0 ) {
          float normfac, frontforce, topforce,leftforce;

          normfac    = sqrt(VPRIK(hook_to_wire,hook_to_wire));
          hook_to_wire = svmult (1/normfac, hook_to_wire);

          frontforce = VPRIK(hook_to_wire,front)*f_wire;
          leftforce  = VPRIK(hook_to_wire,left )*f_wire;
          topforce   = VPRIK(hook_to_wire,top  )*f_wire;

          accfront  += frontforce/totmass;
          accleft   += leftforce/totmass;
          acctop    += topforce/totmass;

          /* This one puts eight on nose-wheel, which creates roll instability */
          waccleft  -= (hook.hingepos.z-cg.z)*frontforce/iy;
          waccleft  += (hook.hingepos.x-cg.x)*topforce/iy;

          /* spin-moment */
          wacctop   += (hook.hingepos.y-cg.y)*frontforce/iz;
          wacctop   -= (hook.hingepos.x-cg.x)*leftforce/iz;

          waccfront -= (hook.hingepos.z-cg.z)*leftforce/ix;

        }
     }
   }  /* endelse hook.down==0 */
  }     /* wire_trap==0 */
 }      /* hook.exists */


 if (on_catapult > 0) {
   cartvektor cat_pos = get_catapult_pos();
   cartvektor cat_to_whl, wheel, pln;
   float frontforce, leftforce, topforce;
   float cat_gradu_strength;

   #define cat_strength 300000. /* Newton per meter */
   #define damp_fac     0.1

   if (!enter_cat_time)
      enter_cat_time = ticks_8h;

   cat_gradu_strength = 3*(ticks_8h-enter_cat_time)/(float)tickspersec;
   if (cat_gradu_strength > 10) cat_gradu_strength=10;
   cat_gradu_strength *= cat_strength;

   wheel.x=gear[steerwhlid].hingepos.x;
   wheel.y=gear[steerwhlid].hingepos.y;
   wheel.z=gear[steerwhlid].hingepos.z
           -(gear[steerwhlid].length
           /* +gear[steerwhlid].stroke*/)  *gear[steerwhlid].down;

   pln.x=x; pln.y=y; pln.z=z;
   pln=vplus(pln,svmult(wheel.x,front));
   pln=vplus(pln,svmult(-wheel.y,left));
   pln=vplus(pln,svmult(wheel.z,top));

   cat_to_whl = vminus(cat_pos, pln);

   frontforce = VPRIK(cat_to_whl,front)*cat_gradu_strength;
   leftforce  = VPRIK(cat_to_whl,left )*cat_gradu_strength;
   topforce   = VPRIK(cat_to_whl,top  )*cat_gradu_strength;

   {
   /* Damping. Does not behave correctly when the cat moves. */
   cartvektor v_carrier=get_carrier_speed(pln.x,pln.y);

   /* Re-calculate speeds, this time without wind-speed */
   vfront=VPRIK(v,front);
   vleft =VPRIK(v,left );
   /* vtop  =VPRIK(v,top  ); */
   vtop=v.z;

   vfront-=VPRIK(v_carrier,front);
   vleft -=VPRIK(v_carrier,left );
   vtop  -=VPRIK(v_carrier,top  );

   locvtop    =-wfront*wheel.y;
   locvtop   += wleft*wheel.x;

   locvleft   =-wtop*wheel.x;
   locvleft  -= wfront*wheel.z;
   locvfront  =-wtop*wheel.y;
   locvfront -= wleft*wheel.z;

   /*
   if((ncalc % ncalcperframe)==0) {
       setcolor(YELLOW);
       moveto(100*xscl,100*yscl);
       if ( sgn(topforce) == sgn(vtop+locvtop) )
           outtext("Damping");
       else
           outtext("Increasing!");
   }
   */

   /* These conditions will slightly help avoiding oscillations on slow machines */
   if ( sgn(frontforce) == sgn(vfront+locvfront) )
      frontforce -= (vfront+locvfront)*damp_fac*cat_gradu_strength;

   if ( sgn(leftforce) == sgn(vleft+locvleft) )
      leftforce  -= (vleft +locvleft )*damp_fac*cat_gradu_strength;

   if ( sgn(topforce) == sgn(vtop+locvtop) )
      topforce   -= (vtop  +locvtop  )*damp_fac*cat_gradu_strength;

   }


   /* Requires damping term! */

   accfront  += frontforce/totmass;
   accleft   += leftforce /totmass;
   acctop    += topforce  /totmass;

   waccleft  -= (wheel.z-cg.z)*frontforce/iy;
   waccleft  += (wheel.x-cg.x)*topforce  /iy;

   wacctop   += (wheel.y-cg.y)*frontforce/iz;
   wacctop   -= (wheel.x-cg.x)*leftforce /iz;

   waccfront -= (wheel.z-cg.z)*leftforce /ix;
 }

  /*
  if((ncalc % ncalcperframe)==0) {
       int i;
       extern short nfueltanks;
       extern tank fueltank[];

       for (i=0; i<nfueltanks; i++) {
         setcolor(YELLOW);
         moveto(10+100*i,50);
         printfg(fueltank[i].content*100.,6,5);
       }
  }
  */

 nowtick=ticks_8h;
 for (i=0; i<nguns; i++)
 {
  if ((fire_guns==true) && (gun[i].nrounds>0) && (nowtick-gun[i].t_last_shot >= tickspersec/gun[i].fire_rate)) {
   float recoil=gun[i].recoil/dt;
   shot_fired=true;
   gun[i].nrounds--;
   gun[i].t_last_shot+=tickspersec/gun[i].fire_rate;
   accfront -= recoil/totmass;
   waccleft += (gun[i].pos.z-cg.z)*recoil/iy;
   wacctop  -= (gun[i].pos.y-cg.y)*recoil/iz;
   if (nactive_bullets<maxnbullets) {
    int id=last_fired_bullet+1;
    if (id < maxnbullets) {
     if (bullet[id].active==true) {
      id=0;
      while(bullet[id].active==true) id++;
     }
    /* pos id is free */
    nactive_bullets++;
    bullet[id].pos.x=x;
    bullet[id].pos.y=y;
    bullet[id].pos.z=z;
    bullet[id].pos=vplus(bullet[id].pos,svmult(gun[i].pos.x,front));
    bullet[id].pos=vplus(bullet[id].pos,svmult(gun[i].pos.y,left));
    bullet[id].pos=vplus(bullet[id].pos,svmult(gun[i].pos.z,top));
    bullet[id].velocity=svmult(gun[i].aim.x,front);
    bullet[id].velocity=vplus(bullet[id].velocity,svmult(gun[i].aim.y+(rnd(100)-50)*0.00003,left));
    bullet[id].velocity=vplus(bullet[id].velocity,svmult(gun[i].aim.z+(rnd(100)-50)*0.00003,top));
    bullet[id].velocity=svmult(gun[i].muzzle_vel,bullet[id].velocity);
    bullet[id].velocity=vplus(bullet[id].velocity,v);
    bullet[id].mass=gun[i].projectile_mass;
    bullet[id].active=true;
    if ( gun[i].tracer_freq > 0) {
       if ( (gun[i].nrounds+i) % gun[i].tracer_freq == 0 )
          bullet[id].tracer = true;
    }
    else
       bullet[id].tracer = false;
    bullet[id].starttime = elapsed_time;
    }
   }
  }
 }

 if (shot_fired) {
    play_wav(CANNON_WAV, 255, 128, 1000, false);
    shot_fired=false;
 }

 /* omregn fra front,left,top accel til x,y,z accel */
 acc.x=front.x*accfront+left.x*accleft+top.x*acctop;
 acc.y=front.y*accfront+left.y*accleft+top.y*acctop;
 acc.z=front.z*accfront+left.z*accleft+top.z*acctop;

 acc.z -= G;  /* Gravity */

 gpull=acctop/9.82; 
 if (elapsed_time > 0.0005) { /* Avoid G's from initial bounce on ground */
  if (gpull > gposmax) gposmax = gpull;
  if (gpull < gnegmax) gnegmax = gpull;
 }
 avg_acctop  += acctop;
 avg_accleft += accleft;

}
