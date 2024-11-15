#include <bits/stdc++.h>
#define ll long long int

using namespace std;

const ll N=50005,inf=1e+18;
ll n,q,t,x,y,z,ST[4*N]={},Add[4*N]={};
void Update(ll id, ll l, ll r, ll x, ll y, ll z){
    if (l>y || r<x) return;
    if (l>=x && r<=y){
        Add[id]+=z;
        ST[id]+=z;
        return;
    }
    ll md=(l+r)/2;
    Update(id*2,l,md,x,y,z);
    Update(id*2+1,md+1,r,x,y,z);
    ST[id]=max(ST[id*2],ST[id*2+1])+Add[id];
}
ll Get_Max(ll id, ll l, ll r, ll x, ll y){
    if (l>y || r<x) return -inf;
    if (l>=x && r<=y) return ST[id];
    ll md=(l+r)/2;
    return max(Get_Max(id*2,l,md,x,y),Get_Max(id*2+1,md+1,r,x,y))+Add[id];
}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin>>n>>q;
    while (q--){
        cin>>t;
        if (t==0){
            cin>>x>>y>>z;
            Update(1,1,n,x,y,z);
        }
        else if (t==1){
            cin>>x>>y;
            cout<<Get_Max(1,1,n,x,y)<<endl;
        }
    }
}

