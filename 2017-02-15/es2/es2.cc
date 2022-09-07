#include <iostream>
using namespace std;
// Inserire qui sotto la dichiarazione della funzione
int* crea_vettore(int n);
int* crea_vettore_aux(int n, int* v, int i);

int main(){
   int N;
   cout << "Dimensione: ";
   cin >> N;
   if (N < 0) {
      cout << "Attenzione: inserire intero positivo!\n";
      return 1;
   }
   int* vector = crea_vettore(N);
   cout << "Array creato: ";
   for(int i=0; i<N; i++) {
      cout << vector[i] << " ";
   }cout << endl;
   delete[] vector;
   return 0;
}
// Inserire qui sotto la definizione della funzione crea_vettore

int* crea_vettore(int n){
   int *v=new int[n];
   return crea_vettore_aux(n,v,0);
}
int* crea_vettore_aux(int n, int* v,int i){
   if(i==n){
      return v;
   }
   else{
      v[i]=i*i;
      crea_vettore_aux(n,v,++i);
   }
}
