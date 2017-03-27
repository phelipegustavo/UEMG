#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct {
    int valor;
} T_item;

typedef struct T_celula* T_apontador;

typedef struct T_celula {
    T_item item;
    T_apontador proximo;
} T_celula;

typedef struct {
    T_apontador frente, tras;
} T_fila;

void inicializar(T_fila* fila) {
    fila->frente = (T_apontador) malloc(sizeof (T_celula));
    fila->tras = fila->frente;
    fila->tras->proximo = NULL;
}

bool vazia(T_fila* fila) {
    return fila->frente == fila->tras;
}

void enfileirar(T_fila* fila, T_item item) {
    fila->tras->proximo = (T_apontador) malloc(sizeof (T_celula));
    fila->tras = fila->tras->proximo;
    fila->tras->item = item;
    fila->tras->proximo = NULL;
}

void desenfileirar(T_fila* fila) {
    if (vazia(fila)) {
        printf("Impossivel, a fila ja esta vazia!\n");
    } else {
        T_apontador desenfileirado = fila->frente;
        fila->frente = fila->frente->proximo;
        free(desenfileirado);
    }
}

void imprimir(T_fila* fila) {
    if (vazia(fila)) {
        printf("A fila esta vazia!\n");
    } else {
        for (T_apontador i = fila->frente->proximo; i != NULL; i = i->proximo) {
            printf("%5d\n", i->item.valor);
        }
    }
}

//Exercicio 01

int Total_itens(T_fila* fila) {
    int total = 0;
    for (T_apontador i = fila->frente->proximo; i != NULL; i = i->proximo) {
        total += 1;
    }
    return total;
}

//Exercicio 02

void fura_fila(T_fila* fila, T_item item) {
    T_apontador anterior = fila->frente;
    T_apontador atual = fila->frente->proximo;
    T_apontador Item = (T_apontador) malloc(sizeof (T_celula));
    Item->item.valor = item.valor;

    int cont = 0;
    int meio = (Total_itens(fila) / 2);

    while (cont < meio) {
        anterior = anterior->proximo;
        atual = atual->proximo;
        cont++;
    }
    anterior->proximo = Item;
    Item->proximo = atual;

}

//Exercicio 04

void reiniciar(T_fila* fila) {
    for (T_apontador i = fila->frente->proximo; i != NULL; i = i->proximo) {
        T_apontador temp = fila->frente;
        fila->frente = fila->frente->proximo;
        free(temp);
    }
}

int menu() {
    int op = 1;
    printf("1- Enfileirar\n");
    printf("2- Desenfileirar\n");
    printf("3- Imprimir\n");
    printf("4- Reiniciar fila\n");
    printf("0- SAIR\n");
    scanf("%d", &op);
    return op;
}

