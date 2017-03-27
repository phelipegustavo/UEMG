#include "01.h"

int menu();

int main() {
    T_apontador raiz, aux;
    T_registro reg;
    int op = 1;
    int total = 0;
    float soma = 0;
    inicializa(&raiz);
    inicializa(&aux);

    while (op != 0) {
        op = menu();
        switch (op) {
            case 1:
                printf("Informe o valor a ser inserido: ");
                scanf("%d", &reg.valor);
                insere(&raiz, reg);
                insere(&aux, reg);
                break;

            case 2:
                printf("Informe o valor a ser retirado: ");
                scanf("%d", &reg.valor);
                retira(&raiz, reg);
                break;

            case 3:
                printf("Informe o valor : ");
                scanf("%d", &reg.valor);
                buscar(&raiz, reg);
                break;

            case 4:
                folhas(&raiz, &total);
                printf("Total de folhas: %d\n", total);
                break;

            case 5:
                nos(&raiz, &total);
                printf("Total de nos: %d\n", total);
                break;

            case 6:
                reg.valor = 1000000;
                //insere(&aux, reg);
                imprimir(&aux);
                compara(&raiz, &aux, &total);
                if (total == 1)
                    printf("As árvores são iguais\n");
                else
                    printf("As árvores são diferentes\n");
                break;

            case 7:
                soma_nos(&raiz, &soma);
                printf("Soma: %.2f\n", soma);
                break;

            case 8:
                crescente(&raiz);
                break;

            case 9:
                total = altura(&raiz);
                printf("Altura: %d\n", total);
                break;
            case 10:
                imprimir(&raiz);
                break;

        }
        total = 0;
        soma = 0;
    }
    return 0;
}

int menu() {
    int op;
    printf("------ARVORE BINARIA------\n"
            "1  - Inserir item\n"
            "2  - Retirar item\n"
            "3  - Busca item <Pai, Avo, Irmão>\n"
            "4  - Quantidade de folhas\n"
            "5  - Quantidade de nos\n"
            "6  - Comparar Árvores\n"
            "7  - Soma de nos\n"
            "8  - Imprimir arvore crescente\n"
            "9  - Altura da arvore\n"
            "10 - Imprimir arvore\n"
            "0  - SAIR\n");

    scanf("%d", &op);
    return op;
}
