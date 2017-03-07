#include <stdlib.h>
#include "triangulo.h"
int op =10;

int main(){
    triangulo aux;
    
    while (op!=0){
        printf ("\n-----------MENU-----------");
        printf ("\n1-CADASTAR TRIANGULO");
        printf ("\n2-CLASSIFICAR QUANTO AOS LADOS TRIANGULO");
        printf ("\n3-CLASSIFICAR QUANTO AOS ÂNGULOS DO TRIANGULO");
        printf ("\n4-RETOMAR PERIMETRO DO TRIANGULO");
        printf ("\n5-RETOMAR AREA DO TRIANGULO");
        printf ("\n6-IMPRIMIR INFORMAÇÕES DO TRIANGULO");
        printf ("\n0-SAIR\n");
        scanf ("%d", &op);
        printf ("--------------------------\n");
        
        switch (op){
            case 1:aux=CADASTRO();break;
            case 2:LADOS (aux);break;
            case 3:ANGULOS(aux);break;
            case 4:aux=PERIMETRO(aux);
                printf ("PERIMETRO: %.2f", aux.perimetro);break;
            case 5:aux=AREA(aux);
		printf ("AREA: %.2f", aux.area);break;
            case 6:IMPRIMIR(aux);break;
            case 0:printf ("\nSAINDO...");break;
            default:printf("\nOPÇÃO INVÁLIDA\n");
        }
    }
    
    return 0;
}
