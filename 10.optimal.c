#include<stdio.h>
#include<stdbool.h>

bool search(int key,int fr[],int fn)
{
    for(int i=0;i<fn;i++){
        if(fr[i]==key)
            return true;
    }
    return false;
}

int predict(int pg[],int fr[],int pn,int fn,int index)
{
    int res=-1,far=index;
    for(int i=0;i<fn;i++){
        int j;
        for(j=index;j<pn;j++){
            if(fr[i]==pg[j]){
                if(j>far){
                    far=j;
                    res=i;
                }
                break;
            }
        }
        if(j==pn){
            return i;
        }
    }
    return (res==-1)?0:res;
}

void optimal(int pg[],int pn,int fn)
{
    int fr[fn];
    int index=0,hit=0;
    for(int i=0;i<pn;i++){
        if(search(pg[i],fr,fn)){
            hit++;
            continue;
        }
        if(index<fn)
            fr[index++]=pg[i];
        else{
            int j=predict(pg,fr,pn,fn,i+1);
            fr[j]=pg[i];
        }
    }
    printf("Hits=%d\n",hit);
    printf("Misses=%d\n",(pn-hit));
}

int main()
{
    int pn,fn;
    printf("Enter no. of frames:");
    scanf("%d",&fn);
    printf("Enter no. of pages:");
    scanf("%d",&pn);
    int pg[pn];
    printf("Enter pages:\n");
    for(int i=0;i<pn;i++){
        scanf("%d",&pg[i]);
    }
    optimal(pg,pn,fn);
    return 0;
}
