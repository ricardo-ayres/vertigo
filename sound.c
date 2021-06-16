#include "bool.h"
#include "objects/objects.h"
#include "vertigo.h"

#include <stdio.h>
#include <string.h>
#include "allegro.h"
#include "sound.h"
#include <math.h>
cartvektor vminus(cartvektor a, cartvektor b);
#include "mymath.h"
#include "carrier.h"

typedef struct {
	float dist_vol;
	float doppler;
	} snd_spec;

static int digicard  = -1;
static int midicard  = -1;
static int n_sounds  =  0;
static void *sound_item[MAXNSOUNDS];
static bool sound_on = true;

int sample_len[MAXNSOUNDS];

extern short talk_volume, engine_volume, effect_volume;
extern void warningmessage(char *text);
extern void errormessage(char *text);

void init_sound()
{
 int i;
 char filenames[MAXNSOUNDS][80];

 digicard =  1;
 n_sounds = 62;
 strcpy(filenames[ 0],"sound/cannon.wav");
 strcpy(filenames[ 1],"sound/screetch.wav");
 strcpy(filenames[ 2],"sound/gear_up.wav");
 strcpy(filenames[ 3],"sound/prop.wav");
 strcpy(filenames[ 4],"sound/jet_ext.wav");
 strcpy(filenames[ 5],"sound/crash.wav");
 strcpy(filenames[ 6],"sound/flaps.wav");
 strcpy(filenames[ 7],"sound/talk/call_bal.wav");
 strcpy(filenames[ 8],"sound/talk/vir_ball.wav");
 strcpy(filenames[ 9],"sound/talk/rog_ball.wav");
 strcpy(filenames[10],"sound/talk/lit_low.wav");
 strcpy(filenames[11],"sound/talk/low.wav");
 strcpy(filenames[12],"sound/talk/lit_high.wav");
 strcpy(filenames[13],"sound/talk/high.wav");
 strcpy(filenames[14],"sound/talk/lit_slow.wav");
 strcpy(filenames[15],"sound/talk/slow.wav");
 strcpy(filenames[16],"sound/talk/lit_fast.wav");
 strcpy(filenames[17],"sound/talk/fast.wav");
 strcpy(filenames[18],"sound/talk/lit_righ.wav");
 strcpy(filenames[19],"sound/talk/lin_righ.wav");
 strcpy(filenames[20],"sound/talk/lit_left.wav");
 strcpy(filenames[21],"sound/talk/lin_left.wav");
 strcpy(filenames[22],"sound/talk/eagle2.wav");
 strcpy(filenames[22],"sound/talk/wind_axi.wav");
 strcpy(filenames[23],"sound/talk/power.wav");
 strcpy(filenames[24],"sound/talk/waveoff.wav");
 strcpy(filenames[25],"sound/talk/bolter.wav");
 strcpy(filenames[26],"sound/talk/low_gear.wav");
 strcpy(filenames[27],"sound/talk/low_hook.wav");
 strcpy(filenames[28],"sound/talk/attitude.wav");
 strcpy(filenames[29],"sound/talk/keep_com.wav");
 strcpy(filenames[30],"sound/stall.wav");
 strcpy(filenames[31],"sound/warning.wav");
 strcpy(filenames[32],"sound/cat_lnch.wav");
 strcpy(filenames[33],"sound/rumble.wav");
 strcpy(filenames[34],"sound/ping.wav");
 strcpy(filenames[35],"sound/explode.wav");
 strcpy(filenames[36],"sound/ab_rmbl.wav");
 strcpy(filenames[37],"sound/ab_ignit.wav");
 strcpy(filenames[38],"sound/talk/n0.wav");
 strcpy(filenames[39],"sound/talk/n1.wav");
 strcpy(filenames[40],"sound/talk/n2.wav");
 strcpy(filenames[41],"sound/talk/n3.wav");
 strcpy(filenames[42],"sound/talk/n4.wav");
 strcpy(filenames[43],"sound/talk/n5.wav");
 strcpy(filenames[44],"sound/talk/n6.wav");
 strcpy(filenames[45],"sound/talk/n7.wav");
 strcpy(filenames[46],"sound/talk/n8.wav");
 strcpy(filenames[47],"sound/talk/n9.wav");
 strcpy(filenames[48],"sound/talk/point.wav");
 strcpy(filenames[49],"sound/talk/tom_ball.wav");
 strcpy(filenames[50],"sound/talk/cm_left.wav");
 strcpy(filenames[51],"sound/talk/cm_right.wav");
 strcpy(filenames[52],"sound/rocket.wav");
 strcpy(filenames[53],"sound/lm/eagle.wav");
 strcpy(filenames[54],"sound/lm/700.wav");
 strcpy(filenames[55],"sound/lm/540.wav");
 strcpy(filenames[56],"sound/lm/200.wav");
 strcpy(filenames[57],"sound/lm/100.wav");
 strcpy(filenames[58],"sound/lm/70.wav");
 strcpy(filenames[59],"sound/lm/50.wav");
 strcpy(filenames[60],"sound/lm/contact.wav");
 strcpy(filenames[61],"sound/lm/engstop.wav");

 /* Only defined for samples where needed. Assumes 1000 ticks/sec */
 for (i=0; i<MAXNSOUNDS; i++)
     sample_len[i]=0;
 sample_len[NUM_0_WAV] = 500-50;
 sample_len[NUM_1_WAV] = 330-50;
 sample_len[NUM_2_WAV] = 400-50;
 sample_len[NUM_3_WAV] = 330-50;
 sample_len[NUM_4_WAV] = 390-50;
 sample_len[NUM_5_WAV] = 330-50;
 sample_len[NUM_6_WAV] = 500-50;
 sample_len[NUM_7_WAV] = 400-50;
 sample_len[NUM_8_WAV] = 370-50;
 sample_len[NUM_9_WAV] = 310-50;
 sample_len[POINT_WAV] = 500-50;

 if (sound_on) {
  #ifndef MGUI
  printf("\nAttempting to initialize sound card.\n\r");
  #endif
  if (install_sound(digicard, midicard, NULL) != 0) {
     char text[255];
     sprintf(text,"\nError initialising sound system.\n%s\n Fix it, or add -nosound in call to continue.", allegro_error);
     warningmessage(text);
     sound_on = false;
  }
 }
 #ifndef MGUI
 else printf("Sound disabled.\n");
 #endif


 if (sound_on) {

  #ifndef MGUI
  printf("Digital sound driver: %s\n", digi_driver->name);
  printf("Description: %s\n\n", digi_driver->desc);
  #endif

  for (i=0; i<n_sounds; i++) {
     sound_item[i] = load_sample(filenames[i]);

     if (!sound_item[i]) {
        char text[255];

        sprintf(text,"Error reading sample: %s", filenames[i]);
        if (i==0) strcat(text,"\nYou probably forgot to use the 'pkunzip -d' option when unpacking.");
        errormessage(text);
     }
  }
 }
}



