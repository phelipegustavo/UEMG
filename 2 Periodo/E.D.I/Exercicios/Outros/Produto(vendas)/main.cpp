#include <stdio.h>
#include <stdlib.h>

typedef struct{
    char descricao[40];
    int quantidade;
    float preco;   
}produto;

int main(){
    float total;
    produto moto;
    
    printf ("Informe a descrição da moto: ");
    scanf("%s", moto.descricao);
    printf("Informe a Quantidade de motos: ");
    scanf("%d", &moto.quantidade);
    printf("Informe o preco da moto: ");
    scanf("%f", &moto.preco);
    
    
    total=moto.quantidade*moto.preco;
    
    printf("Total = R$%.2f", total);
    printf("%s ", moto.descricao);


}