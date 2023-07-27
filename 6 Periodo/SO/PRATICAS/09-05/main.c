#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <sys/types.h>
#include <sys/wait.h>


void exemplo_getPid();
void exemplo_exec();
int main(){

    pid_t c_pid, c_pidb, c_pidc, pid;
    int status;

    printf("Inicio do Programa\n");

    c_pid=fork(); //joao
    //printf("depois do fork 1\n");
    //printf("PID 1: %d \n", c_pid);
    c_pidb=fork(); //phelipe
    //printf("depois do fork 2\n");
    //printf("PID 2: %d \n", c_pidb);    
    c_pidc=fork();  //gustavo
    
    //Joao
    if(c_pid==0){
        //filho
        pid = getpid();
        
        int a=0;
        a+=5;
        printf("Eu sou joao %d\n", a);
                
        printf("Filho meu PID e: %d\n", pid);
        printf("Filho dormindo por 2 segundos\n");
        sleep(2);
        exit(12); //Sai com status 12
    }else if(c_pid > 0) {
        //Pai

        //Esperando o filho terminar
        pid = wait(&status);

        if(WIFEXITED(status)){
            printf("Pai: filho finalizado com status %d\n", status);
        }
    }
    //phelipe
    if(c_pidb==0){
        //filho
        pid = getpid();
        
        int b=0;
        b+=5;
        printf("Eu sou phelipe %d\n", b);
                
        printf("Filho meu PID e: %d\n", pid);
        printf("Filho dormindo por 2 segundos\n");
        sleep(2);
        exit(12); //Sai com status 12
    }else if(c_pidb > 0) {
        //Pai

        //Esperando o filho terminar
        pid = wait(&status);

        if(WIFEXITED(status)){
            printf("Pai: filho finalizado com status %d\n", status);
        }
    }
    //gustavo
    if(c_pidc==0){
        //filho
        pid = getpid();
        
        int a=0;
        a+=5;
        printf("Eu sou gustavo %d\n", a);
                
        printf("Filho meu PID e: %d\n", pid);
        printf("Filho dormindo por 2 segundos\n");
        sleep(2);
        exit(12); //Sai com status 12
    }else if(c_pidc > 0) {
        //Pai

        //Esperando o filho terminar
        pid = wait(&status);

        if(WIFEXITED(status)){
            printf("Pai: filho finalizado com status %d\n", status);
        }
    } else {
        //erro retorno do fork e negativo
        perror("erro no fork\n");
        _exit(2); 
    }
    
    return 0;
}
void exemplo_exec(){
    char* ls_args[] = { "/bin/ls", "-l", NULL };

    // Passando caminho completo
    execv( ls_args[0], ls_args );
    
    // Passando comando
    //execvp( ls_args[0], ls_args );    

    perror("execv");
}

void exemplo_getPid() {

    //pid do processo atual
    //ppid do processo pai
    pid_t pid, ppid;

    pid = getpid();
    ppid = getppid();    

    printf("Meu PID e: %d\n", pid);
    printf("O PID do meu pai e: %d\n", ppid);
    
}
