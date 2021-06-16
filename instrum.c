

void update_filters()
{
 /* Recursive filter constant */
 /* Time scale of 1.0 sec */
 /* As dtperframe varies, this has to be updated */

 filter_const = exp(-dtperframe / 1.0);
}



void showflap(int xcorn, int ycorn, float skala)
{
 rectfill(active_page, xcorn,ycorn,xcorn+20*skala*xscl,ycorn+100*skala*yscl, BLACK);
 rect(active_page, xcorn,ycorn,xcorn+20*skala*xscl,ycorn+100*skala*yscl, LIGHTGREEN);
 rectfill(active_page, xcorn,ycorn+(50+setflap)*skala*yscl,xcorn+20*skala*xscl,ycorn+50*skala*yscl, LIGHTGREEN);
 rectfill(active_page, xcorn+3*skala*xscl,ycorn+(50+flap)*skala*yscl,xcorn+17*skala*xscl,ycorn+50*skala*yscl, RED);
 line(active_page, xcorn,ycorn+50*skala*yscl, xcorn+20*skala*xscl,ycorn+50*skala*yscl, WHITE);
}



void showthrottle(int xcorn, int ycorn, float skala,int engineid)
{
 float rpm=0;
 if (npropengines > 0) rpm=pengine[engineid].rpm_percent;
 if (njetengines > 0) rpm=jengine[engineid].rpm;

 rectfill(active_page, xcorn,ycorn,xcorn+20*skala*xscl,ycorn+100*skala*yscl, BLACK);
 rect(active_page, xcorn,ycorn,xcorn+20*skala*xscl,ycorn+100*skala*yscl, LIGHTGREEN);
 rectfill(active_page, xcorn,ycorn+(100-throttle)*skala*yscl,xcorn+20*skala*xscl,ycorn+100*skala*yscl, LIGHTGREEN);
 if (detail_prop && npropengines > 0)
   rectfill(active_page, xcorn+3*skala*xscl,ycorn+(100-pengine[0].rpm/27)*skala*yscl,xcorn+17*skala*xscl,ycorn+100*skala*yscl, RED);
 else
   rectfill(active_page, xcorn+3*skala*xscl,ycorn+(100-rpm)*skala*yscl,xcorn+17*skala*xscl,ycorn+100*skala*yscl, RED);
 if (auto_throttle) {
   textout(active_page, font_med, "A", xcorn+8*skala*xscl,ycorn+50*skala*yscl, YELLOW);
 }
}



void show_throttle_ctrl(int xcorn, int ycorn, float skala, int engineid)
{
 /* Only for detailed engine model */
 rectfill(active_page, xcorn,ycorn-10*skala*yscl,xcorn+20*skala*xscl,ycorn+110*skala*yscl, LIGHTGRAY);
 rectfill(active_page, xcorn+8*skala*xscl,ycorn,xcorn+12*skala*xscl,ycorn+100*skala*yscl, BLACK);

 if (npropengines > 0) {
    int throttle = pengine[engineid].throttle;

    rectfill(active_page, xcorn,ycorn+(100-throttle-5)*skala*yscl,xcorn+20*skala*xscl,ycorn+(100-throttle+5)*skala*yscl, BLACK);

    if (pengine[engineid].blower_speeds > 0) {
       switch(pengine[engineid].current_blower_speed) {

         case 0 : textout(active_page, font_med, "N", xcorn+8*skala*xscl,ycorn+50*skala*yscl, YELLOW);
                  break;
         case 1 : textout(active_page, font_med, "L", xcorn+8*skala*xscl,ycorn+50*skala*yscl, YELLOW);
                  break;
         case 2 : textout(active_page, font_med, "H", xcorn+8*skala*xscl,ycorn+50*skala*yscl, YELLOW);
                  break;
         default: ;
       }
    }
 }
 if (njetengines > 0) {
    int throttle = jengine[engineid].throttle;

    rectfill(active_page, xcorn,ycorn+(100-throttle-5)*skala*yscl,xcorn+20*skala*xscl,ycorn+(100-throttle+5)*skala*yscl, BLACK);

    if (jengine[engineid].n_abstages > 0 && jengine[engineid].ab_throttle >= 1) {
       int ab_throttle = jengine[engineid].ab_throttle;
           textprintf(active_page, font_med, xcorn+3*skala*xscl,ycorn+50*skala*yscl, YELLOW, "AB%i", ab_throttle);
    }
 }
 if (nrocketengines > 0) {
    int throttle = rengine[engineid].throttle;

    rectfill(active_page, xcorn,ycorn+(100-throttle-5)*skala*yscl,xcorn+20*skala*xscl,ycorn+(100-throttle+5)*skala*yscl, BLACK);
 }
 if (auto_throttle) {
   textout(active_page, font_med, "A", xcorn+8*skala*xscl,ycorn+50*skala*yscl, YELLOW);
 }
}



void show_prop_ctrl(int xcorn, int ycorn, float skala)
{
 rectfill(active_page, xcorn,ycorn-10*skala*yscl,xcorn+20*skala*xscl,ycorn+110*skala*yscl, LIGHTGRAY);
 rectfill(active_page, xcorn+8*skala*xscl,ycorn,xcorn+12*skala*xscl,ycorn+100*skala*yscl, BLACK);
 rectfill(active_page, xcorn+6*skala*xscl,ycorn+(100-prop_ctrl-10)*skala*yscl,xcorn+14*skala*xscl,ycorn+(100-prop_ctrl+10)*skala*yscl, BLUE);
}



void show_RPM(int xcorn, int ycorn)
{
 float vin = RPM_vin(pengine[0].rpm*pengine[0].reduct_gear,0,3500);
 float cosv= cos(vin);
 float sinv= sin(vin);
 int corners[8];
 float xscale = xscl * INST_SCALE;
 float yscale = yscl * INST_SCALE;
 const float lang   = 45.0;
 const float bred   =  2.0;

 show_RPM_dial(xcorn,ycorn);

 corners[0]=xcorn+50*xscale;
 corners[1]=ycorn+50*yscale;

 corners[2]=xcorn+(50+sinv*bred+0.75*cosv*lang)*xscale;
 corners[3]=ycorn+(50-cosv*bred+0.75*sinv*lang)*yscale;

 corners[4]=xcorn+(50+cosv*lang)*xscale;
 corners[5]=ycorn+(50+sinv*lang)*yscale;

 corners[6]=xcorn+(50-sinv*bred+0.75*cosv*lang)*xscale;
 corners[7]=ycorn+(50+cosv*bred+0.75*sinv*lang)*yscale;

 polygon(active_page,4,corners, WHITE);
}



void show_MAN(int xcorn, int ycorn)
{
 float vin = MAN_vin(pengine[0].mani_press,pengine[0].mani_min , 7*PI/8, pengine[0].mani_max , 2*PI+6*PI/8);
 float cosv= cos(vin);
 float sinv= sin(vin);
 int corners[8];
 float xscale = xscl * INST_SCALE;
 float yscale = yscl * INST_SCALE;
 const float lang   = 45.0;
 const float bred   =  2.0;

 show_MAN_dial(xcorn,ycorn);

 corners[0]=xcorn+50*xscale;
 corners[1]=ycorn+50*yscale;

 corners[2]=xcorn+(50+sinv*bred+0.75*cosv*lang)*xscale;
 corners[3]=ycorn+(50-cosv*bred+0.75*sinv*lang)*yscale;

 corners[4]=xcorn+(50+cosv*lang)*xscale;
 corners[5]=ycorn+(50+sinv*lang)*yscale;

 corners[6]=xcorn+(50-sinv*bred+0.75*cosv*lang)*xscale;
 corners[7]=ycorn+(50+cosv*bred+0.75*sinv*lang)*yscale;

 polygon(active_page, 4,corners, WHITE);
}



void show_IAS(int xcorn, int ycorn)
{
 float ias = tas / sqrt(1.225/atmospheric_density(z));
 float vin, sinv, cosv;
 int corners[8];
 float xscale = xscl * INST_SCALE;
 float yscale = yscl * INST_SCALE;
 const float lang   = 45.0;
 const float bred   =  2.0;

 /* Low-pass filtering */
 ias = filter_const * last_ias + (1.-filter_const) * ias;
 last_ias = ias;

 vin = IAS_vin(ias,instrum.min_ias, -PI/2, instrum.max_ias, 11*PI/8);
 cosv= cos(vin);
 sinv= sin(vin);

 show_IAS_dial(xcorn,ycorn);

 corners[0]=xcorn+50*xscale;
 corners[1]=ycorn+50*yscale;

 corners[2]=xcorn+(50+sinv*bred+0.75*cosv*lang)*xscale;
 corners[3]=ycorn+(50-cosv*bred+0.75*sinv*lang)*yscale;

 corners[4]=xcorn+(50+cosv*lang)*xscale;
 corners[5]=ycorn+(50+sinv*lang)*yscale;

 corners[6]=xcorn+(50-sinv*bred+0.75*cosv*lang)*xscale;
 corners[7]=ycorn+(50+cosv*bred+0.75*sinv*lang)*yscale;

 polygon(active_page, 4,corners, WHITE);
}



void show_TURN(int xcorn, int ycorn)
{
 int corners[8];
 float cosv,sinv;
 const float lang   =-35.0;
 const float bred   =  2.0;
 float deflect= 4*wtop;
 float xscale = xscl * INST_SCALE;
 float yscale = yscl * INST_SCALE;
 float ballx, bally, norm, ballangle;
 float change,dballdt,dball;
 const float ballresponse=20.0*(PI/180);  /* 50 */

 if (fabs(deflect) > 45*(PI/180)) deflect=45*(PI/180)*sgn(deflect);
 cosv=cos(-deflect);
 sinv=sin(-deflect);

 show_TURN_dial(xcorn,ycorn);

 corners[0]=xcorn+(50.5+cosv*bred)*xscale;
 corners[1]=ycorn+(50  -sinv*bred)*yscale;

 corners[2]=xcorn+(50.5+cosv*bred+sinv*lang)*xscale;
 corners[3]=ycorn+(50  -sinv*bred+cosv*lang)*yscale;

 corners[4]=xcorn+(50.5-cosv*bred+sinv*lang)*xscale;
 corners[5]=ycorn+(50  +sinv*bred+cosv*lang)*yscale;

 corners[6]=xcorn+(50.5-cosv*bred)*xscale;
 corners[7]=ycorn+(50  +sinv*bred)*yscale;

 polygon(active_page, 4,corners, WHITE);

 ballx  = avg_accleft-pilotpos.x*ncalcperframe*wacctop;
 bally  = avg_acctop +pilotpos.x*ncalcperframe*waccleft;
 norm   = sqrt(SQR(ballx)+SQR(bally));
 if (norm < 1e-9) {
     ballx=0;
     bally=1;
 }
 else {
     ballx /= norm;
     bally /= norm;
 }

 ballangle=2*arcsin(ballx);


 if (bally < 0) ballangle = 2*PI-ballangle;

 change=ballangle-last_ballangle;
 dballdt=ballresponse*dtperframe;
 if (fabs(change)>dballdt)
    dball=dballdt*sgn(change);
 else
    dball=change;
 ballangle = last_ballangle + dball;

 if (fabs(ballangle) > 25*(PI/180)) ballangle=25*(PI/180)*sgn(ballangle);
 circlefill(active_page, xcorn+(50+50*(sin(ballangle)))*xscale, ycorn+(67.5-50*(1-cos(ballangle)))*yscale, 6*xscale, WHITE);

 last_ballangle = ballangle;
}



