#include <iostream>

/* Faça um programa que leia um vetor de dez posições. Em seguida, compacte o vetor, retirando os
valores nulos e negativos. Coloque o resultado no vetor B, mostrando o vetor resultante. */

int main(int argc, char** argv) {
	
	int vetor[10]{1,3,5,0,-3,-1,7,0,8,-9};
	int i,qde=0,aux=0;
	
	for (i=0; i<10; i++){
		if (vetor[i]>0)
		qde++;
	}
	int vetorb[qde];
	
	for (i=0; i<10; i++){
		if (vetor[i]>0){
			vetorb[aux]=vetor[i];
			aux++;
		}
	}
	for (i=0; i<qde; i++){
		printf ("\n%d", vetorb[i]);
	}
	return 0;
}
