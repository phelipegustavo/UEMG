#include "pilhadinamica.h"

//Quetão 06

/* Utilizando da mesma biblioteca e main desenvolvidos em sala, faça uma 
 * função para retornar o número de elementos da pilha que possuem valor ímpar.
 */

int menu();

int main() {
    T_pilha* pilha = (T_pilha*) malloc(sizeof (T_celula));
    T_item* item = (T_item*) malloc(sizeof (T_item));

    int op = 1;

    inicializar(pilha);

    while (op != 0) {
        op = menu();

        switch (op) {
            case 1:
                ler_item(item);
                empilhar(pilha, item);
                break;

            case 2:
                desempilha(pilha, item);
                printf("O item de valor %d foi removido\n", item->valor);
                break;

            case 3:
                printf("A pilha possui %d itens\n", pilha->tamanho);
                break;

            case 4:
                imprimir(pilha);
                break;
            case 5:
                printf("Total de numeros ímpares : %d\n", impares(pilha));
                break;
        }
        printf("------------------------\n");
    }
    return 0;
}

int menu() {
    int op = 1;
    printf("1- Empilhar\n");
    printf("2- Desempilhar\n");
    printf("3- Tamanho da pilha\n");
    printf("4- Imprimir\n");
    printf("5- Retornar total de impares\n");
    printf("0- SAIR\n");
    printf("Digite um opção: ");
    scanf("%d", &op);
    printf("------------------------\n");
    return op;
}