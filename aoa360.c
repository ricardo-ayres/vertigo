#include <stdio.h>

static float naca0012_cl[360];
static float naca0012_cd[360];
static float naca0012_cm[360];

/* In vertigo.c */
extern void errormessage(char *text);


void read_file(char filename[], float cl[], float cd[], float cm[])
/* Reads text file into array */
{
 FILE *fp;
 int i;
 char text[255];

 if ((fp=fopen(filename,"r")) == NULL) {
        sprintf(text,"Cannot open file: %s\n\r",filename);
        errormessage(text);
 }

 for (i=0; i<360; i++) {
     if(!feof(fp))
       fscanf(fp,"%f\n",&cl[i]);
     else {
       fclose(fp);
       sprintf(text,"Premature end of file: %s\n\r",filename);
       errormessage(text);
     }
 }

 for (i=0; i<360; i++) {
     if(!feof(fp))
       fscanf(fp,"%f\n",&cd[i]);
     else {
       fclose(fp);
       sprintf(text,"Premature end of file: %s\n\r",filename);
       errormessage(text);
     }
 }

 for (i=0; i<360; i++) {
     if(!feof(fp))
       fscanf(fp,"%f\n",&cm[i]);
     else {
       fclose(fp);
       sprintf(text,"Premature end of file: %s\n\r",filename);
       errormessage(text);
     }
 }

 fclose(fp);
}



void init_aoa_data()
{

 read_file("naca0012.dat", naca0012_cl, naca0012_cd, naca0012_cm);

}



float cl_naca(float alpha)
{
 int   idx1, idx2;
 float frac, cl1, cl2, cl;

 if (alpha >= 360) alpha -= 360;
 if (alpha < 0)    alpha += 360;

 idx1 = (int)alpha;
 idx2 = idx1+1;
 if (idx2 == 360) idx2=0;
 frac = alpha - idx1;

 cl1  = naca0012_cl[idx1];
 cl2  = naca0012_cl[idx2];

 cl   = cl1 + (cl2-cl1)*frac;

 /* Same sign convention as old c_l function */
 if (alpha > 90 && alpha < 270) cl = -cl;

 return cl;
}



float cd_naca(float alpha)
{
 int   idx1, idx2;
 float frac, cd1, cd2, cd;

 if (alpha >= 360) alpha -= 360;
 if (alpha < 0)    alpha += 360;

 idx1 = (int)alpha;
 idx2 = idx1+1;
 if (idx2 == 360) idx2=0;
 frac = alpha - idx1;

 cd1  = naca0012_cd[idx1];
 cd2  = naca0012_cd[idx2];

 cd   = cd1 + (cd2-cd1)*frac;

 return cd;
}



float cm_naca(float alpha)
{
 int   idx1, idx2;
 float frac, cm1, cm2, cm;

 if (alpha >= 360) alpha -= 360;
 if (alpha < 0)    alpha += 360;

 idx1 = (int)alpha;
 idx2 = idx1+1;
 if (idx2 == 360) idx2=0;
 frac = alpha - idx1;

 cm1  = naca0012_cm[idx1];
 cm2  = naca0012_cm[idx2];

 cm   = cm1 + (cm2-cm1)*frac;

 return cm;
}
