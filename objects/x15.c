
 id=X15;
 object[id].max_draw_dist=5000;
 object[id].always_draw_dist=50;

 object[id].nvertices = 157;
 object[id].nfacets   = 136; /* Excluding control surface polys */
 object[id].nctrl_srf =   9;

 // Flaps
 object[id].ctrl_surface[0].hinge.x      =-1.26;
 object[id].ctrl_surface[0].hinge.y      = 1.11;
 object[id].ctrl_surface[0].hinge.z      = 0;
 object[id].ctrl_surface[0].rudder_gain  = 0;
 object[id].ctrl_surface[0].aileron_gain = 0;
 object[id].ctrl_surface[0].elevator_gain= 0;
 object[id].ctrl_surface[0].flap_gain    = 1.5;
 object[id].ctrl_surface[0].brake_gain   = 0;
 object[id].ctrl_surface[0].gear_gain    = 0;
 object[id].ctrl_surface[0].gear_id      =-1;
 object[id].ctrl_surface[0].nctrlpoly    = 2;
 object[id].ctrl_surface[0].poly_id[0]   = 136;
 object[id].ctrl_surface[0].poly_id[1]   = 137;
 
 object[id].ctrl_surface[1].hinge.x      =-1.26;
 object[id].ctrl_surface[1].hinge.y      =-1.11;
 object[id].ctrl_surface[1].hinge.z      = 0;
 object[id].ctrl_surface[1].rudder_gain  = 0;
 object[id].ctrl_surface[1].aileron_gain = 0;
 object[id].ctrl_surface[1].elevator_gain= 0;
 object[id].ctrl_surface[1].flap_gain    =-1.5;
 object[id].ctrl_surface[1].brake_gain   = 0;
 object[id].ctrl_surface[1].gear_gain    = 0;
 object[id].ctrl_surface[1].gear_id      =-1;
 object[id].ctrl_surface[1].nctrlpoly    = 2;
 object[id].ctrl_surface[1].poly_id[0]   = 138;
 object[id].ctrl_surface[1].poly_id[1]   = 139;
 
 // Air brakes
 object[id].ctrl_surface[2].hinge.x      =-4.41;
 object[id].ctrl_surface[2].hinge.y      = 0.18;
 object[id].ctrl_surface[2].hinge.z      =-0.68;
 object[id].ctrl_surface[2].rudder_gain  = 0;
 object[id].ctrl_surface[2].aileron_gain = 0;
 object[id].ctrl_surface[2].elevator_gain= 0;
 object[id].ctrl_surface[2].flap_gain    = 0;
 object[id].ctrl_surface[2].brake_gain   =45;
 object[id].ctrl_surface[2].gear_gain    = 0;
 object[id].ctrl_surface[2].gear_id      =-1;
 object[id].ctrl_surface[2].nctrlpoly    = 2;
 object[id].ctrl_surface[2].poly_id[0]   = 140;
 object[id].ctrl_surface[2].poly_id[1]   = 141;

 object[id].ctrl_surface[3].hinge.x      =-4.41;
 object[id].ctrl_surface[3].hinge.y      =-0.18;
 object[id].ctrl_surface[3].hinge.z      =-0.68;
 object[id].ctrl_surface[3].rudder_gain  = 0;
 object[id].ctrl_surface[3].aileron_gain = 0;
 object[id].ctrl_surface[3].elevator_gain= 0;
 object[id].ctrl_surface[3].flap_gain    = 0;
 object[id].ctrl_surface[3].brake_gain   =45;
 object[id].ctrl_surface[3].gear_gain    = 0;
 object[id].ctrl_surface[3].gear_id      =-1;
 object[id].ctrl_surface[3].nctrlpoly    = 2;
 object[id].ctrl_surface[3].poly_id[0]   = 142;
 object[id].ctrl_surface[3].poly_id[1]   = 143;

 // Tail plane
 object[id].ctrl_surface[4].hinge.x      =-4.19;
 object[id].ctrl_surface[4].hinge.y      = 1.08;
 object[id].ctrl_surface[4].hinge.z      = 0;
 object[id].ctrl_surface[4].rudder_gain  = 0;
 object[id].ctrl_surface[4].aileron_gain =-1.5;
 object[id].ctrl_surface[4].elevator_gain= 1.5;
 object[id].ctrl_surface[4].flap_gain    = 0;
 object[id].ctrl_surface[4].brake_gain   = 0;
 object[id].ctrl_surface[4].gear_gain    = 0;
 object[id].ctrl_surface[4].gear_id      =-1;
 object[id].ctrl_surface[4].nctrlpoly    = 2;
 object[id].ctrl_surface[4].poly_id[0]   = 144;
 object[id].ctrl_surface[4].poly_id[1]   = 145;

 object[id].ctrl_surface[5].hinge.x      =-4.19;
 object[id].ctrl_surface[5].hinge.y      =-1.08;
 object[id].ctrl_surface[5].hinge.z      = 0;
 object[id].ctrl_surface[5].rudder_gain  = 0;
 object[id].ctrl_surface[5].aileron_gain = 1.5;
 object[id].ctrl_surface[5].elevator_gain= 1.5;
 object[id].ctrl_surface[5].flap_gain    = 0;
 object[id].ctrl_surface[5].brake_gain   = 0;
 object[id].ctrl_surface[5].gear_gain    = 0;
 object[id].ctrl_surface[5].gear_id      =-1;
 object[id].ctrl_surface[5].nctrlpoly    = 2;
 object[id].ctrl_surface[5].poly_id[0]   = 146;
 object[id].ctrl_surface[5].poly_id[1]   = 147;

 // Nose wheel
 object[id].ctrl_surface[6].hinge.x      = 8.24;
 object[id].ctrl_surface[6].hinge.y      = 0;
 object[id].ctrl_surface[6].hinge.z      =-0.40;
 object[id].ctrl_surface[6].rudder_gain  = 0;
 object[id].ctrl_surface[6].aileron_gain = 0;
 object[id].ctrl_surface[6].elevator_gain= 0;
 object[id].ctrl_surface[6].flap_gain    = 0;
 object[id].ctrl_surface[6].brake_gain   = 0;
 object[id].ctrl_surface[6].gear_gain    =90;
 object[id].ctrl_surface[6].gear_id      = 0;
 object[id].ctrl_surface[6].nctrlpoly    = 4;
 object[id].ctrl_surface[6].poly_id[0]   = 148;
 object[id].ctrl_surface[6].poly_id[1]   = 149;
 object[id].ctrl_surface[6].poly_id[2]   = 150;
 object[id].ctrl_surface[6].poly_id[3]   = 151;

 // Skids
 object[id].ctrl_surface[7].hinge.x      =-4.41;
 object[id].ctrl_surface[7].hinge.y      = 0.57;
 object[id].ctrl_surface[7].hinge.z      =-0.50;
 object[id].ctrl_surface[7].rudder_gain  = 0;
 object[id].ctrl_surface[7].aileron_gain = 0;
 object[id].ctrl_surface[7].elevator_gain= 0;
 object[id].ctrl_surface[7].flap_gain    = 0;
 object[id].ctrl_surface[7].brake_gain   = 0;
 object[id].ctrl_surface[7].gear_gain    = 45;
 object[id].ctrl_surface[7].gear_id      = 1;
 object[id].ctrl_surface[7].nctrlpoly    = 4;
 object[id].ctrl_surface[7].poly_id[0]   = 152;
 object[id].ctrl_surface[7].poly_id[1]   = 153;
 object[id].ctrl_surface[7].poly_id[2]   = 156;
 object[id].ctrl_surface[7].poly_id[3]   = 157;

 object[id].ctrl_surface[8].hinge.x      =-4.41;
 object[id].ctrl_surface[8].hinge.y      =-0.57;
 object[id].ctrl_surface[8].hinge.z      =-0.50;
 object[id].ctrl_surface[8].rudder_gain  = 0;
 object[id].ctrl_surface[8].aileron_gain = 0;
 object[id].ctrl_surface[8].elevator_gain= 0;
 object[id].ctrl_surface[8].flap_gain    = 0;
 object[id].ctrl_surface[8].brake_gain   = 0;
 object[id].ctrl_surface[8].gear_gain    =-45;
 object[id].ctrl_surface[8].gear_id      = 2;
 object[id].ctrl_surface[8].nctrlpoly    = 4;
 object[id].ctrl_surface[8].poly_id[0]   = 154;
 object[id].ctrl_surface[8].poly_id[1]   = 155;
 object[id].ctrl_surface[8].poly_id[2]   = 158;
 object[id].ctrl_surface[8].poly_id[3]   = 159;


 /*
 object[id].ctrl_surface[].hinge.x      = ;
 object[id].ctrl_surface[].hinge.y      = ;
 object[id].ctrl_surface[].hinge.z      = ;
 object[id].ctrl_surface[].rudder_gain  = ;
 object[id].ctrl_surface[].aileron_gain = ;
 object[id].ctrl_surface[].elevator_gain= ;
 object[id].ctrl_surface[].flap_gain    = ;
 object[id].ctrl_surface[].brake_gain   = ;
 object[id].ctrl_surface[].gear_gain    = ;
 object[id].ctrl_surface[].gear_id      = ;
 object[id].ctrl_surface[].nctrlpoly    = ;
 object[id].ctrl_surface[].poly_id[0]   = ;
 object[id].ctrl_surface[].poly_id[1]   = ;
 object[id].ctrl_surface[].poly_id[2]   = ;
 object[id].ctrl_surface[].poly_id[3]   = ;
 */


 nfacets=object[id].nfacets;
 for (j=0; j<object[id].nctrl_srf; j++) nfacets+=object[id].ctrl_surface[j].nctrlpoly;

 if ((object[id].vertex = malloc(object[id].nvertices*sizeof(cartvektor))) == NULL)
 {
   printf("Not enough memory\n");
   exit(1);
 }

 if ((object[id].facet = malloc(nfacets*sizeof(polygon_struct))) == NULL)
 {
   printf("Not enough memory\n");
   exit(1);
 }
 facetid=object[id].facet;

 // Body
 (object[id].vertex+0)->x= 3.46;
 (object[id].vertex+0)->y=-0.26;
 (object[id].vertex+0)->z= 0.74;

 (object[id].vertex+1)->x= 3.46;
 (object[id].vertex+1)->y= 0.26;
 (object[id].vertex+1)->z= 0.74;

 (object[id].vertex+2)->x=-2.12;
 (object[id].vertex+2)->y= 0.26;
 (object[id].vertex+2)->z= 0.74;

 (object[id].vertex+3)->x=-2.12;
 (object[id].vertex+3)->y=-0.26;
 (object[id].vertex+3)->z= 0.74;

 (object[id].vertex+4)->x= 3.46;
 (object[id].vertex+4)->y=-0.61;
 (object[id].vertex+4)->z= 0.42;

 (object[id].vertex+5)->x= 3.46;
 (object[id].vertex+5)->y= 0.61;
 (object[id].vertex+5)->z= 0.42;
 
 (object[id].vertex+6)->x=-2.12;
 (object[id].vertex+6)->y= 0.61;
 (object[id].vertex+6)->z= 0.42;

 (object[id].vertex+7)->x=-2.12;
 (object[id].vertex+7)->y=-0.61;
 (object[id].vertex+7)->z= 0.42;

 (object[id].vertex+8)->x= 1.40;
 (object[id].vertex+8)->y= 0.61;
 (object[id].vertex+8)->z= 0.42;

 (object[id].vertex+9)->x= 1.40;
 (object[id].vertex+9)->y=-0.61;
 (object[id].vertex+9)->z= 0.42;

 (object[id].vertex+10)->x= 1.40;
 (object[id].vertex+10)->y= 1.11;
 (object[id].vertex+10)->z= 0.09;

 (object[id].vertex+11)->x= 1.40;
 (object[id].vertex+11)->y=-1.11;
 (object[id].vertex+11)->z= 0.09;

 (object[id].vertex+12)->x=-2.12;
 (object[id].vertex+12)->y= 1.11;
 (object[id].vertex+12)->z= 0.09;

 (object[id].vertex+13)->x=-2.12;
 (object[id].vertex+13)->y=-1.11;
 (object[id].vertex+13)->z= 0.09;

 (object[id].vertex+14)->x=-5.69;
 (object[id].vertex+14)->y=-1.11;
 (object[id].vertex+14)->z= 0.09;

 (object[id].vertex+15)->x=-5.69;
 (object[id].vertex+15)->y=-0.61;
 (object[id].vertex+15)->z= 0.42;

 (object[id].vertex+16)->x=-5.69;
 (object[id].vertex+16)->y= 0.61;
 (object[id].vertex+16)->z= 0.42;

 (object[id].vertex+17)->x=-5.69;
 (object[id].vertex+17)->y= 1.11;
 (object[id].vertex+17)->z= 0.09;

 // Wing
 (object[id].vertex+18)->x= 1.40;
 (object[id].vertex+18)->y= 1.11;
 (object[id].vertex+18)->z= 0;

 (object[id].vertex+19)->x= 1.40;
 (object[id].vertex+19)->y=-1.11;
 (object[id].vertex+19)->z= 0;

 (object[id].vertex+20)->x=-1.26;
 (object[id].vertex+20)->y= 1.11;
 (object[id].vertex+20)->z= 0;

 (object[id].vertex+21)->x=-1.26;
 (object[id].vertex+21)->y=-1.11;
 (object[id].vertex+21)->z= 0;

 (object[id].vertex+22)->x=-1.26;
 (object[id].vertex+22)->y= 2.50;
 (object[id].vertex+22)->z= 0;

 (object[id].vertex+23)->x=-1.26;
 (object[id].vertex+23)->y=-2.50;
 (object[id].vertex+23)->z= 0;

 (object[id].vertex+24)->x=-1.54;
 (object[id].vertex+24)->y=-2.50;
 (object[id].vertex+24)->z= 0;

 (object[id].vertex+25)->x=-1.54;
 (object[id].vertex+25)->y= 2.50;
 (object[id].vertex+25)->z= 0;

 (object[id].vertex+26)->x=-1.25;
 (object[id].vertex+26)->y= 3.38;
 (object[id].vertex+26)->z= 0;

 (object[id].vertex+27)->x=-1.25;
 (object[id].vertex+27)->y=-3.38;
 (object[id].vertex+27)->z= 0;

 (object[id].vertex+28)->x=-0.36;
 (object[id].vertex+28)->y= 3.38;
 (object[id].vertex+28)->z= 0;

 (object[id].vertex+29)->x=-0.36;
 (object[id].vertex+29)->y=-3.38;
 (object[id].vertex+29)->z= 0;

 // Body
 (object[id].vertex+30)->x=-2.12;
 (object[id].vertex+30)->y=-0.26;
 (object[id].vertex+30)->z=-0.74;

 (object[id].vertex+31)->x=-2.12;
 (object[id].vertex+31)->y= 0.26;
 (object[id].vertex+31)->z=-0.74;

 (object[id].vertex+32)->x= 3.46;
 (object[id].vertex+32)->y=-0.26;
 (object[id].vertex+32)->z=-0.74;

 (object[id].vertex+33)->x= 3.46;
 (object[id].vertex+33)->y= 0.26;
 (object[id].vertex+33)->z=-0.74;

 (object[id].vertex+34)->x=-2.12;
 (object[id].vertex+34)->y=-0.61;
 (object[id].vertex+34)->z=-0.42;

 (object[id].vertex+35)->x=-2.12;
 (object[id].vertex+35)->y= 0.61;
 (object[id].vertex+35)->z=-0.42;

 (object[id].vertex+36)->x= 3.46;
 (object[id].vertex+36)->y=-0.61;
 (object[id].vertex+36)->z=-0.42;

 (object[id].vertex+37)->x= 3.46;
 (object[id].vertex+37)->y= 0.61;
 (object[id].vertex+37)->z=-0.42;

 (object[id].vertex+38)->x=-2.12;
 (object[id].vertex+38)->y=-1.11;
 (object[id].vertex+38)->z=-0.09;

 (object[id].vertex+39)->x=-2.12;
 (object[id].vertex+39)->y= 1.11;
 (object[id].vertex+39)->z=-0.09;

 (object[id].vertex+40)->x= 1.40;
 (object[id].vertex+40)->y=-1.11;
 (object[id].vertex+40)->z=-0.09;

 (object[id].vertex+41)->x= 1.40;
 (object[id].vertex+41)->y= 1.11;
 (object[id].vertex+41)->z=-0.09;

 (object[id].vertex+42)->x= 1.40;
 (object[id].vertex+42)->y=-0.61;
 (object[id].vertex+42)->z=-0.42;

 (object[id].vertex+43)->x= 1.40;
 (object[id].vertex+43)->y= 0.61;
 (object[id].vertex+43)->z=-0.42;

 (object[id].vertex+44)->x= 3.46;
 (object[id].vertex+44)->y=-1.00;
 (object[id].vertex+44)->z= 0;

 (object[id].vertex+45)->x= 3.46;
 (object[id].vertex+45)->y= 1.00;
 (object[id].vertex+45)->z= 0;

 (object[id].vertex+46)->x= 6.19;
 (object[id].vertex+46)->y=-0.65;
 (object[id].vertex+46)->z= 0;

 (object[id].vertex+47)->x= 6.19;
 (object[id].vertex+47)->y= 0.65;
 (object[id].vertex+47)->z= 0;

 // Tail fin
 (object[id].vertex+48)->x=-2.12;
 (object[id].vertex+48)->y= 0;
 (object[id].vertex+48)->z= 0.74;

 (object[id].vertex+49)->x=-2.92;
 (object[id].vertex+49)->y= 0;
 (object[id].vertex+49)->z= 2.15;

 (object[id].vertex+50)->x=-5.49;
 (object[id].vertex+50)->y= 0.31;
 (object[id].vertex+50)->z= 0.74;

 (object[id].vertex+51)->x=-5.49;
 (object[id].vertex+51)->y=-0.31;
 (object[id].vertex+51)->z= 0.74;

 (object[id].vertex+52)->x=-5.49;
 (object[id].vertex+52)->y= 0.23;
 (object[id].vertex+52)->z= 2.15;

 (object[id].vertex+53)->x=-5.49;
 (object[id].vertex+53)->y=-0.23;
 (object[id].vertex+53)->z= 2.15;

 // Rocket 
 for (i=0; i<8; i++){
  float xc=-5.69, yc=0.00, zc=0.0, radius=0.33;

  (object[id].vertex+54+i)->x=xc;
  (object[id].vertex+54+i)->y=yc-radius*sin(i*PI/4+PI/8);
  (object[id].vertex+54+i)->z=zc+radius*cos(i*PI/4+PI/8);
 }

 (object[id].vertex+62)->x=-4.85;
 (object[id].vertex+62)->y= 0;
 (object[id].vertex+62)->z= 0;

 // Nose
 for (i=0; i<8; i++){
  float xc= 8.01, yc=0.00, zc=0.0, radius=0.52;

  (object[id].vertex+63+i)->x=xc;
  (object[id].vertex+63+i)->y=yc-radius*sin(i*PI/4+PI/8);
  (object[id].vertex+63+i)->z=zc+radius*cos(i*PI/4+PI/8);
 }

 (object[id].vertex+71)->x=10.05;
 (object[id].vertex+71)->y= 0;
 (object[id].vertex+71)->z= 0;

 for (i=0; i<6; i++){
  float xc= 6.19, yc=0.00, zc=0.0, radius=0.69;

  (object[id].vertex+72+i)->x=xc;
  (object[id].vertex+72+i)->y=yc-radius*sin(i*PI/4+3*PI/8);
  (object[id].vertex+72+i)->z=zc+radius*cos(i*PI/4+3*PI/8);
 }

 // Canopy
 (object[id].vertex+78)->x= 7.35;
 (object[id].vertex+78)->y= 0;
 (object[id].vertex+78)->z= 0.94;

 (object[id].vertex+79)->x= 6.79;
 (object[id].vertex+79)->y=-0.25;
 (object[id].vertex+79)->z= 0.94;

 (object[id].vertex+80)->x= 6.79;
 (object[id].vertex+80)->y= 0.25;
 (object[id].vertex+80)->z= 0.94;

 (object[id].vertex+81)->x= 8.01;
 (object[id].vertex+81)->y= 0;
 (object[id].vertex+81)->z= 0.48;

 (object[id].vertex+82)->x= 6.79;
 (object[id].vertex+82)->y= 0.38;
 (object[id].vertex+82)->z= 0.61;

 (object[id].vertex+83)->x= 6.79;
 (object[id].vertex+83)->y=-0.38;
 (object[id].vertex+83)->z= 0.61;

 (object[id].vertex+84)->x= 3.46;
 (object[id].vertex+84)->y= 0;
 (object[id].vertex+84)->z= 0.74;

 // Rear body
 (object[id].vertex+85)->x=-5.69;
 (object[id].vertex+85)->y= 1.05;
 (object[id].vertex+85)->z=-0.25;

 (object[id].vertex+86)->x=-5.69;
 (object[id].vertex+86)->y=-1.05;
 (object[id].vertex+86)->z=-0.25;

 (object[id].vertex+87)->x=-3.90;
 (object[id].vertex+87)->y= 1.05;
 (object[id].vertex+87)->z=-0.25;

 (object[id].vertex+88)->x=-3.90;
 (object[id].vertex+88)->y=-1.05;
 (object[id].vertex+88)->z=-0.25;

 (object[id].vertex+89)->x=-5.49;
 (object[id].vertex+89)->y= 0.29;
 (object[id].vertex+89)->z= 1.18;

 (object[id].vertex+90)->x=-5.49;
 (object[id].vertex+90)->y=-0.29;
 (object[id].vertex+90)->z= 1.18;

 (object[id].vertex+91)->x=-5.83;
 (object[id].vertex+91)->y= 0.35;
 (object[id].vertex+91)->z= 0.72;

 (object[id].vertex+92)->x=-5.83;
 (object[id].vertex+92)->y=-0.35;
 (object[id].vertex+92)->z= 0.72;

 (object[id].vertex+93)->x=-5.69;
 (object[id].vertex+93)->y= 0.33;
 (object[id].vertex+93)->z= 0.72;

 (object[id].vertex+94)->x=-5.69;
 (object[id].vertex+94)->y=-0.33;
 (object[id].vertex+94)->z= 0.72;

 (object[id].vertex+95)->x=-5.69;
 (object[id].vertex+95)->y= 0.56;
 (object[id].vertex+95)->z=-0.34;

 (object[id].vertex+96)->x=-5.69;
 (object[id].vertex+96)->y=-0.56;
 (object[id].vertex+96)->z=-0.34;

 (object[id].vertex+97)->x=-3.90;
 (object[id].vertex+97)->y= 0.56;
 (object[id].vertex+97)->z=-0.34;

 (object[id].vertex+98)->x=-3.90;
 (object[id].vertex+98)->y=-0.56;
 (object[id].vertex+98)->z=-0.34;

 // Belly fin
 (object[id].vertex+99)->x=-3.20;
 (object[id].vertex+99)->y= 0;
 (object[id].vertex+99)->z=-0.74;

 (object[id].vertex+100)->x=-4.41;
 (object[id].vertex+100)->y= 0.18;
 (object[id].vertex+100)->z=-0.68;

 (object[id].vertex+101)->x=-4.41;
 (object[id].vertex+101)->y=-0.18;
 (object[id].vertex+101)->z=-0.68;

 (object[id].vertex+102)->x=-3.20;
 (object[id].vertex+102)->y= 0;
 (object[id].vertex+102)->z=-1.17;

 (object[id].vertex+103)->x=-4.41;
 (object[id].vertex+103)->y= 0.18;
 (object[id].vertex+103)->z=-1.17;

 (object[id].vertex+104)->x=-4.41;
 (object[id].vertex+104)->y=-0.18;
 (object[id].vertex+104)->z=-1.17;

 (object[id].vertex+105)->x=-3.20;
 (object[id].vertex+105)->y= 0.26;
 (object[id].vertex+105)->z=-0.74;

 (object[id].vertex+106)->x=-3.20;
 (object[id].vertex+106)->y=-0.26;
 (object[id].vertex+106)->z=-0.74;

 (object[id].vertex+107)->x=-5.69;
 (object[id].vertex+107)->y= 0.30;
 (object[id].vertex+107)->z=-0.60;

 (object[id].vertex+108)->x=-5.69;
 (object[id].vertex+108)->y=-0.30;
 (object[id].vertex+108)->z=-0.60;

 (object[id].vertex+109)->x=-5.44;
 (object[id].vertex+109)->y= 0.28;
 (object[id].vertex+109)->z=-1.17;

 (object[id].vertex+110)->x=-5.44;
 (object[id].vertex+110)->y=-0.28;
 (object[id].vertex+110)->z=-1.17;

 // Flaps
 (object[id].vertex+111)->x=-1.98;
 (object[id].vertex+111)->y= 1.11;
 (object[id].vertex+111)->z= 0;

 (object[id].vertex+112)->x=-1.98;
 (object[id].vertex+112)->y=-1.11;
 (object[id].vertex+112)->z= 0;

 // Air brakes
 (object[id].vertex+113)->x=-5.44;
 (object[id].vertex+113)->y= 0.28;
 (object[id].vertex+113)->z=-0.63;

 (object[id].vertex+114)->x=-5.44;
 (object[id].vertex+114)->y=-0.28;
 (object[id].vertex+114)->z=-0.63;

 // Tail plane
 (object[id].vertex+115)->x=-3.06;
 (object[id].vertex+115)->y= 1.08;
 (object[id].vertex+115)->z= 0;

 (object[id].vertex+116)->x=-3.06;
 (object[id].vertex+116)->y=-1.08;
 (object[id].vertex+116)->z= 0;

 (object[id].vertex+117)->x=-5.21;
 (object[id].vertex+117)->y= 1.08;
 (object[id].vertex+117)->z= 0;

 (object[id].vertex+118)->x=-5.21;
 (object[id].vertex+118)->y=-1.08;
 (object[id].vertex+118)->z= 0;

 (object[id].vertex+119)->x=-5.17;
 (object[id].vertex+119)->y= 2.77;
 (object[id].vertex+119)->z=-0.65;

 (object[id].vertex+120)->x=-5.17;
 (object[id].vertex+120)->y=-2.77;
 (object[id].vertex+120)->z=-0.65;

 (object[id].vertex+121)->x=-5.88;
 (object[id].vertex+121)->y= 2.77;
 (object[id].vertex+121)->z=-0.65;

 (object[id].vertex+122)->x=-5.88;
 (object[id].vertex+122)->y=-2.77;
 (object[id].vertex+122)->z=-0.65;

 // Fuel dump
 (object[id].vertex+123)->x=-6.37;
 (object[id].vertex+123)->y= 1.05;
 (object[id].vertex+123)->z=-0.25;

 (object[id].vertex+124)->x=-6.37;
 (object[id].vertex+124)->y=-1.05;
 (object[id].vertex+124)->z=-0.25;

 (object[id].vertex+125)->x=-6.37;
 (object[id].vertex+125)->y= 0.94;
 (object[id].vertex+125)->z=-0.11;

 (object[id].vertex+126)->x=-6.37;
 (object[id].vertex+126)->y=-0.94;
 (object[id].vertex+126)->z=-0.11;

 (object[id].vertex+127)->x=-5.69;
 (object[id].vertex+127)->y= 0.94;
 (object[id].vertex+127)->z=-0.11;

 (object[id].vertex+128)->x=-5.69;
 (object[id].vertex+128)->y=-0.94;
 (object[id].vertex+128)->z=-0.11;

 /* Nose wheel */
 for (i=0; i<8; i++){
  float xc=8.56, yc= 0.00, zc=-1.00, radius=0.19;

  (object[id].vertex+129+i)->x=xc+radius*sin(i*PI/4+PI/8);
  (object[id].vertex+129+i)->y=yc;
  (object[id].vertex+129+i)->z=zc+radius*cos(i*PI/4+PI/8);
 }

 (object[id].vertex+137)->x= 8.46;
 (object[id].vertex+137)->y= 0.00;
 (object[id].vertex+137)->z=-0.40;

 (object[id].vertex+138)->x= 8.36;
 (object[id].vertex+138)->y= 0.00;
 (object[id].vertex+138)->z=-0.40;

 (object[id].vertex+139)->x= 8.51;
 (object[id].vertex+139)->y= 0.00;
 (object[id].vertex+139)->z=-0.95;

 (object[id].vertex+140)->x= 8.61;
 (object[id].vertex+140)->y= 0.00;
 (object[id].vertex+140)->z=-0.95;

 // Skids
 (object[id].vertex+141)->x=-3.62;
 (object[id].vertex+141)->y= 1.15;
 (object[id].vertex+141)->z=-1.52;

 (object[id].vertex+142)->x=-3.62;
 (object[id].vertex+142)->y= 1.00;
 (object[id].vertex+142)->z=-1.52;

 (object[id].vertex+143)->x=-3.62;
 (object[id].vertex+143)->y=-1.00;
 (object[id].vertex+143)->z=-1.52;

 (object[id].vertex+144)->x=-3.62;
 (object[id].vertex+144)->y=-1.15;
 (object[id].vertex+144)->z=-1.52;

 (object[id].vertex+145)->x=-5.20;
 (object[id].vertex+145)->y= 1.15;
 (object[id].vertex+145)->z=-1.58;

 (object[id].vertex+146)->x=-5.20;
 (object[id].vertex+146)->y= 1.00;
 (object[id].vertex+146)->z=-1.58;

 (object[id].vertex+147)->x=-5.20;
 (object[id].vertex+147)->y=-1.00;
 (object[id].vertex+147)->z=-1.58;

 (object[id].vertex+148)->x=-5.20;
 (object[id].vertex+148)->y=-1.15;
 (object[id].vertex+148)->z=-1.58;

 (object[id].vertex+149)->x=-4.41;
 (object[id].vertex+149)->y= 1.15;
 (object[id].vertex+149)->z=-1.55;

 (object[id].vertex+150)->x=-4.46;
 (object[id].vertex+150)->y= 1.00;
 (object[id].vertex+150)->z=-1.55;

 (object[id].vertex+151)->x=-4.46;
 (object[id].vertex+151)->y=-1.00;
 (object[id].vertex+151)->z=-1.55;

 (object[id].vertex+152)->x=-4.41;
 (object[id].vertex+152)->y=-1.15;
 (object[id].vertex+152)->z=-1.55;

 (object[id].vertex+153)->x=-4.41;
 (object[id].vertex+153)->y= 0.62;
 (object[id].vertex+153)->z=-0.50;

 (object[id].vertex+154)->x=-4.46;
 (object[id].vertex+154)->y= 0.52;
 (object[id].vertex+154)->z=-0.50;

 (object[id].vertex+155)->x=-4.46;
 (object[id].vertex+155)->y=-0.52;
 (object[id].vertex+155)->z=-0.50;

 (object[id].vertex+156)->x=-4.41;
 (object[id].vertex+156)->y=-0.62;
 (object[id].vertex+156)->z=-0.50;

 
 /*
 (object[id].vertex+)->x=;
 (object[id].vertex+)->y=;
 (object[id].vertex+)->z=;
 */

 /*
 for (i=0; i<8; i++){
  float xc=-6.74, yc=0.00, zc=0.33, radius=0.52;

  (object[id].vertex+25+i)->x=xc+radius;
  (object[id].vertex+25+i)->y=yc-radius*sin(i*PI/4+PI/8);
  (object[id].vertex+25+i)->z=zc+radius*cos(i*PI/4+PI/8);
 }
 */

 /**********/
 /* Facets */
 /**********/

 //Body
 facetid->color=DARKGRAY;
 facetid->nedges=4;
 facetid->edge[0]=0;
 facetid->edge[1]=1;
 facetid->edge[2]=2;
 facetid->edge[3]=3;
 facetid++;
 
 facetid->color=DARKGRAY;
 facetid->nedges=4;
 facetid->edge[0]=4;
 facetid->edge[1]=0;
 facetid->edge[2]=3;
 facetid->edge[3]=7;
 facetid++;

 facetid->color=DARKGRAY;
 facetid->nedges=4;
 facetid->edge[0]=1;
 facetid->edge[1]=5;
 facetid->edge[2]=6;
 facetid->edge[3]=2;
 facetid++;

 facetid->color=DARKGRAY;
 facetid->nedges=4;
 facetid->edge[0]=8;
 facetid->edge[1]=10;
 facetid->edge[2]=12;
 facetid->edge[3]=6;
 facetid++;

 facetid->color=DARKGRAY;
 facetid->nedges=4;
 facetid->edge[0]=11;
 facetid->edge[1]=9;
 facetid->edge[2]=7;
 facetid->edge[3]=13;
 facetid++;

 facetid->color=DARKGRAY;
 facetid->nedges=4;
 facetid->edge[0]=14;
 facetid->edge[1]=13;
 facetid->edge[2]=7;
 facetid->edge[3]=15;
 facetid++;

 facetid->color=DARKGRAY;
 facetid->nedges=4;
 facetid->edge[0]=16;
 facetid->edge[1]=6;
 facetid->edge[2]=12;
 facetid->edge[3]=17;
 facetid++;

 //Wings
 facetid->color=DARKGRAY;
 facetid->nedges=6;
 facetid->edge[0]=29;
 facetid->edge[1]=19;
 facetid->edge[2]=21;
 facetid->edge[3]=23;
 facetid->edge[4]=24;
 facetid->edge[5]=27;
 facetid++;

 facetid->color=DARKGRAY;
 facetid->nedges=6;
 facetid->edge[0]=29;
 facetid->edge[1]=27;
 facetid->edge[2]=24;
 facetid->edge[3]=23;
 facetid->edge[4]=21;
 facetid->edge[5]=19;
 facetid++;

 facetid->color=DARKGRAY;
 facetid->nedges=6;
 facetid->edge[0]=18;
 facetid->edge[1]=28;
 facetid->edge[2]=26;
 facetid->edge[3]=25;
 facetid->edge[4]=22;
 facetid->edge[5]=20;
 facetid++;

 facetid->color=DARKGRAY;
 facetid->nedges=6;
 facetid->edge[0]=18;
 facetid->edge[1]=20;
 facetid->edge[2]=22;
 facetid->edge[3]=25;
 facetid->edge[4]=26;
 facetid->edge[5]=28;
 facetid++;

 //Body
 facetid->color=DARKGRAY;
 facetid->nedges=4;
 facetid->edge[0]=30;
 facetid->edge[1]=31;
 facetid->edge[2]=33;
 facetid->edge[3]=32;
 facetid++;

 facetid->color=DARKGRAY;
 facetid->nedges=4;
 facetid->edge[0]=31;
 facetid->edge[1]=35;
 facetid->edge[2]=37;
 facetid->edge[3]=33;
 facetid++;

 facetid->color=DARKGRAY;
 facetid->nedges=4;
 facetid->edge[0]=34;
 facetid->edge[1]=30;
 facetid->edge[2]=32;
 facetid->edge[3]=36;
 facetid++;

 facetid->color=DARKGRAY;
 facetid->nedges=4;
 facetid->edge[0]=38;
 facetid->edge[1]=34;
 facetid->edge[2]=42;
 facetid->edge[3]=40;
 facetid++;

 facetid->color=DARKGRAY;
 facetid->nedges=4;
 facetid->edge[0]=35;
 facetid->edge[1]=39;
 facetid->edge[2]=41;
 facetid->edge[3]=43;
 facetid++;

 facetid->color=DARKGRAY;
 facetid->nedges=4;
 facetid->edge[0]=39;
 facetid->edge[1]=12;
 facetid->edge[2]=10;
 facetid->edge[3]=41;
 facetid++;

 facetid->color=DARKGRAY;
 facetid->nedges=4;
 facetid->edge[0]=38;
 facetid->edge[1]=40;
 facetid->edge[2]=11;
 facetid->edge[3]=13;
 facetid++;

 facetid->color=DARKGRAY;
 facetid->nedges=3;
 facetid->edge[0]=41;
 facetid->edge[1]=10;
 facetid->edge[2]=45;
 facetid++;

 facetid->color=DARKGRAY;
 facetid->nedges=3;
 facetid->edge[0]=44;
 facetid->edge[1]=11;
 facetid->edge[2]=40;
 facetid++;

 facetid->color=DARKGRAY;
 facetid->nedges=3;
 facetid->edge[0]=10;
 facetid->edge[1]=8;
 facetid->edge[2]=5;
 facetid++;

 facetid->color=DARKGRAY;
 facetid->nedges=3;
 facetid->edge[0]=9;
 facetid->edge[1]=11;
 facetid->edge[2]=4;
 facetid++;

 facetid->color=DARKGRAY;
 facetid->nedges=3;
 facetid->edge[0]=5;
 facetid->edge[1]=45;
 facetid->edge[2]=10;
 facetid++;

 facetid->color=DARKGRAY;
 facetid->nedges=3;
 facetid->edge[0]=44;
 facetid->edge[1]=4;
 facetid->edge[2]=11;
 facetid++;

 facetid->color=DARKGRAY;
 facetid->nedges=3;
 facetid->edge[0]=43;
 facetid->edge[1]=41;
 facetid->edge[2]=37;
 facetid++;

 facetid->color=DARKGRAY;
 facetid->nedges=3;
 facetid->edge[0]=40;
 facetid->edge[1]=42;
 facetid->edge[2]=36;
 facetid++;

 facetid->color=DARKGRAY;
 facetid->nedges=3;
 facetid->edge[0]=45;
 facetid->edge[1]=37;
 facetid->edge[2]=41;
 facetid++;

 facetid->color=DARKGRAY;
 facetid->nedges=3;
 facetid->edge[0]=44;
 facetid->edge[1]=40;
 facetid->edge[2]=36;
 facetid++;

 facetid->color=DARKGRAY;
 facetid->nedges=3;
 facetid->edge[0]=45;
 facetid->edge[1]=5;
 facetid->edge[2]=47;
 facetid++;

 facetid->color=DARKGRAY;
 facetid->nedges=3;
 facetid->edge[0]=4;
 facetid->edge[1]=44;
 facetid->edge[2]=46;
 facetid++;

 facetid->color=DARKGRAY;
 facetid->nedges=3;
 facetid->edge[0]=37;
 facetid->edge[1]=45;
 facetid->edge[2]=47;
 facetid++;

 facetid->color=DARKGRAY;
 facetid->nedges=3;
 facetid->edge[0]=44;
 facetid->edge[1]=36;
 facetid->edge[2]=46;
 facetid++;

 facetid->color=DARKGRAY;
 facetid->nedges=4;
 facetid->edge[0]=50;
 facetid->edge[1]=48;
 facetid->edge[2]= 2;
 facetid->edge[3]=93;
 facetid++;

 facetid->color=DARKGRAY;
 facetid->nedges=4;
 facetid->edge[0]=94;
 facetid->edge[1]= 3;
 facetid->edge[2]=48;
 facetid->edge[3]=51;
 facetid++;

 // Tail fin
 facetid->color=DARKGRAY;
 facetid->nedges=3;
 facetid->edge[0]=49;
 facetid->edge[1]=52;
 facetid->edge[2]=53;
 facetid++;

 facetid->color=LIGHTGRAY;
 facetid->nedges=4;
 facetid->edge[0]=89;
 facetid->edge[1]=90;
 facetid->edge[2]=53;
 facetid->edge[3]=52;
 facetid++;

 facetid->color=DARKGRAY;
 facetid->nedges=4;
 facetid->edge[0]=52;
 facetid->edge[1]=49;
 facetid->edge[2]=48;
 facetid->edge[3]=50;
 facetid++;

 facetid->color=DARKGRAY;
 facetid->nedges=4;
 facetid->edge[0]=48;
 facetid->edge[1]=49;
 facetid->edge[2]=53;
 facetid->edge[3]=51;
 facetid++;

 //Rocket
 facetid->color=LIGHTGRAY;
 facetid->nedges=3;
 facetid->edge[0]=55;
 facetid->edge[1]=54;
 facetid->edge[2]=62;
 facetid++;

 facetid->color=LIGHTGRAY;
 facetid->nedges=3;
 facetid->edge[0]=56;
 facetid->edge[1]=55;
 facetid->edge[2]=62;
 facetid++;

 facetid->color=LIGHTGRAY;
 facetid->nedges=3;
 facetid->edge[0]=57;
 facetid->edge[1]=56;
 facetid->edge[2]=62;
 facetid++;

 facetid->color=LIGHTGRAY;
 facetid->nedges=3;
 facetid->edge[0]=58;
 facetid->edge[1]=57;
 facetid->edge[2]=62;
 facetid++;

 facetid->color=LIGHTGRAY;
 facetid->nedges=3;
 facetid->edge[0]=59;
 facetid->edge[1]=58;
 facetid->edge[2]=62;
 facetid++;

 facetid->color=LIGHTGRAY;
 facetid->nedges=3;
 facetid->edge[0]=60;
 facetid->edge[1]=59;
 facetid->edge[2]=62;
 facetid++;

 facetid->color=LIGHTGRAY;
 facetid->nedges=3;
 facetid->edge[0]=61;
 facetid->edge[1]=60;
 facetid->edge[2]=62;
 facetid++;

 facetid->color=LIGHTGRAY;
 facetid->nedges=3;
 facetid->edge[0]=54;
 facetid->edge[1]=61;
 facetid->edge[2]=62;
 facetid++;

 // Nose
 facetid->color=DARKGRAY;
 facetid->nedges=3;
 facetid->edge[0]=63;
 facetid->edge[1]=64;
 facetid->edge[2]=71;
 facetid++;

 facetid->color=DARKGRAY;
 facetid->nedges=3;
 facetid->edge[0]=64;
 facetid->edge[1]=65;
 facetid->edge[2]=71;
 facetid++;

 facetid->color=DARKGRAY;
 facetid->nedges=3;
 facetid->edge[0]=65;
 facetid->edge[1]=66;
 facetid->edge[2]=71;
 facetid++;

 facetid->color=DARKGRAY;
 facetid->nedges=3;
 facetid->edge[0]=66;
 facetid->edge[1]=67;
 facetid->edge[2]=71;
 facetid++;

 facetid->color=DARKGRAY;
 facetid->nedges=3;
 facetid->edge[0]=67;
 facetid->edge[1]=68;
 facetid->edge[2]=71;
 facetid++;

 facetid->color=DARKGRAY;
 facetid->nedges=3;
 facetid->edge[0]=68;
 facetid->edge[1]=69;
 facetid->edge[2]=71;
 facetid++;

 facetid->color=DARKGRAY;
 facetid->nedges=3;
 facetid->edge[0]=69;
 facetid->edge[1]=70;
 facetid->edge[2]=71;
 facetid++;

 facetid->color=DARKGRAY;
 facetid->nedges=3;
 facetid->edge[0]=70;
 facetid->edge[1]=63;
 facetid->edge[2]=71;
 facetid++;

 facetid->color=DARKGRAY;
 facetid->nedges=4;
 facetid->edge[0]=65;
 facetid->edge[1]=64;
 facetid->edge[2]=72;
 facetid->edge[3]=73;
 facetid++;

 facetid->color=DARKGRAY;
 facetid->nedges=4;
 facetid->edge[0]=66;
 facetid->edge[1]=65;
 facetid->edge[2]=73;
 facetid->edge[3]=74;
 facetid++;

 facetid->color=DARKGRAY;
 facetid->nedges=4;
 facetid->edge[0]=67;
 facetid->edge[1]=66;
 facetid->edge[2]=74;
 facetid->edge[3]=75;
 facetid++;

 facetid->color=DARKGRAY;
 facetid->nedges=4;
 facetid->edge[0]=68;
 facetid->edge[1]=67;
 facetid->edge[2]=75;
 facetid->edge[3]=76;
 facetid++;

 facetid->color=DARKGRAY;
 facetid->nedges=4;
 facetid->edge[0]=69;
 facetid->edge[1]=68;
 facetid->edge[2]=76;
 facetid->edge[3]=77;
 facetid++;

 facetid->color=DARKGRAY;
 facetid->nedges=4;
 facetid->edge[0]=32;
 facetid->edge[1]=33;
 facetid->edge[2]=75;
 facetid->edge[3]=74;
 facetid++;

 facetid->color=DARKGRAY;
 facetid->nedges=4;
 facetid->edge[0]=33;
 facetid->edge[1]=37;
 facetid->edge[2]=76;
 facetid->edge[3]=75;
 facetid++;

 facetid->color=DARKGRAY;
 facetid->nedges=4;
 facetid->edge[0]=36;
 facetid->edge[1]=32;
 facetid->edge[2]=74;
 facetid->edge[3]=73;
 facetid++;

 facetid->color=DARKGRAY;
 facetid->nedges=3;
 facetid->edge[0]=5;
 facetid->edge[1]=77;
 facetid->edge[2]=47;
 facetid++;

 facetid->color=DARKGRAY;
 facetid->nedges=3;
 facetid->edge[0]=4;
 facetid->edge[1]=46;
 facetid->edge[2]=72;
 facetid++;

 facetid->color=DARKGRAY;
 facetid->nedges=3;
 facetid->edge[0]=37;
 facetid->edge[1]=47;
 facetid->edge[2]=76;
 facetid++;

 facetid->color=DARKGRAY;
 facetid->nedges=3;
 facetid->edge[0]=36;
 facetid->edge[1]=73;
 facetid->edge[2]=46;
 facetid++;

 // Canopy
 facetid->color=DARKGRAY;
 facetid->nedges=3;
 facetid->edge[0]=79;
 facetid->edge[1]=78;
 facetid->edge[2]=80;
 facetid++;

 facetid->color=DARKGRAY;
 facetid->nedges=3;
 facetid->edge[0]=80;
 facetid->edge[1]=78;
 facetid->edge[2]=81;
 facetid++;

 facetid->color=DARKGRAY;
 facetid->nedges=3;
 facetid->edge[0]=79;
 facetid->edge[1]=81;
 facetid->edge[2]=78;
 facetid++;

 facetid->color=DARKGRAY;
 facetid->nedges=3;
 facetid->edge[0]=82;
 facetid->edge[1]=80;
 facetid->edge[2]=81;
 facetid++;

 facetid->color=DARKGRAY;
 facetid->nedges=3;
 facetid->edge[0]=79;
 facetid->edge[1]=83;
 facetid->edge[2]=81;
 facetid++;

 facetid->color=DARKGRAY;
 facetid->nedges=3;
 facetid->edge[0]=84;
 facetid->edge[1]=83;
 facetid->edge[2]=79;
 facetid++;

 facetid->color=DARKGRAY;
 facetid->nedges=3;
 facetid->edge[0]=84;
 facetid->edge[1]=79;
 facetid->edge[2]=80;
 facetid++;

 facetid->color=DARKGRAY;
 facetid->nedges=3;
 facetid->edge[0]=84;
 facetid->edge[1]=80;
 facetid->edge[2]=82;
 facetid++;

 facetid->color=DARKGRAY;
 facetid->nedges=3;
 facetid->edge[0]=1;
 facetid->edge[1]=84;
 facetid->edge[2]=82;
 facetid++;

 facetid->color=DARKGRAY;
 facetid->nedges=3;
 facetid->edge[0]=84;
 facetid->edge[1]=0;
 facetid->edge[2]=83;
 facetid++;

 facetid->color=DARKGRAY;
 facetid->nedges=3;
 facetid->edge[0]=82;
 facetid->edge[1]=81;
 facetid->edge[2]=70;
 facetid++;

 facetid->color=DARKGRAY;
 facetid->nedges=3;
 facetid->edge[0]=83;
 facetid->edge[1]=63;
 facetid->edge[2]=81;
 facetid++;

 facetid->color=DARKGRAY;
 facetid->nedges=3;
 facetid->edge[0]=82;
 facetid->edge[1]=70;
 facetid->edge[2]=69;
 facetid++;

 facetid->color=DARKGRAY;
 facetid->nedges=3;
 facetid->edge[0]=83;
 facetid->edge[1]=64;
 facetid->edge[2]=63;
 facetid++;

 facetid->color=DARKGRAY;
 facetid->nedges=3;
 facetid->edge[0]=77;
 facetid->edge[1]=82;
 facetid->edge[2]=69;
 facetid++;

 facetid->color=DARKGRAY;
 facetid->nedges=3;
 facetid->edge[0]=83;
 facetid->edge[1]=72;
 facetid->edge[2]=64;
 facetid++;

 facetid->color=DARKGRAY;
 facetid->nedges=3;
 facetid->edge[0]=5;
 facetid->edge[1]=1;
 facetid->edge[2]=82;
 facetid++;

 facetid->color=DARKGRAY;
 facetid->nedges=3;
 facetid->edge[0]=5;
 facetid->edge[1]=82;
 facetid->edge[2]=77;
 facetid++;

 facetid->color=DARKGRAY;
 facetid->nedges=3;
 facetid->edge[0]=0;
 facetid->edge[1]=4;
 facetid->edge[2]=83;
 facetid++;

 facetid->color=DARKGRAY;
 facetid->nedges=3;
 facetid->edge[0]=4;
 facetid->edge[1]=72;
 facetid->edge[2]=83;
 facetid++;

 // Rear body
 facetid->color=DARKGRAY;
 facetid->nedges=4;
 facetid->edge[0]=85;
 facetid->edge[1]=17;
 facetid->edge[2]=12;
 facetid->edge[3]=87;
 facetid++;

 facetid->color=DARKGRAY;
 facetid->nedges=4;
 facetid->edge[0]=14;
 facetid->edge[1]=86;
 facetid->edge[2]=88;
 facetid->edge[3]=13;
 facetid++;

 facetid->color=DARKGRAY;
 facetid->nedges=3;
 facetid->edge[0]=88;
 facetid->edge[1]=38;
 facetid->edge[2]=13;
 facetid++;

 facetid->color=DARKGRAY;
 facetid->nedges=3;
 facetid->edge[0]=87;
 facetid->edge[1]=12;
 facetid->edge[2]=39;
 facetid++;

 facetid->color=LIGHTGRAY;
 facetid->nedges=4;
 facetid->edge[0]=90;
 facetid->edge[1]=89;
 facetid->edge[2]=91;
 facetid->edge[3]=92;
 facetid++;

 facetid->color=DARKGRAY;
 facetid->nedges=3;
 facetid->edge[0]=91;
 facetid->edge[1]=89;
 facetid->edge[2]=50;
 facetid++;

 facetid->color=DARKGRAY;
 facetid->nedges=3;
 facetid->edge[0]=51;
 facetid->edge[1]=90;
 facetid->edge[2]=92;
 facetid++;

 facetid->color=DARKGRAY;
 facetid->nedges=3;
 facetid->edge[0]=2;
 facetid->edge[1]=6;
 facetid->edge[2]=16;
 facetid++;

 facetid->color=DARKGRAY;
 facetid->nedges=3;
 facetid->edge[0]=15;
 facetid->edge[1]=7;
 facetid->edge[2]=3;
 facetid++;

 facetid->color=DARKGRAY;
 facetid->nedges=3;
 facetid->edge[0]=16;
 facetid->edge[1]=93;
 facetid->edge[2]=2;
 facetid++;

 facetid->color=DARKGRAY;
 facetid->nedges=3;
 facetid->edge[0]=94;
 facetid->edge[1]=15;
 facetid->edge[2]=3;
 facetid++;

 facetid->color=DARKGRAY;
 facetid->nedges=4;
 facetid->edge[0]=95;
 facetid->edge[1]=85;
 facetid->edge[2]=87;
 facetid->edge[3]=97;
 facetid++;

 facetid->color=DARKGRAY;
 facetid->nedges=4;
 facetid->edge[0]=86;
 facetid->edge[1]=96;
 facetid->edge[2]=98;
 facetid->edge[3]=88;
 facetid++;

 facetid->color=DARKGRAY;
 facetid->nedges=3;
 facetid->edge[0]=34;
 facetid->edge[1]=38;
 facetid->edge[2]=98;
 facetid++;

 facetid->color=DARKGRAY;
 facetid->nedges=3;
 facetid->edge[0]=98;
 facetid->edge[1]=38;
 facetid->edge[2]=88;
 facetid++;

 facetid->color=DARKGRAY;
 facetid->nedges=3;
 facetid->edge[0]=97;
 facetid->edge[1]=39;
 facetid->edge[2]=35;
 facetid++;

 facetid->color=DARKGRAY;
 facetid->nedges=3;
 facetid->edge[0]=97;
 facetid->edge[1]=87;
 facetid->edge[2]=39;
 facetid++;

 // Belly fin
 facetid->color=DARKGRAY;
 facetid->nedges=3;
 facetid->edge[0]=104;
 facetid->edge[1]=103;
 facetid->edge[2]=102;
 facetid++;

 facetid->color=DARKGRAY;
 facetid->nedges=4;
 facetid->edge[0]=101;
 facetid->edge[1]=100;
 facetid->edge[2]=103;
 facetid->edge[3]=104;
 facetid++;

 facetid->color=DARKGRAY;
 facetid->nedges=4;
 facetid->edge[0]=100;
 facetid->edge[1]=99;
 facetid->edge[2]=102;
 facetid->edge[3]=103;
 facetid++;

 facetid->color=DARKGRAY;
 facetid->nedges=4;
 facetid->edge[0]=99;
 facetid->edge[1]=101;
 facetid->edge[2]=104;
 facetid->edge[3]=102;
 facetid++;

 facetid->color=DARKGRAY;
 facetid->nedges=4;
 facetid->edge[0]=106;
 facetid->edge[1]=105;
 facetid->edge[2]=31;
 facetid->edge[3]=30;
 facetid++;

 facetid->color=DARKGRAY;
 facetid->nedges=3;
 facetid->edge[0]=100;
 facetid->edge[1]=105;
 facetid->edge[2]=99;
 facetid++;

 facetid->color=DARKGRAY;
 facetid->nedges=3;
 facetid->edge[0]=101;
 facetid->edge[1]=99;
 facetid->edge[2]=106;
 facetid++;

 facetid->color=DARKGRAY;
 facetid->nedges=4;
 facetid->edge[0]=107;
 facetid->edge[1]=100;
 facetid->edge[2]=101;
 facetid->edge[3]=108;
 facetid++;

 facetid->color=DARKGRAY;
 facetid->nedges=3;
 facetid->edge[0]=35;
 facetid->edge[1]=31;
 facetid->edge[2]=105;
 facetid++;

 facetid->color=DARKGRAY;
 facetid->nedges=3;
 facetid->edge[0]=30;
 facetid->edge[1]=34;
 facetid->edge[2]=106;
 facetid++;

 facetid->color=DARKGRAY;
 facetid->nedges=3;
 facetid->edge[0]=97;
 facetid->edge[1]=35;
 facetid->edge[2]=105;
 facetid++;

 facetid->color=DARKGRAY;
 facetid->nedges=3;
 facetid->edge[0]=34;
 facetid->edge[1]=98;
 facetid->edge[2]=106;
 facetid++;

 facetid->color=DARKGRAY;
 facetid->nedges=3;
 facetid->edge[0]=100;
 facetid->edge[1]=97;
 facetid->edge[2]=105;
 facetid++;

 facetid->color=DARKGRAY;
 facetid->nedges=3;
 facetid->edge[0]=101;
 facetid->edge[1]=106;
 facetid->edge[2]=98;
 facetid++;

 facetid->color=DARKGRAY;
 facetid->nedges=3;
 facetid->edge[0]=107;
 facetid->edge[1]=95;
 facetid->edge[2]=97;
 facetid++;

 facetid->color=DARKGRAY;
 facetid->nedges=3;
 facetid->edge[0]=96;
 facetid->edge[1]=108;
 facetid->edge[2]=98;
 facetid++;

 facetid->color=DARKGRAY;
 facetid->nedges=3;
 facetid->edge[0]=107;
 facetid->edge[1]=97;
 facetid->edge[2]=100;
 facetid++;

 facetid->color=DARKGRAY;
 facetid->nedges=3;
 facetid->edge[0]=108;
 facetid->edge[1]=101;
 facetid->edge[2]=98;
 facetid++;

 // Rear #122
 facetid->color=DARKGRAY;
 facetid->nedges=8;
 facetid->edge[0]=94;
 facetid->edge[1]=93;
 facetid->edge[2]=16;
 facetid->edge[3]=60;
 facetid->edge[4]=61;
 facetid->edge[5]=54;
 facetid->edge[6]=55;
 facetid->edge[7]=15;
 facetid++;

 facetid->color=DARKGRAY;
 facetid->nedges=7;
 facetid->edge[0]=60;
 facetid->edge[1]=16;
 facetid->edge[2]=17;
 facetid->edge[3]=85;
 facetid->edge[4]=95;
 facetid->edge[5]=58;
 facetid->edge[6]=59;
 facetid++;

 facetid->color=DARKGRAY;
 facetid->nedges=7;
 facetid->edge[0]=96;
 facetid->edge[1]=86;
 facetid->edge[2]=14;
 facetid->edge[3]=15;
 facetid->edge[4]=55;
 facetid->edge[5]=56;
 facetid->edge[6]=57;
 facetid++;

 facetid->color=DARKGRAY;
 facetid->nedges=6;
 facetid->edge[0]=57;
 facetid->edge[1]=58;
 facetid->edge[2]=95;
 facetid->edge[3]=107;
 facetid->edge[4]=108;
 facetid->edge[5]=96;
 facetid++;

 facetid->color=DARKGRAY;
 facetid->nedges=4;
 facetid->edge[0]=93;
 facetid->edge[1]=94;
 facetid->edge[2]=92;
 facetid->edge[3]=91;
 facetid++;

 facetid->color=DARKGRAY;
 facetid->nedges=4;
 facetid->edge[0]=109;
 facetid->edge[1]=110;
 facetid->edge[2]=104;
 facetid->edge[3]=103;
 facetid++;

 facetid->color=DARKGRAY;
 facetid->nedges=4;
 facetid->edge[0]=109;
 facetid->edge[1]=103;
 facetid->edge[2]=104;
 facetid->edge[3]=110;
 facetid++;

 // Air brakes, retracted
 facetid->color=DARKGRAY;
 facetid->nedges=4;
 facetid->edge[0]=109;
 facetid->edge[1]=113;
 facetid->edge[2]=100;
 facetid->edge[3]=103;
 facetid++;

 facetid->color=DARKGRAY;
 facetid->nedges=4;
 facetid->edge[0]=109;
 facetid->edge[1]=103;
 facetid->edge[2]=100;
 facetid->edge[3]=113;
 facetid++;

 facetid->color=DARKGRAY;
 facetid->nedges=4;
 facetid->edge[0]=110;
 facetid->edge[1]=114;
 facetid->edge[2]=101;
 facetid->edge[3]=104;
 facetid++;

 facetid->color=DARKGRAY;
 facetid->nedges=4;
 facetid->edge[0]=110;
 facetid->edge[1]=104;
 facetid->edge[2]=101;
 facetid->edge[3]=114;
 facetid++;

 // Fuel dump
 facetid->color=DARKGRAY;
 facetid->nedges=4;
 facetid->edge[0]=123;
 facetid->edge[1]=125;
 facetid->edge[2]=127;
 facetid->edge[3]=85;
 facetid++;

 facetid->color=DARKGRAY;
 facetid->nedges=4;
 facetid->edge[0]=123;
 facetid->edge[1]=85;
 facetid->edge[2]=127;
 facetid->edge[3]=125;
 facetid++;

 facetid->color=DARKGRAY;
 facetid->nedges=4;
 facetid->edge[0]=124;
 facetid->edge[1]=86;
 facetid->edge[2]=128;
 facetid->edge[3]=126;
 facetid++;

 facetid->color=DARKGRAY;
 facetid->nedges=4;
 facetid->edge[0]=124;
 facetid->edge[1]=126;
 facetid->edge[2]=128;
 facetid->edge[3]=86;
 facetid++;

 /* Control surfaces below */

 // 137 Flaps
 facetid->color=DARKGRAY;
 facetid->nedges=4;
 facetid->edge[0]=111;
 facetid->edge[1]=20;
 facetid->edge[2]=22;
 facetid->edge[3]=25;
 facetid++;

 facetid->color=DARKGRAY;
 facetid->nedges=4;
 facetid->edge[0]=111;
 facetid->edge[1]=25;
 facetid->edge[2]=22;
 facetid->edge[3]=20;
 facetid++;

 facetid->color=DARKGRAY;
 facetid->nedges=4;
 facetid->edge[0]=23;
 facetid->edge[1]=21;
 facetid->edge[2]=112;
 facetid->edge[3]=24;
 facetid++;

 facetid->color=DARKGRAY;
 facetid->nedges=4;
 facetid->edge[0]=23;
 facetid->edge[1]=24;
 facetid->edge[2]=112;
 facetid->edge[3]=21;
 facetid++;

 // Air brakes
 facetid->color=DARKGRAY;
 facetid->nedges=4;
 facetid->edge[0]=109;
 facetid->edge[1]=113;
 facetid->edge[2]=100;
 facetid->edge[3]=103;
 facetid++;

 facetid->color=DARKGRAY;
 facetid->nedges=4;
 facetid->edge[0]=109;
 facetid->edge[1]=103;
 facetid->edge[2]=100;
 facetid->edge[3]=113;
 facetid++;

 facetid->color=DARKGRAY;
 facetid->nedges=4;
 facetid->edge[0]=110;
 facetid->edge[1]=114;
 facetid->edge[2]=101;
 facetid->edge[3]=104;
 facetid++;

 facetid->color=DARKGRAY;
 facetid->nedges=4;
 facetid->edge[0]=110;
 facetid->edge[1]=104;
 facetid->edge[2]=101;
 facetid->edge[3]=114;
 facetid++;

 // Tail plane
 facetid->color=DARKGRAY;
 facetid->nedges=4;
 facetid->edge[0]=117;
 facetid->edge[1]=115;
 facetid->edge[2]=119;
 facetid->edge[3]=121;
 facetid++;

 facetid->color=DARKGRAY;
 facetid->nedges=4;
 facetid->edge[0]=117;
 facetid->edge[1]=121;
 facetid->edge[2]=119;
 facetid->edge[3]=115;
 facetid++;

 facetid->color=DARKGRAY;
 facetid->nedges=4;
 facetid->edge[0]=118;
 facetid->edge[1]=122;
 facetid->edge[2]=120;
 facetid->edge[3]=116;
 facetid++;

 facetid->color=DARKGRAY;
 facetid->nedges=4;
 facetid->edge[0]=118;
 facetid->edge[1]=116;
 facetid->edge[2]=120;
 facetid->edge[3]=122;
 facetid++;

 // Nose wheel
 facetid->color=WHITE;
 facetid->nedges=4;
 facetid->edge[0]=137;
 facetid->edge[1]=138;
 facetid->edge[2]=139;
 facetid->edge[3]=140;
 facetid++;

 facetid->color=WHITE;
 facetid->nedges=4;
 facetid->edge[0]=137;
 facetid->edge[1]=140;
 facetid->edge[2]=139;
 facetid->edge[3]=138;
 facetid++;

 facetid->color=DARKGRAY;
 facetid->nedges=8;
 facetid->edge[0]=129;
 facetid->edge[1]=130;
 facetid->edge[2]=131;
 facetid->edge[3]=132;
 facetid->edge[4]=133;
 facetid->edge[5]=134;
 facetid->edge[6]=135;
 facetid->edge[7]=136;
 facetid++;

 facetid->color=DARKGRAY;
 facetid->nedges=8;
 facetid->edge[0]=136;
 facetid->edge[1]=135;
 facetid->edge[2]=134;
 facetid->edge[3]=133;
 facetid->edge[4]=132;
 facetid->edge[5]=131;
 facetid->edge[6]=130;
 facetid->edge[7]=129;
 facetid++;

 // Skids
 facetid->color=DARKGRAY;
 facetid->nedges=4;
 facetid->edge[0]=145;
 facetid->edge[1]=146;
 facetid->edge[2]=142;
 facetid->edge[3]=141;
 facetid++;

 facetid->color=DARKGRAY;
 facetid->nedges=4;
 facetid->edge[0]=145;
 facetid->edge[1]=141;
 facetid->edge[2]=142;
 facetid->edge[3]=146;
 facetid++;

 facetid->color=DARKGRAY;
 facetid->nedges=4;
 facetid->edge[0]=147;
 facetid->edge[1]=148;
 facetid->edge[2]=144;
 facetid->edge[3]=143;
 facetid++;

 facetid->color=DARKGRAY;
 facetid->nedges=4;
 facetid->edge[0]=147;
 facetid->edge[1]=143;
 facetid->edge[2]=144;
 facetid->edge[3]=148;
 facetid++;

 facetid->color=DARKGRAY;
 facetid->nedges=4;
 facetid->edge[0]=149;
 facetid->edge[1]=150;
 facetid->edge[2]=154;
 facetid->edge[3]=153;
 facetid++;

 facetid->color=DARKGRAY;
 facetid->nedges=4;
 facetid->edge[0]=149;
 facetid->edge[1]=153;
 facetid->edge[2]=154;
 facetid->edge[3]=150;
 facetid++;

 facetid->color=DARKGRAY;
 facetid->nedges=4;
 facetid->edge[0]=151;
 facetid->edge[1]=152;
 facetid->edge[2]=156;
 facetid->edge[3]=155;
 facetid++;

 facetid->color=DARKGRAY;
 facetid->nedges=4;
 facetid->edge[0]=151;
 facetid->edge[1]=155;
 facetid->edge[2]=156;
 facetid->edge[3]=152;
 facetid++;



 if (object[id].facet+nfacets!=facetid)
 {
   printf("X-15: Incorrect number of facets.\n");
   //printf("%n expected, %n found.\n", (int)object[id].facet+nfacets, (int)facetid);
   exit(1);
 }

 /*
 facetid->color=DARKGRAY;
 facetid->nedges=4;
 facetid->edge[0]=;
 facetid->edge[1]=;
 facetid->edge[2]=;
 facetid->edge[3]=;
 facetid++;

 facetid->color=DARKGRAY;
 facetid->nedges=3;
 facetid->edge[0]=;
 facetid->edge[1]=;
 facetid->edge[2]=;
 facetid++;
 */

 /* Define control surface rotation axis */
 /*
 object[id].ctrl_surface[].axis =
   vminus(*(object[id].vertex+),*(object[id].vertex+));
 */
 object[id].ctrl_surface[0].axis =
   vminus(*(object[id].vertex+20),*(object[id].vertex+22));
 object[id].ctrl_surface[1].axis =
   vminus(*(object[id].vertex+21),*(object[id].vertex+23));
 object[id].ctrl_surface[2].axis =
   vminus(*(object[id].vertex+103),*(object[id].vertex+100));
 object[id].ctrl_surface[3].axis =
   vminus(*(object[id].vertex+101),*(object[id].vertex+104));
 object[id].ctrl_surface[4].axis =
   vminus(*(object[id].vertex+119),*(object[id].vertex+117));
 object[id].ctrl_surface[5].axis =
   vminus(*(object[id].vertex+118),*(object[id].vertex+120));
 object[id].ctrl_surface[6].axis =
   vminus(*(object[id].vertex+44),*(object[id].vertex+45));
 object[id].ctrl_surface[7].axis =
   vminus(*(object[id].vertex+1),*(object[id].vertex+2));
 object[id].ctrl_surface[8].axis =
   vminus(*(object[id].vertex+1),*(object[id].vertex+2));
  
 
 for (j=0; j<object[id].nctrl_srf; j++){
  float norm;
  cartvektor tmp, tmp2;

  /* Generate orthonormal-system */
  norm=sqrt(VPRIK(object[id].ctrl_surface[j].axis,
                  object[id].ctrl_surface[j].axis));
  object[id].ctrl_surface[j].front=
                  svmult(1./norm,object[id].ctrl_surface[j].axis);
  /* Rotate 90 deg about z */
  tmp.x = -object[id].ctrl_surface[j].front.y;
  tmp.y =  object[id].ctrl_surface[j].front.x;
  tmp.z =  object[id].ctrl_surface[j].front.z;

  /* Rotate 90 deg about x - then the vector is not parallel with front vector */
  tmp2.x =  tmp.x;
  tmp2.y = -tmp.z;
  tmp2.z =  tmp.y;

  object[id].ctrl_surface[j].left =
   vkryds(object[id].ctrl_surface[j].front,tmp2);
  norm=sqrt(VPRIK(object[id].ctrl_surface[j].left,
                  object[id].ctrl_surface[j].left));
  object[id].ctrl_surface[j].left=
                  svmult(1./norm,object[id].ctrl_surface[j].left);

  object[id].ctrl_surface[j].top =
   vkryds(object[id].ctrl_surface[j].front,object[id].ctrl_surface[j].left);
 }

 object[id].colarr[WHITE].r = 255;
 object[id].colarr[WHITE].g = 255;
 object[id].colarr[WHITE].b = 255;

 object[id].colarr[LIGHTGRAY].r = 192;
 object[id].colarr[LIGHTGRAY].g = 192;
 object[id].colarr[LIGHTGRAY].b = 192;

 object[id].colarr[DARKGRAY].r =  80;
 object[id].colarr[DARKGRAY].g =  80;
 object[id].colarr[DARKGRAY].b =  80;

 object[id].colarr[RED].r = 255;
 object[id].colarr[RED].g =  32;
 object[id].colarr[RED].b =  32;

 object[id].colarr[GREEN].r =  32;
 object[id].colarr[GREEN].g = 255;
 object[id].colarr[GREEN].b =  32;

 object[id].colarr[BLUE].r =  32;
 object[id].colarr[BLUE].g =  32;
 object[id].colarr[BLUE].b = 255;

 object[id].colarr[LIGHTRED].r = 255;
 object[id].colarr[LIGHTRED].g =  96;
 object[id].colarr[LIGHTRED].b =  96;

 object[id].colarr[LIGHTBLUE].r = 96;
 object[id].colarr[LIGHTBLUE].g = 96;
 object[id].colarr[LIGHTBLUE].b = 255;

 object[id].colarr[CYAN].r =  96;
 object[id].colarr[CYAN].g = 192;
 object[id].colarr[CYAN].b = 192;

 object[id].colarr[LIGHTCYAN].r =  64;
 object[id].colarr[LIGHTCYAN].g = 255;
 object[id].colarr[LIGHTCYAN].b = 255;

 object[id].colarr[DARKGREEN].r =  50;
 object[id].colarr[DARKGREEN].g = 100;
 object[id].colarr[DARKGREEN].b =  40;

 nobjects++;
