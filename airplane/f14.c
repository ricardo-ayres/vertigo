 strcpy(modelname,"Grumman F-14A Tomcat");

 /* Krop, masse lagt fremefter - motor masse bagtil */
 /* Sidevaerts kraefter i seperat element */
 element[0].weight          = 9500;	/* Kg */ // 9300
 element[0].topcurvature    = 1.0;
 element[0].front.area      = 5.0;  /* m^2 */
 element[0].front.aspect    = 1;
 element[0].front.dragcoeff = 0.2;		/* min 0, max 1 */
 element[0].front.masscenter= 2.5;  /* foran center for stabilitet */
 element[0].front.liftcenter= 0.4; /* 0.0; */
 element[0].front.dragcenter= 0.0;
 element[0].front.deflect   = 0;
 element[0].left.area       = 0;
 element[0].left.aspect     = 0.5;
 element[0].left.dragcoeff  = 0.;
 element[0].left.masscenter = 0;
 element[0].left.liftcenter = 0;
 element[0].left.dragcenter = 0;          /* bag massecenter: stabiliserende */
 element[0].left.deflect    = 0;
 element[0].top.area        =40.0;  /* 50.0 */
 element[0].top.aspect      = 1.0;
 element[0].top.dragcoeff   = 0.6;
 element[0].top.masscenter  = 0.1;
 element[0].top.liftcenter  = 0.1;
 element[0].top.dragcenter  = 0.1;         /* bag massecenter: stabiliserende */
 element[0].top.deflect     = 0;
 element[0].top.oswald      = 0.5;

 /* Port taileron */
 element[1].weight          = 200;		 /* Kg */
 element[1].topcurvature    = 0;
 element[1].front.area      = 0.10*2.9;
 element[1].front.aspect    =30;
 element[1].front.dragcoeff = 0.1;		 /* min 0, max 1 */
 element[1].front.masscenter=-5.5;
 element[1].front.liftcenter=-5.4;
 element[1].front.dragcenter=-5.4;
 element[1].front.deflect   = 0;
 element[1].left.area       = 0.10*2.9;
 element[1].left.aspect     =10;
 element[1].left.dragcoeff  = 0.1;
 element[1].left.masscenter = 3.6;
 element[1].left.liftcenter = 3.6;
 element[1].left.dragcenter = 3.6;
 element[1].left.deflect    = 0;
 element[1].top.area        = 6.0;
 element[1].top.aspect      = 1.5;
 element[1].top.dragcoeff   = 0.6;
 element[1].top.masscenter  = 0.0;
 element[1].top.liftcenter  = 0.0;
 element[1].top.dragcenter  = 0.0;
 element[1].top.deflect     = 0;
 element[1].top.oswald      = 1.;

 /* Stb. taileron */
 element[2].weight          = 200;		 /* Kg */
 element[2].topcurvature    = 0;
 element[2].front.area      = 0.10*2.9;
 element[2].front.aspect    =30;
 element[2].front.dragcoeff = 0.1;		 /* min 0, max 1 */
 element[2].front.masscenter=-5.5;
 element[2].front.liftcenter=-5.4;
 element[2].front.dragcenter=-5.4;
 element[2].front.deflect   = 0;
 element[2].left.area       = 0.10*2.9;
 element[2].left.aspect     =10;
 element[2].left.dragcoeff  = 0.1;
 element[2].left.masscenter =-3.6;
 element[2].left.liftcenter =-3.6;
 element[2].left.dragcenter =-3.6;
 element[2].left.deflect    = 0;
 element[2].top.area        = 6.0;
 element[2].top.aspect      = 1.5;
 element[2].top.dragcoeff   = 0.6;
 element[2].top.masscenter  = 0.0;
 element[2].top.liftcenter  = 0.0;
 element[2].top.dragcenter  = 0.0;
 element[2].top.deflect     = 0;
 element[2].top.oswald      = 1.;

 /* Halefinne snyd: begge behandles som eet */
 element[3].weight=400;			/* Kg */
 element[3].topcurvature=0;
 element[3].front.area=0.1*2.2;
 element[3].front.aspect=20;
 element[3].front.dragcoeff=.1;		/* min 0, max 1 */
 element[3].front.masscenter=-5.6;
 element[3].front.liftcenter=-5.5;
 element[3].front.dragcenter=-5.5;
 element[3].front.deflect=0;
 element[3].left.area=5.4*2;
 element[3].left.aspect=1.5;
 element[3].left.dragcoeff=0.6;
 element[3].left.masscenter=0;
 element[3].left.liftcenter=0;
 element[3].left.dragcenter=0;
 element[3].left.deflect=0;
 element[3].top.area=0.05*1.4;
 element[3].top.aspect=20;
 element[3].top.dragcoeff=0.1;
 element[3].top.masscenter=1.9;
 element[3].top.liftcenter=1.9;
 element[3].top.dragcenter=1.9;
 element[3].top.deflect=0;
 element[3].top.oswald=1.0;

 /* Styrbord indre vinge */
 element[4].weight=750;
 element[4].topcurvature=3;
 element[4].front.area=0.2*3.4;
 element[4].front.aspect=20;
 element[4].front.dragcoeff=.1;
 element[4].front.masscenter=-0.3;
 element[4].front.liftcenter=0.1;  /* -0.2;*/
 element[4].front.dragcenter=-0.3;
 element[4].front.deflect=0;
 element[4].left.area=.1*1;
 element[4].left.aspect=20;
 element[4].left.dragcoeff=0.1;
 element[4].left.masscenter=4.7;
 element[4].left.liftcenter=4.7;
 element[4].left.dragcenter=4.7;
 element[4].left.deflect=0;
 element[4].top.area=11.0;
 element[4].top.aspect=5.0;
 element[4].top.dragcoeff=0.6;
 element[4].top.masscenter=0.54;
 element[4].top.liftcenter=0.54;
 element[4].top.dragcenter=0.54;
 element[4].top.deflect=0;
 element[4].top.oswald=0.95;

 /* Bagbord indre vinge */
 element[5].weight=750;
 element[5].topcurvature=3;
 element[5].front.area=0.2*3.4;
 element[5].front.aspect=20;
 element[5].front.dragcoeff=.1;
 element[5].front.masscenter=-0.3;
 element[5].front.liftcenter=0.1;  /* -0.2; */
 element[5].front.dragcenter=-0.3;
 element[5].front.deflect=0;
 element[5].left.area=0.1*1;
 element[5].left.aspect=20;
 element[5].left.dragcoeff=0.1;
 element[5].left.masscenter=-4.7;
 element[5].left.liftcenter=-4.7;
 element[5].left.dragcenter=-4.7;
 element[5].left.deflect=0;
 element[5].top.area=11.0;
 element[5].top.aspect=5.0;
 element[5].top.dragcoeff=0.6;
 element[5].top.masscenter=0.54;
 element[5].top.liftcenter=0.54;
 element[5].top.dragcenter=0.54;
 element[5].top.deflect=0;
 element[5].top.oswald=0.95;

 /* Styrbord ydre vinge */
 element[6].weight=250;
 element[6].topcurvature=2;
 element[6].front.area=0.15*2.7;
 element[6].front.aspect=20;
 element[6].front.dragcoeff=.1;
 element[6].front.masscenter=-1.0;
 element[6].front.liftcenter=-0.6; /* -0.9 */
 element[6].front.dragcenter=-1.0;
 element[6].front.deflect=0;
 element[6].left.area=.1*1;
 element[6].left.aspect=20;
 element[6].left.dragcoeff=0.1;
 element[6].left.masscenter=7.8;
 element[6].left.liftcenter=7.8;
 element[6].left.dragcenter=7.8;
 element[6].left.deflect=0;
 element[6].top.area=5.00;
 element[6].top.aspect=5.0;
 element[6].top.dragcoeff=0.6;
 element[6].top.masscenter=0.54;
 element[6].top.liftcenter=0.54;
 element[6].top.dragcenter=0.54;
 element[6].top.deflect=0;
 element[6].top.oswald=0.8;

 /* Bagbord ydre vinge */
 element[7].weight=250;
 element[7].topcurvature=2;
 element[7].front.area=0.15*2.7;
 element[7].front.aspect=20;
 element[7].front.dragcoeff=.1;
 element[7].front.masscenter=-1.0;
 element[7].front.liftcenter=-0.6;  /* -0.9 */
 element[7].front.dragcenter=-1.0;
 element[7].front.deflect=0;
 element[7].left.area=0.1*1;
 element[7].left.aspect=20;
 element[7].left.dragcoeff=0.1;
 element[7].left.masscenter=-7.8;
 element[7].left.liftcenter=-7.8;
 element[7].left.dragcenter=-7.8;
 element[7].left.deflect=0;
 element[7].top.area=5.00;
 element[7].top.aspect=5.0;
 element[7].top.dragcoeff=0.6;
 element[7].top.masscenter=0.54;
 element[7].top.liftcenter=0.54;
 element[7].top.dragcenter=0.54;
 element[7].top.deflect=0;
 element[7].top.oswald=0.8;

 /* Krop, kun sidevaerts kraefter */
 element[8].weight=1;		  	/* Kg */
 element[8].topcurvature=0;
 element[8].front.area=0;    		/* m^2 */
 element[8].front.aspect=1;
 element[8].front.dragcoeff=0;		/* min 0, max 1 */
 element[8].front.masscenter=3.5;
 element[8].front.liftcenter= 1.0;
 element[8].front.dragcenter= 1.0;
 element[8].front.deflect=0;
 element[8].left.area=24;
 element[8].left.aspect=0.5;
 element[8].left.dragcoeff=0.5;
 element[8].left.masscenter=0;
 element[8].left.liftcenter=0;
 element[8].left.dragcenter=0;
 element[8].left.deflect=0;
 element[8].top.area=0;
 element[8].top.aspect=1;
 element[8].top.dragcoeff=0.;
 element[8].top.masscenter=0.1;
 element[8].top.liftcenter=0.1;
 element[8].top.dragcenter=0.1;
 element[8].top.deflect=0;
 element[8].top.oswald=1.0;

 /* Jet-engines */
 /* Mass and thrust origins in same point */
 /* Left engine */
 jengine[0].weight=2650; //2750
 jengine[0].front.masscenter=-3.6;
 jengine[0].left.masscenter =-1.42;
 jengine[0].top.masscenter  =-0.3;
 jengine[0].throttle=0; /* % */
 jengine[0].rpm=0;        /* % */
 jengine[0].egt=500;
 jengine[0].ab_status  =0;
 jengine[0].vectoruplim=0;
 jengine[0].vectordnlim=0;
 jengine[0].vectorpos=0;
 jengine[0].vectordesire=0;
 jengine[0].vectorresponse=0;
 jengine[0].rpm_response =     5; /* %/sec */
 jengine[0].ab_response  =     2; /* stages / sec */
 jengine[0].idle_rpm     =    65; /* % */
 jengine[0].idle_thrust  =  1000; /* Newton */
 jengine[0].mil_thrust   = 54011; /* Newton  = 12350 pounds */
 jengine[0].ab_stg_thrust=  7617; /* Newton  = 1710 pounds / AB stage */
 jengine[0].n_abstages   =     5;
 jengine[0].idle_fflow   =     0.126; /* kg/sec = 1000 lbs/h */
 jengine[0].mil_fflow    =     0.756; /* kg/sec = 6000 lbs/h */
 jengine[0].ab_stg_fflow =     1.008; /* kg/sec = 8000 lbs/stage/h */
 jengine[0].fflw         =     0;
 jengine[0].stall_pitchup   = 25;
 jengine[0].stall_pitchdown =  8;
 jengine[0].stall_yawleft   = 10;
 jengine[0].stall_yawright  = 25;
 jengine[0].inlet_ramp_m0   =  2.2;
 jengine[0].inlet_ramp_slope=  1;
 jengine[0].ignition        =  true;
 jengine[0].compressor_stall=  false;
 /* Simple model */
 jengine[0].response=20;  /* %/sec */
 jengine[0].power=93000.;   /* Newton = 9480 kg full A/B*/

 /* Right engine */
 jengine[1].weight=2650; // 2750
 jengine[1].front.masscenter=-3.6;
 jengine[1].left.masscenter = 1.42;
 jengine[1].top.masscenter  =-0.3;
 jengine[1].throttle=0; /* % */
 jengine[1].rpm=0;        /* % */
 jengine[1].egt=500;
 jengine[1].ab_status  =0;
 jengine[1].vectoruplim=0;
 jengine[1].vectordnlim=0;
 jengine[1].vectorpos=0;
 jengine[1].vectordesire=0;
 jengine[1].vectorresponse=0;
 jengine[1].rpm_response =     5; /* %/sec */
 jengine[1].ab_response  =     2; /* stages / sec */
 jengine[1].idle_rpm     =    65; /* % */
 jengine[1].idle_thrust  =  1000; /* Newton */
 jengine[1].mil_thrust   = 54011; /* Newton  = 12350 pounds */
 jengine[1].ab_stg_thrust=  7617; /* Newton  = 1710 pounds / AB stage */
 jengine[1].n_abstages   =     5;
 jengine[1].idle_fflow   =     0.126; /* kg/sec = 1000 lbs/h */
 jengine[1].mil_fflow    =     0.756; /* kg/sec = 6000 lbs/h */
 jengine[1].ab_stg_fflow =     1.008; /* kg/sec = 8000 lbs/stage/h */
 jengine[1].fflw         =     0;
 jengine[1].stall_pitchup   = 25;
 jengine[1].stall_pitchdown =  8;
 jengine[1].stall_yawleft   = 25;
 jengine[1].stall_yawright  = 10;
 jengine[1].inlet_ramp_m0   =  2.2;
 jengine[1].inlet_ramp_slope=  1;
 jengine[1].ignition        =  true;
 jengine[1].compressor_stall=  false;
 /* simple model */
 jengine[1].response=20;  /* %/sec */
 jengine[1].power=93000.;   /* Newton = 9480 kg full A/B*/


 /* Naese-hjul */
 gear[0].weight=200;
 gear[0].hingepos.x=6.25;
 gear[0].hingepos.y=0;
 gear[0].hingepos.z=-0.41;
 gear[0].length=0.9;
 gear[0].stroke=0.37;
 gear[0].strokepos=0.;
 gear[0].damping=0.10;
 gear[0].down=1;
 gear[0].downrate=0.3;
 gear[0].steergain=1.0;
 gear[0].brakeeffect=0;
 gear[0].area=0.2*1.5;
 gear[0].dragcoeff=1.0;
 gear[0].spring=100000.; /* newton per meter */
 gear[0].steer=0;
 gear[0].wheel_radius=0.24;
 gear[0].wheel_omega=0;
 gear[0].wheel_moment=0.5*8*SQR(0.66*gear[0].wheel_radius);
 gear[0].skid=false;

 /* Port gear */
 gear[1].weight=250;
 gear[1].hingepos.x=-0.62;
 gear[1].hingepos.y=-2.45;
 gear[1].hingepos.z=-0.01;
 gear[1].length=1.3;
 gear[1].stroke=0.51;
 gear[1].strokepos=0.;
 gear[1].damping=0.12;
 gear[1].down=1;
 gear[1].downrate=0.2;
 gear[1].steergain=1;
 gear[1].brakeeffect=0.5;
 gear[1].area=0.3*1.8;
 gear[1].dragcoeff=1.0;
 gear[1].spring=300000.; /* newton per meter */
 gear[1].steer=0;
 gear[1].wheel_radius=0.47;
 gear[1].wheel_omega=0;
 gear[1].wheel_moment=0.5*10*SQR(0.66*gear[1].wheel_radius);
 gear[1].skid=false;

 /* Stb. gear */
 gear[2].weight=250;
 gear[2].hingepos.x=-0.62;
 gear[2].hingepos.y= 2.45;
 gear[2].hingepos.z=-0.01;
 gear[2].length=1.3;
 gear[2].stroke=0.51;
 gear[2].strokepos=0.;
 gear[2].damping=0.12;
 gear[2].down=1;
 gear[2].downrate=0.2;
 gear[2].steergain=1;
 gear[2].brakeeffect=0.5;
 gear[2].area=0.3*1.8;
 gear[2].dragcoeff=1.0;
 gear[2].spring=300000.; /* newton per meter */
 gear[2].steer=0;
 gear[2].wheel_radius=0.47;
 gear[2].wheel_omega=0;
 gear[2].wheel_moment=0.5*10*SQR(0.66*gear[2].wheel_radius);
 gear[2].skid=false;

 /* Tail hardpoint */
 gear[3].weight=0;
 gear[3].hingepos.x=-6.14;
 gear[3].hingepos.y= 1.44;
 gear[3].hingepos.z=-0.69;
 gear[3].length=0;
 gear[3].stroke=0;
 gear[3].strokepos=0.;
 gear[3].damping=0.1;
 gear[3].down=1;
 gear[3].downrate=0;
 gear[3].steergain=0;
 gear[3].brakeeffect=0.75;
 gear[3].area=0;
 gear[3].dragcoeff=0;
 gear[3].spring=300000.; /* newton per meter */
 gear[3].steer=0;
 gear[3].skid=false;

 gear[4].weight=0;
 gear[4].hingepos.x=-6.14;
 gear[4].hingepos.y=-1.44;
 gear[4].hingepos.z=-0.69;
 gear[4].length=0;
 gear[4].stroke=0;
 gear[4].strokepos=0.;
 gear[4].damping=0.1;
 gear[4].down=1;
 gear[4].downrate=0;
 gear[4].steergain=0;
 gear[4].brakeeffect=0.75;
 gear[4].area=0;
 gear[4].dragcoeff=0;
 gear[4].spring=300000.; /* newton per meter */
 gear[4].steer=0;
 gear[4].skid=false;

 /* Stb. ving tip, zero sweep */
 gear[5].weight=0;
 gear[5].hingepos.x=-2.3;
 gear[5].hingepos.y= 9.60;
 gear[5].hingepos.z= 0.47;
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

 /* Port ving tip, zero sweep */
 gear[6].weight=0;
 gear[6].hingepos.x=-2.3;
 gear[6].hingepos.y=-9.60;
 gear[6].hingepos.z= 0.47;
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
 gear[6].spring=100000.; /* newton per meter */
 gear[6].steer=0;
 gear[6].skid=false;

 /* nose */
 gear[7].weight=0;
 gear[7].hingepos.x= 9.4;
 gear[7].hingepos.y= 0.0;
 gear[7].hingepos.z=-0.4;
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
 hook.hingepos.x = -4.84;
 hook.hingepos.y =  0;
 hook.hingepos.z = -0.20;
 hook.length     =  2.22;
 hook.down       =  0;
 hook.downrate   =  1.0;
 hook.deaccel    =  2.0;

 /* Gun data from rec.aviation.military fact page */
 /* GE M61 */
 gun[0].pos.x           =    8.91;
 gun[0].pos.y           =    0.60;
 gun[0].pos.z           =   -0.18;
 gun[0].aim.x           =    1;
 gun[0].aim.y           =    0;
 gun[0].aim.z           =    0;
 gun[0].nrounds         =  675;
 gun[0].muzzle_vel      = 1036;     /* meter/sec */
 gun[0].fire_rate       =  100;     /* per second */
 gun[0].projectile_mass =    0.098; /* kg */
 gun[0].t_last_shot     =    0;
 gun[0].recoil          =  150;      /* Newton/sec */
 gun[0].tracer_freq     =    3;

 airbrake.area      = 2.1;   /* Upper 0.8 m^2, lower 0.69 m^2, ref M. Spick */
 airbrake.dragcoeff = 1.0;
 airbrake.out       = 0;
 airbrake.outrate   = 0.5;   /* ref M. Spick */
 airbrake.pos.x     =-5.4;
 airbrake.pos.y     = 0.0;
 airbrake.pos.z     = 0.2;

 /* Wing tanks */
 fueltank[0].pos.x    =   -0.8;
 fueltank[0].pos.y    =    6.5;
 fueltank[0].pos.z    =    0.6;
 fueltank[0].capacity = 1092;  /* Liter */

 fueltank[1].pos.x    =   -0.8;
 fueltank[1].pos.y    =   -6.5;
 fueltank[1].pos.z    =    0.6;
 fueltank[1].capacity = 1092;  /* Liter */

 /* wing box tanks */
 fueltank[2].pos.x    =    0.0;
 fueltank[2].pos.y    =    1.8;
 fueltank[2].pos.z    =    0.6;
 fueltank[2].capacity =  874;  /* Liter */

 fueltank[3].pos.x    =    0.0;
 fueltank[3].pos.y    =   -1.8;
 fueltank[3].pos.z    =    0.6;
 fueltank[3].capacity =  874;  /* Liter */

 /* Front and aft tanks */
 fueltank[4].pos.x    =    2.9;
 fueltank[4].pos.y    =    0.0;
 fueltank[4].pos.z    =    0.6;
 fueltank[4].capacity = 2486;  /* Liter */

 fueltank[5].pos.x    =   -2.9;
 fueltank[5].pos.y    =    0.0;
 fueltank[5].pos.z    =   -0.2;
 fueltank[5].capacity = 2486;  /* Liter */

 rho_fuel = 0.83; /* JP-5 at 60 deg F */

 flapresponse=5; /* deg/sec */
 flap_cp_travel = 0.0; /* Does not work with wing sweep */
 slat_eff = 0.75;

 nwingsections = 0;
 nelements     = 9;
 njetengines   = 2;
 npropengines  = 0;
 nrocketengines= 0;
 ngears        = 3;
 nhardpts      = 5;
 nguns         = 1;
 nfueltanks    = 6;

 pilotpos.x=7.15;
 pilotpos.y=0;
 pilotpos.z=1.37;  /* 1.34 */

 show_hud=true;

 ldg_aim_offset  = 1.2; /* 2.5 */ /* meters */
 desired_ldg_spd = 123;   /* KTS */
 desired_ldg_AOA = 10.8;   /* degrees */
 meatball_tilt   = ldg_aim_offset/24.4; /* Distance to meatball */

 controls.elevatorrate = 120; /* degrees/sec */
 controls.aileronrate  = 120;
 controls.rudderrate   = 120;

 stall_angle = 14.0*(PI/180);

 elevator_gain = 0.95;
 aileron_gain  = 1.0;
 rudder_gain   = 0.85;

 elevator_vmax = 500; /* KTS */
 aileron_vmax  = 500; /* KTS */
 rudder_vmax   = 400; /* KTS */

 instrum.max_vv = 6000; /* ft/min */
 instrum.min_ias  =   30; /* kts */
 instrum.max_ias  =  700; /* kts */
 instrum.max_fuel_flow = 3000; /* gal/hr */

 front_superdrag = 2.0;  /* overwritten by external code */
 left_superdrag  = 5.0;
 top_superdrag   = 5.0;
