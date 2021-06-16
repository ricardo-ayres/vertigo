void plotangle(float v1, float v2)
{
 /* Only for test-purposes */
 int i;
 int x=50;
 int y=50;
 int r=40;
 v1=-v1-PI/2.;
 v2=-v2-PI/2.;
 for (i=0; i<36; i++)
	putpixel(active_page, x+r*cos(PI*i/18.0),y+r*sin(PI*i/18.0),LIGHTBLUE);
 line(active_page, x,y,x+r*cos(v1),y+r*sin(v1), LIGHTRED);
 line(active_page, x,y,x+0.8*r*cos(v2),y+0.8*r*sin(v2), LIGHTGREEN);
}



float atmospheric_temperature(float h) {
	// Returns atmospheric temperature in degrees Celsius as a function of altitude in meters
	
	if (h < 11000.) {
		// Troposphere
		return( 15.04 - 0.00649 * h );
	}
	if (h < 25000.) {
		// Lower stratosphere
		return( -56.46 );
	}
	// h > 25000: Upper stratosphere
	return( -131.21 + 0.00299 * h );
}



float atmospheric_pressure(float h) {
	// Returns atmospheric pressure in degrees Celsius as a function of altitude in meters

	if (world == MOON) return 0.;

	if (h < 11000.) {
		// Troposphere
		return( 101.29 * pow( (atmospheric_temperature(h) + 273.1)/288.08  , 5.256) );
	}
	if (h < 25000.) {
		// Lower stratosphere
		return( 22.65*exp(1.73 - 0.000157 * h) );
	}
	// h > 25000: Upper stratosphere
	return( 2.488 * pow( (atmospheric_temperature(h) + 273.1)/216.6 , -11.388 ) );
}



float atmospheric_density(float h) {
	if (world == MOON) return 0.;
	return( atmospheric_pressure( h ) / ( 0.2869 * ( atmospheric_temperature(h) + 273.1 )  )  );
}



float mach(float v, float alt)
{
/* Returns Mach number */
/* Input airspeed [m/s] and altitude [m] */
 float soundspeed = 331.46 + 0.5955 * atmospheric_temperature(alt);

 return( v / soundspeed );
}



float old_mach(float v, float alt)
{
/* Returns Mach number */
/* Input airspeed [m/s] and altitude [m] */
 float soundspeed = 340.3 - 3.7667e-3 * alt;

 if (alt > 12000.) soundspeed=295.1;

 return( v / soundspeed );
}



float superdrag(float m)
{
 /* Produces lookalike drag curve as function of mach number */
 /* Has maximum of 1 at mach 1.0 */

 #define wl (50.0)
 #define wh (1.2)

 float sd;

 if (m < 1) 
   sd = pow ( wl , -wl * SQR( m - 1.0 ) );
 else
   sd = pow ( wh , -wh * SQR( m - 1.0 ) );

 return (sd);
}



float flow_quality(float aoa)
{
 /* Returns the degree of turbulence
    completely turbulent at normalized aoa = 1 */
 #define SHARP (20.0)

 if (aoa < 1.0)
   return( 1.0 - pow ( SHARP , -SHARP * SQR( aoa - 1.0 ) ) );
 else
   return(0.0);
}



float auto_sweep(float mach_number)
{
 float a_sweep=0;

 if (mach_number <  0.4 ) a_sweep=20.0;
 if (mach_number >= 0.4  && mach_number < 0.75 ) a_sweep=22.0;
 if (mach_number >= 0.75 && mach_number < 1.2  )
    a_sweep=22.0+(mach_number-0.75)*102.22;
 if (mach_number >  1.2 ) a_sweep=68.0;

 return(a_sweep);
}



float cl(float alpha, float sf, float curv, float slat)
/* Calculate lift coefficient C_L */
/* The method is ad-hoc, but seems OK */
/* alpha is given in degrees */
{
 float cl,cl2,astall;

 cl      = (alpha+curv)/10;             /* Linear regime with curvature corr. */
 cl     /= (1+1/sf);                    /* Correction for aspect ratio */
 astall  = (20-curv/3);                 /* Estimate of stall-angle */
 astall += 5*slat*sgn(alpha);
 astall *= (1+1.33/(sf+0.33));
 cl     /= (1+SQR(SQR(alpha/astall)));
 /* Nu beregning for regime naer 180gr. pitch */
 if  (alpha < 0) alpha = -180-alpha;
 if (alpha >= 0) alpha =  180-alpha;
 cl2     = (alpha+curv)/15;
 cl2    /= (1+1/sf);
 astall  = (15-curv/2)*(1+1.33/(sf+0.33));
 cl2    /= (1+SQR(SQR(alpha/astall)));
 cl     += cl2;
 return(cl);
}



void plotaero()
{
 /* Only for test-purposes */
 float i;

 line(active_page, 20*2,100, 380*2,100, LIGHTGRAY);
 line(active_page, 200*2,0,  200*2,200, LIGHTGRAY);
 line(active_page, 200*2,50, 205*2,50,  LIGHTGRAY);

 for (i=-18; i<18; i++)  {
    line(active_page, i*20+200,98, i*20+200,102,LIGHTGRAY);
 }

 for (i=-180; i<180; i++)
  {
   /* C_L vs. AOA */

   /* Infinite aspect, zero curvature */
   /* putpixel(i*2+400,100-50*cl(i,10000,0,0),BLUE); */

   /* aspect = 5.0, curvature = 2 */
   /* putpixel(i*2+400,100-50*cl(i,5.0*0.94,2,0),RED); */

   /* F-14, flaps up:   aspect = 3.5, curvature = 2 */
   putpixel(active_page, i*2+400,100-50*cl(i,3.5,2,0),WHITE);

   /* F-14, flaps down: aspect = 3.5, curvature = 14, slat up */
   putpixel(active_page, i*2+400,100-50*cl(i+24/6,3.5,2+24/2,0),GREEN);

   /* F-14, flaps down: aspect = 3.5, curvature = 14, slat down */
   putpixel(active_page, i*2+400,100-50*cl( i+24/6, 3.5, 2+24/2, 0.8),RED);


   /*
   putpixel(active_page, i*2+400,100-50*cl_naca(i),WHITE);
   putpixel(active_page, i*2+400,100-50*cd_naca(i),GREEN);
   putpixel(active_page, i*2+400,100-50*cm_naca(i),RED);
   */
  }

 /* Plot of propeller engine torque */
 /*
 for (i=0; i<350; i++) {
  float torque,hp,rpm;

  rpm = i*10;

  if (rpm <= 2700)
    torque= 1-0.9*SQR((rpm/2700)-1);
  else
    torque= 1-2*pow((rpm/2700)-1,1.5);

  hp = torque*rpm;

  setcolor(LIGHTGRAY);
  moveto(270,300);
  lineto(270,200);
  putpixel(i,300-100*torque,RED);
  putpixel(i,300-hp/30,YELLOW);

 }
 */

 /* Plot of air density */
 /*
 for (i=0; i<6000; i++)
  {
   putpixel(50+100*atmospheric_density(i*10),350-i/50,LIGHTBLUE);
  }
 */

 /* Plot af power-law control gain */
 /* Max udslag ca. 270 ved linear input */
 /*
 for (i=-270; i<=270; i++)
  {
   float x=i/4;
   float xn=i/270;
   putpixel(x+400,250-x,RED);
   putpixel(x+400,250-(270/4)*(xn+3*pow(xn,5)),YELLOW);
  }
*/

}




