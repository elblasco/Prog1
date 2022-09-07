#include<iostream>
#include<fstream>
#include<string>
using namespace std;

#define MAXDIM 256

int strlen(char* str){
   return *str!='\0' ? strlen(str+1)+1:-1;
}

int main(int argc, char** argv){
   if(argc!=3){
      cerr<<"Errore nel numero di input\n";
      exit(1);
   }
   else{
      fstream input,output;
      input.open(argv[1],ios::in);
      output.open(argv[2],ios::out);
      if(input.fail()){
         cerr<<"Errore nell'apertura del file\n";
         exit(2);
      }
      else{
         char buffer[MAXDIM];
         while(!input.eof()){
            input.getline(buffer,MAXDIM);
            for(int i=0;i<strlen(buffer);++i){
               if(buffer[i]!='\0'){
                  output<<(char) (buffer[i]+3);
               }
            }
            output<<'\n';
         }
      }
      input.close();
      output.close();
   }
   return 0;
}