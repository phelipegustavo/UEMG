#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <string>
/*Faça um programa que carregue uma matriz 12 x 4 com os valores das vendas de urna loja, onde cada
linha representa mm mês do ano e cada coluna representa uma semana do mês. Calcule e mostre:
² o total vendido em cada mês do ano, mostrando o nome do mês por extenso;
² o total vendido em cada semana durante todo o ano;
² o total vendido pela loja no ano.*/

int main(){
setlocale(LC_ALL, "Portuguese");

    float valores[12][4],total_mes[12]={0},total_ano=0,total_semana[48]={0};
    int i,j,c=0;
    char mes[8];

    for (i=0; i<12; i++){
        for (j=0; j<4; j++){
            printf("Informe os valores de vendas no mes %d , semana %d: ", i+1,j+1);
            scanf("%f", &valores[i][j]);
            total_semana[c]=valores[i][j];
            c++;
            total_mes[i]=valores[i][j]+total_mes[i];
        }
    total_ano=total_mes[i]+total_ano;
    printf("TOTAL MES DE ");
    switch (i+1){
        case 1: printf("JANEIRO %.2f\n", total_mes[i]);break;
        case 2: printf("FEVEREIRO %.2f\n", total_mes[i]);break;
        case 3: printf("MARÇO %.2f\n", total_mes[i]);break;
        case 4: printf("ABRIL %.2f\n", total_mes[i]);break;
        case 5: printf("MAIO %.2f\n", total_mes[i]);break;
        case 6: printf("JUNHO %.2f\n", total_mes[i]);break;
        case 7: printf("JULHO %.2f\n", total_mes[i]);break;
        case 8: printf("AGOSTO %.2f\n", total_mes[i]);break;
        case 9: printf("SETEMBRO %.2f\n", total_mes[i]);break;
        case 10: printf("OUTUBRO %.2f\n", total_mes[i]);break;

        case 11: printf("NOVEMBRO %.2f\n", total_mes[i]);break;
        case 12: printf("DEZEMBRO %.2f\n", total_mes[i]);break;
    }
    }
    printf("\nTOTAL ANO ----------------- %.2f\n", total_ano);
    for (c=0; c<48; c++){
        printf("TOTAL SEMANA %d = %.2f\n", c+1,total_semana[c]);
    }

}