void findangles()
/* Finder bl.a. Pitch og Yaw. Arbejder i kartesiske koordinater */
{
 float vpfront, vpleft, vptop;
 float lv;
 float pitchnorm, yawnorm;
 cartvektor v1;
 cartvektor top0,left0;

 /* Calculate time-demanding trigonometry */
 cos_roll=cos(roll);
 sin_roll=sin(roll);
 cos_nosealt=cos(nosealt);
 sin_nosealt=sin(nosealt);
 cos_azi=cos(azi);
 sin_azi=sin(azi);


 /* Naese vektor */
 front.x=cos_azi*cos_nosealt;
 front.y=sin_azi*cos_nosealt;
 front.z=sin_nosealt;

 /* Overhead vektor for roll=0 */
 top0.x=cos_azi*cos(nosealt+PI/2);
 top0.y=sin_azi*cos(nosealt+PI/2);
 top0.z=sin(nosealt+PI/2);

 /* Bagbord vektor for roll=0 */
 left0=vkryds(top0,front);

 /* Bagbord vektor */
 left=vplus(svmult(cos_roll,left0),svmult(sin_roll,top0));

 /* Overhead vektor */
 top=vkryds(front,left);

 v_air=vplus(v,wind);

 /* Normaliseret kartesisk hastighedsvektor */
 lv=sqrt(SQR(v_air.x) + SQR(v_air.y) + SQR(v_air.z));
 if (fabs(lv>1e-9))
    v1=svmult(1/lv,v_air);
 else {
    v1.x=0;
    v1.y=0;
    v1.z=0;
 }

 tas=VPRIK(v_air,front)/0.5144;

 aircraft_mach_number=mach(VPRIK(v_air,front),z);

 /* Find Pitch og Yaw */
 vpfront=v1.x*front.x+v1.y*front.y+v1.z*front.z;
 vpleft=v1.x*left.x+v1.y*left.y+v1.z*left.z;
 vptop=v1.x*top.x+v1.y*top.y+v1.z*top.z;

 prev_yaw=yaw;
 prev_pitch=pitch;

 yawnorm=sqrt((SQR(vpfront)+SQR(vpleft)));
 if (fabs(yawnorm)>1e-9) {                   /* Avoid div. by 0 */
    yaw=arccos(vpfront/yawnorm);
    if (vpleft < 0) yaw=-yaw;
    }
 else
    yaw=0;

 pitchnorm=sqrt((SQR(vpfront)+SQR(vptop)));
 if (fabs(pitchnorm)>1e-9) {                 /* Avoid div. by 0 */
    pitch=arccos(vpfront/pitchnorm);
    if (vptop > 0) pitch=-pitch;
    }
 else
    pitch=0;

 avg_yaw=0.5*(yaw+prev_yaw);
 avg_pitch=0.5*(pitch+prev_pitch);
}



void applyaccel()
{
 prev_v=v;
 v=vplus(v,svmult(dt,acc));
 avg_v=svmult(0.5,vplus(v,prev_v));

 wfront += waccfront*dt;
 wleft  += waccleft*dt;
 wtop   += wacctop*dt;
}



void motion()
{
 cartvektor nyfront,nyleft,nytop,top0,top1;
 float nyazi,nynosealt,nyroll;
 float norm;

 x += v.x*dt;
 y += v.y*dt;
 z += v.z*dt;

 /* drejning af fly delt op i tre komponenter */
 /* Metode (maaske) forkert, men nogenlunde OK for smaa vinkler? */
 /* drej om front-akse */
 nytop   = vplus(svmult(cos(wfront*dt),top),svmult(sin(wfront*dt),left));
 nyleft  = vplus(svmult(cos(wfront*dt),left),svmult(sin(wfront*dt),top));
 nyfront = front;

 /* drej om left-akse */
 left  = nyleft;
 front = vplus(svmult(cos(wleft*dt),nyfront),svmult(sin(wleft*dt),nytop));
 top   = vplus(svmult(cos(wleft*dt),nytop),svmult(sin(wleft*dt),nyfront));

 /* drej om top-akse */
 nytop   = top;
 nyfront = vplus(svmult(cos(-wtop*dt),front),svmult(sin(-wtop*dt),left));
 nyleft  = vplus(svmult(cos(wtop*dt),left),svmult(sin(wtop*dt),front));

 front = nyfront;
 left  = nyleft;
 top   = vkryds(front,left); /* Mere praecist end "top=nytop" */

 /* Konvertering tilbage til azi, nosealt og roll */
 nynosealt=arcsin(front.z);
 /* This calculation of nyazi avoids the poorly defined regions
    of arccos and arcsin */
 norm=sqrt((SQR(front.x)+SQR(front.y)));
 if (fabs(norm)>1e-9) {
      if ( fabs(front.x) < fabs(front.y) ) {
           nyazi=arccos(front.x/norm);
           if (front.y < 0) nyazi=-nyazi;
      }
      else {
           nyazi=arcsin(front.y/norm);
           if (front.x < 0) {
              nyazi=PI-nyazi;
              if (front.y <0)
                 nyazi-=2*PI;
           }
      }
    }
 else
    nyazi=0;

 /* Beregn top for nosealt=0 */
 /* top0=vplus(svmult(cos(nynosealt),top),svmult(sin(nynosealt),front)); */
 /* Drej foerst azi om z-akse */
 top0.x=cos(nyazi)*top.x+sin(nyazi)*top.y;
 top0.y=sin(nyazi)*top.x+cos(nyazi)*top.y;
 top0.z=top.z;
 /* Drej derefter -nosealt om y-akse */
 top1.x=cos(-nynosealt)*top0.x+sin(-nynosealt)*top0.z;
 top1.y=top0.y;
 top1.z=sin(-nynosealt)*top0.x+cos(-nynosealt)*top0.z;
 /* Skal principielt drejes -azi om y-akse, men det paavirker ikke top1.z */
 top0=top1;
 roll=arccos(top0.z);
 if (left.z < 0) roll=-roll;
 nyroll=roll;

 if (nyroll >  PI) nyroll -= 2*PI;
 if (nyroll < -PI) nyroll += 2*PI;
 if (top.z > 0)
    {
    if (nyroll > PI/2)
      nyroll -= PI;
    else
      if (nyroll < -PI/2) nyroll += PI;
    };

 if (top.z < 0)
    {
    if (nyroll >= 0 && nyroll < PI/2)
      nyroll -= PI;
    else
      if (nyroll < 0 && nyroll > -PI/2) nyroll += PI;
    };

 azi     = nyazi;
 nosealt = nynosealt;
 roll    = nyroll;

 logdata.x = x;
 logdata.y = y;
 logdata.z = z;
 logdata.omega_front = wfront;
 logdata.omega_left  = wleft;
 logdata.omega_top   = wtop;
 logdata.v_z  = v.z;
 logdata.ias  = ias;
 logdata.tas  = tas;
 logdata.mach = aircraft_mach_number;
 logdata.AoA  = pitch;
 logdata.yaw  = yaw;
 logdata.acc_front = VPRIK(front,acc);
 logdata.acc_left  = VPRIK(left ,acc);
 logdata.acc_top   = VPRIK(top  ,acc);
}



