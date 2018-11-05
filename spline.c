/*
 This code calculates the coefficients from boundary condition for each cell.
 */
#include <stdio.h>
#include "spline.h"
#include <stdlib.h>
#include <math.h>

int main() {
 
  int i,j,k;
  FILE *fp;
  double _val_x,_val_y,_val_z;
  
  fp = fopen("input.txt","r");
  
  if(fp == NULL) { printf("error open file\n"); exit(1); }

  
  
  return 0;
}
