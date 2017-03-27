#include "fila_dinamica.h"

int main() {
    T_fila fila; //= (T_fila)malloc(sizeof(T_celula));
    T_item item; //= (T_apontador)malloc(sizeof(T_celula));
    int op = 1;
    inicializar(&fila);

    while (op != 0) {
        op = menu();
        switch (op) {
            
            case 1:
                printf("Informe um valor: ");
                scanf("%d", &item.valor);
                enfileirar(&fila, item);
                break;

            case 2:desenfileirar(&fila);
                break;

            case 3:
                imprimir(&fila);
                break;



        }
    }



    return 0;
}
