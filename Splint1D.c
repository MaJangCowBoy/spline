#include <stdio.h>
#include "spline.h"
#include <stdlib.h>
#include <math.h>

int main() {
  
  int i,j,k;
  int a,b,c;
  int N,M;
  int _NL;
  double _delX;
  double _Val_x,_Val_y,_Val_z;
  double _tmp_BC[4];         /* Boundary condition */
  FILE *fp;
  
  fp = fopen("something.txt","r");

  fscanf(fp,"%d",&_NL);
  fscanf(fp,"%lf",&_delX);
  
  double _Coeff_a[4][_NL];    /* Coefficient vector */  
  
  for(N=0;N<_NL;N++) {

    for(j=0;j<2;j++) {
      fscanf(fp,"%lf",&_tmp_BC[j]);
    }
    for(j=2;j<4;j++) {
      fscanf(fp,"%lf",&_tmp_BC[j]);
      _tmp_BC[j] *= _delX;
    }
    
    for(i=0;i<4;i++) {
      _Coeff_a[i][N] = 0.0;
    }
    
    for(i=0;i<4;i++) 
      for(j=0;j<4;j++) {
        _Coeff_a[i][N] += _C1[i][j]*_tmp_BC[j];
      }
  }
  
  fclose(fp);
  
  fp = fopen("something_else.txt","w");
  
  fprintf(fp,"%d\n",_NL);
  fprintf(fp,"%lf\n",_delX);
  
  for(N=0;N<_NL;N++) {
    fprintf(fp,"%lf\t",_Coeff_a[0][N]);
    fprintf(fp,"%lf\t",_Coeff_a[1][N]);
    fprintf(fp,"%lf\t",_Coeff_a[2][N]);
    fprintf(fp,"%lf\n",_Coeff_a[3][N]);
  }
  
  fclose(fp);
  
  return 0;
}
