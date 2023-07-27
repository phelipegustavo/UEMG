#include <stdlib.h>
#include <stdio.h>
#include <errno.h>
#include <string.h>
#include <sys/types.h>
#include <netinet/in.h>
#include <sys/wait.h>
#include <sys/socket.h>
#include <signal.h>
#include <ctype.h>          
#include <arpa/inet.h>
#include <netdb.h>

#define PORT 20000 
#define BACKLOG 5
#define LENGTH 512 
//#define FILE_SEND "/home/phelipe/video-server.mp4"

void error(const char *msg) {
	perror(msg);
	exit(1);
}

int main (int argc, char *argv[]) {
	int sockfd; 
	int nsockfd; 
	int num;
	int sin_size; 
	struct sockaddr_in addr_local; //endereco cliente
	struct sockaddr_in addr_remote; //endereco servidor
	char revbuf[LENGTH]; // buffer
	char* fs_name = argv[1];

	if((sockfd = socket(AF_INET, SOCK_STREAM, 0)) == -1 ) {
		fprintf(stderr, "ERROR: Falha ao obter Socket! (errno = %d)\n", errno);
		exit(1);
	}
	else printf("[Servidor] Sucesso ao obter Socket.\n");

	// endereco
	addr_local.sin_family = AF_INET; // Protocol Family
	addr_local.sin_port = htons(PORT); // Port number
	addr_local.sin_addr.s_addr = INADDR_ANY; // AutoFill local address
	bzero(&(addr_local.sin_zero), 8); // Flush the rest of struct

	// montando servidor 
	if( bind(sockfd, (struct sockaddr*)&addr_local, sizeof(struct sockaddr)) == -1 ) {
		fprintf(stderr, "ERRO: nao foi possivel montar servidor na porta %d. (errno = %d)\n", PORT, errno);
		exit(1);
	}
	else printf("[Servidor] rodando na porta %d endereco 127.0.0.1.\n",PORT);

	// ouvir porta 
	if(listen(sockfd,BACKLOG) == -1) {
		fprintf(stderr, "ERROR: falha ao ouvir porta. (errno = %d)\n", errno);
		exit(1);
	}
	else printf ("[Servidor] ouvindo na porta %d .\n", PORT);

	while(1) {
		sin_size = sizeof(struct sockaddr_in);

		// aguardando conexao
		if ((nsockfd = accept(sockfd, (struct sockaddr *)&addr_remote, &sin_size)) == -1) {
		    fprintf(stderr, "ERROR: obtendo novo socket (errno = %d)\n", errno);
			exit(1);
		}
		else printf("[Servidor] recebeu conexao %s.\n", inet_ntoa(addr_remote.sin_addr));

		char sdbuf[LENGTH]; // Send buffer
		printf("[Servidor] enviando %s para o cliente...\n", fs_name);
		FILE *fs = fopen(fs_name, "r");
		if(fs == NULL){
			fprintf(stderr, "ERROR: arquivo %s nao encontrado no servidor. (errno = %d)\n", fs_name, errno);
			exit(1);
		}

		bzero(sdbuf, LENGTH); 
		int fs_block_sz; 
		while((fs_block_sz = fread(sdbuf, sizeof(char), LENGTH, fs))>0) {
			if(send(nsockfd, sdbuf, fs_block_sz, 0) < 0){
				fprintf(stderr, "ERROR: falha ao enviar arquivo %s. (errno = %d)\n", fs_name, errno);
				exit(1);
			}
			bzero(sdbuf, LENGTH);
		}
		printf("Ok enviado ao cliente!\n");
		close(nsockfd);
		printf("[Servidor] encerrando conexao...\n");
		while(waitpid(-1, NULL, WNOHANG) > 0);
	}
}
