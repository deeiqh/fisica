#include <iostream>
#include <fstream>

using namespace std;

int main()
{
    fstream archivo_persona;
    fstream archivo_tren;
    float t;
    
    archivo_persona.open("tx_persona.txt", fstream::out);
    archivo_tren.open("tx_tren.txt", fstream::out);
    
    float a, b, d;
    for (int t = 0; t != 30; t++){
        a = 8*t;
        archivo_persona << t << ' ' << a<<' ';
        b = 30+0.5*t*t;
        archivo_tren << t << ' ' << b <<'\n';
        d = b - a;
        archivo_persona << d <<'\n';
        if (a == b) cout << "alcance a "<< t << " s, "<< a << " m.\n";
    }
    
    archivo_persona.close();
    cout << "tx_persona.txt\n";
    archivo_tren.close();
    cout << "tx_tren.txt\n";    
    cout << "gnuplot... plot 'tx_persona.txt' using 1:2, 'tx_tren.txt' using 1:2, 'tx_persona.txt' using 1:3" << '\n';
}
