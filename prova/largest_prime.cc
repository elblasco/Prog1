#include <iostream>
#include <cmath>
#include <cstdlib>
using namespace std;

int main(int argc, char** argv){
    long long int big_number=atoi(argv[1]);
    int div=2;

    while(big_number%div==0){
        big_number/=div;
    }

    div++;

    for(;div<=sqrt(big_number);div+=2){
        while(big_number%div==0){
            big_number=big_number/div;
        }
    }

    div-=2;

    if(big_number%div==0 || big_number==1){
        cout<<div<<endl;
    }
    else{
       cout<<big_number<<" is prime\n"; 
    }
    return 0;
}