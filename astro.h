typedef struct {
        float ra,dec,mag;
        } star_form;

void init_stars();
void draw_stars();
void update_stars();
void find_mag_lim_id();
void update_sun(float time);
