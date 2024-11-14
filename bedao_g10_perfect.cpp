#include <bits/stdc++.h>
#define ll long long int

using namespace std;

const ll N=100005,inf=1e+18;
ll n,q,x,y,a[N],ST_Max[4*N],ST_Min[4*N];
void Build(ll id, ll l, ll r){
    if (l==r){
        ST_Max[id]=a[l];
        ST_Min[id]=a[l];
        return;
    }
    ll md=(l+r)/2;
    Build(id*2,l,md);
    Build(id*2+1,md+1,r);
    ST_Max[id]=max(ST_Max[id*2],ST_Max[id*2+1]);
    ST_Min[id]=min(ST_Min[id*2],ST_Min[id*2+1]);
}
ll Find_Max(ll id, ll l, ll r, ll x, ll y){
    if (l>y || r<x) return -inf;
    if (l>=x && r<=y) return ST_Max[id];
    ll md=(l+r)/2;
    return max(Find_Max(id*2,l,md,x,y),Find_Max(id*2+1,md+1,r,x,y));
}
ll Find_Min(ll id, ll l, ll r, ll x, ll y){
    if (l>y || r<x) return inf;
    if (l>=x && r<=y) return ST_Min[id];
    ll md=(l+r)/2;
    return min(Find_Min(id*2,l,md,x,y),Find_Min(id*2+1,md+1,r,x,y));
}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin>>n>>q;
    for (ll i=1;i<=n;i++) cin>>a[i];
    Build(1,1,n);
    while (q--){
        cin>>x>>y;
        (Find_Max(1,1,n,x,y)-Find_Min(1,1,n,x,y)==y-x) ? cout<<"YES"<<endl : cout<<"NO"<<endl;
    }
}

