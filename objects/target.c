
 id=TARGET;
 object[id].max_draw_dist=10000;
 object[id].always_draw_dist=500;

 object[id].nvertices =   6;
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


 (object[id].vertex+0)->x= -2;
 (object[id].vertex+0)->y=  2;
 (object[id].vertex+0)->z=  0;

 (object[id].vertex+1)->x= -2;
 (object[id].vertex+1)->y= -2;
 (object[id].vertex+1)->z=  0;

 (object[id].vertex+2)->x=  2;
 (object[id].vertex+2)->y= -2;
 (object[id].vertex+2)->z=  0;

 (object[id].vertex+3)->x=  2;
 (object[id].vertex+3)->y=  2;
 (object[id].vertex+3)->z=  0;

 (object[id].vertex+4)->x=  0;
 (object[id].vertex+4)->y=  0;
 (object[id].vertex+4)->z=  3.5;

 (object[id].vertex+5)->x=  0;
 (object[id].vertex+5)->y=  0;
 (object[id].vertex+5)->z= -3.5;

 /*
 (object[id].vertex+)->x=;
 (object[id].vertex+)->y=;
 (object[id].vertex+)->z=;
 */

 /**********/
 /* Facets */
 /**********/



 facetid->color=   LIGHTRED;
 facetid->nedges=  3;
 facetid->edge[0]= 0;
 facetid->edge[1]= 1;
 facetid->edge[2]= 4;
 facetid++;

 facetid->color=   WHITE;
 facetid->nedges=  3;
 facetid->edge[0]= 1;
 facetid->edge[1]= 2;
 facetid->edge[2]= 4;
 facetid++;

 facetid->color=   LIGHTRED;
 facetid->nedges=  3;
 facetid->edge[0]= 2;
 facetid->edge[1]= 3;
 facetid->edge[2]= 4;
 facetid++;

 facetid->color=   WHITE;
 facetid->nedges=  3;
 facetid->edge[0]= 3;
 facetid->edge[1]= 0;
 facetid->edge[2]= 4;
 facetid++;

 facetid->color=   WHITE;
 facetid->nedges=  3;
 facetid->edge[0]= 1;
 facetid->edge[1]= 0;
 facetid->edge[2]= 5;
 facetid++;

 facetid->color=   LIGHTRED;
 facetid->nedges=  3;
 facetid->edge[0]= 2;
 facetid->edge[1]= 1;
 facetid->edge[2]= 5;
 facetid++;

 facetid->color=   WHITE;
 facetid->nedges=  3;
 facetid->edge[0]= 3;
 facetid->edge[1]= 2;
 facetid->edge[2]= 5;
 facetid++;

 facetid->color=   LIGHTRED;
 facetid->nedges=  3;
 facetid->edge[0]= 0;
 facetid->edge[1]= 3;
 facetid->edge[2]= 5;
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
