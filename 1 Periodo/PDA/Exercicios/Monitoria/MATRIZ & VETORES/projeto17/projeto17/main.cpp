#include <stdio.h>
#include <stdlib.h>
/*Faça um programa que carregue uma matriz M de ordem 4 x 6 e uma segunda matriz N de ordem 6 x
4. calcule e imprima a soma das linhas de M com as colunas de N.*/

int main(){

    int m[4][6],n[6][4],r[4][6];
    int i,j;

    for (i=0; i<4; i++){
        for (j=0; j<6; j++){
            printf("Informe o valor da matriz M em %d,%d: ",i+1,j+1);
            scanf("%d", &m[i][j]);
        }
    }
    for (i=0; i<6; i++){
        for (j=0; j<4; j++){
            printf("Informe o valor da matriz N em %d,%d: ",i+1,j+1);
            scanf("%d", &n[i][j]);
        }
    }

    for (i=0; i<4; i++){
        for (j=0; j<6; j++){
            r[i][j]=m[i][j]+n[j][i];
        printf("MATRIZ RESULTANTE EM %d,%d = %d\n", i+1,j+1,r[i][j]);
        }
    }

}
