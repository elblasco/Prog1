#include<iostream>
#include<fstream>
#include<cstring>
using namespace std;

const int PAROLE=1000;
const int CARATTERI=101;

char toLower(char c){
   if(c>='A' && c<='Z'){
      c=(c-'A')+'a';
   }
   return c;
}

bool isPresent(char paro[CARATTERI],char voca[PAROLE][CARATTERI],int lung){
   bool left=false;
   for(int i=0;i<lung && !left;++i){
      if(strlen(paro)==strlen(voca[i])){
         bool uguali=true;
         for(int j=0;j<strlen(paro)&&uguali;++j){
            if(toLower(paro[j])!=toLower(voca[i][j])){
               uguali=false;
            }
         }
         left=uguali;
      }
   }
   return left;
}

int main(int argc,char* argv[]){
   if(argc!=4){
      cerr<<"errore in input\n";
   }
   else{
      fstream input,vocabolario,output;
      input.open(argv[1],ios::in);
      vocabolario.open(argv[2],ios::in);
      output.open(argv[3],ios::out);
      if(input.fail() || vocabolario.fail()){
         cerr<<"errore nei file\n";
      }
      else{
         char matriceVocabolario[PAROLE][CARATTERI];
         int lunghezza=0;
         while(vocabolario>>matriceVocabolario[lunghezza]){
            ++lunghezza;
         }
         char tmp[CARATTERI];
         while(input>>tmp){
            if(isPresent(tmp,matriceVocabolario,lunghezza)){
               for(int i=0;i<strlen(tmp);++i){
                  output<<"X";
               }
               output<<" ";
            }
            else{
               output<<tmp<<" ";
            }
         }
      }
      input.close();
      output.close();
      vocabolario.close();
   }
   return 0;
}
