#include <stdio.h>
#include <stdlib.h>
/*Faça um programa que carregue uma matriz 3 x 5 com números inteiros, calcule e mostre a quantidade
de elementos entre 15 e 20.*/

int main(){

    int matriz[3][5],j,i;

    for (i=0; i<3; i++){
        for (j=0; j<5; j++){
        printf("Informe o valor da matriz em %d,%d: ", i+1,j+1);
        scanf ("%d", &matriz[i][j]);
        }
    }
    printf("\nVALORES ENTE 15 e 20: ");
    for (i=0; i<3; i++){
        for (j=0; j<5; j++){
            if (matriz[i][j]>15 && matriz[i][j]<20){
            printf("\n%d", matriz[i][j]);
            }
        }
    }
}
