#include<stdio.h>
#include<conio.h>
#define MAX 30


int main()
{
    int i,n,j,t,bt[MAX],wt[MAX],pr[MAX],tat[MAX],pos;
    float avg_wt=0;
    float avg_tat=0;

    printf("Enter the number of process   ");
    scanf("%d",&n);

    printf("\nEnter the Burst Time of the process   ");
    for(int i=0;i<n;i++)
    scanf("%d",&bt[i]);

    printf("\nEnter the Priority of the process   ");
    for(int i=0;i<n;i++)
    scanf("%d",&pr[i]);

    for(i=0;i<n;i++)
    {
        pos=i;
        for(j=i+1;j<n;j++)
        {
            if(pr[j]<pr[pos])
            pos=j;
        }
        t=pr[i];
        pr[i]=pr[pos];
        pr[pos]=t;

        t=bt[i];
        bt[i]=bt[pos];
        bt[pos]=t;
    }

    wt[0]=0;
    printf("Process\t\tBurst Time\tPriority\tWaiting Time\tTurn Around Time\n");

    for(i=0;i<n;i++)
    {
        wt[i]=0;
        tat[i]=0;

        for(j=0;j<i;j++)
        {
            wt[i]=wt[i]+bt[j];
        }
        tat[i]=wt[i]+bt[i];

        avg_wt+=wt[i];
        avg_tat+=tat[i];

        printf("%d\t\t%d\t\t%d\t\t%d\t\t%d\n",i+1,bt[i],pr[i],wt[i],tat[i]);
    }


    avg_wt/=n;
    avg_tat/=n;
    printf("Average waiting and Turn around time is %f  %f",avg_wt,avg_tat);
}