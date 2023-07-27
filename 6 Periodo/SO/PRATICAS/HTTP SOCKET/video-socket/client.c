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
#define LENGTH 512 
//#define FILE_RECEIVED "/tmp/video-cliente.mp4"

void error(const char *msg) {
	perror(msg);
	exit(1);
}

int main(int argc, char *argv[]) {
	int sockfd; 
	int nsockfd;
	char revbuf[LENGTH]; 
	struct sockaddr_in remote_addr;
	char* fr_name = argv[1];
    

	if ((sockfd = socket(AF_INET, SOCK_STREAM, 0)) == -1) {
		fprintf(stderr, "ERROR: Falha ao obter Socket! (errno = %d)\n",errno);
		exit(1);
	}

	// endereco
	remote_addr.sin_family = AF_INET; 
	remote_addr.sin_port = htons(PORT); 
	inet_pton(AF_INET, "172.16.0.117", &remote_addr.sin_addr); 
	bzero(&(remote_addr.sin_zero), 8);

	// tentar conexao
	if (connect(sockfd, (struct sockaddr *)&remote_addr, sizeof(struct sockaddr)) == -1){
		fprintf(stderr, "ERROR: falha ao conectar com o host! (errno = %d)\n",errno);
		exit(1);
	}
	else printf("[Cliente] conectado ao servidor na porta %d com sucesso!\n", PORT);

	// recebendo arquivo
	printf("[Cliente] Recebendo o arquivo do servidor e salvando em %s\n", fr_name);
	FILE *fr = fopen(fr_name, "a");	
	if(fr == NULL) printf("Nao foi possivel abrir o arquivo %s .\n", fr_name);
	else {
		bzero(revbuf, LENGTH); 
		int fr_block_sz = 0;
	    while((fr_block_sz = recv(sockfd, revbuf, LENGTH, 0)) > 0) {

			int write_sz = fwrite(revbuf, sizeof(char), fr_block_sz, fr);

	        if(write_sz < fr_block_sz) error("Falha ao escrever.\n");

			bzero(revbuf, LENGTH);

			if (fr_block_sz == 0 || fr_block_sz != 512)	break;
		}
		if(fr_block_sz < 0) {

			if (errno == EAGAIN) printf("recv() Tempo excedido.\n");
			else fprintf(stderr, "recv() falha = %d\n", errno);

		}
	    printf("Ok recebido do servidor!\n");
	    fclose(fr);

	    printf(">>> REPRODUZINDO >>>\n");	
		char *args[] = {"/usr/bin/mpv", fr_name, NULL};
		//execv(args[0], args);
        system("/usr/bin/mplayer -vo aa '/tmp/video.mp4'");
	}
	close (sockfd);
	printf("[Cliente] Conexao encerrada.\n");
	return (0);
}
