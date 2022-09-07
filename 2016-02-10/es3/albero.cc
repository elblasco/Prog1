#include<iostream>
#include"albero.h"
using namespace std;

void inizializza(Albero &t){
   t=NULL;
}

boolean vuoto(const Albero &t){
   return (t==NULL)?VERO:FALSO;
}
boolean inserisci(Albero &t, int val){
   if(vuoto(t)==VERO){
      t=new Nodo;
      t->val=val;
      t->sx=t->dx=NULL;
      return VERO;
   }
   else if(val<=t->val){
      inserisci(t->sx,val);
   }
   else if(val > t->val){
      inserisci(t->dx,val);
   }
}

boolean cerca(const Albero &t, int val){
   if(vuoto(t)==VERO){
      return FALSO;
   }
   else if(val < t->val){
      cerca(t->sx,val);
   }
   else if(val > t->val){
      cerca(t->dx,val);
   }
   else if(val==t->val){
      return VERO;
   }
   else{
      return FALSO;
   }
}

void stampa(const Albero &t){
   if(vuoto(t)==FALSO){
      stampa(t->sx);
      cout<<t->val<<" ";
      stampa(t->dx);
   }
}
