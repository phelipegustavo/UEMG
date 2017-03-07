#ifndef ALUNO_H
#define ALUNO_H

#include <stdio.h>

struct aluno{
    int mat;
    char nome[20];
};

aluno ler_aluno (){
    aluno aux;
    printf("Nome: ");
    scanf("%s", &aux.nome);
    printf("Matricula: ");
    scanf("%d", &aux.mat);
    
    return aux;
}

void imprimir_aluno(aluno aux1){
    printf("Matricula: %d\nNome: %s", aux1.mat, aux1.nome);
}


#endif	// ALUNO_H

