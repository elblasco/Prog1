#include<iostream>
#include "tree.h"
using namespace std;

static tree tuttonull() {
  tree tmp;
  tmp.pos=-1;
  return tmp;
}

static tree destra(const tree &  t){
   tree  tmp;
   tmp.pos=(t.pos*2)+2;
   tmp.array=t.array;
   return tmp;
}

static tree sinistra(const tree &  t){
   tree tmp;
   tmp.pos=(t.pos*2)+1;
   tmp.array=t.array;
   return tmp;
}

char & elemento(const tree & t) {
  return t.array[t.pos];
}

int empty(const tree & t) {
  return (elemento(t)=='\0');
}

void init(tree &t){
   t.pos=0;
   t.array=new char[MAXSIZE];
   for(int i=0;i<MAXSIZE;++i){
      t.array[i]='\0';
   }
}

void deinit(tree &t){
 delete[] t.array;
}

bool nullp(const tree & t){
   return (t.pos==-1);
}

retval insert(tree &t, char c){
   tree tmp;
   if(t.pos>=MAXSIZE){
      return FAIL;
   }
   else if(empty(t)){
      elemento(t)=c;
   }
   else if(c<=elemento(t)){
      tmp=sinistra(t);
      insert(tmp,c);
   }
   else{
      tmp=destra(t);
      insert(tmp,c);
   }
   return OK;
}

tree cerca (const tree &t,char c){
   if(elemento(t)==c){
      return t;
   }
   else if(empty(t)){
      return tuttonull();
   }
   else if(c>elemento(t)){
      return cerca(destra(t),c);
   }
   else{
      return cerca(sinistra(t),c);
   }
}

void print_ordered(const tree &t){
   if(!empty(t)){
      print_ordered(sinistra(t));
      cout<<elemento(t)<<" ";
      print_ordered(destra(t));
   }
}

void print_indented(const tree &t){
 cout<<"Non implementata\n";   
}
