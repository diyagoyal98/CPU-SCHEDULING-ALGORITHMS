#include<stdio.h>
#include<conio.h>
#define MAX 10
int main()
{
    int n,i,qt,count=0,tmp,sq=0;
    int bt[MAX],wt[MAX],tat[MAX],rem_bt[MAX];
    float avg_wt=0;
    float avg_tat=0;

    printf("Enter the number of process ");
    scanf("%d",&n);

    printf("\nEnter the Burst Time  ");
    for(i=0;i<n;i++)
    {
        scanf("%d",&bt[i]);
        rem_bt[i]=bt[i];
    }

    printf("\nEnter quantum time  ");
    scanf("%d",&qt); 


    while(1)
    {
        for(i=0,count=0;i<n;i++)
        {
            tmp=qt;
            if(rem_bt[i]==0)
            {
                count++;
                continue;
            }
            if(rem_bt[i]>qt)
            {
                rem_bt[i]=rem_bt[i]-qt;
            }    
            else
            {
                if(rem_bt[i]>=0)
                {
                    tmp=rem_bt[i];
                    rem_bt[i]=0;
                }
            }
            sq=sq+tmp;
            tat[i]=sq;
        }
        if(n==count)
        break;
    }   

    printf("Process\t\tBurst Time\tWaiting Time\tTurn Around Time\n");
    for(i=0;i<n;i++)
    {
        wt[i]=tat[i]-bt[i];
        avg_wt+=wt[i];
        avg_tat+=tat[i];

        printf("%d\t\t%d\t\t%d\t\t%d\n",i+1,bt[i],wt[i],tat[i]);
    }
    avg_wt/=n;
    avg_tat/=n;
    printf("Average waiting and Turn around time is %f  %f",avg_wt,avg_tat);

    return 0;
}