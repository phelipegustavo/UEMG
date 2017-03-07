#include <stdio.h>
#include "sistemas.h"

int main() {
    int tam = 0;
    int op = 1; 
    tipo_chave item;
    tipo_lista aux;

    while (op != 0) {
        printf("\nMENU");
        printf("\n1-Criar lista vazia");
        printf("\n2-Verificar se a lista esta vazia");
        printf("\n3-Inserir item");
        printf("\n4-Retirar item");
        printf("\n5-Combinar listas");
        printf("\n6-Dividir um lista");
        printf("\n7-Copiar lista");
        printf("\n8-Ordenar lista");
        printf("\n9-Pesquisar item\n");
        scanf("%d", &op);

        if (op == 1) {
            printf("\nInforme o Tamanho da Lista: ");
            scanf("%d", &tam);
            aux = limpar(tam);
        
        } else if (op == 2) {
            if (listavazia(aux) == -1) {
                printf("\nA lista esta vazia");
            } else {
                printf("\nA lista não esta vazia");
            }

        } else if (op == 3) {
            printf("\nInforme um numero para inserir: ");
            scanf("%d", &item.valor);
            inserir(aux, item);
        
        }else if (op==4){
            printf("\nInforme um numero para retirar: ");
            scanf("%d", &item.valor);
            retirar (aux,item);
        
        }else if (op==5){
            
        }else if (op==6){
            
        }else if (op==7){
            
        }else if (op==8){
            
        }else if (op==9){
            
        }else
            printf ("\nOperação invalida");
        
        
    }
    return 0;
}
