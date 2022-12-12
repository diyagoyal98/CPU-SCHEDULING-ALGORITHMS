#include<stdio.h>

#include<stdbool.h>
#include<conio.h>
#define MAX 100
struct process_struct
{
    int at,pid,bt;
    int ct,wt,tat,rt,start_time;
}ps[100];


int main()
{
    int n;
    printf("Enter the number of process   ");
    scanf("%d",&n);

    printf("Enter the arrival times   ");
    for(int i=0;i<n;i++)
    {
        scanf("%d",&ps[i].at);
        ps[i].pid=i;
    } 

    printf("Enter the burst time   ");
    for(int i=0;i<n;i++)
    {
        scanf("%d",&ps[i].bt);
    }

    int current_time=0,prev=0;
    int completed=0;
    int sum_tat=0,sum_wt=0,sum_rt=0;
    int total_idel_time=0;
    bool is_completed[MAX]={false};
    bool is_first_process=true;
    while(completed!=n)
    {
        int min_idx=-1;
        int minimum=100000000;

        for(int i=0;i<n;i++)
        {
            if(ps[i].at<=current_time && is_completed[i]==false)
            {
                if(ps[i].bt < minimum)
                {
                    minimum=ps[i].bt;
                    min_idx=i;
                }
                if(ps[i].bt == minimum)
                {
                    if(ps[i].at<ps[min_idx].at)
                    {
                        min_idx=i;
                        minimum=ps[i].bt;
                    }
                }
            }
        }

        if(min_idx==-1)
        {
            current_time++;
        }
        else
        {
            ps[min_idx].start_time=current_time;
            ps[min_idx].ct=ps[min_idx].start_time+ps[min_idx].bt;
            ps[min_idx].tat=ps[min_idx].ct-ps[min_idx].at;
            ps[min_idx].wt=ps[min_idx].tat-ps[min_idx].bt;
            ps[min_idx].rt=ps[min_idx].wt;

            sum_tat+=ps[min_idx].tat;
            sum_rt+=ps[min_idx].rt;
            sum_wt+=ps[min_idx].wt;

            total_idel_time+=(is_first_process==true)?0:(ps[min_idx].start_time-prev);

            completed++;

            is_completed[min_idx]=true;
            current_time=ps[min_idx].ct;
            prev=current_time;
            is_first_process=false;
        }
    }


    printf("Process Number\tArrival Time\tBurst Time\tStart Time\tCT\tTAT\tWT\tRT\n");

    for(int i=0;i<n;i++)
    {
        printf("%d\t\t%d\t\t%d\t\t%d\t\t%d\t\t%d\t\t%d\t\t%d\n\n",ps[i].pid,ps[i].at,ps[i].bt,ps[i].start_time,ps[i].ct,ps[i].tat,ps[i].wt,ps[i].rt);
    }

    printf("\n tat  %d",sum_tat);
}