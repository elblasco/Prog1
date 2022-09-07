#include <iostream>
#include <fstream>
using namespace std;

const int PAROLE=1000;
const int CARATTERI=101;

int strlen(char parola[CARATTERI]){
   int i=0;
   for(;parola[i]!='\0';){
      ++i;
   }
   return i;
}

int main(int argc, char * argv []){
   if(argc!=3){
      cerr<<"Errore in input\n";
   }
   else{
      fstream input,output;
      input.open(argv[1],ios::in);
      output.open(argv[2],ios::out);
      if(input.fail()){
         cerr<<"Errore nei file\n";
      }
      else{
         char file[PAROLE][CARATTERI];
         int lunghezza=0;
         while(input>>file[lunghezza]){
            ++lunghezza;
         }
         for(;lunghezza>=0;--lunghezza){
            if(strlen(file[lunghezza])%2==0){
               output<<file[lunghezza]<<" ";
            }
         }
      }
      input.close();
      output.close();
   }
  return 0;
}
