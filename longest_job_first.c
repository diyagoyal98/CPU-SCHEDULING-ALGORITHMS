#include<stdio.h>
#include<conio.h>
#define MAX 30

int main()
{
    int i,j,n,t,p[MAX],bt[MAX],wt[MAX],tat[MAX];
    float avg_wt=0;
    float avg_tat=0;

    printf("Enter the number of process   ");
    scanf("%d",&n);

    printf("\nEnter the process number   ");
    for(int i=0;i<n;i++)
    scanf("%d",&p[i]);

    printf("\nEnter the Burst Time of the process   ");
    for(int i=0;i<n;i++)
    scanf("%d",&bt[i]);

    //Applying bubble sort technique to sort according to their burst time

    for(i=0;i<n;i++)
    {
        for(j=0;j<n-i-1;j++)
        {
            if(bt[j]<bt[j+1])
            {
                t=bt[j];
                bt[j]=bt[j+1];
                bt[j+1]=t;

                t=p[j];
                p[j]=p[j+1];
                p[j+1]=t;
            }
        }
    }

    printf("Process\t\tBurst Time\tWaiting Time\tTurn Around Time\n");
    for(i=0;i<n;i++)
    {
        wt[i]=0;
        tat[i]=0;

        for(j=0;j<i;j++)
        {
            wt[i]=wt[i]+bt[j];
        }
        tat[i]=bt[i]+wt[i];

        avg_wt+=wt[i];
        avg_tat+=tat[i];

        printf("%d\t\t%d\t\t%d\t\t%d\n",p[i],bt[i],wt[i],tat[i]);
    }
    avg_wt/=n;
    avg_tat/=n;
    printf("Average waiting and Turn around time is %f  %f",avg_wt,avg_tat);
    return 0;
}