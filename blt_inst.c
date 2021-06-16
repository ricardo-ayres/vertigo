#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#include "bool.h"
#include <allegro.h>
#include "objects/objects.h"
#include "vertigo.h"
#include "blt_inst.h"
#include "mymath.h"

static BITMAP *RPM_buf;
static BITMAP *MAN_buf;
static BITMAP *TURN_buf;
static BITMAP *ALT_buf;
static BITMAP *VVI_buf;
static BITMAP *IAS_buf;
static BITMAP *COMP_buf;
static BITMAP *ACC_buf;
static BITMAP *HOR_buf;
static BITMAP *ILS_buf;
static BITMAP *TANK_buf;
static BITMAP *FFLW_buf;
static BITMAP *JET_RPM_buf;
static BITMAP *JET_EGT_buf;
static BITMAP *JET_FFLW_buf;
static BITMAP *GEAR_buf;

extern void errormessage(char *text);

extern float xscl, yscl;

extern propengine    pengine[maxnpropengines+1];
extern short npropengines;
extern instrum_par   instrum;

extern short page;
extern bool  paging;
extern BITMAP *active_page;

extern FONT *font_big;
extern FONT *font_med;
extern FONT *font_sml; 

void draw_screws(BITMAP *bmp)
{
 float xscale=xscl*INST_SCALE;
 float yscale=yscl*INST_SCALE;

 circlefill(bmp,  5*xscale, 5*yscale, 2*xscale, BLACK);
 circlefill(bmp,  5*xscale,95*yscale, 2*xscale, BLACK);
 circlefill(bmp, 95*xscale, 5*yscale, 2*xscale, BLACK);
 circlefill(bmp, 95*xscale,95*yscale, 2*xscale, BLACK);
}



float RPM_vin(float RPM, float minRPM, float maxRPM)
{
 float vin, v_frac;

 v_frac = (RPM-minRPM)/(maxRPM-minRPM);

 vin    = 2 * PI * (v_frac*0.8-0.75+0.1);

 return vin;
}



void make_RPM_dial()
{
 float rpm;
 float xscale=xscl*INST_SCALE;
 float yscale=yscl*INST_SCALE;
 int charx,chary;
 float redline_lo = 256 - 128*RPM_vin(3000,0,3500)/PI;
 float redline_hi = 256 - 128*RPM_vin(3500,0,3500)/PI;
 int r;

 if (!(RPM_buf=create_bitmap(100*xscale,100*yscale))) {
   errormessage("Not enough memory for instrument bitmaps");
 }

 clear_to_color(RPM_buf, LIGHTGRAY);
 draw_screws(RPM_buf);
 circlefill(RPM_buf, 50*xscale, 50*yscale, 48*xscale, BLACK);
 for (r=410; r<=450; r++)
   arc(RPM_buf, 50*xscale, 50*yscale, ftofix(redline_hi), ftofix(redline_lo), r*xscale/10, LIGHTRED);
 

 charx=text_length(font_sml,"M");
 chary=text_height(font_sml);
 textout(RPM_buf, font_sml, "RPM", 50*xscale-1.5*charx,50*yscale-1.5*chary, WHITE);

 for (rpm=0; rpm<=3500; rpm+=100) {
     float vin=RPM_vin(rpm,0,3500);
     float ri =40*xscale;
     float ry =45*xscale;
     float cosv=cos(vin);
     float sinv=sin(vin);
     line(RPM_buf, 50*xscale+cosv*ri,50*yscale+sinv*ri, 50*xscale+cosv*ry,50*yscale+sinv*ry, WHITE);
 }
 for (rpm=0; rpm<=3500; rpm+=500) {
     char text[4];

     float vin=RPM_vin(rpm,0,3500);
     float ri =35*xscale;
     float ry =45*xscale;
     float cosv=cos(vin);
     float sinv=sin(vin);
     line(RPM_buf, 50*xscale+cosv*ri,50*yscale+sinv*ri, 50*xscale+cosv*ry,50*yscale+sinv*ry, WHITE);
    
	 sprintf(text,"%d",(int)rpm/100);
	 textout(RPM_buf, font_sml, text, 50*xscale+cosv*ri*0.75-charx,50*yscale+sinv*ri*0.75-0.5*chary, WHITE);
 }
}



void show_RPM_dial(int xcorn, int ycorn)
{
 float xscale=xscl*INST_SCALE;
 float yscale=yscl*INST_SCALE;

 blit(RPM_buf, active_page, 0, 0, xcorn, ycorn, 100*xscale,100*yscale);
}



float MAN_vin(float man, float min_press, float min_vin, float max_press, float max_vin)
{
 float vin, man_frac;

 if ( man < min_press ) man = min_press;
 if ( man > max_press ) man = max_press;

 man_frac = (man-min_press)/(max_press-min_press);

 vin      = man_frac*(max_vin-min_vin) + min_vin;

 return vin;
}



