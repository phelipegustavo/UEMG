#include <stdlib.h>
#include <stdio.h>
#include <time.h>
#include <sys/time.h>
#define MAX 20000

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

void imprimir(T_lista* aux) {
    int c = 1;
    printf("\n---------------------------------------------------\n");
    int i;
    for (i = 0; i <= aux->ultimo; i++) {
        printf("%5d", aux->lista[i].valor);
        if (c % 10 == 0) {
            printf("\n");
        }
        c++;
    }
    printf("\n---------------------------------------------------\n");
}

void ShellSort(T_lista* lista, int n, int* passos) {
    int i, j;
    int h = 1;
    int x;

    do
        h = h * 3 + 1;
    while (h < n);

    do {
        h /= 3;
        for (i = h; i < n; i++) {
            x = lista->lista[i].valor;
            j = i;
            while (lista->lista[j - h].valor > x) {
                lista->lista[j].valor = lista->lista[j - h].valor;
                j -= h;
                if (j < h)
                    break;
                (*passos)++;
            }
            lista->lista[j].valor = x;
        }
    } while (h != 1);
}

void particao(int Esq, int Dir, int* i, int* j, T_lista * lista) {
    int x, w;
    *i = Esq;
    *j = Dir;

    x = lista->lista[(*i + *j) / 2].valor;

    do {
        while (x > lista->lista[*i].valor)
            (*i)++;

        while (x < lista->lista[*j].valor)
            (*j)--;

        if (*i <= *j) {
            w = lista->lista[*i].valor;
            lista->lista[*i].valor = lista->lista[*j].valor;
            lista->lista[*j].valor = w;
            (*i)++;
            (*j)--;
        }
    } while (*i <= *j);
}

void Ordena(int Esq, int Dir, T_lista* lista, int* passos) {
    int i, j;
    
    (*passos)++;
    
    particao(Esq, Dir, &i, &j, lista);
    if (Esq < j) {
        Ordena(Esq, j, lista, passos);
    }
    if (i < Dir) {
        Ordena(i, Dir, lista, passos);
    }    
}

void QuickSort(T_lista* lista, int n, int* passos) {
    *passos = 0;
    Ordena(0, n-1, lista, passos);
}

