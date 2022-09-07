#include<iostream>
#include<fstream>
#include<cstring>
using namespace std;

const int DIM_PAROLA = 50 + 1;
const char* PAROLA_STOP = "STOP";

int min(int a,int b){
   return (a<b)?a:b;
}

int main(int argc, char* argv[]){
   if(argc!=4){
      cerr<<"Errore in input\n";
   }
   else{
      fstream input,output;
      input.open(argv[1],ios::in);
      output.open(argv[3],ios::out);
      if(input.fail()){
         cerr<<"Errore di file\n";
      }
      else{
         int righe=atoi(argv[2]);
         char **file=new char*[righe];
         char* tmp=new char[DIM_PAROLA];
         input.getline(tmp,DIM_PAROLA);
         int i=0;
         while(!input.eof() && i<=righe){
            file[i]=new char[strlen(tmp)+1];
            strcpy(file[i],tmp);
            input.getline(tmp,DIM_PAROLA);
            i++;
         }
         for(int x=min(i,righe)-1;x>=0;x--){
            if(x%2!=0){
               output<<file[x]<<"\n";
            }
            delete [] file[x];
         }

      }
      input.close();
      output.close();
   }
   return 0;
}
