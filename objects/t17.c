
 id=T17;
 object[id].max_draw_dist=5000;
 object[id].always_draw_dist=50;

 object[id].nvertices = 153;
 object[id].nfacets   =  88; /* Excluding control surface polys */
 object[id].nctrl_srf =   6;

 object[id].ctrl_surface[0].hinge.x      =  -4.17;
 object[id].ctrl_surface[0].hinge.y      =   0;
 object[id].ctrl_surface[0].hinge.z      =   1.12;
 object[id].ctrl_surface[0].rudder_gain  =   0;
 object[id].ctrl_surface[0].aileron_gain =   0;
 object[id].ctrl_surface[0].elevator_gain=   1;
 object[id].ctrl_surface[0].flap_gain    =   0;
 object[id].ctrl_surface[0].brake_gain   =   0;
 object[id].ctrl_surface[0].gear_gain    =   0;
 object[id].ctrl_surface[0].gear_id      =  -1;
 object[id].ctrl_surface[0].nctrlpoly    =   4;
 object[id].ctrl_surface[0].poly_id[0]   =  88;
 object[id].ctrl_surface[0].poly_id[1]   =  89;
 object[id].ctrl_surface[0].poly_id[2]   =  90;
 object[id].ctrl_surface[0].poly_id[3]   =  91;

 object[id].ctrl_surface[1].hinge.x      =  -4.62;
 object[id].ctrl_surface[1].hinge.y      =   0;
 object[id].ctrl_surface[1].hinge.z      =   1.22;
 object[id].ctrl_surface[1].rudder_gain  =   1;
 object[id].ctrl_surface[1].aileron_gain =   0;
 object[id].ctrl_surface[1].elevator_gain=   0;
 object[id].ctrl_surface[1].flap_gain    =   0;
 object[id].ctrl_surface[1].brake_gain   =   0;
 object[id].ctrl_surface[1].gear_gain    =   0;
 object[id].ctrl_surface[1].gear_id      =  -1;
 object[id].ctrl_surface[1].nctrlpoly    =   2;
 object[id].ctrl_surface[1].poly_id[0]   =  92;
 object[id].ctrl_surface[1].poly_id[1]   =  93;

 object[id].ctrl_surface[2].hinge.x      =  -0.86;
 object[id].ctrl_surface[2].hinge.y      =   2.92;
 object[id].ctrl_surface[2].hinge.z      =   0.39;
 object[id].ctrl_surface[2].rudder_gain  =   0;
 object[id].ctrl_surface[2].aileron_gain =   1;
 object[id].ctrl_surface[2].elevator_gain=   0;
 object[id].ctrl_surface[2].flap_gain    =   0;
 object[id].ctrl_surface[2].brake_gain   =   0;
 object[id].ctrl_surface[2].gear_gain    =   0;
 object[id].ctrl_surface[2].gear_id      =  -1;
 object[id].ctrl_surface[2].nctrlpoly    =   2;
 object[id].ctrl_surface[2].poly_id[0]   =  94;
 object[id].ctrl_surface[2].poly_id[1]   =  95;

 object[id].ctrl_surface[3].hinge.x      =  -0.86;
 object[id].ctrl_surface[3].hinge.y      =  -2.92;
 object[id].ctrl_surface[3].hinge.z      =   0.39;
 object[id].ctrl_surface[3].rudder_gain  =   0;
 object[id].ctrl_surface[3].aileron_gain =  -1;
 object[id].ctrl_surface[3].elevator_gain=   0;
 object[id].ctrl_surface[3].flap_gain    =   0;
 object[id].ctrl_surface[3].brake_gain   =   0;
 object[id].ctrl_surface[3].gear_gain    =   0;
 object[id].ctrl_surface[3].gear_id      =  -1;
 object[id].ctrl_surface[3].nctrlpoly    =   2;
 object[id].ctrl_surface[3].poly_id[0]   =  96;
 object[id].ctrl_surface[3].poly_id[1]   =  97;

 object[id].ctrl_surface[4].hinge.x      =  -0.86;
 object[id].ctrl_surface[4].hinge.y      =   2.92;
 object[id].ctrl_surface[4].hinge.z      =   0.39;
 object[id].ctrl_surface[4].rudder_gain  =   0;
 object[id].ctrl_surface[4].aileron_gain =   0;
 object[id].ctrl_surface[4].elevator_gain=   0;
 object[id].ctrl_surface[4].flap_gain    =   1.5;
 object[id].ctrl_surface[4].brake_gain   =   0;
 object[id].ctrl_surface[4].gear_gain    =   0;
 object[id].ctrl_surface[4].gear_id      =  -1;
 object[id].ctrl_surface[4].nctrlpoly    =   2;
 object[id].ctrl_surface[4].poly_id[0]   =  98;
 object[id].ctrl_surface[4].poly_id[1]   =  99;

 object[id].ctrl_surface[5].hinge.x      =  -0.86;
 object[id].ctrl_surface[5].hinge.y      =  -2.92;
 object[id].ctrl_surface[5].hinge.z      =   0.39;
 object[id].ctrl_surface[5].rudder_gain  =   0;
 object[id].ctrl_surface[5].aileron_gain =   0;
 object[id].ctrl_surface[5].elevator_gain=   0;
 object[id].ctrl_surface[5].flap_gain    =   1.5;
 object[id].ctrl_surface[5].brake_gain   =   0;
 object[id].ctrl_surface[5].gear_gain    =   0;
 object[id].ctrl_surface[5].gear_id      =  -1;
 object[id].ctrl_surface[5].nctrlpoly    =   2;
 object[id].ctrl_surface[5].poly_id[0]   = 100;
 object[id].ctrl_surface[5].poly_id[1]   = 101;

 nfacets=object[id].nfacets;
 for (j=0; j<object[id].nctrl_srf; j++) nfacets+=object[id].ctrl_surface[j].nctrlpoly;

 if (many_colors==true) t17color=DARKGREEN;
 else t17color=BROWN;

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

 (object[id].vertex+0)->x= 0.87;
 (object[id].vertex+0)->y= 0.57;
 (object[id].vertex+0)->z=-0.16;

 (object[id].vertex+1)->x= 0.87;
 (object[id].vertex+1)->y= 0.57;
 (object[id].vertex+1)->z=-0.53;

 (object[id].vertex+2)->x=-0.51;
 (object[id].vertex+2)->y= 0.57;
 (object[id].vertex+2)->z=-0.53;

 (object[id].vertex+3)->x=-0.51;
 (object[id].vertex+3)->y= 0.57;
 (object[id].vertex+3)->z= 0.46;

 (object[id].vertex+4)->x= 0.87;
 (object[id].vertex+4)->y=-0.57;
 (object[id].vertex+4)->z=-0.16;

 (object[id].vertex+5)->x= 0.87;
 (object[id].vertex+5)->y=-0.57;
 (object[id].vertex+5)->z=-0.53;

 (object[id].vertex+6)->x=-0.51;
 (object[id].vertex+6)->y=-0.57;
 (object[id].vertex+6)->z=-0.53;

 (object[id].vertex+7)->x=-0.51;
 (object[id].vertex+7)->y=-0.57;
 (object[id].vertex+7)->z= 0.46;

 (object[id].vertex+8)->x=-0.51;
 (object[id].vertex+8)->y= 0.57;
 (object[id].vertex+8)->z=-0.16;

 (object[id].vertex+9)->x=-0.51;
 (object[id].vertex+9)->y=-0.57;
 (object[id].vertex+9)->z=-0.16;

 (object[id].vertex+10)->x=-0.97;
 (object[id].vertex+10)->y= 0.57;
 (object[id].vertex+10)->z=-0.53;

 (object[id].vertex+11)->x=-0.97;
 (object[id].vertex+11)->y= 0.57;
 (object[id].vertex+11)->z=-0.16;

 (object[id].vertex+12)->x=-0.97;
 (object[id].vertex+12)->y=-0.57;
 (object[id].vertex+12)->z=-0.53;

 (object[id].vertex+13)->x=-0.97;
 (object[id].vertex+13)->y=-0.57;
 (object[id].vertex+13)->z=-0.16;

 (object[id].vertex+14)->x=-0.51;
 (object[id].vertex+14)->y= 0.57;
 (object[id].vertex+14)->z= 0.26;

 (object[id].vertex+15)->x=-0.51;
 (object[id].vertex+15)->y=-0.57;
 (object[id].vertex+15)->z= 0.26;

 (object[id].vertex+16)->x=-0.97;
 (object[id].vertex+16)->y= 0.57;
 (object[id].vertex+16)->z= 0.26;

 (object[id].vertex+17)->x=-0.97;
 (object[id].vertex+17)->y=-0.57;
 (object[id].vertex+17)->z= 0.26;

 (object[id].vertex+18)->x=-0.97;
 (object[id].vertex+18)->y= 0.57;
 (object[id].vertex+18)->z= 0.43;

 (object[id].vertex+19)->x=-0.97;
 (object[id].vertex+19)->y=-0.57;
 (object[id].vertex+19)->z= 0.43;

 (object[id].vertex+20)->x=-4.85;
 (object[id].vertex+20)->y= 0.00;
 (object[id].vertex+20)->z= 0.18;

 (object[id].vertex+21)->x=-0.51;
 (object[id].vertex+21)->y= 0.46;
 (object[id].vertex+21)->z= 0.72;

 (object[id].vertex+22)->x=-0.51;
 (object[id].vertex+22)->y=-0.46;
 (object[id].vertex+22)->z= 0.72;

 (object[id].vertex+23)->x=-1.38;
 (object[id].vertex+23)->y= 0.51;
 (object[id].vertex+23)->z= 0.41;

 (object[id].vertex+24)->x=-1.38;
 (object[id].vertex+24)->y=-0.51;
 (object[id].vertex+24)->z= 0.41;

 (object[id].vertex+25)->x=-0.97;
 (object[id].vertex+25)->y= 0.00;
 (object[id].vertex+25)->z=-0.53;

 (object[id].vertex+26)->x=-4.08;
 (object[id].vertex+26)->y= 0.00;
 (object[id].vertex+26)->z=-0.14;

 (object[id].vertex+27)->x=-4.97;
 (object[id].vertex+27)->y= 0.00;
 (object[id].vertex+27)->z= 1.53;

 (object[id].vertex+28)->x=-4.32;
 (object[id].vertex+28)->y= 0.00;
 (object[id].vertex+28)->z= 1.53;

 (object[id].vertex+29)->x=-4.03;
 (object[id].vertex+29)->y= 0.00;
 (object[id].vertex+29)->z= 1.25;

 (object[id].vertex+30)->x=-3.84;
 (object[id].vertex+30)->y= 0.00;
 (object[id].vertex+30)->z= 1.16;

 (object[id].vertex+31)->x=-3.88;
 (object[id].vertex+31)->y= 0.00;
 (object[id].vertex+31)->z= 1.04;

 (object[id].vertex+32)->x=-3.55;
 (object[id].vertex+32)->y= 0.00;
 (object[id].vertex+32)->z= 0.55;

 (object[id].vertex+33)->x=-1.38;
 (object[id].vertex+33)->y= 0.00;
 (object[id].vertex+33)->z= 0.41;

 (object[id].vertex+34)->x=-4.09;
 (object[id].vertex+34)->y= 0.00;
 (object[id].vertex+34)->z= 1.38;

 (object[id].vertex+35)->x=-3.40;
 (object[id].vertex+35)->y= 0.00;
 (object[id].vertex+35)->z= 0.46;

 (object[id].vertex+36)->x=-3.98;
 (object[id].vertex+36)->y= 0.00;
 (object[id].vertex+36)->z= 1.12;

 (object[id].vertex+37)->x=-3.98;
 (object[id].vertex+37)->y= 1.29;
 (object[id].vertex+37)->z= 1.12;

 (object[id].vertex+38)->x=-4.09;
 (object[id].vertex+38)->y= 1.41;
 (object[id].vertex+38)->z= 1.12;

 (object[id].vertex+39)->x=-4.80;
 (object[id].vertex+39)->y= 1.41;
 (object[id].vertex+39)->z= 1.12;

 (object[id].vertex+40)->x=-4.80;
 (object[id].vertex+40)->y= 0.16;
 (object[id].vertex+40)->z= 1.12;

 (object[id].vertex+41)->x=-4.55;
 (object[id].vertex+41)->y= 0.00;
 (object[id].vertex+41)->z= 1.12;

 (object[id].vertex+42)->x=-3.98;
 (object[id].vertex+42)->y=-1.29;
 (object[id].vertex+42)->z= 1.12;

 (object[id].vertex+43)->x=-4.09;
 (object[id].vertex+43)->y=-1.41;
 (object[id].vertex+43)->z= 1.12;

 (object[id].vertex+44)->x=-4.80;
 (object[id].vertex+44)->y=-1.41;
 (object[id].vertex+44)->z= 1.12;

 (object[id].vertex+45)->x=-4.80;
 (object[id].vertex+45)->y=-0.16;
 (object[id].vertex+45)->z= 1.12;

 (object[id].vertex+46)->x=-0.18;
 (object[id].vertex+46)->y= 0.53;
 (object[id].vertex+46)->z= 0.40;

 (object[id].vertex+47)->x=-1.43;
 (object[id].vertex+47)->y= 0.51;
 (object[id].vertex+47)->z= 0.30;

 (object[id].vertex+48)->x=-1.08;
 (object[id].vertex+48)->y= 4.50;
 (object[id].vertex+48)->z= 0.40;

 (object[id].vertex+49)->x=-0.18;
 (object[id].vertex+49)->y= 4.42;
 (object[id].vertex+49)->z= 0.47;

 (object[id].vertex+50)->x= 0.23;
 (object[id].vertex+50)->y= 4.27;
 (object[id].vertex+50)->z= 0.49;

 (object[id].vertex+51)->x= 0.28;
 (object[id].vertex+51)->y= 4.17;
 (object[id].vertex+51)->z= 0.50;

 (object[id].vertex+52)->x=-0.02;
 (object[id].vertex+52)->y= 0.99;
 (object[id].vertex+52)->z= 0.42;

 (object[id].vertex+53)->x=-0.18;
 (object[id].vertex+53)->y=-0.53;
 (object[id].vertex+53)->z= 0.40;

 (object[id].vertex+54)->x=-1.43;
 (object[id].vertex+54)->y=-0.51;
 (object[id].vertex+54)->z= 0.30;

 (object[id].vertex+55)->x=-1.08;
 (object[id].vertex+55)->y=-4.50;
 (object[id].vertex+55)->z= 0.40;

 (object[id].vertex+56)->x=-0.18;
 (object[id].vertex+56)->y=-4.42;
 (object[id].vertex+56)->z= 0.47;

 (object[id].vertex+57)->x= 0.23;
 (object[id].vertex+57)->y=-4.27;
 (object[id].vertex+57)->z= 0.49;

 (object[id].vertex+58)->x= 0.28;
 (object[id].vertex+58)->y=-4.17;
 (object[id].vertex+58)->z= 0.50;

 (object[id].vertex+59)->x=-0.02;
 (object[id].vertex+59)->y=-0.99;
 (object[id].vertex+59)->z= 0.42;

 (object[id].vertex+60)->x= 0.53;
 (object[id].vertex+60)->y= 0.57;
 (object[id].vertex+60)->z=-0.01;

 (object[id].vertex+61)->x= 0.53;
 (object[id].vertex+61)->y=-0.57;
 (object[id].vertex+61)->z=-0.01;

 (object[id].vertex+62)->x= 0.80;
 (object[id].vertex+62)->y= 0.57;
 (object[id].vertex+62)->z= 0.33;

 (object[id].vertex+63)->x= 0.80;
 (object[id].vertex+63)->y=-0.57;
 (object[id].vertex+63)->z= 0.33;

 (object[id].vertex+64)->x=-0.31;
 (object[id].vertex+64)->y= 0.57;
 (object[id].vertex+64)->z= 0.36;

 (object[id].vertex+65)->x=-0.41;
 (object[id].vertex+65)->y= 0.46;
 (object[id].vertex+65)->z= 0.73;

 (object[id].vertex+66)->x=-0.41;
 (object[id].vertex+66)->y=-0.46;
 (object[id].vertex+66)->z= 0.73;

 (object[id].vertex+67)->x=-0.31;
 (object[id].vertex+67)->y=-0.57;
 (object[id].vertex+67)->z= 0.36;

 (object[id].vertex+68)->x= 0.14;
 (object[id].vertex+68)->y= 0.46;
 (object[id].vertex+68)->z= 0.75;

 (object[id].vertex+69)->x= 0.14;
 (object[id].vertex+69)->y=-0.46;
 (object[id].vertex+69)->z= 0.75;

 (object[id].vertex+70)->x= 0.87;
 (object[id].vertex+70)->y= 0.57;
 (object[id].vertex+70)->z= 0.33;

 (object[id].vertex+71)->x= 0.87;
 (object[id].vertex+71)->y=-0.57;
 (object[id].vertex+71)->z= 0.33;

 (object[id].vertex+72)->x= 1.66;
 (object[id].vertex+72)->y= 0.43;
 (object[id].vertex+72)->z= 0.23;

 (object[id].vertex+73)->x= 1.66;
 (object[id].vertex+73)->y= 0.48;
 (object[id].vertex+73)->z=-0.07;

 (object[id].vertex+74)->x= 1.66;
 (object[id].vertex+74)->y= 0.38;
 (object[id].vertex+74)->z=-0.25;

 (object[id].vertex+75)->x= 1.66;
 (object[id].vertex+75)->y=-0.43;
 (object[id].vertex+75)->z= 0.23;

 (object[id].vertex+76)->x= 1.66;
 (object[id].vertex+76)->y=-0.48;
 (object[id].vertex+76)->z=-0.07;

 (object[id].vertex+77)->x= 1.66;
 (object[id].vertex+77)->y=-0.38;
 (object[id].vertex+77)->z=-0.25;

 (object[id].vertex+78)->x= 1.66;
 (object[id].vertex+78)->y= 0.00;
 (object[id].vertex+78)->z=-0.28;

 (object[id].vertex+79)->x= 1.66;
 (object[id].vertex+79)->y= 0.00;
 (object[id].vertex+79)->z= 0.16;

 (object[id].vertex+80)->x= 1.66;
 (object[id].vertex+80)->y= 0.16;
 (object[id].vertex+80)->z= 0.00;

 (object[id].vertex+81)->x= 1.66;
 (object[id].vertex+81)->y= 0.00;
 (object[id].vertex+81)->z=-0.16;

 (object[id].vertex+82)->x= 1.66;
 (object[id].vertex+82)->y=-0.16;
 (object[id].vertex+82)->z= 0.00;

 (object[id].vertex+83)->x= 1.94;
 (object[id].vertex+83)->y= 0.00;
 (object[id].vertex+83)->z= 0.00;

 (object[id].vertex+84)->x=-0.20;
 (object[id].vertex+84)->y= 0.57;
 (object[id].vertex+84)->z=-0.53;

 (object[id].vertex+85)->x=-0.37;
 (object[id].vertex+85)->y= 0.70;
 (object[id].vertex+85)->z=-0.53;

 (object[id].vertex+86)->x=-0.97;
 (object[id].vertex+86)->y= 0.57;
 (object[id].vertex+86)->z=-0.53;

 (object[id].vertex+87)->x=-0.37;
 (object[id].vertex+87)->y= 0.57;
 (object[id].vertex+87)->z=-0.43;

 (object[id].vertex+88)->x=-0.20;
 (object[id].vertex+88)->y=-0.57;
 (object[id].vertex+88)->z=-0.53;

 (object[id].vertex+89)->x=-0.37;
 (object[id].vertex+89)->y=-0.70;
 (object[id].vertex+89)->z=-0.53;

 (object[id].vertex+90)->x=-0.97;
 (object[id].vertex+90)->y=-0.57;
 (object[id].vertex+90)->z=-0.53;

 /* antenna */
 (object[id].vertex+91)->x=-0.37;
 (object[id].vertex+91)->y=-0.57;
 (object[id].vertex+91)->z=-0.43;

 (object[id].vertex+92)->x=-1.43;
 (object[id].vertex+92)->y=-0.36;
 (object[id].vertex+92)->z= 0.38;

 (object[id].vertex+93)->x=-1.69;
 (object[id].vertex+93)->y=-0.36;
 (object[id].vertex+93)->z= 0.38;

 (object[id].vertex+94)->x=-1.46;
 (object[id].vertex+94)->y=-0.40;
 (object[id].vertex+94)->z= 0.72;

 (object[id].vertex+95)->x=-1.66;
 (object[id].vertex+95)->y=-0.40;
 (object[id].vertex+95)->z= 0.72;

 /* wing struts */
 (object[id].vertex+96)->x=-0.36;
 (object[id].vertex+96)->y= 0.57;
 (object[id].vertex+96)->z=-0.53;

 (object[id].vertex+97)->x=-0.45;
 (object[id].vertex+97)->y= 0.57;
 (object[id].vertex+97)->z=-0.53;

 (object[id].vertex+98)->x=-0.26;
 (object[id].vertex+98)->y= 2.27;
 (object[id].vertex+98)->z= 0.41;

 (object[id].vertex+99)->x=-0.35;
 (object[id].vertex+99)->y= 2.27;
 (object[id].vertex+99)->z= 0.41;

 (object[id].vertex+100)->x=-0.36;
 (object[id].vertex+100)->y=-0.57;
 (object[id].vertex+100)->z=-0.53;

 (object[id].vertex+101)->x=-0.45;
 (object[id].vertex+101)->y=-0.57;
 (object[id].vertex+101)->z=-0.53;

 (object[id].vertex+102)->x=-0.26;
 (object[id].vertex+102)->y=-2.27;
 (object[id].vertex+102)->z= 0.41;

 (object[id].vertex+103)->x=-0.35;
 (object[id].vertex+103)->y=-2.27;
 (object[id].vertex+103)->z= 0.41;

 /* nose gear */
 (object[id].vertex+104)->x= 1.05;
 (object[id].vertex+104)->y= 0.00;
 (object[id].vertex+104)->z=-0.48;

 (object[id].vertex+105)->x= 0.97;
 (object[id].vertex+105)->y= 0.00;
 (object[id].vertex+105)->z=-0.48;

 (object[id].vertex+106)->x= 1.12;
 (object[id].vertex+106)->y= 0.00;
 (object[id].vertex+106)->z=-1.03;

 (object[id].vertex+107)->x= 1.06;
 (object[id].vertex+107)->y= 0.00;
 (object[id].vertex+107)->z=-1.03;

 /* main gear */
 (object[id].vertex+108)->x=-0.46;
 (object[id].vertex+108)->y= 0.60;
 (object[id].vertex+108)->z=-0.53;

 (object[id].vertex+109)->x=-0.57;
 (object[id].vertex+109)->y= 0.60;
 (object[id].vertex+109)->z=-0.53;

 (object[id].vertex+110)->x=-0.47;
 (object[id].vertex+110)->y= 1.09;
 (object[id].vertex+110)->z=-0.98;

 (object[id].vertex+111)->x=-0.56;
 (object[id].vertex+111)->y= 1.09;
 (object[id].vertex+111)->z=-0.98;

 (object[id].vertex+112)->x=-0.46;
 (object[id].vertex+112)->y=-0.60;
 (object[id].vertex+112)->z=-0.53;

 (object[id].vertex+113)->x=-0.57;
 (object[id].vertex+113)->y=-0.60;
 (object[id].vertex+113)->z=-0.53;

 (object[id].vertex+114)->x=-0.47;
 (object[id].vertex+114)->y=-1.09;
 (object[id].vertex+114)->z=-0.98;

 (object[id].vertex+115)->x=-0.56;
 (object[id].vertex+115)->y=-1.09;
 (object[id].vertex+115)->z=-0.98;

 for (i=0; i<8; i++){
  float xc=-0.52, yc=1.10, zc=-0.98, radius=0.20;

  (object[id].vertex+116+i)->x=xc+radius*sin(i*PI/4+PI/8);
  (object[id].vertex+116+i)->y=yc;
  (object[id].vertex+116+i)->z=zc+radius*cos(i*PI/4+PI/8);
 }

 for (i=0; i<8; i++){
  float xc=-0.52, yc=-1.10, zc=-0.98, radius=0.20;

  (object[id].vertex+124+i)->x=xc+radius*sin(i*PI/4+PI/8);
  (object[id].vertex+124+i)->y=yc;
  (object[id].vertex+124+i)->z=zc+radius*cos(i*PI/4+PI/8);
 }

 for (i=0; i<8; i++){
  float xc=1.09, yc=0.00, zc=-1.03, radius=0.18;

  (object[id].vertex+132+i)->x=xc+radius*sin(i*PI/4+PI/8);
  (object[id].vertex+132+i)->y=yc;
  (object[id].vertex+132+i)->z=zc+radius*cos(i*PI/4+PI/8);
 }

 /* rudder */
 (object[id].vertex+140)->x=-4.28;
 (object[id].vertex+140)->y= 0.00;
 (object[id].vertex+140)->z= 1.22;

 (object[id].vertex+141)->x=-4.62;
 (object[id].vertex+141)->y= 0.00;
 (object[id].vertex+141)->z= 1.22;

 (object[id].vertex+142)->x=-4.29;
 (object[id].vertex+142)->y= 0.00;
 (object[id].vertex+142)->z= 0.24;

 /* flaps / aileron */
 (object[id].vertex+143)->x=-1.10;
 (object[id].vertex+143)->y= 4.30;
 (object[id].vertex+143)->z= 0.395;

 (object[id].vertex+144)->x=-0.74;
 (object[id].vertex+144)->y= 4.27;
 (object[id].vertex+144)->z= 0.42;

 (object[id].vertex+145)->x=-1.07;
 (object[id].vertex+145)->y= 0.52;
 (object[id].vertex+145)->z= 0.33;

 (object[id].vertex+146)->x=-1.10;
 (object[id].vertex+146)->y=-4.30;
 (object[id].vertex+146)->z= 0.395;

 (object[id].vertex+147)->x=-0.74;
 (object[id].vertex+147)->y=-4.27;
 (object[id].vertex+147)->z= 0.42;

 (object[id].vertex+148)->x=-1.07;
 (object[id].vertex+148)->y=-0.52;
 (object[id].vertex+148)->z= 0.33;

 (object[id].vertex+149)->x=-1.215;
 (object[id].vertex+149)->y= 2.95;
 (object[id].vertex+149)->z= 0.36;

 (object[id].vertex+150)->x=-0.86;
 (object[id].vertex+150)->y= 2.92;
 (object[id].vertex+150)->z= 0.39;

 (object[id].vertex+151)->x=-1.215;
 (object[id].vertex+151)->y=-2.95;
 (object[id].vertex+151)->z= 0.36;

 (object[id].vertex+152)->x=-0.86;
 (object[id].vertex+152)->y=-2.92;
 (object[id].vertex+152)->z= 0.39;

 /*
 (object[id].vertex+)->x=;
 (object[id].vertex+)->y=;
 (object[id].vertex+)->z=;
 */

 /**********/
 /* Facets */
 /**********/

 /*0 cockpit */
 facetid->color=t17color;
 facetid->nedges=4;
 facetid->edge[0]=0;
 facetid->edge[1]=1;
 facetid->edge[2]=2;
 facetid->edge[3]=3;
 facetid++;

 facetid->color=t17color;
 facetid->nedges=4;
 facetid->edge[0]=4;
 facetid->edge[1]=7;
 facetid->edge[2]=6;
 facetid->edge[3]=5;
 facetid++;

 facetid->color=t17color;
 facetid->nedges=4;
 facetid->edge[0]=10;
 facetid->edge[1]=1;
 facetid->edge[2]=5;
 facetid->edge[3]=12;
 facetid++;

 /* 3 rear compartment */
 facetid->color=t17color;
 facetid->nedges=4;
 facetid->edge[0]=8;
 facetid->edge[1]=2;
 facetid->edge[2]=10;
 facetid->edge[3]=11;
 facetid++;

 facetid->color=t17color;
 facetid->nedges=4;
 facetid->edge[0]=9;
 facetid->edge[1]=13;
 facetid->edge[2]=12;
 facetid->edge[3]=6;
 facetid++;

 facetid->color=LIGHTGRAY;
 facetid->nedges=4;
 facetid->edge[0]=16;
 facetid->edge[1]=14;
 facetid->edge[2]=8;
 facetid->edge[3]=11;
 facetid++;

 facetid->color=LIGHTGRAY;
 facetid->nedges=4;
 facetid->edge[0]=15;
 facetid->edge[1]=17;
 facetid->edge[2]=13;
 facetid->edge[3]=9;
 facetid++;

 facetid->color=t17color;
 facetid->nedges=4;
 facetid->edge[0]=14;
 facetid->edge[1]=16;
 facetid->edge[2]=18;
 facetid->edge[3]=3;
 facetid++;

 facetid->color=t17color;
 facetid->nedges=4;
 facetid->edge[0]=17;
 facetid->edge[1]=15;
 facetid->edge[2]=7;
 facetid->edge[3]=19;
 facetid++;

 /* 9 rear body */
 facetid->color=t17color;
 facetid->nedges=3;
 facetid->edge[0]=10;
 facetid->edge[1]=12;
 facetid->edge[2]=20;
 facetid++;

 facetid->color=t17color;
 facetid->nedges=3;
 facetid->edge[0]=18;
 facetid->edge[1]=10;
 facetid->edge[2]=20;
 facetid++;

 facetid->color=t17color;
 facetid->nedges=3;
 facetid->edge[0]=24;
 facetid->edge[1]=23;
 facetid->edge[2]=20;
 facetid++;

 facetid->color=t17color;
 facetid->nedges=3;
 facetid->edge[0]=12;
 facetid->edge[1]=19;
 facetid->edge[2]=20;
 facetid++;

 /* 13 rear canopy */
 facetid->color=LIGHTGRAY;
 facetid->nedges=4;
 facetid->edge[0]=23;
 facetid->edge[1]=24;
 facetid->edge[2]=22;
 facetid->edge[3]=21;
 facetid++;

 facetid->color=LIGHTGRAY;
 facetid->nedges=3;
 facetid->edge[0]=23;
 facetid->edge[1]=21;
 facetid->edge[2]=3;
 facetid++;

 facetid->color=LIGHTGRAY;
 facetid->nedges=3;
 facetid->edge[0]=7;
 facetid->edge[1]=22;
 facetid->edge[2]=24;
 facetid++;

 /* 16 belly fin */
 facetid->color=t17color;
 facetid->nedges=3;
 facetid->edge[0]=25;
 facetid->edge[1]=26;
 facetid->edge[2]=20;
 facetid++;

 facetid->color=t17color;
 facetid->nedges=3;
 facetid->edge[0]=25;
 facetid->edge[1]=20;
 facetid->edge[2]=26;
 facetid++;

 /* 18 tail fin */
 facetid->color=t17color;
 facetid->nedges=7;
 facetid->edge[0]=142;
 facetid->edge[1]=141;
 facetid->edge[2]=140;
 facetid->edge[3]=28;
 facetid->edge[4]=34;
 facetid->edge[5]=32;
 facetid->edge[6]=35;
 facetid++;

 facetid->color=t17color;
 facetid->nedges=7;
 facetid->edge[0]=141;
 facetid->edge[1]=142;
 facetid->edge[2]=35;
 facetid->edge[3]=32;
 facetid->edge[4]=34;
 facetid->edge[5]=28;
 facetid->edge[6]=140;
 facetid++;

 facetid->color=t17color;
 facetid->nedges=3;
 facetid->edge[0]=29;
 facetid->edge[1]=30;
 facetid->edge[2]=31;
 facetid++;

 facetid->color=t17color;
 facetid->nedges=3;
 facetid->edge[0]=31;
 facetid->edge[1]=30;
 facetid->edge[2]=29;
 facetid++;


 /* 22 wing tips */
 facetid->color=t17color;
 facetid->nedges=5;
 facetid->edge[0]= 48;
 facetid->edge[1]=143;
 facetid->edge[2]= 51;
 facetid->edge[3]= 50;
 facetid->edge[4]= 49;
 facetid++;

 facetid->color=t17color;
 facetid->nedges=5;
 facetid->edge[0]=143;
 facetid->edge[1]= 48;
 facetid->edge[2]= 49;
 facetid->edge[3]= 50;
 facetid->edge[4]= 51;
 facetid++;

 facetid->color=t17color;
 facetid->nedges=5;
 facetid->edge[0]=146;
 facetid->edge[1]= 55;
 facetid->edge[2]= 56;
 facetid->edge[3]= 57;
 facetid->edge[4]= 58;
 facetid++;

 facetid->color=t17color;
 facetid->nedges=5;
 facetid->edge[0]=146;
 facetid->edge[1]= 58;
 facetid->edge[2]= 57;
 facetid->edge[3]= 56;
 facetid->edge[4]= 55;
 facetid++;

 /* 26 canopy bar */
 facetid->color=t17color;
 facetid->nedges=4;
 facetid->edge[0]=3;
 facetid->edge[1]=21;
 facetid->edge[2]=65;
 facetid->edge[3]=64;
 facetid++;

 facetid->color=t17color;
 facetid->nedges=4;
 facetid->edge[0]=21;
 facetid->edge[1]=22;
 facetid->edge[2]=66;
 facetid->edge[3]=65;
 facetid++;

 facetid->color=t17color;
 facetid->nedges=4;
 facetid->edge[0]=22;
 facetid->edge[1]=7;
 facetid->edge[2]=67;
 facetid->edge[3]=66;
 facetid++;

 /* 33 front canopy */
 facetid->color=LIGHTGRAY;
 facetid->nedges=4;
 facetid->edge[0]=62;
 facetid->edge[1]=68;
 facetid->edge[2]=69;
 facetid->edge[3]=63;
 facetid++;

 facetid->color=LIGHTGRAY;
 facetid->nedges=3;
 facetid->edge[0]=60;
 facetid->edge[1]=64;
 facetid->edge[2]=62;
 facetid++;

 facetid->color=LIGHTGRAY;
 facetid->nedges=3;
 facetid->edge[0]=64;
 facetid->edge[1]=68;
 facetid->edge[2]=62;
 facetid++;

 facetid->color=LIGHTGRAY;
 facetid->nedges=3;
 facetid->edge[0]=63;
 facetid->edge[1]=69;
 facetid->edge[2]=67;
 facetid++;

 facetid->color=LIGHTGRAY;
 facetid->nedges=3;
 facetid->edge[0]=61;
 facetid->edge[1]=63;
 facetid->edge[2]=67;
 facetid++;

 facetid->color=LIGHTGRAY;
 facetid->nedges=4;
 facetid->edge[0]=68;
 facetid->edge[1]=65;
 facetid->edge[2]=66;
 facetid->edge[3]=69;
 facetid++;

 facetid->color=LIGHTGRAY;
 facetid->nedges=3;
 facetid->edge[0]=64;
 facetid->edge[1]=65;
 facetid->edge[2]=68;
 facetid++;

 facetid->color=LIGHTGRAY;
 facetid->nedges=3;
 facetid->edge[0]=69;
 facetid->edge[1]=66;
 facetid->edge[2]=67;
 facetid++;

 /* 37 engine cowl */
 facetid->color=DARKGRAY;
 facetid->nedges=4;
 facetid->edge[0]=0;
 facetid->edge[1]=60;
 facetid->edge[2]=62;
 facetid->edge[3]=70;
 facetid++;

 facetid->color=DARKGRAY;
 facetid->nedges=4;
 facetid->edge[0]=4;
 facetid->edge[1]=71;
 facetid->edge[2]=63;
 facetid->edge[3]=61;
 facetid++;

 facetid->color=DARKGRAY;
 facetid->nedges=4;
 facetid->edge[0]=62;
 facetid->edge[1]=63;
 facetid->edge[2]=71;
 facetid->edge[3]=70;
 facetid++;

 facetid->color=DARKGRAY;
 facetid->nedges=4;
 facetid->edge[0]=72;
 facetid->edge[1]=75;
 facetid->edge[2]=76;
 facetid->edge[3]=73;
 facetid++;

 facetid->color=t17color;
 facetid->nedges=5;
 facetid->edge[0]=73;
 facetid->edge[1]=76;
 facetid->edge[2]=77;
 facetid->edge[3]=78;
 facetid->edge[4]=74;
 facetid++;

 facetid->color=DARKGRAY;
 facetid->nedges=4;
 facetid->edge[0]=75;
 facetid->edge[1]=72;
 facetid->edge[2]=70;
 facetid->edge[3]=71;
 facetid++;

 facetid->color=DARKGRAY;
 facetid->nedges=3;
 facetid->edge[0]=0;
 facetid->edge[1]=70;
 facetid->edge[2]=73;
 facetid++;

 facetid->color=DARKGRAY;
 facetid->nedges=3;
 facetid->edge[0]=4;
 facetid->edge[1]=76;
 facetid->edge[2]=71;
 facetid++;

 facetid->color=DARKGRAY;
 facetid->nedges=3;
 facetid->edge[0]=70;
 facetid->edge[1]=72;
 facetid->edge[2]=73;
 facetid++;

 facetid->color=DARKGRAY;
 facetid->nedges=3;
 facetid->edge[0]=71;
 facetid->edge[1]=76;
 facetid->edge[2]=75;
 facetid++;

 facetid->color=t17color;
 facetid->nedges=3;
 facetid->edge[0]=0;
 facetid->edge[1]=73;
 facetid->edge[2]=1;
 facetid++;

 facetid->color=t17color;
 facetid->nedges=3;
 facetid->edge[0]=4;
 facetid->edge[1]=5;
 facetid->edge[2]=76;
 facetid++;

 facetid->color=t17color;
 facetid->nedges=3;
 facetid->edge[0]=5;
 facetid->edge[1]=1;
 facetid->edge[2]=78;
 facetid++;

 facetid->color=t17color;
 facetid->nedges=3;
 facetid->edge[0]=1;
 facetid->edge[1]=74;
 facetid->edge[2]=78;
 facetid++;

 facetid->color=t17color;
 facetid->nedges=3;
 facetid->edge[0]=1;
 facetid->edge[1]=73;
 facetid->edge[2]=74;
 facetid++;

 facetid->color=t17color;
 facetid->nedges=3;
 facetid->edge[0]=78;
 facetid->edge[1]=77;
 facetid->edge[2]=5;
 facetid++;

 facetid->color=t17color;
 facetid->nedges=3;
 facetid->edge[0]=77;
 facetid->edge[1]=76;
 facetid->edge[2]=5;
 facetid++;

 /* 54 spinner */
 facetid->color=DARKGRAY;
 facetid->nedges=3;
 facetid->edge[0]=80;
 facetid->edge[1]=79;
 facetid->edge[2]=83;
 facetid++;

 facetid->color=DARKGRAY;
 facetid->nedges=3;
 facetid->edge[0]=79;
 facetid->edge[1]=82;
 facetid->edge[2]=83;
 facetid++;

 facetid->color=DARKGRAY;
 facetid->nedges=3;
 facetid->edge[0]=82;
 facetid->edge[1]=81;
 facetid->edge[2]=83;
 facetid++;

 facetid->color=DARKGRAY;
 facetid->nedges=3;
 facetid->edge[0]=81;
 facetid->edge[1]=80;
 facetid->edge[2]=83;
 facetid++;

 /* 58 gear/strut fairing */
 facetid->color=t17color;
 facetid->nedges=3;
 facetid->edge[0]=84;
 facetid->edge[1]=85;
 facetid->edge[2]=87;
 facetid++;

 facetid->color=t17color;
 facetid->nedges=3;
 facetid->edge[0]=85;
 facetid->edge[1]=86;
 facetid->edge[2]=87;
 facetid++;

 facetid->color=t17color;
 facetid->nedges=3;
 facetid->edge[0]=85;
 facetid->edge[1]=84;
 facetid->edge[2]=86;
 facetid++;

 facetid->color=t17color;
 facetid->nedges=3;
 facetid->edge[0]=88;
 facetid->edge[1]=91;
 facetid->edge[2]=89;
 facetid++;

 facetid->color=t17color;
 facetid->nedges=3;
 facetid->edge[0]=90;
 facetid->edge[1]=89;
 facetid->edge[2]=91;
 facetid++;

 facetid->color=t17color;
 facetid->nedges=3;
 facetid->edge[0]=88;
 facetid->edge[1]=89;
 facetid->edge[2]=90;
 facetid++;

 /* 64 antenna */
 facetid->color=DARKGRAY;
 facetid->nedges=4;
 facetid->edge[0]=92;
 facetid->edge[1]=93;
 facetid->edge[2]=95;
 facetid->edge[3]=94;
 facetid++;

 facetid->color=DARKGRAY;
 facetid->nedges=4;
 facetid->edge[0]=94;
 facetid->edge[1]=95;
 facetid->edge[2]=93;
 facetid->edge[3]=92;
 facetid++;

 /* 66 wing struts */
 facetid->color=t17color;
 facetid->nedges=4;
 facetid->edge[0]=97;
 facetid->edge[1]=96;
 facetid->edge[2]=98;
 facetid->edge[3]=99;
 facetid++;

 facetid->color=t17color;
 facetid->nedges=4;
 facetid->edge[0]=99;
 facetid->edge[1]=98;
 facetid->edge[2]=96;
 facetid->edge[3]=97;
 facetid++;

 facetid->color=t17color;
 facetid->nedges=4;
 facetid->edge[0]=103;
 facetid->edge[1]=102;
 facetid->edge[2]=100;
 facetid->edge[3]=101;
 facetid++;

 facetid->color=t17color;
 facetid->nedges=4;
 facetid->edge[0]=101;
 facetid->edge[1]=100;
 facetid->edge[2]=102;
 facetid->edge[3]=103;
 facetid++;

 /* 70 gear */
 facetid->color=t17color;
 facetid->nedges=4;
 facetid->edge[0]=106;
 facetid->edge[1]=107;
 facetid->edge[2]=105;
 facetid->edge[3]=104;
 facetid++;

 facetid->color=t17color;
 facetid->nedges=4;
 facetid->edge[0]=107;
 facetid->edge[1]=106;
 facetid->edge[2]=104;
 facetid->edge[3]=105;
 facetid++;

 facetid->color=t17color;
 facetid->nedges=4;
 facetid->edge[0]=110;
 facetid->edge[1]=111;
 facetid->edge[2]=109;
 facetid->edge[3]=108;
 facetid++;

 facetid->color=t17color;
 facetid->nedges=4;
 facetid->edge[0]=108;
 facetid->edge[1]=109;
 facetid->edge[2]=111;
 facetid->edge[3]=110;
 facetid++;

 facetid->color=t17color;
 facetid->nedges=4;
 facetid->edge[0]=114;
 facetid->edge[1]=112;
 facetid->edge[2]=113;
 facetid->edge[3]=115;
 facetid++;

 facetid->color=t17color;
 facetid->nedges=4;
 facetid->edge[0]=114;
 facetid->edge[1]=115;
 facetid->edge[2]=113;
 facetid->edge[3]=112;
 facetid++;

 /* 76 wheels */
 facetid->color=DARKGRAY;
 facetid->nedges=8;
 facetid->edge[0]=116;
 facetid->edge[1]=117;
 facetid->edge[2]=118;
 facetid->edge[3]=119;
 facetid->edge[4]=120;
 facetid->edge[5]=121;
 facetid->edge[6]=122;
 facetid->edge[7]=123;
 facetid++;

 facetid->color=DARKGRAY;
 facetid->nedges=8;
 facetid->edge[0]=123;
 facetid->edge[1]=122;
 facetid->edge[2]=121;
 facetid->edge[3]=120;
 facetid->edge[4]=119;
 facetid->edge[5]=118;
 facetid->edge[6]=117;
 facetid->edge[7]=116;
 facetid++;


 facetid->color=DARKGRAY;
 facetid->nedges=8;
 facetid->edge[0]=124;
 facetid->edge[1]=125;
 facetid->edge[2]=126;
 facetid->edge[3]=127;
 facetid->edge[4]=128;
 facetid->edge[5]=129;
 facetid->edge[6]=130;
 facetid->edge[7]=131;
 facetid++;

 facetid->color=DARKGRAY;
 facetid->nedges=8;
 facetid->edge[0]=131;
 facetid->edge[1]=130;
 facetid->edge[2]=129;
 facetid->edge[3]=128;
 facetid->edge[4]=127;
 facetid->edge[5]=126;
 facetid->edge[6]=125;
 facetid->edge[7]=124;
 facetid++;

 facetid->color=DARKGRAY;
 facetid->nedges=8;
 facetid->edge[0]=132;
 facetid->edge[1]=133;
 facetid->edge[2]=134;
 facetid->edge[3]=135;
 facetid->edge[4]=136;
 facetid->edge[5]=137;
 facetid->edge[6]=138;
 facetid->edge[7]=139;
 facetid++;

 facetid->color=DARKGRAY;
 facetid->nedges=8;
 facetid->edge[0]=139;
 facetid->edge[1]=138;
 facetid->edge[2]=137;
 facetid->edge[3]=136;
 facetid->edge[4]=135;
 facetid->edge[5]=134;
 facetid->edge[6]=133;
 facetid->edge[7]=132;
 facetid++;

 /* 82 Ruck fin */
 facetid->color=t17color;
 facetid->nedges=4;
 facetid->edge[0]= 20;
 facetid->edge[1]=142;
 facetid->edge[2]= 35;
 facetid->edge[3]= 33;
 facetid++;

 facetid->color=t17color;
 facetid->nedges=4;
 facetid->edge[0]= 35;
 facetid->edge[1]=142;
 facetid->edge[2]= 20;
 facetid->edge[3]= 33;
 facetid++;

 /* 84 main wing */
 facetid->color=t17color;
 facetid->nedges=5;
 facetid->edge[0]= 52;
 facetid->edge[1]= 51;
 facetid->edge[2]=144;
 facetid->edge[3]=145;
 facetid->edge[4]= 46;
 facetid++;

 facetid->color=t17color;
 facetid->nedges=5;
 facetid->edge[0]=144;
 facetid->edge[1]= 51;
 facetid->edge[2]= 52;
 facetid->edge[3]= 46;
 facetid->edge[4]=145;
 facetid++;

 facetid->color=t17color;
 facetid->nedges=5;
 facetid->edge[0]=148;
 facetid->edge[1]=147;
 facetid->edge[2]= 58;
 facetid->edge[3]= 59;
 facetid->edge[4]= 53;
 facetid++;

 facetid->color=t17color;
 facetid->nedges=5;
 facetid->edge[0]= 58;
 facetid->edge[1]=147;
 facetid->edge[2]=148;
 facetid->edge[3]= 53;
 facetid->edge[4]= 59;
 facetid++;


 /* *** Control surfaces below here *** */

 /* 88 tail plane */
 facetid->color=t17color;
 facetid->nedges=6;
 facetid->edge[0]=36;
 facetid->edge[1]=37;
 facetid->edge[2]=38;
 facetid->edge[3]=39;
 facetid->edge[4]=40;
 facetid->edge[5]=41;
 facetid++;

 facetid->color=t17color;
 facetid->nedges=6;
 facetid->edge[0]=36;
 facetid->edge[1]=41;
 facetid->edge[2]=40;
 facetid->edge[3]=39;
 facetid->edge[4]=38;
 facetid->edge[5]=37;
 facetid++;


 facetid->color=t17color;
 facetid->nedges=6;
 facetid->edge[0]=36;
 facetid->edge[1]=41;
 facetid->edge[2]=45;
 facetid->edge[3]=44;
 facetid->edge[4]=43;
 facetid->edge[5]=42;
 facetid++;


 facetid->color=t17color;
 facetid->nedges=6;
 facetid->edge[0]=36;
 facetid->edge[1]=42;
 facetid->edge[2]=43;
 facetid->edge[3]=44;
 facetid->edge[4]=45;
 facetid->edge[5]=41;
 facetid++;

 /* 92 rudder */
 facetid->color=t17color;
 facetid->nedges=6;
 facetid->edge[0]= 20;
 facetid->edge[1]=142;
 facetid->edge[2]=141;
 facetid->edge[3]=140;
 facetid->edge[4]= 28;
 facetid->edge[5]= 27;
 facetid++;


 facetid->color=t17color;
 facetid->nedges=6;
 facetid->edge[0]= 20;
 facetid->edge[1]= 27;
 facetid->edge[2]= 28;
 facetid->edge[3]=140;
 facetid->edge[4]=141;
 facetid->edge[5]=142;
 facetid++;

 /* 94 ailerons */
 facetid->color=t17color;
 facetid->nedges=4;
 facetid->edge[0]=149;
 facetid->edge[1]=150;
 facetid->edge[2]=144;
 facetid->edge[3]=143;
 facetid++;

 facetid->color=t17color;
 facetid->nedges=4;
 facetid->edge[0]=144;
 facetid->edge[1]=150;
 facetid->edge[2]=149;
 facetid->edge[3]=143;
 facetid++;

 facetid->color=t17color;
 facetid->nedges=4;
 facetid->edge[0]=151;
 facetid->edge[1]=152;
 facetid->edge[2]=147;
 facetid->edge[3]=146;
 facetid++;

 facetid->color=t17color;
 facetid->nedges=4;
 facetid->edge[0]=147;
 facetid->edge[1]=152;
 facetid->edge[2]=151;
 facetid->edge[3]=146;
 facetid++;

 /* 98 flaps */
 facetid->color=t17color;
 facetid->nedges=4;
 facetid->edge[0]= 47;
 facetid->edge[1]=145;
 facetid->edge[2]=150;
 facetid->edge[3]=149;
 facetid++;

 facetid->color=t17color;
 facetid->nedges=4;
 facetid->edge[0]=150;
 facetid->edge[1]=145;
 facetid->edge[2]= 47;
 facetid->edge[3]=149;
 facetid++;

 facetid->color=t17color;
 facetid->nedges=4;
 facetid->edge[0]= 54;
 facetid->edge[1]=151;
 facetid->edge[2]=152;
 facetid->edge[3]=148;
 facetid++;

 facetid->color=t17color;
 facetid->nedges=4;
 facetid->edge[0]=152;
 facetid->edge[1]=151;
 facetid->edge[2]= 54;
 facetid->edge[3]=148;
 facetid++;

 if (object[id].facet+nfacets!=facetid)
 {
   printf("T17: Incorrect number of facets\n");
   exit(1);
 }

 /*
 facetid->color=;
 facetid->nedges=;
 facetid->edge[0]=;
 facetid->edge[1]=;
 facetid->edge[2]=;
 facetid->edge[3]=;
 facetid++;
 */

 /* Define control surface rotation axis */
 object[id].ctrl_surface[0].axis =
   vminus(*(object[id].vertex+38),*(object[id].vertex+43));
 object[id].ctrl_surface[1].axis =
   vminus(*(object[id].vertex+141),*(object[id].vertex+142));
 object[id].ctrl_surface[2].axis =
   vminus(*(object[id].vertex+150),*(object[id].vertex+144));
 object[id].ctrl_surface[3].axis =
   vminus(*(object[id].vertex+147),*(object[id].vertex+152));
 object[id].ctrl_surface[4].axis =
   vminus(*(object[id].vertex+145),*(object[id].vertex+150));
 object[id].ctrl_surface[5].axis =
   vminus(*(object[id].vertex+152),*(object[id].vertex+148));

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
