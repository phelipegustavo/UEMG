#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <string.h>
/*Faça um programa que receba uma frase e troque a palavra ALUNO por ESTUDANTE e a palavra
ESCOLA por UNIVERSIDADE.
Exemplo: EU SOU ALUNO DA ESCOLA
Saída: EU SOU ESTUDANTE DA UNIVERSIDADE*/
int main(){
setlocale(LC_ALL, "Portuguese");

    char frase[100],aluno[6]="aluno",estudante[12]=" estudante ";
    int i,j,c;

    printf("Informe uma frase: ");
    gets (frase);

    for (i=0; i<strlen(frase); i++){

        if (frase[i]==aluno[0]){
            for (j=0; j<6; j++){
                if (frase[i+j]==aluno[j]){
                    c++;
                }
                if (c==5){
                    printf("%d\n", c);

                    c=0;
                }
            }
        }
    }

    printf("%s", frase);

}