void update_lcos_bullets()
{
 /* Unfortunately, the length of the snake depends on the frame rate */

 int i;
 float density,vtot,vloss;
 float dt = dtperframe;

 /* Shift list */
 if (nlcos_bullets_flying > 0) {
   int last=nlcos_bullets_flying;
   if (last==nlcos_bullets) last--;
   for (i=last; i>0; i--) {
     lcos_bullet[i]=lcos_bullet[i-1];
   }
 }

 /* Insert new bullet here */
 lcos_bullet[0].pos.x=x;
 lcos_bullet[0].pos.y=y;
 lcos_bullet[0].pos.z=z;
 lcos_bullet[0].velocity=svmult(gun[0].muzzle_vel,front);
 lcos_bullet[0].velocity=vplus(lcos_bullet[0].velocity,v);
 lcos_bullet[0].mass=gun[0].projectile_mass;

 if (nlcos_bullets_flying < nlcos_bullets)
     nlcos_bullets_flying++;

 /* Update position */
 for (i=0; i<nlcos_bullets_flying; i++) {
   lcos_bullet[i].velocity.z-=G*dt;
   vtot=sqrt(SQR(lcos_bullet[i].velocity.x)+SQR(lcos_bullet[i].velocity.y)+SQR(lcos_bullet[i].velocity.z));
   density=atmospheric_density(lcos_bullet[i].pos.z);
   vloss=0.5*density*SQR(vtot)*0.0001*0.2*dt/lcos_bullet[i].mass;
   lcos_bullet[i].velocity=svmult(1-vloss/vtot,lcos_bullet[i].velocity);
   lcos_bullet[i].pos=vplus(lcos_bullet[i].pos,svmult(dt,lcos_bullet[i].velocity));
 }
}



void update_bullets()
{
 /* Does not take wind into account */
 int   i=0;
 int   n=0;
 float density,vtot,vloss;
 float dt               = dtperframe;
 int   new_nactive      = nactive_bullets;
 bool  target_hit       = false;
 bool  target_destroyed = false;

 while (n < nactive_bullets) {
  if (bullet[i].active==true) {
   cartvektor tmppos;
   int j;
   #define tracer_life_time ( 5./3600.) /*  5 sec */
   #define bullet_life_time (15./3600.) /* 15 sec */

   n++;

   bullet[i].velocity.z-=G*dt;
   vtot=sqrt(SQR(bullet[i].velocity.x)+SQR(bullet[i].velocity.y)+SQR(bullet[i].velocity.z));
   density=atmospheric_density(bullet[i].pos.z);
   vloss=0.5*density*SQR(vtot)*0.0001*0.2*dt/bullet[i].mass;
   /*                            ^     ^ */
   /*                    frontarea dragcoeff */
   bullet[i].velocity=svmult(1-vloss/vtot,bullet[i].velocity);
   tmppos=vplus(bullet[i].pos,svmult(dt,bullet[i].velocity));

   if (elapsed_time - bullet[i].starttime > tracer_life_time)
      bullet[i].tracer = false;

   if (elapsed_time - bullet[i].starttime > bullet_life_time) {
      bullet[i].active=false;
      new_nactive--;
   }

   /* Is a target hit? */
   for (j=0; j<ntargets; j++) {
    if (target[j].strength > target[j].nhits && bullet[i].active) {
       /* With very low frame rate (approx < 10/sec), this method will
          be ineffective */
       if ( SQR(tmppos.x - target[j].pos.x) +
            SQR(tmppos.y - target[j].pos.y) +
            SQR(tmppos.z - target[j].pos.z) < 20000) {
         /* Bullet is close */
         bool  hit=false;
         float sqrrad = SQR(target[j].hitrad);
         cartvektor b1b2  = vminus(tmppos, bullet[i].pos);
         cartvektor b1t   = vminus(target[j].pos, bullet[i].pos);
         cartvektor b2t   = vminus(target[j].pos, tmppos);
         float b1b2_p_b1t = VPRIK(b1b2, b1t);
         float b1b2_p_b2t = VPRIK(b1b2, b2t);

         if ( (b1b2_p_b1t > 0) && (b1b2_p_b2t < 0) ) {
            float sqrb1b2len = VPRIK( b1b2, b1b2);
            float sqrdist = VPRIK( b1t, b1t ) - SQR(b1b2_p_b1t)/sqrb1b2len;

            if ( sqrdist < sqrrad ) {
               hit=true;
               /* Would be nicer if this showed where on the target the hit is */
               sym_explode(target[j].pos);
            }
         }

         if (hit) {
           target[j].nhits++;
           bullet[i].active=false;
           new_nactive--;
           target_hit = true;
           if (target[j].nhits == target[j].strength) {
              target_destroyed = true;
              selected_target  = -1;
           }
         }
       }
    }
   }

   /* Has bullet hit ground? */
   if (tmppos.z<groundalt(tmppos.x,tmppos.y) && bullet[i].active) {
     float z1,z2;
     cartvektor hitpos;
      /* this calc assumes flat ground */
     z1=bullet[i].pos.z-groundalt(bullet[i].pos.x,bullet[i].pos.y);
     z2=tmppos.z-groundalt(tmppos.x,tmppos.y);
     hitpos=vplus(svmult(z1/(z1-z2),vminus(tmppos,bullet[i].pos)),bullet[i].pos);
     explode(hitpos);
     bullet[i].active=false;
     new_nactive--;

   }
   bullet[i].pos=tmppos;
  }
  i++;
 }
 nactive_bullets=new_nactive;
 if (target_hit) {
   if (target_destroyed)
      play_wav(EXPLODE_WAV, 255, 128, 1000, false);
   else
      play_wav(PING_WAV, 255, 128, 2000, false);
 }
}



