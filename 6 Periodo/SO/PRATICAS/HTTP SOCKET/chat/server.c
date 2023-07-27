// Server side C/C++ program to demonstrate Socket programming
#include <unistd.h>
#include <stdio.h>
#include <sys/socket.h>
#include <stdlib.h>
#include <netinet/in.h>
#include <string.h>
#define PORT 8080

int main(int argc, char const *argv[])
{
    int server_id, new_socket, valread;
    struct sockaddr_in address;
    int opt = 1;
    int addrlen = sizeof(address);
    char buffer[1024] = {0};
    char menssagem[100];

    // Criando socket 
    // AF_INET  2 -> Internet IP Protocol
    // SOCK_STREAM	1 -> stream (connection) socket	
    // Protocolo 0 -> confiavel
    if ((server_id = socket(AF_INET, SOCK_STREAM, 0)) == 0) {
        perror("socket failed");
        exit(EXIT_FAILURE);
    }
      
    // Forcefully attaching socket to the port 8080
    if (setsockopt(server_id, SOL_SOCKET, SO_REUSEADDR | SO_REUSEPORT, &opt, sizeof(opt))) {
        perror("setsockopt");
        exit(EXIT_FAILURE);
    }
    address.sin_family = AF_INET;
    address.sin_addr.s_addr = INADDR_ANY;
    address.sin_port = htons( PORT );
      
    // Liga socket a porta
    if ( bind(server_id, (struct sockaddr *)&address, sizeof(address))<0 ) {
        perror("bind failed");
        exit(EXIT_FAILURE);
    }

    // Aguarda Cliente
    while (1) {
        if (listen(server_id, 3) < 0) {
            perror("listen");
            exit(EXIT_FAILURE);
        
        }/*else { 
            printf("SERVIDOR RODANDO NA PORTA %d\n", PORT); 
        }*/

        // Conexao iniciada
        if ((new_socket = accept(server_id, (struct sockaddr *)&address, (socklen_t*)&addrlen))<0) {
            perror("accept");
            exit(EXIT_FAILURE);
        }
        // Recebe do cliente
        valread = read( new_socket , buffer, 1024);
        printf("Cliente Mandou: %s\n", buffer );
        
        printf("Menssagem: ");
        scanf("%s", &menssagem);
        send(new_socket , &menssagem , strlen(&menssagem) , 0 );        
    }
    
    return 0;
}