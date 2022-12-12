#include<stdio.h>
#include<limits.h>
#define MAX 20
typedef struct
{
    int id;
    int burst_time;
    int arr_time;
    int priority;

}process;
int main()
{
    
    int waiting[10],turnaround[10],completion[10];
    int i,j,smallest,count=0,time,n;
    double avg=0,tt=0,end;

    printf("\nEnter the number of Processes: ");
    scanf("%d",&n);

    process p[MAX+1];
    int x[MAX];

    for(i=0;i<n;i++)
   {
      printf("\nEnter arrival time, burst time, priority of process: ");
      scanf("%d%d%d",&p[i].arr_time,&p[i].burst_time,&p[i].priority);
      p[i].id = i;
   }
    for(i=0; i<n; i++)
        x[i]=p[i].burst_time;

    p[n].priority = -1;
    printf("Process\t||\tArrival Time\t||\tCompletion time\n");
    for(time=0; count!=n; time++)
    {
        smallest=n;
        for(i=0;i<n;i++)
        {
            if(p[i].arr_time<=time && p[i].priority>p[smallest].priority && p[i].burst_time>0 )
                smallest=i;
        }
        p[smallest].burst_time--;

        if(p[smallest].burst_time==0)
        {
            count++;
            end=time+1;
            completion[smallest] = end;
            waiting[smallest] = end - p[smallest].arr_time - x[smallest];
            turnaround[smallest] = end - p[smallest].arr_time;
            printf("Process %d, arrival: %d, completion: %d\n",smallest+1,p[smallest].arr_time, completion[smallest]);
        }
    }
     for(i=0;i<n;i++)
    {
        // printf("p")i+1)"\t\t")x[i])"\t\t")a[i])"\t\t")waiting[i])"\t\t")turnaround[i])"\t\t")completion[i])"\t\t")pr[i])endl;
        printf("Waiting : %d, turnaround : %d\n", waiting[i], turnaround[i]);
        avg = avg + waiting[i];
        tt = tt + turnaround[i];
    }
    printf("\nAverage waiting time = %f",avg/(float)n);
    printf("\nAverage Turnaround time =  %f",tt/(float)n);
}