#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main() {
  int i,j,k;
  int N,M,L;
  FILE *fp,*fq;
  int _NL;
  int Quot,Resd;
  double _delX,_delY;
  double coeff[16];
  double _tmpX,_tmpY,_tmpZ;

  fp = fopen("something_else.txt","r");
  fq = fopen("result.txt","w");
  
  fscanf(fp,"%d",&_NL);
  fscanf(fp,"%lf",&_delX);
  fscanf(fp,"%lf",&_delY);
  
  for(i=0;i<_NL;i++)
    for(j=0;j<_NL;j++) {
    
      for(k=0;k<16;k++) {
        fscanf(fp,"%lf",&coeff[k]);
      }
    
      for(N=0;N<10;N++) 
        for(M=0;M<10;M++) {
        
          _tmpX = N * 0.1;
          _tmpY = M * 0.1;
          
          _tmpZ = 0.0;
          for(L=0;L<16;L++) {
            Quot = L/4;
            Resd = L%4;
            _tmpZ += coeff[L] * pow(_tmpX,Resd) * pow(_tmpY,Quot);
          }
        
          _tmpX *= _delX;  _tmpX += i * _delX;
          _tmpY *= _delY;  _tmpY += j * _delY;
        
          fprintf(fq,"%lf\t%lf\t%lf\n",_tmpX,_tmpY,_tmpZ);
        }
    }  

  fclose(fp);
  fclose(fq);

  return 0;
}
