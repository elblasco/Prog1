#include<iostream>
using namespace std;

//Inserire qui la dichiarazione della funzione calcola_somma
void calcola_somma(int a ,int b,int &res);

int main(){
   int res=0;
   int x1,x2;
   do{
      cout<<"Inserire il primo numero: ";
      cin>>x1;
      cout<<"Inserire il secondo numero: ";
      cin>>x2;
   }while(x1>x2);
   calcola_somma(x1,x2,res);
   cout<<"Sommatoria dei numeri compresi tra "<<x1<<" e "<<x2<<" = ";
   cout<<res<<endl;
   return 0;
}

//Inserire qui la definizione della funzione calcola_somma
void calcola_somma(int a ,int b,int &res){
   if(b==a){
      res+=b;
   }
   else{
      res+=b;
      calcola_somma(a,b-1,res);
   }
}