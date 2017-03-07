#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
/*Faça um algoritmo que leia 10 salários.
Depois de lidos e armazenados, mostre o maior valor.*/
int main(){
    setlocale(LC_ALL, "Portuguese");

    float salario[10]={0},maior=0;
    int i;

    for (i=0; i<10; i++){
        printf("Informe o salario do %dº funcionario: ",i+1);
        scanf("%f", &salario[i]);
        if (salario[i]>maior){
            maior=salario[i];
        }
    }
    printf("\nMAIOR SALÁRIO ----- R$%.2f", maior);

}
