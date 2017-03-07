#include <stdlib.h>
#include <stdio.h>

/*Faça um programa que leia um vetor de 50 posições de números inteiros e mostre somente os números
positivos. */

int main(int argc, char** argv) {
	
	int i,vetor[10]{1,-5,9,-23,12,3,-10,6,7,-13};
	
	
	printf ("VETORES POSITIVOS E PARES: ");
	for (i=0; i<10; i++){
		if (vetor[i]>0){
			if (vetor[i]%2==0)		
			printf("\n%d", vetor[i]);
		}
	}
		
	return 0;
}
