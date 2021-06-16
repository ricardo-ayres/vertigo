/* Included in FLTMODEL.C */
/* Code for propeller engine */

/* Effective fractional propeller radius */
#define R_EFF 0.8

 for (i=0; i<npropengines; i++)
 {
  float L_prop,Tau;
  float omega_prop=2*PI*pengine[i].rpm/60.;
  float int_drag = 1.0;   /* 0.2 */
  float d_rpm_dt = 0.0;
  float fail_throttle;

  /* Torque from gravity */
  waccfront += cos_roll    *G*pengine[i].weight*(pengine[i].left.masscenter- cg.y)/ix;
  waccfront += sin_roll    *G*pengine[i].weight*(pengine[i].top.masscenter  -cg.z)/ix;
  waccleft  -= cos_nosealt *G*pengine[i].weight*(pengine[i].front.masscenter-cg.x)/iy;
  waccleft  += sin_nosealt *G*pengine[i].weight*(pengine[i].top.masscenter  -cg.z)/iy;
  wacctop   += sin_roll    *G*pengine[i].weight*(pengine[i].front.masscenter-cg.x)/iz;
  wacctop   += sin_nosealt *G*pengine[i].weight*(pengine[i].left.masscenter -cg.y)/iz;

  /* RPM */
  if (detail_prop) {
   float engine_torque;
   float high_rpm      = pengine[i].rpm_omega_high*60/(2*PI);
   float idle_throttle = 0.25/pengine[i].reduct_gear;

   /*
      Shape of torque vs. RPM curve resembles
      graphs for two-stroke engines in
      "Ultralight Propulsion" by Glenn Brinks.
   */
   if (pengine[i].rpm <= high_rpm)
      engine_torque= 1-0.9*SQR((pengine[i].rpm/high_rpm)-1);
   else
      engine_torque= 1-2*pow((pengine[i].rpm/high_rpm)-1,1.5);

   if (pengine[i].power==0) fail_throttle=0;
   else fail_throttle=throttle;

   pengine[i].mani_press = (density/1.225)*(idle_throttle+(1-idle_throttle)*fail_throttle/100);

   if (pengine[i].blower_speeds > 0) {
      /* Set auxiliary blower speed */
      int j;

      for (j=0; j<pengine[i].blower_speeds; j++) {
          if (z > pengine[i].blower_alt[j])
             pengine[i].current_blower_speed = j+1;
          if (z < (pengine[i].blower_alt[j] - 30) &&
              pengine[i].current_blower_speed == j+1)
             pengine[i].current_blower_speed = j;
      }

      if (pengine[i].current_blower_speed > 0)
         pengine[i].mani_press *= pengine[i].blower_fak[pengine[i].current_blower_speed-1];

   }

   {
    /* Calculate fuel consumption */
    float effect    = pengine[i].mani_press * pengine[i].torque * omega_prop;
    float fuel_flow = 1.3e-4 * effect / ( 735.5 * pengine[i].fuel_eff );
    extern bool consume_fuel(float fuel_flow);

    if (!consume_fuel(fuel_flow)) {
       engine_torque = 0;
       fuel_flow     = 0;
    }

    /*
    if ((ncalc % ncalcperframe)==0) {
     setcolor(YELLOW);
     moveto(10*xscl,20*yscl);
     printfg((fuel_flow*3600.0/3.705)*100,6,5);
     outtext(" gal/hr");
    }
    */

    if ((ncalc % ncalcperframe)==0)
      total_fuel_flow+=fuel_flow;
   }

   engine_torque *= pengine[i].mani_press * pengine[i].torque * (1+int_drag);

   pengine[i].mani_press *= pengine[i].mani_ref_press *
                            (pengine[i].rpm / high_rpm);

   engine_torque -=(pengine[i].rpm/2700.0)*int_drag*pengine[i].torque;

   omega_prop += engine_torque*dt/pengine[i].inertimoment;
   waccfront  -= engine_torque/iprop[i].x;

   pengine[i].rpm = 60*omega_prop/(2*PI);

   if (pengine[i].rpm < 0) {
      omega_prop=0;
      pengine[i].rpm=0;
   }

   d_rpm_dt = (pengine[i].rpm - pengine[i].last_rpm) / dt;
   pengine[i].last_rpm=pengine[i].rpm;


   /*
   if ((ncalc % ncalcperframe)==0) {
     setcolor(YELLOW);
     moveto(10*xscl,20*yscl);
     printfg(pengine[i].mani_press*100,6,5);
     outtext(" MP");
   }
   if ((ncalc % ncalcperframe)==0) {
     setcolor(YELLOW);
     moveto(10*xscl,40*yscl);
     if (pengine[i].current_blower_speed==0) outtext("N");
     if (pengine[i].current_blower_speed==1) outtext("L");
     if (pengine[i].current_blower_speed==2) outtext("H");
   }
   if ((ncalc % ncalcperframe)==0) {
     setcolor(YELLOW);
     moveto(150*xscl,20*yscl);
     printfg(pengine[i].rpm*100,6,5);
     outtext(" RPM");
   }
   if ((ncalc % ncalcperframe)==0) {
     setcolor(YELLOW);
     moveto(150*xscl,30*yscl);
     printfg(engine_torque*100,6,5);
     outtext(" Eng. torque");
   }
   if ((ncalc % ncalcperframe)==0) {
     setcolor(YELLOW);
     moveto(150*xscl,50*yscl);
     printfg(pengine[i].v_inflow*100,6,5);
     outtext(" V_inflow");
   }
   */


  }

  /* P-factor, etc. */
  if (detail_prop) {
   float stb_locvtop, stb_locvleft, stb_locvfront;
   float prt_locvtop, prt_locvleft, prt_locvfront;
   float top_locvtop, top_locvleft, top_locvfront;
   float bot_locvtop, bot_locvleft, bot_locvfront;
   float stb_vel, prt_vel, top_vel, bot_vel;
   float stb_combpitch, prt_combpitch;
   float top_combyaw, bot_combyaw;
   float stb_blade_AoA, prt_blade_AoA;
   float top_blade_AoA, bot_blade_AoA;
   float stb_cl, stb_lift;
   float stb_profdrag, stb_inddrag, stb_drag, stb_cdi;
   float stb_thrust, stb_torque;
   float prt_cl, prt_lift;
   float prt_profdrag, prt_inddrag, prt_drag, prt_cdi;
   float prt_thrust, prt_torque;
   float top_cl, top_lift;
   float top_profdrag, top_inddrag, top_drag, top_cdi;
   float top_thrust, top_torque;
   float bot_cl, bot_lift;
   float bot_profdrag, bot_inddrag, bot_drag, bot_cdi;
   float bot_thrust, bot_torque;
   float tot_thrust, tot_torque;
   float airmass, min_airmass, prop_area;
   float cos_stb_blade_AoA, sin_stb_blade_AoA;
   float cos_prt_blade_AoA, sin_prt_blade_AoA;
   float cos_top_blade_AoA, sin_top_blade_AoA;
   float cos_bot_blade_AoA, sin_bot_blade_AoA;

   {  /* Pitch governor */
   float target_rpm=pengine[i].rpm_omega_idle+
                    (pengine[i].rpm_omega_high-pengine[i].rpm_omega_idle)*prop_ctrl/100.0;

   target_rpm *= 60/(2*PI);

   /* Digital servo */
   /*
   if (pengine[i].rpm < target_rpm && pengine[i].pitch > pengine[i].min_pitch)
      pengine[i].pitch -= dt*10*PI/180;
   if (pengine[i].rpm > target_rpm && pengine[i].pitch < pengine[i].max_pitch)
      pengine[i].pitch += dt*10*PI/180;
   }
   */
   /* Differentiel servo */
   if (pengine[i].rpm+d_rpm_dt < target_rpm) {
      pengine[i].pitch -= dt*10*PI/180;
      if (pengine[i].pitch < pengine[i].min_pitch) pengine[i].pitch = pengine[i].min_pitch;
   }
   if (pengine[i].rpm+d_rpm_dt > target_rpm) {
      pengine[i].pitch += dt*10*PI/180;
      if (pengine[i].pitch > pengine[i].max_pitch) pengine[i].pitch = pengine[i].max_pitch;
   }
   }

   stb_locvtop    =-wfront*(pengine[i].spinnerloc.y-pengine[i].radius*R_EFF);
   stb_locvtop   += wleft * pengine[i].spinnerloc.x;
   stb_locvtop   -= omega_prop*pengine[i].radius*R_EFF;
   stb_locvleft   =-wtop  * pengine[i].spinnerloc.x;
   stb_locvleft  -= wfront* pengine[i].spinnerloc.z;
   stb_locvfront  =-wtop  *(pengine[i].spinnerloc.y-pengine[i].radius*R_EFF);
   stb_locvfront -= wleft * pengine[i].spinnerloc.z;
   stb_locvfront += pengine[i].v_inflow;

   prt_locvtop    =-wfront*(pengine[i].spinnerloc.y+pengine[i].radius*R_EFF);
   prt_locvtop   += wleft * pengine[i].spinnerloc.x;
   prt_locvtop   += omega_prop*pengine[i].radius*R_EFF;
   prt_locvleft   =-wtop  * pengine[i].spinnerloc.x;
   prt_locvleft  -= wfront* pengine[i].spinnerloc.z;
   prt_locvfront  =-wtop  *(pengine[i].spinnerloc.y+pengine[i].radius*R_EFF);
   prt_locvfront -= wleft * pengine[i].spinnerloc.z;
   prt_locvfront += pengine[i].v_inflow;

   top_locvtop    =-wfront* pengine[i].spinnerloc.y;
   top_locvtop   += wleft * pengine[i].spinnerloc.x;
   top_locvleft   =-wtop  * pengine[i].spinnerloc.x;
   top_locvleft  -= wfront*(pengine[i].spinnerloc.z+pengine[i].radius*R_EFF);
   top_locvleft  -= omega_prop*pengine[i].radius*R_EFF;
   top_locvfront  =-wtop  * pengine[i].spinnerloc.y;
   top_locvfront -= wleft *(pengine[i].spinnerloc.z+pengine[i].radius*R_EFF);
   top_locvfront += pengine[i].v_inflow;

   bot_locvtop    =-wfront* pengine[i].spinnerloc.y;
   bot_locvtop   += wleft * pengine[i].spinnerloc.x;
   bot_locvleft   =-wtop  * pengine[i].spinnerloc.x;
   bot_locvleft  -= wfront*(pengine[i].spinnerloc.z+pengine[i].radius*R_EFF);
   bot_locvleft  += omega_prop*pengine[i].radius*R_EFF;
   bot_locvfront  =-wtop  * pengine[i].spinnerloc.y;
   bot_locvfront -= wleft *(pengine[i].spinnerloc.z-pengine[i].radius*R_EFF);
   bot_locvfront += pengine[i].v_inflow;

   stb_vel=sqrt((SQR(vfront+stb_locvfront)+SQR(vtop+stb_locvtop)));
   if (fabs(stb_vel)>1e-9) {                               /* Avoid div. by 0 */
      stb_combpitch=arccos((vfront+stb_locvfront)/stb_vel);
      if ((vtop+stb_locvtop) > 0) stb_combpitch=-stb_combpitch;
      }
   else
      stb_combpitch=0;

   /* Angle of airstream relative to blade pitch */
   stb_blade_AoA=pengine[i].pitch-(PI/2-stb_combpitch);

   /* Angle of airstream relative to plane of rotation */
   stb_combpitch=PI/2-stb_combpitch;

   prt_vel=sqrt((SQR(vfront+prt_locvfront)+SQR(vtop+prt_locvtop)));
   if (fabs(prt_vel)>1e-9) {                               /* Avoid div. by 0 */
      prt_combpitch=arccos((vfront+prt_locvfront)/prt_vel);
      if ((vtop+prt_locvtop) > 0) prt_combpitch=-prt_combpitch;
      }
   else
      prt_combpitch=0;

   /* Angle of airstream relative to blade pitch */
   prt_blade_AoA=pengine[i].pitch-(PI/2+prt_combpitch);

   /* Angle of airstream relative to plane of rotation */
   prt_combpitch=PI/2+prt_combpitch;

   top_vel=sqrt((SQR(vfront+top_locvfront)+SQR(vleft+top_locvleft)));
   if (fabs(top_vel)>1e-9) {                               /* Avoid div. by 0 */
      top_combyaw=arccos((vfront+top_locvfront)/top_vel);
      if ((vleft+top_locvleft) > 0) top_combyaw=-top_combyaw;
      }
   else
      top_combyaw=0;

   /* Angle of airstream relative to blade pitch */
   top_blade_AoA=pengine[i].pitch-(PI/2-top_combyaw);

   /* Angle of airstream relative to plane of rotation */
   top_combyaw=PI/2-top_combyaw;


   bot_vel=sqrt((SQR(vfront+bot_locvfront)+SQR(vleft+bot_locvleft)));
   if (fabs(bot_vel)>1e-9) {                               /* Avoid div. by 0 */
      bot_combyaw=arccos((vfront+bot_locvfront)/bot_vel);
      if ((vleft+bot_locvleft) > 0) bot_combyaw=-bot_combyaw;
      }
   else
      bot_combyaw=0;

   /* Angle of airstream relative to blade pitch */
   bot_blade_AoA=pengine[i].pitch-(PI/2+bot_combyaw);

   /* Angle of airstream relative to plane of rotation */
   bot_combyaw=PI/2+bot_combyaw;

   /*
   if ((ncalc % ncalcperframe)==0) {
     setcolor(RED);
     moveto(50*xscl,70*yscl);
     printfg((prt_combpitch*180/PI)*100,6,5);
   }
   if ((ncalc % ncalcperframe)==0) {
     setcolor(LIGHTGREEN);
     moveto(100*xscl,70*yscl);
     printfg((stb_combpitch*180/PI)*100,6,5);
     outtext(" combpitch");
   }
   if ((ncalc % ncalcperframe)==0) {
     setcolor(WHITE);
     moveto(200*xscl,70*yscl);
     printfg((top_combyaw*180/PI)*100,6,5);
   }
   if ((ncalc % ncalcperframe)==0) {
     setcolor(BLACK);
     moveto(250*xscl,70*yscl);
     printfg((bot_combyaw*180/PI)*100,6,5);
     outtext(" combyaw");
   }

   if ((ncalc % ncalcperframe)==0) {
     setcolor(RED);
     moveto(50*xscl,90*yscl);
     printfg((prt_blade_AoA*180/PI)*100,6,5);
   }
   if ((ncalc % ncalcperframe)==0) {
     setcolor(LIGHTGREEN);
     moveto(100*xscl,90*yscl);
     printfg((stb_blade_AoA*180/PI)*100,6,5);
     outtext(" Prop AoA");
   }
   if ((ncalc % ncalcperframe)==0) {
     setcolor(WHITE);
     moveto(200*xscl,90*yscl);
     printfg((top_blade_AoA*180/PI)*100,6,5);
   }
   if ((ncalc % ncalcperframe)==0) {
     setcolor(BLACK);
     moveto(250*xscl,90*yscl);
     printfg((bot_blade_AoA*180/PI)*100,6,5);
   }

   if ((ncalc % ncalcperframe)==0) {
     setcolor(YELLOW);
     moveto(150*xscl,40*yscl);
     printfg((pengine[i].pitch*180/PI)*100,6,5);
     outtext(" Prop Pitch");
   }
   */

   cos_stb_blade_AoA=cos(stb_blade_AoA);
   sin_stb_blade_AoA=sin(stb_blade_AoA);
   cos_prt_blade_AoA=cos(prt_blade_AoA);
   sin_prt_blade_AoA=sin(prt_blade_AoA);
   cos_top_blade_AoA=cos(top_blade_AoA);
   sin_top_blade_AoA=sin(top_blade_AoA);
   cos_bot_blade_AoA=cos(bot_blade_AoA);
   sin_bot_blade_AoA=sin(bot_blade_AoA);

   /*
   stb_cl       = cl((stb_blade_AoA)*180/PI,pengine[i].aspect_ratio,
                  pengine[i].curvature);
   */
   stb_cl       = cl_naca(stb_blade_AoA*180/PI);
   stb_lift     = 0.5*density*SQR(stb_vel)*
                  pengine[i].top_area*stb_cl;
   /*
   stb_profdrag = 0.5*density*SQR(stb_vel)*
                  fabs(cos_stb_blade_AoA)*pengine[i].front_area*
	               pengine[i].front_dragcoeff;
   stb_profdrag+= 0.5*density*SQR(stb_vel)*
                  fabs(sin_stb_blade_AoA)*pengine[i].top_area*
	               pengine[i].top_dragcoeff;
   */

   /* ??? drag prop. med top eller front areal? */

   /* Calculating change of AoA due to inflow and also calculating */
   /* "standard" induced drag may be resulting in twice the amount of */
   /* induced drag(?) */

   stb_profdrag = 0.5*density*SQR(stb_vel)*pengine[i].top_area*
	               (cd_naca((stb_blade_AoA)*180/PI)/*+pengine[i].front_dragcoeff*/);
   stb_cdi      = SQR(stb_cl)/(PI*pengine[i].aspect_ratio);
   stb_inddrag  = 0.5*density*SQR(stb_vel)*pengine[i].top_area*
	               stb_cdi;
   stb_drag     = stb_profdrag+stb_inddrag;

   stb_thrust   = cos(stb_combpitch)*stb_lift-sin(stb_combpitch)*stb_drag;

   stb_torque   = sin(stb_combpitch)*stb_lift+cos(stb_combpitch)*stb_drag;

   /*
   if ((ncalc % ncalcperframe)==0) {
     setcolor(YELLOW);
     moveto(300*xscl,10*yscl);
     printfg((0.5*density*SQR(stb_vel)*
                  fabs(cos(stb_blade_AoA))*pengine[i].front_area*
	               pengine[i].front_dragcoeff)*100,6,5);
     outtext(" front-profdrag");
   }
   if ((ncalc % ncalcperframe)==0) {
     setcolor(YELLOW);
     moveto(300*xscl,20*yscl);
     printfg((0.5*density*SQR(stb_vel)*
                  fabs(sin(stb_blade_AoA))*pengine[i].top_area*
	               pengine[i].top_dragcoeff)*100,6,5);
     outtext(" top-profdrag");
   }
   if ((ncalc % ncalcperframe)==0) {
     setcolor(YELLOW);
     moveto(300*xscl,30*yscl);
     printfg(stb_profdrag*100,6,5);
     outtext(" stb-profdrag");
   }
   if ((ncalc % ncalcperframe)==0) {
     setcolor(YELLOW);
     moveto(300*xscl,40*yscl);
     printfg((0.5*density*SQR(stb_vel)*pengine[i].top_area*
	               stb_cdi)*100,6,5);
     outtext(" induced");
   }
   if ((ncalc % ncalcperframe)==0) {
     setcolor(YELLOW);
     moveto(300*xscl,50*yscl);
     printfg((stb_cl)*100,6,5);
     outtext(" C_l");
   }
   */


   /*
   prt_cl       = cl((prt_blade_AoA)*180/PI,pengine[i].aspect_ratio,
                  pengine[i].curvature);
   */
   prt_cl       = cl_naca(prt_blade_AoA*180/PI);
   prt_lift     = 0.5*density*SQR(prt_vel)*
                  pengine[i].top_area*prt_cl;
   /*
   prt_profdrag = 0.5*density*SQR(prt_vel)*
                  fabs(cos_prt_blade_AoA)*pengine[i].front_area*
	               pengine[i].front_dragcoeff;
   prt_profdrag+= 0.5*density*SQR(prt_vel)*
                  fabs(sin_prt_blade_AoA)*pengine[i].top_area*
	               pengine[i].top_dragcoeff;
   */
   prt_profdrag = 0.5*density*SQR(prt_vel)*pengine[i].top_area*
	               (cd_naca((prt_blade_AoA)*180/PI)/*+pengine[i].front_dragcoeff*/);
   prt_cdi      = SQR(prt_cl)/(PI*pengine[i].aspect_ratio);
   prt_inddrag  = 0.5*density*SQR(prt_vel)*pengine[i].top_area*
	               prt_cdi;
   prt_drag     = prt_profdrag+prt_inddrag;

   prt_thrust   = cos(prt_combpitch)*prt_lift-sin(prt_combpitch)*prt_drag;

   prt_torque   = sin(prt_combpitch)*prt_lift+cos(prt_combpitch)*prt_drag;

   /*
   top_cl       = cl((top_blade_AoA)*180/PI,pengine[i].aspect_ratio,
                  pengine[i].curvature);
   */
   top_cl       = cl_naca(top_blade_AoA*180/PI);
   top_lift     = 0.5*density*SQR(top_vel)*
                  pengine[i].top_area*top_cl;
   /*
   top_profdrag = 0.5*density*SQR(top_vel)*
                  fabs(cos_top_blade_AoA)*pengine[i].front_area*
	               pengine[i].front_dragcoeff;
   top_profdrag+= 0.5*density*SQR(top_vel)*
                  fabs(sin_top_blade_AoA)*pengine[i].top_area*
	               pengine[i].top_dragcoeff;
   */
   top_profdrag = 0.5*density*SQR(top_vel)*pengine[i].top_area*
	               (cd_naca((top_blade_AoA)*180/PI)/*+pengine[i].front_dragcoeff*/);
   top_cdi      = SQR(top_cl)/(PI*pengine[i].aspect_ratio);
   top_inddrag  = 0.5*density*SQR(top_vel)*pengine[i].top_area*
	               top_cdi;
   top_drag     = top_profdrag+top_inddrag;

   top_thrust   = cos(top_combyaw)*top_lift-sin(top_combyaw)*top_drag;

   top_torque   = sin(top_combyaw)*top_lift+cos(top_combyaw)*top_drag;

   /*
   bot_cl       = cl((bot_blade_AoA)*180/PI,pengine[i].aspect_ratio,
                  pengine[i].curvature);
   */
   bot_cl       = cl_naca(bot_blade_AoA*180/PI);
   bot_lift     = 0.5*density*SQR(bot_vel)*
                  pengine[i].top_area*bot_cl;
   /*
   bot_profdrag = 0.5*density*SQR(bot_vel)*
                  fabs(cos_bot_blade_AoA)*pengine[i].front_area*
	               pengine[i].front_dragcoeff;
   bot_profdrag+= 0.5*density*SQR(bot_vel)*
                  fabs(sin_bot_blade_AoA)*pengine[i].top_area*
	               pengine[i].top_dragcoeff;
   */
   bot_profdrag = 0.5*density*SQR(bot_vel)*pengine[i].top_area*
	               (cd_naca((bot_blade_AoA)*180/PI)/*+pengine[i].front_dragcoeff*/);
   bot_cdi      = SQR(bot_cl)/(PI*pengine[i].aspect_ratio);
   bot_inddrag  = 0.5*density*SQR(bot_vel)*pengine[i].top_area*
	               bot_cdi;
   bot_drag     = bot_profdrag+bot_inddrag;

   bot_thrust   = cos(bot_combyaw)*bot_lift-sin(bot_combyaw)*bot_drag;

   bot_torque   = sin(bot_combyaw)*bot_lift+cos(bot_combyaw)*bot_drag;

   /*
   if ((ncalc % ncalcperframe)==0) {
     setcolor(LIGHTGREEN);
     moveto(100*xscl,110*yscl);
     printfg(stb_thrust*100,7,6);
     outtext(" Thrust");
   }
   if ((ncalc % ncalcperframe)==0) {
     setcolor(LIGHTGREEN);
     moveto(100*xscl,130*yscl);
     printfg(stb_torque*100,7,6);
     outtext(" Torque");
   }
   if ((ncalc % ncalcperframe)==0) {
     setcolor(RED);
     moveto(50*xscl,110*yscl);
     printfg(prt_thrust*100,7,6);
   }
   if ((ncalc % ncalcperframe)==0) {
     setcolor(RED);
     moveto(50*xscl,130*yscl);
     printfg(prt_torque*100,7,6);
   }
   if ((ncalc % ncalcperframe)==0) {
     setcolor(WHITE);
     moveto(200*xscl,110*yscl);
     printfg(top_thrust*100,7,6);
   }
   if ((ncalc % ncalcperframe)==0) {
     setcolor(WHITE);
     moveto(200*xscl,130*yscl);
     printfg(top_torque*100,7,6);
   }
   if ((ncalc % ncalcperframe)==0) {
     setcolor(BLACK);
     moveto(250*xscl,110*yscl);
     printfg(bot_thrust*100,7,6);
   }
   if ((ncalc % ncalcperframe)==0) {
     setcolor(BLACK);
     moveto(250*xscl,130*yscl);
     printfg(bot_torque*100,7,6);
   }
   */


   prt_thrust *= pengine[i].n_blades/4.0;
   stb_thrust *= pengine[i].n_blades/4.0;
   top_thrust *= pengine[i].n_blades/4.0;
   bot_thrust *= pengine[i].n_blades/4.0;

   tot_thrust = prt_thrust + stb_thrust + top_thrust + bot_thrust;

   /*
   if ((ncalc % ncalcperframe)==0) {
     setcolor(YELLOW);
     moveto(300*xscl,110*yscl);
     printfg(tot_thrust*100,7,6);
   }
   */

   /* Forces on aircraft */
   accfront += tot_thrust/totmass;

   waccleft -= ( pengine[i].spinnerloc.z-cg.z)*stb_thrust/iy;
   wacctop  += ((pengine[i].spinnerloc.y-cg.y)-pengine[i].radius*R_EFF)*stb_thrust/iz;
   waccleft -= ( pengine[i].spinnerloc.z-cg.z)*prt_thrust/iy;
   wacctop  += ((pengine[i].spinnerloc.y-cg.y)+pengine[i].radius*R_EFF)*prt_thrust/iz;
   waccleft -= ((pengine[i].spinnerloc.z-cg.z)+pengine[i].radius*R_EFF)*top_thrust/iy;
   wacctop  += ( pengine[i].spinnerloc.y-cg.y)*top_thrust/iz;
   waccleft -= ((pengine[i].spinnerloc.z-cg.z)-pengine[i].radius*R_EFF)*bot_thrust/iy;
   wacctop  += ( pengine[i].spinnerloc.y-cg.y)*bot_thrust/iz;

   tot_torque  = stb_torque + prt_torque + top_torque + bot_torque;

   tot_torque *= pengine[i].n_blades/4.0;

   omega_prop -= dt*pengine[i].radius*R_EFF*tot_torque/pengine[i].inertimoment;

   pengine[i].rpm = 60*omega_prop/(2*PI);

   /* Prop-vortex "caught" by airframe */
   waccfront  += (1.-pengine[i].vortex_gain)*tot_torque/iprop[i].x;

   /* Prop-wash */
   prop_area = PI * SQR(pengine[i].radius);
   airmass   = prop_area * density * ( vfront +
               (stb_locvfront+prt_locvfront+top_locvfront+bot_locvfront)/4);
   min_airmass = prop_area*density;
   if (airmass < min_airmass) airmass = min_airmass;

   /* Prop-wash is low-pass filtered to avoid oscillation */
   /* Wash-speed at the propeller is half the final wash speed far behind */
   pengine[i].v_inflow = 0.75*pengine[i].v_inflow + 0.25*0.5*tot_thrust/airmass;

   /*
   if ((ncalc % ncalcperframe)==0) {
     setcolor(YELLOW);
     moveto(150*xscl,60*yscl);
     printfg(airmass*100,6,5);
     outtext(" airmass");
   }
   */

   /* Prop vortex */
   pengine[i].omega_vortex = tot_torque / ( 0.5 * airmass * SQR(pengine[i].radius) );

   /*
   if ((ncalc % ncalcperframe)==0) {
     setcolor(YELLOW);
     moveto(150*xscl,80*yscl);
     printfg(pengine[i].omega_vortex*100,6,5);
     outtext(" omega_vortex");
   }
   */

  }

  /* Gyroscopic forces */
  if (detail_prop){
     L_prop=pengine[i].inertimoment*(omega_prop+wfront);
     Tau=L_prop*wleft;
     wacctop += Tau/iprop[i].z;
     Tau=L_prop*wtop;
     waccleft-= Tau/iprop[i].y;
  }

 if (!detail_prop) {
  /* Den enkle propelmotor-model */
  thrust=pengine[i].power*pengine[i].rpm_percent/100;
  accfront += thrust/totmass;
  acctop   += thrust/totmass;

  /* Torque from thrust */
  waccleft-= (pengine[i].spinnerloc.z-cg.z)*thrust/iy;
  wacctop += (pengine[i].spinnerloc.y-cg.y)*thrust/iz;
 }


 }
