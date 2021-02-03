#include <iostream>
#include <math.h>
#define c 418,9829

using namespace std;

int numeroAleatorio(int menor, int maior) {
       return rand()%(maior-menor+1) + menor;
}
void Entradas(double ** matrix, int nP, int d, int * aux){
    double soma = 0;
    for(int i = 0; i < nP; i++){
        for(int j = 0; j< d; j++){
           double x = matrix[i][j];
           soma = soma + x * sin(sqrt(fabs(x)));
        }
        double resul = ((c * d) - soma);
        aux[i] = resul;
    }
}
void preencher(double ** matrix, int nP, int d){
    for(int i = 0 ; i <nP; i++){
        for(int j = 0; j < d; j++){
            matrix[i][j] = numeroAleatorio(-500, 500);
        }
    }
}
void preencherNulo(double ** matrix, int nP, int d){
    for(int i = 0 ; i <nP; i++){
        for(int j = 0; j < d; j++){
            matrix[i][j] = 0;
        }
    }
}
void imprimir (double ** matrix, int nP, int d){
    for(int i = 0 ; i <nP; i++){
        for(int j = 0; j < d; j++){
            cout <<matrix[i][j] << " ";
        }
        cout<<endl;
    }
}
void PSO(double ** vP,double ** matrixP, double ** pbest, int nP, int d, int * gbest){
    double * aux1 = new double[nP]; //valor de cada particula
    double * aux2 = new double[nP];
    double w = 0;

    Entradas(matrixP,nP,d,aux1);
    Entradas(pbest,nP,d,aux2);

    do {
        for(int i = 0; i < nP; i++){
            if(aux1[i] < aux2[i]){
                for(int j = 0; j < d; j++){
                    pbest[i][j] = matrixP[i][j];
                }
                if(aux1[i] < aux2[gbest])
                    gbest = i;
            }
            for(int j = 0; j < nP; j++){
                w = 0.9 - (j*((0.9 - 0.4)/0.9));
                double r1 = numeroAleatorio(-500,500);
                double r2 = numeroAleatorio(-500,500);
                int con = 2;
                double part1 = (w*vP[i][j]);
                double part2 = (con * r1 * (aux2[i] - matrixP[i][j]));
                double part3 = (con * r2 *(pbest[gbest][j] - matrixP[i][j]));

                vP[i][j] = part1+part2+part3; ///parei aqui
            }
        }
    }while(///criterio de parada);
}
