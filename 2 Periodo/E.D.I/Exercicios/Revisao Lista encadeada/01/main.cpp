#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Biblioteca.h"

int main(){
    T_celula *item=(T_celula*)malloc(sizeof(T_celula));
    T_fila *aux=(T_fila*)malloc(sizeof(T_celula));
    int op=1;
    
    inicializar(aux);
    
    while (op!=0){
        printf("------------------------\n");
        printf("1-Enfileirar\n");
        printf("2-Atender Processo\n");
        printf("3-Imprimir\n");
        printf("0-SAIR\n");
        scanf("%d", &op);
        
        switch (op){
            
            case 1: 
                printf("Tipo do Processamento ( Leitura ou Escrita ): ");
                scanf("%s", item->processamento);
                printf("Hora do Processamento (int): ");
                scanf("%d", &item->hora);
                printf("Tipo do Recurso (Banco_de_Dados, Impressora ou HD): ");
                scanf("%s",item->recurso);
                enfileirar(aux,item);
                break;
                
            case 2:
                desenfileirar(aux);
                printf("Processo Realizado\n");
                break;
                
            case 3:
                imprimir(aux);
                break;
                
        }
    
    }
    
    return 0;
}