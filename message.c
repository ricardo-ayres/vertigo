#include <string.h>
#include "message.h"
#include <allegro.h>


static float time_left[N_MESSAGES];
static float msg_color[N_MESSAGES];
static char  message_name[N_MESSAGES][MESSAGE_NAMELEN];

extern float dtperframe;
extern FONT *font_big;
extern BITMAP *active_page;

void message_reset()
{
 int i;

 for (i=0; i<N_MESSAGES; i++) {
     time_left[i]=0;
     /* set_message("Initialized!",i,LIGHTGREEN); */
     }
}



void set_message(char *name, float t, short color)
{
 int free=-1;
 int i;

 for (i=0; i<N_MESSAGES; i++)
     if ((time_left[i]<=0) && (free==-1)) free=i;
 if (free!=-1){
    strcpy(message_name[free],name);
    time_left[free]=t;
    msg_color[free]=color;
 }
}



void update_message()
{
 int i;

 for (i=0; i<N_MESSAGES; i++) time_left[i]-=dtperframe;

}


void show_message() 
{
  int i,msg_num=0;

  for (i=0; i<N_MESSAGES; i++) {
    if(time_left[i]>0){
      msg_num++;
		  textout(active_page, font_big, message_name[i], 5, msg_num*text_height(font_big), msg_color[i]);
		}
  }
}
