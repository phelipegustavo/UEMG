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

//TAD PILHA

typedef struct {
    T_apontador fundo, topo;
} T_pilha;

//TAD FILA

typedef struct {
    T_apontador frente, tras;
} T_fila;

//Funções pilha

void inicializar_pilha(T_pilha* pilha) {
    pilha->topo = (T_apontador) malloc(sizeof (T_celula));
    pilha->fundo = pilha->topo;
    pilha->topo->proximo = NULL;
}

bool pilha_vazia(T_pilha* pilha) {
    return pilha->topo == pilha->fundo;
}

void empilhar(T_pilha* pilha, T_item item) {
    T_apontador aux = (T_apontador) malloc(sizeof (T_celula));
    pilha->topo->item = item;
    aux->proximo = pilha->topo;
    pilha->topo = aux;
}

void desempilhar(T_pilha* pilha) {
    if (pilha_vazia(pilha)) {
        printf("Impossivel, a pilha ja esta vazia!\n");
    } else {
        T_apontador desempilhado = pilha->topo->proximo;
        pilha->topo = pilha->topo->proximo;
        free(desempilhado);
    }
}

void imprimir_pilha(T_pilha* pilha) {
    if (pilha_vazia(pilha)) {
        printf("A pilha esta vazia\n");
    } else {
        for (T_apontador i = pilha->topo->proximo; i != NULL; i = i->proximo) {
            printf("%5d\n", i->item.valor);
        }
    }
}

//Funções fila

void inicializar_fila(T_fila* fila) {
    fila->frente = (T_apontador) malloc(sizeof (T_celula));
    fila->tras = fila->frente;
    fila->tras->proximo = NULL;
}

bool fila_vazia(T_fila* fila) {
    return fila->frente == fila->tras;
}

void enfileirar(T_fila*fila, T_item item) {
    fila->tras->proximo = (T_apontador) malloc(sizeof (T_celula));
    fila->tras = fila->tras->proximo;
    fila->tras->item = item;
    fila->tras->proximo = NULL;
}

void desenfileirar(T_fila* fila) {
    if (fila_vazia(fila)) {
        printf("Impossivel, a fila ja esta vazia!\n");
    } else {
        T_apontador desenfileirado = fila->frente->proximo;
        fila->frente = fila->frente->proximo;
        free(desenfileirado);
    }
}

void imprimir_fila(T_fila* fila) {
    if (fila_vazia(fila)) {
        printf("A fila esta vazia\n");
    } else {
        for (T_apontador i = fila->frente->proximo; i != NULL; i = i->proximo) {
            printf("%5d\n", i->item.valor);
        }
    }
}

void inverter_fila(T_fila* fila, T_pilha* pilha) {
    for (T_apontador i = fila->frente->proximo; i != NULL; i = i->proximo) {
        empilhar(pilha, i->item);
    }
    inicializar_fila(fila);
    for (T_apontador i = pilha->topo->proximo; i != NULL; i = i->proximo) {
        enfileirar(fila, i->item);
    }
    inicializar_pilha(pilha);
}

int menu(){
    int op = 1;
    printf("1- Enfileirar\n");
    printf("2- Desenfileirar\n");
    printf("3- Imprimir\n");
    printf("4- Inverter (utilizando pilha)\n");
    printf("0- SAIR\n");
    scanf("%d", &op);
    return op;
}