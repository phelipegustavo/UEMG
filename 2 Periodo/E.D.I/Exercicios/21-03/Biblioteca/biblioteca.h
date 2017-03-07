#ifndef BIBLIOTECA_H
#define BIBLIOTECA_H

#include <stdio.h>

typedef struct  {
    char nome[20];
    int prat;
    char autor[20];
    int paginas;
    char area[20];
}livro;

livro lerlivro(){
    livro aux;
    printf ("Nome: ");
    scanf ("%s", aux.nome);
    printf ("Prateleira: ");
    scanf ("%d", &aux.prat);
    printf ("Autor: ");
    scanf ("%s", aux.autor);
    printf ("Paginas: ");
    scanf ("%d", &aux.paginas);
    printf ("Area: ");
    scanf ("%s", aux.area);
    
    return aux;
}

void imprimirlivro(livro aux){
    printf("\nNome: %s", aux.nome);
    printf("\nPrateleira: %d", aux.prat);
    printf("\nAutor: %s", aux.autor);
    printf("\nPaginas: %d", aux.paginas);
    printf("\nArea: %s", aux.area);
    printf("\n");
}
#endif	// BIBLIOTECA_H

