#include <bits/stdc++.h>
#define ll long long int

using namespace std;

const ll N=200000,inf=1e+18;
ll n,x=inf,y=inf,z=-inf,t=-inf,a[N+5],b[N+5];
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin>>n;
    for (ll i=1;i<=n;i++) cin>>a[i];
    for (ll i=1;i<=n;i++){
        cin>>b[i];
        a[i]+=b[i];
        b[i]+=b[i]-a[i];
        x=min(x,a[i]);y=min(y,b[i]);
        z=max(z,a[i]);t=max(t,b[i]);
    }
    for (ll i=1;i<=n;i++)
        cout<<max(max(abs(a[i]-x),abs(a[i]-z)),max(abs(b[i]-y),abs(b[i]-t)))<<" ";
}

