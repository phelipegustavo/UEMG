#include <stdio.h>
#include <stdlib.h>

//2. Faça um programa que carregue dois vetores de dez posições cada um. Calcule e mostre um terceiro
//vetor que contenha os elementos dos dois vetores anteriores ordenados de maneira decrescente.

int main(int argc, char** argv) {
	
	int vetor1[10], vetor2[10], vetor3[20];
	int i=0, j=0, aux=0;
	
	for (i=0; i<5; i++){
		printf("Informe o valor do vetor na posicao %d: ", i+1);
		scanf("%d", &vetor1[i]);
		printf ("Informe o valor do vetor na posicao %d: ", i+1);
		scanf("%d", &vetor2[i]);		
	}
	
	for (i=0; i<10; i++){
		vetor3[i]=vetor1[i];
		vetor3[i+10]=vetor2[i];
	}
	
	for (i=0; i<20; i++){
	for (j=0; j<20; j++){
	if (vetor3[i]>vetor3[j]){
	aux=vetor3[i];
	vetor3[i]=vetor3[j];
	vetor3[j]=aux;
	}	
	}	
	}
	
	for (i=0; i<20; i++){
	printf("\nVetor 3 na posicao %d = %d", i+1, vetor3[i]);
	}
	
	
	return 0;
}
