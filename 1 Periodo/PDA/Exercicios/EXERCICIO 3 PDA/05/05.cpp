#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
/*Ler 2 valores do teclado e mostrar a soma de todos os valores no intervalo.*/
int main(){
setlocale(LC_ALL, "Portuguese");

    int valor1,valor2,i=1,q,soma=0;

    printf("Informe o 1º valor: ");
    scanf("%d", &valor1);
    printf("Informe o 2º valor: ");
    scanf("%d", &valor2);

    if (valor1<valor2){
    while (valor1+i<valor2){
        soma=soma+valor1+i;
        i++;
    }
    }

    else if (valor2<valor1){
    while (valor2+i<valor1){
        soma=soma+valor2+i;
        i++;
    }
    }
    printf("\nSOMA= %d", soma);
}
