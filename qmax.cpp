#include <bits/stdc++.h>
#define ll long long int

using namespace std;

const ll N=50005;
ll n,m,p,x,y,t,a[N]={},ST[4*N];
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
    if (l>y || r<x) return -1e+18;
    if (l>=x && r<=y) return ST[id];
    ll md=(l+r)/2;
    return max(Find_Max(id*2,l,md,x,y),Find_Max(id*2+1,md+1,r,x,y));
}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin>>n>>m;
    while (m--){
        cin>>x>>y>>t;
        a[x]+=t;
        a[y+1]-=t;
    }
    a[0]=0;
    for (ll i=1;i<=n;i++) a[i]+=a[i-1];
    Build(1,1,n);
    cin>>p;
    while (p--){
        cin>>x>>y;
        cout<<Find_Max(1,1,n,x,y)<<endl;
    }
}

