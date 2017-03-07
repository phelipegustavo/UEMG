#include "listas.h"

int main() {

    int tam = 0;
    int op = 1;
    chave item;
    lista aux;

    while (op != 0) {
        printf("\nMENU");
        printf("\n1-Criar lista vazia");
        printf("\n2-Inserir item");
        printf("\n3-Verificar se a lista esta vazia");
        printf("\n4-Pesquisar item");
        printf("\n5-Retirar item");
        printf("\n6-Combinar listas");
        printf("\n7-Dividir um lista");
        printf("\n9-Copiar lista");
        printf("\n9-Ordenar lista");
        printf("\n10-Imprimir lista");
        printf("\n0-Sair\n");
        scanf("%d", &op);

        if (op == 1) {
            aux = criar_lista();

        } else if (op == 2) {
            printf("\nInforme o numero para inserir na lista: ");
            scanf("%d", &item.valor);
            aux = inserir(aux, item);

        } else if (op == 3) {
            if (verificar_lista(aux))
                printf("\nA lista esta vazia");
            else
                printf("\nA lista nao esta vazia");

        } else if (op == 4) {
            printf("\nInforme o numero para pesquisar: ");
            scanf("%d", &item.valor);
            int posicao = pesquisar_item(aux, item);
            if (posicao == -1) {
                printf("\nItem não encontrado");
            } else {
                printf("\nItem encontrado na posicao %d", posicao + 1);
            }

        }else if (op == 5) {
            printf("\nInforme o item para retirar: ");
            scanf("%d", &item.valor);
            aux=retirar(aux,item);
        
        }else if (op == 6) {
        
        }else if (op == 7) {
        
        }else if (op == 8) {
        
        }else if (op == 9) {    
            aux=ordenar_lista(aux);
        
        }else if (op == 10) {
            imprimir(aux);
        
        } else if (op == 0){
            printf("Saindo...");
        
        }else
            printf ("\nOperação invalida");
    }

    return 0;
}