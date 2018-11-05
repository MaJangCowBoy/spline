/*
 This code calculates the coefficients from boundary condition for each cell.
 */
#include <stdio.h>
#include "spline.h"
#include <stdlib.h>
#include <math.h>

int main() {
 
  int i,j,k;
  int a,b,c;
  FILE *fp;
  double _Val_x,_Val_y,_Val_z;
 
  double 
  double _Coeff[64];
  
  fp = fopen("input.txt","r");
  
  if(fp == NULL) { printf("error open file\n"); exit(1); }

  fscanf();
 
 for(i=0;i<64;i++)
  for(j=0;j<64;j++) {
    
  }
  
  return 0;
}
