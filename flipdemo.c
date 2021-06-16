
#include <allegro.h>

#define SCX 320
#define SCY 200

BITMAP *page1, *page2;
BITMAP *active_page;




void flip()
{
 show_video_bitmap(active_page);

 if (active_page == page1) {
   active_page = page2;
 }
 else {
   active_page = page1;
 }
}



int setup_graph()
{
 set_color_depth(8);

 if (set_gfx_mode(GFX_AUTODETECT, SCX, SCY, 0, 2*SCY) != 0) {
      if (set_gfx_mode(GFX_SAFE, SCX, SCY, 0, 0) != 0) {
         set_gfx_mode(GFX_TEXT, 0, 0, 0, 0);
         allegro_message("Unable to set any graphic mode\n%s\n", allegro_error);
         return 1;
      }
 }

 page1 = create_video_bitmap(SCREEN_W, SCREEN_H);
 page2 = create_video_bitmap(SCREEN_W, SCREEN_H);

 if ((!page1) || (!page2)) {
      set_gfx_mode(GFX_TEXT, 0, 0, 0, 0);
      allegro_message("Unable to create two video memory pages\n");
      return 1;
 }

 active_page = page2;
 
 set_palette(default_palette);
 text_mode(-1);
 
 return 0;
}





void init()
{
 allegro_init();

 install_keyboard();

 setup_graph();
}



void finish()
{
 destroy_bitmap(page1);
 destroy_bitmap(page2);
}



void visual()
{
	clear_to_color(active_page, makecol(0,0,255));
	clear_to_color(active_page, makecol(0,255,0));
	clear_to_color(active_page, makecol(255,0,0));
}



int main()
{
 int crash=0;

 init();

 while (crash == 0)
 {
  visual();
  flip();
  if (key[KEY_SPACE]) crash = 1;
 } 
 
 finish();
 return(0);
}

END_OF_MAIN()
