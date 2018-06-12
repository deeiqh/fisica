#include <iostream>
#include <fstream>

using namespace std;

int main()
{
    fstream archivos;
    float t;
    
    archivos.open("xt_persona.txt", fstream::out);
    for (int t = 0; t != 30; t++){
        archivos << t << ' ' << 8*t <<'\n';
    }
    archivos.close();
    cout << "xt_persona.txt...\n";
    
    archivos.open("xt_tren.txt", fstream::out);
    for (int t = 0; t != 30; t++){
        archivos << t << ' ' << 30*t+0.5*t*t <<'\n';
    }
    archivos.close();
    cout << "xt_tren.txt...\n";
}
