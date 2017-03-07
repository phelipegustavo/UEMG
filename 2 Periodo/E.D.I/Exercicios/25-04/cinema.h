#include <stdio.h>
#define MAX 250

typedef struct {
    char filme[30];
    float valor;
    int tipo;
    int sala;
    int codigo;
    
}cinema;

typedef struct {
    int primeiro;
    int ultimo;
    cinema lista[MAX];
    
}lista;

lista criar_lista(lista aux){
    aux.primeiro=0;
    aux.ultimo=-1;
    return aux;
   
}

int lugares_sala (lista aux, int sala){
    int cont=0;
    for (int i=0; i<=aux.ultimo; i++){
        if (aux.lista[i].sala==sala){
            cont ++;
        }       
    }
    return cont;
}

lista comprar_ingresso (lista aux, cinema ingresso){
    if (lugares_sala(aux,ingresso.sala)<=50){
        aux.ultimo++;/*
        aux.lista[aux.ultimo].codigo=ingresso.codigo;
        for(int i=0; i<30; i++){
        aux.lista[aux.ultimo].filme[i]=ingresso.filme[i];
        }
        aux.lista[aux.ultimo].sala=ingresso.sala;
        aux.lista[aux.ultimo].tipo=ingresso.tipo;
        aux.lista[aux.ultimo].valor=ingresso.valor;*/
        aux.lista[aux.ultimo]=ingresso;
        
    }else 
        printf ("\nSALA CHEIA");
    return aux;
}

int pesquisar_ingresso (lista aux, cinema ingresso){
    int posicao=-1;
    for(int i=0; i<aux.ultimo; i++){
        if (aux.lista[i].codigo==ingresso.codigo)
            posicao=i;
    }
    return posicao;
}

lista devolver_ingresso (lista aux, int codigo){
    if (codigo <= 250){
        for(int i=codigo; i<=aux.ultimo; i++){
        aux.lista[i]=aux.lista[i+1];   
        }
        aux.ultimo--;
        printf ("\nO ingresso foi devolvido\n");
    }else
        printf ("\nCodigo invalido!\n");
    return aux;
}

void imprimir (lista aux, int sala){

    for (int i=0; i<=aux.ultimo; i++){
        if(aux.lista[i].sala==sala){
            printf ("\nCodigo: %d", aux.lista[i].codigo);
            printf ("\nFilme: %s", aux.lista[i].filme);
            printf ("\nValor: %.2f", aux.lista[i].valor);
            printf ("\nTipo de ingresso: ");
            if (aux.lista[i].tipo==2){
                printf("Meia");
            }else
                printf("Inteira");
            printf("\n-------------------");
        }
    }
}

float total(lista aux, int sala){
    float total=0;
    for (int i=0;i<=aux.ultimo; i++){
        if(aux.lista[i].sala==sala)
            total+=aux.lista[i].valor;
    }
    return total;
}

int total_meia (lista aux){
    int cont=0;
    for (int i=0; i<=aux.ultimo; i++){
        if(aux.lista[i].tipo==2)
            cont++;
    }
    return cont;
}

lista backup (lista aux){
    int cont=1;
    lista copia;
    do{
        for (int i=0; i<=aux.ultimo; i++){
            if (aux.lista[i].sala==cont){
                copia.lista[i]=aux.lista[i];
            }   
        }
        cont++;
    }while (cont<=5);
    copia.primeiro=aux.primeiro;
    copia.ultimo=aux.ultimo;
    return copia;
}

lista fechamento(lista aux){
    float total=0;
    for (int i=0; i<=aux.ultimo; i++){
        total+=aux.lista[i].valor;
    }
    printf("\nTotal Recebido: R$%.f\n", total);
    aux=criar_lista(aux);
    return aux;
}
