#include <stdio.h>
#include <stdlib.h>
/*Faça um programa que carregue duas matrizes 3 x 8 com números inteiros. calcule e mostre:
² a soma das duas matrizes, resultando em uma terceira matriz também de ordem 3 x 8;
² a diferença das duas matrizes, resultando em uma quarta matriz também de ordem 3 x 8.*/

int main(){

    int matriz1[3][8],matriz2[3][8];
    int matriz[3][8],i,j;

    for (i=0; i<3; i++){
        for (j=0; j<8; j++){
            printf("Informe o valor da matriz 1 em %d,%d: ",i+1,j+1);
            scanf("%d", &matriz1[i][j]);
        }
    }

     for (i=0; i<3; i++){
        for (j=0; j<8; j++){
            printf("Informe o valor da matriz 2 em %d,%d: ",i+1,j+1);
            scanf("%d", &matriz2[i][j]);
        }
    }

    for (i=0; i<3; i++){
        for (j=0; j<8; j++){
        matriz[i][j]=matriz1[i][j]+matriz2[i][j];
        printf("SOMA %d,%d: \t%d\n", i+1,j+1,matriz[i][j]);
        matriz[i][j]=matriz1[i][j]-matriz2[i][j];
        printf("SUBTRACAO %d,%d: \t%d\n", i+1,j+1,matriz[i][j]);
        }
    }


}