void make_MAN_dial(float min_press, float min_vin, float max_press, float max_vin)
{
 float man;
 float xscale=xscl*INST_SCALE;
 float yscale=yscl*INST_SCALE;
 int charx,chary;

 if (!(MAN_buf=create_bitmap(100*xscale,100*yscale))) {
   errormessage("Not enough memory for instrument bitmaps");
 }

 clear_to_color(MAN_buf, LIGHTGRAY);
 draw_screws(MAN_buf);
 circlefill(MAN_buf, 50*xscale, 50*yscale, 48*xscale, BLACK);

 charx=text_length(font_sml,"M");
 chary=text_height(font_sml);
 textout(MAN_buf, font_sml, "MAN", 50*xscale-1.5*charx,50*yscale-1.5*chary, WHITE);

 for (man=min_press; man<=max_press; man+=2) {
     float vin=MAN_vin(man, min_press, min_vin, max_press, max_vin);
     float ri =40*xscale;
     float ry =45*xscale;
     float cosv=cos(vin);
     float sinv=sin(vin);
	 line(MAN_buf, 50*xscale+cosv*ri,50*yscale+sinv*ri, 50*xscale+cosv*ry,50*yscale+sinv*ry, WHITE);
 }
 for (man=min_press; man<=max_press; man+=10) {
     char text[4];

     float vin=MAN_vin(man, min_press, min_vin, max_press, max_vin);
     float ri =35*xscale;
     float ry =45*xscale;
     float cosv=cos(vin);
     float sinv=sin(vin);
	 line(MAN_buf, 50*xscale+cosv*ri,50*yscale+sinv*ri, 50*xscale+cosv*ry,50*yscale+sinv*ry, WHITE);
	 sprintf(text,"%d",(int)man);
	 textout(MAN_buf, font_sml, text, 50*xscale+cosv*ri*0.75-charx,50*yscale+sinv*ri*0.75-0.5*chary, WHITE);
 }
}



void show_MAN_dial(int xcorn, int ycorn)
{
 float xscale=xscl*INST_SCALE;
 float yscale=yscl*INST_SCALE;

 blit(MAN_buf, active_page, 0, 0, xcorn, ycorn, 100*xscale,100*yscale);
}



void make_TURN_dial()
{
 float xscale=xscl*INST_SCALE;
 float yscale=yscl*INST_SCALE;
 int i;

 if (!(TURN_buf=create_bitmap(100*xscale,100*yscale))) {
   errormessage("Not enough memory for instrument bitmaps");
 }

 clear_to_color(TURN_buf, LIGHTGRAY);
 draw_screws(TURN_buf);
 circlefill(TURN_buf, 50*xscale, 50*yscale, 48*xscale, BLACK);
 circlefill(TURN_buf, 50*xscale, 50*yscale, 40*xscale, DARKGRAY);

 rectfill(TURN_buf, 46*xscale,11*yscale,54*xscale,16*yscale, WHITE);

 for (i=-25; i<25; i++) {
  float y=50*(1-cos(i*(PI/180)));
  line(TURN_buf, (50+i)*xscale,(60-y)*yscale,(50+i)*xscale,(75-y)*yscale, BLACK);
 }

 line(TURN_buf, 40*xscale,58*yscale,40*xscale,77*yscale, WHITE);
 line(TURN_buf, 60*xscale,58*yscale,60*xscale,77*yscale, WHITE);
}



void show_TURN_dial(int xcorn, int ycorn)
{
 float xscale=xscl*INST_SCALE;
 float yscale=yscl*INST_SCALE;

 blit(TURN_buf, active_page, 0, 0, xcorn, ycorn, 100*xscale,100*yscale);
}



void make_ALT_dial()
{
 float xscale=xscl*INST_SCALE;
 float yscale=yscl*INST_SCALE;
 int tick,charx,chary;

 if (!(ALT_buf=create_bitmap(100*xscale,100*yscale))) {
   errormessage("Not enough memory for instrument bitmaps");
 }

 clear_to_color(ALT_buf, LIGHTGRAY);
 draw_screws(ALT_buf);
 circlefill(ALT_buf, 50*xscale, 50*yscale, 50*xscale, BLACK);
 circlefill(ALT_buf, 12*xscale, 88*yscale,  8*xscale, BLACK);

 charx=text_length(font_sml,"O");
 chary=text_height(font_sml);
 textout(ALT_buf, font_sml, "oo", 50*xscale+0.5*charx,50*yscale-0.6*chary, WHITE); 
 
 for (tick=0; tick<50; tick++) {
     float vin=2*PI*tick/50;
     float ri =43*xscale;
     float ry =45*xscale;
     float cosv=cos(vin-PI/2);
     float sinv=sin(vin-PI/2);
	 line(ALT_buf, 50*xscale+cosv*ri,50*yscale+sinv*ri, 50*xscale+cosv*ry,50*yscale+sinv*ry, WHITE);
 }
 for (tick=0; tick<10; tick++) {
     char text[3];

     float vin=2*PI*tick/10;
     float ri =40*xscale;
     float ry =45*xscale;
     float cosv=cos(vin-PI/2);
     float sinv=sin(vin-PI/2);
	 line(ALT_buf, 50*xscale+cosv*ri,50*yscale+sinv*ri, 50*xscale+cosv*ry,50*yscale+sinv*ry, WHITE);

	 sprintf(text,"%d",tick);
	 textout(ALT_buf, font_sml, text, 50*xscale+cosv*ri*0.8-0.4*charx,50*yscale+sinv*ri*0.8-0.2*chary, WHITE);
 }

 textout(ALT_buf, font_sml, "1013", 52*xscale, 63*yscale, WHITE);
}



