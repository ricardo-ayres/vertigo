/*
#include <math.h>
#include "vertigo.h"
*/

void matrix_mult444(mat4 a, mat4 b, mat4 c)
/* Matrix multiplication c=a*b, all of size 4*4 */
{
 int i,j,k;
 float x;
 mat4 tmp;

 for (i=0; i<4; i++) {
  for (j=0; j<4; j++) {
   x=0;
   for (k=0; k<4; k++)
    x+=a[i][k]*b[k][j];
   tmp[i][j]=x;
  }
 }
 for (i=0; i<4; i++) {
  for (j=0; j<4; j++)
   c[i][j]=tmp[i][j];
 }
}



cartvektor matrix_mult411(mat4 a, cartvektor b)
/*  Multiplication (vector 1*3) c = (matrix 4*4) a * (vector 1*3) b */
{
 cartvektor c;

 c.x=a[0][0]*b.x+a[0][1]*b.y+a[0][2]*b.z+a[0][3];
 c.y=a[1][0]*b.x+a[1][1]*b.y+a[1][2]*b.z+a[1][3];
 c.z=a[2][0]*b.x+a[2][1]*b.y+a[2][2]*b.z+a[2][3];
 return(c);
}



void translate3D(cartvektor a, mat4 b)
/* Let b represent a matrix for translation by a */
{
 b[0][0]=1; b[0][1]=0; b[0][2]=0; b[0][3]=a.x;
 b[1][0]=0; b[1][1]=1; b[1][2]=0; b[1][3]=a.y;
 b[2][0]=0; b[2][1]=0; b[2][2]=1; b[2][3]=a.z;
 b[3][0]=0; b[3][1]=0; b[3][2]=0; b[3][3]=1;
}



void scale3D(cartvektor a, mat4 b)
/* Let b represent a matrix for scaling by a */
{
 b[0][0]=a.x; b[0][1]=0;   b[0][2]=0;   b[0][3]=0;
 b[1][0]=0;   b[1][1]=a.y; b[1][2]=0;   b[1][3]=0;
 b[2][0]=0;   b[2][1]=0;   b[2][2]=a.z; b[2][3]=0;
 b[3][0]=0;   b[3][1]=0;   b[3][2]=0;   b[3][3]=1;
}



void rot3D(float theta, int ax, mat4 b)
/* Let b represent a matrix for rotation by angle theta about axis ax */
{
 int ax1, ax2;
 float ct=cos(theta);
 float st=sin(theta);

 b[0][0]=0;   b[0][1]=0;   b[0][2]=0;   b[0][3]=0;
 b[1][0]=0;   b[1][1]=0;   b[1][2]=0;   b[1][3]=0;
 b[2][0]=0;   b[2][1]=0;   b[2][2]=0;   b[2][3]=0;
 b[3][0]=0;   b[3][1]=0;   b[3][2]=0;   b[3][3]=1;
 b[ax][ax]=1;
 ax1=ax+1;
 if (ax1==3) ax1=0;
 ax2=ax1+1;
 if (ax2==3) ax2=0;
 b[ax1][ax1]= ct;
 b[ax2][ax2]= ct;
 b[ax1][ax2]=-st;
 b[ax2][ax1]= st;
}



void genrot3D(cartvektor p, cartvektor q, float gamma, mat4 r)
/* Finds a matrix r that will rotate space an angle gamma around the
   axis given by p+u*q for every u */
{
 mat4 f, g, h, w, invf, invg, invh;
 float alpha, beta, nu;

 translate3D(svmult(-1,p),f);

 alpha=atan(q.y/q.x);        /**** DIV BY 0 HAZARD ***/
 rot3D(-alpha, zaxis, g);
 nu=sqrt(SQR(q.x)+SQR(q.y));
 beta=atan(nu/q.z);          /**** DIV BY 0 HAZARD ***/
 rot3D(-beta, yaxis, h);
 rot3D(gamma,zaxis,w);
 translate3D(p,invf);
 rot3D(alpha,zaxis,invg);
 rot3D(beta,yaxis,invh);

 matrix_mult444(g,f,r);
 matrix_mult444(h,r,r);
 matrix_mult444(w,r,r);
 matrix_mult444(invh,r,r);
 matrix_mult444(invg,r,r);
 matrix_mult444(invf,r,r);
}