#include <stdlib.h>
#include <stdio.h>
/*Faça um programa que carregue urna matriz 6 x 3, calcule e mostre:
² o maior elemento da matriz e sua respectiva posição. ou seja, linha e coluna:
² o menor elemento da matriz e sua respectiva posição. ou seja, linha e coluna */

int main(){

    int matriz[6][3];
    int i,j,menor=100,lmenor=0,cmenor=0,maior=-100,lmaior=0,cmaior=0;

    for (i=0; i<6; i++){
        for (j=0; j<3; j++){
            printf("Informe o valor da matriz em %d,%d: ",i+1,j+1);
            scanf("%d", &matriz[i][j]);
        }
    }

    for (i=0; i<6; i++){
        for (j=0; j<3; j++){
            if (matriz[i][j]>maior){
                maior=matriz[i][j];
                lmaior=i;
                cmaior=j;
            }
             if (matriz[i][j]<menor){
                menor=matriz[i][j];
                lmenor=i;
                cmenor=j;
            }
        }
    }

    printf("\nMAIOR ELEMENTO: %d posicao: %d,%d",maior,lmaior+1,cmaior+1);
    printf("\nMENOR ELEMENTO: %d posicao: %d,%d",menor,lmenor+1,cmenor+1);

}
