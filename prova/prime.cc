#include <iostream>
#include <cmath>
#include <cstdlib>
using namespace std;

int main(int argc, char** argv){
    long long int big_number=atoi(argv[1]);

    while(big_number%2==0){
        cout<<2<<" ";
        big_number/=2;
    }

    for(int i=3;i<=sqrt(big_number);i=i+2){
        while(big_number % i==0){
            cout<<i<<" ";
            big_number/=i;
        }
    }

    if(big_number>2){
        cout<<big_number<<" ";
    }
    
    cout<<endl;
    return 0;
}