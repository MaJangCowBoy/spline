#include <stdio.h>
#include "spline.h"
#include <stdlib.h>
#include <math.h>

int main() {
  
  int i,j,k;
  int a,b,c;
  int N,M,L;
  int _NL;
  double _delX,_delY,_delZ;
  double _Val_x,_Val_y,_Val_z;
  double _Coeff_a[64][_NL][_NL][_NL];    /* Coefficient vector */
  double _tmp_BC[64];         /* Boundary condition */
  FILE *fp;
  
  fp = fopen("something.txt","r");

  
  return 0;
}
