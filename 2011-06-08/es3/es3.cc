#include "stampa.h"
#include <iostream>
using namespace std;

double fatt(int n);
void crea_matrice(double** &m,int row, int col);
//void dealloca_matrice(double** &m,int row);

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
    /**
     * Vi lascio sotto la chiamata e la definizione ad una funzione
     * per deallocare la matrice, nella soluzionbe non è presente 
     * ma se non si chiama si verificano dei memory leak
    **/
    //dealloca_matrice(matrix,row);
    return 0;
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
/*
void dealloca_matrice(double** &m,int row){
    for(int i=0;i<row;++i){
        delete[] m[i];
    }
    delete[] m;
}
*/