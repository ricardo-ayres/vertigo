void init_carrier(int xpos, int ypos);

void update_carrier();

float carrier_deck_alt(float x, float y);

int hook_deck_pos(float x, float y);

void draw_carrier();

cartvektor get_carrier_pos();

cartvektor get_carrier_speed(float x, float y);

cartvektor get_trap_pos(int wire_no, int side);

cartvektor get_LSO_pos();

cartvektor ILS_signal();

void LSO_comms();

void init_carrier_lights();

void init_catapults();

void update_catapults();

cartvektor get_catapult_pos();

cartvektor get_catapult_init_pos(int i);

void update_JBD();

void draw_JBD();

#define NCARRIERLIGHTS 67