void gun_snake()
{
 if (nlcos_bullets_flying > 2) {
   int i;
   bool drawit = false;
   int lastx=0;
   int lasty=0;
   /* First one looks weird */
   for (i=1; i<nlcos_bullets_flying; i++) {
     cartvektor pos=scrpos3d(lcos_bullet[i].pos);
     if (drawit) {
       if (pos.z==1) {
          line(active_page, lastx, lasty, pos.x,pos.y, LIGHTGREEN);
	  lastx = pos.x;
	  lasty = pos.y;
       }
       else
         drawit=false;
     }
     else {
       if (pos.z==1) {
	  lastx = pos.x;
	  lasty = pos.y;
          drawit=true;
       }
     }
   }
 }
}



void gun_lcos()
{
 if (nlcos_bullets_flying > 2) {
   int okid=-1;
   int i;
   float tgt_dist = SQR(target[selected_target].pos.x - x) +
                    SQR(target[selected_target].pos.y - y) +
                    SQR(target[selected_target].pos.z - z);


   for (i=0; i<nlcos_bullets_flying; i++) {
     float buldist= SQR(x - lcos_bullet[i].pos.x) +
                    SQR(y - lcos_bullet[i].pos.y) +
                    SQR(z - lcos_bullet[i].pos.z);
     if ( (buldist > tgt_dist) && okid==-1) {
        okid = i;
     }
   }

   if (okid > 0) {
     float substep = 10;
     int k;
     cartvektor scrpos;
     bool posok = false;
     cartvektor pos=lcos_bullet[okid].pos;
     cartvektor subvect= svmult(1./substep, vminus(lcos_bullet[okid].pos, lcos_bullet[okid-1].pos));

     for (k=0; k<substep; k++) {
       cartvektor subtmp = vplus( svmult(k, subvect), lcos_bullet[okid-1].pos);
       float buldist= SQR(x - subtmp.x) +
                      SQR(y - subtmp.y) +
                      SQR(z - subtmp.z);
       if ( (buldist > tgt_dist) && !posok) {
         posok = true;
         pos   = subtmp;
       }
     }

     scrpos=scrpos3d(pos);
     if (scrpos.z==1) {
       putpixel(active_page, scrpos.x,scrpos.y,LIGHTGREEN);
       circle(active_page, scrpos.x,scrpos.y,10*xscl, LIGHTGREEN);
       tgt_dist = sqrt(tgt_dist)/(1000*0.3048); /* unit: 1000s of feet */
       if (tgt_dist < 4) {
          float rngarc = 90*tgt_dist;
          rngarc= 90-rngarc;
          if (rngarc < 0)
             rngarc += 360;
          arc(active_page, scrpos.x, scrpos.y, rngarc, 90, 8*xscl, LIGHTGREEN);
       }
     }
   }
 }
}



void gun_ccip()
{
 /* Does not take wind into account */
 float density,vtot,vloss,time_passed=0;
 float time_limit=10;
 cartvektor pos,velocity,tmppos,ccip_pos,scrpos;
 bool timeout=false;
 bool impact=false;

 pos.x=x;
 pos.y=y;
 pos.z=z;
 velocity=svmult(gun[0].muzzle_vel,front);
 velocity=vplus(velocity,v);

 while(!timeout && !impact) {

   velocity.z-=G*dtperframe;

   vtot=sqrt(SQR(velocity.x)+SQR(velocity.y)+SQR(velocity.z));
   density=atmospheric_density(pos.z);
   vloss=0.5*density*SQR(vtot)*0.0001*0.2*dtperframe/gun[0].projectile_mass;
   /*                            ^     ^ */
   /*                    frontarea dragcoeff */
   velocity=svmult(1-vloss/vtot,velocity);
   tmppos=vplus(pos,svmult(dtperframe,velocity));
   if (tmppos.z<groundalt(tmppos.x,tmppos.y)) {
     float z1,z2;
      /* this calc assumes flat ground */
     z1=pos.z-groundalt(pos.x,pos.y);
     z2=tmppos.z-groundalt(tmppos.x,tmppos.y);
     ccip_pos=vplus(svmult(z1/(z1-z2),vminus(tmppos,pos)),pos);
     impact=true;
   }
   pos=tmppos;
   time_passed+=dtperframe;
   if (time_passed>time_limit) timeout=true;
 }
 if (impact) {
  scrpos=scrpos3d(ccip_pos);
  if (scrpos.z==1) {
    putpixel(active_page, scrpos.x,scrpos.y,LIGHTGREEN);
    circle(active_page, scrpos.x,scrpos.y,10*xscl, LIGHTGREEN);
  }
 }
}



void generate_failure()
{
 int failid;

 if (npropengines > 0) {
   failid=rnd(npropengines);
   pengine[failid].power=0;
   pengine[failid].rpm_percent=0;
   pengine[failid].response=0;
 }
 else {
   failid=rnd(njetengines);
   if (detail_jet)
     jengine[failid].ignition = false;
   else {
     jengine[failid].power=0;
     jengine[failid].rpm=0;
     jengine[failid].response=0;
   }
 }
}



