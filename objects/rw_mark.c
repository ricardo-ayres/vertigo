
 id=RW_MARK;
 object[id].max_draw_dist=4000;
 object[id].always_draw_dist=2000;

 object[id].nvertices =15*4;
 object[id].nfacets   =  15;
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

 for (i=0; i<15; i++) {

     (object[id].vertex+i*4  )->x=-20-700+100*i;
     (object[id].vertex+i*4  )->y=  0.5;
     (object[id].vertex+i*4  )->z=  0.0;

     (object[id].vertex+i*4+1)->x=-20-700+100*i;
     (object[id].vertex+i*4+1)->y=- 0.5;
     (object[id].vertex+i*4+1)->z=  0.0;

     (object[id].vertex+i*4+2)->x= 20-700+100*i;
     (object[id].vertex+i*4+2)->y=- 0.5;
     (object[id].vertex+i*4+2)->z=  0.0;

     (object[id].vertex+i*4+3)->x= 20-700+100*i;
     (object[id].vertex+i*4+3)->y=  0.5;
     (object[id].vertex+i*4+3)->z=  0.0;
 }

 /*
 (object[id].vertex+)->x=;
 (object[id].vertex+)->y=;
 (object[id].vertex+)->z=;
 */

 /**********/
 /* Facets */
 /**********/

 /*0 */

 for (i=0; i<15; i++) {
     facetid->color=WHITE;
     facetid->nedges=4;
     facetid->edge[0]=0+4*i;
     facetid->edge[1]=1+4*i;
     facetid->edge[2]=2+4*i;
     facetid->edge[3]=3+4*i;
     facetid++;
     }

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
