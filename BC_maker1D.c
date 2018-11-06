#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#ifndef _INTV
#define _INTV 0.1
#endif

int main() {

  int i,j,k;
  int NL;
  double _Val_x[11], _Val_y[11], _Val_z[11];
  FILE *fp;
	
  fp = fopen("nothing.txt","r");

  fscanf(fp,"%d",&NL);
	
  double coeff[NL];
  
  for(i=0;i<NL;i++) {
    fscanf(fp,"%lf",&coeff[i]);  
  }
	
  for(i=0;i<11;i++) {
    _Val_x[i] = _INTV * i;
    _Val_y[i] = 0.0;
    _Val_z[i] = 0.0;
    for(j=0;j<NL;j++) {
      _Val_y[i] += cos(M_PI*j*_Val_x[i]);
      _Val_z[i] += -sin*M_PI*j*sin(M_PI*j*_Val_x[i]);
    }
  }
  
  fp = fopen("something.txt","w"); 

  fprintf(fp,"%lf\n",_INTV);
  
  for(i=0;i<10;i++) {
    fprintf(fp,"%lf\t",_Val_y[i]);
    fprintf(fp,"%lf\t",_Val_y[i+1]);
    fprintf(fp,"%lf\t",_Val_z[i]);
    fprintf(fp,"%lf\n",_Val_z[i+1]);
  }
	 
  fclose(fp);
    
  return 0;
}
