#include <stdlib.h>
#define MAX 5

typedef struct {
    int valor;
}tchave;

typedef struct{
    int inicio;
    int fim;
    tchave fila[MAX]; 
}tfila;

tfila inicializar (tfila aux){
    aux.inicio=1;
    aux.fim=1;
    return aux;
}

bool fila_vazia (tfila aux){
    if (aux.inicio==aux.fim){
        return true;
    }else
        return false;
}

tfila enfileirar (tfila aux, tchave item){
    if ( aux.fim % MAX +1 == aux.inicio){
        printf("\nFila Cheia!");
    }else{
        aux.fila[aux.fim-1]= item;
        aux.fim = aux.fim % MAX+1;
    }
    return aux;
}

tfila retirar (tfila aux){
    if(fila_vazia(aux)){
        printf("\nA fila ja esta vazia!");
    }else{
        aux.inicio = aux.inicio % MAX+1;
    }return aux;
}
void imprimir (tfila aux){
    while (aux.fim!=aux.inicio){
        printf("\n%d",aux.fila[aux.inicio-1].valor);
        aux=retirar(aux);
    }
    printf("\n---------------");
}
