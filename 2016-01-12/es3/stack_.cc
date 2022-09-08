#include"stack.h"
#include<iostream>
using namespace std;

void init(stack &s, int maxdim){
    s.index=0;
    s.dim=maxdim;
    s.elem=new double[maxdim];
}

void deinit(stack &s){
    delete[] s.elem;
}

bool push(stack &s, double n){
    bool result;
    if(s.index==s.dim){
        result=false;
    }
    else{
        s.elem[s.index]=n;
        s.index++;
        result=true;
    }
    return result;
}

bool top(const stack &s, double &out){
    bool result;
    if(s.index==0){
        result=false;
    }
    else{
        out=s.elem[s.index-1];
        result=true;
    }
    return result;
}

bool pop(stack &s){
    bool result;
    if(s.index==0){
        result=false;
    }
    else{
        --s.index;
        result=true;
    }
    return result;
}

void print(const stack &s){
    for(int i=0;i<s.index;++i){
        cout<<s.elem[i]<<" ";
    }
    cout<<"\n";
}