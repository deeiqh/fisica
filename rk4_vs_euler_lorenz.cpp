#include <iostream>
#include <math.h>
#include <fstream>
using namespace std;
ofstream archivo;
double funcion1(double t,double x,double y);
double funcion2(double t,double x,double y,double z);
double funcion3(double t,double x,double y,double z);

double rk41(double x,double y1,double y2,double h);
double rk42(double x,double y1,double y2,double y3,double h);
double rk43(double x,double y1,double y2,double y3,double h);

int main(){
    archivo.open("datos4.txt");
    int i,j,k,l,N,n;
    double x,y1,y2,y3,xi,xf,h,f1,f2,f3,M;
    xi=0;
    xf=20.0;
    y1=5.0;
    y2=5.0;
    y3=5.0;

    N=5000;

    h=0.001;
    M=xf/N;
    i=0;

    //double x0=y1,y0=y2,z0=y3;

    for(x=xi;x<=xf;x+=h){
        f1=rk41(x,y1,y2,h);
        f2=rk42(x,y1,y2,y3,h);
        f3=rk43(x,y1,y2,y3,h);
        //cout<<f1<<"\t"<<f2<<"\t"<<f3;
        y1=y1+f1*h;
        y2=y2+f2*h;
        y3=y3+f3*h;
        archivo<<i<<"\t"<<y1<<"\t"<<y2<<"\t"<<y3<<endl;

        /*
        //EULER.
        double auxx=x0,auxy=y0,auxz=z0;
        x0=auxx+(10.0*(auxy-auxx))*h;
        y0=auxy+(-auxx*auxz+28.0*auxx-auxy)*h;
        z0=auxz+(auxx*auxy-2.666667*auxz)*h;
        archivo<<i<<"\t"<<x0<<"\t"<<y0<<"\t"<<z0<<endl;
        */

        i++;
    }
}
double funcion1(double t,double x,double y){
    return 10.0*(y-x);
}
double funcion2(double t,double x,double y,double z){
    return -x*z+28.0*x-y;
}
double funcion3(double t,double x,double y,double z){
    return x*y-2.666667*z;
}

double rk41(double x,double y1,double y2,double h){
    double ym1,ym2,k1,k2,k3,k4,sum,ye1,ye2,sos;
    k1=funcion1(x,y1,y2);
    ym1=y1+k1*h/2.0;
    ym2=y2+k1*h/2.0;
    k2=funcion1(x+h/2.0,ym1,ym2);
    ym1=y1+k2*h/2.0;
    ym2=y2+k2*h/2.0;
    k3=funcion1(x+h/2.0,ym1,ym2);
    ye1=y1+k3*h;
    ye2=y2+k3*h;
    k4=funcion1(x+h,ye1,ye2);
    sum=(k1+2.0*(k2+k3)+k4)/6.0;
    return sum;
    x=x+h;
}

double rk42(double x,double y1,double y2,double y3,double h){
    double ym1,ym2,ym3,k1,k2,k3,k4,sum,ye1,ye2,ye3,sos;
    k1=funcion2(x,y1,y2,y3);
    ym1=y1+k1*h/2.0;
    ym2=y2+k1*h/2.0;
    ym3=y3+k1*h/2.0;
    k2=funcion2(x+h/2.0,ym1,ym2,ym3);
    ym1=y1+k2*h/2.0;
    ym2=y2+k2*h/2.0;
    ym3=y3+k2*h/2.0;
    k3=funcion2(x+h/2.0,ym1,ym2,ym3);
    ye1=y1+k3*h;
    ye2=y2+k3*h;
    ye3=y3+k3*h;
    k4=funcion2(x+h,ye1,ye2,ye3);
    sum=(k1+2.0*(k2+k3)+k4)/6.0;
    return sum;
    x=x+h;
}

double rk43(double x,double y1,double y2,double y3,double h){
    double ym1,ym2,ym3,k1,k2,k3,k4,sum,ye1,ye2,ye3,sos;
    k1=funcion3(x,y1,y2,y3);
    ym1=y1+k1*h/2.0;
    ym2=y2+k1*h/2.0;
    ym3=y3+k1*h/2.0;
    k2=funcion3(x+h/2.0,ym1,ym2,ym3);
    ym1=y1+k2*h/2.0;
    ym2=y2+k2*h/2.0;
    ym3=y3+k2*h/2.0;
    k3=funcion3(x+h/2.0,ym1,ym2,ym3);
    ye1=y1+k3*h;
    ye2=y2+k3*h;
    ye3=y3+k3*h;
    k4=funcion3(x+h,ye1,ye2,ye3);
    sum=(k1+2.0*(k2+k3)+k4)/6.0;
    return sum;
    x=x+h;
}
