#include <iostream>
#include <cmath>
#include <fstream>

using namespace std;

int main()
{			
	
	fstream tabla;

	tabla.open("data.txt", fstream::out);
	
	double tiempo = 0, analitico = 0, aprox = 0, error = 0, incremento = 1;
	double v0 = 0, m = 68.1*2, c = 12.5;
	int pasos =0;
	
	tabla<< "\t"<< tiempo << "\t\t" << analitico << "\t\t" << aprox << "\t\t" << error << "%\n";
	
	for(tiempo=incremento; ; tiempo += incremento){
	
		analitico = 9.8*(m/c)*(1-exp(-(c/m)*tiempo));
		analitico = truncf(analitico*100)/100;

		aprox = aprox + (9.8-(c/m*aprox))*(incremento);
		aprox = truncf(aprox*100)/100;
		
		error = ((aprox-analitico)/analitico)*100;
                error = truncf(error*1000)/1000;
                
		tabla<< "\t"<< tiempo << "\t\t" << analitico << "\t\t" << aprox << "\t\t" << error << "%\n";
		
		if(abs(aprox-analitico) == 0) break;	
		
		pasos++;
		cout << "pasos... " << pasos << '\n';
	}
	
	tabla.close();
	return 0;
}
