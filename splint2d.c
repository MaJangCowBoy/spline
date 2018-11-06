#include <stdio.h>
#include "spline.h"
#include <stdlib.h>
#include <math.h>

#define _NL 10

int main() {
  
  int i,j,k;
  int a,b,c;
  int N,M;
  double _Val_x,_Val_y,_Val_z;
  double _Coeff_a[16][_NL][_NL];    /* Coefficient vector */
  double _tmp_BC[16];         /* Boundary condition */
  FILE *fp;
  
  fp = fopen("something.txt","r");

  for(N=0;N<_NL;N++) 
    for(M=0;M<_NL;M++) {

      for(j=0;j<16;j++) {
        fscanf(fp,"%lf",&_tmp_BC[j]); 
      }
    
      for(i=0;i<16;i++) {
        _Coeff_a[i][N][M] = 0.0;
      }
    
      for(i=0;i<16;i++) {
          _Coeff_a[i][N][M] += _C2[i][j]*_tmp_BC[j];
      }
    }
    
  fp = fopen("something_else.txt","w");
  
  for(N=0;N<_NL)
  
  return 0;
}