void show_ALT(int xcorn, int ycorn)
{
 float xscale = xscl*INST_SCALE;
 float yscale = yscl*INST_SCALE;
 float feet = z / 0.3048;
 int   feet1000;
 float vin, cosv, sinv;
 int charx, chary;
 int corners[8];
 const float lang   = 45.0;
 const float indre  = 15.0;
 const float bred   =  2.0;

 
 /* Low-pass filtering */
 feet = filter_const * last_feet + (1.-filter_const) * feet;
 last_feet = feet;

 if (feet > 100000.) feet = 100000.;
 if (last_feet > 100000.) last_feet = 100000.;

 feet1000 = (long int)feet % 1000;
 vin = (3*PI/2)+(2*PI*feet1000)/1000;
 cosv= cos(vin);
 sinv= sin(vin);

 show_ALT_dial(xcorn,ycorn);

 corners[0]=xcorn+(50+cosv*indre)*xscale;
 corners[1]=ycorn+(50+sinv*indre)*yscale;

 corners[2]=xcorn+(50+sinv*bred+0.75*cosv*lang)*xscale;
 corners[3]=ycorn+(50-cosv*bred+0.75*sinv*lang)*yscale;

 corners[4]=xcorn+(50+cosv*lang)*xscale;
 corners[5]=ycorn+(50+sinv*lang)*yscale;

 corners[6]=xcorn+(50-sinv*bred+0.75*cosv*lang)*xscale;
 corners[7]=ycorn+(50+cosv*bred+0.75*sinv*lang)*yscale;

 polygon(active_page, 4,corners, WHITE);

 charx=text_length(font_med,"O");
 chary=text_height(font_med);
 printg(active_page, font_med, feet/100,3, xcorn+50*xscale-2.5*charx,ycorn+50*yscale-0.8*chary, WHITE);
}



void show_VVI(int xcorn, int ycorn)
{
 float xscale = xscl*INST_SCALE;
 float yscale = yscl*INST_SCALE;
 float ftmin = 60 * v.z / 0.3048;
 float vin, cosv, sinv;
 int corners[8];
 const float lang   = 45.0;
 const float bred   =  2.0;

 /* Low-pass filtering */
 ftmin = filter_const * last_ftmin + (1.-filter_const) * ftmin;
 last_ftmin = ftmin;

 vin = VVI_vin( ftmin, 5000);
 cosv= cos(vin);
 sinv= sin(vin);

 show_VVI_dial(xcorn,ycorn);

 corners[0]=xcorn+50*xscale;
 corners[1]=ycorn+50*yscale;

 corners[2]=xcorn+(50+sinv*bred+0.75*cosv*lang)*xscale;
 corners[3]=ycorn+(50-cosv*bred+0.75*sinv*lang)*yscale;

 corners[4]=xcorn+(50+cosv*lang)*xscale;
 corners[5]=ycorn+(50+sinv*lang)*yscale;

 corners[6]=xcorn+(50-sinv*bred+0.75*cosv*lang)*xscale;
 corners[7]=ycorn+(50+cosv*bred+0.75*sinv*lang)*yscale;

 polygon(active_page, 4,corners, WHITE);
}



void show_COMP(int xcorn, int ycorn)
{	
 float xscale = xscl*INST_SCALE;
 float yscale = yscl*INST_SCALE;
 float head, headmax, headmin;
 int i, deghead;
 int charx,chary;

 show_COMP_dial(xcorn,ycorn);

 charx=text_length(font_med,"O");
 chary=text_height(font_med);

 head=-azi*180/PI; /* Azimuth increases counter-clockwise, heading clockwise */
 headmax=head+40;
 headmin=head-39;
 for (i=headmin; i<headmax; i++)
  {
   if(fmod(i,10)==0)
    {
     line(active_page, xcorn+(50-(i-head)*0.75)*xscale,ycorn+52*yscale,
                       xcorn+(50-(i-head)*0.75)*xscale,ycorn+57*yscale,
          WHITE);
    }

   if(fmod(i,30)==0)
    {
     deghead=i;
     if (deghead<0) deghead+=360;
     if (deghead>=360) deghead-=360;

     switch(deghead) {

     case   0: textout(active_page, font_med, "N", 
                      xcorn+(50-(i-head)*0.75)*xscale-0.5*charx,
                      ycorn+38*yscale, WHITE);
               break;
     case  90: textout(active_page, font_med, "E", 
                      xcorn+(50-(i-head)*0.75)*xscale-0.5*charx,
                      ycorn+38*yscale, WHITE);
               break;
     case 180: textout(active_page, font_med, "S", 
                      xcorn+(50-(i-head)*0.75)*xscale-0.5*charx,
                      ycorn+38*yscale, WHITE);
               break;
     case 270: textout(active_page, font_med, "W", 
                      xcorn+(50-(i-head)*0.75)*xscale-0.5*charx,
                      ycorn+38*yscale, WHITE);
               break;

     default:  if (deghead > 99) {
                  printg(active_page, font_med, deghead/10,2, 
                  xcorn+(50-(i-head)*0.75)*xscale-charx,
                  ycorn+38*yscale, WHITE);
               }
               else {
                  printg(active_page, font_med, deghead/10,1, 
                  xcorn+(50-(i-head)*0.75)*xscale-charx,
                  ycorn+38*yscale, WHITE);
               }
     }
    }
  }

  rectfill(active_page, xcorn+15*xscale,ycorn+35*yscale,xcorn+25*xscale,ycorn+65*yscale, DARKGRAY);
  rectfill(active_page, xcorn+75*xscale,ycorn+35*yscale,xcorn+85*xscale,ycorn+65*yscale, DARKGRAY);
}



void show_ACC(int xcorn, int ycorn)
{
 float xscale = xscl*INST_SCALE;
 float yscale = yscl*INST_SCALE;
 float vin = ACC_vin(gpull, -5, 10);
 float cosv= cos(vin);
 float sinv= sin(vin);
 int corners[8];
 const float lang   = 45.0;
 const float bred   =  2.0;

 show_ACC_dial(xcorn,ycorn);

 corners[0]=xcorn+50*xscale;
 corners[1]=ycorn+50*yscale;

 corners[2]=xcorn+(50+sinv*bred+0.75*cosv*lang)*xscale;
 corners[3]=ycorn+(50-cosv*bred+0.75*sinv*lang)*yscale;

 corners[4]=xcorn+(50+cosv*lang)*xscale;
 corners[5]=ycorn+(50+sinv*lang)*yscale;

 corners[6]=xcorn+(50-sinv*bred+0.75*cosv*lang)*xscale;
 corners[7]=ycorn+(50+cosv*bred+0.75*sinv*lang)*yscale;

 polygon(active_page, 4,corners, WHITE);
 
 vin = ACC_vin(gposmax, -5, 10);
 cosv= cos(vin);
 sinv= sin(vin);
 line(active_page, xcorn+50*xscale,ycorn+50*yscale,
 xcorn+(50+cosv*lang)*xscale,ycorn+(50+sinv*lang)*yscale, WHITE);

 vin = ACC_vin(gnegmax, -5, 10);
 cosv= cos(vin);
 sinv= sin(vin);
 line(active_page, xcorn+50*xscale,ycorn+50*yscale,
 xcorn+(50+cosv*lang)*xscale,ycorn+(50+sinv*lang)*yscale, WHITE);
}



void show_ILS(int xcorn, int ycorn)
{
 float xscale = xscl*INST_SCALE;
 float yscale = yscl*INST_SCALE;
 cartvektor ILSspecs = ILS_signal();
 int xoff=0;
 int yoff=0;
 float xdeg=ILSspecs.y;
 float ydeg=ILSspecs.z;

 show_ILS_dial(xcorn,ycorn);

 if (ILSspecs.x < 10000 && ILSspecs.x > 0) {

    if (xdeg >  3) xdeg= 3;
    if (xdeg < -3) xdeg=-3;
    if (ydeg >  3) ydeg= 3;
    if (ydeg < -3) ydeg=-3;

    xoff = (50+xdeg*9)*yscale;
    yoff = (50-ydeg*9)*yscale;

    line(active_page,xcorn+xoff,ycorn+20*yscale,
    xcorn+xoff,ycorn+80*yscale, WHITE);

    line(active_page, xcorn+20*xscale,ycorn+yoff,
    xcorn+80*xscale,ycorn+yoff, WHITE);
 }
 else {
  rectfill(active_page, xcorn+65*xscale, ycorn+30*yscale, xcorn+85*xscale, ycorn+40*yscale, LIGHTRED);
  line(active_page, xcorn+10*xscale,ycorn+20*yscale, xcorn+10*xscale,ycorn+80*yscale, WHITE);
  line(active_page, xcorn+20*xscale,ycorn+10*yscale, xcorn+80*xscale,ycorn+10*yscale, WHITE);
 }
}



void show_HOR(int xcorn, int ycorn)
{
 #define HORmax 23
 float xscale = xscl*INST_SCALE;
 float yscale = yscl*INST_SCALE;
 float cos_roll     = cos(roll);
 float sin_roll     = sin(roll);
 int i;
 int corners[8];
 int charx, chary;
 char text[4];

 show_HOR_dial(xcorn,ycorn);

 /* Roll angle indicator */
 line(active_page, xcorn+(50+sin_roll*35)*xscale,ycorn+(50+cos_roll*35)*yscale,
	  xcorn+(50+sin_roll*40)*xscale,ycorn+(50+cos_roll*40)*yscale, WHITE);

 for (i=-18; i<17; i++) {
   float vintop=nosealt*180/PI-i*10;
   float vinbot=nosealt*180/PI-(i-1)*10;

   if (fabs(vintop) < HORmax || fabs(vinbot) < HORmax) {
	   int tmpcol;
      if ( i <= 0 ) {
		  tmpcol=BROWN;
      }
      else {
		  tmpcol=LIGHTBLUE;
      }

      if (vintop >  HORmax) vintop =  HORmax;
      if (vintop < -HORmax) vintop = -HORmax;
      if (vinbot >  HORmax) vinbot =  HORmax;
      if (vinbot < -HORmax) vinbot = -HORmax;

      corners[0]=xcorn+(50+sin_roll*vintop-cos_roll*30)*xscale;
      corners[1]=ycorn+(50+cos_roll*vintop+sin_roll*30)*yscale;

      corners[2]=xcorn+(50+sin_roll*vintop+cos_roll*30)*xscale;
      corners[3]=ycorn+(50+cos_roll*vintop-sin_roll*30)*yscale;

      corners[4]=xcorn+(50+sin_roll*vinbot+cos_roll*30)*xscale;
      corners[5]=ycorn+(50+cos_roll*vinbot-sin_roll*30)*yscale;

      corners[6]=xcorn+(50+sin_roll*vinbot-cos_roll*30)*xscale;
      corners[7]=ycorn+(50+cos_roll*vinbot+sin_roll*30)*yscale;

	  polygon(active_page, 4,corners, tmpcol);

   }
 }

 
 charx=text_length(font_med,"M");
 chary=text_height(font_med);
 

 for (i=-18; i<17; i++) {
   if (fabs(nosealt*180/PI-i*10) < HORmax) {
     float upvink=PI*i*10/180 - nosealt;
     int vin;

     upvink *= 180/PI;

     line(active_page, 
		    xcorn+(50-sin_roll*upvink-cos_roll*30)*xscale,
            ycorn+(50-cos_roll*upvink+sin_roll*30)*yscale,
		    xcorn+(50-sin_roll*upvink-cos_roll*10)*xscale,
            ycorn+(50-cos_roll*upvink+sin_roll*10)*yscale, WHITE);

     vin = abs(i);
     if (vin > 9) vin = 18 - vin;
     sprintf(text,"%d",vin);
     textprintf(active_page, font_med, 
                xcorn+(50-sin_roll*upvink)*xscale-0.5*charx,
                ycorn+(50-cos_roll*upvink)*yscale-0.5*chary, WHITE,
                "%d",vin);
             
     line(active_page, xcorn+(50-sin_roll*upvink+cos_roll*10)*xscale,
     ycorn+(50-cos_roll*upvink-sin_roll*10)*yscale,
     xcorn+(50-sin_roll*upvink+cos_roll*30)*xscale,
     ycorn+(50-cos_roll*upvink-sin_roll*30)*yscale, WHITE);
			
   }
 }

 /* Erase numbers on edge */

 corners[0]=xcorn+(50+sin_roll*HORmax-cos_roll*30)*xscale;
 corners[1]=ycorn+(50+cos_roll*HORmax+sin_roll*30)*yscale;

 corners[2]=xcorn+(50+sin_roll*HORmax+cos_roll*30)*xscale;
 corners[3]=ycorn+(50+cos_roll*HORmax-sin_roll*30)*yscale;

 corners[4]=xcorn+(50+sin_roll*(HORmax+5))*xscale;
 corners[5]=ycorn+(50+cos_roll*(HORmax+5))*yscale;

 polygon(active_page, 3,corners, BLACK);

 corners[0]=xcorn+(50-sin_roll*HORmax-cos_roll*30)*xscale;
 corners[1]=ycorn+(50-cos_roll*HORmax+sin_roll*30)*yscale;

 corners[2]=xcorn+(50-sin_roll*HORmax+cos_roll*30)*xscale;
 corners[3]=ycorn+(50-cos_roll*HORmax-sin_roll*30)*yscale;

 corners[4]=xcorn+(50-sin_roll*(HORmax+5))*xscale;
 corners[5]=ycorn+(50-cos_roll*(HORmax+5))*yscale;

 polygon(active_page, 3,corners, BLACK);


 /* Static "aircraft" */
 line(active_page, xcorn+25*xscale, ycorn+50*yscale,
      xcorn+45*xscale, ycorn+50*yscale, WHITE);
 line(active_page, xcorn+55*xscale, ycorn+50*yscale,
      xcorn+75*xscale, ycorn+50*yscale, WHITE);
}



