#include <stdio.h>
#include <stdlib.h>
#include "cinema.h"

int main(){
    cinema cineritz;
    cinema copia;
    ingresso entrada;
    entrada.codigo=0;
    
    int op=1;
    int aux;
    
    cineritz=limpar(cineritz);
    while (op!=0){
        printf("\n----------MENU----------");
        printf("\n1-Comprar Ingresso");
        printf("\n2-Devolver Ingresso");
        printf("\n3-Ver ingressos vendidos de uma sala");
        printf("\n4-Calcular valor total de uma sala");
        printf("\n5-Calcular total de lugares vendidos de uma sala");
        printf("\n6-Criar Backup ordenado por sala");
        printf("\n7-Fechamento do dia");
        printf("\n8-Verificar Backup");
        printf("\n0-SAIR\n");
        scanf("%d", &op);
        printf("\n------------------------");
        
        switch (op){
            case 1:
                printf ("\nNome do filme: ");
                scanf(" %[^\n]s", entrada.filme);
                printf ("Valor: R$ ");
                scanf("%f", &entrada.valor);
                printf ("Tipo de ingresso (1-normal 2-meia): ");
                scanf ("%d", &entrada.tipo);
                printf ("Sala: ");
                scanf("%d", &entrada.sala);
                entrada.codigo++;
                cineritz=comprar_ingresso(cineritz,entrada);
            break;
                
            case 2:
                printf ("\nInforme o codigo da devolucao: ");
                scanf ("%d", &aux);
                cineritz=devolver_ingresso(cineritz,aux);
            break;
                
            case 3:
                printf ("\nInforme a sala: ");
                scanf ("%d", &aux);
                imprimir(cineritz,aux);
            break;
                
            case 4:
                printf ("\nInforme a sala: ");
                scanf ("%d", &aux);
                printf("Total sala %d: R$%.2f",aux, valor_sala(cineritz,aux));
            break;
                
            case 5:
                printf ("\nInforme a sala: ");
                scanf ("%d", &aux);
                printf("Lugares Vendidos sala %d: %d",aux, lugares_sala(cineritz,aux));
            break;
                
            case 6:copia=backup(cineritz,copia);break;
            
            case 7:cineritz=fechamento(cineritz);break;
            
            case 8:
                printf("\n1-Imprimir todos ingressos ");
                printf("\n2-Imprimir ingressos de uma sala\n");
                scanf("%d", &aux);
                if(aux==1){
                    for (int i=1; i<=5; i++){
                        imprimir(copia,i);
                    }
                } else if(aux==2) {
                    printf ("\nInforme a sala: ");
                    scanf ("%d", &aux);
                    imprimir(copia,aux);
                }
            break;
            case 0: printf("\nSaindo...");break;
            default: printf("\nOperação Invalida!");
            
        }
    }
    
    return 0;
}