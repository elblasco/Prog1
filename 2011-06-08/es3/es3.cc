#include "stampa.h"
#include <iostream>
using namespace std;

double fatt(int n);
void crea_matrice(double** &m,int row, int col);

int main(){
    int row=0,col=0;
    double **matrix;

    do{
        cout<<"Insert the number of rows\n";
        cin>>row;
    }while (row<=0);

    do{
        cout<<"Insert the number of colons\n";
        cin>>col;
    }while (col<=0);

    crea_matrice(matrix,row,col);
    cout<<"Matrice:"<<endl;
    stampa_matrice(matrix,row,col);
}

double fatt(int n){
    if(n==0){
        return 1.0;
    }
    else{
        return n*fatt(n-1);
    }
}

void crea_matrice(double** &m,int row, int col){
    m=new double*[row];
    for(int i=0;i<row;++i){
        m[i]=new double[col];
        for(int j=0;j<col;++j){
            m[i][j]=fatt(i)+fatt(j);
        }
    }
}