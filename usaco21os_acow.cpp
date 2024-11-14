#include<bits/stdc++.h>
using namespace std; 
long long n,m,k,a[100010];
bool check(int x)
{
    long long s=0;
    for(int i=1;i<=n;i++){
        if(a[i]<x){
            s+=x-a[i];
            if(x-a[i]>m) return 0;
        }
        if(s>m*k) return 0;
        if(i==x) return 1;
    }
}
bool cmp(const int &x,const int &y)
{
    return x>y;
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin>>n>>m>>k;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    sort(a+1,a+1+n,cmp);
    int l=0,r=n;
    while(l<r){
        int mid=(l+r+1)/2;
        if(check(mid)) l=mid;
        else r=mid-1;
    }
    cout<<l<<"\n";
    return 0;
}

