#include <iostream>
#include <cmath>
#include <fstream>

using namespace std;

int main()
{			
	
	fstream tabla;

	tabla.open("data.txt", fstream::out);
	
	double tiempo = 0, analitico = 0, aprox = 0, error = 0, incremento = 2;
	double v0 = 0, m = 68.1, c = 12.5;
	int pasos =0;
	
	tabla<< "\t"<< tiempo << "\t\t" << analitico << "\t\t" << aprox << "\t\t" << error << "%\n";
	
	for(tiempo=incremento; ; tiempo += incremento){
	
		analitico = 9.8*(m/c)*(1-exp(-(c/m)*tiempo));
		analitico = truncf(analitico*1000)/1000;
		
		aprox = aprox + (9.8-(c/m*aprox))*(incremento);
		
		error = ((aprox-analitico)/analitico)*100;
                error = truncf(error*1000)/1000;
                
		tabla<< "\t"<< tiempo << "\t\t" << analitico << "\t\t" <<  truncf(aprox*1000)/1000 << "\t\t" << error << "%\n";
		
		pasos++;
		cerr << aprox;
		if(abs(aprox-analitico) <= 0.001) break;	
		
				
	}
	
	cout << "pasos... " << pasos << '\n';
	tabla.close();
	return 0;
}
