#include <bits/stdc++.h>
#define ll long long int

using namespace std;

const ll N=100005;
ll n,q,a,b,c,d,x[N],ST[4*N],Add[4*N]={};
void Build(ll ip, ll l, ll r){
    if (l==r){
        ST[ip]=x[l];
        return;
    }
    ll mid=(l+r)/2;
    Build(ip*2,l,mid);
    Build(ip*2+1,mid+1,r);
    ST[ip]=max(ST[ip*2],ST[ip*2+1]);
}
void Update(ll ip, ll l, ll r, ll x, ll y, ll k){
    if (r<x || l>y) return;
    if (l>=x && r<=y){
        ST[ip]+=k;
        Add[ip]+=k;
        return;
    }
    ll mid=(l+r)/2;
    Update(ip*2,l,mid,x,y,k);
    Update(ip*2+1,mid+1,r,x,y,k);
    ST[ip]=max(ST[ip*2],ST[ip*2+1])+Add[ip];
}
ll FindMax(ll ip, ll l, ll r, ll x, ll y){
    if (l>r || r<x || l>y) return -1e+18;
    if (l>=x && r<=y) return ST[ip];
    ll mid=(l+r)/2;
    return max(FindMax(ip*2,l,mid,x,y),FindMax(ip*2+1,mid+1,r,x,y))+Add[ip];
}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin>>n;
    for (ll i=1;i<=n;i++) cin>>x[i];
    Build(1,1,n);
    cin>>q;
    while (q--){
        cin>>a;
        if (a==1){
            cin>>b>>c>>d;
            Update(1,1,n,b,c,d);
        }
        else if (a==2){
            cin>>b>>c;
            cout<<FindMax(1,1,n,b,c)<<endl;
        }
    }
}

