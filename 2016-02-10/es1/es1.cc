#include <iostream>
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
         cerr<<"Errore in input\n";
      }
      else{
         char tmp[31];
         input>>tmp;
         tmp[0]=tmp[0]+('A'-'a');
         output<<tmp<<" ";
         while(input>>tmp){
            output<<tmp<<" ";
            if(tmp[strlen(tmp)-1]=='.'||
               tmp[strlen(tmp)-1]=='?'||
               tmp[strlen(tmp)-1]=='!'){
                  if(!(tmp[0] >= 'A' && tmp[0] <= 'Z')){
                     output<<'\n';
                     outpu<<tmp;
                     tmp[0] = tmp[0] + ('A'-'a');
                     output<<tmp<<" ";
                  }
            }
         }
      }
      input.close();
      output.close();
   }
   return 0;
}
