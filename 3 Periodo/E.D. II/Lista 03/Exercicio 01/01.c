#include "filadinamica.h"

//Questão 01

/* Na biblioteca feita em sala de aula, sobre Filas Dinâmicas, crie uma função 
 * que retorne (int) o tamanho total da fila.  No main adicione uma opção no 
 * menu para chamar essa função.*/

int main() {
    T_fila* fila = (T_fila*) malloc(sizeof (T_celula));
    T_item item;
    int op = 1;

    inicializar(fila);

    while (op != 0) {
        op = menu();

        switch (op) {
            case 1:
                printf("Informe o valor : ");
                scanf("%d", &item.valor);
                enfileirar(fila, item);
                break;
            case 2:
                desenfileirar(fila);
                break;
            case 3:
                imprimir(fila);
                break;
            case 4:
                printf("Total de itens: %d\n", Total_itens(fila));
                break;
        }
    }
    return 0;
}

