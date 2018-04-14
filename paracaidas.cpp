#include <iostream>
#include <cmath>
#include <fstream>

using namespace std;

int main()
{			
	
	fstream tabla;

	tabla.open("data.txt", fstream::out);
	
	double tiempo = 0, analitico = 0, aprox = 0, error = 0, incremento = 0.1;
	double v0 = 0, m = 68.1, c = 12.5*2;
	int pasos =0;
	
	tabla<< "\t"<< tiempo << "\t\t" << analitico << "\t\t" << aprox << "\t\t" << error << "%\n";
	
	for(tiempo=incremento; ; tiempo += incremento){
	
		analitico = 9.8*(m/c)*(1-exp(-(c/m)*tiempo));		
		
		aprox = aprox + (9.8-(c/m*aprox))*(incremento);
		
		error = ((aprox-analitico)/analitico)*100;
                
		tabla<< "\t"<< tiempo << "\t\t"<< truncf(analitico*10000)/10000<<"\t\t"<< truncf(aprox*10000)/10000 << "\t\t" << error << "%\n";
		
		pasos++;
		if(abs(aprox-analitico) <= 0.00001) break;				
	}
	
	cout << "pasos... " << pasos << '\n';
	tabla.close();
	return 0;
}
