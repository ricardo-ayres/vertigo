#include <math.h>
#include "bool.h"
#include "objects/objects.h"



float arccos(float v)
/* Returns inverse cos(v) with domain protection */
{
 if (v > 1) v=1;
 if (v < -1) v=-1;
 return(acos(v));
}



float arcsin(float v)
/* Returns inverse sin(v) with domain protection */
{
 if (v > 1) v=1;
 if (v < -1) v=-1;
 return(asin(v));
}

/* Returns x squared */
/* Also as macro: SQR */
float sqr(float x)
{
 return(x*x);
}



int sgn(float x)
/* Returns the sign of x */
{
 int s=0;

 if (x>0) s=1;
 if (x<0) s=-1;
 return(s);
}



cartvektor vkryds(cartvektor a, cartvektor b)
/* returns the cross product of a and b vectors */
{
 cartvektor c;

 c.x = a.y * b.z - a.z * b.y;
 c.y = a.z * b.x - a.x * b.z;
 c.z = a.x * b.y - a.y * b.x;

 return(c);
}



cartvektor vplus(cartvektor a, cartvektor b)
/* Adds two vectors */
{
 cartvektor c;

 c.x = a.x + b.x;
 c.y = a.y + b.y;
 c.z = a.z + b.z;

 return(c);
}



cartvektor vminus(cartvektor a, cartvektor b)
/* subtracts two vectors */
{
 cartvektor c;

 c.x = a.x - b.x;
 c.y = a.y - b.y;
 c.z = a.z - b.z;

 return(c);
}



cartvektor svmult(float a, cartvektor b)
/* returns the vector b multiplied by a scalar a */
{
 cartvektor c;

 c.x = a * b.x;
 c.y = a * b.y;
 c.z = a * b.z;

 return(c);
}


#include "mymath.h"

/* Returns the scalar (or dot) product of vectors a and b */
/* Also as macro: VPRIK */
float vprik(cartvektor a,cartvektor b)
{
 return( a.x*b.x + a.y*b.y + a.z*b.z );
}



#ifdef MATRIX
  #include "matrixma.c"
#endif



float degtorad(float v)
{
 return(v*PI/180.0);
}



float radtodeg(float v)
{
 return(v*180.0/PI);
}
