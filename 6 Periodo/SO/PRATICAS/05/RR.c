
#include<stdio.h>
int exibirProcessos(int quantum, int pid, int bc, int index);
int main() {

    int count,j,n,time,remain,flag=0,time_quantum;
    int wait_time=0,turnaround_time=0,at[10],bt[10],rt[10],process[10];
    printf("Insira a quantidade de processos:\t ");
    scanf("%d",&n);

    remain=n;

    for(count=0;count<n;count++){
        printf("Insira o tempo de chegada e o tempo de execução %d :",count+1);
        scanf("%d",&at[count]);
        scanf("%d",&bt[count]);
        rt[count]=bt[count];
        process[count]=bt[count];
    }

    printf("Insira as fatias de tempo (quantum):\t");
    scanf("%d",&time_quantum);

    int index=0;
    for(j=0;j<n;j++){
    while(process[j]>0){
    for(int i=0; i<n; i++){
        process[i]=exibirProcessos(time_quantum, i, process[i], index);
        index += time_quantum;
    }
    }
    }




    printf("\n\nProcesso\t|Tempo de Resp.|Tempo de Esp.\n\n");

    for(time=0,count=0;remain!=0;) {

        if(rt[count]<=time_quantum && rt[count]>0) {
            time+=rt[count];
            rt[count]=0;
            flag=1;
        } else if(rt[count]>0) {
            rt[count]-=time_quantum;
            time+=time_quantum;
        }
        if(rt[count]==0 && flag==1) {
            remain--;
            printf("P[%d]\t\t|\t%d\t|\t%d\n",count+1,time-at[count],time-at[count]-bt[count]);
            wait_time+=time-at[count]-bt[count];
            turnaround_time+=time-at[count];
            flag=0;
        }
        if(count==n-1) count=0;

        else if(at[count+1]<=time) count++;

        else count=0;
    }

    printf("Uso da cpu: 100");
    printf("\nTempo Medio de Epera = %f\n",wait_time*1.0/n);
    printf("Tempo Medio de Resposta = %f",turnaround_time*1.0/n);
    printf("\n-------------------------------\n");
    return 0;

}

int exibirProcessos(int quantum, int pid, int bc, int index){
    for(int i=0; i<quantum; i++){
        if(bc>0){
            index++;
            printf("<system time %d> process %d is running\n", index, pid);
            bc--;
        }
        if(bc==0){
             printf("<system time %d> process %d is finish\n", index, pid);
            bc--;
        }
    }
    return bc;
}