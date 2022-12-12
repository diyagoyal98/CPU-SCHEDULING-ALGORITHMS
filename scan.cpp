#include<iostream>
#include<climits>
#include<vector>
#include<algorithm>
using namespace std;
#define MAX 20
int min_element(int request_queue[],int n)
{
    int mini=INT_MAX;
    for(int i=0;i<n;i++)
    {
        if(request_queue[i]<mini)
        {
            mini=request_queue[i];
        }
    }
    return mini;
}

int max_element(int request_queue[],int n)
{
    int maxi=INT_MIN;
    for(int i=0;i<n;i++)
    {
        if(request_queue[i]>maxi)
        maxi=request_queue[i];
    }
    return maxi;
}
int applySCAN(int total_cylinder,int request_queue[],int initial_pos,int seek_sequence[],int direction,int *sequence_size,int n)
{
    int total_head_mov=0;
    int j=0,k=0;
    vector<int>left(MAX);
    vector<int>right(MAX);

    if(direction == 0)
    {
        if(initial_pos > min_element(request_queue,n))
        {
            right[j++]=total_cylinder-1;
        }
        right[j++]=initial_pos;
    }
    else if(direction == 1)
    {
        if(initial_pos < max_element(request_queue,n))
        {
            left[k++]=0;
        }
        left[k++]=initial_pos;
    }

    for(int i=0;i<n;i++)
    {
        if(request_queue[i]<initial_pos)
        left[k++]=request_queue[i];
        if(request_queue[i]>initial_pos)
        right[j++]=request_queue[i];
    }

    sort(left.begin(),left.end());
    sort(right.begin(),right.end());

    int completed=2;
    while(completed--)
    {
        if(direction==0)
        {
            for(int i=0;i<j;i++)
            {
                total_head_mov+=abs(initial_pos-right[i]);
                initial_pos=right[i];
                seek_sequence[*sequence_size]=right[i];
                (*sequence_size)++;
            }
            direction=1;
        }
        else if(direction == 1)
        {
            for(int i=k-1;i>=0;i--)
            {
                total_head_mov+=abs(initial_pos-left[i]);
                initial_pos=left[i];
                seek_sequence[*sequence_size]=left[i];
                (*sequence_size)++;
            }
            direction=0;
        }
    }
    return total_head_mov;
}

int main()
{
    int total_cylinder;
    printf("Enter the total number of cylinders   ");
    scanf("%d",&total_cylinder);

    int n;
    printf("Enter request queue size   ");
    scanf("%d",&n);

    int request_queue[MAX];
    int seek_sequence[MAX];
    int sequence_size=0;
    int initial_pos=0,direction=0;

    printf("Enter the entries in the request queue   ");
    for(int i=0;i<n;i++)
    {
        scanf("%d",&request_queue[i]);
    }

    printf("Enter the initial position  ");
    scanf("%d",&initial_pos);

    printf("Enter the direction for right enter 0 and for lest enter 1 ");
    scanf("%d",&direction);

    int total_head_mov=applySCAN(total_cylinder,request_queue,initial_pos,seek_sequence,direction,&sequence_size,n);


    printf("Seek sequence is    ");
    for(int i=0;i<sequence_size;i++)
    {
        printf("%d    ",seek_sequence[i]);
    }
    printf("\nTotal number of head movemets  =  %d",total_head_mov);
    printf("\nAverage Head movements  =  %d ",(float)total_head_mov/n);

    return 0;
}