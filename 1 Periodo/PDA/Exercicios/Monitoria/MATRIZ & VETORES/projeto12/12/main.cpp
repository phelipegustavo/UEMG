#include <stdlib.h>
#include <stdio.h>
/* Faça um programa que carregue uma matriz 2 x 4 com números inteiros, calcule e mostre:
² a quantidade de elementos entre 12 e 20 em cada linha:
² a média dos elementos pares da matriz.*/

int main(){
    int matriz[2][4],i,j,qnt=0,qntp=0,pares=0;
    float media=0;

    for (i=0; i<2; i++){
        for (j=0; j<4; j++){
            printf("Informe o valor da matriz em %d,%d: ", i+1,j+1);
            scanf("%d", &matriz[i][j]);
        }
    }

    for (i=0; i<2; i++){
        for (j=0; j<4; j++){
            if (matriz[i][j]>12 && matriz[i][j]<20){
                qnt++;
            }
        }
        printf("\nA QUANTIDADE DE NUMEROS ENTRE 12 e 20 na linha %d = %d", i+1,qnt);
        qnt=0;
    }

    for (i=0; i<2; i++){
        for (j=0; j<4; j++){
            if (matriz[i][j]%2==0){
                pares=matriz[i][j]+pares;
                qntp++;
            }
        }
    }
    media=((float)pares/(float)qntp);
    printf("\nA MEDIA DOS ELEMENTOS PARES : %.2f",media);

}
