#define INST_SCALE 0.6

void show_RPM_dial(int xcorn, int ycorn);
void show_MAN_dial(int xcorn, int ycorn);
void show_TURN_dial(int xcorn, int ycorn);
void show_ALT_dial(int xcorn, int ycorn);
void show_VVI_dial(int xcorn, int ycorn);
void show_IAS_dial(int xcorn, int ycorn);
void show_COMP_dial(int xcorn, int ycorn);
void show_ACC_dial(int xcorn, int ycorn);
void show_ILS_dial(int xcorn, int ycorn);
void show_HOR_dial(int xcorn, int ycorn);
void show_TANK_dial(int xcorn, int ycorn);
void show_FFLW_dial(int xcorn, int ycorn);
void show_JET_RPM_dial(int xcorn, int ycorn);
void show_JET_EGT_dial(int xcorn, int ycorn);
void show_JET_FFLW_dial(int xcorn, int ycorn);
void show_GEAR_dial(int xcorn, int ycorn);


void dial_cleanup();
void make_instruments();
float RPM_vin(float RPM, float minRPM, float maxRPM);
float MAN_vin(float man, float min_press, float min_vin, float max_press, float max_vin);
float VVI_vin(float vv, float max_vv);
float IAS_vin(float ias, float min_ias, float min_vin, float max_ias, float max_vin);
float ACC_vin(float acc, float min_acc, float max_acc);
float TANK_vin(float fuelfrac, int id);
float FFLW_vin(float flow, float max_flow, float min_vin, float max_vin);
float JET_RPM_tick(float rpm);
float JET_EGT_tick(float egt);
float JET_FFLW_tick(float fflw);
