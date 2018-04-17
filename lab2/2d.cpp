/*

Fx = Fairecos0(CApv) -> v -> v0 ->vx
Fy = Fairesen0 + mg 

*/

#include<iostream>
#include<cmath>
#include<fstream>

using namespace std;

int main()
{
	double v0 = 25 , theta = 37, m = 0.1, d = 0.06, c = 12.5, p = 1.225, g = 9.8;
	double a = 3.1415*(d/2)*(d/2);
	double ax, ay;
	double x = 0, y = 0, vx, vy;
	
	fstream arch;
	arch.open("2d.txt", fstream::out);
	
	for(double t = 0; t != 30; t++){
		ax = 0.5/m*c*a*p*v0*v0*cos(theta);
		vx = (v0 + ax*t)*cos(theta);
		vy = (v0 + ax*t)*sin(theta);
		x = vx*t - 0.5*(0.5/m*c*a*p*v0*v0*cos(theta))*t*t;
		y = vy*t - 0.5*(g+(0.5/m*c*a*p*v0*v0*sin(theta)))*t*t;
		arch << t << ' '<<x<<' '<<y<<' '<<vx<<' '<<vy<<' '<<'\n';
	}
	arch.close();
}
