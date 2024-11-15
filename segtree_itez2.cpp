#include <bits/stdc++.h>
#define ll long long int

using namespace std;

const ll N=100001,inf=1e+18;
ll n,q,t,x,y,ST[N*4]={};
void Update(ll id, ll l, ll r, ll x, ll y){
    if (l>x || r<x || l>r) return;
    if (l==r){
        ST[id]=y;
        return;
    }
    ll md=(l+r)/2;
    Update(id*2,l,md,x,y);
    Update(id*2+1,md+1,r,x,y);
    ST[id]=ST[id*2]+ST[id*2+1];
}
ll FindSum(ll id, ll l, ll r, ll x, ll y){
    if (l>y || r<x || l>r) return 0;
    if (l>=x && r<=y) return ST[id];
    ll md=(l+r)/2;
    return FindSum(id*2,l,md,x,y)+FindSum(id*2+1,md+1,r,x,y);
}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin>>n>>q;
    while (q--){
        cin>>t>>x>>y;
        if (t==1) Update(1,1,n,x,y);
        else if (t==2) cout<<FindSum(1,1,n,x,y)<<endl;
    }
}

