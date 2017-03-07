#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
/*Faça um programa que solicite ao usuário 10 números inteiros e, ao final, informe a quantidade de números ímpares e pares lidos.
Calcule também a soma dos números pares e a média dos números ímpares.*/
int main(){
setlocale(LC_ALL, "Portuguese");

    int n[10]={0},i,qP=0,qI=0;
    float somaP=0,somaI=0,mediaI=0;

    for (i=0; i<10; i++){
        printf("Informe um numero inteiro: ");
        scanf("%d", &n[i]);
        if (n[i]%2==0){
            somaP=somaP+n[i];
            qP++;
        }
        else if (n[i]%2!=0){
            somaI=somaI+n[i];
            qI++;
            mediaI=somaI/(float)qI;
        }
    }
    printf("\nQUANTIDADE DE NUMEROS PARES = %d", qP);
    printf("\nQUANTIDADE DE NUMEROS IMPARES = %d", qI);
    printf("\nSOMA DOS NUMEROS PARES = %.2f", somaP);
    printf("\nMEDIA DOS NUMEROS IMPARES = %.2f", mediaI);


}
