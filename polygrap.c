#include <math.h>
#ifndef LINUX
#  include <conio.h>
#else
#  include <stdio.h>
#endif

#include <stdlib.h>

#include <allegro.h>

#include "bool.h"
#include "objects/objects.h"
#include "vertigo.h"
#include "polygrap.h"
#include "map.h"
#ifdef TIMESTAT
#  include "timestat.h"
#endif

#define MAP_SCALE 140


extern bool crash;
extern short current_model;
extern int  poly_plane_id[nmodels];
extern int  cockpit_id[nmodels];
extern object3D object[maxnobjects];
extern float viewx,viewy,viewz;
extern int   xpixels,ypixels,xcenter,ycenter;
extern poly_scrcoord poly_queue[max_poly_queue_length];
extern int poly_queue_length;
extern float scrnwidth,scrnheight,viewdist;
extern cartvektor viewfront,viewleft,viewtop;
extern int horizon_color;
extern bool many_colors;
extern short groundtype;
extern float xscl,yscl;
extern short groundtype;
extern BITMAP *active_page;

/* In MYMATH.C */
cartvektor vplus(cartvektor a, cartvektor b);
cartvektor vminus(cartvektor a, cartvektor b);
cartvektor vkryds(cartvektor a, cartvektor b);
cartvektor svmult(float a, cartvektor b);
#include "mymath.h"

/* In GRAPHICS.C */
cartvektor rot_to_plane(cartvektor a);
void sort_poly_queue(void);
void draw_poly_queue(void);
void printfg(float x,int len,int dec);
void printg(float x,int len);

/* For control surface animation */
static polygon_struct    ctrl_poly;
static cartvektor ctrl_vertex[maxnedges];

/* For propeller animation */
#define PROPSEGMENTS 16
static float prop_seg_x[PROPSEGMENTS];
static float prop_seg_y[PROPSEGMENTS];

/* For F-14 wing sweep animation */
#define nsweepvertices    64
#define firstsweepvertex 286
static cartvektor sweepvertex[nsweepvertices];
static cartvektor ctrlvertex[8];
static float lastsweep=0;


#define NAIRFIELDLIGHTS 99
static light lightlist[NAIRFIELDLIGHTS];

void setup_sweep_buffer()
/* Store un-swept wing coordinates of F-14 */
{
 int i;
 for (i=0; i<nsweepvertices; i++)
     sweepvertex[i]=object[F14].vertex[firstsweepvertex+i];
 for (i=0; i<8; i++) {
     ctrlvertex[i].x=object[F14].ctrl_surface[i].hinge.x;
     ctrlvertex[i].y=object[F14].ctrl_surface[i].hinge.y;
 }
}



void update_sweep_graphics()
{
 extern float sweep;

 if (sweep != lastsweep) {
   float fulcrum_x=sweepvertex[0].x;
   float fulcrum_y=sweepvertex[0].y-0.35;
   float cos_swp=cos(PI*(sweep-20)/180);
   float sin_swp=sin(PI*(sweep-20)/180);
   int i;

   for (i=0; i<nsweepvertices; i++){
    if (sweepvertex[i].y > 0) {
     cartvektor newpos;
     float wingx=sweepvertex[i].x-fulcrum_x;
     float wingy=sweepvertex[i].y-fulcrum_y;

     newpos.x= fulcrum_x+cos_swp*wingx-sin_swp*wingy;
     newpos.y= fulcrum_y+cos_swp*wingy+sin_swp*wingx;
     newpos.z= sweepvertex[i].z;

     object[F14].vertex[firstsweepvertex+i]=newpos;
    }
    else {
     cartvektor newpos;
     float wingx=sweepvertex[i].x-fulcrum_x;
     float wingy=-sweepvertex[i].y-fulcrum_y;

     newpos.x= fulcrum_x+cos_swp*wingx-sin_swp*wingy;
     newpos.y=-fulcrum_y-cos_swp*wingy-sin_swp*wingx;
     newpos.z= sweepvertex[i].z;

     object[F14].vertex[firstsweepvertex+i]=newpos;
    }
   }

   object[F14].vertex[318]=sweepvertex[32];
   object[F14].vertex[319]=sweepvertex[33];


   if (sweep < 55) {
     int j;

     object[F14].ctrl_surface[4].nctrlpoly=4;
     object[F14].ctrl_surface[5].nctrlpoly=4;
     /*
     object[F14].ctrl_surface[4].flap_gain=-1.50;
     object[F14].ctrl_surface[5].flap_gain=-1.50;
     */

     for (i=0; i<8; i++){
      if (ctrlvertex[i].y > 0) {
       cartvektor newpos;
       float wingx=ctrlvertex[i].x-fulcrum_x;
       float wingy=ctrlvertex[i].y-fulcrum_y;

       newpos.x= fulcrum_x+cos_swp*wingx-sin_swp*wingy;
       newpos.y= fulcrum_y+cos_swp*wingy+sin_swp*wingx;

       object[F14].ctrl_surface[i].hinge.x=newpos.x;
       object[F14].ctrl_surface[i].hinge.y=newpos.y;
      }
      else {
       cartvektor newpos;
       float wingx= ctrlvertex[i].x-fulcrum_x;
       float wingy=-ctrlvertex[i].y-fulcrum_y;

       newpos.x= fulcrum_x+cos_swp*wingx-sin_swp*wingy;
       newpos.y=-fulcrum_y-cos_swp*wingy-sin_swp*wingx;

       object[F14].ctrl_surface[i].hinge.x=newpos.x;
       object[F14].ctrl_surface[i].hinge.y=newpos.y;
      }
     }

 /* Define control surface rotation axis */
 object[F14].ctrl_surface[0].axis =
   vminus(*(object[F14].vertex+308),*(object[F14].vertex+318));
 object[F14].ctrl_surface[1].axis =
   vminus(*(object[F14].vertex+319),*(object[F14].vertex+309));
 object[F14].ctrl_surface[2].axis =
   vminus(*(object[F14].vertex+322),*(object[F14].vertex+325));
 object[F14].ctrl_surface[3].axis =
   vminus(*(object[F14].vertex+327),*(object[F14].vertex+323));
 object[F14].ctrl_surface[4].axis =
   vminus(*(object[F14].vertex+322),*(object[F14].vertex+325));
 object[F14].ctrl_surface[5].axis =
   vminus(*(object[F14].vertex+327),*(object[F14].vertex+323));
 object[F14].ctrl_surface[6].axis =
   vminus(*(object[F14].vertex+342),*(object[F14].vertex+343));
 object[F14].ctrl_surface[7].axis =
   vminus(*(object[F14].vertex+344),*(object[F14].vertex+345));

 for (j=0; j<8; j++){
  float norm;
  cartvektor tmp, tmp2;

  /* Generer orthonormalsystem */
  norm=sqrt(VPRIK(object[F14].ctrl_surface[j].axis,
                  object[F14].ctrl_surface[j].axis));
  object[F14].ctrl_surface[j].front=
                  svmult(1./norm,object[F14].ctrl_surface[j].axis);
  /* Roter 90 deg om z */
  tmp.x = -object[F14].ctrl_surface[j].front.y;
  tmp.y =  object[F14].ctrl_surface[j].front.x;
  tmp.z =  object[F14].ctrl_surface[j].front.z;

  /* Roter 90 deg om x - dermed haves vektor ej parallel med front */
  tmp2.x =  tmp.x;
  tmp2.y = -tmp.z;
  tmp2.z =  tmp.y;

  object[F14].ctrl_surface[j].left =
   vkryds(object[F14].ctrl_surface[j].front,tmp2);
  norm=sqrt(VPRIK(object[F14].ctrl_surface[j].left,
                  object[F14].ctrl_surface[j].left));
  object[F14].ctrl_surface[j].left=
                  svmult(1./norm,object[F14].ctrl_surface[j].left);

  object[F14].ctrl_surface[j].top =
   vkryds(object[F14].ctrl_surface[j].front,object[F14].ctrl_surface[j].left);
 }

   }

   if (sweep > 67 ) {
     /* Hide part of inboard flaps if sweep is large */
     object[F14].ctrl_surface[4].nctrlpoly=2;
     object[F14].ctrl_surface[5].nctrlpoly=2;
     /*
     object[F14].ctrl_surface[4].flap_gain =0;
     object[F14].ctrl_surface[5].flap_gain =0;
     */
     object[F14].vertex[294]=object[F14].vertex[292];
     object[F14].vertex[300]=object[F14].vertex[292];
     object[F14].vertex[295]=object[F14].vertex[293];
     object[F14].vertex[301]=object[F14].vertex[293];
   }

   lastsweep=sweep;
 }
}



