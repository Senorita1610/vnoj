#include<cstdio>
#include<iostream>
#include<algorithm>
#define N 50005
using namespace std;
int a[N],b[N],ans,j=1;
int main(){
    int n,m,d,l;
    cin>>n>>m>>d>>l;
    for(int i=1;i<=n;i++)
        cin>>a[i];
    sort(a+1,a+1+n);
    for(int i=1;i<=n;i++){
        if(l<=a[i]-b[j]*d){ans++;b[j]++;j++;}
        if(j>m)j=1;
    }
    printf("%d\n",ans);
    return 0;
}

