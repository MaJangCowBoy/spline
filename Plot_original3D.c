#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main() {

  int i,j,k;
  int N,M,L;
  int a,b,c;
  int _NL,_NR;
  double Fc;
  double _ValX,_ValY,_ValZ,_ValF;
  double _delX,_delY,_delZ;
  double _tmpX,_tmpY,_tmpZ,_tmpF;
  FILE *fp;
  
  fp = fopen("nothing.txt","r");
  
  fscanf(fp,"%d",&_NL);
  
  double _Coeff[_NL][_NL][_NL];
  
  for(i=0;i<_NL;i++)
    for(j=0;j<_NL;j++)
      for(k=0;k<_NL;k++) {
        fscanf(fp,"%lf",&_Coeff[i][j][k]);
      }
  
  fclose(fp);
  
  fp = fopen("something.txt","r");
  
  fscanf(fp,"%d",&_NR);
  fscanf(fp,"%lf",&_delX);
  fscanf(fp,"%lf",&_delY);
  fscanf(fp,"%lf",&_delZ);
  
  fclose(fp);
  
  fp = fopen("original.txt","w");
  
  for(i=0;i<_NR;i++)
    for(j=0;j<_NR;j++)
      for(k=0;k<_NR;k++) {
      
        for(N=0;N<2;N++)
          for(M=0;M<2;M++)
            for(L=0;L<2;L++) {
            
              _ValX = i * _delX + 0.5 * N * _delX;
              _ValY = j * _delY + 0.5 * M * _delY;
              _ValZ = k * _delZ + 0.5 * L * _delZ;
            
              _ValF = 0.0;
              for(a=0;a<_NL;a++) 
                for(b=0;b<_NL;b++)    
                  for(c=0;c<_NL;c++) {
                      _ValF += _Coeff[a][b][c]
                             * sin( (a+1)*M_PI*_ValX )
                             * sin( (b+1)*M_PI*_ValY )
                             * sin( (c+1)*M_PI*_ValZ );
                    }
                    
              if( _ValX < 0.1 ) {
                Fc = ( ( 1 - cos(10*M_PI*_ValX) ) * 0.5 );
                _ValF *= Fc;
              } else if( _ValX > 0.9 ) {
                Fc = ( ( 1 + cos(10*M_PI*(_ValX-0.9)) ) * 0.5 );
                _ValF *= Fc;
              } else {    }
                    
              if( _ValY < 0.1 ) {
                Fc = ( ( 1 - cos(10*M_PI*_ValY) ) * 0.5 );
                _ValF *= Fc;
              } else if( _ValY > 0.9 ) {
                Fc = ( ( 1 + cos(10*M_PI*(_ValY-0.9)) ) * 0.5 );
                _ValF *= Fc;
              } else {    }
              
              if( _ValZ < 0.1 ) {
                Fc = ( ( 1 - cos(10*M_PI*_ValZ) ) * 0.5 );
                _ValF *= Fc;
              } else if( _ValZ > 0.9 ) {
                Fc = ( ( 1 + cos(10*M_PI*(_ValZ-0.9)) ) * 0.5 );
                _ValF *= Fc;
              } else {    }
                    
              fprintf(fp,"%.15e\t%.15e\t%.15e\t%.15e\n",_ValX,_ValY,_ValZ,_ValF);
            }
      }
       
  fclose(fp);

  return 0;
}
