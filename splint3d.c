/*
 This code calculates the coefficients from boundary condition for each cell.
 */
#include <stdio.h>
#include "spline.h"
#include <stdlib.h>
#include <math.h>

#define _NL 2

int main() {
  
  int i,j,k;
  int a,b,c;
  int N,M,L;
  double _Val_x,_Val_y,_Val_z;
  double _Coeff_a[64][_NL][_NL][_NL];    
  /* Coefficient vector */
  double _tmp_BC[64];         
  /* Boundary condition */
  FILE *fp;
  
  fp = fopen("something.txt","r");

  for(N=0;N<_NL;N++) 
    for(M=0;M<_NL;M++)
      for(L=0;L<_NL;L++) {
     
        for(j=0;j<64;j++) {
          fscanf(fp,"%lf",&_tmp_BC[j]); 
        }
    
        for(i=0;i<64;i++) {
          _Coeff_a[i][n] = 0.0;
        }
    
        for(i=0;i<64;i++) 
          for(j=0;j<64;j++) {
            _Coeff_a[i][N][M][L] += _C3[i][j]*_tmp_BC[j];
          }
      }
  
  return 0;
}
