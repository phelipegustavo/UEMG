#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
//Faça um programa que carregue um vetor com 15 posições, calcule e mostre:
//o maior elemento do vetor e em que posição esse elemento se encontra:
//o menor elemento do vetor e em que posição esse elemento se encontra.

int main() {
    setlocale (LC_ALL, "Portuguese");

    int vetor[15]{2,6,-7,9,1,10,61,5,15,25,16,1,15,11,133};
    int maior,pmaior=0,menor,pmenor=0,i;
	
	maior=vetor[0];
	menor=vetor[0];
	
    for (i=0; i<15; i++){
        if(vetor[i]>maior){
            maior=vetor[i];
            pmaior++;
        }
        if (vetor[i]<menor){
            menor=vetor[i];
            pmenor++;
        }
    }
    printf("\nMAIOR VETOR = %d POSIÇÃO %d ", maior,pmaior);
    printf("\nMENOR VETOR = %d POSIÇÃO %d ", menor,pmenor);
	return 0;
}
