/* GRAPHICS.C */
/* Inkluderes i VERTIGO.C */


void shade16(int colid, int cr, int cg, int cb, float contrast, float illum,int start)
//Sets up 16 shades of a color in the pallette
{
  int i;
  int j=0;
  int r,g,b;

  for (i=start; i<start+16; i++) {
    r = (cr/4) * (1.0 + contrast * ((j - 15.0) / 15.0) ) * illum;
    g = (cg/4) * (1.0 + contrast * ((j - 15.0) / 15.0) ) * illum;
    b = (cb/4) * (1.0 + contrast * ((j - 15.0) / 15.0) ) * illum;
 
    verpal[i].r=r;
    verpal[i].g=g;
    verpal[i].b=b;

    colortable[colid][j]=i;
    j++;
  }
}



void setup_palette()
{
 /* For 256 color palette */
 int i,j;
 float illum=1.0;
 float contrast;

 int colnam[]={
	LIGHTRED, 
	LIGHTBLUE,
	LIGHTGRAY,
	RED,
	GREEN,
	BLUE,
	DARKGRAY,
	WHITE,
	CYAN,
	LIGHTCYAN,
	DARKGREEN
	};

	int colpos[]={
	16, 
	48,
	64,
	80,
	96,
	112,
	128,
	144,
	160,
	176,
	192
	};

 refresh_palette=0;
 last_palette_time=running_time;

 if (world == EARTH) contrast = 0.3;
 else contrast = 0.9;

#ifdef MGUI
 /* MGUI messes the table up */
 /* Some colors still need tuning */
 /* BLACK */
 verpal[0].r = 0;
 verpal[0].g = 0;
 verpal[0].b = 0;
 /* BLUE */
 verpal[1].r = 0;
 verpal[1].g = 0;
 verpal[1].b = 32;
 /* GREEN */
 verpal[2].r = 0;
 verpal[2].g = 32;
 verpal[2].b = 0;
 /* CYAN */
 verpal[3].r = 0;
 verpal[3].g = 16;
 verpal[3].b = 16;
 /* RED */
 verpal[4].r = 32;
 verpal[4].g = 0;
 verpal[4].b = 0;
 /* MAGENTA */
 verpal[5].r = 16;
 verpal[5].g = 0;
 verpal[5].b = 16;
 /* BROWN */
 verpal[6].r = 24;
 verpal[6].g = 0;
 verpal[6].b = 16;
 /* LIGHTGRAY */
 verpal[7].r = 32;
 verpal[7].g = 32;
 verpal[7].b = 32;
 /* DARKGRAY */
 verpal[8].r = 16;
 verpal[8].g = 16;
 verpal[8].b = 16;
 /* LIGHTBLUE */
 verpal[9].r = 0;
 verpal[9].g = 0;
 verpal[9].b = 63;
 /* LIGHTGREEN */
 verpal[10].r = 0;
 verpal[10].g = 63;
 verpal[10].b = 0;
 /* LIGHTCYAN */
 verpal[11].r = 0;
 verpal[11].g = 32;
 verpal[11].b = 32;
 /* LIGHTRED */
 verpal[12].r = 63;
 verpal[12].g = 0;
 verpal[12].b = 0;
 /* LIGHTMAGENTA */
 verpal[13].r = 32;
 verpal[13].g = 0;
 verpal[13].b = 32;
 /* YELLOW */
 verpal[14].r = 63;
 verpal[14].g = 63;
 verpal[14].b = 0;
 /* WHITE */
 verpal[15].r = 63;
 verpal[15].g = 63;
 verpal[15].b = 63;
#endif

 if (running_time > 17.75 && running_time <= 18.25)
      illum=1-0.85*2*(running_time-17.75);

 if (running_time > 5.75 && running_time < 6.25)
      illum=0.15+0.85*2*(running_time-5.75);

 if (running_time > 18.25 || running_time < 5.75) illum=0.15;
 if (show_map) illum=1.0;

 for (i=0; i<16; i++)
  for (j=0; j<16; j++)
   colortable[i][j]=0;

 /* R,G,B intensity range: 0-63 */

 for (i=0; i<4; i++){
  for (j=0; j<4; j++){
     int r=18;
     int g=18;
     int b=28+j*2;
     r=(r*(4-i)+32*i)/4;
     g=(g*(4-i)+32*i)/4;
     b=(b*(4-i)+32*i)/4;
	 verpal[i+j*4+32].r=r;
	 verpal[i+j*4+32].g=g;
	 verpal[i+j*4+32].b=b;
     colortable[BLUE_HAZE][i+j*4]=i+j*4+32;
  }
 }

 for (i=0; i<11; i++){
	 shade16(colnam[i],
	 object[poly_plane_id[current_model]].colarr[colnam[i]].r,
	 object[poly_plane_id[current_model]].colarr[colnam[i]].g,
	 object[poly_plane_id[current_model]].colarr[colnam[i]].b,
	 contrast,illum,colpos[i]);
 }
 
 /* These are now used by custom colours instead
 shade16(LIGHTRED,255,96,96,contrast,illum,16);
 shade16(LIGHTBLUE,96,96,255,contrast,illum,48);
 shade16(LIGHTGRAY,192,192,192,contrast,illum,64);
 shade16(RED,255,32,32,contrast,illum,80);
 shade16(GREEN,32,255,32,contrast,illum,96);
 shade16(BLUE,32,32,255,contrast,illum,112);
 shade16(DARKGRAY,80,80,80,contrast,illum,128);
 shade16(WHITE,
	 object[poly_plane_id[current_model]].colarr[WHITE].r,
	 object[poly_plane_id[current_model]].colarr[WHITE].g,
	 object[poly_plane_id[current_model]].colarr[WHITE].b,
	 contrast,illum,144);
 shade16(CYAN,96,192,192,contrast,illum,160);
 shade16(LIGHTCYAN,64,255,255,contrast,illum,176); // Used???
 shade16(DARKGREEN,50,100,40,contrast,illum,192);
 */

 verpal[WHITE_SHADE].r=63*illum;
 verpal[WHITE_SHADE].g=63*illum;
 verpal[WHITE_SHADE].b=63*illum;
 verpal[YELLOW_SHADE].r=63*illum;
 verpal[YELLOW_SHADE].g=63*illum;
 verpal[YELLOW_SHADE].b=0*illum;
 verpal[GRAY_SHADE].r=32*illum;
 verpal[GRAY_SHADE].g=32*illum;
 verpal[GRAY_SHADE].b=32*illum;
 verpal[DARKGRAY_SHADE].r=12*illum;
 verpal[DARKGRAY_SHADE].g=12*illum;
 verpal[DARKGRAY_SHADE].b=12*illum;
 
{
	extern float atmospheric_density(float z);
	float skybright = pow(atmospheric_density(viewz) / 1.225, 0.33);
	int sky_r=30*illum*skybright;
	int sky_g=40*illum*skybright;
	int sky_b=63*illum*skybright;
	int star_r, star_g, star_b;
	int i;

        //220
	verpal[SKY_BLUE].r=sky_r;
	verpal[SKY_BLUE].g=sky_g;
	verpal[SKY_BLUE].b=sky_b;

 for (i=0; i<8; i++) {

 if (!make_stars_bright) {
   star_r = 23+i*5;
   star_g = 23+i*5;
   star_b = 23+i*5;
 }
 else {
   star_r = 35+i*4;
   star_g = 35+i*4;
   star_b = 35+i*4;
 }


   if (star_r > sky_r && star_g > sky_g && star_b > sky_b) {
	verpal[212+i].r=star_r;
	verpal[212+i].g=star_g;
	verpal[212+i].b=star_b;
      /* printf("Star #%d brighter than sky\n\r",i); */
   }
   else {
	verpal[212+i].r=sky_r;
	verpal[212+i].g=sky_g;
	verpal[212+i].b=sky_b;
   }

 }

}
 
 /* Room available: no 221 - 223 */

 for (i=0; i<4; i++){
  for (j=0; j<4; j++){
     int r=16;
     int g=28+j*2;
     int b=16;
     r=(r*(4-i)+32*i)/4;
     g=(g*(4-i)+32*i)/4;
     b=(b*(4-i)+32*i)/4;
	 verpal[i+j*4+224].r=r*illum;
	 verpal[i+j*4+224].g=g*illum;
	 verpal[i+j*4+224].b=b*illum;
     colortable[GREEN_HAZE][i+j*4]=i+j*4+224;
  }
 }

 for (i=0; i<4; i++){
  for (j=0; j<4; j++){
     int r=20+j*3;
     int g=16+j*1.5;
     int b=12+j;
     r=(r*(4-i)+32*i)/4;
     g=(g*(4-i)+32*i)/4;
     b=(b*(4-i)+32*i)/4;
	 verpal[i+j*4+240].r=r*illum;
	 verpal[i+j*4+240].g=g*illum;
	 verpal[i+j*4+240].b=b*illum;
     colortable[BROWN_HAZE][i+j*4]=i+j*4+240;
  }
 }
 set_palette(verpal);
}



