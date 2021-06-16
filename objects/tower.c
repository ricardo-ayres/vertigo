
 id=TOWER;
 object[id].max_draw_dist=6000;
 object[id].always_draw_dist=100;

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

 /* front */
 (object[id].vertex+0)->x=-2;
 (object[id].vertex+0)->y=-2;
 (object[id].vertex+0)->z=0;

 (object[id].vertex+1)->x=2;
 (object[id].vertex+1)->y=-2;
 (object[id].vertex+1)->z=0;

 (object[id].vertex+2)->x=2;
 (object[id].vertex+2)->y=-2;
 (object[id].vertex+2)->z=10;

 (object[id].vertex+3)->x=-2;
 (object[id].vertex+3)->y=-2;
 (object[id].vertex+3)->z=10;

 (object[id].vertex+4)->x=-2;
 (object[id].vertex+4)->y=2;
 (object[id].vertex+4)->z=0;

 (object[id].vertex+5)->x=-2;
 (object[id].vertex+5)->y=2;
 (object[id].vertex+5)->z=10;

 (object[id].vertex+6)->x=2;
 (object[id].vertex+6)->y=2;
 (object[id].vertex+6)->z=0;

 (object[id].vertex+7)->x=2;
 (object[id].vertex+7)->y=2;
 (object[id].vertex+7)->z=10;

 (object[id].vertex+8)->x=-3;
 (object[id].vertex+8)->y=-3;
 (object[id].vertex+8)->z=12;

 (object[id].vertex+9)->x=3;
 (object[id].vertex+9)->y=-3;
 (object[id].vertex+9)->z=12;

 (object[id].vertex+10)->x=3;
 (object[id].vertex+10)->y=3;
 (object[id].vertex+10)->z=12;

 (object[id].vertex+11)->x=-3;
 (object[id].vertex+11)->y=3;
 (object[id].vertex+11)->z=12;

 (object[id].facet+0)->color=LIGHTGRAY;
 (object[id].facet+0)->nedges=4;
 (object[id].facet+0)->edge[0]=0;
 (object[id].facet+0)->edge[1]=1;
 (object[id].facet+0)->edge[2]=2;
 (object[id].facet+0)->edge[3]=3;

 (object[id].facet+1)->color=LIGHTGRAY;
 (object[id].facet+1)->nedges=4;
 (object[id].facet+1)->edge[0]=0;
 (object[id].facet+1)->edge[1]=3;
 (object[id].facet+1)->edge[2]=5;
 (object[id].facet+1)->edge[3]=4;

 (object[id].facet+2)->color=LIGHTGRAY;
 (object[id].facet+2)->nedges=4;
 (object[id].facet+2)->edge[0]=4;
 (object[id].facet+2)->edge[1]=5;
 (object[id].facet+2)->edge[2]=7;
 (object[id].facet+2)->edge[3]=6;

 (object[id].facet+3)->color=LIGHTGRAY;
 (object[id].facet+3)->nedges=4;
 (object[id].facet+3)->edge[0]=6;
 (object[id].facet+3)->edge[1]=7;
 (object[id].facet+3)->edge[2]=2;
 (object[id].facet+3)->edge[3]=1;

 (object[id].facet+4)->color=LIGHTGRAY;
 (object[id].facet+4)->nedges=4;
 (object[id].facet+4)->edge[0]=8;
 (object[id].facet+4)->edge[1]=9;
 (object[id].facet+4)->edge[2]=10;
 (object[id].facet+4)->edge[3]=11;

 (object[id].facet+5)->color=LIGHTBLUE;
 (object[id].facet+5)->nedges=4;
 (object[id].facet+5)->edge[0]=2;
 (object[id].facet+5)->edge[1]=9;
 (object[id].facet+5)->edge[2]=8;
 (object[id].facet+5)->edge[3]=3;

 (object[id].facet+6)->color=LIGHTBLUE;
 (object[id].facet+6)->nedges=4;
 (object[id].facet+6)->edge[0]=3;
 (object[id].facet+6)->edge[1]=8;
 (object[id].facet+6)->edge[2]=11;
 (object[id].facet+6)->edge[3]=5;

 (object[id].facet+7)->color=LIGHTBLUE;
 (object[id].facet+7)->nedges=4;
 (object[id].facet+7)->edge[0]=7;
 (object[id].facet+7)->edge[1]=5;
 (object[id].facet+7)->edge[2]=11;
 (object[id].facet+7)->edge[3]=10;

 (object[id].facet+8)->color=LIGHTBLUE;
 (object[id].facet+8)->nedges=4;
 (object[id].facet+8)->edge[0]=7;
 (object[id].facet+8)->edge[1]=10;
 (object[id].facet+8)->edge[2]=9;
 (object[id].facet+8)->edge[3]=2;

nobjects++;
