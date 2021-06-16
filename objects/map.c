
 id=MAP;
 object[id].max_draw_dist=30000;
 object[id].always_draw_dist=1600;

 object[id].nvertices =   3;
 object[id].nfacets   =   1;
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

 /* map-triangle */
 (object[id].vertex+0)->x=    0.0;
 (object[id].vertex+0)->y=    0.0;
 (object[id].vertex+0)->z=    0.0;

 (object[id].vertex+1)->x=    0.0;
 (object[id].vertex+1)->y=    0.0;
 (object[id].vertex+1)->z=    0.0;

 (object[id].vertex+2)->x=    0.0;
 (object[id].vertex+2)->y=    0.0;
 (object[id].vertex+2)->z=    0.0;

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
 facetid->nedges=3;
 facetid->edge[0]=0;
 facetid->edge[1]=1;
 facetid->edge[2]=2;
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
