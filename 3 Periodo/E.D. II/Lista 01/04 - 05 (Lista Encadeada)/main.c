#include <stdio.h>
#include <stdlib.h>

typedef struct T_celula {
    int valor;
    struct T_celula *proximo;
} T_celula;

typedef struct {
    T_celula *primeiro;
    T_celula *ultimo;
} T_lista;

void inicializar(T_lista *aux) {
    aux->primeiro = (T_celula*) malloc(sizeof (T_celula));
    aux->ultimo = aux->primeiro;
}

void inserir(T_lista *aux, T_celula *item) {
    aux->ultimo->proximo = (T_celula*) malloc(sizeof (T_celula));
    aux->ultimo = aux->ultimo->proximo;
    aux->ultimo->valor = item->valor;
    aux->ultimo->proximo = NULL;
}

void retirar(T_lista *aux, T_celula *item) {
    T_celula *anterior = aux->primeiro;
    T_celula *atual = anterior->proximo;

    while (atual != NULL) {
        if (atual->valor == item->valor) {
            if (atual == aux->primeiro->proximo) {
                aux->primeiro->proximo = aux->primeiro->proximo->proximo;
            } else if (atual == aux->ultimo) {
                aux->ultimo = anterior;
                aux->ultimo->proximo = NULL;
            } else {
                anterior->proximo = atual->proximo;
            }
        }
        atual = atual->proximo;
        anterior = anterior->proximo;
    }

}

void retirarX(T_lista *aux, int x) {
    T_celula *temp = aux->primeiro->proximo;
    int i = 0;
    while (i < x) {
        inserir(aux, aux->primeiro->proximo);
        retirar(aux, aux->primeiro->proximo);
        i++;
        temp = temp->proximo;
    }

}

void retirarPar(T_lista *aux) {
    T_celula *temp = aux->primeiro;
    for (temp = temp->proximo; temp != NULL; temp = temp->proximo) {
        if (temp->valor % 2 == 0){
            retirar(aux,temp);
        }
    }
}

void imprimir(T_lista *aux) {
    T_celula *temp = aux->primeiro;
    for (temp = temp->proximo; temp != NULL; temp = temp->proximo) {
        printf("%d\n", temp->valor);
    }
}

int main() {
    T_lista *aux = (T_lista*) malloc(sizeof (T_celula));
    T_celula *item = (T_celula*) malloc(sizeof (T_celula));

    inicializar(aux);

    item->valor = 5;
    inserir(aux, item);
    item->valor = 10;
    inserir(aux, item);
    item->valor = 15;
    inserir(aux, item);
    item->valor = 20;
    inserir(aux, item);

    retirarPar(aux);

    retirarX(aux, 1);
    imprimir(aux);
    return 0;
}