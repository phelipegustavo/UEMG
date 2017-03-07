#include <stdio.h>
#include <stdlib.h>
// 1. Faça um programa que receba o nome de cinco produtos e seus respectivos preços, calcule e mostre:
// a quantidade de produtos com preço inferior a R$ 50,00;
// o nome dos produtos com preço entre R$ 50,00 e R$ 100.00;
// a média dos preços dos produtos com preço superior a R$ 100.00.


int main() {
	
	char nome[5][30];
	int i=0,m50=0,entre,m=0;
	float preco[5],soma=0,media=0;
	
	for (i=0; i<5; i++){
	printf("Informe o nome do produto na posicao %d: ", 1+i);
	scanf("%s", nome[i]);
	printf("Informe o preco do produto na posicao %d: ", 1+i);
	scanf("%f", &preco[i]);
	}
	
	for (i=0; i<5; i++){
	if(preco[i]<50.0){
		m50++;
	}	
	}
	printf("\nA quantidade produtos com preco menor que 50 e: %d", m50);
	
	printf("\nProdutos entre 50 e 100: ");	
	for (i=0; i<5; i++){
	if(preco[i]>50.0 && preco[i]<100.0){
		entre++;
		printf("\n%s", nome[i]);
	}
	}
	for (i=0; i<5; i++){
	if(preco[i]>100.0){
		soma=preco[i]+soma;
		m++;
	}
	}
	media=(soma/m);
	printf("\nMedia produtos maiores que 100: %.2f", media);	
	
	return 0;
}
