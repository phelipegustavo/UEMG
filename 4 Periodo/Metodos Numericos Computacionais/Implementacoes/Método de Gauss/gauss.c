/*
 * File:   gauss.c
 * Author: phelipe
 *
 * Created on 18 de Março de 2017
 */

#include <stdio.h>
#include <stdlib.h>

/*
 * 
 */

#define N 3 //Numero de incognitas
#define LINHAS 3 //Numero de linhas
#define COLUNAS 4 //Numero de colunas

void imprimirMatriz(double AB[LINHAS][COLUNAS]);

void imprimirResultado(double AB[LINHAS][COLUNAS]);

int main() {

    double AB[LINHAS][COLUNAS];
    double m;

    /*Receber Valores*/
    for (int i = 0; i < LINHAS; i++) {
        for (int j = 0; j < COLUNAS; j++) {
            printf("Informe o valor do elemento A[%d][%d]: ", i + 1, j + 1);
            scanf("%lf", &AB[i][j]);
        }
    }

    /*Verifica se primeiro elemento é nulo*/
    if (AB[0][0] == 0) {
        for (int i = 0; i < COLUNAS; i++) {
            double aux = AB[0][i];
            AB[0][i] = AB[1][i];
            AB[1][i] = aux;
        }
    }
    
    /*Gauss*/
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            if (j > i) {
                m = AB[j][i] / AB[i][i];
                for (int k = i; k <= COLUNAS; k++) {
                    AB[j][k] = AB[j][k] - m * AB[i][k];
                }
            }
        }
    }

    imprimirResultado(AB);

    return 0;
}

void imprimirMatriz(double AB[LINHAS][COLUNAS]) {
    for (int i = 0; i < LINHAS; i++) {
        printf("|      ");
        for (int j = 0; j < COLUNAS; j++) {
            printf("%2lf \t", AB[i][j]);
        }
        printf("|\n");
    }
    printf("----------------------------------------\n");
}

void imprimirResultado(double AB[LINHAS][COLUNAS]) {
    /*Substituição Retroativa*/
    double x[N];
    x[N - 1] = AB[N - 1][N] / AB[N - 1][N - 1];

    for (int i = N - 2; i >= 0; i--) {
        double soma = 0;
        for (int j = i; j < N; j++) {
            soma += AB[i][j] * x[j];
        }
        x[i] = (AB[i][N] - soma) / AB[i][i];
    }

    printf("Solução: \n");
    for (int i = 0; i < N; i++) {
        printf("x%d: %f \n", i + 1, x[i]);
    }
}