void show_TANK(int xcorn, int ycorn)
/* Two-needle fuel gauge, but the needles are always showing the same */
{
 float fuelrat = get_aircraft_fuel_qty() / get_aircraft_fuel_capacity();
 float vin = TANK_vin(fuelrat,0);
 float cosv= cos(vin);
 float sinv= sin(vin);
 int corners[8];
 float xscale = xscl * INST_SCALE;
 float yscale = yscl * INST_SCALE;
 const float lang   = 28.0;
 const float bred   =  2.0;

 show_TANK_dial(xcorn,ycorn);

 corners[0]=xcorn+20*xscale;
 corners[1]=ycorn+50*yscale;

 corners[2]=xcorn+(20+sinv*bred+0.75*cosv*lang)*xscale;
 corners[3]=ycorn+(50-cosv*bred+0.75*sinv*lang)*yscale;

 corners[4]=xcorn+(20+cosv*lang)*xscale;
 corners[5]=ycorn+(50+sinv*lang)*yscale;

 corners[6]=xcorn+(20-sinv*bred+0.75*cosv*lang)*xscale;
 corners[7]=ycorn+(50+cosv*bred+0.75*sinv*lang)*yscale;

 polygon(active_page, 4,corners, WHITE);

 vin = TANK_vin(fuelrat,1);
 cosv= cos(vin);
 sinv= sin(vin);

 corners[0]=xcorn+80*xscale;
 corners[1]=ycorn+50*yscale;

 corners[2]=xcorn+(80+sinv*bred+0.75*cosv*lang)*xscale;
 corners[3]=ycorn+(50-cosv*bred+0.75*sinv*lang)*yscale;

 corners[4]=xcorn+(80+cosv*lang)*xscale;
 corners[5]=ycorn+(50+sinv*lang)*yscale;

 corners[6]=xcorn+(80-sinv*bred+0.75*cosv*lang)*xscale;
 corners[7]=ycorn+(50+cosv*bred+0.75*sinv*lang)*yscale;

 polygon(active_page, 4,corners, WHITE);
}



void show_FFLW(int xcorn, int ycorn)
{
 float vin = FFLW_vin(total_fuel_flow*3600.0/3.705, instrum.max_fuel_flow, 5.5*PI/8, 2*PI+2.5*PI/8);
 float cosv= cos(vin);
 float sinv= sin(vin);
 int corners[8];
 float xscale = xscl * INST_SCALE;
 float yscale = yscl * INST_SCALE;
 const float lang   = 45.0;
 const float bred   =  2.0;

 show_FFLW_dial(xcorn,ycorn);

 corners[0]=xcorn+50*xscale;
 corners[1]=ycorn+50*yscale;

 corners[2]=xcorn+(50+sinv*bred+0.75*cosv*lang)*xscale;
 corners[3]=ycorn+(50-cosv*bred+0.75*sinv*lang)*yscale;

 corners[4]=xcorn+(50+cosv*lang)*xscale;
 corners[5]=ycorn+(50+sinv*lang)*yscale;

 corners[6]=xcorn+(50-sinv*bred+0.75*cosv*lang)*xscale;
 corners[7]=ycorn+(50+cosv*bred+0.75*sinv*lang)*yscale;

 polygon(active_page, 4,corners, WHITE);
}



void show_JET_RPM(int xcorn, int ycorn, float rpm)
{
 float xscale = xscl * INST_SCALE;
 float yscale = yscl * INST_SCALE;

 show_JET_RPM_dial(xcorn,ycorn);

 rectfill(active_page, xcorn+10*xscale, ycorn+143*yscale ,
     xcorn+15*xscale, ycorn+(143-JET_RPM_tick(rpm)*135)*yscale, WHITE );
}



void show_JET_EGT(int xcorn, int ycorn, float egt)
{
 float xscale = xscl * INST_SCALE;
 float yscale = yscl * INST_SCALE;

 show_JET_EGT_dial(xcorn,ycorn);

 rectfill(active_page, xcorn+10*xscale, ycorn+143*yscale ,
     xcorn+15*xscale, ycorn+(143-JET_EGT_tick(egt)*135)*yscale, WHITE );
}



void show_JET_FFLW(int xcorn, int ycorn, float fflw)
{
 float xscale = xscl * INST_SCALE;
 float yscale = yscl * INST_SCALE;

 show_JET_FFLW_dial(xcorn,ycorn);

 rectfill(active_page, xcorn+10*xscale, ycorn+143*yscale ,
     xcorn+15*xscale, ycorn+(143-JET_FFLW_tick(fflw)*135)*yscale, WHITE );
}



void show_GEAR(int xcorn, int ycorn)
{
 float xscale = xscl * INST_SCALE;
 float yscale = yscl * INST_SCALE;
 int i;
 float maxdim = 0;
 float skala;
 int charx, chary;
 float xcg = 0;
 int color = BLACK;

 show_GEAR_dial(xcorn,ycorn);

 for (i=0 ; i<ngears ; i++)
   xcg += gear[i].hingepos.x;
 xcg /= ngears;

 for (i=0 ; i<ngears ; i++) {
  if (fabs(gear[i].hingepos.x-xcg) > maxdim)
     maxdim = fabs(gear[i].hingepos.x);
  if (fabs(gear[i].hingepos.y) > maxdim)
     maxdim = fabs(gear[i].hingepos.y);
 }

 if (hook.exists) {
   if (fabs(hook.hingepos.x) > maxdim)
     maxdim = fabs(hook.hingepos.x);
 }

 if (airbrake.area > 0) {

 }

 skala = 30.0 / maxdim;

 charx=text_length(font_med,"M");
 chary=text_height(font_med);

 for (i=0 ; i<ngears ; i++) {
  if (gear[i].down==1) color = LIGHTGREEN;
  if (gear[i].down==0) color = BLACK;
  if (gear[i].down>0 && gear[i].down<1) color = YELLOW;
  if ( ((whlbrakes==true) && (gear[i].brakeeffect>0)) || (gear[i].skid==true) )
    textout(active_page, font_med, "W", 
            xcorn+((gear[i].hingepos.y*skala)+50)*xscale-0.5*charx,
            ycorn-(((gear[i].hingepos.x-xcg)*skala)-50)*yscale-0.5*chary, color);
  else
    textout(active_page, font_med, "G", 
            xcorn+((gear[i].hingepos.y*skala)+50)*xscale-0.5*charx,
            ycorn-(((gear[i].hingepos.x-xcg)*skala)-50)*yscale-0.5*chary, color);
 }

 if (hook.exists) {
   if (hook.down==1) color = LIGHTGREEN;
   if (hook.down==0) color = BLACK;
   if (hook.down>0 && hook.down<1) color = YELLOW;
   textout(active_page, font_med, "H", xcorn+50*xscale-0.5*charx,ycorn+80*yscale-0.5*chary, color);
 }

 if (airbrake.area > 0) {
   if (airbrake.out==1) color = LIGHTGREEN;
   if (airbrake.out==0) color = BLACK;
   if (airbrake.out>0 && airbrake.out<1) color = YELLOW;
   textout(active_page, font_med, "B", xcorn+50*xscale-0.5*charx, ycorn+90*yscale-0.5*chary, color);
 }
}



void showvector(int xcorn, int ycorn , float skala)
{
 float vin,dx,dy;
 const float inner=45;
 const float outher=50;

 /* Only shown for the first engine */
 for (vin=jengine[0].vectoruplim ; vin<=jengine[0].vectordnlim ; vin=vin+15 )
 {
  dx=cos(vin*PI/180);
  dy=sin(vin*PI/180);
  line(active_page, xcorn+inner*dx*skala*xscl,ycorn+inner*dy*skala*yscl,
    xcorn+outher*dx*skala*xscl,ycorn+outher*dy*skala*yscl, LIGHTGREEN);
 }
 vin=jengine[0].vectordnlim;
 dx=cos(vin*PI/180);
 dy=sin(vin*PI/180);
 line(active_page, xcorn+inner*dx*skala*xscl,ycorn+inner*dy*skala*yscl,
   xcorn+outher*dx*skala*xscl,ycorn+outher*dy*skala*yscl, LIGHTGREEN);

 dx=cos(jengine[0].vectordesire*PI/180);
 dy=sin(jengine[0].vectordesire*PI/180);
 line(active_page, xcorn,ycorn,
   xcorn+outher*dx*skala*xscl,ycorn+outher*dy*skala*yscl, LIGHTGREEN);
 dx=cos(jengine[0].vectorpos*PI/180);
 dy=sin(jengine[0].vectorpos*PI/180);
 line(active_page, xcorn,ycorn, 
   xcorn+outher*dx*skala*xscl,ycorn+outher*dy*skala*yscl, LIGHTRED);
}



void showgear(int xcorn,int ycorn, float skala)
/* HUD-like version */
{
 int i;
 int color=0;

 for (i=0 ; i<ngears ; i++) {
  if (gear[i].down==1) color = YELLOW;
  if (gear[i].strokepos > 0) color = LIGHTGREEN;
  if (gear[i].down==0) color = LIGHTGRAY;
  if (gear[i].down>0 && gear[i].down<1) color = LIGHTRED;
  if ( ((whlbrakes==true) && (gear[i].brakeeffect>0)) || (gear[i].skid==true) )
    textout(active_page, font_med, "W",
    xcorn+gear[i].hingepos.y*skala*xscl,ycorn-gear[i].hingepos.x*skala*yscl,
    color);
  else
    textout(active_page, font_med, "G",
    xcorn+gear[i].hingepos.y*skala*xscl,ycorn-gear[i].hingepos.x*skala*yscl,
    color);
 }
}



void showhook(int xcorn,int ycorn, float skala)
{
 int color=0;

 if (hook.down==1) color = YELLOW;
 if (hook.down==0) color = LIGHTGRAY;
 if (hook.down>0 && hook.down<1) color =  LIGHTRED;
 textout(active_page, font_med, "H",
    xcorn-hook.hingepos.y*skala*xscl,ycorn-hook.hingepos.x*skala*yscl,
    color);
}



void showairbrake(int xcorn,int ycorn)
{
 int color=0;

 if (airbrake.out==1) color = YELLOW;
 if (airbrake.out==0) color = LIGHTGRAY;
 if (airbrake.out>0 && airbrake.out<1) color = LIGHTRED;
 textout(active_page, font_med, "B", xcorn,ycorn, color);
}



