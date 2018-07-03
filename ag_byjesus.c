#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <limits.h>
#include "gnuplot_i.h"
#define pi 3.1415


typedef double number;
typedef unsigned char binary;

number f1(number x, number y){return 0.5f + ((pow(sin(sqrt(pow(x,2.0)+pow(y,2.0))),2.0) - 0.5f) / pow(1.0f + (0.0001f*(pow(x,2.0)+pow(y,2.0))),2.0));}
number f2(number x, number y){return 21.5f + (x*sin(4*pi*x)) + (y*sin(20*pi*y));}

int o_max(number x, number y){return x < y;}
int o_min(number x, number y){return x > y;}

int random_gen(int n){ return n*(float)rand()/(RAND_MAX + 1.0f); }
number random_number(number n){ return n*(number)rand()/(RAND_MAX + 1.0f); }

void GeneratePopulation(binary Arr[], int n, int BITS){
  for(int i = 0; i < n; ++i){
    Arr[i] = random_gen(pow(2.0,BITS));
    //printf("%d\t %d\n",i, Arr[i]);
  }
}
void EncodePopulation(number v1[], number v2[], number fv[], binary gen1[], binary gen2[], number a, number b, int n, int BITS, number (*f)(number,number), int c){
  for(int i = 0; i < n; ++i){
    v1[i] = a + b * gen1[i] / pow(2.0,BITS) - c;
    v2[i] = a + b * gen2[i] / pow(2.0,BITS) - c;
    fv[i] = f(v1[i],v2[i]);
    //printf("%d\t %d\t %d\t %f\t %f\t %f\n",i,gen1[i], gen2[i],v1[i],v2[i],fv[i]);
  }
}
void MediaPopulation(number v1[], number v2[], number fv[], binary gen1[], binary gen2[], number a, number b, int n, int BITS, number (*f)(number,number), int (*optimization)(number,number), int c, number *sum, number *tem,number *px, number *py){
  if(*optimization == o_max)
    *tem = a;
  else
    *tem = b;
  number t = 0;
  for(int i = 0; i < n; ++i){
    v1[i] = a + b * gen1[i] / (pow(2.0,BITS) - c);
    v2[i] = a + b * gen2[i] / (pow(2.0,BITS) - c);
    fv[i] = f(v1[i],v2[i]);
    printf("%d\t %d\t %f\t %f\t %f\n",gen1[i], gen2[i], v1[i], v2[i], fv[i]);
    if(!optimization(fv[i],*tem)){
      *tem = fv[i];
      *px = v1[i];
      *py = v2[i];
    }
    t += fv[i];
  }
  *sum = t/n;
}
void SortGenes(binary G1[], binary G2[], number Arr[], int N, int (*optimization)(number,number)){
  number tem1,tem2,tem3;
  for(int j = 0; j < N - 1; j++)
    for(int i = j + 1; i < N; i++)
      if (!optimization(Arr[j],Arr[i])){
        tem1 = Arr[j];
        Arr[j] = Arr[i];
        Arr[i] = tem1;
        tem2 = G1[j];
        G1[j] = G1[i];
        G1[i] = tem2;
        tem3 = G2[j];
        G2[j] = G2[i];
        G2[i] = tem3;
      }
}
void Cross(binary G1[], binary G2[], binary H1[], binary H2[], int N, int BITS){
  int k = random_gen(BITS);
  int i, sos,h = BITS;
  number tem, pc = 0.8;
  binary P0,P1,P2,P3;
  for(i = 0, sos = 0; i < N; i += 2){
    tem = random_number(1.0);
    if(tem < pc){
      P0 = G1[i]>>(h-k);
      P0 = P0<<(h-k);
      P2 = G2[i]>>(h-k);
      P2 = P2<<(h-k);

      P1 = G1[i+1]<<(k);
      P1 = P1>>(k);
      H1[i] = P0 | P1;
      P3 = G2[i+1]<<(k);
      P3 = P3>>(k);
      H2[i] = P2 | P3;

      P1 = G1[i+1]>>(h-k);
      P1 = P1<<(h-k);
      P3 = G2[i+1]>>(h-k);
      P3 = P3<<(h-k);

      P0 = G1[i]<<(k);
      P0 = P0>>(k);
      H1[i+1] = P1 | P0;
      P2 = G2[i]<<(k);
      P2 = P2>>(k);
      H2[i+1] = P3 | P2;
      //printf("%d\t %d\t %d\t %d\n",H1[i],H1[i+1],H2[i],H2[i+1]);
      sos++;
    }
    else{
      H1[i] = G1[i];
      H1[i+1] = G1[i+1];
      H2[i] = G2[i];
      H2[i+1] = G2[i+1];
    }
  }
}
void Mutation(binary H[], int N, int BITS){
  int mas, h = BITS;
  number pm = 0.002, tem;
  for(int j = 0; j < N; j++)
    for(int i = 0; i < h; i++){
      tem = random_number(1.0);
      if(tem < pm){
        mas = 1;
        mas = mas << i;
        H[j] = H[j] ^ mas;
      }
    }
}

