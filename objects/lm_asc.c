
 id=LM_ASCENT;
 object[id].max_draw_dist=10000;
 object[id].always_draw_dist=500;

 object[id].nvertices =  12;
 object[id].nfacets   =   9;
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

 (object[id].vertex+0)->x= -1.5;
 (object[id].vertex+0)->y=  1.5;
 (object[id].vertex+0)->z=  0;

 (object[id].vertex+1)->x= -1.5;
 (object[id].vertex+1)->y= -1.5;
 (object[id].vertex+1)->z=  0;

 (object[id].vertex+2)->x=  1.5;
 (object[id].vertex+2)->y= -1.5;
 (object[id].vertex+2)->z=  0;

 (object[id].vertex+3)->x=  1.5;
 (object[id].vertex+3)->y=  1.5;
 (object[id].vertex+3)->z=  0;

 (object[id].vertex+4)->x= -1.5;
 (object[id].vertex+4)->y=  1.5;
 (object[id].vertex+4)->z=  2;

 (object[id].vertex+5)->x= -1.5;
 (object[id].vertex+5)->y= -1.5;
 (object[id].vertex+5)->z=  2;

 (object[id].vertex+6)->x=  1.5;
 (object[id].vertex+6)->y= -1.5;
 (object[id].vertex+6)->z=  2;

 (object[id].vertex+7)->x=  1.5;
 (object[id].vertex+7)->y=  1.5;
 (object[id].vertex+7)->z=  2;

 (object[id].vertex+8)->x= -1;
 (object[id].vertex+8)->y=  1;
 (object[id].vertex+8)->z=  3;

 (object[id].vertex+9)->x= -1;
 (object[id].vertex+9)->y= -1;
 (object[id].vertex+9)->z=  3;

 (object[id].vertex+10)->x=  1;
 (object[id].vertex+10)->y= -1;
 (object[id].vertex+10)->z=  3;

 (object[id].vertex+11)->x=  1;
 (object[id].vertex+11)->y=  1;
 (object[id].vertex+11)->z=  3;

 /*
 (object[id].vertex+)->x=;
 (object[id].vertex+)->y=;
 (object[id].vertex+)->z=;
 */

 /**********/
 /* Facets */
 /**********/



 facetid->color=   WHITE;
 facetid->nedges=  4;
 facetid->edge[0]= 1;
 facetid->edge[1]= 5;
 facetid->edge[2]= 4;
 facetid->edge[3]= 0;
 facetid++;

 facetid->color=   WHITE;
 facetid->nedges=  4;
 facetid->edge[0]= 0;
 facetid->edge[1]= 4;
 facetid->edge[2]= 7;
 facetid->edge[3]= 3;
 facetid++;

 facetid->color=   WHITE;
 facetid->nedges=  4;
 facetid->edge[0]= 3;
 facetid->edge[1]= 7;
 facetid->edge[2]= 6;
 facetid->edge[3]= 2;
 facetid++;

 facetid->color=   WHITE;
 facetid->nedges=  4;
 facetid->edge[0]= 2;
 facetid->edge[1]= 6;
 facetid->edge[2]= 5;
 facetid->edge[3]= 1;
 facetid++;

 facetid->color=   WHITE;
 facetid->nedges=  4;
 facetid->edge[0]= 5;
 facetid->edge[1]= 9;
 facetid->edge[2]= 8;
 facetid->edge[3]= 4;
 facetid++;

 facetid->color=   WHITE;
 facetid->nedges=  4;
 facetid->edge[0]= 4;
 facetid->edge[1]= 8;
 facetid->edge[2]= 11;
 facetid->edge[3]= 7;
 facetid++;

 facetid->color=   WHITE;
 facetid->nedges=  4;
 facetid->edge[0]= 7;
 facetid->edge[1]= 11;
 facetid->edge[2]= 10;
 facetid->edge[3]= 6;
 facetid++;

 facetid->color=   WHITE;
 facetid->nedges=  4;
 facetid->edge[0]= 5;
 facetid->edge[1]= 6;
 facetid->edge[2]= 10;
 facetid->edge[3]= 9;
 facetid++;

 facetid->color=   WHITE;
 facetid->nedges=  4;
 facetid->edge[0]= 8;
 facetid->edge[1]= 9;
 facetid->edge[2]= 10;
 facetid->edge[3]= 11;
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
