#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct {
    int valor;
} T_item;

typedef struct T_celula* T_apontador;

typedef struct T_celula {
    T_apontador ant, prox;
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

T_apontador pesquisar(T_lista* lista, T_item item) {
    for (T_apontador i = lista->primeiro; i != NULL; i = i ->prox) {
        if (i->item.valor == item.valor)
            return i;
    }
}

void inserirInicio(T_lista* lista, T_item item) {
    T_apontador aux = (T_apontador) malloc(sizeof (T_celula));
    T_apontador pri = lista->primeiro;

    if (vazia(lista)) { //Se estiver vazia o ultimo devera ser igual ao primeiro
        lista->ultimo = aux;
    } else { //Caso contrario o anterior ao primeiro deve ser igual ao item inserido
        pri->ant = aux;
    }

    aux->item = item;
    aux->ant = NULL;
    lista->primeiro = aux;
    aux->prox = pri;
}

void inserirMeio(T_lista* lista, T_item item) {
    T_item x;
    printf("Informe o valor anterior ao item a ser inserido: ");
    scanf("%d", &x.valor);
    T_apontador itemAnt = pesquisar(lista, x);

    T_apontador novo = (T_apontador) malloc(sizeof (T_celula));

    novo->ant = itemAnt;
    novo->item = item;
    novo->prox = itemAnt->prox;
    itemAnt->prox = novo;
    novo->prox->ant = novo;
}

void inserirFim(T_lista* lista, T_item item) {
    T_apontador aux = (T_apontador) malloc(sizeof (T_celula));
    aux->item = item;

    if (vazia(lista)) {
        aux->ant = NULL;
        aux->prox = NULL;
        lista->primeiro = aux;
        lista->ultimo = aux;

    } else {
        lista->ultimo->prox = aux;
        aux->ant = lista->ultimo;
        aux->prox = NULL;
        lista->ultimo = aux;
    }
}

void retirar(T_lista* lista, T_item x) {
    if (vazia(lista)) {
        printf("impossivel, a lista esta vazia!\n");
    } else {
        T_apontador item = pesquisar(lista, x);
        if (item == lista->primeiro) {
            T_apontador pri = lista->primeiro;
            lista->primeiro = pri->prox;
            lista->primeiro->ant = NULL;
            free(pri);

        } else if (item == lista->ultimo) {
            T_apontador ult = lista->ultimo;
            T_apontador ultAnt = lista->ultimo->ant;
            lista->ultimo = ult->ant;
            lista->ultimo->ant = ultAnt->ant;
            lista->ultimo->prox = NULL;
            free(ult);

        } else {
            T_apontador ant = item->ant;
            T_apontador prox = item->prox;

            ant->prox = prox;
            prox->ant = ant;

            free(item);
        }
    }
}

void imprimir(T_lista* lista) {
    if (vazia(lista)) {
        printf("A lista esta vazia!\n");
    } else {
        for (T_apontador i = lista->primeiro; i != NULL; i = i->prox) {
            printf("%5d\n", i->item.valor);
        }
    }
}

void imprimirInverso(T_lista* lista) {
    if (vazia(lista)) {
        printf("A lista esta vazia!\n");
    } else {
        for (T_apontador i = lista->ultimo; i != NULL; i = i->ant) {
            printf("%5d\n", i->item.valor);
        }
    }
}

int menu() {
    int op;
    printf("------------------------------------------\n");
    printf("1 - Inserir item no inicio da lista\n");
    printf("2 - Inserir no meio da lista\n");
    printf("3 - Inserir no fim da lista\n");
    printf("4 - Retirar item\n");
    printf("5 - Imprimir\n");
    printf("6 - Imprimir Inversamente\n");
    printf("0 - SAIR\n");
    scanf("%d", &op);
    printf("------------------------------------------\n");
    return op;
}

T_item lerItem() {
    T_item item;
    printf("Informe o valor: ");
    scanf("%d", &item.valor);
    return item;
}