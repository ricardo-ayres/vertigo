 strcpy(modelname,"Vought F4U-1 Corsair");

 /* Krop */
 element[0].weight=700; 	// 1100	/* Kg */
 element[0].topcurvature=0;
 element[0].front.area=1.4;    		/* m^2 */
 element[0].front.aspect=1;
 element[0].front.dragcoeff=.4;		/* min 0, max 1 */
 element[0].front.masscenter=1.1;      /* foran center for stabilitet */
 element[0].front.liftcenter=-1.5;
 element[0].front.dragcenter=-2.5;
 element[0].front.deflect=0;
 element[0].left.area=1.3*9.7;
 element[0].left.aspect=0.5;   /* Increased for better sideslip */
 element[0].left.dragcoeff=0.5;
 element[0].left.masscenter=0;
 element[0].left.liftcenter=0;
 element[0].left.dragcenter=0;         /* bag massecenter: stabiliserende */
 element[0].left.deflect=0;
 element[0].top.area=1.2*9.7;
 element[0].top.aspect=0.12;
 element[0].top.dragcoeff=0.5;
 element[0].top.masscenter=0;
 element[0].top.liftcenter=0;
 element[0].top.dragcenter=0;          /* bag massecenter: stabiliserende */
 element[0].top.deflect=0;
 element[0].top.oswald=0.5;

 /* Haleplan */
 element[1].weight=100;	  		/* Kg */
 element[1].topcurvature=0;
 element[1].front.area=0.10*4.85;
 element[1].front.aspect=50;
 element[1].front.dragcoeff=.1;		/* min 0, max 1 */
 element[1].front.masscenter=-6.4;
 element[1].front.liftcenter=-6.3;
 element[1].front.dragcenter=-6.3;
 element[1].front.deflect=0;
 element[1].left.area=0;    /* 0.05*0.5; */
 element[1].left.aspect=10;
 element[1].left.dragcoeff=0.1;
 element[1].left.masscenter=0;
 element[1].left.liftcenter=0;
 element[1].left.dragcenter=0;
 element[1].left.deflect=0;
 element[1].top.area=4.84*0.85;
 element[1].top.aspect=5.7;
 element[1].top.dragcoeff=0.6;
 element[1].top.masscenter=0.4;
 element[1].top.liftcenter=0.4;
 element[1].top.dragcenter=0.4;
 element[1].top.deflect=0;
 element[1].top.oswald=0.7;

 /* Halefinne */
 element[2].weight=100;			/* Kg */
 element[2].topcurvature=0;
 element[2].front.area=0.10*1.7;
 element[2].front.aspect=14.5;
 element[2].front.dragcoeff=.1;		/* min 0, max 1 */
 element[2].front.masscenter=-5.7;
 element[2].front.liftcenter=-5.6;
 element[2].front.dragcenter=-5.6;
 element[2].front.deflect=0;
 element[2].left.area=1.3*1.7;
 element[2].left.aspect=1.2;
 element[2].left.dragcoeff=0.6;
 element[2].left.masscenter=0;
 element[2].left.liftcenter=0;
 element[2].left.dragcenter=0;
 element[2].left.deflect=0;
 element[2].top.area=0;     /* 0.05*1; */
 element[2].top.aspect=10;
 element[2].top.dragcoeff=0.1;
 element[2].top.masscenter=1.3;
 element[2].top.liftcenter=1.3;
 element[2].top.dragcenter=1.3;
 element[2].top.deflect=0;
 element[2].top.oswald=0.1;

 /* Styrbord indre vinge */
 element[3].weight=500;	 		/* Kg */
 element[3].topcurvature=3;
 element[3].front.area=0.35*2.8;
 element[3].front.aspect=20;
 element[3].front.dragcoeff=.08;		/* min 0, max 1 */
 element[3].front.masscenter=-.25;
 element[3].front.liftcenter=0.9;   /* 0.0 */
 element[3].front.dragcenter=0.9;
 element[3].front.deflect=0;
 element[3].left.area=0;   /* .1*1; */
 element[3].left.aspect=10;
 element[3].left.dragcoeff=0.1;
 element[3].left.masscenter=2.18;
 element[3].left.liftcenter=2.18;
 element[3].left.dragcenter=2.18;
 element[3].left.deflect=0;
 element[3].top.area=2.7*2.9;
 element[3].top.aspect=5;
 element[3].top.dragcoeff=0.6;
 element[3].top.masscenter=-0.7;
 element[3].top.liftcenter=-0.7;
 element[3].top.dragcenter=-0.7;
 element[3].top.deflect=0;
 element[3].top.oswald=1.2;

 /* Bagbord indre vinge */
 element[4].weight=500;	  	/* Kg */
 element[4].topcurvature=3;
 element[4].front.area=0.35*2.8;
 element[4].front.aspect=20;
 element[4].front.dragcoeff=.08;		/* min 0, max 1 */
 element[4].front.masscenter=-.25;
 element[4].front.liftcenter=0.9;  /* 0.0 */
 element[4].front.dragcenter=0.9;
 element[4].front.deflect=0;
 element[4].left.area=0;   /* .1*1; */
 element[4].left.aspect=10;
 element[4].left.dragcoeff=0.1;
 element[4].left.masscenter=-2.18;
 element[4].left.liftcenter=-2.18;
 element[4].left.dragcenter=-2.18;
 element[4].left.deflect=0;
 element[4].top.area=2.7*2.9;
 element[4].top.aspect=5;
 element[4].top.dragcoeff=0.6;
 element[4].top.masscenter=-0.7;
 element[4].top.liftcenter=-0.7;
 element[4].top.dragcenter=-0.7;
 element[4].top.deflect=0;
 element[4].top.oswald=1.2;

 /* Styrbord ydre vinge */
 element[5].weight=200;
 element[5].topcurvature=3;
 element[5].front.area=0.2*2.5;
 element[5].front.aspect=20;
 element[5].front.dragcoeff=.08;
 element[5].front.masscenter=-.25;
 element[5].front.liftcenter=0.9; /* 0.0 */
 element[5].front.dragcenter=0.9;
 element[5].front.deflect=0;
 element[5].left.area=0;  /* .1*1; */
 element[5].left.aspect=10;
 element[5].left.dragcoeff=0.1;
 element[5].left.masscenter=4.86;
 element[5].left.liftcenter=4.86;
 element[5].left.dragcenter=4.86;
 element[5].left.deflect=0;
 element[5].top.area=2.5*2.0;
 element[5].top.aspect=5;
 element[5].top.dragcoeff=0.6;
 element[5].top.masscenter=-0.35;
 element[5].top.liftcenter=-0.35;
 element[5].top.dragcenter=-0.35;
 element[5].top.deflect=0;
 element[5].top.oswald=0.35;

 /* Bagbord ydre vinge */
 element[6].weight=200;
 element[6].topcurvature=3;
 element[6].front.area=0.2*2.5;
 element[6].front.aspect=20;
 element[6].front.dragcoeff=.08;
 element[6].front.masscenter=-.25;
 element[6].front.liftcenter=0.9; /* 0.0 */
 element[6].front.dragcenter=0.9;
 element[6].front.deflect=0;
 element[6].left.area=0;   /* .1*1; */
 element[6].left.aspect=10;
 element[6].left.dragcoeff=0.1;
 element[6].left.masscenter=-4.86;
 element[6].left.liftcenter=-4.86;
 element[6].left.dragcenter=-4.86;
 element[6].left.deflect=0;
 element[6].top.area=2.5*2.0;
 element[6].top.aspect=5;
 element[6].top.dragcoeff=0.6;
 element[6].top.masscenter=-0.35;
 element[6].top.liftcenter=-0.35;
 element[6].top.dragcenter=-0.35;
 element[6].top.deflect=0;
 element[6].top.oswald=0.35;

 /* Prop-engine */
 /* Unused parameters not (yet) defined */
 /* Mass and thrust origins in same point */
 pengine[0].weight           = 1700; // 1300
 pengine[0].front.masscenter = 2.1;
 pengine[0].left.masscenter  = 0;
 pengine[0].top.masscenter   = 0;
 pengine[0].throttle         = 100; /* % */
 pengine[0].rpm              = 550; /* revolutions per minute */
 pengine[0].last_rpm=pengine[0].rpm;
 pengine[0].rpm_percent    = 0; /* % */
 pengine[0].response       = 20;  /* %/sec */
 pengine[0].power          = 15000;   /* Newton */
 pengine[0].reduct_gear    = 2.0;
 pengine[0].torque         = 10400; /* 2000 HP at 1350 RPM, full throttle, sea level */
 pengine[0].spinnerloc.x   = 2.77;
 pengine[0].spinnerloc.y   = 0.00;
 pengine[0].spinnerloc.z   = 0.00;
 pengine[0].radius         = 1.98; /* m */
 pengine[0].inertimoment   = 0.333 * 45/*(?)kg*/ * SQR(pengine[0].radius); /* 50 kg in 0.17 */
 pengine[0].rpm_omega_high = 2*PI*2700.0 /*RPM*/ / 60.0 /*sec*/ / pengine[0].reduct_gear;
 pengine[0].rpm_omega_idle = 2*PI*1100.0 /*RPM*/ / 60.0 /*sec*/ / pengine[0].reduct_gear;
 pengine[0].aspect_ratio   =  4.0;  /* 20.0 */
 pengine[0].curvature      =  2.0;
 pengine[0].min_pitch      = 12.0*PI/180;  /*  5 */
 pengine[0].max_pitch      = 54.0*PI/180;  /* 25 */
 pengine[0].pitch          = (pengine[0].min_pitch+pengine[0].max_pitch)/2;
 pengine[0].n_blades       = 3;
 pengine[0].front_dragcoeff= 0.05;
 pengine[0].top_dragcoeff  = 0.6;
 pengine[0].front_area     = 0.5*0.024*pengine[0].radius;
 pengine[0].top_area       = 0.5*0.4*pengine[0].radius; /* 0.5*0.4* */ /* Large to avoid stalling */
 pengine[0].v_inflow       = 0;
 pengine[0].omega_vortex   = 0;
 pengine[0].vortex_gain    =  0.5; /* Fraction of omega_vortex left when it hits the rudder */
 pengine[0].mani_ref_press = 54.0; /* Inches Hg */
 pengine[0].mani_press     =  0;
 pengine[0].mani_max       = 75;
 pengine[0].mani_min       = 10;
 pengine[0].blower_speeds  =  2;
 pengine[0].current_blower_speed = 0;
 pengine[0].blower_alt[0]  = 8000*.3048;
 pengine[0].blower_fak[0]  =    1.297;
 pengine[0].blower_alt[1]  =13000*.3048;
 pengine[0].blower_fak[1]  =    1.526;
 pengine[0].fuel_eff       =  0.90;

 /* Hale-hjul */
 gear[0].weight=50;
 gear[0].hingepos.x=-5.6;
 gear[0].hingepos.y=0;
 gear[0].hingepos.z=-0.15;
 gear[0].length=0.5;
 gear[0].stroke=0.2;
 gear[0].strokepos=0.;
 gear[0].damping=0.10; /* 0.05 */
 gear[0].down=1;
 gear[0].downrate=0.25;
 gear[0].steergain=-1.2;
 gear[0].brakeeffect=0;
 gear[0].area=0.2*0.5;
 gear[0].dragcoeff=1.0;
 gear[0].spring=30000.; /* newton per meter */
 gear[0].steer=0;
 gear[0].wheel_radius=0.13;
 gear[0].wheel_omega=0;
 gear[0].wheel_moment=0.5*2*SQR(0.66*gear[0].wheel_radius);
 gear[0].skid=false;

 /* Starboard main gear */
 gear[1].weight=100;
 gear[1].hingepos.x=0.75;
 gear[1].hingepos.y=1.8;
 gear[1].hingepos.z=-0.85;
 gear[1].length=1;
 gear[1].stroke=0.4;
 gear[1].strokepos=0.;
 gear[1].damping=0.10; /* 0.05 */
 gear[1].down=1;
 gear[1].downrate=0.2;
 gear[1].steergain=1;
 gear[1].brakeeffect=0.35;
 gear[1].area=0.3*1.5;    /* Large front area */
 gear[1].dragcoeff=1.0;
 gear[1].spring=150000.; /* newton per meter */
 gear[1].steer= 4.;       /* Must be slightly positive */
 gear[1].wheel_radius=0.40;
 gear[1].wheel_omega=0;
 gear[1].wheel_moment=0.5*10*SQR(0.66*gear[1].wheel_radius);
 gear[1].skid=false;

 /* Port main gear */
 gear[2].weight=100;
 gear[2].hingepos.x=0.75;
 gear[2].hingepos.y=-1.8;
 gear[2].hingepos.z=-0.85;
 gear[2].length=1;
 gear[2].stroke=0.4;
 gear[2].strokepos=0.;
 gear[2].damping=0.10; /* 0.05 */
 gear[2].down=1;
 gear[2].downrate=0.2;
 gear[2].steergain=1;
 gear[2].brakeeffect=0.35;
 gear[2].area=0.3*1.5;
 gear[2].dragcoeff=1.0;
 gear[2].spring=150000.; /* newton per meter */
 gear[2].steer=-4.;      /* Must be slightly negative */
 gear[2].wheel_radius=0.40;
 gear[2].wheel_omega=0;
 gear[2].wheel_moment=0.5*10*SQR(0.66*gear[2].wheel_radius);
 gear[2].skid=false;

 /* Hardpoint - defineret som gear */
 /* Naese */
 gear[3].weight=0;
 gear[3].hingepos.x=2.55;
 gear[3].hingepos.y=0;
 gear[3].hingepos.z=-0.7;
 gear[3].length=0;
 gear[3].stroke=0;
 gear[3].strokepos=0.;
 gear[3].damping=0.1;
 gear[3].down=1;
 gear[3].downrate=0;
 gear[3].steergain=0;
 gear[3].brakeeffect=2;
 gear[3].area=0;
 gear[3].dragcoeff=0;
 gear[3].spring=200000.; /* newton per meter */
 gear[3].steer=0;
 gear[3].skid=false;

 /* Stb. vingetip forkant */
 gear[4].weight=0;
 gear[4].hingepos.x=0.;
 gear[4].hingepos.y=6.2;
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
 gear[4].spring=20000; /* newton per meter */
 gear[4].steer=0;
 gear[4].skid=false;

 /* Bagb. vingetip forkant */
 gear[5].weight=0;
 gear[5].hingepos.x=0.;
 gear[5].hingepos.y=-6.2;
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
 gear[5].spring=20000; /* newton per meter */
 gear[5].steer=0;
 gear[5].skid=false;

 /* inboard wing */
 gear[6].weight=0;
 gear[6].hingepos.x= 0.87;
 gear[6].hingepos.y= 1.94;
 gear[6].hingepos.z=-0.85;
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
 gear[6].spring=100000; /* newton per meter */
 gear[6].steer=0;
 gear[6].skid=false;

 /* inboard wing */
 gear[7].weight=0;
 gear[7].hingepos.x= 0.87;
 gear[7].hingepos.y=-1.94;
 gear[7].hingepos.z=-0.85;
 gear[7].length=0;
 gear[7].stroke=0;
 gear[7].strokepos=0.;
 gear[7].damping=0.1;
 gear[7].down=1;
 gear[7].downrate=0;
 gear[7].steergain=0;
 gear[7].brakeeffect=0.75;
 gear[7].area=0;
 gear[7].dragcoeff=0;
 gear[7].spring=100000; /* newton per meter */
 gear[7].steer=0;
 gear[7].skid=false;

 /* Tail */
 gear[8].weight=0;
 gear[8].hingepos.x=-7.45;
 gear[8].hingepos.y=0.;
 gear[8].hingepos.z=0.12;
 gear[8].length=0;
 gear[8].stroke=0;
 gear[8].strokepos=0.;
 gear[8].damping=0.1;
 gear[8].down=1;
 gear[8].downrate=0;
 gear[8].steergain=0;
 gear[8].brakeeffect=0.75;
 gear[8].area=0;
 gear[8].dragcoeff=0;
 gear[8].spring=50000; /* newton per meter */
 gear[8].steer=0;
 gear[8].skid=false;


 hook.exists     = true;
 hook.hingepos.x = -5.6;
 hook.hingepos.y =  0;
 hook.hingepos.z = -0.15;
 hook.length     =  1.60;
 hook.down       =  0;
 hook.downrate   =  0.5;
 hook.deaccel    =  1.0;

 /* 0.50 inch Colt-browning M-2 machine gun */
 /* Data from Robert L. Shaw: Fighter Combat, table 1-1 */
 /* Own measurement of projectile mass consistent with table. */
 gun[0].pos.x=0.78;
 gun[0].pos.y=2.38;
 gun[0].pos.z=-0.70;
 gun[0].aim.x=1;
 gun[0].aim.y=-.009;
 gun[0].aim.z=0;
 gun[0].nrounds=400;
 gun[0].muzzle_vel=856; /* meter/sec */
 gun[0].fire_rate=13.2;     /* per second */
 gun[0].projectile_mass=0.044; /* kg */
 gun[0].t_last_shot=0;
 gun[0].recoil=100;      /* Newton/sec */
 gun[0].tracer_freq=2;

 gun[1].pos.x=0.78;
 gun[1].pos.y=2.58;
 gun[1].pos.z=-0.68;
 gun[1].aim.x=1;
 gun[1].aim.y=-.009;
 gun[1].aim.z=0;
 gun[1].nrounds=400;
 gun[1].muzzle_vel=856; /* meter/sec */
 gun[1].fire_rate=13.3;     /* per second */
 gun[1].projectile_mass=0.044; /* kg */
 gun[1].t_last_shot=0;
 gun[1].recoil=100;      /* Newton/sec */
 gun[1].tracer_freq=2;

 gun[2].pos.x=0.78;
 gun[2].pos.y=2.78;
 gun[2].pos.z=-0.66;
 gun[2].aim.x=1;
 gun[2].aim.y=-.009;
 gun[2].aim.z=0;
 gun[2].nrounds=375;
 gun[2].muzzle_vel=856; /* meter/sec */
 gun[2].fire_rate=13.4;     /* per second */
 gun[2].projectile_mass=0.044; /* kg */
 gun[2].t_last_shot=0;
 gun[2].recoil=100;      /* Newton/sec */
 gun[2].tracer_freq=2;

 gun[3].pos.x=0.78;
 gun[3].pos.y=-2.38;
 gun[3].pos.z=-0.70;
 gun[3].aim.x=1;
 gun[3].aim.y= .009;
 gun[3].aim.z=0;
 gun[3].nrounds=400;
 gun[3].muzzle_vel=856; /* meter/sec */
 gun[3].fire_rate=13.25;     /* per second */
 gun[3].projectile_mass=0.044; /* kg */
 gun[3].t_last_shot=0;
 gun[3].recoil=100;      /* Newton/sec */
 gun[3].tracer_freq=2;

 gun[4].pos.x=0.78;
 gun[4].pos.y=-2.58;
 gun[4].pos.z=-0.68;
 gun[4].aim.x=1;
 gun[4].aim.y= .009;
 gun[4].aim.z=0;
 gun[4].nrounds=400;
 gun[4].muzzle_vel=856; /* meter/sec */
 gun[4].fire_rate=13.35;     /* per second */
 gun[4].projectile_mass=0.044; /* kg */
 gun[4].t_last_shot=0;
 gun[4].recoil=100;      /* Newton/sec */
 gun[4].tracer_freq=2;

 gun[5].pos.x=0.78;
 gun[5].pos.y=-2.78;
 gun[5].pos.z=-0.66;
 gun[5].aim.x=1;
 gun[5].aim.y= .009;
 gun[5].aim.z=0;
 gun[5].nrounds=375;
 gun[5].muzzle_vel=856; /* meter/sec */
 gun[5].fire_rate=13.3;     /* per second */
 gun[5].projectile_mass=0.044; /* kg (measured by me)*/
 gun[5].t_last_shot=0;
 gun[5].recoil=100;      /* Newton/sec */
 gun[5].tracer_freq=2;

 airbrake.area      = 0;
 airbrake.dragcoeff = 1.0;
 airbrake.out       = 0;
 airbrake.outrate   = 1.0;
 airbrake.pos.x     =-2.0;
 airbrake.pos.y     = 0.0;
 airbrake.pos.z     = 0.0;

 /* Wing tip leading edge tank */
 fueltank[0].pos.x    = 0.30;
 fueltank[0].pos.y    = 4.10;
 fueltank[0].pos.z    =-0.50;
 fueltank[0].capacity =  235;  /* Liter */

 /* Wing tip leading edge tank */
 fueltank[1].pos.x    = 0.30;
 fueltank[1].pos.y    =-4.10;
 fueltank[1].pos.z    =-0.50;
 fueltank[1].capacity =  235;  /* Liter */

 /* Fuselage main tank, split in two */
 fueltank[2].pos.x    =-0.40;
 fueltank[2].pos.y    = 0.30;
 fueltank[2].pos.z    = 0.20;
 fueltank[2].capacity =  448.5;  /* Liter */

 /* Fuselage main tank, split in two */
 fueltank[3].pos.x    =-0.40;
 fueltank[3].pos.y    =-0.30;
 fueltank[3].pos.z    = 0.20;
 fueltank[3].capacity =  448.5;  /* Liter */

 rho_fuel = 0.83; /* JP-5 at 60 deg F */

 flapresponse=5; /* deg/sec */
 flap_cp_travel = -0.5;
 slat_eff = 0;

 nwingsections = 0;
 nelements     = 7;
 njetengines   = 0;
 npropengines  = 1;
 nrocketengines= 0;
 ngears        = 3;
 nhardpts      = 6;
 nguns         = 6;
 nfueltanks    = 4;

 pilotpos.x=-1.6;
 pilotpos.y=0;
 pilotpos.z=1.0;

 show_hud=false;

 ldg_aim_offset  = -1.75; /* meters */
 desired_ldg_spd = 85;  /* 90 */ /* KTS */
 desired_ldg_AOA = 6.0; /* 5.0 */ /* degrees */
 meatball_tilt   = ldg_aim_offset/24.4; /* Distance to meatball */

 controls.elevatorrate = 180; /* degrees/sec */
 controls.aileronrate  = 180;
 controls.rudderrate   = 180;

 stall_angle = 12.0*(PI/180);

 elevator_gain = 0.8;
 aileron_gain  = 0.75;
 rudder_gain   = 1.5;

 elevator_vmax = 250; /* KTS */
 aileron_vmax  = 240; /* KTS */
 rudder_vmax   = 150; /* KTS */

 instrum.max_vv = 5000; /* ft/min */
 instrum.min_ias  =   30; /* kts */
 instrum.max_ias  =  350; /* kts */
 instrum.max_fuel_flow = 300; /* gal/hr */

 front_superdrag = 2.5;
 left_superdrag  = 5.0;
 top_superdrag   = 5.0;
