
 strcpy(modelname,"Lockheed F-104G Starfighter");

 /* Krop, masse lagt fremefter - motor masse bagtil */
 /* Sidevaerts kraefter i seperat element */
 element[0].weight=2500;		  /* 2400 */	/* Kg */
 element[0].topcurvature=0;
 element[0].front.area=1.2*1.4;    		/* m^2 */
 element[0].front.aspect=1;
 element[0].front.dragcoeff=.2;		/* min 0, max 1 */
 element[0].front.masscenter=3.5;   /* foran center for stabilitet */
 element[0].front.liftcenter= 1.0;  /* 1.5 */ /* -0.5 */
 element[0].front.dragcenter= 1.0;  /* 1.5 */ /* -0.5 */
 element[0].front.deflect=0;
 element[0].left.area=0;
 element[0].left.aspect=0.5;   /* 0.1 */
 element[0].left.dragcoeff=0.;
 element[0].left.masscenter=0;
 element[0].left.liftcenter=0;
 element[0].left.dragcenter=0;          /* bag massecenter: stabiliserende */
 element[0].left.deflect=0;
 element[0].top.area=1.0*15;
 element[0].top.aspect=0.07;    /* 0.07 */
 element[0].top.dragcoeff=0.5;
 element[0].top.masscenter=0.1;
 element[0].top.liftcenter=0.1;
 element[0].top.dragcenter=0.1;         /* bag massecenter: stabiliserende */
 element[0].top.deflect=0;
 element[0].top.oswald=0.5;
 /* Haleplan */
 element[1].weight=         100;			 /* Kg */
 element[1].topcurvature=     0;
 element[1].front.area=       0.05*3.30;
 element[1].front.aspect=    30;
 element[1].front.dragcoeff=  0.1;		 /* min 0, max 1 */
 element[1].front.masscenter=-6.7;
 element[1].front.liftcenter=-6.5;
 element[1].front.dragcenter=-6.5;
 element[1].front.deflect=    0;
 element[1].left.area=        0.05*1.4;
 element[1].left.aspect=     10;
 element[1].left.dragcoeff=   0.1;
 element[1].left.masscenter=  0;
 element[1].left.liftcenter=  0;
 element[1].left.dragcenter=  0;
 element[1].left.deflect=     0;
 element[1].top.area=         4.7;  /* 3.3*1 */ /* 4.70 correct value */
 element[1].top.aspect=       3.3;  /* 3.3   */
 element[1].top.dragcoeff=    0.6;  /* 0.6   */
 element[1].top.masscenter=   2.35;
 element[1].top.liftcenter=   2.35;
 element[1].top.dragcenter=   2.35;
 element[1].top.deflect=      0;
 element[1].top.oswald=0.7;

 /* Halefinne */
 element[2].weight=200;			/* Kg */
 element[2].topcurvature=0;
 element[2].front.area=0.05*1.4;
 element[2].front.aspect=20;
 element[2].front.dragcoeff=.1;		/* min 0, max 1 */
 element[2].front.masscenter=-6;
 element[2].front.liftcenter=-5.9;
 element[2].front.dragcenter=-5.9;
 element[2].front.deflect=0;
 element[2].left.area=2.6*1.5;
 element[2].left.aspect=0.6;
 element[2].left.dragcoeff=0.6;
 element[2].left.masscenter=0;
 element[2].left.liftcenter=0;
 element[2].left.dragcenter=0;
 element[2].left.deflect=0;
 element[2].top.area=0.05*1.4;
 element[2].top.aspect=20;
 element[2].top.dragcoeff=0.1;
 element[2].top.masscenter=1.7;
 element[2].top.liftcenter=1.0;  /* 1.7 */ /* Lowered to decrease roll moment */
 element[2].top.dragcenter=1.0;  /* 1.7 */
 element[2].top.deflect=0;
 element[2].top.oswald=0.1;

 /* Styrbord indre vinge */
 element[3].weight=450;			/* Kg */
 element[3].topcurvature=3;
 element[3].front.area=0.05*1.45;
 element[3].front.aspect=20;
 element[3].front.dragcoeff=.1;		/* min 0, max 1 */
 element[3].front.masscenter=-1.0;
 element[3].front.liftcenter= 1.2;  /* -0.8 */  /* -2.3 for neutral */
 element[3].front.dragcenter= 1.2;  /* -0.8 */
 element[3].front.deflect=0;
 element[3].left.area=0;   /* .1*1; */
 element[3].left.aspect=10;
 element[3].left.dragcoeff=0.1;
 element[3].left.masscenter=1.7;
 element[3].left.liftcenter=1.7;
 element[3].left.dragcenter=1.7;
 element[3].left.deflect=0;
 element[3].top.area=2.55*1.45;
 element[3].top.aspect=2.1;
 element[3].top.dragcoeff=0.6;
 element[3].top.masscenter=-0.2;
 element[3].top.liftcenter=-0.2;
 element[3].top.dragcenter=-0.2;
 element[3].top.deflect=0;
 element[3].top.oswald=1.2;

 /* Bagbord indre vinge */
 element[4].weight=450;			/* Kg */
 element[4].topcurvature=3;
 element[4].front.area=0.05*1.45;
 element[4].front.aspect=20;
 element[4].front.dragcoeff=.1;		/* min 0, max 1 */
 element[4].front.masscenter=-1.0;
 element[4].front.liftcenter= 1.2;  /* -0.8 */
 element[4].front.dragcenter= 1.2; /* -0.8 */
 element[4].front.deflect=0;
 element[4].left.area=0;   /* .1*1; */
 element[4].left.aspect=10;
 element[4].left.dragcoeff=0.1;
 element[4].left.masscenter=-1.7;
 element[4].left.liftcenter=-1.7;
 element[4].left.dragcenter=-1.7;
 element[4].left.deflect=0;
 element[4].top.area=2.55*1.45;
 element[4].top.aspect=2.1;
 element[4].top.dragcoeff=0.6;
 element[4].top.masscenter=-0.2;
 element[4].top.liftcenter=-0.2;
 element[4].top.dragcenter=-0.2;
 element[4].top.deflect=0;
 element[4].top.oswald=1.2;

 /* Styrbord ydre vinge */
 element[5].weight=200;
 element[5].topcurvature=3;
 element[5].front.area=0.05*0.9;
 element[5].front.aspect=20;
 element[5].front.dragcoeff=.1;
 element[5].front.masscenter=-1.0;
 element[5].front.liftcenter= 1.2;  /* -0.8 */
 element[5].front.dragcenter= 1.2;  /* -0.8 */
 element[5].front.deflect=0;
 element[5].left.area=.1*1.7;
 element[5].left.aspect=20;
 element[5].left.dragcoeff=0.1;
 element[5].left.masscenter=2.85;
 element[5].left.liftcenter=2.85;
 element[5].left.dragcenter=2.85;
 element[5].left.deflect=0;
 element[5].top.area=0.9*1.8;
 element[5].top.aspect=2.1;
 element[5].top.dragcoeff=0.6;
 element[5].top.masscenter=-0.4;
 element[5].top.liftcenter=-0.4;
 element[5].top.dragcenter=-0.4;
 element[5].top.deflect=0;
 element[5].top.oswald=0.35;

 /* Bagbord ydre vinge */
 element[6].weight=200;
 element[6].topcurvature=3;
 element[6].front.area=0.05*0.9;
 element[6].front.aspect=20;
 element[6].front.dragcoeff=.1;
 element[6].front.masscenter=-1.0;
 element[6].front.liftcenter= 1.2;   /* -0.8 */
 element[6].front.dragcenter= 1.2;   /* -0.8 */
 element[6].front.deflect=0;
 element[6].left.area=0.1*1.7;
 element[6].left.aspect=20;
 element[6].left.dragcoeff=0.1;
 element[6].left.masscenter=-2.85;
 element[6].left.liftcenter=-2.85;
 element[6].left.dragcenter=-2.85;
 element[6].left.deflect=0;
 element[6].top.area=0.9*1.8;
 element[6].top.aspect=2.1;
 element[6].top.dragcoeff=0.6;
 element[6].top.masscenter=-0.4;
 element[6].top.liftcenter=-0.4;
 element[6].top.dragcenter=-0.4;
 element[6].top.deflect=0;
 element[6].top.oswald=0.35;

 /* Krop, kun sidevaerts kraefter */
 element[7].weight=1;		  	/* Kg */
 element[7].topcurvature=0;
 element[7].front.area=0;    		/* m^2 */
 element[7].front.aspect=1;
 element[7].front.dragcoeff=0;		/* min 0, max 1 */
 element[7].front.masscenter=3.5;   /* foran center for stabilitet */
 element[7].front.liftcenter=-0.3;  /* -0.1 */ /* -0.5 */
 element[7].front.dragcenter=-0.3;  /* -0.1 */ /* -0.5 */
 element[7].front.deflect=0;
 element[7].left.area=1.4*15;
 element[7].left.aspect=0.5;   /* 0.1 */
 element[7].left.dragcoeff=0.5;
 element[7].left.masscenter=0;
 element[7].left.liftcenter=0;
 element[7].left.dragcenter=0;          /* bag massecenter: stabiliserende */
 element[7].left.deflect=0;
 element[7].top.area=0;
 element[7].top.aspect=0.07;    /* 0.07 */
 element[7].top.dragcoeff=0.;
 element[7].top.masscenter=0.1;
 element[7].top.liftcenter=0.1;
 element[7].top.dragcenter=0.1;         /* bag massecenter: stabiliserende */
 element[7].top.deflect=0;
 element[7].top.oswald=0.5;

 /* Jet-engine */
 /* Mass and thrust origins in same point */
 jengine[0].weight=1800;             /* 1900 */
 jengine[0].front.masscenter=-4.17;
 jengine[0].left.masscenter=0;
 jengine[0].top.masscenter=0.2;
 jengine[0].throttle=0; /* % */
 jengine[0].rpm=0;        /* % */
 jengine[0].vectoruplim=0;
 jengine[0].vectordnlim=0;
 jengine[0].vectorpos=0;
 jengine[0].vectordesire=0;
 jengine[0].vectorresponse=0;
 jengine[0].egt=500;
 jengine[0].ab_status  =0;
 jengine[0].rpm_response =     5; /* %/sec */
 jengine[0].ab_response  =     1.5; /* stages / sec */
 jengine[0].idle_rpm     =    65; /* % */
 jengine[0].idle_thrust  =  1000; /* Newton */
 jengine[0].mil_thrust   = 44400; /* Newton  = 10000 pounds */
 jengine[0].ab_stg_thrust=  8306; /* Newton  / AB stage */
 jengine[0].n_abstages   =     3;
 jengine[0].idle_fflow   =     0.126; /* kg/sec = 1000 lbs/h */
 jengine[0].mil_fflow    =     0.605; /* kg/sec = 4800 lbs/h */
 jengine[0].ab_stg_fflow =     1.109; /* kg/sec = 8800 lbs/stage/h */
 jengine[0].fflw         =     0;
 jengine[0].stall_pitchup   = 30;
 jengine[0].stall_pitchdown = 30;
 jengine[0].stall_yawleft   = 20;
 jengine[0].stall_yawright  = 20;
 jengine[0].inlet_ramp_m0   =  2.5;
 jengine[0].inlet_ramp_slope=  1;
 jengine[0].ignition        =  true;
 jengine[0].compressor_stall=  false;
 /* Simple model */
 jengine[0].response=20;  /* %/sec */
 jengine[0].power=69400.;   /* Newton = 7076 kg full A/B*/

 /* Naese-hjul */
 gear[0].weight=150;
 gear[0].hingepos.x=3.8;
 gear[0].hingepos.y=0;
 gear[0].hingepos.z=-0.6;
 gear[0].length=0.5;
 gear[0].stroke=0.25;
 gear[0].strokepos=0.;
 gear[0].damping=0.10;   /* 0.10 */
 gear[0].down=1;
 gear[0].downrate=0.2;
 gear[0].steergain=0.5;
 gear[0].brakeeffect=0;
 gear[0].area=0.2*1.0;
 gear[0].dragcoeff=1.0;
 gear[0].spring=200000.; /* newton per meter */
 gear[0].steer=0;
 gear[0].wheel_radius=0.19;
 gear[0].wheel_omega=0;
 gear[0].wheel_moment=0.5*4*SQR(0.66*gear[0].wheel_radius);
 gear[0].skid=false;

 /* Port gear */
 gear[1].weight=150;
 gear[1].hingepos.x=-0.7;
 gear[1].hingepos.y=-1.4;
 gear[1].hingepos.z=-0.1;
 gear[1].length=1.2;
 gear[1].stroke=0.3;
 gear[1].strokepos=0.;
 gear[1].damping=0.12;     /* 0.10 */
 gear[1].down=1;
 gear[1].downrate=0.3;
 gear[1].steergain=1;
 gear[1].brakeeffect=0.5;
 gear[1].area=0.2*1.5;
 gear[1].dragcoeff=1.0;
 gear[1].spring=300000.; /* newton per meter */
 gear[1].steer=0;
 gear[1].wheel_radius=0.38;
 gear[1].wheel_omega=0;
 gear[1].wheel_moment=0.5*6*SQR(0.66*gear[1].wheel_radius);
 gear[1].skid=false;

 /* Stb. gear */
 gear[2].weight=150;
 gear[2].hingepos.x=-0.7;
 gear[2].hingepos.y=1.4;
 gear[2].hingepos.z=-0.1;
 gear[2].length=1.2;
 gear[2].stroke=0.3;
 gear[2].strokepos=0.;
 gear[2].damping=0.12;     /* 0.10 */
 gear[2].down=1;
 gear[2].downrate=0.3;
 gear[2].steergain=1;
 gear[2].brakeeffect=0.5;
 gear[2].area=0.2*1.5;
 gear[2].dragcoeff=1.0;
 gear[2].spring=300000.; /* newton per meter */
 gear[2].steer=0;
 gear[2].wheel_radius=0.38;
 gear[2].wheel_omega=0;
 gear[2].wheel_moment=0.5*6*SQR(0.66*gear[2].wheel_radius);
 gear[2].skid=false;

 /* Halespids hardpoint */
 gear[3].weight=0;
 gear[3].hingepos.x=-6.8;
 gear[3].hingepos.y=0;
 gear[3].hingepos.z=-0.2;
 gear[3].length=0;
 gear[3].stroke=0;
 gear[3].strokepos=0.;
 gear[3].damping=0.1;
 gear[3].down=1;
 gear[3].downrate=0;
 gear[3].steergain=0;
 gear[3].brakeeffect=1;
 gear[3].area=0;
 gear[3].dragcoeff=0;
 gear[3].spring=300000.; /* newton per meter */
 gear[3].steer=0;
 gear[3].skid=false;

 /* Stb. vingetip */
 gear[4].weight=0;
 gear[4].hingepos.x=-1;
 gear[4].hingepos.y=2.36;
 gear[4].hingepos.z=-0.4;
 gear[4].length=0;
 gear[4].stroke=0;
 gear[4].strokepos=0.;
 gear[4].damping=0.1;
 gear[4].down=1;
 gear[4].downrate=0;
 gear[4].steergain=0;
 gear[4].brakeeffect=1;
 gear[4].area=0;
 gear[4].dragcoeff=0;
 gear[4].spring=100000.; /* newton per meter */
 gear[4].steer=0;
 gear[4].skid=false;

 /* Bagb. vingetip */
 gear[5].weight=0;
 gear[5].hingepos.x=-1;
 gear[5].hingepos.y=-2.36;
 gear[5].hingepos.z=-0.4;
 gear[5].length=0;
 gear[5].stroke=0;
 gear[5].strokepos=0.;
 gear[5].damping=0.1;
 gear[5].down=1;
 gear[5].downrate=0;
 gear[5].steergain=0;
 gear[5].brakeeffect=1;
 gear[5].area=0;
 gear[5].dragcoeff=0;
 gear[5].spring=100000.; /* newton per meter */
 gear[5].steer=0;
 gear[5].skid=false;

 gear[6].weight=0;
 gear[6].hingepos.x= 7.28;
 gear[6].hingepos.y= 0.;
 gear[6].hingepos.z=-0.44;
 gear[6].length=0;
 gear[6].stroke=0;
 gear[6].strokepos=0.;
 gear[6].damping=0.1;
 gear[6].down=1;
 gear[6].downrate=0;
 gear[6].steergain=0;
 gear[6].brakeeffect=1;
 gear[6].area=0;
 gear[6].dragcoeff=0;
 gear[6].spring=300000.; /* newton per meter */
 gear[6].steer=0;
 gear[6].skid=false;

 gear[7].weight=0;
 gear[7].hingepos.x=-3.22;
 gear[7].hingepos.y= 0.;
 gear[7].hingepos.z=-0.7;
 gear[7].length=0;
 gear[7].stroke=0;
 gear[7].strokepos=0.;
 gear[7].damping=0.1;
 gear[7].down=1;
 gear[7].downrate=0;
 gear[7].steergain=0;
 gear[7].brakeeffect=1;
 gear[7].area=0;
 gear[7].dragcoeff=0;
 gear[7].spring=300000.; /* newton per meter */
 gear[7].steer=0;
 gear[7].skid=false;


 hook.exists     = true;
 hook.hingepos.x = -2.8;
 hook.hingepos.y =  0;
 hook.hingepos.z = -0.70;
 hook.length     =  1.50;
 hook.down       =  0;
 hook.downrate   =  0.5;
 hook.deaccel    =  3.5;

 /* Gun data from rec.aviation.military fact page */
 /* GE M61 */
 gun[0].pos.x=5.28;
 gun[0].pos.y=0.49;
 gun[0].pos.z=-0.28;
 gun[0].aim.x=1;
 gun[0].aim.y=0;
 gun[0].aim.z=0;
 gun[0].nrounds=725;
 gun[0].muzzle_vel=1036; /* meter/sec */
 gun[0].fire_rate=100;     /* per second */
 gun[0].projectile_mass=0.098; /* kg */
 gun[0].t_last_shot=0;
 gun[0].recoil=150;      /* Newton/sec */
 gun[0].tracer_freq=3;

 airbrake.area      = 1.0;
 airbrake.dragcoeff = 1.0;
 airbrake.out       = 0;
 airbrake.outrate   = 1.0;
 airbrake.pos.x     =-4.0;
 airbrake.pos.y     = 0.0;
 airbrake.pos.z     = 0.1;

 /* Body fuel tank, split in four sections */
 fueltank[0].pos.x    = 2.60;
 fueltank[0].pos.y    = 0.00;
 fueltank[0].pos.z    = 0.35;
 fueltank[0].capacity =  963;  /* Liter */

 fueltank[1].pos.x    = 0.20;
 fueltank[1].pos.y    = 0.00;
 fueltank[1].pos.z    = 0.35;
 fueltank[1].capacity =  963;  /* Liter */

 fueltank[2].pos.x    = 2.60;
 fueltank[2].pos.y    = 0.00;
 fueltank[2].pos.z    =-0.35;
 fueltank[2].capacity =  963;  /* Liter */

 fueltank[3].pos.x    = 0.20;
 fueltank[3].pos.y    = 0.00;
 fueltank[3].pos.z    =-0.35;
 fueltank[3].capacity =  963;  /* Liter */

 rho_fuel = 0.83; /* JP-5 at 60 deg F */

 flapresponse=5; /* deg/sec */
 flap_cp_travel = -1.0;
 slat_eff = 0;

 nwingsections = 0;
 nelements     = 8;
 njetengines   = 1;
 npropengines  = 0;
 nrocketengines= 0;
 ngears        = 3;
 nhardpts      = 5;
 nguns         = 1;
 nfueltanks    = 4;

 pilotpos.x=5.84;
 pilotpos.y=0;
 pilotpos.z=0.83;

 show_hud=true;

 ldg_aim_offset  =  -1.1; /* meters */
 desired_ldg_spd = 160; /* 170 */  /* KTS */
 desired_ldg_AOA = 9.0;   /* degrees */
 meatball_tilt   = ldg_aim_offset/24.4; /* Distance to meatball */

 controls.elevatorrate = 120; /* degrees/sec */
 controls.aileronrate  = 120;
 controls.rudderrate   = 120;

 stall_angle = 15.0*(PI/180);

 elevator_gain = 0.5;
 aileron_gain  = 0.6;
 rudder_gain   = 0.7;

 elevator_vmax = 500; /* KTS */
 aileron_vmax  = 500; /* KTS */
 rudder_vmax   = 500; /* KTS */

 instrum.max_vv = 5000; /* ft/min */
 instrum.min_ias  =   30; /* kts */
 instrum.max_ias  =  700; /* kts */
 instrum.max_fuel_flow = 3000; /* gal/hr */

 front_superdrag = 0.8;
 left_superdrag  = 5.0;
 top_superdrag   = 5.0;
