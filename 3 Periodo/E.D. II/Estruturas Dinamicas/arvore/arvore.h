#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int valor;
} T_registro;

typedef struct T_no* T_apontador;

typedef struct T_no {
    T_registro reg;
    T_apontador esq, dir;
} T_no;

void inicializa(T_apontador* raiz) {
    *raiz = NULL;
}

void insere(T_registro x, T_apontador* p) {
    if (*p == NULL) {
        *p = (T_apontador) malloc(sizeof (T_no));
        (*p)->reg = x;
        (*p)->esq = NULL;
        (*p)->dir = NULL;
        return;
    }
    if (x.valor < (*p)->reg.valor) {
        insere(x, &(*p)->esq);
        return;
    }
    if (x.valor > (*p)->reg.valor)
        insere(x, &(*p)->dir);
    else
        printf("Erro: Registro ja existe na arvore\n");
}

void pesquisa(T_registro* x, T_apontador* p) {
    if (*p == NULL) {
        printf("Erro: Registro não está presente na arvore\n");
        return;
    }
    if (x->valor < (*p)->reg.valor) {
        pesquisa(x, &(*p)->esq);
        return;
    }
    if (x->valor > (*p)->reg.valor)
        pesquisa(x, &(*p)->dir);
    else
        *x = (*p)->reg;
}

void antecessor(T_apontador q, T_apontador* p) {
    if ((*p)->dir != NULL) {
        antecessor(q, &(*p)->dir);
        return;
    }
    q->reg = (*p)->reg;
    q = *p;
    *p = (*p)->esq;
    free(q);
}

void retira(T_registro x, T_apontador *p) {
    T_apontador aux;
    if (*p == NULL) {
        printf("Erro: Registro nao esta presente na arvore\n");
        return;
    }
    if (x.valor < (*p)->reg.valor) {
        retira(x, &(*p)->esq);
        return;
    }
    if (x.valor > (*p)->reg.valor) {
        retira(x, &(*p)->dir);
        return;
    }
    if ((*p)->dir == NULL) {
        aux = *p;
        *p = (*p)->esq;
        free(aux);
        return;
    }
    if ((*p)->esq != NULL) {
        antecessor(*p, &(*p)->esq);
        return;
    }
    aux = *p;
    *p = (*p)->dir;
    free(aux);
}

void imprimir(T_apontador *p) {
    if ((*p) != NULL) {
        printf("%5d\n", (*p)->reg.valor);
    }
    if ((*p)->esq != NULL) {
        imprimir(&(*p) ->esq);
    }
    if ((*p)->dir != NULL) {
        imprimir(&(*p) -> dir);
    }

}