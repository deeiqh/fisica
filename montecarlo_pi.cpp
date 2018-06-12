#include <iostream>
#include <cstdlib>
#include <ctime>
#include <cmath>
#include <fstream>
using namespace std;
ofstream archivo;
void valorPI(int N){
    int n;
    double x,y,R,PI,suma,prom;
    srand(time(NULL));
    suma=0;
    for (int j=0;j<20;j++)
    {
    n=0;
    for (int i=0;i<N;i++){
        x=2.0*rand()/(RAND_MAX+1.0)-1.0;
        y=2.0*rand()/(RAND_MAX+1.0)-1.0;
        R=sqrt(x*x+y*y);
        if (R<=1.0)    n++;
        cout<<x<<"\t"<<y<<endl;
    }
    PI=4.0*n/N;
    suma+=PI;
    }

    prom=suma/20.0;
    cout<<prom<<endl;
}


int main(){
    archivo.open("datos.txt");
    int N=100;
    /*
    while (N<1000){
        valorPI(N);
        N++;
    }
    */
    valorPI(N);
}
