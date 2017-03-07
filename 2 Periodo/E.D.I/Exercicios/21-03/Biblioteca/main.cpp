#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "biblioteca.h"
#define QTD 50

int main(){
    livro livros[QTD];
    int op=1,i,j=0;
    char titulo[20];
    
    while (op!=0){
        printf("\n-----------------MENU-----------------");
        printf("\n1-CADASTRO\n2-IMPRIMIR\n0-CANCELAR\n");
        scanf ("%d", &op);
        printf("--------------------------------------\n");
        if (op==1){
                livros[j]=lerlivro();
                printf("\n");
                j++;
        }
        else if (op==2){
            printf("Informe o nome do livro: ");
            scanf ("%s", titulo);
            
            for (i=0; i<j; i++){
                if (strcmp (livros[i].nome,titulo)==0)
                    imprimirlivro(livros[i]);
            }
        }
    }
}