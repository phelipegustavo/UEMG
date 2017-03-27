#include "pilhadinamica.h"

//Quetão 05

/*5. Desenvolva uma função para transferir elementos de uma pilha P1 para uma 
 * pilha P2 (copia), faça o retorno da P2 como passagem de parâmetro por 
 * referência na função main imprima a pilha de cópia. (Obs.: essa função pode 
 * ser implementada na biblioteca feita em sala)
 */

int menu();

int main() {
    T_pilha* pilha = (T_pilha*) malloc(sizeof (T_celula));
    T_pilha* copia = (T_pilha*) malloc(sizeof (T_celula));
    T_item* item = (T_item*) malloc(sizeof (T_item));

    int op = 1;

    inicializar(pilha);
    inicializar(copia);

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
                backup(pilha, copia);
                imprimir(copia);
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
    printf("5- Realizar copia e imprimir pilha\n");
    printf("0- SAIR\n");
    printf("Digite um opção: ");
    scanf("%d", &op);
    printf("------------------------\n");
    return op;
}