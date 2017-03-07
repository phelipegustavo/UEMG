#include <stdio.h>
#include <stdlib.h>
/*Faça um programa que carregue uma matriz 3 x 3 com números reais e receba um valor digitado pelo
usuário, calcule e mostre a matriz resultante da multiplicação do número digitado pelos elementos da
matriz.*/
int main(){
    float matriz[3][3],c;
    int i,j;

    printf("Informe o valor do numero que multiplicara a matriz: ");
    scanf("%f", &c);

    for (i=0; i<3; i++){
        for(j=0; j<3; j++){
            printf("Informe o valor da matriz em %d,%d: ",i+1,j+1);
            scanf("%f", &matriz[i][j]);

        }
    }
    printf("------------------------------------\n");
    for (i=0; i<3; i++){
        for(j=0; j<3; j++){
        matriz[i][j]=matriz[i][j]*c;
        printf("MATRIZ RESULTANTE EM %d,%d= %.2f\n", i+1,j+1,matriz[i][j]);
        }
    }


}
