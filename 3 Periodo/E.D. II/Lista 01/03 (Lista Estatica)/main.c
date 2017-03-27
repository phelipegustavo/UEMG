/*3.Construa uma função que recebe como parâmetros uma Lista ( L1 ) e 
 * um valor inteiro ( X ) e que retire os primeiros X elementos da lista 
 * L1, inserindo-os no fim da mesma. Suponha que a lista está inicialmente 
 * preenchida. É proibido o uso de uma lista auxiliar. Obs.: Considere 
 * lista estática e Não se esqueça de regularizar as variáveis de controle.*/

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#define MAX 10

typedef struct {
    int valor;
} T_chave;

typedef struct {
    int primeiro;
    int ultimo;
    T_chave lista[MAX];
} T_lista;

T_lista inicializar(T_lista aux) {
    aux.primeiro = 0;
    aux.ultimo = -1;
    return aux;
}

int vazia(T_lista aux) {
    return (aux.ultimo == -1) ? 1 : 0;
}

T_lista inserir(T_lista aux, T_chave item) {
    aux.ultimo++;
    aux.lista[aux.ultimo] = item;
    return aux;
}

int pesquisar(T_lista aux, T_chave item) {
    if (vazia(aux) == 0) {
        for (int i = aux.primeiro; i <= aux.ultimo; i++) {
            if (aux.lista[i].valor == item.valor)
                return i;
        }
    }
    return -1;
}

T_lista retirar(T_lista aux, T_chave item) {
    int posicao = pesquisar(aux, item);
    if (vazia(aux) == 0) {
        for (int i = aux.primeiro; i <= aux.ultimo; i++) {
            aux.lista[i].valor = aux.lista[i + 1].valor;
        }
        aux.ultimo--;
    }
    return aux;
}

T_lista retiraX(T_lista aux, int x) {
    if (x > (MAX - 1) - aux.ultimo) {
        printf("Impossível retirar, espaço indisponível");
    } else {
        for (int i = aux.primeiro; i < x; i++) {
            aux = inserir(aux, aux.lista[i]);
        }
        aux.primeiro = x;
    }
    return aux;
}

void imprimir(T_lista aux) {
    for (int i = aux.primeiro; i <= aux.ultimo; i++) {
        printf("%d\n", aux.lista[i].valor);
    }
}

int main() {
    T_lista aux;
    T_chave item;

    aux = inicializar(aux);

    item.valor = 1;
    aux = inserir(aux, item);

    item.valor = 2;
    aux = inserir(aux, item);

    item.valor = 3;
    aux = inserir(aux, item);

    item.valor = 4;
    aux = inserir(aux, item);

    aux = retiraX(aux, 2);

    imprimir(aux);
    return 0;
}