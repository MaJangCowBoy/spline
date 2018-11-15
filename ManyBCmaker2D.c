#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#ifndef _INTVX
#define _INTVX 0.1
#endif

#ifndef _INTVY
#define _INTVY 0.1
#endif

#ifndef _NPOINT
#define _NPOINT 11
#endif

int main() {

  int i,j,k;
  int N,M;
  int a,b;
  int NL,NR;
  double _ValX, _ValY;
  double _ValF[_NPOINT][_NPOINT];
  double _ValFx[_NPOINT][_NPOINT], _ValFy[_NPOINT][_NPOINT];
  double _ValFxx[_NPOINT][_NPOINT],_ValFyy[_NPOINT][_NPOINT],_ValFxy[_NPOINT][_NPOINT];
  double _ValFxxy[_NPOINT][_NPOINT],_ValFyxy[_NPOINT][_NPOINT];
  FILE *fp;
	
  fp = fopen("nothing.txt","r");

  fscanf(fp,"%d",&NL);
	
  NR = NL * NL;
	
  double coeff[NR];
  
  for(N=0;N<NR;N++) {
    fscanf(fp,"%lf",&coeff[N]);  
  }
	
  fclose(fp);
	
  for(i=0;i<_NPOINT;i++) 
    for(j=0;j<_NPOINT;j++) {
	    
      _ValX = _INTVX * i;
      _ValY = _INTVY * j;
      
      _ValF[i][j] = 0.0; _ValFx[i][j] = 0.0;
      _ValFy[i][j] = 0.0; _ValFxy[i][j] = 0.0;
	    
      for(N=0;N<NR;N++) {
    
        a = (N % NL) + 1;  b = (N / NL) + 1;
        _ValF[i][j]    += coeff[N]*sin(a*M_PI*_ValX)*sin(b*M_PI*_ValY);
        _ValFx[i][j]   += a*M_PI*coeff[N]*cos(a*M_PI*_ValX)*sin(b*M_PI*_ValY);
        _ValFy[i][j]   += b*M_PI*coeff[N]*sin(a*M_PI*_ValX)*cos(b*M_PI*_ValY);
        _ValFxy[i][j]  += a*b*M_PI*M_PI*coeff[N]*cos(a*M_PI*_ValX)*cos(b*M_PI*_ValY);
        _ValFxx[i][j]  += -a*M_PI*a*M_PI*coeff[N]*sin(a*M_PI*_ValX)*sin(b*M_PI*_ValY);
        _ValFyy[i][j]  += -b*M_PI*b*M_PI*coeff[N]*sin(a*M_PI*_ValX)*sin(b*M_PI*_ValY);
        _ValFxxy[i][j] += -a*M_PI*a*M_PI*b*M_PI*coeff[N]*sin(a*M_PI*_ValX)*cos(b*M_PI*_ValY);
        _ValFyxy[i][j] += -a*M_PI*b*M_PI*b*M_PI*coeff[N]*cos(a*M_PI*_ValX)*sin(b*M_PI*_ValY);
      }
    }
  
  fp = fopen("something.txt","w"); 

  fprintf(fp,"%d\n",(_NPOINT-1));
  fprintf(fp,"%lf\t%lf\n",_INTVX,_INTVY);
  
  for(i=0;i<(_NPOINT-1);i++) 
    for(j=0;j<(_NPOINT-1);j++) {
      fprintf(fp,"%lf\t",_ValF[i][j]);
      fprintf(fp,"%lf\t",_ValF[i+1][j]);
      fprintf(fp,"%lf\t",_ValF[i][j+1]);
      fprintf(fp,"%lf\t",_ValF[i+1][j+1]);
      fprintf(fp,"%lf\t",_ValFx[i][j]);
      fprintf(fp,"%lf\t",_ValFx[i+1][j]);
      fprintf(fp,"%lf\t",_ValFx[i][j+1]);
      fprintf(fp,"%lf\t",_ValFx[i+1][j+1]);
      fprintf(fp,"%lf\t",_ValFy[i][j]);
      fprintf(fp,"%lf\t",_ValFy[i+1][j]);
      fprintf(fp,"%lf\t",_ValFy[i][j+1]);
      fprintf(fp,"%lf\t",_ValFy[i+1][j+1]);
      fprintf(fp,"%lf\t",_ValFxy[i][j]);
      fprintf(fp,"%lf\t",_ValFxy[i+1][j]);
      fprintf(fp,"%lf\t",_ValFxy[i][j+1]);
      fprintf(fp,"%lf\n",_ValFxy[i+1][j+1]);
    }
  fclose(fp);
	
  fp = fopen("somethingX.txt","w"); 

  fprintf(fp,"%d\n",(_NPOINT-1));
  fprintf(fp,"%lf\t%lf\n",_INTVX,_INTVY);
  
  for(i=0;i<(_NPOINT-1);i++) 
    for(j=0;j<(_NPOINT-1);j++) {
      fprintf(fp,"%lf\t",_ValFx[i][j]);
      fprintf(fp,"%lf\t",_ValFx[i+1][j]);
      fprintf(fp,"%lf\t",_ValFx[i][j+1]);
      fprintf(fp,"%lf\t",_ValFx[i+1][j+1]);
      fprintf(fp,"%lf\t",_ValFxx[i][j]);
      fprintf(fp,"%lf\t",_ValFxx[i+1][j]);
      fprintf(fp,"%lf\t",_ValFxx[i][j+1]);
      fprintf(fp,"%lf\t",_ValFxx[i+1][j+1]);
      fprintf(fp,"%lf\t",_ValFxy[i][j]);
      fprintf(fp,"%lf\t",_ValFxy[i+1][j]);
      fprintf(fp,"%lf\t",_ValFxy[i][j+1]);
      fprintf(fp,"%lf\t",_ValFxy[i+1][j+1]);
      fprintf(fp,"%lf\t",_ValFxxy[i][j]);
      fprintf(fp,"%lf\t",_ValFxxy[i+1][j]);
      fprintf(fp,"%lf\t",_ValFxxy[i][j+1]);
      fprintf(fp,"%lf\n",_ValFxxy[i+1][j+1]);
    }
  fclose(fp);
	

  fp = fopen("somethingY.txt","w"); 

  fprintf(fp,"%d\n",(_NPOINT-1));
  fprintf(fp,"%lf\t%lf\n",_INTVX,_INTVY);
  
  for(i=0;i<(_NPOINT-1);i++) 
    for(j=0;j<(_NPOINT-1);j++) {
      fprintf(fp,"%lf\t",_ValFy[i][j]);
      fprintf(fp,"%lf\t",_ValFy[i+1][j]);
      fprintf(fp,"%lf\t",_ValFy[i][j+1]);
      fprintf(fp,"%lf\t",_ValFy[i+1][j+1]);
      fprintf(fp,"%lf\t",_ValFxy[i][j]);
      fprintf(fp,"%lf\t",_ValFxy[i+1][j]);
      fprintf(fp,"%lf\t",_ValFxy[i][j+1]);
      fprintf(fp,"%lf\t",_ValFxy[i+1][j+1]);
      fprintf(fp,"%lf\t",_ValFyy[i][j]);
      fprintf(fp,"%lf\t",_ValFyy[i+1][j]);
      fprintf(fp,"%lf\t",_ValFyy[i][j+1]);
      fprintf(fp,"%lf\t",_ValFyy[i+1][j+1]);
      fprintf(fp,"%lf\t",_ValFyxy[i][j]);
      fprintf(fp,"%lf\t",_ValFyxy[i+1][j]);
      fprintf(fp,"%lf\t",_ValFyxy[i][j+1]);
      fprintf(fp,"%lf\n",_ValFyxy[i+1][j+1]);
    }
  fclose(fp);
    
  return 0;
}
