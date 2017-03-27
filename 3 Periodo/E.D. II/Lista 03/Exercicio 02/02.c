#include "filadinamica.h"

//Questão 02

/* Ainda na mesma biblioteca desenvolva uma função “Fura Fila”, utilizando 
 * a função do exercício anterior descubra onde é o meio da fila e insira um 
 * item (TIpoItem) nesta “posição”, lembre-se de atualizar todos os ponteiros 
 * para não perder a referência do resto da Fila.*/

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
                printf("Informe o valor : ");
                scanf("%d", &item.valor);
                fura_fila(fila, item);
                break;
        }
    }
    return 0;
}

