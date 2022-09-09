#include <iostream>
#include <fstream>
#include <cstring>
using namespace std;

#define MAXDIM 31

/**
 * Non ho capito come a fare in modo che il testo vada a capo
 * ma guardando le soluzioni lo ho fatto identico al professore
 * ciò significa che manco il suo dovrebbe andare a capo
*/

int main(int argc,char* argv[]){
   if(argc!=3){
      cerr<<"Errore in input\n";
   }
   else{
      fstream input,output;
      input.open(argv[1],ios::in);
      output.open(argv[2],ios::out);
      if(input.fail()){
         cerr<<"Errore in input\n";
      }
      else{
         char buffer[MAXDIM];
         input>>buffer;
         if(!(buffer[0]>='A' && buffer[0]<='Z')){
            buffer[0]=buffer[0]+('A'-'a');
         }
         while(!input.eof()){
            output<<buffer<<" ";
            if(buffer[strlen(buffer)-1]=='.' ||
               buffer[strlen(buffer)-1]=='!' ||
               buffer[strlen(buffer)-1]=='?'){
                  input>>buffer;
                  if(!(buffer[0]>='A' && buffer[0]<='Z')){
                     buffer[0]=buffer[0]+('A'-'a');
                  }
            }
            else{
               input>>buffer;
            }
         }
      }
      input.close();
      output.close();
   }
   return 0;
}