void show_ALT_dial(int xcorn, int ycorn)
{
 float xscale=xscl*INST_SCALE;
 float yscale=yscl*INST_SCALE;

 blit(ALT_buf, active_page, 0, 0, xcorn, ycorn, 100*xscale,100*yscale);
}




float VVI_vin(float vv, float max_vv)
{
 float vin, vv_frac;
 float min_vv = -max_vv;

 if ( vv < min_vv ) vv = min_vv;
 if ( vv > max_vv ) vv = max_vv;

 vv_frac  = vv/max_vv;

 vin      = PI + vv_frac*7*PI/8;

 return vin;
}



void make_VVI_dial(float max_vv)
{
 /* Instrument scale is thousands of feet per minute */

 float vv;
 float xscale=xscl*INST_SCALE;
 float yscale=yscl*INST_SCALE;
 float min_vv=-max_vv;
 int charx,chary;

 if (!(VVI_buf=create_bitmap(100*xscale,100*yscale))) {
   errormessage("Not enough memory for instrument bitmaps");
 }

 clear_to_color(VVI_buf, LIGHTGRAY);
 draw_screws(VVI_buf);
 circlefill(VVI_buf, 50*xscale, 50*yscale, 48*xscale, BLACK);

 charx=text_length(font_sml,"M");
 chary=text_height(font_sml);
 
 textout(VVI_buf, font_sml, "VVI", 50*xscale-1.5*charx,50*yscale-1.5*chary, WHITE); 
 textout(VVI_buf, font_sml, "1000", 50*xscale-2*charx,50*yscale+0.6*chary, WHITE); 
 textout(VVI_buf, font_sml, "FT/MIN", 50*xscale-3*charx,50*yscale+1.6*chary, WHITE); 

 for (vv=min_vv; vv<=max_vv; vv+=200) {
     float vin=VVI_vin(vv, max_vv);
     float ri =40*xscale;
     float ry =45*xscale;
     float cosv=cos(vin);
     float sinv=sin(vin);
     line(VVI_buf, 50*xscale+cosv*ri,50*yscale+sinv*ri, 50*xscale+cosv*ry,50*yscale+sinv*ry, WHITE);
 }

 for (vv=min_vv; vv<=max_vv; vv+=1000) {
     char text[4];

     float vin=VVI_vin(vv, max_vv);
     float ri =35*xscale;
     float ry =45*xscale;
     float cosv=cos(vin);
     float sinv=sin(vin);
     line(VVI_buf, 50*xscale+cosv*ri,50*yscale+sinv*ri, 50*xscale+cosv*ry,50*yscale+sinv*ry, WHITE);
     sprintf(text,"%d",(int)vv / 1000);
	   textout(VVI_buf, font_sml, text, 50*xscale+cosv*ri*0.75-charx,50*yscale+sinv*ri*0.75-0.5*chary , WHITE);
 }
}



void show_VVI_dial(int xcorn, int ycorn)
{
 float xscale=xscl*INST_SCALE;
 float yscale=yscl*INST_SCALE;

 blit(VVI_buf, active_page, 0, 0, xcorn, ycorn, 100*xscale,100*yscale);
}



float IAS_vin(float ias, float min_ias, float min_vin, float max_ias, float max_vin)
{
 float vin, ias_frac;

 if ( ias < min_ias ) ias = min_ias;
 if ( ias > max_ias ) ias = max_ias;

 ias_frac = (ias-min_ias)/(max_ias-min_ias);

 vin      = ias_frac*(max_vin-min_vin) + min_vin;

 return vin;
}



void make_IAS_dial(float min_ias, float min_vin, float max_ias, float max_vin)
{
 int ias;
 float xscale=xscl*INST_SCALE;
 float yscale=yscl*INST_SCALE;
 int charx,chary;
 int smallstep, bigstep;

 if (!(IAS_buf=create_bitmap(100*xscale,100*yscale))) {
   errormessage("Not enough memory for instrument bitmaps");
 }

 clear_to_color(IAS_buf, LIGHTGRAY);
 draw_screws(IAS_buf);
 circlefill(IAS_buf, 50*xscale, 50*yscale, 48*xscale, BLACK);

 charx=text_length(font_sml,"M");
 chary=text_height(font_sml);
 
 textout(IAS_buf, font_sml, "IAS", 50*xscale-1.5*charx,50*yscale-1.5*chary, WHITE); 
 textout(IAS_buf, font_sml, "KTS", 50*xscale-1.5*charx,50*yscale+1.0*chary, WHITE); 

 smallstep                    =  5;
 if (max_ias > 300) smallstep = 10;
 if (max_ias > 600) smallstep = 20;
 for (ias=min_ias; ias<=max_ias; ias++) {
   if (ias % smallstep == 0) {
     float vin=IAS_vin(ias, min_ias, min_vin, max_ias, max_vin);
     float ri =40*xscale;
     float ry =45*xscale;
     float cosv=cos(vin);
     float sinv=sin(vin);
		 line(IAS_buf, 50*xscale+cosv*ri,50*yscale+sinv*ri, 50*xscale+cosv*ry,50*yscale+sinv*ry, WHITE);
   }
 }

 bigstep                    =  20;
 if (max_ias > 300) bigstep =  50;
 if (max_ias > 600) bigstep = 100;
 for (ias=min_ias; ias<=max_ias; ias++) {
   if (ias % bigstep == 0) {
     char text[4];

     float vin=IAS_vin(ias, min_ias, min_vin, max_ias, max_vin);
     float ri =35*xscale;
     float ry =45*xscale;
     float cosv=cos(vin);
     float sinv=sin(vin);
     line(IAS_buf, 50*xscale+cosv*ri,50*yscale+sinv*ri, 50*xscale+cosv*ry,50*yscale+sinv*ry, WHITE);

		 sprintf(text,"%d",(int)ias);
	   textout(IAS_buf, font_sml, text, 50*xscale+cosv*ri*0.75-1.5*charx,50*yscale+sinv*ri*0.75-0.5*chary, WHITE);
   }
 }
}



