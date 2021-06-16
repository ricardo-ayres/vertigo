

 id=NIMITZ_MARK1;
 object[id].max_draw_dist=5000;
 object[id].always_draw_dist=1000;

 object[id].nvertices =  60;
 object[id].nfacets   =  31;
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

 {
 float v=9.20*PI/180;
 float sin_v=sin(v);
 float cos_v=cos(v);
 float xc,yc,b,l;
 float yc_0=  6.35;
 float xc_0=-132.3;

 /* Centerline */
 yc= yc_0-cos_v*13.25;
 xc= xc_0+sin_v*13.25;
 b=1.0;
 l=237.5;

 (object[id].vertex+0)->x= xc;
 (object[id].vertex+0)->y= yc;
 (object[id].vertex+0)->z= 20.0;

 (object[id].vertex+1)->x= xc+sin_v*b;
 (object[id].vertex+1)->y= yc-cos_v*b;
 (object[id].vertex+1)->z= 20.0;

 (object[id].vertex+2)->x= xc+cos_v*l;
 (object[id].vertex+2)->y= yc+sin_v*l;
 (object[id].vertex+2)->z= 20.0;

 (object[id].vertex+3)->x= xc+cos_v*l+sin_v*b  +b;
 (object[id].vertex+3)->y= yc-cos_v*b+sin_v*l;
 (object[id].vertex+3)->z= 20.0;


 /* Port border */
 yc=  yc_0;
 xc=  xc_0;
 b=    4.3;
 l=  226.5;

 (object[id].vertex+4)->x= xc;
 (object[id].vertex+4)->y= yc;
 (object[id].vertex+4)->z= 20.0;

 (object[id].vertex+5)->x= xc+sin_v*b;
 (object[id].vertex+5)->y= yc-cos_v*b;
 (object[id].vertex+5)->z= 20.0;

 (object[id].vertex+6)->x= xc+cos_v*l;
 (object[id].vertex+6)->y= yc+sin_v*l;
 (object[id].vertex+6)->z= 20.0;

 (object[id].vertex+7)->x= xc+cos_v*l+sin_v*b  +b;
 (object[id].vertex+7)->y= yc-cos_v*b+sin_v*l;
 (object[id].vertex+7)->z= 20.0;

 /* Stb. border */
 yc= yc_0-cos_v*23.2;
 xc= xc_0+sin_v*23.2;
 b=    4.3;
 l=  246.0;

 (object[id].vertex+8)->x= xc;
 (object[id].vertex+8)->y= yc;
 (object[id].vertex+8)->z= 20.0;

 (object[id].vertex+9)->x= xc+sin_v*b;
 (object[id].vertex+9)->y= yc-cos_v*b;
 (object[id].vertex+9)->z= 20.0;

 (object[id].vertex+10)->x= xc+cos_v*l;
 (object[id].vertex+10)->y= yc+sin_v*l;
 (object[id].vertex+10)->z= 20.0;

 (object[id].vertex+11)->x= xc+cos_v*l+sin_v*b  +b;
 (object[id].vertex+11)->y= yc-cos_v*b+sin_v*l;
 (object[id].vertex+11)->z= 20.0;

 /* Threshold */
 yc=  yc_0;
 xc=  xc_0;
 b=   27.5;
 l=    3.0;

 (object[id].vertex+12)->x= xc;
 (object[id].vertex+12)->y= yc;
 (object[id].vertex+12)->z= 20.0;

 (object[id].vertex+13)->x= xc+sin_v*b;
 (object[id].vertex+13)->y= yc-cos_v*b;
 (object[id].vertex+13)->z= 20.0;

 (object[id].vertex+14)->x= xc+cos_v*l;
 (object[id].vertex+14)->y= yc+sin_v*l;
 (object[id].vertex+14)->z= 20.0;

 (object[id].vertex+15)->x= xc+cos_v*l+sin_v*b;
 (object[id].vertex+15)->y= yc-cos_v*b+sin_v*l;
 (object[id].vertex+15)->z= 20.0;

 }

 /* Island base */
 (object[id].vertex+16)->x= -5.4;
 (object[id].vertex+16)->y=-25.0;
 (object[id].vertex+16)->z= 20.0;

 (object[id].vertex+17)->x=-30.6;
 (object[id].vertex+17)->y=-25.0;
 (object[id].vertex+17)->z= 20.0;

 (object[id].vertex+18)->x=-30.6;
 (object[id].vertex+18)->y=-32.8;
 (object[id].vertex+18)->z= 20.0;

 (object[id].vertex+19)->x= -5.4;
 (object[id].vertex+19)->y=-32.8;
 (object[id].vertex+19)->z= 20.0;

 (object[id].vertex+20)->x= -5.4;
 (object[id].vertex+20)->y=-25.0;
 (object[id].vertex+20)->z= 29.3;

 (object[id].vertex+21)->x=-30.6;
 (object[id].vertex+21)->y=-25.0;
 (object[id].vertex+21)->z= 29.3;

 (object[id].vertex+22)->x=-30.6;
 (object[id].vertex+22)->y=-32.8;
 (object[id].vertex+22)->z= 29.3;

 (object[id].vertex+23)->x= -5.4;
 (object[id].vertex+23)->y=-32.8;
 (object[id].vertex+23)->z= 29.3;

 /* Rear extension of island */
 (object[id].vertex+24)->x=-26.7;
 (object[id].vertex+24)->y=-23.3;
 (object[id].vertex+24)->z= 29.3;

 (object[id].vertex+25)->x=-34.4;
 (object[id].vertex+25)->y=-23.3;
 (object[id].vertex+25)->z= 29.3;

 (object[id].vertex+26)->x=-34.4;
 (object[id].vertex+26)->y=-33.9;
 (object[id].vertex+26)->z= 29.3;

 (object[id].vertex+27)->x=-26.7;
 (object[id].vertex+27)->y=-33.9;
 (object[id].vertex+27)->z= 29.3;

 (object[id].vertex+28)->x=-26.7;
 (object[id].vertex+28)->y=-23.3;
 (object[id].vertex+28)->z= 32.7;

 (object[id].vertex+29)->x=-34.4;
 (object[id].vertex+29)->y=-23.3;
 (object[id].vertex+29)->z= 32.7;

 (object[id].vertex+30)->x=-34.4;
 (object[id].vertex+30)->y=-33.9;
 (object[id].vertex+30)->z= 32.7;

 (object[id].vertex+31)->x=-26.7;
 (object[id].vertex+31)->y=-33.9;
 (object[id].vertex+31)->z= 32.7;

 /* island top */
 (object[id].vertex+32)->x= -4.0;
 (object[id].vertex+32)->y=-21.4;
 (object[id].vertex+32)->z= 29.3;

 (object[id].vertex+33)->x= -8.9;
 (object[id].vertex+33)->y=-21.4;
 (object[id].vertex+33)->z= 29.3;

 (object[id].vertex+34)->x= -8.9;
 (object[id].vertex+34)->y=-24.4;
 (object[id].vertex+34)->z= 29.3;

 (object[id].vertex+35)->x=-26.7;
 (object[id].vertex+35)->y=-25.0;
 (object[id].vertex+35)->z= 29.3;

 (object[id].vertex+36)->x=-26.7;
 (object[id].vertex+36)->y=-32.8;
 (object[id].vertex+36)->z= 29.3;

 (object[id].vertex+37)->x= -4.0;
 (object[id].vertex+37)->y=-32.8;
 (object[id].vertex+37)->z= 29.3;

 (object[id].vertex+38)->x= -4.0;
 (object[id].vertex+38)->y=-21.4;
 (object[id].vertex+38)->z= 36.2;

 (object[id].vertex+39)->x= -8.9;
 (object[id].vertex+39)->y=-21.4;
 (object[id].vertex+39)->z= 36.2;

 (object[id].vertex+40)->x= -8.9;
 (object[id].vertex+40)->y=-24.4;
 (object[id].vertex+40)->z= 36.2;

 (object[id].vertex+41)->x=-26.7;
 (object[id].vertex+41)->y=-25.0;
 (object[id].vertex+41)->z= 36.2;

 (object[id].vertex+42)->x=-26.7;
 (object[id].vertex+42)->y=-32.8;
 (object[id].vertex+42)->z= 36.2;

 (object[id].vertex+43)->x= -4.0;
 (object[id].vertex+43)->y=-32.8;
 (object[id].vertex+43)->z= 36.2;

 (object[id].vertex+44)->x=-26.7;
 (object[id].vertex+44)->y=-25.0;
 (object[id].vertex+44)->z= 32.7;

 (object[id].vertex+45)->x=-26.7;
 (object[id].vertex+45)->y=-32.8;
 (object[id].vertex+45)->z= 32.7;

 (object[id].vertex+46)->x= -4.0;
 (object[id].vertex+46)->y=-25.0;
 (object[id].vertex+46)->z= 29.3;

 /* Radar */
 (object[id].vertex+47)->x=-10.4+3;
 (object[id].vertex+47)->y=-28.0+1.5;
 (object[id].vertex+47)->z= 38.5;

 (object[id].vertex+48)->x=-10.4-3;
 (object[id].vertex+48)->y=-28.0-1.5;
 (object[id].vertex+48)->z= 38.5;

 (object[id].vertex+49)->x=-10.4-3;
 (object[id].vertex+49)->y=-28.0-1.5;
 (object[id].vertex+49)->z= 42.8;

 (object[id].vertex+50)->x=-10.4+3;
 (object[id].vertex+50)->y=-28.0+1.5;
 (object[id].vertex+50)->z= 42.8;

 /* deck mast */
 (object[id].vertex+51)->x=-41.3+1;
 (object[id].vertex+51)->y=-31.8+1;
 (object[id].vertex+51)->z= 20.0;

 (object[id].vertex+52)->x=-41.3+1;
 (object[id].vertex+52)->y=-31.8-1;
 (object[id].vertex+52)->z= 20.0;

 (object[id].vertex+53)->x=-41.3-1;
 (object[id].vertex+53)->y=-31.8-1;
 (object[id].vertex+53)->z= 20.0;

 (object[id].vertex+54)->x=-41.3-1;
 (object[id].vertex+54)->y=-31.8+1;
 (object[id].vertex+54)->z= 20.0;

 (object[id].vertex+55)->x=-41.3;
 (object[id].vertex+55)->y=-31.8;
 (object[id].vertex+55)->z= 41.3;

 /* radar on mast */
 (object[id].vertex+56)->x=-41.3-2;
 (object[id].vertex+56)->y=-31.8+0.5;
 (object[id].vertex+56)->z= 41.3;

 (object[id].vertex+57)->x=-41.3+2;
 (object[id].vertex+57)->y=-31.8-0.5;
 (object[id].vertex+57)->z= 41.3;

 (object[id].vertex+58)->x=-41.3+2;
 (object[id].vertex+58)->y=-31.8-0.5;
 (object[id].vertex+58)->z= 41.3+2;

 (object[id].vertex+59)->x=-41.3-2;
 (object[id].vertex+59)->y=-31.8+0.5;
 (object[id].vertex+59)->z= 41.3+2;

 /*
 (object[id].vertex+)->x=;
 (object[id].vertex+)->y=;
 (object[id].vertex+)->z=;
 */

 /**********/
 /* Facets */
 /**********/

 /*0 */

 facetid->color=WHITE_SHADE;
 facetid->nedges=4;
 facetid->edge[0]=0;
 facetid->edge[1]=1;
 facetid->edge[2]=3;
 facetid->edge[3]=2;
 facetid++;

 facetid->color=WHITE_SHADE;
 facetid->nedges=4;
 facetid->edge[0]=4;
 facetid->edge[1]=5;
 facetid->edge[2]=7;
 facetid->edge[3]=6;
 facetid++;

 facetid->color=WHITE_SHADE;
 facetid->nedges=4;
 facetid->edge[0]=8;
 facetid->edge[1]=9;
 facetid->edge[2]=11;
 facetid->edge[3]=10;
 facetid++;

 facetid->color=WHITE_SHADE;
 facetid->nedges=4;
 facetid->edge[0]=12;
 facetid->edge[1]=13;
 facetid->edge[2]=15;
 facetid->edge[3]=14;
 facetid++;

 facetid->color=LIGHTGRAY;
 facetid->nedges=4;
 facetid->edge[0]=17;
 facetid->edge[1]=21;
 facetid->edge[2]=20;
 facetid->edge[3]=16;
 facetid++;

 facetid->color=LIGHTGRAY;
 facetid->nedges=4;
 facetid->edge[0]=17;
 facetid->edge[1]=18;
 facetid->edge[2]=22;
 facetid->edge[3]=21;
 facetid++;

 facetid->color=LIGHTGRAY;
 facetid->nedges=4;
 facetid->edge[0]=19;
 facetid->edge[1]=23;
 facetid->edge[2]=22;
 facetid->edge[3]=18;
 facetid++;

 facetid->color=LIGHTGRAY;
 facetid->nedges=4;
 facetid->edge[0]=16;
 facetid->edge[1]=20;
 facetid->edge[2]=23;
 facetid->edge[3]=19;
 facetid++;

 /* rear island extension */
 facetid->color=LIGHTGRAY;
 facetid->nedges=4;
 facetid->edge[0]=24;
 facetid->edge[1]=25;
 facetid->edge[2]=29;
 facetid->edge[3]=28;
 facetid++;

 facetid->color=LIGHTGRAY;
 facetid->nedges=4;
 facetid->edge[0]=25;
 facetid->edge[1]=26;
 facetid->edge[2]=30;
 facetid->edge[3]=29;
 facetid++;

 facetid->color=LIGHTGRAY;
 facetid->nedges=4;
 facetid->edge[0]=26;
 facetid->edge[1]=27;
 facetid->edge[2]=31;
 facetid->edge[3]=30;
 facetid++;

 facetid->color=LIGHTGRAY;
 facetid->nedges=4;
 facetid->edge[0]=27;
 facetid->edge[1]=24;
 facetid->edge[2]=28;
 facetid->edge[3]=31;
 facetid++;

 facetid->color=LIGHTGRAY;
 facetid->nedges=4;
 facetid->edge[0]=27;
 facetid->edge[1]=26;
 facetid->edge[2]=25;
 facetid->edge[3]=24;
 facetid++;

 facetid->color=LIGHTGRAY;
 facetid->nedges=4;
 facetid->edge[0]=28;
 facetid->edge[1]=29;
 facetid->edge[2]=30;
 facetid->edge[3]=31;
 facetid++;

 /* Island top */
 facetid->color=LIGHTGRAY;
 facetid->nedges=4;
 facetid->edge[0]=32;
 facetid->edge[1]=33;
 facetid->edge[2]=39;
 facetid->edge[3]=38;
 facetid++;

 facetid->color=LIGHTGRAY;
 facetid->nedges=4;
 facetid->edge[0]=33;
 facetid->edge[1]=34;
 facetid->edge[2]=40;
 facetid->edge[3]=39;
 facetid++;

 facetid->color=LIGHTGRAY;
 facetid->nedges=4;
 facetid->edge[0]=34;
 facetid->edge[1]=35;
 facetid->edge[2]=41;
 facetid->edge[3]=40;
 facetid++;

 facetid->color=LIGHTGRAY;
 facetid->nedges=4;
 facetid->edge[0]=44;
 facetid->edge[1]=45;
 facetid->edge[2]=42;
 facetid->edge[3]=41;
 facetid++;

 facetid->color=LIGHTGRAY;
 facetid->nedges=4;
 facetid->edge[0]=36;
 facetid->edge[1]=37;
 facetid->edge[2]=43;
 facetid->edge[3]=42;
 facetid++;

 facetid->color=LIGHTGRAY;
 facetid->nedges=4;
 facetid->edge[0]=37;
 facetid->edge[1]=32;
 facetid->edge[2]=38;
 facetid->edge[3]=43;
 facetid++;

 facetid->color=LIGHTGRAY;
 facetid->nedges=5;
 facetid->edge[0]=46;
 facetid->edge[1]=35;
 facetid->edge[2]=34;
 facetid->edge[3]=33;
 facetid->edge[4]=32;
 facetid++;

 facetid->color=LIGHTGRAY;
 facetid->nedges=6;
 facetid->edge[0]=38;
 facetid->edge[1]=39;
 facetid->edge[2]=40;
 facetid->edge[3]=41;
 facetid->edge[4]=42;
 facetid->edge[5]=43;
 facetid++;

 facetid->color=LIGHTGRAY;
 facetid->nedges=4;
 facetid->edge[0]=46;
 facetid->edge[1]=37;
 facetid->edge[2]=23;
 facetid->edge[3]=20;
 facetid++;

 facetid->color=DARKGRAY_SHADE;
 facetid->nedges=4;
 facetid->edge[0]=47;
 facetid->edge[1]=48;
 facetid->edge[2]=49;
 facetid->edge[3]=50;
 facetid++;

 facetid->color=LIGHTGRAY;
 facetid->nedges=4;
 facetid->edge[0]=50;
 facetid->edge[1]=49;
 facetid->edge[2]=48;
 facetid->edge[3]=47;
 facetid++;

 facetid->color=LIGHTGRAY;
 facetid->nedges=3;
 facetid->edge[0]=51;
 facetid->edge[1]=54;
 facetid->edge[2]=55;
 facetid++;

 facetid->color=LIGHTGRAY;
 facetid->nedges=3;
 facetid->edge[0]=54;
 facetid->edge[1]=53;
 facetid->edge[2]=55;
 facetid++;

 facetid->color=LIGHTGRAY;
 facetid->nedges=3;
 facetid->edge[0]=53;
 facetid->edge[1]=52;
 facetid->edge[2]=55;
 facetid++;

 facetid->color=LIGHTGRAY;
 facetid->nedges=3;
 facetid->edge[0]=52;
 facetid->edge[1]=51;
 facetid->edge[2]=55;
 facetid++;

 facetid->color=DARKGRAY_SHADE;
 facetid->nedges=4;
 facetid->edge[0]=56;
 facetid->edge[1]=57;
 facetid->edge[2]=58;
 facetid->edge[3]=59;
 facetid++;

 facetid->color=DARKGRAY_SHADE;
 facetid->nedges=4;
 facetid->edge[0]=59;
 facetid->edge[1]=58;
 facetid->edge[2]=57;
 facetid->edge[3]=56;
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
