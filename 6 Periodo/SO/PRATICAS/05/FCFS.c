#include<stdio.h>

int printProcesso(int index, int pid); 
int main()
{
    int n,bt[20],wt[20],tat[20],tc[20],avwt=0,avtat=0,i,j;
    printf("Insira a quantidade de processos (max 20):");
    scanf("%d",&n);
 
    printf("\nInsira o tempo de chegada: \n");
    for(i=0;i<n;i++)
    {
        printf("Tchegada[%d]:",i+1);
        scanf("%d",&tc[i]);
    }

    printf("\nInsira o tempo de execucao: \n");
    for(i=0;i<n;i++)
    {
        printf("P[%d]:",i+1);
        scanf("%d",&bt[i]);
    }
 
    wt[0]=0;    //Tempo de espera para primeiro processo é 0
    //Calculando tempo de espera
    for(i=1;i<n;i++)
    {
        wt[i]=0;
        for(j=0;j<i;j++)
            wt[i]+=bt[j];
        wt[i]=wt[i]-tc[i];
    }
    
    int index = printProcesso(0, 1);
    for(int i=1; i<n; i++){
        index = printProcesso(index, i+1);
    }

    printf("\nProcesso\tTempo de Exec.\tTempo de Esp.\tTempo de Resp.");
 
    //Calculando tempo de Resposta
    for(i=0;i<n;i++)
    {
        tat[i]=bt[i]+wt[i]+tc[i];
        avwt+=wt[i];
        avtat+=tat[i];
        printf("\nP[%d]\t\t%d\t\t%d\t\t%d",i+1,bt[i],wt[i],tat[i]);
    }
 
    avwt/=i;
    avtat/=i;
    printf("Uso da cpu: 100");    
    printf("\n\nTempo Medio de Espera:%d",avwt);
    printf("\nTempo Medio de Resposta:%d",avtat);
    printf("\n-------------------------------\n");
    return 0;
}

int printProcesso(int index, int pid){
    for (int i=index; i<index+10; i++) {
        printf("<system time %d> process %d is running\n", i, pid);
    }
    printf("<system time %d> process %d finish\n", index+10, pid);        
    return index+11;
}