void bank_indicator()
{
 int i;
 float dial_rad=60;
 float dial_height=150;

 int angles[]={0,10,20,30,45,60};
 int length[]={6,3,3,6,3,6};

 float droll, droll_l, droll_r;
 float cos_roll, sin_roll;
 float cos_roll_l, sin_roll_l;
 float cos_roll_r, sin_roll_r;
 bool drawit = true;

 for (i=0; i<6; i++) {
  float cosang=int_cos[angles[i]];
  float sinang=int_sin[angles[i]];

  line(active_page, 
  xcenter+dial_rad*xscl*sinang, ycenter+(dial_height+dial_rad*cosang)*yscl,
  xcenter+(dial_rad+length[i])*xscl*sinang, ycenter+(dial_height+(dial_rad+length[i])*cosang)*yscl, LIGHTGREEN);

  if (i>0) {
	line(active_page,
    xcenter-dial_rad*xscl*sinang, ycenter+(dial_height+dial_rad*cosang)*yscl,
    xcenter-(dial_rad+length[i])*xscl*sinang, ycenter+(dial_height+(dial_rad+length[i])*cosang)*yscl, LIGHTGREEN);
  }
 }

 if (fabs(roll) > PI/3) {
   #define flash_freq 3
   long int elap_sec = elapsed_time*3600*flash_freq;

   droll=sgn(roll)*PI/3;

   if (elapsed_time*3600*flash_freq - elap_sec > 0.5)
     drawit=false;
 }
 else
   droll=roll;

 if (drawit) {
   droll_l = droll + 0.03;
   droll_r = droll - 0.03;

   cos_roll     = cos(droll);
   sin_roll     = sin(droll);
   cos_roll_l   = cos(droll_l);
   sin_roll_l   = sin(droll_l);
   cos_roll_r   = cos(droll_r);
   sin_roll_r   = sin(droll_r);

   line(active_page,
   xcenter+(dial_rad-7)*xscl*sin_roll_l, ycenter+(dial_height+(dial_rad-7)*cos_roll_l)*yscl,
   xcenter+dial_rad*xscl*sin_roll, ycenter+(dial_height+dial_rad*cos_roll)*yscl, LIGHTGREEN);
   line(active_page,
   xcenter+dial_rad*xscl*sin_roll, ycenter+(dial_height+dial_rad*cos_roll)*yscl,
   xcenter+(dial_rad-7)*xscl*sin_roll_r, ycenter+(dial_height+(dial_rad-7)*cos_roll_r)*yscl, LIGHTGREEN);
 }
}



void pitch_ladder()
{
 #define dist 10

 const float degtorad = PI/180;
 int i;
 float nvx,nvy,normfak,upvink;
 float side1,side2;
 char ladderid[]="00";
 cartvektor textscrpos,text3dpos;

 /* Nose-up lines 3D-Draw */

 /* normeret hastigheds-vektor projiceret paa x-y plan */
 normfak=sqrt(SQR(v_air.x)+SQR(v_air.y));
 if (normfak != 0){
  nvx=v_air.x/normfak;
  nvy=v_air.y/normfak;

  /* Horizon marker */
  side1=.2;
  side2=.9;
  draw3d(viewx+dist*nvx-side1*nvy,viewy+dist*nvy+side1*nvx,viewz
	 ,viewx+dist*nvx-side2*nvy,viewy+dist*nvy+side2*nvx,viewz, hud_white);
  side1=-.2;
  side2=-.9;
  draw3d(viewx+dist*nvx-side1*nvy,viewy+dist*nvy+side1*nvx,viewz
	 ,viewx+dist*nvx-side2*nvy,viewy+dist*nvy+side2*nvx,viewz, hud_white);


  for (i=1; i<17; i++)
  {
   if ((fabs(nosealt*180/PI-i*10) < 20) && i!= 9) /* omtrent indenfor skaerm? */
   {
    float cos_upvink1_dist, sin_upvink1_dist, cos_upvink2_dist, sin_upvink2_dist;
    upvink=PI*i*10/180;

    cos_upvink1_dist=cos(upvink)*dist;
    sin_upvink1_dist=sin(upvink)*dist;
    cos_upvink2_dist=cos_upvink1_dist;
    sin_upvink2_dist=sin_upvink1_dist;


    side1=.2;
    side2=.6;
    draw3d(viewx+cos_upvink1_dist*nvx-side1*nvy,viewy+cos_upvink1_dist*nvy+side1*nvx,viewz+sin_upvink1_dist
	   ,viewx+cos_upvink2_dist*nvx-side2*nvy,viewy+cos_upvink2_dist*nvy+side2*nvx,viewz+sin_upvink2_dist, hud_blue);


    side1=-.2;
    side2=-.6;
    draw3d(viewx+cos_upvink1_dist*nvx-side1*nvy,viewy+cos_upvink1_dist*nvy+side1*nvx,viewz+sin_upvink1_dist
	   ,viewx+cos_upvink2_dist*nvx-side2*nvy,viewy+cos_upvink2_dist*nvy+side2*nvx,viewz+sin_upvink2_dist, hud_blue);

    side1=-.75;
    side2=-.75;
    text3dpos.x=viewx+cos_upvink2_dist*nvx-side2*nvy;
    text3dpos.y=viewy+cos_upvink2_dist*nvy+side2*nvx;
    text3dpos.z=viewz+sin_upvink2_dist;
    textscrpos=scrpos3d(text3dpos);
    if (textscrpos.z==1) {
       if (i<10) ladderid[0]=48+i;
       else ladderid[0]=38+i;
       textout(active_page, font_med, ladderid, textscrpos.x,textscrpos.y, hud_blue);
    }

    cos_upvink2_dist=cos(upvink-.5*degtorad)*dist;
    sin_upvink2_dist=sin(upvink-.5*degtorad)*dist;
    side1=.2;
    side2=.2;
    draw3d(viewx+cos_upvink1_dist*nvx-side1*nvy,viewy+cos_upvink1_dist*nvy+side1*nvx,viewz+sin_upvink1_dist
	   ,viewx+cos_upvink2_dist*nvx-side2*nvy,viewy+cos_upvink2_dist*nvy+side2*nvx,viewz+sin_upvink2_dist, hud_blue);

    side1=-.2;
    side2=-.2;
    draw3d(viewx+cos_upvink1_dist*nvx-side1*nvy,viewy+cos_upvink1_dist*nvy+side1*nvx,viewz+sin_upvink1_dist
	   ,viewx+cos_upvink2_dist*nvx-side2*nvy,viewy+cos_upvink2_dist*nvy+side2*nvx,viewz+sin_upvink2_dist, hud_blue);
   }
  }
  /* Nose-down lines */
  for (i=1; i<17; i++)
  {
   if ((fabs(nosealt*180/PI+i*10) < 20) && i!= 9) /* omtrent indenfor skaerm? */
   {
    float cos_upvink1_dist, sin_upvink1_dist, cos_upvink2_dist, sin_upvink2_dist;
    upvink=-PI*i*10/180;

    /* One could use: */
    /*setlinestyle(USERBIT_LINE, 255, 1);*/

    cos_upvink1_dist=cos(upvink)*dist;
    sin_upvink1_dist=sin(upvink)*dist;
    cos_upvink2_dist=cos_upvink1_dist;
    sin_upvink2_dist=sin_upvink1_dist;

    side1=.2;
    side2=.28;
    draw3d(viewx+cos_upvink1_dist*nvx-side1*nvy,viewy+cos_upvink1_dist*nvy+side1*nvx,viewz+sin_upvink1_dist
	   ,viewx+cos_upvink2_dist*nvx-side2*nvy,viewy+cos_upvink2_dist*nvy+side2*nvx,viewz+sin_upvink2_dist, hud_red);

    side1=-.2;
    side2=-.28;
    draw3d(viewx+cos_upvink1_dist*nvx-side1*nvy,viewy+cos_upvink1_dist*nvy+side1*nvx,viewz+sin_upvink1_dist
	   ,viewx+cos_upvink2_dist*nvx-side2*nvy,viewy+cos_upvink2_dist*nvy+side2*nvx,viewz+sin_upvink2_dist, hud_red);

    side1=.36;
    side2=.44;
    draw3d(viewx+cos_upvink1_dist*nvx-side1*nvy,viewy+cos_upvink1_dist*nvy+side1*nvx,viewz+sin_upvink1_dist
	   ,viewx+cos_upvink2_dist*nvx-side2*nvy,viewy+cos_upvink2_dist*nvy+side2*nvx,viewz+sin_upvink2_dist, hud_red);

    side1=-.36;
    side2=-.44;
    draw3d(viewx+cos_upvink1_dist*nvx-side1*nvy,viewy+cos_upvink1_dist*nvy+side1*nvx,viewz+sin_upvink1_dist
	   ,viewx+cos_upvink2_dist*nvx-side2*nvy,viewy+cos_upvink2_dist*nvy+side2*nvx,viewz+sin_upvink2_dist, hud_red);

    side1=.52;
    side2=.6;
    draw3d(viewx+cos_upvink1_dist*nvx-side1*nvy,viewy+cos_upvink1_dist*nvy+side1*nvx,viewz+sin_upvink1_dist
	   ,viewx+cos_upvink2_dist*nvx-side2*nvy,viewy+cos_upvink2_dist*nvy+side2*nvx,viewz+sin_upvink2_dist, hud_red);

    side1=-.52;
    side2=-.6;
    draw3d(viewx+cos_upvink1_dist*nvx-side1*nvy,viewy+cos_upvink1_dist*nvy+side1*nvx,viewz+sin_upvink1_dist
	   ,viewx+cos_upvink2_dist*nvx-side2*nvy,viewy+cos_upvink2_dist*nvy+side2*nvx,viewz+sin_upvink2_dist, hud_red);

    side1=-.75;
    side2=-.75;
    text3dpos.x=viewx+cos_upvink2_dist*nvx-side2*nvy;
    text3dpos.y=viewy+cos_upvink2_dist*nvy+side2*nvx;
    text3dpos.z=viewz+sin_upvink2_dist;
    textscrpos=scrpos3d(text3dpos);
    if (textscrpos.z==1) {
       if (i<10) ladderid[0]=48+i;
       else ladderid[0]=38+i;
       textout(active_page, font_med, ladderid, textscrpos.x,textscrpos.y, hud_red);
    }

    cos_upvink2_dist=cos(upvink+.5*degtorad)*dist;
    sin_upvink2_dist=sin(upvink+.5*degtorad)*dist;

    side1=.2;
    side2=.2;
    draw3d(viewx+cos_upvink1_dist*nvx-side1*nvy,viewy+cos_upvink1_dist*nvy+side1*nvx,viewz+sin_upvink1_dist
	   ,viewx+cos_upvink2_dist*nvx-side2*nvy,viewy+cos_upvink2_dist*nvy+side2*nvx,viewz+sin_upvink2_dist, hud_red);

    side1=-.2;
    side2=-.2;
    draw3d(viewx+cos_upvink1_dist*nvx-side1*nvy,viewy+cos_upvink1_dist*nvy+side1*nvx,viewz+sin_upvink1_dist
	   ,viewx+cos_upvink2_dist*nvx-side2*nvy,viewy+cos_upvink2_dist*nvy+side2*nvx,viewz+sin_upvink2_dist, hud_red);
   }
  }
 }
}



void show_controls()
{
 float xx,yy;

 /* Forward-cross */
 line(active_page, 315*xscl,240*yscl,325*xscl,240*yscl, LIGHTGRAY);
 line(active_page, 320*xscl,235*yscl,320*xscl,245*yscl, LIGHTGRAY);

 /* Joystick position */
 xx=xcenter+joyx/2;
 yy=ycenter+joyy/2;
 line(active_page, xx+3*xscl,yy+3*yscl,xx-3*xscl,yy-3*yscl, LIGHTRED);
 line(active_page, xx+3*xscl,yy-3*yscl,xx-3*xscl,yy+3*yscl, LIGHTRED);

 /* Rudder position */
 line(active_page, xcenter+rudder*2,ycenter-3*yscl,xcenter+rudder*2,ycenter+3*yscl, LIGHTRED);
}



void show_trim(int xcent, int ycent, float skala)
{
 #define TRIMWID 5

 float xscale = xscl*skala;
 float yscale = yscl*skala;

 line(active_page, xcent-50*xscale,ycent,xcent+50*xscale,ycent, LIGHTGRAY);
 line(active_page, xcent,ycent-50*yscale,xcent,ycent+50*yscale, LIGHTGRAY);
 line(active_page, xcent-50*xscale,ycent+60*yscale,xcent+50*xscale,ycent+60*yscale, LIGHTGRAY);

 line(active_page, xcent-TRIMWID*xscale,ycent-0.167*elevatortrim*yscale,xcent+TRIMWID*xscale,ycent-0.167*elevatortrim*yscale, LIGHTRED);
 line(active_page, xcent+0.50*ailerontrim*xscale,ycent-TRIMWID*yscale,xcent+0.50*ailerontrim*xscale,ycent+TRIMWID*yscale, LIGHTRED);
 line(active_page, xcent+0.50*ruddertrim*xscale,ycent+(60-TRIMWID)*yscale,xcent+0.50*ruddertrim*xscale,ycent+(60+TRIMWID)*yscale, LIGHTRED);
}



