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
	double v0 = 250 , theta = 37*3.1415/180, m = 0.1, d = 0.06, c = 0.1, p = 1.225, g = 9.8;
	double a = 3.1415*(d/2)*(d/2);
	double ax, ay;
	double x = 0, y = 0, vx, vy;
	
	fstream arch;
	arch.open("2d.txt", fstream::out);
	
	for(double t = 0; t != 30; t++){
		ax = -0.5/m*c*a*p*v0*v0*cos(theta);
		ay = -1*( g + (0.5/m*c*a*p*v0*v0*sin(theta)) );

		vx = v0*cos(theta) + ax*t;
		vy = v0*sin(theta) + ay*t;

		x = v0*cos(theta)*t + 0.5*(ax)*t*t;
		y = v0*sin(theta)*t + 0.5*(ay)*t*t;

		arch << t << '\t'<<x<<'\t'<<y<<'\t'<<vx<<'\t'<<vy<<'\t'<<'\n';
	}
	arch.close();
}
