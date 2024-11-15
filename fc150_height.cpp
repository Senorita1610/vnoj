#include<bits/stdc++.h>
using namespace std;
const int N=1e5;
int n,mx;
int a[N+5],b[N+5],c[N+5];
int main() {
    cin>>n;
    for (int i=1;i<=n;i++) cin>>a[i];
    for (int i=1;i<=n;i++) cin>>b[i];
    for (int i=1;i<=n;i++) {
        c[i]=b[i]-a[i];
        mx=max(mx,c[i]);
    }
    for (int i=1;i<=n;i++)
        if (c[i]==mx) cout<<i<<' ';
}