int framedraw(float x1, float y1, float x2, float y2,float xpixels,float ypixels, int color)
/* Interpolates line-coordinates to edge of screen, if outside, before drawing */
/* Returns 0, if nothing drawn, 1 else */
{
 float ay,by,tx,ty;

 /* Return without drawing, if outside screen */
 /* This is also checked in draw3d */
 /* Some lines outside screen will not be filtered out by this */
 if (x1 < 0       && x2 < 0      ) return(0);
 if (x1 > xpixels && x2 > xpixels) return(0);
 if (y1 < 0       && y2 < 0      ) return(0);
 if (y1 > ypixels && y2 > ypixels) return(0);

 /* Express line as y=ay*x+by and x=(y-by)/ay */
 if (x2==x1) x2+=0.1; /* Avoid div. by 0 */
 ay=(y2-y1)/(x2-x1);
 by=y1-ay*x1;

 /* 'sort' points by X */
 if (x1 > x2) {
  tx=x1; ty=y1;
  x1=x2; y1=y2;
  x2=tx; y2=ty;
 }

 /* Interpolate to left edge, if outside */
 if (x1 < 0) {
  x1=0;
  y1=by;
 }

 /*interpolate to right edge, if outside */
 if (x2 > xpixels) {
  x2=xpixels;
  y2=ay*xpixels+by;
 }

 /* 'sort' points by Y */
 if (y1 > y2) {
  tx=x1; ty=y1;
  x1=x2; y1=y2;
  x2=tx; y2=ty;
 }

 /*interpolate to lower edge, if outside */
 if (y1 < 0) {
  y1=0;
  x1=-by/ay;
 }

 /*interpolate to upper edge, if outside */
 if (y2 > ypixels) {
  y2=ypixels;
  x2=(ypixels-by)/ay;
 }

 /* draw it */
 line(active_page, x1,y1, x2, y2, color);

 return(1);
}



