#include <stdio.h>
#include <stdlib.h>
#define MAX 10

//Fila de pilhas
{
	typedef struct {
		int topo;
	}T_pilha;
	
	typedef struct {
		int primeiro, ultimo;
		T_pilha pilha[MAX];
	}T_fila;
}

//Pilha de filas
{
	typedef struct {
		int primeiro, ultimo;
	}T_fila;
	
	typedef struct {
		int topo;
		T_fila fila[MAX];
	}T_pilha;
}

//Fila de Filas
{
	typedef struct {
		int primeiro, ultimo;
	}T_fila;
	
	typedef struct {
		int primeiro, ultimo;
		T_fila filas[MAX]
	}T_filas;
}


int main() {
	return 0;
}
