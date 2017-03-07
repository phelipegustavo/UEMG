#include <stdio.h>
#include <stdlib.h>
#define MAX 100

typedef struct {
    int valor;
}chave;

typedef struct {
    int topo;
    chave pilha[MAX];
}pilha;

pilha criarpilha (pilha aux) {
    aux.topo = -1;
    return aux;
}

bool pilhacheia(pilha aux) {
    if (aux.topo++ == MAX)
        return true;
    else 
        return false;
}

pilha empilhar (pilha aux, chave item) {
    if (!pilhacheia(aux)){
        aux.topo++;
        aux.pilha[aux.topo]=item;
    }else 
        printf("\nPilha Cheia!Impossivel empilhar");
    
    return aux;
}

pilha desempilhar (pilha aux) {
    if (aux.topo==-1){
        printf ("\nA pilha esta vazia");    
    }else
        aux.topo--;
    
    return aux;
}

int pesquisar (pilha aux, chave item){
    int posicao=-1;
    for (int i=0; i<=aux.topo; i++){
        if (item.valor==aux.pilha[i].valor)
            posicao=i;
    }
    return posicao;
}
                                     
pilha retirar_item (pilha aux, chave item) {
    pilha temp;
    temp=criarpilha(temp);
    int posicao=pesquisar (aux,item);
    if (posicao==-1){
        printf("Item nao encontrado na pilha!");
    }else{
        for (int i=aux.topo; i>posicao; i--){   
            temp=empilhar (temp, aux.pilha[aux.topo]);
            aux=desempilhar (aux);
        }
        aux=desempilhar(aux);
        for (int i= temp.topo; i>=0; i--){
            aux=empilhar (aux, temp.pilha[temp.topo]);
            temp=desempilhar (temp);
        }
    }
    return aux;
    
}

void imprimir (pilha aux){
    for (int i=0; i<=aux.topo; i++){
        printf("\n%d", aux.pilha[i].valor);
    }
    
}