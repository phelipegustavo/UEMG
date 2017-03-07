#include <stdio.h>
#include <math.h>


typedef struct{
    float lado[3];
    float angulo[3];
    float perimetro;
    float area;
    
}triangulo;

triangulo CADASTRO(){
    triangulo aux;
    int i;
    float soma =0;
    
    for (i=0; i<3; i++){
        printf ("Informe o %dº lado: ", i+1);
        scanf ("%f", &aux.lado[i]);
    }
    printf ("\n");
    for (i=0; i<3; i++){
        printf ("Informe o %dº Angulo: ", i+1);
        scanf ("%f", &aux.angulo[i]);
        soma += aux.angulo[i];
    }
    if (soma!=180||aux.angulo[0]==0||aux.angulo[1]==0||aux.angulo[2]==0){
        printf("\nPOR FAVOR INSIRA ANGULOS VALIDOS! ");
    }
    
    return aux;
  
}

void LADOS(triangulo aux){
    printf ("\nCLASIFICAÇÃO QUANTO AOS LADOS: Triângulo ");
    if (aux.lado[0]==aux.lado[1]&&aux.lado[0]==aux.lado[2]){
        printf ("Equilatero\n");
    }
    else if (aux.lado[0]==aux.lado[1]||aux.lado[0]==aux.lado[2]||aux.lado[1]==aux.lado[2]){
        printf("Isosceles\n");
    }
    else{
        printf("Escaleno\n");
    }
}

void ANGULOS(triangulo aux){
    printf ("\nCLASSIFICAÇÃO QUANTO AOS ANGULOS: Triângulo ");
    
    int a=0,b=0,c=0,i;
    
    for (i=0; i<3; i++){                        
        if (aux.angulo[i]<90){
        a++;
        }else if (aux.angulo[i]>90){
        b++;
        }else if (aux.angulo[i]==90)
        c++;
    }
    if(a==3&&b==0&&c==0){
        printf ("Acutângulo\n");
    }else if(b==1){
        printf ("Obtusângulo\n");   
    }else if(a==2&&c==1){
        printf ("Retângulo\n");
    }
}

triangulo PERIMETRO(triangulo aux){
    aux.perimetro=0;
    for (int i=0; i<3; i++){
        aux.perimetro +=aux.lado[i];
    }    
    return aux;
}

triangulo AREA(triangulo aux){
    aux=PERIMETRO(aux);
    
    float p ; //Variavel que armazena aux.perimetro/2
    p=aux.perimetro/2; 
    
    aux.area=sqrt(p*(p-aux.lado[0])*(p-aux.lado[1])*(p-aux.lado[2]));//Formula de Heron
    
    return aux;
}

void IMPRIMIR(triangulo aux){
    int i;
    for (i=0; i<3; i++){
        printf ("\nLADO %d : %.2f", i+1, aux.lado[i]);
    }
    printf ("\n--------------------------");
    for (i=0; i<3; i++){
        printf ("\nANGULO %d : %.2f", i+1, aux.angulo[i]);
    }
    aux=PERIMETRO(aux);
    aux=AREA(aux);
    printf ("\n--------------------------");
    printf ("\nPERIMETRO: %.2f", aux.perimetro);
    printf ("\nAREA: %.2f\n", aux.area);
    LADOS (aux);
    ANGULOS (aux);
}
