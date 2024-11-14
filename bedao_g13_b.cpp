#include <bits/stdc++.h>
#define ll long long int

using namespace std;

const ll N=100000,inf=1e+18;
ll n,ans,m=-inf,m1=-inf,a[N+5],b[N+5],x[N+5],y[N+5];
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin>>n;
    if (n==1){
        cin>>n;
        cout<<n;
        return 0;
    }
    x[0]=0,y[n+1]=0;
    for (ll i=1;i<=n;i++){
        cin>>a[i];
        x[i]=x[i-1]+a[i];
    }
    ans=x[n];
    for (ll i=n;i>=1;i--) y[i]=y[i+1]+a[i];
    a[0]=0,b[n+1]=0;
    for (ll i=1;i<=n;i++){
        a[i]=max(a[i-1],x[i]);
        x[i]=a[i]-x[i];
    }
    for (ll i=n;i>=1;i--){
        b[i]=max(b[i+1],y[i]);
        y[i]=b[i]-y[i];
    }
    for (ll i=1;i<=n;i++){
        m1=max(m1,m+y[i]);
        m=max(m,x[i]);
    }
    cout<<ans+2*m1;
}

