#include "albero.h"
#include <iostream>
using namespace std;

void inizializza(Albero &t){
    t=NULL;
}

boolean vuoto(const Albero &t){
    return t==NULL?VERO:FALSO;
}

boolean inserisci(Albero &t, int val){
    boolean res = FALSO;
    if(vuoto(t)==VERO){
        t=new (nothrow) Nodo;
        if(t!=NULL){
            t->dx=t->sx=NULL;
            t->val=val;
            res=VERO;
        }
    }
    else{
        if(t->val>=val){
            res=inserisci(t->sx,val);
        }
        else{
            res=inserisci(t->dx,val);
        }
    }
    return res;
}

boolean cerca(const Albero &t, int val){
    boolean ret=FALSO;
    if(vuoto(t)==VERO){
        ret=FALSO;
    }
    else if(t->val==val){
        ret=VERO;
    }
    else{
        if(t->val>val){
            ret=cerca(t->sx,val);
        }
        else{
            ret=cerca(t->dx,val);
        }
    }
    return ret;
}

void stampa(const Albero &t){
    if(vuoto(t)==FALSO){
        if(t->dx==NULL && t->sx==NULL){
            cout<<t->val<<" ";
        }
        else{
            stampa(t->sx);
            cout<<t->val<<" ";
            stampa(t->dx);
        }
    }
}