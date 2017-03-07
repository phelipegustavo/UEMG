#include <stdio.h>
#include <stdlib.h>
#include <math.h>

typedef struct{
    float a;
    float b;
    float c;
    float delta;
    float raiz[2];
}equacao;

equacao LER(){
    equacao aux;
    
    printf ("\nax² + bx + c = 0\n");
    printf("\nINFORME O VALOR DE a : ");
    scanf ("%f", &aux.a);
    printf("INFORME O VALOR DE b : ");
    scanf ("%f", &aux.b);
    printf("INFORME O VALOR DE c : ");
    scanf ("%f", &aux.c);
    
    return aux;
}

equacao DELTA(){
    equacao aux;
 
    aux.delta=pow(aux.b,2)-4*(aux.a*aux.c);
    printf ("\nDELTA = %.2f\n", aux.delta);
    return aux;
}

equacao RAIZ(){
    equacao aux;
    
    aux.delta=pow(aux.b,2)-4*(aux.a*aux.c);
    if(aux.delta<0){
        printf("\nDELTA < 0 A EQUAÇÃO NÃO POSSUI RAIZES REAIS");
    }else if(aux.delta==0){
        aux.raiz[0]=(-(aux.b)+sqrt(aux.delta))/(2*aux.a);
        printf ("\nDELTA = 0 A EQUAÇÃO POSSUI UMA RAIZ REAL");
        printf ("\nRAIZ = %.2f", aux.raiz[0]);
    }else{ 
        aux.raiz[0]=(-(aux.b)+sqrt(aux.delta))/(2*aux.a);
        aux.raiz[1]=(-(aux.b)-sqrt(aux.delta))/(2*aux.a);
        printf ("\nRAIZES = %.2f e %.2f", aux.raiz[0], aux.raiz[1]);
    }
    printf ("\n");
    return aux;
}

void IMPRIMIR(equacao aux){

    printf ("\nEQUAÇÃO: ");
    printf ("%.2fx²",aux.a);
    if (aux.b>=0){ 
        printf ("+%.2fx",aux.b);
    }else if (aux.b<0){ 
        printf ("%.2fx",aux.b);
    }
    if (aux.c>=0){ 
        printf ("+%.2f",aux.c);
    }else if (aux.c<0){ 
        printf ("%.2f",aux.c);
    }
    printf ("\n"); 
}

int main(){
    equacao aux; //Variavel para armazenar dados da equação
    int op=10;
    
    while (op!=0){
        printf ("\n----------MENU----------");
        printf ("\n1-INSERIR EQUAÇÃO");
        printf ("\n2-CALCULAR DELTA");
        printf ("\n3-CALCULAR RAIZES");
        printf ("\n4-IMPRIMIR");
        printf ("\n0-SAIR\n");
        scanf ("%d", &op);
        printf ("------------------------\n");
        
        switch (op){
            case 1: aux = LER(); break;
            case 2: aux = DELTA (); break;
            case 3: aux = RAIZ (); break;
            case 4: IMPRIMIR (aux); break;
            case 0: printf ("\nSAINDO...");break;
            default: printf ("\nOPÇÃO INVALIDA\n");
        }
        
        
    }
    return 0;
}