#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main() {
  int i,j,k;
  int a,b,c;
  int N,M,L;
  FILE *fp;
  int _NL;
  int Resd,Quot1,Quot2;
  double _delX,_delY,_delZ;
  double coeff[64];
  double _tmpX,_tmpY,_tmpZ,_tmpF;

  fp = fopen("something_else.txt","r");
  
  fscanf(fp,"%d",&_NL);
  fscanf(fp,"%lf",&_delX);
  fscanf(fp,"%lf",&_delY);
  fscanf(fp,"%lf",&_delY);
  
  for(i=0;i<_NL;i++)
    for(j=0;j<_NL;j++) 
      for(k=0;k<_NL;k++) {
      
        for(a=0;a<64;a++) {
          fscanf(fp,"%lf",&coeff[a]);
        }
      
        for(N=0;N<10;N++) 
          for(M=0;M<10;M++) 
            for(L=0;L<10;L++) {
            
              _tmpX = N * 0.1;
              _tmpY = M * 0.1;
              _tmpZ = L * 0.1;
              
              for(a=0;a<64;a++) {
                
                Resd  = a % 4;
                Quot1 = a % 16;  Quot1 /= 4;
                Quot2 = a / 16;
                
                _tmpF += coeff[a] * pow(_tmpX,Resd) * pow(_tmpY,Quot1) * pow(_tmpZ,Quot2);
              }
            
              _tmpX *= _delX;  _tmpX += i * _delX;
              _tmpY *= _delY;  _tmpY += j * _delY;
              _tmpZ *= _delZ;  _tmpZ += k * _delZ;
            
              printf("%lf\t%lf\t%lf\t%lf\n",_tmpX,_tmpY,_tmpZ,_tmpF);
            }
        
      }  
      
  fclose(fp);

  return 0;
}
