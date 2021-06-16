
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



void init_objects_b()
{
 int id,i,j,nfacets;
 short t17color;
 polygon_struct *facetid;

 #include "u2.c"

 #include "runway.c"

 #include "rw_mark.c"

 #include "map.c"

 #include "sun.c"

 #include "t17.c"

 #include "f104.c"

}
