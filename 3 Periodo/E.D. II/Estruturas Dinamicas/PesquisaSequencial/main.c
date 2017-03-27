#include "PesquisaSequencial.h"

int menu();

int main() {
    int op = 1;
    T_registro item;
    T_tabela aux;
    inicializar(&aux);

    while (op != 0) {
        op = menu();
        switch (op) {
            case 1:
                inicializar(&aux);
                break;
            case 2:
                printf("Informe o valor a inserir: ");
                scanf("%ld", &item.chave);
                Insere(item, &aux);
                break;
            case 3:
                imprimir(&aux);
                break;

            case 4:
                printf("Informe o item a pesquisar: ");
                scanf("%ld", &item.chave);
                printf("O item %ld esta na posicao %d", item.chave, Binaria(item.chave, &aux));
        }
    }
    return 0;
}

int menu() {
    int op;
    printf("\nPesquisa Sequencial\n");
    printf("1 - Inicializar\n");
    printf("2 - Inserir\n");
    printf("3 - Imprimir\n");
    printf("4 - Realizar Pesquisa Binaria\n");

    scanf("%d", &op);
    return op;
}