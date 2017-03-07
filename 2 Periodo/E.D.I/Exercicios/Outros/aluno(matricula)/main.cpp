#include <stdio.h>
#include "aluno.h"

int main(){
    aluno turma[20];
    int i;
    
    for(i=0; i<20; i++){
        turma[i]=ler_aluno();
    }
    for(i=0; i<20; i++){
        imprimir_aluno(turma[i]);
    }    
    
    return 0;
}