/* Routines for the general orientation wing */

#include "bool.h"
#include "objects/objects.h"
#include "vertigo.h"
#include <math.h>
#include "mymath.h"

extern int nwingsections;
extern wingspecs     wingsection[maxnwingsections+1];



cartvektor rot_z(cartvektor to_rot, float angle)
{
 cartvektor result;

 result.x = cos(angle)*to_rot.x + sin(angle)*to_rot.y;
 result.y = cos(angle)*to_rot.y + sin(angle)*to_rot.x;
 result.z = to_rot.z;

 return result;
}



cartvektor rot_x(cartvektor to_rot, float angle)
{
 cartvektor result;

 result.x = to_rot.x;
 result.y = cos(angle)*to_rot.y + sin(angle)*to_rot.z;
 result.z = sin(angle)*to_rot.y + cos(angle)*to_rot.z;

 return result;
}



void convert_wing_angles()
{
 int i;

 for ( i=0; i<nwingsections ; i++ ) {
     float dihedral, sweep;

     dihedral =  wingsection[i].dihedral *PI/180.;
     sweep    = -wingsection[i].sweepback*PI/180.;

     /* Initial orthogonal orientation */
     wingsection[i].normal.x = 0;
     wingsection[i].normal.y = 0;
     wingsection[i].normal.z = 1;

     wingsection[i].leadingedge.x = 1;
     wingsection[i].leadingedge.y = 0;
     wingsection[i].leadingedge.z = 0;

     /* Apply sweep */
     wingsection[i].normal     =rot_z(wingsection[i].normal     , sweep);
     wingsection[i].leadingedge=rot_z(wingsection[i].leadingedge, sweep);

     /* Apply dihedral */
     wingsection[i].normal     =rot_x(wingsection[i].normal     , dihedral);
     wingsection[i].leadingedge=rot_x(wingsection[i].leadingedge, dihedral);

 }
}


