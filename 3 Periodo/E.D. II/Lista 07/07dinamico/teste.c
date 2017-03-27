#include "07dinamico.h"


void alterar (T_apontador ponteiro){
	ponteiro->item.valor = 1000;
}


void alterar2 (T_apontador ponteiro){
	alterar (ponteiro);
	
	ponteiro->item.valor *= 2; 
}

void alterar3 (T_apontador ponteiro){
	T_apontador pon
	alterar2 (ponteiro);
	
	ponteiro->item.valor *=4;
}



int main(){


	T_apontador pont = (T_apontador)malloc(sizeof(T_celula));
	
	alterar3(pont);
	
	printf("%d", pont->item.valor);
	
}
