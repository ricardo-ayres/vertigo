typedef unsigned short	Ushort;

struct stick {
	Ushort	a[4];
	Ushort	b[4];
};
typedef struct stick	STICK;

unsigned int readjoy(STICK *s, int joymask);
unsigned int polljoy(STICK *s, int mode, int mask, int nread, int delay);