int draw3d(float x1,float y1,float z1,float x2,float y2,float z2, int color)
/* Draws a line between two points in xyz coordinates as seen from plane */
/* Returns 0, if nothing drawn, 1 else */
{
 cartvektor xyz1,xyz2,flt1,flt2;
 float sx1,sy1,sx2,sy2;
 float xpixpermeter=xpixels/scrnwidth;
 float ypixpermeter=ypixels/scrnheight;
 float ay,by,az,bz;

 float xborder=scrnwidth/(2*viewdist); /* cm -> m */
 float yborder=scrnheight/(2*viewdist);

 int result;

 xyz1.x=x1-viewx;
 xyz1.y=y1-viewy;
 xyz1.z=z1-viewz;
 xyz2.x=x2-viewx;
 xyz2.y=y2-viewy;
 xyz2.z=z2-viewz;
 flt1.x=VPRIK(xyz1,viewfront);   /* Representation in top,front,left coordinates */
 flt1.y=VPRIK(xyz1,viewleft);
 flt1.z=VPRIK(xyz1,viewtop);
 flt2.x=VPRIK(xyz2,viewfront);
 flt2.y=VPRIK(xyz2,viewleft);
 flt2.z=VPRIK(xyz2,viewtop);

 /* Return without drawing if line is out of sight */
 if (flt1.x<0 && flt2.x<0) return(0); /* Both points behind observer */
 if (flt1.y>xborder*flt1.x && flt2.y>xborder*flt2.x) return(0); /* Left of window */
 if (flt1.y<-xborder*flt1.x && flt2.y<-xborder*flt2.x) return(0); /* Right of window */
 if (flt1.z>yborder*flt1.x && flt2.z>yborder*flt2.x) return(0); /* Above window */
 if (flt1.z<-yborder*flt1.x && flt2.z<-yborder*flt2.x) return(0); /* Below window */

 sx1=xcenter-(flt1.y*viewdist/flt1.x)*xpixpermeter;
 sy1=ycenter-(flt1.z*viewdist/flt1.x)*ypixpermeter;

 sx2=xcenter-(flt2.y*viewdist/flt2.x)*xpixpermeter;
 sy2=ycenter-(flt2.z*viewdist/flt2.x)*ypixpermeter;

 /* If one point is behind screen then interpolate onto screen */


 if (flt1.x < viewdist || flt2.x < viewdist) {

	 float y_scr,z_scr;

	 /* Express line as y=ay*x+by and z=az*x+bz */
	 if (flt2.x==flt1.x) flt2.x+=0.1; /* Avoid div. by 0 */
	 ay=(flt2.y-flt1.y)/(flt2.x-flt1.x);
	 by=flt1.y-ay*flt1.x;
	 az=(flt2.z-flt1.z)/(flt2.x-flt1.x);
	 bz=flt1.z-az*flt1.x;

	 /* Find intersection for x=viewdist */
	 y_scr=ay*viewdist+by;
	 z_scr=az*viewdist+bz;

	 /* Replace coordinates */
	 if (flt1.x < viewdist) {
	  sx1=xcenter-y_scr*xpixpermeter;
	  sy1=ycenter-z_scr*ypixpermeter; }
	 else {
	  sx2=xcenter-y_scr*xpixpermeter;
	  sy2=ycenter-z_scr*ypixpermeter; }

 }

 result=framedraw(sx1,sy1,sx2,sy2,xpixels,ypixels, color);

 return(result);
}



int point3d(cartvektor pos, int color)
/* Draws a point in xyz coordinates as seen from plane */
/* Returns 0, if nothing drawn, 1 else */
{
 cartvektor xyz1,flt1;
 float sx1,sy1;
 float xpixpermeter=xpixels/(scrnwidth);
 float ypixpermeter=ypixels/(scrnheight);

 float xborder=scrnwidth/(2*viewdist); /* cm -> m */
 float yborder=scrnheight/(2*viewdist);

 xyz1.x=pos.x-viewx;
 xyz1.y=pos.y-viewy;
 xyz1.z=pos.z-viewz;
 flt1.x=VPRIK(xyz1,viewfront);   /* Representation in top,front,left coordinates */
 flt1.y=VPRIK(xyz1,viewleft);
 flt1.z=VPRIK(xyz1,viewtop);

 /* Return if point is out of sight */
 if (flt1.x<0) return(0); /* Point behind observer */
 if (flt1.y>xborder*flt1.x) return(0); /* Left of window */
 if (flt1.y<-xborder*flt1.x) return(0); /* Right of window */
 if (flt1.z>yborder*flt1.x) return(0); /* Above window */
 if (flt1.z<-yborder*flt1.x) return(0); /* Below window */

 sx1=xcenter-(flt1.y*viewdist/flt1.x)*xpixpermeter;
 sy1=ycenter-(flt1.z*viewdist/flt1.x)*ypixpermeter;

 putpixel(active_page, sx1,sy1,color);

 return(1);
}



cartvektor scrpos3d(cartvektor pos)
{
 /* Returns coordinates projected onto screen of a 3d-point
    X,Y are screen coordinates
    Z= 1 : inside screen
    Z=-1 : point behind observer. X,Y not calculated.
    Z=-2 : point outside screen
 */

 cartvektor xyz1,flt1,scrpos;
 float sx1,sy1;
 float xpixpermeter=xpixels/scrnwidth;
 float ypixpermeter=ypixels/scrnheight;

 float xborder=scrnwidth/(2*viewdist);
 float yborder=scrnheight/(2*viewdist);

 scrpos.x=0; scrpos.y=0; scrpos.z=1;

 xyz1.x=pos.x-viewx;
 xyz1.y=pos.y-viewy;
 xyz1.z=pos.z-viewz;
 flt1.x=VPRIK(xyz1,viewfront);   /* Representation in top,front,left coordinates */
 flt1.y=VPRIK(xyz1,viewleft);
 flt1.z=VPRIK(xyz1,viewtop);

 if (flt1.x<0) {
    scrpos.z=-1;
    return(scrpos);
    }
 if (flt1.y>xborder*flt1.x)  scrpos.z=-2; /* Left of window */
 if (flt1.y<-xborder*flt1.x) scrpos.z=-2; /* Right of window */
 if (flt1.z>yborder*flt1.x)  scrpos.z=-2; /* Above window */
 if (flt1.z<-yborder*flt1.x) scrpos.z=-2; /* Below window */

 sx1=xcenter-(flt1.y*viewdist/flt1.x)*xpixpermeter;
 sy1=ycenter-(flt1.z*viewdist/flt1.x)*ypixpermeter;

 scrpos.x=sx1;
 scrpos.y=sy1;
 return(scrpos);
}



