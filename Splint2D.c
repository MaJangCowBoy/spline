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
  FILE *fp,*fq;
  
  fp = fopen("something.txt","r");
  fq = fopen("something_else.txt","w");
  
  fscanf(fp,"%d",&_NL);
  fscanf(fp,"%lf",&_delX);
  fscanf(fp,"%lf",&_delY);
  
  fprintf(fq,"%d\n",_NL);
  fprintf(fq,"%lf\t%lf\n",_delX,_delY);
  
  double _Coeff_a[16];    /* Coefficient vector */
  
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
        _Coeff_a[i] = 0.0;
      }
    
      for(i=0;i<16;i++) 
        for(j=0;j<16;j++) {
          _Coeff_a[i] += _C2[i][j]*_tmp_BC[j];
        }
      
      for(i=0;i<16;i++) {
        fprintf(fq,"%lf\t",_Coeff_a[i]);
      }
      fprintf(fq,"\n");
    }
  
  fclose(fp);
  fclose(fq);
  
  return 0;
}
