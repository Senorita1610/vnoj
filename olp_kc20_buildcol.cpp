#include <bits/stdc++.h>
#define ll long long int

using namespace std;

const ll N=100005,inf=1e+18;
ll n,m,a[N],l=inf,r=-inf;
ll Get(ll x){
    ll y[N]={},z=x,ans=0,o=0;
    y[0]=x;
    for (ll i=1;i<=n;i++)
        y[i]=max(y[i-1],a[i]);
    for (ll i=n;i>=1;i--){
        z=max(z,a[i]);
        ans+=max(o,(min(y[i],z)-max(a[i],x)));
    }
    return ans;
}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin>>n>>m;
    for (ll i=1;i<=n;i++){
        cin>>a[i];
        l=min(l,a[i]);
        r=max(r,a[i]);
    }
    if (Get(0)<m){
        cout<<-1;
        return 0;
    }
    while (l<r){
        ll md=(l+r)/2;
        if (Get(md+1)>m) l=md+1;
        else if (Get(md+1)<m) r=md;
        else if (Get(md+1)==m){
            cout<<md+1;
            return 0;
        }
    }
    cout<<l;
}

