/* BA Sea Harrier FRS Mk.1 */

 strcpy(modelname,"BA Sea Harrier FRS Mk.1");

 /* Krop */
 element[0].weight=2400;			/* Kg */
 element[0].topcurvature=0;
 element[0].front.area=2.3*1.9;    		/* m^2 */
 element[0].front.aspect=1;
 element[0].front.dragcoeff=.20;		/* min 0, max 1 */
 element[0].front.masscenter=2.5;       /* foran center for stabilitet */
 element[0].front.liftcenter=-.5;
 element[0].front.dragcenter=-.5;       /* Langt fremme for hover egensk. */
 element[0].front.deflect=0;
 element[0].left.area=1.5*11;
 element[0].left.aspect=0.5;  /* 0.136 */
 element[0].left.dragcoeff=0.5;
 element[0].left.masscenter=0;
 element[0].left.liftcenter=0;
 element[0].left.dragcenter=0;         /* bag massecenter: stabiliserende */
 element[0].left.deflect=0;
 element[0].top.area=1.5*11;
 element[0].top.aspect=0.136;    /* 0.136 */
 element[0].top.dragcoeff=0.5;
 element[0].top.masscenter=-0.1;
 element[0].top.liftcenter=0;
 element[0].top.dragcenter=0;          /* bag massecenter: stabiliserende */
 element[0].top.deflect=0;
 element[0].top.oswald=0.5;

 /* Haleplan */
 element[1].weight=50;			/* Kg */
 element[1].topcurvature=0;
 element[1].front.area=0.05*4.5;
 element[1].front.aspect=20;
 element[1].front.dragcoeff=.12;		/* min 0, max 1 */
 element[1].front.masscenter=-5.8;
 element[1].front.liftcenter=-5.7;
 element[1].front.dragcenter=-5.7;
 element[1].front.deflect=0;
 element[1].left.area=0;    /* 0.05*0.5; */
 element[1].left.aspect=10;
 element[1].left.dragcoeff=0.1;
 element[1].left.masscenter=0;
 element[1].left.liftcenter=0;
 element[1].left.dragcenter=0;
 element[1].left.deflect=0;
 element[1].top.area=4.5*1;
 element[1].top.aspect=4.5;
 element[1].top.dragcoeff=0.6;
 element[1].top.masscenter=0.5;
 element[1].top.liftcenter=0.5;
 element[1].top.dragcenter=0.5;
 element[1].top.deflect=0;
 element[1].top.oswald=0.7;

 /* Halefinne */
 element[2].weight=100;			/* Kg */
 element[2].topcurvature=0;
 element[2].front.area=0.05*1;
 element[2].front.aspect=10;
 element[2].front.dragcoeff=.12;		/* min 0, max 1 */
 element[2].front.masscenter=-5.7;
 element[2].front.liftcenter=-5.6;
 element[2].front.dragcenter=-5.6;
 element[2].front.deflect=0;
 element[2].left.area=1.5*2;
 element[2].left.aspect=1.33;
 element[2].left.dragcoeff=0.6;
 element[2].left.masscenter=0;
 element[2].left.liftcenter=0;
 element[2].left.dragcenter=0;
 element[2].left.deflect=0;
 element[2].top.area=0;     /* 0.05*1; */
 element[2].top.aspect=10;
 element[2].top.dragcoeff=0.1;
 element[2].top.masscenter=1;
 element[2].top.liftcenter=1;
 element[2].top.dragcenter=1;
 element[2].top.deflect=0;
 element[2].top.oswald=0.1;

 /* Styrbord indre vinge */
 element[3].weight=400;			/* Kg */
 element[3].topcurvature=3;
 element[3].front.area=0.2*2;
 element[3].front.aspect=20;
 element[3].front.dragcoeff=.12;		/* min 0, max 1 */
 element[3].front.masscenter=-.75;
 element[3].front.liftcenter=1.4; /* 0.5 */   /* flyttet langt frem for vertikal v */
 element[3].front.dragcenter=0.5;    /* hover egenskaber */
 element[3].front.deflect=0;
 element[3].left.area=0;   /* .1*1; */
 element[3].left.aspect=10;
 element[3].left.dragcoeff=0.1;
 element[3].left.masscenter=1.7;
 element[3].left.liftcenter=1.7;
 element[3].left.dragcenter=1.7;
 element[3].left.deflect=0;
 element[3].top.area=2.7*1.7;
 element[3].top.aspect=2.6;
 element[3].top.dragcoeff=0.6;
 element[3].top.masscenter=0.5;
 element[3].top.liftcenter=0.5;
 element[3].top.dragcenter=0.5;
 element[3].top.deflect=0;
 element[3].top.oswald=1.2;

 /* Bagbord indre vinge */
 element[4].weight=400;			/* Kg */
 element[4].topcurvature=3;
 element[4].front.area=0.2*2;
 element[4].front.aspect=20;
 element[4].front.dragcoeff=.12;		/* min 0, max 1 */
 element[4].front.masscenter=-.75;
 element[4].front.liftcenter=1.4;  /* 0.5 */
 element[4].front.dragcenter=0.5;
 element[4].front.deflect=0;
 element[4].left.area=0;   /* .1*1; */
 element[4].left.aspect=10;
 element[4].left.dragcoeff=0.1;
 element[4].left.masscenter=-1.7;
 element[4].left.liftcenter=-1.7;
 element[4].left.dragcenter=-1.7;
 element[4].left.deflect=0;
 element[4].top.area=2.7*1.7;
 element[4].top.aspect=2.6;
 element[4].top.dragcoeff=0.6;
 element[4].top.masscenter=0.5;
 element[4].top.liftcenter=0.5;
 element[4].top.dragcenter=0.5;
 element[4].top.deflect=0;
 element[4].top.oswald=1.2;

 /* Styrbord ydre vinge */
 element[5].weight=250;
 element[5].topcurvature=3;
 element[5].front.area=0.1*2;
 element[5].front.aspect=20;
 element[5].front.dragcoeff=.12;
 element[5].front.masscenter=-1.0;
 element[5].front.liftcenter=1.0;   /* 0.1 */
 element[5].front.dragcenter=0.1;
 element[5].front.deflect=0;
 element[5].left.area=0;  /* .1*1; */
 element[5].left.aspect=10;
 element[5].left.dragcoeff=0.1;
 element[5].left.masscenter=3.0;
 element[5].left.liftcenter=3.0;
 element[5].left.dragcenter=3.0;
 element[5].left.deflect=0;
 element[5].top.area=2*1.6;
 element[5].top.aspect=2.6;
 element[5].top.dragcoeff=0.6;
 element[5].top.masscenter=0.0;
 element[5].top.liftcenter=0.0;
 element[5].top.dragcenter=0.0;
 element[5].top.deflect=0;
 element[5].top.oswald=0.35;

 /* Bagbord ydre vinge */
 element[6].weight=250;
 element[6].topcurvature=3;
 element[6].front.area=0.1*2;
 element[6].front.aspect=20;
 element[6].front.dragcoeff=.12;
 element[6].front.masscenter=-1.0;
 element[6].front.liftcenter=1.0; /* 0.1 */
 element[6].front.dragcenter=0.1;
 element[6].front.deflect=0;
 element[6].left.area=0;   /* .1*1; */
 element[6].left.aspect=10;
 element[6].left.dragcoeff=0.1;
 element[6].left.masscenter=-3.0;
 element[6].left.liftcenter=-3.0;
 element[6].left.dragcenter=-3.0;
 element[6].left.deflect=0;
 element[6].top.area=2*1.6;
 element[6].top.aspect=2.6;
 element[6].top.dragcoeff=0.6;
 element[6].top.masscenter=0.0;
 element[6].top.liftcenter=0.0;
 element[6].top.dragcenter=0.0;
 element[6].top.deflect=0;
 element[6].top.oswald=0.35;

 /* Jet-engine */
 /* Unused parameters not (yet) defined */
 /* Mass and thrust origins in same point */
 jengine[0].weight=1650;
 jengine[0].front.masscenter=-2.5;
 jengine[0].left.masscenter=0;
 jengine[0].top.masscenter=0;
 jengine[0].throttle=0; /* % */
 jengine[0].rpm=0;        /* % */
 jengine[0].vectoruplim=0;
 jengine[0].vectordnlim=98;
 jengine[0].vectorpos=0;
 jengine[0].vectordesire=0;
 jengine[0].vectorresponse=45;
 jengine[0].egt=500;
 jengine[0].ab_status  =0;
 jengine[0].rpm_response =     5; /* %/sec */
 jengine[0].ab_response  =     0; /* stages / sec */
 jengine[0].idle_rpm     =    65; /* % */
 jengine[0].idle_thrust  =  1000; /* Newton */
 jengine[0].mil_thrust   = 94000; /* Newton  = 12350 pounds */
 jengine[0].ab_stg_thrust=     0; /* Newton  = 1710 pounds / AB stage */
 jengine[0].n_abstages   =     0;
 jengine[0].idle_fflow   =     0.126; /* kg/sec = 1000 lbs/h */
 jengine[0].mil_fflow    =     1.32;  /* kg/sec */
 jengine[0].ab_stg_fflow =     0; /* kg/sec/stage */
 jengine[0].fflw         =     0;
 jengine[0].stall_pitchup   = 30;
 jengine[0].stall_pitchdown = 30;
 jengine[0].stall_yawleft   = 20;
 jengine[0].stall_yawright  = 20;
 jengine[0].inlet_ramp_m0   =  1.0;
 jengine[0].inlet_ramp_slope=  1;
 jengine[0].ignition        =  true;
 jengine[0].compressor_stall=  false;
 /* Simple model */
 jengine[0].response=20;  /* %/sec */
 jengine[0].power=95000.;   /* Newton */


 /* Naese-hjul */
 gear[0].weight=50;
 gear[0].hingepos.x=3;
 gear[0].hingepos.y=0;
 gear[0].hingepos.z=-0.6;
 gear[0].length=1.1;       /* 1.0*/
 gear[0].stroke=0.25;
 gear[0].strokepos=0.;
 gear[0].damping=0.10; /* 0.05 */
 gear[0].down=1;
 gear[0].downrate=0.2;
 gear[0].steergain=0.8;
 gear[0].brakeeffect=0;
 gear[0].area=0.2*1.0;
 gear[0].dragcoeff=1.0;
 gear[0].spring=120000.; /* newton per meter */
 gear[0].steer=0;
 gear[0].wheel_radius=0.26;
 gear[0].wheel_omega=0;
 gear[0].wheel_moment=0.5*4*SQR(0.66*gear[0].wheel_radius);
 gear[0].skid=false;

 /* main gear */
 gear[1].weight=150;
 gear[1].hingepos.x=-1.45;
 gear[1].hingepos.y=0;
 gear[1].hingepos.z=-0.65;
 gear[1].length=0.65;
 gear[1].stroke=0.3;
 gear[1].strokepos=0.;
 gear[1].damping=0.10; /* 0.05 */
 gear[1].down=1;
 gear[1].downrate=0.2;
 gear[1].steergain=1;
 gear[1].brakeeffect=1.0; /* 1.0 */
 gear[1].area=0.2*1.0;
 gear[1].dragcoeff=1.0;
 gear[1].spring=150000.; /* newton per meter */
 gear[1].steer=0;
 gear[1].wheel_radius=0.33;
 gear[1].wheel_omega=0;
 gear[1].wheel_moment=0.5*10*SQR(0.66*gear[1].wheel_radius);
 gear[1].skid=false;

 /* Port strut gear */
 gear[2].weight=50;
 gear[2].hingepos.x=-1.95;
 gear[2].hingepos.y=-3.5;
 gear[2].hingepos.z=-0.30;
 gear[2].length=0.85;
 gear[2].stroke=0.1;
 gear[2].strokepos=0.0;
 gear[2].damping=0.10;   /* 0.0 */
 gear[2].down=1;
 gear[2].downrate=0.3;
 gear[2].steergain=1;
 gear[2].brakeeffect=0; /* 0 */
 gear[2].area=0.2*1.5;
 gear[2].dragcoeff=1.0;
 gear[2].spring=150000.; /* newton per meter */
 gear[2].steer=0;
 gear[2].wheel_radius=0.18;
 gear[2].wheel_omega=0;
 gear[2].wheel_moment=0.5*2*SQR(0.66*gear[2].wheel_radius);
 gear[2].skid=false;

 /* Stb. strut gear */
 gear[3].weight=50;
 gear[3].hingepos.x=-1.95;
 gear[3].hingepos.y= 3.5;
 gear[3].hingepos.z=-0.30;
 gear[3].length=0.85;
 gear[3].stroke=0.1;
 gear[3].strokepos=0.0;
 gear[3].damping=0.15; /* 0.01 */
 gear[3].down=1;
 gear[3].downrate=0.3;
 gear[3].steergain=1;
 gear[3].brakeeffect=0; /* 0 */
 gear[3].area=0.2*1.5;
 gear[3].dragcoeff=1.0;
 gear[3].spring=150000.; /* newton per meter */
 gear[3].steer=0;
 gear[3].wheel_radius=0.18;
 gear[3].wheel_omega=0;
 gear[3].wheel_moment=0.5*2*SQR(gear[3].wheel_radius);
 gear[3].skid=false;

 /* Naese hardpt */
 gear[4].weight=0;
 gear[4].hingepos.x=5.7;
 gear[4].hingepos.y=0;
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
 gear[4].dragcoeff=1;
 gear[4].spring=200000.; /* newton per meter */
 gear[4].steer=0;
 gear[4].skid=false;

 /* Hale hardpt */
 gear[5].weight=0;
 gear[5].hingepos.x=-5.8;
 gear[5].hingepos.y=0;
 gear[5].hingepos.z=-0.5;
 gear[5].length=0;
 gear[5].stroke=0;
 gear[5].strokepos=0.;
 gear[5].damping=0.1;
 gear[5].down=1;
 gear[5].downrate=0;
 gear[5].steergain=0;
 gear[5].brakeeffect=0.75;
 gear[5].area=0;
 gear[5].dragcoeff=0;
 gear[5].spring=200000.; /* newton per meter */
 gear[5].steer=0;
 gear[5].skid=false;

 /* Gun pod */
 gear[6].weight=0;
 gear[6].hingepos.x= 0.24;
 gear[6].hingepos.y= 0.51;
 gear[6].hingepos.z=-1.05;
 gear[6].length=0;
 gear[6].stroke=0;
 gear[6].strokepos=0.;
 gear[6].damping=0.1;
 gear[6].down=1;
 gear[6].downrate=0;
 gear[6].steergain=0;
 gear[6].brakeeffect=.75;
 gear[6].area=0;
 gear[6].dragcoeff=0;
 gear[6].spring=200000.; /* newton per meter */
 gear[6].steer=0;
 gear[6].skid=false;

 /* gun pod */
 gear[7].weight=0;
 gear[7].hingepos.x= 0.24;
 gear[7].hingepos.y=-0.51;
 gear[7].hingepos.z=-1.05;
 gear[7].length=0;
 gear[7].stroke=0;
 gear[7].strokepos=0.;
 gear[7].damping=0.1;
 gear[7].down=1;
 gear[7].downrate=0;
 gear[7].steergain=0;
 gear[7].brakeeffect=.75;
 gear[7].area=0;
 gear[7].dragcoeff=0;
 gear[7].spring=200000.; /* newton per meter */
 gear[7].steer=0;
 gear[7].skid=false;

 /* wing tip */
 gear[8].weight=0;
 gear[8].hingepos.x=-2.50;
 gear[8].hingepos.y= 3.88;
 gear[8].hingepos.z=-0.43;
 gear[8].length=0;
 gear[8].stroke=0;
 gear[8].strokepos=0.;
 gear[8].damping=0.1;
 gear[8].down=1;
 gear[8].downrate=0;
 gear[8].steergain=0;
 gear[8].brakeeffect=1.;
 gear[8].area=0;
 gear[8].dragcoeff=0;
 gear[8].spring=200000.; /* newton per meter */
 gear[8].steer=0;
 gear[8].skid=false;

 /* wing tip */
 gear[9].weight=0;
 gear[9].hingepos.x=-2.50;
 gear[9].hingepos.y=-3.88;
 gear[9].hingepos.z=-0.43;
 gear[9].length=0;
 gear[9].stroke=0;
 gear[9].strokepos=0.;
 gear[9].damping=0.1;
 gear[9].down=1;
 gear[9].downrate=0;
 gear[9].steergain=0;
 gear[9].brakeeffect=1.;
 gear[9].area=0;
 gear[9].dragcoeff=0;
 gear[9].spring=200000.; /* newton per meter */
 gear[9].steer=0;
 gear[9].skid=false;

 hook.exists     = false;
 hook.hingepos.x = 0;
 hook.hingepos.y = 0;
 hook.hingepos.z = 0;
 hook.length     = 0;
 hook.down       = 0;
 hook.downrate   = 0;
 hook.deaccel    = 0;

 /* Gun data from rec.aviation.military fact page */
 /* Aden 30mm - data extrapolated from Aden 25mm data */
 gun[0].pos.x=1.80;
 gun[0].pos.y=0.49;
 gun[0].pos.z=-0.85;
 gun[0].aim.x=1;
 gun[0].aim.y=0;
 gun[0].aim.z=0;
 gun[0].nrounds        = 130;
 gun[0].muzzle_vel     =1050; /* meter/sec */
 gun[0].fire_rate      =  30.83;     /* per second */
 gun[0].projectile_mass=   0.310; /* kg */
 gun[0].t_last_shot    =   0;
 gun[0].recoil         = 200;      /* Newton/sec */
 gun[0].tracer_freq    =   2;

 gun[1].pos.x=1.80;
 gun[1].pos.y=-0.49;
 gun[1].pos.z=-0.85;
 gun[1].aim.x=1;
 gun[1].aim.y=0;
 gun[1].aim.z=0;
 gun[1].nrounds=130;
 gun[1].muzzle_vel=1050; /* meter/sec */
 gun[1].fire_rate=30.83;     /* per second */
 gun[1].projectile_mass=0.310; /* kg */
 gun[1].t_last_shot=0;
 gun[1].recoil=200;      /* Newton/sec */
 gun[1].tracer_freq = 2;

 airbrake.area      = 0.5;
 airbrake.dragcoeff = 1.0;
 airbrake.out       = 0;
 airbrake.outrate   = 1.0;
 airbrake.pos.x     =-1.7;
 airbrake.pos.y     = 0.0;
 airbrake.pos.z     =-0.8;

 fueltank[0].pos.x    =-0.60;
 fueltank[0].pos.y    = 1.52;
 fueltank[0].pos.z    = 0.38;
 fueltank[0].capacity = 500;  /* Liter */

 fueltank[1].pos.x    =-0.60;
 fueltank[1].pos.y    =-1.52;
 fueltank[1].pos.z    = 0.38;
 fueltank[1].capacity = 500;  /* Liter */

 fueltank[2].pos.x    = 2.00;
 fueltank[2].pos.y    = 0.00;
 fueltank[2].pos.z    = 0.30;
 fueltank[2].capacity = 932;  /* Liter */

 fueltank[3].pos.x    =-2.00;
 fueltank[3].pos.y    = 0.00;
 fueltank[3].pos.z    =-0.30;
 fueltank[3].capacity = 932;  /* Liter */

 rho_fuel = 0.83; /* JP-5 at 60 deg F */

 flapresponse=5; /* deg/sec */
 flap_cp_travel = -1.0;
 slat_eff = 0;

 nwingsections = 0;
 nelements     = 7;
 njetengines   = 1;
 npropengines  = 0;
 nrocketengines= 0;
 ngears        = 4;
 nhardpts      = 6;
 nguns         = 2;
 nfueltanks    = 4;

 pilotpos.x= 3.80;
 pilotpos.y= 0.00;
 pilotpos.z= 0.88;

 show_hud=true;

 ldg_aim_offset  = -2.0; /* meters */
 desired_ldg_spd = 145;   /* KTS */
 desired_ldg_AOA = 6.2; /* degrees */
 meatball_tilt   = ldg_aim_offset/24.4; /* Distance to meatball */

 controls.elevatorrate = 120; /* degrees/sec */
 controls.aileronrate  = 120;
 controls.rudderrate   = 120;

 stall_angle = 15.0*(PI/180);

 elevator_gain = 0.5;
 aileron_gain  = 0.5;
 rudder_gain   = 1.0;

 elevator_vmax = 400; /* KTS */
 aileron_vmax  = 400; /* KTS */
 rudder_vmax   = 400; /* KTS */

 instrum.max_vv = 5000; /* ft/min */
 instrum.min_ias  =   30; /* kts */
 instrum.max_ias  =  700; /* kts */
 instrum.max_fuel_flow = 3000; /* gal/hr */

 front_superdrag = 0.5;
 left_superdrag  = 5.0;
 top_superdrag   = 5.0;
