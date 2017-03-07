#include "filacircular.h"

int main() {

    T_fila aux;
    T_chave item;
    
    int op=1;
    
    while (op!=0){
        printf("----------------------\n");
        printf("1-Criar\n");
        printf("2-Inserir\n");
        printf("3-Retirar\n");
        printf("4-Imprimir\n");
        scanf("%d", &op);
        
        switch (op){
            case 1:aux=inicializar(aux);break;
            
            case 2:printf("Numero: ");scanf("%d",&item.valor);aux=inserir(aux,item);break;
            
            case 3:aux=remover(aux);break;
            
            case 4:imprimir(aux);break;
        }
    }
    
    return 0;
}
