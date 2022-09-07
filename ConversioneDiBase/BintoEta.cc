#include<iostream>
using namespace std;

int binToDec(int n){
   if(n==0){
      return 0;
   }
   else{
      return (n%10+2*binToDec(n/10));
   }
}

int binToEta(int n){
   if(n==0){
      return 0;
   }
   else{
      int tmp=n%1000;
      tmp=binToDec(tmp);
      return tmp+(binToEta(n/1000)*10);
   }
}

int main(){
   int n;
   cin>>n;
   cout<<binToEta(n)<<endl;
   return 0;
}