snd_spec sound_specs()
{
 extern float viewx, viewy, viewz;
 extern float x, y, z;
 extern cartvektor v, viewfront;
 extern short viewpoint;

 snd_spec svar;
 float v_closure;

 /* Lydstyrke aftager lineaert(!) med afstand. Max. ved dist<=50m */
 svar.dist_vol = 50/sqrt(SQR(viewx-x)+SQR(viewy-y)+SQR(viewz-z));

 if (svar.dist_vol > 1) svar.dist_vol=1;

 if (viewpoint==4 || viewpoint==7) {
    cartvektor p_carr=get_carrier_pos();
    cartvektor v_carr=get_carrier_speed(p_carr.x,p_carr.y);
    if (viewpoint==4)
       v_closure = VPRIK(v, viewfront);
    else
       v_closure = VPRIK(vminus(v,v_carr), viewfront);
    svar.doppler   = 1+v_closure/340.;        /* approx. v_sound m/sec */
    if (svar.doppler < 0.25) svar.doppler=0.25;    /* no extreme supersonic values */

 } else {
   svar.doppler = 1;
 }

 return svar;
}



void play_wav(int sample_id, int volume, int balance, int frequency, bool loop)
{
 if (sound_on) {
  snd_spec sound_params = sound_specs();
  play_sample((SAMPLE *)sound_item[sample_id],
             volume*sound_params.dist_vol*(float)effect_volume/255,
             balance,
             frequency/sound_params.doppler,
             loop);
 }
}



void play_rdo_wav(int sample_id, int volume, int balance, int frequency)
{
 if (sound_on) {
  play_sample((SAMPLE *)sound_item[sample_id],
             volume*(float)talk_volume/255,
             balance,
             frequency,
             false);
 }
}



