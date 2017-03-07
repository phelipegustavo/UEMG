#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
/*2.Com a finalidade de melhorar a segurança e auditoria de uma empresa, 
teve-se a ideia de gerar uma lista com todas as ações de todos os usuários 
que utilizam um banco de dados. Como serão muitos dados inseridos esta lista
não pode ter tamanho máximo definido, portanto, deve-se criar uma lista 
inâmica contendo os seguintes dados: Nome do Usuário, Tipo de Ação no banco
de Dados (Inserção, Deleção ou Edição), Nome da Tabela (Cliente ou Produtos) 
e Data da Ação (Exemplo: 24/06/2016 – “String”). Para então gerar o controle 
e fazer a auditoria de sistemas, crie as funções em uma biblioteca:
a.Inserir Ação (insere item na lista)
b.Impressão por um determinado tipo de Ação (Imprimir todas as ações de acordo com um parâmetro tipo de ação)
c.Impressão por uma determinada data (Imprimir todas as ações de acordo com um parâmetro data)
d.Impressão por uma determinada tabela (Imprimir todas as ações de acordo com um parâmetro data)*/

typedef struct celula {
    char nome[30];
    char acao[10];
    char tabela[10];
    char data[15];
    struct celula *proximo;
} T_celula;

typedef struct {
    T_celula *primeiro;
    T_celula *ultimo;
} T_lista;

void inicializar(T_lista *aux) {
    aux->primeiro = (T_celula*) malloc(sizeof (T_celula));
    aux->ultimo = aux->primeiro;
}

bool vazia(T_lista *aux) {
    return aux->primeiro == aux->ultimo;
}

void inserir(T_lista *aux, T_celula *item) {
    aux->ultimo->proximo = (T_celula*) malloc(sizeof (T_celula));
    aux->ultimo = aux->ultimo->proximo;
    strcpy(aux->ultimo->acao, item->acao);
    strcpy(aux->ultimo->data, item->data);
    strcpy(aux->ultimo->nome, item->nome);
    strcpy(aux->ultimo->tabela, item->tabela);
    aux->ultimo->proximo = NULL;
}

void imprimirAcao(T_lista *aux, T_celula *item) {
    T_celula *temp = aux->primeiro->proximo;
    while (temp != NULL) {
        if (strcmp(temp->acao, item->acao) == 0) {
            printf("------------------------\n");
            printf("Nome: %s\n", item->nome);
            printf("Data: %s\n", item->data);
            printf("Acao: %s\n", item->acao);
            printf("Tabela: %s\n", item->tabela);
        }
        temp = temp->proximo;
    }
}

void imprimirData(T_lista *aux, T_celula *item) {
    T_celula *temp = aux->primeiro->proximo;
    while (temp != NULL) {
        if (strcmp(temp->data, item->data) == 0) {
            printf("------------------------\n");
            printf("Nome: %s\n", item->nome);
            printf("Data: %s\n", item->data);
            printf("Acao: %s\n", item->acao);
            printf("Tabela: %s\n", item->tabela);
        }
        temp = temp->proximo;
    }
}

void imprimirTabela(T_lista *aux, T_celula *item) {
    T_celula *temp = aux->primeiro->proximo;
    while (temp != NULL) {
        if (strcmp(temp->tabela, item->tabela) == 0) {
            printf("------------------------\n");
            printf("Nome: %s\n", item->nome);
            printf("Data: %s\n", item->data);
            printf("Acao: %s\n", item->acao);
            printf("Tabela: %s\n", item->tabela);
        }
        temp = temp->proximo;
    }
}
