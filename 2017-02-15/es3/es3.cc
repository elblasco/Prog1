using namespace std;
#include "queue.h"
#include <iostream>

static int next(int index, const queue &q){
   return (index + 1) % q.dim;
}
static bool is_empt(const queue &q){
   return q.tail == q.head;
}

static bool is_full(const queue &q){
   return next(q.tail, q) == q.head;
}

void init(queue &q,int maxdim){
   q.head=q.tail=0;
   q.dim=maxdim+1;
   q.elem=new float[q.dim];
}

void deinit(queue &q){
   delete[] q.elem;
}

bool enqueue(queue &q,float n){
   if(is_full(q)){
      return false;
   }
   else{
      q.elem[q.tail]=n;
      q.tail=next(q.tail,q);
      return true;
   }
}
bool dequeue(queue &q){
   if(is_empt(q)){
      return false;
   }
   else{
      q.head=next(q.head,q);
   }
}

bool first(queue &q,float &out){
   if (is_empt(q)) {
      return false;
   }
   else{
      out=q.elem[q.head];
      return true;
   }
}

void print(const queue &q){
   for(int i=q.head;i!=q.tail;i=next(i,q)){
      cout << q.elem[i] << endl;
   }
}
