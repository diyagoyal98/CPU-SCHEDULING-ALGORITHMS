#include<iostream>
using namespace std;
#define MAX 30

bool search(int k,int frame[],int frame_no)
{
    
    for(int i=0;i<frame_no;i++)
    {
        if(k==frame[i])
        return true;
        
    }
    return false;
}

int predict(int reference_string[],int n,int frame_no,int frame[],int idx)
{
    int as_far_as=idx;
   
    int ans=-1;
    for(int i=0;i<frame_no;i++)
    {
        int j;
        for(j=idx;j<n;j++)
        {
            if(reference_string[j]==frame[i])
            {
                if(j>as_far_as)
                {
                    as_far_as=j;
                    //cout<<as_far_as<<"   ";
                    ans=i;
                }
                break;
            }
        }
        if(j==n)
        return i;
    }

    return ans==-1?0:ans;
}

void optimal(int reference_string[],int n,int frame_no)
{
    int frame[MAX];
    int current=0;
    int miss=0;
    for(int i=0;i<n;i++)
    {
        if(!search(reference_string[i],frame,frame_no))
        {
            miss++;
            if(current<frame_no)
            {
                frame[current]=reference_string[i];
            }
            else
            {
                int predict_idx=predict(reference_string,n,frame_no,frame,i+1);
                frame[predict_idx]=reference_string[i];
            }
            current++;
        }
    }
    cout<<"Misss "<<miss;
}
int main()
{
    int n;
    cout<<"Enter the size  ";
    cin>>n;
    int reference_string[MAX];
    cout<<"Enter the string  ";
    for(int i=0;i<n;i++)
    {
        cin>>reference_string[i];
    }
    int frame_no;
    cout<<"Enter frame number   ";
    cin>>frame_no;
    
    optimal(reference_string,n,frame_no);
    return 0;
}