void show_IAS_dial(int xcorn, int ycorn)
{
 float xscale=xscl*INST_SCALE;
 float yscale=yscl*INST_SCALE;

 blit(IAS_buf, active_page, 0, 0, xcorn, ycorn, 100*xscale,100*yscale); 
}



void make_COMP_dial()
{
 float xscale=xscl*INST_SCALE;
 float yscale=yscl*INST_SCALE;

 if (!(COMP_buf=create_bitmap(100*xscale,100*yscale))) {
   errormessage("Not enough memory for instrument bitmaps");
 }

 clear_to_color(COMP_buf, LIGHTGRAY);
 draw_screws(COMP_buf);
 circlefill(COMP_buf, 50*xscale, 50*yscale, 48*xscale, BLACK);
 circlefill(COMP_buf, 50*xscale, 50*yscale, 40*xscale, DARKGRAY);
 rectfill(COMP_buf, 25*xscale, 35*yscale, 75*xscale, 65*yscale, BLACK);
 line(COMP_buf, 50*xscale,35*yscale, 50*xscale,65*yscale, WHITE);
}



void show_COMP_dial(int xcorn, int ycorn)
{
 float xscale=xscl*INST_SCALE;
 float yscale=yscl*INST_SCALE;

 blit(COMP_buf, active_page, 0, 0, xcorn, ycorn, 100*xscale,100*yscale);  
}



float ACC_vin(float acc, float min_acc, float max_acc)
{
 float vin;
 float range, scale;

 if ( acc < min_acc ) acc = min_acc;
 if ( acc > max_acc ) acc = max_acc;

 range=max_acc-min_acc+2;
 scale=2*PI/range;

 vin = PI+(acc-1)*scale;

 return vin;
}



void make_ACC_dial(float min_acc, float max_acc)
{
 int acc;
 float xscale=xscl*INST_SCALE;
 float yscale=yscl*INST_SCALE;
 int charx, chary;

 if (!(ACC_buf=create_bitmap(100*xscale,100*yscale))) {
   errormessage("Not enough memory for instrument bitmaps");
 }

 clear_to_color(ACC_buf, LIGHTGRAY);
 draw_screws(ACC_buf);
 circlefill(ACC_buf, 50*xscale, 50*yscale, 48*xscale, BLACK);

 charx=text_length(font_sml,"M");
 chary=text_height(font_sml);

 textout(ACC_buf, font_sml, "ACC", 50*xscale-1.5*charx,50*yscale-1.5*chary, WHITE); 
 
 for (acc=min_acc; acc<=max_acc-1; acc++) {
     float vin=ACC_vin((float)acc+0.5, min_acc, max_acc);
     float ri =40*xscale;
     float ry =45*xscale;
     float cosv=cos(vin);
     float sinv=sin(vin);

     line(ACC_buf, 50*xscale+cosv*ri,50*yscale+sinv*ri, 50*xscale+cosv*ry,50*yscale+sinv*ry, WHITE);
 }

 for (acc=min_acc; acc<=max_acc; acc++) {
     char text[4];
     float vin=ACC_vin(acc, min_acc, max_acc);
     float ri =35*xscale;
     float ry =45*xscale;
     float cosv=cos(vin);
     float sinv=sin(vin);

     line(ACC_buf, 50*xscale+cosv*ri,50*yscale+sinv*ri, 50*xscale+cosv*ry,50*yscale+sinv*ry, WHITE);
     if (acc % 2 == 0) {
			 sprintf(text,"%d",acc);
	     textout(ACC_buf, font_sml, text, 50*xscale+cosv*ri*0.75-charx,50*yscale+sinv*ri*0.75-0.5*chary, WHITE);
     }
 }
}



void show_ACC_dial(int xcorn, int ycorn)
{
 float xscale=xscl*INST_SCALE;
 float yscale=yscl*INST_SCALE;

 blit(ACC_buf, active_page, 0, 0, xcorn, ycorn, 100*xscale,100*yscale);  
}



void make_ILS_dial()
{
 float xscale=xscl*INST_SCALE;
 float yscale=yscl*INST_SCALE;
 int i;

 if (!(ILS_buf=create_bitmap(100*xscale,100*yscale))) {
   errormessage("Not enough memory for instrument bitmaps");
 }

 clear_to_color(ILS_buf, LIGHTGRAY);
 draw_screws(ILS_buf);
 circlefill(ILS_buf, 50*xscale, 50*yscale, 48*xscale, BLACK);

 circle(ILS_buf, 50*xscale, 50*yscale, 4*xscale, WHITE);

 for (i=-3; i<=3; i++) {
   if (i!=0) {
     line(ILS_buf, (50+10*i)*xscale, 48*yscale, (50+10*i)*xscale, 52*yscale, WHITE);
     line(ILS_buf, 48*xscale,(50+10*i)*yscale,  52*xscale,(50+10*i)*yscale,  WHITE);
   }
 }
}



