/*6.Existem partes de sistemas operacionais que cuidam da ordem em que 
 * os programas devem ser executados. Por exemplo, em um sistema de computa��o  
 * de tempo-compartilhadao (�time-shared�) existe a necessidade de manter um 
 * conjunto de  processos em uma fila, esperando para serem executados. 
 * Escreva tr�s fun��es, uma  para cada opera��o abaixo:      
a.	Incluir novos processos na fila de processo;  
b.	Retirar da fila o processo com o maior tempo de espera;  
c.	Imprimir o conte�do da lista de processos em determinado momento.  
d.	Assuma que cada processo � representado por um registro composto por 
 *      um n�mero identificador do processo e seu nome (fa�a uma struct).
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX 7

typedef struct {
    int id;
    char nome[20];
} T_chave;

typedef struct {
    int frente;
    int tras;
    T_chave fila[MAX];
} T_fila;

T_fila inicializar(T_fila aux) {
    aux.frente = 1;
    aux.tras = 1;
    return aux;
}

int cheia(T_fila aux) {
    return (aux.tras % MAX + 1 == aux.frente) ? 1 : 0;
}

T_fila inserir(T_fila aux, T_chave item) {
    if (cheia(aux) == 0) {
        aux.fila[aux.tras-1] = item;
        aux.tras = aux.tras % MAX + 1;
    } else {
        printf("Fila cheia!");
    }
    return aux;
}

T_fila retirar(T_fila aux) {
    aux.frente = aux.frente % MAX + 1;
    return aux;
}

void imprimir(T_fila aux) {
    for (int i = aux.frente; i != aux.tras; i = i % MAX + 1) {
        printf("Nome: %5c\n", aux.fila[i-1].id);
        printf("ID: %5d\n\n", aux.fila[i-1].id);

    }
}

int main() {
    T_fila aux;
    T_chave item;

    //TESTES
    {
    aux = inicializar(aux);
    item.id = 1;
    
    aux = inserir(aux, item);

    item.id = 2;
    
    aux = inserir(aux, item);

    item.id = 3;
   
    aux = inserir(aux, item);

    aux = retirar(aux);
    aux = retirar(aux);

    item.id = 4;
    
    aux = inserir(aux, item);

    aux = retirar(aux);

    item.id = 5;

    aux = inserir(aux, item);
    item.id = 6;
 
    aux = inserir(aux, item);
    }

    imprimir(aux);
    return 0;
}