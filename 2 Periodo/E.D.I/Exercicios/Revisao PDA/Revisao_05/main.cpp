#include <stdio.h>
#include <stdlib.h>

int main(){
    
    int matriz[5][5]={0},i,j,soma=0;
    long int mult=1;
    float media=0;
    
    for (i=0; i<5; i++){
        for (j=0; j<5; j++){
            printf ("Informe o valor da matriz na posição %d,%d: ", i+1,j+1);
            scanf ("%d", &matriz[i][j]);
        }
    }
    
    for (j=0; j<5; j++){
        soma+=matriz[2][j];
    }
    
    for (i=0; i<5; i++){
        media+=matriz[i][3];
    }
    media/=5;
    
    for (i=0; i<5; i++){
        for (j=0; j<5; j++){
            mult*=matriz[i][j];
        }
    }
    
    printf ("\nSOMA DA 3ª LINHA = %d", soma);
    printf ("\nMEDIA DA 4ª COLUNA = %.2f", media);
    printf ("\nMULTIPLICAÇÂO DE TODOS VALORES = %ld", mult);
}
