#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main() {

  int i,j,k;
  int N,M,L;
  int a,b,c;
  int _NL;
  double _ValX,_ValY,_ValZ,_ValF;
  double _delX,_delY,_delZ;
  double _tmpX,_tmpY,_tmpZ,_tmpF;
  FILE *fp;
  
  fp = fopen("nothing.txt","r");
  
  fscanf(fp,"%d",_NL);
  
  double _Coeff[_NL];
  
  for(i=0;i<_NL;i++) {
  
    fscanf(fp,"%lf",_Coeff[i]);
  }
  
  fclose(fp);
  
  fp = fopen("something","r");
  
  fscanf(fp,"%d",_NL);
  fscanf(fp,"%lf",_delX);
  
  fclose(fp);
  
  for(i=0;i<_)

  return 0;
}
