#include "arvore.h"

int menu();

int main() {

    T_apontador raiz;
    T_registro x;
    int op = 1;

    inicializa(&raiz);

    while (op != 0) {
        op = menu();
        switch (op) {
            case 1: inicializa(&raiz);
                break;
            case 2:
                printf("Informe o valor a ser inserido: ");
                scanf("%d", &x.valor);
                insereBalanceado(&raiz, x);
                break;
            case 3:
                printf("Informe o valor a ser retirado: ");
                scanf("%d", &x.valor);
                retira(&raiz, x);
                break;
            case 4:imprimirERD(&raiz);break;
            case 5:imprimirRED(&raiz);break;
            case 6:imprimirEDR(&raiz);break;
        }
    }

    return 0;
}

int menu() {
    int op;
    printf("---------ÁRVORE BINÁRIA---------\n"
            "1 - Criar Ávore\n"
            "2 - Inserir Registro\n"
            "3 - Retirar Registro\n"
            "4 - Imprimir <Caminhamento Central>\n"
            "5 - Imprimir <Caminhamento Pre-Ordem>\n"
            "6 - Imprimir <Caminhamento Pos-Ordem>\n"
            "0 - SAIR\n");
    scanf("%d", &op);
    return op;
}