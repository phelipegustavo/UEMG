#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
//Faça um programa que leia dois vetores de dez posições e faça a multiplicação dos elementos de mesmo
//índice colocando o resultado em um terceiro vetor. Mostre o vetor resultante

int main(){
    setlocale (LC_ALL, "Portuguese");

    int vetor1[10], vetor2[10], vetor3[10], i;

    for (i=0; i<10; i++){
        printf("Informe o valor do vetor 1 na posição %d: ", i+1);
        scanf("%d", &vetor1[i]);
        printf("Informe o valor do vetor 2 na posição %d: ", i+1);
        scanf("%d", &vetor2[i]);
    }

    for (i=0; i<10; i++){
        vetor3[i]=vetor1[i]*vetor2[i];
        printf("\nVetor 3 na posição %d: %d * %d = %d", i+1, vetor1[i], vetor2[i], vetor3[i]);
    }

}
