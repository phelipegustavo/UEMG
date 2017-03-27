#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

typedef struct {
    char letra;
} T_letra;

typedef struct celula {
    struct celula* proximo;
    T_letra item;
} T_celula;

typedef struct celula* T_apontador;

typedef struct {
    T_apontador topo, fundo;
} T_palavra;

void inicializar(T_palavra* palavra) {
    palavra->topo = (T_apontador) malloc(sizeof (T_celula));
    palavra->fundo = palavra->topo;
    palavra->fundo->proximo = NULL;
}

bool vazia(T_palavra* palavra) {
    return palavra->topo == palavra->fundo;
}

void empilhar_letra(T_palavra* palavra, char letraX) {
    T_apontador aux = (T_apontador) malloc(sizeof (T_celula));
    palavra->topo->item.letra = letraX;
    aux->proximo = palavra->topo;
    palavra->topo = aux;
}

void empilhar_palavra(T_palavra* palavra, char palavraX[]) {
    for (int i = strlen(palavraX) - 1; i >= 0; i--) {
        empilhar_letra(palavra, palavraX[i]);
    }
}

void imprimir(T_palavra* palavra) {
    T_apontador aux = palavra->topo;
    for (aux = aux->proximo; aux != NULL; aux = aux->proximo) {
        printf("%c", aux->item.letra);
    }
    printf("\n");
}

bool palindromo(T_palavra* palavra) {
    T_apontador i = palavra->topo;
    T_palavra* palavra_teste = (T_palavra*) malloc(sizeof (T_celula));

    //palavra invertida
    inicializar(palavra_teste);

    for (i = i->proximo; i != NULL; i = i->proximo) {
        empilhar_letra(palavra_teste, i->item.letra);
    }

    //Compara as duas palavras
    i = palavra->topo->proximo;
    T_apontador j = palavra_teste->topo->proximo;

    while (j->proximo != NULL) {
        if (i->item.letra != j->item.letra) {
            return false;
        }
        i = i->proximo;
        j = j->proximo;
    }
    return true;
}

void teste(T_palavra* palavra, char palavraX[]) {
    empilhar_palavra(palavra, palavraX);
    if (palindromo(palavra)) {
        printf("A palavra %s é um palíndromo\n", palavraX);
    } else {
        printf("A palavra %s não é um palíndromo\n", palavraX);
    }
    inicializar(palavra);
}