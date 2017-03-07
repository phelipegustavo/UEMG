#include <stdio.h>
#define MAX 11
typedef struct{
    int valor;
}Chave;

typedef struct{
    int inicio;
    int fim;
    Chave fila[MAX];
}Fila;

Fila inicializar (Fila aux){
    aux.inicio=1;
    aux.fim=1;
    return aux;
}

bool vazia (Fila aux){
    if (aux.inicio==aux.fim)
        return true;
    else
        return false;
}

Fila inserir (Fila aux, Chave item){
    if (aux.fim % MAX+1==aux.inicio){
        printf("\nFila Cheia!");
    }else{
        aux.fila[aux.fim-1]=item;  
        aux.fim=aux.fim % MAX +1;
        
    }
    return aux;
}

Fila remover (Fila aux){
    if (vazia (aux)){
        printf ("\nA Fila ja esta vazia!");
    }else{
        aux.inicio=aux.inicio % MAX +1;
    }
    return aux;
}

void imprimir (Fila aux){
    while (aux.inicio!=aux.fim){
        printf("\n%5d", aux.fila[aux.inicio-1].valor);
        aux=remover(aux);
    }
}

int pesquisar (Fila aux,Chave item){
    while (aux.inicio!=aux.fim){
        if (aux.fila[aux.inicio-1].valor==item.valor){
            return aux.inicio-1;
        }else if (aux.inicio==0){
            return -1;
        }else
            aux=remover(aux);
    }       
}