#include <iostream>
#include <fstream>
#include <cstring>
#include <cstdlib>
using namespace std;

const int DIM_RIGA=256;

int main(int argc,char* argv[]){
   if(argc!=4){
      cerr<<"Errore in input\n";
   }
   else{
      fstream input,output;
      input.open(argv[1],ios::in);
      output.open(argv[3],ios::out);
      if(input.fail()){
         cerr<<"Errore nel file\n";
      }
      else{
         char tmp[DIM_RIGA];
         int righe=atoi(argv[2]);
         char **file=new char*[righe];
         int i=0;
         for(;i<righe;++i){
            input.getline(tmp,DIM_RIGA);
            file[i]=new char[strlen(tmp)];
            for(int j=0;tmp[j]!='\0';++j){
               if(tmp[j]==' '||tmp[j]=='\t'){
                  file[i][j]=tmp[j];
               }
               else{
                  file[i][j]=(j%2!=0?'+':'*');
               }
            }
            file[i][strlen(tmp)]='\0';
         }
         i=i-1;;
         for(;i>=0;--i){
            output<<file[i]<<endl;
         }
         for(int x=0;x<righe;++x){
            delete[] file[x];
         }
         delete[] file;
      }
      input.close();
      output.close();
   }
   return 0;
}