void engine_sound(bool play_it)
{
 extern short npropengines, njetengines, nrocketengines;
 extern jetengine     jengine[maxnjetengines+1];
 extern propengine    pengine[maxnpropengines+1];

 if (sound_on) {
  if (npropengines > 0) {
    if (play_it) {
        play_wav(PROP_INT_WAV, 255*(float)engine_volume/255, 128, 900, true);
        engine_rpm_sound(pengine[0].rpm_percent);
    }
    else stop_sample((SAMPLE *)sound_item[PROP_INT_WAV]);
  }
  if (njetengines > 0) {
    if (play_it) {
       play_wav(JET_INT_WAV, 255*(float)engine_volume/255, 128, 1000, true);
       engine_rpm_sound(jengine[0].rpm);
    }
    else stop_sample((SAMPLE *)sound_item[JET_INT_WAV]);
  }
	if (nrocketengines > 0) {
		if (play_it) {
			play_wav(ROCKET_RMBL_WAV, 255*(float)engine_volume/255, 128, 1000, true);
			engine_rpm_sound(100.);
		}
	else stop_sample((SAMPLE *)sound_item[ROCKET_RMBL_WAV]);
  }
 }
}




void engine_rpm_sound(float rpm)
{
 extern short npropengines, njetengines, nrocketengines;
 extern short viewpoint;

 int frequency = 500+10*rpm;
 snd_spec sound_params = sound_specs();

 if (sound_on) {
  if (viewpoint<4 || viewpoint==8 || viewpoint==10) sound_params.dist_vol *= 0.5; /* In cockpit */

  if (npropengines > 0)
    adjust_sample((SAMPLE *)sound_item[PROP_INT_WAV],
                  255*sound_params.dist_vol*(float)engine_volume/255,
                  128,
                  /* (frequency+500)/sound_params.doppler, */
                  /* (frequency+300)/sound_params.doppler, */
                  (400+rpm*15)/sound_params.doppler,
                  true);
  if (njetengines > 0)
    adjust_sample((SAMPLE *)sound_item[JET_INT_WAV],
                  255*sound_params.dist_vol*(float)engine_volume/255,
                  128,
                  frequency/sound_params.doppler,
                  true);
  if (nrocketengines > 0)
    adjust_sample((SAMPLE *)sound_item[ROCKET_RMBL_WAV],
                  255*sound_params.dist_vol*(float)engine_volume/255*(rpm/100),
                  128,
                  1500/sound_params.doppler,
                  true);
 }
}



void ab_sound(bool play_it)
{
 extern short njetengines;
 extern jetengine     jengine[maxnjetengines+1];

 if (sound_on) {
  if (njetengines > 0) {
    if (play_it) {
       play_wav(AB_RUMBLE_WAV, 255*(float)engine_volume/255, 128, 2000, true);
       ab_level_sound( (float) ((int)jengine[0].ab_status)/jengine[0].n_abstages);
    }
    else stop_sample((SAMPLE *)sound_item[AB_RUMBLE_WAV]);
  }
 }
}



void ab_level_sound(float ab_level)
{
 extern short njetengines;
 extern short viewpoint;

 snd_spec sound_params = sound_specs();

 if (sound_on) {
  if (viewpoint<4 || viewpoint==8 || viewpoint==10) sound_params.dist_vol *= 0.5; /* In cockpit */


  ab_level = 0.5 + 0.5 * ab_level;

  if (njetengines > 0)
    adjust_sample((SAMPLE *)sound_item[AB_RUMBLE_WAV],
                  255*ab_level*sound_params.dist_vol*(float)engine_volume/255,
                  128,
                  2000/sound_params.doppler,
                  true);
 }
}



void exit_sound()
{
 int i;

 if (sound_on) {
 for (i=0; i<n_sounds; i++)
     destroy_sample((SAMPLE *)sound_item[i]);
 }
}



void set_nosound()
{
 sound_on = FALSE;
}



void stall_horn(bool active)
{
 if (sound_on) {
    if (active) {
       play_wav(STALL_HORN_WAV, effect_volume, 128, 1000, true);
    }
    else stop_sample((SAMPLE *)sound_item[STALL_HORN_WAV]);
 }
}



void play_gear_rumble(float strength)
{
 if (sound_on) {
    if (strength > 0) {
       play_wav(RUMBLE_WAV, effect_volume*strength, 128, 1000, true);
    }
    else stop_sample((SAMPLE *)sound_item[RUMBLE_WAV]);
 }
}



void adjust_gear_rumble(float strength)
{
 if (sound_on)
    adjust_sample((SAMPLE *)sound_item[RUMBLE_WAV],
                     effect_volume*strength,
                     128, 1000, true);
}


