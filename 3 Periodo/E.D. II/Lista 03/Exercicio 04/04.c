#include "filadinamica.h"

//Questao 04

/* Na biblioteca feita em sala, acrescente a função reiniciar toda a fila, 
 * lembrando de liberar cada espaço na memória de cada item na fila e 
 * inicializar novamente as variáveis de controle. No main, acrescente uma 
 * opção para chamar essa função e imprimir a Fila, ao fazer isso deve-se 
 * informar que a Fila está vazia.*/

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
                reiniciar(fila);
                printf("A fila agora esta vazia");
                break;
        }
    }
    return 0;
}