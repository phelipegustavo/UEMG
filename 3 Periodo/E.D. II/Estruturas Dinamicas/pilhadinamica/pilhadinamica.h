#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int valor;
} T_item;

typedef struct T_celula {
    T_item item;
    struct T_celula* prox;
} T_celula;

typedef struct T_celula* T_apontador;

typedef struct {
    T_apontador topo, fundo;
    int tamanho;
} T_pilha;

void inicializar(T_pilha* pilha) {
    pilha->topo = (T_apontador) malloc(sizeof (T_celula));
    pilha->fundo = pilha->topo;
    pilha->topo->prox = NULL;
    pilha->tamanho = 0;
}

void empilha(T_pilha* pilha, T_item* x) {
    T_celula* aux = (T_apontador) malloc(sizeof (T_celula));
    pilha->topo->item.valor = x->valor;
    aux->prox = pilha->topo;
    pilha->topo = aux;
    pilha->tamanho++;
}

void desempilha(T_pilha* pilha, T_item* x) {
    T_apontador q;
    if (pilha->topo == pilha->fundo) {
        printf("Pilha vazia!");
    } else {
        q = pilha->topo;
        pilha->topo = q->prox;
        x->valor = q->prox->item.valor;
        free(q);
        pilha->tamanho--;
    }
}

T_apontador pesquisar(T_pilha* pilha, T_item* item) {
    T_apontador aux = pilha->topo;

    for (aux = aux; aux != NULL; aux = aux->prox) {
        if (aux->item.valor == item->valor) {
            printf("%d", aux->item);
        }
    }


}

void imprimir(T_pilha *pilha) {
    T_apontador aux;
    aux = pilha->topo->prox;
    while (aux != NULL) {
        printf("%5d\n", aux->item.valor);
        aux = aux->prox;
    }
}