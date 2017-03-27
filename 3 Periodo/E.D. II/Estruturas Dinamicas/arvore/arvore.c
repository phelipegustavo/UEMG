#include "arvore.h"

int menu();

int main() {
    T_apontador aux;
    T_registro reg;
    int op = 1;

    inicializa(&aux);

    while (op != 0) {
        op = menu();
        switch (op) {
            case 1:
                printf("Informe o valor a ser inserido: ");
                scanf("%d", &reg.valor);
                insere(reg, &aux);
                break;

            case 2:
                printf("Informe o valor a ser retirado: ");
                scanf("%d", &reg.valor);
                retira(reg, &aux);
                break;

            case 3:
                printf("Informe o valor a ser pesquisado: ");
                scanf("%d", &reg.valor);
                pesquisa(&reg, &aux);
                printf("Item encontrado: valor %d, endereco %p\n", reg.valor, &reg.valor);
                break;
                
            case 4:
                imprimir(&aux);
        }


    }
    return 0;
}

int menu() {
    int op;
    printf("------ARVORE BINARIA------\n"
            "1 - Inserir item\n"
            "2 - Retirar item\n"
            "3 - Pesquisar item\n"
            "4 - Imprimir arvore\n"
            "0 - SAIR\n");
    
    scanf("%d", &op);
    return op;
}
