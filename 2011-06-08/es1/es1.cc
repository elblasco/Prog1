#include<iostream>
#include<fstream>
#include<cstring>
using namespace std;

int main(int argc,char* argv[]){
   if(argc!=3){
      cerr<<"Errore in input\n";
   }
   else{
      fstream input,output;
      input.open(argv[1],ios::in);
      output.open(argv[2],ios::out);
      if(input.fail()){
         cerr<<"Errore nel file\n";
      }
      else{
         char tmp[256];
         while(!input.eof()){
            input.getline(tmp,256);
            for(int i=0;i<strlen(tmp);++i){
               if(tmp[i]!='\0'){
                  output<<(char)(tmp[i]+3);
               }
               else{
                  output<<tmp[i];
               }
            }
         }
      }
      input.close();
      output.close();
   }
   return 0;
}
