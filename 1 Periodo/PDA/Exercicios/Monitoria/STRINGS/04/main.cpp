#include <stdio.h>
#include <stdlib.h>
#include <string.h>
/*Faça um programa que receba uma frase e uma palavra, calcule e mostre a quantidade de vezes que a
palavra digitada aparece na frase. Exemplo:
Frase: EU ESTOU NA ESCOLA. GOSTO MUITO DE ESTUDAR E ACHO QUE A ESCOLA É LEGAL.
Palavra: ESCOLA
Resposta: A palavra ESCOLA apareceu duas vezes na frase.*/
int main(){

    char palavra[30],frase[100];
    int i,j=0,c,cont=0;

    printf("Informe a palavra: ");
    gets(palavra);

    printf("Informe a frase: \n");
    gets(frase);

    for (i=0;i<=strlen(frase);i++){
        if (frase[i]==palavra[j]){
            j++;
                if (j==strlen(palavra)){
                    cont++;
                        j=0;
                }
        }
        else
        j=0;
    }
    printf("\nA PALAVRA %s APARECEU %d VEZES", palavra,cont);

}