void show_ILS_dial(int xcorn, int ycorn)
{
 float xscale=xscl*INST_SCALE;
 float yscale=yscl*INST_SCALE;

 blit(ILS_buf, active_page, 0, 0, xcorn, ycorn, 100*xscale,100*yscale); 
}



void make_HOR_dial()
{

 float xscale=xscl*INST_SCALE;
 float yscale=yscl*INST_SCALE;
 float vin;

  if (!(HOR_buf=create_bitmap(100*xscale,100*yscale))) {
   errormessage("Not enough memory for instrument bitmaps");
 }

 clear_to_color(HOR_buf, LIGHTGRAY);
 draw_screws(HOR_buf);
 circlefill(HOR_buf, 50*xscale, 50*yscale, 48*xscale, BLACK);
 circlefill(HOR_buf, 88*xscale, 88*yscale,  8*xscale, BLACK);

 for (vin = 0; vin <= PI; vin+=PI/6) {
   float ri =40*xscale;
   float ry =45*xscale;
   float cosv=cos(vin);
   float sinv=sin(vin);

   line(HOR_buf, 50*xscale+cosv*ri,50*yscale+sinv*ri, 50*xscale+cosv*ry,50*yscale+sinv*ry, WHITE);
 }

 for (vin = PI/2-PI/9; vin <= PI/2+PI/9; vin+=PI/18) {
   float ri =43*xscale;
   float ry =45*xscale;
   float cosv=cos(vin);
   float sinv=sin(vin);

   line(HOR_buf, 50*xscale+cosv*ri,50*yscale+sinv*ri, 50*xscale+cosv*ry,50*yscale+sinv*ry, WHITE);
 }
}



void show_HOR_dial(int xcorn, int ycorn)
{
 float xscale=xscl*INST_SCALE;
 float yscale=yscl*INST_SCALE;

 blit(HOR_buf, active_page, 0, 0, xcorn, ycorn, 100*xscale,100*yscale);  
}



float TANK_vin(float fuelfrac, int id)
{
 float vin;


 if (id == 0) {
    vin    = -2*PI*(fuelfrac*0.45-0.225);
 }
 else {
    vin    = -2*PI*(-fuelfrac*0.45-0.275);
 }

 return vin;
}



void make_TANK_dial()
{
 float xscale=xscl*INST_SCALE;
 float yscale=yscl*INST_SCALE;
 int charx,chary;
 float fuel;
 float hi, lo;
 int r;

 if (!(TANK_buf=create_bitmap(100*xscale,100*yscale))) {
   errormessage("Not enough memory for instrument bitmaps");
 }

 clear_to_color(TANK_buf, LIGHTGRAY);
 draw_screws(TANK_buf);
 circlefill(TANK_buf, 50*xscale, 50*yscale, 48*xscale, BLACK);

 hi = TANK_vin(1-0, 0)*128/PI;
 lo = TANK_vin(1-0.2, 0)*128/PI;
 for (r=270; r<=290; r++) {
   arc(TANK_buf, 20*xscale, 50*yscale, ftofix(hi), ftofix(lo), r*xscale/10, LIGHTRED);
 }

 hi = TANK_vin(1-0, 1)*128/PI;
 lo = TANK_vin(1-0.2, 1)*128/PI;
 for (r=270; r<=290; r++) {
   arc(TANK_buf, 80*xscale, 50*yscale, ftofix(lo), ftofix(hi), r*xscale/10, LIGHTRED);
 }

 charx=text_length(font_sml,"M");
 chary=text_height(font_sml);
 textout(TANK_buf, font_sml,"FUEL",50*xscale-1.5*charx,50*yscale-4.5*chary, WHITE);

 for (fuel=0; fuel<=1; fuel+=0.2) {
     float vin=TANK_vin(fuel,0);
     float ri =24*xscale;
     float ry =29*xscale;
     float cosv=cos(vin);
     float sinv=sin(vin);
     line(TANK_buf, 20*xscale+cosv*ri,50*yscale+sinv*ri, 20*xscale+cosv*ry,50*yscale+sinv*ry, WHITE);
 }

 for (fuel=0; fuel<=1; fuel+=0.2) {
     float vin=TANK_vin(fuel,1);
     float ri =24*xscale;
     float ry =29*xscale;
     float cosv=cos(vin);
     float sinv=sin(vin);
     line(TANK_buf, 80*xscale+cosv*ri,50*yscale+sinv*ri, 80*xscale+cosv*ry,50*yscale+sinv*ry, WHITE);
 }

 for (fuel=0; fuel<=1; fuel+=0.1) {
     float vin=TANK_vin(fuel,0);
     float ri =27*xscale;
     float ry =29*xscale;
     float cosv=cos(vin);
     float sinv=sin(vin);
     line(TANK_buf, 20*xscale+cosv*ri,50*yscale+sinv*ri, 20*xscale+cosv*ry,50*yscale+sinv*ry, WHITE);
 }

 for (fuel=0; fuel<=1; fuel+=0.1) {
     float vin=TANK_vin(fuel,1);
     float ri =27*xscale;
     float ry =29*xscale;
     float cosv=cos(vin);
     float sinv=sin(vin);
     line(TANK_buf, 80*xscale+cosv*ri,50*yscale+sinv*ri, 80*xscale+cosv*ry,50*yscale+sinv*ry, WHITE);
 }

 {
  float vin=TANK_vin(1,0);
  float r =23*xscale;
  float cosv=cos(vin);
  float sinv=sin(vin);
	textout(TANK_buf, font_sml, "F", 20*xscale+cosv*r-charx,50*yscale+sinv*r-0.5*chary, WHITE);
 }

 {
  float vin=TANK_vin(1,1);
  float r =23*xscale;
  float cosv=cos(vin);
  float sinv=sin(vin);
	textout(TANK_buf, font_sml, "F", 80*xscale+cosv*r+0.5*charx,50*yscale+sinv*r-0.5*chary, WHITE);
 }

 {
  float vin=TANK_vin(0,0);
  float r =23*xscale;
  float cosv=cos(vin);
  float sinv=sin(vin);
  textout(TANK_buf, font_sml, "E", 20*xscale+cosv*r-charx,50*yscale+sinv*r-0.5*chary, WHITE);
 }

 {
  float vin=TANK_vin(0,1);
  float r =23*xscale;
  float cosv=cos(vin);
  float sinv=sin(vin);
	textout(TANK_buf, font_sml, "E", 80*xscale+cosv*r+0.5*charx,50*yscale+sinv*r-0.5*chary, WHITE);
 }
}



