#include <stdio.h>
#include <stdlib.h>
#define MAX 10

//typedef long T_chave;
//typedef int T_indice;

typedef struct T_registro {
    long chave;
} T_registro;

typedef struct T_tabela {
    T_registro item[MAX + 1];
    int n;
} T_tabela;

void inicializar(T_tabela* T) {
    T->n = 0;
}

int Pesquisa(long X, T_tabela* T) {
    T->item[0].chave = X;
    int i = T->n + 1;

    do {
        i--;
    } while (T->item[i].chave != X);
    return i;
}

void Insere(T_registro Reg, T_tabela* T) {
    if (T->n == MAX) {
        printf("Erro: Tabela cheia\n");
    } else {
        T->n++;
        T->item[T->n] = Reg;
    }
}

void imprimir(T_tabela* T) {
    for (int i = 1; i <= T->n; i++) {
        printf("%5ld\n", T->item[i].chave);
    }
}

int Binaria(long int X, T_tabela* T) {
    int i, Esq, Dir;
    if (T->n == 0)
        return 0;
    else {
        Esq = 1;
        Dir = T->n;

        do {
            i = (Esq + Dir) / 2;
            if (X > T->item[i].chave)
                Esq = i + 1;
            else
                Dir = i - 1;

        } while (X != T->item[i].chave && Esq <= Dir);
        if (X == T->item[i].chave)
            return i;
        else
            return 0;
    }
}