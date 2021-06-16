#define MAXNSOUNDS 62

#define CANNON_WAV        0
#define TOUCHDN_WAV       1
#define GEAR_WAV          2
#define PROP_INT_WAV      3
#define JET_INT_WAV       4
#define CRASH_WAV         5
#define FLAP_WAV          6
#define CALL_BALL_WAV     7
#define BALL_WAV          8
#define ROGER_BALL_WAV    9
#define LITTLE_LOW_WAV   10
#define LOW_WAV          11
#define LITTLE_HIGH_WAV  12
#define HIGH_WAV         13
#define LITTLE_SLOW_WAV  14
#define SLOW_WAV         15
#define LITTLE_FAST_WAV  16
#define FAST_WAV         17
#define LITTLE_RIGHT_WAV 18
#define RIGHT_WAV        19
#define LITTLE_LEFT_WAV  20
#define LEFT_WAV         21
#define WIND_AXI_WAV     22
#define POWER_WAV        23
#define WAVEOFF_WAV      24
#define BOLTER_WAV       25
#define LOWER_GEAR_WAV   26
#define LOWER_HOOK_WAV   27
#define ATTITUDE_WAV     28
#define KEEP_COMING_WAV  29
#define STALL_HORN_WAV   30
#define WARNING_WAV      31
#define CAT_LNCH_WAV     32
#define RUMBLE_WAV       33
#define PING_WAV         34
#define EXPLODE_WAV      35
#define AB_RUMBLE_WAV    36
#define AB_IGNIT_WAV     37
#define NUM_0_WAV        38
#define NUM_1_WAV        39
#define NUM_2_WAV        40
#define NUM_3_WAV        41
#define NUM_4_WAV        42
#define NUM_5_WAV        43
#define NUM_6_WAV        44
#define NUM_7_WAV        45
#define NUM_8_WAV        46
#define NUM_9_WAV        47
#define POINT_WAV        48
#define TOM_BALL_WAV     49
#define COME_LEFT_WAV    50
#define COME_RIGHT_WAV   51
#define ROCKET_RMBL_WAV  52
#define EAGLE_LAND_WAV   53
#define H700FT_WAV       54
#define H540FT_WAV       55
#define H200FT_WAV       56
#define H100FT_WAV       57
#define H70FT_WAV        58
#define H50FT_WAV        59
#define CONTACT_WAV      60
#define ENGINE_STOP_WAV  61

void init_sound();

void play_wav(int sample_id, int volume, int balance, int frequency, bool loop);

void play_rdo_wav(int sample_id, int volume, int balance, int frequency);

void exit_sound();

void engine_sound(bool play_it);

void engine_rpm_sound(float rpm);

void set_nosound();

void stall_horn(bool active);

void play_gear_rumble(float strength);

void adjust_gear_rumble(float strength);

void ab_sound(bool play_it);

void ab_level_sound(float ab_level);
