#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
/*Apresentar todos os números divisíveis por 4 que sejam menores que 200*/
int main(){
    setlocale(LC_ALL, "Portuguese");

    int n[200]={0},i;

    printf("NUMEROS MENORES QUE 200 DIVISIVEIS POR 4: \n\n");
    for (i=0; i<200; i++){
        n[i]=i;
        if (n[i]%4==0){
            printf("%d\t", n[i]);
        }
    }

}
