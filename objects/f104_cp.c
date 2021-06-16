
 id=F104_CP;
 object[id].max_draw_dist=100;
 object[id].always_draw_dist=10;

 object[id].nvertices =  16;
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

 (object[id].vertex+0)->x= 7.28;
 (object[id].vertex+0)->y=-0.18;
 (object[id].vertex+0)->z= 0.42;

 (object[id].vertex+1)->x= 7.28;
 (object[id].vertex+1)->y= 0.18;
 (object[id].vertex+1)->z= 0.42;

 (object[id].vertex+2)->x= 6.28;
 (object[id].vertex+2)->y= 0.36;
 (object[id].vertex+2)->z= 0.49;

 (object[id].vertex+3)->x= 6.28;
 (object[id].vertex+3)->y=-0.36;
 (object[id].vertex+3)->z= 0.49;

 (object[id].vertex+4)->x= 5.32;
 (object[id].vertex+4)->y= 0.39;
 (object[id].vertex+4)->z= 0.58;

 (object[id].vertex+5)->x= 5.32;
 (object[id].vertex+5)->y=-0.39;
 (object[id].vertex+5)->z= 0.58;

 (object[id].vertex+6)->x= 4.45;
 (object[id].vertex+6)->y= 0.27;
 (object[id].vertex+6)->z= 0.83;

 (object[id].vertex+7)->x= 4.45;
 (object[id].vertex+7)->y=-0.27;
 (object[id].vertex+7)->z= 0.83;

 (object[id].vertex+8)->x= 7.28;
 (object[id].vertex+8)->y=-0.18;
 (object[id].vertex+8)->z=-0.50;

 (object[id].vertex+9)->x= 7.28;
 (object[id].vertex+9)->y= 0.18;
 (object[id].vertex+9)->z=-0.50;

 (object[id].vertex+10)->x= 6.28;
 (object[id].vertex+10)->y= 0.36;
 (object[id].vertex+10)->z=-0.50;

 (object[id].vertex+11)->x= 6.28;
 (object[id].vertex+11)->y=-0.36;
 (object[id].vertex+11)->z=-0.50;

 (object[id].vertex+12)->x= 5.32;
 (object[id].vertex+12)->y= 0.39;
 (object[id].vertex+12)->z=-0.50;

 (object[id].vertex+13)->x= 5.32;
 (object[id].vertex+13)->y=-0.39;
 (object[id].vertex+13)->z=-0.50;

 (object[id].vertex+14)->x= 4.45;
 (object[id].vertex+14)->y= 0.27;
 (object[id].vertex+14)->z=-0.50;

 (object[id].vertex+15)->x= 4.45;
 (object[id].vertex+15)->y=-0.27;
 (object[id].vertex+15)->z=-0.50;


 /*
 (object[id].vertex+)->x=;
 (object[id].vertex+)->y=;
 (object[id].vertex+)->z=;
 */

 /**********/
 /* Facets */
 /**********/

 facetid->color=LIGHTGRAY;
 facetid->nedges=4;
 facetid->edge[0]=0;
 facetid->edge[1]=1;
 facetid->edge[2]=9;
 facetid->edge[3]=8;
 facetid++;

 facetid->color=LIGHTGRAY;
 facetid->nedges=4;
 facetid->edge[0]=3;
 facetid->edge[1]=0;
 facetid->edge[2]=8;
 facetid->edge[3]=11;
 facetid++;

 facetid->color=LIGHTGRAY;
 facetid->nedges=4;
 facetid->edge[0]=1;
 facetid->edge[1]=2;
 facetid->edge[2]=10;
 facetid->edge[3]=9;
 facetid++;

 facetid->color=LIGHTGRAY;
 facetid->nedges=4;
 facetid->edge[0]=5;
 facetid->edge[1]=3;
 facetid->edge[2]=11;
 facetid->edge[3]=13;
 facetid++;

 facetid->color=LIGHTGRAY;
 facetid->nedges=4;
 facetid->edge[0]=2;
 facetid->edge[1]=4;
 facetid->edge[2]=12;
 facetid->edge[3]=10;
 facetid++;

 facetid->color=LIGHTGRAY;
 facetid->nedges=4;
 facetid->edge[0]=4;
 facetid->edge[1]=6;
 facetid->edge[2]=14;
 facetid->edge[3]=12;
 facetid++;

 facetid->color=LIGHTGRAY;
 facetid->nedges=4;
 facetid->edge[0]=6;
 facetid->edge[1]=7;
 facetid->edge[2]=15;
 facetid->edge[3]=14;
 facetid++;

 facetid->color=LIGHTGRAY;
 facetid->nedges=4;
 facetid->edge[0]=7;
 facetid->edge[1]=5;
 facetid->edge[2]=13;
 facetid->edge[3]=15;
 facetid++;

 facetid->color=LIGHTGRAY;
 facetid->nedges=8;
 facetid->edge[0]=11;
 facetid->edge[1]=8;
 facetid->edge[2]=9;
 facetid->edge[3]=10;
 facetid->edge[4]=12;
 facetid->edge[5]=14;
 facetid->edge[6]=15;
 facetid->edge[7]=13;
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
