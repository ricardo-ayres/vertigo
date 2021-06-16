
 id=NIMITZ_MARK2;
 object[id].max_draw_dist=2000;
 object[id].always_draw_dist=700;

 object[id].nvertices = 4+10*4+11*4+8*4+4*4;
 object[id].nfacets   = 1+10+11+8+4;
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

 /* Rear center line */
 (object[id].vertex+0)->x=-131.0;
 (object[id].vertex+0)->y=  -6.9;
 (object[id].vertex+0)->z=  19.0;

 (object[id].vertex+1)->x=-131.0;
 (object[id].vertex+1)->y=  -7.9;
 (object[id].vertex+1)->z=  19.0;

 (object[id].vertex+2)->x=-131.0;
 (object[id].vertex+2)->y=  -6.9;
 (object[id].vertex+2)->z=   5.0;

 (object[id].vertex+3)->x=-131.0;
 (object[id].vertex+3)->y=  -7.9;
 (object[id].vertex+3)->z=   5.0;

 {
 float v=9.20*PI/180;
 float sin_v=sin(v);
 float cos_v=cos(v);
 float yc_0=  6.35;
 float xc_0=-132.3;

 for (i=0; i<10; i++){
  float b= 3.0;
  float l=18.0;
  float xc=xc_0+(3+22*i)*cos_v+0.3*sin_v;
  float yc=yc_0+(3+22*i)*sin_v-0.3*cos_v;

 (object[id].vertex+(i+1)*4)->x= xc;
 (object[id].vertex+(i+1)*4)->y= yc;
 (object[id].vertex+(i+1)*4)->z= 20.0;

 (object[id].vertex+(i+1)*4+1)->x= xc+sin_v*b;
 (object[id].vertex+(i+1)*4+1)->y= yc-cos_v*b;
 (object[id].vertex+(i+1)*4+1)->z= 20.0;

 (object[id].vertex+(i+1)*4+2)->x= xc+cos_v*l;
 (object[id].vertex+(i+1)*4+2)->y= yc+sin_v*l;
 (object[id].vertex+(i+1)*4+2)->z= 20.0;

 (object[id].vertex+(i+1)*4+3)->x= xc+cos_v*l+sin_v*b;
 (object[id].vertex+(i+1)*4+3)->y= yc-cos_v*b+sin_v*l;
 (object[id].vertex+(i+1)*4+3)->z= 20.0;
 }

 for (i=0; i<11; i++){
  float b= 3.0;
  float l=18.0;
  float xc=xc_0+(3+22*i)*cos_v+24.2*sin_v;
  float yc=yc_0+(3+22*i)*sin_v-24.2*cos_v;

 (object[id].vertex+(i+11)*4)->x= xc;
 (object[id].vertex+(i+11)*4)->y= yc;
 (object[id].vertex+(i+11)*4)->z= 20.0;

 (object[id].vertex+(i+11)*4+1)->x= xc+sin_v*b;
 (object[id].vertex+(i+11)*4+1)->y= yc-cos_v*b;
 (object[id].vertex+(i+11)*4+1)->z= 20.0;

 (object[id].vertex+(i+11)*4+2)->x= xc+cos_v*l;
 (object[id].vertex+(i+11)*4+2)->y= yc+sin_v*l;
 (object[id].vertex+(i+11)*4+2)->z= 20.0;

 (object[id].vertex+(i+11)*4+3)->x= xc+cos_v*l+sin_v*b;
 (object[id].vertex+(i+11)*4+3)->y= yc-cos_v*b+sin_v*l;
 (object[id].vertex+(i+11)*4+3)->z= 20.0;
 }

 for (i=0; i<8; i++){
  float b= 1.05;
  float l=14.0;
  float xc=xc_0+(l+3+2*l*i)*cos_v+13.25*sin_v;
  float yc=yc_0+(l+3+2*l*i)*sin_v-13.25*cos_v;

 (object[id].vertex+(i+22)*4)->x= xc;
 (object[id].vertex+(i+22)*4)->y= yc;
 (object[id].vertex+(i+22)*4)->z= 20.0;

 (object[id].vertex+(i+22)*4+1)->x= xc+sin_v*b;
 (object[id].vertex+(i+22)*4+1)->y= yc-cos_v*b;
 (object[id].vertex+(i+22)*4+1)->z= 20.0;

 (object[id].vertex+(i+22)*4+2)->x= xc+cos_v*l;
 (object[id].vertex+(i+22)*4+2)->y= yc+sin_v*l;
 (object[id].vertex+(i+22)*4+2)->z= 20.0;

 (object[id].vertex+(i+22)*4+3)->x= xc+cos_v*l+sin_v*b;
 (object[id].vertex+(i+22)*4+3)->y= yc-cos_v*b+sin_v*l;
 (object[id].vertex+(i+22)*4+3)->z= 20.0;
 }

 }

 /* Catapults */
 (object[id].vertex+120)->x= 89.0;
 (object[id].vertex+120)->y=  7.4;
 (object[id].vertex+120)->z= 20.0;

 (object[id].vertex+121)->x= 89.0;
 (object[id].vertex+121)->y=  5.4;
 (object[id].vertex+121)->z= 20.0;

 (object[id].vertex+122)->x=190.4;
 (object[id].vertex+122)->y= 10.1;
 (object[id].vertex+122)->z= 20.0;

 (object[id].vertex+123)->x=190.4;
 (object[id].vertex+123)->y=  8.1;
 (object[id].vertex+123)->z= 20.0;


 (object[id].vertex+124)->x= 94.3;
 (object[id].vertex+124)->y=-16.2;
 (object[id].vertex+124)->z= 20.0;

 (object[id].vertex+125)->x= 94.3;
 (object[id].vertex+125)->y=-18.2;
 (object[id].vertex+125)->z= 20.0;

 (object[id].vertex+126)->x=195.5;
 (object[id].vertex+126)->y= -7.3;
 (object[id].vertex+126)->z= 20.0;

 (object[id].vertex+127)->x=195.5;
 (object[id].vertex+127)->y= -9.3;
 (object[id].vertex+127)->z= 20.0;


 (object[id].vertex+128)->x=-22.5;
 (object[id].vertex+128)->y= 34.0;
 (object[id].vertex+128)->z= 20.0;

 (object[id].vertex+129)->x=-22.5;
 (object[id].vertex+129)->y= 32.0;
 (object[id].vertex+129)->z= 20.0;

 (object[id].vertex+130)->x= 81.2;
 (object[id].vertex+130)->y= 34.0;
 (object[id].vertex+130)->z= 20.0;

 (object[id].vertex+131)->x= 81.2;
 (object[id].vertex+131)->y= 32.0;
 (object[id].vertex+131)->z= 20.0;


 (object[id].vertex+132)->x= -2.7;
 (object[id].vertex+132)->y= 21.8;
 (object[id].vertex+132)->z= 20.0;

 (object[id].vertex+133)->x= -2.7;
 (object[id].vertex+133)->y= 19.8;
 (object[id].vertex+133)->z= 20.0;

 (object[id].vertex+134)->x=100.5;
 (object[id].vertex+134)->y= 31.1;
 (object[id].vertex+134)->z= 20.0;

 (object[id].vertex+135)->x=100.5;
 (object[id].vertex+135)->y= 29.1;
 (object[id].vertex+135)->z= 20.0;

 /*
 (object[id].vertex+)->x=;
 (object[id].vertex+)->y=;
 (object[id].vertex+)->z=;
 */

 /**********/
 /* Facets */
 /**********/

 /*0 */
 facetid->color=YELLOW_SHADE;
 facetid->nedges=4;
 facetid->edge[0]=0;
 facetid->edge[1]=2;
 facetid->edge[2]=3;
 facetid->edge[3]=1;
 facetid++;


 for (i=0; i<10; i++){
  facetid->color=DARKGRAY;
  facetid->nedges=4;
  facetid->edge[0]=(i+1)*4;
  facetid->edge[1]=(i+1)*4+1;
  facetid->edge[2]=(i+1)*4+3;
  facetid->edge[3]=(i+1)*4+2;
  facetid++;
 }

 for (i=0; i<11; i++){
  facetid->color=DARKGRAY;
  facetid->nedges=4;
  facetid->edge[0]=(i+11)*4;
  facetid->edge[1]=(i+11)*4+1;
  facetid->edge[2]=(i+11)*4+3;
  facetid->edge[3]=(i+11)*4+2;
  facetid++;
 }

 for (i=0; i<8; i++){
  facetid->color=YELLOW_SHADE;
  facetid->nedges=4;
  facetid->edge[0]=(i+22)*4;
  facetid->edge[1]=(i+22)*4+1;
  facetid->edge[2]=(i+22)*4+3;
  facetid->edge[3]=(i+22)*4+2;
  facetid++;
 }

 facetid->color=GRAY_SHADE;
 facetid->nedges=4;
 facetid->edge[0]=120;
 facetid->edge[1]=121;
 facetid->edge[2]=123;
 facetid->edge[3]=122;
 facetid++;

 facetid->color=GRAY_SHADE;
 facetid->nedges=4;
 facetid->edge[0]=124;
 facetid->edge[1]=125;
 facetid->edge[2]=127;
 facetid->edge[3]=126;
 facetid++;

 facetid->color=GRAY_SHADE;
 facetid->nedges=4;
 facetid->edge[0]=128;
 facetid->edge[1]=129;
 facetid->edge[2]=131;
 facetid->edge[3]=130;
 facetid++;

 facetid->color=GRAY_SHADE;
 facetid->nedges=4;
 facetid->edge[0]=132;
 facetid->edge[1]=133;
 facetid->edge[2]=135;
 facetid->edge[3]=134;
 facetid++;

 if (object[id].facet+object[id].nfacets!=facetid)
    errormessage("Incorrect number of facets");

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
