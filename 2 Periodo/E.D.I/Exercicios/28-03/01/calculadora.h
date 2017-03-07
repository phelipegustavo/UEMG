#ifndef CALCULADORA_H
#define CALCULADORA_H

#include <stdio.h>
#include <math.h>

float ler_A (){
    float a;
    printf ("Informe o valor do primeiro numero: ");
    scanf ("%f", &a);
    return a;
}
float ler_B (){
    float b;
    printf ("Informe o valor do segundo numero: ");
    scanf ("%f", &b);
    return b;
}

float soma (float a, float b){  
    a=ler_A();
    b=ler_B();
    return a+b;
}

float subtracao (float a, float b){
    a=ler_A();
    b=ler_B();
    return a-b;
}

float divisao (float a, float b){
    a=ler_A();
    b=ler_B();
    return a/b;
}

float multiplicacao (float a, float b){
    a=ler_A();
    b=ler_B();
    return a*b;
}

void igualdade (float a, float b){
    a=ler_A();
    b=ler_B();
    if (a==b){
        printf ("OS VALORES %.2f e %.2f SAO IGUAIS", a ,b);
    }else {
        printf ("OS VALORES %.2f e %.2f SAO DIFERENTES", a,b);
    }
}

float potencia (float base, float expoente){
    printf ("Informe o valor da Base :");
    scanf("%f", &base);
    printf ("Informe o valor do Expoente :");
    scanf("%f", &expoente);
    float c=1,i;
    if (expoente == 1){
        c = 1;
    }
    else {
        for (i=0; i<expoente; i++){
            c*=base;
        }
    }
    return c;
}


#endif	// CALCULADORA_H

