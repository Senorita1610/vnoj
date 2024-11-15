#include <bits/stdc++.h>
#define ll long long int

using namespace std;

const ll N=50005,inf=1e+18;
ll n,q,x,y,a[N],ST_Max[N*4],ST_Min[N*4];
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
ll Get_Max(ll id, ll l, ll r, ll x, ll y){
    if (l>y || r<x) return -inf;
    if (l>=x && r<=y) return ST_Max[id];
    ll md=(l+r)/2;
    return max(Get_Max(id*2,l,md,x,y),Get_Max(id*2+1,md+1,r,x,y));
}
ll Get_Min(ll id, ll l, ll r, ll x, ll y){
    if (l>y || r<x) return inf;
    if (l>=x && r<=y) return ST_Min[id];
    ll md=(l+r)/2;
    return min(Get_Min(id*2,l,md,x,y),Get_Min(id*2+1,md+1,r,x,y));
}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin>>n>>q;
    for (ll i=1;i<=n;i++) cin>>a[i];
    Build(1,1,n);
    while (q--){
        cin>>x>>y;
        cout<<Get_Max(1,1,n,x,y)-Get_Min(1,1,n,x,y)<<endl;
    }
}

