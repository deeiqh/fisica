#include <iostream>
#include <math.h>
#include <fstream>

using namespace std;

int main()
{	
	int lim = 13;
	double v, t;
	double m = 68.1, c = 12.5;
	fstream tabla;

	tabla.open("data.txt", fstream::out);
	
	double a, b, b2 = -1, e, vel_const = 0.001, inc = 0.1;//INCREMENTO
	double v0 = 0, t0 = 0;
	int pasos =0;
	for(float t=0; t < lim; t += inc){
		a = 53.39*(1-exp(-0.18355*t));
		tabla << t << '\t' << a;
		if(t == 0){
			b = 0;
		}
		else
			b = v0 + (9.8-(c/m*v0))*(inc);
		v0 = b;
		tabla << '\t' << b;
		e = ((b-a)/a)*100;
		tabla << '\t' << e << " %\n";
		if(b2 == b ) break;
		b2 = b;
		pasos++;
		cout << "pasos... " << pasos << '\n';
	}
	
	tabla.close();
	return 0;
}
