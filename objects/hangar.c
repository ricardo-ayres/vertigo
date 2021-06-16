
 id=HANGAR;
 object[id].max_draw_dist=6000;
 object[id].always_draw_dist=200;

 object[id].nvertices =  18;
 object[id].nfacets   =  11;
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
 (object[id].vertex+0)->x=20;
 (object[id].vertex+0)->y=-30;
 (object[id].vertex+0)->z=5;

 (object[id].vertex+1)->x=10;
 (object[id].vertex+1)->y=-30;
 (object[id].vertex+1)->z=8;

 (object[id].vertex+2)->x=0;
 (object[id].vertex+2)->y=-30;
 (object[id].vertex+2)->z=9;

 (object[id].vertex+3)->x=-10;
 (object[id].vertex+3)->y=-30;
 (object[id].vertex+3)->z=8;

 (object[id].vertex+4)->x=-20;
 (object[id].vertex+4)->y=-30;
 (object[id].vertex+4)->z=5;

 (object[id].vertex+5)->x=-20;
 (object[id].vertex+5)->y=-30;
 (object[id].vertex+5)->z=0;

 (object[id].vertex+6)->x=20;
 (object[id].vertex+6)->y=-30;
 (object[id].vertex+6)->z=0;

 /* rear */
 (object[id].vertex+7)->x=20;
 (object[id].vertex+7)->y=30;
 (object[id].vertex+7)->z=5;

 (object[id].vertex+8)->x=10;
 (object[id].vertex+8)->y=30;
 (object[id].vertex+8)->z=8;

 (object[id].vertex+9)->x=0;
 (object[id].vertex+9)->y=30;
 (object[id].vertex+9)->z=9;

 (object[id].vertex+10)->x=-10;
 (object[id].vertex+10)->y=30;
 (object[id].vertex+10)->z=8;

 (object[id].vertex+11)->x=-20;
 (object[id].vertex+11)->y=30;
 (object[id].vertex+11)->z=5;

 (object[id].vertex+12)->x=-20;
 (object[id].vertex+12)->y=30;
 (object[id].vertex+12)->z=0;

 (object[id].vertex+13)->x=20;
 (object[id].vertex+13)->y=30;
 (object[id].vertex+13)->z=0;

 /* door */
 (object[id].vertex+14)->x=15;
 (object[id].vertex+14)->y=-30;
 (object[id].vertex+14)->z=5;

 (object[id].vertex+15)->x=-15;
 (object[id].vertex+15)->y=-30;
 (object[id].vertex+15)->z=5;

 (object[id].vertex+16)->x=-15;
 (object[id].vertex+16)->y=-30;
 (object[id].vertex+16)->z=0;

 (object[id].vertex+17)->x=15;
 (object[id].vertex+17)->y=-30;
 (object[id].vertex+17)->z=0;



 /* front */
 (object[id].facet+0)->color=LIGHTGRAY;
 (object[id].facet+0)->nedges=5;
 (object[id].facet+0)->edge[0]=0;
 (object[id].facet+0)->edge[1]=1;
 (object[id].facet+0)->edge[2]=2;
 (object[id].facet+0)->edge[3]=3;
 (object[id].facet+0)->edge[4]=4;

 /* rear */
 (object[id].facet+1)->color=LIGHTGRAY;
 (object[id].facet+1)->nedges=7;
 (object[id].facet+1)->edge[0]=13;
 (object[id].facet+1)->edge[1]=12;
 (object[id].facet+1)->edge[2]=11;
 (object[id].facet+1)->edge[3]=10;
 (object[id].facet+1)->edge[4]=9;
 (object[id].facet+1)->edge[5]=8;
 (object[id].facet+1)->edge[6]=7;

 /* rear */
 (object[id].facet+2)->color=DARKGRAY;
 (object[id].facet+2)->nedges=4;
 (object[id].facet+2)->edge[0]=14;
 (object[id].facet+2)->edge[1]=15;
 (object[id].facet+2)->edge[2]=16;
 (object[id].facet+2)->edge[3]=17;

 (object[id].facet+3)->color=LIGHTGRAY;
 (object[id].facet+3)->nedges=4;
 (object[id].facet+3)->edge[0]=0;
 (object[id].facet+3)->edge[1]=6;
 (object[id].facet+3)->edge[2]=13;
 (object[id].facet+3)->edge[3]=7;

 (object[id].facet+4)->color=LIGHTGRAY;
 (object[id].facet+4)->nedges=4;
 (object[id].facet+4)->edge[0]=1;
 (object[id].facet+4)->edge[1]=0;
 (object[id].facet+4)->edge[2]=7;
 (object[id].facet+4)->edge[3]=8;

 (object[id].facet+5)->color=LIGHTGRAY;
 (object[id].facet+5)->nedges=4;
 (object[id].facet+5)->edge[0]=2;
 (object[id].facet+5)->edge[1]=1;
 (object[id].facet+5)->edge[2]=8;
 (object[id].facet+5)->edge[3]=9;

 (object[id].facet+6)->color=LIGHTGRAY;
 (object[id].facet+6)->nedges=4;
 (object[id].facet+6)->edge[0]=3;
 (object[id].facet+6)->edge[1]=2;
 (object[id].facet+6)->edge[2]=9;
 (object[id].facet+6)->edge[3]=10;

 (object[id].facet+7)->color=LIGHTGRAY;
 (object[id].facet+7)->nedges=4;
 (object[id].facet+7)->edge[0]=4;
 (object[id].facet+7)->edge[1]=3;
 (object[id].facet+7)->edge[2]=10;
 (object[id].facet+7)->edge[3]=11;

 (object[id].facet+8)->color=LIGHTGRAY;
 (object[id].facet+8)->nedges=4;
 (object[id].facet+8)->edge[0]=5;
 (object[id].facet+8)->edge[1]=4;
 (object[id].facet+8)->edge[2]=11;
 (object[id].facet+8)->edge[3]=12;

 (object[id].facet+9)->color=LIGHTGRAY;
 (object[id].facet+9)->nedges=4;
 (object[id].facet+9)->edge[0]=16;
 (object[id].facet+9)->edge[1]=15;
 (object[id].facet+9)->edge[2]=4;
 (object[id].facet+9)->edge[3]=5;

 (object[id].facet+10)->color=LIGHTGRAY;
 (object[id].facet+10)->nedges=4;
 (object[id].facet+10)->edge[0]=6;
 (object[id].facet+10)->edge[1]=0;
 (object[id].facet+10)->edge[2]=14;
 (object[id].facet+10)->edge[3]=17;

nobjects++;
