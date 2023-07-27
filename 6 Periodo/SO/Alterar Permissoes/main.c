#include <stdio.h>
#include <sys/stat.h>

int chmod(const char *pathname, mode_t mode);
int fchmod(int fd, mode_t mode);

int main(){

    char arquivo="arquivos/a.txt";
    chmod(*arquivo, 666);

    return 0;
}