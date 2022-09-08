#include"stampa.h"
#include<iostream>
#include<cstdlib>
using namespace std;

void stampa_matrice(double** m,int row, int col){
    for(int i=0;i<row;++i){
        for(int j=0;j<col;++j){
            cout<<m[i][j]<<" ";
        }
        cout<<'\n';
    }
}