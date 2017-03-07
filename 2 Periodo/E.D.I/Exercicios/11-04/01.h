#include <stdio.h>

typedef struct {
	int valor;
}tipo_chave;

typedef struct {
	int primeiro;
	int ultimo;
	int maxtam;
	tipo_chave lista[maxtam];
}tipo_lista;

tipo_lista limpar(int tam){
	tipo_lista aux;
	
	aux.primeiro=0;
	aux.ultimo=-1;
	aux.maxtam=tam;	
	return aux;
}

int listavazia(tipo_lista aux){
	if (aux.ultimo==-1){
		return 0;
	}else
		return 1;
}

int pesquisar (tipo_lista aux, tipo_chave item){
	int posicao=-1;
	for (int i=0; i<aux.ultimo; i++){
		if (aux.lista[i]==item){
			posicao = i;	
		}return posicao;
	}
}

tipo_lista inserir (tipo_lista aux, tipo_chave item){
	if (aux.ultimo+1<aux.maxtam){
		aux.lista[aux.ultimo+1]=item;
	}
	return aux;
}

tipo_lista retirar (tipo_lista aux, tipo_chave item){
	int posicao=-1;
	posicao=pesquisar(aux,item);
		if (posicao!=-1){
			for (i=posicao; i<=aux.ultimo; i++){
				aux.lista[i]=aux.lista[i+1];
			}
			aux.ultimo--;
		}
	return aux;
}

tipo_lista copiar (tipo_lista aux){
	tipo_lista auxcopia;
	
	auxcopia=aux;
	
	return auxcopia;
}