void printg(BITMAP *bmp, const FONT *f, float val, int len, int x, int y, int color)
{
 int rest;
 char str[]=" ";
 int charx,chary;

 charx=text_length(f,"M");
 chary=text_height(f);

 if (val<0) {
        textout(bmp, f, "-", x-charx, y, color);
        val=fabs(val);
        }
 if(len>1) printg(bmp, f, val/10,len-1, x, y, color);
 rest=fmod(val,10);
 rest+=48;
 str[0]=rest;
 textout(bmp, f, str, x+charx*(len-1), y, color);
}



void printfg(BITMAP *bmp, const FONT *f, float val, int len, int dec, int x, int y, int color)
{
// Print number x using len digits and decimal place at dec in graphics 
// I.e. pseudo-float printout 
// E.g.: printfg(1234.45*100,6,5) : "1234.45" 
 int rest;
 char str[]=" ";
 int charx,chary;

 charx=text_length(f,"M");
 chary=text_height(f);

 if (val<0) {
        textout(bmp, f, "-", x-charx, y, color);
        val=fabs(val);
        }
 if(len==dec) {
   textout(bmp, f, ".", x+charx*(len-1), y, color);
 }
 if(len>1) { 
   printfg(bmp, f, val/10,len-1, dec, x, y, color);
 }
 rest=fmod(val,10);
 rest+=48;
 str[0]=rest;
 if (len >= dec)
   textout(bmp, f, str, x+charx*len, y, color);
 else
   textout(bmp, f, str, x+charx*(len-1), y, color);
}



void tower()
/* Used when viewing from inside the tower */
{
 draw3d(1198,48,airfieldalt,1198,48,10+airfieldalt, LIGHTGRAY);
 draw3d(1202,48,airfieldalt,1202,48,10+airfieldalt, LIGHTGRAY);
 draw3d(1198,52,airfieldalt,1198,52,10+airfieldalt, LIGHTGRAY);
 draw3d(1202,52,airfieldalt,1202,52,10+airfieldalt, LIGHTGRAY);

 draw3d(1198,48,10+airfieldalt,1197,47,12+airfieldalt, LIGHTBLUE);
 draw3d(1202,48,10+airfieldalt,1203,47,12+airfieldalt, LIGHTBLUE);
 draw3d(1198,52,10+airfieldalt,1197,53,12+airfieldalt, LIGHTBLUE);
 draw3d(1202,52,10+airfieldalt,1203,53,12+airfieldalt, LIGHTBLUE);

 draw3d(1203,53,12+airfieldalt,1203,47,12+airfieldalt, LIGHTGRAY);
 draw3d(1197,47,12+airfieldalt,1203,47,12+airfieldalt, LIGHTGRAY);
 draw3d(1197,47,12+airfieldalt,1197,53,12+airfieldalt, LIGHTGRAY);
 draw3d(1197,53,12+airfieldalt,1203,53,12+airfieldalt, LIGHTGRAY);

 draw3d(1202,52,10+airfieldalt,1202,48,10+airfieldalt, LIGHTGRAY);
 draw3d(1198,48,10+airfieldalt,1202,48,10+airfieldalt, LIGHTGRAY);
 draw3d(1198,48,10+airfieldalt,1198,52,10+airfieldalt, LIGHTGRAY);
 draw3d(1198,52,10+airfieldalt,1202,52,10+airfieldalt, LIGHTGRAY);

 draw3d(1202,52,airfieldalt,1202,48,airfieldalt, LIGHTGRAY);
 draw3d(1198,48,airfieldalt,1202,48,airfieldalt, LIGHTGRAY);
 draw3d(1198,48,airfieldalt,1198,52,airfieldalt, LIGHTGRAY);
 draw3d(1198,52,airfieldalt,1202,52,airfieldalt, LIGHTGRAY);

}



void flatground(int grid1, int mask1,int farve)
/* Tegner jord-net i store streger */
{
 float sx,sy;
 float ix,iy;
 float grid=grid1;
 float mask=mask1;

 /* grid: stoerrelse af jord-net, ialt (2*grid+1)^2 tern */
 /* mask: sidelaengde af tern i meter */
 sx= (int) (viewx/mask);
 sy= (int) (viewy/mask);
 for (ix=sx-grid; ix<sx+grid; ix++)
	draw3d(ix*mask,(sy-grid)*mask,0,ix*mask,(sy+grid)*mask,0, farve);
 for (iy=sy-grid; iy<sy+grid; iy++)
	draw3d((sx-grid)*mask,iy*mask,0,(sx+grid)*mask,iy*mask,0, farve);
}




int poly_map_color(int h1, int h2, int h3)
{
 int col, max=h1;
 if (h2 > max) max=h2;
 if (h3 > max) max=h3;
 if (max>0)
    if (max>1500)
       if (max>2500)
		    col=WHITE;
		 else col=BROWN;
	 else col=GREEN;
 else col=BLUE;
 return(col);
}



void dot_ground(int grid, int mask)
{
 float sx,sy;
 float ix,iy;

 /* grid: stoerrelse af jord-net, ialt (2*grid+1)^2 tern */
 /* mask: sidelaengde af tern i meter */
 sx= (int) (viewx/mask);
 sy= (int) (viewy/mask);
 for (ix=sx-grid; ix<sx+grid; ix++) {
     for (iy=sy-grid; iy<sy+grid; iy++) {
         cartvektor pos,gndnorm,view;
         short color=BLACK;

         pos.x=ix*mask;
         pos.y=iy*mask;
         pos.z=groundalt(pos.x,pos.y);
         gndnorm=groundnorm(pos.x,pos.y);
         view.x=pos.x-viewx;
         view.y=pos.y-viewy;
         view.z=pos.z-viewz;
         if (VPRIK(gndnorm,view) < 0) {
            if (pos.z>0)
               if (pos.z>1500)
                  if (pos.z>2500)
		               color=BROWN;
		            else color=GREEN;
	            else color=BROWN;
            else color=WHITE_SHADE;

            /* color=hook_deck_pos(pos.x,pos.y); */

	        point3d(pos,color);
         }
     }
 }
}



