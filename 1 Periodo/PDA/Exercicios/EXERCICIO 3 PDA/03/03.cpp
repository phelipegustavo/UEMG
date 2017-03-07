#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
/*Elaborar um programa que efetue a leitura de valores numéricos e apresente no final o total do somatório, a média e o total de números lidos.
O programa deve fazer a leitura dos valores enquanto o usuário estiver fornecendo valores positivos. Ou seja, o programa deve parar quando o usuário fornecer um valor negativo.*/
int main(){
setlocale(LC_ALL, "Portuguese");

    float numero=0,soma=0,media=0;
    int q=0;

    while (numero>=0){
        printf("Informe um numero: ");
        scanf("%f", &numero);
        if(numero>0){
        soma=numero+soma;
        q++;
        media=soma/(float)q;
        }
    }
    printf("\nSOMA----------------%.2f", soma);
    printf("\nMEDIA---------------%.2f", media);
    printf("\nNUMEROS LIDOS-------%d",q);
}
