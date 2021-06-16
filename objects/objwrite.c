
/*
    This file is part of the source code for the Vertigo flight simulator
    Copyright (C) 1998-2001 Anton Norup Soerensen, a_norup@post.tele.dk       

    This program is free software; you can redistribute it and/or modify
    it under the terms of the GNU General Public License as published by
    the Free Software Foundation; either version 2 of the License, or
    (at your option) any later version.

    This program is distributed in the hope that it will be useful,
    but WITHOUT ANY WARRANTY; without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
    GNU General Public License for more details.

    You should have received a copy of the GNU General Public License
    along with this program; if not, write to the Free Software
    Foundation, Inc., 675 Mass Ave, Cambridge, MA 02139, USA.
*/



/* Object definitions for the Vertigo flight simulator */

#include <stdlib.h>
#include <stdio.h>
#include "../bool.h"
#include "objects.h"
#include "objwrite.h"


object3D object[maxnobjects];

int nobjects=0;

bool many_colors=true;


void errormessage(char *text)
{
 printf("%s\n", text);
 exit(1);
}



void init()
{

 init_objects_a();
 init_objects_b();
 init_objects_c();
 init_objects_d();
 init_objects_e();
 init_objects_f();
 init_objects_g();
}



void save_objects(void)
{
 FILE *fp;
 int i;

 if((fp=fopen("objects.dat","wb"))==NULL)
   errormessage("Cannot create objects file");
 fwrite(&object, sizeof(object3D)*maxnobjects, 1, fp);

 for (i=0; i<maxnobjects; i++) {
     int j, nfacets;

     nfacets=object[i].nfacets;
     for (j=0; j<object[i].nctrl_srf; j++) nfacets+=object[i].ctrl_surface[j].nctrlpoly;

     fwrite(object[i].vertex, object[i].nvertices*sizeof(cartvektor), 1, fp);
     fwrite(object[i].facet,  nfacets*sizeof(polygon_struct), 1, fp);
 }

 fclose(fp);
}



int main(int argc, char *argv[])
{

 printf("3D-objects definition writer\n");
 printf("For the Vertigo flight simulator\n");
 printf("Version 0.24\n");
 printf("Copyright 2000 Anton Norup Soerensen\n");
 printf("This program with source code is distributed under the\n");
 printf("GNU General Public License, and may be modified and\n");
 printf("re-distributed under the conditions given therein\n");
 printf("Read the 'license' file for details\n");
 printf("Read the 'objects.txt' file on how to modify this program\n");

 init();
 save_objects();
 printf("\nFile 'objects.dat' written\n");

 return(0);

}
