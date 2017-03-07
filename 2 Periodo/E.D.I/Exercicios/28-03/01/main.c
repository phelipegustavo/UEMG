#include <stdlib.h>
#include <math.h>
#include "calculadora.h"

int main(){
    float n1,n2,R;
    int op=5;
    
    while (op!=0){
        
        printf ("\n----------MENU----------");
        printf ("\n1-SOMA"
                "\n2-SUBTRAÇÃO"
                "\n3-DIVISÃO"
                "\n4-MULTIPLICAÇÃO"
                "\n5-TESTE DE IGUALDADE"
                "\n6-POTENCIA\n"
                "0-SAIR\n");
        
        scanf ("%d", &op);
        printf ("------------------------\n");
        
        switch (op){
            case 1:R=soma(n1,n2);
            printf ("\nRESULTADO %.2f\n", R);break;
            
            case 2:R=subtracao(n1,n2);
            printf ("\nRESULTADO %.2f\n", R);break;
            
            case 3:R=divisao(n1,n2);
            printf ("\nRESULTADO %.2f\n", R);break;
            
            case 4:R=multiplicacao(n1,n2);
            printf ("\nRESULTADO %.2f\n", R);break;
            
            case 5:igualdade(n1,n2);break;
            
            case 6:R=potencia(n1,n2);
            printf ("\nRESULTADO %.2f\n", R);break;
            
            case 0:printf ("Saindo...");break;
            default : printf ("\nOPERAÇÃO INVALIDA\n");
        }
        
    }
    
    return 0;
}