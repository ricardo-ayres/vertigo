/* Har en svag lighed med U-2 */

 strcpy(modelname,"Lockheed U-2");

 /* Krop */
 element[0].weight=2300;			/* Kg */
 element[0].topcurvature=0;
 element[0].front.area=1*1;   		/* m^2 */
 element[0].front.aspect=1;
 element[0].front.dragcoeff=.1;		/* min 0, max 1 */
 element[0].front.masscenter=3.5;       /* foran center for stabilitet */
 element[0].front.liftcenter=-3;
 element[0].front.dragcenter=-3;
 element[0].front.deflect=0;
 element[0].left.area=1*14.4;
 element[0].left.aspect=0.5;   /* 0.0694 */
 element[0].left.dragcoeff=0.5;
 element[0].left.masscenter=0;
 element[0].left.liftcenter=0;
 element[0].left.dragcenter=0;         /* bag massecenter: stabiliserende */
 element[0].left.deflect=0;
 element[0].top.area=1.5*14.4;
 element[0].top.aspect=0.104;  /* 0.104 */
 element[0].top.dragcoeff=0.5;
 element[0].top.masscenter=0;
 element[0].top.liftcenter=0;
 element[0].top.dragcenter=0;          /* bag massecenter: stabiliserende */
 element[0].top.deflect=0;
 element[0].top.oswald=0.5;

 /* Haleplan */
 element[1].weight=200;			/* Kg */
 element[1].topcurvature=0;
 element[1].front.area=0.05*6;
 element[1].front.aspect=20;
 element[1].front.dragcoeff=.1;		/* min 0, max 1 */
 element[1].front.masscenter=-6;
 element[1].front.liftcenter=-5.9;
 element[1].front.dragcenter=-5.9;
 element[1].front.deflect=0;
 element[1].left.area=0.05*1.0;
 element[1].left.aspect=10;
 element[1].left.dragcoeff=0.1;
 element[1].left.masscenter=0;
 element[1].left.liftcenter=0;
 element[1].left.dragcenter=0;
 element[1].left.deflect=0;
 element[1].top.area=6*1.;
 element[1].top.aspect=6;
 element[1].top.dragcoeff=0.6;
 element[1].top.masscenter=0.5;
 element[1].top.liftcenter=0.5;
 element[1].top.dragcenter=0.5;
 element[1].top.deflect=0;
 element[1].top.oswald=0.7;

 /* Halefinne */
 element[2].weight=100;			/* Kg */
 element[2].topcurvature=0;
 element[2].front.area=0.05*3;
 element[2].front.aspect=10;
 element[2].front.dragcoeff=.2;		/* min 0, max 1 */
 element[2].front.masscenter=-6;
 element[2].front.liftcenter=-5.9;
 element[2].front.dragcenter=-5.9;
 element[2].front.deflect=0;
 element[2].left.area=2.88*1.44;
 element[2].left.aspect=2.;
 element[2].left.dragcoeff=0.6;
 element[2].left.masscenter=0;
 element[2].left.liftcenter=0;
 element[2].left.dragcenter=0;
 element[2].left.deflect=0;
 element[2].top.area=0.05*1;
 element[2].top.aspect=10;
 element[2].top.dragcoeff=0.1;
 element[2].top.masscenter=1;
 element[2].top.liftcenter=1;
 element[2].top.dragcenter=1;
 element[2].top.deflect=0;
 element[2].top.oswald=0.1;

 /* Styrbord indre vinge */
 element[3].weight=700;			/* Kg */
 element[3].topcurvature=3;
 element[3].front.area=0.3*7.5;
 element[3].front.aspect=20;
 element[3].front.dragcoeff=.2;		/* min 0, max 1 */
 element[3].front.masscenter=-.25;
 element[3].front.liftcenter=0.5;   /* 0. */
 element[3].front.dragcenter=0.5;
 element[3].front.deflect=0;
 element[3].left.area=0;   /* .1*1; */
 element[3].left.aspect=10;
 element[3].left.dragcoeff=0.1;
 element[3].left.masscenter=4.5;
 element[3].left.liftcenter=4.5;
 element[3].left.dragcenter=4.5;
 element[3].left.deflect=0;
 element[3].top.area=2.5*7;
 element[3].top.aspect=12;
 element[3].top.dragcoeff=0.6;
 element[3].top.masscenter=0.;
 element[3].top.liftcenter=0.;
 element[3].top.dragcenter=0.;
 element[3].top.deflect=0;
 element[3].top.oswald=1.2;

 /* Bagbord indre vinge */
 element[4].weight=700;			/* Kg */
 element[4].topcurvature=3;
 element[4].front.area=0.3*7.5;
 element[4].front.aspect=20;
 element[4].front.dragcoeff=.2;		/* min 0, max 1 */
 element[4].front.masscenter=-.25;
 element[4].front.liftcenter=0.5;  /* 0. */
 element[4].front.dragcenter=0.5;
 element[4].front.deflect=0;
 element[4].left.area=0;   /* .1*1; */
 element[4].left.aspect=10;
 element[4].left.dragcoeff=0.1;
 element[4].left.masscenter=-4.5;
 element[4].left.liftcenter=-4.5;
 element[4].left.dragcenter=-4.5;
 element[4].left.deflect=0;
 element[4].top.area=2.5*7;
 element[4].top.aspect=12;
 element[4].top.dragcoeff=0.6;
 element[4].top.masscenter=0.;
 element[4].top.liftcenter=0.;
 element[4].top.dragcenter=0.;
 element[4].top.deflect=0;
 element[4].top.oswald=1.2;

 /* Styrbord ydre vinge */
 element[5].weight=300;
 element[5].topcurvature=3;
 element[5].front.area=0.2*4.3;
 element[5].front.aspect=20;
 element[5].front.dragcoeff=.2;
 element[5].front.masscenter=-.25;
 element[5].front.liftcenter=0.5; /* 0. */
 element[5].front.dragcenter=0.5;
 element[5].front.deflect=0;
 element[5].left.area=0;  /* .1*1; */
 element[5].left.aspect=10;
 element[5].left.dragcoeff=0.1;
 element[5].left.masscenter=10;
 element[5].left.liftcenter=10;
 element[5].left.dragcenter=10;
 element[5].left.deflect=0;
 element[5].top.area=1.3*4.3;
 element[5].top.aspect=8;
 element[5].top.dragcoeff=0.6;
 element[5].top.masscenter=0.;
 element[5].top.liftcenter=0.;
 element[5].top.dragcenter=0.;
 element[5].top.deflect=0;
 element[5].top.oswald=0.35;

 /* Bagbord ydre vinge */
 element[6].weight=300;
 element[6].topcurvature=3;
 element[6].front.area=0.2*4.3;
 element[6].front.aspect=20;
 element[6].front.dragcoeff=.2;
 element[6].front.masscenter=-.25;
 element[6].front.liftcenter=0.5;  /* 0. */
 element[6].front.dragcenter=0.5;
 element[6].front.deflect=0;
 element[6].left.area=0;   /* .1*1; */
 element[6].left.aspect=10;
 element[6].left.dragcoeff=0.1;
 element[6].left.masscenter=-10;
 element[6].left.liftcenter=-10;
 element[6].left.dragcenter=-10;
 element[6].left.deflect=0;
 element[6].top.area=1.3*4.3;
 element[6].top.aspect=8;
 element[6].top.dragcoeff=0.6;
 element[6].top.masscenter=0.;
 element[6].top.liftcenter=0.;
 element[6].top.dragcenter=0.;
 element[6].top.deflect=0;
 element[6].top.oswald=0.35;

 /* Jet-engine */
 /* Unused parameters not (yet) defined */
 /* Mass and thrust origins in same point */
 jengine[0].weight=1200;
 jengine[0].front.masscenter=-4;
 jengine[0].left.masscenter=0;
 jengine[0].top.masscenter=0;
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
 jengine[0].ab_response  =     0; /* stages / sec */
 jengine[0].idle_rpm     =    65; /* % */
 jengine[0].idle_thrust  =  1000; /* Newton */
 jengine[0].mil_thrust   = 69000; /* Newton  = 12350 pounds */
 jengine[0].ab_stg_thrust=     0; /* Newton  = 1710 pounds / AB stage */
 jengine[0].n_abstages   =     0;
 jengine[0].idle_fflow   =     0.126; /* kg/sec = 1000 lbs/h */
 jengine[0].mil_fflow    =     0.966; /* kg/sec */
 jengine[0].ab_stg_fflow =     0; /* kg/sec/stage */
 jengine[0].fflw         =     0;
 jengine[0].stall_pitchup   = 25;
 jengine[0].stall_pitchdown = 25;
 jengine[0].stall_yawleft   = 15;
 jengine[0].stall_yawright  = 15;
 jengine[0].inlet_ramp_m0   =  0.9;
 jengine[0].inlet_ramp_slope=  1;
 jengine[0].ignition        =  true;
 jengine[0].compressor_stall=  false;
 /* Simple model */
 jengine[0].response=20;  /* %/sec */
 jengine[0].power=70000.;   /* Newton */

 /* Main-gear */
 gear[1].weight=150;
 gear[1].hingepos.x=1.0;
 gear[1].hingepos.y=0;
 gear[1].hingepos.z=-0.65;
 gear[1].length=0.65;
 gear[1].stroke=0.25;
 gear[1].strokepos=0.;
 gear[1].damping=0.10; /* 0.05 */
 gear[1].down=1;
 gear[1].downrate=0.2;
 gear[1].steergain=1;
 gear[1].brakeeffect=0.5;
 gear[1].area=0.2*1.0;
 gear[1].dragcoeff=1.0;
 gear[1].spring=300000.; /* newton per meter */
 gear[1].steer=0;
 gear[1].wheel_radius=0.25;
 gear[1].wheel_omega=0;
 gear[1].wheel_moment=0.5*8*SQR(0.66*gear[1].wheel_radius);
 gear[1].skid=false;

 /* Hale-hjul */
 gear[0].weight=50;
 gear[0].hingepos.x=-5.15;
 gear[0].hingepos.y=0;
 gear[0].hingepos.z=-0.5;
 gear[0].length=0.4;
 gear[0].stroke=0.3;
 gear[0].strokepos=0.;
 gear[0].damping=0.10;  /* 0.05 */
 gear[0].down=1;
 gear[0].downrate=0.5;
 gear[0].steergain=-0.25;  /* Negativ: halehjuls-styring */
 gear[0].brakeeffect=0;
 gear[0].area=0.2*0.5;
 gear[0].dragcoeff=1.0;
 gear[0].spring=100000.; /* newton per meter */
 gear[0].steer=0;
 gear[0].wheel_radius=0.10;
 gear[0].wheel_omega=0;
 gear[0].wheel_moment=0.5*1*SQR(0.66*gear[0].wheel_radius);
 gear[0].skid=false;

 /* Hardpoint - defineret som gear */

 /* Halespids */
 gear[2].weight=0;
 gear[2].hingepos.x=-7.57;
 gear[2].hingepos.y=0;
 gear[2].hingepos.z=-0.27;
 gear[2].length=0;
 gear[2].stroke=0;
 gear[2].strokepos=0.;
 gear[2].damping=0.1;
 gear[2].down=1;
 gear[2].downrate=0;
 gear[2].steergain=0;
 gear[2].brakeeffect=0.75;
 gear[2].area=0;
 gear[2].dragcoeff=0;
 gear[2].spring=300000.; /* newton per meter */
 gear[2].steer=0;
 gear[2].skid=false;


 /* Naese */
 gear[3].weight=0;
 gear[3].hingepos.x=6.75;
 gear[3].hingepos.y=0;
 gear[3].hingepos.z=-0.38;
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
 gear[4].hingepos.x=-0.5;
 gear[4].hingepos.y=12.2;
 gear[4].hingepos.z=-0.2;
 gear[4].length=0;
 gear[4].stroke=0;
 gear[4].strokepos=0.;
 gear[4].damping=0.1;
 gear[4].down=1;
 gear[4].downrate=0;
 gear[4].steergain=0;
 gear[4].brakeeffect=1.5;
 gear[4].area=0;
 gear[4].dragcoeff=0;
 gear[4].spring=50000.; /* newton per meter */
 gear[4].steer=0;
 gear[4].skid=false;

 /* Bagb. vingetip */
 gear[5].weight=0;
 gear[5].hingepos.x=-0.5;
 gear[5].hingepos.y=-12.2;
 gear[5].hingepos.z=-0.2;
 gear[5].length=0;
 gear[5].stroke=0;
 gear[5].strokepos=0.;
 gear[5].damping=0.1;
 gear[5].down=1;
 gear[5].downrate=0;
 gear[5].steergain=0;
 gear[5].brakeeffect=1.5;
 gear[5].area=0;
 gear[5].dragcoeff=0;
 gear[5].spring=50000.; /* newton per meter */
 gear[5].steer=0;
 gear[5].skid=false;

 /* Center body */
 gear[6].weight=0;
 gear[6].hingepos.x= 0.0;
 gear[6].hingepos.y= 0.0;
 gear[6].hingepos.z=-0.70;
 gear[6].length=0;
 gear[6].stroke=0;
 gear[6].strokepos=0.;
 gear[6].damping=0.1;
 gear[6].down=1;
 gear[6].downrate=0;
 gear[6].steergain=0;
 gear[6].brakeeffect=0.75;
 gear[6].area=0;
 gear[6].dragcoeff=0;
 gear[6].spring=600000.; /* newton per meter */
 gear[6].steer=0;
 gear[6].skid=false;

 hook.exists     = true;
 hook.hingepos.x = -5.3;
 hook.hingepos.y =  0;
 hook.hingepos.z = -0.5;
 hook.length     =  1.50;
 hook.down       =  0;
 hook.downrate   =  0.5;
 hook.deaccel    =  1.0;

 airbrake.area      = 1.5;
 airbrake.dragcoeff = 1.0;
 airbrake.out       = 0;
 airbrake.outrate   = 0.5;
 airbrake.pos.x     =-3.2;
 airbrake.pos.y     = 0.0;
 airbrake.pos.z     =-0.35;

 /* Outer wing tanks */
 fueltank[0].pos.x    = -0.25;
 fueltank[0].pos.y    = 10.0;
 fueltank[0].pos.z    =  0.0;
 fueltank[0].capacity =  345;  /* Liter */

 fueltank[1].pos.x    = -0.25;
 fueltank[1].pos.y    =-10.0;
 fueltank[1].pos.z    =  0.0;
 fueltank[1].capacity =  345;  /* Liter */

 /* Inner wing tanks */
 fueltank[2].pos.x    =-0.25;
 fueltank[2].pos.y    = 4.5;
 fueltank[2].pos.z    = 0.0;
 fueltank[2].capacity =  800;  /* Liter */

 fueltank[3].pos.x    =-0.25;
 fueltank[3].pos.y    =-4.5;
 fueltank[3].pos.z    = 0.0;
 fueltank[3].capacity =  800;  /* Liter */

 /* Body tanks */
 fueltank[4].pos.x    = 2.5;
 fueltank[4].pos.y    = 0.0;
 fueltank[4].pos.z    = 0.5;
 fueltank[4].capacity = 1300;  /* Liter */

 fueltank[5].pos.x    =-2.5;
 fueltank[5].pos.y    = 0.0;
 fueltank[5].pos.z    =-0.5;
 fueltank[5].capacity = 1300;  /* Liter */

 rho_fuel = 0.83; /* JP-5 at 60 deg F */

 flapresponse=5; /* deg/sec */
 flap_cp_travel = -0.5;
 slat_eff = 0;

 nwingsections=0;
 nelements=7;
 njetengines=1;
 npropengines=0;
 nrocketengines= 0;
 ngears=2;
 nhardpts=5;
 nguns=0;
 nfueltanks    = 6;

 pilotpos.x=4.29;
 pilotpos.y=0.00;
 pilotpos.z=0.68;

 show_hud=true;

 ldg_aim_offset  = -1.5; /* meters */ /*-2.25*/
 desired_ldg_spd = 100; /* 100 */  /* KTS */
 desired_ldg_AOA = 3.3; /* 3.7 */ /* degrees */
 meatball_tilt   = ldg_aim_offset/24.4; /* Distance to meatball */

 controls.elevatorrate = 120; /* degrees/sec */
 controls.aileronrate  = 120;
 controls.rudderrate   = 120;

 stall_angle = 10.0*(PI/180);

 elevator_gain = 0.7;
 aileron_gain  = 0.5;
 rudder_gain   = 0.7;

 elevator_vmax = 200; /* KTS */
 aileron_vmax  = 200; /* KTS */
 rudder_vmax   = 200; /* KTS */

 instrum.max_vv = 5000; /* ft/min */
 instrum.min_ias  =   30; /* kts */
 instrum.max_ias  =  350; /* kts */
 instrum.max_fuel_flow = 3000; /* gal/hr */

 front_superdrag = 3.0;
 left_superdrag  = 5.0;
 top_superdrag   = 5.0;
