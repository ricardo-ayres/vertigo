
#include <time.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>

#include "bool.h"
#include "objects/objects.h"
#include "vertigo.h"
#include "map.h"
#include "carrier.h"
#include "config.h"

#define rnd(a)        random() % (int) a


static int map[mapsize][mapsize];
static bool first_call=true;

/* in VERTIGO.C */
extern int airfieldalt;
extern int groundtype;
extern int nwaypoints;
extern waypoint waypointlst[maxnwaypoints];

/* In MYMATH.C */
extern cartvektor svmult(float a, cartvektor b);

#include "mymath.h"



float groundalt(float xg, float yg)
/* returns ground altitude at xg,yg */
{
 int ix,iy;
 int indx,indy;
 long lx,ly;
 float fracx,fracy;
 float a,b,c,d;
 /* float alt; */
 const int mask=1000;
 const int mapwidth=mapsize-1;

 /*
 alt=carrier_deck_alt(xg,yg);
 if (alt > 0) return(alt);
 */

 if (groundtype==0) return(0); /* Flat ground */

 /* Translate xg,yg to map indices */
 ix= (xg/mask);
 iy= (yg/mask);
 if (xg < 0) ix-=1; /* To compensate for round-off differences */
 if (yg < 0) iy-=1; /* between positive and negative numbers */

 /* Geometry used:

 C--D ^
 |\ | |
 | \| y
 A--B  x ->

 */

 indx=ix % mapwidth;
 indy=iy % mapwidth;
 if (indx < 0) indx+=mapwidth;
 if (indy < 0) indy+=mapwidth;
 a=map[indx][indy];

 indx=(ix+1) % mapwidth;
 indy=iy % mapwidth;
 if (indx < 0) indx+=mapwidth;
 if (indy < 0) indy+=mapwidth;
 b=map[indx][indy];

 indx=ix % mapwidth;
 indy=(iy+1) % mapwidth;
 if (indx < 0) indx+=mapwidth;
 if (indy < 0) indy+=mapwidth;
 c=map[indx][indy];

 indx=(ix+1) % mapwidth;
 indy=(iy+1) % mapwidth;
 if (indx < 0) indx+=mapwidth;
 if (indy < 0) indy+=mapwidth;
 d=map[indx][indy];

 lx=xg/mask;
 ly=yg/mask;
 if (xg < 0) lx-=1;
 if (yg < 0) ly-=1;
 fracx=xg/mask-lx; /* Fractional part of x */
 fracy=yg/mask-ly;


 if (fracx+fracy<1)  /* In triangle ABC */
	return(a+fracx*(b-a)+fracy*(c-a));
 else                /* In triangle BCD */
	return(d+(1-fracx)*(c-d)+(1-fracy)*(b-d));
}



cartvektor groundnorm(float xg, float yg)
/* 	Similar to groundalt function,
	but returns vector perpendicular to ground at xg,yg */

{
 int ix,iy;
 int indx,indy;
 long lx,ly;
 float fracx,fracy;
 float a,b,c,d;
 const int mask=1000;
 const int mapwidth=mapsize-1;
 cartvektor norm;
 float normlen;

 if (groundtype==0) {  /* Flat ground */
	norm.x=0;
	norm.y=0;
	norm.z=1;
	return(norm);
 }

 /* Translate xg,yg to map indices */
 ix= (xg/mask);
 iy= (yg/mask);
 if (xg < 0) ix-=1; /* To compensate for round-off differences */
 if (yg < 0) iy-=1; /* between positive and negative numbers */

 /* Geometry used:

 C--D ^
 |\ | |
 | \| y
 A--B  x ->

 */

 indx=ix % mapwidth;
 indy=iy % mapwidth;
 if (indx < 0) indx+=mapwidth;
 if (indy < 0) indy+=mapwidth;
 a=map[indx][indy];

 indx=(ix+1) % mapwidth;
 indy=iy % mapwidth;
 if (indx < 0) indx+=mapwidth;
 if (indy < 0) indy+=mapwidth;
 b=map[indx][indy];

 indx=ix % mapwidth;
 indy=(iy+1) % mapwidth;
 if (indx < 0) indx+=mapwidth;
 if (indy < 0) indy+=mapwidth;
 c=map[indx][indy];

 indx=(ix+1) % mapwidth;
 indy=(iy+1) % mapwidth;
 if (indx < 0) indx+=mapwidth;
 if (indy < 0) indy+=mapwidth;
 d=map[indx][indy];

 lx=xg/mask;
 ly=yg/mask;
 if (xg < 0) lx-=1;
 if (yg < 0) ly-=1;
 fracx=xg/mask-lx; /* Fractional part of x */
 fracy=yg/mask-ly;

 if (fracx+fracy<1) { /* In triangle ABC */
	norm.x=a-b;
	norm.y=a-c;
	norm.z=mask;
	/* Normalize normal vector */
	normlen=sqrt(VPRIK(norm,norm));
	norm=svmult(1./normlen,norm);
	return(norm); }
 else {               /* In triangle BCD */
	norm.x=c-d;
	norm.y=b-d;
	norm.z=mask;
	/* Normalize normal vector */
	normlen=sqrt(VPRIK(norm,norm));
	norm=svmult(1./normlen,norm);
	return(norm);
 }
}



int map_vertex(int x, int y)
{
 return(map[x][y]);
}



