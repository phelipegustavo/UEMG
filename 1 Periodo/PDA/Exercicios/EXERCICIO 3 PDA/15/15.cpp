#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
/*Faça um algoritmo que leia e armazene 5 valores inteiros em um vetor Vet1.
Leia outros 5 valores inteiros e armazene num vetor Vet2. A partir destes valores lidos, mostre na tela:
- a soma dos elementos de cada vetor, nas respectivas posições
- a diferença dos elementos de cada vetor, nas respectivas posições
- o produto dos elementos de cada vetor, nas respectivas posições
- a divisão entre os elementos de cada vetor, nas respectivas posições*/
int main(){
setlocale(LC_ALL, "Portuguese");

    int vetor1[5]={0},vetor2[5]={0};
    int i,soma=0,diferenca=0,produto=0;
    float divisao=0;

    for (i=0; i<5; i++){
        printf("Informe o valor do vetor 1 na posição %d: ", i+1);
        scanf("%d", &vetor1[i]);
    }
    for (i=0; i<5; i++){
        printf("Informe o valor do vetor 2 na posição %d: ", i+1);
        scanf("%d", &vetor2[i]);
    }

    for (i=0; i<5; i++){
        printf("\n");
        soma=vetor1[i]+vetor2[i];
        diferenca=vetor1[i]-vetor2[i];
        produto=vetor1[i]*vetor2[i];
        printf("SOMA %d+%d = %d\n", vetor1[i],vetor2[i],soma);
        printf("DIFERENÇA %d-%d = %d\n", vetor1[i],vetor2[i],diferenca);
        printf("PRODUTO %d*%d = %d\n", vetor1[i],vetor2[i],produto);
        if (vetor2[i]!=0){
            divisao=(float)vetor1[i]/(float)vetor2[i];
            printf("DIVISÃO %d/%d = %.2f\n", vetor1[i],vetor2[i],divisao);}
        else if (vetor2[i]==0){
             printf("ATENÇÃO!\nInforme um valor diferente de 0 para o vetor 2!\n");}
    }
}
