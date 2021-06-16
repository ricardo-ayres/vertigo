/* SAAB T-17 */

/* Some shortcomings of model compared to the real thing:

   Wing drops too easily in a stall.
   High-G maneuvers are too difficult, e.g.,
   a loop, entry 4G, 140kts, should be easy.

*/

/*
   Starboard: Positive for sweep-back
              Positive for dihedral (v-shape)
   Port:      Negative for sweep-back
              Negative for dihedral (v-shape)
*/

/* The T-17 has wings 5 deg swept forward. */
/* The dihedral is exaggerated to 5 deg.   */
/* It is approx. 2 deg in reality.         */



 strcpy(modelname,"Dihedral demo");

 /* Starboard outer wing section */
 wingsection[0].area        =  1.36*1.50; /* m^2 */
 wingsection[0].aspect      =  6.5;
 wingsection[0].sweepback   =    0; /* -5 */   /* Degrees */
 wingsection[0].dihedral    =   15; /*  2 */   /* Degrees */
 wingsection[0].pitchup     =    0;            /* Degrees */
 wingsection[0].weight      =   80;            /* Kg */
 wingsection[0].airfoiltype = GENERIC;
 wingsection[0].oswald      =    0.35;
 wingsection[0].deflect     =    0;
 wingsection[0].aerocenter.x=    0.2;
 wingsection[0].aerocenter.y=    3.7;
 wingsection[0].aerocenter.z=    0.45;
 wingsection[0].masscenter.x=   -0.25;
 wingsection[0].masscenter.y=    3.7;
 wingsection[0].masscenter.z=    0.45;
 wingsection[0].ailerongain =   -1;
 wingsection[0].curvature   =    3;

 /* Port outer wing section */
 wingsection[1].area        =   1.36*1.50; /* m^2 */
 wingsection[1].aspect      =  6.5;
 wingsection[1].sweepback   =    0; /*  5 */  /* Degrees */
 wingsection[1].dihedral    =  -15; /* -2 */  /* Degrees */
 wingsection[1].pitchup     =    0;          /* Degrees */
 wingsection[1].weight      =   80;          /* Kg */
 wingsection[1].airfoiltype = GENERIC;
 wingsection[1].oswald      =    0.35;
 wingsection[1].deflect     =    0;
 wingsection[1].aerocenter.x=    0.2;
 wingsection[1].aerocenter.y=   -3.7;
 wingsection[1].aerocenter.z=    0.45;
 wingsection[1].masscenter.x=   -0.25;
 wingsection[1].masscenter.y=   -3.7;
 wingsection[1].masscenter.z=    0.45;
 wingsection[1].ailerongain =    1;
 wingsection[1].curvature   =    3;

 /* Starboard inner wing section */
 wingsection[2].area        =  1.36*2.3; /* m^2 */
 wingsection[2].aspect      =  6.5;
 wingsection[2].sweepback   =    0; /* -5 */  /* Degrees */
 wingsection[2].dihedral    =   15; /*  2 */  /* Degrees */
 wingsection[2].pitchup     =    0;          /* Degrees */
 wingsection[2].weight      =  120;          /* Kg */
 wingsection[2].airfoiltype = GENERIC;
 wingsection[2].oswald      =    1.2;
 wingsection[2].deflect     =    0;
 wingsection[2].aerocenter.x=    0.0;
 wingsection[2].aerocenter.y=    1.8;
 wingsection[2].aerocenter.z=    0.4;
 wingsection[2].masscenter.x=   -0.4;
 wingsection[2].masscenter.y=    1.8;
 wingsection[2].masscenter.z=    0.4;
 wingsection[2].ailerongain =    1;
 wingsection[2].curvature   =    3;

 /* Port inner wing section */
 wingsection[3].area        =  1.36*2.3; /* m^2 */
 wingsection[3].aspect      =  6.5;
 wingsection[3].sweepback   =    0; /*  5 */  /* Degrees */
 wingsection[3].dihedral    =  -15; /* -2 */  /* Degrees */
 wingsection[3].pitchup     =    0;          /* Degrees */
 wingsection[3].weight      =  120;          /* Kg */
 wingsection[3].airfoiltype = GENERIC;
 wingsection[3].oswald      =    1.2;
 wingsection[3].deflect     =    0;
 wingsection[3].aerocenter.x=    0.0;
 wingsection[3].aerocenter.y=   -1.8;
 wingsection[3].aerocenter.z=    0.4;
 wingsection[3].masscenter.x=   -0.4;
 wingsection[3].masscenter.y=   -1.8;
 wingsection[3].masscenter.z=    0.4;
 wingsection[3].ailerongain =    1;
 wingsection[3].curvature   =    3;


 /* Body */
 element[0].weight=200; 	 		         /* Kg */
 element[0].topcurvature=0;
 element[0].front.area=1.1*1.3;    		/* m^2 */
 element[0].front.aspect=1.1;
 element[0].front.dragcoeff=.3;		   /* min 0, max 1 */
 element[0].front.masscenter=-0.4;
 element[0].front.liftcenter= 0.0;
 element[0].front.dragcenter= 0.0;
 element[0].front.deflect=0;
 element[0].left.area=1*6*0.1;
 element[0].left.aspect=0.5;
 element[0].left.dragcoeff=0.5;
 element[0].left.masscenter=0;
 element[0].left.liftcenter=0;
 element[0].left.dragcenter=0;
 element[0].left.deflect=0;
 element[0].top.area=0.7*6;
 element[0].top.aspect=0.12;
 element[0].top.dragcoeff=0.5;
 element[0].top.masscenter=-0.2;
 element[0].top.liftcenter=0;
 element[0].top.dragcenter=0;
 element[0].top.deflect=0;
 element[0].top.oswald=0.5;

 /** Tail plane **/
 element[1].weight=20;
 element[1].topcurvature=0;
 element[1].front.area=0.05*2.85;
 element[1].front.aspect=25;
 element[1].front.dragcoeff=.1;
 element[1].front.masscenter=-4.1;
 element[1].front.liftcenter=-4.0;
 element[1].front.dragcenter=-4.0;
 element[1].front.deflect=0;
 element[1].left.area=0;
 element[1].left.aspect=10;
 element[1].left.dragcoeff=0.1;
 element[1].left.masscenter=0;
 element[1].left.liftcenter=0;
 element[1].left.dragcenter=0;
 element[1].left.deflect=0;
 element[1].top.area=2.85*0.80;
 element[1].top.aspect=3.6;
 element[1].top.dragcoeff=0.6;
 element[1].top.masscenter=1.12;
 element[1].top.liftcenter=1.12;
 element[1].top.dragcenter=1.12;
 element[1].top.deflect=0;
 element[1].top.oswald=0.7;

 /** Tail fin **/
 element[2].weight=20;
 element[2].topcurvature=0;
 element[2].front.area=0.05*1;
 element[2].front.aspect=20;
 element[2].front.dragcoeff=.1;
 element[2].front.masscenter=-4.1;
 element[2].front.liftcenter=-4.0;
 element[2].front.dragcenter=-4.0;
 element[2].front.deflect=0;
 element[2].left.area=2.0            * 0.4;
 element[2].left.aspect=1.5;
 element[2].left.dragcoeff=0.6;
 element[2].left.masscenter=0;
 element[2].left.liftcenter=0;
 element[2].left.dragcenter=0;
 element[2].left.deflect=0;
 element[2].top.area=0;
 element[2].top.aspect=10;
 element[2].top.dragcoeff=0.1;
 element[2].top.masscenter=1;
 element[2].top.liftcenter=1;
 element[2].top.dragcenter=1;
 element[2].top.deflect=0;
 element[2].top.oswald=0.1;

 /** Starboard inner wing section **/
 element[3].weight=0;
 element[3].topcurvature=3;
 element[3].front.area=0.1*2.3  /* *0 */;
 element[3].front.aspect=23;
 element[3].front.dragcoeff=.1;
 element[3].front.masscenter=-.4;
 element[3].front.liftcenter= 0.0;
 element[3].front.dragcenter=-0.0;
 element[3].front.deflect=0;
 element[3].left.area=0;
 element[3].left.aspect=10;
 element[3].left.dragcoeff=0.1;
 element[3].left.masscenter=1.8;
 element[3].left.liftcenter=1.8;
 element[3].left.dragcenter=1.8;
 element[3].left.deflect=0;
 element[3].top.area=1.36*2.3              *0;
 element[3].top.aspect=6.5;
 element[3].top.dragcoeff=0.6;
 element[3].top.masscenter=0.4;
 element[3].top.liftcenter=0.4;
 element[3].top.dragcenter=0.4;
 element[3].top.deflect=0;
 element[3].top.oswald=1.2;

 /** Port inner wing section **/
 element[4].weight=0;
 element[4].topcurvature=3;
 element[4].front.area=0.1*2.3     /* *0 */;
 element[4].front.aspect=23;
 element[4].front.dragcoeff=.1;
 element[4].front.masscenter=-.4;
 element[4].front.liftcenter= 0.0;
 element[4].front.dragcenter=-0.0;
 element[4].front.deflect=0;
 element[4].left.area=0;
 element[4].left.aspect=10;
 element[4].left.dragcoeff=0.1;
 element[4].left.masscenter=-1.8;
 element[4].left.liftcenter=-1.8;
 element[4].left.dragcenter=-1.8;
 element[4].left.deflect=0;
 element[4].top.area=1.36*2.3              *0;
 element[4].top.aspect=6.5;
 element[4].top.dragcoeff=0.6;
 element[4].top.masscenter=0.4;
 element[4].top.liftcenter=0.4;
 element[4].top.dragcenter=0.4;
 element[4].top.deflect=0;
 element[4].top.oswald=1.2;

 /** Starbard outer wing section **/
 element[5].weight=0;
 element[5].topcurvature=3;
 element[5].front.area=0.1*1.50  /* *0  */;
 element[5].front.aspect=15;
 element[5].front.dragcoeff=.1;
 element[5].front.masscenter=-.25;
 element[5].front.liftcenter= 0.2;
 element[5].front.dragcenter= 0.2;
 element[5].front.deflect=0;
 element[5].left.area=0;
 element[5].left.aspect=10;
 element[5].left.dragcoeff=0.1;
 element[5].left.masscenter=3.7;
 element[5].left.liftcenter=3.7;
 element[5].left.dragcenter=3.7;
 element[5].left.deflect=0;
 element[5].top.area=1.36*1.50            *0;
 element[5].top.aspect=6.5;
 element[5].top.dragcoeff=0.6;
 element[5].top.masscenter=0.45;
 element[5].top.liftcenter=0.45;
 element[5].top.dragcenter=0.45;
 element[5].top.deflect=0;
 element[5].top.oswald=0.35;

 /** Port outer wing section **/
 element[6].weight=0;
 element[6].topcurvature=3;
 element[6].front.area=0.1*1.50 /* *0 */;
 element[6].front.aspect=15;
 element[6].front.dragcoeff=.1;
 element[6].front.masscenter=-.25;
 element[6].front.liftcenter= 0.2;
 element[6].front.dragcenter= 0.2;
 element[6].front.deflect=0;
 element[6].left.area=0;
 element[6].left.aspect=10;
 element[6].left.dragcoeff=0.1;
 element[6].left.masscenter=-3.7;
 element[6].left.liftcenter=-3.7;
 element[6].left.dragcenter=-3.7;
 element[6].left.deflect=0;
 element[6].top.area=1.36*1.50              *0;
 element[6].top.aspect=6.5;
 element[6].top.dragcoeff=0.6;
 element[6].top.masscenter=0.45;
 element[6].top.liftcenter=0.45;
 element[6].top.dragcenter=0.45;
 element[6].top.deflect=0;
 element[6].top.oswald=0.35;

 /** Prop-engine **/
 /* Unused parameters not (yet) defined */
 /* Mass and thrust origins in same point */
 pengine[0].weight=170;
 pengine[0].front.masscenter=1.4;
 pengine[0].left.masscenter=0;
 pengine[0].top.masscenter=0;
 pengine[0].throttle=100;   /* % */
 pengine[0].rpm=550;        /* rpm */
 pengine[0].last_rpm=pengine[0].rpm;
 pengine[0].rpm_percent=0;/* % */
 pengine[0].response=20;  /* %/sec */
 pengine[0].power=3000                * 2;   /* Newton */
 pengine[0].reduct_gear    = 1.0;
 pengine[0].torque=520*1.33;     /* 200HP at 2700 RPM, full throttle, sea level */
 /* Adding 33% HP to get right feel */
 pengine[0].spinnerloc.x=1.71;
 pengine[0].spinnerloc.y=0.00;
 pengine[0].spinnerloc.z=0.00;
 pengine[0].radius=0.90; /* m */
 pengine[0].inertimoment= 0.333 * 20/*(?)kg*/ * SQR(pengine[0].radius);
 pengine[0].rpm_omega_high=2*PI*2700.0 /*RPM*/ / 60.0 /*sec*/ / pengine[0].reduct_gear;
 pengine[0].rpm_omega_idle=2*PI*1100.0 /*RPM*/ / 60.0 /*sec*/ / pengine[0].reduct_gear;
 pengine[0].aspect_ratio=20.0;
 pengine[0].curvature=2.0;
 pengine[0].min_pitch= 8*PI/180;
 pengine[0].max_pitch=30*PI/180;
 pengine[0].pitch    =(pengine[0].min_pitch+pengine[0].max_pitch)/2;
 pengine[0].n_blades = 2;
 pengine[0].front_dragcoeff= 0.05;
 pengine[0].top_dragcoeff  = 0.6;
 pengine[0].front_area     = 0.5*0.018*pengine[0].radius;
 pengine[0].top_area       = 0.5*0.15*pengine[0].radius;
 pengine[0].v_inflow       = 0;
 pengine[0].omega_vortex   = 0;
 pengine[0].vortex_gain    = 0.5; /* Fraction of omega_vortex left when it hits the rudder */
 pengine[0].mani_ref_press = 28.0; /* Inches Hg */
 pengine[0].mani_press     = 0;
 pengine[0].mani_max       = 35;
 pengine[0].mani_min       = 10;
 pengine[0].blower_speeds  = 0;
 pengine[0].current_blower_speed = 0;
 pengine[0].fuel_eff       = 1.5;

 /* Nose wheel */
 gear[0].weight=30;
 gear[0].hingepos.x=1.06;
 gear[0].hingepos.y=0;
 gear[0].hingepos.z=-1.18;
 gear[0].length=0.01;
 gear[0].stroke=0.01;
 gear[0].strokepos=0.;
 gear[0].damping=0.10;
 gear[0].down=1;
 gear[0].downrate=0;
 gear[0].steergain=0.30;
 gear[0].brakeeffect=0;
 gear[0].area=0.2*0.5;
 gear[0].dragcoeff=0.5;
 gear[0].spring=40000.; /* newton per meter */
 gear[0].steer=0;
 gear[0].wheel_radius=0.17;
 gear[0].wheel_omega=0;
 gear[0].wheel_moment=0.5*2*SQR(0.66*gear[0].wheel_radius);
 gear[0].skid=false;

 /* Starboard main gear */
 gear[1].weight=40;
 gear[1].hingepos.x=-.51;
 gear[1].hingepos.y=1.1;
 gear[1].hingepos.z=-1.13;
 gear[1].length=0.01;
 gear[1].stroke=0.01;
 gear[1].strokepos=0.;
 gear[1].damping=0.10;
 gear[1].down=1;
 gear[1].downrate=0;
 gear[1].steergain=1;
 gear[1].brakeeffect=0.5;
 gear[1].area=0.2*1.5;
 gear[1].dragcoeff=0.5;
 gear[1].spring=50000.;
 gear[1].steer=0;
 gear[1].wheel_radius=0.21;
 gear[1].wheel_omega=0;
 gear[1].wheel_moment=0.5*4*SQR(0.66*gear[1].wheel_radius);
 gear[1].skid=false;

 /* Port main gear */
 gear[2].weight=40;
 gear[2].hingepos.x=-.51;
 gear[2].hingepos.y=-1.1;
 gear[2].hingepos.z=-1.13;
 gear[2].length=0.01;
 gear[2].stroke=0.01;
 gear[2].strokepos=0.;
 gear[2].damping=0.10;
 gear[2].down=1;
 gear[2].downrate=0;
 gear[2].steergain=1;
 gear[2].brakeeffect=0.5;
 gear[2].area=0.2*1.5;
 gear[2].dragcoeff=0.5;
 gear[2].spring=50000.;
 gear[2].steer=0;
 gear[2].wheel_radius=0.21;
 gear[2].wheel_omega=0;
 gear[2].wheel_moment=0.5*4*SQR(0.66*gear[2].wheel_radius);
 gear[2].skid=false;

 /* Hard contact points - defined as gear */
 /* Tail bumper */
 gear[3].weight=0;
 gear[3].hingepos.x=-4.07;
 gear[3].hingepos.y=0;
 gear[3].hingepos.z=-0.19;
 gear[3].length=0;
 gear[3].stroke=0;
 gear[3].strokepos=0.;
 gear[3].damping=0.05;
 gear[3].down=1;
 gear[3].downrate=0;
 gear[3].steergain=0;
 gear[3].brakeeffect=3;
 gear[3].area=0;
 gear[3].dragcoeff=1;
 gear[3].spring=20000;
 gear[3].steer=0;
 gear[4].skid=false;

 /* Stb. wing tip */
 gear[4].weight=0;
 gear[4].hingepos.x=-0.35;
 gear[4].hingepos.y=4.42;
 gear[4].hingepos.z=0.45;
 gear[4].length=0;
 gear[4].stroke=0;
 gear[4].strokepos=0.;
 gear[4].damping=0.1;
 gear[4].down=1;
 gear[4].downrate=0;
 gear[4].steergain=0;
 gear[4].brakeeffect=2;
 gear[4].area=0;
 gear[4].dragcoeff=0;
 gear[4].spring=20000;
 gear[4].steer=0;
 gear[4].skid=false;

 /* Port ving tip */
 gear[5].weight=0;
 gear[5].hingepos.x=-0.35;
 gear[5].hingepos.y=-4.42;
 gear[5].hingepos.z=0.45;
 gear[5].length=0;
 gear[5].stroke=0;
 gear[5].strokepos=0.;
 gear[5].damping=0.1;
 gear[5].down=1;
 gear[5].downrate=0;
 gear[5].steergain=0;
 gear[5].brakeeffect=2;
 gear[5].area=0;
 gear[5].dragcoeff=0;
 gear[5].spring=20000;
 gear[5].steer=0;
 gear[5].skid=false;

 hook.exists     = false;
 hook.hingepos.x = 0;
 hook.hingepos.y = 0;
 hook.hingepos.z = 0;
 hook.length     = 0;
 hook.down       = 0;
 hook.downrate   = 0;
 hook.deaccel    = 0;

 airbrake.area      = 0;
 airbrake.dragcoeff = 1.0;
 airbrake.out       = 0;
 airbrake.outrate   = 1.0;
 airbrake.pos.x     =-2.0;
 airbrake.pos.y     = 0.0;
 airbrake.pos.z     = 0.0;

 /* Wing tank */
 fueltank[0].pos.x    = 0.30;
 fueltank[0].pos.y    = 1.40;
 fueltank[0].pos.z    = 0.41;
 fueltank[0].capacity =   78;  /* Liter */

 /* Wing tank */
 fueltank[1].pos.x    = 0.30;
 fueltank[1].pos.y    =-1.40;
 fueltank[1].pos.z    = 0.41;
 fueltank[1].capacity =   78;  /* Liter */

 rho_fuel = 0.83; /* JP-5 at 60 deg F */

 flapresponse=5; /* deg/sec */
 flap_cp_travel = -0.3;
 slat_eff = 0;

 nwingsections=4;
 nelements=7;
 njetengines=0;
 npropengines=1;
 nrocketengines= 0;
 ngears=3;
 nhardpts=3;
 nguns=0;
 nfueltanks    = 2;

 pilotpos.x=0.20;
 pilotpos.y=0.25;
 pilotpos.z=0.53;

 show_hud=true;

 ldg_aim_offset  = -2.0; /* meters */
 desired_ldg_spd = 60;   /* KTS */
 desired_ldg_AOA = 5.5;  /* degrees */
 meatball_tilt   = ldg_aim_offset/24.4; /* Distance to meatball */

 controls.elevatorrate = 180; /* degrees/sec */
 controls.aileronrate  = 180;
 controls.rudderrate   = 180;

 stall_angle = 10.0*(PI/180);

 elevator_gain = 1.0;
 aileron_gain  = 1.0;
 rudder_gain   = 1.0;

 elevator_vmax = 150; /* KTS */
 aileron_vmax  = 150; /* KTS */
 rudder_vmax   = 150; /* KTS */

 instrum.max_vv   = 2000; /* ft/min */
 instrum.min_ias  =   30; /* kts */
 instrum.max_ias  =  220; /* kts */
 instrum.max_fuel_flow = 30; /* gal/hr */

 front_superdrag = 3.0;
 left_superdrag  = 5.0;
 top_superdrag   = 5.0;
