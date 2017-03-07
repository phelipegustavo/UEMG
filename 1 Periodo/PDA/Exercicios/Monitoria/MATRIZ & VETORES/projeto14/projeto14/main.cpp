#include <stdio.h>
#include <stdlib.h>

/*Faça um programa que receba:
² as notas de 15 alunos em cinco provas diferentes e armazene-as em urna matriz 15 x 5:
² os nomes dos 15 alunos e armazene-os em um vetor de 15 posições.*/

int main(){

    float nota [7][2];
    char nome [7][20];
    int i,j;

    for (i=0; i<7; i++){
        printf("Informe o nome do aluno: ");
        scanf("%s", nome[i]);
        for (j=0; j<2; j++){
            printf("Informe a nota da prova %d :",j+1);
            scanf("%f", &nota[i][j]);
        }
    }

    for (i=0; i<7; i++){
        printf ("\nNome : %s\n",nome[i]);
        for (j=0; j<2; j++){
        printf ("Nota %d: %.2f\t",j+1,nota[i][j] );
        }
    }
}
