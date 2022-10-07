#include<stdio.h>
#include<conio.h>
#define MAX 10



int main()
{
    int n;
    int at[MAX],bt[MAX],tat[MAX],wt[MAX],tmp[MAX];
    float avg_tat=0;
    float avg_wat=0;

    printf("Enter the number of process  ");
    scanf("%d",&n);
    
    printf("\nEnter the arrival time   ");
    for(int i=0;i<n;i++)
    scanf("%d",&at[i]);

    printf("\nEnter the Burst time  ");
    for(int i=0;i<n;i++)
    scanf("%d",&bt[i]);

    tmp[0]=0;
    for(int i=0;i<n;i++)
    {
        wt[i]=0;
        tat[i];
        tmp[i+1]=tmp[i]+bt[i];
        wt[i]=tmp[i]-at[i];
        tat[i]=wt[i]+bt[i];
        avg_wat+=wt[i];
        avg_tat+=tat[i];
    }
    avg_tat=avg_tat/n;
    avg_wat=avg_wat/n;

    printf("Process id\tArrival Time\tBurst Time\tWaiting Time\tTurn Around Time\n");
    for(int i=0;i<n;i++)
    {
        printf("%d\t\t%d\t\t%d\t\t%d\t\t%d\n",i,at[i],bt[i],wt[i],tat[i]);
    }

    printf("Average turn around time is %f and average waitin g time is %f ",avg_tat,avg_wat);
    return 0;
}