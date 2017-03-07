#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/*Faça um programa que receba uma frase, calcule e mostre a quantidade de vogais da frase digitada.*/
int main(){

    char frase[10000];
    int size;

    printf("Digite uma frase:\n");
    gets(frase);
    size=strlen(frase);
    printf("\n%s\n",frase);
    printf("\nEsta frase possui %d caracteres:", size);

}
