#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
/*Leia 4 valores inteiros (X, Y, Z, W), determina e escreve o menor deles.*/
int main(){
setlocale(LC_ALL, "Portuguese");

    int vetor[4],i,menor[1];

    for (i=0; i<4; i++){
        printf("Informe um valor: ");
        scanf("%d", &vetor[i]);
        menor[0]=vetor[0];
        if (vetor[i]<menor[0]){
            menor[0]=vetor[i];
        }
    }
    printf("\nO MENOR VALOR É: %d", menor[0]);
}
