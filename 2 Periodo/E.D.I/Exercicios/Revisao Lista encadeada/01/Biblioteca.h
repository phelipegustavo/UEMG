#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#define MAX 20

/*1.Para fazer uma fila de processos funcionar (20 processos no máximo), 
o “Processador”, precisa identificar cada processo que está aguardando
“atendimento”, para isso, precisa saber: Tipo do Processamento (Leitura
ou Escrita), Hora de Chegada (valor int da hora), Tipo do Recurso a ser 
utilizado (Banco de Dados, Impressora ou HD). Tendo essas informações crie 
uma biblioteca para “ajudar” o processador a controlar a sua fila, com as funções:

a.Enfileirar Processo 
b.Atender Processo ( “desenfileirar”)
c.Imprimir Fila Completa
d.Avisar Processo que não pode ser atendido (Fila cheia)*/

typedef struct celula {
    char processo[15];
    int hora;
    char recurso[15];
} T_chave;

typedef struct {
    T_chave primeiro;
    T_chave ultimo;
} T_fila;

T_fila inicializar(T_fila aux) {
    aux.primeiro = 1;
    aux.ultimo = 1;
}

bool vazia(T_fila aux) {
    return (aux.primeiro = aux.ultimo);
}

bool cheia(T_fila aux) {
    return (aux.primeiro % MAX +1= aux.ultimo);
}

T_fila inserir(T_fila aux, T_chave item) {

}