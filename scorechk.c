#include <stdio.h>
#include "bool.h"
#include "objects/objects.h"
#include "vertigo.h"

int main()
{
 int current_model,input;
 float score;
 bool HUD_always_off;
 bool ILS_always_off;
 bool auto_coord_always_off;
 bool wind_always_active;
/* bool anti_bounce_always_off; */
 bool pengine_always_real;
 bool auto_throttle_always_off;
 char to_scramble[6];
 char scrambled[]="ACAB";

 printf("F-4U  : 1\n\r");
 printf("U-2   : 2\n\r");
 printf("F-104 : 3\n\r");
 printf("F-14A : 5\n\r");
 printf("Enter aircraft type ");
 scanf("%d",&current_model);
 printf("Enter score         ");
 scanf("%f",&score);
 printf("HUD on:1 off:0      ");
 scanf("%d",&input);
 HUD_always_off=1-input;
 printf("ILS on:1 off:0      ");
 scanf("%d",&input);
 ILS_always_off=1-input;
 printf("Realistic prop engine on:1 off:0      ");
 scanf("%d",&input);
 pengine_always_real=input;
 printf("Wind on:1 off:0      ");
 scanf("%d",&input);
 wind_always_active=input;
 printf("Auto-coordination on:1 off:0      ");
 scanf("%d",&input);
 auto_coord_always_off=1-input;
 /*
 printf("Bounce kludge on:1 off:0      ");
 scanf("%d",&input);
 anti_bounce_always_off=1-input;
 */
 printf("Auto-throttle on:1 off:0      ");
 scanf("%d",&input);
 auto_throttle_always_off=1-input;

 sprintf(to_scramble,"%05.2f",score);
 scrambled[0] += to_scramble[1]-'0';
 scrambled[1] += to_scramble[4]-'0';
 scrambled[1] += to_scramble[3]-'0';
 scrambled[2] += to_scramble[0]-'0';
 scrambled[2] += to_scramble[4]-'0';
 scrambled[3] += to_scramble[3]-'0';
 scrambled[3] += to_scramble[1]-'0';
 if (HUD_always_off==true) {
    scrambled[0] += 5;
    scrambled[1] += 2;
 }
 if (ILS_always_off==true) {
    scrambled[0] += 3;
    scrambled[3] += 1;
 }
 if (auto_coord_always_off)  scrambled[0] += 1;
 if (wind_always_active)     scrambled[1] += 1;
/* if (anti_bounce_always_off) scrambled[2] += 1; */
 if (!pengine_always_real && current_model==1 )   scrambled[3] += 1;
 if (!auto_throttle_always_off)                   scrambled[1] += 1;

 scrambled[0] += (char)current_model;
 scrambled[2] += 7-(char)current_model;

 printf("Validation code %s\n\r",scrambled);

 return 0;
}
