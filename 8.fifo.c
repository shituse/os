#include <stdio.h>
#include<stdbool.h>
int pageFaults(int pages[],int n,int frames)
{
    bool s[100]={false};
    int indexes[frames];
    for(int i=0;i<frames;i++)
        indexes[i]=-1;
    int page_faults=0;
    int front=0;
    int rear=-1;
    for(int i=0;i<n;i++){
        if(rear<frames-1){
            if(!s[pages[i]]){
                s[pages[i]]=true;
                page_faults++;
                rear++;
                s[indexes[rear]]=false;
                indexes[rear]=pages[i];
            }
        }
        else{
            if(!s[pages[i]]){
                    int val=indexes[front];
                    front=(front+1)%frames;
                    s[val]=false;
                    s[pages[i]]=true;
                    rear=(rear+1)%frames;
                    indexes[rear]=pages[i];
                    page_faults++;
            }
        }

    }
    return page_faults;
}

int main()
{
    int n;
    printf("Enter no. of pages:");
    scanf("%d",&n);
    int pages[n];
    printf("Enter pages\n");
    for(int i=0;i<n;i++){
        scanf("%d",&pages[i]);
    }
    int frames;
    printf("Enter no. of frames:");
    scanf("%d",&frames);
    printf("Page faults=%d\n",pageFaults(pages,n,frames));

    return 0;
}