void show_TANK_dial(int xcorn, int ycorn)
{
 float xscale=xscl*INST_SCALE;
 float yscale=yscl*INST_SCALE;

 blit(TANK_buf, active_page, 0, 0, xcorn, ycorn, 100*xscale,100*yscale);   
}




float FFLW_vin(float flow, float max_flow, float min_vin, float max_vin)
{
 float vin, flow_frac;

 if ( flow > max_flow ) flow = max_flow;

 flow_frac = flow/max_flow;

 vin      = flow_frac*(max_vin-min_vin) + min_vin;

 return vin;
}



void make_FFLW_dial(float max_flow, float min_vin, float max_vin)
{
 float flow;
 float xscale=xscl*INST_SCALE;
 float yscale=yscl*INST_SCALE;
 int charx,chary;
 int divfak=1;
 char text[4];

 if (!(FFLW_buf=create_bitmap(100*xscale,100*yscale))) {
   errormessage("Not enough memory for instrument bitmaps");
 }

 clear_to_color(FFLW_buf, LIGHTGRAY);
 draw_screws(FFLW_buf);
 circlefill(FFLW_buf, 50*xscale, 50*yscale, 48*xscale, BLACK);

 charx=text_length(font_sml,"M");
 chary=text_height(font_sml);

 textout(FFLW_buf, font_sml, "FUEL FLOW", 50*xscale-4.0*charx,50*yscale-1.5*chary, WHITE); 
 textout(FFLW_buf, font_sml, "GAL/HR", 50*xscale-2.5*charx,50*yscale+0.5*chary, WHITE); 

 while (max_flow/divfak > 100)
    divfak*=10;

 for (flow=0; flow<=max_flow/divfak; flow++) {
     float vin=FFLW_vin(flow*divfak, max_flow, min_vin, max_vin);
     float ri =43*xscale;
     float ry =45*xscale;
     float cosv=cos(vin);
     float sinv=sin(vin);
     line(FFLW_buf, 50*xscale+cosv*ri,50*yscale+sinv*ri, 50*xscale+cosv*ry,50*yscale+sinv*ry, WHITE);
 }


 divfak=1;
 while (max_flow/divfak > 10)
    divfak*=10;

 for (flow=0; flow<=max_flow/divfak; flow++) {
     float vin=FFLW_vin(flow*divfak, max_flow, min_vin, max_vin);
     float ri =38*xscale;
     float ry =45*xscale;
     float cosv=cos(vin);
     float sinv=sin(vin);

     line(FFLW_buf, 50*xscale+cosv*ri,50*yscale+sinv*ri, 50*xscale+cosv*ry,50*yscale+sinv*ry, WHITE);

		 sprintf(text,"%d",(int)flow*10);
	   textout(FFLW_buf, font_sml, text, 50*xscale+cosv*ri*0.75-charx,50*yscale+sinv*ri*0.75-0.5*chary, WHITE);
 }

 if (divfak > 10) {
	 sprintf(text,"x%d",(int)divfak/10);
   textout(FFLW_buf, font_sml, text, 50*xscale-2*charx,50*yscale+1.5*chary, WHITE);
 }

}



void show_FFLW_dial(int xcorn, int ycorn)
{
 float xscale=xscl*INST_SCALE;
 float yscale=yscl*INST_SCALE;

 blit(FFLW_buf, active_page, 0, 0, xcorn, ycorn, 100*xscale,100*yscale);  
}



/*********** Jet RPM ************/

