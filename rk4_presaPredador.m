clear all
 t0=0; tN=100;
 y0=[3,1]; 
 N=5000; h=1;
 y=y0;
 R(1)=y(1);
 F(1)=y(2);
 a=0.4; b=0.37; c=0.3; d=0.05; 

for n=1:N
         k1=[a*y(1)-c*y(1)*y(2);-b*y(2)+d*y(2)*y(1)];
     k2=[a*(y(1)+1/2*h*k1(1))-c*(y(1)+1/2*h*k1(1))*(y(2)+1/2*h*k1(2));-b*(y(2)+1/2*h*k1(2))+d*(y(2)+1/2*h*k1(2))*(y(1)+1/2*h*k1(1))];
     k3=[a*(y(1)+1/2*h*k2(1))-c*(y(1)+1/2*h*k2(1))*(y(2)+1/2*h*k2(2));-b*(y(2)+1/2*h*k2(2))+d*(y(2)+1/2*h*k2(2))*(y(1)+1/2*h*k2(1))];
     k4=[a*(y(1)+h*k3(1))-c*(y(1)+h*k3(1))*(y(2)+h*k3(2));-b*(y(2)+h*k3(2))+d*(y(2)+h*k3(2))*(y(1)+h*k3(1))];
     y=y+h/6*(k1+2*k2+2*k3+k4);
     R(n+1)=y(1);
     F(n+1)=y(2);
end

t=t0:h:tN;
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



