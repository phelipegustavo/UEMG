#include <stdio.h>
#include <stdlib.h>

int main (){
    
    int i,j,c,cont=0;
    float aluno[20][3],media=0;
            
    for (i=0; i<20; i++){
        for (j=0; j<3; j++){
            printf ("Informe a %dª nota do %dº aluno: ", j+1,i+1);
            scanf ("%f", &aluno[i][j]);
        }
        media=aluno[i][0]*3+aluno[i][1]*4+aluno[i][2]*3;
        media/=10;
        
        if (media>=60)
        cont++;
        media=0;
    }
    printf("\nALUNOS APROVADOS = %d", cont);
    
}