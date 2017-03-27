#include "06dinamico.h"

int main() {
    T_lista* lista = (T_lista*) malloc(sizeof (T_apontador));
    T_item item;
    clock_t inicio, fim;
    int mtd = 1, qtd = 50;
    int passos = 0;


    srand(time(NULL));

    while (mtd != 0) {
        printf("Informe o método de ordenação: \n"
                "1 - Troca <BubbleSort> \n"
                "2 - Seleção <SelectionSort> \n"
                "3 - Insercão <InsertionSort> \n"
                "0 - SAIR\n");
        scanf("%d", &mtd);

        inicializar(lista);

        switch (mtd) {
            case 1:
                for (int i = 0; i < qtd; i++) {
                    item.valor = rand() % 100;
                    inserir(lista, item);
                }
                printf("Lista:");
                imprimir(lista);
                inicio = clock();
                troca(lista, &passos);
                fim = clock();
                printf("Ordenada:");
                imprimir(lista);
                break;

            case 2:
                for (int i = 0; i < qtd; i++) {
                    item.valor = rand() % 100;
                    inserir(lista, item);
                }
                printf("Lista:");
                imprimir(lista);
                inicio = clock();
                selecao(lista, &passos);
                fim = clock();
                printf("Ordenada:");
                imprimir(lista);
                break;

            case 3:
                for (int i = 0; i < qtd; i++) {
                    item.valor = rand() % 100;
                    inserir(lista, item);
                }
                printf("Lista:");
                imprimir(lista);
                inicio = clock();
                insercao(lista, &passos);
                fim = clock();
                printf("Ordenada:");
                imprimir(lista);
                break;

            case 0:
                printf("Saindo...\n");
                break;

            default:
                printf("Opção inválida!");
        }
        printf("Passos: %5d\n", passos);
        double tempo = (fim - inicio)*1000.0 / CLOCKS_PER_SEC;
        printf("Tempo gasto: %5g ms.", tempo);
        passos = 0;
        printf("\n---------------------------------------------------\n");
    }
}