void draw_vector(cartvektor a, cartvektor b, int color)
{
 draw3d(a.x,a.y,a.z,b.x,b.y,b.z, color);
}



void draw_object(int id, cartvektor pos)
/* Draw an item of type object3D */
/* A convex closed surface will be drawn without hidden surfaces */
{
 cartvektor view_to_obj;
 float distance=sqrt(SQR(pos.x-viewx)+SQR(pos.y-viewy)+SQR(pos.z-viewz));
 float normfak=1/distance;
 ori_vector orient;

 orient.rot=false;

 view_to_obj.x=pos.x-viewx;
 view_to_obj.y=pos.y-viewy;
 view_to_obj.z=pos.z-viewz;
 view_to_obj=svmult(normfak,view_to_obj);

 /* Is object visible? */
 if ( (distance < object[id].max_draw_dist) &&
      ( (VPRIK(view_to_obj,viewfront) > cos_diag) ||
      (distance < object[id].always_draw_dist))) {

  int i,k;
  cartvektor normvector,edge1,edge2,view;

  #ifdef TIMESTAT
    clock_start(8);
  #endif

  for (i=0; i<object[id].nfacets; i++) {
  /* Find vectors describing the first two edges
     calculate vector perpendicular to the polygon by the
     cross product of these.
     If normal vector has an anti-parallel component to the
     viewing direction, the surface is visible, and will
     be drawn. */
  edge1=vminus(*(object[id].vertex+(object[id].facet+i)->edge[1]),
               *(object[id].vertex+(object[id].facet+i)->edge[0]));
  k=2;
  if (k==(object[id].facet+i)->nedges) k=0;
  edge2=vminus(*(object[id].vertex+(object[id].facet+i)->edge[k]),
               *(object[id].vertex+(object[id].facet+i)->edge[1]));

  normvector=vkryds(edge1,edge2);
  view=vplus(pos,*(object[id].vertex+(object[id].facet+i)->edge[0]));
  view.x-=viewx;
  view.y-=viewy;
  view.z-=viewz;

  if (VPRIK(normvector,view) < 0) {
    float normfak = sqrt(SQR(normvector.x)+SQR(normvector.y)+SQR(normvector.z));
    float lighting=VPRIK(normvector,sun)/normfak;
     #ifdef TIMESTAT
       clock_stop(8);
     #endif
    filled_poly_to_queue(object[id].facet+i, id, pos, lighting, orient);
     #ifdef TIMESTAT
        clock_start(8);
     #endif
   }
  }
  #ifdef TIMESTAT
    clock_stop(8);
  #endif
 }
}



short find_ground_color(float lighting, float dist, short gnd_col)
{
   if ((gnd_col!=WHITE) && (many_colors==true)) {
        short col_idx=0;

        switch (gnd_col) {
          case GREEN : gnd_col=GREEN_HAZE; break;
          case BLUE  : gnd_col=BLUE_HAZE;  break;
          case BROWN : gnd_col=BROWN_HAZE; break;
        }

        if (lighting > -0.80) col_idx+=4;
        if (lighting > -0.60) col_idx+=4;
        if (lighting > -0.40) col_idx+=4;
        if (dist > 0.75) col_idx++;
        if (dist > 0.84) col_idx++;
        if (dist > 0.93) col_idx++;
        gnd_col=colortable[gnd_col][col_idx];
       }

	if ( world == MOON ) gnd_col = LIGHTGRAY;

 return gnd_col;
}



