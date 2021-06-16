/*
 * Written by Eyal Lebedinsky (eyal@ise.canberra.edu.au).
 * This version: January 1994.
*/
/* Modified to not support timer option, that would not compile on */
/* older compiler, ANS */

#ifndef LINUX
#  include <conio.h>
#  include <dos.h>
#endif
#include <string.h>
#include "joystick.h"
#include "bool.h"
#include "objects/objects.h"
#include "vertigo.h"

#define CHANNEL_0       0x0040          /* system tick */
#define COMMAND_REG     0x0043
#define READ_SPECIAL    0x00c2
#define TIMER_MODES     0x000e
#define TIMER_MODE      0x0002
#define TIMER_OUT       0x0080

#define JS_PORT         0x201
#define JS_TIMEOUT      32000
#define JS_READ         inp (JS_PORT)

#define inp           inportb
#define outp          outportb

typedef unsigned int    Uint;
typedef unsigned long   Ulong;

static Ushort x1_arr[5];
static Ushort y1_arr[5];
static Ushort x2_arr[5];
static Ushort y2_arr[5];

extern int joy_n_sample;

/* These are the timer reading support functions. */

static Uint get_timer (void)
{
	Ushort          t, status /* ,flags */ ;

#ifndef LINUX
	do {
		outp (COMMAND_REG, READ_SPECIAL);
		status = (Ushort) inp (CHANNEL_0);
		t  = (Ushort)inp (CHANNEL_0);
		t += (Ushort)(inp (CHANNEL_0) << 8);
		} while (0 == t);
#else
 t=1; /* Suppress warning */
 status=1;
#endif

	return ((Uint)(Ushort)~((status & TIMER_MODES) == TIMER_MODE*2 ? t
		: ((t>>1) + (Ushort)((status&TIMER_OUT)<<8))));
}

#define READING (mode ? get_timer () : JS_TIMEOUT-i)



unsigned int polljoy (STICK *s, int mode, int mask, int nread, int delay)
{
	register int    i;
	register Uint   m;
	unsigned int    t, x1, y1, x2, y2, minx1, miny1, minx2, miny2;
	int             js, tt, ntimes;
#ifdef LINUX
 js=1; /* Suppress warning */
#endif

	minx1 = miny1 = minx2 = miny2 = 0xffffU; /* avoid compiler warning */
	memset (s->a, 0, sizeof (s->a));

	for (ntimes = 0;;) {
		i = JS_TIMEOUT;
		t = READING;
		x1 = y1 = x2 = y2 = t;
#ifndef LINUX
		outp (JS_PORT, 0);              /* set trigger */
#endif
		for (m = mask; m;) {
#ifndef LINUX
			while (!(~JS_READ & m) && --i)
				;
#endif
			if (!i)
				break;
			tt = READING;
#ifndef LINUX
			js = ~JS_READ & m;
#endif
			if (js & 0x01) {
				x1 = tt;
				m &= ~0x01;
			}
			if (js & 0x02) {
				y1 = tt;
				m &= ~0x02;
			}
			if (js & 0x04) {
				x2 = tt;
				m &= ~0x04;
			}
			if (js & 0x08) {
				y2 = tt;
				m &= ~0x08;
			}
		}
		if (minx1 > (x1 -= t))
			minx1 = x1;
		if (miny1 > (y1 -= t))
			miny1 = y1;
		if (minx2 > (x2 -= t))
			minx2 = x2;
		if (miny2 > (y2 -= t))
			miny2 = y2;

		if (++ntimes >= nread)  /* read more? */
			break;

		if (0 != (i = delay)) {         /* delay? */
			tt = 1234;
			for (i *= 10; i-- > 0;)
				tt *= 19;
		}
	}

	js = m | ~mask;
	s->a[0] = (js & 0x01) ? 0 : minx1;      /* analog 1 */
	s->a[1] = (js & 0x02) ? 0 : miny1;      /* analog 2 */
	s->a[2] = (js & 0x04) ? 0 : minx2;      /* analog 3 */
	s->a[3] = (js & 0x08) ? 0 : miny2;      /* analog 4 */

#ifndef LINUX
	js = ~JS_READ;
#endif
	s->b[0] = !!(js & 0x10);                /* button 1 */
	s->b[1] = !!(js & 0x20);                /* button 2 */
	s->b[2] = !!(js & 0x40);                /* button 3 */
	s->b[3] = !!(js & 0x80);                /* button 4 */

	return (m);



}



Ushort median(Ushort arr[])
{
 int           i;
 bool          ok=false;
 Ushort        temp;

 while (ok==false) {
  ok=true;
  for (i=0; i<joy_n_sample-1; i++) {
   if (arr[i] < arr[i+1]) {
    ok=false;
    temp=arr[i];
    arr[i]=arr[i+1];
    arr[i+1]=temp;
   }
  }
 }

 return arr[(joy_n_sample-1)/2];

 /* return arr[joy_n_sample-1]; */
}



unsigned int readjoy(STICK *s,int joymask)
{
 /* msec-timer suspended while reading joystick */
 unsigned int status=0;
 int i;

 /* disable(); */
 for (i=0; i<joy_n_sample; i++) {
#ifndef LINUX
     disable();
#endif
     status=polljoy(s, 0, joymask, 1, 0);
#ifndef LINUX
     enable();
#endif
     /*Pause(10);*/
     x1_arr[i]=s->a[0];
     y1_arr[i]=s->a[1];
     x2_arr[i]=s->a[2];
     y2_arr[i]=s->a[3];
 }
 /* enable(); */

 s->a[0]=median(x1_arr);
 s->a[1]=median(y1_arr);
 s->a[2]=median(x2_arr);
 s->a[3]=median(y2_arr);

 return(status);
}



STICK s[1];
