#include<iostream>
#include<fstream>
#include<cstring>
using namespace std;

const int DIM_PAROLA = 50 + 1;
const char* PAROLA_STOP = "STOP";

int main(int argc, char* argv[]){
   if(argc!=3){
      cerr<<"Errore in input\n";
   }
   else{
      fstream input,output;
      input.open(argv[1],ios::in);
      output.open(argv[2],ios::out);
      if(input.fail()){
         cerr<<"Errore di file\n";
      }
      else{
         char ** file=new char*[DIM_PAROLA];
         char tmp[DIM_PAROLA];
         int lunghezza=0;
         input>>tmp;
         while(strcmp(tmp,PAROLA_STOP)!=0 || input.eof()){
            file[lunghezza]=new char[strlen(tmp)];
            strcpy(file[lunghezza],tmp);
            lunghezza++;
            input>>tmp;
         }
         for(int i=lunghezza-1;i>=0;--i){
            output<<file[i]<<" ";
         }
         for(int i=lunghezza-1;i>=0;--i){
            delete[] file[i];
         }
         delete[] file;
      }
      input.close();
      output.close();
   }
   return 0;
}
