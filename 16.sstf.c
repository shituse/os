#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>

int nearestReq(int requests[],bool visited[],int head,int n)
{
    int mindist=__INT_MAX__;
    int nearestreq=-1;

    for(int i=0;i<n;i++){
        if(!visited[i] && abs(requests[i]-head)<mindist){
            mindist=abs(requests[i]-head);
            nearestreq=i;
        }
    }
    return nearestreq;
}

void sstf(int requests[],int head,int n)
{
    int totalops=0,currentreq=head;

    bool visited[n];
    for(int i=0;i<n;i++)
        visited[i]=false;
    for(int i=0;i<n;i++){

        int nearestreq=nearestReq(requests,visited,currentreq,n);

        visited[nearestreq]=true;

        printf("%d ",requests[nearestreq]);
        totalops+=abs(requests[nearestreq]-currentreq);
        currentreq=requests[nearestreq];
    }
    printf("\nTotal operations=%d",totalops);

}

int main()
{
    int n,head;
    printf("Enter head request:");
    scanf("%d",&head);
    printf("Enter no. of requests:");
    scanf("%d",&n);
    int requests[n];
    printf("Enter all requests:\n");
    for(int i=0;i<n;i++){
        scanf("%d",&requests[i]);
    }
    sstf(requests,head,n);
    return 0;
}