void gunsight()
{
 line(active_page, 310*xscl,240*yscl,317*xscl,240*yscl, LIGHTGREEN);
 line(active_page, 320*xscl,230*yscl,320*xscl,237*yscl, LIGHTGREEN);
 line(active_page, 323*xscl,240*yscl,330*xscl,240*yscl, LIGHTGREEN);
 line(active_page, 320*xscl,243*yscl,320*xscl,250*yscl, LIGHTGREEN);
}



void AoA_indexer(int xpos, int ypos) {
/* Approach indexer */
 if (gear[0].down==1 && (HUDmode==ILS || HUDmode==NAVIGATION) ) {
    if (fabs(desired_ldg_AOA-pitch*180/PI) < 0.8) {
       circle(active_page, xpos*xscl,ypos,4*xscl, YELLOW);
    }
    if (pitch*180/PI-desired_ldg_AOA >  0.4) {
       line(active_page,(xpos-4)*xscl,ypos-16*yscl,
       (xpos-2)*xscl,ypos-8*yscl, LIGHTGREEN);
       line(active_page,(xpos+4)*xscl,ypos-16*yscl,
       (xpos+2)*xscl,ypos-8*yscl, LIGHTGREEN);

    }
    if (pitch*180/PI-desired_ldg_AOA < -0.4) {
       line(active_page,(xpos-4)*xscl,ypos+16*yscl,
       (xpos-2)*xscl,ypos+8*yscl, LIGHTRED);
       line(active_page,(xpos+4)*xscl,ypos+16*yscl,
       (xpos+2)*xscl,ypos+8*yscl, LIGHTRED);
    }
 }
}



void target_box()
{	
 cartvektor target_pos = scrpos3d(target[selected_target].pos);

 if (target_pos.z == 1) {
	rect(active_page, target_pos.x-10*xscl,target_pos.y-10*yscl,
	target_pos.x+10*xscl,target_pos.y+10*yscl, LIGHTGREEN);   
 }
}



void target_info()
{
  /*
     Calculates and displays:
     Distance to target
     Target closure speed
     Target relative heading, projected in the horizontal plane
     Target aspect
  */
	
  float tgt_dist =  sqrt(SQR(target[selected_target].pos.x - x) +
                         SQR(target[selected_target].pos.y - y) +
                         SQR(target[selected_target].pos.z - z));
  cartvektor target_pos = scrpos3d(target[selected_target].pos);
  cartvektor tgtvect, ownpos, tgtyzvect;
  float closure, normfak, aspect;
  float tgtvhor, tgthead;
	int charx,chary;

  ownpos.x=x;
  ownpos.y=y;
  ownpos.z=z;

	charx=text_length(font_med,"M");
  chary=text_height(font_med);

  tgtvect=vminus(target[selected_target].pos, ownpos);
  normfak=1/sqrt(SQR(tgtvect.x)+SQR(tgtvect.y)+SQR(tgtvect.z));
  tgtvect=svmult(normfak, tgtvect);

  /* Closure */
  closure  = VPRIK(v, tgtvect);
  closure -= VPRIK(target[selected_target].vel, tgtvect);

  /* Target heading relative to own heading */
  tgtvhor  = sqrt( SQR(target[selected_target].vel.x) + SQR(target[selected_target].vel.y) );

  if (tgtvhor > 0.1) {
    float normtgtvx = target[selected_target].vel.x / tgtvhor;
    float normtgtvy = target[selected_target].vel.y / tgtvhor;
    float coshead, sinhead;

    tgthead = arccos(normtgtvx);
    if (normtgtvy < 0) tgthead = -tgthead;

    tgthead -= azi;

    coshead=cos(tgthead);
    sinhead=sin(tgthead);

    tgthead *= 180.0/PI;
    if (tgthead >  180) tgthead -=360;
    if (tgthead < -180) tgthead +=360;

    if (target_pos.z == 1) {
     line(active_page, target_pos.x-15*sinhead*xscl, target_pos.y-15*coshead*yscl,
     target_pos.x-22*sinhead*xscl, target_pos.y-22*coshead*yscl, LIGHTGREEN);
    }
  }
  else
    tgthead = 0;

  /* Aspect */
  if (target[selected_target].rad > 0.1 ) {
    float cosasp, sinasp;
    float cosasp2, sinasp2;
    float cosasp3, sinasp3;
    cartvektor tgtprojvect;

    tgtprojvect.x = VPRIK( target[selected_target].front, tgtvect );
    tgtprojvect.y = VPRIK( target[selected_target].left , tgtvect );
    tgtprojvect.z = 0;

    normfak = sqrt( SQR(tgtprojvect.x) + SQR(tgtprojvect.y) );
    tgtprojvect = svmult(1./normfak, tgtprojvect);

    aspect = arccos( tgtprojvect.x );

    if ( tgtprojvect.y > 0 )
       aspect = -aspect;

    cosasp  = tgtprojvect.x; /* = cos(aspect) */
    sinasp  = sin(aspect);
    cosasp2 = cos(aspect + (PI*5.0/180) );
    sinasp2 = sin(aspect + (PI*5.0/180) );
    cosasp3 = cos(aspect - (PI*5.0/180) );
    sinasp3 = sin(aspect - (PI*5.0/180) );

    if (target_pos.z == 1) {
     line( active_page, target_pos.x+27*sinasp2*xscl, target_pos.y+27*cosasp2*yscl,
     target_pos.x+20*sinasp *xscl, target_pos.y+20*cosasp *yscl, LIGHTGREEN);
     line( active_page, target_pos.x+20*sinasp *xscl, target_pos.y+20*cosasp *yscl,
	 target_pos.x+27*sinasp3*xscl, target_pos.y+27*cosasp3*yscl, LIGHTGREEN);
    }

    aspect *= 180.0/PI;
    aspect += 180.0;
    if (aspect >  180) aspect -=360;
    if (aspect < -180) aspect +=360;
  }
  else
    aspect = 0;

  /* Target direction pointer */
  /* Don't draw pointer if the target is almost dead ahead */
  if (VPRIK(tgtvect, front) < 0.99) {
    tgtyzvect.z = VPRIK(top , tgtvect);
    tgtyzvect.y = VPRIK(left, tgtvect);
    tgtyzvect.x = 0;
    normfak = sqrt( SQR(tgtyzvect.z) + SQR(tgtyzvect.y) );
    if (normfak > 1e-9) {
      tgtyzvect = svmult( -1./normfak, tgtyzvect);
      line(active_page, xcenter,ycenter,
      xcenter+tgtyzvect.y*20*xscl, ycenter+tgtyzvect.z*20*yscl, LIGHTGREEN);
    }
  }
 
  textout(active_page, font_med, "R", 445*xscl,330*yscl, LIGHTGREEN);
	printfg(active_page, font_med, 10*tgt_dist/1852, 4, 4, 445*xscl+3*charx,330*yscl, LIGHTGREEN);

  textout(active_page, font_med, "C", 445*xscl,340*yscl, LIGHTGREEN);
  printg(active_page, font_med, closure/0.5144,4, 445*xscl+3*charx,340*yscl, LIGHTGREEN);

  
	printg(active_page, font_med, (int)fabs(aspect), 3, 445*xscl+3*charx,350*yscl, LIGHTGREEN);
  if (aspect > 0)
    textout(active_page, font_med, "A     R", 445*xscl,350*yscl, LIGHTGREEN);
  else
    textout(active_page, font_med, "A     L", 445*xscl,350*yscl, LIGHTGREEN);
}