void AG_FunctionXYZ_Optimization(int N, int BITS, int GEN, number a, number b, number (*f)(number,number),int (*optimization)(number,number)){
  gnuplot_ctrl    *h1;
	h1 = gnuplot_init() ;
  gnuplot_setstyle(h1, "lines") ;
  number Z[N], X[N], Y[N], best[GEN], prom[GEN];//GEN = generacion, el x mejor en cada generacion
  binary genX[N], genY[N], genSelX[N], genSelY[N], HX[N], HY[N];
  number suma = 0, temp = 0, px,py;
  number RX[GEN], RY[GEN];
  //**Generating initial population**//
  GeneratePopulation(genX,N,BITS);
  GeneratePopulation(genY,N,BITS);
  EncodePopulation(X,Y,Z,genX,genY,a,b-a,N,BITS,f,0);
  number tem;
  number SumAcc[N], sumTemp = 0;
  for(int ii = 0; ii < GEN; ++ii){
    //*Sort genes *//
    SortGenes(genX,genY,Z,N,optimization);
    for(int i = 0; i < N; ++i)
      printf("%d\t %d\n",genX[i], genY[i]);
    //**Montecarlo Selection**//
    sumTemp = 0;
    for(int i = 0; i < N; ++i){
      sumTemp += Z[i];
      SumAcc[i] = sumTemp;
    }
    for(int j = 0; j < N; j++){
			tem = random_number(1.0) * sumTemp;
			for(int i = 0; i < N; i++)
				if(SumAcc[i] > tem && SumAcc[i+1] < tem){
				  genSelX[j] = genX[i];
          genSelY[j] = genY[i];
        }
		}
    for(int j = 0; j < N; j++){
      genX[j] = genSelX[j];
      genY[j] = genSelY[j];
      printf("%d\t %d\n", genX[j], genY[j]);
    }
    EncodePopulation(X,Y,Z,genX,genY,a,b-a,N,BITS,f,1);
    SortGenes(genX,genY,Z,N,optimization);
    Cross(genX,genY,HX,HY,N,BITS);
    Mutation(HX,N,BITS);
    Mutation(HY,N,BITS);
    printf("%d\n", ii);
    MediaPopulation(X,Y,Z,HX,HY,a,b-a,N,BITS,f,optimization,1,&suma,&temp,&px,&py);
    printf("%f\t %f\t %f\t %f\n", suma, temp, px, py);
    best[ii] = temp;
    prom[ii] = suma;
    RX[ii] = px;
    RY[ii] = py;
    for(int i = 0; i < N; i++){
      genX[i] = HX[i];
      genY[i] = HY[i];
    }
  }
  number xx[GEN];
  for(int i = 0; i < GEN; ++i)
    xx[i] = i;
  gnuplot_plot_xy(h1, xx, prom, GEN, "Valor promedio") ;
  gnuplot_plot_xy(h1, xx, best, GEN, "Valor encontrado") ;
  sleep(30) ;
  gnuplot_close(h1);
}


int main(){
  //printf("%f\n", f2(110,190));
  AG_FunctionXYZ_Optimization(200,4,100,-200,200,f2,o_max);//poblacion de 200, 4 bits (2^4), 100 generaciones
  printf("%s\n", "finish");
  return 0;
}