float JET_RPM_tick(float rpm)
{
 float tick, nrpm;

 nrpm = rpm/100.0;

 if ( nrpm > 1.1 ) nrpm = 1.1;

 if (nrpm <= 0.6)
    tick = 0.30*nrpm;
 else
    tick = 0.18 + (nrpm-0.6)*1.5;

 return tick;
}



void make_JET_RPM_dial()
{
 float xscale=xscl*INST_SCALE;
 float yscale=yscl*INST_SCALE;
 int charx,chary;
 int rpm;

 if (!(JET_RPM_buf=create_bitmap(25*xscale,150*yscale))) {
   errormessage("Not enough memory for instrument bitmaps");
 }

 clear_to_color(JET_RPM_buf, LIGHTGRAY);

 rectfill(JET_RPM_buf, 0, 3, 26*xscale, 148*yscale, BLACK);
 
 rectfill(JET_RPM_buf, 5*xscale, (143-JET_RPM_tick(104.0)*135)*yscale ,
     20*xscale, (143-JET_RPM_tick(110.0)*135)*yscale, LIGHTRED );

 charx=text_length(font_sml,"M");
 chary=text_height(font_sml);

 textout(JET_RPM_buf, font_sml, "RPM", 13*xscale-1.5*charx,5*yscale, WHITE); 
 
 for (rpm = 0; rpm<=11; rpm ++) {
  float tickh=JET_RPM_tick(rpm*10);

  line(JET_RPM_buf, 3*xscale,(143-tickh*135)*yscale, 12*xscale,(143-tickh*135)*yscale, WHITE);

  if (rpm == 0 || rpm >=6) {
     char text[4];
     sprintf(text,"%2d",rpm);
		 textout(JET_RPM_buf, font_sml, text, 12*xscale+0.4*charx,(143-tickh*135)*yscale-0.2*chary , WHITE);
  }
 }

 for (rpm = 0; rpm<=25; rpm ++) {
  float tickh=JET_RPM_tick(rpm*2+60);

  line(JET_RPM_buf, 3*xscale,(143-tickh*135)*yscale, 6*xscale,(143-tickh*135)*yscale, WHITE);
 }
}



void show_JET_RPM_dial(int xcorn, int ycorn)
{
 float xscale=xscl*INST_SCALE;
 float yscale=yscl*INST_SCALE;

 blit(JET_RPM_buf, active_page, 0, 0, xcorn, ycorn, 25*xscale,150*yscale);  
}



/************ JET Exhaust Gas Temperature **************/

float JET_EGT_tick(float egt)
{
 float tick, negt;

 negt = egt/1400.0;

 if ( negt > 1.0 ) negt = 1.0;

 if (negt <= (600./1400.))
    tick = 0.3*negt;
 else
    tick = 0.3*(600./1400.) + (negt-(600./1400.))*1.4;

 return tick;
}



void make_JET_EGT_dial()
{
 float xscale=xscl*INST_SCALE;
 float yscale=yscl*INST_SCALE;
 int charx,chary;
 int egt;

 if (!(JET_EGT_buf=create_bitmap(25*xscale,150*yscale))) {
   errormessage("Not enough memory for instrument bitmaps");
 }

 clear_to_color(JET_EGT_buf, LIGHTGRAY);

 rectfill(JET_EGT_buf, 0, 3, 26*xscale, 148*yscale, BLACK);
 
 rectfill(JET_EGT_buf, 5*xscale, (143-JET_EGT_tick(1320.0)*135)*yscale ,
     10*xscale, (143-JET_EGT_tick(1150.0)*135)*yscale, YELLOW);

 rectfill(JET_EGT_buf, 5*xscale, (143-JET_EGT_tick(1400.0)*135)*yscale ,
     20*xscale, (143-JET_EGT_tick(1320.0)*135)*yscale, LIGHTRED);

 charx=text_length(font_sml,"M");
 chary=text_height(font_sml);

 textout(JET_EGT_buf, font_sml, "EGT", 13*xscale-1.5*charx,5*yscale, WHITE); 
 
 for (egt = 0; egt<=14; egt ++) {
  float tickh=JET_EGT_tick(egt*100);

  line(JET_EGT_buf, 3*xscale,(143-tickh*135)*yscale, 12*xscale,(143-tickh*135)*yscale, WHITE);

  if (egt == 0 || (egt >=6 && egt <= 14)) {
     char text[4];
     sprintf(text,"%2d",egt);
		 textout(JET_EGT_buf, font_sml, text, 12*xscale+0.4*charx,(143-tickh*135)*yscale-0.2*chary, WHITE);
  }
 }

 for (egt = 0; egt<=40; egt ++) {
  float tickh=JET_EGT_tick(egt*20+600);

  line(JET_EGT_buf, 3*xscale,(143-tickh*135)*yscale, 6*xscale,(143-tickh*135)*yscale, WHITE);
 }
}



void show_JET_EGT_dial(int xcorn, int ycorn)
{
 float xscale=xscl*INST_SCALE;
 float yscale=yscl*INST_SCALE;

 blit(JET_EGT_buf, active_page, 0, 0, xcorn, ycorn, 25*xscale,150*yscale);   
}



/**********  JET Fuel Flow ************/

