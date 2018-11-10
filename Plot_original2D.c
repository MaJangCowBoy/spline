#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main() {

  int i,j,k;
  int N,M,L;
  int a,b,c;
  int _NL,_NL1,_NL2;
  int resd,quot;
  double _ValX,_ValY,_ValZ,_ValF;
  double _delX,_delY,_delZ;
  double _tmpX,_tmpY,_tmpZ,_tmpF;
  FILE *fp;
  
  fp = fopen("nothing.txt","r");
  
  fscanf(fp,"%d",&_NL);
  _NL1 = _NL*_NL;
  
  double _Coeff[_NL1];
  
  for(i=0;i<(_NL1);i++) {
  
    fscanf(fp,"%lf",&_Coeff[i]);
  }
  
  fclose(fp);
  
  fp = fopen("something.txt","r");
  
  fscanf(fp,"%d",&_NL2);
  fscanf(fp,"%lf",&_delX);
  fscanf(fp,"%lf",&_delY);  
  
  fclose(fp);
  
  fp = fopen("original.txt","w");
  
  for(i=0;i<_NL2;i++)
    for(j=0;j<_NL2;j++) {
      
      for(N=0;N<10;N++)
        for(M=0;M<10;M++) {
          
          _ValX = i * _delX + 0.1 * N * _delX;
          _ValY = j * _delY + 0.1 * M * _delY;
          
          _ValF = 0.0;
          for(a=0;a<(_NL1);a++) {
            
            resd = a % _NL; 
            quot = a / _NL;  
            _Valf += _Coeff[a] * cos(resd*M_PI*_ValX) * cos(quot*M_PI*_ValY);
          }
          
          fprintf(fp,"%lf\t%lf\t%lf\n",_ValX,_ValY,_ValF);
        }
    }
    
  
  fclose(fp);

  return 0;
}
