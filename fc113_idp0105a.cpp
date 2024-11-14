#include <bits/stdc++.h>
#define ll long long int

using namespace std;

const ll N=100000;
ll n,q,x,y,a[N+5],ST[4*N+5];
void Build(ll id, ll l, ll r){
    if (l==r){
        ST[id]=a[l]*(a[l]>0);
        return;
    }
    ll md=(l+r)/2;
    Build(id*2,l,md);
    Build(id*2+1,md+1,r);
    ST[id]=ST[id*2]+ST[id*2+1];
}
ll Get_Sum(ll id, ll l, ll r, ll x, ll y){
    if (l>y || r<x) return 0;
    if (l>=x && r<=y) return ST[id];
    ll md=(l+r)/2;
    return Get_Sum(id*2,l,md,x,y)+Get_Sum(id*2+1,md+1,r,x,y);
}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin>>n>>q;
    for (ll i=1;i<=n;i++) cin>>a[i];
    Build(1,1,n);
    while (q--){
        cin>>x>>y;
        cout<<Get_Sum(1,1,n,x,y)<<endl;
    }
}

