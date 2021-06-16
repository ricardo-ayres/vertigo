
 id=NIMITZ_DECK;
 object[id].max_draw_dist=15000;
 object[id].always_draw_dist=3000;

 object[id].nvertices =  37;
 object[id].nfacets   =   8;
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

 /* Deck */
 (object[id].vertex+0)->x=  199.3;
 (object[id].vertex+0)->y=  -13.2;
 (object[id].vertex+0)->z=   20.0;

 (object[id].vertex+1)->x=  199.3;
 (object[id].vertex+1)->y=   13.2;
 (object[id].vertex+1)->z=   20.0;

 (object[id].vertex+2)->x=  119.1;
 (object[id].vertex+2)->y=   19.5;
 (object[id].vertex+2)->z=   20.0;

 (object[id].vertex+3)->x=  119.1;
 (object[id].vertex+3)->y=  -20.6;
 (object[id].vertex+3)->z=   20.0;

 (object[id].vertex+4)->x=   92.8;
 (object[id].vertex+4)->y=   41.8;
 (object[id].vertex+4)->z=   20.0;

 (object[id].vertex+5)->x=   65.7;
 (object[id].vertex+5)->y=   41.8;
 (object[id].vertex+5)->z=   20.0;

 (object[id].vertex+6)->x=   48.2;
 (object[id].vertex+6)->y=   36.7;
 (object[id].vertex+6)->z=   20.0;

 (object[id].vertex+7)->x=   98.0;
 (object[id].vertex+7)->y=  -34.8;
 (object[id].vertex+7)->z=   20.0;

 (object[id].vertex+8)->x=  -86.5;
 (object[id].vertex+8)->y=   37.9;
 (object[id].vertex+8)->z=   20.0;

 (object[id].vertex+9)->x=  -91.8;
 (object[id].vertex+9)->y=   19.6;
 (object[id].vertex+9)->z=   20.0;

 (object[id].vertex+10)->x= -80.1;
 (object[id].vertex+10)->y= -28.8;
 (object[id].vertex+10)->z=  20.0;

 (object[id].vertex+11)->x= -78.0;
 (object[id].vertex+11)->y= -34.8;
 (object[id].vertex+11)->z=  20.0;

 (object[id].vertex+12)->x=-131.0;
 (object[id].vertex+12)->y=  16.7;
 (object[id].vertex+12)->z=  20.0;

 (object[id].vertex+13)->x=-132.3;
 (object[id].vertex+13)->y=   6.6;
 (object[id].vertex+13)->z=  20.0;

 (object[id].vertex+14)->x=-127.7;
 (object[id].vertex+14)->y= -22.0;
 (object[id].vertex+14)->z=  20.0;

 (object[id].vertex+15)->x=-114.7;
 (object[id].vertex+15)->y= -20.6;
 (object[id].vertex+15)->z=  20.0;

 (object[id].vertex+16)->x=-110.0;
 (object[id].vertex+16)->y= -25.7;
 (object[id].vertex+16)->z=  20.0;

 /*Bageste aabning */
 (object[id].vertex+17)->x=-131.0;
 (object[id].vertex+17)->y=  14.0;
 (object[id].vertex+17)->z=  17.0;

 (object[id].vertex+18)->x=-130.0;
 (object[id].vertex+18)->y= -14.0;
 (object[id].vertex+18)->z=  17.0;

 (object[id].vertex+19)->x=-131.0;
 (object[id].vertex+19)->y=  14.0;
 (object[id].vertex+19)->z=   8.0;

 (object[id].vertex+20)->x=-130.0;
 (object[id].vertex+20)->y= -14.0;
 (object[id].vertex+20)->z=   8.0;

 /* Hangar ports */
 (object[id].vertex+21)->x= -75.5;
 (object[id].vertex+21)->y= -20.0;
 (object[id].vertex+21)->z=  16.0;

 (object[id].vertex+22)->x= -75.5;
 (object[id].vertex+22)->y= -20.0;
 (object[id].vertex+22)->z=   9.0;

 (object[id].vertex+23)->x= -56.0;
 (object[id].vertex+23)->y= -20.0;
 (object[id].vertex+23)->z=   9.0;

 (object[id].vertex+24)->x= -56.0;
 (object[id].vertex+24)->y= -20.0;
 (object[id].vertex+24)->z=  16.0;


 (object[id].vertex+25)->x=   1.5;
 (object[id].vertex+25)->y= -20.0;
 (object[id].vertex+25)->z=  16.0;

 (object[id].vertex+26)->x=   1.5;
 (object[id].vertex+26)->y= -20.0;
 (object[id].vertex+26)->z=   9.0;

 (object[id].vertex+27)->x=  21.0;
 (object[id].vertex+27)->y= -20.0;
 (object[id].vertex+27)->z=   9.0;

 (object[id].vertex+28)->x=  21.0;
 (object[id].vertex+28)->y= -20.0;
 (object[id].vertex+28)->z=  16.0;


 (object[id].vertex+29)->x=  47.5;
 (object[id].vertex+29)->y= -20.0;
 (object[id].vertex+29)->z=  16.0;

 (object[id].vertex+30)->x=  47.5;
 (object[id].vertex+30)->y= -20.0;
 (object[id].vertex+30)->z=   9.0;

 (object[id].vertex+31)->x=  67.0;
 (object[id].vertex+31)->y= -20.0;
 (object[id].vertex+31)->z=   9.0;

 (object[id].vertex+32)->x=  67.0;
 (object[id].vertex+32)->y= -20.0;
 (object[id].vertex+32)->z=  16.0;


 (object[id].vertex+33)->x= -63.0;
 (object[id].vertex+33)->y=  20.0;
 (object[id].vertex+33)->z=  16.0;

 (object[id].vertex+34)->x= -63.0;
 (object[id].vertex+34)->y=  20.0;
 (object[id].vertex+34)->z=   9.0;

 (object[id].vertex+35)->x= -82.5;
 (object[id].vertex+35)->y=  20.0;
 (object[id].vertex+35)->z=   9.0;

 (object[id].vertex+36)->x= -82.5;
 (object[id].vertex+36)->y=  20.0;
 (object[id].vertex+36)->z=  16.0;


 /*
 (object[id].vertex+)->x=;
 (object[id].vertex+)->y=;
 (object[id].vertex+)->z=;
 */

 /**********/
 /* Facets */
 /**********/

 /*0 Deck */
 facetid->color=DARKGRAY;
 facetid->nedges=8;
 facetid->edge[0]=0;
 facetid->edge[1]=1;
 facetid->edge[2]=2;
 facetid->edge[3]=4;
 facetid->edge[4]=5;
 facetid->edge[5]=6;
 facetid->edge[6]=7;
 facetid->edge[7]=3;
 facetid++;

 facetid->color=DARKGRAY;
 facetid->nedges=6;
 facetid->edge[0]=7;
 facetid->edge[1]=6;
 facetid->edge[2]=8;
 facetid->edge[3]=9;
 facetid->edge[4]=10;
 facetid->edge[5]=11;
 facetid++;

 facetid->color=DARKGRAY;
 facetid->nedges=7;
 facetid->edge[0]=9;
 facetid->edge[1]=12;
 facetid->edge[2]=13;
 facetid->edge[3]=14;
 facetid->edge[4]=15;
 facetid->edge[5]=16;
 facetid->edge[6]=10;
 facetid++;


 facetid->color=DARKGRAY;
 facetid->nedges=4;
 facetid->edge[0]=18;
 facetid->edge[1]=17;
 facetid->edge[2]=19;
 facetid->edge[3]=20;
 facetid++;


 facetid->color=DARKGRAY_SHADE;
 facetid->nedges=4;
 facetid->edge[0]=21;
 facetid->edge[1]=22;
 facetid->edge[2]=23;
 facetid->edge[3]=24;
 facetid++;

 facetid->color=DARKGRAY_SHADE;
 facetid->nedges=4;
 facetid->edge[0]=25;
 facetid->edge[1]=26;
 facetid->edge[2]=27;
 facetid->edge[3]=28;
 facetid++;


 facetid->color=DARKGRAY_SHADE;
 facetid->nedges=4;
 facetid->edge[0]=29;
 facetid->edge[1]=30;
 facetid->edge[2]=31;
 facetid->edge[3]=32;
 facetid++;


 facetid->color=DARKGRAY_SHADE;
 facetid->nedges=4;
 facetid->edge[0]=33;
 facetid->edge[1]=34;
 facetid->edge[2]=35;
 facetid->edge[3]=36;
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
