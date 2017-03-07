#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
/*Leia um vetor de 12 posições e em seguida ler também dois valores X e Y quaisquer correspondentes a duas posições no vetor.
Ao final seu programa deverá escrever a soma dos valores encontrados nas respectivas posições X e Y.*/
int main(){
setlocale(LC_ALL, "Portuguese");

    int vetor[12]={0},posicaox,posicaoy,i,soma=0;

    for (i=0; i<12; i++){
        printf("Informe o valor do vetor na posição %d: ",i+1);
        scanf("%d", &vetor[i]);
    }
    //considerando que o usuario ira digitar a posição adicionada de 1 (Ignorando a posição 0)

    printf("Informe a posição X para soma: ");
    scanf ("%d", &posicaox);
    printf("Informe a posição y para soma: ");
    scanf("%d", &posicaoy);

    soma=vetor[posicaox-1]+vetor[posicaoy-1];

    printf("\nSOMA = %d", soma);

}
