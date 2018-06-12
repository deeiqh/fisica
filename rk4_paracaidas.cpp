#include <iostream>
#include <math.h>
using namespace std;
double m=68.1,c=12.5,g=9.8;
double funcion(double x,double y){
    double a,v1=y;
    a=g+c*v1/m;
    return a;  //LA FUNCION ES G+C*V/M
}
double rungeKutta(double x,double y,double h){
    double k1,k2,k3,k4,mrk;
    k1=funcion(x,y);
    k2=funcion(x+h/2.0,y+h*k1/2.0);
    k3=funcion(x+h/2.0,y+h*k2/2.0);
    k4=funcion(x+h,y+h*k3);
    mrk=(k1+2*k2+2*k3+k4)/6.0;
    return mrk;
}


int main(){
    double x=0,y=0,mr;
    double xn=50,h=0.1,v;
    cout<<"RK \t SA"<<endl;
    while(x<xn){
        //y0=y;
        //x0=x;
        mr=rungeKutta(x,y,h);
        y=y+mr*h;
        v=g*m/c*(1-exp(-1*(c/m)*x));
        cout<<y<<"\t"<<v<<endl;
        x=x+h;
    }
    //PARACAIDISTA
    //v=g*m*(1-exp(-c*t/m))/c;
}
