
 id=NIMITZ_HULL;
 object[id].max_draw_dist=15000;
 object[id].always_draw_dist=3000;

 object[id].nvertices =  40;
 object[id].nfacets   =  20;
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

 (object[id].vertex+14)->x=-128.5;
 (object[id].vertex+14)->y= -22.0;
 (object[id].vertex+14)->z=  20.0;

 (object[id].vertex+15)->x=-114.7;
 (object[id].vertex+15)->y= -20.6;
 (object[id].vertex+15)->z=  20.0;

 (object[id].vertex+16)->x=-110.0;
 (object[id].vertex+16)->y= -25.7;
 (object[id].vertex+16)->z=  20.0;

 /* Hull */
 (object[id].vertex+17)->x=-129.0;
 (object[id].vertex+17)->y= -16.7;
 (object[id].vertex+17)->z=  20.0;

 (object[id].vertex+18)->x=-129.0;
 (object[id].vertex+18)->y= -16.7;
 (object[id].vertex+18)->z=   0.0;

 (object[id].vertex+19)->x=-131.0;
 (object[id].vertex+19)->y=  16.7;
 (object[id].vertex+19)->z=   0.0;

 (object[id].vertex+20)->x= 119.1;
 (object[id].vertex+20)->y=  19.5;
 (object[id].vertex+20)->z=   0.0;

 (object[id].vertex+21)->x= 119.1;
 (object[id].vertex+21)->y= -20.6;
 (object[id].vertex+21)->z=   0.0;

 (object[id].vertex+22)->x= 189.2;
 (object[id].vertex+22)->y=   0.0;
 (object[id].vertex+22)->z=   5.8;

 (object[id].vertex+23)->x= 189.2;
 (object[id].vertex+23)->y=   0.0;
 (object[id].vertex+23)->z=   0.0;

 (object[id].vertex+24)->x= -52.2;
 (object[id].vertex+24)->y= -20.0;
 (object[id].vertex+24)->z=  20.0;

 (object[id].vertex+25)->x= -52.2;
 (object[id].vertex+25)->y= -20.0;
 (object[id].vertex+25)->z=   0.0;

 (object[id].vertex+26)->x= -52.0;
 (object[id].vertex+26)->y= -20.0;
 (object[id].vertex+26)->z=   6.0;

 (object[id].vertex+27)->x=  -2.0;
 (object[id].vertex+27)->y= -20.0;
 (object[id].vertex+27)->z=  20.0;

 (object[id].vertex+28)->x=  -2.0;
 (object[id].vertex+28)->y= -20.0;
 (object[id].vertex+28)->z=   6.0;

 (object[id].vertex+29)->x=  -2.0;
 (object[id].vertex+29)->y= -20.0;
 (object[id].vertex+29)->z=   0.0;

 (object[id].vertex+30)->x= -52.0;
 (object[id].vertex+30)->y= -34.8;
 (object[id].vertex+30)->z=  20.0;

 (object[id].vertex+31)->x=  -2.0;
 (object[id].vertex+31)->y= -34.8;
 (object[id].vertex+31)->z=  20.0;

 (object[id].vertex+32)->x= -91.8;
 (object[id].vertex+32)->y=  19.6;
 (object[id].vertex+32)->z=   0.0;

 (object[id].vertex+33)->x=  80.0;
 (object[id].vertex+33)->y=  19.6;
 (object[id].vertex+33)->z=   6.0;

 (object[id].vertex+34)->x=  80.0;
 (object[id].vertex+34)->y=  19.6;
 (object[id].vertex+34)->z=   0.0;

 (object[id].vertex+35)->x= -10.0;
 (object[id].vertex+35)->y=  19.6;
 (object[id].vertex+35)->z=  20.0;

 (object[id].vertex+36)->x= -10.0;
 (object[id].vertex+36)->y=  19.6;
 (object[id].vertex+36)->z=   0.0;

 /* Koelvand */
 (object[id].vertex+37)->x=-300.0;
 (object[id].vertex+37)->y=  30.0;
 (object[id].vertex+37)->z=   0.0;

 (object[id].vertex+38)->x=-300.0;
 (object[id].vertex+38)->y= -30.0;
 (object[id].vertex+38)->z=   0.0;

 (object[id].vertex+39)->x=-400.0;
 (object[id].vertex+39)->y=   0.0;
 (object[id].vertex+39)->z=   0.0;

 /*
 (object[id].vertex+)->x=;
 (object[id].vertex+)->y=;
 (object[id].vertex+)->z=;
 */

 /**********/
 /* Facets */
 /**********/



 /* 0 Hull */
 facetid->color=LIGHTGRAY;
 facetid->nedges=4;
 facetid->edge[0]=12;
 facetid->edge[1]=19;
 facetid->edge[2]=18;
 facetid->edge[3]=17;
 facetid++;

 facetid->color=LIGHTGRAY;
 facetid->nedges=3;
 facetid->edge[0]=1;
 facetid->edge[1]=0;
 facetid->edge[2]=22;
 facetid++;

 facetid->color=LIGHTGRAY;
 facetid->nedges=3;
 facetid->edge[0]=0;
 facetid->edge[1]=3;
 facetid->edge[2]=22;
 facetid++;

 facetid->color=LIGHTGRAY;
 facetid->nedges=3;
 facetid->edge[0]=2;
 facetid->edge[1]=1;
 facetid->edge[2]=22;
 facetid++;

 facetid->color=LIGHTGRAY;
 facetid->nedges=4;
 facetid->edge[0]=3;
 facetid->edge[1]=21;
 facetid->edge[2]=23;
 facetid->edge[3]=22;
 facetid++;

 facetid->color=LIGHTGRAY;
 facetid->nedges=4;
 facetid->edge[0]=20;
 facetid->edge[1]=2;
 facetid->edge[2]=22;
 facetid->edge[3]=23;
 facetid++;

 facetid->color=LIGHTGRAY;
 facetid->nedges=4;
 facetid->edge[0]=24;
 facetid->edge[1]=17;
 facetid->edge[2]=18;
 facetid->edge[3]=25;
 facetid++;

 facetid->color=LIGHTGRAY;
 facetid->nedges=4;
 facetid->edge[0]=28;
 facetid->edge[1]=26;
 facetid->edge[2]=25;
 facetid->edge[3]=29;
 facetid++;

 facetid->color=LIGHTGRAY;
 facetid->nedges=4;
 facetid->edge[0]=3;
 facetid->edge[1]=27;
 facetid->edge[2]=29;
 facetid->edge[3]=21;
 facetid++;

 facetid->color=LIGHTGRAY;
 facetid->nedges=4;
 facetid->edge[0]=31;
 facetid->edge[1]=30;
 facetid->edge[2]=26;
 facetid->edge[3]=28;
 facetid++;

 facetid->color=LIGHTGRAY;
 facetid->nedges=3;
 facetid->edge[0]=30;
 facetid->edge[1]=24;
 facetid->edge[2]=26;
 facetid++;

 facetid->color=LIGHTGRAY;
 facetid->nedges=3;
 facetid->edge[0]=27;
 facetid->edge[1]=31;
 facetid->edge[2]=28;
 facetid++;

 facetid->color=LIGHTGRAY;
 facetid->nedges=4;
 facetid->edge[0]=12;
 facetid->edge[1]=9;
 facetid->edge[2]=32;
 facetid->edge[3]=19;
 facetid++;

 facetid->color=LIGHTGRAY;
 facetid->nedges=3;
 facetid->edge[0]=5;
 facetid->edge[1]=4;
 facetid->edge[2]=33;
 facetid++;

 facetid->color=LIGHTGRAY;
 facetid->nedges=3;
 facetid->edge[0]=4;
 facetid->edge[1]=2;
 facetid->edge[2]=33;
 facetid++;

 facetid->color=LIGHTGRAY;
 facetid->nedges=4;
 facetid->edge[0]=2;
 facetid->edge[1]=20;
 facetid->edge[2]=34;
 facetid->edge[3]=33;
 facetid++;

 facetid->color=LIGHTGRAY;
 facetid->nedges=4;
 facetid->edge[0]=9;
 facetid->edge[1]=35;
 facetid->edge[2]=36;
 facetid->edge[3]=32;
 facetid++;

 facetid->color=LIGHTGRAY;
 facetid->nedges=3;
 facetid->edge[0]=35;
 facetid->edge[1]=5;
 facetid->edge[2]=33;
 facetid++;

 facetid->color=LIGHTGRAY;
 facetid->nedges=4;
 facetid->edge[0]=35;
 facetid->edge[1]=33;
 facetid->edge[2]=34;
 facetid->edge[3]=36;
 facetid++;

 /*20*/

 facetid->color=WHITE;
 facetid->nedges=5;
 facetid->edge[0]=18;
 facetid->edge[1]=19;
 facetid->edge[2]=37;
 facetid->edge[3]=39;
 facetid->edge[4]=38;
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
