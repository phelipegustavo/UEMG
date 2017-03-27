#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct {
    int valor;
} T_item;

typedef struct celula {
    struct celula* proximo;
    T_item item;
} T_celula;

typedef T_celula* T_apontador;

typedef struct {
    T_apontador topo, fundo;
    int tamanho;
} T_pilha;

void inicializar(T_pilha* pilha) {
    pilha->topo = (T_apontador) malloc(sizeof (T_celula));
    pilha->fundo = pilha->topo;
    pilha->fundo->proximo = NULL;
    pilha->tamanho = 0;
}

bool vazia(T_pilha* pilha) {
    return pilha->topo == pilha->fundo;
}

void empilhar(T_pilha* pilha, T_item* item) {
    T_apontador aux = (T_apontador) malloc(sizeof (T_celula));
    pilha->topo->item.valor = item->valor;
    aux->proximo = pilha->topo;
    pilha->topo = aux;
    pilha->tamanho++;
}

void desempilha(T_pilha* pilha, T_item* item) {
    if (vazia(pilha)) {
        printf("A pilha ja esta vazia!\n");
    } else {
        T_apontador aux = pilha->topo;
        pilha->topo = aux->proximo;
        item->valor = aux->proximo->item.valor;
        free(aux);
        pilha->tamanho--;
    }
}

void imprimir(T_pilha* pilha) {
    if (vazia(pilha)) {
        printf("A pilha esta vazia\n");
    } else {
        T_apontador aux = pilha->topo;
        for (aux = aux->proximo; aux != NULL; aux = aux->proximo) {
            printf("%5d\n", aux->item.valor);
        }
    }
}

void ler_item(T_item* item) {
    printf("Informe o valor do item: ");
    scanf("%d", &item->valor);
}

//Exercício 01

int posicao(T_pilha* pilha, T_item* item) {
    T_apontador aux = pilha->topo;
    int posicao = 0;
    for (aux = aux->proximo; aux != NULL; aux = aux->proximo) {
        if (aux->item.valor == item->valor) {
            return pilha->tamanho - posicao;
        }
        posicao++;
    }
    return 0;

}

//Exercício 03

void ordenacao(T_pilha* pilha) {
    T_apontador i = pilha->topo;
    T_apontador j = pilha->topo;
    T_apontador aux = (T_apontador) malloc(sizeof (T_celula));

    for (i = i->proximo; i != NULL; i = i->proximo) {
        for (j = i->proximo; j != NULL; j = j->proximo) {
            if (j->item.valor > i->item.valor) {
                aux->item.valor = j->item.valor;
                j->item.valor = i->item.valor;
                i->item.valor = aux->item.valor;
            }
        }
    }
}

//Exercício 04

void print(T_pilha* pilha) {
    T_apontador i = pilha->topo;
    int maior = pilha->topo->item.valor;
    int menor = pilha->topo->item.valor;
    int soma = 0;
    float media = 0;

    for (i = i->proximo; i != NULL; i = i->proximo) {
        if (i->item.valor > maior) {
            maior = i->item.valor;
        }
        if (i->item.valor < menor) {
            menor = i->item.valor;
        }
        soma += i->item.valor;
    }
    media = soma / pilha->tamanho;
    printf("Maior: %d\n", maior);
    printf("Menor: %d\n", menor);
    printf("Media: %.2f\n", media);
}

//Exercicio 05

void backup(T_pilha* pilha, T_pilha* copia) {
    T_apontador i = pilha->topo;
    T_apontador aux = pilha->topo;
    int tamanho_copia = pilha->tamanho;
    inicializar(copia);
    for (aux = aux->proximo; aux != NULL; aux = aux->proximo) {
        for (int k = tamanho_copia; k > 0; k--) {
            i = i->proximo;
        }
        empilhar(copia, &i->item);
        tamanho_copia--;
        i = pilha->topo;
    }
}

//Exercício 06

int impares(T_pilha* pilha) {
    int impar = 0;
    T_apontador i = pilha->topo;

    for (i = i->proximo; i != NULL; i = i->proximo) {
        if (i->item.valor % 2 != 0) {
            impar++;
        }
    }
    return impar;
}