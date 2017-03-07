#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
/*Solicitar a idade de várias pessoas e determinar se elas são maiores ou menores de idade. Parar de solicitar quando uma idade negativa for informada.*/
int main(){
setlocale(LC_ALL, "Portuguese");

    int idade=0;

    while (idade>=0){
        printf("\nInforme a idade: ");
        scanf("%d", &idade);
        if (idade>=18){
            printf("MAIOR DE IDADE!\n");
        }
        else {
            printf("MENOR DE IDADE!\n");
        }
    }
}
