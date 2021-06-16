
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

void init_objects_a()
{
 int id,i,j,nfacets;
 polygon_struct *facetid;

 nobjects=0;

 #include "harrier.c"

 #include "corsair.c"

 #include "hangar.c"

 #include "tower.c"

}
