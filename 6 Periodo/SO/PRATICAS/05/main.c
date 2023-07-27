#include <stdio.h>
#include <stdlib.h>

int printProcesso();
int main() {

    return 0;

    system("./FSFS");
}

int printProcesso(int index, int pid){
    for (int i=index; i<index+40; i++) {
        printf("<system time %d> process %d is running\n", i, pid);
    }
    printf("<system time %d> process %d finish\n", index+40, pid);        
    return index+40;
}