void hud()
{
 float xx,yy;
 float xpixperdeg=xpixperrad*PI/180;
 float ypixperdeg=ypixperrad*PI/180;
 int i;
 long j;
 float ias;
 int iasmin,iasmax;
 float alt,climb;
 long altmin, altmax;
 float head;
 int headmax,headmin,deghead;
 int comp_tck_1, comp_tck_5, comp_tck_num, comp_all_y, comp_hdg_y;
 int wpt_y1, wpt_y2, wpt_y3;
 int hudcolor=LIGHTGREEN;
 int vvi_col;
 int charx, chary;

 typedef struct {
	float x,y;
	} scrcoord;

 scrcoord degvert,heading;

 charx=text_length(font_med,"M");
 chary=text_height(font_med);

 heading.x=xcenter+nosealt*xpixperrad*sin(roll);
 heading.y=ycenter+nosealt*ypixperrad*cos(roll);

 degvert.x=-sin(roll)*xpixperdeg;
 degvert.y=-cos(roll)*ypixperdeg;

 /* No erasing needed - is done in 'outside' */
 xx=xcenter-avg_yaw*xpixperrad;
 yy=ycenter+avg_pitch*ypixperrad;
 circle(active_page, xx,yy,3.5*xscl, LIGHTGREEN);
 line(active_page, xx+3.5*xscl,yy,xx+8*xscl,yy, LIGHTGREEN);
 line(active_page, xx-3.5*xscl,yy,xx-8*xscl,yy, LIGHTGREEN);
 line(active_page, xx,yy-3.5*yscl,xx,yy-6*yscl, LIGHTGREEN);

 if (!show_ctrlpos) {
    /* Forward-cross */
    line(active_page, 318*xscl,240*yscl,322*xscl,240*yscl, LIGHTGREEN);
    line(active_page, 320*xscl,238*yscl,320*xscl,242*yscl, LIGHTGREEN);
 }

 pitch_ladder();

 /* Zenith marker */
 if (fabs(nosealt*180/PI-90) < 20)
 {
   circle(active_page, heading.x+degvert.x*90,heading.y+degvert.y*90,5*xscl, hud_blue);
 }

 /* Nadir marker */
 if (fabs(nosealt*180/PI+90) < 20)
  {
   float xc=heading.x-degvert.x*90;
   float yc=heading.y-degvert.y*90;

   circle(active_page, xc,yc,5, hud_red);
   line(active_page, xc-3*xscl,yc-3*yscl,xc+3*xscl,yc+3*yscl, hud_red);
   line(active_page, xc-3*xscl,yc+3*yscl,xc+3*xscl,yc-3*yscl, hud_red);
  }

 /* Airspeed ladder, displaying IAS */
 line(active_page, 200*xscl,240*yscl,210*xscl,240*yscl, LIGHTGREEN);


 ias=tas/sqrt(1.225/atmospheric_density(z));
 iasmax=ias/10+8;
 iasmin=ias/10-7;
 
 for (i=iasmin; i<iasmax; i++)
  {
   
   if(fmod(i,5)==0)
    {
	 line(active_page,200*xscl,(240-(i*10-ias)/2)*yscl, 190*xscl,(240-(i*10-ias)/2)*yscl, LIGHTGREEN);
     printg(active_page, font_med, i,2, 175*xscl,(235-(i*10-ias)/2)*yscl+0.5*chary, LIGHTGREEN);
    }
    else line(active_page,200*xscl,(240-(i*10-ias)/2)*yscl, 195*xscl,(240-(i*10-ias)/2)*yscl, LIGHTGREEN);
  }

 /* Print TAS */
 printg(active_page, font_med, tas,4, 180*xscl,290*yscl, LIGHTGREEN);

 printfg(active_page, font_med, aircraft_mach_number*100,3,2, 180*xscl,300*yscl, LIGHTGREEN);

 /* Altitude ladder, displaying feet MSL */
 line(active_page, 440*xscl,240*yscl,435*xscl,240*yscl, LIGHTGREEN);

 alt=z/0.3048; /* Meter per feet */
 altmax=alt/100+8;
 altmin=alt/100-8;
 for (j=altmin; j<altmax; j++)
  {
   if(j>0) hudcolor=LIGHTGREEN;
	else hudcolor=hud_red;
   if(fmod(j,5)==0)
    {
     line(active_page, 440*xscl,(240-(j*100-alt)/20)*yscl, 450*xscl,(240-(j*100-alt)/20)*yscl, hudcolor);
     printg(active_page, font_med, j,3, 460*xscl,(235-(j*100-alt)/20)*yscl+0.5*chary, hudcolor);
    }
    else line(active_page, 440*xscl,(240-(j*100-alt)/20)*yscl, 445*xscl,(240-(j*100-alt)/20)*yscl, hudcolor);
  }

 /* Print ALT */
 printg(active_page, font_med, alt,6,445*xscl,290*yscl, hudcolor);

 /* VVI-bar */
 climb=v.z/0.3048;  /* Feet per second */

 if (climb>0) vvi_col = hud_blue;
	else vvi_col=hud_red;

 printg(active_page, font_med, climb,3, 445*xscl+3*charx,300*yscl, vvi_col);

 if (climb>100) climb=100;
 if (climb<-100) climb=-100;
 rectfill(active_page, 433*xscl,240*yscl,435*xscl,(240-climb)*yscl, vvi_col);
 if (fabs(climb)==100) {
   line(active_page, 433*xscl,(240-climb)*yscl,435*xscl,(240-climb)*yscl, WHITE);
 }

 /* Altitude above Ground Level */
 {
  float agl    = z-groundalt(x,y);
  bool critical = false;

  /* Impact within 5 seconds? */
  if ( agl + 5.0*((agl-lastgroundalt)/dtperframe) < 0.0)
     critical = true;
  lastgroundalt = agl;

  agl /= 0.3048;

  if (agl < 300 || critical)
     vvi_col=hud_red;
  else
     vvi_col=LIGHTGREEN;

  if (agl < 3000)
    printg(active_page, font_med, agl,4, 445*xscl+2*charx,310*yscl, vvi_col);

  if (critical && gear[0].down < 1) {
     #define flash_freq 3
     long int elap_sec = elapsed_time*3600*flash_freq;

     if (elapsed_time*3600*flash_freq - elap_sec > 0.5)
        textout(active_page, font_med, "PULL UP", 320*xscl-3.5*charx,220*yscl, vvi_col);

     if ( (elapsed_time-last_warn_time) > (1.5/3600) && stall_horn_on) {
        last_warn_time=elapsed_time;
          play_rdo_wav(WARNING_WAV, 255, 128, 1000);
     }
  }
 }

 /* Compass */
 if (HUDmode==AIRAIR) {
    comp_tck_1   = 325*yscl;
    comp_tck_5   = 330*yscl;
    comp_tck_num = 332*yscl;
    comp_all_y   = 320*yscl;
    comp_hdg_y   = 310*yscl;
    wpt_y1       = 312*yscl;
    wpt_y2       = 315*yscl;
    wpt_y3       = 318*yscl;
 }
 else {
    comp_tck_1   = 175*yscl;
    comp_tck_5   = 170*yscl;
    comp_tck_num = (168-text_height(font_med))*yscl;
    comp_all_y   = 180*yscl;
    comp_hdg_y   = 190*yscl;
    wpt_y1       = 188*yscl;
    wpt_y2       = 185*yscl;
    wpt_y3       = 182*yscl;
 }

 line(active_page, 320*xscl,comp_hdg_y,320*xscl,comp_all_y, LIGHTGREEN);

 head=-azi*180/PI; /* Azimuth increases counter-clockwise, heading clockwise */
 headmax=head+8;
 headmin=head-7;
 for (i=headmin; i<headmax; i++)
  {
   if(fmod(i,5)==0)
    {
     line(active_page, xcenter+(i-head)*xpixperdeg,comp_all_y,
                       xcenter+(i-head)*xpixperdeg,comp_tck_5, LIGHTGREEN);
    }
   if(fmod(i,10)==0)
    {
     deghead=i;
     if (deghead<0) deghead+=360;
     if (deghead>=360) deghead-=360;
     printg(active_page, font_med, deghead/10,2, 315*xscl+(i-head)*xpixperdeg,comp_tck_num, LIGHTGREEN);
    }
    else line(active_page, xcenter+(i-head)*xpixperdeg,comp_all_y,
                           xcenter+(i-head)*xpixperdeg,comp_tck_1, LIGHTGREEN);
  }

 /* Waypoint */
 if (HUDmode!=AIRAIR) {
  float offset;
  float distance=sqrt(SQR(waypointlst[active_waypoint].pos.x-x)+
                      SQR(waypointlst[active_waypoint].pos.y-y));
  float bearing=arccos((waypointlst[active_waypoint].pos.x-x)/distance)*180/PI;
  float speed_to_wpt, sec_to_wpt;
  bool time_out=true;
  int minutes, seconds;

  if((waypointlst[active_waypoint].pos.y-y) > 0) bearing=-bearing;

  offset=bearing-head;
  if (offset>= 180) offset-=360;
  if (offset<=-180) offset+=360;

  if (fabs(offset)<8) {
   line(active_page, xcenter+offset*xpixperdeg, wpt_y3,
                     xcenter+(offset+0.2)*xpixperdeg,wpt_y1, LIGHTGREEN);
   line(active_page, xcenter+offset*xpixperdeg, wpt_y3,
                     xcenter+(offset-0.2)*xpixperdeg,wpt_y1, LIGHTGREEN);
  }
  if (offset < -8) {
   line(active_page, xcenter-8*xpixperdeg,  wpt_y2,
                     xcenter-7.6*xpixperdeg,wpt_y1, LIGHTGREEN);
   line(active_page, xcenter-8*xpixperdeg,  wpt_y2,
                     xcenter-7.6*xpixperdeg,wpt_y3, LIGHTGREEN);
  }
  if (offset > 8) {
   line(active_page, xcenter+8*xpixperdeg,  wpt_y2,
                     xcenter+7.6*xpixperdeg,wpt_y1, LIGHTGREEN);
   line(active_page, xcenter+8*xpixperdeg,  wpt_y2,
                     xcenter+7.6*xpixperdeg,wpt_y3, LIGHTGREEN);
  }

     printg(active_page, font_med, active_waypoint+1,2, 445*xscl,330*yscl, LIGHTGREEN);

     textout(active_page, font_med, waypointlst[active_waypoint].ident, 460*xscl,330*yscl, LIGHTGREEN);

     printg(active_page, font_med, distance/1852.0,3, 445*xscl,340*yscl, LIGHTGREEN);

     if (bearing < 0) bearing+=360;
     printg(active_page, font_med, bearing,3, 445*xscl+4*charx,340*yscl, LIGHTGREEN);

     speed_to_wpt=(v.x*(waypointlst[active_waypoint].pos.x-x)+
                v.y*(waypointlst[active_waypoint].pos.y-y))/distance;
     if (speed_to_wpt > 0)
        sec_to_wpt=distance/speed_to_wpt;
     else
        sec_to_wpt=1e9;
     minutes=sec_to_wpt/60;
     seconds=sec_to_wpt-minutes*60;
     if (minutes<100) time_out=false;

     if (!time_out)
        printg(active_page, font_med, minutes,2, 445*xscl,350*yscl, LIGHTGREEN);
     else
        textout(active_page, font_med, "--", 445*xscl,350*yscl, LIGHTGREEN);
		 textout(active_page, font_med, ":", 445*xscl+2*charx,350*yscl, LIGHTGREEN);
     if (!time_out)
        printg(active_page, font_med, seconds,2, 445*xscl+3*charx,350*yscl, LIGHTGREEN);
     else
        textout(active_page, font_med, "--", 445*xscl+3*charx,350*yscl, LIGHTGREEN);
 }

 /* Show G-load */
 printfg(active_page, font_med, gpull*10+0.5,3,3, 180*xscl,170*yscl, LIGHTGREEN); /* +0.5 for nice round-off */
 textout(active_page, font_med, "G", 180*xscl+5*charx, 170*yscl, LIGHTGREEN);

 /* Show AoA */
 printfg(active_page, font_med, (pitch*180/PI)*10+0.5,3,3, 445*xscl,170*yscl, LIGHTGREEN); /* +0.5 for nice round-off */

 if (dtperframe > 0.01 && nguns > 0) {
 /*               ^to avoid weird value on first iteration */
      if(HUDmode == AIRGROUND) gun_ccip();
      if(HUDmode == AIRAIR) {
       gun_snake();
       if (selected_target >= 0) gun_lcos();
      }
 }

 switch (HUDmode) {
  case AIRAIR:     textout(active_page, font_med, "A-A", 180*xscl,330*yscl, LIGHTGREEN);
                   break;
  case AIRGROUND:  textout(active_page, font_med, "A-G", 180*xscl,330*yscl, LIGHTGREEN);
                   break;
  case NAVIGATION: textout(active_page, font_med, "NAV", 180*xscl,330*yscl, LIGHTGREEN);
                   break;
  case ILS:        textout(active_page, font_med, "ILS", 180*xscl,330*yscl, LIGHTGREEN);
                   break;

 }
 if ( (rcs_control) && (nrocketengines > 0) ) {
   textout(active_page, font_med, "RCS", 180*xscl,320*yscl, LIGHTGREEN);        
 }

 if ( (HUDmode == AIRAIR) || (HUDmode == AIRGROUND) ) {
    int nrounds=0;
    int i;
    for (i=0; i<nguns; i++)
        nrounds += gun[i].nrounds;
    textout(active_page, font_med, "GUN", 180*xscl,320*yscl, LIGHTGREEN);
    printg(active_page, font_med, nrounds,4, 200*xscl,320*yscl, LIGHTGREEN);
    if (selected_target >= 0) {
       target_box();
       if (HUDmode == AIRAIR)
          target_info();
    }
 }

 if (HUDmode==ILS) {
  cartvektor ILSspecs = ILS_signal();
  int xoff=xcenter;
  int yoff=ycenter;
  float xdeg=ILSspecs.y;
  float ydeg=ILSspecs.z;
  int i;

  if (ILSspecs.x < 10000 && ILSspecs.x > 0) {

     if (xdeg >  3) xdeg= 3;
     if (xdeg < -3) xdeg=-3;
     if (ydeg >  3) ydeg= 3;
     if (ydeg < -3) ydeg=-3;

     xoff += xdeg*xscl*10;
     yoff -= ydeg*yscl*10;

     for (i=-7; i<8; i++) {
       putpixel(active_page,xoff,ycenter+i*yscl*4,LIGHTGREEN);
       putpixel(active_page,xcenter+i*xscl*4,yoff,LIGHTGREEN);
     }

     line(active_page, xcenter-3*xscl,ycenter, xcenter+3*xscl,ycenter, LIGHTGREEN);
     line(active_page, xcenter,ycenter-3*yscl, xcenter,ycenter+3*yscl, LIGHTGREEN);
  }
 }

 if ( (HUDmode == NAVIGATION) || (HUDmode == ILS) )
    bank_indicator();
}



void show_DLC()
{
 float DLC_bar = DLC_spoiler;
 #define DLCX 520

 textout(active_page,font_med,"DLC", (DLCX+19)*xscl,440*yscl, LIGHTGREEN);
 line(active_page,(DLCX+20)*xscl,460*yscl,(DLCX+30)*xscl,460*yscl, LIGHTGREEN);
 line(active_page,(DLCX+20)*xscl,(460+8)*yscl,(DLCX+30)*xscl,(460+8)*yscl, LIGHTGREEN);
 line(active_page,(DLCX+20)*xscl,(460-7)*yscl,(DLCX+30)*xscl,(460-7)*yscl, LIGHTGREEN);
 if (DLC_spoiler == 55) DLC_bar=20;
 line(active_page,(DLCX+21)*xscl,(460+DLC_bar-7)*yscl, (DLCX+29)*xscl,(460+DLC_bar-7)*yscl, YELLOW);
}



