
 id=F14_CP;
 object[id].max_draw_dist=100;
 object[id].always_draw_dist=10;

 object[id].nvertices =  70;
 object[id].nfacets   =  36;
 object[id].nctrl_srf =   0;

 if ((object[id].vertex = malloc(object[id].nvertices*sizeof(cartvektor))) == NULL)
 {
   printf("Not enough memory\n");
   exit(1);
 }

 if ((object[id].facet = malloc(object[id].nfacets*sizeof(polygon_struct))) == NULL)
 {
   printf("Not enough memory\n");
   exit(1);
 }
 facetid=object[id].facet;

 (object[id].vertex+0)->x= 6.68;
 (object[id].vertex+0)->y= 0.421;
 (object[id].vertex+0)->z= 1.13;

 (object[id].vertex+1)->x= 6.68;
 (object[id].vertex+1)->y=-0.421;
 (object[id].vertex+1)->z= 1.13;

 (object[id].vertex+2)->x= 5.49;
 (object[id].vertex+2)->y= 0.406;
 (object[id].vertex+2)->z= 1.22;

 (object[id].vertex+3)->x= 5.49;
 (object[id].vertex+3)->y=-0.406;
 (object[id].vertex+3)->z= 1.22;

 (object[id].vertex+4)->x= 6.68;
 (object[id].vertex+4)->y= 0.421;
 (object[id].vertex+4)->z= 0.00;

 (object[id].vertex+5)->x= 6.68;
 (object[id].vertex+5)->y=-0.421;
 (object[id].vertex+5)->z= 0.00;

 (object[id].vertex+6)->x= 5.49;
 (object[id].vertex+6)->y= 0.406;
 (object[id].vertex+6)->z= 0.00;

 (object[id].vertex+7)->x= 5.49;
 (object[id].vertex+7)->y=-0.406;
 (object[id].vertex+7)->z= 0.00;

 (object[id].vertex+8)->x= 7.33;
 (object[id].vertex+8)->y= 0.43;
 (object[id].vertex+8)->z= 1.12;

 (object[id].vertex+9)->x= 7.33;
 (object[id].vertex+9)->y=-0.43;
 (object[id].vertex+9)->z= 1.12;

 (object[id].vertex+10)->x= 7.35;
 (object[id].vertex+10)->y= 0.43;
 (object[id].vertex+10)->z= 0.00;

 (object[id].vertex+11)->x= 7.35;
 (object[id].vertex+11)->y=-0.43;
 (object[id].vertex+11)->z= 0.00;

 (object[id].vertex+12)->x= 8.48;
 (object[id].vertex+12)->y= 0.16;
 (object[id].vertex+12)->z= 0.96;

 (object[id].vertex+13)->x= 8.48;
 (object[id].vertex+13)->y=-0.16;
 (object[id].vertex+13)->z= 0.96;

 (object[id].vertex+14)->x= 8.48;
 (object[id].vertex+14)->y= 0.16;
 (object[id].vertex+14)->z= 0.00;

 (object[id].vertex+15)->x= 8.48;
 (object[id].vertex+15)->y=-0.16;
 (object[id].vertex+15)->z= 0.00;

 (object[id].vertex+16)->x= 4.06;
 (object[id].vertex+16)->y= 0.08;
 (object[id].vertex+16)->z= 1.55;

 (object[id].vertex+17)->x= 4.06;
 (object[id].vertex+17)->y=-0.08;
 (object[id].vertex+17)->z= 1.55;

 (object[id].vertex+18)->x= 4.09;
 (object[id].vertex+18)->y= 0.27;
 (object[id].vertex+18)->z= 1.46;

 (object[id].vertex+19)->x= 4.09;
 (object[id].vertex+19)->y=-0.27;
 (object[id].vertex+19)->z= 1.46;

 (object[id].vertex+20)->x= 4.14;
 (object[id].vertex+20)->y= 0.37;
 (object[id].vertex+20)->z= 1.28;

 (object[id].vertex+21)->x= 4.14;
 (object[id].vertex+21)->y=-0.37;
 (object[id].vertex+21)->z= 1.28;

 (object[id].vertex+22)->x= 4.14;
 (object[id].vertex+22)->y= 0.37;
 (object[id].vertex+22)->z= 0.00;

 (object[id].vertex+23)->x= 4.14;
 (object[id].vertex+23)->y=-0.37;
 (object[id].vertex+23)->z= 0.00;

 (object[id].vertex+24)->x= 5.96;
 (object[id].vertex+24)->y= 0.14;
 (object[id].vertex+24)->z= 1.69;

 (object[id].vertex+25)->x= 5.96;
 (object[id].vertex+25)->y=-0.14;
 (object[id].vertex+25)->z= 1.69;

 (object[id].vertex+26)->x= 6.01;
 (object[id].vertex+26)->y= 0.14;
 (object[id].vertex+26)->z= 1.69;

 (object[id].vertex+27)->x= 6.01;
 (object[id].vertex+27)->y=-0.14;
 (object[id].vertex+27)->z= 1.69;

 (object[id].vertex+28)->x= 5.96;
 (object[id].vertex+28)->y= 0.41;
 (object[id].vertex+28)->z= 1.18;

 (object[id].vertex+29)->x= 5.96;
 (object[id].vertex+29)->y=-0.41;
 (object[id].vertex+29)->z= 1.18;

 (object[id].vertex+30)->x= 6.01;
 (object[id].vertex+30)->y= 0.41;
 (object[id].vertex+30)->z= 1.18;

 (object[id].vertex+31)->x= 6.01;
 (object[id].vertex+31)->y=-0.41;
 (object[id].vertex+31)->z= 1.18;

 (object[id].vertex+32)->x= 5.96;
 (object[id].vertex+32)->y= 0.41;
 (object[id].vertex+32)->z= 1.40;

 (object[id].vertex+33)->x= 5.96;
 (object[id].vertex+33)->y=-0.41;
 (object[id].vertex+33)->z= 1.40;

 (object[id].vertex+34)->x= 6.01;
 (object[id].vertex+34)->y= 0.41;
 (object[id].vertex+34)->z= 1.40;

 (object[id].vertex+35)->x= 6.01;
 (object[id].vertex+35)->y=-0.41;
 (object[id].vertex+35)->z= 1.40;

 (object[id].vertex+36)->x= 5.96;
 (object[id].vertex+36)->y= 0.35;
 (object[id].vertex+36)->z= 1.58;

 (object[id].vertex+37)->x= 5.96;
 (object[id].vertex+37)->y=-0.35;
 (object[id].vertex+37)->z= 1.58;

 (object[id].vertex+38)->x= 6.01;
 (object[id].vertex+38)->y= 0.35;
 (object[id].vertex+38)->z= 1.58;

 (object[id].vertex+39)->x= 6.01;
 (object[id].vertex+39)->y=-0.35;
 (object[id].vertex+39)->z= 1.58;

 (object[id].vertex+40)->x= 7.33;
 (object[id].vertex+40)->y= 0.40;
 (object[id].vertex+40)->z= 1.12;

 (object[id].vertex+41)->x= 7.33;
 (object[id].vertex+41)->y=-0.40;
 (object[id].vertex+41)->z= 1.12;

 (object[id].vertex+42)->x= 7.455;
 (object[id].vertex+42)->y= 0.249;
 (object[id].vertex+42)->z= 1.433;

 (object[id].vertex+43)->x= 7.455;
 (object[id].vertex+43)->y=-0.249;
 (object[id].vertex+43)->z= 1.433;

 (object[id].vertex+44)->x= 7.486;
 (object[id].vertex+44)->y= 0.089;
 (object[id].vertex+44)->z= 1.510;

 (object[id].vertex+45)->x= 7.486;
 (object[id].vertex+45)->y=-0.089;
 (object[id].vertex+45)->z= 1.510;

 (object[id].vertex+46)->x= 7.399;
 (object[id].vertex+46)->y= 0.360;
 (object[id].vertex+46)->z= 1.294;

 (object[id].vertex+47)->x= 7.399;
 (object[id].vertex+47)->y=-0.360;
 (object[id].vertex+47)->z= 1.294;

 (object[id].vertex+48)->x= 7.33;
 (object[id].vertex+48)->y= 0.43;
 (object[id].vertex+48)->z= 1.12;

 (object[id].vertex+49)->x= 7.33;
 (object[id].vertex+49)->y=-0.43;
 (object[id].vertex+49)->z= 1.12;

 (object[id].vertex+50)->x= 7.464;
 (object[id].vertex+50)->y= 0.268;
 (object[id].vertex+50)->z= 1.456;

 (object[id].vertex+51)->x= 7.464;
 (object[id].vertex+51)->y=-0.268;
 (object[id].vertex+51)->z= 1.456;

 (object[id].vertex+52)->x= 7.498;
 (object[id].vertex+52)->y= 0.096;
 (object[id].vertex+52)->z= 1.539;

 (object[id].vertex+53)->x= 7.498;
 (object[id].vertex+53)->y=-0.096;
 (object[id].vertex+53)->z= 1.539;

 (object[id].vertex+54)->x= 7.405;
 (object[id].vertex+54)->y= 0.387;
 (object[id].vertex+54)->z= 1.307;

 (object[id].vertex+55)->x= 7.405;
 (object[id].vertex+55)->y=-0.387;
 (object[id].vertex+55)->z= 1.307;

 /* Windscreen */
 (object[id].vertex+56)->x= 8.24;
 (object[id].vertex+56)->y= 0.12;
 (object[id].vertex+56)->z= 1.07;

 (object[id].vertex+57)->x= 8.24;
 (object[id].vertex+57)->y=-0.12;
 (object[id].vertex+57)->z= 1.07;

 (object[id].vertex+58)->x= 8.24;
 (object[id].vertex+58)->y= 0.15;
 (object[id].vertex+58)->z= 1.07;

 (object[id].vertex+59)->x= 8.24;
 (object[id].vertex+59)->y=-0.15;
 (object[id].vertex+59)->z= 1.07;

 (object[id].vertex+60)->x= 8.09;
 (object[id].vertex+60)->y= 0.157;
 (object[id].vertex+60)->z= 1.167;

 (object[id].vertex+61)->x= 8.09;
 (object[id].vertex+61)->y=-0.157;
 (object[id].vertex+61)->z= 1.167;

 (object[id].vertex+62)->x= 8.09;
 (object[id].vertex+62)->y= 0.187;
 (object[id].vertex+62)->z= 1.167;

 (object[id].vertex+63)->x= 8.09;
 (object[id].vertex+63)->y=-0.187;
 (object[id].vertex+63)->z= 1.167;

 (object[id].vertex+64)->x= 7.96;
 (object[id].vertex+64)->y= 0.157;
 (object[id].vertex+64)->z= 1.249;

 (object[id].vertex+65)->x= 7.96;
 (object[id].vertex+65)->y=-0.157;
 (object[id].vertex+65)->z= 1.249;

 (object[id].vertex+66)->x= 7.96;
 (object[id].vertex+66)->y= 0.187;
 (object[id].vertex+66)->z= 1.249;

 (object[id].vertex+67)->x= 7.96;
 (object[id].vertex+67)->y=-0.187;
 (object[id].vertex+67)->z= 1.249;

 (object[id].vertex+68)->x= 7.486;
 (object[id].vertex+68)->y= 0.06;
 (object[id].vertex+68)->z= 1.510;

 (object[id].vertex+69)->x= 7.486;
 (object[id].vertex+69)->y=-0.06;
 (object[id].vertex+69)->z= 1.510;

 /*
 (object[id].vertex+)->x=;
 (object[id].vertex+)->y=;
 (object[id].vertex+)->z=;
 */

 /**********/
 /* Facets */
 /**********/

 facetid->color=LIGHTGRAY;
 facetid->nedges=4;
 facetid->edge[0]=0;
 facetid->edge[1]=2;
 facetid->edge[2]=6;
 facetid->edge[3]=4;
 facetid++;

 facetid->color=LIGHTGRAY;
 facetid->nedges=4;
 facetid->edge[0]=5;
 facetid->edge[1]=4;
 facetid->edge[2]=6;
 facetid->edge[3]=7;
 facetid++;

 facetid->color=LIGHTGRAY;
 facetid->nedges=4;
 facetid->edge[0]=3;
 facetid->edge[1]=1;
 facetid->edge[2]=5;
 facetid->edge[3]=7;
 facetid++;

 facetid->color=LIGHTGRAY;
 facetid->nedges=4;
 facetid->edge[0]=8;
 facetid->edge[1]=0;
 facetid->edge[2]=4;
 facetid->edge[3]=10;
 facetid++;

 facetid->color=LIGHTGRAY;
 facetid->nedges=4;
 facetid->edge[0]=11;
 facetid->edge[1]=10;
 facetid->edge[2]=4;
 facetid->edge[3]=5;
 facetid++;

 facetid->color=LIGHTGRAY;
 facetid->nedges=4;
 facetid->edge[0]=1;
 facetid->edge[1]=9;
 facetid->edge[2]=11;
 facetid->edge[3]=5;
 facetid++;

 facetid->color=LIGHTGRAY;
 facetid->nedges=4;
 facetid->edge[0]=12;
 facetid->edge[1]=8;
 facetid->edge[2]=10;
 facetid->edge[3]=14;
 facetid++;

 facetid->color=LIGHTGRAY;
 facetid->nedges=4;
 facetid->edge[0]=11;
 facetid->edge[1]=15;
 facetid->edge[2]=14;
 facetid->edge[3]=10;
 facetid++;

 facetid->color=LIGHTGRAY;
 facetid->nedges=4;
 facetid->edge[0]=9;
 facetid->edge[1]=13;
 facetid->edge[2]=15;
 facetid->edge[3]=11;
 facetid++;

 facetid->color=LIGHTGRAY;
 facetid->nedges=4;
 facetid->edge[0]=13;
 facetid->edge[1]=12;
 facetid->edge[2]=14;
 facetid->edge[3]=15;
 facetid++;

 facetid->color=LIGHTGRAY;
 facetid->nedges=6;
 facetid->edge[0]=21;
 facetid->edge[1]=20;
 facetid->edge[2]=18;
 facetid->edge[3]=16;
 facetid->edge[4]=17;
 facetid->edge[5]=19;
 facetid++;

 facetid->color=LIGHTGRAY;
 facetid->nedges=4;
 facetid->edge[0]=2;
 facetid->edge[1]=20;
 facetid->edge[2]=22;
 facetid->edge[3]=6;
 facetid++;

 facetid->color=LIGHTGRAY;
 facetid->nedges=4;
 facetid->edge[0]=3;
 facetid->edge[1]=7;
 facetid->edge[2]=23;
 facetid->edge[3]=21;
 facetid++;

 facetid->color=LIGHTGRAY;
 facetid->nedges=4;
 facetid->edge[0]=20;
 facetid->edge[1]=21;
 facetid->edge[2]=23;
 facetid->edge[3]=22;
 facetid++;

 facetid->color=LIGHTGRAY;
 facetid->nedges=4;
 facetid->edge[0]=7;
 facetid->edge[1]=6;
 facetid->edge[2]=22;
 facetid->edge[3]=23;
 facetid++;

 facetid->color=DARKGRAY;
 facetid->nedges=4;
 facetid->edge[0]=24;
 facetid->edge[1]=26;
 facetid->edge[2]=27;
 facetid->edge[3]=25;
 facetid++;

 facetid->color=DARKGRAY;
 facetid->nedges=4;
 facetid->edge[0]=34;
 facetid->edge[1]=32;
 facetid->edge[2]=28;
 facetid->edge[3]=30;
 facetid++;

 facetid->color=DARKGRAY;
 facetid->nedges=4;
 facetid->edge[0]=33;
 facetid->edge[1]=35;
 facetid->edge[2]=31;
 facetid->edge[3]=29;
 facetid++;

 facetid->color=DARKGRAY;
 facetid->nedges=4;
 facetid->edge[0]=38;
 facetid->edge[1]=36;
 facetid->edge[2]=32;
 facetid->edge[3]=34;
 facetid++;

 facetid->color=DARKGRAY;
 facetid->nedges=4;
 facetid->edge[0]=26;
 facetid->edge[1]=24;
 facetid->edge[2]=36;
 facetid->edge[3]=38;
 facetid++;

 facetid->color=DARKGRAY;
 facetid->nedges=4;
 facetid->edge[0]=25;
 facetid->edge[1]=27;
 facetid->edge[2]=39;
 facetid->edge[3]=37;
 facetid++;

 facetid->color=DARKGRAY;
 facetid->nedges=4;
 facetid->edge[0]=37;
 facetid->edge[1]=39;
 facetid->edge[2]=35;
 facetid->edge[3]=33;
 facetid++;

 /* Front canopy frame */
 facetid->color=DARKGRAY;
 facetid->nedges=4;
 facetid->edge[0]=46;
 facetid->edge[1]=54;
 facetid->edge[2]=48;
 facetid->edge[3]=40;
 facetid++;

 facetid->color=DARKGRAY;
 facetid->nedges=4;
 facetid->edge[0]=42;
 facetid->edge[1]=50;
 facetid->edge[2]=54;
 facetid->edge[3]=46;
 facetid++;

 facetid->color=DARKGRAY;
 facetid->nedges=4;
 facetid->edge[0]=44;
 facetid->edge[1]=52;
 facetid->edge[2]=50;
 facetid->edge[3]=42;
 facetid++;

 facetid->color=DARKGRAY;
 facetid->nedges=4;
 facetid->edge[0]=45;
 facetid->edge[1]=53;
 facetid->edge[2]=52;
 facetid->edge[3]=44;
 facetid++;

 facetid->color=DARKGRAY;
 facetid->nedges=4;
 facetid->edge[0]=43;
 facetid->edge[1]=51;
 facetid->edge[2]=53;
 facetid->edge[3]=45;
 facetid++;

 facetid->color=DARKGRAY;
 facetid->nedges=4;
 facetid->edge[0]=47;
 facetid->edge[1]=55;
 facetid->edge[2]=51;
 facetid->edge[3]=43;
 facetid++;

 facetid->color=DARKGRAY;
 facetid->nedges=4;
 facetid->edge[0]=41;
 facetid->edge[1]=49;
 facetid->edge[2]=55;
 facetid->edge[3]=47;
 facetid++;

 /* Windscreen */
 facetid->color=DARKGRAY;
 facetid->nedges=4;
 facetid->edge[0]=60;
 facetid->edge[1]=62;
 facetid->edge[2]=58;
 facetid->edge[3]=56;
 facetid++;

 facetid->color=DARKGRAY;
 facetid->nedges=4;
 facetid->edge[0]=63;
 facetid->edge[1]=61;
 facetid->edge[2]=57;
 facetid->edge[3]=59;
 facetid++;

 facetid->color=DARKGRAY;
 facetid->nedges=4;
 facetid->edge[0]=58;
 facetid->edge[1]=12;
 facetid->edge[2]=13;
 facetid->edge[3]=59;
 facetid++;

 facetid->color=DARKGRAY;
 facetid->nedges=4;
 facetid->edge[0]=64;
 facetid->edge[1]=66;
 facetid->edge[2]=62;
 facetid->edge[3]=60;
 facetid++;

 facetid->color=DARKGRAY;
 facetid->nedges=4;
 facetid->edge[0]=67;
 facetid->edge[1]=65;
 facetid->edge[2]=61;
 facetid->edge[3]=63;
 facetid++;

 facetid->color=DARKGRAY;
 facetid->nedges=4;
 facetid->edge[0]=68;
 facetid->edge[1]=44;
 facetid->edge[2]=66;
 facetid->edge[3]=64;
 facetid++;

 facetid->color=DARKGRAY;
 facetid->nedges=4;
 facetid->edge[0]=45;
 facetid->edge[1]=69;
 facetid->edge[2]=65;
 facetid->edge[3]=67;
 facetid++;

 if (object[id].facet+object[id].nfacets!=facetid)
 {
   printf("Incorrect number of facets\n");
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

 nobjects++;
