
 id=NIMITZ_JBD;
 object[id].max_draw_dist=2000;
 object[id].always_draw_dist=700;

 object[id].nvertices = 4*4;
 object[id].nfacets   = 2*4;
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


 /* Jet blast deflectors */
 (object[id].vertex+0)->x=-38.1;
 (object[id].vertex+0)->y= 29.0;
 (object[id].vertex+0)->z= 20.0;

 (object[id].vertex+1)->x=-38.1;
 (object[id].vertex+1)->y= 36.4;
 (object[id].vertex+1)->z= 20.0;

 (object[id].vertex+2)->x=-40.9;
 (object[id].vertex+2)->y= 36.4;
 (object[id].vertex+2)->z= 20.0;

 (object[id].vertex+3)->x=-40.9;
 (object[id].vertex+3)->y= 29.0;
 (object[id].vertex+3)->z= 20.0;


 (object[id].vertex+4)->x=-18.9;
 (object[id].vertex+4)->y= 14.4;
 (object[id].vertex+4)->z= 20.0;

 (object[id].vertex+5)->x=-18.9;
 (object[id].vertex+5)->y= 25.2;
 (object[id].vertex+5)->z= 20.0;

 (object[id].vertex+6)->x=-22.7;
 (object[id].vertex+6)->y= 25.2;
 (object[id].vertex+6)->z= 20.0;

 (object[id].vertex+7)->x=-22.7;
 (object[id].vertex+7)->y= 14.4;
 (object[id].vertex+7)->z= 20.0;


 (object[id].vertex+8)->x= 70.6;
 (object[id].vertex+8)->y=  0.3;
 (object[id].vertex+8)->z= 20.0;

 (object[id].vertex+9)->x= 70.6;
 (object[id].vertex+9)->y= 10.2;
 (object[id].vertex+9)->z= 20.0;

 (object[id].vertex+10)->x= 66.8;
 (object[id].vertex+10)->y= 10.2;
 (object[id].vertex+10)->z= 20.0;

 (object[id].vertex+11)->x= 66.8;
 (object[id].vertex+11)->y=  0.3;
 (object[id].vertex+11)->z= 20.0;


 (object[id].vertex+12)->x= 77.9;
 (object[id].vertex+12)->y=-22.9;
 (object[id].vertex+12)->z= 20.0;

 (object[id].vertex+13)->x= 77.9;
 (object[id].vertex+13)->y=-13.2;
 (object[id].vertex+13)->z= 20.0;

 (object[id].vertex+14)->x= 74.1;
 (object[id].vertex+14)->y=-13.2;
 (object[id].vertex+14)->z= 20.0;

 (object[id].vertex+15)->x= 74.1;
 (object[id].vertex+15)->y=-22.9;
 (object[id].vertex+15)->z= 20.0;

 /*
 (object[id].vertex+)->x=;
 (object[id].vertex+)->y=;
 (object[id].vertex+)->z=;
 */

 /**********/
 /* Facets */
 /**********/

 /* JBD */
 facetid->color=DARKGRAY_SHADE;
 facetid->nedges=4;
 facetid->edge[0]=0;
 facetid->edge[1]=1;
 facetid->edge[2]=2;
 facetid->edge[3]=3;
 facetid++;

 facetid->color=DARKGRAY_SHADE;
 facetid->nedges=4;
 facetid->edge[0]=0;
 facetid->edge[1]=3;
 facetid->edge[2]=2;
 facetid->edge[3]=1;
 facetid++;

 facetid->color=DARKGRAY_SHADE;
 facetid->nedges=4;
 facetid->edge[0]=4;
 facetid->edge[1]=5;
 facetid->edge[2]=6;
 facetid->edge[3]=7;
 facetid++;

 facetid->color=DARKGRAY_SHADE;
 facetid->nedges=4;
 facetid->edge[0]=4;
 facetid->edge[1]=7;
 facetid->edge[2]=6;
 facetid->edge[3]=5;
 facetid++;

 facetid->color=DARKGRAY_SHADE;
 facetid->nedges=4;
 facetid->edge[0]= 8;
 facetid->edge[1]= 9;
 facetid->edge[2]=10;
 facetid->edge[3]=11;
 facetid++;

 facetid->color=DARKGRAY_SHADE;
 facetid->nedges=4;
 facetid->edge[0]= 8;
 facetid->edge[1]=11;
 facetid->edge[2]=10;
 facetid->edge[3]= 9;
 facetid++;

 facetid->color=DARKGRAY_SHADE;
 facetid->nedges=4;
 facetid->edge[0]=12;
 facetid->edge[1]=13;
 facetid->edge[2]=14;
 facetid->edge[3]=15;
 facetid++;

 facetid->color=DARKGRAY_SHADE;
 facetid->nedges=4;
 facetid->edge[0]=12;
 facetid->edge[1]=15;
 facetid->edge[2]=14;
 facetid->edge[3]=13;
 facetid++;


 if (object[id].facet+object[id].nfacets!=facetid)
    errormessage("Incorrect number of facets\n");

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
