#include "queue.h"
#include <iostream>
using namespace std;

int next(int index, const queue &q){
    return (index+1)%q.dim;
}

bool is_full(queue q){
    return next(q.tail,q)==q.head;
}

bool is_Empty(queue q){
    return q.tail==q.head;
}

void init(queue &q,int maxdim){
    q.dim=maxdim+1;
    q.head=0;
    q.tail=0;
    q.elem=new float[maxdim];
}

void deinit(queue &q){
    q.dim=0;
    q.head=0;
    q.tail=0;
    delete[] q.elem;
}

bool enqueue(queue &q,float n){
    bool ret;
    if(is_full(q)){
        ret=false;
    }
    else{
        q.elem[q.tail]=n;
        q.tail=next(q.tail,q);
        ret=true;
    }
    return ret;
}

bool dequeue(queue &q){
    bool ret;
    if(is_Empty(q)){
        ret=false;
    }
    else{
        q.head=next(q.head,q);
        ret=true;
    }
    return ret;
}

bool first(queue &q,float &out){
    bool ret;
    if(is_Empty(q)){
        ret=false;
    }
    else{
        out=q.elem[q.head];
        ret=true;
    }
    return ret;
}

void print(const queue &q){
    for(int index=q.head;index!=q.tail;index=next(index,q)){
        cout<<q.elem[index]<<" ";
    }
    cout<<endl;
}