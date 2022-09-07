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

int main(){
   int n;
   cin>>n;
   cout<<binToDec(n)<<endl;
   return 0;
}