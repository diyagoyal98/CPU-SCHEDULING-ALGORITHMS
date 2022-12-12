#include<stdio.h>
#include<conio.h>
#define MAX 10



int main()
{
    int n,i,j,k=1,t,b=0,mini,tmp[MAX],bt[MAX],wt[MAX],at[MAX],pr[MAX],tat[MAX];
    float atat=0,awt=0;
    printf("Enter the number of process ");
    scanf("%d",&n);

    for(int i=0;i<n;i++)
    {
        scanf("%d",&at[i]);
    }
    for(int i=0;i<n;i++)
    {
        scanf("%d",&bt[i]);
    }
    for(int i=0;i<n;i++)
    {
        scanf("%d",&pr[i]);
    }
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
        {
            if(at[i]<at[j])
            {
                t=at[j];
                at[j]=at[i];
                at[i]=t;

                t=bt[j];
                bt[j]=bt[i];
                bt[i]=t;
            }
        }
    }
    for(int j=0;j<n;j++)
    {
        b=b+bt[j];
        mini=bt[k];
        for(int i=k;i<n;i++)
        {
            mini=pr[k];
            
        }
    }

    
}