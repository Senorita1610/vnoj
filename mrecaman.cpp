#include<stdio.h>
int a[500001],flag[4000000]={1},k,t;
int main(){
    a[0]=0;
    for(k=1;k<500001;k++){
        t=a[k-1]-k;
        if(t>0&&flag[t]==0) a[k]=t;
        else a[k]=a[k-1]+k;
        flag[a[k]]=1;
    }
    while(scanf("%d",&k)&&k!=-1) printf("%d\n",a[k]);
    return 0;
}

