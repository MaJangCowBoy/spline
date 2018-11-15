#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#ifndef _INTV
#define _INTV 0.1
#endif

#ifndef _NPOINT
#define _NPOINT 11
#endif

int main() {

  int i,j,k;
  int NL;
  double _ValX[_NPOINT], _ValF[_NPOINT], _ValFx[_NPOINT], _ValFxx[_NPOINT];
  FILE *fp;
	
  fp = fopen("nothing.txt","r");

  fscanf(fp,"%d",&NL);
	
  double coeff[NL];
  
  for(i=0;i<NL;i++) {
    fscanf(fp,"%lf",&coeff[i]);  
  }
  fclose(fp);
	
  for(i=0;i<_NPOINT;i++) {
    _ValX[i] = _INTV * i;
    _ValF[i] = 0.0;
    _ValFx[i] = 0.0;
    _ValFxx[i] = 0.0;
    for(j=0;j<NL;j++) {
      _ValF[i] += coeff[j]*sin(M_PI*j*_Val_x[i]);
      _ValFx[i] += coeff[j]*M_PI*j*cos(M_PI*j*_Val_x[i]);
      _ValFxx[i] += -coeff[j]*M_PI*j*M_PI*j*sin(M_PI*j*_Val_x[i]);
    }
  }
  
  fp = fopen("something.txt","w"); 

  fprintf(fp,"%d\n",(_NPOINT-1));
  fprintf(fp,"%lf\n",_INTV);
	
  for(i=0;i<(_NPOINT-1);i++) {
    fprintf(fp,"%lf\t",_ValF[i]);
    fprintf(fp,"%lf\t",_ValF[i+1]);
    fprintf(fp,"%lf\t",_ValFx[i]);
    fprintf(fp,"%lf\n",_ValFx[i+1]);
  }
  fclose(fp);

  fp = fopen("something2.txt","w");

  fprintf(fp,"%d\n",(_NPOINT-1));
  fprintf(fp,"%lf\n",_INTV);

  for(i=0;i<(_NPOINT-1);i++) {
    fprintf(fp,"%lf\t",_ValFx[i]);
    fprintf(fp,"%lf\t",_ValFx[i+1]);
    fprintf(fp,"%lf\t",_ValFxx[i]);
    fprintf(fp,"%lf\n",_ValFxx[i+1]);
  }
  fclose(fp);

  return 0;
}