void draw_poly_map()
{
 #define poly_grid 10
 #define poly_mask 1000
 #define cos_diag_num 10
 typedef struct {
         cartvektor pos;
         int        drawn;
         } mapvertex;

 float sx,sy;   /* Are float to avoid overflow */
 float ix,iy;
 int idx_x,idx_y;
 const int mapwidth=mapsize-1;
 int indx,indy;
 cartvektor edge1,edge2,normvector,view;
 mapvertex poly_map[poly_grid*2+2][poly_grid*2+2];
 int cos_diag_idx;
 float cos_diag_modif[cos_diag_num]={
                          0.0,
                          0.1,
                          0.2,
                          0.3,
                          0.4,
                          0.5,
                          0.6,
                          0.7,
                          0.8,
                          0.9
                          };

 #ifdef TIMESTAT
   clock_start(7);
 #endif

 sx= (int) (viewx/poly_mask);
 sy= (int) (viewy/poly_mask);
 for (ix=sx-poly_grid; ix<sx+poly_grid+1; ix++) {
  for (iy=sy-poly_grid; iy<sy+poly_grid+1; iy++) {
   idx_x=ix-sx+poly_grid;
   idx_y=iy-sy+poly_grid;
   indx=(int)ix % mapwidth;
   indy=(int)iy % mapwidth;
   if (indx < 0) indx+=mapwidth;
   if (indy < 0) indy+=mapwidth;
   poly_map[idx_x][idx_y].pos.z=map_vertex(indx,indy);
   poly_map[idx_x][idx_y].pos.x=ix*poly_mask;
   poly_map[idx_x][idx_y].pos.y=iy*poly_mask;
   poly_map[idx_x][idx_y].drawn=0;
  }
 }
 for (idx_x=poly_grid-ground_view; idx_x<poly_grid+ground_view; idx_x++) {
  for (idx_y=poly_grid-ground_view; idx_y<poly_grid+ground_view; idx_y++) {

   cartvektor view_to_obj;
   float distance=sqrt(SQR(poly_map[idx_x][idx_y].pos.x-viewx)+SQR(poly_map[idx_x][idx_y].pos.y-viewy)+SQR(poly_map[idx_x][idx_y].pos.z-viewz));
   float normfak=1/distance;

   view_to_obj.x=poly_map[idx_x][idx_y].pos.x-viewx;
   view_to_obj.y=poly_map[idx_x][idx_y].pos.y-viewy;
   view_to_obj.z=poly_map[idx_x][idx_y].pos.z-viewz;
   view_to_obj=svmult(normfak,view_to_obj);

   /* Is object visible? */
   cos_diag_idx=distance/1000;
   if (cos_diag_idx>cos_diag_num-1) cos_diag_idx=cos_diag_num;
   if ( (VPRIK(view_to_obj,viewfront) > cos_diag_modif[cos_diag_idx]*cos_diag) || (distance < object[MAP].always_draw_dist)) {

   edge1=vminus(poly_map[idx_x+1][idx_y].pos,poly_map[idx_x][idx_y].pos);
   edge2=vminus(poly_map[idx_x][idx_y+1].pos,poly_map[idx_x][idx_y].pos);
   normvector=vkryds(edge1,edge2);
   view=poly_map[idx_x][idx_y].pos;
   view.x-=viewx;
   view.y-=viewy;
   view.z-=viewz;

   if (VPRIK(normvector,view) < 0) {
       float normfak = sqrt(SQR(normvector.x)+SQR(normvector.y)+SQR(normvector.z));
       float lighting=VPRIK(normvector,sun)/normfak;
       short gnd_col=poly_map_color(poly_map[idx_x][idx_y].pos.z,
                                    poly_map[idx_x][idx_y+1].pos.z,
                                    poly_map[idx_x+1][idx_y].pos.z);

        #ifdef TIMESTAT
           clock_stop(7);
        #endif

       map_to_poly_queue(poly_map[idx_x+1][idx_y].pos,
                         poly_map[idx_x][idx_y+1].pos,
                         poly_map[idx_x][idx_y].pos,
                         lighting,
                         find_ground_color(lighting,distance/(ground_view*1000),gnd_col)
                         );
        #ifdef TIMESTAT
           clock_start(7);
        #endif
   }

   edge1=vminus(poly_map[idx_x][idx_y+1].pos,poly_map[idx_x+1][idx_y+1].pos);
   edge2=vminus(poly_map[idx_x+1][idx_y].pos,poly_map[idx_x+1][idx_y+1].pos);
   normvector=vkryds(edge1,edge2);
   view=poly_map[idx_x+1][idx_y+1].pos;
   view.x-=viewx;
   view.y-=viewy;
   view.z-=viewz;

   if (VPRIK(normvector,view) < 0) {
       float normfak = sqrt(SQR(normvector.x)+SQR(normvector.y)+SQR(normvector.z));
       float lighting=VPRIK(normvector,sun)/normfak;
       short gnd_col=poly_map_color(poly_map[idx_x+1][idx_y+1].pos.z,
                     poly_map[idx_x][idx_y+1].pos.z,
                     poly_map[idx_x+1][idx_y].pos.z);

       #ifdef TIMESTAT
          clock_stop(7);
       #endif

       map_to_poly_queue(poly_map[idx_x+1][idx_y+1].pos,
                         poly_map[idx_x][idx_y+1].pos,
                         poly_map[idx_x+1][idx_y].pos,
                         lighting+0.41,
                         find_ground_color(lighting+0.2,distance/(ground_view*1000),gnd_col)
                         );
        #ifdef TIMESTAT
           clock_start(7);
        #endif
   }
  } /* endif */
  }
 }
  #ifdef TIMESTAT
   clock_stop(7);
  #endif
}



cartvektor rot_to_plane(cartvektor a)
{
 cartvektor b;

 b.x=0; b.y=0; b.z=0;
 b=vplus(b,svmult(a.x,front));
 b=vplus(b,svmult(a.y,left));
 b=vplus(b,svmult(a.z,top));
 return(b);
}



void draw_filled_poly(polygon_struct *flade, int id, cartvektor pos)
{
 int j;
 int p[maxnedges*2];
 bool outside=false;
 cartvektor scr_coord;

 for (j=0; j<flade->nedges; j++) {
     int v1=flade->edge[j];
     scr_coord=scrpos3d(vplus(pos,rot_to_plane(*(object[id].vertex+v1))));
     if (scr_coord.z < 1) outside=true;
     p[j*2]=scr_coord.x;
     p[j*2+1]=scr_coord.y;
 }
 if (outside==false) polygon(active_page, flade->nedges, p, flade->color);
}



void sort_poly_queue(void)
/* Sorting polygons by distance to viewer */
/* Bubble-sort like algoritm */
/* Sorts indices instead of whole structures, as this is faster */
{
 typedef struct {
   int   id;
   float dist;
   } sortinfo;

 sortinfo      to_sort[max_poly_queue_length];
 poly_scrcoord poly_temp[max_poly_queue_length];
 sortinfo      sort_temp;
 int           i;
 bool          ok=false;

 #ifdef TIMESTAT
   clock_start(2);
 #endif

 for (i=0; i<poly_queue_length; i++) {
     to_sort[i].id   = i;
     to_sort[i].dist = poly_queue[i].dist;
     poly_temp[i]    = poly_queue[i];
 }

 while (ok==false) {
  ok=true;
  for (i=0; i<poly_queue_length-1; i++) {
   if (to_sort[i].dist < to_sort[i+1].dist) {
    ok=false;
    sort_temp=to_sort[i];
    to_sort[i]=to_sort[i+1];
    to_sort[i+1]=sort_temp;
   }
  }
 }

 for (i=0; i<poly_queue_length; i++)
     poly_queue[i]=poly_temp[to_sort[i].id];

 #ifdef TIMESTAT
   clock_stop(2);
 #endif
}



