void print_matrix(mat4 a)
{
 printf("%f %f %f %f\n\r",a[0][0],a[0][1],a[0][2],a[0][3]);
 printf("%f %f %f %f\n\r",a[1][0],a[1][1],a[1][2],a[1][3]);
 printf("%f %f %f %f\n\r",a[2][0],a[2][1],a[2][2],a[2][3]);
 printf("%f %f %f %f\n\r",a[3][0],a[3][1],a[3][2],a[3][3]);
 printf("\n\r");
}



void print_vector(cartvektor a)
{
 printf("%f %f %f\n\r",a.x,a.y,a.z);
 printf("\n\r");
}



void test_matrix(void)
{
 cartvektor p,q;
 mat4 r;
 int i;

 p.x=1; p.y=0; p.z=1;
 q.x=3; q.y=4; q.z=5;

 genrot3D(p,q,pi/4,r);


 for (i=0; i<planelines; i++){
  planelooks[i].a=matrix_mult411(r,planelooks[i].a);
  planelooks[i].b=matrix_mult411(r,planelooks[i].b);
 }

}
