#include "palavra.h"

//Questão 02

/* Escreva uma biblioteca para pilha dinâmica, considere uma pilha que armazene
 *  caracteres. Escreva as funções de inicializa pilha, de verificação de pilha
 *  vazia e uma função que verifique se uma palavra (pilha de caracteres) e um
 *  palíndromo (retorne 1 para sim e 0 para não). Escreva o main para teste com
 *  as seguintes palavras:
a. OPERA
b. CURSO
c. ROTAS
d. ESCOLA
e. TESTE
f. ARARA
g. MARROCOS
 */

int main() {
    T_palavra* palavra = (T_palavra*) malloc(sizeof (T_apontador));
    inicializar(palavra);
    
    teste(palavra, "OPERA");
    teste(palavra, "CURSO");
    teste(palavra, "ROTAS");
    teste(palavra, "ESCOLA");
    teste(palavra, "TESTE");
    teste(palavra, "ARARA");
    teste(palavra, "MARROCOS");
    
    return 0;
}