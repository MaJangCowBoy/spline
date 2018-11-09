#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#ifndef _INTVX
#define _INTVX 0.1
#endif

#ifndef _INTVY
#define _INTVY 0.1
#endif

#ifndef _INTVZ
#define _INTVZ 0.1
#endif

#ifndef _NPOINT
#define _NPOINT 11
#endif

int main() {

  int i,j,k;
  int N,M,L;
  int a,b,c;
  int NL;
  double _Val_x[_NPOINT], _Val_y[_NPOINT], _Val_z[_NPOINT];
  double _Val_f[_NPOINT][_NPOINT][_NPOINT];
  double _Val_fx[_NPOINT][_NPOINT][_NPOINT], _Val_fy[_NPOINT][_NPOINT][_NPOINT], _Val_fz[_NPOINT][_NPOINT][_NPOINT];
  double _Val_fxy[_NPOINT][_NPOINT][_NPOINT], _Val_fxz[_NPOINT][_NPOINT][_NPOINT], _Val_fyz[_NPOINT][_NPOINT][_NPOINT];
  double _Val_fxyz[_NPOINT][_NPOINT][_NPOINT];
  FILE *fp;
	
  fp = fopen("nothing.txt","r");

  fscanf(fp,"%d",&NL);
	
  double coeff[NL*NL*NL];
  
  for(N=0;N<(NL*NL*NL);N++) {
    fscanf(fp,"%lf",&coeff[N]);  
  }
	
  fclose(fp);

  for(i=0;i<_NPOINT;i++) 
    for(j=0;j<_NPOINT;j++) 
      for(k=0;k<_NPOINT;k++) {
	    
        _Val_x[i] = _INTVX * i;
        _Val_y[j] = _INTVY * j;
        _Val_y[k] = _INTVZ * k;
        
        _Val_f[i][j][k] = 0.0; 
        _Val_fx[i][j][k] = 0.0; _Val_fy[i][j][k] = 0.0; _Val_fz[i][j][k] = 0.0;
        _Val_fxy[i][j][k] = 0.0; _Val_fxz[i][j][k] = 0.0; _Val_fyz[i][j][k] = 0.0;
        _Val_fxyz[i][j][k] = 0.0;
	    
        N = 0;
        for(a=0;a<NL;a++) 
          for(b=0;b<NL;b++) 
            for(c=0;c<NL;c++) {
              _Val_f[i][j][k] += coeff[N]
                                *cos(a*M_PI*_Val_x[i])
                                *cos(b*M_PI*_Val_y[j])
                                *cos(c*M_PI*_Val_z[k]);
                                
              _Val_fx[i][j][k] += -a*M_PI*coeff[N]
                                 *sin(a*M_PI*_Val_x[i])
                                 *cos(b*M_PI*_Val_y[j])
                                 *cos(c*M_PI*_Val_z[k]);

              _Val_fy[i][j][k] += -b*M_PI*coeff[N]
                                 *cos(a*M_PI*_Val_x[i])
                                 *sin(b*M_PI*_Val_y[j])
                                 *cos(c*M_PI*_Val_z[k]);
                                 
              _Val_fz[i][j][k] += -c*M_PI*coeff[N]
                                 *cos(a*M_PI*_Val_x[i])
                                 *cos(b*M_PI*_Val_y[j])
                                 *sin(c*M_PI*_Val_z[k]);
                                 
              _Val_fxy[i][j][k] += a*b*M_PI*M_PI*coeff[N]
                                  *sin(a*M_PI*_Val_x[i])
                                  *sin(b*M_PI*_Val_y[j])
                                  *cos(c*M_PI*_Val_z[k]);
                                  
              _Val_fxz[i][j][k] += a*c*M_PI*M_PI*coeff[N]
                                  *sin(a*M_PI*_Val_x[i])
                                  *cos(b*M_PI*_Val_y[j])
                                  *sin(c*M_PI*_Val_z[k]);
                                  
              _Val_fyz[i][j][k] += b*c*M_PI*M_PI*coeff[N]
                                  *cos(a*M_PI*_Val_x[i])
                                  *sin(b*M_PI*_Val_y[j])
                                  *sin(c*M_PI*_Val_z[k]);
                                  
              _Val_fxyz[i][j][k] += -a*b*c*M_PI*M_PI*M_PI*coeff[N]
                                   *sin(a*M_PI*_Val_x[i])
                                   *sin(b*M_PI*_Val_y[j])
                                   *sin(c*M_PI*_Val_z[k]);                                  
	      N++;
            }
      }
  
  fp = fopen("something.txt","w"); 

  fprintf(fp,"%d\n",(_NPOINT-1));
  fprintf(fp,"%lf\t%lf\t%lf\n",_INTVX,_INTVY,_INTVZ);
  
  for(i=0;i<(_NPOINT-1);i++) 
    for(j=0;j<(_NPOINT-1);j++) 
      for(k=0;k<(_NPOINT-1);k++) {
        fprintf(fp,"%lf\t",_Val_f[i][j][k]);  fprintf(fp,"%lf\t",_Val_f[i+1][j][k]);
        fprintf(fp,"%lf\t",_Val_f[i][j+1][k]);  fprintf(fp,"%lf\t",_Val_f[i+1][j+1][k]);
        fprintf(fp,"%lf\t",_Val_f[i][j][k+1]);  fprintf(fp,"%lf\t",_Val_f[i+1][j][k+1]);
        fprintf(fp,"%lf\t",_Val_f[i][j+1][k+1]);  fprintf(fp,"%lf\t",_Val_f[i+1][j+1][k+1]);
      
        fprintf(fp,"%lf\t",_Val_fx[i][j][k]);  fprintf(fp,"%lf\t",_Val_fx[i+1][j][k]);
        fprintf(fp,"%lf\t",_Val_fx[i][j+1][k]);  fprintf(fp,"%lf\t",_Val_fx[i+1][j+1][k]);
        fprintf(fp,"%lf\t",_Val_fx[i][j][k+1]);  fprintf(fp,"%lf\t",_Val_fx[i+1][j][k+1]);
        fprintf(fp,"%lf\t",_Val_fx[i][j+1][k+1]);  fprintf(fp,"%lf\t",_Val_fx[i+1][j+1][k+1]);
        
        fprintf(fp,"%lf\t",_Val_fy[i][j][k]);  fprintf(fp,"%lf\t",_Val_fy[i+1][j][k]);
        fprintf(fp,"%lf\t",_Val_fy[i][j+1][k]);  fprintf(fp,"%lf\t",_Val_fy[i+1][j+1][k]);
        fprintf(fp,"%lf\t",_Val_fy[i][j][k+1]);  fprintf(fp,"%lf\t",_Val_fy[i+1][j][k+1]);
        fprintf(fp,"%lf\t",_Val_fy[i][j+1][k+1]);  fprintf(fp,"%lf\t",_Val_fy[i+1][j+1][k+1]);

        fprintf(fp,"%lf\t",_Val_fz[i][j][k]);  fprintf(fp,"%lf\t",_Val_fz[i+1][j][k]);
        fprintf(fp,"%lf\t",_Val_fz[i][j+1][k]);  fprintf(fp,"%lf\t",_Val_fz[i+1][j+1][k]);
        fprintf(fp,"%lf\t",_Val_fz[i][j][k+1]);  fprintf(fp,"%lf\t",_Val_fz[i+1][j][k+1]);
        fprintf(fp,"%lf\t",_Val_fz[i][j+1][k+1]);  fprintf(fp,"%lf\t",_Val_fz[i+1][j+1][k+1]);
        
        fprintf(fp,"%lf\t",_Val_fxy[i][j][k]);  fprintf(fp,"%lf\t",_Val_fxy[i+1][j][k]);
        fprintf(fp,"%lf\t",_Val_fxy[i][j+1][k]);  fprintf(fp,"%lf\t",_Val_fxy[i+1][j+1][k]);
        fprintf(fp,"%lf\t",_Val_fxy[i][j][k+1]);  fprintf(fp,"%lf\t",_Val_fxy[i+1][j][k+1]);
        fprintf(fp,"%lf\t",_Val_fxy[i][j+1][k+1]);  fprintf(fp,"%lf\t",_Val_fxy[i+1][j+1][k+1]);
        
        fprintf(fp,"%lf\t",_Val_fxz[i][j][k]);  fprintf(fp,"%lf\t",_Val_fxz[i+1][j][k]);
        fprintf(fp,"%lf\t",_Val_fxz[i][j+1][k]);  fprintf(fp,"%lf\t",_Val_fxz[i+1][j+1][k]);
        fprintf(fp,"%lf\t",_Val_fxz[i][j][k+1]);  fprintf(fp,"%lf\t",_Val_fxz[i+1][j][k+1]);
        fprintf(fp,"%lf\t",_Val_fxz[i][j+1][k+1]);  fprintf(fp,"%lf\t",_Val_fxz[i+1][j+1][k+1]);        

        fprintf(fp,"%lf\t",_Val_fyz[i][j][k]);  fprintf(fp,"%lf\t",_Val_fyz[i+1][j][k]);
        fprintf(fp,"%lf\t",_Val_fyz[i][j+1][k]);  fprintf(fp,"%lf\t",_Val_fyz[i+1][j+1][k]);
        fprintf(fp,"%lf\t",_Val_fyz[i][j][k+1]);  fprintf(fp,"%lf\t",_Val_fyz[i+1][j][k+1]);
        fprintf(fp,"%lf\t",_Val_fyz[i][j+1][k+1]);  fprintf(fp,"%lf\t",_Val_fyz[i+1][j+1][k+1]);
        
        fprintf(fp,"%lf\t",_Val_fxyz[i][j][k]);  fprintf(fp,"%lf\t",_Val_fxyz[i+1][j][k]);
        fprintf(fp,"%lf\t",_Val_fxyz[i][j+1][k]);  fprintf(fp,"%lf\t",_Val_fxyz[i+1][j+1][k]);
        fprintf(fp,"%lf\t",_Val_fxyz[i][j][k+1]);  fprintf(fp,"%lf\t",_Val_fxyz[i+1][j][k+1]);
        fprintf(fp,"%lf\t",_Val_fxyz[i][j+1][k+1]);  fprintf(fp,"%lf\n",_Val_fxyz[i+1][j+1][k+1]);        
      }
	 
  fclose(fp);
    
  return 0;
}
