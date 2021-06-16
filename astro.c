#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#include "bool.h"
#include "objects/objects.h"
#include "vertigo.h"
#include "astro.h"
#include "polygrap.h"
#include "mymath.h"

/* In vertigo.c */
extern void errormessage(char *text);

extern int star_mag_lim;
extern float sidereal_time;
extern float latitude;

static star_form *star;
static cartvektor *star_vect;
static int nentries;

static int mag_lim_id=0;



void read_stars()
{
 FILE *fp;
 int i;

 if ((fp=fopen("ybstars.dat","r")) == NULL)
        errormessage("Cannot open file: ybstars.dat\n\r");

 if(!feof(fp))
       fscanf(fp,"%d\n",&nentries);
     else {
       fclose(fp);
       errormessage("Premature end of file: ybstars.dat\n\r");
 }

 if ((star = malloc(nentries*sizeof(star_form))) == NULL)
    errormessage("Not enough memory\n");

 for (i=0; i<nentries; i++) {

     if(!feof(fp))
       fscanf(fp,"%f\n",&((star+i)->ra));
     else {
       fclose(fp);
       errormessage("Premature end of file: ybstars.dat\n\r");
     }
     if(!feof(fp))
       fscanf(fp,"%f\n",&((star+i)->dec));
     else {
       fclose(fp);
       errormessage("Premature end of file: ybstars.dat\n\r");
     }
     if(!feof(fp))
       fscanf(fp,"%f\n",&((star+i)->mag));
     else {
       fclose(fp);
       errormessage("Premature end of file: ybstars.dat\n\r");
     }

 }

 fclose(fp);

 #ifdef LINUX
  printf("Loaded %d stars.\n\r",nentries);
 #endif
}



void update_stars()
{
 int i;
 float cos_lat = cos(PI/2-latitude);
 float sin_lat = sin(PI/2-latitude);

 for (i=0; i<mag_lim_id; i++) {
   /* Rotate polar coords. for siderial time */
   float ra  = (star+i)->ra - PI - 2*PI*sidereal_time/24.0;
   float dec = (star+i)->dec;
   float x,y,z;
   float x2,y2,z2;

   /* Convert from polar to Cartesian */
   x = cos(dec) * cos(ra);
   y = cos(dec) * sin(ra);
   z = sin(dec);

   /* Account for latitude */
   x2 = sin_lat * z + cos_lat * x;
   y2 = y;
   z2 = cos_lat * z - sin_lat * x;

   (star_vect+i)->x = x2;
   (star_vect+i)->y = y2;
   (star_vect+i)->z = z2;

 }
}



void draw_stars()
{
 int i;

   for (i=mag_lim_id-1; i>=0; i--) { /* Draw faintest stars first */
   if ((star_vect+i)->z > 0) {     /* Above horizon */
     int color = 212;
     int j;

     for (j=6; j>=0; j--)
      if ( (star+i)->mag < (float) j*0.667 )
         color = 219 - j;
     /*
     m4.0  - 5.0  : 212
     m3.33 - 3.99 : 213
     m2.66 - 3.33 : 214
     ...
     */

     point_vect(*(star_vect+i),color);
   }
 }

}



void find_mag_lim_id()
{
 int i;
 int id = 0;
 
 if (star_mag_lim==0)
    mag_lim_id=0;

 if (star_mag_lim==5)
    mag_lim_id=nentries;

 if (star_mag_lim==3) {
    for (i=nentries-1; i>=0; i--) {
        if ((star+i)->mag >=3)
           id = i+1;
    }
    mag_lim_id=id; 
 }
}



void init_stars()
{
 read_stars();
 find_mag_lim_id();

 if ((star_vect = malloc(nentries*sizeof(cartvektor))) == NULL)
    errormessage("Not enough memory\n");

 update_stars();

}



void update_sun(float time)
{
	extern float sun_hour;

	sun_hour = 2*PI*((time + 6.) / 24);
}
