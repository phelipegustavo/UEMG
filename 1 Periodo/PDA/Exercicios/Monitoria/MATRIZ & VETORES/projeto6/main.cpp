#include <iostream>

/* Faça um programa que leia um vetor inteiro de 30 posições e crie um segundo vetor, substituindo os
valores nulos por 1. Mostre os dois vetores. */

int main(int argc, char** argv) {
	
	int vetor[10]{1,-9,6,0,2,12,0,5,0,0},vetor2[10];
	int i=0;
	
	for (i=0; i<10; i++){
		if (vetor[i]==0){
			vetor2[i]=1;
		}
		else 
		vetor2[i]=vetor[i];
	}
	
	
	for (i=0; i<10; i++){
		printf("\nVetor 2 na posicao %d = %d", i+1, vetor2[i]);
	}
	
	return 0;
}
