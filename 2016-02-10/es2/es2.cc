#include <iostream>
#include <cstring>
using namespace std;
const char SEGNAPOSTO = '!';
const int DIMMAX = 40;
// Dichiarare qui sotto la funzione reverse_array
void reverse_array(char* input,int len);
bool is_vocale(char c);

int main (int argc, char* argv[]) {
   char input[DIMMAX];
   cout << "Introdurre stringa da invertire: ";
   cin >> input;
   // Assumiamo che sia sempre strlen(input) < DIMMAX
   reverse_array(input, strlen(input));
   cout << "Array invertito: " << input << endl;
   return 0;
}
// Definire qui sotto la funzione reverse_array
bool is_vocale(char c){
   return(c=='a' ||
         c=='e' ||
         c=='i' ||
         c=='o' ||
         c=='u');
}

void reverse_array(char* input,int len){
   if(len==0){
      return;
   }
   else if(is_vocale(input[len-1]) && is_vocale(input[0])){
      input[len-1]=SEGNAPOSTO;
      input[0]=SEGNAPOSTO;
   }
   else if(is_vocale(input[0])){
      input[0]=input[len-1];
      input[len-1]=SEGNAPOSTO;
   }
   else{
      char tmp=input[len-1];
      input[len-1]=input[0];
      input[0]=tmp;
   }
   reverse_array(input,len=len-1);
}
