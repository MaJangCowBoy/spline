#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main() {

  int i,j,k;
  int N,M,L;
  int a,b,c;
  int _NL,_NX;
  double _ValX,_ValY,_ValZ,_ValF;
  double _delX,_delY,_delZ;
  double _tmpX,_tmpY,_tmpZ,_tmpF;
  FILE *fp;
  
  fp = fopen("nothing.txt","r");
  
  fscanf(fp,"%d",&_NL);
  
  double _Coeff[_NL];
  
  for(i=0;i<_NL;i++) {
  
    fscanf(fp,"%lf",&_Coeff[i]);
  }
  
  fclose(fp);
  
  fp = fopen("something.txt","r");
  
  fscanf(fp,"%d",&_NX);
  fscanf(fp,"%lf",&_delX);
  
  fclose(fp);
  
  fp = fopen("original.txt","w");
  
  for(i=0;i<_NX;i++) {
  
    for(j=0;j<10;j++) {
    
      _ValX = i * _delX + 0.1 * j * delX;
      
      _ValY  = 0.0;
      for(k=0;k<_NL;k++) {
      
        _ValY += _Coeff[k] * cos(k*M_PI*_ValX);
      }
      
      fprintf(fp,"%lf\t%lf\n",_ValX,_ValY);
    }
  }
  
  fclose(fp);

  return 0;
}
