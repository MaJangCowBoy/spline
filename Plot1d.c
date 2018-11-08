#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main() {
  int i,j,k;
  int N,M,L;
  FILE *fp;
  int _NL;
  double _delX;
  double coeff[4];
  double _tmpX,_tmpY;

  fp = fopen("something_else.txt","r");
  
  fscanf(fp,"%d",&_NL);
  fscanf(fp,"%lf,&_delX);
  
  for(i=0;i<_NL;i++) {

    for(j=0;j<4;j++) {
      fscanf(fp,"%lf",&coeff[j]);
    }
    
    for(j=0;j<10;j++)
      _tmpX = j * _delX * 0.1;
      _tmpY = 0.0;
      for(k=0;k<4;k++) {
        _tmpY += coeff[k] * pow(_tmpX,k);
      }
      _tmpX += i * _delX;
      printf("%lf\t%lf\n",_tmpX,_tmpY);
  }
  
  fclose(fp);

  return 0;
}
