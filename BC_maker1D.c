#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main() {

  int i,j,k;
  double _Val_x[11], _Val_y[11], _Val_z[11];
  FILE *fp;
  
  for(i=0;i<11;i++) {
    _Val_x[i] = i * 0.2 * M_PI;
    _Val_y[i] = sin(_Val_x);
    _Val_z[i] = cos(_Val_x);
  }
  
  fp = fopen("something.txt","w");
  
  fprintf(fp,"0.1\n");
  
  for(i=0;i<10;i++) {
    fprintf(fp,"%lf\t%lf\t%lf\t%lf\n",
            _Val_y[i],_Val_y[i+1],
            (0.2*M_PI*_Val_z[i]),(0.2*M_PI*_Val_z[i+1]));
  }
    
  return 0;
}