void draw_poly_queue(void)
/* Draw polygons in the queue, using fill pattern for light source shading */
{
 int i;
 int tmpcol=0;
 /*
 char nul88[8] = {253,223,247,127,253,223,247,127};
 char nul75[8] = {238,187,238,187,238,187,238,187};
 char nul69[8] = {182,219,182,109,182,219,182,109};
 char nul5[8]  = {
  0xAA,   // 10101010  =  Û Û Û Û 
  0x55,   // 01010101  =   Û Û Û Û
  0xAA,   // 10101010  =  Û Û Û Û 
  0x55,   // 01010101  =   Û Û Û Û
  0xAA,   // 10101010  =  Û Û Û Û 
  0x55,   // 01010101  =   Û Û Û Û
  0xAA,   // 10101010  =  Û Û Û Û 
  0x55    // 01010101  =   Û Û Û Û 
  };
 */

 #ifdef TIMESTAT
   clock_start(3);
 #endif

 for (i=0; i<poly_queue_length; i++) {

  if (many_colors==false){
	  /*
     switch(poly_queue[i].fill) {

     case 0: setfillstyle(SOLID_FILL,poly_queue[i].color);
          break;
     case 1: setfillpattern(nul88,poly_queue[i].color);
          break;
     case 2: setfillpattern(nul75,poly_queue[i].color);
          break;
     case 3: setfillpattern(nul69,poly_queue[i].color);
          break;
     case 4: setfillpattern(nul5,poly_queue[i].color);
          break;
     };
	 */
     tmpcol=poly_queue[i].color;
	
  }
  else {
        short col=poly_queue[i].color;
        if ((col < 16) && (col>=0) ){
          tmpcol=colortable[col][poly_queue[i].fill];
        }
        if (col >= 16) {
          tmpcol=col;
        }
        if (col < 0) {
          tmpcol=-col;
        }
  }

  polygon(active_page, poly_queue[i].nedges,poly_queue[i].scr_coords, tmpcol);
 }
 poly_queue_length=0;

 #ifdef TIMESTAT
   clock_stop(3);
 #endif
}



void draw_poly_plane(int id)
{
 cartvektor a,b,pos,view,pilpos;
 int i,k;
 cartvektor normvector,edge1,edge2;
 ori_vector orient;

 orient.rot=false;

 #ifdef TIMESTAT
   clock_start(6);
 #endif

 pos.x=x; pos.y=y; pos.z=z;
 pilpos = rot_to_plane(pilotpos);

 for (i=0; i<object[id].nfacets; i++) {
  edge1=vminus(*(object[id].vertex+(object[id].facet+i)->edge[1]),
               *(object[id].vertex+(object[id].facet+i)->edge[0]));
  k=2;
  if (k==(object[id].facet+i)->nedges) k=0;
  edge2=vminus(*(object[id].vertex+(object[id].facet+i)->edge[k]),
               *(object[id].vertex+(object[id].facet+i)->edge[1]));

  edge1=rot_to_plane(edge1);
  edge2=rot_to_plane(edge2);
  normvector=vkryds(edge1,edge2);
  view=vplus(pos,rot_to_plane(*(object[id].vertex+(object[id].facet+i)->edge[0])));
  view.x-=viewx;
  view.y-=viewy;
  view.z-=viewz;

  if (VPRIK(normvector,view) < 0) {
    float normfak = sqrt(SQR(normvector.x)+SQR(normvector.y)+SQR(normvector.z));
    float lighting=VPRIK(normvector,sun)/normfak;
     #ifdef TIMESTAT
        clock_stop(6);
     #endif
    if (viewpoint == 8 || viewpoint < 4)
      local_filled_poly_to_queue(object[id].facet+i, id, pilpos, lighting, orient);
    else
      filled_poly_to_queue(object[id].facet+i, id, pos, lighting, orient);
     #ifdef TIMESTAT
       clock_start(6);
     #endif
  }
 }

 /* Only draw stuff below if less than 2km to viewer */
 if ( SQR(x-viewx)+SQR(y-viewy)+SQR(z-viewz) < 4e6 ) {

 draw_ctrl_surfaces(id);

 if (hook.down > 0) {
   cartvektor ga,gb;

   ga.x=hook.hingepos.x;
   ga.y=hook.hingepos.y;
   ga.z=hook.hingepos.z;
   gb.x=hook.hingepos.x-hook.length*(1-hook.down*0.643);
   gb.y=hook.hingepos.y;
   gb.z=hook.hingepos.z-hook.length*hook.down*0.766;
   a.x=x; a.y=y; a.z=z;
   b.x=x; b.y=y; b.z=z;
   a=vplus(a,svmult(ga.x,front));
   a=vplus(a,svmult(ga.y,left));
   a=vplus(a,svmult(ga.z,top));
   b=vplus(b,svmult(gb.x,front));
   b=vplus(b,svmult(gb.y,left));
   b=vplus(b,svmult(gb.z,top));
   draw3d(a.x,a.y,a.z,b.x,b.y,b.z, WHITE_SHADE);
 }

 }

 #ifdef TIMESTAT
   clock_stop(6);
 #endif
}



void draw_cockpit(int id)
{
 /* Draws virtual cockpit */
 /* All coordinates are local, to avoid floating point precision
    problems with global coordiantes */

 cartvektor view, pilpos;
 int i,k;
 cartvektor normvector,edge1,edge2;
 ori_vector orient;

 orient.rot=false;

 if (id < 0) return;  /* No cockpit defined */

 pilpos = rot_to_plane(pilotpos);

 for (i=0; i<object[id].nfacets; i++) {
  /* Determine whether the surface is visible */
  edge1=vminus(*(object[id].vertex+(object[id].facet+i)->edge[1]),
               *(object[id].vertex+(object[id].facet+i)->edge[0]));
  k=2;
  if (k==(object[id].facet+i)->nedges) k=0;
  edge2=vminus(*(object[id].vertex+(object[id].facet+i)->edge[k]),
               *(object[id].vertex+(object[id].facet+i)->edge[1]));

  edge1=rot_to_plane(edge1);
  edge2=rot_to_plane(edge2);
  normvector=vkryds(edge1,edge2);

  view=vminus(rot_to_plane(*(object[id].vertex+(object[id].facet+i)->edge[0])),pilpos);

  if (VPRIK(normvector,view) < 0) {
    /* It's visible, so draw the surface */
    float normfak = sqrt(SQR(normvector.x)+SQR(normvector.y)+SQR(normvector.z));
    float lighting=VPRIK(normvector,sun)/normfak;

    local_filled_poly_to_queue(object[id].facet+i, id, pilpos, lighting, orient);
  }
 }
}



