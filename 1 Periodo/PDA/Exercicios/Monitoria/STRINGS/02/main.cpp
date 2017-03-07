#include <stdio.h>
#include <stdlib.h>
#include <string.h>
/*Faça um programa que receba uma frase, calcule e mostre a quantidade de consoantes da frase digitada*/
int main(){

    char consoantes[23]{"bcdfghjklmnpqrstvwxyz"},frase[100];
    int cont=0,i,j;

    printf("informe uma frase (caixa baixa): ");
    gets(frase);

    for (i=0;i<strlen(frase);i++){
        for (j=0;j<strlen(consoantes);j++){
            if (frase[i]==consoantes[j] && frase[i]!=0){
                cont++;
            }
        }
    }

    printf("\n%d LETRAS SAO CONSOANTES! ", cont);

}
