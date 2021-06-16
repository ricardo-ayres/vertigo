#include <string.h>
#include "timestat.h"

extern unsigned long int ticks_8h;

static unsigned long int clock_tick[NCLOCKS];
static unsigned long int clock_start_tick[NCLOCKS];
static char              clock_name[NCLOCKS][NAMELEN];

void clock_reset()
{
 int i;

 for (i=0; i<NCLOCKS; i++) {
     clock_tick[i]=0;
     clock_start_tick[i]=0;
     clock_set_name(i,"Unused");
     }
}

void clock_start(int i)
{
 clock_start_tick[i]=ticks_8h;
}

void clock_stop(int i)
{
 clock_tick[i]+=ticks_8h-clock_start_tick[i];
}

unsigned long int clock_read(int i)
{
 return clock_tick[i];
}

void clock_set_name(int i, char *name)
{
 strcpy(clock_name[i],name);
}

char *clock_read_name(int i)
{
 return clock_name[i];
}
