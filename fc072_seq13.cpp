#include <bits/stdc++.h>
#define ll long long int

using namespace std;

const ll N=500000,inf=1e+18;
ll n,q,l,r,a[N+5],ST[4*N+5];
void Build(ll id, ll l, ll r){
    if (l==r){
        ST[id]=a[l];
        return;
    }
    ll md=(l+r)/2;
    Build(id*2,l,md);
    Build(id*2+1,md+1,r);
    ST[id]=max(ST[id*2],ST[id*2+1]);
}
ll Find_Max(ll id, ll l, ll r, ll x, ll y){
    if (l>y || r<x) return -inf;
    if (l>=x && r<=y) return ST[id];
    ll md=(l+r)/2;
    return max(Find_Max(id*2,l,md,x,y),Find_Max(id*2+1,md+1,r,x,y));
}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin>>n>>q;
    for (ll i=1;i<=n;i++) cin>>a[i];
    Build(1,1,n);
    while (q--){
        cin>>l>>r;
        cout<<Find_Max(1,1,n,l,r)<<endl;
    }
}