int fract_build(int bredde, int xcorn, int ycorn)
{
 int i;
 int halv=bredde/2;
 const int roughfak=100;

 /* return, if finished building */
 if (bredde<=2) return(0);

 /* Ensure seamless wrap-around at map-edge */
 for (i=0; i<mapsize; i++)
  if (map[i][0]!=0) map[i][mapsize-1]=map[i][0];
 for (i=0; i<mapsize; i++)
  if (map[i][mapsize-1]!=0) map[i][0]=map[i][mapsize-1];
 for (i=0; i<mapsize; i++)
  if (map[0][i]!=0) map[mapsize-1][i]=map[0][i];
 for (i=0; i<mapsize; i++)
  if (map[mapsize-1][i]!=0) map[0][i]=map[mapsize-1][i];

 /* Fill in new points */
 if (map[xcorn+halv][ycorn]==0)
	map[xcorn+halv][ycorn]=
	(map[xcorn][ycorn]+map[xcorn+bredde-1][ycorn])/2.+
	rnd(bredde*roughfak)-(bredde*roughfak)/2;

 if (map[xcorn][ycorn+halv]==0)
	map[xcorn][ycorn+halv]=
	(map[xcorn][ycorn]+map[xcorn][ycorn+bredde-1])/2.+
	rnd(bredde*roughfak)-(bredde*roughfak)/2;

 if (map[xcorn+halv][ycorn+bredde-1]==0)
	map[xcorn+halv][ycorn+bredde-1]=
	(map[xcorn][ycorn+bredde-1]+map[xcorn+bredde-1][ycorn+bredde-1])/2.+
	rnd(bredde*roughfak)-(bredde*roughfak)/2;

 if (map[xcorn+bredde-1][ycorn+halv]==0)
	map[xcorn+bredde-1][ycorn+halv]=
	(map[xcorn+bredde-1][ycorn]+map[xcorn+bredde-1][ycorn+bredde-1])/2.+
	rnd(bredde*roughfak)-(bredde*roughfak)/2;

 if (map[xcorn+halv][ycorn+halv]==0)
	map[xcorn+halv][ycorn+halv]=
	(map[xcorn+halv][ycorn]+map[xcorn][ycorn+halv]+
	 map[xcorn+halv][ycorn+bredde-1]+map[xcorn+bredde-1][ycorn+halv])/4.+
	rnd(bredde*roughfak)-(bredde*roughfak)/2;

 /* for improper sizing of the array, this error-check should work */
 /*
 if (xcorn+bredde-1 > mapsize-1) {
	cprintf("Bredde %4i xcorn %4i ycorn %4i halv %4i\n\r",
	bredde,xcorn,ycorn,halv);
	errorexit(1);
 }
 if (ycorn+bredde-1 > mapsize-1) {
	cprintf("Bredde %4i xcorn %4i ycorn %4i halv %4i\n\r",
	bredde,xcorn,ycorn,halv);
	errorexit(1);
 }
 */

 /* recursively fill in map */
 fract_build(halv+1,xcorn,ycorn);
 fract_build(halv+1,xcorn+halv,ycorn);
 fract_build(halv+1,xcorn,ycorn+halv);
 fract_build(halv+1,xcorn+halv,ycorn+halv);

 return(0);
}



void init_map()
{
 int i,j;
 int alt;
 extern int world;

 /* Zero map */
 for (i=0; i<mapsize; i++) {
  for (j=0; j<mapsize; j++) {
   map[i][j]=0;
  }
 }

 if (first_call) {
    #ifndef NO_RANDOMIZE
     srandom(time(0));
    #endif
    first_call=false;
 }

 /* Will be roughly the altitude of the airfield */
 map[0][0]=rnd(1000)-500;

 fract_build(mapsize,0,0);

 if (world == EARTH) {
	/* Make plane area for airfield */
	alt=(map[1][0]+map[2][0]+map[3][0])/3;
	if (alt <= 0) alt=200;
	airfieldalt=alt;
	map[1][0]=alt;
	map[2][0]=alt;
	map[3][0]=alt;
	map[1][1]=alt;
	map[2][1]=alt;
	map[3][1]=alt;
	map[1][mapsize-2]=alt;
	map[2][mapsize-2]=alt;
	map[3][mapsize-2]=alt;
 }
 else {
	/* Make smaller plane area for Lunar lander */
	alt=(map[1][0]+map[2][0])/2;
	if (alt <= 0) alt=0;
	airfieldalt=alt;
	map[1][0]=alt;
	map[2][0]=alt;
	map[1][1]=alt;
	map[2][1]=alt;
 }

}



cartvektor find_lowest_point()
{
 int i,j;
 float minalt=1e6;
 int minxpos=0;
 int minypos=0;
 cartvektor pos;

 for (i=0; i<mapsize-1; i++) {
  for (j=0; j<mapsize-1; j++) {
   if (map[i][j] < minalt) {
      minalt=map[i][j];
      minxpos=i;
      minypos=j;
   }
  }
 }
 pos.x=minxpos;
 pos.y=minypos;
 pos.z=minalt;

 return pos;
}



void create_sea()
{
/* Put negative levels at sea-level */
/* Called seperately in order to find best spot for carrier */
 int i,j;

 for (i=0; i<mapsize-1; i++) {
  for (j=0; j<mapsize-1; j++) {
   if (map[i][j]<0) map[i][j]=0;
  }
 }
}



void init_waypoints()
{
 extern int rw_wpt_id;

 /* Set waypoint at airfield */
 waypointlst[nwaypoints].pos.x=1850;
 waypointlst[nwaypoints].pos.y=   0;
 waypointlst[nwaypoints].pos.z=airfieldalt;
 strcpy(waypointlst[nwaypoints].ident,"HOME");
 rw_wpt_id=nwaypoints;
 nwaypoints++;

 /* Shooting gallery*/
 waypointlst[nwaypoints].pos.x= 10000.;
 waypointlst[nwaypoints].pos.y= -5000.;
 waypointlst[nwaypoints].pos.z=     0.;
 strcpy(waypointlst[nwaypoints].ident,"TARGETS");
 nwaypoints++;

}
