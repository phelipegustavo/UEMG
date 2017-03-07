#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#define QTD 35 //Quantidade de Funcionarios

typedef struct {
    char nome[30];
    float salario;
    int cargo; 
}funcionario;

funcionario ler(){
    funcionario aux;
    printf ("\nNome do funcionario: ");
    scanf ("%s", aux.nome);
    printf ("Salario: ");
    scanf ("%f", &aux.salario);
    printf ("Iforme o Cargo ");
    printf ("\n1-SECRETARIO(A)");
    printf ("\n2-OPERADOR(A)");
    printf ("\n3-SUPERVISOR(A)");
    printf ("\n4-GERENTE");
    printf ("\nCargo: ");
    scanf ("%d", &aux.cargo);
    
    return aux;
}

funcionario aumento (funcionario aux, int cargo){    
    
    switch (cargo){
        case 1: aux.salario*= 1.05;break;
        case 2: aux.salario*= 1.05;break;
        case 3: aux.salario*= 1.07;break;
        case 4: aux.salario*= 1.075;break;
    }
    return aux;
}

void imprimir (funcionario aux){
    printf ("\nFUNCIONARIO: %s", aux.nome);
    printf ("\nSALARIO: R$ %.2f", aux.salario);
    switch (aux.cargo){
        case 1: printf ("\nCARGO: Secretario(a)\n");break;
        case 2: printf ("\nCARGO: Operador(a)\n");break;
        case 3: printf ("\nCARGO: Supervisor(a)\n");break;
        case 4: printf ("\nCARGO: Gerente\n");break;
    }
}

int main(){
    
    int i,j=0,op=10;
    int cargo;
    funcionario aux[QTD]; //Variavel para cadastrar funcionarios
        
    while (op!=0){
        printf ("\n-------------MENU-------------");
        printf ("\n1-CADASTRO");
        printf ("\n2-REALIZAR AUMENTO");
        printf ("\n3-ORDENAR FUNCIONARIOS POR SALARIOS");
        printf ("\n4-IMPRIMIR TODOS OS SUPERVISORES");
        printf ("\n5-IMPRIMIR TODOS OS GERENTES");
        printf ("\n6-IMPRIMIR TODOS OS FUNCIONARIOS");
        printf ("\n0-SAIR\n");
        scanf ("%d", &op);
        printf ("------------------------------\n");
        
        if (op==1){
            aux[j]=ler();
            j++;
        
        }else if (op==2){
            printf ("Realizar aumento para quais funcionarios: ");
            printf ("\n1-SECRETARIO(A)");
            printf ("\n2-OPERADOR(A)");
            printf ("\n3-SUPERVISOR(A)");
            printf ("\n4-GERENTE\n");
            scanf ("%d", &cargo);
            
            for (i=0; i<j; i++){
                if (cargo==aux[i].cargo)
                aux[i]=aumento(aux[i], cargo);
            }
        
        }else if (op==3){
            funcionario menor;
            int k;
            
            for (i=1; i<j; i++){
                for (k=0; k<j; k++){
                    if (aux[i].salario<aux[k].salario){
                    menor=aux[i];
                    aux[i]=aux[k];
                    aux[k]=menor;
                    }
                }
            }
            for (i=0; i<j; i++){
                imprimir (aux[i]);
            }
        
        }else if (op==4){
            for (i=0; i<j; i++){
                if (aux[i].cargo==3)
                    imprimir(aux[i]);
            }
        
        }else if(op==5){
            for (i=0; i<j; i++){
                if (aux[i].cargo==4)
                    imprimir(aux[i]);
            }
        
        }else if (op==6){
            for (i=0; i<j; i++){
                imprimir(aux[i]);
            }
        }else if (op==0){
            printf ("SAINDO...");
        }
    } 
    return 0;
}