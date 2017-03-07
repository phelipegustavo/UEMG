#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>

typedef struct celula {
    int valor;
    struct celula *proximo;
} T_celula;

typedef struct {
    T_celula *primeiro;
    T_celula *ultimo;
} T_lista;

void inicializar(T_lista *aux) {
    aux->primeiro = (T_celula*) malloc(sizeof (T_celula));
    aux->ultimo = aux->primeiro;
    aux->ultimo->proximo = NULL;
}

bool vazia(T_lista *aux) {
    return aux->primeiro == aux->ultimo; //se forem iguais retorna true
}

void inserir(T_lista *aux, T_celula *item) {
    aux->ultimo->proximo = (T_celula*) malloc(sizeof (T_celula)); //Aloca espaço para inserir o item
    aux->ultimo = aux->ultimo->proximo; //ultimo passa a ser o espaço reservado para o item
    aux->ultimo->valor = item->valor; //o espaco reservado recebe o item
    aux->ultimo->proximo = NULL; //o posterior ao item é NULL indicando o fim da lista
}

void imprimir(T_lista *aux) {
    T_celula *item; //Item que vai percorrer a lista
    item = aux->primeiro->proximo; //Primeiro valor da lista
    if (vazia(aux)) {
        printf("Alista esta vazia!\n");
    } else {
        while (item != NULL) { //Ira percorrer ate o fim da lista
            printf("%5d\n", item->valor);
            item = item->proximo;
        }
    }
}

void retirar(T_lista *aux, T_celula *item) {
    T_celula *anterior, *atual;
    anterior = aux->primeiro; //Primeiro valor da lista
    atual = aux->primeiro->proximo; //Segundo valor da lista

    if (vazia(aux)) {
        printf("A lista ja esta vazia\n");
    } else {
        while (atual != NULL) { //Ira percorrer ate o fim da lista
            if (atual->valor == item->valor) {
                if (atual->valor == aux->primeiro->proximo->valor) { //caso item a remover estiver na primeira posição
                    aux->primeiro = aux->primeiro->proximo; //Primeiro valor passa a ser o proximo
                    break; //sai do laço

                }
                if (atual->valor == aux->ultimo->valor) { //caso item a remover estiver na ultima posição
                    aux->ultimo = anterior; //ultimo passa a ser o anterior a ele
                    aux->ultimo->proximo = NULL; //o posterior ao item é NULL indicando o fim da lista
                    break; //sai do laço

                } else { //caso o item estiver no meio da lista
                    anterior->proximo = atual->proximo; //remove o atual
                    free(aux);
                    break;
                }
            } else {
                anterior = anterior->proximo;
                atual = atual->proximo;
            }
        }
    }
}

bool crescente(T_lista *aux) {
    T_celula *anterior, *atual;
    anterior = aux->primeiro; //Primeiro valor da lista
    atual = aux->primeiro->proximo; //Segundo valor da lista

    while (atual != NULL) { //Ira percorrer ate o fim da lista
        if (anterior->valor > atual->valor) { //Não esta crescente
            return false;
            break; //sai do laço
        }
        anterior = anterior->proximo;
        atual = atual->proximo;

    }//Não saiu do laço logo esta crescente
    return true;
}

void copiar(T_lista *aux, T_lista *copia) {
    inicializar(copia);
    copia->primeiro = aux->primeiro;
    copia->ultimo = aux->ultimo;
}

int total_celulas(T_lista *aux) {
    int total = 0;
    T_celula *item; //Percorre a lista aux
    item = aux->primeiro->proximo;
    if (vazia(aux)) {
        return total; //retorna 0
    } else {
        while (item != NULL) {
            total += 1; //incrementa 1
            item = item->proximo;
        }
    }
    return total;
}

T_celula* meio(T_lista *aux) {
    T_celula *item; //sera a o item do meio da lista
    int metade = (total_celulas(aux) / 2);

    item = aux->primeiro->proximo;
    for (int i = 0; i < metade; i++) {
        item = item->proximo;
    }//apos percorrer ate a metade
    return item;
}

void inverter(T_lista *aux) {
    T_lista *temp = (T_lista*) malloc(sizeof (T_celula));
    inicializar(temp);

    if (vazia(aux)) {
        printf("A lista esta vazia\n");
    } else {
        while (!vazia(aux)) {
            inserir(temp, aux->ultimo);
            retirar(aux, aux->ultimo);
        }
    }
    inicializar(aux);
    copiar(temp, aux);

}

bool comparar(T_lista *aux, T_lista *aux2) {

    T_celula *item = (T_celula*) malloc(sizeof (T_celula));
    T_celula *item2 = (T_celula*) malloc(sizeof (T_celula));
    int op = 1;

    inicializar(aux2);
    while (op != 2) { //insere valores na lista "aux2"
        printf("Informe o item a inserir na lista 2: ");
        scanf("%d", &item2->valor);
        inserir(aux2, item2);
        printf("Inserir outro? < 1-Sim > < 2-Nao >: ");
        scanf("%d", &op);
    }

    item = aux->primeiro->proximo; //percorre a lista "aux"
    item2 = aux2->primeiro->proximo; //percorre a lista "aux2"

    if (total_celulas(aux) != total_celulas(aux2)) { //possuem tamanhos diferentes
        return false;
    }

    while (item != NULL) {
        if (item->valor != item2->valor) { //posuem valores diferentes
            return false;
            break;
        }
        item = item->proximo;
        item2 = item2->proximo;

    } //se não saiu do laço então são iguais

    return true;
}