void draw_bullets()
{
 int i=0;
 int n=0;

 while (n < nactive_bullets) {
  if (bullet[i].active) {
   n++;
   if (bullet[i].tracer)
      point3d(bullet[i].pos,WHITE);
  }
  i++;
 }
}



void explode(cartvektor pos)
{
 draw3d(pos.x,pos.y,pos.z,pos.x,pos.y,pos.z+4,   YELLOW);
 draw3d(pos.x,pos.y,pos.z,pos.x+1,pos.y,pos.z+2, YELLOW);
 draw3d(pos.x,pos.y,pos.z,pos.x,pos.y+1,pos.z+2, YELLOW);
 draw3d(pos.x,pos.y,pos.z,pos.x-1,pos.y,pos.z+2, YELLOW);
 draw3d(pos.x,pos.y,pos.z,pos.x,pos.y-1,pos.z+2, YELLOW);
}



void sym_explode(cartvektor pos)
{
 draw3d(pos.x-2,pos.y-2,pos.z-2, pos.x+2,pos.y+2,pos.z+2, YELLOW);
 draw3d(pos.x-2,pos.y+2,pos.z-2, pos.x+2,pos.y-2,pos.z+2, YELLOW);
 draw3d(pos.x+2,pos.y-2,pos.z-2, pos.x-2,pos.y+2,pos.z+2, YELLOW);
 draw3d(pos.x+2,pos.y+2,pos.z-2, pos.x-2,pos.y-2,pos.z+2, YELLOW);
}


void draw_targets()
{
 int i;
 for (i=0; i<ntargets; i++)
     if (target[i].strength > target[i].nhits)
        draw_object(TARGET, target[i].pos);
}



void draw_sun()
{
	update_sun(running_time);
	sun_to_poly_queue();
	update_lightvector();
}



void outside()
{
 cartvektor pos;
 int i;

 /* slet skaerm */
 #ifdef TIMESTAT
    clock_start(4);
 #endif
 filled_horizon();
 #ifdef TIMESTAT
    clock_stop(4);
 #endif

 if (groundtype==0) {
	flatground(10,100,DARKGRAY);
	flatground(10,1000,BROWN);
	draw_stars();
	draw_sun();
	sort_poly_queue();
	draw_poly_queue();
 }
 else {
       draw_stars();
	   draw_sun();
	   sort_poly_queue();
	   draw_poly_queue();
       draw_poly_map();
       sort_poly_queue();
       if (poly_queue_length > 0) horizon_color=poly_queue[0].color;
       draw_poly_queue();


       if ( viewz < groundalt(viewx,viewy)+3000 ) dot_ground(10,100);
 }

 if (world == EARTH) {
 for (i=0; i<nobjectpos; i++) {
   pos.x=file_objectpos[i].pos.x;
   pos.y=file_objectpos[i].pos.y;
   pos.z=file_objectpos[i].pos.z + groundalt(pos.x,pos.y);
   if (file_objectpos[i].rot==0)
      draw_object(file_objectpos[i].object, pos);
   else {
      float angle=file_objectpos[i].rot*PI/180;
      float sinv = sin(angle);
      float cosv = cos(angle);
      ori_vector orient;

      orient.rot=TRUE;
      orient.top.x=0;
      orient.top.y=0;
      orient.top.z=1;
      orient.front.x= cosv;
      orient.front.y=-sinv;
      orient.front.z= 0;
      orient.left.x= sinv;
      orient.left.y= cosv;
      orient.left.z= 0;

      draw_rot_object(file_objectpos[i].object, pos, orient);
   }
   if (file_objectpos[i].draw_now) {
     sort_poly_queue();
     draw_poly_queue();
   }
 }
 sort_poly_queue();
 draw_poly_queue();

 if (running_time > 17.75 || running_time < 6.25) draw_airfield_lights();
 }

 /* tower */
 if (viewpoint!=4) { /* view tower from outside */
	if (world==EARTH) {
		pos.x=1200; pos.y=50; pos.z=airfieldalt;
		draw_object(TOWER,pos);
	}
 }
 else tower(); /* view tower from the inside */
 
 if (world==EARTH) {
	pos.x=1300; pos.y=40; pos.z=airfieldalt;
	draw_object(WINDBAG,pos);
	draw3d(pos.x,pos.y,pos.z,pos.x,pos.y,pos.z+6.8, GRAY_SHADE);
	sort_poly_queue();
	draw_poly_queue();
 }

 draw_targets();
 sort_poly_queue();
 draw_poly_queue();

 if (world==EARTH) draw_carrier();

 draw_propellers();
 if (poly_plane_id[current_model]==F14) update_sweep_graphics();

 if (!(!show_plane_inside && (viewpoint == 8 || viewpoint < 4 || viewpoint == 10)))
    draw_poly_plane(poly_plane_id[current_model]);
	if (poly_plane_id[current_model] == LM) {
		cartvektor orgpos, nypos;
		orgpos.x = x;
		orgpos.y = y;
		orgpos.z = z;
		nypos = vplus(svmult(0.35, top),orgpos);
		x=nypos.x;
		y=nypos.y;
		z=nypos.z;
		draw_poly_plane(LM_ASCENT);
		x=orgpos.x;
		y=orgpos.y;
		z=orgpos.z;
	}
 draw_JBD();

 draw_bullets();

 sort_poly_queue();
 draw_poly_queue();

 if (show_cockpit && (viewpoint == 8 || viewpoint < 4 || viewpoint == 10))
   draw_cockpit(cockpit_id[current_model]);

 sort_poly_queue();
 draw_poly_queue();
}
