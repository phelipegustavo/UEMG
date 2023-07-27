#include<stdio.h>

int printProcesso(int index, int pid); 
void main()
{
    int bt[20],p[20],wt[20],tat[20],tc[20],i,j,n,total=0,pos,temp, tcTemp;
    float avg_wt,avg_tat;
    printf("Insira a quantidade de processos:");
    scanf("%d",&n);
    
    printf("\nInsira o tempo de chegada: \n");
    for(i=0;i<n;i++)
    {
        printf("Tchegada[%d]:",i+1);
        scanf("%d",&tc[i]);
    }

    printf("\nInsira o tempo de execucao:\n");
    for(i=0;i<n;i++)
    {
        printf("p%d:",i+1);
        scanf("%d",&bt[i]);
        p[i]=i+1;           //Contem o numero do processo
    }
 
    //Ordena tempo de execucao em ordem crescente usando ordenacao por selecao
    for(i=0;i<n;i++)
    {
        pos=i;
        for(j=i+1;j<n;j++)
        {
            if(bt[j]<bt[pos])
                pos=j;
        }
 
        temp=bt[i];
        bt[i]=bt[pos];
        bt[pos]=temp;
        temp=p[i];
        tcTemp=tc[i];

        p[i]=p[pos];
        tc[i] = tc[pos];

        p[pos]=temp;
        tc[pos]=tcTemp;
    }
 
    //Tempo de espera para primeiro processo é 0
    
    wt[0]=0;
    //Calculando tempo de espera
    for(i=1;i<n;i++)
    {
        wt[i]=0;
        for(j=0;j<i;j++){
            if(j==0)
                wt[i]+=bt[j]+tc[j];// wt[1]=2+3; wt[2]=2+3+4+2=11;
            else 
                wt[i]+=bt[j];
        }
        wt[i]=wt[i]-tc[i];// wt[1]=5
        total+=wt[i];
    }
 
    avg_wt=(float)total/n;      //Tempo medio de espera
    total=0;
    
    int index = 0;
    for(int i=0; i<n; i++){
        index = printProcesso(index, p[i]);
    }

    printf("\nProcesso\tTempo de Exec.\tTempo de Esp.\tTempo de Resp.");
    for(i=0;i<n;i++)
    {
        tat[i]=bt[i]+wt[i]+tc[i];     
        total+=tat[i];
        printf("\np%d\t\t  %d\t\t    %d\t\t\t%d",p[i],bt[i],wt[i],tat[i]);
    }
 
    avg_tat=(float)total/n;  
    printf("Uso da cpu: 100");       
    printf("\n\nTempo Medio de Espera = %f",avg_wt);
    printf("\nTempo Medio de Resposta = %f\n",avg_tat);
    printf("\n-------------------------------\n");    


    for (int i=0; i<n; i++){
        printf("Tempo exec. %d, Tempo Cheg. %d", bt[i], tc[i]);
    }
}


int printProcesso(int index, int pid){
    for (int i=index; i<index+10; i++) {
        printf("<system time %d> process %d is running\n", i, pid);
    }
    printf("<system time %d> process %d finish\n", index+10, pid);        
    return index+11;
}