#include <iostream>
#include <math.h>
#include <fstream>

using namespace std;

int main()
{	
	
	double v, t;
	double m = 68.1*2, c = 12.5;
	fstream tabla;

	tabla.open("data.txt", fstream::out);
	
	double a, b, b2 = -1, e, vel_const = 0.001, inc = 0.1;//INCREMENTO
	double v0 = 0, t0 = 0;
	int pasos =0;
	for(float t=0; ; t += inc){
		a = 9.8*(m/c)*(1-exp(-(c/m)*t));
		tabla<< "\t"<< t << "\t\t" << a;
		if(t == 0){
			b = 0; e = 0; 
		}
		else{
			b = v0 + (9.8-(c/m*v0))*(inc);
			e = ((b-a)/a)*100;
		}
		v0 = b;
		tabla << "\t\t" << b;		
		tabla << "\t\t" << e << " %\n";
		if(b2 == b ){cerr<< "ok";
			tabla<< "\t"<< t << "\t\t" << a;
			tabla << "\t\t" << b;		
			tabla << "\t\t" << e << " dfsdfdf%\n";
			break;		
		}
		b2 = b;
		pasos++;
		cout << "pasos... " << pasos << '\n';
	}
	
	tabla.close();
	return 0;
}
