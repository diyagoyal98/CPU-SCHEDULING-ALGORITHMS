#include<stdio.h>
#include<conio.h>
#define MAX 10

int main()
{
    int n;
    int bt[MAX],wt[MAX],tat[MAX];
    float avg_tat=0;
    float avg_wt=0;

    printf("Enter the number of proces   ");
    scanf("%d",&n);
    printf("\nEnter the burst time of the process  ");
    for(int i=0;i<n;i++)
    scanf("%d",&bt[i]);

    printf("Process id\tBurst Time\tWaiting Time\tTurn aAround Time\n");

    //Calculating waiting time
    for(int i=0;i<n;i++)
    {
        wt[i]=0;
        for(int j=0;j<i;j++)
        wt[i]+=bt[j];
    }

    //Calculating turn around time waiting time = Turn Around time - Burst Time so turn around time = waiting time + burst time

    for(int i=0;i<n;i++)
    {
        tat[i]=0;
        tat[i]=wt[i]+bt[i];
    }

    //Calculating average turnaround and average waiting time

    for(int i=0;i<n;i++)
    {
        avg_wt+=wt[i];
        avg_tat+=tat[i];
    }

    for(int i=0;i<n;i++)
    {
        printf("%d\t\t%d\t\t%d\t\t%d\n",i,bt[i],wt[i],tat[i]);
    }

    avg_wt=avg_wt/n;
    avg_tat=avg_tat/n;

    printf("Average turnaround time is %f and average waiting time is %f ",avg_tat,avg_wt);

    return 0;
}