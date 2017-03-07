#include <stdio.h>
#define MAX 250

typedef struct {
    int codigo;
    char filme[30];
    float valor;
    int tipo;
    int sala;
}ingresso;

typedef struct {
    int primeiro;
    int ultimo;
    ingresso lista[MAX];
}cinema;

cinema limpar (cinema aux){
    aux.primeiro=0;
    aux.ultimo=-1;
    return aux;
}

int lugares_sala (cinema aux, int sala){
    int total=0;
    for (int i=0; i<=aux.ultimo; i++){
        if (sala==aux.lista[i].sala)
            total++;
    }
    return total;
}

cinema comprar_ingresso (cinema aux, ingresso entrada){
    if (lugares_sala(aux,entrada.sala)<=50){
        aux.ultimo++;
        aux.lista[aux.ultimo]=entrada;
        printf("Sucesso\n");
    }else
        printf("Sala Cheia!\n");
    return aux;
}

int pesquisar_ingresso (cinema aux, int codigo){
    int posicao= -1;
    for (int i=0; i<=aux.ultimo; i++){
        if (aux.lista[i].codigo==codigo)
            posicao=i;
        else
            printf("Codigo inválido!\n");
        
    }
    return posicao;
}

cinema devolver_ingresso (cinema aux, int codigo){
    int posicao=pesquisar_ingresso(aux,codigo);
    if (posicao==-1){
        printf("Ingresso não pode ser devolvido\n");
    }else{
        for (int i=posicao; i<=aux.ultimo; i++){
            aux.lista[i]=aux.lista[i+1];
        }
        aux.ultimo--;
    }
    return aux;
}

void imprimir (cinema aux, int sala){
    for (int i=0; i<=aux.ultimo; i++){
        if (aux.lista[i].sala==sala){
            printf("\nCodigo: %d", aux.lista[i].codigo);
            printf("\nFilme: %s", aux.lista[i].filme);
            printf("\nSala: %d", aux.lista[i].sala);
            printf("\nTipo do Ingresso: ");
            if (aux.lista[i].tipo==1)
                printf ("Inteira");
            else 
                printf ("Meia");
            printf("\nValor: %.2f", aux.lista[i].valor);
            printf("\n------------------------");
        }
    }
}

float valor_sala (cinema aux, int sala){
    float total=0;
    for (int i=0; i<=aux.ultimo; i++){
        if(aux.lista[i].sala==sala){
            total+=aux.lista[i].valor;
        }
    }
    return total;
}

cinema backup (cinema aux,cinema copia){
    int sala=1;
    while (sala<=5){
        for (int i=0; i<=aux.ultimo; i++){
            if(aux.lista[i].sala=sala)
                copia.lista[i]=aux.lista[i];
        }
        sala++;
    }
    copia.primeiro=aux.primeiro;
    copia.ultimo=aux.ultimo;
    printf("\nBackup Realizado com Sucesso\n");
}

int total_meia (cinema aux){
    int total=0;
    for (int i=0; i<=aux.ultimo; i++){
        if (aux.lista[i].tipo==2){
            total++;
        }
    }
    return total;
}

cinema fechamento (cinema aux){
    float total=0;
    for (int i=0; i<=aux.ultimo; i++){
        total+=aux.lista[i].valor;
    }
    printf("\nTotal: R$%.2f", total);
    aux=limpar(aux);
    return aux;
}
