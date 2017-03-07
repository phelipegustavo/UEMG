#include <stdio.h>
#include <stdlib.h>
#include "fila.h"
int main() {
    
tchave item;
tfila aux;
int op=-1;

    while (op!=0){
        printf("\n1-Criar fila");
        printf("\n2-Inserir item");
        printf("\n3-Remover item");
        printf("\n4-Imprimir");
        printf("\n0-SAIR\n");
        scanf("%d", &op);
        printf("---------------");
        switch (op){
            case 1: aux=inicializar(aux);break;
            
            case 2:
                printf("\nInforme o item a inserir: ");
                scanf("%d", &item.valor);
                aux=enfileirar(aux,item);
                break;

            case 3:
                printf("\nPrimeiro item da fila removido!\n");
                aux=retirar(aux);
                break;
            
            case 4:imprimir(aux);break;
            
            default:printf("\nOperação Invalida!");
    
        }
    }
    return 0;
}

