#include <bits/stdc++.h>
#define ll long long int

using namespace std;

const ll N=100005;
ll n,q,x,y,a[N],b[N],ST[4*N];
void Build(ll id, ll l, ll r){
    if (l==r){
        ST[id]=a[l];
        return;
    }
    ll md=(l+r)/2;
    Build(id*2,l,md);
    Build(id*2+1,md+1,r);
    ST[id]=__gcd(ST[id*2],ST[id*2+1]);
}
ll Get(ll id, ll l, ll r, ll x, ll y){
    if (l>y || r<x) return 0;
    if (l>=x && r<=y) return ST[id];
    ll md=(l+r)/2;
    return __gcd(Get(id*2,l,md,x,y),Get(id*2+1,md+1,r,x,y));
}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin>>n>>q;
    for (ll i=1;i<=n;i++) cin>>a[i];
    for (ll i=1;i<=n;i++){
        cin>>b[i];
        a[i]=abs(a[i]-b[i]);
    }
    Build(1,1,n);
    while (q--){
        cin>>x>>y;
        cout<<Get(1,1,n,x,y)<<endl;
    }
}

