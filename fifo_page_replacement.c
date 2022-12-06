#include<stdio.h>
#include<stdbool.h>
#define MAX 20


struct pageTable
{
    int frame_no;
    int valid;
};

bool isPagePresent(struct pageTable pt[],int page)
{
    if(pt[page].valid==1)
    return true;
    return false;
}

void updatePageTable(struct pageTable pt[],int page , int frame_no,int status)
{
    pt[page].valid=status;
    pt[page].frame_no=frame_no;
}

void printFrameContent(int frames[],int frame_no)
{
    for(int i=0;i<frame_no;i++)
    {
        printf("%d    ",frames[i]);
    }
    printf("\n");
}

int main()
{
    int n;
    printf("Enter number of pages ");
    scanf("%d",&n);

    int reference_string[MAX];
    printf("\nEntre the reference string   ");
    for(int i=0;i<n;i++)
    {
        scanf("%d",&reference_string[i]);
    }

    int frame_no;
    printf("\nEnter the number of frames   ");
    scanf("%d",&frame_no);

    int frames[MAX];
    memset(frames,-1,frame_no*sizeof(int));

    struct pageTable pt[MAX];
    for(int i=0;i<MAX;i++)
    {
        pt[i].valid=0;
    }
    int pagefault=0;
    bool flag=false;
    int current=0;
    for (int i = 0; i < n; i++)
    {
        if(!isPagePresent(pt,reference_string[i])) //if the page is not present int he page table then this will exeute
        {
            pagefault++;
            if(flag=false && current < frame_no) //this will initially fill the frame table
            {
                frames[current]=reference_string[i];
                printFrameContent(frames,frame_no);
                updatePageTable(pt,reference_string[i],current,i);
                current++;
                if(current == frame_no)
                {
                    flag=true;
                    current=0;
                }
            }
            else
            {
                updatePageTable(pt,frames[current],-1,0);
                frames[current]=reference_string[i];
                printFrameContent(frames,frame_no);
                updatePageTable(pt,reference_string[i],current,1);
                current=(current+1)%frame_no;
            }
        }
    }
    printf("\nTotal number of page faults %d",pagefault);
    printf("\nPage fault ratio = %.2f",(float)pagefault/n);
    printf("\nPge hit ratio = %.2f",(float)(n-pagefault)/n);
}