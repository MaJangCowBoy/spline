#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#ifndef _INTVX
#define _INTVX 0.05
#endif

#ifndef _INTVY
#define _INTVY 0.05
#endif

#ifndef _INTVZ
#define _INTVZ 0.05
#endif

#ifndef _NPOINT
#define _NPOINT 21
#endif

int main() {

  int i,j,k;
  int N,M,L;
  int a,b,c;
  int NL;
  double _FCx, _FCxp;
  double _FCy, _FCyp;
  double _FCz, _FCzp;
  double _FU, _FUx, _FUy, _FUz, _FUxy, _FUyz, _FUxz, _FUxyz;
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
        
        
        
        _FU = 0.0;
        _FUx = 0.0; _FUy = 0.0; _FUz = 0.0;
        _FUxy = 0.0; _FUxz = 0.0; _FUyz = 0.0;
        _FUxyz = 0.0;
	    
        for(N = 0; N < NL; N++)
          for(M = 0; M < NL; M++)
            for(L = 0; L < NL; L++) {
		
              _FU += coeff[N][M][L]
                   * sin( (N+1)*M_PI*_ValX )
                   * sin( (M+1)*M_PI*_ValY )
                   * sin( (L+1)*M_PI*_ValZ );
                                
              _FUx += (N+1) * M_PI * coeff[N][M][L]
                    * cos( (N+1)*M_PI*_ValX )
                    * sin( (M+1)*M_PI*_ValY )
                    * sin( (L+1)*M_PI*_ValZ );

              _FUy += (M+1) * M_PI * coeff[N][M][L]
                    * sin( (N+1)*M_PI*_ValX )
                    * cos( (M+1)*M_PI*_ValY )
                    * sin( (L+1)*M_PI*_ValZ );
                                 
              _FUz += (L+1) * M_PI * coeff[N][M][L]
                    * sin( (N+1)*M_PI*_ValX )
                    * sin( (M+1)*M_PI*_ValY )
                    * cos( (L+1)*M_PI*_ValZ );
                                 
              _FUxy += (N+1) * (M+1) * M_PI * M_PI
                     * coeff[N][M][L]
                     * cos( (N+1)*M_PI*_ValX )
                     * cos( (M+1)*M_PI*_ValY )
                     * sin( (L+1)*M_PI*_ValZ );
                                  
              _FUxz += (N+1) * (L+1) * M_PI * M_PI
                     * coeff[N][M][L]
                     * cos( (N+1)*M_PI*_ValX )
                     * sin( (M+1)*M_PI*_ValY )
                     * cos( (L+1)*M_PI*_ValZ );
                                  
              _FUyz += (M+1) * (L+1) * M_PI * M_PI
                     * coeff[N][M][L]
                     * sin( (N+1)*M_PI*_ValX )
                     * cos( (M+1)*M_PI*_ValY )
                     * cos( (L+1)*M_PI*_ValZ );
                                  
              _FUxyz += (N+1) * (M+1) * (L+1)
                      * M_PI * M_PI * M_PI
                      * coeff[N][M][L]
                      * cos( (N+1)*M_PI*_ValX )
                      * cos( (M+1)*M_PI*_ValY )
                      * cos( (L+1)*M_PI*_ValZ );
            }
            
            if( _ValX < 0.1 ) {
              _FCx = ( ( 1 - cos(10*M_PI*_ValX) ) * 0.5 );
              _FCxp = ( 5 * M_PI * sin(10*M_PI*_ValX) );
            } else if( _ValX > 0.9 ) {
              _FCx = ( ( 1 + cos(10*M_PI*(_ValX-0.9)) ) * 0.5 );
              _FCxp = ( -5 * M_PI * sin(10*M_PI*(_ValX-0.9)) );
            } else {
              _FCx = 1.0;
              _FCxp = 0.0;
            }
            
            if( _ValY < 0.1 ) {
              _FCy = ( ( 1 - cos(10*M_PI*_ValY) ) * 0.5 );
              _FCyp = ( 5 * M_PI * sin(10*M_PI*_ValY) );
            } else if( _ValY > 0.9 ) {
              _FCy = ( ( 1 + cos(10*M_PI*(_ValY-0.9)) ) * 0.5 );
              _FCyp = ( -5 * M_PI * sin(10*M_PI*(_ValY-0.9)) );
            } else {
              _FCy = 1.0;
              _FCyp = 0.0;
            }
            
            if( _ValZ < 0.1 ) {
              _FCz = ( ( 1 - cos(10*M_PI*_ValZ) ) * 0.5 );
              _FCzp = ( 5 * M_PI * sin(10*M_PI*_ValZ) );              
            } else if( _ValZ > 0.9 ) {
              _FCz = ( ( 1 + cos(10*M_PI*(_ValZ-0.9)) ) * 0.5 );
              _FCzp = ( -5 * M_PI * sin(10*M_PI*(_ValZ-0.9)) );
            } else {
              _FCz = 1.0;
              _FCzp = 0.0;
            }

            _ValF[i][j][k] = _FU * _FCx * _FCy * _FCz;

            _ValFx[i][j][k] = _FUx * _FCx * _FCy * _FCz
                            + _FU * _FCxp * _FCy * _FCz;
                            
            _ValFy[i][j][k] = _FUy * _FCx * _FCy * _FCz
                            + _FU * _FCx * _FCyp * _FCz;
                            
            _ValFz[i][j][k] = _FUz * _FCx * _FCy * _FCz
                            + _FU * _FCx * _FCy * _FCzp;
                            
            _ValFxy[i][j][k] = _FUxy * _FCx * _FCy * _FCz
                             + _FUx * _FCx * _FCyp * _FCz
                             + _FUy * _FCxp * _FCy * _FCz
                             + _FU * _FCxp * _FCyp * _FCz;
                             
            _ValFxz[i][j][k] = _FUxz * _FCx * _FCy * _FCz
                             + _FUx * _FCx * _FCy * _FCzp
                             + _FUz * _FCxp * _FCy * _FCz
                             + _FU * _FCxp * _FCy * _FCzp;
                             
            _ValFyz[i][j][k] = _FUyz * _FCx * _FCy * _FCz
                             + _FUy * _FCx * _FCy * _FCzp
                             + _FUz * _FCx * _FCyp * _FCz
                             + _FU * _FCx * _FCyp * _FCzp;
            
            _ValFxyz[i][j][k] = _FUxyz* _FCx * _FCy * _FCz
                              + _FUxy* _FCx * _FCy * _FCzp
                              + _FUxz* _FCx * _FCyp * _FCz
                              + _FUyz* _FCxp * _FCy * _FCz
                              + _FUx* _FCx * _FCyp * _FCzp              
                              + _FUy* _FCxp * _FCy * _FCzp
                              + _FUz* _FCxp * _FCyp * _FCz
                              + _FU* _FCxp * _FCyp * _FCzp;
            
      }
  
  fp = fopen("something.txt","w"); 

  fprintf(fp,"%d\n",(_NPOINT-1));
  fprintf(fp,"%.15e\t%.15e\t%.15e\n",_INTVX,_INTVY,_INTVZ);
  
  for(i=0;i<(_NPOINT-1);i++) 
    for(j=0;j<(_NPOINT-1);j++) 
      for(k=0;k<(_NPOINT-1);k++) {
        fprintf(fp,"%.15e\t",_ValF[i][j][k]);  fprintf(fp,"%.15e\t",_ValF[i+1][j][k]);
        fprintf(fp,"%.15e\t",_ValF[i][j+1][k]);  fprintf(fp,"%.15e\t",_ValF[i+1][j+1][k]);
        fprintf(fp,"%.15e\t",_ValF[i][j][k+1]);  fprintf(fp,"%.15e\t",_ValF[i+1][j][k+1]);
        fprintf(fp,"%.15e\t",_ValF[i][j+1][k+1]);  fprintf(fp,"%.15e\t",_ValF[i+1][j+1][k+1]);
      
        fprintf(fp,"%.15e\t",_ValFx[i][j][k]);  fprintf(fp,"%.15e\t",_ValFx[i+1][j][k]);
        fprintf(fp,"%.15e\t",_ValFx[i][j+1][k]);  fprintf(fp,"%.15e\t",_ValFx[i+1][j+1][k]);
        fprintf(fp,"%.15e\t",_ValFx[i][j][k+1]);  fprintf(fp,"%.15e\t",_ValFx[i+1][j][k+1]);
        fprintf(fp,"%.15e\t",_ValFx[i][j+1][k+1]);  fprintf(fp,"%.15e\t",_ValFx[i+1][j+1][k+1]);
        
        fprintf(fp,"%.15e\t",_ValFy[i][j][k]);  fprintf(fp,"%.15e\t",_ValFy[i+1][j][k]);
        fprintf(fp,"%.15e\t",_ValFy[i][j+1][k]);  fprintf(fp,"%.15e\t",_ValFy[i+1][j+1][k]);
        fprintf(fp,"%.15e\t",_ValFy[i][j][k+1]);  fprintf(fp,"%.15e\t",_ValFy[i+1][j][k+1]);
        fprintf(fp,"%.15e\t",_ValFy[i][j+1][k+1]);  fprintf(fp,"%.15e\t",_ValFy[i+1][j+1][k+1]);

        fprintf(fp,"%.15e\t",_ValFz[i][j][k]);  fprintf(fp,"%.15e\t",_ValFz[i+1][j][k]);
        fprintf(fp,"%.15e\t",_ValFz[i][j+1][k]);  fprintf(fp,"%.15e\t",_ValFz[i+1][j+1][k]);
        fprintf(fp,"%.15e\t",_ValFz[i][j][k+1]);  fprintf(fp,"%.15e\t",_ValFz[i+1][j][k+1]);
        fprintf(fp,"%.15e\t",_ValFz[i][j+1][k+1]);  fprintf(fp,"%.15e\t",_ValFz[i+1][j+1][k+1]);
        
        fprintf(fp,"%.15e\t",_ValFxy[i][j][k]);  fprintf(fp,"%.15e\t",_ValFxy[i+1][j][k]);
        fprintf(fp,"%.15e\t",_ValFxy[i][j+1][k]);  fprintf(fp,"%.15e\t",_ValFxy[i+1][j+1][k]);
        fprintf(fp,"%.15e\t",_ValFxy[i][j][k+1]);  fprintf(fp,"%.15e\t",_ValFxy[i+1][j][k+1]);
        fprintf(fp,"%.15e\t",_ValFxy[i][j+1][k+1]);  fprintf(fp,"%.15e\t",_ValFxy[i+1][j+1][k+1]);
        
        fprintf(fp,"%.15e\t",_ValFxz[i][j][k]);  fprintf(fp,"%.15e\t",_ValFxz[i+1][j][k]);
        fprintf(fp,"%.15e\t",_ValFxz[i][j+1][k]);  fprintf(fp,"%.15e\t",_ValFxz[i+1][j+1][k]);
        fprintf(fp,"%.15e\t",_ValFxz[i][j][k+1]);  fprintf(fp,"%.15e\t",_ValFxz[i+1][j][k+1]);
        fprintf(fp,"%.15e\t",_ValFxz[i][j+1][k+1]);  fprintf(fp,"%.15e\t",_ValFxz[i+1][j+1][k+1]);        

        fprintf(fp,"%.15e\t",_ValFyz[i][j][k]);  fprintf(fp,"%.15e\t",_ValFyz[i+1][j][k]);
        fprintf(fp,"%.15e\t",_ValFyz[i][j+1][k]);  fprintf(fp,"%.15e\t",_ValFyz[i+1][j+1][k]);
        fprintf(fp,"%.15e\t",_ValFyz[i][j][k+1]);  fprintf(fp,"%.15e\t",_ValFyz[i+1][j][k+1]);
        fprintf(fp,"%.15e\t",_ValFyz[i][j+1][k+1]);  fprintf(fp,"%.15e\t",_ValFyz[i+1][j+1][k+1]);
        
        fprintf(fp,"%.15e\t",_ValFxyz[i][j][k]);  fprintf(fp,"%.15e\t",_ValFxyz[i+1][j][k]);
        fprintf(fp,"%.15e\t",_ValFxyz[i][j+1][k]);  fprintf(fp,"%.15e\t",_ValFxyz[i+1][j+1][k]);
        fprintf(fp,"%.15e\t",_ValFxyz[i][j][k+1]);  fprintf(fp,"%.15e\t",_ValFxyz[i+1][j][k+1]);
        fprintf(fp,"%.15e\t",_ValFxyz[i][j+1][k+1]);  fprintf(fp,"%.15e\n",_ValFxyz[i+1][j+1][k+1]);        
      }
	 
  fclose(fp);
    
  return 0;
}
