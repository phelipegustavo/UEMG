#include "biblioteca.h"

int main(){
    
    T_lista *aux=(T_lista*)malloc(sizeof(T_celula));
    T_celula *item=(T_celula*)malloc(sizeof(T_celula));
    T_celula *item2=(T_celula*)malloc(sizeof(T_celula));
    
    inicializar(aux);
    strcpy(item->acao,"Insercao");
    strcpy(item->data,"26/06/2016");
    strcpy(item->nome,"EU");
    strcpy(item->tabela,"Cliente");
    inserir(aux,item);
    
    
    strcpy(item->acao,"Delecao");
    strcpy(item->data,"27/06/2016");
    strcpy(item->nome,"N_EU");
    strcpy(item->tabela,"Produto");
    inserir(aux,item);
    
    
    strcpy(item2->data,"26/06/2016");
    imprimirTabela(aux,item2);
    
    
    return 0;
}