
 id=RUNWAY;
 object[id].max_draw_dist=20000;
 object[id].always_draw_dist=5000;

 object[id].nvertices =  18;
 object[id].nfacets   =   5;
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

 /* runway */
 (object[id].vertex+0)->x= -750.0;
 (object[id].vertex+0)->y=   20.0;
 (object[id].vertex+0)->z=    0.0;

 (object[id].vertex+1)->x= -750.0;
 (object[id].vertex+1)->y=  -20.0;
 (object[id].vertex+1)->z=    0.0;

 (object[id].vertex+2)->x=  750.0;
 (object[id].vertex+2)->y=  -20.0;
 (object[id].vertex+2)->z=    0.0;

 (object[id].vertex+3)->x=  750.0;
 (object[id].vertex+3)->y=   20.0;
 (object[id].vertex+3)->z=    0.0;

 (object[id].vertex+4)->x= -720.0;
 (object[id].vertex+4)->y=   20.0;
 (object[id].vertex+4)->z=    0.0;

 (object[id].vertex+5)->x= -700.0;
 (object[id].vertex+5)->y=   20.0;
 (object[id].vertex+5)->z=    0.0;

 (object[id].vertex+6)->x= -700.0;
 (object[id].vertex+6)->y=  100.0;
 (object[id].vertex+6)->z=    0.0;

 (object[id].vertex+7)->x= -720.0;
 (object[id].vertex+7)->y=  100.0;
 (object[id].vertex+7)->z=    0.0;

 (object[id].vertex+8)->x=  720.0;
 (object[id].vertex+8)->y=   20.0;
 (object[id].vertex+8)->z=    0.0;

 (object[id].vertex+9)->x=  720.0;
 (object[id].vertex+9)->y=  100.0;
 (object[id].vertex+9)->z=    0.0;

 (object[id].vertex+10)->x= 700.0;
 (object[id].vertex+10)->y= 100.0;
 (object[id].vertex+10)->z=   0.0;

 (object[id].vertex+11)->x= 700.0;
 (object[id].vertex+11)->y=  20.0;
 (object[id].vertex+11)->z=   0.0;

 (object[id].vertex+12)->x= 720.0;
 (object[id].vertex+12)->y= 120.0;
 (object[id].vertex+12)->z=   0.0;

 (object[id].vertex+13)->x=-720.0;
 (object[id].vertex+13)->y= 120.0;
 (object[id].vertex+13)->z=   0.0;

 (object[id].vertex+14)->x= 350.0;
 (object[id].vertex+14)->y= 120.0;
 (object[id].vertex+14)->z=   0.0;

 (object[id].vertex+15)->x= 350.0;
 (object[id].vertex+15)->y= 150.0;
 (object[id].vertex+15)->z=   0.0;

 (object[id].vertex+16)->x= 150.0;
 (object[id].vertex+16)->y= 150.0;
 (object[id].vertex+16)->z=   0.0;

 (object[id].vertex+17)->x= 150.0;
 (object[id].vertex+17)->y= 120.0;
 (object[id].vertex+17)->z=   0.0;

 /*
 (object[id].vertex+)->x=;
 (object[id].vertex+)->y=;
 (object[id].vertex+)->z=;
 */

 /**********/
 /* Facets */
 /**********/

 /*0 */
 facetid->color=DARKGRAY;
 facetid->nedges=4;
 facetid->edge[0]=0;
 facetid->edge[1]=1;
 facetid->edge[2]=2;
 facetid->edge[3]=3;
 facetid++;

 facetid->color=DARKGRAY;
 facetid->nedges=4;
 facetid->edge[0]=8;
 facetid->edge[1]=9;
 facetid->edge[2]=10;
 facetid->edge[3]=11;
 facetid++;

 facetid->color=DARKGRAY;
 facetid->nedges=4;
 facetid->edge[0]=5;
 facetid->edge[1]=6;
 facetid->edge[2]=7;
 facetid->edge[3]=4;
 facetid++;

 facetid->color=DARKGRAY;
 facetid->nedges=4;
 facetid->edge[0]=12;
 facetid->edge[1]=13;
 facetid->edge[2]=7;
 facetid->edge[3]=9;
 facetid++;

 facetid->color=DARKGRAY;
 facetid->nedges=4;
 facetid->edge[0]=14;
 facetid->edge[1]=15;
 facetid->edge[2]=16;
 facetid->edge[3]=17;
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
