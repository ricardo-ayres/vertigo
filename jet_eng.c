/* Included in ACCEL.C */
/* Code for jet-engines */

 for (i=0; i<njetengines; i++)
 {
  if (detail_jet) {
    float p_comp, p_burner, p_exhaust;
    float fuel_flow;
    float desire, drpmdt, drpm;
    float alt_scale;
    float inflow_quality = 1.0;
    float intake_aoa;
    extern bool consume_fuel(float fuel_flow);
    float flameoutlim, compstalllim;

    alt_scale = pow(density/1.225, 0.7);

    p_comp = (density/1.225)*SQR(jengine[i].rpm);
    p_burner = 0.5 * p_comp;
    p_exhaust= 0.5 * p_burner;

    /* Turbulence of intake flow */
    if (yaw >= 0) {
       intake_aoa =  radtodeg(yaw) / jengine[i].stall_yawright;
    }
    else {
       intake_aoa = -radtodeg(yaw) / jengine[i].stall_yawleft;
    }
    /* At low airspeeds, the intake AOA is decreased from suction */
    intake_aoa /= (1.0+49.0*pow ( 2.5 , -2.5 * SQR( tas/100.0 ) ) );
    inflow_quality *= flow_quality(intake_aoa);

    if (pitch >= 0) {
       intake_aoa =  radtodeg(pitch) / jengine[i].stall_pitchup;
    }
    else {
       intake_aoa = -radtodeg(pitch) / jengine[i].stall_pitchdown;
    }
    /* At low airspeeds, the intake AOA is decreased from suction */
    intake_aoa /= (1.0+49.0*pow ( 2.5 , -2.5 * SQR( tas/100.0 ) ) );
    inflow_quality *= flow_quality(intake_aoa);



    /* Fuel flow */
    fuel_flow = jengine[i].idle_fflow +
                jengine[i].mil_fflow * (jengine[i].throttle/100);

    /* For FF meter. Not measuring AB FF */
    jengine[i].fflw = fuel_flow*alt_scale;

    if (jengine[i].n_abstages > 0 ) {
      fuel_flow += jengine[i].ab_stg_fflow * (int) jengine[i].ab_status;
    }

    /* Fuel consumption scales as thrust */
    fuel_flow *= alt_scale;

    if (!consume_fuel(fuel_flow/rho_fuel)) {
       fuel_flow = 0;
       jengine[i].throttle=0;
       jengine[i].ab_throttle=0;
       jengine[i].ignition = false;
       jengine[i].fflw = 0;
    }

    /* Compressor stall */
    compstalllim = 0.3 * inflow_quality * ( 1.0 + SQR(aircraft_mach_number) ) ;
    compstalllim += SQR(0.01*jengine[i].rpm);

    /* No re-start at very low RPM */
    if (jengine[i].rpm < 0.10 * jengine[i].idle_rpm)
      jengine[i].ignition = false;

    /* RPM change from throttle */
    desire = jengine[i].idle_rpm +
             (jengine[i].throttle/100) * (100 - jengine[i].idle_rpm)
             - jengine[i].rpm;

    if ((jengine[i].throttle == 0 && inflow_quality > 0.5) || !jengine[i].ignition)
       jengine[i].compressor_stall = false;

    if (jengine[i].ignition) {
      compstalllim -= jengine[i].throttle/150.0;
    }

    /* Flame-out */
    flameoutlim = 0.9
                - 1.1  * SQR(1.0-(density/1.225))
                - 0.002* (100-jengine[i].rpm)
                - 0.05 * (1.0-inflow_quality)
                + 0.03 * aircraft_mach_number;
    if (desire < 0)
      flameoutlim += 0.005*desire;
    if (jengine[i].egt < 400)
       flameoutlim -= 0.001*(400-jengine[i].egt);

    if ( flameoutlim < 0) {
    /* Introduce a small random delay of flameout */
       if (rnd(100) < 5)
          jengine[i].ignition = false;
    }

    if (!jengine[i].ignition ) {
       /* Windmilling */
       desire = 40*SQR(aircraft_mach_number)*inflow_quality*density/1.225 - jengine[i].rpm;
    }

    if (jengine[i].compressor_stall)
       desire = - jengine[i].rpm;

    /* Too slow at high alt!? */
    drpmdt=alt_scale*jengine[i].rpm_response*dt;
    if (fabs(desire)>drpmdt)
      drpm=drpmdt*sgn(desire);
    else
      drpm=desire;
    jengine[i].rpm += drpm;

    /* Turn off afterburner of flamed-out engine */
    if (!jengine[i].ignition && jengine[i].ab_status>0) {
      int j;
      bool last = true;

      jengine[i].ab_status = 0;

      /* Only turn off sound if this is the last running AB-engine*/
      for (j=0; j<njetengines; j++)
        if (jengine[j].ignition && jengine[j].ab_status > 0) last = false;
      if (last) {
        ab_burning  = false;
        ab_stopping = true;
      }
    }

    if (jengine[i].ab_status > jengine[i].ab_throttle) {
          jengine[i].ab_status = jengine[i].ab_throttle;
        if (jengine[i].ab_throttle == 0) {
           ab_burning  = false;
           ab_stopping = true;
        }
    }
    else {
      if (jengine[i].rpm > 95) {
        float desire, dab, dabdt;
        int prev_ab_status = jengine[i].ab_status;

        desire = jengine[i].ab_throttle - jengine[i].ab_status;
        dabdt  = jengine[i].ab_response*dt;
        if (fabs(desire)>dabdt)
          dab=dabdt*sgn(desire);
        else
          dab=desire;
        if (!jengine[i].ignition) dab = 0;
        jengine[i].ab_status += dab;
        if (prev_ab_status < (int) jengine[i].ab_status)
           ab_ignition=true;
        if (ab_burning == false && jengine[i].ab_status >= 1) {
          ab_burning  = true;
          ab_starting = true;
        }
      }
    }

    if (jengine[i].ignition && jengine[i].n_abstages > 0 ) {
      compstalllim -= 0.35 * ((int) jengine[i].ab_status) / jengine[i].n_abstages;
    }

    if (compstalllim < 0) {
      jengine[i].compressor_stall = true;
    }

    jengine[i].egt = 600 + 1.3 * jengine[i].rpm + 14 * (int) jengine[i].ab_status;

    if (jengine[i].compressor_stall)
      jengine[i].egt += 10 * jengine[i].throttle;

    if (jengine[i].rpm < 40)
       jengine[i].egt += 0.5*SQR(40 - jengine[i].rpm);

    if(!jengine[i].ignition) jengine[i].egt=0;

    /* First thrust model: */
    /*
       Ram effect approximation based on data from
       Stevens & Lewis: Aircraft Control & Simulation
    */
    /*
    thrust    = 0;
    if (jengine[i].rpm >= jengine[i].idle_rpm) {
      thrust    = jengine[i].idle_thrust;
      thrust   += jengine[i].mil_thrust    *
        (jengine[i].rpm - jengine[i].idle_rpm) / (100 - jengine[i].idle_rpm);
      thrust   += jengine[i].ab_stg_thrust * (int) jengine[i].ab_status;
    }
    else {
      thrust    = jengine[i].idle_thrust *
        (jengine[i].rpm / jengine[i].idle_rpm);
    }
    thrust   *= density/1.225;
    thrust   *= 1.0 + SQR(aircraft_mach_number);
    */

    /* Thrust model based on Mattingley: "Aircraft Engine Design" */
    /* The model includes Mach number for V_in and V_out effects and density */
    thrust    = 0;
    if (jengine[i].rpm >= jengine[i].idle_rpm) {
      float matt_mil = 0.88 + 0.245 * pow( fabs(aircraft_mach_number - 0.6), 1.4);
      float matt_max = 0.94 + 0.38  * pow( fabs(aircraft_mach_number - 0.4), 2.0);
      float abtomilfac;

      thrust    = jengine[i].idle_thrust;
      thrust   += jengine[i].mil_thrust    * matt_mil *
        (jengine[i].rpm - jengine[i].idle_rpm) / (100 - jengine[i].idle_rpm);

      if (jengine[i].n_abstages > 0) {
        abtomilfac = ((jengine[i].ab_stg_thrust * jengine[i].n_abstages)
                     + jengine[i].mil_thrust) / jengine[i].mil_thrust;

        matt_max = abtomilfac*matt_max - matt_mil;

        thrust   += jengine[i].mil_thrust * matt_max * (float) ((int)jengine[i].ab_status) / jengine[i].n_abstages;
      }
    }
    else {
      thrust    = jengine[i].idle_thrust *
        (jengine[i].rpm / jengine[i].idle_rpm);
    }

    thrust   *= alt_scale;

    if (aircraft_mach_number > jengine[i].inlet_ramp_m0) {
      thrust = thrust * (1.0 - jengine[i].inlet_ramp_slope *
               (aircraft_mach_number - jengine[i].inlet_ramp_m0));
      if (thrust < 0) thrust = 0;
    }


    if (fuel_flow == 0) {
       thrust = 0;
       jengine[i].egt = 0;
    }

    if (jengine[i].compressor_stall)
      thrust = 0;


    if (jengine[i].vectordnlim > 0) {
      /* Harrier */
      /* ground-cushion-effect kludge
      tager bl.a ikke hensyn til attitude */
      float gndeffect = 1+0.2*(1/(z-groundalt(x,y)));
      float cosvect   = cos(jengine[i].vectorpos*PI/180);
      float sinvect   = sin(jengine[i].vectorpos*PI/180);

      /* Make engine less efficient when vectoring */
      thrust = 0.85*thrust + 0.15*cosvect;

      accfront += cosvect*thrust/totmass;
      acctop   += gndeffect*sinvect*thrust/totmass;

      wacctop -= (jengine[i].left.masscenter-cg.y)*thrust/iz;
    }
    else {
      /* Normal, non-thrust-vectoring engines */
      accfront += thrust/totmass;
      wacctop  -= (jengine[i].left.masscenter-cg.y)*thrust/iz;
    }

    if ((ncalc % ncalcperframe)==0 /*&& i==0*/) {
     //setcolor(YELLOW);
     /*
     moveto(10*xscl,20*yscl);
     printfg(p_comp*100,6,5);
     outtext(" p_comp");
     moveto(10*xscl,30*yscl);
     printfg(p_burner*100,6,5);
     outtext(" p_burner");
     moveto(10*xscl,40*yscl);
     printfg(p_exhaust*100,6,5);
     outtext(" p_exhaust");
     */

     /*
     moveto(10*xscl,50*yscl);
     printfg(jengine[i].rpm*100,6,5);
     outtext(" RPM  ");
     printfg(jengine[i].ab_status*100,4,3);
     outtext(" AB status");
     moveto(10*xscl,60*yscl);
     printfg((fuel_flow*3600.0/rho_fuel)*100,7,6);
     outtext(" ltr/h");

     moveto(200*xscl,60*yscl);
     printfg(((fuel_flow*3.6/rho_fuel)/0.454)*100,7,6);
     outtext(" 1000 lbs/h");
     */
     /*
     moveto((10+200*i)*xscl,50*yscl);
     printfg(flameoutlim*100,6,5);
     outtext("flameoutlim");

     moveto((10+200*i)*xscl,60*yscl);
     printfg(
     (- SQR(1.0-(density/1.225)))
     *100,6,5);
     outtext("density term");

     moveto((10+200*i)*xscl,70*yscl);
     printfg(
     (- 0.002*(100-jengine[i].rpm))
     *100,6,5);
     outtext("rpm term");

     moveto((10+200*i)*xscl,80*yscl);
     printfg(
     (0.005*desire)
     *100,6,5);
     outtext("desire term");

     moveto((10+200*i)*xscl,90*yscl);
     printfg((density/1.225)*100,6,5);
     outtext(" density");
     */

     /*
     moveto((10+200*i)*xscl,100*yscl);
     printfg(inflow_quality*100,6,5);
     outtext(" flow qual");

     moveto((10+200*i)*xscl,110*yscl);
     printfg(compstalllim*100,6,5);
     outtext(" compstalllim");

     moveto((10+200*i)*xscl,120*yscl);
     printfg(jengine[i].compressor_stall*100,6,5);
     outtext(" compstall");
     */

     /*
     moveto((10+200*i)*xscl,110*yscl);
     printfg( (1.0+49.0*pow ( 2.5 , -2.5 * SQR( tas/100.0 ) ) )*100,6,5);
     outtext(" aoa vel fak");

     moveto((10+200*i)*xscl,120*yscl);
     printfg(tas*100,6,5);
     outtext(" tas");
     */
     /*
     moveto(10*xscl,70*yscl);
     printfg(jengine[i].throttle*100,6,5);
     outtext(" thr     ");
     printfg(jengine[i].ab_throttle*100,6,5);
     outtext(" AB thr");
     */

     /*
     moveto(10*xscl,70*yscl);
     printfg(thrust*100,8,7);
     outtext(" Thrust");

     moveto(10*xscl,80*yscl);
     printfg(inflow_quality*100,6,5);
     outtext(" flow quality");

     moveto(10*xscl,90*yscl);
     printfg(jengine[i].egt*100,6,5);
     outtext(" EGT");
     */

    }


  }
  else {  /* Simple jet model */
    /* ground-cushion-effect kludge
    tager bl.a ikke hensyn til attitude */
    float gndeffect=1+0.2*(1/(z-groundalt(x,y)));

    thrust    = jengine[i].power*jengine[i].rpm/100;
    /* thrust   *= density/1.225; */
    accfront += cos(jengine[i].vectorpos*PI/180)*thrust/totmass;
    acctop   += gndeffect*sin(jengine[i].vectorpos*PI/180)*thrust/totmass;

    /* Ovenstaaende ALT for simpel! */
    /* Torque from thrust */

    /* Denne skal goeres mere detaljeret (mht. vektor-thrust)
    waccleft=waccleft-jengine[i].top.masscenter*thrust/iy;
    */

    wacctop -= (jengine[i].left.masscenter-cg.y)*thrust/iz;
  }


  /* Torque from gravity */
  waccfront += cos_roll    *G*jengine[i].weight*(jengine[i].left.masscenter -cg.y)/ix;
  waccfront += sin_roll    *G*jengine[i].weight*(jengine[i].top.masscenter  -cg.z)/ix;
  waccleft  -= cos_nosealt *G*jengine[i].weight*(jengine[i].front.masscenter-cg.x)/iy;
  waccleft  += sin_nosealt *G*jengine[i].weight*(jengine[i].top.masscenter  -cg.z)/iy;
  wacctop   += sin_roll    *G*jengine[i].weight*(jengine[i].front.masscenter-cg.x)/iz;
  wacctop   += sin_nosealt *G*jengine[i].weight*(jengine[i].left.masscenter -cg.y)/iz;

  /* Vektor-controls */
  if (jengine[i].vectoruplim!=jengine[i].vectordnlim)
   {
    float styrke=0.004;
    waccleft  -= (element[elevatorid].front.liftcenter-cg.x)*thrust*styrke*elevator/iy;
    wacctop   -= (element[rudderid].front.liftcenter-cg.x)*thrust*styrke*rudder/iz;
    waccfront += (element[stbaileronid].left.liftcenter-cg.y)*thrust*styrke*aileron/ix;
   }
 }
