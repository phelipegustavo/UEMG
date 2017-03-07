#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
/*Dada uma sequência de n números, imprimi-la na ordem inversa à da leitura.*/
int main(){
setlocale(LC_ALL, "Portuguese");

    int qtd=0,i,aux=0,j;

    printf("Quantos valores devem ser lidos? ");
    scanf("%d", &qtd);

    int n[qtd],n2[qtd];

    for (i=0; i<qtd; i++){
        printf("Informe um numero: ");
        scanf ("%d", &n[i]);
    }
    for (i=qtd-1; i>=0; i--){
        printf("%d\n", n[i]);
    }
}
