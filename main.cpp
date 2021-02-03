#include "funcoes.h"
int main()
{
    int nP = 3;
    int d = 4;

    double **  matrixP= new double * [nP];
    double **  vP = new double * [nP];
    double ** pbest = new double *[nP];
    ///double * aux = new double [nP];

    for(int i = 0; i< nP; i++){
        matrixP[i] = new double[d];
        vP[i] = new double[d];
        pbest[i] = new double[d];
    }
    preencher(matrixP, nP, d);
    preencherNulo(vP,nP,d);

    /*imprimir(matrixP,nP,d);
    cout<<endl;
    imprimir(vP, nP, d);*/

    for(int i =0; i< nP; i++){
        cout << aux[i] << " ";
    }


    for(int i = 0; i< nP; i++){
        delete matrixP[i];
        delete vP[i];
        delete pbest[i];
    }
    delete pbest;
    delete vP;
    delete aux;
    delete matrixP;
}
