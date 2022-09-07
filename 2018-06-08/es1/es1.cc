#include<iostream>
#include<fstream>
#include<cstring>
using namespace std;

const int MAXCHAR=256;

int main(int argc,char* argv[]){
   if(argc!=4){
         cerr<<"Errore in input\n";
   }
   else{
      fstream input1,input2,output;
      input1.open(argv[1],ios::in);
      input2.open(argv[2],ios::in);
      output.open(argv[3],ios::out);
      if(input1.fail() || input2.fail()){
         cerr<<"Errore nei file\n";
      }
      else{
         char tmp[MAXCHAR],tmp2[MAXCHAR];
         while(input1>>tmp){
            bool oltre=false;
            input2.open(argv[2],ios::in);
            while(input2>>tmp2 && !oltre){
               if(strcmp(tmp,tmp2)==0){
                  oltre=true;
                  output<<tmp<<'\n';
               }
            }
            input2.close();
         }
      }
      input1.close();
      output.close();
   }
   return 0;
}
