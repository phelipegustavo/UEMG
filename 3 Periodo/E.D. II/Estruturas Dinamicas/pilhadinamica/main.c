#include "pilhadinamica.h"

int main() {
    T_pilha aux;
    T_item item;
    int op = 1;

    while (op != 0) {
        printf("1-Inicializar\n");
        printf("2-Empilhar\n");
        printf("3-Desempilhar\n");
        printf("4-Tamanho da pilha\n");
        printf("5-Imprimir\n");
        printf("0-SAIR\n");
        scanf("%d", &op);

        switch (op) {
            case 1:inicializar(&aux);
                break;
            case 2:
                printf("Informe o valor: ");
                scanf("%d", &item.valor);
                empilha(&aux, &item);
                break;
            case 3:
                desempilha(&aux, &item);
                printf("O item %d, foi removido\n", item.valor);
                break;
            case 4:
                printf("TAMANHO: %d\n", aux.tamanho);
                break;
            case 5:
                imprimir(&aux);
            case 6:
                item.valor = 1;
                pesquisar(&aux,&item);break;
        }
        printf("-----------------------\n");
    }
    return 0;
}