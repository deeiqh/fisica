
clear all

t0=0; tn=100; 
 y0=[0.250;1]; 
 N=5000; h=(tn-t0)/N;
 y=y0; 
 R(1)=y(1); 
 F(1)=y(2); 
 A=[0.4 0;0 -0.37]; 

 for i=1:N
     y=y+h*(A*y+y(1)*y(2)*[-0.3;0.05]); 
     R(i+1)=y(1);
     F(i+1)=y(2);
 end
 t=t0:h:tn;

 figure(1)
 hold on
 plot(t,R,"linewidth", 3,'b') 
 plot(t,F,"linewidth", 3,'r')
 title('Población de conejos y zorros en función del tiempo, azul y rojo respectivamente');
 ylabel('miles');
 xlabel('años');
 hold off
 figure(2)
 plot(R,F,"linewidth", 3,'000000') 
 title('Población de zorros vs conejos');
 xlabel('Conejos(miles)');
 ylabel('Zorros (miles)');



















using namespace std;

int main()
{		
    /*	
	R′(t)=aR(t)−cR(t)F(t)
    F′(t)=−bF(t)+dR(t)F(t)
	*/
	
	double a = 0.4;
	double b = 0.37;
	double c = 0.3;
	double d = 0.05;
	
	double ti = 0;
	double tf = 100;
	
	int n = 5000;
	
	long r = 3;
	long f = 1;
	
	double intervalo = (tf-ti)/n;
	
	long r_;
	for(int i = 1; i <= n; i++){
	    //R(tiempoi+intervalo)
	    r_ = r;
	    r = r + a*r -c*r*f;
	    f = f - b*f + d*r_*f;
	}
	
	
	fstream tabla;
	tabla.open("data.txt", fstream::out);
	tabla.close();
	return 0;
}
