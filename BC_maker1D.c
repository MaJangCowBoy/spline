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
  double _Val_x[_NPOINT], _Val_y[_NPOINT], _Val_z[_NPOINT];
  FILE *fp;
	
  fp = fopen("nothing.txt","r");

  fscanf(fp,"%d",&NL);
	
  double coeff[NL];
  
  for(i=0;i<NL;i++) {
    fscanf(fp,"%lf",&coeff[i]);  
  }
	
  fclose(fp);
	
  for(i=0;i<_NPOINT;i++) {
    _Val_x[i] = _INTV * i;
    _Val_y[i] = 0.0;
    _Val_z[i] = 0.0;
    for(j=0;j<NL;j++) {
      _Val_y[i] += cos(M_PI*j*_Val_x[i]);
      _Val_z[i] += -M_PI*j*sin(M_PI*j*_Val_x[i]);
    }
  }
  
  fp = fopen("something.txt","w"); 

  fprintf(fp,"%d\n",(_NPOINT-1));
  fprintf(fp,"%lf\n",_INTV);
  
  for(i=0;i<(_NPOINT-1);i++) {
    fprintf(fp,"%lf\t",_Val_y[i]);
    fprintf(fp,"%lf\t",_Val_y[i+1]);
    fprintf(fp,"%lf\t",_Val_z[i]);
    fprintf(fp,"%lf\n",_Val_z[i+1]);
  }
	 
  fclose(fp);
    
  return 0;
}
