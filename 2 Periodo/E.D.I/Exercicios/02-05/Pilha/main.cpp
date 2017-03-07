#include <stdio.h>
#include "pilha.h"

int main(){
    chave item;
    pilha aux;
    int op=-1;
    
    while (op!=0){
        printf("\n-------------------");
        printf("\n1-Criar pilha");
        printf("\n2-Adcionar item");
        printf("\n3-Retirar item");
        printf("\n4-Imprimir pilha");
        printf("\n0-Sair\n");
        scanf("%d", &op);
        printf("-------------------");
        switch (op){
            case 1: aux=criarpilha(aux);printf("\nPilha criada!");break;
            
            case 2: 
                printf("\nInforme o item: ");
                scanf("%d", &item.valor);
                aux=empilhar(aux, item);
                printf("\nItem adcionado!");
                break;
            
            case 3: 
                printf("\nInforme o item: ");
                scanf("%d", &item.valor);
                aux=retirar_item(aux, item);
                printf("\nItem removido");
                break;
                
            case 4:imprimir (aux);break;
            
            case 0:printf("\nSaindo...");break;
            
            default:printf("\nOpção Invalida!");
                
        }
    }

    return 0;
}