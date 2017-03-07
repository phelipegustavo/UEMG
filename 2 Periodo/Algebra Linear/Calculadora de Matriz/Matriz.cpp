#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

int main() {
    setlocale(LC_ALL, "Portuguese");

    int linhaA = 0, colunaA = 0, linhaB = 0, colunaB = 0, i, j, aux = 0, c, m, op = 1;

    printf("MULTIPLICAÇÃO DE MATRIZES:\n");

    do {
        //VALORES MATRIZ A
        printf("\nInforme a quantidade de linhas da matriz A: ");
        scanf("%d", &linhaA);
        printf("Informe a quantidade de colunas da matriz A: ");
        scanf("%d", &colunaA);

        int matrizA[linhaA][colunaA];

        //VALORES DA MATRIZ B
        printf("Informe a quantidade de linhas da matriz B: ");
        scanf("%d", &linhaB);
        printf("Informe a quantidade de colunas da matriz B: ");
        scanf("%d", &colunaB);

        int matrizB[linhaB][colunaB];

        //VERIFICANDO SE É POSSIVEL CALCULAR
        if (colunaA == linhaB) {
            printf("\n");
            
            //RECEBENDO VALORES
            for (i = 0; i < linhaA; i++) {
                for (j = 0; j < colunaA; j++) {
                    printf("Informe o valor da matriz A em %d,%d: ", i + 1, j + 1);
                    scanf("%d", &matrizA[i][j]);
                }
            }
            printf("\n");
            for (i = 0; i < linhaB; i++) {
                for (j = 0; j < colunaB; j++) {
                    printf("Informe o valor da matriz B em %d,%d: ", i + 1, j + 1);
                    scanf("%d", &matrizB[i][j]);
                }
            }
            
            //CALCULANDO... 
            
            int matrizR[linhaA][colunaB];
            for (i = 0; i < linhaA; i++) {
                for (j = 0; j < colunaB; j++) {
                    aux = 0;
                    for (c = 0; c < colunaA; c++) {
                        aux += matrizA[i][c] * matrizB[c][j];
                    }
                    matrizR[i][j] = aux;
                }
            }

            printf("---------------------------------------------------------");
            printf("\nRESULTADO A*B: \n\n");
            for (i = 0; i < linhaA; i++) {
                printf("|      ");
                for (j = 0; j < colunaB; j++) {
                    printf("%2d \t", matrizR[i][j]);
                }
                printf("|\n");
            }
            printf("---------------------------------------------------------");
            printf("\nDeseja realizar outra operação\n1-sim \t2-Não : ");
            scanf("%d", &op);

        } else {
            printf("\nImpossivel calcular: \nA matrizA deve ter a quantidade de "
                    "colunas igual as linhas da matrizB!\n");
            printf("\nDeseja realizar outra operação\n1-sim \t2-Não : ");
            scanf("%d", &op);
        }

    } while (op == 1);
    
    return 0;
}
