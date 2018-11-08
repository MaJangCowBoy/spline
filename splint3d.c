#include <stdio.h>
#include "spline.h"
#include <stdlib.h>
#include <math.h>

int main() {
  
  int i,j,k;
  int a,b,c;
  int N,M;
  int _NL;
  double _delX,_delY,_delZ;
  double _Val_x,_Val_y,_Val_z;
  double _tmp_BC[16];         /* Boundary condition */
  FILE *fp;
  
  fp = fopen("something.txt","r");

  fscanf(fp,"%d",&_NL);
  fscanf(fp,"%lf",&_delX);
  fscanf(fp,"%lf",&_delY);
  fscanf(fp,"%lf",&_delZ);
  
  double _Coeff_a[64][_NL][_NL][_NL];    /* Coefficient vector */
/* From here */  
  for(N=0;N<_NL;N++) 
    for(M=0;M<_NL;M++) 
      for(L=0;L<_NL;L++) {
        
        for(i=0;i<8;i++) {
          fscanf(fp,"%lf",&_tmp_BC[i]); 
        }
        for(i=8;i<16;i++) {
          fscanf(fp,"%lf",&_tmp_BC[i]);
          _tmp_BC[i] *= _delX;
        }
        for(i=16;i<24;i++) {
          fscanf(fp,"%lf",&_tmp_BC[i]);
          _tmp_BC[i] *= _delY;
        }
        for(i=24;i<32;i++) {
          fscanf(fp,"%lf",&_tmp_BC[i]);
          _tmp_BC[i] *= _delZ;
        }
        for(i=32;i<40;i++) {
          fscanf(fp,"%lf",&_tmp_BC[i]);
          _tmp_BC[i] *= _delX*_delY;
        }
        for(i=40;i<48;i++) {
          fscanf(fp,"%lf",&_tmp_BC[i]);
          _tmp_BC[i] *= _delX*_delZ;
        }
        for(i=48;i<56;i++) {
          fscanf(fp,"%lf",&_tmp_BC[i]);
          _tmp_BC[i] *= _delY*_delZ;
        }
        for(i=56;i<64;i++) {
          fscanf(fp,"%lf",&_tmp_BC[i]);
          _tmp_BC[i] *= _delX*_delY*_delZ;
        }        
        
        for(i=0;i<64;i++) {
          _Coeff_a[i][N][M] = 0.0;
        }
        
        for(i=0;i<64;i++) 
          for(j=0;j<64;j++) {
            _Coeff_a[i][N][M][L] += _C3[i][j]*_tmp_BC[j];
          }
      }
  
  fclose(fp);
  
  fp = fopen("something_else.txt","w");
  
  for(N=0;N<_NL;N++) 
    for(M=0;M<_NL;M++)
      for(L=0;L<_NL;L++) {
        for(i=0;i<64;i++) {
          fprintf(fp,"%lf\t",_Coeff_a[i][N][M][L]);
        }
        fprintf(fp,"\n");
      }
  
  fclose(fp);
  
  return 0;
}
