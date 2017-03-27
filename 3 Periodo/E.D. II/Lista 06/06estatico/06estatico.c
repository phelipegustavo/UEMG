#include "06estatico.h"

int main() {

    T_lista aux;
    T_item item;
    clock_t inicio, fim;
    int qtd = 0, mtd = 1;
    int passos = 0;

    srand(time(NULL));

    while (mtd != 0) {
        printf("Informe o método de ordenação: \n"
                "1 - Troca <BubbleSort> \n"
                "2 - Seleção <SelectionSort> \n"
                "3 - Insercão <InsertionSort> \n"
                "0 - SAIR\n");
        scanf("%d", &mtd);
        aux = inicializar(aux);

        if (mtd != 0) {
            printf("Informe a quantidade de numeros <50> <100> <500> :");
            scanf("%d", &qtd);
        }
        switch (mtd) {
            case 1:
                for (int i = 0; i < qtd; i++) {
                    item.valor = rand() % 100;
                    aux = inserir(aux, item);
                }
                printf("Lista:");
                imprimir(aux);
                inicio = clock();
                aux = troca(aux,&passos);
                fim = clock();
                printf("Ordenada:");
                imprimir(aux);
                break;

            case 2:
                for (int i = 0; i < qtd; i++) {
                    item.valor = rand() % 100;
                    aux = inserir(aux, item);
                }
                printf("Lista:");
                imprimir(aux);
                inicio = clock();
                aux = selecao(aux, &passos);
                fim = clock();
                printf("Ordenada:");
                imprimir(aux);
                break;

            case 3:
                for (int i = 0; i < qtd; i++) {
                    item.valor = rand() % 100;
                    aux = inserir(aux, item);
                }
                printf("Lista:");
                imprimir(aux);
                inicio = clock();
                aux = insercao(aux, &passos);
                fim = clock();
                printf("Ordenada:");
                imprimir(aux);
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