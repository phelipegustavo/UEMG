#include <stdlib.h>
#include <stdio.h>
#include <time.h>
#include <sys/time.h>
#define MAX 2000

typedef struct {
    int valor;
} T_item;

typedef struct {
    int primeiro, ultimo;
    T_item lista[MAX];
} T_lista;

T_lista inicializar(T_lista aux) {
    aux.primeiro = 0;
    aux.ultimo = -1;
    return aux;
}

T_lista inserir(T_lista aux, T_item item) {
    if (aux.ultimo < MAX) {
        aux.ultimo++;
        aux.lista[aux.ultimo] = item;
    } else {
        printf("Impossivel!, lista cheia\n");
    }
    return aux;
}

T_lista troca(T_lista aux, int* passos) {
    int i, j;
    for (i = 0; i <= aux.ultimo; i++) {
        for (j = 0; j <= aux.ultimo; j++) {
            if (aux.lista[j].valor > aux.lista[j + 1].valor) {
                int temp = aux.lista[j].valor;
                aux.lista[j].valor = aux.lista[j + 1].valor;
                aux.lista[j + 1].valor = temp;
                (*passos)++;
            }
        }
    }
    return aux;
}

T_lista selecao(T_lista aux, int* passos) {
    int i, j, min;

    for (i = 0; i < aux.ultimo - 1; i++) {
        min = i;
        for (j = i + 1; j <= aux.ultimo; j++) {
            if (aux.lista[j].valor < aux.lista[min].valor) {
                min = j;
                (*passos)++;
            }
        }
        if (i != min) {
            int temp = aux.lista[i].valor;
            aux.lista[i].valor = aux.lista[min].valor;
            aux.lista[min].valor = temp;
        }
    }
    return aux;
}

T_lista insercao(T_lista aux, int* passos) {
    int i, j, x;
    for (i = 1; i <= aux.ultimo; i++) {
        x = aux.lista[i].valor;
        j = i - 1;

        while (x < aux.lista[j].valor && j >= 0) {
            aux.lista[j + 1].valor = aux.lista[j].valor;
            j--;
            (*passos)++;
        }
        aux.lista[j + 1].valor = x;
    }
    return aux;
}

void imprimir(T_lista aux) {
    int c = 1;
    printf("\n---------------------------------------------------\n");
    for (int i = 0; i <= aux.ultimo; i++) {
        printf("%5d", aux.lista[i].valor);
        if (c % 10 == 0) {
            printf("\n");
        }
        c++;
    }
    printf("\n---------------------------------------------------\n");
}