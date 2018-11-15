#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#ifndef _INTVX
#define _INTVX 0.1
#endif

#ifndef _INTVY
#define _INTVY 0.1
#endif

#ifndef _INTVZ
#define _INTVZ 0.1
#endif

#ifndef _NPOINT
#define _NPOINT 11
#endif

int main() {

  int i,j,k;
  int N,M,L;
  int a,b,c;
  int NL,NR;
  double _ValX, _ValY, _ValZ;
  double _ValF[_NPOINT][_NPOINT][_NPOINT];
  double _ValFx[_NPOINT][_NPOINT][_NPOINT], _ValFy[_NPOINT][_NPOINT][_NPOINT], _ValFz[_NPOINT][_NPOINT][_NPOINT];
  double _ValFxy[_NPOINT][_NPOINT][_NPOINT], _ValFxz[_NPOINT][_NPOINT][_NPOINT], _ValFyz[_NPOINT][_NPOINT][_NPOINT];
  double _ValFxyz[_NPOINT][_NPOINT][_NPOINT];

  double _ValFx[_NPOINT][_NPOINT][_NPOINT];
  double _ValFxx[_NPOINT][_NPOINT][_NPOINT], _ValFxy[_NPOINT][_NPOINT][_NPOINT], _ValFxz[_NPOINT][_NPOINT][_NPOINT];
  double _ValFxxy[_NPOINT][_NPOINT][_NPOINT], _ValFxxz[_NPOINT][_NPOINT][_NPOINT], _ValFxyz[_NPOINT][_NPOINT][_NPOINT];
  double _ValFxxyz[_NPOINT][_NPOINT][_NPOINT];

  double _ValFy[_NPOINT][_NPOINT][_NPOINT];
  double _ValFyx[_NPOINT][_NPOINT][_NPOINT], _ValFyy[_NPOINT][_NPOINT][_NPOINT], _ValFyz[_NPOINT][_NPOINT][_NPOINT];
  double _ValFyxy[_NPOINT][_NPOINT][_NPOINT], _ValFyxz[_NPOINT][_NPOINT][_NPOINT], _ValFyyz[_NPOINT][_NPOINT][_NPOINT];
  double _ValFyxyz[_NPOINT][_NPOINT][_NPOINT];
  
  double _ValFz[_NPOINT][_NPOINT][_NPOINT];
  double _ValFzx[_NPOINT][_NPOINT][_NPOINT], _ValFzy[_NPOINT][_NPOINT][_NPOINT], _ValFzz[_NPOINT][_NPOINT][_NPOINT];
  double _ValFzxy[_NPOINT][_NPOINT][_NPOINT], _ValFzxz[_NPOINT][_NPOINT][_NPOINT], _ValFzyz[_NPOINT][_NPOINT][_NPOINT];
  double _ValFzxyz[_NPOINT][_NPOINT][_NPOINT];
  
  FILE *fp;
	
  fp = fopen("nothing.txt","r");

  fscanf(fp,"%d",&NL);
	
  NR = NL * NL * NL;
	
  double coeff[NR];
  
  for(N=0;N<NR;N++) {
    fscanf(fp,"%lf",&coeff[N]);  
  }
	
  fclose(fp);

  for(i=0;i<_NPOINT;i++) 
    for(j=0;j<_NPOINT;j++) 
      for(k=0;k<_NPOINT;k++) {
	    
        _ValX = _INTVX * i;
        _ValY = _INTVY * j;
        _ValZ = _INTVZ * k;
        
        _ValF[i][j][k] = 0.0; 
        _ValFx[i][j][k] = 0.0; _ValFy[i][j][k] = 0.0; _ValFz[i][j][k] = 0.0;
        _ValFxy[i][j][k] = 0.0; _ValFxz[i][j][k] = 0.0; _ValFyz[i][j][k] = 0.0;
        _ValFxyz[i][j][k] = 0.0;
/*        
        _ValFx[i][j][k] = 0.0;
        _ValFxx[i][j][k] = 0.0; _ValFxy[i][j][k] = 0.0; _ValFxz[i][j][k] = 0.0;
        _ValFxxy[i][j][k] = 0.0; _ValFxxz[i][j][k] = 0.0; _ValFxyz[i][j][k] = 0.0;
        _ValFxxyz[i][j][k] = 0.0;
        
        _ValFy[i][j][k] = 0.0;
        _ValFyx[i][j][k] = 0.0; _ValFyy[i][j][k] = 0.0; _ValFyz[i][j][k] = 0.0;
        _ValFyxy[i][j][k] = 0.0; _ValFyxz[i][j][k] = 0.0; _ValFyyz[i][j][k] = 0.0;
        _ValFyxyz[i][j][k] = 0.0;
        
        _ValFz[i][j][k] = 0.0;
        _ValFzx[i][j][k] = 0.0; _ValFzy[i][j][k] = 0.0; _ValFzz[i][j][k] = 0.0;
        _ValFzxy[i][j][k] = 0.0; _ValFzxz[i][j][k] = 0.0; _ValFzyz[i][j][k] = 0.0;
        _ValFzxyz[i][j][k] = 0.0;
*/	    
        for(N=0;N<NR;N++) {
		
             a = (N % NL) + 1;
             b = N % (NL*NL);  b = (b / NL) + 1; 
             c = (N / (NL*NL)) + 1;
		
              _ValF[i][j][k] += coeff[N]
                              * sin(a*M_PI*_ValX)
                              * sin(b*M_PI*_ValY)
                              * sin(c*M_PI*_ValZ);                              
              _ValFx[i][j][k] += coeff[n]
                              * a * M_PI
                              * cos(a*M_PI*_ValX)
                              * sin(b*M_PI*_ValY)
                              * sin(c*M_PI*_ValZ);
              _ValFy[i][j][k] += coeff[n]
                              * b * M_PI
                              * sin(a*M_PI*_ValX)
                              * cos(b*M_PI*_ValY)
                              * sin(c*M_PI*_ValZ);
              _ValFz[i][j][k] += coeff[n]
                              * c * M_PI
                              * sin(a*M_PI*_ValX)
                              * sin(b*M_PI*_ValY)
                              * cos(c*M_PI*_ValZ);
              _ValFxy[i][j][k] += coeff[n]
                              * a * b * M_PI * M_PI
                              * cos(a*M_PI*_ValX)
                              * cos(b*M_PI*_ValY)
                              * sin(c*M_PI*_ValZ);
              _ValFxz[i][j][k] += coeff[n]
                              * a * c * M_PI * M_PI
                              * cos(a*M_PI*_ValX)
                              * sin(b*M_PI*_ValY)
                              * cos(c*M_PI*_ValZ);
              _ValFyz[i][j][k] += coeff[n]
                              * b * c * M_PI * M_PI
                              * sin(a*M_PI*_ValX)
                              * cos(b*M_PI*_ValY)
                              * cos(c*M_PI*_ValZ);
              _ValFxyz[i][j][k] += coeff[n]
                              * a * b * c * M_PI * M_PI * M_PI
                              * cos(a*M_PI*_ValX)
                              * cos(b*M_PI*_ValY)
                              * cos(c*M_PI*_ValZ);
		
		
        }
      }
  
  fp = fopen("something.txt","w"); 

  fprintf(fp,"%d\n",(_NPOINT-1));
  fprintf(fp,"%lf\t%lf\t%lf\n",_INTVX,_INTVY,_INTVZ);
  
  for(i=0;i<(_NPOINT-1);i++) 
    for(j=0;j<(_NPOINT-1);j++) 
      for(k=0;k<(_NPOINT-1);k++) {
        fprintf(fp,"%lf\t",_ValF[i][j][k]);  fprintf(fp,"%lf\t",_ValF[i+1][j][k]);
        fprintf(fp,"%lf\t",_ValF[i][j+1][k]);  fprintf(fp,"%lf\t",_ValF[i+1][j+1][k]);
        fprintf(fp,"%lf\t",_ValF[i][j][k+1]);  fprintf(fp,"%lf\t",_ValF[i+1][j][k+1]);
        fprintf(fp,"%lf\t",_ValF[i][j+1][k+1]);  fprintf(fp,"%lf\t",_ValF[i+1][j+1][k+1]);
      
        fprintf(fp,"%lf\t",_ValFx[i][j][k]);  fprintf(fp,"%lf\t",_ValFx[i+1][j][k]);
        fprintf(fp,"%lf\t",_ValFx[i][j+1][k]);  fprintf(fp,"%lf\t",_ValFx[i+1][j+1][k]);
        fprintf(fp,"%lf\t",_ValFx[i][j][k+1]);  fprintf(fp,"%lf\t",_ValFx[i+1][j][k+1]);
        fprintf(fp,"%lf\t",_ValFx[i][j+1][k+1]);  fprintf(fp,"%lf\t",_ValFx[i+1][j+1][k+1]);
        
        fprintf(fp,"%lf\t",_ValFy[i][j][k]);  fprintf(fp,"%lf\t",_ValFy[i+1][j][k]);
        fprintf(fp,"%lf\t",_ValFy[i][j+1][k]);  fprintf(fp,"%lf\t",_ValFy[i+1][j+1][k]);
        fprintf(fp,"%lf\t",_ValFy[i][j][k+1]);  fprintf(fp,"%lf\t",_ValFy[i+1][j][k+1]);
        fprintf(fp,"%lf\t",_ValFy[i][j+1][k+1]);  fprintf(fp,"%lf\t",_ValFy[i+1][j+1][k+1]);

        fprintf(fp,"%lf\t",_ValFz[i][j][k]);  fprintf(fp,"%lf\t",_ValFz[i+1][j][k]);
        fprintf(fp,"%lf\t",_ValFz[i][j+1][k]);  fprintf(fp,"%lf\t",_ValFz[i+1][j+1][k]);
        fprintf(fp,"%lf\t",_ValFz[i][j][k+1]);  fprintf(fp,"%lf\t",_ValFz[i+1][j][k+1]);
        fprintf(fp,"%lf\t",_ValFz[i][j+1][k+1]);  fprintf(fp,"%lf\t",_ValFz[i+1][j+1][k+1]);
        
        fprintf(fp,"%lf\t",_ValFxy[i][j][k]);  fprintf(fp,"%lf\t",_ValFxy[i+1][j][k]);
        fprintf(fp,"%lf\t",_ValFxy[i][j+1][k]);  fprintf(fp,"%lf\t",_ValFxy[i+1][j+1][k]);
        fprintf(fp,"%lf\t",_ValFxy[i][j][k+1]);  fprintf(fp,"%lf\t",_ValFxy[i+1][j][k+1]);
        fprintf(fp,"%lf\t",_ValFxy[i][j+1][k+1]);  fprintf(fp,"%lf\t",_ValFxy[i+1][j+1][k+1]);
        
        fprintf(fp,"%lf\t",_ValFxz[i][j][k]);  fprintf(fp,"%lf\t",_ValFxz[i+1][j][k]);
        fprintf(fp,"%lf\t",_ValFxz[i][j+1][k]);  fprintf(fp,"%lf\t",_ValFxz[i+1][j+1][k]);
        fprintf(fp,"%lf\t",_ValFxz[i][j][k+1]);  fprintf(fp,"%lf\t",_ValFxz[i+1][j][k+1]);
        fprintf(fp,"%lf\t",_ValFxz[i][j+1][k+1]);  fprintf(fp,"%lf\t",_ValFxz[i+1][j+1][k+1]);        

        fprintf(fp,"%lf\t",_ValFyz[i][j][k]);  fprintf(fp,"%lf\t",_ValFyz[i+1][j][k]);
        fprintf(fp,"%lf\t",_ValFyz[i][j+1][k]);  fprintf(fp,"%lf\t",_ValFyz[i+1][j+1][k]);
        fprintf(fp,"%lf\t",_ValFyz[i][j][k+1]);  fprintf(fp,"%lf\t",_ValFyz[i+1][j][k+1]);
        fprintf(fp,"%lf\t",_ValFyz[i][j+1][k+1]);  fprintf(fp,"%lf\t",_ValFyz[i+1][j+1][k+1]);
        
        fprintf(fp,"%lf\t",_ValFxyz[i][j][k]);  fprintf(fp,"%lf\t",_ValFxyz[i+1][j][k]);
        fprintf(fp,"%lf\t",_ValFxyz[i][j+1][k]);  fprintf(fp,"%lf\t",_ValFxyz[i+1][j+1][k]);
        fprintf(fp,"%lf\t",_ValFxyz[i][j][k+1]);  fprintf(fp,"%lf\t",_ValFxyz[i+1][j][k+1]);
        fprintf(fp,"%lf\t",_ValFxyz[i][j+1][k+1]);  fprintf(fp,"%lf\n",_ValFxyz[i+1][j+1][k+1]);        
      }
	 
  fclose(fp);
/*  
  fp = fopen("somethingX.txt","w"); 

  fprintf(fp,"%d\n",(_NPOINT-1));
  fprintf(fp,"%lf\t%lf\t%lf\n",_INTVX,_INTVY,_INTVZ);
  
  for(i=0;i<(_NPOINT-1);i++) 
    for(j=0;j<(_NPOINT-1);j++) 
      for(k=0;k<(_NPOINT-1);k++) {
        fprintf(fp,"%lf\t",_ValF[i][j][k]);  fprintf(fp,"%lf\t",_ValF[i+1][j][k]);
        fprintf(fp,"%lf\t",_ValF[i][j+1][k]);  fprintf(fp,"%lf\t",_ValF[i+1][j+1][k]);
        fprintf(fp,"%lf\t",_ValF[i][j][k+1]);  fprintf(fp,"%lf\t",_ValF[i+1][j][k+1]);
        fprintf(fp,"%lf\t",_ValF[i][j+1][k+1]);  fprintf(fp,"%lf\t",_ValF[i+1][j+1][k+1]);
      
        fprintf(fp,"%lf\t",_ValFx[i][j][k]);  fprintf(fp,"%lf\t",_ValFx[i+1][j][k]);
        fprintf(fp,"%lf\t",_ValFx[i][j+1][k]);  fprintf(fp,"%lf\t",_ValFx[i+1][j+1][k]);
        fprintf(fp,"%lf\t",_ValFx[i][j][k+1]);  fprintf(fp,"%lf\t",_ValFx[i+1][j][k+1]);
        fprintf(fp,"%lf\t",_ValFx[i][j+1][k+1]);  fprintf(fp,"%lf\t",_ValFx[i+1][j+1][k+1]);
        
        fprintf(fp,"%lf\t",_ValFy[i][j][k]);  fprintf(fp,"%lf\t",_ValFy[i+1][j][k]);
        fprintf(fp,"%lf\t",_ValFy[i][j+1][k]);  fprintf(fp,"%lf\t",_ValFy[i+1][j+1][k]);
        fprintf(fp,"%lf\t",_ValFy[i][j][k+1]);  fprintf(fp,"%lf\t",_ValFy[i+1][j][k+1]);
        fprintf(fp,"%lf\t",_ValFy[i][j+1][k+1]);  fprintf(fp,"%lf\t",_ValFy[i+1][j+1][k+1]);

        fprintf(fp,"%lf\t",_ValFz[i][j][k]);  fprintf(fp,"%lf\t",_ValFz[i+1][j][k]);
        fprintf(fp,"%lf\t",_ValFz[i][j+1][k]);  fprintf(fp,"%lf\t",_ValFz[i+1][j+1][k]);
        fprintf(fp,"%lf\t",_ValFz[i][j][k+1]);  fprintf(fp,"%lf\t",_ValFz[i+1][j][k+1]);
        fprintf(fp,"%lf\t",_ValFz[i][j+1][k+1]);  fprintf(fp,"%lf\t",_ValFz[i+1][j+1][k+1]);
        
        fprintf(fp,"%lf\t",_ValFxy[i][j][k]);  fprintf(fp,"%lf\t",_ValFxy[i+1][j][k]);
        fprintf(fp,"%lf\t",_ValFxy[i][j+1][k]);  fprintf(fp,"%lf\t",_ValFxy[i+1][j+1][k]);
        fprintf(fp,"%lf\t",_ValFxy[i][j][k+1]);  fprintf(fp,"%lf\t",_ValFxy[i+1][j][k+1]);
        fprintf(fp,"%lf\t",_ValFxy[i][j+1][k+1]);  fprintf(fp,"%lf\t",_ValFxy[i+1][j+1][k+1]);
        
        fprintf(fp,"%lf\t",_ValFxz[i][j][k]);  fprintf(fp,"%lf\t",_ValFxz[i+1][j][k]);
        fprintf(fp,"%lf\t",_ValFxz[i][j+1][k]);  fprintf(fp,"%lf\t",_ValFxz[i+1][j+1][k]);
        fprintf(fp,"%lf\t",_ValFxz[i][j][k+1]);  fprintf(fp,"%lf\t",_ValFxz[i+1][j][k+1]);
        fprintf(fp,"%lf\t",_ValFxz[i][j+1][k+1]);  fprintf(fp,"%lf\t",_ValFxz[i+1][j+1][k+1]);        

        fprintf(fp,"%lf\t",_ValFyz[i][j][k]);  fprintf(fp,"%lf\t",_ValFyz[i+1][j][k]);
        fprintf(fp,"%lf\t",_ValFyz[i][j+1][k]);  fprintf(fp,"%lf\t",_ValFyz[i+1][j+1][k]);
        fprintf(fp,"%lf\t",_ValFyz[i][j][k+1]);  fprintf(fp,"%lf\t",_ValFyz[i+1][j][k+1]);
        fprintf(fp,"%lf\t",_ValFyz[i][j+1][k+1]);  fprintf(fp,"%lf\t",_ValFyz[i+1][j+1][k+1]);
        
        fprintf(fp,"%lf\t",_ValFxyz[i][j][k]);  fprintf(fp,"%lf\t",_ValFxyz[i+1][j][k]);
        fprintf(fp,"%lf\t",_ValFxyz[i][j+1][k]);  fprintf(fp,"%lf\t",_ValFxyz[i+1][j+1][k]);
        fprintf(fp,"%lf\t",_ValFxyz[i][j][k+1]);  fprintf(fp,"%lf\t",_ValFxyz[i+1][j][k+1]);
        fprintf(fp,"%lf\t",_ValFxyz[i][j+1][k+1]);  fprintf(fp,"%lf\n",_ValFxyz[i+1][j+1][k+1]);        
      }
	 
  fclose(fp);
  
  fp = fopen("somethingY.txt","w"); 

  fprintf(fp,"%d\n",(_NPOINT-1));
  fprintf(fp,"%lf\t%lf\t%lf\n",_INTVX,_INTVY,_INTVZ);
  
  for(i=0;i<(_NPOINT-1);i++) 
    for(j=0;j<(_NPOINT-1);j++) 
      for(k=0;k<(_NPOINT-1);k++) {
        fprintf(fp,"%lf\t",_ValF[i][j][k]);  fprintf(fp,"%lf\t",_ValF[i+1][j][k]);
        fprintf(fp,"%lf\t",_ValF[i][j+1][k]);  fprintf(fp,"%lf\t",_ValF[i+1][j+1][k]);
        fprintf(fp,"%lf\t",_ValF[i][j][k+1]);  fprintf(fp,"%lf\t",_ValF[i+1][j][k+1]);
        fprintf(fp,"%lf\t",_ValF[i][j+1][k+1]);  fprintf(fp,"%lf\t",_ValF[i+1][j+1][k+1]);
      
        fprintf(fp,"%lf\t",_ValFx[i][j][k]);  fprintf(fp,"%lf\t",_ValFx[i+1][j][k]);
        fprintf(fp,"%lf\t",_ValFx[i][j+1][k]);  fprintf(fp,"%lf\t",_ValFx[i+1][j+1][k]);
        fprintf(fp,"%lf\t",_ValFx[i][j][k+1]);  fprintf(fp,"%lf\t",_ValFx[i+1][j][k+1]);
        fprintf(fp,"%lf\t",_ValFx[i][j+1][k+1]);  fprintf(fp,"%lf\t",_ValFx[i+1][j+1][k+1]);
        
        fprintf(fp,"%lf\t",_ValFy[i][j][k]);  fprintf(fp,"%lf\t",_ValFy[i+1][j][k]);
        fprintf(fp,"%lf\t",_ValFy[i][j+1][k]);  fprintf(fp,"%lf\t",_ValFy[i+1][j+1][k]);
        fprintf(fp,"%lf\t",_ValFy[i][j][k+1]);  fprintf(fp,"%lf\t",_ValFy[i+1][j][k+1]);
        fprintf(fp,"%lf\t",_ValFy[i][j+1][k+1]);  fprintf(fp,"%lf\t",_ValFy[i+1][j+1][k+1]);

        fprintf(fp,"%lf\t",_ValFz[i][j][k]);  fprintf(fp,"%lf\t",_ValFz[i+1][j][k]);
        fprintf(fp,"%lf\t",_ValFz[i][j+1][k]);  fprintf(fp,"%lf\t",_ValFz[i+1][j+1][k]);
        fprintf(fp,"%lf\t",_ValFz[i][j][k+1]);  fprintf(fp,"%lf\t",_ValFz[i+1][j][k+1]);
        fprintf(fp,"%lf\t",_ValFz[i][j+1][k+1]);  fprintf(fp,"%lf\t",_ValFz[i+1][j+1][k+1]);
        
        fprintf(fp,"%lf\t",_ValFxy[i][j][k]);  fprintf(fp,"%lf\t",_ValFxy[i+1][j][k]);
        fprintf(fp,"%lf\t",_ValFxy[i][j+1][k]);  fprintf(fp,"%lf\t",_ValFxy[i+1][j+1][k]);
        fprintf(fp,"%lf\t",_ValFxy[i][j][k+1]);  fprintf(fp,"%lf\t",_ValFxy[i+1][j][k+1]);
        fprintf(fp,"%lf\t",_ValFxy[i][j+1][k+1]);  fprintf(fp,"%lf\t",_ValFxy[i+1][j+1][k+1]);
        
        fprintf(fp,"%lf\t",_ValFxz[i][j][k]);  fprintf(fp,"%lf\t",_ValFxz[i+1][j][k]);
        fprintf(fp,"%lf\t",_ValFxz[i][j+1][k]);  fprintf(fp,"%lf\t",_ValFxz[i+1][j+1][k]);
        fprintf(fp,"%lf\t",_ValFxz[i][j][k+1]);  fprintf(fp,"%lf\t",_ValFxz[i+1][j][k+1]);
        fprintf(fp,"%lf\t",_ValFxz[i][j+1][k+1]);  fprintf(fp,"%lf\t",_ValFxz[i+1][j+1][k+1]);        

        fprintf(fp,"%lf\t",_ValFyz[i][j][k]);  fprintf(fp,"%lf\t",_ValFyz[i+1][j][k]);
        fprintf(fp,"%lf\t",_ValFyz[i][j+1][k]);  fprintf(fp,"%lf\t",_ValFyz[i+1][j+1][k]);
        fprintf(fp,"%lf\t",_ValFyz[i][j][k+1]);  fprintf(fp,"%lf\t",_ValFyz[i+1][j][k+1]);
        fprintf(fp,"%lf\t",_ValFyz[i][j+1][k+1]);  fprintf(fp,"%lf\t",_ValFyz[i+1][j+1][k+1]);
        
        fprintf(fp,"%lf\t",_ValFxyz[i][j][k]);  fprintf(fp,"%lf\t",_ValFxyz[i+1][j][k]);
        fprintf(fp,"%lf\t",_ValFxyz[i][j+1][k]);  fprintf(fp,"%lf\t",_ValFxyz[i+1][j+1][k]);
        fprintf(fp,"%lf\t",_ValFxyz[i][j][k+1]);  fprintf(fp,"%lf\t",_ValFxyz[i+1][j][k+1]);
        fprintf(fp,"%lf\t",_ValFxyz[i][j+1][k+1]);  fprintf(fp,"%lf\n",_ValFxyz[i+1][j+1][k+1]);        
      }
	 
  fclose(fp);

  fp = fopen("somethingZ.txt","w"); 

  fprintf(fp,"%d\n",(_NPOINT-1));
  fprintf(fp,"%lf\t%lf\t%lf\n",_INTVX,_INTVY,_INTVZ);
  
  for(i=0;i<(_NPOINT-1);i++) 
    for(j=0;j<(_NPOINT-1);j++) 
      for(k=0;k<(_NPOINT-1);k++) {
        fprintf(fp,"%lf\t",_ValF[i][j][k]);  fprintf(fp,"%lf\t",_ValF[i+1][j][k]);
        fprintf(fp,"%lf\t",_ValF[i][j+1][k]);  fprintf(fp,"%lf\t",_ValF[i+1][j+1][k]);
        fprintf(fp,"%lf\t",_ValF[i][j][k+1]);  fprintf(fp,"%lf\t",_ValF[i+1][j][k+1]);
        fprintf(fp,"%lf\t",_ValF[i][j+1][k+1]);  fprintf(fp,"%lf\t",_ValF[i+1][j+1][k+1]);
      
        fprintf(fp,"%lf\t",_ValFx[i][j][k]);  fprintf(fp,"%lf\t",_ValFx[i+1][j][k]);
        fprintf(fp,"%lf\t",_ValFx[i][j+1][k]);  fprintf(fp,"%lf\t",_ValFx[i+1][j+1][k]);
        fprintf(fp,"%lf\t",_ValFx[i][j][k+1]);  fprintf(fp,"%lf\t",_ValFx[i+1][j][k+1]);
        fprintf(fp,"%lf\t",_ValFx[i][j+1][k+1]);  fprintf(fp,"%lf\t",_ValFx[i+1][j+1][k+1]);
        
        fprintf(fp,"%lf\t",_ValFy[i][j][k]);  fprintf(fp,"%lf\t",_ValFy[i+1][j][k]);
        fprintf(fp,"%lf\t",_ValFy[i][j+1][k]);  fprintf(fp,"%lf\t",_ValFy[i+1][j+1][k]);
        fprintf(fp,"%lf\t",_ValFy[i][j][k+1]);  fprintf(fp,"%lf\t",_ValFy[i+1][j][k+1]);
        fprintf(fp,"%lf\t",_ValFy[i][j+1][k+1]);  fprintf(fp,"%lf\t",_ValFy[i+1][j+1][k+1]);

        fprintf(fp,"%lf\t",_ValFz[i][j][k]);  fprintf(fp,"%lf\t",_ValFz[i+1][j][k]);
        fprintf(fp,"%lf\t",_ValFz[i][j+1][k]);  fprintf(fp,"%lf\t",_ValFz[i+1][j+1][k]);
        fprintf(fp,"%lf\t",_ValFz[i][j][k+1]);  fprintf(fp,"%lf\t",_ValFz[i+1][j][k+1]);
        fprintf(fp,"%lf\t",_ValFz[i][j+1][k+1]);  fprintf(fp,"%lf\t",_ValFz[i+1][j+1][k+1]);
        
        fprintf(fp,"%lf\t",_ValFxy[i][j][k]);  fprintf(fp,"%lf\t",_ValFxy[i+1][j][k]);
        fprintf(fp,"%lf\t",_ValFxy[i][j+1][k]);  fprintf(fp,"%lf\t",_ValFxy[i+1][j+1][k]);
        fprintf(fp,"%lf\t",_ValFxy[i][j][k+1]);  fprintf(fp,"%lf\t",_ValFxy[i+1][j][k+1]);
        fprintf(fp,"%lf\t",_ValFxy[i][j+1][k+1]);  fprintf(fp,"%lf\t",_ValFxy[i+1][j+1][k+1]);
        
        fprintf(fp,"%lf\t",_ValFxz[i][j][k]);  fprintf(fp,"%lf\t",_ValFxz[i+1][j][k]);
        fprintf(fp,"%lf\t",_ValFxz[i][j+1][k]);  fprintf(fp,"%lf\t",_ValFxz[i+1][j+1][k]);
        fprintf(fp,"%lf\t",_ValFxz[i][j][k+1]);  fprintf(fp,"%lf\t",_ValFxz[i+1][j][k+1]);
        fprintf(fp,"%lf\t",_ValFxz[i][j+1][k+1]);  fprintf(fp,"%lf\t",_ValFxz[i+1][j+1][k+1]);        

        fprintf(fp,"%lf\t",_ValFyz[i][j][k]);  fprintf(fp,"%lf\t",_ValFyz[i+1][j][k]);
        fprintf(fp,"%lf\t",_ValFyz[i][j+1][k]);  fprintf(fp,"%lf\t",_ValFyz[i+1][j+1][k]);
        fprintf(fp,"%lf\t",_ValFyz[i][j][k+1]);  fprintf(fp,"%lf\t",_ValFyz[i+1][j][k+1]);
        fprintf(fp,"%lf\t",_ValFyz[i][j+1][k+1]);  fprintf(fp,"%lf\t",_ValFyz[i+1][j+1][k+1]);
        
        fprintf(fp,"%lf\t",_ValFxyz[i][j][k]);  fprintf(fp,"%lf\t",_ValFxyz[i+1][j][k]);
        fprintf(fp,"%lf\t",_ValFxyz[i][j+1][k]);  fprintf(fp,"%lf\t",_ValFxyz[i+1][j+1][k]);
        fprintf(fp,"%lf\t",_ValFxyz[i][j][k+1]);  fprintf(fp,"%lf\t",_ValFxyz[i+1][j][k+1]);
        fprintf(fp,"%lf\t",_ValFxyz[i][j+1][k+1]);  fprintf(fp,"%lf\n",_ValFxyz[i+1][j+1][k+1]);        
      }
	 
  fclose(fp);
*/
  return 0;
}
