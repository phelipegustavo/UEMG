#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

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

void insere(T_apontador* raiz, T_registro x) {
    if ((*raiz) == NULL) {
        (*raiz) = (T_apontador) malloc(sizeof (T_no));
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
        return;
    } else
        printf("Erro: Registro já existente na árvore!\n");
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

void retira(T_apontador *p, T_registro x) {
    T_apontador aux;
    if (*p == NULL) {
        printf("Erro: Registro nao esta presente na arvore\n");
        return;
    }
    if (x.valor < (*p)->reg.valor) {
        retira(&(*p)->esq, x);
        return;
    }
    if (x.valor > (*p)->reg.valor) {
        retira(&(*p)->dir, x);
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

void busca(T_apontador* raiz, T_registro x, T_registro* pai) {
    if (*raiz == NULL) {
        x.valor = -1;
        (*pai).valor = -1;
        return;
    }
    if (x.valor < (*raiz)->reg.valor) {
        (*pai) = (*raiz)->reg;
        busca(&(*raiz)->esq, x, pai);
        return;
    }
    if (x.valor > (*raiz)->reg.valor) {
        (*pai) = (*raiz)->reg;
        busca(&(*raiz)->dir, x, pai);
        return;
    } else {
        x = (*raiz)->reg;
    }
}

void irmao(T_apontador* raiz, T_registro pai, T_registro item, T_registro* irmaoo) {
    if (*raiz == NULL) {
        return;
    }
    if (pai.valor < (*raiz)->reg.valor) {
        irmao(&(*raiz)->esq, pai, item, irmaoo);
        return;
    }
    if (pai.valor > (*raiz)->reg.valor) {
        irmao(&(*raiz)->dir, pai, item, irmaoo);
        return;
    } else {

        if ((*raiz)->esq != NULL && (*raiz)->esq->reg.valor == item.valor) {
            if ((*raiz)->dir != NULL)
                (*irmaoo) = (*raiz)->dir->reg;
            else
                (*irmaoo).valor = -1;
        } else if ((*raiz)->dir != NULL && (*raiz)->dir->reg.valor == item.valor) {
            if ((*raiz)->esq != NULL)
                (*irmaoo) = (*raiz)->esq->reg;
            else
                (*irmaoo).valor = -1;
        }
    }
}

void buscar(T_apontador* raiz, T_registro x) {
    T_registro pai, avo, irmaoo;

    printf("Item: %d\n", x.valor);
    if ((*raiz)->reg.valor == x.valor) {
        printf("Nao possui pai, avo ou irmao\n");
    } else {
        busca(raiz, x, &pai);


        printf("Pai: %d\n", pai.valor);

        busca(raiz, pai, &avo);


        if (avo.valor != -1)
            printf("Avo: %d\n", avo.valor);
        else
            printf("Nao possui avo\n");
        irmao(raiz, pai, x, &irmaoo);
        if (irmaoo.valor != -1)
            printf("Irmao: %d\n", irmaoo.valor);
        else
            printf("Nao possui irmao\n");

    }
}

void imprimir(T_apontador *raiz) {
    if ((*raiz) != NULL) {
        printf("%5d\n", (*raiz)->reg.valor);
    }
    if ((*raiz)->esq != NULL) {
        imprimir(&(*raiz) ->esq);
    }
    if ((*raiz)->dir != NULL) {
        imprimir(&(*raiz) -> dir);
    }
}

void folhas(T_apontador* raiz, int* total) {
    if (*raiz != NULL) {
        if ((*raiz)->esq == NULL && (*raiz)->dir == NULL) {
            (*total)++;
            return;
        }
    }
    if ((*raiz)->esq != NULL) {
        folhas(&(*raiz)->esq, total);
    }
    if ((*raiz)->dir != NULL) {
        folhas(&(*raiz)->dir, total);
    }
}

void nos(T_apontador* raiz, int* total) {
    if (*raiz != NULL) {
        if ((*raiz)->esq != NULL || (*raiz)->dir != NULL)
            (*total)++;
    } else {
        return;
    }
    if ((*raiz)->esq != NULL) {
        nos(&(*raiz)->esq, total);
    }
    if ((*raiz)->dir != NULL) {
        nos(&(*raiz)->dir, total);
    }
}

void compara(T_apontador* raiz, T_apontador* aux, int* resultado) {
    if (*raiz != NULL && *aux != NULL && (*raiz)->reg.valor == (*aux)->reg.valor) {
        *resultado = 1;
    } else {
        *resultado = 0;
        return;
    }
    if ((*raiz)->esq != NULL || (*aux)->esq != NULL) {
        compara(&(*raiz)->esq, &(*aux)->esq, resultado);
    }
    if ((*raiz)->dir != NULL || (*aux)->dir != NULL) {
        compara(&(*raiz)->dir, &(*aux)->dir, resultado);
    }
}

void soma_nos(T_apontador* raiz, float *soma) {
    if (*raiz == NULL)
        return;
    else
        *soma += (*raiz)->reg.valor;
    if ((*raiz)->esq != NULL) {
        soma_nos(&(*raiz)->esq, soma);
    }
    if ((*raiz)->dir != NULL) {
        soma_nos(&(*raiz)->dir, soma);
    }

}

void crescente(T_apontador* raiz) {
    if (*raiz == NULL) {
        return;
    }
    if ((*raiz)->esq != NULL) {
        crescente(&(*raiz)->esq);
    }
    printf("%5d\n", (*raiz)->reg.valor);
    if ((*raiz)->dir != NULL) {
        crescente(&(*raiz)->dir);
    }
}

int altura(T_apontador* raiz) {
    int alt1, alt2;
    if (*raiz == NULL) {
        return -1;
    }
    alt1 = altura(&(*raiz)->esq);
    alt2 = altura(&(*raiz)->dir);
    if (alt1 > alt2) return alt1 + 1;
    else return alt2 + 1;
}
