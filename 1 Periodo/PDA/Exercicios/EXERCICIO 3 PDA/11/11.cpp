#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
/*Faça um programa que leia n valores reais. Armazene estes valores num vetor. Ao final, imprima a média aritmética destes valores.*/

int main(){
setlocale(LC_ALL, "Portuguese");

    int qtd=0,i;

    printf("Quantos valores devem ser lidos? ");
    scanf("%d", &qtd);

    float vetor[qtd],media=0,soma=0;

    for (i=0; i<qtd; i++){
        printf("Informe o valor do vetor na posição %d: ", i+1);
        scanf("%f", &vetor[i]);
        soma=soma+vetor[i];
    }
    media=soma/(float)qtd;
    printf("\nMEDIA ARITMÉTICA = %.2f", media);
}
