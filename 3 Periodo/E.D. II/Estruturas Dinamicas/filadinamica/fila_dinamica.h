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
    T_apontador frente;
    T_apontador tras;
} T_fila;

void inicializar(T_fila* fila) {
    fila->frente = malloc(sizeof (T_celula));
    fila->tras = fila->frente;
    fila->frente->proximo = NULL;
}

bool vazia(T_fila* fila) {
    return (fila->frente == fila->tras);
}

void enfileirar(T_fila* fila, T_item item) {
    fila->tras->proximo = (T_apontador) malloc(sizeof (T_celula));
    fila->tras = fila->tras->proximo;
    fila->tras->item = item;
}

void desenfileirar(T_fila* fila) {
    if (vazia(fila)) {
        printf("Impossivel, a fila ja esta vazia");
    } else {
        T_apontador temp = fila->frente;
        fila->frente = fila->frente->proximo;
        free(temp);
    }
}

void imprimir(T_fila* fila) {
    T_apontador i = fila->frente;
    for (i = i->proximo; i != NULL; i = i->proximo) {
        printf("%d\n", i->item.valor);
    }
    printf("-----------------------\n");
}

int menu() {
    int op;
    printf("1-Enfileirar\n");
    printf("2-Desenfileirar\n");
    printf("3-Imprimir\n");
    printf("0-SAIR\n");
    scanf("%d", &op);
    printf("-----------------------\n");
    return op;
}