void updaterpm()
{
 int   i;
 float desire,drpm,drpmdt;
 float maxrpm=0;
 int   maxab=0;

 for (i=0; i<npropengines; i++)
 {
  pengine[i].throttle=throttle;
  desire=pengine[i].throttle-pengine[i].rpm_percent;
  drpmdt=pengine[i].response*dt;
  if (fabs(desire)>drpmdt)
    drpm=drpmdt*sgn(desire);
  else
    drpm=desire;
  pengine[i].rpm_percent += drpm;
  if(((ncalc % ncalcperframe)==0) && (i==0)) {
    if (!detail_prop) {
       engine_rpm_sound(pengine[i].rpm_percent);
    }
    else {
       engine_rpm_sound(100.0*pengine[i].rpm/(pengine[0].rpm_omega_high*60/(2*PI)));
    }
  }
 }

	for (i=0; i<nrocketengines; i++) {
		float rpm;

		rengine[i].throttle=throttle;

		rpm = ((rengine[i].throttle + 50) / 1.50 ) * rengine[i].ignition;
		if (rpm > maxrpm) maxrpm = rpm;

		if(((ncalc % ncalcperframe)==0) && (nrocketengines>0)) {
			engine_rpm_sound(maxrpm);
		}
	}


 maxrpm = 0;
 for (i=0; i<njetengines; i++)
 {


  if (detail_jet) {
    if (throttle_type == 1) {
     /* Only treat analog throttle */
    if (jengine[i].n_abstages > 0) {
      float ab_throttle;

      /* 70 % stroke = mil throttle */
      jengine[i].throttle=throttle/0.70;
      if (jengine[i].throttle > 100)
        jengine[i].throttle = 100;

      ab_throttle = (throttle - 75) / 26;
      if (ab_throttle < 0) ab_throttle = 0;
      if (ab_throttle > 1) ab_throttle = 1;

      jengine[i].ab_throttle = ab_throttle * (jengine[i].n_abstages+1);
    }
    else {
      /* No afterburner */
      jengine[i].throttle    = throttle;
      jengine[i].ab_throttle = 0;
    }
    }
    if (jengine[i].rpm > maxrpm) maxrpm=jengine[i].rpm;
    if (jengine[i].ab_status > maxab && jengine[i].ignition==true)
      maxab=jengine[i].ab_status;
  }
  else {
    /* Simple jet engine throttle */
    jengine[i].throttle=throttle;
    desire=jengine[i].throttle-jengine[i].rpm;
    drpmdt=jengine[i].response*dt;
    if (fabs(desire)>drpmdt)
      drpm=drpmdt*sgn(desire);
    else
      drpm=desire;
    jengine[i].rpm += drpm;
    if (jengine[i].rpm > maxrpm) maxrpm=jengine[i].rpm;
  }
 }

 if(((ncalc % ncalcperframe)==0) && (njetengines>0)) {
   if (detail_jet) {
     maxrpm-=jengine[0].idle_rpm;
     maxrpm*=100.0 / (100.0 - jengine[0].idle_rpm);
     if (maxrpm < 0) maxrpm = 0;
     if (ab_ignition) {
       play_wav(AB_IGNIT_WAV, 196*(float)engine_volume/255, 128, 400, false);
       ab_ignition=FALSE;
     }
     if (ab_starting) {
       ab_sound(true);
       ab_starting = FALSE;
     }
     if (ab_stopping) {
       ab_sound(false);
       ab_stopping = FALSE;
     }
     if (ab_burning)  ab_level_sound( (float) maxab / jengine[0].n_abstages);
   }
   engine_rpm_sound(maxrpm);
 }



 if (failure_upcoming)
    if (failure_time < lasttick) {
       generate_failure();
       failure_upcoming=false;
    }
}



void updateflap()
{
 float desire,dflap,dflapdt;

 if (poly_plane_id[current_model]==F14 && sweep > 55) setflap=0;

 desire=setflap-flap;
 if (desire!=0)
 {
  int stbflap, portflap;

  if (flap==0 || flap==8 || flap==16 || flap==24)
  play_wav(FLAP_WAV, 64, 128, 1000, false);
  dflapdt=flapresponse*dt;
  if (fabs(desire)>dflapdt)
     dflap=dflapdt*sgn(desire);
   else
     dflap=desire;
  flap += dflap;
  if (poly_plane_id[current_model]==F14) {
      stbflap = 4;
      portflap= 5;
  }
  else {
      stbflap = stbflapid;
      portflap= portflapid;
  }
  element[stbflap ].top.deflect     = noflapdeflect+flap/6;
  element[portflap].top.deflect     = noflapdeflect+flap/6;
  element[stbflap ].topcurvature    = noflapcurvature+flap/2;
  element[portflap].topcurvature    = noflapcurvature+flap/2;
  element[stbflap ].front.dragcoeff = noflapdragcoeff+abs(flap/100);
  element[portflap].front.dragcoeff = noflapdragcoeff+abs(flap/100);
  element[stbflap ].front.area      = noflapfrontarea*(1.+sin(flap*PI/180));
  element[portflap].front.area      = noflapfrontarea*(1.+sin(flap*PI/180));

  if (poly_plane_id[current_model]==F14) { /* Also outboard flaps */
      stbflap = 6;
      portflap= 7;
      element[stbflap ].top.deflect     = nooutflapdeflect+flap/6;
      element[portflap].top.deflect     = nooutflapdeflect+flap/6;
      element[stbflap ].topcurvature    = nooutflapcurvature+flap/2;
      element[portflap].topcurvature    = nooutflapcurvature+flap/2;
      element[stbflap ].front.dragcoeff = nooutflapdragcoeff+abs(flap/100);
      element[portflap].front.dragcoeff = nooutflapdragcoeff+abs(flap/100);
      element[stbflap ].front.area      = nooutflapfrontarea*(1.+sin(flap*PI/180));
      element[portflap].front.area      = nooutflapfrontarea*(1.+sin(flap*PI/180));
  }
  else {
    /* Flap center of pressure travel does not work with wing sweep */
    element[stbflap ].front.liftcenter = noflap_front_liftcenter+flap_cp_travel*flap/24;
    element[portflap].front.liftcenter = noflap_front_liftcenter+flap_cp_travel*flap/24;
  }
 }
}



void updatevector()
{
 int   i;
 float desire,dvect,dvectdt;

 for (i=0; i<njetengines; i++)
 {
  desire=jengine[i].vectordesire-jengine[i].vectorpos;
  if (desire!=0)
  {
   dvectdt=jengine[i].vectorresponse*dt;
   if (fabs(desire)>dvectdt)
     dvect=dvectdt*sgn(desire);
    else
     dvect=desire;
    jengine[i].vectorpos += dvect;
  }
 }
}



void updatesweep()
{
 float desire, dsweep, dsweepdt;

 if (!manual_sweep)
   set_sweep=auto_sweep(aircraft_mach_number);

 desire=set_sweep-sweep;
 if (desire != 0) {
  dsweepdt=7.5*dt;            /* max speed (1g) 7.5 deg/sec */
  if (fabs(desire)>dsweepdt)
   dsweep=dsweepdt*sgn(desire);
  else
   dsweep=desire;
  sweep += dsweep;
 }
}



