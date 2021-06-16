
 id=WINDBAG;
 object[id].max_draw_dist=2000;
 object[id].always_draw_dist=100;

 object[id].nvertices =  24;
 object[id].nfacets   =  24;
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

 /* Vertices are not defined here, but in update_windbag() */

 for (i=0; i<5; i++) {
  int color;

  if (i % 2) color = WHITE;
  else       color = LIGHTRED;

  for (j=0; j<4; j++) {
    int k = j+1;

    if (j==3) k=0;

    (object[id].facet+j+i*4)->color=color;
    (object[id].facet+j+i*4)->nedges=4;
    (object[id].facet+j+i*4)->edge[0]=j+i*4;
    (object[id].facet+j+i*4)->edge[1]=j+(i+1)*4;
    (object[id].facet+j+i*4)->edge[2]=k+(i+1)*4;
    (object[id].facet+j+i*4)->edge[3]=k+i*4;


  }
 }

 /* Only the first cylinder is drawn on the inside */
 for (j=0; j<4; j++) {
    int k = j+1;
    i=0;

    if (j==3) k=0;
    (object[id].facet+j+i*4+20)->color=LIGHTRED;
    (object[id].facet+j+i*4+20)->nedges=4;
    (object[id].facet+j+i*4+20)->edge[0]=j+i*4;
    (object[id].facet+j+i*4+20)->edge[1]=k+i*4;
    (object[id].facet+j+i*4+20)->edge[2]=k+(i+1)*4;
    (object[id].facet+j+i*4+20)->edge[3]=j+(i+1)*4;
 }

nobjects++;
