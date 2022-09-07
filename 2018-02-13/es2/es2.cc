using namespace std;
#include <iostream>
const int DIM = 81;
// Dichiarare qui sotto la funzione estrai
char* estrai(char *stringa);
char* aux(char *stringa,char* estratta,int i,int j);

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
   char* estratta = new char[DIM + 1];
   return aux(stringa,estratta,0,0);
}

char* aux(char *stringa,char* estratta,int i,int j){
   if(stringa[i]=='\0' || i==DIM){
      return estratta;
   }
   else{
      if(stringa[i]>='A'&&stringa[i]<='Z'){
         estratta[j]=stringa[i];
         aux(stringa,estratta,i+1,j+1);
      }
      else{
         aux(stringa,estratta,i+1,j);
      }
   }
}
