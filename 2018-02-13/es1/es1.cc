#include<iostream>
#include<fstream>

using namespace std;

const int DIM=82;

int lunghezza(char* mail){
   int i=0;
   for(;mail[i]!='\0';++i){

   }
   return i;
}

bool corretta(char* mail){
   bool ok=true;
   int atCounter=0;
   if(lunghezza(mail)<2){
      cout<<"Troppo poco lungo\n";
      ok=false;
   }
   if(mail[0]=='.'|| mail[lunghezza(mail)-1]=='.'){
      cout<<"Troppi punti\n";
      ok=false;
   }
   else{
      for(int i=0;mail[i]!='\0' && ok && atCounter<=1;++i){
         if(mail[i]=='@'){
            atCounter++;
         }
         if((mail[i]>='A'&&mail[i]<='Z')
            ||(mail[i]>='a'&&mail[i]<='z')
            ||(mail[i]>='0'&&mail[i]<='9')
            ||(mail[i]=='_') || mail[i]=='@' || mail[i]=='.'){
            ok=true;
         }
         else{
            cout<<"carattere illegale\n";
            ok=false;
         }
      }
   }
   if(atCounter>1){
      cout<<"Troppe chiocciole\n";
      ok=false;
   }
   return ok;
}

int main(int argc,char *argv[]){
   if(argc!=3){
      cerr<<"Eoore in input";
   }
   else{
      fstream input,output;
      input.open(argv[1],ios::in);
      output.open(argv[2],ios::out);
      if(input.fail()){
         cerr<<"Errore nel file";
      }
      else{
         char tmp[DIM];
         while(input>>tmp){
            if(corretta(tmp)){
               output<<tmp<<'\n';
            }
         }
      input.close();
      output.close();
      }
   }
   return 0;
}
