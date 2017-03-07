#include <stdio.h>
#include <stdlib.h>

float DEPOSITO(float saldo, float valor){
    saldo=(saldo+valor);
    return saldo;
}

float SAQUE(float saldo, float valor){
    saldo=(saldo-valor);
    return saldo;
}

int main(){
    float saldo, valor;
    int op=-1;
    
    //Receber saldo
    printf("Informe o valor do saldo: ");
    scanf("%f", &saldo);
    
    //Menu
    do{
    printf("\nQual Servico deseja realizar: ");
    printf("\n1-Exibir Saldo \n2-Saque \n3-Deposito \n0-Sair\n");
    scanf ("%d", &op);
    
    if (op==0)
        printf("Saindo...\n");
    
    else if (op==1){ 
        printf("SALDO = R$ %.2f\n", saldo);
    }
    else if (op==2){    
        printf("\nInforme o valor do saque: R$ ");
        scanf("%f", &valor);
        saldo=SAQUE(saldo,valor);
    }            
    else if (op==3){    
        printf("\nInforme o valor do deposito: R$ ");
        scanf("%f", &valor);
        saldo=DEPOSITO(saldo,valor);       
    }
    
    }while (op != 0);
    
}