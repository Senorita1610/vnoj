#include<bits/stdc++.h>
using namespace std;
const int N=1e5;
int n,a[N+5],mn[N+5],res=INT_MIN;
int main() {
    cin>>n;
    for (int i=1;i<=n;i++) cin>>a[i];
    mn[n+1]=INT_MAX;
    for (int i=n;i>=1;i--) mn[i]=min(mn[i+1],a[i]);
    for (int i=1;i<n;i++) res=max(res,a[i]-mn[i+1]);
    if (res<=0) cout<<"Lo nang roi!";
    else cout<<res;
}