linecoord local_calc_line_project(cartvektor p1, cartvektor p2)
/* Calculate projected screen coordinates of end points of a 3D-line */
{
 cartvektor xyz1,xyz2,flt1,flt2;
 float sx1=0,sy1=0,sx2=0,sy2=0,status1=0,status2=0;
 float xpixpermeter=xpixels/scrnwidth;
 float ypixpermeter=ypixels/scrnheight;
 float ay,by,az,bz;
 linecoord result;

 xyz1.x=p1.x;
 xyz1.y=p1.y;
 xyz1.z=p1.z;
 xyz2.x=p2.x;
 xyz2.y=p2.y;
 xyz2.z=p2.z;

 /* Representation in top,front,left coordinates */
 flt1.x=VPRIK(xyz1,viewfront);
 flt1.y=VPRIK(xyz1,viewleft);
 flt1.z=VPRIK(xyz1,viewtop);
 flt2.x=VPRIK(xyz2,viewfront);
 flt2.y=VPRIK(xyz2,viewleft);
 flt2.z=VPRIK(xyz2,viewtop);

 /* Statis= 0 if point is on screen */
 /* Status=-3 if one point behind observer */
 /* Status=-2 if both points behind observer */

 if (flt1.x<=0) status1=-3;

 if (flt2.x<=0) status2=-3;

 if (flt1.x<=0 && flt2.x<=0)
    status1=status2=-2;
 else {
       sx1=xcenter-(flt1.y*viewdist/flt1.x)*xpixpermeter;
       sy1=ycenter-(flt1.z*viewdist/flt1.x)*ypixpermeter;

       sx2=xcenter-(flt2.y*viewdist/flt2.x)*xpixpermeter;
       sy2=ycenter-(flt2.z*viewdist/flt2.x)*ypixpermeter;

       /* If one point is behind screen then interpolate onto screen */
       if (flt1.x <= 0 || flt2.x <= 0) {
	       float y_scr,z_scr;

	       /* Express line as y=ay*x+by and z=az*x+bz */
	       if (flt2.x==flt1.x)
           flt2.x+=0.1; /* Avoid div. by 0 */
	       ay=(flt2.y-flt1.y)/(flt2.x-flt1.x);
	       by=flt1.y-ay*flt1.x;
	       az=(flt2.z-flt1.z)/(flt2.x-flt1.x);
	       bz=flt1.z-az*flt1.x;

	       /* Find intersection for x=viewdist */
	       y_scr=ay*viewdist+by;
	       z_scr=az*viewdist+bz;

	       /* Replace coordinates */
          if (flt1.x < flt2.x) {
	          sx1=xcenter-y_scr*xpixpermeter;
	          sy1=ycenter-z_scr*ypixpermeter;
          }
	       else {
	          sx2=xcenter-y_scr*xpixpermeter;
	          sy2=ycenter-z_scr*ypixpermeter;
          }
       }
 } /* endelse */

 result.first.x=sx1;
 result.first.y=sy1;
 result.first.z=status1;
 result.last.x =sx2;
 result.last.y =sy2;
 result.last.z =status2;

 /* Contains coordinates except when result.first.z=result.last.z=-2 */
 return(result);
}



linecoord calc_line_project(cartvektor p1, cartvektor p2)
/* Calculate projected screen coordinates of end points of a 3D-line */
{
 cartvektor xyz1,xyz2,flt1,flt2;
 float sx1=0,sy1=0,sx2=0,sy2=0,status1=0,status2=0;
 float xpixpermeter=xpixels/scrnwidth;
 float ypixpermeter=ypixels/scrnheight;
 float ay,by,az,bz;
 linecoord result;

 xyz1.x=p1.x-viewx;
 xyz1.y=p1.y-viewy;
 xyz1.z=p1.z-viewz;
 xyz2.x=p2.x-viewx;
 xyz2.y=p2.y-viewy;
 xyz2.z=p2.z-viewz;

 /* Representation in top,front,left coordinates */
 flt1.x=VPRIK(xyz1,viewfront);
 flt1.y=VPRIK(xyz1,viewleft);
 flt1.z=VPRIK(xyz1,viewtop);
 flt2.x=VPRIK(xyz2,viewfront);
 flt2.y=VPRIK(xyz2,viewleft);
 flt2.z=VPRIK(xyz2,viewtop);

 /* Statis= 0 if point is on screen */
 /* Status=-3 if one point behind observer */
 /* Status=-2 if both points behind observer */

 if (flt1.x<viewdist) status1=-3;

 if (flt2.x<viewdist) status2=-3;

 if (flt1.x<viewdist && flt2.x<viewdist)
    status1=status2=-2;
 else {
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
	          sy1=ycenter-z_scr*ypixpermeter;
          }
	       else {
	          sx2=xcenter-y_scr*xpixpermeter;
	          sy2=ycenter-z_scr*ypixpermeter;
          }
       }
 } /* endelse */

 result.first.x=sx1;
 result.first.y=sy1;
 result.first.z=status1;
 result.last.x =sx2;
 result.last.y =sy2;
 result.last.z =status2;

 /* Contains coordinates except when result.first.z=result.last.z=-2 */
 return(result);
}



