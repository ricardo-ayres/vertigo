

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

void init_objects_e()
{
 int id,i,j, nfacets;
 polygon_struct *facetid;

 #include "windbag.c"

 #include "target.c"

 #include "t17_cp.c"

 #include "corsa_cp.c"

 #include "u2_cp.c"

 #include "f104_cp.c"

 #include "harr_cp.c"

 #include "f14_cp.c"

 #include "addon1.c"

 #include "addon2.c"

 #include "addon3.c"

 #include "x15.c"

}
