
#include "../bool.h"
#include "objects.h"

#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "../vertigo.h"

/* In MYMATH.C */
cartvektor vplus(cartvektor a, cartvektor b);
cartvektor vminus(cartvektor a, cartvektor b);
cartvektor vkryds(cartvektor a, cartvektor b);
cartvektor svmult(float a, cartvektor b);
#include "../mymath.h"

extern object3D object[maxnobjects];
extern int nobjects;
extern bool many_colors;

extern void errormessage(char *text);

void init_objects_c()
{
 int id,i;
 polygon_struct *facetid;

 #include "nim_hull.c"
 #include "nim_deck.c"
 #include "nim_mk1.c"
 #include "nim_mk2.c"
 #include "nim_jbd.c"
}
