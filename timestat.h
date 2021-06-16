#define NCLOCKS 15
#define NAMELEN 40

void clock_reset();
void clock_start(int i);
void clock_stop(int i);
unsigned long int clock_read(int i);
void clock_set_name(int i, char *name);
char *clock_read_name(int i);


