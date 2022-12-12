#include<iostream>
#include<algorithm>
#include<climits>
#include<queue>
#define MAX 100
using namespace std;

struct process_struct
{
    int pid;
    int at;
    int bt;
    int ct,wt,tat,rt,start_time;
    int bt_rem;
}ps[100];

bool comperatorAt(struct process_struct a,struct process_struct b)
{
    return a.at<b.at;
}

bool comperatorId(struct process_struct a ,struct process_struct b)
{
    return a.pid<b.pid;
}

int main()
{
    int n;
    cout<<"Entert he total number of the process  ";
    cin>>n;

    for(int i=0;i<n;i++)
    {
        cout<<"Enter process "<<i<<"  Arrival Time  ";
        cin>>ps[i].at;
        ps[i].pid=i;
    }


    for(int i=0;i<n;i++)
    {
        cout<<"Enter process "<<i<<"  Burst Time   ";
        cin>>ps[i].bt;
        ps[i].bt_rem=ps[i].bt;
    }

    int tq;
    cout<<"Enter the Time Quanta   ";
    cin>>tq;

    sort(ps,ps+n,comperatorAt); //sorting according to the arrival time

    queue<int>q;
    bool visited[MAX]={false};
    int completed=0;
    int idx=0;
    int current_time=0;
    int total_idel_time=0;
    bool is_first_process=true;
    int sum_tat=0,sum_wt=0,sum_rt=0;

    q.push(0);
    visited[0]=true;
    
    while(completed!=n)
    {
      
        idx=q.front();
        q.pop();


        if(ps[idx].bt == ps[idx].bt_rem)
        {
       
            ps[idx].start_time=max(current_time,ps[idx].at);
            total_idel_time+=(is_first_process == true)?0:ps[idx].start_time-current_time;
            current_time=ps[idx].start_time;
            is_first_process=false;
        }

        if(ps[idx].bt_rem-tq>0)
        {
          
            ps[idx].bt_rem-=tq;
            current_time+=tq;
        }
        else
        {
        
            current_time+=ps[idx].bt_rem;
            ps[idx].bt_rem=0;
            completed++;


            ps[idx].ct=current_time;
            ps[idx].tat=ps[idx].ct-ps[idx].at;
            ps[idx].wt=ps[idx].tat-ps[idx].bt;
            ps[idx].rt=ps[idx].start_time-ps[idx].at;

            sum_tat+=ps[idx].tat;
            sum_wt+=ps[idx].wt;
            sum_rt+=ps[idx].rt;
        }
        
        for(int i=1;i<n;i++)
        {
            
            if(ps[i].bt_rem>0 && ps[i].at<=current_time && visited[i]==false)
            {
                q.push(i);
                visited[i]=true;
            }
        }
       
        if(ps[idx].bt_rem >0)
        {
            q.push(idx);
        }

        if(q.empty())
        {
            for(int i=1;i<n;i++)
            {
                if(ps[i].bt_rem>0)
                {
                    q.push(i);
                    visited[i]=true;
                    break;
                }
            }
        }
    }

    int max_comp_time=INT_MIN;
    for(int i=0;i<n;i++)
    {
        max_comp_time=max(max_comp_time,ps[i].ct);
    }

    int length_cycle=0;
    length_cycle=max_comp_time-ps[0].at;
    int cpu_utli=0;
    cpu_utli=(float)(length_cycle-total_idel_time)/length_cycle;

    sort(ps,ps+n,comperatorId);
    cout<<"Process Number\tArrival Time\tBurst Time\tStart Time\tCT\tTAT\tWT\tRT\n";

    for(int i=0;i<n;i++)
    {
        cout<<i<<"\t\t"<<ps[i].at<<"\t\t"<<ps[i].bt<<"\t\t"<<ps[i].start_time<<"\t\t"<<ps[i].ct<<"\t"<<ps[i].tat<<"\t"<<ps[i].wt<<"\t"<<ps[i].rt;
        cout<<endl;
    }


    cout<<"Average tat "<<sum_tat<<endl;
    cout<<"Average wt  "<<sum_wt<<endl;
    cout<<"Average rt  "<<sum_rt<<endl;

    cout<<"ThroughPut   "<<(float)length_cycle<<endl;
    cout<<"CPU utlization  "<<cpu_utli<<endl;
    return 0;



     
}