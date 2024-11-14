#include <bits/stdc++.h>
#define ll long long int

using namespace std;

const ll N=40005,inf=1e+18;
ll w,h,n,x[N],y[N],a=-inf,b=-inf;
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin>>w>>h>>n;
    for (ll i=1;i<=n;i++) cin>>x[i]>>y[i];
    x[0]=0,y[0]=0;
    x[n+1]=w+1,y[n+1]=h+1;
    sort(x,x+n+2);
    sort(y,y+n+2);
    for (ll i=1;i<=n+1;i++){
        a=max(a,x[i]-x[i-1]-1);
        b=max(b,y[i]-y[i-1]-1);
    }
    cout<<a*b;
}

