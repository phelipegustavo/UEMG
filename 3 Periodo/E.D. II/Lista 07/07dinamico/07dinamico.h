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

int posicao(T_lista* lista, T_item* item) {
    int count = 0;
    for (T_apontador i = lista->primeiro; i != NULL; i = i->proximo) {
        if (&i->item == item) {
            return count;
        }
        count++;
    }
    return -1;
}

void ShellSort(T_lista* lista, int* passos) {
    T_apontador i = (T_apontador) malloc(sizeof (T_celula));
    T_apontador j = (T_apontador) malloc(sizeof (T_celula));
    T_item x;
    int h = 1;

    do {
        h = h * 3 + 1;
    } while (h <= (posicao(lista, &lista->ultimo->item)));

    do {
        h /= 3;

        i = lista->primeiro; // i = h

        for (int count = h; count > 0; count--) {
            i = i->proximo;
        } //Agora i = h

        for (i; i != NULL; i = i->proximo) {
            x = i->item;
            j = i;

            T_apontador sub = lista->primeiro; //apontara para o item A[j-h];
            for (int count = (posicao(lista, &j->item) - h); count > 0; count--) {
                sub = sub->proximo;
            }// Agora sub = A[j-h]

            while (sub->item.valor > x.valor) {
                j->item = sub->item;

                sub = lista->primeiro;
                for (int count = (posicao(lista, &j->item) - h); count > 0; count--) {
                    sub = sub->proximo;
                }

                j = sub;

                if (posicao(lista, &j->item) < h)
                    break;

                sub = lista->primeiro;
                for (int count = (posicao(lista, &j->item) - h); count > 0; count--) {
                    sub = sub->proximo;
                }// Atualiza o valor de sub = A[j-h]
                (*passos)++;
            }
            j->item = x;
        }
    } while (h != 0);
}

bool valido(T_apontador Esq, T_apontador Dir) {
    if (Esq == NULL || Dir == NULL || Esq == Dir)
        return false;

    while (Esq->proximo != NULL) {
        Esq = Esq->proximo;
        if (Esq == Dir)
            return true;
    }
    return false;
}

void QuickSort(T_apontador Esq, T_apontador Dir, int *passos) {

    if (!valido(Esq, Dir))
        return;
    T_item pivo = Esq->item;
    T_apontador inicio = Esq;
    T_apontador fim = Dir;
    T_apontador aux = (T_apontador) malloc(sizeof (T_celula));
    bool cruzou = false;

    do {
        while (!cruzou && Esq->item.valor <= pivo.valor) {
            if (Esq == Dir)
                cruzou = true;
            Esq = Esq->proximo;
        }
        while (Dir->item.valor > pivo.valor) {
            if (Esq == Dir)
                cruzou = true;
            Dir = Dir->anterior;
        }
        if (!cruzou) {
            aux->item = Esq->item;
            Esq->item = Dir->item;
            Dir->item = aux->item;
        }
        (*passos)++;
    } while (!cruzou);
    aux->item = inicio->item;
    inicio->item = Dir->item;
    Dir->item = aux->item;

    if (inicio != Dir) QuickSort(inicio, Dir->anterior, passos);
    if (inicio != fim) QuickSort(Dir->proximo, fim, passos);
}

