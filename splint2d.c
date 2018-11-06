#include <stdio.h>
#include "spline.h"
#include <stdlib.h>
#include <math.h>

int main() {
  
  int i,j,k;
  int a,b,c;
  int N,M;
  int _NL;
  double _delX,_delY;
  double _Val_x,_Val_y,_Val_z;
  double _tmp_BC[16];         /* Boundary condition */
  FILE *fp;
  
  fp = fopen("something.txt","r");

  fscanf(fp,"%d",&_NL);
  fscanf(fp,"%lf",&_delX);
  fscanf(fp,"%lf",&_delY);
  
  double _Coeff_a[16][_NL][_NL];    /* Coefficient vector */
  
  for(N=0;N<_NL;N++) 
    for(M=0;M<_NL;M++) {
    
      for(i=0;i<4;i++) {
        fscanf(fp,"%lf",&_tmp_BC[i]); 
      }
      for(i=4;i<8;i++) {
        fscanf(fp,"%lf",&_tmp_BC[i]);
        _tmp_BC[i] *= _delX;
      }
      for(i=8;i<12;i++) {
        fscanf(fp,"%lf",&_tmp_BC[i]);
        _tmp_BC[i] *= _delY;
      }
      for(i=12;i<16;i++) {
        fscanf(fp,"%lf",&_tmp_BC[i]);
        _tmp_BC[i] *= _delX*_delY;
      }
    
      for(i=0;i<16;i++) {
        _Coeff_a[i][N][M] = 0.0;
      }
    
      for(i=0;i<16;i++) 
        for(j=0;j<16;j++) {
          _Coeff_a[i][N][M] += _C2[i][j]*_tmp_BC[j];
        }
    }
  
  fclose(fp);
  
  fp = fopen("something_else.txt","w");
  
  for(N=0;N<_NL;N++) 
    for(M=0;M<_NL;M++) {
      
      for(i=0;i<16;i++) {
        fprintf(fp,"%lf\t",_Coeff_a[i][N][M]);
      }
      fprintf(fp,"\n");
  }
  
  fclose(fp);
  
  return 0;
}