void show_sweep()
{
 #define SWX 580
 #define SWY 455
 float cossweep;
 float sinsweep;

 if (manual_sweep) {
   cossweep=cos(PI*set_sweep/180.0);
   sinsweep=sin(PI*set_sweep/180.0);
   line(active_page, SWX*xscl,SWY*yscl, (SWX+20*cossweep)*xscl,(SWY+20*sinsweep)*yscl, LIGHTGRAY);
   line(active_page, SWX*xscl,SWY*yscl, (SWX-20*cossweep)*xscl,(SWY+20*sinsweep)*yscl, LIGHTGRAY);
 }

 cossweep=cos(PI*sweep/180.0);
 sinsweep=sin(PI*sweep/180.0);
 line(active_page, SWX*xscl,SWY*yscl, (SWX+20*cossweep)*xscl,(SWY+20*sinsweep)*yscl, LIGHTGREEN);
 line(active_page, SWX*xscl,SWY*yscl, (SWX-20*cossweep)*xscl,(SWY+20*sinsweep)*yscl, LIGHTGREEN);
 if (manual_sweep)
   textout(active_page, font_med, "M", (SWX-2)*xscl,(SWY+ 5)*yscl, LIGHTGREEN);
 else
   textout(active_page, font_med, "A", (SWX-2)*xscl,(SWY+ 5)*yscl, LIGHTGREEN);
 printg(active_page, font_med, sweep,2, (SWX-4)*xscl,(SWY+12)*yscl, LIGHTGREEN);
}



void one_line_info() /* Print brief flight status at bottom of screen */
{
 float tas, ias, alt, head;
 int charx,chary;

 charx=text_length(font_med,"M");
 chary=text_height(font_med);

 tas=VPRIK(v_air,front)/0.5144;
 ias=tas/sqrt(1.225/atmospheric_density(z));
 alt=z/0.3048; /* Meter per feet */
 head=-azi*180/PI; /* Azimuth increases counter-clockwise, heading clockwise */
 if (head<0) head+=360;
 if (head>=360) head-=360;
 textout(active_page, font_med, "IAS      KT",200*xscl,460*yscl, LIGHTGREEN);
 printg(active_page, font_med, ias,4, 200*xscl+4*charx,460*yscl, LIGHTGREEN);
 
 textout(active_page, font_med, "ALT        FT",300*xscl,460*yscl, LIGHTGREEN);
 printg(active_page, font_med, alt,6, 300*xscl+4*charx,460*yscl, LIGHTGREEN);

 textout(active_page, font_med, "HDG     DEG",410*xscl,460*yscl, LIGHTGREEN);
 printg(active_page, font_med, head,3, 410*xscl+4*charx,460*yscl, LIGHTGREEN);
}



void refresh_HUD()
{
 /* For stuff that need to be calculated when the HUD is not shown */

  lastgroundalt = z-groundalt(x,y);
}



void refresh_instruments()
{
 /* For stuff that need to be calculated when the analog instruments are not shown */

 float ias   = tas / sqrt(1.225/atmospheric_density(z));
 float feet  = z / 0.3048;
 float ftmin = 60 * v.z / 0.3048;

 /* Low-pass filtering */
 last_ias   = filter_const * last_ias   + (1.-filter_const) * ias;
 last_feet  = filter_const * last_feet  + (1.-filter_const) * feet;
 last_ftmin = filter_const * last_ftmin + (1.-filter_const) * ftmin;

}



void LM_descent_callout()
{
	#define ncallouts 7
	float calloutalt[] = { 700, 540, 200, 100, 70, 50, 3+10 };
	int calloutid[] = { H700FT_WAV, H540FT_WAV, H200FT_WAV, H100FT_WAV, H70FT_WAV, H50FT_WAV, CONTACT_WAV };
	int i;
	float lastalt_feet = lastgroundalt      / 0.3048;
	float nowalt_feet  = (z-groundalt(x,y)) / 0.3048;

	for (i=0; i<ncallouts; i++) {
		if ( ( lastalt_feet >= calloutalt[i] ) && ( nowalt_feet < calloutalt[i] ) && (ticks_8h-lm_call_wait > 1000) ) {
			play_wav(calloutid[i], 255, 180, 1000, false);
			lm_call_wait = ticks_8h;
		}
	}

}


void setviewpoint()
{
 float normfak;

 if ( (viewpoint == 8 || viewpoint == 9) &&
      (HUDmode == AIRAIR || HUDmode == AIRGROUND) &&
       selected_target < 0)
         viewpoint=0;

 if (viewpoint < 4) { /* In cockpit */
  cartvektor viewpos;

  viewpos.x=x; viewpos.y=y; viewpos.z=z;
  viewpos=vplus(viewpos,svmult(pilotpos.x,front));
  viewpos=vplus(viewpos,svmult(pilotpos.y,left));
  viewpos=vplus(viewpos,svmult(pilotpos.z,top));

  viewx=viewpos.x;
  viewy=viewpos.y;
  viewz=viewpos.z;

  viewfront=front;
  viewleft=left;
  viewtop=top;
 }
 if (viewpoint == 1) { /* looking backwards */
  viewleft=svmult(-1,left);
  viewfront=svmult(-1,front);
 }
 if (viewpoint == 2) { /* looking left */
  viewleft=svmult(-1,front);
  viewfront=left;
 }
 if (viewpoint == 3) { /* looking right */
  viewleft=front;
  viewfront=svmult(-1,left);
 }
 if (viewpoint == 4) { /* Looking at airplane from tower */
  viewx=1200;
  viewy=50;
  viewz=11+airfieldalt;
  viewfront.x=x-1200;
  viewfront.y=y-50;
  viewfront.z=z-(11+airfieldalt);
  normfak=1/sqrt(SQR(viewfront.x)+SQR(viewfront.y)+SQR(viewfront.z));
  viewfront=svmult(normfak,viewfront);
  viewleft.x=-viewfront.y;
  viewleft.y=viewfront.x;
  viewleft.z=0;
  normfak=1/sqrt(SQR(viewleft.x)+SQR(viewleft.y));
  viewleft=svmult(normfak,viewleft);
  viewtop=vkryds(viewfront,viewleft);
 }
 if (viewpoint == 5) { /* Looking at airplane from trail */
  viewx=x+traildist*cos(panhoriz+azi)*cos(panvert);
  viewy=y+traildist*sin(panhoriz+azi)*cos(panvert);
  viewz=z+traildist*sin(panvert);
  viewfront.x=x-viewx;
  viewfront.y=y-viewy;
  viewfront.z=z-viewz;
  normfak=1/sqrt(SQR(viewfront.x)+SQR(viewfront.y)+SQR(viewfront.z));
  viewfront=svmult(normfak,viewfront);
  viewleft.x=-viewfront.y;
  viewleft.y=viewfront.x;
  viewleft.z=0;
  normfak=1/sqrt(SQR(viewleft.x)+SQR(viewleft.y));
  viewleft=svmult(normfak,viewleft);
  viewtop=vkryds(viewfront,viewleft);
 }
 if (viewpoint == 6) { /* Looking at airplane from outside */
  viewx=x+traildist*cos(panhoriz)*cos(panvert);
  viewy=y+traildist*sin(panhoriz)*cos(panvert);
  viewz=z+traildist*sin(panvert);
  viewfront.x=x-viewx;
  viewfront.y=y-viewy;
  viewfront.z=z-viewz;
  normfak=1/sqrt(SQR(viewfront.x)+SQR(viewfront.y)+SQR(viewfront.z));
  viewfront=svmult(normfak,viewfront);
  viewleft.x=-viewfront.y;
  viewleft.y=viewfront.x;
  viewleft.z=0;
  normfak=1/sqrt(SQR(viewleft.x)+SQR(viewleft.y));
  viewleft=svmult(normfak,viewleft);
  viewtop=vkryds(viewfront,viewleft);
 }
 if (viewpoint == 7) { /* Looking at airplane from LSO station */
  cartvektor viewpos=get_LSO_pos();

  viewx=viewpos.x;
  viewy=viewpos.y;
  viewz=viewpos.z;
  viewfront.x=x-viewx;
  viewfront.y=y-viewy;
  viewfront.z=z-viewz;
  normfak=1/sqrt(SQR(viewfront.x)+SQR(viewfront.y)+SQR(viewfront.z));
  viewfront=svmult(normfak,viewfront);
  viewleft.x=-viewfront.y;
  viewleft.y=viewfront.x;
  viewleft.z=0;
  normfak=1/sqrt(SQR(viewleft.x)+SQR(viewleft.y));
  viewleft=svmult(normfak,viewleft);
  viewtop=vkryds(viewfront,viewleft);
 }
 if (viewpoint == 8) {
  /* Looking at target/waypoint from cockpit */
  /* The plane x-y axis are defining the "horizontal" plane */
  cartvektor viewpos, lookat;
  float pfront, pleft;

  if ( (HUDmode == NAVIGATION) || (HUDmode == ILS) )
    lookat = waypointlst[active_waypoint].pos;
  else
    lookat = target[selected_target].pos;

  viewpos.x=x; viewpos.y=y; viewpos.z=z;
  viewpos=vplus(viewpos,svmult(pilotpos.x,front));
  viewpos=vplus(viewpos,svmult(pilotpos.y,left));
  viewpos=vplus(viewpos,svmult(pilotpos.z,top));

  viewx=viewpos.x;
  viewy=viewpos.y;
  viewz=viewpos.z;

  viewfront=vminus(lookat, viewpos);
  normfak=1/sqrt(SQR(viewfront.x)+SQR(viewfront.y)+SQR(viewfront.z));
  viewfront=svmult(normfak,viewfront);

  pfront = VPRIK(viewfront, front);
  pleft  = VPRIK(viewfront, left);

  viewleft=svmult(pfront, left);
  viewleft=vplus(viewleft, svmult(-pleft, front));
  normfak=1/sqrt(SQR(viewleft.x)+SQR(viewleft.y)+SQR(viewleft.z));
  viewleft=svmult(normfak,viewleft);

  viewtop=vkryds(viewfront,viewleft);
 }
 if (viewpoint == 9) { /* Looking at target/waypoint from outside aircraft */
  cartvektor viewpos, tgtvect, lookat;

  if ( (HUDmode == NAVIGATION) || (HUDmode == ILS) )
    lookat = waypointlst[active_waypoint].pos;
  else
    lookat = target[selected_target].pos;

  viewpos.x=x; viewpos.y=y; viewpos.z=z+4;
  tgtvect=vminus(lookat, viewpos);
  normfak=1/sqrt(SQR(tgtvect.x)+SQR(tgtvect.y)+SQR(tgtvect.z));
  tgtvect=svmult(normfak, tgtvect);
  viewpos=vminus(viewpos, svmult(traildist, tgtvect));
  viewx=viewpos.x;
  viewy=viewpos.y;
  viewz=viewpos.z;
  viewfront=tgtvect;
  viewleft.x=-viewfront.y;
  viewleft.y=viewfront.x;
  viewleft.z=0;
  normfak=1/sqrt(SQR(viewleft.x)+SQR(viewleft.y));
  viewleft=svmult(normfak,viewleft);
  viewtop=vkryds(viewfront,viewleft);
 }
 if (viewpoint == 10) { /* Cockpit panning */
  cartvektor viewpos;

  viewpos.x=x; viewpos.y=y; viewpos.z=z;
  viewpos=vplus(viewpos,svmult(pilotpos.x,front));
  viewpos=vplus(viewpos,svmult(pilotpos.y,left));
  viewpos=vplus(viewpos,svmult(pilotpos.z,top));

  viewx=viewpos.x;
  viewy=viewpos.y;
  viewz=viewpos.z;

  viewfront = vplus(svmult(cos(panhoriz_int),front),svmult( sin(panhoriz_int),left ));
  viewfront = vplus(svmult(cos(panvert_int),viewfront),svmult(sin(panvert_int),top));
  viewleft  = vplus(svmult(cos(panhoriz_int),left ),svmult(-sin(panhoriz_int),front));
  viewtop=vkryds(viewfront,viewleft);
 }
}