float JET_FFLW_tick(float fflw)
{
 float tick, nfflw;

 nfflw = fflw/13000.0;

 if ( nfflw > 1. ) nfflw = 1.;

 if (nfflw <= (5./13.))
    tick = 1.43*nfflw;
 else
    tick = 1.43*(5./13.) + (nfflw-(5./13.))*0.62;

 return tick;
}



void make_JET_FFLW_dial()
{
 float xscale=xscl*INST_SCALE;
 float yscale=yscl*INST_SCALE;
 int charx,chary;
 int fflw;

 if (!(JET_FFLW_buf=create_bitmap(25*xscale,150*yscale))) {
   errormessage("Not enough memory for instrument bitmaps");
 }

 clear_to_color(JET_FFLW_buf, LIGHTGRAY);

 rectfill(JET_FFLW_buf, 0, 3, 26*xscale, 148*yscale, BLACK);
 
 rectfill(JET_FFLW_buf, 5*xscale, (143-JET_FFLW_tick(11000.0)*135)*yscale ,
     20*xscale, (143-JET_FFLW_tick(13000.0)*135)*yscale, LIGHTRED);

 charx=text_length(font_sml,"M");
 chary=text_height(font_sml);

 textout(JET_FFLW_buf, font_sml, "FF", 13*xscale-1.0*charx,5*yscale, WHITE); 

 for (fflw = 6; fflw<=13; fflw ++) {
  float tickh=JET_FFLW_tick(fflw*1000.);

  line(JET_FFLW_buf, 3*xscale,(143-tickh*135)*yscale, 12*xscale,(143-tickh*135)*yscale, WHITE);

  if (fflw % 2 == 1) {
     char text[4];
     sprintf(text,"%2d",fflw);
		 textout(JET_FFLW_buf, font_sml, text, 12*xscale+0.4*charx,(143-tickh*135)*yscale-0.2*chary, WHITE);
  }
 }

 for (fflw = 0; fflw<=5; fflw ++) {
  float tickh=JET_FFLW_tick(fflw*1000);

  line(JET_FFLW_buf, 3*xscale,(143-tickh*135)*yscale, 12*xscale,(143-tickh*135)*yscale, WHITE);
  {
     char text[4];
     sprintf(text,"%2d",fflw);
     textout(JET_FFLW_buf, font_sml, text, 12*xscale+0.4*charx,(143-tickh*135)*yscale-0.2*chary, WHITE);
  }
 }

 for (fflw = 0; fflw<=25; fflw ++) {
  float tickh=JET_FFLW_tick(fflw*200);

  line(JET_FFLW_buf, 3*xscale,(143-tickh*135)*yscale, 5*xscale,(143-tickh*135)*yscale, WHITE);
 }
}



void show_JET_FFLW_dial(int xcorn, int ycorn)
{
 float xscale=xscl*INST_SCALE;
 float yscale=yscl*INST_SCALE;

 blit(JET_FFLW_buf, active_page, 0, 0, xcorn, ycorn, 25*xscale,150*yscale);    
}

/***************** Gear, brake, hook position *******************/


void make_GEAR_dial()
{
 float xscale=xscl*INST_SCALE;
 float yscale=yscl*INST_SCALE;

 if (!(GEAR_buf=create_bitmap(100*xscale,100*yscale))) {
   errormessage("Not enough memory for instrument bitmaps");
 }

 clear_to_color(GEAR_buf, LIGHTGRAY);
 draw_screws(GEAR_buf);
}



void show_GEAR_dial(int xcorn, int ycorn)
{
 float xscale=xscl*INST_SCALE;
 float yscale=yscl*INST_SCALE;

 blit(GEAR_buf, active_page, 0, 0, xcorn, ycorn, 100*xscale,100*yscale); 
}




void dial_cleanup()
{
 destroy_bitmap(RPM_buf);
 destroy_bitmap(MAN_buf);
 destroy_bitmap(TURN_buf);
 destroy_bitmap(ALT_buf);
 destroy_bitmap(VVI_buf);
 destroy_bitmap(IAS_buf);
 destroy_bitmap(COMP_buf);
 destroy_bitmap(ACC_buf);
 destroy_bitmap(HOR_buf);
 destroy_bitmap(ILS_buf);
 destroy_bitmap(TANK_buf);
 destroy_bitmap(FFLW_buf);
 destroy_bitmap(JET_RPM_buf);
 destroy_bitmap(JET_EGT_buf);
 destroy_bitmap(JET_FFLW_buf);
 destroy_bitmap(GEAR_buf);
}



void make_instruments()
{
 make_RPM_dial();
 if (npropengines > 0)
   make_MAN_dial(pengine[0].mani_min , 7*PI/8, pengine[0].mani_max , 2*PI+6*PI/8);
 make_TURN_dial();
 make_ALT_dial();
 make_VVI_dial(instrum.max_vv);
 make_IAS_dial(instrum.min_ias, -PI/2, instrum.max_ias, 11*PI/8);
 make_COMP_dial();
 make_ACC_dial(-5, 10);
 make_ILS_dial();
 make_HOR_dial();
 make_TANK_dial();
 make_FFLW_dial(instrum.max_fuel_flow, 5.5*PI/8, 2*PI+2.5*PI/8);
 make_JET_RPM_dial();
 make_JET_EGT_dial();
 make_JET_FFLW_dial();
 make_GEAR_dial();
}