screenlinecoord calc_frame_line(linecoord linec,float xpixels, float ypixels)
/* Interpolates line-coordinates to edge of screen, if outside */
/* and returns coordinates */
/* float xpixels and ypixels parameters seems to be faster than global int's */
{
 float ay,by,tx,ty;
 float x1=linec.first.x;
 float y1=linec.first.y;
 float x2=linec.last.x;
 float y2=linec.last.y;
 int   status1=linec.first.z;
 int   status2=linec.last.z;
 int   swap=1;
 int   cross_sgn=0;        /* Sign of point on line crossing (x=*,y=ypixels/2) */
 screenlinecoord line_frame;

 /* Determine on what side of x=xpixels/2 the line crosses y=ypixels/2 */
 /* cross_sgn = 0 : No crossing */
 /* cross_sgn =-1 : Left side   */
 /* cross_sgn = 1 : right side  */
 if (status1!=-2 && status2!=-2) {
      float cross;

      /* Express line as y=ay*x+by and x=(y-by)/ay */
      if (x2==x1) x2+=0.1; /* Avoid div. by 0 */
      if (y2==y1) y2+=0.1; /* Avoid div. by 0 */
      ay=(y2-y1)/(x2-x1);
      by=y1-ay*x1;

      /* find x-coordinate of crossing */
      cross = ( ypixels/2 - by ) / ay;

      if ( (cross < x1 && cross < x2) || ( cross > x1 && cross > x2) ) {
       /* crossing point is outside end of line points */
       cross_sgn=0;
      }
      else {
       if ( cross > xpixels/2) cross_sgn=1;
       else cross_sgn=-1;
      }

 }

 if (status1!=-2){
          if ( (x1<0) || (x1>xpixels) ||
               (y1<0) || (y1>ypixels) )
               status1=-1;
          else status1=0;
 }

 if (status2!=-2){
          if ( (x2<0) || (x2>xpixels) ||
               (y2<0) || (y2>ypixels) )
               status2=-1;
          else status2=0;
 }

 /* This only detects a fraction of the lines outside the screen */
 if ((x1 < 0       && x2 < 0      ) ||
     (x1 > xpixels && x2 > xpixels) ||
     (y1 < 0       && y2 < 0      ) ||
     (y1 > ypixels && y2 > ypixels))
         status1=status2=-2;
 else { /* status1!=-2 */
      /* Express line as y=ay*x+by and x=(y-by)/ay */
      if (x2==x1) x2+=0.1; /* Avoid div. by 0 */
      ay=(y2-y1)/(x2-x1);
      by=y1-ay*x1;

      /* 'sort' points by X */
      if (x1 > x2) {
      tx=x1; ty=y1;
      x1=x2; y1=y2;
      x2=tx; y2=ty;
      swap=-swap;
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
      swap=-swap;
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

      /* Restore order */
      if (swap < 0) {
      tx=x1; ty=y1;
      x1=x2; y1=y2;
      x2=tx; y2=ty;
      }

 } /* endelse */

 if ( (x1>0) && (x1<xpixels) && (y1>0) && (y1<ypixels) ) status1=0;
 if ( (x2>0) && (x2<xpixels) && (y2>0) && (y2<ypixels) ) status2=0;

 if ((x1<0) || (y1<0) || (x2<0) || (y2<0) ||
     (x1>xpixels) || (y1>ypixels) || (x2>xpixels) || (y2>ypixels))
      status1=status2=-2;

 line_frame.first.x      = x1;
 line_frame.first.y      = y1;
 line_frame.last.x       = x2;
 line_frame.last.y       = y2;
 line_frame.first.status = status1;
 line_frame.last.status  = status2;
 line_frame.cross_sgn    = cross_sgn;

 return(line_frame);
}



void local_filled_poly_to_queue(polygon_struct *flade, int id, cartvektor pos, float light, ori_vector orient)
/* This version does not use global coordinates in order to avoid
   lack of precision of floating point representation */
{
 int j;                             /* Counts through vertices */
 poly_scrcoord poly_result;         /* Holds info on projected polygon */
 bool          drawit = false;      /* Should we draw at all? */
 cartvektor    coord3d[maxnedges];  /* 3D coordinates of vertices */
 bool          lastok  = true;      /* Last point outside screen? */
 int           nokpts = 0;          /* points in projected polygon */
 int           n_crossings = 0;
 int           cross_sgn = 1;
 bool controls = false;

 if (id >= maxnobjects ) {
  controls=true;
  id -= maxnobjects;
 }

 poly_result.color=flade->color;
 poly_result.dist=0;

 /* Find 3D-coordinates of vertices and average distance of polygon */
 for (j=0; j<flade->nedges; j++) {
     int v = flade->edge[j];

     if (!controls)
        coord3d[j]=rot_to_plane(*(object[id].vertex+v));
     else
        coord3d[j]=rot_to_plane(ctrl_vertex[j]);

     poly_result.dist+=sqrt(SQR(coord3d[j].x-pos.x)+SQR(coord3d[j].y-pos.y)+SQR(coord3d[j].z-pos.z));

  /* Now coord3d is relative to aircraft center, but in world x,y,z
     orientation in stead if local orientation.
     That seems like a waste of time */
 }

 poly_result.dist/=flade->nedges;

 for (j=0; j<flade->nedges; j++) {
     int       j2=(j+1) % flade->nedges;
     /* j,j2 holds indices of vertices in line to be evaluated */
     linecoord       proj_coords;       /* Line coords projected onto screen */
     screenlinecoord frame_proj_coords; /* Line coords framed by screen */

     proj_coords=local_calc_line_project(vminus(coord3d[j],pos),vminus(coord3d[j2],pos));

     frame_proj_coords=calc_frame_line(proj_coords,xpixels,ypixels);

     if (frame_proj_coords.cross_sgn!=0) {
        n_crossings++;
        cross_sgn *= frame_proj_coords.cross_sgn;
     }

     if ((frame_proj_coords.first.status!=-2) && (frame_proj_coords.last.status!=-2)) {/* Line is on screen */
      if (j==0) {
         /* Put very first point in list */

         poly_result.scr_coords[nokpts*2]   = frame_proj_coords.first.x;
         poly_result.scr_coords[nokpts*2+1] = frame_proj_coords.first.y;
         nokpts++;
      }
      else {/* j!=0 */
           if (lastok==false){

              if (nokpts>0){
                 /* Draw along edge of screen to first point of line */
                 /* list corner coordinates in right-hand order */

                 int corn[4][2];
                 int firstedge=-1,lastedge=-1,i=0;

                 corn[0][0]=0;       corn[0][1]=0;
                 corn[1][0]=0;       corn[1][1]=ypixels;
                 corn[2][0]=xpixels; corn[2][1]=ypixels;
                 corn[3][0]=xpixels; corn[3][1]=0;

                 /* find edge of contact for previous point */
                 if (poly_result.scr_coords[(nokpts-1)*2+1]<1)          firstedge=0; /* upper */
                 if (poly_result.scr_coords[(nokpts-1)*2]  <1)          firstedge=1; /* left */
                 if (poly_result.scr_coords[(nokpts-1)*2+1]>ypixels-1)  firstedge=2; /* lower */
                 if (poly_result.scr_coords[(nokpts-1)*2]  >xpixels-1)  firstedge=3; /* right */
                 /* find edge of contact for next point */
                 {
                  int besterr=1000;
                  int newerr;

                  newerr=abs(frame_proj_coords.first.y);
                  if (newerr < besterr) {
                     besterr=newerr;
                     lastedge=0;
                  }
                  newerr=abs(frame_proj_coords.first.x);
                  if (newerr < besterr) {
                     besterr=newerr;
                     lastedge=1;
                  }
                  newerr=abs(frame_proj_coords.first.y-ypixels);
                  if (newerr < besterr) {
                     besterr=newerr;
                     lastedge=2;
                  }
                  newerr=abs(frame_proj_coords.first.x-xpixels);
                  if (newerr < besterr) {
                     besterr=newerr;
                     lastedge=3;
                  }
                 }


                 i=firstedge;
                 while (i!=lastedge) {

                   poly_result.scr_coords[nokpts*2]   = corn[i][0];
                   poly_result.scr_coords[nokpts*2+1] = corn[i][1];
                   nokpts++;
                   i++;
                   i=i % 4;
                 }
              } /* endif (nokpts>0) */


           poly_result.scr_coords[nokpts*2]   = frame_proj_coords.first.x;
           poly_result.scr_coords[nokpts*2+1] = frame_proj_coords.first.y;
           nokpts++;
           } /* endif (lastok==false) */
      } /* endelse: j!=0 */
      /* Put last point of line in list */

      poly_result.scr_coords[nokpts*2]   = frame_proj_coords.last.x;
      poly_result.scr_coords[nokpts*2+1] = frame_proj_coords.last.y;
      nokpts++;

     } /* endif (frame_proj_coords.first.status!=-2) */
     if (frame_proj_coords.last.status!=0) lastok=false;
     else lastok=true;

 } /* endfor */

 /* If very first point was not placed, draw along edge from end to start */
 if ((lastok==false) && (nokpts>0)) {
                 /* Draw along edge of screen to first point of line */
                 /* list corner coordinates in right-hand order */
                 int corn[4][2];
                 int firstedge=-1,lastedge=-1,i=0;

                 corn[0][0]=0;       corn[0][1]=0;
                 corn[1][0]=0;       corn[1][1]=ypixels;
                 corn[2][0]=xpixels; corn[2][1]=ypixels;
                 corn[3][0]=xpixels; corn[3][1]=0;

                 /* find edge of contact for previous point */
                 if (poly_result.scr_coords[(nokpts-1)*2+1]<1)          firstedge=0; /* upper */
                 if (poly_result.scr_coords[(nokpts-1)*2]  <1)          firstedge=1; /* left */
                 if (poly_result.scr_coords[(nokpts-1)*2+1]>ypixels-1)  firstedge=2; /* lower */
                 if (poly_result.scr_coords[(nokpts-1)*2]  >xpixels-1)  firstedge=3; /* right */
                 /* find edge of contact for very first point */
                 {
                  int besterr=1000;
                  int newerr;

                  newerr=abs(poly_result.scr_coords[1]);
                  if (newerr < besterr) {
                     besterr=newerr;
                     lastedge=0;
                  }
                  newerr=abs(poly_result.scr_coords[0]);
                  if (newerr < besterr) {
                     besterr=newerr;
                     lastedge=1;
                  }
                  newerr=abs(poly_result.scr_coords[1]-ypixels);
                  if (newerr < besterr) {
                     besterr=newerr;
                     lastedge=2;
                  }
                  newerr=abs(poly_result.scr_coords[0]-xpixels);
                  if (newerr < besterr) {
                     besterr=newerr;
                     lastedge=3;
                  }
                 }

                 i=firstedge;
                 while (i!=lastedge) {

                   poly_result.scr_coords[nokpts*2]   = corn[i][0];
                   poly_result.scr_coords[nokpts*2+1] = corn[i][1];
                   nokpts++;
                   i++;
                   i=i % 4;
                 } ;
 }

 if (nokpts>2) drawit=true;

 if ( (nokpts==0) && (n_crossings==2 && cross_sgn==-1) ) {
    poly_result.scr_coords[0] = 0;
    poly_result.scr_coords[1] = 0;
    poly_result.scr_coords[2] = 0;
    poly_result.scr_coords[3] = ypixels;
    poly_result.scr_coords[4] = xpixels;
    poly_result.scr_coords[5] = ypixels;
    poly_result.scr_coords[6] = xpixels;
    poly_result.scr_coords[7] = 0;
    nokpts=4;
    drawit=true;
 }

 if (drawit==true) {
    poly_result.nedges=nokpts;
    /* Determine shading of polygon */
    if (many_colors==false) {
       poly_result.fill=0;
       if (light > -0.60) poly_result.fill=1;
       if (light > -0.40) poly_result.fill=2;
       if (light >  0.20) poly_result.fill=3;
       if (light >  0.00) poly_result.fill=4;
    }
    else {
     poly_result.fill=(1-light)*8;
    }

    /* Add polygon to queue */
    poly_queue[poly_queue_length]=poly_result;
    poly_queue_length++;

    /* Draw if queue is full */
    if (poly_queue_length==max_poly_queue_length) {
       sort_poly_queue();
       draw_poly_queue();
    }  /* endif */
 }     /* endif */

}




void filled_poly_to_queue(polygon_struct *flade, int id, cartvektor pos, float light, ori_vector orient)
{
 int j;                             /* Counts through vertices */
 poly_scrcoord poly_result;         /* Holds info on projected polygon */
 bool          drawit = false;      /* Should we draw at all? */
 cartvektor    coord3d[maxnedges];  /* 3D coordinates of vertices */
 bool          lastok  = true;      /* Last point outside screen? */
 int           nokpts = 0;          /* points in projected polygon */
 int           n_crossings = 0;
 int           cross_sgn = 1;
 bool controls = false;

 #ifdef TIMESTAT
   clock_start(5);
 #endif

 if (id >= maxnobjects ) {
  controls=true;
  id -= maxnobjects;
 }

 poly_result.color=flade->color;
 poly_result.dist=0;

 /* Find 3D-coordinates of vertices and average distance of polygon */
 #ifdef TIMESTAT
    clock_start(11);
 #endif
 for (j=0; j<flade->nedges; j++) {
     int v = flade->edge[j];
     if (id == poly_plane_id[current_model] || id == cockpit_id[current_model] || ( (poly_plane_id[current_model] == LM) && (id == LM_ASCENT) ) )
        if (!controls)
           coord3d[j]=vplus(pos,rot_to_plane(*(object[id].vertex+v)));
        else
           coord3d[j]=vplus(pos,rot_to_plane(ctrl_vertex[j]));
     else {
        if (orient.rot) coord3d[j]=vplus(pos,rot_edge(*(object[id].vertex+v),orient));
        else coord3d[j]=vplus(pos,*(object[id].vertex+v));
     }

     poly_result.dist+=sqrt(SQR(coord3d[j].x-viewx)+SQR(coord3d[j].y-viewy)+SQR(coord3d[j].z-viewz));
 }

 poly_result.dist/=flade->nedges;

 #ifdef TIMESTAT
    clock_stop(11);
 #endif

 for (j=0; j<flade->nedges; j++) {
     int       j2=(j+1) % flade->nedges;
     /* j,j2 holds indices of vertices in line to be evaluated */
     linecoord       proj_coords;       /* Line coords projected onto screen */
     screenlinecoord frame_proj_coords; /* Line coords framed by screen */

     #ifdef TIMESTAT
       clock_start(9);
     #endif
     proj_coords=calc_line_project(coord3d[j],coord3d[j2]);
     #ifdef TIMESTAT
       clock_stop(9);
     #endif
     #ifdef TIMESTAT
       clock_start(10);
     #endif
     frame_proj_coords=calc_frame_line(proj_coords,xpixels,ypixels);
     if (frame_proj_coords.cross_sgn!=0) {
        n_crossings++;
        cross_sgn *= frame_proj_coords.cross_sgn;
     }

     #ifdef TIMESTAT
        clock_stop(10);
     #endif

     #ifdef TIMESTAT
       clock_start(12);
     #endif

     if ((frame_proj_coords.first.status!=-2) && (frame_proj_coords.last.status!=-2)) {/* Line is on screen */
      if (j==0) {
         /* Put very first point in list */

         poly_result.scr_coords[nokpts*2]   = frame_proj_coords.first.x;
         poly_result.scr_coords[nokpts*2+1] = frame_proj_coords.first.y;
         nokpts++;
      }
      else {/* j!=0 */
           if (lastok==false){

              if (nokpts>0){
                 /* Draw along edge of screen to first point of line */
                 /* list corner coordinates in right-hand order */

                 int corn[4][2];
                 int firstedge=-1,lastedge=-1,i=0;

                 corn[0][0]=0;       corn[0][1]=0;
                 corn[1][0]=0;       corn[1][1]=ypixels;
                 corn[2][0]=xpixels; corn[2][1]=ypixels;
                 corn[3][0]=xpixels; corn[3][1]=0;

                 /* find edge of contact for previous point */
                 if (poly_result.scr_coords[(nokpts-1)*2+1]<1)          firstedge=0; /* upper */
                 if (poly_result.scr_coords[(nokpts-1)*2]  <1)          firstedge=1; /* left */
                 if (poly_result.scr_coords[(nokpts-1)*2+1]>ypixels-1)  firstedge=2; /* lower */
                 if (poly_result.scr_coords[(nokpts-1)*2]  >xpixels-1)  firstedge=3; /* right */
                 /* find edge of contact for next point */
                 /*if (frame_proj_coords.first.y<1)          lastedge=0;*/ /* upper */
                 /*if (frame_proj_coords.first.x<1)          lastedge=1;*/ /* left */
                 /*if (frame_proj_coords.first.y>ypixels-1)  lastedge=2;*/ /* lower */
                 /*if (frame_proj_coords.first.x>xpixels-1)  lastedge=3;*/ /* right */
                 /* Because the same point may be determined as being slightly */
                 /* inside the screen in one calculation and slightly outside  */
                 /* in the next, the following must be used in stead */
                 {
                  int besterr=1000;
                  int newerr;

                  newerr=abs(frame_proj_coords.first.y);
                  if (newerr < besterr) {
                     besterr=newerr;
                     lastedge=0;
                  }
                  newerr=abs(frame_proj_coords.first.x);
                  if (newerr < besterr) {
                     besterr=newerr;
                     lastedge=1;
                  }
                  newerr=abs(frame_proj_coords.first.y-ypixels);
                  if (newerr < besterr) {
                     besterr=newerr;
                     lastedge=2;
                  }
                  newerr=abs(frame_proj_coords.first.x-xpixels);
                  if (newerr < besterr) {
                     besterr=newerr;
                     lastedge=3;
                  }
                 }


                 i=firstedge;
                 while (i!=lastedge) {

                   poly_result.scr_coords[nokpts*2]   = corn[i][0];
                   poly_result.scr_coords[nokpts*2+1] = corn[i][1];
                   nokpts++;
                   i++;
                   i=i % 4;
                 }
              } /* endif (nokpts>0) */


           poly_result.scr_coords[nokpts*2]   = frame_proj_coords.first.x;
           poly_result.scr_coords[nokpts*2+1] = frame_proj_coords.first.y;
           nokpts++;
           } /* endif (lastok==false) */
      } /* endelse: j!=0 */
      /* Put last point of line in list */

      poly_result.scr_coords[nokpts*2]   = frame_proj_coords.last.x;
      poly_result.scr_coords[nokpts*2+1] = frame_proj_coords.last.y;
      nokpts++;

     } /* endif (frame_proj_coords.first.status!=-2) */
     if (frame_proj_coords.last.status!=0) lastok=false;
     else lastok=true;

     #ifdef TIMESTAT
       clock_stop(12);
     #endif

 } /* endfor */

      #ifdef TIMESTAT
       clock_start(12);
     #endif

 /* If very first point was not placed, draw along edge from end to start */
 if ((lastok==false) && (nokpts>0)) {
                 /* Draw along edge of screen to first point of line */
                 /* list corner coordinates in right-hand order */
                 int corn[4][2];
                 int firstedge=-1,lastedge=-1,i=0;

                 corn[0][0]=0;       corn[0][1]=0;
                 corn[1][0]=0;       corn[1][1]=ypixels;
                 corn[2][0]=xpixels; corn[2][1]=ypixels;
                 corn[3][0]=xpixels; corn[3][1]=0;

                 /* find edge of contact for previous point */
                 if (poly_result.scr_coords[(nokpts-1)*2+1]<1)          firstedge=0; /* upper */
                 if (poly_result.scr_coords[(nokpts-1)*2]  <1)          firstedge=1; /* left */
                 if (poly_result.scr_coords[(nokpts-1)*2+1]>ypixels-1)  firstedge=2; /* lower */
                 if (poly_result.scr_coords[(nokpts-1)*2]  >xpixels-1)  firstedge=3; /* right */
                 /* find edge of contact for very first point */
                 /*if (poly_result.scr_coords[1]<1)          lastedge=0;*/ /* upper */
                 /*if (poly_result.scr_coords[0]<1)          lastedge=1;*/ /* left */
                 /*if (poly_result.scr_coords[1]>ypixels-1)  lastedge=2;*/ /* lower */
                 /*if (poly_result.scr_coords[0]>xpixels-1)  lastedge=3;*/ /* right */
                 /* Because the same point may be determined as being slightly */
                 /* inside the screen in one calculation and slightly outside  */
                 /* in the next, the following must be used in stead */
                 {
                  int besterr=1000;
                  int newerr;

                  newerr=abs(poly_result.scr_coords[1]);
                  if (newerr < besterr) {
                     besterr=newerr;
                     lastedge=0;
                  }
                  newerr=abs(poly_result.scr_coords[0]);
                  if (newerr < besterr) {
                     besterr=newerr;
                     lastedge=1;
                  }
                  newerr=abs(poly_result.scr_coords[1]-ypixels);
                  if (newerr < besterr) {
                     besterr=newerr;
                     lastedge=2;
                  }
                  newerr=abs(poly_result.scr_coords[0]-xpixels);
                  if (newerr < besterr) {
                     besterr=newerr;
                     lastedge=3;
                  }
                 }

                 i=firstedge;
                 while (i!=lastedge) {

                   poly_result.scr_coords[nokpts*2]   = corn[i][0];
                   poly_result.scr_coords[nokpts*2+1] = corn[i][1];
                   nokpts++;
                   i++;
                   i=i % 4;
                 } ;
 }
 #ifdef TIMESTAT
    clock_stop(12);
 #endif

 if (nokpts>2) drawit=true;

 if ( (nokpts==0) && (n_crossings==2 && cross_sgn==-1) ) {
    poly_result.scr_coords[0] = 0;
    poly_result.scr_coords[1] = 0;
    poly_result.scr_coords[2] = 0;
    poly_result.scr_coords[3] = ypixels;
    poly_result.scr_coords[4] = xpixels;
    poly_result.scr_coords[5] = ypixels;
    poly_result.scr_coords[6] = xpixels;
    poly_result.scr_coords[7] = 0;
    nokpts=4;
    drawit=true;
 }

 #ifdef TIMESTAT
   clock_stop(5);
 #endif

 if (drawit==true) {
    poly_result.nedges=nokpts;
    /* Determine shading of polygon */
    if (many_colors==false) {
       poly_result.fill=0;
       if (light > -0.60) poly_result.fill=1;
       if (light > -0.40) poly_result.fill=2;
       if (light >  0.20) poly_result.fill=3;
       if (light >  0.00) poly_result.fill=4;
    }
    else {
     poly_result.fill=(1-light)*8;
    }


    /* Add polygon to queue */
    poly_queue[poly_queue_length]=poly_result;
    poly_queue_length++;

    /* Draw if queue is full */
    if (poly_queue_length==max_poly_queue_length) {
       sort_poly_queue();
       draw_poly_queue();
    }  /* endif */
 }     /* endif */

}



void map_to_poly_queue(cartvektor va, cartvektor vb, cartvektor vc, float light, int color)
/* Places calculated vertices into an object and puts it onto the z-queue */
{

 cartvektor pos;
 ori_vector orient;

 orient.rot=false;

 pos.x=0;
 pos.y=0;
 pos.z=0;

 /* map-triangle */
 (object[MAP].vertex+0)->x=    va.x;
 (object[MAP].vertex+0)->y=    va.y;
 (object[MAP].vertex+0)->z=    va.z;

 (object[MAP].vertex+1)->x=    vb.x;
 (object[MAP].vertex+1)->y=    vb.y;
 (object[MAP].vertex+1)->z=    vb.z;

 (object[MAP].vertex+2)->x=    vc.x;
 (object[MAP].vertex+2)->y=    vc.y;
 (object[MAP].vertex+2)->z=    vc.z;

 object[MAP].facet->color =   color;

 filled_poly_to_queue(object[MAP].facet, MAP, pos, light, orient);
}



void move_sun()
{
	cartvektor temp;
	int i;
	extern float sun_hour, latitude;
	
	float cos_sun_hour = cos(sun_hour);
	float sin_sun_hour = sin(sun_hour);
	float cos_latitude = cos(-latitude);
	float sin_latitude = sin(-latitude);

	// First rotate hour-angle, i.e. around n-s axis
	for (i=0; i<8; i++){
		temp.y =  (object[SUN].vertex+i)->y * cos_sun_hour + (object[SUN].vertex+i)->z * sin_sun_hour;
		temp.z = -(object[SUN].vertex+i)->y * sin_sun_hour + (object[SUN].vertex+i)->z * cos_sun_hour;
        (object[SUN].vertex+i)->y = temp.y;
		(object[SUN].vertex+i)->z = temp.z;
	}

	// Then rotate according to geographic latitude, i.e. around e-w axis
	for (i=0; i<8; i++){
		temp.x =  (object[SUN].vertex+i)->x * cos_latitude + (object[SUN].vertex+i)->z * sin_latitude;
		temp.z = -(object[SUN].vertex+i)->x * sin_latitude + (object[SUN].vertex+i)->z * cos_latitude;
        (object[SUN].vertex+i)->x = temp.x;
		(object[SUN].vertex+i)->z = temp.z;
	}



}



void update_lightvector()
{
	float norm;
	extern cartvektor sun;

	sun.x = (object[SUN].vertex+0)->x;
	sun.y = (object[SUN].vertex+0)->y;
	sun.z = (object[SUN].vertex+0)->z;

	norm = sqrt(VPRIK(sun,sun));
	sun  = svmult( -1/norm, sun);
}



void sun_to_poly_queue()
/* Places calculated vertices into an object and puts it onto the z-queue */
{

 cartvektor pos;
 ori_vector orient;
 int i;

 orient.rot=false;

 pos.x=viewx;
 pos.y=viewy;
 pos.z=viewz;

 for (i=0; i<8; i++){
  float xc=0.0, yc=100.0, zc=0.0, radius=0.47; // Angular diameter: 0.53 degree

  (object[SUN].vertex+i)->x=xc-radius*sin(i*PI/4+PI/8);
  (object[SUN].vertex+i)->y=yc;
  (object[SUN].vertex+i)->z=zc+radius*cos(i*PI/4+PI/8);
 }

 object[SUN].facet->color =   -WHITE;

 move_sun();

 filled_poly_to_queue(object[SUN].facet, SUN, pos, 1.0, orient);
}



void filled_horizon()
{
 float nfx,nfy,normfak,dyb,bred;
 cartvektor p1,p2;
 screenlinecoord p1p2cut;
 poly_scrcoord poly_result;
 int sky_color;

 if (many_colors)
    sky_color=SKY_BLUE; /* 175-8; */ /* CYAN */
 else
    sky_color=CYAN;

 if (groundtype==1) {
    horizon_color=LIGHTGRAY;
    if (many_colors) horizon_color=79-8; /* LIGHTGRAY */
 }

 /* normeret viewfront vektor projiceret paa x-y plan */
 normfak=sqrt(SQR(viewfront.x)+SQR(viewfront.y));
 if (normfak != 0){
  nfx=viewfront.x/normfak;
  nfy=viewfront.y/normfak;
  dyb=viewdist*1000;
  bred=scrnwidth*800;
  p1.x=viewx+nfx*dyb-bred*nfy;
  p1.y=viewy+nfy*dyb+bred*nfx;
  p1.z=viewz;
  p2.x=viewx+nfx*dyb+bred*nfy;
  p2.y=viewy+nfy*dyb-bred*nfx;
  p2.z=viewz;
  p1p2cut=calc_frame_line(calc_line_project(p1,p2),xpixels,ypixels);

  if (p1p2cut.first.status!=-2){
     int corn[4][2];
     int firstedge=-1,lastedge=-1,i=0, nokpts=1;

     corn[0][0]=0;       corn[0][1]=0;
     corn[1][0]=0;       corn[1][1]=ypixels;
     corn[2][0]=xpixels; corn[2][1]=ypixels;
     corn[3][0]=xpixels; corn[3][1]=0;

     /* find edge of contact for first point */
     if (p1p2cut.first.y<1)          firstedge=0; /* upper */
     if (p1p2cut.first.x<1)          firstedge=1; /* left */
     if (p1p2cut.first.y>ypixels-1)  firstedge=2; /* lower */
     if (p1p2cut.first.x>xpixels-1)  firstedge=3; /* right */
     /* find edge of contact for last point */
     if (p1p2cut.last.y<1)          lastedge=0; /* upper */
     if (p1p2cut.last.x<1)          lastedge=1; /* left */
     if (p1p2cut.last.y>ypixels-1)  lastedge=2; /* lower */
     if (p1p2cut.last.x>xpixels-1)  lastedge=3; /* right */

     if (firstedge <0 || lastedge<0) {
        //closegraph();
        cprintf("You have encountered a bug in the horizon drawing routine!\n\r");
        errorexit(1);
     }

     poly_result.scr_coords[0]=p1p2cut.first.x;
     poly_result.scr_coords[1]=p1p2cut.first.y;

     i=firstedge;
     while (i!=lastedge) {
        poly_result.scr_coords[nokpts*2]   = corn[i][0];
        poly_result.scr_coords[nokpts*2+1] = corn[i][1];
        nokpts++;
        i++;
        i=i % 4;
     }
     poly_result.scr_coords[nokpts*2]   = p1p2cut.last.x;
     poly_result.scr_coords[nokpts*2+1] = p1p2cut.last.y;
     nokpts++;
     poly_result.nedges=nokpts;
     rectfill(active_page, 0,0,xpixels,ypixels, sky_color);
	 
     polygon(active_page, poly_result.nedges,poly_result.scr_coords, horizon_color);
	 
  }
  else { /* horizon outside screen */
     if (viewfront.z>0) {
       clear_to_color(active_page, sky_color);
     }
     else {
       clear_to_color(active_page, horizon_color);
     }
  }
 }
}



void draw_map_triangle(cartvektor va, cartvektor vb, cartvektor vc, float light, int color)
{
 poly_scrcoord poly_result;         /* Holds info on projected polygon */
 bool drawit=true;

 poly_result.color=color;
 poly_result.dist=0; /* Not to be Z-sorted */

 poly_result.scr_coords[0] = (va.x*xscl*MAP_SCALE)+xcenter;
 poly_result.scr_coords[1] = (va.y*yscl*MAP_SCALE)+ycenter;
 poly_result.scr_coords[2] = (vb.x*xscl*MAP_SCALE)+xcenter;
 poly_result.scr_coords[3] = (vb.y*yscl*MAP_SCALE)+ycenter;
 poly_result.scr_coords[4] = (vc.x*xscl*MAP_SCALE)+xcenter;
 poly_result.scr_coords[5] = (vc.y*yscl*MAP_SCALE)+ycenter;

  if (drawit==true) {
    poly_result.nedges=3;
    /* Determine shading of polygon */
    if (many_colors==false) {
       poly_result.fill=0;
       if (light > -0.60) poly_result.fill=1;
       if (light > -0.40) poly_result.fill=2;
       if (light >  0.20) poly_result.fill=3;
       if (light >  0.00) poly_result.fill=4;
    }
    else {
     poly_result.fill=(1-light)*8;
    }


    /* Add polygon to queue */
    poly_queue[poly_queue_length]=poly_result;
    poly_queue_length++;

    /* Draw if queue is full */
    if (poly_queue_length==max_poly_queue_length) {
       /* sort_poly_queue(); */
       draw_poly_queue();
    }  /* endif */
 }     /* endif */

}



void draw_map(float xorig, float yorig, float azimuth, int to_dist)
{
 #define poly_grid (mapsize-1)/2
 #define poly_mask 1000
 typedef struct {
         cartvektor pos;
         int        drawn;
         } mapvertex;
 float sx,sy;   /* Are float to avoid overflow */
 float ix,iy;
 int idx_x,idx_y,i;
 const int mapwidth=mapsize-1;
 int indx,indy;
 mapvertex poly_map[poly_grid*2+2][poly_grid*2+2];
 mapvertex light_map[poly_grid*2+2][poly_grid*2+2];
 float cosazi=cos(azimuth-PI/2);
 float sinazi=sin(azimuth-PI/2);

 extern int nwaypoints, active_waypoint;
 extern waypoint waypointlst[maxnwaypoints];
 extern short map_zoom;


 sort_poly_queue();
 draw_poly_queue();

 rectfill(active_page, 0,0,xpixels,ypixels, LIGHTGRAY);

 sx= (int) (viewx/poly_mask);
 sy= (int) (viewy/poly_mask);
 for (ix=sx-poly_grid; ix<sx+poly_grid+1; ix++) {
  for (iy=sy-poly_grid; iy<sy+poly_grid+1; iy++) {
   float posx,posy;
   idx_x=ix-sx+poly_grid;
   idx_y=iy-sy+poly_grid;
   indx=(int)ix % mapwidth;
   indy=(int)iy % mapwidth;
   if (indx < 0) indx+=mapwidth;
   if (indy < 0) indy+=mapwidth;
   posx=(ix*poly_mask-xorig)/((float)poly_mask*map_zoom);
   posy=-(iy*poly_mask-yorig)/((float)poly_mask*map_zoom);
   if (groundtype>0)
      poly_map[idx_x][idx_y].pos.z=map_vertex(indx,indy);
   else
      poly_map[idx_x][idx_y].pos.z=0;
   poly_map[idx_x][idx_y].pos.x=cosazi*posx-sinazi*posy;
   poly_map[idx_x][idx_y].pos.y=cosazi*posy+sinazi*posx;
   poly_map[idx_x][idx_y].drawn=0;
   if (groundtype>0)
      light_map[idx_x][idx_y].pos.z=map_vertex(indx,indy);
   else
      light_map[idx_x][idx_y].pos.z=0;
   light_map[idx_x][idx_y].pos.x=(float)ix*poly_mask;
   light_map[idx_x][idx_y].pos.y=(float)iy*poly_mask;
  }
 }

 for (idx_x=poly_grid-map_zoom; idx_x<poly_grid+map_zoom; idx_x++) {
  for (idx_y=poly_grid-map_zoom; idx_y<poly_grid+map_zoom; idx_y++) {
       float normfak,lighting;
       cartvektor edge1,edge2,normvector;
       short gnd_col;
       extern cartvektor sun;
       extern int poly_map_color(int h1, int h2, int h3);
       extern short find_ground_color(float lighting, float dist, short gnd_col);

       edge1=vminus(light_map[idx_x+1][idx_y].pos,light_map[idx_x][idx_y].pos);
       edge2=vminus(light_map[idx_x][idx_y+1].pos,light_map[idx_x][idx_y].pos);
       normvector=vkryds(edge1,edge2);

       normfak = sqrt(SQR(normvector.x)+SQR(normvector.y)+SQR(normvector.z));
       lighting=VPRIK(normvector,sun)/normfak;
       if (groundtype>0)
         gnd_col=poly_map_color(poly_map[idx_x][idx_y].pos.z,
                                poly_map[idx_x][idx_y+1].pos.z,
                                poly_map[idx_x+1][idx_y].pos.z);
       else
         gnd_col=GREEN;

       draw_map_triangle(poly_map[idx_x+1][idx_y].pos,
                         poly_map[idx_x][idx_y+1].pos,
                         poly_map[idx_x][idx_y].pos,
                         lighting,
                         find_ground_color(lighting,0,gnd_col)
                         );

       edge1=vminus(light_map[idx_x][idx_y+1].pos,light_map[idx_x+1][idx_y+1].pos);
       edge2=vminus(light_map[idx_x+1][idx_y].pos,light_map[idx_x+1][idx_y+1].pos);
       normvector=vkryds(edge1,edge2);

       normfak = sqrt(SQR(normvector.x)+SQR(normvector.y)+SQR(normvector.z));
       lighting=VPRIK(normvector,sun)/normfak;
       if (groundtype>0)
          gnd_col=poly_map_color(poly_map[idx_x+1][idx_y+1].pos.z,
                                 poly_map[idx_x][idx_y+1].pos.z,
                                 poly_map[idx_x+1][idx_y].pos.z);
       else
          gnd_col=GREEN;

       draw_map_triangle(poly_map[idx_x+1][idx_y+1].pos,
                         poly_map[idx_x][idx_y+1].pos,
                         poly_map[idx_x+1][idx_y].pos,
                         lighting+0.41,
                         find_ground_color(lighting+0.2,0,gnd_col)
                         );

  }
 }
 draw_poly_queue();

 /* Aircraft marker */
 line(active_page, xcenter,ycenter, xcenter+5*xscl,ycenter+10*yscl, YELLOW);
 line(active_page, xcenter,ycenter, xcenter-5*xscl,ycenter+10*yscl, YELLOW);

 for (i=0; i<nwaypoints; i++){
  float wx= (waypointlst[i].pos.x-xorig)/((float)poly_mask*map_zoom);
  float wy=-(waypointlst[i].pos.y-yorig)/((float)poly_mask*map_zoom);
  float wscrx,wscry;
  int wptcol;

  if ((fabs(wx)<1) && (fabs(wy)<1)) {
   wscrx=cosazi*wx-sinazi*wy;
   wscry=cosazi*wy+sinazi*wx;

   if (i==active_waypoint) wptcol=RED;
   else wptcol=YELLOW;

   line(active_page, 
   (wscrx*MAP_SCALE+4)*xscl+xcenter,wscry*yscl*MAP_SCALE+ycenter,
   (wscrx*MAP_SCALE-4)*xscl+xcenter,wscry*yscl*MAP_SCALE+ycenter, wptcol);
   line(active_page,
   wscrx*xscl*MAP_SCALE+xcenter,(wscry*MAP_SCALE+4)*yscl+ycenter,
   wscrx*xscl*MAP_SCALE+xcenter,(wscry*MAP_SCALE-4)*yscl+ycenter, wptcol);

   /*
   moveto((wscrx*MAP_SCALE+6)*xscl+xcenter,(wscry*MAP_SCALE-2)*yscl+ycenter);
   printg(i+1,2);

   moveto((wscrx*MAP_SCALE+20)*xscl+xcenter,(wscry*MAP_SCALE-2)*yscl+ycenter);
   outtext(waypointlst[i].ident);
   */
  }
 }
}



cartvektor rot_edge(cartvektor a, ori_vector orient)
{
 cartvektor b;

 b.x=0; b.y=0; b.z=0;
 b=vplus(b,svmult(a.x,orient.front));
 b=vplus(b,svmult(a.y,orient.left));
 b=vplus(b,svmult(a.z,orient.top));
 return(b);
}



void draw_rot_object(int id, cartvektor pos, ori_vector orient)
/* Draw an item of type object3D */
/* A convex closed surface will be drawn without hidden surfaces */
{
 /* In vertigo.c */
 extern cartvektor sun;
 extern void draw_vector(cartvektor a, cartvektor b, int color);
 extern float cos_diag;

 cartvektor view_to_obj;
 float distance=sqrt(SQR(pos.x-viewx)+SQR(pos.y-viewy)+SQR(pos.z-viewz));
 float normfak=1/distance;

 view_to_obj.x=pos.x-viewx;
 view_to_obj.y=pos.y-viewy;
 view_to_obj.z=pos.z-viewz;
 view_to_obj=svmult(normfak,view_to_obj);

 /* Is object visible? */
 if ( (distance < object[id].max_draw_dist) &&
      ( (VPRIK(view_to_obj,viewfront) > cos_diag) || (distance < object[id].always_draw_dist))) {

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

  /* roter her! */
  edge1=rot_edge(edge1,orient);
  edge2=rot_edge(edge2,orient);
  normvector=vkryds(edge1,edge2);
  /* view=vplus(pos,*(object[id].vertex+(object[id].facet+i)->edge[0])); */
  view=vplus(pos,rot_edge(*(object[id].vertex+(object[id].facet+i)->edge[0]),orient));
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



void draw_rot_line(cartvektor a, cartvektor b, cartvektor pos, ori_vector orient, int color, int vis_dist)
{
 /* In vertigo.c */
 extern void draw_vector(cartvektor a, cartvektor b, int color);
 extern float cos_diag;

 cartvektor view_to_obj;
 float distance=sqrt(SQR(pos.x-viewx)+SQR(pos.y-viewy)+SQR(pos.z-viewz));
 float normfak=1/distance;

 view_to_obj.x=pos.x-viewx;
 view_to_obj.y=pos.y-viewy;
 view_to_obj.z=pos.z-viewz;
 view_to_obj=svmult(normfak,view_to_obj);

 /* Is object visible? */
 if ( (distance < vis_dist) &&
      ( (VPRIK(view_to_obj,viewfront) > cos_diag) || (distance < 500))) {

 #ifdef TIMESTAT
   clock_start(8);
 #endif

   draw_vector(
   vplus(pos,rot_edge(a,orient)),
   vplus(pos,rot_edge(b,orient)), color);

 #ifdef TIMESTAT
   clock_stop(8);
 #endif
}
}




void draw_rot_point(cartvektor a, cartvektor pos, ori_vector orient, int color, int vis_dist, bool big, float yoffset)
{
 /* In vertigo.c */
 extern int point3d(cartvektor a, int color);
 extern float cos_diag;

 cartvektor view_to_obj;
 float distance=sqrt(SQR(pos.x-viewx)+SQR(pos.y-viewy)+SQR(pos.z-viewz));
 float normfak=1/distance;

 view_to_obj.x=pos.x-viewx;
 view_to_obj.y=pos.y-viewy;
 view_to_obj.z=pos.z-viewz;
 view_to_obj=svmult(normfak,view_to_obj);

 /* Make big blobs appear small at large distance */
 if (big && distance>vis_dist/2) big=false;

 /* Is object visible? */
 if ( (distance < vis_dist) &&
      ( (VPRIK(view_to_obj,viewfront) > cos_diag) || (distance < 1000))) {

 #ifdef TIMESTAT
   clock_start(8);
 #endif

   if (big == false) {
      if (orient.rot)
        point3d(vplus(pos,rot_edge(a,orient)),color);
      else
        point3d(vplus(pos,a),color);
   }
   else {
    extern cartvektor scrpos3d(cartvektor a);
    cartvektor scrpos;

    if (orient.rot)
       scrpos=scrpos3d(vplus(pos,rot_edge(a,orient)));
    else
       scrpos=scrpos3d(vplus(pos,a));

    if (scrpos.z==1) {
       scrpos.y -= yoffset;
       rectfill(active_page, scrpos.x-0.5,scrpos.y-0.5,scrpos.x+0.5,scrpos.y+0.5, color);
    }
   }

 #ifdef TIMESTAT
   clock_stop(8);
 #endif
}
}



cartvektor rot_ctrl_surface(float cos_angle, float sin_angle, cartvektor a, ctrl_srf surface)
{
 cartvektor b,c;

 /* Translate to center of rotation */
 a = vminus(a, surface.hinge);

 /* Write in basis of rotation axis */
 b.x = VPRIK(surface.front, a);
 b.y = VPRIK(surface.left,  a);
 b.z = VPRIK(surface.top,   a);

 /* Rotate */
 c.x = b.x;
 c.y = cos_angle*b.y - sin_angle*b.z;
 c.z = sin_angle*b.y + cos_angle*b.z;

 /* Write in original basis */
 b.x=0; b.y=0; b.z=0;
 b = vplus(b, svmult(c.x, surface.front));
 b = vplus(b, svmult(c.y, surface.left ));
 b = vplus(b, svmult(c.z, surface.top  ));

 /* Translate back to original position */
 b = vplus(b, surface.hinge);

 return(b);
}



void draw_ctrl_surfaces(int id)
{
 cartvektor pos,view;
 int i,j,k;
 cartvektor normvector,edge1,edge2;
 ori_vector orient;

 extern float x,y,z;
 extern cartvektor sun;
 extern float elevator, aileron, tail_rudder, flap;
 extern a_brake airbrake;
 extern undercarriage gear[maxngears+maxnhardpts+1];
 extern float stb_spoiler, port_spoiler;

 orient.rot=false;

 #ifdef TIMESTAT
   clock_start(6);
 #endif

 pos.x=x; pos.y=y; pos.z=z;

 for (i=0; i<object[id].nctrl_srf; i++) {
  float angle=0, cos_angle, sin_angle;
  bool hide = FALSE;

  if (object[id].ctrl_surface[i].brake_gain != 0 &&
      airbrake.out==0) hide=TRUE; /* May be a bad idea for e.g. an A-6 */

  if (object[id].ctrl_surface[i].gear_gain != 0) {
     if (gear[object[id].ctrl_surface[i].gear_id].down < 0.1 &&
     !(id==HARRIER && i > 8) /* Show Harrier's outboard gear always */
     ) hide=TRUE;
     else angle += (1-gear[object[id].ctrl_surface[i].gear_id].down) *
                   object[id].ctrl_surface[i].gear_gain;
  }

  if (id==F14) {
    if (i==6) {
      if (port_spoiler > 0)
         angle = 55 * port_spoiler;
      else
         hide=TRUE;
    }
    if (i==7) {
      if (stb_spoiler > 0)
         angle = 55 * stb_spoiler;
      else
         hide=TRUE;
    }
  }

  if (!hide){

  /* Calculate rotation angle */
  angle   +=object[id].ctrl_surface[i].aileron_gain * aileron
           +object[id].ctrl_surface[i].elevator_gain * elevator
           +object[id].ctrl_surface[i].flap_gain * flap
           +object[id].ctrl_surface[i].rudder_gain * tail_rudder
           +object[id].ctrl_surface[i].brake_gain * airbrake.out;


  angle *= PI/180.;
  /* save a little time: */
  cos_angle=cos(angle);
  sin_angle=sin(angle);


  for (j=0; j<object[id].ctrl_surface[i].nctrlpoly; j++) {
   int poly_id=object[id].ctrl_surface[i].poly_id[j];
   int nver;

   /* Make copy of polygon */
   ctrl_poly=*(object[id].facet+poly_id);
   for (nver=0; nver<ctrl_poly.nedges; nver++)
       ctrl_vertex[nver]=*(object[id].vertex+(object[id].facet+poly_id)->edge[nver]);

   /* Rotate vertices */
   for (nver=0; nver<ctrl_poly.nedges; nver++)
       ctrl_vertex[nver]=rot_ctrl_surface(cos_angle,sin_angle,ctrl_vertex[nver],object[id].ctrl_surface[i]);

   edge1=vminus(ctrl_vertex[1],ctrl_vertex[0]);

   k=2;
   if (k==ctrl_poly.nedges) k=0;
   edge2=vminus(ctrl_vertex[k],ctrl_vertex[1]);

   edge1=rot_to_plane(edge1);
   edge2=rot_to_plane(edge2);
   normvector=vkryds(edge1,edge2);
   view=vplus(pos,rot_to_plane(ctrl_vertex[0]));
   view.x-=viewx;
   view.y-=viewy;
   view.z-=viewz;

   if (VPRIK(normvector,view) < 0) {
     float normfak = sqrt(SQR(normvector.x)+SQR(normvector.y)+SQR(normvector.z));
     float lighting=VPRIK(normvector,sun)/normfak;
      #ifdef TIMESTAT
         clock_stop(6);
      #endif
     filled_poly_to_queue(&ctrl_poly, id+maxnobjects, pos, lighting, orient);
     /*         Signal control surface   ^^^^^^^^^^^ */
      #ifdef TIMESTAT
        clock_start(6);
      #endif
   }
  } /* nctrlpoly */
  } /* hide */
 }  /* nctrl_surf */

 #ifdef TIMESTAT
   clock_stop(6);
 #endif
}



void init_prop_graph()
{
 int i;

 for (i=0; i<PROPSEGMENTS; i++) {
     prop_seg_x[i]=cos(2*PI*i/(float)PROPSEGMENTS);
     prop_seg_y[i]=sin(2*PI*i/(float)PROPSEGMENTS);
 }
}



void draw_propellers()
{
 extern float x,y,z;
 extern short      npropengines;
 extern propengine pengine[maxnpropengines+1];
 extern void draw_vector(cartvektor a, cartvektor b, int color);
 int i;

 for (i=0; i<npropengines; i++) {
  int j;
  cartvektor perif_pos[PROPSEGMENTS];

  for (j=0; j<PROPSEGMENTS; j++) {
    perif_pos[j]=pengine[i].spinnerloc;
    perif_pos[j].y += prop_seg_x[j]*pengine[i].radius;
    perif_pos[j].z += prop_seg_y[j]*pengine[i].radius;
    perif_pos[j]=rot_to_plane(perif_pos[j]);
    perif_pos[j].x += x;
    perif_pos[j].y += y;
    perif_pos[j].z += z;
  }
  for (j=0; j<PROPSEGMENTS; j++) {
    int next=j+1;

    if (rand() % 4==0) {
       if (next==PROPSEGMENTS) next=0;
       draw_vector(perif_pos[j],perif_pos[next], GRAY_SHADE);
    }
  }
 }
}



void init_airfield_lights()
{
 int i;

 /* side */
 for (i=0; i<16; i++){
  float xc=-750+100*i;

  lightlist[i].pos.x    =    xc;
  lightlist[i].pos.y    =  20.0;
  lightlist[i].pos.z    =   0.0;
  lightlist[i].color    = WHITE;
  lightlist[i].bright   =  true;
  lightlist[i].showdist =  6000;
 }

 for (i=0; i<16; i++){
  float xc=-750+100*i;

  lightlist[i+16].pos.x    =    xc;
  lightlist[i+16].pos.y    = -20.0;
  lightlist[i+16].pos.z    =   0.0;
  lightlist[i+16].color    = WHITE;
  lightlist[i+16].bright   =  true;
  lightlist[i+16].showdist =  6000;
 }

 lightlist[32].pos.x    =1200-1850;
 lightlist[32].pos.y    =       50;
 lightlist[32].pos.z    =     15.0;
 lightlist[32].color    = LIGHTRED;
 lightlist[32].bright   =     true;
 lightlist[32].showdist =     4000;


 for (i=0; i<3; i++){
  float yc=20+50*i;

  lightlist[i+33].pos.x    =      720;
  lightlist[i+33].pos.y    =       yc;
  lightlist[i+33].pos.z    =      0.0;
  lightlist[i+33].color    =LIGHTBLUE;
  lightlist[i+33].bright   =    false;
  lightlist[i+33].showdist =     3000;
 }

 for (i=0; i<3; i++){
  float yc=20+50*i;

  lightlist[i+36].pos.x    =     -720;
  lightlist[i+36].pos.y    =       yc;
  lightlist[i+36].pos.z    =      0.0;
  lightlist[i+36].color    =LIGHTBLUE;
  lightlist[i+36].bright   =    false;
  lightlist[i+36].showdist =     3000;
 }

 for (i=0; i<29; i++){
  float xc=-700+50*i;

  lightlist[i+39].pos.x    =       xc;
  lightlist[i+39].pos.y    =      100;
  lightlist[i+39].pos.z    =      0.0;
  lightlist[i+39].color    =LIGHTBLUE;
  lightlist[i+39].bright   =    false;
  lightlist[i+39].showdist =     3000;
 }

 for (i=0; i<18; i++){
  float xc=-700+50*i;

  lightlist[i+68].pos.x    =       xc;
  lightlist[i+68].pos.y    =      120;
  lightlist[i+68].pos.z    =      0.0;
  lightlist[i+68].color    =LIGHTBLUE;
  lightlist[i+68].bright   =    false;
  lightlist[i+68].showdist =     3000;
 }

 for (i=0; i<8; i++){
  float xc=350+50*i;

  lightlist[i+86].pos.x    =       xc;
  lightlist[i+86].pos.y    =      120;
  lightlist[i+86].pos.z    =      0.0;
  lightlist[i+86].color    =LIGHTBLUE;
  lightlist[i+86].bright   =    false;
  lightlist[i+86].showdist =     3000;
 }

 for (i=0; i<2; i++){
  float yc=20+50*i;

  lightlist[i+94].pos.x    =      700;
  lightlist[i+94].pos.y    =       yc;
  lightlist[i+94].pos.z    =      0.0;
  lightlist[i+94].color    =LIGHTBLUE;
  lightlist[i+94].bright   =    false;
  lightlist[i+94].showdist =     2000;
 }

 for (i=0; i<2; i++){
  float yc=20+50*i;

  lightlist[i+96].pos.x    =     -700;
  lightlist[i+96].pos.y    =       yc;
  lightlist[i+96].pos.z    =      0.0;
  lightlist[i+96].color    =LIGHTBLUE;
  lightlist[i+96].bright   =    false;
  lightlist[i+96].showdist =     2000;
 }

 lightlist[98].pos.x    =1300-1850;
 lightlist[98].pos.y    =       40;
 lightlist[98].pos.z    =      7.0;
 lightlist[98].color    = LIGHTRED;
 lightlist[98].bright   =     true;
 lightlist[98].showdist =     3000;
}



void draw_airfield_lights()
{
 int i;
 cartvektor airfield_pos;
 ori_vector airfield_orient;

 extern int airfieldalt;

 airfield_pos.x =        1850;
 airfield_pos.y =           0;
 airfield_pos.z = airfieldalt;

 airfield_orient.rot = false;

 for (i=0; i<NAIRFIELDLIGHTS; i++){
     draw_rot_point(lightlist[i].pos,airfield_pos,airfield_orient,
                    lightlist[i].color,lightlist[i].showdist,
                    lightlist[i].bright,0);
 }
}



int point_vect(cartvektor vect, int color)
/* Draws in absolute direction */
{
 cartvektor flt1;
 float sx1,sy1;
 float xpixpermeter=xpixels/(scrnwidth);
 float ypixpermeter=ypixels/(scrnheight);

 float xborder=scrnwidth/(2*viewdist); /* cm -> m */
 float yborder=scrnheight/(2*viewdist);

 /* Representation in top,front,left coordinates */
 flt1.x=VPRIK(vect,viewfront);   
 flt1.y=VPRIK(vect,viewleft);
 flt1.z=VPRIK(vect,viewtop);

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



void update_windbag()
{
 extern cartvektor wind;
 extern float wind_speed;
 int i;
 float vnx, vny;

 if (wind_speed > 0) {
    vnx = -wind.x/wind_speed;
    vny = -wind.y/wind_speed;
 }
 else {
    vnx = 1;
    vny = 0;
 }



 for (i=0; i<6; i++) {
  float hoej  = 6;
  float rad   = 0.5-0.05*i;
  float lng   = 0.5+0.8*i;
  float flyth = 0;

  if (i==0) lng = -0.5;

  if (i > 1 ) {
     flyth=-0.8*(i-1)*(1-wind_speed/10);
     if (wind_speed > 10) flyth = 0;

     lng += flyth;
  }

  (object[WINDBAG].vertex+0+i*4)->x= lng*vnx;
  (object[WINDBAG].vertex+0+i*4)->y= lng*vny;
  (object[WINDBAG].vertex+0+i*4)->z= hoej + rad + flyth;

  (object[WINDBAG].vertex+1+i*4)->x= lng*vnx - rad*vny;
  (object[WINDBAG].vertex+1+i*4)->y= lng*vny + rad*vnx;
  (object[WINDBAG].vertex+1+i*4)->z= hoej + flyth;

  (object[WINDBAG].vertex+2+i*4)->x= lng*vnx;
  (object[WINDBAG].vertex+2+i*4)->y= lng*vny;
  (object[WINDBAG].vertex+2+i*4)->z= hoej - rad + flyth;

  (object[WINDBAG].vertex+3+i*4)->x= lng*vnx + rad*vny;
  (object[WINDBAG].vertex+3+i*4)->y= lng*vny - rad*vnx;
  (object[WINDBAG].vertex+3+i*4)->z= hoej + flyth;

 }
}