void setup_cockpit_panning()
{
 if (viewpoint == 0 || viewpoint == 4 || viewpoint == 7) {
    panhoriz_int     = 0;
    panvert_int      = 0;
    set_panhoriz_int = 0;
    set_panvert_int  = 0;
 }

 if (viewpoint == 1) {
    panhoriz_int     = PI;
    panvert_int      = 0;
    set_panhoriz_int = PI;
    set_panvert_int  = 0;

 }

 if (viewpoint == 2) {
    panhoriz_int     = PI/2;
    panvert_int      = 0;
    set_panhoriz_int = PI/2;
    set_panvert_int  = 0;
 }

 if (viewpoint == 3) {
    panhoriz_int     = 3*PI/2;
    panvert_int      = 0;
    set_panhoriz_int = 3*PI/2;
    set_panvert_int  = 0;
 }

 if (viewpoint == 8) {
    /* Should be offsetting from padlock position instead */
    panhoriz_int     = 0;
    panvert_int      = 0;
    set_panhoriz_int = 0;
    set_panvert_int  = 0;
 }

 if (viewpoint == 9) {
    /* Should be offsetting from padlock position instead */
    panhoriz_int     = 0;
    panvert_int      = 0;
    set_panhoriz_int = 0;
    set_panvert_int  = 0;
 }

 viewpoint = 10;
}



void update_panning()
{
 if (smooth_pan) {
   float desire;
   /* float tmp_panhoriz, tmp_set_panhoriz; */
   float tmp_panhoriz_int, tmp_set_panhoriz_int;

   /* panhoriz     = set_panhoriz; */

   /*
   tmp_panhoriz = panhoriz;
   if (panhoriz >= PI) tmp_panhoriz -= 2*PI;
   tmp_set_panhoriz = set_panhoriz;
   if (set_panhoriz > PI) tmp_set_panhoriz -=2*PI;
   desire = tmp_set_panhoriz-tmp_panhoriz;
   if (desire != 0) {
     float dpandt = 0.5*PI*dtperframe;
     float dpan;

     if (fabs(desire)>dpandt)
      dpan=dpandt*sgn(desire);
     else
      dpan=desire;
     tmp_panhoriz += dpan;

     if (tmp_panhoriz < 0) tmp_panhoriz += 2*PI;
     panhoriz=tmp_panhoriz;

     if (panhoriz < 0)    panhoriz += 2*PI;
     if (panhoriz > 2*PI) panhoriz -= 2*PI;
   }
   */

   desire = set_panhoriz-panhoriz;
   if (desire >=  2*PI) desire-=2*PI;
   if (desire <= -2*PI) desire+=2*PI;
   if (desire != 0) {
     float dpandt = 0.75*PI*dtperframe;

     if (panhorizsgn==1) {
       float newpanhoriz=dpandt+panhoriz;

       if (newpanhoriz>=2*PI) newpanhoriz-=2*PI;

       /* if (newpanhoriz>set_panhoriz) */
       if (fabs(desire) < dpandt)
          panhoriz=set_panhoriz;
       else
          panhoriz=newpanhoriz;
     }
     else {
       float newpanhoriz=panhoriz-dpandt;

       if (newpanhoriz<0) newpanhoriz+=2*PI;

       /* if (newpanhoriz<set_panhoriz) */
       if (fabs(desire) < dpandt)
          panhoriz=set_panhoriz;
       else
          panhoriz=newpanhoriz;
     }
   }

   tmp_panhoriz_int = panhoriz_int;
   if (panhoriz_int >= PI) tmp_panhoriz_int -= 2*PI;
   tmp_set_panhoriz_int = set_panhoriz_int;
   if (set_panhoriz_int > PI) tmp_set_panhoriz_int -=2*PI;
   desire = tmp_set_panhoriz_int-tmp_panhoriz_int;
   if (desire != 0) {
     float dpandt = 0.75*PI*dtperframe;
     float dpan;

     if (fabs(desire)>dpandt)
      dpan=dpandt*sgn(desire);
     else
      dpan=desire;
     tmp_panhoriz_int += dpan;

     if (tmp_panhoriz_int < 0) tmp_panhoriz_int += 2*PI;
     panhoriz_int=tmp_panhoriz_int;
   }

   /* Not framerate-independent */
   desire = set_traildist-traildist;
   if (desire!=0) {
     #define ZOOMSPD (0.12)
     if (desire > 0) {
      if ((1+ZOOMSPD)*traildist > set_traildist)
        traildist=set_traildist;
      else
        traildist *=(1+ZOOMSPD);
     }
     else {
      if ((1-ZOOMSPD)*traildist < set_traildist)
        traildist=set_traildist;
      else
        traildist *=(1-ZOOMSPD);
     }
   }

   desire = set_panvert-panvert;
   if (desire != 0) {
     float dpandt = 0.5*PI*dtperframe;
     float dpan;

     if (fabs(desire)>dpandt)
      dpan=dpandt*sgn(desire);
     else
      dpan=desire;
     panvert += dpan;
   }

   desire = set_panvert_int-panvert_int;
   if (desire != 0) {
     float dpandt = 0.75*PI*dtperframe;
     float dpan;

     if (fabs(desire)>dpandt)
      dpan=dpandt*sgn(desire);
     else
      dpan=desire;
     panvert_int += dpan;
   }
 }
 else {
   traildist    = set_traildist;
   panhoriz     = set_panhoriz;
   panvert      = set_panvert;
   panhoriz_int = set_panhoriz_int;
   panvert_int  = set_panvert_int;
 }

 if (viewpoint == 10)
   if ( (panhoriz_int < 1e-3 || 2*PI-panhoriz_int < 1e-3) && fabs(panvert_int) < 1e-3)
          viewpoint = 0;
}



void visual()                   /* Tegn cockpit,instrumenter og udsyn */
{
 setviewpoint();
 update_filters();

 if ( (!show_instruments) || (viewpoint != 0) )
    refresh_instruments();
 if ( (!show_hud) || (viewpoint != 0) )
    refresh_HUD();

 if (show_map) {
  draw_map(x,y,azi,20);
  one_line_info();
 }
 else {
 outside();
 if (show_hud==true && nguns>0)
    update_lcos_bullets();
 if (viewpoint == 0) {  /* Looking forward from cockpit */
  #ifdef TIMESTAT
    clock_start(13);
  #endif
  if (show_ctrlpos==true) show_controls();
  show_trim(620*xscl,450*yscl,0.4);
  if (show_hud==true) {
      hud();
      AoA_indexer(220, ycenter);
  }
  else {
    if (hook.exists) {
      if (show_instruments)
        AoA_indexer(100, 425*yscl);
      else
        AoA_indexer(150, 425*yscl);
    }
    if ((nguns > 0) && (HUDmode < NAVIGATION)) gunsight();
  }
  if (poly_plane_id[current_model]==F14) {
    if (DLC_active) show_DLC();
    show_sweep();
  }
  #ifdef TIMESTAT
    clock_stop(13);
  #endif
  #ifdef TIMESTAT
    clock_start(14);
  #endif
  if (flapresponse > 0) showflap(50*xscl,380*yscl,0.9);


  if (npropengines > 0) {
    if (detail_prop) {
      show_throttle_ctrl(10*xscl,370*yscl,1.0,0);
      show_prop_ctrl(30*xscl,370*yscl,1.0);
      if (show_instruments) {
        show_RPM((320-250*INST_SCALE)*xscl,(481-200*INST_SCALE)*yscl);
        show_MAN((320-250*INST_SCALE)*xscl,(481-100*INST_SCALE)*yscl);
        show_FFLW((320-350*INST_SCALE)*xscl,(481-100*INST_SCALE)*yscl);
        show_TANK((320-350*INST_SCALE)*xscl,(481-200*INST_SCALE)*yscl);
      }
    }
    else {
      int i;
      for (i=0 ; i<npropengines ; i++)
         showthrottle(10*xscl+20*xscl*i,380*yscl,1.0,i);
      if (show_instruments)
        show_TANK((320-250*INST_SCALE)*xscl,(481-100*INST_SCALE)*yscl);
    }
  }

  if (njetengines > 0) {
    int i;
    if (detail_jet) {
      for (i=0 ; i<njetengines ; i++) {
         show_throttle_ctrl(10*xscl+20*xscl*i,370*yscl,1.0,i);
         if (show_instruments) {
           int xoffs=250+(75*njetengines-1);

           show_JET_RPM((320-(xoffs-25*i)*INST_SCALE)*xscl,(481-150*INST_SCALE)*yscl,
           jengine[i].rpm);
           show_JET_EGT((320-(xoffs-25*njetengines-25*i)*INST_SCALE)*xscl,(481-150*INST_SCALE)*yscl,
           jengine[i].egt);
           show_JET_FFLW((320-(xoffs-50*njetengines-25*i)*INST_SCALE)*xscl,(481-150*INST_SCALE)*yscl,
           (jengine[i].fflw*3600.0/rho_fuel)/0.454);
         }
      }
    }
    else {
      for (i=0 ; i<njetengines ; i++)
         showthrottle(10*xscl+20*xscl*i,380*yscl,1.0,i);
    }
    if (show_instruments)
      show_TANK((320-250*INST_SCALE)*xscl,(481-100*INST_SCALE)*yscl);
  }

	if (nrocketengines > 0) {
		int i;
    
		for (i=0 ; i<nrocketengines ; i++) {
			show_throttle_ctrl(10*xscl+20*xscl*i,370*yscl,1.0,i);
		}
		if (show_instruments)
			show_TANK((320-250*INST_SCALE)*xscl,(481-100*INST_SCALE)*yscl);
	} 

  if (show_instruments) {
     show_COMP((320- 50*INST_SCALE)*xscl,(481-100*INST_SCALE)*yscl);
     show_TURN((320-150*INST_SCALE)*xscl,(481-100*INST_SCALE)*yscl);
     show_VVI( (320+ 50*INST_SCALE)*xscl,(481-100*INST_SCALE)*yscl);
     show_HOR( (320- 50*INST_SCALE)*xscl,(481-200*INST_SCALE)*yscl);
     show_IAS( (320-150*INST_SCALE)*xscl,(481-200*INST_SCALE)*yscl);
     show_ALT( (320+ 50*INST_SCALE)*xscl,(481-200*INST_SCALE)*yscl);
     show_ILS( (320+150*INST_SCALE)*xscl,(481-200*INST_SCALE)*yscl);
     show_ACC( (320+150*INST_SCALE)*xscl,(481-100*INST_SCALE)*yscl);
     show_GEAR((320+250*INST_SCALE)*xscl,(481-100*INST_SCALE)*yscl);
  }
  else {
     showgear(100*xscl,420*yscl,5);
     if (hook.exists) showhook(100*xscl,426*yscl,5);
     if (airbrake.area > 0) showairbrake(100*xscl,460*yscl);
  }
  if (njetengines > 0) {
   if (jengine[0].vectoruplim!=jengine[0].vectordnlim)
	showvector(550*xscl,430*yscl,0.8);
  }
  #ifdef TIMESTAT
    clock_stop(14);
  #endif
 }
 else one_line_info();  /* Show brief info instead of HUD */
 if (viewpoint==4) { /* Tower / RC-mode */
  #ifdef TIMESTAT
    clock_start(14);
  #endif
  if (flapresponse > 0) showflap(50*xscl,380*yscl,0.9);

  if (npropengines > 0) {
    if (detail_prop) {
      show_throttle_ctrl(10*xscl,370*yscl,1.0,0);
      show_prop_ctrl(30*xscl,370*yscl,1.0);
    }
    else {
      int i;
      for (i=0 ; i<npropengines ; i++)
         showthrottle(10*xscl+20*xscl*i,380*yscl,1.0,i);
    }
  }

  if (njetengines > 0) {
    int i;
    if (detail_jet) {
      for (i=0 ; i<njetengines ; i++)
         show_throttle_ctrl(10*xscl+20*xscl*i,370*yscl,1.0,i);
    }
    else {
      for (i=0 ; i<njetengines ; i++)
         showthrottle(10*xscl+20*xscl*i,380*yscl,1.0,i);
    }
  }

  showgear(100*xscl,420*yscl,5);
  if (hook.exists) showhook(100*xscl,426*yscl,5);
  if (airbrake.area > 0) showairbrake(100*xscl,460*yscl /* ,5 */);
  if (njetengines > 0) {
   if (jengine[0].vectoruplim!=jengine[0].vectordnlim)
	showvector(550*xscl,430*yscl,0.8);
  }
  #ifdef TIMESTAT
    clock_stop(14);
  #endif
 }
 }
 update_message();
 show_message();
}
