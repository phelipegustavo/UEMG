#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "notas.h"
#define QTD 40

int main() {

    int op = 1, i, j=0, imp = 1;
    aluno cadastro[QTD];
    char nome[20];

    while (op != 0) {
        printf("\n------------------MENU------------------");
        printf("\n1-CADASTRO\n2-IMPRIMIR\n3-MEDIA\n0-CANCELAR\n");
        scanf("%d", &op);
        printf("-----------------------------------------\n");

        if (op == 1) {
            cadastro[j] = ler();
            cadastro[j] = media();
            j++;
        } else if (op == 2) {
            printf("1-Imprimir todos os alunos\n2-Imprimir um aluno\n");
            scanf("%d", &imp);
            printf("-----------------------------------------\n");
            if (imp == 1) {
                for (i = 0; i < j; i++) {
                    imprimir(cadastro[i]);
                }
            } else if (imp == 2) {
                printf("Informe o nome do aluno: ");
                scanf("%s", nome);
                for (i = 0; i < j; i++) {
                    if (strcmp(cadastro[i].nome, nome) == 0) {
                        imprimir(cadastro[i]);
                    }
                }
            }
        }
        else if (op==3){
            for (i = 0; i < j; i++) {
                imprimir(cadastro[i]);
            }
        }
    }

    return 0;
}