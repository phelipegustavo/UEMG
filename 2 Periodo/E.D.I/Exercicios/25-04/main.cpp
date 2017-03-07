#include <stdio.h>
#include <stdlib.h>
# include "cinema.h"
int main(){
    
    lista cineritz;
    lista copia;
    cinema ingresso;
    ingresso.codigo=0;
    int op=-1;
    int aux=0;
    int cont=0;
    cineritz=criar_lista(cineritz);
    
    while (op!=0){
        printf("\nMENU");
        printf("\n1-Comprar ingresso");
        printf("\n2-Devolver ingresso");
        printf("\n3-Imprimir todos os ingressos de uma sala");
        printf("\n4-Calcular valor total de uma sala");
        printf("\n5-Calcular lugares em uma sala");
        printf("\n6-Criar backup ordenado por sala");
        printf("\n7-Calcular total de ingressos tipo meia");
        printf("\n8-Limpar vendas do dia e retornar total");
        printf("\n9-Verificar Backup");
        printf("\n0-SAIR\n");
	scanf("%d", &op);
        
        switch (op){
            case 1:
                printf ("\nInforme o nome do filme: ");
                scanf(" %[^\n]s", ingresso.filme);
                printf ("Informe o valor: ");
                scanf("%f", &ingresso.valor);
                printf ("Informe o tipo de ingresso (1-normal 2-meia): ");
                scanf ("%d", &ingresso.tipo);
                printf ("Iforme a sala: ");
                scanf("%d", &ingresso.sala);
                ingresso.codigo++;
                cineritz=comprar_ingresso(cineritz, ingresso);
                break;
            
            case 2:
                printf ("\nInforme o codigo da devolucao: ");
                scanf ("%d", &aux);
                cineritz=devolver_ingresso(cineritz,aux);
                break;
            
            case 3:
                printf ("\nInforme a sala: ");
                scanf("%d", &aux);
                imprimir(cineritz,aux);
                break;
            
            case 4:
                printf ("\nInforme a sala: ");
                scanf("%d", &aux);
                printf ("\nValor Total da sala %d: R$%.2f",aux,total(cineritz,aux));
                break;
                
            case 5:
                printf ("\nInforme a sala: ");
                scanf("%d", &aux);
                printf ("\nLugares Ocupados na sala %d: %d",aux,lugares_sala(cineritz,aux));
                break;
                
            case 6:
                copia=backup(cineritz);
                printf("\nBackup realizado com sucesso!");
                break;
            
            case 7:
                printf("\nTotal de ingressos do tipo meia: %d", total_meia(cineritz));
                break;
                
            case 8:cineritz=fechamento(cineritz);break;
            
            case 9:
                printf ("\nInforme a sala: ");
                scanf("%d", &aux);
                imprimir(copia,aux);
                break;
            
            case 0: printf("\nSaindo...");break;
            default: printf("\nOperação invalida!");
            
        }   
    
    }   
    return 0;
}