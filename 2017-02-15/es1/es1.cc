#include<iostream>
#include<fstream>
#include<cstring>
using namespace std;

const int DIM_PAROLA = 50 + 1;
const char* STOP = "STOP";

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
         int lunghezza=0;
         char tmp_buffer[DIM_PAROLA];
         input>>tmp_buffer;

         while ((!input.eof()) && (strcmp(tmp_buffer,STOP)!=0)){
            lunghezza++;
            input>>tmp_buffer;
         }
         
         input.close();
         input.open(argv[1],ios::in);
         char ** file=new char*[lunghezza];

         for(int i=0;i<lunghezza;++i){
            file[i]=new char[50];
            input>>file[i];
         }

         for(int i=lunghezza-1;i>=0;--i){
            output<<file[i]<<" ";
            cout<<file[i]<<" ";
         }

         for(int i=lunghezza-1;i>=0;--i){
            delete[] file[i];
         }
         
         delete[] file;
         input.close();
      }
      output.close();
   }
   return 0;
}
