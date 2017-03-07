#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
/*Faça um programa que pergunte ao usuário o número de alunos a ser lido. O tamanho dos vetores será o número informado pelo usuário.
Armazene num vetor as notas G1 destes alunos; num outro vetor, armazene as notas G2 destes alunos.
Ambas notas, G1 e G2, são informadas pelo usuário. Calcule a média aritmética destes alunos e armazene num terceiro vetor.
Ao final, mostre as 3 notas dos alunos.*/
int main(){
setlocale(LC_ALL, "Portuguese");

    int alunos=0,i;

    printf ("Informe a quantidade de alunos: ");
    scanf ("%d", &alunos);

    float g1[alunos], g2[alunos],media[alunos];

    for (i=0; i<alunos; i++){
        printf ("Informe a nota do aluno %d no G1: ", i+1);
        scanf ("%f", &g1[i]);
    }
    for (i=0; i<alunos; i++){
        printf ("Informe a nota do aluno %d no G2: ", i+1);
        scanf ("%f", &g2[i]);
    }

    for (i=0; i<alunos; i++){
        media[i]=0;
        media[i]=(g1[i]+g2[i])/2;
        printf ("ALUNO %d \tNOTA 1: %.2f\tNOTA2: %.2f\tMEDIA: %.2f\n",i+1,g1[i],g2[i],media[i]);
    }

}
