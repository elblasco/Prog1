#include <iostream>
using namespace std;

const int DIM = 81;
// Dichiarare qui sotto la funzione estrai

char* estrai(char *stringa);
void aux(char *stringa,char* &estratta,int i,int j);

int main () {
   char stringa[DIM], *estratta, risposta;
   do {cout << "Inserisci la stringa da controllare: ";
      cin >> stringa;
      estratta = estrai(stringa);
      cout << "La stringa estratta e': " << estratta << endl;
      cout << "Vuoi inserire un'altra stringa? [s/n] ";
      cin >> risposta;
   }while (risposta != 'n' && risposta != 'N');
   return 0;
}
// Definire qui sotto la funzione estrai

char* estrai(char *stringa){
   char* estratta = new char[DIM];
   aux(stringa,estratta,0,0);
   return estratta;
}

void aux(char *stringa,char* &estratta,int i,int j){
   if(stringa[i]=='\0' || i==DIM){
      estratta=new char[j];
   }
   else{
      if(stringa[i]>='A'&&stringa[i]<='Z'){
         aux(stringa,estratta,i+1,j+1);
         estratta[j]=stringa[i];
      }
      else{
         aux(stringa,estratta,i+1,j);
      }
   }
}
