#include "listaDuplamenteEncadeada.h"

int main() {
    T_lista* lista = (T_lista*) malloc(sizeof (T_celula));
    T_item item;
    int op = 1;

    inicializar(lista);

    while (op != 0) {
        op = menu();
        switch (op) {
            case 1:
                item = lerItem();
                inserirInicio(lista, item);
                break;

            case 2:
                item = lerItem();
                inserirMeio(lista, item);
                break;

            case 3:
                item = lerItem();
                inserirFim(lista, item);
                break;

            case 4:
                item = lerItem();
                retirar(lista, item);
                break;
            case 5:
                imprimir(lista);
                break;

            case 6:
                imprimirInverso(lista);
                break;
        }
    }
    return 0;
}