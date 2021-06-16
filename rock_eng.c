/* Included in ACCEL.C */
/* Code for rocket engines */

for (i=0; i<nrocketengines; i++){
	float fuel_flow;
	extern bool consume_fuel(float fuel_flow);
	extern bool rcs_control;
	
	if (rengine[i].ignition) {
		thrust = rengine[i].min_thrust_fraction * rengine[i].max_thrust + 
				 (rengine[i].max_thrust * (1. - rengine[i].min_thrust_fraction)) * (rengine[i].throttle/100.);
	}
	else
		thrust = 0;

	/* Fuel flow */
	//fuel_flow = rengine[i].max_fuelflow * (rengine[i].throttle/100.);
	fuel_flow = thrust / (rengine[i].specific_impulse * 9.82 * rho_fuel); // Liter/sec

	if (!consume_fuel(fuel_flow)) {
		fuel_flow = 0;
		thrust = 0;
		rengine[i].ignition = false;
	}

	// Linear acceleration from thrust
	accfront += thrust * rengine[i].thrustvector.x / totmass;
	accleft  += thrust * rengine[i].thrustvector.y / totmass;
	acctop   += thrust * rengine[i].thrustvector.z / totmass;

	// Angular acceleration from thrust
	waccfront += thrust * rengine[i].thrustvector.y *(rengine[i].top.masscenter  -cg.z)/ix; 
	waccfront -= thrust * rengine[i].thrustvector.z *(rengine[i].left.masscenter -cg.y)/ix; 
	waccleft  -= thrust * rengine[i].thrustvector.x *(rengine[i].top.masscenter  -cg.z)/iy; 
	waccleft  += thrust * rengine[i].thrustvector.z *(rengine[i].front.masscenter-cg.x)/iy; 
	wacctop   -= thrust * rengine[i].thrustvector.x *(rengine[i].left.masscenter -cg.y)/iz; 
	wacctop   += thrust * rengine[i].thrustvector.y *(rengine[i].front.masscenter-cg.x)/iz; 
	
	/* Torque from gravity */
	waccfront += cos_roll    *G*rengine[i].weight*(rengine[i].left.masscenter -cg.y)/ix;
	waccfront += sin_roll    *G*rengine[i].weight*(rengine[i].top.masscenter  -cg.z)/ix;
	waccleft  -= cos_nosealt *G*rengine[i].weight*(rengine[i].front.masscenter-cg.x)/iy;
	waccleft  += sin_nosealt *G*rengine[i].weight*(rengine[i].top.masscenter  -cg.z)/iy;
	wacctop   += sin_roll    *G*rengine[i].weight*(rengine[i].front.masscenter-cg.x)/iz;
	wacctop   += sin_nosealt *G*rengine[i].weight*(rengine[i].left.masscenter -cg.y)/iz;

	/* Vector-controls */
	if (rcs_control){
		float styrke=500; // Newton
		waccleft  -= (element[elevatorid].front.liftcenter-cg.z) *styrke*elevator/iy;
		wacctop   -= (element[rudderid].front.liftcenter-cg.x)   *styrke*rudder/iz;
		waccfront += (element[stbaileronid].left.liftcenter-cg.y)*styrke*aileron/ix;
	}
}

