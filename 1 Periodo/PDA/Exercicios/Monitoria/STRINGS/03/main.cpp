#include <stdio.h>
#include <stdlib.h>
#include <string.h>
/*Faça um programa que receba uma frase, calcule e mostre a quantidade de vezes que a palavra AULA
aparece na frase digitada.*/

int main(){

    char frase[100];
    int i,c=0;

    printf("Informe uma frase: \n");
    gets(frase);

    for (i=0; i<strlen(frase); i++){
        if (frase[i]=='A' && frase[i+1]=='U' && frase[i+2]=='L' && frase[i+3]=='A' ){
            c++;
        }
    }
    printf("A PALAVRA AULA APARECE %d vezes", c);



}
