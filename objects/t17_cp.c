
 id=T17_CP;
 object[id].max_draw_dist=100;
 object[id].always_draw_dist=10;

 object[id].nvertices =  47;
 object[id].nfacets   =  23;
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
 (object[id].vertex+21)->y= 0.37;
 (object[id].vertex+21)->z= 0.72;

 (object[id].vertex+22)->x=-0.51;
 (object[id].vertex+22)->y=-0.37;
 (object[id].vertex+22)->z= 0.72;

 (object[id].vertex+23)->x=-1.38;
 (object[id].vertex+23)->y= 0.51;
 (object[id].vertex+23)->z= 0.41;

 (object[id].vertex+24)->x=-1.38;
 (object[id].vertex+24)->y=-0.51;
 (object[id].vertex+24)->z= 0.41;

 (object[id].vertex+25)->x= 0.53;
 (object[id].vertex+25)->y= 0.57;
 (object[id].vertex+25)->z=-0.01;

 (object[id].vertex+26)->x= 0.53;
 (object[id].vertex+26)->y=-0.57;
 (object[id].vertex+26)->z=-0.01;

 (object[id].vertex+27)->x= 0.80;
 (object[id].vertex+27)->y= 0.57;
 (object[id].vertex+27)->z= 0.33;

 (object[id].vertex+28)->x= 0.80;
 (object[id].vertex+28)->y=-0.57;
 (object[id].vertex+28)->z= 0.33;

 (object[id].vertex+29)->x= 0.87;
 (object[id].vertex+29)->y= 0.57;
 (object[id].vertex+29)->z= 0.33;

 (object[id].vertex+30)->x= 0.87;
 (object[id].vertex+30)->y=-0.57;
 (object[id].vertex+30)->z= 0.33;

 (object[id].vertex+31)->x=-0.41;
 (object[id].vertex+31)->y= 0.37;
 (object[id].vertex+31)->z= 0.73;

 (object[id].vertex+32)->x=-0.41;
 (object[id].vertex+32)->y=-0.37;
 (object[id].vertex+32)->z= 0.73;

 (object[id].vertex+33)->x=-0.41;
 (object[id].vertex+33)->y= 0.015;
 (object[id].vertex+33)->z= 0.73;

 (object[id].vertex+34)->x=-0.41;
 (object[id].vertex+34)->y=-0.015;
 (object[id].vertex+34)->z= 0.73;

 (object[id].vertex+35)->x= 0.0;
 (object[id].vertex+35)->y= 0.015;
 (object[id].vertex+35)->z= 0.73;

 (object[id].vertex+36)->x= 0.0;
 (object[id].vertex+36)->y=-0.015;
 (object[id].vertex+36)->z= 0.73;

 (object[id].vertex+37)->x= 0.3;
 (object[id].vertex+37)->y= 0.015;
 (object[id].vertex+37)->z= 0.63;

 (object[id].vertex+38)->x= 0.3;
 (object[id].vertex+38)->y=-0.015;
 (object[id].vertex+38)->z= 0.63;

 (object[id].vertex+39)->x= 0.80;
 (object[id].vertex+39)->y= 0.015;
 (object[id].vertex+39)->z= 0.33;

 (object[id].vertex+40)->x= 0.80;
 (object[id].vertex+40)->y=-0.015;
 (object[id].vertex+40)->z= 0.33;

 (object[id].vertex+41)->x=-0.31;
 (object[id].vertex+41)->y= 0.58;
 (object[id].vertex+41)->z= 0.36;

 (object[id].vertex+42)->x=-0.31;
 (object[id].vertex+42)->y=-0.58;
 (object[id].vertex+42)->z= 0.36;

 (object[id].vertex+43)->x=-0.51;
 (object[id].vertex+43)->y= 0.52;
 (object[id].vertex+43)->z= 0.65;

 (object[id].vertex+44)->x=-0.51;
 (object[id].vertex+44)->y=-0.52;
 (object[id].vertex+44)->z= 0.65;

 (object[id].vertex+45)->x=-0.41;
 (object[id].vertex+45)->y= 0.52;
 (object[id].vertex+45)->z= 0.65;

 (object[id].vertex+46)->x=-0.41;
 (object[id].vertex+46)->y=-0.52;
 (object[id].vertex+46)->z= 0.65;

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
 facetid->edge[0]=1;
 facetid->edge[1]=2;
 facetid->edge[2]=6;
 facetid->edge[3]=5;
 facetid++;

 facetid->color=LIGHTGRAY;
 facetid->nedges=4;
 facetid->edge[0]=0;
 facetid->edge[1]=3;
 facetid->edge[2]=2;
 facetid->edge[3]=1;
 facetid++;

 facetid->color=LIGHTGRAY;
 facetid->nedges=4;
 facetid->edge[0]=7;
 facetid->edge[1]=4;
 facetid->edge[2]=5;
 facetid->edge[3]=6;
 facetid++;

 facetid->color=LIGHTGRAY;
 facetid->nedges=4;
 facetid->edge[0]=2;
 facetid->edge[1]=8;
 facetid->edge[2]=11;
 facetid->edge[3]=10;
 facetid++;

 facetid->color=LIGHTGRAY;
 facetid->nedges=4;
 facetid->edge[0]=14;
 facetid->edge[1]=3;
 facetid->edge[2]=18;
 facetid->edge[3]=16;
 facetid++;

 facetid->color=LIGHTGRAY;
 facetid->nedges=4;
 facetid->edge[0]=9;
 facetid->edge[1]=6;
 facetid->edge[2]=12;
 facetid->edge[3]=13;
 facetid++;

 facetid->color=LIGHTGRAY;
 facetid->nedges=4;
 facetid->edge[0]=7;
 facetid->edge[1]=15;
 facetid->edge[2]=17;
 facetid->edge[3]=19;
 facetid++;

 facetid->color=LIGHTGRAY;
 facetid->nedges=4;
 facetid->edge[0]=6;
 facetid->edge[1]=2;
 facetid->edge[2]=10;
 facetid->edge[3]=12;
 facetid++;

 facetid->color=LIGHTGRAY;
 facetid->nedges=4;
 facetid->edge[0]=18;
 facetid->edge[1]=19;
 facetid->edge[2]=12;
 facetid->edge[3]=10;
 facetid++;

 facetid->color=LIGHTGRAY;
 facetid->nedges=4;
 facetid->edge[0]=0;
 facetid->edge[1]=1;
 facetid->edge[2]=5;
 facetid->edge[3]=4;
 facetid++;

 facetid->color=LIGHTGRAY;
 facetid->nedges=4;
 facetid->edge[0]=0;
 facetid->edge[1]=29;
 facetid->edge[2]=27;
 facetid->edge[3]=25;
 facetid++;

 facetid->color=LIGHTGRAY;
 facetid->nedges=4;
 facetid->edge[0]=28;
 facetid->edge[1]=30;
 facetid->edge[2]=4;
 facetid->edge[3]=26;
 facetid++;

 facetid->color=LIGHTGRAY;
 facetid->nedges=4;
 facetid->edge[0]=0;
 facetid->edge[1]=4;
 facetid->edge[2]=30;
 facetid->edge[3]=29;
 facetid++;

 facetid->color=LIGHTGRAY;
 facetid->nedges=4;
 facetid->edge[0]=19;
 facetid->edge[1]=18;
 facetid->edge[2]=23;
 facetid->edge[3]=24;
 facetid++;

 facetid->color=LIGHTGRAY;
 facetid->nedges=4;
 facetid->edge[0]=21;
 facetid->edge[1]=31;
 facetid->edge[2]=32;
 facetid->edge[3]=22;
 facetid++;

 facetid->color=LIGHTGRAY;
 facetid->nedges=4;
 facetid->edge[0]=35;
 facetid->edge[1]=36;
 facetid->edge[2]=34;
 facetid->edge[3]=33;
 facetid++;

 facetid->color=LIGHTGRAY;
 facetid->nedges=4;
 facetid->edge[0]=37;
 facetid->edge[1]=38;
 facetid->edge[2]=36;
 facetid->edge[3]=35;
 facetid++;

 facetid->color=LIGHTGRAY;
 facetid->nedges=4;
 facetid->edge[0]=39;
 facetid->edge[1]=40;
 facetid->edge[2]=38;
 facetid->edge[3]=37;
 facetid++;

 facetid->color=DARKGRAY;
 facetid->nedges=4;
 facetid->edge[0]=27;
 facetid->edge[1]=28;
 facetid->edge[2]=30;
 facetid->edge[3]=29;
 facetid++;

 facetid->color=LIGHTGRAY;
 facetid->nedges=4;
 facetid->edge[0]=43;
 facetid->edge[1]=45;
 facetid->edge[2]=31;
 facetid->edge[3]=21;
 facetid++;

 facetid->color=LIGHTGRAY;
 facetid->nedges=4;
 facetid->edge[0]=22;
 facetid->edge[1]=32;
 facetid->edge[2]=46;
 facetid->edge[3]=44;
 facetid++;

 facetid->color=LIGHTGRAY;
 facetid->nedges=4;
 facetid->edge[0]=41;
 facetid->edge[1]=45;
 facetid->edge[2]=43;
 facetid->edge[3]=3;
 facetid++;

 facetid->color=LIGHTGRAY;
 facetid->nedges=4;
 facetid->edge[0]=7;
 facetid->edge[1]=44;
 facetid->edge[2]=46;
 facetid->edge[3]=42;
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
