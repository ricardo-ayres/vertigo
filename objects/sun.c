
 id=SUN;
 object[id].max_draw_dist=30000;
 object[id].always_draw_dist=1600;

 object[id].nvertices =   8;
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

 for (i=0; i<8; i++){
  (object[id].vertex+i)->x=0;
  (object[id].vertex+i)->y=0;
  (object[id].vertex+i)->z=0;
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
 facetid->color=WHITE;
 facetid->nedges=8;
 facetid->edge[0]=0;
 facetid->edge[1]=1;
 facetid->edge[2]=2;
 facetid->edge[3]=3;
 facetid->edge[4]=4;
 facetid->edge[5]=5;
 facetid->edge[6]=6;
 facetid->edge[7]=7;
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
