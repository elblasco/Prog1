#include<iostream>
using namespace std;

int decToBin(int n){
   if(n==0){
      return 0;
   }
   else{
      return n%2+10*(decToBin(n/2));
   }
}

int main(){
   int n;
   cin>>n;
   cout<<decToBin(n)<<endl;
   return 0;
}
