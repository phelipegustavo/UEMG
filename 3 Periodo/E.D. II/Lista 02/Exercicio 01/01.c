#include "pilhadinamica.h"

//Questão 01

/*Na biblioteca desenvolvida em sala, para pilhas dinâmicas numéricas, 
 * escreva uma função para retornar qual “posição” de um determinado número 
 * a ser pesquisado, exemplo: Pilha: 1  5  6  7  9, o número pesquisado 6 
 * está na 3ª posição. Escreva dentro no menu elaborado em sala, mais uma 
 * opção para ler um valor a ser pesquisado e retornar seu posicionamento 
 * na pilha, se o número não existir na mesma imprima essa informação.
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
                ler_item(item);
                if (posicao(pilha, item) == 0) {
                    printf("Item nao encontrado\n");
                } else {
                    printf("O item esta na %dª posição\n", posicao(pilha, item));
                }
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
    printf("5- Retornar posição do item na pilha\n");
    printf("0- SAIR\n");
    printf("Digite um opção: ");
    scanf("%d", &op);
    printf("------------------------\n");
    return op;
}