void updatesweepfltmodel()
{
 float cossweep=cos(PI*sweep/180.0);
 float sinsweep=sin(PI*sweep/180.0);
 const float fulcrum_x=0.61; /* needs correction for CG? */
 const float fulcrum_y=2.91;
 float x1,y1,x2,y2;

 x1=outer_wing.left.masscenter -fulcrum_y;
 y1=outer_wing.front.masscenter-fulcrum_x;
 x2=x1*cossweep+y1*sinsweep;
 y2=y1*cossweep-x1*sinsweep;
 element[6].left.masscenter = x2+fulcrum_y;
 element[6].front.masscenter= y2+fulcrum_x;
 element[7].front.masscenter= element[6].front.masscenter;
 element[7].left.masscenter =-element[6].left.masscenter;

 x1=outer_wing.left.liftcenter -fulcrum_y;
 y1=outer_wing.front.liftcenter-fulcrum_x;
 x2=x1*cossweep+y1*sinsweep;
 y2=y1*cossweep-x1*sinsweep;
 element[6].left.liftcenter = x2+fulcrum_y;
 element[6].front.liftcenter= y2+fulcrum_x;
 element[7].front.liftcenter= element[6].front.liftcenter;
 element[7].left.liftcenter =-element[6].left.liftcenter;

 x1=outer_wing.left.dragcenter -fulcrum_y;
 y1=outer_wing.front.dragcenter-fulcrum_x;
 x2=x1*cossweep+y1*sinsweep;
 y2=y1*cossweep-x1*sinsweep;
 element[6].left.dragcenter = x2+fulcrum_y;
 element[6].front.dragcenter= y2+fulcrum_x;
 element[7].front.dragcenter= element[6].front.dragcenter;
 element[7].left.dragcenter =-element[6].left.dragcenter;


 x1=inner_wing.left.masscenter -fulcrum_y;
 y1=inner_wing.front.masscenter-fulcrum_x;
 x2=x1*cossweep+y1*sinsweep;
 y2=y1*cossweep-x1*sinsweep;
 element[4].left.masscenter = x2+fulcrum_y;
 element[4].front.masscenter= y2+fulcrum_x;
 element[5].front.masscenter= element[4].front.masscenter;
 element[5].left.masscenter =-element[4].left.masscenter;

 x1=inner_wing.left.liftcenter -fulcrum_y;
 y1=inner_wing.front.liftcenter-fulcrum_x;
 x2=x1*cossweep+y1*sinsweep;
 y2=y1*cossweep-x1*sinsweep;
 element[4].left.liftcenter = x2+fulcrum_y;
 element[4].front.liftcenter= y2+fulcrum_x;
 element[5].front.liftcenter= element[4].front.liftcenter;
 element[5].left.liftcenter =-element[4].left.liftcenter;

 x1=inner_wing.left.dragcenter -fulcrum_y;
 y1=inner_wing.front.dragcenter-fulcrum_x;
 x2=x1*cossweep+y1*sinsweep;
 y2=y1*cossweep-x1*sinsweep;
 element[4].left.dragcenter = x2+fulcrum_y;
 element[4].front.dragcenter= y2+fulcrum_x;
 element[5].front.dragcenter= element[4].front.dragcenter;
 element[5].left.dragcenter =-element[4].left.dragcenter;

 element[4].front.area=inner_wing.front.area*cossweep;
 element[5].front.area=element[4].front.area;
 element[6].front.area=outer_wing.front.area*cossweep;
 element[7].front.area=element[6].front.area;

 element[4].top.aspect=inner_wing.top.aspect*cossweep;
 element[5].top.aspect=element[4].top.aspect;
 element[6].top.aspect=outer_wing.top.aspect*cossweep;
 element[7].top.aspect=element[6].top.aspect;

 x1=outer_wing_tank.pos.y - fulcrum_y;
 y1=outer_wing_tank.pos.x - fulcrum_x;
 x2=x1*cossweep+y1*sinsweep;
 y2=y1*cossweep-x1*sinsweep;
 fueltank[0].pos.y = x2+fulcrum_y;
 fueltank[0].pos.x = y2+fulcrum_x;
 fueltank[1].pos.x = fueltank[0].pos.x;
 fueltank[1].pos.y =-fueltank[0].pos.y;

 front_superdrag = 0.5 + SQR(cossweep);

 /*
 if ((ncalc % ncalcperframe)==0) {
       setcolor(YELLOW);
       moveto(10*xscl,10*yscl);
       printfg(element[6].front.masscenter*100.,6,5);
       moveto(100*xscl,10*yscl);
       printfg(element[6].left.masscenter*100.,6,5);
      }
 */

 /*
 if ((ncalc % ncalcperframe)==0) {
       setcolor(YELLOW);
       moveto(10*xscl,10*yscl);
       printfg(fueltank[0].pos.x*100.,6,5);
       moveto(100*xscl,10*yscl);
       printfg(fueltank[0].pos.y*100.,6,5);
      }
 */
}



void update_DLC()
{
 if (!DLC_active) {
  if (setgear && setabrk) {
   DLC_active=true;
   DLC_spoiler=7.0;
  }
 }
 else if (!setabrk || sweep > 55) {
   DLC_active=false;
   DLC_spoiler=0.0;
 }
}



void update_spoilers()
{
 float desire, dspoil, dspoildt;

 desire=set_port_spoiler-port_spoiler;
 if (desire != 0) {
  dspoildt=3.0*dt;            /* full stroke in 0.33 sec */
  if (fabs(desire)>dspoildt)
   dspoil=dspoildt*sgn(desire);
  else
   dspoil=desire;
  port_spoiler += dspoil;
 }

 desire=set_stb_spoiler-stb_spoiler;
 if (desire != 0) {
  dspoildt=3.0*dt;            /* full stroke in 0.33 sec */
  if (fabs(desire)>dspoildt)
   dspoil=dspoildt*sgn(desire);
  else
   dspoil=desire;
  stb_spoiler += dspoil;
 }
}



void update_glove_vane()
{
 float desire, dvanedt, dvane;

 if (aircraft_mach_number > 1.40) desire_vane=1;
 if (aircraft_mach_number < 1.35) desire_vane=0;

 desire=desire_vane-glove_vane;
 if (desire != 0) {
  dvanedt=0.7*dt;   /* stroke 15 deg, speed 10.5 deg/sec */
  if (fabs(desire)>dvanedt)
   dvane=dvanedt*sgn(desire);
  else
   dvane=desire;
  glove_vane += dvane;
 }

 (object[F14].vertex+452)->x = (object[F14].vertex+450)->x+0.4  *glove_vane;
 (object[F14].vertex+452)->y = (object[F14].vertex+450)->y+0.605*glove_vane;

 (object[F14].vertex+453)->x = (object[F14].vertex+451)->x+0.4  *glove_vane;
 (object[F14].vertex+453)->y = (object[F14].vertex+451)->y-0.605*glove_vane;

 element[0].top.area=no_glove_body.top.area+glove_vane*1.72;
 element[0].front.liftcenter=no_glove_body.front.liftcenter+glove_vane;
 element[0].front.dragcenter=no_glove_body.front.dragcenter+glove_vane;
}



