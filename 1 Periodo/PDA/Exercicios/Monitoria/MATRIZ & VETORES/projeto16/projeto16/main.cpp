#include <stdlib.h>
#include <stdio.h>

/*Faça um programa que carregue uma matriz 20 x 10 com números inteiros e some cada urna das
colunas. armazenando o resultado da soma em um vetor. A seguir, multiplique cada elemento da
matriz pela soma da coluna e mostre a matriz resultante.*/

int main(){

    int matriz[5][3],rmatriz[5][3];
    int coluna[3]={0},j,i;

    for (i=0; i<5; i++){
        for (j=0; j<3; j++){
            printf("Informe o valor da matriz em %d,%d: ",i+1,j+1);
            scanf("%d", &matriz[i][j]);
            coluna[j]=matriz[i][j]+coluna[j];
        }
    }
    for (i=0; i<5; i++){
        for (j=0; j<3; j++){
            matriz[i][j]=matriz[i][j]*coluna[j];
            printf("Matriz %d %d = %d\n", i+1,j+1,matriz[i][j]);
        }
    }
}
