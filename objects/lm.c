/* H. Frik has made the graphics of this file */

 id=LM;
 object[id].max_draw_dist=5000;
 object[id].always_draw_dist=50;

 object[id].nvertices =  1723;//1707
 object[id].nfacets   =  1613; //1628
 object[id].nctrl_srf =  0;

 nfacets=object[id].nfacets;
 for (j=0; j<object[id].nctrl_srf; j++) nfacets+=object[id].ctrl_surface[j].nctrlpoly;

 if ((object[id].vertex = malloc(object[id].nvertices*sizeof(cartvektor))) == NULL)
 {
   printf("Not enough memory\n");
   exit(1);
 }

 if ((object[id].facet = malloc(nfacets*sizeof(polygon_struct))) == NULL)
 {
   printf("Not enough memory\n");
   exit(1);
 }
 facetid=object[id].facet;




  
 /*  1*/                                  
 (object[id].vertex+0)->x= -0.6858; 
 (object[id].vertex+0)->y= -2.0574;    
 (object[id].vertex+0)->z= -0.08;  

 (object[id].vertex+1)->x= 0.6858; 
 (object[id].vertex+1)->y=-2.0574;          
 (object[id].vertex+1)->z=-0.08; 
 
 (object[id].vertex+2)->x= 0.6858; 
 (object[id].vertex+2)->y= -2.0574;           
 (object[id].vertex+2)->z= 1.60;  

 (object[id].vertex+3)->x= -0.6858;
 (object[id].vertex+3)->y= -2.0574;              
 (object[id].vertex+3)->z= 1.60;  

 (object[id].vertex+4)->x= -0.6858;
 (object[id].vertex+4)->y= -0.6858;            
 (object[id].vertex+4)->z= -0.08; 

 (object[id].vertex+5)->x=-0.6858; 
 (object[id].vertex+5)->y= -0.6858;           
 (object[id].vertex+5)->z= 1.60;   

 (object[id].vertex+6)->x=  0.6858;  
 (object[id].vertex+6)->y= -0.6858;               
 (object[id].vertex+6)->z= -0.08;   

 (object[id].vertex+7)->x=  0.6858; 
 (object[id].vertex+7)->y= -0.6858;                 
 (object[id].vertex+7)->z= 1.60;  
	
 /* 2*/                                  
 (object[id].vertex+8)->x= -2.0574;        
 (object[id].vertex+8)->y= -0.6858;   
 (object[id].vertex+8)->z= -0.08;           

 (object[id].vertex+9)->x=-0.6858;   
 (object[id].vertex+9)->y=-0.6858;    
 (object[id].vertex+9)->z=-0.08;      

 (object[id].vertex+10)->x=-0.6858;    
 (object[id].vertex+10)->y= -0.6858;   
 (object[id].vertex+10)->z=1.60;      

 (object[id].vertex+11)->x=-2.0574; 
 (object[id].vertex+11)->y=-0.6858; 
 (object[id].vertex+11)->z=1.60; 

 (object[id].vertex+12)->x= -2.0574; 
 (object[id].vertex+12)->y= 0.6858; 
 (object[id].vertex+12)->z=-0.08; 

 (object[id].vertex+13)->x=-2.0574; 
 (object[id].vertex+13)->y= 0.6858; 
 (object[id].vertex+13)->z=1.60;  

 (object[id].vertex+14)->x=-0.6858;  
 (object[id].vertex+14)->y= 0.6858; 
 (object[id].vertex+14)->z=-0.08;  

 (object[id].vertex+15)->x=-0.6858; 
 (object[id].vertex+15)->y= 0.6858; 
 (object[id].vertex+15)->z=1.60;  
	
 /* 3*/                                   
 (object[id].vertex+16)->x= 2.0574; 
 (object[id].vertex+16)->y= -0.6858; 
 (object[id].vertex+16)->z= -0.08; 

 (object[id].vertex+17)->x= 0.6858; 
 (object[id].vertex+17)->y=-0.6858; 
 (object[id].vertex+17)->z=-0.08;  

 (object[id].vertex+18)->x= 0.6858;  
 (object[id].vertex+18)->y= -0.6858; 
 (object[id].vertex+18)->z=1.60; 

 (object[id].vertex+19)->x= 2.0574; 
 (object[id].vertex+19)->y=-0.6858; 
 (object[id].vertex+19)->z=1.60; 

 (object[id].vertex+20)->x= 2.0574; 
 (object[id].vertex+20)->y= 0.6858; 
 (object[id].vertex+20)->z=-0.08; 

 (object[id].vertex+21)->x= 2.0574;
 (object[id].vertex+21)->y= 0.6858; 
 (object[id].vertex+21)->z=1.60;  

 (object[id].vertex+22)->x= 0.6858;  
 (object[id].vertex+22)->y= 0.6858;
 (object[id].vertex+22)->z=-0.08;  

 (object[id].vertex+23)->x= 0.6858; 
 (object[id].vertex+23)->y= 0.6858; 
 (object[id].vertex+23)->z=1.60;  
	
 /* Heat Shield */                                 
 (object[id].vertex+24)->x= 1.60; 
 (object[id].vertex+24)->y= -0.35;  
 (object[id].vertex+24)->z= -0.08;  

 (object[id].vertex+25)->x=1.48;  
 (object[id].vertex+25)->y=-0.35; 
 (object[id].vertex+25)->z=-0.30;    

 (object[id].vertex+26)->x=1.60;  
 (object[id].vertex+26)->y= 0.35; 
 (object[id].vertex+26)->z=-0.08;

 (object[id].vertex+27)->x=1.48;    
 (object[id].vertex+27)->y= 0.35;  
 (object[id].vertex+27)->z=-0.30;

 (object[id].vertex+28)->x= -0.35;    
 (object[id].vertex+28)->y= 1.48; 	  
 (object[id].vertex+28)->z=-0.30;    

 (object[id].vertex+29)->x= -0.35;    
 (object[id].vertex+29)->y= 1.60;    
 (object[id].vertex+29)->z=-0.08;  

 (object[id].vertex+30)->x=0.35;       
 (object[id].vertex+30)->y= 1.48;   
 (object[id].vertex+30)->z=-0.30;  
 
 (object[id].vertex+31)->x=0.35;    
 (object[id].vertex+31)->y= 1.60;   
 (object[id].vertex+31)->z=-0.08;      
	
 (object[id].vertex+104)->x=-1.48;        
 (object[id].vertex+104)->y= 0.35;   
 (object[id].vertex+104)->z=-0.30;     
 
 (object[id].vertex+105)->x=-1.60;      
 (object[id].vertex+105)->y= 0.35;   
 (object[id].vertex+105)->z=-0.08;      
 
 (object[id].vertex+106)->x=-1.48;        
 (object[id].vertex+106)->y= -0.35;       
 (object[id].vertex+106)->z=-0.30;     
 
 (object[id].vertex+107)->x=-1.60;      
 (object[id].vertex+107)->y= -0.35;        
 (object[id].vertex+107)->z=-0.08;      
 
 (object[id].vertex+108)->x= -0.35;       
 (object[id].vertex+108)->y= -1.48;        
 (object[id].vertex+108)->z=-0.30;     
 
 (object[id].vertex+109)->x=-0.35;      
 (object[id].vertex+109)->y= -1.60;        
 (object[id].vertex+109)->z=-0.08;      

 (object[id].vertex+110)->x= 0.35;        
 (object[id].vertex+110)->y= -1.48;        
 (object[id].vertex+110)->z=-0.30;     
 
 (object[id].vertex+111)->x= 0.35;      
 (object[id].vertex+111)->y= -1.60;        
 (object[id].vertex+111)->z=-0.08;      

 (object[id].vertex+112)->x= 1.48;        
 (object[id].vertex+112)->y= -0.35;        
 (object[id].vertex+112)->z=-0.30;     
 
 (object[id].vertex+113)->x= 1.60;      
 (object[id].vertex+113)->y= -0.35;       
 (object[id].vertex+113)->z=-0.08;       

 /* 5 */ 
 (object[id].vertex+32)->x= -0.6858; 
 (object[id].vertex+32)->y= 0.6858;   
 (object[id].vertex+32)->z= -0.08;

 (object[id].vertex+33)->x=0.6858; 
 (object[id].vertex+33)->y=0.6858; 
 (object[id].vertex+33)->z=-0.08;    

 (object[id].vertex+34)->x= 0.6858;     
 (object[id].vertex+34)->y= 0.6858; 
 (object[id].vertex+34)->z=1.60; 

 (object[id].vertex+35)->x=-0.6858;
 (object[id].vertex+35)->y= 0.6858; 
 (object[id].vertex+35)->z=1.60;  

 (object[id].vertex+36)->x= -0.6858; 
 (object[id].vertex+36)->y= 2.0574; 
 (object[id].vertex+36)->z=-0.08; 

 (object[id].vertex+37)->x=-0.6858; 
 (object[id].vertex+37)->y= 2.0574; 
 (object[id].vertex+37)->z=1.60;  

 (object[id].vertex+38)->x= 0.6858;  
 (object[id].vertex+38)->y= 2.0574; 
 (object[id].vertex+38)->z=-0.08;  

 (object[id].vertex+39)->x=0.6858;
 (object[id].vertex+39)->y=2.0574; 
 (object[id].vertex+39)->z=1.60; 

 	                                                    
 /* Landing pad 1 */
 for (i=0; i<8; i++){
  float xc=4.25628 , yc= 0.00, zc=-1.1, radius=0.47; 

  (object[id].vertex+40+i)->x=xc+radius*sin(i*PI/4+PI/8);
  (object[id].vertex+40+i)->y=yc+radius*cos(i*PI/4+PI/8);
  (object[id].vertex+40+i)->z=zc;
 }
 
 /* Landing pad 1 */
 for (i=0; i<8; i++){
  float xc=4.25628, yc= 0.00, zc=-1.2, radius=0.35;                      

  (object[id].vertex+48+i)->x=xc+radius*sin(i*PI/4+PI/8);
  (object[id].vertex+48+i)->y=yc+radius*cos(i*PI/4+PI/8);
  (object[id].vertex+48+i)->z=zc;
 }

 /* Landing pad 2 */
 for (i=0; i<8; i++){
  float xc=0.00 , yc= 4.25628, zc=-1.1, radius=0.47;

  (object[id].vertex+56+i)->x=xc+radius*sin(i*PI/4+PI/8);
  (object[id].vertex+56+i)->y=yc+radius*cos(i*PI/4+PI/8);
  (object[id].vertex+56+i)->z=zc;
 }
	
   /* Landing pad 2 */
 for (i=0; i<8; i++){
  float xc=0.00 , yc= 4.25628, zc=-1.2, radius=0.35;

  (object[id].vertex+64+i)->x=xc+radius*sin(i*PI/4+PI/8);
  (object[id].vertex+64+i)->y=yc+radius*cos(i*PI/4+PI/8);
  (object[id].vertex+64+i)->z=zc;
 }
 
   /* Landing pad 3 */
 for (i=0; i<8; i++){
  float xc=0.00 , yc= -4.25628, zc=-1.1, radius=0.47;

  (object[id].vertex+72+i)->x=xc+radius*sin(i*PI/4+PI/8);
  (object[id].vertex+72+i)->y=yc+radius*cos(i*PI/4+PI/8);
  (object[id].vertex+72+i)->z=zc;
 }

    /* Landing pad 3 */
 for (i=0; i<8; i++){
  float xc=0.00 , yc= -4.25628, zc=-1.2, radius=0.35;

  (object[id].vertex+80+i)->x=xc+radius*sin(i*PI/4+PI/8);
  (object[id].vertex+80+i)->y=yc+radius*cos(i*PI/4+PI/8);
  (object[id].vertex+80+i)->z=zc;
 }

   /* Landing pad 4 */
 for (i=0; i<8; i++){
  float xc=-4.25628 , yc= 0.00, zc=-1.1, radius=0.47;

  (object[id].vertex+88+i)->x=xc+radius*sin(i*PI/4+PI/8);
  (object[id].vertex+88+i)->y=yc+radius*cos(i*PI/4+PI/8);
  (object[id].vertex+88+i)->z=zc;
 }

    /* Landing pad 4 */
 for (i=0; i<8; i++){
  float xc=-4.25628 , yc= 0.00, zc=-1.2, radius=0.35;

  (object[id].vertex+96+i)->x=xc+radius*sin(i*PI/4+PI/8);
  (object[id].vertex+96+i)->y=yc+radius*cos(i*PI/4+PI/8);
  (object[id].vertex+96+i)->z=zc;
 }
 
  (object[id].vertex+114)->x= 1.20; 
  (object[id].vertex+114)->y= 1.20; 	
  (object[id].vertex+114)->z=2.70;

  (object[id].vertex+115)->x=-1.20;
  (object[id].vertex+115)->y= 1.20;     
  (object[id].vertex+115)->z= 2.70;

  (object[id].vertex+116)->x= -1.20; 
  (object[id].vertex+116)->y= -1.20;      
  (object[id].vertex+116)->z= 2.70;

  (object[id].vertex+117)->x=1.20; 
  (object[id].vertex+117)->y= -1.20;   
  (object[id].vertex+117)->z= 2.70;
 
/* Decent Engine */  
 for (i=0; i<8; i++){
  float xc=0.00 , yc= 0.00, zc=-0.30, radius=0.54;

  (object[id].vertex+118+i)->x=xc+radius*sin(i*PI/4+PI/8);
  (object[id].vertex+118+i)->y=yc+radius*cos(i*PI/4+PI/8);
  (object[id].vertex+118+i)->z=zc;
 }

    /* Decent Engine */
 for (i=0; i<8; i++){
  float xc=0.00 , yc= 0.00, zc=-0.89, radius=0.70;

  (object[id].vertex+126+i)->x=xc+radius*sin(i*PI/4+PI/8);
  (object[id].vertex+126+i)->y=yc+radius*cos(i*PI/4+PI/8);
  (object[id].vertex+126+i)->z=zc;
 }
  
     /* Landing Gear 1 */  
 for (i=0; i<8; i++){
  float xc=-3.10, yc= 0.00, zc=1.18, radius=0.07; 

  (object[id].vertex+134+i)->x=xc+radius*sin(i*PI/4+PI/8);
  (object[id].vertex+134+i)->y=yc+radius*cos(i*PI/4+PI/8);
  (object[id].vertex+134+i)->z=zc;
 }

    /* Landing Gear 1 */
 for (i=0; i<8; i++){
  float xc=-3.895 , yc= 0.00, zc=-0.40, radius=0.07; 
        
  (object[id].vertex+142+i)->x=xc+radius*sin(i*PI/4+PI/8);
  (object[id].vertex+142+i)->y=yc+radius*cos(i*PI/4+PI/8);
  (object[id].vertex+142+i)->z=zc;
 }
 
     /* Landing Gear 2 */  
 for (i=0; i<8; i++){
  float xc=0.00 , yc= 3.10, zc=1.18, radius=0.07; 

  (object[id].vertex+150+i)->x=xc+radius*sin(i*PI/4+PI/8);
  (object[id].vertex+150+i)->y=yc+radius*cos(i*PI/4+PI/8);
  (object[id].vertex+150+i)->z=zc;
 }

    /* Landing Gear 2 */
 for (i=0; i<8; i++){
  float xc=0.0 , yc= 3.895, zc=-0.40, radius=0.07;
                   
  (object[id].vertex+158+i)->x=xc+radius*sin(i*PI/4+PI/8);
  (object[id].vertex+158+i)->y=yc+radius*cos(i*PI/4+PI/8);
  (object[id].vertex+158+i)->z=zc;
 }
  
      /* Landing Gear 3 */  
 for (i=0; i<8; i++){
  float xc=0.00 , yc= -3.10, zc=1.18, radius=0.07; 

  (object[id].vertex+166+i)->x=xc+radius*sin(i*PI/4+PI/8);
  (object[id].vertex+166+i)->y=yc+radius*cos(i*PI/4+PI/8);
  (object[id].vertex+166+i)->z=zc;
 }

    /* Landing Gear 3 */
 for (i=0; i<8; i++){
  float xc=0.0 , yc= -3.895, zc=-0.40, radius=0.07;
                    
  (object[id].vertex+174+i)->x=xc+radius*sin(i*PI/4+PI/8);
  (object[id].vertex+174+i)->y=yc+radius*cos(i*PI/4+PI/8);
  (object[id].vertex+174+i)->z=zc;
 }
 
       /* Landing Gear 4 */ 
 for (i=0; i<8; i++){
  float xc=3.10 , yc= 0.00, zc=1.18, radius=0.07; 

  (object[id].vertex+182+i)->x=xc+radius*sin(i*PI/4+PI/8);
  (object[id].vertex+182+i)->y=yc+radius*cos(i*PI/4+PI/8);
  (object[id].vertex+182+i)->z=zc;
 }

    /* Landing Gear 4 */
 for (i=0; i<8; i++){
  float xc=3.895 , yc= 0.00, zc=-0.40, radius=0.07; 
         
  (object[id].vertex+190+i)->x=xc+radius*sin(i*PI/4+PI/8);
  (object[id].vertex+190+i)->y=yc+radius*cos(i*PI/4+PI/8);
  (object[id].vertex+190+i)->z=zc;
 }

        /* 1 1 */ 
 for (i=0; i<8; i++){
  float xc=1.53 , yc=0.60, zc=-2.0574, radius=0.07;  

  (object[id].vertex+198+i)->z=xc+radius*sin(i*PI/4+PI/8); 
  (object[id].vertex+198+i)->x=yc+radius*cos(i*PI/4+PI/8);
  (object[id].vertex+198+i)->y=zc;
 }

    /*  1 1 */
 for (i=0; i<8; i++){
  float xc=1.40, yc=0.40, zc=-2.45, radius=0.15;

  (object[id].vertex+206+i)->z=xc+radius*sin(i*PI/4+PI/8); 
  (object[id].vertex+206+i)->x=yc+radius*cos(i*PI/4+PI/8);
  (object[id].vertex+206+i)->y=zc;
 }

         /* 2 1  */ 
 for (i=0; i<8; i++){
  float xc=1.53 , yc=-0.60, zc=-2.0574, radius=0.07;   

  (object[id].vertex+214+i)->z=xc+radius*sin(i*PI/4+PI/8); 
  (object[id].vertex+214+i)->x=yc+radius*cos(i*PI/4+PI/8);
  (object[id].vertex+214+i)->y=zc;
 }

    /* 2 1 */
 for (i=0; i<8; i++){
  float xc=1.40 , yc=-0.40, zc=-2.45, radius=0.15;

  (object[id].vertex+222+i)->z=xc+radius*sin(i*PI/4+PI/8); 
  (object[id].vertex+222+i)->x=yc+radius*cos(i*PI/4+PI/8);
  (object[id].vertex+222+i)->y=zc;
 }

           /* 3  */  
 for (i=0; i<8; i++){
  float xc=1.53 , yc=0.60, zc=2.0574, radius=0.07;   

  (object[id].vertex+230+i)->z=xc+radius*sin(i*PI/4+PI/8); 
  (object[id].vertex+230+i)->x=yc+radius*cos(i*PI/4+PI/8);
  (object[id].vertex+230+i)->y=zc;
 }

    /* 3 */
 for (i=0; i<8; i++){
  float xc=1.40 , yc=0.40, zc=2.45, radius=0.15; 

  (object[id].vertex+238+i)->z=xc+radius*sin(i*PI/4+PI/8); 
  (object[id].vertex+238+i)->x=yc+radius*cos(i*PI/4+PI/8);
  (object[id].vertex+238+i)->y=zc;
 }
 
           /* 4   */  
 for (i=0; i<8; i++){
  float xc=1.53 , yc=-0.60, zc=2.0574, radius=0.07;   

  (object[id].vertex+246+i)->z=xc+radius*sin(i*PI/4+PI/8); 
  (object[id].vertex+246+i)->x=yc+radius*cos(i*PI/4+PI/8);
  (object[id].vertex+246+i)->y=zc;
 }

    /* 4  */
 for (i=0; i<8; i++){
  float xc=1.40 , yc=-0.40, zc=2.45, radius=0.15; 

  (object[id].vertex+254+i)->z=xc+radius*sin(i*PI/4+PI/8); 
  (object[id].vertex+254+i)->x=yc+radius*cos(i*PI/4+PI/8);
  (object[id].vertex+254+i)->y=zc;
 }
 
            /* 5   */  
 for (i=0; i<8; i++){        
  float xc=0.60 , yc=1.53, zc=2.0574, radius=0.07;   

  (object[id].vertex+262+i)->y=xc+radius*sin(i*PI/4+PI/8); 
  (object[id].vertex+262+i)->z=yc+radius*cos(i*PI/4+PI/8);
  (object[id].vertex+262+i)->x=zc;
 }

    /* 5  */   
 for (i=0; i<8; i++){
  float xc=0.40 , yc=1.40, zc=2.45, radius=0.15;

  (object[id].vertex+270+i)->y=xc+radius*sin(i*PI/4+PI/8); 
  (object[id].vertex+270+i)->z=yc+radius*cos(i*PI/4+PI/8);
  (object[id].vertex+270+i)->x=zc;
 }
 
             /*6   */       
 for (i=0; i<8; i++){
  float xc=-0.60 , yc=1.53, zc=2.0574, radius=0.07;   

  (object[id].vertex+278+i)->y=xc+radius*sin(i*PI/4+PI/8); 
  (object[id].vertex+278+i)->z=yc+radius*cos(i*PI/4+PI/8);
  (object[id].vertex+278+i)->x=zc;
 }

    /* 6  */
 for (i=0; i<8; i++){
  float xc=-0.40 , yc=1.40, zc=2.45, radius=0.15;

  (object[id].vertex+286+i)->y=xc+radius*sin(i*PI/4+PI/8); 
  (object[id].vertex+286+i)->z=yc+radius*cos(i*PI/4+PI/8);
  (object[id].vertex+286+i)->x=zc;
 }
 
              /* 7   */  
 for (i=0; i<8; i++){
  float xc=-0.60 , yc=1.53, zc=-2.0574, radius=0.07;   

  (object[id].vertex+294+i)->y=xc+radius*sin(i*PI/4+PI/8); 
  (object[id].vertex+294+i)->z=yc+radius*cos(i*PI/4+PI/8);
  (object[id].vertex+294+i)->x=zc;
 }

    /* 7  */
 for (i=0; i<8; i++){
  float xc=-0.40 , yc=1.40, zc=-2.45, radius=0.15;

  (object[id].vertex+302+i)->y=xc+radius*sin(i*PI/4+PI/8); 
  (object[id].vertex+302+i)->z=yc+radius*cos(i*PI/4+PI/8);
  (object[id].vertex+302+i)->x=zc;
 }

               /*8   */
 for (i=0; i<8; i++){                      
  float xc=0.60 , yc=1.53, zc=-2.0574, radius=0.07; 

  (object[id].vertex+310+i)->y=xc+radius*sin(i*PI/4+PI/8); 
  (object[id].vertex+310+i)->z=yc+radius*cos(i*PI/4+PI/8);
  (object[id].vertex+310+i)->x=zc;
 }

    /* 8  */
 for (i=0; i<8; i++){
  float xc=0.40 , yc=1.40, zc=-2.45, radius=0.15;

  (object[id].vertex+318+i)->y=xc+radius*sin(i*PI/4+PI/8); 
  (object[id].vertex+318+i)->z=yc+radius*cos(i*PI/4+PI/8);
  (object[id].vertex+318+i)->x=zc;
 }
 
         /* 1' 1 */ 
 for (i=0; i<8; i++){               
  float xc=1.40, yc=0.40, zc=-2.45, radius=0.15;

  (object[id].vertex+326+i)->z=xc+radius*sin(i*PI/4+PI/8); 
  (object[id].vertex+326+i)->x=yc+radius*cos(i*PI/4+PI/8);
  (object[id].vertex+326+i)->y=zc;
 }

    /* 1' 1*/
 for (i=0; i<8; i++){
  float xc=1.35 , yc=0.00, zc=-3.00, radius=0.0001;

  (object[id].vertex+334+i)->z=xc+radius*sin(i*PI/4+PI/8); 
  (object[id].vertex+334+i)->x=yc+radius*cos(i*PI/4+PI/8);
  (object[id].vertex+334+i)->y=zc;
 }

         /* 2' 1  */ 
 for (i=0; i<8; i++){
  float xc=1.40, yc=-0.40, zc=-2.45, radius=0.15;  

  (object[id].vertex+342+i)->z=xc+radius*sin(i*PI/4+PI/8); 
  (object[id].vertex+342+i)->x=yc+radius*cos(i*PI/4+PI/8);
  (object[id].vertex+342+i)->y=zc;
 }

    /* 2' 1 */
 for (i=0; i<8; i++){
  float xc=1.35, yc=-0.00, zc=-3.00, radius=0.0001;

  (object[id].vertex+350+i)->z=xc+radius*sin(i*PI/4+PI/8); 
  (object[id].vertex+350+i)->x=yc+radius*cos(i*PI/4+PI/8);
  (object[id].vertex+350+i)->y=zc;
 }
 
            /* 3'2  */
 for (i=0; i<8; i++){
  float xc=1.40, yc=0.40, zc=2.45, radius=0.15;   

  (object[id].vertex+358+i)->z=xc+radius*sin(i*PI/4+PI/8); 
  (object[id].vertex+358+i)->x=yc+radius*cos(i*PI/4+PI/8);
  (object[id].vertex+358+i)->y=zc;
 }

    /* 3'2 */
 for (i=0; i<8; i++){
  float xc=1.35, yc=0.00, zc=3.00, radius=0.0001;

  (object[id].vertex+366+i)->z=xc+radius*sin(i*PI/4+PI/8); 
  (object[id].vertex+366+i)->x=yc+radius*cos(i*PI/4+PI/8);
  (object[id].vertex+366+i)->y=zc;
 }
 
           /* 4' 2  */
 for (i=0; i<8; i++){
  float xc=1.40, yc=-0.40, zc=2.45, radius=0.15; 

  (object[id].vertex+374+i)->z=xc+radius*sin(i*PI/4+PI/8); 
  (object[id].vertex+374+i)->x=yc+radius*cos(i*PI/4+PI/8);
  (object[id].vertex+374+i)->y=zc;
 }

    /* 4' 2 */
 for (i=0; i<8; i++){
  float xc=1.35, yc=0.00, zc=3.00, radius=0.0001; 

  (object[id].vertex+382+i)->z=xc+radius*sin(i*PI/4+PI/8); 
  (object[id].vertex+382+i)->x=yc+radius*cos(i*PI/4+PI/8);
  (object[id].vertex+382+i)->y=zc;
 }

             /* 5' 3  */     
 for (i=0; i<8; i++){
  float xc=0.40, yc=1.40, zc=2.45, radius=0.15;

  (object[id].vertex+390+i)->y=xc+radius*sin(i*PI/4+PI/8); 
  (object[id].vertex+390+i)->z=yc+radius*cos(i*PI/4+PI/8);
  (object[id].vertex+390+i)->x=zc;
 }

    /* 5' 3 */   
 for (i=0; i<8; i++){
  float xc=0.00, yc=1.35, zc=3.00, radius=0.0001; 

  (object[id].vertex+398+i)->y=xc+radius*sin(i*PI/4+PI/8); 
  (object[id].vertex+398+i)->z=yc+radius*cos(i*PI/4+PI/8);
  (object[id].vertex+398+i)->x=zc;
 }
 
             /* 6' 3  */   
 for (i=0; i<8; i++){  
  float xc=-0.40, yc=1.40, zc=2.45, radius=0.15; 

  (object[id].vertex+406+i)->y=xc+radius*sin(i*PI/4+PI/8); 
  (object[id].vertex+406+i)->z=yc+radius*cos(i*PI/4+PI/8);
  (object[id].vertex+406+i)->x=zc;
 }

    /* 6' 3 */
 for (i=0; i<8; i++){
  float xc=-0.00, yc=1.35, zc=3.00, radius=0.0001;

  (object[id].vertex+414+i)->y=xc+radius*sin(i*PI/4+PI/8); 
  (object[id].vertex+414+i)->z=yc+radius*cos(i*PI/4+PI/8);
  (object[id].vertex+414+i)->x=zc;
 }

  
       /* 7' 4  */  
 for (i=0; i<8; i++){   
  float xc=-0.40, yc=1.40, zc=-2.45, radius=0.15;   

  (object[id].vertex+422+i)->y=xc+radius*sin(i*PI/4+PI/8); 
  (object[id].vertex+422+i)->z=yc+radius*cos(i*PI/4+PI/8);
  (object[id].vertex+422+i)->x=zc;
 }

    /* 7' 4 */
 for (i=0; i<8; i++){
  float xc=-0.00, yc=1.35, zc=-3.00, radius=0.0001;

  (object[id].vertex+430+i)->y=xc+radius*sin(i*PI/4+PI/8); 
  (object[id].vertex+430+i)->z=yc+radius*cos(i*PI/4+PI/8);
  (object[id].vertex+430+i)->x=zc;
 }

       /* 8' 4  */
 for (i=0; i<8; i++){                
  float xc=0.40, yc=1.40, zc=-2.45, radius=0.15;

  (object[id].vertex+438+i)->y=xc+radius*sin(i*PI/4+PI/8); 
  (object[id].vertex+438+i)->z=yc+radius*cos(i*PI/4+PI/8);
  (object[id].vertex+438+i)->x=zc;
 }

    /* 8' 4 */
 for (i=0; i<8; i++){
  float xc=0.00, yc=1.35, zc=-3.00, radius=0.0001;

  (object[id].vertex+446+i)->y=xc+radius*sin(i*PI/4+PI/8); 
  (object[id].vertex+446+i)->z=yc+radius*cos(i*PI/4+PI/8);
  (object[id].vertex+446+i)->x=zc;
 }

  /* Cilinder */   
 for (i=0; i<8; i++){
  float xc=0.00 , yc= 0.00, zc=1.60, radius=0.60;

  (object[id].vertex+454+i)->x=xc+radius*sin(i*PI/4+PI/8);
  (object[id].vertex+454+i)->y=yc+radius*cos(i*PI/4+PI/8);
  (object[id].vertex+454+i)->z=zc;
 }

    /* Cilinder */
 for (i=0; i<8; i++){
  float xc=0.00 , yc= 0.00, zc=1.20, radius=0.60;

  (object[id].vertex+462+i)->x=xc+radius*sin(i*PI/4+PI/8);
  (object[id].vertex+462+i)->y=yc+radius*cos(i*PI/4+PI/8);
  (object[id].vertex+462+i)->z=zc;
 }
  
      /* Outrigger L 1 */               
 for (i=0; i<8; i++){
  float xc=0.10 , yc=1.20, zc=-2.90, radius_x=0.06,radius_y=0.10; 

  (object[id].vertex+470+i)->y=xc+radius_x*sin(i*PI/4+PI/8);
  (object[id].vertex+470+i)->z=yc+radius_y*cos(i*PI/4+PI/8);
  (object[id].vertex+470+i)->x=zc;
 }

    /* Outrigger L 1 */   
 for (i=0; i<8; i++){
  float xc=0.615, yc= 0.035, zc=-2.0574, radius_x=0.06,radius_y=0.10;

  (object[id].vertex+478+i)->y=xc+radius_x*sin(i*PI/4+PI/8);
  (object[id].vertex+478+i)->z=yc+radius_y*cos(i*PI/4+PI/8);
  (object[id].vertex+478+i)->x=zc;
 }
  
       /*Outrigger R 1 */ 
 for (i=0; i<8; i++){
  float xc=-0.10 , yc=1.20, zc=-2.90, radius_x=0.06,radius_y=0.10;  

  (object[id].vertex+486+i)->y=xc+radius_x*sin(i*PI/4+PI/8);
  (object[id].vertex+486+i)->z=yc+radius_y*cos(i*PI/4+PI/8);  
  (object[id].vertex+486+i)->x=zc;
 }

    /* Outrigger R 1 */   
 for (i=0; i<8; i++){
  float xc=-0.615, yc=0.035, zc=-2.0574, radius_x=0.06,radius_y=0.10;

  (object[id].vertex+494+i)->y=xc+radius_x*sin(i*PI/4+PI/8);
  (object[id].vertex+494+i)->z=yc+radius_y*cos(i*PI/4+PI/8);   
  (object[id].vertex+494+i)->x=zc;
 }

      /* Outrigger R 2 */  
 for (i=0; i<8; i++){
  float xc=0.10 , yc= 1.20, zc=2.90, radius_x=0.06,radius_y=0.10;

  (object[id].vertex+502+i)->x=xc+radius_x*sin(i*PI/4+PI/8);
  (object[id].vertex+502+i)->z=yc+radius_y*cos(i*PI/4+PI/8);  
  (object[id].vertex+502+i)->y=zc;
 }

    /* Outrigger R 2 */
 for (i=0; i<8; i++){
  float xc=0.615 , yc= 0.035, zc=2.0574, radius_x=0.06,radius_y=0.10;

  (object[id].vertex+510+i)->x=xc+radius_x*sin(i*PI/4+PI/8);
  (object[id].vertex+510+i)->z=yc+radius_y*cos(i*PI/4+PI/8);   
  (object[id].vertex+510+i)->y=zc;
 }
   
      /* Outrigger L 2 */
 for (i=0; i<8; i++){
  float xc=-0.10 , yc= 1.20, zc=2.90, radius_x=0.06,radius_y=0.10;

  (object[id].vertex+518+i)->x=xc+radius_x*sin(i*PI/4+PI/8);
  (object[id].vertex+518+i)->z=yc+radius_y*cos(i*PI/4+PI/8);  
  (object[id].vertex+518+i)->y=zc;                              
 }

    /* Outrigger L 2 */  
 for (i=0; i<8; i++){
  float xc=-0.615 , yc=0.035, zc=2.0574, radius_x=0.06,radius_y=0.10;

  (object[id].vertex+526+i)->x=xc+radius_x*sin(i*PI/4+PI/8);
  (object[id].vertex+526+i)->z=yc+radius_y*cos(i*PI/4+PI/8);
  (object[id].vertex+526+i)->y=zc;                                                       
 }                                  

      /* OutriggerR 3 */   
 for (i=0; i<8; i++){
  float xc=-0.10 , yc=1.20, zc=-2.90, radius_x=0.06,radius_y=0.10;

  (object[id].vertex+534+i)->x=xc+radius_x*sin(i*PI/4+PI/8);
  (object[id].vertex+534+i)->z=yc+radius_y*cos(i*PI/4+PI/8);
  (object[id].vertex+534+i)->y=zc;                           
 }

    /*Outrigger R 3 */    
 for (i=0; i<8; i++){
  float xc=-0.615 , yc=0.035, zc=-2.0574, radius_x=0.06,radius_y=0.10;

  (object[id].vertex+542+i)->x=xc+radius_x*sin(i*PI/4+PI/8);
  (object[id].vertex+542+i)->z=yc+radius_y*cos(i*PI/4+PI/8); 
  (object[id].vertex+542+i)->y=zc;
 }

       /*Outrigger L 3 */  
 for (i=0; i<8; i++){
  float xc=0.10 , yc=1.20, zc=-2.90, radius_x=0.06,radius_y=0.10;
                                                                
  (object[id].vertex+550+i)->x=xc+radius_x*sin(i*PI/4+PI/8);
  (object[id].vertex+550+i)->z=yc+radius_y*cos(i*PI/4+PI/8);        
  (object[id].vertex+550+i)->y=zc;
 }

    /*Outrigger L 3 */   
 for (i=0; i<8; i++){
  float xc=0.615 , yc=0.035, zc=-2.0574, radius_x=0.06,radius_y=0.10;
                                                                   
  (object[id].vertex+558+i)->x=xc+radius_x*sin(i*PI/4+PI/8);
  (object[id].vertex+558+i)->z=yc+radius_y*cos(i*PI/4+PI/8);      
  (object[id].vertex+558+i)->y=zc;
 }
 
        /* OutriggerL 4 */   
 for (i=0; i<8; i++){
  float xc=0.10 , yc= 1.20, zc=2.90, radius_x=0.06,radius_y=0.10;

  (object[id].vertex+566+i)->y=xc+radius_x*sin(i*PI/4+PI/8);
  (object[id].vertex+566+i)->z=yc+radius_y*cos(i*PI/4+PI/8);           
  (object[id].vertex+566+i)->x=zc;
 }

    /* OutriggerL 4 */     
 for (i=0; i<8; i++){
  float xc=0.615, yc= 0.035, zc=2.0574, radius_x=0.06,radius_y=0.10; 

  (object[id].vertex+574+i)->y=xc+radius_x*sin(i*PI/4+PI/8);
  (object[id].vertex+574+i)->z=yc+radius_y*cos(i*PI/4+PI/8);             
  (object[id].vertex+574+i)->x=zc;
 }
  
        /* OutriggerR 4 */  
 for (i=0; i<8; i++){
  float xc=-0.10 , yc= 1.20, zc=2.90, radius_x=0.06,radius_y=0.10;   

  (object[id].vertex+582+i)->y=xc+radius_x*sin(i*PI/4+PI/8);
  (object[id].vertex+582+i)->z=yc+radius_y*cos(i*PI/4+PI/8);            
  (object[id].vertex+582+i)->x=zc;
 }

    /* OutriggerR 4 */  
 for (i=0; i<8; i++){
  float xc=-0.615, yc= 0.035, zc=2.0574, radius_x=0.06,radius_y=0.10; 

  (object[id].vertex+590+i)->y=xc+radius_x*sin(i*PI/4+PI/8);
  (object[id].vertex+590+i)->z=yc+radius_y*cos(i*PI/4+PI/8);         
  (object[id].vertex+590+i)->x=zc;
 }

  /* S 1 1 */  
 for (i=0; i<8; i++){              
  float xc=0.28 , yc=-0.67, zc=-2.15, radius=0.02; 

  (object[id].vertex+598+i)->z=xc+radius*sin(i*PI/4+PI/8); 
  (object[id].vertex+598+i)->x=yc+radius*cos(i*PI/4+PI/8);
  (object[id].vertex+598+i)->y=zc;
 }

    /* S 1 1 */ 
 for (i=0; i<8; i++){
  float xc=-0.04, yc=-0.84, zc=-2.60, radius=0.02; 

  (object[id].vertex+606+i)->z=xc+radius*sin(i*PI/4+PI/8); 
  (object[id].vertex+606+i)->x=yc+radius*cos(i*PI/4+PI/8);
  (object[id].vertex+606+i)->y=zc;
 }

   /* S 2 1 */  
 for (i=0; i<8; i++){              
  float xc=0.28 , yc=0.67, zc=-2.15, radius=0.02;

  (object[id].vertex+614+i)->z=xc+radius*sin(i*PI/4+PI/8); 
  (object[id].vertex+614+i)->x=yc+radius*cos(i*PI/4+PI/8);
  (object[id].vertex+614+i)->y=zc;
 }

    /* S 2  1 */  
 for (i=0; i<8; i++){
  float xc=-0.04 , yc=0.84, zc=-2.60, radius=0.02;

  (object[id].vertex+622+i)->z=xc+radius*sin(i*PI/4+PI/8); 
  (object[id].vertex+622+i)->x=yc+radius*cos(i*PI/4+PI/8);
  (object[id].vertex+622+i)->y=zc;
 }

   /* SL 1 2 */ 
 for (i=0; i<8; i++){              
  float xc=0.28 , yc=-0.67, zc=2.15, radius=0.02;

  (object[id].vertex+630+i)->z=xc+radius*sin(i*PI/4+PI/8); 
  (object[id].vertex+630+i)->x=yc+radius*cos(i*PI/4+PI/8);
  (object[id].vertex+630+i)->y=zc;
 }

    /* SL 1 2 */  
 for (i=0; i<8; i++){
  float xc=-0.04 , yc=-0.84, zc=2.60, radius=0.02; 

  (object[id].vertex+638+i)->z=xc+radius*sin(i*PI/4+PI/8); 
  (object[id].vertex+638+i)->x=yc+radius*cos(i*PI/4+PI/8);
  (object[id].vertex+638+i)->y=zc;
 }

    /* SR 2 2 */  
 for (i=0; i<8; i++){              
  float xc=0.28 , yc=0.67, zc=2.15, radius=0.02;

  (object[id].vertex+646+i)->z=xc+radius*sin(i*PI/4+PI/8); 
  (object[id].vertex+646+i)->x=yc+radius*cos(i*PI/4+PI/8);
  (object[id].vertex+646+i)->y=zc;
 }

    /* SR 2 2 */  
 for (i=0; i<8; i++){
  float xc=-0.04 , yc=0.84, zc=2.60, radius=0.02; 

  (object[id].vertex+654+i)->z=xc+radius*sin(i*PI/4+PI/8); 
  (object[id].vertex+654+i)->x=yc+radius*cos(i*PI/4+PI/8);
  (object[id].vertex+654+i)->y=zc;
 }

  
    /* SR 1 3 */  
 for (i=0; i<8; i++){              
  float xc=0.84, yc=-0.04, zc=2.60, radius=0.02;

  (object[id].vertex+662+i)->y=xc+radius*sin(i*PI/4+PI/8); 
  (object[id].vertex+662+i)->z=yc+radius*cos(i*PI/4+PI/8);
  (object[id].vertex+662+i)->x=zc;
 }

    /* SR 1 3 */  
 for (i=0; i<8; i++){
  float xc=0.67 , yc=0.28, zc=2.15, radius=0.02; 

  (object[id].vertex+670+i)->y=xc+radius*sin(i*PI/4+PI/8); 
  (object[id].vertex+670+i)->z=yc+radius*cos(i*PI/4+PI/8);
  (object[id].vertex+670+i)->x=zc;
 }

     /* SL 2 3 */  
 for (i=0; i<8; i++){              
  float xc=-0.84 , yc=-0.04, zc=2.60, radius=0.02;

  (object[id].vertex+678+i)->y=xc+radius*sin(i*PI/4+PI/8); 
  (object[id].vertex+678+i)->z=yc+radius*cos(i*PI/4+PI/8);
  (object[id].vertex+678+i)->x=zc;
 }

    /* SL 2 3 */  
 for (i=0; i<8; i++){
  float xc=-0.67 , yc=0.28, zc=2.15, radius=0.02; 

  (object[id].vertex+686+i)->y=xc+radius*sin(i*PI/4+PI/8); 
  (object[id].vertex+686+i)->z=yc+radius*cos(i*PI/4+PI/8);
  (object[id].vertex+686+i)->x=zc;
 }

      /* S 1 4 */  
 for (i=0; i<8; i++){              
  float xc=-0.84 , yc=-0.04, zc=-2.60, radius=0.02;

  (object[id].vertex+694+i)->y=xc+radius*sin(i*PI/4+PI/8); 
  (object[id].vertex+694+i)->z=yc+radius*cos(i*PI/4+PI/8);
  (object[id].vertex+694+i)->x=zc;
 }

    /* SL 1 4 */  
 for (i=0; i<8; i++){
  float xc=-0.67 , yc=0.28, zc=-2.15, radius=0.02; 

  (object[id].vertex+702+i)->y=xc+radius*sin(i*PI/4+PI/8); 
  (object[id].vertex+702+i)->z=yc+radius*cos(i*PI/4+PI/8);
  (object[id].vertex+702+i)->x=zc;
 }

       /* SR 2 4 */  
 for (i=0; i<8; i++){              
  float xc=0.84, yc=-0.04, zc=-2.60, radius=0.02;

  (object[id].vertex+710+i)->y=xc+radius*sin(i*PI/4+PI/8); 
  (object[id].vertex+710+i)->z=yc+radius*cos(i*PI/4+PI/8);
  (object[id].vertex+710+i)->x=zc;
 }

    /* SR 2 4 */  
 for (i=0; i<8; i++){
  float xc=0.67 , yc=0.28, zc=-2.15, radius=0.02; 

  (object[id].vertex+718+i)->y=xc+radius*sin(i*PI/4+PI/8); 
  (object[id].vertex+718+i)->z=yc+radius*cos(i*PI/4+PI/8);
  (object[id].vertex+718+i)->x=zc;
 }
      /* Cone 1 1 */
 (object[id].vertex+726)->y= 0.0;
 (object[id].vertex+726)->z= 1.35;
 (object[id].vertex+726)->x=-3.00; 

    /* Cone 2 1 */
 (object[id].vertex+727)->y= 0.0;
 (object[id].vertex+727)->z= 1.35; 
 (object[id].vertex+727)->x=-3.00;  

   /* Cone R1 2 */
 (object[id].vertex+728)->x= 0.0;     
 (object[id].vertex+728)->y= 3.00; 
 (object[id].vertex+728)->z=1.35;  
 
  /* Cone L2 2 */
 (object[id].vertex+729)->x= 0.0;   
 (object[id].vertex+729)->y= 3.00;  
 (object[id].vertex+729)->z=1.35;  
  
  /* Cone R1 3 */
 (object[id].vertex+730)->x= 0.0; 
 (object[id].vertex+730)->z=1.35;
 (object[id].vertex+730)->y=-3.00;    
  
   /* Cone L1 3 */
 (object[id].vertex+731)->x= 0.0;
 (object[id].vertex+731)->z= 1.35;
 (object[id].vertex+731)->y= -3.00; 
   
  /* Cone L1 4 */
 (object[id].vertex+732)->z= 1.35;
 (object[id].vertex+732)->x= 3.00;
 (object[id].vertex+732)->y= 0.0; 

   /* Cone R1 4 */
 (object[id].vertex+733)->z= 1.35; 
 (object[id].vertex+733)->x= 3.00; 
 (object[id].vertex+733)->y= 0.0; 

   /* Cone Gear 1  */ 
 (object[id].vertex+734)->x= -3.00;
 (object[id].vertex+734)->z= 1.35; 
 (object[id].vertex+734)->y= 0.0; 

   /* Cone Gear 2  */
 (object[id].vertex+735)->x= 0.0; 
 (object[id].vertex+735)->z= 1.35; 
 (object[id].vertex+735)->y= 3.00; 
 
   /* Cone Gear 3  */
 (object[id].vertex+736)->x= 0.0; 
 (object[id].vertex+736)->z= 1.35; 
 (object[id].vertex+736)->y= -3.00; 

   /* Cone Gear 4  */
 (object[id].vertex+737)->x= 3.00; 
 (object[id].vertex+737)->z= 1.35; 
 (object[id].vertex+737)->y= 0.0; 

   /* Cone Outrigger 1 1  */ 
 (object[id].vertex+738)->x= -0.64;
 (object[id].vertex+738)->z= 0.34; 
 (object[id].vertex+738)->y= -2.0574;
 
  /* Cone Outrigger Back 1 1  */
 (object[id].vertex+739)->y= -2.69;
 (object[id].vertex+739)->z= -0.11; 
 (object[id].vertex+739)->x= -0.87; 

  /* Cone Outrigger 2 1  */
 (object[id].vertex+740)->x= 0.64;
 (object[id].vertex+740)->z= 0.34; 
 (object[id].vertex+740)->y= -2.0574; 

  /* Cone Outrigger Back 2 1  */
 (object[id].vertex+741)->x= 0.87;
 (object[id].vertex+741)->z= -0.11; 
 (object[id].vertex+741)->y= -2.69; 

  /* Cone Outrigger  1 2  */  
 (object[id].vertex+742)->x= -0.64;
 (object[id].vertex+742)->z= 0.34; 
 (object[id].vertex+742)->y= 2.0574; 

  /* Cone Outrigger Back  1 2  */  
 (object[id].vertex+743)->x= -0.87;
 (object[id].vertex+743)->z= -0.11; 
 (object[id].vertex+743)->y= 2.69; 

  /* Cone Outrigger   2 2  */ 
 (object[id].vertex+744)->x= 0.64;
 (object[id].vertex+744)->z= 0.34; 
 (object[id].vertex+744)->y= 2.0574; 
  
  /* Cone Outrigger Back   2 2  */  
 (object[id].vertex+745)->x= 0.87;
 (object[id].vertex+745)->z= -0.11; 
 (object[id].vertex+745)->y= 2.69; 
 
 /* Cone Outrigger    L1 3  */  
 (object[id].vertex+746)->y= 0.64;
 (object[id].vertex+746)->z= 0.34; 
 (object[id].vertex+746)->x= 2.0574; 
 
 /* Cone Outrigger Back  L2 3  */  
 (object[id].vertex+747)->y= 0.87;
 (object[id].vertex+747)->z= -0.11; 
 (object[id].vertex+747)->x= 2.69; 

  /* Cone Outrigger  R1 3  */  
 (object[id].vertex+748)->y= -0.64;
 (object[id].vertex+748)->z= 0.34; 
 (object[id].vertex+748)->x= 2.0574; 

  /* Cone Outrigger Back R1 3  */  
 (object[id].vertex+749)->y= -0.87;
 (object[id].vertex+749)->z= -0.11; 
 (object[id].vertex+749)->x= 2.69; 

   /* Cone Outrigger  L1 4  */  
 (object[id].vertex+750)->y= -0.64;
 (object[id].vertex+750)->z= 0.34; 
 (object[id].vertex+750)->x= -2.0574; 

  /* Cone Outrigger Back L1 4  */  
 (object[id].vertex+751)->y= -0.87;
 (object[id].vertex+751)->z= -0.11; 
 (object[id].vertex+751)->x= -2.69; 
 
   /* Cone Outrigger R1 4  */  
 (object[id].vertex+752)->y= 0.64;
 (object[id].vertex+752)->z= 0.34; 
 (object[id].vertex+752)->x= -2.0574; 

  /* Cone Outrigger Back R1 4  */  
 (object[id].vertex+753)->y= 0.87;
 (object[id].vertex+753)->z= -0.11; 
 (object[id].vertex+753)->x= -2.69; 

 
   /* S UNDER 1 1 */ 
 for (i=0; i<8; i++){              
  float xc=-0.08 , yc=-0.68, zc=-2.15, radius=0.03;

  (object[id].vertex+754+i)->z=xc+radius*sin(i*PI/4+PI/8); 
  (object[id].vertex+754+i)->x=yc+radius*cos(i*PI/4+PI/8);  
  (object[id].vertex+754+i)->y=zc;
 }

    /* S 1 1 */ 
 for (i=0; i<8; i++){
  float xc=-0.12 , yc=-0.85, zc=-2.65, radius=0.03; 

  (object[id].vertex+762+i)->z=xc+radius*sin(i*PI/4+PI/8); 
  (object[id].vertex+762+i)->x=yc+radius*cos(i*PI/4+PI/8);
  (object[id].vertex+762+i)->y=zc;
 }


    /* S UNDER L 2 1 */  
 for (i=0; i<8; i++){              
  float xc=-0.08 , yc=0.68, zc=-2.15, radius=0.03;

  (object[id].vertex+770+i)->z=xc+radius*sin(i*PI/4+PI/8); 
  (object[id].vertex+770+i)->x=yc+radius*cos(i*PI/4+PI/8);
  (object[id].vertex+770+i)->y=zc;
 }

    /* S L UNDER 2 1 */  
 for (i=0; i<8; i++){
  float xc=-0.12 , yc=0.85, zc=-2.65, radius=0.03; 

  (object[id].vertex+778+i)->z=xc+radius*sin(i*PI/4+PI/8); 
  (object[id].vertex+778+i)->x=yc+radius*cos(i*PI/4+PI/8);
  (object[id].vertex+778+i)->y=zc;
 }
 
   /* SL UNDER L1 2 */ 
 for (i=0; i<8; i++){              
  float xc=-0.08 , yc=-0.68, zc=2.15, radius=0.03;

  (object[id].vertex+786+i)->z=xc+radius*sin(i*PI/4+PI/8); 
  (object[id].vertex+786+i)->x=yc+radius*cos(i*PI/4+PI/8);
  (object[id].vertex+786+i)->y=zc;                                  
 }

    /* S UNDER L1 2 */  
 for (i=0; i<8; i++){
  float xc=-0.12 , yc=-0.85, zc=2.65, radius=0.03; 

  (object[id].vertex+794+i)->z=xc+radius*sin(i*PI/4+PI/8); 
  (object[id].vertex+794+i)->x=yc+radius*cos(i*PI/4+PI/8);
  (object[id].vertex+794+i)->y=zc;
 }
                                                               
     /* S UNDER R2 2 */  
 for (i=0; i<8; i++){              
  float xc=-0.08 , yc=0.68, zc=2.15, radius=0.03;

  (object[id].vertex+802+i)->z=xc+radius*sin(i*PI/4+PI/8); 
  (object[id].vertex+802+i)->x=yc+radius*cos(i*PI/4+PI/8);
  (object[id].vertex+802+i)->y=zc;
 }

    /* S UNDER R2 2 */                                       
 for (i=0; i<8; i++){
  float xc=-0.12 , yc=0.85, zc=2.65, radius=0.03; 

  (object[id].vertex+810+i)->z=xc+radius*sin(i*PI/4+PI/8); 
  (object[id].vertex+810+i)->x=yc+radius*cos(i*PI/4+PI/8);
  (object[id].vertex+810+i)->y=zc;
 }

    /* SR 1 3 */     
 for (i=0; i<8; i++){              
  float xc=0.85 , yc=-0.12, zc=2.65, radius=0.03;

  (object[id].vertex+818+i)->y=xc+radius*sin(i*PI/4+PI/8); 
  (object[id].vertex+818+i)->z=yc+radius*cos(i*PI/4+PI/8);
  (object[id].vertex+818+i)->x=zc;                           
 }

    /* SR 1 3 */  
 for (i=0; i<8; i++){
  float xc=0.68 , yc=-0.08, zc=2.15, radius=0.03; 

  (object[id].vertex+826+i)->y=xc+radius*sin(i*PI/4+PI/8); 
  (object[id].vertex+826+i)->z=yc+radius*cos(i*PI/4+PI/8);
  (object[id].vertex+826+i)->x=zc;
 }

      /* SL UNDER 2 3 */                    
 for (i=0; i<8; i++){              
  float xc=-0.85 , yc=-0.12, zc=2.65, radius=0.03;

  (object[id].vertex+834+i)->y=xc+radius*sin(i*PI/4+PI/8); 
  (object[id].vertex+834+i)->z=yc+radius*cos(i*PI/4+PI/8);
  (object[id].vertex+834+i)->x=zc;
 }                                                              

    /* SL UNDER 2 3 */  
 for (i=0; i<8; i++){
  float xc=-0.68 , yc=-0.08, zc=2.15, radius=0.03; 

  (object[id].vertex+842+i)->y=xc+radius*sin(i*PI/4+PI/8); 
  (object[id].vertex+842+i)->z=yc+radius*cos(i*PI/4+PI/8);
  (object[id].vertex+842+i)->x=zc;
 }
  
  /* S UNDER R1 4 */  
 for (i=0; i<8; i++){              
  float xc=-0.85 , yc=-0.12, zc=-2.65, radius=0.03;

  (object[id].vertex+850+i)->y=xc+radius*sin(i*PI/4+PI/8); 
  (object[id].vertex+850+i)->z=yc+radius*cos(i*PI/4+PI/8);
  (object[id].vertex+850+i)->x=zc;                              
 }

    /* S UNDER R1 4 */  
 for (i=0; i<8; i++){
  float xc=-0.68 , yc=-0.08, zc=-2.15, radius=0.03; 

  (object[id].vertex+858+i)->y=xc+radius*sin(i*PI/4+PI/8); 
  (object[id].vertex+858+i)->z=yc+radius*cos(i*PI/4+PI/8);
  (object[id].vertex+858+i)->x=zc;
 }

         /* S UNDER L2 4 */  
 for (i=0; i<8; i++){              
  float xc=0.85 , yc=-0.12, zc=-2.65, radius=0.03;

  (object[id].vertex+866+i)->y=xc+radius*sin(i*PI/4+PI/8); 
  (object[id].vertex+866+i)->z=yc+radius*cos(i*PI/4+PI/8);         
  (object[id].vertex+866+i)->x=zc;
 }

    /* S UNDER L2 4 */  
 for (i=0; i<8; i++){
  float xc=0.68 , yc=-0.08, zc=-2.15, radius=0.03; 

  (object[id].vertex+874+i)->y=xc+radius*sin(i*PI/4+PI/8); 
  (object[id].vertex+874+i)->z=yc+radius*cos(i*PI/4+PI/8);
  (object[id].vertex+874+i)->x=zc;
 }
  
   /* Cone Gear 1   */  
 (object[id].vertex+882)->x= -4.25628;
 (object[id].vertex+882)->z= -1.2; 
 (object[id].vertex+882)->y= 0.0; 

  /* Cone Gear 2   */  
 (object[id].vertex+883)->x= 0.0;
 (object[id].vertex+883)->z= -1.2; 
 (object[id].vertex+883)->y= 4.25628; 

  /* Cone Gear 3   */  
 (object[id].vertex+884)->x= 0.0;
 (object[id].vertex+884)->z= -1.2; 
 (object[id].vertex+884)->y= -4.25628; 

 /* Cone Gear 4  */  
 (object[id].vertex+885)->x= 4.25628;
 (object[id].vertex+885)->z= -1.2;
 (object[id].vertex+885)->y= -0.0; 

   /* Cone Front Under Outrigger  1 1 */  
 (object[id].vertex+886)->x= -0.64;
 (object[id].vertex+886)->z= -0.07;
 (object[id].vertex+886)->y= -2.0574; 

 /* Cone Front Under Outrigger  2 1 */  
 (object[id].vertex+887)->x= 0.64;
 (object[id].vertex+887)->z= -0.07;
 (object[id].vertex+887)->y= -2.0574; 

 /* Cone Front Under Outrigger  1 2 */  
 (object[id].vertex+888)->x= -0.64;
 (object[id].vertex+888)->z= -0.07;
 (object[id].vertex+888)->y= 2.0574; 

 /* Cone Front Under Outrigger  2 2 */  
 (object[id].vertex+889)->x= 0.64;
 (object[id].vertex+889)->z= -0.07;
 (object[id].vertex+889)->y= 2.0574; 

 /* Cone Front Under Outrigger  1 3 */  
 (object[id].vertex+890)->x= 2.0574;
 (object[id].vertex+890)->z= -0.07;
 (object[id].vertex+890)->y= 0.64; 

  /* Cone Front Under Outrigger  2 3 */  
 (object[id].vertex+891)->x= 2.0574;
 (object[id].vertex+891)->z= -0.07;
 (object[id].vertex+891)->y= -0.64; 

 /* Cone Front Under Outrigger  1 4 */  
 (object[id].vertex+892)->x= -2.0574;
 (object[id].vertex+892)->z= -0.07;
 (object[id].vertex+892)->y= -0.64; 

  /* Cone Front Under Outrigger  2 4 */  
 (object[id].vertex+893)->x= -2.0574;
 (object[id].vertex+893)->z= -0.07;
 (object[id].vertex+893)->y= 0.64; 

   /* Cone Back Under Outrigger  1 1 */  
 (object[id].vertex+894)->x= -0.90;
 (object[id].vertex+894)->z= -0.13;
 (object[id].vertex+894)->y= -2.78; 

 /* Cone Back Under Outrigger  2 1 */  
 (object[id].vertex+895)->x= 0.90;
 (object[id].vertex+895)->z= -0.13;
 (object[id].vertex+895)->y= -2.78; 

  /* Cone Back Under Outrigger  1 2 */  
 (object[id].vertex+896)->x= -0.90;
 (object[id].vertex+896)->z= -0.13;
 (object[id].vertex+896)->y= 2.78; 

  /* Cone Back Under Outrigger  2 2 */  
 (object[id].vertex+897)->x= 0.90;
 (object[id].vertex+897)->z= -0.13;
 (object[id].vertex+897)->y= 2.78; 

  /* Cone Back Under Outrigger  1 3 */  
 (object[id].vertex+898)->x= 2.78;
 (object[id].vertex+898)->z= -0.13;
 (object[id].vertex+898)->y= 0.90; 

 /* Cone Back Under Outrigger  2 3 */  
 (object[id].vertex+899)->x= 2.78;
 (object[id].vertex+899)->z= -0.13;
 (object[id].vertex+899)->y= -0.90; 

   /* Cone Back Under Outrigger  1 4 */  
 (object[id].vertex+900)->x= -2.78;
 (object[id].vertex+900)->z= -0.13;
 (object[id].vertex+900)->y= -0.90; 

   /* Cone Back Under Outrigger  2 4 */  
 (object[id].vertex+901)->x= -2.78;
 (object[id].vertex+901)->z= -0.13;
 (object[id].vertex+901)->y= 0.90; 

      /* A X R 1 */               
 for (i=0; i<8; i++){                  
  float xc=-2.40 , yc=-0.11, zc=0.0, radius_x=0.03,radius_y=0.03;  
            
  (object[id].vertex+902+i)->x=xc+radius_x*sin(i*PI/4+PI/8);
  (object[id].vertex+902+i)->z=yc+radius_y*cos(i*PI/4+PI/8);
  (object[id].vertex+902+i)->y=zc;                              
 }

    /* A X R 1 */    
 for (i=0; i<8; i++){
  float xc=-2.15, yc= -0.08, zc=0.50, radius_x=0.03,radius_y=0.03;
          
  (object[id].vertex+910+i)->x=xc+radius_x*sin(i*PI/4+PI/8);    
  (object[id].vertex+910+i)->z=yc+radius_y*cos(i*PI/4+PI/8);
  (object[id].vertex+910+i)->y=zc;
 }                                    
                                                              
       /* B X L 1 */ 
 for (i=0; i<8; i++){
  float xc= -2.40 , yc=-0.11, zc=0.0, radius_x=0.03,radius_y=0.03;  
          
  (object[id].vertex+918+i)->x=xc+radius_x*sin(i*PI/4+PI/8);
  (object[id].vertex+918+i)->z=yc+radius_y*cos(i*PI/4+PI/8);      
  (object[id].vertex+918+i)->y=zc;
 }

    /* B X L 1 */   
 for (i=0; i<8; i++){
  float xc=-2.15, yc=-0.08, zc=-0.50, radius_x=0.03,radius_y=0.03;
          
  (object[id].vertex+926+i)->x=xc+radius_x*sin(i*PI/4+PI/8);
  (object[id].vertex+926+i)->z=yc+radius_y*cos(i*PI/4+PI/8);   
  (object[id].vertex+926+i)->y=zc;
 }
 
       /* C X R 2 */  
 for (i=0; i<8; i++){
  float xc=2.40 , yc= -0.11, zc=0.0, radius_x=0.03,radius_y=0.03;
         
  (object[id].vertex+934+i)->x=xc+radius_x*sin(i*PI/4+PI/8);  
  (object[id].vertex+934+i)->z=yc+radius_y*cos(i*PI/4+PI/8);  
  (object[id].vertex+934+i)->y=zc;
 }

    /*  C X R 2 */
 for (i=0; i<8; i++){
  float xc=2.15 , yc= -0.08, zc=0.50, radius_x=0.03,radius_y=0.03;
          
  (object[id].vertex+942+i)->x=xc+radius_x*sin(i*PI/4+PI/8);
  (object[id].vertex+942+i)->z=yc+radius_y*cos(i*PI/4+PI/8);   
  (object[id].vertex+942+i)->y=zc;
 }
 
       /* X L 2 */
 for (i=0; i<8; i++){
  float xc=2.40 , yc= -0.11, zc=0.0, radius_x=0.03,radius_y=0.03;
           
  (object[id].vertex+950+i)->x=xc+radius_x*sin(i*PI/4+PI/8);
  (object[id].vertex+950+i)->z=yc+radius_y*cos(i*PI/4+PI/8);  
  (object[id].vertex+950+i)->y=zc;                              
 }

    /* X L 2 */  
 for (i=0; i<8; i++){
  float xc=2.15 , yc=-0.08, zc=-0.50, radius_x=0.03,radius_y=0.03;
           
  (object[id].vertex+958+i)->x=xc+radius_x*sin(i*PI/4+PI/8);    
  (object[id].vertex+958+i)->z=yc+radius_y*cos(i*PI/4+PI/8);
  (object[id].vertex+958+i)->y=zc;                                                       
 }                                  

      /* X R 3 */   
 for (i=0; i<8; i++){
  float xc=-2.40, yc=-0.11, zc=0.0, radius_x=0.03,radius_y=0.03;

  (object[id].vertex+966+i)->y=xc+radius_x*sin(i*PI/4+PI/8);
  (object[id].vertex+966+i)->z=yc+radius_y*cos(i*PI/4+PI/8);   
  (object[id].vertex+966+i)->x=zc;                           
 }

    /*X R 3 */    
 for (i=0; i<8; i++){
  float xc=-2.15 , yc=-0.08, zc=-0.50, radius_x=0.03,radius_y=0.03;

  (object[id].vertex+974+i)->y=xc+radius_x*sin(i*PI/4+PI/8);
  (object[id].vertex+974+i)->z=yc+radius_y*cos(i*PI/4+PI/8); 
  (object[id].vertex+974+i)->x=zc;
 }

        /* X L 3 */  
 for (i=0; i<8; i++){
  float xc=-2.40 , yc=-0.11, zc=0.0, radius_x=0.03,radius_y=0.03;
                                                                
  (object[id].vertex+982+i)->y=xc+radius_x*sin(i*PI/4+PI/8);
  (object[id].vertex+982+i)->z=yc+radius_y*cos(i*PI/4+PI/8);        
  (object[id].vertex+982+i)->x=zc;
 }

    /* X L 3 */   
 for (i=0; i<8; i++){
  float xc=-2.15 , yc=-0.08, zc=0.50, radius_x=0.03,radius_y=0.03;
                                                                   
  (object[id].vertex+990+i)->y=xc+radius_x*sin(i*PI/4+PI/8);  
  (object[id].vertex+990+i)->z=yc+radius_y*cos(i*PI/4+PI/8);      
  (object[id].vertex+990+i)->x=zc;
 }

          /* X L 4 */   
 for (i=0; i<8; i++){
  float xc=2.15 , yc= -0.08, zc=0.50, radius_x=0.03,radius_y=0.03;

  (object[id].vertex+998+i)->y=xc+radius_x*sin(i*PI/4+PI/8);
  (object[id].vertex+998+i)->z=yc+radius_y*cos(i*PI/4+PI/8);           
  (object[id].vertex+998+i)->x=zc;
 }

    /* X L 4 */     
 for (i=0; i<8; i++){
  float xc=2.40, yc= -0.11, zc=0.0, radius_x=0.03,radius_y=0.03;

  (object[id].vertex+1006+i)->y=xc+radius_x*sin(i*PI/4+PI/8);
  (object[id].vertex+1006+i)->z=yc+radius_y*cos(i*PI/4+PI/8);             
  (object[id].vertex+1006+i)->x=zc;
 }  
        /* X R 4 */   
 for (i=0; i<8; i++){
  float xc=2.15 , yc= -0.08, zc=-0.50, radius_x=0.03,radius_y=0.03;   

  (object[id].vertex+1014+i)->y=xc+radius_x*sin(i*PI/4+PI/8);
  (object[id].vertex+1014+i)->z=yc+radius_y*cos(i*PI/4+PI/8);           
  (object[id].vertex+1014+i)->x=zc;
 }

    /* X R 4 */ 
 for (i=0; i<8; i++){
  float xc=2.40, yc= -0.11, zc=0.0, radius_x=0.03,radius_y=0.03;  

  (object[id].vertex+1022+i)->y=xc+radius_x*sin(i*PI/4+PI/8);
  (object[id].vertex+1022+i)->z=yc+radius_y*cos(i*PI/4+PI/8);         
  (object[id].vertex+1022+i)->x=zc;
 }

  /* Cone X  1 1 */  
 (object[id].vertex+1030)->x= -2.0574;
 (object[id].vertex+1030)->z= -0.07;
 (object[id].vertex+1030)->y= 0.64; 

 /* Cone X  2 1 */  
 (object[id].vertex+1031)->x= -2.0574;
 (object[id].vertex+1031)->z= -0.07;
 (object[id].vertex+1031)->y= -0.64; 

  /* Cone X 1 2 */  
 (object[id].vertex+1032)->x= 2.0574; 
 (object[id].vertex+1032)->z= -0.07;
 (object[id].vertex+1032)->y= 0.64; 

     /* Cone X 2 2 */  
 (object[id].vertex+1033)->x= 2.0574; 
 (object[id].vertex+1033)->z= -0.07;
 (object[id].vertex+1033)->y= -0.64; 

     /* Cone X 1 3 */  
 (object[id].vertex+1034)->x=-0.64; 
 (object[id].vertex+1034)->z= -0.07;  
 (object[id].vertex+1034)->y= -2.0574; 

     /* Cone X 2 3 */  
 (object[id].vertex+1035)->x=0.64; 
 (object[id].vertex+1035)->z= -0.07;
 (object[id].vertex+1035)->y= -2.0574; 

    /* Cone X 1 4 */  
 (object[id].vertex+1036)->x=0.64; 
 (object[id].vertex+1036)->z= -0.07;
 (object[id].vertex+1036)->y= 2.0574; 

    /* Cone X 2 4 */  
 (object[id].vertex+1037)->x=-0.64; 
 (object[id].vertex+1037)->z= -0.07;
 (object[id].vertex+1037)->y= 2.0574; 

      /* XX R 1 */          
 for (i=0; i<8; i++){
  float xc=-2.40 , yc=-0.11, zc=0.0, radius_x=0.03,radius_y=0.03;  
                                        
  (object[id].vertex+1038+i)->x=xc+radius_x*sin(i*PI/4+PI/8);
  (object[id].vertex+1038+i)->z=yc+radius_y*cos(i*PI/4+PI/8);
  (object[id].vertex+1038+i)->y=zc;                              
 }

    /* XX R 1 */    
 for (i=0; i<8; i++){
  float xc=-2.74, yc= -0.13, zc=0.80, radius_x=0.03,radius_y=0.03;
                               
  (object[id].vertex+1046+i)->x=xc+radius_x*sin(i*PI/4+PI/8);    
  (object[id].vertex+1046+i)->z=yc+radius_y*cos(i*PI/4+PI/8);
  (object[id].vertex+1046+i)->y=zc;
 }                                    

   /* XX L 1 */              
 for (i=0; i<8; i++){
  float xc=-2.40 , yc=-0.11, zc=0.0, radius_x=0.03,radius_y=0.03;  
                                        
  (object[id].vertex+1054+i)->x=xc+radius_x*sin(i*PI/4+PI/8);
  (object[id].vertex+1054+i)->z=yc+radius_y*cos(i*PI/4+PI/8);
  (object[id].vertex+1054+i)->y=zc;                              
 }

    /* XX L 1 */  
 for (i=0; i<8; i++){
  float xc=-2.74, yc= -0.13, zc=-0.80, radius_x=0.03,radius_y=0.03;
                               
  (object[id].vertex+1062+i)->x=xc+radius_x*sin(i*PI/4+PI/8);    
  (object[id].vertex+1062+i)->z=yc+radius_y*cos(i*PI/4+PI/8);
  (object[id].vertex+1062+i)->y=zc;
 }                                    
   
        /* XX R 2 */  
 for (i=0; i<8; i++){
  float xc=2.40 , yc= -0.11, zc=0.0, radius_x=0.03,radius_y=0.03;
         
  (object[id].vertex+1070+i)->x=xc+radius_x*sin(i*PI/4+PI/8);  
  (object[id].vertex+1070+i)->z=yc+radius_y*cos(i*PI/4+PI/8);  
  (object[id].vertex+1070+i)->y=zc;
 }

    /* XX R 2 */
 for (i=0; i<8; i++){
  float xc=2.74 , yc= -0.13, zc=0.80, radius_x=0.03,radius_y=0.03;
          
  (object[id].vertex+1078+i)->x=xc+radius_x*sin(i*PI/4+PI/8);
  (object[id].vertex+1078+i)->z=yc+radius_y*cos(i*PI/4+PI/8);   
  (object[id].vertex+1078+i)->y=zc;
 }
 
       /* XX L 2 */
 for (i=0; i<8; i++){
  float xc=2.40 , yc= -0.11, zc=0.0, radius_x=0.03,radius_y=0.03;
           
  (object[id].vertex+1086+i)->x=xc+radius_x*sin(i*PI/4+PI/8);
  (object[id].vertex+1086+i)->z=yc+radius_y*cos(i*PI/4+PI/8);  
  (object[id].vertex+1086+i)->y=zc;                              
 }

        /* XX L 2 */  
 for (i=0; i<8; i++){
  float xc=2.74 , yc=-0.13, zc=-0.80, radius_x=0.03,radius_y=0.03;
           
  (object[id].vertex+1094+i)->x=xc+radius_x*sin(i*PI/4+PI/8);    
  (object[id].vertex+1094+i)->z=yc+radius_y*cos(i*PI/4+PI/8);
  (object[id].vertex+1094+i)->y=zc;                                                       
 }                                  

         /* XX R 3 */   
 for (i=0; i<8; i++){
  float xc=-2.40, yc=-0.11, zc=0.0, radius_x=0.03,radius_y=0.03;

  (object[id].vertex+1102+i)->y=xc+radius_x*sin(i*PI/4+PI/8);
  (object[id].vertex+1102+i)->z=yc+radius_y*cos(i*PI/4+PI/8);   
  (object[id].vertex+1102+i)->x=zc;                           
 }

          /* XX R 3 */    
 for (i=0; i<8; i++){
  float xc=-2.74 , yc=-0.13, zc=-0.80, radius_x=0.03,radius_y=0.03;

  (object[id].vertex+1110+i)->y=xc+radius_x*sin(i*PI/4+PI/8);
  (object[id].vertex+1110+i)->z=yc+radius_y*cos(i*PI/4+PI/8); 
  (object[id].vertex+1110+i)->x=zc;
 }

           /* XX L 3 */  
 for (i=0; i<8; i++){
  float xc=-2.40 , yc=-0.11, zc=0.0, radius_x=0.03,radius_y=0.03;
                                                                
  (object[id].vertex+1118+i)->y=xc+radius_x*sin(i*PI/4+PI/8);
  (object[id].vertex+1118+i)->z=yc+radius_y*cos(i*PI/4+PI/8);        
  (object[id].vertex+1118+i)->x=zc;
 }

         /* XX L 3 */   
 for (i=0; i<8; i++){
  float xc=-2.74 , yc=-0.13, zc=0.80, radius_x=0.03,radius_y=0.03;
                                                                   
  (object[id].vertex+1126+i)->y=xc+radius_x*sin(i*PI/4+PI/8);  
  (object[id].vertex+1126+i)->z=yc+radius_y*cos(i*PI/4+PI/8);      
  (object[id].vertex+1126+i)->x=zc;
 }

           /* XX L 4 */   
 for (i=0; i<8; i++){
  float xc=2.74 , yc= -0.13, zc=0.80, radius_x=0.03,radius_y=0.03;

  (object[id].vertex+1134+i)->y=xc+radius_x*sin(i*PI/4+PI/8);
  (object[id].vertex+1134+i)->z=yc+radius_y*cos(i*PI/4+PI/8);           
  (object[id].vertex+1134+i)->x=zc;
 }

         /* XX L 4 */     
 for (i=0; i<8; i++){
  float xc=2.40, yc= -0.11, zc=0.0, radius_x=0.03,radius_y=0.03;

  (object[id].vertex+1142+i)->y=xc+radius_x*sin(i*PI/4+PI/8);
  (object[id].vertex+1142+i)->z=yc+radius_y*cos(i*PI/4+PI/8);             
  (object[id].vertex+1142+i)->x=zc;
 }  
         /* XX R 4 */   
 for (i=0; i<8; i++){
  float xc=2.74, yc= -0.13, zc=-0.80, radius_x=0.03,radius_y=0.03;   

  (object[id].vertex+1150+i)->y=xc+radius_x*sin(i*PI/4+PI/8);
  (object[id].vertex+1150+i)->z=yc+radius_y*cos(i*PI/4+PI/8);           
  (object[id].vertex+1150+i)->x=zc;
 }

        /* XX R 4 */ 
 for (i=0; i<8; i++){
  float xc=2.40, yc= -0.11, zc=0.0, radius_x=0.03,radius_y=0.03;  

  (object[id].vertex+1158+i)->y=xc+radius_x*sin(i*PI/4+PI/8);
  (object[id].vertex+1158+i)->z=yc+radius_y*cos(i*PI/4+PI/8);         
  (object[id].vertex+1158+i)->x=zc;
 }

    /* XX Cone  R 1 */ 
 (object[id].vertex+1166)->x= -2.78;
 (object[id].vertex+1166)->z= -0.13;
 (object[id].vertex+1166)->y= 0.90; 

    /* XX Cone  L 1 */  
 (object[id].vertex+1167)->x= -2.78;
 (object[id].vertex+1167)->z= -0.13;
 (object[id].vertex+1167)->y= -0.90; 

   /* XX Cone  L 2 */  
 (object[id].vertex+1168)->x= 2.78;
 (object[id].vertex+1168)->z= -0.13;
 (object[id].vertex+1168)->y= 0.90; 

   /* XX Cone  R 2 */  
 (object[id].vertex+1169)->x= 2.78;
 (object[id].vertex+1169)->z= -0.13;
 (object[id].vertex+1169)->y= -0.90; 

   /* XX Cone  R 3 */  
 (object[id].vertex+1170)->x= -0.90;
 (object[id].vertex+1170)->z= -0.13;
 (object[id].vertex+1170)->y= -2.78; 

   /* XX Cone L 3 */  
 (object[id].vertex+1171)->x= 0.90;
 (object[id].vertex+1171)->z= -0.13;
 (object[id].vertex+1171)->y= -2.78; 

   /* XX Cone  R 4 */  
 (object[id].vertex+1172)->x= 0.90;
 (object[id].vertex+1172)->z= -0.13;
 (object[id].vertex+1172)->y= 2.78; 

    /* XX Cone L 4 */  
 (object[id].vertex+1173)->x= -0.90;
 (object[id].vertex+1173)->z= -0.13;
 (object[id].vertex+1173)->y= 2.78; 

    /* XXX  R 1 */     
 for (i=0; i<8; i++){              
  float xc=-0.15 , yc=-0.79, zc=-2.95, radius_x=0.05,radius_y=0.05;

  (object[id].vertex+1174+i)->z=xc+radius_x*sin(i*PI/4+PI/8); 
  (object[id].vertex+1174+i)->x=yc+radius_y*cos(i*PI/4+PI/8);  
  (object[id].vertex+1174+i)->y=zc;
 }

    /* XXX R 1 */ 
 for (i=0; i<8; i++){
  float xc=-0.22 , yc=-0.26, zc=-3.50, radius_x=0.05,radius_y=0.05; 

  (object[id].vertex+1182+i)->z=xc+radius_x*sin(i*PI/4+PI/8); 
  (object[id].vertex+1182+i)->x=yc+radius_y*cos(i*PI/4+PI/8);
  (object[id].vertex+1182+i)->y=zc;
 }

     /* XXX L 1 */  
 for (i=0; i<8; i++){              
  float xc=-0.15 , yc=0.79, zc=-2.95, radius_x=0.05,radius_y=0.05;

  (object[id].vertex+1190+i)->z=xc+radius_x*sin(i*PI/4+PI/8); 
  (object[id].vertex+1190+i)->x=yc+radius_y*cos(i*PI/4+PI/8);
  (object[id].vertex+1190+i)->y=zc;
 }

    /* XXX  L 1 */  
 for (i=0; i<8; i++){
  float xc=-0.22 , yc=0.26, zc=-3.50, radius_x=0.05,radius_y=0.05; 

  (object[id].vertex+1198+i)->z=xc+radius_x*sin(i*PI/4+PI/8); 
  (object[id].vertex+1198+i)->x=yc+radius_y*cos(i*PI/4+PI/8);
  (object[id].vertex+1198+i)->y=zc;
 }

    /* XXX  L1 2 */ 
 for (i=0; i<8; i++){              
  float xc=-0.15 , yc=-0.79, zc=2.95, radius_x=0.05,radius_y=0.05;

  (object[id].vertex+1206+i)->z=xc+radius_x*sin(i*PI/4+PI/8); 
  (object[id].vertex+1206+i)->x=yc+radius_y*cos(i*PI/4+PI/8);
  (object[id].vertex+1206+i)->y=zc;                                  
 }

    /* XXX L1 2 */  
 for (i=0; i<8; i++){
  float xc=-0.22 , yc=-0.26, zc=3.50, radius_x=0.05,radius_y=0.05; 

  (object[id].vertex+1214+i)->z=xc+radius_x*sin(i*PI/4+PI/8); 
  (object[id].vertex+1214+i)->x=yc+radius_y*cos(i*PI/4+PI/8);
  (object[id].vertex+1214+i)->y=zc;
 }
                                                               
     /* XXX R 2 */  
 for (i=0; i<8; i++){              
  float xc=-0.15 , yc=0.79, zc=2.95, radius_x=0.05,radius_y=0.05;

  (object[id].vertex+1222+i)->z=xc+radius_x*sin(i*PI/4+PI/8); 
  (object[id].vertex+1222+i)->x=yc+radius_y*cos(i*PI/4+PI/8);
  (object[id].vertex+1222+i)->y=zc;
 }

    /* XXX R 2 */                                       
 for (i=0; i<8; i++){
  float xc=-0.22 , yc=0.26, zc=3.50, radius_x=0.05,radius_y=0.05; 

  (object[id].vertex+1230+i)->z=xc+radius_x*sin(i*PI/4+PI/8); 
  (object[id].vertex+1230+i)->x=yc+radius_y*cos(i*PI/4+PI/8);
  (object[id].vertex+1230+i)->y=zc;
 }

     /* XXX L 3 */     
 for (i=0; i<8; i++){              
  float xc=0.26 , yc=-0.22, zc=3.50, radius_x=0.05,radius_y=0.05;

  (object[id].vertex+1238+i)->y=xc+radius_x*sin(i*PI/4+PI/8); 
  (object[id].vertex+1238+i)->z=yc+radius_y*cos(i*PI/4+PI/8);
  (object[id].vertex+1238+i)->x=zc;                           
 }

    /* XXX L 3 */  
 for (i=0; i<8; i++){
  float xc=0.79 , yc=-0.15, zc=2.95, radius_x=0.05,radius_y=0.05; 

  (object[id].vertex+1246+i)->y=xc+radius_x*sin(i*PI/4+PI/8); 
  (object[id].vertex+1246+i)->z=yc+radius_y*cos(i*PI/4+PI/8);
  (object[id].vertex+1246+i)->x=zc;
 }

      /* XXX R 3 */                    
 for (i=0; i<8; i++){              
  float xc=-0.26 , yc=-0.22, zc=3.50, radius_x=0.05,radius_y=0.05;

  (object[id].vertex+1254+i)->y=xc+radius_x*sin(i*PI/4+PI/8); 
  (object[id].vertex+1254+i)->z=yc+radius_y*cos(i*PI/4+PI/8);
  (object[id].vertex+1254+i)->x=zc;
 }                                                              

      /* XXX R 3 */  
 for (i=0; i<8; i++){
  float xc=-0.79 , yc=-0.15, zc=2.95, radius_x=0.05,radius_y=0.05; 

  (object[id].vertex+1262+i)->y=xc+radius_x*sin(i*PI/4+PI/8); 
  (object[id].vertex+1262+i)->z=yc+radius_y*cos(i*PI/4+PI/8);
  (object[id].vertex+1262+i)->x=zc;
 }
  
    /* XXX L 4 */  
 for (i=0; i<8; i++){              
  float xc=-0.26 , yc=-0.22, zc=-3.50, radius_x=0.05,radius_y=0.05;

  (object[id].vertex+1270+i)->y=xc+radius_x*sin(i*PI/4+PI/8); 
  (object[id].vertex+1270+i)->z=yc+radius_y*cos(i*PI/4+PI/8);
  (object[id].vertex+1270+i)->x=zc;                              
 }

     /* XXX L 4 */  
 for (i=0; i<8; i++){
  float xc=-0.79 , yc=-0.15, zc=-2.95, radius_x=0.05,radius_y=0.05; 

  (object[id].vertex+1278+i)->y=xc+radius_x*sin(i*PI/4+PI/8); 
  (object[id].vertex+1278+i)->z=yc+radius_y*cos(i*PI/4+PI/8);
  (object[id].vertex+1278+i)->x=zc;
 }

         /* XXX R 4 */  
 for (i=0; i<8; i++){              
  float xc=0.26 , yc=-0.22, zc=-3.50, radius_x=0.05,radius_y=0.05; 
  
  (object[id].vertex+1286+i)->y=xc+radius_x*sin(i*PI/4+PI/8); 
  (object[id].vertex+1286+i)->z=yc+radius_y*cos(i*PI/4+PI/8);         
  (object[id].vertex+1286+i)->x=zc;
 }

    /* XXX R 4 */  
 for (i=0; i<8; i++){
  float xc=0.79 , yc=-0.15, zc=-2.95, radius_x=0.05,radius_y=0.05; 

  (object[id].vertex+1294+i)->y=xc+radius_x*sin(i*PI/4+PI/8); 
  (object[id].vertex+1294+i)->z=yc+radius_y*cos(i*PI/4+PI/8);
  (object[id].vertex+1294+i)->x=zc;
 }

   /* XXX Cone R 1 */  
 (object[id].vertex+1302)->x= -0.90;
 (object[id].vertex+1302)->z= -0.13;
 (object[id].vertex+1302)->y= -2.78; 

 
    /* XXX Cone  L 1 */  
 (object[id].vertex+1303)->x= 0.90;
 (object[id].vertex+1303)->z= -0.13;
 (object[id].vertex+1303)->y= -2.78; 

   /* XXX Cone  L 2 */  
 (object[id].vertex+1304)->x= -0.90;
 (object[id].vertex+1304)->z= -0.13;
 (object[id].vertex+1304)->y= 2.78; 

   /* XXX Cone  R 2 */  
 (object[id].vertex+1305)->x= 0.90;
 (object[id].vertex+1305)->z= -0.13;
 (object[id].vertex+1305)->y= 2.78; 

   /* XXX Cone  L 3 */  
 (object[id].vertex+1306)->x= 2.78;
 (object[id].vertex+1306)->z= -0.13;
 (object[id].vertex+1306)->y= 0.90; 

   /* XXX Cone R 3 */  
 (object[id].vertex+1307)->x= 2.78;
 (object[id].vertex+1307)->z= -0.13;
 (object[id].vertex+1307)->y= -0.90; 

   /* XXX Cone  R 4 */  
 (object[id].vertex+1308)->x= -2.78;
 (object[id].vertex+1308)->z= -0.13;
 (object[id].vertex+1308)->y= -0.90; 

    /* XXX Cone L 4 */  
 (object[id].vertex+1309)->x= -2.78;
 (object[id].vertex+1309)->z= -0.13;
 (object[id].vertex+1309)->y= 0.90; 
  
   /* XXX Cone BACK  R 1 */  
 (object[id].vertex+1310)->x= -0.0;
 (object[id].vertex+1310)->z= -0.26;
 (object[id].vertex+1310)->y= -3.76; 

  /* XXX Cone BACK L 1 */  
 (object[id].vertex+1311)->x= 0.0;
 (object[id].vertex+1311)->z= -0.26;
 (object[id].vertex+1311)->y= -3.76;

   /* XXX Cone BACK L 2 */  
 (object[id].vertex+1312)->x= -0.0;
 (object[id].vertex+1312)->z= -0.26;
 (object[id].vertex+1312)->y= 3.76; 

   /* XXX Cone BACK R 2 */  
 (object[id].vertex+1313)->x= 0.0;
 (object[id].vertex+1313)->z= -0.26;
 (object[id].vertex+1313)->y= 3.76; 

   /* XXX Cone BACK L 3 */  
 (object[id].vertex+1314)->x= 3.76;
 (object[id].vertex+1314)->z= -0.26;
 (object[id].vertex+1314)->y= 0.0; 

   /* XXX Cone BACK R 3 */  
 (object[id].vertex+1315)->x= 3.76;
 (object[id].vertex+1315)->z= -0.26;
 (object[id].vertex+1315)->y= -0.0; 

   /* XXX Cone BACK L 4 */  
 (object[id].vertex+1316)->x= -3.76;
 (object[id].vertex+1316)->z= -0.26;
 (object[id].vertex+1316)->y= -0.0; 

    /* XXX Cone BACK R 4 */  
 (object[id].vertex+1317)->x= -3.76;
 (object[id].vertex+1317)->z= -0.26;
 (object[id].vertex+1317)->y= 0.0; 
  
       /* H 9 */          
 for (i=0; i<8; i++){
  float xc=3.945 , yc=-0.29, zc=-0.214, radius_x=0.005,radius_y=0.008;  
                                        
  (object[id].vertex+1318+i)->x=xc+radius_x*sin(i*PI/4+PI/8);
  (object[id].vertex+1318+i)->z=yc+radius_y*cos(i*PI/4+PI/8);
  (object[id].vertex+1318+i)->y=zc;                              
 }

    /* H 9 */    
 for (i=0; i<8; i++){
  float xc=3.945 , yc=-0.29, zc=0.214, radius_x=0.005,radius_y=0.008;
                               
  (object[id].vertex+1326+i)->x=xc+radius_x*sin(i*PI/4+PI/8);    
  (object[id].vertex+1326+i)->z=yc+radius_y*cos(i*PI/4+PI/8);
  (object[id].vertex+1326+i)->y=zc;
 }                                    

         /* H 1 1 */          
 for (i=0; i<8; i++){
  float xc=3.10 , yc=1.20, zc=-0.055, radius_x=0.005,radius_y=0.008;  
                                        
  (object[id].vertex+1334+i)->x=xc+radius_x*sin(i*PI/4+PI/8);
  (object[id].vertex+1334+i)->z=yc+radius_y*cos(i*PI/4+PI/8);
  (object[id].vertex+1334+i)->y=zc;                              
 }

    /* H 1 1 */    
 for (i=0; i<8; i++){
  float xc=3.10, yc=1.20, zc=-0.214, radius_x=0.005,radius_y=0.008;
                               
  (object[id].vertex+1342+i)->x=xc+radius_x*sin(i*PI/4+PI/8);    
  (object[id].vertex+1342+i)->z=yc+radius_y*cos(i*PI/4+PI/8);
  (object[id].vertex+1342+i)->y=zc;
 }                                    
 
            /* H 2 1 */          
 for (i=0; i<8; i++){
  float xc=3.10 , yc=1.20, zc=0.055, radius_x=0.005,radius_y=0.008;  
                                        
  (object[id].vertex+1350+i)->x=xc+radius_x*sin(i*PI/4+PI/8);
  (object[id].vertex+1350+i)->z=yc+radius_y*cos(i*PI/4+PI/8);
  (object[id].vertex+1350+i)->y=zc;                              
 }

          /* H 2 1 */    
 for (i=0; i<8; i++){
  float xc=3.10, yc= 1.20, zc=0.214, radius_x=0.005,radius_y=0.008;
                               
  (object[id].vertex+1358+i)->x=xc+radius_x*sin(i*PI/4+PI/8);    
  (object[id].vertex+1358+i)->z=yc+radius_y*cos(i*PI/4+PI/8);
  (object[id].vertex+1358+i)->y=zc;
 }                                    
  
                 /* H 8  */          
 for (i=0; i<8; i++){
  float xc=3.845 , yc=-0.104, zc=-0.214, radius_x=0.005,radius_y=0.008;  
                                        
  (object[id].vertex+1366+i)->x=xc+radius_x*sin(i*PI/4+PI/8);
  (object[id].vertex+1366+i)->z=yc+radius_y*cos(i*PI/4+PI/8);
  (object[id].vertex+1366+i)->y=zc;                              
 }

         /* H 8  */    
 for (i=0; i<8; i++){
  float xc=3.845, yc= -0.104, zc=0.214, radius_x=0.005,radius_y=0.008;
                               
  (object[id].vertex+1374+i)->x=xc+radius_x*sin(i*PI/4+PI/8);    
  (object[id].vertex+1374+i)->z=yc+radius_y*cos(i*PI/4+PI/8);
  (object[id].vertex+1374+i)->y=zc;
 }                                    

         /* H 2  */          
 for (i=0; i<8; i++){
  float xc=3.26 , yc=1.012, zc=0.214, radius_x=0.005,radius_y=0.008;  
                                        
  (object[id].vertex+1382+i)->x=xc+radius_x*sin(i*PI/4+PI/8);
  (object[id].vertex+1382+i)->z=yc+radius_y*cos(i*PI/4+PI/8);
  (object[id].vertex+1382+i)->y=zc;                              
 }

            /* H 2  */    
 for (i=0; i<8; i++){
  float xc=3.26, yc= 1.012, zc=-0.214, radius_x=0.005,radius_y=0.008;
                               
  (object[id].vertex+1390+i)->x=xc+radius_x*sin(i*PI/4+PI/8);    
  (object[id].vertex+1390+i)->z=yc+radius_y*cos(i*PI/4+PI/8);
  (object[id].vertex+1390+i)->y=zc;
 }                                    
 
         /* H 3 */          
 for (i=0; i<8; i++){
  float xc=3.36 , yc=0.826, zc=-0.214, radius_x=0.005,radius_y=0.008;  
                                        
  (object[id].vertex+1398+i)->x=xc+radius_x*sin(i*PI/4+PI/8);
  (object[id].vertex+1398+i)->z=yc+radius_y*cos(i*PI/4+PI/8);
  (object[id].vertex+1398+i)->y=zc;                              
 }

        /* H 3  */    
 for (i=0; i<8; i++){
  float xc=3.36, yc= 0.826, zc=0.214, radius_x=0.005,radius_y=0.008;
                               
  (object[id].vertex+1406+i)->x=xc+radius_x*sin(i*PI/4+PI/8);    
  (object[id].vertex+1406+i)->z=yc+radius_y*cos(i*PI/4+PI/8);
  (object[id].vertex+1406+i)->y=zc;
 }                                    

           /* H 4 */          
 for (i=0; i<8; i++){
  float xc=3.455 , yc=0.64, zc=-0.214, radius_x=0.005,radius_y=0.008;  
                                       
  (object[id].vertex+1414+i)->x=xc+radius_x*sin(i*PI/4+PI/8);
  (object[id].vertex+1414+i)->z=yc+radius_y*cos(i*PI/4+PI/8);
  (object[id].vertex+1414+i)->y=zc;                              
 }

        /* H 4  */    
 for (i=0; i<8; i++){
  float xc=3.455, yc= 0.64, zc=0.214, radius_x=0.005,radius_y=0.008;
                               
  (object[id].vertex+1422+i)->x=xc+radius_x*sin(i*PI/4+PI/8);    
  (object[id].vertex+1422+i)->z=yc+radius_y*cos(i*PI/4+PI/8);
  (object[id].vertex+1422+i)->y=zc;
 }                                    
  
             /* H 5 */          
 for (i=0; i<8; i++){
  float xc=3.555 , yc=0.454, zc=-0.214, radius_x=0.005,radius_y=0.008;  
                                       
  (object[id].vertex+1430+i)->x=xc+radius_x*sin(i*PI/4+PI/8);
  (object[id].vertex+1430+i)->z=yc+radius_y*cos(i*PI/4+PI/8);
  (object[id].vertex+1430+i)->y=zc;                              
 }

        /* H 5  */    
 for (i=0; i<8; i++){
  float xc=3.555, yc= 0.454, zc=0.214, radius_x=0.005,radius_y=0.008;
                               
  (object[id].vertex+1438+i)->x=xc+radius_x*sin(i*PI/4+PI/8);    
  (object[id].vertex+1438+i)->z=yc+radius_y*cos(i*PI/4+PI/8);
  (object[id].vertex+1438+i)->y=zc;
 }                                    

              /* H 6 */          
 for (i=0; i<8; i++){
  float xc=3.65 , yc=0.268, zc=-0.214, radius_x=0.005,radius_y=0.008;  
                                        
  (object[id].vertex+1446+i)->x=xc+radius_x*sin(i*PI/4+PI/8);
  (object[id].vertex+1446+i)->z=yc+radius_y*cos(i*PI/4+PI/8);
  (object[id].vertex+1446+i)->y=zc;                              
 }

        /* H 6  */    
 for (i=0; i<8; i++){
  float xc=3.65, yc= 0.268, zc=0.214, radius_x=0.005,radius_y=0.008;
                               
  (object[id].vertex+1454+i)->x=xc+radius_x*sin(i*PI/4+PI/8);    
  (object[id].vertex+1454+i)->z=yc+radius_y*cos(i*PI/4+PI/8);
  (object[id].vertex+1454+i)->y=zc;
 }                                    

                /* H 7 */          
 for (i=0; i<8; i++){
  float xc=3.75 , yc=0.082, zc=-0.214, radius_x=0.005,radius_y=0.008;  
                                       
  (object[id].vertex+1462+i)->x=xc+radius_x*sin(i*PI/4+PI/8);
  (object[id].vertex+1462+i)->z=yc+radius_y*cos(i*PI/4+PI/8);
  (object[id].vertex+1462+i)->y=zc;                              
 }

        /* H 7 */    
 for (i=0; i<8; i++){
  float xc=3.75, yc= 0.082, zc=0.214, radius_x=0.005,radius_y=0.008;
                               
  (object[id].vertex+1470+i)->x=xc+radius_x*sin(i*PI/4+PI/8);    
  (object[id].vertex+1470+i)->z=yc+radius_y*cos(i*PI/4+PI/8);
  (object[id].vertex+1470+i)->y=zc;
 }                                    
 
  (object[id].vertex+1478)->x= 3.94; 
  (object[id].vertex+1478)->y= -0.214;
  (object[id].vertex+1478)->z= -0.30;  

  (object[id].vertex+1479)->x= 3.96; 
  (object[id].vertex+1479)->y=-0.214; 
  (object[id].vertex+1479)->z=-0.30; 
 
  (object[id].vertex+1480)->x= 3.27;
  (object[id].vertex+1480)->y= -0.214;
  (object[id].vertex+1480)->z= 0.98;

  (object[id].vertex+1481)->x= 3.29;
  (object[id].vertex+1481)->y= -0.214;            
  (object[id].vertex+1481)->z= 0.98;

  (object[id].vertex+1482)->x= 3.96;
  (object[id].vertex+1482)->y= -0.224;
  (object[id].vertex+1482)->z= -0.30; 

  (object[id].vertex+1483)->x= 3.94; 
  (object[id].vertex+1483)->y= -0.224;
  (object[id].vertex+1483)->z= -0.30;   

  (object[id].vertex+1484)->x=  3.29; 
  (object[id].vertex+1484)->y= -0.224;
  (object[id].vertex+1484)->z= 0.98;  

  (object[id].vertex+1485)->x=  3.27;
  (object[id].vertex+1485)->y= -0.224;   
  (object[id].vertex+1485)->z= 0.98; 
    
  (object[id].vertex+1486)->x= 3.94; 
  (object[id].vertex+1486)->y= 0.214;
  (object[id].vertex+1486)->z= -0.30;  

  (object[id].vertex+1487)->x= 3.96;
  (object[id].vertex+1487)->y= 0.214;   
  (object[id].vertex+1487)->z=-0.30; 
 
  (object[id].vertex+1488)->x= 3.27;
  (object[id].vertex+1488)->y=  0.214;  
  (object[id].vertex+1488)->z= 0.98;  

  (object[id].vertex+1489)->x= 3.29;
  (object[id].vertex+1489)->y= 0.214; 
  (object[id].vertex+1489)->z= 0.98;

  (object[id].vertex+1490)->x= 3.96;
  (object[id].vertex+1490)->y= 0.224;
  (object[id].vertex+1490)->z= -0.30;

  (object[id].vertex+1491)->x= 3.94; 
  (object[id].vertex+1491)->y= 0.224;
  (object[id].vertex+1491)->z= -0.30;   

  (object[id].vertex+1492)->x=  3.29;
  (object[id].vertex+1492)->y= 0.224; 
  (object[id].vertex+1492)->z= 0.98;   

  (object[id].vertex+1493)->x=  3.27;
  (object[id].vertex+1493)->y= 0.224;
  (object[id].vertex+1493)->z= 0.98;  
    
  (object[id].vertex+1494)->x= 3.11;
  (object[id].vertex+1494)->y= 0.214;           
  (object[id].vertex+1494)->z= 1.21;

  (object[id].vertex+1495)->x= 3.09; 
  (object[id].vertex+1495)->y= 0.214;          
  (object[id].vertex+1495)->z= 1.21;  

  (object[id].vertex+1496)->x= 3.11;  
  (object[id].vertex+1496)->y= 0.224;               
  (object[id].vertex+1496)->z= 1.21;   

  (object[id].vertex+1497)->x= 3.09; 
  (object[id].vertex+1497)->y= 0.224;            
  (object[id].vertex+1497)->z= 1.21;
    
  (object[id].vertex+1498)->x= 3.11; 
  (object[id].vertex+1498)->y= -0.214;           
  (object[id].vertex+1498)->z= 1.21;

  (object[id].vertex+1499)->x= 3.09; 
  (object[id].vertex+1499)->y= -0.214;          
  (object[id].vertex+1499)->z= 1.21;   

  (object[id].vertex+1500)->x=  3.11;  
  (object[id].vertex+1500)->y= -0.224;              
  (object[id].vertex+1500)->z= 1.21;   

  (object[id].vertex+1501)->x=  3.09; 
  (object[id].vertex+1501)->y= -0.224;                 
  (object[id].vertex+1501)->z= 1.21;  
    
       
  (object[id].vertex+1502)->x= 2.90;    //Porch
  (object[id].vertex+1502)->y= 0.49;    
  (object[id].vertex+1502)->z= 1.40;  

  (object[id].vertex+1503)->x= 2.90; 
  (object[id].vertex+1503)->y=0.49;          
  (object[id].vertex+1503)->z=1.41;
 
  (object[id].vertex+1504)->x= 2.35;
  (object[id].vertex+1504)->y= 0.49;           
  (object[id].vertex+1504)->z= 1.58; 

  (object[id].vertex+1505)->x= 2.35;
  (object[id].vertex+1505)->y= 0.49;              
  (object[id].vertex+1505)->z= 1.59;  

  (object[id].vertex+1506)->x= 2.90;
  (object[id].vertex+1506)->y= -0.49;            
  (object[id].vertex+1506)->z= 1.41; 

  (object[id].vertex+1507)->x= 2.90; 
  (object[id].vertex+1507)->y= -0.49;           
  (object[id].vertex+1507)->z= 1.40;   

  (object[id].vertex+1508)->x=  2.35; 
  (object[id].vertex+1508)->y= -0.49;               
  (object[id].vertex+1508)->z= 1.59; 

  (object[id].vertex+1509)->x=  2.35; 
  (object[id].vertex+1509)->y= -0.49;                 
  (object[id].vertex+1509)->z= 1.58; 

  (object[id].vertex+1510)->x= 2.05; 
  (object[id].vertex+1510)->y= 0.49;            
  (object[id].vertex+1510)->z= 1.6155;

  (object[id].vertex+1511)->x= 2.05; 
  (object[id].vertex+1511)->y= 0.49;           
  (object[id].vertex+1511)->z= 1.6055;   

  (object[id].vertex+1512)->x=  2.05;  
  (object[id].vertex+1512)->y= -0.49;               
  (object[id].vertex+1512)->z= 1.6155;  

  (object[id].vertex+1513)->x=  2.05; 
  (object[id].vertex+1513)->y= -0.49;                 
  (object[id].vertex+1513)->z= 1.6055;  

 
      /* Grasp L */  
 for (i=0; i<8; i++){
  float xc=2.90, yc= 0.48, zc=1.409, radius_x=0.004,radius_y=0.006;
              
  (object[id].vertex+1514+i)->x=xc+radius_x*sin(i*PI/4+PI/8);
  (object[id].vertex+1514+i)->y=yc+radius_y*cos(i*PI/4+PI/8);
  (object[id].vertex+1514+i)->z=zc;
 }

    /* Grasp L */
 for (i=0; i<8; i++){
  float xc=2.85 , yc= 0.48, zc=1.59, radius_x=0.004,radius_y=0.006;
           
  (object[id].vertex+1522+i)->x=xc+radius_x*sin(i*PI/4+PI/8);
  (object[id].vertex+1522+i)->y=yc+radius_y*cos(i*PI/4+PI/8);
  (object[id].vertex+1522+i)->z=zc;
 }
  
       /* Grasp R */  
 for (i=0; i<8; i++){
  float xc=2.90, yc=-0.48, zc=1.409, radius_x=0.004,radius_y=0.006; 
          
  (object[id].vertex+1530+i)->x=xc+radius_x*sin(i*PI/4+PI/8);
  (object[id].vertex+1530+i)->y=yc+radius_y*cos(i*PI/4+PI/8);
  (object[id].vertex+1530+i)->z=zc;
 }

    /* Grasp R */
 for (i=0; i<8; i++){
  float xc=2.85 , yc=-0.48, zc=1.59, radius_x=0.004,radius_y=0.006;
          
  (object[id].vertex+1538+i)->x=xc+radius_x*sin(i*PI/4+PI/8);
  (object[id].vertex+1538+i)->y=yc+radius_y*cos(i*PI/4+PI/8);
  (object[id].vertex+1538+i)->z=zc;
 }
  
         /* Grasp L */  
 for (i=0; i<8; i++){
  float xc=2.055, yc=0.48, zc=1.609, radius_x=0.010,radius_y=0.008; 
         
  (object[id].vertex+1546+i)->x=xc+radius_x*sin(i*PI/4+PI/8);
  (object[id].vertex+1546+i)->y=yc+radius_y*cos(i*PI/4+PI/8);
  (object[id].vertex+1546+i)->z=zc;
 }

    /* Grasp L */
 for (i=0; i<8; i++){
  float xc=2.30 , yc=0.48, zc=1.80, radius_x=0.010,radius_y=0.008;
           
  (object[id].vertex+1554+i)->x=xc+radius_x*sin(i*PI/4+PI/8);
  (object[id].vertex+1554+i)->y=yc+radius_y*cos(i*PI/4+PI/8);
  (object[id].vertex+1554+i)->z=zc;
 } 
           /* Grasp R */  
 for (i=0; i<8; i++){
  float xc=2.055, yc=-0.48, zc=1.609, radius_x=0.010,radius_y=0.008; 
                              
  (object[id].vertex+1562+i)->x=xc+radius_x*sin(i*PI/4+PI/8);
  (object[id].vertex+1562+i)->y=yc+radius_y*cos(i*PI/4+PI/8);
  (object[id].vertex+1562+i)->z=zc;
 }

    /* Grasp R */
 for (i=0; i<8; i++){
  float xc=2.30 , yc=-0.48, zc=1.80, radius_x=0.010,radius_y=0.008;
           
  (object[id].vertex+1570+i)->x=xc+radius_x*sin(i*PI/4+PI/8);
  (object[id].vertex+1570+i)->y=yc+radius_y*cos(i*PI/4+PI/8);
  (object[id].vertex+1570+i)->z=zc;
 }
 
  
    /* Top R */  
 for (i=0; i<8; i++){              
  float xc=-0.48 , yc=1.82, zc=2.33, radius=0.007;
                       
  (object[id].vertex+1578+i)->y=xc+radius*sin(i*PI/4+PI/8); 
  (object[id].vertex+1578+i)->z=yc+radius*cos(i*PI/4+PI/8);
  (object[id].vertex+1578+i)->x=zc;                              
 }

    /* Top R */  
 for (i=0; i<8; i++){
  float xc=-0.48 , yc=1.65, zc=2.80, radius=0.007; 
                                
  (object[id].vertex+1586+i)->y=xc+radius*sin(i*PI/4+PI/8); 
  (object[id].vertex+1586+i)->z=yc+radius*cos(i*PI/4+PI/8);
  (object[id].vertex+1586+i)->x=zc;
 }

    /* Top L */  
 for (i=0; i<8; i++){              
  float xc=0.48 , yc=1.82, zc=2.33, radius=0.007;            
                      
 (object[id].vertex+1594+i)->y=xc+radius*sin(i*PI/4+PI/8); 
  (object[id].vertex+1594+i)->z=yc+radius*cos(i*PI/4+PI/8);
  (object[id].vertex+1594+i)->x=zc;                              
 }

    /* Top L */  
 for (i=0; i<8; i++){
  float xc=0.48 , yc=1.65, zc=2.80, radius=0.007; 
          
  (object[id].vertex+1602+i)->y=xc+radius*sin(i*PI/4+PI/8); 
  (object[id].vertex+1602+i)->z=yc+radius*cos(i*PI/4+PI/8);
  (object[id].vertex+1602+i)->x=zc;
 }
  
   /* 5' */ 
 (object[id].vertex+1610)->x= 1.437885;
 (object[id].vertex+1610)->y= -1.30517;  
 (object[id].vertex+1610)->z= 0.592;


 (object[id].vertex+1611)->x= 1.437885;   
 (object[id].vertex+1611)->y= -1.30517;
 (object[id].vertex+1611)->z= 0.312; 

 (object[id].vertex+1612)->x= 1.344;
 (object[id].vertex+1612)->y= -1.40; 
 (object[id].vertex+1612)->z= 0.312; 

 (object[id].vertex+1613)->x= 1.344;
 (object[id].vertex+1613)->y= -1.40; 
 (object[id].vertex+1613)->z= 0.704;  

 (object[id].vertex+1614)->x= 1.595;  
 (object[id].vertex+1614)->y=  -1.15;
 (object[id].vertex+1614)->z= 0.704;  
 
 (object[id].vertex+1615)->x= 1.595; 
 (object[id].vertex+1615)->y=  -1.15;
 (object[id].vertex+1615)->z= 0.928;  
 
 (object[id].vertex+1616)->x= 2.0574;  
 (object[id].vertex+1616)->y=  -0.6858;
 (object[id].vertex+1616)->z= 0.928;  
 
 (object[id].vertex+1617)->x= 0.8190; 
 (object[id].vertex+1617)->y= -1.925;        
 (object[id].vertex+1617)->z= 1.60;  

 (object[id].vertex+1618)->x= 1.745;
 (object[id].vertex+1618)->y= 1.0; 
 (object[id].vertex+1618)->z=-0.08; 

 (object[id].vertex+1619)->x= 2.0574;
 (object[id].vertex+1619)->y= 0.6858; 
 (object[id].vertex+1619)->z=1.012;  

 (object[id].vertex+1620)->x= 1.745;  
 (object[id].vertex+1620)->y= 1.0; 
 (object[id].vertex+1620)->z= 0.76;  

 (object[id].vertex+1621)->x= -0.845;
 (object[id].vertex+1621)->y= 1.90; 
 (object[id].vertex+1621)->z=-0.08; 

 (object[id].vertex+1622)->x=-0.6858; 
 (object[id].vertex+1622)->y= 2.0574; 
 (object[id].vertex+1622)->z=0.87;  

 (object[id].vertex+1623)->x= -0.845; 
 (object[id].vertex+1623)->y= 1.90;
 (object[id].vertex+1623)->z=0.87; 

 (object[id].vertex+1624)->x=-2.0574; 
 (object[id].vertex+1624)->y= 0.6858; 
 (object[id].vertex+1624)->z=0.87;  
 
 (object[id].vertex+1625)->x=-1.90;
 (object[id].vertex+1625)->y=0.845; 
 (object[id].vertex+1625)->z=0.87; 

 (object[id].vertex+1626)->x=-1.90;
 (object[id].vertex+1626)->y=0.845;
 (object[id].vertex+1626)->z=-0.08; 

    /*  Landing gear 1   */                
 for (i=0; i<8; i++){              
  float xc=-3.895 , yc=0.0, zc=-0.40, radius=0.06;
                            
  (object[id].vertex+1627+i)->x=xc+radius*sin(i*PI/4+PI/8); 
  (object[id].vertex+1627+i)->y=yc+radius*cos(i*PI/4+PI/8);  
  (object[id].vertex+1627+i)->z=zc;
 }

    /* / Landing gear  1   */ 
 for (i=0; i<8; i++){
  float xc=-4.2562 , yc=0.0, zc=-1.10, radius=0.06; 
          
  (object[id].vertex+1635+i)->x=xc+radius*sin(i*PI/4+PI/8); 
  (object[id].vertex+1635+i)->y=yc+radius*cos(i*PI/4+PI/8);
  (object[id].vertex+1635+i)->z=zc;
 }

     /* Landing gear 2 */  
 for (i=0; i<8; i++){              
  float xc=0.0 , yc=3.895, zc=-0.40, radius=0.06;
                           
  (object[id].vertex+1643+i)->x=xc+radius*sin(i*PI/4+PI/8); 
  (object[id].vertex+1643+i)->y=yc+radius*cos(i*PI/4+PI/8);
  (object[id].vertex+1643+i)->z=zc;
 }

    /* / Landing gear 2  */  
 for (i=0; i<8; i++){
  float xc=0.0, yc=4.2562, zc=-1.10, radius=0.06; 
                  
  (object[id].vertex+1651+i)->x=xc+radius*sin(i*PI/4+PI/8); 
  (object[id].vertex+1651+i)->y=yc+radius*cos(i*PI/4+PI/8);
  (object[id].vertex+1651+i)->z=zc;
 }
 
     /* Landing gear 3 */  
 for (i=0; i<8; i++){              
  float xc=0.0 , yc=-3.895, zc=-0.40, radius=0.06;
         
  (object[id].vertex+1659+i)->x=xc+radius*sin(i*PI/4+PI/8); 
  (object[id].vertex+1659+i)->y=yc+radius*cos(i*PI/4+PI/8);
  (object[id].vertex+1659+i)->z=zc;
 }

    /* / Landing gear 3  */  
 for (i=0; i<8; i++){
  float xc=0.0, yc=-4.2562, zc=-1.10, radius=0.06; 
       
  (object[id].vertex+1667+i)->x=xc+radius*sin(i*PI/4+PI/8); 
  (object[id].vertex+1667+i)->y=yc+radius*cos(i*PI/4+PI/8);
  (object[id].vertex+1667+i)->z=zc;
 }

      /* Landing gear 4 */  
 for (i=0; i<8; i++){              
  float xc=3.895 , yc=0.0, zc=-0.40, radius=0.06;
               
  (object[id].vertex+1675+i)->x=xc+radius*sin(i*PI/4+PI/8); 
  (object[id].vertex+1675+i)->y=yc+radius*cos(i*PI/4+PI/8);
  (object[id].vertex+1675+i)->z=zc;
 }

    /* / Landing gear 4  */  
 for (i=0; i<8; i++){
  float xc= 4.2562, yc=0.0, zc=-1.10, radius=0.06; 
        
  (object[id].vertex+1683+i)->x=xc+radius*sin(i*PI/4+PI/8); 
  (object[id].vertex+1683+i)->y=yc+radius*cos(i*PI/4+PI/8);
  (object[id].vertex+1683+i)->z=zc;
 }


  /*  P1   */                
 for (i=0; i<8; i++){              
  float xc=-2.0 , yc=1.30, zc= 0.80, radius_x=0.03,radius_y=0.03;
             
  (object[id].vertex+1691+i)->x=xc+radius_x*sin(i*PI/4+PI/8); 
  (object[id].vertex+1691+i)->z=yc+radius_y*cos(i*PI/4+PI/8);  
  (object[id].vertex+1691+i)->y=zc;
 }

    /* / P1   */ 
 for (i=0; i<8; i++){
  float xc=-1.75 , yc=1.55, zc=1.60, radius_x=0.03,radius_y=0.03; 
          
  (object[id].vertex+1699+i)->x=xc+radius_x*sin(i*PI/4+PI/8); 
  (object[id].vertex+1699+i)->z=yc+radius_y*cos(i*PI/4+PI/8);
  (object[id].vertex+1699+i)->y=zc;
 }

     /* P2  */  
 for (i=0; i<8; i++){              
  float xc=2.0 , yc=1.20, zc=0.80, radius_x=0.03,radius_y=0.03;
        //-2.0    //1.20    //0.80
  (object[id].vertex+1707+i)->x=xc+radius_x*sin(i*PI/4+PI/8); 
  (object[id].vertex+1707+i)->z=yc+radius_y*cos(i*PI/4+PI/8);
  (object[id].vertex+1707+i)->y=zc;
 }

    /* / P2  */  
 for (i=0; i<8; i++){
  float xc=1.75, yc=1.45, zc=1.60, radius_x=0.03,radius_y=0.03; 
           //-1.75    //1.45  //1.60      
  (object[id].vertex+1715+i)->x=xc+radius_x*sin(i*PI/4+PI/8); 
  (object[id].vertex+1715+i)->z=yc+radius_y*cos(i*PI/4+PI/8);
  (object[id].vertex+1715+i)->y=zc;
 }

    //    /* C  */                 
 //for (i=0; i<8; i++){
  //float xc=1.30 , yc= 0.80, zc=2.0, radius_x=0.03,radius_y=0.03;
          
  //(object[id].vertex+1642+i)->z=xc+radius_x*sin(i*PI/4+PI/8);  
  //(object[id].vertex+1642+i)->x=yc+radius_y*cos(i*PI/4+PI/8);  
  //(object[id].vertex+1642+i)->y=zc;
 //}

   // /*  C  */
 //for (i=0; i<8; i++){
  //float xc=1.55 , yc= 1.65, zc=1.60, radius_x=0.03,radius_y=0.03;
       
  //(object[id].vertex+1650+i)->z=xc+radius_x*sin(i*PI/4+PI/8);
  //(object[id].vertex+1650+i)->x=yc+radius_y*cos(i*PI/4+PI/8);   
  //(object[id].vertex+1650+i)->y=zc;
 //}




   /*
 (object[id].vertex+)->x=;
 (object[id].vertex+)->y=;
 (object[id].vertex+)->z=;
 */

 /**********/
 /* Facets */
 /**********/

 
 /* 1 */                    
 facetid->color=LIGHTCYAN;
 facetid->nedges=4;
 facetid->edge[0]=0;
 facetid->edge[1]=1;             
 facetid->edge[2]=2;
 facetid->edge[3]=3;
 facetid++;
 
 facetid->color=LIGHTRED;     
 facetid->nedges=4;   
 facetid->edge[0]=111;  
 facetid->edge[1]=1;            
 facetid->edge[2]=0; 
 facetid->edge[3]=109;
 facetid++;
 
 /* 2 */                  
 
 facetid->color=LIGHTCYAN;
 facetid->nedges=4;     
 facetid->edge[0]=8;  
 facetid->edge[1]=11;       
 facetid->edge[2]=13;                 
 facetid->edge[3]=12; 
 facetid++;
 
 //facetid->color=WHITE;
 //facetid->nedges=4;
 //facetid->edge[0]=14;  
 //facetid->edge[1]=15;          
 //facetid->edge[2]=10; 
 //facetid->edge[3]=9; 
 //facetid++;
  
 facetid->color=LIGHTRED;
 facetid->nedges=4;
 facetid->edge[0]=105;
 facetid->edge[1]=107;          
 facetid->edge[2]=8; 
 facetid->edge[3]=12; 
 facetid++;


 //facetid->color=WHITE;
 //facetid->nedges=4;
 //facetid->edge[0]=11;
 //facetid->edge[1]=10;      
 //facetid->edge[2]=15;
 //facetid->edge[3]=13;
 //facetid++;
 
 /* 3 */                
 facetid->color=LIGHTCYAN;
 facetid->nedges=4;
 facetid->edge[0]=20;  
 facetid->edge[1]=21;  
 facetid->edge[2]=19;                 
 facetid->edge[3]=16; 
 facetid++;
 
 //facetid->color=WHITE;
 //facetid->nedges=4;
 //facetid->edge[0]=17;  
 //facetid->edge[1]=18;          
 //facetid->edge[2]=23; 
 //facetid->edge[3]=22; 
 //facetid++;
  
 facetid->color=LIGHTRED;    
 facetid->nedges=4;
 facetid->edge[0]=20;  
 facetid->edge[1]=16;        
 facetid->edge[2]=24;    
 facetid->edge[3]=26; 
 facetid++;


 //facetid->color=WHITE;
 //facetid->nedges=4;
 //facetid->edge[0]=21;
 //facetid->edge[1]=23;
 //facetid->edge[2]=18;
 //facetid->edge[3]=19;
 //facetid++;
 
  /* Heat Shield */                    
 facetid->color=LIGHTRED;
 facetid->nedges=4;
 facetid->edge[0]=27;    
 facetid->edge[1]=26;      
 facetid->edge[2]=24;                   
 facetid->edge[3]=25;            
 facetid++;
 
 facetid->color=LIGHTRED;
 facetid->nedges=4;
 facetid->edge[0]=31;  
 facetid->edge[1]=30;  
 facetid->edge[2]=28;   
 facetid->edge[3]=29; 
 facetid++;
 
 facetid->color=LIGHTRED;
 facetid->nedges=4;
 facetid->edge[0]=30; 
 facetid->edge[1]=31;   
 facetid->edge[2]=26;
 facetid->edge[3]=27;
 facetid++;
  
 
 facetid->color=LIGHTRED;
 facetid->nedges=4;          
 facetid->edge[0]=104;  
 facetid->edge[1]=105;         
 facetid->edge[2]=29;
 facetid->edge[3]=28;
 facetid++;

 facetid->color=LIGHTRED;
 facetid->nedges=4;          
 facetid->edge[0]=106;   
 facetid->edge[1]=107;          
 facetid->edge[2]=105;
 facetid->edge[3]=104;
 facetid++;

 facetid->color=LIGHTRED;
 facetid->nedges=4;          
 facetid->edge[0]=108;   
 facetid->edge[1]=109;           
 facetid->edge[2]=107;
 facetid->edge[3]=106;
 facetid++;
 
 facetid->color=LIGHTRED;
 facetid->nedges=4;          
 facetid->edge[0]=110;   
 facetid->edge[1]=111;          
 facetid->edge[2]=109;
 facetid->edge[3]=108;
 facetid++;
 
 facetid->color=LIGHTRED;
 facetid->nedges=4;          
 facetid->edge[0]=112;   
 facetid->edge[1]=113;        
 facetid->edge[2]=111;
 facetid->edge[3]=110;
 facetid++;

 /* Under Heatshield */ 
 facetid->color=LIGHTGRAY;
 facetid->nedges=4;
 facetid->edge[0]=28; 
 facetid->edge[1]=30;   
 facetid->edge[2]=118;
 facetid->edge[3]=125;
 facetid++;

 facetid->color=LIGHTGRAY;
 facetid->nedges=4;
 facetid->edge[0]=28; 
 facetid->edge[1]=125;   
 facetid->edge[2]=124;
 facetid->edge[3]=104;
 facetid++;

 facetid->color=LIGHTGRAY;
 facetid->nedges=4;
 facetid->edge[0]=104; 
 facetid->edge[1]=124;   
 facetid->edge[2]=123;
 facetid->edge[3]=106;
 facetid++;

 facetid->color=LIGHTGRAY;
 facetid->nedges=4;
 facetid->edge[0]=106; 
 facetid->edge[1]=123;   
 facetid->edge[2]=122;
 facetid->edge[3]=108;
 facetid++;

 facetid->color=LIGHTGRAY;
 facetid->nedges=4;
 facetid->edge[0]=108; 
 facetid->edge[1]=122;   
 facetid->edge[2]=121;
 facetid->edge[3]=110;
 facetid++;

 facetid->color=LIGHTGRAY;
 facetid->nedges=4;
 facetid->edge[0]=110;
 facetid->edge[1]=121;   
 facetid->edge[2]=120;
 facetid->edge[3]=112;
 facetid++;

 facetid->color=LIGHTGRAY;
 facetid->nedges=4;
 facetid->edge[0]=112; 
 facetid->edge[1]=120;   
 facetid->edge[2]=119;
 facetid->edge[3]=27;
 facetid++;

 facetid->color=LIGHTGRAY;
 facetid->nedges=4;
 facetid->edge[0]=27;
 facetid->edge[1]=119;   
 facetid->edge[2]=118;
 facetid->edge[3]=30;
 facetid++;

 /*  5 */            
 facetid->color=LIGHTCYAN;
 facetid->nedges=4;
 facetid->edge[0]=39;
 facetid->edge[1]=38;  
 facetid->edge[2]=36;  
 facetid->edge[3]=37;  
 facetid++;
 
  
 facetid->color=LIGHTRED;
 facetid->nedges=4;
 facetid->edge[0]=38;  
 facetid->edge[1]=31;          
 facetid->edge[2]=29;  
 facetid->edge[3]=36;  
 facetid++;
 
 facetid->color=DARKGRAY; 
 facetid->nedges=4;
 facetid->edge[0]=3;
 facetid->edge[1]=11;      
 facetid->edge[2]=8; 
 facetid->edge[3]=0; 
 facetid++;
 
 facetid->color=LIGHTCYAN;
 facetid->nedges=7;
 facetid->edge[0]=1;
 facetid->edge[1]=16;       
 facetid->edge[2]=1611; 
 facetid->edge[3]=1612;
 facetid->edge[4]=1613;
 facetid->edge[5]=1617;
 facetid->edge[6]=2;
 facetid++;

 facetid->color=LIGHTCYAN;
 facetid->nedges=6;
 facetid->edge[0]=1616;
 facetid->edge[1]=1615;       
 facetid->edge[2]=1614; 
 facetid->edge[3]=1610;
 facetid->edge[4]=1611;
 facetid->edge[5]=16;
 facetid++;

 facetid->color=DARKGRAY;
 facetid->nedges=4;
 facetid->edge[0]=1613;
 facetid->edge[1]=1612;    
 facetid->edge[2]=1611;
 facetid->edge[3]=1610;
 facetid++;

 facetid->color=DARKGRAY;
 facetid->nedges=7;
 facetid->edge[0]=1617;
 facetid->edge[1]=1613;
 facetid->edge[2]=1610;
 facetid->edge[3]=1614;
 facetid->edge[4]=1615;
 facetid->edge[5]=1616;
 facetid->edge[6]=19;
 facetid++;

 
 facetid->color=DARKGRAY;
 facetid->nedges=6;
 facetid->edge[0]=1618;
 facetid->edge[1]=38;       
 facetid->edge[2]=39; 
 facetid->edge[3]=21;
 facetid->edge[4]=1619;
 facetid->edge[5]=1620;
 facetid++;

 facetid->color=LIGHTRED;
 facetid->nedges=4;
 facetid->edge[0]=20;
 facetid->edge[1]=1618;       
 facetid->edge[2]=1620; 
 facetid->edge[3]=1619;
 facetid++;

 facetid->color=DARKGRAY;
 facetid->nedges=3;
 facetid->edge[0]=37; 
 facetid->edge[1]=1622;       
 facetid->edge[2]=1623; 
 facetid++;
 
 facetid->color=DARKGRAY; 
 facetid->nedges=4;
 facetid->edge[0]=1625;
 facetid->edge[1]=1624;        
 facetid->edge[2]=13; 
 facetid->edge[3]=37;
 facetid++;
 
 facetid->color=DARKGRAY; 
 facetid->nedges=6;
 facetid->edge[0]=1625;
 facetid->edge[1]=37;        
 facetid->edge[2]=1622; 
 facetid->edge[3]=1623;
 facetid->edge[4]=1621;
 facetid->edge[5]=1626;
 facetid++;

 facetid->color=LIGHTCYAN; 
 facetid->nedges=4;
 facetid->edge[0]=1624; 
 facetid->edge[1]=1625;        
 facetid->edge[2]=1626; 
 facetid->edge[3]=12;
 facetid++;

 facetid->color=LIGHTCYAN;
 facetid->nedges=4;
 facetid->edge[0]=1623;
 facetid->edge[1]=1622;        
 facetid->edge[2]=36; 
 facetid->edge[3]=1621;
 facetid++;

 facetid->color=LIGHTRED; 
 facetid->nedges=4;
 facetid->edge[0]=12;
 facetid->edge[1]=36;       
 facetid->edge[2]=29;
 facetid->edge[3]=105; 
 facetid++;
 
 facetid->color=LIGHTRED; 
 facetid->nedges=4;
 facetid->edge[0]=109;       
 facetid->edge[1]=0;               
 facetid->edge[2]=8;          
 facetid->edge[3]=107;
 facetid++;
 
 facetid->color=LIGHTRED; 
 facetid->nedges=4;
 facetid->edge[0]=38;           
 facetid->edge[1]=20;             
 facetid->edge[2]=26;         
 facetid->edge[3]=31;   
 facetid++;
  
 facetid->color=LIGHTRED; 
 facetid->nedges=4;
 facetid->edge[0]=113;             
 facetid->edge[1]=16;               
 facetid->edge[2]=1;          
 facetid->edge[3]=111;
 facetid++;

 facetid->color=LIGHTRED;   
 facetid->nedges=4;                            
 facetid->edge[0]=3;                           
 facetid->edge[1]=2;      
 facetid->edge[2]=457;
 facetid->edge[3]=458;
 facetid++;
 
 facetid->color=DARKGRAY;
 facetid->nedges=4;
 facetid->edge[0]=11;          
 facetid->edge[1]=3;               
 facetid->edge[2]=458;          
 facetid->edge[3]=459;
 facetid++;
 
 facetid->color=LIGHTRED;  
 facetid->nedges=4;
 facetid->edge[0]=21;             
 facetid->edge[1]=39;               
 facetid->edge[2]=454;          
 facetid->edge[3]=455;
 facetid++;
 
 facetid->color=DARKGRAY;
 facetid->nedges=4;
 facetid->edge[0]=37;           
 facetid->edge[1]=13;               
 facetid->edge[2]=460;          
 facetid->edge[3]=461;
 facetid++;

 facetid->color=LIGHTRED;
 facetid->nedges=4;
 facetid->edge[0]=19;          
 facetid->edge[1]=21;            
 facetid->edge[2]=455;      
 facetid->edge[3]=456;
 facetid++;

 facetid->color=LIGHTRED; 
 facetid->nedges=4;
 facetid->edge[0]=13;         
 facetid->edge[1]=11;             
 facetid->edge[2]=459;      
 facetid->edge[3]=460;
 facetid++;

 facetid->color=LIGHTRED; 
 facetid->nedges=4;
 facetid->edge[0]=2;          
 facetid->edge[1]=19;             
 facetid->edge[2]=456;      
 facetid->edge[3]=457;
 facetid++;
 
 facetid->color=LIGHTRED; 
 facetid->nedges=4;
 facetid->edge[0]=39;          
 facetid->edge[1]=37;             
 facetid->edge[2]=461;      
 facetid->edge[3]=454;
 facetid++;

 //facetid->color=BLUE;        //Landing pad 1
 //facetid->nedges=8; 
 //facetid->edge[0]=40;
 //facetid->edge[1]=41;
 //facetid->edge[2]=42;
 //facetid->edge[3]=43;            
 //facetid->edge[4]=44;
 //facetid->edge[5]=45;
 //facetid->edge[6]=46;
 //facetid->edge[7]=47;
 //facetid++;

 facetid->color=BLUE;
 facetid->nedges=8;
 facetid->edge[0]=55;
 facetid->edge[1]=54;
 facetid->edge[2]=53;
 facetid->edge[3]=52;          
 facetid->edge[4]=51;
 facetid->edge[5]=50;
 facetid->edge[6]=49;
 facetid->edge[7]=48;
 facetid++;

 facetid->color=BLUE;
 facetid->nedges=3;                             
 facetid->edge[0]=48;       
 facetid->edge[1]=49;        
 facetid->edge[2]=885;  
 facetid++;
 
 facetid->color=BLUE;
 facetid->nedges=3;                             
 facetid->edge[0]=49;       
 facetid->edge[1]=50;        
 facetid->edge[2]=885;  
 facetid++;

 facetid->color=BLUE;
 facetid->nedges=3;                             
 facetid->edge[0]=50;       
 facetid->edge[1]=51;        
 facetid->edge[2]=885;  
 facetid++;
 
 facetid->color=BLUE;
 facetid->nedges=3;                             
 facetid->edge[0]=51;       
 facetid->edge[1]=52;        
 facetid->edge[2]=885;  
 facetid++;

 facetid->color=BLUE;
 facetid->nedges=3;                             
 facetid->edge[0]=52;       
 facetid->edge[1]=53;        
 facetid->edge[2]=885;  
 facetid++;
 
 facetid->color=BLUE;
 facetid->nedges=3;                             
 facetid->edge[0]=53;       
 facetid->edge[1]=54;        
 facetid->edge[2]=885;  
 facetid++;
 
 facetid->color=BLUE;
 facetid->nedges=3;                             
 facetid->edge[0]=54;       
 facetid->edge[1]=55;        
 facetid->edge[2]=885;  
 facetid++;

 facetid->color=BLUE;
 facetid->nedges=3;                             
 facetid->edge[0]=55;       
 facetid->edge[1]=48;        
 facetid->edge[2]=885;  
 facetid++;

 facetid->color=BLUE;
 facetid->nedges=4;                             
 facetid->edge[0]=40;       
 facetid->edge[1]=41;        
 facetid->edge[2]=49;  
 facetid->edge[3]=48;
 facetid++;

 facetid->color=BLUE;
 facetid->nedges=4;                        
 facetid->edge[0]=41;                           
 facetid->edge[1]=42;      
 facetid->edge[2]=50;
 facetid->edge[3]=49;
 facetid++;

 facetid->color=BLUE;
 facetid->nedges=4;                             
 facetid->edge[0]=42;                        
 facetid->edge[1]=43;      
 facetid->edge[2]=51;
 facetid->edge[3]=50;
 facetid++;

 facetid->color=BLUE;
 facetid->nedges=4;                         
 facetid->edge[0]=43;                           
 facetid->edge[1]=44;      
 facetid->edge[2]=52;
 facetid->edge[3]=51;
 facetid++;

 facetid->color=BLUE;
 facetid->nedges=4;                       
 facetid->edge[0]=44;                           
 facetid->edge[1]=45;      
 facetid->edge[2]=53;
 facetid->edge[3]=52;
 facetid++;

 facetid->color=BLUE;
 facetid->nedges=4;                      
 facetid->edge[0]=45;                           
 facetid->edge[1]=46;      
 facetid->edge[2]=54;
 facetid->edge[3]=53;
 facetid++;

 facetid->color=BLUE;
 facetid->nedges=4;                             
 facetid->edge[0]=46;                      
 facetid->edge[1]=47;      
 facetid->edge[2]=55;
 facetid->edge[3]=54;
 facetid++;

 facetid->color=BLUE;
 facetid->nedges=4;                        
 facetid->edge[0]=47;                           
 facetid->edge[1]=40;      
 facetid->edge[2]=48;
 facetid->edge[3]=55;
 facetid++;                     

 facetid->color=BLUE;
 facetid->nedges=4;                             
 facetid->edge[0]=48;                        
 facetid->edge[1]=49;      
 facetid->edge[2]=41;
 facetid->edge[3]=40;
 facetid++;

 facetid->color=BLUE;
 facetid->nedges=4;                       
 facetid->edge[0]=49;                           
 facetid->edge[1]=50;      
 facetid->edge[2]=42;
 facetid->edge[3]=41;
 facetid++;

 facetid->color=BLUE;
 facetid->nedges=4;                             
 facetid->edge[0]=50;                    
 facetid->edge[1]=51;     
 facetid->edge[2]=43;
 facetid->edge[3]=42;
 facetid++;

 facetid->color=BLUE;
 facetid->nedges=4;                      
 facetid->edge[0]=51;                        
 facetid->edge[1]=52;    
 facetid->edge[2]=44;
 facetid->edge[3]=43;
 facetid++;

 facetid->color=BLUE;
 facetid->nedges=4;                   
 facetid->edge[0]=52;                          
 facetid->edge[1]=53;     
 facetid->edge[2]=45;
 facetid->edge[3]=44;
 facetid++;

 facetid->color=BLUE;
 facetid->nedges=4;                      
 facetid->edge[0]=53;                        
 facetid->edge[1]=54;    
 facetid->edge[2]=46;
 facetid->edge[3]=45;
 facetid++;

 facetid->color=BLUE;
 facetid->nedges=4;                             
 facetid->edge[0]=54;                    
 facetid->edge[1]=55;      
 facetid->edge[2]=47;
 facetid->edge[3]=46;
 facetid++;

 facetid->color=BLUE;
 facetid->nedges=4;                         
 facetid->edge[0]=55;                           
 facetid->edge[1]=48;      
 facetid->edge[2]=40;
 facetid->edge[3]=47;
 facetid++;

 //facetid->color=BLUE;        //Landing pad 2 
 //facetid->nedges=8;
 //facetid->edge[0]=56;
 //facetid->edge[1]=57;
 //facetid->edge[2]=58;
 //facetid->edge[3]=59;            
 //facetid->edge[4]=60;
 //facetid->edge[5]=61;
 //facetid->edge[6]=62;
 //facetid->edge[7]=63;
 //facetid++;

 facetid->color=BLUE;
 facetid->nedges=3;                             
 facetid->edge[0]=64;                         
 facetid->edge[1]=65;        
 facetid->edge[2]=883;  
 facetid++;
 
 facetid->color=BLUE;
 facetid->nedges=3;                             
 facetid->edge[0]=65;                         
 facetid->edge[1]=66;        
 facetid->edge[2]=883;  
 facetid++;
 
 facetid->color=BLUE;
 facetid->nedges=3;                             
 facetid->edge[0]=66;                         
 facetid->edge[1]=67;        
 facetid->edge[2]=883;  
 facetid++;
 
 facetid->color=BLUE;
 facetid->nedges=3;                             
 facetid->edge[0]=67;                         
 facetid->edge[1]=68;        
 facetid->edge[2]=883;  
 facetid++;
 
 facetid->color=BLUE;
 facetid->nedges=3;                             
 facetid->edge[0]=68;                         
 facetid->edge[1]=69;        
 facetid->edge[2]=883;  
 facetid++;
 
 facetid->color=BLUE;
 facetid->nedges=3;                             
 facetid->edge[0]=69;                         
 facetid->edge[1]=70;        
 facetid->edge[2]=883;  
 facetid++;
 
 facetid->color=BLUE;
 facetid->nedges=3;                             
 facetid->edge[0]=70;                         
 facetid->edge[1]=71;        
 facetid->edge[2]=883;  
 facetid++;
 
 facetid->color=BLUE;
 facetid->nedges=3;                             
 facetid->edge[0]=71;                         
 facetid->edge[1]=64;        
 facetid->edge[2]=883;  
 facetid++;
 
 facetid->color=BLUE;
 facetid->nedges=8;
 facetid->edge[0]=71;
 facetid->edge[1]=70;
 facetid->edge[2]=69;
 facetid->edge[3]=68;          
 facetid->edge[4]=67;
 facetid->edge[5]=66;
 facetid->edge[6]=65;
 facetid->edge[7]=64;
 facetid++;

 facetid->color=BLUE;
 facetid->nedges=4;                             
 facetid->edge[0]=56;                         
 facetid->edge[1]=57;        
 facetid->edge[2]=65;  
 facetid->edge[3]=64;
 facetid++;

 facetid->color=BLUE;
 facetid->nedges=4;                        
 facetid->edge[0]=57;                           
 facetid->edge[1]=58;      
 facetid->edge[2]=66;
 facetid->edge[3]=65;
 facetid++;

 facetid->color=BLUE;
 facetid->nedges=4;                             
 facetid->edge[0]=58;                       
 facetid->edge[1]=59;      
 facetid->edge[2]=67;
 facetid->edge[3]=66;
 facetid++;

 facetid->color=BLUE;
 facetid->nedges=4;                     
 facetid->edge[0]=59;                           
 facetid->edge[1]=60;      
 facetid->edge[2]=68;
 facetid->edge[3]=67;
 facetid++;

 facetid->color=BLUE;
 facetid->nedges=4;                       
 facetid->edge[0]=60;                           
 facetid->edge[1]=61;      
 facetid->edge[2]=69;
 facetid->edge[3]=68;
 facetid++;

 facetid->color=BLUE;
 facetid->nedges=4;                      
 facetid->edge[0]=61;                         
 facetid->edge[1]=62;      
 facetid->edge[2]=70;
 facetid->edge[3]=69;
 facetid++;

 facetid->color=BLUE;
 facetid->nedges=4;                             
 facetid->edge[0]=62;                   
 facetid->edge[1]=63;      
 facetid->edge[2]=71;
 facetid->edge[3]=70;
 facetid++;

 facetid->color=BLUE;
 facetid->nedges=4;                          
 facetid->edge[0]=63;                           
 facetid->edge[1]=56;      
 facetid->edge[2]=64;
 facetid->edge[3]=71;
 facetid++;                     

 facetid->color=BLUE;
 facetid->nedges=4;                             
 facetid->edge[0]=64;                     
 facetid->edge[1]=65;      
 facetid->edge[2]=57;
 facetid->edge[3]=56;
 facetid++;

 facetid->color=BLUE;
 facetid->nedges=4;                      
 facetid->edge[0]=65;                           
 facetid->edge[1]=66;      
 facetid->edge[2]=58;
 facetid->edge[3]=57;
 facetid++;

 facetid->color=BLUE;
 facetid->nedges=4;                             
 facetid->edge[0]=66;                     
 facetid->edge[1]=67;     
 facetid->edge[2]=59;
 facetid->edge[3]=58;
 facetid++;

 facetid->color=BLUE;
 facetid->nedges=4;                        
 facetid->edge[0]=67;                        
 facetid->edge[1]=68;    
 facetid->edge[2]=60;
 facetid->edge[3]=59;
 facetid++;

 facetid->color=BLUE;
 facetid->nedges=4;                       
 facetid->edge[0]=68;                         
 facetid->edge[1]=69;     
 facetid->edge[2]=61;
 facetid->edge[3]=60;
 facetid++;

 facetid->color=BLUE;
 facetid->nedges=4;                        
 facetid->edge[0]=69;                        
 facetid->edge[1]=70;    
 facetid->edge[2]=62;
 facetid->edge[3]=61;
 facetid++;

 facetid->color=BLUE;
 facetid->nedges=4;                             
 facetid->edge[0]=70;                   
 facetid->edge[1]=71;      
 facetid->edge[2]=63;
 facetid->edge[3]=62;
 facetid++;

 facetid->color=BLUE;
 facetid->nedges=4;                         
 facetid->edge[0]=71;                           
 facetid->edge[1]=64;      
 facetid->edge[2]=56;
 facetid->edge[3]=63;
 facetid++;

  //facetid->color=BLUE;        //Landing pad 3
 //facetid->nedges=8; 
 //facetid->edge[0]=72;
 //facetid->edge[1]=73;
 //facetid->edge[2]=74;
 //facetid->edge[3]=75;            
 //facetid->edge[4]=76;
 //facetid->edge[5]=77;
 //facetid->edge[6]=78;
 //facetid->edge[7]=79;
 //facetid++;

 facetid->color=BLUE;
 facetid->nedges=3;                             
 facetid->edge[0]=80;                       
 facetid->edge[1]=81;        
 facetid->edge[2]=884; 
 facetid++;

 facetid->color=BLUE;
 facetid->nedges=3;                             
 facetid->edge[0]=81;                       
 facetid->edge[1]=82;        
 facetid->edge[2]=884; 
 facetid++;
 
 facetid->color=BLUE;
 facetid->nedges=3;                             
 facetid->edge[0]=82;                       
 facetid->edge[1]=83;        
 facetid->edge[2]=884; 
 facetid++;
 
 facetid->color=BLUE;
 facetid->nedges=3;                             
 facetid->edge[0]=83;                       
 facetid->edge[1]=84;        
 facetid->edge[2]=884; 
 facetid++;

 facetid->color=BLUE;
 facetid->nedges=3;                             
 facetid->edge[0]=84;                       
 facetid->edge[1]=85;        
 facetid->edge[2]=884; 
 facetid++;
 
 facetid->color=BLUE;
 facetid->nedges=3;                             
 facetid->edge[0]=85;                       
 facetid->edge[1]=86;        
 facetid->edge[2]=884; 
 facetid++;
 
 facetid->color=BLUE;
 facetid->nedges=3;                             
 facetid->edge[0]=86;                       
 facetid->edge[1]=87;        
 facetid->edge[2]=884; 
 facetid++;

 facetid->color=BLUE;
 facetid->nedges=3;                             
 facetid->edge[0]=87;                       
 facetid->edge[1]=80;        
 facetid->edge[2]=884; 
 facetid++;

 facetid->color=BLUE;
 facetid->nedges=8;
 facetid->edge[0]=87;
 facetid->edge[1]=86;
 facetid->edge[2]=85;
 facetid->edge[3]=84;          
 facetid->edge[4]=83;
 facetid->edge[5]=82;
 facetid->edge[6]=81;
 facetid->edge[7]=80;
 facetid++;

 facetid->color=BLUE;
 facetid->nedges=4;                             
 facetid->edge[0]=72;                       
 facetid->edge[1]=73;        
 facetid->edge[2]=81;  
 facetid->edge[3]=80;
 facetid++;

 facetid->color=BLUE;
 facetid->nedges=4;                        
 facetid->edge[0]=73;                           
 facetid->edge[1]=74;      
 facetid->edge[2]=82;
 facetid->edge[3]=81;
 facetid++;

 facetid->color=BLUE;
 facetid->nedges=4;                             
 facetid->edge[0]=74;                    
 facetid->edge[1]=75;      
 facetid->edge[2]=83;
 facetid->edge[3]=82;
 facetid++;

 facetid->color=BLUE;
 facetid->nedges=4;                        
 facetid->edge[0]=75;                           
 facetid->edge[1]=76;      
 facetid->edge[2]=84;
 facetid->edge[3]=83;
 facetid++;

 facetid->color=BLUE;
 facetid->nedges=4;                     
 facetid->edge[0]=76;                           
 facetid->edge[1]=77;      
 facetid->edge[2]=85;
 facetid->edge[3]=84;
 facetid++;

 facetid->color=BLUE;
 facetid->nedges=4;                     
 facetid->edge[0]=77;                           
 facetid->edge[1]=78;      
 facetid->edge[2]=86;
 facetid->edge[3]=85;
 facetid++;

 facetid->color=BLUE;
 facetid->nedges=4;                             
 facetid->edge[0]=78;                     
 facetid->edge[1]=79;      
 facetid->edge[2]=87;
 facetid->edge[3]=86;
 facetid++;

 facetid->color=BLUE;
 facetid->nedges=4;                          
 facetid->edge[0]=79;                           
 facetid->edge[1]=72;      
 facetid->edge[2]=80;
 facetid->edge[3]=87;
 facetid++;                    

  facetid->color=BLUE;
 facetid->nedges=4;                             
 facetid->edge[0]=80;                    
 facetid->edge[1]=81;      
 facetid->edge[2]=73;
 facetid->edge[3]=72;
 facetid++;

 facetid->color=BLUE;
 facetid->nedges=4;                      
 facetid->edge[0]=81;                           
 facetid->edge[1]=82;      
 facetid->edge[2]=74;
 facetid->edge[3]=73;
 facetid++;

 facetid->color=BLUE;
 facetid->nedges=4;                             
 facetid->edge[0]=82;                       
 facetid->edge[1]=83;     
 facetid->edge[2]=75;
 facetid->edge[3]=74;
 facetid++;

 facetid->color=BLUE;
 facetid->nedges=4;                        
 facetid->edge[0]=83;                        
 facetid->edge[1]=84;    
 facetid->edge[2]=76;
 facetid->edge[3]=75;
 facetid++;

 facetid->color=BLUE;
 facetid->nedges=4;                     
 facetid->edge[0]=84;                          
 facetid->edge[1]=85;     
 facetid->edge[2]=77;
 facetid->edge[3]=76;
 facetid++;

 facetid->color=BLUE;
 facetid->nedges=4;                       
 facetid->edge[0]=85;                        
 facetid->edge[1]=86;    
 facetid->edge[2]=78;
 facetid->edge[3]=77;
 facetid++;

 facetid->color=BLUE;
 facetid->nedges=4;                             
 facetid->edge[0]=86;                       
 facetid->edge[1]=87;      
 facetid->edge[2]=79;
 facetid->edge[3]=78;
 facetid++;

 facetid->color=BLUE;
 facetid->nedges=4;                        
 facetid->edge[0]=87;                           
 facetid->edge[1]=80;      
 facetid->edge[2]=72;
 facetid->edge[3]=79;
 facetid++;

 //facetid->color=BLUE;        //Landing pad 4 
 //facetid->nedges=8; 
 //facetid->edge[0]=88;
 //facetid->edge[1]=89;
 //facetid->edge[2]=90;
 //facetid->edge[3]=91;            
 //facetid->edge[4]=92;
 //facetid->edge[5]=93;
 //facetid->edge[6]=94;
 //facetid->edge[7]=95;
 //facetid++;

 facetid->color=BLUE;
 facetid->nedges=8;
 facetid->edge[0]=103;
 facetid->edge[1]=102;
 facetid->edge[2]=101;
 facetid->edge[3]=100;          
 facetid->edge[4]=99;
 facetid->edge[5]=98;
 facetid->edge[6]=97;
 facetid->edge[7]=96;
 facetid++;

 facetid->color=BLUE;
 facetid->nedges=3;                             
 facetid->edge[0]=96;                        
 facetid->edge[1]=97;        
 facetid->edge[2]=882;  
 facetid++;

 facetid->color=BLUE;
 facetid->nedges=3;                             
 facetid->edge[0]=97;                        
 facetid->edge[1]=98;        
 facetid->edge[2]=882;  
 facetid++;

 facetid->color=BLUE;
 facetid->nedges=3;                             
 facetid->edge[0]=98;                        
 facetid->edge[1]=99;        
 facetid->edge[2]=882;  
 facetid++;

 facetid->color=BLUE;
 facetid->nedges=3;                             
 facetid->edge[0]=99;                        
 facetid->edge[1]=100;        
 facetid->edge[2]=882;  
 facetid++;
  
 facetid->color=BLUE;
 facetid->nedges=3;                             
 facetid->edge[0]=100;                        
 facetid->edge[1]=101;        
 facetid->edge[2]=882;  
 facetid++;

 facetid->color=BLUE;
 facetid->nedges=3;                             
 facetid->edge[0]=101;                        
 facetid->edge[1]=102;        
 facetid->edge[2]=882;  
 facetid++;

 facetid->color=BLUE;
 facetid->nedges=3;                             
 facetid->edge[0]=102;                        
 facetid->edge[1]=103;        
 facetid->edge[2]=882;  
 facetid++;

 facetid->color=BLUE;
 facetid->nedges=3;                             
 facetid->edge[0]=103;                        
 facetid->edge[1]=96;        
 facetid->edge[2]=882;  
 facetid++;

 facetid->color=BLUE;
 facetid->nedges=4;                             
 facetid->edge[0]=88;                        
 facetid->edge[1]=89;        
 facetid->edge[2]=97;  
 facetid->edge[3]=96;
 facetid++;

 facetid->color=BLUE;
 facetid->nedges=4;                     
 facetid->edge[0]=89;                           
 facetid->edge[1]=90;      
 facetid->edge[2]=98;
 facetid->edge[3]=97;
 facetid++;

 facetid->color=BLUE;
 facetid->nedges=4;                             
 facetid->edge[0]=90;                     
 facetid->edge[1]=91;      
 facetid->edge[2]=99;
 facetid->edge[3]=98;
 facetid++;

 facetid->color=BLUE;
 facetid->nedges=4;                           
 facetid->edge[0]=91;                           
 facetid->edge[1]=92;      
 facetid->edge[2]=100;
 facetid->edge[3]=99;
 facetid++;

 facetid->color=BLUE;
 facetid->nedges=4;                       
 facetid->edge[0]=92;                           
 facetid->edge[1]=93;      
 facetid->edge[2]=101;
 facetid->edge[3]=100;
 facetid++;

 facetid->color=BLUE;
 facetid->nedges=4;                     
 facetid->edge[0]=93;                           
 facetid->edge[1]=94;      
 facetid->edge[2]=102;
 facetid->edge[3]=101;
 facetid++;

 facetid->color=BLUE;
 facetid->nedges=4;                             
 facetid->edge[0]=94;                   
 facetid->edge[1]=95;      
 facetid->edge[2]=103;
 facetid->edge[3]=102;
 facetid++;

 facetid->color=BLUE;
 facetid->nedges=4;                       
 facetid->edge[0]=95;                           
 facetid->edge[1]=88;      
 facetid->edge[2]=96;
 facetid->edge[3]=103;
 facetid++;                     

  facetid->color=BLUE;
 facetid->nedges=4;                             
 facetid->edge[0]=96;                      
 facetid->edge[1]=97;      
 facetid->edge[2]=89;
 facetid->edge[3]=88;
 facetid++;

 facetid->color=BLUE;
 facetid->nedges=4;                    
 facetid->edge[0]=97;                           
 facetid->edge[1]=98;      
 facetid->edge[2]=90;
 facetid->edge[3]=89;
 facetid++;

 facetid->color=BLUE;
 facetid->nedges=4;                             
 facetid->edge[0]=98;                 
 facetid->edge[1]=99;     
 facetid->edge[2]=91;
 facetid->edge[3]=90;
 facetid++;

 facetid->color=BLUE;
 facetid->nedges=4;                     
 facetid->edge[0]=99;                        
 facetid->edge[1]=100;    
 facetid->edge[2]=92;
 facetid->edge[3]=91;
 facetid++;

 facetid->color=BLUE;
 facetid->nedges=4;                        
 facetid->edge[0]=100;                          
 facetid->edge[1]=101;     
 facetid->edge[2]=93;
 facetid->edge[3]=92;
 facetid++;

 facetid->color=BLUE;
 facetid->nedges=4;                       
 facetid->edge[0]=101;                        
 facetid->edge[1]=102;    
 facetid->edge[2]=94;
 facetid->edge[3]=93;
 facetid++;

 facetid->color=BLUE;
 facetid->nedges=4;                             
 facetid->edge[0]=102;                   
 facetid->edge[1]=103;      
 facetid->edge[2]=95;
 facetid->edge[3]=94;
 facetid++;

 facetid->color=BLUE;
 facetid->nedges=4;                          
 facetid->edge[0]=103;                           
 facetid->edge[1]=96;      
 facetid->edge[2]=88;
 facetid->edge[3]=95;
 facetid++;

 
 facetid->color=CYAN;        //Decent Engine 
 facetid->nedges=8; 
 facetid->edge[0]=118;
 facetid->edge[1]=119;
 facetid->edge[2]=120;
 facetid->edge[3]=121;            
 facetid->edge[4]=122;
 facetid->edge[5]=123;
 facetid->edge[6]=124;
 facetid->edge[7]=125;
 facetid++;

 facetid->color=CYAN;
 facetid->nedges=8;
 facetid->edge[0]=125;
 facetid->edge[1]=124;
 facetid->edge[2]=123;
 facetid->edge[3]=122;         
 facetid->edge[4]=121;
 facetid->edge[5]=120;
 facetid->edge[6]=119;
 facetid->edge[7]=118;
 facetid++;

 facetid->color=CYAN;
 facetid->nedges=4;                             
 facetid->edge[0]=118;                            
 facetid->edge[1]=119;     
 facetid->edge[2]=127;
 facetid->edge[3]=126;
 facetid++;

 facetid->color=CYAN;
 facetid->nedges=4;                           
 facetid->edge[0]=119;                           
 facetid->edge[1]=120;      
 facetid->edge[2]=128;
 facetid->edge[3]=127;
 facetid++;

 facetid->color=CYAN;
 facetid->nedges=4;                             
 facetid->edge[0]=120;                       
 facetid->edge[1]=121;      
 facetid->edge[2]=129;
 facetid->edge[3]=128;
 facetid++;

 facetid->color=CYAN;
 facetid->nedges=4;                       
 facetid->edge[0]=121;                           
 facetid->edge[1]=122;      
 facetid->edge[2]=130;
 facetid->edge[3]=129;
 facetid++;

 facetid->color=CYAN;
 facetid->nedges=4;                        
 facetid->edge[0]=122;                           
 facetid->edge[1]=123;      
 facetid->edge[2]=131;
 facetid->edge[3]=130;
 facetid++;

 facetid->color=CYAN;
 facetid->nedges=4;                      
 facetid->edge[0]=123;                           
 facetid->edge[1]=124;      
 facetid->edge[2]=132;
 facetid->edge[3]=131;
 facetid++;

 facetid->color=CYAN;
 facetid->nedges=4;                             
 facetid->edge[0]=124;                       
 facetid->edge[1]=125;      
 facetid->edge[2]=133;
 facetid->edge[3]=132;
 facetid++;

 facetid->color=CYAN;
 facetid->nedges=4;                         
 facetid->edge[0]=125;                           
 facetid->edge[1]=118;      
 facetid->edge[2]=126;
 facetid->edge[3]=133;
 facetid++;                     

 facetid->color=CYAN;
 facetid->nedges=4;                             
 facetid->edge[0]=126;                       
 facetid->edge[1]=127;      
 facetid->edge[2]=119;
 facetid->edge[3]=118;
 facetid++;

 facetid->color=CYAN;
 facetid->nedges=4;                         
 facetid->edge[0]=127;                           
 facetid->edge[1]=128;     
 facetid->edge[2]=120;
 facetid->edge[3]=119;
 facetid++;

 facetid->color=CYAN;
 facetid->nedges=4;                             
 facetid->edge[0]=128;                      
 facetid->edge[1]=129;     
 facetid->edge[2]=121;
 facetid->edge[3]=120;
 facetid++;

 facetid->color=CYAN;
 facetid->nedges=4;                       
 facetid->edge[0]=129;                        
 facetid->edge[1]=130;    
 facetid->edge[2]=122;
 facetid->edge[3]=121;
 facetid++;

 facetid->color=CYAN;
 facetid->nedges=4;                     
 facetid->edge[0]=130;                          
 facetid->edge[1]=131;     
 facetid->edge[2]=123;
 facetid->edge[3]=122;
 facetid++;

 facetid->color=CYAN;
 facetid->nedges=4;                       
 facetid->edge[0]=131;                        
 facetid->edge[1]=132;    
 facetid->edge[2]=124;
 facetid->edge[3]=123;
 facetid++;

 facetid->color=CYAN;
 facetid->nedges=4;                             
 facetid->edge[0]=132;                     
 facetid->edge[1]=133;      
 facetid->edge[2]=125;
 facetid->edge[3]=124;
 facetid++;

 facetid->color=CYAN;
 facetid->nedges=4;                         
 facetid->edge[0]=133;                           
 facetid->edge[1]=126;      
 facetid->edge[2]=118;
 facetid->edge[3]=125;
 facetid++;
 
 //facetid->color=WHITE;        //Landing Gear 1 
 //facetid->nedges=8; 
 //facetid->edge[0]=134;
 //facetid->edge[1]=135;
 //facetid->edge[2]=136;
 //facetid->edge[3]=137;            
 //facetid->edge[4]=138;
 //facetid->edge[5]=139;
 //facetid->edge[6]=140;
 //facetid->edge[7]=141;
 //facetid++;

 facetid->color=LIGHTRED;
 facetid->nedges=4;                             
 facetid->edge[0]=134;                          
 facetid->edge[1]=135;        
 facetid->edge[2]=143;  
 facetid->edge[3]=142;
 facetid++;

 facetid->color=LIGHTRED;
 facetid->nedges=4;                        
 facetid->edge[0]=135;                           
 facetid->edge[1]=136;      
 facetid->edge[2]=144;
 facetid->edge[3]=143;
 facetid++;
 
 facetid->color=LIGHTRED;
 facetid->nedges=4;                             
 facetid->edge[0]=136;                    
 facetid->edge[1]=137;      
 facetid->edge[2]=145;
 facetid->edge[3]=144;
 facetid++;

 facetid->color=DARKGREEN;
 facetid->nedges=4;                      
 facetid->edge[0]=137;                           
 facetid->edge[1]=138;      
 facetid->edge[2]=146;
 facetid->edge[3]=145;
 facetid++;

 facetid->color=DARKGREEN;
 facetid->nedges=4;                        
 facetid->edge[0]=138;                           
 facetid->edge[1]=139;      
 facetid->edge[2]=147;
 facetid->edge[3]=146;
 facetid++;

 facetid->color=DARKGREEN;
 facetid->nedges=4;                         
 facetid->edge[0]=139;                           
 facetid->edge[1]=140;      
 facetid->edge[2]=148;
 facetid->edge[3]=147;
 facetid++;

 facetid->color=DARKGREEN;
 facetid->nedges=4;                             
 facetid->edge[0]=140;                        
 facetid->edge[1]=141;      
 facetid->edge[2]=149;
 facetid->edge[3]=148;
 facetid++;

 facetid->color=DARKGREEN;
 facetid->nedges=4;                          
 facetid->edge[0]=141;                           
 facetid->edge[1]=134;      
 facetid->edge[2]=142;
 facetid->edge[3]=149;
 facetid++;                     
  
 //facetid->color=WHITE;        //Landing Gear 2 
 //facetid->nedges=8; 
 //facetid->edge[0]=150;
 //facetid->edge[1]=151;
 //facetid->edge[2]=152;
 //facetid->edge[3]=153;            
 //facetid->edge[4]=154;
 //facetid->edge[5]=155;
 //facetid->edge[6]=156;
 //facetid->edge[7]=157;
 //facetid++;

 facetid->color=DARKGREEN;
 facetid->nedges=4;                             
 facetid->edge[0]=150;                           
 facetid->edge[1]=151;        
 facetid->edge[2]=159; 
 facetid->edge[3]=158;
 facetid++;

 facetid->color=DARKGREEN;
 facetid->nedges=4;                            
 facetid->edge[0]=151;                           
 facetid->edge[1]=152;      
 facetid->edge[2]=160;
 facetid->edge[3]=159;
 facetid++;

 facetid->color=LIGHTRED;
 facetid->nedges=4;                             
 facetid->edge[0]=152;                        
 facetid->edge[1]=153;      
 facetid->edge[2]=161;
 facetid->edge[3]=160;
 facetid++;

 facetid->color=LIGHTRED;
 facetid->nedges=4;                        
 facetid->edge[0]=153;                           
 facetid->edge[1]=154;      
 facetid->edge[2]=162;
 facetid->edge[3]=161;
 facetid++;

 facetid->color=LIGHTRED;
 facetid->nedges=4;                      
 facetid->edge[0]=154;                           
 facetid->edge[1]=155;      
 facetid->edge[2]=163;
 facetid->edge[3]=162;
 facetid++;

 facetid->color=DARKGREEN;
 facetid->nedges=4;                       
 facetid->edge[0]=155;                           
 facetid->edge[1]=156;      
 facetid->edge[2]=164;
 facetid->edge[3]=163;
 facetid++;

 facetid->color=DARKGREEN;
 facetid->nedges=4;                             
 facetid->edge[0]=156;                    
 facetid->edge[1]=157;      
 facetid->edge[2]=165;
 facetid->edge[3]=164;
 facetid++;

 facetid->color=DARKGREEN;
 facetid->nedges=4;                          
 facetid->edge[0]=157;                           
 facetid->edge[1]=150;      
 facetid->edge[2]=158;
 facetid->edge[3]=165;
 facetid++;                    
 
 //facetid->color=WHITE;        //Landing Gear 3
 //facetid->nedges=8; 
 //facetid->edge[0]=166;
 //facetid->edge[1]=167;
 //facetid->edge[2]=168;
 //facetid->edge[3]=169;            
 //facetid->edge[4]=170;
 //facetid->edge[5]=171;
 //facetid->edge[6]=172;
 //facetid->edge[7]=173;
 //facetid++;

 facetid->color=LIGHTRED;
 facetid->nedges=4;                             
 facetid->edge[0]=166;                           
 facetid->edge[1]=167;        
 facetid->edge[2]=175; 
 facetid->edge[3]=174;
 facetid++;

 facetid->color=DARKGREEN;
 facetid->nedges=4;                         
 facetid->edge[0]=167;                           
 facetid->edge[1]=168;      
 facetid->edge[2]=176;
 facetid->edge[3]=175;
 facetid++;

 facetid->color=DARKGREEN;
 facetid->nedges=4;                             
 facetid->edge[0]=168;                    
 facetid->edge[1]=169;      
 facetid->edge[2]=177;
 facetid->edge[3]=176;
 facetid++;

 facetid->color=DARKGREEN;
 facetid->nedges=4;                          
 facetid->edge[0]=169;                           
 facetid->edge[1]=170;      
 facetid->edge[2]=178;
 facetid->edge[3]=177;
 facetid++;

 facetid->color=DARKGREEN;
 facetid->nedges=4;                         
 facetid->edge[0]=170;                           
 facetid->edge[1]=171;      
 facetid->edge[2]=179;
 facetid->edge[3]=178;
 facetid++;

 facetid->color=DARKGREEN;
 facetid->nedges=4;                         
 facetid->edge[0]=171;                           
 facetid->edge[1]=172;      
 facetid->edge[2]=180;
 facetid->edge[3]=179;
 facetid++;

 facetid->color=LIGHTRED;
 facetid->nedges=4;                             
 facetid->edge[0]=172;                       
 facetid->edge[1]=173;      
 facetid->edge[2]=181;
 facetid->edge[3]=180;
 facetid++;

 facetid->color=LIGHTRED;
 facetid->nedges=4;                          
 facetid->edge[0]=173;                           
 facetid->edge[1]=166;      
 facetid->edge[2]=174;
 facetid->edge[3]=181;
 facetid++;                     
 
 //facetid->color=WHITE;        //Landing Gear 4 
 //facetid->nedges=8; 
 //facetid->edge[0]=182;
 //facetid->edge[1]=183;
 //facetid->edge[2]=184;
 //facetid->edge[3]=185;            
 //facetid->edge[4]=186;
 //facetid->edge[5]=187;
 //facetid->edge[6]=188;
 //facetid->edge[7]=189;
 //facetid++;

 facetid->color=DARKGREEN;
 facetid->nedges=4;                             
 facetid->edge[0]=182;                       
 facetid->edge[1]=183;        
 facetid->edge[2]=191; 
 facetid->edge[3]=190;
 facetid++;

 facetid->color=DARKGREEN;
 facetid->nedges=4;                          
 facetid->edge[0]=183;                           
 facetid->edge[1]=184;      
 facetid->edge[2]=192;
 facetid->edge[3]=191;
 facetid++;

 facetid->color=DARKGREEN;
 facetid->nedges=4;                             
 facetid->edge[0]=184;                    
 facetid->edge[1]=185;      
 facetid->edge[2]=193;
 facetid->edge[3]=192;
 facetid++;

 facetid->color=DARKGREEN;
 facetid->nedges=4;                        
 facetid->edge[0]=185;                           
 facetid->edge[1]=186;      
 facetid->edge[2]=194;
 facetid->edge[3]=193;
 facetid++;

 facetid->color=LIGHTRED;
 facetid->nedges=4;                       
 facetid->edge[0]=186;                           
 facetid->edge[1]=187;      
 facetid->edge[2]=195;
 facetid->edge[3]=194;
 facetid++;

 facetid->color=LIGHTRED;
 facetid->nedges=4;                       
 facetid->edge[0]=187;                           
 facetid->edge[1]=188;      
 facetid->edge[2]=196;
 facetid->edge[3]=195;
 facetid++;

 facetid->color=LIGHTRED;
 facetid->nedges=4;                             
 facetid->edge[0]=188;                      
 facetid->edge[1]=189;      
 facetid->edge[2]=197;
 facetid->edge[3]=196;
 facetid++;

 facetid->color=DARKGREEN;
 facetid->nedges=4;                          
 facetid->edge[0]=189;                           
 facetid->edge[1]=182;      
 facetid->edge[2]=190;
 facetid->edge[3]=197;
 facetid++;                    
 
 //facetid->color=WHITE;        //++++++ 1 
 //facetid->nedges=8; 
 //facetid->edge[0]=198;
 //facetid->edge[1]=199;
 //facetid->edge[2]=200;
 //facetid->edge[3]=201;            
 //facetid->edge[4]=202;
 //facetid->edge[5]=203;
 //facetid->edge[6]=204;
 //facetid->edge[7]=205;
 //facetid++;

 facetid->color=DARKGRAY;
 facetid->nedges=4;                             
 facetid->edge[0]=198;                         
 facetid->edge[1]=199;        
 facetid->edge[2]=207; 
 facetid->edge[3]=206;
 facetid++;

 facetid->color=DARKGRAY;
 facetid->nedges=4;                         
 facetid->edge[0]=199;                           
 facetid->edge[1]=200;      
 facetid->edge[2]=208;
 facetid->edge[3]=207;
 facetid++;

 facetid->color=DARKGRAY;
 facetid->nedges=4;                             
 facetid->edge[0]=200;                       
 facetid->edge[1]=201;      
 facetid->edge[2]=209;
 facetid->edge[3]=208;
 facetid++;

 facetid->color=DARKGRAY;
 facetid->nedges=4;                       
 facetid->edge[0]=201;                           
 facetid->edge[1]=202;      
 facetid->edge[2]=210;
 facetid->edge[3]=209;
 facetid++;

 facetid->color=DARKGRAY;
 facetid->nedges=4;                         
 facetid->edge[0]=202;                           
 facetid->edge[1]=203;      
 facetid->edge[2]=211;
 facetid->edge[3]=210;
 facetid++;

 facetid->color=DARKGRAY;
 facetid->nedges=4;                      
 facetid->edge[0]=203;                           
 facetid->edge[1]=204;      
 facetid->edge[2]=212;
 facetid->edge[3]=211;
 facetid++;

 facetid->color=DARKGRAY;
 facetid->nedges=4;                             
 facetid->edge[0]=204;                         
 facetid->edge[1]=205;      
 facetid->edge[2]=213;
 facetid->edge[3]=212;
 facetid++;

 facetid->color=DARKGRAY;
 facetid->nedges=4;                          
 facetid->edge[0]=205;                           
 facetid->edge[1]=198;      
 facetid->edge[2]=206;
 facetid->edge[3]=213;
 facetid++;                     
 
 //facetid->color=WHITE;        //++++++ 2
 //facetid->nedges=8; 
 //facetid->edge[0]=214;
 //facetid->edge[1]=215;
 //facetid->edge[2]=216;
 //facetid->edge[3]=217;            
 //facetid->edge[4]=218;
 //facetid->edge[5]=219;
 //facetid->edge[6]=220;
 //facetid->edge[7]=221;
 //facetid++;

 facetid->color=DARKGRAY;
 facetid->nedges=4;                             
 facetid->edge[0]=214;                           
 facetid->edge[1]=215;        
 facetid->edge[2]=223; 
 facetid->edge[3]=222;
 facetid++;

 facetid->color=DARKGRAY;
 facetid->nedges=4;                        
 facetid->edge[0]=215;                           
 facetid->edge[1]=216;      
 facetid->edge[2]=224;
 facetid->edge[3]=223;
 facetid++;

 facetid->color=DARKGRAY;
 facetid->nedges=4;                             
 facetid->edge[0]=216;                        
 facetid->edge[1]=217;      
 facetid->edge[2]=225;
 facetid->edge[3]=224;
 facetid++;

 facetid->color=DARKGRAY;
 facetid->nedges=4;                          
 facetid->edge[0]=217;                           
 facetid->edge[1]=218;      
 facetid->edge[2]=226;
 facetid->edge[3]=225;
 facetid++;

 facetid->color=DARKGRAY;
 facetid->nedges=4;                       
 facetid->edge[0]=218;                           
 facetid->edge[1]=219;      
 facetid->edge[2]=227;
 facetid->edge[3]=226;
 facetid++;

 facetid->color=DARKGRAY;
 facetid->nedges=4;                       
 facetid->edge[0]=219;                           
 facetid->edge[1]=220;      
 facetid->edge[2]=228;
 facetid->edge[3]=227;
 facetid++;

 facetid->color=DARKGRAY;
 facetid->nedges=4;                             
 facetid->edge[0]=220;                      
 facetid->edge[1]=221;      
 facetid->edge[2]=229;
 facetid->edge[3]=228;
 facetid++;

 facetid->color=DARKGRAY;
 facetid->nedges=4;                            
 facetid->edge[0]=221;                           
 facetid->edge[1]=214;      
 facetid->edge[2]=222;
 facetid->edge[3]=229;
 facetid++;                     
 
 //facetid->color=WHITE;        //++++++ 3 
 //facetid->nedges=8; 
 //facetid->edge[0]=230;
 //facetid->edge[1]=231;
 //facetid->edge[2]=232;
 //facetid->edge[3]=233;            
 //facetid->edge[4]=234;
 //facetid->edge[5]=235;
 //facetid->edge[6]=236;
 //facetid->edge[7]=237;
 //facetid++;

 facetid->color=DARKGRAY;
 facetid->nedges=4;                             
 facetid->edge[0]=238;                          
 facetid->edge[1]=239;        
 facetid->edge[2]=231; 
 facetid->edge[3]=230;
 facetid++;

 facetid->color=DARKGRAY;
 facetid->nedges=4;                         
 facetid->edge[0]=239;                           
 facetid->edge[1]=240;      
 facetid->edge[2]=232;
 facetid->edge[3]=231;
 facetid++;

 facetid->color=DARKGRAY;
 facetid->nedges=4;                             
 facetid->edge[0]=240;                        
 facetid->edge[1]=241;      
 facetid->edge[2]=233;
 facetid->edge[3]=232;
 facetid++;

 facetid->color=DARKGRAY;
 facetid->nedges=4;                           
 facetid->edge[0]=241;                           
 facetid->edge[1]=242;     
 facetid->edge[2]=234;
 facetid->edge[3]=233;
 facetid++;

 facetid->color=DARKGRAY;
 facetid->nedges=4;                        
 facetid->edge[0]=242;                           
 facetid->edge[1]=243;      
 facetid->edge[2]=235;
 facetid->edge[3]=234;
 facetid++;

 facetid->color=DARKGRAY;
 facetid->nedges=4;                         
 facetid->edge[0]=243;                           
 facetid->edge[1]=244;      
 facetid->edge[2]=236;
 facetid->edge[3]=235;
 facetid++;

 facetid->color=DARKGRAY;
 facetid->nedges=4;                             
 facetid->edge[0]=244;                      
 facetid->edge[1]=245;      
 facetid->edge[2]=237;
 facetid->edge[3]=236;
 facetid++;

 facetid->color=DARKGRAY;
 facetid->nedges=4;                           
 facetid->edge[0]=245;                           
 facetid->edge[1]=238;      
 facetid->edge[2]=230;
 facetid->edge[3]=237;
 facetid++;                    
 
 //facetid->color=WHITE;        //+++++ 4 5 
 //facetid->nedges=8; 
 //facetid->edge[0]=246;
 //facetid->edge[1]=247;
 //facetid->edge[2]=248;
 //facetid->edge[3]=249;            
 //facetid->edge[4]=250;
 //facetid->edge[5]=251;
 //facetid->edge[6]=252;
 //facetid->edge[7]=253;
 //facetid++;

 facetid->color=DARKGRAY;
 facetid->nedges=4;                             
 facetid->edge[0]=254;                          
 facetid->edge[1]=255;        
 facetid->edge[2]=247; 
 facetid->edge[3]=246;
 facetid++;

 facetid->color=DARKGRAY;
 facetid->nedges=4;                       
 facetid->edge[0]=255;                           
 facetid->edge[1]=256;      
 facetid->edge[2]=248;
 facetid->edge[3]=247;
 facetid++;

 facetid->color=DARKGRAY;
 facetid->nedges=4;                             
 facetid->edge[0]=256;                      
 facetid->edge[1]=257;      
 facetid->edge[2]=249;
 facetid->edge[3]=248;
 facetid++;

 facetid->color=DARKGRAY;
 facetid->nedges=4;                       
 facetid->edge[0]=257;                           
 facetid->edge[1]=258;     
 facetid->edge[2]=250;
 facetid->edge[3]=249;
 facetid++;

facetid->color=DARKGRAY;
 facetid->nedges=4;                       
 facetid->edge[0]=258;                          
 facetid->edge[1]=259;      
 facetid->edge[2]=251;
 facetid->edge[3]=250;
 facetid++;

 facetid->color=DARKGRAY;
 facetid->nedges=4;                         
 facetid->edge[0]=259;                           
 facetid->edge[1]=260;      
 facetid->edge[2]=252;
 facetid->edge[3]=251;
 facetid++;

 facetid->color=DARKGRAY;
 facetid->nedges=4;                             
 facetid->edge[0]=260;                     
 facetid->edge[1]=261;      
 facetid->edge[2]=253;
 facetid->edge[3]=252;
 facetid++;

 facetid->color=DARKGRAY;
 facetid->nedges=4;                           
 facetid->edge[0]=261;//261                           
 facetid->edge[1]=254;//254      
 facetid->edge[2]=246;//246
 facetid->edge[3]=253;//253
 facetid++;                     
 
 //facetid->color=WHITE;        //++++++ 5  
 //facetid->nedges=8; 
 //facetid->edge[0]=262;
 //facetid->edge[1]=263;
 //facetid->edge[2]=264;
 //facetid->edge[3]=265;            
 //facetid->edge[4]=266;
 //facetid->edge[5]=267;
 //facetid->edge[6]=268;
 //facetid->edge[7]=269;
 //facetid++;

 facetid->color=DARKGRAY;
 facetid->nedges=4;                             
 facetid->edge[0]=270;                       
 facetid->edge[1]=271;        
 facetid->edge[2]=263; 
 facetid->edge[3]=262;
 facetid++;

 facetid->color=DARKGRAY;
 facetid->nedges=4;                          
 facetid->edge[0]=271;                           
 facetid->edge[1]=272;      
 facetid->edge[2]=264;
 facetid->edge[3]=263;
 facetid++;

 facetid->color=DARKGRAY;
 facetid->nedges=4;                             
 facetid->edge[0]=272;                      
 facetid->edge[1]=273;      
 facetid->edge[2]=265;
 facetid->edge[3]=264;
 facetid++;

 facetid->color=DARKGRAY;
 facetid->nedges=4;                         
 facetid->edge[0]=273;                           
 facetid->edge[1]=274;     
 facetid->edge[2]=266;
 facetid->edge[3]=265;
 facetid++;

facetid->color=DARKGRAY;
 facetid->nedges=4;                        
 facetid->edge[0]=274;                          
 facetid->edge[1]=275;      
 facetid->edge[2]=267;
 facetid->edge[3]=266;
 facetid++;

 facetid->color=DARKGRAY;
 facetid->nedges=4;                         
 facetid->edge[0]=275;                           
 facetid->edge[1]=276;      
 facetid->edge[2]=268;
 facetid->edge[3]=267;
 facetid++;

 facetid->color=DARKGRAY;
 facetid->nedges=4;                             
 facetid->edge[0]=276;                        
 facetid->edge[1]=277;      
 facetid->edge[2]=269;
 facetid->edge[3]=268;
 facetid++;

 facetid->color=DARKGRAY;
 facetid->nedges=4;                            
 facetid->edge[0]=277;                           
 facetid->edge[1]=270;      
 facetid->edge[2]=262;
 facetid->edge[3]=269;
 facetid++;                     

 //facetid->color=WHITE;        //++++++ 6 
 //facetid->nedges=8; 
 //facetid->edge[0]=278;
 //facetid->edge[1]=279;
 //facetid->edge[2]=280;
 //facetid->edge[3]=281;            
 //facetid->edge[4]=282;
 //facetid->edge[5]=283;
 //facetid->edge[6]=284;
 //facetid->edge[7]=285;
 //facetid++;

 facetid->color=DARKGRAY;
 facetid->nedges=4;                             
 facetid->edge[0]=286;                          
 facetid->edge[1]=287;        
 facetid->edge[2]=279; 
 facetid->edge[3]=278;
 facetid++;

 facetid->color=DARKGRAY;
 facetid->nedges=4;                          
 facetid->edge[0]=287;                           
 facetid->edge[1]=288;      
 facetid->edge[2]=280;
 facetid->edge[3]=279;
 facetid++;

 facetid->color=DARKGRAY;
 facetid->nedges=4;                             
 facetid->edge[0]=288;                       
 facetid->edge[1]=289;      
 facetid->edge[2]=281;
 facetid->edge[3]=280;
 facetid++;

 facetid->color=DARKGRAY;
 facetid->nedges=4;                             
 facetid->edge[0]=289;                  
 facetid->edge[1]=290;     
 facetid->edge[2]=282;
 facetid->edge[3]=281;
 facetid++;

facetid->color=DARKGRAY;
 facetid->nedges=4;                            
 facetid->edge[0]=290;              
 facetid->edge[1]=291;      
 facetid->edge[2]=283;
 facetid->edge[3]=282;
 facetid++;

 facetid->color=DARKGRAY;
 facetid->nedges=4;                  
 facetid->edge[0]=291;                      
 facetid->edge[1]=292;      
 facetid->edge[2]=284;
 facetid->edge[3]=283;
 facetid++;

 facetid->color=DARKGRAY;
 facetid->nedges=4;                             
 facetid->edge[0]=292;                          
 facetid->edge[1]=293;      
 facetid->edge[2]=285;
 facetid->edge[3]=284;
 facetid++;

 facetid->color=DARKGRAY;
 facetid->nedges=4;                          
 facetid->edge[0]=293;         
 facetid->edge[1]=286;      
 facetid->edge[2]=278;
 facetid->edge[3]=285;
 facetid++;                     

 //facetid->color=WHITE;        //++++++ 7  
 //facetid->nedges=8; 
 //facetid->edge[0]=301;
 //facetid->edge[1]=300;
 //facetid->edge[2]=299;
 //facetid->edge[3]=298;            
 //facetid->edge[4]=297;
 //facetid->edge[5]=296;
 //facetid->edge[6]=295;
 //facetid->edge[7]=294;
 //facetid++;

 facetid->color=DARKGRAY;
 facetid->nedges=4;                             
 facetid->edge[0]=294;                            
 facetid->edge[1]=295;      
 facetid->edge[2]=303; 
 facetid->edge[3]=302;
 facetid++;

 facetid->color=DARKGRAY;
 facetid->nedges=4;                            
 facetid->edge[0]=295;                        
 facetid->edge[1]=296;      
 facetid->edge[2]=304;
 facetid->edge[3]=303;
 facetid++;

 facetid->color=DARKGRAY;
 facetid->nedges=4;                             
 facetid->edge[0]=296;               
 facetid->edge[1]=297;      
 facetid->edge[2]=305;
 facetid->edge[3]=304;
 facetid++;

 facetid->color=DARKGRAY;
 facetid->nedges=4;                        
 facetid->edge[0]=297;                     
 facetid->edge[1]=298;    
 facetid->edge[2]=306;
 facetid->edge[3]=305;
 facetid++;

facetid->color=DARKGRAY;
 facetid->nedges=4;                     
 facetid->edge[0]=298;                     
 facetid->edge[1]=299;     
 facetid->edge[2]=307;
 facetid->edge[3]=306;
 facetid++;

 facetid->color=DARKGRAY;
 facetid->nedges=4;              
 facetid->edge[0]=299;                          
 facetid->edge[1]=300;      
 facetid->edge[2]=308;
 facetid->edge[3]=307;
 facetid++;

 facetid->color=DARKGRAY;
 facetid->nedges=4;                             
 facetid->edge[0]=300;          
 facetid->edge[1]=301;     
 facetid->edge[2]=309;
 facetid->edge[3]=308;
 facetid++;

 facetid->color=DARKGRAY;
 facetid->nedges=4;          
 facetid->edge[0]=301;                         
 facetid->edge[1]=294;     
 facetid->edge[2]=302;
 facetid->edge[3]=309;
 facetid++;                     

  //facetid->color=WHITE;        //++++++ 8 3 
 //facetid->nedges=8; 
 //facetid->edge[0]=310;
 //facetid->edge[1]=311;
 //facetid->edge[2]=312;
 //facetid->edge[3]=313;            
 //facetid->edge[4]=314;
 //facetid->edge[5]=315;
 //facetid->edge[6]=316;
 //facetid->edge[7]=317;
 //facetid++;

 facetid->color=DARKGRAY;
 facetid->nedges=4;                             
 facetid->edge[0]=310;                   
 facetid->edge[1]=311;        
 facetid->edge[2]=319; 
 facetid->edge[3]=318;
 facetid++;

 facetid->color=DARKGRAY;
 facetid->nedges=4;                             
 facetid->edge[0]=311;                        
 facetid->edge[1]=312;      
 facetid->edge[2]=320;
 facetid->edge[3]=319;
 facetid++;

 facetid->color=DARKGRAY;
 facetid->nedges=4;                             
 facetid->edge[0]=312;              
 facetid->edge[1]=313;      
 facetid->edge[2]=321;
 facetid->edge[3]=320;
 facetid++;

 facetid->color=DARKGRAY;
 facetid->nedges=4;                          
 facetid->edge[0]=313;                    
 facetid->edge[1]=314;     
 facetid->edge[2]=322;
 facetid->edge[3]=321;
 facetid++;

facetid->color=DARKGRAY;
 facetid->nedges=4;                           
 facetid->edge[0]=314;               
 facetid->edge[1]=315;      
 facetid->edge[2]=323;
 facetid->edge[3]=322;
 facetid++;

 facetid->color=DARKGRAY;
 facetid->nedges=4;                
 facetid->edge[0]=315;                        
 facetid->edge[1]=316;     
 facetid->edge[2]=324;
 facetid->edge[3]=323;
 facetid++;

 facetid->color=DARKGRAY;
 facetid->nedges=4;                             
 facetid->edge[0]=316;  
 facetid->edge[1]=317;     
 facetid->edge[2]=325;
 facetid->edge[3]=324;
 facetid++;

 facetid->color=DARKGRAY;
 facetid->nedges=4;          
 facetid->edge[0]=317;                         
 facetid->edge[1]=310;     
 facetid->edge[2]=318;
 facetid->edge[3]=325;
 facetid++;                     

 //facetid->color=WHITE;        //++++++ 1' 
 //facetid->nedges=8; 
 //facetid->edge[0]=326;
 //facetid->edge[1]=327;
 //facetid->edge[2]=328;
 //facetid->edge[3]=329;            
 //facetid->edge[4]=330;
 //facetid->edge[5]=331;
 //facetid->edge[6]=332;
 //facetid->edge[7]=333;
 //facetid++;

 facetid->color=DARKGRAY;
 facetid->nedges=4;                             
 facetid->edge[0]=326;                            
 facetid->edge[1]=327;       
 facetid->edge[2]=335; 
 facetid->edge[3]=334;
 facetid++;

 facetid->color=DARKGRAY;
 facetid->nedges=4;                            
 facetid->edge[0]=327;                           
 facetid->edge[1]=328;      
 facetid->edge[2]=336;
 facetid->edge[3]=335;
 facetid++;

 facetid->color=DARKGRAY;
 facetid->nedges=4;                             
 facetid->edge[0]=328;                          
 facetid->edge[1]=329;      
 facetid->edge[2]=337;
 facetid->edge[3]=336;
 facetid++;

 facetid->color=DARKGRAY;
 facetid->nedges=4;                          
 facetid->edge[0]=329;                           
 facetid->edge[1]=330;      
 facetid->edge[2]=338;
 facetid->edge[3]=337;
 facetid++;

 facetid->color=DARKGRAY;
 facetid->nedges=4;                       
 facetid->edge[0]=330;                           
 facetid->edge[1]=331;      
 facetid->edge[2]=339;
 facetid->edge[3]=338;
 facetid++;

 facetid->color=DARKGRAY;
 facetid->nedges=4;                          
 facetid->edge[0]=331;                           
 facetid->edge[1]=332;      
 facetid->edge[2]=340;
 facetid->edge[3]=339;
 facetid++;

 facetid->color=DARKGRAY;
 facetid->nedges=4;                             
 facetid->edge[0]=332;                      
 facetid->edge[1]=333;      
 facetid->edge[2]=341;
 facetid->edge[3]=340;
 facetid++;

 facetid->color=DARKGRAY;
 facetid->nedges=4;                      
 facetid->edge[0]=333;//205                           
 facetid->edge[1]=326;//198      
 facetid->edge[2]=334;//206
 facetid->edge[3]=341;//213
 facetid++;                     
 
 //facetid->color=WHITE;        //++++++ 2' 
 //facetid->nedges=8; 
 //facetid->edge[0]=342;
 //facetid->edge[1]=343;
 //facetid->edge[2]=344;
 //facetid->edge[3]=345;            
 //facetid->edge[4]=346;
 //facetid->edge[5]=347;
 //facetid->edge[6]=348;
 //facetid->edge[7]=349;
 //facetid++;

 facetid->color=DARKGRAY;
 facetid->nedges=4;                             
 facetid->edge[0]=342;                   
 facetid->edge[1]=343;        
 facetid->edge[2]=351; 
 facetid->edge[3]=350;
 facetid++;

 facetid->color=DARKGRAY;
 facetid->nedges=4;                            
 facetid->edge[0]=343;                        
 facetid->edge[1]=344;      
 facetid->edge[2]=352;
 facetid->edge[3]=351;
 facetid++;

 facetid->color=DARKGRAY;
 facetid->nedges=4;                             
 facetid->edge[0]=344;                           
 facetid->edge[1]=345;      
 facetid->edge[2]=353;
 facetid->edge[3]=352;
 facetid++;

 facetid->color=DARKGRAY;
 facetid->nedges=4;                         
 facetid->edge[0]=345;                           
 facetid->edge[1]=346;      
 facetid->edge[2]=354;
 facetid->edge[3]=353;
 facetid++;

 facetid->color=DARKGRAY;
 facetid->nedges=4;                       
 facetid->edge[0]=346;                           
 facetid->edge[1]=347;      
 facetid->edge[2]=355;
 facetid->edge[3]=354;
 facetid++;

 facetid->color=DARKGRAY;
 facetid->nedges=4;                         
 facetid->edge[0]=347;                           
 facetid->edge[1]=348;      
 facetid->edge[2]=356;
 facetid->edge[3]=355;
 facetid++;

 facetid->color=DARKGRAY;
 facetid->nedges=4;                             
 facetid->edge[0]=348;                          
 facetid->edge[1]=349;      
 facetid->edge[2]=357;
 facetid->edge[3]=356;
 facetid++;

 facetid->color=DARKGRAY;
 facetid->nedges=4;                        
 facetid->edge[0]=349;                           
 facetid->edge[1]=342;      
 facetid->edge[2]=350;
 facetid->edge[3]=357;
 facetid++;                     
 
 //facetid->color=WHITE;        //++++++ 3'
 //facetid->nedges=8; 
 //facetid->edge[0]=358;
 //facetid->edge[1]=359;
 //facetid->edge[2]=360;
 //facetid->edge[3]=361;            
 //facetid->edge[4]=362;
 //facetid->edge[5]=363;
 //facetid->edge[6]=364;
 //facetid->edge[7]=365;
 //facetid++;

 facetid->color=DARKGRAY;
 facetid->nedges=4;                             
 facetid->edge[0]=366;                    
 facetid->edge[1]=367;        
 facetid->edge[2]=359; 
 facetid->edge[3]=358;
 facetid++;

 facetid->color=DARKGRAY;
 facetid->nedges=4;                             
 facetid->edge[0]=367;                       
 facetid->edge[1]=368;      
 facetid->edge[2]=360;
 facetid->edge[3]=359;
 facetid++;

 facetid->color=DARKGRAY;
 facetid->nedges=4;                             
 facetid->edge[0]=368;                
 facetid->edge[1]=369;      
 facetid->edge[2]=361;
 facetid->edge[3]=360;
 facetid++;

 facetid->color=DARKGRAY;
 facetid->nedges=4;                          
 facetid->edge[0]=369;                    
 facetid->edge[1]=370;      
 facetid->edge[2]=362;
 facetid->edge[3]=361;
 facetid++;

 facetid->color=DARKGRAY;
 facetid->nedges=4;                         
 facetid->edge[0]=370;                  
 facetid->edge[1]=371;      
 facetid->edge[2]=363;
 facetid->edge[3]=362;
 facetid++;

 facetid->color=DARKGRAY;
 facetid->nedges=4;                
 facetid->edge[0]=371;                        
 facetid->edge[1]=372;      
 facetid->edge[2]=364;
 facetid->edge[3]=363;
 facetid++;

 facetid->color=DARKGRAY;
 facetid->nedges=4;                             
 facetid->edge[0]=372;           
 facetid->edge[1]=373;    
 facetid->edge[2]=365;
 facetid->edge[3]=364;
 facetid++;

 facetid->color=DARKGRAY;
 facetid->nedges=4;                         
 facetid->edge[0]=373;          
 facetid->edge[1]=366;      
 facetid->edge[2]=358;
 facetid->edge[3]=365;
 facetid++;                     
 
 //facetid->color=WHITE;        //+++++ 4' 
 //facetid->nedges=8; 
 //facetid->edge[0]=374;
 //facetid->edge[1]=375;
 //facetid->edge[2]=376;
 //facetid->edge[3]=377;            
 //facetid->edge[4]=378;
 //facetid->edge[5]=379;
 //facetid->edge[6]=380;
 //facetid->edge[7]=381;
 //facetid++;

 facetid->color=DARKGRAY;
 facetid->nedges=4;                             
 facetid->edge[0]=382;                     
 facetid->edge[1]=383;        
 facetid->edge[2]=375; 
 facetid->edge[3]=374;
 facetid++;

 facetid->color=DARKGRAY;
 facetid->nedges=4;                       
 facetid->edge[0]=383;                           
 facetid->edge[1]=384;      
 facetid->edge[2]=376;
 facetid->edge[3]=375;
 facetid++;

 facetid->color=DARKGRAY;
 facetid->nedges=4;                             
 facetid->edge[0]=384;              
 facetid->edge[1]=385;    
 facetid->edge[2]=377;
 facetid->edge[3]=376;
 facetid++;

 facetid->color=DARKGRAY;
 facetid->nedges=4;                            
 facetid->edge[0]=385;                  
 facetid->edge[1]=386;      
 facetid->edge[2]=378;
 facetid->edge[3]=377;
 facetid++;

 facetid->color=DARKGRAY;
 facetid->nedges=4;               
 facetid->edge[0]=386;                           
 facetid->edge[1]=387;      
 facetid->edge[2]=379;
 facetid->edge[3]=378;
 facetid++;

 facetid->color=DARKGRAY;
 facetid->nedges=4;                
 facetid->edge[0]=387;                        
 facetid->edge[1]=388;    
 facetid->edge[2]=380;
 facetid->edge[3]=379;
 facetid++;

 facetid->color=DARKGRAY;
 facetid->nedges=4;                             
 facetid->edge[0]=388;           
 facetid->edge[1]=389;  
 facetid->edge[2]=381;
 facetid->edge[3]=380;
 facetid++;

 facetid->color=DARKGRAY;
 facetid->nedges=4;         
 facetid->edge[0]=389;                          
 facetid->edge[1]=382;     
 facetid->edge[2]=374;
 facetid->edge[3]=381;
 facetid++;                     
 
 //facetid->color=WHITE;        //++++++ 5' 
 //facetid->nedges=8; 
 //facetid->edge[0]=390;
 //facetid->edge[1]=391;
 //facetid->edge[2]=392;
 //facetid->edge[3]=393;            
 //facetid->edge[4]=394;
 //facetid->edge[5]=395;
 //facetid->edge[6]=396;
 //facetid->edge[7]=397;
 //facetid++;

 facetid->color=DARKGRAY;
 facetid->nedges=4;                             
 facetid->edge[0]=398;                      
 facetid->edge[1]=399;        
 facetid->edge[2]=391; 
 facetid->edge[3]=390;
 facetid++;

 facetid->color=DARKGRAY;
 facetid->nedges=4;                         
 facetid->edge[0]=399;                           
 facetid->edge[1]=400;      
 facetid->edge[2]=392;
 facetid->edge[3]=391;
 facetid++;

 facetid->color=DARKGRAY;
 facetid->nedges=4;                             
 facetid->edge[0]=400;                      
 facetid->edge[1]=401;      
 facetid->edge[2]=393;
 facetid->edge[3]=392;
 facetid++;

 facetid->color=DARKGRAY;
 facetid->nedges=4;                      
 facetid->edge[0]=401;                          
 facetid->edge[1]=402;      
 facetid->edge[2]=394;
 facetid->edge[3]=393;
 facetid++;

 facetid->color=DARKGRAY;
 facetid->nedges=4;                       
 facetid->edge[0]=402;                           
 facetid->edge[1]=403;      
 facetid->edge[2]=395;
 facetid->edge[3]=394;
 facetid++;

 facetid->color=DARKGRAY;
 facetid->nedges=4;                          
 facetid->edge[0]=403;                           
 facetid->edge[1]=404;      
 facetid->edge[2]=396;
 facetid->edge[3]=395;
 facetid++;

 facetid->color=DARKGRAY;
 facetid->nedges=4;                             
 facetid->edge[0]=404;                       
 facetid->edge[1]=405;      
 facetid->edge[2]=397;
 facetid->edge[3]=396;
 facetid++;

 facetid->color=DARKGRAY;
 facetid->nedges=4;                          
 facetid->edge[0]=405;                           
 facetid->edge[1]=398;      
 facetid->edge[2]=390;
 facetid->edge[3]=397;
 facetid++;                     
 
 //facetid->color=WHITE;        //++++++ 6' 
 //facetid->nedges=8; 
 //facetid->edge[0]=406;
 //facetid->edge[1]=407;
 //facetid->edge[2]=408;
 //facetid->edge[3]=409;            
 //facetid->edge[4]=410;
 //facetid->edge[5]=411;
 //facetid->edge[6]=412;
 //facetid->edge[7]=413;
 //facetid++;

 facetid->color=DARKGRAY;
 facetid->nedges=4;                             
 facetid->edge[0]=414;                            
 facetid->edge[1]=415;        
 facetid->edge[2]=407; 
 facetid->edge[3]=406;
 facetid++;

 facetid->color=DARKGRAY;
 facetid->nedges=4;                            
 facetid->edge[0]=415;                           
 facetid->edge[1]=416;      
 facetid->edge[2]=408;
 facetid->edge[3]=407;
 facetid++;

 facetid->color=DARKGRAY;
 facetid->nedges=4;                             
 facetid->edge[0]=416;                       
 facetid->edge[1]=417;      
 facetid->edge[2]=409;
 facetid->edge[3]=408;
 facetid++;

 facetid->color=DARKGRAY;
 facetid->nedges=4;                      
 facetid->edge[0]=417;                           
 facetid->edge[1]=418;      
 facetid->edge[2]=410;
 facetid->edge[3]=409;
 facetid++;

 facetid->color=DARKGRAY;
 facetid->nedges=4;                        
 facetid->edge[0]=418;                           
 facetid->edge[1]=419;      
 facetid->edge[2]=411;
 facetid->edge[3]=410;
 facetid++;

 facetid->color=DARKGRAY;
 facetid->nedges=4;                          
 facetid->edge[0]=419;                           
 facetid->edge[1]=420;    
 facetid->edge[2]=412;
 facetid->edge[3]=411;
 facetid++;

 facetid->color=DARKGRAY;
 facetid->nedges=4;                             
 facetid->edge[0]=420;                       
 facetid->edge[1]=421;    
 facetid->edge[2]=413;
 facetid->edge[3]=412;
 facetid++;

 facetid->color=DARKGRAY;
 facetid->nedges=4;                         
 facetid->edge[0]=421;                           
 facetid->edge[1]=414;      
 facetid->edge[2]=406;
 facetid->edge[3]=413;
 facetid++;                     
 
 //facetid->color=WHITE;  //+++++ 7'
 //facetid->nedges=8; 
 //facetid->edge[0]=422;
 //facetid->edge[1]=423;
 //facetid->edge[2]=424;
 //facetid->edge[3]=425;            
 //facetid->edge[4]=426;
 //facetid->edge[5]=427;
 //facetid->edge[6]=428;
 //facetid->edge[7]=429;
 //facetid++;

 facetid->color=DARKGRAY ;
 facetid->nedges=4;                             
 facetid->edge[0]=422;                        
 facetid->edge[1]=423;        
 facetid->edge[2]=431; 
 facetid->edge[3]=430;
 facetid++;

 facetid->color=DARKGRAY;
 facetid->nedges=4;                          
 facetid->edge[0]=423;                           
 facetid->edge[1]=424;      
 facetid->edge[2]=432;
 facetid->edge[3]=431;
 facetid++;

 facetid->color=DARKGRAY;
 facetid->nedges=4;                             
 facetid->edge[0]=424;                      
 facetid->edge[1]=425;      
 facetid->edge[2]=433;
 facetid->edge[3]=432;
 facetid++;

 facetid->color=DARKGRAY;
 facetid->nedges=4;                      
 facetid->edge[0]=425;                           
 facetid->edge[1]=426;     
 facetid->edge[2]=434;
 facetid->edge[3]=433;
 facetid++;

facetid->color=DARKGRAY;
 facetid->nedges=4;                         
 facetid->edge[0]=426;                          
 facetid->edge[1]=427;      
 facetid->edge[2]=435;
 facetid->edge[3]=434;
 facetid++;

 facetid->color=DARKGRAY;
 facetid->nedges=4;                      
 facetid->edge[0]=427;                           
 facetid->edge[1]=428;      
 facetid->edge[2]=436;
 facetid->edge[3]=435;
 facetid++;

 facetid->color=DARKGRAY;
 facetid->nedges=4;                             
 facetid->edge[0]=428;                      
 facetid->edge[1]=429;      
 facetid->edge[2]=437;
 facetid->edge[3]=436;
 facetid++;

 facetid->color=DARKGRAY;
 facetid->nedges=4;                          
 facetid->edge[0]=429;                           
 facetid->edge[1]=422;      
 facetid->edge[2]=430;
 facetid->edge[3]=437;
 facetid++;                     

 //facetid->color=WHITE;        //++++++ 8'
 //facetid->nedges=8; 
 //facetid->edge[0]=438;
 //facetid->edge[1]=439;
 //facetid->edge[2]=440;
 //facetid->edge[3]=441;            
 //facetid->edge[4]=442;
 //facetid->edge[5]=443;
 //facetid->edge[6]=444;
 //facetid->edge[7]=445;
 //facetid++;

 facetid->color=DARKGRAY;
 facetid->nedges=4;                             
 facetid->edge[0]=438;                        
 facetid->edge[1]=439;        
 facetid->edge[2]=447; 
 facetid->edge[3]=446;
 facetid++;

 facetid->color=DARKGRAY;
 facetid->nedges=4;                          
 facetid->edge[0]=439;                           
 facetid->edge[1]=440;      
 facetid->edge[2]=448;
 facetid->edge[3]=447;
 facetid++;

 facetid->color=DARKGRAY;
 facetid->nedges=4;                             
 facetid->edge[0]=440;                       
 facetid->edge[1]=441;      
 facetid->edge[2]=449;
 facetid->edge[3]=448;
 facetid++;

 facetid->color=DARKGRAY;
 facetid->nedges=4;                          
 facetid->edge[0]=441;                           
 facetid->edge[1]=442;     
 facetid->edge[2]=450;
 facetid->edge[3]=449;
 facetid++;

facetid->color=DARKGRAY;
 facetid->nedges=4;                          
 facetid->edge[0]=442;                          
 facetid->edge[1]=443;      
 facetid->edge[2]=451;
 facetid->edge[3]=450;
 facetid++;

 facetid->color=DARKGRAY;
 facetid->nedges=4;                         
 facetid->edge[0]=443;                           
 facetid->edge[1]=444;      
 facetid->edge[2]=452;
 facetid->edge[3]=451;
 facetid++;

 facetid->color=DARKGRAY;
 facetid->nedges=4;                             
 facetid->edge[0]=444;                      
 facetid->edge[1]=445;      
 facetid->edge[2]=453;
 facetid->edge[3]=452;
 facetid++;

 facetid->color=DARKGRAY;
 facetid->nedges=4;                          
 facetid->edge[0]=445;                           
 facetid->edge[1]=438;      
 facetid->edge[2]=446;
 facetid->edge[3]=452;
 facetid++;                     

 //facetid->color=WHITE;        //++++++Cilinder 
 //facetid->nedges=8; 
 //facetid->edge[0]=454;
 //facetid->edge[1]=455;
 //facetid->edge[2]=456;
 //facetid->edge[3]=457;            
 //facetid->edge[4]=458;
 //facetid->edge[5]=459;
 //facetid->edge[6]=460;
 //facetid->edge[7]=461;
 //facetid++;

 facetid->color=LIGHTCYAN; 
 facetid->nedges=8;
 facetid->edge[0]=469;          
 facetid->edge[1]=468;             
 facetid->edge[2]=467;      
 facetid->edge[3]=466;
 facetid->edge[4]=465;          
 facetid->edge[5]=464;             
 facetid->edge[6]=463;      
 facetid->edge[7]=462;
 facetid++;
 
 facetid->color=LIGHTCYAN;
 facetid->nedges=4;                             
 facetid->edge[0]=462;                  
 facetid->edge[1]=463;        
 facetid->edge[2]=455; 
 facetid->edge[3]=454;
 facetid++;

 facetid->color=LIGHTCYAN;
 facetid->nedges=4;                           
 facetid->edge[0]=463;                         
 facetid->edge[1]=464;      
 facetid->edge[2]=456;
 facetid->edge[3]=455;
 facetid++;

 facetid->color=LIGHTCYAN;
 facetid->nedges=4;                             
 facetid->edge[0]=464;                
 facetid->edge[1]=465;      
 facetid->edge[2]=457;
 facetid->edge[3]=456;
 facetid++;

 facetid->color=LIGHTCYAN;
 facetid->nedges=4;                     
 facetid->edge[0]=465;                         
 facetid->edge[1]=466;     
 facetid->edge[2]=458;
 facetid->edge[3]=457;
 facetid++;

facetid->color=LIGHTCYAN;
 facetid->nedges=4;             
 facetid->edge[0]=466;                          
 facetid->edge[1]=467;      
 facetid->edge[2]=459;
 facetid->edge[3]=458;
 facetid++;

 facetid->color=LIGHTCYAN;
 facetid->nedges=4;           
 facetid->edge[0]=467;                           
 facetid->edge[1]=468;      
 facetid->edge[2]=460;
 facetid->edge[3]=459;
 facetid++;

 facetid->color=LIGHTCYAN;
 facetid->nedges=4;                             
 facetid->edge[0]=468;    
 facetid->edge[1]=469;      
 facetid->edge[2]=461;
 facetid->edge[3]=460;
 facetid++;

 facetid->color=LIGHTCYAN;
 facetid->nedges=4;         
 facetid->edge[0]=469;                          
 facetid->edge[1]=462;      
 facetid->edge[2]=454;
 facetid->edge[3]=461;
 facetid++;                     

 //facetid->color=WHITE;        //++++++ OutriggerR 1 
 //facetid->nedges=8; 
 //facetid->edge[0]=470;
 //facetid->edge[1]=471;
 //facetid->edge[2]=472;
 //facetid->edge[3]=473;            
 //facetid->edge[4]=474;
 //facetid->edge[5]=475;
 //facetid->edge[6]=476;
 //facetid->edge[7]=477;
 //facetid++;

 facetid->color=LIGHTRED;
 facetid->nedges=4;                             
 facetid->edge[0]=478;                       
 facetid->edge[1]=479;        
 facetid->edge[2]=471; 
 facetid->edge[3]=470;
 facetid++;

 facetid->color=LIGHTRED;
 facetid->nedges=4;                          
 facetid->edge[0]=479;                           
 facetid->edge[1]=480;      
 facetid->edge[2]=472;
 facetid->edge[3]=471;
 facetid++;

 facetid->color=LIGHTRED;
 facetid->nedges=4;                             
 facetid->edge[0]=480;                      
 facetid->edge[1]=481;      
 facetid->edge[2]=473;
 facetid->edge[3]=472;
 facetid++;

 facetid->color=LIGHTRED;
 facetid->nedges=4;                     
 facetid->edge[0]=481;                           
 facetid->edge[1]=482;      
 facetid->edge[2]=474;
 facetid->edge[3]=473;
 facetid++;

 facetid->color=LIGHTRED;
 facetid->nedges=4;                        
 facetid->edge[0]=482;                           
 facetid->edge[1]=483;      
 facetid->edge[2]=475;
 facetid->edge[3]=474;
 facetid++;

 facetid->color=LIGHTRED;
 facetid->nedges=4;                       
 facetid->edge[0]=483;                           
 facetid->edge[1]=484;      
 facetid->edge[2]=476;
 facetid->edge[3]=475;
 facetid++;

 facetid->color=LIGHTRED;
 facetid->nedges=4;                             
 facetid->edge[0]=484;                   
 facetid->edge[1]=485;      
 facetid->edge[2]=477;
 facetid->edge[3]=476;
 facetid++;

 facetid->color=LIGHTRED; 
 facetid->nedges=4;                          
 facetid->edge[0]=485;                           
 facetid->edge[1]=478;         
 facetid->edge[2]=470;
 facetid->edge[3]=477;
 facetid++;                    
 
 //facetid->color=WHITE;        //++++++ Outriggerl 1 
 //facetid->nedges=8; 
 //facetid->edge[0]=486;
 //facetid->edge[1]=487;
 //facetid->edge[2]=488;
 //facetid->edge[3]=489;            
 //facetid->edge[4]=490;
 //facetid->edge[5]=491;
 //facetid->edge[6]=492;
 //facetid->edge[7]=493;
 //facetid++;

 facetid->color=LIGHTRED;
 facetid->nedges=4;                             
 facetid->edge[0]=494;                          
 facetid->edge[1]=495;        
 facetid->edge[2]=487; 
 facetid->edge[3]=486;
 facetid++;

 facetid->color=LIGHTRED;
 facetid->nedges=4;                         
 facetid->edge[0]=495;                           
 facetid->edge[1]=496;      
 facetid->edge[2]=488;
 facetid->edge[3]=487;
 facetid++;

 facetid->color=LIGHTRED;
 facetid->nedges=4;                             
 facetid->edge[0]=496;                     
 facetid->edge[1]=497;      
 facetid->edge[2]=489;
 facetid->edge[3]=488;
 facetid++;

 facetid->color=LIGHTRED;
 facetid->nedges=4;                      
 facetid->edge[0]=497;                           
 facetid->edge[1]=498;      
 facetid->edge[2]=490;
 facetid->edge[3]=489;
 facetid++;

 facetid->color=LIGHTRED;
 facetid->nedges=4;                         
 facetid->edge[0]=498;                           
 facetid->edge[1]=499;      
 facetid->edge[2]=491;
 facetid->edge[3]=490;
 facetid++;

 facetid->color=LIGHTRED;
 facetid->nedges=4;                        
 facetid->edge[0]=499;                           
 facetid->edge[1]=500;      
 facetid->edge[2]=492;
 facetid->edge[3]=491;
 facetid++;

 facetid->color=LIGHTRED;
 facetid->nedges=4;                             
 facetid->edge[0]=500;                        
 facetid->edge[1]=501;      
 facetid->edge[2]=493;
 facetid->edge[3]=492;
 facetid++;

 facetid->color=LIGHTRED;
 facetid->nedges=4;                          
 facetid->edge[0]=501;                           
 facetid->edge[1]=494;         
 facetid->edge[2]=486;
 facetid->edge[3]=493;
 facetid++;                    
 
 //facetid->color=WHITE;        //++++++ Outrigger R 2
 //facetid->nedges=8; 
 //facetid->edge[0]=502;
 //facetid->edge[1]=503;
 //facetid->edge[2]=504;
 //facetid->edge[3]=505;            
 //facetid->edge[4]=506;
 //facetid->edge[5]=507;
 //facetid->edge[6]=508;
 //facetid->edge[7]=509;
 //facetid++;

 facetid->color=LIGHTRED;
 facetid->nedges=4;                             
 facetid->edge[0]=510;                       
 facetid->edge[1]=511;        
 facetid->edge[2]=503; 
 facetid->edge[3]=502;
 facetid++;

 facetid->color=LIGHTRED;
 facetid->nedges=4;                         
 facetid->edge[0]=511;                           
 facetid->edge[1]=512;      
 facetid->edge[2]=504;
 facetid->edge[3]=503;
 facetid++;

 facetid->color=LIGHTRED;
 facetid->nedges=4;                             
 facetid->edge[0]=512;                       
 facetid->edge[1]=513;      
 facetid->edge[2]=505;
 facetid->edge[3]=504;
 facetid++;

 facetid->color=LIGHTRED;
 facetid->nedges=4;                        
 facetid->edge[0]=513;                           
 facetid->edge[1]=514;      
 facetid->edge[2]=506;
 facetid->edge[3]=505;
 facetid++;

 facetid->color=LIGHTRED;
 facetid->nedges=4;                         
 facetid->edge[0]=514;                           
 facetid->edge[1]=515;      
 facetid->edge[2]=507;
 facetid->edge[3]=506;
 facetid++;

 facetid->color=LIGHTRED;
 facetid->nedges=4;                         
 facetid->edge[0]=515;                           
 facetid->edge[1]=516;      
 facetid->edge[2]=508;
 facetid->edge[3]=507;
 facetid++;

 facetid->color=LIGHTRED;
 facetid->nedges=4;                             
 facetid->edge[0]=516;                       
 facetid->edge[1]=517;      
 facetid->edge[2]=509;
 facetid->edge[3]=508;
 facetid++;

 facetid->color=LIGHTRED;
 facetid->nedges=4;                          
 facetid->edge[0]=517;                           
 facetid->edge[1]=510;      
 facetid->edge[2]=502;
 facetid->edge[3]=509;
 facetid++;                    
 
 //facetid->color=WHITE;        //++++++ Outrigger L 2
 //facetid->nedges=8; 
 //facetid->edge[0]=518;
 //facetid->edge[1]=519;
 //facetid->edge[2]=520;
 //facetid->edge[3]=521;            
 //facetid->edge[4]=522;
 //facetid->edge[5]=523;
 //facetid->edge[6]=524;
 //facetid->edge[7]=525;
 //facetid++;

 facetid->color=LIGHTRED;
 facetid->nedges=4;                             
 facetid->edge[0]=526;                          
 facetid->edge[1]=527;        
 facetid->edge[2]=519; 
 facetid->edge[3]=518;
 facetid++;

 facetid->color=LIGHTRED;
 facetid->nedges=4;                           
 facetid->edge[0]=527;                           
 facetid->edge[1]=528;      
 facetid->edge[2]=520;
 facetid->edge[3]=519;
 facetid++;

 facetid->color=LIGHTRED;
 facetid->nedges=4;                             
 facetid->edge[0]=528;                          
 facetid->edge[1]=529;      
 facetid->edge[2]=521;
 facetid->edge[3]=520;
 facetid++;

 facetid->color=LIGHTRED;
 facetid->nedges=4;                          
 facetid->edge[0]=529;                           
 facetid->edge[1]=530;      
 facetid->edge[2]=522;
 facetid->edge[3]=521;
 facetid++;

 facetid->color=LIGHTRED;
 facetid->nedges=4;                         
 facetid->edge[0]=530;                           
 facetid->edge[1]=531;      
 facetid->edge[2]=523;
 facetid->edge[3]=522;
 facetid++;

 facetid->color=LIGHTRED;
 facetid->nedges=4;                         
 facetid->edge[0]=531;                           
 facetid->edge[1]=532;      
 facetid->edge[2]=524;
 facetid->edge[3]=523;
 facetid++;

 facetid->color=LIGHTRED;
 facetid->nedges=4;                             
 facetid->edge[0]=532;                       
 facetid->edge[1]=533;      
 facetid->edge[2]=525;
 facetid->edge[3]=524;
 facetid++;

 facetid->color=LIGHTRED;
 facetid->nedges=4;                         
 facetid->edge[0]=533;                           
 facetid->edge[1]=526;      
 facetid->edge[2]=518;
 facetid->edge[3]=525;
 facetid++;                    

 //facetid->color=WHITE;        //++++++Outrigger R 3
 //facetid->nedges=8; 
 //facetid->edge[0]=534;
 //facetid->edge[1]=535;
 //facetid->edge[2]=536;
 //facetid->edge[3]=537;            
 //facetid->edge[4]=538;
 //facetid->edge[5]=539;
 //facetid->edge[6]=540;
 //facetid->edge[7]=541;
 //facetid++;

 facetid->color=LIGHTRED;
 facetid->nedges=4;                             
 facetid->edge[0]=534;                         
 facetid->edge[1]=535;        
 facetid->edge[2]=543; 
 facetid->edge[3]=542;
 facetid++;

 facetid->color=LIGHTRED;
 facetid->nedges=4;                          
 facetid->edge[0]=535;                           
 facetid->edge[1]=536;      
 facetid->edge[2]=544;
 facetid->edge[3]=543;
 facetid++;

 facetid->color=LIGHTRED;
 facetid->nedges=4;                             
 facetid->edge[0]=536;                        
 facetid->edge[1]=537;      
 facetid->edge[2]=545;
 facetid->edge[3]=544;
 facetid++;

 facetid->color=LIGHTRED;
 facetid->nedges=4;                      
 facetid->edge[0]=537;                           
 facetid->edge[1]=538;      
 facetid->edge[2]=546;
 facetid->edge[3]=545;
 facetid++;

 facetid->color=LIGHTRED;
 facetid->nedges=4;                         
 facetid->edge[0]=538;                           
 facetid->edge[1]=539;      
 facetid->edge[2]=547;
 facetid->edge[3]=546;
 facetid++;

 facetid->color=LIGHTRED;
 facetid->nedges=4;                          
 facetid->edge[0]=539;                           
 facetid->edge[1]=540;      
 facetid->edge[2]=548;
 facetid->edge[3]=547;
 facetid++;

 facetid->color=LIGHTRED;
 facetid->nedges=4;                             
 facetid->edge[0]=540;                        
 facetid->edge[1]=541;      
 facetid->edge[2]=549;
 facetid->edge[3]=548;
 facetid++;

 facetid->color=LIGHTRED;
 facetid->nedges=4;                         
 facetid->edge[0]=541;                           
 facetid->edge[1]=534;      
 facetid->edge[2]=542;
 facetid->edge[3]=549;
 facetid++;                    

 //facetid->color=WHITE;        //++++++ Outrigger L 3 
 //facetid->nedges=8; 
 //facetid->edge[0]=550;
 //facetid->edge[1]=551;
 //facetid->edge[2]=552;
 //facetid->edge[3]=553;            
 //facetid->edge[4]=554;
 //facetid->edge[5]=555;
 //facetid->edge[6]=556;
 //facetid->edge[7]=557;
 //facetid++;

 facetid->color=LIGHTRED;
 facetid->nedges=4;                             
 facetid->edge[0]=550;                        
 facetid->edge[1]=551;        
 facetid->edge[2]=559; 
 facetid->edge[3]=558;
 facetid++;

 facetid->color=LIGHTRED;
 facetid->nedges=4;                          
 facetid->edge[0]=551;                           
 facetid->edge[1]=552;      
 facetid->edge[2]=560;
 facetid->edge[3]=559;
 facetid++;

 facetid->color=LIGHTRED;
 facetid->nedges=4;                             
 facetid->edge[0]=552;                          
 facetid->edge[1]=553;      
 facetid->edge[2]=561;
 facetid->edge[3]=560;
 facetid++;

 facetid->color=LIGHTRED;
 facetid->nedges=4;                          
 facetid->edge[0]=553;                           
 facetid->edge[1]=554;      
 facetid->edge[2]=562;
 facetid->edge[3]=561;
 facetid++;

 facetid->color=LIGHTRED;
 facetid->nedges=4;                        
 facetid->edge[0]=554;                           
 facetid->edge[1]=555;      
 facetid->edge[2]=563;
 facetid->edge[3]=562;
 facetid++;

 facetid->color=LIGHTRED;
 facetid->nedges=4;                           
 facetid->edge[0]=555;                           
 facetid->edge[1]=556;      
 facetid->edge[2]=564;
 facetid->edge[3]=563;
 facetid++;

 facetid->color=LIGHTRED;
 facetid->nedges=4;                             
 facetid->edge[0]=556;                       
 facetid->edge[1]=557;      
 facetid->edge[2]=565;
 facetid->edge[3]=564;
 facetid++;

 facetid->color=LIGHTRED;
 facetid->nedges=4;                           
 facetid->edge[0]=557;                           
 facetid->edge[1]=550;      
 facetid->edge[2]=558;
 facetid->edge[3]=565;
 facetid++;                    

 //facetid->color=WHITE;             //++++++Outrigger  L 4 
 //facetid->nedges=8; 
 //facetid->edge[0]=566;
 //facetid->edge[1]=567;
 //facetid->edge[2]=568;
 //facetid->edge[3]=569;            
 //facetid->edge[4]=570;
 //facetid->edge[5]=571;
 //facetid->edge[6]=572;
 //facetid->edge[7]=573;
 //facetid++;

 facetid->color=LIGHTRED;
 facetid->nedges=4;                             
 facetid->edge[0]=566;                            
 facetid->edge[1]=567;        
 facetid->edge[2]=575; 
 facetid->edge[3]=574;
 facetid++;

 facetid->color=LIGHTRED;
 facetid->nedges=4;                            
 facetid->edge[0]=567;                           
 facetid->edge[1]=568;      
 facetid->edge[2]=576;
 facetid->edge[3]=575;
 facetid++;

 facetid->color=LIGHTRED;
 facetid->nedges=4;                             
 facetid->edge[0]=568;                          
 facetid->edge[1]=569;      
 facetid->edge[2]=577;
 facetid->edge[3]=576;
 facetid++;

 facetid->color=LIGHTRED;
 facetid->nedges=4;                          
 facetid->edge[0]=569;                           
 facetid->edge[1]=570;      
 facetid->edge[2]=578;
 facetid->edge[3]=577;
 facetid++;

 facetid->color=LIGHTRED;
 facetid->nedges=4;                          
 facetid->edge[0]=570;                           
 facetid->edge[1]=571;      
 facetid->edge[2]=579;
 facetid->edge[3]=578;
 facetid++;

 facetid->color=LIGHTRED;
 facetid->nedges=4;                          
 facetid->edge[0]=571;                           
 facetid->edge[1]=572;      
 facetid->edge[2]=580;
 facetid->edge[3]=579;
 facetid++;

 facetid->color=LIGHTRED;
 facetid->nedges=4;                             
 facetid->edge[0]=572;                       
 facetid->edge[1]=573;      
 facetid->edge[2]=581;
 facetid->edge[3]=580;
 facetid++;

 facetid->color=LIGHTRED;
 facetid->nedges=4;                         
 facetid->edge[0]=573;                           
 facetid->edge[1]=566;      
 facetid->edge[2]=574;
 facetid->edge[3]=581;
 facetid++;                    

 //facetid->color=WHITE;        //++++++Outrigger  R 4
 //facetid->nedges=8; 
 //facetid->edge[0]=582;
 //facetid->edge[1]=583;
 //facetid->edge[2]=584;
 //facetid->edge[3]=585;            
 //facetid->edge[4]=586;
 //facetid->edge[5]=587;
 //facetid->edge[6]=588;
 //facetid->edge[7]=589;
 //facetid++;

 facetid->color=LIGHTRED;
 facetid->nedges=4;                             
 facetid->edge[0]=582;                          
 facetid->edge[1]=583;        
 facetid->edge[2]=591; 
 facetid->edge[3]=590;
 facetid++;

 facetid->color=LIGHTRED;
 facetid->nedges=4;                            
 facetid->edge[0]=583;                           
 facetid->edge[1]=584;      
 facetid->edge[2]=592;
 facetid->edge[3]=591;
 facetid++;

 facetid->color=LIGHTRED;
 facetid->nedges=4;                             
 facetid->edge[0]=584;                      
 facetid->edge[1]=585;      
 facetid->edge[2]=593;
 facetid->edge[3]=592;
 facetid++;

 facetid->color=LIGHTRED;
 facetid->nedges=4;                          
 facetid->edge[0]=585;                           
 facetid->edge[1]=586;      
 facetid->edge[2]=594;
 facetid->edge[3]=593;
 facetid++;

 facetid->color=LIGHTRED;
 facetid->nedges=4;                         
 facetid->edge[0]=586;                           
 facetid->edge[1]=587;      
 facetid->edge[2]=595;
 facetid->edge[3]=594;
 facetid++;

 facetid->color=LIGHTRED;
 facetid->nedges=4;                            
 facetid->edge[0]=587;                           
 facetid->edge[1]=588;      
 facetid->edge[2]=596;
 facetid->edge[3]=595;
 facetid++;

 facetid->color=LIGHTRED;
 facetid->nedges=4;                             
 facetid->edge[0]=588;                       
 facetid->edge[1]=589;      
 facetid->edge[2]=597;
 facetid->edge[3]=596;
 facetid++;

 facetid->color=LIGHTRED;
 facetid->nedges=4;                          
 facetid->edge[0]=589;                                
 facetid->edge[1]=582;      
 facetid->edge[2]=590;
 facetid->edge[3]=597;
 facetid++;                    

 // facetid->color=WHITE;    //+++++++++++ SL 1 1   
 //facetid->nedges=8; 
 //facetid->edge[0]=598;
 //facetid->edge[1]=599;
 //facetid->edge[2]=600;
 //facetid->edge[3]=601;            
 //facetid->edge[4]=602;
 //facetid->edge[5]=603;
 //facetid->edge[6]=604;
// facetid->edge[7]=605;
 //facetid++;

 facetid->color=DARKGREEN;
 facetid->nedges=4;                             
 facetid->edge[0]=598;                          
 facetid->edge[1]=599;        
 facetid->edge[2]=607; 
 facetid->edge[3]=606;
 facetid++;

 facetid->color=DARKGREEN;
 facetid->nedges=4;                          
 facetid->edge[0]=599;                           
 facetid->edge[1]=600;      
 facetid->edge[2]=608;
 facetid->edge[3]=607;
 facetid++;

 facetid->color=DARKGREEN;
 facetid->nedges=4;                             
 facetid->edge[0]=600;                        
 facetid->edge[1]=601;      
 facetid->edge[2]=609;
 facetid->edge[3]=608;
 facetid++;

 facetid->color=DARKGREEN;
 facetid->nedges=4;                           
 facetid->edge[0]=601;                           
 facetid->edge[1]=602;      
 facetid->edge[2]=610;
 facetid->edge[3]=609;
 facetid++;

 facetid->color=DARKGREEN;
 facetid->nedges=4;                         
 facetid->edge[0]=602;                           
 facetid->edge[1]=603;      
 facetid->edge[2]=611;
 facetid->edge[3]=610;
 facetid++;

 facetid->color=DARKGREEN;
 facetid->nedges=4;                        
 facetid->edge[0]=603;                           
 facetid->edge[1]=604;      
 facetid->edge[2]=612;
 facetid->edge[3]=611;
 facetid++;

 facetid->color=DARKGREEN;
 facetid->nedges=4;                             
 facetid->edge[0]=604;                       
 facetid->edge[1]=605;      
 facetid->edge[2]=613;
 facetid->edge[3]=612;
 facetid++;

 facetid->color=DARKGREEN;
 facetid->nedges=4;                           
 facetid->edge[0]=605;                           
 facetid->edge[1]=598;      
 facetid->edge[2]=606;
 facetid->edge[3]=613;
 facetid++;                    
 
 //facetid->color=WHITE;  //++++++++++++++ SL 2 1 
 //facetid->nedges=8; 
 //facetid->edge[0]=614;
 //facetid->edge[1]=615;
 //facetid->edge[2]=616;
 //facetid->edge[3]=617;            
 //facetid->edge[4]=618;
 //facetid->edge[5]=619;
 //facetid->edge[6]=620;
 //facetid->edge[7]=621;
 //facetid++;

 facetid->color=DARKGREEN;
 facetid->nedges=4;                             
 facetid->edge[0]=614;                            
 facetid->edge[1]=615;        
 facetid->edge[2]=623; 
 facetid->edge[3]=622;
 facetid++;

 facetid->color=DARKGREEN;
 facetid->nedges=4;                       
 facetid->edge[0]=615;                           
 facetid->edge[1]=616;      
 facetid->edge[2]=624;
 facetid->edge[3]=623;
 facetid++;

 facetid->color=DARKGREEN;
 facetid->nedges=4;                             
 facetid->edge[0]=616;                        
 facetid->edge[1]=617;      
 facetid->edge[2]=625;
 facetid->edge[3]=624;
 facetid++;

 facetid->color=DARKGREEN;
 facetid->nedges=4;                        
 facetid->edge[0]=617;                           
 facetid->edge[1]=618;      
 facetid->edge[2]=626;
 facetid->edge[3]=625;
 facetid++;

 facetid->color=DARKGREEN;
 facetid->nedges=4;                          
 facetid->edge[0]=618;                           
 facetid->edge[1]=619;      
 facetid->edge[2]=627;
 facetid->edge[3]=626;
 facetid++;

 facetid->color=DARKGREEN;
 facetid->nedges=4;                         
 facetid->edge[0]=619;                           
 facetid->edge[1]=620;      
 facetid->edge[2]=628;
 facetid->edge[3]=627;
 facetid++;

 facetid->color=DARKGREEN;
 facetid->nedges=4;                             
 facetid->edge[0]=620;                      
 facetid->edge[1]=621;      
 facetid->edge[2]=629;
 facetid->edge[3]=628;
 facetid++;

 facetid->color=DARKGREEN;
 facetid->nedges=4;                         
 facetid->edge[0]=621;                           
 facetid->edge[1]=614;      
 facetid->edge[2]=622;
 facetid->edge[3]=629;
 facetid++;                    

 //facetid->color=WHITE;    //++++++ SL 1 2   
 //facetid->nedges=8; 
 //facetid->edge[0]=630;
 //facetid->edge[1]=631;
 //facetid->edge[2]=632;
 //facetid->edge[3]=633;            
 //facetid->edge[4]=634;
 //facetid->edge[5]=635;
 //facetid->edge[6]=636;
 //facetid->edge[7]=637;
 //facetid++;

 facetid->color=DARKGREEN;
 facetid->nedges=4;                             
 facetid->edge[0]=638;                          
 facetid->edge[1]=639;       
 facetid->edge[2]=631; 
 facetid->edge[3]=630;
 facetid++;

 facetid->color=DARKGREEN;
 facetid->nedges=4;                          
 facetid->edge[0]=639;                       
 facetid->edge[1]=640;      
 facetid->edge[2]=632;
 facetid->edge[3]=631;
 facetid++;

 facetid->color=DARKGREEN;
 facetid->nedges=4;                             
 facetid->edge[0]=640;                        
 facetid->edge[1]=641; 
 facetid->edge[2]=633;
 facetid->edge[3]=632;
 facetid++;

 facetid->color=DARKGREEN;
 facetid->nedges=4;                           
 facetid->edge[0]=641;                        
 facetid->edge[1]=642;      
 facetid->edge[2]=634;
 facetid->edge[3]=633;
 facetid++;

 facetid->color=DARKGREEN;
 facetid->nedges=4;                         
 facetid->edge[0]=642;                        
 facetid->edge[1]=643;      
 facetid->edge[2]=635;
 facetid->edge[3]=634;
 facetid++;

 facetid->color=DARKGREEN;
 facetid->nedges=4;                        
 facetid->edge[0]=641;                           
 facetid->edge[1]=644; 
 facetid->edge[2]=636;
 facetid->edge[3]=635;
 facetid++;

 facetid->color=DARKGREEN;
 facetid->nedges=4;                             
 facetid->edge[0]=644;                       
 facetid->edge[1]=645;   
 facetid->edge[2]=637;
 facetid->edge[3]=636;
 facetid++;

 facetid->color=DARKGREEN;
 facetid->nedges=4;                           
 facetid->edge[0]=645;                           
 facetid->edge[1]=638; 
 facetid->edge[2]=630;
 facetid->edge[3]=637;
 facetid++;                    

 //facetid->color=WHITE;    //++++++ SR 2 2   
 //facetid->nedges=8; 
 //facetid->edge[0]=646;
 //facetid->edge[1]=647;
 //facetid->edge[2]=648;
 //facetid->edge[3]=649;            
 //facetid->edge[4]=650;
 //facetid->edge[5]=651;
 //facetid->edge[6]=652;
 //facetid->edge[7]=653;
 //facetid++;

 facetid->color=DARKGREEN;
 facetid->nedges=4;                             
 facetid->edge[0]=654;                          
 facetid->edge[1]=655;       
 facetid->edge[2]=647; 
 facetid->edge[3]=646;
 facetid++;

 facetid->color=DARKGREEN;
 facetid->nedges=4;                          
 facetid->edge[0]=655;                       
 facetid->edge[1]=656;      
 facetid->edge[2]=648;
 facetid->edge[3]=647;
 facetid++;

 facetid->color=DARKGREEN;
 facetid->nedges=4;                             
 facetid->edge[0]=656;                        
 facetid->edge[1]=657;  
 facetid->edge[2]=649;
 facetid->edge[3]=648;
 facetid++;

 facetid->color=DARKGREEN;
 facetid->nedges=4;                           
 facetid->edge[0]=657;                      
 facetid->edge[1]=658;      
 facetid->edge[2]=650;
 facetid->edge[3]=649;
 facetid++;

 facetid->color=DARKGREEN;
 facetid->nedges=4;                         
 facetid->edge[0]=658;                        
 facetid->edge[1]=659;      
 facetid->edge[2]=651;
 facetid->edge[3]=650;
 facetid++;

 facetid->color=DARKGREEN;
 facetid->nedges=4;                        
 facetid->edge[0]=659;                           
 facetid->edge[1]=660;  
 facetid->edge[2]=652;
 facetid->edge[3]=651;
 facetid++;

 facetid->color=DARKGREEN;
 facetid->nedges=4;                             
 facetid->edge[0]=660;                       
 facetid->edge[1]=661;   
 facetid->edge[2]=653;
 facetid->edge[3]=652;
 facetid++;

 facetid->color=DARKGREEN;
 facetid->nedges=4;                           
 facetid->edge[0]=661;                           
 facetid->edge[1]=654;  
 facetid->edge[2]=646;
 facetid->edge[3]=653;
 facetid++;                    

 //facetid->color=WHITE;    //++++++ SL 1 3   
 //facetid->nedges=8; 
 //facetid->edge[0]=662;
 //facetid->edge[1]=663;
 //facetid->edge[2]=664;
 //facetid->edge[3]=665;            
 //facetid->edge[4]=666;
 //facetid->edge[5]=667;
 //facetid->edge[6]=668;
 //facetid->edge[7]=669;
 //facetid++;

 facetid->color=DARKGREEN;
 facetid->nedges=4;                             
 facetid->edge[0]=662;                          
 facetid->edge[1]=663;    
 facetid->edge[2]=671; 
 facetid->edge[3]=670;
 facetid++;

 facetid->color=DARKGREEN;
 facetid->nedges=4;                          
 facetid->edge[0]=663;                         
 facetid->edge[1]=664;      
 facetid->edge[2]=672;
 facetid->edge[3]=671;
 facetid++;

 facetid->color=DARKGREEN;
 facetid->nedges=4;                             
 facetid->edge[0]=664;                        
 facetid->edge[1]=665;   
 facetid->edge[2]=673;
 facetid->edge[3]=672;
 facetid++;

 facetid->color=DARKGREEN;
 facetid->nedges=4;                           
 facetid->edge[0]=665;                     
 facetid->edge[1]=666;      
 facetid->edge[2]=674;
 facetid->edge[3]=673;
 facetid++;

 facetid->color=DARKGREEN;
 facetid->nedges=4;                         
 facetid->edge[0]=666;                        
 facetid->edge[1]=667;      
 facetid->edge[2]=675;
 facetid->edge[3]=674;
 facetid++;

 facetid->color=DARKGREEN;
 facetid->nedges=4;                        
 facetid->edge[0]=667;                           
 facetid->edge[1]=668;    
 facetid->edge[2]=676;
 facetid->edge[3]=675;
 facetid++;

 facetid->color=DARKGREEN;
 facetid->nedges=4;                             
 facetid->edge[0]=668;                       
 facetid->edge[1]=669;   
 facetid->edge[2]=677;
 facetid->edge[3]=676;
 facetid++;

 facetid->color=DARKGREEN;
 facetid->nedges=4;                           
 facetid->edge[0]=669;                           
 facetid->edge[1]=662;      
 facetid->edge[2]=670;
 facetid->edge[3]=677;
 facetid++;                    
 
 //facetid->color=WHITE;    //++++++ SR 2 3   
 //facetid->nedges=8; 
 //facetid->edge[0]=678;
 //facetid->edge[1]=679;
 //facetid->edge[2]=680;
 //facetid->edge[3]=681;            
 //facetid->edge[4]=682;
 //facetid->edge[5]=683;
 //facetid->edge[6]=684;
 //facetid->edge[7]=685;
 //facetid++;

 facetid->color=DARKGREEN;
 facetid->nedges=4;                             
 facetid->edge[0]=678;                          
 facetid->edge[1]=679;   
 facetid->edge[2]=687; 
 facetid->edge[3]=686;
 facetid++;

 facetid->color=DARKGREEN;
 facetid->nedges=4;                          
 facetid->edge[0]=679;                     
 facetid->edge[1]=680;      
 facetid->edge[2]=688;
 facetid->edge[3]=687;
 facetid++;

 facetid->color=DARKGREEN;
 facetid->nedges=4;                             
 facetid->edge[0]=680;                        
 facetid->edge[1]=681;  
 facetid->edge[2]=689;
 facetid->edge[3]=688;
 facetid++;

 facetid->color=DARKGREEN;
 facetid->nedges=4;                           
 facetid->edge[0]=681;                      
 facetid->edge[1]=682;      
 facetid->edge[2]=690;
 facetid->edge[3]=689;
 facetid++;

 facetid->color=DARKGREEN;
 facetid->nedges=4;                         
 facetid->edge[0]=682;                     
 facetid->edge[1]=683;      
 facetid->edge[2]=691;
 facetid->edge[3]=690;
 facetid++;

 facetid->color=DARKGREEN;
 facetid->nedges=4;                        
 facetid->edge[0]=683;                           
 facetid->edge[1]=684;   
 facetid->edge[2]=692;
 facetid->edge[3]=691;
 facetid++;

 facetid->color=DARKGREEN;
 facetid->nedges=4;                             
 facetid->edge[0]=684;                       
 facetid->edge[1]=685;  
 facetid->edge[2]=693;
 facetid->edge[3]=692;
 facetid++;

 facetid->color=DARKGREEN;
 facetid->nedges=4;                           
 facetid->edge[0]=685;                           
 facetid->edge[1]=678;      
 facetid->edge[2]=686;
 facetid->edge[3]=693;
 facetid++;                 
 
 //facetid->color=WHITE;    //++++++ SR 1 4  
 //facetid->nedges=8; 
 //facetid->edge[0]=694;
 //facetid->edge[1]=695;
 //facetid->edge[2]=696;
 //facetid->edge[3]=697;            
 //facetid->edge[4]=698;
 //facetid->edge[5]=699;
 //facetid->edge[6]=700;
 //facetid->edge[7]=701;
 //facetid++;

 facetid->color=DARKGREEN;
 facetid->nedges=4;                             
 facetid->edge[0]=702;                          
 facetid->edge[1]=703;  
 facetid->edge[2]=695; 
 facetid->edge[3]=694;
 facetid++;

 facetid->color=DARKGREEN;
 facetid->nedges=4;                          
 facetid->edge[0]=703;                      
 facetid->edge[1]=704;      
 facetid->edge[2]=696;
 facetid->edge[3]=695;
 facetid++;

 facetid->color=DARKGREEN;
 facetid->nedges=4;                             
 facetid->edge[0]=704;                        
 facetid->edge[1]=705;     
 facetid->edge[2]=697;
 facetid->edge[3]=696;
 facetid++;

 facetid->color=DARKGREEN;
 facetid->nedges=4;                           
 facetid->edge[0]=705;                       
 facetid->edge[1]=706;      
 facetid->edge[2]=698;
 facetid->edge[3]=697;
 facetid++;

 facetid->color=DARKGREEN;
 facetid->nedges=4;                         
 facetid->edge[0]=706;                      
 facetid->edge[1]=707;      
 facetid->edge[2]=699;
 facetid->edge[3]=698;
 facetid++;

 facetid->color=DARKGREEN;
 facetid->nedges=4;                        
 facetid->edge[0]=707;                           
 facetid->edge[1]=708;
 facetid->edge[2]=700;
 facetid->edge[3]=699;
 facetid++;

 facetid->color=DARKGREEN;
 facetid->nedges=4;                             
 facetid->edge[0]=708;                       
 facetid->edge[1]=709;      
 facetid->edge[2]=701;
 facetid->edge[3]=700;
 facetid++;

 facetid->color=DARKGREEN;
 facetid->nedges=4;                           
 facetid->edge[0]=709;                           
 facetid->edge[1]=702;      
 facetid->edge[2]=694;
 facetid->edge[3]=701;
 facetid++;                 

 //facetid->color=WHITE;    //++++++ SR 2 4   
 //facetid->nedges=8; 
 //facetid->edge[0]=710;
 //facetid->edge[1]=711;
 //facetid->edge[2]=712;
 //facetid->edge[3]=713;            
 //facetid->edge[4]=714;
 //facetid->edge[5]=715;
 //facetid->edge[6]=716;
 //facetid->edge[7]=717;
 //facetid++;

 facetid->color=DARKGREEN;
 facetid->nedges=4;                             
 facetid->edge[0]=718;                          
 facetid->edge[1]=719;        
 facetid->edge[2]=711; 
 facetid->edge[3]=710;
 facetid++;

 facetid->color=DARKGREEN;
 facetid->nedges=4;                          
 facetid->edge[0]=719;                           
 facetid->edge[1]=720;      
 facetid->edge[2]=712;
 facetid->edge[3]=711;
 facetid++;

 facetid->color=DARKGREEN;
 facetid->nedges=4;                             
 facetid->edge[0]=720;                        
 facetid->edge[1]=721;      
 facetid->edge[2]=713;
 facetid->edge[3]=712;
 facetid++;

 facetid->color=DARKGREEN;
 facetid->nedges=4;                           
 facetid->edge[0]=721;                          
 facetid->edge[1]=722;      
 facetid->edge[2]=714;
 facetid->edge[3]=713;
 facetid++;

 facetid->color=DARKGREEN;
 facetid->nedges=4;                         
 facetid->edge[0]=722;                           
 facetid->edge[1]=723;      
 facetid->edge[2]=715;
 facetid->edge[3]=714;
 facetid++;

 facetid->color=DARKGREEN;
 facetid->nedges=4;                        
 facetid->edge[0]=723;                           
 facetid->edge[1]=724;      
 facetid->edge[2]=716;
 facetid->edge[3]=715;
 facetid++;

 facetid->color=DARKGREEN;
 facetid->nedges=4;                             
 facetid->edge[0]=724;                       
 facetid->edge[1]=725;      
 facetid->edge[2]=717;
 facetid->edge[3]=716;
 facetid++;

 facetid->color=DARKGREEN;
 facetid->nedges=4;                           
 facetid->edge[0]=725;                           
 facetid->edge[1]=718;      
 facetid->edge[2]=710;
 facetid->edge[3]=717;
 facetid++;                 
 
                                      //++++++ Cone 2 1  
 facetid->color=LIGHTRED;
 facetid->nedges=3;                             
 facetid->edge[0]=470;                         
 facetid->edge[1]=471;       
 facetid->edge[2]=726; 
 facetid++;

 facetid->color=LIGHTRED;
 facetid->nedges=3;                          
 facetid->edge[0]=471;                           
 facetid->edge[1]=472;     
 facetid->edge[2]=726;
 facetid++;

 facetid->color=LIGHTRED;
 facetid->nedges=3;                             
 facetid->edge[0]=472;                        
 facetid->edge[1]=473;      
 facetid->edge[2]=726;
 facetid++;

 facetid->color=LIGHTRED;
 facetid->nedges=3;                           
 facetid->edge[0]=473;                           
 facetid->edge[1]=474;      
 facetid->edge[2]=726;
 facetid++;

 facetid->color=LIGHTRED;
 facetid->nedges=3;                         
 facetid->edge[0]=474;                           
 facetid->edge[1]=475;      
 facetid->edge[2]=726;
 facetid++;

 facetid->color=LIGHTRED;
 facetid->nedges=3;                        
 facetid->edge[0]=475;                           
 facetid->edge[1]=476;      
 facetid->edge[2]=726;
 facetid++;

 facetid->color=LIGHTRED;
 facetid->nedges=3;                             
 facetid->edge[0]=476;                       
 facetid->edge[1]=477;      
 facetid->edge[2]=726;
 facetid++;

 facetid->color=LIGHTRED;
 facetid->nedges=3;                           
 facetid->edge[0]=477;                           
 facetid->edge[1]=470;      
 facetid->edge[2]=726;
 facetid++;                 
 
                              //++++++ Cone 2 1   
 facetid->color=LIGHTRED;
 facetid->nedges=3;                             
 facetid->edge[0]=486;                         
 facetid->edge[1]=487;     
 facetid->edge[2]=727; 
 facetid++;

 facetid->color=LIGHTRED;
 facetid->nedges=3;                          
 facetid->edge[0]=487;                           
 facetid->edge[1]=488;     
 facetid->edge[2]=727;
 facetid++;

 facetid->color=LIGHTRED;
 facetid->nedges=3;                             
 facetid->edge[0]=488;                        
 facetid->edge[1]=489;      
 facetid->edge[2]=727;
 facetid++;

 facetid->color=LIGHTRED;
 facetid->nedges=3;                           
 facetid->edge[0]=489;                           
 facetid->edge[1]=490;      
 facetid->edge[2]=727;
 facetid++;

 facetid->color=LIGHTRED;
 facetid->nedges=3;                         
 facetid->edge[0]=490;                           
 facetid->edge[1]=491;      
 facetid->edge[2]=727;
 facetid++;

 facetid->color=LIGHTRED;
 facetid->nedges=3;                        
 facetid->edge[0]=491;                           
 facetid->edge[1]=492;      
 facetid->edge[2]=727;
 facetid++;

 facetid->color=LIGHTRED;
 facetid->nedges=3;                             
 facetid->edge[0]=492;                       
 facetid->edge[1]=493;      
 facetid->edge[2]=727;
 facetid++;

 facetid->color=LIGHTRED;
 facetid->nedges=3;                           
 facetid->edge[0]=493;                           
 facetid->edge[1]=486;      
 facetid->edge[2]=727;
 facetid++;                 
 
                                //++++++ Cone R1 2  
 facetid->color=LIGHTRED;
 facetid->nedges=3;                             
 facetid->edge[0]=502;                    
 facetid->edge[1]=503;       
 facetid->edge[2]=728; 
 facetid++;

 facetid->color=LIGHTRED;
 facetid->nedges=3;                          
 facetid->edge[0]=503;                   
 facetid->edge[1]=504;     
 facetid->edge[2]=728;
 facetid++;

 facetid->color=LIGHTRED;
 facetid->nedges=3;                             
 facetid->edge[0]=504;                        
 facetid->edge[1]=505;      
 facetid->edge[2]=728;
 facetid++;

 facetid->color=LIGHTRED;
 facetid->nedges=3;                           
 facetid->edge[0]=505;                           
 facetid->edge[1]=506;      
 facetid->edge[2]=728;
 facetid++;

 facetid->color=LIGHTRED;
 facetid->nedges=3;                         
 facetid->edge[0]=506;                           
 facetid->edge[1]=507;      
 facetid->edge[2]=728;
 facetid++;

 facetid->color=LIGHTRED;
 facetid->nedges=3;                        
 facetid->edge[0]=507;                           
 facetid->edge[1]=508;       
 facetid->edge[2]=728;
 facetid++;

 facetid->color=LIGHTRED;
 facetid->nedges=3;                             
 facetid->edge[0]=508;                       
 facetid->edge[1]=509;      
 facetid->edge[2]=728;
 facetid++;

 facetid->color=LIGHTRED;
 facetid->nedges=3;                           
 facetid->edge[0]=509;                           
 facetid->edge[1]=502;      
 facetid->edge[2]=728;
 facetid++;                 
 
                                  //++++++ Cone L2 2  
 facetid->color=LIGHTRED;
 facetid->nedges=3;                             
 facetid->edge[0]=518;                    
 facetid->edge[1]=519;     
 facetid->edge[2]=729; 
 facetid++;

 facetid->color=LIGHTRED;
 facetid->nedges=3;                          
 facetid->edge[0]=519;                   
 facetid->edge[1]=520;     
 facetid->edge[2]=729;
 facetid++;

 facetid->color=LIGHTRED;
 facetid->nedges=3;                             
 facetid->edge[0]=520;                        
 facetid->edge[1]=521;      
 facetid->edge[2]=729;
 facetid++;

 facetid->color=LIGHTRED;
 facetid->nedges=3;                           
 facetid->edge[0]=521;                         
 facetid->edge[1]=522;      
 facetid->edge[2]=729;
 facetid++;

 facetid->color=LIGHTRED;
 facetid->nedges=3;                         
 facetid->edge[0]=522;                          
 facetid->edge[1]=523;      
 facetid->edge[2]=729;
 facetid++;

 facetid->color=LIGHTRED;
 facetid->nedges=3;                        
 facetid->edge[0]=523;                           
 facetid->edge[1]=524;      
 facetid->edge[2]=729;
 facetid++;

 facetid->color=LIGHTRED;
 facetid->nedges=3;                             
 facetid->edge[0]=524;                       
 facetid->edge[1]=525;    
 facetid->edge[2]=729;
 facetid++;

 facetid->color=LIGHTRED;
 facetid->nedges=3;                           
 facetid->edge[0]=525;                           
 facetid->edge[1]=518;      
 facetid->edge[2]=729;
 facetid++;                 

                              //++++++ Cone L1 3  
 facetid->color=LIGHTRED;
 facetid->nedges=3;                            
 facetid->edge[0]=535;                     
 facetid->edge[1]=534;    
 facetid->edge[2]=730; 
 facetid++;

 facetid->color=LIGHTRED;
 facetid->nedges=3;                          
 facetid->edge[0]=536;                   
 facetid->edge[1]=535;     
 facetid->edge[2]=730;
 facetid++;

 facetid->color=LIGHTRED;
 facetid->nedges=3;                             
 facetid->edge[0]=537;                        
 facetid->edge[1]=536;      
 facetid->edge[2]=730;
 facetid++;

 facetid->color=LIGHTRED;
 facetid->nedges=3;                           
 facetid->edge[0]=538;                           
 facetid->edge[1]=537;      
 facetid->edge[2]=730;
 facetid++;

 facetid->color=LIGHTRED;
 facetid->nedges=3;                         
 facetid->edge[0]=539;                           
 facetid->edge[1]=538;      
 facetid->edge[2]=730;
 facetid++;

 facetid->color=LIGHTRED;
 facetid->nedges=3;                        
 facetid->edge[0]=540;                           
 facetid->edge[1]=539;      
 facetid->edge[2]=730;
 facetid++;

 facetid->color=LIGHTRED;
 facetid->nedges=3;                             
 facetid->edge[0]=541;                       
 facetid->edge[1]=540;      
 facetid->edge[2]=730;
 facetid++;

 facetid->color=LIGHTRED;
 facetid->nedges=3;                           
 facetid->edge[0]=535;                           
 facetid->edge[1]=541;      
 facetid->edge[2]=730;
 facetid++;                 

                            //++++++ Cone L1 3   
 facetid->color=LIGHTRED;
 facetid->nedges=3;                             
 facetid->edge[0]=551;                    
 facetid->edge[1]=550;     
 facetid->edge[2]=731; 
 facetid++;

 facetid->color=LIGHTRED;
 facetid->nedges=3;                          
 facetid->edge[0]=552;                   
 facetid->edge[1]=551;    
 facetid->edge[2]=731;
 facetid++;

 facetid->color=LIGHTRED;
 facetid->nedges=3;                             
 facetid->edge[0]=553;                        
 facetid->edge[1]=552;      
 facetid->edge[2]=731;
 facetid++;

 facetid->color=LIGHTRED;
 facetid->nedges=3;                           
 facetid->edge[0]=554;                           
 facetid->edge[1]=553;      
 facetid->edge[2]=731;
 facetid++;

 facetid->color=LIGHTRED;
 facetid->nedges=3;                         
 facetid->edge[0]=555;                           
 facetid->edge[1]=554;      
 facetid->edge[2]=731;
 facetid++;

 facetid->color=LIGHTRED;
 facetid->nedges=3;                        
 facetid->edge[0]=556;                           
 facetid->edge[1]=555;      
 facetid->edge[2]=731;
 facetid++;

 facetid->color=LIGHTRED;
 facetid->nedges=3;                             
 facetid->edge[0]=557;                       
 facetid->edge[1]=556;      
 facetid->edge[2]=731;
 facetid++;

 facetid->color=LIGHTRED;
 facetid->nedges=3;                           
 facetid->edge[0]=550;                           
 facetid->edge[1]=557;      
 facetid->edge[2]=731;
 facetid++;                 

                          //++++++ Cone L1 4   
 facetid->color=LIGHTRED;
 facetid->nedges=3;                             
 facetid->edge[0]=567;     
 facetid->edge[1]=566;   
 facetid->edge[2]=732; 
 facetid++;

 facetid->color=LIGHTRED;
 facetid->nedges=3;                          
 facetid->edge[0]=568;                   
 facetid->edge[1]=567;    
 facetid->edge[2]=732;
 facetid++;

 facetid->color=LIGHTRED;
 facetid->nedges=3;                             
 facetid->edge[0]=569;                        
 facetid->edge[1]=568;      
 facetid->edge[2]=732;
 facetid++;

 facetid->color=LIGHTRED;
 facetid->nedges=3;                           
 facetid->edge[0]=570;                           
 facetid->edge[1]=569;      
 facetid->edge[2]=732;
 facetid++;

 facetid->color=LIGHTRED;
 facetid->nedges=3;                         
 facetid->edge[0]=571;                           
 facetid->edge[1]=570;      
 facetid->edge[2]=732;
 facetid++;

 facetid->color=LIGHTRED;
 facetid->nedges=3;                        
 facetid->edge[0]=572;                           
 facetid->edge[1]=571;      
 facetid->edge[2]=732;
 facetid++;

 facetid->color=LIGHTRED;
 facetid->nedges=3;                             
 facetid->edge[0]=573;                       
 facetid->edge[1]=572;      
 facetid->edge[2]=732;
 facetid++;

 facetid->color=LIGHTRED;
 facetid->nedges=3;                           
 facetid->edge[0]=566;                           
 facetid->edge[1]=573;      
 facetid->edge[2]=732;
 facetid++;                 

                            //++++++ Cone R1 4   
 facetid->color=LIGHTRED;
 facetid->nedges=3;                             
 facetid->edge[0]=583;                         
 facetid->edge[1]=582;
 facetid->edge[2]=733; 
 facetid++;

 facetid->color=LIGHTRED;
 facetid->nedges=3;                          
 facetid->edge[0]=584;                   
 facetid->edge[1]=583;     
 facetid->edge[2]=733;
 facetid++;

 facetid->color=LIGHTRED;
 facetid->nedges=3;                             
 facetid->edge[0]=585;                        
 facetid->edge[1]=584;      
 facetid->edge[2]=733;
 facetid++;

 facetid->color=LIGHTRED;
 facetid->nedges=3;                           
 facetid->edge[0]=586;                           
 facetid->edge[1]=585;      
 facetid->edge[2]=733;
 facetid++;

 facetid->color=LIGHTRED;
 facetid->nedges=3;                         
 facetid->edge[0]=587;                           
 facetid->edge[1]=586;      
 facetid->edge[2]=733;
 facetid++;

 facetid->color=LIGHTRED;
 facetid->nedges=3;                        
 facetid->edge[0]=588;                           
 facetid->edge[1]=587;      
 facetid->edge[2]=733;
 facetid++;

 facetid->color=LIGHTRED;
 facetid->nedges=3;                             
 facetid->edge[0]=589;                       
 facetid->edge[1]=588;      
 facetid->edge[2]=733;
 facetid++;

 facetid->color=LIGHTRED;
 facetid->nedges=3;                           
 facetid->edge[0]=582;                           
 facetid->edge[1]=589;      
 facetid->edge[2]=733;
 facetid++;                 

                            //++++++ Cone Landing Gear 1    
 facetid->color=DARKGREEN;
 facetid->nedges=3;                             
 facetid->edge[0]=135;                         
 facetid->edge[1]=134;
 facetid->edge[2]=734; 
 facetid++;

 facetid->color=DARKGREEN;
 facetid->nedges=3;                          
 facetid->edge[0]=136;                   
 facetid->edge[1]=135;     
 facetid->edge[2]=734;
 facetid++;

 facetid->color=DARKGREEN;
 facetid->nedges=3;                             
 facetid->edge[0]=137;                        
 facetid->edge[1]=136;      
 facetid->edge[2]=734;
 facetid++;

 facetid->color=DARKGREEN;
 facetid->nedges=3;                           
 facetid->edge[0]=138;                           
 facetid->edge[1]=137;      
 facetid->edge[2]=734;
 facetid++;

 facetid->color=DARKGREEN;
 facetid->nedges=3;                         
 facetid->edge[0]=139;                           
 facetid->edge[1]=138;      
 facetid->edge[2]=734;
 facetid++;

 facetid->color=DARKGREEN;
 facetid->nedges=3;                        
 facetid->edge[0]=140;                           
 facetid->edge[1]=139;      
 facetid->edge[2]=734;
 facetid++;

 facetid->color=DARKGREEN;
 facetid->nedges=3;                             
 facetid->edge[0]=141;                       
 facetid->edge[1]=140;      
 facetid->edge[2]=734;
 facetid++;

 facetid->color=DARKGREEN;
 facetid->nedges=3;                           
 facetid->edge[0]=134;                           
 facetid->edge[1]=141;      
 facetid->edge[2]=734;
 facetid++;                 
 
                            //+++++++++Cone Landing Gear 2    
 facetid->color=DARKGREEN;
 facetid->nedges=3;                             
 facetid->edge[0]=151; 
 facetid->edge[1]=150;
 facetid->edge[2]=735; 
 facetid++;

 facetid->color=DARKGREEN;
 facetid->nedges=3;                          
 facetid->edge[0]=152;                   
 facetid->edge[1]=151;     
 facetid->edge[2]=735;
 facetid++;

 facetid->color=DARKGREEN;
 facetid->nedges=3;                             
 facetid->edge[0]=153;                        
 facetid->edge[1]=152;      
 facetid->edge[2]=735;
 facetid++;

 facetid->color=DARKGREEN;
 facetid->nedges=3;                           
 facetid->edge[0]=154;                           
 facetid->edge[1]=153;      
 facetid->edge[2]=735;
 facetid++;

 facetid->color=DARKGREEN;
 facetid->nedges=3;                         
 facetid->edge[0]=155;                           
 facetid->edge[1]=154;      
 facetid->edge[2]=735;
 facetid++;

 facetid->color=DARKGREEN;
 facetid->nedges=3;                        
 facetid->edge[0]=156;                           
 facetid->edge[1]=155;      
 facetid->edge[2]=735;
 facetid++;

 facetid->color=DARKGREEN;
 facetid->nedges=3;                             
 facetid->edge[0]=157;                       
 facetid->edge[1]=156;      
 facetid->edge[2]=735;
 facetid++;

 facetid->color=DARKGREEN; 
 facetid->nedges=3;                           
 facetid->edge[0]=150;                           
 facetid->edge[1]=157;      
 facetid->edge[2]=735;
 facetid++;                 

                            //++++++ Cone Landing Gear 3    
 facetid->color=DARKGREEN;
 facetid->nedges=3;                              
 facetid->edge[0]=167;                                                       
 facetid->edge[1]=166;
 facetid->edge[2]=736; 
 facetid++;

 facetid->color=DARKGREEN;
 facetid->nedges=3;                          
 facetid->edge[0]=168;                   
 facetid->edge[1]=167;     
 facetid->edge[2]=736;
 facetid++;

 facetid->color=DARKGREEN;
 facetid->nedges=3;                             
 facetid->edge[0]=169;                        
 facetid->edge[1]=168;      
 facetid->edge[2]=736;
 facetid++;

 facetid->color=DARKGREEN;
 facetid->nedges=3;                           
 facetid->edge[0]=170;                           
 facetid->edge[1]=169;      
 facetid->edge[2]=736;
 facetid++;

 facetid->color=DARKGREEN;
 facetid->nedges=3;                         
 facetid->edge[0]=171;                           
 facetid->edge[1]=170;      
 facetid->edge[2]=736;
 facetid++;

 facetid->color=DARKGREEN;
 facetid->nedges=3;                        
 facetid->edge[0]=172;                           
 facetid->edge[1]=171;      
 facetid->edge[2]=736;
 facetid++;

 facetid->color=DARKGREEN;
 facetid->nedges=3;                             
 facetid->edge[0]=173;                       
 facetid->edge[1]=172;      
 facetid->edge[2]=736;
 facetid++;

 facetid->color=DARKGREEN; 
 facetid->nedges=3;                           
 facetid->edge[0]=166;                           
 facetid->edge[1]=173;      
 facetid->edge[2]=736;
 facetid++;                 

                            //++++++ Cone Landing Gear 4    
 facetid->color=DARKGREEN;
 facetid->nedges=3;                             
 facetid->edge[0]=183;                           
 facetid->edge[1]=182;
 facetid->edge[2]=737; 
 facetid++;

 facetid->color=DARKGREEN;
 facetid->nedges=3;                          
 facetid->edge[0]=184;                   
 facetid->edge[1]=183;     
 facetid->edge[2]=737;
 facetid++;

 facetid->color=DARKGREEN;
 facetid->nedges=3;                             
 facetid->edge[0]=185;                        
 facetid->edge[1]=184;      
 facetid->edge[2]=737;
 facetid++;

 facetid->color=DARKGREEN;
 facetid->nedges=3;                           
 facetid->edge[0]=186;                           
 facetid->edge[1]=185;      
 facetid->edge[2]=737;
 facetid++;

 facetid->color=DARKGREEN;
 facetid->nedges=3;                         
 facetid->edge[0]=187;                           
 facetid->edge[1]=186;      
 facetid->edge[2]=737;
 facetid++;

 facetid->color=DARKGREEN;
 facetid->nedges=3;                        
 facetid->edge[0]=188;                           
 facetid->edge[1]=187;      
 facetid->edge[2]=737;
 facetid++;

 facetid->color=DARKGREEN;
 facetid->nedges=3;                             
 facetid->edge[0]=189;                       
 facetid->edge[1]=188;      
 facetid->edge[2]=737;
 facetid++;

 facetid->color=DARKGREEN; 
 facetid->nedges=3;                           
 facetid->edge[0]=182;                           
 facetid->edge[1]=189;      
 facetid->edge[2]=737;
 facetid++;                 

                          //++++++ Cone Outrigger 1 1   
 facetid->color=DARKGREEN;
 facetid->nedges=3;                             
 facetid->edge[0]=599;                            
 facetid->edge[1]=598;
 facetid->edge[2]=738; 
 facetid++;

 facetid->color=DARKGREEN;
 facetid->nedges=3;                          
 facetid->edge[0]=600;                   
 facetid->edge[1]=599;     
 facetid->edge[2]=738;
 facetid++;

 facetid->color=DARKGREEN;
 facetid->nedges=3;                             
 facetid->edge[0]=601;                        
 facetid->edge[1]=600;      
 facetid->edge[2]=738;
 facetid++;

 facetid->color=DARKGREEN;
 facetid->nedges=3;                           
 facetid->edge[0]=602;                           
 facetid->edge[1]=601;      
 facetid->edge[2]=738;
 facetid++;

 facetid->color=DARKGREEN;
 facetid->nedges=3;                         
 facetid->edge[0]=603;                           
 facetid->edge[1]=602;      
 facetid->edge[2]=738;
 facetid++;

 facetid->color=DARKGREEN;
 facetid->nedges=3;                        
 facetid->edge[0]=604;                           
 facetid->edge[1]=603;      
 facetid->edge[2]=738;
 facetid++;

 facetid->color=DARKGREEN;
 facetid->nedges=3;                             
 facetid->edge[0]=605;                       
 facetid->edge[1]=604;      
 facetid->edge[2]=738;
 facetid++;

 facetid->color=DARKGREEN; 
 facetid->nedges=3;                           
 facetid->edge[0]=598;                           
 facetid->edge[1]=605;      
 facetid->edge[2]=738;
 facetid++;                 
 
 				    //++++++ Cone Outrigger Back 1 1    
 facetid->color=DARKGREEN;
 facetid->nedges=3;                             
 facetid->edge[0]=606;                            
 facetid->edge[1]=607;
 facetid->edge[2]=739; 
 facetid++;

 facetid->color=DARKGREEN;
 facetid->nedges=3;                          
 facetid->edge[0]=607;                   
 facetid->edge[1]=608;     
 facetid->edge[2]=739;
 facetid++;

 facetid->color=DARKGREEN;
 facetid->nedges=3;                             
 facetid->edge[0]=608;                        
 facetid->edge[1]=609;      
 facetid->edge[2]=739;
 facetid++;

 facetid->color=DARKGREEN;
 facetid->nedges=3;                           
 facetid->edge[0]=609;                           
 facetid->edge[1]=610;      
 facetid->edge[2]=739;
 facetid++;

 facetid->color=DARKGREEN;
 facetid->nedges=3;                         
 facetid->edge[0]=610;                           
 facetid->edge[1]=611;      
 facetid->edge[2]=739;
 facetid++;

 facetid->color=DARKGREEN;
 facetid->nedges=3;                        
 facetid->edge[0]=611;                           
 facetid->edge[1]=612;      
 facetid->edge[2]=739;
 facetid++;

 facetid->color=DARKGREEN;
 facetid->nedges=3;                             
 facetid->edge[0]=612;                       
 facetid->edge[1]=613;      
 facetid->edge[2]=739;
 facetid++;

 facetid->color=DARKGREEN; 
 facetid->nedges=3;                           
 facetid->edge[0]=613;                           
 facetid->edge[1]=606;      
 facetid->edge[2]=739;
 facetid++;                 

 				 //++++++ Cone Outrigger 2 1    
 facetid->color=DARKGREEN;
 facetid->nedges=3;                             
 facetid->edge[0]=615;                           
 facetid->edge[1]=614;
 facetid->edge[2]=740; 
 facetid++;

 facetid->color=DARKGREEN;
 facetid->nedges=3;                          
 facetid->edge[0]=616;                   
 facetid->edge[1]=615;     
 facetid->edge[2]=740;
 facetid++;

 facetid->color=DARKGREEN;
 facetid->nedges=3;                             
 facetid->edge[0]=617;                        
 facetid->edge[1]=616;      
 facetid->edge[2]=740;
 facetid++;

 facetid->color=DARKGREEN;
 facetid->nedges=3;                           
 facetid->edge[0]=618;                           
 facetid->edge[1]=617;      
 facetid->edge[2]=740;
 facetid++;

 facetid->color=DARKGREEN;
 facetid->nedges=3;                         
 facetid->edge[0]=619;                           
 facetid->edge[1]=618;      
 facetid->edge[2]=740;
 facetid++;

 facetid->color=DARKGREEN;
 facetid->nedges=3;                        
 facetid->edge[0]=620;                           
 facetid->edge[1]=619;      
 facetid->edge[2]=740;
 facetid++;

 facetid->color=DARKGREEN;
 facetid->nedges=3;                             
 facetid->edge[0]=621;                       
 facetid->edge[1]=620;      
 facetid->edge[2]=740;
 facetid++;

 facetid->color=DARKGREEN; 
 facetid->nedges=3;                           
 facetid->edge[0]=614;                           
 facetid->edge[1]=621;      
 facetid->edge[2]=740;
 facetid++;                 

 				    //++++++ Cone Outrigger 2 1    
 facetid->color=DARKGREEN;
 facetid->nedges=3;                             
 facetid->edge[0]=622;   
 facetid->edge[1]=623;
 facetid->edge[2]=741; 
 facetid++;

 facetid->color=DARKGREEN;
 facetid->nedges=3;                          
 facetid->edge[0]=623;                   
 facetid->edge[1]=624;     
 facetid->edge[2]=741;
 facetid++;

 facetid->color=DARKGREEN;
 facetid->nedges=3;                             
 facetid->edge[0]=624;                        
 facetid->edge[1]=625;      
 facetid->edge[2]=741;
 facetid++;

 facetid->color=DARKGREEN;
 facetid->nedges=3;                           
 facetid->edge[0]=625;                           
 facetid->edge[1]=626;      
 facetid->edge[2]=741;
 facetid++;

 facetid->color=DARKGREEN;
 facetid->nedges=3;                         
 facetid->edge[0]=626;                           
 facetid->edge[1]=627;      
 facetid->edge[2]=741;
 facetid++;

 facetid->color=DARKGREEN;
 facetid->nedges=3;                        
 facetid->edge[0]=627;                           
 facetid->edge[1]=628;      
 facetid->edge[2]=741;
 facetid++;

 facetid->color=DARKGREEN;
 facetid->nedges=3;                             
 facetid->edge[0]=628;                       
 facetid->edge[1]=629;      
 facetid->edge[2]=741;
 facetid++;

 facetid->color=DARKGREEN; 
 facetid->nedges=3;                           
 facetid->edge[0]=629;                           
 facetid->edge[1]=622;      
 facetid->edge[2]=741;
 facetid++;                 
  
 				  //++++++ Cone Outrigger 1 2    
 facetid->color=DARKGREEN;
 facetid->nedges=3;                             
 facetid->edge[0]=630;                            
 facetid->edge[1]=631;
 facetid->edge[2]=742; 
 facetid++;

 facetid->color=DARKGREEN;
 facetid->nedges=3;                          
 facetid->edge[0]=631;                   
 facetid->edge[1]=632;     
 facetid->edge[2]=742;
 facetid++;

 facetid->color=DARKGREEN;
 facetid->nedges=3;                             
 facetid->edge[0]=632;                        
 facetid->edge[1]=633;      
 facetid->edge[2]=742;
 facetid++;

 facetid->color=DARKGREEN;
 facetid->nedges=3;                           
 facetid->edge[0]=633;                           
 facetid->edge[1]=634;      
 facetid->edge[2]=742;
 facetid++;

 facetid->color=DARKGREEN;
 facetid->nedges=3;                         
 facetid->edge[0]=634;                           
 facetid->edge[1]=635;      
 facetid->edge[2]=742;
 facetid++;

 facetid->color=DARKGREEN;
 facetid->nedges=3;                        
 facetid->edge[0]=635;                           
 facetid->edge[1]=636;      
 facetid->edge[2]=742;
 facetid++;

 facetid->color=DARKGREEN;
 facetid->nedges=3;                             
 facetid->edge[0]=636;                       
 facetid->edge[1]=637;      
 facetid->edge[2]=742;
 facetid++;

 facetid->color=DARKGREEN; 
 facetid->nedges=3;                           
 facetid->edge[0]=637;                           
 facetid->edge[1]=630;      
 facetid->edge[2]=742;
 facetid++;                 
  
 				    //++++++ Cone Outrigger 1 2    
 facetid->color=DARKGREEN;
 facetid->nedges=3;                             
 facetid->edge[0]=639;   
 facetid->edge[1]=638;
 facetid->edge[2]=743; 
 facetid++;

 facetid->color=DARKGREEN;
 facetid->nedges=3;                          
 facetid->edge[0]=640;                   
 facetid->edge[1]=639;     
 facetid->edge[2]=743;
 facetid++;

 facetid->color=DARKGREEN;
 facetid->nedges=3;                             
 facetid->edge[0]=641;                        
 facetid->edge[1]=640;      
 facetid->edge[2]=743;
 facetid++;

 facetid->color=DARKGREEN;
 facetid->nedges=3;                           
 facetid->edge[0]=642;                           
 facetid->edge[1]=641;      
 facetid->edge[2]=743;
 facetid++;

 facetid->color=DARKGREEN;
 facetid->nedges=3;                         
 facetid->edge[0]=643;                           
 facetid->edge[1]=642;      
 facetid->edge[2]=743;
 facetid++;

 facetid->color=DARKGREEN;
 facetid->nedges=3;                        
 facetid->edge[0]=644;                           
 facetid->edge[1]=643;      
 facetid->edge[2]=743;
 facetid++;

 facetid->color=DARKGREEN;
 facetid->nedges=3;                             
 facetid->edge[0]=645;                       
 facetid->edge[1]=644;      
 facetid->edge[2]=743;
 facetid++;

 facetid->color=DARKGREEN; 
 facetid->nedges=3;                           
 facetid->edge[0]=638;                           
 facetid->edge[1]=645;      
 facetid->edge[2]=743;
 facetid++;                 

  			       //++++++ Cone Outrigger 2 2    
 facetid->color=DARKGREEN;
 facetid->nedges=3;                             
 facetid->edge[0]=646;                            
 facetid->edge[1]=647;
 facetid->edge[2]=744; 
 facetid++;

 facetid->color=DARKGREEN;
 facetid->nedges=3;                          
 facetid->edge[0]=647;                   
 facetid->edge[1]=648;     
 facetid->edge[2]=744;
 facetid++;

 facetid->color=DARKGREEN;
 facetid->nedges=3;                             
 facetid->edge[0]=648;                        
 facetid->edge[1]=649;      
 facetid->edge[2]=744;
 facetid++;

 facetid->color=DARKGREEN;
 facetid->nedges=3;                           
 facetid->edge[0]=649;                           
 facetid->edge[1]=650;      
 facetid->edge[2]=744;
 facetid++;

 facetid->color=DARKGREEN;
 facetid->nedges=3;                         
 facetid->edge[0]=650;                           
 facetid->edge[1]=651;      
 facetid->edge[2]=744;
 facetid++;

 facetid->color=DARKGREEN;
 facetid->nedges=3;                        
 facetid->edge[0]=651;                           
 facetid->edge[1]=652;      
 facetid->edge[2]=744;
 facetid++;

 facetid->color=DARKGREEN;
 facetid->nedges=3;                             
 facetid->edge[0]=652;                       
 facetid->edge[1]=653;      
 facetid->edge[2]=744;
 facetid++;

 facetid->color=DARKGREEN; 
 facetid->nedges=3;                           
 facetid->edge[0]=653;                           
 facetid->edge[1]=646;      
 facetid->edge[2]=744;
 facetid++;                 

				   //++++++ Cone Outrigger Back 2 2    
 facetid->color=DARKGREEN;
 facetid->nedges=3;                             
 facetid->edge[0]=655;                            
 facetid->edge[1]=654;
 facetid->edge[2]=745; 
 facetid++;

 facetid->color=DARKGREEN;
 facetid->nedges=3;                          
 facetid->edge[0]=656;                   
 facetid->edge[1]=655;     
 facetid->edge[2]=745;
 facetid++;

 facetid->color=DARKGREEN;
 facetid->nedges=3;                             
 facetid->edge[0]=657;                        
 facetid->edge[1]=656;      
 facetid->edge[2]=745;
 facetid++;

 facetid->color=DARKGREEN;
 facetid->nedges=3;                           
 facetid->edge[0]=658;                           
 facetid->edge[1]=657;      
 facetid->edge[2]=745;
 facetid++;

 facetid->color=DARKGREEN;
 facetid->nedges=3;                         
 facetid->edge[0]=659;                           
 facetid->edge[1]=658;      
 facetid->edge[2]=745;
 facetid++;

 facetid->color=DARKGREEN;
 facetid->nedges=3;                        
 facetid->edge[0]=660;                           
 facetid->edge[1]=659;      
 facetid->edge[2]=745;
 facetid++;

 facetid->color=DARKGREEN;
 facetid->nedges=3;                             
 facetid->edge[0]=661;                       
 facetid->edge[1]=660;      
 facetid->edge[2]=745;
 facetid++;

 facetid->color=DARKGREEN; 
 facetid->nedges=3;                           
 facetid->edge[0]=654;                           
 facetid->edge[1]=661;      
 facetid->edge[2]=745;
 facetid++;                 

 				  //++++++ Cone Outrigger L1 3    
 facetid->color=DARKGREEN;
 facetid->nedges=3;                             
 facetid->edge[0]=670;                         
 facetid->edge[1]=671;
 facetid->edge[2]=746; 
 facetid++;

 facetid->color=DARKGREEN;
 facetid->nedges=3;                          
 facetid->edge[0]=671;                   
 facetid->edge[1]=672;     
 facetid->edge[2]=746;
 facetid++;

 facetid->color=DARKGREEN;
 facetid->nedges=3;                             
 facetid->edge[0]=672;                        
 facetid->edge[1]=673;      
 facetid->edge[2]=746;
 facetid++;

 facetid->color=DARKGREEN;
 facetid->nedges=3;                           
 facetid->edge[0]=673;                           
 facetid->edge[1]=674;      
 facetid->edge[2]=746;
 facetid++;

 facetid->color=DARKGREEN;
 facetid->nedges=3;                         
 facetid->edge[0]=674;                           
 facetid->edge[1]=675;      
 facetid->edge[2]=746;
 facetid++;

 facetid->color=DARKGREEN;
 facetid->nedges=3;                        
 facetid->edge[0]=675;                           
 facetid->edge[1]=676;      
 facetid->edge[2]=746;
 facetid++;

 facetid->color=DARKGREEN;
 facetid->nedges=3;                             
 facetid->edge[0]=676;                       
 facetid->edge[1]=677;      
 facetid->edge[2]=746;
 facetid++;

 facetid->color=DARKGREEN; 
 facetid->nedges=3;                           
 facetid->edge[0]=677;                           
 facetid->edge[1]=670;      
 facetid->edge[2]=746;
 facetid++;                 

				//++++++ Cone Outrigger Back L1 3     
 facetid->color=DARKGREEN;
 facetid->nedges=3;                             
 facetid->edge[0]=663;                            
 facetid->edge[1]=662;
 facetid->edge[2]=747; 
 facetid++;

 facetid->color=DARKGREEN;
 facetid->nedges=3;                          
 facetid->edge[0]=664;                   
 facetid->edge[1]=663;     
 facetid->edge[2]=747;
 facetid++;

 facetid->color=DARKGREEN;
 facetid->nedges=3;                             
 facetid->edge[0]=665;                        
 facetid->edge[1]=664;      
 facetid->edge[2]=747;
 facetid++;

 facetid->color=DARKGREEN;
 facetid->nedges=3;                           
 facetid->edge[0]=666;                           
 facetid->edge[1]=665;      
 facetid->edge[2]=747;
 facetid++;

 facetid->color=DARKGREEN;
 facetid->nedges=3;                         
 facetid->edge[0]=667;                           
 facetid->edge[1]=666;      
 facetid->edge[2]=747;
 facetid++;

 facetid->color=DARKGREEN;
 facetid->nedges=3;                        
 facetid->edge[0]=668;                           
 facetid->edge[1]=667;      
 facetid->edge[2]=747;
 facetid++;

 facetid->color=DARKGREEN;
 facetid->nedges=3;                             
 facetid->edge[0]=669;                       
 facetid->edge[1]=668;      
 facetid->edge[2]=747;
 facetid++;

 facetid->color=DARKGREEN; 
 facetid->nedges=3;                           
 facetid->edge[0]=662;                           
 facetid->edge[1]=669;      
 facetid->edge[2]=747;
 facetid++;                 
  
 				    //++++++ Cone Outrigger R1 3     
 facetid->color=DARKGREEN;
 facetid->nedges=3;                             
 facetid->edge[0]=686;   
 facetid->edge[1]=687;
 facetid->edge[2]=748; 
 facetid++;

 facetid->color=DARKGREEN;
 facetid->nedges=3;                          
 facetid->edge[0]=687;                   
 facetid->edge[1]=688;     
 facetid->edge[2]=748;
 facetid++;

 facetid->color=DARKGREEN;
 facetid->nedges=3;                             
 facetid->edge[0]=688;                        
 facetid->edge[1]=689;      
 facetid->edge[2]=748;
 facetid++;

 facetid->color=DARKGREEN;
 facetid->nedges=3;                           
 facetid->edge[0]=689;                           
 facetid->edge[1]=690;      
 facetid->edge[2]=748;
 facetid++;

 facetid->color=DARKGREEN;
 facetid->nedges=3;                         
 facetid->edge[0]=690;                           
 facetid->edge[1]=691;      
 facetid->edge[2]=748;
 facetid++;

 facetid->color=DARKGREEN;
 facetid->nedges=3;                        
 facetid->edge[0]=691;                           
 facetid->edge[1]=692;      
 facetid->edge[2]=748;
 facetid++;

 facetid->color=DARKGREEN;
 facetid->nedges=3;                             
 facetid->edge[0]=692;                       
 facetid->edge[1]=693;      
 facetid->edge[2]=748;
 facetid++;

 facetid->color=DARKGREEN; 
 facetid->nedges=3;                           
 facetid->edge[0]=693;                           
 facetid->edge[1]=686;      
 facetid->edge[2]=748;
 facetid++;                 

				//++++++ Cone Outrigger Back R1 3    
 facetid->color=DARKGREEN;
 facetid->nedges=3;                             
 facetid->edge[0]=679;   
 facetid->edge[1]=678;
 facetid->edge[2]=749; 
 facetid++;

 facetid->color=DARKGREEN;
 facetid->nedges=3;                          
 facetid->edge[0]=680;                   
 facetid->edge[1]=679;     
 facetid->edge[2]=749;
 facetid++;

 facetid->color=DARKGREEN;
 facetid->nedges=3;                             
 facetid->edge[0]=681;                        
 facetid->edge[1]=680;      
 facetid->edge[2]=749;
 facetid++;

 facetid->color=DARKGREEN;
 facetid->nedges=3;                           
 facetid->edge[0]=682;                           
 facetid->edge[1]=681;      
 facetid->edge[2]=749;
 facetid++;

 facetid->color=DARKGREEN;
 facetid->nedges=3;                         
 facetid->edge[0]=683;                           
 facetid->edge[1]=682;      
 facetid->edge[2]=749;
 facetid++;

 facetid->color=DARKGREEN;
 facetid->nedges=3;                        
 facetid->edge[0]=684;                           
 facetid->edge[1]=683;      
 facetid->edge[2]=749;
 facetid++;

 facetid->color=DARKGREEN;
 facetid->nedges=3;                             
 facetid->edge[0]=685;                       
 facetid->edge[1]=684;      
 facetid->edge[2]=749;
 facetid++;

 facetid->color=DARKGREEN; 
 facetid->nedges=3;                           
 facetid->edge[0]=678;                           
 facetid->edge[1]=685;      
 facetid->edge[2]=749;
 facetid++;                 

				    //++++++ Cone Outrigger  R1 4     
 facetid->color=DARKGREEN;
 facetid->nedges=3;                             
 facetid->edge[0]=703;   
 facetid->edge[1]=702;
 facetid->edge[2]=750; 
 facetid++;

 facetid->color=DARKGREEN;
 facetid->nedges=3;                          
 facetid->edge[0]=704;                   
 facetid->edge[1]=703;     
 facetid->edge[2]=750;
 facetid++;

 facetid->color=DARKGREEN;
 facetid->nedges=3;                             
 facetid->edge[0]=705;                        
 facetid->edge[1]=704;      
 facetid->edge[2]=750;
 facetid++;

 facetid->color=DARKGREEN;
 facetid->nedges=3;                           
 facetid->edge[0]=706;                           
 facetid->edge[1]=705;      
 facetid->edge[2]=750;
 facetid++;

 facetid->color=DARKGREEN;
 facetid->nedges=3;                         
 facetid->edge[0]=707;                           
 facetid->edge[1]=706;      
 facetid->edge[2]=750;
 facetid++;

 facetid->color=DARKGREEN;
 facetid->nedges=3;                        
 facetid->edge[0]=708;                           
 facetid->edge[1]=707;      
 facetid->edge[2]=750;
 facetid++;

 facetid->color=DARKGREEN;
 facetid->nedges=3;                             
 facetid->edge[0]=709;                       
 facetid->edge[1]=708;      
 facetid->edge[2]=750;
 facetid++;

 facetid->color=DARKGREEN; 
 facetid->nedges=3;                           
 facetid->edge[0]=702;                           
 facetid->edge[1]=709;      
 facetid->edge[2]=750;
 facetid++;                 

				    //++++++ Cone Outrigger Back R1 4    
 facetid->color=DARKGREEN;
 facetid->nedges=3;                             
 facetid->edge[0]=694;                            
 facetid->edge[1]=695;
 facetid->edge[2]=751; 
 facetid++;

 facetid->color=DARKGREEN;
 facetid->nedges=3;                          
 facetid->edge[0]=695;                   
 facetid->edge[1]=696;     
 facetid->edge[2]=751;
 facetid++;

 facetid->color=DARKGREEN;
 facetid->nedges=3;                             
 facetid->edge[0]=696;                        
 facetid->edge[1]=697;      
 facetid->edge[2]=751;
 facetid++;

 facetid->color=DARKGREEN;
 facetid->nedges=3;                           
 facetid->edge[0]=697;                           
 facetid->edge[1]=698;      
 facetid->edge[2]=751;
 facetid++;

 facetid->color=DARKGREEN;
 facetid->nedges=3;                         
 facetid->edge[0]=698;                           
 facetid->edge[1]=699;      
 facetid->edge[2]=751;
 facetid++;

 facetid->color=DARKGREEN;
 facetid->nedges=3;                        
 facetid->edge[0]=699;                           
 facetid->edge[1]=700;      
 facetid->edge[2]=751;
 facetid++;

 facetid->color=DARKGREEN;
 facetid->nedges=3;                             
 facetid->edge[0]=700;                       
 facetid->edge[1]=701;      
 facetid->edge[2]=751;
 facetid++;

 facetid->color=DARKGREEN; 
 facetid->nedges=3;                           
 facetid->edge[0]=701;                           
 facetid->edge[1]=694;      
 facetid->edge[2]=751;
 facetid++;                 

				//++++++ Cone Outrigger L 1 4     
 facetid->color=DARKGREEN;
 facetid->nedges=3;                             
 facetid->edge[0]=719;                         
 facetid->edge[1]=718;
 facetid->edge[2]=752; 
 facetid++;

 facetid->color=DARKGREEN;
 facetid->nedges=3;                          
 facetid->edge[0]=720;                   
 facetid->edge[1]=719;     
 facetid->edge[2]=752;
 facetid++;

 facetid->color=DARKGREEN;
 facetid->nedges=3;                             
 facetid->edge[0]=721;                        
 facetid->edge[1]=720;      
 facetid->edge[2]=752;
 facetid++;

 facetid->color=DARKGREEN;
 facetid->nedges=3;                           
 facetid->edge[0]=722;                           
 facetid->edge[1]=721;      
 facetid->edge[2]=752;
 facetid++;

 facetid->color=DARKGREEN;
 facetid->nedges=3;                         
 facetid->edge[0]=723;                           
 facetid->edge[1]=722;      
 facetid->edge[2]=752;
 facetid++;

 facetid->color=DARKGREEN;
 facetid->nedges=3;                        
 facetid->edge[0]=724;                           
 facetid->edge[1]=723;      
 facetid->edge[2]=752;
 facetid++;

 facetid->color=DARKGREEN;
 facetid->nedges=3;                             
 facetid->edge[0]=725;                       
 facetid->edge[1]=724;      
 facetid->edge[2]=752;
 facetid++;

 facetid->color=DARKGREEN; 
 facetid->nedges=3;                           
 facetid->edge[0]=718;                           
 facetid->edge[1]=725;      
 facetid->edge[2]=752;
 facetid++;                 
 
				   //++++++ Cone Outrigger Back L 1 4     
 facetid->color=DARKGREEN;
 facetid->nedges=3;                             
 facetid->edge[0]=710;                            
 facetid->edge[1]=711;
 facetid->edge[2]=753; 
 facetid++;

 facetid->color=DARKGREEN;
 facetid->nedges=3;                          
 facetid->edge[0]=711;                   
 facetid->edge[1]=712;     
 facetid->edge[2]=753;
 facetid++;

 facetid->color=DARKGREEN;
 facetid->nedges=3;                             
 facetid->edge[0]=712;                        
 facetid->edge[1]=713;      
 facetid->edge[2]=753;
 facetid++;

 facetid->color=DARKGREEN;
 facetid->nedges=3;                           
 facetid->edge[0]=713;                           
 facetid->edge[1]=714;      
 facetid->edge[2]=753;
 facetid++;

 facetid->color=DARKGREEN;
 facetid->nedges=3;                         
 facetid->edge[0]=714;                           
 facetid->edge[1]=715;      
 facetid->edge[2]=753;
 facetid++;

 facetid->color=DARKGREEN;
 facetid->nedges=3;                        
 facetid->edge[0]=715;                           
 facetid->edge[1]=716;      
 facetid->edge[2]=753;
 facetid++;

 facetid->color=DARKGREEN;
 facetid->nedges=3;                             
 facetid->edge[0]=716;                       
 facetid->edge[1]=717;      
 facetid->edge[2]=753;
 facetid++;

 facetid->color=DARKGREEN; 
 facetid->nedges=3;                           
 facetid->edge[0]=717;                           
 facetid->edge[1]=710;      
 facetid->edge[2]=753;
 facetid++;                 

 //facetid->color=WHITE;    //++++++++++++ S UNDER R1 1   
 //facetid->nedges=8; 
 //facetid->edge[0]=754;
 //facetid->edge[1]=755;
 //facetid->edge[2]=756;
 //facetid->edge[3]=757;            
 //facetid->edge[4]=758;
 //facetid->edge[5]=759;
 //facetid->edge[6]=760;
 //facetid->edge[7]=761;
 //facetid++;

 facetid->color=DARKGREEN;
 facetid->nedges=4;                             
 facetid->edge[0]=754;                          
 facetid->edge[1]=755;        
 facetid->edge[2]=763; 
 facetid->edge[3]=762;
 facetid++;

 facetid->color=DARKGREEN;
 facetid->nedges=4;                          
 facetid->edge[0]=755;                           
 facetid->edge[1]=756;      
 facetid->edge[2]=764;
 facetid->edge[3]=763;
 facetid++;

 facetid->color=DARKGREEN;
 facetid->nedges=4;                             
 facetid->edge[0]=756;                        
 facetid->edge[1]=757;      
 facetid->edge[2]=765;
 facetid->edge[3]=764;
 facetid++;

 facetid->color=DARKGREEN;
 facetid->nedges=4;                           
 facetid->edge[0]=757;                           
 facetid->edge[1]=758;      
 facetid->edge[2]=766;
 facetid->edge[3]=765;
 facetid++;

 facetid->color=DARKGREEN;
 facetid->nedges=4;                         
 facetid->edge[0]=758;                           
 facetid->edge[1]=759;      
 facetid->edge[2]=767;
 facetid->edge[3]=766;
 facetid++;

 facetid->color=DARKGREEN;
 facetid->nedges=4;                        
 facetid->edge[0]=759;                           
 facetid->edge[1]=760;      
 facetid->edge[2]=768;
 facetid->edge[3]=767;
 facetid++;

 facetid->color=DARKGREEN; 
 facetid->nedges=4;                             
 facetid->edge[0]=760;                       
 facetid->edge[1]=761;      
 facetid->edge[2]=769;
 facetid->edge[3]=768;
 facetid++;

 facetid->color=DARKGREEN;
 facetid->nedges=4;                           
 facetid->edge[0]=761;                           
 facetid->edge[1]=754;      
 facetid->edge[2]=762;
 facetid->edge[3]=769;
 facetid++;                    

 //facetid->color=WHITE;    //+++++++++++++ S UNDER 2 1   
 //facetid->nedges=8; 
 //facetid->edge[0]=770;
 //facetid->edge[1]=771;
 //facetid->edge[2]=772;
 //facetid->edge[3]=773;            
 //facetid->edge[4]=774;
 //facetid->edge[5]=775;
 //facetid->edge[6]=776;
 //facetid->edge[7]=777;
 //facetid++;

 facetid->color=DARKGREEN;
 facetid->nedges=4;                             
 facetid->edge[0]=770;                          
 facetid->edge[1]=771;        
 facetid->edge[2]=779; 
 facetid->edge[3]=778;
 facetid++;

 facetid->color=DARKGREEN;
 facetid->nedges=4;                          
 facetid->edge[0]=771;                           
 facetid->edge[1]=772;      
 facetid->edge[2]=780;
 facetid->edge[3]=779;
 facetid++;

 facetid->color=DARKGREEN;
 facetid->nedges=4;                             
 facetid->edge[0]=772;                        
 facetid->edge[1]=773;      
 facetid->edge[2]=781;
 facetid->edge[3]=780;
 facetid++;

 facetid->color=DARKGREEN;
 facetid->nedges=4;                           
 facetid->edge[0]=773;                           
 facetid->edge[1]=774;      
 facetid->edge[2]=782;
 facetid->edge[3]=781;
 facetid++;

 facetid->color=DARKGREEN;
 facetid->nedges=4;                         
 facetid->edge[0]=774;                           
 facetid->edge[1]=775;      
 facetid->edge[2]=783;
 facetid->edge[3]=782;
 facetid++;

 facetid->color=DARKGREEN;
 facetid->nedges=4;                        
 facetid->edge[0]=775;                           
 facetid->edge[1]=776;      
 facetid->edge[2]=784;
 facetid->edge[3]=783;
 facetid++;

 facetid->color=DARKGREEN; 
 facetid->nedges=4;                             
 facetid->edge[0]=776;                      
 facetid->edge[1]=777;      
 facetid->edge[2]=785;
 facetid->edge[3]=784;
 facetid++;

 facetid->color=DARKGREEN;
 facetid->nedges=4;                           
 facetid->edge[0]=777;                           
 facetid->edge[1]=770;      
 facetid->edge[2]=778;
 facetid->edge[3]=785;
 facetid++;                    

 //facetid->color=WHITE;    //+++++++++++++++ S UNDER 1 2
 //facetid->nedges=8; 
 //facetid->edge[0]=786;
 //facetid->edge[1]=787;
 //facetid->edge[2]=788;
 //facetid->edge[3]=789;            
 //facetid->edge[4]=790;
 //facetid->edge[5]=791;
 //facetid->edge[6]=792;
 //facetid->edge[7]=793;
 //facetid++;

 facetid->color=DARKGREEN;
 facetid->nedges=4;                             
 facetid->edge[0]=794;                         
 facetid->edge[1]=795;        
 facetid->edge[2]=787; 
 facetid->edge[3]=786;
 facetid++;

 facetid->color=DARKGREEN;
 facetid->nedges=4;                          
 facetid->edge[0]=795;                           
 facetid->edge[1]=796;      
 facetid->edge[2]=788;
 facetid->edge[3]=787;
 facetid++;

 facetid->color=DARKGREEN;
 facetid->nedges=4;                             
 facetid->edge[0]=796;                        
 facetid->edge[1]=797;      
 facetid->edge[2]=789;
 facetid->edge[3]=788;
 facetid++;

 facetid->color=DARKGREEN;
 facetid->nedges=4;                           
 facetid->edge[0]=797;                           
 facetid->edge[1]=798;      
 facetid->edge[2]=790;
 facetid->edge[3]=789;
 facetid++;

 facetid->color=DARKGREEN;
 facetid->nedges=4;                         
 facetid->edge[0]=798;                           
 facetid->edge[1]=799;      
 facetid->edge[2]=791;
 facetid->edge[3]=790;
 facetid++;

 facetid->color=DARKGREEN;
 facetid->nedges=4;                        
 facetid->edge[0]=799;                           
 facetid->edge[1]=800;      
 facetid->edge[2]=792;
 facetid->edge[3]=791;
 facetid++;

 facetid->color=DARKGREEN; 
 facetid->nedges=4;                             
 facetid->edge[0]=800;                       
 facetid->edge[1]=801;      
 facetid->edge[2]=793;
 facetid->edge[3]=792;
 facetid++;

 facetid->color=DARKGREEN;
 facetid->nedges=4;                           
 facetid->edge[0]=801;                           
 facetid->edge[1]=794;      
 facetid->edge[2]=786;
 facetid->edge[3]=793;
 facetid++;                    
 
 //facetid->color=WHITE;    //++++++++++++ S UNDER 2 2   
 //facetid->nedges=8; 
 //facetid->edge[0]=802;
 //facetid->edge[1]=803;
 //facetid->edge[2]=804;
 //facetid->edge[3]=805;            
 //facetid->edge[4]=806;
 //facetid->edge[5]=807;
 //facetid->edge[6]=808;
 //facetid->edge[7]=809;
 //facetid++;

 facetid->color=DARKGREEN;
 facetid->nedges=4;                             
 facetid->edge[0]=810;                          
 facetid->edge[1]=811;        
 facetid->edge[2]=803; 
 facetid->edge[3]=802;
 facetid++;

 facetid->color=DARKGREEN;
 facetid->nedges=4;                          
 facetid->edge[0]=811;                           
 facetid->edge[1]=812;      
 facetid->edge[2]=804;
 facetid->edge[3]=803;
 facetid++;

 facetid->color=DARKGREEN;
 facetid->nedges=4;                             
 facetid->edge[0]=812;                        
 facetid->edge[1]=813;      
 facetid->edge[2]=805;
 facetid->edge[3]=804;
 facetid++;

 facetid->color=DARKGREEN;
 facetid->nedges=4;                           
 facetid->edge[0]=813;                           
 facetid->edge[1]=814;      
 facetid->edge[2]=806;
 facetid->edge[3]=805;
 facetid++;

 facetid->color=DARKGREEN;
 facetid->nedges=4;                         
 facetid->edge[0]=814;                           
 facetid->edge[1]=815;      
 facetid->edge[2]=807;
 facetid->edge[3]=806;
 facetid++;

 facetid->color=DARKGREEN;
 facetid->nedges=4;                        
 facetid->edge[0]=815;                           
 facetid->edge[1]=816;      
 facetid->edge[2]=808;
 facetid->edge[3]=807;
 facetid++;

 facetid->color=DARKGREEN; 
 facetid->nedges=4;                             
 facetid->edge[0]=816;                      
 facetid->edge[1]=817;      
 facetid->edge[2]=809;
 facetid->edge[3]=808;
 facetid++;

 facetid->color=DARKGREEN;
 facetid->nedges=4;                           
 facetid->edge[0]=817;                           
 facetid->edge[1]=810;      
 facetid->edge[2]=802;
 facetid->edge[3]=809;
 facetid++;                    

 //facetid->color=WHITE;    //+++++++ S UNDER L1 3   
 //facetid->nedges=8;             
 //facetid->edge[0]=818;
 //facetid->edge[1]=819;
 //facetid->edge[2]=820;
 //facetid->edge[3]=821;            
 //facetid->edge[4]=822;
 //facetid->edge[5]=823;
 //facetid->edge[6]=824;
 //facetid->edge[7]=825;
 //facetid++;

 facetid->color=DARKGREEN;
 facetid->nedges=4;                             
 facetid->edge[0]=818;                         
 facetid->edge[1]=819;        
 facetid->edge[2]=827; 
 facetid->edge[3]=826;
 facetid++;

 facetid->color=DARKGREEN;
 facetid->nedges=4;                          
 facetid->edge[0]=819;                           
 facetid->edge[1]=820;      
 facetid->edge[2]=828;
 facetid->edge[3]=827;
 facetid++;

 facetid->color=DARKGREEN;
 facetid->nedges=4;                             
 facetid->edge[0]=820;                        
 facetid->edge[1]=821;      
 facetid->edge[2]=829;
 facetid->edge[3]=828;
 facetid++;

 facetid->color=DARKGREEN;
 facetid->nedges=4;                           
 facetid->edge[0]=821;                           
 facetid->edge[1]=822;      
 facetid->edge[2]=830;
 facetid->edge[3]=829;
 facetid++;

 facetid->color=DARKGREEN;
 facetid->nedges=4;                         
 facetid->edge[0]=822;                           
 facetid->edge[1]=823;      
 facetid->edge[2]=831;
 facetid->edge[3]=830;
 facetid++;

 facetid->color=DARKGREEN;
 facetid->nedges=4;                        
 facetid->edge[0]=823;                           
 facetid->edge[1]=824;      
 facetid->edge[2]=832;
 facetid->edge[3]=831;
 facetid++;

 facetid->color=DARKGREEN; 
 facetid->nedges=4;                             
 facetid->edge[0]=824;                       
 facetid->edge[1]=825;      
 facetid->edge[2]=833;
 facetid->edge[3]=832;
 facetid++;

 facetid->color=DARKGREEN;
 facetid->nedges=4;                           
 facetid->edge[0]=825;                           
 facetid->edge[1]=818;      
 facetid->edge[2]=826;
 facetid->edge[3]=833;
 facetid++;                    
 
 //facetid->color=WHITE;    //++++++ S R2 3 
 //facetid->nedges=8;          
 //facetid->edge[0]=834;
 //facetid->edge[1]=835;
 //facetid->edge[2]=836;
 //facetid->edge[3]=837;            
 //facetid->edge[4]=838;
 //facetid->edge[5]=839;
 //facetid->edge[6]=840;
 //facetid->edge[7]=841;
 //facetid++;

 facetid->color=DARKGREEN;
 facetid->nedges=4;                             
 facetid->edge[0]=834;                          
 facetid->edge[1]=835;   
 facetid->edge[2]=843; 
 facetid->edge[3]=842;
 facetid++;

 facetid->color=DARKGREEN;
 facetid->nedges=4;                          
 facetid->edge[0]=835;                     
 facetid->edge[1]=836;      
 facetid->edge[2]=844;
 facetid->edge[3]=843;
 facetid++;

 facetid->color=DARKGREEN;
 facetid->nedges=4;                             
 facetid->edge[0]=836;                        
 facetid->edge[1]=837;  
 facetid->edge[2]=845;
 facetid->edge[3]=844;
 facetid++;

 facetid->color=DARKGREEN;
 facetid->nedges=4;                           
 facetid->edge[0]=837;                      
 facetid->edge[1]=838;      
 facetid->edge[2]=846;
 facetid->edge[3]=845;
 facetid++;

 facetid->color=DARKGREEN;
 facetid->nedges=4;                         
 facetid->edge[0]=838;                     
 facetid->edge[1]=839;      
 facetid->edge[2]=847;
 facetid->edge[3]=846;
 facetid++;

 facetid->color=DARKGREEN;
 facetid->nedges=4;                        
 facetid->edge[0]=839;                           
 facetid->edge[1]=840;   
 facetid->edge[2]=848;
 facetid->edge[3]=847;
 facetid++;

 facetid->color=DARKGREEN;
 facetid->nedges=4;                             
 facetid->edge[0]=840;                       
 facetid->edge[1]=841;  
 facetid->edge[2]=849;
 facetid->edge[3]=848;
 facetid++;

 facetid->color=DARKGREEN;
 facetid->nedges=4;                           
 facetid->edge[0]=841;                           
 facetid->edge[1]=834;      
 facetid->edge[2]=842;
 facetid->edge[3]=849;
 facetid++;                 

 //facetid->color=WHITE;    //++++++ S 1 4   
 //facetid->nedges=8;      
 //facetid->edge[0]=850;
 //facetid->edge[1]=851;
 //facetid->edge[2]=852;
 //facetid->edge[3]=853;            
 //facetid->edge[4]=854;
 //facetid->edge[5]=855;
 //facetid->edge[6]=856;
 //facetid->edge[7]=857;
 //facetid++;

 facetid->color=DARKGREEN;
 facetid->nedges=4;                             
 facetid->edge[0]=851;                          
 facetid->edge[1]=850;   
 facetid->edge[2]=858; 
 facetid->edge[3]=859;
 facetid++;

 facetid->color=DARKGREEN;
 facetid->nedges=4;                          
 facetid->edge[0]=852;                     
 facetid->edge[1]=851;      
 facetid->edge[2]=859;
 facetid->edge[3]=860;
 facetid++;

 facetid->color=DARKGREEN;
 facetid->nedges=4;                             
 facetid->edge[0]=853;                        
 facetid->edge[1]=852;  
 facetid->edge[2]=860;
 facetid->edge[3]=861;
 facetid++;

 facetid->color=DARKGREEN;
 facetid->nedges=4;                           
 facetid->edge[0]=854;                      
 facetid->edge[1]=853;      
 facetid->edge[2]=861;
 facetid->edge[3]=862;
 facetid++;

 facetid->color=DARKGREEN;
 facetid->nedges=4;                         
 facetid->edge[0]=855;                     
 facetid->edge[1]=854;      
 facetid->edge[2]=862;
 facetid->edge[3]=863;
 facetid++;

 facetid->color=DARKGREEN;
 facetid->nedges=4;                        
 facetid->edge[0]=856;                           
 facetid->edge[1]=855;   
 facetid->edge[2]=863;
 facetid->edge[3]=864;
 facetid++;

 facetid->color=DARKGREEN;
 facetid->nedges=4;                             
 facetid->edge[0]=857;                       
 facetid->edge[1]=856;  
 facetid->edge[2]=864;
 facetid->edge[3]=865;
 facetid++;

 facetid->color=DARKGREEN;
 facetid->nedges=4;                           
 facetid->edge[0]=865;                          
 facetid->edge[1]=858;    
 facetid->edge[2]=850;
 facetid->edge[3]=857;
 facetid++;                 
 
 //facetid->color=WHITE;    //++++++ S R2 4   
 //facetid->nedges=8;        
 //facetid->edge[0]=866;
 //facetid->edge[1]=867;
 //facetid->edge[2]=868;
 //facetid->edge[3]=869;            
 //facetid->edge[4]=870;
 //facetid->edge[5]=871;
 //facetid->edge[6]=872;
 //facetid->edge[7]=873;
 //facetid++;

 facetid->color=DARKGREEN;
 facetid->nedges=4;                             
 facetid->edge[0]=867;                          
 facetid->edge[1]=866;   
 facetid->edge[2]=874; 
 facetid->edge[3]=875;
 facetid++;

 facetid->color=DARKGREEN;
 facetid->nedges=4;                          
 facetid->edge[0]=868;                     
 facetid->edge[1]=867;      
 facetid->edge[2]=875;
 facetid->edge[3]=876;
 facetid++;

 facetid->color=DARKGREEN;
 facetid->nedges=4;                             
 facetid->edge[0]=869;                        
 facetid->edge[1]=868;  
 facetid->edge[2]=876;
 facetid->edge[3]=877;
 facetid++;

 facetid->color=DARKGREEN;
 facetid->nedges=4;                           
 facetid->edge[0]=870;                      
 facetid->edge[1]=869;      
 facetid->edge[2]=877;
 facetid->edge[3]=878;
 facetid++;

 facetid->color=DARKGREEN;
 facetid->nedges=4;                         
 facetid->edge[0]=871;                     
 facetid->edge[1]=870;      
 facetid->edge[2]=878;
 facetid->edge[3]=879;
 facetid++;

 facetid->color=DARKGREEN;
 facetid->nedges=4;                        
 facetid->edge[0]=872;                           
 facetid->edge[1]=871;   
 facetid->edge[2]=879;
 facetid->edge[3]=880;
 facetid++;

 facetid->color=DARKGREEN;
 facetid->nedges=4;                             
 facetid->edge[0]=873;                       
 facetid->edge[1]=872;  
 facetid->edge[2]=880;
 facetid->edge[3]=881;
 facetid++;

 facetid->color=DARKGREEN;
 facetid->nedges=4;                           
 facetid->edge[0]=881;                          
 facetid->edge[1]=874;    
 facetid->edge[2]=866;
 facetid->edge[3]=873;
 facetid++;                 
 
				//++++++ Cone Landing Gear 1   
 facetid->color=BLUE;
 facetid->nedges=3;                             
 facetid->edge[0]=1635;                         
 facetid->edge[1]=1636;
 facetid->edge[2]=882;
 facetid++;

 facetid->color=BLUE;
 facetid->nedges=3;                          
 facetid->edge[0]=1636;                   
 facetid->edge[1]=1637;     
 facetid->edge[2]=882;
 facetid++;

 facetid->color=BLUE;
 facetid->nedges=3;                             
 facetid->edge[0]=1637;                        
 facetid->edge[1]=1638;      
 facetid->edge[2]=882;
 facetid++;

 facetid->color=BLUE;
 facetid->nedges=3;                           
 facetid->edge[0]=1638;                           
 facetid->edge[1]=1639;      
 facetid->edge[2]=882;
 facetid++;

 facetid->color=BLUE;
 facetid->nedges=3;                         
 facetid->edge[0]=1639;                           
 facetid->edge[1]=1640;      
 facetid->edge[2]=882;
 facetid++;

 facetid->color=BLUE;
 facetid->nedges=3;                        
 facetid->edge[0]=1640;                          
 facetid->edge[1]=1641;      
 facetid->edge[2]=882;
 facetid++;

 facetid->color=BLUE;
 facetid->nedges=3;                             
 facetid->edge[0]=1641;                       
 facetid->edge[1]=1642;      
 facetid->edge[2]=882;
 facetid++;

 facetid->color=BLUE;
 facetid->nedges=3;                           
 facetid->edge[0]=1642;                           
 facetid->edge[1]=1635;      
 facetid->edge[2]=882;
 facetid++;                 

			    //++++++ Cone Landing Gear 2    
 facetid->color=BLUE;
 facetid->nedges=3;                             
 facetid->edge[0]=1651; 
 facetid->edge[1]=1652;
 facetid->edge[2]=883; 
 facetid++;

 facetid->color=BLUE;
 facetid->nedges=3;                          
 facetid->edge[0]=1652;                   
 facetid->edge[1]=1653;    
 facetid->edge[2]=883;
 facetid++;

 facetid->color=BLUE;
 facetid->nedges=3;                             
 facetid->edge[0]=1653;                       
 facetid->edge[1]=1654;    
 facetid->edge[2]=883;
 facetid++;

 facetid->color=BLUE;
 facetid->nedges=3;                           
 facetid->edge[0]=1654;                          
 facetid->edge[1]=1655;     
 facetid->edge[2]=883;
 facetid++;

 facetid->color=BLUE;
 facetid->nedges=3;                         
 facetid->edge[0]=1655;                          
 facetid->edge[1]=1656;     
 facetid->edge[2]=883;
 facetid++;

 facetid->color=BLUE;
 facetid->nedges=3;                        
 facetid->edge[0]=1656;                         
 facetid->edge[1]=1657;    
 facetid->edge[2]=883;
 facetid++;

 facetid->color=BLUE;
 facetid->nedges=3;                             
 facetid->edge[0]=1657;		                      
 facetid->edge[1]=1658;    
 facetid->edge[2]=883;
 facetid++;

 facetid->color=BLUE; 
 facetid->nedges=3;                           
 facetid->edge[0]=1658;                           
 facetid->edge[1]=1651;    
 facetid->edge[2]=883;
 facetid++;                 

			    //++++++ Cone Landing Gear 3    
 facetid->color=BLUE;
 facetid->nedges=3;                              
 facetid->edge[0]=1667;                                                       
 facetid->edge[1]=1668;
 facetid->edge[2]=884; 
 facetid++;

 facetid->color=BLUE;
 facetid->nedges=3;                          
 facetid->edge[0]=1668;                   
 facetid->edge[1]=1669;     
 facetid->edge[2]=884;
 facetid++;

 facetid->color=BLUE;
 facetid->nedges=3;                             
 facetid->edge[0]=1669;                        
 facetid->edge[1]=1670;      
 facetid->edge[2]=884;
 facetid++;

 facetid->color=BLUE;
 facetid->nedges=3;                           
 facetid->edge[0]=1670;                           
 facetid->edge[1]=1671;      
 facetid->edge[2]=884;
 facetid++;

 facetid->color=BLUE;
 facetid->nedges=3;                         
 facetid->edge[0]=1671;                           
 facetid->edge[1]=1672;      
 facetid->edge[2]=884;
 facetid++;

 facetid->color=BLUE;
 facetid->nedges=3;                        
 facetid->edge[0]=1672;                           
 facetid->edge[1]=1673;      
 facetid->edge[2]=884;
 facetid++;

 facetid->color=BLUE;
 facetid->nedges=3;                             
 facetid->edge[0]=1673;                       
 facetid->edge[1]=1674;      
 facetid->edge[2]=884;
 facetid++;

 facetid->color=BLUE; 
 facetid->nedges=3;                           
 facetid->edge[0]=1674;                          
 facetid->edge[1]=1667;     
 facetid->edge[2]=884;
 facetid++;                 
 
			    //++++++ Cone Landing Gear 4    
 facetid->color=BLUE;
 facetid->nedges=3;                             
 facetid->edge[0]=1683;                            
 facetid->edge[1]=1684;
 facetid->edge[2]=885; 
 facetid++;

 facetid->color=BLUE;
 facetid->nedges=3;                          
 facetid->edge[0]=1684;                   
 facetid->edge[1]=1685;     
 facetid->edge[2]=885;
 facetid++;

 facetid->color=BLUE;
 facetid->nedges=3;                             
 facetid->edge[0]=1685;                        
 facetid->edge[1]=1686;      
 facetid->edge[2]=885;
 facetid++;

 facetid->color=BLUE;
 facetid->nedges=3;                           
 facetid->edge[0]=1686;                           
 facetid->edge[1]=1687;      
 facetid->edge[2]=885;
 facetid++;

 facetid->color=BLUE;
 facetid->nedges=3;                         
 facetid->edge[0]=1687;                           
 facetid->edge[1]=1688;      
 facetid->edge[2]=885;
 facetid++;

 facetid->color=BLUE;
 facetid->nedges=3;                        
 facetid->edge[0]=1688;                           
 facetid->edge[1]=1689;      
 facetid->edge[2]=885;
 facetid++;

 facetid->color=BLUE;
 facetid->nedges=3;                             
 facetid->edge[0]=1689;                       
 facetid->edge[1]=1690;      
 facetid->edge[2]=885;
 facetid++;

 facetid->color=BLUE; 
 facetid->nedges=3;                           
 facetid->edge[0]=1690;                           
 facetid->edge[1]=1683;      
 facetid->edge[2]=885;
 facetid++;                 

				  //++++++ Cone For Under Outrigger 1 1   
 facetid->color=DARKGREEN;
 facetid->nedges=3;                             
 facetid->edge[0]=755;                           
 facetid->edge[1]=754;
 facetid->edge[2]=886; 
 facetid++;

 facetid->color=DARKGREEN;
 facetid->nedges=3;                          
 facetid->edge[0]=756;                   
 facetid->edge[1]=755;     
 facetid->edge[2]=886;
 facetid++;

 facetid->color=DARKGREEN;
 facetid->nedges=3;                             
 facetid->edge[0]=757;                        
 facetid->edge[1]=756;      
 facetid->edge[2]=886;
 facetid++;

 facetid->color=DARKGREEN;
 facetid->nedges=3;                           
 facetid->edge[0]=758;                           
 facetid->edge[1]=757;      
 facetid->edge[2]=886;
 facetid++;

 facetid->color=DARKGREEN;
 facetid->nedges=3;                         
 facetid->edge[0]=759;                           
 facetid->edge[1]=758;      
 facetid->edge[2]=886;
 facetid++;

 facetid->color=DARKGREEN;
 facetid->nedges=3;                        
 facetid->edge[0]=760;                           
 facetid->edge[1]=759;      
 facetid->edge[2]=886;
 facetid++;

 facetid->color=DARKGREEN;
 facetid->nedges=3;                             
 facetid->edge[0]=761;                       
 facetid->edge[1]=760;      
 facetid->edge[2]=886;
 facetid++;

 facetid->color=DARKGREEN;
 facetid->nedges=3;                           
 facetid->edge[0]=754;                           
 facetid->edge[1]=761;      
 facetid->edge[2]=886;
 facetid++;                 

				   //++++++ Cone For Under Outrigger 2 1     
 facetid->color=DARKGREEN;
 facetid->nedges=3;                            
 facetid->edge[0]=771;                           
 facetid->edge[1]=770;
 facetid->edge[2]=887; 
 facetid++;

 facetid->color=DARKGREEN;
 facetid->nedges=3;                          
 facetid->edge[0]=772;                   
 facetid->edge[1]=771;     
 facetid->edge[2]=887;
 facetid++;

 facetid->color=DARKGREEN;
 facetid->nedges=3;                             
 facetid->edge[0]=773;                        
 facetid->edge[1]=772;      
 facetid->edge[2]=887;
 facetid++;

 facetid->color=DARKGREEN;
 facetid->nedges=3;                           
 facetid->edge[0]=774;                           
 facetid->edge[1]=773;      
 facetid->edge[2]=887;
 facetid++;

 facetid->color=DARKGREEN;
 facetid->nedges=3;                         
 facetid->edge[0]=775;                           
 facetid->edge[1]=774;      
 facetid->edge[2]=887;
 facetid++;

 facetid->color=DARKGREEN;
 facetid->nedges=3;                        
 facetid->edge[0]=776;                           
 facetid->edge[1]=775;      
 facetid->edge[2]=887;
 facetid++;

 facetid->color=DARKGREEN;
 facetid->nedges=3;                             
 facetid->edge[0]=777;                       
 facetid->edge[1]=776;      
 facetid->edge[2]=887;
 facetid++;

 facetid->color=DARKGREEN; 
 facetid->nedges=3;                           
 facetid->edge[0]=770;                           
 facetid->edge[1]=777;      
 facetid->edge[2]=887;
 facetid++;                 
  
				   //++++++ Cone For Under Outrigger 1 2     
 facetid->color=DARKGREEN;
 facetid->nedges=3;                            
 facetid->edge[0]=786;                           
 facetid->edge[1]=787;
 facetid->edge[2]=888; 
 facetid++;

 facetid->color=DARKGREEN;
 facetid->nedges=3;                          
 facetid->edge[0]=787;                   
 facetid->edge[1]=788;     
 facetid->edge[2]=888;
 facetid++;

 facetid->color=DARKGREEN;
 facetid->nedges=3;                             
 facetid->edge[0]=788;                        
 facetid->edge[1]=789;      
 facetid->edge[2]=888;
 facetid++;

 facetid->color=DARKGREEN;
 facetid->nedges=3;                           
 facetid->edge[0]=789;                           
 facetid->edge[1]=790;      
 facetid->edge[2]=888;
 facetid++;

 facetid->color=DARKGREEN;
 facetid->nedges=3;                         
 facetid->edge[0]=790;                           
 facetid->edge[1]=791;      
 facetid->edge[2]=888;
 facetid++;

 facetid->color=DARKGREEN;
 facetid->nedges=3;                        
 facetid->edge[0]=791;                           
 facetid->edge[1]=792;      
 facetid->edge[2]=888;
 facetid++;

 facetid->color=DARKGREEN;
 facetid->nedges=3;                             
 facetid->edge[0]=792;                       
 facetid->edge[1]=793;      
 facetid->edge[2]=888;
 facetid++;

 facetid->color=DARKGREEN; 
 facetid->nedges=3;                           
 facetid->edge[0]=793;                           
 facetid->edge[1]=786;      
 facetid->edge[2]=888;
 facetid++;                 
 
				 //++++++ Cone For Under Outrigger 2 2     
 facetid->color=DARKGREEN;
 facetid->nedges=3;                             
 facetid->edge[0]=802;                           
 facetid->edge[1]=803;
 facetid->edge[2]=889; 
 facetid++;

 facetid->color=DARKGREEN;
 facetid->nedges=3;                          
 facetid->edge[0]=803;                   
 facetid->edge[1]=804;     
 facetid->edge[2]=889;
 facetid++;

 facetid->color=DARKGREEN;
 facetid->nedges=3;                             
 facetid->edge[0]=804;                        
 facetid->edge[1]=805;      
 facetid->edge[2]=889;
 facetid++;

 facetid->color=DARKGREEN;
 facetid->nedges=3;                           
 facetid->edge[0]=805;                           
 facetid->edge[1]=806;      
 facetid->edge[2]=889;
 facetid++;

 facetid->color=DARKGREEN;
 facetid->nedges=3;                         
 facetid->edge[0]=806;                           
 facetid->edge[1]=807;      
 facetid->edge[2]=889;
 facetid++;

 facetid->color=DARKGREEN;
 facetid->nedges=3;                        
 facetid->edge[0]=807;                           
 facetid->edge[1]=808;      
 facetid->edge[2]=889;
 facetid++;

 facetid->color=DARKGREEN;
 facetid->nedges=3;                             
 facetid->edge[0]=808;                       
 facetid->edge[1]=809;      
 facetid->edge[2]=889;
 facetid++;

 facetid->color=DARKGREEN; 
 facetid->nedges=3;                           
 facetid->edge[0]=809;                           
 facetid->edge[1]=802;      
 facetid->edge[2]=889;
 facetid++;                 

 				   //++++++ Cone For Under Outrigger 1 3    
 facetid->color=DARKGREEN;
 facetid->nedges=3;                             
 facetid->edge[0]=826;                           
 facetid->edge[1]=827;
 facetid->edge[2]=890; 
 facetid++;

 facetid->color=DARKGREEN;
 facetid->nedges=3;                          
 facetid->edge[0]=827;                   
 facetid->edge[1]=828;     
 facetid->edge[2]=890;
 facetid++;

 facetid->color=DARKGREEN;
 facetid->nedges=3;                             
 facetid->edge[0]=828;                        
 facetid->edge[1]=829;      
 facetid->edge[2]=890;
 facetid++;

 facetid->color=DARKGREEN;
 facetid->nedges=3;                           
 facetid->edge[0]=829;                           
 facetid->edge[1]=830;      
 facetid->edge[2]=890;
 facetid++;

 facetid->color=DARKGREEN;
 facetid->nedges=3;                         
 facetid->edge[0]=830;                           
 facetid->edge[1]=831;      
 facetid->edge[2]=890;
 facetid++;

 facetid->color=DARKGREEN;
 facetid->nedges=3;                        
 facetid->edge[0]=831;                           
 facetid->edge[1]=832;      
 facetid->edge[2]=890;
 facetid++;

 facetid->color=DARKGREEN;
 facetid->nedges=3;                             
 facetid->edge[0]=832;                       
 facetid->edge[1]=833;      
 facetid->edge[2]=890;
 facetid++;

 facetid->color=DARKGREEN; 
 facetid->nedges=3;                           
 facetid->edge[0]=833;                           
 facetid->edge[1]=826;      
 facetid->edge[2]=890;
 facetid++;                 

				    //++++++ Cone For Under Outrigger 2 3     
 facetid->color=DARKGREEN;
 facetid->nedges=3;                             
 facetid->edge[0]=842;                           
 facetid->edge[1]=843;
 facetid->edge[2]=891; 
 facetid++;

 facetid->color=DARKGREEN;
 facetid->nedges=3;                          
 facetid->edge[0]=843;                   
 facetid->edge[1]=844;     
 facetid->edge[2]=891;
 facetid++;

 facetid->color=DARKGREEN;
 facetid->nedges=3;                             
 facetid->edge[0]=844;                        
 facetid->edge[1]=845;      
 facetid->edge[2]=891;
 facetid++;

 facetid->color=DARKGREEN;
 facetid->nedges=3;                           
 facetid->edge[0]=845;                           
 facetid->edge[1]=846;      
 facetid->edge[2]=891;
 facetid++;

 facetid->color=DARKGREEN;
 facetid->nedges=3;                         
 facetid->edge[0]=846;                           
 facetid->edge[1]=847;      
 facetid->edge[2]=891;
 facetid++;

 facetid->color=DARKGREEN;
 facetid->nedges=3;                        
 facetid->edge[0]=847;                           
 facetid->edge[1]=848;      
 facetid->edge[2]=891;
 facetid++;

 facetid->color=DARKGREEN;
 facetid->nedges=3;                             
 facetid->edge[0]=848;                       
 facetid->edge[1]=849;      
 facetid->edge[2]=891;
 facetid++;

 facetid->color=DARKGREEN; 
 facetid->nedges=3;                           
 facetid->edge[0]=849;                           
 facetid->edge[1]=842;      
 facetid->edge[2]=891;
 facetid++;                 

  			     //++++++ Cone For Under Outrigger 1 4     
 facetid->color=DARKGREEN;
 facetid->nedges=3;                             
 facetid->edge[0]=859;                           
 facetid->edge[1]=858;
 facetid->edge[2]=892; 
 facetid++;

 facetid->color=DARKGREEN;
 facetid->nedges=3;                          
 facetid->edge[0]=860;                   
 facetid->edge[1]=859;     
 facetid->edge[2]=892;
 facetid++;

 facetid->color=DARKGREEN;
 facetid->nedges=3;                             
 facetid->edge[0]=861;                        
 facetid->edge[1]=860;      
 facetid->edge[2]=892;
 facetid++;

 facetid->color=DARKGREEN;
 facetid->nedges=3;                           
 facetid->edge[0]=862;                           
 facetid->edge[1]=861;      
 facetid->edge[2]=892;
 facetid++;

 facetid->color=DARKGREEN;
 facetid->nedges=3;                         
 facetid->edge[0]=863;                           
 facetid->edge[1]=862;      
 facetid->edge[2]=892;
 facetid++;

 facetid->color=DARKGREEN;
 facetid->nedges=3;                        
 facetid->edge[0]=864;                           
 facetid->edge[1]=863;      
 facetid->edge[2]=892;
 facetid++;

 facetid->color=DARKGREEN;
 facetid->nedges=3;                             
 facetid->edge[0]=865;                       
 facetid->edge[1]=864;      
 facetid->edge[2]=892;
 facetid++;

 facetid->color=DARKGREEN;
 facetid->nedges=3;                           
 facetid->edge[0]=858;                           
 facetid->edge[1]=865;      
 facetid->edge[2]=892;
 facetid++;                 
				   //++++++ Cone For Under Outrigger 2 4    
 facetid->color=DARKGREEN;
 facetid->nedges=3;                             
 facetid->edge[0]=875;                           
 facetid->edge[1]=874;
 facetid->edge[2]=893; 
 facetid++;

 facetid->color=DARKGREEN;
 facetid->nedges=3;                          
 facetid->edge[0]=876;                   
 facetid->edge[1]=875;     
 facetid->edge[2]=893;
 facetid++;

 facetid->color=DARKGREEN;
 facetid->nedges=3;                             
 facetid->edge[0]=877;                        
 facetid->edge[1]=876;      
 facetid->edge[2]=893;
 facetid++;

 facetid->color=DARKGREEN;
 facetid->nedges=3;                           
 facetid->edge[0]=878;                           
 facetid->edge[1]=877;      
 facetid->edge[2]=893;
 facetid++;

 facetid->color=DARKGREEN;
 facetid->nedges=3;                         
 facetid->edge[0]=879;                           
 facetid->edge[1]=878;      
 facetid->edge[2]=893;
 facetid++;

 facetid->color=DARKGREEN;
 facetid->nedges=3;                        
 facetid->edge[0]=880;                           
 facetid->edge[1]=879;      
 facetid->edge[2]=893;
 facetid++;

 facetid->color=DARKGREEN;
 facetid->nedges=3;                             
 facetid->edge[0]=881;                       
 facetid->edge[1]=880;      
 facetid->edge[2]=893;
 facetid++;

 facetid->color=DARKGREEN; 
 facetid->nedges=3;                           
 facetid->edge[0]=874;                           
 facetid->edge[1]=881;      
 facetid->edge[2]=893;
 facetid++;                 

		           //++++++ Cone Back Under Outrigger 1 1    
 facetid->color=DARKGREEN;
 facetid->nedges=3;                             
 facetid->edge[0]=762;                           
 facetid->edge[1]=763;
 facetid->edge[2]=894; 
 facetid++;

 facetid->color=DARKGREEN;
 facetid->nedges=3;                          
 facetid->edge[0]=763;                   
 facetid->edge[1]=764;     
 facetid->edge[2]=894;
 facetid++;

 facetid->color=DARKGREEN;
 facetid->nedges=3;                             
 facetid->edge[0]=764;                        
 facetid->edge[1]=765;      
 facetid->edge[2]=894;
 facetid++;

 facetid->color=DARKGREEN;
 facetid->nedges=3;                           
 facetid->edge[0]=765;                           
 facetid->edge[1]=766;      
 facetid->edge[2]=894;
 facetid++;

 facetid->color=DARKGREEN;
 facetid->nedges=3;                         
 facetid->edge[0]=766;                           
 facetid->edge[1]=767;      
 facetid->edge[2]=894;
 facetid++;

 facetid->color=DARKGREEN;
 facetid->nedges=3;                        
 facetid->edge[0]=767;                           
 facetid->edge[1]=768;      
 facetid->edge[2]=894;
 facetid++;

 facetid->color=DARKGREEN;
 facetid->nedges=3;                             
 facetid->edge[0]=768;                       
 facetid->edge[1]=769;      
 facetid->edge[2]=894;
 facetid++;

 facetid->color=DARKGREEN; 
 facetid->nedges=3;                           
 facetid->edge[0]=769;                           
 facetid->edge[1]=762;      
 facetid->edge[2]=894;
 facetid++;                 

 				//++++++ Cone Back Under Outrigger 2 1     
 facetid->color=DARKGREEN;
 facetid->nedges=3;                             
 facetid->edge[0]=778;                           
 facetid->edge[1]=779;
 facetid->edge[2]=895; 
 facetid++;

 facetid->color=DARKGREEN;
 facetid->nedges=3;                          
 facetid->edge[0]=779;                   
 facetid->edge[1]=780;     
 facetid->edge[2]=895;
 facetid++;

 facetid->color=DARKGREEN;
 facetid->nedges=3;                             
 facetid->edge[0]=780;                        
 facetid->edge[1]=781;      
 facetid->edge[2]=895;
 facetid++;

 facetid->color=DARKGREEN;
 facetid->nedges=3;                           
 facetid->edge[0]=781;                           
 facetid->edge[1]=782;      
 facetid->edge[2]=895;
 facetid++;

 facetid->color=DARKGREEN;
 facetid->nedges=3;                         
 facetid->edge[0]=782;                           
 facetid->edge[1]=783;      
 facetid->edge[2]=895;
 facetid++;

 facetid->color=DARKGREEN;
 facetid->nedges=3;                        
 facetid->edge[0]=783;                           
 facetid->edge[1]=784;      
 facetid->edge[2]=895;
 facetid++;

 facetid->color=DARKGREEN;
 facetid->nedges=3;                             
 facetid->edge[0]=784;                       
 facetid->edge[1]=785;      
 facetid->edge[2]=895;
 facetid++;

 facetid->color=DARKGREEN; 
 facetid->nedges=3;                           
 facetid->edge[0]=785;                           
 facetid->edge[1]=778;      
 facetid->edge[2]=895;
 facetid++;                 

			   //++++++ Cone Back Under Outrigger 1 2    
 facetid->color=DARKGREEN;
 facetid->nedges=3;                            
 facetid->edge[0]=795;                          
 facetid->edge[1]=794;
 facetid->edge[2]=896; 
 facetid++;

 facetid->color=DARKGREEN;
 facetid->nedges=3;                          
 facetid->edge[0]=796;                   
 facetid->edge[1]=795;     
 facetid->edge[2]=896;
 facetid++;

 facetid->color=DARKGREEN;
 facetid->nedges=3;                             
 facetid->edge[0]=797;                        
 facetid->edge[1]=796;      
 facetid->edge[2]=896;
 facetid++;

 facetid->color=DARKGREEN;
 facetid->nedges=3;                           
 facetid->edge[0]=798;                           
 facetid->edge[1]=797;      
 facetid->edge[2]=896;
 facetid++;

 facetid->color=DARKGREEN;
 facetid->nedges=3;                         
 facetid->edge[0]=799;                           
 facetid->edge[1]=798;      
 facetid->edge[2]=896;
 facetid++;

 facetid->color=DARKGREEN;
 facetid->nedges=3;                        
 facetid->edge[0]=800;                           
 facetid->edge[1]=799;      
 facetid->edge[2]=896;
 facetid++;

 facetid->color=DARKGREEN;
 facetid->nedges=3;                             
 facetid->edge[0]=801;                       
 facetid->edge[1]=800;      
 facetid->edge[2]=896;
 facetid++;

 facetid->color=DARKGREEN; 
 facetid->nedges=3;                           
 facetid->edge[0]=794;                           
 facetid->edge[1]=801;     
 facetid->edge[2]=896;
 facetid++;                 

		         //++++++ Cone Back Under Outrigger 2 2    
 facetid->color=DARKGREEN;
 facetid->nedges=3;                           
 facetid->edge[0]=811;                           
 facetid->edge[1]=810;
 facetid->edge[2]=897; 
 facetid++;

 facetid->color=DARKGREEN;
 facetid->nedges=3;                          
 facetid->edge[0]=812;                   
 facetid->edge[1]=811;     
 facetid->edge[2]=897;
 facetid++;

 facetid->color=DARKGREEN;
 facetid->nedges=3;                             
 facetid->edge[0]=813;                        
 facetid->edge[1]=812;      
 facetid->edge[2]=897;
 facetid++;

 facetid->color=DARKGREEN;
 facetid->nedges=3;                           
 facetid->edge[0]=814;                           
 facetid->edge[1]=813;      
 facetid->edge[2]=897;
 facetid++;

 facetid->color=DARKGREEN;
 facetid->nedges=3;                         
 facetid->edge[0]=815;                           
 facetid->edge[1]=814;      
 facetid->edge[2]=897;
 facetid++;

 facetid->color=DARKGREEN;
 facetid->nedges=3;                        
 facetid->edge[0]=816;                           
 facetid->edge[1]=815;      
 facetid->edge[2]=897;
 facetid++;

 facetid->color=DARKGREEN;
 facetid->nedges=3;                             
 facetid->edge[0]=817;                       
 facetid->edge[1]=816;      
 facetid->edge[2]=897;
 facetid++;

 facetid->color=DARKGREEN; 
 facetid->nedges=3;                           
 facetid->edge[0]=810;                           
 facetid->edge[1]=817;     
 facetid->edge[2]=897;
 facetid++;                 

				   //++++++ Cone Back Under Outrigger 1 3     
 facetid->color=DARKGREEN;
 facetid->nedges=3;                           
 facetid->edge[0]=819;                           
 facetid->edge[1]=818;
 facetid->edge[2]=898; 
 facetid++;

 facetid->color=DARKGREEN;
 facetid->nedges=3;                          
 facetid->edge[0]=820;                   
 facetid->edge[1]=819;     
 facetid->edge[2]=898;
 facetid++;

 facetid->color=DARKGREEN;
 facetid->nedges=3;                             
 facetid->edge[0]=821;                        
 facetid->edge[1]=820;      
 facetid->edge[2]=898;
 facetid++;

 facetid->color=DARKGREEN;
 facetid->nedges=3;                           
 facetid->edge[0]=822;                           
 facetid->edge[1]=821;      
 facetid->edge[2]=898;
 facetid++;

 facetid->color=DARKGREEN;
 facetid->nedges=3;                         
 facetid->edge[0]=823;                           
 facetid->edge[1]=822;      
 facetid->edge[2]=898;
 facetid++;

 facetid->color=DARKGREEN;
 facetid->nedges=3;                        
 facetid->edge[0]=824;                           
 facetid->edge[1]=823;      
 facetid->edge[2]=898;
 facetid++;

 facetid->color=DARKGREEN;
 facetid->nedges=3;                             
 facetid->edge[0]=825;                       
 facetid->edge[1]=824;      
 facetid->edge[2]=898;
 facetid++;

 facetid->color=DARKGREEN; 
 facetid->nedges=3;                           
 facetid->edge[0]=818;                           
 facetid->edge[1]=825;     
 facetid->edge[2]=898;
 facetid++;                 
 			    //++++++ Cone Back Under Outrigger 2 3   
 facetid->color=DARKGREEN;
 facetid->nedges=3;                           
 facetid->edge[0]=835;                           
 facetid->edge[1]=834;
 facetid->edge[2]=899; 
 facetid++;

 facetid->color=DARKGREEN;
 facetid->nedges=3;                          
 facetid->edge[0]=836;                   
 facetid->edge[1]=835;     
 facetid->edge[2]=899;
 facetid++;

 facetid->color=DARKGREEN;
 facetid->nedges=3;                             
 facetid->edge[0]=837;                        
 facetid->edge[1]=836;      
 facetid->edge[2]=899;
 facetid++;

 facetid->color=DARKGREEN;
 facetid->nedges=3;                           
 facetid->edge[0]=838;                           
 facetid->edge[1]=837;      
 facetid->edge[2]=899;
 facetid++;

 facetid->color=DARKGREEN;
 facetid->nedges=3;                         
 facetid->edge[0]=839;                           
 facetid->edge[1]=838;      
 facetid->edge[2]=899;
 facetid++;

 facetid->color=DARKGREEN;
 facetid->nedges=3;                        
 facetid->edge[0]=840;                           
 facetid->edge[1]=839;      
 facetid->edge[2]=899;
 facetid++;

 facetid->color=DARKGREEN;
 facetid->nedges=3;                             
 facetid->edge[0]=841;                       
 facetid->edge[1]=840;      
 facetid->edge[2]=899;
 facetid++;

 facetid->color=DARKGREEN; 
 facetid->nedges=3;                           
 facetid->edge[0]=834;                           
 facetid->edge[1]=841;     
 facetid->edge[2]=899;
 facetid++;                 

				    //++++++ Cone Back Under Outrigger 1 4    
 facetid->color=DARKGREEN;
 facetid->nedges=3;                             
 facetid->edge[0]=850;                           
 facetid->edge[1]=851;
 facetid->edge[2]=900; 
 facetid++;

 facetid->color=DARKGREEN;
 facetid->nedges=3;                          
 facetid->edge[0]=851;                   
 facetid->edge[1]=852;     
 facetid->edge[2]=900;
 facetid++;

 facetid->color=DARKGREEN;
 facetid->nedges=3;                             
 facetid->edge[0]=852;                        
 facetid->edge[1]=853;      
 facetid->edge[2]=900;
 facetid++;

 facetid->color=DARKGREEN;
 facetid->nedges=3;                           
 facetid->edge[0]=853;                           
 facetid->edge[1]=854;      
 facetid->edge[2]=900;
 facetid++;

 facetid->color=DARKGREEN;
 facetid->nedges=3;                         
 facetid->edge[0]=854;                           
 facetid->edge[1]=855;      
 facetid->edge[2]=900;
 facetid++;

 facetid->color=DARKGREEN;
 facetid->nedges=3;                        
 facetid->edge[0]=855;                           
 facetid->edge[1]=856;      
 facetid->edge[2]=900;
 facetid++;

 facetid->color=DARKGREEN;
 facetid->nedges=3;                             
 facetid->edge[0]=856;                       
 facetid->edge[1]=857;      
 facetid->edge[2]=900;
 facetid++;

 facetid->color=DARKGREEN; 
 facetid->nedges=3;                           
 facetid->edge[0]=857;                           
 facetid->edge[1]=850;     
 facetid->edge[2]=900;
 facetid++;                 

				   //++++++ Cone Back Under Outrigger 2 4    
 facetid->color=DARKGREEN;
 facetid->nedges=3;                            
 facetid->edge[0]=866;                           
 facetid->edge[1]=867;
 facetid->edge[2]=901; 
 facetid++;

 facetid->color=DARKGREEN;
 facetid->nedges=3;                          
 facetid->edge[0]=867;                   
 facetid->edge[1]=868;     
 facetid->edge[2]=901;
 facetid++;

 facetid->color=DARKGREEN;
 facetid->nedges=3;                             
 facetid->edge[0]=868;                        
 facetid->edge[1]=869;      
 facetid->edge[2]=901;
 facetid++;

 facetid->color=DARKGREEN;
 facetid->nedges=3;                           
 facetid->edge[0]=869;                           
 facetid->edge[1]=870;      
 facetid->edge[2]=901;
 facetid++;

 facetid->color=DARKGREEN;
 facetid->nedges=3;                         
 facetid->edge[0]=870;                           
 facetid->edge[1]=871;      
 facetid->edge[2]=901;
 facetid++;

 facetid->color=DARKGREEN;
 facetid->nedges=3;                        
 facetid->edge[0]=871;                           
 facetid->edge[1]=872;      
 facetid->edge[2]=901;
 facetid++;

 facetid->color=DARKGREEN;
 facetid->nedges=3;                             
 facetid->edge[0]=872;                       
 facetid->edge[1]=873;      
 facetid->edge[2]=901;
 facetid++;

 facetid->color=DARKGREEN; 
 facetid->nedges=3;                           
 facetid->edge[0]=873;                           
 facetid->edge[1]=866;     
 facetid->edge[2]=901;
 facetid++;                 

 //facetid->color=WHITE;        //++++++ X L 1
 //facetid->nedges=8;              
 //facetid->edge[0]=902;
 //facetid->edge[1]=903;
 //facetid->edge[2]=904;
 //facetid->edge[3]=905;            
 //facetid->edge[4]=906;
 //facetid->edge[5]=907;
 //facetid->edge[6]=908;
 //facetid->edge[7]=909;
 //facetid++;

 facetid->color=DARKGREEN;
 facetid->nedges=4;                             
 facetid->edge[0]=902;                          
 facetid->edge[1]=903;        
 facetid->edge[2]=911; 
 facetid->edge[3]=910;
 facetid++;

 facetid->color=DARKGREEN;
 facetid->nedges=4;                         
 facetid->edge[0]=903;                           
 facetid->edge[1]=904;      
 facetid->edge[2]=912;
 facetid->edge[3]=911;
 facetid++;

 facetid->color=DARKGREEN;
 facetid->nedges=4;                             
 facetid->edge[0]=904;                     
 facetid->edge[1]=905;      
 facetid->edge[2]=913;
 facetid->edge[3]=912;
 facetid++;

 facetid->color=DARKGREEN;
 facetid->nedges=4;                      
 facetid->edge[0]=905;                           
 facetid->edge[1]=906;      
 facetid->edge[2]=914;
 facetid->edge[3]=913;
 facetid++;

 facetid->color=DARKGREEN;
 facetid->nedges=4;                         
 facetid->edge[0]=906;                           
 facetid->edge[1]=907;      
 facetid->edge[2]=915;
 facetid->edge[3]=914;
 facetid++;

 facetid->color=DARKGREEN;
 facetid->nedges=4;                        
 facetid->edge[0]=907;                           
 facetid->edge[1]=908;      
 facetid->edge[2]=916;
 facetid->edge[3]=915;
 facetid++;

 facetid->color=DARKGREEN;
 facetid->nedges=4;                             
 facetid->edge[0]=908;                        
 facetid->edge[1]=909;      
 facetid->edge[2]=917;
 facetid->edge[3]=916;
 facetid++;

 facetid->color=DARKGREEN;
 facetid->nedges=4;                          
 facetid->edge[0]=909;                           
 facetid->edge[1]=902;         
 facetid->edge[2]=910;
 facetid->edge[3]=917;
 facetid++;                    

  //facetid->color=WHITE;        //++++++ X R 1 
 //facetid->nedges=8; 
 //facetid->edge[0]=918;
 //facetid->edge[1]=919;
 //facetid->edge[2]=920;
 //facetid->edge[3]=921;            
 //facetid->edge[4]=922;
 //facetid->edge[5]=923;
 //facetid->edge[6]=924;
 //facetid->edge[7]=925;
 //facetid++;

 facetid->color=DARKGREEN;
 facetid->nedges=4;                             
 facetid->edge[0]=926;                       
 facetid->edge[1]=927;        
 facetid->edge[2]=919; 
 facetid->edge[3]=918;
 facetid++;

 facetid->color=DARKGREEN;
 facetid->nedges=4;                          
 facetid->edge[0]=927;                           
 facetid->edge[1]=928;      
 facetid->edge[2]=920;
 facetid->edge[3]=919;
 facetid++;

 facetid->color=DARKGREEN;
 facetid->nedges=4;                             
 facetid->edge[0]=928;                      
 facetid->edge[1]=929;      
 facetid->edge[2]=921;
 facetid->edge[3]=920;
 facetid++;

 facetid->color=DARKGREEN;
 facetid->nedges=4;                     
 facetid->edge[0]=929;                           
 facetid->edge[1]=930;      
 facetid->edge[2]=922;
 facetid->edge[3]=921;
 facetid++;

 facetid->color=DARKGREEN;
 facetid->nedges=4;                        
 facetid->edge[0]=930;                           
 facetid->edge[1]=931;      
 facetid->edge[2]=923;
 facetid->edge[3]=922;
 facetid++;

 facetid->color=DARKGREEN;
 facetid->nedges=4;                       
 facetid->edge[0]=931;                           
 facetid->edge[1]=932;      
 facetid->edge[2]=924;
 facetid->edge[3]=923;
 facetid++;

 facetid->color=DARKGREEN;
 facetid->nedges=4;                             
 facetid->edge[0]=932;                   
 facetid->edge[1]=933;      
 facetid->edge[2]=925;
 facetid->edge[3]=924;
 facetid++;

 facetid->color=DARKGREEN; 
 facetid->nedges=4;                          
 facetid->edge[0]=933;                           
 facetid->edge[1]=926;         
 facetid->edge[2]=918;
 facetid->edge[3]=925;
 facetid++;                    

 //facetid->color=WHITE;        //++++++ X R 2
 //facetid->nedges=8; 
 //facetid->edge[0]=934;
 //facetid->edge[1]=935;
 //facetid->edge[2]=936;
 //facetid->edge[3]=937;            
 //facetid->edge[4]=938;
 //facetid->edge[5]=939;
 //facetid->edge[6]=940;
 //facetid->edge[7]=941;
 //facetid++;

 facetid->color=DARKGREEN;
 facetid->nedges=4;                             
 facetid->edge[0]=934;                       
 facetid->edge[1]=935;        
 facetid->edge[2]=943; 
 facetid->edge[3]=942;
 facetid++;

 facetid->color=DARKGREEN;
 facetid->nedges=4;                         
 facetid->edge[0]=935;                           
 facetid->edge[1]=936;      
 facetid->edge[2]=944;
 facetid->edge[3]=943;
 facetid++;

 facetid->color=DARKGREEN;
 facetid->nedges=4;                             
 facetid->edge[0]=936;                       
 facetid->edge[1]=937;      
 facetid->edge[2]=945;
 facetid->edge[3]=944;
 facetid++;

 facetid->color=DARKGREEN;
 facetid->nedges=4;                        
 facetid->edge[0]=937;                           
 facetid->edge[1]=938;      
 facetid->edge[2]=946;
 facetid->edge[3]=945;
 facetid++;

 facetid->color=DARKGREEN;
 facetid->nedges=4;                         
 facetid->edge[0]=938;                           
 facetid->edge[1]=939;      
 facetid->edge[2]=947;
 facetid->edge[3]=946;
 facetid++;

 facetid->color=DARKGREEN;
 facetid->nedges=4;                         
 facetid->edge[0]=939;                           
 facetid->edge[1]=940;      
 facetid->edge[2]=948;
 facetid->edge[3]=947;
 facetid++;

 facetid->color=DARKGREEN;
 facetid->nedges=4;                             
 facetid->edge[0]=940;                       
 facetid->edge[1]=941;      
 facetid->edge[2]=949;
 facetid->edge[3]=948;
 facetid++;

 facetid->color=DARKGREEN;
 facetid->nedges=4;                          
 facetid->edge[0]=941;                           
 facetid->edge[1]=934;      
 facetid->edge[2]=942;
 facetid->edge[3]=949;
 facetid++;                    

 //facetid->color=WHITE;        //++++++ X L 2 
 //facetid->nedges=8; 
 //facetid->edge[0]=950;               
 //facetid->edge[1]=951;
 //facetid->edge[2]=952;
 //facetid->edge[3]=953;            
 //facetid->edge[4]=954;
 //facetid->edge[5]=955;
 //facetid->edge[6]=956;
 //facetid->edge[7]=957;
 //facetid++;

 facetid->color=DARKGREEN;
 facetid->nedges=4;                             
 facetid->edge[0]=958;                          
 facetid->edge[1]=959;        
 facetid->edge[2]=951; 
 facetid->edge[3]=950;
 facetid++;

 facetid->color=DARKGREEN;
 facetid->nedges=4;                           
 facetid->edge[0]=959;                           
 facetid->edge[1]=960;      
 facetid->edge[2]=952;
 facetid->edge[3]=951;
 facetid++;

 facetid->color=DARKGREEN;
 facetid->nedges=4;                             
 facetid->edge[0]=960;                          
 facetid->edge[1]=961;      
 facetid->edge[2]=953;
 facetid->edge[3]=952;
 facetid++;

 facetid->color=DARKGREEN;
 facetid->nedges=4;                          
 facetid->edge[0]=961;                           
 facetid->edge[1]=962;      
 facetid->edge[2]=954;
 facetid->edge[3]=953;
 facetid++;

 facetid->color=DARKGREEN;
 facetid->nedges=4;                         
 facetid->edge[0]=962;                           
 facetid->edge[1]=963;      
 facetid->edge[2]=955;
 facetid->edge[3]=954;
 facetid++;

 facetid->color=DARKGREEN;
 facetid->nedges=4;                         
 facetid->edge[0]=963;                           
 facetid->edge[1]=964;      
 facetid->edge[2]=956;
 facetid->edge[3]=955;
 facetid++;

 facetid->color=DARKGREEN;
 facetid->nedges=4;                             
 facetid->edge[0]=964;                       
 facetid->edge[1]=965;      
 facetid->edge[2]=957;
 facetid->edge[3]=956;
 facetid++;

 facetid->color=DARKGREEN;
 facetid->nedges=4;                         
 facetid->edge[0]=965;            
 facetid->edge[1]=958;      
 facetid->edge[2]=950;
 facetid->edge[3]=957;
 facetid++;                    
 
 //facetid->color=WHITE;        //+++++++X R 3 
 //facetid->nedges=8; 
 //facetid->edge[0]=966;
 //facetid->edge[1]=967;
 //facetid->edge[2]=968;
 //facetid->edge[3]=969;            
 //facetid->edge[4]=970;
 //facetid->edge[5]=971;
 //facetid->edge[6]=972;
 //facetid->edge[7]=973;
 //facetid++;

 facetid->color=DARKGREEN;
 facetid->nedges=4;                             
 facetid->edge[0]=966;                         
 facetid->edge[1]=967;        
 facetid->edge[2]=975; 
 facetid->edge[3]=974;
 facetid++;

 facetid->color=DARKGREEN;
 facetid->nedges=4;                          
 facetid->edge[0]=967;                           
 facetid->edge[1]=968;      
 facetid->edge[2]=976;
 facetid->edge[3]=975;
 facetid++;

 facetid->color=DARKGREEN;
 facetid->nedges=4;                             
 facetid->edge[0]=968;                        
 facetid->edge[1]=969;      
 facetid->edge[2]=977;
 facetid->edge[3]=976;
 facetid++;

 facetid->color=DARKGREEN;
 facetid->nedges=4;                      
 facetid->edge[0]=969;                           
 facetid->edge[1]=970;      
 facetid->edge[2]=978;
 facetid->edge[3]=977;
 facetid++;

 facetid->color=DARKGREEN;
 facetid->nedges=4;                         
 facetid->edge[0]=970;                           
 facetid->edge[1]=971;      
 facetid->edge[2]=979;
 facetid->edge[3]=978;
 facetid++;

 facetid->color=DARKGREEN;
 facetid->nedges=4;                          
 facetid->edge[0]=971;                           
 facetid->edge[1]=972;      
 facetid->edge[2]=980;
 facetid->edge[3]=979;
 facetid++;

 facetid->color=DARKGREEN;
 facetid->nedges=4;                             
 facetid->edge[0]=972;                        
 facetid->edge[1]=973;      
 facetid->edge[2]=981;
 facetid->edge[3]=980;
 facetid++;

 facetid->color=DARKGREEN;
 facetid->nedges=4;                         
 facetid->edge[0]=973;                           
 facetid->edge[1]=966;      
 facetid->edge[2]=974;
 facetid->edge[3]=981;
 facetid++;                    
 
 //facetid->color=WHITE;        //++++++ X L 3  
 //facetid->nedges=8; 
 //facetid->edge[0]=982;
 //facetid->edge[1]=983;
 //facetid->edge[2]=984;
 //facetid->edge[3]=985;            
 //facetid->edge[4]=986;
 //facetid->edge[5]=987;
 //facetid->edge[6]=988;
 //facetid->edge[7]=989;
 //facetid++;

 facetid->color=DARKGREEN;
 facetid->nedges=4;                             
 facetid->edge[0]=990;                        
 facetid->edge[1]=991;        
 facetid->edge[2]=983; 
 facetid->edge[3]=982;
 facetid++;

 facetid->color=DARKGREEN;
 facetid->nedges=4;                          
 facetid->edge[0]=991;                           
 facetid->edge[1]=992;      
 facetid->edge[2]=984;
 facetid->edge[3]=983;
 facetid++;

 facetid->color=DARKGREEN;
 facetid->nedges=4;                             
 facetid->edge[0]=992;                          
 facetid->edge[1]=993;      
 facetid->edge[2]=985;
 facetid->edge[3]=984;
 facetid++;

 facetid->color=DARKGREEN;
 facetid->nedges=4;                          
 facetid->edge[0]=993;                           
 facetid->edge[1]=994;      
 facetid->edge[2]=986;
 facetid->edge[3]=985;
 facetid++;

 facetid->color=DARKGREEN;
 facetid->nedges=4;                        
 facetid->edge[0]=994;                           
 facetid->edge[1]=995;      
 facetid->edge[2]=987;
 facetid->edge[3]=986;
 facetid++;

 facetid->color=DARKGREEN;
 facetid->nedges=4;                           
 facetid->edge[0]=995;                           
 facetid->edge[1]=996;      
 facetid->edge[2]=988;
 facetid->edge[3]=987;
 facetid++;

 facetid->color=DARKGREEN;
 facetid->nedges=4;                             
 facetid->edge[0]=996;                       
 facetid->edge[1]=997;      
 facetid->edge[2]=989;
 facetid->edge[3]=988;
 facetid++;

 facetid->color=DARKGREEN;
 facetid->nedges=4;                           
 facetid->edge[0]=997;                           
 facetid->edge[1]=990;      
 facetid->edge[2]=982;
 facetid->edge[3]=989;
 facetid++;                    

 //facetid->color=WHITE; //++++++ X  L 4 
 //facetid->nedges=8; 
 //facetid->edge[0]=998;
 //facetid->edge[1]=999;
 //facetid->edge[2]=1000;
 //facetid->edge[3]=1001;            
 //facetid->edge[4]=1002;
 //facetid->edge[5]=1003;
 //facetid->edge[6]=1004;
 //facetid->edge[7]=1005;
 //facetid++;

 facetid->color=DARKGREEN;
 facetid->nedges=4;                             
 facetid->edge[0]=998;                            
 facetid->edge[1]=999;        
 facetid->edge[2]=1007; 
 facetid->edge[3]=1006;
 facetid++;

 facetid->color=DARKGREEN;
 facetid->nedges=4;                            
 facetid->edge[0]=999;                           
 facetid->edge[1]=1000;      
 facetid->edge[2]=1008;
 facetid->edge[3]=1007;
 facetid++;

 facetid->color=DARKGREEN;
 facetid->nedges=4;                             
 facetid->edge[0]=1000;                          
 facetid->edge[1]=1001;      
 facetid->edge[2]=1009;
 facetid->edge[3]=1008;
 facetid++;

 facetid->color=DARKGREEN;
 facetid->nedges=4;                          
 facetid->edge[0]=1001;                           
 facetid->edge[1]=1002;      
 facetid->edge[2]=1010;
 facetid->edge[3]=1009;
 facetid++;

 facetid->color=DARKGREEN;
 facetid->nedges=4;                          
 facetid->edge[0]=1002;                           
 facetid->edge[1]=1003;      
 facetid->edge[2]=1011;
 facetid->edge[3]=1010;
 facetid++;

 facetid->color=DARKGREEN;
 facetid->nedges=4;                          
 facetid->edge[0]=1003;                           
 facetid->edge[1]=1004;      
 facetid->edge[2]=1012;
 facetid->edge[3]=1011;
 facetid++;

 facetid->color=DARKGREEN;
 facetid->nedges=4;                             
 facetid->edge[0]=1004;                       
 facetid->edge[1]=1005;      
 facetid->edge[2]=1013;
 facetid->edge[3]=1012;
 facetid++;

 facetid->color=DARKGREEN;
 facetid->nedges=4;                         
 facetid->edge[0]=1005;                           
 facetid->edge[1]=998;      
 facetid->edge[2]=1006;
 facetid->edge[3]=1013;
 facetid++;                    

 //facetid->color=WHITE;  //++++++X R 4
 //facetid->nedges=8; 
 //facetid->edge[0]=1014;
 //facetid->edge[1]=1015;
 //facetid->edge[2]=1016;
 //facetid->edge[3]=1017;            
 //facetid->edge[4]=1018;
 //facetid->edge[5]=1019;
 //facetid->edge[6]=1020;
 //facetid->edge[7]=1021;
 //facetid++;

 facetid->color=DARKGREEN;
 facetid->nedges=4;                             
 facetid->edge[0]=1022;                            
 facetid->edge[1]=1023;        
 facetid->edge[2]=1015; 
 facetid->edge[3]=1014;
 facetid++;

 facetid->color=DARKGREEN;
 facetid->nedges=4;                            
 facetid->edge[0]=1023;                           
 facetid->edge[1]=1024;      
 facetid->edge[2]=1016;
 facetid->edge[3]=1015;
 facetid++;

 facetid->color=DARKGREEN;
 facetid->nedges=4;                             
 facetid->edge[0]=1024;                          
 facetid->edge[1]=1025;      
 facetid->edge[2]=1017;
 facetid->edge[3]=1016;
 facetid++;

 facetid->color=DARKGREEN;
 facetid->nedges=4;                          
 facetid->edge[0]=1025;                           
 facetid->edge[1]=1026;      
 facetid->edge[2]=1018;
 facetid->edge[3]=1017;
 facetid++;

 facetid->color=DARKGREEN;
 facetid->nedges=4;                          
 facetid->edge[0]=1026;                           
 facetid->edge[1]=1027;      
 facetid->edge[2]=1019;
 facetid->edge[3]=1018;
 facetid++;

 facetid->color=DARKGREEN;
 facetid->nedges=4;                          
 facetid->edge[0]=1027;                           
 facetid->edge[1]=1028;      
 facetid->edge[2]=1020;
 facetid->edge[3]=1019;
 facetid++;

 facetid->color=DARKGREEN;
 facetid->nedges=4;                             
 facetid->edge[0]=1028;                       
 facetid->edge[1]=1029;      
 facetid->edge[2]=1021;
 facetid->edge[3]=1020;
 facetid++;

 facetid->color=DARKGREEN;
 facetid->nedges=4;                         
 facetid->edge[0]=1029;                           
 facetid->edge[1]=1022;      
 facetid->edge[2]=1014;
 facetid->edge[3]=1021;
 facetid++;                    
				    //++++++ Cone X R 1    
 facetid->color=DARKGREEN;
 facetid->nedges=3;                             
 facetid->edge[0]=910;                            
 facetid->edge[1]=911;
 facetid->edge[2]=1030; 
 facetid++;

 facetid->color=DARKGREEN;
 facetid->nedges=3;                          
 facetid->edge[0]=911;                   
 facetid->edge[1]=912;     
 facetid->edge[2]=1030;
 facetid++;

 facetid->color=DARKGREEN;
 facetid->nedges=3;                             
 facetid->edge[0]=912;                        
 facetid->edge[1]=913;      
 facetid->edge[2]=1030;
 facetid++;

 facetid->color=DARKGREEN;
 facetid->nedges=3;                           
 facetid->edge[0]=913;                           
 facetid->edge[1]=914;      
 facetid->edge[2]=1030;
 facetid++;

 facetid->color=DARKGREEN;
 facetid->nedges=3;                         
 facetid->edge[0]=914;                           
 facetid->edge[1]=915;      
 facetid->edge[2]=1030;
 facetid++;

 facetid->color=DARKGREEN;
 facetid->nedges=3;                        
 facetid->edge[0]=915;                           
 facetid->edge[1]=916;      
 facetid->edge[2]=1030;
 facetid++;

 facetid->color=DARKGREEN;
 facetid->nedges=3;                             
 facetid->edge[0]=916;                       
 facetid->edge[1]=917;      
 facetid->edge[2]=1030;
 facetid++;

 facetid->color=DARKGREEN;
 facetid->nedges=3;                           
 facetid->edge[0]=917;                           
 facetid->edge[1]=910;      
 facetid->edge[2]=1030;
 facetid++;                 
 				    //++++++ Cone X L 1    
 facetid->color=DARKGREEN;
 facetid->nedges=3;                             
 facetid->edge[0]=927;                            
 facetid->edge[1]=926;
 facetid->edge[2]=1031; 
 facetid++;

 facetid->color=DARKGREEN;
 facetid->nedges=3;                          
 facetid->edge[0]=928;                   
 facetid->edge[1]=927;     
 facetid->edge[2]=1031;
 facetid++;

 facetid->color=DARKGREEN;
 facetid->nedges=3;                             
 facetid->edge[0]=929;                        
 facetid->edge[1]=928;      
 facetid->edge[2]=1031;
 facetid++;

 facetid->color=DARKGREEN;
 facetid->nedges=3;                           
 facetid->edge[0]=930;                           
 facetid->edge[1]=929;      
 facetid->edge[2]=1031;
 facetid++;

 facetid->color=DARKGREEN;
 facetid->nedges=3;                         
 facetid->edge[0]=931;                           
 facetid->edge[1]=930;      
 facetid->edge[2]=1031;
 facetid++;

 facetid->color=DARKGREEN;
 facetid->nedges=3;                        
 facetid->edge[0]=932;                           
 facetid->edge[1]=931;      
 facetid->edge[2]=1031;
 facetid++;

 facetid->color=DARKGREEN;
 facetid->nedges=3;                             
 facetid->edge[0]=933;                       
 facetid->edge[1]=932;      
 facetid->edge[2]=1031;
 facetid++;

 facetid->color=DARKGREEN; 
 facetid->nedges=3;                           
 facetid->edge[0]=926;                           
 facetid->edge[1]=933;      
 facetid->edge[2]=1031;
 facetid++;                 
    
  				    //++++++ Cone X L 2   
 facetid->color=DARKGREEN;
 facetid->nedges=3;                             
 facetid->edge[0]=942;                            
 facetid->edge[1]=943;
 facetid->edge[2]=1032; 
 facetid++;

 facetid->color=DARKGREEN;
 facetid->nedges=3;                          
 facetid->edge[0]=943;                   
 facetid->edge[1]=944;     
 facetid->edge[2]=1032;
 facetid++;

 facetid->color=DARKGREEN;
 facetid->nedges=3;                             
 facetid->edge[0]=944;                        
 facetid->edge[1]=945;      
 facetid->edge[2]=1032;
 facetid++;

 facetid->color=DARKGREEN;
 facetid->nedges=3;                           
 facetid->edge[0]=945;                           
 facetid->edge[1]=946;      
 facetid->edge[2]=1032;
 facetid++;

 facetid->color=DARKGREEN;
 facetid->nedges=3;                         
 facetid->edge[0]=946;                           
 facetid->edge[1]=947;      
 facetid->edge[2]=1032;
 facetid++;

 facetid->color=DARKGREEN;
 facetid->nedges=3;                        
 facetid->edge[0]=947;                           
 facetid->edge[1]=948;      
 facetid->edge[2]=1032;
 facetid++;

 facetid->color=DARKGREEN;
 facetid->nedges=3;                             
 facetid->edge[0]=948;                       
 facetid->edge[1]=949;      
 facetid->edge[2]=1032;
 facetid++;

 facetid->color=DARKGREEN; 
 facetid->nedges=3;                           
 facetid->edge[0]=949;                           
 facetid->edge[1]=942;      
 facetid->edge[2]=1032;
 facetid++;                 

                              //++++++ Cone X L 2  
 facetid->color=DARKGREEN;              
 facetid->nedges=3;                             
 facetid->edge[0]=959;                            
 facetid->edge[1]=958;
 facetid->edge[2]=1033; 
 facetid++;

 facetid->color=DARKGREEN;
 facetid->nedges=3;                          
 facetid->edge[0]=960;                   
 facetid->edge[1]=959;     
 facetid->edge[2]=1033;
 facetid++;

 facetid->color=DARKGREEN;
 facetid->nedges=3;                             
 facetid->edge[0]=961;                        
 facetid->edge[1]=960;      
 facetid->edge[2]=1033;
 facetid++;

 facetid->color=DARKGREEN;
 facetid->nedges=3;                           
 facetid->edge[0]=962;                           
 facetid->edge[1]=961;      
 facetid->edge[2]=1033;
 facetid++;

 facetid->color=DARKGREEN;
 facetid->nedges=3;                         
 facetid->edge[0]=963;                           
 facetid->edge[1]=962;      
 facetid->edge[2]=1033;
 facetid++;

 facetid->color=DARKGREEN;
 facetid->nedges=3;                        
 facetid->edge[0]=964;                           
 facetid->edge[1]=963;      
 facetid->edge[2]=1033;
 facetid++;

 facetid->color=DARKGREEN;
 facetid->nedges=3;                             
 facetid->edge[0]=965;                       
 facetid->edge[1]=964;      
 facetid->edge[2]=1033;
 facetid++;

 facetid->color=DARKGREEN; 
 facetid->nedges=3;                           
 facetid->edge[0]=958;                           
 facetid->edge[1]=965;      
 facetid->edge[2]=1033;
 facetid++;                 
 
                              //++++++ Cone X 1 3  
 facetid->color=DARKGREEN;              
 facetid->nedges=3;                             
 facetid->edge[0]=974;                            
 facetid->edge[1]=975;
 facetid->edge[2]=1034; 
 facetid++;

 facetid->color=DARKGREEN;
 facetid->nedges=3;                          
 facetid->edge[0]=975;                   
 facetid->edge[1]=976;     
 facetid->edge[2]=1034;
 facetid++;

 facetid->color=DARKGREEN;
 facetid->nedges=3;                             
 facetid->edge[0]=976;                        
 facetid->edge[1]=977;      
 facetid->edge[2]=1034;
 facetid++;

 facetid->color=DARKGREEN;
 facetid->nedges=3;                           
 facetid->edge[0]=977;                           
 facetid->edge[1]=978;      
 facetid->edge[2]=1034;
 facetid++;

 facetid->color=DARKGREEN;
 facetid->nedges=3;                         
 facetid->edge[0]=978;                           
 facetid->edge[1]=979;      
 facetid->edge[2]=1034;
 facetid++;

 facetid->color=DARKGREEN;
 facetid->nedges=3;                        
 facetid->edge[0]=979;                           
 facetid->edge[1]=980;      
 facetid->edge[2]=1034;
 facetid++;

 facetid->color=DARKGREEN;
 facetid->nedges=3;                             
 facetid->edge[0]=980;                       
 facetid->edge[1]=981;      
 facetid->edge[2]=1034;
 facetid++;

 facetid->color=DARKGREEN;   
 facetid->nedges=3;                           
 facetid->edge[0]=981;                           
 facetid->edge[1]=974;      
 facetid->edge[2]=1034;
 facetid++;                 

                               //++++++ Cone X 2 3  
 facetid->color=DARKGREEN;
 facetid->nedges=3;                                             
 facetid->edge[0]=991;                            
 facetid->edge[1]=990;
 facetid->edge[2]=1035; 
 facetid++;

 facetid->color=DARKGREEN;
 facetid->nedges=3;                          
 facetid->edge[0]=992;                   
 facetid->edge[1]=991;     
 facetid->edge[2]=1035;
 facetid++;

 facetid->color=DARKGREEN;
 facetid->nedges=3;                             
 facetid->edge[0]=993;                        
 facetid->edge[1]=992;      
 facetid->edge[2]=1035;
 facetid++;

 facetid->color=DARKGREEN;
 facetid->nedges=3;                           
 facetid->edge[0]=994;                           
 facetid->edge[1]=993;      
 facetid->edge[2]=1035;
 facetid++;

 facetid->color=DARKGREEN;
 facetid->nedges=3;                         
 facetid->edge[0]=995;                           
 facetid->edge[1]=994;      
 facetid->edge[2]=1035;
 facetid++;

 facetid->color=DARKGREEN;
 facetid->nedges=3;                        
 facetid->edge[0]=996;                           
 facetid->edge[1]=995;      
 facetid->edge[2]=1035;
 facetid++;

 facetid->color=DARKGREEN;
 facetid->nedges=3;                             
 facetid->edge[0]=997;                       
 facetid->edge[1]=996;      
 facetid->edge[2]=1035;
 facetid++;

 facetid->color=DARKGREEN;   
 facetid->nedges=3;                           
 facetid->edge[0]=990;                           
 facetid->edge[1]=997;      
 facetid->edge[2]=1035;
 facetid++;                 

                                //++++++ Cone X 1 4  
 facetid->color=DARKGREEN;
 facetid->nedges=3;                             
 facetid->edge[0]=999;                            
 facetid->edge[1]=998;
 facetid->edge[2]=1036; 
 facetid++;

 facetid->color=DARKGREEN;
 facetid->nedges=3;                          
 facetid->edge[0]=1000;                   
 facetid->edge[1]=999;     
 facetid->edge[2]=1036;
 facetid++;

 facetid->color=DARKGREEN;
 facetid->nedges=3;                             
 facetid->edge[0]=1001;                        
 facetid->edge[1]=1000;      
 facetid->edge[2]=1036;
 facetid++;

 facetid->color=DARKGREEN;
 facetid->nedges=3;                           
 facetid->edge[0]=1002;                           
 facetid->edge[1]=1001;      
 facetid->edge[2]=1036;
 facetid++;

 facetid->color=DARKGREEN;
 facetid->nedges=3;                         
 facetid->edge[0]=1003;                           
 facetid->edge[1]=1002;      
 facetid->edge[2]=1036;
 facetid++;

 facetid->color=DARKGREEN;
 facetid->nedges=3;                        
 facetid->edge[0]=1004;                           
 facetid->edge[1]=1003;      
 facetid->edge[2]=1036;
 facetid++;

 facetid->color=DARKGREEN;
 facetid->nedges=3;                             
 facetid->edge[0]=1005;                       
 facetid->edge[1]=1004;      
 facetid->edge[2]=1036;
 facetid++;

 facetid->color=DARKGREEN;   
 facetid->nedges=3;                           
 facetid->edge[0]=998;                           
 facetid->edge[1]=1005;      
 facetid->edge[2]=1036;
 facetid++;                  

                                 //++++++ Cone X 2 4  
 facetid->color=DARKGREEN;
 facetid->nedges=3;                             
 facetid->edge[0]=1014;                            
 facetid->edge[1]=1015;
 facetid->edge[2]=1037; 
 facetid++;

 facetid->color=DARKGREEN;
 facetid->nedges=3;                          
 facetid->edge[0]=1015;                   
 facetid->edge[1]=1016;     
 facetid->edge[2]=1037;
 facetid++;

 facetid->color=DARKGREEN;
 facetid->nedges=3;                             
 facetid->edge[0]=1016;                        
 facetid->edge[1]=1017;      
 facetid->edge[2]=1037;
 facetid++;

 facetid->color=DARKGREEN;
 facetid->nedges=3;                           
 facetid->edge[0]=1017;                           
 facetid->edge[1]=1018;      
 facetid->edge[2]=1037;
 facetid++;

 facetid->color=DARKGREEN;
 facetid->nedges=3;                         
 facetid->edge[0]=1018;                           
 facetid->edge[1]=1019;      
 facetid->edge[2]=1037;
 facetid++;

 facetid->color=DARKGREEN;
 facetid->nedges=3;                        
 facetid->edge[0]=1019;                           
 facetid->edge[1]=1020;      
 facetid->edge[2]=1037;
 facetid++;

 facetid->color=DARKGREEN;
 facetid->nedges=3;                             
 facetid->edge[0]=1020;                       
 facetid->edge[1]=1021;      
 facetid->edge[2]=1037;
 facetid++;

 facetid->color=DARKGREEN;  
 facetid->nedges=3;                           
 facetid->edge[0]=1021;                           
 facetid->edge[1]=1014;      
 facetid->edge[2]=1037;
 facetid++;                  

 //facetid->color=WHITE;        //++++++ XX R 1 
 //facetid->nedges=8;            
 //facetid->edge[0]=1038;
 //facetid->edge[1]=1039;
 //facetid->edge[2]=1040;
 //facetid->edge[3]=1041;            
 //facetid->edge[4]=1042;
 //facetid->edge[5]=1043;
 //facetid->edge[6]=1044;
 //facetid->edge[7]=1045;
 //facetid++;

 facetid->color=DARKGREEN;
 facetid->nedges=4;                             
 facetid->edge[0]=1038;                       
 facetid->edge[1]=1039;        
 facetid->edge[2]=1047; 
 facetid->edge[3]=1046;
 facetid++;

 facetid->color=DARKGREEN;
 facetid->nedges=4;                          
 facetid->edge[0]=1039;                           
 facetid->edge[1]=1040;      
 facetid->edge[2]=1048;
 facetid->edge[3]=1047;
 facetid++;

 facetid->color=DARKGREEN;
 facetid->nedges=4;                             
 facetid->edge[0]=1040;                      
 facetid->edge[1]=1041;      
 facetid->edge[2]=1049;
 facetid->edge[3]=1048;
 facetid++;

 facetid->color=DARKGREEN;
 facetid->nedges=4;                     
 facetid->edge[0]=1041;                           
 facetid->edge[1]=1042;      
 facetid->edge[2]=1050;
 facetid->edge[3]=1049;
 facetid++;

 facetid->color=DARKGREEN;
 facetid->nedges=4;                        
 facetid->edge[0]=1042;                           
 facetid->edge[1]=1043;      
 facetid->edge[2]=1051;
 facetid->edge[3]=1050;
 facetid++;

 facetid->color=DARKGREEN;
 facetid->nedges=4;                       
 facetid->edge[0]=1043;                           
 facetid->edge[1]=1044;      
 facetid->edge[2]=1052;
 facetid->edge[3]=1051;
 facetid++;

 facetid->color=DARKGREEN;
 facetid->nedges=4;                             
 facetid->edge[0]=1044;                   
 facetid->edge[1]=1045;      
 facetid->edge[2]=1053;
 facetid->edge[3]=1052;
 facetid++;

 facetid->color=DARKGREEN; 
 facetid->nedges=4;                          
 facetid->edge[0]=1045;                           
 facetid->edge[1]=1038;         
 facetid->edge[2]=1046;
 facetid->edge[3]=1053;
 facetid++;                    
  
 //facetid->color=WHITE;        //++++++ XX L 1 
 //facetid->nedges=8;                 
 //facetid->edge[0]=1054;
 //facetid->edge[1]=1055;
 //facetid->edge[2]=1056;
 //facetid->edge[3]=1057;            
 //facetid->edge[4]=1058;
 //facetid->edge[5]=1059;
 //facetid->edge[6]=1060;
 //facetid->edge[7]=1061;
 //facetid++;

 facetid->color=DARKGREEN;
 facetid->nedges=4;                             
 facetid->edge[0]=1062;                       
 facetid->edge[1]=1063;        
 facetid->edge[2]=1055; 
 facetid->edge[3]=1054;
 facetid++;

 facetid->color=DARKGREEN;
 facetid->nedges=4;                          
 facetid->edge[0]=1063;                           
 facetid->edge[1]=1064;      
 facetid->edge[2]=1056;
 facetid->edge[3]=1055;
 facetid++;

 facetid->color=DARKGREEN;
 facetid->nedges=4;                             
 facetid->edge[0]=1064;                      
 facetid->edge[1]=1065;      
 facetid->edge[2]=1057;
 facetid->edge[3]=1056;
 facetid++;

 facetid->color=DARKGREEN;
 facetid->nedges=4;                     
 facetid->edge[0]=1065;                           
 facetid->edge[1]=1066;      
 facetid->edge[2]=1058;
 facetid->edge[3]=1057;
 facetid++;

 facetid->color=DARKGREEN;
 facetid->nedges=4;                        
 facetid->edge[0]=1066;                           
 facetid->edge[1]=1067;      
 facetid->edge[2]=1059;
 facetid->edge[3]=1058;
 facetid++;

 facetid->color=DARKGREEN;
 facetid->nedges=4;                       
 facetid->edge[0]=1067;                           
 facetid->edge[1]=1068;      
 facetid->edge[2]=1060;
 facetid->edge[3]=1059;
 facetid++;

 facetid->color=DARKGREEN;
 facetid->nedges=4;                             
 facetid->edge[0]=1068;                   
 facetid->edge[1]=1069;      
 facetid->edge[2]=1061;
 facetid->edge[3]=1060;
 facetid++;

 facetid->color=DARKGREEN; 
 facetid->nedges=4;                          
 facetid->edge[0]=1069;                           
 facetid->edge[1]=1062;         
 facetid->edge[2]=1054;
 facetid->edge[3]=1061;
 facetid++;                    

 //facetid->color=WHITE;        //++++++ XX R 2
 //facetid->nedges=8; 
 //facetid->edge[0]=1070;
 //facetid->edge[1]=1071;
 //facetid->edge[2]=1072;
 //facetid->edge[3]=1073;            
 //facetid->edge[4]=1074;
 //facetid->edge[5]=1075;
 //facetid->edge[6]=1076;
 //facetid->edge[7]=1077;
 //facetid++;

 facetid->color=DARKGREEN;
 facetid->nedges=4;                             
 facetid->edge[0]=1070;                       
 facetid->edge[1]=1071;        
 facetid->edge[2]=1079; 
 facetid->edge[3]=1078;
 facetid++;

 facetid->color=DARKGREEN;
 facetid->nedges=4;                         
 facetid->edge[0]=1071;                           
 facetid->edge[1]=1072;      
 facetid->edge[2]=1080;
 facetid->edge[3]=1079;
 facetid++;

 facetid->color=DARKGREEN;
 facetid->nedges=4;                             
 facetid->edge[0]=1072;                       
 facetid->edge[1]=1073;      
 facetid->edge[2]=1081;
 facetid->edge[3]=1080;
 facetid++;

 facetid->color=DARKGREEN;
 facetid->nedges=4;                        
 facetid->edge[0]=1073;                           
 facetid->edge[1]=1074;      
 facetid->edge[2]=1082;
 facetid->edge[3]=1081;
 facetid++;

 facetid->color=DARKGREEN;
 facetid->nedges=4;                         
 facetid->edge[0]=1074;                           
 facetid->edge[1]=1075;      
 facetid->edge[2]=1083;
 facetid->edge[3]=1082;
 facetid++;

 facetid->color=DARKGREEN;
 facetid->nedges=4;                         
 facetid->edge[0]=1075;                           
 facetid->edge[1]=1076;      
 facetid->edge[2]=1084;
 facetid->edge[3]=1083;
 facetid++;

 facetid->color=DARKGREEN;
 facetid->nedges=4;                             
 facetid->edge[0]=1076;                       
 facetid->edge[1]=1077;      
 facetid->edge[2]=1085;
 facetid->edge[3]=1084;
 facetid++;

 facetid->color=DARKGREEN;
 facetid->nedges=4;                          
 facetid->edge[0]=1077;                           
 facetid->edge[1]=1070;      
 facetid->edge[2]=1078;
 facetid->edge[3]=1085;
 facetid++;                    

 //facetid->color=WHITE;        //++++++ XX L 2 
 //facetid->nedges=8; 
 //facetid->edge[0]=1086;               
 //facetid->edge[1]=1087;
 //facetid->edge[2]=1088;
 //facetid->edge[3]=1089;            
 //facetid->edge[4]=1090;
 //facetid->edge[5]=1091;
 //facetid->edge[6]=1092;
 //facetid->edge[7]=1093;
 //facetid++;

 facetid->color=DARKGREEN;
 facetid->nedges=4;                             
 facetid->edge[0]=1094;                          
 facetid->edge[1]=1095;        
 facetid->edge[2]=1087; 
 facetid->edge[3]=1086;
 facetid++;

 facetid->color=DARKGREEN;
 facetid->nedges=4;                           
 facetid->edge[0]=1095;                           
 facetid->edge[1]=1096;      
 facetid->edge[2]=1088;
 facetid->edge[3]=1087;
 facetid++;

 facetid->color=DARKGREEN;
 facetid->nedges=4;                             
 facetid->edge[0]=1096;                          
 facetid->edge[1]=1097;      
 facetid->edge[2]=1089;
 facetid->edge[3]=1088;
 facetid++;

 facetid->color=DARKGREEN;
 facetid->nedges=4;                          
 facetid->edge[0]=1097;                           
 facetid->edge[1]=1098;      
 facetid->edge[2]=1090;
 facetid->edge[3]=1089;
 facetid++;

 facetid->color=DARKGREEN;
 facetid->nedges=4;                         
 facetid->edge[0]=1098;                           
 facetid->edge[1]=1099;      
 facetid->edge[2]=1091;
 facetid->edge[3]=1090;
 facetid++;

 facetid->color=DARKGREEN;
 facetid->nedges=4;                         
 facetid->edge[0]=1099;                           
 facetid->edge[1]=1100;      
 facetid->edge[2]=1092;
 facetid->edge[3]=1091;
 facetid++;

 facetid->color=DARKGREEN;
 facetid->nedges=4;                             
 facetid->edge[0]=1100;                       
 facetid->edge[1]=1101;      
 facetid->edge[2]=1093;
 facetid->edge[3]=1092;
 facetid++;

 facetid->color=DARKGREEN;
 facetid->nedges=4;                         
 facetid->edge[0]=1101;            
 facetid->edge[1]=1094;      
 facetid->edge[2]=1086;
 facetid->edge[3]=1093;
 facetid++;                    
  
  //facetid->color=WHITE;        //+++++++XX R 3 
 //facetid->nedges=8; 
 //facetid->edge[0]=1102;
 //facetid->edge[1]=1103;
 //facetid->edge[2]=1104;
 //facetid->edge[3]=1105;            
 //facetid->edge[4]=1106;
 //facetid->edge[5]=1107;
 //facetid->edge[6]=1108;
 //facetid->edge[7]=1109;
 //facetid++;

 facetid->color=DARKGREEN;
 facetid->nedges=4;                             
 facetid->edge[0]=1102;                         
 facetid->edge[1]=1103;        
 facetid->edge[2]=1111; 
 facetid->edge[3]=1110;
 facetid++;

 facetid->color=DARKGREEN;
 facetid->nedges=4;                          
 facetid->edge[0]=1103;                           
 facetid->edge[1]=1104;      
 facetid->edge[2]=1112;
 facetid->edge[3]=1111;
 facetid++;

 facetid->color=DARKGREEN;
 facetid->nedges=4;                             
 facetid->edge[0]=1104;                        
 facetid->edge[1]=1105;      
 facetid->edge[2]=1113;
 facetid->edge[3]=1112;
 facetid++;

 facetid->color=DARKGREEN;
 facetid->nedges=4;                      
 facetid->edge[0]=1105;                           
 facetid->edge[1]=1106;      
 facetid->edge[2]=1114;
 facetid->edge[3]=1113;
 facetid++;

 facetid->color=DARKGREEN;
 facetid->nedges=4;                         
 facetid->edge[0]=1106;                           
 facetid->edge[1]=1107;      
 facetid->edge[2]=1115;
 facetid->edge[3]=1114;
 facetid++;

 facetid->color=DARKGREEN;
 facetid->nedges=4;                          
 facetid->edge[0]=1107;                           
 facetid->edge[1]=1108;      
 facetid->edge[2]=1116;
 facetid->edge[3]=1115;
 facetid++;

 facetid->color=DARKGREEN;
 facetid->nedges=4;                             
 facetid->edge[0]=1108;                        
 facetid->edge[1]=1109;      
 facetid->edge[2]=1117;
 facetid->edge[3]=1116;
 facetid++;

 facetid->color=DARKGREEN;
 facetid->nedges=4;                         
 facetid->edge[0]=1109;                           
 facetid->edge[1]=1102;      
 facetid->edge[2]=1110;
 facetid->edge[3]=1117;
 facetid++;                    
 
 //facetid->color=WHITE;        //++++++ XX L 3  
 //facetid->nedges=8; 
 //facetid->edge[0]=1118;
 //facetid->edge[1]=1119;
 //facetid->edge[2]=1120;
 //facetid->edge[3]=1121;            
 //facetid->edge[4]=1122;
 //facetid->edge[5]=1123;
 //facetid->edge[6]=1124;
 //facetid->edge[7]=1125;
 //facetid++;

 facetid->color=DARKGREEN;
 facetid->nedges=4;                             
 facetid->edge[0]=1126;                        
 facetid->edge[1]=1127;        
 facetid->edge[2]=1119; 
 facetid->edge[3]=1118;
 facetid++;

 facetid->color=DARKGREEN;
 facetid->nedges=4;                          
 facetid->edge[0]=1127;                           
 facetid->edge[1]=1128;      
 facetid->edge[2]=1120;
 facetid->edge[3]=1119;
 facetid++;

 facetid->color=DARKGREEN;
 facetid->nedges=4;                             
 facetid->edge[0]=1128;                          
 facetid->edge[1]=1129;      
 facetid->edge[2]=1121;
 facetid->edge[3]=1120;
 facetid++;

 facetid->color=DARKGREEN;
 facetid->nedges=4;                          
 facetid->edge[0]=1129;                           
 facetid->edge[1]=1130;      
 facetid->edge[2]=1122;
 facetid->edge[3]=1121;
 facetid++;

 facetid->color=DARKGREEN;
 facetid->nedges=4;                        
 facetid->edge[0]=1130;                           
 facetid->edge[1]=1131;      
 facetid->edge[2]=1123;
 facetid->edge[3]=1122;
 facetid++;

 facetid->color=DARKGREEN;
 facetid->nedges=4;                           
 facetid->edge[0]=1131;                           
 facetid->edge[1]=1132;      
 facetid->edge[2]=1124;
 facetid->edge[3]=1123;
 facetid++;

 facetid->color=DARKGREEN;
 facetid->nedges=4;                             
 facetid->edge[0]=1132;                       
 facetid->edge[1]=1133;      
 facetid->edge[2]=1125;
 facetid->edge[3]=1124;
 facetid++;

 facetid->color=DARKGREEN;
 facetid->nedges=4;                           
 facetid->edge[0]=1133;                           
 facetid->edge[1]=1126;      
 facetid->edge[2]=1118;
 facetid->edge[3]=1125;
 facetid++;                    

 //facetid->color=WHITE;      //++++++ XX L 4 
 //facetid->nedges=8; 
 //facetid->edge[0]=1134;
 //facetid->edge[1]=1135;
 //facetid->edge[2]=1136;
 //facetid->edge[3]=1137;            
 //facetid->edge[4]=1138;
 //facetid->edge[5]=1139;
 //facetid->edge[6]=1140;
 //facetid->edge[7]=1141;
 //facetid++;

 facetid->color=DARKGREEN;
 facetid->nedges=4;                             
 facetid->edge[0]=1134;                            
 facetid->edge[1]=1135;        
 facetid->edge[2]=1143; 
 facetid->edge[3]=1142;
 facetid++;

 facetid->color=DARKGREEN;
 facetid->nedges=4;                            
 facetid->edge[0]=1135;                           
 facetid->edge[1]=1136;      
 facetid->edge[2]=1144;
 facetid->edge[3]=1143;
 facetid++;

 facetid->color=DARKGREEN;
 facetid->nedges=4;                             
 facetid->edge[0]=1136;                          
 facetid->edge[1]=1137;      
 facetid->edge[2]=1145;
 facetid->edge[3]=1144;
 facetid++;

 facetid->color=DARKGREEN;
 facetid->nedges=4;                          
 facetid->edge[0]=1137;                           
 facetid->edge[1]=1138;      
 facetid->edge[2]=1146;
 facetid->edge[3]=1145;
 facetid++;

 facetid->color=DARKGREEN;
 facetid->nedges=4;                          
 facetid->edge[0]=1138;                           
 facetid->edge[1]=1139;      
 facetid->edge[2]=1147;
 facetid->edge[3]=1146;
 facetid++;

 facetid->color=DARKGREEN;
 facetid->nedges=4;                          
 facetid->edge[0]=1139;                           
 facetid->edge[1]=1140;      
 facetid->edge[2]=1148;
 facetid->edge[3]=1147;
 facetid++;

 facetid->color=DARKGREEN;
 facetid->nedges=4;                             
 facetid->edge[0]=1140;                       
 facetid->edge[1]=1141;      
 facetid->edge[2]=1149;
 facetid->edge[3]=1148;
 facetid++;

 facetid->color=DARKGREEN;
 facetid->nedges=4;                         
 facetid->edge[0]=1141;                           
 facetid->edge[1]=1134;      
 facetid->edge[2]=1142;
 facetid->edge[3]=1149;
 facetid++;                    

 //facetid->color=WHITE;      //++++++XX R 4
 //facetid->nedges=8; 
 //facetid->edge[0]=1150;
 //facetid->edge[1]=1151;
 //facetid->edge[2]=1152;
 //facetid->edge[3]=1153;            
 //facetid->edge[4]=1154;
 //facetid->edge[5]=1155;
 //facetid->edge[6]=1156;
 //facetid->edge[7]=1157;
 //facetid++;

 facetid->color=DARKGREEN;
 facetid->nedges=4;                             
 facetid->edge[0]=1158;                            
 facetid->edge[1]=1159;        
 facetid->edge[2]=1151;
 facetid->edge[3]=1150;
 facetid++;

 facetid->color=DARKGREEN;
 facetid->nedges=4;                            
 facetid->edge[0]=1159;                           
 facetid->edge[1]=1160;      
 facetid->edge[2]=1152;
 facetid->edge[3]=1151;
 facetid++;

 facetid->color=DARKGREEN;
 facetid->nedges=4;                             
 facetid->edge[0]=1160;                          
 facetid->edge[1]=1161;      
 facetid->edge[2]=1153;
 facetid->edge[3]=1152;
 facetid++;

 facetid->color=DARKGREEN;
 facetid->nedges=4;                          
 facetid->edge[0]=1161;                           
 facetid->edge[1]=1162;      
 facetid->edge[2]=1154;
 facetid->edge[3]=1153;
 facetid++;

 facetid->color=DARKGREEN;
 facetid->nedges=4;                          
 facetid->edge[0]=1162;                           
 facetid->edge[1]=1163;      
 facetid->edge[2]=1155;
 facetid->edge[3]=1154;
 facetid++;

 facetid->color=DARKGREEN;
 facetid->nedges=4;                          
 facetid->edge[0]=1163;                           
 facetid->edge[1]=1164;      
 facetid->edge[2]=1156;
 facetid->edge[3]=1155;
 facetid++;

 facetid->color=DARKGREEN;
 facetid->nedges=4;                             
 facetid->edge[0]=1164;                       
 facetid->edge[1]=1165;      
 facetid->edge[2]=1157;
 facetid->edge[3]=1156;
 facetid++;

 facetid->color=DARKGREEN;
 facetid->nedges=4;                         
 facetid->edge[0]=1165;                         
 facetid->edge[1]=1158;    
 facetid->edge[2]=1150;
 facetid->edge[3]=1157;
 facetid++;                    

				    //++++++ Cone XX R 1    
 facetid->color=DARKGREEN;
 facetid->nedges=3;                             
 facetid->edge[0]=1046;                            
 facetid->edge[1]=1047;
 facetid->edge[2]=1166; 
 facetid++;

 facetid->color=DARKGREEN;
 facetid->nedges=3;                          
 facetid->edge[0]=1047;                   
 facetid->edge[1]=1048;     
 facetid->edge[2]=1166;
 facetid++;

 facetid->color=DARKGREEN;
 facetid->nedges=3;                             
 facetid->edge[0]=1048;                        
 facetid->edge[1]=1049;      
 facetid->edge[2]=1166;
 facetid++;

 facetid->color=DARKGREEN;
 facetid->nedges=3;                           
 facetid->edge[0]=1049;                           
 facetid->edge[1]=1050;      
 facetid->edge[2]=1166;
 facetid++;

 facetid->color=DARKGREEN;
 facetid->nedges=3;                         
 facetid->edge[0]=1050;                           
 facetid->edge[1]=1051;      
 facetid->edge[2]=1166;
 facetid++;

 facetid->color=DARKGREEN;
 facetid->nedges=3;                        
 facetid->edge[0]=1051;                           
 facetid->edge[1]=1052;      
 facetid->edge[2]=1166;
 facetid++;

 facetid->color=DARKGREEN;
 facetid->nedges=3;                             
 facetid->edge[0]=1052;                       
 facetid->edge[1]=1053;      
 facetid->edge[2]=1166;
 facetid++;

 facetid->color=DARKGREEN;
 facetid->nedges=3;                           
 facetid->edge[0]=1053;                           
 facetid->edge[1]=1046;      
 facetid->edge[2]=1166;
 facetid++;                 
 				    //++++++ Cone XX L 1    
 facetid->color=DARKGREEN;
 facetid->nedges=3;                             
 facetid->edge[0]=1063;                            
 facetid->edge[1]=1062;
 facetid->edge[2]=1167; 
 facetid++;

 facetid->color=DARKGREEN;
 facetid->nedges=3;                          
 facetid->edge[0]=1064;                   
 facetid->edge[1]=1063;     
 facetid->edge[2]=1167;
 facetid++;

 facetid->color=DARKGREEN;
 facetid->nedges=3;                             
 facetid->edge[0]=1065;                        
 facetid->edge[1]=1064;      
 facetid->edge[2]=1167;
 facetid++;

 facetid->color=DARKGREEN;
 facetid->nedges=3;                           
 facetid->edge[0]=1066;                           
 facetid->edge[1]=1065;      
 facetid->edge[2]=1167;
 facetid++;

 facetid->color=DARKGREEN;
 facetid->nedges=3;                         
 facetid->edge[0]=1067;                           
 facetid->edge[1]=1066;      
 facetid->edge[2]=1167;
 facetid++;

 facetid->color=DARKGREEN;
 facetid->nedges=3;                        
 facetid->edge[0]=1068;                           
 facetid->edge[1]=1067;      
 facetid->edge[2]=1167;
 facetid++;

 facetid->color=DARKGREEN;
 facetid->nedges=3;                             
 facetid->edge[0]=1069;                       
 facetid->edge[1]=1068;      
 facetid->edge[2]=1167;
 facetid++;

 facetid->color=DARKGREEN; 
 facetid->nedges=3;                           
 facetid->edge[0]=1062;                           
 facetid->edge[1]=1069;      
 facetid->edge[2]=1167;
 facetid++;                    //++++++ Cone XX L 2   
 
 facetid->color=DARKGREEN;
 facetid->nedges=3;                             
 facetid->edge[0]=1078;                            
 facetid->edge[1]=1079;
 facetid->edge[2]=1168; 
 facetid++;

 facetid->color=DARKGREEN;
 facetid->nedges=3;                          
 facetid->edge[0]=1079;                   
 facetid->edge[1]=1080;     
 facetid->edge[2]=1168;
 facetid++;

 facetid->color=DARKGREEN;
 facetid->nedges=3;                             
 facetid->edge[0]=1080;                        
 facetid->edge[1]=1081;      
 facetid->edge[2]=1168;
 facetid++;

 facetid->color=DARKGREEN;
 facetid->nedges=3;                           
 facetid->edge[0]=1081;                           
 facetid->edge[1]=1082;      
 facetid->edge[2]=1168;
 facetid++;

 facetid->color=DARKGREEN;
 facetid->nedges=3;                         
 facetid->edge[0]=1082;                           
 facetid->edge[1]=1083;      
 facetid->edge[2]=1168;
 facetid++;

 facetid->color=DARKGREEN;
 facetid->nedges=3;                        
 facetid->edge[0]=1083;                           
 facetid->edge[1]=1084;      
 facetid->edge[2]=1168;
 facetid++;

 facetid->color=DARKGREEN;
 facetid->nedges=3;                             
 facetid->edge[0]=1084;                       
 facetid->edge[1]=1085;      
 facetid->edge[2]=1168;
 facetid++;

 facetid->color=DARKGREEN; 
 facetid->nedges=3;                           
 facetid->edge[0]=1085;                           
 facetid->edge[1]=1078;      
 facetid->edge[2]=1168;
 facetid++;                 

                              //++++++ Cone XX R 2  
 facetid->color=DARKGREEN;              
 facetid->nedges=3;                             
 facetid->edge[0]=1095;                            
 facetid->edge[1]=1094;
 facetid->edge[2]=1169; 
 facetid++;

 facetid->color=DARKGREEN;
 facetid->nedges=3;                          
 facetid->edge[0]=1096;                  
 facetid->edge[1]=1095;     
 facetid->edge[2]=1169;
 facetid++;

 facetid->color=DARKGREEN;
 facetid->nedges=3;                             
 facetid->edge[0]=1097;                        
 facetid->edge[1]=1096;      
 facetid->edge[2]=1169;
 facetid++;

 facetid->color=DARKGREEN;
 facetid->nedges=3;                           
 facetid->edge[0]=1098;                           
 facetid->edge[1]=1097;      
 facetid->edge[2]=1169;
 facetid++;

 facetid->color=DARKGREEN;
 facetid->nedges=3;                         
 facetid->edge[0]=1099;                           
 facetid->edge[1]=1098;      
 facetid->edge[2]=1169;
 facetid++;

 facetid->color=DARKGREEN;
 facetid->nedges=3;                        
 facetid->edge[0]=1100;                           
 facetid->edge[1]=1099;      
 facetid->edge[2]=1169;
 facetid++;

 facetid->color=DARKGREEN;
 facetid->nedges=3;                             
 facetid->edge[0]=1101;                       
 facetid->edge[1]=1100;      
 facetid->edge[2]=1169;
 facetid++;

 facetid->color=DARKGREEN; 
 facetid->nedges=3;                           
 facetid->edge[0]=1094;                           
 facetid->edge[1]=1101;      
 facetid->edge[2]=1169;
 facetid++;                 

                              //++++++ Cone XX 1 3 
 facetid->color=DARKGREEN;              
 facetid->nedges=3;                             
 facetid->edge[0]=1110;                            
 facetid->edge[1]=1111;
 facetid->edge[2]=1170; 
 facetid++;

 facetid->color=DARKGREEN;
 facetid->nedges=3;                          
 facetid->edge[0]=1111;                   
 facetid->edge[1]=1112;     
 facetid->edge[2]=1170;
 facetid++;

 facetid->color=DARKGREEN;
 facetid->nedges=3;                             
 facetid->edge[0]=1112;                        
 facetid->edge[1]=1113;      
 facetid->edge[2]=1170;
 facetid++;

 facetid->color=DARKGREEN;
 facetid->nedges=3;                           
 facetid->edge[0]=1113;                           
 facetid->edge[1]=1114;      
 facetid->edge[2]=1170;
 facetid++;

 facetid->color=DARKGREEN;
 facetid->nedges=3;                         
 facetid->edge[0]=1114;                           
 facetid->edge[1]=1115;      
 facetid->edge[2]=1170;
 facetid++;

 facetid->color=DARKGREEN;
 facetid->nedges=3;                        
 facetid->edge[0]=1115;                           
 facetid->edge[1]=1116;      
 facetid->edge[2]=1170;
 facetid++;

 facetid->color=DARKGREEN;
 facetid->nedges=3;                             
 facetid->edge[0]=1116;                       
 facetid->edge[1]=1117;      
 facetid->edge[2]=1170;
 facetid++;

 facetid->color=DARKGREEN;  
 facetid->nedges=3;                           
 facetid->edge[0]=1117;                           
 facetid->edge[1]=1110;      
 facetid->edge[2]=1170;
 facetid++;                 

                               //++++++ Cone XX 2 3  
 facetid->color=DARKGREEN;
 facetid->nedges=3;                                             
 facetid->edge[0]=1127;                            
 facetid->edge[1]=1126;
 facetid->edge[2]=1171; 
 facetid++;

 facetid->color=DARKGREEN;
 facetid->nedges=3;                          
 facetid->edge[0]=1128;                   
 facetid->edge[1]=1127;     
 facetid->edge[2]=1171;
 facetid++;

 facetid->color=DARKGREEN;
 facetid->nedges=3;                             
 facetid->edge[0]=1129;                        
 facetid->edge[1]=1128;      
 facetid->edge[2]=1171;
 facetid++;

 facetid->color=DARKGREEN;
 facetid->nedges=3;                           
 facetid->edge[0]=1130;                           
 facetid->edge[1]=1129;      
 facetid->edge[2]=1171;
 facetid++;

 facetid->color=DARKGREEN;
 facetid->nedges=3;                         
 facetid->edge[0]=1131;                           
 facetid->edge[1]=1130;      
 facetid->edge[2]=1171;
 facetid++;

 facetid->color=DARKGREEN;
 facetid->nedges=3;                        
 facetid->edge[0]=1132;                           
 facetid->edge[1]=1131;      
 facetid->edge[2]=1171;
 facetid++;

 facetid->color=DARKGREEN;
 facetid->nedges=3;                             
 facetid->edge[0]=1133;                       
 facetid->edge[1]=1132;      
 facetid->edge[2]=1171;
 facetid++;

 facetid->color=DARKGREEN;   
 facetid->nedges=3;                           
 facetid->edge[0]=1126;                           
 facetid->edge[1]=1133;      
 facetid->edge[2]=1171;
 facetid++;                 

                                 //++++++ XX Cone R 4  
 facetid->color=DARKGREEN;
 facetid->nedges=3;                             
 facetid->edge[0]=1135;                            
 facetid->edge[1]=1134;
 facetid->edge[2]=1172; 
 facetid++;

 facetid->color=DARKGREEN;
 facetid->nedges=3;                          
 facetid->edge[0]=1136;                   
 facetid->edge[1]=1135;     
 facetid->edge[2]=1172;
 facetid++;

 facetid->color=DARKGREEN;
 facetid->nedges=3;                             
 facetid->edge[0]=1137;                        
 facetid->edge[1]=1136;      
 facetid->edge[2]=1172;
 facetid++;

 facetid->color=DARKGREEN;
 facetid->nedges=3;                           
 facetid->edge[0]=1138;                           
 facetid->edge[1]=1137;      
 facetid->edge[2]=1172;
 facetid++;

 facetid->color=DARKGREEN;
 facetid->nedges=3;                         
 facetid->edge[0]=1139;                           
 facetid->edge[1]=1138;      
 facetid->edge[2]=1172;
 facetid++;

 facetid->color=DARKGREEN;
 facetid->nedges=3;                        
 facetid->edge[0]=1140;                           
 facetid->edge[1]=1139;      
 facetid->edge[2]=1172;
 facetid++;

 facetid->color=DARKGREEN;
 facetid->nedges=3;                             
 facetid->edge[0]=1141;                       
 facetid->edge[1]=1140;      
 facetid->edge[2]=1172;
 facetid++;

 facetid->color=DARKGREEN;   
 facetid->nedges=3;                           
 facetid->edge[0]=1134;                           
 facetid->edge[1]=1141;      
 facetid->edge[2]=1172;
 facetid++;                  

                                 //++++++ XX Cone L 4  
 facetid->color=DARKGREEN;
 facetid->nedges=3;                             
 facetid->edge[0]=1150;                            
 facetid->edge[1]=1151;
 facetid->edge[2]=1173; 
 facetid++;

 facetid->color=DARKGREEN;
 facetid->nedges=3;                          
 facetid->edge[0]=1151;                   
 facetid->edge[1]=1152;     
 facetid->edge[2]=1173;
 facetid++;

 facetid->color=DARKGREEN;
 facetid->nedges=3;                             
 facetid->edge[0]=1152;                        
 facetid->edge[1]=1153;      
 facetid->edge[2]=1173;
 facetid++;

 facetid->color=DARKGREEN;
 facetid->nedges=3;                           
 facetid->edge[0]=1153;                           
 facetid->edge[1]=1154;      
 facetid->edge[2]=1173;
 facetid++;

 facetid->color=DARKGREEN;
 facetid->nedges=3;                         
 facetid->edge[0]=1154;                           
 facetid->edge[1]=1155;      
 facetid->edge[2]=1173;
 facetid++;

 facetid->color=DARKGREEN;
 facetid->nedges=3;                        
 facetid->edge[0]=1155;                           
 facetid->edge[1]=1156;      
 facetid->edge[2]=1173;
 facetid++;

 facetid->color=DARKGREEN;
 facetid->nedges=3;                             
 facetid->edge[0]=1156;                       
 facetid->edge[1]=1157;      
 facetid->edge[2]=1173;
 facetid++;

 facetid->color=DARKGREEN;
 facetid->nedges=3;                           
 facetid->edge[0]=1157;                           
 facetid->edge[1]=1150;      
 facetid->edge[2]=1173;
 facetid++;                  
  
 //facetid->color=WHITE;    //++++++++++++ XXX R 1  
 //facetid->nedges=8; 
 //facetid->edge[0]=754;
 //facetid->edge[1]=755;
 //facetid->edge[2]=756;
 //facetid->edge[3]=757;            
 //facetid->edge[4]=758;
 //facetid->edge[5]=759;
 //facetid->edge[6]=760;
 //facetid->edge[7]=761;
 //facetid++;

 facetid->color=DARKGRAY;
 facetid->nedges=4;                             
 facetid->edge[0]=1174;                          
 facetid->edge[1]=1175;        
 facetid->edge[2]=1183; 
 facetid->edge[3]=1182;
 facetid++;

 facetid->color=DARKGRAY;
 facetid->nedges=4;                          
 facetid->edge[0]=1175;                           
 facetid->edge[1]=1176;      
 facetid->edge[2]=1184;
 facetid->edge[3]=1183;
 facetid++;

 facetid->color=DARKGRAY;
 facetid->nedges=4;                             
 facetid->edge[0]=1176;                        
 facetid->edge[1]=1177;      
 facetid->edge[2]=1185;
 facetid->edge[3]=1184;
 facetid++;

 facetid->color=DARKGRAY;
 facetid->nedges=4;                           
 facetid->edge[0]=1177;                           
 facetid->edge[1]=1178;      
 facetid->edge[2]=1186;
 facetid->edge[3]=1185;
 facetid++;

 facetid->color=DARKGRAY;
 facetid->nedges=4;                         
 facetid->edge[0]=1178;                           
 facetid->edge[1]=1179;      
 facetid->edge[2]=1187;
 facetid->edge[3]=1186;
 facetid++;

 facetid->color=DARKGRAY;
 facetid->nedges=4;                        
 facetid->edge[0]=1179;                           
 facetid->edge[1]=1180;      
 facetid->edge[2]=1188;
 facetid->edge[3]=1187;
 facetid++;

 facetid->color=DARKGRAY; 
 facetid->nedges=4;                             
 facetid->edge[0]=1180;                       
 facetid->edge[1]=1181;      
 facetid->edge[2]=1189;
 facetid->edge[3]=1188;
 facetid++;

 facetid->color=DARKGRAY;
 facetid->nedges=4;                           
 facetid->edge[0]=1181;                           
 facetid->edge[1]=1174;      
 facetid->edge[2]=1182;
 facetid->edge[3]=1189;
 facetid++;                   

 //facetid->color=WHITE;    //+++++++++++++ XXX L 1   
 //facetid->nedges=8; 
 //facetid->edge[0]=1190;
 //facetid->edge[1]=1191;
 //facetid->edge[2]=1192;
 //facetid->edge[3]=1193;            
 //facetid->edge[4]=1194;
 //facetid->edge[5]=1195;
 //facetid->edge[6]=1196;
 //facetid->edge[7]=1197;
 //facetid++;

 facetid->color=DARKGRAY;
 facetid->nedges=4;                             
 facetid->edge[0]=1190;                          
 facetid->edge[1]=1191;        
 facetid->edge[2]=1199; 
 facetid->edge[3]=1198;
 facetid++;

 facetid->color=DARKGRAY;
 facetid->nedges=4;                          
 facetid->edge[0]=1191;                           
 facetid->edge[1]=1192;      
 facetid->edge[2]=1200;
 facetid->edge[3]=1199;
 facetid++;

 facetid->color=DARKGRAY;
 facetid->nedges=4;                             
 facetid->edge[0]=1192;                        
 facetid->edge[1]=1193;      
 facetid->edge[2]=1201;
 facetid->edge[3]=1200;
 facetid++;

 facetid->color=DARKGRAY;
 facetid->nedges=4;                           
 facetid->edge[0]=1193;                           
 facetid->edge[1]=1194;      
 facetid->edge[2]=1202;
 facetid->edge[3]=1201;
 facetid++;

 facetid->color=DARKGRAY;
 facetid->nedges=4;                         
 facetid->edge[0]=1194;                           
 facetid->edge[1]=1195;      
 facetid->edge[2]=1203;
 facetid->edge[3]=1202;
 facetid++;

 facetid->color=DARKGRAY;
 facetid->nedges=4;                        
 facetid->edge[0]=1195;                           
 facetid->edge[1]=1196;      
 facetid->edge[2]=1204;
 facetid->edge[3]=1203;
 facetid++;

 facetid->color=DARKGRAY; 
 facetid->nedges=4;                             
 facetid->edge[0]=1196;                      
 facetid->edge[1]=1197;      
 facetid->edge[2]=1205;
 facetid->edge[3]=1204;
 facetid++;

 facetid->color=DARKGRAY;
 facetid->nedges=4;                           
 facetid->edge[0]=1197;                           
 facetid->edge[1]=1190;      
 facetid->edge[2]=1198;
 facetid->edge[3]=1205;
 facetid++;                    

 //facetid->color=WHITE;    //+++++++++++++++ XXX L 2
 //facetid->nedges=8; 
 //facetid->edge[0]=1206;
 //facetid->edge[1]=1207;
 //facetid->edge[2]=1208;
 //facetid->edge[3]=1209;            
 //facetid->edge[4]=1210;
 //facetid->edge[5]=1211;
 //facetid->edge[6]=1212;
 //facetid->edge[7]=1213;
 //facetid++;

 facetid->color=DARKGRAY;
 facetid->nedges=4;                             
 facetid->edge[0]=1214;                         
 facetid->edge[1]=1215;        
 facetid->edge[2]=1207; 
 facetid->edge[3]=1206;
 facetid++;

 facetid->color=DARKGRAY;
 facetid->nedges=4;                          
 facetid->edge[0]=1215;                           
 facetid->edge[1]=1216;      
 facetid->edge[2]=1208;
 facetid->edge[3]=1207;
 facetid++;

 facetid->color=DARKGRAY;
 facetid->nedges=4;                             
 facetid->edge[0]=1216;                        
 facetid->edge[1]=1217;      
 facetid->edge[2]=1209;
 facetid->edge[3]=1208;
 facetid++;

 facetid->color=DARKGRAY;
 facetid->nedges=4;                           
 facetid->edge[0]=1217;                           
 facetid->edge[1]=1218;      
 facetid->edge[2]=1210;
 facetid->edge[3]=1209;
 facetid++;

 facetid->color=DARKGRAY;
 facetid->nedges=4;                         
 facetid->edge[0]=1218;                           
 facetid->edge[1]=1219;      
 facetid->edge[2]=1211;
 facetid->edge[3]=1210;
 facetid++;

 facetid->color=DARKGRAY;
 facetid->nedges=4;                        
 facetid->edge[0]=1219;                           
 facetid->edge[1]=1220;      
 facetid->edge[2]=1212;
 facetid->edge[3]=1211;
 facetid++;

 facetid->color=DARKGRAY; 
 facetid->nedges=4;                             
 facetid->edge[0]=1220;                       
 facetid->edge[1]=1221;      
 facetid->edge[2]=1213;
 facetid->edge[3]=1212;
 facetid++;

 facetid->color=DARKGRAY;
 facetid->nedges=4;                           
 facetid->edge[0]=1221;                           
 facetid->edge[1]=1214;      
 facetid->edge[2]=1206;
 facetid->edge[3]=1213;
 facetid++;                    
 
 //facetid->color=WHITE;    //++++++++++++ XXX R 2   
 //facetid->nedges=8; 
 //facetid->edge[0]=1222;
 //facetid->edge[1]=1223;
 //facetid->edge[2]=1224;
 //facetid->edge[3]=1225;            
 //facetid->edge[4]=1226;
 //facetid->edge[5]=1227;
 //facetid->edge[6]=1228;
 //facetid->edge[7]=1229;
 //facetid++;

 facetid->color=DARKGRAY;
 facetid->nedges=4;                             
 facetid->edge[0]=1230;                          
 facetid->edge[1]=1231;        
 facetid->edge[2]=1223; 
 facetid->edge[3]=1222;
 facetid++;

 facetid->color=DARKGRAY;
 facetid->nedges=4;                          
 facetid->edge[0]=1231;                           
 facetid->edge[1]=1232;      
 facetid->edge[2]=1224;
 facetid->edge[3]=1223;
 facetid++;

 facetid->color=DARKGRAY;
 facetid->nedges=4;                             
 facetid->edge[0]=1232;                        
 facetid->edge[1]=1233;      
 facetid->edge[2]=1225;
 facetid->edge[3]=1224;
 facetid++;

 facetid->color=DARKGRAY;
 facetid->nedges=4;                           
 facetid->edge[0]=1233;                           
 facetid->edge[1]=1234;      
 facetid->edge[2]=1226;
 facetid->edge[3]=1225;
 facetid++;

 facetid->color=DARKGRAY;
 facetid->nedges=4;                         
 facetid->edge[0]=1234;                           
 facetid->edge[1]=1235;      
 facetid->edge[2]=1227;
 facetid->edge[3]=1226;
 facetid++;

 facetid->color=DARKGRAY;
 facetid->nedges=4;                        
 facetid->edge[0]=1235;                           
 facetid->edge[1]=1236;      
 facetid->edge[2]=1228;
 facetid->edge[3]=1227;
 facetid++;

 facetid->color=DARKGRAY; 
 facetid->nedges=4;                             
 facetid->edge[0]=1236;                      
 facetid->edge[1]=1237;      
 facetid->edge[2]=1229;
 facetid->edge[3]=1228;
 facetid++;

 facetid->color=DARKGRAY;
 facetid->nedges=4;                           
 facetid->edge[0]=1237;                           
 facetid->edge[1]=1230;      
 facetid->edge[2]=1222;
 facetid->edge[3]=1229;
 facetid++;                    
   
 //facetid->color=WHITE;    //+++++++ XXX L 3   
 //facetid->nedges=8;             
 //facetid->edge[0]=1238;
 //facetid->edge[1]=1239;
 //facetid->edge[2]=1240;
 //facetid->edge[3]=1241;            
 //facetid->edge[4]=1242;
 //facetid->edge[5]=1243;
 //facetid->edge[6]=1244;
 //facetid->edge[7]=1245;
 //facetid++;

 facetid->color=DARKGRAY;
 facetid->nedges=4;                             
 facetid->edge[0]=1238;                         
 facetid->edge[1]=1239;        
 facetid->edge[2]=1247; 
 facetid->edge[3]=1246;
 facetid++;

 facetid->color=DARKGRAY;
 facetid->nedges=4;                          
 facetid->edge[0]=1239;                           
 facetid->edge[1]=1240;      
 facetid->edge[2]=1248;
 facetid->edge[3]=1247;
 facetid++;

 facetid->color=DARKGRAY;
 facetid->nedges=4;                             
 facetid->edge[0]=1240;                        
 facetid->edge[1]=1241;      
 facetid->edge[2]=1249;
 facetid->edge[3]=1248;
 facetid++;

 facetid->color=DARKGRAY;
 facetid->nedges=4;                           
 facetid->edge[0]=1241;                           
 facetid->edge[1]=1242;      
 facetid->edge[2]=1250;
 facetid->edge[3]=1249;
 facetid++;

 facetid->color=DARKGRAY;
 facetid->nedges=4;                         
 facetid->edge[0]=1242;                           
 facetid->edge[1]=1243;      
 facetid->edge[2]=1251;
 facetid->edge[3]=1250;
 facetid++;

 facetid->color=DARKGRAY;
 facetid->nedges=4;                        
 facetid->edge[0]=1243;                           
 facetid->edge[1]=1244;      
 facetid->edge[2]=1252;
 facetid->edge[3]=1251;
 facetid++;

 facetid->color=DARKGRAY; 
 facetid->nedges=4;                             
 facetid->edge[0]=1244;                       
 facetid->edge[1]=1245;      
 facetid->edge[2]=1253;
 facetid->edge[3]=1252;
 facetid++;

 facetid->color=DARKGRAY;
 facetid->nedges=4;                           
 facetid->edge[0]=1245;                           
 facetid->edge[1]=1238;      
 facetid->edge[2]=1246;
 facetid->edge[3]=1253;
 facetid++;                    
 
 //facetid->color=WHITE;    //++++++ XXX R 3 
 //facetid->nedges=8;          
 //facetid->edge[0]=1254;
 //facetid->edge[1]=1255;
 //facetid->edge[2]=1256;
 //facetid->edge[3]=1257;            
 //facetid->edge[4]=1258;
 //facetid->edge[5]=1259;
 //facetid->edge[6]=1260;
 //facetid->edge[7]=1261;
 //facetid++;

 facetid->color=DARKGRAY;
 facetid->nedges=4;                             
 facetid->edge[0]=1254;                          
 facetid->edge[1]=1255;   
 facetid->edge[2]=1263; 
 facetid->edge[3]=1262;
 facetid++;

 facetid->color=DARKGRAY;
 facetid->nedges=4;                          
 facetid->edge[0]=1255;                     
 facetid->edge[1]=1256;      
 facetid->edge[2]=1264;
 facetid->edge[3]=1263;
 facetid++;

 facetid->color=DARKGRAY;
 facetid->nedges=4;                             
 facetid->edge[0]=1256;                        
 facetid->edge[1]=1257;  
 facetid->edge[2]=1265;
 facetid->edge[3]=1264;
 facetid++;

 facetid->color=DARKGRAY;
 facetid->nedges=4;                           
 facetid->edge[0]=1257;                      
 facetid->edge[1]=1258;      
 facetid->edge[2]=1266;
 facetid->edge[3]=1265;
 facetid++;

 facetid->color=DARKGRAY;
 facetid->nedges=4;                         
 facetid->edge[0]=1258;                     
 facetid->edge[1]=1259;      
 facetid->edge[2]=1267;
 facetid->edge[3]=1266;
 facetid++;

 facetid->color=DARKGRAY;
 facetid->nedges=4;                        
 facetid->edge[0]=1259;                           
 facetid->edge[1]=1260;   
 facetid->edge[2]=1268;
 facetid->edge[3]=1267;
 facetid++;

 facetid->color=DARKGRAY;
 facetid->nedges=4;                             
 facetid->edge[0]=1260;                       
 facetid->edge[1]=1261;  
 facetid->edge[2]=1269;
 facetid->edge[3]=1268;
 facetid++;

 facetid->color=DARKGRAY;
 facetid->nedges=4;                           
 facetid->edge[0]=1261;                           
 facetid->edge[1]=1254;      
 facetid->edge[2]=1262;
 facetid->edge[3]=1269;
 facetid++;                 

 //facetid->color=WHITE;    //++++++ XXX L 4   
 //facetid->nedges=8;      
 //facetid->edge[0]=1270;
 //facetid->edge[1]=1271;
 //facetid->edge[2]=1272;
 //facetid->edge[3]=1273;            
 //facetid->edge[4]=1274;
 //facetid->edge[5]=1275;
 //facetid->edge[6]=1276;
 //facetid->edge[7]=1277;
 //facetid++;

 facetid->color=DARKGRAY;
 facetid->nedges=4;                             
 facetid->edge[0]=1271;                          
 facetid->edge[1]=1270;   
 facetid->edge[2]=1278; 
 facetid->edge[3]=1279;
 facetid++;

 facetid->color=DARKGRAY;
 facetid->nedges=4;                          
 facetid->edge[0]=1272;                     
 facetid->edge[1]=1271;      
 facetid->edge[2]=1279;
 facetid->edge[3]=1280;
 facetid++;

 facetid->color=DARKGRAY;
 facetid->nedges=4;                             
 facetid->edge[0]=1273;                        
 facetid->edge[1]=1272;  
 facetid->edge[2]=1280;
 facetid->edge[3]=1281;
 facetid++;

 facetid->color=DARKGRAY;
 facetid->nedges=4;                           
 facetid->edge[0]=1274;                      
 facetid->edge[1]=1273;      
 facetid->edge[2]=1281;
 facetid->edge[3]=1282;
 facetid++;

 facetid->color=DARKGRAY;
 facetid->nedges=4;                         
 facetid->edge[0]=1275;                     
 facetid->edge[1]=1274;      
 facetid->edge[2]=1282;
 facetid->edge[3]=1283;
 facetid++;

 facetid->color=DARKGRAY;
 facetid->nedges=4;                        
 facetid->edge[0]=1276;                           
 facetid->edge[1]=1275;   
 facetid->edge[2]=1283;
 facetid->edge[3]=1284;
 facetid++;

 facetid->color=DARKGRAY;
 facetid->nedges=4;                             
 facetid->edge[0]=1277;                       
 facetid->edge[1]=1276;  
 facetid->edge[2]=1284;
 facetid->edge[3]=1285;
 facetid++;

 facetid->color=DARKGRAY;
 facetid->nedges=4;                           
 facetid->edge[0]=1285;                          
 facetid->edge[1]=1278;    
 facetid->edge[2]=1270;
 facetid->edge[3]=1277;
 facetid++;                 
 
 //facetid->color=WHITE;    //++++++ XXX R 4   
 //facetid->nedges=8;        
 //facetid->edge[0]=1286;
 //facetid->edge[1]=1287;
 //facetid->edge[2]=1288;
 //facetid->edge[3]=1289;            
 //facetid->edge[4]=1290;
 //facetid->edge[5]=1291;
 //facetid->edge[6]=1291;
 //facetid->edge[7]=1292;
 //facetid++;

 facetid->color=DARKGRAY;
 facetid->nedges=4;                             
 facetid->edge[0]=1287;                          
 facetid->edge[1]=1286;   
 facetid->edge[2]=1294; 
 facetid->edge[3]=1295;
 facetid++;

 facetid->color=DARKGRAY;
 facetid->nedges=4;                          
 facetid->edge[0]=1288;                     
 facetid->edge[1]=1287;      
 facetid->edge[2]=1295;
 facetid->edge[3]=1296;
 facetid++;

 facetid->color=DARKGRAY;
 facetid->nedges=4;                             
 facetid->edge[0]=1289;                        
 facetid->edge[1]=1288;  
 facetid->edge[2]=1296;
 facetid->edge[3]=1297;
 facetid++;

 facetid->color=DARKGRAY;
 facetid->nedges=4;                           
 facetid->edge[0]=1290;                      
 facetid->edge[1]=1289;      
 facetid->edge[2]=1297;
 facetid->edge[3]=1298;
 facetid++;

 facetid->color=DARKGRAY;
 facetid->nedges=4;                         
 facetid->edge[0]=1291;                     
 facetid->edge[1]=1290;      
 facetid->edge[2]=1298;
 facetid->edge[3]=1299;
 facetid++;

 facetid->color=DARKGRAY;
 facetid->nedges=4;                        
 facetid->edge[0]=1292;                           
 facetid->edge[1]=1291;   
 facetid->edge[2]=1299;
 facetid->edge[3]=1300;
 facetid++;

 facetid->color=DARKGRAY;
 facetid->nedges=4;                             
 facetid->edge[0]=1293;                       
 facetid->edge[1]=1292;  
 facetid->edge[2]=1300;
 facetid->edge[3]=1301;
 facetid++;

 facetid->color=DARKGRAY;
 facetid->nedges=4;                           
 facetid->edge[0]=1301;                          
 facetid->edge[1]=1294;    
 facetid->edge[2]=1286;
 facetid->edge[3]=1293;  
 facetid++;                 
 
				    //++++++ Cone XXX R 1   
 facetid->color=DARKGREEN;
 facetid->nedges=3;                             
 facetid->edge[0]=1175;                            
 facetid->edge[1]=1174;
 facetid->edge[2]=1302; 
 facetid++;

 facetid->color=DARKGREEN;
 facetid->nedges=3;                          
 facetid->edge[0]=1176;                   
 facetid->edge[1]=1175;     
 facetid->edge[2]=1302;
 facetid++;

 facetid->color=DARKGREEN;
 facetid->nedges=3;                             
 facetid->edge[0]=1177;                        
 facetid->edge[1]=1176;      
 facetid->edge[2]=1302;
 facetid++;

 facetid->color=DARKGREEN;
 facetid->nedges=3;                           
 facetid->edge[0]=1178;                           
 facetid->edge[1]=1177;      
 facetid->edge[2]=1302;
 facetid++;

 facetid->color=DARKGREEN;
 facetid->nedges=3;                         
 facetid->edge[0]=1179;                           
 facetid->edge[1]=1178;      
 facetid->edge[2]=1302;
 facetid++;

 facetid->color=DARKGREEN;
 facetid->nedges=3;                        
 facetid->edge[0]=1180;                           
 facetid->edge[1]=1179;      
 facetid->edge[2]=1302;
 facetid++;

 facetid->color=DARKGREEN;
 facetid->nedges=3;                             
 facetid->edge[0]=1181;                       
 facetid->edge[1]=1180;      
 facetid->edge[2]=1302;
 facetid++;

 facetid->color=DARKGREEN;
 facetid->nedges=3;                           
 facetid->edge[0]=1174;                           
 facetid->edge[1]=1181;      
 facetid->edge[2]=1302;
 facetid++;                 
 
				   //++++++ Cone XXX L 1    
 facetid->color=DARKGREEN;
 facetid->nedges=3;                             
 facetid->edge[0]=1191;                            
 facetid->edge[1]=1190;
 facetid->edge[2]=1303; 
 facetid++;

 facetid->color=DARKGREEN;
 facetid->nedges=3;                          
 facetid->edge[0]=1192;                   
 facetid->edge[1]=1191;     
 facetid->edge[2]=1303;
 facetid++;

 facetid->color=DARKGREEN;
 facetid->nedges=3;                             
 facetid->edge[0]=1193;                        
 facetid->edge[1]=1192;      
 facetid->edge[2]=1303;
 facetid++;

 facetid->color=DARKGREEN;
 facetid->nedges=3;                           
 facetid->edge[0]=1194;                           
 facetid->edge[1]=1193;      
 facetid->edge[2]=1303;
 facetid++;

 facetid->color=DARKGREEN;
 facetid->nedges=3;                         
 facetid->edge[0]=1195;                           
 facetid->edge[1]=1194;      
 facetid->edge[2]=1303;
 facetid++;

 facetid->color=DARKGREEN;
 facetid->nedges=3;                        
 facetid->edge[0]=1196;                           
 facetid->edge[1]=1195;      
 facetid->edge[2]=1303;
 facetid++;

 facetid->color=DARKGREEN;
 facetid->nedges=3;                             
 facetid->edge[0]=1197;                       
 facetid->edge[1]=1196;      
 facetid->edge[2]=1303;
 facetid++;

 facetid->color=DARKGREEN; 
 facetid->nedges=3;                           
 facetid->edge[0]=1190;                           
 facetid->edge[1]=1197;      
 facetid->edge[2]=1303;
 facetid++;                    //++++++ Cone XXX L 2   
 
 facetid->color=DARKGREEN;
 facetid->nedges=3;                             
 facetid->edge[0]=1206;                            
 facetid->edge[1]=1207;
 facetid->edge[2]=1304; 
 facetid++;

 facetid->color=DARKGREEN;
 facetid->nedges=3;                          
 facetid->edge[0]=1207;                   
 facetid->edge[1]=1208;     
 facetid->edge[2]=1304;
 facetid++;

 facetid->color=DARKGREEN;
 facetid->nedges=3;                             
 facetid->edge[0]=1208;                        
 facetid->edge[1]=1209;      
 facetid->edge[2]=1304;
 facetid++;

 facetid->color=DARKGREEN;
 facetid->nedges=3;                           
 facetid->edge[0]=1209;                           
 facetid->edge[1]=1210;      
 facetid->edge[2]=1304;
 facetid++;

 facetid->color=DARKGREEN;
 facetid->nedges=3;                         
 facetid->edge[0]=1210;                           
 facetid->edge[1]=1211;      
 facetid->edge[2]=1304;
 facetid++;

 facetid->color=DARKGREEN;
 facetid->nedges=3;                        
 facetid->edge[0]=1211;                           
 facetid->edge[1]=1212;      
 facetid->edge[2]=1304;
 facetid++;

 facetid->color=DARKGREEN;
 facetid->nedges=3;                             
 facetid->edge[0]=1212;                       
 facetid->edge[1]=1213;      
 facetid->edge[2]=1304;
 facetid++;

 facetid->color=DARKGREEN; 
 facetid->nedges=3;                           
 facetid->edge[0]=1213;                           
 facetid->edge[1]=1206;      
 facetid->edge[2]=1304;
 facetid++;                 
                                   //++++++ Cone XXX R 2  
 facetid->color=DARKGREEN;              
 facetid->nedges=3;                             
 facetid->edge[0]=1222;                            
 facetid->edge[1]=1223;
 facetid->edge[2]=1305; 
 facetid++;

 facetid->color=DARKGREEN;
 facetid->nedges=3;                          
 facetid->edge[0]=1223;                  
 facetid->edge[1]=1224;     
 facetid->edge[2]=1305;
 facetid++;

 facetid->color=DARKGREEN;
 facetid->nedges=3;                             
 facetid->edge[0]=1224;                        
 facetid->edge[1]=1225;      
 facetid->edge[2]=1305;
 facetid++;

 facetid->color=DARKGREEN;
 facetid->nedges=3;                           
 facetid->edge[0]=1225;                           
 facetid->edge[1]=1226;      
 facetid->edge[2]=1305;
 facetid++;

 facetid->color=DARKGREEN;
 facetid->nedges=3;                         
 facetid->edge[0]=1226;                           
 facetid->edge[1]=1227;      
 facetid->edge[2]=1305;
 facetid++;

 facetid->color=DARKGREEN;
 facetid->nedges=3;                        
 facetid->edge[0]=1227;                           
 facetid->edge[1]=1228;      
 facetid->edge[2]=1305;
 facetid++;

 facetid->color=DARKGREEN;
 facetid->nedges=3;                             
 facetid->edge[0]=1228;                       
 facetid->edge[1]=1229;      
 facetid->edge[2]=1305;
 facetid++;

 facetid->color=DARKGREEN;
 facetid->nedges=3;                           
 facetid->edge[0]=1229;                           
 facetid->edge[1]=1222;      
 facetid->edge[2]=1305;
 facetid++;                 

                              //++++++ Cone XXX 1 3 
 facetid->color=DARKGREEN;              
 facetid->nedges=3;                             
 facetid->edge[0]=1246;                            
 facetid->edge[1]=1247;
 facetid->edge[2]=1306; 
 facetid++;

 facetid->color=DARKGREEN;
 facetid->nedges=3;                          
 facetid->edge[0]=1247;                   
 facetid->edge[1]=1248;     
 facetid->edge[2]=1306;
 facetid++;

 facetid->color=DARKGREEN;
 facetid->nedges=3;                             
 facetid->edge[0]=1248;                        
 facetid->edge[1]=1249;      
 facetid->edge[2]=1306;
 facetid++;

 facetid->color=DARKGREEN;
 facetid->nedges=3;                           
 facetid->edge[0]=1249;                           
 facetid->edge[1]=1250;      
 facetid->edge[2]=1306;
 facetid++;

 facetid->color=DARKGREEN;
 facetid->nedges=3;                         
 facetid->edge[0]=1250;                           
 facetid->edge[1]=1251;      
 facetid->edge[2]=1306;
 facetid++;

 facetid->color=DARKGREEN;
 facetid->nedges=3;                        
 facetid->edge[0]=1251;                           
 facetid->edge[1]=1252;      
 facetid->edge[2]=1306;
 facetid++;

 facetid->color=DARKGREEN;
 facetid->nedges=3;                             
 facetid->edge[0]=1252;                       
 facetid->edge[1]=1253;      
 facetid->edge[2]=1306;
 facetid++;

 facetid->color=DARKGREEN;  
 facetid->nedges=3;                           
 facetid->edge[0]=1253;                           
 facetid->edge[1]=1246;      
 facetid->edge[2]=1306;
 facetid++;                 

                               //++++++ Cone XXX 2 3  
 facetid->color=DARKGREEN;
 facetid->nedges=3;                                             
 facetid->edge[0]=1262;                            
 facetid->edge[1]=1263;
 facetid->edge[2]=1307; 
 facetid++;

 facetid->color=DARKGREEN;
 facetid->nedges=3;                          
 facetid->edge[0]=1263;                   
 facetid->edge[1]=1264;     
 facetid->edge[2]=1307;
 facetid++;

 facetid->color=DARKGREEN;
 facetid->nedges=3;                             
 facetid->edge[0]=1264;                        
 facetid->edge[1]=1265;      
 facetid->edge[2]=1307;
 facetid++;

 facetid->color=DARKGREEN;
 facetid->nedges=3;                           
 facetid->edge[0]=1265;                           
 facetid->edge[1]=1266;      
 facetid->edge[2]=1307;
 facetid++;

 facetid->color=DARKGREEN;
 facetid->nedges=3;                         
 facetid->edge[0]=1266;                           
 facetid->edge[1]=1267;      
 facetid->edge[2]=1307;
 facetid++;

 facetid->color=DARKGREEN;
 facetid->nedges=3;                        
 facetid->edge[0]=1267;                           
 facetid->edge[1]=1268;      
 facetid->edge[2]=1307;
 facetid++;

 facetid->color=DARKGREEN;
 facetid->nedges=3;                             
 facetid->edge[0]=1268;                       
 facetid->edge[1]=1269;      
 facetid->edge[2]=1307;
 facetid++;

 facetid->color=DARKGREEN;  
 facetid->nedges=3;                           
 facetid->edge[0]=1269;                           
 facetid->edge[1]=1262;      
 facetid->edge[2]=1307;
 facetid++;                 

                                 //++++++ XXX Cone R 4  
 facetid->color=DARKGREEN;
 facetid->nedges=3;                             
 facetid->edge[0]=1279;                            
 facetid->edge[1]=1278;
 facetid->edge[2]=1308; 
 facetid++;

 facetid->color=DARKGREEN;
 facetid->nedges=3;                          
 facetid->edge[0]=1280;                   
 facetid->edge[1]=1279;     
 facetid->edge[2]=1308;
 facetid++;

 facetid->color=DARKGREEN;
 facetid->nedges=3;                             
 facetid->edge[0]=1281;                        
 facetid->edge[1]=1280;      
 facetid->edge[2]=1308;
 facetid++;

 facetid->color=DARKGREEN;
 facetid->nedges=3;                           
 facetid->edge[0]=1282;                           
 facetid->edge[1]=1281;      
 facetid->edge[2]=1308;
 facetid++;

 facetid->color=DARKGREEN;
 facetid->nedges=3;                         
 facetid->edge[0]=1283;                           
 facetid->edge[1]=1282;      
 facetid->edge[2]=1308;
 facetid++;

 facetid->color=DARKGREEN;
 facetid->nedges=3;                        
 facetid->edge[0]=1284;                           
 facetid->edge[1]=1283;      
 facetid->edge[2]=1308;
 facetid++;

 facetid->color=DARKGREEN;
 facetid->nedges=3;                             
 facetid->edge[0]=1285;                       
 facetid->edge[1]=1284;      
 facetid->edge[2]=1308;
 facetid++;

 facetid->color=DARKGREEN;   
 facetid->nedges=3;                           
 facetid->edge[0]=1278;                           
 facetid->edge[1]=1285;      
 facetid->edge[2]=1308;
 facetid++;                  

                                 //++++++ XXX Cone L 4  
 facetid->color=DARKGREEN;
 facetid->nedges=3;                             
 facetid->edge[0]=1295;                            
 facetid->edge[1]=1294;
 facetid->edge[2]=1309; 
 facetid++;

 facetid->color=DARKGREEN;
 facetid->nedges=3;                          
 facetid->edge[0]=1296;                   
 facetid->edge[1]=1295;     
 facetid->edge[2]=1309;
 facetid++;

 facetid->color=DARKGREEN;
 facetid->nedges=3;                             
 facetid->edge[0]=1297;                        
 facetid->edge[1]=1296;      
 facetid->edge[2]=1309;
 facetid++;

 facetid->color=DARKGREEN;
 facetid->nedges=3;                           
 facetid->edge[0]=1298;                           
 facetid->edge[1]=1297;      
 facetid->edge[2]=1309;
 facetid++;

 facetid->color=DARKGREEN;
 facetid->nedges=3;                         
 facetid->edge[0]=1299;                           
 facetid->edge[1]=1298;      
 facetid->edge[2]=1309;
 facetid++;

 facetid->color=DARKGREEN;
 facetid->nedges=3;                        
 facetid->edge[0]=1300;                           
 facetid->edge[1]=1299;      
 facetid->edge[2]=1309;
 facetid++;

 facetid->color=DARKGREEN;
 facetid->nedges=3;                             
 facetid->edge[0]=1301;                       
 facetid->edge[1]=1300;      
 facetid->edge[2]=1309;
 facetid++;

 facetid->color=DARKGREEN;
 facetid->nedges=3;                           
 facetid->edge[0]=1294;                           
 facetid->edge[1]=1301;      
 facetid->edge[2]=1309;
 facetid++;                  
				   //++++++ Cone XXX R 1  
 facetid->color=DARKGREEN;
 facetid->nedges=3;                             
 facetid->edge[0]=1182;                            
 facetid->edge[1]=1183;
 facetid->edge[2]=1310; 
 facetid++;

 facetid->color=DARKGREEN;
 facetid->nedges=3;                          
 facetid->edge[0]=1183;                   
 facetid->edge[1]=1184;     
 facetid->edge[2]=1310;
 facetid++;

 facetid->color=DARKGREEN;
 facetid->nedges=3;                             
 facetid->edge[0]=1184;                        
 facetid->edge[1]=1185;      
 facetid->edge[2]=1310;
 facetid++;

 facetid->color=DARKGREEN;
 facetid->nedges=3;                           
 facetid->edge[0]=1185;                           
 facetid->edge[1]=1186;      
 facetid->edge[2]=1310;
 facetid++;

 facetid->color=DARKGREEN;
 facetid->nedges=3;                         
 facetid->edge[0]=1186;                           
 facetid->edge[1]=1187;      
 facetid->edge[2]=1310;
 facetid++;

 facetid->color=DARKGREEN;
 facetid->nedges=3;                        
 facetid->edge[0]=1187;                           
 facetid->edge[1]=1188;      
 facetid->edge[2]=1310;
 facetid++;

 facetid->color=DARKGREEN;
 facetid->nedges=3;                             
 facetid->edge[0]=1188;                       
 facetid->edge[1]=1189;      
 facetid->edge[2]=1310;
 facetid++;

 facetid->color=DARKGREEN;
 facetid->nedges=3;                           
 facetid->edge[0]=1189;                           
 facetid->edge[1]=1182;      
 facetid->edge[2]=1310;
 facetid++;                 
 
				   //++++++ Cone XXX L 1    
 facetid->color=DARKGREEN;
 facetid->nedges=3;                             
 facetid->edge[0]=1198;                            
 facetid->edge[1]=1199;
 facetid->edge[2]=1311; 
 facetid++;

 facetid->color=DARKGREEN;
 facetid->nedges=3;                          
 facetid->edge[0]=1199;                   
 facetid->edge[1]=1200;     
 facetid->edge[2]=1311;
 facetid++;

 facetid->color=DARKGREEN;
 facetid->nedges=3;                             
 facetid->edge[0]=1200;                        
 facetid->edge[1]=1201;      
 facetid->edge[2]=1311;
 facetid++;

 facetid->color=DARKGREEN;
 facetid->nedges=3;                           
 facetid->edge[0]=1201;                           
 facetid->edge[1]=1202;      
 facetid->edge[2]=1311;
 facetid++;

 facetid->color=DARKGREEN;
 facetid->nedges=3;                         
 facetid->edge[0]=1202;                           
 facetid->edge[1]=1203;      
 facetid->edge[2]=1311;
 facetid++;

 facetid->color=DARKGREEN;
 facetid->nedges=3;                        
 facetid->edge[0]=1203;                           
 facetid->edge[1]=1204;      
 facetid->edge[2]=1311;
 facetid++;

 facetid->color=DARKGREEN;
 facetid->nedges=3;                             
 facetid->edge[0]=1204;                       
 facetid->edge[1]=1205;      
 facetid->edge[2]=1311;
 facetid++;

 facetid->color=DARKGREEN; 
 facetid->nedges=3;                           
 facetid->edge[0]=1205;                           
 facetid->edge[1]=1198;      
 facetid->edge[2]=1311;
 facetid++;                 

   				//+++++ Cone XXX L 2   
 facetid->color=DARKGREEN;
 facetid->nedges=3;                             
 facetid->edge[0]=1215;                            
 facetid->edge[1]=1214;
 facetid->edge[2]=1312; 
 facetid++;

 facetid->color=DARKGREEN;
 facetid->nedges=3;                          
 facetid->edge[0]=1216;                   
 facetid->edge[1]=1215;     
 facetid->edge[2]=1312;
 facetid++;

 facetid->color=DARKGREEN;
 facetid->nedges=3;                             
 facetid->edge[0]=1217;                        
 facetid->edge[1]=1216;      
 facetid->edge[2]=1312;
 facetid++;

 facetid->color=DARKGREEN;
 facetid->nedges=3;                           
 facetid->edge[0]=1218;                           
 facetid->edge[1]=1217;      
 facetid->edge[2]=1312;
 facetid++;

 facetid->color=DARKGREEN;
 facetid->nedges=3;                         
 facetid->edge[0]=1219;                           
 facetid->edge[1]=1218;      
 facetid->edge[2]=1312;
 facetid++;

 facetid->color=DARKGREEN;
 facetid->nedges=3;                        
 facetid->edge[0]=1220;                           
 facetid->edge[1]=1219;      
 facetid->edge[2]=1312;
 facetid++;

 facetid->color=DARKGREEN;
 facetid->nedges=3;                             
 facetid->edge[0]=1221;                       
 facetid->edge[1]=1220;      
 facetid->edge[2]=1312;
 facetid++;

 facetid->color=DARKGREEN; 
 facetid->nedges=3;                           
 facetid->edge[0]=1214;                           
 facetid->edge[1]=1221;      
 facetid->edge[2]=1312;
 facetid++;                 

                              //++++++ Cone XXX R 2  
 facetid->color=DARKGREEN;              
 facetid->nedges=3;                             
 facetid->edge[0]=1231;                            
 facetid->edge[1]=1230;
 facetid->edge[2]=1313; 
 facetid++;

 facetid->color=DARKGREEN;
 facetid->nedges=3;                          
 facetid->edge[0]=1232;                  
 facetid->edge[1]=1231;     
 facetid->edge[2]=1313;
 facetid++;

 facetid->color=DARKGREEN;
 facetid->nedges=3;                             
 facetid->edge[0]=1233;                        
 facetid->edge[1]=1232;      
 facetid->edge[2]=1313;
 facetid++;

 facetid->color=DARKGREEN;
 facetid->nedges=3;                           
 facetid->edge[0]=1234;                           
 facetid->edge[1]=1233;      
 facetid->edge[2]=1313;
 facetid++;

 facetid->color=DARKGREEN;
 facetid->nedges=3;                         
 facetid->edge[0]=1235;                           
 facetid->edge[1]=1234;      
 facetid->edge[2]=1313;
 facetid++;

 facetid->color=DARKGREEN;
 facetid->nedges=3;                        
 facetid->edge[0]=1236;                           
 facetid->edge[1]=1235;      
 facetid->edge[2]=1313;
 facetid++;

 facetid->color=DARKGREEN;
 facetid->nedges=3;                             
 facetid->edge[0]=1237;                       
 facetid->edge[1]=1236;      
 facetid->edge[2]=1313;
 facetid++;

 facetid->color=DARKGREEN;
 facetid->nedges=3;                           
 facetid->edge[0]=1230;                           
 facetid->edge[1]=1237;      
 facetid->edge[2]=1313;
 facetid++;                 

                              //++++++ Cone XXX 1 3 
 facetid->color=DARKGREEN;              
 facetid->nedges=3;                             
 facetid->edge[0]=1239;                            
 facetid->edge[1]=1238;
 facetid->edge[2]=1314; 
 facetid++;

 facetid->color=DARKGREEN;
 facetid->nedges=3;                          
 facetid->edge[0]=1240;                   
 facetid->edge[1]=1239;     
 facetid->edge[2]=1314;
 facetid++;

 facetid->color=DARKGREEN;
 facetid->nedges=3;                             
 facetid->edge[0]=1241;                        
 facetid->edge[1]=1240;      
 facetid->edge[2]=1314;
 facetid++;

 facetid->color=DARKGREEN;
 facetid->nedges=3;                           
 facetid->edge[0]=1242;                           
 facetid->edge[1]=1241;      
 facetid->edge[2]=1314;
 facetid++;

 facetid->color=DARKGREEN;
 facetid->nedges=3;                         
 facetid->edge[0]=1243;                           
 facetid->edge[1]=1242;      
 facetid->edge[2]=1314;
 facetid++;

 facetid->color=DARKGREEN;
 facetid->nedges=3;                        
 facetid->edge[0]=1244;                           
 facetid->edge[1]=1243;      
 facetid->edge[2]=1314;
 facetid++;

 facetid->color=DARKGREEN;
 facetid->nedges=3;                             
 facetid->edge[0]=1245;                       
 facetid->edge[1]=1244;      
 facetid->edge[2]=1314;
 facetid++;

 facetid->color=DARKGREEN;  
 facetid->nedges=3;                           
 facetid->edge[0]=1238;                           
 facetid->edge[1]=1245;      
 facetid->edge[2]=1314;
 facetid++;                 

                               //++++++ Cone XXX 2 3  
 facetid->color=DARKGREEN;
 facetid->nedges=3;                                             
 facetid->edge[0]=1255;                            
 facetid->edge[1]=1254;
 facetid->edge[2]=1315; 
 facetid++;

 facetid->color=DARKGREEN;
 facetid->nedges=3;                          
 facetid->edge[0]=1256;                   
 facetid->edge[1]=1255;     
 facetid->edge[2]=1315;
 facetid++;

 facetid->color=DARKGREEN;
 facetid->nedges=3;                             
 facetid->edge[0]=1257;                        
 facetid->edge[1]=1256;      
 facetid->edge[2]=1315;
 facetid++;

 facetid->color=DARKGREEN;
 facetid->nedges=3;                           
 facetid->edge[0]=1258;                           
 facetid->edge[1]=1257;      
 facetid->edge[2]=1315;
 facetid++;

 facetid->color=DARKGREEN;
 facetid->nedges=3;                         
 facetid->edge[0]=1259;                           
 facetid->edge[1]=1258;      
 facetid->edge[2]=1315;
 facetid++;

 facetid->color=DARKGREEN;
 facetid->nedges=3;                        
 facetid->edge[0]=1260;                           
 facetid->edge[1]=1259;      
 facetid->edge[2]=1315;
 facetid++;

 facetid->color=DARKGREEN;
 facetid->nedges=3;                             
 facetid->edge[0]=1261;                       
 facetid->edge[1]=1260;      
 facetid->edge[2]=1315;
 facetid++;

 facetid->color=DARKGREEN;  
 facetid->nedges=3;                           
 facetid->edge[0]=1254;                           
 facetid->edge[1]=1261;      
 facetid->edge[2]=1315;
 facetid++;                 

                                 //++++++ XXX Cone R 4  
 facetid->color=DARKGREEN;
 facetid->nedges=3;                             
 facetid->edge[0]=1270;                            
 facetid->edge[1]=1271;
 facetid->edge[2]=1316; 
 facetid++;

 facetid->color=DARKGREEN;
 facetid->nedges=3;                          
 facetid->edge[0]=1271;                   
 facetid->edge[1]=1272;     
 facetid->edge[2]=1316;
 facetid++;

 facetid->color=DARKGREEN;
 facetid->nedges=3;                             
 facetid->edge[0]=1272;                        
 facetid->edge[1]=1273;      
 facetid->edge[2]=1316;
 facetid++;

 facetid->color=DARKGREEN;
 facetid->nedges=3;                           
 facetid->edge[0]=1273;                           
 facetid->edge[1]=1274;      
 facetid->edge[2]=1316;
 facetid++;

 facetid->color=DARKGREEN;
 facetid->nedges=3;                         
 facetid->edge[0]=1274;                           
 facetid->edge[1]=1275;      
 facetid->edge[2]=1316;
 facetid++;

 facetid->color=DARKGREEN;
 facetid->nedges=3;                        
 facetid->edge[0]=1275;                           
 facetid->edge[1]=1276;      
 facetid->edge[2]=1316;
 facetid++;

 facetid->color=DARKGREEN;
 facetid->nedges=3;                             
 facetid->edge[0]=1276;                       
 facetid->edge[1]=1277;      
 facetid->edge[2]=1316;
 facetid++;

 facetid->color=DARKGREEN;   
 facetid->nedges=3;                           
 facetid->edge[0]=1277;                           
 facetid->edge[1]=1270;      
 facetid->edge[2]=1316;
 facetid++;                  

                                 //++++++ XXX Cone L 4  
 facetid->color=DARKGREEN;
 facetid->nedges=3;                             
 facetid->edge[0]=1286;                            
 facetid->edge[1]=1287;
 facetid->edge[2]=1316; 
 facetid++;

 facetid->color=DARKGREEN;
 facetid->nedges=3;                          
 facetid->edge[0]=1287;                   
 facetid->edge[1]=1288;     
 facetid->edge[2]=1316;
 facetid++;

 facetid->color=DARKGREEN;
 facetid->nedges=3;                             
 facetid->edge[0]=1288;                        
 facetid->edge[1]=1289;      
 facetid->edge[2]=1316;
 facetid++;

 facetid->color=DARKGREEN;
 facetid->nedges=3;                           
 facetid->edge[0]=1289;                           
 facetid->edge[1]=1290;      
 facetid->edge[2]=1316;
 facetid++;

 facetid->color=DARKGREEN;
 facetid->nedges=3;                         
 facetid->edge[0]=1290;                           
 facetid->edge[1]=1291;      
 facetid->edge[2]=1316;
 facetid++;

 facetid->color=DARKGREEN;
 facetid->nedges=3;                        
 facetid->edge[0]=1291;                           
 facetid->edge[1]=1292;      
 facetid->edge[2]=1316;
 facetid++;

 facetid->color=DARKGREEN;
 facetid->nedges=3;                             
 facetid->edge[0]=1292;                       
 facetid->edge[1]=1293;      
 facetid->edge[2]=1316;
 facetid++;

 facetid->color=DARKGREEN;
 facetid->nedges=3;                           
 facetid->edge[0]=1293;                           
 facetid->edge[1]=1286;      
 facetid->edge[2]=1316;
 facetid++;                  

 //facetid->color=WHITE;        //++++++ Ladder 1 
 //facetid->nedges=8;            
 //facetid->edge[0]=1318;
 //facetid->edge[1]=1319;
 //facetid->edge[2]=1320;
 //facetid->edge[3]=1321;            
 //facetid->edge[4]=1322;
 //facetid->edge[5]=1323;
 //facetid->edge[6]=1324;
 //facetid->edge[7]=1325;
 //facetid++;

 facetid->color=WHITE;
 facetid->nedges=4;                             
 facetid->edge[0]=1318;                       
 facetid->edge[1]=1319;        
 facetid->edge[2]=1327; 
 facetid->edge[3]=1326;
 facetid++;

 facetid->color=WHITE;
 facetid->nedges=4;                          
 facetid->edge[0]=1319;                           
 facetid->edge[1]=1320;      
 facetid->edge[2]=1328;
 facetid->edge[3]=1327;
 facetid++;

 facetid->color=WHITE;
 facetid->nedges=4;                             
 facetid->edge[0]=1320;                      
 facetid->edge[1]=1321;      
 facetid->edge[2]=1329;
 facetid->edge[3]=1328;
 facetid++;

 facetid->color=WHITE;
 facetid->nedges=4;                     
 facetid->edge[0]=1321;                           
 facetid->edge[1]=1322;      
 facetid->edge[2]=1330;
 facetid->edge[3]=1329;
 facetid++;

 facetid->color=WHITE;
 facetid->nedges=4;                        
 facetid->edge[0]=1322;                         
 facetid->edge[1]=1323;     
 facetid->edge[2]=1331;
 facetid->edge[3]=1330;
 facetid++;

 facetid->color=WHITE;
 facetid->nedges=4;                       
 facetid->edge[0]=1323;                           
 facetid->edge[1]=1324;      
 facetid->edge[2]=1332;
 facetid->edge[3]=1331;
 facetid++;

 facetid->color=WHITE;
 facetid->nedges=4;                             
 facetid->edge[0]=1324;                   
 facetid->edge[1]=1325;      
 facetid->edge[2]=1333;
 facetid->edge[3]=1332;
 facetid++;

 facetid->color=WHITE; 
 facetid->nedges=4;                          
 facetid->edge[0]=1325;                           
 facetid->edge[1]=1318;         
 facetid->edge[2]=1326;
 facetid->edge[3]=1333;
 facetid++;                    
  
 //facetid->color=WHITE;        //++++++ Ladder 2 1
 //facetid->nedges=8;            
 //facetid->edge[0]=1334;
 //facetid->edge[1]=1335;
 //facetid->edge[2]=1336;
 //facetid->edge[3]=1337;            
 //facetid->edge[4]=1338;
 //facetid->edge[5]=1339;
 //facetid->edge[6]=1340;
 //facetid->edge[7]=1341;
 //facetid++;

 facetid->color=WHITE;
 facetid->nedges=4;                             
 facetid->edge[0]=1342;                       
 facetid->edge[1]=1343;        
 facetid->edge[2]=1335; 
 facetid->edge[3]=1334;
 facetid++;

 facetid->color=WHITE;
 facetid->nedges=4;                          
 facetid->edge[0]=1343;                           
 facetid->edge[1]=1344;      
 facetid->edge[2]=1336;
 facetid->edge[3]=1335;
 facetid++;

 facetid->color=WHITE;
 facetid->nedges=4;                             
 facetid->edge[0]=1344;                      
 facetid->edge[1]=1345;      
 facetid->edge[2]=1337;
 facetid->edge[3]=1336;
 facetid++;

 facetid->color=WHITE;
 facetid->nedges=4;                     
 facetid->edge[0]=1345;                           
 facetid->edge[1]=1346;      
 facetid->edge[2]=1338;
 facetid->edge[3]=1337;
 facetid++;

 facetid->color=WHITE;
 facetid->nedges=4;                        
 facetid->edge[0]=1346;                         
 facetid->edge[1]=1347;     
 facetid->edge[2]=1339;
 facetid->edge[3]=1338;
 facetid++;

 facetid->color=WHITE;
 facetid->nedges=4;                       
 facetid->edge[0]=1347;                           
 facetid->edge[1]=1348;      
 facetid->edge[2]=1340;
 facetid->edge[3]=1339;
 facetid++;

 facetid->color=WHITE;
 facetid->nedges=4;                             
 facetid->edge[0]=1348;                   
 facetid->edge[1]=1349;      
 facetid->edge[2]=1341;
 facetid->edge[3]=1340;
 facetid++;

 facetid->color=WHITE; 
 facetid->nedges=4;                          
 facetid->edge[0]=1349;                           
 facetid->edge[1]=1342;         
 facetid->edge[2]=1334;
 facetid->edge[3]=1341;
 facetid++;                    

 //facetid->color=WHITE;        //++++++ Ladder 2 2 
 //facetid->nedges=8;            
 //facetid->edge[0]=1350;
 //facetid->edge[1]=1351;
 //facetid->edge[2]=1352;
 //facetid->edge[3]=1353;            
 //facetid->edge[4]=1354;
 //facetid->edge[5]=1355;
 //facetid->edge[6]=1356;
 //facetid->edge[7]=1357;
 //facetid++;

 facetid->color=WHITE;
 facetid->nedges=4;                             
 facetid->edge[0]=1350;                       
 facetid->edge[1]=1351;        
 facetid->edge[2]=1359; 
 facetid->edge[3]=1358;
 facetid++;

 facetid->color=WHITE;
 facetid->nedges=4;                          
 facetid->edge[0]=1351;                           
 facetid->edge[1]=1352;      
 facetid->edge[2]=1360;
 facetid->edge[3]=1359;
 facetid++;

 facetid->color=WHITE;
 facetid->nedges=4;                             
 facetid->edge[0]=1352;                      
 facetid->edge[1]=1353;      
 facetid->edge[2]=1361;
 facetid->edge[3]=1360;
 facetid++;

 facetid->color=WHITE;
 facetid->nedges=4;                     
 facetid->edge[0]=1353;                           
 facetid->edge[1]=1354;      
 facetid->edge[2]=1362;
 facetid->edge[3]=1361;
 facetid++;

 facetid->color=WHITE;
 facetid->nedges=4;                        
 facetid->edge[0]=1354;                         
 facetid->edge[1]=1355;     
 facetid->edge[2]=1363;
 facetid->edge[3]=1362;
 facetid++;

 facetid->color=WHITE;
 facetid->nedges=4;                       
 facetid->edge[0]=1355;                           
 facetid->edge[1]=1356;      
 facetid->edge[2]=1364;
 facetid->edge[3]=1363;
 facetid++;

 facetid->color=WHITE;
 facetid->nedges=4;                             
 facetid->edge[0]=1356;                   
 facetid->edge[1]=1357;      
 facetid->edge[2]=1365;
 facetid->edge[3]=1364;
 facetid++;

 facetid->color=WHITE; 
 facetid->nedges=4;                          
 facetid->edge[0]=1357;                           
 facetid->edge[1]=1350;         
 facetid->edge[2]=1358;
 facetid->edge[3]=1365;
 facetid++;                    

 //facetid->color=WHITE;        //++++++ Ladder 3 1
 //facetid->nedges=8;            
 //facetid->edge[0]=1366;
 //facetid->edge[1]=1367;
 //facetid->edge[2]=1368;
 //facetid->edge[3]=1369;            
 //facetid->edge[4]=1370;
 //facetid->edge[5]=1371;
 //facetid->edge[6]=1372;
 //facetid->edge[7]=1373;
 //facetid++;

 facetid->color=WHITE;
 facetid->nedges=4;                             
 facetid->edge[0]=1366;                       
 facetid->edge[1]=1367;        
 facetid->edge[2]=1375; 
 facetid->edge[3]=1374;
 facetid++;

 facetid->color=WHITE;
 facetid->nedges=4;                          
 facetid->edge[0]=1367;                           
 facetid->edge[1]=1368;      
 facetid->edge[2]=1376;
 facetid->edge[3]=1375;
 facetid++;

 facetid->color=WHITE;
 facetid->nedges=4;                             
 facetid->edge[0]=1368;                      
 facetid->edge[1]=1369;      
 facetid->edge[2]=1377;
 facetid->edge[3]=1376;
 facetid++;

 facetid->color=WHITE;
 facetid->nedges=4;                     
 facetid->edge[0]=1369;                           
 facetid->edge[1]=1370;      
 facetid->edge[2]=1378;
 facetid->edge[3]=1377;
 facetid++;

 facetid->color=WHITE;
 facetid->nedges=4;                        
 facetid->edge[0]=1370;                         
 facetid->edge[1]=1371;     
 facetid->edge[2]=1379;
 facetid->edge[3]=1378;
 facetid++;

 facetid->color=WHITE;
 facetid->nedges=4;                       
 facetid->edge[0]=1371;                           
 facetid->edge[1]=1372;      
 facetid->edge[2]=1380;
 facetid->edge[3]=1379;
 facetid++;

 facetid->color=WHITE;
 facetid->nedges=4;                             
 facetid->edge[0]=1372;                   
 facetid->edge[1]=1373;      
 facetid->edge[2]=1381;
 facetid->edge[3]=1380;
 facetid++;

 facetid->color=WHITE; 
 facetid->nedges=4;                          
 facetid->edge[0]=1373;                           
 facetid->edge[1]=1366;         
 facetid->edge[2]=1374;
 facetid->edge[3]=1381;
 facetid++;                    

  //facetid->color=WHITE;        //++++++ Ladder 3 2 
 //facetid->nedges=8;            
 //facetid->edge[0]=1382;
 //facetid->edge[1]=1383;
 //facetid->edge[2]=1384;
 //facetid->edge[3]=1385;            
 //facetid->edge[4]=1386;
 //facetid->edge[5]=1387;
 //facetid->edge[6]=1388;
 //facetid->edge[7]=1389;
 //facetid++;

 facetid->color=WHITE;
 facetid->nedges=4;                             
 facetid->edge[0]=1390;                       
 facetid->edge[1]=1391;        
 facetid->edge[2]=1383; 
 facetid->edge[3]=1382;
 facetid++;

 facetid->color=WHITE;
 facetid->nedges=4;                          
 facetid->edge[0]=1391;                           
 facetid->edge[1]=1392;      
 facetid->edge[2]=1384;
 facetid->edge[3]=1383;
 facetid++;

 facetid->color=WHITE;
 facetid->nedges=4;                             
 facetid->edge[0]=1392;                      
 facetid->edge[1]=1393;      
 facetid->edge[2]=1385;
 facetid->edge[3]=1384;
 facetid++;

 facetid->color=WHITE;
 facetid->nedges=4;                     
 facetid->edge[0]=1393;                           
 facetid->edge[1]=1394;      
 facetid->edge[2]=1386;
 facetid->edge[3]=1385;
 facetid++;

 facetid->color=WHITE;
 facetid->nedges=4;                        
 facetid->edge[0]=1394;                         
 facetid->edge[1]=1395;     
 facetid->edge[2]=1387;
 facetid->edge[3]=1386;
 facetid++;

 facetid->color=WHITE;
 facetid->nedges=4;                       
 facetid->edge[0]=1395;                           
 facetid->edge[1]=1396;      
 facetid->edge[2]=1388;
 facetid->edge[3]=1387;
 facetid++;

 facetid->color=WHITE;
 facetid->nedges=4;                             
 facetid->edge[0]=1396;                   
 facetid->edge[1]=1397;      
 facetid->edge[2]=1389;
 facetid->edge[3]=1388;
 facetid++;

 facetid->color=WHITE; 
 facetid->nedges=4;                          
 facetid->edge[0]=1397;                           
 facetid->edge[1]=1390;         
 facetid->edge[2]=1382;
 facetid->edge[3]=1389;
 facetid++;                    
 
 
//facetid->color=WHITE;        //++++++ Ladder 4 
 //facetid->nedges=8;            
 //facetid->edge[0]=1398;
 //facetid->edge[1]=1399;
 //facetid->edge[2]=1400;
 //facetid->edge[3]=1401;            
 //facetid->edge[4]=1402;
 //facetid->edge[5]=1403;
 //facetid->edge[6]=1404;
 //facetid->edge[7]=1405;
 //facetid++;

 facetid->color=WHITE;
 facetid->nedges=4;                             
 facetid->edge[0]=1398;                       
 facetid->edge[1]=1399;        
 facetid->edge[2]=1407; 
 facetid->edge[3]=1406;
 facetid++;

 facetid->color=WHITE;
 facetid->nedges=4;                          
 facetid->edge[0]=1399;                           
 facetid->edge[1]=1400;      
 facetid->edge[2]=1408;
 facetid->edge[3]=1407;
 facetid++;

 facetid->color=WHITE;
 facetid->nedges=4;                             
 facetid->edge[0]=1400;                      
 facetid->edge[1]=1401;      
 facetid->edge[2]=1409;
 facetid->edge[3]=1408;
 facetid++;

 facetid->color=WHITE;
 facetid->nedges=4;                     
 facetid->edge[0]=1401;                           
 facetid->edge[1]=1402;      
 facetid->edge[2]=1410;
 facetid->edge[3]=1409;
 facetid++;

 facetid->color=WHITE;
 facetid->nedges=4;                        
 facetid->edge[0]=1402;                         
 facetid->edge[1]=1403;     
 facetid->edge[2]=1411;
 facetid->edge[3]=1410;
 facetid++;

 facetid->color=WHITE;
 facetid->nedges=4;                       
 facetid->edge[0]=1403;                           
 facetid->edge[1]=1404;      
 facetid->edge[2]=1412;
 facetid->edge[3]=1411;
 facetid++;

 facetid->color=WHITE;
 facetid->nedges=4;                             
 facetid->edge[0]=1404;                   
 facetid->edge[1]=1405;      
 facetid->edge[2]=1413;
 facetid->edge[3]=1412;
 facetid++;

 facetid->color=WHITE;
 facetid->nedges=4;                          
 facetid->edge[0]=1405;                           
 facetid->edge[1]=1398;         
 facetid->edge[2]=1406;
 facetid->edge[3]=1413;
 facetid++;                    

 //facetid->color=WHITE;        //++++++ Ladder 5
 //facetid->nedges=8;            
 //facetid->edge[0]=1414;
 //facetid->edge[1]=1415;
 //facetid->edge[2]=1416;
 //facetid->edge[3]=1417;            
 //facetid->edge[4]=1418;
 //facetid->edge[5]=1419;
 //facetid->edge[6]=1420;
 //facetid->edge[7]=1421;
 //facetid++;

 facetid->color=WHITE;
 facetid->nedges=4;                             
 facetid->edge[0]=1414;                       
 facetid->edge[1]=1415;        
 facetid->edge[2]=1423; 
 facetid->edge[3]=1422;
 facetid++;

 facetid->color=WHITE;
 facetid->nedges=4;                          
 facetid->edge[0]=1415;                           
 facetid->edge[1]=1416;      
 facetid->edge[2]=1424;
 facetid->edge[3]=1423;
 facetid++;

 facetid->color=WHITE;
 facetid->nedges=4;                             
 facetid->edge[0]=1416;                      
 facetid->edge[1]=1417;      
 facetid->edge[2]=1425;
 facetid->edge[3]=1424;
 facetid++;

 facetid->color=WHITE;
 facetid->nedges=4;                     
 facetid->edge[0]=1417;                           
 facetid->edge[1]=1418;      
 facetid->edge[2]=1426;
 facetid->edge[3]=1425;
 facetid++;

 facetid->color=WHITE;
 facetid->nedges=4;                        
 facetid->edge[0]=1418;                         
 facetid->edge[1]=1419;     
 facetid->edge[2]=1427;
 facetid->edge[3]=1426;
 facetid++;

 facetid->color=WHITE;
 facetid->nedges=4;                       
 facetid->edge[0]=1419;                           
 facetid->edge[1]=1420;      
 facetid->edge[2]=1428;
 facetid->edge[3]=1427;
 facetid++;

 facetid->color=WHITE;
 facetid->nedges=4;                             
 facetid->edge[0]=1420;                   
 facetid->edge[1]=1421;      
 facetid->edge[2]=1429;
 facetid->edge[3]=1428;
 facetid++;

 facetid->color=WHITE; 
 facetid->nedges=4;                          
 facetid->edge[0]=1421;                           
 facetid->edge[1]=1414;         
 facetid->edge[2]=1422;
 facetid->edge[3]=1429;
 facetid++;                    

 //facetid->color=WHITE;        //++++++ Ladder 6
 //facetid->nedges=8;            
 //facetid->edge[0]=1430;
 //facetid->edge[1]=1431;
 //facetid->edge[2]=1432;
 //facetid->edge[3]=1433;            
 //facetid->edge[4]=1434;
 //facetid->edge[5]=1435;
 //facetid->edge[6]=1436;
 //facetid->edge[7]=1437;
 //facetid++;

 facetid->color=WHITE;
 facetid->nedges=4;                             
 facetid->edge[0]=1430;                       
 facetid->edge[1]=1431;        
 facetid->edge[2]=1439; 
 facetid->edge[3]=1438;
 facetid++;

 facetid->color=WHITE;
 facetid->nedges=4;                          
 facetid->edge[0]=1431;                           
 facetid->edge[1]=1432;      
 facetid->edge[2]=1440;
 facetid->edge[3]=1439;
 facetid++;

 facetid->color=WHITE;
 facetid->nedges=4;                             
 facetid->edge[0]=1432;                      
 facetid->edge[1]=1433;      
 facetid->edge[2]=1441;
 facetid->edge[3]=1440;
 facetid++;

 facetid->color=WHITE;
 facetid->nedges=4;                     
 facetid->edge[0]=1433;                           
 facetid->edge[1]=1434;      
 facetid->edge[2]=1442;
 facetid->edge[3]=1441;
 facetid++;

 facetid->color=WHITE;
 facetid->nedges=4;                        
 facetid->edge[0]=1434;                         
 facetid->edge[1]=1435;     
 facetid->edge[2]=1443;
 facetid->edge[3]=1442;
 facetid++;

 facetid->color=WHITE;
 facetid->nedges=4;                       
 facetid->edge[0]=1435;                           
 facetid->edge[1]=1436;      
 facetid->edge[2]=1444;
 facetid->edge[3]=1443;
 facetid++;

 facetid->color=WHITE;
 facetid->nedges=4;                             
 facetid->edge[0]=1436;                   
 facetid->edge[1]=1437;      
 facetid->edge[2]=1445;
 facetid->edge[3]=1444;
 facetid++;

 facetid->color=WHITE; 
 facetid->nedges=4;                          
 facetid->edge[0]=1437;                           
 facetid->edge[1]=1430;         
 facetid->edge[2]=1438;
 facetid->edge[3]=1445;
 facetid++;                    

 //facetid->color=WHITE;        //++++++ Ladder 7
 //facetid->nedges=8;            
 //facetid->edge[0]=1446;
 //facetid->edge[1]=1447;
 //facetid->edge[2]=1448;
 //facetid->edge[3]=1449;            
 //facetid->edge[4]=1450;
 //facetid->edge[5]=1451;
 //facetid->edge[6]=1452;
 //facetid->edge[7]=1453;
 //facetid++;

 facetid->color=WHITE;
 facetid->nedges=4;                             
 facetid->edge[0]=1446;                       
 facetid->edge[1]=1447;        
 facetid->edge[2]=1455; 
 facetid->edge[3]=1454;
 facetid++;

 facetid->color=WHITE;
 facetid->nedges=4;                          
 facetid->edge[0]=1447;                           
 facetid->edge[1]=1448;      
 facetid->edge[2]=1456;
 facetid->edge[3]=1455;
 facetid++;

 facetid->color=WHITE;
 facetid->nedges=4;                             
 facetid->edge[0]=1448;                      
 facetid->edge[1]=1449;      
 facetid->edge[2]=1457;
 facetid->edge[3]=1456;
 facetid++;

 facetid->color=WHITE;
 facetid->nedges=4;                     
 facetid->edge[0]=1449;                           
 facetid->edge[1]=1450;      
 facetid->edge[2]=1458;
 facetid->edge[3]=1457;
 facetid++;

 facetid->color=WHITE;
 facetid->nedges=4;                        
 facetid->edge[0]=1450;                         
 facetid->edge[1]=1451;     
 facetid->edge[2]=1459;
 facetid->edge[3]=1458;
 facetid++;

 facetid->color=WHITE;
 facetid->nedges=4;                       
 facetid->edge[0]=1451;                           
 facetid->edge[1]=1452;      
 facetid->edge[2]=1460;
 facetid->edge[3]=1459;
 facetid++;

 facetid->color=WHITE;
 facetid->nedges=4;                             
 facetid->edge[0]=1452;                   
 facetid->edge[1]=1453;      
 facetid->edge[2]=1461;
 facetid->edge[3]=1460;
 facetid++;

 facetid->color=WHITE;
 facetid->nedges=4;                          
 facetid->edge[0]=1453;                           
 facetid->edge[1]=1446;         
 facetid->edge[2]=1454;
 facetid->edge[3]=1461;
 facetid++;               
 
 //facetid->color=WHITE;        //++++++ Ladder 8
 //facetid->nedges=8;            
 //facetid->edge[0]=1462;
 //facetid->edge[1]=1463;
 //facetid->edge[2]=1464;
 //facetid->edge[3]=1465;            
 //facetid->edge[4]=1466;
 //facetid->edge[5]=1467;
 //facetid->edge[6]=1468;
 //facetid->edge[7]=1469;
 //facetid++;

 facetid->color=WHITE;
 facetid->nedges=4;                             
 facetid->edge[0]=1462;                       
 facetid->edge[1]=1463;        
 facetid->edge[2]=1471; 
 facetid->edge[3]=1470;
 facetid++;

 facetid->color=WHITE;
 facetid->nedges=4;                          
 facetid->edge[0]=1463;                           
 facetid->edge[1]=1464;      
 facetid->edge[2]=1472;
 facetid->edge[3]=1471;
 facetid++;

 facetid->color=WHITE;
 facetid->nedges=4;                             
 facetid->edge[0]=1464;                      
 facetid->edge[1]=1465;      
 facetid->edge[2]=1473;
 facetid->edge[3]=1472;
 facetid++;

 facetid->color=WHITE;
 facetid->nedges=4;                     
 facetid->edge[0]=1465;                           
 facetid->edge[1]=1466;      
 facetid->edge[2]=1474;
 facetid->edge[3]=1473;
 facetid++;

 facetid->color=WHITE;
 facetid->nedges=4;                        
 facetid->edge[0]=1466;                         
 facetid->edge[1]=1467;     
 facetid->edge[2]=1475;
 facetid->edge[3]=1474;
 facetid++;

 facetid->color=WHITE;
 facetid->nedges=4;                       
 facetid->edge[0]=1467;                           
 facetid->edge[1]=1468;      
 facetid->edge[2]=1476;
 facetid->edge[3]=1475;
 facetid++;

 facetid->color=WHITE;
 facetid->nedges=4;                             
 facetid->edge[0]=1468;                   
 facetid->edge[1]=1469;      
 facetid->edge[2]=1477;
 facetid->edge[3]=1476;
 facetid++;

 facetid->color=WHITE;
 facetid->nedges=4;                          
 facetid->edge[0]=1469;                           
 facetid->edge[1]=1462;         
 facetid->edge[2]=1470;
 facetid->edge[3]=1477;
 facetid++;               
 
 //facetid->color=WHITE;        //++++++ Ladder R
 //facetid->nedges=8;            
 //facetid->edge[0]=1478;
 //facetid->edge[1]=1479;
 //facetid->edge[2]=1480;
 //facetid->edge[3]=1481;            
 //facetid->edge[4]=1482;
 //facetid->edge[5]=1483;
 //facetid->edge[6]=1484;
 //facetid->edge[7]=1485;
 //facetid++;

 facetid->color=WHITE;
 facetid->nedges=4;                             
 facetid->edge[0]=1480;                      
 facetid->edge[1]=1481;        
 facetid->edge[2]=1479; 
 facetid->edge[3]=1478;
 facetid++;

 facetid->color=WHITE;
 facetid->nedges=4;                          
 facetid->edge[0]=1479;                           
 facetid->edge[1]=1482;      
 facetid->edge[2]=1483;
 facetid->edge[3]=1478;
 facetid++;

 facetid->color=WHITE;
 facetid->nedges=4;                             
 facetid->edge[0]=1485;                      
 facetid->edge[1]=1483;     
 facetid->edge[2]=1482;
 facetid->edge[3]=1484;
 facetid++;

 facetid->color=WHITE;
 facetid->nedges=4;                     
 facetid->edge[0]=1481;                           
 facetid->edge[1]=1484;      
 facetid->edge[2]=1482;
 facetid->edge[3]=1479;
 facetid++;

 facetid->color=WHITE;
 facetid->nedges=4;                        
 facetid->edge[0]=1478;                         
 facetid->edge[1]=1483;     
 facetid->edge[2]=1485;
 facetid->edge[3]=1480;
 facetid++;

 //facetid->color=WHITE;        //++++++ Ladder L
 //facetid->nedges=8;            
 //facetid->edge[0]=1486;
 //facetid->edge[1]=1487;
 //facetid->edge[2]=1488;
 //facetid->edge[3]=1489;            
 //facetid->edge[4]=1490;
 //facetid->edge[5]=1491;
 //facetid->edge[6]=1492;
 //facetid->edge[7]=1493;
 //facetid++;

 facetid->color=WHITE;
 facetid->nedges=4;                             
 facetid->edge[0]=1486;                      
 facetid->edge[1]=1487;        
 facetid->edge[2]=1489; 
 facetid->edge[3]=1488;
 facetid++;

 facetid->color=WHITE;
 facetid->nedges=4;                          
 facetid->edge[0]=1486;                           
 facetid->edge[1]=1491;      
 facetid->edge[2]=1490;
 facetid->edge[3]=1487;
 facetid++;

 facetid->color=WHITE;
 facetid->nedges=4;                             
 facetid->edge[0]=1492;                      
 facetid->edge[1]=1490;     
 facetid->edge[2]=1491;
 facetid->edge[3]=1493;
 facetid++;

 facetid->color=WHITE;
 facetid->nedges=4;                     
 facetid->edge[0]=1487;                           
 facetid->edge[1]=1490;      
 facetid->edge[2]=1492;
 facetid->edge[3]=1489;
 facetid++;

 facetid->color=WHITE;
 facetid->nedges=4;                        
 facetid->edge[0]=1488;                         
 facetid->edge[1]=1493;     
 facetid->edge[2]=1491;
 facetid->edge[3]=1486;
 facetid++;

 //facetid->color=WHITE;        //++++++ Ladder L
 //facetid->nedges=8;            
 //facetid->edge[0]=1494;
 //facetid->edge[1]=1495;
 //facetid->edge[2]=1496;
 //facetid->edge[3]=1497;            
 //facetid->edge[4]=1498;
 //facetid->edge[5]=1499;
 //facetid->edge[6]=1500;
 //facetid->edge[7]=1501;
 //facetid++;

 facetid->color=WHITE;
 facetid->nedges=4;                             
 facetid->edge[0]=1488;                      
 facetid->edge[1]=1489;        
 facetid->edge[2]=1494; 
 facetid->edge[3]=1495;
 facetid++;

 facetid->color=WHITE;
 facetid->nedges=4;                          
 facetid->edge[0]=1497;                          
 facetid->edge[1]=1495;      
 facetid->edge[2]=1494;
 facetid->edge[3]=1496;
 facetid++;

 facetid->color=WHITE;
 facetid->nedges=4;                             
 facetid->edge[0]=1496;                     
 facetid->edge[1]=1494;   
 facetid->edge[2]=1489;
 facetid->edge[3]=1492;
 facetid++;

 facetid->color=WHITE;
 facetid->nedges=4;                     
 facetid->edge[0]=1495;                           
 facetid->edge[1]=1497;      
 facetid->edge[2]=1493;
 facetid->edge[3]=1488;
 facetid++;

 facetid->color=WHITE;
 facetid->nedges=4;                        
 facetid->edge[0]=1497;                         
 facetid->edge[1]=1496;     
 facetid->edge[2]=1492;
 facetid->edge[3]=1493;
 facetid++;

 //facetid->color=WHITE;        //++++++ Ladder R
 //facetid->nedges=8;            
 //facetid->edge[0]=1498;
 //facetid->edge[1]=1499;
 //facetid->edge[2]=1500;
 //facetid->edge[3]=1501;            
 //facetid->edge[4]=1498;
 //facetid->edge[5]=1499;
 //facetid->edge[6]=1500;
 //facetid->edge[7]=1501;
 //facetid++;

 facetid->color=WHITE;
 facetid->nedges=4;                             
 facetid->edge[0]=1481;                      
 facetid->edge[1]=1480;        
 facetid->edge[2]=1499; 
 facetid->edge[3]=1498;
 facetid++;

 facetid->color=WHITE;
 facetid->nedges=4;                          
 facetid->edge[0]=1498;                          
 facetid->edge[1]=1500;      
 facetid->edge[2]=1484;
 facetid->edge[3]=1481;
 facetid++;

 facetid->color=WHITE;
 facetid->nedges=4;                             
 facetid->edge[0]=1499;                     
 facetid->edge[1]=1501;   
 facetid->edge[2]=1500;
 facetid->edge[3]=1498;
 facetid++;

 facetid->color=WHITE;
 facetid->nedges=4;                     
 facetid->edge[0]=1501;                           
 facetid->edge[1]=1499;      
 facetid->edge[2]=1480;
 facetid->edge[3]=1485;
 facetid++;

 facetid->color=WHITE;
 facetid->nedges=4;                        
 facetid->edge[0]=1485;                         
 facetid->edge[1]=1484;     
 facetid->edge[2]=1500;
 facetid->edge[3]=1501;
 facetid++;

 //facetid->color=WHITE;        //++++++ Porch
 //facetid->nedges=8;            
 //facetid->edge[0]=1502;
 //facetid->edge[1]=1503;
 //facetid->edge[2]=1504;
 //facetid->edge[3]=1505;            
 //facetid->edge[4]=1506;
 //facetid->edge[5]=1491;
 //facetid->edge[6]=1492;
 //facetid->edge[7]=1493;
 //facetid++;

 facetid->color=LIGHTCYAN;
 facetid->nedges=4;                             
 facetid->edge[0]=1504;                      
 facetid->edge[1]=1505;        
 facetid->edge[2]=1503; 
 facetid->edge[3]=1502;
 facetid++;

 facetid->color=LIGHTCYAN;
 facetid->nedges=4;                          
 facetid->edge[0]=1503;                           
 facetid->edge[1]=1506;      
 facetid->edge[2]=1507;
 facetid->edge[3]=1502;
 facetid++;

 facetid->color=LIGHTCYAN;
 facetid->nedges=4;                             
 facetid->edge[0]=1509;                      
 facetid->edge[1]=1507;     
 facetid->edge[2]=1506;
 facetid->edge[3]=1508;
 facetid++;

 facetid->color=LIGHTCYAN;
 facetid->nedges=4;                     
 facetid->edge[0]=1505;                           
 facetid->edge[1]=1508;      
 facetid->edge[2]=1506;
 facetid->edge[3]=1503;
 facetid++;

 facetid->color=LIGHTCYAN;
 facetid->nedges=4;                        
 facetid->edge[0]=1502;                         
 facetid->edge[1]=1507;     
 facetid->edge[2]=1509;
 facetid->edge[3]=1504;
 facetid++;

 //facetid->color=WHITE;        //++++++  Porch
 //facetid->nedges=8;            
 //facetid->edge[0]=1510;
 //facetid->edge[1]=1511;
 //facetid->edge[2]=1512;
 //facetid->edge[3]=1513;            
 //facetid->edge[4]=1514;
 //facetid->edge[5]=1515;
 //facetid->edge[6]=1516;
 //facetid->edge[7]=1517;
 //facetid++;

 facetid->color=LIGHTCYAN;
 facetid->nedges=4;                             
 facetid->edge[0]=1511;                      
 facetid->edge[1]=1510;        
 facetid->edge[2]=1505; 
 facetid->edge[3]=1504;
 facetid++;

 facetid->color=LIGHTCYAN;
 facetid->nedges=4;                          
 facetid->edge[0]=1509;                          
 facetid->edge[1]=1508;      
 facetid->edge[2]=1512;
 facetid->edge[3]=1513;
 facetid++;

 facetid->color=LIGHTCYAN;
 facetid->nedges=4;                             
 facetid->edge[0]=1510;                     
 facetid->edge[1]=1512;   
 facetid->edge[2]=1508;
 facetid->edge[3]=1505;
 facetid++;

 facetid->color=LIGHTCYAN;
 facetid->nedges=4;                     
 facetid->edge[0]=1513;                          
 facetid->edge[1]=1511;    
 facetid->edge[2]=1504;
 facetid->edge[3]=1509;
 facetid++;

 facetid->color=LIGHTCYAN;
 facetid->nedges=4;                        
 facetid->edge[0]=1510;                         
 facetid->edge[1]=1511;     
 facetid->edge[2]=1513;
 facetid->edge[3]=1512;
 facetid++;
 
 //facetid->color=WHITE;        //++++ Grasp L 
 //facetid->nedges=8; 
 //facetid->edge[0]=1514;
 //facetid->edge[1]=1515;
 //facetid->edge[2]=1516;
 //facetid->edge[3]=1517;            
 //facetid->edge[4]=1518;
 //facetid->edge[5]=1519;
 //facetid->edge[6]=1520;
 //facetid->edge[7]=1521;
 //facetid++;

 facetid->color=WHITE;
 facetid->nedges=4;                             
 facetid->edge[0]=1522;                          
 facetid->edge[1]=1523;        
 facetid->edge[2]=1515; 
 facetid->edge[3]=1514;
 facetid++;

 facetid->color=WHITE;
 facetid->nedges=4;                         
 facetid->edge[0]=1523;                           
 facetid->edge[1]=1524;      
 facetid->edge[2]=1516;
 facetid->edge[3]=1515;
 facetid++;

 facetid->color=WHITE;
 facetid->nedges=4;                             
 facetid->edge[0]=1524;                        
 facetid->edge[1]=1525;      
 facetid->edge[2]=1517;
 facetid->edge[3]=1516;
 facetid++;

 facetid->color=WHITE;
 facetid->nedges=4;                           
 facetid->edge[0]=1525;                           
 facetid->edge[1]=1526;     
 facetid->edge[2]=1518;
 facetid->edge[3]=1517;
 facetid++;

 facetid->color=WHITE;
 facetid->nedges=4;                        
 facetid->edge[0]=1526;                           
 facetid->edge[1]=1527;      
 facetid->edge[2]=1519;
 facetid->edge[3]=1518;
 facetid++;

 facetid->color=WHITE;
 facetid->nedges=4;                         
 facetid->edge[0]=1527;                           
 facetid->edge[1]=1528;      
 facetid->edge[2]=1520;
 facetid->edge[3]=1519;
 facetid++;

 facetid->color=WHITE;
 facetid->nedges=4;                             
 facetid->edge[0]=1528;                      
 facetid->edge[1]=1529;      
 facetid->edge[2]=1521;
 facetid->edge[3]=1520;
 facetid++;

 facetid->color=WHITE;
 facetid->nedges=4;                           
 facetid->edge[0]=1529;                           
 facetid->edge[1]=1522;      
 facetid->edge[2]=1514;
 facetid->edge[3]=1521;
 facetid++;                    

 //facetid->color=WHITE;        //++++ Grasp R 
 //facetid->nedges=8; 
 //facetid->edge[0]=1530;
 //facetid->edge[1]=1531;
 //facetid->edge[2]=1532;
 //facetid->edge[3]=1533;            
 //facetid->edge[4]=1534;
 //facetid->edge[5]=1535;
 //facetid->edge[6]=1536;
 //facetid->edge[7]=1537;
 //facetid++;

 facetid->color=WHITE;
 facetid->nedges=4;                             
 facetid->edge[0]=1538;                          
 facetid->edge[1]=1539;        
 facetid->edge[2]=1531; 
 facetid->edge[3]=1530;
 facetid++;

 facetid->color=WHITE;
 facetid->nedges=4;                         
 facetid->edge[0]=1539;                           
 facetid->edge[1]=1540;      
 facetid->edge[2]=1532;
 facetid->edge[3]=1531;
 facetid++;

 facetid->color=WHITE;
 facetid->nedges=4;                             
 facetid->edge[0]=1540;                        
 facetid->edge[1]=1541;      
 facetid->edge[2]=1533;
 facetid->edge[3]=1532;
 facetid++;

 facetid->color=WHITE;
 facetid->nedges=4;                           
 facetid->edge[0]=1541;                           
 facetid->edge[1]=1542;     
 facetid->edge[2]=1534;
 facetid->edge[3]=1533;
 facetid++;

 facetid->color=WHITE;
 facetid->nedges=4;                        
 facetid->edge[0]=1542;                           
 facetid->edge[1]=1543;      
 facetid->edge[2]=1535;
 facetid->edge[3]=1534;
 facetid++;

 facetid->color=WHITE;
 facetid->nedges=4;                         
 facetid->edge[0]=1543;                           
 facetid->edge[1]=1544;      
 facetid->edge[2]=1536;
 facetid->edge[3]=1535;
 facetid++;

 facetid->color=WHITE;
 facetid->nedges=4;                             
 facetid->edge[0]=1544;                      
 facetid->edge[1]=1545;      
 facetid->edge[2]=1537;
 facetid->edge[3]=1536;
 facetid++;

 facetid->color=WHITE;
 facetid->nedges=4;                           
 facetid->edge[0]=1545;                           
 facetid->edge[1]=1538;      
 facetid->edge[2]=1530;
 facetid->edge[3]=1537;
 facetid++;                    

 //facetid->color=WHITE;        //++++ Grasp L' 
 //facetid->nedges=8; 
 //facetid->edge[0]=1546;
 //facetid->edge[1]=1547;
 //facetid->edge[2]=1548;
 //facetid->edge[3]=1549;            
 //facetid->edge[4]=1550;
 //facetid->edge[5]=1551;
 //facetid->edge[6]=1552;
 //facetid->edge[7]=1553;
 //facetid++;

 facetid->color=WHITE;
 facetid->nedges=4;                             
 facetid->edge[0]=1554;                          
 facetid->edge[1]=1555;        
 facetid->edge[2]=1547; 
 facetid->edge[3]=1546;
 facetid++;

 facetid->color=WHITE;
 facetid->nedges=4;                         
 facetid->edge[0]=1555;                           
 facetid->edge[1]=1556;      
 facetid->edge[2]=1548;
 facetid->edge[3]=1547;
 facetid++;

 facetid->color=WHITE;
 facetid->nedges=4;                             
 facetid->edge[0]=1556;                        
 facetid->edge[1]=1557;      
 facetid->edge[2]=1549;
 facetid->edge[3]=1548;
 facetid++;

 facetid->color=WHITE;
 facetid->nedges=4;                           
 facetid->edge[0]=1557;                           
 facetid->edge[1]=1558;     
 facetid->edge[2]=1550;
 facetid->edge[3]=1549;
 facetid++;

 facetid->color=WHITE;
 facetid->nedges=4;                        
 facetid->edge[0]=1558;                           
 facetid->edge[1]=1559;      
 facetid->edge[2]=1551;
 facetid->edge[3]=1550;
 facetid++;

 facetid->color=WHITE;
 facetid->nedges=4;                         
 facetid->edge[0]=1559;                           
 facetid->edge[1]=1560;      
 facetid->edge[2]=1552;
 facetid->edge[3]=1551;
 facetid++;

 facetid->color=WHITE;
 facetid->nedges=4;                             
 facetid->edge[0]=1560;                      
 facetid->edge[1]=1561;      
 facetid->edge[2]=1553;
 facetid->edge[3]=1552;
 facetid++;

 facetid->color=WHITE;
 facetid->nedges=4;                           
 facetid->edge[0]=1561;                           
 facetid->edge[1]=1554;      
 facetid->edge[2]=1546;
 facetid->edge[3]=1553;
 facetid++;                    

 //facetid->color=WHITE;        //++++ Grasp R' 
 //facetid->nedges=8; 
 //facetid->edge[0]=1562;
 //facetid->edge[1]=1563;
 //facetid->edge[2]=1564;
 //facetid->edge[3]=1565;            
 //facetid->edge[4]=1566;
 //facetid->edge[5]=1567;
 //facetid->edge[6]=1568;
 //facetid->edge[7]=1569;
 //facetid++;

 facetid->color=WHITE;
 facetid->nedges=4;                             
 facetid->edge[0]=1570;                          
 facetid->edge[1]=1571;        
 facetid->edge[2]=1563; 
 facetid->edge[3]=1562;
 facetid++;

 facetid->color=WHITE;
 facetid->nedges=4;                         
 facetid->edge[0]=1571;                           
 facetid->edge[1]=1572;      
 facetid->edge[2]=1564;
 facetid->edge[3]=1563;
 facetid++;

 facetid->color=WHITE;
 facetid->nedges=4;                             
 facetid->edge[0]=1572;                        
 facetid->edge[1]=1573;      
 facetid->edge[2]=1565;
 facetid->edge[3]=1564;
 facetid++;

 facetid->color=WHITE;
 facetid->nedges=4;                           
 facetid->edge[0]=1573;                           
 facetid->edge[1]=1574;     
 facetid->edge[2]=1566;
 facetid->edge[3]=1565;
 facetid++;

 facetid->color=WHITE;
 facetid->nedges=4;                        
 facetid->edge[0]=1574;                           
 facetid->edge[1]=1575;      
 facetid->edge[2]=1567;
 facetid->edge[3]=1566;
 facetid++;

 facetid->color=WHITE;
 facetid->nedges=4;                         
 facetid->edge[0]=1575;                           
 facetid->edge[1]=1576;      
 facetid->edge[2]=1568;
 facetid->edge[3]=1567;
 facetid++;

 facetid->color=WHITE;
 facetid->nedges=4;                             
 facetid->edge[0]=1576;                      
 facetid->edge[1]=1577;      
 facetid->edge[2]=1569;
 facetid->edge[3]=1568;
 facetid++;

 facetid->color=WHITE;
 facetid->nedges=4;                           
 facetid->edge[0]=1577;                           
 facetid->edge[1]=1570;      
 facetid->edge[2]=1562;
 facetid->edge[3]=1569;
 facetid++;                    

 //facetid->color=WHITE;        //++++ Grasp top R' 
 //facetid->nedges=8; 
 //facetid->edge[0]=1578;
 //facetid->edge[1]=1579;
 //facetid->edge[2]=1580;
 //facetid->edge[3]=1581;            
 //facetid->edge[4]=1582;
 //facetid->edge[5]=1583;
 //facetid->edge[6]=1584;
 //facetid->edge[7]=1585;
 //facetid++;

 facetid->color=WHITE;
 facetid->nedges=4;                             
 facetid->edge[0]=1586;                          
 facetid->edge[1]=1587;        
 facetid->edge[2]=1579; 
 facetid->edge[3]=1578;
 facetid++;

 facetid->color=WHITE;
 facetid->nedges=4;                         
 facetid->edge[0]=1587;                           
 facetid->edge[1]=1588;      
 facetid->edge[2]=1580;
 facetid->edge[3]=1579;
 facetid++;

 facetid->color=WHITE;
 facetid->nedges=4;                             
 facetid->edge[0]=1588;                        
 facetid->edge[1]=1589;      
 facetid->edge[2]=1581;
 facetid->edge[3]=1580;
 facetid++;

 facetid->color=WHITE;
 facetid->nedges=4;                           
 facetid->edge[0]=1589;                           
 facetid->edge[1]=1590;     
 facetid->edge[2]=1582;
 facetid->edge[3]=1581;
 facetid++;

 facetid->color=WHITE;
 facetid->nedges=4;                        
 facetid->edge[0]=1590;                           
 facetid->edge[1]=1591;      
 facetid->edge[2]=1583;
 facetid->edge[3]=1582;
 facetid++;

 facetid->color=WHITE;
 facetid->nedges=4;                         
 facetid->edge[0]=1591;                           
 facetid->edge[1]=1592;      
 facetid->edge[2]=1584;
 facetid->edge[3]=1583;
 facetid++;

 facetid->color=WHITE;
 facetid->nedges=4;                             
 facetid->edge[0]=1592;                      
 facetid->edge[1]=1593;      
 facetid->edge[2]=1585;
 facetid->edge[3]=1584;
 facetid++;

 facetid->color=WHITE;
 facetid->nedges=4;                           
 facetid->edge[0]=1593;                           
 facetid->edge[1]=1586;      
 facetid->edge[2]=1578;
 facetid->edge[3]=1585;
 facetid++;                    

 //facetid->color=WHITE;        //++++ Grasp top L'
 //facetid->nedges=8; 
 //facetid->edge[0]=1594;
 //facetid->edge[1]=1595;
 //facetid->edge[2]=1596;
 //facetid->edge[3]=1597;            
 //facetid->edge[4]=1598;
 //facetid->edge[5]=1599;
 //facetid->edge[6]=1600;
 //facetid->edge[7]=1601;
 //facetid++;

 facetid->color=WHITE;
 facetid->nedges=4;                             
 facetid->edge[0]=1602;                          
 facetid->edge[1]=1603;        
 facetid->edge[2]=1595; 
 facetid->edge[3]=1594;
 facetid++;

 facetid->color=WHITE;
 facetid->nedges=4;                         
 facetid->edge[0]=1603;                           
 facetid->edge[1]=1604;      
 facetid->edge[2]=1596;
 facetid->edge[3]=1595;
 facetid++;

 facetid->color=WHITE;
 facetid->nedges=4;                             
 facetid->edge[0]=1604;                        
 facetid->edge[1]=1605;      
 facetid->edge[2]=1597;
 facetid->edge[3]=1596;
 facetid++;

 facetid->color=WHITE;
 facetid->nedges=4;                           
 facetid->edge[0]=1605;                           
 facetid->edge[1]=1606;     
 facetid->edge[2]=1598;
 facetid->edge[3]=1597;
 facetid++;

 facetid->color=WHITE;
 facetid->nedges=4;                        
 facetid->edge[0]=1606;                           
 facetid->edge[1]=1607;      
 facetid->edge[2]=1599;
 facetid->edge[3]=1598;
 facetid++;

 facetid->color=WHITE;
 facetid->nedges=4;                         
 facetid->edge[0]=1607;                           
 facetid->edge[1]=1608;      
 facetid->edge[2]=1600;
 facetid->edge[3]=1599;
 facetid++;

 facetid->color=WHITE;
 facetid->nedges=4;                             
 facetid->edge[0]=1608;                      
 facetid->edge[1]=1609;      
 facetid->edge[2]=1601;
 facetid->edge[3]=1600;
 facetid++;

 facetid->color=WHITE;
 facetid->nedges=4;                           
 facetid->edge[0]=1609;                           
 facetid->edge[1]=1602;      
 facetid->edge[2]=1594;
 facetid->edge[3]=1601;
 facetid++;                     

 facetid->color=WHITE;            //++++ connect top L' 
 facetid->nedges=4;                             
 facetid->edge[0]=1603;                          
 facetid->edge[1]=1602;        
 facetid->edge[2]=1523; 
 facetid->edge[3]=1522;
 facetid++;

 facetid->color=WHITE;
 facetid->nedges=4;                         
 facetid->edge[0]=1604;                           
 facetid->edge[1]=1603;      
 facetid->edge[2]=1522;
 facetid->edge[3]=1529;
 facetid++;

 facetid->color=WHITE;
 facetid->nedges=4;                             
 facetid->edge[0]=1605;                        
 facetid->edge[1]=1604;      
 facetid->edge[2]=1529;
 facetid->edge[3]=1528;
 facetid++;

 facetid->color=WHITE;
 facetid->nedges=4;                           
 facetid->edge[0]=1606;                           
 facetid->edge[1]=1605;     
 facetid->edge[2]=1528;
 facetid->edge[3]=1527;
 facetid++;

 facetid->color=WHITE;
 facetid->nedges=4;                        
 facetid->edge[0]=1607;                           
 facetid->edge[1]=1606;      
 facetid->edge[2]=1527;
 facetid->edge[3]=1526;
 facetid++;

 facetid->color=WHITE;
 facetid->nedges=4;                         
 facetid->edge[0]=1608;                           
 facetid->edge[1]=1607;      
 facetid->edge[2]=1526;
 facetid->edge[3]=1525;
 facetid++;

 facetid->color=WHITE;
 facetid->nedges=4;                             
 facetid->edge[0]=1609;                      
 facetid->edge[1]=1608;      
 facetid->edge[2]=1525;
 facetid->edge[3]=1524;
 facetid++;

 facetid->color=WHITE;
 facetid->nedges=4;                           
 facetid->edge[0]=1602;                           
 facetid->edge[1]=1609;      
 facetid->edge[2]=1524;
 facetid->edge[3]=1523;
 facetid++;                    

 facetid->color=WHITE;            //++++ connect top L '''
 facetid->nedges=4;                             
 facetid->edge[0]=1595;                          
 facetid->edge[1]=1596;       
 facetid->edge[2]=1554;
 facetid->edge[3]=1561;
 facetid++;

 facetid->color=WHITE;
 facetid->nedges=4;                         
 facetid->edge[0]=1596;                           
 facetid->edge[1]=1597;      
 facetid->edge[2]=1555;
 facetid->edge[3]=1554;
 facetid++;

 facetid->color=WHITE;
 facetid->nedges=4;                             
 facetid->edge[0]=1597;                        
 facetid->edge[1]=1598;      
 facetid->edge[2]=1556;
 facetid->edge[3]=1555;
 facetid++;

 facetid->color=WHITE;
 facetid->nedges=4;                           
 facetid->edge[0]=1598;                           
 facetid->edge[1]=1599;     
 facetid->edge[2]=1557;
 facetid->edge[3]=1556;
 facetid++;

 facetid->color=WHITE;
 facetid->nedges=4;                        
 facetid->edge[0]=1599;                           
 facetid->edge[1]=1600;      
 facetid->edge[2]=1558;
 facetid->edge[3]=1557;
 facetid++;

 facetid->color=WHITE;
 facetid->nedges=4;                         
 facetid->edge[0]=1600;                           
 facetid->edge[1]=1601;      
 facetid->edge[2]=1559;
 facetid->edge[3]=1558;
 facetid++;

 facetid->color=WHITE;
 facetid->nedges=4;                             
 facetid->edge[0]=1601;                      
 facetid->edge[1]=1594;      
 facetid->edge[2]=1560;
 facetid->edge[3]=1559;
 facetid++;

 facetid->color=WHITE;
 facetid->nedges=4;                           
 facetid->edge[0]=1594;                          
 facetid->edge[1]=1595;     
 facetid->edge[2]=1561;
 facetid->edge[3]=1560;
 facetid++;                    

 facetid->color=WHITE;            //++++ connect top R'' 
 facetid->nedges=4;                             
 facetid->edge[0]=1588;                          
 facetid->edge[1]=1587;       
 facetid->edge[2]=1538; 
 facetid->edge[3]=1545;
 facetid++;

 facetid->color=WHITE;
 facetid->nedges=4;                         
 facetid->edge[0]=1589;                           
 facetid->edge[1]=1588;      
 facetid->edge[2]=1545;
 facetid->edge[3]=1544;
 facetid++;

 facetid->color=WHITE;
 facetid->nedges=4;                             
 facetid->edge[0]=1590;                        
 facetid->edge[1]=1589;      
 facetid->edge[2]=1544;
 facetid->edge[3]=1543;
 facetid++;

 facetid->color=WHITE;
 facetid->nedges=4;                           
 facetid->edge[0]=1591;                           
 facetid->edge[1]=1590;     
 facetid->edge[2]=1543;
 facetid->edge[3]=1542;
 facetid++;

 facetid->color=WHITE;
 facetid->nedges=4;                        
 facetid->edge[0]=1592;                           
 facetid->edge[1]=1591;      
 facetid->edge[2]=1542;
 facetid->edge[3]=1541;
 facetid++;

 facetid->color=WHITE;
 facetid->nedges=4;                         
 facetid->edge[0]=1593;                           
 facetid->edge[1]=1592;      
 facetid->edge[2]=1541;
 facetid->edge[3]=1540;
 facetid++;

 facetid->color=WHITE;
 facetid->nedges=4;                             
 facetid->edge[0]=1586;                      
 facetid->edge[1]=1593;      
 facetid->edge[2]=1540;
 facetid->edge[3]=1539;
 facetid++;

 facetid->color=WHITE;
 facetid->nedges=4;                           
 facetid->edge[0]=1587;                           
 facetid->edge[1]=1586;      
 facetid->edge[2]=1539;
 facetid->edge[3]=1538;
 facetid++;                    

 facetid->color=WHITE;            //++++ connect top R'' 
 facetid->nedges=4;                             
 facetid->edge[0]=1579;                          
 facetid->edge[1]=1580;       
 facetid->edge[2]=1570; 
 facetid->edge[3]=1577;
 facetid++;

 facetid->color=WHITE;
 facetid->nedges=4;                         
 facetid->edge[0]=1585;                           
 facetid->edge[1]=1578;      
 facetid->edge[2]=1576;
 facetid->edge[3]=1575;
 facetid++;

 facetid->color=WHITE;
 facetid->nedges=4;                             
 facetid->edge[0]=1584;                        
 facetid->edge[1]=1585;     
 facetid->edge[2]=1575;
 facetid->edge[3]=1574;
 facetid++;

 facetid->color=WHITE;
 facetid->nedges=4;                           
 facetid->edge[0]=1583;                           
 facetid->edge[1]=1584;     
 facetid->edge[2]=1574;
 facetid->edge[3]=1573;
 facetid++;

 facetid->color=WHITE;
 facetid->nedges=4;                        
 facetid->edge[0]=1582;                           
 facetid->edge[1]=1583;      
 facetid->edge[2]=1573;
 facetid->edge[3]=1572;
 facetid++;

 facetid->color=WHITE;
 facetid->nedges=4;                         
 facetid->edge[0]=1581;                           
 facetid->edge[1]=1582;      
 facetid->edge[2]=1572;
 facetid->edge[3]=1571;
 facetid++;

 facetid->color=WHITE;
 facetid->nedges=4;                             
 facetid->edge[0]=1580;                      
 facetid->edge[1]=1581;      
 facetid->edge[2]=1571;
 facetid->edge[3]=1570;
 facetid++;

 facetid->color=WHITE;
 facetid->nedges=4;                           
 facetid->edge[0]=1578;                           
 facetid->edge[1]=1579;      
 facetid->edge[2]=1577;
 facetid->edge[3]=1576;
 facetid++;                    

 //facetid->color=BLUE;    //++++++++++++ A  
 //facetid->nedges=8; 
 //facetid->edge[0]=1627;
 //facetid->edge[1]=1628;
 //facetid->edge[2]=1629;
 //facetid->edge[3]=1630;            
 //facetid->edge[4]=1631;
 //facetid->edge[5]=1632;
 //facetid->edge[6]=1633;
 //facetid->edge[7]=1634;
 //facetid++;

 facetid->color=LIGHTRED;
 facetid->nedges=4;                             
 facetid->edge[0]=1627;                          
 facetid->edge[1]=1628;        
 facetid->edge[2]=1636; 
 facetid->edge[3]=1635;
 facetid++;

 facetid->color=LIGHTRED;
 facetid->nedges=4;                          
 facetid->edge[0]=1628;                          
 facetid->edge[1]=1629;      
 facetid->edge[2]=1637;
 facetid->edge[3]=1636;
 facetid++;

 facetid->color=LIGHTRED;
 facetid->nedges=4;                             
 facetid->edge[0]=1629;                        
 facetid->edge[1]=1630;      
 facetid->edge[2]=1638;
 facetid->edge[3]=1637;
 facetid++;

 facetid->color=BLUE;
 facetid->nedges=4;                           
 facetid->edge[0]=1630;                           
 facetid->edge[1]=1631;      
 facetid->edge[2]=1639;
 facetid->edge[3]=1638;
 facetid++;

 facetid->color=BLUE;
 facetid->nedges=4;                         
 facetid->edge[0]=1631;                           
 facetid->edge[1]=1632;      
 facetid->edge[2]=1640;
 facetid->edge[3]=1639;
 facetid++;

 facetid->color=BLUE;
 facetid->nedges=4;                        
 facetid->edge[0]=1632;                           
 facetid->edge[1]=1633;      
 facetid->edge[2]=1641;
 facetid->edge[3]=1640;
 facetid++;

 facetid->color=BLUE; 
 facetid->nedges=4;                             
 facetid->edge[0]=1633;                       
 facetid->edge[1]=1634;      
 facetid->edge[2]=1642;
 facetid->edge[3]=1641;
 facetid++;

 facetid->color=BLUE;
 facetid->nedges=4;                           
 facetid->edge[0]=1634;                           
 facetid->edge[1]=1627;      
 facetid->edge[2]=1635;
 facetid->edge[3]=1642;
 facetid++;                   

 facetid->color=DARKGRAY;
 facetid->nedges=4;                             
 facetid->edge[0]=1628;                          
 facetid->edge[1]=1627;      
 facetid->edge[2]=142;
 facetid->edge[3]=143;
 facetid++;

 facetid->color=DARKGRAY;
 facetid->nedges=4;                          
 facetid->edge[0]=1629;                          
 facetid->edge[1]=1628;      
 facetid->edge[2]=143;
 facetid->edge[3]=144;
 facetid++;

 facetid->color=DARKGRAY;
 facetid->nedges=4;                             
 facetid->edge[0]=1630;                        
 facetid->edge[1]=1629;      
 facetid->edge[2]=144;
 facetid->edge[3]=145;
 facetid++;

 facetid->color=DARKGRAY;
 facetid->nedges=4;                           
 facetid->edge[0]=1631;                           
 facetid->edge[1]=1630;      
 facetid->edge[2]=145;
 facetid->edge[3]=146;
 facetid++;

 facetid->color=DARKGRAY;
 facetid->nedges=4;                         
 facetid->edge[0]=1632;                           
 facetid->edge[1]=1631;      
 facetid->edge[2]=146;
 facetid->edge[3]=147;
 facetid++;

 facetid->color=DARKGRAY;
 facetid->nedges=4;                        
 facetid->edge[0]=1633;                           
 facetid->edge[1]=1632;      
 facetid->edge[2]=147;
 facetid->edge[3]=148;
 facetid++;

 facetid->color=DARKGRAY; 
 facetid->nedges=4;                             
 facetid->edge[0]=1634;                       
 facetid->edge[1]=1633;      
 facetid->edge[2]=148;
 facetid->edge[3]=149;
 facetid++;

 facetid->color=DARKGRAY;
 facetid->nedges=4;                           
 facetid->edge[0]=149;                           
 facetid->edge[1]=142;      
 facetid->edge[2]=1627;
 facetid->edge[3]=1634;
 facetid++;                    

 //facetid->color=BLUE;    //+++++++++++++ B    
 //facetid->nedges=8; 
 //facetid->edge[0]=1643;
 //facetid->edge[1]=1644;
 //facetid->edge[2]=1645;
 //facetid->edge[3]=1646;            
 //facetid->edge[4]=1647;
 //facetid->edge[5]=1648;
 //facetid->edge[6]=1649;
 //facetid->edge[7]=1650;
 //facetid++;

 facetid->color=BLUE;
 facetid->nedges=4;                             
 facetid->edge[0]=1643;                          
 facetid->edge[1]=1644;       
 facetid->edge[2]=1652; 
 facetid->edge[3]=1651;
 facetid++;

 facetid->color=BLUE;
 facetid->nedges=4;                          
 facetid->edge[0]=1644;                           
 facetid->edge[1]=1645;      
 facetid->edge[2]=1653;
 facetid->edge[3]=1652;
 facetid++;

 facetid->color=LIGHTRED;
 facetid->nedges=4;                             
 facetid->edge[0]=1645;                        
 facetid->edge[1]=1646;     
 facetid->edge[2]=1654;
 facetid->edge[3]=1653;
 facetid++;

 facetid->color=LIGHTRED;
 facetid->nedges=4;                           
 facetid->edge[0]=1646;                          
 facetid->edge[1]=1647;     
 facetid->edge[2]=1655;
 facetid->edge[3]=1654;
 facetid++;

 facetid->color=LIGHTRED;
 facetid->nedges=4;                         
 facetid->edge[0]=1647;                           
 facetid->edge[1]=1648;     
 facetid->edge[2]=1656;
 facetid->edge[3]=1655;
 facetid++;

 facetid->color=BLUE;
 facetid->nedges=4;                        
 facetid->edge[0]=1648;                          
 facetid->edge[1]=1649;      
 facetid->edge[2]=1657;
 facetid->edge[3]=1656;
 facetid++;

 facetid->color=BLUE; 
 facetid->nedges=4;                             
 facetid->edge[0]=1649;                     
 facetid->edge[1]=1650;     
 facetid->edge[2]=1658;
 facetid->edge[3]=1657;
 facetid++;

 facetid->color=BLUE;
 facetid->nedges=4;                           
 facetid->edge[0]=1650;                          
 facetid->edge[1]=1643;      
 facetid->edge[2]=1651;
 facetid->edge[3]=1658;
 facetid++;                    
 
 facetid->color=DARKGRAY;
 facetid->nedges=4;                             
 facetid->edge[0]=1644;                          
 facetid->edge[1]=1643;       
 facetid->edge[2]=158; 
 facetid->edge[3]=159;
 facetid++;

 facetid->color=DARKGRAY;
 facetid->nedges=4;                          
 facetid->edge[0]=1645;                           
 facetid->edge[1]=1644;      
 facetid->edge[2]=159;
 facetid->edge[3]=160;
 facetid++;

 facetid->color=DARKGRAY;
 facetid->nedges=4;                             
 facetid->edge[0]=1646;                        
 facetid->edge[1]=1645;     
 facetid->edge[2]=160;
 facetid->edge[3]=161;
 facetid++;

 facetid->color=DARKGRAY;
 facetid->nedges=4;                           
 facetid->edge[0]=1647;                          
 facetid->edge[1]=1646;     
 facetid->edge[2]=161;
 facetid->edge[3]=162;
 facetid++;

 facetid->color=DARKGRAY;
 facetid->nedges=4;                         
 facetid->edge[0]=1648;                           
 facetid->edge[1]=1647;     
 facetid->edge[2]=162;
 facetid->edge[3]=163;
 facetid++;

 facetid->color=DARKGRAY;
 facetid->nedges=4;                        
 facetid->edge[0]=1649;                          
 facetid->edge[1]=1648;      
 facetid->edge[2]=163;
 facetid->edge[3]=164;
 facetid++;

 facetid->color=DARKGRAY; 
 facetid->nedges=4;                             
 facetid->edge[0]=1650;                     
 facetid->edge[1]=1649;     
 facetid->edge[2]=164;
 facetid->edge[3]=165;
 facetid++;

 facetid->color=DARKGRAY;
 facetid->nedges=4;                           
 facetid->edge[0]=165;                          
 facetid->edge[1]=158;     
 facetid->edge[2]=1643;
 facetid->edge[3]=1650;
 facetid++;                    
 
 //facetid->color=BLUE;    //+++++++++++++++ C 
 //facetid->nedges=8; 
 //facetid->edge[0]=1659;
 //facetid->edge[1]=1660;
 //facetid->edge[2]=1661;
 //facetid->edge[3]=1662;            
 //facetid->edge[4]=1663;
 //facetid->edge[5]=1664;
 //facetid->edge[6]=1665;
 //facetid->edge[7]=1666;
 //facetid++;

 facetid->color=LIGHTRED;
 facetid->nedges=4;                             
 facetid->edge[0]=1659;                        
 facetid->edge[1]=1660;        
 facetid->edge[2]=1668; 
 facetid->edge[3]=1667;
 facetid++;

 facetid->color=BLUE;
 facetid->nedges=4;                          
 facetid->edge[0]=1660;                          
 facetid->edge[1]=1661;      
 facetid->edge[2]=1669;
 facetid->edge[3]=1668;
 facetid++;

 facetid->color=BLUE;
 facetid->nedges=4;                             
 facetid->edge[0]=1661;                        
 facetid->edge[1]=1662;      
 facetid->edge[2]=1670;
 facetid->edge[3]=1669;
 facetid++;

 facetid->color=BLUE;
 facetid->nedges=4;                           
 facetid->edge[0]=1662;                          
 facetid->edge[1]=1663;      
 facetid->edge[2]=1671;
 facetid->edge[3]=1670;
 facetid++;

 facetid->color=BLUE;
 facetid->nedges=4;                         
 facetid->edge[0]=1663;                           
 facetid->edge[1]=1664;     
 facetid->edge[2]=1672;
 facetid->edge[3]=1671;
 facetid++;

 facetid->color=BLUE;
 facetid->nedges=4;                        
 facetid->edge[0]=1664;                           
 facetid->edge[1]=1665;     
 facetid->edge[2]=1673;
 facetid->edge[3]=1672;
 facetid++;

 facetid->color=LIGHTRED; 
 facetid->nedges=4;                             
 facetid->edge[0]=1665;                      
 facetid->edge[1]=1666;     
 facetid->edge[2]=1674;
 facetid->edge[3]=1673;
 facetid++;

 facetid->color=LIGHTRED;
 facetid->nedges=4;                           
 facetid->edge[0]=1666;                           
 facetid->edge[1]=1659;      
 facetid->edge[2]=1667;
 facetid->edge[3]=1674;
 facetid++;                    
  
 facetid->color=DARKGRAY;
 facetid->nedges=4;                             
 facetid->edge[0]=1660;                        
 facetid->edge[1]=1659;        
 facetid->edge[2]=174; 
 facetid->edge[3]=175;
 facetid++;

 facetid->color=DARKGRAY;
 facetid->nedges=4;                          
 facetid->edge[0]=1661;                          
 facetid->edge[1]=1660;      
 facetid->edge[2]=175;
 facetid->edge[3]=176;
 facetid++;

 facetid->color=DARKGRAY;
 facetid->nedges=4;                             
 facetid->edge[0]=1662;                        
 facetid->edge[1]=1661;      
 facetid->edge[2]=176;
 facetid->edge[3]=177;
 facetid++;

 facetid->color=DARKGRAY;
 facetid->nedges=4;                           
 facetid->edge[0]=1663;                          
 facetid->edge[1]=1662;      
 facetid->edge[2]=177;
 facetid->edge[3]=178;
 facetid++;

 facetid->color=DARKGRAY;
 facetid->nedges=4;                         
 facetid->edge[0]=1664;                           
 facetid->edge[1]=1663;     
 facetid->edge[2]=178;
 facetid->edge[3]=179;
 facetid++;

 facetid->color=DARKGRAY;
 facetid->nedges=4;                        
 facetid->edge[0]=1665;                           
 facetid->edge[1]=1664;     
 facetid->edge[2]=179;
 facetid->edge[3]=180;
 facetid++;

 facetid->color=DARKGRAY;
 facetid->nedges=4;                             
 facetid->edge[0]=1666;                      
 facetid->edge[1]=1665;     
 facetid->edge[2]=180;
 facetid->edge[3]=181;
 facetid++;

 facetid->color=DARKGRAY;
 facetid->nedges=4;                           
 facetid->edge[0]=181;                           
 facetid->edge[1]=174;      
 facetid->edge[2]=1659;
 facetid->edge[3]=1666;
 facetid++;                    

 //facetid->color=BLUE;    //+++++++++++++++ D 
 //facetid->nedges=8; 
 //facetid->edge[0]=1675;
 //facetid->edge[1]=1676;
 //facetid->edge[2]=1677;
 //facetid->edge[3]=1678;            
 //facetid->edge[4]=1679;
 //facetid->edge[5]=1680;
 //facetid->edge[6]=1681;
 //facetid->edge[7]=1682;
 //facetid++;

 facetid->color=BLUE;
 facetid->nedges=4;                             
 facetid->edge[0]=1675;                        
 facetid->edge[1]=1676;        
 facetid->edge[2]=1684; 
 facetid->edge[3]=1683;
 facetid++;

 facetid->color=BLUE;
 facetid->nedges=4;                          
 facetid->edge[0]=1676;                          
 facetid->edge[1]=1677;      
 facetid->edge[2]=1685;
 facetid->edge[3]=1684;
 facetid++;

 facetid->color=BLUE;
 facetid->nedges=4;                             
 facetid->edge[0]=1677;                       
 facetid->edge[1]=1678;      
 facetid->edge[2]=1686;
 facetid->edge[3]=1685;
 facetid++;

 facetid->color=BLUE;
 facetid->nedges=4;                           
 facetid->edge[0]=1678;                          
 facetid->edge[1]=1679;     
 facetid->edge[2]=1687;
 facetid->edge[3]=1686;
 facetid++;

 facetid->color=LIGHTRED;
 facetid->nedges=4;                         
 facetid->edge[0]=1679;                           
 facetid->edge[1]=1680;      
 facetid->edge[2]=1688;
 facetid->edge[3]=1687;
 facetid++;

 facetid->color=LIGHTRED;
 facetid->nedges=4;                        
 facetid->edge[0]=1680;                          
 facetid->edge[1]=1681;     
 facetid->edge[2]=1689;
 facetid->edge[3]=1688;
 facetid++;

 facetid->color=LIGHTRED; 
 facetid->nedges=4;                             
 facetid->edge[0]=1681;                      
 facetid->edge[1]=1682;     
 facetid->edge[2]=1690;
 facetid->edge[3]=1689;
 facetid++;

 facetid->color=BLUE;
 facetid->nedges=4;                           
 facetid->edge[0]=1682;                           
 facetid->edge[1]=1675;    
 facetid->edge[2]=1683;
 facetid->edge[3]=1690;
 facetid++;                    
                          
 facetid->color=DARKGRAY;
 facetid->nedges=4;                             
 facetid->edge[0]=190;                        
 facetid->edge[1]=191;        
 facetid->edge[2]=1676; 
 facetid->edge[3]=1675;
 facetid++;

 facetid->color=DARKGRAY;
 facetid->nedges=4;                          
 facetid->edge[0]=191;                          
 facetid->edge[1]=192;      
 facetid->edge[2]=1677;
 facetid->edge[3]=1676;
 facetid++;

 facetid->color=DARKGRAY;
 facetid->nedges=4;                             
 facetid->edge[0]=192;                       
 facetid->edge[1]=193;      
 facetid->edge[2]=1678;
 facetid->edge[3]=1677;
 facetid++;

 facetid->color=DARKGRAY;
 facetid->nedges=4;                           
 facetid->edge[0]=193;                          
 facetid->edge[1]=194;     
 facetid->edge[2]=1679;
 facetid->edge[3]=1678;
 facetid++;

 facetid->color=DARKGRAY;
 facetid->nedges=4;                         
 facetid->edge[0]=194;                           
 facetid->edge[1]=195;      
 facetid->edge[2]=1680;
 facetid->edge[3]=1679;
 facetid++;

 facetid->color=DARKGRAY;
 facetid->nedges=4;                        
 facetid->edge[0]=195;                          
 facetid->edge[1]=196;     
 facetid->edge[2]=1681;
 facetid->edge[3]=1680;
 facetid++;

 facetid->color=DARKGRAY; 
 facetid->nedges=4;                             
 facetid->edge[0]=196;                      
 facetid->edge[1]=197;     
 facetid->edge[2]=1682;
 facetid->edge[3]=1681;
 facetid++;

 facetid->color=DARKGRAY;
 facetid->nedges=4;                           
 facetid->edge[0]=197;                           
 facetid->edge[1]=190;    
 facetid->edge[2]=1675;
 facetid->edge[3]=1682;
 facetid++;                    
  

  //facetid->color=WHITE;    //+++++++++++++++ P1
 //facetid->nedges=8; 
 //facetid->edge[0]=1691;
 //facetid->edge[1]=1692;
 //facetid->edge[2]=1693;
 //facetid->edge[3]=1694;            
 //facetid->edge[4]=1695;
 //facetid->edge[5]=1696;
 //facetid->edge[6]=1697;
 //facetid->edge[7]=1698;
 //facetid++;

 /*
 facetid->color=WHITE;
 facetid->nedges=4;                             
 facetid->edge[0]=1691;                       
 facetid->edge[1]=1692;        
 facetid->edge[2]=1700; 
 facetid->edge[3]=1699;
 facetid++;

 facetid->color=WHITE;
 facetid->nedges=4;                          
 facetid->edge[0]=1692;                          
 facetid->edge[1]=1693;      
 facetid->edge[2]=1701;
 facetid->edge[3]=1700;
 facetid++;

 facetid->color=WHITE;
 facetid->nedges=4;                             
 facetid->edge[0]=1693;                       
 facetid->edge[1]=1694;      
 facetid->edge[2]=1702;
 facetid->edge[3]=1701;
 facetid++;

 facetid->color=WHITE;
 facetid->nedges=4;                           
 facetid->edge[0]=1694;                          
 facetid->edge[1]=1695;     
 facetid->edge[2]=1703;
 facetid->edge[3]=1702;
 facetid++;

 facetid->color=WHITE;
 facetid->nedges=4;                         
 facetid->edge[0]=1695;                           
 facetid->edge[1]=1696;      
 facetid->edge[2]=1704;
 facetid->edge[3]=1703;
 facetid++;

 facetid->color=WHITE;
 facetid->nedges=4;                        
 facetid->edge[0]=1696;                          
 facetid->edge[1]=1697;     
 facetid->edge[2]=1705;
 facetid->edge[3]=1704;
 facetid++;

 facetid->color=WHITE; 
 facetid->nedges=4;                             
 facetid->edge[0]=1697;                      
 facetid->edge[1]=1698;     
 facetid->edge[2]=1706;
 facetid->edge[3]=1705;
 facetid++;

 facetid->color=WHITE;
 facetid->nedges=4;                           
 facetid->edge[0]=1698;                           
 facetid->edge[1]=1691;    
 facetid->edge[2]=1699;
 facetid->edge[3]=1706;
 facetid++;                    
 */
                          
 //facetid->color=WHITE;    //+++++++++++++++ P2
 //facetid->nedges=8; 
 //facetid->edge[0]=1707;
 //facetid->edge[1]=1708;
 //facetid->edge[2]=1709;
 //facetid->edge[3]=1710;            
 //facetid->edge[4]=1711;
 //facetid->edge[5]=1712;
 //facetid->edge[6]=1713;
 //facetid->edge[7]=1714;
 //facetid++;

  /*
 facetid->color=WHITE;
 facetid->nedges=4;                             
 facetid->edge[0]=1707;                        
 facetid->edge[1]=1708;        
 facetid->edge[2]=1716; 
 facetid->edge[3]=1715;
 facetid++;

 facetid->color=WHITE;
 facetid->nedges=4;                          
 facetid->edge[0]=1708;                          
 facetid->edge[1]=1709;      
 facetid->edge[2]=1717;
 facetid->edge[3]=1716;
 facetid++;

 facetid->color=WHITE;
 facetid->nedges=4;                             
 facetid->edge[0]=1709;                       
 facetid->edge[1]=1710;      
 facetid->edge[2]=1718;
 facetid->edge[3]=1717;
 facetid++;

 facetid->color=WHITE;
 facetid->nedges=4;                           
 facetid->edge[0]=1710;                          
 facetid->edge[1]=1711;     
 facetid->edge[2]=1719;
 facetid->edge[3]=1718;
 facetid++;

 facetid->color=WHITE;
 facetid->nedges=4;                         
 facetid->edge[0]=1711;                           
 facetid->edge[1]=1712;      
 facetid->edge[2]=1720;
 facetid->edge[3]=1719;
 facetid++;

 facetid->color=WHITE;
 facetid->nedges=4;                        
 facetid->edge[0]=1712;                          
 facetid->edge[1]=1713;     
 facetid->edge[2]=1721;
 facetid->edge[3]=1720;
 facetid++;

 facetid->color=WHITE; 
 facetid->nedges=4;                             
 facetid->edge[0]=1713;                      
 facetid->edge[1]=1714;     
 facetid->edge[2]=1722;
 facetid->edge[3]=1721;
 facetid++;

 facetid->color=WHITE;
 facetid->nedges=4;                           
 facetid->edge[0]=1714;                           
 facetid->edge[1]=1707;    
 facetid->edge[2]=1715;
 facetid->edge[3]=1722;
 facetid++;                    
 */                        


 /*
 facetid->color=; 
 facetid->nedges=;
 facetid->edge[0]=;
 facetid->edge[1]=;
 facetid->edge[2]=;
 facetid->edge[3]=;
 facetid++;
 */

 if (object[id].facet+nfacets!=facetid)
 {
   printf("Harrier: Incorrect number of facets\n");
   exit(1);
 }

 /* Define control surface rotation axis */
 /* 
 object[id].ctrl_surface[0].axis =
   vminus(*(object[id].vertex+67),*(object[id].vertex+72));
 */


 for (j=0; j<object[id].nctrl_srf; j++){
  float norm;
  cartvektor tmp, tmp2;

  /* Generate orthonormal-system */
  norm=sqrt(VPRIK(object[id].ctrl_surface[j].axis,
                  object[id].ctrl_surface[j].axis));
  object[id].ctrl_surface[j].front=
                  svmult(1./norm,object[id].ctrl_surface[j].axis);
  /* Rotate 90 deg about z */
  tmp.x = -object[id].ctrl_surface[j].front.y;
  tmp.y =  object[id].ctrl_surface[j].front.x;
  tmp.z =  object[id].ctrl_surface[j].front.z;

  /* Rotate 90 deg about x - then the vector is not parallel with front vector */
  tmp2.x =  tmp.x;
  tmp2.y = -tmp.z;
  tmp2.z =  tmp.y;

  object[id].ctrl_surface[j].left =
   vkryds(object[id].ctrl_surface[j].front,tmp2);
  norm=sqrt(VPRIK(object[id].ctrl_surface[j].left,
                  object[id].ctrl_surface[j].left));
  object[id].ctrl_surface[j].left=
                  svmult(1./norm,object[id].ctrl_surface[j].left);

  object[id].ctrl_surface[j].top =
   vkryds(object[id].ctrl_surface[j].front,object[id].ctrl_surface[j].left);
 }

 // Custom colour definition:
 // Be carefull of side-effects!
 object[id].colarr[WHITE].r = 255;
 object[id].colarr[WHITE].g = 255;
 object[id].colarr[WHITE].b = 255;

 object[id].colarr[LIGHTGRAY].r = 192;
 object[id].colarr[LIGHTGRAY].g = 192;
 object[id].colarr[LIGHTGRAY].b = 192;

 object[id].colarr[DARKGRAY].r =  57;//63//30//78
 object[id].colarr[DARKGRAY].g =  48;//64//57//60
 object[id].colarr[DARKGRAY].b =  51;//69//64//72

 object[id].colarr[RED].r = 211;
 object[id].colarr[RED].g =  104;
 object[id].colarr[RED].b =  40;

 object[id].colarr[GREEN].r =  32;
 object[id].colarr[GREEN].g = 255;
 object[id].colarr[GREEN].b =  32;

 object[id].colarr[BLUE].r =  232;//32//250//255//253//255//255//233
 object[id].colarr[BLUE].g =  209;//32//240//189//203//221//202//223
 object[id].colarr[BLUE].b =  11;//255//100//84//92//65//86//46

 object[id].colarr[LIGHTRED].r = 182;//182//168//197//151//156//148//182
 object[id].colarr[LIGHTRED].g =  0;//73//31//68//8     //15//14   //0
 object[id].colarr[LIGHTRED].b =  0;//1//13//29//0       //6//0    //0

 object[id].colarr[LIGHTBLUE].r = 96;//96
 object[id].colarr[LIGHTBLUE].g = 96;//96
 object[id].colarr[LIGHTBLUE].b = 255;//255

 object[id].colarr[CYAN].r = 80;
 object[id].colarr[CYAN].g = 110;
 object[id].colarr[CYAN].b = 125;

 object[id].colarr[LIGHTCYAN].r = 251;//249//239//236//192//249 //253//251
 object[id].colarr[LIGHTCYAN].g = 174;//166//197//171//139//166 //165//174
 object[id].colarr[LIGHTCYAN].b = 8;//40//85//25//47//40       //42  //8

 object[id].colarr[DARKGREEN].r = 139;//118//218//253//128
 object[id].colarr[DARKGREEN].g = 140;//127//193//202//142
 object[id].colarr[DARKGREEN].b = 136;//126//90//74//142

 nobjects++;
