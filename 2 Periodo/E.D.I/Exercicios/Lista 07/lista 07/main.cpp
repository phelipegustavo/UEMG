#include "lista.h"

int main() {

    T_lista *aux = (T_lista*) malloc(sizeof (T_celula)); //Aloca memoria para a lista "aux"
    T_lista *aux2 = (T_lista*) malloc(sizeof (T_celula)); //Aloca memoria para a lista "aux2" 
    T_celula *item = (T_celula*) malloc(sizeof (T_celula)); //Aloca memoria para a celula "item"
    T_lista *copia = (T_lista*) malloc(sizeof (T_celula)); //Aloca memoria para a lista "copia"

    int op = -1;

    while (op != 0) {
        printf("------------------------------------------");
        printf("\n1- Criar lista");
        printf("\n2- Inserir item");
        printf("\n3- Retirar item");
        printf("\n4- Inverter lista");
        printf("\n5- Verificar se a lista esta vazia");
        printf("\n6- Verificar se a lista esta crescente");
        printf("\n7- Retornar total de itens na lista");
        printf("\n8- Retornar endereço do item do meio da lista");
        printf("\n9- Realizar copia");
        printf("\n10- Comparar duas listas");
        printf("\n11- Imprimir");
        printf("\n0- SAIR ");
        printf("\nEscolha uma opção: ");
        scanf("%d", &op);
        printf("------------------------------------------\n");

        switch (op) {
            case 1:
                inicializar(aux);
                printf("Lista Criada! \n");
                break;

            case 2:
                printf("Informe um valor para inserir: ");
                scanf("%d", &item->valor);
                inserir(aux, item);
                break;

            case 3:
                printf("Informe um valor para retirar: ");
                scanf("%d", &item->valor);
                retirar(aux, item);
                break;

            case 4:
                inverter(aux);
                printf("Lista Invertida!\n");
                imprimir(aux);
                break;

            case 5:
                if (vazia(aux)) {
                    printf("A lista esta Vazia!\n");
                } else {
                    printf("A lista não esta vazia!\n");
                }
                break;

            case 6:
                if (crescente(aux)) {
                    printf("A lista esta crescente!\n");
                } else {
                    printf("A lista não esta crescente!\n");
                }
                break;

            case 7:
                printf("Total de intens: %d\n", total_celulas(aux));
                break;

            case 8:
                item = meio(aux);
                printf("Valor do item do meio: %d \n", item->valor);
                printf("Endereço do item do meio: %p \n", &item->valor);
                break;

            case 9:
                copiar(aux, copia);
                printf("Copia Realizada!\n");
                imprimir(copia);
                break;

            case 10:
                if (comparar(aux, aux2)) {
                    printf("As listas são iguais\n");
                } else {
                    printf("As listas são diferentes\n");
                }
                break;

            case 11:
                printf("Lista: \n");
                imprimir(aux);
                break;
        }
    }

    return 0;
}