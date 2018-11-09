# spline
spline_for_1,2,3_dimension

# Boundary condition
input boundary condition for each grid should be ordered as

1-D

f(0), f(1), fx(0), fx(1)

2-D 

f(0,0), f(1,0), f(0,1), f(1,1)
fx(0,0), fx(1,0), fx(0,1), fx(1,1)
fy(0,0), fy(1,0), fy(0,1), fy(1,1)
fxy(0,0), fxy(1,0), fxy(0,1), fxy(1,1)

3-D

f(0,0,0), f(1,0,0), f(0,1,0), f(1,1,0), f(0,0,1), f(1,0,1), f(0,1,1), f(1,1,1)
fx(0,0,0), fx(1,0,0), fx(0,1,0), fx(1,1,0), fx(0,0,1), fx(1,0,1), fx(0,1,1), fx(1,1,1)
fy(0,0,0), fy(1,0,0), fy(0,1,0), fy(1,1,0), fy(0,0,1), fy(1,0,1), fy(0,1,1), fy(1,1,1)
fz(0,0,0), fz(1,0,0), fz(0,1,0), fz(1,1,0), fz(0,0,1), fz(1,0,1), fz(0,1,1), fz(1,1,1)
fxy(0,0,0), fxy(1,0,0), fxy(0,1,0), fxy(1,1,0), fxy(0,0,1), fxy(1,0,1), fxy(0,1,1), fxy(1,1,1)
fxz(0,0,0), fxz(1,0,0), fxz(0,1,0), fxz(1,1,0), fxz(0,0,1), fxz(1,0,1), fxz(0,1,1), fxz(1,1,1)
fyz(0,0,0), fyz(1,0,0), fyz(0,1,0), fyz(1,1,0), fyz(0,0,1), fyz(1,0,1), fyz(0,1,1), fyz(1,1,1)
fxyz(0,0,0), fxyz(1,0,0), fxyz(0,1,0), fxyz(1,1,0), fxyz(0,0,1), fxyz(1,0,1), fxyz(0,1,1), fxyz(1,1,1)

# Coefficient Order

1-D

pow(X,0), pow(X,1), pow(X,2), pow(X,3)

2-D

pow(X,0)*pow(Y,0), pow(X,1)*pow(Y,0), pow(X,2)*pow(Y,0), pow(X,3)*pow(Y,0)
pow(X,0)*pow(Y,1), pow(X,1)*pow(Y,1), pow(X,2)*pow(Y,1), pow(X,3)*pow(Y,1)
pow(X,0)*pow(Y,2), pow(X,1)*pow(Y,2), pow(X,2)*pow(Y,2), pow(X,3)*pow(Y,2)
pow(X,0)*pow(Y,3), pow(X,1)*pow(Y,3), pow(X,2)*pow(Y,3), pow(X,3)*pow(Y,3)

3-D

as follows..

