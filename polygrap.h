typedef struct {
  int x;
  int y;
  int status;
  } screencoord;

typedef struct {
  screencoord first;
  screencoord last;
  int         cross_sgn;
  } screenlinecoord;

typedef struct {
  bool rot;
  cartvektor front;
  cartvektor left;
  cartvektor top;
  } ori_vector;

typedef struct {
   cartvektor pos;
   bool       bright;
	float      showdist;
   int        color;
	} light;

void setup_sweep_buffer();
void update_sweep_graphics();
void local_filled_poly_to_queue(polygon_struct *flade, int id, cartvektor pos, float light, ori_vector orient);
void filled_poly_to_queue(polygon_struct *flade, int id, cartvektor pos, float light, ori_vector orient);
void map_to_poly_queue(cartvektor va, cartvektor vb, cartvektor vc, float light, int color);
void update_lightvector();
void sun_to_poly_queue();
linecoord calc_line_project(cartvektor p1, cartvektor p2);
screenlinecoord calc_frame_line(linecoord linec, float xpixels, float ypixels);
void filled_horizon();
void draw_map(float xcenter, float ycenter, float azimuth, int to_dist);
cartvektor rot_edge(cartvektor a, ori_vector orient);
void draw_rot_object(int id, cartvektor pos, ori_vector orient);
void draw_rot_line(cartvektor a, cartvektor b, cartvektor pos, ori_vector orient, int color, int vis_dist);
void draw_rot_point(cartvektor a, cartvektor pos, ori_vector orient, int color, int vis_dist, bool big, float yoffset);
void draw_ctrl_surfaces(int id);
void init_prop_graph();
void draw_propellers();
void init_airfield_lights();
void draw_airfield_lights();
int point_vect(cartvektor vect, int color);
void update_windbag();
