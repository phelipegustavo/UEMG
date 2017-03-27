#include "02.h"

int main() {

    T_apontador raiz;
    T_registro x;

    inicializa(&raiz);

    x.valor = '3';

    insereBalanceado(&raiz, x);


    x.valor = '5';

    insereBalanceado(&raiz, x);

    x.valor = '+';

    insereBalanceado(&raiz, x);

    x.valor = '*';

    insereBalanceado(&raiz, x);

    x.valor = '8';

    insereBalanceado(&raiz, x);

    imprimirRED(&raiz);
    printf("\n");
    imprimirERD(&raiz);
    printf("\n");
    imprimirEDR(&raiz);
    printf("\n");
    return 0;
}

