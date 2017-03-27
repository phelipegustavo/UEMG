#include "07estatico.h"

int main() {

    T_lista aux;
    T_item item;
    clock_t inicio, fim;
    int qtd = 0, mtd = 1;
    int passos = 0, i;

    srand(time(NULL));

    while (mtd != 0) {
        printf("Informe o método de ordenação: \n"
                "1 - ShellSort \n"
                "2 - QuickSort \n"
                "0 - SAIR\n");
        scanf("%d", &mtd);
        aux = inicializar(aux);

        if (mtd != 0) {
            printf("Informe a quantidade de numeros <500> <2000>:");
            scanf("%d", &qtd);
        }
        switch (mtd) {
            case 1:
                for (i = 0; i < qtd; i++) {
                    item.valor = rand() % 100;
                    aux = inserir(aux, item);
                }
                printf("Lista:");
                imprimir(&aux);
                inicio = clock();
                ShellSort(&aux, qtd, &passos);
                fim = clock();
                printf("Ordenada:");
                imprimir(&aux);
                break;

            case 2:
                for (i = 0; i < qtd; i++) {
                    item.valor = rand() % 100;
                    aux = inserir(aux, item);
                }
                printf("Lista:");
                imprimir(&aux);
                inicio = clock();
                QuickSort(&aux, qtd, &passos);
                fim = clock();
                printf("Ordenada:");
                imprimir(&aux);
                break;

            case 0:
                printf("Saindo...\n");
                break;

            default:
                printf("Opção inválida!");
        }
        printf("Passos: %5d\n", passos);
        double tempo = (fim - inicio)*1000.0 / CLOCKS_PER_SEC;
        printf("Tempo: %5g ms.", tempo);
        printf("\n---------------------------------------------------\n");
        passos = 0;
    }
    return 0;
}