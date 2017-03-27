#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <sys/time.h>
#include <stdbool.h>

typedef struct {
    int valor;
} T_item;

typedef struct T_celula* T_apontador;

typedef struct T_celula {
    T_apontador anterior, proximo;
    T_item item;
} T_celula;

typedef struct {
    T_apontador primeiro, ultimo;
} T_lista;

void inicializar(T_lista* lista) {
    lista->primeiro = NULL;
    lista->ultimo = NULL;
}

bool vazia(T_lista* lista) {
    return lista->primeiro == NULL && lista->ultimo == NULL;
}

void inserir(T_lista* lista, T_item item) {
    T_apontador aux = (T_apontador) malloc(sizeof (T_celula));
    aux->item = item;

    if (vazia(lista)) {
        aux->anterior = NULL;
        aux->proximo = NULL;
        lista->primeiro = aux;
        lista->ultimo = aux;
    } else {
        lista->ultimo->proximo = aux;
        aux->anterior = lista->ultimo;
        aux->proximo = NULL;
        lista->ultimo = aux;
    }
}

void imprimir(T_lista* lista) {
    int c = 1;
    printf("\n---------------------------------------------------\n");
    for (T_apontador i = lista->primeiro; i != NULL; i = i->proximo) {
        printf("%5d", i->item.valor);
        if (c % 10 == 0) {
            printf("\n");
        }
        c++;
    }

    printf("\n---------------------------------------------------\n");
}

void troca(T_lista* lista, int* passos) {
    for (T_apontador i = lista->primeiro; i->proximo != NULL; i = i->proximo) {
        for (T_apontador j = lista->primeiro; j->proximo != NULL; j = j->proximo) {
            if (j->item.valor > j->proximo->item.valor) {

                T_item temp = j->proximo->item;
                j->proximo->item = j->item;
                j->item = temp;
                (*passos)++;
            }
        }
    }
}

void selecao(T_lista* lista, int* passos) {
    T_apontador min = (T_apontador) malloc(sizeof (T_celula));

    for (T_apontador i = lista->primeiro; i != lista->ultimo; i = i->proximo) {
        min = i;
        for (T_apontador j = i->proximo; j != NULL; j = j->proximo) {
            if (j->item.valor < min->item.valor) {
                min = j;
                (*passos)++;
            }
        }
        if (i != min) {

            T_item temp = i->item;
            i->item = min->item;
            min->item = temp;
        }
    }
}

void insercao(T_lista* lista, int* passos) {
    T_apontador x = (T_apontador) malloc(sizeof (T_celula));
    T_apontador j = (T_apontador) malloc(sizeof (T_celula));

    for (T_apontador i = lista->primeiro; i != NULL; i = i->proximo) {
        x->item = i->item;

        if (i->anterior != NULL) {
            j = i->anterior;
            while (x->item.valor < j->item.valor) {
                j->proximo->item = j->item;
                if (j->anterior == NULL) {
                    T_apontador temp = (T_apontador) malloc(sizeof (T_celula));
                    temp->anterior = NULL;
                    temp->proximo = j;
                    j = temp;
                } else {
                    j = j->anterior;
                }
                (*passos)++;
            }
            j->proximo->item = x->item;
        }
    }
}