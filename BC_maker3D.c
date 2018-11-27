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
  int NL,NR;
  double _ValX[_NPOINT], _ValY[_NPOINT], _ValZ[_NPOINT];
  double _ValF[_NPOINT][_NPOINT][_NPOINT];
  double _ValFx[_NPOINT][_NPOINT][_NPOINT], _ValFy[_NPOINT][_NPOINT][_NPOINT], _ValFz[_NPOINT][_NPOINT][_NPOINT];
  double _ValFxy[_NPOINT][_NPOINT][_NPOINT], _ValFxz[_NPOINT][_NPOINT][_NPOINT], _ValFyz[_NPOINT][_NPOINT][_NPOINT];
  double _ValFxyz[_NPOINT][_NPOINT][_NPOINT];
  FILE *fp;
	
  fp = fopen("nothing.txt","r");

  fscanf(fp,"%d",&NL);
	
  NR = NL * NL * NL;
	
  double coeff[NR];
  
  for(N=0;N<NR;N++) {
    fscanf(fp,"%lf",&coeff[N]);  
  }
	
  fclose(fp);

  for(i=0;i<_NPOINT;i++) 
    for(j=0;j<_NPOINT;j++) 
      for(k=0;k<_NPOINT;k++) {
	    
        _ValX[i] = _INTVX * i;
        _ValY[j] = _INTVY * j;
        _ValZ[k] = _INTVZ * k;
        
        _ValF[i][j][k] = 0.0; 
        _ValFx[i][j][k] = 0.0; _ValFy[i][j][k] = 0.0; _ValFz[i][j][k] = 0.0;
        _ValFxy[i][j][k] = 0.0; _ValFxz[i][j][k] = 0.0; _ValFyz[i][j][k] = 0.0;
        _ValFxyz[i][j][k] = 0.0;
	    
        for(N=0;N<NR;N++) {
		
             a = N % NL;
             b = N % (NL*NL);  b = b / NL; 
             c = N / (NL*NL);
		
              _ValF[i][j][k] += coeff[N]
                                *cos(a*M_PI*_ValX[i])
                                *cos(b*M_PI*_ValY[j])
                                *cos(c*M_PI*_ValZ[k]);
                                
              _ValFx[i][j][k] += -a*M_PI*coeff[N]
                                 *sin(a*M_PI*_ValX[i])
                                 *cos(b*M_PI*_ValY[j])
                                 *cos(c*M_PI*_ValZ[k]);

              _ValFy[i][j][k] += -b*M_PI*coeff[N]
                                 *cos(a*M_PI*_ValX[i])
                                 *sin(b*M_PI*_ValY[j])
                                 *cos(c*M_PI*_ValZ[k]);
                                 
              _ValFz[i][j][k] += -c*M_PI*coeff[N]
                                 *cos(a*M_PI*_ValX[i])
                                 *cos(b*M_PI*_ValY[j])
                                 *sin(c*M_PI*_ValZ[k]);
                                 
              _ValFxy[i][j][k] += a*b*M_PI*M_PI*coeff[N]
                                  *sin(a*M_PI*_ValX[i])
                                  *sin(b*M_PI*_ValY[j])
                                  *cos(c*M_PI*_ValZ[k]);
                                  
              _ValFxz[i][j][k] += a*c*M_PI*M_PI*coeff[N]
                                  *sin(a*M_PI*_ValX[i])
                                  *cos(b*M_PI*_ValY[j])
                                  *sin(c*M_PI*_ValZ[k]);
                                  
              _ValFyz[i][j][k] += b*c*M_PI*M_PI*coeff[N]
                                  *cos(a*M_PI*_ValX[i])
                                  *sin(b*M_PI*_ValY[j])
                                  *sin(c*M_PI*_ValZ[k]);
                                  
              _ValFxyz[i][j][k] += -a*b*c*M_PI*M_PI*M_PI*coeff[N]
                                   *sin(a*M_PI*_ValX[i])
                                   *sin(b*M_PI*_ValY[j])
                                   *sin(c*M_PI*_ValZ[k]);
        }
      }
  
  fp = fopen("something.txt","w"); 

  fprintf(fp,"%d\n",(_NPOINT-1));
  fprintf(fp,"%lf\t%lf\t%lf\n",_INTVX,_INTVY,_INTVZ);
  
  for(i=0;i<(_NPOINT-1);i++) 
    for(j=0;j<(_NPOINT-1);j++) 
      for(k=0;k<(_NPOINT-1);k++) {
        fprintf(fp,"%lf\t",_ValF[i][j][k]);  fprintf(fp,"%lf\t",_ValF[i+1][j][k]);
        fprintf(fp,"%lf\t",_ValF[i][j+1][k]);  fprintf(fp,"%lf\t",_ValF[i+1][j+1][k]);
        fprintf(fp,"%lf\t",_ValF[i][j][k+1]);  fprintf(fp,"%lf\t",_ValF[i+1][j][k+1]);
        fprintf(fp,"%lf\t",_ValF[i][j+1][k+1]);  fprintf(fp,"%lf\t",_ValF[i+1][j+1][k+1]);
      
        fprintf(fp,"%lf\t",_ValFx[i][j][k]);  fprintf(fp,"%lf\t",_ValFx[i+1][j][k]);
        fprintf(fp,"%lf\t",_ValFx[i][j+1][k]);  fprintf(fp,"%lf\t",_ValFx[i+1][j+1][k]);
        fprintf(fp,"%lf\t",_ValFx[i][j][k+1]);  fprintf(fp,"%lf\t",_ValFx[i+1][j][k+1]);
        fprintf(fp,"%lf\t",_ValFx[i][j+1][k+1]);  fprintf(fp,"%lf\t",_ValFx[i+1][j+1][k+1]);
        
        fprintf(fp,"%lf\t",_ValFy[i][j][k]);  fprintf(fp,"%lf\t",_ValFy[i+1][j][k]);
        fprintf(fp,"%lf\t",_ValFy[i][j+1][k]);  fprintf(fp,"%lf\t",_ValFy[i+1][j+1][k]);
        fprintf(fp,"%lf\t",_ValFy[i][j][k+1]);  fprintf(fp,"%lf\t",_ValFy[i+1][j][k+1]);
        fprintf(fp,"%lf\t",_ValFy[i][j+1][k+1]);  fprintf(fp,"%lf\t",_ValFy[i+1][j+1][k+1]);

        fprintf(fp,"%lf\t",_ValFz[i][j][k]);  fprintf(fp,"%lf\t",_ValFz[i+1][j][k]);
        fprintf(fp,"%lf\t",_ValFz[i][j+1][k]);  fprintf(fp,"%lf\t",_ValFz[i+1][j+1][k]);
        fprintf(fp,"%lf\t",_ValFz[i][j][k+1]);  fprintf(fp,"%lf\t",_ValFz[i+1][j][k+1]);
        fprintf(fp,"%lf\t",_ValFz[i][j+1][k+1]);  fprintf(fp,"%lf\t",_ValFz[i+1][j+1][k+1]);
        
        fprintf(fp,"%lf\t",_ValFxy[i][j][k]);  fprintf(fp,"%lf\t",_ValFxy[i+1][j][k]);
        fprintf(fp,"%lf\t",_ValFxy[i][j+1][k]);  fprintf(fp,"%lf\t",_ValFxy[i+1][j+1][k]);
        fprintf(fp,"%lf\t",_ValFxy[i][j][k+1]);  fprintf(fp,"%lf\t",_ValFxy[i+1][j][k+1]);
        fprintf(fp,"%lf\t",_ValFxy[i][j+1][k+1]);  fprintf(fp,"%lf\t",_ValFxy[i+1][j+1][k+1]);
        
        fprintf(fp,"%lf\t",_ValFxz[i][j][k]);  fprintf(fp,"%lf\t",_ValFxz[i+1][j][k]);
        fprintf(fp,"%lf\t",_ValFxz[i][j+1][k]);  fprintf(fp,"%lf\t",_ValFxz[i+1][j+1][k]);
        fprintf(fp,"%lf\t",_ValFxz[i][j][k+1]);  fprintf(fp,"%lf\t",_ValFxz[i+1][j][k+1]);
        fprintf(fp,"%lf\t",_ValFxz[i][j+1][k+1]);  fprintf(fp,"%lf\t",_ValFxz[i+1][j+1][k+1]);        

        fprintf(fp,"%lf\t",_ValFyz[i][j][k]);  fprintf(fp,"%lf\t",_ValFyz[i+1][j][k]);
        fprintf(fp,"%lf\t",_ValFyz[i][j+1][k]);  fprintf(fp,"%lf\t",_ValFyz[i+1][j+1][k]);
        fprintf(fp,"%lf\t",_ValFyz[i][j][k+1]);  fprintf(fp,"%lf\t",_ValFyz[i+1][j][k+1]);
        fprintf(fp,"%lf\t",_ValFyz[i][j+1][k+1]);  fprintf(fp,"%lf\t",_ValFyz[i+1][j+1][k+1]);
        
        fprintf(fp,"%lf\t",_ValFxyz[i][j][k]);  fprintf(fp,"%lf\t",_ValFxyz[i+1][j][k]);
        fprintf(fp,"%lf\t",_ValFxyz[i][j+1][k]);  fprintf(fp,"%lf\t",_ValFxyz[i+1][j+1][k]);
        fprintf(fp,"%lf\t",_ValFxyz[i][j][k+1]);  fprintf(fp,"%lf\t",_ValFxyz[i+1][j][k+1]);
        fprintf(fp,"%lf\t",_ValFxyz[i][j+1][k+1]);  fprintf(fp,"%lf\n",_ValFxyz[i+1][j+1][k+1]);        
      }
	 
  fclose(fp);
    
  return 0;
}