void updategear()
{
 int i;
 bool gear_snd=false;

 for (i=0 ; i<ngears ; i++) {
  float old_omega=gear[i].wheel_omega;
  float decell=2*PI;

  if (setgear==true && gear[i].strokepos==0 /* && gear[i].down<1 */) {
    /* Gear can only be lowered if free of ground */
    if (gear[i].down==0 && !gear_snd && gear[i].downrate!=0)
    play_wav(GEAR_WAV, 255, 180, 1000, false);
    gear_snd=true;
    gear[i].down += gear[i].downrate*dt;
    if (gear[i].down>1) gear[i].down=1;
  }
  if (setgear==false /* && gear[i].down>0 */) {
    if (gear[i].down==1 && !gear_snd && gear[i].downrate!=0)
    play_wav(GEAR_WAV, 255, 180, 1000, false);
    gear_snd=true;
    gear[i].down -= gear[i].downrate*dt;
    if (gear[i].down<0) gear[i].down=0;
  }
  /* 1 omdr/sek decelleration, stoerre hvis i fri luft, og der bremses */
  if (whlbrakes && gear[i].strokepos==0) decell *= 1.0+10*gear[i].brakeeffect;
  gear[i].wheel_omega -= dt*decell*sgn(gear[i].wheel_omega);
  if (gear[i].wheel_omega*old_omega < 0) gear[i].wheel_omega=0;
  if (gear[i].skid) gear[i].wheel_omega=0;
 }
}



void updateairbrake()
{
 if (setabrk==true) {
   airbrake.out += airbrake.outrate*dt;
   if (airbrake.out>1) airbrake.out=1;
 }
 if (setabrk==false) {
   airbrake.out -= airbrake.outrate*dt;
   if (airbrake.out<0) airbrake.out=0;
 }
}



void updatehook()
{
 if (sethook==true) {
   hook.down += hook.downrate*dt;
   if (hook.down>1) hook.down=1;
 }
 if (sethook==false) {
   hook.down -= hook.downrate*dt;
   if (hook.down<0) hook.down=0;
 }
}



void update_stall_horn()
{
 bool stalled=false;

 /* set stall_angle = 0 for disabling stall horn */
 if (pitch > stall_angle  && stall_angle!=0 &&
     crash==false && (viewpoint<4 || viewpoint==8 || viewpoint==10) /* In cockpit */ &&
     /* Needs 10 m/sec wind for activation */
     VPRIK(v_air,v_air) > 100 )
       stalled = true;

 if (stalled == true) {
    if (stall_horn_on==false) {
       stall_horn_on=true;
       stall_horn(true);
    }
 }
 else {
    if (stall_horn_on==true) {
       stall_horn_on=false;
       stall_horn(false);
    }
 }
}



void update_gear_rumble()
{
 bool to_play = false;

 if (gear_rumble_strength > 0 && ( viewpoint < 4 || viewpoint==8 || viewpoint==10) ) to_play=true;


 if (to_play) {
    if (!playing_gear_rumble) {
      play_gear_rumble(gear_rumble_strength);
      playing_gear_rumble=true;
    }
    else {
      adjust_gear_rumble(gear_rumble_strength);
    }
 }
 else if(playing_gear_rumble) {
        play_gear_rumble(0);
        playing_gear_rumble=false;
      }
}



void update_F14_auto_throttle()
/* New auto-throttle, regulated by AoA */
/* Integral - differential type servo */
{
 #define C_INT        (1.0)             // 100-1        best:    1   
 #define C_DIF     (1000.0)             // 10000-2000   best: 1000 
 #define THR_SPD     (10.)              // 10 

 //   1 , 1000, - 
 //  10, 10000, - 
 //  30, 3000, 10

 float error_signal = pitch*(180.0/PI) - desired_ldg_AOA;
 float pitch_chng   = (pitch - last_pitch) /* /dt */;

 if (THR_SPD > 0) {
   auto_throttle_integrator = (1.0-dt*THR_SPD)*auto_throttle_integrator + dt*THR_SPD*error_signal;
   if (last_throttle_error_signal*error_signal < 0 ) auto_throttle_integrator = 0;
 else
   auto_throttle_integrator = error_signal;
 }

 throttle  = auto_throttle_setting;
 throttle += C_INT*auto_throttle_integrator*dt;
 throttle += C_DIF*pitch_chng /* *dt */ ;

 if (throttle > 100) throttle = 100;
 if (throttle < 0  ) throttle =   0;

 /*
 if (ncalc % ncalcperframe==0) {
 setcolor(YELLOW);
 moveto(200*xscl,20*yscl);
 printfg(auto_throttle_setting*100,6,5);
 outtext(" base thr");
 moveto(200*xscl,30*yscl);
 printfg((C_INT*auto_throttle_integrator*dt)*100,6,5);
 outtext(" int thr");
 moveto(200*xscl,40*yscl);
 printfg((C_DIF*pitch_chng)*100,6,5);
 outtext(" dif thr");
 moveto(200*xscl,50*yscl);
 printfg(throttle*100,6,5);
 outtext(" res thr");
 }
 */

 auto_throttle_setting      = throttle;
 last_throttle_error_signal = error_signal;
 last_pitch                 = pitch;

 if (njetengines > 0 && detail_jet) {
   int i;
   for (i=0; i<njetengines; i++) {
     jengine[i].throttle=throttle;
     jengine[i].ab_throttle=0;
   }
 }
}



void update_LM_auto_throttle()
/* Proportional - Integral type servo */
{
	#define LM_C_INT      (10.0)
	#define LM_C_PRO      (20.0)	
	#define DESIRED_VZ    (-1.0)

	float error_signal = DESIRED_VZ - v.z;

	auto_throttle_integrator += dt * error_signal;

	if ( auto_throttle_integrator >  10 ) auto_throttle_integrator =  10;
	if ( auto_throttle_integrator < -10 ) auto_throttle_integrator = -10;

	throttle  = LM_C_PRO * error_signal;
	throttle += LM_C_INT * auto_throttle_integrator;

	if (throttle > 100) throttle = 100;
	if (throttle < 0  ) throttle =   0;

 /* 
 if (ncalc % ncalcperframe==0) {
 setcolor(YELLOW);
 moveto(200*xscl,20*yscl);
 printfg(throttle*100,6,5);
 outtext(" tot thr");

 moveto(200*xscl,30*yscl);
 printfg((LM_C_INT*auto_throttle_integrator)*100,6,5);
 outtext(" int thr");
 }
 */

}



