void select_ctrl();
void select_magnif();
void introscreen();
void load_config();
void save_config();
void mainmenu();
void joy_center();
void select_start_loc();
void define_start_loc_carrier(int selection);
void define_start_loc_airfield(int selection);
void define_start_loc_moon(int selection);

enum location_id {
 RWY_00	         = 0,
 RWY_00_FINAL	 = 1,
 RWY_00_APPROACH = 2,
 TARMAC	         = 3,
 CARR_DECK       = 4,
 CARR_FINAL      = 5,
 CARR_APPROACH   = 6,
 CARR_CAT        = 7,
 HIGH_ALT        = 8,
 MOON_SURF       = 9,
 MOON_ALT        = 10
};

enum world_id {
	EARTH		= 0,
	MOON		= 1
};

enum graphres {
 R640X480    = 0,
 R800X600    = 1,
 R1024X768   = 2,
 R1366X768   = 3,
 R1440X900   = 4,
 R1920X1080  = 5,
};

