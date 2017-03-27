#include "Pilha_fila.h"

//Questão 03

/* Crie uma biblioteca para construir estruturas de Pilha e Fila. Nesta 
 * biblioteca crie uma função que receba como parâmetro uma Fila não vazia, 
 * e utilizando de uma pilha (inicialmente vazia) e apenas os testes de fila 
 * e pilha vazias, as operações Enfileira, Desenfileira, Empilha, Desempilha, 
 * feitos em sala, escreva uma função que inverta a ordem dos elementos da fila. 
 * No main, preencha a Fila com 10 elementos inteiros aleatórios, chame a função 
 * e imprima a fila alterada.*/

int main() {
    T_pilha* pilha = (T_pilha*) malloc(sizeof (T_celula));
    T_fila* fila = (T_fila*) malloc(sizeof (T_celula));
    T_item item;

    int op = 1;

    inicializar_fila(fila);
    inicializar_pilha(pilha);

    while (op != 0) {
        op = menu();

        switch (op) {
            case 1:
                printf("Informe o valor : ");
                scanf("%d", &item.valor);
                enfileirar(fila, item);
                break;
            case 2:
                desenfileirar(fila);
                break;
            case 3:
                imprimir_fila(fila);
                break;
            case 4:
                inverter_fila(fila, pilha);
                printf("Pilha invertida: \n");
                imprimir_fila(fila);
                break;
        }
    }
    return 0;
}