void init_wind(int center_dir, int scatter_dir)
#define rnd(a)        random() % (int) a
{
 int direction,strength;

 if (wind_active==true && world == EARTH) {
  direction=center_dir+rnd(scatter_dir*2)-scatter_dir;
  if (direction < 0) direction += 360;
  strength=rnd(14)+2;

  /* strength=16; */
  /* Wind max 15 m/s = 31 kts */
  /* if (rnd(2)==0) strength=strength/2; */
 }
 else {
  direction=0;
  strength=0;
 }

 wind.x= strength*cos((float)PI*direction/180.0);
 wind.y= strength*sin((float)PI*direction/180.0);
 wind.z= 0;

 wind_direction=direction;
 wind_speed=strength;
}




void report_wind()
{
 int direction, strength;
 char report[MESSAGE_NAMELEN];

 direction=wind_direction;
 strength=wind_speed;
 strength*=1.944;

 direction=360-direction;
 if (direction==360) direction=0;

 sprintf(report,"Wind is %d degrees, %d knots",direction,strength);
 set_message(report,8,YELLOW);
}



void update_targets()
{
 int i;

 for (i=0; i<ntargets; i++) {
  float angle       = target[i].omega * elapsed_time;
  cartvektor oldpos = target[i].pos;
  float normfak;

  target[i].pos.x = target[i].radcen.x + cos(angle)*target[i].rad;
  target[i].pos.y = target[i].radcen.y + sin(angle)*target[i].rad;

  target[i].vel = svmult((1./dtperframe) ,vminus(target[i].pos, oldpos));

  normfak = sqrt( SQR(target[i].vel.x) +
                  SQR(target[i].vel.y) +
                  SQR(target[i].vel.z)
                 );
  if (normfak > 0.1)
     target[i].front = svmult(1./normfak, target[i].vel);

  if (target[i].rad > 0.1) {
     target[i].left = vminus( target[i].radcen, target[i].pos);
     normfak = sqrt( SQR(target[i].left.x) +
                     SQR(target[i].left.y) +
                     SQR(target[i].left.z)
                   );
     target[i].left = svmult( sgn(target[i].omega)/normfak, target[i].left);

  }
 }
}



void init_targets()
{
 float z;

 target[0].radcen.x=  7000.0+rnd(6000);
 target[0].radcen.y= -2000.0-rnd(6000);
 z = groundalt(target[0].radcen.x,target[0].radcen.y);
 if (z < 0 ) z = 0;
 target[0].radcen.z=  z+2;
 target[0].rad     =  0;
 target[0].omega   =  (3600.*2.*PI)/10;
 target[0].hitrad  =  2;
 target[0].pos.x   =  target[0].radcen.x+target[0].rad;
 target[0].pos.y   =  target[0].radcen.y;
 target[0].pos.z   =  target[0].radcen.z;
 target[0].strength=  10;
 target[0].nhits   =  0;
 target[0].vel.x   =  0;
 target[0].vel.y   =  0;
 target[0].vel.z   =  0;
 target[0].front.x =  1;
 target[0].front.y =  0;
 target[0].front.z =  0;
 target[0].left.x  =  0;
 target[0].left.y  =  1;
 target[0].left.z  =  0;
 target[0].top.x   =  0;
 target[0].top.y   =  0;
 target[0].top.z   =  1;


 if (ntargets > 1) {
   int i;
   for (i=1; i<ntargets; i++)
     {
       float v    = 50 + rnd(200);
       float acen = 1  + rnd(v/50);

       target[i].radcen.x=  7000.0+rnd(6000);
       target[i].radcen.y= -2000.0-rnd(6000);
       z = groundalt(target[i].radcen.x,target[i].radcen.y);
       if (z < 0 ) z = 0;
       target[i].radcen.z=  z+300+rnd(100)*100;
       target[i].rad     =  SQR(v)/(acen*G);
       target[i].omega   =  3600.0 * v / target[i].rad;
       if ( rnd(2) == 1) target[i].omega = -target[i].omega;
       target[i].hitrad  =  2;
       target[i].pos.x   =  target[i].radcen.x+target[i].rad;
       target[i].pos.y   =  target[i].radcen.y;
       target[i].pos.z   =  target[i].radcen.z;
       target[i].strength=  10;
       target[i].nhits   =  0;
       target[i].vel.x   =  0;
       target[i].vel.y   =  0;
       target[i].vel.z   =  0;
       /* Might be wrong for the first iteration: */
       target[i].front.x =  1;
       target[i].front.y =  0;
       target[i].front.z =  0;
       target[i].left.x  =  0;
       target[i].left.y  =  1;
       target[i].left.z  =  0;
       target[i].top.x   =  0;
       target[i].top.y   =  0;
       target[i].top.z   =  1;
     }
   }
}



void fill_fuel_tanks()
{
 /* Fills up tanks, starting with high indices */
 /* The same quantity is given to pairs of tanks */
 int i;
 float fuel_left = 0;

 for (i=0; i<nfueltanks; i++)
   fuel_left += fueltank[i].capacity;

 fuel_left *= start_fuel_fraction;

 for (i=nfueltanks-1; i>=0; i-=2) {
  float to_fill = fueltank[i].capacity;
  if (to_fill > 0.5 * fuel_left)
     to_fill = 0.5 * fuel_left;
  fueltank[i].content   = to_fill;
  fueltank[i-1].content = to_fill;
  fuel_left -= 2 * to_fill;
 }
}



float get_aircraft_empty_weight()
{
 float weight = 0;
 int i;

 for (i=0; i<nwingsections; i++)
   weight+=wingsection[i].weight;
 for (i=0; i<nelements; i++)
   weight+=element[i].weight;

 for (i=0; i<njetengines; i++)
   weight+=jengine[i].weight;

 for (i=0; i<npropengines; i++)
   weight+=pengine[i].weight;

 for (i=0; i<nrocketengines; i++)
   weight+=rengine[i].weight;

 for (i=0; i<ngears; i++)
   weight+=gear[i].weight;

 return weight;
}



float get_aircraft_fuel_qty()
{
 float qty = 0;
 int i;

 for (i=0; i<nfueltanks; i++)
     qty += fueltank[i].content;

 return qty;
}



float get_aircraft_fuel_capacity()
{
 float cap = 0;
 int i;

 for (i=0; i<nfueltanks; i++)
     cap += fueltank[i].capacity;

 return cap;
}



float get_aircraft_fuel_weight()
{
 return get_aircraft_fuel_qty() * rho_fuel;
}



bool consume_fuel(float fuel_flow)
{
 /* Input unit: liters/sec */
 /* Assumes same content in pairs of tanks */
 bool fuel_available = FALSE;
 float to_subtract = fuel_flow * dt / 2;
 int i;

 for (i=0; i<nfueltanks; i+=2) {
  if (fueltank[i].content > 0) {
   fueltank[i  ].content-=to_subtract;
   fueltank[i+1].content-=to_subtract;
   to_subtract = 0;
   fuel_available = TRUE;
  }
 }

 return fuel_available;
}
