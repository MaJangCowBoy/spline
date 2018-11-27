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
  double Fc;
  double _ValX, _ValY, _ValZ;
  double _ValF[_NPOINT][_NPOINT][_NPOINT];
  double _ValFx[_NPOINT][_NPOINT][_NPOINT], _ValFy[_NPOINT][_NPOINT][_NPOINT], _ValFz[_NPOINT][_NPOINT][_NPOINT];
  double _ValFxy[_NPOINT][_NPOINT][_NPOINT], _ValFxz[_NPOINT][_NPOINT][_NPOINT], _ValFyz[_NPOINT][_NPOINT][_NPOINT];
  double _ValFxyz[_NPOINT][_NPOINT][_NPOINT];
  FILE *fp;
	
  fp = fopen("nothing.txt","r");

  fscanf(fp,"%d",&NL);
  
  double coeff[NL][NL][NL];
  
  for(N = 0; N < NL; N++) 
    for(M =0; M < NL; M++)
      for(L = 0; L < NL; L++) {
        fscanf(fp,"%lf",&coeff[N][M][L]);  
      }
	
  fclose(fp);

  for(i=0;i<_NPOINT;i++) 
    for(j=0;j<_NPOINT;j++) 
      for(k=0;k<_NPOINT;k++) {
	    
        _ValX = _INTVX * i;
        _ValY = _INTVY * j;
        _ValZ = _INTVZ * k;
        
        _ValF[i][j][k] = 0.0; 
        _ValFx[i][j][k] = 0.0; _ValFy[i][j][k] = 0.0; _ValFz[i][j][k] = 0.0;
        _ValFxy[i][j][k] = 0.0; _ValFxz[i][j][k] = 0.0; _ValFyz[i][j][k] = 0.0;
        _ValFxyz[i][j][k] = 0.0;
	    
        for(N = 0; N < NL; N++) 
          for(M = 0; M < NL; M++)  
            for(L = 0; L < NL; L++) {
		
              _ValF[i][j][k] += coeff[N][M][L]
                              * sin( (N+1)*M_PI*_ValX )
                              * sin( (M+1)*M_PI*_ValY )
                              * sin( (L+1)*M_PI*_ValZ );
                                
              _ValFx[i][j][k] += (N+1) * M_PI * coeff[N][M][L]
                               * cos( (N+1)*M_PI*_ValX )
                               * sin( (M+1)*M_PI*_ValY )
                               * sin( (L+1)*M_PI*_ValZ );

              _ValFy[i][j][k] += (M+1) * M_PI * coeff[N][M][L]
                               * sin( (N+1)*M_PI*_ValX )
                               * cos( (M+1)*M_PI*_ValY )
                               * sin( (L+1)*M_PI*_ValZ );
                                 
              _ValFz[i][j][k] += (L+1) * M_PI * coeff[N][M][L]
                               * sin( (N+1)*M_PI*_ValX )
                               * sin( (M+1)*M_PI*_ValY )
                               * cos( (L+1)*M_PI*_ValZ );
                                 
              _ValFxy[i][j][k] += (N+1) * (M+1) * M_PI * M_PI
                                * coeff[N][M][L]
                                * cos( (N+1)*M_PI*_ValX )
                                * cos( (M+1)*M_PI*_ValY )
                                * sin( (L+1)*M_PI*_ValZ );
                                  
              _ValFxz[i][j][k] += (N+1) * (L+1) * M_PI * M_PI
                                * coeff[N][M][L]
                                * cos( (N+1)*M_PI*_ValX )
                                * sin( (M+1)*M_PI*_ValY )
                                * cos( (L+1)*M_PI*_ValZ );
                                  
              _ValFyz[i][j][k] += (M+1) * (L+1) * M_PI * M_PI
                                * coeff[N][M][L]
                                * sin( (N+1)*M_PI*_ValX )
                                * cos( (M+1)*M_PI*_ValY )
                                * cos( (L+1)*M_PI*_ValZ );
                                  
              _ValFxyz[i][j][k] += (N+1) * (M+1) * (L+1)
                                 * M_PI * M_PI * M_PI
                                 * coeff[N][M][L]
                                 * cos( (N+1)*M_PI*_ValX )
                                 * cos( (M+1)*M_PI*_ValY )
                                 * cos( (L+1)*M_PI*_ValZ );
            }
            
            if( _ValX < 0.1 ) {
              Fc = ( 1 - cos(10*M_PI*_ValX) ) * 0.5;
              _ValF[i][j][k] *= Fc;
              _ValFx[i][j][k] *= Fc;  _ValFy[i][j][k] *= Fc;  _ValFz[i][j][k] *= Fc;
              _ValFxy[i][j][k] *= Fc;  _ValFxz[i][j][k] *= Fc;  _ValFyz[i][j][k] *= Fc;
              _ValFxyz[i][j][k] *= Fc;
              
            } else if( _ValX > 0.9 ) {
              Fc = ( 1 + cos(10*M_PI*(_ValX-0.9)) ) * 0.5;
              _ValF[i][j][k] *= Fc;
              _ValFx[i][j][k] *= Fc;  _ValFy[i][j][k] *= Fc;  _ValFz[i][j][k] *= Fc;
              _ValFxy[i][j][k] *= Fc;  _ValFxz[i][j][k] *= Fc;  _ValFyz[i][j][k] *= Fc;
              _ValFxyz[i][j][k] *= Fc;
              
            } else {    }
            
            if ( _ValY < 0.1 ) {
              Fc = ( 1 - cos(10*M_PI*_ValY) ) * 0.5;
              _ValF[i][j][k] *= Fc;
              _ValFx[i][j][k] *= Fc;  _ValFy[i][j][k] *= Fc;  _ValFz[i][j][k] *= Fc;
              _ValFxy[i][j][k] *= Fc;  _ValFxz[i][j][k] *= Fc;  _ValFyz[i][j][k] *= Fc;
              _ValFxyz[i][j][k] *= Fc;
              
            } else if( _ValY > 0.9 ) {
              Fc = ( 1 + cos(10*M_PI*(_ValY-0.9)) ) * 0.5;
              _ValF[i][j][k] *= Fc;
              _ValFx[i][j][k] *= Fc;  _ValFy[i][j][k] *= Fc;  _ValFz[i][j][k] *= Fc;
              _ValFxy[i][j][k] *= Fc;  _ValFxz[i][j][k] *= Fc;  _ValFyz[i][j][k] *= Fc;
              _ValFxyz[i][j][k] *= Fc;
              
            } else {    }
            
            if ( _ValZ < 0.1 ) {
              Fc = ( 1 - cos(10*M_PI*_ValZ) ) * 0.5;
              _ValF[i][j][k] *= Fc;
              _ValFx[i][j][k] *= Fc;  _ValFy[i][j][k] *= Fc;  _ValFz[i][j][k] *= Fc;
              _ValFxy[i][j][k] *= Fc;  _ValFxz[i][j][k] *= Fc;  _ValFyz[i][j][k] *= Fc;
              _ValFxyz[i][j][k] *= Fc;
              
            } else if( _ValZ > 0.9 ) {
              Fc = ( 1 + cos(10*M_PI*(_ValZ-0.9)) ) * 0.5;
              _ValF[i][j][k] *= Fc;
              _ValFx[i][j][k] *= Fc;  _ValFy[i][j][k] *= Fc;  _ValFz[i][j][k] *= Fc;
              _ValFxy[i][j][k] *= Fc;  _ValFxz[i][j][k] *= Fc;  _ValFyz[i][j][k] *= Fc;
              _ValFxyz[i][j][k] *= Fc;
              
            } else {    }
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
