/* Lunar Module */

 strcpy(modelname,"Lunar Module");

 /* Krop */
 element[0].weight=2400;			/* Kg */
 element[0].topcurvature=0;
 element[0].front.area=10.;    		/* m^2 */
 element[0].front.aspect=1;
 element[0].front.dragcoeff=.5;		/* min 0, max 1 */
 element[0].front.masscenter=0;     
 element[0].front.liftcenter=0;
 element[0].front.dragcenter=0;     
 element[0].front.deflect=0;
 element[0].left.area=10.;
 element[0].left.aspect=1;
 element[0].left.dragcoeff=0.5;
 element[0].left.masscenter=0;
 element[0].left.liftcenter=0;
 element[0].left.dragcenter=0;        
 element[0].left.deflect=0;
 element[0].top.area=10.;
 element[0].top.aspect=1;
 element[0].top.dragcoeff=0.5;
 element[0].top.masscenter=2.;
 element[0].top.liftcenter=0;
 element[0].top.dragcenter=0;          
 element[0].top.deflect=0;
 element[0].top.oswald=0.5;

 /* Haleplan */
 element[1].weight=0;			/* Kg */
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
 element[2].weight=0;			/* Kg */
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
 element[3].weight=600;			/* Kg */
 element[3].topcurvature=3;
 element[3].front.area=0.2*2;
 element[3].front.aspect=20;
 element[3].front.dragcoeff=.12;		/* min 0, max 1 */
 element[3].front.masscenter=3;
 element[3].front.liftcenter=0; 
 element[3].front.dragcenter=0;    
 element[3].front.deflect=0;
 element[3].left.area=0;   
 element[3].left.aspect=10;
 element[3].left.dragcoeff=0.1;
 element[3].left.masscenter=1.7;
 element[3].left.liftcenter=1.7;
 element[3].left.dragcenter=1.7;
 element[3].left.deflect=0;
 element[3].top.area=2.7*1.7;
 element[3].top.aspect=2.6;
 element[3].top.dragcoeff=0.6;
 element[3].top.masscenter=0;
 element[3].top.liftcenter=0;
 element[3].top.dragcenter=0;
 element[3].top.deflect=0;
 element[3].top.oswald=1.2;

 /* Bagbord indre vinge */
 element[4].weight=600;			/* Kg */
 element[4].topcurvature=3;
 element[4].front.area=0.2*2;
 element[4].front.aspect=20;
 element[4].front.dragcoeff=.12;		/* min 0, max 1 */
 element[4].front.masscenter=3;
 element[4].front.liftcenter=0; 
 element[4].front.dragcenter=0;
 element[4].front.deflect=0;
 element[4].left.area=0;   
 element[4].left.aspect=10;
 element[4].left.dragcoeff=0.1;
 element[4].left.masscenter=-1.7;
 element[4].left.liftcenter=-1.7;
 element[4].left.dragcenter=-1.7;
 element[4].left.deflect=0;
 element[4].top.area=2.7*1.7;
 element[4].top.aspect=2.6;
 element[4].top.dragcoeff=0.6;
 element[4].top.masscenter=0;
 element[4].top.liftcenter=0;
 element[4].top.dragcenter=0;
 element[4].top.deflect=0;
 element[4].top.oswald=1.2;

 /* Styrbord ydre vinge */
 element[5].weight=600;
 element[5].topcurvature=3;
 element[5].front.area=0.1*2;
 element[5].front.aspect=20;
 element[5].front.dragcoeff=.12;
 element[5].front.masscenter=-3;
 element[5].front.liftcenter=0; 
 element[5].front.dragcenter=0;
 element[5].front.deflect=0;
 element[5].left.area=0;  
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
 element[6].weight=600;
 element[6].topcurvature=3;
 element[6].front.area=0.1*2;
 element[6].front.aspect=20;
 element[6].front.dragcoeff=.12;
 element[6].front.masscenter=-3;
 element[6].front.liftcenter=0; 
 element[6].front.dragcenter=0;
 element[6].front.deflect=0;
 element[6].left.area=0;   
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

 /* Rocket engine */
 /* Mass and thrust origins in same point */
 rengine[0].weight=1000;
 rengine[0].front.masscenter= 0.0;
 rengine[0].left.masscenter = 0.0;
 rengine[0].top.masscenter  = 3.0;
 rengine[0].thrustvector.x    = 0.0;
 rengine[0].thrustvector.y    = 0.0;
 rengine[0].thrustvector.z    = 1.0;
 rengine[0].throttle=0; /* % */
 rengine[0].max_thrust = 43900.; // N
 rengine[0].min_thrust_fraction = 0.107; // 10.7% = 4700N idle thrust 
 rengine[0].specific_impulse = 311.; // sec
 rengine[0].ignition = true;

 gear[0].weight=50;
 gear[0].hingepos.x=7.0;
 gear[0].hingepos.y=0;
 gear[0].hingepos.z=-1.0;
 gear[0].length=0;       
 gear[0].stroke=0.2;
 gear[0].strokepos=0.;
 gear[0].damping=0.10;
 gear[0].down=1;
 gear[0].downrate=0.;
 gear[0].steergain=0.;
 gear[0].brakeeffect=1.0;
 gear[0].area=0.2*1.0;
 gear[0].dragcoeff=1.0;
 gear[0].spring=120000.; /* newton per meter */
 gear[0].steer=0;
 gear[0].wheel_radius=0.2;
 gear[0].wheel_omega=0;
 gear[0].wheel_moment=0.5*4*SQR(0.66*gear[0].wheel_radius);
 gear[0].skid=true;

 gear[1].weight=50;
 gear[1].hingepos.x=-7.0;
 gear[1].hingepos.y=0;
 gear[1].hingepos.z=-1.0;
 gear[1].length=0;       
 gear[1].stroke=0.2;
 gear[1].strokepos=0.;
 gear[1].damping=0.10;
 gear[1].down=1;
 gear[1].downrate=0.;
 gear[1].steergain=0.;
 gear[1].brakeeffect=1.0;
 gear[1].area=0.2*1.0;
 gear[1].dragcoeff=1.0;
 gear[1].spring=120000.; /* newton per meter */
 gear[1].steer=0;
 gear[1].wheel_radius=0.2;
 gear[1].wheel_omega=0;
 gear[1].wheel_moment=0.5*4*SQR(0.66*gear[0].wheel_radius);
 gear[1].skid=true;

 gear[2].weight=50;
 gear[2].hingepos.x=0;
 gear[2].hingepos.y=7.0;
 gear[2].hingepos.z=-1.0;
 gear[2].length=0;       
 gear[2].stroke=0.2;
 gear[2].strokepos=0.;
 gear[2].damping=0.10;
 gear[2].down=1;
 gear[2].downrate=0.;
 gear[2].steergain=0.;
 gear[2].brakeeffect=1.0;
 gear[2].area=0.2*1.0;
 gear[2].dragcoeff=1.0;
 gear[2].spring=120000.; /* newton per meter */
 gear[2].steer=0;
 gear[2].wheel_radius=0.2;
 gear[2].wheel_omega=0;
 gear[2].wheel_moment=0.5*4*SQR(0.66*gear[0].wheel_radius);
 gear[2].skid=true;

 gear[3].weight=50;
 gear[3].hingepos.x=0;
 gear[3].hingepos.y=-7.0;
 gear[3].hingepos.z=-1.0;
 gear[3].length=0;       
 gear[3].stroke=0.2;
 gear[3].strokepos=0.;
 gear[3].damping=0.10;
 gear[3].down=1;
 gear[3].downrate=0.;
 gear[3].steergain=0.;
 gear[3].brakeeffect=1.0;
 gear[3].area=0.2*1.0;
 gear[3].dragcoeff=1.0;
 gear[3].spring=120000.; /* newton per meter */
 gear[3].steer=0;
 gear[3].wheel_radius=0.2;
 gear[3].wheel_omega=0;
 gear[3].wheel_moment=0.5*4*SQR(0.66*gear[0].wheel_radius);
 gear[3].skid=true;
 
 // No hook
 hook.exists     = false;
 hook.hingepos.x = 0;
 hook.hingepos.y = 0;
 hook.hingepos.z = 0;
 hook.length     = 0;
 hook.down       = 0;
 hook.downrate   = 0;
 hook.deaccel    = 0;

 // No airbrake
 airbrake.area      = 0;
 airbrake.dragcoeff = 0;
 airbrake.out       = 0;
 airbrake.outrate   = 0;
 airbrake.pos.x     = 0;
 airbrake.pos.y     = 0;
 airbrake.pos.z     = 0;

 // Total descent stage fuel load: 8165 kg
 // Reduced to estimated useful quantity at Low Gate: 522 kg 
 fueltank[0].pos.x    = 2.00;
 fueltank[0].pos.y    = 2.00;
 fueltank[0].pos.z    = 0.;
 //fueltank[0].capacity = 2041;  /* Liter */
 fueltank[0].capacity =  130.5; /* Liter */

 fueltank[1].pos.x    =-2.00;
 fueltank[1].pos.y    =-2.00;
 fueltank[1].pos.z    = 0.;
 //fueltank[1].capacity = 2041;  /* Liter */
 fueltank[1].capacity =  130.5; /* Liter */

 fueltank[2].pos.x    = 2.00;
 fueltank[2].pos.y    =-2.00;
 fueltank[2].pos.z    = 0.;
 //fueltank[2].capacity = 2041;  /* Liter */
 fueltank[2].capacity =  130.5; /* Liter */

 fueltank[3].pos.x    =-2.00;
 fueltank[3].pos.y    = 2.00;
 fueltank[3].pos.z    = 0.;
 //fueltank[3].capacity = 2041;  /* Liter */
 fueltank[3].capacity =  130.5; /* Liter */

 rho_fuel = 1.00; 

 // No flaps
 flapresponse=0; /* deg/sec */
 flap_cp_travel = 0;
 slat_eff = 0;

 nwingsections = 0;
 nelements     = 7;
 njetengines   = 0;
 npropengines  = 0;
 nrocketengines= 1;
 ngears        = 4;
 nhardpts      = 0;
 nguns         = 0;
 nfueltanks    = 4;

 pilotpos.x= 1.00;
 pilotpos.y= 0.50;
 pilotpos.z= 5.50;

 show_hud=true;

 ldg_aim_offset  = -2.0; /* meters */
 desired_ldg_spd = 145;   /* KTS */
 desired_ldg_AOA = 6.2; /* degrees */
 meatball_tilt   = ldg_aim_offset/24.4; /* Distance to meatball */

 controls.elevatorrate = 120; /* degrees/sec */
 controls.aileronrate  = 120;
 controls.rudderrate   = 120;

 stall_angle = 180.0*(PI/180);

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

 front_superdrag = 5.0;
 left_superdrag  = 5.0;
 top_superdrag   = 5.0;
