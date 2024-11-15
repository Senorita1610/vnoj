#include <bits/stdc++.h>
#define ll long long int

using namespace std;

const ll N=100005,inf=1e+18;
ll n,a[N],b[N],c[N],d[N],x[N],y[N],ans=-inf;
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin>>n;
    for (ll i=1;i<=n;i++){
        cin>>a[i];
        b[n-i+1]=a[i];
        c[i]=inf;
        d[i]=inf;
    }
    for (ll i=1;i<=n;i++){
        ll z1=lower_bound(c+1,c+n+1,a[i])-c;
        ll z2=lower_bound(d+1,d+n+1,b[i])-d;
        c[z1]=a[i];
        d[z2]=b[i];
        x[i]=z1;
        y[i]=z2;
    }
    for (ll i=1;i<=n;i++)
        ans=max(ans,min(x[i],y[n-i+1])*2-1);
    cout<<ans;
}

