#include <stdio.h>
#include <stdlib.h>

#include "filadinamica.h"

int main(){
    
    Chave item;
    Fila aux;
    int op=-1;
    
    while(op!=0){
        printf("\n1-Criar fila");
        printf("\n2-Inserir item");
        printf("\n3-Remover item");
        printf("\n4-Imprimir");
        printf("\n0-SAIR\n");
        scanf("%d", &op);
        printf("---------------");
        
        switch (op){
            case 1:aux=inicializar(aux);break;
            
            case 2:
                printf("\nInforme o item: ");
                scanf("%d", &item.valor);
                aux=inserir(aux,item);
                break;
                
            case 3:aux=remover(aux);printf("\nPrimeiro item removido!\n");break;
            
            case 4:imprimir(aux);break;
            
            case 5:printf("posicao %d", pesquisar(aux,item));break;
                
                
            
        }
    }
    
    
    return 0;
}