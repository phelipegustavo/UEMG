#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#define MAX 5

typedef struct {
    int valor;
} T_chave;

typedef struct {
    T_chave fila[MAX];
    int total_itens;
    int primeiro;
    int ultimo;
} T_fila;

T_fila inicializar(T_fila aux) {
    aux.primeiro = 0;
    aux.ultimo = -1;
    aux.total_itens = 0;
    return aux;
}

bool cheia(T_fila aux) {
    return (aux.total_itens +1 == MAX);
}

T_fila inserir(T_fila aux, T_chave item) {
    if (!cheia(aux)) {
        if (aux.ultimo +1 == MAX) //Volta para a primeira posicao, caso chegar a ultima posicao
            aux.ultimo = -1;

        aux.ultimo++;
        aux.fila[aux.ultimo] = item;
        aux.total_itens++; //adcionou um item a fila
        return aux;
    }
}

T_fila remover(T_fila aux) {
    //T_chave primeiro = aux.fila[];
    
    //se o primeiro for == 4(ultimo) passa a ser 5
    aux.primeiro++;//primeiro passa a ser o proximo
    
    if (aux.primeiro == MAX)
        aux.primeiro = 0;

    aux.total_itens--; //retirou um item da fila

    return aux;
    
   // printf("%d",primeiro.valor);
}


void imprimir(T_fila aux) {
    int cont, i;
    i = aux.primeiro;
    
    for (cont = 0; cont < aux.total_itens; cont++) {
        if (i == MAX)
            i = 0;
        
        printf("%5d\n", aux.fila[i].valor);

        
        
        i++;
    }

}