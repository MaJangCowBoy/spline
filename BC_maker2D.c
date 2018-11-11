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
  double _Val_x[_NPOINT], _Val_y[_NPOINT];
  double _Val_f[_NPOINT][_NPOINT];
  double _Val_fx[_NPOINT][_NPOINT], _Val_fy[_NPOINT][_NPOINT];
  double _Val_fxy[_NPOINT][_NPOINT];
  FILE *fp;
	
  fp = fopen("nothing.txt","r");

  fscanf(fp,"%d",&NL);
	
  double coeff[NL*NL];
  
  for(N=0;N<(NL*NL);N++) {
    fscanf(fp,"%lf",&coeff[N]);  
  }
	
  fclose(fp);
	
  for(i=0;i<_NPOINT;i++) 
    for(j=0;j<_NPOINT;j++) {
	    
      _Val_x[i] = _INTVX * i;
      _Val_y[j] = _INTVY * j;
      
      _Val_f[i][j] = 0.0; _Val_fx[i][j] = 0.0;
      _Val_fy[i][j] = 0.0; _Val_fxy[i][j] = 0.0;
	    
      NR = NL* NL;
      for(N=0;N<NR;N++) {
    
        a = N % NL;  b = N / NL;
        _Val_f[i][j] += coeff[N]*cos(a*M_PI*_Val_x[i])*cos(b*M_PI*_Val_y[j]);
        _Val_fx[i][j] += -a*M_PI*coeff[N]*sin(a*M_PI*_Val_x[i])*cos(b*M_PI*_Val_y[j]);
        _Val_fy[i][j] += -b*M_PI*coeff[N]*cos(a*M_PI*_Val_x[i])*sin(b*M_PI*_Val_y[j]);
        _Val_fxy[i][j] += a*b*M_PI*M_PI*coeff[N]*sin(a*M_PI*_Val_x[i])*sin(b*M_PI*_Val_y[j]);
      }
    }
  
  fp = fopen("something.txt","w"); 

  fprintf(fp,"%d\n",(_NPOINT-1));
  fprintf(fp,"%lf\t%lf\n",_INTVX,_INTVY);
  
  for(i=0;i<(_NPOINT-1);i++) 
    for(j=0;j<(_NPOINT-1);j++) {
      fprintf(fp,"%lf\t",_Val_f[i][j]);
      fprintf(fp,"%lf\t",_Val_f[i+1][j]);
      fprintf(fp,"%lf\t",_Val_f[i][j+1]);
      fprintf(fp,"%lf\t",_Val_f[i+1][j+1]);
      fprintf(fp,"%lf\t",_Val_fx[i][j]);
      fprintf(fp,"%lf\t",_Val_fx[i+1][j]);
      fprintf(fp,"%lf\t",_Val_fx[i][j+1]);
      fprintf(fp,"%lf\t",_Val_fx[i+1][j+1]);
      fprintf(fp,"%lf\t",_Val_fy[i][j]);
      fprintf(fp,"%lf\t",_Val_fy[i+1][j]);
      fprintf(fp,"%lf\t",_Val_fy[i][j+1]);
      fprintf(fp,"%lf\t",_Val_fy[i+1][j+1]);
      fprintf(fp,"%lf\t",_Val_fxy[i][j]);
      fprintf(fp,"%lf\t",_Val_fxy[i+1][j]);
      fprintf(fp,"%lf\t",_Val_fxy[i][j+1]);
      fprintf(fp,"%lf\n",_Val_fxy[i+1][j+1]);
    }
	 
  fclose(fp);
    
  return 0;
}
