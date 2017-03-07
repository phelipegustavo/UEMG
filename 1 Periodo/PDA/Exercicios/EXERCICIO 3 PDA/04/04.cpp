#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
/*Escreva todos os números pares entre 1 e 1.000.000.*/
int main(){
    setlocale(LC_ALL, "Portuguese");

    int n[1000000],i=0;

    for(i=2; i<1000000; i=i+2){
        printf("%d\t", i);

    }
}
