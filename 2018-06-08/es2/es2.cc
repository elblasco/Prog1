using namespace std;
#include <iostream>
// Inserire qui sotto la dichiarazione della funzione shift
int* shift(int* v, int n,int j);
void aux(int* v, int n,int j,int i,int* &a);

int main(){
   int J = 0;
   const int N = 15;
   int vector[] = {2, 17, 44, 202, 5, 13, 26, 7, 9, 131, 51, 79, 88, 96, 32};
   cout << "Array iniziale: ";
   for(int i=0; i<N; i++) {
      cout << vector[i] << " ";
   }
   cout << endl;
   cout << "Numero spostamenti a sinistra: ";
   cin >> J;
   int* new_vect = shift(vector, N, J);
   cout << "Nuovo array: ";
   for(int i=0; i<N; i++) {
      cout << new_vect[i] << " ";
   }
   cout << endl;
   delete[] new_vect;
   return 0;
}

// Inserire qui sotto la definizione della funzione shift
int* shift(int* v, int n,int j){
   int* array=new int[n];
   aux(v,n,j,0,array);
   return array;
}
void aux(int* v, int n,int j,int i,int* &a){
   if(i>=n){
      a=new int[n];
   }
   else if(i+j<n){
      aux(v,n,j,i+1,a);
      a[i]=v[i+j];
   }
   else{
      aux(v,n,j,i+1,a);
      a[i]=0;
   }
}
