#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int valor;
} T_registro;

typedef struct T_no* T_apontador;

typedef struct T_no {
    T_registro reg;
    T_apontador esq, dir;
    int peso;
} T_no;

void inicializa(T_apontador* raiz) {
    *raiz = NULL;
}

void insere(T_apontador* raiz, T_registro x) {
    if (*raiz == NULL) {
        *raiz = (T_apontador) malloc(sizeof (T_no));
        (*raiz)->reg = x;
        (*raiz)->esq = NULL;
        (*raiz)->dir = NULL;
        return;
    }
    if (x.valor < (*raiz)->reg.valor) {
        insere(&(*raiz)->esq, x);
        return;
    }
    if (x.valor > (*raiz)->reg.valor) {
        insere(&(*raiz)->dir, x);
    } else {
        printf("Erro: Registro já existente na árvore!\n");
    }
}

void pesquisa(T_apontador* raiz, T_registro* x) {
    if (*raiz == NULL) {
        printf("Erro: Registro não encontrado na arvore!\n");
        return;
    }
    if (x->valor < (*raiz)->reg.valor) {
        pesquisa(&(*raiz)->esq, x);
        return;
    }
    if (x->valor > (*raiz)->reg.valor) {
        pesquisa(&(*raiz)->dir, x);
    } else
        *x = (*raiz)->reg;
}

void antecessor(T_apontador* raiz, T_apontador q) {
    if ((*raiz)->dir != NULL) {
        antecessor(&(*raiz)->dir, q);
        return;
    }
    q->reg = (*raiz)->reg;
    q = *raiz;
    *raiz = (*raiz)->esq;
    free(q);
}

void retira(T_apontador* raiz, T_registro x) {
    T_apontador aux;
    if (*raiz == NULL) {
        printf("Erro: Registro não está presente na áervore\n");
        return;
    }
    if (x.valor < (*raiz)->reg.valor) {
        retira(&(*raiz)->esq, x);
        return;
    }
    if (x.valor > (*raiz)->reg.valor) {
        retira(&(*raiz)->dir, x);
        return;
    }
    if ((*raiz)->dir == NULL) {
        aux = *raiz;
        *raiz = (*raiz)->esq;
        free(aux);
        return;
    }
    if ((*raiz)->esq != NULL) {
        antecessor(&(*raiz)->esq, *raiz);
        return;
    }
    aux = *raiz;
    *raiz = (*raiz)->dir;
    free(aux);
}

void imprimirERD(T_apontador* raiz) {
    if (*raiz == NULL) {
        return;
    }
    if ((*raiz)->esq != NULL) {
        imprimirERD(&(*raiz)->esq);
    }
    printf("%5d\n", (*raiz)->reg.valor);
    if ((*raiz)->dir != NULL) {
        imprimirERD(&(*raiz)->dir);
    }
}

void imprimirRED(T_apontador* raiz) {
    if (*raiz != NULL) {
        printf("%5d\n", (*raiz)->reg.valor);
    }
    if ((*raiz)->esq != NULL) {
        imprimirRED(&(*raiz)->esq);
    }
    if ((*raiz)->dir != NULL) {
        imprimirRED(&(*raiz)->dir);
    } else {
        return;
    }
}

void imprimirEDR(T_apontador* raiz) {
    if (*raiz == NULL) {
        return;
    }
    if ((*raiz)->esq != NULL) {
        imprimirEDR(&(*raiz)->esq);
    }
    if ((*raiz)->dir != NULL) {
        imprimirEDR(&(*raiz)->dir);
    }
    printf("%5d\n", (*raiz)->reg.valor);
}

int getPeso(T_apontador * raiz) {
    if (*raiz == NULL)
        return 0;
    else
        return (*raiz)->peso;
}

int maxPeso(int esqPeso, int dirPeso) {
    if (esqPeso > dirPeso)
        return esqPeso;
    else
        return dirPeso;
}

void simplesDir(T_apontador * raiz) {
    T_apontador aux;

    aux = (*raiz)->esq;
    (*raiz)->esq = aux->dir;
    aux->dir = *raiz;
    (*raiz)->peso = maxPeso(getPeso(&(*raiz)->esq), getPeso(&(*raiz)->dir)) + 1;
    aux->peso = maxPeso(getPeso(&aux->esq), (*raiz)->peso) + 1;
    *raiz = aux;
}

void simplesEsq(T_apontador * raiz) {
    T_apontador aux;

    aux = (*raiz)->dir;
    (*raiz)->dir = aux->esq;
    aux->esq = *raiz;
    (*raiz)->peso = maxPeso(getPeso(&(*raiz)->esq), getPeso(&(*raiz)->dir)) + 1;
    aux->peso = maxPeso(getPeso(&aux->dir), (*raiz)->peso) + 1;
    *raiz = aux;
}

void duplaEsqDir(T_apontador * raiz) {
    simplesEsq(&(*raiz)->esq);
    simplesDir(raiz);
}

void duplaDirEsq(T_apontador * raiz) {
    simplesDir(&(*raiz)->dir);
    simplesEsq(raiz);
}

void insereBalanceado(T_apontador* raiz, T_registro x) {
    if (*raiz == NULL) {
        *raiz = (T_apontador) malloc(sizeof (T_no));
        (*raiz)->reg = x;
        (*raiz)->peso = 0;
        (*raiz)->esq = NULL;
        (*raiz)->dir = NULL;
    } else if (x.valor < (*raiz)->reg.valor) {
        insereBalanceado(&(*raiz)->esq, x);

        if (getPeso(&(*raiz)->esq) - getPeso(&(*raiz)->dir) == 2) {
            if (x.valor < (*raiz)->esq->reg.valor)
                simplesDir(raiz);
            else
                duplaEsqDir(raiz);
        }
    } else if (x.valor > (*raiz)->reg.valor) {
        insereBalanceado(&(*raiz)->dir, x);

        if (getPeso(&(*raiz)->dir) - getPeso(&(*raiz)->esq) == 2) {
            if (x.valor > (*raiz)->dir->reg.valor)
                simplesEsq(raiz);
            else
                duplaDirEsq(raiz);
        }
    }
    (*raiz)->peso = maxPeso(getPeso(&(*raiz)->esq), getPeso(&(*raiz)->dir))+1;
}