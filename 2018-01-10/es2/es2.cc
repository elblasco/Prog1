#include <iostream>
using namespace std;
// Inserire qui le DICHIARAZIONI delle funzioni
int somma_prodotto_incrociato(int* v1,int* v2,int dim);
int somma_prodotto_aux(int* v1,int* v2,int dim,int i);
int main() {
   int primo[10] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
   int secondo[10] = {1, 1, 2, 3, 5, 8, 13, 21, 34, 55};
   cout << "La somma dei prodotti incrociati dei due array e' " <<somma_prodotto_incrociato(primo, secondo, 10) << endl;
   return 0;
}
// Inserire qui le DEFINIZIONI delle funzioni
int somma_prodotto_incrociato(int* v1,int* v2,int dim){
   return somma_prodotto_aux(v1,v2,dim-1,0);
}

int somma_prodotto_aux(int* v1,int* v2,int dim,int i){
   if(dim<0){
      return 0;
   }
   else{
      cout<<"dim= "<<dim;
      cout<<"i= "<<i;
      return (v1[i]*v2[dim])+somma_prodotto_aux(v1,v2,dim=dim-1,i=i+1);
   }
}
