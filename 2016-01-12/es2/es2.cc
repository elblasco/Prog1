#include <iostream>
using namespace std;

void stampa_array(int array[], int dim);
void somma_array(int n1[], int n2[], int risultato[], int dim);
void somma_array_aux(int n1[], int n2[], int risultato[], int dim,int i);
const int SIZE = 10;

int main() {
   int ar1[] = {5, 9, 2, 7, 10, 15, 3, 8, 4, 12};
   int ar2[] = {6, 3, 21, 1, 17, 11, 24, 9, 8, 19};
   int ar3[SIZE];
   cout << "Array1 = ";
   stampa_array(ar1, SIZE);
   cout << endl;
   cout << "Array2 = ";
   stampa_array(ar2, SIZE);
   cout << endl;
   somma_array(ar1, ar2, ar3, SIZE);
   cout << "Somma  = ";
   stampa_array(ar3, SIZE);
   cout << endl;
   return 0;
}

void stampa_array(int array[], int dim) {
   for (int i = 0; i < dim; i++) {
      cout << array[i] << " ";
   }
}
// Inserire qui la definizione della funzione somma_array
void somma_array(int n1[], int n2[], int risultato[], int dim){
   somma_array_aux(n1,n2,risultato,dim,0);
}

void somma_array_aux(int n1[], int n2[], int risultato[], int dim,int i){
   if(i==dim){
      return;
   }
   else{
      risultato[i]=n1[i]+n2[i];
      somma_array_aux(n1,n2,risultato,dim,i=i+1);
   }
}
