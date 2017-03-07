#include <stdio.h>
#define MAXTAM 1000

typedef struct {
    int valor;
} chave;

typedef struct {
    int primeiro;
    int ultimo;
    chave lista [MAXTAM];
} lista;

lista criar_lista() {
    lista aux;
    aux.primeiro = 0;
    aux.ultimo = -1;
    return aux;
}

lista inserir(lista aux, chave item) {

    if (aux.ultimo >= MAXTAM) {
        printf("\nLista cheia");
    } else {
        printf("\nO item sera incluido");
        aux.ultimo++;
        aux.lista[aux.ultimo] = item;
    }
    return aux;
}

bool verificar_lista(lista aux) {
    if (aux.ultimo == -1)
        return true;
    else
        return false;
}

int pesquisar_item(lista aux, chave item) {
    int posicao = -1;
    if (verificar_lista(aux)) {
        printf("\nA lista esta vazia");
    } else {
        for (int i = 0; i <= aux.ultimo; i++) {
            if (aux.lista[i].valor == item.valor) {
                posicao = i;
            }
        }
    }
    return posicao;
}

void imprimir(lista aux) {
    for (int i = 0; i <= aux.ultimo; i++) {
        printf("\n%d", aux.lista[i].valor);
    }
}

lista retirar(lista aux, chave item){
    if(verificar_lista(aux)){
        printf ("\nLista vazia, impossivel retirar");
    }else{
        int posicao = pesquisar_item(aux,item);
        if (posicao == -1){
            printf("\nItem não encontrado, impossivel retirar");
        }else{
            printf("\nItem encontrado e retirado");
            for(int i= posicao; i<aux.ultimo; i++){
                aux.lista[i]=aux.lista[i+1];
            }
            aux.ultimo--;
        }
    }
    return aux;
}

lista ordenar_lista(lista aux){
    chave menor;
    menor.valor=100000;
    for (int i=0; i<=aux.ultimo; i++){
        for (int j=0; j<=aux.ultimo; j++){
            if (aux.lista[i].valor<aux.lista[j].valor){
                menor=aux.lista[i];
                aux.lista[i]=aux.lista[j];
                aux.lista[j]=menor;
            }
        }
    }
    imprimir(aux);
    return aux;
}